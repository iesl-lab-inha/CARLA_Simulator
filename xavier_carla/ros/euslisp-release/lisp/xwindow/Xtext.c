/* ./Xtext.c :  entry=Xtext */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "Xtext.h"
#pragma init (register_Xtext)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___Xtext();
extern pointer build_quote_vector();
static int register_Xtext()
  { add_module_initializer("___Xtext", ___Xtext);}

static pointer F2528make_textwindow_stream();
static pointer F2529expand_tab();

/*:create*/
static pointer M2530characterwindow_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST2532:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[0], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY2533;
	local[1] = makeint(256);
KEY2533:
	if (n & (1<<1)) goto KEY2534;
	local[2] = makeint(256);
KEY2534:
	if (n & (1<<2)) goto KEY2535;
	local[3] = NIL;
KEY2535:
	if (n & (1<<3)) goto KEY2536;
	local[4] = NIL;
KEY2536:
	if (n & (1<<4)) goto KEY2537;
	local[5] = NIL;
KEY2537:
	if (n & (1<<5)) goto KEY2538;
	local[6] = fqv[1];
KEY2538:
	if (n & (1<<6)) goto KEY2539;
	local[7] = loadglobal(fqv[2]);
KEY2539:
	w = local[3];
	if (!isstring(w)) goto CON2541;
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[0])(ctx,1,local+8,&ftab[0],fqv[3]); /*font-id*/
	local[8]= w;
	goto CON2540;
CON2541:
	w = local[3];
	if (!isnum(w)) goto CON2542;
	local[8]= local[3];
	goto CON2540;
CON2542:
	local[8]= local[7];
	local[9]= loadglobal(fqv[2]);
	ctx->vsp=local+10;
	w=(pointer)EQ(ctx,2,local+8); /*eql*/
	if (w!=NIL) goto CON2543;
	local[8]= local[7];
	local[9]= loadglobal(fqv[4]);
	ctx->vsp=local+10;
	w=(pointer)DERIVEDP(ctx,2,local+8); /*derivedp*/
	if (w==NIL) goto CON2543;
	local[8]= local[7];
	local[9]= fqv[5];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	goto CON2540;
CON2543:
	local[8]= loadglobal(fqv[6]);
	goto CON2540;
CON2544:
	local[8]= NIL;
CON2540:
	argv[0]->c.obj.iv[12] = local[8];
	local[8]= fqv[7];
	local[9]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+10;
	w=(*ftab[1])(ctx,2,local+8,&ftab[1],fqv[8]); /*textdots*/
	local[8]= w;
	local[9]= local[8];
	local[10]= makeint(0);
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	local[10]= local[8];
	local[11]= makeint(1);
	ctx->vsp=local+12;
	w=(pointer)ELT(ctx,2,local+10); /*elt*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	argv[0]->c.obj.iv[14] = w;
	local[9]= local[8];
	local[10]= makeint(2);
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	argv[0]->c.obj.iv[13] = w;
	local[9]= local[8];
	local[10]= makeint(0);
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	argv[0]->c.obj.iv[15] = w;
	w = argv[0]->c.obj.iv[15];
	if (local[5]==NIL) goto CON2546;
	local[8]= makeint(4);
	local[9]= argv[0]->c.obj.iv[13];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[1] = w;
	local[8]= local[1];
	goto CON2545;
CON2546:
	if (local[1]==NIL) goto CON2547;
	local[8]= local[1];
	local[9]= makeint(4);
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[5] = w;
	local[8]= local[5];
	goto CON2545;
CON2547:
	local[8]= NIL;
CON2545:
	if (local[4]==NIL) goto CON2549;
	local[8]= makeint(4);
	local[9]= argv[0]->c.obj.iv[14];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[2] = w;
	local[8]= local[2];
	goto CON2548;
CON2549:
	if (local[2]==NIL) goto CON2550;
	local[8]= local[2];
	local[9]= makeint(4);
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[4] = w;
	local[8]= local[4];
	goto CON2548;
CON2550:
	local[8]= NIL;
CON2548:
	argv[0]->c.obj.iv[16] = local[4];
	argv[0]->c.obj.iv[17] = local[5];
	local[8]= (pointer)get_sym_func(fqv[9]);
	local[9]= argv[0];
	local[10]= *(ovafptr(argv[1],fqv[10]));
	local[11]= fqv[11];
	local[12]= fqv[12];
	local[13]= local[1];
	local[14]= fqv[13];
	local[15]= local[2];
	local[16]= fqv[14];
	local[17]= local[6];
	local[18]= fqv[5];
	local[19]= local[3];
	local[20]= fqv[15];
	local[21]= local[7];
	local[22]= local[0];
	ctx->vsp=local+23;
	w=(pointer)APPLY(ctx,15,local+8); /*apply*/
	local[8]= argv[0]->c.obj.iv[3];
	local[9]= fqv[5];
	local[10]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	w = argv[0];
	local[0]= w;
BLK2531:
	ctx->vsp=local; return(local[0]);}

/*:xy*/
static pointer M2551characterwindow_xy(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2555;}
	local[0]= makeint(0);
ENT2555:
	if (n>=4) { local[1]=(argv[3]); goto ENT2554;}
	local[1]= makeint(0);
ENT2554:
ENT2553:
	if (n>4) maerror();
	local[2]= makeint(2);
	local[3]= local[1];
	local[4]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	argv[0]->c.obj.iv[18] = w;
	local[2]= makeint(2);
	local[3]= local[0];
	local[4]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[15];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,3,local+2); /*+*/
	argv[0]->c.obj.iv[19] = w;
	w = argv[0]->c.obj.iv[19];
	local[0]= w;
BLK2552:
	ctx->vsp=local; return(local[0]);}

/*:clear-lines*/
static pointer M2556characterwindow_clear_lines(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[16];
	local[2]= fqv[17];
	local[3]= makeint(0);
	local[4]= fqv[18];
	local[5]= makeint(2);
	local[6]= argv[2];
	local[7]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= fqv[12];
	local[7]= argv[0]->c.obj.iv[5];
	local[8]= fqv[13];
	local[9]= argv[0]->c.obj.iv[14];
	local[10]= argv[3];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,10,local+0); /*send*/
	w = argv[3];
	local[0]= w;
BLK2557:
	ctx->vsp=local; return(local[0]);}

/*:put-line*/
static pointer M2558characterwindow_put_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[20];
	local[2]= argv[0]->c.obj.iv[18];
	local[3]= argv[0]->c.obj.iv[19];
	local[4]= argv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= w;
BLK2559:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M2560textwindow_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST2562:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[21], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY2563;
	local[1] = NIL;
KEY2563:
	if (n & (1<<1)) goto KEY2564;
	local[2] = NIL;
KEY2564:
	if (n & (1<<2)) goto KEY2565;
	local[3] = NIL;
KEY2565:
	if (n & (1<<3)) goto KEY2566;
	local[4] = NIL;
KEY2566:
	if (n & (1<<4)) goto KEY2567;
	local[5] = fqv[22];
KEY2567:
	if (n & (1<<5)) goto KEY2568;
	local[6] = NIL;
KEY2568:
	if (n & (1<<6)) goto KEY2569;
	local[7] = NIL;
KEY2569:
	if (n & (1<<7)) goto KEY2570;
	local[8] = NIL;
KEY2570:
	local[9]= (pointer)get_sym_func(fqv[9]);
	local[10]= argv[0];
	local[11]= *(ovafptr(argv[1],fqv[10]));
	local[12]= fqv[11];
	local[13]= fqv[14];
	local[14]= local[5];
	local[15]= local[0];
	ctx->vsp=local+16;
	w=(pointer)APPLY(ctx,7,local+9); /*apply*/
	local[9]= makeint(1);
	ctx->vsp=local+10;
	w=(*ftab[2])(ctx,1,local+9,&ftab[2],fqv[23]); /*make-string*/
	argv[0]->c.obj.iv[22] = w;
	local[9]= argv[0];
	local[10]= fqv[24];
	local[11]= local[7];
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,4,local+9); /*send*/
	local[9]= argv[0];
	local[10]= fqv[25];
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	argv[0]->c.obj.iv[27] = NIL;
	local[9]= argv[0]->c.obj.iv[3];
	local[10]= fqv[5];
	local[11]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= argv[0];
	local[10]= fqv[26];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= argv[0];
	local[10]= fqv[27];
	local[11]= fqv[28];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	w = argv[0];
	local[0]= w;
BLK2561:
	ctx->vsp=local; return(local[0]);}

/*:set-notify*/
static pointer M2571textwindow_set_notify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	argv[0]->c.obj.iv[28] = argv[2];
	argv[0]->c.obj.iv[29] = argv[3];
	w = argv[0];
	local[0]= w;
BLK2572:
	ctx->vsp=local; return(local[0]);}

/*:show-cursor*/
static pointer M2573textwindow_show_cursor(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[26] = argv[2];
	local[0]= argv[0];
	local[1]= fqv[27];
	if (argv[0]->c.obj.iv[27]==NIL) goto IF2575;
	local[2]= fqv[28];
	goto IF2576;
IF2575:
	local[2]= fqv[29];
IF2576:
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2574:
	ctx->vsp=local; return(local[0]);}

/*:cursor*/
static pointer M2577textwindow_cursor(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2580;}
	local[0]= fqv[30];
ENT2580:
ENT2579:
	if (n>3) maerror();
	if (argv[0]->c.obj.iv[26]==NIL) goto IF2581;
	local[1]= local[0];
	if (fqv[30]==local[1]) goto OR2583;
	local[1]= local[0];
	if (fqv[28]!=local[1]) goto AND2584;
	if (argv[0]->c.obj.iv[27]!=NIL) goto AND2584;
	goto OR2583;
AND2584:
	local[1]= local[0];
	if (fqv[29]!=local[1]) goto AND2585;
	if (argv[0]->c.obj.iv[27]==NIL) goto AND2585;
	goto OR2583;
AND2585:
	goto IF2581;
OR2583:
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[31];
	local[3]= fqv[32];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[19];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= loadglobal(fqv[33]);
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= argv[0]->c.obj.iv[3]->c.obj.iv[2];
	local[4]= argv[0]->c.obj.iv[18];
	local[5]= argv[0]->c.obj.iv[19];
	local[6]= argv[0]->c.obj.iv[15];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	local[6]= makeint(2);
	local[7]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+8;
	w=(*ftab[3])(ctx,7,local+1,&ftab[3],fqv[34]); /*fillrectangle*/
	argv[0]->c.obj.iv[27] = ((argv[0]->c.obj.iv[27])==NIL?T:NIL);
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[31];
	local[3]= fqv[35];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF2582;
IF2581:
	local[1]= NIL;
IF2582:
	w = local[1];
	local[0]= w;
BLK2578:
	ctx->vsp=local; return(local[0]);}

/*:win-row*/
static pointer M2586textwindow_win_row(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[20];
	local[0]= w;
BLK2587:
	ctx->vsp=local; return(local[0]);}

/*:win-col*/
static pointer M2588textwindow_win_col(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[21];
	local[0]= w;
BLK2589:
	ctx->vsp=local; return(local[0]);}

/*:win-row-max*/
static pointer M2590textwindow_win_row_max(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[16];
	local[0]= w;
BLK2591:
	ctx->vsp=local; return(local[0]);}

/*:win-col-max*/
static pointer M2592textwindow_win_col_max(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[17];
	local[0]= w;
BLK2593:
	ctx->vsp=local; return(local[0]);}

/*:xy*/
static pointer M2594textwindow_xy(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2598;}
	local[0]= argv[0]->c.obj.iv[20];
ENT2598:
	if (n>=4) { local[1]=(argv[3]); goto ENT2597;}
	local[1]= argv[0]->c.obj.iv[21];
ENT2597:
ENT2596:
	if (n>4) maerror();
	local[2]= makeint(2);
	local[3]= local[1];
	local[4]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	argv[0]->c.obj.iv[18] = w;
	local[2]= makeint(2);
	local[3]= local[0];
	local[4]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[15];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,3,local+2); /*+*/
	argv[0]->c.obj.iv[19] = w;
	w = argv[0]->c.obj.iv[19];
	local[0]= w;
BLK2595:
	ctx->vsp=local; return(local[0]);}

/*:goto*/
static pointer M2599textwindow_goto(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT2602;}
	local[0]= fqv[28];
ENT2602:
ENT2601:
	if (n>5) maerror();
	local[1]= argv[0];
	local[2]= fqv[27];
	local[3]= fqv[29];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+2;
	w=(pointer)SUB1(ctx,1,local+1); /*1-*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)MAX(ctx,2,local+2); /*max*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MIN(ctx,2,local+1); /*min*/
	argv[0]->c.obj.iv[20] = w;
	local[1]= argv[0]->c.obj.iv[17];
	ctx->vsp=local+2;
	w=(pointer)SUB1(ctx,1,local+1); /*1-*/
	local[1]= w;
	local[2]= argv[3];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)MAX(ctx,2,local+2); /*max*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MIN(ctx,2,local+1); /*min*/
	argv[0]->c.obj.iv[21] = w;
	local[1]= argv[0];
	local[2]= fqv[27];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK2600:
	ctx->vsp=local; return(local[0]);}

