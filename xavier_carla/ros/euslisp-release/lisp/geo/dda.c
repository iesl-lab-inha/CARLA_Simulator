/* ./dda.c :  entry=dda */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "dda.h"
#pragma init (register_dda)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___dda();
extern pointer build_quote_vector();
static int register_dda()
  { add_module_initializer("___dda", ___dda);}

static pointer F4795dda_line();
static pointer F4796dda_ellipse();
static pointer F4797draw_ellipse();

/*:init*/
static pointer M4798dda_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[1] = makeint(0);
	w = argv[0];
	local[0]= w;
BLK4799:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M4800line_dda_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[0]));
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[4];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	argv[0]->c.obj.iv[4] = w;
	local[2]= argv[5];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	argv[0]->c.obj.iv[5] = w;
	local[2]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+3;
	w=(pointer)ABS(ctx,1,local+2); /*abs*/
	local[0] = w;
	local[2]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+3;
	w=(pointer)ABS(ctx,1,local+2); /*abs*/
	local[1] = w;
	argv[0]->c.obj.iv[6] = makeint(0);
	local[2]= makeint(2);
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ABS(ctx,1,local+3); /*abs*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	argv[0]->c.obj.iv[8] = w;
	local[2]= makeint(2);
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)GREATERP(ctx,2,local+3); /*>*/
	if (w==NIL) goto IF4802;
	local[3]= local[1];
	goto IF4803;
IF4802:
	local[3]= local[0];
IF4803:
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	argv[0]->c.obj.iv[7] = w;
	argv[0]->c.obj.iv[2] = argv[2];
	argv[0]->c.obj.iv[3] = argv[3];
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)MAX(ctx,2,local+2); /*max*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	argv[0]->c.obj.iv[10] = w;
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto CON4805;
	local[2]= makeint(2);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	argv[0]->c.obj.iv[6] = w;
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto IF4806;
	local[2]= makeint(1);
	goto IF4807;
IF4806:
	local[2]= makeint(-1);
IF4807:
	argv[0]->c.obj.iv[9] = local[2];
	argv[0]->c.obj.iv[11] = fqv[2];
	local[2]= argv[0]->c.obj.iv[11];
	goto CON4804;
CON4805:
	local[2]= makeint(2);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	argv[0]->c.obj.iv[6] = w;
	local[2]= argv[0]->c.obj.iv[4];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto IF4809;
	local[2]= makeint(1);
	goto IF4810;
IF4809:
	local[2]= makeint(-1);
IF4810:
	argv[0]->c.obj.iv[9] = local[2];
	argv[0]->c.obj.iv[11] = fqv[3];
	local[2]= argv[0]->c.obj.iv[11];
	goto CON4804;
CON4808:
	local[2]= NIL;
CON4804:
	w = local[2];
	w = argv[0];
	local[0]= w;
BLK4801:
	ctx->vsp=local; return(local[0]);}

/*:update-x-major*/
static pointer M4811line_dda_update_x_major(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[6];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto CON4814;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[3] = w;
	local[0]= argv[0]->c.obj.iv[6];
	local[1]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	argv[0]->c.obj.iv[6] = w;
	local[0]= argv[0]->c.obj.iv[6];
	goto CON4813;
CON4814:
	local[0]= argv[0]->c.obj.iv[6];
	local[1]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[6] = w;
	local[0]= argv[0]->c.obj.iv[6];
	goto CON4813;
CON4815:
	local[0]= NIL;
CON4813:
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[4];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)GREATERP(ctx,2,local+1); /*>*/
	if (w==NIL) goto IF4816;
	local[1]= makeint(1);
	goto IF4817;
IF4816:
	local[1]= makeint(-1);
IF4817:
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[2] = w;
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK4812:
	ctx->vsp=local; return(local[0]);}

/*:update-y-major*/
static pointer M4818line_dda_update_y_major(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[6];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto CON4821;
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[2] = w;
	local[0]= argv[0]->c.obj.iv[6];
	local[1]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	argv[0]->c.obj.iv[6] = w;
	local[0]= argv[0]->c.obj.iv[6];
	goto CON4820;
CON4821:
	local[0]= argv[0]->c.obj.iv[6];
	local[1]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[6] = w;
	local[0]= argv[0]->c.obj.iv[6];
	goto CON4820;
CON4822:
	local[0]= NIL;
CON4820:
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= argv[0]->c.obj.iv[5];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)GREATERP(ctx,2,local+1); /*>*/
	if (w==NIL) goto IF4823;
	local[1]= makeint(1);
	goto IF4824;
IF4823:
	local[1]= makeint(-1);
IF4824:
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[3] = w;
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK4819:
	ctx->vsp=local; return(local[0]);}

