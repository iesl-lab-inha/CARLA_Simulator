/* ./packsym.c :  entry=packsym */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "packsym.h"
#pragma init (register_packsym)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___packsym();
extern pointer build_quote_vector();
static int register_packsym()
  { add_module_initializer("___packsym", ___packsym);}

static pointer F45937metaclass_name();
static pointer F45941symbol_plist();
static pointer F45944remprop();
static pointer F45947symbol_package();
static pointer F45950symbol_name();
static pointer F45953make_symbol();
static pointer F45956documentation();
static pointer F45960gentemp();
static pointer F45965package_name();
static pointer F45968package_nicknames();
static pointer F45971package_use_list();
static pointer F45974package_used_by_list();
static pointer F45977packagep();
static pointer F45980use_package();
static pointer F45983unuse_package();
static pointer F45986make_package();
static pointer F45990rename_package();
static pointer F45993shadow();
static pointer F45996import();
static pointer F45999symbol_string();
static pointer F46002unintern();
static pointer F46004package_stats();

/*metaclass-name*/
static pointer F45937metaclass_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = *(ovafptr(argv[0],fqv[0]));
	local[0]= w;
BLK46046:
	ctx->vsp=local; return(local[0]);}

/*:home-package*/
static pointer M46076symbol_home_package(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK46077:
	ctx->vsp=local; return(local[0]);}

/*:pname*/
static pointer M46092symbol_pname(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK46093:
	ctx->vsp=local; return(local[0]);}

/*:func*/
static pointer M46108symbol_func(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK46109:
	ctx->vsp=local; return(local[0]);}

/*:value*/
static pointer M46124symbol_value(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	if (w==NIL) goto IF46139;
	local[0]= makeint(11);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,2,local+0); /*error*/
	local[0]= w;
	goto IF46140;
IF46139:
	local[0]= NIL;
IF46140:
	argv[0]->c.obj.iv[1] = argv[2];
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK46125:
	ctx->vsp=local; return(local[0]);}

/*:constant*/
static pointer M46157symbol_constant(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT46161;}
	local[0]= NIL;
ENT46161:
ENT46160:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)NUMEQUAL(ctx,2,local+1); /*=*/
	if (w==NIL) goto IF46180;
	goto IF46181;
IF46180:
	local[-1]= NIL;
IF46181:
	if (local[0]==NIL) goto IF46195;
	local[-1]= argv[0];
	local[0]= local[0];
	local[1]= fqv[1];
	ctx->vsp=local+2;
	w=(pointer)PUTPROP(ctx,3,local+-1); /*putprop*/
	local[-1]= w;
	goto IF46196;
IF46195:
	local[-1]= NIL;
IF46196:
	argv[0]->c.obj.iv[2] = makeint(0);
	argv[0]->c.obj.iv[1] = argv[2];
	w = argv[0];
	local[-2]= w;
BLK46158:
	ctx->vsp=local; return(local[0]);}

/*:special*/
static pointer M46220symbol_special(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT46224;}
	local[0]= NIL;
ENT46224:
ENT46223:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)NUMEQUAL(ctx,2,local+1); /*=*/
	if (w==NIL) goto IF46242;
	local[1]= makeint(11);
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,2,local+1); /*error*/
	local[1]= w;
	goto IF46243;
IF46242:
	local[1]= NIL;
IF46243:
	if (local[0]==NIL) goto IF46252;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= w;
	goto IF46253;
IF46252:
	local[1]= NIL;
IF46253:
	ctx->vsp=local+1;
	w=(pointer)NEXT_SPECIAL_INDEX(ctx,0,local+1); /*system::next-special-index*/
	argv[0]->c.obj.iv[2] = w;
	local[1]= argv[0];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SETSPECIAL(ctx,2,local+1); /*set*/
	w = argv[0];
	local[0]= w;
BLK46221:
	ctx->vsp=local; return(local[0]);}

/*:global*/
static pointer M46281symbol_global(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT46285;}
	local[0]= NIL;
ENT46285:
ENT46284:
	if (n>4) maerror();
	argv[0]->c.obj.iv[2] = makeint(2);
	argv[0]->c.obj.iv[1] = argv[2];
	if (local[0]==NIL) goto IF46316;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= w;
	goto IF46317;
