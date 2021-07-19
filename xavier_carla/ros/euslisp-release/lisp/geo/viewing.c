/* ./viewing.c :  entry=viewing */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "viewing.h"
#pragma init (register_viewing)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___viewing();
extern pointer build_quote_vector();
static int register_viewing()
  { add_module_initializer("___viewing", ___viewing);}


/*:update*/
static pointer M3427viewing_update(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[0]));
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= argv[0]->c.obj.iv[5]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[8]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)TRANSPOSE(ctx,2,local+0); /*transpose*/
	local[0]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	if (makeint(3)!=local[0]) goto IF3429;
	local[0]= fqv[2];
	local[1]= argv[0]->c.obj.iv[8]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[8]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)MATTIMES(ctx,3,local+0); /*m**/
	local[0]= w;
	goto IF3430;
IF3429:
	local[0]= NIL;
IF3430:
	local[0]= makeflt(-1.00000000e+00);
	local[1]= argv[0]->c.obj.iv[8]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[5]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)TRANSFORM(ctx,2,local+1); /*transform*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[8]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,3,local+0); /*scale*/
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK3428:
	ctx->vsp=local; return(local[0]);}

/*:changed*/
static pointer M3431viewing_changed(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[0]));
	local[2]= fqv[3];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= argv[0];
	local[1]= fqv[4];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK3432:
	ctx->vsp=local; return(local[0]);}

/*:viewpoint*/
static pointer M3433viewing_viewpoint(ctx,n,argv,env)
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
BLK3434:
	ctx->vsp=local; return(local[0]);}

/*:view-direction*/
static pointer M3435viewing_view_direction(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[8]->c.obj.iv[1];
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[6]); /*matrix-row*/
	local[0]= w;
BLK3436:
	ctx->vsp=local; return(local[0]);}

/*:view-up*/
static pointer M3437viewing_view_up(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[8]->c.obj.iv[1];
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[6]); /*matrix-row*/
	local[0]= w;
BLK3438:
	ctx->vsp=local; return(local[0]);}

/*:view-right*/
static pointer M3439viewing_view_right(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[8]->c.obj.iv[1];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[6]); /*matrix-row*/
	local[0]= w;
BLK3440:
	ctx->vsp=local; return(local[0]);}

/*:sendviewcoords*/
static pointer M3441viewing_sendviewcoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[7];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
BLK3442:
	ctx->vsp=local; return(local[0]);}

/*:look*/
static pointer M3443viewing_look(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3446;}
	local[0]= fqv[8];
ENT3446:
ENT3445:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[0] = w;
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[0]));
	local[3]= fqv[9];
	ctx->vsp=local+4;
	w=(pointer)SENDMESSAGE(ctx,3,local+1); /*send-message*/
	local[1]= argv[0];
	local[2]= fqv[10];
	local[3]= local[0];
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	local[4]= local[0];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	local[5]= local[0];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	local[5]= local[0];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	local[6]= local[0];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SQRT(ctx,1,local+4); /*sqrt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ATAN(ctx,2,local+3); /*atan*/
	local[3]= makeflt(-(fltval(w)));
	local[4]= fqv[11];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[10];
	local[3]= local[0];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	local[4]= local[0];
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ATAN(ctx,2,local+3); /*atan*/
	local[3]= w;
	{ double x,y;
		y=fltval(makeflt(3.14159265e+00)); x=fltval(local[3]);
		local[3]=(makeflt(x + y));}
	local[3]= makeflt(-(fltval(local[3])));
	local[4]= fqv[13];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[10];
	local[3]= makeflt(-(fltval(makeflt(3.14159265e+00))));
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,1,local+3); /*-*/
	local[3]= w;
	local[4]= fqv[11];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[0]));
	local[3]= fqv[14];
	local[4]= argv[2];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	w = argv[0];
	local[0]= w;
BLK3444:
	ctx->vsp=local; return(local[0]);}

/*:makeviewcoords*/
static pointer M3447viewing_makeviewcoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[0]));
	local[2]= fqv[15];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= argv[0];
	local[1]= fqv[10];
	local[2]= makeflt(1.57079633e+00);
	local[3]= fqv[11];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[10];
	local[2]= makeflt(1.57079633e+00);
	local[3]= fqv[16];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[10];
	local[2]= argv[2];
	local[3]= fqv[11];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[10];
	local[2]= argv[3];
	local[3]= fqv[13];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[10];
	local[2]= argv[4];
	local[3]= fqv[16];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[14];
	local[2]= argv[5];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK3448:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3449viewing_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3451:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[17], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3452;
	local[1] = makeint(3);
