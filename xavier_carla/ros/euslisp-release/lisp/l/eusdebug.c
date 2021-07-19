/* ./eusdebug.c :  entry=eusdebug */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "eusdebug.h"
#pragma init (register_eusdebug)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___eusdebug();
extern pointer build_quote_vector();
static int register_eusdebug()
  { add_module_initializer("___eusdebug", ___eusdebug);}

static pointer F34554warning_message();
static pointer F34558warn();
static pointer F34561describe();
static pointer F34564describe_list();
static pointer F34568apropos();
static pointer F34571apropos_list();
static pointer F34575dump_string();
static pointer F34579break();
static pointer F34582setbreak();
static pointer F34585unbreak();
static pointer F34589btrace();
static pointer F34593eval_dynamic();
static pointer F34596step_hook();
static pointer F34601tracex();
static pointer F34604trace1();
static pointer F34610inspect1();
static pointer F34613time_func();
static pointer F34615list_symbols();
static pointer F34617functions();
static pointer F34619special_variables();
static pointer F34621global_variables();
static pointer F34623variables();
static pointer F34625constants();
static pointer F34627methods();
static pointer F34629method_list();
static pointer F34631y_or_n_p();
static pointer F34633yes_or_no_p();
static pointer F34635bell();
static pointer F34637check_methods();
static pointer F34639pfuncs();
static pointer F34641class_hierarchy();
static pointer F34643classdef();
static pointer F34645classdefs();
static pointer F34647remote_error();
static pointer F34649reval();
static pointer F34651install_remote_function();
static pointer F34653open_server();

/*assert*/
static pointer F34713(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT34717;}
	local[0]= fqv[0];
ENT34717:
ENT34716:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-2);
	local[2]= fqv[1];
	local[3]= fqv[2];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[3];
	local[5]= fqv[4];
	local[6]= local[0];
	local[7]= local[1];
	local[8]= NIL;
	ctx->vsp=local+9;
	w=(pointer)APPEND(ctx,2,local+7); /*append*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[5];
	local[6]= fqv[4];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[6];
	local[7]= fqv[7];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[0]= w;
BLK34714:
	ctx->vsp=local; return(local[0]);}

/*warning-message*/
static pointer F34554warning_message(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST34791:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= loadglobal(fqv[4]);
	local[2]= fqv[8];
	local[3]= makeint(27);
	local[4]= argv[0];
	local[5]= makeint(48);
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,4,local+1); /*format*/
	local[1]= (pointer)get_sym_func(fqv[3]);
	local[2]= loadglobal(fqv[4]);
	local[3]= argv[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[1]= loadglobal(fqv[4]);
	local[2]= fqv[9];
	local[3]= makeint(27);
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= loadglobal(fqv[4]);
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,1,local+1); /*finish-output*/
	local[0]= w;
BLK34789:
	ctx->vsp=local; return(local[0]);}

/*warn*/
static pointer F34558warn(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST34835:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= (pointer)get_sym_func(fqv[3]);
	local[2]= loadglobal(fqv[4]);
	local[3]= argv[0];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[1]= loadglobal(fqv[4]);
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,1,local+1); /*finish-output*/
	if (loadglobal(fqv[10])==NIL) goto IF34858;
	local[1]= fqv[11];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[6]); /*reploop*/
	local[1]= w;
	goto IF34859;
IF34858:
	local[1]= NIL;
IF34859:
	w = local[1];
	local[0]= w;
BLK34833:
	ctx->vsp=local; return(local[0]);}

/*describe*/
static pointer F34561describe(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT34875;}
	local[0]= loadglobal(fqv[12]);
ENT34875:
	if (n>=3) { local[1]=(argv[2]); goto ENT34874;}
	local[1]= NIL;
ENT34874:
	w = local[1];
	ctx->vsp=local+1;
	bindspecial(ctx,fqv[13],w);
	if (n>=4) { local[4]=(argv[3]); goto ENT34873;}
	local[4]= NIL;
ENT34873:
	w = local[4];
	ctx->vsp=local+4;
	bindspecial(ctx,fqv[14],w);
ENT34872:
	if (n>4) maerror();
	w = argv[0];
	if (!isnum(w)) goto IF34902;
	local[7]= argv[0];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)PRINT(ctx,2,local+7); /*print*/
	w = NIL;
	ctx->vsp=local+7;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK34870;
	goto IF34903;
IF34902:
	local[7]= NIL;
IF34903:
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)GETCLASS(ctx,1,local+7); /*class*/
	local[7]= w;
	local[8]= NIL;
	local[9]= makeint(0);
	local[10]= makeint(0);
	local[8] = local[7]->c.obj.iv[4];
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(pointer)LENGTH(ctx,1,local+11); /*length*/
	local[9] = w;
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)VECTORP(ctx,1,local+11); /*vectorp*/
	if (w==NIL) goto IF34960;
	local[11]= argv[0];
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(*ftab[1])(ctx,2,local+11,&ftab[1],fqv[15]); /*pprint*/
	local[11]= w;
	goto IF34961;
IF34960:
	local[11]= makeint(0);
	local[12]= local[9];
WHL34996:
	local[13]= local[11];
	w = local[12];
	if ((eusinteger_t)local[13] >= (eusinteger_t)w) goto WHX34997;
	local[13]= local[0];
	local[14]= fqv[16];
	local[15]= local[8];
	{ register eusinteger_t i=intval(local[11]);
	  w=(local[15]->c.vec.v[i]);}
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)XFORMAT(ctx,3,local+13); /*format*/
	local[13]= local[8];
	{ register eusinteger_t i=intval(local[11]);
	  w=(local[13]->c.vec.v[i]);}
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)PRNTSIZE(ctx,1,local+13); /*print-size*/
	local[10] = w;
	local[13]= local[10];
	local[14]= makeint(20);
	ctx->vsp=local+15;
	w=(pointer)GREATERP(ctx,2,local+13); /*>*/
	if (w==NIL) goto IF35028;
	local[10] = makeint(5);
	local[13]= local[0];
	ctx->vsp=local+14;
	w=(pointer)TERPRI(ctx,1,local+13); /*terpri*/
	local[13]= w;
	goto IF35029;
IF35028:
	local[13]= NIL;
IF35029:
	if (loadglobal(fqv[13])==NIL) goto IF35047;
	local[13]= argv[0];
	local[14]= local[7];
	local[15]= local[11];
	ctx->vsp=local+16;
	w=(pointer)SLOT(ctx,3,local+13); /*slot*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)PRINT(ctx,1,local+13); /*print*/
	local[13]= w;
	goto IF35048;
IF35047:
	local[13]= argv[0];
	local[14]= local[7];
	local[15]= local[11];
	ctx->vsp=local+16;
	w=(pointer)SLOT(ctx,3,local+13); /*slot*/
	local[13]= w;
	local[14]= local[0];
	local[15]= local[10];
	ctx->vsp=local+16;
	w=(pointer)ADD1(ctx,1,local+15); /*1+*/
	local[15]= w;
	local[16]= makeint(78);
	ctx->vsp=local+17;
	w=(*ftab[1])(ctx,4,local+13,&ftab[1],fqv[15]); /*pprint*/
	local[13]= w;
IF35048:
	local[13]= local[11];
	ctx->vsp=local+14;
	w=(pointer)ADD1(ctx,1,local+13); /*1+*/
	local[11] = w;
	goto WHL34996;
WHX34997:
	local[13]= NIL;
BLK34998:
	w = NIL;
	local[11]= w;
IF34961:
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)FINOUT(ctx,1,local+11); /*finish-output*/
	local[7]= w;
	ctx->vsp=local+8;
	unbindx(ctx,2);
	w = local[7];
	local[0]= w;
BLK34870:
	ctx->vsp=local; return(local[0]);}

/*describe-list*/
static pointer F34564describe_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT35093;}
	local[0]= loadglobal(fqv[12]);
ENT35093:
ENT35092:
	if (n>2) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,FLET35121,env,argv,local);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)STREAMP(ctx,1,local+3); /*streamp*/
	if (w!=NIL) goto IF35125;
	local[3]= local[0];
	local[4]= fqv[17];
	local[5]= fqv[18];
	local[6]= fqv[19];
	local[7]= fqv[20];
	local[8]= fqv[21];
	local[9]= fqv[22];
	ctx->vsp=local+10;
	w=(*ftab[2])(ctx,7,local+3,&ftab[2],fqv[23]); /*open*/
	local[1] = w;
	local[3]= local[1];
	goto IF35126;
IF35125:
	local[3]= NIL;
IF35126:
	local[3]= argv[0];
	w = local[2];
	ctx->vsp=local+4;
	w=FLET35121(ctx,1,local+3,w);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)STREAMP(ctx,1,local+3); /*streamp*/
	if (w!=NIL) goto IF35161;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)CLOSE(ctx,1,local+3); /*close*/
	local[3]= w;
	goto IF35162;
IF35161:
	local[3]= NIL;
IF35162:
	w = local[3];
	local[0]= w;
BLK35090:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET35121(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON35185;
	local[0]= NIL;
	local[1]= argv[0];
WHL35210:
	if (local[1]==NIL) goto WHX35211;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	w = env->c.clo.env2[2];
	ctx->vsp=local+3;
	w=FLET35121(ctx,1,local+2,w);
	goto WHL35210;
WHX35211:
	local[2]= NIL;
BLK35212:
	w = NIL;
	local[0]= w;
	goto CON35183;
CON35185:
	local[0]= env->c.clo.env2[1];
	local[1]= fqv[24];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0];
	local[1]= env->c.clo.env2[1];
	ctx->vsp=local+2;
	w=(pointer)F34561describe(ctx,2,local+0); /*describe*/
	local[0]= env->c.clo.env2[1];
	ctx->vsp=local+1;
	w=(pointer)TERPRI(ctx,1,local+0); /*terpri*/
	local[0]= env->c.clo.env2[1];
	ctx->vsp=local+1;
	w=(pointer)TERPRI(ctx,1,local+0); /*terpri*/
	local[0]= w;
	goto CON35183;
CON35266:
	local[0]= NIL;
CON35183:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*apropos*/
static pointer F34568apropos(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT35293;}
	local[0]= NIL;
ENT35293:
ENT35292:
	if (n>2) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[25]); /*string*/
	argv[0] = w;
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,FLET35319,env,argv,local);
	if (local[0]==NIL) goto CON35325;
	local[2]= NIL;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)FINDPACKAGE(ctx,1,local+3); /*find-package*/
	local[3]= w;
	local[4]= makeint(0);
	local[5]= *(ovafptr(local[3],fqv[26]));
	local[6]= local[5];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
WHL35361:
	local[7]= local[4];
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto WHX35362;
	local[7]= local[5];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[2] = w;
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[4] = w;
	w = local[2];
	if (!issymbol(w)) goto IF35391;
	local[7]= argv[0];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(*ftab[3])(ctx,1,local+8,&ftab[3],fqv[25]); /*string*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[4])(ctx,2,local+7,&ftab[4],fqv[27]); /*substringp*/
	if (w==NIL) goto IF35401;
	local[7]= local[2];
	w = local[1];
	ctx->vsp=local+8;
	w=FLET35319(ctx,1,local+7,w);
	local[7]= w;
	goto IF35402;
IF35401:
	local[7]= NIL;
IF35402:
	goto IF35392;
IF35391:
	local[7]= NIL;
IF35392:
	goto WHL35361;
WHX35362:
	local[7]= NIL;
