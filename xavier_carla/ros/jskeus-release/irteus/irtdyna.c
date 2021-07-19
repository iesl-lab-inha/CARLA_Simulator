/* ./irtdyna.c :  entry=irtdyna */
/* compiled by EusLisp 9.27() for Linux created on ip-10-0-1-214(Fri Apr 16 04:05:26 PST 2021) */
#include "eus.h"
#include "irtdyna.h"
#pragma init (register_irtdyna)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___irtdyna();
extern pointer build_quote_vector();
static int register_irtdyna()
  { add_module_initializer("___irtdyna", ___irtdyna);}

static pointer F2999calc_inertia_matrix_rotational();
static pointer F3000calc_inertia_matrix_linear();

/*:calc-inertia-matrix*/
static pointer M3001joint_calc_inertia_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3003:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= fqv[0];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[1]); /*warn*/
	local[0]= w;
BLK3002:
	ctx->vsp=local; return(local[0]);}

/*calc-inertia-matrix-rotational*/
static pointer F2999calc_inertia_matrix_rotational(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=20) maerror();
	local[0]= argv[9];
	local[1]= fqv[2];
	local[2]= argv[3];
	local[3]= argv[15];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	local[1]= argv[15];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[3]); /*normalize-vector*/
	local[0]= w;
	local[1]= makeflt(1.0000000000000000208167e-03);
	local[2]= argv[4];
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	local[2]= makeflt(1.0000000000000000208167e-03);
	local[3]= argv[5];
	local[4]= argv[16];
	ctx->vsp=local+5;
	w=(pointer)SCALEVEC(ctx,3,local+2); /*scale*/
	local[2]= w;
	local[3]= makeflt(9.9999999999999985548644e-10);
	local[4]= argv[6];
	local[5]= argv[19];
	ctx->vsp=local+6;
	w=(*ftab[2])(ctx,3,local+3,&ftab[2],fqv[4]); /*scale-matrix*/
	local[3]= w;
	local[4]= local[1];
	local[5]= local[0];
	local[6]= local[2];
	local[7]= makeflt(1.0000000000000000208167e-03);
	local[8]= argv[8];
	local[9]= fqv[5];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= argv[17];
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,3,local+7); /*scale*/
	local[7]= w;
	local[8]= argv[17];
	ctx->vsp=local+9;
	w=(pointer)VMINUS(ctx,3,local+6); /*v-*/
	local[6]= w;
	local[7]= argv[18];
	ctx->vsp=local+8;
	w=(pointer)VCROSSPRODUCT(ctx,3,local+5); /*v**/
	local[5]= w;
	local[6]= argv[17];
	ctx->vsp=local+7;
	w=(pointer)SCALEVEC(ctx,3,local+4); /*scale*/
	local[4]= w;
	local[5]= local[2];
	local[6]= local[4];
	local[7]= argv[18];
	ctx->vsp=local+8;
	w=(pointer)VCROSSPRODUCT(ctx,3,local+5); /*v**/
	local[5]= w;
	local[6]= local[3];
	local[7]= local[0];
	local[8]= argv[16];
	ctx->vsp=local+9;
	w=(pointer)TRANSFORM(ctx,3,local+6); /*transform*/
	local[6]= w;
	local[7]= argv[16];
	ctx->vsp=local+8;
	w=(pointer)VPLUS(ctx,3,local+5); /*v+*/
	local[5]= w;
	local[6]= makeflt(1.0000000000000000208167e-03);
	local[7]= argv[7];
	local[8]= argv[15];
	ctx->vsp=local+9;
	w=(pointer)SCALEVEC(ctx,3,local+6); /*scale*/
	local[6]= w;
	local[7]= local[4];
	local[8]= argv[18];
	ctx->vsp=local+9;
	w=(pointer)VCROSSPRODUCT(ctx,3,local+6); /*v**/
	local[6]= w;
	local[7]= argv[16];
	ctx->vsp=local+8;
	w=(pointer)VMINUS(ctx,3,local+5); /*v-*/
	local[5]= w;
	local[6]= local[4];
	local[7]= argv[10];
	local[8]= argv[12];
	local[9]= argv[13];
	local[10]= argv[14];
	ctx->vsp=local+11;
	w=(*ftab[3])(ctx,5,local+6,&ftab[3],fqv[6]); /*calc-dif-with-axis*/
	local[6]= w;
	local[7]= makeint((eusinteger_t)0L);
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
WHL3006:
	local[9]= local[7];
	w = local[8];
	if ((eusinteger_t)local[9] >= (eusinteger_t)w) goto WHX3007;
	local[9]= argv[0];
	local[10]= argv[1];
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[10]= w;
	local[11]= argv[2];
	local[12]= local[6];
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)ASET(ctx,4,local+9); /*aset*/
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	local[7] = w;
	goto WHL3006;
WHX3007:
	local[9]= NIL;
BLK3008:
	w = NIL;
	local[7]= local[5];
	local[8]= argv[11];
	local[9]= argv[12];
	local[10]= argv[13];
	local[11]= argv[14];
	ctx->vsp=local+12;
	w=(*ftab[3])(ctx,5,local+7,&ftab[3],fqv[6]); /*calc-dif-with-axis*/
	local[7]= w;
	local[8]= makeint((eusinteger_t)0L);
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	local[9]= w;
WHL3010:
	local[10]= local[8];
	w = local[9];
	if ((eusinteger_t)local[10] >= (eusinteger_t)w) goto WHX3011;
	local[10]= argv[0];
	local[11]= argv[1];
	local[12]= local[8];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(pointer)LENGTH(ctx,1,local+13); /*length*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,3,local+11); /*+*/
	local[11]= w;
	local[12]= argv[2];
	local[13]= local[7];
	local[14]= local[8];
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)ASET(ctx,4,local+10); /*aset*/
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[8] = w;
	goto WHL3010;
WHX3011:
	local[10]= NIL;
BLK3012:
	w = NIL;
	local[0]= w;
BLK3004:
	ctx->vsp=local; return(local[0]);}

/*calc-inertia-matrix-linear*/
static pointer F3000calc_inertia_matrix_linear(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=20) maerror();
	local[0]= argv[9];
	local[1]= fqv[2];
	local[2]= argv[3];
	local[3]= argv[15];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	local[1]= argv[15];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[3]); /*normalize-vector*/
	local[0]= w;
	local[1]= makeflt(1.0000000000000000208167e-03);
	local[2]= argv[4];
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	local[2]= makeflt(1.0000000000000000208167e-03);
	local[3]= argv[5];
	local[4]= argv[16];
	ctx->vsp=local+5;
	w=(pointer)SCALEVEC(ctx,3,local+2); /*scale*/
	local[2]= w;
	local[3]= makeflt(9.9999999999999985548644e-10);
	local[4]= argv[6];
	local[5]= argv[19];
	ctx->vsp=local+6;
	w=(*ftab[2])(ctx,3,local+3,&ftab[2],fqv[4]); /*scale-matrix*/
	local[3]= w;
	local[4]= local[1];
	local[5]= local[0];
	local[6]= argv[15];
	ctx->vsp=local+7;
	w=(pointer)SCALEVEC(ctx,3,local+4); /*scale*/
	local[4]= w;
	local[5]= local[2];
	local[6]= local[4];
	local[7]= argv[17];
	ctx->vsp=local+8;
	w=(pointer)VCROSSPRODUCT(ctx,3,local+5); /*v**/
	local[5]= w;
	local[6]= makeflt(1.0000000000000000208167e-03);
	local[7]= argv[7];
	local[8]= argv[16];
	ctx->vsp=local+9;
	w=(pointer)SCALEVEC(ctx,3,local+6); /*scale*/
	local[6]= w;
	local[7]= local[4];
	local[8]= argv[18];
	ctx->vsp=local+9;
	w=(pointer)VCROSSPRODUCT(ctx,3,local+6); /*v**/
	local[6]= w;
	local[7]= argv[16];
	ctx->vsp=local+8;
	w=(pointer)VMINUS(ctx,3,local+5); /*v-*/
	local[5]= w;
	local[6]= local[4];
	local[7]= argv[10];
	local[8]= argv[12];
	local[9]= argv[13];
	local[10]= argv[14];
	ctx->vsp=local+11;
	w=(*ftab[3])(ctx,5,local+6,&ftab[3],fqv[6]); /*calc-dif-with-axis*/
	local[6]= w;
	local[7]= makeint((eusinteger_t)0L);
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
WHL3015:
	local[9]= local[7];
	w = local[8];
	if ((eusinteger_t)local[9] >= (eusinteger_t)w) goto WHX3016;
	local[9]= argv[0];
	local[10]= argv[1];
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[10]= w;
	local[11]= argv[2];
	local[12]= local[6];
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)ASET(ctx,4,local+9); /*aset*/
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	local[7] = w;
	goto WHL3015;
WHX3016:
	local[9]= NIL;
BLK3017:
	w = NIL;
	local[7]= local[5];
	local[8]= argv[11];
	local[9]= argv[12];
	local[10]= argv[13];
	local[11]= argv[14];
	ctx->vsp=local+12;
	w=(*ftab[3])(ctx,5,local+7,&ftab[3],fqv[6]); /*calc-dif-with-axis*/
	local[7]= w;
	local[8]= makeint((eusinteger_t)0L);
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	local[9]= w;
WHL3019:
	local[10]= local[8];
	w = local[9];
	if ((eusinteger_t)local[10] >= (eusinteger_t)w) goto WHX3020;
	local[10]= argv[0];
	local[11]= argv[1];
	local[12]= local[8];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(pointer)LENGTH(ctx,1,local+13); /*length*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,3,local+11); /*+*/
	local[11]= w;
	local[12]= argv[2];
	local[13]= local[7];
	local[14]= local[8];
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)ASET(ctx,4,local+10); /*aset*/
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[8] = w;
	goto WHL3019;
WHX3020:
	local[10]= NIL;
BLK3021:
	w = NIL;
	local[0]= w;
BLK3013:
	ctx->vsp=local; return(local[0]);}

/*:calc-inertia-matrix*/
static pointer M3022rotational_joint_calc_inertia_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=21) maerror();
	local[0]= argv[2];
	local[1]= argv[3];
	local[2]= argv[4];
	local[3]= argv[5];
	local[4]= argv[6];
	local[5]= argv[7];
	local[6]= argv[8];
	local[7]= argv[9];
	local[8]= argv[0]->c.obj.iv[2];
	local[9]= argv[10];
	local[10]= argv[11];
	local[11]= argv[12];
	local[12]= argv[13];
	local[13]= argv[14];
	local[14]= argv[15];
	local[15]= argv[16];
	local[16]= argv[17];
	local[17]= argv[18];
	local[18]= argv[19];
	local[19]= argv[20];
	ctx->vsp=local+20;
	w=(pointer)F2999calc_inertia_matrix_rotational(ctx,20,local+0); /*calc-inertia-matrix-rotational*/
	local[0]= w;
BLK3023:
	ctx->vsp=local; return(local[0]);}

/*:calc-inertia-matrix*/
static pointer M3024linear_joint_calc_inertia_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=21) maerror();
	local[0]= argv[2];
	local[1]= argv[3];
	local[2]= argv[4];
	local[3]= argv[5];
	local[4]= argv[6];
	local[5]= argv[7];
	local[6]= argv[8];
	local[7]= argv[9];
	local[8]= argv[0]->c.obj.iv[2];
	local[9]= argv[10];
	local[10]= argv[11];
	local[11]= argv[12];
	local[12]= argv[13];
	local[13]= argv[14];
	local[14]= argv[15];
	local[15]= argv[16];
	local[16]= argv[17];
	local[17]= argv[18];
	local[18]= argv[19];
	local[19]= argv[20];
	ctx->vsp=local+20;
	w=(pointer)F3000calc_inertia_matrix_linear(ctx,20,local+0); /*calc-inertia-matrix-linear*/
	local[0]= w;
BLK3025:
	ctx->vsp=local; return(local[0]);}

/*:calc-inertia-matrix*/
static pointer M3026omniwheel_joint_calc_inertia_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=21) maerror();
	local[0]= argv[2];
	local[1]= argv[3];
	local[2]= argv[4];
	local[3]= fqv[7];
	local[4]= argv[6];
	local[5]= argv[7];
	local[6]= argv[8];
	local[7]= argv[9];
	local[8]= argv[0]->c.obj.iv[2];
	local[9]= argv[10];
	local[10]= argv[11];
	local[11]= argv[12];
	local[12]= argv[13];
	local[13]= argv[14];
	local[14]= argv[15];
	local[15]= argv[16];
	local[16]= argv[17];
	local[17]= argv[18];
	local[18]= argv[19];
	local[19]= argv[20];
	ctx->vsp=local+20;
	w=(pointer)F3000calc_inertia_matrix_linear(ctx,20,local+0); /*calc-inertia-matrix-linear*/
	local[0]= argv[2];
	local[1]= argv[3];
	local[2]= argv[4];
	local[3]= makeint((eusinteger_t)1L);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= fqv[8];
	local[4]= argv[6];
	local[5]= argv[7];
	local[6]= argv[8];
	local[7]= argv[9];
	local[8]= argv[0]->c.obj.iv[2];
	local[9]= argv[10];
	local[10]= argv[11];
	local[11]= argv[12];
	local[12]= argv[13];
	local[13]= argv[14];
	local[14]= argv[15];
	local[15]= argv[16];
	local[16]= argv[17];
	local[17]= argv[18];
	local[18]= argv[19];
	local[19]= argv[20];
	ctx->vsp=local+20;
	w=(pointer)F3000calc_inertia_matrix_linear(ctx,20,local+0); /*calc-inertia-matrix-linear*/
	local[0]= argv[2];
	local[1]= argv[3];
	local[2]= argv[4];
	local[3]= makeint((eusinteger_t)2L);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= fqv[9];
	local[4]= argv[6];
	local[5]= argv[7];
	local[6]= argv[8];
	local[7]= argv[9];
	local[8]= argv[0]->c.obj.iv[2];
	local[9]= argv[10];
	local[10]= argv[11];
	local[11]= argv[12];
	local[12]= argv[13];
	local[13]= argv[14];
	local[14]= argv[15];
	local[15]= argv[16];
	local[16]= argv[17];
	local[17]= argv[18];
	local[18]= argv[19];
	local[19]= argv[20];
	ctx->vsp=local+20;
	w=(pointer)F2999calc_inertia_matrix_rotational(ctx,20,local+0); /*calc-inertia-matrix-rotational*/
	local[0]= w;
BLK3027:
	ctx->vsp=local; return(local[0]);}

/*:calc-inertia-matrix*/
static pointer M3028sphere_joint_calc_inertia_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=21) maerror();
	local[0]= argv[2];
	local[1]= argv[3];
	local[2]= argv[4];
	local[3]= fqv[10];
	local[4]= argv[6];
	local[5]= argv[7];
	local[6]= argv[8];
	local[7]= argv[9];
	local[8]= argv[0]->c.obj.iv[2];
	local[9]= argv[10];
	local[10]= argv[11];
	local[11]= argv[12];
	local[12]= argv[13];
	local[13]= argv[14];
	local[14]= argv[15];
	local[15]= argv[16];
	local[16]= argv[17];
	local[17]= argv[18];
	local[18]= argv[19];
	local[19]= argv[20];
	ctx->vsp=local+20;
	w=(pointer)F2999calc_inertia_matrix_rotational(ctx,20,local+0); /*calc-inertia-matrix-rotational*/
	local[0]= argv[2];
	local[1]= argv[3];
	local[2]= argv[4];
	local[3]= makeint((eusinteger_t)1L);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= fqv[11];
	local[4]= argv[6];
	local[5]= argv[7];
	local[6]= argv[8];
	local[7]= argv[9];
	local[8]= argv[0]->c.obj.iv[2];
	local[9]= argv[10];
	local[10]= argv[11];
	local[11]= argv[12];
	local[12]= argv[13];
	local[13]= argv[14];
	local[14]= argv[15];
	local[15]= argv[16];
	local[16]= argv[17];
	local[17]= argv[18];
	local[18]= argv[19];
	local[19]= argv[20];
	ctx->vsp=local+20;
	w=(pointer)F2999calc_inertia_matrix_rotational(ctx,20,local+0); /*calc-inertia-matrix-rotational*/
	local[0]= argv[2];
	local[1]= argv[3];
	local[2]= argv[4];
	local[3]= makeint((eusinteger_t)2L);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= fqv[12];
	local[4]= argv[6];
	local[5]= argv[7];
	local[6]= argv[8];
	local[7]= argv[9];
	local[8]= argv[0]->c.obj.iv[2];
	local[9]= argv[10];
	local[10]= argv[11];
	local[11]= argv[12];
	local[12]= argv[13];
	local[13]= argv[14];
	local[14]= argv[15];
	local[15]= argv[16];
	local[16]= argv[17];
	local[17]= argv[18];
	local[18]= argv[19];
	local[19]= argv[20];
	ctx->vsp=local+20;
	w=(pointer)F2999calc_inertia_matrix_rotational(ctx,20,local+0); /*calc-inertia-matrix-rotational*/
	local[0]= w;
BLK3029:
	ctx->vsp=local; return(local[0]);}

/*:calc-inertia-matrix*/
static pointer M30306dof_joint_calc_inertia_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=21) maerror();
	local[0]= argv[2];
	local[1]= argv[3];
	local[2]= argv[4];
	local[3]= fqv[13];
	local[4]= argv[6];
	local[5]= argv[7];
	local[6]= argv[8];
	local[7]= argv[9];
	local[8]= argv[0]->c.obj.iv[2];
	local[9]= argv[10];
	local[10]= argv[11];
	local[11]= argv[12];
	local[12]= argv[13];
	local[13]= argv[14];
	local[14]= argv[15];
	local[15]= argv[16];
	local[16]= argv[17];
	local[17]= argv[18];
	local[18]= argv[19];
	local[19]= argv[20];
	ctx->vsp=local+20;
	w=(pointer)F3000calc_inertia_matrix_linear(ctx,20,local+0); /*calc-inertia-matrix-linear*/
	local[0]= argv[2];
	local[1]= argv[3];
	local[2]= argv[4];
	local[3]= makeint((eusinteger_t)1L);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= fqv[14];
	local[4]= argv[6];
	local[5]= argv[7];
	local[6]= argv[8];
	local[7]= argv[9];
	local[8]= argv[0]->c.obj.iv[2];
	local[9]= argv[10];
	local[10]= argv[11];
	local[11]= argv[12];
	local[12]= argv[13];
	local[13]= argv[14];
	local[14]= argv[15];
	local[15]= argv[16];
	local[16]= argv[17];
	local[17]= argv[18];
	local[18]= argv[19];
	local[19]= argv[20];
	ctx->vsp=local+20;
	w=(pointer)F3000calc_inertia_matrix_linear(ctx,20,local+0); /*calc-inertia-matrix-linear*/
	local[0]= argv[2];
	local[1]= argv[3];
	local[2]= argv[4];
	local[3]= makeint((eusinteger_t)2L);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= fqv[15];
	local[4]= argv[6];
	local[5]= argv[7];
	local[6]= argv[8];
	local[7]= argv[9];
	local[8]= argv[0]->c.obj.iv[2];
	local[9]= argv[10];
	local[10]= argv[11];
	local[11]= argv[12];
	local[12]= argv[13];
	local[13]= argv[14];
	local[14]= argv[15];
	local[15]= argv[16];
	local[16]= argv[17];
	local[17]= argv[18];
	local[18]= argv[19];
	local[19]= argv[20];
	ctx->vsp=local+20;
	w=(pointer)F3000calc_inertia_matrix_linear(ctx,20,local+0); /*calc-inertia-matrix-linear*/
	local[0]= argv[2];
	local[1]= argv[3];
	local[2]= argv[4];
	local[3]= makeint((eusinteger_t)3L);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= fqv[16];
	local[4]= argv[6];
	local[5]= argv[7];
	local[6]= argv[8];
	local[7]= argv[9];
	local[8]= argv[0]->c.obj.iv[2];
	local[9]= argv[10];
	local[10]= argv[11];
	local[11]= argv[12];
	local[12]= argv[13];
	local[13]= argv[14];
	local[14]= argv[15];
	local[15]= argv[16];
	local[16]= argv[17];
	local[17]= argv[18];
	local[18]= argv[19];
	local[19]= argv[20];
	ctx->vsp=local+20;
	w=(pointer)F2999calc_inertia_matrix_rotational(ctx,20,local+0); /*calc-inertia-matrix-rotational*/
	local[0]= argv[2];
	local[1]= argv[3];
	local[2]= argv[4];
	local[3]= makeint((eusinteger_t)4L);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= fqv[17];
	local[4]= argv[6];
	local[5]= argv[7];
	local[6]= argv[8];
	local[7]= argv[9];
	local[8]= argv[0]->c.obj.iv[2];
	local[9]= argv[10];
	local[10]= argv[11];
	local[11]= argv[12];
	local[12]= argv[13];
	local[13]= argv[14];
	local[14]= argv[15];
	local[15]= argv[16];
	local[16]= argv[17];
	local[17]= argv[18];
	local[18]= argv[19];
	local[19]= argv[20];
	ctx->vsp=local+20;
	w=(pointer)F2999calc_inertia_matrix_rotational(ctx,20,local+0); /*calc-inertia-matrix-rotational*/
	local[0]= argv[2];
	local[1]= argv[3];
	local[2]= argv[4];
	local[3]= makeint((eusinteger_t)5L);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= fqv[18];
	local[4]= argv[6];
	local[5]= argv[7];
	local[6]= argv[8];
	local[7]= argv[9];
	local[8]= argv[0]->c.obj.iv[2];
	local[9]= argv[10];
	local[10]= argv[11];
	local[11]= argv[12];
	local[12]= argv[13];
	local[13]= argv[14];
	local[14]= argv[15];
	local[15]= argv[16];
	local[16]= argv[17];
	local[17]= argv[18];
	local[18]= argv[19];
	local[19]= argv[20];
	ctx->vsp=local+20;
	w=(pointer)F2999calc_inertia_matrix_rotational(ctx,20,local+0); /*calc-inertia-matrix-rotational*/
	local[0]= w;
BLK3031:
	ctx->vsp=local; return(local[0]);}

/*:append-weight-no-update*/
static pointer M3032bodyset_link_append_weight_no_update(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[19], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY3034;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[0] = w;
KEY3034:
	local[1]= argv[0];
	local[2]= fqv[20];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= makeint((eusinteger_t)0L);
	local[3]= local[0];
WHL3036:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX3037;
	local[4]= argv[2];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[1] = w;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL3036;
WHX3037:
	local[4]= NIL;
BLK3038:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK3033:
	ctx->vsp=local; return(local[0]);}

/*:append-centroid-no-update*/
static pointer M3039bodyset_link_append_centroid_no_update(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<6) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[21], &argv[6], n-6, local+0, 0);
	if (n & (1<<0)) goto KEY3041;
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[0] = w;
KEY3041:
	if (n & (1<<1)) goto KEY3042;
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[1] = w;
KEY3042:
	if (n & (1<<2)) goto KEY3043;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[2] = w;
KEY3043:
	local[3]= argv[5];
	ctx->vsp=local+4;
	w=(pointer)EUSFLOAT(ctx,1,local+3); /*float*/
	local[3]= w;
	local[4]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[22]); /*eps=*/
	if (w==NIL) goto IF3044;
	local[3]= argv[4];
	goto IF3045;
IF3044:
	local[3]= makeflt(1.0000000000000000000000e+00);
	local[4]= argv[5];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[20];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= argv[4];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SCALEVEC(ctx,3,local+4); /*scale*/
	local[4]= w;
	local[5]= makeint((eusinteger_t)0L);
	local[6]= local[2];
WHL3047:
	local[7]= local[5];
	w = local[6];
	if ((eusinteger_t)local[7] >= (eusinteger_t)w) goto WHX3048;
	local[7]= local[4];
	local[8]= argv[2];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	local[9]= argv[3];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)SCALEVEC(ctx,3,local+8); /*scale*/
	local[8]= w;
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)VPLUS(ctx,3,local+7); /*v+*/
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[5] = w;
	goto WHL3047;
WHX3048:
	local[7]= NIL;
BLK3049:
	w = NIL;
	w = local[4];
	local[4]= w;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SCALEVEC(ctx,3,local+3); /*scale*/
	local[3]= w;
IF3045:
	w = local[3];
	local[0]= w;
BLK3040:
	ctx->vsp=local; return(local[0]);}

/*:append-inertia-no-update*/
static pointer M3050bodyset_link_append_inertia_no_update(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<7) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[23], &argv[7], n-7, local+0, 0);
	if (n & (1<<0)) goto KEY3052;
	local[6]= makeint((eusinteger_t)3L);
	local[7]= makeint((eusinteger_t)3L);
	ctx->vsp=local+8;
	w=(*ftab[5])(ctx,2,local+6,&ftab[5],fqv[24]); /*make-matrix*/
	local[0] = w;
KEY3052:
	if (n & (1<<1)) goto KEY3053;
	local[6]= makeint((eusinteger_t)3L);
	local[7]= makeint((eusinteger_t)3L);
	ctx->vsp=local+8;
	w=(*ftab[5])(ctx,2,local+6,&ftab[5],fqv[24]); /*make-matrix*/
	local[1] = w;
KEY3053:
	if (n & (1<<2)) goto KEY3054;
	local[6]= makeint((eusinteger_t)3L);
	local[7]= makeint((eusinteger_t)3L);
	ctx->vsp=local+8;
	w=(*ftab[5])(ctx,2,local+6,&ftab[5],fqv[24]); /*make-matrix*/
	local[2] = w;
KEY3054:
	if (n & (1<<3)) goto KEY3055;
	local[6]= makeint((eusinteger_t)3L);
	local[7]= makeint((eusinteger_t)3L);
	ctx->vsp=local+8;
	w=(*ftab[5])(ctx,2,local+6,&ftab[5],fqv[24]); /*make-matrix*/
	local[3] = w;
KEY3055:
	if (n & (1<<4)) goto KEY3056;
	local[6]= makeint((eusinteger_t)0L);
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,3,local+6); /*float-vector*/
	local[4] = w;
KEY3056:
	if (n & (1<<5)) goto KEY3057;
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[5] = w;
KEY3057:
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,FLET3058,env,argv,local);
	local[7]= argv[0];
	local[8]= fqv[25];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= argv[0];
	local[9]= fqv[26];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)MATTIMES(ctx,3,local+7); /*m**/
	local[7]= w;
	local[8]= argv[0];
	local[9]= fqv[25];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)TRANSPOSE(ctx,2,local+8); /*transpose*/
	local[8]= w;
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)MATTIMES(ctx,3,local+7); /*m**/
	local[7]= w;
	local[8]= argv[0];
	local[9]= fqv[20];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= argv[5];
	local[10]= argv[6];
	local[11]= local[4];
	ctx->vsp=local+12;
	w=(pointer)VMINUS(ctx,3,local+9); /*v-*/
	local[9]= w;
	w = local[6];
	ctx->vsp=local+10;
	w=FLET3058(ctx,1,local+9,w);
	local[9]= w;
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(*ftab[2])(ctx,3,local+8,&ftab[2],fqv[4]); /*scale-matrix*/
	local[8]= w;
	local[9]= local[7];
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(*ftab[6])(ctx,3,local+8,&ftab[6],fqv[27]); /*m+*/
	local[8]= makeint((eusinteger_t)0L);
	local[9]= local[5];
WHL3060:
	local[10]= local[8];
	w = local[9];
	if ((eusinteger_t)local[10] >= (eusinteger_t)w) goto WHX3061;
	local[10]= argv[4];
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(pointer)ELT(ctx,2,local+10); /*elt*/
	local[10]= w;
	local[11]= local[7];
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(*ftab[6])(ctx,3,local+10,&ftab[6],fqv[27]); /*m+*/
	local[10]= argv[2];
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(pointer)ELT(ctx,2,local+10); /*elt*/
	local[10]= w;
	local[11]= argv[3];
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	local[12]= argv[6];
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)VMINUS(ctx,3,local+11); /*v-*/
	local[11]= w;
	w = local[6];
	ctx->vsp=local+12;
	w=FLET3058(ctx,1,local+11,w);
	local[11]= w;
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(*ftab[2])(ctx,3,local+10,&ftab[2],fqv[4]); /*scale-matrix*/
	local[10]= w;
	local[11]= local[7];
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(*ftab[6])(ctx,3,local+10,&ftab[6],fqv[27]); /*m+*/
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[8] = w;
	goto WHL3060;
WHX3061:
	local[10]= NIL;
BLK3062:
	w = NIL;
	w = local[7];
	local[0]= w;
BLK3051:
	ctx->vsp=local; return(local[0]);}

/*:append-mass-properties*/
static pointer M3063bodyset_link_append_mass_properties(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[28], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY3065;
	local[0] = T;
KEY3065:
	if (n & (1<<1)) goto KEY3066;
	local[11]= makeint((eusinteger_t)0L);
	local[12]= makeint((eusinteger_t)0L);
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(pointer)MKFLTVEC(ctx,3,local+11); /*float-vector*/
	local[1] = w;
KEY3066:
	if (n & (1<<2)) goto KEY3067;
	local[11]= makeint((eusinteger_t)0L);
	local[12]= makeint((eusinteger_t)0L);
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(pointer)MKFLTVEC(ctx,3,local+11); /*float-vector*/
	local[2] = w;
KEY3067:
	if (n & (1<<3)) goto KEY3068;
	local[11]= makeint((eusinteger_t)3L);
	local[12]= makeint((eusinteger_t)3L);
	ctx->vsp=local+13;
	w=(*ftab[5])(ctx,2,local+11,&ftab[5],fqv[24]); /*make-matrix*/
	local[3] = w;
KEY3068:
	if (n & (1<<4)) goto KEY3069;
	local[11]= makeint((eusinteger_t)3L);
	local[12]= makeint((eusinteger_t)3L);
	ctx->vsp=local+13;
	w=(*ftab[5])(ctx,2,local+11,&ftab[5],fqv[24]); /*make-matrix*/
	local[4] = w;
KEY3069:
	if (n & (1<<5)) goto KEY3070;
	local[11]= makeint((eusinteger_t)3L);
	local[12]= makeint((eusinteger_t)3L);
	ctx->vsp=local+13;
	w=(*ftab[5])(ctx,2,local+11,&ftab[5],fqv[24]); /*make-matrix*/
	local[5] = w;
KEY3070:
	if (n & (1<<6)) goto KEY3071;
	local[11]= makeint((eusinteger_t)3L);
	local[12]= makeint((eusinteger_t)3L);
	ctx->vsp=local+13;
	w=(*ftab[5])(ctx,2,local+11,&ftab[5],fqv[24]); /*make-matrix*/
	local[6] = w;
KEY3071:
	if (n & (1<<7)) goto KEY3072;
	local[11]= argv[2];
	local[12]= fqv[20];
	ctx->vsp=local+13;
	w=(*ftab[7])(ctx,2,local+11,&ftab[7],fqv[29]); /*send-all*/
	local[7] = w;
KEY3072:
	if (n & (1<<8)) goto KEY3073;
	local[11]= argv[2];
	local[12]= fqv[30];
	ctx->vsp=local+13;
	w=(*ftab[7])(ctx,2,local+11,&ftab[7],fqv[29]); /*send-all*/
	local[8] = w;
KEY3073:
	if (n & (1<<9)) goto KEY3074;
	ctx->vsp=local+11;
	local[11]= makeclosure(codevec,quotevec,CLO3075,env,argv,local);
	local[12]= argv[2];
	ctx->vsp=local+13;
	w=(pointer)MAPCAR(ctx,2,local+11); /*mapcar*/
	local[9] = w;
KEY3074:
	if (n & (1<<10)) goto KEY3076;
	local[11]= argv[0];
	local[12]= fqv[30];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[10] = w;
KEY3076:
	local[11]= argv[2];
	ctx->vsp=local+12;
	w=(pointer)LENGTH(ctx,1,local+11); /*length*/
	local[11]= w;
	local[12]= argv[0];
	local[13]= fqv[31];
	local[14]= local[7];
	local[15]= fqv[32];
	local[16]= local[11];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,5,local+12); /*send*/
	local[12]= w;
	local[13]= argv[0];
	local[14]= fqv[33];
	local[15]= local[7];
	local[16]= local[8];
	local[17]= local[10];
	local[18]= local[12];
	local[19]= fqv[34];
	local[20]= local[1];
	local[21]= fqv[35];
	local[22]= local[2];
	local[23]= fqv[32];
	local[24]= local[11];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,12,local+13); /*send*/
	local[13]= w;
	local[14]= argv[0];
	local[15]= fqv[36];
	local[16]= local[7];
	local[17]= local[8];
	local[18]= local[9];
	local[19]= local[10];
	local[20]= local[13];
	local[21]= fqv[37];
	local[22]= local[3];
	local[23]= fqv[38];
	local[24]= local[4];
	local[25]= fqv[39];
	local[26]= local[5];
	local[27]= fqv[40];
	local[28]= local[6];
	local[29]= fqv[34];
	local[30]= local[1];
	local[31]= fqv[32];
	local[32]= local[11];
	ctx->vsp=local+33;
	w=(pointer)SEND(ctx,19,local+14); /*send*/
	local[14]= w;
	if (local[0]==NIL) goto IF3077;
	local[15]= argv[0];
	local[16]= fqv[20];
	local[17]= local[12];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,3,local+15); /*send*/
	local[15]= argv[0];
	local[16]= fqv[41];
	local[17]= local[13];
	local[18]= argv[0]->c.obj.iv[15];
	local[19]= local[1];
	local[20]= local[3];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,6,local+15); /*send*/
	argv[0]->c.obj.iv[15] = w;
	local[15]= argv[0];
	local[16]= fqv[26];
	local[17]= argv[0];
	local[18]= fqv[25];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
	local[18]= local[3];
	ctx->vsp=local+19;
	w=(pointer)TRANSPOSE(ctx,2,local+17); /*transpose*/
	local[17]= w;
	local[18]= local[14];
	local[19]= local[4];
	ctx->vsp=local+20;
	w=(pointer)MATTIMES(ctx,3,local+17); /*m**/
	local[17]= w;
	local[18]= argv[0];
	local[19]= fqv[25];
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,2,local+18); /*send*/
	local[18]= w;
	local[19]= argv[0];
	local[20]= fqv[26];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,2,local+19); /*send*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)MATTIMES(ctx,3,local+17); /*m**/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,3,local+15); /*send*/
	local[15]= w;
	goto IF3078;
IF3077:
	local[15]= NIL;
IF3078:
	local[15]= local[12];
	local[16]= local[13];
	local[17]= local[14];
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,3,local+15); /*list*/
	local[0]= w;
BLK3064:
	ctx->vsp=local; return(local[0]);}

/*:propagate-mass-properties*/
static pointer M3079bodyset_link_propagate_mass_properties(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[42], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY3081;
	local[0] = NIL;
KEY3081:
	if (n & (1<<1)) goto KEY3082;
	local[6]= loadglobal(fqv[43]);
	local[7]= makeint((eusinteger_t)3L);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,2,local+6); /*instantiate*/
	local[1] = w;
KEY3082:
	if (n & (1<<2)) goto KEY3083;
	local[6]= loadglobal(fqv[43]);
	local[7]= makeint((eusinteger_t)3L);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,2,local+6); /*instantiate*/
	local[2] = w;
KEY3083:
	if (n & (1<<3)) goto KEY3084;
	local[6]= makeint((eusinteger_t)3L);
	local[7]= makeint((eusinteger_t)3L);
	ctx->vsp=local+8;
	w=(*ftab[5])(ctx,2,local+6,&ftab[5],fqv[24]); /*make-matrix*/
	local[3] = w;
KEY3084:
	if (n & (1<<4)) goto KEY3085;
	local[6]= makeint((eusinteger_t)3L);
	local[7]= makeint((eusinteger_t)3L);
	ctx->vsp=local+8;
	w=(*ftab[5])(ctx,2,local+6,&ftab[5],fqv[24]); /*make-matrix*/
	local[4] = w;
KEY3085:
	if (n & (1<<5)) goto KEY3086;
	local[6]= makeint((eusinteger_t)3L);
	local[7]= makeint((eusinteger_t)3L);
	ctx->vsp=local+8;
	w=(*ftab[5])(ctx,2,local+6,&ftab[5],fqv[24]); /*make-matrix*/
	local[5] = w;
KEY3086:
	if (argv[0]->c.obj.iv[11]==NIL) goto IF3087;
	local[6]= NIL;
	local[7]= argv[0]->c.obj.iv[11];