KEY3452:
	if (n & (1<<1)) goto KEY3453;
	local[2] = NIL;
KEY3453:
	if (n & (1<<2)) goto KEY3454;
	local[3] = NIL;
KEY3454:
	if (n & (1<<3)) goto KEY3455;
	local[6]= makeflt(0.00000000e+00);
	local[7]= makeflt(0.00000000e+00);
	local[8]= makeflt(1.00000000e+00);
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,3,local+6); /*float-vector*/
	local[4] = w;
KEY3455:
	if (n & (1<<4)) goto KEY3456;
	local[5] = NIL;
KEY3456:
	local[6]= (pointer)get_sym_func(fqv[18]);
	local[7]= argv[0];
	local[8]= *(ovafptr(argv[1],fqv[0]));
	local[9]= fqv[9];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)APPLY(ctx,5,local+6); /*apply*/
	local[6]= fqv[19];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[1])(ctx,2,local+6,&ftab[1],fqv[20]); /*coords*/
	argv[0]->c.obj.iv[8] = w;
	if (local[2]!=NIL) goto OR3459;
	if (local[3]!=NIL) goto OR3459;
	goto IF3457;
OR3459:
	if (local[3]!=NIL) goto IF3460;
	local[6]= local[2];
	local[7]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+8;
	w=(pointer)VMINUS(ctx,2,local+6); /*v-*/
	local[3] = w;
	local[6]= local[3];
	goto IF3461;
IF3460:
	local[6]= NIL;
IF3461:
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)VNORMALIZE(ctx,1,local+6); /*normalize-vector*/
	local[3] = w;
	if (local[5]!=NIL) goto IF3462;
	local[6]= local[3];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+6); /*v**/
	local[5] = w;
	local[6]= local[5];
	goto IF3463;
IF3462:
	local[6]= NIL;
IF3463:
	local[6]= local[5];
	ctx->vsp=local+7;
	w=(pointer)VNORMALIZE(ctx,1,local+6); /*normalize-vector*/
	local[5] = w;
	local[6]= local[5];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+6); /*v**/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)VNORMALIZE(ctx,1,local+6); /*normalize-vector*/
	local[4] = w;
	local[6]= makeflt(-1.00000000e+00);
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SCALEVEC(ctx,2,local+6); /*scale*/
	local[3] = w;
	local[6]= loadglobal(fqv[21]);
	local[7]= local[5];
	local[8]= local[4];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)CONCATENATE(ctx,4,local+6); /*concatenate*/
	local[6]= w;
	local[7]= w;
	w = argv[0]->c.obj.iv[1];
	w->c.obj.iv[1] = local[7];
	local[6]= argv[0]->c.obj.iv[1];
	local[7]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+8;
	w=(pointer)TRANSPOSE(ctx,2,local+6); /*transpose*/
	local[6]= w;
	goto IF3458;
IF3457:
	local[6]= NIL;
IF3458:
	local[6]= argv[0];
	local[7]= fqv[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	w = argv[0];
	local[0]= w;
BLK3450:
	ctx->vsp=local; return(local[0]);}

/*:projection*/
static pointer M3464projection_projection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[13];
	local[0]= w;
BLK3465:
	ctx->vsp=local; return(local[0]);}

/*:newprojection*/
static pointer M3466projection_newprojection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[13] = argv[2];
	w = argv[0]->c.obj.iv[13];
	local[0]= w;
BLK3467:
	ctx->vsp=local; return(local[0]);}

/*:project*/
static pointer M3468projection_project(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
BLK3469:
	ctx->vsp=local; return(local[0]);}

/*:project3*/
static pointer M3470projection_project3(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)HOMOGENIZE(ctx,1,local+1); /*homogenize*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
BLK3471:
	ctx->vsp=local; return(local[0]);}

/*:view*/
static pointer M3472projection_view(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[22];
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[23];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3473:
	ctx->vsp=local; return(local[0]);}

/*:screen*/
static pointer M3474projection_screen(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3478;}
	local[0]= NIL;
ENT3478:
	if (n>=4) { local[1]=(argv[3]); goto ENT3477;}
	local[1]= local[0];
ENT3477:
ENT3476:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF3479;
	argv[0]->c.obj.iv[9] = local[0];
	argv[0]->c.obj.iv[10] = local[1];
	local[2]= argv[0];
	local[3]= fqv[24];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	goto IF3480;
