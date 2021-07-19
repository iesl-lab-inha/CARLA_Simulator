/* ./glprim.c :  entry=glprim */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "glprim.h"
#pragma init (register_glprim)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___glprim();
extern pointer build_quote_vector();
static int register_glprim()
  { add_module_initializer("___glprim", ___glprim);}

static pointer F119draw_face();
static pointer F120draw_body();

/*draw-face*/
static pointer F119draw_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[0];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= argv[0];
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO122,env,argv,local);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	if (w==NIL) goto CON124;
	local[3]= argv[0];
	local[4]= fqv[3];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	if (w!=NIL) goto CON124;
	local[3]= makeint(9);
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,1,local+3,&ftab[0],fqv[4]); /*glbegin*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(*ftab[1])(ctx,1,local+3,&ftab[1],fqv[5]); /*glnormal3fv*/
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO125,env,argv,local);
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)MAPC(ctx,2,local+3); /*mapc*/
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,0,local+3,&ftab[2],fqv[6]); /*glend*/
	local[3]= w;
	goto CON123;
CON124:
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,FLET127,env,argv,local);
	local[4]= argv[0];
	local[5]= fqv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[3];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)MAPCAR(ctx,2,local+5); /*mapcar*/
	local[5]= w;
	local[6]= loadglobal(fqv[7]);
	ctx->vsp=local+7;
	w=(*ftab[3])(ctx,1,local+6,&ftab[3],fqv[8]); /*glubeginpolygon*/
	local[6]= loadglobal(fqv[7]);
	local[7]= makeint(100123);
	ctx->vsp=local+8;
	w=(*ftab[4])(ctx,2,local+6,&ftab[4],fqv[9]); /*glunextcontour*/
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,1,local+6,&ftab[1],fqv[5]); /*glnormal3fv*/
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO128,env,argv,local);
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)MAPC(ctx,2,local+6); /*mapc*/
	if (local[4]==NIL) goto IF129;
	local[6]= NIL;
	local[7]= local[4];
WHL132:
	if (local[7]==NIL) goto WHX133;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	local[9]= fqv[0];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.cdr;
	ctx->vsp=local+9;
	local[9]= makeclosure(codevec,quotevec,CLO136,env,argv,local);
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)MAPCAR(ctx,2,local+9); /*mapcar*/
	local[9]= w;
	local[10]= local[3];
	local[11]= local[9];
	ctx->vsp=local+12;
	w=(pointer)MAPCAR(ctx,2,local+10); /*mapcar*/
	local[10]= w;
	local[11]= loadglobal(fqv[7]);
	local[12]= makeint(100122);
	ctx->vsp=local+13;
	w=(*ftab[4])(ctx,2,local+11,&ftab[4],fqv[9]); /*glunextcontour*/
	ctx->vsp=local+11;
	local[11]= makeclosure(codevec,quotevec,CLO137,env,argv,local);
	local[12]= local[10];
	ctx->vsp=local+13;
	w=(pointer)MAPC(ctx,2,local+11); /*mapc*/
	local[11]= local[5];
	local[12]= local[10];
	ctx->vsp=local+13;
	w=(pointer)NCONC(ctx,2,local+11); /*nconc*/
	goto WHL132;
WHX133:
	local[8]= NIL;
BLK134:
	w = NIL;
	local[6]= w;
	goto IF130;
IF129:
	local[6]= NIL;
IF130:
	local[6]= loadglobal(fqv[7]);
	ctx->vsp=local+7;
	w=(*ftab[5])(ctx,1,local+6,&ftab[5],fqv[10]); /*gluendpolygon*/
	local[6]= (pointer)get_sym_func(fqv[11]);
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)MAPC(ctx,2,local+6); /*mapc*/
	local[3]= w;
	goto CON123;
CON126:
	local[3]= NIL;
CON123:
	w = local[3];
	local[0]= w;
