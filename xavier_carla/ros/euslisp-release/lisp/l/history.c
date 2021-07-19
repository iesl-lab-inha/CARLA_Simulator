/* ./history.c :  entry=history */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "history.h"
#pragma init (register_history)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___history();
extern pointer build_quote_vector();
static int register_history()
  { add_module_initializer("___history", ___history);}

static pointer F74256refresh_line();
static pointer F74258line_head();
static pointer F74260line_left();
static pointer F74262line_right();
static pointer F74264line_delch();
static pointer F74266line_delch_previous();
static pointer F74268line_tail();
static pointer F74270line_refresh();
static pointer F74272line_insert();
static pointer F74274line_clear();
static pointer F74276line_null();
static pointer F74278line_abort();
static pointer F74280line_end();
static pointer F74284line_edit();
static pointer F74286new_history();
static pointer F74288add_history();
static pointer F74290print_history();
static pointer F74292h();
static pointer F74294get_history();
static pointer F74296_();

/*refresh-line*/
static pointer F74256refresh_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*cursor-pos*/
	ctx->vsp=local+0;
	w=(*ftab[1])(ctx,0,local+0,&ftab[1],fqv[1]); /*erase-eol*/
	local[0]= makeint(0);
	local[1]= argv[2];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
WHL74387:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX74388;
	local[2]= argv[0];
	local[3]= local[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	local[3]= loadglobal(fqv[2]);
	ctx->vsp=local+4;
	w=(pointer)WRTBYTE(ctx,2,local+2); /*write-byte*/
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL74387;
WHX74388:
	local[2]= NIL;
BLK74389:
	w = NIL;
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*cursor-pos*/
	local[0]= w;
BLK74336:
	ctx->vsp=local; return(local[0]);}

/*line-head*/
static pointer F74258line_head(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= makeint(0);
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*cursor-pos*/
	local[0]= argv[1];
	local[1]= makeint(0);
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK74427:
	ctx->vsp=local; return(local[0]);}

/*line-left*/
static pointer F74260line_left(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF74467;
	ctx->vsp=local+0;
	w=(*ftab[2])(ctx,0,local+0,&ftab[2],fqv[3]); /*cursor-backward*/
	local[0]= w;
	goto IF74468;
IF74467:
	local[0]= NIL;
IF74468:
	local[0]= argv[1];
	local[1]= makeint(0);
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SUB1(ctx,1,local+2); /*1-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAX(ctx,2,local+1); /*max*/
	local[1]= w;
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK74451:
	ctx->vsp=local; return(local[0]);}

/*line-right*/
static pointer F74262line_right(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF74504;
	ctx->vsp=local+0;
	w=(*ftab[3])(ctx,0,local+0,&ftab[3],fqv[4]); /*cursor-forward*/
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	argv[2] = w;
	local[0]= argv[2];
	goto IF74505;
IF74504:
	local[0]= NIL;
IF74505:
	local[0]= argv[1];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK74487:
	ctx->vsp=local; return(local[0]);}

/*line-delch*/
static pointer F74264line_delch(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF74551;
	local[0]= argv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[5]); /*list-delete*/
	argv[1] = w;
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)SUB1(ctx,1,local+0); /*1-*/
	argv[3] = w;
	local[0]= argv[1];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)F74256refresh_line(ctx,3,local+0); /*refresh-line*/
	local[0]= w;
	goto IF74552;
IF74551:
	local[0]= NIL;
IF74552:
	local[0]= argv[1];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK74534:
	ctx->vsp=local; return(local[0]);}

/*line-delch-previous*/
static pointer F74266line_delch_previous(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF74611;
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)SUB1(ctx,1,local+0); /*1-*/
	argv[2] = w;
	local[0]= argv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[5]); /*list-delete*/
	argv[1] = w;
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)SUB1(ctx,1,local+0); /*1-*/
	argv[3] = w;
	local[0]= argv[1];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)F74256refresh_line(ctx,3,local+0); /*refresh-line*/
	local[0]= w;
	goto IF74612;
