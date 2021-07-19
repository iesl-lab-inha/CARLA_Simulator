/* ./Xtop.c :  entry=Xtop */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "Xtop.h"
#pragma init (register_Xtop)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___Xtop();
extern pointer build_quote_vector();
static int register_Xtop()
  { add_module_initializer("___Xtop", ___Xtop);}

static pointer F3304eustop_win_time_tick();
static pointer F3305eustop_update_history();
static pointer F3306eustop_update_gc();
static pointer F3307eustop_exit();
static pointer F3308eustop_win();
static pointer F3309init_xwindow();

/*:buttonpress*/
static pointer M3310eustop_history_window_buttonpress(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[0],w);
	local[3]= argv[0];
	local[4]= fqv[1];
	local[5]= fqv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3311:
	ctx->vsp=local; return(local[0]);}

/*:buttonrelease*/
static pointer M3312eustop_history_window_buttonrelease(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[0],w);
	local[3]= argv[0];
	local[4]= fqv[3];
	local[5]= loadglobal(fqv[0]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[4];
	local[6]= loadglobal(fqv[0]);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= loadglobal(fqv[0]);
	ctx->vsp=local+6;
	w=(*ftab[0])(ctx,1,local+5,&ftab[0],fqv[5]); /*event-button*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[7];
	local[7]= fqv[6];
	local[8]= local[3];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3313:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M3314eustop_win_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3316:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= loadglobal(fqv[7]);
	local[2]= fqv[8];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= loadglobal(fqv[7]);
	local[3]= fqv[9];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	argv[0]->c.obj.iv[30] = makeint(0);
	argv[0]->c.obj.iv[31] = NIL;
	argv[0]->c.obj.iv[33] = makeint(0);
	local[3]= (pointer)get_sym_func(fqv[10]);
	local[4]= argv[0];
	local[5]= *(ovafptr(argv[1],fqv[11]));
	local[6]= fqv[12];
	local[7]= fqv[8];
	local[8]= local[1];
	local[9]= fqv[9];
	local[10]= makeint(200);
	local[11]= fqv[13];
	local[12]= fqv[14];
	local[13]= fqv[15];
	local[14]= loadglobal(fqv[16]);
	local[15]= fqv[17];
	local[16]= NIL;
	local[17]= fqv[18];
	ctx->vsp=local+18;
	w=(pointer)GETPID(ctx,0,local+18); /*unix:getpid*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)XFORMAT(ctx,3,local+16); /*format*/
	local[16]= w;
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)APPLY(ctx,15,local+3); /*apply*/
	local[3]= loadglobal(fqv[19]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[12];
	local[6]= fqv[8];
	local[7]= argv[0]->c.obj.iv[5];
	local[8]= makeint(300);
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,2,local+7); /*-*/
	local[7]= w;
	local[8]= fqv[9];
	local[9]= makeint(143);
	local[10]= fqv[20];
	local[11]= argv[0];
	local[12]= fqv[21];
	local[13]= makeint(0);
	local[14]= fqv[22];
	local[15]= makeint(0);
	local[16]= fqv[15];
	local[17]= loadglobal(fqv[23]);
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,14,local+4); /*send*/
	w = local[3];
	argv[0]->c.obj.iv[25] = w;
	local[3]= loadglobal(fqv[24]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[12];
	local[6]= fqv[20];
	local[7]= argv[0];
	local[8]= fqv[8];
	local[9]= argv[0]->c.obj.iv[5];
	local[10]= makeint(300);
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,2,local+9); /*-*/
	local[9]= w;
	local[10]= fqv[9];
	local[11]= makeint(34);
	local[12]= fqv[21];
	local[13]= makeint(0);
	local[14]= fqv[22];
	local[15]= makeint(145);
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,12,local+4); /*send*/
	w = local[3];
	argv[0]->c.obj.iv[32] = w;
	local[3]= loadglobal(fqv[24]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[12];
	local[6]= fqv[20];
	local[7]= argv[0];
	local[8]= fqv[8];
	local[9]= argv[0]->c.obj.iv[5];
	local[10]= makeint(300);
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,2,local+9); /*-*/
	local[9]= w;
	local[10]= fqv[9];
	local[11]= makeint(16);
	local[12]= fqv[21];
	local[13]= makeint(0);
	local[14]= fqv[22];
	local[15]= makeint(181);
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,12,local+4); /*send*/
	w = local[3];
	argv[0]->c.obj.iv[26] = w;
	local[3]= loadglobal(fqv[25]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[12];
	local[6]= fqv[20];
	local[7]= argv[0];
	local[8]= fqv[8];
	local[9]= makeint(300);
	local[10]= fqv[9];
	local[11]= makeint(197);
	local[12]= fqv[21];
	local[13]= argv[0]->c.obj.iv[5];
	local[14]= makeint(300);
	ctx->vsp=local+15;
	w=(pointer)MINUS(ctx,2,local+13); /*-*/
	local[13]= w;
	local[14]= fqv[22];
	local[15]= makeint(0);
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,12,local+4); /*send*/
	w = local[3];
	argv[0]->c.obj.iv[29] = w;
	local[3]= argv[0]->c.obj.iv[25];
	local[4]= fqv[26];
	local[5]= loadglobal(fqv[27]);
	local[6]= fqv[28];
	local[7]= argv[0];
	local[8]= fqv[29];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	argv[0]->c.obj.iv[28] = w;
	local[3]= argv[0]->c.obj.iv[25];
	local[4]= fqv[26];
	local[5]= loadglobal(fqv[27]);
	local[6]= fqv[30];
	local[7]= argv[0];
	local[8]= fqv[31];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[25];
	local[4]= fqv[26];
	local[5]= loadglobal(fqv[27]);
	local[6]= fqv[32];
	local[7]= argv[0];
	local[8]= fqv[33];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[25];
	local[4]= fqv[26];
	local[5]= loadglobal(fqv[27]);
	local[6]= fqv[34];
	local[7]= argv[0];
	local[8]= fqv[35];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[25];
	local[4]= fqv[26];
	local[5]= loadglobal(fqv[27]);
	local[6]= fqv[36];
	local[7]= argv[0];
	local[8]= fqv[37];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[25];
	local[4]= fqv[26];
	local[5]= loadglobal(fqv[38]);
	local[6]= fqv[39];
	local[7]= argv[0];
	local[8]= fqv[40];
	local[9]= fqv[41];
	local[10]= makeflt(1.00000000e-01);
	local[11]= fqv[42];
	local[12]= makeint(5);
	local[13]= fqv[43];
	local[14]= fqv[44];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,12,local+3); /*send*/
	w = argv[0];
	local[0]= w;