IF46316:
	local[1]= NIL;
IF46317:
	w = argv[2];
	local[0]= w;
BLK46282:
	ctx->vsp=local; return(local[0]);}

/*:vtype*/
static pointer M46332symbol_vtype(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT46336;}
	local[0]= NIL;
ENT46336:
ENT46335:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF46352;
	argv[0]->c.obj.iv[2] = local[0];
	local[1]= argv[0]->c.obj.iv[2];
	goto IF46353;
IF46352:
	local[1]= NIL;
IF46353:
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK46333:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M46368symbol_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT46372;}
	local[0]= makeint(1);
ENT46372:
ENT46371:
	if (n>4) maerror();
	argv[0]->c.obj.iv[4] = argv[2];
	argv[0]->c.obj.iv[2] = local[0];
	w = argv[0];
	local[0]= w;
BLK46369:
	ctx->vsp=local; return(local[0]);}

/*symbol-plist*/
static pointer F45941symbol_plist(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[2];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK46406:
	ctx->vsp=local; return(local[0]);}

/*remprop*/
static pointer F45944remprop(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[3];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK46423:
	ctx->vsp=local; return(local[0]);}

/*symbol-package*/
static pointer F45947symbol_package(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[4];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK46443:
	ctx->vsp=local; return(local[0]);}

/*symbol-name*/
static pointer F45950symbol_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!issymbol(w)) goto IF46476;
	local[0]= argv[0]->c.obj.iv[4];
	goto IF46477;
IF46476:
	local[0]= fqv[5];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF46477:
	w = local[0];
	local[0]= w;
BLK46460:
	ctx->vsp=local; return(local[0]);}

/*make-symbol*/
static pointer F45953make_symbol(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT46491;}
	local[0]= loadglobal(fqv[6]);
ENT46491:
ENT46490:
	if (n>2) maerror();
	w = argv[0];
	if (isstring(w)) goto IF46507;
	local[1]= fqv[7];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF46508;
IF46507:
	local[1]= NIL;
IF46508:
	local[1]= loadglobal(fqv[8]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= argv[0];
	w = local[1];
	w->c.obj.iv[4] = local[2];
	local[2]= makeint(1);
	w = local[1];
	w->c.obj.iv[2] = local[2];
	local[2]= local[0];
	local[3]= local[2];
	w = local[1];
	w->c.obj.iv[5] = local[3];
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)MAKUNBOUND(ctx,1,local+2); /*makunbound*/
	w = local[1];
	local[0]= w;
BLK46488:
	ctx->vsp=local; return(local[0]);}

/*documentation*/
static pointer F45956documentation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT46559;}
	local[0]= NIL;
ENT46559:
ENT46558:
	if (n>2) maerror();
	local[1]= local[0];
	local[2]= local[1];
	w = fqv[9];
	if (memq(local[2],w)==NIL) goto IF46586;
	local[2]= argv[0];
	local[3]= fqv[10];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	goto IF46587;
IF46586:
	local[2]= local[1];
	w = fqv[11];
	if (memq(local[2],w)==NIL) goto IF46602;
	local[2]= argv[0];
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	goto IF46603;
IF46602:
	local[2]= local[1];
	w = fqv[12];
	if (memq(local[2],w)==NIL) goto IF46618;
	local[2]= argv[0];
	local[3]= fqv[13];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	goto IF46619;
IF46618:
	local[2]= local[1];
	w = fqv[14];
	if (memq(local[2],w)==NIL) goto IF46634;
	local[2]= argv[0];
	local[3]= fqv[15];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	goto IF46635;
IF46634:
	if (T==NIL) goto IF46650;
	local[2]= argv[0];
	local[3]= fqv[10];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	if (w!=NIL) goto CON46655;
CON46657:
	local[2]= argv[0];
	local[3]= fqv[15];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	if (w!=NIL) goto CON46655;
CON46665:
	local[2]= argv[0];
	local[3]= fqv[13];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	if (w!=NIL) goto CON46655;
CON46673:
	local[2]= argv[0];
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	if (w!=NIL) goto CON46655;
CON46681:
	local[2]= NIL;
CON46655:
	goto IF46651;
IF46650:
	local[2]= NIL;
