/* ./trans.c :  entry=trans */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "trans.h"
#pragma init (register_trans)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___trans();
extern pointer build_quote_vector();
static int register_trans()
  { add_module_initializer("___trans", ___trans);}

static pointer F102c_stringize();
static pointer F110ftab_index();

/*c-stringize*/
static pointer F102c_stringize(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*prin1-to-string*/
	local[0]= w;
	local[1]= NIL;
	local[2]= makeint(10);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[1])(ctx,2,local+2,&ftab[1],fqv[1]); /*position*/
	if (w==NIL) goto CON153;
	local[2]= makeint(0);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
WHL187:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX188;
	local[4]= local[0];
	{ register eusinteger_t i=intval(local[2]);
	  w=makeint(local[4]->c.str.chars[i]);}
	local[4]= w;
	local[5]= makeint(10);
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w==NIL) goto IF196;
	local[4]= makeint(92);
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= makeint(110);
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[1];
	goto IF197;
IF196:
	local[4]= local[0];
	{ register eusinteger_t i=intval(local[2]);
	  w=makeint(local[4]->c.str.chars[i]);}
	local[4]= w;
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[1];
IF197:
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL187;
WHX188:
	local[4]= NIL;
BLK189:
	w = NIL;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)NREVERSE(ctx,1,local+2); /*nreverse*/
	local[2]= w;
	local[3]= loadglobal(fqv[2]);
	ctx->vsp=local+4;
	w=(pointer)COERCE(ctx,2,local+2); /*coerce*/
	local[2]= w;
	goto CON151;
CON153:
	local[2]= local[0];
	goto CON151;
CON266:
	local[2]= NIL;
CON151:
	w = local[2];
	local[0]= w;
BLK125:
	ctx->vsp=local; return(local[0]);}

/*ftab-index*/
static pointer F110ftab_index(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[3];
	ctx->vsp=local+2;
	w=(pointer)GETPROP(ctx,2,local+0); /*get*/
	local[0]= w;
	if (local[0]!=NIL) goto IF309;
	local[1]= argv[0];
	local[2]= loadglobal(fqv[4]);
	local[3]= fqv[3];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= w;
	local[2]= argv[0];
	w = loadglobal(fqv[5]);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	storeglobal(fqv[5],local[2]);
	local[2]= loadglobal(fqv[4]);
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[2]= w;
	storeglobal(fqv[4],w);
	w = local[1];
	local[1]= w;
	goto IF310;
IF309:
	local[1]= local[0];
IF310:
	w = local[1];
	local[0]= w;
BLK284:
	ctx->vsp=local; return(local[0]);}

/*:label*/
static pointer M379translator_label(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[7];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK380:
	ctx->vsp=local; return(local[0]);}

/*:comment*/
static pointer M404translator_comment(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST407:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= fqv[8];
	local[2]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+3;
	w=(pointer)PRINC(ctx,2,local+1); /*princ*/
WHL424:
	if (local[0]==NIL) goto WHX425;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[1];
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+3;
	w=(pointer)PRINC(ctx,2,local+1); /*princ*/
	goto WHL424;
WHX425:
	local[1]= NIL;
BLK426:
	local[1]= fqv[9];
	local[2]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+3;
	w=(pointer)PRINC(ctx,2,local+1); /*princ*/
	local[1]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+2;
	w=(pointer)TERPRI(ctx,1,local+1); /*terpri*/
	local[0]= w;
BLK405:
	ctx->vsp=local; return(local[0]);}

/*:pop*/
static pointer M478translator_pop(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[2]==NIL) goto IF491;
	local[0]= argv[0]->c.obj.iv[2];
	argv[0]->c.obj.iv[2] = NIL;
	w = local[0];
	local[0]= w;
	goto IF492;
IF491:
	local[0]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+1;
	w=(pointer)SUB1(ctx,1,local+0); /*1-*/
	argv[0]->c.obj.iv[3] = w;
	local[0]= NIL;
	local[1]= fqv[10];
	local[2]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
IF492:
	w = local[0];
	local[0]= w;
BLK479:
	ctx->vsp=local; return(local[0]);}

/*:store*/
static pointer M538translator_store(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[0]->c.obj.iv[2]==NIL) goto OR555;
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)EQUAL(ctx,2,local+0); /*equal*/
	if (w==NIL) goto OR555;
	goto IF553;
OR555:
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[11];
	local[2]= argv[2];
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
	goto IF554;
IF553:
	argv[0]->c.obj.iv[2] = NIL;
	local[0]= argv[0]->c.obj.iv[2];
IF554:
	w = local[0];
	local[0]= w;
BLK539:
	ctx->vsp=local; return(local[0]);}

/*:push*/
static pointer M581translator_push(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[2] = argv[2];
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK582:
	ctx->vsp=local; return(local[0]);}

/*:clearpush*/
static pointer M609translator_clearpush(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[2]==NIL) goto IF623;
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[13];
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	argv[0]->c.obj.iv[3] = w;
	local[0]= argv[0]->c.obj.iv[3];
	goto IF624;
IF623:
	local[0]= NIL;
IF624:
	argv[0]->c.obj.iv[2] = NIL;
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK610:
	ctx->vsp=local; return(local[0]);}

/*:quote-entry*/
static pointer M670translator_quote_entry(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	w = argv[2];
	if (!issymbol(w)) goto CON696;
	local[1]= argv[2];
	w = argv[0]->c.obj.iv[4];
	local[0] = memq(local[1],w);
	if (local[0]==NIL) goto CON696;
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[0] = (pointer)((eusinteger_t)local[1] - (eusinteger_t)w);
	local[1]= local[0];
	goto CON694;
CON696:
	local[1]= argv[0]->c.obj.iv[4];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)NCONC(ctx,2,local+1); /*nconc*/
	argv[0]->c.obj.iv[4] = w;
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SUB1(ctx,1,local+1); /*1-*/
	local[0] = w;
	local[1]= local[0];
	goto CON694;
CON728:
	local[1]= NIL;
CON694:
	w = local[0];
	local[0]= w;
BLK671:
	ctx->vsp=local; return(local[0]);}

/*:dupe*/
static pointer M772translator_dupe(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= fqv[14];
	ctx->vsp=local+2;
	w=(pointer)EQUAL(ctx,2,local+0); /*equal*/
	if (w==NIL) goto CON787;
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[16];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON785;
CON787:
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[17];
	local[4]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+5;
	w=(pointer)SUB1(ctx,1,local+4); /*1-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON785;
CON799:
	local[0]= NIL;
CON785:
	w = local[0];
	local[0]= w;
BLK773:
	ctx->vsp=local; return(local[0]);}

/*:discard*/
static pointer M819translator_discard(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[0]->c.obj.iv[2]==NIL) goto IF835;
	argv[0]->c.obj.iv[2] = NIL;
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)SUB1(ctx,1,local+0); /*1-*/
	argv[2] = w;
	local[0]= argv[2];
	goto IF836;
