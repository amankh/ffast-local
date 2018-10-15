/* File generated form template iLQG_func.tem on 2018-05-09 20:17:43-04:00. Do not edit! */

namespace stationary {

#include "iLQGStationary/iLQG.h"
#include "iLQGStationary/matMult.h"
#include <math.h>

#define mcond(cond, a, dummy, b) ((cond)? a: b)
#define sec(x) (1.0/cos(x))
#define csc(x) (1.0/sin(x))
#define abs(x) fabs(x)


int n_params= 20;
    
tParamDesc p_name1= {"I_z", 1, 0}; // -> p[0][0]
tParamDesc p_name2= {"L_f", 1, 0}; // -> p[1][0]
tParamDesc p_name3= {"L_r", 1, 0}; // -> p[2][0]
tParamDesc p_name4= {"c_a", 1, 0}; // -> p[3][0]
tParamDesc p_name5= {"c_x", 1, 0}; // -> p[4][0]
tParamDesc p_name6= {"cdu", 2, 0}; // -> p[5][0]
tParamDesc p_name7= {"cf", 3, 0}; // -> p[6][0]
tParamDesc p_name8= {"cu", 2, 0}; // -> p[7][0]
tParamDesc p_name9= {"cx", 6, 0}; // -> p[8][0]
tParamDesc p_name10= {"dt", 1, 0}; // -> p[9][0]
tParamDesc p_name11= {"goal", 3, 0}; // -> p[10][0]
tParamDesc p_name12= {"limSteer", 2, 0}; // -> p[11][0]
tParamDesc p_name13= {"limThr", 2, 0}; // -> p[12][0]
tParamDesc p_name14= {"load_f", 1, 0}; // -> p[13][0]
tParamDesc p_name15= {"load_r", 1, 0}; // -> p[14][0]
tParamDesc p_name16= {"m", 1, 0}; // -> p[15][0]
tParamDesc p_name17= {"mu", 1, 0}; // -> p[16][0]
tParamDesc p_name18= {"mu_s", 1, 0}; // -> p[17][0]
tParamDesc p_name19= {"pf", 3, 0}; // -> p[18][0]
tParamDesc p_name20= {"px", 6, 0}; // -> p[19][0]
int n_vars= 0;
    
tParamDesc *paramdesc[]= {&p_name1, &p_name2, &p_name3, &p_name4, &p_name5, &p_name6, &p_name7, &p_name8, &p_name9, &p_name10, &p_name11, &p_name12, &p_name13, &p_name14, &p_name15, &p_name16, &p_name17, &p_name18, &p_name19, &p_name20};







static int calcXVariableAux(trajEl_t *t, multipliersEl_t *m, int k, tOptSet *o);
static int calcXUVariableAux(trajEl_t *t, multipliersEl_t *m, int k, tOptSet *o);
static int calcFVariableAux(trajFin_t *t, multipliersFin_t *m, tOptSet *o);
static int calcLAuxDeriv(trajEl_t *t, multipliersEl_t *m, int k, tOptSet *o);
static int calcFAuxDeriv(trajFin_t *t, multipliersFin_t *m, tOptSet *o);
static int bp_derivsL(trajEl_t *t, int k, double **p);
static int bp_derivsF(trajFin_t *t, int k, double **p);

static int ddpL(trajEl_t *t, int k, tOptSet *o) {
    const double *x= t->x;
    const double *u= t->u;
    double **p= o->p;
    
    t->c=pow(u[0],2.0)*p[7][0]+pow(u[1],2.0)*p[7][1]+p[5][0]*pow((u[0]-x[6])/p[9][0],2.0)+p[5][1]*pow((u[1]-x[7])/p[9][0],2.0)+p[8][0]*(-p[19][0]+sqrt(pow(x[0],2.0)+pow(p[19][0],2.0)))+p[8][1]*(-p[19][1]+sqrt(pow(x[1],2.0)+pow(p[19][1],2.0)))+p[8][3]*(-p[19][3]+sqrt(pow(x[3]-p[10][0],2.0)+pow(p[19][3],2.0)))+p[8][5]*(-p[19][5]+sqrt(pow(x[5]-p[10][2],2.0)+pow(p[19][5],2.0)))+p[8][4]*(-p[19][4]+sqrt(pow(p[19][4],2.0)+pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0)));
    if (isNANorINF(t->c))
        {
            PRNT("    @k %d: t->c in line %d is nan or inf: %g\n", k, __LINE__-3,t->c);
            {
                PRNT("        p[8,5]= %g\n",p[8][5]);
                PRNT("        p[19,5]= %g\n",p[19][5]);
                PRNT("        p[10,2]= %g\n",p[10][2]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        p[7,1]= %g\n",p[7][1]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[5,1]= %g\n",p[5][1]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[7]= %g\n",x[7]);
                PRNT("        p[7,0]= %g\n",p[7][0]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        p[5,0]= %g\n",p[5][0]);
                PRNT("        x[6]= %g\n",x[6]);
                PRNT("        p[8,3]= %g\n",p[8][3]);
                PRNT("        p[19,3]= %g\n",p[19][3]);
                PRNT("        p[10,0]= %g\n",p[10][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[8,4]= %g\n",p[8][4]);
                PRNT("        p[19,4]= %g\n",p[19][4]);
                PRNT("        p[10,1]= %g\n",p[10][1]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[8,0]= %g\n",p[8][0]);
                PRNT("        p[19,0]= %g\n",p[19][0]);
                PRNT("        x[0]= %g\n",x[0]);
                PRNT("        p[8,1]= %g\n",p[8][1]);
                PRNT("        p[19,1]= %g\n",p[19][1]);
                PRNT("        x[1]= %g\n",x[1]);
            }
            return(0);
        }
    
    return 1;
}

static int ddpF(trajFin_t *t, tOptSet *o) {
    const double *x= t->x;
    const int k= o->n_hor;
    double **p= o->p;
    
    t->c=p[6][0]*(-p[18][0]+sqrt(pow(x[3]-p[10][0],2.0)+pow(p[18][0],2.0)))+p[6][2]*(-p[18][2]+sqrt(pow(x[5]-p[10][2],2.0)+pow(p[18][2],2.0)))+p[6][1]*(-p[18][1]+sqrt(pow(p[18][1],2.0)+pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0)));
    if (isNANorINF(t->c))
        {
            PRNT("    @k %d: t->c in line %d is nan or inf: %g\n", k, __LINE__-3,t->c);
            {
                PRNT("        p[6,2]= %g\n",p[6][2]);
                PRNT("        p[18,2]= %g\n",p[18][2]);
                PRNT("        p[10,2]= %g\n",p[10][2]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        p[6,0]= %g\n",p[6][0]);
                PRNT("        p[18,0]= %g\n",p[18][0]);
                PRNT("        p[10,0]= %g\n",p[10][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[6,1]= %g\n",p[6][1]);
                PRNT("        p[18,1]= %g\n",p[18][1]);
                PRNT("        p[10,1]= %g\n",p[10][1]);
                PRNT("        x[4]= %g\n",x[4]);
            }
            return(0);
        }
    
    return 1;
}

static int ddpf(double x_next[], trajEl_t *t, int k, double **p, int N) {
    const double *x= t->x;
    const double *u= t->u;
    
    x_next[0]=x[0]+sqrt(pow(x[3],2.0)+pow(x[4],2.0))*p[9][0]*cos(x[2]+atan2(x[4],x[3]));
    if (isNANorINF(x_next[0]))
        {
            PRNT("    @k %d: x_next[0] in line %d is nan or inf: %g\n", k, __LINE__-3,x_next[0]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[2]= %g\n",x[2]);
                PRNT("        x[0]= %g\n",x[0]);
            }
            return(0);
        }
    x_next[1]=x[1]+sqrt(pow(x[3],2.0)+pow(x[4],2.0))*p[9][0]*sin(x[2]+atan2(x[4],x[3]));
    if (isNANorINF(x_next[1]))
        {
            PRNT("    @k %d: x_next[1] in line %d is nan or inf: %g\n", k, __LINE__-3,x_next[1]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[2]= %g\n",x[2]);
                PRNT("        x[1]= %g\n",x[1]);
            }
            return(0);
        }
    x_next[2]=x[2]+x[5]*p[9][0];
    if (isNANorINF(x_next[2]))
        {
            PRNT("    @k %d: x_next[2] in line %d is nan or inf: %g\n", k, __LINE__-3,x_next[2]);
            {
                PRNT("        x[2]= %g\n",x[2]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[5]= %g\n",x[5]);
            }
            return(0);
        }
    x_next[3]=x[3]+p[9][0]*(x[4]*x[5]+((u[0]-x[3])*p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/(0.001+abs(x[3]))/(1.0+(u[0]-
     x[3])/(0.001+abs(x[3])))-sin(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-p[3][0]*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-0.037037037037037035*pow(p[3][0],3.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(p[13][0],2.0)/p[16][0]+0.3333333333333333*pow(p[3][0],2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/p[13][0]/p[16][0],1,-p[13][0]*p[16][0]*(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0]);
    if (isNANorINF(x_next[3]))
        {
            PRNT("    @k %d: x_next[3] in line %d is nan or inf: %g\n", k, __LINE__-3,x_next[3]);
            {
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
    x_next[4]=x[4]+p[9][0]*(-x[3]*x[5]+(-p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/x[3]/(1.0+(u[0]-x[3
     ])/(0.001+abs(x[3])))+cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-p[3][0]*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-0.037037037037037035*pow(p[3][0],3.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(p[13][0],2.0)/p[16][0]+0.3333333333333333*pow(p[3][0],2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/p[13][0]/p[16][0],1,-p[13][0]*p[16][0]*(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0]);
    if (isNANorINF(x_next[4]))
        {
            PRNT("    @k %d: x_next[4] in line %d is nan or inf: %g\n", k, __LINE__-3,x_next[4]);
            {
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
    x_next[5]=x[5]+p[9][0]*(p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/x[3]/(1.0+(u[0]-x[3])/(
     0.001+abs(x[3])))+p[1][0]*cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-p[3][0]*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-0.037037037037037035*pow(p[3][0],3.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(p[13][0],2.0)/p[16][0]+0.3333333333333333*pow(p[3][0],2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/p[13][0]/p[16][0],1,-p[13][0]*p[16][0]*(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[0][0];
    if (isNANorINF(x_next[5]))
        {
            PRNT("    @k %d: x_next[5] in line %d is nan or inf: %g\n", k, __LINE__-3,x_next[5]);
            {
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        p[0,0]= %g\n",p[0][0]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
    x_next[6]=u[0];
    if (isNANorINF(x_next[6]))
        {
            PRNT("    @k %d: x_next[6] in line %d is nan or inf: %g\n", k, __LINE__-3,x_next[6]);
            {
                PRNT("        u[0]= %g\n",u[0]);
            }
            return(0);
        }
    x_next[7]=u[1];
    if (isNANorINF(x_next[7]))
        {
            PRNT("    @k %d: x_next[7] in line %d is nan or inf: %g\n", k, __LINE__-3,x_next[7]);
            {
                PRNT("        u[1]= %g\n",u[1]);
            }
            return(0);
        }
    return 1;
}

void clampU(double *u, trajEl_t *t, int k, double **p, int N) {
    double limit;
    const double *x= t->x;

// constraint h[1]= limThr[0]-thr
    limit=p[12][0];
    if (u[0]<limit)
        u[0]=limit;

// constraint h[2]= -limThr[1]+thr
    limit=p[12][1];
    if (u[0]>limit)
        u[0]=limit;

// constraint h[3]= limSteer[0]-steer
    limit=p[11][0];
    if (u[1]<limit)
        u[1]=limit;

// constraint h[4]= -limSteer[1]+steer
    limit=p[11][1];
    if (u[1]>limit)
        u[1]=limit;

}

static void limitsU(trajEl_t *t, int k, double **p, int N) {
    int i, j;
    int lower_idx[N_U], upper_idx[N_U], *idx_;
    double limit;
    const double *x= t->x;
    double *hx_, *h_sign;

    for(i= 0; i<N_U; i++) {
        lower_idx[i]= -1;
        upper_idx[i]= -1;
        t->lower[i]= -INF;
        t->upper[i]= INF;
    }        
    
// constraint h[1]= limThr[0]-thr
    limit=p[12][0];
    if (t->lower[0]<limit)
        {
            t->lower[0]=limit;
            lower_idx[0]=0;
        }

// constraint h[2]= -limThr[1]+thr
    limit=p[12][1];
    if (t->upper[0]>limit)
        {
            t->upper[0]=limit;
            upper_idx[0]=1;
        }

// constraint h[3]= limSteer[0]-steer
    limit=p[11][0];
    if (t->lower[1]<limit)
        {
            t->lower[1]=limit;
            lower_idx[1]=2;
        }

// constraint h[4]= -limSteer[1]+steer
    limit=p[11][1];
    if (t->upper[1]>limit)
        {
            t->upper[1]=limit;
            upper_idx[1]=3;
        }


    for(i= 0; i<N_U; i++) {
        t->lower[i]-= t->u[i];
        t->upper[i]-= t->u[i]; 
    }

    for(j= 0; j<2; j++) {
        if(j==0) {
            idx_= lower_idx;
            hx_= t->lower_hx;
            h_sign= t->lower_sign;
        } else {
            idx_= upper_idx;
            hx_= t->upper_hx;
            h_sign= t->upper_sign;
        }
        for(i= 0; i<N_U; i++, hx_+= N_X, h_sign++) {
            switch(idx_[i]) {
                case -1:
                    h_sign[0]= 0.0;
                    break;
                case 0:
// constraint h[1]= limThr[0]-thr
                    hx_[0]=0.0;
                    hx_[1]=0.0;
                    hx_[2]=0.0;
                    hx_[3]=0.0;
                    hx_[4]=0.0;
                    hx_[5]=0.0;
                    hx_[6]=0.0;
                    hx_[7]=0.0;
                    h_sign[0]=-1.0;
                    break;
                case 1:
// constraint h[2]= -limThr[1]+thr
                    hx_[0]=0.0;
                    hx_[1]=0.0;
                    hx_[2]=0.0;
                    hx_[3]=0.0;
                    hx_[4]=0.0;
                    hx_[5]=0.0;
                    hx_[6]=0.0;
                    hx_[7]=0.0;
                    h_sign[0]=1.0;
                    break;
                case 2:
// constraint h[3]= limSteer[0]-steer
                    hx_[0]=0.0;
                    hx_[1]=0.0;
                    hx_[2]=0.0;
                    hx_[3]=0.0;
                    hx_[4]=0.0;
                    hx_[5]=0.0;
                    hx_[6]=0.0;
                    hx_[7]=0.0;
                    h_sign[0]=-1.0;
                    break;
                case 3:
// constraint h[4]= -limSteer[1]+steer
                    hx_[0]=0.0;
                    hx_[1]=0.0;
                    hx_[2]=0.0;
                    hx_[3]=0.0;
                    hx_[4]=0.0;
                    hx_[5]=0.0;
                    hx_[6]=0.0;
                    hx_[7]=0.0;
                    h_sign[0]=1.0;
                    break;
            }
        }
    }
}

int forward_pass(traj_t *c, tOptSet *o, double alpha, double *csum, int cost_only) {
    int i, k, j;
    double dx;
    double *x0= o->x0;
    int N= o->n_hor;
    double **params= o->p;
    
    trajEl_t *t= o->nominal->t;
    trajFin_t *f= &o->nominal->f;
    trajEl_t *ct= c->t;
    trajFin_t *cf= &c->f;
    
    multipliersEl_t *m= o->multipliers.t;
    multipliersFin_t *mf= &o->multipliers.f;
    
    double *x_next;
    
    csum[0]= 0.0;

    if(!cost_only)
        for(i= 0; i<N_X; i++) ct->x[i]= x0[i]; // ic

    for(k= 0; k<N; k++, t++, ct++, m++) {
        if(!cost_only) {
            if(alpha) {
                for(j= 0; j<N_U; j++)
                    ct->u[j]= t->u[j] + t->l[j]*alpha;
                for(i= 0; i<N_X; i++) {
                    dx= ct->x[i] - t->x[i];
                    
                    for(j= 0; j<N_U; j++) {
                        ct->u[j]+= t->L[MAT_IDX(j, i, N_U)]*dx;
                    }
                }
            } else {
                for(j= 0; j<N_U; j++)
                    ct->u[j]= t->u[j];
            }
        }        
        if(!calcXVariableAux(ct, m, k, o)) return 0;
        
        if(!cost_only)
            clampU(ct->u, ct, k, params, N);
        if(!calcXUVariableAux(ct, m, k, o)) return 0;
        
        if(!cost_only) {
            if(k>=N-1)
                x_next= cf->x;
            else
                x_next= (ct+1)->x;
                
            if(!ddpf(x_next, ct, k, params, N)) return 0;
        }
        
        if(!ddpL(ct, k, o)) return 0;
        csum[0]+= ct->c;        
    }
    
    if(!calcFVariableAux(cf, mf, o)) return 0;
        
    if(!ddpF(cf, o))  return 0;
    csum[0]+= cf->c;
        
    return 1;
}

int calc_derivs(tOptSet *o) {
    int k, i_;
    int N= o->n_hor;

    trajEl_t *t= o->nominal->t + N -1;
    trajFin_t *f= &o->nominal->f;
    
    multipliersEl_t *m= o->multipliers.t + N - 1;
    multipliersFin_t *mf= &o->multipliers.f;

    if(!calcFAuxDeriv(f, mf, o)) return 0;
    if(!bp_derivsF(f, N, o->p)) return 0;
    
#if MULTI_THREADED   
    pthread_mutex_lock(&step_mutex);
    step_calc_done= N;
    pthread_cond_signal(&next_step_condition);
    pthread_mutex_unlock(&step_mutex);
#endif

    for(k= N-1; k>=0; k--, t--, m--) {
        if(!calcLAuxDeriv(t, m, k, o)) return 0;
        if(!bp_derivsL(t, k, o->p)) return 0;
        
        limitsU(t, k, o->p, N);

#if MULTI_THREADED   
        pthread_mutex_lock(&step_mutex);
        step_calc_done= k;
        pthread_cond_signal(&next_step_condition);
        pthread_mutex_unlock(&step_mutex);
#endif
    }
    return 1;
}

static int calcXVariableAux(trajEl_t *t, multipliersEl_t *m, int k, tOptSet *o) {
    const double *x= t->x;
    double **p= o->p;
    const double w_pen= o->w_pen_l;
    
    return 1;
} 

static int calcXUVariableAux(trajEl_t *t, multipliersEl_t *m, int k, tOptSet *o) {
    const double *x= t->x;
    const double *u= t->u;
    double **p= o->p;
    const double w_pen= o->w_pen_l;
    
    return 1;
} 

static int calcFVariableAux(trajFin_t *t, multipliersFin_t *m, tOptSet *o) {
    const double *x= t->x;
    double **p= o->p;
    const double w_pen= o->w_pen_f;
    const int k= o->n_hor;
    
    return 1;
} 

static int calcLAuxDeriv(trajEl_t *t, multipliersEl_t *m, int k, tOptSet *o) {
    const double *x= t->x;
    const double *u= t->u;
    const double w_pen= o->w_pen_l;
    double **p= o->p;
    
    return 1;
}

static int bp_derivsL(trajEl_t *t, int k, double **p) {
    const double *x= t->x;
    const double *u= t->u;
    
// derivatives of f
// df[i]/d x[0]
// df[i]/d x[1]
// df[i]/d x[2]
    t->fx[16]=-sqrt(pow(x[3],2.0)+pow(x[4],2.0))*p[9][0]*sin(x[2]+atan2(x[4],x[3]));
    if (isNANorINF(t->fx[16]))
        {
            PRNT("    @k %d: t->fx[16] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fx[16]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[2]= %g\n",x[2]);
            }
            return(0);
        }
    t->fx[17]=sqrt(pow(x[3],2.0)+pow(x[4],2.0))*p[9][0]*cos(x[2]+atan2(x[4],x[3]));
    if (isNANorINF(t->fx[17]))
        {
            PRNT("    @k %d: t->fx[17] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fx[17]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[2]= %g\n",x[2]);
            }
            return(0);
        }
// df[i]/d x[3]
    t->fx[24]=x[3]*p[9][0]*cos(x[2]+atan2(x[4],x[3]))/sqrt(pow(x[3],2.0)+pow(x[4],2.0))+x[4]*p[9][0]*sin(x[2]+atan2(x[4],x[3]))/sqrt(pow(x[3],2.0)+pow(x[4],2.0));
    if (isNANorINF(t->fx[24]))
        {
            PRNT("    @k %d: t->fx[24] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fx[24]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[2]= %g\n",x[2]);
            }
            return(0);
        }
    t->fx[25]=-x[4]*p[9][0]*cos(x[2]+atan2(x[4],x[3]))/sqrt(pow(x[3],2.0)+pow(x[4],2.0))+x[3]*p[9][0]*sin(x[2]+atan2(x[4],x[3]))/sqrt(pow(x[3],2.0)+pow(x[4],2.0));
    if (isNANorINF(t->fx[25]))
        {
            PRNT("    @k %d: t->fx[25] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fx[25]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        x[2]= %g\n",x[2]);
            }
            return(0);
        }
    t->fx[27]=1.0+p[9][0]*(-p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/(0.001+abs(x[3]))/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))
     )-(u[0]-x[3])*p[4][0]*mcond(x[3]>0.0,1.0,1,-1.0)*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0
     ]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*p[4][0]*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5
     ])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+(u[0]-x[3])*p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]
     ),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0
     )+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-
     x[3])/(0.001+abs(x[3]))),2.0),1.5))/(0.001+abs(x[3]))/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-sin(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),p[3][0]*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))+0.1111111111111111*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0)
     )/p[13][0]/p[16][0],1,(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0];
    if (isNANorINF(t->fx[27]))
        {
            PRNT("    @k %d: t->fx[27] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fx[27]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
    t->fx[28]=p[9][0]*(-x[5]+(p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/pow(x[3],2.0)/(1.0+(u[0]-x[3])
     /(0.001+abs(x[3])))+p[3][0]*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[
     5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),
     2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+
     pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[
     3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),p[3][0]*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))+0.1111111111111111*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16
     ][0],1,(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0]);
    if (isNANorINF(t->fx[28]))
        {
            PRNT("    @k %d: t->fx[28] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fx[28]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
    t->fx[29]=p[9][0]*(-p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/pow(x[3],2.0)/(1.0+(u[0]-x[3
     ])/(0.001+abs(x[3])))-p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-
     p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(
     0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001
     +abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[
     3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[1][0]*cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),p[3][0]*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))+0.1111111111111111*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*
     x[5],2.0))/p[13][0]/p[16][0],1,(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[0][0];
    if (isNANorINF(t->fx[29]))
        {
            PRNT("    @k %d: t->fx[29] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fx[29]);
            {
                PRNT("        p[0,0]= %g\n",p[0][0]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
// df[i]/d x[4]
    t->fx[32]=x[4]*p[9][0]*cos(x[2]+atan2(x[4],x[3]))/sqrt(pow(x[3],2.0)+pow(x[4],2.0))-x[3]*p[9][0]*sin(x[2]+atan2(x[4],x[3]))/sqrt(pow(x[3],2.0)+pow(x[4],2.0));
    if (isNANorINF(t->fx[32]))
        {
            PRNT("    @k %d: t->fx[32] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fx[32]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        x[2]= %g\n",x[2]);
            }
            return(0);
        }
    t->fx[33]=x[3]*p[9][0]*cos(x[2]+atan2(x[4],x[3]))/sqrt(pow(x[3],2.0)+pow(x[4],2.0))+x[4]*p[9][0]*sin(x[2]+atan2(x[4],x[3]))/sqrt(pow(x[3],2.0)+pow(x[4],2.0));
    if (isNANorINF(t->fx[33]))
        {
            PRNT("    @k %d: t->fx[33] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fx[33]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[2]= %g\n",x[2]);
            }
            return(0);
        }
    t->fx[35]=p[9][0]*(x[5]+((u[0]-x[3])*p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.07407407407407407*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-0.3333333333333333*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5]
     )/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/(0.001+abs(x[3]))/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-sin(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-x[3]*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))-0.1111111111111111*x[3]*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]+0.3333333333333333*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.3333333333333333*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0],1,-x[3]*p[13][0]*p[16
     ][0]/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+x[3]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0]);
    if (isNANorINF(t->fx[35]))
        {
            PRNT("    @k %d: t->fx[35] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fx[35]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
    t->fx[36]=1.0+p[9][0]*(-p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.07407407407407407*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-0.3333333333333333*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][
     0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-p[3][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])
     /(0.001+abs(x[3]))),2.0)))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-x[3]*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))-0.1111111111111111*x[3]*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]+0.3333333333333333*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.3333333333333333*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0],1,-x[3]*p[13][0]*p[16][0]/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5
     ],2.0))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+x[3]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0];
    if (isNANorINF(t->fx[36]))
        {
            PRNT("    @k %d: t->fx[36] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fx[36]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
    t->fx[37]=p[9][0]*(p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.07407407407407407*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-0.3333333333333333*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[
     2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[2][0]*p[3][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+
     (u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[1][0]*cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-x[3]*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))-0.1111111111111111*x[3]*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]+0.3333333333333333*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.3333333333333333*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0],1,-x[3]*p[13][0]*p[16][0]/(pow(x[3],2.0)+
     pow(x[4]+p[1][0]*x[5],2.0))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+x[3]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[0][0];
    if (isNANorINF(t->fx[37]))
        {
            PRNT("    @k %d: t->fx[37] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fx[37]);
            {
                PRNT("        p[0,0]= %g\n",p[0][0]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
// df[i]/d x[5]
    t->fx[43]=p[9][0]*(x[4]+((u[0]-x[3])*p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],-0.07407407407407407*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+0.3333333333333333*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0
     )*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/(0.001+abs(x[3]))/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-sin(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-p[1][0]*x[3]*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))-0.1111111111111111*p[1][0]*x[3]*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]+0.3333333333333333*p[1][0]*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.3333333333333333*p[1][0]*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[
     1][0]*x[5],2.0))/p[13][0]/p[16][0],1,-p[1][0]*x[3]*p[13][0]*p[16][0]/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+p[1][0]*x[3]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0]);
    if (isNANorINF(t->fx[43]))
        {
            PRNT("    @k %d: t->fx[43] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fx[43]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
    t->fx[44]=p[9][0]*(-x[3]+(-p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],-0.07407407407407407*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+0.3333333333333333*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p
     [3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[2][0]*p[3][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-
     p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-p[1][0]*x[3]*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))-0.1111111111111111*p[1][0]*x[3]*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]+0.3333333333333333*p[1][0]*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.3333333333333333*p[1][0]*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[
     16][0],1,-p[1][0]*x[3]*p[13][0]*p[16][0]/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+p[1][0]*x[3]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0]);
    if (isNANorINF(t->fx[44]))
        {
            PRNT("    @k %d: t->fx[44] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fx[44]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
    t->fx[45]=1.0+p[9][0]*(p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],-0.07407407407407407*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+0.3333333333333333*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+
     pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-pow(p[2][0],2.0)*p[3][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],
     2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[1][0]*cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-p[1][0]*x[3]*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))-0.1111111111111111*p[1][0]*x[3]*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]+0.3333333333333333*p[1][0]*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.3333333333333333*p[1][0]*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*
     x[5],2.0))/p[13][0]/p[16][0],1,-p[1][0]*x[3]*p[13][0]*p[16][0]/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+p[1][0]*x[3]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[0][0];
    if (isNANorINF(t->fx[45]))
        {
            PRNT("    @k %d: t->fx[45] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fx[45]);
            {
                PRNT("        p[0,0]= %g\n",p[0][0]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
// df[i]/d x[6]
// df[i]/d x[7]

// df[i]/d u[0]
    t->fu[3]=p[9][0]*((u[0]-x[3])*p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x
     [3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/(0.001+abs(x[3]))/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5
     ])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]
     /(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/(0.001+abs(x[3]))/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[15][0];
    if (isNANorINF(t->fu[3]))
        {
            PRNT("    @k %d: t->fu[3] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fu[3]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
            }
            return(0);
        }
    t->fu[4]=p[9][0]*(-p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(
     0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][
     0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/p[15][0];
    if (isNANorINF(t->fu[4]))
        {
            PRNT("    @k %d: t->fu[4] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fu[4]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
            }
            return(0);
        }
    t->fu[5]=p[9][0]*(p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[
     3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*
     pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/p[0][0];
    if (isNANorINF(t->fu[5]))
        {
            PRNT("    @k %d: t->fu[5] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fu[5]);
            {
                PRNT("        p[0,0]= %g\n",p[0][0]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
            }
            return(0);
        }
// df[i]/d u[1]
    t->fu[11]=p[9][0]*(-cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-p[3][0]*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-0.037037037037037035*pow(p[3][0],3.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(p[13][0],2.0)/p[16][0]+0.3333333333333333*pow(p[3][0],2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/p[13][0]/p[16][0],1,-p[13][0]*p[16][0]*(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))-sin(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)+0.1111111111111111*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(p[13][0],2.0)/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/p[13][0]/p[16][0]
     -0.3333333333333333*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/p[13][0]/p[16][0],1,p[13][0]*p[16][0]/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0];
    if (isNANorINF(t->fu[11]))
        {
            PRNT("    @k %d: t->fu[11] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fu[11]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
            }
            return(0);
        }
    t->fu[12]=p[9][0]*(-sin(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-p[3][0]*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-0.037037037037037035*pow(p[3][0],3.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(p[13][0],2.0)/p[16][0]+0.3333333333333333*pow(p[3][0],2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/p[13][0]/p[16][0],1,-p[13][0]*p[16][0]*(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))+cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)+0.1111111111111111*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(p[13][0],2.0)/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/p[13][0]/p[16][0]
     -0.3333333333333333*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/p[13][0]/p[16][0],1,p[13][0]*p[16][0]/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0];
    if (isNANorINF(t->fu[12]))
        {
            PRNT("    @k %d: t->fu[12] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fu[12]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
            }
            return(0);
        }
    t->fu[13]=p[9][0]*(-p[1][0]*sin(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-p[3][0]*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-0.037037037037037035*pow(p[3][0],3.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(p[13][0],2.0)/p[16][0]+0.3333333333333333*pow(p[3][0],2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/p[13][0]/p[16][0],1,-p[13][0]*p[16][0]*(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))+p[1][0]*cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)+0.1111111111111111*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(p[13][0],2.0)/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/p[13][0]/p[
     16][0]-0.3333333333333333*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/p[13][0]/p[16][0],1,p[13][0]*p[16][0]/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[0][0];
    if (isNANorINF(t->fu[13]))
        {
            PRNT("    @k %d: t->fu[13] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fu[13]);
            {
                PRNT("        p[0,0]= %g\n",p[0][0]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
            }
            return(0);
        }

#if FULL_DDP
// d^2f[0]/dx[i] dx[j]
// j= 0
// j= 1
// j= 2
    t->fxx[5]=-sqrt(pow(x[3],2.0)+pow(x[4],2.0))*p[9][0]*cos(x[2]+atan2(x[4],x[3]));
    if (isNANorINF(t->fxx[5]))
        {
            PRNT("    @k %d: t->fxx[5] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[5]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[2]= %g\n",x[2]);
            }
            return(0);
        }
// j= 3
    t->fxx[8]=x[4]*p[9][0]*cos(x[2]+atan2(x[4],x[3]))/sqrt(pow(x[3],2.0)+pow(x[4],2.0))-x[3]*p[9][0]*sin(x[2]+atan2(x[4],x[3]))/sqrt(pow(x[3],2.0)+pow(x[4],2.0));
    if (isNANorINF(t->fxx[8]))
        {
            PRNT("    @k %d: t->fxx[8] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[8]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        x[2]= %g\n",x[2]);
            }
            return(0);
        }
    t->fxx[9]=-pow(x[3],2.0)*p[9][0]*cos(x[2]+atan2(x[4],x[3]))/pow(pow(x[3],2.0)+pow(x[4],2.0),1.5)-pow(x[4],2.0)*p[9][0]*cos(x[2]+atan2(x[4],x[3]))/pow(pow(x[3],2.0)+pow(x[4],2.0),1.5)+p[9][0]*cos(x[2]+atan2(x[4],x[3]))/sqrt(pow(x[3],2.0)+pow(x[4],2.0));
    if (isNANorINF(t->fxx[9]))
        {
            PRNT("    @k %d: t->fxx[9] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[9]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[2]= %g\n",x[2]);
            }
            return(0);
        }
// j= 4
    t->fxx[12]=-x[3]*p[9][0]*cos(x[2]+atan2(x[4],x[3]))/sqrt(pow(x[3],2.0)+pow(x[4],2.0))-x[4]*p[9][0]*sin(x[2]+atan2(x[4],x[3]))/sqrt(pow(x[3],2.0)+pow(x[4],2.0));
    if (isNANorINF(t->fxx[12]))
        {
            PRNT("    @k %d: t->fxx[12] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[12]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[2]= %g\n",x[2]);
            }
            return(0);
        }
    t->fxx[13]=-pow(x[3],2.0)*p[9][0]*sin(x[2]+atan2(x[4],x[3]))/pow(pow(x[3],2.0)+pow(x[4],2.0),1.5)-pow(x[4],2.0)*p[9][0]*sin(x[2]+atan2(x[4],x[3]))/pow(pow(x[3],2.0)+pow(x[4],2.0),1.5)+p[9][0]*sin(x[2]+atan2(x[4],x[3]))/sqrt(pow(x[3],2.0)+pow(x[4],2.0));
    if (isNANorINF(t->fxx[13]))
        {
            PRNT("    @k %d: t->fxx[13] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[13]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[2]= %g\n",x[2]);
            }
            return(0);
        }
    t->fxx[14]=-pow(x[3],2.0)*p[9][0]*cos(x[2]+atan2(x[4],x[3]))/pow(pow(x[3],2.0)+pow(x[4],2.0),1.5)-pow(x[4],2.0)*p[9][0]*cos(x[2]+atan2(x[4],x[3]))/pow(pow(x[3],2.0)+pow(x[4],2.0),1.5)+p[9][0]*cos(x[2]+atan2(x[4],x[3]))/sqrt(pow(x[3],2.0)+pow(x[4],2.0));
    if (isNANorINF(t->fxx[14]))
        {
            PRNT("    @k %d: t->fxx[14] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[14]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        x[2]= %g\n",x[2]);
            }
            return(0);
        }
// j= 5
// j= 6
// j= 7
// d^2f[1]/dx[i] dx[j]
// j= 0
// j= 1
// j= 2
    t->fxx[41]=-sqrt(pow(x[3],2.0)+pow(x[4],2.0))*p[9][0]*sin(x[2]+atan2(x[4],x[3]));
    if (isNANorINF(t->fxx[41]))
        {
            PRNT("    @k %d: t->fxx[41] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[41]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[2]= %g\n",x[2]);
            }
            return(0);
        }
// j= 3
    t->fxx[44]=x[3]*p[9][0]*cos(x[2]+atan2(x[4],x[3]))/sqrt(pow(x[3],2.0)+pow(x[4],2.0))+x[4]*p[9][0]*sin(x[2]+atan2(x[4],x[3]))/sqrt(pow(x[3],2.0)+pow(x[4],2.0));
    if (isNANorINF(t->fxx[44]))
        {
            PRNT("    @k %d: t->fxx[44] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[44]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[2]= %g\n",x[2]);
            }
            return(0);
        }
    t->fxx[45]=-pow(x[3],2.0)*p[9][0]*sin(x[2]+atan2(x[4],x[3]))/pow(pow(x[3],2.0)+pow(x[4],2.0),1.5)-pow(x[4],2.0)*p[9][0]*sin(x[2]+atan2(x[4],x[3]))/pow(pow(x[3],2.0)+pow(x[4],2.0),1.5)+p[9][0]*sin(x[2]+atan2(x[4],x[3]))/sqrt(pow(x[3],2.0)+pow(x[4],2.0));
    if (isNANorINF(t->fxx[45]))
        {
            PRNT("    @k %d: t->fxx[45] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[45]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[2]= %g\n",x[2]);
            }
            return(0);
        }
// j= 4
    t->fxx[48]=x[4]*p[9][0]*cos(x[2]+atan2(x[4],x[3]))/sqrt(pow(x[3],2.0)+pow(x[4],2.0))-x[3]*p[9][0]*sin(x[2]+atan2(x[4],x[3]))/sqrt(pow(x[3],2.0)+pow(x[4],2.0));
    if (isNANorINF(t->fxx[48]))
        {
            PRNT("    @k %d: t->fxx[48] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[48]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        x[2]= %g\n",x[2]);
            }
            return(0);
        }
    t->fxx[49]=pow(x[3],2.0)*p[9][0]*cos(x[2]+atan2(x[4],x[3]))/pow(pow(x[3],2.0)+pow(x[4],2.0),1.5)+pow(x[4],2.0)*p[9][0]*cos(x[2]+atan2(x[4],x[3]))/pow(pow(x[3],2.0)+pow(x[4],2.0),1.5)-p[9][0]*cos(x[2]+atan2(x[4],x[3]))/sqrt(pow(x[3],2.0)+pow(x[4],2.0));
    if (isNANorINF(t->fxx[49]))
        {
            PRNT("    @k %d: t->fxx[49] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[49]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[2]= %g\n",x[2]);
            }
            return(0);
        }
    t->fxx[50]=-pow(x[3],2.0)*p[9][0]*sin(x[2]+atan2(x[4],x[3]))/pow(pow(x[3],2.0)+pow(x[4],2.0),1.5)-pow(x[4],2.0)*p[9][0]*sin(x[2]+atan2(x[4],x[3]))/pow(pow(x[3],2.0)+pow(x[4],2.0),1.5)+p[9][0]*sin(x[2]+atan2(x[4],x[3]))/sqrt(pow(x[3],2.0)+pow(x[4],2.0));
    if (isNANorINF(t->fxx[50]))
        {
            PRNT("    @k %d: t->fxx[50] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[50]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[2]= %g\n",x[2]);
            }
            return(0);
        }
// j= 5
// j= 6
// j= 7
// d^2f[2]/dx[i] dx[j]
// j= 0
// j= 1
// j= 2
// j= 3
// j= 4
// j= 5
// j= 6
// j= 7
// d^2f[3]/dx[i] dx[j]
// j= 0
// j= 1
// j= 2
// j= 3
    t->fxx[117]=p[9][0]*(-(u[0]-x[3])*p[4][0]*mcond(x[3]>0.0,0.0,1,0.0)*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/pow(0.001+abs(x[
     3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*p[4][0]*mcond(x[3]>0.0,1.0,1,-1.0)*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))
     /pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*p[4][0]*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0]
     ,2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(u[0]-x[3])*p[4][0]*mcond(x[3]>0.0,1.0,1,-1.0)*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]
     /sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(u[0]-x[3])*p[4][0]*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))
     ),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/pow(0.001+abs(x[3]),3.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*p[4][0]*(-(u[0]-x[3])*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),2.0)+2.0*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)+2.0*(u[0]-x[3])*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),3.0))*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)
     -0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(u[0]-x[3])*p[4][0]*pow(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0),2.0)*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-
     p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)-2.0*p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]
     -x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+
     abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+
     abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/(0.001+abs(x[3]))/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-2.0*(u[0]-x[3])*p[4][0]*mcond(x[3]>0.0,1.0,1,-1.0)*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),
     3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)
     )/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[
     3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-2.0*(u[0]-x[3])*p[4][0]*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x
     [3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,
     1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(
     1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+(u[0]-x[3])*p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+
     abs(x[3]))),2.0)*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),3.0)-8.0*(u[0]-x[3])*pow(p[4][0],2.0)*mcond(x[3]>0.0,1.0,1,-1.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),3.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+6.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),4.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(2.0*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-(u[0]-x[3])*(-(u[0]-x[3])*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),2.0)+2.0*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)+2.0*(u[0]-x[3])*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),3.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(u[0]-x[3])*pow(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3
     ]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(2.0*(x[4]-p[2][0]*x[5])/pow(x[3],3.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-(x[4]-p[2][0]*x[5])*(-(u[0]-x[3])*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),2.0)+2.0*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)+2.0*(u[0]-x[3])*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),3.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(x[4]-p[2][0]*x[5])*pow(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0),2.0)/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[4][0],2.0)*pow(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(
     0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0),2.0)/pow(0.001+abs(x[3]),2.0)+2.0*pow(p[3][0],2.0)*pow(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),3.0)-8.0*(u[0]-x[3])*pow(p[4][0],2.0)*mcond(x[3]>0.0,1.0,1,-1.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),3.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+6.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*pow(mcond(x[3]
     >0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),4.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(2.0*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-(u[0]-x[3])*(-(u[0]-x[3])*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),2.0)+2.0*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)+2.0*(u[0]-x[3])*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),3.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(u[0]-x[3])*pow(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(2.0*(x[4]-p[2][0]*x[5])/pow(x[3],3.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-(x[4]-p[2][0]*x[5])*(-(u[0]
     -x[3])*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),2.0)+2.0*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)+2.0*(u[0]-x[3])*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),3.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(x[4]-p[2][0]*x[5])*pow(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0),2.0)/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[4][0],2.0)*pow(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0),2.0)/pow(0.001+abs(x[3]),2.0)+2.0*pow(p[3][0],2.0)*pow(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0),2.0))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3]
     )/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))+0.08333333333333333*pow(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/p[14][0]/p[16][0]/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),
     2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),3.0)-8.0*(u[0]-x[3])*pow(p[4][0],2.0)*mcond(x[3]>0.0,1.0,1,-1.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),3.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+6.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),4.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(2.0*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-(u[0]-x[3])*(-(u[0]-x[3])*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),2.0)+2.0*mcond(x[3]>0.0,1.0,1,-1.0
     )/pow(0.001+abs(x[3]),2.0)+2.0*(u[0]-x[3])*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),3.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(u[0]-x[3])*pow(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(2.0*(x[4]-p[2][0]*x[5])/pow(x[3],3.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-(x[4]-p[2][0]*x[5])*(-(u[0]-x[3])*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),2.0)+2.0*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)+2.0*(u[0]-x[3])*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),3.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(x[4]-p[2][0]*x[5])*pow(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1
     ,-1.0)/pow(0.001+abs(x[3]),2.0),2.0)/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[4][0],2.0)*pow(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0),2.0)/pow(0.001+abs(x[3]),2.0)+2.0*pow(p[3][0],2.0)*pow(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0),2.0))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5)+0.75*p[14][0]*p[17][0]*pow(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[
     4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),2.5))/(0.001+abs(x[3]))/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-sin(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-2.0*x[3]*p[3][0]*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])
     ),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)-2.0*p[3][0]*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)-0.2222222222222222*pow(p[3][0],3.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.2222222222222222*x[3]*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.2222222222222222*pow(p[3][0],3.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]+0.6666666666666666*x[3]*pow(p[3][0],2.0)*(x[4]+p[
     1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*x[3]*pow(p[3][0],
     2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0],1,-2.0*x[3]*(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+2.0*x[3]*(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][
     0]*x[5],2.0),2.0)/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0];
    if (isNANorINF(t->fxx[117]))
        {
            PRNT("    @k %d: t->fxx[117] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[117]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
// j= 4
    t->fxx[121]=p[9][0]*(-p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.07407407407407407*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-0.3333333333333333*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[
     0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/(0.001+abs(x[3]))/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*p[4][0]*mcond(x[3]>0.0,1.0,1,-1.0)*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.07407407407407407*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-0.3333333333333333*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0
     ]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*p[4][0]*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.07407407407407407*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-0.3333333333333333*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+
     abs(x[3]))),2.0)),1,-pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+(u[0]-x[3])*p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-1/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[
     3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-1/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][
     0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))+0.16666666666666666*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001
     +abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5),1,-0.5*p[14][0]*p[17][0]*(2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-1/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5)+1.5*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+
     (u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),2.5))/(0.001+abs(x[3]))/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-sin(u[1])*
     mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-2.0*p[3][0]*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)+p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))+2.0*x[3]*p[3][0]*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)+0.2222222222222222*x[3]*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.2222222222222222*pow(p[3][0],3.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]+0.1111111111111111*pow(
     p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]+0.2222222222222222*x[3]*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*
     abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0
     )*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0],1,-2.0*pow(x[4]+p[1][0]*x[5],2.0)*p[13][0]*p[16][0]/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+p[13][0]*p[16][0]/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+2.0*pow(x[4]+p[1][0]*x[5],2.0)*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/pow(pow(
     x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0];
    if (isNANorINF(t->fxx[121]))
        {
            PRNT("    @k %d: t->fxx[121] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[121]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
    t->fxx[122]=p[9][0]*((u[0]-x[3])*p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.07407407407407407*pow(p[3][0],2.0)/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+0.3333333333333333*pow(p[3][0],4.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],4.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),4.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5)-0.3333333333333333*pow(p[3][0],2.0)/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]
     -x[3])/(0.001+abs(x[3]))),2.0)),1,3.0*pow(p[3][0],4.0)*pow(x[4]-p[2][0]*x[5],2.0)*p[14][0]*p[17][0]/pow(x[3],4.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),4.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),2.5)-pow(p[3][0],2.0)*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/(0.001+abs(x[3]))/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-sin(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),2.0*x[3]*p[3][0]*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)-2.0*pow(x[3],2.0)*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))
     ,2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)-0.2222222222222222*pow(x[3],2.0)*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]+0.2222222222222222*x[3]*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.2222222222222222*pow(x[3],2.0)*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.6666666666666666*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]
     /p[16][0]+0.6666666666666666*pow(x[3],2.0)*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.3333333333333333*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.6666666666666666*pow(x[3],2.0)*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]-0.6666666666666666*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[
     1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*pow(x[3],2.0)*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0],1,2.0*x[3]*(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+x[3]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-2.0*x[3]*(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0];
    if (isNANorINF(t->fxx[122]))
        {
            PRNT("    @k %d: t->fxx[122] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[122]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
// j= 5
    t->fxx[126]=p[9][0]*(-p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],-0.07407407407407407*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+0.3333333333333333*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2
     ][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/(0.001+abs(x[3]))/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*p[4][0]*mcond(x[3]>0.0,1.0,1,-1.0)*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],-0.07407407407407407*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+0.3333333333333333*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0
     )/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*p[4][0]*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],-0.07407407407407407*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+0.3333333333333333*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[
     3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+(u[0]-x[3])*p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(p[2][0]/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[2][0]*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(
     0.001+abs(x[3])))-2.0*p[2][0]*pow(p[3][0],2.0)*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(p[2][0]/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[2][0]*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-2.0*p[2][0]*pow(p[3][0],2.0)*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],
     2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))-0.16666666666666666*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(x[3],2.0)/p[14][0]/p[16][0]/pow
     (1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5),1,-0.5*p[14][0]*p[17][0]*(2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(p[2][0]/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[2][0]*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-2.0*p[2][0]*pow(p[3][0],2.0)*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(
     1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5)-1.5*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow
     (p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),2.5))/(0.001+abs(x[3]))/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-sin(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-2.0*p[1][0]*p[3][0]*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)+p[1][0]*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))+2.0*p[1][0]*x[3]*p[3][0]*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)+0.2222222222222222*p[1][0]*x[3]*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.2222222222222222*p[1][0]*pow(p[3][0],3.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(
     sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]+0.1111111111111111*p[1][0]*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]+0.2222222222222222*p[1][0]*x[3]*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]+0.6666666666666666*p[1][0]*pow(p[3][0],2.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]-0.3333333333333333*p[1][0]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*
     x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*p[1][0]*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*p[1][0]*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*p[1][0]*pow(p[3][0],2.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u
     [1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]-0.3333333333333333*p[1][0]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*p[1][0]*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0],1,-2.0*p[1][0]*pow(x[4]+p[1][0]*x[5],2.0)*p[13][0]*p[16][0]/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+p[1][0]*p[13][0]*p[16][0]/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-(x[4]+p[1
     ][0]*x[5])*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+2.0*p[1][0]*pow(x[4]+p[1][0]*x[5],2.0)*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-p[1][0]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0];
    if (isNANorINF(t->fxx[126]))
        {
            PRNT("    @k %d: t->fxx[126] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[126]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
    t->fxx[127]=p[9][0]*(1.0+((u[0]-x[3])*p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],-0.07407407407407407*p[2][0]*pow(p[3][0],2.0)/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-0.3333333333333333*p[2][0]*pow(p[3][0],4.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],4.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),4.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5)+0.3333333333333333*p[2][0]*pow(p[3][0],2.0)/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]
     -p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-3.0*p[2][0]*pow(p[3][0],4.0)*pow(x[4]-p[2][0]*x[5],2.0)*p[14][0]*p[17][0]/pow(x[3],4.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),4.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),2.5)+p[2][0]*pow(p[3][0],2.0)*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/(0.001+abs(x[3]))/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-sin(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),2.0*p[1][0]*x[3]*p[3][0]*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)-2.0*p[1][0]*pow
     (x[3],2.0)*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)-0.2222222222222222*p[1][0]*pow(x[3],2.0)*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]+0.2222222222222222*p[1][0]*x[3]*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.2222222222222222*p[1][0]*pow(x[3],2.0)*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.6666666666666666*p[1][0]*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-
     u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*p[1][0]*pow(x[3],2.0)*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.3333333333333333*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.6666666666666666*p[1][0]*pow(x[3],2.0)*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]-0.6666666666666666*p[1][0]*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+
     atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*p[1][0]*pow(x[3],2.0)*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0],1,2.0*p[1][0]*x[3]*(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+x[3]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-2.0*p[1][0]*x[3]*(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0]);
    if (isNANorINF(t->fxx[127]))
        {
            PRNT("    @k %d: t->fxx[127] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[127]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
    t->fxx[128]=p[9][0]*((u[0]-x[3])*p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.07407407407407407*pow(p[2][0],2.0)*pow(p[3][0],2.0)/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+0.3333333333333333*pow(p[2][0],2.0)*pow(p[3][0],4.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],4.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),4.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5)-0.3333333333333333*pow(p[2][0],2.0)*pow(p[3][0],2.0)/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p
     [3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,3.0*pow(p[2][0],2.0)*pow(p[3][0],4.0)*pow(x[4]-p[2][0]*x[5],2.0)*p[14][0]*p[17][0]/pow(x[3],4.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),4.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),2.5)-pow(p[2][0],2.0)*pow(p[3][0],2.0)*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/(0.001+abs(x[3]))/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-sin(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),2.0*pow(p[1][0],2.0)*x[3]*p[3][0]*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+
     pow(x[4]+p[1][0]*x[5],2.0),2.0)-2.0*pow(p[1][0],2.0)*pow(x[3],2.0)*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)-0.2222222222222222*pow(p[1][0],2.0)*pow(x[3],2.0)*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]+0.2222222222222222*pow(p[1][0],2.0)*x[3]*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.2222222222222222*pow(p[1][0],2.0)*pow(x[3],2.0)*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.6666666666666666*pow(p[1][0],2.0)*x[3]*pow(
     p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*pow(p[1][0],2.0)*pow(x[3],2.0)*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.3333333333333333*p[1][0]*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.6666666666666666*pow(p[1][0],2.0)*pow(x[3],2.0)*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]
     -0.6666666666666666*pow(p[1][0],2.0)*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*pow(p[1][0],2.0)*pow(x[3],2.0)*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0],1,2.0*pow(p[1][0],2.0)*x[3]*(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+p[1][0]*x[3]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-2.0*pow(p[1][0],2.0)*x[3]*(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*mcond(
     -u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0];
    if (isNANorINF(t->fxx[128]))
        {
            PRNT("    @k %d: t->fxx[128] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[128]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
// j= 6
// j= 7
// d^2f[4]/dx[i] dx[j]
// j= 0
// j= 1
// j= 2
// j= 3
    t->fxx[153]=p[9][0]*(-2.0*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/pow(x[3],3.0)/(1.0+(u[0]-x[3])
     /(0.001+abs(x[3])))-2.0*p[3][0]*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0
     ]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+p[3][0]*(x[4]-p[2][0]*x[5])*(-(u[0]-x[3])*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),2.0)+2.0*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)+2.0*(u[0]-x[3])*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),3.0))*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])
     /(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-2.0*p[3][0]*(x[4]-p[2][0]*x[5])*pow(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0),2.0)*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),
     2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/
     (0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(
     -1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x
     [3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*p[3][0]*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*
     mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5]
     )/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+
     abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),3.0)-8.0*(u[0]-x[3])*pow(p[4][0],2.0)*mcond(x[3]>0.0,1.0,1,-1.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-
     x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),3.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+6.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),4.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(2.0*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-(u[0]-x[3])*(-(u[0]-x[3])*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),2.0)+2.0*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)+2.0*(u[0]-x[3])*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),3.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(u[0]-x[3])*pow(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(2.0*(x[4]-p[2
     ][0]*x[5])/pow(x[3],3.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-(x[4]-p[2][0]*x[5])*(-(u[0]-x[3])*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),2.0)+2.0*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)+2.0*(u[0]-x[3])*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),3.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(x[4]-p[2][0]*x[5])*pow(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0),2.0)/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[4][0],2.0)*pow(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0),2.0)/pow(0.001+abs(x[3]),2.0)+2.0*pow(p[3][0],2.0)*pow(-(x[4]-p[2][0]*x[5])/pow(x[3],
     2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),3.0)-8.0*(u[0]-x[3])*pow(p[4][0],2.0)*mcond(x[3]>0.0,1.0,1,-1.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),3.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+6.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),4.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(2.0*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),
     2.0)-(u[0]-x[3])*(-(u[0]-x[3])*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),2.0)+2.0*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)+2.0*(u[0]-x[3])*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),3.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(u[0]-x[3])*pow(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(2.0*(x[4]-p[2][0]*x[5])/pow(x[3],3.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-(x[4]-p[2][0]*x[5])*(-(u[0]-x[3])*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),2.0)+2.0*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)+2.0*(u[0]-x[3])*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),3.0))/x[3]/pow(1.0+(u[0]
     -x[3])/(0.001+abs(x[3])),2.0)+2.0*(x[4]-p[2][0]*x[5])*pow(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0),2.0)/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[4][0],2.0)*pow(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0),2.0)/pow(0.001+abs(x[3]),2.0)+2.0*pow(p[3][0],2.0)*pow(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0),2.0))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))+0.08333333333333333*pow(-2.0*pow(p[4][0],2.0)*pow((u[0
     ]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/p[14][0]/p[16][0]/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+
     abs(x[3]))),2.0)*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),3.0)-8.0*(u[0]-x[3])*pow(p[4][0],2.0)*mcond(x[3]>0.0,1.0,1,-1.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),3.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+6.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),4.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(2.0*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-(u[0]-x[3])*(-(u[0]-x[3])*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),2.0)+2.0*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)+2.0*(u[0]-x[3])*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),3.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(u[0]-x[3])*pow(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3
     ]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(2.0*(x[4]-p[2][0]*x[5])/pow(x[3],3.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-(x[4]-p[2][0]*x[5])*(-(u[0]-x[3])*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),2.0)+2.0*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)+2.0*(u[0]-x[3])*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),3.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(x[4]-p[2][0]*x[5])*pow(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0),2.0)/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[4][0],2.0)*pow(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(
     0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0),2.0)/pow(0.001+abs(x[3]),2.0)+2.0*pow(p[3][0],2.0)*pow(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0),2.0))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5)+0.75*p[14][0]*p[17][0]*pow(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(
     x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),2.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-2.0*x[3]*p[3][0]*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)-2.0*p[3][0]*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]
     *x[5],2.0),2.0)-0.2222222222222222*pow(p[3][0],3.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.2222222222222222*x[3]*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.2222222222222222*pow(p[3][0],3.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]+0.6666666666666666*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*pow(x[4]+
     p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0
     ),2.0)/p[13][0]/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0],1,-2.0*x[3]*(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+2.0*x[3]*(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0];
    if (isNANorINF(t->fxx[153]))
        {
            PRNT("    @k %d: t->fxx[153] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[153]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
// j= 4
    t->fxx[157]=p[9][0]*(p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.07407407407407407*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-0.3333333333333333*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*
     x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[3][0]*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.07407407407407407*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-0.3333333333333333*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(
     1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+p[3][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[
     14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[3][0]*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(
     1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-1/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]
     ))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-1/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))+
     0.16666666666666666*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])
     /x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5),1,-0.5*p[14][0]*p[17][0]*(2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-1/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5)+1.5*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1
     ,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),2.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-p[3][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x
     [3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-
     x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]
     >0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-2.0*p[3][0]*pow(x[4]+p[1][0]*x[5]
     ,2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)+p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))+2.0*x[3]*p[3][0]*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)+0.2222222222222222*x[3]*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.2222222222222222*pow(p[3][0],3.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]+0.1111111111111111*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(
     x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]+0.2222222222222222*x[3]*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]
     -0.3333333333333333*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[
     3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0],1,-2.0*pow(x[4]+p[1][0]*x[5],2.0)*p[13][0]*p[16][0]/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+p[13][0]*p[16][0]/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+2.0*pow(x[4]+p[1][0]*x[5],2.0)*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-p[13][0]*p[16][0]*mcond(-u[1]+
     atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0];
    if (isNANorINF(t->fxx[157]))
        {
            PRNT("    @k %d: t->fxx[157] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[157]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
    t->fxx[158]=p[9][0]*(-p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.07407407407407407*pow(p[3][0],2.0)/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+0.3333333333333333*pow(p[3][0],4.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],4.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),4.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5)-0.3333333333333333*pow(p[3][0],2.0)/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(
     1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,3.0*pow(p[3][0],4.0)*pow(x[4]-p[2][0]*x[5],2.0)*p[14][0]*p[17][0]/pow(x[3],4.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),4.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),2.5)-pow(p[3][0],2.0)*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-2.0*p[3][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.07407407407407407*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/
     pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-0.3333333333333333*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),2.0*x[3]*p[3][0]*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)-2.0*pow(x[
     3],2.0)*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)-0.2222222222222222*pow(x[3],2.0)*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]+0.2222222222222222*x[3]*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.2222222222222222*pow(x[3],2.0)*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.6666666666666666*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))
     )/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*pow(x[3],2.0)*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.3333333333333333*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.6666666666666666*pow(x[3],2.0)*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]-0.6666666666666666*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][
     0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*pow(x[3],2.0)*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0],1,2.0*x[3]*(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+x[3]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-2.0*x[3]*(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0];
    if (isNANorINF(t->fxx[158]))
        {
            PRNT("    @k %d: t->fxx[158] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[158]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
// j= 5
    t->fxx[162]=p[9][0]*(-1.0+(p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],-0.07407407407407407*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+0.3333333333333333*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p
     [3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[3][0]*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],-0.07407407407407407*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+0.3333333333333333*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,p[2][0]*pow(p[3][0],2.0)*(x[4
     ]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-p[2][0]*p[3][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+
     (u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-p[2][0]*p[3][0]*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(
     0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(p[2][0]/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[2][0]*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-2.0*p[2][0]*pow(p[3][0],2.0)*(-(x[4]-p[2][0]*x[5])/
     pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(p[2][0]/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[2][0]*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-2.0*p[2][0]*pow(p[3][0],2.0)*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001
     +abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))-0.16666666666666666*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-
     x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5),1,-0.5*p[14][0]*p[17][0]*(2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(p[2][0]/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[2][0]*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-2.0*p[2][0]*pow(p[3][0],2.0)*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5)-1.5*p[2][0]*pow(p[3][0],
     2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+
     abs(x[3]))),2.0),2.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[2][0]*p[3][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),
     2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(
     1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[
     0]-x[3])/(0.001+abs(x[3])))+cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-2.0*p[1][0]*p[3][0]*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)+p[1][0]*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))+2.0*p[1][0]*x[3]*p[3][0]*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)+0.2222222222222222*p[1][0]*x[3]*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.2222222222222222*p[1][0]*pow(p[3][0],3.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(
     x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]+0.1111111111111111*p[1][0]*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]+0.2222222222222222*p[1][0]*x[3]*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]+0.6666666666666666*p[1][0]*pow(p[3][0],2.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]-0.3333333333333333*p[1][0]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*p[1][0]*x[3]*pow(p[3][0],
     2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*p[1][0]*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*p[1][0]*pow(p[3][0],2.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+
     pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]-0.3333333333333333*p[1][0]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*p[1][0]*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0],1,-2.0*p[1][0]*pow(x[4]+p[1][0]*x[5],2.0)*p[13][0]*p[16][0]/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+p[1][0]*p[13][0]*p[16][0]/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0
     ]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+2.0*p[1][0]*pow(x[4]+p[1][0]*x[5],2.0)*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-p[1][0]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0]);
    if (isNANorINF(t->fxx[162]))
        {
            PRNT("    @k %d: t->fxx[162] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[162]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
    t->fxx[163]=p[9][0]*(-p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],-0.07407407407407407*p[2][0]*pow(p[3][0],2.0)/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-0.3333333333333333*p[2][0]*pow(p[3][0],4.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],4.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),4.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5)+0.3333333333333333*p[2][0]*pow(p[3][0],2.0)/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((
     x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-3.0*p[2][0]*pow(p[3][0],4.0)*pow(x[4]-p[2][0]*x[5],2.0)*p[14][0]*p[17][0]/pow(x[3],4.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),4.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),2.5)+p[2][0]*pow(p[3][0],2.0)*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[2][0]*p[3][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.07407407407407407*pow(p[
     3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-0.3333333333333333*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-p[3][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]
     ))),2.0))<=3.0*p[14][0]*p[16][0],-0.07407407407407407*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+0.3333333333333333*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),2.0*p[1][0]*x[3]*p[
     3][0]*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)-2.0*p[1][0]*pow(x[3],2.0)*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)-0.2222222222222222*p[1][0]*pow(x[3],2.0)*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]+0.2222222222222222*p[1][0]*x[3]*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.2222222222222222*p[1][0]*pow(x[3],2.0)*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],
     2.0)/p[16][0]-0.6666666666666666*p[1][0]*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*p[1][0]*pow(x[3],2.0)*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.3333333333333333*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.6666666666666666*p[1][0]*pow(x[3],2.0)*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/
     p[16][0]-0.6666666666666666*p[1][0]*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*p[1][0]*pow(x[3],2.0)*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0],1,2.0*p[1][0]*x[3]*(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+x[3]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-2.0*p[1][0]*x[3]*(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>
     0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0];
    if (isNANorINF(t->fxx[163]))
        {
            PRNT("    @k %d: t->fxx[163] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[163]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
    t->fxx[164]=p[9][0]*(-p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.07407407407407407*pow(p[2][0],2.0)*pow(p[3][0],2.0)/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+0.3333333333333333*pow(p[2][0],2.0)*pow(p[3][0],4.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],4.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),4.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5)-0.3333333333333333*pow(p[2][0],2.0)*pow(p[3][0],2.0)/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),
     2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,3.0*pow(p[2][0],2.0)*pow(p[3][0],4.0)*pow(x[4]-p[2][0]*x[5],2.0)*p[14][0]*p[17][0]/pow(x[3],4.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),4.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),2.5)-pow(p[2][0],2.0)*pow(p[3][0],2.0)*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*p[2][0]*p[3][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=
     3.0*p[14][0]*p[16][0],-0.07407407407407407*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+0.3333333333333333*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),2.0*pow(p[1][0],2.0)*x[3]*p[3]
     [0]*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)-2.0*pow(p[1][0],2.0)*pow(x[3],2.0)*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)-0.2222222222222222*pow(p[1][0],2.0)*pow(x[3],2.0)*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]+0.2222222222222222*pow(p[1][0],2.0)*x[3]*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.2222222222222222*pow(p[1][0],2.0)*pow(x[3],2.0)*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1
     ][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.6666666666666666*pow(p[1][0],2.0)*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*pow(p[1][0],2.0)*pow(x[3],2.0)*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.3333333333333333*p[1][0]*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.6666666666666666*pow(p[1][0],2.0)*pow(x[3],2.0)*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0
     ,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]-0.6666666666666666*pow(p[1][0],2.0)*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*pow(p[1][0],2.0)*pow(x[3],2.0)*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0],1,2.0*pow(p[1][0],2.0)*x[3]*(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+p[1][0]*x[3]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x
     [3]))-2.0*pow(p[1][0],2.0)*x[3]*(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0];
    if (isNANorINF(t->fxx[164]))
        {
            PRNT("    @k %d: t->fxx[164] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[164]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
// j= 6
// j= 7
// d^2f[5]/dx[i] dx[j]
// j= 0
// j= 1
// j= 2
// j= 3
    t->fxx[189]=p[9][0]*(2.0*p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/pow(x[3],3.0)/(1.0+(u[0
     ]-x[3])/(0.001+abs(x[3])))+2.0*p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*
     pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*(-(u[0]-x[3])*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),2.0)+2.0*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)+2.0*(u[0]-x[3])*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),3.0))*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5
     ])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*pow(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0),2.0)*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+
     (u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)-2.0*p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(
     0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3]
     )/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])
     *(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-2.0*p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]
     )))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3
     ][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[
     2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),3.0)-8.0*(u[0]-x[3])*pow(p[4][0],2.0)*mcond(x[3]>0.0,1.0,1,-1.0)*(-1/(1.0+(u[0]-x[3])/(
     0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),3.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+6.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),4.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(2.0*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-(u[0]-x[3])*(-(u[0]-x[3])*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),2.0)+2.0*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)+2.0*(u[0]-x[3])*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),3.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(u[0]-x[3])*pow(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])
     ))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(2.0*(x[4]-p[2][0]*x[5])/pow(x[3],3.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-(x[4]-p[2][0]*x[5])*(-(u[0]-x[3])*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),2.0)+2.0*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)+2.0*(u[0]-x[3])*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),3.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(x[4]-p[2][0]*x[5])*pow(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0),2.0)/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[4][0],2.0)*pow(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0),2.0)/pow(0.001+abs(x[3]),
     2.0)+2.0*pow(p[3][0],2.0)*pow(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),3.0)-8.0*(u[0]-x[3])*pow(p[4][0],2.0)*mcond(x[3]>0.0,1.0,1,-1.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),3.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+6.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),4.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(2.0*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(
     0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-(u[0]-x[3])*(-(u[0]-x[3])*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),2.0)+2.0*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)+2.0*(u[0]-x[3])*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),3.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(u[0]-x[3])*pow(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(2.0*(x[4]-p[2][0]*x[5])/pow(x[3],3.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-(x[4]-p[2][0]*x[5])*(-(u[0]-x[3])*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),2.0)+2.0*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)+2.0*(u[0]-x[3])*pow(mcond(x[3]>0.0,
     1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),3.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(x[4]-p[2][0]*x[5])*pow(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0),2.0)/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[4][0],2.0)*pow(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0),2.0)/pow(0.001+abs(x[3]),2.0)+2.0*pow(p[3][0],2.0)*pow(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0),2.0))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))
     ,2.0))+0.08333333333333333*pow(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/p[14][0]/p[16][0]/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5),1,-0.5*p[14][0]*p[17][0]*(
     -2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),3.0)-8.0*(u[0]-x[3])*pow(p[4][0],2.0)*mcond(x[3]>0.0,1.0,1,-1.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),3.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+6.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),4.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(2.0*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-(u[0]-x[3])*(-(u[0]-x[3])*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),2.0)+2.0*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)+2.0*(u[0]-x[3])*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),3.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+
     2.0*(u[0]-x[3])*pow(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(2.0*(x[4]-p[2][0]*x[5])/pow(x[3],3.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-(x[4]-p[2][0]*x[5])*(-(u[0]-x[3])*mcond(x[3]>0.0,0.0,1,0.0)/pow(0.001+abs(x[3]),2.0)+2.0*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)+2.0*(u[0]-x[3])*pow(mcond(x[3]>0.0,1.0,1,-1.0),2.0)/pow(0.001+abs(x[3]),3.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(x[4]-p[2][0]*x[5])*pow(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0),2.0)/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[4][0],2.0)*
     pow(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0),2.0)/pow(0.001+abs(x[3]),2.0)+2.0*pow(p[3][0],2.0)*pow(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0),2.0))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5)+0.75*p[14][0]*p[17][0]*pow(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)
     )/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),2.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[1][0]*cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-2.0*x[3]*p[3][0]*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)-2.0*p[3][0]*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[
     1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)-0.2222222222222222*pow(p[3][0],3.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.2222222222222222*x[3]*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.2222222222222222*pow(p[3][0],3.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]+0.6666666666666666*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),
     2.0)/p[13][0]/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5
     ],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0],1,-2.0*x[3]*(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+2.0*x[3]*(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[0][0];
    if (isNANorINF(t->fxx[189]))
        {
            PRNT("    @k %d: t->fxx[189] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[189]);
            {
                PRNT("        p[0,0]= %g\n",p[0][0]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
// j= 4
    t->fxx[193]=p[9][0]*(-p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.07407407407407407*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-0.3333333333333333*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]
     -p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.07407407407407407*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-0.3333333333333333*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow
     (x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-p[2][0]*p[3][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/
     p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-p[2][0]*p[3][0]*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*
     pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-1/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(
     x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-1/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]
     -x[3])/(0.001+abs(x[3]))),2.0))+0.16666666666666666*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3]
     [0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5),1,-0.5*p[14][0]*p[17][0]*(2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-1/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5)+1.5*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x
     [3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),2.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[2][0]*p[3][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((
     u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(
     p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-
     x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[1][0]*cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16
     ][0]/p[3][0]),-2.0*p[3][0]*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)+p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))+2.0*x[3]*p[3][0]*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)+0.2222222222222222*x[3]*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.2222222222222222*pow(p[3][0],3.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]+0.1111111111111111*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan
     (-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]+0.2222222222222222*x[3]*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]
     +p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[
     1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0],1,-2.0*pow(x[4]+p[1][0]*x[5],2.0)*p[13][0]*p[16][0]/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+p[13][0]*p[16][0]/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+2.0*pow(x[4]+p[1][0]*x[5],2.0)*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/(-u[1]+atan2(x[4]+p[1][0]*x[5]
     ,x[3]))-p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[0][0];
    if (isNANorINF(t->fxx[193]))
        {
            PRNT("    @k %d: t->fxx[193] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[193]);
            {
                PRNT("        p[0,0]= %g\n",p[0][0]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
    t->fxx[194]=p[9][0]*(p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.07407407407407407*pow(p[3][0],2.0)/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+0.3333333333333333*pow(p[3][0],4.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],4.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),4.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5)-0.3333333333333333*pow(p[3][0],2.0)/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])
     /x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,3.0*pow(p[3][0],4.0)*pow(x[4]-p[2][0]*x[5],2.0)*p[14][0]*p[17][0]/pow(x[3],4.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),4.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),2.5)-pow(p[3][0],2.0)*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*p[2][0]*p[3][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.07407407407407407*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/
     pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-0.3333333333333333*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[1][0]*cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),2.0*x[3]*p[3][0]*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5
     ],2.0),2.0)-2.0*pow(x[3],2.0)*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)-0.2222222222222222*pow(x[3],2.0)*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]+0.2222222222222222*x[3]*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.2222222222222222*pow(x[3],2.0)*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.6666666666666666*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[
     4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*pow(x[3],2.0)*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.3333333333333333*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.6666666666666666*pow(x[3],2.0)*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]-0.6666666666666666*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(
     -u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*pow(x[3],2.0)*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0],1,2.0*x[3]*(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+x[3]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-2.0*x[3]*(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[0][0];
    if (isNANorINF(t->fxx[194]))
        {
            PRNT("    @k %d: t->fxx[194] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[194]);
            {
                PRNT("        p[0,0]= %g\n",p[0][0]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
// j= 5
    t->fxx[198]=p[9][0]*(-p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],-0.07407407407407407*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+0.3333333333333333*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+
     pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],-0.07407407407407407*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+0.3333333333333333*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,p[2][0]*pow(p[3]
     [0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+pow(p[2][0],2.0)*p[3][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[
     2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+pow(p[2][0],2.0)*p[3][0]*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])
     /(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(p[2][0]/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[2][0]*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-2.0*p[2][0]*
     pow(p[3][0],2.0)*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(p[2][0]/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[2][0]*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-2.0*p[2][0]*pow(p[3][0],2.0)*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-
     x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))-0.16666666666666666*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3]
     )),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5),1,-0.5*p[14][0]*p[17][0]*(2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(p[2][0]/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[2][0]*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-2.0*p[2][0]*pow(p[3][0],2.0)*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])
     )),2.0),1.5)-1.5*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*
     x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),2.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-pow(p[2][0],2.0)*p[3][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/
     x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[
     3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(
     0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[1][0]*cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-2.0*p[1][0]*p[3][0]*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)+p[1][0]*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))+2.0*p[1][0]*x[3]*p[3][0]*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)+0.2222222222222222*p[1][0]*x[3]*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.2222222222222222*p[1][0]*pow(p[3][0],3.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[
     4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]+0.1111111111111111*p[1][0]*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]+0.2222222222222222*p[1][0]*x[3]*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]+0.6666666666666666*p[1][0]*pow(p[3][0],2.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]-0.3333333333333333*p[1][0]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[
     16][0]-0.6666666666666666*p[1][0]*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*p[1][0]*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*p[1][0]*pow(p[3][0],2.0)*pow(x[4]+p[1][0]*x[5],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][
     0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]-0.3333333333333333*p[1][0]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*p[1][0]*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0],1,-2.0*p[1][0]*pow(x[4]+p[1][0]*x[5],2.0)*p[13][0]*p[16][0]/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+p[1][0]*p[13][0]*p[16][0]/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[
     3])>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+2.0*p[1][0]*pow(x[4]+p[1][0]*x[5],2.0)*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-p[1][0]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[0][0];
    if (isNANorINF(t->fxx[198]))
        {
            PRNT("    @k %d: t->fxx[198] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[198]);
            {
                PRNT("        p[0,0]= %g\n",p[0][0]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
    t->fxx[199]=p[9][0]*(p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],-0.07407407407407407*p[2][0]*pow(p[3][0],2.0)/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-0.3333333333333333*p[2][0]*pow(p[3][0],4.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],4.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),4.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5)+0.3333333333333333*p[2][0]*pow(p[3][0],2.0)/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0
     )*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-3.0*p[2][0]*pow(p[3][0],4.0)*pow(x[4]-p[2][0]*x[5],2.0)*p[14][0]*p[17][0]/pow(x[3],4.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),4.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),2.5)+p[2][0]*pow(p[3][0],2.0)*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-pow(p[2][0],2.0)*p[3][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],
     0.07407407407407407*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-0.3333333333333333*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[2][0]*p[3][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3
     ]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],-0.07407407407407407*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+0.3333333333333333*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[1][0]*cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13
     ][0]*p[16][0]/p[3][0]),2.0*p[1][0]*x[3]*p[3][0]*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)-2.0*p[1][0]*pow(x[3],2.0)*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)-0.2222222222222222*p[1][0]*pow(x[3],2.0)*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]+0.2222222222222222*p[1][0]*x[3]*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.2222222222222222*p[1][0]*pow(x[3],2.0)*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(pow(x[3],2.0)+pow(
     x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.6666666666666666*p[1][0]*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*p[1][0]*pow(x[3],2.0)*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.3333333333333333*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.6666666666666666*p[1][0]*pow(x[3],2.0)*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+
     pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]-0.6666666666666666*p[1][0]*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*p[1][0]*pow(x[3],2.0)*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0],1,2.0*p[1][0]*x[3]*(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+x[3]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-2.0*p[1][0]*x[3]*(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*
     mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[0][0];
    if (isNANorINF(t->fxx[199]))
        {
            PRNT("    @k %d: t->fxx[199] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[199]);
            {
                PRNT("        p[0,0]= %g\n",p[0][0]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
    t->fxx[200]=p[9][0]*(p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.07407407407407407*pow(p[2][0],2.0)*pow(p[3][0],2.0)/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+0.3333333333333333*pow(p[2][0],2.0)*pow(p[3][0],4.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],4.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),4.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5)-0.3333333333333333*pow(p[2][0],2.0)*pow(p[3][0],2.0)/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(
     x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,3.0*pow(p[2][0],2.0)*pow(p[3][0],4.0)*pow(x[4]-p[2][0]*x[5],2.0)*p[14][0]*p[17][0]/pow(x[3],4.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),4.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),2.5)-pow(p[2][0],2.0)*pow(p[3][0],2.0)*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-2.0*pow(p[2][0],2.0)*p[3][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(
     x[3]))),2.0))<=3.0*p[14][0]*p[16][0],-0.07407407407407407*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+0.3333333333333333*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[1][0]*cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),2.0*pow
     (p[1][0],2.0)*x[3]*p[3][0]*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)-2.0*pow(p[1][0],2.0)*pow(x[3],2.0)*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)-0.2222222222222222*pow(p[1][0],2.0)*pow(x[3],2.0)*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]+0.2222222222222222*pow(p[1][0],2.0)*x[3]*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.2222222222222222*pow(p[1][0],2.0)*pow(x[3],2.0)*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(pow
     (x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/pow(p[13][0],2.0)/p[16][0]-0.6666666666666666*pow(p[1][0],2.0)*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*pow(p[1][0],2.0)*pow(x[3],2.0)*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.3333333333333333*p[1][0]*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.6666666666666666*pow(p[1][0],2.0)*pow(x[3],2.0)*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1]
     [0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]-0.6666666666666666*pow(p[1][0],2.0)*x[3]*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0]+0.6666666666666666*pow(p[1][0],2.0)*pow(x[3],2.0)*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/p[13][0]/p[16][0],1,2.0*pow(p[1][0],2.0)*x[3]*(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+p[1][0]*x[3]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+
     atan2(x[4]+p[1][0]*x[5],x[3]))-2.0*pow(p[1][0],2.0)*x[3]*(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/pow(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0),2.0)/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[0][0];
    if (isNANorINF(t->fxx[200]))
        {
            PRNT("    @k %d: t->fxx[200] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxx[200]);
            {
                PRNT("        p[0,0]= %g\n",p[0][0]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
            }
            return(0);
        }
// j= 6
// j= 7
// d^2f[6]/dx[i] dx[j]
// j= 0
// j= 1
// j= 2
// j= 3
// j= 4
// j= 5
// j= 6
// j= 7
// d^2f[7]/dx[i] dx[j]
// j= 0
// j= 1
// j= 2
// j= 3
// j= 4
// j= 5
// j= 6
// j= 7

// d^2f[0]/du[i] du[j]
// j= 0
// j= 1
// d^2f[1]/du[i] du[j]
// j= 0
// j= 1
// d^2f[2]/du[i] du[j]
// j= 0
// j= 1
// d^2f[3]/du[i] du[j]
// j= 0
    t->fuu[9]=p[9][0]*((u[0]-x[3])*p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(6.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),4.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(2.0*(u[0]-x[3])/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)-2.0/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[4][0],2.0)*pow(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(6.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+
     abs(x[3])),4.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(2.0*(u[0]-x[3])/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)-2.0/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[4][0],2.0)*pow(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))+0.08333333333333333*pow(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),
     2.0)/p[14][0]/p[16][0]/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5),1,-0.5*p[14][0]*p[17][0]*(6.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),4.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(2.0*(u[0]-x[3])/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)-2.0/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[4][0],2.0)*pow(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5)+0.75*p[14][0]
     *p[17][0]*pow(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),2.5))/(0.001+abs(x[3]))/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-2.0*(u[0]-x[3])*p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0
     *(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0
     ]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]
     -x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p
     [4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/(0.001+abs(x[3]))/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*(u[0]-x[3])*p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[
     4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/pow(0.001+abs(x[3]),3.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)-2.0*p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][
     0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/p[15][0];
    if (isNANorINF(t->fuu[9]))
        {
            PRNT("    @k %d: t->fuu[9] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fuu[9]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
            }
            return(0);
        }
// j= 1
    t->fuu[11]=p[9][0]*(sin(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-p[3][0]*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-0.037037037037037035*pow(p[3][0],3.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(p[13][0],2.0)/p[16][0]+0.3333333333333333*pow(p[3][0],2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/p[13][0]/p[16][0],1,-p[13][0]*p[16][0]*(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))-2.0*cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)+0.1111111111111111*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(p[13][0],2.0)/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/p[13][0]/p[16][0]
     -0.3333333333333333*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/p[13][0]/p[16][0],1,p[13][0]*p[16][0]/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))-sin(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-2.0*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-0.2222222222222222*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(p[13][0],2.0)/p[16][0]-0.2222222222222222*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(p[13][0],2.0)/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]
     +atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/p[13][0]/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/p[13][0]/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/p[13][0]/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/p[13][0]/p[16][0],1,-p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,0.0,1,0.0)/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0];
    if (isNANorINF(t->fuu[11]))
        {
            PRNT("    @k %d: t->fuu[11] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fuu[11]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
            }
            return(0);
        }