IF3479:
	local[2]= NIL;
IF3480:
	local[2]= argv[0]->c.obj.iv[9];
	local[3]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[0]= w;
BLK3475:
	ctx->vsp=local; return(local[0]);}

/*:hither*/
static pointer M3481projection_hither(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3484;}
	local[0]= NIL;
ENT3484:
ENT3483:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3485;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)EUSFLOAT(ctx,1,local+1); /*float*/
	argv[0]->c.obj.iv[11] = w;
	local[1]= argv[0];
	local[2]= fqv[24];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF3486;
IF3485:
	local[1]= NIL;
IF3486:
	w = argv[0]->c.obj.iv[11];
	local[0]= w;
BLK3482:
	ctx->vsp=local; return(local[0]);}

/*:yon*/
static pointer M3487projection_yon(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3490;}
	local[0]= NIL;
ENT3490:
ENT3489:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3491;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)EUSFLOAT(ctx,1,local+1); /*float*/
	argv[0]->c.obj.iv[12] = w;
	local[1]= argv[0];
	local[2]= fqv[24];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF3492;
IF3491:
	local[1]= NIL;
IF3492:
	w = argv[0]->c.obj.iv[12];
	local[0]= w;
BLK3488:
	ctx->vsp=local; return(local[0]);}

/*:aspect*/
static pointer M3493projection_aspect(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3496;}
	local[0]= NIL;
ENT3496:
ENT3495:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3497;
	local[1]= argv[0]->c.obj.iv[9];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	argv[0]->c.obj.iv[10] = w;
	local[1]= argv[0];
	local[2]= fqv[24];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF3498;
IF3497:
	local[1]= NIL;
IF3498:
	local[1]= argv[0]->c.obj.iv[10];
	local[2]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[0]= w;
BLK3494:
	ctx->vsp=local; return(local[0]);}

/*:viewreference*/
static pointer M3499projection_viewreference(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(0);
	local[1]= makeint(0);
	local[2]= argv[0]->c.obj.iv[11];
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[12]); x=fltval(local[2]);
		local[2]=(makeflt(x + y));}
	local[3]= makeflt(2.00000000e+00);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
BLK3500:
	ctx->vsp=local; return(local[0]);}

/*:make-projection*/
static pointer M3501projection_make_projection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3503:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= fqv[25];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[0]= w;
BLK3502:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3504projection_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3506:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[26], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3507;
	local[1] = makeflt(1.00000000e+02);
KEY3507:
	if (n & (1<<1)) goto KEY3508;
	local[2] = makeflt(1.00000000e+04);
KEY3508:
	if (n & (1<<2)) goto KEY3509;
	local[3] = makeflt(1.00000000e+00);
KEY3509:
	if (n & (1<<3)) goto KEY3510;
	local[4] = makeflt(1.00000000e+02);
KEY3510:
	if (n & (1<<4)) goto KEY3511;
	local[5] = local[4];
KEY3511:
	if (n & (1<<5)) goto KEY3512;
	local[7]= local[3];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[6] = w;
KEY3512:
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)EUSFLOAT(ctx,1,local+7); /*float*/
	argv[0]->c.obj.iv[11] = w;
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)EUSFLOAT(ctx,1,local+7); /*float*/
	argv[0]->c.obj.iv[12] = w;
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)EUSFLOAT(ctx,1,local+7); /*float*/
	argv[0]->c.obj.iv[9] = w;
	local[7]= local[6];
	ctx->vsp=local+8;
	w=(pointer)EUSFLOAT(ctx,1,local+7); /*float*/
	argv[0]->c.obj.iv[10] = w;
	local[7]= (pointer)get_sym_func(fqv[18]);
	local[8]= argv[0];
	local[9]= *(ovafptr(argv[1],fqv[0]));
	local[10]= fqv[9];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)APPLY(ctx,5,local+7); /*apply*/
	local[7]= argv[0];
	local[8]= fqv[24];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	w = argv[0];
	local[0]= w;
BLK3505:
	ctx->vsp=local; return(local[0]);}

/*:project*/
static pointer M3513viewing2d_project(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
BLK3514:
	ctx->vsp=local; return(local[0]);}

/*:project2*/
static pointer M3515viewing2d_project2(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)HOMOGENIZE(ctx,1,local+0); /*homogenize*/
	local[0]= w;
BLK3516:
	ctx->vsp=local; return(local[0]);}

