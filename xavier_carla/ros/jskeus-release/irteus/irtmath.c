/* ./irtmath.c :  entry=irtmath */
/* compiled by EusLisp 9.27() for Linux created on ip-10-0-1-214(Fri Apr 16 04:05:26 PST 2021) */
#include "eus.h"
#include "irtmath.h"
#pragma init (register_irtmath)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___irtmath();
extern pointer build_quote_vector();
static int register_irtmath()
  { add_module_initializer("___irtmath", ___irtmath);}

static pointer F70inverse_matrix();
static pointer F71diagonal();
static pointer F72minor_matrix();
static pointer F73atan2();
static pointer F74outer_product_matrix();
static pointer F75matrix2quaternion();
static pointer F76quaternion2matrix();
static pointer F77matrix_log();
static pointer F78matrix_exponent();
static pointer F79midrot();
static pointer F80pseudo_inverse();
static pointer F81pseudo_inverse_org();
static pointer F82sr_inverse();
static pointer F83sr_inverse_org();
static pointer F84manipulability();
static pointer F85random_gauss();
static pointer F86gaussian_random();
static pointer F87eigen_decompose();
static pointer F88lms();
static pointer F89lms_estimate();
static pointer F90lms_error();
static pointer F91lmeds();
static pointer F92lmeds_error();
static pointer F93lmeds_error_mat();
static pointer F94concatenate_matrix_column();
static pointer F95concatenate_matrix_row();
static pointer F96concatenate_matrix_diagonal();
static pointer F97vector_variance();
static pointer F98covariance_matrix();
static pointer F99normalize_vector();

/*inverse-matrix*/
static pointer F70inverse_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[0]); /*array-dimension*/
	local[0]= w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,1,local+1,&ftab[1],fqv[1]); /*unit-matrix*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(*ftab[2])(ctx,2,local+2,&ftab[2],fqv[2]); /*lu-decompose2*/
	local[2]= w;
	local[3]= NIL;
	local[4]= local[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[3])(ctx,2,local+4,&ftab[3],fqv[3]); /*make-matrix*/
	local[4]= w;
	local[5]= loadglobal(fqv[4]);
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,2,local+5); /*instantiate*/
	local[5]= w;
	local[6]= makeint((eusinteger_t)0L);
	if (local[2]!=NIL) goto IF101;
	local[7]= fqv[5];
	ctx->vsp=local+8;
	w=(*ftab[4])(ctx,1,local+7,&ftab[4],fqv[6]); /*warn*/
	w = local[1];
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK100;
	goto IF102;
IF101:
	local[7]= NIL;
IF102:
	local[7]= makeint((eusinteger_t)0L);
	local[8]= local[0];
WHL104:
	local[9]= local[7];
	w = local[8];
	if ((eusinteger_t)local[9] >= (eusinteger_t)w) goto WHX105;
	local[9]= argv[0];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(*ftab[2])(ctx,2,local+9,&ftab[2],fqv[2]); /*lu-decompose2*/
	local[2] = w;
	local[9]= local[5];
	local[10]= local[7];
	local[11]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+12;
	w=(pointer)ASET(ctx,3,local+9); /*aset*/
	local[9]= local[1];
	local[10]= local[2];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(*ftab[5])(ctx,3,local+9,&ftab[5],fqv[7]); /*lu-solve2*/
	local[3] = w;
	local[9]= makeint((eusinteger_t)0L);
	local[10]= local[0];
WHL108:
	local[11]= local[9];
	w = local[10];
	if ((eusinteger_t)local[11] >= (eusinteger_t)w) goto WHX109;
	local[11]= local[4];
	local[12]= local[9];
	local[13]= local[7];
	local[14]= local[3];
	local[15]= local[9];
	ctx->vsp=local+16;
	w=(pointer)AREF(ctx,2,local+14); /*aref*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)ASET(ctx,4,local+11); /*aset*/
	local[11]= local[9];
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[9] = w;
	goto WHL108;
WHX109:
	local[11]= NIL;
BLK110:
	w = NIL;
	local[9]= local[5];
	local[10]= local[7];
	local[11]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+12;
	w=(pointer)ASET(ctx,3,local+9); /*aset*/
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	local[7] = w;
	goto WHL104;
WHX105:
	local[9]= NIL;
BLK106:
	w = NIL;
	w = local[4];
	local[0]= w;
BLK100:
	ctx->vsp=local; return(local[0]);}

/*diagonal*/
static pointer F71diagonal(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= local[0];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,2,local+1,&ftab[3],fqv[3]); /*make-matrix*/
	local[1]= w;
	local[2]= makeint((eusinteger_t)0L);
	local[3]= local[0];
WHL113:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX114;
	local[4]= local[1];
	local[5]= local[2];
	local[6]= local[2];
	local[7]= argv[0];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)ASET(ctx,4,local+4); /*aset*/
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL113;
WHX114:
	local[4]= NIL;
BLK115:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK111:
	ctx->vsp=local; return(local[0]);}

/*minor-matrix*/
static pointer F72minor_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[0]); /*array-dimension*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)SUB1(ctx,1,local+0); /*1-*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= makeint((eusinteger_t)1L);
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[0]); /*array-dimension*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SUB1(ctx,1,local+1); /*1-*/
	local[1]= w;
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(*ftab[3])(ctx,2,local+2,&ftab[3],fqv[3]); /*make-matrix*/
	local[2]= w;
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
TAG119:
	local[5]= local[3];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)NUMEQUAL(ctx,2,local+5); /*=*/
	if (w==NIL) goto IF120;
	w = NIL;
	ctx->vsp=local+5;
	local[3]=w;
	goto BLK118;
	goto IF121;
IF120:
	local[5]= NIL;
IF121:
	local[5]= local[4];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)NUMEQUAL(ctx,2,local+5); /*=*/
	if (w==NIL) goto IF122;
	local[5]= local[4];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[4] = w;
	local[5]= local[4];
	goto IF123;
IF122:
	local[5]= NIL;
IF123:
	local[5]= makeint((eusinteger_t)0L);
	local[6]= makeint((eusinteger_t)0L);
TAG126:
	local[7]= local[5];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)NUMEQUAL(ctx,2,local+7); /*=*/
	if (w==NIL) goto IF127;
	w = NIL;
	ctx->vsp=local+7;
	local[5]=w;
	goto BLK125;
	goto IF128;
IF127:
	local[7]= NIL;
IF128:
	local[7]= local[6];
	local[8]= argv[2];
	ctx->vsp=local+9;
	w=(pointer)NUMEQUAL(ctx,2,local+7); /*=*/
	if (w==NIL) goto IF129;
	local[7]= local[6];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[6] = w;
	local[7]= local[6];
	goto IF130;
IF129:
	local[7]= NIL;
IF130:
	local[7]= local[2];
	local[8]= local[3];
	local[9]= local[5];
	local[10]= argv[0];
	local[11]= local[4];
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,3,local+10); /*aref*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)ASET(ctx,4,local+7); /*aset*/
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[7]= w;
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[8]= w;
	local[5] = local[7];
	local[6] = local[8];
	w = NIL;
	ctx->vsp=local+7;
	goto TAG126;
	w = NIL;
	local[5]= w;
BLK125:
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[5]= w;
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[6]= w;
	local[3] = local[5];
	local[4] = local[6];
	w = NIL;
	ctx->vsp=local+5;
	goto TAG119;
	w = NIL;
	local[3]= w;
BLK118:
	w = local[2];
	local[0]= w;
BLK116:
	ctx->vsp=local; return(local[0]);}

/*atan2*/
static pointer F73atan2(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeflt(9.9999999999999964869129e-11);
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,1,local+1); /*-*/
	local[1]= w;
	local[2]= argv[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto IF136;
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ATAN(ctx,1,local+2); /*atan*/
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK135;
	goto IF137;
IF136:
	local[2]= NIL;
IF137:
	local[2]= argv[1];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto IF138;
	local[2]= argv[0];
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto IF140;
	local[2]= makeflt(3.1415926535897931159980e+00);
	local[3]= argv[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ATAN(ctx,1,local+3); /*atan*/
	{ double x,y;
		y=fltval(w); x=fltval(local[2]);
		local[2]=(makeflt(x + y));}
	w = local[2];
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK135;
	goto IF141;
IF140:
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ATAN(ctx,1,local+2); /*atan*/
	local[2]= w;
	{ double x,y;
		y=fltval(makeflt(3.1415926535897931159980e+00)); x=fltval(local[2]);
		local[2]=(makeflt(x - y));}
	w = local[2];
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK135;
IF141:
	goto IF139;
IF138:
	local[2]= NIL;
IF139:
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)ABS(ctx,1,local+2); /*abs*/
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto IF142;
	w = makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK135;
	goto IF143;
IF142:
	local[2]= NIL;
IF143:
	local[2]= argv[0];
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto IF144;
	local[2]= makeflt(1.5707963267948965579990e+00);
	goto IF145;
IF144:
	local[2]= makeflt(-1.5707963267948965579990e+00);
IF145:
	w = local[2];
	local[0]= w;
BLK135:
	ctx->vsp=local; return(local[0]);}

/*outer-product-matrix*/
static pointer F74outer_product_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT148;}
	local[0]= makeint((eusinteger_t)3L);
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[1]); /*unit-matrix*/
	local[0]= w;
ENT148:
ENT147:
	if (n>2) maerror();
	local[1]= local[0];
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,4,local+1); /*aset*/
	local[1]= local[0];
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)1L);
	local[4]= argv[0];
	local[5]= makeint((eusinteger_t)2L);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,1,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,4,local+1); /*aset*/
	local[1]= local[0];
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)2L);
	local[4]= argv[0];
	local[5]= makeint((eusinteger_t)1L);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,4,local+1); /*aset*/
	local[1]= local[0];
	local[2]= makeint((eusinteger_t)1L);
	local[3]= makeint((eusinteger_t)0L);
	local[4]= argv[0];
	local[5]= makeint((eusinteger_t)2L);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,4,local+1); /*aset*/
	local[1]= local[0];
	local[2]= makeint((eusinteger_t)1L);
	local[3]= makeint((eusinteger_t)1L);
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,4,local+1); /*aset*/
	local[1]= local[0];
	local[2]= makeint((eusinteger_t)1L);
	local[3]= makeint((eusinteger_t)2L);
	local[4]= argv[0];
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,1,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,4,local+1); /*aset*/
	local[1]= local[0];
	local[2]= makeint((eusinteger_t)2L);
	local[3]= makeint((eusinteger_t)0L);
	local[4]= argv[0];
	local[5]= makeint((eusinteger_t)1L);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,1,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,4,local+1); /*aset*/
	local[1]= local[0];
	local[2]= makeint((eusinteger_t)2L);
	local[3]= makeint((eusinteger_t)1L);
	local[4]= argv[0];
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,4,local+1); /*aset*/
	local[1]= local[0];
	local[2]= makeint((eusinteger_t)2L);
	local[3]= makeint((eusinteger_t)2L);
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,4,local+1); /*aset*/
	w = local[0];
	local[0]= w;
BLK146:
	ctx->vsp=local; return(local[0]);}

