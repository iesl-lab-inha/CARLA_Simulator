/* ./Xapplwin.c :  entry=Xapplwin */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "Xapplwin.h"
#pragma init (register_Xapplwin)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___Xapplwin();
extern pointer build_quote_vector();
static int register_Xapplwin()
  { add_module_initializer("___Xapplwin", ___Xapplwin);}

static pointer F3429ls_l();

/*:create-buttons*/
static pointer M3430filedialog_create_buttons(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= loadglobal(fqv[1]);
	local[3]= fqv[2];
	local[4]= argv[0];
	local[5]= fqv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	argv[0]->c.obj.iv[31] = w;
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= loadglobal(fqv[1]);
	local[3]= fqv[4];
	local[4]= argv[0];
	local[5]= fqv[5];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	argv[0]->c.obj.iv[32] = w;
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= loadglobal(fqv[1]);
	local[3]= fqv[6];
	local[4]= argv[0];
	local[5]= fqv[7];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	argv[0]->c.obj.iv[26] = w;
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= loadglobal(fqv[1]);
	local[3]= fqv[8];
	local[4]= argv[0];
	local[5]= fqv[9];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	argv[0]->c.obj.iv[34] = w;
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= loadglobal(fqv[1]);
	local[3]= fqv[10];
	local[4]= argv[0];
	local[5]= fqv[11];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	argv[0]->c.obj.iv[33] = w;
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= loadglobal(fqv[12]);
	local[3]= fqv[13];
	local[4]= argv[0];
	local[5]= fqv[7];
	local[6]= fqv[14];
	local[7]= makeint(23);
	local[8]= fqv[15];
	local[9]= loadglobal(fqv[16]);
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,10,local+0); /*send*/
	argv[0]->c.obj.iv[28] = w;
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= loadglobal(fqv[12]);
	local[3]= fqv[17];
	local[4]= argv[0];
	local[5]= fqv[7];
	local[6]= fqv[14];
	local[7]= makeint(46);
	local[8]= fqv[15];
	local[9]= loadglobal(fqv[16]);
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,10,local+0); /*send*/
	argv[0]->c.obj.iv[27] = w;
	w = argv[0]->c.obj.iv[27];
	local[0]= w;
BLK3431:
	ctx->vsp=local; return(local[0]);}

/*:create-fileview*/
static pointer M3432filedialog_create_fileview(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= loadglobal(fqv[18]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[19];
	local[3]= fqv[20];
	local[4]= argv[0];
	local[5]= fqv[21];
	local[6]= argv[0]->c.obj.iv[5];
	local[7]= makeint(15);
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	local[7]= fqv[22];
	local[8]= argv[0]->c.obj.iv[6];
	local[9]= argv[0]->c.obj.iv[18];
	local[10]= makeint(40);
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,3,local+8); /*-*/
	local[8]= w;
	local[9]= fqv[15];
	local[10]= argv[0];
	local[11]= fqv[15];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	local[11]= fqv[23];
	local[12]= T;
	local[13]= fqv[24];
	local[14]= T;
	local[15]= fqv[25];
	local[16]= NIL;
	local[17]= fqv[26];
	local[18]= argv[0];
	local[19]= fqv[27];
	local[20]= fqv[28];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,20,local+1); /*send*/
	w = local[0];
	argv[0]->c.obj.iv[29] = w;
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[29]); /*truename*/
	argv[0]->c.obj.iv[25] = w;
	local[0]= argv[0]->c.obj.iv[29];
	local[1]= fqv[30];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)F3429ls_l(ctx,1,local+2); /*ls-l*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	argv[0]->c.obj.iv[30] = argv[0]->c.obj.iv[18];
	local[0]= argv[0];
	local[1]= fqv[31];
	local[2]= argv[0]->c.obj.iv[29];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[27];
	local[1]= fqv[32];
	local[2]= argv[0]->c.obj.iv[25];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,1,local+2,&ftab[1],fqv[33]); /*namestring*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3433:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M3435filedialog_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3437:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[34], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3438;
	local[1] = loadglobal(fqv[16]);
KEY3438:
	if (n & (1<<1)) goto KEY3439;
	local[5]= loadglobal(fqv[35]);
	ctx->vsp=local+6;
	w=(*ftab[2])(ctx,0,local+6,&ftab[2],fqv[36]); /*pwd*/
	local[6]= w;
	local[7]= fqv[37];
	ctx->vsp=local+8;
	w=(pointer)CONCATENATE(ctx,3,local+5); /*concatenate*/
	local[2] = w;
KEY3439:
	if (n & (1<<2)) goto KEY3440;
	local[3] = NIL;
KEY3440:
	if (n & (1<<3)) goto KEY3441;
	local[4] = local[3];
KEY3441:
	local[5]= (pointer)get_sym_func(fqv[38]);
	local[6]= argv[0];
	local[7]= *(ovafptr(argv[1],fqv[39]));
	local[8]= fqv[19];
	local[9]= fqv[21];
	local[10]= makeint(380);
	local[11]= fqv[22];
	local[12]= makeint(330);
	local[13]= fqv[15];
	local[14]= local[1];
	local[15]= fqv[40];
	local[16]= fqv[41];
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)APPLY(ctx,13,local+5); /*apply*/
	local[5]= argv[0];
	local[6]= fqv[42];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[43];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	argv[0]->c.obj.iv[35] = local[3];
	argv[0]->c.obj.iv[36] = local[4];
	w = argv[0];
	local[0]= w;
BLK3436:
	ctx->vsp=local; return(local[0]);}

/*:cwd*/
static pointer M3442filedialog_cwd(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[27];
	local[1]= fqv[32];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK3443:
	ctx->vsp=local; return(local[0]);}

/*:file-selected*/
static pointer M3444filedialog_file_selected(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[29];
	local[1]= fqv[44];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= makeint(32);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[3])(ctx,2,local+3,&ftab[3],fqv[45]); /*position*/
	local[1] = w;
	if (local[1]==NIL) goto IF3446;
	local[3]= local[0];
	local[4]= makeint(0);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SUBSEQ(ctx,3,local+3); /*subseq*/
	local[2] = w;
	local[3]= argv[0]->c.obj.iv[28];
	local[4]= fqv[32];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= local[2];
	goto IF3447;
IF3446:
	local[3]= NIL;
IF3447:
	w = local[3];
	local[0]= w;
BLK3445:
	ctx->vsp=local; return(local[0]);}

/*:selected-fname*/
static pointer M3448filedialog_selected_fname(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[28];
	local[1]= fqv[32];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	w = makeint(0);
	if ((eusinteger_t)local[1] <= (eusinteger_t)w) goto IF3450;
	local[1]= argv[0]->c.obj.iv[28];
	local[2]= fqv[32];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[46];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[4])(ctx,2,local+1,&ftab[4],fqv[47]); /*merge-pathnames*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[29]); /*truename*/
	local[1]= w;
	goto IF3451;
IF3450:
	local[1]= argv[0];
	local[2]= fqv[46];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[29]); /*truename*/
	local[1]= w;
IF3451:
	w = local[1];
	local[0]= w;
BLK3449:
	ctx->vsp=local; return(local[0]);}