WHL3090:
	if (local[7]==NIL) goto WHX3091;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	local[9]= fqv[44];
	local[10]= fqv[45];
	local[11]= local[0];
	local[12]= fqv[34];
	local[13]= local[1];
	local[14]= fqv[35];
	local[15]= local[2];
	local[16]= fqv[37];
	local[17]= local[3];
	local[18]= fqv[38];
	local[19]= local[4];
	local[20]= fqv[39];
	local[21]= local[5];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,14,local+8); /*send*/
	goto WHL3090;
WHX3091:
	local[8]= NIL;
BLK3092:
	w = NIL;
	local[6]= argv[0];
	local[7]= fqv[46];
	local[8]= fqv[47];
	local[9]= argv[0];
	local[10]= fqv[48];
	local[11]= argv[0]->c.obj.iv[11];
	local[12]= fqv[37];
	local[13]= local[3];
	local[14]= fqv[38];
	local[15]= local[4];
	local[16]= fqv[39];
	local[17]= local[5];
	local[18]= fqv[40];
	local[19]= argv[0];
	local[20]= fqv[49];
	local[21]= fqv[50];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,3,local+19); /*send*/
	local[19]= w;
	local[20]= fqv[34];
	local[21]= local[1];
	local[22]= fqv[35];
	local[23]= argv[0];
	local[24]= fqv[49];
	local[25]= fqv[51];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,3,local+23); /*send*/
	local[23]= w;
	local[24]= fqv[52];
	local[25]= argv[0]->c.obj.iv[11];
	local[26]= fqv[49];
	local[27]= fqv[47];
	ctx->vsp=local+28;
	w=(*ftab[7])(ctx,3,local+25,&ftab[7],fqv[29]); /*send-all*/
	local[25]= w;
	local[26]= fqv[53];
	local[27]= argv[0]->c.obj.iv[11];
	local[28]= fqv[49];
	local[29]= fqv[51];
	ctx->vsp=local+30;
	w=(*ftab[7])(ctx,3,local+27,&ftab[7],fqv[29]); /*send-all*/
	local[27]= w;
	local[28]= fqv[54];
	local[29]= argv[0]->c.obj.iv[11];
	local[30]= fqv[49];
	local[31]= fqv[50];
	ctx->vsp=local+32;
	w=(*ftab[7])(ctx,3,local+29,&ftab[7],fqv[29]); /*send-all*/
	local[29]= w;
	local[30]= fqv[55];
	local[31]= argv[0];
	local[32]= fqv[30];
	ctx->vsp=local+33;
	w=(pointer)SEND(ctx,2,local+31); /*send*/
	local[31]= w;
	local[32]= fqv[56];
	local[33]= NIL;
	ctx->vsp=local+34;
	w=(pointer)SEND(ctx,25,local+9); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[6]= w;
	goto IF3088;
IF3087:
	local[6]= argv[0];
	local[7]= fqv[30];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)3L);
WHL3095:
	local[9]= local[7];
	w = local[8];
	if ((eusinteger_t)local[9] >= (eusinteger_t)w) goto WHX3096;
	local[9]= argv[0];
	local[10]= fqv[49];
	local[11]= fqv[51];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= w;
	local[10]= local[7];
	local[11]= local[6];
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)SETELT(ctx,3,local+9); /*setelt*/
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	local[7] = w;
	goto WHL3095;
WHX3096:
	local[9]= NIL;
BLK3097:
	w = NIL;
	local[7]= argv[0];
	local[8]= fqv[46];
	local[9]= fqv[47];
	local[10]= argv[0];
	local[11]= fqv[20];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[7]= argv[0];
	local[8]= fqv[25];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= argv[0];
	local[9]= fqv[26];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)MATTIMES(ctx,3,local+7); /*m**/
	local[7]= w;
	local[8]= argv[0];
	local[9]= fqv[25];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)TRANSPOSE(ctx,2,local+8); /*transpose*/
	local[8]= w;
	local[9]= argv[0];
	local[10]= fqv[49];
	local[11]= fqv[50];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MATTIMES(ctx,3,local+7); /*m**/
	local[6]= w;
IF3088:
	if (local[0]==NIL) goto IF3098;
	local[6]= fqv[57];
	local[7]= argv[0];
	local[8]= fqv[58];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= argv[0];
	local[9]= fqv[49];
	local[10]= fqv[47];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	local[9]= argv[0];
	local[10]= fqv[49];
	local[11]= fqv[51];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[0])(ctx,4,local+6,&ftab[0],fqv[1]); /*warn*/
	local[6]= w;
	goto IF3099;
IF3098:
	local[6]= NIL;
IF3099:
	w = T;
	local[0]= w;
BLK3080:
	ctx->vsp=local; return(local[0]);}

/*:calc-inertia-matrix-column*/
static pointer M3100bodyset_link_calc_inertia_matrix_column(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST3102:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[59], &argv[3], n-3, local+1, 1);
	if (n & (1<<0)) goto KEY3103;
	local[1] = NIL;
KEY3103:
	if (n & (1<<1)) goto KEY3104;
	local[2] = T;
KEY3104:
	if (n & (1<<2)) goto KEY3105;
	local[3] = NIL;
KEY3105:
	if (n & (1<<3)) goto KEY3106;
	local[13]= makeint((eusinteger_t)0L);
	local[14]= makeint((eusinteger_t)0L);
	local[15]= makeint((eusinteger_t)0L);
	ctx->vsp=local+16;
	w=(pointer)MKFLTVEC(ctx,3,local+13); /*float-vector*/
	local[4] = w;
KEY3106:
	if (n & (1<<4)) goto KEY3107;
	local[13]= loadglobal(fqv[43]);
	local[14]= makeint((eusinteger_t)0L);
	ctx->vsp=local+15;
	w=(pointer)INSTANTIATE(ctx,2,local+13); /*instantiate*/
	local[5] = w;
KEY3107:
	if (n & (1<<5)) goto KEY3108;
	local[13]= loadglobal(fqv[43]);
	local[14]= makeint((eusinteger_t)1L);
	ctx->vsp=local+15;
	w=(pointer)INSTANTIATE(ctx,2,local+13); /*instantiate*/
	local[6] = w;
KEY3108:
	if (n & (1<<6)) goto KEY3109;
	local[13]= loadglobal(fqv[43]);
	local[14]= makeint((eusinteger_t)2L);
	ctx->vsp=local+15;
	w=(pointer)INSTANTIATE(ctx,2,local+13); /*instantiate*/
	local[7] = w;
KEY3109:
	if (n & (1<<7)) goto KEY3110;
	local[13]= loadglobal(fqv[43]);
	local[14]= makeint((eusinteger_t)3L);
	ctx->vsp=local+15;
	w=(pointer)INSTANTIATE(ctx,2,local+13); /*instantiate*/
	local[8] = w;
KEY3110:
	if (n & (1<<8)) goto KEY3111;
	local[13]= loadglobal(fqv[43]);
	local[14]= makeint((eusinteger_t)3L);
	ctx->vsp=local+15;
	w=(pointer)INSTANTIATE(ctx,2,local+13); /*instantiate*/
	local[9] = w;
KEY3111:
	if (n & (1<<9)) goto KEY3112;
	local[13]= loadglobal(fqv[43]);
	local[14]= makeint((eusinteger_t)3L);
	ctx->vsp=local+15;
	w=(pointer)INSTANTIATE(ctx,2,local+13); /*instantiate*/
	local[10] = w;
KEY3112:
	if (n & (1<<10)) goto KEY3113;
	local[13]= loadglobal(fqv[43]);
	local[14]= makeint((eusinteger_t)3L);
	ctx->vsp=local+15;
	w=(pointer)INSTANTIATE(ctx,2,local+13); /*instantiate*/
	local[11] = w;
KEY3113:
	if (n & (1<<11)) goto KEY3114;
	local[13]= makeint((eusinteger_t)3L);
	local[14]= makeint((eusinteger_t)3L);
	ctx->vsp=local+15;
	w=(*ftab[5])(ctx,2,local+13,&ftab[5],fqv[24]); /*make-matrix*/
	local[12] = w;
KEY3114:
	local[13]= *(ovafptr(argv[0]->c.obj.iv[9],fqv[60]));
	local[14]= local[13];
	if (fqv[61]!=local[14]) goto IF3116;
	local[14]= makeint((eusinteger_t)1L);
	local[15]= makeint((eusinteger_t)0L);
	local[16]= makeint((eusinteger_t)0L);
	ctx->vsp=local+17;
	w=(pointer)MKFLTVEC(ctx,3,local+14); /*float-vector*/
	local[14]= w;
	goto IF3117;
IF3116:
	local[14]= local[13];
	if (fqv[62]!=local[14]) goto IF3118;
	local[14]= makeint((eusinteger_t)-1L);
	local[15]= makeint((eusinteger_t)0L);
	local[16]= makeint((eusinteger_t)0L);
	ctx->vsp=local+17;
	w=(pointer)MKFLTVEC(ctx,3,local+14); /*float-vector*/
	local[14]= w;
	goto IF3119;
IF3118:
	local[14]= local[13];
	if (fqv[63]!=local[14]) goto IF3120;
	local[14]= makeint((eusinteger_t)0L);
	local[15]= makeint((eusinteger_t)1L);
	local[16]= makeint((eusinteger_t)0L);
	ctx->vsp=local+17;
	w=(pointer)MKFLTVEC(ctx,3,local+14); /*float-vector*/
	local[14]= w;
	goto IF3121;
IF3120:
	local[14]= local[13];
	if (fqv[64]!=local[14]) goto IF3122;
	local[14]= makeint((eusinteger_t)0L);
	local[15]= makeint((eusinteger_t)-1L);
	local[16]= makeint((eusinteger_t)0L);
	ctx->vsp=local+17;
	w=(pointer)MKFLTVEC(ctx,3,local+14); /*float-vector*/
	local[14]= w;
	goto IF3123;
IF3122:
	local[14]= local[13];
	if (fqv[65]!=local[14]) goto IF3124;
	local[14]= makeint((eusinteger_t)0L);
	local[15]= makeint((eusinteger_t)0L);
	local[16]= makeint((eusinteger_t)1L);
	ctx->vsp=local+17;
	w=(pointer)MKFLTVEC(ctx,3,local+14); /*float-vector*/
	local[14]= w;
	goto IF3125;
IF3124:
	local[14]= local[13];
	if (fqv[66]!=local[14]) goto IF3126;
	local[14]= makeint((eusinteger_t)0L);
	local[15]= makeint((eusinteger_t)0L);
	local[16]= makeint((eusinteger_t)-1L);
	ctx->vsp=local+17;
	w=(pointer)MKFLTVEC(ctx,3,local+14); /*float-vector*/
	local[14]= w;
	goto IF3127;
IF3126:
	if (T==NIL) goto IF3128;
	local[14]= *(ovafptr(argv[0]->c.obj.iv[9],fqv[60]));
	goto IF3129;
IF3128:
	local[14]= NIL;
IF3129:
IF3127:
IF3125:
IF3123:
IF3121:
IF3119:
IF3117:
	w = local[14];
	local[13]= w;
	local[14]= makeint((eusinteger_t)0L);
	local[15]= argv[0]->c.obj.iv[9];
	local[16]= fqv[67];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
	local[16]= fqv[68];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
	local[16]= fqv[69];
	local[17]= *(ovafptr(argv[0]->c.obj.iv[9],fqv[70]));
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,3,local+15); /*send*/
	local[15]= w;
	local[16]= argv[0]->c.obj.iv[9];
	local[17]= fqv[71];
	local[18]= local[3];
	local[19]= local[14];
	local[20]= argv[2];
	local[21]= local[13];
	local[22]= argv[0];
	local[23]= fqv[49];
	local[24]= fqv[47];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[22]= w;
	local[23]= argv[0];
	local[24]= fqv[49];
	local[25]= fqv[51];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,3,local+23); /*send*/
	local[23]= w;
	local[24]= argv[0];
	local[25]= fqv[49];
	local[26]= fqv[50];
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,3,local+24); /*send*/
	local[24]= w;
	local[25]= local[4];
	local[26]= local[15];
	local[27]= local[2];
	local[28]= local[1];
	local[29]= local[5];
	local[30]= local[6];
	local[31]= local[7];
	local[32]= local[8];
	local[33]= local[9];
	local[34]= local[10];
	local[35]= local[11];
	local[36]= local[12];
	ctx->vsp=local+37;
	w=(pointer)SEND(ctx,21,local+16); /*send*/
	w = T;
	local[0]= w;
BLK3101:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET3058(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env2[0];
	ctx->vsp=local+2;
	w=(*ftab[8])(ctx,2,local+0,&ftab[8],fqv[72]); /*outer-product-matrix*/
	local[0]= w;
	local[1]= local[0];
	local[2]= env->c.clo.env2[1];
	ctx->vsp=local+3;
	w=(pointer)TRANSPOSE(ctx,2,local+1); /*transpose*/
	local[1]= w;
	local[2]= local[0];
	local[3]= env->c.clo.env2[2];
	ctx->vsp=local+4;
	w=(pointer)MATTIMES(ctx,3,local+1); /*m**/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3075(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[25];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[26];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= env->c.clo.env2[3];
	ctx->vsp=local+3;
	w=(pointer)MATTIMES(ctx,3,local+0); /*m**/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[25];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= env->c.clo.env2[4];
	ctx->vsp=local+3;
	w=(pointer)TRANSPOSE(ctx,2,local+1); /*transpose*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MATTIMES(ctx,2,local+0); /*m**/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:update-mass-properties*/
static pointer M3130cascaded_link_update_mass_properties(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[73], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY3132;
	local[5]= loadglobal(fqv[43]);
	local[6]= makeint((eusinteger_t)3L);
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,2,local+5); /*instantiate*/
	local[0] = w;
KEY3132:
	if (n & (1<<1)) goto KEY3133;
	local[5]= loadglobal(fqv[43]);
	local[6]= makeint((eusinteger_t)3L);
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,2,local+5); /*instantiate*/
	local[1] = w;
KEY3133:
	if (n & (1<<2)) goto KEY3134;
	local[5]= makeint((eusinteger_t)3L);
	local[6]= makeint((eusinteger_t)3L);
	ctx->vsp=local+7;
	w=(*ftab[5])(ctx,2,local+5,&ftab[5],fqv[24]); /*make-matrix*/
	local[2] = w;
KEY3134:
	if (n & (1<<3)) goto KEY3135;
	local[5]= makeint((eusinteger_t)3L);
	local[6]= makeint((eusinteger_t)3L);
	ctx->vsp=local+7;
	w=(*ftab[5])(ctx,2,local+5,&ftab[5],fqv[24]); /*make-matrix*/
	local[3] = w;
KEY3135:
	if (n & (1<<4)) goto KEY3136;
	local[5]= makeint((eusinteger_t)3L);
	local[6]= makeint((eusinteger_t)3L);
	ctx->vsp=local+7;
	w=(*ftab[5])(ctx,2,local+5,&ftab[5],fqv[24]); /*make-matrix*/
	local[4] = w;
KEY3136:
	local[5]= argv[0];
	local[6]= fqv[74];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO3137,env,argv,local);
	ctx->vsp=local+7;
	w=(*ftab[9])(ctx,2,local+5,&ftab[9],fqv[75]); /*all-child-links*/
	local[5]= argv[0];
	local[6]= fqv[74];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= fqv[44];
	local[7]= fqv[34];
	local[8]= local[0];
	local[9]= fqv[35];
	local[10]= local[1];
	local[11]= fqv[37];
	local[12]= local[2];
	local[13]= fqv[38];
	local[14]= local[3];
	local[15]= fqv[39];
	local[16]= local[4];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,12,local+5); /*send*/
	local[0]= w;
BLK3131:
	ctx->vsp=local; return(local[0]);}

/*:calc-inertia-matrix-from-link-list*/
static pointer M3138cascaded_link_calc_inertia_matrix_from_link_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3140:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[76], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3141;
	local[18]= argv[0]->c.obj.iv[9];
	local[19]= fqv[77];
	ctx->vsp=local+20;
	w=(*ftab[7])(ctx,2,local+18,&ftab[7],fqv[29]); /*send-all*/
	local[1] = w;
KEY3141:
	if (n & (1<<1)) goto KEY3142;
	local[2] = NIL;
KEY3142:
	if (n & (1<<2)) goto KEY3143;
	local[3] = T;
KEY3143:
	if (n & (1<<3)) goto KEY3144;
	local[18]= argv[0];
	local[19]= fqv[78];
	local[20]= local[2];
	local[21]= local[3];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,4,local+18); /*send*/
	local[4] = w;
KEY3144:
	if (n & (1<<4)) goto KEY3145;
	local[18]= local[4];
	local[19]= argv[0];
	local[20]= fqv[79];
	local[21]= local[1];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,3,local+19); /*send*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(*ftab[5])(ctx,2,local+18,&ftab[5],fqv[24]); /*make-matrix*/
	local[5] = w;
KEY3145:
	if (n & (1<<5)) goto KEY3146;
	local[6] = T;
KEY3146:
	if (n & (1<<6)) goto KEY3147;
	local[7] = NIL;
KEY3147:
	if (n & (1<<7)) goto KEY3148;
	local[18]= loadglobal(fqv[43]);
	local[19]= makeint((eusinteger_t)0L);
	ctx->vsp=local+20;
	w=(pointer)INSTANTIATE(ctx,2,local+18); /*instantiate*/
	local[8] = w;
KEY3148:
	if (n & (1<<8)) goto KEY3149;
	local[18]= loadglobal(fqv[43]);
	local[19]= makeint((eusinteger_t)1L);
	ctx->vsp=local+20;
	w=(pointer)INSTANTIATE(ctx,2,local+18); /*instantiate*/
	local[9] = w;
KEY3149:
	if (n & (1<<9)) goto KEY3150;
	local[18]= loadglobal(fqv[43]);
	local[19]= makeint((eusinteger_t)2L);
	ctx->vsp=local+20;
	w=(pointer)INSTANTIATE(ctx,2,local+18); /*instantiate*/
	local[10] = w;
KEY3150:
	if (n & (1<<10)) goto KEY3151;
	local[18]= loadglobal(fqv[43]);
	local[19]= makeint((eusinteger_t)3L);
	ctx->vsp=local+20;
	w=(pointer)INSTANTIATE(ctx,2,local+18); /*instantiate*/
	local[11] = w;
KEY3151:
	if (n & (1<<11)) goto KEY3152;
	local[18]= loadglobal(fqv[43]);
	local[19]= makeint((eusinteger_t)3L);
	ctx->vsp=local+20;
	w=(pointer)INSTANTIATE(ctx,2,local+18); /*instantiate*/
	local[12] = w;
KEY3152:
	if (n & (1<<12)) goto KEY3153;
	local[18]= loadglobal(fqv[43]);
	local[19]= makeint((eusinteger_t)3L);
	ctx->vsp=local+20;
	w=(pointer)INSTANTIATE(ctx,2,local+18); /*instantiate*/
	local[13] = w;
KEY3153:
	if (n & (1<<13)) goto KEY3154;
	local[18]= loadglobal(fqv[43]);
	local[19]= makeint((eusinteger_t)3L);
	ctx->vsp=local+20;
	w=(pointer)INSTANTIATE(ctx,2,local+18); /*instantiate*/
	local[14] = w;
KEY3154:
	if (n & (1<<14)) goto KEY3155;
	local[18]= makeint((eusinteger_t)3L);
	local[19]= makeint((eusinteger_t)3L);
	ctx->vsp=local+20;
	w=(*ftab[5])(ctx,2,local+18,&ftab[5],fqv[24]); /*make-matrix*/
	local[15] = w;
KEY3155:
	if (n & (1<<15)) goto KEY3156;
	local[18]= makeint((eusinteger_t)3L);
	local[19]= makeint((eusinteger_t)3L);
	ctx->vsp=local+20;
	w=(*ftab[5])(ctx,2,local+18,&ftab[5],fqv[24]); /*make-matrix*/
	local[16] = w;
KEY3156:
	if (n & (1<<16)) goto KEY3157;
	local[18]= makeint((eusinteger_t)3L);
	local[19]= makeint((eusinteger_t)3L);
	ctx->vsp=local+20;
	w=(*ftab[5])(ctx,2,local+18,&ftab[5],fqv[24]); /*make-matrix*/
	local[17] = w;
KEY3157:
	if (local[6]==NIL) goto IF3158;
	local[18]= argv[0];
	local[19]= fqv[80];
	local[20]= fqv[34];
	local[21]= local[11];
	local[22]= fqv[35];
	local[23]= local[12];
	local[24]= fqv[37];
	local[25]= local[15];
	local[26]= fqv[38];
	local[27]= local[16];
	local[28]= fqv[39];
	local[29]= local[17];
	ctx->vsp=local+30;
	w=(pointer)SEND(ctx,12,local+18); /*send*/
	local[18]= w;
	goto IF3159;
IF3158:
	local[18]= NIL;
IF3159:
	local[18]= NIL;
	local[19]= makeint((eusinteger_t)0L);
	local[20]= makeint((eusinteger_t)0L);
TAG3162:
	local[21]= local[20];
	local[22]= local[1];
	ctx->vsp=local+23;
	w=(pointer)LENGTH(ctx,1,local+22); /*length*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)GREQP(ctx,2,local+21); /*>=*/
	if (w==NIL) goto IF3163;
	w = NIL;
	ctx->vsp=local+21;
	local[19]=w;
	goto BLK3161;
	goto IF3164;
IF3163:
	local[21]= NIL;
IF3164:
	local[21]= local[1];
	local[22]= local[20];
	ctx->vsp=local+23;
	w=(pointer)ELT(ctx,2,local+21); /*elt*/
	local[21]= w;
	local[22]= fqv[81];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,2,local+21); /*send*/
	local[18] = w;
	local[21]= (pointer)get_sym_func(fqv[82]);
	local[22]= local[1];
	local[23]= local[20];
	ctx->vsp=local+24;
	w=(pointer)ELT(ctx,2,local+22); /*elt*/
	local[22]= w;
	local[23]= fqv[83];
	local[24]= local[19];
	local[25]= fqv[84];
	local[26]= local[5];
	local[27]= fqv[85];
	if (local[7]==NIL) goto IF3165;
	local[28]= local[7];
	goto IF3166;
IF3165:
	local[28]= argv[0];
	local[29]= fqv[30];
	local[30]= NIL;
	ctx->vsp=local+31;
	w=(pointer)SEND(ctx,3,local+28); /*send*/
	local[28]= w;
IF3166:
	local[29]= fqv[86];
	local[30]= local[3];
	local[31]= fqv[87];
	local[32]= local[2];
	local[33]= local[0];
	ctx->vsp=local+34;
	w=(pointer)APPLY(ctx,13,local+21); /*apply*/
	local[21]= local[19];
	local[22]= local[18];
	local[23]= fqv[88];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,2,local+22); /*send*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)PLUS(ctx,2,local+21); /*+*/
	local[21]= w;
	local[22]= local[20];
	local[23]= makeint((eusinteger_t)1L);
	ctx->vsp=local+24;
	w=(pointer)PLUS(ctx,2,local+22); /*+*/
	local[22]= w;
	local[19] = local[21];
	local[20] = local[22];
	w = NIL;
	ctx->vsp=local+21;
	goto TAG3162;
	w = NIL;
	local[19]= w;
BLK3161:
	w = local[19];
	w = local[5];
	local[0]= w;
BLK3139:
	ctx->vsp=local; return(local[0]);}

/*:calc-cog-jacobian-from-link-list*/
static pointer M3169cascaded_link_calc_cog_jacobian_from_link_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3171:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[89], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3172;
	local[7]= argv[0]->c.obj.iv[9];
	local[8]= fqv[77];
	ctx->vsp=local+9;
	w=(*ftab[7])(ctx,2,local+7,&ftab[7],fqv[29]); /*send-all*/
	local[1] = w;
KEY3172:
	if (n & (1<<1)) goto KEY3173;
	local[2] = NIL;
KEY3173:
	if (n & (1<<2)) goto KEY3174;
	local[3] = T;
KEY3174:
	if (n & (1<<3)) goto KEY3175;
	local[7]= argv[0];
	local[8]= fqv[78];
	local[9]= local[2];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[4] = w;
KEY3175:
	if (n & (1<<4)) goto KEY3176;
	local[7]= local[4];
	local[8]= argv[0];
	local[9]= fqv[79];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[5])(ctx,2,local+7,&ftab[5],fqv[24]); /*make-matrix*/
	local[5] = w;
KEY3176:
	if (n & (1<<5)) goto KEY3177;
	local[6] = T;
KEY3177:
	local[7]= makeflt(1.0000000000000000208167e-03);
	local[8]= argv[0];
	local[9]= fqv[20];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	local[8]= (pointer)get_sym_func(fqv[82]);
	local[9]= argv[0];
	local[10]= fqv[90];
	local[11]= fqv[80];
	local[12]= NIL;
	local[13]= fqv[84];
	local[14]= local[5];
	local[15]= fqv[91];
	local[16]= local[1];
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)APPLY(ctx,10,local+8); /*apply*/
	local[8]= makeint((eusinteger_t)0L);
	local[9]= local[4];
WHL3179:
	local[10]= local[8];
	w = local[9];
	if ((eusinteger_t)local[10] >= (eusinteger_t)w) goto WHX3180;
	local[10]= makeint((eusinteger_t)0L);
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(*ftab[10])(ctx,1,local+11,&ftab[10],fqv[92]); /*array-dimensions*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
WHL3183:
	local[12]= local[10];
	w = local[11];
	if ((eusinteger_t)local[12] >= (eusinteger_t)w) goto WHX3184;
	local[12]= local[5];
	local[13]= local[8];
	local[14]= local[10];
	local[15]= local[5];
	local[16]= local[8];
	local[17]= local[10];
	ctx->vsp=local+18;
	w=(pointer)AREF(ctx,3,local+15); /*aref*/
	local[15]= w;
	local[16]= local[7];
	ctx->vsp=local+17;
	w=(pointer)QUOTIENT(ctx,2,local+15); /*/*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)ASET(ctx,4,local+12); /*aset*/
	local[12]= local[10];
	ctx->vsp=local+13;
	w=(pointer)ADD1(ctx,1,local+12); /*1+*/
	local[10] = w;
	goto WHL3183;
WHX3184:
	local[12]= NIL;
BLK3185:
	w = NIL;
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[8] = w;
	goto WHL3179;
WHX3180:
	local[10]= NIL;
BLK3181:
	w = NIL;
	w = local[5];
	local[0]= w;
BLK3170:
	ctx->vsp=local; return(local[0]);}

/*:cog-jacobian-balance-nspace*/
static pointer M3186cascaded_link_cog_jacobian_balance_nspace(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST3188:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[93], &argv[3], n-3, local+1, 1);
	if (n & (1<<0)) goto KEY3189;
	local[1] = makeflt(1.0000000000000000000000e+00);
KEY3189:
	if (n & (1<<1)) goto KEY3190;
	local[2] = fqv[65];
KEY3190:
	if (n & (1<<2)) goto KEY3191;
	local[3] = NIL;
KEY3191:
	if (n & (1<<3)) goto KEY3192;
	local[4] = NIL;
KEY3192:
	if (n & (1<<4)) goto KEY3193;
	local[5] = T;
KEY3193:
	local[6]= (pointer)get_sym_func(fqv[82]);
	local[7]= argv[0];
	local[8]= fqv[94];
	local[9]= (pointer)get_sym_func(fqv[82]);
	local[10]= argv[0];
	local[11]= fqv[95];
	local[12]= fqv[80];
	local[13]= local[5];
	local[14]= fqv[91];
	local[15]= argv[2];
	local[16]= fqv[86];
	local[17]= local[2];
	local[18]= local[0];
	ctx->vsp=local+19;
	w=(pointer)APPLY(ctx,10,local+9); /*apply*/
	local[9]= w;
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)APPLY(ctx,5,local+6); /*apply*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= fqv[96];
	local[9]= local[1];
	local[10]= local[2];
	local[11]= local[3];
	local[12]= fqv[97];
	local[13]= local[4];
	local[14]= fqv[80];
	local[15]= NIL;
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,9,local+7); /*send*/
	local[7]= w;
	local[8]= argv[0];
	local[9]= fqv[49];
	local[10]= fqv[98];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	if (w==NIL) goto IF3194;
	local[8]= fqv[30];
	local[9]= argv[0];
	local[10]= fqv[49];
	local[11]= fqv[98];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[11])(ctx,2,local+8,&ftab[11],fqv[99]); /*assoc*/
	local[8]= w;
	local[9]= local[7];
	local[10]= fqv[30];
	local[11]= argv[0];
	local[12]= fqv[49];
	local[13]= fqv[98];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[11])(ctx,2,local+10,&ftab[11],fqv[99]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)RPLACD2(ctx,2,local+8); /*rplacd2*/
	local[8]= w;
	goto IF3195;
IF3194:
	local[8]= NIL;
IF3195:
	w = local[7];
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)TRANSFORM(ctx,2,local+6); /*transform*/
	local[0]= w;
BLK3187:
	ctx->vsp=local; return(local[0]);}

/*:calc-vel-for-cog*/
static pointer M3196cascaded_link_calc_vel_for_cog(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[100], &argv[5], n-5, local+0, 0);
	if (n & (1<<0)) goto KEY3198;
	local[0] = NIL;
KEY3198:
	if (n & (1<<1)) goto KEY3199;
	local[1] = T;
KEY3199:
	local[2]= makeflt(1.0000000000000000208167e-03);
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[101];
	local[5]= argv[4];
	local[6]= fqv[97];
	local[7]= local[0];
	local[8]= fqv[86];
	local[9]= argv[3];
	local[10]= fqv[102];
	local[11]= T;
	local[12]= fqv[80];
	local[13]= local[1];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,11,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SCALEVEC(ctx,2,local+2); /*scale*/
	local[0]= w;
BLK3197:
	ctx->vsp=local; return(local[0]);}

/*:difference-cog-position*/
static pointer M3200cascaded_link_difference_cog_position(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[103], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY3202;
	local[0] = NIL;
KEY3202:
	if (n & (1<<1)) goto KEY3203;
	local[1] = fqv[65];
KEY3203:
	if (n & (1<<2)) goto KEY3204;
	local[2] = NIL;
KEY3204:
	if (n & (1<<3)) goto KEY3205;
	local[3] = T;
KEY3205:
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[12])(ctx,1,local+4,&ftab[12],fqv[104]); /*functionp*/
	if (w==NIL) goto IF3206;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)FUNCALL(ctx,1,local+4); /*funcall*/
	local[4]= w;
	goto IF3207;
IF3206:
	local[4]= argv[0];
	local[5]= fqv[30];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
IF3207:
	if (local[2]==NIL) goto IF3208;
	local[5]= argv[0];
	local[6]= fqv[46];
	local[7]= fqv[105];
	local[8]= argv[0];
	local[9]= fqv[49];
	local[10]= fqv[105];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	local[9]= argv[2];
	local[10]= fqv[106];
	local[11]= fqv[107];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,3,local+9); /*list*/
	local[9]= w;
	local[10]= local[4];
	local[11]= makeint((eusinteger_t)0L);
	ctx->vsp=local+12;
	w=(pointer)ELT(ctx,2,local+10); /*elt*/
	local[10]= w;
	local[11]= local[4];
	local[12]= makeint((eusinteger_t)1L);
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	local[12]= argv[2];
	local[13]= makeint((eusinteger_t)2L);
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)MKFLTVEC(ctx,3,local+10); /*float-vector*/
	local[10]= w;
	local[11]= fqv[108];
	local[12]= makeint((eusinteger_t)100L);
	local[13]= fqv[106];
	local[14]= fqv[109];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,5,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,2,local+9); /*list*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)APPEND(ctx,2,local+8); /*append*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto IF3209;
IF3208:
	local[5]= NIL;
IF3209:
	local[5]= argv[2];
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)VMINUS(ctx,2,local+5); /*v-*/
	local[5]= w;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[3])(ctx,2,local+5,&ftab[3],fqv[6]); /*calc-dif-with-axis*/
	local[0]= w;
BLK3201:
	ctx->vsp=local; return(local[0]);}

/*:cog-convergence-check*/
static pointer M3210cascaded_link_cog_convergence_check(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[110], &argv[4], n-4, local+0, 0);
	if (n & (1<<0)) goto KEY3212;
	local[0] = NIL;
KEY3212:
	if (n & (1<<1)) goto KEY3213;
	local[1] = fqv[65];
KEY3213:
	if (n & (1<<2)) goto KEY3214;
	local[2] = T;
KEY3214:
	local[3]= argv[0];
	local[4]= fqv[101];
	local[5]= argv[3];
	local[6]= fqv[97];
	local[7]= local[0];
	local[8]= fqv[86];
	local[9]= local[1];
	local[10]= fqv[80];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,9,local+3); /*send*/
	local[3]= w;
	w = argv[2];
	if (!isnum(w)) goto CON3216;
	local[4]= argv[2];
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)VNORM(ctx,1,local+5); /*norm*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)GREATERP(ctx,2,local+4); /*>*/
	local[4]= w;
	goto CON3215;
CON3216:
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(*ftab[12])(ctx,1,local+4,&ftab[12],fqv[104]); /*functionp*/
	if (w==NIL) goto CON3217;
	local[4]= argv[2];
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)FUNCALL(ctx,2,local+4); /*funcall*/
	local[4]= w;
	goto CON3215;
CON3217:
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)VECTORP(ctx,1,local+4); /*vectorp*/
	if (w==NIL) goto CON3218;
	local[4]= loadglobal(fqv[43]);
	local[5]= (pointer)get_sym_func(fqv[111]);
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)MAP(ctx,3,local+4); /*map*/
	local[4]= w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)VLESSP(ctx,2,local+4); /*v<*/
	local[4]= w;
	goto CON3215;
CON3218:
	local[4]= NIL;
CON3215:
	w = local[4];
	local[0]= w;
BLK3211:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3137(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[46];
	local[2]= fqv[47];
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)3L);
WHL3220:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX3221;
	local[2]= argv[0];
	local[3]= fqv[49];
	local[4]= fqv[51];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= local[0];
	local[4]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+5;
	w=(pointer)SETELT(ctx,3,local+2); /*setelt*/
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL3220;
WHX3221:
	local[2]= NIL;
BLK3222:
	w = NIL;
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)3L);
WHL3224:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX3225;
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)3L);
WHL3228:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX3229;
	local[4]= argv[0];
	local[5]= fqv[49];
	local[6]= fqv[50];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= local[2];
	local[6]= local[0];
	local[7]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+8;
	w=(pointer)ASET(ctx,4,local+4); /*aset*/
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL3228;
WHX3229:
	local[4]= NIL;
BLK3230:
	w = NIL;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL3224;
WHX3225:
	local[2]= NIL;
BLK3226:
	w = NIL;
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:calc-spacial-velocity-jacobian*/
static pointer M3231joint_calc_spacial_velocity_jacobian(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3233:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= fqv[112];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[1]); /*warn*/
	local[0]= w;
BLK3232:
	ctx->vsp=local; return(local[0]);}

/*:calc-angular-velocity-jacobian*/
static pointer M3234joint_calc_angular_velocity_jacobian(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3236:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= fqv[113];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[1]); /*warn*/
	local[0]= w;
BLK3235:
	ctx->vsp=local; return(local[0]);}

/*:calc-spacial-acceleration-jacobian*/
static pointer M3237joint_calc_spacial_acceleration_jacobian(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3239:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= fqv[114];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[1]); /*warn*/
	local[0]= w;
BLK3238:
	ctx->vsp=local; return(local[0]);}

/*:calc-angular-acceleration-jacobian*/
static pointer M3240joint_calc_angular_acceleration_jacobian(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3242:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= fqv[115];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[1]); /*warn*/
	local[0]= w;
BLK3241:
	ctx->vsp=local; return(local[0]);}

/*:calc-spacial-velocity-jacobian*/
static pointer M3243rotational_joint_calc_spacial_velocity_jacobian(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= makeflt(1.0000000000000000208167e-03);
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[5];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,3,local+0); /*scale*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= argv[4];
	ctx->vsp=local+3;
	w=(pointer)VCROSSPRODUCT(ctx,3,local+0); /*v**/
	local[0]= w;
BLK3244:
	ctx->vsp=local; return(local[0]);}

/*:calc-angular-velocity-jacobian*/
static pointer M3245rotational_joint_calc_angular_velocity_jacobian(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)3L);
WHL3248:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX3249;
	local[2]= argv[3];
	local[3]= local[0];
	local[4]= argv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SETELT(ctx,3,local+2); /*setelt*/
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL3248;
WHX3249:
	local[2]= NIL;