/*matrix2quaternion*/
static pointer F75matrix2quaternion(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= makeint((eusinteger_t)1L);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)1L);
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	local[8]= argv[0];
	local[9]= makeint((eusinteger_t)2L);
	local[10]= makeint((eusinteger_t)2L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,4,local+5); /*+*/
	local[5]= w;
	local[6]= makeint((eusinteger_t)4L);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= makeint((eusinteger_t)1L);
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	local[8]= argv[0];
	local[9]= makeint((eusinteger_t)1L);
	local[10]= makeint((eusinteger_t)1L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,1,local+8); /*-*/
	local[8]= w;
	local[9]= argv[0];
	local[10]= makeint((eusinteger_t)2L);
	local[11]= makeint((eusinteger_t)2L);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,3,local+9); /*aref*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,1,local+9); /*-*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,4,local+6); /*+*/
	local[6]= w;
	local[7]= makeint((eusinteger_t)4L);
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	local[7]= makeint((eusinteger_t)1L);
	local[8]= argv[0];
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,1,local+8); /*-*/
	local[8]= w;
	local[9]= argv[0];
	local[10]= makeint((eusinteger_t)1L);
	local[11]= makeint((eusinteger_t)1L);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,3,local+9); /*aref*/
	local[9]= w;
	local[10]= argv[0];
	local[11]= makeint((eusinteger_t)2L);
	local[12]= makeint((eusinteger_t)2L);
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,3,local+10); /*aref*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,1,local+10); /*-*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,4,local+7); /*+*/
	local[7]= w;
	local[8]= makeint((eusinteger_t)4L);
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	local[7]= w;
	local[8]= makeint((eusinteger_t)1L);
	local[9]= argv[0];
	local[10]= makeint((eusinteger_t)0L);
	local[11]= makeint((eusinteger_t)0L);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,3,local+9); /*aref*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,1,local+9); /*-*/
	local[9]= w;
	local[10]= argv[0];
	local[11]= makeint((eusinteger_t)1L);
	local[12]= makeint((eusinteger_t)1L);
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,3,local+10); /*aref*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,1,local+10); /*-*/
	local[10]= w;
	local[11]= argv[0];
	local[12]= makeint((eusinteger_t)2L);
	local[13]= makeint((eusinteger_t)2L);
	ctx->vsp=local+14;
	w=(pointer)AREF(ctx,3,local+11); /*aref*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,4,local+8); /*+*/
	local[8]= w;
	local[9]= makeint((eusinteger_t)4L);
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	local[9]= local[5];
	local[10]= local[6];
	local[11]= local[7];
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(pointer)MAX(ctx,4,local+9); /*max*/
	local[4] = w;
	local[9]= local[4];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(*ftab[6])(ctx,2,local+9,&ftab[6],fqv[8]); /*eps=*/
	if (w==NIL) goto CON151;
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)SQRT(ctx,1,local+9); /*sqrt*/
	local[0] = w;
	local[9]= argv[0];
	local[10]= makeint((eusinteger_t)2L);
	local[11]= makeint((eusinteger_t)1L);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,3,local+9); /*aref*/
	local[9]= w;
	local[10]= argv[0];
	local[11]= makeint((eusinteger_t)1L);
	local[12]= makeint((eusinteger_t)2L);
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,3,local+10); /*aref*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,2,local+9); /*-*/
	local[9]= w;
	local[10]= makeint((eusinteger_t)4L);
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[1] = w;
	local[9]= argv[0];
	local[10]= makeint((eusinteger_t)0L);
	local[11]= makeint((eusinteger_t)2L);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,3,local+9); /*aref*/
	local[9]= w;
	local[10]= argv[0];
	local[11]= makeint((eusinteger_t)2L);
	local[12]= makeint((eusinteger_t)0L);
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,3,local+10); /*aref*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,2,local+9); /*-*/
	local[9]= w;
	local[10]= makeint((eusinteger_t)4L);
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[2] = w;
	local[9]= argv[0];
	local[10]= makeint((eusinteger_t)1L);
	local[11]= makeint((eusinteger_t)0L);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,3,local+9); /*aref*/
	local[9]= w;
	local[10]= argv[0];
	local[11]= makeint((eusinteger_t)0L);
	local[12]= makeint((eusinteger_t)1L);
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,3,local+10); /*aref*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,2,local+9); /*-*/
	local[9]= w;
	local[10]= makeint((eusinteger_t)4L);
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[3] = w;
	local[9]= local[3];
	goto CON150;
CON151:
	local[9]= local[4];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(*ftab[6])(ctx,2,local+9,&ftab[6],fqv[8]); /*eps=*/
	if (w==NIL) goto CON152;
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)SQRT(ctx,1,local+9); /*sqrt*/
	local[1] = w;
	local[9]= argv[0];
	local[10]= makeint((eusinteger_t)2L);
	local[11]= makeint((eusinteger_t)1L);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,3,local+9); /*aref*/
	local[9]= w;
	local[10]= argv[0];
	local[11]= makeint((eusinteger_t)1L);
	local[12]= makeint((eusinteger_t)2L);
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,3,local+10); /*aref*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,2,local+9); /*-*/
	local[9]= w;
	local[10]= makeint((eusinteger_t)4L);
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[0] = w;
	local[9]= argv[0];
	local[10]= makeint((eusinteger_t)0L);
	local[11]= makeint((eusinteger_t)1L);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,3,local+9); /*aref*/
	local[9]= w;
	local[10]= argv[0];
	local[11]= makeint((eusinteger_t)1L);
	local[12]= makeint((eusinteger_t)0L);
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,3,local+10); /*aref*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	local[10]= makeint((eusinteger_t)4L);
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[2] = w;
	local[9]= argv[0];
	local[10]= makeint((eusinteger_t)0L);
	local[11]= makeint((eusinteger_t)2L);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,3,local+9); /*aref*/
	local[9]= w;
	local[10]= argv[0];
	local[11]= makeint((eusinteger_t)2L);
	local[12]= makeint((eusinteger_t)0L);
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,3,local+10); /*aref*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	local[10]= makeint((eusinteger_t)4L);
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[3] = w;
	local[9]= local[3];
	goto CON150;
CON152:
	local[9]= local[4];
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(*ftab[6])(ctx,2,local+9,&ftab[6],fqv[8]); /*eps=*/
	if (w==NIL) goto CON153;
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)SQRT(ctx,1,local+9); /*sqrt*/
	local[2] = w;
	local[9]= argv[0];
	local[10]= makeint((eusinteger_t)0L);
	local[11]= makeint((eusinteger_t)2L);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,3,local+9); /*aref*/
	local[9]= w;
	local[10]= argv[0];
	local[11]= makeint((eusinteger_t)2L);
	local[12]= makeint((eusinteger_t)0L);
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,3,local+10); /*aref*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,2,local+9); /*-*/
	local[9]= w;
	local[10]= makeint((eusinteger_t)4L);
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[0] = w;
	local[9]= argv[0];
	local[10]= makeint((eusinteger_t)0L);
	local[11]= makeint((eusinteger_t)1L);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,3,local+9); /*aref*/
	local[9]= w;
	local[10]= argv[0];
	local[11]= makeint((eusinteger_t)1L);
	local[12]= makeint((eusinteger_t)0L);
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,3,local+10); /*aref*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	local[10]= makeint((eusinteger_t)4L);
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[1] = w;
	local[9]= argv[0];
	local[10]= makeint((eusinteger_t)1L);
	local[11]= makeint((eusinteger_t)2L);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,3,local+9); /*aref*/
	local[9]= w;
	local[10]= argv[0];
	local[11]= makeint((eusinteger_t)2L);
	local[12]= makeint((eusinteger_t)1L);
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,3,local+10); /*aref*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	local[10]= makeint((eusinteger_t)4L);
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[3] = w;
	local[9]= local[3];
	goto CON150;
CON153:
	local[9]= local[4];
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(*ftab[6])(ctx,2,local+9,&ftab[6],fqv[8]); /*eps=*/
	if (w==NIL) goto CON154;
	local[9]= local[8];
	ctx->vsp=local+10;
	w=(pointer)SQRT(ctx,1,local+9); /*sqrt*/
	local[3] = w;
	local[9]= argv[0];
	local[10]= makeint((eusinteger_t)1L);
	local[11]= makeint((eusinteger_t)0L);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,3,local+9); /*aref*/
	local[9]= w;
	local[10]= argv[0];
	local[11]= makeint((eusinteger_t)0L);
	local[12]= makeint((eusinteger_t)1L);
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,3,local+10); /*aref*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,2,local+9); /*-*/
	local[9]= w;
	local[10]= makeint((eusinteger_t)4L);
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[0] = w;
	local[9]= argv[0];
	local[10]= makeint((eusinteger_t)0L);
	local[11]= makeint((eusinteger_t)2L);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,3,local+9); /*aref*/
	local[9]= w;
	local[10]= argv[0];
	local[11]= makeint((eusinteger_t)2L);
	local[12]= makeint((eusinteger_t)0L);
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,3,local+10); /*aref*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	local[10]= makeint((eusinteger_t)4L);
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[1] = w;
	local[9]= argv[0];
	local[10]= makeint((eusinteger_t)1L);
	local[11]= makeint((eusinteger_t)2L);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,3,local+9); /*aref*/
	local[9]= w;
	local[10]= argv[0];
	local[11]= makeint((eusinteger_t)2L);
	local[12]= makeint((eusinteger_t)1L);
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,3,local+10); /*aref*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	local[10]= makeint((eusinteger_t)4L);
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[2] = w;
	local[9]= local[2];
	goto CON150;
CON154:
	local[9]= fqv[9];
	ctx->vsp=local+10;
	w=(*ftab[4])(ctx,1,local+9,&ftab[4],fqv[6]); /*warn*/
	local[9]= w;
	goto CON150;
CON155:
	local[9]= NIL;
CON150:
	local[9]= local[0];
	local[10]= local[1];
	local[11]= local[2];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)MKFLTVEC(ctx,4,local+9); /*float-vector*/
	local[0]= w;
BLK149:
	ctx->vsp=local; return(local[0]);}

/*quaternion2matrix*/
static pointer F76quaternion2matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= makeint((eusinteger_t)1L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= makeint((eusinteger_t)2L);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= makeint((eusinteger_t)3L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)VINNERPRODUCT(ctx,2,local+4); /*v.*/
	local[4]= w;
	local[5]= makeflt(1.0000000000000000000000e+00);
	local[6]= makeflt(9.9999999999999950039964e-03);
	ctx->vsp=local+7;
	w=(*ftab[6])(ctx,3,local+4,&ftab[6],fqv[8]); /*eps=*/
	if (w!=NIL) goto IF157;
	local[4]= makeint((eusinteger_t)1L);
	local[5]= fqv[10];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(*ftab[7])(ctx,3,local+4,&ftab[7],fqv[11]); /*warning-message*/
	local[4]= w;
	goto IF158;
IF157:
	local[4]= NIL;
IF158:
	local[4]= makeint((eusinteger_t)3L);
	local[5]= makeint((eusinteger_t)3L);
	local[6]= local[0];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	local[7]= local[1];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	local[8]= local[2];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,1,local+8); /*-*/
	local[8]= w;
	local[9]= local[3];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,1,local+9); /*-*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,4,local+6); /*+*/
	local[6]= w;
	local[7]= makeint((eusinteger_t)2L);
	local[8]= local[1];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	local[9]= local[0];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	local[8]= makeint((eusinteger_t)2L);
	local[9]= local[1];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	local[10]= local[0];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,3,local+6); /*float-vector*/
	local[6]= w;
	local[7]= makeint((eusinteger_t)2L);
	local[8]= local[1];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	local[9]= local[0];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	local[8]= local[0];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	local[9]= local[1];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,1,local+9); /*-*/
	local[9]= w;
	local[10]= local[2];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	local[11]= local[3];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)MINUS(ctx,1,local+11); /*-*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,4,local+8); /*+*/
	local[8]= w;
	local[9]= makeint((eusinteger_t)2L);
	local[10]= local[2];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	local[11]= local[0];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)MINUS(ctx,2,local+10); /*-*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,3,local+7); /*float-vector*/
	local[7]= w;
	local[8]= makeint((eusinteger_t)2L);
	local[9]= local[1];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	local[10]= local[0];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,2,local+9); /*-*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	local[9]= makeint((eusinteger_t)2L);
	local[10]= local[2];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	local[11]= local[0];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	local[10]= local[0];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	local[11]= local[1];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)MINUS(ctx,1,local+11); /*-*/
	local[11]= w;
	local[12]= local[2];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)TIMES(ctx,2,local+12); /***/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)MINUS(ctx,1,local+12); /*-*/
	local[12]= w;
	local[13]= local[3];
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(pointer)TIMES(ctx,2,local+13); /***/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,4,local+10); /*+*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)MKFLTVEC(ctx,3,local+8); /*float-vector*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,3,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[3])(ctx,3,local+4,&ftab[3],fqv[3]); /*make-matrix*/
	local[0]= w;