IF74611:
	local[0]= NIL;
IF74612:
	local[0]= argv[1];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK74594:
	ctx->vsp=local; return(local[0]);}

/*line-tail*/
static pointer F74268line_tail(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*cursor-pos*/
	local[0]= argv[1];
	local[1]= argv[3];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK74662:
	ctx->vsp=local; return(local[0]);}

/*line-refresh*/
static pointer F74270line_refresh(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[1];
	local[1]= makeint(0);
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)F74256refresh_line(ctx,3,local+0); /*refresh-line*/
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*cursor-pos*/
	local[0]= argv[1];
	local[1]= argv[3];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK74688:
	ctx->vsp=local; return(local[0]);}

/*line-insert*/
static pointer F74272line_insert(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= argv[2];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(*ftab[5])(ctx,3,local+0,&ftab[5],fqv[6]); /*list-insert*/
	argv[1] = w;
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	argv[3] = w;
	local[0]= argv[1];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)F74256refresh_line(ctx,3,local+0); /*refresh-line*/
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	argv[2] = w;
	ctx->vsp=local+0;
	w=(*ftab[3])(ctx,0,local+0,&ftab[3],fqv[4]); /*cursor-forward*/
	local[0]= argv[1];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK74719:
	ctx->vsp=local; return(local[0]);}

/*line-clear*/
static pointer F74274line_clear(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= makeint(0);
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*cursor-pos*/
	ctx->vsp=local+0;
	w=(*ftab[1])(ctx,0,local+0,&ftab[1],fqv[1]); /*erase-eol*/
	local[0]= fqv[7];
	local[1]= makeint(0);
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK74782:
	ctx->vsp=local; return(local[0]);}

/*line-null*/
static pointer F74276line_null(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[1];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK74809:
	ctx->vsp=local; return(local[0]);}

/*line-abort*/
static pointer F74278line_abort(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= fqv[8];
	w = NIL;
	ctx->vsp=local+1;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	w = local[0];
	local[0]= w;
BLK74831:
	ctx->vsp=local; return(local[0]);}

/*line-end*/
static pointer F74280line_end(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= fqv[8];
	w = argv[1];
	ctx->vsp=local+1;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	w = local[0];
	local[0]= w;
BLK74853:
	ctx->vsp=local; return(local[0]);}

/*line-edit*/
static pointer F74284line_edit(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[9]);
	ctx->vsp=local+2;
	w=(pointer)COERCE(ctx,2,local+0); /*coerce*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	local[4]= local[3];
	local[5]= NIL;
	local[6]= T;
	local[7]= fqv[10];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	ctx->vsp=local+6;
	w=(*ftab[6])(ctx,0,local+6,&ftab[6],fqv[11]); /*tty-raw*/
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,1,local+6,&ftab[0],fqv[0]); /*cursor-pos*/
	ctx->vsp=local+6;
	w=(pointer)FINOUT(ctx,0,local+6); /*finish-output*/
	ctx->vsp=local+6;
	w=(pointer)READCH(ctx,0,local+6); /*read-char*/
	local[2] = w;
	{jmp_buf jb;
	w = fqv[8];
	ctx->vsp=local+6;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT74957;}
WHL74964:
	if (T==NIL) goto WHX74965;
	local[12]= loadglobal(fqv[12]);
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)AREF(ctx,2,local+12); /*aref*/
	local[12]= w;
	local[13]= local[2];
	local[14]= local[0];
	local[15]= local[4];
	local[16]= local[3];
	ctx->vsp=local+17;
	w=(pointer)FUNCALL(ctx,5,local+12); /*funcall*/
	local[1] = w;
	local[12]= loadglobal(fqv[2]);
	ctx->vsp=local+13;
	w=(pointer)FINOUT(ctx,1,local+12); /*finish-output*/
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	ctx->vsp=local+12;
	w=(pointer)READCH(ctx,0,local+12); /*read-char*/
	local[2] = w;
	goto WHL74964;
WHX74965:
	local[12]= NIL;
