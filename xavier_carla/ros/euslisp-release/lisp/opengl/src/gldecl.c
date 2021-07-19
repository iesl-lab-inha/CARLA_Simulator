/* ./gldecl.c :  entry=gldecl */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "gldecl.h"
#pragma init (register_gldecl)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___gldecl();
extern pointer build_quote_vector();
static int register_gldecl()
  { add_module_initializer("___gldecl", ___gldecl);}


/* initializer*/
pointer ___gldecl(ctx,n,argv,env)
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
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w!=NIL) goto IF103;
	local[0]= fqv[1];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[2]); /*make-package*/
	local[0]= w;
	goto IF104;
IF103:
	local[0]= NIL;
IF104:
	local[0]= fqv[3];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF105;
	local[0]= fqv[4];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[5],w);
	goto IF106;
IF105:
	local[0]= fqv[6];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF106:
	local[0]= fqv[7];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[8];
	local[1]= fqv[9];
	local[2]= fqv[8];
	local[3]= fqv[10];
	local[4]= loadglobal(fqv[11]);
	local[5]= fqv[12];
	local[6]= fqv[13];
	local[7]= fqv[14];
	local[8]= NIL;
	local[9]= fqv[15];
	local[10]= NIL;
	local[11]= fqv[16];
	local[12]= makeint(-1);
	local[13]= fqv[17];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[18]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[19];
	local[1]= fqv[9];
	local[2]= fqv[19];
	local[3]= fqv[10];
	local[4]= loadglobal(fqv[20]);
	local[5]= fqv[12];
	local[6]= fqv[21];
	local[7]= fqv[14];
	local[8]= NIL;
	local[9]= fqv[15];
	local[10]= NIL;
	local[11]= fqv[16];
	local[12]= makeint(-1);
	local[13]= fqv[17];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[18]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[22];
	local[1]= fqv[9];
	local[2]= fqv[22];
	local[3]= fqv[10];
	local[4]= loadglobal(fqv[20]);
	local[5]= fqv[12];
	local[6]= fqv[23];
	local[7]= fqv[14];
	local[8]= NIL;
	local[9]= fqv[15];
	local[10]= NIL;
	local[11]= fqv[16];
	local[12]= makeint(-1);
	local[13]= fqv[17];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[18]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[24];
	local[1]= fqv[9];
	local[2]= fqv[24];
	local[3]= fqv[12];
	local[4]= fqv[25];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,3,local+2,&ftab[1],fqv[18]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[26];
	local[1]= fqv[27];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF107;
	local[0]= fqv[26];
	local[1]= fqv[27];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[26];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF109;
	local[0]= fqv[26];
	local[1]= fqv[9];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF110;
IF109:
	local[0]= NIL;
IF110:
	local[0]= fqv[26];
	goto IF108;
IF107:
	local[0]= NIL;
IF108:
	local[0]= fqv[28];
	local[1]= fqv[27];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF111;
	local[0]= fqv[28];
	local[1]= fqv[27];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[28];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF113;
	local[0]= fqv[28];
	local[1]= fqv[9];
	local[2]= makeint(4);
	local[3]= makeint(4);
	ctx->vsp=local+4;
	w=(*ftab[2])(ctx,2,local+2,&ftab[2],fqv[29]); /*make-matrix*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF114;
IF113:
	local[0]= NIL;
IF114:
	local[0]= fqv[28];
	goto IF112;
IF111:
	local[0]= NIL;
IF112:
	local[0]= fqv[30];
	local[1]= fqv[27];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF115;
	local[0]= fqv[30];
	local[1]= fqv[27];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[30];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF117;
	local[0]= fqv[30];
	local[1]= fqv[9];
	local[2]= T;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF118;
IF117:
	local[0]= NIL;
IF118:
	local[0]= fqv[30];
	goto IF116;
IF115:
	local[0]= NIL;
IF116:
	local[0]= fqv[31];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[32];
	local[1]= fqv[33];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,2,local+0,&ftab[3],fqv[34]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<4; i++) ftab[i]=fcallx;
}