BLK156:
	ctx->vsp=local; return(local[0]);}

/*matrix-log*/
static pointer F77matrix_log(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F75matrix2quaternion(ctx,1,local+0); /*matrix2quaternion*/
	local[0]= w;
	local[1]= local[0];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= local[0];
	local[3]= makeint((eusinteger_t)1L);
	local[4]= makeint((eusinteger_t)4L);
	ctx->vsp=local+5;
	w=(pointer)SUBSEQ(ctx,3,local+2); /*subseq*/
	local[2]= w;
	local[3]= makeflt(2.0000000000000000000000e+00);
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)VNORM(ctx,1,local+4); /*norm*/
	local[4]= w;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)ATAN(ctx,2,local+4); /*atan*/
	{ double x,y;
		y=fltval(w); x=fltval(local[3]);
		local[3]=(makeflt(x * y));}
	local[4]= local[3];
	local[5]= makeflt(3.1415926535897931159980e+00);
	ctx->vsp=local+6;
	w=(pointer)GREATERP(ctx,2,local+4); /*>*/
	if (w==NIL) goto CON161;
	local[4]= local[3];
	local[5]= makeflt(6.2831853071795862319959e+00);
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[3] = w;
	local[4]= local[3];
	goto CON160;
CON161:
	local[4]= local[3];
	local[5]= makeflt(-3.1415926535897931159980e+00);
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,2,local+4); /*<*/
	if (w==NIL) goto CON162;
	local[4]= local[3];
	local[5]= makeflt(6.2831853071795862319959e+00);
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[3] = w;
	local[4]= local[3];
	goto CON160;
CON162:
	local[4]= NIL;
CON160:
	local[4]= local[3];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)F99normalize_vector(ctx,1,local+5); /*normalize-vector*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SCALEVEC(ctx,2,local+4); /*scale*/
	local[0]= w;
BLK159:
	ctx->vsp=local; return(local[0]);}

/*matrix-exponent*/
static pointer F78matrix_exponent(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT165;}
	local[0]= makeflt(1.0000000000000000000000e+00);
ENT165:
ENT164:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)VNORM(ctx,1,local+3); /*norm*/
	local[1] = w;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F99normalize_vector(ctx,1,local+3); /*normalize-vector*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)F74outer_product_matrix(ctx,1,local+3); /*outer-product-matrix*/
	local[2] = w;
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,0,local+3,&ftab[1],fqv[1]); /*unit-matrix*/
	local[3]= w;
	local[4]= local[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SIN(ctx,1,local+4); /*sin*/
	local[4]= w;
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(*ftab[8])(ctx,2,local+4,&ftab[8],fqv[12]); /*scale-matrix*/
	local[4]= w;
	local[5]= makeflt(1.0000000000000000000000e+00);
	local[6]= local[1];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)COS(ctx,1,local+6); /*cos*/
	{ double x,y;
		y=fltval(w); x=fltval(local[5]);
		local[5]=(makeflt(x - y));}
	local[6]= local[2];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)MATTIMES(ctx,2,local+6); /*m**/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[8])(ctx,2,local+5,&ftab[8],fqv[12]); /*scale-matrix*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[9])(ctx,2,local+4,&ftab[9],fqv[13]); /*m+*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[9])(ctx,2,local+3,&ftab[9],fqv[13]); /*m+*/
	local[0]= w;
BLK163:
	ctx->vsp=local; return(local[0]);}

/*midrot*/
static pointer F79midrot(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)TRANSPOSE(ctx,1,local+2); /*transpose*/
	local[2]= w;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)MATTIMES(ctx,2,local+2); /*m**/
	local[0] = w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F77matrix_log(ctx,1,local+2); /*matrix-log*/
	local[1] = w;
	local[2]= local[1];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F78matrix_exponent(ctx,2,local+2); /*matrix-exponent*/
	local[0] = w;
	local[2]= argv[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)MATTIMES(ctx,2,local+2); /*m**/
	local[0]= w;
BLK166:
	ctx->vsp=local; return(local[0]);}

/*pseudo-inverse*/
static pointer F80pseudo_inverse(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT172;}
	local[0]= NIL;
ENT172:
	if (n>=3) { local[1]=(argv[2]); goto ENT171;}
	local[1]= NIL;
ENT171:
	if (n>=4) { local[2]=(argv[3]); goto ENT170;}
	local[2]= NIL;
ENT170:
	if (n>=5) { local[3]=(argv[4]); goto ENT169;}
	local[3]= NIL;
ENT169:
ENT168:
	if (n>5) maerror();
	local[4]= argv[0];
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(*ftab[0])(ctx,2,local+4,&ftab[0],fqv[0]); /*array-dimension*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,2,local+5,&ftab[0],fqv[0]); /*array-dimension*/
	local[5]= w;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	if (local[1]!=NIL) goto IF173;
	local[9]= local[5];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(*ftab[3])(ctx,2,local+9,&ftab[3],fqv[3]); /*make-matrix*/
	local[1] = w;
	local[9]= local[1];
	goto IF174;
IF173:
	local[9]= NIL;
IF174:
	if (local[0]!=NIL) goto IF175;
	local[9]= argv[0];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(*ftab[10])(ctx,2,local+9,&ftab[10],fqv[14]); /*pseudo-inverse2*/
	ctx->vsp=local+9;
	local[0]=w;
	goto BLK167;
	goto IF176;
IF175:
	local[9]= NIL;
IF176:
	local[9]= local[4];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)MAX(ctx,2,local+9); /*max*/
	local[6] = w;
	if (local[2]!=NIL) goto IF177;
	local[9]= local[6];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(*ftab[3])(ctx,2,local+9,&ftab[3],fqv[3]); /*make-matrix*/
	local[2] = w;
	local[9]= local[2];
	goto IF178;
IF177:
	local[9]= NIL;
IF178:
	if (local[3]!=NIL) goto IF179;
	local[9]= local[4];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(*ftab[3])(ctx,2,local+9,&ftab[3],fqv[3]); /*make-matrix*/
	local[3] = w;
	local[9]= local[3];
	goto IF180;
IF179:
	local[9]= NIL;
IF180:
	local[9]= makeint((eusinteger_t)0L);
	local[10]= local[6];
WHL182:
	local[11]= local[9];
	w = local[10];
	if ((eusinteger_t)local[11] >= (eusinteger_t)w) goto WHX183;
	local[11]= local[2];
	local[12]= local[9];
	local[13]= local[9];
	local[14]= local[0];
	local[15]= local[9];
	ctx->vsp=local+16;
	w=(pointer)AREF(ctx,2,local+14); /*aref*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SQRT(ctx,1,local+14); /*sqrt*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)ASET(ctx,4,local+11); /*aset*/
	local[11]= local[9];
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[9] = w;
	goto WHL182;
WHX183:
	local[11]= NIL;
BLK184:
	w = NIL;
	local[9]= local[4];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)LSEQP(ctx,2,local+9); /*<=*/
	if (w==NIL) goto IF185;
	local[9]= argv[0];
	local[10]= local[2];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)MATTIMES(ctx,3,local+9); /*m**/
	local[9]= w;
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(*ftab[10])(ctx,2,local+9,&ftab[10],fqv[14]); /*pseudo-inverse2*/
	local[7] = w;
	if (local[7]==NIL) goto IF187;
	local[9]= local[2];
	local[10]= local[7];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)MATTIMES(ctx,3,local+9); /*m**/
	local[9]= w;
	goto IF188;
IF187:
	local[9]= NIL;
IF188:
	goto IF186;
IF185:
	local[9]= local[2];
	local[10]= argv[0];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)MATTIMES(ctx,3,local+9); /*m**/
	local[9]= w;
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(*ftab[10])(ctx,2,local+9,&ftab[10],fqv[14]); /*pseudo-inverse2*/
	local[7] = w;
	if (local[7]==NIL) goto IF189;
	local[9]= local[7];
	local[10]= local[2];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)MATTIMES(ctx,3,local+9); /*m**/
	local[9]= w;
	goto IF190;
IF189:
	local[9]= NIL;
IF190:
IF186:
	w = local[9];
	local[0]= w;
BLK167:
	ctx->vsp=local; return(local[0]);}

/*pseudo-inverse-org*/
static pointer F81pseudo_inverse_org(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT195;}
	local[0]= NIL;
ENT195:
	if (n>=3) { local[1]=(argv[2]); goto ENT194;}
	local[1]= NIL;
ENT194:
	if (n>=4) { local[2]=(argv[3]); goto ENT193;}
	local[2]= NIL;
ENT193:
ENT192:
	if (n>4) maerror();
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(*ftab[11])(ctx,1,local+9,&ftab[11],fqv[15]); /*array-dimensions*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(*ftab[12])(ctx,1,local+9,&ftab[12],fqv[16]); /*sv-decompose*/
	local[4] = w;
	if (local[4]!=NIL) goto IF196;
	local[9]= fqv[17];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(*ftab[4])(ctx,2,local+9,&ftab[4],fqv[6]); /*warn*/
	w = NIL;
	ctx->vsp=local+9;
	local[0]=w;
	goto BLK191;
	goto IF197;
IF196:
	local[9]= NIL;
IF197:
	local[9]= local[4];
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[5] = w;
	local[9]= local[4];
	local[10]= makeint((eusinteger_t)1L);
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[6] = w;
	local[9]= local[4];
	local[10]= makeint((eusinteger_t)2L);
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[7] = w;
	if (local[1]!=NIL) goto IF198;
	local[9]= local[3];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(*ftab[3])(ctx,2,local+9,&ftab[3],fqv[3]); /*make-matrix*/
	local[1] = w;
	local[9]= local[1];
	goto IF199;
IF198:
	local[9]= NIL;
IF199:
	if (local[2]!=NIL) goto IF200;
	local[9]= local[3];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(*ftab[11])(ctx,1,local+10,&ftab[11],fqv[15]); /*array-dimensions*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	w=(*ftab[3])(ctx,2,local+9,&ftab[3],fqv[3]); /*make-matrix*/
	local[2] = w;
	local[9]= local[2];
	goto IF201;
IF200:
	local[9]= NIL;
IF201:
	if (local[0]!=NIL) goto IF202;
	local[9]= local[3];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(*ftab[11])(ctx,1,local+10,&ftab[11],fqv[15]); /*array-dimensions*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	w=(*ftab[3])(ctx,2,local+9,&ftab[3],fqv[3]); /*make-matrix*/
	local[0] = w;
	local[9]= local[0];
	goto IF203;
IF202:
	local[9]= NIL;
IF203:
	local[9]= local[1]->c.obj.iv[1];
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(*ftab[13])(ctx,2,local+9,&ftab[13],fqv[18]); /*fill*/
	local[9]= local[6];
	local[10]= makeint((eusinteger_t)0L);
	local[11]= makeint((eusinteger_t)0L);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,3,local+9); /*aref*/
	local[8] = w;
	local[9]= local[8];
	local[10]= makeflt(9.9999999999999991239646e-05);
	ctx->vsp=local+11;
	w=(pointer)GREATERP(ctx,2,local+9); /*>*/
	if (w==NIL) goto IF204;
	local[9]= makeint((eusinteger_t)0L);
	local[10]= local[3];