IF835:
	local[0]= NIL;
IF836:
	local[0]= argv[2];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF861;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	argv[0]->c.obj.iv[3] = w;
	local[0]= argv[0]->c.obj.iv[3];
	goto IF862;
IF861:
	local[0]= NIL;
IF862:
	w = local[0];
	local[0]= w;
BLK820:
	ctx->vsp=local; return(local[0]);}

/*:adjust*/
static pointer M880translator_adjust(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	argv[0]->c.obj.iv[3] = w;
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK881:
	ctx->vsp=local; return(local[0]);}

/*:setpushcount*/
static pointer M906translator_setpushcount(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[3] = argv[2];
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK907:
	ctx->vsp=local; return(local[0]);}

/*:offset-from-fp*/
static pointer M928translator_offset_from_fp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK929:
	ctx->vsp=local; return(local[0]);}

/*:reset-vsp*/
static pointer M949translator_reset_vsp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[18];
	local[2]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK950:
	ctx->vsp=local; return(local[0]);}

/*:bind-special*/
static pointer M966translator_bind_special(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[20];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[22];
	local[2]= argv[0];
	local[3]= fqv[23];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= makeint(3);
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[3] = w;
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK967:
	ctx->vsp=local; return(local[0]);}

/*:unbind-special*/
static pointer M1013translator_unbind_special(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[24];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK1014:
	ctx->vsp=local; return(local[0]);}

/*:pushenv*/
static pointer M1044translator_pushenv(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[25];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK1045:
	ctx->vsp=local; return(local[0]);}

/*:enter*/
static pointer M1074translator_enter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+1;
	w=(pointer)TERPRI(ctx,1,local+0); /*terpri*/
	local[0]= argv[0];
	local[1]= fqv[26];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	argv[0]->c.obj.iv[3] = makeint(0);
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[27];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[28];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[29];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[30];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[31];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= w;
BLK1075:
	ctx->vsp=local; return(local[0]);}

/*:check-req-arg*/
static pointer M1128translator_check_req_arg(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= loadglobal(fqv[32]);
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF1145;
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[33];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= w;
	goto IF1146;
IF1145:
	local[0]= NIL;
IF1146:
	local[0]= loadglobal(fqv[32]);
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF1156;
	local[0]= argv[2];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto IF1162;
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[34];
	local[2]= argv[3];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)NUMEQUAL(ctx,2,local+2); /*=*/
	if (w==NIL) goto IF1170;
	local[2]= fqv[35];
	goto IF1171;
IF1170:
	local[2]= fqv[36];
IF1171:
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
	goto IF1163;
IF1162:
	local[0]= NIL;
IF1163:
	goto IF1157;
IF1156:
	local[0]= NIL;
IF1157:
	w = local[0];
	local[0]= w;
BLK1129:
	ctx->vsp=local; return(local[0]);}

/*:check-opt-arg*/
static pointer M1178translator_check_opt_arg(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[37];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[3];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,6,local+0); /*format*/
	local[0]= w;
BLK1179:
	ctx->vsp=local; return(local[0]);}

/*:check-rest-arg*/
static pointer M1204translator_check_rest_arg(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= loadglobal(fqv[32]);
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF1219;
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[38];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto IF1220;
IF1219:
	local[0]= NIL;
IF1220:
	w = local[0];
	local[0]= w;
BLK1205:
	ctx->vsp=local; return(local[0]);}

/*:rest*/
static pointer M1229translator_rest(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[39];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1230:
	ctx->vsp=local; return(local[0]);}

/*:parse-key-params*/
static pointer M1264translator_parse_key_params(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[40];
	local[2]= argv[0];
	local[3]= fqv[23];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[3];
	local[4]= argv[3];
	local[5]= argv[0]->c.obj.iv[3];
	if (argv[5]==NIL) goto IF1308;
	local[6]= makeint(1);
	goto IF1309;
IF1308:
	local[6]= makeint(0);
IF1309:
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,7,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[3] = w;
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK1265:
	ctx->vsp=local; return(local[0]);}

/*:check-key-arg*/
static pointer M1327translator_check_key_arg(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[41];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
BLK1328:
	ctx->vsp=local; return(local[0]);}

/*:getbase*/
static pointer M1349translator_getbase(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	if (w==NIL) goto CON1368;
	if (argv[3]==NIL) goto IF1374;
	local[0]= fqv[42];
	goto IF1375;
IF1374:
	local[0]= fqv[43];
IF1375:
	goto CON1366;
CON1368:
	local[0]= fqv[44];
WHL1391:
	local[1]= argv[2];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)GREATERP(ctx,2,local+1); /*>*/
	if (w==NIL) goto WHX1392;
	local[1]= loadglobal(fqv[2]);
	local[2]= local[0];
	local[3]= fqv[45];
	ctx->vsp=local+4;
	w=(pointer)CONCATENATE(ctx,3,local+1); /*concatenate*/
	local[0] = w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)SUB1(ctx,1,local+1); /*1-*/
	argv[2] = w;
	goto WHL1391;
WHX1392:
	local[1]= NIL;
BLK1393:
	local[1]= loadglobal(fqv[2]);
	local[2]= local[0];
	if (argv[3]==NIL) goto IF1424;
	local[3]= fqv[46];
	goto IF1425;
IF1424:
	local[3]= fqv[47];
IF1425:
	ctx->vsp=local+4;
	w=(pointer)CONCATENATE(ctx,3,local+1); /*concatenate*/
	local[0] = w;
	w = local[0];
	local[0]= w;
	goto CON1366;
CON1379:
	local[0]= NIL;
CON1366:
	w = local[0];
	local[0]= w;
BLK1350:
	ctx->vsp=local; return(local[0]);}

/*:load-t*/
static pointer M1438translator_load_t(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[48];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1439:
	ctx->vsp=local; return(local[0]);}

/*:load-nil*/
static pointer M1456translator_load_nil(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[49];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1457:
	ctx->vsp=local; return(local[0]);}

/*:load-int*/
static pointer M1474translator_load_int(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[50];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1475:
	ctx->vsp=local; return(local[0]);}

/*:load-float*/
static pointer M1497translator_load_float(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[51];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1498:
	ctx->vsp=local; return(local[0]);}