IF46651:
IF46635:
IF46619:
IF46603:
IF46587:
	w = local[2];
	local[0]= w;
BLK46556:
	ctx->vsp=local; return(local[0]);}

/*gentemp*/
static pointer F45960gentemp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT46699;}
	local[0]= fqv[16];
ENT46699:
	if (n>=2) { local[1]=(argv[1]); goto ENT46698;}
	local[1]= loadglobal(fqv[6]);
ENT46698:
ENT46697:
	if (n>2) maerror();
	local[2]= NIL;
WHL46725:
	local[3]= loadglobal(fqv[17]);
	local[4]= local[0];
	local[5]= loadglobal(fqv[18]);
	ctx->vsp=local+6;
	w=(*ftab[0])(ctx,1,local+5,&ftab[0],fqv[17]); /*string*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)CONCATENATE(ctx,3,local+3); /*concatenate*/
	local[2] = w;
	local[3]= local[2];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)FINDSYMBOL(ctx,2,local+3); /*find-symbol*/
	if (w==NIL) goto WHX46726;
	local[3]= loadglobal(fqv[18]);
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[3]= w;
	storeglobal(fqv[18],w);
	goto WHL46725;
WHX46726:
	local[3]= NIL;
BLK46727:
	local[3]= local[2];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)INTERN(ctx,2,local+3); /*intern*/
	local[0]= w;
BLK46695:
	ctx->vsp=local; return(local[0]);}

/*:use-list*/
static pointer M46788package_use_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK46789:
	ctx->vsp=local; return(local[0]);}

/*:used-by-list*/
static pointer M46804package_used_by_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK46805:
	ctx->vsp=local; return(local[0]);}

/*:used-by*/
static pointer M46820package_used_by(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[19]); /*adjoin*/
	argv[0]->c.obj.iv[8] = w;
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK46821:
	ctx->vsp=local; return(local[0]);}

/*:use*/
static pointer M46847package_use(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto IF46862;
WHL46873:
	if (argv[2]==NIL) goto WHX46874;
	local[0]= argv[0];
	local[1]= fqv[20];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	goto WHL46873;
WHX46874:
	local[0]= NIL;
BLK46875:
	local[0]= argv[0]->c.obj.iv[2];
	goto IF46863;
IF46862:
	local[0]= NIL;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)FINDPACKAGE(ctx,1,local+1); /*find-package*/
	argv[2] = w;
	local[1]= argv[2];
	if (argv[0]==local[1]) goto IF46924;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F45977packagep(ctx,1,local+1); /*packagep*/
	if (w==NIL) goto IF46924;
	local[1]= NIL;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)FINDPACKAGE(ctx,1,local+2); /*find-package*/
	local[2]= w;
	local[3]= makeint(0);
	local[4]= *(ovafptr(local[2],fqv[21]));
	local[5]= local[4];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
WHL46970:
	local[6]= local[3];
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,2,local+6); /*<*/
	if (w==NIL) goto WHX46971;
	local[6]= local[4];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[1] = w;
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[3] = w;
	w = local[1];
	if (!issymbol(w)) goto IF47000;
	local[6]= argv[0];
	local[7]= fqv[22];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[0] = w;
	if (local[0]==NIL) goto IF47021;
	local[6]= argv[0]->c.obj.iv[5];
	{ register eusinteger_t i=intval(local[0]);
	  w=(local[6]->c.vec.v[i]);}
	local[6]= w;
	if (local[1]==local[6]) goto IF47021;
	local[6]= fqv[23];
	local[7]= local[1];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)SIGERROR(ctx,3,local+6); /*error*/
	local[6]= w;
	goto IF47022;
IF47021:
	local[6]= NIL;
IF47022:
	goto IF47001;
IF47000:
	local[6]= NIL;
IF47001:
	goto WHL46970;
WHX46971:
	local[6]= NIL;
BLK46972:
	w = NIL;
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[19]); /*adjoin*/
	argv[0]->c.obj.iv[2] = w;
	local[1]= argv[2];
	local[2]= fqv[24];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF46925;
IF46924:
	local[1]= NIL;
IF46925:
	w = local[1];
	local[0]= w;
IF46863:
	w = local[0];
	local[0]= w;