WHL207:
	local[11]= local[9];
	w = local[10];
	if ((eusinteger_t)local[11] >= (eusinteger_t)w) goto WHX208;
	local[11]= local[6];
	local[12]= local[9];
	local[13]= local[9];
	ctx->vsp=local+14;
	w=(pointer)AREF(ctx,3,local+11); /*aref*/
	local[11]= w;
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(pointer)QUOTIENT(ctx,2,local+11); /*/*/
	local[11]= w;
	local[12]= makeflt(9.9999999999999991239646e-05);
	ctx->vsp=local+13;
	w=(pointer)GREATERP(ctx,2,local+11); /*>*/
	if (w==NIL) goto IF210;
	local[11]= local[1];
	local[12]= local[9];
	local[13]= local[9];
	local[14]= makeflt(1.0000000000000000000000e+00);
	local[15]= local[6];
	local[16]= local[9];
	local[17]= local[9];
	ctx->vsp=local+18;
	w=(pointer)AREF(ctx,3,local+15); /*aref*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)QUOTIENT(ctx,2,local+14); /*/*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)ASET(ctx,4,local+11); /*aset*/
	local[11]= w;
	goto IF211;
IF210:
	local[11]= NIL;
IF211:
	local[11]= local[9];
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[9] = w;
	goto WHL207;
WHX208:
	local[11]= NIL;
BLK209:
	w = NIL;
	local[9]= w;
	goto IF205;
IF204:
	local[9]= NIL;
IF205:
	local[9]= local[7];
	local[10]= local[1];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)MATTIMES(ctx,3,local+9); /*m**/
	local[9]= w;
	local[10]= local[5];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)TRANSPOSE(ctx,2,local+10); /*transpose*/
	local[10]= w;
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)MATTIMES(ctx,3,local+9); /*m**/
	local[0] = w;
	w = local[0];
	local[0]= w;
BLK191:
	ctx->vsp=local; return(local[0]);}

/*sr-inverse*/
static pointer F82sr_inverse(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT224;}
	local[0]= makeflt(1.0000000000000000000000e+00);
ENT224:
	if (n>=3) { local[1]=(argv[2]); goto ENT223;}
	local[1]= NIL;
ENT223:
	if (n>=4) { local[2]=(argv[3]); goto ENT222;}
	local[2]= NIL;
ENT222:
	if (n>=5) { local[3]=(argv[4]); goto ENT221;}
	local[3]= NIL;
ENT221:
	if (n>=6) { local[4]=(argv[5]); goto ENT220;}
	local[4]= NIL;
ENT220:
	if (n>=7) { local[5]=(argv[6]); goto ENT219;}
	local[5]= NIL;
ENT219:
	if (n>=8) { local[6]=(argv[7]); goto ENT218;}
	local[6]= NIL;
ENT218:
	if (n>=9) { local[7]=(argv[8]); goto ENT217;}
	local[7]= NIL;
ENT217:
	if (n>=10) { local[8]=(argv[9]); goto ENT216;}
	local[8]= NIL;
ENT216:
	if (n>=11) { local[9]=(argv[10]); goto ENT215;}
	local[9]= NIL;
ENT215:
	if (n>=12) { local[10]=(argv[11]); goto ENT214;}
	local[10]= NIL;
ENT214:
ENT213:
	if (n>12) maerror();
	local[11]= argv[0];
	local[12]= makeint((eusinteger_t)0L);
	ctx->vsp=local+13;
	w=(*ftab[0])(ctx,2,local+11,&ftab[0],fqv[0]); /*array-dimension*/
	local[11]= w;
	local[12]= argv[0];
	local[13]= makeint((eusinteger_t)1L);
	ctx->vsp=local+14;
	w=(*ftab[0])(ctx,2,local+12,&ftab[0],fqv[0]); /*array-dimension*/
	local[12]= w;
	if (local[4]!=NIL) goto IF225;
	local[13]= local[12];
	local[14]= local[11];
	ctx->vsp=local+15;
	w=(*ftab[3])(ctx,2,local+13,&ftab[3],fqv[3]); /*make-matrix*/
	local[4] = w;
	local[13]= local[4];
	goto IF226;
IF225:
	local[13]= NIL;
IF226:
	if (local[1]!=NIL) goto IF227;
	if (local[9]!=NIL) goto IF229;
	local[13]= local[11];
	local[14]= local[11];
	ctx->vsp=local+15;
	w=(*ftab[3])(ctx,2,local+13,&ftab[3],fqv[3]); /*make-matrix*/
	local[9] = w;
	local[13]= local[9];
	goto IF230;
IF229:
	local[13]= NIL;
IF230:
	if (local[10]!=NIL) goto IF231;
	local[13]= local[11];
	local[14]= local[11];
	ctx->vsp=local+15;
	w=(*ftab[3])(ctx,2,local+13,&ftab[3],fqv[3]); /*make-matrix*/
	local[10] = w;
	local[13]= local[10];
	goto IF232;
IF231:
	local[13]= NIL;
IF232:
	local[13]= argv[0];
	local[14]= local[0];
	local[15]= local[9];
	local[16]= local[4];
	local[17]= local[10];
	ctx->vsp=local+18;
	w=(pointer)F83sr_inverse_org(ctx,5,local+13); /*sr-inverse-org*/
	ctx->vsp=local+13;
	local[0]=w;
	goto BLK212;
	goto IF228;
IF227:
	local[13]= NIL;
IF228:
	if (local[2]!=NIL) goto IF233;
	local[13]= local[12];
	local[14]= local[11];
	ctx->vsp=local+15;
	w=(*ftab[3])(ctx,2,local+13,&ftab[3],fqv[3]); /*make-matrix*/
	local[2] = w;
	local[13]= local[2];
	goto IF234;
IF233:
	local[13]= NIL;
IF234:
	if (local[3]!=NIL) goto IF235;
	local[13]= local[12];
	local[14]= local[12];
	ctx->vsp=local+15;
	w=(*ftab[3])(ctx,2,local+13,&ftab[3],fqv[3]); /*make-matrix*/
	local[3] = w;
	local[13]= local[3];
	goto IF236;
IF235:
	local[13]= NIL;
IF236:
	if (local[8]!=NIL) goto IF237;
	local[13]= local[11];
	local[14]= local[12];
	ctx->vsp=local+15;
	w=(*ftab[3])(ctx,2,local+13,&ftab[3],fqv[3]); /*make-matrix*/
	local[8] = w;
	local[13]= local[8];
	goto IF238;
IF237:
	local[13]= NIL;
IF238:
	local[13]= local[0];
	local[14]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+15;
	w=(pointer)NUMEQUAL(ctx,2,local+13); /*=*/
	if (w==NIL) goto IF239;
	local[13]= argv[0];
	local[14]= local[1];
	local[15]= local[2];
	local[16]= local[3];
	local[17]= local[8];
	ctx->vsp=local+18;
	w=(pointer)F80pseudo_inverse(ctx,5,local+13); /*pseudo-inverse*/
	ctx->vsp=local+13;
	local[0]=w;
	goto BLK212;
	goto IF240;
IF239:
	local[13]= NIL;
IF240:
	if (local[5]!=NIL) goto IF241;
	local[13]= local[11];
	ctx->vsp=local+14;
	w=(*ftab[1])(ctx,1,local+13,&ftab[1],fqv[1]); /*unit-matrix*/
	local[5] = w;
	local[13]= local[5];
	goto IF242;
IF241:
	local[13]= local[5]->c.obj.iv[1];
	local[14]= makeint((eusinteger_t)0L);
	ctx->vsp=local+15;
	w=(*ftab[13])(ctx,2,local+13,&ftab[13],fqv[18]); /*fill*/
	local[13]= makeint((eusinteger_t)0L);
	local[14]= local[11];
WHL244:
	local[15]= local[13];
	w = local[14];
	if ((eusinteger_t)local[15] >= (eusinteger_t)w) goto WHX245;
	local[15]= local[5];
	local[16]= local[13];
	local[17]= local[13];
	local[18]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+19;
	w=(pointer)ASET(ctx,4,local+15); /*aset*/
	local[15]= local[13];
	ctx->vsp=local+16;
	w=(pointer)ADD1(ctx,1,local+15); /*1+*/
	local[13] = w;
	goto WHL244;
WHX245:
	local[15]= NIL;
BLK246:
	w = NIL;
	local[13]= w;
IF242:
	if (local[6]!=NIL) goto IF247;
	local[13]= local[11];
	local[14]= local[11];
	ctx->vsp=local+15;
	w=(*ftab[3])(ctx,2,local+13,&ftab[3],fqv[3]); /*make-matrix*/
	local[6] = w;
	local[13]= local[6];
	goto IF248;
IF247:
	local[13]= NIL;
IF248:
	if (local[7]!=NIL) goto IF249;
	local[13]= local[12];
	local[14]= local[11];
	ctx->vsp=local+15;
	w=(*ftab[3])(ctx,2,local+13,&ftab[3],fqv[3]); /*make-matrix*/
	local[7] = w;
	local[13]= local[7];
	goto IF250;
IF249:
	local[13]= NIL;
IF250:
	local[13]= makeint((eusinteger_t)0L);
	local[14]= local[12];
WHL252:
	local[15]= local[13];
	w = local[14];
	if ((eusinteger_t)local[15] >= (eusinteger_t)w) goto WHX253;
	local[15]= local[3];
	local[16]= local[13];
	local[17]= local[13];
	local[18]= local[1];
	local[19]= local[13];
	ctx->vsp=local+20;
	w=(pointer)AREF(ctx,2,local+18); /*aref*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)ASET(ctx,4,local+15); /*aset*/
	local[15]= local[13];
	ctx->vsp=local+16;
	w=(pointer)ADD1(ctx,1,local+15); /*1+*/
	local[13] = w;
	goto WHL252;
WHX253:
	local[15]= NIL;
BLK254:
	w = NIL;
	local[13]= local[3];
	local[14]= argv[0];
	local[15]= local[4];
	ctx->vsp=local+16;
	w=(pointer)TRANSPOSE(ctx,2,local+14); /*transpose*/
	local[14]= w;
	local[15]= local[7];
	ctx->vsp=local+16;
	w=(pointer)MATTIMES(ctx,3,local+13); /*m**/
	local[13]= w;
	local[14]= argv[0];
	local[15]= local[7];
	local[16]= local[6];
	ctx->vsp=local+17;
	w=(pointer)MATTIMES(ctx,3,local+14); /*m**/
	local[14]= w;
	local[15]= local[0];
	local[16]= local[5];
	local[17]= local[5];
	ctx->vsp=local+18;
	w=(*ftab[8])(ctx,3,local+15,&ftab[8],fqv[12]); /*scale-matrix*/
	local[15]= w;
	local[16]= local[5];
	ctx->vsp=local+17;
	w=(*ftab[9])(ctx,3,local+14,&ftab[9],fqv[13]); /*m+*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)F70inverse_matrix(ctx,1,local+14); /*inverse-matrix*/
	local[14]= w;
	local[15]= local[2];
	ctx->vsp=local+16;
	w=(pointer)MATTIMES(ctx,3,local+13); /*m**/
	w = local[2];
	local[0]= w;
BLK212:
	ctx->vsp=local; return(local[0]);}

/*sr-inverse-org*/
static pointer F83sr_inverse_org(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT260;}
	local[0]= makeint((eusinteger_t)1L);
ENT260:
	if (n>=3) { local[1]=(argv[2]); goto ENT259;}
	local[1]= NIL;
ENT259:
	if (n>=4) { local[2]=(argv[3]); goto ENT258;}
	local[2]= NIL;
ENT258:
	if (n>=5) { local[3]=(argv[4]); goto ENT257;}
	local[3]= NIL;