BLK3250:
	w = NIL;
	w = argv[3];
	local[0]= w;
BLK3246:
	ctx->vsp=local; return(local[0]);}

/*:calc-spacial-acceleration-jacobian*/
static pointer M3251rotational_joint_calc_spacial_acceleration_jacobian(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[116];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= argv[4];
	ctx->vsp=local+3;
	w=(pointer)VCROSSPRODUCT(ctx,3,local+0); /*v**/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[3];
	local[3]= argv[5];
	ctx->vsp=local+4;
	w=(pointer)VCROSSPRODUCT(ctx,3,local+1); /*v**/
	local[1]= w;
	local[2]= argv[5];
	ctx->vsp=local+3;
	w=(pointer)VPLUS(ctx,3,local+0); /*v+*/
	local[0]= w;
BLK3252:
	ctx->vsp=local; return(local[0]);}

/*:calc-angular-acceleration-jacobian*/
static pointer M3253rotational_joint_calc_angular_acceleration_jacobian(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[116];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)VCROSSPRODUCT(ctx,3,local+0); /*v**/
	local[0]= w;
BLK3254:
	ctx->vsp=local; return(local[0]);}

/*:calc-spacial-velocity-jacobian*/
static pointer M3255linear_joint_calc_spacial_velocity_jacobian(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)3L);
WHL3258:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX3259;
	local[2]= argv[4];
	local[3]= local[0];
	local[4]= argv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SETELT(ctx,3,local+2); /*setelt*/
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL3258;
WHX3259:
	local[2]= NIL;
BLK3260:
	w = NIL;
	w = argv[4];
	local[0]= w;
BLK3256:
	ctx->vsp=local; return(local[0]);}

/*:calc-angular-velocity-jacobian*/
static pointer M3261linear_joint_calc_angular_velocity_jacobian(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)3L);
WHL3264:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX3265;
	local[2]= argv[3];
	local[3]= local[0];
	local[4]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+5;
	w=(pointer)SETELT(ctx,3,local+2); /*setelt*/
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL3264;
WHX3265:
	local[2]= NIL;
BLK3266:
	w = NIL;
	w = argv[3];
	local[0]= w;
BLK3262:
	ctx->vsp=local; return(local[0]);}

/*:calc-spacial-acceleration-jacobian*/
static pointer M3267linear_joint_calc_spacial_acceleration_jacobian(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[116];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= argv[5];
	ctx->vsp=local+3;
	w=(pointer)VCROSSPRODUCT(ctx,3,local+0); /*v**/
	local[0]= w;
BLK3268:
	ctx->vsp=local; return(local[0]);}

/*:calc-angular-acceleration-jacobian*/
static pointer M3269linear_joint_calc_angular_acceleration_jacobian(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)3L);
WHL3272:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX3273;
	local[2]= argv[3];
	local[3]= local[0];
	local[4]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+5;
	w=(pointer)SETELT(ctx,3,local+2); /*setelt*/
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL3272;
WHX3273:
	local[2]= NIL;
BLK3274:
	w = NIL;
	w = argv[3];
	local[0]= w;
BLK3270:
	ctx->vsp=local; return(local[0]);}

/*:reset-dynamics*/
static pointer M3275bodyset_link_reset_dynamics(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[46];
	local[2]= fqv[47];
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[46];
	local[2]= fqv[51];
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[46];
	local[2]= fqv[50];
	local[3]= makeint((eusinteger_t)3L);
	local[4]= makeint((eusinteger_t)3L);
	ctx->vsp=local+5;
	w=(*ftab[5])(ctx,2,local+3,&ftab[5],fqv[24]); /*make-matrix*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	argv[0]->c.obj.iv[17] = w;
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	argv[0]->c.obj.iv[18] = w;
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	argv[0]->c.obj.iv[19] = w;
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	argv[0]->c.obj.iv[20] = w;
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	argv[0]->c.obj.iv[24] = w;
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	argv[0]->c.obj.iv[23] = w;
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	argv[0]->c.obj.iv[22] = w;
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	argv[0]->c.obj.iv[21] = w;
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	argv[0]->c.obj.iv[25] = w;
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	argv[0]->c.obj.iv[26] = w;
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	argv[0]->c.obj.iv[27] = w;
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	argv[0]->c.obj.iv[28] = w;
	w = argv[0]->c.obj.iv[28];
	local[0]= w;
BLK3276:
	ctx->vsp=local; return(local[0]);}

/*:angular-velocity*/
static pointer M3277bodyset_link_angular_velocity(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3280;}
	local[0]= NIL;
ENT3280:
ENT3279:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3281;
	argv[0]->c.obj.iv[17] = local[0];
	local[1]= argv[0]->c.obj.iv[17];
	goto IF3282;
IF3281:
	local[1]= argv[0]->c.obj.iv[17];
IF3282:
	w = local[1];
	local[0]= w;
BLK3278:
	ctx->vsp=local; return(local[0]);}

/*:angular-acceleration*/
static pointer M3283bodyset_link_angular_acceleration(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3286;}
	local[0]= NIL;
ENT3286:
ENT3285:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3287;
	argv[0]->c.obj.iv[18] = local[0];
	local[1]= argv[0]->c.obj.iv[18];
	goto IF3288;
IF3287:
	local[1]= argv[0]->c.obj.iv[18];
IF3288:
	w = local[1];
	local[0]= w;
BLK3284:
	ctx->vsp=local; return(local[0]);}

/*:spacial-velocity*/
static pointer M3289bodyset_link_spacial_velocity(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3292;}
	local[0]= NIL;
ENT3292:
ENT3291:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3293;
	argv[0]->c.obj.iv[19] = local[0];
	local[1]= argv[0]->c.obj.iv[19];
	goto IF3294;
IF3293:
	local[1]= argv[0]->c.obj.iv[19];
IF3294:
	w = local[1];
	local[0]= w;
BLK3290:
	ctx->vsp=local; return(local[0]);}

/*:spacial-acceleration*/
static pointer M3295bodyset_link_spacial_acceleration(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3298;}
	local[0]= NIL;
ENT3298:
ENT3297:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3299;
	argv[0]->c.obj.iv[20] = local[0];
	local[1]= argv[0]->c.obj.iv[20];
	goto IF3300;
IF3299:
	local[1]= argv[0]->c.obj.iv[20];
IF3300:
	w = local[1];
	local[0]= w;
BLK3296:
	ctx->vsp=local; return(local[0]);}

/*:force*/
static pointer M3301bodyset_link_force(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[25];
	local[0]= w;
BLK3302:
	ctx->vsp=local; return(local[0]);}

/*:moment*/
static pointer M3303bodyset_link_moment(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[26];
	local[0]= w;
BLK3304:
	ctx->vsp=local; return(local[0]);}

/*:ext-force*/
static pointer M3305bodyset_link_ext_force(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3308;}
	local[0]= NIL;
ENT3308:
ENT3307:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3309;
	argv[0]->c.obj.iv[27] = local[0];
	local[1]= argv[0]->c.obj.iv[27];
	goto IF3310;
IF3309:
	local[1]= argv[0]->c.obj.iv[27];
IF3310:
	w = local[1];
	local[0]= w;
BLK3306:
	ctx->vsp=local; return(local[0]);}

/*:ext-moment*/
static pointer M3311bodyset_link_ext_moment(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3314;}
	local[0]= NIL;
ENT3314:
ENT3313:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3315;
	argv[0]->c.obj.iv[28] = local[0];
	local[1]= argv[0]->c.obj.iv[28];
	goto IF3316;
IF3315:
	local[1]= argv[0]->c.obj.iv[28];
IF3316:
	w = local[1];
	local[0]= w;
BLK3312:
	ctx->vsp=local; return(local[0]);}

/*:forward-all-kinematics*/
static pointer M3317bodyset_link_forward_all_kinematics(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[118], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY3319;
	local[0] = NIL;
KEY3319:
	if (n & (1<<1)) goto KEY3320;
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[1] = w;
KEY3320:
	if (local[0]==NIL) goto IF3321;
	local[2]= T;
	local[3]= fqv[119];
	local[4]= argv[0];
	local[5]= fqv[58];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	goto IF3322;
IF3321:
	local[2]= NIL;
IF3322:
	if (argv[0]->c.obj.iv[10]==NIL) goto IF3323;
	local[2]= argv[0];
	local[3]= fqv[120];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= loadglobal(fqv[121]);
	ctx->vsp=local+4;
	w=(pointer)DERIVEDP(ctx,2,local+2); /*derivedp*/
	if (w==NIL) goto IF3323;
	local[2]= *(ovafptr(argv[0]->c.obj.iv[9],fqv[60]));
	local[3]= local[2];
	if (fqv[61]!=local[3]) goto IF3326;
	local[3]= fqv[122];
	goto IF3327;
IF3326:
	local[3]= local[2];
	if (fqv[63]!=local[3]) goto IF3328;
	local[3]= fqv[123];
	goto IF3329;
IF3328:
	local[3]= local[2];
	if (fqv[65]!=local[3]) goto IF3330;
	local[3]= fqv[124];
	goto IF3331;
IF3330:
	local[3]= local[2];
	if (fqv[125]!=local[3]) goto IF3332;
	local[3]= fqv[126];
	goto IF3333;
IF3332:
	local[3]= local[2];
	if (fqv[127]!=local[3]) goto IF3334;
	local[3]= fqv[128];
	goto IF3335;
IF3334:
	local[3]= local[2];
	if (fqv[129]!=local[3]) goto IF3336;
	local[3]= fqv[130];
	goto IF3337;
IF3336:
	local[3]= local[2];
	if (fqv[62]!=local[3]) goto IF3338;
	local[3]= fqv[131];
	goto IF3339;
IF3338:
	local[3]= local[2];
	if (fqv[64]!=local[3]) goto IF3340;
	local[3]= fqv[132];
	goto IF3341;
IF3340:
	local[3]= local[2];
	if (fqv[66]!=local[3]) goto IF3342;
	local[3]= fqv[133];
	goto IF3343;
IF3342:
	if (T==NIL) goto IF3344;
	local[3]= *(ovafptr(argv[0]->c.obj.iv[9],fqv[60]));
	goto IF3345;
IF3344:
	local[3]= NIL;
IF3345:
IF3343:
IF3341:
IF3339:
IF3337:
IF3335:
IF3333:
IF3331:
IF3329:
IF3327:
	w = local[3];
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[10];
	local[4]= fqv[68];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= fqv[69];
	local[5]= *(ovafptr(argv[0]->c.obj.iv[9],fqv[70]));
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= fqv[2];
	local[5]= local[2];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[49];
	local[6]= fqv[134];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[3]); /*normalize-vector*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[9];
	local[5]= fqv[135];
	local[6]= local[3];
	local[7]= local[1];
	local[8]= argv[0];
	local[9]= fqv[49];
	local[10]= fqv[136];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[9];
	local[6]= fqv[137];
	local[7]= local[3];
	local[8]= argv[0];
	local[9]= fqv[49];
	local[10]= fqv[134];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[10];
	local[7]= fqv[116];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[9];
	local[8]= fqv[138];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= local[5];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,3,local+7); /*scale*/
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[17];
	ctx->vsp=local+9;
	w=(pointer)VPLUS(ctx,3,local+6); /*v+*/
	argv[0]->c.obj.iv[17] = w;
	local[6]= argv[0]->c.obj.iv[10];
	local[7]= fqv[117];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[9];
	local[8]= fqv[138];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= local[4];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,3,local+7); /*scale*/
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[19];
	ctx->vsp=local+9;
	w=(pointer)VPLUS(ctx,3,local+6); /*v+*/
	argv[0]->c.obj.iv[19] = w;
	local[6]= argv[0]->c.obj.iv[9];
	local[7]= fqv[139];
	local[8]= local[4];
	local[9]= local[5];
	local[10]= local[1];
	local[11]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,6,local+6); /*send*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[10];
	local[8]= fqv[140];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[9];
	local[9]= fqv[138];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= local[6];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(pointer)SCALEVEC(ctx,3,local+8); /*scale*/
	local[8]= w;
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)VPLUS(ctx,3,local+7); /*v+*/
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[9];
	local[9]= fqv[141];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= local[4];
	local[10]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+11;
	w=(pointer)SCALEVEC(ctx,3,local+8); /*scale*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+10;
	w=(pointer)VPLUS(ctx,3,local+7); /*v+*/
	argv[0]->c.obj.iv[20] = w;
	w = argv[0]->c.obj.iv[20];
	local[6]= argv[0]->c.obj.iv[9];
	local[7]= fqv[142];
	local[8]= local[5];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[10];
	local[8]= fqv[143];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[9];
	local[9]= fqv[138];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= local[6];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(pointer)SCALEVEC(ctx,3,local+8); /*scale*/
	local[8]= w;
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)VPLUS(ctx,3,local+7); /*v+*/
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[9];
	local[9]= fqv[141];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= local[5];
	local[10]= argv[0]->c.obj.iv[18];
	ctx->vsp=local+11;
	w=(pointer)SCALEVEC(ctx,3,local+8); /*scale*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[18];
	ctx->vsp=local+10;
	w=(pointer)VPLUS(ctx,3,local+7); /*v+*/
	argv[0]->c.obj.iv[18] = w;
	w = argv[0]->c.obj.iv[18];
	local[2]= w;
	goto IF3324;
IF3323:
	local[2]= NIL;
IF3324:
	local[2]= argv[0]->c.obj.iv[11];
	local[3]= fqv[144];
	local[4]= fqv[45];
	local[5]= local[0];
	local[6]= fqv[34];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[7])(ctx,6,local+2,&ftab[7],fqv[29]); /*send-all*/
	local[0]= w;
BLK3318:
	ctx->vsp=local; return(local[0]);}

/*:inverse-dynamics*/
static pointer M3346bodyset_link_inverse_dynamics(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[145], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY3348;
	local[0] = NIL;
KEY3348:
	if (n & (1<<1)) goto KEY3349;
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)MKFLTVEC(ctx,3,local+8); /*float-vector*/
	local[1] = w;
KEY3349:
	if (n & (1<<2)) goto KEY3350;
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)MKFLTVEC(ctx,3,local+8); /*float-vector*/
	local[2] = w;
KEY3350:
	if (n & (1<<3)) goto KEY3351;
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)MKFLTVEC(ctx,3,local+8); /*float-vector*/
	local[3] = w;
KEY3351:
	if (n & (1<<4)) goto KEY3352;
	local[8]= makeint((eusinteger_t)3L);
	local[9]= makeint((eusinteger_t)3L);
	ctx->vsp=local+10;
	w=(*ftab[5])(ctx,2,local+8,&ftab[5],fqv[24]); /*make-matrix*/
	local[4] = w;
KEY3352:
	if (n & (1<<5)) goto KEY3353;
	local[8]= makeint((eusinteger_t)3L);
	local[9]= makeint((eusinteger_t)3L);
	ctx->vsp=local+10;
	w=(*ftab[5])(ctx,2,local+8,&ftab[5],fqv[24]); /*make-matrix*/
	local[5] = w;
KEY3353:
	if (n & (1<<6)) goto KEY3354;
	local[8]= makeint((eusinteger_t)3L);
	local[9]= makeint((eusinteger_t)3L);
	ctx->vsp=local+10;
	w=(*ftab[5])(ctx,2,local+8,&ftab[5],fqv[24]); /*make-matrix*/
	local[6] = w;
KEY3354:
	if (n & (1<<7)) goto KEY3355;
	local[8]= makeint((eusinteger_t)3L);
	local[9]= makeint((eusinteger_t)3L);
	ctx->vsp=local+10;
	w=(*ftab[5])(ctx,2,local+8,&ftab[5],fqv[24]); /*make-matrix*/
	local[7] = w;
KEY3355:
	if (local[0]==NIL) goto IF3356;
	local[8]= T;
	local[9]= fqv[146];
	local[10]= argv[0];
	local[11]= fqv[58];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,3,local+8); /*format*/
	local[8]= w;
	goto IF3357;
IF3356:
	local[8]= NIL;
IF3357:
	local[8]= makeflt(1.0000000000000000208167e-03);
	local[9]= argv[0];
	local[10]= fqv[20];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	local[9]= makeflt(-1.0000000000000000000000e+00);
	local[10]= local[8];
	local[11]= makeflt(1.0000000000000000208167e-03);
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,3,local+9); /***/
	local[9]= w;
	local[10]= loadglobal(fqv[147]);
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)SCALEVEC(ctx,3,local+9); /*scale*/
	local[9]= w;
	local[10]= makeflt(1.0000000000000000208167e-03);
	local[11]= argv[0];
	local[12]= fqv[30];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)SCALEVEC(ctx,3,local+10); /*scale*/
	local[10]= w;
	local[11]= argv[0];
	local[12]= fqv[25];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	local[12]= makeflt(9.9999999999999985548644e-10);
	local[13]= argv[0];
	local[14]= fqv[26];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	local[13]= w;
	local[14]= local[4];
	ctx->vsp=local+15;
	w=(*ftab[2])(ctx,3,local+12,&ftab[2],fqv[4]); /*scale-matrix*/
	local[12]= w;
	local[13]= local[5];
	ctx->vsp=local+14;
	w=(pointer)MATTIMES(ctx,3,local+11); /*m**/
	local[11]= w;
	local[12]= argv[0];
	local[13]= fqv[25];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[12]= w;
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(pointer)TRANSPOSE(ctx,2,local+12); /*transpose*/
	local[12]= w;
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)MATTIMES(ctx,3,local+11); /*m**/
	local[11]= w;
	local[12]= local[10];
	local[13]= local[5];
	ctx->vsp=local+14;
	w=(*ftab[8])(ctx,2,local+12,&ftab[8],fqv[72]); /*outer-product-matrix*/
	local[12]= w;
	local[13]= local[11];
	local[14]= local[8];
	local[15]= local[12];
	local[16]= local[12];
	local[17]= local[6];
	ctx->vsp=local+18;
	w=(pointer)TRANSPOSE(ctx,2,local+16); /*transpose*/
	local[16]= w;
	local[17]= local[7];
	ctx->vsp=local+18;
	w=(pointer)MATTIMES(ctx,3,local+15); /*m**/
	local[15]= w;
	local[16]= local[5];
	ctx->vsp=local+17;
	w=(*ftab[2])(ctx,3,local+14,&ftab[2],fqv[4]); /*scale-matrix*/
	local[14]= w;
	local[15]= local[5];
	ctx->vsp=local+16;
	w=(*ftab[6])(ctx,3,local+13,&ftab[6],fqv[27]); /*m+*/
	local[13]= w;
	local[14]= local[8];
	local[15]= argv[0]->c.obj.iv[19];
	local[16]= argv[0]->c.obj.iv[17];
	local[17]= local[10];
	local[18]= local[3];
	ctx->vsp=local+19;
	w=(pointer)VCROSSPRODUCT(ctx,3,local+16); /*v**/
	local[16]= w;
	local[17]= local[3];
	ctx->vsp=local+18;
	w=(pointer)VPLUS(ctx,3,local+15); /*v+*/
	local[15]= w;
	local[16]= argv[0]->c.obj.iv[23];
	ctx->vsp=local+17;
	w=(pointer)SCALEVEC(ctx,3,local+14); /*scale*/
	argv[0]->c.obj.iv[23] = w;
	local[14]= local[8];
	local[15]= local[10];
	local[16]= argv[0]->c.obj.iv[19];
	local[17]= local[3];
	ctx->vsp=local+18;
	w=(pointer)VCROSSPRODUCT(ctx,3,local+15); /*v**/
	local[15]= w;
	local[16]= argv[0]->c.obj.iv[24];
	ctx->vsp=local+17;
	w=(pointer)SCALEVEC(ctx,3,local+14); /*scale*/
	local[14]= w;
	local[15]= local[13];
	local[16]= argv[0]->c.obj.iv[17];
	local[17]= local[3];
	ctx->vsp=local+18;
	w=(pointer)TRANSFORM(ctx,3,local+15); /*transform*/
	local[15]= w;
	local[16]= argv[0]->c.obj.iv[24];
	ctx->vsp=local+17;
	w=(pointer)VPLUS(ctx,3,local+14); /*v+*/
	argv[0]->c.obj.iv[24] = w;
	local[14]= local[8];
	local[15]= argv[0]->c.obj.iv[20];
	local[16]= argv[0]->c.obj.iv[18];
	local[17]= local[10];
	local[18]= local[3];
	ctx->vsp=local+19;
	w=(pointer)VCROSSPRODUCT(ctx,3,local+16); /*v**/
	local[16]= w;
	local[17]= argv[0]->c.obj.iv[25];
	ctx->vsp=local+18;
	w=(pointer)VPLUS(ctx,3,local+15); /*v+*/
	local[15]= w;
	local[16]= argv[0]->c.obj.iv[25];
	ctx->vsp=local+17;
	w=(pointer)SCALEVEC(ctx,3,local+14); /*scale*/
	local[14]= w;
	local[15]= argv[0]->c.obj.iv[17];
	local[16]= argv[0]->c.obj.iv[23];
	local[17]= local[3];
	ctx->vsp=local+18;
	w=(pointer)VCROSSPRODUCT(ctx,3,local+15); /*v**/
	local[15]= w;
	local[16]= argv[0]->c.obj.iv[25];
	ctx->vsp=local+17;
	w=(pointer)VPLUS(ctx,3,local+14); /*v+*/
	argv[0]->c.obj.iv[25] = w;
	local[14]= local[8];
	local[15]= local[10];
	local[16]= argv[0]->c.obj.iv[20];
	local[17]= local[3];
	ctx->vsp=local+18;
	w=(pointer)VCROSSPRODUCT(ctx,3,local+15); /*v**/
	local[15]= w;
	local[16]= argv[0]->c.obj.iv[26];
	ctx->vsp=local+17;
	w=(pointer)SCALEVEC(ctx,3,local+14); /*scale*/
	local[14]= w;
	local[15]= local[13];
	local[16]= argv[0]->c.obj.iv[18];
	local[17]= local[3];
	ctx->vsp=local+18;
	w=(pointer)TRANSFORM(ctx,3,local+15); /*transform*/
	local[15]= w;
	local[16]= argv[0]->c.obj.iv[26];
	ctx->vsp=local+17;
	w=(pointer)VPLUS(ctx,3,local+14); /*v+*/
	local[14]= w;
	local[15]= argv[0]->c.obj.iv[19];
	local[16]= argv[0]->c.obj.iv[23];
	local[17]= local[3];
	ctx->vsp=local+18;
	w=(pointer)VCROSSPRODUCT(ctx,3,local+15); /*v**/
	local[15]= w;
	local[16]= argv[0]->c.obj.iv[26];
	ctx->vsp=local+17;
	w=(pointer)VPLUS(ctx,3,local+14); /*v+*/
	local[14]= w;
	local[15]= argv[0]->c.obj.iv[17];
	local[16]= argv[0]->c.obj.iv[24];
	local[17]= local[3];
	ctx->vsp=local+18;
	w=(pointer)VCROSSPRODUCT(ctx,3,local+15); /*v**/
	local[15]= w;
	local[16]= argv[0]->c.obj.iv[26];
	ctx->vsp=local+17;
	w=(pointer)VPLUS(ctx,3,local+14); /*v+*/
	argv[0]->c.obj.iv[26] = w;
	local[14]= argv[0]->c.obj.iv[25];
	local[15]= local[9];
	local[16]= argv[0]->c.obj.iv[27];
	local[17]= local[3];
	ctx->vsp=local+18;
	w=(pointer)VPLUS(ctx,3,local+15); /*v+*/
	local[15]= w;
	local[16]= argv[0]->c.obj.iv[25];
	ctx->vsp=local+17;
	w=(pointer)VMINUS(ctx,3,local+14); /*v-*/
	argv[0]->c.obj.iv[25] = w;
	local[14]= argv[0]->c.obj.iv[26];
	local[15]= local[10];
	local[16]= local[9];
	local[17]= local[3];
	ctx->vsp=local+18;
	w=(pointer)VCROSSPRODUCT(ctx,3,local+15); /*v**/
	local[15]= w;
	local[16]= argv[0]->c.obj.iv[28];
	local[17]= local[1];
	ctx->vsp=local+18;
	w=(pointer)VPLUS(ctx,3,local+15); /*v+*/
	local[15]= w;
	local[16]= argv[0]->c.obj.iv[26];
	ctx->vsp=local+17;
	w=(pointer)VMINUS(ctx,3,local+14); /*v-*/
	argv[0]->c.obj.iv[26] = w;
	w = argv[0]->c.obj.iv[26];
	local[8]= NIL;
	local[9]= argv[0]->c.obj.iv[11];
WHL3359:
	if (local[9]==NIL) goto WHX3360;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= local[8];
	local[11]= fqv[148];
	local[12]= fqv[45];
	local[13]= local[0];
	local[14]= fqv[34];
	local[15]= local[1];
	local[16]= fqv[35];
	local[17]= local[2];
	local[18]= fqv[149];
	local[19]= local[3];
	local[20]= fqv[37];
	local[21]= local[4];
	local[22]= fqv[38];
	local[23]= local[5];
	local[24]= fqv[39];
	local[25]= local[6];
	local[26]= fqv[40];
	local[27]= local[7];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,18,local+10); /*send*/
	local[10]= argv[0]->c.obj.iv[25];
	local[11]= local[8];
	local[12]= fqv[150];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	local[12]= argv[0]->c.obj.iv[25];
	ctx->vsp=local+13;
	w=(pointer)VPLUS(ctx,3,local+10); /*v+*/
	argv[0]->c.obj.iv[25] = w;
	local[10]= argv[0]->c.obj.iv[26];
	local[11]= local[8];
	local[12]= fqv[151];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	local[12]= argv[0]->c.obj.iv[26];
	ctx->vsp=local+13;
	w=(pointer)VPLUS(ctx,3,local+10); /*v+*/
	argv[0]->c.obj.iv[26] = w;
	goto WHL3359;
WHX3360:
	local[10]= NIL;
BLK3361:
	w = NIL;
	if (argv[0]->c.obj.iv[9]==NIL) goto IF3363;
	if (argv[0]->c.obj.iv[10]==NIL) goto IF3363;
	local[8]= argv[0];
	local[9]= fqv[120];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= loadglobal(fqv[121]);
	ctx->vsp=local+10;
	w=(pointer)DERIVEDP(ctx,2,local+8); /*derivedp*/
	if (w==NIL) goto IF3363;
	local[8]= argv[0]->c.obj.iv[9];
	local[9]= fqv[152];
	local[10]= argv[0];
	local[11]= fqv[49];
	local[12]= fqv[136];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	local[11]= argv[0]->c.obj.iv[25];
	ctx->vsp=local+12;
	w=(pointer)VINNERPRODUCT(ctx,2,local+10); /*v.*/
	local[10]= w;
	local[11]= argv[0];
	local[12]= fqv[49];
	local[13]= fqv[134];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[11]= w;
	local[12]= argv[0]->c.obj.iv[26];
	ctx->vsp=local+13;
	w=(pointer)VINNERPRODUCT(ctx,2,local+11); /*v.*/
	{ double x,y;
		y=fltval(w); x=fltval(local[10]);
		local[10]=(makeflt(x + y));}
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	goto IF3364;
IF3363:
	local[8]= NIL;
IF3364:
	w = local[8];
	local[0]= w;
BLK3347:
	ctx->vsp=local; return(local[0]);}

/*:max-torque-vector*/
static pointer M3365cascaded_link_max_torque_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[43]);
	local[1]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,1,local+1,&ftab[13],fqv[153]); /*calc-target-joint-dimension*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,2,local+0); /*instantiate*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)0L);
	local[2]= NIL;
	local[3]= argv[0]->c.obj.iv[9];
WHL3368:
	if (local[3]==NIL) goto WHX3369;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= makeint((eusinteger_t)0L);
	local[5]= local[2];
	local[6]= fqv[88];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
WHL3373:
	local[6]= local[4];
	w = local[5];
	if ((eusinteger_t)local[6] >= (eusinteger_t)w) goto WHX3374;
	local[6]= local[0];
	local[7]= local[1];
	local[8]= local[2];
	local[9]= fqv[88];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= local[8];
	if (fqv[154]!=local[9]) goto IF3377;
	local[9]= local[2];
	local[10]= fqv[155];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	goto IF3378;
IF3377:
	if (T==NIL) goto IF3379;
	local[9]= local[2];
	local[10]= fqv[155];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	goto IF3380;
IF3379:
	local[9]= NIL;
IF3380:
IF3378:
	w = local[9];
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SETELT(ctx,3,local+6); /*setelt*/
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[1] = w;
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[4] = w;
	goto WHL3373;
WHX3374:
	local[6]= NIL;
BLK3375:
	w = NIL;
	goto WHL3368;
WHX3369:
	local[4]= NIL;
BLK3370:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK3366:
	ctx->vsp=local; return(local[0]);}

/*:torque-ratio-vector*/
static pointer M3381cascaded_link_torque_ratio_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3383:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[156], &argv[2], n-2, local+1, 0);
	if (n & (1<<0)) goto KEY3384;
	local[2]= (pointer)get_sym_func(fqv[82]);
	local[3]= argv[0];
	local[4]= fqv[157];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,4,local+2); /*apply*/
	local[1] = w;
KEY3384:
	local[2]= argv[0];
	local[3]= fqv[158];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= loadglobal(fqv[43]);
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,2,local+3); /*instantiate*/
	local[3]= w;
	local[4]= makeint((eusinteger_t)0L);
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
WHL3386:
	local[6]= local[4];
	w = local[5];
	if ((eusinteger_t)local[6] >= (eusinteger_t)w) goto WHX3387;
	local[6]= local[3];
	local[7]= local[4];
	local[8]= local[1];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	local[9]= local[2];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SETELT(ctx,3,local+6); /*setelt*/
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[4] = w;
	goto WHL3386;
WHX3387:
	local[6]= NIL;
BLK3388:
	w = NIL;
	w = local[3];
	local[0]= w;
BLK3382:
	ctx->vsp=local; return(local[0]);}

/*:calc-torque-buffer-args*/
static pointer M3389cascaded_link_calc_torque_buffer_args(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[34];
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	local[1]= w;
	local[2]= fqv[35];
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[3]= w;
	local[4]= fqv[149];
	local[5]= makeint((eusinteger_t)0L);
	local[6]= makeint((eusinteger_t)0L);
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[5]= w;
	local[6]= fqv[37];
	local[7]= makeint((eusinteger_t)3L);
	local[8]= makeint((eusinteger_t)3L);
	ctx->vsp=local+9;
	w=(*ftab[5])(ctx,2,local+7,&ftab[5],fqv[24]); /*make-matrix*/
	local[7]= w;
	local[8]= fqv[38];
	local[9]= makeint((eusinteger_t)3L);
	local[10]= makeint((eusinteger_t)3L);
	ctx->vsp=local+11;
	w=(*ftab[5])(ctx,2,local+9,&ftab[5],fqv[24]); /*make-matrix*/
	local[9]= w;
	local[10]= fqv[39];
	local[11]= makeint((eusinteger_t)3L);
	local[12]= makeint((eusinteger_t)3L);
	ctx->vsp=local+13;
	w=(*ftab[5])(ctx,2,local+11,&ftab[5],fqv[24]); /*make-matrix*/
	local[11]= w;
	local[12]= fqv[40];
	local[13]= makeint((eusinteger_t)3L);
	local[14]= makeint((eusinteger_t)3L);
	ctx->vsp=local+15;
	w=(*ftab[5])(ctx,2,local+13,&ftab[5],fqv[24]); /*make-matrix*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,14,local+0); /*list*/
	local[0]= w;
BLK3390:
	ctx->vsp=local; return(local[0]);}

/*:calc-torque*/
static pointer M3391cascaded_link_calc_torque(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[159], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY3393;
	local[0] = NIL;
KEY3393:
	if (n & (1<<1)) goto KEY3394;
	local[1] = T;
KEY3394:
	if (n & (1<<2)) goto KEY3395;
	local[2] = makeflt(4.9999999999999975019982e-03);
KEY3395:
	if (n & (1<<3)) goto KEY3396;
	local[9]= argv[0];
	local[10]= fqv[160];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[3] = w;
KEY3396:
	if (n & (1<<4)) goto KEY3397;
	local[9]= argv[0];
	local[10]= fqv[74];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= fqv[68];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[4] = w;
KEY3397:
	if (n & (1<<5)) goto KEY3398;
	local[5] = NIL;
KEY3398:
	if (n & (1<<6)) goto KEY3399;
	local[6] = NIL;
KEY3399:
	if (n & (1<<7)) goto KEY3400;
	local[7] = NIL;
KEY3400:
	if (n & (1<<8)) goto KEY3401;
	local[9]= argv[0];
	local[10]= fqv[161];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[8] = w;
KEY3401:
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	local[9]= w;
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)LENGTH(ctx,1,local+10); /*length*/
	local[10]= w;
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)LENGTH(ctx,1,local+11); /*length*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)NUMEQUAL(ctx,3,local+9); /*=*/
	if (w!=NIL) goto IF3402;
	local[9]= fqv[162];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)LENGTH(ctx,1,local+10); /*length*/
	local[10]= w;
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)LENGTH(ctx,1,local+11); /*length*/
	local[11]= w;
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(pointer)LENGTH(ctx,1,local+12); /*length*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)SIGERROR(ctx,4,local+9); /*error*/
	local[9]= w;
	goto IF3403;
IF3402:
	local[9]= NIL;
IF3403:
	ctx->vsp=local+9;
	local[9]= makeclosure(codevec,quotevec,CLO3404,env,argv,local);
	local[10]= local[5];
	local[11]= local[6];
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(pointer)MAPCAR(ctx,4,local+9); /*mapcar*/
	local[9]= argv[0];
	local[10]= fqv[163];
	local[11]= fqv[45];
	local[12]= local[0];
	local[13]= fqv[164];
	local[14]= local[1];
	local[15]= fqv[165];
	local[16]= local[3];
	local[17]= fqv[166];
	local[18]= local[4];
	local[19]= fqv[167];
	local[20]= local[2];
	local[21]= fqv[161];
	local[22]= local[8];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,14,local+9); /*send*/
	local[0]= w;
BLK3392:
	ctx->vsp=local; return(local[0]);}

/*:calc-torque-without-ext-wrench*/
static pointer M3405cascaded_link_calc_torque_without_ext_wrench(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[168], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY3407;
	local[0] = NIL;
KEY3407:
	if (n & (1<<1)) goto KEY3408;
	local[1] = T;
KEY3408:
	if (n & (1<<2)) goto KEY3409;
	local[2] = makeflt(4.9999999999999975019982e-03);
KEY3409:
	if (n & (1<<3)) goto KEY3410;
	local[6]= argv[0];
	local[7]= fqv[160];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[3] = w;
KEY3410:
	if (n & (1<<4)) goto KEY3411;
	local[6]= argv[0];
	local[7]= fqv[74];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= fqv[68];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[4] = w;
KEY3411:
	if (n & (1<<5)) goto KEY3412;
	local[6]= argv[0];
	local[7]= fqv[161];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[5] = w;
KEY3412:
	local[6]= (pointer)get_sym_func(fqv[82]);
	local[7]= argv[0];
	local[8]= fqv[169];
	local[9]= fqv[45];
	local[10]= local[0];
	local[11]= fqv[161];
	local[12]= local[5];
	if (local[1]!=NIL) goto IF3413;
	local[13]= argv[0];
	local[14]= fqv[170];
	local[15]= local[2];
	local[16]= local[4];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,4,local+13); /*send*/
	local[13]= w;
	local[14]= argv[0];
	local[15]= fqv[171];
	local[16]= local[2];
	local[17]= local[3];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,4,local+14); /*send*/
	local[14]= w;
	local[15]= fqv[172];
	local[16]= fqv[173];
	w = local[14];
	w=memq(local[16],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	local[17]= fqv[174];
	local[18]= fqv[175];
	w = local[14];
	w=memq(local[18],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	local[19]= fqv[176];
	local[20]= fqv[176];
	w = local[13];
	w=memq(local[20],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	local[21]= fqv[177];
	local[22]= fqv[177];
	w = local[13];
	w=memq(local[22],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	local[23]= fqv[178];
	local[24]= fqv[178];
	w = local[13];
	w=memq(local[24],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24]= (w)->c.cons.car;
	local[25]= fqv[179];
	local[26]= fqv[179];
	w = local[13];
	w=memq(local[26],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	ctx->vsp=local+27;
	w=(pointer)LIST(ctx,12,local+15); /*list*/
	local[13]= w;
	goto IF3414;
IF3413:
	local[13]= NIL;
IF3414:
	ctx->vsp=local+14;
	w=(pointer)APPLY(ctx,8,local+6); /*apply*/
	local[0]= w;
BLK3406:
	ctx->vsp=local; return(local[0]);}

/*:calc-torque-from-vel-acc*/
static pointer M3415cascaded_link_calc_torque_from_vel_acc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[180], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY3417;
	local[0] = NIL;
KEY3417:
	if (n & (1<<1)) goto KEY3418;
	local[8]= loadglobal(fqv[43]);
	local[9]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,2,local+8); /*instantiate*/
	local[1] = w;
KEY3418:
	if (n & (1<<2)) goto KEY3419;
	local[8]= loadglobal(fqv[43]);
	local[9]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,2,local+8); /*instantiate*/
	local[2] = w;
KEY3419:
	if (n & (1<<3)) goto KEY3420;
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)MKFLTVEC(ctx,3,local+8); /*float-vector*/
	local[3] = w;
KEY3420:
	if (n & (1<<4)) goto KEY3421;
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)MKFLTVEC(ctx,3,local+8); /*float-vector*/
	local[4] = w;
