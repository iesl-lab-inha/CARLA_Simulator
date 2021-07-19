/* ./irtrobot.c :  entry=irtrobot */
/* compiled by EusLisp 9.27() for Linux created on ip-10-0-1-214(Fri Apr 16 04:05:26 PST 2021) */
#include "eus.h"
#include "irtrobot.h"
#pragma init (register_irtrobot)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___irtrobot();
extern pointer build_quote_vector();
static int register_irtrobot()
  { add_module_initializer("___irtrobot", ___irtrobot);}

static pointer F4068make_default_robot_link();

/*make-default-robot-link*/
static pointer F4068make_default_robot_link(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT4071;}
	local[0]= NIL;
ENT4071:
ENT4070:
	if (n>5) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[1];
	local[7]= makeint((eusinteger_t)2L);
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	local[7]= local[6];
	local[8]= argv[1];
	ctx->vsp=local+9;
	w=(*ftab[0])(ctx,2,local+7,&ftab[0],fqv[0]); /*make-cylinder*/
	local[2] = w;
	local[7]= local[6];
	local[8]= local[6];
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(*ftab[1])(ctx,3,local+7,&ftab[1],fqv[1]); /*make-cube*/
	local[3] = w;
	ctx->vsp=local+7;
	w=(*ftab[2])(ctx,0,local+7,&ftab[2],fqv[2]); /*make-cascoords*/
	local[4] = w;
	local[7]= argv[2];
	local[8]= local[7];
	if (fqv[3]!=local[8]) goto IF4073;
	local[5] = fqv[4];
	local[8]= local[5];
	goto IF4074;
IF4073:
	local[8]= local[7];
	if (fqv[5]!=local[8]) goto IF4075;
	local[5] = fqv[6];
	local[8]= local[5];
	goto IF4076;
IF4075:
	local[8]= local[7];
	if (fqv[7]!=local[8]) goto IF4077;
	local[5] = fqv[8];
	local[8]= local[5];
	goto IF4078;
IF4077:
	local[8]= local[7];
	if (fqv[9]!=local[8]) goto IF4079;
	local[5] = fqv[10];
	local[8]= local[5];
	goto IF4080;
IF4079:
	local[8]= local[7];
	if (fqv[11]!=local[8]) goto IF4081;
	local[5] = fqv[12];
	local[8]= local[5];
	goto IF4082;
IF4081:
	local[8]= local[7];
	if (fqv[13]!=local[8]) goto IF4083;
	local[5] = fqv[14];
	local[8]= local[5];
	goto IF4084;
IF4083:
	if (T==NIL) goto IF4085;
	local[5] = argv[2];
	local[8]= local[5];
	goto IF4086;
IF4085:
	local[8]= NIL;
IF4086:
IF4084:
IF4082:
IF4080:
IF4078:
IF4076:
IF4074:
	w = local[8];
	local[7]= local[5];
	local[8]= fqv[15];
	ctx->vsp=local+9;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+7); /*v**/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)VNORM(ctx,1,local+7); /*norm*/
	local[7]= w;
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)GREATERP(ctx,2,local+7); /*>*/
	if (w==NIL) goto IF4087;
	local[7]= local[4];
	local[8]= fqv[16];
	local[9]= local[5];
	local[10]= fqv[17];
	ctx->vsp=local+11;
	w=(pointer)VINNERPRODUCT(ctx,2,local+9); /*v.*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[3])(ctx,1,local+9,&ftab[3],fqv[18]); /*acos*/
	local[9]= w;
	local[10]= local[5];
	local[11]= fqv[19];
	ctx->vsp=local+12;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+10); /*v**/
	local[10]= w;
	local[11]= fqv[20];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	local[7]= w;
	goto IF4088;
IF4087:
	local[7]= NIL;
IF4088:
	local[7]= local[2];
	local[8]= fqv[21];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= local[2];
	local[8]= fqv[22];
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)0L);
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)MINUS(ctx,1,local+11); /*-*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)MKFLTVEC(ctx,3,local+9); /*float-vector*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= local[3];
	local[8]= fqv[22];
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)0L);
	local[11]= argv[0];
	local[12]= makeint((eusinteger_t)-2L);
	ctx->vsp=local+13;
	w=(pointer)QUOTIENT(ctx,2,local+11); /*/*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)MKFLTVEC(ctx,3,local+9); /*float-vector*/
	local[9]= w;
	local[10]= fqv[23];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[7]= local[2];
	local[8]= fqv[24];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= local[2];
	local[8]= fqv[25];
	local[9]= fqv[26];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= local[3];
	local[8]= fqv[25];
	local[9]= fqv[27];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= local[2];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[1] = w;
	if (local[0]==NIL) goto IF4089;
	local[7]= NIL;
	local[8]= local[0];
WHL4092:
	if (local[8]==NIL) goto WHX4093;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[3];
	local[10]= fqv[24];
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	goto WHL4092;
WHX4093:
	local[9]= NIL;
BLK4094:
	w = NIL;
	local[7]= local[1];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)APPEND(ctx,2,local+7); /*append*/
	local[1] = w;
	local[7]= local[1];
	goto IF4090;
IF4089:
	local[7]= NIL;
IF4090:
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO4096,env,argv,local);
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(*ftab[4])(ctx,2,local+7,&ftab[4],fqv[28]); /*remove-if*/
	local[7]= w;
	local[8]= local[7];
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
	if (makeint((eusinteger_t)1L)!=local[8]) goto IF4097;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= fqv[29];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	goto IF4098;
IF4097:
	local[8]= makeflt(1.0000000000000000000000e+00);
	local[9]= (pointer)get_sym_func(fqv[30]);
	ctx->vsp=local+10;
	local[10]= makeclosure(codevec,quotevec,CLO4099,env,argv,local);
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)MAPCAR(ctx,2,local+10); /*mapcar*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[5])(ctx,2,local+9,&ftab[5],fqv[31]); /*reduce*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	local[9]= (pointer)get_sym_func(fqv[32]);
	ctx->vsp=local+10;
	local[10]= makeclosure(codevec,quotevec,CLO4100,env,argv,local);
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)MAPCAR(ctx,2,local+10); /*mapcar*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[5])(ctx,2,local+9,&ftab[5],fqv[31]); /*reduce*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,2,local+8); /*scale*/
	local[8]= w;
IF4098:
	local[9]= loadglobal(fqv[33]);
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,1,local+9); /*instantiate*/
	local[9]= w;
	local[10]= local[9];
	local[11]= fqv[34];
	ctx->vsp=local+12;
	w=(*ftab[2])(ctx,0,local+12,&ftab[2],fqv[2]); /*make-cascoords*/
	local[12]= w;
	local[13]= fqv[35];
	local[14]= local[1];
	local[15]= fqv[36];
	local[16]= argv[3];
	local[17]= fqv[29];
	local[18]= local[8];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,9,local+10); /*send*/
	w = local[9];
	local[0]= w;
BLK4069:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4096(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[37];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	local[0]= w;
	if (w==NIL) goto AND4102;
	local[0]= argv[0];
	local[1]= fqv[37];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	local[0]= w;
AND4102:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4099(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[37];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4100(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[37];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[29];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SCALEVEC(ctx,2,local+0); /*scale*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:init-ending*/
static pointer M4103robot_model_init_ending(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[38]));
	local[2]= fqv[39];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= w;
	local[1]= (pointer)get_sym_func(fqv[40]);
	local[2]= argv[0];
	local[3]= fqv[41];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[6])(ctx,2,local+1,&ftab[6],fqv[42]); /*every*/
	if (w!=NIL) goto IF4106;
	local[1]= (pointer)get_sym_func(fqv[40]);
	local[2]= argv[0];
	local[3]= fqv[41];
	local[4]= fqv[43];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[6])(ctx,2,local+1,&ftab[6],fqv[42]); /*every*/
	if (w!=NIL) goto IF4106;
	local[1]= argv[0];
	local[2]= fqv[44];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF4107;
IF4106:
	local[1]= NIL;
IF4107:
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[12];
	local[3]= argv[0]->c.obj.iv[13];
	local[4]= argv[0]->c.obj.iv[14];
	local[5]= argv[0]->c.obj.iv[15];
	local[6]= argv[0]->c.obj.iv[16];
	local[7]= argv[0]->c.obj.iv[17];
	local[8]= argv[0]->c.obj.iv[18];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,6,local+3); /*list*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPEND(ctx,2,local+2); /*append*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[7])(ctx,2,local+1,&ftab[7],fqv[45]); /*remove*/
	argv[0]->c.obj.iv[12] = w;
	w = local[0];
	local[0]= w;
BLK4104:
	ctx->vsp=local; return(local[0]);}

/*:rarm-end-coords*/
static pointer M4108robot_model_rarm_end_coords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[14];
	local[0]= w;
BLK4109:
	ctx->vsp=local; return(local[0]);}

/*:larm-end-coords*/
static pointer M4110robot_model_larm_end_coords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[13];
	local[0]= w;
BLK4111:
	ctx->vsp=local; return(local[0]);}

/*:rleg-end-coords*/
static pointer M4112robot_model_rleg_end_coords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[16];
	local[0]= w;
BLK4113:
	ctx->vsp=local; return(local[0]);}

/*:lleg-end-coords*/
static pointer M4114robot_model_lleg_end_coords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[15];
	local[0]= w;
BLK4115:
	ctx->vsp=local; return(local[0]);}

/*:head-end-coords*/
static pointer M4116robot_model_head_end_coords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[17];
	local[0]= w;
BLK4117:
	ctx->vsp=local; return(local[0]);}

/*:torso-end-coords*/
static pointer M4118robot_model_torso_end_coords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[18];
	local[0]= w;
BLK4119:
	ctx->vsp=local; return(local[0]);}

/*:rarm-root-link*/
static pointer M4120robot_model_rarm_root_link(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[20];
	local[0]= w;
BLK4121:
	ctx->vsp=local; return(local[0]);}

/*:larm-root-link*/
static pointer M4122robot_model_larm_root_link(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[19];
	local[0]= w;
BLK4123:
	ctx->vsp=local; return(local[0]);}

/*:rleg-root-link*/
static pointer M4124robot_model_rleg_root_link(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[22];
	local[0]= w;
BLK4125:
	ctx->vsp=local; return(local[0]);}

/*:lleg-root-link*/
static pointer M4126robot_model_lleg_root_link(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[21];
	local[0]= w;
BLK4127:
	ctx->vsp=local; return(local[0]);}

/*:head-root-link*/
static pointer M4128robot_model_head_root_link(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[23];
	local[0]= w;
BLK4129:
	ctx->vsp=local; return(local[0]);}

/*:torso-root-link*/
static pointer M4130robot_model_torso_root_link(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[24];
	local[0]= w;
BLK4131:
	ctx->vsp=local; return(local[0]);}

/*:limb*/
static pointer M4132robot_model_limb(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
RST4134:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-4);
	local[1]= NIL;
	local[2]= argv[3];
	local[3]= local[2];
	if (fqv[43]!=local[3]) goto IF4136;
	local[3]= argv[0];
	local[4]= NIL;
	local[5]= fqv[46];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[8])(ctx,1,local+4,&ftab[8],fqv[47]); /*read-from-string*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[9])(ctx,2,local+3,&ftab[9],fqv[48]); /*forward-message-to*/
	local[3]= w;
	goto IF4137;
IF4136:
	local[3]= local[2];
	if (fqv[49]!=local[3]) goto IF4138;
	local[3]= argv[0];
	local[4]= NIL;
	local[5]= fqv[50];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[8])(ctx,1,local+4,&ftab[8],fqv[47]); /*read-from-string*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[9])(ctx,2,local+3,&ftab[9],fqv[48]); /*forward-message-to*/
	local[3]= w;
	goto IF4139;
IF4138:
	local[3]= local[2];
	if (fqv[51]!=local[3]) goto IF4140;
	if (local[0]==NIL) goto IF4142;
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO4144,env,argv,local);
	local[4]= argv[0];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= loadglobal(fqv[52]);
	ctx->vsp=local+7;
	w=(pointer)COERCE(ctx,2,local+5); /*coerce*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,3,local+3); /*mapcar*/
	local[3]= argv[0];
	local[4]= argv[2];
	local[5]= fqv[51];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF4143;
IF4142:
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO4145,env,argv,local);
	local[4]= argv[0];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	local[4]= loadglobal(fqv[53]);
	ctx->vsp=local+5;
	w=(pointer)COERCE(ctx,2,local+3); /*coerce*/
	local[3]= w;
IF4143:
	goto IF4141;
IF4140:
	local[3]= local[2];
	if (fqv[54]!=local[3]) goto IF4146;
	local[3]= fqv[55];
	w = local[0];
	if (memq(local[3],w)==NIL) goto IF4148;
	local[3]= fqv[55];
	w = local[0];
	w=memq(local[3],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	goto IF4149;
IF4148:
	local[3]= argv[0];
	local[4]= fqv[55];
	local[5]= argv[0];
	local[6]= argv[2];
	local[7]= fqv[43];
	local[8]= fqv[56];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	local[6]= argv[0];
	local[7]= argv[2];
	local[8]= fqv[49];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
IF4149:
	local[4]= fqv[57];
	w = local[0];
	if (memq(local[4],w)==NIL) goto IF4150;
	local[4]= fqv[57];
	w = local[0];
	w=memq(local[4],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	goto IF4151;
IF4150:
	local[4]= argv[0];
	local[5]= fqv[58];
	local[6]= local[3];
	local[7]= fqv[59];
	local[8]= argv[0];
	local[9]= argv[2];
	local[10]= fqv[59];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[4]= w;
IF4151:
	local[5]= (pointer)get_sym_func(fqv[60]);
	local[6]= argv[0];
	local[7]= fqv[54];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= fqv[61];
	local[10]= fqv[61];
	w = local[0];
	if (memq(local[10],w)==NIL) goto IF4152;
	local[10]= fqv[61];
	w = local[0];
	w=memq(local[10],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	goto IF4153;
IF4152:
	local[10]= argv[0];
	local[11]= argv[2];
	local[12]= fqv[43];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
IF4153:
	local[11]= fqv[57];
	local[12]= local[4];
	local[13]= fqv[55];
	local[14]= local[3];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.cdr;
	ctx->vsp=local+16;
	w=(pointer)APPLY(ctx,11,local+5); /*apply*/
	local[3]= w;
	goto IF4147;
IF4146:
	local[3]= local[2];
	if (fqv[62]!=local[3]) goto IF4154;
	local[3]= (pointer)get_sym_func(fqv[60]);
	local[4]= argv[0];
	local[5]= argv[2];
	local[6]= fqv[54];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,5,local+3); /*apply*/
	local[3]= w;
	goto IF4155;
IF4154:
	local[3]= local[2];
	if (fqv[63]!=local[3]) goto IF4156;
	local[3]= argv[0];
	local[4]= argv[2];
	local[5]= fqv[43];
	local[6]= fqv[64];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[4]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[5];
	local[5]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	if (local[6]!=NIL) goto IF4161;
	local[6] = fqv[65];
	local[7]= local[6];
	goto IF4162;
IF4161:
	local[7]= NIL;
IF4162:
	local[7]= (pointer)get_sym_func(fqv[60]);
	local[8]= argv[0];
	local[9]= argv[2];
	local[10]= fqv[62];
	local[11]= local[3];
	local[12]= fqv[66];
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(*ftab[10])(ctx,1,local+13,&ftab[10],fqv[67]); /*deg2rad*/
	local[13]= w;
	local[14]= local[5];
	local[15]= local[6];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,5,local+11); /*send*/
	local[11]= w;
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)APPLY(ctx,6,local+7); /*apply*/
	local[3]= w;
	goto IF4157;
IF4156:
	local[3]= local[2];
	if (fqv[68]!=local[3]) goto IF4163;
	local[3]= argv[0];
	local[4]= argv[2];
	local[5]= fqv[43];
	local[6]= fqv[64];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[4]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[5];
	local[5]= w;
	if (local[5]!=NIL) goto IF4167;
	local[5] = fqv[65];
	local[6]= local[5];
	goto IF4168;
IF4167:
	local[6]= NIL;
IF4168:
	local[6]= (pointer)get_sym_func(fqv[60]);
	local[7]= argv[0];
	local[8]= argv[2];
	local[9]= fqv[62];
	local[10]= local[3];
	local[11]= fqv[22];
	local[12]= local[4];
	local[13]= local[5];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	local[10]= w;
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)APPLY(ctx,6,local+6); /*apply*/
	local[3]= w;
	goto IF4164;
IF4163:
	local[3]= local[2];
	if (fqv[69]!=local[3]) goto IF4169;
	local[3]= argv[0];
	local[4]= fqv[70];
	local[5]= fqv[71];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	if (w==NIL) goto IF4171;
	local[3]= (pointer)get_sym_func(fqv[60]);
	local[4]= argv[0];
	local[5]= fqv[72];
	local[6]= argv[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,5,local+3); /*apply*/
	local[3]= w;
	goto IF4172;
IF4171:
	local[3]= NIL;
IF4172:
	goto IF4170;
IF4169:
	local[3]= local[2];
	if (fqv[59]!=local[3]) goto IF4173;
	local[3]= NIL;
	local[4]= fqv[73];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(*ftab[11])(ctx,1,local+5,&ftab[11],fqv[74]); /*string-upcase*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)INTERN(ctx,1,local+3); /*intern*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[75];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[12])(ctx,2,local+3,&ftab[12],fqv[76]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[9])(ctx,2,local+3,&ftab[9],fqv[48]); /*forward-message-to*/
	local[3]= w;
	goto IF4174;
IF4173:
	local[3]= local[2];
	if (fqv[71]!=local[3]) goto IF4175;
	local[3]= argv[0];
	local[4]= fqv[77];
	local[5]= argv[2];
	local[6]= NIL;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF4176;
IF4175:
	local[3]= local[2];
	if (fqv[78]!=local[3]) goto IF4177;
	local[3]= argv[0];
	local[4]= fqv[77];
	local[5]= argv[2];
	local[6]= fqv[71];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	local[4]= fqv[79];
	ctx->vsp=local+5;
	w=(*ftab[13])(ctx,2,local+3,&ftab[13],fqv[80]); /*send-all*/
	local[3]= w;
	goto IF4178;
IF4177:
	local[3]= local[2];
	if (fqv[81]!=local[3]) goto IF4179;
	local[3]= (pointer)get_sym_func(fqv[60]);
	local[4]= argv[0];
	local[5]= fqv[81];
	local[6]= argv[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,5,local+3); /*apply*/
	local[3]= w;
	goto IF4180;
IF4179:
	local[3]= local[2];
	if (fqv[82]!=local[3]) goto IF4181;
	local[3]= argv[0];
	local[4]= fqv[82];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF4182;
IF4181:
	local[3]= local[2];
	if (fqv[83]!=local[3]) goto IF4183;
	local[3]= argv[0];
	local[4]= fqv[84];
	local[5]= fqv[83];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF4184;
IF4183:
	local[3]= local[2];
	if (fqv[85]!=local[3]) goto IF4185;
	local[3]= argv[0];
	local[4]= fqv[84];
	local[5]= fqv[85];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF4186;
IF4185:
	local[3]= local[2];
	if (fqv[86]!=local[3]) goto IF4187;
	local[3]= argv[0];
	local[4]= fqv[84];
	local[5]= fqv[86];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF4188;
IF4187:
	if (T==NIL) goto IF4189;
	if (argv[3]==NIL) goto OR4193;
	local[3]= loadglobal(fqv[33]);
	local[4]= fqv[87];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	if (w!=NIL) goto OR4193;
	goto CON4192;
OR4193:
	if (argv[3]==NIL) goto IF4194;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(*ftab[11])(ctx,1,local+3,&ftab[11],fqv[74]); /*string-upcase*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)INTERN(ctx,1,local+3); /*intern*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[75];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[12])(ctx,2,local+3,&ftab[12],fqv[76]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(*ftab[13])(ctx,2,local+3,&ftab[13],fqv[80]); /*send-all*/
	local[3]= w;
	goto IF4195;