/*:view*/
static pointer M3517viewing2d_view(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[27];
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[23];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3518:
	ctx->vsp=local; return(local[0]);}

/*:make-projection*/
static pointer M3519viewing2d_make_projection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(2);
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[28]); /*make-matrix*/
	argv[0]->c.obj.iv[13] = w;
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= makeint(0);
	local[2]= makeint(0);
	local[3]= makeflt(2.00000000e+00);
	local[4]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,4,local+0); /*aset*/
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= makeint(1);
	local[2]= makeint(1);
	local[3]= makeflt(2.00000000e+00);
	local[4]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,4,local+0); /*aset*/
	w = argv[0]->c.obj.iv[13];
	local[0]= w;
BLK3520:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3521viewing2d_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3523:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[29], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3524;
	local[1] = makeflt(1.00000000e+00);
KEY3524:
	if (n & (1<<1)) goto KEY3525;
	local[2] = local[1];
KEY3525:
	if (n & (1<<2)) goto KEY3526;
	local[3] = local[2];
KEY3526:
	local[4]= (pointer)get_sym_func(fqv[18]);
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[0]));
	local[7]= fqv[9];
	local[8]= fqv[19];
	local[9]= makeint(2);
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)APPLY(ctx,7,local+4); /*apply*/
	argv[0]->c.obj.iv[9] = local[2];
	argv[0]->c.obj.iv[10] = local[3];
	local[4]= argv[0];
	local[5]= fqv[24];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	w = argv[0];
	local[0]= w;
BLK3522:
	ctx->vsp=local; return(local[0]);}

/*:make-projection*/
static pointer M3527parallel_viewing_make_projection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(4);
	local[1]= makeint(4);
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[28]); /*make-matrix*/
	argv[0]->c.obj.iv[13] = w;
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= makeint(0);
	local[2]= makeint(0);
	local[3]= makeflt(1.00000000e+00);
	local[4]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,4,local+0); /*aset*/
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= makeint(1);
	local[2]= makeint(1);
	local[3]= makeflt(1.00000000e+00);
	local[4]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,4,local+0); /*aset*/
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= makeint(2);
	local[2]= makeint(2);
	local[3]= makeflt(1.00000000e+00);
	local[4]= argv[0]->c.obj.iv[12];
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[11]); x=fltval(local[4]);
		local[4]=(makeflt(x - y));}
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,4,local+0); /*aset*/
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= makeint(2);
	local[2]= makeint(3);
	local[3]= argv[0]->c.obj.iv[11];
	local[4]= argv[0]->c.obj.iv[12];
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[11]); x=fltval(local[4]);
		local[4]=(makeflt(x - y));}
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,1,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,4,local+0); /*aset*/
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= makeint(3);
	local[2]= makeint(3);
	local[3]= makeflt(1.00000000e+00);
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,4,local+0); /*aset*/
	w = argv[0];
	local[0]= w;
BLK3528:
	ctx->vsp=local; return(local[0]);}

/*:ray*/
static pointer M3531perspective_viewing_ray(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[30];
	local[2]= argv[0]->c.obj.iv[9];
	{ double x,y;
		y=fltval(argv[2]); x=fltval(local[2]);
		local[2]=(makeflt(x * y));}
	local[3]= argv[0]->c.obj.iv[10];
	{ double x,y;
		y=fltval(argv[3]); x=fltval(local[3]);
		local[3]=(makeflt(x * y));}
	local[4]= makeflt(-(fltval(argv[0]->c.obj.iv[14])));
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)VNORMALIZE(ctx,1,local+0); /*normalize-vector*/
	local[0]= w;
BLK3532:
	ctx->vsp=local; return(local[0]);}

/*:view-plane*/
static pointer M3533perspective_viewing_view_plane(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3536;}
	local[0]= makeflt(0.00000000e+00);
ENT3536:
ENT3535:
	if (n>3) maerror();
	local[1]= fqv[31];
	local[2]= argv[0];
	local[3]= fqv[32];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= fqv[33];
	local[4]= argv[0];
	local[5]= fqv[23];
	local[6]= makeflt(0.00000000e+00);
	local[7]= makeflt(0.00000000e+00);
	local[8]= local[0];
	local[9]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,3,local+6); /*float-vector*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[3])(ctx,4,local+1,&ftab[3],fqv[34]); /*make-plane*/
	local[0]= w;
BLK3534:
	ctx->vsp=local; return(local[0]);}