/*:view*/
static pointer M3452filedialog_view(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0];
	local[4]= fqv[49];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[5])(ctx,1,local+3,&ftab[5],fqv[50]); /*probe-file*/
	if (w==NIL) goto IF3454;
	local[3]= loadglobal(fqv[51]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[19];
	local[6]= fqv[52];
	local[7]= argv[0];
	local[8]= fqv[49];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= fqv[21];
	local[9]= makeint(500);
	local[10]= fqv[22];
	local[11]= makeint(500);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,8,local+4); /*send*/
	w = local[3];
	local[3]= w;
	goto IF3455;
IF3454:
	local[3]= NIL;
IF3455:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3453:
	ctx->vsp=local; return(local[0]);}

/*:ok*/
static pointer M3457filedialog_ok(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0];
	local[4]= fqv[53];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	if (argv[0]->c.obj.iv[35]==NIL) goto IF3459;
	local[3]= (pointer)get_sym_func(fqv[54]);
	w=argv[0]->c.obj.iv[35];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[35];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= argv[0];
	local[7]= fqv[49];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	w=argv[0]->c.obj.iv[35];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,5,local+3); /*apply*/
	local[3]= w;
	goto IF3460;
IF3459:
	local[3]= NIL;
IF3460:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3458:
	ctx->vsp=local; return(local[0]);}

/*:cancel*/
static pointer M3461filedialog_cancel(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0];
	local[4]= fqv[53];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	if (argv[0]->c.obj.iv[36]==NIL) goto IF3463;
	w=argv[0]->c.obj.iv[36];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[36];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= NIL;
	w=argv[0]->c.obj.iv[36];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.cdr;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF3464;
IF3463:
	local[3]= NIL;
IF3464:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3462:
	ctx->vsp=local; return(local[0]);}

/*:open*/
static pointer M3465filedialog_open(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0];
	local[4]= fqv[49];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,1,local+4,&ftab[1],fqv[33]); /*namestring*/
	local[3] = w;
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(*ftab[6])(ctx,1,local+4,&ftab[6],fqv[55]); /*lisp::directory-p*/
	if (w==NIL) goto IF3467;
	local[4]= loadglobal(fqv[35]);
	local[5]= local[3];
	local[6]= fqv[56];
	ctx->vsp=local+7;
	w=(pointer)CONCATENATE(ctx,3,local+4); /*concatenate*/
	argv[0]->c.obj.iv[25] = w;
	local[4]= argv[0]->c.obj.iv[28];
	local[5]= fqv[32];
	local[6]= fqv[57];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0]->c.obj.iv[29];
	local[5]= fqv[58];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= argv[0]->c.obj.iv[29];
	local[5]= fqv[30];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)F3429ls_l(ctx,1,local+6); /*ls-l*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0]->c.obj.iv[27];
	local[5]= fqv[32];
	local[6]= argv[0]->c.obj.iv[25];
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,1,local+6,&ftab[1],fqv[33]); /*namestring*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF3468;
IF3467:
	local[4]= NIL;
IF3468:
	w = local[4];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3466:
	ctx->vsp=local; return(local[0]);}

/*:go-up*/
static pointer M3469filedialog_go_up(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0];
	local[4]= fqv[46];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,1,local+3,&ftab[0],fqv[29]); /*truename*/
	local[3]= w;
	local[4]= fqv[59];
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(*ftab[7])(ctx,1,local+5,&ftab[7],fqv[60]); /*pathname-directory*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)BUTLAST(ctx,1,local+5); /*butlast*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[8])(ctx,2,local+4,&ftab[8],fqv[61]); /*make-pathname*/
	local[4]= w;
	local[5]= local[4];
	ctx->vsp=local+6;
	w=(*ftab[1])(ctx,1,local+5,&ftab[1],fqv[33]); /*namestring*/
	local[4] = w;
	argv[0]->c.obj.iv[25] = local[4];
	local[5]= argv[0]->c.obj.iv[27];
	local[6]= fqv[32];
	local[7]= argv[0]->c.obj.iv[25];
	ctx->vsp=local+8;
	w=(*ftab[1])(ctx,1,local+7,&ftab[1],fqv[33]); /*namestring*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0]->c.obj.iv[29];
	local[6]= fqv[58];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= argv[0]->c.obj.iv[29];
	local[6]= fqv[30];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)F3429ls_l(ctx,1,local+7); /*ls-l*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0]->c.obj.iv[28];
	local[6]= fqv[32];
	local[7]= fqv[62];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3470:
	ctx->vsp=local; return(local[0]);}

/*:resize*/
static pointer M3471filedialog_resize(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	argv[0]->c.obj.iv[5] = argv[2];
	argv[0]->c.obj.iv[6] = argv[3];
	local[0]= argv[0]->c.obj.iv[29];
	local[1]= fqv[63];
	local[2]= argv[2];
	local[3]= makeint(15);
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	local[3]= argv[3];
	local[4]= argv[0]->c.obj.iv[30];
	local[5]= makeint(40);
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,3,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK3472:
	ctx->vsp=local; return(local[0]);}

/*:configurenotify*/
static pointer M3473filedialog_configurenotify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0];
	local[4]= fqv[21];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[22];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[3];
	local[6]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+7;
	w=(*ftab[9])(ctx,2,local+5,&ftab[9],fqv[64]); /*/=*/
	if (w!=NIL) goto OR3477;
	local[5]= local[4];
	local[6]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+7;
	w=(*ftab[9])(ctx,2,local+5,&ftab[9],fqv[64]); /*/=*/
	if (w!=NIL) goto OR3477;
	goto IF3475;
OR3477:
	local[5]= argv[0];
	local[6]= fqv[63];
	local[7]= local[3];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto IF3476;
IF3475:
	local[5]= NIL;
IF3476:
	w = local[5];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3474:
	ctx->vsp=local; return(local[0]);}

/*:create-buttons*/
static pointer M3478filepanel_create_buttons(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[39]));
	local[2]= fqv[42];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= loadglobal(fqv[1]);
	local[3]= fqv[65];
	local[4]= argv[0];
	local[5]= fqv[66];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	argv[0]->c.obj.iv[40] = w;
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= loadglobal(fqv[1]);
	local[3]= fqv[67];
	local[4]= argv[0];
	local[5]= fqv[68];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	argv[0]->c.obj.iv[38] = w;
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= loadglobal(fqv[1]);
	local[3]= fqv[69];
	local[4]= argv[0];
	local[5]= fqv[70];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	argv[0]->c.obj.iv[37] = w;
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= loadglobal(fqv[1]);
	local[3]= fqv[71];
	local[4]= argv[0];
	local[5]= fqv[72];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	argv[0]->c.obj.iv[41] = w;
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= loadglobal(fqv[12]);
	local[3]= fqv[73];
	local[4]= argv[0];
	local[5]= fqv[74];
	local[6]= fqv[14];
	local[7]= makeint(47);
	local[8]= fqv[15];
	local[9]= loadglobal(fqv[16]);
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,10,local+0); /*send*/
	argv[0]->c.obj.iv[42] = w;
	w = argv[0]->c.obj.iv[42];
	local[0]= w;
BLK3479:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M3480filepanel_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3482:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[38]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[39]));
	local[4]= fqv[19];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	local[1]= loadglobal(fqv[75]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[19];
	local[4]= fqv[25];
	local[5]= NIL;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	argv[0]->c.obj.iv[43] = w;
	w = argv[0];
	local[0]= w;
BLK3481:
	ctx->vsp=local; return(local[0]);}