IF4194:
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(*ftab[11])(ctx,1,local+3,&ftab[11],fqv[74]); /*string-upcase*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)INTERN(ctx,1,local+3); /*intern*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[75];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[12])(ctx,2,local+3,&ftab[12],fqv[76]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
IF4195:
	goto CON4191;
CON4192:
	local[3]= NIL;
	local[4]= fqv[88];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(*ftab[11])(ctx,1,local+5,&ftab[11],fqv[74]); /*string-upcase*/
	local[5]= w;
	local[6]= argv[3];
	ctx->vsp=local+7;
	w=(*ftab[11])(ctx,1,local+6,&ftab[11],fqv[74]); /*string-upcase*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,4,local+3); /*format*/
	local[3]= w;
	local[4]= loadglobal(fqv[89]);
	ctx->vsp=local+5;
	w=(pointer)INTERN(ctx,2,local+3); /*intern*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(*ftab[14])(ctx,2,local+4,&ftab[14],fqv[90]); /*find-method*/
	if (w==NIL) goto IF4197;
	local[4]= argv[0];
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[9])(ctx,2,local+4,&ftab[9],fqv[48]); /*forward-message-to*/
	local[4]= w;
	goto IF4198;
IF4197:
	local[4]= fqv[91];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(*ftab[15])(ctx,2,local+4,&ftab[15],fqv[92]); /*warn*/
	local[4]= w;
IF4198:
	w = local[4];
	local[3]= w;
	goto CON4191;
CON4196:
	local[3]= NIL;
CON4191:
	goto IF4190;
IF4189:
	local[3]= NIL;
IF4190:
IF4188:
IF4186:
IF4184:
IF4182:
IF4180:
IF4178:
IF4176:
IF4174:
IF4170:
IF4164:
IF4157:
IF4155:
IF4147:
IF4141:
IF4139:
IF4137:
	w = local[3];
	local[0]= w;
BLK4133:
	ctx->vsp=local; return(local[0]);}

/*:inverse-kinematics-loop-for-look-at*/
static pointer M4199robot_model_inverse_kinematics_loop_for_look_at(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST4201:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	local[1]= fqv[61];
	w = local[0];
	if (memq(local[1],w)==NIL) goto IF4202;
	local[1]= fqv[61];
	w = local[0];
	w=memq(local[1],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	goto IF4203;
IF4202:
	local[1]= argv[0];
	local[2]= argv[2];
	local[3]= fqv[43];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
IF4203:
	local[2]= fqv[55];
	w = local[0];
	if (memq(local[2],w)==NIL) goto IF4204;
	local[2]= fqv[55];
	w = local[0];
	w=memq(local[2],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	goto IF4205;
IF4204:
	local[2]= argv[0];
	local[3]= fqv[55];
	local[4]= local[1];
	local[5]= fqv[56];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= argv[2];
	local[7]= fqv[49];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
IF4205:
	local[3]= fqv[93];
	w = local[0];
	if (memq(local[3],w)==NIL) goto IF4206;
	local[3]= fqv[93];
	w = local[0];
	w=memq(local[3],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	goto IF4207;
IF4206:
	local[3]= makeint((eusinteger_t)100L);
IF4207:
	local[4]= fqv[94];
	w = local[0];
	if (memq(local[4],w)==NIL) goto IF4208;
	local[4]= fqv[94];
	w = local[0];
	w=memq(local[4],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	goto IF4209;
IF4208:
	local[4]= T;
IF4209:
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= makeint((eusinteger_t)0L);
WHL4210:
	local[9]= local[8];
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	local[8] = w;
	local[9]= local[8];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)LESSP(ctx,2,local+9); /*<*/
	if (w==NIL) goto WHX4211;
	if (local[7]==NIL) goto IF4213;
	local[9]= local[7];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)VMINUS(ctx,2,local+9); /*v-*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)VNORM(ctx,1,local+9); /*norm*/
	local[9]= w;
	local[10]= makeflt(1.0000000000000000208167e-03);
	ctx->vsp=local+11;
	w=(pointer)GREATERP(ctx,2,local+9); /*>*/
	local[9]= w;
	goto IF4214;
IF4213:
	local[9]= T;
IF4214:
	if (local[9]==NIL) goto WHX4211;
	local[9]= fqv[95];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	w=(*ftab[16])(ctx,2,local+9,&ftab[16],fqv[96]); /*make-coords*/
	local[9]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= local[1];
	local[12]= fqv[97];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)VMINUS(ctx,2,local+10); /*v-*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[17])(ctx,2,local+9,&ftab[17],fqv[98]); /*orient-coords-to-axis*/
	local[9]= w;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= NIL;
	local[15]= NIL;
	local[16]= NIL;
	local[7] = local[6];
	local[17]= local[1];
	local[18]= fqv[99];
	local[19]= local[9];
	local[20]= fqv[100];
	local[21]= NIL;
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,5,local+17); /*send*/
	local[5] = w;
	local[17]= local[1];
	local[18]= fqv[101];
	local[19]= local[9];
	local[20]= fqv[102];
	local[21]= fqv[7];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,5,local+17); /*send*/
	local[6] = w;
	local[17]= loadglobal(fqv[53]);
	local[18]= argv[0];
	local[19]= fqv[103];
	local[20]= local[2];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,3,local+18); /*send*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)INSTANTIATE(ctx,2,local+17); /*instantiate*/
	local[14] = w;
	local[17]= loadglobal(fqv[53]);
	local[18]= argv[0];
	local[19]= fqv[103];
	local[20]= local[2];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,3,local+18); /*send*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)INSTANTIATE(ctx,2,local+17); /*instantiate*/
	local[15] = w;
	local[17]= local[14];
	local[18]= makeint((eusinteger_t)1L);
	ctx->vsp=local+19;
	w=(*ftab[18])(ctx,2,local+17,&ftab[18],fqv[104]); /*fill*/
	local[17]= local[9];
	local[18]= fqv[105];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
	local[18]= makeint((eusinteger_t)2L);
	ctx->vsp=local+19;
	w=(*ftab[19])(ctx,2,local+17,&ftab[19],fqv[106]); /*matrix-column*/
	local[10] = w;
	local[17]= local[1];
	local[18]= fqv[105];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
	local[18]= makeint((eusinteger_t)2L);
	ctx->vsp=local+19;
	w=(*ftab[19])(ctx,2,local+17,&ftab[19],fqv[106]); /*matrix-column*/
	local[11] = w;
	local[16] = makeint((eusinteger_t)0L);
	local[17]= NIL;
	local[18]= local[2];
	local[19]= fqv[79];
	ctx->vsp=local+20;
	w=(*ftab[13])(ctx,2,local+18,&ftab[13],fqv[80]); /*send-all*/
	local[18]= w;
WHL4216:
	if (local[18]==NIL) goto WHX4217;
	w=local[18];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	w=local[18];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18] = (w)->c.cons.cdr;
	w = local[19];
	local[17] = w;
	local[19]= local[17];
	local[20]= fqv[107];
	local[21]= fqv[108];
	local[22]= *(ovafptr(local[17],fqv[109]));
	local[23]= local[22];
	if (fqv[3]!=local[23]) goto IF4221;
	local[23]= fqv[110];
	goto IF4222;
IF4221:
	local[23]= local[22];
	if (fqv[5]!=local[23]) goto IF4223;
	local[23]= fqv[111];
	goto IF4224;
IF4223:
	local[23]= local[22];
	if (fqv[7]!=local[23]) goto IF4225;
	local[23]= fqv[112];
	goto IF4226;
IF4225:
	local[23]= local[22];
	if (fqv[9]!=local[23]) goto IF4227;
	local[23]= fqv[113];
	goto IF4228;
IF4227:
	local[23]= local[22];
	if (fqv[11]!=local[23]) goto IF4229;
	local[23]= fqv[114];
	goto IF4230;
IF4229:
	local[23]= local[22];
	if (fqv[13]!=local[23]) goto IF4231;
	local[23]= fqv[115];
	goto IF4232;
IF4231:
	if (T==NIL) goto IF4233;
	local[23]= *(ovafptr(local[17],fqv[109]));
	goto IF4234;
IF4233:
	local[23]= NIL;
IF4234:
IF4232:
IF4230:
IF4228:
IF4226:
IF4224:
IF4222:
	w = local[23];
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,4,local+19); /*send*/
	local[12] = w;
	local[19]= local[17];
	local[20]= fqv[107];
	local[21]= fqv[108];
	local[22]= fqv[116];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,4,local+19); /*send*/
	local[13] = w;
	local[19]= local[12];
	local[20]= local[11];
	local[21]= local[10];
	ctx->vsp=local+22;
	w=(pointer)SCA3PROD(ctx,3,local+19); /*v.**/
	local[19]= w;
	{ double left,right;
		right=fltval(makeflt(0.0000000000000000000000e+00)); left=fltval(local[19]);
	if (left >= right) goto AND4238;}
	local[19]= local[12];
	local[20]= local[11];
	local[21]= local[13];
	ctx->vsp=local+22;
	w=(pointer)SCA3PROD(ctx,3,local+19); /*v.**/
	local[19]= w;
	{ double left,right;
		right=fltval(makeflt(0.0000000000000000000000e+00)); left=fltval(local[19]);
	if (left >= right) goto AND4238;}
	local[19]= local[12];
	local[20]= local[13];
	local[21]= local[10];
	ctx->vsp=local+22;
	w=(pointer)SCA3PROD(ctx,3,local+19); /*v.**/
	local[19]= w;
	{ double left,right;
		right=fltval(makeflt(0.0000000000000000000000e+00)); left=fltval(local[19]);
	if (left >= right) goto AND4238;}
	goto OR4237;
AND4238:
	local[19]= local[12];
	local[20]= local[11];
	local[21]= local[10];
	ctx->vsp=local+22;
	w=(pointer)SCA3PROD(ctx,3,local+19); /*v.**/
	local[19]= w;
	{ double left,right;
		right=fltval(makeflt(0.0000000000000000000000e+00)); left=fltval(local[19]);
	if (left <= right) goto AND4239;}
	local[19]= local[12];
	local[20]= local[11];
	local[21]= local[13];
	ctx->vsp=local+22;
	w=(pointer)SCA3PROD(ctx,3,local+19); /*v.**/
	local[19]= w;
	{ double left,right;
		right=fltval(makeflt(0.0000000000000000000000e+00)); left=fltval(local[19]);
	if (left <= right) goto AND4239;}
	local[19]= local[12];
	local[20]= local[13];
	local[21]= local[10];
	ctx->vsp=local+22;
	w=(pointer)SCA3PROD(ctx,3,local+19); /*v.**/
	local[19]= w;
	{ double left,right;
		right=fltval(makeflt(0.0000000000000000000000e+00)); left=fltval(local[19]);
	if (left <= right) goto AND4239;}
	goto OR4237;
AND4239:
	goto IF4235;
OR4237:
	local[19]= local[12];
	local[20]= local[11];
	local[21]= local[10];
	ctx->vsp=local+22;
	w=(pointer)SCA3PROD(ctx,3,local+19); /*v.**/
	local[19]= w;
	local[20]= makeint((eusinteger_t)0L);
	ctx->vsp=local+21;
	w=(pointer)GREATERP(ctx,2,local+19); /*>*/
	if (w==NIL) goto IF4240;
	local[19]= local[15];
	local[20]= local[16];
	local[21]= makeint((eusinteger_t)-1L);
	ctx->vsp=local+22;
	w=(pointer)SETELT(ctx,3,local+19); /*setelt*/
	local[19]= w;
	goto IF4241;
IF4240:
	local[19]= local[15];
	local[20]= local[16];
	local[21]= makeint((eusinteger_t)1L);
	ctx->vsp=local+22;
	w=(pointer)SETELT(ctx,3,local+19); /*setelt*/
	local[19]= w;
IF4241:
	local[19]= local[14];
	local[20]= makeflt(9.9999999999999950039964e-03);
	ctx->vsp=local+21;
	w=(*ftab[18])(ctx,2,local+19,&ftab[18],fqv[104]); /*fill*/
	local[19]= local[14];
	local[20]= local[16];
	local[21]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+22;
	w=(pointer)SETELT(ctx,3,local+19); /*setelt*/
	w = NIL;
	ctx->vsp=local+19;
	local[19]=w;
	goto BLK4218;
	goto IF4236;
IF4235:
	local[19]= NIL;
IF4236:
	local[19]= local[16];
	ctx->vsp=local+20;
	w=(pointer)ADD1(ctx,1,local+19); /*1+*/
	local[16] = w;
	goto WHL4216;
WHX4217:
	local[19]= NIL;
BLK4218:
	w = NIL;
	local[17]= argv[0];
	local[18]= fqv[117];
	local[19]= local[5];
	local[20]= local[6];
	local[21]= fqv[61];
	local[22]= local[1];
	local[23]= fqv[57];
	local[24]= NIL;
	local[25]= fqv[102];
	local[26]= fqv[7];
	local[27]= fqv[100];
	local[28]= NIL;
	local[29]= fqv[55];
	local[30]= local[2];
	local[31]= fqv[118];
	local[32]= local[8];
	local[33]= fqv[93];
	local[34]= local[3];
	local[35]= fqv[119];
	local[36]= local[9];
	local[37]= fqv[120];
	local[38]= local[15];
	local[39]= fqv[121];
	local[40]= local[14];
	local[41]= fqv[122];
	local[42]= fqv[122];
	w = local[0];
	w=memq(local[42],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[42]= (w)->c.cons.car;
	ctx->vsp=local+43;
	w=(pointer)SEND(ctx,26,local+17); /*send*/
	goto WHL4210;
WHX4211:
	local[9]= NIL;
BLK4212:
	if (local[7]==NIL) goto IF4242;
	local[9]= local[7];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)VMINUS(ctx,2,local+9); /*v-*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)VNORM(ctx,1,local+9); /*norm*/
	local[9]= w;
	{ double left,right;
		right=fltval(makeflt(1.0000000000000000208167e-03)); left=fltval(local[9]);
	if (left > right) goto IF4242;}
	local[9]= argv[0];
	local[10]= fqv[51];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	goto IF4243;
IF4242:
	if (local[4]==NIL) goto IF4244;
	local[9]= fqv[123];
	ctx->vsp=local+10;
	w=(*ftab[15])(ctx,1,local+9,&ftab[15],fqv[92]); /*warn*/
	local[9]= fqv[124];
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(*ftab[15])(ctx,2,local+9,&ftab[15],fqv[92]); /*warn*/
	if (local[7]==NIL) goto IF4246;
	local[9]= fqv[125];
	local[10]= local[7];
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)VNORM(ctx,1,local+11); /*norm*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[15])(ctx,3,local+9,&ftab[15],fqv[92]); /*warn*/
	local[9]= fqv[126];
	local[10]= local[6];
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)VNORM(ctx,1,local+11); /*norm*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[15])(ctx,3,local+9,&ftab[15],fqv[92]); /*warn*/
	local[9]= fqv[127];
	local[10]= local[7];
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)VMINUS(ctx,2,local+10); /*v-*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)VNORM(ctx,1,local+10); /*norm*/
	local[10]= w;
	local[11]= makeflt(1.0000000000000000208167e-03);
	ctx->vsp=local+12;
	w=(*ftab[15])(ctx,3,local+9,&ftab[15],fqv[92]); /*warn*/
	local[9]= w;
	goto IF4247;
IF4246:
	local[9]= NIL;
IF4247:
	goto IF4245;
IF4244:
	local[9]= NIL;
IF4245:
IF4243:
	w = local[9];
	local[0]= w;
BLK4200:
	ctx->vsp=local; return(local[0]);}

/*:gripper*/
static pointer M4248robot_model_gripper(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST4250:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	local[1]= fqv[71];
	w = local[0];
	if (memq(local[1],w)==NIL) goto CON4252;
	local[1]= argv[0];
	local[2]= argv[2];
	local[3]= fqv[43];
	local[4]= fqv[56];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[20])(ctx,1,local+1,&ftab[20],fqv[128]); /*all-child-links*/
	local[1]= w;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO4253,env,argv,local);
	ctx->vsp=local+3;
	w=(pointer)SORT(ctx,2,local+1); /*sort*/
	local[1]= w;
	goto CON4251;
CON4252:
	local[1]= fqv[78];
	w = local[0];
	if (memq(local[1],w)==NIL) goto CON4254;
	local[1]= argv[0];
	local[2]= fqv[81];
	local[3]= argv[2];
	local[4]= fqv[71];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[79];
	ctx->vsp=local+3;
	w=(*ftab[13])(ctx,2,local+1,&ftab[13],fqv[80]); /*send-all*/
	local[1]= w;
	goto CON4251;
CON4254:
	local[1]= fqv[51];
	w = local[0];
	if (memq(local[1],w)==NIL) goto CON4255;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr!=NIL) goto IF4256;
	local[1]= loadglobal(fqv[53]);
	local[2]= argv[0];
	local[3]= fqv[81];
	local[4]= argv[2];
	local[5]= fqv[78];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	local[3]= fqv[129];
	ctx->vsp=local+4;
	w=(*ftab[13])(ctx,2,local+2,&ftab[13],fqv[80]); /*send-all*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)CONCATENATE(ctx,2,local+1); /*concatenate*/
	local[1]= w;
	goto IF4257;
IF4256:
	local[1]= loadglobal(fqv[53]);
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO4258,env,argv,local);
	local[3]= argv[0];
	local[4]= fqv[81];
	local[5]= argv[2];
	local[6]= fqv[78];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)MAP(ctx,4,local+1); /*map*/
	local[1]= w;
IF4257:
	goto CON4251;
CON4255:
	local[1]= NIL;
CON4251:
	w = local[1];
	local[0]= w;
BLK4249:
	ctx->vsp=local; return(local[0]);}

/*:camera*/
static pointer M4259robot_model_camera(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[130];
	local[2]= fqv[131];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK4260:
	ctx->vsp=local; return(local[0]);}

/*:force-sensor*/
static pointer M4261robot_model_force_sensor(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[130];
	local[2]= fqv[132];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK4262:
	ctx->vsp=local; return(local[0]);}

/*:imu-sensor*/
static pointer M4263robot_model_imu_sensor(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[130];
	local[2]= fqv[133];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK4264:
	ctx->vsp=local; return(local[0]);}

/*:get-sensor-method*/
static pointer M4265robot_model_get_sensor_method(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= NIL;
	local[2]= fqv[134];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[8])(ctx,1,local+1,&ftab[8],fqv[47]); /*read-from-string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[3];
	local[2]= local[0];
	local[3]= fqv[135];
	local[4]= (pointer)get_sym_func(fqv[136]);
	local[5]= fqv[137];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO4267,env,argv,local);
	ctx->vsp=local+7;
	w=(*ftab[21])(ctx,6,local+1,&ftab[21],fqv[138]); /*find*/
	local[0]= w;
BLK4266:
	ctx->vsp=local; return(local[0]);}

/*:get-sensors-method-by-limb*/
static pointer M4268robot_model_get_sensors_method_by_limb(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO4270,env,argv,local);
	local[1]= argv[0];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[22])(ctx,2,local+0,&ftab[22],fqv[139]); /*remove-if-not*/
	local[0]= w;
BLK4269:
	ctx->vsp=local; return(local[0]);}

/*:force-sensors*/
static pointer M4271robot_model_force_sensors(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[33];
	local[0]= w;
BLK4272:
	ctx->vsp=local; return(local[0]);}

/*:imu-sensors*/
static pointer M4273robot_model_imu_sensors(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[34];
	local[0]= w;
BLK4274:
	ctx->vsp=local; return(local[0]);}

/*:cameras*/
static pointer M4275robot_model_cameras(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[35];
	local[0]= w;
BLK4276:
	ctx->vsp=local; return(local[0]);}

/*:larm*/
static pointer M4277robot_model_larm(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST4279:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	if (local[0]!=NIL) goto IF4280;
	local[1]= NIL;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
	goto IF4281;
IF4280:
	local[1]= NIL;
IF4281:
	local[1]= (pointer)get_sym_func(fqv[60]);
	local[2]= argv[0];
	local[3]= fqv[77];
	local[4]= fqv[140];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	local[0]= w;
BLK4278:
	ctx->vsp=local; return(local[0]);}