/*:make-projection*/
static pointer M3537perspective_viewing_make_projection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeflt(2.00000000e+00);
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[11]); x=fltval(local[0]);
		local[0]=(makeflt(x * y));}
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[14]); x=fltval(local[0]);
		local[0]=(makeflt(x - y));}
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[14]); x=fltval(local[0]);
		local[0]=(makeflt(x * y));}
	local[1]= argv[0]->c.obj.iv[11];
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
	local[1]= makeflt(2.00000000e+00);
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[12]); x=fltval(local[1]);
		local[1]=(makeflt(x * y));}
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[14]); x=fltval(local[1]);
		local[1]=(makeflt(x - y));}
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[14]); x=fltval(local[1]);
		local[1]=(makeflt(x * y));}
	local[2]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= local[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= makeint(4);
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,1,local+5,&ftab[4],fqv[35]); /*unit-matrix*/
	local[3] = w;
	local[5]= local[3];
	local[6]= makeint(2);
	local[7]= makeint(2);
	local[8]= makeflt(2.00000000e+00);
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[3];
	local[6]= makeint(3);
	local[7]= makeint(2);
	local[8]= makeflt(1.00000000e+00);
	local[9]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[3];
	local[6]= makeint(2);
	local[7]= makeint(3);
	local[8]= makeflt(-(fltval(argv[0]->c.obj.iv[14])));
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[3];
	local[6]= makeint(3);
	local[7]= makeint(3);
	local[8]= makeflt(0.00000000e+00);
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= makeint(4);
	local[6]= makeint(4);
	ctx->vsp=local+7;
	w=(*ftab[2])(ctx,2,local+5,&ftab[2],fqv[28]); /*make-matrix*/
	local[4] = w;
	local[5]= local[4];
	local[6]= makeint(0);
	local[7]= makeint(0);
	local[8]= makeflt(1.00000000e+00);
	local[9]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[4];
	local[6]= makeint(1);
	local[7]= makeint(1);
	local[8]= makeflt(1.00000000e+00);
	local[9]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[4];
	local[6]= makeint(2);
	local[7]= makeint(2);
	local[8]= makeflt(1.00000000e+00);
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[4];
	local[6]= makeint(2);
	local[7]= makeint(3);
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,1,local+8); /*-*/
	local[8]= w;
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[4];
	local[6]= makeint(3);
	local[7]= makeint(3);
	local[8]= makeflt(1.00000000e+00);
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[4];
	local[6]= local[3];
	local[7]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+8;
	w=(pointer)MATTIMES(ctx,3,local+5); /*m**/
	local[0]= w;
BLK3538:
	ctx->vsp=local; return(local[0]);}

/*:viewdistance*/
static pointer M3539perspective_viewing_viewdistance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3542;}
	local[0]= NIL;
ENT3542:
ENT3541:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3543;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)EUSFLOAT(ctx,1,local+1); /*float*/
	argv[0]->c.obj.iv[14] = w;
	local[1]= argv[0];
	local[2]= fqv[24];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF3544;
IF3543:
	local[1]= NIL;
IF3544:
	w = argv[0]->c.obj.iv[14];
	local[0]= w;
BLK3540:
	ctx->vsp=local; return(local[0]);}

/*:view-angle*/
static pointer M3545perspective_viewing_view_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3548;}
	local[0]= NIL;
ENT3548:
ENT3547:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3549;
	local[1]= argv[0]->c.obj.iv[10];
	local[2]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[14];
	local[3]= local[0];
	local[4]= makeflt(2.00000000e+00);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)TAN(ctx,1,local+3); /*tan*/
	{ double x,y;
		y=fltval(w); x=fltval(local[2]);
		local[2]=(makeflt(x * y));}
	local[3]= NIL;
	local[4]= local[2];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	local[5]= makeflt(1.00000000e+00);
	local[6]= local[1];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SQRT(ctx,1,local+4); /*sqrt*/
	local[3] = w;
	local[4]= argv[0];
	local[5]= fqv[36];
	local[6]= local[3];
	local[7]= local[3];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[24];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	w = local[0];
	local[1]= w;
	goto IF3550;
