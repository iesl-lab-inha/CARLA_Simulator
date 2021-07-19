/* ./glutil.c :  entry=glutil */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "glutil.h"
#pragma init (register_glutil)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___glutil();
extern pointer build_quote_vector();
static int register_glutil()
  { add_module_initializer("___glutil", ___glutil);}


/* initializer*/
pointer ___glutil(ctx,n,argv,env)
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
	local[0]= fqv[0];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[1]); /*provide*/
	local[0]= fqv[2];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF101;
	local[0]= fqv[3];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[4],w);
	goto IF102;
IF101:
	local[0]= fqv[5];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF102:
	local[0]= fqv[6];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<1; i++) ftab[i]=fcallx;
}