/*:rarm*/
static pointer M4282robot_model_rarm(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST4284:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	if (local[0]!=NIL) goto IF4285;
	local[1]= NIL;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
	goto IF4286;
IF4285:
	local[1]= NIL;
IF4286:
	local[1]= (pointer)get_sym_func(fqv[60]);
	local[2]= argv[0];
	local[3]= fqv[77];
	local[4]= fqv[141];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	local[0]= w;
BLK4283:
	ctx->vsp=local; return(local[0]);}

/*:lleg*/
static pointer M4287robot_model_lleg(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST4289:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	if (local[0]!=NIL) goto IF4290;
	local[1]= NIL;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
	goto IF4291;
IF4290:
	local[1]= NIL;
IF4291:
	local[1]= (pointer)get_sym_func(fqv[60]);
	local[2]= argv[0];
	local[3]= fqv[77];
	local[4]= fqv[142];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	local[0]= w;
BLK4288:
	ctx->vsp=local; return(local[0]);}

/*:rleg*/
static pointer M4292robot_model_rleg(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST4294:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	if (local[0]!=NIL) goto IF4295;
	local[1]= NIL;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
	goto IF4296;
IF4295:
	local[1]= NIL;
IF4296:
	local[1]= (pointer)get_sym_func(fqv[60]);
	local[2]= argv[0];
	local[3]= fqv[77];
	local[4]= fqv[143];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	local[0]= w;
BLK4293:
	ctx->vsp=local; return(local[0]);}

/*:head*/
static pointer M4297robot_model_head(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST4299:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	if (local[0]!=NIL) goto IF4300;
	local[1]= NIL;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
	goto IF4301;
IF4300:
	local[1]= NIL;
IF4301:
	local[1]= (pointer)get_sym_func(fqv[60]);
	local[2]= argv[0];
	local[3]= fqv[77];
	local[4]= fqv[70];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	local[0]= w;
BLK4298:
	ctx->vsp=local; return(local[0]);}

/*:torso*/
static pointer M4302robot_model_torso(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST4304:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	if (local[0]!=NIL) goto IF4305;
	local[1]= NIL;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
	goto IF4306;
IF4305:
	local[1]= NIL;
IF4306:
	local[1]= (pointer)get_sym_func(fqv[60]);
	local[2]= argv[0];
	local[3]= fqv[77];
	local[4]= fqv[144];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	local[0]= w;
BLK4303:
	ctx->vsp=local; return(local[0]);}

/*:arms*/
static pointer M4307robot_model_arms(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST4309:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[60]);
	local[2]= argv[0];
	local[3]= fqv[140];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[1]= w;
	local[2]= (pointer)get_sym_func(fqv[60]);
	local[3]= argv[0];
	local[4]= fqv[141];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,4,local+2); /*apply*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[0]= w;
BLK4308:
	ctx->vsp=local; return(local[0]);}

/*:legs*/
static pointer M4310robot_model_legs(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST4312:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[60]);
	local[2]= argv[0];
	local[3]= fqv[142];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[1]= w;
	local[2]= (pointer)get_sym_func(fqv[60]);
	local[3]= argv[0];
	local[4]= fqv[143];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,4,local+2); /*apply*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[0]= w;
BLK4311:
	ctx->vsp=local; return(local[0]);}

/*:look-at-hand*/
static pointer M4313robot_model_look_at_hand(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[145];
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO4315,env,argv,local);
	w = argv[2];
	if (!iscons(w)) goto CON4317;
	local[3]= argv[2];
	goto CON4316;
CON4317:
	local[3]= argv[2];
	if (fqv[146]!=local[3]) goto CON4318;
	local[3]= fqv[147];
	goto CON4316;
CON4318:
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[3]= w;
	goto CON4316;
CON4319:
	local[3]= NIL;
CON4316:
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK4314:
	ctx->vsp=local; return(local[0]);}

/*:inverse-kinematics*/
static pointer M4320robot_model_inverse_kinematics(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST4322:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[148], &argv[3], n-3, local+1, 1);
	if (n & (1<<0)) goto KEY4323;
	local[1] = NIL;
KEY4323:
	if (n & (1<<1)) goto KEY4324;
	local[2] = NIL;
KEY4324:
	if (n & (1<<2)) goto KEY4325;
	w = local[2];
	if (!!iscons(w)) goto IF4326;
	local[4]= argv[0];
	local[5]= fqv[55];
	local[6]= local[2];
	local[7]= fqv[56];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF4327;
IF4326:
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO4328,env,argv,local);
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[4]= w;
IF4327:
	local[3] = local[4];
KEY4325:
	w = argv[2];
	if (!iscons(w)) goto OR4331;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(*ftab[23])(ctx,1,local+4,&ftab[23],fqv[149]); /*functionp*/
	if (w!=NIL) goto OR4331;
	goto IF4329;
OR4331:
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	argv[2] = w;
	local[4]= argv[2];
	goto IF4330;
IF4329:
	local[4]= NIL;
IF4330:
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO4334,env,argv,local);
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(*ftab[6])(ctx,2,local+4,&ftab[6],fqv[42]); /*every*/
	if (w!=NIL) goto IF4332;
	local[4]= fqv[150];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(*ftab[15])(ctx,2,local+4,&ftab[15],fqv[92]); /*warn*/
	w = NIL;
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK4321;
	goto IF4333;
IF4332:
	local[4]= NIL;
IF4333:
	local[4]= (pointer)get_sym_func(fqv[151]);
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[38]));
	local[7]= fqv[54];
	local[8]= argv[2];
	local[9]= fqv[61];
	local[10]= local[2];
	local[11]= fqv[55];
	local[12]= local[3];
	local[13]= local[0];
	ctx->vsp=local+14;
	w=(pointer)APPLY(ctx,10,local+4); /*apply*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[145];
	local[7]= local[1];
	local[8]= fqv[119];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	w = local[4];
	local[0]= w;
BLK4321:
	ctx->vsp=local; return(local[0]);}

/*:inverse-kinematics-loop*/
static pointer M4336robot_model_inverse_kinematics_loop(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
RST4338:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-4);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[152], &argv[4], n-4, local+1, 1);
	if (n & (1<<0)) goto KEY4339;
	local[1] = NIL;
KEY4339:
	if (n & (1<<1)) goto KEY4340;
	local[2] = NIL;
KEY4340:
	if (n & (1<<2)) goto KEY4341;
	local[3] = NIL;
KEY4341:
	if (n & (1<<3)) goto KEY4342;
	local[4] = NIL;
KEY4342:
	if (n & (1<<4)) goto KEY4343;
	w = local[4];
	if (!!iscons(w)) goto IF4344;
	local[6]= argv[0];
	local[7]= fqv[55];
	local[8]= local[4];
	local[9]= fqv[56];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	goto IF4345;
IF4344:
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO4346,env,argv,local);
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[6]= w;
IF4345:
	local[5] = local[6];
KEY4343:
	w = local[1];
	if (!iscons(w)) goto OR4349;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[23])(ctx,1,local+6,&ftab[23],fqv[149]); /*functionp*/
	if (w!=NIL) goto OR4349;
	goto IF4347;
OR4349:
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	local[1] = w;
	local[6]= local[1];
	goto IF4348;
IF4347:
	local[6]= NIL;
IF4348:
	local[6]= (pointer)get_sym_func(fqv[151]);
	local[7]= argv[0];
	local[8]= *(ovafptr(argv[1],fqv[38]));
	local[9]= fqv[117];
	local[10]= argv[2];
	local[11]= argv[3];
	local[12]= fqv[55];
	local[13]= local[5];
	local[14]= fqv[61];
	local[15]= local[4];
	local[16]= fqv[119];
	local[17]= local[1];
	local[18]= local[0];
	ctx->vsp=local+19;
	w=(pointer)APPLY(ctx,13,local+6); /*apply*/
	local[6]= w;
	if (local[2]==NIL) goto IF4351;
	local[7]= argv[0];
	local[8]= fqv[145];
	local[9]= local[3];
	local[10]= fqv[119];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	local[7]= w;
	goto IF4352;
IF4351:
	local[7]= NIL;
IF4352:
	w = local[6];
	local[0]= w;
BLK4337:
	ctx->vsp=local; return(local[0]);}

/*:look-at-target*/
static pointer M4353robot_model_look_at_target(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[153], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY4355;
	local[0] = NIL;
KEY4355:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[24])(ctx,1,local+1,&ftab[24],fqv[154]); /*float-vector-p*/
	if (w==NIL) goto CON4357;
	local[1]= argv[0];
	local[2]= fqv[70];
	local[3]= fqv[69];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON4356;
CON4357:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[25])(ctx,1,local+1,&ftab[25],fqv[155]); /*coordinates-p*/
	if (w==NIL) goto CON4358;
	local[1]= argv[0];
	local[2]= fqv[70];
	local[3]= fqv[69];
	local[4]= argv[2];
	local[5]= fqv[97];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON4356;
CON4358:
	w = argv[2];
	if (!iscons(w)) goto CON4359;
	local[1]= (pointer)get_sym_func(fqv[156]);
	local[2]= (pointer)get_sym_func(fqv[154]);
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[6])(ctx,2,local+1,&ftab[6],fqv[42]); /*every*/
	if (w==NIL) goto CON4359;
	local[1]= argv[0];
	local[2]= fqv[70];
	local[3]= fqv[69];
	local[4]= makeflt(1.0000000000000000000000e+00);
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	local[5]= (pointer)get_sym_func(fqv[32]);
	local[6]= argv[2];
	local[7]= fqv[157];
	local[8]= fqv[158];
	ctx->vsp=local+9;
	w=(*ftab[5])(ctx,4,local+5,&ftab[5],fqv[31]); /*reduce*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SCALEVEC(ctx,2,local+4); /*scale*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON4356;
CON4359:
	w = argv[2];
	if (!iscons(w)) goto CON4360;
	local[1]= (pointer)get_sym_func(fqv[156]);
	local[2]= (pointer)get_sym_func(fqv[155]);
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[6])(ctx,2,local+1,&ftab[6],fqv[42]); /*every*/
	if (w==NIL) goto CON4360;
	local[1]= argv[0];
	local[2]= fqv[70];
	local[3]= fqv[69];
	local[4]= makeflt(1.0000000000000000000000e+00);
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	local[5]= (pointer)get_sym_func(fqv[32]);
	local[6]= argv[2];
	local[7]= fqv[97];
	ctx->vsp=local+8;
	w=(*ftab[13])(ctx,2,local+6,&ftab[13],fqv[80]); /*send-all*/
	local[6]= w;
	local[7]= fqv[157];
	local[8]= fqv[159];
	ctx->vsp=local+9;
	w=(*ftab[5])(ctx,4,local+5,&ftab[5],fqv[31]); /*reduce*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SCALEVEC(ctx,2,local+4); /*scale*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON4356;
CON4360:
	local[1]= ((argv[2])==NIL?T:NIL);
	if (local[1]!=NIL) goto CON4356;
CON4361:
	local[1]= argv[0];
	local[2]= fqv[70];
	local[3]= fqv[69];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= fqv[97];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON4356;
CON4362:
	local[1]= NIL;
CON4356:
	w = local[1];
	local[0]= w;
BLK4354:
	ctx->vsp=local; return(local[0]);}

/*:init-pose*/
static pointer M4363robot_model_init_pose(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[51];
	local[2]= loadglobal(fqv[53]);
	local[3]= argv[0];
	local[4]= fqv[103];
	local[5]= argv[0];
	local[6]= fqv[71];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,2,local+2); /*instantiate*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK4364:
	ctx->vsp=local; return(local[0]);}

/*:torque-vector*/
static pointer M4365robot_model_torque_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[160], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY4367;
	local[0] = NIL;
KEY4367:
	if (n & (1<<1)) goto KEY4368;
	local[1] = NIL;
KEY4368:
	if (n & (1<<2)) goto KEY4369;
	local[2] = NIL;
KEY4369:
	if (n & (1<<3)) goto KEY4370;
	local[3] = NIL;
KEY4370:
	if (n & (1<<4)) goto KEY4371;
	local[4] = T;
KEY4371:
	if (n & (1<<5)) goto KEY4372;
	local[5] = makeflt(4.9999999999999975019982e-03);
KEY4372:
	if (n & (1<<6)) goto KEY4373;
	local[10]= argv[0];
	local[11]= fqv[51];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[6] = w;
KEY4373:
	if (n & (1<<7)) goto KEY4374;
	local[10]= argv[0];
	local[11]= fqv[71];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= fqv[64];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[7] = w;
KEY4374:
	if (n & (1<<8)) goto KEY4375;
	local[10]= argv[0];
	local[11]= fqv[161];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[8] = w;
KEY4375:
	if (n & (1<<9)) goto KEY4376;
	local[10]= (pointer)get_sym_func(fqv[40]);
	local[11]= argv[0];
	local[12]= fqv[41];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[6])(ctx,2,local+10,&ftab[6],fqv[42]); /*every*/
	if (w!=NIL) goto IF4377;
	if (local[0]==NIL) goto AND4379;
	if (local[1]==NIL) goto AND4379;
	if (local[2]==NIL) goto AND4379;
	goto IF4377;
AND4379:
	local[10]= fqv[162];
	goto IF4378;
IF4377:
	local[10]= NIL;
IF4378:
	local[9] = local[10];
KEY4376:
	local[10]= argv[0];
	local[11]= fqv[163];
	local[12]= fqv[122];
	local[13]= local[3];
	local[14]= fqv[164];
	local[15]= local[4];
	local[16]= fqv[165];
	local[17]= local[6];
	local[18]= fqv[166];
	local[19]= local[7];
	local[20]= fqv[167];
	local[21]= local[5];
	local[22]= fqv[168];
	local[23]= local[0];
	local[24]= fqv[169];
	local[25]= local[1];
	local[26]= fqv[119];
	local[27]= local[2];
	local[28]= fqv[161];
	local[29]= local[8];
	ctx->vsp=local+30;
	w=(pointer)SEND(ctx,20,local+10); /*send*/
	local[10]= w;
	local[11]= argv[0];
	local[12]= local[9];
	ctx->vsp=local+13;
	w=(*ftab[14])(ctx,2,local+11,&ftab[14],fqv[90]); /*find-method*/
	if (w==NIL) goto IF4380;
	local[11]= argv[0];
	local[12]= local[9];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	local[12]= makeint((eusinteger_t)0L);
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(pointer)LENGTH(ctx,1,local+13); /*length*/
	local[13]= w;
WHL4383:
	local[14]= local[12];
	w = local[13];
	if ((eusinteger_t)local[14] >= (eusinteger_t)w) goto WHX4384;
	local[14]= local[10];
	local[15]= local[12];
	local[16]= local[10];
	local[17]= local[12];
	ctx->vsp=local+18;
	w=(pointer)ELT(ctx,2,local+16); /*elt*/
	local[16]= w;
	local[17]= local[11];
	local[18]= local[12];
	ctx->vsp=local+19;
	w=(pointer)ELT(ctx,2,local+17); /*elt*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)MINUS(ctx,2,local+16); /*-*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)SETELT(ctx,3,local+14); /*setelt*/
	local[14]= argv[0]->c.obj.iv[9];
	local[15]= local[12];
	ctx->vsp=local+16;
	w=(pointer)ELT(ctx,2,local+14); /*elt*/
	local[14]= w;
	local[15]= fqv[170];
	local[16]= local[10];
	local[17]= local[12];
	ctx->vsp=local+18;
	w=(pointer)ELT(ctx,2,local+16); /*elt*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[14]= local[12];
	ctx->vsp=local+15;
	w=(pointer)ADD1(ctx,1,local+14); /*1+*/
	local[12] = w;
	goto WHL4383;
WHX4384:
	local[14]= NIL;
BLK4385:
	w = NIL;
	local[11]= w;
	goto IF4381;
IF4380:
	local[11]= NIL;
IF4381:
	w = local[10];
	local[0]= w;
BLK4366:
	ctx->vsp=local; return(local[0]);}

/*:distribute-total-wrench-to-torque-method-default*/
static pointer M4386robot_model_distribute_total_wrench_to_torque_method_default(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= fqv[171];
WHL4389:
	if (local[2]==NIL) goto WHX4390;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	if (w==NIL) goto IF4393;
	local[3]= argv[0];
	local[4]= local[1];
	local[5]= fqv[43];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	local[3]= local[0];
	goto IF4394;
IF4393:
	local[3]= NIL;
IF4394:
	goto WHL4389;
WHX4390:
	local[3]= NIL;
BLK4391:
	w = NIL;
	local[1]= argv[0];
	local[2]= fqv[172];
	local[3]= local[0];
	local[4]= fqv[97];
	ctx->vsp=local+5;
	w=(*ftab[13])(ctx,2,local+3,&ftab[13],fqv[80]); /*send-all*/
	local[3]= w;
	local[4]= fqv[173];
	local[5]= loadglobal(fqv[53]);
	local[6]= argv[0];
	local[7]= fqv[71];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= fqv[174];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= fqv[71];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= fqv[175];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)CONCATENATE(ctx,3,local+5); /*concatenate*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[176];
	local[4]= fqv[168];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= fqv[169];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= fqv[119];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,8,local+2); /*send*/
	local[0]= w;
BLK4387:
	ctx->vsp=local; return(local[0]);}

/*:calc-force-from-joint-torque*/
static pointer M4395robot_model_calc_force_from_joint_torque(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[177], &argv[4], n-4, local+0, 0);
	if (n & (1<<0)) goto KEY4397;
	local[2]= argv[0];
	local[3]= argv[2];
	local[4]= fqv[43];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0] = w;
KEY4397:
	if (n & (1<<1)) goto KEY4398;
	local[1] = NIL;
KEY4398:
	local[2]= argv[0];
	local[3]= fqv[55];
	local[4]= local[0];
	local[5]= fqv[56];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	if (local[1]!=NIL) goto IF4399;
	local[5]= argv[0];
	local[6]= argv[2];
	local[7]= fqv[71];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	goto IF4400;
IF4399:
	local[5]= NIL;
IF4400:
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[178];
	local[5]= local[2];
	local[6]= fqv[61];
	local[7]= local[0];
	local[8]= fqv[102];
	local[9]= T;
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[9]= w;
	local[10]= fqv[100];
	local[11]= T;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,9,local+3); /*send*/
	local[3]= w;
	local[4]= loadglobal(fqv[53]);
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)INSTANTIATE(ctx,2,local+4); /*instantiate*/
	local[4]= w;
	local[5]= makeint((eusinteger_t)0L);
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
WHL4402:
	local[7]= local[5];
	w = local[6];
	if ((eusinteger_t)local[7] >= (eusinteger_t)w) goto WHX4403;
	local[7]= local[4];
	local[8]= local[5];
	local[9]= argv[3];
	local[10]= local[2];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)ELT(ctx,2,local+10); /*elt*/
	local[10]= w;
	local[11]= fqv[79];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	local[11]= argv[0];
	local[12]= fqv[78];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[26])(ctx,2,local+10,&ftab[26],fqv[179]); /*position*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SETELT(ctx,3,local+7); /*setelt*/
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[5] = w;
	goto WHL4402;
WHX4403:
	local[7]= NIL;
BLK4404:
	w = NIL;
	local[5]= argv[0];
	local[6]= fqv[180];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)TRANSPOSE(ctx,1,local+7); /*transpose*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)TRANSFORM(ctx,2,local+5); /*transform*/
	local[0]= w;
BLK4396:
	ctx->vsp=local; return(local[0]);}

/*:fullbody-inverse-kinematics*/
static pointer M4405robot_model_fullbody_inverse_kinematics(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST4407:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[181], &argv[3], n-3, local+1, 1);
	if (n & (1<<0)) goto KEY4408;
	local[1] = NIL;
KEY4408:
	if (n & (1<<1)) goto KEY4409;
	local[2] = NIL;
KEY4409:
	if (n & (1<<2)) goto KEY4410;
	local[15]= makeint((eusinteger_t)-500L);
	local[16]= makeint((eusinteger_t)-500L);
	local[17]= makeint((eusinteger_t)-500L);
	local[18]= makeint((eusinteger_t)-20L);
	local[19]= makeint((eusinteger_t)-20L);
	local[20]= makeint((eusinteger_t)-10L);
	ctx->vsp=local+21;
	w=(pointer)MKFLTVEC(ctx,6,local+15); /*float-vector*/
	local[3] = w;
