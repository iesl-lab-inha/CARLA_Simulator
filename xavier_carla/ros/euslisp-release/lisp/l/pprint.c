/* ./pprint.c :  entry=pprint */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "pprint.h"
#pragma init (register_pprint)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___pprint();
extern pointer build_quote_vector();
static int register_pprint()
  { add_module_initializer("___pprint", ___pprint);}

static pointer F20115spaces();
static pointer F20119px();
static pointer F20123pp_method();
static pointer F20126pprint();
static pointer F20129pprint_file();
static pointer F20132pprint1();
static pointer F20135pparg();
static pointer F20137pprint_array();
static pointer F20141tprint();

/*spaces*/
static pointer F20115spaces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT20172;}
	local[0]= T;
ENT20172:
ENT20171:
	if (n>2) maerror();
	local[1]= makeint(0);
	local[2]= argv[0];
WHL20209:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX20210;
	local[3]= fqv[0];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)PRINC(ctx,2,local+3); /*princ*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL20209;
WHX20210:
	local[3]= NIL;
BLK20211:
	w = NIL;
	local[0]= w;
BLK20169:
	ctx->vsp=local; return(local[0]);}

/*px*/
static pointer F20119px(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT20239;}
	local[0]= T;
ENT20239:
ENT20238:
	if (n>2) maerror();
	local[1]= local[0];
	local[2]= fqv[1];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[0]= w;
BLK20236:
	ctx->vsp=local; return(local[0]);}

/*pf*/
static pointer F20259(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT20263;}
	local[0]= loadglobal(fqv[2]);
ENT20263:
ENT20262:
	if (n>2) maerror();
	local[1]= fqv[3];
	local[2]= fqv[4];
	local[3]= fqv[5];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[6];
	local[4]= fqv[7];
	local[5]= fqv[5];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[5];
	local[5]= fqv[8];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK20260:
	ctx->vsp=local; return(local[0]);}

/*pp-method*/
static pointer F20123pp_method(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT20341;}
	local[0]= loadglobal(fqv[2]);
ENT20341:
ENT20340:
	if (n>3) maerror();
	local[1]= argv[1];
	local[2]= *(ovafptr(argv[0],fqv[9]));
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[10]); /*assoc*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F20126pprint(ctx,2,local+1); /*pprint*/
	local[0]= w;
BLK20338:
	ctx->vsp=local; return(local[0]);}

/*pprint*/
static pointer F20126pprint(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT20374;}
	local[0]= loadglobal(fqv[2]);
ENT20374:
	if (n>=3) { local[1]=(argv[2]); goto ENT20373;}
	local[1]= makeint(0);
ENT20373:
	if (n>=4) { local[2]=(argv[3]); goto ENT20372;}
	local[2]= makeint(75);
ENT20372:
ENT20371:
	if (n>4) maerror();
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= local[1];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F20132pprint1(ctx,4,local+3); /*pprint1*/
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)TERPRI(ctx,1,local+3); /*terpri*/
	local[0]= w;
BLK20369:
	ctx->vsp=local; return(local[0]);}

/*pprint-file*/
static pointer F20129pprint_file(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= fqv[11];
	local[2]= fqv[12];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,3,local+0,&ftab[1],fqv[13]); /*open*/
	local[0]= w;
	ctx->vsp=local+1;
	w = makeclosure(codevec,quotevec,UWP20440,env,argv,local);
	local[1]=(pointer)(ctx->protfp); local[2]=w;
	ctx->protfp=(struct protectframe *)(local+1);
	local[3]= argv[0];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)F20126pprint(ctx,2,local+3); /*pprint*/
	ctx->vsp=local+3;
	UWP20440(ctx,0,local+3,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK20409:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP20440(ctx,n,argv,env)
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

/*pprint1*/
static pointer F20132pprint1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	w = argv[0];
	if (issymbol(w)) goto OR20485;
	w = argv[0];
	if (isnum(w)) goto OR20485;
	w = argv[0];
	if (isstring(w)) goto OR20485;
	local[0]= argv[0];
	local[1]= argv[3];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)PRNTSIZE(ctx,2,local+0); /*print-size*/
	local[0]= w;
	local[1]= argv[3];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w!=NIL) goto OR20485;
	goto CON20484;
OR20485:
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)PRIN1(ctx,2,local+0); /*prin1*/
	local[0]= w;
	goto CON20482;
CON20484:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON20518;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[5]!=local[0]) goto CON20518;
	local[0]= fqv[14];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)PRINC(ctx,2,local+0); /*princ*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)F20132pprint1(ctx,4,local+0); /*pprint1*/
	local[0]= w;
	goto CON20482;