/*:load-quote*/
static pointer M1536translator_load_quote(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[52];
	local[4]= argv[0];
	local[5]= fqv[23];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1537:
	ctx->vsp=local; return(local[0]);}

/*:load-arg*/
static pointer M1580translator_load_arg(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[53];
	local[4]= argv[0];
	local[5]= fqv[54];
	local[6]= argv[3];
	local[7]= fqv[55];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,4,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1581:
	ctx->vsp=local; return(local[0]);}

/*:load-local*/
static pointer M1613translator_load_local(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[56];
	local[4]= argv[0];
	local[5]= fqv[54];
	local[6]= argv[3];
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,4,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1614:
	ctx->vsp=local; return(local[0]);}

/*:load-obj*/
static pointer M1644translator_load_obj(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[57];
	local[4]= argv[0];
	local[5]= fqv[54];
	local[6]= argv[3];
	local[7]= fqv[55];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,4,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1645:
	ctx->vsp=local; return(local[0]);}

/*:load-global*/
static pointer M1677translator_load_global(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[58];
	local[4]= argv[0];
	local[5]= fqv[23];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1678:
	ctx->vsp=local; return(local[0]);}

/*:store-arg*/
static pointer M1705translator_store_arg(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= NIL;
	local[3]= fqv[59];
	local[4]= argv[0];
	local[5]= fqv[54];
	local[6]= argv[3];
	local[7]= fqv[55];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,4,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1706:
	ctx->vsp=local; return(local[0]);}

/*:store-local*/
static pointer M1738translator_store_local(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= NIL;
	local[3]= fqv[60];
	local[4]= argv[0];
	local[5]= fqv[54];
	local[6]= argv[3];
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,4,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1739:
	ctx->vsp=local; return(local[0]);}

/*:store-obj*/
static pointer M1769translator_store_obj(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= NIL;
	local[3]= fqv[61];
	local[4]= argv[0];
	local[5]= fqv[54];
	local[6]= argv[3];
	local[7]= fqv[55];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,4,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1770:
	ctx->vsp=local; return(local[0]);}

/*:store-global*/
static pointer M1802translator_store_global(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[62];
	local[2]= argv[0];
	local[3]= fqv[23];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
BLK1803:
	ctx->vsp=local; return(local[0]);}

/*:load-ovaf*/
static pointer M1831translator_load_ovaf(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[63];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[23];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,4,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1832:
	ctx->vsp=local; return(local[0]);}

/*:load-indexed-ov*/
static pointer M1864translator_load_indexed_ov(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[64];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,4,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1865:
	ctx->vsp=local; return(local[0]);}

/*:store-ovaf*/
static pointer M1892translator_store_ovaf(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= NIL;
	local[3]= fqv[65];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[23];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,4,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1893:
	ctx->vsp=local; return(local[0]);}

/*:store-indexed-ov*/
static pointer M1925translator_store_indexed_ov(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[66];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= NIL;
	local[3]= fqv[67];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1926:
	ctx->vsp=local; return(local[0]);}

/*:call*/
static pointer M1954translator_call(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= argv[2];
	local[2]= fqv[68];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[0] = w;
	if (local[0]!=NIL) goto IF1992;
	local[1]= argv[2];
	local[2]= fqv[69];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[0] = w;
	local[1]= local[0];
	goto IF1993;
IF1992:
	local[1]= NIL;
IF1993:
	local[1]= argv[0];
	local[2]= fqv[6];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[21];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,1,local+1,&ftab[2],fqv[70]); /*functionp*/
	if (w!=NIL) goto IF2022;
	local[1]= loadglobal(fqv[71]);
	local[2]= fqv[72];
	local[3]= makeint(27);
	local[4]= argv[2];
	local[5]= makeint(27);
	local[6]= makeint(27);
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,6,local+1); /*format*/
	local[1]= w;
	goto IF2023;
IF2022:
	local[1]= NIL;
IF2023:
	if (local[0]==NIL) goto IF2040;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[73];
	local[3]= local[0];
	local[4]= argv[3];
	local[5]= argv[0]->c.obj.iv[3];
	local[6]= argv[3];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,6,local+1); /*format*/
	local[1]= w;
	goto IF2041;
IF2040:
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[74];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)F110ftab_index(ctx,1,local+3); /*ftab-index*/
	local[3]= w;
	local[4]= argv[3];
	local[5]= argv[0]->c.obj.iv[3];
	local[6]= argv[3];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F110ftab_index(ctx,1,local+6); /*ftab-index*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= fqv[23];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	local[8]= argv[2];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,8,local+1); /*format*/
	local[1]= w;
IF2041:
	local[1]= argv[0];
	local[2]= fqv[75];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[15];
	local[3]= fqv[76];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK1955:
	ctx->vsp=local; return(local[0]);}

/*:call-closure*/
static pointer M2091translator_call_closure(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[77];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[78];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= argv[0];
	local[1]= fqv[75];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[79];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2092:
	ctx->vsp=local; return(local[0]);}

/*:getfunc*/
static pointer M2142translator_getfunc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[80];
	local[4]= argv[0];
	local[5]= fqv[23];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2143:
	ctx->vsp=local; return(local[0]);}

/*:1-*/
static pointer M2186translator_1_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[81];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2187:
	ctx->vsp=local; return(local[0]);}

/*:1+*/
static pointer M2211translator_1_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[82];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2212:
	ctx->vsp=local; return(local[0]);}

/*:check-cons-nil*/
static pointer M2236translator_check_cons_nil(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= fqv[83];
	ctx->vsp=local+2;
	w=(pointer)EQUAL(ctx,2,local+0); /*equal*/
	if (w==NIL) goto IF2249;
	local[0]= argv[0];
	local[1]= fqv[12];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF2250;
IF2249:
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[84];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
IF2250:
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[85];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[86];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2237:
	ctx->vsp=local; return(local[0]);}

/*:car*/
static pointer M2280translator_car(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[87]);
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF2293;
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[88];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF2294;
IF2293:
	local[0]= loadglobal(fqv[32]);
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto IF2316;
	local[0]= argv[0];
	local[1]= fqv[89];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF2317;
IF2316:
	local[0]= NIL;
IF2317:
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[90];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
IF2294:
	w = local[0];
	local[0]= w;
BLK2281:
	ctx->vsp=local; return(local[0]);}

/*:cdr*/
static pointer M2343translator_cdr(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[87]);
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF2356;
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[91];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF2357;
IF2356:
	local[0]= loadglobal(fqv[32]);
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto IF2378;
	local[0]= argv[0];
	local[1]= fqv[89];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF2379;
IF2378:
	local[0]= NIL;
IF2379:
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[92];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
IF2357:
	w = local[0];
	local[0]= w;