BLK121:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO122(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	if (env->c.clo.env1[1]==NIL) goto IF138;
	local[1]= argv[0];
	local[2]= env->c.clo.env2[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[1]= w;
	local[2]= env->c.clo.env1[1];
	ctx->vsp=local+3;
	w=(*ftab[6])(ctx,2,local+1,&ftab[6],fqv[12]); /*gethash*/
	local[1]= w;
	goto IF139;
IF138:
	local[1]= NIL;
IF139:
	if (env->c.clo.env1[2]==NIL) goto IF140;
	local[2]= argv[0];
	local[3]= env->c.clo.env2[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	local[3]= env->c.clo.env1[2];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,2,local+2,&ftab[6],fqv[12]); /*gethash*/
	local[2]= w;
	goto IF141;
IF140:
	local[2]= NIL;
IF141:
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO125(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto IF142;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	w=(*ftab[7])(ctx,1,local+0,&ftab[7],fqv[13]); /*gltexcoord2fv*/
	local[0]= w;
	goto IF143;
IF142:
	local[0]= NIL;
IF143:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto IF144;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[5]); /*glnormal3fv*/
	local[0]= w;
	goto IF145;
IF144:
	local[0]= NIL;
IF145:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	w=(*ftab[8])(ctx,1,local+0,&ftab[8],fqv[14]); /*glvertex3fv*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET127(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto CON147;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto CON147;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= makeint(1);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= makeint(1);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(*ftab[9])(ctx,5,local+0,&ftab[9],fqv[15]); /*alloctessinfo*/
	local[0]= w;
	goto CON146;
CON147:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto CON148;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= makeint(1);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= makeint(0);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(*ftab[9])(ctx,5,local+0,&ftab[9],fqv[15]); /*alloctessinfo*/
	local[0]= w;
	goto CON146;
CON148:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto CON149;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= makeint(0);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= makeint(1);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(*ftab[9])(ctx,5,local+0,&ftab[9],fqv[15]); /*alloctessinfo*/
	local[0]= w;
	goto CON146;
CON149:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= makeint(0);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= makeint(0);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(*ftab[9])(ctx,5,local+0,&ftab[9],fqv[15]); /*alloctessinfo*/
	local[0]= w;
	goto CON146;
CON150:
	local[0]= NIL;
CON146:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO128(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[7]);
	local[1]= argv[0];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[10])(ctx,3,local+0,&ftab[10],fqv[16]); /*glutessvertex*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO136(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	if (env->c.clo.env1[1]==NIL) goto IF151;
	local[1]= argv[0];
	local[2]= env->c.clo.env2[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[1]= w;
	local[2]= env->c.clo.env1[1];
	ctx->vsp=local+3;
	w=(*ftab[6])(ctx,2,local+1,&ftab[6],fqv[12]); /*gethash*/
	local[1]= w;
	goto IF152;
IF151:
	local[1]= NIL;
IF152:
	if (env->c.clo.env1[2]==NIL) goto IF153;
	local[2]= argv[0];
	local[3]= env->c.clo.env2[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	local[3]= env->c.clo.env1[2];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,2,local+2,&ftab[6],fqv[12]); /*gethash*/
	local[2]= w;
	goto IF154;
IF153:
	local[2]= NIL;
IF154:
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO137(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[7]);
	local[1]= argv[0];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[10])(ctx,3,local+0,&ftab[10],fqv[16]); /*glutessvertex*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*draw-body*/