/*:load*/
static pointer M3484filepanel_load(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0];
	local[4]= fqv[49];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[10])(ctx,1,local+3,&ftab[10],fqv[76]); /*load*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3485:
	ctx->vsp=local; return(local[0]);}

/*:eval*/
static pointer M3486filepanel_eval(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0]->c.obj.iv[42];
	local[4]= fqv[32];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[11])(ctx,1,local+3,&ftab[11],fqv[77]); /*read-from-string*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)EVAL(ctx,1,local+3); /*eval*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PRINT(ctx,1,local+3); /*print*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3487:
	ctx->vsp=local; return(local[0]);}

/*:print*/
static pointer M3488filepanel_print(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0];
	local[4]= fqv[49];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	if (local[3]==NIL) goto IF3490;
	local[4]= NIL;
	local[5]= fqv[78];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,1,local+6,&ftab[1],fqv[33]); /*namestring*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SYSTEM(ctx,1,local+4); /*unix:system*/
	local[4]= w;
	goto IF3491;
IF3490:
	local[4]= NIL;
IF3491:
	w = local[4];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3489:
	ctx->vsp=local; return(local[0]);}

/*:compile*/
static pointer M3492filepanel_compile(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0];
	local[4]= fqv[49];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	if (local[3]==NIL) goto IF3494;
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,1,local+4,&ftab[1],fqv[33]); /*namestring*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[12])(ctx,1,local+4,&ftab[12],fqv[79]); /*compiler:compile-file*/
	local[4]= w;
	goto IF3495;
IF3494:
	local[4]= NIL;
IF3495:
	w = local[4];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3493:
	ctx->vsp=local; return(local[0]);}

/*:remove*/
static pointer M3496filepanel_remove(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0];
	local[4]= fqv[49];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[1])(ctx,1,local+3,&ftab[1],fqv[33]); /*namestring*/
	argv[0]->c.obj.iv[44] = w;
	local[3]= argv[0]->c.obj.iv[43];
	local[4]= fqv[80];
	local[5]= argv[0];
	local[6]= fqv[81];
	local[7]= fqv[82];
	local[8]= loadglobal(fqv[35]);
	local[9]= argv[0]->c.obj.iv[44];
	local[10]= fqv[83];
	ctx->vsp=local+11;
	w=(pointer)CONCATENATE(ctx,3,local+8); /*concatenate*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3497:
	ctx->vsp=local; return(local[0]);}

/*:remove-confirm*/
static pointer M3498filepanel_remove_confirm(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	if (fqv[84]!=local[0]) goto IF3500;
	local[0]= argv[0]->c.obj.iv[44];
	ctx->vsp=local+1;
	w=(pointer)PRINT(ctx,1,local+0); /*print*/
	local[0]= argv[0]->c.obj.iv[44];
	ctx->vsp=local+1;
	w=(pointer)UNLINK(ctx,1,local+0); /*unix:unlink*/
	local[0]= argv[0]->c.obj.iv[29];
	local[1]= fqv[58];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[29];
	local[1]= fqv[30];
	local[2]= argv[0];
	local[3]= fqv[46];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F3429ls_l(ctx,1,local+2); /*ls-l*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF3501;
IF3500:
	local[0]= NIL;
IF3501:
	argv[0]->c.obj.iv[44] = NIL;
	w = argv[0]->c.obj.iv[44];
	local[0]= w;
BLK3499:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M3502textviewpanel_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3504:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[85], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3505;
	local[1] = NIL;
KEY3505:
	if (n & (1<<1)) goto KEY3506;
	local[2] = NIL;
KEY3506:
	if (n & (1<<2)) goto KEY3507;
	local[3] = NIL;
KEY3507:
	if (n & (1<<3)) goto KEY3508;
	local[4] = NIL;
KEY3508:
	if (n & (1<<4)) goto KEY3509;
	local[5] = makeint(400);
KEY3509:
	local[6]= (pointer)get_sym_func(fqv[38]);
	local[7]= argv[0];
	local[8]= *(ovafptr(argv[1],fqv[39]));
	local[9]= fqv[19];
	local[10]= fqv[21];
	local[11]= local[5];
	local[12]= fqv[15];
	local[13]= local[1];
	local[14]= fqv[40];
	local[15]= fqv[86];
	local[16]= local[0];
	ctx->vsp=local+17;
	w=(pointer)APPLY(ctx,11,local+6); /*apply*/
	local[6]= argv[0];
	local[7]= fqv[0];
	local[8]= loadglobal(fqv[1]);
	local[9]= fqv[87];
	local[10]= argv[0];
	local[11]= fqv[88];
	local[12]= fqv[15];
	local[13]= loadglobal(fqv[16]);
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,8,local+6); /*send*/
	argv[0]->c.obj.iv[25] = w;
	local[6]= argv[0];
	local[7]= fqv[0];
	local[8]= loadglobal(fqv[1]);
	local[9]= fqv[89];
	local[10]= argv[0];
	local[11]= fqv[70];
	local[12]= fqv[15];
	local[13]= loadglobal(fqv[16]);
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,8,local+6); /*send*/
	argv[0]->c.obj.iv[27] = w;
	local[6]= argv[0];
	local[7]= fqv[0];
	local[8]= loadglobal(fqv[1]);
	local[9]= fqv[90];
	local[10]= argv[0];
	local[11]= fqv[91];
	local[12]= fqv[15];
	local[13]= loadglobal(fqv[16]);
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,8,local+6); /*send*/
	argv[0]->c.obj.iv[26] = w;
	local[6]= argv[0];
	local[7]= fqv[0];
	local[8]= loadglobal(fqv[12]);
	local[9]= fqv[92];
	local[10]= argv[0];
	local[11]= fqv[91];
	local[12]= fqv[15];
	local[13]= loadglobal(fqv[16]);
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,8,local+6); /*send*/
	argv[0]->c.obj.iv[30] = w;
	local[6]= argv[0];
	local[7]= fqv[31];
	local[8]= loadglobal(fqv[18]);
	ctx->vsp=local+9;
	w=(pointer)INSTANTIATE(ctx,1,local+8); /*instantiate*/
	local[8]= w;
	local[9]= local[8];
	local[10]= fqv[19];
	local[11]= fqv[21];
	local[12]= argv[0];
	local[13]= fqv[21];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[12]= w;
	local[13]= makeint(10);
	ctx->vsp=local+14;
	w=(pointer)MINUS(ctx,2,local+12); /*-*/
	local[5] = w;
	local[12]= local[5];
	local[13]= fqv[22];
	local[14]= argv[0];
	local[15]= fqv[22];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,2,local+14); /*send*/
	argv[0]->c.obj.iv[6] = w;
	local[14]= argv[0]->c.obj.iv[6];
	local[15]= makeint(60);
	ctx->vsp=local+16;
	w=(pointer)MINUS(ctx,2,local+14); /*-*/
	local[14]= w;
	local[15]= fqv[23];
	local[16]= T;
	local[17]= fqv[24];
	local[18]= T;
	local[19]= fqv[25];
	local[20]= NIL;
	local[21]= fqv[15];
	local[22]= local[1];
	local[23]= fqv[20];
	local[24]= argv[0];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,16,local+9); /*send*/
	w = local[8];
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	argv[0]->c.obj.iv[31] = w;
	if (local[2]==NIL) goto CON3512;
	argv[0]->c.obj.iv[28] = local[2];
	local[6]= argv[0]->c.obj.iv[31];
	local[7]= fqv[93];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	goto CON3511;