BLK35363:
	w = NIL;
	local[2]= w;
	goto CON35323;
CON35325:
	local[2]= NIL;
	ctx->vsp=local+3;
	w=(pointer)ALLPACKAGES(ctx,0,local+3); /*list-all-packages*/
	local[3]= w;
WHL35446:
	if (local[3]==NIL) goto WHX35447;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= NIL;
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)FINDPACKAGE(ctx,1,local+5); /*find-package*/
	local[5]= w;
	local[6]= makeint(0);
	local[7]= *(ovafptr(local[5],fqv[26]));
	local[8]= local[7];
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
WHL35525:
	local[9]= local[6];
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)LESSP(ctx,2,local+9); /*<*/
	if (w==NIL) goto WHX35526;
	local[9]= local[7];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[4] = w;
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	local[6] = w;
	w = local[4];
	if (!issymbol(w)) goto IF35555;
	local[9]= argv[0];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(*ftab[3])(ctx,1,local+10,&ftab[3],fqv[25]); /*string*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[4])(ctx,2,local+9,&ftab[4],fqv[27]); /*substringp*/
	if (w==NIL) goto IF35565;
	local[9]= local[4];
	w = local[1];
	ctx->vsp=local+10;
	w=FLET35319(ctx,1,local+9,w);
	local[9]= w;
	goto IF35566;
IF35565:
	local[9]= NIL;
IF35566:
	goto IF35556;
IF35555:
	local[9]= NIL;
IF35556:
	goto WHL35525;
WHX35526:
	local[9]= NIL;
BLK35527:
	w = NIL;
	goto WHL35446;
WHX35447:
	local[4]= NIL;
BLK35448:
	w = NIL;
	local[2]= w;
	goto CON35323;
CON35423:
	local[2]= NIL;
CON35323:
	w = NIL;
	local[0]= w;
BLK35290:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET35319(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= T;
	local[1]= fqv[28];
	local[2]= argv[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)FBOUNDP(ctx,1,local+3); /*fboundp*/
	if (w==NIL) goto IF35604;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[5])(ctx,1,local+3,&ftab[5],fqv[29]); /*special-form-p*/
	if (w==NIL) goto IF35612;
	local[3]= fqv[30];
	goto IF35613;
IF35612:
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,1,local+3,&ftab[6],fqv[31]); /*macro-function*/
	if (w==NIL) goto IF35621;
	local[3]= fqv[32];
	goto IF35622;
IF35621:
	local[3]= fqv[33];
IF35622:
IF35613:
	goto IF35605;
IF35604:
	local[3]= fqv[34];
IF35605:
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)BOUNDP(ctx,1,local+4); /*boundp*/
	if (w==NIL) goto IF35630;
	local[4]= argv[0];
	local[5]= fqv[35];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[4];
	if (fqv[36]!=local[5]) goto IF35655;
	local[5]= fqv[37];
	goto IF35656;
IF35655:
	local[5]= local[4];
	if (fqv[38]!=local[5]) goto IF35663;
	local[5]= fqv[39];
	goto IF35664;
IF35663:
	local[5]= local[4];
	if (fqv[40]!=local[5]) goto IF35671;
	local[5]= fqv[41];
	goto IF35672;
IF35671:
	if (T==NIL) goto IF35679;
	local[5]= fqv[42];
	goto IF35680;
IF35679:
	local[5]= NIL;
IF35680:
IF35672:
IF35664:
IF35656:
	w = local[5];
	local[4]= w;
	goto IF35631;
IF35630:
	local[4]= fqv[43];
IF35631:
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)BOUNDP(ctx,1,local+5); /*boundp*/
	if (w==NIL) goto IF35685;
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)SYMBNDVALUE(ctx,1,local+5); /*symbol-bound-value*/
	local[5]= w;
	goto IF35686;
IF35685:
	local[5]= fqv[44];
IF35686:
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,6,local+0); /*format*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*apropos-list*/
static pointer F34571apropos_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT35702;}
	local[0]= NIL;
ENT35702:
ENT35701:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[25]); /*string*/
	argv[0] = w;
	if (local[0]==NIL) goto CON35736;
	local[2]= NIL;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)FINDPACKAGE(ctx,1,local+3); /*find-package*/
	local[3]= w;
	local[4]= makeint(0);
	local[5]= *(ovafptr(local[3],fqv[26]));
	local[6]= local[5];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
WHL35772:
	local[7]= local[4];
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto WHX35773;
	local[7]= local[5];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[2] = w;
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[4] = w;
	w = local[2];
	if (!issymbol(w)) goto IF35802;
	local[7]= argv[0];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(*ftab[3])(ctx,1,local+8,&ftab[3],fqv[25]); /*string*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[4])(ctx,2,local+7,&ftab[4],fqv[27]); /*substringp*/
	if (w==NIL) goto IF35812;
	local[7]= local[2];
	w = local[1];
	ctx->vsp=local+8;
	local[1] = cons(ctx,local[7],w);
	local[7]= local[1];
	goto IF35813;
IF35812:
	local[7]= NIL;
IF35813:
	goto IF35803;
IF35802:
	local[7]= NIL;
IF35803:
	goto WHL35772;
WHX35773:
	local[7]= NIL;
BLK35774:
	w = NIL;
	local[2]= w;
	goto CON35734;
CON35736:
	local[2]= NIL;
	ctx->vsp=local+3;
	w=(pointer)ALLPACKAGES(ctx,0,local+3); /*list-all-packages*/
	local[3]= w;
WHL35861:
	if (local[3]==NIL) goto WHX35862;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= NIL;
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)FINDPACKAGE(ctx,1,local+5); /*find-package*/
	local[5]= w;
	local[6]= makeint(0);
	local[7]= *(ovafptr(local[5],fqv[26]));
	local[8]= local[7];
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
WHL35940:
	local[9]= local[6];
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)LESSP(ctx,2,local+9); /*<*/
	if (w==NIL) goto WHX35941;
	local[9]= local[7];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[4] = w;
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	local[6] = w;
	w = local[4];
	if (!issymbol(w)) goto IF35970;
	local[9]= argv[0];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(*ftab[3])(ctx,1,local+10,&ftab[3],fqv[25]); /*string*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[4])(ctx,2,local+9,&ftab[4],fqv[27]); /*substringp*/
	if (w==NIL) goto IF35980;
	local[9]= local[4];
	w = local[1];
	ctx->vsp=local+10;
	local[1] = cons(ctx,local[9],w);
	local[9]= local[1];
	goto IF35981;
IF35980:
	local[9]= NIL;
IF35981:
	goto IF35971;
IF35970:
	local[9]= NIL;
IF35971:
	goto WHL35940;
WHX35941:
	local[9]= NIL;
BLK35942:
	w = NIL;
	goto WHL35861;
WHX35862:
	local[4]= NIL;
BLK35863:
	w = NIL;
	local[2]= w;
	goto CON35734;
CON35838:
	local[2]= NIL;
CON35734:
	w = local[1];
	local[0]= w;
BLK35699:
	ctx->vsp=local; return(local[0]);}

/*dump-string*/
static pointer F34575dump_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT36022;}
	local[0]= loadglobal(fqv[12]);
ENT36022:
	if (n>=3) { local[1]=(argv[2]); goto ENT36021;}
	local[1]= fqv[45];
ENT36021:
	if (n>=4) { local[2]=(argv[3]); goto ENT36020;}
	local[2]= makeint(16);
ENT36020:
ENT36019:
	if (n>4) maerror();
	local[3]= makeint(0);
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
	local[5]= NIL;
	local[6]= local[1];
	local[7]= fqv[46];
	local[8]= fqv[47];
	local[9]= (pointer)get_sym_func(fqv[48]);
	ctx->vsp=local+10;
	w=(*ftab[7])(ctx,4,local+6,&ftab[7],fqv[49]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.car;
WHL36088:
	local[6]= local[3];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,2,local+6); /*<*/
	if (w==NIL) goto WHX36089;
	local[6]= local[3];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)MOD(ctx,2,local+6); /*mod*/
	local[6]= w;
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)NUMEQUAL(ctx,2,local+6); /*=*/
	if (w==NIL) goto IF36097;
	local[6]= local[0];
	local[7]= fqv[50];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	goto IF36098;
IF36097:
	local[6]= NIL;
IF36098:
	local[6]= local[5];
	local[7]= local[6];
	if (fqv[51]!=local[7]) goto IF36124;
	local[7]= local[0];
	local[8]= fqv[52];
	local[9]= argv[0];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= w;
	goto IF36125;
IF36124:
	local[7]= local[6];
	if (fqv[53]!=local[7]) goto IF36139;
	local[7]= local[0];
	local[8]= fqv[54];
	local[9]= makeint(65535);
	local[10]= argv[0];
	local[11]= local[3];
	local[12]= fqv[55];
	ctx->vsp=local+13;
	w=(pointer)PEEK(ctx,3,local+10); /*system:peek*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LOGAND(ctx,2,local+9); /*logand*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= w;
	goto IF36140;
IF36139:
	local[7]= local[6];
	if (fqv[56]!=local[7]) goto IF36161;
	local[7]= local[0];
	local[8]= fqv[57];
	local[9]= argv[0];
	local[10]= local[3];
	local[11]= fqv[58];
	ctx->vsp=local+12;
	w=(pointer)PEEK(ctx,3,local+9); /*system:peek*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= w;
	goto IF36162;
IF36161:
	local[7]= NIL;
IF36162:
IF36140:
IF36125:
	w = local[7];
	local[6]= local[3];
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[3] = w;
	local[6]= local[3];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)MOD(ctx,2,local+6); /*mod*/
	local[6]= w;
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)NUMEQUAL(ctx,2,local+6); /*=*/
	if (w==NIL) goto IF36193;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)TERPRI(ctx,1,local+6); /*terpri*/
	local[6]= w;
	goto IF36194;
IF36193:
	local[6]= NIL;
IF36194:
	goto WHL36088;
WHX36089:
	local[6]= NIL;
BLK36090:
	w = local[6];
	local[0]= w;
BLK36017:
	ctx->vsp=local; return(local[0]);}

/*break*/
static pointer F34579break(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT36212;}
	local[0]= NIL;
	local[1]= fqv[59];
	local[2]= loadglobal(fqv[60]);
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
ENT36212:
ENT36211:
	if (n>1) maerror();
	local[1]= loadglobal(fqv[60]);
	ctx->vsp=local+2;
	w=(pointer)ADD1(ctx,1,local+1); /*1+*/
	local[1]= w;
	w = local[1];
	ctx->vsp=local+2;
	bindspecial(ctx,fqv[60],w);
	{jmp_buf jb;
	w = loadglobal(fqv[60]);
	ctx->vsp=local+5;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT36246;}
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(*ftab[0])(ctx,1,local+11,&ftab[0],fqv[6]); /*reploop*/
CAT36246:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[5]= w;
	ctx->vsp=local+6;
	unbindx(ctx,1);
	w = local[5];
	local[0]= w;
BLK36209:
	ctx->vsp=local; return(local[0]);}