IF3549:
	local[1]= makeint(2);
	local[2]= argv[0]->c.obj.iv[9];
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[9]); x=fltval(local[2]);
		local[2]=(makeflt(x * y));}
	local[3]= argv[0]->c.obj.iv[10];
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[10]); x=fltval(local[3]);
		local[3]=(makeflt(x * y));}
	{ double x,y;
		y=fltval(local[3]); x=fltval(local[2]);
		local[2]=(makeflt(x + y));}
	ctx->vsp=local+3;
	w=(pointer)SQRT(ctx,1,local+2); /*sqrt*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+4;
	w=(pointer)ATAN(ctx,2,local+2); /*atan*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
IF3550:
	w = local[1];
	local[0]= w;
BLK3546:
	ctx->vsp=local; return(local[0]);}

/*:fovy*/
static pointer M3551perspective_viewing_fovy(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(2);
	local[1]= argv[0]->c.obj.iv[10];
	local[2]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+3;
	w=(pointer)ATAN(ctx,2,local+1); /*atan*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
BLK3552:
	ctx->vsp=local; return(local[0]);}

/*:zoom*/
static pointer M3553perspective_viewing_zoom(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3556;}
	local[0]= NIL;
ENT3556:
ENT3555:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3557;
	local[1]= argv[0]->c.obj.iv[9];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	argv[0]->c.obj.iv[9] = w;
	local[1]= argv[0]->c.obj.iv[10];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	argv[0]->c.obj.iv[10] = w;
	local[1]= argv[0];
	local[2]= fqv[24];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF3558;
IF3557:
	local[1]= NIL;
IF3558:
	local[1]= argv[0];
	local[2]= fqv[37];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[0]= w;
BLK3554:
	ctx->vsp=local; return(local[0]);}

/*:lookaround*/
static pointer M3559perspective_viewing_lookaround(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= makeint(0);
	local[1]= makeint(0);
	local[2]= argv[0]->c.obj.iv[12];
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[11]); x=fltval(local[2]);
		local[2]=(makeflt(x + y));}
	local[3]= makeflt(2.00000000e+00);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[14];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)VMINUS(ctx,1,local+3); /*v-*/
	local[3]= w;
	local[4]= fqv[38];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[10];
	local[3]= argv[2];
	local[4]= fqv[16];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[10];
	local[3]= argv[3];
	local[4]= fqv[11];
	local[5]= fqv[38];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[14];
	local[3]= local[0];
	local[4]= fqv[38];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK3560:
	ctx->vsp=local; return(local[0]);}

/*:look-body*/
static pointer M3561perspective_viewing_look_body(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3563:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,1,local+1,&ftab[5],fqv[39]); /*flatten*/
	local[0] = w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[40]); /*bounding-box-union*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= local[1];
	local[6]= fqv[41];
	local[7]= makeflt(1.00000000e-01);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[42];
	local[7]= argv[0];
	local[8]= fqv[43];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= local[1];
	local[9]= fqv[44];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= loadglobal(fqv[45]);
	ctx->vsp=local+6;
	w=(pointer)INSTANTIATE(ctx,1,local+5); /*instantiate*/
	local[5]= w;
	local[6]= local[5];
	local[7]= fqv[9];
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,CLO3565,env,argv,local);
	local[9]= local[1];
	local[10]= fqv[46];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MAPCAR(ctx,2,local+8); /*mapcar*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	w = local[5];
	local[1] = w;
	local[5]= local[1];
	local[6]= fqv[47];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)VNORMALIZE(ctx,1,local+5); /*normalize-vector*/
	local[2] = w;
	local[5]= local[1];
	local[6]= fqv[48];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)VNORMALIZE(ctx,1,local+5); /*normalize-vector*/
	local[3] = w;
	local[5]= local[2];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)VINNERPRODUCT(ctx,2,local+5); /*v.*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[7])(ctx,1,local+5,&ftab[7],fqv[49]); /*acos*/
	local[4] = w;
	local[5]= argv[0];
	local[6]= fqv[50];
	local[7]= makeflt(5.00000000e-01);
	local[8]= local[1];
	local[9]= fqv[51];
	local[10]= fqv[52];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	local[9]= makeint(2);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[53];
	local[7]= makeflt(2.00000000e+00);
	local[8]= local[1];
	local[9]= fqv[51];
	local[10]= fqv[54];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	local[9]= makeint(2);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[37];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	w = argv[0];
	local[0]= w;
BLK3562:
	ctx->vsp=local; return(local[0]);}