CON20518:
	local[0]= argv[0];
	local[1]= loadglobal(fqv[15]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON20558;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[2])(ctx,1,local+0,&ftab[2],fqv[16]); /*array-rank*/
	local[0]= w;
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	if (w==NIL) goto CON20558;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[3])(ctx,1,local+0,&ftab[3],fqv[17]); /*array-total-size*/
	local[0]= w;
	local[1]= makeint(100);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto CON20558;
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)F20137pprint_array(ctx,3,local+0); /*pprint-array*/
	local[0]= w;
	goto CON20482;
CON20558:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)VECTORP(ctx,1,local+0); /*vectorp*/
	if (w==NIL) goto CON20585;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[4])(ctx,1,local+0,&ftab[4],fqv[18]); /*float-vector-p*/
	if (w==NIL) goto CON20595;
	local[0]= fqv[19];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)PRINC(ctx,2,local+0); /*princ*/
	local[0]= argv[2];
	local[1]= makeint(3);
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[2] = w;
	local[0]= argv[2];
	goto CON20593;
CON20595:
	local[0]= fqv[20];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)PRINC(ctx,2,local+0); /*princ*/
	local[0]= argv[2];
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[2] = w;
	local[0]= argv[2];
	goto CON20593;
CON20618:
	local[0]= NIL;
CON20593:
	local[0]= makeint(0);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
WHL20661:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX20662;
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	local[3]= argv[1];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)F20132pprint1(ctx,4,local+2); /*pprint1*/
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)TERPRI(ctx,1,local+2); /*terpri*/
	local[2]= argv[2];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)F20115spaces(ctx,2,local+2); /*spaces*/
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL20661;
WHX20662:
	local[2]= NIL;
BLK20663:
	local[2]= fqv[21];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)PRINC(ctx,2,local+2); /*princ*/
	local[0]= w;
	goto CON20482;
CON20585:
	w = argv[0];
	if (!!iscons(w)) goto CON20702;
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)PRIN1(ctx,2,local+0); /*prin1*/
	local[0]= w;
	goto CON20482;
CON20702:
	local[0]= fqv[22];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)PRINC(ctx,2,local+0); /*princ*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= argv[1];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)LISTP(ctx,1,local+2); /*listp*/
	if (w==NIL) goto IF20726;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[2]= w;
	goto IF20727;
IF20726:
	local[2]= argv[2];
IF20727:
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)F20132pprint1(ctx,4,local+0); /*pprint1*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= local[0];
	w = fqv[23];
	if (memq(local[1],w)==NIL) goto IF20762;
	local[1]= makeint(1);
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)F20115spaces(ctx,2,local+1); /*spaces*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)PRINC(ctx,2,local+1); /*princ*/
	local[1]= makeint(1);
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)F20115spaces(ctx,2,local+1); /*spaces*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[2];
	local[3]= makeint(3);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	argv[2] = w;
	local[2]= argv[2];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)PRNTSIZE(ctx,1,local+3); /*print-size*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= argv[3];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)F20135pparg(ctx,4,local+1); /*pparg*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	local[1]= argv[0];
	goto IF20763;
IF20762:
	local[1]= local[0];
	w = fqv[24];
	if (memq(local[1],w)==NIL) goto IF20844;
	local[1]= makeint(1);
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)F20115spaces(ctx,2,local+1); /*spaces*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[2];
	local[3]= makeint(3);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	argv[2] = w;
	local[2]= argv[2];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)PRNTSIZE(ctx,1,local+3); /*print-size*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= argv[3];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)F20135pparg(ctx,4,local+1); /*pparg*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	local[1]= argv[0];
	goto IF20845;
IF20844:
	local[1]= local[0];
	w = fqv[25];
	if (memq(local[1],w)==NIL) goto IF20905;
WHL20919:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	if (argv[0]==NIL) goto WHX20920;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX20920;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)TERPRI(ctx,1,local+1); /*terpri*/
	local[1]= argv[2];
	local[2]= makeint(3);
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[1]= w;
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)F20115spaces(ctx,2,local+1); /*spaces*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)PRINC(ctx,2,local+1); /*princ*/
	local[1]= makeint(1);
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)F20115spaces(ctx,2,local+1); /*spaces*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[1];
	local[3]= argv[2];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)PRNTSIZE(ctx,1,local+4); /*print-size*/
	local[4]= w;
	local[5]= makeint(4);
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,3,local+3); /*+*/
	local[3]= w;
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)F20132pprint1(ctx,4,local+1); /*pprint1*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	goto WHL20919;
WHX20920:
	local[1]= NIL;
BLK20921:
	argv[0] = fqv[26];
	local[1]= argv[0];
	goto IF20906;
IF20905:
	if (T==NIL) goto IF21012;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!issymbol(w)) goto IF21017;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)FBOUNDP(ctx,1,local+1); /*fboundp*/
	if (w==NIL) goto IF21017;
	local[1]= argv[2];
	local[2]= makeint(3);
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	argv[2] = w;
	local[1]= argv[2];
	goto IF21018;