/*setbreak*/
static pointer F34582setbreak(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FBOUNDP(ctx,1,local+0); /*fboundp*/
	if (w!=NIL) goto IF36270;
	local[0]= fqv[61];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto IF36271;
IF36270:
	local[0]= NIL;
IF36271:
	local[0]= argv[0];
	local[1]= fqv[62];
	ctx->vsp=local+2;
	w=(pointer)GETPROP(ctx,2,local+0); /*get*/
	if (w!=NIL) goto IF36285;
	local[0]= argv[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	local[2]= fqv[62];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= argv[0];
	local[1]= fqv[63];
	local[2]= fqv[64];
	local[3]= fqv[65];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[66];
	local[4]= fqv[67];
	local[5]= fqv[68];
	local[6]= fqv[69];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[69];
	local[8]= fqv[62];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[65];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[70];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*setfunc*/
	local[0]= argv[0];
	goto IF36286;
IF36285:
	local[0]= NIL;
IF36286:
	w = local[0];
	local[0]= w;
BLK36259:
	ctx->vsp=local; return(local[0]);}

/*unbreak*/
static pointer F34585unbreak(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[62];
	ctx->vsp=local+2;
	w=(pointer)GETPROP(ctx,2,local+0); /*get*/
	if (w==NIL) goto IF36392;
	local[0]= argv[0];
	local[1]= argv[0];
	local[2]= fqv[62];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*setfunc*/
	local[0]= argv[0];
	local[1]= NIL;
	local[2]= fqv[62];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= w;
	goto IF36393;
IF36392:
	local[0]= NIL;
IF36393:
	w = local[0];
	local[0]= w;
BLK36381:
	ctx->vsp=local; return(local[0]);}

/*timing*/
static pointer F36425(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST36428:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[71];
	local[2]= fqv[72];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[73];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[74];
	local[5]= fqv[75];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[76];
	local[6]= fqv[77];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[78];
	local[7]= fqv[79];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[1];
	local[4]= fqv[80];
	local[5]= fqv[72];
	local[6]= fqv[81];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[82];
	local[6]= fqv[72];
	local[7]= fqv[83];
	local[8]= fqv[72];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	w = local[0];
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[82];
	local[5]= fqv[78];
	local[6]= fqv[75];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[1];
	local[6]= fqv[80];
	local[7]= fqv[73];
	local[8]= fqv[84];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[82];
	local[8]= fqv[73];
	local[9]= fqv[83];
	local[10]= fqv[73];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[82];
	local[7]= fqv[76];
	local[8]= fqv[85];
	local[9]= fqv[75];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[9]= w;
	local[10]= fqv[78];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[3];
	local[8]= fqv[86];
	local[9]= fqv[87];
	local[10]= fqv[88];
	local[11]= fqv[89];
	local[12]= fqv[88];
	local[13]= fqv[90];
	local[14]= fqv[91];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[85];
	local[14]= fqv[78];
	local[15]= fqv[74];
	local[16]= fqv[76];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK36426:
	ctx->vsp=local; return(local[0]);}

/*btrace*/
static pointer F34589btrace(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT36711;}
	local[0]= makeint(10);
ENT36711:
ENT36710:
	if (n>1) maerror();
	local[1]= (pointer)get_sym_func(fqv[92]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)BKTRACE(ctx,1,local+2); /*system::bktrace*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	ctx->vsp=local+3;
	w=(pointer)MAPC(ctx,2,local+1); /*mapc*/
	w = T;
	local[0]= w;
BLK36708:
	ctx->vsp=local; return(local[0]);}

/*eval-dynamic*/
static pointer F34593eval_dynamic(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT36743;}
	ctx->vsp=local+0;
	w=(pointer)LISTBINDINGS(ctx,0,local+0); /*system:list-all-bindings*/
	local[0]= w;
ENT36743:
ENT36742:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= local[0];
WHL36785:
	if (local[3]==NIL) goto WHX36786;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= argv[0];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car!=local[4]) goto IF36834;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK36740;
	goto IF36835;
IF36834:
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)VECTORP(ctx,1,local+4); /*vectorp*/
	if (w==NIL) goto IF36853;
	local[4]= argv[0];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(*ftab[8])(ctx,2,local+4,&ftab[8],fqv[93]); /*position*/
	local[1] = w;
	if (local[1]==NIL) goto IF36853;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
	ctx->vsp=local+6;
	w=(pointer)GETCLASS(ctx,1,local+5); /*class*/
	local[5]= w;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SLOT(ctx,3,local+4); /*slot*/
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK36740;
	goto IF36854;
IF36853:
	local[4]= NIL;
IF36854:
IF36835:
	goto WHL36785;
WHX36786:
	local[4]= NIL;
BLK36787:
	w = NIL;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)BOUNDP(ctx,1,local+2); /*boundp*/
	if (w==NIL) goto IF36903;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SYMVALUE(ctx,1,local+2); /*symbol-value*/
	local[2]= w;
	goto IF36904;
IF36903:
	local[2]= fqv[94];
IF36904:
	w = local[2];
	local[0]= w;
BLK36740:
	ctx->vsp=local; return(local[0]);}

/*step-hook*/
static pointer F34596step_hook(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= T;
	local[3]= makeint(10);
	local[4]= makeint(5);
	w = local[4];
	ctx->vsp=local+5;
	bindspecial(ctx,fqv[13],w);
	w = local[3];
	ctx->vsp=local+8;
	bindspecial(ctx,fqv[14],w);
	local[11]= loadglobal(fqv[95]);
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[11]= w;
	storeglobal(fqv[95],w);
	local[11]= loadglobal(fqv[95]);
	ctx->vsp=local+12;
	w=(*ftab[9])(ctx,1,local+11,&ftab[9],fqv[96]); /*spaces*/
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)PRINT(ctx,1,local+11); /*print*/
WHL36978:
	if (local[2]==NIL) goto WHX36979;
	local[11]= T;
	local[12]= fqv[97];
	local[13]= loadglobal(fqv[95]);
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,3,local+11); /*format*/
	ctx->vsp=local+11;
	w=(pointer)FINOUT(ctx,0,local+11); /*finish-output*/
	local[11]= loadglobal(fqv[98]);
	w = local[11];
	ctx->vsp=local+12;
	bindspecial(ctx,fqv[99],w);
	ctx->vsp=local+15;
	w=(pointer)READ(ctx,0,local+15); /*read*/
	local[15]= w;
	ctx->vsp=local+16;
	unbindx(ctx,1);
	w = local[15];
	local[0] = w;
	local[11]= local[0];
	local[12]= local[11];
	w = fqv[100];
	if (memq(local[12],w)==NIL) goto IF37030;
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(*ftab[1])(ctx,1,local+12,&ftab[1],fqv[15]); /*pprint*/
	local[12]= w;
	goto IF37031;
IF37030:
	local[12]= local[11];
	w = fqv[101];
	if (memq(local[12],w)==NIL) goto IF37044;
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)PRINT(ctx,1,local+12); /*print*/
	local[12]= w;
	goto IF37045;
IF37044:
	local[12]= local[11];
	w = fqv[102];
	if (memq(local[12],w)==NIL) goto IF37058;
	local[12]= argv[0];
	local[13]= argv[1];
	ctx->vsp=local+14;
	w=(pointer)EVAL(ctx,2,local+12); /*eval*/
	local[1] = w;
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)PRINT(ctx,1,local+12); /*print*/
	local[12]= T;
	local[13]= fqv[103];
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)XFORMAT(ctx,3,local+12); /*format*/
	local[2] = NIL;
	local[12]= local[2];
	goto IF37059;
IF37058:
	local[12]= local[11];
	w = fqv[104];
	if (memq(local[12],w)==NIL) goto IF37095;
	local[12]= argv[0];
	local[13]= (pointer)get_sym_func(fqv[66]);
	local[14]= argv[1];
	ctx->vsp=local+15;
	w=(pointer)EVALHOOK(ctx,3,local+12); /*evalhook*/
	local[1] = w;
	local[12]= T;
	local[13]= fqv[105];
	local[14]= argv[0];
	local[15]= local[1];
	ctx->vsp=local+16;
	w=(pointer)XFORMAT(ctx,4,local+12); /*format*/
	local[2] = NIL;
	local[12]= local[2];
	goto IF37096;
IF37095:
	local[12]= local[11];
	w = fqv[106];
	if (memq(local[12],w)==NIL) goto IF37131;
	local[12]= fqv[107];
	w = fqv[108];
	ctx->vsp=local+13;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	goto IF37132;
IF37131:
	local[12]= local[11];
	w = fqv[109];
	if (memq(local[12],w)==NIL) goto IF37149;
	local[12]= T;
	local[13]= fqv[110];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,2,local+12); /*format*/
	local[12]= T;
	local[13]= fqv[111];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,2,local+12); /*format*/
	local[12]= T;
	local[13]= fqv[112];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,2,local+12); /*format*/
	local[12]= T;
	local[13]= fqv[113];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,2,local+12); /*format*/
	local[12]= T;
	local[13]= fqv[114];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,2,local+12); /*format*/
	local[12]= w;
	goto IF37150;
IF37149:
	local[12]= local[11];
	if (fqv[115]!=local[12]) goto IF37177;
	ctx->vsp=local+12;
	w=(pointer)READ(ctx,0,local+12); /*read*/
	local[0] = w;
	w = local[0];
	if (!issymbol(w)) goto CON37198;
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)F34593eval_dynamic(ctx,1,local+12); /*eval-dynamic*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)PRINT(ctx,1,local+12); /*print*/
	local[12]= w;
	goto CON37196;
CON37198:
	{jmp_buf jb;
	w = fqv[116];
	ctx->vsp=local+12;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT37212;}
	local[18]= fqv[117];
	w = local[18];
	ctx->vsp=local+19;
	bindspecial(ctx,fqv[118],w);
	local[22]= local[0];
	ctx->vsp=local+23;
	w=(pointer)EVAL(ctx,1,local+22); /*eval*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)PRINT(ctx,1,local+22); /*print*/
	local[22]= w;
	ctx->vsp=local+23;
	unbindx(ctx,1);
	w = local[22];
CAT37212:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[12]= w;
	goto CON37196;
CON37208:
	local[12]= NIL;
CON37196:
	goto IF37178;
IF37177:
	if (T==NIL) goto IF37241;
	local[12]= T;
	local[13]= fqv[119];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,2,local+12); /*format*/
	local[12]= w;
	goto IF37242;
IF37241:
	local[12]= NIL;
IF37242:
IF37178:
IF37150:
IF37132:
IF37096:
IF37059:
IF37045:
IF37031:
	w = local[12];
	goto WHL36978;
WHX36979:
	local[11]= NIL;
BLK36980:
	local[11]= loadglobal(fqv[95]);
	ctx->vsp=local+12;
	w=(pointer)SUB1(ctx,1,local+11); /*1-*/
	local[11]= w;
	storeglobal(fqv[95],w);
	local[11]= local[1];
	ctx->vsp=local+12;
	unbindx(ctx,2);
	w = local[11];
	local[0]= w;
BLK36919:
	ctx->vsp=local; return(local[0]);}

/*step*/
static pointer F37263(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[120];
	local[1]= fqv[82];
	local[2]= fqv[95];
	local[3]= fqv[121];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[122];
	local[3]= fqv[69];
	local[4]= fqv[107];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[123];
	local[5]= fqv[69];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[124];
	local[7]= fqv[69];
	local[8]= fqv[66];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK37264:
	ctx->vsp=local; return(local[0]);}