BLK2344:
	ctx->vsp=local; return(local[0]);}

/*:caar*/
static pointer M2405translator_caar(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[87]);
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto CON2420;
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[93];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2418;
CON2420:
	local[0]= loadglobal(fqv[32]);
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto CON2437;
	local[0]= argv[0];
	local[1]= fqv[89];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[94];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[89];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[95];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2418;
CON2437:
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[96];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2418;
CON2479:
	local[0]= NIL;
CON2418:
	w = local[0];
	local[0]= w;
BLK2406:
	ctx->vsp=local; return(local[0]);}

/*:cddr*/
static pointer M2495translator_cddr(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[87]);
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto CON2510;
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[97];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2508;
CON2510:
	local[0]= loadglobal(fqv[32]);
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto CON2527;
	local[0]= argv[0];
	local[1]= fqv[89];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[98];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[89];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[99];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2508;
CON2527:
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[100];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2508;
CON2569:
	local[0]= NIL;
CON2508:
	w = local[0];
	local[0]= w;
BLK2496:
	ctx->vsp=local; return(local[0]);}

/*:cdar*/
static pointer M2585translator_cdar(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[87]);
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto CON2600;
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[101];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2598;
CON2600:
	local[0]= loadglobal(fqv[32]);
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto CON2617;
	local[0]= argv[0];
	local[1]= fqv[89];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[102];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[89];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[103];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2598;
CON2617:
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[104];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2598;
CON2659:
	local[0]= NIL;
CON2598:
	w = local[0];
	local[0]= w;
BLK2586:
	ctx->vsp=local; return(local[0]);}

/*:cadr*/
static pointer M2675translator_cadr(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[87]);
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto CON2690;
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[105];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2688;
CON2690:
	local[0]= loadglobal(fqv[32]);
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto CON2707;
	local[0]= argv[0];
	local[1]= fqv[89];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[106];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[89];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[107];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2688;
CON2707:
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[108];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2688;
CON2749:
	local[0]= NIL;
CON2688:
	w = local[0];
	local[0]= w;
BLK2676:
	ctx->vsp=local; return(local[0]);}

/*:caddr*/
static pointer M2765translator_caddr(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[87]);
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto CON2780;
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[109];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2778;
CON2780:
	local[0]= loadglobal(fqv[32]);
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto CON2797;
	local[0]= argv[0];
	local[1]= fqv[89];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[110];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[89];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[111];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[89];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[112];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2778;
CON2797:
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[113];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON2778;
CON2858:
	local[0]= NIL;
CON2778:
	w = local[0];
	local[0]= w;
BLK2766:
	ctx->vsp=local; return(local[0]);}

/*:cons*/
static pointer M2874translator_cons(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[114];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[115];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2875:
	ctx->vsp=local; return(local[0]);}

/*:svref*/
static pointer M2911translator_svref(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[116];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0];
	local[1]= fqv[12];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[117];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[118];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2912:
	ctx->vsp=local; return(local[0]);}

/*:svset*/
static pointer M2959translator_svset(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[119];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[120];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[121];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[122];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[123];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2960:
	ctx->vsp=local; return(local[0]);}

/*:char*/
static pointer M3005translator_char(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[124];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0];
	local[1]= fqv[12];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[125];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[126];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3006:
	ctx->vsp=local; return(local[0]);}

/*:setchar*/
static pointer M3053translator_setchar(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[127];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[128];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[129];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[130];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[131];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3054:
	ctx->vsp=local; return(local[0]);}

/*:bit*/
static pointer M3099translator_bit(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[132];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0];
	local[1]= fqv[12];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[133];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[134];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3100:
	ctx->vsp=local; return(local[0]);}

/*:setbit*/
static pointer M3147translator_setbit(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[135];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[136];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[137];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[138];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[139];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[140];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3148:
	ctx->vsp=local; return(local[0]);}

/*:vref*/
static pointer M3197translator_vref(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[141];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0];
	local[1]= fqv[12];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= local[1];
	if (fqv[142]!=local[2]) goto IF3249;
	local[2]= argv[0]->c.obj.iv[0];
	local[3]= fqv[143];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	goto IF3250;
IF3249:
	local[2]= local[1];
	if (fqv[144]!=local[2]) goto IF3261;
	local[2]= argv[0]->c.obj.iv[0];
	local[3]= fqv[145];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	goto IF3262;
IF3261:
	local[2]= local[1];
	if (fqv[146]!=local[2]) goto IF3273;
	local[2]= argv[0]->c.obj.iv[0];
	local[3]= fqv[147];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	goto IF3274;
IF3273:
	local[2]= local[1];
	if (fqv[148]!=local[2]) goto IF3285;
	local[2]= argv[0]->c.obj.iv[0];
	local[3]= fqv[149];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	goto IF3286;
IF3285:
	if (T==NIL) goto IF3297;
	local[2]= argv[0];
	local[3]= fqv[150];
	local[4]= fqv[151];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF3298;
IF3297:
	local[2]= NIL;
IF3298:
IF3286:
IF3274:
IF3262:
IF3250:
	w = local[2];
	local[1]= argv[0];
	local[2]= fqv[15];
	local[3]= fqv[152];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK3198:
	ctx->vsp=local; return(local[0]);}

/*:vset*/
static pointer M3315translator_vset(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[153];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[154];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[155];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= argv[2];
	local[1]= local[0];
	if (fqv[142]!=local[1]) goto IF3367;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[156];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,2,local+1); /*format*/
	local[1]= w;
	goto IF3368;
IF3367:
	local[1]= local[0];
	if (fqv[144]!=local[1]) goto IF3378;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[157];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,2,local+1); /*format*/
	local[1]= w;
	goto IF3379;
IF3378:
	local[1]= local[0];
	if (fqv[146]!=local[1]) goto IF3389;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[158];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,2,local+1); /*format*/
	local[1]= w;
	goto IF3390;
IF3389:
	local[1]= local[0];
	if (fqv[148]!=local[1]) goto IF3400;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[159];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,2,local+1); /*format*/
	local[1]= w;
	goto IF3401;
IF3400:
	if (T==NIL) goto IF3411;
	local[1]= argv[0];
	local[2]= fqv[150];
	local[3]= fqv[160];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF3412;
IF3411:
	local[1]= NIL;
IF3412:
IF3401:
IF3390:
IF3379:
IF3368:
	w = local[1];
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[161];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3316:
	ctx->vsp=local; return(local[0]);}

/*:nullx*/
static pointer M3428translator_nullx(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[162];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3429:
	ctx->vsp=local; return(local[0]);}