/*:goback*/
static pointer M2603textwindow_goback(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2606;}
	local[0]= fqv[28];
ENT2606:
ENT2605:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[36];
	local[3]= argv[0]->c.obj.iv[20];
	local[4]= makeint(0);
	local[5]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+6;
	w=(pointer)SUB1(ctx,1,local+5); /*1-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MAX(ctx,2,local+4); /*max*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[0]= w;
BLK2604:
	ctx->vsp=local; return(local[0]);}

/*:advance*/
static pointer M2607textwindow_advance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2610;}
	local[0]= makeint(1);
ENT2610:
ENT2609:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[21];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	argv[0]->c.obj.iv[21] = w;
	local[1]= argv[0]->c.obj.iv[20];
	local[2]= argv[0]->c.obj.iv[21];
	local[3]= argv[0]->c.obj.iv[17];
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	argv[0]->c.obj.iv[20] = w;
	local[1]= argv[0]->c.obj.iv[21];
	local[2]= argv[0]->c.obj.iv[17];
	ctx->vsp=local+3;
	w=(pointer)MOD(ctx,2,local+1); /*mod*/
	argv[0]->c.obj.iv[21] = w;
	w = argv[0]->c.obj.iv[21];
	local[0]= w;
BLK2608:
	ctx->vsp=local; return(local[0]);}

/*:scroll*/
static pointer M2611textwindow_scroll(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2614;}
	local[0]= makeint(1);
ENT2614:
ENT2613:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= local[0];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)NUMEQUAL(ctx,2,local+5); /*=*/
	if (w==NIL) goto CON2616;
	w = NIL;
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK2612;
	goto CON2615;
CON2616:
	local[5]= local[0];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto CON2617;
	local[2] = local[0];
	local[3] = makeint(0);
	local[5]= argv[0]->c.obj.iv[16];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[4] = w;
	local[5]= local[4];
	goto CON2615;
CON2617:
	local[2] = makeint(0);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[3] = w;
	local[4] = makeint(0);
	local[5]= local[4];
	goto CON2615;
CON2618:
	local[5]= NIL;
CON2615:
	local[5]= argv[0]->c.obj.iv[16];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)ABS(ctx,1,local+6); /*abs*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MIN(ctx,2,local+5); /*min*/
	local[0] = w;
	local[5]= loadglobal(fqv[33]);
	local[6]= argv[0]->c.obj.iv[2];
	local[7]= argv[0]->c.obj.iv[2];
	local[8]= argv[0]->c.obj.iv[3]->c.obj.iv[2];
	local[9]= makeint(2);
	local[10]= makeint(2);
	local[11]= local[2];
	local[12]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[10]= w;
	local[11]= argv[0]->c.obj.iv[5];
	local[12]= argv[0]->c.obj.iv[16];
	local[13]= local[0];
	ctx->vsp=local+14;
	w=(pointer)MINUS(ctx,2,local+12); /*-*/
	local[12]= w;
	local[13]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+14;
	w=(pointer)TIMES(ctx,2,local+12); /***/
	local[12]= w;
	local[13]= makeint(2);
	local[14]= makeint(2);
	local[15]= local[3];
	local[16]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+17;
	w=(pointer)TIMES(ctx,2,local+15); /***/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)PLUS(ctx,2,local+14); /*+*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(*ftab[4])(ctx,10,local+5,&ftab[4],fqv[37]); /*copyarea*/
	local[5]= loadglobal(fqv[33]);
	local[6]= argv[0]->c.obj.iv[2];
	local[7]= makeint(2);
	local[8]= makeint(2);
	local[9]= local[4];
	local[10]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[5];
	local[10]= local[0];
	local[11]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	local[11]= makeint(0);
	ctx->vsp=local+12;
	w=(*ftab[5])(ctx,7,local+5,&ftab[5],fqv[38]); /*cleararea*/
	local[0]= w;
BLK2612:
	ctx->vsp=local; return(local[0]);}

/*:horizontal-scroll*/
static pointer M2619textwindow_horizontal_scroll(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2622;}
	local[0]= makeint(1);
ENT2622:
ENT2621:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= local[0];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)NUMEQUAL(ctx,2,local+5); /*=*/
	if (w==NIL) goto CON2624;
	w = NIL;
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK2620;
	goto CON2623;
CON2624:
	local[5]= local[0];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto CON2625;
	local[2] = local[0];
	local[3] = makeint(0);
	local[5]= argv[0]->c.obj.iv[17];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[4] = w;
	local[5]= local[4];
	goto CON2623;
CON2625:
	local[2] = makeint(0);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[3] = w;
	local[4] = makeint(0);
	local[5]= local[4];
	goto CON2623;
CON2626:
	local[5]= NIL;
CON2623:
	local[5]= argv[0]->c.obj.iv[17];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)ABS(ctx,1,local+6); /*abs*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MIN(ctx,2,local+5); /*min*/
	local[0] = w;
	local[5]= loadglobal(fqv[33]);
	local[6]= argv[0]->c.obj.iv[2];
	local[7]= argv[0]->c.obj.iv[2];
	local[8]= argv[0]->c.obj.iv[3]->c.obj.iv[2];
	local[9]= makeint(2);
	local[10]= local[2];
	local[11]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	local[10]= makeint(2);
	local[11]= argv[0]->c.obj.iv[17];
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)MINUS(ctx,2,local+11); /*-*/
	local[11]= w;
	local[12]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	local[12]= argv[0]->c.obj.iv[6];
	local[13]= makeint(2);
	local[14]= local[3];
	local[15]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+16;
	w=(pointer)TIMES(ctx,2,local+14); /***/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,2,local+13); /*+*/
	local[13]= w;
	local[14]= makeint(2);
	ctx->vsp=local+15;
	w=(*ftab[4])(ctx,10,local+5,&ftab[4],fqv[37]); /*copyarea*/
	local[5]= loadglobal(fqv[33]);
	local[6]= argv[0]->c.obj.iv[2];
	local[7]= makeint(2);
	local[8]= local[4];
	local[9]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	local[8]= makeint(2);
	local[9]= local[0];
	local[10]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	local[10]= argv[0]->c.obj.iv[6];
	local[11]= makeint(0);
	ctx->vsp=local+12;
	w=(*ftab[5])(ctx,7,local+5,&ftab[5],fqv[38]); /*cleararea*/
	local[0]= w;
BLK2620:
	ctx->vsp=local; return(local[0]);}

/*:newline*/
static pointer M2627textwindow_newline(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[21] = makeint(0);
	local[0]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	argv[0]->c.obj.iv[20] = w;
	local[0]= argv[0]->c.obj.iv[20];
	local[1]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto IF2629;
	local[0]= argv[0];
	local[1]= fqv[39];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+1;
	w=(pointer)SUB1(ctx,1,local+0); /*1-*/
	argv[0]->c.obj.iv[20] = w;
	local[0]= argv[0]->c.obj.iv[20];
	goto IF2630;
IF2629:
	local[0]= NIL;
IF2630:
	w = local[0];
	local[0]= w;
BLK2628:
	ctx->vsp=local; return(local[0]);}

/*:clear*/
static pointer M2631textwindow_clear(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[27];
	local[2]= fqv[29];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[10]));
	local[2]= fqv[26];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	argv[0]->c.obj.iv[20] = makeint(0);
	argv[0]->c.obj.iv[21] = makeint(0);
	local[0]= argv[0];
	local[1]= fqv[27];
	local[2]= fqv[28];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	w = argv[0];
	local[0]= w;
BLK2632:
	ctx->vsp=local; return(local[0]);}

/*:clear-eol*/
static pointer M2633textwindow_clear_eol(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2638;}
	local[0]= argv[0]->c.obj.iv[20];
ENT2638:
	if (n>=4) { local[1]=(argv[3]); goto ENT2637;}
	local[1]= argv[0]->c.obj.iv[21];
ENT2637:
	if (n>=5) { local[2]=(argv[4]); goto ENT2636;}
	local[2]= fqv[28];
ENT2636:
ENT2635:
	if (n>5) maerror();
	local[3]= argv[0];
	local[4]= fqv[27];
	local[5]= fqv[29];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= fqv[17];
	local[6]= makeint(2);
	local[7]= local[1];
	local[8]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	local[7]= fqv[18];
	local[8]= makeint(2);
	local[9]= local[0];
	local[10]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	local[9]= fqv[12];
	local[10]= argv[0]->c.obj.iv[13];
	local[11]= argv[0]->c.obj.iv[17];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)MINUS(ctx,2,local+11); /*-*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	local[11]= fqv[13];
	local[12]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,10,local+3); /*send*/
	local[3]= argv[0];
	local[4]= fqv[27];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[0]= w;
BLK2634:
	ctx->vsp=local; return(local[0]);}

/*:clear-lines*/
static pointer M2639textwindow_clear_lines(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT2642;}
	local[0]= argv[0]->c.obj.iv[20];
ENT2642:
ENT2641:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[27];
	local[3]= fqv[29];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= fqv[17];
	local[4]= makeint(0);
	local[5]= fqv[18];
	local[6]= makeint(2);
	local[7]= local[0];
	local[8]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	local[7]= fqv[12];
	local[8]= argv[0]->c.obj.iv[5];
	local[9]= fqv[13];
	local[10]= argv[0]->c.obj.iv[14];
	local[11]= argv[2];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,10,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[27];
	local[3]= fqv[28];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK2640:
	ctx->vsp=local; return(local[0]);}

/*:clear-eos*/
static pointer M2643textwindow_clear_eos(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2647;}
	local[0]= argv[0]->c.obj.iv[20];
ENT2647:
	if (n>=4) { local[1]=(argv[3]); goto ENT2646;}
	local[1]= argv[0]->c.obj.iv[21];
ENT2646:
ENT2645:
	if (n>4) maerror();
	local[2]= argv[0];
	local[3]= fqv[27];
	local[4]= fqv[29];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[40];
	local[4]= local[0];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[16];
	local[4]= fqv[17];
	local[5]= makeint(0);
	local[6]= fqv[18];
	local[7]= makeint(2);
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	local[8]= fqv[12];
	local[9]= argv[0]->c.obj.iv[5];
	local[10]= fqv[13];
	local[11]= argv[0]->c.obj.iv[14];
	local[12]= argv[0]->c.obj.iv[16];
	local[13]= local[0];
	local[14]= makeint(1);
	ctx->vsp=local+15;
	w=(pointer)MINUS(ctx,3,local+12); /*-*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,10,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[27];
	local[4]= fqv[28];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0]= w;
BLK2644:
	ctx->vsp=local; return(local[0]);}

/*:clear-in-line*/
static pointer M2648textwindow_clear_in_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= fqv[16];
	local[2]= fqv[17];
	local[3]= makeint(2);
	local[4]= argv[0]->c.obj.iv[13];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	local[4]= fqv[18];
	local[5]= makeint(2);
	local[6]= argv[0]->c.obj.iv[14];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= fqv[12];
	local[7]= argv[0]->c.obj.iv[13];
	local[8]= argv[4];
	local[9]= argv[3];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,1,local+9); /*-*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	local[8]= fqv[13];
	local[9]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,10,local+0); /*send*/
	local[0]= w;
BLK2649:
	ctx->vsp=local; return(local[0]);}

/*:clear-text-area*/
static pointer M2650textwindow_clear_text_area(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[2];
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	if (w==NIL) goto IF2652;
	local[0]= argv[0];
	local[1]= fqv[41];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= argv[5];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= w;
	goto IF2653;
IF2652:
	local[0]= argv[0];
	local[1]= fqv[41];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= argv[0]->c.obj.iv[17];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= w;
IF2653:
	local[0]= argv[2];
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)SUB1(ctx,1,local+1); /*1-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF2654;
	local[0]= argv[0];
	local[1]= fqv[42];
	local[2]= argv[4];
	local[3]= argv[2];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,3,local+2); /*-*/
	local[2]= w;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2655;
IF2654:
	local[0]= NIL;
IF2655:
	local[0]= argv[4];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF2656;
	local[0]= argv[0];
	local[1]= fqv[41];
	local[2]= argv[4];
	local[3]= makeint(0);
	local[4]= argv[5];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= w;
	goto IF2657;
IF2656:
	local[0]= NIL;
IF2657:
	w = local[0];
	local[0]= w;
BLK2651:
	ctx->vsp=local; return(local[0]);}