static pointer F120draw_body(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= fqv[17];
	ctx->vsp=local+2;
	w=(pointer)GETPROP(ctx,2,local+0); /*get*/
	local[0]= w;
	local[1]= argv[1];
	local[2]= fqv[18];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[1]= w;
	local[2]= argv[1];
	local[3]= fqv[19];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	local[3]= argv[1];
	local[4]= fqv[20];
	ctx->vsp=local+5;
	w=(pointer)GETPROP(ctx,2,local+3); /*get*/
	local[3]= w;
	local[4]= argv[1];
	local[5]= fqv[21];
	ctx->vsp=local+6;
	w=(pointer)GETPROP(ctx,2,local+4); /*get*/
	local[4]= w;
	local[5]= local[3];
	local[6]= loadglobal(fqv[22]);
	ctx->vsp=local+7;
	w=(pointer)DERIVEDP(ctx,2,local+5); /*derivedp*/
	if (w==NIL) goto CON157;
	local[5]= local[3];
	local[6]= fqv[23];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	goto CON156;
CON157:
	local[5]= local[4];
	local[6]= loadglobal(fqv[22]);
	ctx->vsp=local+7;
	w=(pointer)DERIVEDP(ctx,2,local+5); /*derivedp*/
	if (w==NIL) goto CON158;
	local[5]= local[4];
	local[6]= fqv[23];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	goto CON156;
CON158:
	local[5]= local[4];
	ctx->vsp=local+6;
	w=(*ftab[11])(ctx,1,local+5,&ftab[11],fqv[24]); /*float-vector-p*/
	if (w==NIL) goto CON159;
	local[5]= makeint(1032);
	local[6]= makeint(4608);
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(*ftab[12])(ctx,3,local+5,&ftab[12],fqv[25]); /*glmaterialfv*/
	local[5]= makeint(1032);
	local[6]= makeint(4609);
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(*ftab[12])(ctx,3,local+5,&ftab[12],fqv[25]); /*glmaterialfv*/
	local[5]= makeint(1032);
	local[6]= makeint(4610);
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(*ftab[12])(ctx,3,local+5,&ftab[12],fqv[25]); /*glmaterialfv*/
	local[5]= w;
	goto CON156;
CON159:
	local[5]= NIL;
CON156:
	if (local[0]==NIL) goto CON161;
	local[5]= argv[1];
	local[6]= fqv[26];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= fqv[27];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[13])(ctx,0,local+6,&ftab[13],fqv[28]); /*glpushmatrix*/
	local[6]= local[5];
	local[7]= loadglobal(fqv[29]);
	ctx->vsp=local+8;
	w=(pointer)TRANSPOSE(ctx,2,local+6); /*transpose*/
	local[6]= w->c.obj.iv[1];
	ctx->vsp=local+7;
	w=(*ftab[14])(ctx,1,local+6,&ftab[14],fqv[30]); /*glmultmatrixf*/
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[15])(ctx,1,local+6,&ftab[15],fqv[31]); /*glcalllist*/
	ctx->vsp=local+6;
	w=(*ftab[16])(ctx,0,local+6,&ftab[16],fqv[32]); /*glpopmatrix*/
	local[5]= w;
	goto CON160;
CON161:
	if (local[1]==NIL) goto CON162;
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(*ftab[17])(ctx,1,local+5,&ftab[17],fqv[33]); /*glgenlists*/
	local[5]= w;
	local[6]= argv[1];
	local[7]= fqv[26];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= fqv[34];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= argv[1];
	local[8]= fqv[35];
	ctx->vsp=local+9;
	w=(pointer)GETPROP(ctx,2,local+7); /*get*/
	local[7]= w;
	local[8]= argv[1];
	local[9]= fqv[36];
	ctx->vsp=local+10;
	w=(pointer)GETPROP(ctx,2,local+8); /*get*/
	local[8]= w;
	local[8]= ((fqv[37])==(local[8])?T:NIL);
	local[9]= fqv[38];
	ctx->vsp=local+10;
	w=(*ftab[18])(ctx,1,local+9,&ftab[18],fqv[39]); /*probe-extension*/
	if (w==NIL) goto IF163;
	local[9]= makeint(1);
	local[10]= fqv[40];
	local[11]= fqv[41];
	ctx->vsp=local+12;
	w=(*ftab[19])(ctx,3,local+9,&ftab[19],fqv[42]); /*make-array*/
	local[9]= w;
	local[10]= makeint(1);
	local[11]= local[9];
	ctx->vsp=local+12;
	w=(*ftab[20])(ctx,2,local+10,&ftab[20],fqv[43]); /*glgentexturesext*/
	local[10]= local[9];
	local[11]= makeint(0);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,2,local+10); /*aref*/
	local[9]= w;
	goto IF164;