KEY3421:
	if (n & (1<<5)) goto KEY3422;
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)MKFLTVEC(ctx,3,local+8); /*float-vector*/
	local[5] = w;
KEY3422:
	if (n & (1<<6)) goto KEY3423;
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)MKFLTVEC(ctx,3,local+8); /*float-vector*/
	local[6] = w;
KEY3423:
	if (n & (1<<7)) goto KEY3424;
	local[8]= argv[0];
	local[9]= fqv[161];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[7] = w;
KEY3424:
	local[8]= loadglobal(fqv[43]);
	local[9]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,2,local+8); /*instantiate*/
	local[8]= w;
	ctx->vsp=local+9;
	local[9]= makeclosure(codevec,quotevec,CLO3425,env,argv,local);
	local[10]= argv[0];
	local[11]= fqv[74];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)MAPCAR(ctx,2,local+9); /*mapcar*/
	local[9]= w;
	local[10]= argv[0];
	local[11]= fqv[74];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	local[11]= fqv[181];
	local[12]= fqv[182];
	ctx->vsp=local+13;
	w=(*ftab[7])(ctx,3,local+10,&ftab[7],fqv[29]); /*send-all*/
	local[10]= argv[0];
	local[11]= fqv[74];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	local[11]= makeclosure(codevec,quotevec,CLO3426,env,argv,local);
	ctx->vsp=local+12;
	w=(*ftab[9])(ctx,2,local+10,&ftab[9],fqv[75]); /*all-child-links*/
	local[10]= makeint((eusinteger_t)0L);
	local[11]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+12;
	w=(pointer)LENGTH(ctx,1,local+11); /*length*/
	local[11]= w;
WHL3428:
	local[12]= local[10];
	w = local[11];
	if ((eusinteger_t)local[12] >= (eusinteger_t)w) goto WHX3429;
	local[12]= argv[0]->c.obj.iv[9];
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[12]= w;
	local[13]= local[12];
	local[14]= fqv[138];
	local[15]= local[1];
	local[16]= local[10];
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= local[12];
	local[14]= fqv[141];
	local[15]= local[2];
	local[16]= local[10];
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[12]= local[10];
	ctx->vsp=local+13;
	w=(pointer)ADD1(ctx,1,local+12); /*1+*/
	local[10] = w;
	goto WHL3428;
WHX3429:
	local[12]= NIL;
BLK3430:
	w = NIL;
	local[10]= argv[0];
	local[11]= fqv[74];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= fqv[140];
	local[12]= local[5];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= argv[0];
	local[11]= fqv[74];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= fqv[143];
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= argv[0];
	local[11]= fqv[74];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= fqv[117];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= argv[0];
	local[11]= fqv[74];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= fqv[116];
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= (pointer)get_sym_func(fqv[82]);
	local[11]= argv[0];
	local[12]= fqv[74];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= fqv[144];
	local[13]= fqv[45];
	local[14]= local[0];
	local[15]= local[7];
	local[16]= makeint((eusinteger_t)0L);
	local[17]= makeint((eusinteger_t)2L);
	ctx->vsp=local+18;
	w=(pointer)SUBSEQ(ctx,3,local+15); /*subseq*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)APPLY(ctx,6,local+10); /*apply*/
	local[10]= (pointer)get_sym_func(fqv[82]);
	local[11]= argv[0];
	local[12]= fqv[74];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= fqv[148];
	local[13]= fqv[45];
	local[14]= local[0];
	local[15]= local[7];
	ctx->vsp=local+16;
	w=(pointer)APPLY(ctx,6,local+10); /*apply*/
	local[10]= argv[0];
	local[11]= fqv[74];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	local[11]= makeclosure(codevec,quotevec,CLO3431,env,argv,local);
	ctx->vsp=local+12;
	w=(*ftab[9])(ctx,2,local+10,&ftab[9],fqv[75]); /*all-child-links*/
	local[10]= makeint((eusinteger_t)0L);
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(pointer)LENGTH(ctx,1,local+11); /*length*/
	local[11]= w;
WHL3433:
	local[12]= local[10];
	w = local[11];
	if ((eusinteger_t)local[12] >= (eusinteger_t)w) goto WHX3434;
	local[12]= local[8];
	local[13]= local[10];
	local[14]= argv[0]->c.obj.iv[9];
	local[15]= local[10];
	ctx->vsp=local+16;
	w=(pointer)ELT(ctx,2,local+14); /*elt*/
	local[14]= w;
	local[15]= fqv[152];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,2,local+14); /*send*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SETELT(ctx,3,local+12); /*setelt*/
	local[12]= local[10];
	ctx->vsp=local+13;
	w=(pointer)ADD1(ctx,1,local+12); /*1+*/
	local[10] = w;
	goto WHL3433;
WHX3434:
	local[12]= NIL;
BLK3435:
	w = NIL;
	ctx->vsp=local+10;
	local[10]= makeclosure(codevec,quotevec,CLO3436,env,argv,local);
	local[11]= argv[0];
	local[12]= fqv[74];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	local[12]= local[9];
	ctx->vsp=local+13;
	w=(pointer)MAPCAR(ctx,3,local+10); /*mapcar*/
	w = local[8];
	local[0]= w;
BLK3416:
	ctx->vsp=local; return(local[0]);}

/*:calc-root-coords-vel-acc-from-pos*/
static pointer M3437cascaded_link_calc_root_coords_vel_acc_from_pos(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,FLET3439,env,argv,local);
	local[1]= makeflt(1.0000000000000000000000e+00);
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[49];
	local[4]= fqv[183];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	if (w==NIL) goto IF3440;
	local[2]= argv[0];
	local[3]= fqv[49];
	local[4]= fqv[183];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF3441;
IF3440:
	local[2]= argv[3];
IF3441:
	local[3]= local[1];
	local[4]= local[2];
	local[5]= fqv[2];
	local[6]= local[2];
	local[7]= fqv[25];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)TRANSPOSE(ctx,1,local+6); /*transpose*/
	local[6]= w;
	local[7]= argv[3];
	local[8]= fqv[25];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MATTIMES(ctx,2,local+6); /*m**/
	local[6]= w;
	w = local[0];
	ctx->vsp=local+7;
	w=FLET3439(ctx,1,local+6,w);
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SCALEVEC(ctx,2,local+3); /*scale*/
	local[3]= w;
	local[4]= makeflt(1.0000000000000000208167e-03);
	local[5]= argv[3];
	local[6]= fqv[5];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SCALEVEC(ctx,2,local+4); /*scale*/
	local[4]= w;
	local[5]= makeflt(1.0000000000000000208167e-03);
	local[6]= local[2];
	local[7]= fqv[5];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SCALEVEC(ctx,2,local+5); /*scale*/
	local[5]= w;
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)VNORM(ctx,1,local+6); /*norm*/
	local[6]= w;
	local[7]= makeflt(0.0000000000000000000000e+00);
	local[8]= makeflt(4.9999999999999975019982e-03);
	ctx->vsp=local+9;
	w=(*ftab[4])(ctx,3,local+6,&ftab[4],fqv[22]); /*eps=*/
	if (w==NIL) goto IF3442;
	local[6]= local[1];
	local[7]= local[4];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)VMINUS(ctx,2,local+7); /*v-*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SCALEVEC(ctx,2,local+6); /*scale*/
	local[6]= w;
	goto IF3443;
IF3442:
	local[6]= local[3];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+6); /*v**/
	local[6]= w;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)VNORM(ctx,1,local+7); /*norm*/
	local[7]= w;
	local[8]= makeint((eusinteger_t)3L);
	ctx->vsp=local+9;
	w=(*ftab[14])(ctx,1,local+8,&ftab[14],fqv[184]); /*unit-matrix*/
	local[8]= w;
	local[9]= argv[2];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)SCALEVEC(ctx,2,local+9); /*scale*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[15])(ctx,1,local+9,&ftab[15],fqv[185]); /*matrix-exponent*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[16])(ctx,2,local+8,&ftab[16],fqv[186]); /*m-*/
	local[8]= w;
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(*ftab[1])(ctx,1,local+9,&ftab[1],fqv[3]); /*normalize-vector*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[8])(ctx,1,local+9,&ftab[8],fqv[72]); /*outer-product-matrix*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MATTIMES(ctx,2,local+8); /*m**/
	local[8]= w;
	local[9]= argv[2];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)VNORM(ctx,1,local+10); /*norm*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	local[10]= makeint((eusinteger_t)1L);
	local[11]= makeint((eusinteger_t)3L);
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(*ftab[5])(ctx,3,local+10,&ftab[5],fqv[24]); /*make-matrix*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)TRANSPOSE(ctx,1,local+10); /*transpose*/
	local[10]= w;
	local[11]= makeint((eusinteger_t)1L);
	local[12]= makeint((eusinteger_t)3L);
	local[13]= local[3];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(*ftab[5])(ctx,3,local+11,&ftab[5],fqv[24]); /*make-matrix*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)MATTIMES(ctx,2,local+10); /*m**/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[2])(ctx,2,local+9,&ftab[2],fqv[4]); /*scale-matrix*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[6])(ctx,2,local+8,&ftab[6],fqv[27]); /*m+*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[17])(ctx,1,local+8,&ftab[17],fqv[187]); /*inverse-matrix*/
	local[8]= w;
	local[9]= local[4];
	local[10]= argv[2];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)SCALEVEC(ctx,2,local+10); /*scale*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[15])(ctx,1,local+10,&ftab[15],fqv[185]); /*matrix-exponent*/
	local[10]= w;
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)TRANSFORM(ctx,2,local+10); /*transform*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)VMINUS(ctx,2,local+9); /*v-*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)TRANSFORM(ctx,2,local+8); /*transform*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SCALEVEC(ctx,2,local+7); /*scale*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)VPLUS(ctx,2,local+6); /*v+*/
	local[6]= w;
IF3443:
	local[7]= argv[0];
	local[8]= fqv[49];
	local[9]= fqv[188];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	if (w==NIL) goto IF3444;
	local[7]= argv[0];
	local[8]= fqv[49];
	local[9]= fqv[188];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	goto IF3445;
IF3444:
	local[7]= local[6];
IF3445:
	local[8]= argv[0];
	local[9]= fqv[49];
	local[10]= fqv[189];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	if (w==NIL) goto IF3446;
	local[8]= argv[0];
	local[9]= fqv[49];
	local[10]= fqv[189];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	goto IF3447;
IF3446:
	local[8]= local[3];
IF3447:
	local[9]= local[1];
	local[10]= local[3];
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(pointer)VMINUS(ctx,2,local+10); /*v-*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SCALEVEC(ctx,2,local+9); /*scale*/
	local[9]= w;
	local[10]= local[1];
	local[11]= local[6];
	local[12]= argv[2];
	local[13]= local[3];
	ctx->vsp=local+14;
	w=(pointer)SCALEVEC(ctx,2,local+12); /*scale*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(*ftab[15])(ctx,1,local+12,&ftab[15],fqv[185]); /*matrix-exponent*/
	local[12]= w;
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(pointer)TRANSFORM(ctx,2,local+12); /*transform*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)VMINUS(ctx,2,local+11); /*v-*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)SCALEVEC(ctx,2,local+10); /*scale*/
	local[10]= w;
	local[11]= local[9];
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+11); /*v**/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)VMINUS(ctx,2,local+10); /*v-*/
	local[10]= w;
	local[11]= argv[0];
	local[12]= fqv[46];
	local[13]= fqv[183];
	local[14]= argv[3];
	local[15]= fqv[68];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,2,local+14); /*send*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,4,local+11); /*send*/
	local[11]= argv[0];
	local[12]= fqv[46];
	local[13]= fqv[188];
	local[14]= local[6];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,4,local+11); /*send*/
	local[11]= argv[0];
	local[12]= fqv[46];
	local[13]= fqv[189];
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,4,local+11); /*send*/
	local[11]= fqv[176];
	local[12]= local[6];
	local[13]= local[3];
	local[14]= makeflt(1.0000000000000000208167e-03);
	local[15]= argv[3];
	local[16]= fqv[5];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)SCALEVEC(ctx,2,local+14); /*scale*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+13); /*v**/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)VMINUS(ctx,2,local+12); /*v-*/
	local[12]= w;
	local[13]= fqv[177];
	local[14]= local[3];
	local[15]= fqv[178];
	local[16]= local[10];
	local[17]= fqv[179];
	local[18]= local[9];
	ctx->vsp=local+19;
	w=(pointer)LIST(ctx,8,local+11); /*list*/
	local[0]= w;
BLK3438:
	ctx->vsp=local; return(local[0]);}

/*:calc-av-vel-acc-from-pos*/
static pointer M3448cascaded_link_calc_av_vel_acc_from_pos(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= makeflt(1.0000000000000000000000e+00);
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[49];
	local[3]= fqv[190];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	if (w==NIL) goto IF3450;
	local[1]= argv[0];
	local[2]= fqv[49];
	local[3]= fqv[190];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF3451;
IF3450:
	local[1]= argv[3];
IF3451:
	local[2]= loadglobal(fqv[43]);
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,2,local+2); /*instantiate*/
	local[2]= w;
	local[3]= makeint((eusinteger_t)0L);
	local[4]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
WHL3453:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX3454;
	local[5]= local[2];
	local[6]= local[3];
	local[7]= local[0];
	local[8]= argv[0]->c.obj.iv[9];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	local[9]= fqv[191];
	local[10]= argv[3];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)ELT(ctx,2,local+10); /*elt*/
	local[10]= w;
	local[11]= local[1];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)MINUS(ctx,2,local+10); /*-*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SETELT(ctx,3,local+5); /*setelt*/
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL3453;
WHX3454:
	local[5]= NIL;
BLK3455:
	w = NIL;
	w = local[2];
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[49];
	local[5]= fqv[192];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	if (w==NIL) goto IF3456;
	local[3]= argv[0];
	local[4]= fqv[49];
	local[5]= fqv[192];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF3457;
IF3456:
	local[3]= local[2];
IF3457:
	local[4]= local[0];
	local[5]= local[2];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)VMINUS(ctx,2,local+5); /*v-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SCALEVEC(ctx,2,local+4); /*scale*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[46];
	local[7]= fqv[190];
	local[8]= argv[3];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[46];
	local[7]= fqv[192];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= fqv[173];
	local[6]= local[2];
	local[7]= fqv[175];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,4,local+5); /*list*/
	local[0]= w;
BLK3449:
	ctx->vsp=local; return(local[0]);}

/*:calc-torque-from-ext-wrenches*/
static pointer M3458cascaded_link_calc_torque_from_ext_wrenches(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[193], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY3460;
	local[0] = NIL;
KEY3460:
	if (n & (1<<1)) goto KEY3461;
	local[1] = NIL;
KEY3461:
	if (n & (1<<2)) goto KEY3462;
	local[2] = NIL;
KEY3462:
	if (n & (1<<3)) goto KEY3463;
	local[3] = NIL;
KEY3463:
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO3464,env,argv,local);
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[4]= w;
	if (local[3]==NIL) goto IF3465;
	local[5]= local[3];
	goto IF3466;
IF3465:
	local[5]= argv[0];
	local[6]= fqv[194];
	local[7]= local[4];
	local[8]= fqv[195];
	local[9]= local[2];
	local[10]= fqv[196];
	ctx->vsp=local+11;
	local[11]= makeclosure(codevec,quotevec,CLO3467,env,argv,local);
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)MAPCAR(ctx,2,local+11); /*mapcar*/
	local[11]= w;
	local[12]= fqv[87];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)LENGTH(ctx,1,local+13); /*length*/
	local[13]= w;
	local[14]= fqv[197];
	local[15]= T;
	ctx->vsp=local+16;
	w=(*ftab[18])(ctx,3,local+13,&ftab[18],fqv[198]); /*make-list*/
	local[13]= w;
	local[14]= fqv[86];
	local[15]= local[2];
	ctx->vsp=local+16;
	w=(pointer)LENGTH(ctx,1,local+15); /*length*/
	local[15]= w;
	local[16]= fqv[197];
	local[17]= T;
	ctx->vsp=local+18;
	w=(*ftab[18])(ctx,3,local+15,&ftab[18],fqv[198]); /*make-list*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,11,local+5); /*send*/
	local[5]= w;
IF3466:
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO3468,env,argv,local);
	local[7]= local[0];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)MAPCAR(ctx,3,local+6); /*mapcar*/
	local[6]= w;
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)TRANSPOSE(ctx,1,local+7); /*transpose*/
	local[7]= w;
	local[8]= (pointer)get_sym_func(fqv[199]);
	local[9]= loadglobal(fqv[43]);
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)APPLY(ctx,3,local+8); /*apply*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)TRANSFORM(ctx,2,local+7); /*transform*/
	local[7]= w;
	local[8]= loadglobal(fqv[43]);
	local[9]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,2,local+8); /*instantiate*/
	local[8]= w;
	local[9]= argv[0];
	local[10]= fqv[200];
	local[11]= local[4];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= w;
	local[10]= makeint((eusinteger_t)0L);
	local[11]= local[9];
	ctx->vsp=local+12;
	w=(pointer)LENGTH(ctx,1,local+11); /*length*/
	local[11]= w;
WHL3470:
	local[12]= local[10];
	w = local[11];
	if ((eusinteger_t)local[12] >= (eusinteger_t)w) goto WHX3471;
	local[12]= local[8];
	local[13]= local[9];
	local[14]= local[10];
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	local[14]= fqv[81];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	local[13]= w;
	local[14]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+15;
	w=(*ftab[19])(ctx,2,local+13,&ftab[19],fqv[201]); /*position*/
	local[13]= w;
	local[14]= local[7];
	local[15]= local[10];
	ctx->vsp=local+16;
	w=(pointer)ELT(ctx,2,local+14); /*elt*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SETELT(ctx,3,local+12); /*setelt*/
	local[12]= local[10];
	ctx->vsp=local+13;
	w=(pointer)ADD1(ctx,1,local+12); /*1+*/
	local[10] = w;
	goto WHL3470;
WHX3471:
	local[12]= NIL;
BLK3472:
	w = NIL;
	w = local[8];
	local[0]= w;
BLK3459:
	ctx->vsp=local; return(local[0]);}

/*:calc-zmp*/
static pointer M3473cascaded_link_calc_zmp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3477;}
	local[0]= argv[0];
	local[1]= fqv[160];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
ENT3477:
	if (n>=4) { local[1]=(argv[3]); goto ENT3476;}
	local[1]= argv[0];
	local[2]= fqv[74];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[68];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
ENT3476:
ENT3475:
	ctx->vsp=local+2;
	n=parsekeyparams(fqv[202], &argv[4], n-4, local+2, 0);
	if (n & (1<<0)) goto KEY3478;
	local[2] = makeflt(0.0000000000000000000000e+00);
KEY3478:
	if (n & (1<<1)) goto KEY3479;
	local[3] = makeflt(4.9999999999999975019982e-03);
KEY3479:
	if (n & (1<<2)) goto KEY3480;
	local[4] = T;
KEY3480:
	if (n & (1<<3)) goto KEY3481;
	local[5] = NIL;
KEY3481:
	if (n & (1<<4)) goto KEY3482;
	local[7]= argv[0];
	local[8]= fqv[161];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[6] = w;
KEY3482:
	if (local[4]==NIL) goto IF3483;
	local[7]= argv[0];
	local[8]= fqv[74];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,CLO3485,env,argv,local);
	ctx->vsp=local+9;
	w=(*ftab[9])(ctx,2,local+7,&ftab[9],fqv[75]); /*all-child-links*/
	local[7]= argv[0];
	local[8]= fqv[203];
	local[9]= fqv[167];
	local[10]= local[3];
	local[11]= fqv[165];
	local[12]= local[0];
	local[13]= fqv[166];
	local[14]= local[1];
	local[15]= fqv[45];
	local[16]= local[5];
	local[17]= fqv[164];
	local[18]= NIL;
	local[19]= fqv[161];
	local[20]= local[6];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,14,local+7); /*send*/
	local[7]= w;
	goto IF3484;
IF3483:
	local[7]= NIL;
IF3484:
	local[7]= argv[0];
	local[8]= fqv[74];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= fqv[150];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= argv[0];
	local[9]= fqv[74];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= fqv[151];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= local[7];
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	local[10]= local[7];
	local[11]= makeint((eusinteger_t)1L);
	ctx->vsp=local+12;
	w=(pointer)ELT(ctx,2,local+10); /*elt*/
	local[10]= w;
	local[11]= local[7];
	local[12]= makeint((eusinteger_t)2L);
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	local[12]= local[8];
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[12]= w;
	local[13]= local[8];
	local[14]= makeint((eusinteger_t)1L);
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	local[14]= local[8];
	local[15]= makeint((eusinteger_t)2L);
	ctx->vsp=local+16;
	w=(pointer)ELT(ctx,2,local+14); /*elt*/
	local[14]= w;
	local[15]= makeflt(1.0000000000000000208167e-03);
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)TIMES(ctx,2,local+15); /***/
	local[15]= w;
	local[16]= local[13];
	ctx->vsp=local+17;
	w=(pointer)MINUS(ctx,1,local+16); /*-*/
	local[16]= w;
	local[17]= local[15];
	local[18]= local[9];
	ctx->vsp=local+19;
	w=(pointer)TIMES(ctx,2,local+17); /***/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)PLUS(ctx,2,local+16); /*+*/
	local[16]= w;
	local[17]= local[11];
	ctx->vsp=local+18;
	w=(pointer)QUOTIENT(ctx,2,local+16); /*/*/
	local[16]= w;
	local[17]= local[12];
	local[18]= local[15];
	local[19]= local[10];
	ctx->vsp=local+20;
	w=(pointer)TIMES(ctx,2,local+18); /***/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)PLUS(ctx,2,local+17); /*+*/
	local[17]= w;
	local[18]= local[11];
	ctx->vsp=local+19;
	w=(pointer)QUOTIENT(ctx,2,local+17); /*/*/
	local[17]= w;
	local[18]= local[15];
	ctx->vsp=local+19;
	w=(pointer)MKFLTVEC(ctx,3,local+16); /*float-vector*/
	local[16]= w;
	local[17]= argv[0];
	local[18]= fqv[46];
	local[19]= fqv[204];
	local[20]= makeflt(1.0000000000000000000000e+03);
	local[21]= local[16];
	ctx->vsp=local+22;
	w=(pointer)SCALEVEC(ctx,2,local+20); /*scale*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,4,local+17); /*send*/
	local[17]= argv[0];
	local[18]= fqv[46];
	local[19]= fqv[205];
	local[20]= makeint((eusinteger_t)0L);
	local[21]= makeint((eusinteger_t)0L);
	local[22]= local[14];
	local[23]= makeflt(1.0000000000000000208167e-03);
	local[24]= argv[0];
	local[25]= fqv[49];
	local[26]= fqv[204];
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,3,local+24); /*send*/
	local[24]= w;
	local[25]= makeint((eusinteger_t)0L);
	ctx->vsp=local+26;
	w=(pointer)ELT(ctx,2,local+24); /*elt*/
	local[24]= w;
	ctx->vsp=local+25;
	w=(pointer)TIMES(ctx,2,local+23); /***/
	local[23]= w;
	local[24]= local[10];
	local[25]= makeflt(-1.0000000000000000000000e+00);
	ctx->vsp=local+26;
	w=(pointer)TIMES(ctx,3,local+23); /***/
	local[23]= w;
	local[24]= makeflt(1.0000000000000000208167e-03);
	local[25]= argv[0];
	local[26]= fqv[49];
	local[27]= fqv[204];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,3,local+25); /*send*/
	local[25]= w;
	local[26]= makeint((eusinteger_t)1L);
	ctx->vsp=local+27;
	w=(pointer)ELT(ctx,2,local+25); /*elt*/
	local[25]= w;
	ctx->vsp=local+26;
	w=(pointer)TIMES(ctx,2,local+24); /***/
	local[24]= w;
	local[25]= local[9];
	ctx->vsp=local+26;
	w=(pointer)TIMES(ctx,2,local+24); /***/
	local[24]= w;
	ctx->vsp=local+25;
	w=(pointer)PLUS(ctx,3,local+22); /*+*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)MKFLTVEC(ctx,3,local+20); /*float-vector*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,4,local+17); /*send*/
	local[7]= argv[0];
	local[8]= fqv[49];
	local[9]= fqv[204];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[0]= w;
BLK3474:
	ctx->vsp=local; return(local[0]);}

/*:calc-cop-from-force-moment*/
static pointer M3486cascaded_link_calc_cop_from_force_moment(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<6) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[206], &argv[6], n-6, local+0, 0);
	if (n & (1<<0)) goto KEY3488;
	local[0] = makeint((eusinteger_t)1L);
KEY3488:
	if (n & (1<<1)) goto KEY3489;
	local[1] = NIL;
KEY3489:
	local[2]= argv[5];
	local[3]= fqv[207];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[5];
	local[4]= fqv[207];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= makeflt(1.0000000000000000208167e-03);
	local[5]= argv[5];
	local[6]= fqv[41];
	local[7]= argv[4];
	local[8]= fqv[5];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SCALEVEC(ctx,2,local+4); /*scale*/
	local[4]= w;
	local[5]= local[2];
	local[6]= makeint((eusinteger_t)2L);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	local[6]= local[4];
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	local[6]= local[4];
	local[7]= makeint((eusinteger_t)2L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	local[7]= local[2];
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,1,local+6); /*-*/
	local[6]= w;
	local[7]= local[3];
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,1,local+7); /*-*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,3,local+5); /*+*/
	local[5]= w;
	local[6]= local[2];
	local[7]= makeint((eusinteger_t)2L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	local[7]= local[4];
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	local[7]= local[4];
	local[8]= makeint((eusinteger_t)2L);
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	local[8]= local[2];
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,1,local+7); /*-*/
	local[7]= w;
	local[8]= local[3];
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,3,local+6); /*+*/
	local[6]= w;
	local[7]= local[2];
	local[8]= makeint((eusinteger_t)2L);
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	local[8]= local[7];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)LESSP(ctx,2,local+8); /*<*/
	if (w==NIL) goto CON3491;
	local[8]= NIL;
	goto CON3490;
CON3491:
	if (local[1]==NIL) goto CON3492;
	local[8]= fqv[208];
	local[9]= argv[5];
	local[10]= fqv[209];
	local[11]= makeflt(1.0000000000000000000000e+03);
	local[12]= local[5];
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(pointer)QUOTIENT(ctx,2,local+12); /*/*/
	local[12]= w;
	local[13]= local[6];
	local[14]= local[7];
	ctx->vsp=local+15;
	w=(pointer)QUOTIENT(ctx,2,local+13); /*/*/
	local[13]= w;
	local[14]= makeint((eusinteger_t)0L);
	ctx->vsp=local+15;
	w=(pointer)MKFLTVEC(ctx,3,local+12); /*float-vector*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)SCALEVEC(ctx,2,local+11); /*scale*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= w;
	local[10]= fqv[210];
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,4,local+8); /*list*/
	local[8]= w;
	goto CON3490;
CON3492:
	local[8]= argv[5];
	local[9]= fqv[209];
	local[10]= makeflt(1.0000000000000000000000e+03);
	local[11]= local[5];
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(pointer)QUOTIENT(ctx,2,local+11); /*/*/
	local[11]= w;
	local[12]= local[6];
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(pointer)QUOTIENT(ctx,2,local+12); /*/*/
	local[12]= w;
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(pointer)MKFLTVEC(ctx,3,local+11); /*float-vector*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)SCALEVEC(ctx,2,local+10); /*scale*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	goto CON3490;
CON3493:
	local[8]= NIL;
CON3490:
	w = local[8];
	local[0]= w;
BLK3487:
	ctx->vsp=local; return(local[0]);}

/*:wrench-vector->wrench-list*/
static pointer M3494cascaded_link_wrench_vector__wrench_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= makeint((eusinteger_t)0L);
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	local[4]= makeint((eusinteger_t)6L);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
WHL3497:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX3498;
	local[4]= argv[2];
	local[5]= makeint((eusinteger_t)6L);
	{ eusinteger_t i,j;
		j=intval(local[2]); i=intval(local[5]);
		local[5]=(makeint(i * j));}
	local[6]= makeint((eusinteger_t)3L);
	local[7]= makeint((eusinteger_t)6L);
	{ eusinteger_t i,j;
		j=intval(local[2]); i=intval(local[7]);
		local[7]=(makeint(i * j));}
	w = local[7];
#if sun4 || vax || mips || alpha || Linux
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[6]= (pointer)((eusinteger_t)local[6] + (eusinteger_t)w);
	ctx->vsp=local+7;
	w=(pointer)SUBSEQ(ctx,3,local+4); /*subseq*/
	local[4]= w;
	w = local[0];
	ctx->vsp=local+5;
	local[0] = cons(ctx,local[4],w);
	local[4]= argv[2];
	local[5]= makeint((eusinteger_t)3L);
	local[6]= makeint((eusinteger_t)6L);
	{ eusinteger_t i,j;
		j=intval(local[2]); i=intval(local[6]);
		local[6]=(makeint(i * j));}
	w = local[6];
#if sun4 || vax || mips || alpha || Linux
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[5]= (pointer)((eusinteger_t)local[5] + (eusinteger_t)w);
	local[6]= makeint((eusinteger_t)6L);
	local[7]= makeint((eusinteger_t)6L);
	{ eusinteger_t i,j;
		j=intval(local[2]); i=intval(local[7]);
		local[7]=(makeint(i * j));}
	w = local[7];
#if sun4 || vax || mips || alpha || Linux
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[6]= (pointer)((eusinteger_t)local[6] + (eusinteger_t)w);
	ctx->vsp=local+7;
	w=(pointer)SUBSEQ(ctx,3,local+4); /*subseq*/
	local[4]= w;
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL3497;
WHX3498:
	local[4]= NIL;
BLK3499:
	w = NIL;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)REVERSE(ctx,1,local+2); /*reverse*/
	local[2]= w;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)REVERSE(ctx,1,local+3); /*reverse*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[0]= w;
BLK3495:
	ctx->vsp=local; return(local[0]);}

/*:wrench-list->wrench-vector*/
static pointer M3500cascaded_link_wrench_list__wrench_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= (pointer)get_sym_func(fqv[199]);
	local[1]= loadglobal(fqv[43]);
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO3502,env,argv,local);
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,3,local+2); /*mapcar*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,3,local+0); /*apply*/
	local[0]= w;
BLK3501:
	ctx->vsp=local; return(local[0]);}

/*:calc-contact-wrenches-from-total-wrench*/
static pointer M3503cascaded_link_calc_contact_wrenches_from_total_wrench(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[211], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY3505;
	local[0] = NIL;
KEY3505:
	if (n & (1<<1)) goto KEY3506;
	local[2]= loadglobal(fqv[43]);
	local[3]= makeint((eusinteger_t)6L);
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	{ eusinteger_t i,j;
		j=intval(w); i=intval(local[3]);
		local[3]=(makeint(i * j));}
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,2,local+2); /*instantiate*/
	local[2]= w;
	local[3]= makeint((eusinteger_t)1L);
	ctx->vsp=local+4;
	w=(*ftab[20])(ctx,2,local+2,&ftab[20],fqv[212]); /*fill*/
	local[1] = w;
KEY3506:
	if (local[0]!=NIL) goto IF3507;
	local[2]= argv[0];
	local[3]= fqv[20];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= makeflt(9.9999999999999974298988e-07);
	local[4]= loadglobal(fqv[147]);
	local[5]= makeint((eusinteger_t)2L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,3,local+2); /***/
	local[2]= w;
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	local[5]= local[2];
	local[6]= makeflt(1.0000000000000000208167e-03);
	local[7]= argv[0];
	local[8]= fqv[30];
	local[9]= NIL;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,3,local+6); /***/
	local[6]= w;
	local[7]= makeflt(-1.0000000000000000208167e-03);
	local[8]= argv[0];
	local[9]= fqv[30];
	local[10]= NIL;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,3,local+7); /***/
	local[7]= w;
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,6,local+3); /*float-vector*/
	local[0] = w;
	local[2]= local[0];
	goto IF3508;
IF3507:
	local[2]= NIL;
IF3508:
	local[2]= argv[0];
	local[3]= fqv[94];
	local[4]= argv[0];
	local[5]= fqv[213];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= fqv[20];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)TRANSFORM(ctx,2,local+2); /*transform*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= makeint((eusinteger_t)0L);
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
WHL3510:
	local[7]= local[5];
	w = local[6];
	if ((eusinteger_t)local[7] >= (eusinteger_t)w) goto WHX3511;
	local[7]= local[2];
	local[8]= local[5];
	{ eusinteger_t i,j;
		j=intval(makeint((eusinteger_t)6L)); i=intval(local[8]);
		local[8]=(makeint(i * j));}
	local[9]= local[5];
	{ eusinteger_t i,j;
		j=intval(makeint((eusinteger_t)6L)); i=intval(local[9]);
		local[9]=(makeint(i * j));}
	w = makeint((eusinteger_t)3L);
#if sun4 || vax || mips || alpha || Linux
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[9]= (pointer)((eusinteger_t)local[9] + (eusinteger_t)w);
	ctx->vsp=local+10;
	w=(pointer)SUBSEQ(ctx,3,local+7); /*subseq*/
	local[7]= w;
	w = local[3];
	ctx->vsp=local+8;
	local[3] = cons(ctx,local[7],w);
	local[7]= local[2];
	local[8]= local[5];
	{ eusinteger_t i,j;
		j=intval(makeint((eusinteger_t)6L)); i=intval(local[8]);
		local[8]=(makeint(i * j));}
	w = makeint((eusinteger_t)3L);
#if sun4 || vax || mips || alpha || Linux
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[8]= (pointer)((eusinteger_t)local[8] + (eusinteger_t)w);
	local[9]= local[5];
	{ eusinteger_t i,j;
		j=intval(makeint((eusinteger_t)6L)); i=intval(local[9]);
		local[9]=(makeint(i * j));}
	w = makeint((eusinteger_t)6L);
#if sun4 || vax || mips || alpha || Linux
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[9]= (pointer)((eusinteger_t)local[9] + (eusinteger_t)w);
	ctx->vsp=local+10;
	w=(pointer)SUBSEQ(ctx,3,local+7); /*subseq*/
	local[7]= w;
	w = local[4];
	ctx->vsp=local+8;
	local[4] = cons(ctx,local[7],w);
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[5] = w;
	goto WHL3510;
WHX3511:
	local[7]= NIL;
BLK3512:
	w = NIL;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)REVERSE(ctx,1,local+5); /*reverse*/
	local[5]= w;
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)REVERSE(ctx,1,local+6); /*reverse*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,2,local+5); /*list*/
	local[0]= w;
BLK3504:
	ctx->vsp=local; return(local[0]);}

/*:draw-torque*/
static pointer M3513cascaded_link_draw_torque(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[214], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY3515;
	local[0] = NIL;
KEY3515:
	if (n & (1<<1)) goto KEY3516;
	local[1] = makeint((eusinteger_t)2L);
KEY3516:
	if (n & (1<<2)) goto KEY3517;
	local[2] = makeint((eusinteger_t)100L);
KEY3517:
	if (n & (1<<3)) goto KEY3518;
	local[8]= makeint((eusinteger_t)1L);
	local[9]= makeflt(2.9999999999999982236432e-01);
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)MKFLTVEC(ctx,3,local+8); /*float-vector*/
	local[3] = w;
KEY3518:
	if (n & (1<<4)) goto KEY3519;
	local[8]= makeint((eusinteger_t)1L);
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)MKFLTVEC(ctx,3,local+8); /*float-vector*/
	local[4] = w;