// d^2f[4]/du[i] du[j]
// j= 0
    t->fuu[12]=p[9][0]*(-p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(6.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),4.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(2.0*(u[0]-x[3])/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)-2.0/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[4][0],2.0)*pow(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(6.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3
     ])/(0.001+abs(x[3])),4.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(2.0*(u[0]-x[3])/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)-2.0/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[4][0],2.0)*pow(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))+0.08333333333333333*pow(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+
     abs(x[3]))),2.0)/p[14][0]/p[16][0]/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5),1,-0.5*p[14][0]*p[17][0]*(6.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),4.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(2.0*(u[0]-x[3])/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)-2.0/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[4][0],2.0)*pow(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5)+
     0.75*p[14][0]*p[17][0]*pow(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),2.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),
     3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0
     )*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-2.0*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[
     3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/x[3]/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/p[15][0];
    if (isNANorINF(t->fuu[12]))
        {
            PRNT("    @k %d: t->fuu[12] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fuu[12]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
            }
            return(0);
        }
// j= 1
    t->fuu[14]=p[9][0]*(-cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-p[3][0]*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-0.037037037037037035*pow(p[3][0],3.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(p[13][0],2.0)/p[16][0]+0.3333333333333333*pow(p[3][0],2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/p[13][0]/p[16][0],1,-p[13][0]*p[16][0]*(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))-2.0*sin(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)+0.1111111111111111*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(p[13][0],2.0)/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/p[13][0]/p[16][0]
     -0.3333333333333333*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/p[13][0]/p[16][0],1,p[13][0]*p[16][0]/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))+cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-2.0*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-0.2222222222222222*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(p[13][0],2.0)/p[16][0]-0.2222222222222222*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(p[13][0],2.0)/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]
     +atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/p[13][0]/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/p[13][0]/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/p[13][0]/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/p[13][0]/p[16][0],1,-p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,0.0,1,0.0)/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0];
    if (isNANorINF(t->fuu[14]))
        {
            PRNT("    @k %d: t->fuu[14] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fuu[14]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
            }
            return(0);
        }