CON3512:
	if (local[4]==NIL) goto CON3513;
	local[6]= NIL;
	goto CON3511;
CON3513:
	if (local[3]==NIL) goto CON3514;
	local[6]= argv[0]->c.obj.iv[31];
	local[7]= fqv[30];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	goto CON3511;
CON3514:
	local[6]= NIL;
CON3511:
	w = argv[0];
	local[0]= w;
BLK3503:
	ctx->vsp=local; return(local[0]);}

/*:quit*/
static pointer M3515textviewpanel_quit(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0];
	local[4]= fqv[53];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= argv[0];
	local[4]= fqv[94];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3516:
	ctx->vsp=local; return(local[0]);}

/*:finish*/
static pointer M3517textviewpanel_finish(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= fqv[95];
	w = argv[0];
	ctx->vsp=local+4;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3518:
	ctx->vsp=local; return(local[0]);}

/*:print*/
static pointer M3519textviewpanel_print(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0]->c.obj.iv[28];
	local[4]= NIL;
	if (argv[0]->c.obj.iv[28]!=NIL) goto IF3521;
	local[5]= argv[0]->c.obj.iv[31];
	local[6]= fqv[96];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[4] = w;
	local[5]= NIL;
	local[6]= fqv[97];
	local[7]= argv[0];
	local[8]= fqv[98];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)GETPID(ctx,0,local+8); /*unix:getpid*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,4,local+5); /*format*/
	local[3] = w;
	local[5]= local[3];
	local[6]= fqv[99];
	local[7]= fqv[100];
	ctx->vsp=local+8;
	w=(*ftab[13])(ctx,3,local+5,&ftab[13],fqv[101]); /*open*/
	local[5]= w;
	ctx->vsp=local+6;
	w = makeclosure(codevec,quotevec,UWP3523,env,argv,local);
	local[6]=(pointer)(ctx->protfp); local[7]=w;
	ctx->protfp=(struct protectframe *)(local+6);
	local[8]= makeint(0);
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	local[9]= w;
WHL3525:
	local[10]= local[8];
	w = local[9];
	if ((eusinteger_t)local[10] >= (eusinteger_t)w) goto WHX3526;
	local[10]= local[5];
	local[11]= fqv[102];
	local[12]= local[4];
	local[13]= local[8];
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,3,local+10); /*format*/
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[8] = w;
	goto WHL3525;
WHX3526:
	local[10]= NIL;
BLK3527:
	w = NIL;
	ctx->vsp=local+8;
	UWP3523(ctx,0,local+8,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[5]= w;
	goto IF3522;
IF3521:
	local[5]= NIL;
IF3522:
	local[5]= NIL;
	local[6]= fqv[103];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(*ftab[1])(ctx,1,local+7,&ftab[1],fqv[33]); /*namestring*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,3,local+5); /*format*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SYSTEM(ctx,1,local+5); /*unix:system*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3520:
	ctx->vsp=local; return(local[0]);}

/*:find*/
static pointer M3528textviewpanel_find(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0]->c.obj.iv[30];
	local[4]= fqv[32];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= NIL;
	local[5]= argv[0]->c.obj.iv[31];
	local[6]= fqv[104];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= makeint(0);
TAG3532:
	local[7]= local[6];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)GREQP(ctx,2,local+7); /*>=*/
	if (w!=NIL) goto OR3535;
	if (local[4]!=NIL) goto OR3535;
	goto IF3533;
OR3535:
	w = NIL;
	ctx->vsp=local+7;
	local[6]=w;
	goto BLK3531;
	goto IF3534;
IF3533:
	local[7]= NIL;
IF3534:
	local[7]= local[3];
	local[8]= argv[0]->c.obj.iv[31];
	local[9]= fqv[105];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[14])(ctx,2,local+7,&ftab[14],fqv[106]); /*substringp*/
	if (w==NIL) goto IF3536;
	local[4] = local[6];
	local[7]= local[4];
	goto IF3537;
IF3536:
	local[7]= NIL;
IF3537:
	local[7]= local[6];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[7]= w;
	local[6] = local[7];
	w = NIL;
	ctx->vsp=local+7;
	goto TAG3532;
	w = NIL;
	local[6]= w;
BLK3531:
	if (local[4]==NIL) goto IF3539;
	local[6]= argv[0]->c.obj.iv[31];
	local[7]= fqv[107];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= argv[0]->c.obj.iv[31];
	local[7]= fqv[108];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	goto IF3540;
IF3539:
	local[6]= NIL;
IF3540:
	w = local[6];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3529:
	ctx->vsp=local; return(local[0]);}

/*:resize*/
static pointer M3541textviewpanel_resize(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	argv[0]->c.obj.iv[5] = argv[2];
	argv[0]->c.obj.iv[6] = argv[3];
	local[0]= argv[0]->c.obj.iv[31];
	local[1]= fqv[63];
	local[2]= argv[2];
	local[3]= makeint(10);
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	local[3]= argv[3];
	local[4]= makeint(38);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK3542:
	ctx->vsp=local; return(local[0]);}

/*:configurenotify*/
static pointer M3543textviewpanel_configurenotify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0];
	local[4]= fqv[21];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[22];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[3];
	local[6]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+7;
	w=(*ftab[9])(ctx,2,local+5,&ftab[9],fqv[64]); /*/=*/
	if (w!=NIL) goto OR3547;
	local[5]= local[4];
	local[6]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+7;
	w=(*ftab[9])(ctx,2,local+5,&ftab[9],fqv[64]); /*/=*/
	if (w!=NIL) goto OR3547;
	goto IF3545;
OR3547:
	local[5]= argv[0];
	local[6]= fqv[63];
	local[7]= local[3];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto IF3546;
IF3545:
	local[5]= NIL;
IF3546:
	w = local[5];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3544:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP3523(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[5];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*ls-l*/
static pointer F3429ls_l(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT3550;}
	local[0]= fqv[109];
ENT3550:
ENT3549:
	if (n>1) maerror();
	local[1]= fqv[110];
	local[2]= fqv[111];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[1])(ctx,1,local+3,&ftab[1],fqv[33]); /*namestring*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[15])(ctx,3,local+1,&ftab[15],fqv[112]); /*piped-fork*/
	local[1]= w;
	local[2]= NIL;
	w = NIL;
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= local[1];
	local[9]= NIL;
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)READLINE(ctx,3,local+8); /*read-line*/
WHL3551:
	local[8]= local[1];
	local[9]= NIL;
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)READLINE(ctx,3,local+8); /*read-line*/
	local[5] = w;
	local[8]= local[5];
	if (local[2]==local[8]) goto WHX3552;
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)NREVERSE(ctx,1,local+8); /*nreverse*/
	local[8]= makeint(32);
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(*ftab[3])(ctx,2,local+8,&ftab[3],fqv[45]); /*position*/
	local[6] = w;
	if (local[6]==NIL) goto IF3554;
	local[8]= local[5];
	local[9]= makeint(0);
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)SUBSEQ(ctx,3,local+8); /*subseq*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)NREVERSE(ctx,1,local+8); /*nreverse*/
	local[8]= w;
	goto IF3555;
