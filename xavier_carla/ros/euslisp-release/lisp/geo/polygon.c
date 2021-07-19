/* ./polygon.c :  entry=polygon */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "polygon.h"
#pragma init (register_polygon)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___polygon();
extern pointer build_quote_vector();
static int register_polygon()
  { add_module_initializer("___polygon", ___polygon);}

static pointer F3031make_polygon2d();
static pointer F3032make_rectangle();
static pointer F3033make_circle();

/*:vertices*/
static pointer M3034polygon2d_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK3035:
	ctx->vsp=local; return(local[0]);}

/*:lines*/
static pointer M3036polygon2d_lines(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[10];
	local[0]= w;
BLK3037:
	ctx->vsp=local; return(local[0]);}

/*:edges*/
static pointer M3038polygon2d_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[9];
WHL3040:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX3041;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[2]= w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	w = local[0];
	ctx->vsp=local+3;
	local[0] = cons(ctx,local[2],w);
	goto WHL3040;
WHX3041:
	local[2]= NIL;
BLK3042:
	w = local[0];
	local[0]= w;
BLK3039:
	ctx->vsp=local; return(local[0]);}

/*:drawners*/
static pointer M3044polygon2d_drawners(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[0];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK3045:
	ctx->vsp=local; return(local[0]);}

/*:box*/
static pointer M3046polygon2d_box(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[12];
	local[0]= w;
BLK3047:
	ctx->vsp=local; return(local[0]);}

/*:boxtest*/
static pointer M3048polygon2d_boxtest(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= loadglobal(fqv[1]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w!=NIL) goto IF3050;
	local[0]= argv[2];
	local[1]= fqv[2];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[2] = w;
	local[0]= argv[2];
	goto IF3051;
IF3050:
	local[0]= NIL;
IF3051:
	local[0]= argv[0]->c.obj.iv[12];
	local[1]= fqv[3];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3049:
	ctx->vsp=local; return(local[0]);}

/*:update*/
static pointer M3052polygon2d_update(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= argv[0]->c.obj.iv[9];
	local[2]= argv[0]->c.obj.iv[5]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[5]->c.obj.iv[2];
WHL3054:
	if (local[0]==NIL) goto WHX3055;
	local[4]= local[2];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)TRANSFORM(ctx,3,local+4); /*transform*/
	local[4]= local[3];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)VPLUS(ctx,3,local+4); /*v+*/
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[4];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	goto WHL3054;
WHX3055:
	local[4]= NIL;
BLK3056:
	local[4]= argv[0]->c.obj.iv[12];
	local[5]= fqv[4];
	local[6]= argv[0]->c.obj.iv[9];
	local[7]= loadglobal(fqv[5]);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = argv[0];
	local[0]= w;
BLK3053:
	ctx->vsp=local; return(local[0]);}

/*:set-convexp*/
static pointer M3059polygon2d_set_convexp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[9];
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	local[0]= w;
	local[1]= (pointer)get_sym_func(fqv[6]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[0] = w;
	argv[0]->c.obj.iv[11] = T;
WHL3061:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX3062;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[1];
	local[1]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,3,local+1,&ftab[0],fqv[7]); /*triangle*/
	local[1]= w;
	local[2]= makeflt(0.00000000e+00);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto IF3064;
	argv[0]->c.obj.iv[11] = NIL;
	local[0] = NIL;
	local[1]= local[0];
	goto IF3065;
IF3064:
	local[1]= NIL;
IF3065:
	goto WHL3061;
WHX3062:
	local[1]= NIL;
BLK3063:
	w = local[1];
	w = argv[0]->c.obj.iv[11];
	local[0]= w;
BLK3060:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3067polygon2d_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[8]));
	local[2]= fqv[4];
	local[3]= fqv[9];
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,5,local+0); /*send-message*/
	local[0]= argv[2];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	argv[0]->c.obj.iv[9] = w;
	local[0]= (pointer)get_sym_func(fqv[10]);
	local[1]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	argv[0]->c.obj.iv[8] = w;
	local[0]= argv[0]->c.obj.iv[9];
	local[1]= makeflt(1.00000000e-02);
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[11]); /*make-bounding-box*/
	argv[0]->c.obj.iv[12] = w;
	local[0]= argv[0]->c.obj.iv[9];
	argv[0]->c.obj.iv[10] = NIL;