/*:next*/
static pointer M4825line_dda_next(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	argv[0]->c.obj.iv[1] = w;
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF4827;
	w = NIL;
	ctx->vsp=local+0;
	local[0]=w;
	goto BLK4826;
	goto IF4828;
IF4827:
	local[0]= NIL;
IF4828:
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= argv[0]->c.obj.iv[11];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK4826:
	ctx->vsp=local; return(local[0]);}

/*dda-line*/
static pointer F4795dda_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= loadglobal(fqv[4]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[1];
	local[3]= argv[0];
	local[4]= argv[1];
	local[5]= argv[2];
	local[6]= argv[3];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	w = local[0];
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
WHL4832:
	local[3]= local[0];
	local[4]= fqv[5];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[1] = w;
	if (local[1]==NIL) goto WHX4833;
	local[3]= local[1];
	w = local[2];
	ctx->vsp=local+4;
	local[2] = cons(ctx,local[3],w);
	goto WHL4832;
WHX4833:
	local[3]= NIL;
BLK4834:
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	local[0]= w;
BLK4830:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M4835ellipse_dda_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT4839;}
	local[0]= makeint(0);
ENT4839:
	if (n>=6) { local[1]=(argv[5]); goto ENT4838;}
	local[1]= makeint(0);
ENT4838:
ENT4837:
	if (n>6) maerror();
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[0]));
	local[4]= fqv[1];
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,3,local+2); /*send-message*/
	argv[0]->c.obj.iv[2] = NIL;
	argv[0]->c.obj.iv[3] = local[0];
	argv[0]->c.obj.iv[4] = local[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)EUSFLOAT(ctx,1,local+2); /*float*/
	argv[0]->c.obj.iv[5] = w;
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)EUSFLOAT(ctx,1,local+2); /*float*/
	argv[0]->c.obj.iv[6] = w;
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[6];
	local[4]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	argv[0]->c.obj.iv[7] = w;
	local[2]= makeint(2);
	local[3]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+4;
	w=(pointer)LOG(ctx,1,local+3); /*log*/
	local[3]= w;
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)LOG(ctx,1,local+4); /*log*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)CEILING(ctx,1,local+3); /*ceiling*/
	local[3]= makeint(-(intval(w)));
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,2,local+2,&ftab[0],fqv[6]); /*expt*/
	argv[0]->c.obj.iv[8] = w;
	local[2]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+3;
	w=(pointer)EUSFLOAT(ctx,1,local+2); /*float*/
	argv[0]->c.obj.iv[15] = w;
	argv[0]->c.obj.iv[16] = makeflt(0.00000000e+00);
	local[2]= argv[0]->c.obj.iv[15];
	ctx->vsp=local+3;
	w=(pointer)ROUND(ctx,1,local+2); /*round*/
	argv[0]->c.obj.iv[13] = w;
	local[2]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+3;
	w=(pointer)ROUND(ctx,1,local+2); /*round*/
	argv[0]->c.obj.iv[14] = w;
	argv[0]->c.obj.iv[9] = argv[0]->c.obj.iv[13];
	argv[0]->c.obj.iv[10] = argv[0]->c.obj.iv[14];
	argv[0]->c.obj.iv[12] = makeint(0);
	w = argv[0];
	local[0]= w;
BLK4836:
	ctx->vsp=local; return(local[0]);}

/*:next*/
static pointer M4840ellipse_dda_next(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	argv[0]->c.obj.iv[1] = w;
	local[0]= argv[0]->c.obj.iv[12];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF4842;
	local[0]= argv[0]->c.obj.iv[16];
	local[1]= makeflt(0.00000000e+00);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto IF4842;
	argv[0]->c.obj.iv[2] = T;
	w = NIL;
	ctx->vsp=local+0;
	local[0]=w;
	goto BLK4841;
	goto IF4843;
IF4842:
	local[0]= NIL;
IF4843:
	argv[0]->c.obj.iv[11] = argv[0]->c.obj.iv[15];
	argv[0]->c.obj.iv[12] = argv[0]->c.obj.iv[16];
	local[0]= argv[0]->c.obj.iv[11];
	local[1]= argv[0]->c.obj.iv[8];
	local[2]= argv[0]->c.obj.iv[7];
	local[3]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,3,local+1); /***/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	argv[0]->c.obj.iv[15] = w;
	local[0]= argv[0]->c.obj.iv[12];
	local[1]= argv[0]->c.obj.iv[8];
	local[2]= argv[0]->c.obj.iv[15];
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[16] = w;
	local[0]= argv[0]->c.obj.iv[15];
	ctx->vsp=local+1;
	w=(pointer)ROUND(ctx,1,local+0); /*round*/
	argv[0]->c.obj.iv[13] = w;
	local[0]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+1;
	w=(pointer)ROUND(ctx,1,local+0); /*round*/
	argv[0]->c.obj.iv[14] = w;
	local[0]= argv[0]->c.obj.iv[9];
	local[1]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[7]); /*/=*/
	if (w!=NIL) goto OR4846;
	local[0]= argv[0]->c.obj.iv[10];
	local[1]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[7]); /*/=*/
	if (w!=NIL) goto OR4846;
	goto CON4845;