BLK74966:
	w = local[12];
CAT74957:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[1] = w;
	ctx->vsp=local+6;
	w=(*ftab[7])(ctx,0,local+6,&ftab[7],fqv[13]); /*tty-cooked*/
	if (local[1]==NIL) goto IF75039;
	local[6]= local[0];
	local[7]= loadglobal(fqv[14]);
	ctx->vsp=local+8;
	w=(pointer)COERCE(ctx,2,local+6); /*coerce*/
	local[6]= w;
	goto IF75040;
IF75039:
	local[6]= NIL;
IF75040:
	w = local[6];
	local[0]= w;
BLK74895:
	ctx->vsp=local; return(local[0]);}

/*new-history*/
static pointer F74286new_history(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[8])(ctx,1,local+0,&ftab[8],fqv[15]); /*make-array*/
	local[0]= w;
	storeglobal(fqv[16],w);
	local[0]= argv[0];
	storeglobal(fqv[17],local[0]);
	local[0]= makeint(0);
	storeglobal(fqv[18],local[0]);
	local[0]= loadglobal(fqv[16]);
	local[1]= makeint(0);
	local[2]= loadglobal(fqv[19]);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= w;
BLK75056:
	ctx->vsp=local; return(local[0]);}

/*add-history*/
static pointer F74288add_history(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[19]);
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	local[0]= w;
	storeglobal(fqv[19],w);
	local[0]= loadglobal(fqv[18]);
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	local[0]= w;
	storeglobal(fqv[18],w);
	local[0]= loadglobal(fqv[18]);
	local[1]= loadglobal(fqv[17]);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto IF75127;
	local[0]= loadglobal(fqv[17]);
	ctx->vsp=local+1;
	w=(pointer)SUB1(ctx,1,local+0); /*1-*/
	local[0]= w;
	storeglobal(fqv[18],w);
	local[0]= loadglobal(fqv[16]);
	local[1]= loadglobal(fqv[16]);
	local[2]= fqv[20];
	local[3]= makeint(0);
	local[4]= fqv[21];
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(*ftab[9])(ctx,6,local+0,&ftab[9],fqv[22]); /*replace*/
	local[0]= w;
	goto IF75128;
IF75127:
	local[0]= NIL;
IF75128:
	local[0]= loadglobal(fqv[16]);
	local[1]= loadglobal(fqv[18]);
	local[2]= loadglobal(fqv[19]);
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= fqv[23];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w==NIL) goto IF75166;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[24];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,2,local+0,&ftab[10],fqv[25]); /*find-method*/
	if (w==NIL) goto IF75166;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[24];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF75167;
IF75166:
	local[0]= NIL;
IF75167:
	w = loadglobal(fqv[16]);
	local[0]= w;
BLK75098:
	ctx->vsp=local; return(local[0]);}

/*print-history*/
static pointer F74290print_history(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT75197;}
	local[0]= loadglobal(fqv[2]);
ENT75197:
ENT75196:
	if (n>1) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= makeint(0);
	local[4]= loadglobal(fqv[18]);
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[4]= w;
WHL75239:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX75240;
	local[5]= loadglobal(fqv[16]);
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[2] = w;
	w = local[2];
	if (!iscons(w)) goto IF75258;
	local[5]= local[0];
	local[6]= fqv[26];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,4,local+5); /*format*/
	local[5]= w;
	goto IF75259;
IF75258:
	local[5]= NIL;
IF75259:
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL75239;
WHX75240:
	local[5]= NIL;
BLK75241:
	w = NIL;
	local[0]= w;
BLK75194:
	ctx->vsp=local; return(local[0]);}

/*h*/
static pointer F74292h(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	ctx->vsp=local+0;
	w=(pointer)F74290print_history(ctx,0,local+0); /*print-history*/
	local[0]= w;
BLK75293:
	ctx->vsp=local; return(local[0]);}