IF3554:
	local[8]= fqv[113];
IF3555:
	local[3] = local[8];
	if (local[6]==NIL) goto IF3556;
	local[8]= local[5];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)SUBSEQ(ctx,2,local+8); /*subseq*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)NREVERSE(ctx,1,local+8); /*nreverse*/
	local[8]= w;
	goto IF3557;
IF3556:
	local[8]= fqv[114];
IF3557:
	local[5] = local[8];
	local[8]= NIL;
	local[9]= fqv[115];
	local[10]= local[3];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,4,local+8); /*format*/
	local[8]= w;
	w = local[4];
	ctx->vsp=local+9;
	local[4] = cons(ctx,local[8],w);
	goto WHL3551;
WHX3552:
	local[8]= NIL;
BLK3553:
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)CLOSE(ctx,1,local+8); /*close*/
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)NREVERSE(ctx,1,local+8); /*nreverse*/
	local[0]= w;
BLK3548:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M3558confirmpanel_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3560:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[38]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[39]));
	local[4]= fqv[19];
	local[5]= fqv[21];
	local[6]= makeint(400);
	local[7]= fqv[22];
	local[8]= makeint(260);
	local[9]= fqv[15];
	local[10]= loadglobal(fqv[116]);
	local[11]= fqv[117];
	local[12]= fqv[118];
	local[13]= fqv[25];
	local[14]= NIL;
	local[15]= fqv[40];
	local[16]= NIL;
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)APPLY(ctx,17,local+1); /*apply*/
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= loadglobal(fqv[1]);
	local[4]= fqv[119];
	local[5]= argv[0];
	local[6]= fqv[84];
	local[7]= fqv[15];
	local[8]= loadglobal(fqv[116]);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,8,local+1); /*send*/
	argv[0]->c.obj.iv[25] = w;
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= loadglobal(fqv[1]);
	local[4]= fqv[120];
	local[5]= argv[0];
	local[6]= fqv[121];
	local[7]= fqv[15];
	local[8]= loadglobal(fqv[116]);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,8,local+1); /*send*/
	argv[0]->c.obj.iv[26] = w;
	local[1]= argv[0]->c.obj.iv[25];
	local[2]= fqv[122];
	local[3]= makeint(70);
	local[4]= makeint(200);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[26];
	local[2]= fqv[122];
	local[3]= makeint(270);
	local[4]= makeint(200);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = argv[0];
	local[0]= w;
BLK3559:
	ctx->vsp=local; return(local[0]);}

/*:draw-message*/
static pointer M3561confirmpanel_draw_message(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(20);
	local[1]= makeint(50);
	local[2]= argv[0];
	local[3]= fqv[58];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= NIL;
	local[3]= argv[0]->c.obj.iv[28];
WHL3564:
	if (local[3]==NIL) goto WHX3565;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= argv[0];
	local[5]= fqv[123];
	local[6]= local[0];
	local[7]= local[1];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[4]= local[1];
	local[5]= makeint(30);
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[1] = w;
	goto WHL3564;
WHX3565:
	local[4]= NIL;
BLK3566:
	w = NIL;
	local[0]= w;
BLK3562:
	ctx->vsp=local; return(local[0]);}

/*:ask*/
static pointer M3568confirmpanel_ask(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
RST3570:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-4);
	argv[0]->c.obj.iv[27] = NIL;
	argv[0]->c.obj.iv[28] = local[0];
	local[1]= argv[0];
	local[2]= fqv[124];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[25];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	argv[0]->c.obj.iv[29] = argv[2];
	argv[0]->c.obj.iv[30] = argv[3];
	w = argv[0];
	local[0]= w;
BLK3569:
	ctx->vsp=local; return(local[0]);}

/*:yes*/
static pointer M3571confirmpanel_yes(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	argv[0]->c.obj.iv[27] = fqv[84];
	local[3]= argv[0];
	local[4]= fqv[125];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[29];
	local[4]= argv[0]->c.obj.iv[30];
	local[5]= fqv[84];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3572:
	ctx->vsp=local; return(local[0]);}

/*:no*/
static pointer M3573confirmpanel_no(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	argv[0]->c.obj.iv[27] = fqv[121];
	local[3]= argv[0];
	local[4]= fqv[125];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[29];
	local[4]= argv[0]->c.obj.iv[30];
	local[5]= fqv[121];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3574:
	ctx->vsp=local; return(local[0]);}

/*:configurenotify*/
static pointer M3575confirmpanel_configurenotify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= loadglobal(fqv[48]);
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,1,local+3,&ftab[16],fqv[126]); /*event-width*/
	local[3]= w;
	local[4]= loadglobal(fqv[48]);
	ctx->vsp=local+5;
	w=(*ftab[17])(ctx,1,local+4,&ftab[17],fqv[127]); /*event-height*/
	local[4]= w;
	local[5]= local[3];
	local[6]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+7;
	w=(*ftab[9])(ctx,2,local+5,&ftab[9],fqv[64]); /*/=*/
	if (w!=NIL) goto OR3579;
	local[5]= local[4];
	local[6]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+7;
	w=(*ftab[9])(ctx,2,local+5,&ftab[9],fqv[64]); /*/=*/
	if (w!=NIL) goto OR3579;
	goto IF3577;
OR3579:
	local[5]= argv[0];
	local[6]= fqv[124];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	goto IF3578;
IF3577:
	local[5]= NIL;