/*tracex*/
static pointer F34601tracex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= loadglobal(fqv[95]);
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[2]= w;
	w = local[2];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[95],w);
	local[6]= T;
	local[7]= fqv[125];
	local[8]= loadglobal(fqv[95]);
	local[9]= argv[0];
	local[10]= argv[1];
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,5,local+6); /*format*/
	local[6]= argv[0];
	local[7]= fqv[126];
	ctx->vsp=local+8;
	w=(pointer)GETPROP(ctx,2,local+6); /*get*/
	local[6]= w;
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,2,local+6); /*apply*/
	local[0] = w;
	local[6]= T;
	local[7]= fqv[127];
	local[8]= loadglobal(fqv[95]);
	local[9]= local[0];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,5,local+6); /*format*/
	local[6]= loadglobal(fqv[95]);
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)EQUAL(ctx,2,local+6); /*equal*/
	local[6]= w;
	if (w==NIL) goto AND37406;
	ctx->vsp=local+6;
	w=(pointer)TERPRI(ctx,0,local+6); /*terpri*/
	local[6]= w;
AND37406:
	local[6]= local[0];
	ctx->vsp=local+7;
	unbindx(ctx,1);
	w = local[6];
	local[0]= w;
BLK37348:
	ctx->vsp=local; return(local[0]);}

/*trace1*/
static pointer F34604trace1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)SYMFUNC(ctx,1,local+0); /*symbol-function*/
	local[0]= w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,1,local+1,&ftab[10],fqv[128]); /*functionp*/
	if (w!=NIL) goto IF37442;
	w = NIL;
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK37421;
	goto IF37443;
IF37442:
	local[1]= NIL;
IF37443:
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[126];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= argv[0];
	local[2]= fqv[63];
	local[3]= fqv[129];
	local[4]= fqv[130];
	local[5]= fqv[69];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[131];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,3,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SETFUNC(ctx,2,local+1); /*setfunc*/
	w = argv[0];
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK37421;
	w = local[1];
	local[0]= w;
BLK37421:
	ctx->vsp=local; return(local[0]);}

/*trace*/
static pointer F37498(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST37501:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= fqv[132];
	local[2]= fqv[133];
	local[3]= fqv[69];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[134];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[135];
	local[4]= fqv[48];
	local[5]= fqv[133];
	local[6]= fqv[134];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[136];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[137];
	local[6]= fqv[138];
	local[7]= fqv[133];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[139];
	local[7]= fqv[140];
	local[8]= fqv[133];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[86];
	local[7]= fqv[141];
	local[8]= fqv[133];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[142];
	local[9]= fqv[133];
	local[10]= fqv[134];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK37499:
	ctx->vsp=local; return(local[0]);}

/*untrace*/
static pointer F37632(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST37635:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	if (local[0]!=NIL) goto IF37645;
	local[0] = loadglobal(fqv[134]);
	local[1]= local[0];
	goto IF37646;
IF37645:
	local[1]= NIL;
IF37646:
	local[1]= fqv[132];
	local[2]= fqv[133];
	local[3]= fqv[69];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[134];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[135];
	local[4]= fqv[48];
	local[5]= fqv[133];
	local[6]= fqv[134];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[143];
	local[6]= fqv[124];
	local[7]= fqv[133];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[68];
	local[8]= fqv[133];
	local[9]= fqv[69];
	local[10]= fqv[126];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[82];
	local[7]= fqv[134];
	local[8]= fqv[144];
	local[9]= fqv[133];
	local[10]= fqv[134];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
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
	local[0]= w;
BLK37633:
	ctx->vsp=local; return(local[0]);}

/*inspect1*/
static pointer F34610inspect1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT37782;}
	local[0]= NIL;
ENT37782:
ENT37781:
	if (n>2) maerror();
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,FLET37798,env,argv,local);
	local[2]= local[0];
	w = local[1];
	ctx->vsp=local+3;
	w=FLET37798(ctx,1,local+2,w);
	local[2]= w;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)GETCLASS(ctx,1,local+3); /*class*/
	local[3]= *(ovafptr(w,fqv[145]));
	local[4]= NIL;
TAG37830:
	if (NIL==NIL) goto IF37835;
	w = NIL;
	ctx->vsp=local+5;
	local[2]=w;
	goto BLK37804;
	goto IF37836;
IF37835:
	local[5]= NIL;
IF37836:
	w = local[2];
	if (!issymbol(w)) goto IF37856;
	local[5]= local[2]->c.obj.iv[4];
	{ register eusinteger_t i=intval(makeint(0));
	  w=makeint(local[5]->c.str.chars[i]);}
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)CHUPCASE(ctx,1,local+5); /*char-upcase*/
	local[5]= w;
	goto IF37857;
IF37856:
	local[5]= local[2];
IF37857:
	local[6]= local[5];
	if (fqv[146]!=local[6]) goto IF37876;
	local[6]= argv[0];
	local[7]= loadglobal(fqv[147]);
	local[8]= makeint(2);
	local[9]= makeint(3);
	ctx->vsp=local+10;
	w=(pointer)F34561describe(ctx,4,local+6); /*describe*/
	local[6]= w;
	goto IF37877;
IF37876:
	local[6]= local[5];
	if (fqv[148]!=local[6]) goto IF37889;
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,1,local+6,&ftab[1],fqv[15]); /*pprint*/
	local[6]= w;
	goto IF37890;
IF37889:
	local[6]= local[5];
	if (fqv[149]!=local[6]) goto IF37900;
	ctx->vsp=local+6;
	w=(pointer)READ(ctx,0,local+6); /*read*/
	local[2] = w;
	local[6]= loadglobal(fqv[25]);
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(*ftab[3])(ctx,1,local+7,&ftab[3],fqv[25]); /*string*/
	local[7]= w;
	local[8]= fqv[150];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(*ftab[3])(ctx,1,local+9,&ftab[3],fqv[25]); /*string*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)CONCATENATE(ctx,4,local+6); /*concatenate*/
	local[4] = w;
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(*ftab[11])(ctx,2,local+6,&ftab[11],fqv[151]); /*find*/
	if (w!=NIL) goto OR37937;
	w = local[2];
	if (!isint(w)) goto AND37946;
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)ARRAYP(ctx,1,local+6); /*arrayp*/
	if (w!=NIL) goto OR37951;
	w = argv[0];
	if (iscons(w)) goto OR37951;
	goto AND37946;
OR37951:
	local[6]= local[2];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,2,local+6); /*<*/
	if (w==NIL) goto AND37946;
	goto OR37937;
AND37946:
	goto IF37935;
OR37937:
	w = local[2];
	if (!isint(w)) goto IF37969;
	local[6]= argv[0];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	goto IF37970;
IF37969:
	local[6]= argv[0];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)GETCLASS(ctx,1,local+7); /*class*/
	local[7]= w;
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)SLOT(ctx,3,local+6); /*slot*/
	local[6]= w;
IF37970:
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)F34610inspect1(ctx,2,local+6); /*inspect1*/
	local[6]= w;
	goto IF37936;
IF37935:
	local[6]= makeint(4);
	local[7]= fqv[152];
	ctx->vsp=local+8;
	w=(pointer)F34554warning_message(ctx,2,local+6); /*warning-message*/
	local[6]= w;
IF37936:
	goto IF37901;
IF37900:
	local[6]= local[5];
	if (fqv[153]!=local[6]) goto IF37990;
	w = NIL;
	ctx->vsp=local+6;
	local[0]=w;
	goto BLK37779;
	goto IF37991;
IF37990:
	local[6]= local[5];
	if (fqv[154]!=local[6]) goto IF38001;
	local[6]= fqv[155];
	w = NIL;
	ctx->vsp=local+7;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	goto IF38002;
IF38001:
	local[6]= local[5];
	if (fqv[156]!=local[6]) goto IF38014;
	ctx->vsp=local+6;
	w=(pointer)READ(ctx,0,local+6); /*read*/
	local[2] = w;
	ctx->vsp=local+6;
	w=(pointer)READ(ctx,0,local+6); /*read*/
	local[4] = w;
	w = local[2];
	if (!isint(w)) goto IF38037;
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)ARRAYP(ctx,1,local+6); /*arrayp*/
	if (w!=NIL) goto OR38043;
	w = argv[0];
	if (iscons(w)) goto OR38043;
	goto IF38037;
OR38043:
	local[6]= local[2];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,2,local+6); /*<*/
	if (w==NIL) goto IF38037;
	local[6]= argv[0];
	local[7]= local[2];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SETELT(ctx,3,local+6); /*setelt*/
	local[6]= w;
	goto IF38038;
IF38037:
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(*ftab[11])(ctx,2,local+6,&ftab[11],fqv[151]); /*find*/
	if (w==NIL) goto IF38066;
	local[6]= argv[0];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)GETCLASS(ctx,1,local+7); /*class*/
	local[7]= w;
	local[8]= local[2];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)SETSLOT(ctx,4,local+6); /*setslot*/
	local[6]= w;
	goto IF38067;
IF38066:
	local[6]= NIL;
IF38067:
IF38038:
	goto IF38015;
IF38014:
	local[6]= local[5];
	w = fqv[157];
	if (memq(local[6],w)==NIL) goto IF38084;
	local[6]= T;
	local[7]= fqv[158];
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,2,local+6); /*format*/
	local[6]= w;
	goto IF38085;
IF38084:
	if (T==NIL) goto IF38097;
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(*ftab[11])(ctx,2,local+6,&ftab[11],fqv[151]); /*find*/
	if (w==NIL) goto CON38104;
	local[6]= argv[0];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)GETCLASS(ctx,1,local+7); /*class*/
	local[7]= w;
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)SLOT(ctx,3,local+6); /*slot*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)F34561describe(ctx,1,local+6); /*describe*/
	local[6]= w;
	goto CON38102;
CON38104:
	w = local[2];
	if (!isint(w)) goto CON38121;
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)ARRAYP(ctx,1,local+6); /*arrayp*/
	if (w!=NIL) goto OR38126;
	w = argv[0];
	if (iscons(w)) goto OR38126;
	goto CON38121;
OR38126:
	local[6]= local[2];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,2,local+6); /*<*/
	if (w==NIL) goto CON38121;
	local[6]= argv[0];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)PRINT(ctx,1,local+6); /*print*/
	local[6]= w;
	goto CON38102;
CON38121:
	{jmp_buf jb;
	w = fqv[159];
	ctx->vsp=local+6;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT38153;}
	local[12]= fqv[160];
	w = local[12];
	ctx->vsp=local+13;
	bindspecial(ctx,fqv[118],w);
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)EVAL(ctx,1,local+16); /*eval*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)PRINT(ctx,1,local+16); /*print*/
	local[16]= w;
	ctx->vsp=local+17;
	unbindx(ctx,1);
	w = local[16];
CAT38153:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[6]= w;
	goto CON38102;
CON38149:
	local[6]= NIL;
CON38102:
	goto IF38098;
IF38097:
	local[6]= NIL;
IF38098:
IF38085:
IF38015:
IF38002:
IF37991:
IF37901:
IF37890:
IF37877:
	w = local[6];
	local[5]= local[0];
	w = local[1];
	ctx->vsp=local+6;
	w=FLET37798(ctx,1,local+5,w);
	local[2] = w;
	local[4] = NIL;
	ctx->vsp=local+5;
	goto TAG37830;
	w = NIL;
	local[2]= w;
BLK37804:
	w = local[2];
	local[0]= w;