/*get-history*/
static pointer F74294get_history(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!isnum(w)) goto IF75314;
	local[0]= argv[0];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)LSEQP(ctx,2,local+0); /*<=*/
	if (w==NIL) goto IF75320;
	local[0]= loadglobal(fqv[16]);
	local[1]= loadglobal(fqv[18]);
	local[2]= argv[0];
	local[3]= makeint(-1);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,3,local+1); /*+*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	goto IF75321;
IF75320:
	local[0]= loadglobal(fqv[16]);
	local[1]= loadglobal(fqv[18]);
	local[2]= makeint(0);
	local[3]= argv[0];
	local[4]= loadglobal(fqv[16]);
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= makeint(-1);
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,3,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MAX(ctx,2,local+2); /*max*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MIN(ctx,2,local+1); /*min*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
IF75321:
	goto IF75315;
IF75314:
	local[0]= loadglobal(fqv[18]);
	ctx->vsp=local+1;
	w=(pointer)SUB1(ctx,1,local+0); /*1-*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[11])(ctx,1,local+1,&ftab[11],fqv[14]); /*string*/
	local[1]= w;
	local[2]= NIL;
TAG75397:
	local[3]= local[0];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)LSEQP(ctx,2,local+3); /*<=*/
	if (w==NIL) goto IF75402;
	w = NIL;
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK75369;
	goto IF75403;
IF75402:
	local[3]= NIL;
IF75403:
	local[3]= local[1];
	local[4]= loadglobal(fqv[16]);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(*ftab[11])(ctx,1,local+4,&ftab[11],fqv[14]); /*string*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[12])(ctx,2,local+3,&ftab[12],fqv[27]); /*substringp*/
	if (w==NIL) goto IF75416;
	w = local[2];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK75304;
	goto IF75417;
IF75416:
	local[3]= NIL;
IF75417:
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SUB1(ctx,1,local+3); /*1-*/
	local[3]= w;
	local[0] = local[3];
	w = NIL;
	ctx->vsp=local+3;
	goto TAG75397;
	w = NIL;
	local[0]= w;
BLK75369:
IF75315:
	w = local[0];
	local[0]= w;
BLK75304:
	ctx->vsp=local; return(local[0]);}

/*!*/
static pointer F74296_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT75480;}
	local[0]= makeint(0);
ENT75480:
ENT75479:
	if (n>1) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F74294get_history(ctx,1,local+1); /*get-history*/
	local[1]= w;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)F74284line_edit(ctx,1,local+2); /*line-edit*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)TERPRI(ctx,0,local+3); /*terpri*/
	if (local[2]==NIL) goto CON75513;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)F74288add_history(ctx,1,local+3); /*add-history*/
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(*ftab[13])(ctx,1,local+3,&ftab[13],fqv[28]); /*make-string-input-stream*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[14])(ctx,1,local+3,&ftab[14],fqv[29]); /*evaluate-stream*/
	local[3]= w;
	goto CON75511;
CON75513:
	local[3]= NIL;
	goto CON75511;
CON75529:
	local[3]= NIL;
CON75511:
	w = local[3];
	local[0]= w;