IF3578:
	w = local[5];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3576:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M3580colorpickerpanel_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3582:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[38]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[39]));
	local[4]= fqv[19];
	local[5]= fqv[21];
	local[6]= makeint(300);
	local[7]= fqv[22];
	local[8]= makeint(300);
	local[9]= fqv[15];
	local[10]= loadglobal(fqv[128]);
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)APPLY(ctx,11,local+1); /*apply*/
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= loadglobal(fqv[1]);
	local[4]= fqv[129];
	local[5]= argv[0];
	local[6]= fqv[3];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	argv[0]->c.obj.iv[25] = w;
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= loadglobal(fqv[1]);
	local[4]= fqv[130];
	local[5]= argv[0];
	local[6]= fqv[5];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	argv[0]->c.obj.iv[26] = w;
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= loadglobal(fqv[1]);
	local[4]= fqv[131];
	local[5]= argv[0];
	local[6]= fqv[132];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	argv[0]->c.obj.iv[27] = w;
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= loadglobal(fqv[1]);
	local[4]= fqv[133];
	local[5]= argv[0];
	local[6]= fqv[134];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	argv[0]->c.obj.iv[28] = w;
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= loadglobal(fqv[1]);
	local[4]= fqv[135];
	local[5]= argv[0];
	local[6]= fqv[136];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	argv[0]->c.obj.iv[29] = w;
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= loadglobal(fqv[1]);
	local[4]= fqv[137];
	local[5]= argv[0];
	local[6]= fqv[138];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	argv[0]->c.obj.iv[30] = w;
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= loadglobal(fqv[1]);
	local[4]= fqv[139];
	local[5]= argv[0];
	local[6]= fqv[140];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	argv[0]->c.obj.iv[34] = w;
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= loadglobal(fqv[1]);
	local[4]= fqv[141];
	local[5]= argv[0];
	local[6]= fqv[142];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	argv[0]->c.obj.iv[35] = w;
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= loadglobal(fqv[143]);
	local[4]= fqv[144];
	local[5]= argv[0];
	local[6]= fqv[145];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	argv[0]->c.obj.iv[31] = w;
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= loadglobal(fqv[143]);
	local[4]= fqv[146];
	local[5]= argv[0];
	local[6]= fqv[147];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	argv[0]->c.obj.iv[32] = w;
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= loadglobal(fqv[143]);
	local[4]= fqv[148];
	local[5]= argv[0];
	local[6]= fqv[149];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	argv[0]->c.obj.iv[33] = w;
	local[1]= makeflt(3.00000000e-01);
	local[2]= makeflt(4.00000000e-01);
	local[3]= makeflt(5.00000000e-01);
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	argv[0]->c.obj.iv[36] = w;
	local[1]= makeflt(5.00000000e-01);
	local[2]= makeflt(4.00000000e-01);
	local[3]= makeflt(3.00000000e-01);
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	argv[0]->c.obj.iv[37] = w;
	local[1]= makeflt(2.00000000e-01);
	local[2]= makeflt(2.00000000e-01);
	local[3]= makeflt(2.00000000e-01);
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	argv[0]->c.obj.iv[38] = w;
	local[1]= makeflt(1.00000000e-01);
	local[2]= makeflt(1.00000000e-01);
	local[3]= makeflt(1.00000000e-01);
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	argv[0]->c.obj.iv[39] = w;
	argv[0]->c.obj.iv[40] = makeflt(1.00000000e+01);
	argv[0]->c.obj.iv[41] = makeflt(0.00000000e+00);
	argv[0]->c.obj.iv[42] = NIL;
	argv[0]->c.obj.iv[43] = NIL;
	w = argv[0];
	local[0]= w;
BLK3581:
	ctx->vsp=local; return(local[0]);}

/*:init-value*/
static pointer M3583colorpickerpanel_init_value(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[132];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[36] = w;
	local[0]= argv[2];
	local[1]= fqv[134];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[37] = w;
	local[0]= argv[2];
	local[1]= fqv[136];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[38] = w;
	local[0]= argv[2];
	local[1]= fqv[138];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[39] = w;
	local[0]= argv[2];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[40] = w;
	local[0]= argv[2];
	local[1]= fqv[142];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[41] = w;
	w = NIL;
	local[0]= w;
BLK3584:
	ctx->vsp=local; return(local[0]);}

/*:value1*/
static pointer M3585colorpickerpanel_value1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)PRINT(ctx,1,local+0); /*print*/
	local[0]= w;
BLK3586:
	ctx->vsp=local; return(local[0]);}

/*:value2*/
static pointer M3587colorpickerpanel_value2(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)PRINT(ctx,1,local+0); /*print*/
	local[0]= w;
BLK3588:
	ctx->vsp=local; return(local[0]);}

/*:value3*/
static pointer M3589colorpickerpanel_value3(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)PRINT(ctx,1,local+0); /*print*/
	local[0]= w;
BLK3590:
	ctx->vsp=local; return(local[0]);}

/*:ambient*/
static pointer M3591colorpickerpanel_ambient(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0]->c.obj.iv[31];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[36];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[32];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[36];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[33];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[36];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3592:
	ctx->vsp=local; return(local[0]);}

/*:diffuse*/
static pointer M3593colorpickerpanel_diffuse(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0]->c.obj.iv[31];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[37];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[32];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[37];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[33];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[37];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3594:
	ctx->vsp=local; return(local[0]);}

/*:specular*/
static pointer M3595colorpickerpanel_specular(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0]->c.obj.iv[31];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[38];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[32];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[38];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[33];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[38];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3596:
	ctx->vsp=local; return(local[0]);}

/*:emission*/
static pointer M3597colorpickerpanel_emission(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0]->c.obj.iv[31];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[39];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[32];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[39];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[33];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[39];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3598:
	ctx->vsp=local; return(local[0]);}

/*:shininess*/
static pointer M3599colorpickerpanel_shininess(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0]->c.obj.iv[31];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[40];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3600:
	ctx->vsp=local; return(local[0]);}

/*:transparency*/
static pointer M3601colorpickerpanel_transparency(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[48],w);
	local[3]= argv[0]->c.obj.iv[31];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[41];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3602:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M3603objectbrowser_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3605:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[150], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3606;
	local[1] = makeint(350);
KEY3606:
	if (n & (1<<1)) goto KEY3607;
	local[2] = makeint(500);
KEY3607:
	local[3]= (pointer)get_sym_func(fqv[38]);
	local[4]= argv[0];
	local[5]= *(ovafptr(argv[1],fqv[39]));
	local[6]= fqv[19];
	local[7]= fqv[21];
	local[8]= local[1];
	local[9]= fqv[22];
	local[10]= local[2];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)APPLY(ctx,9,local+3); /*apply*/
	local[3]= argv[0];
	local[4]= fqv[0];
	local[5]= loadglobal(fqv[12]);
	local[6]= fqv[151];
	local[7]= argv[0];
	local[8]= fqv[152];
	local[9]= fqv[15];
	local[10]= loadglobal(fqv[16]);
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,8,local+3); /*send*/
	argv[0]->c.obj.iv[25] = w;
	local[3]= argv[0];
	local[4]= fqv[0];
	local[5]= loadglobal(fqv[12]);
	local[6]= fqv[153];
	local[7]= argv[0];
	local[8]= fqv[154];
	local[9]= fqv[15];
	local[10]= loadglobal(fqv[16]);
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,8,local+3); /*send*/
	argv[0]->c.obj.iv[26] = w;
	local[3]= argv[0];
	local[4]= fqv[0];
	local[5]= loadglobal(fqv[1]);
	local[6]= fqv[155];
	local[7]= argv[0];
	local[8]= fqv[156];
	local[9]= fqv[15];
	local[10]= loadglobal(fqv[116]);
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,8,local+3); /*send*/
	argv[0]->c.obj.iv[28] = w;
	local[3]= argv[0];
	local[4]= fqv[0];
	local[5]= loadglobal(fqv[1]);
	local[6]= fqv[157];
	local[7]= argv[0];
	local[8]= fqv[158];
	local[9]= fqv[15];
	local[10]= loadglobal(fqv[116]);
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,8,local+3); /*send*/
	argv[0]->c.obj.iv[27] = w;
	local[3]= loadglobal(fqv[51]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[19];
	local[6]= fqv[20];
	local[7]= argv[0];
	local[8]= fqv[21];
	local[9]= argv[0];
	local[10]= fqv[21];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	local[10]= fqv[22];
	local[11]= argv[0];
	local[12]= fqv[22];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	local[12]= makeint(120);
	ctx->vsp=local+13;
	w=(pointer)MINUS(ctx,2,local+11); /*-*/
	local[11]= w;
	local[12]= fqv[159];
	local[13]= makeint(120);
	local[14]= fqv[15];
	local[15]= loadglobal(fqv[16]);
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,12,local+4); /*send*/
	w = local[3];
	argv[0]->c.obj.iv[29] = w;
	local[3]= loadglobal(fqv[160]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[19];
	local[6]= fqv[21];
	local[7]= local[1];
	local[8]= fqv[22];
	local[9]= makeint(60);
	local[10]= fqv[159];
	local[11]= makeint(60);
	local[12]= fqv[15];
	local[13]= loadglobal(fqv[16]);
	local[14]= fqv[20];
	local[15]= argv[0];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,12,local+4); /*send*/
	w = local[3];
	argv[0]->c.obj.iv[30] = w;
	local[3]= argv[0]->c.obj.iv[30];
	ctx->vsp=local+4;
	w=(*ftab[18])(ctx,1,local+3,&ftab[18],fqv[161]); /*make-textwindow-stream*/
	argv[0]->c.obj.iv[31] = w;
	w = argv[0];
	local[0]= w;
