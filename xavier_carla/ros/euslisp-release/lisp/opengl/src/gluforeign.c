/* ./gluforeign.c :  entry=gluforeign */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "gluforeign.h"
#pragma init (register_gluforeign)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___gluforeign();
extern pointer build_quote_vector();
static int register_gluforeign()
  { add_module_initializer("___gluforeign", ___gluforeign);}

static pointer F83glunurbscurve();
static pointer F84glunurbssurface();

/*glunurbscurve*/
static pointer F83glunurbscurve(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=7) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*user::dvector2float-bytestring*/
	local[0]= w;
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[0]); /*user::dvector2float-bytestring*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= argv[1];
	local[4]= local[0];
	local[5]= argv[3];
	local[6]= local[1];
	local[7]= argv[5];
	local[8]= argv[6];
	ctx->vsp=local+9;
	w=(*ftab[1])(ctx,7,local+2,&ftab[1],fqv[1]); /*glunurbscurve-org*/
	local[0]= w;
BLK85:
	ctx->vsp=local; return(local[0]);}

/*glunurbssurface*/
static pointer F84glunurbssurface(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=11) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*user::dvector2float-bytestring*/
	local[0]= w;
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[0]); /*user::dvector2float-bytestring*/
	local[1]= w;
	local[2]= argv[7];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,1,local+2,&ftab[0],fqv[0]); /*user::dvector2float-bytestring*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= argv[1];
	local[5]= local[0];
	local[6]= argv[3];
	local[7]= local[1];
	local[8]= argv[5];
	local[9]= argv[6];
	local[10]= local[2];
	local[11]= argv[8];
	local[12]= argv[9];
	local[13]= argv[10];
	ctx->vsp=local+14;
	w=(*ftab[2])(ctx,11,local+3,&ftab[2],fqv[2]); /*glunurbssurface-org*/
	local[0]= w;
BLK86:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___gluforeign(ctx,n,argv,env)
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
	local[0]= fqv[3];
	ctx->vsp=local+1;
	w=(*ftab[3])(ctx,1,local+0,&ftab[3],fqv[4]); /*provide*/
	local[0]= fqv[5];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF87;
	local[0]= fqv[6];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[7],w);
	goto IF88;
IF87:
	local[0]= fqv[8];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF88:
	local[0]= fqv[9];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[10];
	local[1]= fqv[11];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[11];
	local[1]= fqv[12];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[1];
	local[1]= fqv[13];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	local[0]= fqv[2];
	local[1]= fqv[14];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[13],module,F83glunurbscurve,fqv[15]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[14],module,F84glunurbssurface,fqv[16]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<4; i++) ftab[i]=fcallx;
}