ENT257:
ENT256:
	if (n>5) maerror();
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[11])(ctx,1,local+4,&ftab[11],fqv[15]); /*array-dimensions*/
	local[4]= w;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	if (local[1]!=NIL) goto IF261;
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(*ftab[1])(ctx,1,local+7,&ftab[1],fqv[1]); /*unit-matrix*/
	local[1] = w;
	local[7]= local[1];
	goto IF262;
IF261:
	local[7]= local[1]->c.obj.iv[1];
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(*ftab[13])(ctx,2,local+7,&ftab[13],fqv[18]); /*fill*/
	local[7]= makeint((eusinteger_t)0L);
	local[8]= local[5];
WHL264:
	local[9]= local[7];
	w = local[8];
	if ((eusinteger_t)local[9] >= (eusinteger_t)w) goto WHX265;
	local[9]= local[1];
	local[10]= local[7];
	local[11]= local[7];
	local[12]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+13;
	w=(pointer)ASET(ctx,4,local+9); /*aset*/
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	local[7] = w;
	goto WHL264;
WHX265:
	local[9]= NIL;
BLK266:
	w = NIL;
	local[7]= w;
IF262:
	if (local[2]!=NIL) goto IF267;
	local[7]= local[6];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(*ftab[3])(ctx,2,local+7,&ftab[3],fqv[3]); /*make-matrix*/
	local[2] = w;
	local[7]= local[2];
	goto IF268;
IF267:
	local[7]= NIL;
IF268:
	if (local[3]!=NIL) goto IF269;
	local[7]= local[5];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(*ftab[3])(ctx,2,local+7,&ftab[3],fqv[3]); /*make-matrix*/
	local[3] = w;
	local[7]= local[3];
	goto IF270;
IF269:
	local[7]= NIL;
IF270:
	local[7]= argv[0];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)TRANSPOSE(ctx,2,local+7); /*transpose*/
	local[2] = w;
	local[7]= local[2];
	local[8]= argv[0];
	local[9]= local[2];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)MATTIMES(ctx,3,local+8); /*m**/
	local[8]= w;
	local[9]= local[0];
	local[10]= local[1];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(*ftab[8])(ctx,3,local+9,&ftab[8],fqv[12]); /*scale-matrix*/
	local[9]= w;
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(*ftab[9])(ctx,3,local+8,&ftab[9],fqv[13]); /*m+*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)F70inverse_matrix(ctx,1,local+8); /*inverse-matrix*/
	local[8]= w;
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)MATTIMES(ctx,3,local+7); /*m**/
	local[0]= w;
BLK255:
	ctx->vsp=local; return(local[0]);}

/*manipulability*/
static pointer F84manipulability(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT274;}
	local[0]= NIL;
ENT274:
	if (n>=3) { local[1]=(argv[2]); goto ENT273;}
	local[1]= NIL;
ENT273:
ENT272:
	if (n>3) maerror();
	local[2]= argv[0];
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,2,local+2,&ftab[0],fqv[0]); /*array-dimension*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,2,local+3,&ftab[0],fqv[0]); /*array-dimension*/
	local[3]= w;
	if (local[0]!=NIL) goto IF275;
	local[4]= local[2];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(*ftab[3])(ctx,2,local+4,&ftab[3],fqv[3]); /*make-matrix*/
	local[0] = w;
	local[4]= local[0];
	goto IF276;
IF275:
	local[4]= NIL;
IF276:
	if (local[1]!=NIL) goto IF277;
	local[4]= local[3];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(*ftab[3])(ctx,2,local+4,&ftab[3],fqv[3]); /*make-matrix*/
	local[1] = w;
	local[4]= local[1];
	goto IF278;
IF277:
	local[4]= NIL;
IF278:
	local[4]= makeflt(0.0000000000000000000000e+00);
	local[5]= argv[0];
	local[6]= argv[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)TRANSPOSE(ctx,2,local+6); /*transpose*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)MATTIMES(ctx,3,local+5); /*m**/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[14])(ctx,1,local+5,&ftab[14],fqv[19]); /*matrix-determinant*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MAX(ctx,2,local+4); /*max*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SQRT(ctx,1,local+4); /*sqrt*/
	local[0]= w;
BLK271:
	ctx->vsp=local; return(local[0]);}

/*random-gauss*/
static pointer F85random_gauss(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT282;}
	local[0]= makeint((eusinteger_t)0L);
ENT282:
	if (n>=2) { local[1]=(argv[1]); goto ENT281;}
	local[1]= makeint((eusinteger_t)1L);
ENT281:
ENT280:
	if (n>2) maerror();
	local[2]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+3;
	w=(pointer)RANDOM(ctx,1,local+2); /*random*/
	local[2]= w;
	local[3]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+4;
	w=(pointer)RANDOM(ctx,1,local+3); /*random*/
	local[3]= w;
	local[4]= makeflt(-2.0000000000000000000000e+00);
	local[5]= local[1];
	local[6]= local[1];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)LOG(ctx,1,local+7); /*log*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,4,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SQRT(ctx,1,local+4); /*sqrt*/
	local[4]= w;
	local[5]= makeint((eusinteger_t)2L);
	local[6]= makeflt(3.1415926535897931159980e+00);
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,3,local+5); /***/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)COS(ctx,1,local+5); /*cos*/
	{ double x,y;
		y=fltval(w); x=fltval(local[4]);
		local[4]=(makeflt(x * y));}
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[0]= w;
BLK279:
	ctx->vsp=local; return(local[0]);}

/*gaussian-random*/
static pointer F86gaussian_random(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT286;}
	local[0]= makeint((eusinteger_t)0L);
ENT286:
	if (n>=3) { local[1]=(argv[2]); goto ENT285;}
	local[1]= makeint((eusinteger_t)1L);
ENT285:
ENT284:
	if (n>3) maerror();
	local[2]= loadglobal(fqv[4]);
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,2,local+2); /*instantiate*/
	local[2]= w;
	w = local[0];
	if (!isnum(w)) goto IF287;
	local[3]= argv[0];
	local[4]= fqv[20];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[15])(ctx,3,local+3,&ftab[15],fqv[21]); /*make-list*/
	local[0] = w;
	local[3]= local[0];
	goto IF288;
IF287:
	local[3]= NIL;
IF288:
	w = local[1];
	if (!isnum(w)) goto IF289;
	local[3]= argv[0];
	local[4]= fqv[20];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(*ftab[15])(ctx,3,local+3,&ftab[15],fqv[21]); /*make-list*/
	local[1] = w;
	local[3]= local[1];
	goto IF290;
IF289:
	local[3]= NIL;
IF290:
	local[3]= makeint((eusinteger_t)0L);
	local[4]= argv[0];
WHL292:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX293;
	local[5]= local[2];
	local[6]= local[3];
	local[7]= local[0];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	local[8]= local[1];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)F85random_gauss(ctx,2,local+7); /*random-gauss*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)ASET(ctx,3,local+5); /*aset*/
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL292;
WHX293:
	local[5]= NIL;
BLK294:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK283:
	ctx->vsp=local; return(local[0]);}

/*eigen-decompose*/
static pointer F87eigen_decompose(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[16])(ctx,1,local+0,&ftab[16],fqv[22]); /*qr-decompose*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= local[1];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(*ftab[3])(ctx,2,local+2,&ftab[3],fqv[3]); /*make-matrix*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= makeint((eusinteger_t)10L);
	local[12]= NIL;
	local[13]= NIL;
	local[14]= local[0];
	local[15]= (pointer)get_sym_func(fqv[23]);
	ctx->vsp=local+16;
	w=(pointer)SORT(ctx,2,local+14); /*sort*/
	local[0] = w;
	local[14]= makeint((eusinteger_t)0L);
	local[15]= local[1];
WHL297:
	local[16]= local[14];
	w = local[15];
	if ((eusinteger_t)local[16] >= (eusinteger_t)w) goto WHX298;
	local[16]= argv[0];
	local[17]= local[0];
	local[18]= local[14];
	ctx->vsp=local+19;
	w=(pointer)ELT(ctx,2,local+17); /*elt*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)MINUS(ctx,1,local+17); /*-*/
	local[17]= w;
	local[18]= local[1];
	ctx->vsp=local+19;
	w=(*ftab[1])(ctx,1,local+18,&ftab[1],fqv[1]); /*unit-matrix*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(*ftab[8])(ctx,2,local+17,&ftab[8],fqv[12]); /*scale-matrix*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(*ftab[9])(ctx,2,local+16,&ftab[9],fqv[13]); /*m+*/
	local[3] = w;
	local[16]= local[3];
	ctx->vsp=local+17;
	w=(*ftab[17])(ctx,1,local+16,&ftab[17],fqv[24]); /*copy-matrix*/
	local[4] = w;
	local[16]= local[3];
	ctx->vsp=local+17;
	w=(pointer)LU_DECOMPOSE(ctx,1,local+16); /*lu-decompose*/
	local[7] = w;
	if (local[7]==NIL) goto IF300;
	local[16]= loadglobal(fqv[4]);
	local[17]= local[1];
	ctx->vsp=local+18;
	w=(pointer)INSTANTIATE(ctx,2,local+16); /*instantiate*/
	local[5] = w;
WHL302:
	local[16]= local[5];
	ctx->vsp=local+17;
	w=(pointer)VNORM(ctx,1,local+16); /*norm*/
	local[16]= w;
	local[17]= makeint((eusinteger_t)0L);
	ctx->vsp=local+18;
	w=(*ftab[6])(ctx,2,local+16,&ftab[6],fqv[8]); /*eps=*/
	if (w==NIL) goto WHX303;
	local[16]= makeint((eusinteger_t)0L);
	local[17]= local[1];
WHL306:
	local[18]= local[16];
	w = local[17];
	if ((eusinteger_t)local[18] >= (eusinteger_t)w) goto WHX307;
	local[18]= local[5];
	local[19]= local[16];
	local[20]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+21;
	w=(pointer)RANDOM(ctx,1,local+20); /*random*/
	local[20]= w;
	local[21]= makeflt(5.0000000000000000000000e-01);
	ctx->vsp=local+22;
	w=(pointer)MINUS(ctx,2,local+20); /*-*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)SETELT(ctx,3,local+18); /*setelt*/
	local[18]= local[16];
	ctx->vsp=local+19;
	w=(pointer)ADD1(ctx,1,local+18); /*1+*/
	local[16] = w;
	goto WHL306;
WHX307:
	local[18]= NIL;
BLK308:
	w = NIL;
	local[16]= local[5];
	ctx->vsp=local+17;
	w=(pointer)F99normalize_vector(ctx,1,local+16); /*normalize-vector*/
	local[5] = w;
	goto WHL302;
WHX303:
	local[16]= NIL;
BLK304:
	local[6] = local[5];
	local[10] = makeint((eusinteger_t)0L);
TAG311:
	local[16]= local[3];
	local[17]= local[7];
	local[18]= local[5];
	ctx->vsp=local+19;
	w=(pointer)LU_SOLVE(ctx,3,local+16); /*lu-solve*/
	local[5] = w;
	local[16]= local[5];
	ctx->vsp=local+17;
	w=(pointer)F99normalize_vector(ctx,1,local+16); /*normalize-vector*/
	local[5] = w;
	local[16]= local[10];
	ctx->vsp=local+17;
	w=(pointer)ADD1(ctx,1,local+16); /*1+*/
	local[10] = w;
	local[16]= local[10];
	local[17]= local[11];
	ctx->vsp=local+18;
	w=(pointer)GREQP(ctx,2,local+16); /*>=*/
	if (w!=NIL) goto OR314;
	local[16]= local[6];
	local[17]= local[5];
	ctx->vsp=local+18;
	w=(pointer)VDISTANCE(ctx,2,local+16); /*distance*/
	local[16]= w;
	local[17]= makeint((eusinteger_t)0L);
	ctx->vsp=local+18;
	w=(*ftab[6])(ctx,2,local+16,&ftab[6],fqv[8]); /*eps=*/
	if (w!=NIL) goto OR314;
	goto IF312;