// d^2f[5]/du[i] du[j]
// j= 0
    t->fuu[15]=p[9][0]*(p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(6.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),4.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(2.0*(u[0]-x[3])/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)-2.0/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[4][0],2.0)*pow(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(6.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u
     [0]-x[3])/(0.001+abs(x[3])),4.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(2.0*(u[0]-x[3])/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)-2.0/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[4][0],2.0)*pow(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))+0.08333333333333333*pow(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(
     0.001+abs(x[3]))),2.0)/p[14][0]/p[16][0]/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5),1,-0.5*p[14][0]*p[17][0]*(6.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),4.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(2.0*(u[0]-x[3])/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)-2.0/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[4][0],2.0)*pow(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),
     1.5)+0.75*p[14][0]*p[17][0]*pow(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),2.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-2.0*p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(
     0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3]
     )*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(
     p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/x[3]/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/p[0][0];
    if (isNANorINF(t->fuu[15]))
        {
            PRNT("    @k %d: t->fuu[15] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fuu[15]);
            {
                PRNT("        p[0,0]= %g\n",p[0][0]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
            }
            return(0);
        }
// j= 1
    t->fuu[17]=p[9][0]*(-p[1][0]*cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-p[3][0]*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-0.037037037037037035*pow(p[3][0],3.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(p[13][0],2.0)/p[16][0]+0.3333333333333333*pow(p[3][0],2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/p[13][0]/p[16][0],1,-p[13][0]*p[16][0]*(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))-2.0*p[1][0]*sin(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)+0.1111111111111111*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/pow(p[13][0],2.0)/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/p[13][0
     ]/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/p[13][0]/p[16][0],1,p[13][0]*p[16][0]/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))+p[1][0]*cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-2.0*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-0.2222222222222222*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/pow(p[13][0],2.0)/p[16][0]-0.2222222222222222*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/pow(p[13][0],2.0)/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3
     ])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/p[13][0]/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/p[13][0]/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/p[13][0]/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/p[13][0]/p[16][0],1,-p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,0.0,1,0.0)/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[0][0];
    if (isNANorINF(t->fuu[17]))
        {
            PRNT("    @k %d: t->fuu[17] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fuu[17]);
            {
                PRNT("        p[0,0]= %g\n",p[0][0]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
            }
            return(0);
        }
// d^2f[6]/du[i] du[j]
// j= 0
// j= 1
// d^2f[7]/du[i] du[j]
// j= 0
// j= 1

// d^2f[0]/dx[i] du[j]
// j= 0
// j= 1
// d^2f[1]/dx[i] du[j]
// j= 0
// j= 1
// d^2f[2]/dx[i] du[j]
// j= 0
// j= 1
// d^2f[3]/dx[i] du[j]
// j= 0
    t->fxu[51]=p[9][0]*(-p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p
     [14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/(0.001+abs(x[3]))/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*p[4][0]*mcond(x[3]>0.0,1.0,1,-1.0)*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow
     ((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[
     5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*p[4][0]*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],
     0.037037037037037035*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[3][
     0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(
     0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(u[0]-x[3])*p[4][0]*mcond(x[3]>0.0,1.0,1,-1.0)*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p
     [2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/pow(0.001+abs(x[3]),3.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-p[4][0]*mcond(x[3]>0.0,1.0,1,-1.0)*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3]
     [0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*(u[0]-x[3])*p[4][0]*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*
     pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)-p[4][0]*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(
     x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+(u[0]-x[3])*p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[
     3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-4.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*((x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+(x[4]-p[2][0]*x[5])*mcond(x[3]>0.0,1.0,1,-1.0)/x[3]/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(1/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(u[0]-x[3])*(-1/(
     0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)-(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)-2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(
     0.001+abs(x[3])),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-4.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*((x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+(x[4]-p[2][0]*x[5])*mcond(x[3]>0.0,1.0,1,-1.0)/x[3]/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(1/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)
     +2.0*(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)-(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)-2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(0.001+abs(x[3]))/pow
     (1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))+0.08333333333333333*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/
     (0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5),1,-0.5*p[14][0]*p[17][0]*(-4.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*((x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+(x[4]-p[2][0]*x[5])*mcond(x[3]>0.0,1.0,1,-1.0)/x[3]/
     pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(1/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)-(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))*(-1/(1.0+(u[0
     ]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)-2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5)+0.75*p[14][0]*p[17][0]*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-
     x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),
     2.0),2.5))/(0.001+abs(x[3]))/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3
     ])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]
     /(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/pow(0.001+
     abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0
     +(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(
     0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/(0.001+abs(x[3]))/(1.0+(u[0]-x
     [3])/(0.001+abs(x[3]))))/p[15][0];
    if (isNANorINF(t->fxu[51]))
        {
            PRNT("    @k %d: t->fxu[51] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxu[51]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
            }
            return(0);
        }
    t->fxu[52]=p[9][0]*((u[0]-x[3])*p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],-0.14814814814814814*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+0.16666666666666666*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),
     2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5)+0.6666666666666666*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,1.5*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+
     pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),2.5)+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/(0.001+abs(x[3]))/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.07407407407407407*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-0.3333333333333333*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),
     2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.07407407407407407*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-0.3333333333333333*pow(p[3][0],2.0)*(x[4
     ]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/(0.001+abs(x[3]))/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[15][0];
    if (isNANorINF(t->fxu[52]))
        {
            PRNT("    @k %d: t->fxu[52] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxu[52]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
            }
            return(0);
        }
    t->fxu[53]=p[9][0]*((u[0]-x[3])*p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.14814814814814814*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)-0.16666666666666666*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(
     0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5)-0.6666666666666666*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-1.5*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))
     ,2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),2.5)-2.0*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/(0.001+abs(x[3]))/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],-0.07407407407407407*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+0.3333333333333333*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[
     14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+p[4][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],-0.07407407407407407*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]
     -x[3])/(0.001+abs(x[3])),2.0)+0.3333333333333333*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/(0.001+abs(x[3]))/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[15][0];
    if (isNANorINF(t->fxu[53]))
        {
            PRNT("    @k %d: t->fxu[53] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxu[53]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
            }
            return(0);
        }
// j= 1
    t->fxu[59]=p[9][0]*(-cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),p[3][0]*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))+0.1111111111111111*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0],1,(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]/(pow(x[3],
     2.0)+pow(x[4]+p[1][0]*x[5],2.0))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))-sin(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-2.0*p[3][0]*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))-0.2222222222222222*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]-0.2222222222222222*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*(x[
     4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0],
     1,-(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0];
    if (isNANorINF(t->fxu[59]))
        {
            PRNT("    @k %d: t->fxu[59] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxu[59]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
            }
            return(0);
        }
    t->fxu[60]=p[9][0]*(-cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-x[3]*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))-0.1111111111111111*x[3]*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]+0.3333333333333333*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.3333333333333333*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0],1,-x[3]*p[13][0]*p[16][0]/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))
     +x[3]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))-sin(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),2.0*x[3]*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))+0.2222222222222222*x[3]*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]+0.2222222222222222*x[3]*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]-0.6666666666666666*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3
     ])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.3333333333333333*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0],1,x[3]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0];
    if (isNANorINF(t->fxu[60]))
        {
            PRNT("    @k %d: t->fxu[60] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxu[60]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
            }
            return(0);
        }
    t->fxu[61]=p[9][0]*(-cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-p[1][0]*x[3]*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))-0.1111111111111111*p[1][0]*x[3]*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]+0.3333333333333333*p[1][0]*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.3333333333333333*p[1][0]*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0],1,-p[1][0]*x[3]*p[13][0]*p[16][0]/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/
     abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+p[1][0]*x[3]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))-sin(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),2.0*p[1][0]*x[3]*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))+0.2222222222222222*p[1][0]*x[3]*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]+0.2222222222222222*p[1][0]*x[3]*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]-0.6666666666666666*p[1][0]*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*
     tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.3333333333333333*p[1][0]*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*p[1][0]*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*p[1][0]*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0],1,p[1][0]*x[3]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,0.0,1,0.0
     )/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0];
    if (isNANorINF(t->fxu[61]))
        {
            PRNT("    @k %d: t->fxu[61] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxu[61]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
            }
            return(0);
        }