BLK3315:
	ctx->vsp=local; return(local[0]);}

/*:attach*/
static pointer M3321eustop_win_attach(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[0]->c.obj.iv[27]==NIL) goto IF3323;
	local[0]= argv[0];
	local[1]= fqv[45];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF3324;
IF3323:
	local[0]= loadglobal(fqv[7]);
	local[1]= fqv[8];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= loadglobal(fqv[7]);
	local[2]= fqv[9];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[46];
	local[4]= local[0];
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	local[5]= local[1];
	local[6]= makeint(200);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= loadglobal(fqv[7]);
	local[3]= fqv[47];
	local[4]= argv[0];
	local[5]= makeint(0);
	local[6]= makeint(200);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	local[2]= argv[0]->c.obj.iv[28];
	local[3]= fqv[48];
	local[4]= fqv[49];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	argv[0]->c.obj.iv[27] = T;
	w = argv[0]->c.obj.iv[27];
	local[0]= w;
IF3324:
	w = local[0];
	local[0]= w;
BLK3322:
	ctx->vsp=local; return(local[0]);}

/*:detach*/
static pointer M3325eustop_win_detach(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= loadglobal(fqv[7]);
	local[1]= fqv[47];
	local[2]= loadglobal(fqv[50]);
	local[3]= makeint(100);
	local[4]= makeint(100);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[46];
	local[2]= makeint(400);
	local[3]= makeint(200);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[28];
	local[1]= fqv[48];
	local[2]= fqv[51];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	argv[0]->c.obj.iv[27] = NIL;
	ctx->vsp=local+0;
	w=(*ftab[1])(ctx,0,local+0,&ftab[1],fqv[52]); /*xflush*/
	local[0]= w;
BLK3326:
	ctx->vsp=local; return(local[0]);}

/*:filepanel*/
static pointer M3327eustop_win_filepanel(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= loadglobal(fqv[53]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[12];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK3328:
	ctx->vsp=local; return(local[0]);}

/*:refresh-history*/
static pointer M3330eustop_win_refresh_history(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[29];
	local[2]= fqv[54];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[29];
	local[3]= fqv[55];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[29];
	local[4]= fqv[56];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[31];
WHL3333:
	if (local[4]==NIL) goto WHX3334;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	w = local[3];
	if (!iscons(w)) goto IF3337;
	local[5]= argv[0]->c.obj.iv[29];
	local[6]= fqv[57];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SUB1(ctx,1,local+7); /*1-*/
	local[1] = w;
	local[7]= local[1];
	local[8]= makeint(0);
	local[9]= NIL;
	local[10]= fqv[58];
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,4,local+9); /*format*/
	local[9]= w;
	local[10]= makeint(0);
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)SUBSEQ(ctx,3,local+9); /*subseq*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	local[5]= w;
	goto IF3338;
IF3337:
	local[5]= NIL;
IF3338:
	goto WHL3333;
WHX3334:
	local[5]= NIL;
BLK3335:
	w = NIL;
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,0,local+3,&ftab[1],fqv[52]); /*xflush*/
	local[0]= w;
BLK3331:
	ctx->vsp=local; return(local[0]);}

/*:update-history*/
static pointer M3339eustop_win_update_history(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[59]);
	local[1]= loadglobal(fqv[60]);
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[29];
	local[2]= fqv[55];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[29];
	local[3]= fqv[54];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	w = local[0];
	if (!iscons(w)) goto IF3341;
	local[3]= argv[0]->c.obj.iv[30];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==local[3]) goto IF3341;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[30] = (w)->c.cons.car;
	local[3]= local[0];
	w = argv[0]->c.obj.iv[31];
	ctx->vsp=local+4;
	argv[0]->c.obj.iv[31] = cons(ctx,local[3],w);
	local[3]= argv[0]->c.obj.iv[31];
	local[4]= makeint(0);
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SUBSEQ(ctx,3,local+3); /*subseq*/
	argv[0]->c.obj.iv[31] = w;
	local[3]= argv[0]->c.obj.iv[29];
	local[4]= fqv[61];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[29];
	local[4]= fqv[57];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SUB1(ctx,1,local+5); /*1-*/
	local[5]= w;
	local[6]= makeint(0);
	local[7]= NIL;
	local[8]= fqv[62];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,4,local+7); /*format*/
	local[7]= w;
	local[8]= makeint(0);
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SUBSEQ(ctx,3,local+7); /*subseq*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,5,local+3); /*send*/
	local[3]= w;
	goto IF3342;
IF3341:
	local[3]= NIL;