KEY3519:
	if (n & (1<<5)) goto KEY3520;
	local[5] = NIL;
KEY3520:
	if (n & (1<<6)) goto KEY3521;
	local[8]= argv[0];
	local[9]= fqv[157];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[6] = w;
KEY3521:
	if (n & (1<<7)) goto KEY3522;
	local[8]= argv[0];
	local[9]= fqv[215];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[7] = w;
KEY3522:
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,CLO3523,env,argv,local);
	local[9]= local[7];
	local[10]= local[6];
	local[11]= loadglobal(fqv[216]);
	ctx->vsp=local+12;
	w=(pointer)COERCE(ctx,2,local+10); /*coerce*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)MAPCAR(ctx,3,local+8); /*mapcar*/
	if (local[0]==NIL) goto IF3524;
	local[8]= argv[2];
	local[9]= fqv[217];
	local[10]= fqv[218];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	goto IF3525;
IF3524:
	local[8]= NIL;
IF3525:
	w = local[8];
	local[0]= w;
BLK3514:
	ctx->vsp=local; return(local[0]);}

/*:weight*/
static pointer M3526cascaded_link_weight(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3529;}
	local[0]= T;
ENT3529:
ENT3528:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3530;
	local[1]= argv[0];
	local[2]= fqv[80];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF3531;
IF3530:
	local[1]= NIL;
IF3531:
	local[1]= argv[0];
	local[2]= fqv[74];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[49];
	local[3]= fqv[47];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK3527:
	ctx->vsp=local; return(local[0]);}

/*:centroid*/
static pointer M3532cascaded_link_centroid(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3535;}
	local[0]= T;
ENT3535:
ENT3534:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3536;
	local[1]= argv[0];
	local[2]= fqv[80];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF3537;
IF3536:
	local[1]= NIL;
IF3537:
	local[1]= argv[0];
	local[2]= fqv[74];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[49];
	local[3]= fqv[51];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK3533:
	ctx->vsp=local; return(local[0]);}

/*:inertia-tensor*/
static pointer M3538cascaded_link_inertia_tensor(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3541;}
	local[0]= T;
ENT3541:
ENT3540:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3542;
	local[1]= argv[0];
	local[2]= fqv[80];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF3543;
IF3542:
	local[1]= NIL;
IF3543:
	local[1]= argv[0];
	local[2]= fqv[74];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[49];
	local[3]= fqv[50];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK3539:
	ctx->vsp=local; return(local[0]);}

/*:preview-control-dynamics-filter*/
static pointer M3544cascaded_link_preview_control_dynamics_filter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[219], &argv[4], n-4, local+0, 0);
	if (n & (1<<0)) goto KEY3546;
	local[0] = loadglobal(fqv[220]);
KEY3546:
	if (n & (1<<1)) goto KEY3547;
	local[1] = fqv[221];
KEY3547:
	if (n & (1<<2)) goto KEY3548;
	local[2] = makeflt(7.9999999999999982236432e-01);
KEY3548:
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,FLET3549,env,argv,local);
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w = local[3];
	ctx->vsp=local+5;
	w=FLET3549(ctx,1,local+4,w);
	local[4]= loadglobal(fqv[222]);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= local[4];
	local[6]= fqv[223];
	local[7]= argv[2];
	local[8]= argv[0];
	local[9]= fqv[30];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	local[9]= fqv[224];
	local[10]= local[2];
	local[11]= fqv[225];
	local[12]= T;
	local[13]= fqv[226];
	local[14]= local[0];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,10,local+5); /*send*/
	w = local[4];
	local[4]= w;
	local[5]= NIL;
	local[6]= makeint((eusinteger_t)0L);
	local[7]= makeint((eusinteger_t)2L);
WHL3552:
	local[8]= local[6];
	w = local[7];
	if ((eusinteger_t)local[8] >= (eusinteger_t)w) goto WHX3553;
	local[8]= argv[0];
	local[9]= fqv[227];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[6] = w;
	goto WHL3552;
WHX3553:
	local[8]= NIL;
BLK3554:
	w = NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= argv[3];
	ctx->vsp=local+12;
	w=(pointer)COPYOBJ(ctx,1,local+11); /*copy-object*/
	local[11]= w;
WHL3555:
	local[12]= local[4];
	local[13]= fqv[228];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	if (w!=NIL) goto WHX3556;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[12];
	local[10] = w;
	if (local[10]==NIL) goto IF3559;
	local[12]= local[10];
	w = local[3];
	ctx->vsp=local+13;
	w=FLET3549(ctx,1,local+12,w);
	local[7] = local[10];
	local[12]= local[7];
	goto IF3560;
IF3559:
	local[12]= local[7];
	w = local[3];
	ctx->vsp=local+13;
	w=FLET3549(ctx,1,local+12,w);
	local[12]= w;
IF3560:
	local[12]= argv[0];
	local[13]= fqv[227];
	local[14]= argv[0];
	local[15]= fqv[160];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,2,local+14); /*send*/
	local[14]= w;
	local[15]= argv[0];
	local[16]= fqv[68];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
	local[16]= fqv[167];
	local[17]= argv[2];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,6,local+12); /*send*/
	local[12]= w;
	local[13]= fqv[204];
	w = local[10];
	w=memq(local[13],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	if (local[13]==NIL) goto IF3561;
	local[9] = local[13];
	local[14]= local[9];
	goto IF3562;
IF3561:
	local[14]= local[9];
IF3562:
	w = local[14];
	local[13]= w;
	local[14]= local[12];
	local[15]= local[13];
	ctx->vsp=local+16;
	w=(pointer)VMINUS(ctx,2,local+14); /*v-*/
	local[14]= w;
	local[15]= local[4];
	local[16]= fqv[229];
	if (local[10]==NIL) goto IF3563;
	local[17]= local[14];
	goto IF3564;
IF3563:
	local[17]= NIL;
IF3564:
	local[18]= local[10];
	local[19]= local[12];
	local[20]= argv[0];
	local[21]= fqv[30];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,2,local+20); /*send*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)COPYOBJ(ctx,1,local+20); /*copy-object*/
	local[20]= w;
	local[21]= local[13];
	ctx->vsp=local+22;
	w=(pointer)LIST(ctx,4,local+18); /*list*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,4,local+15); /*send*/
	local[5] = w;
	if (local[5]==NIL) goto IF3565;
	local[15]= local[4];
	local[16]= fqv[230];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
	local[16]= local[5];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,2,local+15); /*list*/
	local[15]= w;
	w = local[6];
	ctx->vsp=local+16;
	local[6] = cons(ctx,local[15],w);
	local[15]= argv[0];
	local[16]= fqv[160];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
	local[16]= argv[0];
	local[17]= fqv[68];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,2,local+16); /*send*/
	local[16]= w;
	local[17]= local[4];
	local[18]= fqv[230];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17]= (w)->c.cons.car;
	w = local[3];
	ctx->vsp=local+18;
	w=FLET3549(ctx,1,local+17,w);
	local[17]= local[1];
	local[18]= local[17];
	if (fqv[231]!=local[18]) goto IF3568;
	local[18]= argv[0];
	local[19]= fqv[231];
	local[20]= fqv[232];
	local[21]= fqv[233];
	local[22]= fqv[234];
	local[23]= makeflt(9.9999999999999977795540e-02);
	local[24]= fqv[235];
	local[25]= argv[0];
	local[26]= fqv[30];
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,2,local+25); /*send*/
	local[25]= w;
	local[26]= local[4];
	local[27]= fqv[236];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,2,local+26); /*send*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)VMINUS(ctx,2,local+25); /*v-*/
	local[25]= w;
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,8,local+18); /*send*/
	local[18]= w;
	goto IF3569;
IF3568:
	local[18]= local[17];
	if (fqv[221]!=local[18]) goto IF3570;
	ctx->vsp=local+18;
	local[18]= makeclosure(codevec,quotevec,CLO3572,env,argv,local);
	local[19]= fqv[237];
	ctx->vsp=local+20;
	w=(pointer)MAPCAR(ctx,2,local+18); /*mapcar*/
	local[18]= w;
	local[19]= argv[0];
	local[20]= fqv[238];
	local[21]= local[4];
	local[22]= fqv[236];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,2,local+21); /*send*/
	local[21]= w;
	local[22]= makeint((eusinteger_t)0L);
	ctx->vsp=local+23;
	w=(pointer)ELT(ctx,2,local+21); /*elt*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)MINUS(ctx,1,local+21); /*-*/
	local[21]= w;
	local[22]= local[4];
	local[23]= fqv[236];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,2,local+22); /*send*/
	local[22]= w;
	local[23]= makeint((eusinteger_t)1L);
	ctx->vsp=local+24;
	w=(pointer)ELT(ctx,2,local+22); /*elt*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)MINUS(ctx,1,local+22); /*-*/
	local[22]= w;
	local[23]= makeint((eusinteger_t)0L);
	ctx->vsp=local+24;
	w=(pointer)MKFLTVEC(ctx,3,local+21); /*float-vector*/
	local[21]= w;
	local[22]= fqv[239];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,4,local+19); /*send*/
	ctx->vsp=local+19;
	local[19]= makeclosure(codevec,quotevec,CLO3573,env,argv,local);
	local[20]= fqv[240];
	local[21]= local[18];
	ctx->vsp=local+22;
	w=(pointer)MAPCAR(ctx,3,local+19); /*mapcar*/
	local[18]= w;
	goto IF3571;
IF3570:
	local[18]= NIL;
IF3571:
IF3569:
	w = local[18];
	local[17]= fqv[160];
	local[18]= argv[0];
	local[19]= fqv[160];
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,2,local+18); /*send*/
	local[18]= w;
	local[19]= fqv[166];
	local[20]= argv[0];
	local[21]= fqv[74];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,2,local+20); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	local[21]= fqv[68];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,2,local+20); /*send*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)LIST(ctx,4,local+17); /*list*/
	local[17]= w;
	w = local[8];
	ctx->vsp=local+18;
	local[8] = cons(ctx,local[17],w);
	local[17]= argv[0];
	local[18]= fqv[160];
	local[19]= local[15];
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,3,local+17); /*send*/
	local[17]= argv[0];
	local[18]= fqv[241];
	local[19]= local[16];
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,3,local+17); /*send*/
	local[15]= w;
	goto IF3566;
IF3565:
	local[15]= NIL;
IF3566:
	w = local[15];
	goto WHL3555;
WHX3556:
	local[12]= NIL;
BLK3557:
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(pointer)REVERSE(ctx,1,local+12); /*reverse*/
	local[8] = w;
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)REVERSE(ctx,1,local+12); /*reverse*/
	local[6] = w;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w = local[3];
	ctx->vsp=local+13;
	w=FLET3549(ctx,1,local+12,w);
	local[12]= makeint((eusinteger_t)0L);
	local[13]= makeint((eusinteger_t)2L);
WHL3575:
	local[14]= local[12];
	w = local[13];
	if ((eusinteger_t)local[14] >= (eusinteger_t)w) goto WHX3576;
	local[14]= argv[0];
	local[15]= fqv[227];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,2,local+14); /*send*/
	local[14]= local[12];
	ctx->vsp=local+15;
	w=(pointer)ADD1(ctx,1,local+14); /*1+*/
	local[12] = w;
	goto WHL3575;
WHX3576:
	local[14]= NIL;
BLK3577:
	w = NIL;
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(*ftab[21])(ctx,1,local+12,&ftab[21],fqv[242]); /*objects*/
	local[12]= argv[2];
	ctx->vsp=local+13;
	w=(pointer)MINUS(ctx,1,local+12); /*-*/
	local[12]= w;
	ctx->vsp=local+13;
	local[13]= makeclosure(codevec,quotevec,CLO3578,env,argv,local);
	local[14]= local[8];
	local[15]= local[6];
	ctx->vsp=local+16;
	w=(pointer)MAPCAR(ctx,3,local+13); /*mapcar*/
	local[13]= w;
	ctx->vsp=local+14;
	local[14]= makeclosure(codevec,quotevec,CLO3579,env,argv,local);
	local[15]= local[8];
	local[16]= local[13];
	ctx->vsp=local+17;
	w=(pointer)MAPCAR(ctx,3,local+14); /*mapcar*/
	local[0]= w;
BLK3545:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3404(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[120];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[243];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= makeflt(1.0000000000000000208167e-03);
	local[1]= argv[2];
	local[2]= fqv[5];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SCALEVEC(ctx,2,local+0); /*scale*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+0); /*v**/
	local[0]= w;
	local[1]= argv[2];
	local[2]= fqv[120];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[244];
	local[3]= argv[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)VPLUS(ctx,2,local+3); /*v+*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3425(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[181];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3426(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[46];
	local[2]= fqv[136];
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[46];
	local[2]= fqv[134];
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3431(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[243];
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[244];
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3436(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[181];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET3439(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeflt(5.0000000000000000000000e-01);
	local[1]= argv[0];
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,3,local+1); /*aref*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= makeint((eusinteger_t)1L);
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,3,local+2); /*aref*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= makeint((eusinteger_t)2L);
	local[5]= makeint((eusinteger_t)2L);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,3,local+3); /*aref*/
	local[3]= w;
	local[4]= makeint((eusinteger_t)-1L);
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,4,local+1); /*+*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= local[0];
	local[2]= makeint((eusinteger_t)1L);
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)ABS(ctx,1,local+1); /*abs*/
	local[1]= w;
	local[2]= makeflt(0.0000000000000000000000e+00);
	local[3]= makeflt(9.9999999999999949376344e-21);
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,3,local+1,&ftab[4],fqv[22]); /*eps=*/
	if (w==NIL) goto IF3580;
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	local[1]= w;
	goto IF3581;
IF3580:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[22])(ctx,1,local+1,&ftab[22],fqv[245]); /*acos*/
	local[1]= w;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)SIN(ctx,1,local+2); /*sin*/
	local[2]= w;
	local[3]= local[2];
	local[4]= makeflt(9.9999999999999949376344e-21);
	ctx->vsp=local+5;
	w=(pointer)LESSP(ctx,2,local+3); /*<*/
	if (w==NIL) goto IF3582;
	local[3]= local[1];
	local[4]= makeflt(5.0000000000000000000000e-01);
	local[5]= argv[0];
	local[6]= makeint((eusinteger_t)0L);
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,3,local+5); /*aref*/
	local[5]= w;
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SQRT(ctx,1,local+3); /*sqrt*/
	local[3]= w;
	local[4]= local[1];
	local[5]= makeflt(5.0000000000000000000000e-01);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)1L);
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SQRT(ctx,1,local+4); /*sqrt*/
	local[4]= w;
	local[5]= local[1];
	local[6]= makeflt(5.0000000000000000000000e-01);
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)2L);
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SQRT(ctx,1,local+5); /*sqrt*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[3]= w;
	goto IF3583;
IF3582:
	local[3]= makeflt(-5.0000000000000000000000e-01);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	local[4]= local[3];
	local[5]= argv[0];
	local[6]= makeint((eusinteger_t)1L);
	local[7]= makeint((eusinteger_t)2L);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,3,local+5); /*aref*/
	local[5]= w;
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)2L);
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	local[5]= local[3];
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)2L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	local[6]= local[3];
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	local[8]= argv[0];
	local[9]= makeint((eusinteger_t)1L);
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,2,local+7); /*-*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[3]= w;
IF3583:
	w = local[3];
	local[1]= w;
IF3581:
	w = local[1];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3464(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= fqv[91];
	local[2]= argv[0];
	local[3]= fqv[120];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3467(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	w=(*ftab[23])(ctx,0,local+0,&ftab[23],fqv[246]); /*make-coords*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3468(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[43]);
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)CONCATENATE(ctx,3,local+0); /*concatenate*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3485(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[243];
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[244];
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3502(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[43]);
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)CONCATENATE(ctx,3,local+0); /*concatenate*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3523(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= fqv[155];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[77];
	local[3]= fqv[2];
	local[4]= *(ovafptr(argv[0],fqv[60]));
	local[5]= local[4];
	if (fqv[61]!=local[5]) goto IF3585;
	local[5]= fqv[247];
	goto IF3586;
IF3585:
	local[5]= local[4];
	if (fqv[63]!=local[5]) goto IF3587;
	local[5]= fqv[248];
	goto IF3588;
IF3587:
	local[5]= local[4];
	if (fqv[65]!=local[5]) goto IF3589;
	local[5]= fqv[249];
	goto IF3590;
IF3589:
	local[5]= local[4];
	if (fqv[62]!=local[5]) goto IF3591;
	local[5]= fqv[250];
	goto IF3592;
IF3591:
	local[5]= local[4];
	if (fqv[64]!=local[5]) goto IF3593;
	local[5]= fqv[251];
	goto IF3594;
IF3593:
	local[5]= local[4];
	if (fqv[66]!=local[5]) goto IF3595;
	local[5]= fqv[252];
	goto IF3596;
IF3595:
	if (T==NIL) goto IF3597;
	local[5]= *(ovafptr(argv[0],fqv[60]));
	goto IF3598;
IF3597:
	local[5]= NIL;
IF3598:
IF3596:
IF3594:
IF3592:
IF3590:
IF3588:
IF3586:
	w = local[5];
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)VINNERPRODUCT(ctx,2,local+2); /*v.*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[22])(ctx,1,local+2,&ftab[22],fqv[245]); /*acos*/
	local[2]= w;
	local[3]= local[2];
	local[4]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[22]); /*eps=*/
	if (w==NIL) goto IF3599;
	local[3]= makeint((eusinteger_t)3L);
	ctx->vsp=local+4;
	w=(*ftab[14])(ctx,1,local+3,&ftab[14],fqv[184]); /*unit-matrix*/
	local[3]= w;
	goto IF3600;
IF3599:
	local[3]= local[2];
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)0L);
	local[6]= local[0];
	local[7]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+8;
	w=(pointer)GREATERP(ctx,2,local+6); /*>*/
	if (w==NIL) goto IF3601;
	local[6]= makeflt(1.0000000000000000000000e+00);
	goto IF3602;
IF3601:
	local[6]= makeflt(-1.0000000000000000000000e+00);
IF3602:
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+4); /*v**/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+3); /*rotation-matrix*/
	local[3]= w;
IF3600:
	local[4]= env->c.clo.env2[1];
	local[5]= env->c.clo.env2[3];
	if (local[3]!=NIL) goto IF3603;
	local[6]= makeint((eusinteger_t)3L);
	ctx->vsp=local+7;
	w=(*ftab[14])(ctx,1,local+6,&ftab[14],fqv[184]); /*unit-matrix*/
	local[3] = w;
	local[6]= local[3];
	goto IF3604;
IF3603:
	local[6]= NIL;
IF3604:
	if (env->c.clo.env2[5]==NIL) goto IF3605;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)ABS(ctx,1,local+6); /*abs*/
	local[6]= w;
	local[7]= env->c.clo.env2[5];
	ctx->vsp=local+8;
	w=(pointer)GREATERP(ctx,2,local+6); /*>*/
	if (w==NIL) goto IF3605;
	local[6]= makeint((eusinteger_t)2L);
	local[7]= env->c.clo.env2[1];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	env->c.clo.env2[1] = w;
	env->c.clo.env2[3] = env->c.clo.env2[4];
	local[6]= env->c.clo.env2[3];
	goto IF3606;
IF3605:
	local[6]= NIL;
IF3606:
	local[6]= env->c.clo.env1[2];
	local[7]= fqv[217];
	local[8]= fqv[253];
	local[9]= env->c.clo.env2[1];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[6]= env->c.clo.env1[2];
	local[7]= fqv[217];
	local[8]= fqv[106];
	local[9]= env->c.clo.env2[3];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[6]= env->c.clo.env1[2];
	local[7]= fqv[254];
	local[8]= fqv[255];
	local[9]= argv[0];
	local[10]= fqv[77];
	local[11]= fqv[5];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= w;
	local[10]= fqv[256];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(*ftab[23])(ctx,4,local+8,&ftab[23],fqv[246]); /*make-coords*/
	local[8]= w;
	local[9]= fqv[257];
	local[10]= env->c.clo.env2[2];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)ABS(ctx,1,local+11); /*abs*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	local[11]= fqv[258];
	local[12]= T;
	local[13]= fqv[259];
	local[14]= makeint((eusinteger_t)330L);
	ctx->vsp=local+15;
	w=(*ftab[24])(ctx,1,local+14,&ftab[24],fqv[260]); /*deg2rad*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,9,local+6); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET3549(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= fqv[160];
	local[2]= fqv[160];
	w = argv[0];
	w=memq(local[2],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= env->c.clo.env1[0];
	local[1]= fqv[261];
	local[2]= fqv[166];
	w = argv[0];
	w=memq(local[2],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= env->c.clo.env1[0];
	local[4]= fqv[74];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3572(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= argv[0];
	local[2]= fqv[262];
	local[3]= fqv[68];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3573(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= argv[0];
	local[2]= fqv[263];
	local[3]= argv[1];
	local[4]= fqv[264];
	local[5]= makeflt(9.9999999999999977795540e-02);
	local[6]= fqv[265];
	local[7]= makeflt(9.9999999999999977795540e-02);
	ctx->vsp=local+8;
	w=(*ftab[24])(ctx,1,local+7,&ftab[24],fqv[260]); /*deg2rad*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,8,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3578(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	w = env->c.clo.env2[3];
	ctx->vsp=local+1;
	w=FLET3549(ctx,1,local+0,w);
	local[0]= env->c.clo.env1[0];
	local[1]= fqv[227];
	local[2]= env->c.clo.env1[0];
	local[3]= fqv[160];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= env->c.clo.env1[0];
	local[4]= fqv[68];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= fqv[167];
	local[5]= env->c.clo.env1[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	local[0]= w;
	local[1]= loadglobal(fqv[266]);
	local[2]= fqv[267];
	local[3]= fqv[218];
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[268];
	local[3]= fqv[218];
	local[4]= NIL;
	local[5]= fqv[108];
	local[6]= makeint((eusinteger_t)400L);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= env->c.clo.env1[0];
	local[2]= fqv[30];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[268];
	local[3]= fqv[218];
	local[4]= NIL;
	local[5]= fqv[108];
	local[6]= makeint((eusinteger_t)300L);
	local[7]= fqv[106];
	local[8]= fqv[269];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,8,local+1); /*send*/
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[268];
	local[3]= fqv[218];
	local[4]= NIL;
	local[5]= fqv[108];
	local[6]= makeint((eusinteger_t)400L);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= local[0];
	local[2]= fqv[268];
	local[3]= fqv[218];
	local[4]= T;
	local[5]= fqv[108];
	local[6]= makeint((eusinteger_t)300L);
	local[7]= fqv[106];
	local[8]= fqv[270];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,8,local+1); /*send*/
	ctx->vsp=local+1;
	w=(*ftab[25])(ctx,0,local+1,&ftab[25],fqv[271]); /*x::window-main-one*/
	local[1]= makeint((eusinteger_t)10000L);
	ctx->vsp=local+2;
	w=(*ftab[26])(ctx,1,local+1,&ftab[26],fqv[272]); /*unix:usleep*/
	local[1]= env->c.clo.env2[12];
	local[2]= env->c.clo.env1[2];
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	env->c.clo.env2[12] = w;
	local[1]= fqv[273];
	local[2]= env->c.clo.env2[12];
	local[3]= fqv[274];
	local[4]= local[0];
	local[5]= fqv[275];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= fqv[276];
	local[8]= env->c.clo.env1[0];
	local[9]= fqv[30];
	local[10]= NIL;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	local[9]= fqv[277];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	w=(*ftab[27])(ctx,1,local+10,&ftab[27],fqv[278]); /*cadddr*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,10,local+1); /*list*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3579(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3607riccati_equation_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=7) maerror();
	argv[0]->c.obj.iv[1] = argv[2];
	argv[0]->c.obj.iv[2] = argv[3];
	argv[0]->c.obj.iv[3] = argv[4];
	argv[0]->c.obj.iv[5] = argv[5];
	argv[0]->c.obj.iv[6] = argv[6];
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(*ftab[28])(ctx,2,local+0,&ftab[28],fqv[279]); /*array-dimension*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= makeint((eusinteger_t)1L);
	ctx->vsp=local+3;
	w=(*ftab[28])(ctx,2,local+1,&ftab[28],fqv[279]); /*array-dimension*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,2,local+0,&ftab[5],fqv[24]); /*make-matrix*/
	argv[0]->c.obj.iv[4] = w;
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK3608:
	ctx->vsp=local; return(local[0]);}

/*:solve*/
static pointer M3609riccati_equation_solve(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)TRANSPOSE(ctx,1,local+1); /*transpose*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)TRANSPOSE(ctx,1,local+2); /*transpose*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+4;
	w=(pointer)TRANSPOSE(ctx,1,local+3); /*transpose*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= makeint((eusinteger_t)1L);
	ctx->vsp=local+6;
	w=(*ftab[28])(ctx,2,local+4,&ftab[28],fqv[279]); /*array-dimension*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[3];
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(*ftab[28])(ctx,2,local+5,&ftab[28],fqv[279]); /*array-dimension*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[5])(ctx,2,local+4,&ftab[5],fqv[24]); /*make-matrix*/
	local[4]= w;
	local[5]= makeint((eusinteger_t)0L);
TAG3613:
	local[6]= local[5];
	local[7]= makeint((eusinteger_t)10000L);
	ctx->vsp=local+8;
	w=(pointer)GREQP(ctx,2,local+6); /*>=*/
	if (w==NIL) goto IF3614;
	w = NIL;
	ctx->vsp=local+6;
	local[5]=w;
	goto BLK3612;
	goto IF3615;
IF3614:
	local[6]= NIL;
IF3615:
	local[6]= argv[0]->c.obj.iv[4];
	local[7]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+8;
	w=(pointer)MATTIMES(ctx,2,local+6); /*m**/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[6];
	local[8]= argv[0]->c.obj.iv[2];
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(*ftab[28])(ctx,2,local+8,&ftab[28],fqv[279]); /*array-dimension*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[14])(ctx,1,local+8,&ftab[14],fqv[184]); /*unit-matrix*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[2])(ctx,2,local+7,&ftab[2],fqv[4]); /*scale-matrix*/
	local[7]= w;
	local[8]= local[2];
	local[9]= argv[0]->c.obj.iv[4];
	local[10]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+11;
	w=(pointer)MATTIMES(ctx,2,local+9); /*m**/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MATTIMES(ctx,2,local+8); /*m**/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[6])(ctx,2,local+7,&ftab[6],fqv[27]); /*m+*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[17])(ctx,1,local+7,&ftab[17],fqv[187]); /*inverse-matrix*/
	argv[0]->c.obj.iv[9] = w;
	local[7]= argv[0]->c.obj.iv[9];
	local[8]= local[2];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)MATTIMES(ctx,2,local+8); /*m**/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MATTIMES(ctx,2,local+7); /*m**/
	argv[0]->c.obj.iv[7] = w;
	local[7]= local[1];
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)MATTIMES(ctx,2,local+7); /*m**/
	local[7]= w;
	local[8]= local[3];
	local[9]= argv[0]->c.obj.iv[5];
	local[10]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+11;
	w=(*ftab[2])(ctx,2,local+9,&ftab[2],fqv[4]); /*scale-matrix*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MATTIMES(ctx,2,local+8); /*m**/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[6])(ctx,2,local+7,&ftab[6],fqv[27]); /*m+*/
	local[7]= w;
	local[8]= local[1];
	local[9]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+10;
	w=(pointer)MATTIMES(ctx,2,local+8); /*m**/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+10;
	w=(pointer)MATTIMES(ctx,2,local+8); /*m**/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+10;
	w=(pointer)MATTIMES(ctx,2,local+8); /*m**/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[16])(ctx,2,local+7,&ftab[16],fqv[186]); /*m-*/
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[4];
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(*ftab[16])(ctx,2,local+8,&ftab[16],fqv[186]); /*m-*/
	local[0] = w;
	local[8]= local[0]->c.obj.iv[1];
	local[9]= local[4]->c.obj.iv[1];
	local[10]= loadglobal(fqv[280]);
	local[11]= makeflt(9.9999999999999950039964e-03);
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[29])(ctx,3,local+8,&ftab[29],fqv[281]); /*eps-v=*/
	if (w==NIL) goto IF3616;
	local[8]= argv[0]->c.obj.iv[1];
	local[9]= argv[0]->c.obj.iv[2];
	local[10]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+11;
	w=(pointer)MATTIMES(ctx,2,local+9); /*m**/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[16])(ctx,2,local+8,&ftab[16],fqv[186]); /*m-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)TRANSPOSE(ctx,1,local+8); /*transpose*/
	argv[0]->c.obj.iv[8] = w;
	local[8]= argv[0]->c.obj.iv[4];
	local[9]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,2,local+8); /*list*/
	ctx->vsp=local+8;
	local[0]=w;
	goto BLK3610;
	goto IF3617;
IF3616:
	local[8]= NIL;
IF3617:
	argv[0]->c.obj.iv[4] = local[7];
	w = argv[0]->c.obj.iv[4];
	local[6]= local[5];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[6]= w;
	local[5] = local[6];
	w = NIL;
	ctx->vsp=local+6;
	goto TAG3613;
	w = NIL;
	local[5]= w;
BLK3612:
	local[5]= fqv[282];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,2,local+5,&ftab[0],fqv[1]); /*warn*/
	local[0]= w;
BLK3610:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3619preview_controller_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[283], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY3621;
	local[0] = NIL;
KEY3621:
	if (n & (1<<1)) goto KEY3622;
	local[1] = NIL;
KEY3622:
	if (n & (1<<2)) goto KEY3623;
	local[2] = NIL;
KEY3623:
	if (n & (1<<3)) goto KEY3624;
	local[3] = NIL;
KEY3624:
	if (n & (1<<4)) goto KEY3625;
	local[4] = NIL;
KEY3625:
	if (n & (1<<5)) goto KEY3626;
	local[5] = NIL;
KEY3626:
	if (n & (1<<6)) goto KEY3627;
	local[12]= local[3];
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(*ftab[28])(ctx,2,local+12,&ftab[28],fqv[279]); /*array-dimension*/
	local[6] = w;
KEY3627:
	if (n & (1<<7)) goto KEY3628;
	local[12]= local[5];
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(*ftab[28])(ctx,2,local+12,&ftab[28],fqv[279]); /*array-dimension*/
	local[7] = w;
KEY3628:
	if (n & (1<<8)) goto KEY3629;
	local[12]= local[4];
	local[13]= makeint((eusinteger_t)1L);
	ctx->vsp=local+14;
	w=(*ftab[28])(ctx,2,local+12,&ftab[28],fqv[279]); /*array-dimension*/
	local[8] = w;
KEY3629:
	if (n & (1<<9)) goto KEY3630;
	local[12]= loadglobal(fqv[43]);
	local[13]= local[3];
	local[14]= makeint((eusinteger_t)0L);
	ctx->vsp=local+15;
	w=(*ftab[28])(ctx,2,local+13,&ftab[28],fqv[279]); /*array-dimension*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)INSTANTIATE(ctx,2,local+12); /*instantiate*/
	local[9] = w;
KEY3630:
	if (n & (1<<10)) goto KEY3631;
	local[12]= local[4];
	local[13]= makeint((eusinteger_t)1L);
	ctx->vsp=local+14;
	w=(*ftab[28])(ctx,2,local+12,&ftab[28],fqv[279]); /*array-dimension*/
	local[12]= w;
	local[13]= makeint((eusinteger_t)1L);
	ctx->vsp=local+14;
	w=(*ftab[5])(ctx,2,local+12,&ftab[5],fqv[24]); /*make-matrix*/
	local[10] = w;
KEY3631:
	if (n & (1<<11)) goto KEY3632;
	local[11] = NIL;
KEY3632:
	local[12]= local[2];
	local[13]= argv[2];
	ctx->vsp=local+14;
	w=(pointer)QUOTIENT(ctx,2,local+12); /*/*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)ROUND(ctx,1,local+12); /*round*/
	argv[0]->c.obj.iv[12] = w;
	argv[0]->c.obj.iv[16] = local[11];
	argv[0]->c.obj.iv[20] = local[7];
	argv[0]->c.obj.iv[21] = local[8];
	local[12]= argv[0];
	local[13]= *(ovafptr(argv[1],fqv[284]));
	local[14]= fqv[223];
	local[15]= local[3];
	local[16]= local[4];
	local[17]= local[5];
	local[18]= local[0];
	local[19]= local[1];
	ctx->vsp=local+20;
	w=(pointer)SENDMESSAGE(ctx,8,local+12); /*send-message*/
	argv[0]->c.obj.iv[15] = makeint((eusinteger_t)0L);
	if (argv[0]->c.obj.iv[10]!=NIL) goto IF3633;
	local[12]= local[6];
	local[13]= makeint((eusinteger_t)1L);
	ctx->vsp=local+14;
	w=(*ftab[5])(ctx,2,local+12,&ftab[5],fqv[24]); /*make-matrix*/
	argv[0]->c.obj.iv[10] = w;
	local[12]= makeint((eusinteger_t)0L);
	local[13]= local[6];
WHL3636:
	local[14]= local[12];
	w = local[13];
	if ((eusinteger_t)local[14] >= (eusinteger_t)w) goto WHX3637;
	local[14]= argv[0]->c.obj.iv[10];
	local[15]= local[12];
	local[16]= makeint((eusinteger_t)0L);
	local[17]= local[9];
	local[18]= local[12];
	ctx->vsp=local+19;
	w=(pointer)ELT(ctx,2,local+17); /*elt*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)ASET(ctx,4,local+14); /*aset*/
	local[14]= local[12];
	ctx->vsp=local+15;
	w=(pointer)ADD1(ctx,1,local+14); /*1+*/
	local[12] = w;
	goto WHL3636;
WHX3637:
	local[14]= NIL;
BLK3638:
	w = NIL;
	local[12]= w;
	goto IF3634;
IF3633:
	local[12]= NIL;
IF3634:
	argv[0]->c.obj.iv[11] = local[10];
	local[12]= argv[0];
	local[13]= fqv[285];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[12]= argv[0];
	local[13]= fqv[286];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	w = argv[0];
	local[0]= w;
BLK3620:
	ctx->vsp=local; return(local[0]);}

/*:calc-f*/
static pointer M3639preview_controller_calc_f(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[21];
	local[1]= argv[0]->c.obj.iv[20];
	local[2]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,2,local+0,&ftab[5],fqv[24]); /*make-matrix*/
	argv[0]->c.obj.iv[13] = w;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(*ftab[28])(ctx,2,local+0,&ftab[28],fqv[279]); /*array-dimension*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[14])(ctx,1,local+0,&ftab[14],fqv[184]); /*unit-matrix*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSPOSE(ctx,1,local+1); /*transpose*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+3;
	w=(pointer)TRANSPOSE(ctx,1,local+2); /*transpose*/
	local[2]= w;
	local[3]= makeint((eusinteger_t)0L);
	local[4]= argv[0]->c.obj.iv[12];
WHL3642:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX3643;
	local[5]= argv[0]->c.obj.iv[5];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(*ftab[2])(ctx,2,local+5,&ftab[2],fqv[4]); /*scale-matrix*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[9];
	local[7]= local[1];
	local[8]= local[0];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)MATTIMES(ctx,2,local+8); /*m**/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MATTIMES(ctx,2,local+7); /*m**/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MATTIMES(ctx,2,local+6); /*m**/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[8];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)MATTIMES(ctx,2,local+7); /*m**/
	local[0] = w;
	local[7]= makeint((eusinteger_t)0L);
	local[8]= argv[0]->c.obj.iv[21];
WHL3646:
	local[9]= local[7];
	w = local[8];
	if ((eusinteger_t)local[9] >= (eusinteger_t)w) goto WHX3647;
	local[9]= makeint((eusinteger_t)0L);
	local[10]= argv[0]->c.obj.iv[20];
WHL3650:
	local[11]= local[9];
	w = local[10];
	if ((eusinteger_t)local[11] >= (eusinteger_t)w) goto WHX3651;
	local[11]= argv[0]->c.obj.iv[13];
	local[12]= local[7];
	local[13]= argv[0]->c.obj.iv[20];
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(pointer)ADD1(ctx,1,local+14); /*1+*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)TIMES(ctx,2,local+13); /***/
	local[13]= w;
	local[14]= local[9];
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,2,local+13); /*+*/
	local[13]= w;
	local[14]= local[6];
	local[15]= local[7];
	local[16]= local[9];
	ctx->vsp=local+17;
	w=(pointer)AREF(ctx,3,local+14); /*aref*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)ASET(ctx,4,local+11); /*aset*/
	local[11]= local[9];
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[9] = w;
	goto WHL3650;