/*:eqx*/
static pointer M3453translator_eqx(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[163];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[12];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,4,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3454:
	ctx->vsp=local; return(local[0]);}

/*:memqx*/
static pointer M3483translator_memqx(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[164];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[165];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3484:
	ctx->vsp=local; return(local[0]);}

/*:type-check-predicate*/
static pointer M3514translator_type_check_predicate(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[166];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[167];
	local[4]= argv[2];
	local[5]= fqv[168];
	ctx->vsp=local+6;
	w=(*ftab[3])(ctx,2,local+4,&ftab[3],fqv[169]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3515:
	ctx->vsp=local; return(local[0]);}

/*:if-nil*/
static pointer M3552translator_if_nil(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[170];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
BLK3553:
	ctx->vsp=local; return(local[0]);}

/*:if-t*/
static pointer M3576translator_if_t(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[171];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
BLK3577:
	ctx->vsp=local; return(local[0]);}

/*:if-eq*/
static pointer M3600translator_if_eq(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[172];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= w;
BLK3601:
	ctx->vsp=local; return(local[0]);}

/*:if-neq*/
static pointer M3629translator_if_neq(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[173];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= w;
BLK3630:
	ctx->vsp=local; return(local[0]);}

/*:int-op2*/
static pointer M3658translator_int_op2(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	w = fqv[174];
	if (memq(local[0],w)==NIL) goto CON3675;
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[175];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[2];
	w = fqv[176];
	if (memq(local[0],w)==NIL) goto IF3693;
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[177];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= w;
	goto IF3694;
IF3693:
	local[0]= NIL;
IF3694:
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[178];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= argv[2];
	local[6]= fqv[179];
	ctx->vsp=local+7;
	w=(pointer)ASSQ(ctx,2,local+5); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,4,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON3673;
CON3675:
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[180];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[181];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[182];
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= argv[2];
	local[4]= fqv[183];
	ctx->vsp=local+5;
	w=(pointer)ASSQ(ctx,2,local+3); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	argv[0]->c.obj.iv[3] = w;
	local[0]= argv[0]->c.obj.iv[3];
	goto CON3673;
CON3731:
	local[0]= NIL;
CON3673:
	w = local[0];
	local[0]= w;
BLK3659:
	ctx->vsp=local; return(local[0]);}

/*:int-neg*/
static pointer M3776translator_int_neg(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[184];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3777:
	ctx->vsp=local; return(local[0]);}

/*:int-abs*/
static pointer M3801translator_int_abs(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[185];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3802:
	ctx->vsp=local; return(local[0]);}

/*:flt-abs*/
static pointer M3826translator_flt_abs(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[186];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3827:
	ctx->vsp=local; return(local[0]);}

/*:compare*/
static pointer M3851translator_compare(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[3];
	if (fqv[187]!=local[0]) goto CON3872;
	local[0]= argv[0];
	local[1]= fqv[188];
	local[2]= argv[4];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON3870;
CON3872:
	local[0]= argv[3];
	if (fqv[189]!=local[0]) goto CON3885;
	local[0]= argv[0];
	local[1]= fqv[190];
	local[2]= argv[4];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON3870;
CON3885:
	local[0]= argv[2];
	if (fqv[191]!=local[0]) goto CON3898;
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[192];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[193];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[3];
	local[4]= argv[4];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= w;
	goto CON3870;
CON3898:
	local[0]= argv[2];
	if (fqv[146]!=local[0]) goto CON3921;
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[194];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[195];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[196];
	local[2]= argv[3];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
	goto CON3870;
CON3921:
	local[0]= argv[0];
	local[1]= fqv[150];
	local[2]= fqv[197];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON3870;
CON3951:
	local[0]= NIL;
CON3870:
	w = local[0];
	local[0]= w;
BLK3852:
	ctx->vsp=local; return(local[0]);}

/*:flt-op2*/
static pointer M3960translator_flt_op2(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[198];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[199];
	local[2]= argv[0];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[200];
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= argv[2];
	local[4]= fqv[201];
	ctx->vsp=local+5;
	w=(pointer)ASSQ(ctx,2,local+3); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	argv[0]->c.obj.iv[3] = w;
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK3961:
	ctx->vsp=local; return(local[0]);}

/*:flt-neg*/
static pointer M4017translator_flt_neg(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[202];
	local[4]= argv[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK4018:
	ctx->vsp=local; return(local[0]);}

/*:type-checker*/
static pointer M4042translator_type_checker(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[203];
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK4043:
	ctx->vsp=local; return(local[0]);}

/*:if-type*/
static pointer M4067translator_if_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[204];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[205];
	local[2]= argv[0];
	local[3]= fqv[206];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
BLK4068:
	ctx->vsp=local; return(local[0]);}

/*:if-not-type*/
static pointer M4100translator_if_not_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[207];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[208];
	local[2]= argv[0];
	local[3]= fqv[206];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
BLK4101:
	ctx->vsp=local; return(local[0]);}

/*:jump*/
static pointer M4133translator_jump(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[209];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK4134:
	ctx->vsp=local; return(local[0]);}

/*:return*/
static pointer M4158translator_return(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[210];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+1;
	w=(pointer)SUB1(ctx,1,local+0); /*1-*/
	argv[0]->c.obj.iv[3] = w;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	if (w!=NIL) goto IF4181;
	local[0]= fqv[211];
	local[1]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[212]); /*warn*/
	local[0]= w;
	goto IF4182;
IF4181:
	local[0]= NIL;
IF4182:
	w = local[0];
	local[0]= w;
BLK4159:
	ctx->vsp=local; return(local[0]);}

/*:del-frame*/
static pointer M4199translator_del_frame(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[213];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[75];
	local[2]= makeint(3);
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[214];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK4200:
	ctx->vsp=local; return(local[0]);}

/*:entercatch*/
static pointer M4239translator_entercatch(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[215];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[216];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[217];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[218];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= makeint(6);
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[3] = w;
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK4240:
	ctx->vsp=local; return(local[0]);}

/*:exitcatch*/
static pointer M4289translator_exitcatch(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[219];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[220];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[221];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[222];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= makeint(6);
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	argv[0]->c.obj.iv[3] = w;
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[223];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK4290:
	ctx->vsp=local; return(local[0]);}

/*:throw*/
static pointer M4340translator_throw(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[224];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[225];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[226];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= w;
BLK4341:
	ctx->vsp=local; return(local[0]);}

/*:bind-cleaner*/
static pointer M4372translator_bind_cleaner(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[227];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[228];
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[3] = w;
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK4373:
	ctx->vsp=local; return(local[0]);}