WHL3069:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX3070;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[1];
	local[1]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[12]); /*make-line*/
	local[1]= w;
	w = argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[10] = cons(ctx,local[1],w);
	goto WHL3069;
WHX3070:
	local[1]= NIL;
BLK3071:
	w = local[1];
	local[0]= argv[0];
	local[1]= fqv[13];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = argv[0];
	local[0]= w;
BLK3068:
	ctx->vsp=local; return(local[0]);}

/*:intersect-line*/
static pointer M3073polygon2d_intersect_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3076;}
	local[0]= NIL;
ENT3076:
ENT3075:
	if (n>4) maerror();
	if (local[0]!=NIL) goto IF3077;
	local[0] = argv[2]->c.obj.iv[2];
	argv[2] = argv[2]->c.obj.iv[1];
	local[1]= argv[2];
	goto IF3078;
IF3077:
	local[1]= NIL;
IF3078:
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[0]->c.obj.iv[10];
WHL3080:
	if (local[6]==NIL) goto WHX3081;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[5]->c.obj.iv[1];
	local[8]= local[5]->c.obj.iv[2];
	local[9]= argv[2];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)LINEINTERSECTION(ctx,4,local+7); /*line-intersection*/
	local[1] = w;
	if (local[1]==NIL) goto IF3084;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	local[7]= makeflt(0.00000000e+00);
	local[8]= local[2];
	local[9]= makeflt(1.00000000e+00);
	ctx->vsp=local+10;
	w=(pointer)LSEQP(ctx,3,local+7); /*<=*/
	if (w==NIL) goto IF3086;
	local[7]= makeflt(0.00000000e+00);
	local[8]= local[3];
	local[9]= makeflt(1.00000000e+00);
	ctx->vsp=local+10;
	w=(pointer)LSEQP(ctx,3,local+7); /*<=*/
	if (w==NIL) goto IF3086;
	local[7]= local[2];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	w = local[4];
	ctx->vsp=local+8;
	local[4] = cons(ctx,local[7],w);
	local[7]= local[4];
	goto IF3087;
IF3086:
	local[7]= NIL;
IF3087:
	goto IF3085;
IF3084:
	local[7]= NIL;
IF3085:
	goto WHL3080;
WHX3081:
	local[7]= NIL;
BLK3082:
	w = NIL;
	w = local[4];
	local[0]= w;
BLK3074:
	ctx->vsp=local; return(local[0]);}

/*:on-edge*/
static pointer M3088polygon2d_on_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3091;}
	local[0]= loadglobal(fqv[5]);
ENT3091:
ENT3090:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[10];
WHL3093:
	if (local[4]==NIL) goto WHX3094;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3];
	local[6]= fqv[14];
	local[7]= argv[2];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	if (w==NIL) goto IF3097;
	local[5]= local[3];
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[2];
	goto IF3098;
IF3097:
	local[5]= NIL;
IF3098:
	goto WHL3093;
WHX3094:
	local[5]= NIL;
BLK3095:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK3089:
	ctx->vsp=local; return(local[0]);}

/*:insidep*/
static pointer M3099polygon2d_insidep(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (w==NIL) goto IF3101;
	local[0]= fqv[16];
	goto IF3102;
IF3101:
	local[0]= argv[0];
	local[1]= fqv[17];
	local[2]= argv[2];
	local[3]= makeflt(1.00000000e+10);
	ctx->vsp=local+4;
	w=(pointer)RANDOM(ctx,1,local+3); /*random*/
	local[3]= w;
	local[4]= makeflt(1.00000000e+10);
	ctx->vsp=local+5;
	w=(pointer)RANDOM(ctx,1,local+4); /*random*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,2,local+3); /*float-vector*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[3])(ctx,1,local+0,&ftab[3],fqv[18]); /*evenp*/
	local[0]= ((w)==NIL?T:NIL);
IF3102:
	w = local[0];
	local[0]= w;
BLK3100:
	ctx->vsp=local; return(local[0]);}