/*:look-body2*/
static pointer M3566perspective_viewing_look_body2(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3568:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,1,local+1,&ftab[5],fqv[39]); /*flatten*/
	local[0] = w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[40]); /*bounding-box-union*/
	local[1]= w;
	local[2]= fqv[41];
	local[3]= makeflt(1.00000000e-01);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= *(ovafptr(local[1],fqv[55]));
	local[3]= *(ovafptr(local[1],fqv[56]));
	ctx->vsp=local+4;
	w=(pointer)VDISTANCE(ctx,2,local+2); /*distance*/
	local[2]= w;
	local[3]= local[1];
	local[4]= fqv[44];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[43];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)VDISTANCE(ctx,2,local+4); /*distance*/
	local[4]= w;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= argv[0];
	local[9]= fqv[42];
	local[10]= argv[0];
	local[11]= fqv[43];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= makeflt(2.00000000e+00);
	local[9]= local[2];
	local[10]= makeflt(2.00000000e+00);
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)ATAN(ctx,2,local+9); /*atan*/
	{ double x,y;
		y=fltval(w); x=fltval(local[8]);
		local[8]=(makeflt(x * y));}
	local[7] = local[8];
	local[8]= local[2];
	local[9]= local[4];
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,3,local+8); /*list*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)PRINT(ctx,1,local+8); /*print*/
	local[8]= argv[0];
	local[9]= fqv[50];
	local[10]= makeflt(5.00000000e-01);
	local[11]= local[1];
	local[12]= fqv[51];
	local[13]= fqv[57];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[11]= w;
	local[12]= makeint(2);
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,2,local+11); /*aref*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= argv[0];
	local[9]= fqv[53];
	local[10]= makeflt(2.00000000e+00);
	local[11]= local[1];
	local[12]= fqv[51];
	local[13]= fqv[58];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[11]= w;
	local[12]= makeint(2);
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,2,local+11); /*aref*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= argv[0];
	local[9]= fqv[37];
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	w = argv[0];
	local[0]= w;
BLK3567:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M3569perspective_viewing_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3572;}
	local[0]= NIL;
ENT3572:
ENT3571:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[0]));
	local[3]= fqv[59];
	local[4]= argv[2];
	local[5]= NIL;
	local[6]= fqv[60];
	local[7]= argv[0];
	local[8]= fqv[37];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[8])(ctx,1,local+7,&ftab[8],fqv[61]); /*rad2deg*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,3,local+5); /*format*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,6,local+1); /*send-message*/
	local[0]= w;
BLK3570:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3573perspective_viewing_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3575:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[62], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3576;
	local[1] = NIL;
KEY3576:
	if (local[1]==NIL) goto IF3577;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)EUSFLOAT(ctx,1,local+2); /*float*/
	argv[0]->c.obj.iv[14] = w;
	local[2]= argv[0]->c.obj.iv[14];
	goto IF3578;
IF3577:
	if (argv[0]->c.obj.iv[14]!=NIL) goto IF3579;
	argv[0]->c.obj.iv[14] = makeflt(1.00000000e+02);
	local[2]= argv[0]->c.obj.iv[14];
	goto IF3580;
IF3579:
	local[2]= NIL;
IF3580:
IF3578:
	if (argv[0]->c.obj.iv[13]!=NIL) goto IF3581;
	local[2]= makeint(4);
	ctx->vsp=local+3;
	w=(*ftab[4])(ctx,1,local+2,&ftab[4],fqv[35]); /*unit-matrix*/
	argv[0]->c.obj.iv[13] = w;
	local[2]= argv[0]->c.obj.iv[13];
	goto IF3582;
IF3581:
	local[2]= NIL;
IF3582:
	local[2]= (pointer)get_sym_func(fqv[18]);
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[0]));
	local[5]= fqv[9];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,5,local+2); /*apply*/
	w = argv[0];
	local[0]= w;
BLK3574:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3565(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0]->c.obj.iv[8];
	local[1]= fqv[23];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:view-orient*/
static pointer M3583perspective_viewing_view_orient(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3586;}
	local[0]= makeint(0);
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)MKFLTVEC(ctx,2,local+0); /*float-vector*/
	local[0]= w;
ENT3586:
ENT3585:
	if (n>3) maerror();
	local[1]= *(ovafptr(argv[0]->c.obj.iv[8],fqv[63]));
	ctx->vsp=local+2;
	w=(pointer)TRANSPOSE(ctx,1,local+1); /*transpose*/
	local[1]= w;
	local[2]= local[0];
	{ register eusinteger_t i=intval(makeint(0));
	  w=makeflt(local[2]->c.fvec.fv[i]);}
	local[2]= w;
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[9]); x=fltval(local[2]);
		local[2]=(makeflt(x * y));}
	local[3]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	local[3]= local[0];
	{ register eusinteger_t i=intval(makeint(1));
	  w=makeflt(local[3]->c.fvec.fv[i]);}
	local[3]= w;
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[10]); x=fltval(local[3]);
		local[3]=(makeflt(x * y));}
	local[4]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VNORMALIZE(ctx,1,local+2); /*normalize-vector*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)TRANSFORM(ctx,2,local+1); /*transform*/
	local[0]= w;
