/* ./glforeign.c :  entry=glforeign */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "glforeign.h"
#pragma init (register_glforeign)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___glforeign();
extern pointer build_quote_vector();
static int register_glforeign()
  { add_module_initializer("___glforeign", ___glforeign);}

static pointer F62glmaterialfv();
static pointer F63glgetmaterialfv();
static pointer F64gllightfv();

/*set-function-fv-as-dv*/
static pointer F65(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[0];
	local[1]= fqv[1];
	local[2]= fqv[2];
	local[3]= fqv[3];
	local[4]= NIL;
	local[5]= fqv[4];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,1,local+4,&ftab[0],fqv[5]); /*read-from-string*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[2];
	local[4]= fqv[3];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[1];
	local[3]= fqv[2];
	local[4]= fqv[3];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[2];
	local[5]= fqv[3];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK66:
	ctx->vsp=local; return(local[0]);}

/*glmaterialfv*/
static pointer F62glmaterialfv(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[6]); /*user::dvector2float-bytestring*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[2])(ctx,3,local+1,&ftab[2],fqv[7]); /*glmaterialfv-org*/
	local[0]= w;
BLK67:
	ctx->vsp=local; return(local[0]);}

/*glgetmaterialfv*/
static pointer F63glgetmaterialfv(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[6]); /*user::dvector2float-bytestring*/
	local[0]= w;
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= argv[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[3])(ctx,3,local+2,&ftab[3],fqv[8]); /*glgetmaterialfv-org*/
	local[1] = w;
	local[2]= local[0];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,2,local+2,&ftab[4],fqv[9]); /*user::float-bytestring2dvector*/
	w = local[1];
	local[0]= w;
BLK68:
	ctx->vsp=local; return(local[0]);}

/*gllightfv*/
static pointer F64gllightfv(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[6]); /*user::dvector2float-bytestring*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[5])(ctx,3,local+1,&ftab[5],fqv[10]); /*gllightfv-org*/
	local[0]= w;
BLK69:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___glforeign(ctx,n,argv,env)
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
	local[0]= fqv[11];
	ctx->vsp=local+1;
	w=(*ftab[6])(ctx,1,local+0,&ftab[6],fqv[12]); /*provide*/
	local[0]= fqv[13];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF70;
	local[0]= fqv[14];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[15],w);
	goto IF71;
IF70:
	local[0]= fqv[16];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF71:
	local[0]= fqv[17];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compmacro(ctx,fqv[18],module,F65,fqv[19]);
	local[0]= fqv[20];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[21];
	local[1]= fqv[22];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[20];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[21];
	local[1]= fqv[22];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[23];
	local[1]= fqv[24];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[24];
	local[1]= fqv[25];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[26];
	local[1]= fqv[27];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[27];
	local[1]= fqv[28];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[29];
	local[1]= fqv[30];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[30];
	local[1]= fqv[31];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[32];
	local[1]= fqv[33];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[33];
	local[1]= fqv[34];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[35];
	local[1]= fqv[36];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[36];
	local[1]= fqv[37];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[38];
	local[1]= fqv[39];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[39];
	local[1]= fqv[40];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[41];
	local[1]= fqv[42];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[42];
	local[1]= fqv[43];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[44];
	local[1]= fqv[45];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[45];
	local[1]= fqv[46];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[47];
	local[1]= fqv[48];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[48];
	local[1]= fqv[49];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[50];
	local[1]= fqv[51];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[51];
	local[1]= fqv[52];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[10];
	local[1]= fqv[53];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[8];
	local[1]= fqv[54];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[7];
	local[1]= fqv[55];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[56];
	ctx->vsp=local+1;
	w=(pointer)FBOUNDP(ctx,1,local+0); /*fboundp*/
	if (w!=NIL) goto IF72;
	local[0]= fqv[56];
	local[1]= fqv[57];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= w;
	goto IF73;
IF72:
	local[0]= NIL;
IF73:
	local[0]= fqv[58];
	ctx->vsp=local+1;
	w=(pointer)FBOUNDP(ctx,1,local+0); /*fboundp*/
	if (w!=NIL) goto IF74;
	local[0]= fqv[58];
	local[1]= fqv[59];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= w;
	goto IF75;
IF74:
	local[0]= NIL;
IF75:
	local[0]= fqv[56];
	ctx->vsp=local+1;
	w=(pointer)FBOUNDP(ctx,1,local+0); /*fboundp*/
	if (w==NIL) goto IF76;
	local[0]= fqv[60];
	local[1]= fqv[56];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= w;
	goto IF77;
IF76:
	local[0]= NIL;
IF77:
	ctx->vsp=local+0;
	compfun(ctx,fqv[55],module,F62glmaterialfv,fqv[61]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[54],module,F63glgetmaterialfv,fqv[62]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[53],module,F64gllightfv,fqv[63]);
	local[0]= fqv[60];
	ctx->vsp=local+1;
	w=(pointer)FBOUNDP(ctx,1,local+0); /*fboundp*/
	if (w==NIL) goto IF78;
	local[0]= fqv[56];
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO80,env,argv,local);
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= w;
	goto IF79;
IF78:
	local[0]= NIL;
IF79:
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO80(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(*ftab[7])(ctx,1,local+0,&ftab[7],fqv[64]); /*user::lvector2integer-bytestring*/
	local[0]= w;
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[8])(ctx,2,local+2,&ftab[8],fqv[60]); /*glgentexturesext-org*/
	local[1] = w;
	local[2]= local[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(*ftab[9])(ctx,2,local+2,&ftab[9],fqv[65]); /*user::integer-bytestring2lvector*/
	w = local[1];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<10; i++) ftab[i]=fcallx;
}