/*:intersect-polygon2d*/
static pointer M3103polygon2d_intersect_polygon2d(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (w==NIL) goto IF3105;
	local[0]= argv[2];
	local[1]= fqv[20];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[0]->c.obj.iv[10];
WHL3108:
	if (local[5]==NIL) goto WHX3109;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[1] = local[4]->c.obj.iv[1];
	local[2] = local[4]->c.obj.iv[2];
	local[6]= NIL;
	local[7]= local[0];
WHL3113:
	if (local[7]==NIL) goto WHX3114;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[1];
	local[9]= local[2];
	local[10]= local[6]->c.obj.iv[1];
	local[11]= local[6]->c.obj.iv[2];
	ctx->vsp=local+12;
	w=(pointer)LINEINTERSECTION(ctx,4,local+8); /*line-intersection*/
	local[3] = w;
	if (local[3]==NIL) goto IF3117;
	local[8]= makeflt(0.00000000e+00);
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= makeflt(1.00000000e+00);
	local[11]= makeflt(-1.00000000e-03);
	ctx->vsp=local+12;
	w=(*ftab[4])(ctx,4,local+8,&ftab[4],fqv[21]); /*eps-in-range*/
	if (w==NIL) goto CON3120;
	local[8]= makeflt(0.00000000e+00);
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= makeflt(1.00000000e+00);
	local[11]= makeflt(-1.00000000e-03);
	ctx->vsp=local+12;
	w=(*ftab[4])(ctx,4,local+8,&ftab[4],fqv[21]); /*eps-in-range*/
	if (w==NIL) goto CON3120;
	w = T;
	ctx->vsp=local+8;
	local[0]=w;
	goto BLK3104;
	goto CON3119;
CON3120:
	local[8]= NIL;
CON3119:
	goto IF3118;
IF3117:
	local[8]= NIL;
IF3118:
	goto WHL3113;
WHX3114:
	local[8]= NIL;
BLK3115:
	w = NIL;
	goto WHL3108;
WHX3109:
	local[6]= NIL;
BLK3110:
	w = NIL;
	local[4]= NIL;
	local[5]= makeint(0);
	local[6]= makeint(0);
	local[7]= makeint(0);
	local[8]= NIL;
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
WHL3122:
	if (local[9]==NIL) goto WHX3123;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= argv[2];
	local[11]= fqv[22];
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[4] = w;
	local[10]= local[4];
	if (T!=local[10]) goto CON3127;
	w = T;
	ctx->vsp=local+10;
	local[0]=w;
	goto BLK3104;
	goto CON3126;
CON3127:
	local[10]= local[4];
	if (NIL!=local[10]) goto CON3128;
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[6] = w;
	local[10]= local[6];
	goto CON3126;
CON3128:
	local[10]= local[4];
	if (fqv[16]!=local[10]) goto CON3129;
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[7] = w;
	local[10]= local[7];
	goto CON3126;
CON3129:
	local[10]= NIL;
CON3126:
	goto WHL3122;
WHX3123:
	local[10]= NIL;
BLK3124:
	w = NIL;
	local[8]= NIL;
	local[9]= argv[2];
	local[10]= fqv[23];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
WHL3131:
	if (local[9]==NIL) goto WHX3132;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= argv[0];
	local[11]= fqv[22];
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[4] = w;
	local[10]= local[4];
	if (T!=local[10]) goto CON3136;
	w = T;
	ctx->vsp=local+10;
	local[0]=w;
	goto BLK3104;
	goto CON3135;
CON3136:
	local[10]= local[4];
	if (NIL!=local[10]) goto CON3137;
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[6] = w;
	local[10]= local[6];
	goto CON3135;
CON3137:
	local[10]= local[4];
	if (fqv[16]!=local[10]) goto CON3138;
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[7] = w;
	local[10]= local[7];
	goto CON3135;
CON3138:
	local[10]= NIL;
CON3135:
	goto WHL3131;
WHX3132:
	local[10]= NIL;
BLK3133:
	w = NIL;
	local[8]= local[7];
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(pointer)GREATERP(ctx,2,local+8); /*>*/
	if (w==NIL) goto IF3139;
	local[8]= fqv[16];
	goto IF3140;
IF3139:
	local[8]= NIL;
IF3140:
	w = local[8];
	local[0]= w;
	goto IF3106;
IF3105:
	local[0]= NIL;
IF3106:
	w = local[0];
	local[0]= w;
BLK3104:
	ctx->vsp=local; return(local[0]);}