WHX3651:
	local[11]= NIL;
BLK3652:
	w = NIL;
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	local[7] = w;
	goto WHL3646;
WHX3647:
	local[9]= NIL;
BLK3648:
	w = NIL;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL3642;
WHX3643:
	local[5]= NIL;
BLK3644:
	w = NIL;
	local[0]= w;
BLK3640:
	ctx->vsp=local; return(local[0]);}

/*:calc-u*/
static pointer M3653preview_controller_calc_u(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+2;
	w=(pointer)MATTIMES(ctx,2,local+0); /*m**/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[7];
	local[2]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+3;
	w=(pointer)MATTIMES(ctx,2,local+1); /*m**/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[186]); /*m-*/
	argv[0]->c.obj.iv[11] = w;
	w = argv[0]->c.obj.iv[11];
	local[0]= w;
BLK3654:
	ctx->vsp=local; return(local[0]);}

/*:calc-xk*/
static pointer M3655preview_controller_calc_xk(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	w=(pointer)MATTIMES(ctx,2,local+0); /*m**/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= argv[0];
	local[3]= fqv[287];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MATTIMES(ctx,2,local+1); /*m**/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,2,local+0,&ftab[6],fqv[27]); /*m+*/
	argv[0]->c.obj.iv[10] = w;
	w = argv[0]->c.obj.iv[10];
	local[0]= w;
BLK3656:
	ctx->vsp=local; return(local[0]);}

/*:update-xk*/
static pointer M3657preview_controller_update_xk(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3660;}
	local[0]= NIL;
ENT3660:
ENT3659:
	if (n>4) maerror();
	if (argv[2]==NIL) goto IF3661;
	if (argv[0]->c.obj.iv[19]!=NIL) goto IF3663;
	local[1]= argv[0]->c.obj.iv[15];
	ctx->vsp=local+2;
	w=(pointer)ADD1(ctx,1,local+1); /*1+*/
	argv[0]->c.obj.iv[15] = w;
	local[1]= argv[0]->c.obj.iv[15];
	local[2]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)GREQP(ctx,2,local+1); /*>=*/
	argv[0]->c.obj.iv[19] = w;
	local[1]= argv[0]->c.obj.iv[19];
	goto IF3664;
IF3663:
	local[1]= NIL;
IF3664:
	if (argv[0]->c.obj.iv[14]!=NIL) goto IF3665;
	local[1]= argv[0]->c.obj.iv[20];
	local[2]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	local[2]= makeint((eusinteger_t)1L);
	ctx->vsp=local+3;
	w=(*ftab[5])(ctx,2,local+1,&ftab[5],fqv[24]); /*make-matrix*/
	argv[0]->c.obj.iv[14] = w;
	local[1]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+2;
	w=(pointer)ADD1(ctx,1,local+1); /*1+*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[18])(ctx,1,local+1,&ftab[18],fqv[198]); /*make-list*/
	argv[0]->c.obj.iv[17] = w;
	if (argv[0]->c.obj.iv[16]==NIL) goto IF3667;
	local[1]= makeint((eusinteger_t)0L);
	local[2]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[2]= w;
WHL3670:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX3671;
	local[3]= makeint((eusinteger_t)0L);
	local[4]= argv[0]->c.obj.iv[20];
WHL3674:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX3675;
	local[5]= argv[0]->c.obj.iv[14];
	local[6]= argv[0]->c.obj.iv[20];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	local[7]= makeint((eusinteger_t)0L);
	local[8]= argv[2];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL3674;
WHX3675:
	local[5]= NIL;
BLK3676:
	w = NIL;
	local[3]= argv[0]->c.obj.iv[17];
	local[4]= local[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SETELT(ctx,3,local+3); /*setelt*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL3670;
WHX3671:
	local[3]= NIL;
BLK3672:
	w = NIL;
	local[1]= w;
	goto IF3668;
IF3667:
	local[1]= NIL;
IF3668:
	goto IF3666;
IF3665:
	local[1]= NIL;
IF3666:
	if (argv[0]->c.obj.iv[16]!=NIL) goto IF3677;
	local[1]= argv[0]->c.obj.iv[15];
	local[2]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto IF3679;
	local[1]= makeint((eusinteger_t)0L);
	local[2]= argv[0]->c.obj.iv[20];
WHL3682:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX3683;
	local[3]= argv[0]->c.obj.iv[14];
	local[4]= argv[0]->c.obj.iv[20];
	local[5]= argv[0]->c.obj.iv[15];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	local[5]= makeint((eusinteger_t)0L);
	local[6]= argv[2];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,4,local+3); /*aset*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL3682;
WHX3683:
	local[3]= NIL;
BLK3684:
	w = NIL;
	local[1]= argv[0]->c.obj.iv[17];
	local[2]= argv[0]->c.obj.iv[15];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SETELT(ctx,3,local+1); /*setelt*/
	w = NIL;
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK3658;
	goto IF3680;
IF3679:
	local[1]= NIL;
IF3680:
	goto IF3678;
IF3677:
	local[1]= NIL;
IF3678:
	goto IF3662;
IF3661:
	local[1]= argv[0]->c.obj.iv[15];
	ctx->vsp=local+2;
	w=(pointer)SUB1(ctx,1,local+1); /*1-*/
	argv[0]->c.obj.iv[15] = w;
	local[1]= argv[0];
	local[2]= fqv[288];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	argv[2] = w;
	local[1]= argv[0]->c.obj.iv[15];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)LSEQP(ctx,2,local+1); /*<=*/
	if (w==NIL) goto IF3685;
	argv[0]->c.obj.iv[18] = T;
	local[1]= argv[0]->c.obj.iv[18];
	goto IF3686;
IF3685:
	local[1]= NIL;
IF3686:
IF3662:
	local[1]= makeint((eusinteger_t)0L);
	local[2]= argv[0]->c.obj.iv[12];
WHL3688:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX3689;
	local[3]= makeint((eusinteger_t)0L);
	local[4]= argv[0]->c.obj.iv[20];
WHL3692:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX3693;
	local[5]= argv[0]->c.obj.iv[14];
	local[6]= argv[0]->c.obj.iv[20];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	local[7]= makeint((eusinteger_t)0L);
	local[8]= argv[0]->c.obj.iv[14];
	local[9]= argv[0]->c.obj.iv[20];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL3692;
WHX3693:
	local[5]= NIL;
BLK3694:
	w = NIL;
	local[3]= argv[0]->c.obj.iv[17];
	local[4]= local[1];
	local[5]= argv[0]->c.obj.iv[17];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SETELT(ctx,3,local+3); /*setelt*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL3688;
WHX3689:
	local[3]= NIL;
BLK3690:
	w = NIL;
	local[1]= makeint((eusinteger_t)0L);
	local[2]= argv[0]->c.obj.iv[20];
WHL3696:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX3697;
	local[3]= argv[0]->c.obj.iv[14];
	local[4]= argv[0]->c.obj.iv[20];
	local[5]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	local[5]= makeint((eusinteger_t)0L);
	local[6]= argv[2];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,4,local+3); /*aset*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL3696;
WHX3697:
	local[3]= NIL;
BLK3698:
	w = NIL;
	local[1]= argv[0]->c.obj.iv[17];
	local[2]= argv[0]->c.obj.iv[12];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SETELT(ctx,3,local+1); /*setelt*/
	local[1]= argv[0];
	local[2]= fqv[289];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (argv[0]->c.obj.iv[19]==NIL) goto IF3699;
	if (argv[0]->c.obj.iv[18]!=NIL) goto IF3699;
	local[1]= argv[0];
	local[2]= fqv[290];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[291];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[292];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[1]= w;
	goto IF3700;
IF3699:
	local[1]= NIL;
IF3700:
	w = local[1];
	local[0]= w;
BLK3658:
	ctx->vsp=local; return(local[0]);}

/*:finishedp*/
static pointer M3701preview_controller_finishedp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[18];
	local[0]= w;
BLK3702:
	ctx->vsp=local; return(local[0]);}

/*:last-reference-output-vector*/
static pointer M3703preview_controller_last_reference_output_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[14];
	local[1]= argv[0]->c.obj.iv[20];
	local[2]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[20];
	local[3]= argv[0]->c.obj.iv[20];
	local[4]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SUBSEQ(ctx,3,local+0); /*subseq*/
	local[0]= w;
BLK3704:
	ctx->vsp=local; return(local[0]);}

/*:current-reference-output-vector*/
static pointer M3705preview_controller_current_reference_output_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[14];
	local[1]= makeint((eusinteger_t)0L);
	local[2]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+3;
	w=(pointer)SUBSEQ(ctx,3,local+0); /*subseq*/
	local[0]= w;
BLK3706:
	ctx->vsp=local; return(local[0]);}

/*:current-state-vector*/
static pointer M3707preview_controller_current_state_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[10];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(*ftab[30])(ctx,2,local+0,&ftab[30],fqv[293]); /*matrix-column*/
	local[0]= w;
BLK3708:
	ctx->vsp=local; return(local[0]);}

/*:current-output-vector*/
static pointer M3709preview_controller_current_output_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	w=(pointer)MATTIMES(ctx,2,local+0); /*m**/
	local[0]= w;
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(*ftab[30])(ctx,2,local+0,&ftab[30],fqv[293]); /*matrix-column*/
	local[0]= w;
BLK3710:
	ctx->vsp=local; return(local[0]);}

/*:current-additional-data*/
static pointer M3711preview_controller_current_additional_data(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK3712:
	ctx->vsp=local; return(local[0]);}

/*:pass-preview-controller*/
static pointer M3713preview_controller_pass_preview_controller(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
WHL3715:
	local[2]= argv[0];
	local[3]= fqv[229];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[4];
	local[4]= w;
	local[5]= NIL;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[0] = w;
	if (local[0]!=NIL) goto WHX3716;
	goto WHL3715;
WHX3716:
	local[2]= NIL;
BLK3717:
	local[2]= local[0];
	w = local[1];
	ctx->vsp=local+3;
	local[1] = cons(ctx,local[2],w);
WHL3719:
	local[2]= argv[0];
	local[3]= fqv[229];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[4];
	local[4]= w;
	local[5]= NIL;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[0] = w;
	if (local[0]==NIL) goto WHX3720;
	local[2]= local[0];
	w = local[1];
	ctx->vsp=local+3;
	local[1] = cons(ctx,local[2],w);
	goto WHL3719;
WHX3720:
	local[2]= NIL;
BLK3721:
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)REVERSE(ctx,1,local+2); /*reverse*/
	local[0]= w;
BLK3714:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3723extended_preview_controller_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[294], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY3725;
	local[0] = NIL;
KEY3725:
	if (n & (1<<1)) goto KEY3726;
	local[1] = NIL;
KEY3726:
	if (n & (1<<2)) goto KEY3727;
	local[2] = NIL;
KEY3727:
	if (n & (1<<3)) goto KEY3728;
	local[3] = NIL;
KEY3728:
	if (n & (1<<4)) goto KEY3729;
	local[4] = NIL;
KEY3729:
	if (n & (1<<5)) goto KEY3730;
	local[5] = NIL;
KEY3730:
	if (n & (1<<6)) goto KEY3731;
	local[11]= loadglobal(fqv[43]);
	local[12]= local[3];
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(*ftab[28])(ctx,2,local+12,&ftab[28],fqv[279]); /*array-dimension*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)INSTANTIATE(ctx,2,local+11); /*instantiate*/
	local[6] = w;
KEY3731:
	if (n & (1<<7)) goto KEY3732;
	local[11]= local[4];
	local[12]= makeint((eusinteger_t)1L);
	ctx->vsp=local+13;
	w=(*ftab[28])(ctx,2,local+11,&ftab[28],fqv[279]); /*array-dimension*/
	local[11]= w;
	local[12]= makeint((eusinteger_t)1L);
	ctx->vsp=local+13;
	w=(*ftab[5])(ctx,2,local+11,&ftab[5],fqv[24]); /*make-matrix*/
	local[7] = w;
KEY3732:
	if (n & (1<<8)) goto KEY3733;
	local[11]= local[3];
	local[12]= makeint((eusinteger_t)0L);
	ctx->vsp=local+13;
	w=(*ftab[28])(ctx,2,local+11,&ftab[28],fqv[279]); /*array-dimension*/
	local[8] = w;
KEY3733:
	if (n & (1<<9)) goto KEY3734;
	local[9] = NIL;
KEY3734:
	if (n & (1<<10)) goto KEY3735;
	local[10] = NIL;
KEY3735:
	argv[0]->c.obj.iv[22] = local[3];
	argv[0]->c.obj.iv[23] = local[4];
	argv[0]->c.obj.iv[24] = local[5];
	local[11]= argv[0]->c.obj.iv[24];
	local[12]= makeint((eusinteger_t)0L);
	ctx->vsp=local+13;
	w=(*ftab[28])(ctx,2,local+11,&ftab[28],fqv[279]); /*array-dimension*/
	argv[0]->c.obj.iv[20] = w;
	local[11]= argv[0]->c.obj.iv[23];
	local[12]= makeint((eusinteger_t)1L);
	ctx->vsp=local+13;
	w=(*ftab[28])(ctx,2,local+11,&ftab[28],fqv[279]); /*array-dimension*/
	argv[0]->c.obj.iv[21] = w;
	local[11]= argv[0]->c.obj.iv[22];
	local[12]= makeint((eusinteger_t)0L);
	ctx->vsp=local+13;
	w=(*ftab[28])(ctx,2,local+11,&ftab[28],fqv[279]); /*array-dimension*/
	local[11]= w;
	local[12]= argv[0]->c.obj.iv[20];
	local[13]= local[11];
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,2,local+12); /*+*/
	local[12]= w;
	local[13]= argv[0]->c.obj.iv[24];
	local[14]= argv[0]->c.obj.iv[22];
	ctx->vsp=local+15;
	w=(pointer)MATTIMES(ctx,2,local+13); /*m**/
	local[13]= w;
	local[14]= local[12];
	local[15]= local[12];
	ctx->vsp=local+16;
	w=(*ftab[5])(ctx,2,local+14,&ftab[5],fqv[24]); /*make-matrix*/
	local[14]= w;
	local[15]= argv[0]->c.obj.iv[24];
	local[16]= argv[0]->c.obj.iv[23];
	ctx->vsp=local+17;
	w=(pointer)MATTIMES(ctx,2,local+15); /*m**/
	local[15]= w;
	local[16]= local[12];
	local[17]= argv[0]->c.obj.iv[23];
	local[18]= makeint((eusinteger_t)1L);
	ctx->vsp=local+19;
	w=(*ftab[28])(ctx,2,local+17,&ftab[28],fqv[279]); /*array-dimension*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(*ftab[5])(ctx,2,local+16,&ftab[5],fqv[24]); /*make-matrix*/
	local[16]= w;
	local[17]= argv[0]->c.obj.iv[20];
	local[18]= local[12];
	ctx->vsp=local+19;
	w=(*ftab[5])(ctx,2,local+17,&ftab[5],fqv[24]); /*make-matrix*/
	local[17]= w;
	local[18]= makeint((eusinteger_t)0L);
	local[19]= argv[0]->c.obj.iv[20];
WHL3737:
	local[20]= local[18];
	w = local[19];
	if ((eusinteger_t)local[20] >= (eusinteger_t)w) goto WHX3738;
	local[20]= local[14];
	local[21]= local[18];
	local[22]= local[18];
	local[23]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+24;
	w=(pointer)ASET(ctx,4,local+20); /*aset*/
	local[20]= local[18];
	ctx->vsp=local+21;
	w=(pointer)ADD1(ctx,1,local+20); /*1+*/
	local[18] = w;
	goto WHL3737;
WHX3738:
	local[20]= NIL;
BLK3739:
	w = NIL;
	local[18]= makeint((eusinteger_t)0L);
	local[19]= argv[0]->c.obj.iv[20];
WHL3741:
	local[20]= local[18];
	w = local[19];
	if ((eusinteger_t)local[20] >= (eusinteger_t)w) goto WHX3742;
	local[20]= makeint((eusinteger_t)0L);
	local[21]= local[11];
WHL3745:
	local[22]= local[20];
	w = local[21];
	if ((eusinteger_t)local[22] >= (eusinteger_t)w) goto WHX3746;
	local[22]= local[14];
	local[23]= local[18];
	local[24]= argv[0]->c.obj.iv[20];
	local[25]= local[20];
	ctx->vsp=local+26;
	w=(pointer)PLUS(ctx,2,local+24); /*+*/
	local[24]= w;
	local[25]= local[13];
	local[26]= local[18];
	local[27]= local[20];
	ctx->vsp=local+28;
	w=(pointer)AREF(ctx,3,local+25); /*aref*/
	local[25]= w;
	ctx->vsp=local+26;
	w=(pointer)ASET(ctx,4,local+22); /*aset*/
	local[22]= local[20];
	ctx->vsp=local+23;
	w=(pointer)ADD1(ctx,1,local+22); /*1+*/
	local[20] = w;
	goto WHL3745;
WHX3746:
	local[22]= NIL;
BLK3747:
	w = NIL;
	local[20]= local[18];
	ctx->vsp=local+21;
	w=(pointer)ADD1(ctx,1,local+20); /*1+*/
	local[18] = w;
	goto WHL3741;
WHX3742:
	local[20]= NIL;
BLK3743:
	w = NIL;
	local[18]= makeint((eusinteger_t)0L);
	local[19]= local[11];
WHL3749:
	local[20]= local[18];
	w = local[19];
	if ((eusinteger_t)local[20] >= (eusinteger_t)w) goto WHX3750;
	local[20]= makeint((eusinteger_t)0L);
	local[21]= local[11];
WHL3753:
	local[22]= local[20];
	w = local[21];
	if ((eusinteger_t)local[22] >= (eusinteger_t)w) goto WHX3754;
	local[22]= local[14];
	local[23]= argv[0]->c.obj.iv[20];
	local[24]= local[18];
	ctx->vsp=local+25;
	w=(pointer)PLUS(ctx,2,local+23); /*+*/
	local[23]= w;
	local[24]= argv[0]->c.obj.iv[20];
	local[25]= local[20];
	ctx->vsp=local+26;
	w=(pointer)PLUS(ctx,2,local+24); /*+*/
	local[24]= w;
	local[25]= argv[0]->c.obj.iv[22];
	local[26]= local[18];
	local[27]= local[20];
	ctx->vsp=local+28;
	w=(pointer)AREF(ctx,3,local+25); /*aref*/
	local[25]= w;
	ctx->vsp=local+26;
	w=(pointer)ASET(ctx,4,local+22); /*aset*/
	local[22]= local[20];
	ctx->vsp=local+23;
	w=(pointer)ADD1(ctx,1,local+22); /*1+*/
	local[20] = w;
	goto WHL3753;
WHX3754:
	local[22]= NIL;
BLK3755:
	w = NIL;
	local[20]= local[18];
	ctx->vsp=local+21;
	w=(pointer)ADD1(ctx,1,local+20); /*1+*/
	local[18] = w;
	goto WHL3749;
WHX3750:
	local[20]= NIL;
BLK3751:
	w = NIL;
	local[18]= makeint((eusinteger_t)0L);
	local[19]= argv[0]->c.obj.iv[20];
WHL3757:
	local[20]= local[18];
	w = local[19];
	if ((eusinteger_t)local[20] >= (eusinteger_t)w) goto WHX3758;
	local[20]= makeint((eusinteger_t)0L);
	local[21]= argv[0]->c.obj.iv[21];
WHL3761:
	local[22]= local[20];
	w = local[21];
	if ((eusinteger_t)local[22] >= (eusinteger_t)w) goto WHX3762;
	local[22]= local[16];
	local[23]= local[18];
	local[24]= local[20];
	local[25]= local[15];
	local[26]= local[18];
	local[27]= local[20];
	ctx->vsp=local+28;
	w=(pointer)AREF(ctx,3,local+25); /*aref*/
	local[25]= w;
	ctx->vsp=local+26;
	w=(pointer)ASET(ctx,4,local+22); /*aset*/
	local[22]= local[20];
	ctx->vsp=local+23;
	w=(pointer)ADD1(ctx,1,local+22); /*1+*/
	local[20] = w;
	goto WHL3761;
WHX3762:
	local[22]= NIL;
BLK3763:
	w = NIL;
	local[20]= local[18];
	ctx->vsp=local+21;
	w=(pointer)ADD1(ctx,1,local+20); /*1+*/
	local[18] = w;
	goto WHL3757;
WHX3758:
	local[20]= NIL;
BLK3759:
	w = NIL;
	local[18]= makeint((eusinteger_t)0L);
	local[19]= local[11];
WHL3765:
	local[20]= local[18];
	w = local[19];
	if ((eusinteger_t)local[20] >= (eusinteger_t)w) goto WHX3766;
	local[20]= makeint((eusinteger_t)0L);
	local[21]= argv[0]->c.obj.iv[21];
WHL3769:
	local[22]= local[20];
	w = local[21];
	if ((eusinteger_t)local[22] >= (eusinteger_t)w) goto WHX3770;
	local[22]= local[16];
	local[23]= argv[0]->c.obj.iv[20];
	local[24]= local[18];
	ctx->vsp=local+25;
	w=(pointer)PLUS(ctx,2,local+23); /*+*/
	local[23]= w;
	local[24]= local[20];
	local[25]= argv[0]->c.obj.iv[23];
	local[26]= local[18];
	local[27]= local[20];
	ctx->vsp=local+28;
	w=(pointer)AREF(ctx,3,local+25); /*aref*/
	local[25]= w;
	ctx->vsp=local+26;
	w=(pointer)ASET(ctx,4,local+22); /*aset*/
	local[22]= local[20];
	ctx->vsp=local+23;
	w=(pointer)ADD1(ctx,1,local+22); /*1+*/
	local[20] = w;
	goto WHL3769;
WHX3770:
	local[22]= NIL;
BLK3771:
	w = NIL;
	local[20]= local[18];
	ctx->vsp=local+21;
	w=(pointer)ADD1(ctx,1,local+20); /*1+*/
	local[18] = w;
	goto WHL3765;
WHX3766:
	local[20]= NIL;
BLK3767:
	w = NIL;
	if (local[10]==NIL) goto IF3772;
	local[18]= makeint((eusinteger_t)0L);
	local[19]= argv[0]->c.obj.iv[20];
WHL3775:
	local[20]= local[18];
	w = local[19];
	if ((eusinteger_t)local[20] >= (eusinteger_t)w) goto WHX3776;
	local[20]= local[17];
	local[21]= local[18];
	local[22]= local[18];
	local[23]= local[10];
	local[24]= local[18];
	local[25]= local[18];
	ctx->vsp=local+26;
	w=(pointer)AREF(ctx,3,local+23); /*aref*/
	local[23]= w;
	ctx->vsp=local+24;
	w=(pointer)ASET(ctx,4,local+20); /*aset*/
	local[20]= local[18];
	ctx->vsp=local+21;
	w=(pointer)ADD1(ctx,1,local+20); /*1+*/
	local[18] = w;
	goto WHL3775;
WHX3776:
	local[20]= NIL;
BLK3777:
	w = NIL;
	local[18]= w;
	goto IF3773;
IF3772:
	local[18]= makeint((eusinteger_t)0L);
	local[19]= argv[0]->c.obj.iv[20];
WHL3779:
	local[20]= local[18];
	w = local[19];
	if ((eusinteger_t)local[20] >= (eusinteger_t)w) goto WHX3780;
	local[20]= local[17];
	local[21]= local[18];
	local[22]= local[18];
	local[23]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+24;
	w=(pointer)ASET(ctx,4,local+20); /*aset*/
	local[20]= local[18];
	ctx->vsp=local+21;
	w=(pointer)ADD1(ctx,1,local+20); /*1+*/
	local[18] = w;
	goto WHL3779;
WHX3780:
	local[20]= NIL;
BLK3781:
	w = NIL;
	local[18]= w;
IF3773:
	local[18]= argv[0];
	local[19]= *(ovafptr(argv[1],fqv[284]));
	local[20]= fqv[223];
	local[21]= argv[2];
	local[22]= fqv[295];
	local[23]= local[14];
	local[24]= fqv[296];
	local[25]= local[16];
	local[26]= fqv[297];
	local[27]= local[17];
	local[28]= fqv[298];
	local[29]= local[8];
	local[30]= fqv[299];
	local[31]= local[0];
	local[32]= fqv[300];
	local[33]= local[1];
	local[34]= fqv[224];
	local[35]= local[2];
	local[36]= fqv[301];
	local[37]= local[6];
	local[38]= fqv[302];
	local[39]= local[7];
	local[40]= fqv[225];
	local[41]= local[9];
	local[42]= fqv[303];
	local[43]= argv[0]->c.obj.iv[20];
	local[44]= fqv[304];
	local[45]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+46;
	w=(pointer)SENDMESSAGE(ctx,28,local+18); /*send-message*/
	if (argv[0]->c.obj.iv[25]!=NIL) goto IF3782;
	local[18]= local[12];
	local[19]= makeint((eusinteger_t)1L);
	ctx->vsp=local+20;
	w=(*ftab[5])(ctx,2,local+18,&ftab[5],fqv[24]); /*make-matrix*/
	argv[0]->c.obj.iv[25] = w;
	local[18]= argv[0]->c.obj.iv[24];
	local[19]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+20;
	w=(pointer)MATTIMES(ctx,2,local+18); /*m**/
	local[18]= w;
	local[19]= makeint((eusinteger_t)0L);
	local[20]= argv[0]->c.obj.iv[20];
WHL3785:
	local[21]= local[19];
	w = local[20];
	if ((eusinteger_t)local[21] >= (eusinteger_t)w) goto WHX3786;
	local[21]= argv[0]->c.obj.iv[25];
	local[22]= local[19];
	local[23]= makeint((eusinteger_t)0L);
	local[24]= local[18];
	local[25]= local[19];
	local[26]= makeint((eusinteger_t)0L);
	ctx->vsp=local+27;
	w=(pointer)AREF(ctx,3,local+24); /*aref*/
	local[24]= w;
	ctx->vsp=local+25;
	w=(pointer)ASET(ctx,4,local+21); /*aset*/
	local[21]= local[19];
	ctx->vsp=local+22;
	w=(pointer)ADD1(ctx,1,local+21); /*1+*/
	local[19] = w;
	goto WHL3785;
WHX3786:
	local[21]= NIL;
BLK3787:
	w = NIL;
	local[18]= w;
	goto IF3783;
IF3782:
	local[18]= NIL;
IF3783:
	w = argv[0];
	local[0]= w;
BLK3724:
	ctx->vsp=local; return(local[0]);}

/*:calc-f*/
static pointer M3788extended_preview_controller_calc_f(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[21];
	local[1]= argv[0]->c.obj.iv[20];
	local[2]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,2,local+0,&ftab[5],fqv[24]); /*make-matrix*/
	argv[0]->c.obj.iv[13] = w;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(*ftab[28])(ctx,2,local+0,&ftab[28],fqv[279]); /*array-dimension*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[14])(ctx,1,local+0,&ftab[14],fqv[184]); /*unit-matrix*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSPOSE(ctx,1,local+1); /*transpose*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+3;
	w=(pointer)TRANSPOSE(ctx,1,local+2); /*transpose*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[9];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)MATTIMES(ctx,2,local+3); /*m**/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[5];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(*ftab[2])(ctx,2,local+4,&ftab[2],fqv[4]); /*scale-matrix*/
	local[4]= w;
	local[5]= makeint((eusinteger_t)0L);
	local[6]= argv[0]->c.obj.iv[12];
WHL3791:
	local[7]= local[5];
	w = local[6];
	if ((eusinteger_t)local[7] >= (eusinteger_t)w) goto WHX3792;
	local[7]= local[5];
	local[8]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+9;
	w=(pointer)SUB1(ctx,1,local+8); /*1-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)NUMEQUAL(ctx,2,local+7); /*=*/
	if (w==NIL) goto IF3794;
	local[7]= argv[0]->c.obj.iv[4];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)MATTIMES(ctx,2,local+7); /*m**/
	local[7]= w;
	goto IF3795;
IF3794:
	local[7]= local[4];
IF3795:
	local[8]= argv[0]->c.obj.iv[9];
	local[9]= local[1];
	local[10]= local[0];
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)MATTIMES(ctx,2,local+10); /*m**/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)MATTIMES(ctx,2,local+9); /*m**/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MATTIMES(ctx,2,local+8); /*m**/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[8];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)MATTIMES(ctx,2,local+9); /*m**/
	local[0] = w;
	local[9]= makeint((eusinteger_t)0L);
	local[10]= argv[0]->c.obj.iv[21];
WHL3797:
	local[11]= local[9];
	w = local[10];
	if ((eusinteger_t)local[11] >= (eusinteger_t)w) goto WHX3798;
	local[11]= makeint((eusinteger_t)0L);
	local[12]= argv[0]->c.obj.iv[20];
WHL3801:
	local[13]= local[11];
	w = local[12];
	if ((eusinteger_t)local[13] >= (eusinteger_t)w) goto WHX3802;
	local[13]= argv[0]->c.obj.iv[13];
	local[14]= local[9];
	local[15]= argv[0]->c.obj.iv[20];
	local[16]= local[5];
	ctx->vsp=local+17;
	w=(pointer)ADD1(ctx,1,local+16); /*1+*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)TIMES(ctx,2,local+15); /***/
	local[15]= w;
	local[16]= local[11];
	ctx->vsp=local+17;
	w=(pointer)PLUS(ctx,2,local+15); /*+*/
	local[15]= w;
	local[16]= local[8];
	local[17]= local[9];
	local[18]= local[11];
	ctx->vsp=local+19;
	w=(pointer)AREF(ctx,3,local+16); /*aref*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)ASET(ctx,4,local+13); /*aset*/
	local[13]= local[11];
	ctx->vsp=local+14;
	w=(pointer)ADD1(ctx,1,local+13); /*1+*/
	local[11] = w;
	goto WHL3801;
WHX3802:
	local[13]= NIL;
BLK3803:
	w = NIL;
	local[11]= local[9];
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[9] = w;
	goto WHL3797;
WHX3798:
	local[11]= NIL;
BLK3799:
	w = NIL;
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[5] = w;
	goto WHL3791;
WHX3792:
	local[7]= NIL;
BLK3793:
	w = NIL;
	local[0]= w;
BLK3789:
	ctx->vsp=local; return(local[0]);}

/*:calc-u*/
static pointer M3804extended_preview_controller_calc_u(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+2;
	w=(pointer)MATTIMES(ctx,2,local+0); /*m**/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[7];
	local[2]= argv[0]->c.obj.iv[25];
	ctx->vsp=local+3;
	w=(pointer)MATTIMES(ctx,2,local+1); /*m**/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[186]); /*m-*/
	local[0]= w;
	local[1]= local[0];
	local[2]= argv[0]->c.obj.iv[11];
	ctx->vsp=local+3;
	w=(*ftab[6])(ctx,2,local+1,&ftab[6],fqv[27]); /*m+*/
	argv[0]->c.obj.iv[11] = w;
	w = local[0];
	local[0]= w;
BLK3805:
	ctx->vsp=local; return(local[0]);}

/*:calc-xk*/
static pointer M3806extended_preview_controller_calc_xk(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[25];
	ctx->vsp=local+2;
	w=(pointer)MATTIMES(ctx,2,local+0); /*m**/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= argv[0];
	local[3]= fqv[287];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MATTIMES(ctx,2,local+1); /*m**/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,2,local+0,&ftab[6],fqv[27]); /*m+*/
	argv[0]->c.obj.iv[25] = w;
	local[0]= makeint((eusinteger_t)0L);
	local[1]= argv[0]->c.obj.iv[22];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(*ftab[28])(ctx,2,local+1,&ftab[28],fqv[279]); /*array-dimension*/
	local[1]= w;
WHL3809:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX3810;
	local[2]= argv[0]->c.obj.iv[10];
	local[3]= local[0];
	local[4]= makeint((eusinteger_t)0L);
	local[5]= argv[0]->c.obj.iv[10];
	local[6]= local[0];
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,3,local+5); /*aref*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[25];
	local[7]= argv[0]->c.obj.iv[20];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,4,local+2); /*aset*/
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL3809;
WHX3810:
	local[2]= NIL;
BLK3811:
	w = NIL;
	local[0]= w;
BLK3807:
	ctx->vsp=local; return(local[0]);}

/*:current-output-vector*/
static pointer M3812extended_preview_controller_current_output_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[25];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(*ftab[30])(ctx,2,local+0,&ftab[30],fqv[293]); /*matrix-column*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)0L);
	local[2]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+3;
	w=(pointer)SUBSEQ(ctx,3,local+0); /*subseq*/
	local[0]= w;
BLK3813:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3814preview_control_cart_table_cog_trajectory_generator_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[305], &argv[4], n-4, local+0, 0);
	if (n & (1<<0)) goto KEY3816;
	local[0] = makeint((eusinteger_t)1L);
KEY3816:
	if (n & (1<<1)) goto KEY3817;
	local[1] = makeflt(9.9999999999999974298988e-07);
KEY3817:
	if (n & (1<<2)) goto KEY3818;
	local[2] = makeflt(1.5999999999999996447286e+00);
KEY3818:
	if (n & (1<<3)) goto KEY3819;
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)0L);
	local[11]= makeint((eusinteger_t)0L);
	ctx->vsp=local+12;
	w=(pointer)MKFLTVEC(ctx,3,local+9); /*float-vector*/
	local[3] = w;
KEY3819:
	if (n & (1<<4)) goto KEY3820;
	local[9]= makeint((eusinteger_t)3L);
	local[10]= makeint((eusinteger_t)3L);
	local[11]= makeint((eusinteger_t)1L);
	local[12]= argv[2];
	local[13]= makeflt(5.0000000000000000000000e-01);
	local[14]= argv[2];
	local[15]= argv[2];
	ctx->vsp=local+16;
	w=(pointer)TIMES(ctx,3,local+13); /***/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,3,local+11); /*list*/
	local[11]= w;
	local[12]= makeint((eusinteger_t)0L);
	local[13]= makeint((eusinteger_t)1L);
	local[14]= argv[2];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,3,local+12); /*list*/
	local[12]= w;
	local[13]= makeint((eusinteger_t)0L);
	local[14]= makeint((eusinteger_t)0L);
	local[15]= makeint((eusinteger_t)1L);
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,3,local+13); /*list*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,3,local+11); /*list*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[5])(ctx,3,local+9,&ftab[5],fqv[24]); /*make-matrix*/
	local[4] = w;
KEY3820:
	if (n & (1<<5)) goto KEY3821;
	local[9]= makeint((eusinteger_t)3L);
	local[10]= makeint((eusinteger_t)1L);
	local[11]= makeflt(1.0000000000000000000000e+00);
	local[12]= makeflt(6.0000000000000000000000e+00);
	ctx->vsp=local+13;
	w=(pointer)QUOTIENT(ctx,2,local+11); /*/*/
	local[11]= w;
	local[12]= argv[2];
	local[13]= argv[2];
	local[14]= argv[2];
	ctx->vsp=local+15;
	w=(pointer)TIMES(ctx,4,local+11); /***/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	local[11]= w;
	local[12]= makeflt(5.0000000000000000000000e-01);
	local[13]= argv[2];
	local[14]= argv[2];
	ctx->vsp=local+15;
	w=(pointer)TIMES(ctx,3,local+12); /***/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	local[12]= w;
	local[13]= argv[2];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,3,local+11); /*list*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[5])(ctx,3,local+9,&ftab[5],fqv[24]); /*make-matrix*/
	local[5] = w;
KEY3821:
	if (n & (1<<6)) goto KEY3822;
	local[9]= makeint((eusinteger_t)1L);
	local[10]= makeint((eusinteger_t)3L);
	local[11]= makeflt(1.0000000000000000000000e+00);
	local[12]= makeflt(0.0000000000000000000000e+00);
	local[13]= argv[3];
	local[14]= loadglobal(fqv[147]);
	local[15]= makeint((eusinteger_t)2L);
	ctx->vsp=local+16;
	w=(pointer)ELT(ctx,2,local+14); /*elt*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)QUOTIENT(ctx,2,local+13); /*/*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)MINUS(ctx,1,local+13); /*-*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,3,local+11); /*list*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[5])(ctx,3,local+9,&ftab[5],fqv[24]); /*make-matrix*/
	local[6] = w;
KEY3822:
	if (n & (1<<7)) goto KEY3823;
	local[7] = NIL;
KEY3823:
	if (n & (1<<8)) goto KEY3824;
	local[8] = loadglobal(fqv[306]);