OR314:
	w = NIL;
	ctx->vsp=local+16;
	local[16]=w;
	goto BLK310;
	goto IF313;
IF312:
	local[16]= NIL;
IF313:
	local[16]= local[10];
	local[17]= local[11];
	local[18]= makeint((eusinteger_t)2L);
	ctx->vsp=local+19;
	w=(pointer)QUOTIENT(ctx,2,local+17); /*/*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)GREATERP(ctx,2,local+16); /*>*/
	if (w==NIL) goto IF315;
	local[16]= makeflt(1.0000000000000000000000e+00);
	local[17]= local[7];
	local[18]= loadglobal(fqv[4]);
	ctx->vsp=local+19;
	w=(pointer)COERCE(ctx,2,local+17); /*coerce*/
	local[17]= w;
	local[18]= local[3];
	local[19]= local[7];
	local[20]= local[5];
	ctx->vsp=local+21;
	w=(pointer)LU_SOLVE(ctx,3,local+18); /*lu-solve*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)VINNERPRODUCT(ctx,2,local+17); /*v.*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)QUOTIENT(ctx,2,local+16); /*/*/
	local[13] = w;
	local[16]= local[0];
	local[17]= local[14];
	local[18]= local[0];
	local[19]= local[14];
	ctx->vsp=local+20;
	w=(pointer)ELT(ctx,2,local+18); /*elt*/
	local[18]= w;
	local[19]= local[13];
	ctx->vsp=local+20;
	w=(pointer)PLUS(ctx,2,local+18); /*+*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)SETELT(ctx,3,local+16); /*setelt*/
	local[16]= argv[0];
	local[17]= local[0];
	local[18]= local[14];
	ctx->vsp=local+19;
	w=(pointer)ELT(ctx,2,local+17); /*elt*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)MINUS(ctx,1,local+17); /*-*/
	local[17]= w;
	local[18]= local[1];
	ctx->vsp=local+19;
	w=(*ftab[1])(ctx,1,local+18,&ftab[1],fqv[1]); /*unit-matrix*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(*ftab[8])(ctx,2,local+17,&ftab[8],fqv[12]); /*scale-matrix*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(*ftab[9])(ctx,2,local+16,&ftab[9],fqv[13]); /*m+*/
	local[3] = w;
	local[16]= local[3];
	ctx->vsp=local+17;
	w=(pointer)LU_DECOMPOSE(ctx,1,local+16); /*lu-decompose*/
	local[7] = w;
	if (local[7]!=NIL) goto IF317;
	w = NIL;
	ctx->vsp=local+16;
	local[16]=w;
	goto BLK310;
	goto IF318;
IF317:
	local[16]= NIL;
IF318:
	goto IF316;
IF315:
	local[16]= NIL;
IF316:
	local[6] = local[5];
	ctx->vsp=local+16;
	goto TAG311;
	local[16]= NIL;
BLK310:
	local[16]= local[10];
	local[17]= local[11];
	ctx->vsp=local+18;
	w=(pointer)GREQP(ctx,2,local+16); /*>=*/
	if (w==NIL) goto IF319;
	local[7] = NIL;
	local[16]= local[7];
	goto IF320;
IF319:
	local[16]= NIL;
IF320:
	goto IF301;
IF300:
	local[16]= NIL;
IF301:
	if (local[7]!=NIL) goto IF321;
	local[16]= local[4];
	ctx->vsp=local+17;
	w=(*ftab[12])(ctx,1,local+16,&ftab[12],fqv[16]); /*sv-decompose*/
	local[8] = w;
	local[16]= local[8];
	local[17]= makeint((eusinteger_t)1L);
	ctx->vsp=local+18;
	w=(pointer)ELT(ctx,2,local+16); /*elt*/
	local[9] = w;
	local[16]= makeint((eusinteger_t)0L);
	local[17]= local[9];
	ctx->vsp=local+18;
	w=(pointer)LENGTH(ctx,1,local+17); /*length*/
	local[17]= w;
WHL324:
	local[18]= local[16];
	w = local[17];
	if ((eusinteger_t)local[18] >= (eusinteger_t)w) goto WHX325;
	local[18]= local[9];
	local[19]= local[16];
	ctx->vsp=local+20;
	w=(pointer)ELT(ctx,2,local+18); /*elt*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)ABS(ctx,1,local+18); /*abs*/
	local[18]= w;
	local[19]= makeflt(9.9999999999999991239646e-05);
	ctx->vsp=local+20;
	w=(pointer)LESSP(ctx,2,local+18); /*<*/
	if (w==NIL) goto IF327;
	local[18]= local[8];
	local[19]= makeint((eusinteger_t)2L);
	ctx->vsp=local+20;
	w=(pointer)ELT(ctx,2,local+18); /*elt*/
	local[18]= w;
	local[19]= local[16];
	ctx->vsp=local+20;
	w=(*ftab[18])(ctx,2,local+18,&ftab[18],fqv[25]); /*matrix-column*/
	local[5] = w;
	local[18]= local[5];
	goto IF328;
IF327:
	local[18]= NIL;
IF328:
	local[18]= local[16];
	ctx->vsp=local+19;
	w=(pointer)ADD1(ctx,1,local+18); /*1+*/
	local[16] = w;
	goto WHL324;
WHX325:
	local[18]= NIL;
BLK326:
	w = NIL;
	local[16]= w;
	goto IF322;
IF321:
	local[16]= NIL;
IF322:
	local[16]= local[2];
	local[17]= local[14];
	local[18]= local[5];
	ctx->vsp=local+19;
	w=(*ftab[19])(ctx,3,local+16,&ftab[19],fqv[26]); /*set-matrix-column*/
	local[16]= local[14];
	ctx->vsp=local+17;
	w=(pointer)ADD1(ctx,1,local+16); /*1+*/
	local[14] = w;
	goto WHL297;
WHX298:
	local[16]= NIL;
BLK299:
	w = NIL;
	local[14]= local[0];
	local[15]= local[2];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,2,local+14); /*list*/
	local[0]= w;
BLK295:
	ctx->vsp=local; return(local[0]);}

/*lms*/
static pointer F88lms(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[20])(ctx,1,local+0,&ftab[20],fqv[27]); /*vector-mean*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= local[1];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)LENGTH(ctx,1,local+11); /*length*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[3])(ctx,2,local+10,&ftab[3],fqv[3]); /*make-matrix*/
	local[3] = w;
	local[10]= makeint((eusinteger_t)0L);
	local[11]= local[1];
WHL331:
	local[12]= local[10];
	w = local[11];
	if ((eusinteger_t)local[12] >= (eusinteger_t)w) goto WHX332;
	local[12]= local[3];
	local[13]= local[10];
	local[14]= argv[0];
	local[15]= local[10];
	ctx->vsp=local+16;
	w=(pointer)ELT(ctx,2,local+14); /*elt*/
	local[14]= w;
	local[15]= local[0];
	ctx->vsp=local+16;
	w=(pointer)VMINUS(ctx,2,local+14); /*v-*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(*ftab[21])(ctx,3,local+12,&ftab[21],fqv[28]); /*set-matrix-row*/
	local[12]= local[10];
	ctx->vsp=local+13;
	w=(pointer)ADD1(ctx,1,local+12); /*1+*/
	local[10] = w;
	goto WHL331;
WHX332:
	local[12]= NIL;
BLK333:
	w = NIL;
	local[10]= makeflt(1.0000000000000000000000e+00);
	local[11]= local[1];
	local[12]= makeint((eusinteger_t)1L);
	ctx->vsp=local+13;
	w=(pointer)MINUS(ctx,2,local+11); /*-*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[10]= w;
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)TRANSPOSE(ctx,1,local+11); /*transpose*/
	local[11]= w;
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)MATTIMES(ctx,2,local+11); /*m**/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[8])(ctx,2,local+10,&ftab[8],fqv[12]); /*scale-matrix*/
	local[4] = w;
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)F87eigen_decompose(ctx,1,local+10); /*eigen-decompose*/
	local[5] = w;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.car;
	local[10]= local[6];
	local[11]= makeint((eusinteger_t)0L);
	ctx->vsp=local+12;
	w=(pointer)ELT(ctx,2,local+10); /*elt*/
	local[8] = w;
	local[10]= local[7];
	local[11]= makeint((eusinteger_t)0L);
	ctx->vsp=local+12;
	w=(*ftab[18])(ctx,2,local+10,&ftab[18],fqv[25]); /*matrix-column*/
	local[9] = w;
	local[10]= makeint((eusinteger_t)0L);
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)LENGTH(ctx,1,local+11); /*length*/
	local[11]= w;
WHL335:
	local[12]= local[10];
	w = local[11];
	if ((eusinteger_t)local[12] >= (eusinteger_t)w) goto WHX336;
	local[12]= local[8];
	local[13]= local[6];
	local[14]= local[10];
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)GREATERP(ctx,2,local+12); /*>*/
	if (w==NIL) goto IF338;
	local[12]= local[6];
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[8] = w;
	local[12]= local[7];
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(*ftab[18])(ctx,2,local+12,&ftab[18],fqv[25]); /*matrix-column*/
	local[9] = w;
	local[12]= local[9];
	goto IF339;
IF338:
	local[12]= NIL;
IF339:
	local[12]= local[10];
	ctx->vsp=local+13;
	w=(pointer)ADD1(ctx,1,local+12); /*1+*/
	local[10] = w;
	goto WHL335;
WHX336:
	local[12]= NIL;
BLK337:
	w = NIL;
	local[10]= local[9];
	local[11]= local[0];
	local[12]= local[9];
	ctx->vsp=local+13;
	w=(pointer)VINNERPRODUCT(ctx,2,local+11); /*v.*/
	local[11]= makeflt(-(fltval(w)));
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,2,local+10); /*list*/
	local[0]= w;
BLK329:
	ctx->vsp=local; return(local[0]);}

/*lms-estimate*/
static pointer F89lms_estimate(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	local[0]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
BLK340:
	ctx->vsp=local; return(local[0]);}

/*lms-error*/
static pointer F90lms_error(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint((eusinteger_t)0L);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[1];
WHL343:
	if (local[3]==NIL) goto WHX344;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= argv[0];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)F89lms_estimate(ctx,2,local+4); /*lms-estimate*/
	local[1] = w;
	local[4]= local[0];
	local[5]= local[1];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[0] = w;
	goto WHL343;
WHX344:
	local[4]= NIL;
BLK345:
	w = NIL;
	local[2]= local[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[0]= w;
BLK341:
	ctx->vsp=local; return(local[0]);}

/*lmeds*/
static pointer F91lmeds(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[29], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY348;
	local[0] = makeint((eusinteger_t)5L);
KEY348:
	if (n & (1<<1)) goto KEY349;
	local[1] = makeflt(2.9999999999999982236432e-01);
KEY349:
	if (n & (1<<2)) goto KEY350;
	local[2] = NIL;
KEY350:
	if (n & (1<<3)) goto KEY351;
	local[3] = NIL;
KEY351:
	if (n & (1<<4)) goto KEY352;
	local[4] = (pointer)get_sym_func(fqv[30]);
KEY352:
	if (n & (1<<5)) goto KEY353;
	local[5] = (pointer)get_sym_func(fqv[31]);
KEY353:
	if (n & (1<<6)) goto KEY354;
	local[6] = (pointer)get_sym_func(fqv[32]);
KEY354:
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= NIL;
	local[15]= NIL;
	local[16]= argv[0];
	ctx->vsp=local+17;
	w=(pointer)LENGTH(ctx,1,local+16); /*length*/
	local[7] = w;
	local[16]= makeint((eusinteger_t)2L);
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)MAX(ctx,2,local+16); /*max*/
	local[16]= w;
	local[17]= local[7];
	ctx->vsp=local+18;
	w=(pointer)MIN(ctx,2,local+16); /*min*/
	local[0] = w;
	local[10] = NIL;
	local[11] = NIL;
	local[15] = NIL;
	if (local[2]==NIL) goto IF355;
	local[12] = local[2];
	local[16]= local[12];
	goto IF356;