BLK46848:
	ctx->vsp=local; return(local[0]);}

/*:unuse*/
static pointer M47062package_unuse(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	argv[2] = w;
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)F45977packagep(ctx,1,local+0); /*packagep*/
	if (w==NIL) goto IF47087;
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[25]); /*delete*/
	argv[0]->c.obj.iv[2] = w;
	local[0]= argv[2];
	local[1]= fqv[26];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF47088;
IF47087:
	local[0]= NIL;
IF47088:
	w = local[0];
	local[0]= w;
BLK47063:
	ctx->vsp=local; return(local[0]);}

/*:unused*/
static pointer M47116package_unused(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[25]); /*delete*/
	argv[0]->c.obj.iv[8] = w;
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK47117:
	ctx->vsp=local; return(local[0]);}

/*:name*/
static pointer M47142package_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK47143:
	ctx->vsp=local; return(local[0]);}

/*:rename*/
static pointer M47162package_rename(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[17]); /*string*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK47163:
	ctx->vsp=local; return(local[0]);}

/*:nicknames*/
static pointer M47189package_nicknames(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT47193;}
	local[0]= NIL;
ENT47193:
ENT47192:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF47209;
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= (pointer)get_sym_func(fqv[17]);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	local[3]= fqv[27];
	local[4]= (pointer)get_sym_func(fqv[28]);
	ctx->vsp=local+5;
	w=(*ftab[3])(ctx,4,local+1,&ftab[3],fqv[29]); /*union*/
	argv[0]->c.obj.iv[1] = w;
	local[1]= argv[0]->c.obj.iv[1];
	goto IF47210;
IF47209:
	local[1]= NIL;
IF47210:
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK47190:
	ctx->vsp=local; return(local[0]);}

/*:hash*/
static pointer M47237package_hash(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[17]); /*string*/
	argv[2] = w;
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)SXHASH(ctx,1,local+0); /*sxhash*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MOD(ctx,2,local+0); /*mod*/
	local[0]= w;
BLK47238:
	ctx->vsp=local; return(local[0]);}

/*:enter*/
static pointer M47270package_enter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	if (issymbol(w)) goto IF47285;
	w = NIL;
	ctx->vsp=local+0;
	local[0]=w;
	goto BLK47271;
	goto IF47286;
IF47285:
	local[0]= NIL;
IF47286:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)SXHASH(ctx,1,local+0); /*sxhash*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MOD(ctx,2,local+0); /*mod*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[6];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)GREQP(ctx,2,local+2); /*>=*/
	if (w==NIL) goto IF47319;
	local[2]= fqv[30];
	local[3]= argv[2];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,3,local+2); /*error*/
	local[2]= w;
	goto IF47320;
IF47319:
	local[2]= NIL;
IF47320:
WHL47331:
	local[2]= argv[0]->c.obj.iv[5];
	{ register eusinteger_t i=intval(local[0]);
	  w=(local[2]->c.vec.v[i]);}
	if (!issymbol(w)) goto WHX47332;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)GREQP(ctx,2,local+2); /*>=*/
	if (w==NIL) goto IF47342;
	local[0] = makeint(0);
	local[2]= local[0];
	goto IF47343;
IF47342:
	local[2]= NIL;
IF47343:
	goto WHL47331;
WHX47332:
	local[2]= NIL;
BLK47333:
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= local[0];
	w = argv[2];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[3]); v=local[2];
	  v->c.vec.v[i]=w;}
	local[2]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	argv[0]->c.obj.iv[6] = w;
	w = argv[2];
	local[0]= w;
BLK47271:
	ctx->vsp=local; return(local[0]);}

/*:find*/
static pointer M47382package_find(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	if (issymbol(w)) goto IF47403;
	local[0]= fqv[31];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto IF47404;
IF47403:
	local[0]= NIL;
IF47404:
	local[0]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)SXHASH(ctx,1,local+1); /*sxhash*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)MOD(ctx,2,local+1); /*mod*/
	local[1]= w;
	local[2]= NIL;
