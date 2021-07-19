/* ./readmacro.c :  entry=readmacro */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "readmacro.h"
#pragma init (register_readmacro)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___readmacro();
extern pointer build_quote_vector();
static int register_readmacro()
  { add_module_initializer("___readmacro", ___readmacro);}

static pointer F3232read_backquote();
static pointer F3235conv_bq();
static pointer F3238conscons();
static pointer F3241read_comma();
static pointer F3246read_binary();
static pointer F3249read_bit_vector();
static pointer F3255read_pathname();
static pointer F3259read_radian();
static pointer F3263read_degree();

/*read-backquote*/
static pointer F3232read_backquote(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT3300;}
	local[0]= NIL;
ENT3300:
ENT3299:
	if (n>2) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)READ(ctx,1,local+1); /*read*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F3235conv_bq(ctx,1,local+1); /*conv-bq*/
	local[0]= w;
BLK3297:
	ctx->vsp=local; return(local[0]);}

/*conv-bq*/
static pointer F3235conv_bq(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	if (argv[0]!=NIL) goto CON3333;
	local[0]= NIL;
	goto CON3331;
CON3333:
	w = argv[0];
	if (!!iscons(w)) goto CON3338;
	local[0]= fqv[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	goto CON3331;
CON3338:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!!iscons(w)) goto CON3348;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[1]!=local[0]) goto CON3360;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	goto CON3358;
CON3360:
	local[0]= fqv[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(pointer)F3235conv_bq(ctx,1,local+1); /*conv-bq*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F3238conscons(ctx,2,local+0); /*conscons*/
	local[0]= w;
	goto CON3358;
CON3376:
	local[0]= NIL;
CON3358:
	goto CON3331;
CON3348:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[1]!=local[0]) goto CON3397;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(pointer)F3235conv_bq(ctx,1,local+1); /*conv-bq*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F3238conscons(ctx,2,local+0); /*conscons*/
	local[0]= w;
	goto CON3331;
CON3397:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[2]!=local[0]) goto CON3426;
	local[0]= fqv[3];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	ctx->vsp=local+3;
	w=(pointer)F3235conv_bq(ctx,1,local+2); /*conv-bq*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
	goto CON3331;
CON3426:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	w=(pointer)F3235conv_bq(ctx,1,local+0); /*conv-bq*/
	local[0]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(pointer)F3235conv_bq(ctx,1,local+1); /*conv-bq*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F3238conscons(ctx,2,local+0); /*conscons*/
	local[0]= w;
	goto CON3331;
CON3457:
	local[0]= NIL;
CON3331:
	w = local[0];
	local[0]= w;
BLK3321:
	ctx->vsp=local; return(local[0]);}

/*conscons*/
static pointer F3238conscons(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[1]!=NIL) goto IF3491;
	local[0]= fqv[4];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	goto IF3492;
IF3491:
	local[0]= fqv[5];
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
IF3492:
	w = local[0];
	local[0]= w;
BLK3479:
	ctx->vsp=local; return(local[0]);}

/*read-comma*/
static pointer F3241read_comma(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT3513;}
	local[0]= NIL;
ENT3513:
ENT3512:
	if (n>2) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)PEEKCH(ctx,1,local+1); /*peek-char*/
	local[1]= w;
	if (makeint(64)!=local[1]) goto CON3529;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)READCH(ctx,1,local+1); /*read-char*/
	local[1]= fqv[2];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)READ(ctx,1,local+2); /*read*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto CON3527;
CON3529:
	local[1]= fqv[1];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)READ(ctx,1,local+2); /*read*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto CON3527;
CON3547:
	local[1]= NIL;
CON3527:
	w = local[1];
	local[0]= w;
BLK3510:
	ctx->vsp=local; return(local[0]);}

/*read-binary*/
static pointer F3246read_binary(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeint(0);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)READCH(ctx,1,local+1); /*read-char*/
	argv[1] = w;
WHL3597:
	local[1]= argv[1];
	local[2]= fqv[6];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[7]); /*find*/
	if (w==NIL) goto WHX3598;
	local[1]= local[0];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	local[2]= argv[1];
	local[3]= makeint(48);
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[0] = w;
	local[1]= argv[0];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)READCH(ctx,3,local+1); /*read-char*/
	argv[1] = w;
	goto WHL3597;
WHX3598:
	local[1]= NIL;
BLK3599:
	w = argv[1];
	if (!isint(w)) goto IF3637;
	local[1]= argv[1];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)UNREADCH(ctx,2,local+1); /*unread-char*/
	local[1]= w;
	goto IF3638;
IF3637:
	local[1]= NIL;
IF3638:
	w = local[0];
	local[0]= w;
BLK3564:
	ctx->vsp=local; return(local[0]);}