/*:putch*/
static pointer M2658textwindow_putch(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[27];
	local[2]= fqv[29];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[2];
	local[1]= local[0];
	if (fqv[43]!=local[1]) goto IF2661;
	local[1]= argv[0];
	local[2]= fqv[44];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF2662;
IF2661:
	local[1]= local[0];
	if (fqv[45]!=local[1]) goto IF2663;
	local[1]= argv[0];
	local[2]= fqv[36];
	local[3]= argv[0]->c.obj.iv[20];
	local[4]= argv[0]->c.obj.iv[21];
	local[5]= makeint(8);
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	local[5]= makeint(8);
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	local[5]= makeint(8);
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF2664;
IF2663:
	if (T==NIL) goto IF2665;
	local[1]= argv[0];
	local[2]= fqv[19];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[22];
	local[2]= makeint(0);
	w = argv[2];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[2]); v=local[1];
	  v->c.str.chars[i]=intval(w);}
	local[1]= argv[0];
	local[2]= fqv[46];
	local[3]= argv[0]->c.obj.iv[18];
	local[4]= argv[0]->c.obj.iv[19];
	local[5]= argv[0]->c.obj.iv[22];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[47];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[20];
	local[2]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+3;
	w=(pointer)GREQP(ctx,2,local+1); /*>=*/
	if (w==NIL) goto IF2667;
	local[1]= argv[0];
	local[2]= fqv[39];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+2;
	w=(pointer)SUB1(ctx,1,local+1); /*1-*/
	argv[0]->c.obj.iv[20] = w;
	local[1]= argv[0]->c.obj.iv[20];
	goto IF2668;
IF2667:
	local[1]= NIL;
IF2668:
	local[1]= argv[2];
	goto IF2666;
IF2665:
	local[1]= NIL;
IF2666:
IF2664:
IF2662:
	w = local[1];
	local[0]= argv[0];
	local[1]= fqv[27];
	local[2]= fqv[28];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2659:
	ctx->vsp=local; return(local[0]);}

/*:putstring*/
static pointer M2669textwindow_putstring(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT2672;}
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
ENT2672:
ENT2671:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= makeint(0);
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[0];
	local[7]= fqv[27];
	local[8]= fqv[29];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
WHL2673:
	local[6]= local[3];
	w = local[0];
	if ((eusinteger_t)local[6] >= (eusinteger_t)w) goto WHX2674;
	local[6]= argv[0]->c.obj.iv[17];
	local[7]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[1] = w;
	local[6]= makeint(10);
	local[7]= argv[2];
	local[8]= fqv[48];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(*ftab[6])(ctx,4,local+6,&ftab[6],fqv[49]); /*position*/
	local[2] = w;
	local[6]= argv[0]->c.obj.iv[17];
	local[7]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	if (local[2]==NIL) goto IF2676;
	local[7]= local[2];
	goto IF2677;
IF2676:
	local[7]= local[0];
IF2677:
	ctx->vsp=local+8;
	w=(pointer)MIN(ctx,2,local+6); /*min*/
	local[4] = w;
	local[6]= argv[0];
	local[7]= fqv[40];
	local[8]= argv[0]->c.obj.iv[20];
	local[9]= argv[0]->c.obj.iv[21];
	local[10]= fqv[29];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,5,local+6); /*send*/
	local[6]= argv[0];
	local[7]= fqv[19];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= argv[0];
	local[7]= fqv[20];
	local[8]= argv[0]->c.obj.iv[18];
	local[9]= argv[0]->c.obj.iv[19];
	local[10]= argv[2];
	local[11]= local[3];
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,7,local+6); /*send*/
	local[6]= argv[0];
	local[7]= fqv[47];
	local[8]= local[4];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	if (local[2]==NIL) goto IF2678;
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[4] = w;
	local[6]= argv[0];
	local[7]= fqv[44];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	goto IF2679;
IF2678:
	local[6]= NIL;
IF2679:
	local[3] = local[4];
	goto WHL2673;
WHX2674:
	local[6]= NIL;
BLK2675:
	local[6]= argv[0];
	local[7]= fqv[27];
	local[8]= fqv[28];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[0]= w;
BLK2670:
	ctx->vsp=local; return(local[0]);}

/*:insert*/
static pointer M2680textwindow_insert(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[50];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2681:
	ctx->vsp=local; return(local[0]);}

/*:event-row*/
static pointer M2682textwindow_event_row(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
	local[3]= loadglobal(fqv[51]);
	ctx->vsp=local+4;
	w=(*ftab[7])(ctx,1,local+3,&ftab[7],fqv[52]); /*event-y*/
	local[3]= w;
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2683:
	ctx->vsp=local; return(local[0]);}

/*:event-col*/
static pointer M2684textwindow_event_col(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
	local[3]= loadglobal(fqv[51]);
	ctx->vsp=local+4;
	w=(*ftab[8])(ctx,1,local+3,&ftab[8],fqv[53]); /*event-x*/
	local[3]= w;
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2685:
	ctx->vsp=local; return(local[0]);}

/*:buttonpress*/
static pointer M2686textwindow_buttonpress(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
	local[3]= argv[0];
	local[4]= fqv[27];
	local[5]= fqv[29];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2687:
	ctx->vsp=local; return(local[0]);}

/*:buttonrelease*/
static pointer M2688textwindow_buttonrelease(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
	local[3]= argv[0];
	local[4]= fqv[36];
	local[5]= argv[0];
	local[6]= fqv[54];
	local[7]= loadglobal(fqv[51]);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	local[6]= argv[0];
	local[7]= fqv[55];
	local[8]= loadglobal(fqv[51]);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2689:
	ctx->vsp=local; return(local[0]);}

/*:resize*/
static pointer M2690textwindow_resize(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[10]));
	local[2]= fqv[56];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,5,local+0); /*send-message*/
	argv[0]->c.obj.iv[5] = argv[2];
	argv[0]->c.obj.iv[6] = argv[3];
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= makeint(4);
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	argv[0]->c.obj.iv[17] = w;
	local[0]= argv[0]->c.obj.iv[6];
	local[1]= makeint(4);
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	argv[0]->c.obj.iv[16] = w;
	local[0]= argv[0];
	local[1]= fqv[36];
	local[2]= argv[0]->c.obj.iv[20];
	local[3]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK2691:
	ctx->vsp=local; return(local[0]);}

/*:configurenotify*/
static pointer M2692textwindow_configurenotify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[13];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[3];
	local[6]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+7;
	w=(*ftab[9])(ctx,2,local+5,&ftab[9],fqv[57]); /*/=*/
	if (w!=NIL) goto OR2696;
	local[5]= local[4];
	local[6]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+7;
	w=(*ftab[9])(ctx,2,local+5,&ftab[9],fqv[57]); /*/=*/
	if (w!=NIL) goto OR2696;
	goto IF2694;
OR2696:
	local[5]= argv[0];
	local[6]= fqv[56];
	local[7]= local[3];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto IF2695;
IF2694:
	local[5]= NIL;
IF2695:
	w = local[5];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2693:
	ctx->vsp=local; return(local[0]);}

/*:echo*/
static pointer M2697textwindow_echo(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[25] = argv[2];
	w = argv[0]->c.obj.iv[25];
	local[0]= w;
BLK2698:
	ctx->vsp=local; return(local[0]);}

/*:getstring*/
static pointer M2699textwindow_getstring(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[23];
	local[1]= makeint(0);
	local[2]= argv[0]->c.obj.iv[24];
	ctx->vsp=local+3;
	w=(pointer)SUBSEQ(ctx,3,local+0); /*subseq*/
	local[0]= w;
	argv[0]->c.obj.iv[24] = makeint(0);
	w = local[0];
	local[0]= w;
BLK2700:
	ctx->vsp=local; return(local[0]);}

/*:enternotify*/
static pointer M2702textwindow_enternotify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
	if (argv[0]->c.obj.iv[2]==NIL) goto IF2704;
	local[3]= loadglobal(fqv[33]);
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= makeint(1);
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(*ftab[10])(ctx,4,local+3,&ftab[10],fqv[58]); /*setinputfocus*/
	local[3]= argv[0];
	local[4]= fqv[27];
	local[5]= fqv[28];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF2705;
IF2704:
	local[3]= NIL;
IF2705:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2703:
	ctx->vsp=local; return(local[0]);}

/*:leavenotify*/
static pointer M2706textwindow_leavenotify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
	local[3]= argv[0];
	local[4]= fqv[27];
	local[5]= fqv[29];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2707:
	ctx->vsp=local; return(local[0]);}

/*:keyrelease*/
static pointer M2708textwindow_keyrelease(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
	local[3]= NIL;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2709:
	ctx->vsp=local; return(local[0]);}

/*:lineenter*/
static pointer M2710textwindow_lineenter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT2713;}
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
ENT2713:
ENT2712:
	if (n>4) maerror();
	local[1]= argv[2];
	if (argv[0]->c.obj.iv[23]==local[1]) goto IF2714;
	local[1]= argv[0]->c.obj.iv[23];
	local[2]= argv[2];
	local[3]= fqv[59];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[11])(ctx,4,local+1,&ftab[11],fqv[60]); /*replace*/
	local[1]= w;
	goto IF2715;
IF2714:
	local[1]= NIL;
IF2715:
	w = local[1];
	local[0]= w;
BLK2711:
	ctx->vsp=local; return(local[0]);}

/*:keyenter*/
static pointer M2716textwindow_keyenter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT2719;}
	local[0]= NIL;
ENT2719:
	w = local[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
ENT2718:
	if (n>4) maerror();
	local[3]= argv[0];
	local[4]= fqv[61];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[2];
	local[4]= makeint(10);
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w==NIL) goto IF2720;
	if (argv[0]->c.obj.iv[28]==NIL) goto IF2720;
	if (argv[0]->c.obj.iv[29]==NIL) goto IF2720;
	local[3]= argv[0]->c.obj.iv[28];
	local[4]= argv[0]->c.obj.iv[29];
	local[5]= loadglobal(fqv[51]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF2721;
IF2720:
	local[3]= NIL;
IF2721:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2717:
	ctx->vsp=local; return(local[0]);}

/*:fill*/
static pointer M2722textwindowstream_fill(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= fqv[62];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK2723:
	ctx->vsp=local; return(local[0]);}

/*:flush*/
static pointer M2724textwindowstream_flush(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(0);
	local[1]= argv[0]->c.obj.iv[3];
WHL2727:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX2728;
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= fqv[50];
	local[4]= argv[0]->c.obj.iv[2];
	{ register eusinteger_t i=intval(local[0]);
	  w=makeint(local[4]->c.str.chars[i]);}
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL2727;
WHX2728:
	local[2]= NIL;
BLK2729:
	w = NIL;
	ctx->vsp=local+0;
	w=(*ftab[12])(ctx,0,local+0,&ftab[12],fqv[63]); /*xflush*/
	argv[0]->c.obj.iv[3] = makeint(0);
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK2725:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M2730textwindowstream_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[10]));
	local[2]= fqv[64];
	local[3]= argv[3];
	local[4]= makeint(256);
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,5,local+0); /*send-message*/
	argv[0]->c.obj.iv[5] = argv[2];
	w = argv[0];
	local[0]= w;
BLK2731:
	ctx->vsp=local; return(local[0]);}

/*make-textwindow-stream*/
static pointer F2528make_textwindow_stream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[65]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[64];
	local[3]= argv[0];
	local[4]= fqv[66];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
	local[1]= loadglobal(fqv[65]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[64];
	local[4]= argv[0];
	local[5]= fqv[67];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,2,local+0,&ftab[13],fqv[68]); /*make-two-way-stream*/
	local[0]= w;
BLK2732:
	ctx->vsp=local; return(local[0]);}

/*expand-tab*/
static pointer F2529expand_tab(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT2737;}
	local[0]= makeint(0);
ENT2737:
ENT2736:
	if (n>2) maerror();
	local[1]= makeint(9);
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[14])(ctx,2,local+1,&ftab[14],fqv[69]); /*count*/
	local[1]= w;
	local[2]= NIL;
	local[3]= makeint(0);
	local[4]= makeint(0);
	local[5]= NIL;
	local[6]= local[1];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)NUMEQUAL(ctx,2,local+6); /*=*/
	if (w==NIL) goto IF2738;
	local[6]= argv[0];
	goto IF2739;