IF163:
	local[9]= NIL;
IF164:
	local[10]= fqv[38];
	ctx->vsp=local+11;
	w=(*ftab[18])(ctx,1,local+10,&ftab[18],fqv[39]); /*probe-extension*/
	if (w==NIL) goto IF165;
	local[10]= makeint(3553);
	local[11]= local[9];
	ctx->vsp=local+12;
	w=(*ftab[21])(ctx,2,local+10,&ftab[21],fqv[44]); /*glbindtextureext*/
	local[10]= w;
	goto IF166;
IF165:
	local[10]= NIL;
IF166:
	local[10]= makeint(3317);
	local[11]= makeint(1);
	ctx->vsp=local+12;
	w=(*ftab[22])(ctx,2,local+10,&ftab[22],fqv[45]); /*glpixelstorei*/
	local[10]= makeint(3553);
	local[11]= makeint(10242);
	local[12]= makeint(10497);
	ctx->vsp=local+13;
	w=(*ftab[23])(ctx,3,local+10,&ftab[23],fqv[46]); /*gltexparameteri*/
	local[10]= makeint(3553);
	local[11]= makeint(10243);
	local[12]= makeint(10497);
	ctx->vsp=local+13;
	w=(*ftab[23])(ctx,3,local+10,&ftab[23],fqv[46]); /*gltexparameteri*/
	local[10]= makeint(3553);
	local[11]= makeint(10240);
	local[12]= makeint(9728);
	ctx->vsp=local+13;
	w=(*ftab[23])(ctx,3,local+10,&ftab[23],fqv[46]); /*gltexparameteri*/
	local[10]= makeint(3553);
	local[11]= makeint(10241);
	local[12]= makeint(9728);
	ctx->vsp=local+13;
	w=(*ftab[23])(ctx,3,local+10,&ftab[23],fqv[46]); /*gltexparameteri*/
	local[10]= makeint(8960);
	local[11]= makeint(8704);
	local[12]= makeint(8448);
	ctx->vsp=local+13;
	w=(*ftab[24])(ctx,3,local+10,&ftab[24],fqv[47]); /*gltexenvi*/
	local[10]= argv[1];
	local[11]= fqv[48];
	ctx->vsp=local+12;
	w=(pointer)GETPROP(ctx,2,local+10); /*get*/
	local[10]= w;
	local[11]= argv[1];
	local[12]= fqv[18];
	ctx->vsp=local+13;
	w=(pointer)GETPROP(ctx,2,local+11); /*get*/
	local[11]= w;
	local[12]= argv[1];
	local[13]= fqv[49];
	ctx->vsp=local+14;
	w=(pointer)GETPROP(ctx,2,local+12); /*get*/
	local[12]= w;
	local[13]= argv[1];
	local[14]= fqv[50];
	ctx->vsp=local+15;
	w=(pointer)GETPROP(ctx,2,local+13); /*get*/
	local[13]= w;
	local[14]= argv[1];
	local[15]= fqv[51];
	ctx->vsp=local+16;
	w=(pointer)GETPROP(ctx,2,local+14); /*get*/
	local[14]= w;
	if (local[10]!=NIL) goto IF167;
	local[15]= NIL;
	local[16]= fqv[52];
	local[17]= local[11];
	ctx->vsp=local+18;
	w=(pointer)XFORMAT(ctx,3,local+15); /*format*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(*ftab[25])(ctx,1,local+15,&ftab[25],fqv[53]); /*warn*/
	local[15]= local[11];
	ctx->vsp=local+16;
	w=(*ftab[26])(ctx,1,local+15,&ftab[26],fqv[54]); /*load-texture-file*/
	local[15]= w;
	local[16]= argv[1];
	local[17]= local[15];
	local[18]= fqv[55];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
	local[18]= fqv[49];
	ctx->vsp=local+19;
	w=(pointer)PUTPROP(ctx,3,local+16); /*putprop*/
	local[16]= argv[1];
	local[17]= local[15];
	local[18]= fqv[56];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
	local[18]= fqv[50];
	ctx->vsp=local+19;
	w=(pointer)PUTPROP(ctx,3,local+16); /*putprop*/
	local[16]= argv[1];
	local[17]= local[15];
	local[18]= fqv[57];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
	local[18]= fqv[51];
	ctx->vsp=local+19;
	w=(pointer)PUTPROP(ctx,3,local+16); /*putprop*/
	local[16]= argv[1];
	local[17]= local[15];
	local[18]= fqv[58];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
	local[18]= fqv[48];
	ctx->vsp=local+19;
	w=(pointer)PUTPROP(ctx,3,local+16); /*putprop*/
	local[16]= local[15];
	local[17]= fqv[55];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,2,local+16); /*send*/
	local[12] = w;
	local[16]= local[15];
	local[17]= fqv[56];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,2,local+16); /*send*/
	local[13] = w;
	local[16]= local[15];
	local[17]= fqv[57];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,2,local+16); /*send*/
	local[14] = w;
	local[16]= local[15];
	local[17]= fqv[58];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,2,local+16); /*send*/
	local[10] = w;
	w = local[10];
	local[15]= w;
	goto IF168;