IF3342:
	local[3]= argv[0]->c.obj.iv[32];
	local[4]= fqv[56];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[32];
	local[4]= fqv[57];
	local[5]= makeint(0);
	local[6]= makeint(0);
	local[7]= NIL;
	local[8]= fqv[63];
	local[9]= loadglobal(fqv[64]);
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= w;
	local[8]= makeint(0);
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SUBSEQ(ctx,3,local+7); /*subseq*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,5,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[32];
	local[4]= fqv[57];
	local[5]= makeint(1);
	local[6]= makeint(0);
	local[7]= NIL;
	local[8]= fqv[65];
	local[9]= loadglobal(fqv[66]);
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= w;
	local[8]= makeint(0);
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SUBSEQ(ctx,3,local+7); /*subseq*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,5,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[32];
	local[4]= fqv[57];
	local[5]= makeint(2);
	local[6]= makeint(0);
	local[7]= NIL;
	local[8]= fqv[67];
	local[9]= loadglobal(fqv[68]);
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= w;
	local[8]= makeint(0);
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SUBSEQ(ctx,3,local+7); /*subseq*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,5,local+3); /*send*/
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,0,local+3,&ftab[1],fqv[52]); /*xflush*/
	local[0]= w;
BLK3340:
	ctx->vsp=local; return(local[0]);}

/*:update-gc*/
static pointer M3343eustop_win_update_gc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	ctx->vsp=local+0;
	w=(pointer)GCTIME(ctx,0,local+0); /*system:gctime*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[26];
	local[2]= fqv[69];
	local[3]= makeint(0);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[26];
	local[2]= fqv[57];
	local[3]= makeint(0);
	local[4]= makeint(1);
	local[5]= NIL;
	local[6]= fqv[70];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= makeflt(1.00000000e+02);
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= makeflt(1.00000000e+02);
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)RUNTIME(ctx,0,local+10); /*unix:runtime*/
	local[10]= w;
	local[11]= makeflt(1.00000000e+02);
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[10]= w;
	local[11]= argv[2];
	local[12]= makeint(256);
	ctx->vsp=local+13;
	w=(pointer)QUOTIENT(ctx,2,local+11); /*/*/
	local[11]= w;
	local[12]= argv[3];
	local[13]= makeint(256);
	ctx->vsp=local+14;
	w=(pointer)QUOTIENT(ctx,2,local+12); /*/*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,8,local+5); /*format*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,0,local+1,&ftab[1],fqv[52]); /*xflush*/
	local[0]= w;
BLK3344:
	ctx->vsp=local; return(local[0]);}

/*:configurenotify*/
static pointer M3345eustop_win_configurenotify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[0],w);
	local[3]= argv[0];
	local[4]= fqv[8];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[9];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	if (argv[0]->c.obj.iv[27]==NIL) goto IF3347;
	local[5]= local[3];
	local[6]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+7;
	w=(*ftab[2])(ctx,2,local+5,&ftab[2],fqv[71]); /*/=*/
	if (w!=NIL) goto OR3349;
	local[5]= local[4];
	local[6]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+7;
	w=(*ftab[2])(ctx,2,local+5,&ftab[2],fqv[71]); /*/=*/
	if (w!=NIL) goto OR3349;
	goto IF3347;
OR3349:
	local[5]= loadglobal(fqv[7]);
	local[6]= fqv[46];
	local[7]= local[3];
	local[8]= makeint(2);
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,2,local+7); /*-*/
	local[7]= w;
	local[8]= local[4];
	local[9]= makeint(201);
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto IF3348;
IF3347:
	local[5]= NIL;
IF3348:
	w = local[5];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3346:
	ctx->vsp=local; return(local[0]);}

/*:select*/
static pointer M3350eustop_win_select(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0]->c.obj.iv[29];
	local[1]= fqv[54];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	local[2]= argv[2];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,3,local+1); /*-*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+3;
	w=(pointer)NTH(ctx,2,local+1); /*nth*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[72]); /*get-history*/
	local[1]= w;
	local[2]= local[1];
	local[3]= argv[3];
	local[4]= local[3];
	if (fqv[73]!=local[4]) goto IF3353;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,1,local+4,&ftab[4],fqv[74]); /*line-edit*/
	local[2] = w;
	local[4]= local[2];
	goto IF3354;
IF3353:
	local[4]= local[3];
	if (fqv[75]!=local[4]) goto IF3355;
	local[4]= NIL;
	goto IF3356;
IF3355:
	local[4]= NIL;
IF3356:
IF3354:
	w = local[4];
	if (local[2]==NIL) goto CON3358;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(*ftab[5])(ctx,1,local+3,&ftab[5],fqv[76]); /*add-history*/
	local[3]= argv[0];
	local[4]= fqv[77];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,1,local+3,&ftab[6],fqv[78]); /*make-string-input-stream*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[7])(ctx,1,local+3,&ftab[7],fqv[79]); /*evaluate-stream*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PRINT(ctx,1,local+3); /*print*/
	local[3]= w;
	goto CON3357;
CON3358:
	local[3]= NIL;
	goto CON3357;
CON3359:
	local[3]= NIL;
CON3357:
	w = local[3];
	local[0]= w;
BLK3351:
	ctx->vsp=local; return(local[0]);}

/*:alloc*/
static pointer M3360eustop_win_alloc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeint(16384);
	ctx->vsp=local+1;
	w=(pointer)ALLOC(ctx,1,local+0); /*system:alloc*/
	ctx->vsp=local+0;
	w=(pointer)GEESEE(ctx,0,local+0); /*system:gc*/
	local[0]= w;
BLK3361:
	ctx->vsp=local; return(local[0]);}

/*:exit*/
static pointer M3362eustop_win_exit(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	w=(pointer)EXIT(ctx,0,local+0); /*unix::exit*/
	local[0]= w;
BLK3363:
	ctx->vsp=local; return(local[0]);}

/*:interval*/
static pointer M3364eustop_win_interval(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	storeglobal(fqv[80],local[0]);
	w = local[0];
	local[0]= w;
BLK3365:
	ctx->vsp=local; return(local[0]);}