IF2738:
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	local[7]= local[1];
	local[8]= makeint(8);
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[2])(ctx,1,local+6,&ftab[2],fqv[23]); /*make-string*/
	local[5] = w;
	local[6]= makeint(0);
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
WHL2741:
	local[8]= local[6];
	w = local[7];
	if ((eusinteger_t)local[8] >= (eusinteger_t)w) goto WHX2742;
	local[8]= argv[0];
	{ register eusinteger_t i=intval(local[6]);
	  w=makeint(local[8]->c.str.chars[i]);}
	local[2] = w;
	local[8]= local[2];
	local[9]= makeint(9);
	ctx->vsp=local+10;
	w=(pointer)EQ(ctx,2,local+8); /*eql*/
	if (w==NIL) goto CON2745;
	local[8]= makeint(8);
	local[9]= local[0];
	w = local[3];
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[9]= (pointer)((eusinteger_t)local[9] + (eusinteger_t)w);
	local[10]= makeint(8);
	ctx->vsp=local+11;
	w=(pointer)MOD(ctx,2,local+9); /*mod*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[4] = w;
	local[8]= local[5];
	local[9]= makeint(32);
	local[10]= fqv[48];
	local[11]= local[3];
	local[12]= fqv[70];
	local[13]= local[3];
	w = local[4];
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[13]= (pointer)((eusinteger_t)local[13] + (eusinteger_t)w);
	ctx->vsp=local+14;
	w=(*ftab[15])(ctx,6,local+8,&ftab[15],fqv[71]); /*fill*/
	local[8]= local[3];
	w = local[4];
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[3] = (pointer)((eusinteger_t)local[8] + (eusinteger_t)w);
	local[8]= local[3];
	goto CON2744;
CON2745:
	local[8]= local[5];
	local[9]= local[3];
	w = local[2];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[9]); v=local[8];
	  v->c.str.chars[i]=intval(w);}
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[3] = w;
	local[8]= local[3];
	goto CON2744;
CON2746:
	local[8]= NIL;
CON2744:
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[6] = w;
	goto WHL2741;
WHX2742:
	local[8]= NIL;
BLK2743:
	w = NIL;
	local[6]= local[5];
	local[7]= makeint(0);
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)SUBSEQ(ctx,3,local+6); /*subseq*/
	local[6]= w;
IF2739:
	w = local[6];
	local[0]= w;
BLK2735:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M2747buffertextwindow_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST2749:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[9]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[10]));
	local[4]= fqv[11];
	local[5]= fqv[14];
	local[6]= fqv[72];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,7,local+1); /*apply*/
	w = argv[0];
	local[0]= w;
BLK2748:
	ctx->vsp=local; return(local[0]);}

/*:redraw*/
static pointer M2750buffertextwindow_redraw(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[73];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK2751:
	ctx->vsp=local; return(local[0]);}

/*:clear*/
static pointer M2752buffertextwindow_clear(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[10]));
	local[2]= fqv[26];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	local[1]= fqv[74];
	local[2]= T;
	ctx->vsp=local+3;
	w=(*ftab[16])(ctx,3,local+0,&ftab[16],fqv[75]); /*make-array*/
	argv[0]->c.obj.iv[31] = w;
	local[0]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	local[1]= fqv[74];
	local[2]= T;
	ctx->vsp=local+3;
	w=(*ftab[16])(ctx,3,local+0,&ftab[16],fqv[75]); /*make-array*/
	argv[0]->c.obj.iv[32] = w;
	w = argv[0];
	local[0]= w;
BLK2753:
	ctx->vsp=local; return(local[0]);}

/*:refresh-line*/
static pointer M2754buffertextwindow_refresh_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2758;}
	local[0]= argv[0]->c.obj.iv[20];
ENT2758:
	if (n>=4) { local[1]=(argv[3]); goto ENT2757;}
	local[1]= argv[0]->c.obj.iv[21];
ENT2757:
ENT2756:
	if (n>4) maerror();
	local[2]= argv[0];
	local[3]= fqv[40];
	local[4]= local[0];
	local[5]= local[1];
	local[6]= fqv[29];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[19];
	local[4]= local[0];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[46];
	local[4]= argv[0]->c.obj.iv[18];
	local[5]= argv[0]->c.obj.iv[19];
	local[6]= argv[0]->c.obj.iv[32];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[0]= w;
BLK2755:
	ctx->vsp=local; return(local[0]);}

/*:refresh*/
static pointer M2759buffertextwindow_refresh(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2762;}
	local[0]= makeint(0);
ENT2762:
ENT2761:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[20];
	local[2]= argv[0]->c.obj.iv[21];
	local[3]= makeint(0);
	local[4]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
WHL2764:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX2765;
	local[5]= argv[0];
	local[6]= fqv[76];
	local[7]= local[3];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	local[8]= makeint(0);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL2764;
WHX2765:
	local[5]= NIL;
BLK2766:
	w = NIL;
	argv[0]->c.obj.iv[20] = local[1];
	argv[0]->c.obj.iv[21] = local[2];
	w = argv[0]->c.obj.iv[21];
	local[0]= w;
BLK2760:
	ctx->vsp=local; return(local[0]);}

/*:refresh-in-line*/
static pointer M2767buffertextwindow_refresh_in_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[32];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w!=NIL) goto IF2769;
	w = NIL;
	ctx->vsp=local+0;
	local[0]=w;
	goto BLK2768;
	goto IF2770;
IF2769:
	local[0]= NIL;
IF2770:
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[32];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	local[1]= argv[4];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MIN(ctx,2,local+1); /*min*/
	argv[4] = w;
	local[1]= argv[0];
	local[2]= fqv[46];
	local[3]= argv[0]->c.obj.iv[18];
	local[4]= argv[0]->c.obj.iv[19];
	local[5]= local[0];
	local[6]= argv[3];
	local[7]= argv[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,7,local+1); /*send*/
	local[0]= w;
BLK2768:
	ctx->vsp=local; return(local[0]);}

/*:refresh-lines*/
static pointer M2771buffertextwindow_refresh_lines(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= makeint(0);
	local[1]= argv[2];
WHL2774:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX2775;
	local[2]= argv[3];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[32];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w!=NIL) goto IF2777;
	w = NIL;
	ctx->vsp=local+2;
	local[2]=w;
	goto BLK2776;
	goto IF2778;
IF2777:
	local[2]= NIL;
IF2778:
	local[2]= argv[0];
	local[3]= fqv[19];
	local[4]= argv[3];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[46];
	local[4]= argv[0]->c.obj.iv[18];
	local[5]= argv[0]->c.obj.iv[19];
	local[6]= argv[0]->c.obj.iv[32];
	local[7]= argv[3];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL2774;
WHX2775:
	local[2]= NIL;
BLK2776:
	w = NIL;
	local[0]= w;
BLK2772:
	ctx->vsp=local; return(local[0]);}

/*:refresh-area*/
static pointer M2779buffertextwindow_refresh_area(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[2];
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w!=NIL) goto OR2783;
	local[0]= argv[2];
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	if (w==NIL) goto AND2784;
	local[0]= argv[3];
	local[1]= argv[5];
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto AND2784;
	goto OR2783;
AND2784:
	goto IF2781;
OR2783:
	local[0]= argv[4];
	local[1]= argv[5];
	local[2]= argv[2];
	local[3]= argv[3];
	argv[2] = local[0];
	argv[3] = local[1];
	argv[4] = local[2];
	argv[5] = local[3];
	w = NIL;
	local[0]= w;
	goto IF2782;
IF2781:
	local[0]= NIL;
IF2782:
	local[0]= argv[2];
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	if (w==NIL) goto IF2789;
	local[0]= argv[0];
	local[1]= fqv[77];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= argv[5];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= w;
	goto IF2790;
IF2789:
	local[0]= argv[0];
	local[1]= fqv[77];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= argv[0]->c.obj.iv[17];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= w;
IF2790:
	local[0]= argv[2];
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)SUB1(ctx,1,local+1); /*1-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF2791;
	local[0]= argv[0];
	local[1]= fqv[78];
	local[2]= argv[4];
	local[3]= argv[2];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,3,local+2); /*-*/
	local[2]= w;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2792;
IF2791:
	local[0]= NIL;
IF2792:
	local[0]= argv[4];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF2793;
	local[0]= argv[0];
	local[1]= fqv[77];
	local[2]= argv[4];
	local[3]= makeint(0);
	local[4]= argv[5];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= w;
	goto IF2794;
IF2793:
	local[0]= NIL;
IF2794:
	w = local[0];
	local[0]= w;
BLK2780:
	ctx->vsp=local; return(local[0]);}

/*:highlight*/
static pointer M2795buffertextwindow_highlight(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=7) maerror();
	if (argv[2]==NIL) goto IF2797;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[79];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF2798;
IF2797:
	local[0]= NIL;
IF2798:
	local[0]= argv[0];
	local[1]= fqv[80];
	local[2]= argv[3];
	local[3]= argv[4];
	local[4]= argv[5];
	local[5]= argv[6];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	if (argv[2]==NIL) goto IF2799;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[79];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF2800;
IF2799:
	local[0]= NIL;
IF2800:
	w = local[0];
	local[0]= w;
BLK2796:
	ctx->vsp=local; return(local[0]);}

/*:goto*/
static pointer M2801buffertextwindow_goto(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT2804;}
	local[0]= fqv[28];
ENT2804:
ENT2803:
	if (n>5) maerror();
	local[1]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)GREATERP(ctx,2,local+1); /*>*/
	if (w==NIL) goto IF2805;
	local[1]= argv[0]->c.obj.iv[31];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)MIN(ctx,2,local+1); /*min*/
	local[1]= w;
	goto IF2806;
IF2805:
	local[1]= makeint(0);
IF2806:
	argv[3] = local[1];
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[10]));
	local[3]= fqv[36];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,6,local+1); /*send-message*/
	local[0]= w;
BLK2802:
	ctx->vsp=local; return(local[0]);}

/*:line*/
static pointer M2807buffertextwindow_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF2809;
	local[0]= argv[0]->c.obj.iv[31];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	goto IF2810;
IF2809:
	local[0]= NIL;
IF2810:
	w = local[0];
	local[0]= w;
BLK2808:
	ctx->vsp=local; return(local[0]);}

/*:lines*/
static pointer M2811buffertextwindow_lines(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[31];
	local[0]= w;
BLK2812:
	ctx->vsp=local; return(local[0]);}

/*:nlines*/
static pointer M2813buffertextwindow_nlines(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
BLK2814:
	ctx->vsp=local; return(local[0]);}

/*:all-lines*/
static pointer M2815buffertextwindow_all_lines(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[31];
	local[0]= w;
BLK2816:
	ctx->vsp=local; return(local[0]);}

/*:max-line-length*/
static pointer M2817buffertextwindow_max_line_length(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= (pointer)get_sym_func(fqv[81]);
	local[1]= makeint(0);
	local[2]= loadglobal(fqv[82]);
	local[3]= (pointer)get_sym_func(fqv[83]);
	local[4]= argv[0]->c.obj.iv[32];
	ctx->vsp=local+5;
	w=(pointer)MAP(ctx,3,local+2); /*map*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,3,local+0); /*apply*/
	argv[0]->c.obj.iv[33] = w;
	w = argv[0]->c.obj.iv[33];
	local[0]= w;
BLK2818:
	ctx->vsp=local; return(local[0]);}

/*:read-file*/
static pointer M2819buffertextwindow_read_file(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[17])(ctx,1,local+0,&ftab[17],fqv[84]); /*open*/
	local[0]= w;
	ctx->vsp=local+1;
	w = makeclosure(codevec,quotevec,UWP2821,env,argv,local);
	local[1]=(pointer)(ctx->protfp); local[2]=w;
	ctx->protfp=(struct protectframe *)(local+1);
	local[3]= makeint(0);
	local[4]= NIL;
	w = NIL;
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= local[0];
	local[6]= NIL;
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)READLINE(ctx,3,local+5); /*read-line*/
	local[5]= w;
TAG2824:
	local[6]= local[5];
	if (local[4]!=local[6]) goto IF2825;
	w = NIL;
	ctx->vsp=local+6;
	local[3]=w;
	goto BLK2823;
	goto IF2826;
IF2825:
	local[6]= NIL;
IF2826:
	local[6]= local[5];
	local[7]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+8;
	w=(pointer)VECTOREXPUSH(ctx,2,local+6); /*vector-push-extend*/
	local[6]= local[5];
	ctx->vsp=local+7;
	w=(pointer)F2529expand_tab(ctx,1,local+6); /*expand-tab*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[32];
	ctx->vsp=local+8;
	w=(pointer)VECTOREXPUSH(ctx,2,local+6); /*vector-push-extend*/
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[3] = w;
	local[6]= local[0];
	local[7]= NIL;
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)READLINE(ctx,3,local+6); /*read-line*/
	local[5] = w;
	ctx->vsp=local+6;
	goto TAG2824;
	w = NIL;
	local[3]= w;
BLK2823:
	w = local[3];
	ctx->vsp=local+3;
	UWP2821(ctx,0,local+3,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= argv[0];
	local[1]= fqv[85];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[73];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = T;
	local[0]= w;
BLK2820:
	ctx->vsp=local; return(local[0]);}

/*:display-line-string*/
static pointer M2827buffertextwindow_display_line_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[86],w);
	local[3]= NIL;
	local[4]= NIL;
	local[5]= makeint(0);
	local[6]= T;