IF21017:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)ADD1(ctx,1,local+1); /*1+*/
	argv[2] = w;
	local[1]= argv[2];
IF21018:
	goto IF21013;
IF21012:
	local[1]= NIL;
IF21013:
IF20906:
IF20845:
IF20763:
	w = local[1];
WHL21058:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto WHX21059;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	if (argv[0]==NIL) goto WHX21059;
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)TERPRI(ctx,1,local+0); /*terpri*/
	local[0]= argv[2];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F20115spaces(ctx,2,local+0); /*spaces*/
	w = argv[0];
	if (!!iscons(w)) goto CON21092;
	local[0]= fqv[27];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)PRINC(ctx,2,local+0); /*princ*/
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= makeint(2);
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)F20132pprint1(ctx,4,local+0); /*pprint1*/
	local[0]= w;
	goto CON21090;
CON21092:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= argv[1];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)F20132pprint1(ctx,4,local+0); /*pprint1*/
	local[0]= w;
	goto CON21090;
CON21112:
	local[0]= NIL;
CON21090:
	goto WHL21058;
WHX21059:
	local[0]= NIL;
BLK21060:
	local[0]= fqv[28];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)PRINC(ctx,2,local+0); /*princ*/
	local[0]= w;
	goto CON20482;
CON20711:
	local[0]= NIL;
CON20482:
	w = local[0];
	local[0]= w;
BLK20466:
	ctx->vsp=local; return(local[0]);}

/*pparg*/
static pointer F20135pparg(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	w = argv[0];
	if (!iscons(w)) goto OR21151;
	local[0]= argv[0];
	local[1]= argv[2];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)PRNTSIZE(ctx,2,local+0); /*print-size*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w!=NIL) goto OR21151;
	goto CON21150;
OR21151:
	local[0]= argv[0];
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)PRIN1(ctx,2,local+0); /*prin1*/
	local[0]= w;
	goto CON21148;
CON21150:
	local[0]= NIL;
	local[1]= fqv[29];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)PRINC(ctx,2,local+1); /*princ*/
	local[0] = argv[1];
WHL21203:
	if (argv[0]==NIL) goto WHX21204;
	local[1]= local[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)PRNTSIZE(ctx,1,local+2); /*print-size*/
	local[2]= w;
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,3,local+1); /*+*/
	local[0] = w;
	local[1]= local[0];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto CON21213;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)PRIN1(ctx,2,local+1); /*prin1*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	local[1]= argv[0];
	if (local[1]==NIL) goto AND21245;
	local[1]= fqv[30];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)PRINC(ctx,2,local+1); /*princ*/
	local[1]= w;
AND21245:
	goto CON21211;
CON21213:
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)TERPRI(ctx,1,local+1); /*terpri*/
	local[1]= argv[1];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)F20115spaces(ctx,2,local+1); /*spaces*/
	local[0] = argv[1];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[3];
	local[3]= local[0];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)F20132pprint1(ctx,4,local+1); /*pprint1*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	local[1]= argv[0];
	if (local[1]==NIL) goto AND21293;
	local[1]= fqv[31];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)PRINC(ctx,2,local+1); /*princ*/
	local[1]= w;
AND21293:
	goto CON21211;
CON21262:
	local[1]= NIL;
CON21211:
	goto WHL21203;
WHX21204:
	local[1]= NIL;
BLK21205:
	local[1]= fqv[32];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)PRINC(ctx,2,local+1); /*princ*/
	local[0]= w;
	goto CON21148;
CON21178:
	local[0]= NIL;
CON21148:
	w = local[0];
	local[0]= w;
BLK21132:
	ctx->vsp=local; return(local[0]);}

/*pprint-array*/
static pointer F20137pprint_array(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[33];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[34];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[10]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= argv[0];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(*ftab[5])(ctx,2,local+1,&ftab[5],fqv[35]); /*array-dimension*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(*ftab[5])(ctx,2,local+2,&ftab[5],fqv[35]); /*array-dimension*/
	local[2]= w;
	if (local[0]!=NIL) goto IF21368;
	local[0] = fqv[36];
	local[3]= local[0];
	goto IF21369;
IF21368:
	local[3]= NIL;
IF21369:
	local[3]= argv[1];
	local[4]= fqv[37];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= makeint(0);
	local[4]= local[1];
WHL21411:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX21412;
	local[5]= argv[1];
	local[6]= fqv[38];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,2,local+5); /*format*/
	local[5]= makeint(0);
	local[6]= local[2];