// d^2f[4]/dx[i] du[j]
// j= 0
    t->fxu[67]=p[9][0]*(p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(
     0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[3][0]*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(
     1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(
     0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+
     0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-p[3][0]*(x[4]-p[2][0]*x[5])*mcond(x[3]>0.0,1.0,1,-1.0)*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(
     0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/x[3]/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-2.0*p[3][0]*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(
     0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)-p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u
     [0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-4.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*((x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+(x[4]-p[2][0]*x[5])*mcond(x[3]>0.0,1.0,1,-1.0)/x[3]/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(1/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3]))
     ,2.0)+(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)-(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)-2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,
     1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-4.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*((x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+(x[4]-p[2][0]*x[5])*mcond(x[3]>0.0,1.0,1,-1.0)/x[3]/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(1/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3]
     )/(0.001+abs(x[3])),2.0)+(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)-(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)-2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3
     ])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))+0.08333333333333333*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[
     3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5),1,-0.5*p[14][0]*p[17][0]*(-4.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*((x[4]-p[2][0]*x[5
     ])/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+(x[4]-p[2][0]*x[5])*mcond(x[3]>0.0,1.0,1,-1.0)/x[3]/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(1/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)-(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[4][0],
     2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)-2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5)+0.75*p[14][0]*p[17][0]*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x
     [3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(
     0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),2.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(
     -1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*
     pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/
     pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/p[15][0];
    if (isNANorINF(t->fxu[67]))
        {
            PRNT("    @k %d: t->fxu[67] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxu[67]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
            }
            return(0);
        }
    t->fxu[68]=p[9][0]*(-p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],-0.14814814814814814*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+0.16666666666666666*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs
     (x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5)+0.6666666666666666*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,1.5*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),
     2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),2.5)+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.07407407407407407*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-0.3333333333333333*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),
     2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-p[3][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])
     /(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3
     ])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[3][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2
     ][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/p[15][0];
    if (isNANorINF(t->fxu[68]))
        {
            PRNT("    @k %d: t->fxu[68] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxu[68]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
            }
            return(0);
        }
    t->fxu[69]=p[9][0]*(-p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.14814814814814814*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)-0.16666666666666666*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0
     )/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5)-0.6666666666666666*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-1.5*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x
     [3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),2.5)-2.0*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],-0.07407407407407407*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+0.3333333333333333*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p
     [14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+p[2][0]*p[3][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])
     /(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[
     3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-p[2][0]*p[3][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(
     0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/p[15][0];
    if (isNANorINF(t->fxu[69]))
        {
            PRNT("    @k %d: t->fxu[69] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxu[69]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
            }
            return(0);
        }
// j= 1
    t->fxu[75]=p[9][0]*(-sin(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),p[3][0]*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))+0.1111111111111111*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0],1,(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]/(pow(x[3],
     2.0)+pow(x[4]+p[1][0]*x[5],2.0))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))+cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-2.0*p[3][0]*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))-0.2222222222222222*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]-0.2222222222222222*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*(x[
     4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0],
     1,-(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0];
    if (isNANorINF(t->fxu[75]))
        {
            PRNT("    @k %d: t->fxu[75] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxu[75]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
            }
            return(0);
        }
    t->fxu[76]=p[9][0]*(-sin(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-x[3]*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))-0.1111111111111111*x[3]*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]+0.3333333333333333*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.3333333333333333*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0],1,-x[3]*p[13][0]*p[16][0]/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))
     +x[3]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))+cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),2.0*x[3]*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))+0.2222222222222222*x[3]*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]+0.2222222222222222*x[3]*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]-0.6666666666666666*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3
     ])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.3333333333333333*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0],1,x[3]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0];
    if (isNANorINF(t->fxu[76]))
        {
            PRNT("    @k %d: t->fxu[76] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxu[76]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
            }
            return(0);
        }
    t->fxu[77]=p[9][0]*(-sin(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-p[1][0]*x[3]*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))-0.1111111111111111*p[1][0]*x[3]*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]+0.3333333333333333*p[1][0]*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.3333333333333333*p[1][0]*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0],1,-p[1][0]*x[3]*p[13][0]*p[16][0]/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/
     abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+p[1][0]*x[3]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))+cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),2.0*p[1][0]*x[3]*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))+0.2222222222222222*p[1][0]*x[3]*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]+0.2222222222222222*p[1][0]*x[3]*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]-0.6666666666666666*p[1][0]*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*
     tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.3333333333333333*p[1][0]*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*p[1][0]*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*p[1][0]*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0],1,p[1][0]*x[3]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,0.0,1,0.0
     )/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[15][0];
    if (isNANorINF(t->fxu[77]))
        {
            PRNT("    @k %d: t->fxu[77] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxu[77]);
            {
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[15,0]= %g\n",p[15][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
            }
            return(0);
        }
// d^2f[5]/dx[i] du[j]
// j= 0
    t->fxu[83]=p[9][0]*(-p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]
     -x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))*mcond(sqrt(pow(p[4][0],2.0)*
     pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(
     1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*
     p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(x[3]>0.0,1.0,1,-1.0)*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5
     ])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/x[3]/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))*mcond(sqrt(pow(p[4][0],2.0)*pow
     ((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(
     pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-4.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*((x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+(x[4]-p[2][0]*x[5])*mcond(x[3]>0.0,1.0,1,-1.0)/x[3]/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(1/(0.001+abs(x[3]
     ))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)-(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)-2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001
     +abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-4.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*((x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+(x[4]-p[2][0]*x[5])*mcond(x[3]>0.0,1.0,1,-1.0)/x[3]/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*
     (1/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)-(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)-2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0
     ]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))+0.08333333333333333*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1
     /(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5),1,-0.5*p[14][0]*p[17][0]*(-4.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)
     *(x[4]-p[2][0]*x[5])*((x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+(x[4]-p[2][0]*x[5])*mcond(x[3]>0.0,1.0,1,-1.0)/x[3]/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(1/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+2.0*(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)-(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3]
     )/(0.001+abs(x[3])))+2.0*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)-2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5)+0.75*p[14][0]*p[17][0]*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[
     3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],
     2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),2.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]
     -x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]
     ))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-1/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(u[0]-x[3])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-(x[4]-p[2][0]*x[5])*(-1/(0.001+abs(x[3]))-(u[0]-x[3])*mcond(x[3]>0.0,1.0,1,-1.0)/pow(0.001+abs(x[3]),2.0))/x[3]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3]
     )/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/p[0][0];
    if (isNANorINF(t->fxu[83]))
        {
            PRNT("    @k %d: t->fxu[83] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxu[83]);
            {
                PRNT("        p[0,0]= %g\n",p[0][0]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
            }
            return(0);
        }
    t->fxu[84]=p[9][0]*(p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],-0.14814814814814814*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+0.16666666666666666*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(
     0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5)+0.6666666666666666*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,1.5*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+
     abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),2.5)+2.0*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.07407407407407407*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-0.3333333333333333*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(
     0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+p[2][0]*p[3][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p
     [4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs
     (x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-p[2][0]*p[3][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),
     2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/p[0][0];
    if (isNANorINF(t->fxu[84]))
        {
            PRNT("    @k %d: t->fxu[84] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxu[84]);
            {
                PRNT("        p[0,0]= %g\n",p[0][0]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
            }
            return(0);
        }
    t->fxu[85]=p[9][0]*(p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.14814814814814814*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)-0.16666666666666666*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]
     ))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5)-0.6666666666666666*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/p[14][0]/p[16][0]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-1.5*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(
     0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),2.5)-2.0*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))-p[2][0]*p[3][0]*(x[4]-p[2][0]*x[5])*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],-0.07407407407407407*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])/pow(x[3],2.0)/pow(p[14][0],2.0)/pow(p[16][0],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+0.3333333333333333*p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[
     5])/pow(x[3],2.0)/p[14][0]/p[16][0]/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,p[2][0]*pow(p[3][0],2.0)*(x[4]-p[2][0]*x[5])*p[14][0]*p[17][0]/pow(x[3],2.0)/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)-pow(p[2][0],2.0)*p[3][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],0.037037037037037035*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+
     abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.16666666666666666*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/p[14][0]/p[16][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)),1,-0.5*p[14][0]*p[17][0]*(-2.0*pow(p[3][0],2.0)*pow(x[4]-p[2][0]*x[5],2.0)/pow(x[3],2.0)/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(
     0.001+abs(x[3])),3.0)+2.0*(u[0]-x[3])*pow(p[4][0],2.0)*(-(u[0]-x[3])/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0)+1/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(0.001+abs(x[3]),2.0)/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))))/pow(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0),1.5))/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3])))+pow(p[2][0],2.0)*p[3][0]*mcond(sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))<=3.0*p[14][0]*p[16][0],1.0+0.037037037037037035*(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/pow(p[14][0],2.0)/pow(p[16][0],2.0)-0.3333333333333333*sqrt(pow(p[4]
     [0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0))/p[14][0]/p[16][0],1,p[14][0]*p[17][0]/sqrt(pow(p[4][0],2.0)*pow((u[0]-x[3])/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)/pow(0.001+abs(x[3]),2.0)+pow(p[3][0],2.0)*pow((x[4]-p[2][0]*x[5])/x[3]/(1.0+(u[0]-x[3])/(0.001+abs(x[3]))),2.0)))/x[3]/(0.001+abs(x[3]))/pow(1.0+(u[0]-x[3])/(0.001+abs(x[3])),2.0))/p[0][0];
    if (isNANorINF(t->fxu[85]))
        {
            PRNT("    @k %d: t->fxu[85] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxu[85]);
            {
                PRNT("        p[0,0]= %g\n",p[0][0]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[2,0]= %g\n",p[2][0]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[4,0]= %g\n",p[4][0]);
                PRNT("        p[14,0]= %g\n",p[14][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
                PRNT("        p[17,0]= %g\n",p[17][0]);
            }
            return(0);
        }
// j= 1
    t->fxu[91]=p[9][0]*(-p[1][0]*sin(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),p[3][0]*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))+0.1111111111111111*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0],1,(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]/(
     pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))-(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))+p[1][0]*cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-2.0*p[3][0]*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))-0.2222222222222222*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]-0.2222222222222222*pow(p[3][0],3.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]+0.6666666666666666*pow
     (p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.3333333333333333*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.6666666666666666*pow(p[3][0],2.0)*(x[4]+p[1][0]*x[5])*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p
     [13][0]/p[16][0],1,-(x[4]+p[1][0]*x[5])*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[0][0];
    if (isNANorINF(t->fxu[91]))
        {
            PRNT("    @k %d: t->fxu[91] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxu[91]);
            {
                PRNT("        p[0,0]= %g\n",p[0][0]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
            }
            return(0);
        }
    t->fxu[92]=p[9][0]*(-p[1][0]*sin(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-x[3]*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))-0.1111111111111111*x[3]*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]+0.3333333333333333*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.3333333333333333*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0],1,-x[3]*p[13][0]*p[16][0]/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5
     ],x[3]))+x[3]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))+p[1][0]*cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),2.0*x[3]*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))+0.2222222222222222*x[3]*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]+0.2222222222222222*x[3]*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]-0.6666666666666666*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+
     p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.3333333333333333*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0],1,x[3]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[0][0];
    if (isNANorINF(t->fxu[92]))
        {
            PRNT("    @k %d: t->fxu[92] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxu[92]);
            {
                PRNT("        p[0,0]= %g\n",p[0][0]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
            }
            return(0);
        }
    t->fxu[93]=p[9][0]*(-p[1][0]*sin(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),-p[1][0]*x[3]*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))-0.1111111111111111*p[1][0]*x[3]*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]+0.3333333333333333*p[1][0]*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.3333333333333333*p[1][0]*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0],1,-p[1][0]*x[3]*p[13][0]*p[16][0]/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5
     ],2.0))/abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))+p[1][0]*x[3]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))+p[1][0]*cos(u[1])*mcond(abs(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))<=atan(3.0*p[13][0]*p[16][0]/p[3][0]),2.0*p[1][0]*x[3]*p[3][0]*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))+0.2222222222222222*p[1][0]*x[3]*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]+0.2222222222222222*p[1][0]*x[3]*pow(p[3][0],3.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),3.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/pow(p[13][0],2.0)/p[16][0]-0.6666666666666666*p[1][0]*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5
     ],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*abs(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])))/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]+0.3333333333333333*p[1][0]*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*p[1][0]*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),4.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0]-0.6666666666666666*p[1][0]*x[3]*pow(p[3][0],2.0)*pow(sec(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*pow(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])),2.0)*mcond(tan(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))>0.0,1.0,1,-1.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/p[13][0]/p[16][0],1,p[1][0]*x[3]*p[13][0]*p[16][0]*mcond(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3])
     >0.0,0.0,1,0.0)/(pow(x[3],2.0)+pow(x[4]+p[1][0]*x[5],2.0))/(-u[1]+atan2(x[4]+p[1][0]*x[5],x[3]))))/p[0][0];
    if (isNANorINF(t->fxu[93]))
        {
            PRNT("    @k %d: t->fxu[93] in line %d is nan or inf: %g\n", k, __LINE__-3,t->fxu[93]);
            {
                PRNT("        p[0,0]= %g\n",p[0][0]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        p[1,0]= %g\n",p[1][0]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[3,0]= %g\n",p[3][0]);
                PRNT("        p[13,0]= %g\n",p[13][0]);
                PRNT("        p[16,0]= %g\n",p[16][0]);
            }
            return(0);
        }