WHL2829:
	if (local[6]==NIL) goto WHX2830;
	local[7]= makeint(10);
	local[8]= loadglobal(fqv[86]);
	local[9]= fqv[48];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(*ftab[6])(ctx,4,local+7,&ftab[6],fqv[49]); /*position*/
	local[4] = w;
	if (local[4]!=NIL) goto CON2833;
	local[7]= loadglobal(fqv[86]);
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)SUBSEQ(ctx,2,local+7); /*subseq*/
	local[7]= w;
	w = local[3];
	ctx->vsp=local+8;
	local[3] = cons(ctx,local[7],w);
	local[6] = NIL;
	local[7]= local[6];
	goto CON2832;
CON2833:
	local[7]= loadglobal(fqv[86]);
	local[8]= local[5];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)SUBSEQ(ctx,3,local+7); /*subseq*/
	local[7]= w;
	w = local[3];
	ctx->vsp=local+8;
	local[3] = cons(ctx,local[7],w);
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[5] = w;
	local[7]= local[5];
	goto CON2832;
CON2834:
	local[7]= NIL;
CON2832:
	goto WHL2829;
WHX2830:
	local[7]= NIL;
BLK2831:
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)NREVERSE(ctx,1,local+7); /*nreverse*/
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	local[8]= fqv[87];
	local[9]= local[3];
	local[10]= fqv[74];
	local[11]= T;
	ctx->vsp=local+12;
	w=(*ftab[16])(ctx,5,local+7,&ftab[16],fqv[75]); /*make-array*/
	argv[0]->c.obj.iv[31] = w;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	local[8]= fqv[87];
	local[9]= local[3];
	local[10]= fqv[74];
	local[11]= T;
	ctx->vsp=local+12;
	w=(*ftab[16])(ctx,5,local+7,&ftab[16],fqv[75]); /*make-array*/
	argv[0]->c.obj.iv[32] = w;
	argv[0]->c.obj.iv[34] = NIL;
	local[7]= argv[0];
	local[8]= fqv[85];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= argv[0];
	local[8]= fqv[73];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[3]= T;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2828:
	ctx->vsp=local; return(local[0]);}

/*:display-strings*/
static pointer M2835buffertextwindow_display_strings(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	local[1]= fqv[87];
	local[2]= argv[2];
	local[3]= fqv[74];
	local[4]= T;
	ctx->vsp=local+5;
	w=(*ftab[16])(ctx,5,local+0,&ftab[16],fqv[75]); /*make-array*/
	argv[0]->c.obj.iv[31] = w;
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	local[1]= fqv[87];
	local[2]= argv[2];
	local[3]= fqv[74];
	local[4]= T;
	ctx->vsp=local+5;
	w=(*ftab[16])(ctx,5,local+0,&ftab[16],fqv[75]); /*make-array*/
	argv[0]->c.obj.iv[32] = w;
	local[0]= makeint(0);
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
WHL2838:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX2839;
	local[2]= argv[0]->c.obj.iv[32];
	local[3]= local[0];
	local[4]= argv[0]->c.obj.iv[32];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)F2529expand_tab(ctx,1,local+4); /*expand-tab*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL2838;
WHX2839:
	local[2]= NIL;
BLK2840:
	w = NIL;
	argv[0]->c.obj.iv[34] = NIL;
	local[0]= argv[0];
	local[1]= fqv[85];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[73];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = argv[0]->c.obj.iv[31];
	local[0]= w;
BLK2836:
	ctx->vsp=local; return(local[0]);}

/*:insert-string*/
static pointer M2841buffertextwindow_insert_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT2844;}
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
ENT2844:
ENT2843:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[31];
	local[2]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	local[3]= local[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[2])(ctx,1,local+3,&ftab[2],fqv[23]); /*make-string*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[27];
	local[6]= fqv[29];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= local[3];
	local[5]= local[1];
	local[6]= fqv[59];
	local[7]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+8;
	w=(*ftab[11])(ctx,4,local+4,&ftab[11],fqv[60]); /*replace*/
	local[4]= local[3];
	local[5]= argv[2];
	local[6]= fqv[88];
	local[7]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+8;
	w=(*ftab[11])(ctx,4,local+4,&ftab[11],fqv[60]); /*replace*/
	local[4]= local[3];
	local[5]= local[1];
	local[6]= fqv[88];
	local[7]= argv[0]->c.obj.iv[21];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	local[8]= fqv[89];
	local[9]= argv[0]->c.obj.iv[21];
	local[10]= fqv[59];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(*ftab[11])(ctx,8,local+4,&ftab[11],fqv[60]); /*replace*/
	local[4]= argv[0]->c.obj.iv[31];
	local[5]= argv[0]->c.obj.iv[20];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	local[4]= argv[0]->c.obj.iv[32];
	local[5]= argv[0]->c.obj.iv[20];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)F2529expand_tab(ctx,1,local+6); /*expand-tab*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	local[4]= argv[0];
	local[5]= fqv[76];
	local[6]= argv[0]->c.obj.iv[20];
	local[7]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[47];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[27];
	local[6]= fqv[28];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[0]= w;
BLK2842:
	ctx->vsp=local; return(local[0]);}

/*:insert*/
static pointer M2845buffertextwindow_insert(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[31];
	local[1]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,1,local+2,&ftab[2],fqv[23]); /*make-string*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[27];
	local[5]= fqv[29];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= local[2];
	local[4]= local[0];
	local[5]= fqv[59];
	local[6]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+7;
	w=(*ftab[11])(ctx,4,local+3,&ftab[11],fqv[60]); /*replace*/
	local[3]= local[2];
	local[4]= argv[0]->c.obj.iv[21];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,3,local+3); /*aset*/
	local[3]= local[2];
	local[4]= local[0];
	local[5]= fqv[88];
	local[6]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[6]= w;
	local[7]= fqv[89];
	local[8]= argv[0]->c.obj.iv[21];
	local[9]= fqv[59];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(*ftab[11])(ctx,8,local+3,&ftab[11],fqv[60]); /*replace*/
	local[3]= argv[0]->c.obj.iv[31];
	local[4]= argv[0]->c.obj.iv[20];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,3,local+3); /*aset*/
	local[3]= argv[0]->c.obj.iv[32];
	local[4]= argv[0]->c.obj.iv[20];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)F2529expand_tab(ctx,1,local+5); /*expand-tab*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,3,local+3); /*aset*/
	local[3]= argv[0];
	local[4]= fqv[47];
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[0];
	local[4]= fqv[76];
	local[5]= argv[0]->c.obj.iv[20];
	local[6]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+7;
	w=(pointer)SUB1(ctx,1,local+6); /*1-*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= argv[0];
	local[4]= fqv[27];
	local[5]= fqv[28];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[0]= w;
BLK2846:
	ctx->vsp=local; return(local[0]);}

/*:delete*/
static pointer M2847buffertextwindow_delete(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[21];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto IF2849;
	local[0]= argv[0]->c.obj.iv[31];
	local[1]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[27];
	local[3]= fqv[29];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= local[0];
	local[2]= local[0];
	local[3]= fqv[88];
	local[4]= argv[0]->c.obj.iv[21];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	local[5]= fqv[89];
	local[6]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+7;
	w=(*ftab[11])(ctx,6,local+1,&ftab[11],fqv[60]); /*replace*/
	local[1]= local[0];
	local[2]= makeint(0);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SUBSEQ(ctx,3,local+1); /*subseq*/
	local[0] = w;
	local[1]= argv[0]->c.obj.iv[31];
	local[2]= argv[0]->c.obj.iv[20];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,3,local+1); /*aset*/
	local[1]= argv[0]->c.obj.iv[32];
	local[2]= argv[0]->c.obj.iv[20];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F2529expand_tab(ctx,1,local+3); /*expand-tab*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,3,local+1); /*aset*/
	local[1]= argv[0]->c.obj.iv[21];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	argv[0]->c.obj.iv[21] = w;
	local[1]= argv[0];
	local[2]= fqv[76];
	local[3]= argv[0]->c.obj.iv[20];
	local[4]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[27];
	local[3]= fqv[28];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
	goto IF2850;
IF2849:
	local[0]= NIL;
IF2850:
	w = local[0];
	local[0]= w;
BLK2848:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP2821(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[0];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:keyenter*/
static pointer M2851buffertextwindow_keyenter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT2854;}
	local[0]= NIL;
ENT2854:
	w = local[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
ENT2853:
	if (n>4) maerror();
	local[3]= argv[2];
	local[4]= local[3];
	w = fqv[90];
	if (memq(local[4],w)==NIL) goto IF2856;
	local[4]= argv[0];
	local[5]= fqv[91];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	goto IF2857;
IF2856:
	local[4]= local[3];
	if (fqv[92]!=local[4]) goto IF2858;
	local[4]= argv[0];
	local[5]= fqv[93];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF2859;
IF2858:
	local[4]= local[3];
	if (fqv[94]!=local[4]) goto IF2860;
	local[4]= argv[0];
	local[5]= fqv[73];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	goto IF2861;
IF2860:
	local[4]= local[3];
	if (fqv[95]!=local[4]) goto IF2862;
	local[4]= argv[0];
	local[5]= fqv[27];
	local[6]= fqv[29];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= fqv[96];
	w = NIL;
	ctx->vsp=local+5;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	goto IF2863;
IF2862:
	local[4]= local[3];
	w = fqv[97];
	if (memq(local[4],w)==NIL) goto IF2864;
	local[4]= argv[0]->c.obj.iv[21];
	local[5]= argv[0]->c.obj.iv[31];
	local[6]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,2,local+4); /*<*/
	if (w==NIL) goto CON2867;
	local[4]= argv[0];
	local[5]= fqv[47];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[93];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto CON2866;
CON2867:
	local[4]= NIL;
CON2866:
	goto IF2865;
IF2864:
	local[4]= local[3];
	if (fqv[98]!=local[4]) goto IF2868;
	local[4]= argv[0];
	local[5]= fqv[27];
	local[6]= fqv[29];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[47];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[27];
	local[6]= fqv[28];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF2869;
IF2868:
	local[4]= local[3];
	w = fqv[99];
	if (memq(local[4],w)==NIL) goto IF2870;
	if (argv[0]->c.obj.iv[28]==NIL) goto IF2872;
	if (argv[0]->c.obj.iv[29]==NIL) goto IF2872;
	local[4]= argv[0]->c.obj.iv[28];
	local[5]= argv[0]->c.obj.iv[29];
	local[6]= loadglobal(fqv[51]);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF2873;
IF2872:
	local[4]= NIL;
IF2873:
	goto IF2871;
IF2870:
	if (T==NIL) goto IF2874;
	local[4]= argv[2];
	local[5]= makeint(32);
	ctx->vsp=local+6;
	w=(pointer)GREQP(ctx,2,local+4); /*>=*/
	if (w==NIL) goto IF2876;
	local[4]= argv[0];
	local[5]= fqv[61];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF2877;
IF2876:
	local[4]= NIL;
IF2877:
	goto IF2875;
IF2874:
	local[4]= NIL;
IF2875:
IF2871:
IF2869:
IF2865:
IF2863:
IF2861:
IF2859:
IF2857:
	w = local[4];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2852:
	ctx->vsp=local; return(local[0]);}

/*:buttonpress*/
static pointer M2878buffertextwindow_buttonpress(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
	if (argv[0]->c.obj.iv[30]==NIL) goto IF2880;
	if (argv[0]->c.obj.iv[34]==NIL) goto IF2880;
	local[3]= argv[0];
	local[4]= fqv[100];
	local[5]= NIL;
	local[6]= argv[0]->c.obj.iv[30];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[30];
	local[8]= makeint(1);
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[34];
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[34];
	local[10]= makeint(1);
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,7,local+3); /*send*/
	local[3]= w;
	goto IF2881;
IF2880:
	local[3]= NIL;
IF2881:
	local[3]= argv[0];
	local[4]= fqv[54];
	local[5]= loadglobal(fqv[51]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[55];
	local[6]= loadglobal(fqv[51]);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= local[3];
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)MKINTVECTOR(ctx,2,local+5); /*integer-vector*/
	argv[0]->c.obj.iv[30] = w;
	argv[0]->c.obj.iv[34] = argv[0]->c.obj.iv[30];
	w = argv[0]->c.obj.iv[34];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2879:
	ctx->vsp=local; return(local[0]);}

/*:region-direction*/
static pointer M2882buffertextwindow_region_direction(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[2];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto CON2885;
	local[0]= fqv[101];
	goto CON2884;
CON2885:
	local[0]= argv[2];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto CON2886;
	local[0]= fqv[102];
	goto CON2884;
CON2886:
	local[0]= argv[2];
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto CON2887;
	local[0]= fqv[101];
	goto CON2884;
CON2887:
	local[0]= fqv[102];
	goto CON2884;
CON2888:
	local[0]= NIL;
CON2884:
	w = local[0];
	local[0]= w;
BLK2883:
	ctx->vsp=local; return(local[0]);}