/*:time-tick*/
static pointer M3366eustop_win_time_tick(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3368:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0]->c.obj.iv[33];
	ctx->vsp=local+2;
	w=(pointer)ADD1(ctx,1,local+1); /*1+*/
	argv[0]->c.obj.iv[33] = w;
	local[1]= argv[0]->c.obj.iv[33];
	ctx->vsp=local+2;
	w=(*ftab[8])(ctx,1,local+1,&ftab[8],fqv[81]); /*oddp*/
	if (w==NIL) goto IF3369;
	local[1]= argv[0]->c.obj.iv[26];
	local[2]= fqv[82];
	local[3]= makeint(1);
	local[4]= makeint(10);
	local[5]= fqv[83];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= w;
	goto IF3370;
IF3369:
	local[1]= argv[0]->c.obj.iv[26];
	local[2]= fqv[82];
	local[3]= makeint(1);
	local[4]= makeint(10);
	local[5]= fqv[84];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= w;
IF3370:
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,0,local+1,&ftab[1],fqv[52]); /*xflush*/
	local[0]= w;
BLK3367:
	ctx->vsp=local; return(local[0]);}

/*eustop-win-time-tick*/
static pointer F3304eustop_win_time_tick(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= loadglobal(fqv[85]);
	local[1]= fqv[86];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK3371:
	ctx->vsp=local; return(local[0]);}

/*eustop-update-history*/
static pointer F3305eustop_update_history(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= loadglobal(fqv[85]);
	local[1]= fqv[77];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK3372:
	ctx->vsp=local; return(local[0]);}

/*eustop-update-gc*/
static pointer F3306eustop_update_gc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[85]);
	local[1]= fqv[87];
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK3373:
	ctx->vsp=local; return(local[0]);}

/*eustop-exit*/
static pointer F3307eustop_exit(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= loadglobal(fqv[85]);
	local[1]= fqv[45];
	local[2]= NIL;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3374:
	ctx->vsp=local; return(local[0]);}

/*eustop-win*/
static pointer F3308eustop_win(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= loadglobal(fqv[88]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[12];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = local[0];
	local[0]= w;
	storeglobal(fqv[85],w);
	local[0]= fqv[89];
	storeglobal(fqv[90],local[0]);
	local[0]= fqv[91];
	storeglobal(fqv[92],local[0]);
	local[0]= fqv[93];
	storeglobal(fqv[94],local[0]);
	local[0]= loadglobal(fqv[85]);
	local[1]= fqv[87];
	local[2]= makeint(0);
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[95];
	local[1]= loadglobal(fqv[96]);
	local[2]= fqv[97];
	local[3]= NIL;
	local[4]= fqv[98];
	local[5]= NIL;
	local[6]= fqv[99];
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(*ftab[9])(ctx,8,local+0,&ftab[9],fqv[100]); /*member*/
	if (w!=NIL) goto IF3377;
	local[0]= fqv[95];
	w = loadglobal(fqv[96]);
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	storeglobal(fqv[96],local[0]);
	goto IF3378;
IF3377:
	local[0]= NIL;
IF3378:
	w = loadglobal(fqv[85]);
	local[0]= w;
BLK3375:
	ctx->vsp=local; return(local[0]);}

/*init-xwindow*/
static pointer F3309init_xwindow(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT3381;}
	local[0]= fqv[101];
	ctx->vsp=local+1;
	w=(pointer)GETENV(ctx,1,local+0); /*unix:getenv*/
	local[0]= w;
ENT3381:
ENT3380:
	if (n>1) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,1,local+1,&ftab[10],fqv[102]); /*opendisplay*/
	local[1]= w;
	storeglobal(fqv[103],w);
	ctx->vsp=local+2;
	w=(*ftab[11])(ctx,1,local+1,&ftab[11],fqv[104]); /*zerop*/
	if (w!=NIL) goto CON3383;
	local[1]= loadglobal(fqv[105]);
	ctx->vsp=local+2;
	w=(pointer)ISATTY(ctx,1,local+1); /*unix:isatty*/
	if (w==NIL) goto IF3384;
	local[1]= fqv[106];
	local[2]= fqv[107];
	ctx->vsp=local+3;
	w=(pointer)GETENV(ctx,1,local+2); /*unix:getenv*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[12])(ctx,2,local+1,&ftab[12],fqv[108]); /*warn*/
	local[1]= w;
	goto IF3385;
IF3384:
	local[1]= NIL;