IF355:
	local[16]= makeflt(9.9999999999999950039964e-03);
	ctx->vsp=local+17;
	w=(pointer)LOG(ctx,1,local+16); /*log*/
	local[16]= w;
	local[17]= makeint((eusinteger_t)1L);
	local[18]= makeint((eusinteger_t)1L);
	local[19]= local[1];
	ctx->vsp=local+20;
	w=(pointer)MINUS(ctx,2,local+18); /*-*/
	local[18]= w;
	local[19]= local[0];
	ctx->vsp=local+20;
	w=(*ftab[22])(ctx,2,local+18,&ftab[22],fqv[33]); /*expt*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)MINUS(ctx,2,local+17); /*-*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)LOG(ctx,1,local+17); /*log*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)QUOTIENT(ctx,2,local+16); /*/*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)CEILING(ctx,1,local+16); /*ceiling*/
	local[12] = w;
	local[16]= local[12];
IF356:
	local[16]= makeint((eusinteger_t)0L);
	local[17]= local[12];
WHL358:
	local[18]= local[16];
	w = local[17];
	if ((eusinteger_t)local[18] >= (eusinteger_t)w) goto WHX359;
	local[13] = NIL;
	local[18]= makeint((eusinteger_t)0L);
	local[19]= local[0];
WHL362:
	local[20]= local[18];
	w = local[19];
	if ((eusinteger_t)local[20] >= (eusinteger_t)w) goto WHX363;
	local[20]= local[7];
	ctx->vsp=local+21;
	w=(pointer)RANDOM(ctx,1,local+20); /*random*/
	local[8] = w;
WHL365:
	local[20]= local[8];
	local[21]= local[13];
	ctx->vsp=local+22;
	w=(*ftab[23])(ctx,2,local+20,&ftab[23],fqv[34]); /*find*/
	if (w==NIL) goto WHX366;
	local[20]= local[7];
	ctx->vsp=local+21;
	w=(pointer)RANDOM(ctx,1,local+20); /*random*/
	local[8] = w;
	goto WHL365;
WHX366:
	local[20]= NIL;
BLK367:
	local[20]= local[8];
	w = local[13];
	ctx->vsp=local+21;
	local[13] = cons(ctx,local[20],w);
	local[20]= local[18];
	ctx->vsp=local+21;
	w=(pointer)ADD1(ctx,1,local+20); /*1+*/
	local[18] = w;
	goto WHL362;
WHX363:
	local[20]= NIL;
BLK364:
	w = NIL;
	local[18]= local[13];
	w = local[14];
	ctx->vsp=local+19;
	local[14] = cons(ctx,local[18],w);
	local[18]= local[16];
	ctx->vsp=local+19;
	w=(pointer)ADD1(ctx,1,local+18); /*1+*/
	local[16] = w;
	goto WHL358;
WHX359:
	local[18]= NIL;
BLK360:
	w = NIL;
	local[16]= NIL;
	local[17]= local[14];
WHL369:
	if (local[17]==NIL) goto WHX370;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17] = (w)->c.cons.cdr;
	w = local[18];
	local[16] = w;
	local[15] = NIL;
	local[18]= NIL;
	local[19]= local[16];
WHL374:
	if (local[19]==NIL) goto WHX375;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19] = (w)->c.cons.cdr;
	w = local[20];
	local[18] = w;
	local[20]= argv[0];
	local[21]= local[18];
	ctx->vsp=local+22;
	w=(pointer)ELT(ctx,2,local+20); /*elt*/
	local[20]= w;
	w = local[15];
	ctx->vsp=local+21;
	local[15] = cons(ctx,local[20],w);
	goto WHL374;
WHX375:
	local[20]= NIL;
BLK376:
	w = NIL;
	local[18]= local[4];
	local[19]= local[15];
	ctx->vsp=local+20;
	w=(pointer)FUNCALL(ctx,2,local+18); /*funcall*/
	local[9] = w;
	local[18]= local[9];
	w = local[10];
	ctx->vsp=local+19;
	local[10] = cons(ctx,local[18],w);
	if (local[3]==NIL) goto IF378;
	local[18]= local[5];
	local[19]= local[9];
	local[20]= argv[0];
	local[21]= local[3];
	local[22]= fqv[35];
	local[23]= local[6];
	ctx->vsp=local+24;
	w=(pointer)FUNCALL(ctx,6,local+18); /*funcall*/
	local[18]= w;
	w = local[11];
	ctx->vsp=local+19;
	local[11] = cons(ctx,local[18],w);
	local[18]= local[11];
	goto IF379;
IF378:
	local[18]= local[5];
	local[19]= local[9];
	local[20]= argv[0];
	local[21]= fqv[35];
	local[22]= local[6];
	ctx->vsp=local+23;
	w=(pointer)FUNCALL(ctx,5,local+18); /*funcall*/
	local[18]= w;
	w = local[11];
	ctx->vsp=local+19;
	local[11] = cons(ctx,local[18],w);
	local[18]= local[11];
IF379:
	goto WHL369;
WHX370:
	local[18]= NIL;
BLK371:
	w = NIL;
	local[16]= local[10];
	local[17]= local[11];
	ctx->vsp=local+18;
	local[18]= makeclosure(codevec,quotevec,CLO380,env,argv,local);
	if (local[3]==NIL) goto IF381;
	local[19]= (pointer)get_sym_func(fqv[36]);
	goto IF382;
IF381:
	local[19]= (pointer)get_sym_func(fqv[37]);
IF382:
	ctx->vsp=local+20;
	w=(*ftab[24])(ctx,3,local+17,&ftab[24],fqv[38]); /*find-extream*/
	local[17]= w;
	local[18]= local[11];
	ctx->vsp=local+19;
	w=(*ftab[25])(ctx,2,local+17,&ftab[25],fqv[39]); /*position*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)ELT(ctx,2,local+16); /*elt*/
	local[0]= w;
BLK347:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO380(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*lmeds-error*/
static pointer F92lmeds_error(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[40], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY384;
	local[0] = (pointer)get_sym_func(fqv[32]);
KEY384:
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[1];
WHL386:
	if (local[4]==NIL) goto WHX387;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[0];
	local[6]= argv[0];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)FUNCALL(ctx,3,local+5); /*funcall*/
	local[1] = w;
	local[5]= local[1];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	goto WHL386;
WHX387:
	local[5]= NIL;
BLK388:
	w = NIL;
	local[3]= local[2];
	local[4]= (pointer)get_sym_func(fqv[37]);
	ctx->vsp=local+5;
	w=(pointer)SORT(ctx,2,local+3); /*sort*/
	local[3]= w;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
	local[5]= makeint((eusinteger_t)2L);
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[0]= w;
BLK383:
	ctx->vsp=local; return(local[0]);}

/*lmeds-error-mat*/
static pointer F93lmeds_error_mat(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[41], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY391;
	local[0] = (pointer)get_sym_func(fqv[32]);
KEY391:
	local[1]= argv[1];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[0]); /*array-dimension*/
	local[1]= w;
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= makeint((eusinteger_t)0L);
	local[6]= local[1];
WHL393:
	local[7]= local[5];
	w = local[6];
	if ((eusinteger_t)local[7] >= (eusinteger_t)w) goto WHX394;
	local[7]= argv[1];
	local[8]= local[5];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(*ftab[26])(ctx,3,local+7,&ftab[26],fqv[42]); /*c-matrix-row*/
	local[7]= local[0];
	local[8]= argv[0];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)FUNCALL(ctx,3,local+7); /*funcall*/
	local[3] = w;
	local[7]= local[3];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	w = local[4];
	ctx->vsp=local+8;
	local[4] = cons(ctx,local[7],w);
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[5] = w;
	goto WHL393;
WHX394:
	local[7]= NIL;
BLK395:
	w = NIL;
	local[5]= local[4];
	local[6]= (pointer)get_sym_func(fqv[37]);
	ctx->vsp=local+7;
	w=(pointer)SORT(ctx,2,local+5); /*sort*/
	local[5]= w;
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	local[7]= makeint((eusinteger_t)2L);
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[0]= w;
BLK390:
	ctx->vsp=local; return(local[0]);}

/*concatenate-matrix-column*/
static pointer F94concatenate_matrix_column(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST397:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= NIL;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,2,local+3,&ftab[0],fqv[0]); /*array-dimension*/
	local[3]= w;
	local[4]= NIL;
	local[5]= local[0];
WHL399:
	if (local[5]==NIL) goto WHX400;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[4];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(*ftab[0])(ctx,2,local+6,&ftab[0],fqv[0]); /*array-dimension*/
	local[6]= w;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)NUMEQUAL(ctx,2,local+6); /*=*/
	if (w!=NIL) goto IF403;
	local[6]= fqv[43];
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO405,env,argv,local);
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)MAPCAR(ctx,2,local+7); /*mapcar*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SIGERROR(ctx,2,local+6); /*error*/
	local[6]= w;
	goto IF404;
IF403:
	local[6]= NIL;
IF404:
	if (local[4]==NIL) goto IF406;
	local[6]= local[4];
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(*ftab[18])(ctx,2,local+6,&ftab[18],fqv[25]); /*matrix-column*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	goto IF407;
IF406:
	local[6]= makeint((eusinteger_t)0L);
IF407:
	local[1] = local[6];
	local[6]= makeint((eusinteger_t)0L);
	local[7]= local[1];
WHL409:
	local[8]= local[6];
	w = local[7];
	if ((eusinteger_t)local[8] >= (eusinteger_t)w) goto WHX410;
	local[8]= local[4];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(*ftab[27])(ctx,2,local+8,&ftab[27],fqv[44]); /*matrix-row*/
	local[8]= w;
	w = local[2];
	ctx->vsp=local+9;
	local[2] = cons(ctx,local[8],w);
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[6] = w;
	goto WHL409;
WHX410:
	local[8]= NIL;
BLK411:
	w = NIL;
	goto WHL399;
WHX400:
	local[6]= NIL;
BLK401:
	w = NIL;
	if (local[2]==NIL) goto IF412;
	local[4]= (pointer)get_sym_func(fqv[45]);
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)REVERSE(ctx,1,local+5); /*reverse*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,2,local+4); /*apply*/
	local[4]= w;
	goto IF413;
IF412:
	local[4]= NIL;
IF413:
	w = local[4];
	local[0]= w;
BLK396:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO405(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[0]); /*array-dimension*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*concatenate-matrix-row*/
static pointer F95concatenate_matrix_row(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST415:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= NIL;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,2,local+3,&ftab[0],fqv[0]); /*array-dimension*/
	local[3]= w;
	local[4]= NIL;
	local[5]= local[0];
WHL417:
	if (local[5]==NIL) goto WHX418;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[4];
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(*ftab[0])(ctx,2,local+6,&ftab[0],fqv[0]); /*array-dimension*/
	local[6]= w;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)NUMEQUAL(ctx,2,local+6); /*=*/
	if (w!=NIL) goto IF421;
	local[6]= fqv[46];
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO423,env,argv,local);
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)MAPCAR(ctx,2,local+7); /*mapcar*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SIGERROR(ctx,2,local+6); /*error*/
	local[6]= w;
	goto IF422;
IF421:
	local[6]= NIL;