BLK3584:
	ctx->vsp=local; return(local[0]);}

/*:view-line*/
static pointer M3587perspective_viewing_view_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3590;}
	local[0]= fqv[64];
ENT3590:
ENT3589:
	if (n>3) maerror();
	local[1]= loadglobal(fqv[65]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[9];
	local[4]= argv[0];
	local[5]= fqv[66];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[43];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK3588:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___viewing(ctx,n,argv,env)
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
	local[0]= fqv[67];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF3592;
	local[0]= fqv[68];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[69],w);
	goto IF3593;
IF3592:
	local[0]= fqv[70];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF3593:
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3427viewing_update,fqv[1],fqv[71],fqv[72]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3431viewing_changed,fqv[3],fqv[71],fqv[73]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3433viewing_viewpoint,fqv[43],fqv[71],fqv[74]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3435viewing_view_direction,fqv[32],fqv[71],fqv[75]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3437viewing_view_up,fqv[76],fqv[71],fqv[77]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3439viewing_view_right,fqv[78],fqv[71],fqv[79]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3441viewing_sendviewcoords,fqv[80],fqv[71],fqv[81]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3443viewing_look,fqv[42],fqv[71],fqv[82]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3447viewing_makeviewcoords,fqv[83],fqv[71],fqv[84]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3449viewing_init,fqv[9],fqv[71],fqv[85]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3464projection_projection,fqv[86],fqv[87],fqv[88]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3466projection_newprojection,fqv[89],fqv[87],fqv[90]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3468projection_project,fqv[91],fqv[87],fqv[92]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3470projection_project3,fqv[22],fqv[87],fqv[93]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3472projection_view,fqv[94],fqv[87],fqv[95]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3474projection_screen,fqv[36],fqv[87],fqv[96]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3481projection_hither,fqv[50],fqv[87],fqv[97]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3487projection_yon,fqv[53],fqv[87],fqv[98]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3493projection_aspect,fqv[99],fqv[87],fqv[100]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3499projection_viewreference,fqv[101],fqv[87],fqv[102]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3501projection_make_projection,fqv[24],fqv[87],fqv[103]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3504projection_init,fqv[9],fqv[87],fqv[104]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3513viewing2d_project,fqv[91],fqv[105],fqv[106]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3515viewing2d_project2,fqv[27],fqv[105],fqv[107]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3517viewing2d_view,fqv[94],fqv[105],fqv[108]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3519viewing2d_make_projection,fqv[24],fqv[105],fqv[109]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3521viewing2d_init,fqv[9],fqv[105],fqv[110]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3527parallel_viewing_make_projection,fqv[24],fqv[111],fqv[112]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3531perspective_viewing_ray,fqv[113],fqv[114],fqv[115]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3533perspective_viewing_view_plane,fqv[116],fqv[114],fqv[117]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3537perspective_viewing_make_projection,fqv[24],fqv[114],fqv[118]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3539perspective_viewing_viewdistance,fqv[119],fqv[114],fqv[120]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3545perspective_viewing_view_angle,fqv[37],fqv[114],fqv[121]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3551perspective_viewing_fovy,fqv[122],fqv[114],fqv[123]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3553perspective_viewing_zoom,fqv[124],fqv[114],fqv[125]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3559perspective_viewing_lookaround,fqv[126],fqv[114],fqv[127]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3561perspective_viewing_look_body,fqv[128],fqv[114],fqv[129]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3566perspective_viewing_look_body2,fqv[130],fqv[114],fqv[131]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3569perspective_viewing_prin1,fqv[59],fqv[114],fqv[132]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3573perspective_viewing_init,fqv[9],fqv[114],fqv[133]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3583perspective_viewing_view_orient,fqv[66],fqv[114],fqv[134]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3587perspective_viewing_view_line,fqv[135],fqv[114],fqv[136]);
	local[0]= fqv[137];
	local[1]= fqv[138];
	ctx->vsp=local+2;
	w=(*ftab[9])(ctx,2,local+0,&ftab[9],fqv[139]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<10; i++) ftab[i]=fcallx;
}