OR4846:
	argv[0]->c.obj.iv[9] = argv[0]->c.obj.iv[13];
	argv[0]->c.obj.iv[10] = argv[0]->c.obj.iv[14];
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[4];
	local[2]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	goto CON4844;
CON4845:
	local[0]= argv[0];
	local[1]= fqv[5];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto CON4844;
CON4847:
	local[0]= NIL;
CON4844:
	w = local[0];
	local[0]= w;
BLK4841:
	ctx->vsp=local; return(local[0]);}

/*dda-ellipse*/
static pointer F4796dda_ellipse(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)EUSFLOAT(ctx,1,local+12); /*float*/
	argv[0] = w;
	local[12]= argv[1];
	ctx->vsp=local+13;
	w=(pointer)EUSFLOAT(ctx,1,local+12); /*float*/
	argv[1] = w;
	local[12]= argv[1];
	local[13]= argv[1];
	ctx->vsp=local+14;
	w=(pointer)TIMES(ctx,2,local+12); /***/
	local[12]= w;
	local[13]= argv[0];
	local[14]= argv[0];
	ctx->vsp=local+15;
	w=(pointer)TIMES(ctx,2,local+13); /***/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)QUOTIENT(ctx,2,local+12); /*/*/
	local[9] = w;
	local[12]= makeflt(1.00000000e+00);
	local[13]= local[9];
	ctx->vsp=local+14;
	w=(pointer)QUOTIENT(ctx,2,local+12); /*/*/
	local[10] = w;
	local[12]= makeint(2);
	local[13]= argv[1];
	ctx->vsp=local+14;
	w=(pointer)LOG(ctx,1,local+13); /*log*/
	local[13]= w;
	local[14]= makeint(2);
	ctx->vsp=local+15;
	w=(pointer)LOG(ctx,1,local+14); /*log*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)QUOTIENT(ctx,2,local+13); /*/*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)CEILING(ctx,1,local+13); /*ceiling*/
	local[13]= makeint(-(intval(w)));
	ctx->vsp=local+14;
	w=(*ftab[0])(ctx,2,local+12,&ftab[0],fqv[6]); /*expt*/
	local[8] = w;
	local[12]= local[8];
	local[13]= local[9];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,2,local+12); /*list*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)PRINT(ctx,1,local+12); /*print*/
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)EUSFLOAT(ctx,1,local+12); /*float*/
	local[2] = w;
	local[3] = makeflt(0.00000000e+00);
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)ROUND(ctx,1,local+12); /*round*/
	local[6] = w;
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)ROUND(ctx,1,local+12); /*round*/
	local[7] = w;
	local[4] = local[6];
	local[5] = local[7];
TAG4849:
	local[0] = local[2];
	local[1] = local[3];
	local[12]= local[0];
	local[13]= local[8];
	local[14]= local[10];
	local[15]= local[1];
	ctx->vsp=local+16;
	w=(pointer)TIMES(ctx,3,local+13); /***/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)MINUS(ctx,2,local+12); /*-*/
	local[2] = w;
	local[12]= local[1];
	local[13]= local[8];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)TIMES(ctx,2,local+13); /***/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,2,local+12); /*+*/
	local[3] = w;
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)ROUND(ctx,1,local+12); /*round*/
	local[6] = w;
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)ROUND(ctx,1,local+12); /*round*/
	local[7] = w;
	local[12]= local[4];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(*ftab[1])(ctx,2,local+12,&ftab[1],fqv[7]); /*/=*/
	if (w!=NIL) goto OR4852;
	local[12]= local[5];
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(*ftab[1])(ctx,2,local+12,&ftab[1],fqv[7]); /*/=*/
	if (w!=NIL) goto OR4852;
	goto IF4850;
OR4852:
	local[4] = local[6];
	local[5] = local[7];
	local[12]= local[4];
	local[13]= local[5];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,2,local+12); /*list*/
	local[12]= w;
	w = local[11];
	ctx->vsp=local+13;
	local[11] = cons(ctx,local[12],w);
	local[12]= local[4];
	local[13]= local[5];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,2,local+12); /*list*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)PRINT(ctx,1,local+12); /*print*/
	local[12]= w;
	goto IF4851;