BLK37779:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET37798(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= T;
	local[1]= fqv[161];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= T;
	ctx->vsp=local+1;
	w=(pointer)FINOUT(ctx,1,local+0); /*finish-output*/
	local[0]= loadglobal(fqv[162]);
	local[1]= NIL;
	local[2]= fqv[163];
	ctx->vsp=local+3;
	w=(pointer)READ(ctx,3,local+0); /*read*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*inspect*/
static pointer F38226(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[122];
	local[1]= fqv[69];
	local[2]= fqv[155];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[164];
	local[3]= argv[0];
	local[4]= fqv[3];
	local[5]= fqv[136];
	local[6]= fqv[165];
	local[7]= fqv[69];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK38227:
	ctx->vsp=local; return(local[0]);}

/*time-func*/
static pointer F34613time_func(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[63];
	local[1]= fqv[64];
	local[2]= fqv[65];
	local[3]= fqv[166];
	local[4]= fqv[167];
	local[5]= fqv[168];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[169];
	local[3]= fqv[68];
	local[4]= fqv[69];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[170];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[82];
	local[4]= fqv[167];
	local[5]= fqv[171];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	local[5]= w;
	local[6]= fqv[168];
	local[7]= fqv[172];
	local[8]= fqv[68];
	local[9]= fqv[69];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[173];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[65];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[169];
	local[5]= fqv[68];
	local[6]= fqv[69];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[174];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[85];
	local[7]= fqv[171];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	local[8]= fqv[167];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[168];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK38290:
	ctx->vsp=local; return(local[0]);}

/*time*/
static pointer F38463(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT38467;}
	local[0]= NIL;
ENT38467:
ENT38466:
	if (n>2) maerror();
	local[1]= fqv[120];
	local[2]= fqv[135];
	local[3]= fqv[68];
	local[4]= fqv[69];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[173];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[175];
	local[5]= fqv[176];
	local[6]= fqv[69];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[69];
	local[8]= fqv[177];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[69];
	local[9]= fqv[178];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[68];
	local[10]= fqv[69];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[170];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[69];
	local[11]= fqv[179];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[69];
	local[12]= fqv[180];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[69];
	local[13]= fqv[181];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[89];
	local[14]= fqv[182];
	local[15]= fqv[68];
	local[16]= fqv[69];
	local[17]= argv[0];
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,1,local+17); /*list*/
	ctx->vsp=local+17;
	local[16]= cons(ctx,local[16],w);
	local[17]= fqv[174];
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,1,local+17); /*list*/
	ctx->vsp=local+17;
	w = cons(ctx,local[16],w);
	ctx->vsp=local+16;
	local[15]= cons(ctx,local[15],w);
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	local[14]= fqv[69];
	local[15]= fqv[183];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[184];
	local[7]= local[0];
	local[8]= fqv[143];
	local[9]= fqv[68];
	local[10]= fqv[69];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[170];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[185];
	local[11]= fqv[68];
	local[12]= fqv[69];
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[174];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[186];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[187];
	local[5]= fqv[2];
	local[6]= fqv[138];
	local[7]= fqv[69];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[31];
	local[7]= fqv[69];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[188];
	local[6]= fqv[189];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[86];
	local[6]= fqv[71];
	local[7]= fqv[190];
	local[8]= fqv[124];
	local[9]= fqv[69];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	local[8]= fqv[143];
	local[9]= fqv[68];
	local[10]= fqv[69];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[170];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[191];
	local[11]= fqv[68];
	local[12]= fqv[69];
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[174];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[192];
	local[13]= fqv[68];
	local[14]= fqv[69];
	local[15]= argv[0];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	local[15]= fqv[173];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	local[14]= fqv[190];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[193];
	local[10]= fqv[69];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[194];
	local[12]= fqv[69];
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[142];
	local[11]= fqv[69];
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[195];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[176];
	local[12]= fqv[69];
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[69];
	local[14]= fqv[177];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	local[14]= fqv[69];
	local[15]= fqv[196];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	local[15]= fqv[69];
	local[16]= fqv[197];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	local[15]= cons(ctx,local[15],w);
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK38464:
	ctx->vsp=local; return(local[0]);}

/*untime*/
static pointer F39001(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[120];
	local[1]= fqv[198];
	local[2]= fqv[68];
	local[3]= fqv[69];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[173];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[82];
	local[4]= fqv[195];
	local[5]= fqv[144];
	local[6]= fqv[69];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[195];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[193];
	local[5]= fqv[69];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[68];
	local[7]= fqv[69];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[173];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[69];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK39002:
	ctx->vsp=local; return(local[0]);}

/*list-symbols*/
static pointer F34615list_symbols(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[1];
WHL39161:
	if (local[2]==NIL) goto WHX39162;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= NIL;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)FINDPACKAGE(ctx,1,local+4); /*find-package*/
	local[4]= w;
	local[5]= makeint(0);
	local[6]= *(ovafptr(local[4],fqv[26]));
	local[7]= local[6];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
WHL39240:
	local[8]= local[5];
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)LESSP(ctx,2,local+8); /*<*/
	if (w==NIL) goto WHX39241;
	local[8]= local[6];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[3] = w;
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[5] = w;
	w = local[3];
	if (!issymbol(w)) goto IF39270;
	local[8]= argv[0];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)FUNCALL(ctx,2,local+8); /*funcall*/
	if (w==NIL) goto IF39279;
	local[8]= local[3];
	w = local[0];
	ctx->vsp=local+9;
	local[0] = cons(ctx,local[8],w);
	local[8]= local[0];
	goto IF39280;
IF39279:
	local[8]= NIL;
IF39280:
	goto IF39271;
IF39270:
	local[8]= NIL;
IF39271:
	goto WHL39240;
WHX39241:
	local[8]= NIL;
BLK39242:
	w = NIL;
	goto WHL39161;
WHX39162:
	local[3]= NIL;
BLK39163:
	w = NIL;
	local[1]= local[0];
	local[2]= (pointer)get_sym_func(fqv[199]);
	ctx->vsp=local+3;
	w=(pointer)SORT(ctx,2,local+1); /*sort*/
	local[0]= w;
BLK39123:
	ctx->vsp=local; return(local[0]);}

/*functions*/
static pointer F34617functions(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT39317;}
	local[0]= fqv[200];
ENT39317:
ENT39316:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-1);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[25]); /*string*/
	local[0] = w;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO39340,env,argv,local);
	if (local[1]==NIL) goto IF39343;
	local[3]= local[1];
	goto IF39344;
IF39343:
	ctx->vsp=local+3;
	w=(pointer)ALLPACKAGES(ctx,0,local+3); /*list-all-packages*/
	local[3]= w;
IF39344:
	ctx->vsp=local+4;
	w=(pointer)F34615list_symbols(ctx,2,local+2); /*list-symbols*/
	local[0]= w;
BLK39314:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO39340(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FBOUNDP(ctx,1,local+0); /*fboundp*/
	local[0]= w;
	if (w==NIL) goto AND39363;
	local[0]= env->c.clo.env2[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[25]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[27]); /*substringp*/
	local[0]= w;
AND39363:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*special-variables*/
static pointer F34619special_variables(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT39382;}
	local[0]= fqv[201];
ENT39382:
ENT39381:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-1);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[25]); /*string*/
	local[0] = w;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO39405,env,argv,local);
	if (local[1]==NIL) goto IF39408;
	local[3]= local[1];
	goto IF39409;
IF39408:
	ctx->vsp=local+3;
	w=(pointer)ALLPACKAGES(ctx,0,local+3); /*list-all-packages*/
	local[3]= w;
IF39409:
	ctx->vsp=local+4;
	w=(pointer)F34615list_symbols(ctx,2,local+2); /*list-symbols*/
	local[0]= w;
BLK39379:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO39405(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	local[0]= w;
	if (w==NIL) goto AND39428;
	local[0]= argv[0];
	local[1]= fqv[35];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(3);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	local[0]= w;
	if (w==NIL) goto AND39428;
	local[0]= env->c.clo.env2[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[25]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[27]); /*substringp*/
	local[0]= w;
AND39428:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*global-variables*/
static pointer F34621global_variables(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT39456;}
	local[0]= fqv[202];
ENT39456:
ENT39455:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-1);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[25]); /*string*/
	local[0] = w;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO39479,env,argv,local);
	if (local[1]==NIL) goto IF39482;
	local[3]= local[1];
	goto IF39483;
IF39482:
	ctx->vsp=local+3;
	w=(pointer)ALLPACKAGES(ctx,0,local+3); /*list-all-packages*/
	local[3]= w;
IF39483:
	ctx->vsp=local+4;
	w=(pointer)F34615list_symbols(ctx,2,local+2); /*list-symbols*/
	local[0]= w;
BLK39453:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO39479(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	local[0]= w;
	if (w==NIL) goto AND39502;
	local[0]= argv[0];
	local[1]= fqv[35];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	local[0]= w;
	if (w==NIL) goto AND39502;
	local[0]= env->c.clo.env2[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[25]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[27]); /*substringp*/
	local[0]= w;
AND39502:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*variables*/
static pointer F34623variables(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT39530;}
	local[0]= fqv[203];
ENT39530:
ENT39529:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-1);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[25]); /*string*/
	local[0] = w;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO39553,env,argv,local);
	if (local[1]==NIL) goto IF39556;
	local[3]= local[1];
	goto IF39557;
IF39556:
	ctx->vsp=local+3;
	w=(pointer)ALLPACKAGES(ctx,0,local+3); /*list-all-packages*/
	local[3]= w;
IF39557:
	ctx->vsp=local+4;
	w=(pointer)F34615list_symbols(ctx,2,local+2); /*list-symbols*/
	local[0]= w;
BLK39527:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO39553(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	local[0]= w;
	if (w==NIL) goto AND39576;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[12])(ctx,1,local+0,&ftab[12],fqv[204]); /*constantp*/
	local[0]= ((w)==NIL?T:NIL);
	if (local[0]==NIL) goto AND39576;
	local[0]= env->c.clo.env2[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[25]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[27]); /*substringp*/
	local[0]= w;
AND39576:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*constants*/
static pointer F34625constants(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT39603;}
	local[0]= fqv[205];
ENT39603:
ENT39602:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO39617,env,argv,local);
	if (local[1]==NIL) goto IF39620;
	local[3]= local[1];
	goto IF39621;
IF39620:
	ctx->vsp=local+3;
	w=(pointer)ALLPACKAGES(ctx,0,local+3); /*list-all-packages*/
	local[3]= w;
IF39621:
	ctx->vsp=local+4;
	w=(pointer)F34615list_symbols(ctx,2,local+2); /*list-symbols*/
	local[0]= w;
BLK39600:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO39617(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[12])(ctx,1,local+0,&ftab[12],fqv[204]); /*constantp*/
	local[0]= w;
	if (w==NIL) goto AND39640;
	local[0]= env->c.clo.env2[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[25]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[27]); /*substringp*/
	local[0]= w;
AND39640:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*methods*/
static pointer F34627methods(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT39660;}
	local[0]= fqv[206];
ENT39660:
	if (n>=2) { local[1]=(argv[1]); goto ENT39659;}
	local[1]= fqv[207];
	ctx->vsp=local+2;
	w=(pointer)FINDPACKAGE(ctx,1,local+1); /*find-package*/
	local[1]= w;
ENT39659:
ENT39658:
	if (n>2) maerror();
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO39679,env,argv,local);
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO39683,env,argv,local);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)F34615list_symbols(ctx,2,local+3); /*list-symbols*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[0]= w;
BLK39656:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO39679(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= argv[0];
	local[2]= fqv[208];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[1]= w;
	local[2]= fqv[209];
	ctx->vsp=local+3;
	w=(*ftab[13])(ctx,2,local+1,&ftab[13],fqv[210]); /*send-all*/
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO39683(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env2[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[25]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[27]); /*substringp*/
	local[0]= w;
	if (w==NIL) goto AND39725;
	local[0]= argv[0];
	local[1]= fqv[208];
	ctx->vsp=local+2;
	w=(pointer)GETPROP(ctx,2,local+0); /*get*/
	local[0]= w;
AND39725:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*method-list*/
static pointer F34629method_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT39746;}
	local[0]= T;
