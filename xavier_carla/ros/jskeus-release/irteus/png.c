/* ./png.c :  entry=png */
/* compiled by EusLisp 9.27() for Linux created on ip-10-0-1-214(Fri Apr 16 04:05:26 PST 2021) */
#include "eus.h"
#include "png.h"
#pragma init (register_png)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___png();
extern pointer build_quote_vector();
static int register_png()
  { add_module_initializer("___png", ___png);}

static pointer F98read_png_file();
static pointer F99write_png_file();

/*read-png-file*/
static pointer F98read_png_file(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*probe-file*/
	if (w==NIL) goto IF101;
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,1,local+6,&ftab[1],fqv[1]); /*png-read-image*/
	local[0] = w;
	local[6]= local[0];
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[1] = w;
	local[6]= local[0];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[2] = w;
	local[6]= local[0];
	local[7]= makeint((eusinteger_t)2L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[3] = w;
	local[6]= local[0];
	local[7]= makeint((eusinteger_t)3L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[4] = w;
	local[6]= local[3];
	local[7]= local[6];
	if (fqv[2]!=local[7]) goto IF104;
	local[7]= loadglobal(fqv[3]);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,1,local+7); /*instantiate*/
	local[7]= w;
	local[8]= local[7];
	local[9]= fqv[4];
	local[10]= local[1];
	local[11]= local[2];
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,5,local+8); /*send*/
	w = local[7];
	local[5] = w;
	local[7]= local[5];
	goto IF105;
IF104:
	local[7]= local[6];
	if (fqv[5]!=local[7]) goto IF107;
	local[7]= loadglobal(fqv[6]);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,1,local+7); /*instantiate*/
	local[7]= w;
	local[8]= local[7];
	local[9]= fqv[4];
	local[10]= local[1];
	local[11]= local[2];
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,5,local+8); /*send*/
	w = local[7];
	local[5] = w;
	local[7]= local[5];
	goto IF108;
IF107:
	if (T==NIL) goto IF110;
	local[7]= fqv[7];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)SIGERROR(ctx,2,local+7); /*error*/
	local[7]= w;
	goto IF111;
IF110:
	local[7]= NIL;
IF111:
IF108:
IF105:
	w = local[7];
	local[6]= local[5];
	local[7]= fqv[8];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	w = local[5];
	local[0]= w;
	goto IF102;
IF101:
	local[0]= NIL;
IF102:
	w = local[0];
	local[0]= w;
BLK100:
	ctx->vsp=local; return(local[0]);}

/*write-png-file*/
static pointer F99write_png_file(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[1];
	local[2]= loadglobal(fqv[3]);
	ctx->vsp=local+3;
	w=(pointer)DERIVEDP(ctx,2,local+1); /*derivedp*/
	if (w==NIL) goto CON114;
	local[0] = makeint((eusinteger_t)1L);
	local[1]= local[0];
	goto CON113;
CON114:
	local[1]= argv[1];
	local[2]= loadglobal(fqv[6]);
	ctx->vsp=local+3;
	w=(pointer)DERIVEDP(ctx,2,local+1); /*derivedp*/
	if (w==NIL) goto CON115;
	local[1]= argv[1];
	local[2]= fqv[9];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[0] = w;
	local[1]= local[0];
	goto CON113;
CON115:
	local[1]= fqv[10];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,2,local+1); /*error*/
	local[1]= w;
	goto CON113;
CON116:
	local[1]= NIL;
CON113:
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= fqv[11];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[1];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= local[0];
	local[5]= argv[1];
	local[6]= fqv[13];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[2])(ctx,5,local+1,&ftab[2],fqv[14]); /*png-write-image*/
	local[0]= w;
BLK112:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___png(ctx,n,argv,env)
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
	local[0]= fqv[15];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF117;
	local[0]= fqv[16];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[17],w);
	goto IF118;
IF117:
	local[0]= fqv[18];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF118:
	local[0]= fqv[19];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[20],module,F98read_png_file,fqv[21]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[22],module,F99write_png_file,fqv[23]);
	local[0]= fqv[24];
	local[1]= fqv[25];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,2,local+0,&ftab[3],fqv[26]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<4; i++) ftab[i]=fcallx;
}