KEY4410:
	if (n & (1<<3)) goto KEY4411;
	local[15]= makeint((eusinteger_t)500L);
	local[16]= makeint((eusinteger_t)500L);
	local[17]= makeint((eusinteger_t)25L);
	local[18]= makeint((eusinteger_t)20L);
	local[19]= makeint((eusinteger_t)20L);
	local[20]= makeint((eusinteger_t)10L);
	ctx->vsp=local+21;
	w=(pointer)MKFLTVEC(ctx,6,local+15); /*float-vector*/
	local[4] = w;
KEY4411:
	if (n & (1<<4)) goto KEY4412;
	local[5] = fqv[182];
KEY4412:
	if (n & (1<<5)) goto KEY4413;
	local[15]= (pointer)get_sym_func(fqv[183]);
	local[16]= makeflt(5.0000000000000000000000e-01);
	local[17]= argv[0];
	local[18]= fqv[41];
	local[19]= fqv[43];
	local[20]= fqv[97];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,4,local+17); /*send*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)APPLY(ctx,3,local+15); /*apply*/
	local[6] = w;
KEY4413:
	if (n & (1<<6)) goto KEY4414;
	local[7] = makeflt(1.0000000000000000000000e+00);
KEY4414:
	if (n & (1<<7)) goto KEY4415;
	local[8] = fqv[7];
KEY4415:
	if (n & (1<<8)) goto KEY4416;
	local[9] = NIL;
KEY4416:
	if (n & (1<<9)) goto KEY4417;
	local[10] = makeflt(5.0000000000000000000000e+00);
KEY4417:
	if (n & (1<<10)) goto KEY4418;
	local[11] = NIL;
KEY4418:
	if (n & (1<<11)) goto KEY4419;
	local[12] = NIL;
KEY4419:
	if (n & (1<<12)) goto KEY4420;
	local[13] = NIL;
KEY4420:
	if (n & (1<<13)) goto KEY4421;
	local[14] = makeint((eusinteger_t)2L);
KEY4421:
	local[15]= argv[0];
	local[16]= (pointer)get_sym_func(fqv[184]);
	local[17]= local[2];
	ctx->vsp=local+18;
	w=(*ftab[6])(ctx,2,local+16,&ftab[6],fqv[42]); /*every*/
	if (w==NIL) goto IF4427;
	local[16]= local[2];
	goto IF4428;
IF4427:
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	local[16]= w;
IF4428:
	local[17]= fqv[185];
	local[18]= local[3];
	local[19]= fqv[186];
	local[20]= local[4];
	ctx->vsp=local+21;
	w=(pointer)LIST(ctx,4,local+17); /*list*/
	local[17]= w;
	local[18]= local[12];
	ctx->vsp=local+19;
	w=(pointer)APPEND(ctx,2,local+17); /*append*/
	local[17]= w;
	local[18]= loadglobal(fqv[33]);
	ctx->vsp=local+19;
	w=(pointer)INSTANTIATE(ctx,1,local+18); /*instantiate*/
	local[18]= w;
	local[19]= local[18];
	local[20]= fqv[34];
	ctx->vsp=local+21;
	w=(*ftab[2])(ctx,0,local+21,&ftab[2],fqv[2]); /*make-cascoords*/
	local[21]= w;
	local[22]= fqv[35];
	local[23]= makeint((eusinteger_t)150L);
	local[24]= makeint((eusinteger_t)10L);
	local[25]= makeint((eusinteger_t)400L);
	ctx->vsp=local+26;
	w=(*ftab[1])(ctx,3,local+23,&ftab[1],fqv[1]); /*make-cube*/
	local[23]= w;
	ctx->vsp=local+24;
	w=(pointer)LIST(ctx,1,local+23); /*list*/
	local[23]= w;
	local[24]= fqv[36];
	local[25]= fqv[187];
	local[26]= fqv[121];
	local[27]= makeint((eusinteger_t)0L);
	local[28]= fqv[29];
	local[29]= makeint((eusinteger_t)0L);
	local[30]= makeint((eusinteger_t)0L);
	local[31]= makeint((eusinteger_t)0L);
	ctx->vsp=local+32;
	w=(pointer)MKFLTVEC(ctx,3,local+29); /*float-vector*/
	local[29]= w;
	local[30]= fqv[188];
	local[31]= makeint((eusinteger_t)3L);
	local[32]= makeint((eusinteger_t)3L);
	ctx->vsp=local+33;
	w=(*ftab[27])(ctx,2,local+31,&ftab[27],fqv[189]); /*make-matrix*/
	local[31]= w;
	ctx->vsp=local+32;
	w=(pointer)SEND(ctx,13,local+19); /*send*/
	w = local[18];
	local[18]= w;
	local[19]= local[15];
	local[20]= fqv[71];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,2,local+19); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	local[20]= local[19];
	local[21]= loadglobal(fqv[33]);
	local[22]= fqv[190];
	local[23]= loadglobal(fqv[191]);
	ctx->vsp=local+24;
	w=(pointer)INSTANTIATE(ctx,1,local+23); /*instantiate*/
	local[23]= w;
	local[24]= (pointer)get_sym_func(fqv[60]);
	local[25]= local[23];
	local[26]= fqv[34];
	local[27]= fqv[192];
	local[28]= local[15];
	local[29]= fqv[107];
	local[30]= local[18];
	local[31]= local[17];
	ctx->vsp=local+32;
	w=(pointer)APPLY(ctx,8,local+24); /*apply*/
	w = local[23];
	local[23]= w;
	ctx->vsp=local+24;
	w=(pointer)SENDMESSAGE(ctx,4,local+20); /*send-message*/
	local[20]= local[19];
	local[21]= fqv[193];
	local[22]= local[18];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= local[18];
	local[21]= fqv[194];
	local[22]= local[19];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	ctx->vsp=local+20;
	w = makeclosure(codevec,quotevec,UWP4431,env,argv,local);
	local[20]=(pointer)(ctx->protfp); local[21]=w;
	ctx->protfp=(struct protectframe *)(local+20);
	ctx->vsp=local+22;
	local[22]= makeclosure(codevec,quotevec,CLO4432,env,argv,local);
	local[23]= local[16];
	ctx->vsp=local+24;
	w=(pointer)MAPCAR(ctx,2,local+22); /*mapcar*/
	local[22]= w;
	local[23]= (pointer)get_sym_func(fqv[60]);
	local[24]= argv[0];
	local[25]= fqv[54];
	local[26]= argv[2];
	local[27]= fqv[61];
	local[28]= local[1];
	local[29]= fqv[55];
	local[30]= local[22];
	local[31]= fqv[195];
	local[32]= local[7];
	local[33]= fqv[196];
	local[34]= local[10];
	local[35]= fqv[197];
	local[36]= local[6];
	local[37]= fqv[198];
	local[38]= local[8];
	local[39]= fqv[199];
	local[40]= local[9];
	local[41]= fqv[200];
	local[42]= local[13];
	local[43]= fqv[201];
	local[44]= local[14];
	local[45]= fqv[202];
	local[46]= local[11];
	local[47]= argv[0];
	local[48]= fqv[71];
	ctx->vsp=local+49;
	w=(pointer)SEND(ctx,2,local+47); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[47]= (w)->c.cons.car;
	local[48]= local[5];
	ctx->vsp=local+49;
	w=(pointer)LIST(ctx,2,local+47); /*list*/
	local[47]= w;
	ctx->vsp=local+48;
	w=(pointer)LIST(ctx,1,local+47); /*list*/
	local[47]= w;
	ctx->vsp=local+48;
	w=(pointer)APPEND(ctx,2,local+46); /*append*/
	local[46]= w;
	local[47]= local[0];
	ctx->vsp=local+48;
	w=(pointer)APPLY(ctx,25,local+23); /*apply*/
	ctx->vsp=local+22;
	UWP4431(ctx,0,local+22,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK4406:
	ctx->vsp=local; return(local[0]);}

/*:joint-angle-limit-nspace-for-6dof*/
static pointer M4433robot_model_joint_angle_limit_nspace_for_6dof(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[203], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY4435;
	local[0] = makeflt(9.9999999999999950039964e-03);
KEY4435:
	if (n & (1<<1)) goto KEY4436;
	local[1] = fqv[204];
KEY4436:
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO4437,env,argv,local);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[178];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO4438,env,argv,local);
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)MAPCAR(ctx,2,local+5); /*mapcar*/
	local[5]= w;
	local[6]= fqv[61];
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO4439,env,argv,local);
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)MAPCAR(ctx,2,local+7); /*mapcar*/
	local[7]= w;
	local[8]= fqv[100];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	local[9]= w;
	local[10]= fqv[205];
	local[11]= T;
	ctx->vsp=local+12;
	w=(*ftab[28])(ctx,3,local+9,&ftab[28],fqv[206]); /*make-list*/
	local[9]= w;
	local[10]= fqv[102];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)LENGTH(ctx,1,local+11); /*length*/
	local[11]= w;
	local[12]= fqv[205];
	local[13]= T;
	ctx->vsp=local+14;
	w=(*ftab[28])(ctx,3,local+11,&ftab[28],fqv[206]); /*make-list*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,9,local+3); /*send*/
	local[3]= w;
	local[4]= local[3];
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(*ftab[29])(ctx,2,local+4,&ftab[29],fqv[207]); /*array-dimension*/
	local[4]= w;
	local[5]= makeint((eusinteger_t)6L);
	ctx->vsp=local+6;
	w=(*ftab[27])(ctx,2,local+4,&ftab[27],fqv[189]); /*make-matrix*/
	local[4]= w;
	local[5]= local[3];
	local[6]= makeint((eusinteger_t)0L);
	ctx->vsp=local+7;
	w=(*ftab[29])(ctx,2,local+5,&ftab[29],fqv[207]); /*array-dimension*/
	local[5]= w;
	local[6]= argv[0];
	local[7]= fqv[103];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[27])(ctx,2,local+5,&ftab[27],fqv[189]); /*make-matrix*/
	local[5]= w;
	local[6]= makeint((eusinteger_t)0L);
	local[7]= local[4];
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(*ftab[29])(ctx,2,local+7,&ftab[29],fqv[207]); /*array-dimension*/
	local[7]= w;
WHL4441:
	local[8]= local[6];
	w = local[7];
	if ((eusinteger_t)local[8] >= (eusinteger_t)w) goto WHX4442;
	local[8]= makeint((eusinteger_t)0L);
	local[9]= local[4];
	local[10]= makeint((eusinteger_t)1L);
	ctx->vsp=local+11;
	w=(*ftab[29])(ctx,2,local+9,&ftab[29],fqv[207]); /*array-dimension*/
	local[9]= w;
WHL4445:
	local[10]= local[8];
	w = local[9];
	if ((eusinteger_t)local[10] >= (eusinteger_t)w) goto WHX4446;
	local[10]= local[4];
	local[11]= local[6];
	local[12]= local[8];
	local[13]= local[3];
	local[14]= local[6];
	local[15]= local[8];
	ctx->vsp=local+16;
	w=(pointer)AREF(ctx,3,local+13); /*aref*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)ASET(ctx,4,local+10); /*aset*/
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[8] = w;
	goto WHL4445;
WHX4446:
	local[10]= NIL;
BLK4447:
	w = NIL;
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[6] = w;
	goto WHL4441;
WHX4442:
	local[8]= NIL;
BLK4443:
	w = NIL;
	local[6]= makeint((eusinteger_t)0L);
	local[7]= local[5];
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(*ftab[29])(ctx,2,local+7,&ftab[29],fqv[207]); /*array-dimension*/
	local[7]= w;
WHL4449:
	local[8]= local[6];
	w = local[7];
	if ((eusinteger_t)local[8] >= (eusinteger_t)w) goto WHX4450;
	local[8]= makeint((eusinteger_t)0L);
	local[9]= local[5];
	local[10]= makeint((eusinteger_t)1L);
	ctx->vsp=local+11;
	w=(*ftab[29])(ctx,2,local+9,&ftab[29],fqv[207]); /*array-dimension*/
	local[9]= w;
WHL4453:
	local[10]= local[8];
	w = local[9];
	if ((eusinteger_t)local[10] >= (eusinteger_t)w) goto WHX4454;
	local[10]= local[5];
	local[11]= local[6];
	local[12]= local[8];
	local[13]= local[3];
	local[14]= local[6];
	local[15]= makeint((eusinteger_t)6L);
	w = local[8];
#if sun4 || vax || mips || alpha || Linux
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[15]= (pointer)((eusinteger_t)local[15] + (eusinteger_t)w);
	ctx->vsp=local+16;
	w=(pointer)AREF(ctx,3,local+13); /*aref*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)ASET(ctx,4,local+10); /*aset*/
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[8] = w;
	goto WHL4453;
WHX4454:
	local[10]= NIL;
BLK4455:
	w = NIL;
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[6] = w;
	goto WHL4449;
WHX4450:
	local[8]= NIL;
BLK4451:
	w = NIL;
	local[6]= argv[0];
	local[7]= fqv[180];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)MATTIMES(ctx,2,local+6); /*m**/
	local[6]= w;
	local[7]= makeint((eusinteger_t)-1L);
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	local[8]= argv[0];
	local[9]= fqv[208];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	local[9]= fqv[79];
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[80]); /*send-all*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[30])(ctx,1,local+8,&ftab[30],fqv[209]); /*joint-angle-limit-nspace*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SCALEVEC(ctx,2,local+7); /*scale*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)TRANSFORM(ctx,2,local+6); /*transform*/
	local[6]= w;
	local[7]= local[6];
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)SETELT(ctx,3,local+7); /*setelt*/
	local[7]= local[6];
	local[8]= makeint((eusinteger_t)1L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)SETELT(ctx,3,local+7); /*setelt*/
	w = local[6];
	local[0]= w;
BLK4434:
	ctx->vsp=local; return(local[0]);}

/*:joint-order*/
static pointer M4456robot_model_joint_order(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT4459;}
	local[0]= NIL;
ENT4459:
ENT4458:
	if (n>4) maerror();
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO4460,env,argv,local);
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO4461,env,argv,local);
	local[3]= argv[0];
	local[4]= fqv[210];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MAPCAN(ctx,2,local+2); /*mapcan*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	if (local[0]!=NIL) goto IF4462;
	local[5]= argv[2];
	local[6]= local[5];
	w = fqv[211];
	if (memq(local[6],w)==NIL) goto IF4465;
	local[6]= fqv[212];
	goto IF4466;
IF4465:
	local[6]= local[5];
	w = fqv[213];
	if (memq(local[6],w)==NIL) goto IF4467;
	local[6]= fqv[214];
	goto IF4468;
IF4467:
	local[6]= local[5];
	w = fqv[215];
	if (memq(local[6],w)==NIL) goto IF4469;
	local[6]= fqv[216];
	goto IF4470;
IF4469:
	local[6]= local[5];
	w = fqv[217];
	if (memq(local[6],w)==NIL) goto IF4471;
	local[6]= fqv[218];
	goto IF4472;
IF4471:
	local[6]= NIL;
IF4472:
IF4470:
IF4468:
IF4466:
	w = local[6];
	local[0] = w;
	local[5]= local[0];
	goto IF4463;
IF4462:
	local[5]= NIL;
IF4463:
	local[5]= NIL;
	local[6]= local[0];
WHL4474:
	if (local[6]==NIL) goto WHX4475;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
WHL4478:
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(*ftab[11])(ctx,1,local+7,&ftab[11],fqv[74]); /*string-upcase*/
	local[7]= w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(*ftab[31])(ctx,1,local+8,&ftab[31],fqv[219]); /*symbol-name*/
	local[4] = w;
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(*ftab[32])(ctx,2,local+7,&ftab[32],fqv[220]); /*substringp*/
	if (w==NIL) goto WHX4479;
	local[7]= NIL;
	local[8]= fqv[221];
	local[9]= local[4];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)LENGTH(ctx,1,local+10); /*length*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SUB1(ctx,1,local+10); /*1-*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SUBSEQ(ctx,2,local+9); /*subseq*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[8])(ctx,1,local+7,&ftab[8],fqv[47]); /*read-from-string*/
	local[7]= w;
	w = local[2];
	ctx->vsp=local+8;
	local[2] = cons(ctx,local[7],w);
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[7];
	goto WHL4478;
WHX4479:
	local[7]= NIL;
BLK4480:
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)NREVERSE(ctx,1,local+7); /*nreverse*/
	local[7]= local[2];
	w = local[3];
	ctx->vsp=local+8;
	local[3] = cons(ctx,local[7],w);
	local[2] = NIL;
	goto WHL4474;
WHX4475:
	local[7]= NIL;
BLK4476:
	w = NIL;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)NREVERSE(ctx,1,local+5); /*nreverse*/
	local[0]= w;
BLK4457:
	ctx->vsp=local; return(local[0]);}

/*:print-vector-for-robot-limb*/
static pointer M4482robot_model_print_vector_for_robot_limb(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO4484,env,argv,local);
	local[1]= argv[0];
	local[2]= fqv[78];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[192];
	ctx->vsp=local+3;
	w=(*ftab[13])(ctx,2,local+1,&ftab[13],fqv[80]); /*send-all*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[33])(ctx,1,local+0,&ftab[33],fqv[222]); /*remove-duplicates*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[78];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= T;
	local[3]= fqv[223];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,2,local+2); /*format*/
	local[2]= NIL;
	local[3]= local[0];
WHL4486:
	if (local[3]==NIL) goto WHX4487;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= NIL;
	local[5]= argv[0];
	local[6]= local[2];
	local[7]= fqv[78];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
WHL4491:
	if (local[5]==NIL) goto WHX4492;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= T;
	local[7]= fqv[224];
	local[8]= argv[2];
	local[9]= local[4];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(*ftab[26])(ctx,2,local+9,&ftab[26],fqv[179]); /*position*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	goto WHL4491;
WHX4492:
	local[6]= NIL;
BLK4493:
	w = NIL;
	local[4]= T;
	local[5]= fqv[225];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,2,local+4); /*format*/
	goto WHL4486;
WHX4487:
	local[4]= NIL;
BLK4488:
	w = NIL;
	local[2]= T;
	local[3]= fqv[226];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,2,local+2); /*format*/
	w = argv[2];
	local[0]= w;
BLK4483:
	ctx->vsp=local; return(local[0]);}

/*:calc-zmp-from-forces-moments*/
static pointer M4495robot_model_calc_zmp_from_forces_moments(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[227], &argv[4], n-4, local+0, 0);
	if (n & (1<<0)) goto KEY4497;
	local[0] = fqv[20];
KEY4497:
	if (n & (1<<1)) goto KEY4498;
	local[6]= argv[0];
	local[7]= fqv[86];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	if (w==NIL) goto IF4499;
	local[6]= NIL;
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO4501,env,argv,local);
	local[8]= argv[0];
	local[9]= fqv[86];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MAPCAR(ctx,2,local+7); /*mapcar*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[7])(ctx,2,local+6,&ftab[7],fqv[45]); /*remove*/
	local[6]= w;
	goto IF4500;
IF4499:
	local[6]= fqv[228];
IF4500:
	local[1] = local[6];
KEY4498:
	if (n & (1<<2)) goto KEY4502;
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO4503,env,argv,local);
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[2] = w;
KEY4502:
	if (n & (1<<3)) goto KEY4504;
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO4505,env,argv,local);
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[3] = w;
KEY4504:
	if (n & (1<<4)) goto KEY4506;
	local[4] = makeflt(1.0000000000000000208167e-03);
KEY4506:
	if (n & (1<<5)) goto KEY4507;
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO4508,env,argv,local);
	local[7]= local[2];
	local[8]= argv[2];
	local[9]= argv[3];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)MAPCAR(ctx,5,local+6); /*mapcar*/
	local[5] = w;
KEY4507:
	local[6]= NIL;
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(*ftab[7])(ctx,2,local+6,&ftab[7],fqv[45]); /*remove*/
	local[6]= w;
	local[7]= (pointer)get_sym_func(fqv[30]);
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,CLO4509,env,argv,local);
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)MAPCAR(ctx,2,local+8); /*mapcar*/
	local[8]= w;
	local[9]= fqv[157];
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(*ftab[5])(ctx,4,local+7,&ftab[5],fqv[31]); /*reduce*/
	local[7]= w;
	local[8]= local[7];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)LESSP(ctx,2,local+8); /*<*/
	if (w==NIL) goto IF4510;
	local[8]= NIL;
	goto IF4511;