/*:motionnotify*/
static pointer M2889buffertextwindow_motionnotify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
	local[3]= argv[0];
	local[4]= fqv[54];
	local[5]= loadglobal(fqv[51]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[55];
	local[6]= loadglobal(fqv[51]);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[103];
	local[7]= argv[0]->c.obj.iv[34];
	local[8]= local[3];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	local[5]= w;
	local[6]= argv[0];
	local[7]= fqv[103];
	local[8]= argv[0]->c.obj.iv[34];
	local[9]= local[3];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,5,local+6); /*send*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= fqv[100];
	local[9]= NIL;
	local[10]= argv[0]->c.obj.iv[30];
	local[11]= makeint(0);
	ctx->vsp=local+12;
	w=(pointer)ELT(ctx,2,local+10); /*elt*/
	local[10]= w;
	local[11]= argv[0]->c.obj.iv[30];
	local[12]= makeint(1);
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	local[12]= argv[0]->c.obj.iv[34];
	local[13]= makeint(0);
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[12]= w;
	local[13]= argv[0]->c.obj.iv[34];
	local[14]= makeint(1);
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,7,local+7); /*send*/
	local[7]= argv[0];
	local[8]= fqv[100];
	local[9]= T;
	local[10]= argv[0]->c.obj.iv[30];
	local[11]= makeint(0);
	ctx->vsp=local+12;
	w=(pointer)ELT(ctx,2,local+10); /*elt*/
	local[10]= w;
	local[11]= argv[0]->c.obj.iv[30];
	local[12]= makeint(1);
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	local[12]= local[3];
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,7,local+7); /*send*/
	local[7]= local[3];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)MKINTVECTOR(ctx,2,local+7); /*integer-vector*/
	argv[0]->c.obj.iv[34] = w;
	w = argv[0]->c.obj.iv[34];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2890:
	ctx->vsp=local; return(local[0]);}

/*:buttonrelease*/
static pointer M2891buffertextwindow_buttonrelease(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
	local[3]= argv[0];
	local[4]= fqv[54];
	local[5]= loadglobal(fqv[51]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[55];
	local[6]= loadglobal(fqv[51]);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[36];
	local[7]= local[3];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[27];
	local[7]= fqv[28];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2892:
	ctx->vsp=local; return(local[0]);}

/*:selection*/
static pointer M2893buffertextwindow_selection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[30]==NIL) goto IF2895;
	if (argv[0]->c.obj.iv[34]==NIL) goto IF2895;
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[30];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[30];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[34];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[34];
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	local[5]= local[1];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w!=NIL) goto OR2899;
	local[5]= local[1];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)NUMEQUAL(ctx,2,local+5); /*=*/
	if (w==NIL) goto AND2900;
	local[5]= local[2];
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto AND2900;
	goto OR2899;
AND2900:
	goto IF2897;
OR2899:
	local[5]= local[3];
	local[6]= local[4];
	local[7]= local[1];
	local[8]= local[2];
	local[1] = local[5];
	local[2] = local[6];
	local[3] = local[7];
	local[4] = local[8];
	w = NIL;
	local[5]= w;
	goto IF2898;
IF2897:
	local[5]= NIL;
IF2898:
	local[5]= local[1];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)NUMEQUAL(ctx,2,local+5); /*=*/
	if (w==NIL) goto IF2905;
	local[5]= argv[0]->c.obj.iv[31];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= local[2];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SUBSEQ(ctx,3,local+5); /*subseq*/
	local[5]= w;
	w = local[0];
	ctx->vsp=local+6;
	local[0] = cons(ctx,local[5],w);
	local[5]= local[0];
	goto IF2906;
IF2905:
	local[5]= argv[0]->c.obj.iv[31];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)SUBSEQ(ctx,2,local+5); /*subseq*/
	local[5]= w;
	w = local[0];
	ctx->vsp=local+6;
	local[0] = cons(ctx,local[5],w);
	local[5]= local[0];
IF2906:
	local[5]= local[1];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)SUB1(ctx,1,local+6); /*1-*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LESSP(ctx,2,local+5); /*<*/
	if (w==NIL) goto IF2907;
	local[5]= makeint(0);
	local[6]= local[3];
	local[7]= local[1];
	local[8]= makeint(1);
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,3,local+6); /*-*/
	local[6]= w;
WHL2910:
	local[7]= local[5];
	w = local[6];
	if ((eusinteger_t)local[7] >= (eusinteger_t)w) goto WHX2911;
	local[7]= argv[0]->c.obj.iv[31];
	local[8]= local[1];
	local[9]= local[5];
	local[10]= makeint(1);
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,3,local+8); /*+*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,2,local+7); /*aref*/
	local[7]= w;
	w = local[0];
	ctx->vsp=local+8;
	local[0] = cons(ctx,local[7],w);
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[5] = w;
	goto WHL2910;
WHX2911:
	local[7]= NIL;
BLK2912:
	w = NIL;
	local[5]= w;
	goto IF2908;
IF2907:
	local[5]= NIL;
IF2908:
	local[5]= local[3];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto IF2913;
	local[5]= argv[0]->c.obj.iv[31];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= makeint(0);
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SUBSEQ(ctx,3,local+5); /*subseq*/
	local[5]= w;
	w = local[0];
	ctx->vsp=local+6;
	local[0] = cons(ctx,local[5],w);
	local[5]= local[0];
	goto IF2914;
IF2913:
	local[5]= NIL;
IF2914:
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)NREVERSE(ctx,1,local+5); /*nreverse*/
	local[0]= w;
	goto IF2896;
IF2895:
	local[0]= NIL;
IF2896:
	w = local[0];
	local[0]= w;
BLK2894:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M2915scrolltextwindow_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST2917:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[104], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY2918;
	local[1] = NIL;
KEY2918:
	if (n & (1<<1)) goto KEY2919;
	local[2] = NIL;
KEY2919:
	local[3]= (pointer)get_sym_func(fqv[9]);
	local[4]= argv[0];
	local[5]= *(ovafptr(argv[1],fqv[10]));
	local[6]= fqv[11];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,5,local+3); /*apply*/
	if (local[1]==NIL) goto IF2920;
	local[3]= loadglobal(fqv[105]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[11];
	local[6]= fqv[12];
	local[7]= makeint(12);
	local[8]= fqv[13];
	local[9]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+10;
	w=(pointer)SUB1(ctx,1,local+9); /*1-*/
	local[9]= w;
	local[10]= fqv[15];
	local[11]= argv[0];
	local[12]= fqv[106];
	local[13]= fqv[107];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,10,local+4); /*send*/
	w = local[3];
	argv[0]->c.obj.iv[39] = w;
	local[3]= argv[0]->c.obj.iv[39];
	goto IF2921;
IF2920:
	local[3]= NIL;
IF2921:
	if (local[2]==NIL) goto IF2923;
	local[3]= loadglobal(fqv[108]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[11];
	local[6]= fqv[12];
	if (local[1]==NIL) goto IF2926;
	local[7]= argv[0]->c.obj.iv[5];
	local[8]= argv[0]->c.obj.iv[39];
	local[9]= fqv[12];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= makeint(4);
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,3,local+7); /*-*/
	local[7]= w;
	goto IF2927;
IF2926:
	local[7]= argv[0]->c.obj.iv[5];
IF2927:
	local[8]= fqv[13];
	local[9]= makeint(12);
	local[10]= fqv[15];
	local[11]= argv[0];
	local[12]= fqv[106];
	local[13]= fqv[109];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,10,local+4); /*send*/
	w = local[3];
	argv[0]->c.obj.iv[40] = w;
	local[3]= argv[0]->c.obj.iv[40];
	goto IF2924;
IF2923:
	local[3]= NIL;
IF2924:
	local[3]= argv[0];
	local[4]= fqv[110];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	w = argv[0];
	local[0]= w;
BLK2916:
	ctx->vsp=local; return(local[0]);}

/*:locate-scroll-bar*/
static pointer M2928scrolltextwindow_locate_scroll_bar(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[39]==NIL) goto IF2930;
	local[0]= argv[0]->c.obj.iv[39];
	local[1]= fqv[56];
	local[2]= makeint(12);
	local[3]= argv[0]->c.obj.iv[6];
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[39];
	local[1]= fqv[111];
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= argv[0]->c.obj.iv[39];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,3,local+2); /*-*/
	local[2]= w;
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= argv[0]->c.obj.iv[39];
	local[2]= fqv[12];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= makeint(4);
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,3,local+0); /*-*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	argv[0]->c.obj.iv[17] = w;
	local[0]= argv[0]->c.obj.iv[17];
	goto IF2931;
IF2930:
	local[0]= NIL;
IF2931:
	if (argv[0]->c.obj.iv[40]==NIL) goto IF2932;
	local[0]= argv[0]->c.obj.iv[40];
	local[1]= fqv[56];
	if (argv[0]->c.obj.iv[39]==NIL) goto IF2934;
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= argv[0]->c.obj.iv[39];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= makeint(4);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,3,local+2); /*-*/
	local[2]= w;
	goto IF2935;
IF2934:
	local[2]= argv[0]->c.obj.iv[5];
IF2935:
	local[3]= makeint(12);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[40];
	local[1]= fqv[111];
	local[2]= makeint(0);
	local[3]= argv[0]->c.obj.iv[6];
	local[4]= argv[0]->c.obj.iv[40];
	local[5]= fqv[13];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,3,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[6];
	local[1]= argv[0]->c.obj.iv[40];
	local[2]= fqv[13];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,3,local+0); /*-*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	argv[0]->c.obj.iv[16] = w;
	local[0]= argv[0]->c.obj.iv[16];
	goto IF2933;
IF2932:
	local[0]= NIL;
IF2933:
	w = local[0];
	local[0]= w;
BLK2929:
	ctx->vsp=local; return(local[0]);}

/*:goto*/
static pointer M2936scrolltextwindow_goto(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT2939;}
	local[0]= fqv[28];
ENT2939:
ENT2938:
	if (n>5) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[10]));
	local[3]= fqv[36];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,6,local+1); /*send-message*/
	local[1]= argv[0]->c.obj.iv[20];
	local[2]= argv[0]->c.obj.iv[37];
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	argv[0]->c.obj.iv[35] = w;
	local[1]= argv[0]->c.obj.iv[21];
	local[2]= argv[0]->c.obj.iv[38];
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	argv[0]->c.obj.iv[36] = w;
	w = argv[0]->c.obj.iv[36];
	local[0]= w;
BLK2937:
	ctx->vsp=local; return(local[0]);}

/*:clear*/
static pointer M2940scrolltextwindow_clear(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[10]));
	local[2]= fqv[26];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	argv[0]->c.obj.iv[37] = makeint(0);
	argv[0]->c.obj.iv[38] = makeint(0);
	argv[0]->c.obj.iv[35] = makeint(0);
	argv[0]->c.obj.iv[36] = makeint(0);
	local[0]= fqv[112];
	local[1]= fqv[74];
	local[2]= T;
	ctx->vsp=local+3;
	w=(*ftab[16])(ctx,3,local+0,&ftab[16],fqv[75]); /*make-array*/
	argv[0]->c.obj.iv[31] = w;
	local[0]= fqv[113];
	local[1]= fqv[74];
	local[2]= T;
	ctx->vsp=local+3;
	w=(*ftab[16])(ctx,3,local+0,&ftab[16],fqv[75]); /*make-array*/
	argv[0]->c.obj.iv[32] = w;
	argv[0]->c.obj.iv[41] = NIL;
	local[0]= argv[0];
	local[1]= fqv[85];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = argv[0];
	local[0]= w;
BLK2941:
	ctx->vsp=local; return(local[0]);}

/*:lines*/
static pointer M2942scrolltextwindow_lines(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[31];
	local[0]= w;
BLK2943:
	ctx->vsp=local; return(local[0]);}

/*:refresh*/
static pointer M2944scrolltextwindow_refresh(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2948;}
	local[0]= makeint(0);
ENT2948:
	if (n>=4) { local[1]=(argv[3]); goto ENT2947;}
	local[1]= argv[0]->c.obj.iv[16];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
ENT2947:
ENT2946:
	if (n>4) maerror();
	local[2]= argv[0]->c.obj.iv[20];
	local[3]= argv[0]->c.obj.iv[21];
	local[4]= argv[0];
	local[5]= fqv[36];
	local[6]= local[0];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= argv[0];
	local[5]= *(ovafptr(argv[1],fqv[10]));
	local[6]= fqv[42];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SENDMESSAGE(ctx,4,local+4); /*send-message*/
	local[4]= argv[0];
	local[5]= fqv[27];
	local[6]= fqv[29];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= makeint(0);
	local[5]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	local[6]= local[0];
	local[7]= argv[0]->c.obj.iv[37];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,3,local+5); /*-*/
	local[5]= w;
	local[6]= local[1];
	local[7]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+8;
	w=(pointer)MIN(ctx,3,local+5); /*min*/
	local[5]= w;