IF167:
	local[15]= NIL;
IF168:
	local[15]= makeint(3553);
	local[16]= makeint(0);
	local[17]= local[14];
	local[18]= local[12];
	local[19]= local[13];
	local[20]= makeint(0);
	local[21]= local[14];
	local[22]= makeint(3);
	ctx->vsp=local+23;
	w=(pointer)NUMEQUAL(ctx,2,local+21); /*=*/
	if (w==NIL) goto IF169;
	local[21]= makeint(6407);
	goto IF170;
IF169:
	local[21]= makeint(6409);
IF170:
	local[22]= makeint(5121);
	local[23]= local[10];
	ctx->vsp=local+24;
	w=(*ftab[27])(ctx,9,local+15,&ftab[27],fqv[59]); /*glteximage2d*/
	local[10]= argv[1];
	local[11]= fqv[60];
	local[12]= local[6];
	local[13]= fqv[61];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= argv[1];
	local[11]= fqv[26];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= local[5];
	local[11]= makeint(4864);
	ctx->vsp=local+12;
	w=(*ftab[28])(ctx,2,local+10,&ftab[28],fqv[62]); /*glnewlist*/
	local[10]= fqv[38];
	ctx->vsp=local+11;
	w=(*ftab[18])(ctx,1,local+10,&ftab[18],fqv[39]); /*probe-extension*/
	if (w==NIL) goto IF171;
	local[10]= makeint(3553);
	local[11]= local[9];
	ctx->vsp=local+12;
	w=(*ftab[21])(ctx,2,local+10,&ftab[21],fqv[44]); /*glbindtextureext*/
	local[10]= w;
	goto IF172;
IF171:
	local[10]= makeint(3553);
	local[11]= makeint(0);
	local[12]= argv[1];
	local[13]= fqv[51];
	ctx->vsp=local+14;
	w=(pointer)GETPROP(ctx,2,local+12); /*get*/
	local[12]= w;
	local[13]= argv[1];
	local[14]= fqv[49];
	ctx->vsp=local+15;
	w=(pointer)GETPROP(ctx,2,local+13); /*get*/
	local[13]= w;
	local[14]= argv[1];
	local[15]= fqv[50];
	ctx->vsp=local+16;
	w=(pointer)GETPROP(ctx,2,local+14); /*get*/
	local[14]= w;
	local[15]= makeint(0);
	local[16]= argv[1];
	local[17]= fqv[51];
	ctx->vsp=local+18;
	w=(pointer)GETPROP(ctx,2,local+16); /*get*/
	local[16]= w;
	local[17]= makeint(3);
	ctx->vsp=local+18;
	w=(pointer)NUMEQUAL(ctx,2,local+16); /*=*/
	if (w==NIL) goto IF173;
	local[16]= makeint(6407);
	goto IF174;