ENT39746:
	if (n>=2) { local[1]=(argv[1]); goto ENT39745;}
	local[1]= NIL;
ENT39745:
ENT39744:
	ctx->vsp=local+2;
	local[2]= minilist(ctx,&argv[n],n-2);
	if (local[2]!=NIL) goto IF39764;
	ctx->vsp=local+3;
	w=(pointer)LISTALLCLASSES(ctx,0,local+3); /*system:list-all-classes*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	local[2] = w;
	local[3]= local[2];
	goto IF39765;
IF39764:
	local[3]= NIL;
IF39765:
	local[3]= NIL;
	local[4]= local[2];
WHL39800:
	if (local[4]==NIL) goto WHX39801;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[0];
	local[8]= fqv[211];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(*ftab[14])(ctx,1,local+9,&ftab[14],fqv[212]); /*metaclass-name*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= (pointer)get_sym_func(fqv[213]);
	local[8]= local[3]->c.obj.iv[7];
	ctx->vsp=local+9;
	w=(pointer)MAPCAR(ctx,2,local+7); /*mapcar*/
	local[6] = w;
	local[7]= NIL;
	local[8]= local[6];
	local[9]= (pointer)get_sym_func(fqv[199]);
	ctx->vsp=local+10;
	w=(pointer)SORT(ctx,2,local+8); /*sort*/
	local[8]= w;
WHL39906:
	if (local[8]==NIL) goto WHX39907;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[3];
	local[10]= local[7];
	local[11]= fqv[214];
	ctx->vsp=local+12;
	w=(*ftab[15])(ctx,2,local+10,&ftab[15],fqv[215]); /*documentation*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[7])(ctx,2,local+9,&ftab[7],fqv[49]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	if (local[5]==NIL) goto IF39975;
	local[9]= local[5];
	local[10]= makeint(0);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,2,local+9); /*aref*/
	local[9]= w;
	local[10]= makeint(40);
	ctx->vsp=local+11;
	w=(pointer)EQUAL(ctx,2,local+9); /*equal*/
	if (w==NIL) goto IF39975;
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(*ftab[16])(ctx,1,local+9,&ftab[16],fqv[216]); /*read-from-string*/
	local[5] = w;
	w = local[5];
	if (!iscons(w)) goto IF40003;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	if (fqv[217]!=local[9]) goto IF40012;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[9];
	local[9]= w;
	goto IF40013;
IF40012:
	local[9]= NIL;
IF40013:
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	if (fqv[218]!=local[9]) goto IF40060;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[9];
	local[9]= w;
	goto IF40061;
IF40060:
	local[9]= NIL;
IF40061:
	goto IF40004;
IF40003:
	local[9]= NIL;
IF40004:
	goto IF39976;
IF39975:
	local[9]= NIL;
IF39976:
	local[9]= local[0];
	local[10]= fqv[219];
	local[11]= makeint(9);
	local[12]= local[7];
	if (local[1]==NIL) goto IF40111;
	if (local[5]==NIL) goto IF40111;
	local[13]= local[5];
	goto IF40112;
IF40111:
	local[13]= fqv[220];
IF40112:
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,5,local+9); /*format*/
	goto WHL39906;
WHX39907:
	local[9]= NIL;
BLK39908:
	w = NIL;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)TERPRI(ctx,1,local+7); /*terpri*/
	goto WHL39800;
WHX39801:
	local[5]= NIL;
BLK39802:
	w = NIL;
	local[0]= w;
BLK39742:
	ctx->vsp=local; return(local[0]);}

/*more*/
static pointer F40135(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= fqv[221];
	ctx->vsp=local+2;
	w=(pointer)GETPID(ctx,0,local+2); /*unix:getpid*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	local[1]= NIL;
	local[2]= fqv[222];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	local[2]= fqv[223];
	local[3]= fqv[120];
	local[4]= fqv[224];
	local[5]= fqv[12];
	local[6]= local[0];
	local[7]= fqv[17];
	local[8]= fqv[18];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[225];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[226];
	local[5]= local[0];
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
	local[0]= w;
BLK40136:
	ctx->vsp=local; return(local[0]);}

/*y-or-n-p*/
static pointer F34631y_or_n_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT40228;}
	local[0]= NIL;
ENT40228:
ENT40227:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-1);
	local[2]= NIL;
	local[3]= NIL;
TAG40245:
	if (local[0]==NIL) goto IF40251;
	local[4]= (pointer)get_sym_func(fqv[3]);
	local[5]= T;
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,4,local+4); /*apply*/
	local[4]= w;
	goto IF40252;
IF40251:
	local[4]= NIL;
IF40252:
	local[4]= T;
	local[5]= fqv[227];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,2,local+4); /*format*/
	local[4]= T;
	ctx->vsp=local+5;
	w=(pointer)FINOUT(ctx,1,local+4); /*finish-output*/
	local[4]= T;
	ctx->vsp=local+5;
	w=(pointer)READLINE(ctx,1,local+4); /*read-line*/
	local[3] = w;
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
	if (makeint(0)!=local[4]) goto IF40281;
	ctx->vsp=local+4;
	goto TAG40245;
	goto IF40282;
IF40281:
	local[4]= NIL;
IF40282:
	local[4]= local[3];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)CHUPCASE(ctx,1,local+4); /*char-upcase*/
	local[4]= w;
	local[5]= local[4];
	if (fqv[228]!=local[5]) goto IF40309;
	w = T;
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK40225;
	goto IF40310;
IF40309:
	local[5]= local[4];
	if (fqv[229]!=local[5]) goto IF40320;
	w = NIL;
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK40225;
	goto IF40321;
IF40320:
	if (T==NIL) goto IF40331;
	ctx->vsp=local+5;
	goto TAG40245;
	goto IF40332;
IF40331:
	local[5]= NIL;
IF40332:
IF40321:
IF40310:
	w = local[5];
	w = NIL;
	local[0]= w;
BLK40225:
	ctx->vsp=local; return(local[0]);}

/*yes-or-no-p*/
static pointer F34633yes_or_no_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT40344;}
	local[0]= NIL;
ENT40344:
ENT40343:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-1);
	local[2]= NIL;
	local[3]= NIL;
TAG40361:
	if (local[0]==NIL) goto IF40367;
	local[4]= (pointer)get_sym_func(fqv[3]);
	local[5]= T;
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,4,local+4); /*apply*/
	local[4]= w;
	goto IF40368;
IF40367:
	local[4]= NIL;
IF40368:
	local[4]= T;
	local[5]= fqv[230];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,2,local+4); /*format*/
	local[4]= T;
	ctx->vsp=local+5;
	w=(pointer)FINOUT(ctx,1,local+4); /*finish-output*/
	local[4]= T;
	ctx->vsp=local+5;
	w=(pointer)READLINE(ctx,1,local+4); /*read-line*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[17])(ctx,1,local+4,&ftab[17],fqv[231]); /*string-upcase*/
	local[3] = w;
	local[4]= local[3];
	local[5]= fqv[232];
	ctx->vsp=local+6;
	w=(*ftab[18])(ctx,2,local+4,&ftab[18],fqv[233]); /*string=*/
	if (w==NIL) goto CON40402;
	w = T;
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK40341;
	goto CON40400;
CON40402:
	local[4]= local[3];
	local[5]= fqv[234];
	ctx->vsp=local+6;
	w=(*ftab[18])(ctx,2,local+4,&ftab[18],fqv[233]); /*string=*/
	if (w==NIL) goto CON40413;
	w = NIL;
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK40341;
	goto CON40400;
CON40413:
	ctx->vsp=local+4;
	goto TAG40361;
	goto CON40400;
CON40423:
	local[4]= NIL;
CON40400:
	w = NIL;
	local[0]= w;
BLK40341:
	ctx->vsp=local; return(local[0]);}

/*bell*/
static pointer F34635bell(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT40434;}
	local[0]= T;
ENT40434:
ENT40433:
	if (n>2) maerror();
	local[1]= makeint(0);
	local[2]= argv[0];
WHL40471:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX40472;
	local[3]= local[0];
	local[4]= fqv[235];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,2,local+3); /*format*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL40471;
WHX40472:
	local[3]= NIL;
BLK40473:
	w = NIL;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,1,local+1); /*finish-output*/
	local[0]= w;
BLK40431:
	ctx->vsp=local; return(local[0]);}

/*:type*/
static pointer M40512compiled_code_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= local[0];
	if (fqv[236]!=local[1]) goto IF40538;
	local[1]= fqv[237];
	goto IF40539;
IF40538:
	local[1]= local[0];
	if (fqv[238]!=local[1]) goto IF40548;
	local[1]= fqv[239];
	goto IF40549;
IF40548:
	local[1]= local[0];
	if (fqv[240]!=local[1]) goto IF40558;
	local[1]= fqv[241];
	goto IF40559;
IF40558:
	local[1]= local[0];
	if (fqv[242]!=local[1]) goto IF40568;
	local[1]= fqv[243];
	goto IF40569;
IF40568:
	local[1]= NIL;
IF40569:
IF40559:
IF40549:
IF40539:
	w = local[1];
	local[0]= w;
BLK40513:
	ctx->vsp=local; return(local[0]);}

/*check-methods*/
static pointer F34637check_methods(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	ctx->vsp=local+0;
	w=(pointer)LISTALLCLASSES(ctx,0,local+0); /*system:list-all-classes*/
	local[0]= w;
	local[1]= (pointer)get_sym_func(fqv[244]);
	local[2]= local[0];
	local[3]= fqv[245];
	ctx->vsp=local+4;
	w=(*ftab[13])(ctx,2,local+2,&ftab[13],fqv[210]); /*send-all*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[1]= w;
	local[2]= (pointer)get_sym_func(fqv[246]);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	local[3]= (pointer)get_sym_func(fqv[213]);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(*ftab[19])(ctx,1,local+4,&ftab[19],fqv[247]); /*remove-duplicates*/
	local[4]= w;
	local[5]= T;
	local[6]= fqv[248];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	local[9]= w;
	local[10]= (pointer)get_sym_func(fqv[249]);
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(*ftab[20])(ctx,2,local+10,&ftab[20],fqv[250]); /*count-if*/
	local[10]= w;
	local[11]= (pointer)get_sym_func(fqv[249]);
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(*ftab[21])(ctx,2,local+11,&ftab[21],fqv[251]); /*count-if-not*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,7,local+5); /*format*/
	local[0]= w;
BLK40581:
	ctx->vsp=local; return(local[0]);}

/*pfuncs*/
static pointer F34639pfuncs(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT40659;}
	ctx->vsp=local+0;
	w=(pointer)F34617functions(ctx,0,local+0); /*functions*/
	local[0]= w;
ENT40659:
	if (n>=3) { local[1]=(argv[2]); goto ENT40658;}
	local[1]= NIL;