WHL2950:
	local[6]= local[4];
	w = local[5];
	if ((eusinteger_t)local[6] >= (eusinteger_t)w) goto WHX2951;
	local[6]= argv[0];
	local[7]= fqv[19];
	local[8]= local[0];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[6]= argv[0];
	local[7]= fqv[20];
	local[8]= argv[0]->c.obj.iv[18];
	local[9]= argv[0]->c.obj.iv[19];
	local[10]= argv[0]->c.obj.iv[32];
	local[11]= local[0];
	local[12]= local[4];
	local[13]= argv[0]->c.obj.iv[37];
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,3,local+11); /*+*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,2,local+10); /*aref*/
	local[10]= w;
	local[11]= argv[0]->c.obj.iv[38];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,6,local+6); /*send*/
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[4] = w;
	goto WHL2950;
WHX2951:
	local[6]= NIL;
BLK2952:
	w = NIL;
	argv[0]->c.obj.iv[20] = local[2];
	argv[0]->c.obj.iv[21] = local[3];
	local[4]= argv[0];
	local[5]= fqv[19];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[27];
	local[6]= fqv[28];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	if (argv[0]->c.obj.iv[41]==NIL) goto IF2953;
	local[4]= argv[0];
	local[5]= fqv[76];
	local[6]= argv[0]->c.obj.iv[41];
	local[7]= T;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto IF2954;
IF2953:
	local[4]= NIL;
IF2954:
	if (argv[0]->c.obj.iv[39]==NIL) goto IF2955;
	local[4]= argv[0]->c.obj.iv[39];
	local[5]= fqv[114];
	local[6]= argv[0]->c.obj.iv[37];
	ctx->vsp=local+7;
	w=(pointer)EUSFLOAT(ctx,1,local+6); /*float*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	local[7]= makeflt(1.00000000e+00);
	local[8]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+9;
	w=(pointer)EUSFLOAT(ctx,1,local+8); /*float*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MIN(ctx,2,local+7); /*min*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto IF2956;
IF2955:
	local[4]= NIL;
IF2956:
	if (argv[0]->c.obj.iv[40]==NIL) goto IF2957;
	local[4]= argv[0]->c.obj.iv[40];
	local[5]= fqv[114];
	local[6]= argv[0]->c.obj.iv[38];
	ctx->vsp=local+7;
	w=(pointer)EUSFLOAT(ctx,1,local+6); /*float*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[33];
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	local[7]= makeflt(1.00000000e+00);
	local[8]= argv[0]->c.obj.iv[17];
	ctx->vsp=local+9;
	w=(pointer)EUSFLOAT(ctx,1,local+8); /*float*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[33];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MIN(ctx,2,local+7); /*min*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto IF2958;
IF2957:
	local[4]= NIL;
IF2958:
	w = local[4];
	local[0]= w;
BLK2945:
	ctx->vsp=local; return(local[0]);}

/*:line-in-window-p*/
static pointer M2959scrolltextwindow_line_in_window_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[37];
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[37];
	local[3]= argv[0]->c.obj.iv[16];
	local[4]= makeint(-1);
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,3,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LSEQP(ctx,3,local+0); /*<=*/
	local[0]= w;
BLK2960:
	ctx->vsp=local; return(local[0]);}

/*:refresh-line*/
static pointer M2961scrolltextwindow_refresh_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT2964;}
	local[0]= NIL;
ENT2964:
ENT2963:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0];
	local[5]= fqv[115];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	if (w==NIL) goto IF2965;
	local[4]= argv[0];
	local[5]= fqv[36];
	local[6]= argv[2];
	local[7]= argv[0]->c.obj.iv[37];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[40];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[19];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	if (local[0]==NIL) goto CON2968;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[116];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[2] = w;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[117];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[3] = w;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[116];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[117];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[46];
	local[6]= argv[0]->c.obj.iv[18];
	local[7]= argv[0]->c.obj.iv[19];
	local[8]= argv[0]->c.obj.iv[32];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[38];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,6,local+4); /*send*/
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[116];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[117];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto CON2967;
CON2968:
	local[4]= argv[0];
	local[5]= fqv[46];
	local[6]= argv[0]->c.obj.iv[18];
	local[7]= argv[0]->c.obj.iv[19];
	local[8]= argv[0]->c.obj.iv[32];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[38];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,6,local+4); /*send*/
	local[4]= w;
	goto CON2967;
CON2969:
	local[4]= NIL;
CON2967:
	goto IF2966;
IF2965:
	local[4]= NIL;
IF2966:
	w = local[4];
	local[0]= w;
BLK2962:
	ctx->vsp=local; return(local[0]);}

/*:locate*/
static pointer M2970scrolltextwindow_locate(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeint(0);
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SUB1(ctx,1,local+2); /*1-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LSEQP(ctx,3,local+0); /*<=*/
	if (w==NIL) goto IF2972;
	argv[0]->c.obj.iv[37] = argv[2];
	local[0]= argv[0];
	local[1]= fqv[73];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF2973;
IF2972:
	local[0]= NIL;
IF2973:
	w = local[0];
	local[0]= w;
BLK2971:
	ctx->vsp=local; return(local[0]);}

/*:display-selection*/
static pointer M2974scrolltextwindow_display_selection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[0]->c.obj.iv[41]==NIL) goto IF2976;
	local[0]= argv[0];
	local[1]= fqv[76];
	local[2]= argv[0]->c.obj.iv[41];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2977;
IF2976:
	local[0]= NIL;
IF2977:
	if (argv[2]==NIL) goto IF2978;
	local[0]= argv[0];
	local[1]= fqv[76];
	local[2]= argv[2];
	local[3]= T;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2979;
IF2978:
	local[0]= NIL;
IF2979:
	argv[0]->c.obj.iv[41] = argv[2];
	w = argv[0]->c.obj.iv[41];
	local[0]= w;
BLK2975:
	ctx->vsp=local; return(local[0]);}

/*:selection*/
static pointer M2980scrolltextwindow_selection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[41]==NIL) goto IF2982;
	local[0]= argv[0]->c.obj.iv[31];
	local[1]= argv[0]->c.obj.iv[41];
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	goto IF2983;
IF2982:
	local[0]= NIL;
IF2983:
	w = local[0];
	local[0]= w;
BLK2981:
	ctx->vsp=local; return(local[0]);}

/*:scroll-fraction*/
static pointer M2984scrolltextwindow_scroll_fraction(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeflt(1.00000000e+00);
	local[1]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
BLK2985:
	ctx->vsp=local; return(local[0]);}

/*:horizontal-scroll-fraction*/
static pointer M2986scrolltextwindow_horizontal_scroll_fraction(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeflt(1.00000000e+00);
	local[1]= argv[0]->c.obj.iv[33];
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
BLK2987:
	ctx->vsp=local; return(local[0]);}

/*:scroll*/
static pointer M2988scrolltextwindow_scroll(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[27];
	local[2]= fqv[29];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	w = argv[2];
	if (!isflt(w)) goto IF2990;
	local[0]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)ROUND(ctx,1,local+0); /*round*/
	argv[2] = w;
	local[0]= argv[2];
	goto IF2991;
IF2990:
	local[0]= NIL;
IF2991:
	local[0]= argv[2];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF2992;
	local[0]= argv[0]->c.obj.iv[37];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)ABS(ctx,1,local+1); /*abs*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MIN(ctx,2,local+0); /*min*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)MINUS(ctx,1,local+0); /*-*/
	local[0]= w;
	goto IF2993;
IF2992:
	local[0]= makeint(0);
	local[1]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[37];
	local[3]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,3,local+1); /*-*/
	local[1]= w;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)MIN(ctx,2,local+1); /*min*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MAX(ctx,2,local+0); /*max*/
	local[0]= w;
IF2993:
	argv[2] = local[0];
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[10]));
	local[2]= fqv[39];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SENDMESSAGE(ctx,4,local+0); /*send-message*/
	local[0]= argv[0]->c.obj.iv[37];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[37] = w;
	local[0]= argv[2];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto CON2995;
	local[0]= argv[0];
	local[1]= fqv[73];
	local[2]= makeint(0);
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)ABS(ctx,1,local+3); /*abs*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON2994;
CON2995:
	local[0]= argv[2];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto CON2996;
	local[0]= argv[0];
	local[1]= fqv[73];
	local[2]= argv[0]->c.obj.iv[16];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON2994;
CON2996:
	local[0]= NIL;
CON2994:
	local[0]= argv[0];
	local[1]= fqv[27];
	local[2]= fqv[28];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2989:
	ctx->vsp=local; return(local[0]);}

/*:horizontal-scroll*/
static pointer M2997scrolltextwindow_horizontal_scroll(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[27];
	local[2]= fqv[29];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	w = argv[2];
	if (!isflt(w)) goto IF2999;
	local[0]= argv[0]->c.obj.iv[33];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)ROUND(ctx,1,local+0); /*round*/
	argv[2] = w;
	local[0]= argv[2];
	goto IF3000;
IF2999:
	local[0]= NIL;
IF3000:
	local[0]= argv[2];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF3001;
	local[0]= argv[0]->c.obj.iv[38];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)ABS(ctx,1,local+1); /*abs*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MIN(ctx,2,local+0); /*min*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)MINUS(ctx,1,local+0); /*-*/
	local[0]= w;
	goto IF3002;
IF3001:
	local[0]= makeint(0);
	local[1]= argv[0]->c.obj.iv[33];
	local[2]= argv[0]->c.obj.iv[38];
	local[3]= argv[0]->c.obj.iv[17];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,3,local+1); /*-*/
	local[1]= w;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)MIN(ctx,2,local+1); /*min*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MAX(ctx,2,local+0); /*max*/
	local[0]= w;
IF3002:
	argv[2] = local[0];
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[10]));
	local[2]= fqv[118];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SENDMESSAGE(ctx,4,local+0); /*send-message*/
	local[0]= argv[0]->c.obj.iv[38];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[38] = w;
	local[0]= argv[0];
	local[1]= fqv[73];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[27];
	local[2]= fqv[28];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2998:
	ctx->vsp=local; return(local[0]);}

/*:insert-char*/
static pointer M3003scrolltextwindow_insert_char(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3006;}
	local[0]= T;
ENT3006:
ENT3005:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[31];
	local[2]= argv[0]->c.obj.iv[35];
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(*ftab[2])(ctx,1,local+3,&ftab[2],fqv[23]); /*make-string*/
	local[3]= w;
	local[4]= local[3];
	local[5]= makeint(0);
	w = argv[2];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[5]); v=local[4];
	  v->c.str.chars[i]=intval(w);}
	local[4]= loadglobal(fqv[86]);
	local[5]= local[1];
	local[6]= makeint(0);
	local[7]= argv[0]->c.obj.iv[36];
	ctx->vsp=local+8;
	w=(pointer)SUBSEQ(ctx,3,local+5); /*subseq*/
	local[5]= w;
	local[6]= local[3];
	local[7]= local[1];
	local[8]= argv[0]->c.obj.iv[36];
	ctx->vsp=local+9;
	w=(pointer)SUBSEQ(ctx,2,local+7); /*subseq*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)CONCATENATE(ctx,4,local+4); /*concatenate*/
	local[1] = w;
	local[4]= argv[0]->c.obj.iv[31];
	local[5]= argv[0]->c.obj.iv[35];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	local[4]= argv[0]->c.obj.iv[32];
	local[5]= argv[0]->c.obj.iv[35];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)F2529expand_tab(ctx,1,local+6); /*expand-tab*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	if (local[0]==NIL) goto IF3007;
	local[4]= argv[0];
	local[5]= fqv[76];
	local[6]= argv[0]->c.obj.iv[35];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF3008;
IF3007:
	local[4]= NIL;
IF3008:
	local[4]= argv[0];
	local[5]= fqv[47];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	if (local[0]==NIL) goto IF3009;
	local[4]= argv[0];
	local[5]= fqv[27];
	local[6]= fqv[28];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF3010;
IF3009:
	local[4]= NIL;
IF3010:
	w = local[4];
	local[0]= w;
BLK3004:
	ctx->vsp=local; return(local[0]);}

/*:insert-newline*/
static pointer M3011scrolltextwindow_insert_newline(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3014;}
	local[0]= T;
ENT3014:
ENT3013:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[40];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = NIL;
	local[0]= w;
BLK3012:
	ctx->vsp=local; return(local[0]);}

/*:insert*/
static pointer M3015scrolltextwindow_insert(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3018;}
	local[0]= T;
ENT3018:
ENT3017:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= fqv[119];
	ctx->vsp=local+3;
	w=(*ftab[18])(ctx,2,local+1,&ftab[18],fqv[120]); /*member*/
	if (w==NIL) goto CON3020;
	local[1]= argv[0];
	local[2]= fqv[121];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto CON3019;