IF173:
	local[16]= makeint(6409);
IF174:
	local[17]= makeint(5121);
	local[18]= argv[1];
	local[19]= fqv[48];
	ctx->vsp=local+20;
	w=(pointer)GETPROP(ctx,2,local+18); /*get*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(*ftab[27])(ctx,9,local+10,&ftab[27],fqv[59]); /*glteximage2d*/
	local[10]= w;
IF172:
	local[10]= makeint(3553);
	ctx->vsp=local+11;
	w=(*ftab[29])(ctx,1,local+10,&ftab[29],fqv[63]); /*glenable*/
	if (local[8]==NIL) goto CON176;
	local[10]= makeint(8192);
	local[11]= makeint(9472);
	local[12]= makeint(9218);
	ctx->vsp=local+13;
	w=(*ftab[30])(ctx,3,local+10,&ftab[30],fqv[64]); /*gltexgeni*/
	local[10]= makeint(8193);
	local[11]= makeint(9472);
	local[12]= makeint(9218);
	ctx->vsp=local+13;
	w=(*ftab[30])(ctx,3,local+10,&ftab[30],fqv[64]); /*gltexgeni*/
	local[10]= makeint(3168);
	ctx->vsp=local+11;
	w=(*ftab[29])(ctx,1,local+10,&ftab[29],fqv[63]); /*glenable*/
	local[10]= makeint(3169);
	ctx->vsp=local+11;
	w=(*ftab[29])(ctx,1,local+10,&ftab[29],fqv[63]); /*glenable*/
	local[10]= w;
	goto CON175;