/*:call-cleaner*/
static pointer M4410translator_call_cleaner(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[229];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[230];
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[231];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	argv[0]->c.obj.iv[3] = w;
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= fqv[232];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK4411:
	ctx->vsp=local; return(local[0]);}

/*:return-from*/
static pointer M4462translator_return_from(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= fqv[233];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	if (argv[3]==NIL) goto IF4491;
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[234];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto IF4492;
IF4491:
	local[0]= NIL;
IF4492:
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[235];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	argv[0]->c.obj.iv[3] = w;
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK4463:
	ctx->vsp=local; return(local[0]);}

/*:go-tag*/
static pointer M4517translator_go_tag(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	if (argv[3]==NIL) goto IF4540;
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[236];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto IF4541;
IF4540:
	local[0]= NIL;
IF4541:
	local[0]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	argv[0]->c.obj.iv[3] = w;
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK4518:
	ctx->vsp=local; return(local[0]);}

/*:closure*/
static pointer M4561translator_closure(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	local[3]= fqv[237];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK4562:
	ctx->vsp=local; return(local[0]);}

/*:defun*/
static pointer M4596translator_defun(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[238];
	local[2]= argv[0];
	local[3]= fqv[23];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[3];
	local[4]= argv[0];
	local[5]= fqv[23];
	local[6]= argv[4];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= w;
BLK4597:
	ctx->vsp=local; return(local[0]);}

/*:defmacro*/
static pointer M4643translator_defmacro(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[239];
	local[2]= argv[0];
	local[3]= fqv[23];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[3];
	local[4]= argv[0];
	local[5]= fqv[23];
	local[6]= argv[4];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= w;
BLK4644:
	ctx->vsp=local; return(local[0]);}

/*:quote-fqv-entry*/
static pointer M4690translator_quote_fqv_entry(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[2]!=NIL) goto IF4705;
	local[0]= fqv[240];
	goto IF4706;
IF4705:
	local[0]= NIL;
	local[1]= fqv[241];
	local[2]= argv[0];
	local[3]= fqv[23];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
IF4706:
	w = local[0];
	local[0]= w;
BLK4691:
	ctx->vsp=local; return(local[0]);}

/*:defmethod*/
static pointer M4719translator_defmethod(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[242];
	local[2]= argv[4];
	local[3]= argv[0];
	local[4]= fqv[23];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[23];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[243];
	local[7]= argv[5];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,6,local+0); /*format*/
	local[0]= w;
BLK4720:
	ctx->vsp=local; return(local[0]);}

/*:declare-forward-function*/
static pointer M4774translator_declare_forward_function(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[244];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK4775:
	ctx->vsp=local; return(local[0]);}

/*:quote*/
static pointer M4793translator_quote(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK4794:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M4808translator_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[2] = NIL;
	argv[0]->c.obj.iv[3] = makeint(0);
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK4809:
	ctx->vsp=local; return(local[0]);}

/*:init-file*/
static pointer M4829translator_init_file(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[3];
	local[1]= fqv[245];
	local[2]= fqv[246];
	ctx->vsp=local+3;
	w=(*ftab[5])(ctx,3,local+0,&ftab[5],fqv[247]); /*open*/
	argv[0]->c.obj.iv[0] = w;
	local[0]= argv[4];
	local[1]= fqv[245];
	local[2]= fqv[246];
	ctx->vsp=local+3;
	w=(*ftab[5])(ctx,3,local+0,&ftab[5],fqv[247]); /*open*/
	argv[0]->c.obj.iv[1] = w;
	argv[0]->c.obj.iv[4] = NIL;
	storeglobal(fqv[5],NIL);
	local[0]= makeint(0);
	storeglobal(fqv[4],local[0]);
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[248];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(*ftab[6])(ctx,1,local+2,&ftab[6],fqv[249]); /*namestring*/
	local[2]= w;
	local[3]= argv[5];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[250];
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,0,local+2,&ftab[7],fqv[251]); /*lisp-implementation-version*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[252];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[253];
	local[2]= argv[4];
	ctx->vsp=local+3;
	w=(*ftab[8])(ctx,1,local+2,&ftab[8],fqv[254]); /*pathname-name*/
	local[2]= w;
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(*ftab[9])(ctx,1,local+3,&ftab[9],fqv[255]); /*pathname-type*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[256];
	local[2]= argv[5];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[257];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[258];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[259];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= loadglobal(fqv[87]);
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto CON4929;
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[260];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[261];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= w;
	goto CON4927;
CON4929:
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[262];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= w;
	goto CON4927;
CON4941:
	local[0]= NIL;
CON4927:
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[263];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= fqv[264];
	w = loadglobal(fqv[265]);
	if (memq(local[0],w)==NIL) goto IF4953;
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[266];
	local[2]= argv[5];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto IF4954;
IF4953:
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[267];
	local[2]= argv[5];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
IF4954:
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[268];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[269];
	local[2]= argv[5];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[270];
	local[2]= loadglobal(fqv[2]);
	local[3]= fqv[271];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(*ftab[8])(ctx,1,local+4,&ftab[8],fqv[254]); /*pathname-name*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)CONCATENATE(ctx,3,local+2); /*concatenate*/
	local[2]= w;
	local[3]= argv[5];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= NIL;
	local[1]= loadglobal(fqv[272]);
WHL5012:
	if (local[1]==NIL) goto WHX5013;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0]->c.obj.iv[0];
	local[3]= fqv[273];
	local[4]= local[0];
	local[5]= fqv[68];
	ctx->vsp=local+6;
	w=(pointer)GETPROP(ctx,2,local+4); /*get*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	goto WHL5012;
WHX5013:
	local[2]= NIL;
BLK5014:
	w = NIL;
	local[0]= w;
BLK4830:
	ctx->vsp=local; return(local[0]);}

/*:eusmain*/
static pointer M5072translator_eusmain(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[274];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[275];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[276];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[277];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[278];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[279];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[280];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[281];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[282];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= w;
BLK5073:
	ctx->vsp=local; return(local[0]);}

/*:write-quote-vector*/
static pointer M5123translator_write_quote_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[283];
	local[2]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[284];
	local[2]= fqv[285];
	w = loadglobal(fqv[265]);
	if (memq(local[2],w)==NIL) goto IF5145;
	local[2]= fqv[286];
	goto IF5146;
IF5145:
	local[2]= fqv[287];
IF5146:
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[4];
WHL5175:
	if (local[1]==NIL) goto WHX5176;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,1,local+2,&ftab[0],fqv[0]); /*prin1-to-string*/
	local[2]= w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	local[4]= NIL;
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= fqv[288];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,2,local+5); /*format*/
	local[5]= makeint(0);
	local[6]= local[3];