ENT40658:
ENT40657:
	if (n>3) maerror();
	local[2]= argv[0];
	local[3]= fqv[17];
	local[4]= fqv[18];
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,3,local+2,&ftab[2],fqv[23]); /*open*/
	local[2]= w;
	ctx->vsp=local+3;
	w = makeclosure(codevec,quotevec,UWP40697,env,argv,local);
	local[3]=(pointer)(ctx->protfp); local[4]=w;
	ctx->protfp=(struct protectframe *)(local+3);
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[0];
WHL40730:
	if (local[7]==NIL) goto WHX40731;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)SYMFUNC(ctx,1,local+8); /*symbol-function*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[22])(ctx,1,local+8,&ftab[22],fqv[249]); /*compiled-function-p*/
	if (w!=NIL) goto OR40782;
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(*ftab[6])(ctx,1,local+8,&ftab[6],fqv[31]); /*macro-function*/
	if (w==NIL) goto OR40782;
	goto IF40780;
OR40782:
	local[8]= local[2];
	local[9]= fqv[252];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(*ftab[23])(ctx,1,local+10,&ftab[23],fqv[253]); /*symbol-name*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[24])(ctx,1,local+10,&ftab[24],fqv[254]); /*string-downcase*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,3,local+8); /*format*/
	local[8]= makeint(40);
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)PRNTSIZE(ctx,1,local+9); /*print-size*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(*ftab[9])(ctx,2,local+8,&ftab[9],fqv[96]); /*spaces*/
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(*ftab[25])(ctx,1,local+8,&ftab[25],fqv[255]); /*symbol-package*/
	local[5] = w;
	local[8]= local[2];
	local[9]= fqv[256];
	local[10]= local[5];
	local[11]= fqv[257];
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	if (w==NIL) goto IF40836;
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(*ftab[26])(ctx,1,local+10,&ftab[26],fqv[258]); /*package-name*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[24])(ctx,1,local+10,&ftab[24],fqv[254]); /*string-downcase*/
	local[10]= w;
	goto IF40837;
IF40836:
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(*ftab[26])(ctx,1,local+10,&ftab[26],fqv[258]); /*package-name*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[17])(ctx,1,local+10,&ftab[17],fqv[231]); /*string-upcase*/
	local[10]= w;
IF40837:
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)SYMFUNC(ctx,1,local+11); /*symbol-function*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[22])(ctx,1,local+11,&ftab[22],fqv[249]); /*compiled-function-p*/
	if (w==NIL) goto IF40858;
	local[11]= fqv[259];
	goto IF40859;
IF40858:
	local[11]= fqv[260];
IF40859:
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(*ftab[6])(ctx,1,local+12,&ftab[6],fqv[31]); /*macro-function*/
	if (w==NIL) goto IF40868;
	local[12]= fqv[261];
	goto IF40869;
IF40868:
	local[12]= fqv[262];
IF40869:
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,5,local+8); /*format*/
	if (local[1]==NIL) goto IF40878;
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(*ftab[15])(ctx,1,local+8,&ftab[15],fqv[215]); /*documentation*/
	if (w==NIL) goto IF40878;
	local[8]= local[2];
	local[9]= fqv[263];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(*ftab[15])(ctx,1,local+10,&ftab[15],fqv[215]); /*documentation*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,3,local+8); /*format*/
	local[8]= w;
	goto IF40879;
IF40878:
	local[8]= NIL;
IF40879:
	goto IF40781;
IF40780:
	local[8]= NIL;
IF40781:
	goto WHL40730;
WHX40731:
	local[8]= NIL;
BLK40732:
	w = NIL;
	ctx->vsp=local+5;
	UWP40697(ctx,0,local+5,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK40655:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP40697(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[2];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*class-hierarchy*/
static pointer F34641class_hierarchy(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT40919;}
	local[0]= loadglobal(fqv[264]);
ENT40919:
	if (n>=2) { local[1]=(argv[1]); goto ENT40918;}
	local[1]= T;
ENT40918:
	if (n>=3) { local[2]=(argv[2]); goto ENT40917;}
	local[2]= NIL;
ENT40917:
ENT40916:
	if (n>3) maerror();
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,FLET40943,env,argv,local);
	local[4]= local[0];
	local[5]= fqv[265];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= makeint(0);
	w = local[3];
	ctx->vsp=local+6;
	w=FLET40943(ctx,2,local+4,w);
	local[0]= w;
BLK40914:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET40943(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	local[1]= argv[1];
	local[2]= env->c.clo.env2[1];
	ctx->vsp=local+3;
	w=(*ftab[9])(ctx,2,local+1,&ftab[9],fqv[96]); /*spaces*/
	local[1]= env->c.clo.env2[1];
	local[2]= fqv[266];
	local[3]= local[0];
	local[4]= fqv[209];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[24])(ctx,1,local+3,&ftab[24],fqv[254]); /*string-downcase*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	if (env->c.clo.env2[2]==NIL) goto IF41011;
	local[1]= local[0]->c.obj.iv[2];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[27])(ctx,1,local+2,&ftab[27],fqv[267]); /*metaclass-vars*/
	local[2]= w;
	local[3]= loadglobal(fqv[67]);
	ctx->vsp=local+4;
	w=(pointer)COERCE(ctx,2,local+2); /*coerce*/
	local[2]= w;
	if (local[1]==NIL) goto IF41040;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(*ftab[27])(ctx,1,local+3,&ftab[27],fqv[267]); /*metaclass-vars*/
	local[3]= w;
	local[4]= loadglobal(fqv[67]);
	ctx->vsp=local+5;
	w=(pointer)COERCE(ctx,2,local+3); /*coerce*/
	local[3]= w;
	goto IF41041;
IF41040:
	local[3]= NIL;
IF41041:
	local[4]= local[2];
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(*ftab[28])(ctx,2,local+4,&ftab[28],fqv[268]); /*set-difference*/
	local[2] = w;
	local[4]= (pointer)get_sym_func(fqv[254]);
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[2] = w;
	local[4]= env->c.clo.env2[1];
	local[5]= fqv[269];
	if (local[2]==NIL) goto IF41078;
	local[6]= local[2];
	goto IF41079;
IF41078:
	local[6]= fqv[270];
IF41079:
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[1]= w;
	goto IF41012;
IF41011:
	local[1]= env->c.clo.env2[1];
	ctx->vsp=local+2;
	w=(pointer)TERPRI(ctx,1,local+1); /*terpri*/
	local[1]= w;
IF41012:
	w = local[1];
	local[0]= NIL;
	local[1]= argv[0];
WHL41109:
	if (local[1]==NIL) goto WHX41110;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= argv[1];
	local[4]= makeint(3);
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	w = env->c.clo.env2[3];
	ctx->vsp=local+4;
	w=FLET40943(ctx,2,local+2,w);
	goto WHL41109;
WHX41110:
	local[2]= NIL;
BLK41111:
	w = NIL;
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*classdef*/
static pointer F34643classdef(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[271];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= fqv[272];
	local[4]= argv[0];
	local[5]= fqv[209];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= fqv[271];
	if (local[0]==NIL) goto IF41215;
	local[6]= local[0];
	local[7]= fqv[209];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	goto IF41216;
IF41215:
	local[6]= NIL;
IF41216:
	local[7]= fqv[273];
	local[8]= argv[0];
	local[9]= fqv[273];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= loadglobal(fqv[67]);
	ctx->vsp=local+10;
	w=(pointer)COERCE(ctx,2,local+8); /*coerce*/
	local[8]= w;
	if (local[0]==NIL) goto IF41241;
	local[9]= local[0];
	local[10]= fqv[273];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	goto IF41242;
IF41241:
	local[9]= NIL;
IF41242:
	local[10]= loadglobal(fqv[67]);
	ctx->vsp=local+11;
	w=(pointer)COERCE(ctx,2,local+9); /*coerce*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[28])(ctx,2,local+8,&ftab[28],fqv[268]); /*set-difference*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	local[0]= w;
BLK41173:
	ctx->vsp=local; return(local[0]);}

/*classdefs*/
static pointer F34645classdefs(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT41272;}
	local[0]= loadglobal(fqv[264]);
ENT41272:
	if (n>=2) { local[1]=(argv[1]); goto ENT41271;}
	local[1]= T;
ENT41271:
ENT41270:
	if (n>2) maerror();
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F34643classdef(ctx,1,local+2); /*classdef*/
	local[2]= w;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(*ftab[1])(ctx,2,local+2,&ftab[1],fqv[15]); /*pprint*/
	local[2]= NIL;
	local[3]= local[0];
	local[4]= fqv[274];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
WHL41317:
	if (local[3]==NIL) goto WHX41318;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)F34645classdefs(ctx,2,local+4); /*classdefs*/
	goto WHL41317;
WHX41318:
	local[4]= NIL;
BLK41319:
	w = NIL;
	local[0]= w;
BLK41268:
	ctx->vsp=local; return(local[0]);}

/*remote-error*/
static pointer F34647remote_error(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT41378;}
	local[0]= NIL;
ENT41378:
ENT41377:
	if (n>4) maerror();
	local[1]= loadglobal(fqv[4]);
	local[2]= fqv[275];
	local[3]= loadglobal(fqv[276]);
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,4,local+1); /*format*/
	if (local[0]==NIL) goto IF41403;
	local[1]= loadglobal(fqv[4]);
	local[2]= fqv[277];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	goto IF41404;
IF41403:
	local[1]= NIL;
IF41404:
	if (argv[2]==NIL) goto IF41414;
	local[1]= loadglobal(fqv[4]);
	local[2]= fqv[278];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	goto IF41415;
IF41414:
	local[1]= NIL;
IF41415:
	local[1]= loadglobal(fqv[4]);
	ctx->vsp=local+2;
	w=(pointer)TERPRI(ctx,1,local+1); /*terpri*/
	local[1]= fqv[279];
	w = NIL;
	ctx->vsp=local+2;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	w = local[1];
	local[0]= w;
BLK41375:
	ctx->vsp=local; return(local[0]);}

/*reval*/
static pointer F34649reval(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[280];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	w = local[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[162],w);
	local[3]= argv[0];
	local[4]= fqv[281];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	w = local[3];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[12],w);
	local[6]= loadglobal(fqv[12]);
	w = local[6];
	ctx->vsp=local+6;
	bindspecial(ctx,fqv[4],w);
	local[9]= fqv[282];
	w = local[9];
	ctx->vsp=local+9;
	bindspecial(ctx,fqv[118],w);
	{jmp_buf jb;
	w = fqv[279];
	ctx->vsp=local+12;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT41476;}
	local[18]= argv[0];
	ctx->vsp=local+19;
	w=(pointer)READ(ctx,1,local+18); /*read*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)EVAL(ctx,1,local+18); /*eval*/
	local[18]= w;
	local[19]= argv[0];
	ctx->vsp=local+20;
	w=(pointer)PRINT(ctx,2,local+18); /*print*/
CAT41476:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[12]= w;
	ctx->vsp=local+13;
	unbindx(ctx,4);
	w = local[12];
	local[0]= w;
BLK41435:
	ctx->vsp=local; return(local[0]);}

/*install-remote-function*/
static pointer F34651install_remote_function(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= T;
	local[1]= fqv[283];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= T;
	local[1]= fqv[284];
	local[2]= loadglobal(fqv[285]);
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[29])(ctx,1,local+0,&ftab[29],fqv[286]); /*make-server-socket-stream*/
	local[0]= w;
	local[1]= local[0];
	w = loadglobal(fqv[287]);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	storeglobal(fqv[287],local[1]);
	local[1]= local[0];
	local[2]= loadglobal(fqv[288]);
	local[3]= fqv[47];
	local[4]= NIL;
	local[5]= fqv[289];
	local[6]= NIL;
	local[7]= fqv[290];
	local[8]= NIL;
	ctx->vsp=local+9;
	w=(*ftab[30])(ctx,8,local+1,&ftab[30],fqv[48]); /*member*/
	if (w!=NIL) goto IF41548;
	local[1]= local[0];
	w = loadglobal(fqv[288]);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	storeglobal(fqv[288],local[1]);
	goto IF41549;