IF422:
	if (local[4]==NIL) goto IF424;
	local[6]= local[4];
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(*ftab[27])(ctx,2,local+6,&ftab[27],fqv[44]); /*matrix-row*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	goto IF425;
IF424:
	local[6]= makeint((eusinteger_t)0L);
IF425:
	local[1] = local[6];
	local[6]= makeint((eusinteger_t)0L);
	local[7]= local[1];
WHL427:
	local[8]= local[6];
	w = local[7];
	if ((eusinteger_t)local[8] >= (eusinteger_t)w) goto WHX428;
	local[8]= local[4];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(*ftab[18])(ctx,2,local+8,&ftab[18],fqv[25]); /*matrix-column*/
	local[8]= w;
	w = local[2];
	ctx->vsp=local+9;
	local[2] = cons(ctx,local[8],w);
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[6] = w;
	goto WHL427;
WHX428:
	local[8]= NIL;
BLK429:
	w = NIL;
	goto WHL417;
WHX418:
	local[6]= NIL;
BLK419:
	w = NIL;
	if (local[2]==NIL) goto IF430;
	local[4]= (pointer)get_sym_func(fqv[45]);
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)REVERSE(ctx,1,local+5); /*reverse*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,2,local+4); /*apply*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)TRANSPOSE(ctx,1,local+4); /*transpose*/
	local[4]= w;
	goto IF431;
IF430:
	local[4]= NIL;
IF431:
	w = local[4];
	local[0]= w;
BLK414:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO423(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[0]); /*array-dimension*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*concatenate-matrix-diagonal*/
static pointer F96concatenate_matrix_diagonal(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST433:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[0];
WHL435:
	if (local[7]==NIL) goto WHX436;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	if (local[6]==NIL) goto IF439;
	local[8]= local[6];
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(*ftab[27])(ctx,2,local+8,&ftab[27],fqv[44]); /*matrix-row*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
	goto IF440;
IF439:
	local[8]= makeint((eusinteger_t)0L);
IF440:
	w = local[3];
	ctx->vsp=local+9;
	local[3] = cons(ctx,local[8],w);
	goto WHL435;
WHX436:
	local[8]= NIL;
BLK437:
	w = NIL;
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)REVERSE(ctx,1,local+6); /*reverse*/
	local[3] = w;
	local[6]= makeint((eusinteger_t)0L);
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
WHL442:
	local[8]= local[6];
	w = local[7];
	if ((eusinteger_t)local[8] >= (eusinteger_t)w) goto WHX443;
	local[8]= local[6];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)NTH(ctx,2,local+8); /*nth*/
	local[1] = w;
	if (local[1]==NIL) goto IF445;
	local[8]= local[1];
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(*ftab[18])(ctx,2,local+8,&ftab[18],fqv[25]); /*matrix-column*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
	goto IF446;
IF445:
	local[8]= makeint((eusinteger_t)0L);
IF446:
	local[2] = local[8];
	local[8]= makeint((eusinteger_t)0L);
	local[9]= local[2];
WHL448:
	local[10]= local[8];
	w = local[9];
	if ((eusinteger_t)local[10] >= (eusinteger_t)w) goto WHX449;
	local[5] = NIL;
	local[10]= makeint((eusinteger_t)0L);
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)LENGTH(ctx,1,local+11); /*length*/
	local[11]= w;
WHL452:
	local[12]= local[10];
	w = local[11];
	if ((eusinteger_t)local[12] >= (eusinteger_t)w) goto WHX453;
	local[12]= local[6];
	if (local[10]!=local[12]) goto IF455;
	local[12]= local[1];
	local[13]= local[8];
	ctx->vsp=local+14;
	w=(*ftab[27])(ctx,2,local+12,&ftab[27],fqv[44]); /*matrix-row*/
	local[12]= w;
	w = local[5];
	ctx->vsp=local+13;
	local[5] = cons(ctx,local[12],w);
	local[12]= local[5];
	goto IF456;
IF455:
	local[12]= local[10];
	local[13]= local[3];
	ctx->vsp=local+14;
	w=(pointer)NTH(ctx,2,local+12); /*nth*/
	local[12]= w;
	local[13]= fqv[47];
	local[14]= loadglobal(fqv[4]);
	local[15]= fqv[20];
	local[16]= makeint((eusinteger_t)0L);
	ctx->vsp=local+17;
	w=(*ftab[28])(ctx,5,local+12,&ftab[28],fqv[48]); /*make-array*/
	local[12]= w;
	w = local[5];
	ctx->vsp=local+13;
	local[5] = cons(ctx,local[12],w);
	local[12]= local[5];
IF456:
	local[12]= local[10];
	ctx->vsp=local+13;
	w=(pointer)ADD1(ctx,1,local+12); /*1+*/
	local[10] = w;
	goto WHL452;
WHX453:
	local[12]= NIL;
BLK454:
	w = NIL;
	local[10]= (pointer)get_sym_func(fqv[49]);
	local[11]= loadglobal(fqv[4]);
	local[12]= local[5];
	ctx->vsp=local+13;
	w=(pointer)REVERSE(ctx,1,local+12); /*reverse*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	ctx->vsp=local+12;
	w=(pointer)APPLY(ctx,2,local+10); /*apply*/
	local[10]= w;
	w = local[4];
	ctx->vsp=local+11;
	local[4] = cons(ctx,local[10],w);
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[8] = w;
	goto WHL448;
WHX449:
	local[10]= NIL;
BLK450:
	w = NIL;
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[6] = w;
	goto WHL442;
WHX443:
	local[8]= NIL;
BLK444:
	w = NIL;
	if (local[4]==NIL) goto IF457;
	local[6]= (pointer)get_sym_func(fqv[45]);
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)REVERSE(ctx,1,local+7); /*reverse*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,2,local+6); /*apply*/
	local[6]= w;
	goto IF458;
IF457:
	local[6]= NIL;
IF458:
	w = local[6];
	local[0]= w;
BLK432:
	ctx->vsp=local; return(local[0]);}

/*vector-variance*/
static pointer F97vector_variance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= local[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[3])(ctx,3,local+1,&ftab[3],fqv[3]); /*make-matrix*/
	local[1]= w;
	local[2]= loadglobal(fqv[4]);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,2,local+2); /*instantiate*/
	local[2]= w;
	local[3]= makeint((eusinteger_t)0L);
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
WHL461:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX462;
	local[5]= local[2];
	local[6]= local[3];
	local[7]= local[1];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[18])(ctx,2,local+7,&ftab[18],fqv[25]); /*matrix-column*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[29])(ctx,1,local+7,&ftab[29],fqv[50]); /*variance*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SETELT(ctx,3,local+5); /*setelt*/
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL461;
WHX462:
	local[5]= NIL;
BLK463:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK459:
	ctx->vsp=local; return(local[0]);}

/*covariance-matrix*/
static pointer F98covariance_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[1] = w;
	local[2]= local[1];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(*ftab[3])(ctx,2,local+2,&ftab[3],fqv[3]); /*make-matrix*/
	local[0] = w;
	local[2]= makeint((eusinteger_t)0L);
	local[3]= local[1];
WHL466:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX467;
	local[4]= makeint((eusinteger_t)0L);
	local[5]= local[1];
WHL470:
	local[6]= local[4];
	w = local[5];
	if ((eusinteger_t)local[6] >= (eusinteger_t)w) goto WHX471;
	local[6]= local[0];
	local[7]= local[2];
	local[8]= local[4];
	local[9]= argv[0];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	local[10]= argv[0];
	local[11]= local[4];
	ctx->vsp=local+12;
	w=(pointer)ELT(ctx,2,local+10); /*elt*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[30])(ctx,2,local+9,&ftab[30],fqv[51]); /*covariance*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)ASET(ctx,4,local+6); /*aset*/
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[4] = w;
	goto WHL470;
WHX471:
	local[6]= NIL;
BLK472:
	w = NIL;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL466;
WHX467:
	local[4]= NIL;
BLK468:
	w = local[0];
	local[0]= w;
BLK464:
	ctx->vsp=local; return(local[0]);}

/*normalize-vector*/
static pointer F99normalize_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT476;}
	local[0]= NIL;
ENT476:
	if (n>=3) { local[1]=(argv[2]); goto ENT475;}
	local[1]= makeflt(9.9999999999999949376344e-21);
ENT475:
ENT474:
	if (n>3) maerror();
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)VNORM(ctx,1,local+2); /*norm*/
	local[2]= w;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto IF477;
	if (local[0]==NIL) goto IF479;
	local[2]= local[0];
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(*ftab[13])(ctx,2,local+2,&ftab[13],fqv[18]); /*fill*/
	local[2]= w;
	goto IF480;
IF479:
	local[2]= loadglobal(fqv[4]);
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,2,local+2); /*instantiate*/
	local[2]= w;
IF480:
	goto IF478;
IF477:
	if (local[0]==NIL) goto IF481;
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)VNORMALIZE(ctx,2,local+2); /*normalize-vector-org*/
	local[2]= w;
	goto IF482;
IF481:
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)VNORMALIZE(ctx,1,local+2); /*normalize-vector-org*/
	local[2]= w;
IF482:
IF478:
	w = local[2];
	local[0]= w;
BLK473:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___irtmath(ctx,n,argv,env)
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
	ctx->vsp=local+0;
	compfun(ctx,fqv[52],module,F70inverse_matrix,fqv[53]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[54],module,F71diagonal,fqv[55]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[56],module,F72minor_matrix,fqv[57]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[58],module,F73atan2,fqv[59]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[60],module,F74outer_product_matrix,fqv[61]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[62],module,F75matrix2quaternion,fqv[63]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[64],module,F76quaternion2matrix,fqv[65]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[66],module,F77matrix_log,fqv[67]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[68],module,F78matrix_exponent,fqv[69]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[70],module,F79midrot,fqv[71]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[72],module,F80pseudo_inverse,fqv[73]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[74],module,F81pseudo_inverse_org,fqv[75]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[76],module,F82sr_inverse,fqv[77]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[78],module,F83sr_inverse_org,fqv[79]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[80],module,F84manipulability,fqv[81]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[82],module,F85random_gauss,fqv[83]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[84],module,F86gaussian_random,fqv[85]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[86],module,F87eigen_decompose,fqv[87]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[30],module,F88lms,fqv[88]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[32],module,F89lms_estimate,fqv[89]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[90],module,F90lms_error,fqv[91]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[92],module,F91lmeds,fqv[93]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[31],module,F92lmeds_error,fqv[94]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[95],module,F93lmeds_error_mat,fqv[96]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[97],module,F94concatenate_matrix_column,fqv[98]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[99],module,F95concatenate_matrix_row,fqv[100]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[101],module,F96concatenate_matrix_diagonal,fqv[102]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[103],module,F97vector_variance,fqv[104]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[105],module,F98covariance_matrix,fqv[106]);
	local[0]= fqv[107];
	ctx->vsp=local+1;
	w=(pointer)FBOUNDP(ctx,1,local+0); /*fboundp*/
	if (w!=NIL) goto IF483;
	local[0]= fqv[108];
	local[1]= fqv[109];
	ctx->vsp=local+2;
	w=(*ftab[31])(ctx,2,local+0,&ftab[31],fqv[110]); /*remprop*/
	local[0]= fqv[107];
	local[1]= fqv[108];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[107];
	local[1]= fqv[111];
	ctx->vsp=local+2;
	w=(*ftab[32])(ctx,2,local+0,&ftab[32],fqv[112]); /*compiler::def-builtin-entry*/
	local[0]= w;
	goto IF484;
IF483:
	local[0]= NIL;
IF484:
	ctx->vsp=local+0;
	compfun(ctx,fqv[108],module,F99normalize_vector,fqv[113]);
	local[0]= fqv[114];
	local[1]= fqv[115];
	ctx->vsp=local+2;
	w=(*ftab[33])(ctx,2,local+0,&ftab[33],fqv[116]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<34; i++) ftab[i]=fcallx;
}