WHL21447:
	local[7]= local[5];
	w = local[6];
	if ((eusinteger_t)local[7] >= (eusinteger_t)w) goto WHX21448;
	local[7]= argv[1];
	local[8]= fqv[39];
	local[9]= argv[0];
	local[10]= local[3];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,3,local+9); /*aref*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[7]= w;
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto CON21467;
	local[7]= argv[1];
	local[8]= fqv[40];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,2,local+7); /*format*/
	local[7]= w;
	goto CON21465;
CON21467:
	local[7]= argv[1];
	local[8]= fqv[41];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,2,local+7); /*format*/
	local[7]= w;
	goto CON21465;
CON21478:
	local[7]= NIL;
CON21465:
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[5] = w;
	goto WHL21447;
WHX21448:
	local[7]= NIL;
BLK21449:
	w = NIL;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[5]= w;
	local[6]= argv[0];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(*ftab[5])(ctx,2,local+6,&ftab[5],fqv[35]); /*array-dimension*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LESSP(ctx,2,local+5); /*<*/
	if (w==NIL) goto IF21499;
	local[5]= argv[1];
	local[6]= fqv[42];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,2,local+5); /*format*/
	local[5]= argv[2];
	local[6]= makeint(4);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)F20115spaces(ctx,2,local+5); /*spaces*/
	local[5]= w;
	goto IF21500;
IF21499:
	local[5]= NIL;
IF21500:
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL21411;
WHX21412:
	local[5]= NIL;
BLK21413:
	w = NIL;
	local[3]= argv[1];
	local[4]= fqv[43];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,2,local+3); /*format*/
	local[0]= w;
BLK21317:
	ctx->vsp=local; return(local[0]);}

/*tprint*/
static pointer F20141tprint(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT21551;}
	local[0]= makeint(0);
ENT21551:
	if (n>=4) { local[1]=(argv[3]); goto ENT21550;}
	local[1]= makeint(79);
ENT21550:
	if (n>=5) { local[2]=(argv[4]); goto ENT21549;}
	local[2]= makeint(0);
ENT21549:
ENT21548:
	if (n>5) maerror();
	local[3]= local[2];
	local[4]= NIL;
	local[5]= makeint(0);
	local[6]= local[1];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	local[7]= makeint(0);
	local[8]= local[0];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)F20115spaces(ctx,1,local+8); /*spaces*/
WHL21613:
	if (argv[0]==NIL) goto WHX21614;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.car;
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)PRNTSIZE(ctx,1,local+8); /*print-size*/
	local[7] = w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	local[8]= argv[1];
	local[9]= local[7];
	local[10]= argv[1];
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[5] = w;
	local[8]= local[5];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)GREATERP(ctx,2,local+8); /*>*/
	if (w==NIL) goto CON21671;
	ctx->vsp=local+8;
	w=(pointer)TERPRI(ctx,0,local+8); /*terpri*/
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)F20115spaces(ctx,1,local+8); /*spaces*/
	local[3] = local[0];
	local[8]= local[1];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[6] = w;
	local[8]= local[6];
	goto CON21669;
CON21671:
	local[8]= NIL;
CON21669:
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)PRINC(ctx,1,local+8); /*princ*/
	local[8]= local[5];
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)F20115spaces(ctx,1,local+8); /*spaces*/
	local[8]= local[6];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[6] = w;
	local[8]= local[3];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[3] = w;
	goto WHL21613;
WHX21614:
	local[8]= NIL;
BLK21615:
	w = local[8];
	local[0]= w;
BLK21546:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___pprint(ctx,n,argv,env)
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
	local[0]= fqv[44];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF21739;
	local[0]= fqv[45];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[46],w);
	goto IF21740;
IF21739:
	local[0]= fqv[47];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF21740:
	local[0]= fqv[48];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[49],module,F20115spaces,fqv[50]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[51],module,F20119px,fqv[52]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[53],module,F20259,fqv[54]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[55],module,F20123pp_method,fqv[56]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[6],module,F20126pprint,fqv[57]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[58],module,F20129pprint_file,fqv[59]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[60],module,F20132pprint1,fqv[61]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[62],module,F20135pparg,fqv[63]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[64],module,F20137pprint_array,fqv[65]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[66],module,F20141tprint,fqv[67]);
	local[0]= fqv[68];
	local[1]= fqv[69];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,2,local+0,&ftab[6],fqv[70]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<7; i++) ftab[i]=fcallx;
}