IF3385:
	local[1]= fqv[109];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,1,local+1,&ftab[13],fqv[110]); /*font-id*/
	local[1]= w;
	storeglobal(fqv[111],w);
	local[1]= fqv[112];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,1,local+1,&ftab[13],fqv[110]); /*font-id*/
	local[1]= w;
	storeglobal(fqv[16],w);
	local[1]= fqv[113];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,1,local+1,&ftab[13],fqv[110]); /*font-id*/
	local[1]= w;
	storeglobal(fqv[114],w);
	local[1]= fqv[115];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,1,local+1,&ftab[13],fqv[110]); /*font-id*/
	local[1]= w;
	storeglobal(fqv[116],w);
	local[1]= fqv[117];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,1,local+1,&ftab[13],fqv[110]); /*font-id*/
	local[1]= w;
	storeglobal(fqv[118],w);
	local[1]= fqv[119];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,1,local+1,&ftab[13],fqv[110]); /*font-id*/
	local[1]= w;
	storeglobal(fqv[23],w);
	local[1]= fqv[120];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,1,local+1,&ftab[13],fqv[110]); /*font-id*/
	local[1]= w;
	storeglobal(fqv[121],w);
	local[1]= fqv[122];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,1,local+1,&ftab[13],fqv[110]); /*font-id*/
	local[1]= w;
	storeglobal(fqv[123],w);
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,1,local+1,&ftab[13],fqv[110]); /*font-id*/
	local[1]= w;
	storeglobal(fqv[125],w);
	local[1]= fqv[126];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,1,local+1,&ftab[13],fqv[110]); /*font-id*/
	local[1]= w;
	storeglobal(fqv[127],w);
	local[1]= fqv[128];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,1,local+1,&ftab[13],fqv[110]); /*font-id*/
	local[1]= w;
	storeglobal(fqv[129],w);
	local[1]= fqv[130];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,1,local+1,&ftab[13],fqv[110]); /*font-id*/
	local[1]= w;
	storeglobal(fqv[131],w);
	local[1]= fqv[132];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,1,local+1,&ftab[13],fqv[110]); /*font-id*/
	local[1]= w;
	storeglobal(fqv[133],w);
	local[1]= fqv[134];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,1,local+1,&ftab[13],fqv[110]); /*font-id*/
	local[1]= w;
	storeglobal(fqv[135],w);
	local[1]= fqv[136];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,1,local+1,&ftab[13],fqv[110]); /*font-id*/
	local[1]= w;
	storeglobal(fqv[137],w);
	local[1]= fqv[138];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,1,local+1,&ftab[13],fqv[110]); /*font-id*/
	local[1]= w;
	storeglobal(fqv[139],w);
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,1,local+1,&ftab[13],fqv[110]); /*font-id*/
	local[1]= w;
	storeglobal(fqv[141],w);
	local[1]= fqv[142];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,1,local+1,&ftab[13],fqv[110]); /*font-id*/
	local[1]= w;
	storeglobal(fqv[143],w);
	local[1]= fqv[144];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,1,local+1,&ftab[13],fqv[110]); /*font-id*/
	local[1]= w;
	storeglobal(fqv[145],w);
	local[1]= fqv[146];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,1,local+1,&ftab[13],fqv[110]); /*font-id*/
	local[1]= w;
	storeglobal(fqv[147],w);
	local[1]= loadglobal(fqv[114]);
	ctx->vsp=local+2;
	w=(*ftab[11])(ctx,1,local+1,&ftab[11],fqv[104]); /*zerop*/
	if (w==NIL) goto IF3386;
	local[1]= makeint(0);
	storeglobal(fqv[103],local[1]);
	local[1]= makeint(1);
	local[2]= fqv[148];
	ctx->vsp=local+3;
	w=(*ftab[14])(ctx,2,local+1,&ftab[14],fqv[149]); /*warning-message*/
	w = NIL;
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK3379;
	goto IF3387;
IF3386:
	local[1]= NIL;
IF3387:
	local[1]= loadglobal(fqv[103]);
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,1,local+1,&ftab[15],fqv[150]); /*defaultscreen*/
	local[1]= w;
	storeglobal(fqv[151],w);
	local[1]= loadglobal(fqv[103]);
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,1,local+1,&ftab[16],fqv[152]); /*defaultscreenofdisplay*/
	local[1]= w;
	storeglobal(fqv[153],w);
	local[1]= loadglobal(fqv[153]);
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,1,local+1,&ftab[17],fqv[154]); /*defaultvisualofscreen*/
	local[1]= w;
	storeglobal(fqv[155],w);
	local[1]= makeint(64);
	ctx->vsp=local+2;
	w=(*ftab[18])(ctx,1,local+1,&ftab[18],fqv[156]); /*make-string*/
	local[1]= w;
	local[2]= NIL;
	local[3]= loadglobal(fqv[103]);
	local[4]= loadglobal(fqv[151]);
	local[5]= makeint(8);
	local[6]= makeint(3);
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[19])(ctx,5,local+3,&ftab[19],fqv[157]); /*matchvisualinfo*/
	local[3]= w;
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w!=NIL) goto IF3388;
	local[3]= local[1];
	local[4]= makeint(0);
	local[5]= fqv[158];
	ctx->vsp=local+6;
	w=(pointer)PEEK(ctx,3,local+3); /*system:peek*/
	local[3]= w;
	storeglobal(fqv[159],w);
	local[4]= makeint(8);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[3]= w;
	w = loadglobal(fqv[160]);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	storeglobal(fqv[160],local[3]);
	goto IF3389;
IF3388:
	local[3]= NIL;
IF3389:
	local[3]= loadglobal(fqv[103]);
	local[4]= loadglobal(fqv[151]);
	local[5]= makeint(8);
	local[6]= makeint(4);
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[19])(ctx,5,local+3,&ftab[19],fqv[157]); /*matchvisualinfo*/
	local[3]= w;
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w!=NIL) goto IF3390;
	local[3]= local[1];
	local[4]= makeint(0);
	local[5]= fqv[158];
	ctx->vsp=local+6;
	w=(pointer)PEEK(ctx,3,local+3); /*system:peek*/
	local[3]= w;
	storeglobal(fqv[161],w);
	local[4]= makeint(8);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[3]= w;
	w = loadglobal(fqv[160]);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	storeglobal(fqv[160],local[3]);
	goto IF3391;
IF3390:
	local[3]= NIL;
IF3391:
	local[3]= loadglobal(fqv[103]);
	local[4]= loadglobal(fqv[151]);
	local[5]= makeint(8);
	local[6]= makeint(5);
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[19])(ctx,5,local+3,&ftab[19],fqv[157]); /*matchvisualinfo*/
	local[3]= w;
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w!=NIL) goto IF3392;
	local[3]= local[1];
	local[4]= makeint(0);
	local[5]= fqv[158];
	ctx->vsp=local+6;
	w=(pointer)PEEK(ctx,3,local+3); /*system:peek*/
	local[3]= w;
	storeglobal(fqv[162],w);
	local[4]= makeint(8);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[3]= w;
	w = loadglobal(fqv[160]);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	storeglobal(fqv[160],local[3]);
	goto IF3393;
IF3392:
	local[3]= NIL;