IF4510:
	local[8]= makeflt(1.0000000000000000000000e+00);
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	local[9]= (pointer)get_sym_func(fqv[32]);
	ctx->vsp=local+10;
	local[10]= makeclosure(codevec,quotevec,CLO4512,env,argv,local);
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)MAPCAR(ctx,2,local+10); /*mapcar*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[5])(ctx,2,local+9,&ftab[5],fqv[31]); /*reduce*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,2,local+8); /*scale*/
	local[8]= w;
	local[9]= local[0];
	if (fqv[20]!=local[9]) goto CON4514;
	local[9]= local[8];
	goto CON4513;
CON4514:
	local[9]= local[0];
	if (fqv[65]!=local[9]) goto CON4515;
	local[9]= argv[0];
	local[10]= fqv[71];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= fqv[229];
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= w;
	goto CON4513;
CON4515:
	local[9]= T;
	if (local[9]!=NIL) goto CON4513;
CON4516:
	local[9]= NIL;
CON4513:
	w = local[9];
	local[8]= w;
IF4511:
	w = local[8];
	local[0]= w;
BLK4496:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4144(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[79];
	local[2]= fqv[129];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4145(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[79];
	local[2]= fqv[129];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4253(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[36];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[34])(ctx,1,local+0,&ftab[34],fqv[230]); /*string*/
	local[0]= w;
	local[1]= argv[1];
	local[2]= fqv[36];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[34])(ctx,1,local+1,&ftab[34],fqv[230]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)STR_LT(ctx,2,local+0); /*string<*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4258(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[129];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4267(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[36];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4270(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[56];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= env->c.clo.env1[0];
	local[2]= env->c.clo.env1[3];
	local[3]= fqv[49];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[20])(ctx,1,local+1,&ftab[20],fqv[128]); /*all-child-links*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[35])(ctx,2,local+0,&ftab[35],fqv[231]); /*member*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4315(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= argv[0];
	local[2]= fqv[43];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4328(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= fqv[55];
	local[2]= argv[0];
	local[3]= fqv[56];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4334(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[25])(ctx,1,local+0,&ftab[25],fqv[155]); /*coordinates-p*/
	local[0]= w;
	if (w!=NIL) goto OR4517;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[23])(ctx,1,local+0,&ftab[23],fqv[149]); /*functionp*/
	local[0]= w;
OR4517:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4346(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= fqv[55];
	local[2]= argv[0];
	local[3]= fqv[56];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP4431(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[19];
	local[1]= fqv[232];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= env->c.clo.env2[19];
	local[1]= fqv[233];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= env->c.clo.env2[18];
	local[1]= fqv[234];
	local[2]= env->c.clo.env2[19];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4432(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env2[19];
	w = argv[0];
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4437(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= argv[0];
	local[2]= fqv[71];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4438(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= fqv[71];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4439(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= argv[0];
	local[2]= fqv[43];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4460(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO4518,env,argv,local);
	local[2]= env->c.clo.env1[0];
	local[3]= env->c.clo.env1[2];
	local[4]= fqv[78];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[36])(ctx,2,local+1,&ftab[36],fqv[235]); /*find-if*/
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4518(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env0->c.clo.env1[0];
	local[2]= env->c.clo.env1[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = ((w)==(local[0])?T:NIL);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4461(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= fqv[236];
	local[2]= env->c.clo.env1[2];
	ctx->vsp=local+3;
	w=(*ftab[31])(ctx,1,local+2,&ftab[31],fqv[219]); /*symbol-name*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[34])(ctx,1,local+1,&ftab[34],fqv[230]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[32])(ctx,2,local+0,&ftab[32],fqv[220]); /*substringp*/
	if (w==NIL) goto IF4519;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF4520;
IF4519:
	local[0]= NIL;
IF4520:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4484(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO4521,env,argv,local);
	local[1]= fqv[237];
	ctx->vsp=local+2;
	w=(*ftab[36])(ctx,2,local+0,&ftab[36],fqv[235]); /*find-if*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4521(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= env->c.clo.env0->c.clo.env1[0];
	local[2]= argv[0];
	local[3]= fqv[71];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[35])(ctx,2,local+0,&ftab[35],fqv[231]); /*member*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4501(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO4522,env,argv,local);
	local[1]= fqv[238];
	ctx->vsp=local+2;
	w=(*ftab[36])(ctx,2,local+0,&ftab[36],fqv[235]); /*find-if*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4522(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= env->c.clo.env0->c.clo.env1[0];
	local[2]= argv[0];
	local[3]= fqv[86];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)EQUAL(ctx,2,local+0); /*equal*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4503(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= fqv[132];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4505(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= argv[0];
	local[2]= fqv[43];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4508(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= makeflt(1.0000000000000000208167e-03);
	local[1]= argv[0];
	local[2]= fqv[97];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SCALEVEC(ctx,2,local+0); /*scale*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[108];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[108];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= env->c.clo.env1[0];
	local[4]= fqv[239];
	local[5]= local[1];
	local[6]= local[2];
	local[7]= argv[0];
	local[8]= argv[3];
	local[9]= fqv[240];
	local[10]= env->c.clo.env2[4];
	local[11]= fqv[241];
	local[12]= T;
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,10,local+3); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4509(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[242];
	w = argv[0];
	w=memq(local[0],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4512(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[242];
	w = argv[0];
	w=memq(local[0],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= fqv[243];
	w = argv[0];
	w=memq(local[1],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)SCALEVEC(ctx,2,local+0); /*scale*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:foot-midcoords*/
static pointer M4523robot_model_foot_midcoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4526;}
	local[0]= makeflt(5.0000000000000000000000e-01);
ENT4526:
ENT4525:
	if (n>3) maerror();
	local[1]= (pointer)get_sym_func(fqv[244]);
	local[2]= local[0];
	local[3]= argv[0];
	local[4]= fqv[41];
	local[5]= fqv[43];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[0]= w;
BLK4524:
	ctx->vsp=local; return(local[0]);}

/*:fix-leg-to-coords*/
static pointer M4527robot_model_fix_leg_to_coords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT4530;}
	local[0]= fqv[245];
ENT4530:
ENT4529:
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[246], &argv[4], n-4, local+1, 1);
	if (n & (1<<0)) goto KEY4531;
	local[1] = makeflt(5.0000000000000000000000e-01);
KEY4531:
	local[2]= (pointer)get_sym_func(fqv[40]);
	local[3]= argv[0];
	local[4]= fqv[41];
	local[5]= fqv[71];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[37])(ctx,2,local+2,&ftab[37],fqv[247]); /*some*/
	if (w==NIL) goto IF4532;
	w = NIL;
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK4528;
	goto IF4533;
IF4532:
	local[2]= NIL;
IF4533:
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= local[0];
	if (fqv[248]==local[8]) goto OR4536;
	local[8]= local[0];
	if (fqv[142]==local[8]) goto OR4536;
	goto CON4535;
OR4536:
	local[8]= argv[0];
	local[9]= fqv[142];
	local[10]= fqv[43];
	local[11]= fqv[64];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[2] = w;
	local[8]= local[2];
	goto CON4534;
CON4535:
	local[8]= local[0];
	if (fqv[249]==local[8]) goto OR4538;
	local[8]= local[0];
	if (fqv[143]==local[8]) goto OR4538;
	goto CON4537;
OR4538:
	local[8]= argv[0];
	local[9]= fqv[143];
	local[10]= fqv[43];
	local[11]= fqv[64];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[2] = w;
	local[8]= local[2];
	goto CON4534;
CON4537:
	local[8]= local[1];
	local[9]= argv[0];
	local[10]= fqv[142];
	local[11]= fqv[43];
	local[12]= fqv[64];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,4,local+9); /*send*/
	local[9]= w;
	local[10]= argv[0];
	local[11]= fqv[143];
	local[12]= fqv[43];
	local[13]= fqv[64];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[38])(ctx,3,local+8,&ftab[38],fqv[244]); /*midcoords*/
	local[2] = w;
	local[8]= local[2];
	goto CON4534;
CON4539:
	local[8]= NIL;
CON4534:
	local[8]= argv[2];
	local[9]= fqv[64];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[3] = w;
	local[8]= local[2];
	local[9]= fqv[250];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[4] = w;
	local[8]= local[3];
	local[9]= fqv[21];
	local[10]= local[4];
	local[11]= fqv[65];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= argv[0];
	local[9]= fqv[251];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= argv[0];
	local[9]= fqv[252];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	w = local[3];
	local[0]= w;
BLK4528:
	ctx->vsp=local; return(local[0]);}

/*:move-centroid-on-foot*/
static pointer M4540robot_model_move_centroid_on_foot(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
RST4542:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-4);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[253], &argv[4], n-4, local+1, 1);
	if (n & (1<<0)) goto KEY4543;
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO4544,env,argv,local);
	local[8]= argv[3];
	ctx->vsp=local+9;
	w=(pointer)MAPCAR(ctx,2,local+7); /*mapcar*/
	local[1] = w;
KEY4543:
	if (n & (1<<1)) goto KEY4545;
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO4546,env,argv,local);
	local[8]= argv[3];
	ctx->vsp=local+9;
	w=(pointer)MAPCAR(ctx,2,local+7); /*mapcar*/
	local[2] = w;
KEY4545:
	if (n & (1<<2)) goto KEY4547;
	local[3] = makeflt(5.0000000000000000000000e-01);
KEY4547:
	if (n & (1<<3)) goto KEY4548;
	local[7]= argv[2];
	if (fqv[245]!=local[7]) goto IF4549;
	local[7]= (pointer)get_sym_func(fqv[183]);
	local[8]= local[3];
	ctx->vsp=local+9;
	local[9]= makeclosure(codevec,quotevec,CLO4551,env,argv,local);
	ctx->vsp=local+10;
	local[10]= makeclosure(codevec,quotevec,CLO4552,env,argv,local);
	local[11]= argv[3];
	ctx->vsp=local+12;
	w=(*ftab[22])(ctx,2,local+10,&ftab[22],fqv[139]); /*remove-if-not*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)MAPCAR(ctx,2,local+9); /*mapcar*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)APPLY(ctx,3,local+7); /*apply*/
	local[7]= w;
	goto IF4550;
IF4549:
	local[7]= argv[0];
	local[8]= argv[2];
	local[9]= fqv[43];
	local[10]= fqv[97];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[7]= w;
IF4550:
	local[4] = local[7];
KEY4548:
	if (n & (1<<4)) goto KEY4553;
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO4554,env,argv,local);
	local[8]= argv[3];
	ctx->vsp=local+9;
	w=(pointer)MAPCAR(ctx,2,local+7); /*mapcar*/
	local[5] = w;
KEY4553:
	if (n & (1<<5)) goto KEY4555;
	local[6] = fqv[254];
KEY4555:
	local[7]= argv[0];
	w = argv[3];
	if (!!iscons(w)) goto IF4560;
	local[8]= argv[3];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	local[8]= w;
	goto IF4561;
IF4560:
	local[8]= argv[3];
IF4561:
	if (NIL==NIL) goto CON4563;
	w = NIL;
	if (!!iscons(w)) goto IF4564;
	local[9]= NIL;
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[9]= w;
	goto IF4565;
IF4564:
	local[9]= NIL;
IF4565:
	goto CON4562;
CON4563:
	ctx->vsp=local+9;
	local[9]= makeclosure(codevec,quotevec,CLO4567,env,argv,local);
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)MAPCAR(ctx,2,local+9); /*mapcar*/
	local[9]= w;
	goto CON4562;
CON4566:
	local[9]= NIL;
CON4562:
	ctx->vsp=local+10;
	local[10]= makeclosure(codevec,quotevec,CLO4568,env,argv,local);
	local[11]= local[9];
	ctx->vsp=local+12;
	w=(pointer)MAPCAR(ctx,2,local+10); /*mapcar*/
	local[10]= w;
	local[11]= local[9];
	local[12]= local[10];
	local[13]= (pointer)get_sym_func(fqv[60]);
	local[14]= argv[0];
	local[15]= fqv[255];
	local[16]= local[5];
	local[17]= fqv[61];
	local[18]= local[11];
	local[19]= fqv[55];
	local[20]= local[12];
	local[21]= fqv[256];
	ctx->vsp=local+22;
	local[22]= makeclosure(codevec,quotevec,CLO4569,env,argv,local);
	local[23]= argv[3];
	ctx->vsp=local+24;
	w=(*ftab[22])(ctx,2,local+22,&ftab[22],fqv[139]); /*remove-if-not*/
	local[22]= w;
	local[23]= fqv[257];
	local[24]= local[6];
	local[25]= fqv[258];
	local[26]= local[1];
	local[27]= fqv[259];
	local[28]= local[2];
	local[29]= fqv[197];
	local[30]= local[4];
	local[31]= local[0];
	ctx->vsp=local+32;
	w=(pointer)APPLY(ctx,19,local+13); /*apply*/
	local[0]= w;
BLK4541:
	ctx->vsp=local; return(local[0]);}

/*:calc-walk-pattern-from-footstep-list*/
static pointer M4570robot_model_calc_walk_pattern_from_footstep_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[260], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY4572;
	local[0] = makeint((eusinteger_t)50L);
KEY4572:
	if (n & (1<<1)) goto KEY4573;
	local[1] = makeflt(9.9999999999999977795540e-02);
KEY4573:
	if (n & (1<<2)) goto KEY4574;
	local[2] = makeflt(1.0000000000000000000000e+00);
KEY4574:
	if (n & (1<<3)) goto KEY4575;
	local[3] = NIL;
KEY4575:
	if (n & (1<<4)) goto KEY4576;
	local[4] = NIL;
KEY4576:
	if (n & (1<<5)) goto KEY4577;
	local[13]= argv[0];
	local[14]= fqv[86];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	if (w==NIL) goto IF4578;
	local[13]= NIL;
	ctx->vsp=local+14;
	local[14]= makeclosure(codevec,quotevec,CLO4580,env,argv,local);
	local[15]= argv[0];
	local[16]= fqv[86];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)MAPCAR(ctx,2,local+14); /*mapcar*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(*ftab[7])(ctx,2,local+13,&ftab[7],fqv[45]); /*remove*/
	local[13]= w;
	goto IF4579;
IF4578:
	local[13]= fqv[261];
IF4579:
	local[5] = local[13];
KEY4577:
	if (n & (1<<6)) goto KEY4581;
	ctx->vsp=local+13;
	local[13]= makeclosure(codevec,quotevec,CLO4582,env,argv,local);
	local[14]= local[5];
	ctx->vsp=local+15;
	w=(pointer)MAPCAN(ctx,2,local+13); /*mapcan*/
	local[6] = w;
KEY4581:
	if (n & (1<<7)) goto KEY4583;
	ctx->vsp=local+13;
	local[7] = makeclosure(codevec,quotevec,CLO4584,env,argv,local);
KEY4583:
	if (n & (1<<8)) goto KEY4585;
	local[8] = T;
KEY4585:
	if (n & (1<<9)) goto KEY4586;
	local[9] = T;
KEY4586:
	if (n & (1<<10)) goto KEY4587;
	local[10] = makeint((eusinteger_t)1L);
KEY4587:
	if (n & (1<<11)) goto KEY4588;
	local[13]= makeint((eusinteger_t)1L);
	ctx->vsp=local+14;
	w=(*ftab[10])(ctx,1,local+13,&ftab[10],fqv[67]); /*deg2rad*/
	local[11] = w;
KEY4588:
	if (n & (1<<12)) goto KEY4589;
	local[12] = T;
KEY4589:
	local[13]= NIL;
	local[14]= NIL;
	local[15]= makeint((eusinteger_t)0L);
	local[16]= loadglobal(fqv[262]);
	ctx->vsp=local+17;
	w=(pointer)INSTANTIATE(ctx,1,local+16); /*instantiate*/
	local[16]= w;
	local[17]= local[16];
	local[18]= fqv[34];
	local[19]= argv[0];
	local[20]= local[1];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,4,local+17); /*send*/
	w = local[16];
	local[16]= w;
	local[17]= local[7];
	ctx->vsp=local+18;
	w=(pointer)FUNCALL(ctx,1,local+17); /*funcall*/
	local[17]= local[16];
	local[18]= fqv[263];
	local[19]= argv[2];
	local[20]= local[2];
	local[21]= argv[0];
	local[22]= fqv[29];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,2,local+21); /*send*/
	local[21]= w;
	local[22]= fqv[264];
	local[23]= local[0];
	local[24]= fqv[265];
	local[25]= makeflt(1.9999999999999995559108e-01);
	local[26]= fqv[266];
	local[27]= local[6];
	local[28]= fqv[267];
	local[29]= local[5];
	local[30]= fqv[258];
	local[31]= local[10];
	local[32]= fqv[259];
	local[33]= local[11];
	local[34]= fqv[268];
	local[35]= local[8];
	local[36]= fqv[269];
	local[37]= local[9];
	ctx->vsp=local+38;
	w=(pointer)SEND(ctx,21,local+17); /*send*/
WHL4591:
	local[17]= local[16];
	local[18]= fqv[270];
	local[19]= fqv[271];
	local[20]= fqv[272];
	local[21]= fqv[273];
	local[22]= T;
	local[23]= fqv[274];
	local[24]= local[3];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,8,local+17); /*send*/
	local[14] = w;
	if (local[14]!=NIL) goto WHX4592;
	goto WHL4591;
WHX4592:
	local[17]= NIL;
BLK4593:
	if (local[12]==NIL) goto IF4594;
	local[17]= makeint((eusinteger_t)0L);
	local[18]= makeint((eusinteger_t)2L);
WHL4597:
	local[19]= local[17];
	w = local[18];
	if ((eusinteger_t)local[19] >= (eusinteger_t)w) goto WHX4598;
	local[19]= argv[0];
	local[20]= fqv[275];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,2,local+19); /*send*/
	local[19]= local[17];
	ctx->vsp=local+20;
	w=(pointer)ADD1(ctx,1,local+19); /*1+*/
	local[17] = w;
	goto WHL4597;
WHX4598:
	local[19]= NIL;
BLK4599:
	w = NIL;
	local[17]= w;
	goto IF4595;
IF4594:
	local[17]= NIL;
IF4595:
WHL4600:
	local[17]= local[16];
	local[18]= fqv[270];
	local[19]= fqv[271];
	local[20]= fqv[272];
	local[21]= fqv[273];
	local[22]= T;
	local[23]= fqv[274];
	local[24]= local[3];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,8,local+17); /*send*/
	local[14] = w;
	if (local[14]==NIL) goto WHX4601;
	if (local[12]==NIL) goto IF4603;
	local[17]= argv[0];
	local[18]= fqv[275];
	local[19]= argv[0];
	local[20]= fqv[51];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,2,local+19); /*send*/
	local[19]= w;
	local[20]= argv[0];
	local[21]= fqv[71];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,2,local+20); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	local[21]= fqv[64];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,2,local+20); /*send*/
	local[20]= w;
	local[21]= fqv[167];
	local[22]= local[1];
	local[23]= fqv[276];
	local[24]= local[14];
	local[25]= makeint((eusinteger_t)5L);
	ctx->vsp=local+26;
	w=(pointer)ELT(ctx,2,local+24); /*elt*/
	local[24]= w;
	local[25]= makeint((eusinteger_t)2L);
	ctx->vsp=local+26;
	w=(pointer)ELT(ctx,2,local+24); /*elt*/
	local[24]= w;
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,8,local+17); /*send*/
	local[17]= w;
	goto IF4604;
IF4603:
	local[17]= NIL;