/*:distance-point*/
static pointer M3141polygon2d_distance_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= (pointer)get_sym_func(fqv[24]);
	local[1]= argv[0]->c.obj.iv[10];
	local[2]= fqv[25];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(*ftab[5])(ctx,3,local+1,&ftab[5],fqv[26]); /*send-all*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
BLK3142:
	ctx->vsp=local; return(local[0]);}

/*:distance*/
static pointer M3143polygon2d_distance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[27];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	local[2]= loadglobal(fqv[5]);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto CON3146;
	local[1]= fqv[16];
	goto CON3145;
CON3146:
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	if (w==NIL) goto CON3147;
	local[1]= fqv[28];
	goto CON3145;
CON3147:
	local[1]= local[0];
	goto CON3145;
CON3148:
	local[1]= NIL;
CON3145:
	w = local[1];
	local[0]= w;
BLK3144:
	ctx->vsp=local; return(local[0]);}

/*:3d*/
static pointer M3149polygon2d_3d(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3153;}
	local[0]= makeflt(0.00000000e+00);
ENT3153:
	if (n>=4) { local[1]=(argv[3]); goto ENT3152;}
	local[1]= loadglobal(fqv[29]);
ENT3152:
ENT3151:
	if (n>4) maerror();
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[4];
	local[5]= fqv[23];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO3155,env,argv,local);
	local[7]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+8;
	w=(pointer)BUTLAST(ctx,1,local+7); /*butlast*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	w = local[2];
	local[0]= w;
BLK3150:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3155(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	local[2]= env->c.clo.env2[0];
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:radius*/
static pointer M3156circle2d_radius(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK3157:
	ctx->vsp=local; return(local[0]);}

/*:draw*/
static pointer M3158circle2d_draw(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[30];
	local[2]= argv[0];
	local[3]= fqv[31];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[8];
	local[4]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= w;
BLK3159:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3160circle2d_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST3162:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)EUSFLOAT(ctx,1,local+1); /*float*/
	argv[0]->c.obj.iv[8] = w;
	local[1]= (pointer)get_sym_func(fqv[32]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[8]));
	local[4]= fqv[4];
	local[5]= fqv[9];
	local[6]= makeint(2);
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,7,local+1); /*apply*/
	w = argv[0];
	local[0]= w;
BLK3161:
	ctx->vsp=local; return(local[0]);}

/*make-polygon2d*/
static pointer F3031make_polygon2d(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST3164:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= loadglobal(fqv[33]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[4];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK3163:
	ctx->vsp=local; return(local[0]);}

/*make-rectangle*/
static pointer F3032make_rectangle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= makeflt(2.00000000e+00);
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
	local[1]= argv[1];
	local[2]= makeflt(2.00000000e+00);
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= loadglobal(fqv[33]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[4];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,1,local+5); /*-*/
	local[5]= w;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,1,local+6); /*-*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,2,local+5); /*float-vector*/
	local[5]= w;
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,1,local+7); /*-*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,2,local+6); /*float-vector*/
	local[6]= w;
	local[7]= local[0];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,2,local+7); /*float-vector*/
	local[7]= w;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,1,local+8); /*-*/
	local[8]= w;
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,2,local+8); /*float-vector*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,4,local+5); /*list*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	w = local[2];
	local[0]= w;
BLK3166:
	ctx->vsp=local; return(local[0]);}

/*make-circle*/
static pointer F3033make_circle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST3169:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= (pointer)get_sym_func(fqv[34]);
	local[2]= loadglobal(fqv[35]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= fqv[4];
	local[4]= argv[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	local[0]= w;
BLK3168:
	ctx->vsp=local; return(local[0]);}

/*:draw*/
static pointer M3170polygon2d_draw(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3173;}
	local[0]= NIL;
ENT3173:
ENT3172:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF3174;
	local[1]= argv[2];
	local[2]= fqv[36];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF3175;
IF3174:
	local[1]= NIL;
IF3175:
	local[1]= argv[2];
	local[2]= fqv[37];
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK3171:
	ctx->vsp=local; return(local[0]);}