/*read-bit-vector*/
static pointer F3249read_bit_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= fqv[8];
	local[1]= fqv[9];
	local[2]= fqv[10];
	local[3]= fqv[11];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,5,local+0,&ftab[1],fqv[12]); /*make-array*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)READCH(ctx,1,local+1); /*read-char*/
	argv[1] = w;
WHL3697:
	local[1]= argv[1];
	local[2]= fqv[13];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[7]); /*find*/
	if (w==NIL) goto WHX3698;
	local[1]= argv[1];
	local[2]= makeint(48);
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)VECTOREXPUSH(ctx,2,local+1); /*vector-push-extend*/
	local[1]= argv[0];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)READCH(ctx,3,local+1); /*read-char*/
	argv[1] = w;
	goto WHL3697;
WHX3698:
	local[1]= NIL;
BLK3699:
	w = argv[1];
	if (!isint(w)) goto IF3725;
	local[1]= argv[1];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)UNREADCH(ctx,2,local+1); /*unread-char*/
	local[1]= w;
	goto IF3726;
IF3725:
	local[1]= NIL;
IF3726:
	local[1]= local[0]->c.obj.iv[1];
	local[2]= makeint(0);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[2])(ctx,1,local+3,&ftab[2],fqv[14]); /*fill-pointer*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SUBSEQ(ctx,3,local+1); /*subseq*/
	local[0]= w;
BLK3653:
	ctx->vsp=local; return(local[0]);}

/*read-pathname*/
static pointer F3255read_pathname(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)READ(ctx,1,local+0); /*read*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[3])(ctx,1,local+0,&ftab[3],fqv[15]); /*pathname*/
	local[0]= w;
BLK3756:
	ctx->vsp=local; return(local[0]);}

/*read-radian*/
static pointer F3259read_radian(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)READ(ctx,1,local+0); /*read*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[4])(ctx,1,local+0,&ftab[4],fqv[16]); /*deg2rad*/
	local[0]= w;
BLK3780:
	ctx->vsp=local; return(local[0]);}

/*read-degree*/
static pointer F3263read_degree(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)READ(ctx,1,local+0); /*read*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[5])(ctx,1,local+0,&ftab[5],fqv[17]); /*rad2deg*/
	local[0]= w;
BLK3804:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___readmacro(ctx,n,argv,env)
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
	local[0]= fqv[18];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= fqv[19];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF3835;
	local[0]= fqv[20];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[21],w);
	goto IF3836;
IF3835:
	local[0]= fqv[22];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF3836:
	local[0]= fqv[23];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[24],module,F3232read_backquote,fqv[25]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[26],module,F3235conv_bq,fqv[27]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[28],module,F3238conscons,fqv[29]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[30],module,F3241read_comma,fqv[31]);
	local[0]= makeint(44);
	local[1]= fqv[30];
	ctx->vsp=local+2;
	w=(pointer)SETMACROCH(ctx,2,local+0); /*set-macro-character*/
	local[0]= makeint(96);
	local[1]= fqv[24];
	ctx->vsp=local+2;
	w=(pointer)SETMACROCH(ctx,2,local+0); /*set-macro-character*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[32],module,F3246read_binary,fqv[33]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[34],module,F3249read_bit_vector,fqv[35]);
	local[0]= makeint(35);
	local[1]= makeint(66);
	local[2]= fqv[32];
	ctx->vsp=local+3;
	w=(pointer)SETDISPMACRO(ctx,3,local+0); /*set-dispatch-macro-character*/
	local[0]= makeint(35);
	local[1]= makeint(42);
	local[2]= fqv[34];
	ctx->vsp=local+3;
	w=(pointer)SETDISPMACRO(ctx,3,local+0); /*set-dispatch-macro-character*/
	local[0]= makeint(35);
	local[1]= makeint(33);
	local[2]= makeint(59);
	ctx->vsp=local+3;
	w=(*ftab[6])(ctx,1,local+2,&ftab[6],fqv[36]); /*get-macro-character*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SETDISPMACRO(ctx,3,local+0); /*set-dispatch-macro-character*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[37],module,F3255read_pathname,fqv[38]);
	local[0]= makeint(35);
	local[1]= makeint(80);
	local[2]= fqv[37];
	ctx->vsp=local+3;
	w=(pointer)SETDISPMACRO(ctx,3,local+0); /*set-dispatch-macro-character*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[39],module,F3259read_radian,fqv[40]);
	local[0]= makeint(35);
	local[1]= makeint(68);
	local[2]= fqv[39];
	ctx->vsp=local+3;
	w=(pointer)SETDISPMACRO(ctx,3,local+0); /*set-dispatch-macro-character*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[41],module,F3263read_degree,fqv[42]);
	local[0]= makeint(35);
	local[1]= makeint(82);
	local[2]= fqv[41];
	ctx->vsp=local+3;
	w=(pointer)SETDISPMACRO(ctx,3,local+0); /*set-dispatch-macro-character*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<7; i++) ftab[i]=fcallx;
}