WHL47439:
	if (T==NIL) goto WHX47440;
	local[3]= argv[0]->c.obj.iv[5];
	local[4]= local[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)MOD(ctx,2,local+4); /*mod*/
	{ register eusinteger_t i=intval(w);
	  w=(local[3]->c.vec.v[i]);}
	local[2] = w;
	local[3]= local[2];
	if (makeint(0)!=local[3]) goto CON47462;
	w = NIL;
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK47383;
	goto CON47460;
CON47462:
	local[3]= local[2];
	local[3]= ((makeint(1))==(local[3])?T:NIL);
	if (local[3]!=NIL) goto CON47460;
CON47470:
	local[3]= local[2]->c.obj.iv[4];
	local[4]= argv[2]->c.obj.iv[4];
	ctx->vsp=local+5;
	w=(pointer)EQUAL(ctx,2,local+3); /*equal*/
	if (w==NIL) goto CON47477;
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)MOD(ctx,2,local+3); /*mod*/
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK47383;
	goto CON47460;
CON47477:
	local[3]= NIL;
CON47460:
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	local[3]= local[1];
	local[4]= makeint(2);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)GREQP(ctx,2,local+3); /*>=*/
	if (w==NIL) goto IF47495;
	local[3]= fqv[32];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,2,local+3); /*error*/
	local[3]= w;
	goto IF47496;
IF47495:
	local[3]= NIL;
IF47496:
	goto WHL47439;
WHX47440:
	local[3]= NIL;
BLK47441:
	w = NIL;
	local[0]= w;
BLK47383:
	ctx->vsp=local; return(local[0]);}

/*:shadow*/
static pointer M47521package_shadow(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[22];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (w!=NIL) goto IF47537;
	local[0]= argv[0];
	local[1]= fqv[33];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,1,local+2,&ftab[0],fqv[17]); /*string*/
	local[2]= w;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F45953make_symbol(ctx,2,local+2); /*make-symbol*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF47538;
IF47537:
	local[0]= NIL;
IF47538:
	w = local[0];
	local[0]= w;
BLK47522:
	ctx->vsp=local; return(local[0]);}

/*:import*/
static pointer M47563package_import(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[22];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	if (local[0]==NIL) goto IF47594;
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[5];
	{ register eusinteger_t i=intval(local[0]);
	  w=(local[2]->c.vec.v[i]);}
	if (w==local[1]) goto IF47594;
	local[1]= fqv[34];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,2,local+1); /*error*/
	local[1]= w;
	goto IF47595;
IF47594:
	local[1]= argv[0];
	local[2]= fqv[33];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
IF47595:
	w = local[1];
	local[0]= w;
BLK47564:
	ctx->vsp=local; return(local[0]);}

/*:unintern*/
static pointer M47620package_unintern(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= *(ovafptr(argv[2],fqv[35]));
	if (argv[0]!=local[1]) goto IF47645;
	local[1]= NIL;
	local[2]= local[1];
	*(ovafptr(argv[2],fqv[35])) = local[2];
	goto IF47646;
IF47645:
	local[1]= NIL;
IF47646:
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0] = w;
	if (local[0]==NIL) goto IF47671;
	local[1]= argv[0]->c.obj.iv[5];
	local[2]= local[0];
	w = makeint(1);
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[2]); v=local[1];
	  v->c.vec.v[i]=w;}
	local[1]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+2;
	w=(pointer)SUB1(ctx,1,local+1); /*1-*/
	argv[0]->c.obj.iv[6] = w;
	local[1]= argv[0]->c.obj.iv[6];
	goto IF47672;
IF47671:
	local[1]= NIL;
IF47672:
	local[1]= argv[0];
	local[2]= fqv[36];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0] = w;
	if (local[0]==NIL) goto IF47708;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= local[0];
	w = makeint(1);
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[2]); v=local[1];
	  v->c.vec.v[i]=w;}
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(pointer)SUB1(ctx,1,local+1); /*1-*/
	argv[0]->c.obj.iv[4] = w;
	local[1]= argv[0]->c.obj.iv[4];
	goto IF47709;
IF47708:
	local[1]= NIL;
IF47709:
	w = local[1];
	local[0]= w;
BLK47621:
	ctx->vsp=local; return(local[0]);}