/*:draw-fill*/
static pointer M3176polygon2d_draw_fill(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3179;}
	local[0]= NIL;
ENT3179:
ENT3178:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF3180;
	local[1]= argv[2];
	local[2]= fqv[36];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF3181;
IF3180:
	local[1]= NIL;
IF3181:
	local[1]= argv[2];
	local[2]= fqv[38];
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK3177:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___polygon(ctx,n,argv,env)
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
	local[0]= fqv[39];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[33];
	local[1]= fqv[40];
	local[2]= fqv[33];
	local[3]= fqv[41];
	local[4]= loadglobal(fqv[42]);
	local[5]= fqv[43];
	local[6]= fqv[44];
	local[7]= fqv[45];
	local[8]= NIL;
	local[9]= fqv[46];
	local[10]= NIL;
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[48];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[6])(ctx,13,local+2,&ftab[6],fqv[49]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3034polygon2d_vertices,fqv[23],fqv[33],fqv[50]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3036polygon2d_lines,fqv[20],fqv[33],fqv[51]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3038polygon2d_edges,fqv[0],fqv[33],fqv[52]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3044polygon2d_drawners,fqv[53],fqv[33],fqv[54]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3046polygon2d_box,fqv[2],fqv[33],fqv[55]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3048polygon2d_boxtest,fqv[19],fqv[33],fqv[56]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3052polygon2d_update,fqv[57],fqv[33],fqv[58]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3059polygon2d_set_convexp,fqv[13],fqv[33],fqv[59]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3067polygon2d_init,fqv[4],fqv[33],fqv[60]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3073polygon2d_intersect_line,fqv[17],fqv[33],fqv[61]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3088polygon2d_on_edge,fqv[15],fqv[33],fqv[62]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3099polygon2d_insidep,fqv[22],fqv[33],fqv[63]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3103polygon2d_intersect_polygon2d,fqv[64],fqv[33],fqv[65]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3141polygon2d_distance_point,fqv[27],fqv[33],fqv[66]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3143polygon2d_distance,fqv[25],fqv[33],fqv[67]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3149polygon2d_3d,fqv[68],fqv[33],fqv[69]);
	local[0]= fqv[35];
	local[1]= fqv[40];
	local[2]= fqv[35];
	local[3]= fqv[41];
	local[4]= loadglobal(fqv[42]);
	local[5]= fqv[43];
	local[6]= fqv[70];
	local[7]= fqv[45];
	local[8]= NIL;
	local[9]= fqv[46];
	local[10]= NIL;
	local[11]= fqv[47];
	local[12]= makeint(-1);
	local[13]= fqv[48];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[6])(ctx,13,local+2,&ftab[6],fqv[49]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3156circle2d_radius,fqv[71],fqv[35],fqv[72]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3158circle2d_draw,fqv[73],fqv[35],fqv[74]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3160circle2d_init,fqv[4],fqv[35],fqv[75]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[76],module,F3031make_polygon2d,fqv[77]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[78],module,F3032make_rectangle,fqv[79]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[80],module,F3033make_circle,fqv[81]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3170polygon2d_draw,fqv[73],fqv[33],fqv[82]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3176polygon2d_draw_fill,fqv[83],fqv[33],fqv[84]);
	local[0]= fqv[85];
	local[1]= fqv[86];
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,2,local+0,&ftab[7],fqv[87]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<8; i++) ftab[i]=fcallx;
}