CON3020:
	w = argv[2];
	if (!isnum(w)) goto CON3021;
	local[1]= argv[0];
	local[2]= fqv[122];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON3019;
CON3021:
	w = argv[2];
	if (!isstring(w)) goto CON3022;
	local[1]= makeint(0);
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
WHL3024:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX3025;
	local[3]= argv[0];
	local[4]= fqv[61];
	local[5]= argv[2];
	{ register eusinteger_t i=intval(local[1]);
	  w=makeint(local[5]->c.str.chars[i]);}
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL3024;
WHX3025:
	local[3]= NIL;
BLK3026:
	w = NIL;
	local[1]= w;
	goto CON3019;
CON3022:
	local[1]= NIL;
CON3019:
	w = local[1];
	local[0]= w;
BLK3016:
	ctx->vsp=local; return(local[0]);}

/*:buttonpress*/
static pointer M3027scrolltextwindow_buttonpress(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[10]));
	local[5]= fqv[123];
	local[6]= loadglobal(fqv[51]);
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,4,local+3); /*send-message*/
	local[3]= argv[0]->c.obj.iv[37];
	local[4]= argv[0];
	local[5]= fqv[54];
	local[6]= loadglobal(fqv[51]);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[38];
	local[5]= argv[0];
	local[6]= fqv[55];
	local[7]= loadglobal(fqv[51]);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SUB1(ctx,1,local+5); /*1-*/
	local[5]= w;
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)MIN(ctx,2,local+5); /*min*/
	argv[0]->c.obj.iv[35] = w;
	local[5]= argv[0]->c.obj.iv[31];
	local[6]= argv[0]->c.obj.iv[35];
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)MIN(ctx,2,local+5); /*min*/
	argv[0]->c.obj.iv[36] = w;
	local[5]= argv[0];
	local[6]= fqv[124];
	local[7]= argv[0]->c.obj.iv[35];
	local[8]= argv[0]->c.obj.iv[31];
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto IF3029;
	local[7]= argv[0]->c.obj.iv[35];
	goto IF3030;
IF3029:
	local[7]= NIL;
IF3030:
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3028:
	ctx->vsp=local; return(local[0]);}

/*:buttonrelease*/
static pointer M3031scrolltextwindow_buttonrelease(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
	local[3]= argv[0]->c.obj.iv[37];
	local[4]= argv[0];
	local[5]= fqv[54];
	local[6]= loadglobal(fqv[51]);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[38];
	local[5]= argv[0];
	local[6]= fqv[55];
	local[7]= loadglobal(fqv[51]);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[41];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)EQ(ctx,2,local+5); /*eql*/
	if (w==NIL) goto IF3033;
	if (argv[0]->c.obj.iv[28]==NIL) goto IF3033;
	if (argv[0]->c.obj.iv[29]==NIL) goto IF3033;
	local[5]= argv[0]->c.obj.iv[28];
	local[6]= argv[0]->c.obj.iv[29];
	local[7]= argv[0];
	local[8]= fqv[125];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF3034;
IF3033:
	local[5]= NIL;
IF3034:
	w = local[5];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3032:
	ctx->vsp=local; return(local[0]);}

/*:resize*/
static pointer M3035scrolltextwindow_resize(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[10]));
	local[2]= fqv[56];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,5,local+0); /*send-message*/
	local[0]= argv[0];
	local[1]= fqv[110];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[73];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK3036:
	ctx->vsp=local; return(local[0]);}

/*:configurenotify*/
static pointer M3037scrolltextwindow_configurenotify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[51],w);
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[13];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[3];
	local[6]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+7;
	w=(*ftab[9])(ctx,2,local+5,&ftab[9],fqv[57]); /*/=*/
	if (w!=NIL) goto OR3041;
	local[5]= local[4];
	local[6]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+7;
	w=(*ftab[9])(ctx,2,local+5,&ftab[9],fqv[57]); /*/=*/
	if (w!=NIL) goto OR3041;
	goto IF3039;
OR3041:
	local[5]= argv[0];
	local[6]= fqv[56];
	local[7]= local[3];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto IF3040;
IF3039:
	local[5]= NIL;
IF3040:
	w = local[5];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3038:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___Xtext(ctx,n,argv,env)
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
	local[0]= fqv[126];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= fqv[127];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF3042;
	local[0]= fqv[128];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[129],w);
	goto IF3043;
IF3042:
	local[0]= fqv[130];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF3043:
	local[0]= fqv[131];
	local[1]= fqv[132];
	ctx->vsp=local+2;
	w=(*ftab[19])(ctx,2,local+0,&ftab[19],fqv[133]); /*require*/
	local[0]= fqv[134];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[135];
	local[1]= fqv[136];
	local[2]= fqv[135];
	local[3]= fqv[137];
	local[4]= loadglobal(fqv[138]);
	local[5]= fqv[139];
	local[6]= fqv[140];
	local[7]= fqv[141];
	local[8]= NIL;
	local[9]= fqv[142];
	local[10]= NIL;
	local[11]= fqv[143];
	local[12]= makeint(-1);
	local[13]= fqv[144];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[20])(ctx,13,local+2,&ftab[20],fqv[145]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2530characterwindow_create,fqv[11],fqv[146],fqv[147]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2551characterwindow_xy,fqv[19],fqv[146],fqv[148]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2556characterwindow_clear_lines,fqv[42],fqv[146],fqv[149]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2558characterwindow_put_line,fqv[150],fqv[146],fqv[151]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2560textwindow_create,fqv[11],fqv[138],fqv[152]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2571textwindow_set_notify,fqv[24],fqv[138],fqv[153]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2573textwindow_show_cursor,fqv[25],fqv[138],fqv[154]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2577textwindow_cursor,fqv[27],fqv[138],fqv[155]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2586textwindow_win_row,fqv[156],fqv[138],fqv[157]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2588textwindow_win_col,fqv[158],fqv[138],fqv[159]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2590textwindow_win_row_max,fqv[160],fqv[138],fqv[161]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2592textwindow_win_col_max,fqv[162],fqv[138],fqv[163]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2594textwindow_xy,fqv[19],fqv[138],fqv[164]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2599textwindow_goto,fqv[36],fqv[138],fqv[165]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2603textwindow_goback,fqv[91],fqv[138],fqv[166]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2607textwindow_advance,fqv[47],fqv[138],fqv[167]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2611textwindow_scroll,fqv[39],fqv[138],fqv[168]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2619textwindow_horizontal_scroll,fqv[118],fqv[138],fqv[169]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2627textwindow_newline,fqv[44],fqv[138],fqv[170]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2631textwindow_clear,fqv[26],fqv[138],fqv[171]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2633textwindow_clear_eol,fqv[40],fqv[138],fqv[172]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2639textwindow_clear_lines,fqv[42],fqv[138],fqv[173]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2643textwindow_clear_eos,fqv[174],fqv[138],fqv[175]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2648textwindow_clear_in_line,fqv[41],fqv[138],fqv[176]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2650textwindow_clear_text_area,fqv[177],fqv[138],fqv[178]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2658textwindow_putch,fqv[50],fqv[138],fqv[179]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2669textwindow_putstring,fqv[180],fqv[138],fqv[181]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2680textwindow_insert,fqv[61],fqv[138],fqv[182]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2682textwindow_event_row,fqv[54],fqv[138],fqv[183]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2684textwindow_event_col,fqv[55],fqv[138],fqv[184]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2686textwindow_buttonpress,fqv[123],fqv[138],fqv[185]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2688textwindow_buttonrelease,fqv[186],fqv[138],fqv[187]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2690textwindow_resize,fqv[56],fqv[138],fqv[188]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2692textwindow_configurenotify,fqv[189],fqv[138],fqv[190]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2697textwindow_echo,fqv[191],fqv[138],fqv[192]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2699textwindow_getstring,fqv[62],fqv[138],fqv[193]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2702textwindow_enternotify,fqv[194],fqv[138],fqv[195]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2706textwindow_leavenotify,fqv[196],fqv[138],fqv[197]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2708textwindow_keyrelease,fqv[198],fqv[138],fqv[199]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2710textwindow_lineenter,fqv[200],fqv[138],fqv[201]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2716textwindow_keyenter,fqv[202],fqv[138],fqv[203]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2722textwindowstream_fill,fqv[204],fqv[65],fqv[205]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2724textwindowstream_flush,fqv[206],fqv[65],fqv[207]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2730textwindowstream_init,fqv[64],fqv[65],fqv[208]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[209],module,F2528make_textwindow_stream,fqv[210]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[211],module,F2529expand_tab,fqv[212]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2747buffertextwindow_create,fqv[11],fqv[213],fqv[214]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2750buffertextwindow_redraw,fqv[215],fqv[213],fqv[216]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2752buffertextwindow_clear,fqv[26],fqv[213],fqv[217]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2754buffertextwindow_refresh_line,fqv[76],fqv[213],fqv[218]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2759buffertextwindow_refresh,fqv[73],fqv[213],fqv[219]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2767buffertextwindow_refresh_in_line,fqv[77],fqv[213],fqv[220]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2771buffertextwindow_refresh_lines,fqv[78],fqv[213],fqv[221]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2779buffertextwindow_refresh_area,fqv[80],fqv[213],fqv[222]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2795buffertextwindow_highlight,fqv[100],fqv[213],fqv[223]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2801buffertextwindow_goto,fqv[36],fqv[213],fqv[224]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2807buffertextwindow_line,fqv[225],fqv[213],fqv[226]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2811buffertextwindow_lines,fqv[227],fqv[213],fqv[228]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2813buffertextwindow_nlines,fqv[229],fqv[213],fqv[230]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2815buffertextwindow_all_lines,fqv[231],fqv[213],fqv[232]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2817buffertextwindow_max_line_length,fqv[85],fqv[213],fqv[233]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2819buffertextwindow_read_file,fqv[234],fqv[213],fqv[235]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2827buffertextwindow_display_line_string,fqv[236],fqv[213],fqv[237]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2835buffertextwindow_display_strings,fqv[238],fqv[213],fqv[239]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2841buffertextwindow_insert_string,fqv[240],fqv[213],fqv[241]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2845buffertextwindow_insert,fqv[61],fqv[213],fqv[242]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2847buffertextwindow_delete,fqv[93],fqv[213],fqv[243]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2851buffertextwindow_keyenter,fqv[202],fqv[213],fqv[244]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2878buffertextwindow_buttonpress,fqv[123],fqv[213],fqv[245]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2882buffertextwindow_region_direction,fqv[103],fqv[213],fqv[246]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2889buffertextwindow_motionnotify,fqv[247],fqv[213],fqv[248]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2891buffertextwindow_buttonrelease,fqv[186],fqv[213],fqv[249]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2893buffertextwindow_selection,fqv[125],fqv[213],fqv[250]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2915scrolltextwindow_create,fqv[11],fqv[251],fqv[252]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2928scrolltextwindow_locate_scroll_bar,fqv[110],fqv[251],fqv[253]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2936scrolltextwindow_goto,fqv[36],fqv[251],fqv[254]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2940scrolltextwindow_clear,fqv[26],fqv[251],fqv[255]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2942scrolltextwindow_lines,fqv[227],fqv[251],fqv[256]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2944scrolltextwindow_refresh,fqv[73],fqv[251],fqv[257]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2959scrolltextwindow_line_in_window_p,fqv[115],fqv[251],fqv[258]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2961scrolltextwindow_refresh_line,fqv[76],fqv[251],fqv[259]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2970scrolltextwindow_locate,fqv[260],fqv[251],fqv[261]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2974scrolltextwindow_display_selection,fqv[124],fqv[251],fqv[262]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2980scrolltextwindow_selection,fqv[125],fqv[251],fqv[263]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2984scrolltextwindow_scroll_fraction,fqv[264],fqv[251],fqv[265]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2986scrolltextwindow_horizontal_scroll_fraction,fqv[266],fqv[251],fqv[267]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2988scrolltextwindow_scroll,fqv[39],fqv[251],fqv[268]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2997scrolltextwindow_horizontal_scroll,fqv[118],fqv[251],fqv[269]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3003scrolltextwindow_insert_char,fqv[122],fqv[251],fqv[270]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3011scrolltextwindow_insert_newline,fqv[121],fqv[251],fqv[271]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3015scrolltextwindow_insert,fqv[61],fqv[251],fqv[272]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3027scrolltextwindow_buttonpress,fqv[123],fqv[251],fqv[273]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3031scrolltextwindow_buttonrelease,fqv[186],fqv[251],fqv[274]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3035scrolltextwindow_resize,fqv[56],fqv[251],fqv[275]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3037scrolltextwindow_configurenotify,fqv[189],fqv[251],fqv[276]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<21; i++) ftab[i]=fcallx;
}