IF3393:
	local[3]= loadglobal(fqv[103]);
	local[4]= loadglobal(fqv[151]);
	local[5]= makeint(15);
	local[6]= makeint(4);
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[19])(ctx,5,local+3,&ftab[19],fqv[157]); /*matchvisualinfo*/
	local[3]= w;
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w!=NIL) goto IF3394;
	local[3]= local[1];
	local[4]= makeint(0);
	local[5]= fqv[158];
	ctx->vsp=local+6;
	w=(pointer)PEEK(ctx,3,local+3); /*system:peek*/
	local[3]= w;
	storeglobal(fqv[163],w);
	local[4]= makeint(15);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[3]= w;
	w = loadglobal(fqv[160]);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	storeglobal(fqv[160],local[3]);
	goto IF3395;
IF3394:
	local[3]= NIL;
IF3395:
	local[3]= loadglobal(fqv[103]);
	local[4]= loadglobal(fqv[151]);
	local[5]= makeint(15);
	local[6]= makeint(5);
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[19])(ctx,5,local+3,&ftab[19],fqv[157]); /*matchvisualinfo*/
	local[3]= w;
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w!=NIL) goto IF3396;
	local[3]= local[1];
	local[4]= makeint(0);
	local[5]= fqv[158];
	ctx->vsp=local+6;
	w=(pointer)PEEK(ctx,3,local+3); /*system:peek*/
	local[3]= w;
	storeglobal(fqv[164],w);
	local[4]= makeint(15);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[3]= w;
	w = loadglobal(fqv[160]);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	storeglobal(fqv[160],local[3]);
	goto IF3397;
IF3396:
	local[3]= NIL;
IF3397:
	local[3]= loadglobal(fqv[103]);
	local[4]= loadglobal(fqv[151]);
	local[5]= makeint(16);
	local[6]= makeint(4);
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[19])(ctx,5,local+3,&ftab[19],fqv[157]); /*matchvisualinfo*/
	local[3]= w;
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w!=NIL) goto IF3398;
	local[3]= local[1];
	local[4]= makeint(0);
	local[5]= fqv[158];
	ctx->vsp=local+6;
	w=(pointer)PEEK(ctx,3,local+3); /*system:peek*/
	local[3]= w;
	storeglobal(fqv[165],w);
	local[4]= makeint(16);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[3]= w;
	w = loadglobal(fqv[160]);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	storeglobal(fqv[160],local[3]);
	goto IF3399;
IF3398:
	local[3]= NIL;
IF3399:
	local[3]= loadglobal(fqv[103]);
	local[4]= loadglobal(fqv[151]);
	local[5]= makeint(16);
	local[6]= makeint(5);
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[19])(ctx,5,local+3,&ftab[19],fqv[157]); /*matchvisualinfo*/
	local[3]= w;
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w!=NIL) goto IF3400;
	local[3]= local[1];
	local[4]= makeint(0);
	local[5]= fqv[158];
	ctx->vsp=local+6;
	w=(pointer)PEEK(ctx,3,local+3); /*system:peek*/
	local[3]= w;
	storeglobal(fqv[166],w);
	local[4]= makeint(16);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[3]= w;
	w = loadglobal(fqv[160]);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	storeglobal(fqv[160],local[3]);
	goto IF3401;
IF3400:
	local[3]= NIL;
IF3401:
	local[3]= loadglobal(fqv[103]);
	local[4]= loadglobal(fqv[151]);
	local[5]= makeint(24);
	local[6]= makeint(4);
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[19])(ctx,5,local+3,&ftab[19],fqv[157]); /*matchvisualinfo*/
	local[3]= w;
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w!=NIL) goto IF3402;
	local[3]= local[1];
	local[4]= makeint(0);
	local[5]= fqv[158];
	ctx->vsp=local+6;
	w=(pointer)PEEK(ctx,3,local+3); /*system:peek*/
	local[3]= w;
	storeglobal(fqv[167],w);
	local[4]= makeint(24);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[3]= w;
	w = loadglobal(fqv[160]);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	storeglobal(fqv[160],local[3]);
	goto IF3403;
IF3402:
	local[3]= NIL;
IF3403:
	local[3]= loadglobal(fqv[103]);
	local[4]= loadglobal(fqv[151]);
	local[5]= makeint(24);
	local[6]= makeint(5);
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[19])(ctx,5,local+3,&ftab[19],fqv[157]); /*matchvisualinfo*/
	local[3]= w;
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w!=NIL) goto IF3404;
	local[3]= local[1];
	local[4]= makeint(0);
	local[5]= fqv[158];
	ctx->vsp=local+6;
	w=(pointer)PEEK(ctx,3,local+3); /*system:peek*/
	local[3]= w;
	storeglobal(fqv[168],w);
	local[4]= makeint(24);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[3]= w;
	w = loadglobal(fqv[160]);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	storeglobal(fqv[160],local[3]);
	goto IF3405;
IF3404:
	local[3]= NIL;