/*:find-external*/
static pointer M47733package_find_external(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	if (issymbol(w)) goto IF47754;
	local[0]= fqv[37];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto IF47755;
IF47754:
	local[0]= NIL;
IF47755:
	local[0]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)SXHASH(ctx,1,local+1); /*sxhash*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)MOD(ctx,2,local+1); /*mod*/
	local[1]= w;
	local[2]= NIL;
WHL47790:
	if (T==NIL) goto WHX47791;
	local[3]= argv[0]->c.obj.iv[3];
	{ register eusinteger_t i=intval(local[1]);
	  w=(local[3]->c.vec.v[i]);}
	local[2] = w;
	local[3]= local[2];
	if (makeint(0)!=local[3]) goto CON47810;
	w = NIL;
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK47734;
	goto CON47808;
CON47810:
	local[3]= local[2];
	local[3]= ((makeint(1))==(local[3])?T:NIL);
	if (local[3]!=NIL) goto CON47808;
CON47818:
	local[3]= local[2]->c.obj.iv[4];
	local[4]= argv[2]->c.obj.iv[4];
	ctx->vsp=local+5;
	w=(pointer)EQUAL(ctx,2,local+3); /*equal*/
	if (w==NIL) goto CON47825;
	w = local[1];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK47734;
	goto CON47808;
CON47825:
	local[3]= NIL;
CON47808:
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)GREQP(ctx,2,local+3); /*>=*/
	if (w==NIL) goto IF47841;
	local[1] = makeint(0);
	local[3]= local[1];
	goto IF47842;
IF47841:
	local[3]= NIL;
IF47842:
	goto WHL47790;
WHX47791:
	local[3]= NIL;
BLK47792:
	w = NIL;
	local[0]= w;
BLK47734:
	ctx->vsp=local; return(local[0]);}

/*:unexport*/
static pointer M47864package_unexport(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[36];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	if (local[0]==NIL) goto IF47895;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= local[0];
	w = makeint(0);
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[2]); v=local[1];
	  v->c.vec.v[i]=w;}
	local[1]= w;
	goto IF47896;
IF47895:
	local[1]= NIL;
IF47896:
	w = local[1];
	local[0]= w;
BLK47865:
	ctx->vsp=local; return(local[0]);}

/*package-name*/
static pointer F45965package_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	argv[0] = w;
	local[0]= argv[0];
	local[1]= fqv[38];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK47910:
	ctx->vsp=local; return(local[0]);}

/*package-nicknames*/
static pointer F45968package_nicknames(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	local[1]= fqv[39];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK47936:
	ctx->vsp=local; return(local[0]);}

/*package-use-list*/
static pointer F45971package_use_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	local[1]= fqv[40];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK47955:
	ctx->vsp=local; return(local[0]);}

/*package-used-by-list*/
static pointer F45974package_used_by_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	local[1]= fqv[41];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK47974:
	ctx->vsp=local; return(local[0]);}

/*packagep*/
static pointer F45977packagep(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)GETCLASS(ctx,1,local+0); /*class*/
	local[0]= w;
	w = ((loadglobal(fqv[42]))==(local[0])?T:NIL);
	local[0]= w;
BLK47993:
	ctx->vsp=local; return(local[0]);}

/*use-package*/
static pointer F45980use_package(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT48017;}
	local[0]= loadglobal(fqv[6]);
ENT48017:
ENT48016:
	if (n>2) maerror();
	local[1]= local[0];
	local[2]= fqv[20];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = T;
	local[0]= w;
BLK48014:
	ctx->vsp=local; return(local[0]);}

/*unuse-package*/
static pointer F45983unuse_package(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT48045;}
	local[0]= loadglobal(fqv[6]);
ENT48045:
ENT48044:
	if (n>2) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)FINDPACKAGE(ctx,1,local+1); /*find-package*/
	local[1]= w;
	local[2]= fqv[43];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK48042:
	ctx->vsp=local; return(local[0]);}

/*make-package*/
static pointer F45986make_package(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[44], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY48080;
	local[0] = NIL;
KEY48080:
	if (n & (1<<1)) goto KEY48085;
	local[2]= fqv[45];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[1] = w;
KEY48085:
	local[2]= argv[0];
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)MAKEPACKAGE(ctx,3,local+2); /*system::makepackage*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[20];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	w = local[2];
	local[0]= w;
BLK48070:
	ctx->vsp=local; return(local[0]);}

/*in-package*/
static pointer F48123(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[46];
	local[1]= fqv[47];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[48];
	local[3]= fqv[6];
	local[4]= fqv[47];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[49];
	local[4]= fqv[50];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK48124:
	ctx->vsp=local; return(local[0]);}