IF4850:
	local[12]= NIL;
IF4851:
	local[12]= local[1];
	local[13]= makeint(0);
	ctx->vsp=local+14;
	w=(pointer)LESSP(ctx,2,local+12); /*<*/
	if (w==NIL) goto AND4855;
	local[12]= local[3];
	local[13]= makeint(0);
	ctx->vsp=local+14;
	w=(pointer)GREQP(ctx,2,local+12); /*>=*/
	if (w==NIL) goto AND4855;
	goto IF4853;
AND4855:
	ctx->vsp=local+12;
	goto TAG4849;
	goto IF4854;
IF4853:
	local[12]= NIL;
IF4854:
	w = T;
	local[0]= w;
BLK4848:
	ctx->vsp=local; return(local[0]);}

/*draw-ellipse*/
static pointer F4797draw_ellipse(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT4858;}
	local[0]= loadglobal(fqv[8]);
ENT4858:
ENT4857:
	if (n>5) maerror();
	local[1]= loadglobal(fqv[9]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[1];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= argv[0];
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	w = local[1];
	local[1]= w;
	local[2]= NIL;
	w = local[1];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[10],w);
WHL4860:
	local[6]= loadglobal(fqv[10]);
	local[7]= fqv[5];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[2] = w;
	if (local[2]==NIL) goto WHX4861;
	local[6]= local[0];
	local[7]= fqv[11];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	goto WHL4860;
WHX4861:
	local[6]= NIL;
BLK4862:
	local[6]= local[0];
	local[7]= fqv[12];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	unbindx(ctx,1);
	w = local[6];
	local[0]= w;
BLK4856:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___dda(ctx,n,argv,env)
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
	local[0]= fqv[13];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[10];
	local[1]= fqv[14];
	local[2]= fqv[10];
	local[3]= fqv[15];
	local[4]= loadglobal(fqv[16]);
	local[5]= fqv[17];
	local[6]= fqv[18];
	local[7]= fqv[19];
	local[8]= NIL;
	local[9]= fqv[20];
	local[10]= NIL;
	local[11]= fqv[21];
	local[12]= makeint(-1);
	local[13]= fqv[22];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[2])(ctx,13,local+2,&ftab[2],fqv[23]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[4];
	local[1]= fqv[14];
	local[2]= fqv[4];
	local[3]= fqv[15];
	local[4]= loadglobal(fqv[10]);
	local[5]= fqv[17];
	local[6]= fqv[24];
	local[7]= fqv[19];
	local[8]= NIL;
	local[9]= fqv[20];
	local[10]= NIL;
	local[11]= fqv[21];
	local[12]= makeint(-1);
	local[13]= fqv[22];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[2])(ctx,13,local+2,&ftab[2],fqv[23]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[9];
	local[1]= fqv[14];
	local[2]= fqv[9];
	local[3]= fqv[15];
	local[4]= loadglobal(fqv[10]);
	local[5]= fqv[17];
	local[6]= fqv[25];
	local[7]= fqv[19];
	local[8]= NIL;
	local[9]= fqv[20];
	local[10]= NIL;
	local[11]= fqv[21];
	local[12]= makeint(-1);
	local[13]= fqv[22];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[2])(ctx,13,local+2,&ftab[2],fqv[23]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[26];
	local[1]= fqv[14];
	local[2]= fqv[26];
	local[3]= fqv[15];
	local[4]= loadglobal(fqv[9]);
	local[5]= fqv[17];
	local[6]= fqv[27];
	local[7]= fqv[19];
	local[8]= NIL;
	local[9]= fqv[20];
	local[10]= NIL;
	local[11]= fqv[21];
	local[12]= makeint(-1);
	local[13]= fqv[22];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[2])(ctx,13,local+2,&ftab[2],fqv[23]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4798dda_init,fqv[1],fqv[10],fqv[28]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4800line_dda_init,fqv[1],fqv[4],fqv[29]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4811line_dda_update_x_major,fqv[2],fqv[4],fqv[30]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4818line_dda_update_y_major,fqv[3],fqv[4],fqv[31]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4825line_dda_next,fqv[5],fqv[4],fqv[32]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[33],module,F4795dda_line,fqv[34]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4835ellipse_dda_init,fqv[1],fqv[9],fqv[35]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4840ellipse_dda_next,fqv[5],fqv[9],fqv[36]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[37],module,F4796dda_ellipse,fqv[38]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[39],module,F4797draw_ellipse,fqv[40]);
	local[0]= fqv[41];
	local[1]= fqv[42];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,2,local+0,&ftab[3],fqv[43]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<4; i++) ftab[i]=fcallx;
}
