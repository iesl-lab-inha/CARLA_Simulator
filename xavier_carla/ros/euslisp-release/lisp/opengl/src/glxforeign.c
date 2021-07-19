/* ./glxforeign.c :  entry=glxforeign */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "glxforeign.h"
#pragma init (register_glxforeign)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___glxforeign();
extern pointer build_quote_vector();
static int register_glxforeign()
  { add_module_initializer("___glxforeign", ___glxforeign);}

static pointer F91glxchoosevisual();

/*glxchoosevisual*/
static pointer F91glxchoosevisual(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= (pointer)get_sym_func(fqv[0]);
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,1,local+3,&ftab[0],fqv[1]); /*user::lvector2integer-bytestring*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)FUNCALL(ctx,4,local+0); /*funcall*/
	local[0]= w;
BLK92:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___glxforeign(ctx,n,argv,env)
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
	local[0]= fqv[2];
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[3]); /*provide*/
	local[0]= fqv[4];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF93;
	local[0]= fqv[5];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[6],w);
	goto IF94;
IF93:
	local[0]= fqv[7];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF94:
	local[0]= fqv[8];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[0];
	local[1]= fqv[9];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*lisp::setfunc*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[9],module,F91glxchoosevisual,fqv[10]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<2; i++) ftab[i]=fcallx;
}