KEY3824:
	local[9]= local[8];
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,1,local+9); /*instantiate*/
	local[9]= w;
	local[10]= local[9];
	local[11]= fqv[223];
	local[12]= argv[2];
	local[13]= fqv[299];
	local[14]= local[0];
	local[15]= fqv[300];
	local[16]= local[1];
	local[17]= fqv[224];
	local[18]= local[2];
	local[19]= fqv[301];
	local[20]= local[3];
	local[21]= makeint((eusinteger_t)0L);
	ctx->vsp=local+22;
	w=(pointer)ELT(ctx,2,local+20); /*elt*/
	local[20]= w;
	local[21]= makeint((eusinteger_t)0L);
	local[22]= makeint((eusinteger_t)0L);
	ctx->vsp=local+23;
	w=(pointer)MKFLTVEC(ctx,3,local+20); /*float-vector*/
	local[20]= w;
	local[21]= fqv[295];
	local[22]= local[4];
	local[23]= fqv[296];
	local[24]= local[5];
	local[25]= fqv[297];
	local[26]= local[6];
	local[27]= fqv[298];
	local[28]= makeint((eusinteger_t)3L);
	local[29]= fqv[225];
	local[30]= local[7];
	ctx->vsp=local+31;
	w=(pointer)SEND(ctx,21,local+10); /*send*/
	w = local[9];
	local[9]= w;
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)INSTANTIATE(ctx,1,local+10); /*instantiate*/
	local[10]= w;
	local[11]= local[10];
	local[12]= fqv[223];
	local[13]= argv[2];
	local[14]= fqv[299];
	local[15]= local[0];
	local[16]= fqv[300];
	local[17]= local[1];
	local[18]= fqv[224];
	local[19]= local[2];
	local[20]= fqv[301];
	local[21]= local[3];
	local[22]= makeint((eusinteger_t)1L);
	ctx->vsp=local+23;
	w=(pointer)ELT(ctx,2,local+21); /*elt*/
	local[21]= w;
	local[22]= makeint((eusinteger_t)0L);
	local[23]= makeint((eusinteger_t)0L);
	ctx->vsp=local+24;
	w=(pointer)MKFLTVEC(ctx,3,local+21); /*float-vector*/
	local[21]= w;
	local[22]= fqv[295];
	local[23]= local[4];
	local[24]= fqv[296];
	local[25]= local[5];
	local[26]= fqv[297];
	local[27]= local[6];
	local[28]= fqv[298];
	local[29]= makeint((eusinteger_t)3L);
	local[30]= fqv[225];
	local[31]= local[7];
	ctx->vsp=local+32;
	w=(pointer)SEND(ctx,21,local+11); /*send*/
	w = local[10];
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,2,local+9); /*list*/
	argv[0]->c.obj.iv[1] = w;
	argv[0]->c.obj.iv[2] = argv[3];
	w = argv[0];
	local[0]= w;
BLK3815:
	ctx->vsp=local; return(local[0]);}

/*:refcog*/
static pointer M3827preview_control_cart_table_cog_trajectory_generator_refcog(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= fqv[291];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[291];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
BLK3828:
	ctx->vsp=local; return(local[0]);}

/*:cart-zmp*/
static pointer M3829preview_control_cart_table_cog_trajectory_generator_cart_zmp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= fqv[292];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[292];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
BLK3830:
	ctx->vsp=local; return(local[0]);}

/*:last-refzmp*/
static pointer M3831preview_control_cart_table_cog_trajectory_generator_last_refzmp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= fqv[288];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[288];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
BLK3832:
	ctx->vsp=local; return(local[0]);}

/*:current-refzmp*/
static pointer M3833preview_control_cart_table_cog_trajectory_generator_current_refzmp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= fqv[290];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[290];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
BLK3834:
	ctx->vsp=local; return(local[0]);}

/*:update-xk*/
static pointer M3835preview_control_cart_table_cog_trajectory_generator_update_xk(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3838;}
	local[0]= NIL;
ENT3838:
ENT3837:
	if (n>4) maerror();
	if (argv[2]==NIL) goto IF3839;
	local[1]= argv[2];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	argv[0]->c.obj.iv[3] = w;
	local[1]= argv[0]->c.obj.iv[3];
	goto IF3840;
IF3839:
	local[1]= NIL;
IF3840:
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[229];
	local[3]= argv[2];
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)1L);
	ctx->vsp=local+6;
	w=(pointer)SUBSEQ(ctx,3,local+3); /*subseq*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[229];
	local[4]= argv[2];
	local[5]= makeint((eusinteger_t)1L);
	local[6]= makeint((eusinteger_t)2L);
	ctx->vsp=local+7;
	w=(pointer)SUBSEQ(ctx,3,local+4); /*subseq*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[1]= w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	if (local[2]==NIL) goto AND3841;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
AND3841:
	local[1] = local[2];
	if (local[1]==NIL) goto IF3842;
	local[2]= argv[0];
	local[3]= fqv[307];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[236];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[308];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,3,local+2); /*list*/
	local[2]= w;
	goto IF3843;
IF3842:
	local[2]= NIL;
IF3843:
	w = local[2];
	local[0]= w;
BLK3836:
	ctx->vsp=local; return(local[0]);}

/*:finishedp*/
static pointer M3844preview_control_cart_table_cog_trajectory_generator_finishedp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= fqv[228];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	if (w==NIL) goto AND3846;
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= fqv[228];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
AND3846:
	w = local[0];
	local[0]= w;
BLK3845:
	ctx->vsp=local; return(local[0]);}

/*:current-additional-data*/
static pointer M3847preview_control_cart_table_cog_trajectory_generator_current_additional_data(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= fqv[230];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK3848:
	ctx->vsp=local; return(local[0]);}

/*:pass-preview-controller*/
static pointer M3849preview_control_cart_table_cog_trajectory_generator_pass_preview_controller(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
WHL3851:
	local[2]= argv[0];
	local[3]= fqv[229];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[4];
	local[4]= w;
	local[5]= NIL;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[0] = w;
	if (local[0]!=NIL) goto WHX3852;
	goto WHL3851;
WHX3852:
	local[2]= NIL;
BLK3853:
	local[2]= local[0];
	w = local[1];
	ctx->vsp=local+3;
	local[1] = cons(ctx,local[2],w);
WHL3855:
	local[2]= argv[0];
	local[3]= fqv[229];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[4];
	local[4]= w;
	local[5]= NIL;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[0] = w;
	if (local[0]==NIL) goto WHX3856;
	local[2]= local[0];
	w = local[1];
	ctx->vsp=local+3;
	local[1] = cons(ctx,local[2],w);
	goto WHL3855;
WHX3856:
	local[2]= NIL;
BLK3857:
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)REVERSE(ctx,1,local+2); /*reverse*/
	local[0]= w;
BLK3850:
	ctx->vsp=local; return(local[0]);}

/*:cog-z*/
static pointer M3859preview_control_cart_table_cog_trajectory_generator_cog_z(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK3860:
	ctx->vsp=local; return(local[0]);}

/*:update-cog-z*/
static pointer M3861preview_control_cart_table_cog_trajectory_generator_update_cog_z(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO3863,env,argv,local);
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	local[0]= w;
BLK3862:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3863(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= *(ovafptr(argv[0],fqv[309]));
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)2L);
	local[3]= env->c.clo.env1[2];
	local[4]= loadglobal(fqv[147]);
	local[5]= makeint((eusinteger_t)2L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,1,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,4,local+0); /*aset*/
	local[0]= argv[0];
	local[1]= fqv[285];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[286];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3864gait_generator_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	argv[0]->c.obj.iv[1] = argv[2];
	argv[0]->c.obj.iv[2] = argv[3];
	local[0]= NIL;
	local[1]= fqv[310];
WHL3867:
	if (local[1]==NIL) goto WHX3868;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= fqv[311];
	local[3]= fqv[312];
	local[4]= NIL;
	local[5]= fqv[313];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[31])(ctx,1,local+4,&ftab[31],fqv[314]); /*read-from-string*/
	local[4]= w;
	local[5]= fqv[315];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	local[5]= w;
	local[6]= fqv[316];
	local[7]= local[0];
	local[8]= fqv[317];
	local[9]= local[0];
	local[10]= fqv[318];
	local[11]= fqv[315];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)EVAL(ctx,1,local+2); /*eval*/
	goto WHL3867;
WHX3868:
	local[2]= NIL;
BLK3869:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK3865:
	ctx->vsp=local; return(local[0]);}

/*:get-footstep-limbs*/
static pointer M3871gait_generator_get_footstep_limbs(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO3873,env,argv,local);
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	local[0]= w;
BLK3872:
	ctx->vsp=local; return(local[0]);}

/*:get-counter-footstep-limbs*/
static pointer M3874gait_generator_get_counter_footstep_limbs(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!issymbol(w)) goto IF3876;
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO3878,env,argv,local);
	local[1]= argv[0]->c.obj.iv[19];
	ctx->vsp=local+2;
	w=(*ftab[32])(ctx,2,local+0,&ftab[32],fqv[319]); /*remove-if*/
	local[0]= w;
	goto IF3877;
IF3876:
	local[0]= argv[0];
	local[1]= fqv[320];
	local[2]= argv[0];
	local[3]= fqv[321];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
IF3877:
	w = local[0];
	local[0]= w;
BLK3875:
	ctx->vsp=local; return(local[0]);}

/*:get-limbs-zmp-list*/
static pointer M3879gait_generator_get_limbs_zmp_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO3881,env,argv,local);
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,3,local+0); /*mapcar*/
	local[0]= w;
BLK3880:
	ctx->vsp=local; return(local[0]);}

/*:get-limbs-zmp*/
static pointer M3882gait_generator_get_limbs_zmp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= makeflt(1.0000000000000000000000e+00);
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
	local[1]= (pointer)get_sym_func(fqv[322]);
	local[2]= argv[0];
	local[3]= fqv[323];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	local[3]= fqv[324];
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)0L);
	local[6]= makeint((eusinteger_t)0L);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[33])(ctx,4,local+1,&ftab[33],fqv[325]); /*reduce*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SCALEVEC(ctx,2,local+0); /*scale*/
	local[0]= w;
BLK3883:
	ctx->vsp=local; return(local[0]);}

/*:get-swing-limbs*/
static pointer M3884gait_generator_get_swing_limbs(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO3886,env,argv,local);
	local[1]= argv[0]->c.obj.iv[19];
	ctx->vsp=local+2;
	w=(*ftab[32])(ctx,2,local+0,&ftab[32],fqv[319]); /*remove-if*/
	local[0]= w;
BLK3885:
	ctx->vsp=local; return(local[0]);}

/*:initialize-gait-parameter*/
static pointer M3887gait_generator_initialize_gait_parameter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[326], &argv[5], n-5, local+0, 0);
	if (n & (1<<0)) goto KEY3889;
	local[0] = makeint((eusinteger_t)50L);
KEY3889:
	if (n & (1<<1)) goto KEY3890;
	local[1] = makeflt(1.9999999999999995559108e-01);
KEY3890:
	if (n & (1<<2)) goto KEY3891;
	local[2] = makeflt(1.5999999999999996447286e+00);
KEY3891:
	if (n & (1<<3)) goto KEY3892;
	local[3] = fqv[327];
KEY3892:
	if (n & (1<<4)) goto KEY3893;
	ctx->vsp=local+11;
	local[11]= makeclosure(codevec,quotevec,CLO3894,env,argv,local);
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)MAPCAN(ctx,2,local+11); /*mapcan*/
	local[4] = w;
KEY3893:
	if (n & (1<<5)) goto KEY3895;
	local[5] = makeflt(1.0000000000000000000000e+00);
KEY3895:
	if (n & (1<<6)) goto KEY3896;
	local[6] = makeflt(9.9999999999999974298988e-07);
KEY3896:
	if (n & (1<<7)) goto KEY3897;
	local[7] = makeint((eusinteger_t)1L);
KEY3897:
	if (n & (1<<8)) goto KEY3898;
	local[11]= makeint((eusinteger_t)1L);
	ctx->vsp=local+12;
	w=(*ftab[24])(ctx,1,local+11,&ftab[24],fqv[260]); /*deg2rad*/
	local[8] = w;
KEY3898:
	if (n & (1<<9)) goto KEY3899;
	local[9] = T;
KEY3899:
	if (n & (1<<10)) goto KEY3900;
	local[10] = T;
KEY3900:
	ctx->vsp=local+11;
	local[11]= makeclosure(codevec,quotevec,CLO3901,env,argv,local);
	local[12]= argv[2];
	ctx->vsp=local+13;
	w=(pointer)MAPCAR(ctx,2,local+11); /*mapcar*/
	argv[0]->c.obj.iv[3] = w;
	local[11]= argv[3];
	local[12]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+13;
	w=(pointer)QUOTIENT(ctx,2,local+11); /*/*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)ROUND(ctx,1,local+11); /*round*/
	argv[0]->c.obj.iv[12] = w;
	argv[0]->c.obj.iv[5] = NIL;
	argv[0]->c.obj.iv[4] = NIL;
	argv[0]->c.obj.iv[6] = NIL;
	argv[0]->c.obj.iv[8] = NIL;
	argv[0]->c.obj.iv[11] = NIL;
	argv[0]->c.obj.iv[14] = local[0];
	argv[0]->c.obj.iv[15] = local[1];
	argv[0]->c.obj.iv[16] = local[4];
	argv[0]->c.obj.iv[13] = argv[0]->c.obj.iv[12];
	argv[0]->c.obj.iv[17] = NIL;
	argv[0]->c.obj.iv[19] = local[3];
	argv[0]->c.obj.iv[21] = local[7];
	argv[0]->c.obj.iv[22] = local[8];
	argv[0]->c.obj.iv[20] = local[10];
	argv[0]->c.obj.iv[25] = makeint((eusinteger_t)0L);
	argv[0]->c.obj.iv[24] = makeint((eusinteger_t)0L);
	argv[0]->c.obj.iv[23] = makeint((eusinteger_t)0L);
	argv[0]->c.obj.iv[28] = makeint((eusinteger_t)0L);
	argv[0]->c.obj.iv[27] = makeint((eusinteger_t)0L);
	argv[0]->c.obj.iv[26] = makeint((eusinteger_t)0L);
	local[11]= argv[0];
	local[12]= fqv[321];
	w=argv[0]->c.obj.iv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[11]= w;
	local[12]= argv[0];
	local[13]= fqv[328];
	local[14]= argv[0];
	local[15]= fqv[320];
	w=argv[0]->c.obj.iv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	w=argv[0]->c.obj.iv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= argv[0];
	local[14]= fqv[329];
	ctx->vsp=local+15;
	local[15]= makeclosure(codevec,quotevec,CLO3902,env,argv,local);
	local[16]= local[12];
	ctx->vsp=local+17;
	w=(pointer)MAPCAR(ctx,2,local+15); /*mapcar*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= argv[0];
	local[14]= fqv[330];
	ctx->vsp=local+15;
	local[15]= makeclosure(codevec,quotevec,CLO3903,env,argv,local);
	local[16]= local[11];
	ctx->vsp=local+17;
	w=(pointer)MAPCAR(ctx,2,local+15); /*mapcar*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	local[15]= argv[0];
	local[16]= fqv[331];
	local[17]= argv[0];
	local[18]= fqv[332];
	if (local[9]==NIL) goto IF3904;
	local[19]= local[14];
	local[20]= local[13];
	ctx->vsp=local+21;
	w=(pointer)APPEND(ctx,2,local+19); /*append*/
	local[19]= w;
	goto IF3905;
IF3904:
	local[19]= local[14];
IF3905:
	if (local[9]==NIL) goto IF3906;
	local[20]= local[11];
	local[21]= local[12];
	ctx->vsp=local+22;
	w=(pointer)APPEND(ctx,2,local+20); /*append*/
	local[20]= w;
	goto IF3907;
IF3906:
	local[20]= local[11];
IF3907:
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,4,local+17); /*send*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,3,local+15); /*send*/
	local[15]= argv[0];
	local[16]= fqv[333];
	local[17]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,3,local+15); /*send*/
	w=argv[0]->c.obj.iv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[3] = (w)->c.cons.cdr;
	w = local[15];
	local[15]= loadglobal(fqv[222]);
	ctx->vsp=local+16;
	w=(pointer)INSTANTIATE(ctx,1,local+15); /*instantiate*/
	local[15]= w;
	local[16]= local[15];
	local[17]= fqv[223];
	local[18]= argv[0]->c.obj.iv[2];
	local[19]= argv[4];
	local[20]= makeint((eusinteger_t)2L);
	ctx->vsp=local+21;
	w=(pointer)ELT(ctx,2,local+19); /*elt*/
	local[19]= w;
	w=argv[0]->c.obj.iv[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	local[21]= makeint((eusinteger_t)2L);
	ctx->vsp=local+22;
	w=(pointer)ELT(ctx,2,local+20); /*elt*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)MINUS(ctx,2,local+19); /*-*/
	local[19]= w;
	local[20]= fqv[224];
	local[21]= local[2];
	local[22]= fqv[299];
	local[23]= local[5];
	local[24]= fqv[300];
	local[25]= local[6];
	local[26]= fqv[301];
	local[27]= argv[4];
	local[28]= fqv[226];
	local[29]= loadglobal(fqv[306]);
	ctx->vsp=local+30;
	w=(pointer)SEND(ctx,14,local+16); /*send*/
	w = local[15];
	argv[0]->c.obj.iv[18] = w;
	argv[0]->c.obj.iv[7] = local[14];
	local[15]= argv[0];
	local[16]= fqv[332];
	ctx->vsp=local+17;
	local[17]= makeclosure(codevec,quotevec,CLO3910,env,argv,local);
	local[18]= argv[0];
	local[19]= fqv[320];
	w=argv[0]->c.obj.iv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	local[21]= fqv[58];
	ctx->vsp=local+22;
	w=(*ftab[7])(ctx,2,local+20,&ftab[7],fqv[29]); /*send-all*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,3,local+18); /*send*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)MAPCAR(ctx,2,local+17); /*mapcar*/
	local[17]= w;
	local[18]= argv[0];
	local[19]= fqv[320];
	w=argv[0]->c.obj.iv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	local[21]= fqv[58];
	ctx->vsp=local+22;
	w=(*ftab[7])(ctx,2,local+20,&ftab[7],fqv[29]); /*send-all*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,3,local+18); /*send*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,4,local+15); /*send*/
	argv[0]->c.obj.iv[9] = w;
	w=argv[0]->c.obj.iv[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[10] = (w)->c.cons.car;
	local[15]= argv[0];
	local[16]= fqv[334];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	w = T;
	local[0]= w;
BLK3888:
	ctx->vsp=local; return(local[0]);}

/*:finalize-gait-parameter*/
static pointer M3911gait_generator_finalize_gait_parameter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+1;
	w=(*ftab[34])(ctx,1,local+0,&ftab[34],fqv[335]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(*ftab[34])(ctx,1,local+1,&ftab[34],fqv[335]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[0];
	local[3]= fqv[328];
	local[4]= argv[0];
	local[5]= fqv[320];
	local[6]= argv[0];
	local[7]= fqv[336];
	local[8]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+9;
	w=(pointer)REVERSE(ctx,1,local+8); /*reverse*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[329];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO3913,env,argv,local);
	local[5]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+6;
	w=(*ftab[34])(ctx,1,local+5,&ftab[34],fqv[335]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[330];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO3914,env,argv,local);
	local[5]= argv[0];
	local[6]= fqv[336];
	local[7]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+8;
	w=(*ftab[34])(ctx,1,local+7,&ftab[34],fqv[335]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[331];
	local[4]= argv[0];
	local[5]= fqv[332];
	if (argv[0]->c.obj.iv[20]==NIL) goto IF3915;
	local[6]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+7;
	w=(*ftab[34])(ctx,1,local+6,&ftab[34],fqv[335]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+8;
	w=(*ftab[34])(ctx,1,local+7,&ftab[34],fqv[335]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)APPEND(ctx,2,local+6); /*append*/
	local[6]= w;
	goto IF3916;
IF3915:
	local[6]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+7;
	w=(*ftab[34])(ctx,1,local+6,&ftab[34],fqv[335]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
IF3916:
	if (argv[0]->c.obj.iv[20]==NIL) goto IF3917;
	local[7]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+8;
	w=(*ftab[34])(ctx,1,local+7,&ftab[34],fqv[335]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= argv[0];
	local[9]= fqv[320];
	local[10]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+11;
	w=(*ftab[34])(ctx,1,local+10,&ftab[34],fqv[335]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)APPEND(ctx,2,local+7); /*append*/
	local[7]= w;
	goto IF3918;
IF3917:
	local[7]= argv[0];
	local[8]= fqv[320];
	local[9]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+10;
	w=(*ftab[34])(ctx,1,local+9,&ftab[34],fqv[335]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
IF3918:
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[333];
	local[4]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+3;
	w=(*ftab[34])(ctx,1,local+2,&ftab[34],fqv[335]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[9] = (w)->c.cons.car;
	w = T;
	local[0]= w;
BLK3912:
	ctx->vsp=local; return(local[0]);}

/*:make-gait-parameter*/
static pointer M3919gait_generator_make_gait_parameter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[3] = (w)->c.cons.cdr;
	w = local[0];
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(*ftab[34])(ctx,1,local+1,&ftab[34],fqv[335]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[0];
	local[3]= fqv[328];
	local[4]= argv[0];
	local[5]= fqv[320];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[329];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO3922,env,argv,local);
	local[5]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+6;
	w=(*ftab[34])(ctx,1,local+5,&ftab[34],fqv[335]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[330];
	local[4]= local[0];
	local[5]= fqv[337];
	ctx->vsp=local+6;
	w=(*ftab[7])(ctx,2,local+4,&ftab[7],fqv[29]); /*send-all*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[331];
	local[4]= argv[0];
	local[5]= fqv[332];
	local[6]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+7;
	w=(*ftab[34])(ctx,1,local+6,&ftab[34],fqv[335]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+8;
	w=(*ftab[34])(ctx,1,local+7,&ftab[34],fqv[335]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[333];
	local[4]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	w = T;
	local[0]= w;
BLK3920:
	ctx->vsp=local; return(local[0]);}

/*:calc-hoffarbib-pos-vel-acc*/
static pointer M3923gait_generator_calc_hoffarbib_pos_vel_acc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=7) maerror();
	local[0]= makeflt(-9.0000000000000000000000e+00);
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= makeflt(-3.6000000000000000000000e+01);
	local[2]= argv[2];
	local[3]= makeint((eusinteger_t)2L);
	ctx->vsp=local+4;
	w=(*ftab[35])(ctx,2,local+2,&ftab[35],fqv[338]); /*expt*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= argv[5];
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
	local[1]= makeflt(6.0000000000000000000000e+01);
	local[2]= argv[2];
	local[3]= makeint((eusinteger_t)3L);
	ctx->vsp=local+4;
	w=(*ftab[35])(ctx,2,local+2,&ftab[35],fqv[338]); /*expt*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= argv[3];
	local[3]= argv[6];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
	local[1]= argv[4];
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[1]= w;
	local[2]= argv[5];
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= argv[6];
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	local[4]= local[1];
	local[5]= local[2];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,3,local+4); /*list*/
	local[0]= w;
BLK3924:
	ctx->vsp=local; return(local[0]);}

/*:calc-current-swing-leg-coords*/
static pointer M3925gait_generator_calc_current_swing_leg_coords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[339],w);
	ctx->vsp=local+3;
	n=parsekeyparams(fqv[340], &argv[5], n-5, local+3, 0);
	if (n & (1<<0)) goto KEY3927;
	local[3] = fqv[341];
KEY3927:
	if (n & (1<<1)) goto KEY3928;
	local[4] = argv[0]->c.obj.iv[14];
KEY3928:
	local[5]= local[3];
	local[6]= local[5];
	if (fqv[341]!=local[6]) goto IF3930;
	local[6]= loadglobal(fqv[339]);
	local[7]= argv[3];
	local[8]= argv[4];
	ctx->vsp=local+9;
	w=(*ftab[36])(ctx,3,local+6,&ftab[36],fqv[342]); /*midcoords*/
	local[6]= w;
	goto IF3931;
IF3930:
	local[6]= local[5];
	if (fqv[343]!=local[6]) goto IF3932;
	local[6]= argv[0];
	local[7]= fqv[344];
	local[8]= loadglobal(fqv[339]);
	local[9]= argv[3];
	local[10]= argv[4];
	local[11]= local[4];
	local[12]= fqv[345];
	local[13]= argv[0]->c.obj.iv[28];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,8,local+6); /*send*/
	local[6]= w;
	goto IF3933;
IF3932:
	local[6]= NIL;
IF3933:
IF3931:
	w = local[6];
	local[5]= w;
	ctx->vsp=local+6;
	unbindx(ctx,1);
	w = local[5];
	local[0]= w;
BLK3926:
	ctx->vsp=local; return(local[0]);}

/*:calc-ratio-from-double-support-ratio*/
static pointer M3934gait_generator_calc_ratio_from_double_support_ratio(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeflt(1.0000000000000000000000e+00);
	local[1]= argv[0]->c.obj.iv[15];
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= makeflt(1.0000000000000000000000e+00);
	local[2]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+3;
	w=(pointer)EUSFLOAT(ctx,1,local+2); /*float*/
	local[2]= w;
	local[3]= makeflt(5.0000000000000000000000e-01);
	local[4]= argv[0]->c.obj.iv[15];
	local[5]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,3,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	local[2]= local[1];
	local[3]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto CON3937;
	local[2]= makeflt(0.0000000000000000000000e+00);
	goto CON3936;
CON3937:
	local[2]= local[1];
	local[3]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto CON3938;
	local[2]= makeflt(1.0000000000000000000000e+00);
	goto CON3936;
CON3938:
	local[2]= local[1];
	goto CON3936;
CON3939:
	local[2]= NIL;
CON3936:
	w = local[2];
	local[0]= w;
BLK3935:
	ctx->vsp=local; return(local[0]);}

/*:calc-current-refzmp*/
static pointer M3940gait_generator_calc_current_refzmp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0]->c.obj.iv[12];
	local[1]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	local[0]= w;
	local[1]= makeflt(5.0000000000000000000000e-01);
	local[2]= argv[0]->c.obj.iv[15];
	local[3]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,3,local+1); /***/
	local[1]= w;
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto CON3943;
	local[2]= makeflt(-5.0000000000000000000000e-01);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= argv[3];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(*ftab[37])(ctx,3,local+2,&ftab[37],fqv[346]); /*midpoint*/
	local[2]= w;
	goto CON3942;
CON3943:
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[12];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto CON3944;
	local[2]= makeflt(5.0000000000000000000000e-01);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	local[3]= local[0];
	local[4]= argv[0]->c.obj.iv[12];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= argv[3];
	local[4]= argv[4];
	ctx->vsp=local+5;
	w=(*ftab[37])(ctx,3,local+2,&ftab[37],fqv[346]); /*midpoint*/
	local[2]= w;
	goto CON3942;
CON3944:
	local[2]= argv[3];
	goto CON3942;
CON3945:
	local[2]= NIL;
CON3942:
	w = local[2];
	local[0]= w;
BLK3941:
	ctx->vsp=local; return(local[0]);}

/*:calc-one-tick-gait-parameter*/
static pointer M3946gait_generator_calc_one_tick_gait_parameter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeflt(5.0000000000000000000000e-01);
	local[1]= argv[0]->c.obj.iv[15];
	local[2]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,3,local+0); /***/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)TRUNCATE(ctx,1,local+0); /*truncate*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[13];
	local[2]= argv[0]->c.obj.iv[12];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)GREATERP(ctx,2,local+1); /*>*/
	if (w==NIL) goto CON3949;
	argv[0]->c.obj.iv[28] = makeint((eusinteger_t)0L);
	argv[0]->c.obj.iv[27] = makeint((eusinteger_t)0L);
	argv[0]->c.obj.iv[26] = makeint((eusinteger_t)0L);
	local[1]= argv[0]->c.obj.iv[26];
	goto CON3948;
CON3949:
	local[1]= argv[0]->c.obj.iv[13];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto CON3950;
	argv[0]->c.obj.iv[28] = makeflt(1.0000000000000000000000e+00);
	argv[0]->c.obj.iv[27] = makeint((eusinteger_t)0L);
	argv[0]->c.obj.iv[26] = makeint((eusinteger_t)0L);
	local[1]= argv[0]->c.obj.iv[26];
	goto CON3948;
CON3950:
	local[1]= argv[0];
	local[2]= fqv[347];
	local[3]= argv[0]->c.obj.iv[13];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	local[4]= makeflt(1.0000000000000000000000e+00);
	local[5]= argv[0]->c.obj.iv[26];
	local[6]= argv[0]->c.obj.iv[27];
	local[7]= argv[0]->c.obj.iv[28];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,7,local+1); /*send*/
	local[1]= w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[28] = (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[27] = (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[26] = (w)->c.cons.car;
	w = argv[0]->c.obj.iv[26];
	local[1]= w;
	goto CON3948;
CON3951:
	local[1]= NIL;
CON3948:
	w = local[1];
	w=argv[0]->c.obj.iv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO3953,env,argv,local);
	local[3]= argv[0]->c.obj.iv[7];
	w=argv[0]->c.obj.iv[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,3,local+2); /*mapcar*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[348];
	local[5]= argv[0]->c.obj.iv[10];
	w=argv[0]->c.obj.iv[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,5,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[13];
	local[5]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+6;
	w=(pointer)NUMEQUAL(ctx,2,local+4); /*=*/
	if (w==NIL) goto IF3954;
	argv[0]->c.obj.iv[25] = makeint((eusinteger_t)0L);
	argv[0]->c.obj.iv[24] = makeint((eusinteger_t)0L);
	argv[0]->c.obj.iv[23] = makeint((eusinteger_t)0L);
	local[4]= argv[0]->c.obj.iv[23];
	goto IF3955;
IF3954:
	local[4]= NIL;
IF3955:
	local[4]= argv[0];
	local[5]= fqv[347];
	local[6]= argv[0]->c.obj.iv[13];
	local[7]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	local[7]= makeflt(1.0000000000000000000000e+00);
	local[8]= argv[0]->c.obj.iv[23];
	local[9]= argv[0]->c.obj.iv[24];
	local[10]= argv[0]->c.obj.iv[25];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,7,local+4); /*send*/
	local[4]= w;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[25] = (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[24] = (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[23] = (w)->c.cons.car;
	w = argv[0]->c.obj.iv[23];
	local[4]= argv[0]->c.obj.iv[25];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO3957,env,argv,local);
	local[6]= argv[0]->c.obj.iv[7];
	w=argv[0]->c.obj.iv[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,3,local+5); /*mapcar*/
	local[5]= w;
	local[6]= argv[0];
	local[7]= fqv[320];
	w=argv[0]->c.obj.iv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	w=argv[0]->c.obj.iv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)APPEND(ctx,2,local+6); /*append*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[18];
	local[8]= fqv[349];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= argv[0];
	local[9]= fqv[332];
	local[10]= local[5];
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	ctx->vsp=local+12;
	w=(pointer)APPEND(ctx,2,local+10); /*append*/
	local[10]= w;
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= w;
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[12];
	local[6]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	local[6]= makeflt(5.0000000000000000000000e-01);
	local[7]= argv[0]->c.obj.iv[15];
	local[8]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,3,local+6); /***/
	local[6]= w;
	local[7]= local[5];
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w!=NIL) goto OR3960;
	local[7]= local[5];
	local[8]= argv[0]->c.obj.iv[12];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)GREATERP(ctx,2,local+7); /*>*/
	if (w!=NIL) goto OR3960;
	w=argv[0]->c.obj.iv[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)EUSFLOAT(ctx,1,local+7); /*float*/
	local[7]= w;
	local[8]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+9;
	w=(*ftab[4])(ctx,2,local+7,&ftab[4],fqv[22]); /*eps=*/
	if (w!=NIL) goto OR3960;
	goto IF3958;
OR3960:
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO3961,env,argv,local);
	local[8]= argv[0]->c.obj.iv[19];
	ctx->vsp=local+9;
	w=(pointer)MAPCAR(ctx,2,local+7); /*mapcar*/
	local[7]= w;
	goto IF3959;
IF3958:
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO3962,env,argv,local);
	local[8]= argv[0]->c.obj.iv[19];
	ctx->vsp=local+9;
	w=(pointer)MAPCAR(ctx,2,local+7); /*mapcar*/
	local[7]= w;
IF3959:
	w = local[7];
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,6,local+0); /*list*/
	local[0]= w;
BLK3947:
	ctx->vsp=local; return(local[0]);}

/*:proc-one-tick*/
static pointer M3963gait_generator_proc_one_tick(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[350], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY3965;
	local[0] = fqv[341];
KEY3965:
	if (n & (1<<1)) goto KEY3966;
	local[1] = fqv[351];
KEY3966:
	if (n & (1<<2)) goto KEY3967;
	local[2] = NIL;
KEY3967:
	if (n & (1<<3)) goto KEY3968;
	local[3] = NIL;
KEY3968:
	if (argv[0]->c.obj.iv[5]==NIL) goto IF3969;
	local[4]= argv[0];
	local[5]= fqv[352];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF3970;
IF3969:
	local[4]= NIL;
IF3970:
	local[5]= argv[0]->c.obj.iv[18];
	local[6]= fqv[229];
	if (local[4]==NIL) goto IF3971;
	local[7]= local[4];
	local[8]= makeint((eusinteger_t)3L);
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	goto IF3972;
IF3971:
	local[7]= NIL;
IF3972:
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[18];
	local[7]= fqv[230];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	if (local[5]==NIL) goto IF3973;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= makeint((eusinteger_t)2L);
	local[9]= local[6];
	local[10]= makeint((eusinteger_t)4L);
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SETELT(ctx,3,local+7); /*setelt*/
	local[7]= w;
	goto IF3974;
IF3973:
	local[7]= NIL;
IF3974:
	if (local[5]==NIL) goto IF3975;
	if (local[1]==NIL) goto IF3975;
	local[7]= argv[0];
	local[8]= fqv[353];
	local[9]= local[6];
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	local[10]= local[6];
	local[11]= makeint((eusinteger_t)1L);
	ctx->vsp=local+12;
	w=(pointer)ELT(ctx,2,local+10); /*elt*/
	local[10]= w;
	local[11]= local[6];
	local[12]= makeint((eusinteger_t)2L);
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= fqv[353];
	local[14]= local[1];
	local[15]= fqv[354];
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,10,local+7); /*send*/
	local[7]= w;
	if (local[3]==NIL) goto IF3977;
	local[8]= local[6];
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)BUTLAST(ctx,2,local+8); /*butlast*/
	local[8]= w;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= argv[0]->c.obj.iv[18];
	local[11]= fqv[308];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,2,local+9); /*list*/
	local[9]= w;
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(*ftab[34])(ctx,1,local+10,&ftab[34],fqv[335]); /*last*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)APPEND(ctx,3,local+8); /*append*/
	local[8]= w;
	goto IF3978;
IF3977:
	local[8]= NIL;
IF3978:
	ctx->vsp=local+9;
	w=(pointer)APPEND(ctx,2,local+7); /*append*/
	local[7]= w;
	goto IF3976;
IF3975:
	local[7]= NIL;
IF3976:
	local[8]= makeint((eusinteger_t)0L);
	local[9]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+10;
	w=(pointer)SUB1(ctx,1,local+9); /*1-*/
	argv[0]->c.obj.iv[13] = w;
	local[9]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+10;
	w=(pointer)GREQP(ctx,2,local+8); /*>=*/
	if (w==NIL) goto IF3979;
	local[8]= argv[0];
	local[9]= fqv[355];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	goto IF3980;
IF3979:
	local[8]= NIL;
IF3980:
	w = local[7];
	local[0]= w;
BLK3964:
	ctx->vsp=local; return(local[0]);}

/*:update-current-gait-parameter*/
static pointer M3981gait_generator_update_current_gait_parameter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[10] = (w)->c.cons.car;
	w=argv[0]->c.obj.iv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (argv[0]->c.obj.iv[3]==NIL) goto CON3984;
	local[1]= argv[0];
	local[2]= fqv[334];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto CON3983;
CON3984:
	if (argv[0]->c.obj.iv[17]!=NIL) goto CON3985;
	local[1]= argv[0];
	local[2]= fqv[356];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	argv[0]->c.obj.iv[17] = T;
	local[1]= argv[0]->c.obj.iv[17];
	goto CON3983;
CON3985:
	local[1]= NIL;