CON176:
	local[10]= argv[1];
	local[11]= fqv[35];
	ctx->vsp=local+12;
	w=(pointer)GETPROP(ctx,2,local+10); /*get*/
	if (w!=NIL) goto CON177;
	local[10]= argv[1];
	local[11]= fqv[65];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	local[11]= local[10];
	local[12]= fqv[66];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	local[12]= local[10];
	local[13]= fqv[67];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[12]= w;
	local[13]= local[11];
	local[14]= makeint(0);
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	local[14]= local[12];
	local[15]= makeint(0);
	ctx->vsp=local+16;
	w=(pointer)ELT(ctx,2,local+14); /*elt*/
	local[14]= w;
	local[15]= local[11];
	local[16]= makeint(1);
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	local[16]= local[12];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)ELT(ctx,2,local+16); /*elt*/
	local[16]= w;
	local[17]= local[14];
	local[18]= local[13];
	ctx->vsp=local+19;
	w=(pointer)MINUS(ctx,2,local+17); /*-*/
	local[17]= w;
	local[18]= local[16];
	local[19]= local[15];
	ctx->vsp=local+20;
	w=(pointer)MINUS(ctx,2,local+18); /*-*/
	local[18]= w;
	local[19]= makeint(8192);
	local[20]= makeint(9472);
	local[21]= makeint(9217);
	ctx->vsp=local+22;
	w=(*ftab[30])(ctx,3,local+19,&ftab[30],fqv[64]); /*gltexgeni*/
	local[19]= makeint(8193);
	local[20]= makeint(9472);
	local[21]= makeint(9217);
	ctx->vsp=local+22;
	w=(*ftab[30])(ctx,3,local+19,&ftab[30],fqv[64]); /*gltexgeni*/
	local[19]= makeint(8192);
	local[20]= makeint(9473);
	local[21]= makeflt(1.00000000e+00);
	local[22]= local[17];
	ctx->vsp=local+23;
	w=(pointer)QUOTIENT(ctx,2,local+21); /*/*/
	local[21]= w;
	local[22]= makeint(0);
	local[23]= makeint(0);
	local[24]= local[13];
	local[25]= local[17];
	ctx->vsp=local+26;
	w=(pointer)QUOTIENT(ctx,2,local+24); /*/*/
	local[24]= w;
	ctx->vsp=local+25;
	w=(pointer)MKFLTVEC(ctx,4,local+21); /*float-vector*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(*ftab[31])(ctx,3,local+19,&ftab[31],fqv[68]); /*gltexgenfv*/
	local[19]= makeint(8193);
	local[20]= makeint(9473);
	local[21]= makeint(0);
	local[22]= makeflt(1.00000000e+00);
	local[23]= local[18];
	ctx->vsp=local+24;
	w=(pointer)QUOTIENT(ctx,2,local+22); /*/*/
	local[22]= w;
	local[23]= makeint(0);
	local[24]= local[15];
	local[25]= local[18];
	ctx->vsp=local+26;
	w=(pointer)QUOTIENT(ctx,2,local+24); /*/*/
	local[24]= w;
	ctx->vsp=local+25;
	w=(pointer)MKFLTVEC(ctx,4,local+21); /*float-vector*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(*ftab[31])(ctx,3,local+19,&ftab[31],fqv[68]); /*gltexgenfv*/
	local[19]= makeint(3168);
	ctx->vsp=local+20;
	w=(*ftab[29])(ctx,1,local+19,&ftab[29],fqv[63]); /*glenable*/
	local[19]= makeint(3169);
	ctx->vsp=local+20;
	w=(*ftab[29])(ctx,1,local+19,&ftab[29],fqv[63]); /*glenable*/
	local[10]= w;
	goto CON175;
CON177:
	local[10]= NIL;
CON175:
	ctx->vsp=local+10;
	local[10]= makeclosure(codevec,quotevec,CLO178,env,argv,local);
	local[11]= argv[1];
	local[12]= fqv[69];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)MAPC(ctx,2,local+10); /*mapc*/
	if (local[8]!=NIL) goto OR181;
	if (local[7]==NIL) goto OR181;
	goto IF179;
OR181:
	local[10]= makeint(3168);
	ctx->vsp=local+11;
	w=(*ftab[32])(ctx,1,local+10,&ftab[32],fqv[70]); /*gldisable*/
	local[10]= makeint(3169);
	ctx->vsp=local+11;
	w=(*ftab[32])(ctx,1,local+10,&ftab[32],fqv[70]); /*gldisable*/
	local[10]= w;
	goto IF180;
IF179:
	local[10]= NIL;
IF180:
	local[10]= makeint(3553);
	ctx->vsp=local+11;
	w=(*ftab[32])(ctx,1,local+10,&ftab[32],fqv[70]); /*gldisable*/
	ctx->vsp=local+10;
	w=(*ftab[33])(ctx,0,local+10,&ftab[33],fqv[71]); /*glendlist*/
	local[10]= argv[1];
	local[11]= fqv[60];
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= argv[1];
	local[11]= fqv[26];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= argv[1];
	local[11]= local[5];
	local[12]= fqv[17];
	ctx->vsp=local+13;
	w=(pointer)PUTPROP(ctx,3,local+10); /*putprop*/
	local[10]= argv[0];
	local[11]= argv[1];
	ctx->vsp=local+12;
	w=(pointer)F120draw_body(ctx,2,local+10); /*draw-body*/
	local[5]= w;
	goto CON160;