// d^2f[6]/dx[i] du[j]
// j= 0
// j= 1
// d^2f[7]/dx[i] du[j]
// j= 0
// j= 1
#endif

// derivatives of L
    t->cx[0]=x[0]*p[8][0]/sqrt(pow(x[0],2.0)+pow(p[19][0],2.0));
    if (isNANorINF(t->cx[0]))
        {
            PRNT("    @k %d: t->cx[0] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cx[0]);
            {
                PRNT("        p[8,0]= %g\n",p[8][0]);
                PRNT("        x[0]= %g\n",x[0]);
                PRNT("        p[19,0]= %g\n",p[19][0]);
            }
            return(0);
        }
    t->cx[1]=x[1]*p[8][1]/sqrt(pow(x[1],2.0)+pow(p[19][1],2.0));
    if (isNANorINF(t->cx[1]))
        {
            PRNT("    @k %d: t->cx[1] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cx[1]);
            {
                PRNT("        p[8,1]= %g\n",p[8][1]);
                PRNT("        x[1]= %g\n",x[1]);
                PRNT("        p[19,1]= %g\n",p[19][1]);
            }
            return(0);
        }
    t->cx[2]=0.0;
    t->cx[3]=p[8][3]*(x[3]-p[10][0])/sqrt(pow(x[3]-p[10][0],2.0)+pow(p[19][3],2.0))-x[4]*p[8][4]*(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]))/(pow(x[3],2.0)+pow(x[4],2.0))/sqrt(pow(p[19][4],2.0)+pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0));
    if (isNANorINF(t->cx[3]))
        {
            PRNT("    @k %d: t->cx[3] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cx[3]);
            {
                PRNT("        p[8,3]= %g\n",p[8][3]);
                PRNT("        p[10,0]= %g\n",p[10][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[19,3]= %g\n",p[19][3]);
                PRNT("        p[8,4]= %g\n",p[8][4]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[10,1]= %g\n",p[10][1]);
                PRNT("        p[19,4]= %g\n",p[19][4]);
            }
            return(0);
        }
    t->cx[4]=x[3]*p[8][4]*(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]))/(pow(x[3],2.0)+pow(x[4],2.0))/sqrt(pow(p[19][4],2.0)+pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0));
    if (isNANorINF(t->cx[4]))
        {
            PRNT("    @k %d: t->cx[4] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cx[4]);
            {
                PRNT("        p[8,4]= %g\n",p[8][4]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[10,1]= %g\n",p[10][1]);
                PRNT("        p[10,0]= %g\n",p[10][0]);
                PRNT("        p[19,4]= %g\n",p[19][4]);
            }
            return(0);
        }
    t->cx[5]=p[8][5]*(x[5]-p[10][2])/sqrt(pow(x[5]-p[10][2],2.0)+pow(p[19][5],2.0));
    if (isNANorINF(t->cx[5]))
        {
            PRNT("    @k %d: t->cx[5] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cx[5]);
            {
                PRNT("        p[8,5]= %g\n",p[8][5]);
                PRNT("        p[10,2]= %g\n",p[10][2]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        p[19,5]= %g\n",p[19][5]);
            }
            return(0);
        }
    t->cx[6]=-2.0*p[5][0]*(u[0]-x[6])/pow(p[9][0],2.0);
    if (isNANorINF(t->cx[6]))
        {
            PRNT("    @k %d: t->cx[6] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cx[6]);
            {
                PRNT("        p[5,0]= %g\n",p[5][0]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[6]= %g\n",x[6]);
                PRNT("        u[0]= %g\n",u[0]);
            }
            return(0);
        }
    t->cx[7]=-2.0*p[5][1]*(u[1]-x[7])/pow(p[9][0],2.0);
    if (isNANorINF(t->cx[7]))
        {
            PRNT("    @k %d: t->cx[7] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cx[7]);
            {
                PRNT("        p[5,1]= %g\n",p[5][1]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[7]= %g\n",x[7]);
                PRNT("        u[1]= %g\n",u[1]);
            }
            return(0);
        }

    t->cxx[0]=-pow(x[0],2.0)*p[8][0]/pow(pow(x[0],2.0)+pow(p[19][0],2.0),1.5)+p[8][0]/sqrt(pow(x[0],2.0)+pow(p[19][0],2.0));
    if (isNANorINF(t->cxx[0]))
        {
            PRNT("    @k %d: t->cxx[0] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cxx[0]);
            {
                PRNT("        p[8,0]= %g\n",p[8][0]);
                PRNT("        x[0]= %g\n",x[0]);
                PRNT("        p[19,0]= %g\n",p[19][0]);
            }
            return(0);
        }
    t->cxx[1]=0.0;
    t->cxx[2]=-pow(x[1],2.0)*p[8][1]/pow(pow(x[1],2.0)+pow(p[19][1],2.0),1.5)+p[8][1]/sqrt(pow(x[1],2.0)+pow(p[19][1],2.0));
    if (isNANorINF(t->cxx[2]))
        {
            PRNT("    @k %d: t->cxx[2] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cxx[2]);
            {
                PRNT("        p[8,1]= %g\n",p[8][1]);
                PRNT("        x[1]= %g\n",x[1]);
                PRNT("        p[19,1]= %g\n",p[19][1]);
            }
            return(0);
        }
    t->cxx[3]=0.0;
    t->cxx[4]=0.0;
    t->cxx[5]=0.0;
    t->cxx[6]=0.0;
    t->cxx[7]=0.0;
    t->cxx[8]=0.0;
    t->cxx[9]=-p[8][3]*pow(x[3]-p[10][0],2.0)/pow(pow(x[3]-p[10][0],2.0)+pow(p[19][3],2.0),1.5)+p[8][3]/sqrt(pow(x[3]-p[10][0],2.0)+pow(p[19][3],2.0))+pow(x[4],2.0)*p[8][4]/pow(pow(x[3],2.0)+pow(x[4],2.0),2.0)/sqrt(pow(p[19][4],2.0)+pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0))-pow(x[4],2.0)*p[8][4]*pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0)/pow(pow(x[3],2.0)+pow(x[4],2.0),2.0)/pow(pow(p[19][4],2.0)+pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0),1.5)+2.0*x[3]*x[4]*p[8][4]*(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]))/pow(pow(x[3],2.0)+pow(x[4],2.0),2.0)/sqrt(pow(p[19][4],2.0)+pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0));
    if (isNANorINF(t->cxx[9]))
        {
            PRNT("    @k %d: t->cxx[9] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cxx[9]);
            {
                PRNT("        p[8,3]= %g\n",p[8][3]);
                PRNT("        p[10,0]= %g\n",p[10][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[19,3]= %g\n",p[19][3]);
                PRNT("        p[8,4]= %g\n",p[8][4]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[10,1]= %g\n",p[10][1]);
                PRNT("        p[19,4]= %g\n",p[19][4]);
            }
            return(0);
        }
    t->cxx[10]=0.0;
    t->cxx[11]=0.0;
    t->cxx[12]=0.0;
    t->cxx[13]=-x[3]*x[4]*p[8][4]/pow(pow(x[3],2.0)+pow(x[4],2.0),2.0)/sqrt(pow(p[19][4],2.0)+pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0))+x[3]*x[4]*p[8][4]*pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0)/pow(pow(x[3],2.0)+pow(x[4],2.0),2.0)/pow(pow(p[19][4],2.0)+pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0),1.5)+2.0*pow(x[4],2.0)*p[8][4]*(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]))/pow(pow(x[3],2.0)+pow(x[4],2.0),2.0)/sqrt(pow(p[19][4],2.0)+pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0))-p[8][4]*(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]))/(pow(x[3],2.0)+pow(x[4],2.0))/sqrt(pow(p[19][4],2.0)+pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0));
    if (isNANorINF(t->cxx[13]))
        {
            PRNT("    @k %d: t->cxx[13] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cxx[13]);
            {
                PRNT("        p[8,4]= %g\n",p[8][4]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[10,1]= %g\n",p[10][1]);
                PRNT("        p[10,0]= %g\n",p[10][0]);
                PRNT("        p[19,4]= %g\n",p[19][4]);
            }
            return(0);
        }
    t->cxx[14]=pow(x[3],2.0)*p[8][4]/pow(pow(x[3],2.0)+pow(x[4],2.0),2.0)/sqrt(pow(p[19][4],2.0)+pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0))-pow(x[3],2.0)*p[8][4]*pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0)/pow(pow(x[3],2.0)+pow(x[4],2.0),2.0)/pow(pow(p[19][4],2.0)+pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0),1.5)-2.0*x[3]*x[4]*p[8][4]*(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]))/pow(pow(x[3],2.0)+pow(x[4],2.0),2.0)/sqrt(pow(p[19][4],2.0)+pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0));
    if (isNANorINF(t->cxx[14]))
        {
            PRNT("    @k %d: t->cxx[14] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cxx[14]);
            {
                PRNT("        p[8,4]= %g\n",p[8][4]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[10,1]= %g\n",p[10][1]);
                PRNT("        p[10,0]= %g\n",p[10][0]);
                PRNT("        p[19,4]= %g\n",p[19][4]);
            }
            return(0);
        }
    t->cxx[15]=0.0;
    t->cxx[16]=0.0;
    t->cxx[17]=0.0;
    t->cxx[18]=0.0;
    t->cxx[19]=0.0;
    t->cxx[20]=-p[8][5]*pow(x[5]-p[10][2],2.0)/pow(pow(x[5]-p[10][2],2.0)+pow(p[19][5],2.0),1.5)+p[8][5]/sqrt(pow(x[5]-p[10][2],2.0)+pow(p[19][5],2.0));
    if (isNANorINF(t->cxx[20]))
        {
            PRNT("    @k %d: t->cxx[20] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cxx[20]);
            {
                PRNT("        p[8,5]= %g\n",p[8][5]);
                PRNT("        p[10,2]= %g\n",p[10][2]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        p[19,5]= %g\n",p[19][5]);
            }
            return(0);
        }
    t->cxx[21]=0.0;
    t->cxx[22]=0.0;
    t->cxx[23]=0.0;
    t->cxx[24]=0.0;
    t->cxx[25]=0.0;
    t->cxx[26]=0.0;
    t->cxx[27]=2.0*p[5][0]/pow(p[9][0],2.0);
    if (isNANorINF(t->cxx[27]))
        {
            PRNT("    @k %d: t->cxx[27] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cxx[27]);
            {
                PRNT("        p[5,0]= %g\n",p[5][0]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
            }
            return(0);
        }
    t->cxx[28]=0.0;
    t->cxx[29]=0.0;
    t->cxx[30]=0.0;
    t->cxx[31]=0.0;
    t->cxx[32]=0.0;
    t->cxx[33]=0.0;
    t->cxx[34]=0.0;
    t->cxx[35]=2.0*p[5][1]/pow(p[9][0],2.0);
    if (isNANorINF(t->cxx[35]))
        {
            PRNT("    @k %d: t->cxx[35] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cxx[35]);
            {
                PRNT("        p[5,1]= %g\n",p[5][1]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
            }
            return(0);
        }

    t->cu[0]=2.0*u[0]*p[7][0]+2.0*p[5][0]*(u[0]-x[6])/pow(p[9][0],2.0);
    if (isNANorINF(t->cu[0]))
        {
            PRNT("    @k %d: t->cu[0] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cu[0]);
            {
                PRNT("        p[7,0]= %g\n",p[7][0]);
                PRNT("        u[0]= %g\n",u[0]);
                PRNT("        p[5,0]= %g\n",p[5][0]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[6]= %g\n",x[6]);
            }
            return(0);
        }
    t->cu[1]=2.0*u[1]*p[7][1]+2.0*p[5][1]*(u[1]-x[7])/pow(p[9][0],2.0);
    if (isNANorINF(t->cu[1]))
        {
            PRNT("    @k %d: t->cu[1] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cu[1]);
            {
                PRNT("        p[7,1]= %g\n",p[7][1]);
                PRNT("        u[1]= %g\n",u[1]);
                PRNT("        p[5,1]= %g\n",p[5][1]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
                PRNT("        x[7]= %g\n",x[7]);
            }
            return(0);
        }

    t->cuu[0]=2.0*p[7][0]+2.0*p[5][0]/pow(p[9][0],2.0);
    if (isNANorINF(t->cuu[0]))
        {
            PRNT("    @k %d: t->cuu[0] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cuu[0]);
            {
                PRNT("        p[7,0]= %g\n",p[7][0]);
                PRNT("        p[5,0]= %g\n",p[5][0]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
            }
            return(0);
        }
    t->cuu[1]=0.0;
    t->cuu[2]=2.0*p[7][1]+2.0*p[5][1]/pow(p[9][0],2.0);
    if (isNANorINF(t->cuu[2]))
        {
            PRNT("    @k %d: t->cuu[2] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cuu[2]);
            {
                PRNT("        p[7,1]= %g\n",p[7][1]);
                PRNT("        p[5,1]= %g\n",p[5][1]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
            }
            return(0);
        }

    t->cxu[0]=0.0;
    t->cxu[1]=0.0;
    t->cxu[2]=0.0;
    t->cxu[3]=0.0;
    t->cxu[4]=0.0;
    t->cxu[5]=0.0;
    t->cxu[6]=-2.0*p[5][0]/pow(p[9][0],2.0);
    if (isNANorINF(t->cxu[6]))
        {
            PRNT("    @k %d: t->cxu[6] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cxu[6]);
            {
                PRNT("        p[5,0]= %g\n",p[5][0]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
            }
            return(0);
        }
    t->cxu[7]=0.0;
    t->cxu[8]=0.0;
    t->cxu[9]=0.0;
    t->cxu[10]=0.0;
    t->cxu[11]=0.0;
    t->cxu[12]=0.0;
    t->cxu[13]=0.0;
    t->cxu[14]=0.0;
    t->cxu[15]=-2.0*p[5][1]/pow(p[9][0],2.0);
    if (isNANorINF(t->cxu[15]))
        {
            PRNT("    @k %d: t->cxu[15] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cxu[15]);
            {
                PRNT("        p[5,1]= %g\n",p[5][1]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
            }
            return(0);
        }

    return 1;
}

static int calcFAuxDeriv(trajFin_t *t, multipliersFin_t *m, tOptSet *o) {
    const double *x= t->x;
    const double w_pen= o->w_pen_f;
    double **p= o->p;
    const int k= o->n_hor;
    
    return 1;
}

static int bp_derivsF(trajFin_t *t, int k, double **p) {
    const double *x= t->x;
    
    t->cx[0]=0.0;
    t->cx[1]=0.0;
    t->cx[2]=0.0;
    t->cx[3]=p[6][0]*(x[3]-p[10][0])/sqrt(pow(x[3]-p[10][0],2.0)+pow(p[18][0],2.0))-x[4]*p[6][1]*(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]))/(pow(x[3],2.0)+pow(x[4],2.0))/sqrt(pow(p[18][1],2.0)+pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0));
    if (isNANorINF(t->cx[3]))
        {
            PRNT("    @k %d: t->cx[3] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cx[3]);
            {
                PRNT("        p[6,0]= %g\n",p[6][0]);
                PRNT("        p[10,0]= %g\n",p[10][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[18,0]= %g\n",p[18][0]);
                PRNT("        p[6,1]= %g\n",p[6][1]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[10,1]= %g\n",p[10][1]);
                PRNT("        p[18,1]= %g\n",p[18][1]);
            }
            return(0);
        }
    t->cx[4]=x[3]*p[6][1]*(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]))/(pow(x[3],2.0)+pow(x[4],2.0))/sqrt(pow(p[18][1],2.0)+pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0));
    if (isNANorINF(t->cx[4]))
        {
            PRNT("    @k %d: t->cx[4] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cx[4]);
            {
                PRNT("        p[6,1]= %g\n",p[6][1]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[10,1]= %g\n",p[10][1]);
                PRNT("        p[10,0]= %g\n",p[10][0]);
                PRNT("        p[18,1]= %g\n",p[18][1]);
            }
            return(0);
        }
    t->cx[5]=p[6][2]*(x[5]-p[10][2])/sqrt(pow(x[5]-p[10][2],2.0)+pow(p[18][2],2.0));
    if (isNANorINF(t->cx[5]))
        {
            PRNT("    @k %d: t->cx[5] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cx[5]);
            {
                PRNT("        p[6,2]= %g\n",p[6][2]);
                PRNT("        p[10,2]= %g\n",p[10][2]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        p[18,2]= %g\n",p[18][2]);
            }
            return(0);
        }
    t->cx[6]=0.0;
    t->cx[7]=0.0;

    t->cxx[0]=0.0;
    t->cxx[1]=0.0;
    t->cxx[2]=0.0;
    t->cxx[3]=0.0;
    t->cxx[4]=0.0;
    t->cxx[5]=0.0;
    t->cxx[6]=0.0;
    t->cxx[7]=0.0;
    t->cxx[8]=0.0;
    t->cxx[9]=-p[6][0]*pow(x[3]-p[10][0],2.0)/pow(pow(x[3]-p[10][0],2.0)+pow(p[18][0],2.0),1.5)+p[6][0]/sqrt(pow(x[3]-p[10][0],2.0)+pow(p[18][0],2.0))+pow(x[4],2.0)*p[6][1]/pow(pow(x[3],2.0)+pow(x[4],2.0),2.0)/sqrt(pow(p[18][1],2.0)+pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0))-pow(x[4],2.0)*p[6][1]*pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0)/pow(pow(x[3],2.0)+pow(x[4],2.0),2.0)/pow(pow(p[18][1],2.0)+pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0),1.5)+2.0*x[3]*x[4]*p[6][1]*(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]))/pow(pow(x[3],2.0)+pow(x[4],2.0),2.0)/sqrt(pow(p[18][1],2.0)+pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0));
    if (isNANorINF(t->cxx[9]))
        {
            PRNT("    @k %d: t->cxx[9] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cxx[9]);
            {
                PRNT("        p[6,0]= %g\n",p[6][0]);
                PRNT("        p[10,0]= %g\n",p[10][0]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        p[18,0]= %g\n",p[18][0]);
                PRNT("        p[6,1]= %g\n",p[6][1]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[10,1]= %g\n",p[10][1]);
                PRNT("        p[18,1]= %g\n",p[18][1]);
            }
            return(0);
        }
    t->cxx[10]=0.0;
    t->cxx[11]=0.0;
    t->cxx[12]=0.0;
    t->cxx[13]=-x[3]*x[4]*p[6][1]/pow(pow(x[3],2.0)+pow(x[4],2.0),2.0)/sqrt(pow(p[18][1],2.0)+pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0))+x[3]*x[4]*p[6][1]*pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0)/pow(pow(x[3],2.0)+pow(x[4],2.0),2.0)/pow(pow(p[18][1],2.0)+pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0),1.5)+2.0*pow(x[4],2.0)*p[6][1]*(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]))/pow(pow(x[3],2.0)+pow(x[4],2.0),2.0)/sqrt(pow(p[18][1],2.0)+pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0))-p[6][1]*(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]))/(pow(x[3],2.0)+pow(x[4],2.0))/sqrt(pow(p[18][1],2.0)+pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0));
    if (isNANorINF(t->cxx[13]))
        {
            PRNT("    @k %d: t->cxx[13] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cxx[13]);
            {
                PRNT("        p[6,1]= %g\n",p[6][1]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[10,1]= %g\n",p[10][1]);
                PRNT("        p[10,0]= %g\n",p[10][0]);
                PRNT("        p[18,1]= %g\n",p[18][1]);
            }
            return(0);
        }
    t->cxx[14]=pow(x[3],2.0)*p[6][1]/pow(pow(x[3],2.0)+pow(x[4],2.0),2.0)/sqrt(pow(p[18][1],2.0)+pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0))-pow(x[3],2.0)*p[6][1]*pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0)/pow(pow(x[3],2.0)+pow(x[4],2.0),2.0)/pow(pow(p[18][1],2.0)+pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0),1.5)-2.0*x[3]*x[4]*p[6][1]*(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]))/pow(pow(x[3],2.0)+pow(x[4],2.0),2.0)/sqrt(pow(p[18][1],2.0)+pow(atan2(x[4],x[3])-atan2(p[10][1],p[10][0]),2.0));
    if (isNANorINF(t->cxx[14]))
        {
            PRNT("    @k %d: t->cxx[14] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cxx[14]);
            {
                PRNT("        p[6,1]= %g\n",p[6][1]);
                PRNT("        x[3]= %g\n",x[3]);
                PRNT("        x[4]= %g\n",x[4]);
                PRNT("        p[10,1]= %g\n",p[10][1]);
                PRNT("        p[10,0]= %g\n",p[10][0]);
                PRNT("        p[18,1]= %g\n",p[18][1]);
            }
            return(0);
        }
    t->cxx[15]=0.0;
    t->cxx[16]=0.0;
    t->cxx[17]=0.0;
    t->cxx[18]=0.0;
    t->cxx[19]=0.0;
    t->cxx[20]=-p[6][2]*pow(x[5]-p[10][2],2.0)/pow(pow(x[5]-p[10][2],2.0)+pow(p[18][2],2.0),1.5)+p[6][2]/sqrt(pow(x[5]-p[10][2],2.0)+pow(p[18][2],2.0));
    if (isNANorINF(t->cxx[20]))
        {
            PRNT("    @k %d: t->cxx[20] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cxx[20]);
            {
                PRNT("        p[6,2]= %g\n",p[6][2]);
                PRNT("        p[10,2]= %g\n",p[10][2]);
                PRNT("        x[5]= %g\n",x[5]);
                PRNT("        p[18,2]= %g\n",p[18][2]);
            }
            return(0);
        }
    t->cxx[21]=0.0;
    t->cxx[22]=0.0;
    t->cxx[23]=0.0;
    t->cxx[24]=0.0;
    t->cxx[25]=0.0;
    t->cxx[26]=0.0;
    t->cxx[27]=0.0;
    t->cxx[28]=0.0;
    t->cxx[29]=0.0;
    t->cxx[30]=0.0;
    t->cxx[31]=0.0;
    t->cxx[32]=0.0;
    t->cxx[33]=0.0;
    t->cxx[34]=0.0;
    t->cxx[35]=0.0;
    return 1;
}

static int init_running(trajEl_t *t, tOptSet *o) {
    int k;
    double **p= o->p;
    
    for(k= 0; k<o->n_hor; k++, t++) {


// derivatives of L
    t->cx[2]=0.0;

    t->cxx[1]=0.0;
    t->cxx[3]=0.0;
    t->cxx[4]=0.0;
    t->cxx[5]=0.0;
    t->cxx[6]=0.0;
    t->cxx[7]=0.0;
    t->cxx[8]=0.0;
    t->cxx[10]=0.0;
    t->cxx[11]=0.0;
    t->cxx[12]=0.0;
    t->cxx[15]=0.0;
    t->cxx[16]=0.0;
    t->cxx[17]=0.0;
    t->cxx[18]=0.0;
    t->cxx[19]=0.0;
    t->cxx[21]=0.0;
    t->cxx[22]=0.0;
    t->cxx[23]=0.0;
    t->cxx[24]=0.0;
    t->cxx[25]=0.0;
    t->cxx[26]=0.0;
    t->cxx[27]=2.0*p[5][0]/pow(p[9][0],2.0);
    if (isNANorINF(t->cxx[27]))
        {
            PRNT("    @k %d: t->cxx[27] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cxx[27]);
            {
                PRNT("        p[5,0]= %g\n",p[5][0]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
            }
            return(0);
        }
    t->cxx[28]=0.0;
    t->cxx[29]=0.0;
    t->cxx[30]=0.0;
    t->cxx[31]=0.0;
    t->cxx[32]=0.0;
    t->cxx[33]=0.0;
    t->cxx[34]=0.0;
    t->cxx[35]=2.0*p[5][1]/pow(p[9][0],2.0);
    if (isNANorINF(t->cxx[35]))
        {
            PRNT("    @k %d: t->cxx[35] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cxx[35]);
            {
                PRNT("        p[5,1]= %g\n",p[5][1]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
            }
            return(0);
        }


    t->cuu[0]=2.0*p[7][0]+2.0*p[5][0]/pow(p[9][0],2.0);
    if (isNANorINF(t->cuu[0]))
        {
            PRNT("    @k %d: t->cuu[0] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cuu[0]);
            {
                PRNT("        p[7,0]= %g\n",p[7][0]);
                PRNT("        p[5,0]= %g\n",p[5][0]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
            }
            return(0);
        }
    t->cuu[1]=0.0;
    t->cuu[2]=2.0*p[7][1]+2.0*p[5][1]/pow(p[9][0],2.0);
    if (isNANorINF(t->cuu[2]))
        {
            PRNT("    @k %d: t->cuu[2] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cuu[2]);
            {
                PRNT("        p[7,1]= %g\n",p[7][1]);
                PRNT("        p[5,1]= %g\n",p[5][1]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
            }
            return(0);
        }

    t->cxu[0]=0.0;
    t->cxu[1]=0.0;
    t->cxu[2]=0.0;
    t->cxu[3]=0.0;
    t->cxu[4]=0.0;
    t->cxu[5]=0.0;
    t->cxu[6]=-2.0*p[5][0]/pow(p[9][0],2.0);
    if (isNANorINF(t->cxu[6]))
        {
            PRNT("    @k %d: t->cxu[6] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cxu[6]);
            {
                PRNT("        p[5,0]= %g\n",p[5][0]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
            }
            return(0);
        }
    t->cxu[7]=0.0;
    t->cxu[8]=0.0;
    t->cxu[9]=0.0;
    t->cxu[10]=0.0;
    t->cxu[11]=0.0;
    t->cxu[12]=0.0;
    t->cxu[13]=0.0;
    t->cxu[14]=0.0;
    t->cxu[15]=-2.0*p[5][1]/pow(p[9][0],2.0);
    if (isNANorINF(t->cxu[15]))
        {
            PRNT("    @k %d: t->cxu[15] in line %d is nan or inf: %g\n", k, __LINE__-3,t->cxu[15]);
            {
                PRNT("        p[5,1]= %g\n",p[5][1]);
                PRNT("        p[9,0]= %g\n",p[9][0]);
            }
            return(0);
        }

// derivatives of f
// df[i]/d x[0]
    t->fx[0]=1.0;
    t->fx[1]=0.0;
    t->fx[2]=0.0;
    t->fx[3]=0.0;
    t->fx[4]=0.0;
    t->fx[5]=0.0;
    t->fx[6]=0.0;
    t->fx[7]=0.0;
// df[i]/d x[1]
    t->fx[8]=0.0;
    t->fx[9]=1.0;
    t->fx[10]=0.0;
    t->fx[11]=0.0;
    t->fx[12]=0.0;
    t->fx[13]=0.0;
    t->fx[14]=0.0;
    t->fx[15]=0.0;
// df[i]/d x[2]
    t->fx[18]=1.0;
    t->fx[19]=0.0;
    t->fx[20]=0.0;
    t->fx[21]=0.0;
    t->fx[22]=0.0;
    t->fx[23]=0.0;
// df[i]/d x[3]
    t->fx[26]=0.0;
    t->fx[30]=0.0;
    t->fx[31]=0.0;
// df[i]/d x[4]
    t->fx[34]=0.0;
    t->fx[38]=0.0;
    t->fx[39]=0.0;
// df[i]/d x[5]
    t->fx[40]=0.0;
    t->fx[41]=0.0;
    t->fx[42]=p[9][0];
    t->fx[46]=0.0;
    t->fx[47]=0.0;
// df[i]/d x[6]
    t->fx[48]=0.0;
    t->fx[49]=0.0;
    t->fx[50]=0.0;
    t->fx[51]=0.0;
    t->fx[52]=0.0;
    t->fx[53]=0.0;
    t->fx[54]=0.0;
    t->fx[55]=0.0;
// df[i]/d x[7]
    t->fx[56]=0.0;
    t->fx[57]=0.0;
    t->fx[58]=0.0;
    t->fx[59]=0.0;
    t->fx[60]=0.0;
    t->fx[61]=0.0;
    t->fx[62]=0.0;
    t->fx[63]=0.0;

// df[i]/d u[0]
    t->fu[0]=0.0;
    t->fu[1]=0.0;
    t->fu[2]=0.0;
    t->fu[6]=1.0;
    t->fu[7]=0.0;
// df[i]/d u[1]
    t->fu[8]=0.0;
    t->fu[9]=0.0;
    t->fu[10]=0.0;
    t->fu[14]=0.0;
    t->fu[15]=1.0;

#if FULL_DDP
// d^2f[0]/dx[i] dx[j]
// j= 0
    t->fxx[0]=0.0;
// j= 1
    t->fxx[1]=0.0;
    t->fxx[2]=0.0;
// j= 2
    t->fxx[3]=0.0;
    t->fxx[4]=0.0;
// j= 3
    t->fxx[6]=0.0;
    t->fxx[7]=0.0;
// j= 4
    t->fxx[10]=0.0;
    t->fxx[11]=0.0;
// j= 5
    t->fxx[15]=0.0;
    t->fxx[16]=0.0;
    t->fxx[17]=0.0;
    t->fxx[18]=0.0;
    t->fxx[19]=0.0;
    t->fxx[20]=0.0;
// j= 6
    t->fxx[21]=0.0;
    t->fxx[22]=0.0;
    t->fxx[23]=0.0;
    t->fxx[24]=0.0;
    t->fxx[25]=0.0;
    t->fxx[26]=0.0;
    t->fxx[27]=0.0;
// j= 7
    t->fxx[28]=0.0;
    t->fxx[29]=0.0;
    t->fxx[30]=0.0;
    t->fxx[31]=0.0;
    t->fxx[32]=0.0;
    t->fxx[33]=0.0;
    t->fxx[34]=0.0;
    t->fxx[35]=0.0;
// d^2f[1]/dx[i] dx[j]
// j= 0
    t->fxx[36]=0.0;
// j= 1
    t->fxx[37]=0.0;
    t->fxx[38]=0.0;
// j= 2
    t->fxx[39]=0.0;
    t->fxx[40]=0.0;
// j= 3
    t->fxx[42]=0.0;
    t->fxx[43]=0.0;
// j= 4
    t->fxx[46]=0.0;
    t->fxx[47]=0.0;
// j= 5
    t->fxx[51]=0.0;
    t->fxx[52]=0.0;
    t->fxx[53]=0.0;
    t->fxx[54]=0.0;
    t->fxx[55]=0.0;
    t->fxx[56]=0.0;
// j= 6
    t->fxx[57]=0.0;
    t->fxx[58]=0.0;
    t->fxx[59]=0.0;
    t->fxx[60]=0.0;
    t->fxx[61]=0.0;
    t->fxx[62]=0.0;
    t->fxx[63]=0.0;
// j= 7
    t->fxx[64]=0.0;
    t->fxx[65]=0.0;
    t->fxx[66]=0.0;
    t->fxx[67]=0.0;
    t->fxx[68]=0.0;
    t->fxx[69]=0.0;
    t->fxx[70]=0.0;
    t->fxx[71]=0.0;
// d^2f[2]/dx[i] dx[j]
// j= 0
    t->fxx[72]=0.0;
// j= 1
    t->fxx[73]=0.0;
    t->fxx[74]=0.0;
// j= 2
    t->fxx[75]=0.0;
    t->fxx[76]=0.0;
    t->fxx[77]=0.0;
// j= 3
    t->fxx[78]=0.0;
    t->fxx[79]=0.0;
    t->fxx[80]=0.0;
    t->fxx[81]=0.0;
// j= 4
    t->fxx[82]=0.0;
    t->fxx[83]=0.0;
    t->fxx[84]=0.0;
    t->fxx[85]=0.0;
    t->fxx[86]=0.0;
// j= 5
    t->fxx[87]=0.0;
    t->fxx[88]=0.0;
    t->fxx[89]=0.0;
    t->fxx[90]=0.0;
    t->fxx[91]=0.0;
    t->fxx[92]=0.0;
// j= 6
    t->fxx[93]=0.0;
    t->fxx[94]=0.0;
    t->fxx[95]=0.0;
    t->fxx[96]=0.0;
    t->fxx[97]=0.0;
    t->fxx[98]=0.0;
    t->fxx[99]=0.0;
// j= 7
    t->fxx[100]=0.0;
    t->fxx[101]=0.0;
    t->fxx[102]=0.0;
    t->fxx[103]=0.0;
    t->fxx[104]=0.0;
    t->fxx[105]=0.0;
    t->fxx[106]=0.0;
    t->fxx[107]=0.0;
// d^2f[3]/dx[i] dx[j]
// j= 0
    t->fxx[108]=0.0;
// j= 1
    t->fxx[109]=0.0;
    t->fxx[110]=0.0;
// j= 2
    t->fxx[111]=0.0;
    t->fxx[112]=0.0;
    t->fxx[113]=0.0;
// j= 3
    t->fxx[114]=0.0;
    t->fxx[115]=0.0;
    t->fxx[116]=0.0;
// j= 4
    t->fxx[118]=0.0;
    t->fxx[119]=0.0;
    t->fxx[120]=0.0;
// j= 5
    t->fxx[123]=0.0;
    t->fxx[124]=0.0;
    t->fxx[125]=0.0;
// j= 6
    t->fxx[129]=0.0;
    t->fxx[130]=0.0;
    t->fxx[131]=0.0;
    t->fxx[132]=0.0;
    t->fxx[133]=0.0;
    t->fxx[134]=0.0;
    t->fxx[135]=0.0;
// j= 7
    t->fxx[136]=0.0;
    t->fxx[137]=0.0;
    t->fxx[138]=0.0;
    t->fxx[139]=0.0;
    t->fxx[140]=0.0;
    t->fxx[141]=0.0;
    t->fxx[142]=0.0;
    t->fxx[143]=0.0;
// d^2f[4]/dx[i] dx[j]
// j= 0
    t->fxx[144]=0.0;
// j= 1
    t->fxx[145]=0.0;
    t->fxx[146]=0.0;
// j= 2
    t->fxx[147]=0.0;
    t->fxx[148]=0.0;
    t->fxx[149]=0.0;
// j= 3
    t->fxx[150]=0.0;
    t->fxx[151]=0.0;
    t->fxx[152]=0.0;
// j= 4
    t->fxx[154]=0.0;
    t->fxx[155]=0.0;
    t->fxx[156]=0.0;
// j= 5
    t->fxx[159]=0.0;
    t->fxx[160]=0.0;
    t->fxx[161]=0.0;
// j= 6
    t->fxx[165]=0.0;
    t->fxx[166]=0.0;
    t->fxx[167]=0.0;
    t->fxx[168]=0.0;
    t->fxx[169]=0.0;
    t->fxx[170]=0.0;
    t->fxx[171]=0.0;
// j= 7
    t->fxx[172]=0.0;
    t->fxx[173]=0.0;
    t->fxx[174]=0.0;
    t->fxx[175]=0.0;
    t->fxx[176]=0.0;
    t->fxx[177]=0.0;
    t->fxx[178]=0.0;
    t->fxx[179]=0.0;
// d^2f[5]/dx[i] dx[j]
// j= 0
    t->fxx[180]=0.0;
// j= 1
    t->fxx[181]=0.0;
    t->fxx[182]=0.0;
// j= 2
    t->fxx[183]=0.0;
    t->fxx[184]=0.0;
    t->fxx[185]=0.0;
// j= 3
    t->fxx[186]=0.0;
    t->fxx[187]=0.0;
    t->fxx[188]=0.0;
// j= 4
    t->fxx[190]=0.0;
    t->fxx[191]=0.0;
    t->fxx[192]=0.0;
// j= 5
    t->fxx[195]=0.0;
    t->fxx[196]=0.0;
    t->fxx[197]=0.0;
// j= 6
    t->fxx[201]=0.0;
    t->fxx[202]=0.0;
    t->fxx[203]=0.0;
    t->fxx[204]=0.0;
    t->fxx[205]=0.0;
    t->fxx[206]=0.0;
    t->fxx[207]=0.0;
// j= 7
    t->fxx[208]=0.0;
    t->fxx[209]=0.0;
    t->fxx[210]=0.0;
    t->fxx[211]=0.0;
    t->fxx[212]=0.0;
    t->fxx[213]=0.0;
    t->fxx[214]=0.0;
    t->fxx[215]=0.0;
// d^2f[6]/dx[i] dx[j]
// j= 0
    t->fxx[216]=0.0;
// j= 1
    t->fxx[217]=0.0;
    t->fxx[218]=0.0;
// j= 2
    t->fxx[219]=0.0;
    t->fxx[220]=0.0;
    t->fxx[221]=0.0;
// j= 3
    t->fxx[222]=0.0;
    t->fxx[223]=0.0;
    t->fxx[224]=0.0;
    t->fxx[225]=0.0;
// j= 4
    t->fxx[226]=0.0;
    t->fxx[227]=0.0;
    t->fxx[228]=0.0;
    t->fxx[229]=0.0;
    t->fxx[230]=0.0;
// j= 5
    t->fxx[231]=0.0;
    t->fxx[232]=0.0;
    t->fxx[233]=0.0;
    t->fxx[234]=0.0;
    t->fxx[235]=0.0;
    t->fxx[236]=0.0;
// j= 6
    t->fxx[237]=0.0;
    t->fxx[238]=0.0;
    t->fxx[239]=0.0;
    t->fxx[240]=0.0;
    t->fxx[241]=0.0;
    t->fxx[242]=0.0;
    t->fxx[243]=0.0;
// j= 7
    t->fxx[244]=0.0;
    t->fxx[245]=0.0;
    t->fxx[246]=0.0;
    t->fxx[247]=0.0;
    t->fxx[248]=0.0;
    t->fxx[249]=0.0;
    t->fxx[250]=0.0;
    t->fxx[251]=0.0;
// d^2f[7]/dx[i] dx[j]
// j= 0
    t->fxx[252]=0.0;
// j= 1
    t->fxx[253]=0.0;
    t->fxx[254]=0.0;
// j= 2
    t->fxx[255]=0.0;
    t->fxx[256]=0.0;
    t->fxx[257]=0.0;
// j= 3
    t->fxx[258]=0.0;
    t->fxx[259]=0.0;
    t->fxx[260]=0.0;
    t->fxx[261]=0.0;
// j= 4
    t->fxx[262]=0.0;
    t->fxx[263]=0.0;
    t->fxx[264]=0.0;
    t->fxx[265]=0.0;
    t->fxx[266]=0.0;
// j= 5
    t->fxx[267]=0.0;
    t->fxx[268]=0.0;
    t->fxx[269]=0.0;
    t->fxx[270]=0.0;
    t->fxx[271]=0.0;
    t->fxx[272]=0.0;
// j= 6
    t->fxx[273]=0.0;
    t->fxx[274]=0.0;
    t->fxx[275]=0.0;
    t->fxx[276]=0.0;
    t->fxx[277]=0.0;
    t->fxx[278]=0.0;
    t->fxx[279]=0.0;
// j= 7
    t->fxx[280]=0.0;
    t->fxx[281]=0.0;
    t->fxx[282]=0.0;
    t->fxx[283]=0.0;
    t->fxx[284]=0.0;
    t->fxx[285]=0.0;
    t->fxx[286]=0.0;
    t->fxx[287]=0.0;

// d^2f[0]/du[i] du[j]
// j= 0
    t->fuu[0]=0.0;
// j= 1
    t->fuu[1]=0.0;
    t->fuu[2]=0.0;
// d^2f[1]/du[i] du[j]
// j= 0
    t->fuu[3]=0.0;
// j= 1
    t->fuu[4]=0.0;
    t->fuu[5]=0.0;
// d^2f[2]/du[i] du[j]
// j= 0
    t->fuu[6]=0.0;
// j= 1
    t->fuu[7]=0.0;
    t->fuu[8]=0.0;
// d^2f[3]/du[i] du[j]
// j= 0
// j= 1
    t->fuu[10]=0.0;
// d^2f[4]/du[i] du[j]
// j= 0
// j= 1
    t->fuu[13]=0.0;
// d^2f[5]/du[i] du[j]
// j= 0
// j= 1
    t->fuu[16]=0.0;
// d^2f[6]/du[i] du[j]
// j= 0
    t->fuu[18]=0.0;
// j= 1
    t->fuu[19]=0.0;
    t->fuu[20]=0.0;
// d^2f[7]/du[i] du[j]
// j= 0
    t->fuu[21]=0.0;
// j= 1
    t->fuu[22]=0.0;
    t->fuu[23]=0.0;

// d^2f[0]/dx[i] du[j]
// j= 0
    t->fxu[0]=0.0;
    t->fxu[1]=0.0;
    t->fxu[2]=0.0;
    t->fxu[3]=0.0;
    t->fxu[4]=0.0;
    t->fxu[5]=0.0;
    t->fxu[6]=0.0;
    t->fxu[7]=0.0;
// j= 1
    t->fxu[8]=0.0;
    t->fxu[9]=0.0;
    t->fxu[10]=0.0;
    t->fxu[11]=0.0;
    t->fxu[12]=0.0;
    t->fxu[13]=0.0;
    t->fxu[14]=0.0;
    t->fxu[15]=0.0;
// d^2f[1]/dx[i] du[j]
// j= 0
    t->fxu[16]=0.0;
    t->fxu[17]=0.0;
    t->fxu[18]=0.0;
    t->fxu[19]=0.0;
    t->fxu[20]=0.0;
    t->fxu[21]=0.0;
    t->fxu[22]=0.0;
    t->fxu[23]=0.0;
// j= 1
    t->fxu[24]=0.0;
    t->fxu[25]=0.0;
    t->fxu[26]=0.0;
    t->fxu[27]=0.0;
    t->fxu[28]=0.0;
    t->fxu[29]=0.0;
    t->fxu[30]=0.0;
    t->fxu[31]=0.0;
// d^2f[2]/dx[i] du[j]
// j= 0
    t->fxu[32]=0.0;
    t->fxu[33]=0.0;
    t->fxu[34]=0.0;
    t->fxu[35]=0.0;
    t->fxu[36]=0.0;
    t->fxu[37]=0.0;
    t->fxu[38]=0.0;
    t->fxu[39]=0.0;
// j= 1
    t->fxu[40]=0.0;
    t->fxu[41]=0.0;
    t->fxu[42]=0.0;
    t->fxu[43]=0.0;
    t->fxu[44]=0.0;
    t->fxu[45]=0.0;
    t->fxu[46]=0.0;
    t->fxu[47]=0.0;
// d^2f[3]/dx[i] du[j]
// j= 0
    t->fxu[48]=0.0;
    t->fxu[49]=0.0;
    t->fxu[50]=0.0;
    t->fxu[54]=0.0;
    t->fxu[55]=0.0;
// j= 1
    t->fxu[56]=0.0;
    t->fxu[57]=0.0;
    t->fxu[58]=0.0;
    t->fxu[62]=0.0;
    t->fxu[63]=0.0;
// d^2f[4]/dx[i] du[j]
// j= 0
    t->fxu[64]=0.0;
    t->fxu[65]=0.0;
    t->fxu[66]=0.0;
    t->fxu[70]=0.0;
    t->fxu[71]=0.0;
// j= 1
    t->fxu[72]=0.0;
    t->fxu[73]=0.0;
    t->fxu[74]=0.0;
    t->fxu[78]=0.0;
    t->fxu[79]=0.0;
// d^2f[5]/dx[i] du[j]
// j= 0
    t->fxu[80]=0.0;
    t->fxu[81]=0.0;
    t->fxu[82]=0.0;
    t->fxu[86]=0.0;
    t->fxu[87]=0.0;
// j= 1
    t->fxu[88]=0.0;
    t->fxu[89]=0.0;
    t->fxu[90]=0.0;
    t->fxu[94]=0.0;
    t->fxu[95]=0.0;
// d^2f[6]/dx[i] du[j]
// j= 0
    t->fxu[96]=0.0;
    t->fxu[97]=0.0;
    t->fxu[98]=0.0;
    t->fxu[99]=0.0;
    t->fxu[100]=0.0;
    t->fxu[101]=0.0;
    t->fxu[102]=0.0;
    t->fxu[103]=0.0;
// j= 1
    t->fxu[104]=0.0;
    t->fxu[105]=0.0;
    t->fxu[106]=0.0;
    t->fxu[107]=0.0;
    t->fxu[108]=0.0;
    t->fxu[109]=0.0;
    t->fxu[110]=0.0;
    t->fxu[111]=0.0;
// d^2f[7]/dx[i] du[j]
// j= 0
    t->fxu[112]=0.0;
    t->fxu[113]=0.0;
    t->fxu[114]=0.0;
    t->fxu[115]=0.0;
    t->fxu[116]=0.0;
    t->fxu[117]=0.0;
    t->fxu[118]=0.0;
    t->fxu[119]=0.0;
// j= 1
    t->fxu[120]=0.0;
    t->fxu[121]=0.0;
    t->fxu[122]=0.0;
    t->fxu[123]=0.0;
    t->fxu[124]=0.0;
    t->fxu[125]=0.0;
    t->fxu[126]=0.0;
    t->fxu[127]=0.0;
#endif
    }
    
    return 1;
}

static int init_final(trajFin_t *t, tOptSet *o) {
    double **p= o->p;
    const int k= o->n_hor;



    t->cx[0]=0.0;
    t->cx[1]=0.0;
    t->cx[2]=0.0;
    t->cx[6]=0.0;
    t->cx[7]=0.0;

    t->cxx[0]=0.0;
    t->cxx[1]=0.0;
    t->cxx[2]=0.0;
    t->cxx[3]=0.0;
    t->cxx[4]=0.0;
    t->cxx[5]=0.0;
    t->cxx[6]=0.0;
    t->cxx[7]=0.0;
    t->cxx[8]=0.0;
    t->cxx[10]=0.0;
    t->cxx[11]=0.0;
    t->cxx[12]=0.0;
    t->cxx[15]=0.0;
    t->cxx[16]=0.0;
    t->cxx[17]=0.0;
    t->cxx[18]=0.0;
    t->cxx[19]=0.0;
    t->cxx[21]=0.0;
    t->cxx[22]=0.0;
    t->cxx[23]=0.0;
    t->cxx[24]=0.0;
    t->cxx[25]=0.0;
    t->cxx[26]=0.0;
    t->cxx[27]=0.0;
    t->cxx[28]=0.0;
    t->cxx[29]=0.0;
    t->cxx[30]=0.0;
    t->cxx[31]=0.0;
    t->cxx[32]=0.0;
    t->cxx[33]=0.0;
    t->cxx[34]=0.0;
    t->cxx[35]=0.0;

    return 1;
}

int init_trajectory(traj_t *t, tOptSet *o) {
    if(!init_running(t->t, o)) return 0;
    if(!init_final(&t->f, o)) return 0;
    
    return 1;
}

static int init_multipliers_running(tOptSet *o) {
    multipliersEl_t *m= o->multipliers.t;
    int k, i;

    for(k= 0; k<o->n_hor; k++, m++) {

    }
    
    return 1;
}

static int init_multipliers_final(tOptSet *o) {
    multipliersFin_t *m= &o->multipliers.f;
    int i;


    
    return 1;
}

int init_multipliers(tOptSet *o) {
    if(!init_multipliers_running(o)) return 0;
    if(!init_multipliers_final(o)) return 0;
    
    return 1;
}

int init_opt(tOptSet *o) {
    int i;
    
    for(i= 0; i<NUMBER_OF_THREADS+1; i++)
        if(!init_trajectory(&o->trajectories[i], o)) return 0;

    o->nominal= &o->trajectories[0];
    for(i= 1; i<NUMBER_OF_THREADS+1; i++)
    o->candidates[i-1]= &o->trajectories[i];
    
    if(!init_multipliers(o)) return 0;
    
    return 1;
}

static int update_multipliers_running(tOptSet *o, int init) {
    trajEl_t *t= o->nominal->t;
    multipliersEl_t *m= o->multipliers.t;
    const double *x= t->x;
    const double *u= t->u;
    const double w_pen= o->w_pen_l;
    double **p= o->p;
    int increase_pen= 0;
    int k, i;
    
    for(k= 0; k<o->n_hor; k++, m++, t++) {

// TODO: maybe check test for sufficient complementarity reduction

    if(init) return 1;

// inequality constraints according to D. Ruxton: Differential dynamic programming applied to continuous optimal control problems with state variable inequality constraints
    }
    
    if(!init && increase_pen)
        o->w_pen_l= min(o->w_pen_max_l, o->w_pen_l*o->w_pen_fact1);
        
    return 1;
}

static int update_multipliers_final(tOptSet *o, int init) {
    trajFin_t *t= &o->nominal->f;
    multipliersFin_t *m= &o->multipliers.f;
    const double *x= t->x;
    const double w_pen= o->w_pen_f;
    double **p= o->p;
    int increase_pen= 0;
    int k= o->n_hor;


// TODO: maybe check test for sufficient complementarity reduction

    if(!init && increase_pen)
        o->w_pen_f= min(o->w_pen_max_f, o->w_pen_f*o->w_pen_fact1);

    if(init) return 1;

// inequality constraints according to D. Ruxton: Differential dynamic programming applied to continuous optimal control problems with state variable inequality constraints

    return 1;
}

int update_multipliers(tOptSet *o, int init) {
    if(!update_multipliers_running(o, init)) return 0;
    if(!update_multipliers_final(o, init)) return 0;

    return 1;
}

int get_g_size() {
    return(0);
}

int calcG(double g[], trajEl_t *t, int k, double **p) {
    const double *x= t->x;
    const double *u= t->u;
    
    return(1);
} 

}