IF3405:
	w = local[3];
	local[1]= loadglobal(fqv[153]);
	ctx->vsp=local+2;
	w=(*ftab[20])(ctx,1,local+1,&ftab[20],fqv[169]); /*doessaveunders*/
	local[1]= w;
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[71]); /*/=*/
	local[1]= w;
	storeglobal(fqv[170],w);
	local[1]= loadglobal(fqv[103]);
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(*ftab[21])(ctx,2,local+1,&ftab[21],fqv[171]); /*defaultdepth*/
	local[1]= w;
	storeglobal(fqv[172],w);
	local[1]= loadglobal(fqv[103]);
	local[2]= loadglobal(fqv[103]);
	ctx->vsp=local+3;
	w=(*ftab[15])(ctx,1,local+2,&ftab[15],fqv[150]); /*defaultscreen*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[22])(ctx,2,local+1,&ftab[22],fqv[173]); /*whitepixel*/
	local[1]= w;
	storeglobal(fqv[174],w);
	local[1]= loadglobal(fqv[103]);
	local[2]= loadglobal(fqv[103]);
	ctx->vsp=local+3;
	w=(*ftab[15])(ctx,1,local+2,&ftab[15],fqv[150]); /*defaultscreen*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[23])(ctx,2,local+1,&ftab[23],fqv[175]); /*blackpixel*/
	local[1]= w;
	storeglobal(fqv[176],w);
	local[1]= loadglobal(fqv[176]);
	storeglobal(fqv[177],local[1]);
	local[1]= loadglobal(fqv[174]);
	storeglobal(fqv[178],local[1]);
	local[1]= loadglobal(fqv[179]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[12];
	local[4]= fqv[15];
	local[5]= loadglobal(fqv[114]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[1]= w;
	storeglobal(fqv[180],w);
	local[1]= loadglobal(fqv[180]);
	local[2]= fqv[181];
	local[3]= loadglobal(fqv[177]);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[180]);
	local[2]= fqv[182];
	local[3]= loadglobal(fqv[178]);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[183]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[184];
	local[4]= loadglobal(fqv[103]);
	ctx->vsp=local+5;
	w=(*ftab[24])(ctx,1,local+4,&ftab[24],fqv[185]); /*defaultrootwindow*/
	local[4]= w;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= loadglobal(fqv[180]);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	w = local[1];
	local[1]= w;
	storeglobal(fqv[50],w);
	local[1]= fqv[186];
	ctx->vsp=local+2;
	w=(pointer)GETENV(ctx,1,local+1); /*unix:getenv*/
	if (w==NIL) goto IF3408;
	local[1]= loadglobal(fqv[183]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[184];
	local[4]= fqv[187];
	ctx->vsp=local+5;
	w=(pointer)GETENV(ctx,1,local+4); /*unix:getenv*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[25])(ctx,1,local+4,&ftab[25],fqv[188]); /*read-from-string*/
	local[4]= w;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= loadglobal(fqv[180]);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	w = local[1];
	local[1]= w;
	storeglobal(fqv[7],w);
	goto IF3409;
IF3408:
	local[1]= NIL;
IF3409:
	local[1]= loadglobal(fqv[178]);
	local[2]= local[1];
	w = loadglobal(fqv[50]);
	w->c.obj.iv[4] = local[2];
	local[1]= loadglobal(fqv[179]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	w = local[1];
	local[1]= w;
	storeglobal(fqv[189],w);
	local[1]= loadglobal(fqv[189]);
	local[2]= fqv[190];
	local[3]= loadglobal(fqv[174]);
	local[4]= loadglobal(fqv[176]);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= loadglobal(fqv[179]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	w = local[1];
	local[1]= w;
	storeglobal(fqv[191],w);
	local[1]= loadglobal(fqv[191]);
	local[2]= fqv[190];
	local[3]= loadglobal(fqv[176]);
	local[4]= loadglobal(fqv[174]);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= loadglobal(fqv[192]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[184];
	local[4]= loadglobal(fqv[103]);
	local[5]= loadglobal(fqv[103]);
	ctx->vsp=local+6;
	w=(*ftab[15])(ctx,1,local+5,&ftab[15],fqv[150]); /*defaultscreen*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[26])(ctx,2,local+4,&ftab[26],fqv[193]); /*defaultcolormap*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	w = local[1];
	local[1]= w;
	storeglobal(fqv[194],w);
	local[1]= loadglobal(fqv[194]);
	local[2]= fqv[195];
	local[3]= fqv[194];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[50]);
	local[2]= fqv[196];
	local[3]= loadglobal(fqv[194]);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= fqv[197];
	local[2]= fqv[198];
	local[3]= loadglobal(fqv[172]);
	ctx->vsp=local+4;
	w=(*ftab[27])(ctx,3,local+1,&ftab[27],fqv[199]); /*create-ximage*/
	local[1]= w;
	storeglobal(fqv[200],w);
	local[1]= makeflt(5.00000000e-01);
	ctx->vsp=local+2;
	w=(*ftab[28])(ctx,1,local+1,&ftab[28],fqv[201]); /*make-gray-gc*/
	local[1]= w;
	storeglobal(fqv[202],w);
	local[1]= makeflt(5.00000000e-01);
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,1,local+1,&ftab[29],fqv[203]); /*make-gray-pixmap*/
	local[1]= w;
	storeglobal(fqv[204],w);
	local[1]= makeflt(2.50000000e-01);
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,1,local+1,&ftab[29],fqv[203]); /*make-gray-pixmap*/
	local[1]= w;
	storeglobal(fqv[205],w);
	local[1]= makeflt(5.00000000e-01);
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,1,local+1,&ftab[29],fqv[203]); /*make-gray-pixmap*/
	local[1]= w;
	storeglobal(fqv[206],w);
	local[1]= makeflt(7.50000000e-01);
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,1,local+1,&ftab[29],fqv[203]); /*make-gray-pixmap*/
	local[1]= w;
	storeglobal(fqv[207],w);
	local[1]= loadglobal(fqv[205]);
	ctx->vsp=local+2;
	w=(*ftab[30])(ctx,1,local+1,&ftab[30],fqv[208]); /*make-gc-from-pixmap*/
	local[1]= w;
	storeglobal(fqv[209],w);
	local[1]= loadglobal(fqv[206]);
	ctx->vsp=local+2;
	w=(*ftab[30])(ctx,1,local+1,&ftab[30],fqv[208]); /*make-gc-from-pixmap*/
	local[1]= w;
	storeglobal(fqv[210],w);
	local[1]= loadglobal(fqv[207]);
	ctx->vsp=local+2;
	w=(*ftab[30])(ctx,1,local+1,&ftab[30],fqv[208]); /*make-gc-from-pixmap*/
	local[1]= w;
	storeglobal(fqv[211],w);
	if (loadglobal(fqv[212])==NIL) goto IF3414;
	local[1]= loadglobal(fqv[213]);
	local[2]= fqv[214];
	ctx->vsp=local+3;
	w=(*ftab[31])(ctx,0,local+3,&ftab[31],fqv[215]); /*display-fd*/
	local[3]= w;
	local[4]= (pointer)get_sym_func(fqv[216]);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= loadglobal(fqv[105]);
	ctx->vsp=local+2;
	w=(pointer)ISATTY(ctx,1,local+1); /*unix:isatty*/
	if (w==NIL) goto IF3416;
	local[1]= fqv[217];
	ctx->vsp=local+2;
	w=(*ftab[12])(ctx,1,local+1,&ftab[12],fqv[108]); /*warn*/
	local[1]= w;
	goto IF3417;
IF3416:
	local[1]= NIL;
IF3417:
	goto IF3415;
IF3414:
	local[1]= NIL;
IF3415:
	goto CON3382;
CON3383:
	local[1]= makeint(1);
	local[2]= fqv[218];
	ctx->vsp=local+3;
	w=(*ftab[14])(ctx,2,local+1,&ftab[14],fqv[149]); /*warning-message*/
	local[1]= w;
	goto CON3382;
CON3418:
	local[1]= NIL;
CON3382:
	w = local[1];
	local[0]= w;
BLK3379:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___Xtop(ctx,n,argv,env)
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
	local[0]= fqv[219];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF3419;
	local[0]= fqv[220];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[221],w);
	goto IF3420;