BLK3604:
	ctx->vsp=local; return(local[0]);}

/*:update-method-names*/
static pointer M3610objectbrowser_update_method_names(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3613;}
	local[0]= argv[0]->c.obj.iv[33];
ENT3613:
ENT3612:
	if (n>3) maerror();
	local[1]= (pointer)get_sym_func(fqv[35]);
	local[2]= (pointer)get_sym_func(fqv[162]);
	local[3]= local[0];
	local[4]= fqv[163];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	argv[0]->c.obj.iv[36] = w;
	local[1]= argv[0]->c.obj.iv[36];
	storeglobal(fqv[164],local[1]);
	local[1]= *(ovafptr(argv[0]->c.obj.iv[29],fqv[165]));
	local[2]= fqv[30];
	local[3]= argv[0]->c.obj.iv[36];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK3611:
	ctx->vsp=local; return(local[0]);}

/*:set-object*/
static pointer M3614objectbrowser_set_object(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[25];
	local[1]= fqv[32];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[11])(ctx,1,local+0,&ftab[11],fqv[77]); /*read-from-string*/
	argv[0]->c.obj.iv[32] = w;
	local[0]= argv[0]->c.obj.iv[32];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w==NIL) goto CON3617;
	local[0]= argv[0]->c.obj.iv[32];
	ctx->vsp=local+1;
	w=(pointer)SYMVALUE(ctx,1,local+0); /*symbol-value*/
	argv[0]->c.obj.iv[32] = w;
	local[0]= argv[0];
	local[1]= fqv[154];
	local[2]= argv[0]->c.obj.iv[32];
	ctx->vsp=local+3;
	w=(pointer)GETCLASS(ctx,1,local+2); /*class*/
	argv[0]->c.obj.iv[33] = w;
	local[2]= argv[0]->c.obj.iv[33];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[31];
	local[1]= fqv[166];
	local[2]= argv[0]->c.obj.iv[32];
	local[3]= argv[0]->c.obj.iv[33];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
	goto CON3616;
CON3617:
	local[0]= argv[0]->c.obj.iv[31];
	local[1]= fqv[167];
	local[2]= argv[0]->c.obj.iv[32];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto CON3616;
CON3618:
	local[0]= NIL;
CON3616:
	w = local[0];
	local[0]= w;
BLK3615:
	ctx->vsp=local; return(local[0]);}

/*:set-class*/
static pointer M3619objectbrowser_set_class(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)CLASSP(ctx,1,local+0); /*classp*/
	if (w!=NIL) goto CON3622;
	local[0]= argv[0]->c.obj.iv[26];
	local[1]= fqv[32];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[11])(ctx,1,local+0,&ftab[11],fqv[77]); /*read-from-string*/
	argv[0]->c.obj.iv[33] = w;
	local[0]= argv[0]->c.obj.iv[33];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w==NIL) goto IF3623;
	local[0]= argv[0]->c.obj.iv[33];
	ctx->vsp=local+1;
	w=(pointer)SYMVALUE(ctx,1,local+0); /*symbol-value*/
	argv[0]->c.obj.iv[33] = w;
	local[0]= argv[0]->c.obj.iv[33];
	goto IF3624;
IF3623:
	local[0]= argv[0]->c.obj.iv[31];
	local[1]= fqv[168];
	local[2]= argv[0]->c.obj.iv[33];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
IF3624:
	goto CON3621;
CON3622:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)CLASSP(ctx,1,local+0); /*classp*/
	if (w==NIL) goto CON3625;
	argv[0]->c.obj.iv[33] = argv[2];
	local[0]= argv[0]->c.obj.iv[26];
	local[1]= fqv[32];
	local[2]= NIL;
	local[3]= fqv[169];
	local[4]= argv[0]->c.obj.iv[33];
	local[5]= fqv[98];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON3621;
CON3625:
	local[0]= NIL;