IF4604:
	ctx->vsp=local+18;
	local[18]= makeclosure(codevec,quotevec,CLO4605,env,argv,local);
	local[19]= *(ovafptr(local[16],fqv[277]));
	ctx->vsp=local+20;
	w=(pointer)MAPCAR(ctx,2,local+18); /*mapcar*/
	local[18]= w;
	local[19]= local[14];
	local[20]= makeint((eusinteger_t)8L);
	ctx->vsp=local+21;
	w=(pointer)ELT(ctx,2,local+19); /*elt*/
	local[19]= w;
	if (local[4]==NIL) goto IF4606;
	local[20]= argv[0];
	local[21]= fqv[278];
	local[22]= local[18];
	local[23]= local[19];
	local[24]= local[14];
	local[25]= makeint((eusinteger_t)5L);
	ctx->vsp=local+26;
	w=(pointer)ELT(ctx,2,local+24); /*elt*/
	local[24]= w;
	local[25]= local[14];
	local[26]= makeint((eusinteger_t)6L);
	ctx->vsp=local+27;
	w=(pointer)ELT(ctx,2,local+25); /*elt*/
	local[25]= w;
	local[26]= local[14];
	local[27]= makeint((eusinteger_t)7L);
	ctx->vsp=local+28;
	w=(pointer)ELT(ctx,2,local+26); /*elt*/
	local[26]= w;
	local[27]= local[17];
	local[28]= local[1];
	ctx->vsp=local+29;
	w=(pointer)SEND(ctx,9,local+20); /*send*/
	ctx->vsp=local+20;
	w=(*ftab[39])(ctx,0,local+20,&ftab[39],fqv[279]); /*x::window-main-one*/
	local[20]= w;
	goto IF4607;
IF4606:
	local[20]= NIL;
IF4607:
	local[20]= fqv[51];
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	local[22]= fqv[166];
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	local[24]= fqv[280];
	local[25]= local[17];
	local[26]= fqv[281];
	local[27]= local[14];
	local[28]= makeint((eusinteger_t)5L);
	ctx->vsp=local+29;
	w=(pointer)ELT(ctx,2,local+27); /*elt*/
	local[27]= w;
	local[28]= fqv[282];
	local[29]= local[14];
	local[30]= makeint((eusinteger_t)6L);
	ctx->vsp=local+31;
	w=(pointer)ELT(ctx,2,local+29); /*elt*/
	local[29]= w;
	local[30]= fqv[283];
	local[31]= local[15];
	local[32]= fqv[284];
	local[33]= local[14];
	local[34]= makeint((eusinteger_t)7L);
	ctx->vsp=local+35;
	w=(pointer)ELT(ctx,2,local+33); /*elt*/
	local[33]= w;
	local[34]= fqv[267];
	local[35]= local[5];
	local[36]= fqv[285];
	local[37]= local[19];
	local[38]= fqv[286];
	local[39]= local[18];
	ctx->vsp=local+40;
	w=(pointer)LIST(ctx,20,local+20); /*list*/
	local[20]= w;
	w = local[13];
	ctx->vsp=local+21;
	local[13] = cons(ctx,local[20],w);
	local[20]= local[15];
	local[21]= local[1];
	ctx->vsp=local+22;
	w=(pointer)PLUS(ctx,2,local+20); /*+*/
	local[15] = w;
	w = local[15];
	goto WHL4600;
WHX4601:
	local[17]= NIL;
BLK4602:
	local[17]= local[13];
	ctx->vsp=local+18;
	w=(pointer)REVERSE(ctx,1,local+17); /*reverse*/
	local[0]= w;
BLK4571:
	ctx->vsp=local; return(local[0]);}

/*:draw-gg-debug-view*/
static pointer M4608robot_model_draw_gg_debug_view(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=9) maerror();
	local[0]= loadglobal(fqv[287]);
	local[1]= fqv[288];
	local[2]= fqv[289];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,FLET4610,env,argv,local);
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO4611,env,argv,local);
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,3,local+1); /*mapcar*/
	local[1]= argv[4];
	local[2]= fqv[290];
	local[3]= fqv[289];
	local[4]= NIL;
	local[5]= fqv[291];
	local[6]= makeint((eusinteger_t)300L);
	local[7]= fqv[292];
	local[8]= fqv[293];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,8,local+1); /*send*/
	if (argv[7]==NIL) goto IF4612;
	local[1]= argv[7];
	local[2]= fqv[290];
	local[3]= fqv[289];
	local[4]= NIL;
	local[5]= fqv[291];
	local[6]= makeint((eusinteger_t)200L);
	local[7]= fqv[294];
	local[8]= makeint((eusinteger_t)5L);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,8,local+1); /*send*/
	local[1]= w;
	goto IF4613;
IF4612:
	local[1]= NIL;
IF4613:
	local[1]= fqv[295];
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO4614,env,argv,local);
	w = local[0];
	ctx->vsp=local+3;
	w=FLET4610(ctx,2,local+1,w);
	local[1]= fqv[296];
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO4615,env,argv,local);
	w = local[0];
	ctx->vsp=local+3;
	w=FLET4610(ctx,2,local+1,w);
	local[1]= fqv[297];
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO4616,env,argv,local);
	w = local[0];
	ctx->vsp=local+3;
	w=FLET4610(ctx,2,local+1,w);
	local[1]= fqv[298];
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO4617,env,argv,local);
	w = local[0];
	ctx->vsp=local+3;
	w=FLET4610(ctx,2,local+1,w);
	local[0]= loadglobal(fqv[287]);
	local[1]= fqv[299];
	local[2]= fqv[289];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK4609:
	ctx->vsp=local; return(local[0]);}

/*:gen-footstep-parameter*/
static pointer M4618robot_model_gen_footstep_parameter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[300], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY4620;
	local[1]= makeflt(1.0000000000000000000000e+00);
	goto KEY4621;
KEY4620:
	local[1]= local[0];
KEY4621:
	w = local[1];
	ctx->vsp=local+1;
	bindspecial(ctx,fqv[301],w);
	local[4]= fqv[302];
	ctx->vsp=local+5;
	w=(*ftab[15])(ctx,1,local+4,&ftab[15],fqv[92]); /*warn*/
	local[4]= argv[0];
	local[5]= fqv[51];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[64];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= argv[0];
	local[7]= fqv[303];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= argv[0];
	local[7]= fqv[304];
	ctx->vsp=local+8;
	w=(*ftab[16])(ctx,0,local+8,&ftab[16],fqv[96]); /*make-coords*/
	local[8]= w;
	local[9]= fqv[305];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[6]= (pointer)get_sym_func(fqv[306]);
	local[7]= argv[0];
	local[8]= fqv[41];
	local[9]= fqv[43];
	local[10]= fqv[97];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,2,local+6); /*apply*/
	local[6]= w;
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ABS(ctx,1,local+6); /*abs*/
	local[6]= w;
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,FLET4622,env,argv,local);
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,CLO4623,env,argv,local);
	ctx->vsp=local+9;
	local[9]= makeclosure(codevec,quotevec,CLO4624,env,argv,local);
	w = local[7];
	ctx->vsp=local+10;
	w=FLET4622(ctx,2,local+8,w);
	local[8]= w;
	ctx->vsp=local+9;
	local[9]= makeclosure(codevec,quotevec,CLO4625,env,argv,local);
	ctx->vsp=local+10;
	local[10]= makeclosure(codevec,quotevec,CLO4626,env,argv,local);
	w = local[7];
	ctx->vsp=local+11;
	w=FLET4622(ctx,2,local+9,w);
	local[9]= w;
	ctx->vsp=local+10;
	local[10]= makeclosure(codevec,quotevec,CLO4627,env,argv,local);
	ctx->vsp=local+11;
	local[11]= makeclosure(codevec,quotevec,CLO4628,env,argv,local);
	ctx->vsp=local+12;
	local[12]= makeclosure(codevec,quotevec,CLO4629,env,argv,local);
	w = local[7];
	ctx->vsp=local+13;
	w=FLET4622(ctx,3,local+10,w);
	local[10]= w;
	local[11]= argv[0];
	local[12]= fqv[251];
	local[13]= local[5];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[11]= argv[0];
	local[12]= fqv[51];
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[11]= fqv[307];
	ctx->vsp=local+12;
	w=(*ftab[15])(ctx,1,local+11,&ftab[15],fqv[92]); /*warn*/
	local[11]= argv[0];
	local[12]= fqv[308];
	local[13]= fqv[309];
	local[14]= fqv[310];
	local[15]= makeint((eusinteger_t)0L);
	local[16]= makeflt(5.0000000000000000000000e-01);
	local[17]= local[6];
	ctx->vsp=local+18;
	w=(pointer)TIMES(ctx,2,local+16); /***/
	local[16]= w;
	local[17]= makeint((eusinteger_t)0L);
	ctx->vsp=local+18;
	w=(pointer)MKFLTVEC(ctx,3,local+15); /*float-vector*/
	local[15]= w;
	local[16]= fqv[311];
	local[17]= local[8];
	local[18]= makeflt(5.0000000000000000000000e-01);
	local[19]= loadglobal(fqv[301]);
	ctx->vsp=local+20;
	w=(pointer)TIMES(ctx,3,local+17); /***/
	local[17]= w;
	local[18]= fqv[312];
	local[19]= local[9];
	local[20]= makeflt(5.0000000000000000000000e-01);
	local[21]= loadglobal(fqv[301]);
	ctx->vsp=local+22;
	w=(pointer)TIMES(ctx,3,local+19); /***/
	local[19]= w;
	local[20]= fqv[313];
	local[21]= local[10];
	local[22]= makeflt(5.0000000000000000000000e-01);
	local[23]= loadglobal(fqv[301]);
	ctx->vsp=local+24;
	w=(pointer)TIMES(ctx,3,local+21); /***/
	local[21]= w;
	ctx->vsp=local+22;
	w=(*ftab[10])(ctx,1,local+21,&ftab[10],fqv[67]); /*deg2rad*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)LIST(ctx,8,local+14); /*list*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,4,local+11); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	unbindx(ctx,1);
	w = local[4];
	local[0]= w;
BLK4619:
	ctx->vsp=local; return(local[0]);}

/*:footstep-parameter*/
static pointer M4630robot_model_footstep_parameter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[314];
	local[2]= fqv[309];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (w!=NIL) goto IF4632;
	local[0]= argv[0];
	local[1]= fqv[315];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF4633;
IF4632:
	local[0]= NIL;
IF4633:
	local[0]= argv[0];
	local[1]= fqv[314];
	local[2]= fqv[309];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK4631:
	ctx->vsp=local; return(local[0]);}

/*:go-pos-params->footstep-list*/
static pointer M4634robot_model_go_pos_params__footstep_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[316], &argv[5], n-5, local+0, 0);
	if (n & (1<<0)) goto KEY4636;
	local[6]= argv[0];
	local[7]= fqv[309];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[0] = w;
KEY4636:
	if (n & (1<<1)) goto KEY4637;
	local[6]= fqv[310];
	w = local[0];
	w=memq(local[6],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
KEY4637:
	if (n & (1<<2)) goto KEY4638;
	local[6]= fqv[311];
	w = local[0];
	w=memq(local[6],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
KEY4638:
	if (n & (1<<3)) goto KEY4639;
	local[6]= fqv[312];
	w = local[0];
	w=memq(local[6],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
KEY4639:
	if (n & (1<<4)) goto KEY4640;
	local[6]= fqv[313];
	w = local[0];
	w=memq(local[6],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(*ftab[40])(ctx,1,local+6,&ftab[40],fqv[317]); /*rad2deg*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ABS(ctx,1,local+6); /*abs*/
	local[4] = w;
KEY4640:
	if (n & (1<<5)) goto KEY4641;
	ctx->vsp=local+6;
	local[5] = makeclosure(codevec,quotevec,CLO4642,env,argv,local);
KEY4641:
	local[6]= argv[2];
	local[7]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+8;
	w=(pointer)GREATERP(ctx,2,local+6); /*>*/
	if (w==NIL) goto IF4643;
	local[6]= makeflt(1.0000000000000000000000e+00);
	goto IF4644;
IF4643:
	local[6]= makeflt(-1.0000000000000000000000e+00);
IF4644:
	local[7]= argv[3];
	local[8]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+9;
	w=(pointer)GREATERP(ctx,2,local+7); /*>*/
	if (w==NIL) goto IF4645;
	local[7]= makeflt(1.0000000000000000000000e+00);
	goto IF4646;
IF4645:
	local[7]= makeflt(-1.0000000000000000000000e+00);
IF4646:
	local[8]= argv[4];
	local[9]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+10;
	w=(pointer)GREATERP(ctx,2,local+8); /*>*/
	if (w==NIL) goto IF4647;
	local[8]= makeflt(1.0000000000000000000000e+00);
	goto IF4648;
IF4647:
	local[8]= makeflt(-1.0000000000000000000000e+00);
IF4648:
	local[9]= makeflt(0.0000000000000000000000e+00);
	local[10]= makeflt(0.0000000000000000000000e+00);
	local[11]= makeflt(0.0000000000000000000000e+00);
	local[12]= makeint((eusinteger_t)0L);
	local[13]= argv[3];
	ctx->vsp=local+14;
	w=(pointer)EUSFLOAT(ctx,1,local+13); /*float*/
	local[13]= w;
	local[14]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+15;
	w=(*ftab[41])(ctx,2,local+13,&ftab[41],fqv[318]); /*eps=*/
	if (w==NIL) goto IF4649;
	local[13]= argv[4];
	local[14]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+15;
	w=(pointer)GREATERP(ctx,2,local+13); /*>*/
	if (w==NIL) goto IF4651;
	local[13]= fqv[142];
	goto IF4652;
IF4651:
	local[13]= fqv[143];
IF4652:
	goto IF4650;
IF4649:
	local[13]= argv[3];
	local[14]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+15;
	w=(pointer)GREATERP(ctx,2,local+13); /*>*/
	if (w==NIL) goto IF4653;
	local[13]= fqv[142];
	goto IF4654;
IF4653:
	local[13]= fqv[143];
IF4654:
IF4650:
	local[14]= (pointer)get_sym_func(fqv[244]);
	local[15]= makeflt(5.0000000000000000000000e-01);
	local[16]= argv[0];
	local[17]= fqv[41];
	local[18]= fqv[43];
	local[19]= fqv[64];
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,4,local+16); /*send*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)APPLY(ctx,3,local+14); /*apply*/
	local[14]= w;
	ctx->vsp=local+15;
	local[15]= makeclosure(codevec,quotevec,CLO4655,env,argv,local);
	local[16]= fqv[319];
	ctx->vsp=local+17;
	w=(pointer)MAPCAR(ctx,2,local+15); /*mapcar*/
	local[15]= w;
	local[16]= local[5];
	local[17]= local[14];
	local[18]= local[13];
	local[19]= local[18];
	if (fqv[142]!=local[19]) goto IF4657;
	local[19]= fqv[143];
	goto IF4658;
IF4657:
	local[19]= local[18];
	if (fqv[143]!=local[19]) goto IF4659;
	local[19]= fqv[142];
	goto IF4660;
IF4659:
	local[19]= NIL;
IF4660:
IF4658:
	w = local[19];
	local[18]= w;
	local[19]= local[15];
	ctx->vsp=local+20;
	w=(pointer)FUNCALL(ctx,4,local+16); /*funcall*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	local[16]= w;
	ctx->vsp=local+17;
	local[17]= makeclosure(codevec,quotevec,FLET4661,env,argv,local);
	ctx->vsp=local+18;
	local[18]= makeclosure(codevec,quotevec,FLET4662,env,argv,local);
	local[19]= argv[2];
	local[20]= local[2];
	w = local[18];
	ctx->vsp=local+21;
	w=FLET4662(ctx,2,local+19,w);
	local[19]= w;
	local[20]= argv[3];
	local[21]= local[3];
	w = local[18];
	ctx->vsp=local+22;
	w=FLET4662(ctx,2,local+20,w);
	local[20]= w;
	local[21]= makeint((eusinteger_t)2L);
	ctx->vsp=local+22;
	w=(pointer)TIMES(ctx,2,local+20); /***/
	local[20]= w;
	local[21]= makeint((eusinteger_t)1L);
	ctx->vsp=local+22;
	w=(pointer)MINUS(ctx,2,local+20); /*-*/
	local[20]= w;
	local[21]= argv[4];
	local[22]= local[4];
	w = local[18];
	ctx->vsp=local+23;
	w=FLET4662(ctx,2,local+21,w);
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)MAX(ctx,3,local+19); /*max*/
	local[19]= w;
	ctx->vsp=local+20;
	local[20]= makeclosure(codevec,quotevec,CLO4663,env,argv,local);
	w = local[17];
	ctx->vsp=local+21;
	w=FLET4661(ctx,2,local+19,w);
	local[19]= local[5];
	local[20]= local[14];
	local[21]= local[13];
	local[22]= local[15];
	ctx->vsp=local+23;
	w=(pointer)FUNCALL(ctx,4,local+19); /*funcall*/
	local[19]= w;
	w = local[16];
	ctx->vsp=local+20;
	local[16] = cons(ctx,local[19],w);
	local[19]= local[16];
	ctx->vsp=local+20;
	w=(pointer)REVERSE(ctx,1,local+19); /*reverse*/
	local[0]= w;
BLK4635:
	ctx->vsp=local; return(local[0]);}

/*:go-pos-quadruped-params->footstep-list*/
static pointer M4664robot_model_go_pos_quadruped_params__footstep_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[320], &argv[5], n-5, local+0, 0);
	if (n & (1<<0)) goto KEY4666;
	local[0] = fqv[321];
KEY4666:
	local[1]= argv[0];
	local[2]= fqv[322];
	local[3]= argv[2];
	local[4]= argv[3];
	local[5]= argv[4];
	local[6]= fqv[311];
	local[7]= makeint((eusinteger_t)100L);
	local[8]= fqv[313];
	local[9]= makeint((eusinteger_t)3L);
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,9,local+1); /*send*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= local[1];
WHL4668:
	if (local[4]==NIL) goto WHX4669;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3];
	local[6]= fqv[36];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= argv[0];
	local[7]= local[5];
	local[8]= fqv[43];
	local[9]= fqv[64];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[6]= w;
	local[7]= fqv[250];
	local[8]= local[3];
	local[9]= fqv[20];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[6]= w;
	local[7]= NIL;
	local[8]= local[0];
	local[9]= local[8];
	if (fqv[321]!=local[9]) goto IF4673;
	local[9]= NIL;
	local[10]= local[5];
	local[11]= local[5];
	local[12]= local[11];
	if (fqv[142]!=local[12]) goto IF4677;
	local[12]= fqv[140];
	goto IF4678;
IF4677:
	local[12]= local[11];
	if (fqv[143]!=local[12]) goto IF4679;
	local[12]= fqv[141];
	goto IF4680;
IF4679:
	local[12]= NIL;
IF4680:
IF4678:
	w = local[12];
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,2,local+10); /*list*/
	local[10]= w;
WHL4681:
	if (local[10]==NIL) goto WHX4682;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	local[11]= fqv[323];
	local[12]= argv[0];
	local[13]= local[9];
	local[14]= fqv[43];
	local[15]= fqv[64];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,4,local+12); /*send*/
	local[12]= w;
	local[13]= fqv[21];
	local[14]= local[6];
	local[15]= fqv[20];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,4,local+12); /*send*/
	local[12]= w;
	local[13]= fqv[36];
	local[14]= local[9];
	ctx->vsp=local+15;
	w=(*ftab[16])(ctx,4,local+11,&ftab[16],fqv[96]); /*make-coords*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	local[11]= w;
	w = local[2];
	ctx->vsp=local+12;
	local[2] = cons(ctx,local[11],w);
	goto WHL4681;
WHX4682:
	local[11]= NIL;
BLK4683:
	w = NIL;
	local[9]= w;
	goto IF4674;
IF4673:
	local[9]= local[8];
	if (fqv[324]!=local[9]) goto IF4685;
	ctx->vsp=local+9;
	local[9]= makeclosure(codevec,quotevec,CLO4687,env,argv,local);
	local[10]= local[5];
	local[11]= local[5];
	local[12]= local[11];
	if (fqv[142]!=local[12]) goto IF4689;
	local[12]= fqv[141];
	goto IF4690;
IF4689:
	local[12]= local[11];
	if (fqv[143]!=local[12]) goto IF4691;
	local[12]= fqv[140];
	goto IF4692;
IF4691:
	local[12]= NIL;
IF4692:
IF4690:
	w = local[12];
	local[7] = w;
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,2,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)MAPCAR(ctx,2,local+9); /*mapcar*/
	local[9]= w;
	w = local[2];
	ctx->vsp=local+10;
	local[2] = cons(ctx,local[9],w);
	local[9]= local[2];
	goto IF4686;