/*rename-package*/
static pointer F45990rename_package(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT48185;}
	local[0]= NIL;
ENT48185:
ENT48184:
	if (n>3) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)FINDPACKAGE(ctx,1,local+1); /*find-package*/
	argv[0] = w;
	local[1]= argv[0];
	local[2]= fqv[51];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	if (local[0]==NIL) goto IF48217;
	local[1]= argv[0];
	local[2]= fqv[39];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF48218;
IF48217:
	local[1]= NIL;
IF48218:
	w = local[1];
	local[0]= w;
BLK48182:
	ctx->vsp=local; return(local[0]);}

/*shadow*/
static pointer F45993shadow(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT48234;}
	local[0]= loadglobal(fqv[6]);
ENT48234:
ENT48233:
	if (n>2) maerror();
	w = argv[0];
	if (!issymbol(w)) goto IF48249;
	local[1]= local[0];
	local[2]= fqv[52];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF48250;
IF48249:
WHL48261:
	if (argv[0]==NIL) goto WHX48262;
	local[1]= local[0];
	local[2]= fqv[52];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	goto WHL48261;
WHX48262:
	local[1]= NIL;
BLK48263:
IF48250:
	w = local[1];
	local[0]= w;
BLK48231:
	ctx->vsp=local; return(local[0]);}

/*import*/
static pointer F45996import(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT48295;}
	local[0]= loadglobal(fqv[6]);
ENT48295:
ENT48294:
	if (n>2) maerror();
	w = argv[0];
	if (!issymbol(w)) goto IF48310;
	local[1]= local[0];
	local[2]= fqv[53];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF48311;
IF48310:
WHL48322:
	if (argv[0]==NIL) goto WHX48323;
	local[1]= local[0];
	local[2]= fqv[53];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	goto WHL48322;
WHX48323:
	local[1]= NIL;
BLK48324:
IF48311:
	w = T;
	local[0]= w;
BLK48292:
	ctx->vsp=local; return(local[0]);}

/*symbol-string*/
static pointer F45999symbol_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!issymbol(w)) goto IF48365;
	local[0]= *(ovafptr(argv[0],fqv[54]));
	goto IF48366;
IF48365:
	local[0]= fqv[55];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF48366:
	w = local[0];
	local[0]= w;
BLK48355:
	ctx->vsp=local; return(local[0]);}

/*unintern*/
static pointer F46002unintern(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT48380;}
	local[0]= loadglobal(fqv[6]);
ENT48380:
ENT48379:
	if (n>2) maerror();
	w = argv[0];
	if (!issymbol(w)) goto IF48395;
	local[1]= local[0];
	local[2]= fqv[56];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF48396;
IF48395:
	local[1]= fqv[57];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
IF48396:
	w = local[1];
	local[0]= w;
BLK48377:
	ctx->vsp=local; return(local[0]);}

/*package-stats*/
static pointer F46004package_stats(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT48413;}
	local[0]= T;
ENT48413:
ENT48412:
	if (n>1) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)ALLPACKAGES(ctx,0,local+5); /*list-all-packages*/
	local[5]= w;
WHL48449:
	if (local[5]==NIL) goto WHX48450;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= (pointer)get_sym_func(fqv[58]);
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)F45971package_use_list(ctx,1,local+7); /*package-use-list*/
	local[7]= w;
	local[8]= fqv[39];
	ctx->vsp=local+9;
	w=(*ftab[4])(ctx,2,local+7,&ftab[4],fqv[59]); /*send-all*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[2] = w;
	local[6]= (pointer)get_sym_func(fqv[58]);
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)F45974package_used_by_list(ctx,1,local+7); /*package-used-by-list*/
	local[7]= w;
	local[8]= fqv[39];
	ctx->vsp=local+9;
	w=(*ftab[4])(ctx,2,local+7,&ftab[4],fqv[59]); /*send-all*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[3] = w;
	local[6]= local[0];
	local[7]= fqv[60];
	local[8]= local[4];
	local[9]= fqv[39];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= local[4];
	local[10]= fqv[39];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF48544;
	local[9]= local[4];
	local[10]= fqv[39];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
	goto IF48545;
IF48544:
	local[9]= fqv[61];
IF48545:
	local[10]= local[4]->c.obj.iv[4];
	if (local[2]==NIL) goto IF48572;
	local[11]= local[2];
	goto IF48573;
IF48572:
	local[11]= fqv[62];
IF48573:
	if (local[3]==NIL) goto IF48579;
	local[12]= local[3];
	goto IF48580;
IF48579:
	local[12]= fqv[63];
IF48580:
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,7,local+6); /*format*/
	goto WHL48449;