IF3419:
	local[0]= fqv[222];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF3420:
	local[0]= fqv[223];
	local[1]= fqv[224];
	ctx->vsp=local+2;
	w=(*ftab[32])(ctx,2,local+0,&ftab[32],fqv[225]); /*require*/
	local[0]= fqv[226];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[7];
	local[1]= fqv[227];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3421;
	local[0]= fqv[7];
	local[1]= fqv[227];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[7];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3423;
	local[0]= fqv[7];
	local[1]= fqv[228];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3424;
IF3423:
	local[0]= NIL;
IF3424:
	local[0]= fqv[7];
	goto IF3422;
IF3421:
	local[0]= NIL;
IF3422:
	local[0]= fqv[85];
	local[1]= fqv[227];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3425;
	local[0]= fqv[85];
	local[1]= fqv[227];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[85];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3427;
	local[0]= fqv[85];
	local[1]= fqv[228];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3428;
IF3427:
	local[0]= NIL;
IF3428:
	local[0]= fqv[85];
	goto IF3426;
IF3425:
	local[0]= NIL;
IF3426:
	local[0]= fqv[229];
	local[1]= fqv[228];
	local[2]= fqv[230];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[231];
	local[1]= fqv[228];
	local[2]= fqv[232];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[233];
	local[1]= fqv[228];
	local[2]= fqv[234];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[235];
	local[1]= fqv[228];
	local[2]= fqv[236];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[237];
	local[1]= fqv[228];
	local[2]= fqv[238];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[239];
	local[1]= fqv[228];
	local[2]= fqv[240];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[241];
	local[1]= fqv[228];
	local[2]= fqv[242];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[243];
	local[1]= fqv[228];
	local[2]= makeint(65535);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[25];
	local[1]= fqv[228];
	local[2]= fqv[25];
	local[3]= fqv[244];
	local[4]= loadglobal(fqv[24]);
	local[5]= fqv[245];
	local[6]= fqv[246];
	local[7]= fqv[247];
	local[8]= NIL;
	local[9]= fqv[248];
	local[10]= NIL;
	local[11]= fqv[249];
	local[12]= makeint(-1);
	local[13]= fqv[250];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[33])(ctx,13,local+2,&ftab[33],fqv[251]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3310eustop_history_window_buttonpress,fqv[252],fqv[25],fqv[253]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3312eustop_history_window_buttonrelease,fqv[254],fqv[25],fqv[255]);
	local[0]= fqv[88];
	local[1]= fqv[228];
	local[2]= fqv[88];
	local[3]= fqv[244];
	local[4]= loadglobal(fqv[19]);
	local[5]= fqv[245];
	local[6]= fqv[256];
	local[7]= fqv[247];
	local[8]= NIL;
	local[9]= fqv[248];
	local[10]= NIL;
	local[11]= fqv[249];
	local[12]= makeint(-1);
	local[13]= fqv[250];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[33])(ctx,13,local+2,&ftab[33],fqv[251]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3314eustop_win_create,fqv[12],fqv[88],fqv[257]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3321eustop_win_attach,fqv[29],fqv[88],fqv[258]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3325eustop_win_detach,fqv[45],fqv[88],fqv[259]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3327eustop_win_filepanel,fqv[31],fqv[88],fqv[260]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3330eustop_win_refresh_history,fqv[33],fqv[88],fqv[261]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3339eustop_win_update_history,fqv[77],fqv[88],fqv[262]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3343eustop_win_update_gc,fqv[87],fqv[88],fqv[263]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3345eustop_win_configurenotify,fqv[264],fqv[88],fqv[265]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3350eustop_win_select,fqv[6],fqv[88],fqv[266]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3360eustop_win_alloc,fqv[37],fqv[88],fqv[267]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3362eustop_win_exit,fqv[35],fqv[88],fqv[268]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3364eustop_win_interval,fqv[40],fqv[88],fqv[269]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3366eustop_win_time_tick,fqv[86],fqv[88],fqv[270]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[95],module,F3304eustop_win_time_tick,fqv[271]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[89],module,F3305eustop_update_history,fqv[272]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[91],module,F3306eustop_update_gc,fqv[273]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[93],module,F3307eustop_exit,fqv[274]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[88],module,F3308eustop_win,fqv[275]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[276],module,F3309init_xwindow,fqv[277]);
	local[0]= fqv[278];
	local[1]= fqv[279];
	ctx->vsp=local+2;
	w=(*ftab[34])(ctx,2,local+0,&ftab[34],fqv[280]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<35; i++) ftab[i]=fcallx;
}