BLK75477:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___history(ctx,n,argv,env)
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
	local[0]= fqv[30];
	local[1]= fqv[31];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[32]); /*require*/
	local[0]= fqv[33];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[12];
	local[1]= fqv[34];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF75553;
	local[0]= fqv[12];
	local[1]= fqv[34];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[12];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF75576;
	local[0]= fqv[12];
	local[1]= fqv[35];
	local[2]= makeint(128);
	ctx->vsp=local+3;
	w=(*ftab[8])(ctx,1,local+2,&ftab[8],fqv[15]); /*make-array*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF75577;
IF75576:
	local[0]= NIL;
IF75577:
	local[0]= fqv[12];
	goto IF75554;
IF75553:
	local[0]= NIL;
IF75554:
	ctx->vsp=local+0;
	compfun(ctx,fqv[36],module,F74256refresh_line,fqv[37]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[38],module,F74258line_head,fqv[39]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[40],module,F74260line_left,fqv[41]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[42],module,F74262line_right,fqv[43]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[44],module,F74264line_delch,fqv[45]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[46],module,F74266line_delch_previous,fqv[47]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[48],module,F74268line_tail,fqv[49]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[50],module,F74270line_refresh,fqv[51]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[52],module,F74272line_insert,fqv[53]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[54],module,F74274line_clear,fqv[55]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[56],module,F74276line_null,fqv[57]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[58],module,F74278line_abort,fqv[59]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[60],module,F74280line_end,fqv[61]);
	local[0]= makeint(0);
	local[1]= makeint(128);
WHL75644:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX75645;
	local[2]= loadglobal(fqv[12]);
	local[3]= local[0];
	local[4]= fqv[52];
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL75644;
WHX75645:
	local[2]= NIL;
BLK75646:
	w = NIL;
	local[0]= makeint(0);
	local[1]= makeint(32);
WHL75694:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX75695;
	local[2]= loadglobal(fqv[12]);
	local[3]= local[0];
	local[4]= fqv[56];
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL75694;
WHX75695:
	local[2]= NIL;
BLK75696:
	w = NIL;
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint(1);
	local[2]= fqv[38];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint(2);
	local[2]= fqv[40];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint(3);
	local[2]= fqv[58];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint(4);
	local[2]= fqv[44];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint(6);
	local[2]= fqv[42];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint(7);
	local[2]= fqv[50];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint(8);
	local[2]= fqv[40];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint(10);
	local[2]= fqv[60];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint(11);
	local[2]= fqv[42];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint(12);
	local[2]= fqv[48];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint(13);
	local[2]= fqv[60];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint(18);
	local[2]= fqv[50];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint(21);
	local[2]= fqv[54];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint(127);
	local[2]= fqv[46];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[8],module,F74284line_edit,fqv[62]);
	local[0]= fqv[17];
	local[1]= fqv[34];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF75824;
	local[0]= fqv[17];
	local[1]= fqv[34];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[17];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF75847;
	local[0]= fqv[17];
	local[1]= fqv[35];
	local[2]= makeint(50);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF75848;
IF75847:
	local[0]= NIL;
IF75848:
	local[0]= fqv[17];
	goto IF75825;
IF75824:
	local[0]= NIL;
IF75825:
	local[0]= fqv[16];
	local[1]= fqv[34];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF75867;
	local[0]= fqv[16];
	local[1]= fqv[34];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[16];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF75890;
	local[0]= fqv[16];
	local[1]= fqv[35];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF75891;
IF75890:
	local[0]= NIL;
IF75891:
	local[0]= fqv[16];
	goto IF75868;
IF75867:
	local[0]= NIL;
IF75868:
	local[0]= fqv[18];
	local[1]= fqv[34];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF75910;
	local[0]= fqv[18];
	local[1]= fqv[34];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[18];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF75933;
	local[0]= fqv[18];
	local[1]= fqv[35];
	local[2]= makeint(0);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF75934;
IF75933:
	local[0]= NIL;
IF75934:
	local[0]= fqv[18];
	goto IF75911;
IF75910:
	local[0]= NIL;
IF75911:
	local[0]= fqv[19];
	local[1]= fqv[34];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF75953;
	local[0]= fqv[19];
	local[1]= fqv[34];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[19];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF75976;
	local[0]= fqv[19];
	local[1]= fqv[35];
	local[2]= makeint(0);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF75977;
IF75976:
	local[0]= NIL;
IF75977:
	local[0]= fqv[19];
	goto IF75954;
IF75953:
	local[0]= NIL;
IF75954:
	ctx->vsp=local+0;
	compfun(ctx,fqv[63],module,F74286new_history,fqv[64]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[65],module,F74288add_history,fqv[66]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[67],module,F74290print_history,fqv[68]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[69],module,F74292h,fqv[70]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[71],module,F74294get_history,fqv[72]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[73],module,F74296_,fqv[74]);
	local[0]= fqv[75];
	local[1]= fqv[76];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[77]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<17; i++) ftab[i]=fcallx;
}