WHX48450:
	local[6]= NIL;
BLK48451:
	w = NIL;
	local[0]= w;
BLK48410:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___packsym(ctx,n,argv,env)
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
	local[0]= fqv[64];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= fqv[65];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF48599;
	local[0]= fqv[66];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[6],w);
	goto IF48600;
IF48599:
	local[0]= fqv[67];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF48600:
	local[0]= fqv[68];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[69],module,F45937metaclass_name,fqv[70]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46076symbol_home_package,fqv[4],fqv[8],fqv[71]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46092symbol_pname,fqv[72],fqv[8],fqv[73]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46108symbol_func,fqv[74],fqv[8],fqv[75]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46124symbol_value,fqv[76],fqv[8],fqv[77]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46157symbol_constant,fqv[78],fqv[8],fqv[79]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46220symbol_special,fqv[80],fqv[8],fqv[81]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46281symbol_global,fqv[82],fqv[8],fqv[83]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46332symbol_vtype,fqv[84],fqv[8],fqv[85]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46368symbol_init,fqv[86],fqv[8],fqv[87]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[88],module,F45941symbol_plist,fqv[89]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[90],module,F45944remprop,fqv[91]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[92],module,F45947symbol_package,fqv[93]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[94],module,F45950symbol_name,fqv[95]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[96],module,F45953make_symbol,fqv[97]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[98],module,F45956documentation,fqv[99]);
	local[0]= makeint(0);
	storeglobal(fqv[18],local[0]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[100],module,F45960gentemp,fqv[101]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46788package_use_list,fqv[40],fqv[42],fqv[102]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46804package_used_by_list,fqv[41],fqv[42],fqv[103]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46820package_used_by,fqv[24],fqv[42],fqv[104]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46847package_use,fqv[20],fqv[42],fqv[105]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47062package_unuse,fqv[43],fqv[42],fqv[106]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47116package_unused,fqv[26],fqv[42],fqv[107]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47142package_name,fqv[38],fqv[42],fqv[108]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47162package_rename,fqv[51],fqv[42],fqv[109]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47189package_nicknames,fqv[39],fqv[42],fqv[110]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47237package_hash,fqv[111],fqv[42],fqv[112]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47270package_enter,fqv[33],fqv[42],fqv[113]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47382package_find,fqv[22],fqv[42],fqv[114]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47521package_shadow,fqv[52],fqv[42],fqv[115]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47563package_import,fqv[53],fqv[42],fqv[116]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47620package_unintern,fqv[56],fqv[42],fqv[117]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47733package_find_external,fqv[36],fqv[42],fqv[118]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47864package_unexport,fqv[119],fqv[42],fqv[120]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[121],module,F45965package_name,fqv[122]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[123],module,F45968package_nicknames,fqv[124]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[125],module,F45971package_use_list,fqv[126]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[127],module,F45974package_used_by_list,fqv[128]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[129],module,F45977packagep,fqv[130]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[131],module,F45980use_package,fqv[132]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[133],module,F45983unuse_package,fqv[134]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[135],module,F45986make_package,fqv[136]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[137],module,F48123,fqv[138]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[139],module,F45990rename_package,fqv[140]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[141],module,F45993shadow,fqv[142]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[143],module,F45996import,fqv[144]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[145],module,F45999symbol_string,fqv[146]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[147],module,F46002unintern,fqv[148]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[149],module,F46004package_stats,fqv[150]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<5; i++) ftab[i]=fcallx;
}