WHL5269:
	local[7]= local[5];
	w = local[6];
	if ((eusinteger_t)local[7] >= (eusinteger_t)w) goto WHX5270;
	local[7]= local[2];
	{ register eusinteger_t i=intval(local[5]);
	  w=makeint(local[7]->c.str.chars[i]);}
	local[7]= w;
	local[8]= makeint(92);
	ctx->vsp=local+9;
	w=(pointer)EQ(ctx,2,local+7); /*eql*/
	if (w==NIL) goto CON5280;
	local[7]= makeint(92);
	local[8]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+9;
	w=(pointer)WRTBYTE(ctx,2,local+7); /*write-byte*/
	local[7]= makeint(92);
	local[8]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+9;
	w=(pointer)WRTBYTE(ctx,2,local+7); /*write-byte*/
	local[7]= w;
	goto CON5278;
CON5280:
	local[7]= local[2];
	{ register eusinteger_t i=intval(local[5]);
	  w=makeint(local[7]->c.str.chars[i]);}
	local[7]= w;
	local[8]= makeint(34);
	ctx->vsp=local+9;
	w=(pointer)EQ(ctx,2,local+7); /*eql*/
	if (w==NIL) goto CON5298;
	local[7]= argv[0]->c.obj.iv[1];
	local[8]= fqv[289];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,2,local+7); /*format*/
	local[7]= w;
	goto CON5278;
CON5298:
	local[7]= local[2];
	{ register eusinteger_t i=intval(local[5]);
	  w=makeint(local[7]->c.str.chars[i]);}
	local[7]= w;
	local[8]= makeint(10);
	ctx->vsp=local+9;
	w=(pointer)EQ(ctx,2,local+7); /*eql*/
	if (w==NIL) goto CON5312;
	local[7]= argv[0]->c.obj.iv[1];
	local[8]= fqv[290];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,2,local+7); /*format*/
	local[7]= w;
	goto CON5278;
CON5312:
	local[7]= local[2];
	{ register eusinteger_t i=intval(local[5]);
	  w=makeint(local[7]->c.str.chars[i]);}
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+9;
	w=(pointer)WRTBYTE(ctx,2,local+7); /*write-byte*/
	local[7]= w;
	goto CON5278;
CON5326:
	local[7]= NIL;
CON5278:
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[5] = w;
	goto WHL5269;
WHX5270:
	local[7]= NIL;
BLK5271:
	w = NIL;
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= fqv[291];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,2,local+5); /*format*/
	goto WHL5175;
WHX5176:
	local[2]= NIL;
BLK5177:
	w = NIL;
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[292];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= w;
BLK5124:
	ctx->vsp=local; return(local[0]);}

/*:declare-ftab*/
static pointer M5362translator_declare_ftab(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[4]);
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF5375;
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[293];
	local[2]= loadglobal(fqv[4]);
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto IF5376;
IF5375:
	local[0]= NIL;
IF5376:
	w = local[0];
	local[0]= w;
BLK5363:
	ctx->vsp=local; return(local[0]);}

/*:ftab-initializer*/
static pointer M5385translator_ftab_initializer(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[294];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= loadglobal(fqv[4]);
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF5403;
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[295];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[296];
	local[2]= loadglobal(fqv[4]);
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto IF5404;
IF5403:
	local[0]= NIL;
IF5404:
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[297];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= NIL;
	local[1]= loadglobal(fqv[5]);
WHL5442:
	if (local[1]==NIL) goto WHX5443;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= fqv[3];
	ctx->vsp=local+4;
	w=(*ftab[10])(ctx,2,local+2,&ftab[10],fqv[298]); /*remprop*/
	goto WHL5442;
WHX5443:
	local[2]= NIL;
BLK5444:
	w = NIL;
	local[0]= w;
BLK5386:
	ctx->vsp=local; return(local[0]);}

/*:close*/
static pointer M5500translator_close(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
BLK5501:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___trans(ctx,n,argv,env)
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
	local[0]= fqv[299];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF5529;
	local[0]= fqv[300];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[301],w);
	goto IF5530;
IF5529:
	local[0]= fqv[302];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF5530:
	local[0]= fqv[303];
	local[1]= fqv[304];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF5547;
	local[0]= fqv[303];
	local[1]= fqv[304];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[303];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF5570;
	local[0]= fqv[303];
	local[1]= fqv[305];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF5571;
IF5570:
	local[0]= NIL;
IF5571:
	local[0]= fqv[303];
	goto IF5548;
IF5547:
	local[0]= NIL;