CON162:
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(*ftab[17])(ctx,1,local+5,&ftab[17],fqv[33]); /*glgenlists*/
	local[5]= w;
	local[6]= argv[1];
	local[7]= fqv[26];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= fqv[34];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= argv[1];
	local[8]= fqv[60];
	local[9]= local[6];
	local[10]= fqv[61];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= argv[1];
	local[8]= fqv[26];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= local[5];
	local[8]= makeint(4864);
	ctx->vsp=local+9;
	w=(*ftab[28])(ctx,2,local+7,&ftab[28],fqv[62]); /*glnewlist*/
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO183,env,argv,local);
	local[8]= argv[1];
	local[9]= fqv[69];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MAPC(ctx,2,local+7); /*mapc*/
	ctx->vsp=local+7;
	w=(*ftab[33])(ctx,0,local+7,&ftab[33],fqv[71]); /*glendlist*/
	local[7]= argv[1];
	local[8]= fqv[60];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= argv[1];
	local[8]= fqv[26];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= argv[1];
	local[8]= local[5];
	local[9]= fqv[17];
	ctx->vsp=local+10;
	w=(pointer)PUTPROP(ctx,3,local+7); /*putprop*/
	local[5]= argv[0];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)F120draw_body(ctx,2,local+5); /*draw-body*/
	local[5]= w;
	goto CON160;
CON182:
	local[5]= NIL;
CON160:
	w = local[5];
	local[0]= w;
BLK155:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO178(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	if (env->c.clo.env2[8]!=NIL) goto IF184;
	local[1]= env->c.clo.env2[7];
	goto IF185;
IF184:
	local[1]= NIL;
IF185:
	local[2]= env->c.clo.env2[2];
	ctx->vsp=local+3;
	w=(pointer)F119draw_face(ctx,3,local+0); /*draw-face*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO183(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= NIL;
	local[2]= env->c.clo.env2[2];
	ctx->vsp=local+3;
	w=(pointer)F119draw_face(ctx,3,local+0); /*draw-face*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___glprim(ctx,n,argv,env)
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
	local[0]= fqv[72];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF186;
	local[0]= fqv[73];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[74],w);
	goto IF187;
IF186:
	local[0]= fqv[75];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF187:
	local[0]= fqv[76];
	local[1]= fqv[77];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF188;
	local[0]= fqv[76];
	local[1]= fqv[77];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[76];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF190;
	local[0]= fqv[76];
	local[1]= fqv[78];
	local[2]= T;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF191;
IF190:
	local[0]= NIL;
IF191:
	local[0]= fqv[76];
	goto IF189;
IF188:
	local[0]= NIL;
IF189:
	local[0]= fqv[7];
	local[1]= fqv[77];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF192;
	local[0]= fqv[7];
	local[1]= fqv[77];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[7];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF194;
	local[0]= fqv[7];
	local[1]= fqv[78];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF195;
IF194:
	local[0]= NIL;
IF195:
	local[0]= fqv[7];
	goto IF193;
IF192:
	local[0]= NIL;
IF193:
	local[0]= fqv[29];
	local[1]= fqv[77];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF196;
	local[0]= fqv[29];
	local[1]= fqv[77];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[29];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF198;
	local[0]= fqv[29];
	local[1]= fqv[78];
	local[2]= fqv[79];
	local[3]= fqv[40];
	local[4]= fqv[80];
	ctx->vsp=local+5;
	w=(*ftab[19])(ctx,3,local+2,&ftab[19],fqv[42]); /*make-array*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF199;
IF198:
	local[0]= NIL;
IF199:
	local[0]= fqv[29];
	goto IF197;
IF196:
	local[0]= NIL;
IF197:
	local[0]= fqv[81];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[82],module,F119draw_face,fqv[83]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[84],module,F120draw_body,fqv[85]);
	local[0]= fqv[86];
	local[1]= fqv[87];
	ctx->vsp=local+2;
	w=(*ftab[34])(ctx,2,local+0,&ftab[34],fqv[88]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<35; i++) ftab[i]=fcallx;
}