CON3621:
	local[0]= argv[0]->c.obj.iv[26];
	local[1]= fqv[32];
	local[2]= argv[0]->c.obj.iv[33];
	local[3]= fqv[98];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[19])(ctx,1,local+2,&ftab[19],fqv[35]); /*string*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[33];
	local[1]= argv[0]->c.obj.iv[33];
	local[2]= fqv[170];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	ctx->vsp=local+1;
	argv[0]->c.obj.iv[34] = cons(ctx,local[0],w);
	local[0]= argv[0];
	local[1]= fqv[171];
	local[2]= argv[0]->c.obj.iv[33];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3620:
	ctx->vsp=local; return(local[0]);}

/*:set-superclass*/
static pointer M3626objectbrowser_set_superclass(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[33];
	local[1]= argv[0]->c.obj.iv[34];
	ctx->vsp=local+2;
	w=(*ftab[20])(ctx,2,local+0,&ftab[20],fqv[172]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (local[0]==NIL) goto IF3628;
	argv[0]->c.obj.iv[33] = local[0];
	local[1]= argv[0]->c.obj.iv[26];
	local[2]= fqv[32];
	local[3]= argv[0]->c.obj.iv[33];
	local[4]= fqv[98];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[19])(ctx,1,local+3,&ftab[19],fqv[35]); /*string*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[171];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF3629;
IF3628:
	local[1]= NIL;
IF3629:
	w = local[1];
	local[0]= w;
BLK3627:
	ctx->vsp=local; return(local[0]);}

/*:set-subclass*/
static pointer M3630objectbrowser_set_subclass(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[34];
WHL3632:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX3633;
	local[1]= argv[0]->c.obj.iv[33];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)EQ(ctx,2,local+1); /*eql*/
	if (w!=NIL) goto WHX3633;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	goto WHL3632;
WHX3633:
	local[1]= NIL;
BLK3634:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF3635;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[33] = (w)->c.cons.car;
	local[1]= argv[0]->c.obj.iv[26];
	local[2]= fqv[32];
	local[3]= argv[0]->c.obj.iv[33];
	local[4]= fqv[98];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[19])(ctx,1,local+3,&ftab[19],fqv[35]); /*string*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[171];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF3636;
IF3635:
	local[1]= NIL;
IF3636:
	w = local[1];
	w = argv[0]->c.obj.iv[33];
	local[0]= w;
BLK3631:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___Xapplwin(ctx,n,argv,env)
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
	local[0]= fqv[173];
	local[1]= fqv[174];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[175]); /*require*/
	local[0]= fqv[176];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[177];
	local[1]= fqv[178];
	local[2]= fqv[177];
	local[3]= fqv[179];
	local[4]= loadglobal(fqv[180]);
	local[5]= fqv[181];
	local[6]= fqv[182];
	local[7]= fqv[183];
	local[8]= NIL;
	local[9]= fqv[184];
	local[10]= NIL;
	local[11]= fqv[185];
	local[12]= makeint(-1);
	local[13]= fqv[186];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[22])(ctx,13,local+2,&ftab[22],fqv[187]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3430filedialog_create_buttons,fqv[42],fqv[177],fqv[188]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3432filedialog_create_fileview,fqv[43],fqv[177],fqv[189]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3435filedialog_create,fqv[19],fqv[177],fqv[190]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3442filedialog_cwd,fqv[46],fqv[177],fqv[191]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3444filedialog_file_selected,fqv[28],fqv[177],fqv[192]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3448filedialog_selected_fname,fqv[49],fqv[177],fqv[193]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3452filedialog_view,fqv[11],fqv[177],fqv[194]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3457filedialog_ok,fqv[3],fqv[177],fqv[195]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3461filedialog_cancel,fqv[5],fqv[177],fqv[196]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3465filedialog_open,fqv[7],fqv[177],fqv[197]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3469filedialog_go_up,fqv[9],fqv[177],fqv[198]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3471filedialog_resize,fqv[63],fqv[177],fqv[199]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3473filedialog_configurenotify,fqv[200],fqv[177],fqv[201]);
	local[0]= fqv[202];
	local[1]= fqv[178];
	local[2]= fqv[202];
	local[3]= fqv[179];
	local[4]= loadglobal(fqv[177]);
	local[5]= fqv[181];
	local[6]= fqv[203];
	local[7]= fqv[183];
	local[8]= NIL;
	local[9]= fqv[184];
	local[10]= NIL;
	local[11]= fqv[185];
	local[12]= makeint(-1);
	local[13]= fqv[186];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[22])(ctx,13,local+2,&ftab[22],fqv[187]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3478filepanel_create_buttons,fqv[42],fqv[202],fqv[204]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3480filepanel_create,fqv[19],fqv[202],fqv[205]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3484filepanel_load,fqv[66],fqv[202],fqv[206]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3486filepanel_eval,fqv[74],fqv[202],fqv[207]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3488filepanel_print,fqv[70],fqv[202],fqv[208]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3492filepanel_compile,fqv[72],fqv[202],fqv[209]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3496filepanel_remove,fqv[68],fqv[202],fqv[210]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3498filepanel_remove_confirm,fqv[81],fqv[202],fqv[211]);
	local[0]= fqv[51];
	local[1]= fqv[178];
	local[2]= fqv[51];
	local[3]= fqv[179];
	local[4]= loadglobal(fqv[180]);
	local[5]= fqv[181];
	local[6]= fqv[212];
	local[7]= fqv[183];
	local[8]= NIL;
	local[9]= fqv[184];
	local[10]= NIL;
	local[11]= fqv[185];
	local[12]= makeint(-1);
	local[13]= fqv[186];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[22])(ctx,13,local+2,&ftab[22],fqv[187]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3502textviewpanel_create,fqv[19],fqv[51],fqv[213]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3515textviewpanel_quit,fqv[88],fqv[51],fqv[214]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3517textviewpanel_finish,fqv[215],fqv[51],fqv[216]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3519textviewpanel_print,fqv[70],fqv[51],fqv[217]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3528textviewpanel_find,fqv[91],fqv[51],fqv[218]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3541textviewpanel_resize,fqv[63],fqv[51],fqv[219]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3543textviewpanel_configurenotify,fqv[200],fqv[51],fqv[220]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[221],module,F3429ls_l,fqv[222]);
	local[0]= fqv[75];
	local[1]= fqv[178];
	local[2]= fqv[75];
	local[3]= fqv[179];
	local[4]= loadglobal(fqv[180]);
	local[5]= fqv[181];
	local[6]= fqv[223];
	local[7]= fqv[183];
	local[8]= NIL;
	local[9]= fqv[184];
	local[10]= NIL;
	local[11]= fqv[185];
	local[12]= makeint(-1);
	local[13]= fqv[186];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[22])(ctx,13,local+2,&ftab[22],fqv[187]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3558confirmpanel_create,fqv[19],fqv[75],fqv[224]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3561confirmpanel_draw_message,fqv[124],fqv[75],fqv[225]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3568confirmpanel_ask,fqv[80],fqv[75],fqv[226]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3571confirmpanel_yes,fqv[84],fqv[75],fqv[227]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3573confirmpanel_no,fqv[121],fqv[75],fqv[228]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3575confirmpanel_configurenotify,fqv[200],fqv[75],fqv[229]);
	local[0]= fqv[230];
	local[1]= fqv[178];
	local[2]= fqv[230];
	local[3]= fqv[179];
	local[4]= loadglobal(fqv[180]);
	local[5]= fqv[181];
	local[6]= fqv[231];
	local[7]= fqv[183];
	local[8]= NIL;
	local[9]= fqv[184];
	local[10]= NIL;
	local[11]= fqv[185];
	local[12]= makeint(-1);
	local[13]= fqv[186];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[22])(ctx,13,local+2,&ftab[22],fqv[187]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3580colorpickerpanel_create,fqv[19],fqv[230],fqv[232]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3583colorpickerpanel_init_value,fqv[233],fqv[230],fqv[234]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3585colorpickerpanel_value1,fqv[145],fqv[230],fqv[235]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3587colorpickerpanel_value2,fqv[147],fqv[230],fqv[236]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3589colorpickerpanel_value3,fqv[149],fqv[230],fqv[237]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3591colorpickerpanel_ambient,fqv[132],fqv[230],fqv[238]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3593colorpickerpanel_diffuse,fqv[134],fqv[230],fqv[239]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3595colorpickerpanel_specular,fqv[136],fqv[230],fqv[240]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3597colorpickerpanel_emission,fqv[138],fqv[230],fqv[241]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3599colorpickerpanel_shininess,fqv[140],fqv[230],fqv[242]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3601colorpickerpanel_transparency,fqv[142],fqv[230],fqv[243]);
	local[0]= fqv[244];
	local[1]= fqv[178];
	local[2]= fqv[244];
	local[3]= fqv[179];
	local[4]= loadglobal(fqv[180]);
	local[5]= fqv[181];
	local[6]= fqv[245];
	local[7]= fqv[183];
	local[8]= NIL;
	local[9]= fqv[184];
	local[10]= NIL;
	local[11]= fqv[185];
	local[12]= makeint(-1);
	local[13]= fqv[186];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[22])(ctx,13,local+2,&ftab[22],fqv[187]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3603objectbrowser_create,fqv[19],fqv[244],fqv[246]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3610objectbrowser_update_method_names,fqv[171],fqv[244],fqv[247]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3614objectbrowser_set_object,fqv[152],fqv[244],fqv[248]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3619objectbrowser_set_class,fqv[154],fqv[244],fqv[249]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3626objectbrowser_set_superclass,fqv[158],fqv[244],fqv[250]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3630objectbrowser_set_subclass,fqv[156],fqv[244],fqv[251]);
	local[0]= fqv[252];
	local[1]= fqv[253];
	ctx->vsp=local+2;
	w=(*ftab[23])(ctx,2,local+0,&ftab[23],fqv[254]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<24; i++) ftab[i]=fcallx;
}