IF5548:
	ctx->vsp=local+0;
	compfun(ctx,fqv[306],module,F102c_stringize,fqv[307]);
	local[0]= fqv[308];
	local[1]= fqv[305];
	local[2]= fqv[308];
	local[3]= fqv[309];
	local[4]= loadglobal(fqv[310]);
	local[5]= fqv[311];
	local[6]= fqv[312];
	local[7]= fqv[313];
	local[8]= NIL;
	local[9]= fqv[314];
	local[10]= NIL;
	local[11]= fqv[315];
	local[12]= makeint(-1);
	local[13]= fqv[316];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[11])(ctx,13,local+2,&ftab[11],fqv[317]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[4];
	local[1]= fqv[305];
	local[2]= makeint(0);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[5];
	local[1]= fqv[305];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[318],module,F110ftab_index,fqv[319]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M379translator_label,fqv[220],fqv[308],fqv[320]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M404translator_comment,fqv[26],fqv[308],fqv[321]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M478translator_pop,fqv[12],fqv[308],fqv[322]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M538translator_store,fqv[19],fqv[308],fqv[323]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M581translator_push,fqv[15],fqv[308],fqv[324]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M609translator_clearpush,fqv[6],fqv[308],fqv[325]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M670translator_quote_entry,fqv[23],fqv[308],fqv[326]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M772translator_dupe,fqv[327],fqv[308],fqv[328]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M819translator_discard,fqv[75],fqv[308],fqv[329]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M880translator_adjust,fqv[330],fqv[308],fqv[331]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M906translator_setpushcount,fqv[332],fqv[308],fqv[333]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M928translator_offset_from_fp,fqv[334],fqv[308],fqv[335]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M949translator_reset_vsp,fqv[21],fqv[308],fqv[336]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M966translator_bind_special,fqv[337],fqv[308],fqv[338]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1013translator_unbind_special,fqv[339],fqv[308],fqv[340]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1044translator_pushenv,fqv[341],fqv[308],fqv[342]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1074translator_enter,fqv[343],fqv[308],fqv[344]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1128translator_check_req_arg,fqv[345],fqv[308],fqv[346]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1178translator_check_opt_arg,fqv[347],fqv[308],fqv[348]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1204translator_check_rest_arg,fqv[349],fqv[308],fqv[350]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1229translator_rest,fqv[351],fqv[308],fqv[352]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1264translator_parse_key_params,fqv[353],fqv[308],fqv[354]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1327translator_check_key_arg,fqv[355],fqv[308],fqv[356]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1349translator_getbase,fqv[54],fqv[308],fqv[357]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1438translator_load_t,fqv[358],fqv[308],fqv[359]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1456translator_load_nil,fqv[360],fqv[308],fqv[361]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1474translator_load_int,fqv[362],fqv[308],fqv[363]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1497translator_load_float,fqv[364],fqv[308],fqv[365]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1536translator_load_quote,fqv[366],fqv[308],fqv[367]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1580translator_load_arg,fqv[368],fqv[308],fqv[369]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1613translator_load_local,fqv[370],fqv[308],fqv[371]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1644translator_load_obj,fqv[372],fqv[308],fqv[373]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1677translator_load_global,fqv[374],fqv[308],fqv[375]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1705translator_store_arg,fqv[376],fqv[308],fqv[377]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1738translator_store_local,fqv[378],fqv[308],fqv[379]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1769translator_store_obj,fqv[380],fqv[308],fqv[381]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1802translator_store_global,fqv[382],fqv[308],fqv[383]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1831translator_load_ovaf,fqv[384],fqv[308],fqv[385]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1864translator_load_indexed_ov,fqv[386],fqv[308],fqv[387]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1892translator_store_ovaf,fqv[388],fqv[308],fqv[389]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1925translator_store_indexed_ov,fqv[390],fqv[308],fqv[391]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1954translator_call,fqv[392],fqv[308],fqv[393]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2091translator_call_closure,fqv[394],fqv[308],fqv[395]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2142translator_getfunc,fqv[396],fqv[308],fqv[397]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2186translator_1_,fqv[398],fqv[308],fqv[399]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2211translator_1_,fqv[400],fqv[308],fqv[401]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2236translator_check_cons_nil,fqv[89],fqv[308],fqv[402]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2280translator_car,fqv[403],fqv[308],fqv[404]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2343translator_cdr,fqv[405],fqv[308],fqv[406]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2405translator_caar,fqv[407],fqv[308],fqv[408]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2495translator_cddr,fqv[409],fqv[308],fqv[410]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2585translator_cdar,fqv[411],fqv[308],fqv[412]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2675translator_cadr,fqv[413],fqv[308],fqv[414]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2765translator_caddr,fqv[415],fqv[308],fqv[416]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2874translator_cons,fqv[417],fqv[308],fqv[418]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2911translator_svref,fqv[419],fqv[308],fqv[420]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2959translator_svset,fqv[421],fqv[308],fqv[422]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3005translator_char,fqv[423],fqv[308],fqv[424]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3053translator_setchar,fqv[425],fqv[308],fqv[426]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3099translator_bit,fqv[427],fqv[308],fqv[428]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3147translator_setbit,fqv[429],fqv[308],fqv[430]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3197translator_vref,fqv[431],fqv[308],fqv[432]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3315translator_vset,fqv[433],fqv[308],fqv[434]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3428translator_nullx,fqv[435],fqv[308],fqv[436]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3453translator_eqx,fqv[437],fqv[308],fqv[438]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3483translator_memqx,fqv[439],fqv[308],fqv[440]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3514translator_type_check_predicate,fqv[441],fqv[308],fqv[442]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3552translator_if_nil,fqv[443],fqv[308],fqv[444]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3576translator_if_t,fqv[445],fqv[308],fqv[446]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3600translator_if_eq,fqv[190],fqv[308],fqv[447]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3629translator_if_neq,fqv[188],fqv[308],fqv[448]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3658translator_int_op2,fqv[449],fqv[308],fqv[450]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3776translator_int_neg,fqv[451],fqv[308],fqv[452]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3801translator_int_abs,fqv[453],fqv[308],fqv[454]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3826translator_flt_abs,fqv[455],fqv[308],fqv[456]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3851translator_compare,fqv[457],fqv[308],fqv[458]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3960translator_flt_op2,fqv[459],fqv[308],fqv[460]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4017translator_flt_neg,fqv[461],fqv[308],fqv[462]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4042translator_type_checker,fqv[206],fqv[308],fqv[463]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4067translator_if_type,fqv[464],fqv[308],fqv[465]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4100translator_if_not_type,fqv[466],fqv[308],fqv[467]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4133translator_jump,fqv[468],fqv[308],fqv[469]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4158translator_return,fqv[470],fqv[308],fqv[471]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4199translator_del_frame,fqv[472],fqv[308],fqv[473]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4239translator_entercatch,fqv[474],fqv[308],fqv[475]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4289translator_exitcatch,fqv[476],fqv[308],fqv[477]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4340translator_throw,fqv[478],fqv[308],fqv[479]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4372translator_bind_cleaner,fqv[480],fqv[308],fqv[481]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4410translator_call_cleaner,fqv[482],fqv[308],fqv[483]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4462translator_return_from,fqv[484],fqv[308],fqv[485]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4517translator_go_tag,fqv[486],fqv[308],fqv[487]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4561translator_closure,fqv[488],fqv[308],fqv[489]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4596translator_defun,fqv[490],fqv[308],fqv[491]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4643translator_defmacro,fqv[492],fqv[308],fqv[493]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4690translator_quote_fqv_entry,fqv[243],fqv[308],fqv[494]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4719translator_defmethod,fqv[495],fqv[308],fqv[496]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4774translator_declare_forward_function,fqv[497],fqv[308],fqv[498]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4793translator_quote,fqv[499],fqv[308],fqv[500]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4808translator_init,fqv[501],fqv[308],fqv[502]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4829translator_init_file,fqv[503],fqv[308],fqv[504]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5072translator_eusmain,fqv[505],fqv[308],fqv[506]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5123translator_write_quote_vector,fqv[507],fqv[308],fqv[508]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5362translator_declare_ftab,fqv[509],fqv[308],fqv[510]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5385translator_ftab_initializer,fqv[511],fqv[308],fqv[512]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5500translator_close,fqv[513],fqv[308],fqv[514]);
	local[0]= loadglobal(fqv[308]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	storeglobal(fqv[303],w);
	local[0]= fqv[515];
	local[1]= fqv[516];
	ctx->vsp=local+2;
	w=(*ftab[12])(ctx,2,local+0,&ftab[12],fqv[517]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<13; i++) ftab[i]=fcallx;
}