CON3983:
	argv[0]->c.obj.iv[13] = argv[0]->c.obj.iv[12];
	w=argv[0]->c.obj.iv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[4] = (w)->c.cons.cdr;
	w = local[1];
	if (argv[0]->c.obj.iv[4]==NIL) goto IF3987;
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO3989,env,argv,local);
	local[2]= argv[0];
	local[3]= fqv[336];
	w=argv[0]->c.obj.iv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	goto IF3988;
IF3987:
	local[1]= NIL;
IF3988:
	argv[0]->c.obj.iv[7] = local[1];
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[5] = (w)->c.cons.cdr;
	w = local[1];
	w=argv[0]->c.obj.iv[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[6] = (w)->c.cons.cdr;
	w = local[0];
	w=argv[0]->c.obj.iv[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[8] = (w)->c.cons.cdr;
	w = local[0];
	w=argv[0]->c.obj.iv[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[11] = (w)->c.cons.cdr;
	w = local[0];
	w=argv[0]->c.obj.iv[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto IF3994;
	w=argv[0]->c.obj.iv[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[9] = (w)->c.cons.car;
	local[0]= argv[0]->c.obj.iv[9];
	goto IF3995;
IF3994:
	w=argv[0]->c.obj.iv[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[9] = (w)->c.cons.car;
	local[0]= argv[0]->c.obj.iv[9];
IF3995:
	w = local[0];
	local[0]= w;
BLK3982:
	ctx->vsp=local; return(local[0]);}

/*:solve-angle-vector*/
static pointer M3996gait_generator_solve_angle_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<6) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[357], &argv[6], n-6, local+0, 0);
	if (n & (1<<0)) goto KEY3998;
	local[0] = fqv[351];
KEY3998:
	if (n & (1<<1)) goto KEY3999;
	local[1] = NIL;
KEY3999:
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[12])(ctx,1,local+2,&ftab[12],fqv[104]); /*functionp*/
	if (w==NIL) goto CON4001;
	local[2]= local[0];
	local[3]= argv[2];
	local[4]= argv[3];
	local[5]= argv[4];
	local[6]= argv[5];
	local[7]= argv[0]->c.obj.iv[1];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,7,local+2); /*apply*/
	local[2]= w;
	goto CON4000;
CON4001:
	w = local[0];
	if (!issymbol(w)) goto CON4002;
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[38])(ctx,2,local+2,&ftab[38],fqv[358]); /*find-method*/
	if (w==NIL) goto CON4002;
	local[2]= (pointer)get_sym_func(fqv[82]);
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= argv[2];
	local[6]= argv[3];
	local[7]= argv[4];
	local[8]= argv[5];
	local[9]= argv[0]->c.obj.iv[1];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(pointer)APPLY(ctx,9,local+2); /*apply*/
	local[2]= w;
	goto CON4000;
CON4002:
	local[2]= fqv[359];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,1,local+2); /*error*/
	local[2]= w;
	goto CON4000;
CON4003:
	local[2]= NIL;
CON4000:
	local[3]= local[2];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= fqv[74];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= fqv[68];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[0]= w;
BLK3997:
	ctx->vsp=local; return(local[0]);}

/*:solve-av-by-move-centroid-on-foot*/
static pointer M4004gait_generator_solve_av_by_move_centroid_on_foot(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<7) maerror();
RST4006:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-7);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[360], &argv[7], n-7, local+1, 1);
	if (n & (1<<0)) goto KEY4007;
	local[1] = makeflt(3.5000000000000000000000e+00);
KEY4007:
	if (n & (1<<1)) goto KEY4008;
	local[2] = makeint((eusinteger_t)100L);
KEY4008:
	if (n & (1<<2)) goto KEY4009;
	local[3] = NIL;
KEY4009:
	local[4]= argv[0];
	local[5]= fqv[320];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)APPEND(ctx,2,local+4); /*append*/
	local[4]= w;
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO4010,env,argv,local);
	local[6]= argv[0]->c.obj.iv[19];
	ctx->vsp=local+7;
	w=(pointer)MAPCAR(ctx,2,local+5); /*mapcar*/
	local[5]= w;
	local[6]= argv[4];
	local[7]= argv[3];
	ctx->vsp=local+8;
	w=(pointer)APPEND(ctx,2,local+6); /*append*/
	local[6]= w;
	local[7]= fqv[264];
	w = local[0];
	if (memq(local[7],w)!=NIL) goto IF4011;
	local[7]= local[0];
	local[8]= fqv[264];
	ctx->vsp=local+9;
	local[9]= makeclosure(codevec,quotevec,CLO4013,env,argv,local);
	local[10]= argv[0]->c.obj.iv[19];
	ctx->vsp=local+11;
	w=(pointer)MAPCAR(ctx,2,local+9); /*mapcar*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,2,local+8); /*list*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)APPEND(ctx,2,local+7); /*append*/
	local[7]= w;
	goto IF4012;
IF4011:
	local[7]= NIL;
IF4012:
	local[7]= fqv[265];
	w = local[0];
	if (memq(local[7],w)!=NIL) goto IF4014;
	local[7]= local[0];
	local[8]= fqv[265];
	ctx->vsp=local+9;
	local[9]= makeclosure(codevec,quotevec,CLO4016,env,argv,local);
	local[10]= argv[0]->c.obj.iv[19];
	ctx->vsp=local+11;
	w=(pointer)MAPCAR(ctx,2,local+9); /*mapcar*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,2,local+8); /*list*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)APPEND(ctx,2,local+7); /*append*/
	local[7]= w;
	goto IF4015;
IF4014:
	local[7]= NIL;
IF4015:
	local[7]= (pointer)get_sym_func(fqv[82]);
	local[8]= argv[6];
	local[9]= fqv[231];
	local[10]= fqv[232];
	local[11]= argv[0]->c.obj.iv[19];
	local[12]= fqv[235];
	local[13]= argv[5];
	local[14]= fqv[361];
	ctx->vsp=local+15;
	local[15]= makeclosure(codevec,quotevec,CLO4017,env,argv,local);
	local[16]= local[5];
	ctx->vsp=local+17;
	w=(pointer)MAPCAR(ctx,2,local+15); /*mapcar*/
	local[15]= w;
	local[16]= fqv[362];
	local[17]= local[1];
	local[18]= fqv[363];
	local[19]= local[2];
	local[20]= fqv[364];
	local[21]= local[3];
	local[22]= argv[6];
	local[23]= fqv[74];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,2,local+22); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	ctx->vsp=local+23;
	local[23]= makeclosure(codevec,quotevec,CLO4018,env,argv,local);
	ctx->vsp=local+24;
	w=(pointer)LIST(ctx,2,local+22); /*list*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)LIST(ctx,1,local+22); /*list*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)APPEND(ctx,2,local+21); /*append*/
	local[21]= w;
	local[22]= local[0];
	ctx->vsp=local+23;
	w=(pointer)APPLY(ctx,16,local+7); /*apply*/
	local[0]= w;
BLK4005:
	ctx->vsp=local; return(local[0]);}

/*:cycloid-midpoint*/
static pointer M4019gait_generator_cycloid_midpoint(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<6) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[339],w);
	ctx->vsp=local+3;
	n=parsekeyparams(fqv[365], &argv[6], n-6, local+3, 0);
	if (n & (1<<0)) goto KEY4021;
	local[3] = makeflt(5.0000000000000000000000e-01);
KEY4021:
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)0L);
	local[6]= argv[5];
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	local[5]= local[3];
	local[6]= argv[3];
	local[7]= argv[4];
	ctx->vsp=local+8;
	w=(*ftab[37])(ctx,3,local+5,&ftab[37],fqv[346]); /*midpoint*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)VPLUS(ctx,2,local+4); /*v+*/
	local[4]= w;
	local[5]= loadglobal(fqv[339]);
	local[6]= makeflt(5.0000000000000000000000e-01);
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto IF4022;
	local[5]= argv[4];
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)VMINUS(ctx,2,local+5); /*v-*/
	local[5]= w;
	goto IF4023;
IF4022:
	local[5]= local[4];
	local[6]= argv[3];
	ctx->vsp=local+7;
	w=(pointer)VMINUS(ctx,2,local+5); /*v-*/
	local[5]= w;
IF4023:
	local[6]= argv[4];
	local[7]= argv[3];
	ctx->vsp=local+8;
	w=(pointer)VMINUS(ctx,2,local+6); /*v-*/
	local[6]= w;
	local[7]= local[5];
	local[8]= makeint((eusinteger_t)2L);
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)ABS(ctx,1,local+7); /*abs*/
	local[7]= w;
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+11;
	w=(pointer)MKFLTVEC(ctx,3,local+8); /*float-vector*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SCALEVEC(ctx,2,local+7); /*scale*/
	local[7]= w;
	local[8]= local[5];
	local[9]= makeint((eusinteger_t)2L);
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)SETELT(ctx,3,local+8); /*setelt*/
	local[8]= local[6];
	local[9]= makeint((eusinteger_t)2L);
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)SETELT(ctx,3,local+8); /*setelt*/
	local[8]= makeflt(2.0000000000000000000000e+00);
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)VNORM(ctx,1,local+9); /*norm*/
	{ double x,y;
		y=fltval(w); x=fltval(local[8]);
		local[8]=(makeflt(x * y));}
	local[9]= makeflt(3.1415926535897931159980e+00);
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(*ftab[1])(ctx,1,local+9,&ftab[1],fqv[3]); /*normalize-vector*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,2,local+8); /*scale*/
	local[8]= w;
	local[9]= local[7];
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+9); /*v**/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[1])(ctx,1,local+9,&ftab[1],fqv[3]); /*normalize-vector*/
	local[9]= w;
	local[10]= makeflt(6.2831853071795862319959e+00);
	local[11]= loadglobal(fqv[339]);
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	local[11]= loadglobal(fqv[339]);
	local[12]= makeflt(5.0000000000000000000000e-01);
	ctx->vsp=local+13;
	w=(pointer)GREATERP(ctx,2,local+11); /*>*/
	if (w==NIL) goto IF4024;
	local[11]= makeflt(-1.5707963267948965579990e+00);
	goto IF4025;
IF4024:
	local[11]= makeflt(0.0000000000000000000000e+00);
IF4025:
	local[12]= makeflt(5.0000000000000000000000e-01);
	local[13]= local[10];
	local[14]= local[10];
	ctx->vsp=local+15;
	w=(pointer)SIN(ctx,1,local+14); /*sin*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)MINUS(ctx,2,local+13); /*-*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)TIMES(ctx,2,local+12); /***/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[11]= w;
	local[12]= makeflt(0.0000000000000000000000e+00);
	local[13]= loadglobal(fqv[339]);
	local[14]= makeflt(5.0000000000000000000000e-01);
	ctx->vsp=local+15;
	w=(pointer)GREATERP(ctx,2,local+13); /*>*/
	if (w==NIL) goto IF4026;
	local[13]= makeint((eusinteger_t)-1L);
	goto IF4027;
IF4026:
	local[13]= makeflt(0.0000000000000000000000e+00);
IF4027:
	local[14]= makeflt(5.0000000000000000000000e-01);
	local[15]= makeflt(1.0000000000000000000000e+00);
	local[16]= local[10];
	ctx->vsp=local+17;
	w=(pointer)COS(ctx,1,local+16); /*cos*/
	{ double x,y;
		y=fltval(w); x=fltval(local[15]);
		local[15]=(makeflt(x - y));}
	{ double x,y;
		y=fltval(local[15]); x=fltval(local[14]);
		local[14]=(makeflt(x * y));}
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,2,local+13); /*+*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)MKFLTVEC(ctx,3,local+11); /*float-vector*/
	local[11]= w;
	local[12]= local[11];
	local[13]= local[8];
	local[14]= local[9];
	local[15]= local[7];
	ctx->vsp=local+16;
	w=(*ftab[39])(ctx,3,local+13,&ftab[39],fqv[366]); /*matrix*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)TRANSFORM(ctx,2,local+12); /*transform*/
	local[12]= w;
	local[13]= local[12];
	local[14]= loadglobal(fqv[339]);
	local[15]= makeflt(5.0000000000000000000000e-01);
	ctx->vsp=local+16;
	w=(pointer)GREATERP(ctx,2,local+14); /*>*/
	if (w==NIL) goto IF4028;
	local[14]= local[4];
	goto IF4029;
IF4028:
	local[14]= argv[3];
IF4029:
	ctx->vsp=local+15;
	w=(pointer)VPLUS(ctx,2,local+13); /*v+*/
	local[4]= w;
	ctx->vsp=local+5;
	unbindx(ctx,1);
	w = local[4];
	local[0]= w;
BLK4020:
	ctx->vsp=local; return(local[0]);}

/*:cycloid-midcoords*/
static pointer M4030gait_generator_cycloid_midcoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<6) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[339],w);
	ctx->vsp=local+3;
	n=parsekeyparams(fqv[367], &argv[6], n-6, local+3, 0);
	if (n & (1<<0)) goto KEY4032;
	local[3] = makeflt(5.0000000000000000000000e-01);
KEY4032:
	if (n & (1<<1)) goto KEY4033;
	local[4] = loadglobal(fqv[339]);
KEY4033:
	local[5]= argv[0];
	local[6]= fqv[368];
	local[7]= loadglobal(fqv[339]);
	local[8]= argv[3];
	local[9]= fqv[5];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= argv[4];
	local[10]= fqv[5];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	local[10]= argv[5];
	local[11]= fqv[369];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,8,local+5); /*send*/
	local[5]= w;
	local[6]= fqv[255];
	local[7]= local[5];
	local[8]= fqv[256];
	local[9]= local[4];
	local[10]= argv[3];
	local[11]= argv[4];
	ctx->vsp=local+12;
	w=(*ftab[36])(ctx,3,local+9,&ftab[36],fqv[342]); /*midcoords*/
	local[9]= w;
	local[10]= fqv[25];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[23])(ctx,4,local+6,&ftab[23],fqv[246]); /*make-coords*/
	local[5]= w;
	ctx->vsp=local+6;
	unbindx(ctx,1);
	w = local[5];
	local[0]= w;
BLK4031:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3873(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[370];
	ctx->vsp=local+2;
	w=(*ftab[38])(ctx,2,local+0,&ftab[38],fqv[358]); /*find-method*/
	if (w==NIL) goto IF4034;
	local[0]= argv[0];
	local[1]= fqv[370];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF4035;
IF4034:
	local[0]= argv[0];
	local[1]= fqv[58];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
IF4035:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3878(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO4036,env,argv,local);
	local[2]= env->c.clo.env1[0]->c.obj.iv[19];
	ctx->vsp=local+3;
	w=(*ftab[40])(ctx,2,local+1,&ftab[40],fqv[371]); /*remove-if-not*/
	w = memq(local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4036(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = env->c.clo.env0->c.clo.env1[2];
	w = memq(local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3881(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[5];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[2];
	local[3]= argv[1];
	w = env->c.clo.env1[0]->c.obj.iv[16];
	w=memq(local[3],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VPLUS(ctx,2,local+0); /*v+*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3886(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = env->c.clo.env1[2];
	w = memq(local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3894(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3901(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!iscons(w)) goto IF4037;
	local[0]= argv[0];
	goto IF4038;
IF4037:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
IF4038:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3902(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0]->c.obj.iv[1];
	local[1]= argv[0];
	local[2]= fqv[262];
	local[3]= fqv[68];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3903(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0]->c.obj.iv[1];
	local[1]= argv[0];
	local[2]= fqv[262];
	local[3]= fqv[68];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3910(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0]->c.obj.iv[1];
	local[1]= argv[0];
	local[2]= fqv[262];
	local[3]= fqv[68];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3913(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = env->c.clo.env2[1];
	if (memq(local[0],w)==NIL) goto IF4039;
	local[0]= env->c.clo.env1[0]->c.obj.iv[5];
	ctx->vsp=local+1;
	w=(*ftab[34])(ctx,1,local+0,&ftab[34],fqv[335]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= argv[0];
	local[2]= env->c.clo.env2[1];
	ctx->vsp=local+3;
	w=(*ftab[19])(ctx,2,local+1,&ftab[19],fqv[201]); /*position*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	goto IF4040;
IF4039:
	local[0]= env->c.clo.env1[0]->c.obj.iv[6];
	ctx->vsp=local+1;
	w=(*ftab[34])(ctx,1,local+0,&ftab[34],fqv[335]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= argv[0];
	local[2]= env->c.clo.env1[0];
	local[3]= fqv[336];
	local[4]= env->c.clo.env2[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[19])(ctx,2,local+1,&ftab[19],fqv[201]); /*position*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
IF4040:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3914(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env2[0];
	local[1]= argv[0];
	local[2]= env->c.clo.env2[1];
	ctx->vsp=local+3;
	w=(*ftab[19])(ctx,2,local+1,&ftab[19],fqv[201]); /*position*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3922(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = env->c.clo.env2[1];
	if (memq(local[0],w)==NIL) goto IF4041;
	local[0]= env->c.clo.env1[0]->c.obj.iv[5];
	ctx->vsp=local+1;
	w=(*ftab[34])(ctx,1,local+0,&ftab[34],fqv[335]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= argv[0];
	local[2]= env->c.clo.env2[1];
	ctx->vsp=local+3;
	w=(*ftab[19])(ctx,2,local+1,&ftab[19],fqv[201]); /*position*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	goto IF4042;
IF4041:
	local[0]= env->c.clo.env1[0]->c.obj.iv[6];
	ctx->vsp=local+1;
	w=(*ftab[34])(ctx,1,local+0,&ftab[34],fqv[335]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= argv[0];
	local[2]= env->c.clo.env1[0];
	local[3]= fqv[336];
	local[4]= env->c.clo.env2[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[19])(ctx,2,local+1,&ftab[19],fqv[201]); /*position*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
IF4042:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3953(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= fqv[372];
	local[2]= env->c.clo.env1[0];
	local[3]= fqv[373];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= argv[1];
	local[5]= fqv[374];
	local[6]= env->c.clo.env1[2];
	local[7]= fqv[375];
	w=env->c.clo.env1[0]->c.obj.iv[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,9,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3957(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= env->c.clo.env2[4];
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(*ftab[36])(ctx,3,local+0,&ftab[36],fqv[342]); /*midcoords*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3961(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = fqv[376];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3962(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w=env->c.clo.env1[0]->c.obj.iv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (memq(local[0],w)==NIL) goto IF4043;
	local[0]= fqv[376];
	goto IF4044;
IF4043:
	local[0]= fqv[377];
IF4044:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3989(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=env->c.clo.env1[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= argv[0];
	local[2]= env->c.clo.env2[0];
	ctx->vsp=local+3;
	w=(*ftab[19])(ctx,2,local+1,&ftab[19],fqv[201]); /*position*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4010(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env2[4];
	ctx->vsp=local+2;
	w=(*ftab[19])(ctx,2,local+0,&ftab[19],fqv[201]); /*position*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4013(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = fqv[378];
	if (memq(local[0],w)==NIL) goto IF4045;
	local[0]= env->c.clo.env1[0]->c.obj.iv[21];
	goto IF4046;
IF4045:
	local[0]= makeint((eusinteger_t)5L);
	local[1]= env->c.clo.env1[0]->c.obj.iv[21];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
IF4046:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4016(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = fqv[379];
	if (memq(local[0],w)==NIL) goto IF4047;
	local[0]= env->c.clo.env1[0]->c.obj.iv[22];
	goto IF4048;
IF4047:
	local[0]= makeint((eusinteger_t)5L);
	local[1]= env->c.clo.env1[0]->c.obj.iv[22];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
IF4048:
	ctx->vsp=local+1;
	w=(*ftab[24])(ctx,1,local+0,&ftab[24],fqv[260]); /*deg2rad*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4017(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env2[6];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4018(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= (pointer)get_sym_func(fqv[342]);
	local[1]= makeflt(5.0000000000000000000000e-01);
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO4049,env,argv,local);
	local[3]= fqv[380];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,3,local+0); /*apply*/
	local[0]= w;
	local[1]= env->c.clo.env1[6];
	local[2]= fqv[2];
	local[3]= env->c.clo.env2[4];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	local[4]= local[3];
	if (fqv[381]!=local[4]) goto IF4051;
	local[4]= fqv[382];
	goto IF4052;
IF4051:
	local[4]= local[3];
	if (fqv[383]!=local[4]) goto IF4053;
	local[4]= fqv[384];
	goto IF4054;
IF4053:
	local[4]= NIL;
IF4054:
IF4052:
	w = local[4];
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= local[0];
	local[3]= fqv[2];
	local[4]= fqv[385];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= local[0];
	local[4]= fqv[207];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)GREATERP(ctx,2,local+3); /*>*/
	if (w==NIL) goto IF4055;
	local[3]= makeint((eusinteger_t)-1L);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SCALEVEC(ctx,2,local+3); /*scale*/
	local[1] = w;
	local[3]= local[1];
	goto IF4056;
IF4055:
	local[3]= NIL;
IF4056:
	local[3]= NIL;
	local[4]= local[1];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,2,local+4); /*list*/
	local[4]= w;
WHL4058:
	if (local[4]==NIL) goto WHX4059;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3];
	local[6]= makeint((eusinteger_t)2L);
	local[7]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+8;
	w=(pointer)SETELT(ctx,3,local+5); /*setelt*/
	goto WHL4058;
WHX4059:
	local[5]= NIL;
BLK4060:
	w = NIL;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)VNORM(ctx,1,local+3); /*norm*/
	local[3]= w;
	local[4]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[22]); /*eps=*/
	if (w==NIL) goto IF4062;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)VNORM(ctx,1,local+3); /*norm*/
	local[3]= w;
	local[4]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[22]); /*eps=*/
	if (w==NIL) goto IF4062;
	local[3]= makeflt(0.0000000000000000000000e+00);
	goto IF4063;
IF4062:
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(*ftab[1])(ctx,1,local+3,&ftab[1],fqv[3]); /*normalize-vector*/
	local[3]= w;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,1,local+4,&ftab[1],fqv[3]); /*normalize-vector*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+3); /*v**/
	local[3]= w;
	local[4]= makeint((eusinteger_t)2L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[41])(ctx,1,local+3,&ftab[41],fqv[386]); /*asin*/
	local[3]= w;
IF4063:
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)0L);
	local[6]= makeint((eusinteger_t)0L);
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)0L);
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,6,local+4); /*float-vector*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4049(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env0->c.clo.env2[6];
	local[1]= argv[0];
	local[2]= env->c.clo.env0->c.clo.env2[4];
	ctx->vsp=local+3;
	w=(*ftab[19])(ctx,2,local+1,&ftab[19],fqv[201]); /*position*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___irtdyna(ctx,n,argv,env)
register context *ctx; int n; pointer *argv; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv;
  register int i;
  numunion nu;
  module=argv[0];
  quotevec=build_quote_vector(ctx,QUOTE_STRINGS_SIZE, quote_strings);
  module->c.code.quotevec=quotevec;
  codevec=module->c.code.codevec;
  fqv=qv=quotevec->c.vec.v;
  init_ftab();
	local[0]= fqv[387];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF4064;
	local[0]= fqv[388];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[389],w);
	goto IF4065;
IF4064:
	local[0]= fqv[390];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF4065:
	local[0]= fqv[391];
	ctx->vsp=local+1;
	w=(*ftab[42])(ctx,1,local+0,&ftab[42],fqv[392]); /*require*/
	local[0]= fqv[393];
	ctx->vsp=local+1;
	w=(*ftab[42])(ctx,1,local+0,&ftab[42],fqv[392]); /*require*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3001joint_calc_inertia_matrix,fqv[71],fqv[394],fqv[395]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[396],module,F2999calc_inertia_matrix_rotational,fqv[397]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[398],module,F3000calc_inertia_matrix_linear,fqv[399]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3022rotational_joint_calc_inertia_matrix,fqv[71],fqv[400],fqv[401]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3024linear_joint_calc_inertia_matrix,fqv[71],fqv[402],fqv[403]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3026omniwheel_joint_calc_inertia_matrix,fqv[71],fqv[404],fqv[405]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3028sphere_joint_calc_inertia_matrix,fqv[71],fqv[406],fqv[407]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M30306dof_joint_calc_inertia_matrix,fqv[71],fqv[408],fqv[409]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3032bodyset_link_append_weight_no_update,fqv[31],fqv[121],fqv[410]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3039bodyset_link_append_centroid_no_update,fqv[33],fqv[121],fqv[411]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3050bodyset_link_append_inertia_no_update,fqv[36],fqv[121],fqv[412]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3063bodyset_link_append_mass_properties,fqv[48],fqv[121],fqv[413]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3079bodyset_link_propagate_mass_properties,fqv[44],fqv[121],fqv[414]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3100bodyset_link_calc_inertia_matrix_column,fqv[83],fqv[121],fqv[415]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3130cascaded_link_update_mass_properties,fqv[80],fqv[416],fqv[417]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3138cascaded_link_calc_inertia_matrix_from_link_list,fqv[90],fqv[416],fqv[418]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3169cascaded_link_calc_cog_jacobian_from_link_list,fqv[95],fqv[416],fqv[419]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3186cascaded_link_cog_jacobian_balance_nspace,fqv[420],fqv[416],fqv[421]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3196cascaded_link_calc_vel_for_cog,fqv[96],fqv[416],fqv[422]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3200cascaded_link_difference_cog_position,fqv[101],fqv[416],fqv[423]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3210cascaded_link_cog_convergence_check,fqv[424],fqv[416],fqv[425]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3231joint_calc_spacial_velocity_jacobian,fqv[135],fqv[394],fqv[426]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3234joint_calc_angular_velocity_jacobian,fqv[137],fqv[394],fqv[427]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3237joint_calc_spacial_acceleration_jacobian,fqv[139],fqv[394],fqv[428]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3240joint_calc_angular_acceleration_jacobian,fqv[142],fqv[394],fqv[429]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3243rotational_joint_calc_spacial_velocity_jacobian,fqv[135],fqv[400],fqv[430]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3245rotational_joint_calc_angular_velocity_jacobian,fqv[137],fqv[400],fqv[431]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3251rotational_joint_calc_spacial_acceleration_jacobian,fqv[139],fqv[400],fqv[432]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3253rotational_joint_calc_angular_acceleration_jacobian,fqv[142],fqv[400],fqv[433]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3255linear_joint_calc_spacial_velocity_jacobian,fqv[135],fqv[402],fqv[434]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3261linear_joint_calc_angular_velocity_jacobian,fqv[137],fqv[402],fqv[435]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3267linear_joint_calc_spacial_acceleration_jacobian,fqv[139],fqv[402],fqv[436]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3269linear_joint_calc_angular_acceleration_jacobian,fqv[142],fqv[402],fqv[437]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3275bodyset_link_reset_dynamics,fqv[438],fqv[121],fqv[439]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3277bodyset_link_angular_velocity,fqv[116],fqv[121],fqv[440]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3283bodyset_link_angular_acceleration,fqv[143],fqv[121],fqv[441]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3289bodyset_link_spacial_velocity,fqv[117],fqv[121],fqv[442]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3295bodyset_link_spacial_acceleration,fqv[140],fqv[121],fqv[443]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3301bodyset_link_force,fqv[150],fqv[121],fqv[444]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3303bodyset_link_moment,fqv[151],fqv[121],fqv[445]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3305bodyset_link_ext_force,fqv[243],fqv[121],fqv[446]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3311bodyset_link_ext_moment,fqv[244],fqv[121],fqv[447]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3317bodyset_link_forward_all_kinematics,fqv[144],fqv[121],fqv[448]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3346bodyset_link_inverse_dynamics,fqv[148],fqv[121],fqv[449]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3365cascaded_link_max_torque_vector,fqv[158],fqv[416],fqv[450]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3381cascaded_link_torque_ratio_vector,fqv[451],fqv[416],fqv[452]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3389cascaded_link_calc_torque_buffer_args,fqv[161],fqv[416],fqv[453]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3391cascaded_link_calc_torque,fqv[203],fqv[416],fqv[454]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3405cascaded_link_calc_torque_without_ext_wrench,fqv[163],fqv[416],fqv[455]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3415cascaded_link_calc_torque_from_vel_acc,fqv[169],fqv[416],fqv[456]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3437cascaded_link_calc_root_coords_vel_acc_from_pos,fqv[170],fqv[416],fqv[457]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3448cascaded_link_calc_av_vel_acc_from_pos,fqv[171],fqv[416],fqv[458]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3458cascaded_link_calc_torque_from_ext_wrenches,fqv[459],fqv[416],fqv[460]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3473cascaded_link_calc_zmp,fqv[227],fqv[416],fqv[461]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3486cascaded_link_calc_cop_from_force_moment,fqv[462],fqv[416],fqv[463]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3494cascaded_link_wrench_vector__wrench_list,fqv[464],fqv[416],fqv[465]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3500cascaded_link_wrench_list__wrench_vector,fqv[466],fqv[416],fqv[467]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3503cascaded_link_calc_contact_wrenches_from_total_wrench,fqv[468],fqv[416],fqv[469]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3513cascaded_link_draw_torque,fqv[470],fqv[416],fqv[471]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3526cascaded_link_weight,fqv[20],fqv[416],fqv[472]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3532cascaded_link_centroid,fqv[30],fqv[416],fqv[473]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3538cascaded_link_inertia_tensor,fqv[26],fqv[416],fqv[474]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3544cascaded_link_preview_control_dynamics_filter,fqv[475],fqv[416],fqv[476]);
	local[0]= fqv[477];
	local[1]= fqv[478];
	local[2]= fqv[477];
	local[3]= fqv[479];
	local[4]= loadglobal(fqv[480]);
	local[5]= fqv[481];
	local[6]= fqv[482];
	local[7]= fqv[483];
	local[8]= NIL;
	local[9]= fqv[484];
	local[10]= NIL;
	local[11]= fqv[108];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[485];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[43])(ctx,13,local+2,&ftab[43],fqv[486]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3607riccati_equation_init,fqv[223],fqv[477],fqv[487]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3609riccati_equation_solve,fqv[285],fqv[477],fqv[488]);
	local[0]= fqv[220];
	local[1]= fqv[478];
	local[2]= fqv[220];
	local[3]= fqv[479];
	local[4]= loadglobal(fqv[477]);
	local[5]= fqv[481];
	local[6]= fqv[489];
	local[7]= fqv[483];
	local[8]= NIL;
	local[9]= fqv[484];
	local[10]= NIL;
	local[11]= fqv[108];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[485];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[43])(ctx,13,local+2,&ftab[43],fqv[486]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3619preview_controller_init,fqv[223],fqv[220],fqv[490]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3639preview_controller_calc_f,fqv[286],fqv[220],fqv[491]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3653preview_controller_calc_u,fqv[287],fqv[220],fqv[492]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3655preview_controller_calc_xk,fqv[289],fqv[220],fqv[493]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3657preview_controller_update_xk,fqv[229],fqv[220],fqv[494]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3701preview_controller_finishedp,fqv[228],fqv[220],fqv[495]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3703preview_controller_last_reference_output_vector,fqv[288],fqv[220],fqv[496]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3705preview_controller_current_reference_output_vector,fqv[290],fqv[220],fqv[497]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3707preview_controller_current_state_vector,fqv[291],fqv[220],fqv[498]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3709preview_controller_current_output_vector,fqv[292],fqv[220],fqv[499]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3711preview_controller_current_additional_data,fqv[230],fqv[220],fqv[500]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3713preview_controller_pass_preview_controller,fqv[501],fqv[220],fqv[502]);
	local[0]= fqv[306];
	local[1]= fqv[478];
	local[2]= fqv[306];
	local[3]= fqv[479];
	local[4]= loadglobal(fqv[220]);
	local[5]= fqv[481];
	local[6]= fqv[503];
	local[7]= fqv[483];
	local[8]= NIL;
	local[9]= fqv[484];
	local[10]= NIL;
	local[11]= fqv[108];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[485];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[43])(ctx,13,local+2,&ftab[43],fqv[486]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3723extended_preview_controller_init,fqv[223],fqv[306],fqv[504]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3788extended_preview_controller_calc_f,fqv[286],fqv[306],fqv[505]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3804extended_preview_controller_calc_u,fqv[287],fqv[306],fqv[506]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3806extended_preview_controller_calc_xk,fqv[289],fqv[306],fqv[507]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3812extended_preview_controller_current_output_vector,fqv[292],fqv[306],fqv[508]);
	local[0]= fqv[222];
	local[1]= fqv[478];
	local[2]= fqv[222];
	local[3]= fqv[479];
	local[4]= loadglobal(fqv[480]);
	local[5]= fqv[481];
	local[6]= fqv[509];
	local[7]= fqv[483];
	local[8]= NIL;
	local[9]= fqv[484];
	local[10]= NIL;
	local[11]= fqv[108];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[485];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[43])(ctx,13,local+2,&ftab[43],fqv[486]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3814preview_control_cart_table_cog_trajectory_generator_init,fqv[223],fqv[222],fqv[510]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3827preview_control_cart_table_cog_trajectory_generator_refcog,fqv[236],fqv[222],fqv[511]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3829preview_control_cart_table_cog_trajectory_generator_cart_zmp,fqv[308],fqv[222],fqv[512]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3831preview_control_cart_table_cog_trajectory_generator_last_refzmp,fqv[513],fqv[222],fqv[514]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3833preview_control_cart_table_cog_trajectory_generator_current_refzmp,fqv[307],fqv[222],fqv[515]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3835preview_control_cart_table_cog_trajectory_generator_update_xk,fqv[229],fqv[222],fqv[516]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3844preview_control_cart_table_cog_trajectory_generator_finishedp,fqv[228],fqv[222],fqv[517]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3847preview_control_cart_table_cog_trajectory_generator_current_additional_data,fqv[230],fqv[222],fqv[518]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3849preview_control_cart_table_cog_trajectory_generator_pass_preview_controller,fqv[501],fqv[222],fqv[519]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3859preview_control_cart_table_cog_trajectory_generator_cog_z,fqv[349],fqv[222],fqv[520]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3861preview_control_cart_table_cog_trajectory_generator_update_cog_z,fqv[521],fqv[222],fqv[522]);
	local[0]= fqv[312];
	local[1]= fqv[478];
	local[2]= fqv[312];
	local[3]= fqv[479];
	local[4]= loadglobal(fqv[480]);
	local[5]= fqv[481];
	local[6]= fqv[523];
	local[7]= fqv[483];
	local[8]= NIL;
	local[9]= fqv[484];
	local[10]= NIL;
	local[11]= fqv[108];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[485];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[43])(ctx,13,local+2,&ftab[43],fqv[486]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3864gait_generator_init,fqv[223],fqv[312],fqv[524]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3871gait_generator_get_footstep_limbs,fqv[321],fqv[312],fqv[525]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3874gait_generator_get_counter_footstep_limbs,fqv[320],fqv[312],fqv[526]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3879gait_generator_get_limbs_zmp_list,fqv[323],fqv[312],fqv[527]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3882gait_generator_get_limbs_zmp,fqv[332],fqv[312],fqv[528]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3884gait_generator_get_swing_limbs,fqv[336],fqv[312],fqv[529]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3887gait_generator_initialize_gait_parameter,fqv[530],fqv[312],fqv[531]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3911gait_generator_finalize_gait_parameter,fqv[356],fqv[312],fqv[532]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3919gait_generator_make_gait_parameter,fqv[334],fqv[312],fqv[533]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3923gait_generator_calc_hoffarbib_pos_vel_acc,fqv[347],fqv[312],fqv[534]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3925gait_generator_calc_current_swing_leg_coords,fqv[372],fqv[312],fqv[535]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3934gait_generator_calc_ratio_from_double_support_ratio,fqv[373],fqv[312],fqv[536]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3940gait_generator_calc_current_refzmp,fqv[348],fqv[312],fqv[537]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3946gait_generator_calc_one_tick_gait_parameter,fqv[352],fqv[312],fqv[538]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3963gait_generator_proc_one_tick,fqv[539],fqv[312],fqv[540]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3981gait_generator_update_current_gait_parameter,fqv[355],fqv[312],fqv[541]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3996gait_generator_solve_angle_vector,fqv[353],fqv[312],fqv[542]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4004gait_generator_solve_av_by_move_centroid_on_foot,fqv[351],fqv[312],fqv[543]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4019gait_generator_cycloid_midpoint,fqv[368],fqv[312],fqv[544]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4030gait_generator_cycloid_midcoords,fqv[344],fqv[312],fqv[545]);
	local[0]= fqv[546];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF4066;
	local[0]= fqv[547];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[389],w);
	goto IF4067;
IF4066:
	local[0]= fqv[548];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF4067:
	local[0]= fqv[549];
	ctx->vsp=local+1;
	w=(*ftab[44])(ctx,1,local+0,&ftab[44],fqv[550]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<45; i++) ftab[i]=fcallx;
}