IF4685:
	local[9]= local[8];
	if (fqv[325]!=local[9]) goto IF4693;
	ctx->vsp=local+9;
	local[9]= makeclosure(codevec,quotevec,CLO4695,env,argv,local);
	local[10]= local[5];
	local[11]= local[5];
	local[12]= local[11];
	if (fqv[142]!=local[12]) goto IF4697;
	local[12]= fqv[140];
	goto IF4698;
IF4697:
	local[12]= local[11];
	if (fqv[143]!=local[12]) goto IF4699;
	local[12]= fqv[141];
	goto IF4700;
IF4699:
	local[12]= NIL;
IF4700:
IF4698:
	w = local[12];
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,2,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)MAPCAR(ctx,2,local+9); /*mapcar*/
	local[9]= w;
	w = local[2];
	ctx->vsp=local+10;
	local[2] = cons(ctx,local[9],w);
	local[9]= local[2];
	goto IF4694;
IF4693:
	local[9]= local[8];
	if (fqv[326]!=local[9]) goto IF4701;
	ctx->vsp=local+9;
	local[9]= makeclosure(codevec,quotevec,CLO4703,env,argv,local);
	local[10]= local[5];
	local[11]= local[10];
	if (fqv[143]!=local[11]) goto IF4705;
	local[11]= fqv[143];
	goto IF4706;
IF4705:
	local[11]= local[10];
	if (fqv[142]!=local[11]) goto IF4707;
	local[11]= fqv[141];
	goto IF4708;
IF4707:
	local[11]= NIL;
IF4708:
IF4706:
	w = local[11];
	local[10]= w;
	local[11]= local[5];
	local[12]= local[11];
	if (fqv[143]!=local[12]) goto IF4710;
	local[12]= fqv[142];
	goto IF4711;
IF4710:
	local[12]= local[11];
	if (fqv[142]!=local[12]) goto IF4712;
	local[12]= fqv[140];
	goto IF4713;
IF4712:
	local[12]= NIL;
IF4713:
IF4711:
	w = local[12];
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,2,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)MAPCAR(ctx,2,local+9); /*mapcar*/
	local[9]= w;
	w = local[2];
	ctx->vsp=local+10;
	local[2] = cons(ctx,local[9],w);
	local[9]= local[2];
	goto IF4702;
IF4701:
	local[9]= NIL;
IF4702:
IF4694:
IF4686:
IF4674:
	w = local[9];
	goto WHL4668;
WHX4669:
	local[5]= NIL;
BLK4670:
	w = NIL;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)REVERSE(ctx,1,local+3); /*reverse*/
	local[0]= w;
BLK4665:
	ctx->vsp=local; return(local[0]);}

/*:support-polygons*/
static pointer M4714robot_model_support_polygons(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[36];
	local[1]= fqv[327];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,2,local+0,&ftab[13],fqv[80]); /*send-all*/
	local[0]= w;
	local[1]= fqv[252];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,2,local+0,&ftab[13],fqv[80]); /*send-all*/
	w = argv[0]->c.obj.iv[36];
	local[0]= w;
BLK4715:
	ctx->vsp=local; return(local[0]);}

/*:support-polygon*/
static pointer M4716robot_model_support_polygon(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	if (!iscons(w)) goto IF4718;
	local[0]= loadglobal(fqv[328]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[34];
	local[3]= fqv[329];
	local[4]= (pointer)get_sym_func(fqv[330]);
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO4721,env,argv,local);
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)MAPCAR(ctx,2,local+5); /*mapcar*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,2,local+4); /*apply*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[42])(ctx,1,local+4,&ftab[42],fqv[331]); /*quickhull*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
	goto IF4719;
IF4718:
	local[0]= argv[2];
	local[1]= argv[0];
	local[2]= fqv[332];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[135];
	local[3]= (pointer)get_sym_func(fqv[136]);
	local[4]= fqv[137];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO4722,env,argv,local);
	ctx->vsp=local+6;
	w=(*ftab[21])(ctx,6,local+0,&ftab[21],fqv[138]); /*find*/
	local[0]= w;
IF4719:
	w = local[0];
	local[0]= w;
BLK4717:
	ctx->vsp=local; return(local[0]);}

/*:make-support-polygons*/
static pointer M4723robot_model_make_support_polygons(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[333];
	local[3]= fqv[143];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[333];
	local[4]= fqv[142];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,2,local+0,&ftab[7],fqv[45]); /*remove*/
	argv[0]->c.obj.iv[36] = w;
	w = argv[0]->c.obj.iv[36];
	local[0]= w;
BLK4724:
	ctx->vsp=local; return(local[0]);}

/*:make-sole-polygon*/
static pointer M4725robot_model_make_sole_polygon(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,FLET4727,env,argv,local);
	local[1]= argv[0];
	local[2]= argv[2];
	local[3]= fqv[71];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	if (w!=NIL) goto IF4728;
	w = NIL;
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK4726;
	goto IF4729;
IF4728:
	local[1]= NIL;
IF4729:
	local[1]= argv[0];
	local[2]= argv[2];
	local[3]= fqv[71];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w = local[0];
	ctx->vsp=local+2;
	w=FLET4727(ctx,1,local+1,w);
	local[1]= w;
	local[2]= fqv[252];
	ctx->vsp=local+3;
	w=(*ftab[13])(ctx,2,local+1,&ftab[13],fqv[80]); /*send-all*/
	local[1]= NIL;
	local[2]= fqv[334];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[8])(ctx,1,local+1,&ftab[8],fqv[47]); /*read-from-string*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= argv[2];
	local[4]= fqv[71];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w = local[0];
	ctx->vsp=local+3;
	w=FLET4727(ctx,1,local+2,w);
	local[2]= w;
	local[3]= fqv[35];
	ctx->vsp=local+4;
	w=(*ftab[13])(ctx,2,local+2,&ftab[13],fqv[80]); /*send-all*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[43])(ctx,1,local+2,&ftab[43],fqv[335]); /*flatten*/
	local[2]= w;
	local[3]= fqv[329];
	ctx->vsp=local+4;
	w=(*ftab[13])(ctx,2,local+2,&ftab[13],fqv[80]); /*send-all*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[43])(ctx,1,local+2,&ftab[43],fqv[335]); /*flatten*/
	local[2]= w;
	local[3]= fqv[135];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO4730,env,argv,local);
	ctx->vsp=local+5;
	w=(*ftab[33])(ctx,3,local+2,&ftab[33],fqv[222]); /*remove-duplicates*/
	local[2]= w;
	local[3]= local[2];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO4731,env,argv,local);
	local[5]= (pointer)get_sym_func(fqv[336]);
	ctx->vsp=local+6;
	w=(*ftab[44])(ctx,3,local+3,&ftab[44],fqv[337]); /*find-extream*/
	local[3]= w;
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO4732,env,argv,local);
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,2,local+4,&ftab[4],fqv[28]); /*remove-if*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[45])(ctx,1,local+4,&ftab[45],fqv[338]); /*make-bounding-box*/
	local[4]= w;
	local[5]= fqv[327];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= argv[2];
	local[7]= fqv[43];
	local[8]= fqv[56];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	local[6]= fqv[24];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[308];
	local[7]= local[1];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= local[4];
	local[6]= fqv[252];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO4733,env,argv,local);
	local[6]= local[4];
	local[7]= fqv[339];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[36])(ctx,2,local+5,&ftab[36],fqv[235]); /*find-if*/
	local[5]= w;
	local[6]= local[5];
	local[7]= fqv[36];
	local[8]= argv[2];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	w = local[5];
	local[0]= w;
BLK4726:
	ctx->vsp=local; return(local[0]);}

/*:make-default-linear-link-joint-between-attach-coords*/
static pointer M4734robot_model_make_default_linear_link_joint_between_attach_coords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[3];
	local[7]= fqv[97];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= argv[2];
	local[8]= fqv[97];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)VDISTANCE(ctx,2,local+6); /*distance*/
	local[6]= w;
	local[7]= loadglobal(fqv[33]);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,1,local+7); /*instantiate*/
	local[7]= w;
	local[8]= local[7];
	local[9]= fqv[34];
	ctx->vsp=local+10;
	w=(*ftab[2])(ctx,0,local+10,&ftab[2],fqv[2]); /*make-cascoords*/
	local[10]= w;
	local[11]= fqv[35];
	local[12]= makeint((eusinteger_t)5L);
	local[13]= makeflt(5.0000000000000000000000e-01);
	local[14]= local[6];
	ctx->vsp=local+15;
	w=(pointer)TIMES(ctx,2,local+13); /***/
	local[13]= w;
	ctx->vsp=local+14;
	w=(*ftab[0])(ctx,2,local+12,&ftab[0],fqv[0]); /*make-cylinder*/
	local[12]= w;
	local[13]= local[12];
	local[14]= fqv[25];
	local[15]= fqv[26];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	w = local[12];
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,5,local+8); /*send*/
	w = local[7];
	local[0] = w;
	local[7]= local[0];
	local[8]= fqv[251];
	local[9]= argv[2];
	local[10]= fqv[64];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= local[0];
	local[8]= argv[3];
	local[9]= fqv[97];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= argv[2];
	local[10]= fqv[97];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)VMINUS(ctx,2,local+8); /*v-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[46])(ctx,1,local+8,&ftab[46],fqv[340]); /*normalize-vector*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[17])(ctx,2,local+7,&ftab[17],fqv[98]); /*orient-coords-to-axis*/
	local[7]= loadglobal(fqv[33]);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,1,local+7); /*instantiate*/
	local[7]= w;
	local[8]= local[7];
	local[9]= fqv[34];
	ctx->vsp=local+10;
	w=(*ftab[2])(ctx,0,local+10,&ftab[2],fqv[2]); /*make-cascoords*/
	local[10]= w;
	local[11]= fqv[35];
	local[12]= makeint((eusinteger_t)5L);
	local[13]= makeflt(5.0000000000000000000000e-01);
	local[14]= local[6];
	ctx->vsp=local+15;
	w=(pointer)TIMES(ctx,2,local+13); /***/
	local[13]= w;
	ctx->vsp=local+14;
	w=(*ftab[0])(ctx,2,local+12,&ftab[0],fqv[0]); /*make-cylinder*/
	local[12]= w;
	local[13]= local[12];
	local[14]= fqv[25];
	local[15]= fqv[26];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= local[12];
	local[14]= fqv[22];
	local[15]= makeint((eusinteger_t)0L);
	local[16]= makeint((eusinteger_t)0L);
	local[17]= makeflt(-5.0000000000000000000000e-01);
	local[18]= local[6];
	ctx->vsp=local+19;
	w=(pointer)TIMES(ctx,2,local+17); /***/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)MKFLTVEC(ctx,3,local+15); /*float-vector*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	w = local[12];
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,5,local+8); /*send*/
	w = local[7];
	local[1] = w;
	local[7]= local[1];
	local[8]= fqv[251];
	local[9]= argv[3];
	local[10]= fqv[64];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= local[1];
	local[8]= argv[3];
	local[9]= fqv[97];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= argv[2];
	local[10]= fqv[97];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)VMINUS(ctx,2,local+8); /*v-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[46])(ctx,1,local+8,&ftab[46],fqv[340]); /*normalize-vector*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[17])(ctx,2,local+7,&ftab[17],fqv[98]); /*orient-coords-to-axis*/
	local[7]= loadglobal(fqv[33]);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,1,local+7); /*instantiate*/
	local[7]= w;
	local[8]= local[7];
	local[9]= fqv[34];
	ctx->vsp=local+10;
	w=(*ftab[2])(ctx,0,local+10,&ftab[2],fqv[2]); /*make-cascoords*/
	local[10]= w;
	local[11]= fqv[35];
	local[12]= makeint((eusinteger_t)5L);
	local[13]= makeint((eusinteger_t)5L);
	local[14]= makeint((eusinteger_t)5L);
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,3,local+12,&ftab[1],fqv[1]); /*make-cube*/
	local[12]= w;
	local[13]= local[12];
	local[14]= fqv[25];
	local[15]= fqv[26];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	w = local[12];
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,5,local+8); /*send*/
	w = local[7];
	local[2] = w;
	local[7]= local[2];
	local[8]= fqv[251];
	local[9]= argv[3];
	local[10]= fqv[64];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= fqv[323];
	local[8]= argv[3];
	local[9]= fqv[64];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= fqv[36];
	local[10]= argv[4];
	ctx->vsp=local+11;
	w=(*ftab[2])(ctx,4,local+7,&ftab[2],fqv[2]); /*make-cascoords*/
	local[7]= w;
	w = argv[0]->c.obj.iv[12];
	ctx->vsp=local+8;
	argv[0]->c.obj.iv[12] = cons(ctx,local[7],w);
	local[7]= argv[2];
	local[8]= fqv[56];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= fqv[24];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= local[0];
	local[8]= fqv[24];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= local[1];
	local[8]= fqv[24];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= local[2];
	local[8]= fqv[24];
	w=argv[0]->c.obj.iv[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= local[1];
	local[8]= fqv[22];
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)0L);
	local[11]= makeint((eusinteger_t)-1L);
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)MKFLTVEC(ctx,3,local+9); /*float-vector*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= loadglobal(fqv[341]);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,1,local+7); /*instantiate*/
	local[7]= w;
	local[8]= local[7];
	local[9]= fqv[34];
	local[10]= fqv[107];
	local[11]= local[0];
	local[12]= fqv[56];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	local[12]= fqv[192];
	local[13]= local[0];
	local[14]= fqv[185];
	local[15]= makeint((eusinteger_t)-360L);
	local[16]= makeint((eusinteger_t)-360L);
	local[17]= makeint((eusinteger_t)-360L);
	ctx->vsp=local+18;
	w=(pointer)MKFLTVEC(ctx,3,local+15); /*float-vector*/
	local[15]= w;
	local[16]= fqv[186];
	local[17]= makeint((eusinteger_t)360L);
	local[18]= makeint((eusinteger_t)360L);
	local[19]= makeint((eusinteger_t)360L);
	ctx->vsp=local+20;
	w=(pointer)MKFLTVEC(ctx,3,local+17); /*float-vector*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,10,local+8); /*send*/
	w = local[7];
	local[3] = w;
	local[7]= loadglobal(fqv[342]);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,1,local+7); /*instantiate*/
	local[7]= w;
	local[8]= local[7];
	local[9]= fqv[34];
	local[10]= fqv[107];
	local[11]= local[1];
	local[12]= fqv[56];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	local[12]= fqv[192];
	local[13]= local[1];
	local[14]= fqv[36];
	local[15]= argv[5];
	local[16]= fqv[343];
	local[17]= fqv[7];
	local[18]= fqv[185];
	local[19]= makeint((eusinteger_t)0L);
	local[20]= fqv[186];
	local[21]= makeint((eusinteger_t)1000L);
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,14,local+8); /*send*/
	w = local[7];
	local[4] = w;
	local[7]= loadglobal(fqv[341]);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,1,local+7); /*instantiate*/
	local[7]= w;
	local[8]= local[7];
	local[9]= fqv[34];
	local[10]= fqv[107];
	local[11]= local[2];
	local[12]= fqv[56];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	local[12]= fqv[192];
	local[13]= local[2];
	local[14]= fqv[185];
	local[15]= makeint((eusinteger_t)-360L);
	local[16]= makeint((eusinteger_t)-360L);
	local[17]= makeint((eusinteger_t)-360L);
	ctx->vsp=local+18;
	w=(pointer)MKFLTVEC(ctx,3,local+15); /*float-vector*/
	local[15]= w;
	local[16]= fqv[186];
	local[17]= makeint((eusinteger_t)360L);
	local[18]= makeint((eusinteger_t)360L);
	local[19]= makeint((eusinteger_t)360L);
	ctx->vsp=local+20;
	w=(pointer)MKFLTVEC(ctx,3,local+17); /*float-vector*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,10,local+8); /*send*/
	w = local[7];
	local[5] = w;
	local[7]= local[4];
	local[8]= fqv[129];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= argv[0]->c.obj.iv[8];
	local[8]= local[0];
	local[9]= local[1];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,3,local+8); /*list*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)APPEND(ctx,2,local+7); /*append*/
	argv[0]->c.obj.iv[8] = w;
	local[7]= argv[0]->c.obj.iv[9];
	local[8]= local[3];
	local[9]= local[4];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,3,local+8); /*list*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)APPEND(ctx,2,local+7); /*append*/
	argv[0]->c.obj.iv[9] = w;
	w = argv[0]->c.obj.iv[9];
	local[0]= w;
BLK4735:
	ctx->vsp=local; return(local[0]);}

/*:calc-static-balance-point*/
static pointer M4742robot_model_calc_static_balance_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[344], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY4744;
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO4745,env,argv,local);
	local[6]= fqv[345];
	ctx->vsp=local+7;
	w=(pointer)MAPCAR(ctx,2,local+5); /*mapcar*/
	local[0] = w;
KEY4744:
	if (n & (1<<1)) goto KEY4746;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	local[6]= fqv[205];
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,3,local+7); /*float-vector*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[28])(ctx,3,local+5,&ftab[28],fqv[206]); /*make-list*/
	local[1] = w;
KEY4746:
	if (n & (1<<2)) goto KEY4747;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	local[6]= fqv[205];
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,3,local+7); /*float-vector*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[28])(ctx,3,local+5,&ftab[28],fqv[206]); /*make-list*/
	local[2] = w;
KEY4747:
	if (n & (1<<3)) goto KEY4748;
	local[5]= (pointer)get_sym_func(fqv[183]);
	local[6]= makeflt(5.0000000000000000000000e-01);
	local[7]= argv[0];
	local[8]= fqv[41];
	local[9]= fqv[43];
	local[10]= fqv[97];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,3,local+5); /*apply*/
	local[5]= w;
	local[6]= makeint((eusinteger_t)2L);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[3] = w;
KEY4748:
	if (n & (1<<4)) goto KEY4749;
	local[4] = T;
KEY4749:
	local[5]= makeint((eusinteger_t)0L);
	local[6]= makeint((eusinteger_t)0L);
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[5]= w;
	local[6]= makeflt(9.9999999999999974298988e-07);
	local[7]= argv[0];
	local[8]= fqv[121];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	local[8]= loadglobal(fqv[346]);
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,3,local+6); /***/
	local[6]= w;
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)2L);
WHL4751:
	local[9]= local[7];
	w = local[8];
	if ((eusinteger_t)local[9] >= (eusinteger_t)w) goto WHX4752;
	local[9]= local[6];
	local[10]= local[6];
	local[11]= argv[0];
	local[12]= fqv[29];
	local[13]= NIL;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[11]= w;
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	local[11]= makeclosure(codevec,quotevec,CLO4754,env,argv,local);
	local[12]= local[1];
	local[13]= local[2];
	local[14]= local[0];
	ctx->vsp=local+15;
	w=(pointer)MAPCAR(ctx,4,local+11); /*mapcar*/
	local[11]= local[5];
	local[12]= local[7];
	local[13]= local[10];
	local[14]= local[9];
	ctx->vsp=local+15;
	w=(pointer)QUOTIENT(ctx,2,local+13); /*/*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SETELT(ctx,3,local+11); /*setelt*/
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	local[7] = w;
	goto WHL4751;
WHX4752:
	local[9]= NIL;
BLK4753:
	w = NIL;
	w = local[5];
	local[0]= w;