IF41548:
	local[1]= NIL;
IF41549:
	local[1]= makeint(29);
	local[2]= fqv[291];
	ctx->vsp=local+3;
	w=(pointer)SIGNAL(ctx,2,local+1); /*unix:signal*/
	w = local[0];
	if (!isint(w)) goto IF41582;
	local[1]= local[0];
	local[2]= makeint(4);
	local[3]= local[0];
	local[4]= makeint(3);
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)FCNTL(ctx,3,local+3); /*unix:fcntl*/
	local[3]= w;
	local[4]= makeint(8192);
	ctx->vsp=local+5;
	w=(pointer)LOGIOR(ctx,2,local+3); /*logior*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)FCNTL(ctx,3,local+1); /*unix:fcntl*/
	local[1]= local[0];
	local[2]= makeint(8);
	ctx->vsp=local+3;
	w=(pointer)GETPID(ctx,0,local+3); /*unix:getpid*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)FCNTL(ctx,3,local+1); /*unix:fcntl*/
	local[1]= w;
	goto IF41583;
IF41582:
	local[1]= local[0];
	local[2]= fqv[292];
	local[3]= T;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
IF41583:
	local[1]= loadglobal(fqv[293]);
	w = local[0];
	if (!isint(w)) goto IF41617;
	local[2]= local[0];
	goto IF41618;
IF41617:
	local[2]= local[0];
	local[3]= fqv[294];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
IF41618:
	local[3]= loadglobal(fqv[285]);
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,3,local+1); /*aset*/
	local[0]= w;
BLK41495:
	ctx->vsp=local; return(local[0]);}

/*open-server*/
static pointer F34653open_server(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT41637;}
	local[0]= makeint(2048);
ENT41637:
	if (n>=2) { local[1]=(argv[1]); goto ENT41636;}
	local[1]= (pointer)get_sym_func(fqv[279]);
ENT41636:
ENT41635:
	if (n>2) maerror();
	local[2]= fqv[295];
	local[3]= makeint(2);
	local[4]= fqv[296];
	ctx->vsp=local+5;
	w=(pointer)GETHOSTNAME(ctx,0,local+5); /*unix:gethostname*/
	local[5]= w;
	local[6]= fqv[297];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,6,local+2,&ftab[31],fqv[298]); /*make-socket-address*/
	local[2]= w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(*ftab[32])(ctx,1,local+3,&ftab[32],fqv[299]); /*make-socket-port*/
	local[3]= w;
	storeglobal(fqv[300],w);
	local[3]= loadglobal(fqv[300]);
	local[4]= loadglobal(fqv[301]);
	ctx->vsp=local+5;
	w=(pointer)DERIVEDP(ctx,2,local+3); /*derivedp*/
	if (w==NIL) goto CON41687;
	local[3]= fqv[302];
	ctx->vsp=local+4;
	w=(pointer)GETHOSTNAME(ctx,0,local+4); /*unix:gethostname*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)F34558warn(ctx,3,local+3); /*warn*/
	local[3]= w;
	goto CON41685;
CON41687:
	local[3]= loadglobal(fqv[300]);
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,1,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SYSERRLIST(ctx,1,local+3); /*unix:syserrlist*/
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK41633;
	goto CON41685;
CON41701:
	local[3]= NIL;
CON41685:
	local[3]= local[1];
	storeglobal(fqv[285],local[3]);
	local[3]= loadglobal(fqv[300]);
	local[4]= loadglobal(fqv[288]);
	local[5]= fqv[47];
	local[6]= NIL;
	local[7]= fqv[289];
	local[8]= NIL;
	local[9]= fqv[290];
	local[10]= NIL;
	ctx->vsp=local+11;
	w=(*ftab[30])(ctx,8,local+3,&ftab[30],fqv[48]); /*member*/
	if (w!=NIL) goto IF41730;
	local[3]= loadglobal(fqv[300]);
	w = loadglobal(fqv[288]);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	storeglobal(fqv[288],local[3]);
	goto IF41731;
IF41730:
	local[3]= NIL;
IF41731:
	local[3]= makeint(29);
	local[4]= fqv[291];
	ctx->vsp=local+5;
	w=(pointer)SIGNAL(ctx,2,local+3); /*unix:signal*/
	w = loadglobal(fqv[300]);
	if (!isint(w)) goto IF41762;
	local[3]= loadglobal(fqv[300]);
	local[4]= makeint(4);
	local[5]= loadglobal(fqv[300]);
	local[6]= makeint(3);
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)FCNTL(ctx,3,local+5); /*unix:fcntl*/
	local[5]= w;
	local[6]= makeint(8192);
	ctx->vsp=local+7;
	w=(pointer)LOGIOR(ctx,2,local+5); /*logior*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)FCNTL(ctx,3,local+3); /*unix:fcntl*/
	local[3]= loadglobal(fqv[300]);
	local[4]= makeint(8);
	ctx->vsp=local+5;
	w=(pointer)GETPID(ctx,0,local+5); /*unix:getpid*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)FCNTL(ctx,3,local+3); /*unix:fcntl*/
	local[3]= w;
	goto IF41763;
IF41762:
	local[3]= loadglobal(fqv[300]);
	local[4]= fqv[292];
	local[5]= T;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
IF41763:
	local[3]= loadglobal(fqv[293]);
	w = loadglobal(fqv[300]);
	if (!isint(w)) goto IF41796;
	local[4]= loadglobal(fqv[300]);
	goto IF41797;
IF41796:
	local[4]= loadglobal(fqv[300]);
	local[5]= fqv[294];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
IF41797:
	local[5]= fqv[303];
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,3,local+3); /*aset*/
	local[0]= w;
BLK41633:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___eusdebug(ctx,n,argv,env)
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
	local[0]= fqv[304];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF41818;
	local[0]= fqv[305];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[99],w);
	goto IF41819;
IF41818:
	local[0]= fqv[306];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF41819:
	local[0]= fqv[307];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compmacro(ctx,fqv[308],module,F34713,fqv[309]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[310],module,F34554warning_message,fqv[311]);
	local[0]= fqv[10];
	local[1]= fqv[35];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF41846;
	local[0]= fqv[10];
	local[1]= fqv[35];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[10];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF41869;
	local[0]= fqv[10];
	local[1]= fqv[312];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF41870;
IF41869:
	local[0]= NIL;
IF41870:
	local[0]= fqv[10];
	goto IF41847;
IF41846:
	local[0]= NIL;
IF41847:
	ctx->vsp=local+0;
	compfun(ctx,fqv[139],module,F34558warn,fqv[313]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[314],module,F34561describe,fqv[315]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[316],module,F34564describe_list,fqv[317]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[318],module,F34568apropos,fqv[319]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[320],module,F34571apropos_list,fqv[321]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[322],module,F34575dump_string,fqv[323]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[324],module,F34579break,fqv[325]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[326],module,F34582setbreak,fqv[327]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[328],module,F34585unbreak,fqv[329]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[330],module,F36425,fqv[331]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[332],module,F34589btrace,fqv[333]);
	local[0]= fqv[95];
	local[1]= fqv[35];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF41911;
	local[0]= fqv[95];
	local[1]= fqv[35];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[95];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF41934;
	local[0]= fqv[95];
	local[1]= fqv[312];
	local[2]= makeint(0);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF41935;
IF41934:
	local[0]= NIL;
IF41935:
	local[0]= fqv[95];
	goto IF41912;
IF41911:
	local[0]= NIL;
IF41912:
	ctx->vsp=local+0;
	compfun(ctx,fqv[334],module,F34593eval_dynamic,fqv[335]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[66],module,F34596step_hook,fqv[336]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[337],module,F37263,fqv[338]);
	local[0]= fqv[134];
	local[1]= fqv[35];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF41960;
	local[0]= fqv[134];
	local[1]= fqv[35];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[134];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF41983;
	local[0]= fqv[134];
	local[1]= fqv[312];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF41984;
IF41983:
	local[0]= NIL;
IF41984:
	local[0]= fqv[134];
	goto IF41961;
IF41960:
	local[0]= NIL;
IF41961:
	ctx->vsp=local+0;
	compfun(ctx,fqv[130],module,F34601tracex,fqv[339]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[141],module,F34604trace1,fqv[340]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[341],module,F37498,fqv[342]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[343],module,F37632,fqv[344]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[164],module,F34610inspect1,fqv[345]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[155],module,F38226,fqv[346]);
	local[0]= fqv[195];
	local[1]= fqv[35];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF42015;
	local[0]= fqv[195];
	local[1]= fqv[35];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[195];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF42038;
	local[0]= fqv[195];
	local[1]= fqv[312];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF42039;
IF42038:
	local[0]= NIL;
IF42039:
	local[0]= fqv[195];
	goto IF42016;
IF42015:
	local[0]= NIL;
IF42016:
	ctx->vsp=local+0;
	compfun(ctx,fqv[194],module,F34613time_func,fqv[347]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[348],module,F38463,fqv[349]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[350],module,F39001,fqv[351]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[352],module,F34615list_symbols,fqv[353]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[354],module,F34617functions,fqv[355]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[356],module,F34619special_variables,fqv[357]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[358],module,F34621global_variables,fqv[359]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[360],module,F34623variables,fqv[361]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[362],module,F34625constants,fqv[363]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[364],module,F34627methods,fqv[365]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[366],module,F34629method_list,fqv[367]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[368],module,F40135,fqv[369]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[370],module,F34631y_or_n_p,fqv[371]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[372],module,F34633yes_or_no_p,fqv[373]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[374],module,F34635bell,fqv[375]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M40512compiled_code_type,fqv[376],fqv[377],fqv[378]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[379],module,F34637check_methods,fqv[380]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[381],module,F34639pfuncs,fqv[382]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[383],module,F34641class_hierarchy,fqv[384]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[385],module,F34643classdef,fqv[386]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[387],module,F34645classdefs,fqv[388]);
	local[0]= fqv[300];
	local[1]= fqv[35];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF42100;
	local[0]= fqv[300];
	local[1]= fqv[35];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[300];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF42123;
	local[0]= fqv[300];
	local[1]= fqv[312];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF42124;
IF42123:
	local[0]= NIL;
IF42124:
	local[0]= fqv[300];
	goto IF42101;
IF42100:
	local[0]= NIL;
IF42101:
	ctx->vsp=local+0;
	compfun(ctx,fqv[282],module,F34647remote_error,fqv[389]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[279],module,F34649reval,fqv[390]);
	local[0]= fqv[287];
	local[1]= fqv[35];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF42147;
	local[0]= fqv[287];
	local[1]= fqv[35];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[287];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF42170;
	local[0]= fqv[287];
	local[1]= fqv[312];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF42171;
IF42170:
	local[0]= NIL;
IF42171:
	local[0]= fqv[287];
	goto IF42148;
IF42147:
	local[0]= NIL;
IF42148:
	ctx->vsp=local+0;
	compfun(ctx,fqv[303],module,F34651install_remote_function,fqv[391]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[392],module,F34653open_server,fqv[393]);
	local[0]= fqv[394];
	local[1]= fqv[395];
	ctx->vsp=local+2;
	w=(*ftab[33])(ctx,2,local+0,&ftab[33],fqv[396]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<34; i++) ftab[i]=fcallx;
}