BLK4743:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4544(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = fqv[347];
	if (memq(local[0],w)==NIL) goto IF4755;
	local[0]= makeint((eusinteger_t)1L);
	goto IF4756;
IF4755:
	local[0]= makeint((eusinteger_t)5L);
IF4756:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4546(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = fqv[348];
	if (memq(local[0],w)==NIL) goto IF4757;
	local[0]= makeint((eusinteger_t)1L);
	goto IF4758;
IF4757:
	local[0]= makeint((eusinteger_t)5L);
IF4758:
	ctx->vsp=local+1;
	w=(*ftab[10])(ctx,1,local+0,&ftab[10],fqv[67]); /*deg2rad*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4551(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= argv[0];
	local[2]= fqv[43];
	local[3]= fqv[97];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4552(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = fqv[349];
	w = memq(local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4554(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= argv[0];
	local[2]= fqv[43];
	local[3]= fqv[64];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4567(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env2[7];
	local[1]= argv[0];
	local[2]= fqv[43];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4568(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env2[7];
	local[1]= fqv[55];
	local[2]= argv[0];
	local[3]= fqv[56];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4569(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = fqv[350];
	w = memq(local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4580(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO4759,env,argv,local);
	local[1]= fqv[351];
	ctx->vsp=local+2;
	w=(*ftab[36])(ctx,2,local+0,&ftab[36],fqv[235]); /*find-if*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4759(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= env->c.clo.env0->c.clo.env1[0];
	local[2]= argv[0];
	local[3]= fqv[86];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)EQUAL(ctx,2,local+0); /*equal*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4582(ctx,n,argv,env)
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
static pointer CLO4584(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= fqv[352];
	local[2]= fqv[245];
	local[3]= fqv[353];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4605(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= argv[0];
	local[2]= fqv[43];
	local[3]= fqv[64];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET4610(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[287]);
	local[1]= fqv[299];
	local[2]= fqv[292];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= loadglobal(fqv[287]);
	local[2]= fqv[299];
	local[3]= fqv[292];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)FUNCALL(ctx,1,local+1); /*funcall*/
	local[1]= loadglobal(fqv[287]);
	local[2]= fqv[299];
	local[3]= fqv[292];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4611(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[290];
	local[2]= fqv[289];
	local[3]= NIL;
	local[4]= fqv[291];
	local[5]= makeint((eusinteger_t)300L);
	local[6]= fqv[292];
	local[7]= fqv[354];
	if (argv[1]!=local[7]) goto IF4760;
	local[7]= fqv[355];
	goto IF4761;
IF4760:
	local[7]= fqv[356];
IF4761:
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,8,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4614(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= loadglobal(fqv[287]);
	local[1]= fqv[299];
	local[2]= fqv[357];
	local[3]= makeint((eusinteger_t)20L);
	local[4]= makeint((eusinteger_t)20L);
	local[5]= fqv[358];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4615(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= loadglobal(fqv[287]);
	local[1]= fqv[299];
	local[2]= fqv[357];
	local[3]= makeint((eusinteger_t)20L);
	local[4]= makeint((eusinteger_t)50L);
	local[5]= fqv[359];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4616(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= loadglobal(fqv[287]);
	local[1]= fqv[299];
	local[2]= fqv[357];
	local[3]= makeint((eusinteger_t)20L);
	local[4]= makeint((eusinteger_t)80L);
	local[5]= fqv[360];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4617(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= loadglobal(fqv[287]);
	local[1]= fqv[299];
	local[2]= fqv[357];
	local[3]= makeint((eusinteger_t)20L);
	local[4]= makeint((eusinteger_t)110L);
	local[5]= fqv[361];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET4622(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4763;}
	local[0]= NIL;
ENT4763:
ENT4762:
	if (n>3) maerror();
	local[1]= env->c.clo.env1[0];
	local[2]= fqv[303];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= env->c.clo.env1[0];
	local[2]= fqv[304];
	ctx->vsp=local+3;
	w=(*ftab[16])(ctx,0,local+3,&ftab[16],fqv[96]); /*make-coords*/
	local[3]= w;
	local[4]= fqv[362];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= env->c.clo.env1[0];
	local[2]= fqv[143];
	local[3]= fqv[43];
	local[4]= fqv[64];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[64];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
WHL4764:
	local[3]= env->c.clo.env1[0];
	local[4]= fqv[54];
	local[5]= argv[0];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)FUNCALL(ctx,2,local+5); /*funcall*/
	local[5]= w;
	local[6]= fqv[55];
	local[7]= env->c.clo.env1[0];
	local[8]= fqv[55];
	local[9]= env->c.clo.env1[0];
	local[10]= fqv[143];
	local[11]= fqv[43];
	local[12]= fqv[56];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,4,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	local[8]= fqv[61];
	local[9]= env->c.clo.env1[0];
	local[10]= fqv[143];
	local[11]= fqv[43];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= w;
	local[10]= fqv[94];
	local[11]= NIL;
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,9,local+3); /*send*/
	if (w==NIL) goto WHX4765;
	if (local[0]==NIL) goto IF4767;
	local[3]= local[0];
	local[4]= local[1];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)FUNCALL(ctx,3,local+3); /*funcall*/
	local[3]= w;
	goto IF4768;
IF4767:
	local[3]= T;
IF4768:
	if (local[3]==NIL) goto WHX4765;
	goto WHL4764;
WHX4765:
	local[3]= NIL;
BLK4766:
	local[3]= argv[1];
	local[4]= local[1];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)FUNCALL(ctx,3,local+3); /*funcall*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4623(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[22];
	local[2]= fqv[363];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4624(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[97];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[1];
	local[2]= fqv[97];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)ABS(ctx,1,local+0); /*abs*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4625(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[22];
	local[2]= fqv[364];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4626(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[97];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[1];
	local[2]= fqv[97];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)ABS(ctx,1,local+0); /*abs*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4627(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[66];
	local[2]= makeflt(-2.5000000000000000000000e+00);
	ctx->vsp=local+3;
	w=(*ftab[10])(ctx,1,local+2,&ftab[10],fqv[67]); /*deg2rad*/
	local[2]= w;
	local[3]= fqv[7];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4628(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[365];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= argv[1];
	local[2]= fqv[365];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[40])(ctx,1,local+0,&ftab[40],fqv[317]); /*rad2deg*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)ABS(ctx,1,local+0); /*abs*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4629(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint((eusinteger_t)90L);
	local[1]= argv[0];
	local[2]= fqv[365];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[1];
	local[3]= fqv[365];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[40])(ctx,1,local+1,&ftab[40],fqv[317]); /*rad2deg*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)ABS(ctx,1,local+1); /*abs*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4642(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[64];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[22];
	local[2]= argv[1];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(*ftab[12])(ctx,2,local+2,&ftab[12],fqv[76]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[36];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4655(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= argv[0];
	local[2]= local[1];
	if (fqv[143]!=local[2]) goto IF4770;
	local[2]= makeint((eusinteger_t)-1L);
	goto IF4771;
IF4770:
	local[2]= local[1];
	if (fqv[142]!=local[2]) goto IF4772;
	local[2]= makeint((eusinteger_t)1L);
	goto IF4773;
IF4772:
	local[2]= NIL;
IF4773:
IF4771:
	w = local[2];
	local[1]= w;
	local[2]= env->c.clo.env2[1];
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,2,local+1); /*scale*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET4661(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	env->c.clo.env2[12] = makeint((eusinteger_t)0L);
	local[0]= makeint((eusinteger_t)0L);
	local[1]= argv[0];
WHL4775:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX4776;
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)FUNCALL(ctx,1,local+2); /*funcall*/
	local[2]= env->c.clo.env2[5];
	local[3]= env->c.clo.env2[14];
	local[4]= env->c.clo.env2[13];
	local[5]= env->c.clo.env2[15];
	ctx->vsp=local+6;
	w=(pointer)FUNCALL(ctx,4,local+2); /*funcall*/
	local[2]= w;
	w = env->c.clo.env2[16];
	ctx->vsp=local+3;
	env->c.clo.env2[16] = cons(ctx,local[2],w);
	local[2]= env->c.clo.env2[13];
	local[3]= local[2];
	if (fqv[142]!=local[3]) goto IF4779;
	local[3]= fqv[143];
	goto IF4780;
IF4779:
	local[3]= local[2];
	if (fqv[143]!=local[3]) goto IF4781;
	local[3]= fqv[142];
	goto IF4782;
IF4781:
	local[3]= NIL;
IF4782:
IF4780:
	w = local[3];
	env->c.clo.env2[13] = w;
	local[2]= env->c.clo.env2[12];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	env->c.clo.env2[12] = w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL4775;
WHX4776:
	local[2]= NIL;
BLK4777:
	w = NIL;
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET4662(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)ABS(ctx,1,local+0); /*abs*/
	local[0]= w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
	local[1]= makeflt(9.9999999999999991239646e-06);
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)FLOOR(ctx,1,local+0); /*floor*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)ROUND(ctx,1,local+0); /*round*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4663(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[2];
	local[1]= env->c.clo.env2[9];
	local[2]= env->c.clo.env1[2];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)ABS(ctx,1,local+1); /*abs*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF4783;
	local[0]= env->c.clo.env1[2];
	local[1]= env->c.clo.env2[9];
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	local[0]= w;
	goto IF4784;
IF4783:
	local[0]= env->c.clo.env2[2];
	local[1]= env->c.clo.env2[6];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
IF4784:
	local[1]= env->c.clo.env2[12];
	ctx->vsp=local+2;
	w=(*ftab[47])(ctx,1,local+1,&ftab[47],fqv[366]); /*oddp*/
	if (w==NIL) goto CON4786;
	local[1]= makeflt(0.0000000000000000000000e+00);
	goto CON4785;
CON4786:
	local[1]= env->c.clo.env2[3];
	local[2]= env->c.clo.env2[10];
	local[3]= env->c.clo.env1[3];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ABS(ctx,1,local+2); /*abs*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)GREATERP(ctx,2,local+1); /*>*/
	if (w==NIL) goto CON4787;
	local[1]= env->c.clo.env1[3];
	local[2]= env->c.clo.env2[10];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	goto CON4785;
CON4787:
	local[1]= env->c.clo.env2[3];
	local[2]= env->c.clo.env2[7];
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	goto CON4785;
CON4788:
	local[1]= NIL;
CON4785:
	local[2]= env->c.clo.env2[4];
	local[3]= env->c.clo.env2[11];
	local[4]= env->c.clo.env1[4];
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ABS(ctx,1,local+3); /*abs*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto CON4790;
	local[2]= env->c.clo.env1[4];
	local[3]= env->c.clo.env2[11];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	goto CON4789;
CON4790:
	local[2]= env->c.clo.env2[4];
	local[3]= env->c.clo.env2[8];
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	goto CON4789;
CON4791:
	local[2]= NIL;
CON4789:
	local[3]= env->c.clo.env2[14];
	local[4]= fqv[22];
	local[5]= local[0];
	local[6]= local[1];
	local[7]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= env->c.clo.env2[14];
	local[4]= fqv[66];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(*ftab[10])(ctx,1,local+5,&ftab[10],fqv[67]); /*deg2rad*/
	local[5]= w;
	local[6]= fqv[7];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= env->c.clo.env2[9];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	env->c.clo.env2[9] = w;
	local[3]= env->c.clo.env2[10];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	env->c.clo.env2[10] = w;
	local[3]= env->c.clo.env2[11];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	env->c.clo.env2[11] = w;
	w = env->c.clo.env2[11];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4687(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[323];
	local[1]= env->c.clo.env1[0];
	local[2]= argv[0];
	local[3]= fqv[43];
	local[4]= fqv[64];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[21];
	local[3]= env->c.clo.env2[6];
	local[4]= fqv[20];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[36];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,4,local+0,&ftab[16],fqv[96]); /*make-coords*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4695(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[323];
	local[1]= env->c.clo.env1[0];
	local[2]= argv[0];
	local[3]= fqv[43];
	local[4]= fqv[64];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[21];
	local[3]= env->c.clo.env2[6];
	local[4]= fqv[20];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[36];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,4,local+0,&ftab[16],fqv[96]); /*make-coords*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4703(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[323];
	local[1]= env->c.clo.env1[0];
	local[2]= argv[0];
	local[3]= fqv[43];
	local[4]= fqv[64];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[21];
	local[3]= env->c.clo.env2[6];
	local[4]= fqv[20];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[36];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,4,local+0,&ftab[16],fqv[96]); /*make-coords*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4721(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= fqv[367];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[329];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4722(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[36];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET4727(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	if (argv[0]==NIL) goto IF4792;
	local[0]= argv[0];
	local[1]= fqv[368];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	if (w==NIL) goto IF4792;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	local[1]= env->c.clo.env2[0];
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO4794,env,argv,local);
	local[3]= argv[0];
	local[4]= fqv[368];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[22])(ctx,2,local+2,&ftab[22],fqv[139]); /*remove-if-not*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[43])(ctx,1,local+1,&ftab[43],fqv[335]); /*flatten*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	local[0]= w;
	goto IF4793;
IF4792:
	local[0]= NIL;
IF4793:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4794(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[33]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4730(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= loadglobal(fqv[369]);
	ctx->vsp=local+3;
	w=(*ftab[48])(ctx,3,local+0,&ftab[48],fqv[370]); /*eps-v=*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4731(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)2L);
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4732(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeflt(5.0000000000000000000000e+00);
	local[1]= argv[0];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= env->c.clo.env2[3];
	local[3]= makeint((eusinteger_t)2L);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4733(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[371];
	local[1]= argv[0];
	local[2]= fqv[372];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = memq(local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4745(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= argv[0];
	local[2]= fqv[43];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[97];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4754(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= env->c.clo.env2[10];
	local[1]= argv[2];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= env->c.clo.env2[3];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= env->c.clo.env2[7];
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	local[2]= argv[2];
	local[3]= env->c.clo.env2[7];
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= makeint((eusinteger_t)2L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	local[2]= env->c.clo.env2[7];
	local[3]= local[2];
	if (fqv[373]!=local[3]) goto IF4796;
	local[3]= argv[1];
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,1,local+3); /*-*/
	local[3]= w;
	goto IF4797;
IF4796:
	local[3]= local[2];
	if (fqv[374]!=local[3]) goto IF4798;
	local[3]= argv[1];
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	goto IF4799;
IF4798:
	local[3]= NIL;
IF4799:
IF4797:
	w = local[3];
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,3,local+0); /*+*/
	env->c.clo.env2[10] = w;
	local[0]= env->c.clo.env2[9];
	local[1]= argv[0];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	env->c.clo.env2[9] = w;
	w = env->c.clo.env2[9];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___irtrobot(ctx,n,argv,env)
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
	local[0]= fqv[375];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF4800;
	local[0]= fqv[376];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[377],w);
	goto IF4801;
IF4800:
	local[0]= fqv[378];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF4801:
	local[0]= fqv[379];
	ctx->vsp=local+1;
	w=(*ftab[49])(ctx,1,local+0,&ftab[49],fqv[380]); /*require*/
	local[0]= fqv[381];
	ctx->vsp=local+1;
	w=(*ftab[49])(ctx,1,local+0,&ftab[49],fqv[380]); /*require*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[382],module,F4068make_default_robot_link,fqv[383]);
	local[0]= fqv[384];
	local[1]= fqv[385];
	local[2]= fqv[384];
	local[3]= fqv[386];
	local[4]= loadglobal(fqv[387]);
	local[5]= fqv[75];
	local[6]= fqv[388];
	local[7]= fqv[389];
	local[8]= NIL;
	local[9]= fqv[390];
	local[10]= NIL;
	local[11]= fqv[291];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[391];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[50])(ctx,13,local+2,&ftab[50],fqv[392]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4103robot_model_init_ending,fqv[39],fqv[384],fqv[393]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4108robot_model_rarm_end_coords,fqv[394],fqv[384],fqv[395]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4110robot_model_larm_end_coords,fqv[396],fqv[384],fqv[397]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4112robot_model_rleg_end_coords,fqv[398],fqv[384],fqv[399]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4114robot_model_lleg_end_coords,fqv[400],fqv[384],fqv[401]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4116robot_model_head_end_coords,fqv[402],fqv[384],fqv[403]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4118robot_model_torso_end_coords,fqv[404],fqv[384],fqv[405]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4120robot_model_rarm_root_link,fqv[406],fqv[384],fqv[407]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4122robot_model_larm_root_link,fqv[408],fqv[384],fqv[409]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4124robot_model_rleg_root_link,fqv[410],fqv[384],fqv[411]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4126robot_model_lleg_root_link,fqv[412],fqv[384],fqv[413]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4128robot_model_head_root_link,fqv[414],fqv[384],fqv[415]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4130robot_model_torso_root_link,fqv[416],fqv[384],fqv[417]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4132robot_model_limb,fqv[77],fqv[384],fqv[418]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4199robot_model_inverse_kinematics_loop_for_look_at,fqv[72],fqv[384],fqv[419]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4248robot_model_gripper,fqv[81],fqv[384],fqv[420]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4259robot_model_camera,fqv[131],fqv[384],fqv[421]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4261robot_model_force_sensor,fqv[132],fqv[384],fqv[422]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4263robot_model_imu_sensor,fqv[133],fqv[384],fqv[423]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4265robot_model_get_sensor_method,fqv[130],fqv[384],fqv[424]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4268robot_model_get_sensors_method_by_limb,fqv[84],fqv[384],fqv[425]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4271robot_model_force_sensors,fqv[86],fqv[384],fqv[426]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4273robot_model_imu_sensors,fqv[85],fqv[384],fqv[427]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4275robot_model_cameras,fqv[83],fqv[384],fqv[428]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4277robot_model_larm,fqv[140],fqv[384],fqv[429]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4282robot_model_rarm,fqv[141],fqv[384],fqv[430]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4287robot_model_lleg,fqv[142],fqv[384],fqv[431]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4292robot_model_rleg,fqv[143],fqv[384],fqv[432]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4297robot_model_head,fqv[70],fqv[384],fqv[433]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4302robot_model_torso,fqv[144],fqv[384],fqv[434]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4307robot_model_arms,fqv[146],fqv[384],fqv[435]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4310robot_model_legs,fqv[41],fqv[384],fqv[436]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4313robot_model_look_at_hand,fqv[437],fqv[384],fqv[438]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4320robot_model_inverse_kinematics,fqv[54],fqv[384],fqv[439]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4336robot_model_inverse_kinematics_loop,fqv[117],fqv[384],fqv[440]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4353robot_model_look_at_target,fqv[145],fqv[384],fqv[441]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4363robot_model_init_pose,fqv[442],fqv[384],fqv[443]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4365robot_model_torque_vector,fqv[444],fqv[384],fqv[445]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4386robot_model_distribute_total_wrench_to_torque_method_default,fqv[162],fqv[384],fqv[446]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4395robot_model_calc_force_from_joint_torque,fqv[447],fqv[384],fqv[448]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4405robot_model_fullbody_inverse_kinematics,fqv[255],fqv[384],fqv[449]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4433robot_model_joint_angle_limit_nspace_for_6dof,fqv[450],fqv[384],fqv[451]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4456robot_model_joint_order,fqv[82],fqv[384],fqv[452]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4482robot_model_print_vector_for_robot_limb,fqv[453],fqv[384],fqv[454]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4495robot_model_calc_zmp_from_forces_moments,fqv[455],fqv[384],fqv[456]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4523robot_model_foot_midcoords,fqv[457],fqv[384],fqv[458]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4527robot_model_fix_leg_to_coords,fqv[304],fqv[384],fqv[459]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4540robot_model_move_centroid_on_foot,fqv[352],fqv[384],fqv[460]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4570robot_model_calc_walk_pattern_from_footstep_list,fqv[461],fqv[384],fqv[462]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4608robot_model_draw_gg_debug_view,fqv[278],fqv[384],fqv[463]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4618robot_model_gen_footstep_parameter,fqv[315],fqv[384],fqv[464]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4630robot_model_footstep_parameter,fqv[309],fqv[384],fqv[465]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4634robot_model_go_pos_params__footstep_list,fqv[322],fqv[384],fqv[466]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4664robot_model_go_pos_quadruped_params__footstep_list,fqv[467],fqv[384],fqv[468]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4714robot_model_support_polygons,fqv[332],fqv[384],fqv[469]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4716robot_model_support_polygon,fqv[367],fqv[384],fqv[470]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4723robot_model_make_support_polygons,fqv[44],fqv[384],fqv[471]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4725robot_model_make_sole_polygon,fqv[333],fqv[384],fqv[472]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4734robot_model_make_default_linear_link_joint_between_attach_coords,fqv[473],fqv[384],fqv[474]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4742robot_model_calc_static_balance_point,fqv[475],fqv[384],fqv[476]);
	local[0]= fqv[477];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF4802;
	local[0]= fqv[478];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[377],w);
	goto IF4803;
IF4802:
	local[0]= fqv[479];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF4803:
	local[0]= fqv[480];
	local[1]= fqv[481];
	ctx->vsp=local+2;
	w=(*ftab[51])(ctx,2,local+0,&ftab[51],fqv[482]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<52; i++) ftab[i]=fcallx;
}
