/* ./comp.c :  entry=comp */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "comp.h"
#pragma init (register_comp)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___comp();
extern pointer build_quote_vector();
static int register_comp()
  { add_module_initializer("___comp", ___comp);}

static pointer F6924compiled_code_p();
static pointer F6941ovafp();
static pointer F6943class_symbolp();
static pointer F6945quoted_symbolp();
static pointer F6947proclaimed_special_p();
static pointer F6949proclaimed_global_p();
static pointer F6951object_variable_names();
static pointer F6953object_variable_type();
static pointer F6955coerce_type();
static pointer F6957check_arg();
static pointer F6959def_function_type();
static pointer F7014dump_function();
static pointer F7016comfile();
static pointer F7018compile_file();
static pointer F7020compile();
static pointer F7022compile_file_if_src_newer();
static pointer F7024comp_file_toplevel();

/*compiled-code-p*/
static pointer F6924compiled_code_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[0]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK7051:
	ctx->vsp=local; return(local[0]);}

/*ovafp*/
static pointer F6941ovafp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	if (local[0]==NIL) goto AND7107;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= (issymbol(w)?T:NIL);
AND7107:
	w = local[0];
	local[0]= w;
BLK7097:
	ctx->vsp=local; return(local[0]);}

/*class-symbolp*/
static pointer F6943class_symbolp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	local[0]= (issymbol(w)?T:NIL);
	if (local[0]==NIL) goto AND7137;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	local[0]= w;
	if (w==NIL) goto AND7137;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)SYMVALUE(ctx,1,local+0); /*symbol-value*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)CLASSP(ctx,1,local+0); /*classp*/
	local[0]= w;
AND7137:
	w = local[0];
	local[0]= w;
BLK7127:
	ctx->vsp=local; return(local[0]);}

/*quoted-symbolp*/
static pointer F6945quoted_symbolp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	local[0]= (iscons(w)?T:NIL);
	if (local[0]==NIL) goto AND7168;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[0]= ((fqv[1])==(local[0])?T:NIL);
	if (local[0]==NIL) goto AND7168;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= (issymbol(w)?T:NIL);
AND7168:
	w = local[0];
	local[0]= w;
BLK7158:
	ctx->vsp=local; return(local[0]);}

/*proclaimed-special-p*/
static pointer F6947proclaimed_special_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= makeint(3);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	local[0]= w;
OR7217:
	w = local[0];
	local[0]= w;
BLK7201:
	ctx->vsp=local; return(local[0]);}

/*proclaimed-global-p*/
static pointer F6949proclaimed_global_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	local[0]= w;
BLK7226:
	ctx->vsp=local; return(local[0]);}

/*object-variable-names*/
static pointer F6951object_variable_names(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	w = argv[0];
	if (!issymbol(w)) goto IF7273;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)SYMVALUE(ctx,1,local+4); /*symbol-value*/
	local[0] = w;
	local[4]= local[0];
	goto IF7274;
IF7273:
	local[0] = argv[0];
	local[4]= local[0];
IF7274:
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)CLASSP(ctx,1,local+4); /*classp*/
	if (w==NIL) goto IF7295;
	local[1] = *(ovafptr(local[0],fqv[2]));
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[2] = w;
WHL7319:
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)SUB1(ctx,1,local+4); /*1-*/
	local[2] = w;
	local[4]= local[2];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)GREQP(ctx,2,local+4); /*>=*/
	if (w==NIL) goto WHX7320;
	local[4]= local[1];
	{ register eusinteger_t i=intval(local[2]);
	  w=(local[4]->c.vec.v[i]);}
	local[4]= w;
	w = local[3];
	ctx->vsp=local+5;
	local[3] = cons(ctx,local[4],w);
	goto WHL7319;
WHX7320:
	local[4]= NIL;
BLK7321:
	goto IF7296;
IF7295:
	local[4]= NIL;
IF7296:
	w = local[3];
	local[0]= w;
BLK7248:
	ctx->vsp=local; return(local[0]);}

/*object-variable-type*/
static pointer F6953object_variable_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)CLASSP(ctx,1,local+0); /*classp*/
	if (w!=NIL) goto IF7374;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F6943class_symbolp(ctx,1,local+0); /*class-symbolp*/
	if (w==NIL) goto IF7385;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)SYMVALUE(ctx,1,local+0); /*symbol-value*/
	argv[0] = w;
	local[0]= argv[0];
	goto IF7386;
IF7385:
	local[0]= fqv[3];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF7386:
	goto IF7375;
IF7374:
	local[0]= NIL;
IF7375:
	w = argv[1];
	if (!isnum(w)) goto IF7404;
	local[0]= argv[0]->c.obj.iv[5];
	{ register eusinteger_t i=intval(argv[1]);
	  w=(local[0]->c.vec.v[i]);}
	argv[1] = w;
	local[0]= argv[1];
	goto IF7405;
IF7404:
	local[0]= argv[1];
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[4]); /*position*/
	local[0]= w;
	if (local[0]!=NIL) goto IF7437;
	local[1]= loadglobal(fqv[5]);
	local[2]= fqv[6];
	local[3]= fqv[7];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF7438;
IF7437:
	local[1]= argv[0]->c.obj.iv[5];
	{ register eusinteger_t i=intval(local[0]);
	  w=(local[1]->c.vec.v[i]);}
	argv[1] = w;
	local[1]= argv[1];
IF7438:
	w = local[1];
	local[0]= w;
IF7405:
	w = argv[1];
	if (!iscons(w)) goto IF7463;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	goto IF7464;
IF7463:
	local[0]= argv[1];
IF7464:
	w = local[0];
	local[0]= w;
BLK7355:
	ctx->vsp=local; return(local[0]);}

/*coerce-type*/
static pointer F6955coerce_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = fqv[8];
	if (memq(local[0],w)==NIL) goto CON7489;
	local[0]= fqv[9];
	goto CON7487;
CON7489:
	local[0]= argv[0];
	w = fqv[10];
	if (memq(local[0],w)==NIL) goto CON7501;
	local[0]= fqv[11];
	goto CON7487;
CON7501:
	local[0]= argv[0];
	goto CON7487;
CON7513:
	local[0]= NIL;
CON7487:
	w = local[0];
	local[0]= w;
BLK7477:
	ctx->vsp=local; return(local[0]);}

/*check-arg*/
static pointer F6957check_arg(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT7523;}
	local[0]= fqv[12];
ENT7523:
ENT7522:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)NUMEQUAL(ctx,2,local+1); /*=*/
	if (w!=NIL) goto IF7539;
	local[1]= fqv[13];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[14]); /*warn*/
	local[1]= w;
	goto IF7540;
IF7539:
	local[1]= NIL;
IF7540:
	w = local[1];
	local[0]= w;
BLK7520:
	ctx->vsp=local; return(local[0]);}

/*def-function-type*/
static pointer F6959def_function_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[1];
WHL7581:
	if (local[1]==NIL) goto WHX7582;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= argv[0];
	local[4]= fqv[15];
	ctx->vsp=local+5;
	w=(pointer)PUTPROP(ctx,3,local+2); /*putprop*/
	goto WHL7581;
WHX7582:
	local[2]= NIL;
BLK7583:
	w = NIL;
	local[0]= w;
BLK7552:
	ctx->vsp=local; return(local[0]);}

/*:type*/
static pointer M7668identifier_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT7672;}
	local[0]= argv[0]->c.obj.iv[1];
ENT7672:
ENT7671:
	if (n>3) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F6955coerce_type(ctx,1,local+1); /*coerce-type*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK7669:
	ctx->vsp=local; return(local[0]);}

/*:offset*/
static pointer M7698identifier_offset(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT7702;}
	local[0]= argv[0]->c.obj.iv[4];
ENT7702:
ENT7701:
	if (n>3) maerror();
	argv[0]->c.obj.iv[4] = local[0];
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK7699:
	ctx->vsp=local; return(local[0]);}

/*:binding*/
static pointer M7726identifier_binding(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT7730;}
	local[0]= argv[0]->c.obj.iv[2];
ENT7730:
ENT7729:
	if (n>3) maerror();
	argv[0]->c.obj.iv[2] = local[0];
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK7727:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M7754identifier_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	argv[0]->c.obj.iv[0] = argv[2];
	argv[0]->c.obj.iv[1] = T;
	argv[0]->c.obj.iv[2] = argv[3];
	argv[0]->c.obj.iv[3] = argv[4];
	argv[0]->c.obj.iv[4] = argv[5];
	w = argv[0];
	local[0]= w;
BLK7755:
	ctx->vsp=local; return(local[0]);}

/*:find*/
static pointer M7815identifier_table_find(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT7819;}
	local[0]= argv[0]->c.obj.iv[1];
ENT7819:
ENT7818:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[0];
	{ register eusinteger_t i=intval(local[0]);
	  w=(local[2]->c.vec.v[i]);}
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ASSQ(ctx,2,local+1); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK7816:
	ctx->vsp=local; return(local[0]);}

/*:get*/
static pointer M7851identifier_table_get(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT7855;}
	local[0]= argv[0]->c.obj.iv[1];
ENT7855:
ENT7854:
	if (n>4) maerror();
	local[1]= NIL;
WHL7883:
	local[2]= local[0];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)GREQP(ctx,2,local+2); /*>=*/
	if (w==NIL) goto WHX7884;
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[0];
	{ register eusinteger_t i=intval(local[0]);
	  w=(local[3]->c.vec.v[i]);}
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ASSQ(ctx,2,local+2); /*assq*/
	local[1] = w;
	if (local[1]==NIL) goto IF7905;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK7852;
	goto IF7906;
IF7905:
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)SUB1(ctx,1,local+2); /*1-*/
	local[0] = w;
	local[2]= local[0];
IF7906:
	goto WHL7883;
WHX7884:
	local[2]= NIL;
BLK7885:
	w = local[2];
	local[0]= w;
BLK7852:
	ctx->vsp=local; return(local[0]);}

/*:enter*/
static pointer M7929identifier_table_enter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT7933;}
	local[0]= argv[0]->c.obj.iv[1];
ENT7933:
ENT7932:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= local[0];
	local[3]= *(ovafptr(argv[2],fqv[16]));
	w = argv[2];
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= argv[0]->c.obj.iv[0];
	{ register eusinteger_t i=intval(local[0]);
	  w=(local[4]->c.vec.v[i]);}
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[2]); v=local[1];
	  v->c.vec.v[i]=w;}
	w = argv[2];
	local[0]= w;
BLK7930:
	ctx->vsp=local; return(local[0]);}

/*:enter-special*/
static pointer M7973identifier_table_enter_special(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[17];
	local[2]= argv[2];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK7974:
	ctx->vsp=local; return(local[0]);}

/*:create-frame*/
static pointer M7994identifier_table_create_frame(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK7995:
	ctx->vsp=local; return(local[0]);}

/*:pop-frame*/
static pointer M8017identifier_table_pop_frame(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= argv[0]->c.obj.iv[1];
	w = NIL;
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[1]); v=local[0];
	  v->c.vec.v[i]=w;}
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)SUB1(ctx,1,local+0); /*1-*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK8018:
	ctx->vsp=local; return(local[0]);}

/*:clear-frame*/
static pointer M8046identifier_table_clear_frame(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= argv[0]->c.obj.iv[1];
	w = NIL;
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[1]); v=local[0];
	  v->c.vec.v[i]=w;}
	local[0]= w;
BLK8047:
	ctx->vsp=local; return(local[0]);}

/*:level*/
static pointer M8064identifier_table_level(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT8068;}
	local[0]= argv[0]->c.obj.iv[1];
ENT8068:
ENT8067:
	if (n>3) maerror();
	argv[0]->c.obj.iv[1] = local[0];
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK8065:
	ctx->vsp=local; return(local[0]);}

/*:frame*/
static pointer M8092identifier_table_frame(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT8096;}
	local[0]= argv[0]->c.obj.iv[1];
ENT8096:
ENT8095:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[0];
	{ register eusinteger_t i=intval(local[0]);
	  w=(local[1]->c.vec.v[i]);}
	local[0]= w;
BLK8093:
	ctx->vsp=local; return(local[0]);}

/*:init-frames*/
static pointer M8118identifier_table_init_frames(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(0);
	local[1]= argv[0]->c.obj.iv[2];
WHL8154:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX8155;
	local[2]= argv[0]->c.obj.iv[0];
	local[3]= local[0];
	w = NIL;
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[3]); v=local[2];
	  v->c.vec.v[i]=w;}
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL8154;
WHX8155:
	local[2]= NIL;
BLK8156:
	w = NIL;
	argv[0]->c.obj.iv[1] = makeint(0);
	w = argv[0];
	local[0]= w;
BLK8119:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M8189identifier_table_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT8193;}
	local[0]= makeint(20);
ENT8193:
ENT8192:
	if (n>3) maerror();
	argv[0]->c.obj.iv[2] = local[0];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,1,local+1,&ftab[2],fqv[18]); /*make-array*/
	argv[0]->c.obj.iv[0] = w;
	argv[0]->c.obj.iv[1] = makeint(0);
	w = argv[0];
	local[0]= w;
BLK8190:
	ctx->vsp=local; return(local[0]);}

/*:offset*/
static pointer M8246stack_frame_offset(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT8250;}
	local[0]= NIL;
ENT8250:
ENT8249:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF8266;
	argv[0]->c.obj.iv[0] = local[0];
	local[1]= argv[0]->c.obj.iv[0];
	goto IF8267;
IF8266:
	local[1]= NIL;
IF8267:
	w = argv[0]->c.obj.iv[0];
	local[0]= w;
BLK8247:
	ctx->vsp=local; return(local[0]);}

/*:special*/
static pointer M8281stack_frame_special(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT8285;}
	local[0]= makeint(0);
ENT8285:
ENT8284:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK8282:
	ctx->vsp=local; return(local[0]);}

/*:local*/
static pointer M8311stack_frame_local(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT8315;}
	local[0]= makeint(0);
ENT8315:
ENT8314:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	argv[0]->c.obj.iv[2] = w;
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK8312:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M8341stack_frame_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[0] = NIL;
	argv[0]->c.obj.iv[1] = makeint(0);
	argv[0]->c.obj.iv[2] = makeint(0);
	w = argv[0];
	local[0]= w;
BLK8342:
	ctx->vsp=local; return(local[0]);}

/*:genlabel*/
static pointer M8400compiler_genlabel(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT8404;}
	local[0]= fqv[19];
ENT8404:
ENT8403:
	if (n>4) maerror();
	local[1]= loadglobal(fqv[20]);
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)GENSYM(ctx,1,local+2); /*gensym*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[20]); /*string*/
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)CONCATENATE(ctx,3,local+1); /*concatenate*/
	local[0]= w;
BLK8401:
	ctx->vsp=local; return(local[0]);}

/*:gencname-tail*/
static pointer M8433compiler_gencname_tail(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST8436:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[21]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[0]= w;
BLK8434:
	ctx->vsp=local; return(local[0]);}

/*:progn*/
static pointer M8454compiler_progn(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[2]==NIL) goto IF8469;
WHL8475:
	if (argv[2]==NIL) goto WHX8476;
	local[0]= argv[0];
	local[1]= fqv[22];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[2];
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[2];
	if (local[0]==NIL) goto AND8524;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[24];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
AND8524:
	goto WHL8475;
WHX8476:
	local[0]= NIL;
BLK8477:
	goto IF8470;
IF8469:
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[25];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
IF8470:
	w = local[0];
	local[0]= w;
BLK8455:
	ctx->vsp=local; return(local[0]);}

/*:eval*/
static pointer M8541compiler_eval(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	if (!issymbol(w)) goto IF8556;
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[4])(ctx,1,local+0,&ftab[4],fqv[26]); /*constantp*/
	if (w==NIL) goto IF8556;
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)SYMVALUE(ctx,1,local+0); /*symbol-value*/
	local[0]= w;
	w = local[0];
	if (!isnum(w)) goto CON8584;
	argv[2] = local[0];
	local[1]= argv[2];
	goto CON8582;
CON8584:
	local[1]= local[0];
	w = fqv[27];
	if (memq(local[1],w)==NIL) goto CON8595;
	argv[2] = local[0];
	local[1]= argv[2];
	goto CON8582;
CON8595:
	w = local[0];
	if (!issymbol(w)) goto CON8611;
	local[1]= fqv[1];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	argv[2] = w;
	local[1]= argv[2];
	goto CON8582;
CON8611:
	w = local[0];
	if (!isstring(w)) goto CON8626;
	argv[2] = local[0];
	local[1]= argv[2];
	goto CON8582;
CON8626:
	local[1]= NIL;
CON8582:
	w = local[1];
	local[0]= w;
	goto IF8557;
IF8556:
	local[0]= NIL;
IF8557:
	local[0]= argv[2];
	if (T!=local[0]) goto CON8642;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[28];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= fqv[29];
	goto CON8640;
CON8642:
	local[0]= argv[2];
	if (NIL!=local[0]) goto CON8655;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[25];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= NIL;
	goto CON8640;
CON8655:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[5])(ctx,1,local+0,&ftab[5],fqv[30]); /*keywordp*/
	if (w==NIL) goto CON8666;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[31];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[29];
	goto CON8640;
CON8666:
	w = argv[2];
	if (!issymbol(w)) goto CON8683;
	local[0]= argv[0];
	local[1]= fqv[32];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON8640;
CON8683:
	w = argv[2];
	if (!isint(w)) goto CON8694;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[33];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[9];
	goto CON8640;
CON8694:
	w = argv[2];
	if (!isflt(w)) goto CON8708;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[34];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[11];
	goto CON8640;
CON8708:
	w = argv[2];
	if (!!iscons(w)) goto CON8722;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[31];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= T;
	goto CON8640;
CON8722:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)F6941ovafp(ctx,1,local+0); /*ovafp*/
	if (w==NIL) goto CON8734;
	local[0]= argv[0];
	local[1]= fqv[35];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON8640;
CON8734:
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON8756;
	local[0]= argv[0];
	local[1]= fqv[22];
	local[2]= fqv[36];
	local[3]= fqv[37];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON8640;
CON8756:
	local[0]= argv[0];
	local[1]= fqv[38];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= local[1];
	local[3]= local[2];
	if (fqv[39]!=local[3]) goto IF8841;
	local[3]= argv[0];
	local[4]= fqv[40];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.cdr;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF8842;
IF8841:
	local[3]= local[2];
	if (fqv[41]!=local[3]) goto IF8864;
	local[3]= argv[0];
	local[4]= fqv[42];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.cdr;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF8865;
IF8864:
	local[3]= local[2];
	if (fqv[43]!=local[3]) goto IF8887;
	local[3]= argv[0];
	local[4]= fqv[22];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(*ftab[6])(ctx,1,local+5,&ftab[6],fqv[44]); /*macroexpand*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF8888;
IF8887:
	local[3]= local[2];
	if (fqv[45]!=local[3]) goto IF8904;
	local[3]= argv[0];
	local[4]= fqv[46];
	local[5]= local[0];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.cdr;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF8905;
IF8904:
	if (T==NIL) goto IF8923;
	local[3]= argv[0];
	local[4]= fqv[6];
	local[5]= fqv[47];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF8924;
IF8923:
	local[3]= NIL;
IF8924:
IF8905:
IF8888:
IF8865:
IF8842:
	w = local[3];
	local[0]= w;
	goto CON8640;
CON8797:
	local[0]= NIL;
CON8640:
	w = local[0];
	local[0]= w;
BLK8542:
	ctx->vsp=local; return(local[0]);}

/*:get-function*/
static pointer M8936compiler_get_function(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	if (issymbol(w)) goto IF8951;
	local[0]= argv[0];
	local[1]= fqv[6];
	local[2]= fqv[48];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF8952;
IF8951:
	local[0]= NIL;
IF8952:
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	local[0]= w;
	if (local[0]==NIL) goto IF8977;
	local[1]= local[0];
	goto IF8978;
IF8977:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)FBOUNDP(ctx,1,local+1); /*fboundp*/
	if (w==NIL) goto CON8986;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[0] = w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,1,local+1,&ftab[7],fqv[49]); /*compiled-function-p*/
	if (w==NIL) goto IF9003;
	local[1]= argv[2];
	local[2]= local[0]->c.obj.iv[2];
	local[3]= fqv[50];
	ctx->vsp=local+4;
	w=(pointer)ASSQ(ctx,2,local+2); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[1]= w;
	goto IF9004;
IF9003:
	local[1]= argv[2];
	w = local[0];
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
IF9004:
	goto CON8984;
CON8986:
	local[1]= argv[2];
	local[2]= fqv[39];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[1]= w;
	goto CON8984;
CON9033:
	local[1]= NIL;
CON8984:
IF8978:
	w = local[1];
	local[0]= w;
BLK8937:
	ctx->vsp=local; return(local[0]);}

/*:call-closure*/
static pointer M9043compiler_call_closure(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	if (loadglobal(fqv[51])==NIL) goto IF9060;
	local[0]= fqv[46];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)PRINT(ctx,1,local+0); /*print*/
	local[0]= w;
	goto IF9061;
IF9060:
	local[0]= NIL;
IF9061:
	local[0]= NIL;
	local[1]= argv[3];
WHL9093:
	if (local[1]==NIL) goto WHX9094;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0];
	local[3]= fqv[22];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	goto WHL9093;
WHX9094:
	local[2]= NIL;
BLK9095:
	w = NIL;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[52];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(*ftab[8])(ctx,1,local+4,&ftab[8],fqv[53]); /*fourth*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[46];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[9])(ctx,1,local+2,&ftab[9],fqv[54]); /*fifth*/
	local[2]= w;
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK9044:
	ctx->vsp=local; return(local[0]);}

/*:variable*/
static pointer M9186compiler_variable(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[55];
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	if (local[0]==NIL) goto IF9218;
	w = local[0];
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK9187;
	goto IF9219;
IF9218:
	local[1]= NIL;
IF9219:
	local[1]= loadglobal(fqv[56]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[57];
	local[4]= argv[2];
	local[5]= fqv[41];
	local[6]= makeint(0);
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	w = local[1];
	local[0] = w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F6947proclaimed_special_p(ctx,1,local+1); /*proclaimed-special-p*/
	if (w==NIL) goto CON9265;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[58];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto CON9263;
CON9265:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F6949proclaimed_global_p(ctx,1,local+1); /*proclaimed-global-p*/
	if (w==NIL) goto CON9278;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[58];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto CON9263;
CON9278:
	local[1]= loadglobal(fqv[59]);
	local[2]= fqv[60];
	local[3]= makeint(27);
	local[4]= argv[2];
	local[5]= makeint(27);
	local[6]= makeint(27);
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,6,local+1); /*format*/
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[17];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto CON9263;
CON9291:
	local[1]= NIL;
CON9263:
	w = local[0];
	local[0]= w;
BLK9187:
	ctx->vsp=local; return(local[0]);}

/*:var-binding*/
static pointer M9311compiler_var_binding(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	if (!iscons(w)) goto IF9326;
	local[0]= fqv[61];
	goto IF9327;
IF9326:
	local[0]= argv[0];
	local[1]= fqv[62];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[63];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
IF9327:
	w = local[0];
	local[0]= w;
BLK9312:
	ctx->vsp=local; return(local[0]);}

/*:special-variable-p*/
static pointer M9344compiler_special_variable_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[64];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	if (local[0]!=NIL) goto IF9375;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F6947proclaimed_special_p(ctx,1,local+1); /*proclaimed-special-p*/
	local[1]= w;
	if (w!=NIL) goto OR9381;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F6949proclaimed_global_p(ctx,1,local+1); /*proclaimed-global-p*/
	local[1]= w;
OR9381:
	goto IF9376;
IF9375:
	local[1]= local[0];
	local[2]= fqv[63];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[1]= ((fqv[41])==(local[1])?T:NIL);
IF9376:
	w = local[1];
	local[0]= w;
BLK9345:
	ctx->vsp=local; return(local[0]);}

/*:enter-variable*/
static pointer M9403compiler_enter_variable(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[64];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	if (local[0]!=NIL) goto IF9435;
	local[1]= loadglobal(fqv[56]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[57];
	local[4]= argv[2];
	local[5]= fqv[65];
	local[6]= argv[0]->c.obj.iv[1];
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	w = local[1];
	local[0] = w;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[17];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F6947proclaimed_special_p(ctx,1,local+1); /*proclaimed-special-p*/
	if (w!=NIL) goto OR9488;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F6949proclaimed_global_p(ctx,1,local+1); /*proclaimed-global-p*/
	if (w!=NIL) goto OR9488;
	goto IF9486;
OR9488:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,1,local+1,&ftab[4],fqv[26]); /*constantp*/
	if (w==NIL) goto IF9504;
	local[1]= argv[0];
	local[2]= fqv[6];
	local[3]= fqv[66];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF9505;
IF9504:
	local[1]= NIL;
IF9505:
	local[1]= local[0];
	local[2]= fqv[63];
	local[3]= fqv[41];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF9487;
IF9486:
	local[1]= NIL;
IF9487:
	goto IF9436;
IF9435:
	local[1]= NIL;
IF9436:
	w = local[0];
	local[0]= w;
BLK9404:
	ctx->vsp=local; return(local[0]);}

/*:bind*/
static pointer M9530compiler_bind(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	if (n>=6) { local[0]=(argv[5]); goto ENT9534;}
	local[0]= NIL;
ENT9534:
ENT9533:
	if (n>6) maerror();
	w = argv[2];
	if (issymbol(w)) goto IF9557;
	local[1]= fqv[67];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,2,local+1); /*error*/
	local[1]= w;
	goto IF9558;
IF9557:
	local[1]= NIL;
IF9558:
	local[1]= argv[0];
	local[2]= fqv[68];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= local[1]->c.obj.iv[2];
	if (fqv[41]!=local[2]) goto CON9594;
	w=argv[0]->c.obj.iv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[69];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[3];
	local[3]= local[2];
	if (fqv[70]!=local[3]) goto IF9626;
	if (local[0]==NIL) goto IF9634;
	w=argv[0]->c.obj.iv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= fqv[71];
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF9635;
IF9634:
	local[3]= NIL;
IF9635:
	goto IF9627;
IF9626:
	local[3]= local[2];
	if (fqv[72]!=local[3]) goto IF9649;
	local[3]= loadglobal(fqv[23]);
	local[4]= fqv[73];
	local[5]= argv[4];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF9650;
IF9649:
	if (T==NIL) goto IF9663;
	local[3]= argv[0];
	local[4]= fqv[6];
	local[5]= fqv[74];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF9664;
IF9663:
	local[3]= NIL;
IF9664:
IF9650:
IF9627:
	w = local[3];
	local[2]= argv[4];
	w = argv[0]->c.obj.iv[9];
	ctx->vsp=local+3;
	argv[0]->c.obj.iv[9] = cons(ctx,local[2],w);
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[75];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto CON9592;
CON9594:
	local[2]= argv[3];
	if (fqv[70]!=local[2]) goto IF9696;
	w=argv[0]->c.obj.iv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[71];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF9697;
IF9696:
	local[2]= NIL;
IF9697:
	local[2]= argv[3];
	w = local[1];
	w->c.obj.iv[2] = local[2];
	local[2]= argv[4];
	local[3]= local[2];
	w = local[1];
	w->c.obj.iv[4] = local[3];
	goto CON9592;
CON9692:
	local[2]= NIL;
CON9592:
	w = local[1];
	local[0]= w;
BLK9531:
	ctx->vsp=local; return(local[0]);}

/*:create-frame*/
static pointer M9726compiler_create_frame(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[76]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[57];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = local[0];
	local[0]= w;
	w = argv[0]->c.obj.iv[3];
	ctx->vsp=local+1;
	argv[0]->c.obj.iv[3] = cons(ctx,local[0],w);
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[77];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[78];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[2] = w;
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK9727:
	ctx->vsp=local; return(local[0]);}

/*:delete-frame*/
static pointer M9792compiler_delete_frame(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[0]->c.obj.iv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[3] = (w)->c.cons.cdr;
	w = local[0];
	local[0]= w;
	local[1]= local[0]->c.obj.iv[1];
	local[2]= local[1];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto IF9860;
	if (argv[2]==NIL) goto IF9866;
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[79];
	local[4]= local[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF9867;
IF9866:
	local[2]= argv[0];
	local[3]= fqv[80];
	local[4]= fqv[81];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
IF9867:
	goto IF9861;
IF9860:
	local[2]= NIL;
IF9861:
	if (argv[2]==NIL) goto IF9885;
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[82];
	local[4]= local[0]->c.obj.iv[1];
	local[5]= local[0]->c.obj.iv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	goto IF9886;
IF9885:
	local[2]= NIL;
IF9886:
	local[2]= argv[0]->c.obj.iv[0];
	local[3]= fqv[83];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= argv[0]->c.obj.iv[0];
	local[3]= fqv[78];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	argv[0]->c.obj.iv[2] = w;
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK9793:
	ctx->vsp=local; return(local[0]);}

/*:load-ovaf*/
static pointer M9919compiler_load_ovaf(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[22];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(0);
	local[2]= local[0];
	w = fqv[84];
	if (memq(local[2],w)!=NIL) goto IF9955;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)SYMVALUE(ctx,1,local+2); /*symbol-value*/
	local[0] = w;
	local[2]= local[0];
	goto IF9956;
IF9955:
	local[2]= NIL;
IF9956:
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)CLASSP(ctx,1,local+2); /*classp*/
	if (w==NIL) goto CON9977;
	local[2]= argv[3];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F6951object_variable_names(ctx,1,local+3); /*object-variable-names*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,2,local+2,&ftab[0],fqv[4]); /*position*/
	local[1] = w;
	w = local[1];
	if (!isnum(w)) goto IF9997;
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[85];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF9998;
IF9997:
	local[2]= argv[0];
	local[3]= fqv[6];
	local[4]= fqv[86];
	local[5]= argv[2];
	local[6]= argv[3];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	local[2]= w;
IF9998:
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F6953object_variable_type(ctx,2,local+2); /*object-variable-type*/
	local[2]= w;
	goto CON9975;
CON9977:
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[35];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= T;
	goto CON9975;
CON10020:
	local[2]= NIL;
CON9975:
	w = local[2];
	local[0]= w;
BLK9920:
	ctx->vsp=local; return(local[0]);}

/*:load-var*/
static pointer M10032compiler_load_var(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	if (!iscons(w)) goto IF10048;
	local[0]= argv[0];
	local[1]= fqv[35];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	w = T;
	ctx->vsp=local+0;
	local[0]=w;
	goto BLK10033;
	goto IF10049;
IF10048:
	local[0]= NIL;
IF10049:
	local[0]= argv[0];
	local[1]= fqv[62];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	argv[2] = w;
	local[0]= *(ovafptr(argv[2],fqv[87]));
	local[1]= local[0];
	w = fqv[88];
	if (memq(local[1],w)==NIL) goto IF10103;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[89];
	local[3]= *(ovafptr(argv[2],fqv[16]));
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF10104;
IF10103:
	local[1]= local[0];
	w = fqv[90];
	if (memq(local[1],w)==NIL) goto IF10121;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[52];
	local[3]= *(ovafptr(argv[2],fqv[91]));
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= *(ovafptr(argv[2],fqv[92]));
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF10122;
IF10121:
	local[1]= local[0];
	w = fqv[93];
	if (memq(local[1],w)==NIL) goto IF10144;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[73];
	local[3]= *(ovafptr(argv[2],fqv[91]));
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= *(ovafptr(argv[2],fqv[92]));
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF10145;
IF10144:
	local[1]= local[0];
	w = fqv[94];
	if (memq(local[1],w)==NIL) goto IF10167;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[95];
	local[3]= *(ovafptr(argv[2],fqv[91]));
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= *(ovafptr(argv[2],fqv[92]));
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF10168;
IF10167:
	local[1]= local[0];
	if (fqv[65]!=local[1]) goto IF10190;
	local[1]= argv[0];
	local[2]= fqv[6];
	local[3]= fqv[96];
	local[4]= *(ovafptr(argv[2],fqv[16]));
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF10191;
IF10190:
	local[1]= NIL;
IF10191:
IF10168:
IF10145:
IF10122:
IF10104:
	w = local[1];
	local[0]= argv[2];
	local[1]= fqv[97];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK10033:
	ctx->vsp=local; return(local[0]);}

/*:store-ovaf*/
static pointer M10212compiler_store_ovaf(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[22];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	w = fqv[98];
	if (memq(local[1],w)!=NIL) goto IF10245;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)SYMVALUE(ctx,1,local+1); /*symbol-value*/
	local[0] = w;
	local[1]= local[0];
	goto IF10246;
IF10245:
	local[1]= NIL;
IF10246:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)CLASSP(ctx,1,local+1); /*classp*/
	if (w==NIL) goto IF10265;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[99];
	local[3]= argv[3];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)F6951object_variable_names(ctx,1,local+4); /*object-variable-names*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,2,local+3,&ftab[0],fqv[4]); /*position*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF10266;
IF10265:
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[100];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
IF10266:
	w = local[1];
	local[0]= w;
BLK10213:
	ctx->vsp=local; return(local[0]);}

/*:store-var*/
static pointer M10295compiler_store_var(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[62];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	argv[2] = w;
	local[0]= *(ovafptr(argv[2],fqv[87]));
	local[1]= local[0];
	w = fqv[101];
	if (memq(local[1],w)==NIL) goto IF10336;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[102];
	local[3]= *(ovafptr(argv[2],fqv[16]));
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF10337;
IF10336:
	local[1]= local[0];
	w = fqv[103];
	if (memq(local[1],w)==NIL) goto IF10354;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[104];
	local[3]= *(ovafptr(argv[2],fqv[91]));
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= *(ovafptr(argv[2],fqv[92]));
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF10355;
IF10354:
	local[1]= local[0];
	w = fqv[105];
	if (memq(local[1],w)==NIL) goto IF10377;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[106];
	local[3]= *(ovafptr(argv[2],fqv[91]));
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= *(ovafptr(argv[2],fqv[92]));
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF10378;
IF10377:
	local[1]= local[0];
	w = fqv[107];
	if (memq(local[1],w)==NIL) goto IF10400;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[108];
	local[3]= *(ovafptr(argv[2],fqv[91]));
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= *(ovafptr(argv[2],fqv[92]));
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF10401;
IF10400:
	local[1]= NIL;
IF10401:
IF10378:
IF10355:
IF10337:
	w = local[1];
	local[0]= w;
BLK10296:
	ctx->vsp=local; return(local[0]);}

/*:funcall*/
static pointer M10451compiler_funcall(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[2];
	w = fqv[109];
	if (memq(local[3],w)!=NIL) goto IF10493;
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO10507,env,argv,local);
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[1] = w;
	local[3]= local[1];
	goto IF10494;
IF10493:
	local[3]= NIL;
IF10494:
	local[3]= argv[2];
	local[4]= local[3];
	w = fqv[110];
	if (memq(local[4],w)==NIL) goto IF10529;
	local[4]= makeint(1);
	local[5]= local[0];
	local[6]= fqv[111];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[112];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= fqv[29];
	goto IF10530;
IF10529:
	local[4]= local[3];
	w = fqv[113];
	if (memq(local[4],w)==NIL) goto IF10557;
	local[4]= makeint(2);
	local[5]= local[0];
	local[6]= fqv[114];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[115];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= fqv[29];
	goto IF10558;
IF10557:
	local[4]= local[3];
	w = fqv[116];
	if (memq(local[4],w)==NIL) goto IF10585;
	local[4]= makeint(2);
	local[5]= local[0];
	local[6]= fqv[117];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[118];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10586;
IF10585:
	local[4]= local[3];
	w = fqv[119];
	if (memq(local[4],w)==NIL) goto IF10611;
	local[4]= makeint(1);
	local[5]= local[0];
	local[6]= fqv[120];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!isint(w)) goto CON10633;
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[121];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= fqv[9];
	goto CON10631;
CON10633:
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!isflt(w)) goto CON10650;
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[122];
	local[6]= argv[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= fqv[11];
	goto CON10631;
CON10650:
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[122];
	local[6]= argv[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= fqv[29];
	goto CON10631;
CON10669:
	local[4]= NIL;
CON10631:
	goto IF10612;
IF10611:
	local[4]= local[3];
	w = fqv[123];
	if (memq(local[4],w)==NIL) goto IF10683;
	local[4]= makeint(1);
	local[5]= local[0];
	local[6]= fqv[124];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!isint(w)) goto CON10705;
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[125];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= fqv[9];
	goto CON10703;
CON10705:
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!isflt(w)) goto CON10722;
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[122];
	local[6]= argv[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= fqv[11];
	goto CON10703;
CON10722:
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[122];
	local[6]= argv[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= fqv[29];
	goto CON10703;
CON10741:
	local[4]= NIL;
CON10703:
	goto IF10684;
IF10683:
	local[4]= local[3];
	w = fqv[126];
	if (memq(local[4],w)==NIL) goto IF10755;
	local[4]= makeint(1);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[127];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10756;
IF10755:
	local[4]= local[3];
	w = fqv[128];
	if (memq(local[4],w)==NIL) goto IF10780;
	local[4]= makeint(1);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[129];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10781;
IF10780:
	local[4]= local[3];
	w = fqv[130];
	if (memq(local[4],w)==NIL) goto IF10805;
	local[4]= makeint(1);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[131];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10806;
IF10805:
	local[4]= local[3];
	w = fqv[132];
	if (memq(local[4],w)==NIL) goto IF10830;
	local[4]= makeint(1);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[133];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10831;
IF10830:
	local[4]= local[3];
	w = fqv[134];
	if (memq(local[4],w)==NIL) goto IF10855;
	local[4]= makeint(1);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[135];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10856;
IF10855:
	local[4]= local[3];
	w = fqv[136];
	if (memq(local[4],w)==NIL) goto IF10880;
	local[4]= makeint(1);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[137];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10881;
IF10880:
	local[4]= local[3];
	w = fqv[138];
	if (memq(local[4],w)==NIL) goto IF10905;
	local[4]= makeint(1);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[139];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10906;
IF10905:
	local[4]= local[3];
	w = fqv[140];
	if (memq(local[4],w)==NIL) goto IF10930;
	local[4]= makeint(2);
	local[5]= local[0];
	local[6]= fqv[141];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[142];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10931;
IF10930:
	local[4]= local[3];
	w = fqv[143];
	if (memq(local[4],w)==NIL) goto IF10956;
	local[4]= makeint(1);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[144];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= T;
	goto IF10957;
IF10956:
	local[4]= local[3];
	w = fqv[145];
	if (memq(local[4],w)==NIL) goto IF10982;
	local[4]= makeint(2);
	local[5]= local[0];
	local[6]= fqv[146];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[147];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10983;
IF10982:
	local[4]= local[3];
	w = fqv[148];
	if (memq(local[4],w)==NIL) goto IF11008;
	local[4]= makeint(3);
	local[5]= local[0];
	local[6]= fqv[149];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[150];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF11009;
IF11008:
	local[4]= local[3];
	w = fqv[151];
	if (memq(local[4],w)==NIL) goto IF11034;
	local[4]= makeint(2);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[152];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	goto IF11035;
IF11034:
	local[4]= local[3];
	w = fqv[153];
	if (memq(local[4],w)==NIL) goto IF11058;
	local[4]= makeint(3);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[154];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	goto IF11059;
IF11058:
	local[4]= local[3];
	w = fqv[155];
	if (memq(local[4],w)==NIL) goto IF11082;
	local[4]= makeint(2);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[156];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	goto IF11083;
IF11082:
	local[4]= local[3];
	w = fqv[157];
	if (memq(local[4],w)==NIL) goto IF11106;
	local[4]= makeint(3);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[158];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	goto IF11107;
IF11106:
	local[4]= local[3];
	w = fqv[159];
	if (memq(local[4],w)==NIL) goto IF11130;
	local[4]= local[0];
	local[5]= argv[2];
	local[6]= fqv[160];
	ctx->vsp=local+7;
	w=(pointer)ASSQ(ctx,2,local+5); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
	ctx->vsp=local+6;
	w=(pointer)GREATERP(ctx,2,local+4); /*>*/
	if (w==NIL) goto IF11141;
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[122];
	local[6]= argv[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto IF11142;
IF11141:
	local[4]= argv[0];
	local[5]= fqv[161];
	local[6]= argv[2];
	local[7]= local[0];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[4]= w;
IF11142:
	goto IF11131;
IF11130:
	local[4]= local[3];
	w = fqv[162];
	if (memq(local[4],w)==NIL) goto IF11171;
	local[4]= argv[0];
	local[5]= fqv[163];
	local[6]= argv[2];
	local[7]= local[0];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[4]= w;
	goto IF11172;
IF11171:
	local[4]= local[3];
	w = fqv[164];
	if (memq(local[4],w)==NIL) goto IF11190;
	local[4]= makeint(3);
	local[5]= local[0];
	local[6]= fqv[165];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= argv[0];
	local[5]= fqv[166];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[4]= w;
	goto IF11191;
IF11190:
	local[4]= local[3];
	w = fqv[167];
	if (memq(local[4],w)==NIL) goto IF11236;
	local[4]= makeint(4);
	local[5]= local[0];
	local[6]= fqv[168];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= argv[0];
	local[5]= fqv[169];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= argv[3];
	ctx->vsp=local+10;
	w=(*ftab[8])(ctx,1,local+9,&ftab[8],fqv[53]); /*fourth*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,6,local+4); /*send*/
	local[4]= w;
	goto IF11237;
IF11236:
	local[4]= local[3];
	w = fqv[170];
	if (memq(local[4],w)==NIL) goto IF11285;
	local[4]= makeint(1);
	local[5]= local[0];
	local[6]= fqv[171];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)F6955coerce_type(ctx,1,local+4); /*coerce-type*/
	local[4]= w;
	local[5]= fqv[9];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w==NIL) goto CON11307;
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[172];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= fqv[9];
	goto CON11305;
CON11307:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)F6955coerce_type(ctx,1,local+4); /*coerce-type*/
	local[4]= w;
	local[5]= fqv[11];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w==NIL) goto CON11330;
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[173];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= fqv[11];
	goto CON11305;
CON11330:
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[122];
	local[6]= argv[2];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= T;
	goto CON11305;
CON11353:
	local[4]= NIL;
CON11305:
	goto IF11286;
IF11285:
	if (T==NIL) goto IF11364;
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[122];
	local[6]= argv[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = argv[2];
	if (!issymbol(w)) goto IF11380;
	local[4]= argv[2];
	local[5]= fqv[15];
	ctx->vsp=local+6;
	w=(pointer)GETPROP(ctx,2,local+4); /*get*/
	local[4]= w;
	goto IF11381;
IF11380:
	local[4]= T;
IF11381:
	goto IF11365;
IF11364:
	local[4]= NIL;
IF11365:
IF11286:
IF11237:
IF11191:
IF11172:
IF11131:
IF11107:
IF11083:
IF11059:
IF11035:
IF11009:
IF10983:
IF10957:
IF10931:
IF10906:
IF10881:
IF10856:
IF10831:
IF10806:
IF10781:
IF10756:
IF10684:
IF10612:
IF10586:
IF10558:
IF10530:
	w = local[4];
	local[0]= w;
BLK10452:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO10507(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= fqv[22];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:vector-op*/
static pointer M11436compiler_vector_op(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	w=argv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= argv[2];
	local[2]= fqv[174];
	ctx->vsp=local+3;
	w=(pointer)ASSQ(ctx,2,local+1); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	w = local[0];
	if (!issymbol(w)) goto IF11482;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)BOUNDP(ctx,1,local+2); /*boundp*/
	if (w==NIL) goto IF11482;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)SYMVALUE(ctx,1,local+2); /*symbol-value*/
	local[0] = w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)CLASSP(ctx,1,local+2); /*classp*/
	if (w==NIL) goto IF11482;
	local[2]= local[0];
	local[3]= loadglobal(fqv[175]);
	ctx->vsp=local+4;
	w=(pointer)SUBCLASSP(ctx,2,local+2); /*subclassp*/
	if (w==NIL) goto CON11508;
	local[2]= loadglobal(fqv[23]);
	local[3]= local[1];
	local[4]= fqv[9];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= fqv[9];
	goto CON11506;
CON11508:
	local[2]= local[0];
	local[3]= loadglobal(fqv[20]);
	ctx->vsp=local+4;
	w=(pointer)SUBCLASSP(ctx,2,local+2); /*subclassp*/
	if (w==NIL) goto CON11526;
	local[2]= loadglobal(fqv[23]);
	local[3]= local[1];
	local[4]= fqv[176];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= fqv[9];
	goto CON11506;
CON11526:
	local[2]= local[0];
	local[3]= loadglobal(fqv[177]);
	ctx->vsp=local+4;
	w=(pointer)SUBCLASSP(ctx,2,local+2); /*subclassp*/
	if (w==NIL) goto CON11543;
	local[2]= loadglobal(fqv[23]);
	local[3]= local[1];
	local[4]= fqv[11];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= fqv[11];
	goto CON11506;
CON11543:
	local[2]= local[0];
	local[3]= loadglobal(fqv[178]);
	ctx->vsp=local+4;
	w=(pointer)SUBCLASSP(ctx,2,local+2); /*subclassp*/
	if (w==NIL) goto CON11561;
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[122];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= fqv[9];
	goto CON11506;
CON11561:
	local[2]= local[0];
	local[3]= loadglobal(fqv[179]);
	ctx->vsp=local+4;
	w=(pointer)SUBCLASSP(ctx,2,local+2); /*subclassp*/
	if (w==NIL) goto CON11580;
	local[2]= loadglobal(fqv[23]);
	local[3]= local[1];
	local[4]= fqv[180];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= T;
	goto CON11506;
CON11580:
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[122];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= T;
	goto CON11506;
CON11596:
	local[2]= NIL;
CON11506:
	goto IF11483;
IF11482:
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[122];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
IF11483:
	w = local[2];
	local[0]= w;
BLK11437:
	ctx->vsp=local; return(local[0]);}

/*:slot*/
static pointer M11616compiler_slot(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = argv[4];
	if (isnum(w)) goto IF11652;
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)F6943class_symbolp(ctx,1,local+1); /*class-symbolp*/
	if (w==NIL) goto IF11652;
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)F6945quoted_symbolp(ctx,1,local+1); /*quoted-symbolp*/
	if (w==NIL) goto IF11652;
	w=argv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)SYMVALUE(ctx,1,local+2); /*symbol-value*/
	local[2]= *(ovafptr(w,fqv[2]));
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[4]); /*position*/
	local[0] = w;
	if (local[0]==NIL) goto IF11652;
	argv[4] = local[0];
	local[1]= argv[4];
	goto IF11653;
IF11652:
	local[1]= NIL;
IF11653:
	w = argv[4];
	if (!isnum(w)) goto CON11701;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[85];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[3];
	local[2]= argv[4];
	ctx->vsp=local+3;
	w=(pointer)F6953object_variable_type(ctx,2,local+1); /*object-variable-type*/
	local[1]= w;
	goto CON11699;
CON11701:
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[122];
	local[3]= fqv[165];
	local[4]= makeint(3);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= T;
	goto CON11699;
CON11717:
	local[1]= NIL;
CON11699:
	w = local[1];
	local[0]= w;
BLK11617:
	ctx->vsp=local; return(local[0]);}

/*:setslot*/
static pointer M11744compiler_setslot(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= NIL;
	w = argv[4];
	if (isnum(w)) goto IF11775;
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)F6943class_symbolp(ctx,1,local+1); /*class-symbolp*/
	if (w==NIL) goto IF11775;
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)F6945quoted_symbolp(ctx,1,local+1); /*quoted-symbolp*/
	if (w==NIL) goto IF11775;
	w=argv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)SYMVALUE(ctx,1,local+2); /*symbol-value*/
	local[2]= *(ovafptr(w,fqv[2]));
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[4]); /*position*/
	local[0] = w;
	if (local[0]==NIL) goto IF11775;
	argv[4] = local[0];
	local[1]= argv[4];
	goto IF11776;
IF11775:
	local[1]= NIL;
IF11776:
	w = argv[4];
	if (!isnum(w)) goto CON11824;
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[181];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[99];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[3];
	local[2]= argv[4];
	ctx->vsp=local+3;
	w=(pointer)F6953object_variable_type(ctx,2,local+1); /*object-variable-type*/
	local[1]= w;
	goto CON11822;
CON11824:
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[122];
	local[3]= fqv[168];
	local[4]= makeint(4);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= T;
	goto CON11822;
CON11860:
	local[1]= NIL;
CON11822:
	w = local[1];
	local[0]= w;
BLK11745:
	ctx->vsp=local; return(local[0]);}

/*:arithmetic*/
static pointer M11928compiler_arithmetic(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= loadglobal(fqv[182]);
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto IF11947;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[122];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= T;
	goto IF11948;
IF11947:
	local[0]= argv[2];
	if (fqv[183]!=local[0]) goto CON11967;
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO11981,env,argv,local);
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,2,local+0,&ftab[10],fqv[184]); /*every*/
	if (w==NIL) goto CON11977;
	local[0]= argv[3];
	local[1]= local[0];
	w = fqv[185];
	if (memq(local[1],w)==NIL) goto IF12002;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[186];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF12003;
IF12002:
	local[1]= local[0];
	w = fqv[187];
	if (memq(local[1],w)==NIL) goto IF12018;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[188];
	local[3]= fqv[183];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF12019;
IF12018:
	if (T==NIL) goto IF12036;
WHL12044:
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)SUB1(ctx,1,local+1); /*1-*/
	argv[3] = w;
	local[1]= argv[3];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)GREATERP(ctx,2,local+1); /*>*/
	if (w==NIL) goto WHX12045;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[188];
	local[3]= fqv[189];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	goto WHL12044;
WHX12045:
	local[1]= NIL;
BLK12046:
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[186];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[188];
	local[3]= fqv[189];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF12037;
IF12036:
	local[1]= NIL;
IF12037:
IF12019:
IF12003:
	w = local[1];
	local[0]= fqv[9];
	goto CON11975;
CON11977:
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO12088,env,argv,local);
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,2,local+0,&ftab[10],fqv[184]); /*every*/
	if (w==NIL) goto CON12084;
	local[0]= argv[3];
	local[1]= local[0];
	w = fqv[190];
	if (memq(local[1],w)==NIL) goto IF12108;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[191];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF12109;
IF12108:
	local[1]= local[0];
	w = fqv[192];
	if (memq(local[1],w)==NIL) goto IF12124;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[193];
	local[3]= fqv[183];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF12125;
IF12124:
	if (T==NIL) goto IF12142;
WHL12150:
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)SUB1(ctx,1,local+1); /*1-*/
	argv[3] = w;
	local[1]= argv[3];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)GREATERP(ctx,2,local+1); /*>*/
	if (w==NIL) goto WHX12151;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[193];
	local[3]= fqv[189];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	goto WHL12150;
WHX12151:
	local[1]= NIL;
BLK12152:
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[191];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[193];
	local[3]= fqv[189];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF12143;
IF12142:
	local[1]= NIL;
IF12143:
IF12125:
IF12109:
	w = local[1];
	local[0]= fqv[11];
	goto CON11975;
CON12084:
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[122];
	local[2]= fqv[183];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= T;
	goto CON11975;
CON12190:
	local[0]= NIL;
CON11975:
	goto CON11965;
CON11967:
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO12212,env,argv,local);
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,2,local+0,&ftab[10],fqv[184]); /*every*/
	if (w==NIL) goto CON12208;
WHL12219:
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)SUB1(ctx,1,local+0); /*1-*/
	argv[3] = w;
	local[0]= argv[3];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto WHX12220;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[188];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	goto WHL12219;
WHX12220:
	local[0]= NIL;
BLK12221:
	local[0]= fqv[9];
	goto CON12206;
CON12208:
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO12247,env,argv,local);
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,2,local+0,&ftab[10],fqv[184]); /*every*/
	if (w==NIL) goto CON12243;
WHL12254:
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)SUB1(ctx,1,local+0); /*1-*/
	argv[3] = w;
	local[0]= argv[3];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto WHX12255;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[193];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	goto WHL12254;
WHX12255:
	local[0]= NIL;
BLK12256:
	local[0]= fqv[11];
	goto CON12206;
CON12243:
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[122];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= T;
	goto CON12206;
CON12278:
	local[0]= NIL;
CON12206:
	goto CON11965;
CON12202:
	local[0]= NIL;
CON11965:
IF11948:
	w = local[0];
	local[0]= w;
BLK11929:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO11981(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = fqv[194];
	w = memq(local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO12088(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = fqv[195];
	w = memq(local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO12212(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = fqv[196];
	w = memq(local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO12247(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = fqv[197];
	w = memq(local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:special-form*/
static pointer M12385compiler_special_form(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= local[0];
	w = fqv[198];
	if (memq(local[1],w)==NIL) goto IF12415;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[31];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12416;
IF12415:
	local[1]= local[0];
	w = fqv[199];
	if (memq(local[1],w)==NIL) goto IF12440;
	local[1]= argv[0];
	local[2]= fqv[200];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF12441;
IF12440:
	local[1]= local[0];
	w = fqv[201];
	if (memq(local[1],w)==NIL) goto IF12457;
	local[1]= argv[0];
	local[2]= fqv[202];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12458;
IF12457:
	local[1]= local[0];
	w = fqv[203];
	if (memq(local[1],w)==NIL) goto IF12478;
	local[1]= argv[0];
	local[2]= fqv[204];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12479;
IF12478:
	local[1]= local[0];
	w = fqv[205];
	if (memq(local[1],w)==NIL) goto IF12499;
	local[1]= argv[0];
	local[2]= fqv[206];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12500;
IF12499:
	local[1]= local[0];
	w = fqv[207];
	if (memq(local[1],w)==NIL) goto IF12520;
	local[1]= argv[0];
	local[2]= fqv[208];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12521;
IF12520:
	local[1]= local[0];
	w = fqv[209];
	if (memq(local[1],w)==NIL) goto IF12541;
	local[1]= argv[0];
	local[2]= fqv[210];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12542;
IF12541:
	local[1]= local[0];
	w = fqv[211];
	if (memq(local[1],w)==NIL) goto IF12562;
	local[1]= argv[0];
	local[2]= fqv[212];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12563;
IF12562:
	local[1]= local[0];
	w = fqv[213];
	if (memq(local[1],w)==NIL) goto IF12583;
	local[1]= argv[0];
	local[2]= fqv[214];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12584;
IF12583:
	local[1]= local[0];
	w = fqv[215];
	if (memq(local[1],w)==NIL) goto IF12604;
	local[1]= argv[0];
	local[2]= fqv[216];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= T;
	goto IF12605;
IF12604:
	local[1]= local[0];
	w = fqv[217];
	if (memq(local[1],w)==NIL) goto IF12634;
	local[1]= argv[0];
	local[2]= fqv[218];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= T;
	goto IF12635;
IF12634:
	local[1]= local[0];
	w = fqv[219];
	if (memq(local[1],w)==NIL) goto IF12666;
	local[1]= argv[0];
	local[2]= fqv[220];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= T;
	goto IF12667;
IF12666:
	local[1]= local[0];
	w = fqv[221];
	if (memq(local[1],w)==NIL) goto IF12696;
	local[1]= argv[0];
	local[2]= fqv[222];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= T;
	goto IF12697;
IF12696:
	local[1]= local[0];
	w = fqv[223];
	if (memq(local[1],w)==NIL) goto IF12728;
	local[1]= argv[0];
	local[2]= fqv[224];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12729;
IF12728:
	local[1]= local[0];
	w = fqv[225];
	if (memq(local[1],w)==NIL) goto IF12749;
	local[1]= argv[0];
	local[2]= fqv[226];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12750;
IF12749:
	local[1]= local[0];
	w = fqv[227];
	if (memq(local[1],w)==NIL) goto IF12774;
	local[1]= argv[0];
	local[2]= fqv[228];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	local[5]= NIL;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= T;
	goto IF12775;
IF12774:
	local[1]= local[0];
	w = fqv[229];
	if (memq(local[1],w)==NIL) goto IF12804;
	local[1]= argv[0];
	local[2]= fqv[228];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	local[5]= T;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= T;
	goto IF12805;
IF12804:
	local[1]= local[0];
	w = fqv[230];
	if (memq(local[1],w)==NIL) goto IF12834;
	local[1]= argv[0];
	local[2]= fqv[231];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= T;
	goto IF12835;
IF12834:
	local[1]= local[0];
	w = fqv[232];
	if (memq(local[1],w)==NIL) goto IF12864;
	local[1]= argv[0];
	local[2]= fqv[233];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12865;
IF12864:
	local[1]= local[0];
	w = fqv[234];
	if (memq(local[1],w)==NIL) goto IF12885;
	local[1]= argv[0];
	local[2]= fqv[235];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12886;
IF12885:
	local[1]= local[0];
	w = fqv[236];
	if (memq(local[1],w)==NIL) goto IF12910;
	local[1]= argv[0];
	local[2]= fqv[22];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)F6955coerce_type(ctx,1,local+1); /*coerce-type*/
	local[1]= w;
	goto IF12911;
IF12910:
	local[1]= local[0];
	w = fqv[237];
	if (memq(local[1],w)==NIL) goto IF12944;
	local[1]= argv[0];
	local[2]= fqv[80];
	local[3]= fqv[238];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12945;
IF12944:
	local[1]= local[0];
	w = fqv[239];
	if (memq(local[1],w)==NIL) goto IF12964;
	local[1]= argv[0];
	local[2]= fqv[80];
	local[3]= fqv[240];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12965;
IF12964:
	local[1]= local[0];
	w = fqv[241];
	if (memq(local[1],w)==NIL) goto IF12984;
	local[1]= argv[0];
	local[2]= fqv[80];
	local[3]= fqv[242];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12985;
IF12984:
	local[1]= local[0];
	w = fqv[243];
	if (memq(local[1],w)==NIL) goto IF13004;
	local[1]= argv[0];
	local[2]= fqv[80];
	local[3]= fqv[244];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF13005;
IF13004:
	if (T==NIL) goto IF13024;
	local[1]= argv[0];
	local[2]= fqv[6];
	local[3]= fqv[245];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF13025;
IF13024:
	local[1]= NIL;
IF13025:
IF13005:
IF12985:
IF12965:
IF12945:
IF12911:
IF12886:
IF12865:
IF12835:
IF12805:
IF12775:
IF12750:
IF12729:
IF12697:
IF12667:
IF12635:
IF12605:
IF12584:
IF12563:
IF12542:
IF12521:
IF12500:
IF12479:
IF12458:
IF12441:
IF12416:
	w = local[1];
	local[0]= w;
BLK12386:
	ctx->vsp=local; return(local[0]);}

/*:conditional-jump*/
static pointer M13063compiler_conditional_jump(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	if (argv[3]==NIL) goto IF13080;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[246];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF13081;
IF13080:
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[247];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
IF13081:
	w = local[0];
	local[0]= w;
BLK13064:
	ctx->vsp=local; return(local[0]);}

/*:evcon*/
static pointer M13098compiler_evcon(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[4];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)LISTP(ctx,1,local+5); /*listp*/
	if (w==NIL) goto IF13134;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	local[5]= local[1];
	goto IF13135;
IF13134:
	local[5]= NIL;
IF13135:
	w = argv[2];
	if (!iscons(w)) goto OR13163;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	w = makeint(1);
	if ((eusinteger_t)local[5] <= (eusinteger_t)w) goto OR13163;
	goto CON13162;
OR13163:
	local[5]= argv[0];
	local[6]= fqv[22];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[248];
	local[7]= argv[3];
	local[8]= argv[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto CON13160;
CON13162:
	local[5]= local[0];
	if (fqv[114]!=local[5]) goto CON13188;
	local[5]= makeint(2);
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)F6957check_arg(ctx,3,local+5); /*check-arg*/
	local[5]= argv[0];
	local[6]= fqv[22];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[22];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	if (argv[4]==NIL) goto IF13227;
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[249];
	local[7]= argv[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF13228;
IF13227:
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[250];
	local[7]= argv[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
IF13228:
	goto CON13160;
CON13188:
	local[5]= local[0];
	w = fqv[251];
	if (memq(local[5],w)==NIL) goto CON13244;
	local[5]= makeint(1);
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)F6957check_arg(ctx,3,local+5); /*check-arg*/
	local[5]= argv[0];
	local[6]= fqv[252];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= argv[4];
	local[9]= argv[3];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	local[5]= w;
	goto CON13160;
CON13244:
	local[5]= local[0];
	if (fqv[253]!=local[5]) goto CON13273;
	if (argv[4]!=NIL) goto IF13281;
	local[5]= argv[0];
	local[6]= fqv[254];
	local[7]= fqv[255];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[4] = w;
	local[5]= local[4];
	goto IF13282;
IF13281:
	local[5]= NIL;
IF13282:
WHL13298:
	if (local[1]==NIL) goto WHX13299;
	local[5]= argv[0];
	local[6]= fqv[252];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[7];
	local[7]= w;
	local[8]= NIL;
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	goto WHL13298;
WHX13299:
	local[5]= NIL;
BLK13300:
	if (argv[4]!=NIL) goto IF13349;
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[256];
	local[7]= argv[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[257];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF13350;
IF13349:
	local[5]= NIL;
IF13350:
	goto CON13160;
CON13273:
	local[5]= local[0];
	if (fqv[258]!=local[5]) goto CON13370;
	if (argv[3]!=NIL) goto IF13378;
	local[5]= argv[0];
	local[6]= fqv[254];
	local[7]= fqv[259];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[4] = w;
	local[5]= local[4];
	goto IF13379;
IF13378:
	local[4] = argv[3];
	local[5]= local[4];
IF13379:
WHL13401:
	if (local[1]==NIL) goto WHX13402;
	local[5]= argv[0];
	local[6]= fqv[252];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[7];
	local[7]= w;
	local[8]= local[4];
	local[9]= NIL;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	goto WHL13401;
WHX13402:
	local[5]= NIL;
BLK13403:
	if (argv[3]!=NIL) goto IF13452;
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[256];
	local[7]= argv[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[257];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF13453;
IF13452:
	local[5]= NIL;
IF13453:
	goto CON13160;
CON13370:
	local[5]= local[0];
	w = fqv[260];
	if (memq(local[5],w)==NIL) goto CON13473;
	local[5]= makeint(1);
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)F6957check_arg(ctx,3,local+5); /*check-arg*/
	local[5]= argv[0];
	local[6]= fqv[22];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	if (argv[4]==NIL) goto IF13502;
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[261];
	local[7]= local[0];
	local[8]= argv[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto IF13503;
IF13502:
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[262];
	local[7]= local[0];
	local[8]= argv[3];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
IF13503:
	goto CON13160;
CON13473:
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	if (makeint(2)!=local[5]) goto CON13521;
	local[5]= local[0];
	w = fqv[263];
	if (memq(local[5],w)==NIL) goto CON13521;
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO13541,env,argv,local);
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)MAPCAR(ctx,2,local+5); /*mapcar*/
	local[2] = w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= fqv[264];
	ctx->vsp=local+7;
	w=(*ftab[11])(ctx,2,local+5,&ftab[11],fqv[265]); /*member*/
	if (w==NIL) goto CON13552;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)EQ(ctx,2,local+5); /*eql*/
	if (w==NIL) goto CON13552;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= fqv[266];
	ctx->vsp=local+7;
	w=(pointer)ASSQ(ctx,2,local+5); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	if (argv[3]==NIL) goto CON13605;
	local[4] = argv[3];
	local[5]= local[4];
	goto CON13603;
CON13605:
	local[5]= local[0];
	local[6]= fqv[267];
	ctx->vsp=local+7;
	w=(pointer)ASSQ(ctx,2,local+5); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	local[5]= local[0];
	goto CON13603;
CON13616:
	local[5]= NIL;
CON13603:
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[268];
	local[7]= local[3];
	local[8]= local[0];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	local[5]= w;
	goto CON13550;
CON13552:
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[122];
	local[7]= local[0];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[248];
	local[7]= argv[3];
	local[8]= argv[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto CON13550;
CON13642:
	local[5]= NIL;
CON13550:
	goto CON13160;
CON13521:
	local[5]= argv[0];
	local[6]= fqv[22];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[248];
	local[7]= argv[3];
	local[8]= argv[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto CON13160;
CON13662:
	local[5]= NIL;
CON13160:
	w = local[5];
	local[0]= w;
BLK13099:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO13541(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= fqv[22];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:if*/
static pointer M13724compiler_if(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[254];
	local[2]= fqv[269];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[254];
	local[3]= fqv[270];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[252];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= NIL;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[22];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[256];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[271];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[257];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[22];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[257];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0]= w;
BLK13725:
	ctx->vsp=local; return(local[0]);}

/*:setq*/
static pointer M13829compiler_setq(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[2]!=NIL) goto IF13845;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[25];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = T;
	ctx->vsp=local+0;
	local[0]=w;
	goto BLK13830;
	goto IF13846;
IF13845:
	local[0]= NIL;
IF13846:
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
WHL13883:
	if (argv[2]==NIL) goto WHX13884;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	local[2] = NIL;
	local[4]= argv[0];
	local[5]= fqv[22];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[3] = w;
	if (argv[2]!=NIL) goto IF13935;
	local[4]= argv[0];
	local[5]= fqv[272];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	w = fqv[273];
	if (memq(local[4],w)==NIL) goto IF13935;
	local[2] = T;
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[181];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	goto IF13936;
IF13935:
	local[4]= NIL;
IF13936:
	w = local[0];
	if (!issymbol(w)) goto IF13970;
	local[4]= argv[0];
	local[5]= fqv[274];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF13971;
IF13970:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	if (issymbol(w)) goto IF13985;
	local[4]= argv[0];
	local[5]= fqv[6];
	local[6]= fqv[275];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto IF13986;
IF13985:
	local[4]= NIL;
IF13986:
	local[4]= argv[0];
	local[5]= fqv[100];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
IF13971:
	local[4]= ((argv[2])==NIL?T:NIL);
	if (local[4]==NIL) goto AND14018;
	local[4]= ((local[2])==NIL?T:NIL);
	if (local[4]==NIL) goto AND14018;
	local[4]= argv[0];
	local[5]= fqv[32];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
AND14018:
	goto WHL13883;
WHX13884:
	local[4]= NIL;
BLK13885:
	w = local[3];
	local[0]= w;
BLK13830:
	ctx->vsp=local; return(local[0]);}

/*:let**/
static pointer M14043compiler_let_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[0];
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[9];
	local[2]= argv[0];
	local[3]= fqv[77];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
WHL14113:
	if (argv[2]==NIL) goto WHX14114;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!iscons(w)) goto WHX14114;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	if (fqv[276]!=local[2]) goto WHX14114;
	local[2]= argv[0];
	local[3]= fqv[277];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	goto WHL14113;
WHX14114:
	local[2]= NIL;
BLK14115:
	local[2]= NIL;
	local[3]= local[0];
WHL14202:
	if (local[3]==NIL) goto WHX14203;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= argv[0];
	local[5]= fqv[22];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)LISTP(ctx,1,local+6); /*listp*/
	if (w==NIL) goto IF14255;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	goto IF14256;
IF14255:
	local[6]= NIL;
IF14256:
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[278];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)LISTP(ctx,1,local+6); /*listp*/
	if (w==NIL) goto IF14276;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	goto IF14277;
IF14276:
	local[6]= local[2];
IF14277:
	local[7]= fqv[70];
	local[8]= loadglobal(fqv[23]);
	local[9]= fqv[279];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SUB1(ctx,1,local+8); /*1-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	goto WHL14202;
WHX14203:
	local[4]= NIL;
BLK14204:
	w = NIL;
	local[2]= argv[0];
	local[3]= fqv[233];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	argv[0]->c.obj.iv[9] = local[1];
	local[2]= argv[0];
	local[3]= fqv[280];
	local[4]= T;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0]= w;
BLK14044:
	ctx->vsp=local; return(local[0]);}

/*:let*/
static pointer M14324compiler_let(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[0];
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[9];
	local[5]= argv[0];
	local[6]= fqv[77];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
WHL14400:
	if (argv[2]==NIL) goto WHX14401;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!iscons(w)) goto WHX14401;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	if (fqv[276]!=local[5]) goto WHX14401;
	local[5]= argv[0];
	local[6]= fqv[277];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	goto WHL14400;
WHX14401:
	local[5]= NIL;
BLK14402:
	local[5]= NIL;
	local[6]= local[0];
WHL14489:
	if (local[6]==NIL) goto WHX14490;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= argv[0]->c.obj.iv[0];
	local[8]= fqv[78];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SUB1(ctx,1,local+7); /*1-*/
	argv[0]->c.obj.iv[2] = w;
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)LISTP(ctx,1,local+7); /*listp*/
	if (w==NIL) goto IF14553;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[7];
	local[7]= w;
	goto IF14554;
IF14553:
	local[7]= local[5];
IF14554:
	local[1] = local[7];
	local[7]= argv[0];
	local[8]= fqv[22];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)LISTP(ctx,1,local+9); /*listp*/
	if (w==NIL) goto IF14604;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	goto IF14605;
IF14604:
	local[9]= NIL;
IF14605:
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= loadglobal(fqv[23]);
	local[8]= fqv[279];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SUB1(ctx,1,local+7); /*1-*/
	local[3] = w;
	local[7]= argv[0];
	local[8]= fqv[281];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	if (w==NIL) goto CON14634;
	w=argv[0]->c.obj.iv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= fqv[71];
	local[9]= makeint(1);
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= local[1];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	w = local[2];
	ctx->vsp=local+8;
	local[2] = cons(ctx,local[7],w);
	local[7]= local[2];
	goto CON14632;
CON14634:
	local[7]= argv[0];
	local[8]= fqv[278];
	local[9]= local[1];
	local[10]= fqv[70];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	local[7]= w;
	goto CON14632;
CON14668:
	local[7]= NIL;
CON14632:
	goto WHL14489;
WHX14490:
	local[7]= NIL;
BLK14491:
	w = NIL;
	local[5]= NIL;
	local[6]= local[2];
WHL14702:
	if (local[6]==NIL) goto WHX14703;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= loadglobal(fqv[23]);
	local[8]= fqv[279];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[3] = w;
	local[7]= loadglobal(fqv[23]);
	local[8]= fqv[52];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= makeint(0);
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[7]= argv[0];
	local[8]= fqv[278];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= fqv[70];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	goto WHL14702;
WHX14703:
	local[7]= NIL;
BLK14704:
	w = NIL;
	local[5]= argv[0]->c.obj.iv[0];
	local[6]= fqv[78];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	argv[0]->c.obj.iv[2] = w;
	local[5]= argv[0];
	local[6]= fqv[233];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	argv[0]->c.obj.iv[9] = local[4];
	local[5]= argv[0];
	local[6]= fqv[280];
	local[7]= T;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[0]= w;
BLK14325:
	ctx->vsp=local; return(local[0]);}

/*:cond*/
static pointer M14823compiler_cond(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0];
	local[5]= fqv[254];
	local[6]= fqv[282];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
WHL14861:
	if (argv[2]==NIL) goto WHX14862;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[5];
	local[0] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	local[5]= argv[0];
	local[6]= fqv[254];
	local[7]= fqv[283];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[2] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr!=NIL) goto CON14926;
	local[5]= argv[0];
	local[6]= fqv[22];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[181];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[247];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[24];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto CON14924;
CON14926:
	local[5]= local[1];
	if (T!=local[5]) goto CON14960;
	local[3] = T;
	local[5]= local[3];
	goto CON14924;
CON14960:
	local[5]= argv[0];
	local[6]= fqv[252];
	local[7]= local[1];
	local[8]= NIL;
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	local[5]= w;
	goto CON14924;
CON14970:
	local[5]= NIL;
CON14924:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF14983;
	local[5]= argv[0];
	local[6]= fqv[233];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[256];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[271];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF14984;
IF14983:
	local[5]= NIL;
IF14984:
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[257];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	goto WHL14861;
WHX14862:
	local[5]= NIL;
BLK14863:
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[25];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[257];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[0]= w;
BLK14824:
	ctx->vsp=local; return(local[0]);}

/*:while*/
static pointer M15040compiler_while(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	local[2]= argv[0];
	local[3]= fqv[254];
	local[4]= fqv[284];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[254];
	local[5]= fqv[285];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[286];
	local[6]= NIL;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[257];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[252];
	local[7]= local[0];
	local[8]= NIL;
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[233];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[24];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[256];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[257];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[25];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[257];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[287];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[0]= w;
BLK15041:
	ctx->vsp=local; return(local[0]);}

/*:and*/
static pointer M15163compiler_and(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[254];
	local[2]= fqv[288];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
WHL15193:
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX15194;
	local[1]= argv[0];
	local[2]= fqv[22];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[3];
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[181];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[246];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[24];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	goto WHL15193;
WHX15194:
	local[1]= NIL;
BLK15195:
	local[1]= argv[0];
	local[2]= fqv[22];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[257];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK15164:
	ctx->vsp=local; return(local[0]);}

/*:or*/
static pointer M15283compiler_or(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[254];
	local[2]= fqv[289];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
WHL15313:
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX15314;
	local[1]= argv[0];
	local[2]= fqv[22];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[3];
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[181];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[247];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[24];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	goto WHL15313;
WHX15314:
	local[1]= NIL;
BLK15315:
	local[1]= argv[0];
	local[2]= fqv[22];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[257];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK15284:
	ctx->vsp=local; return(local[0]);}

/*:catch*/
static pointer M15403compiler_catch(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[254];
	local[2]= fqv[290];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[279];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	w = argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[9] = cons(ctx,local[1],w);
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[291];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[233];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[9] = (w)->c.cons.cdr;
	w = local[1];
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[292];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK15404:
	ctx->vsp=local; return(local[0]);}

/*:throw*/
static pointer M15515compiler_throw(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[22];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[22];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[222];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK15516:
	ctx->vsp=local; return(local[0]);}

/*:unwind-protect*/
static pointer M15551compiler_unwind_protect(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[254];
	local[2]= fqv[293];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[279];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	w = argv[0]->c.obj.iv[9];
	ctx->vsp=local+3;
	argv[0]->c.obj.iv[9] = cons(ctx,local[2],w);
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[294];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[295];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[1] = w;
	local[2]= argv[0];
	local[3]= fqv[296];
	local[4]= local[0];
	local[5]= fqv[39];
	local[6]= NIL;
	w = argv[3];
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,3,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[297];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[22];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[298];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[9] = (w)->c.cons.cdr;
	w = local[2];
	local[0]= w;
BLK15552:
	ctx->vsp=local; return(local[0]);}

/*:enter-block*/
static pointer M15722compiler_enter_block(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[279];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[254];
	local[3]= fqv[299];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	w = argv[2];
	if (issymbol(w)) goto IF15760;
	local[2]= argv[0];
	local[3]= fqv[80];
	local[4]= fqv[300];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF15761;
IF15760:
	local[2]= NIL;
IF15761:
	local[2]= argv[2];
	local[3]= local[1];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	w = argv[0]->c.obj.iv[4];
	ctx->vsp=local+3;
	argv[0]->c.obj.iv[4] = cons(ctx,local[2],w);
	w = local[1];
	local[0]= w;
BLK15723:
	ctx->vsp=local; return(local[0]);}

/*:leave-block*/
static pointer M15792compiler_leave_block(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[4] = (w)->c.cons.cdr;
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK15793:
	ctx->vsp=local; return(local[0]);}

/*:block*/
static pointer M15816compiler_block(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[286];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	argv[2] = w;
	local[0]= argv[0];
	local[1]= fqv[233];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[257];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[287];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK15817:
	ctx->vsp=local; return(local[0]);}

/*:return-from*/
static pointer M15864compiler_return_from(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]!=NIL) goto IF15901;
	local[3]= argv[0];
	local[4]= fqv[6];
	local[5]= fqv[301];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF15902;
IF15901:
	local[3]= NIL;
IF15902:
	local[3]= argv[0];
	local[4]= fqv[22];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[1];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)GREATERP(ctx,2,local+3); /*>*/
	if (w==NIL) goto IF15921;
	local[3]= argv[0];
	local[4]= fqv[6];
	local[5]= fqv[302];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF15922;
IF15921:
	local[3]= NIL;
IF15922:
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[8])(ctx,1,local+3,&ftab[8],fqv[53]); /*fourth*/
	local[2] = w;
	local[3]= argv[0]->c.obj.iv[9];
	if (local[3]==NIL) goto AND15953;
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)GREQP(ctx,2,local+3); /*>=*/
	local[3]= w;
AND15953:
	local[1] = local[3];
	local[3]= loadglobal(fqv[23]);
	local[4]= fqv[218];
	local[5]= local[2];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= loadglobal(fqv[23]);
	local[4]= fqv[256];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[0]= w;
BLK15865:
	ctx->vsp=local; return(local[0]);}

/*:tagbody*/
static pointer M15991compiler_tagbody(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[279];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
WHL16035:
	if (local[2]==NIL) goto WHX16036;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	w = local[3];
	if (!!iscons(w)) goto IF16044;
	local[6]= local[3];
	local[7]= argv[0];
	local[8]= fqv[254];
	local[9]= fqv[303];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,3,local+6); /*list*/
	local[6]= w;
	w = argv[0]->c.obj.iv[5];
	ctx->vsp=local+7;
	argv[0]->c.obj.iv[5] = cons(ctx,local[6],w);
	local[6]= argv[0]->c.obj.iv[5];
	goto IF16045;
IF16044:
	local[6]= NIL;
IF16045:
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	goto WHL16035;
WHX16036:
	local[6]= NIL;
BLK16037:
WHL16093:
	if (argv[2]==NIL) goto WHX16094;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[6];
	local[5] = w;
	w = local[5];
	if (!!iscons(w)) goto CON16144;
	local[6]= loadglobal(fqv[23]);
	local[7]= fqv[257];
	local[8]= local[5];
	local[9]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+10;
	w=(pointer)ASSQ(ctx,2,local+8); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	goto CON16142;
CON16144:
	local[6]= argv[0];
	local[7]= fqv[22];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= loadglobal(fqv[23]);
	local[7]= fqv[24];
	local[8]= makeint(1);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	goto CON16142;
CON16164:
	local[6]= NIL;
CON16142:
	goto WHL16093;
WHX16094:
	local[6]= NIL;
BLK16095:
	local[6]= loadglobal(fqv[23]);
	local[7]= fqv[25];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	argv[0]->c.obj.iv[5] = local[0];
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK15992:
	ctx->vsp=local; return(local[0]);}

/*:go*/
static pointer M16195compiler_go(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]!=NIL) goto IF16230;
	local[3]= argv[0];
	local[4]= fqv[6];
	local[5]= fqv[304];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF16231;
IF16230:
	local[3]= NIL;
IF16231:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	local[3]= argv[0]->c.obj.iv[9];
	if (local[3]==NIL) goto AND16260;
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)GREQP(ctx,2,local+3); /*>=*/
	local[3]= w;
AND16260:
	local[2] = local[3];
	local[3]= loadglobal(fqv[23]);
	local[4]= fqv[305];
	local[5]= local[1];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= loadglobal(fqv[23]);
	local[4]= fqv[256];
	local[5]= local[0];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[0]= w;
BLK16196:
	ctx->vsp=local; return(local[0]);}

/*:function*/
static pointer M16294compiler_function(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	if (!issymbol(w)) goto IF16309;
	local[0]= argv[0];
	local[1]= fqv[38];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	if (fqv[45]!=local[1]) goto IF16331;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[52];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[8])(ctx,1,local+5,&ftab[8],fqv[53]); /*fourth*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF16332;
IF16331:
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[306];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
IF16332:
	w = local[1];
	local[0]= w;
	goto IF16310;
IF16309:
	local[0]= argv[0];
	local[1]= fqv[254];
	local[2]= fqv[307];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[294];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[295];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[1] = w;
	local[2]= argv[0];
	local[3]= fqv[296];
	local[4]= local[0];
	local[5]= argv[2];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,3,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0]= w;
IF16310:
	w = local[0];
	local[0]= w;
BLK16295:
	ctx->vsp=local; return(local[0]);}

/*:flet*/
static pointer M16419compiler_flet(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[8];
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= argv[2];
WHL16475:
	if (local[7]==NIL) goto WHX16476;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= argv[0];
	local[9]= fqv[254];
	local[10]= fqv[308];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[2] = w;
	local[8]= loadglobal(fqv[23]);
	local[9]= fqv[294];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= fqv[45];
	local[10]= loadglobal(fqv[23]);
	local[11]= fqv[279];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SUB1(ctx,1,local+10); /*1-*/
	local[10]= w;
	local[11]= argv[0]->c.obj.iv[1];
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,5,local+8); /*list*/
	local[8]= w;
	w = argv[0]->c.obj.iv[8];
	ctx->vsp=local+9;
	argv[0]->c.obj.iv[8] = cons(ctx,local[8],w);
	local[8]= argv[0];
	local[9]= fqv[295];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[3] = w;
	local[8]= local[3];
	w = local[4];
	ctx->vsp=local+9;
	local[4] = cons(ctx,local[8],w);
	local[8]= argv[0];
	local[9]= fqv[296];
	local[10]= local[2];
	local[11]= fqv[39];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,3,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	goto WHL16475;
WHX16476:
	local[8]= NIL;
BLK16477:
	w = NIL;
	if (argv[4]==NIL) goto IF16617;
	local[6]= local[4];
	local[7]= fqv[309];
	local[8]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+9;
	w=(*ftab[12])(ctx,3,local+6,&ftab[12],fqv[310]); /*send-all*/
	local[6]= w;
	goto IF16618;
IF16617:
	local[6]= NIL;
IF16618:
	local[6]= argv[0];
	local[7]= fqv[233];
	local[8]= argv[3];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+8;
	w=(pointer)NTHCDR(ctx,2,local+6); /*nthcdr*/
	argv[0]->c.obj.iv[8] = w;
	local[6]= loadglobal(fqv[23]);
	local[7]= fqv[82];
	local[8]= makeint(0);
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[0]= w;
BLK16420:
	ctx->vsp=local; return(local[0]);}

/*:change-flets*/
static pointer M16659compiler_change_flets(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[8] = argv[2];
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK16660:
	ctx->vsp=local; return(local[0]);}

/*:declare*/
static pointer M16681compiler_declare(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[2];
WHL16728:
	if (local[2]==NIL) goto WHX16729;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= local[3];
	if (fqv[41]!=local[4]) goto IF16794;
	local[4]= NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
WHL16823:
	if (local[5]==NIL) goto WHX16824;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= argv[0];
	local[7]= fqv[68];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[0] = w;
	local[6]= fqv[41];
	local[7]= local[6];
	w = local[0];
	w->c.obj.iv[2] = local[7];
	goto WHL16823;
WHX16824:
	local[6]= NIL;
BLK16825:
	w = NIL;
	local[4]= w;
	goto IF16795;
IF16794:
	local[4]= local[3];
	if (fqv[311]!=local[4]) goto IF16893;
	local[4]= NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
WHL16924:
	if (local[5]==NIL) goto WHX16925;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= argv[0];
	local[7]= fqv[68];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[0] = w;
	local[6]= local[0];
	local[7]= fqv[97];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	goto WHL16924;
WHX16925:
	local[6]= NIL;
BLK16926:
	w = NIL;
	local[4]= w;
	goto IF16894;
IF16893:
	local[4]= local[3];
	if (fqv[312]!=local[4]) goto IF17000;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
	ctx->vsp=local+6;
	w=(pointer)F6959def_function_type(ctx,2,local+4); /*def-function-type*/
	local[4]= w;
	goto IF17001;
IF17000:
	local[4]= local[3];
	w = fqv[313];
	if (memq(local[4],w)==NIL) goto IF17024;
	local[4]= NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
WHL17056:
	if (local[5]==NIL) goto WHX17057;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= argv[0];
	local[7]= fqv[68];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[0] = w;
	local[6]= local[0];
	local[7]= fqv[97];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	goto WHL17056;
WHX17057:
	local[6]= NIL;
BLK17058:
	w = NIL;
	local[4]= w;
	goto IF17025;
IF17024:
	local[4]= local[3];
	if (fqv[314]!=local[4]) goto IF17130;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	storeglobal(fqv[315],local[4]);
	goto IF17131;
IF17130:
	local[4]= local[3];
	if (fqv[316]!=local[4]) goto IF17150;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	storeglobal(fqv[182],local[4]);
	goto IF17151;
IF17150:
	local[4]= local[3];
	if (fqv[317]!=local[4]) goto IF17169;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	storeglobal(fqv[318],local[4]);
	goto IF17170;
IF17169:
	local[4]= local[3];
	if (fqv[319]!=local[4]) goto IF17189;
	local[4]= NIL;
	goto IF17190;
IF17189:
	local[4]= local[3];
	if (fqv[320]!=local[4]) goto IF17197;
	local[4]= NIL;
	goto IF17198;
IF17197:
	if (T==NIL) goto IF17205;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)F6943class_symbolp(ctx,1,local+4); /*class-symbolp*/
	if (w==NIL) goto CON17212;
	local[4]= NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
WHL17245:
	if (local[5]==NIL) goto WHX17246;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= argv[0];
	local[7]= fqv[68];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[0] = w;
	local[6]= local[0];
	local[7]= fqv[97];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	goto WHL17245;
WHX17246:
	local[6]= NIL;
BLK17247:
	w = NIL;
	local[4]= w;
	goto CON17210;
CON17212:
	local[4]= argv[0];
	local[5]= fqv[80];
	local[6]= fqv[321];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto CON17210;
CON17318:
	local[4]= NIL;
CON17210:
	goto IF17206;
IF17205:
	local[4]= NIL;
IF17206:
IF17198:
IF17190:
IF17170:
IF17151:
IF17131:
IF17025:
IF17001:
IF16894:
IF16795:
	w = local[4];
	goto WHL16728;
WHX16729:
	local[3]= NIL;
BLK16730:
	w = NIL;
	local[0]= w;
BLK16682:
	ctx->vsp=local; return(local[0]);}

/*:lambda*/
static pointer M17333compiler_lambda(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= makeint(0);
	local[2]= makeint(0);
	local[3]= makeint(0);
	local[4]= makeint(0);
	local[5]= fqv[322];
	w = argv[2];
	local[5]= memq(local[5],w);
	local[6]= fqv[323];
	w = argv[2];
	local[6]= memq(local[6],w);
	local[7]= fqv[324];
	w = argv[2];
	local[7]= memq(local[7],w);
	local[8]= fqv[325];
	w = argv[2];
	local[8]= memq(local[8],w);
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= makeint(0);
	local[15]= NIL;
	local[16]= fqv[326];
	w = argv[2];
	local[16]= memq(local[16],w);
	local[17]= argv[0]->c.obj.iv[9];
	local[18]= NIL;
	local[19]= NIL;
	local[20]= local[5];
	if (local[20]!=NIL) goto CON17453;
CON17455:
	local[20]= local[6];
	if (local[20]!=NIL) goto CON17453;
CON17459:
	local[20]= local[7];
	if (local[20]!=NIL) goto CON17453;
CON17463:
	local[20]= local[8];
	if (local[20]!=NIL) goto CON17453;
CON17467:
	local[20]= NIL;
CON17453:
	ctx->vsp=local+21;
	w=(pointer)LENGTH(ctx,1,local+20); /*length*/
	local[20]= w;
	local[21]= argv[2];
	ctx->vsp=local+22;
	w=(pointer)REVERSE(ctx,1,local+21); /*reverse*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)NTHCDR(ctx,2,local+20); /*nthcdr*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)REVERSE(ctx,1,local+20); /*reverse*/
	local[10] = w;
	local[20]= local[6];
	if (local[20]!=NIL) goto CON17488;
CON17490:
	local[20]= local[7];
	if (local[20]!=NIL) goto CON17488;
CON17494:
	local[20]= local[8];
	if (local[20]!=NIL) goto CON17488;
CON17498:
	local[20]= NIL;
CON17488:
	ctx->vsp=local+21;
	w=(pointer)LENGTH(ctx,1,local+20); /*length*/
	local[20]= w;
	local[21]= local[5];
	ctx->vsp=local+22;
	w=(pointer)REVERSE(ctx,1,local+21); /*reverse*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)NTHCDR(ctx,2,local+20); /*nthcdr*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)REVERSE(ctx,1,local+20); /*reverse*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	if (local[6]==NIL) goto CON17516;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	goto CON17514;
CON17516:
	local[20]= NIL;
CON17514:
	local[6] = local[20];
	local[20]= local[10];
	ctx->vsp=local+21;
	w=(pointer)LENGTH(ctx,1,local+20); /*length*/
	local[2] = w;
	local[20]= local[5];
	ctx->vsp=local+21;
	w=(pointer)LENGTH(ctx,1,local+20); /*length*/
	local[3] = w;
	ctx->vsp=local+20;
	local[20]= makeclosure(codevec,quotevec,CLO17541,env,argv,local);
	local[21]= local[5];
	ctx->vsp=local+22;
	w=(pointer)MAPCAR(ctx,2,local+20); /*mapcar*/
	local[11] = w;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	local[20]= local[7];
	ctx->vsp=local+21;
	w=(pointer)LENGTH(ctx,1,local+20); /*length*/
	local[4] = w;
	if (local[16]==NIL) goto IF17563;
	local[20]= local[7];
	local[21]= makeint(0);
	local[22]= local[4];
	ctx->vsp=local+23;
	w=(pointer)SUB1(ctx,1,local+22); /*1-*/
	local[4] = w;
	local[22]= local[4];
	ctx->vsp=local+23;
	w=(pointer)SUBSEQ(ctx,3,local+20); /*subseq*/
	local[7] = w;
	local[20]= local[7];
	goto IF17564;
IF17563:
	local[20]= NIL;
IF17564:
	if (local[5]==NIL) goto IF17590;
WHL17596:
	local[20]= local[1];
	local[21]= local[3];
	ctx->vsp=local+22;
	w=(pointer)LSEQP(ctx,2,local+20); /*<=*/
	if (w==NIL) goto WHX17597;
	local[20]= argv[0];
	local[21]= fqv[254];
	local[22]= fqv[327];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= w;
	w = local[0];
	ctx->vsp=local+21;
	local[0] = cons(ctx,local[20],w);
	local[20]= local[1];
	ctx->vsp=local+21;
	w=(pointer)ADD1(ctx,1,local+20); /*1+*/
	local[1] = w;
	goto WHL17596;
WHX17597:
	local[20]= NIL;
BLK17598:
	goto IF17591;
IF17590:
	if (local[6]==NIL) goto IF17630;
	local[20]= argv[0];
	local[21]= fqv[254];
	local[22]= fqv[328];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)LIST(ctx,1,local+20); /*list*/
	local[0] = w;
	local[20]= local[0];
	goto IF17631;
IF17630:
	local[20]= NIL;
IF17631:
IF17591:
	ctx->vsp=local+20;
	local[20]= makeclosure(codevec,quotevec,CLO17652,env,argv,local);
	local[21]= local[5];
	ctx->vsp=local+22;
	w=(pointer)MAPCAR(ctx,2,local+20); /*mapcar*/
	local[5] = w;
	local[20]= argv[0];
	local[21]= fqv[77];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,2,local+20); /*send*/
	if (local[7]==NIL) goto IF17667;
	local[20]= NIL;
	local[21]= NIL;
	local[22]= NIL;
	local[23]= NIL;
	local[24]= local[7];
WHL17703:
	if (local[24]==NIL) goto WHX17704;
	w=local[24];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25]= (w)->c.cons.car;
	w=local[24];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24] = (w)->c.cons.cdr;
	w = local[25];
	local[23] = w;
	local[25]= local[23];
	ctx->vsp=local+26;
	w=(pointer)LISTP(ctx,1,local+25); /*listp*/
	if (w==NIL) goto CON17754;
	w=local[23];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20] = (w)->c.cons.car;
	w=local[23];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23] = (w)->c.cons.car;
	local[25]= local[23];
	ctx->vsp=local+26;
	w=(pointer)LISTP(ctx,1,local+25); /*listp*/
	if (w==NIL) goto CON17784;
	w=local[23];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21] = (w)->c.cons.car;
	w=local[23];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22] = (w)->c.cons.car;
	local[25]= local[21];
	ctx->vsp=local+26;
	w=(*ftab[5])(ctx,1,local+25,&ftab[5],fqv[30]); /*keywordp*/
	if (w!=NIL) goto IF17812;
	local[25]= argv[0];
	local[26]= fqv[6];
	local[27]= fqv[329];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,3,local+25); /*send*/
	local[25]= w;
	goto IF17813;
IF17812:
	local[25]= NIL;
IF17813:
	if (local[22]==NIL) goto AND17828;
	w = local[22];
	if (!issymbol(w)) goto AND17828;
	goto IF17826;
AND17828:
	local[25]= argv[0];
	local[26]= fqv[6];
	local[27]= fqv[330];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,3,local+25); /*send*/
	local[25]= w;
	goto IF17827;
IF17826:
	local[25]= NIL;
IF17827:
	goto CON17782;
CON17784:
	local[22] = local[23];
	local[25]= local[22];
	ctx->vsp=local+26;
	w=(*ftab[13])(ctx,1,local+25,&ftab[13],fqv[331]); /*symbol-name*/
	local[25]= w;
	local[26]= loadglobal(fqv[332]);
	ctx->vsp=local+27;
	w=(pointer)INTERN(ctx,2,local+25); /*intern*/
	local[21] = w;
	local[25]= local[21];
	goto CON17782;
CON17841:
	local[25]= NIL;
CON17782:
	goto CON17752;
CON17754:
	local[20] = NIL;
	local[22] = local[23];
	local[25]= local[22];
	ctx->vsp=local+26;
	w=(*ftab[13])(ctx,1,local+25,&ftab[13],fqv[331]); /*symbol-name*/
	local[25]= w;
	local[26]= loadglobal(fqv[332]);
	ctx->vsp=local+27;
	w=(pointer)INTERN(ctx,2,local+25); /*intern*/
	local[21] = w;
	local[25]= local[21];
	goto CON17752;
CON17860:
	local[25]= NIL;
CON17752:
	local[25]= local[21];
	w = local[12];
	ctx->vsp=local+26;
	local[12] = cons(ctx,local[25],w);
	local[25]= local[22];
	w = local[9];
	ctx->vsp=local+26;
	local[9] = cons(ctx,local[25],w);
	local[25]= local[20];
	w = local[13];
	ctx->vsp=local+26;
	local[13] = cons(ctx,local[25],w);
	goto WHL17703;
WHX17704:
	local[25]= NIL;
BLK17705:
	w = NIL;
	local[23]= local[12];
	ctx->vsp=local+24;
	w=(pointer)NREVERSE(ctx,1,local+23); /*nreverse*/
	local[23]= local[9];
	ctx->vsp=local+24;
	w=(pointer)NREVERSE(ctx,1,local+23); /*nreverse*/
	local[23]= local[13];
	ctx->vsp=local+24;
	w=(pointer)NREVERSE(ctx,1,local+23); /*nreverse*/
	local[23]= local[12];
	ctx->vsp=local+24;
	w=(pointer)LENGTH(ctx,1,local+23); /*length*/
	local[23]= w;
	w = makeint(128);
	if ((eusinteger_t)local[23] < (eusinteger_t)w) goto IF17921;
	local[23]= argv[0];
	local[24]= fqv[6];
	local[25]= fqv[333];
	local[26]= local[12];
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,4,local+23); /*send*/
	local[23]= w;
	goto IF17922;
IF17921:
	local[23]= NIL;
IF17922:
	w = local[23];
	local[20]= w;
	goto IF17668;
IF17667:
	local[20]= NIL;
IF17668:
WHL17937:
	if (argv[3]==NIL) goto WHX17938;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!iscons(w)) goto WHX17938;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	if (fqv[276]!=local[20]) goto WHX17938;
	local[20]= argv[0];
	local[21]= fqv[277];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[3] = (w)->c.cons.cdr;
	w = local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.cdr;
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	goto WHL17937;
WHX17938:
	local[20]= NIL;
BLK17939:
	local[20]= loadglobal(fqv[23]);
	local[21]= fqv[334];
	local[22]= local[2];
	local[23]= local[3];
	if (local[6]==NIL) goto IF18016;
	local[24]= makeint(1);
	goto IF18017;
IF18016:
	if (local[7]==NIL) goto IF18022;
	local[24]= local[4];
	goto IF18023;
IF18022:
	local[24]= makeint(0);
IF18023:
IF18017:
	ctx->vsp=local+25;
	w=(pointer)PLUS(ctx,2,local+23); /*+*/
	local[23]= w;
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,4,local+20); /*send*/
	local[1] = makeint(0);
	local[20]= NIL;
	local[21]= local[10];
WHL18055:
	if (local[21]==NIL) goto WHX18056;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21] = (w)->c.cons.cdr;
	w = local[22];
	local[20] = w;
	local[22]= argv[0];
	local[23]= fqv[278];
	local[24]= local[20];
	local[25]= fqv[72];
	local[26]= local[1];
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,5,local+22); /*send*/
	local[22]= local[1];
	ctx->vsp=local+23;
	w=(pointer)ADD1(ctx,1,local+22); /*1+*/
	local[1] = w;
	goto WHL18055;
WHX18056:
	local[22]= NIL;
BLK18057:
	w = NIL;
WHL18127:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX18128;
	local[20]= loadglobal(fqv[23]);
	local[21]= fqv[335];
	local[22]= local[1];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,4,local+20); /*send*/
	local[20]= argv[0];
	local[21]= fqv[22];
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[22];
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= loadglobal(fqv[23]);
	local[21]= fqv[257];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[22];
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= argv[0];
	local[21]= fqv[278];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[22];
	local[22]= w;
	local[23]= fqv[70];
	local[24]= loadglobal(fqv[23]);
	local[25]= fqv[279];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,2,local+24); /*send*/
	local[24]= w;
	ctx->vsp=local+25;
	w=(pointer)SUB1(ctx,1,local+24); /*1-*/
	local[24]= w;
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,5,local+20); /*send*/
	local[20]= local[1];
	ctx->vsp=local+21;
	w=(pointer)ADD1(ctx,1,local+20); /*1+*/
	local[1] = w;
	goto WHL18127;
WHX18128:
	local[20]= NIL;
BLK18129:
	if (local[0]==NIL) goto IF18294;
	local[20]= loadglobal(fqv[23]);
	local[21]= fqv[257];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[22];
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= w;
	goto IF18295;
IF18294:
	local[20]= NIL;
IF18295:
	if (local[6]==NIL) goto CON18346;
	local[20]= loadglobal(fqv[23]);
	local[21]= fqv[336];
	local[22]= local[2];
	local[23]= local[3];
	ctx->vsp=local+24;
	w=(pointer)PLUS(ctx,2,local+22); /*+*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= argv[0];
	local[21]= fqv[278];
	local[22]= local[6];
	local[23]= fqv[70];
	local[24]= loadglobal(fqv[23]);
	local[25]= fqv[279];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,2,local+24); /*send*/
	local[24]= w;
	ctx->vsp=local+25;
	w=(pointer)SUB1(ctx,1,local+24); /*1-*/
	local[24]= w;
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,5,local+20); /*send*/
	local[20]= w;
	goto CON18344;
CON18346:
	local[20]= local[3];
	local[21]= makeint(0);
	ctx->vsp=local+22;
	w=(pointer)GREATERP(ctx,2,local+20); /*>*/
	if (w==NIL) goto CON18376;
	if (local[7]!=NIL) goto CON18376;
	local[20]= loadglobal(fqv[23]);
	local[21]= fqv[337];
	local[22]= local[1];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= w;
	goto CON18344;
CON18376:
	local[20]= NIL;
CON18344:
	if (local[7]==NIL) goto IF18394;
	local[20]= loadglobal(fqv[23]);
	local[21]= fqv[279];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,2,local+20); /*send*/
	local[14] = w;
	local[20]= loadglobal(fqv[23]);
	local[21]= fqv[338];
	local[22]= local[12];
	local[23]= loadglobal(fqv[179]);
	ctx->vsp=local+24;
	w=(pointer)COERCE(ctx,2,local+22); /*coerce*/
	local[22]= w;
	local[23]= local[2];
	local[24]= local[3];
	ctx->vsp=local+25;
	w=(pointer)PLUS(ctx,2,local+23); /*+*/
	local[23]= w;
	local[24]= local[4];
	local[25]= local[16];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,6,local+20); /*send*/
	local[20]= makeint(0);
	local[21]= local[4];
WHL18453:
	local[22]= local[20];
	w = local[21];
	if ((eusinteger_t)local[22] >= (eusinteger_t)w) goto WHX18454;
	local[22]= argv[0];
	local[23]= fqv[254];
	local[24]= fqv[339];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[0] = w;
	local[22]= loadglobal(fqv[23]);
	local[23]= fqv[340];
	local[24]= local[20];
	local[25]= local[0];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,4,local+22); /*send*/
	local[22]= argv[0];
	local[23]= fqv[22];
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24]= (w)->c.cons.car;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13] = (w)->c.cons.cdr;
	w = local[24];
	local[24]= w;
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[22];
	local[18] = w;
	local[22]= argv[0];
	local[23]= fqv[281];
	local[24]= local[18];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	if (w==NIL) goto CON18565;
	local[22]= argv[0];
	local[23]= fqv[254];
	local[24]= fqv[341];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[19] = w;
	local[22]= loadglobal(fqv[23]);
	local[23]= fqv[256];
	local[24]= local[19];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[22]= loadglobal(fqv[23]);
	local[23]= fqv[257];
	local[24]= local[0];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[22]= loadglobal(fqv[23]);
	local[23]= fqv[271];
	local[24]= makeint(1);
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[22]= loadglobal(fqv[23]);
	local[23]= fqv[52];
	local[24]= local[20];
	local[25]= local[14];
	ctx->vsp=local+26;
	w=(pointer)PLUS(ctx,2,local+24); /*+*/
	local[24]= w;
	local[25]= makeint(0);
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,4,local+22); /*send*/
	local[22]= loadglobal(fqv[23]);
	local[23]= fqv[257];
	local[24]= local[19];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[22]= argv[0];
	local[23]= fqv[278];
	local[24]= local[18];
	local[25]= fqv[70];
	local[26]= local[14];
	local[27]= local[20];
	ctx->vsp=local+28;
	w=(pointer)PLUS(ctx,2,local+26); /*+*/
	local[26]= w;
	local[27]= T;
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,6,local+22); /*send*/
	local[22]= w;
	goto CON18563;
CON18565:
	local[22]= argv[0];
	local[23]= fqv[278];
	local[24]= local[18];
	local[25]= fqv[70];
	local[26]= local[14];
	local[27]= local[20];
	ctx->vsp=local+28;
	w=(pointer)PLUS(ctx,2,local+26); /*+*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,5,local+22); /*send*/
	local[22]= loadglobal(fqv[23]);
	local[23]= fqv[104];
	local[24]= local[14];
	local[25]= local[20];
	ctx->vsp=local+26;
	w=(pointer)PLUS(ctx,2,local+24); /*+*/
	local[24]= w;
	local[25]= makeint(0);
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,4,local+22); /*send*/
	local[22]= loadglobal(fqv[23]);
	local[23]= fqv[257];
	local[24]= local[0];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[22]= w;
	goto CON18563;
CON18635:
	local[22]= NIL;
CON18563:
	local[22]= local[20];
	ctx->vsp=local+23;
	w=(pointer)ADD1(ctx,1,local+22); /*1+*/
	local[20] = w;
	goto WHL18453;
WHX18454:
	local[22]= NIL;
BLK18455:
	w = NIL;
	local[20]= w;
	goto IF18395;
IF18394:
	local[20]= NIL;
IF18395:
	local[20]= NIL;
	local[21]= local[8];
WHL18698:
	if (local[21]==NIL) goto WHX18699;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21] = (w)->c.cons.cdr;
	w = local[22];
	local[20] = w;
	w = local[20];
	if (!iscons(w)) goto IF18747;
	local[22]= argv[0];
	local[23]= fqv[22];
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24]= (w)->c.cons.car;
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[22]= w;
	goto IF18748;
IF18747:
	local[22]= argv[0];
	local[23]= fqv[22];
	local[24]= NIL;
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[22]= w;
IF18748:
	local[22]= argv[0];
	local[23]= fqv[278];
	local[24]= local[20];
	ctx->vsp=local+25;
	w=(pointer)LISTP(ctx,1,local+24); /*listp*/
	if (w==NIL) goto IF18775;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24]= (w)->c.cons.car;
	goto IF18776;
IF18775:
	local[24]= local[20];
IF18776:
	local[25]= fqv[70];
	local[26]= loadglobal(fqv[23]);
	local[27]= fqv[279];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,2,local+26); /*send*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)SUB1(ctx,1,local+26); /*1-*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,5,local+22); /*send*/
	goto WHL18698;
WHX18699:
	local[22]= NIL;
BLK18700:
	w = NIL;
	local[20]= argv[0];
	local[21]= fqv[233];
	local[22]= argv[3];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	argv[0]->c.obj.iv[9] = local[17];
	local[20]= argv[0];
	local[21]= fqv[280];
	local[22]= T;
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[0]= w;
BLK17334:
	ctx->vsp=local; return(local[0]);}

/*:lambda-block*/
static pointer M18823compiler_lambda_block(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	ctx->vsp=local+0;
	w=(pointer)RUNTIME(ctx,0,local+0); /*unix:runtime*/
	local[0]= w;
	local[1]= NIL;
	if (loadglobal(fqv[342])==NIL) goto IF18858;
	local[2]= T;
	local[3]= fqv[343];
	local[4]= makeint(27);
	local[5]= argv[2];
	local[6]= makeint(27);
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,5,local+2); /*format*/
	local[2]= w;
	goto IF18859;
IF18858:
	local[2]= NIL;
IF18859:
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,0,local+2); /*finish-output*/
	local[2]= argv[0];
	local[3]= fqv[286];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[1] = w;
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[17];
	local[4]= argv[5];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[344];
	local[4]= argv[3];
	local[5]= argv[4];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[257];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[345];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[287];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	if (loadglobal(fqv[342])==NIL) goto IF18919;
	local[2]= T;
	local[3]= fqv[346];
	local[4]= makeflt(1.66700000e-02);
	ctx->vsp=local+5;
	w=(pointer)RUNTIME(ctx,0,local+5); /*unix:runtime*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	goto IF18920;
IF18919:
	local[2]= NIL;
IF18920:
	w = argv[5];
	local[0]= w;
BLK18824:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO17541(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto IF18949;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	goto IF18950;
IF18949:
	local[0]= NIL;
IF18950:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO17652(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto IF18974;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	goto IF18975;
IF18974:
	local[0]= argv[0];
IF18975:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:def-user-entry*/
static pointer M19014compiler_def_user_entry(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[347]!=local[0]) goto IF19029;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= argv[0];
	local[2]= fqv[254];
	local[3]= fqv[348];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[14])(ctx,1,local+4,&ftab[14],fqv[21]); /*lisp::gencname-tail*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	local[2]= local[0];
	local[3]= local[1];
	local[4]= fqv[349];
	ctx->vsp=local+5;
	w=(pointer)PUTPROP(ctx,3,local+2); /*putprop*/
	local[2]= local[0];
	w = loadglobal(fqv[350]);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	storeglobal(fqv[350],local[2]);
	w = local[2];
	local[0]= w;
	goto IF19030;
IF19029:
	local[0]= NIL;
IF19030:
	w = local[0];
	local[0]= w;
BLK19015:
	ctx->vsp=local; return(local[0]);}

/*:defun*/
static pointer M19086compiler_defun(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[3];
	local[1]= fqv[349];
	ctx->vsp=local+2;
	w=(pointer)GETPROP(ctx,2,local+0); /*get*/
	local[0]= w;
	local[1]= NIL;
	if (local[0]!=NIL) goto IF19124;
	local[2]= argv[0];
	local[3]= fqv[254];
	local[4]= fqv[351];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0] = w;
	local[2]= local[0];
	goto IF19125;
IF19124:
	local[2]= NIL;
IF19125:
	local[2]= loadglobal(fqv[315]);
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto IF19142;
	local[2]= argv[3];
	local[3]= local[0];
	local[4]= fqv[349];
	ctx->vsp=local+5;
	w=(pointer)PUTPROP(ctx,3,local+2); /*putprop*/
	local[2]= argv[3];
	w = loadglobal(fqv[350]);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	storeglobal(fqv[350],local[2]);
	goto IF19143;
IF19142:
	local[2]= NIL;
IF19143:
	w=argv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!isstring(w)) goto IF19171;
	w=argv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF19171;
	w=argv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[5] = (w)->c.cons.cdr;
	w = local[2];
	local[2]= w;
	goto IF19172;
IF19171:
	local[2]= NIL;
	local[3]= fqv[352];
	local[4]= argv[4];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
IF19172:
	local[1] = local[2];
	local[2]= argv[0];
	local[3]= fqv[353];
	local[4]= argv[3];
	local[5]= argv[4];
	local[6]= argv[5];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[354];
	local[4]= argv[2];
	local[5]= local[0];
	local[6]= argv[3];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,4,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0]= w;
BLK19087:
	ctx->vsp=local; return(local[0]);}

/*:defmethod*/
static pointer M19252compiler_defmethod(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= local[6];
	ctx->vsp=local+8;
	w=(pointer)F6951object_variable_names(ctx,1,local+7); /*object-variable-names*/
	local[7]= w;
	local[8]= makeint(0);
	local[9]= NIL;
	local[10]= NIL;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	local[11]= argv[0];
	local[12]= fqv[77];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= NIL;
	local[12]= local[7];
WHL19337:
	if (local[12]==NIL) goto WHX19338;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12] = (w)->c.cons.cdr;
	w = local[13];
	local[11] = w;
	local[13]= argv[0];
	local[14]= fqv[68];
	local[15]= local[11];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[9] = w;
	local[13]= fqv[355];
	*(ovafptr(local[9],fqv[87])) = local[13];
	local[13]= local[8];
	*(ovafptr(local[9],fqv[91])) = local[13];
	local[13]= argv[0]->c.obj.iv[1];
	*(ovafptr(local[9],fqv[92])) = local[13];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(pointer)SYMVALUE(ctx,1,local+13); /*symbol-value*/
	local[13]= w;
	local[14]= local[11];
	ctx->vsp=local+15;
	w=(pointer)F6953object_variable_type(ctx,2,local+13); /*object-variable-type*/
	local[13]= w;
	local[14]= w;
	*(ovafptr(local[9],fqv[311])) = local[14];
	local[13]= local[8];
	ctx->vsp=local+14;
	w=(pointer)ADD1(ctx,1,local+13); /*1+*/
	local[8] = w;
	goto WHL19337;
WHX19338:
	local[13]= NIL;
BLK19339:
	w = NIL;
WHL19428:
	if (argv[2]==NIL) goto WHX19429;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[11];
	local[0] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	local[11]= fqv[356];
	local[12]= fqv[357];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[2] = cons(ctx,local[11],w);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	local[11]= argv[0];
	local[12]= fqv[254];
	local[13]= fqv[358];
	local[14]= local[6];
	local[15]= local[1];
	ctx->vsp=local+16;
	w=(*ftab[14])(ctx,2,local+14,&ftab[14],fqv[21]); /*lisp::gencname-tail*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,4,local+11); /*send*/
	local[4] = w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!isstring(w)) goto IF19529;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF19529;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[11];
	local[11]= w;
	goto IF19530;
IF19529:
	local[11]= NIL;
	local[12]= fqv[359];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,3,local+11); /*format*/
	local[11]= w;
IF19530:
	local[10] = local[11];
	local[11]= argv[0];
	local[12]= fqv[353];
	local[13]= local[1];
	local[14]= local[2];
	local[15]= local[3];
	local[16]= local[4];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,6,local+11); /*send*/
	local[11]= argv[0];
	local[12]= fqv[354];
	local[13]= fqv[360];
	local[14]= local[6];
	local[15]= local[1];
	local[16]= local[4];
	local[17]= local[10];
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,5,local+13); /*list*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	goto WHL19428;
WHX19429:
	local[11]= NIL;
BLK19430:
	local[6] = NIL;
	local[11]= argv[0];
	local[12]= fqv[280];
	local[13]= NIL;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[0]= w;
BLK19253:
	ctx->vsp=local; return(local[0]);}

/*:add-initcode*/
static pointer M19651compiler_add_initcode(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	w = argv[0]->c.obj.iv[7];
	ctx->vsp=local+1;
	argv[0]->c.obj.iv[7] = cons(ctx,local[0],w);
	w = argv[0]->c.obj.iv[7];
	local[0]= w;
BLK19652:
	ctx->vsp=local; return(local[0]);}

/*:add-closure*/
static pointer M19677compiler_add_closure(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	w = argv[0]->c.obj.iv[6];
	ctx->vsp=local+1;
	argv[0]->c.obj.iv[6] = cons(ctx,local[0],w);
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK19678:
	ctx->vsp=local; return(local[0]);}

/*:closure-level*/
static pointer M19703compiler_closure_level(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK19704:
	ctx->vsp=local; return(local[0]);}

/*:compile-a-closure*/
static pointer M19729compiler_compile_a_closure(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	if (loadglobal(fqv[51])==NIL) goto IF19746;
	local[0]= T;
	local[1]= fqv[361];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto IF19747;
IF19746:
	local[0]= NIL;
IF19747:
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	argv[0]->c.obj.iv[6] = NIL;
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[362];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[17];
	local[4]= argv[2];
	local[5]= fqv[363];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[344];
	local[4]= local[0];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[345];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[364];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[0]= w;
BLK19730:
	ctx->vsp=local; return(local[0]);}

/*:compile-closures*/
static pointer M19820compiler_compile_closures(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+2;
	w=(pointer)REVERSE(ctx,1,local+1); /*reverse*/
	local[1]= w;
WHL19852:
	if (local[1]==NIL) goto WHX19853;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[365];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	goto WHL19852;
WHX19853:
	local[2]= NIL;
BLK19854:
	w = NIL;
	argv[0]->c.obj.iv[6] = NIL;
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK19821:
	ctx->vsp=local; return(local[0]);}

/*:toplevel-eval*/
static pointer M19936compiler_toplevel_eval(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[6] = NIL;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= local[0];
	local[2]= local[1];
	w = fqv[366];
	if (memq(local[2],w)==NIL) goto IF19983;
	local[2]= argv[0];
	local[3]= fqv[367];
	local[4]= local[0];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(*ftab[15])(ctx,1,local+7,&ftab[15],fqv[368]); /*cdddr*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[364];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	goto IF19984;
IF19983:
	local[2]= local[1];
	w = fqv[369];
	if (memq(local[2],w)==NIL) goto IF20029;
	local[2]= argv[0];
	local[3]= fqv[370];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[364];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	goto IF20030;
IF20029:
	local[2]= local[1];
	w = fqv[371];
	if (memq(local[2],w)==NIL) goto IF20059;
	local[2]= NIL;
	goto IF20060;
IF20059:
	if (T==NIL) goto IF20070;
	local[2]= argv[0];
	local[3]= fqv[354];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF20071;
IF20070:
	local[2]= NIL;
IF20071:
IF20060:
IF20030:
IF19984:
	w = local[2];
	local[0]= w;
BLK19937:
	ctx->vsp=local; return(local[0]);}

/*:toplevel*/
static pointer M20083compiler_toplevel(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT20087;}
	local[0]= NIL;
ENT20087:
ENT20086:
	if (n>5) maerror();
	if (local[0]!=NIL) goto IF20107;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[57];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF20108;
IF20107:
	local[1]= NIL;
IF20108:
	w = argv[2];
	if (!!iscons(w)) goto IF20119;
	w = NIL;
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK20084;
	goto IF20120;
IF20119:
	local[1]= NIL;
IF20120:
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,1,local+1,&ftab[16],fqv[372]); /*macro-function*/
	if (w==NIL) goto IF20129;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[44]); /*macroexpand*/
	argv[2] = w;
	local[1]= argv[2];
	goto IF20130;
IF20129:
	local[1]= NIL;
IF20130:
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	if (fqv[373]!=local[1]) goto CON20153;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= NIL;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
WHL20205:
	if (local[3]==NIL) goto WHX20206;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= fqv[374];
	w = local[1];
	if (memq(local[4],w)==NIL) goto IF20255;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)EVAL(ctx,1,local+4); /*eval*/
	local[4]= w;
	goto IF20256;
IF20255:
	local[4]= NIL;
IF20256:
	local[4]= fqv[375];
	w = local[1];
	if (memq(local[4],w)==NIL) goto IF20274;
	local[4]= argv[0];
	local[5]= fqv[376];
	local[6]= local[2];
	local[7]= NIL;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[4]= w;
	goto IF20275;
IF20274:
	local[4]= NIL;
IF20275:
	goto WHL20205;
WHX20206:
	local[4]= NIL;
BLK20207:
	w = NIL;
	local[1]= w;
	goto CON20151;
CON20153:
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	if (fqv[377]!=local[1]) goto CON20298;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[1];
WHL20346:
	if (argv[2]==NIL) goto WHX20347;
	local[1]= argv[0];
	local[2]= fqv[376];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[3];
	local[3]= w;
	local[4]= argv[3];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	goto WHL20346;
WHX20347:
	local[1]= NIL;
BLK20348:
	goto CON20151;
CON20298:
	if (argv[3]==NIL) goto IF20399;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)EVAL(ctx,1,local+1); /*eval*/
	local[1]= w;
	goto IF20400;
IF20399:
	local[1]= NIL;
IF20400:
	if (local[0]==NIL) goto IF20409;
	local[1]= argv[0];
	local[2]= fqv[378];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF20410;
IF20409:
	local[1]= argv[0];
	local[2]= fqv[379];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
IF20410:
	goto CON20151;
CON20395:
	local[1]= NIL;
CON20151:
	w = local[1];
	local[0]= w;
BLK20084:
	ctx->vsp=local; return(local[0]);}

/*:toplevel-execution*/
static pointer M20427compiler_toplevel_execution(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= local[0];
	local[2]= local[1];
	if (fqv[347]!=local[2]) goto IF20468;
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[367];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(*ftab[8])(ctx,1,local+6,&ftab[8],fqv[53]); /*fourth*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	local[2]= w;
	goto IF20469;
IF20468:
	local[2]= local[1];
	if (fqv[380]!=local[2]) goto IF20500;
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[381];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(*ftab[8])(ctx,1,local+6,&ftab[8],fqv[53]); /*fourth*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	local[2]= w;
	goto IF20501;
IF20500:
	local[2]= local[1];
	if (fqv[360]!=local[2]) goto IF20532;
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[370];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(*ftab[8])(ctx,1,local+6,&ftab[8],fqv[53]); /*fourth*/
	local[6]= w;
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(*ftab[9])(ctx,1,local+7,&ftab[9],fqv[54]); /*fifth*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[2]= w;
	goto IF20533;
IF20532:
	if (T==NIL) goto IF20567;
	local[2]= argv[0];
	local[3]= fqv[22];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[24];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF20568;
IF20567:
	local[2]= NIL;
IF20568:
IF20533:
IF20501:
IF20469:
	w = local[2];
	local[0]= w;
BLK20428:
	ctx->vsp=local; return(local[0]);}

/*:compile-file*/
static pointer M20589compiler_compile_file(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[382], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY20611;
	local[0] = fqv[383];
KEY20611:
	if (n & (1<<1)) goto KEY20616;
	local[1] = loadglobal(fqv[315]);
KEY20616:
	if (n & (1<<2)) goto KEY20622;
	local[2] = makeint(2);
KEY20622:
	if (n & (1<<3)) goto KEY20627;
	local[3] = loadglobal(fqv[182]);
KEY20627:
	if (n & (1<<4)) goto KEY20633;
	local[4] = loadglobal(fqv[384]);
KEY20633:
	if (n & (1<<5)) goto KEY20640;
	local[5] = loadglobal(fqv[385]);
KEY20640:
	if (n & (1<<6)) goto KEY20647;
	local[6] = loadglobal(fqv[342]);
KEY20647:
	if (n & (1<<7)) goto KEY20653;
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(*ftab[17])(ctx,1,local+9,&ftab[17],fqv[386]); /*pathname-name*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[14])(ctx,1,local+9,&ftab[14],fqv[21]); /*lisp::gencname-tail*/
	local[7] = w;
KEY20653:
	if (n & (1<<8)) goto KEY20664;
	local[8] = NIL;
KEY20664:
	w = local[2];
	if (!isint(w)) goto IF20673;
	local[9]= local[2];
	local[10]= makeint(0);
	ctx->vsp=local+11;
	w=(pointer)GREATERP(ctx,2,local+9); /*>*/
	if (w==NIL) goto IF20673;
	local[9]= NIL;
	local[10]= fqv[387];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,3,local+9); /*format*/
	local[9]= w;
	storeglobal(fqv[388],w);
	goto IF20674;
IF20673:
	local[9]= fqv[389];
	storeglobal(fqv[388],local[9]);
IF20674:
	storeglobal(fqv[315],local[1]);
	storeglobal(fqv[182],local[3]);
	local[9]= local[6];
	storeglobal(fqv[342],local[9]);
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(*ftab[18])(ctx,1,local+9,&ftab[18],fqv[390]); /*pathname*/
	local[9]= w;
	local[10]= fqv[391];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	if (w!=NIL) goto IF20709;
	local[9]= fqv[392];
	local[10]= argv[2];
	ctx->vsp=local+11;
	w=(*ftab[19])(ctx,2,local+9,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[20])(ctx,1,local+9,&ftab[20],fqv[394]); /*namestring*/
	argv[2] = w;
	local[9]= argv[2];
	goto IF20710;
IF20709:
	local[9]= NIL;
IF20710:
	if (local[8]==NIL) goto IF20739;
	local[9]= local[8];
	ctx->vsp=local+10;
	w=(*ftab[18])(ctx,1,local+9,&ftab[18],fqv[390]); /*pathname*/
	local[8] = w;
	local[9]= local[8];
	local[10]= argv[2];
	ctx->vsp=local+11;
	w=(*ftab[19])(ctx,2,local+9,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[8] = w;
	local[9]= fqv[395];
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(*ftab[19])(ctx,2,local+9,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[8] = w;
	local[9]= local[8];
	goto IF20740;
IF20739:
	local[9]= NIL;
IF20740:
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= fqv[396];
	local[15]= argv[2];
	ctx->vsp=local+16;
	w=(*ftab[19])(ctx,2,local+14,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[14]= w;
	local[15]= fqv[397];
	local[16]= argv[2];
	ctx->vsp=local+17;
	w=(*ftab[19])(ctx,2,local+15,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[15]= w;
	local[16]= fqv[398];
	local[17]= argv[2];
	ctx->vsp=local+18;
	w=(*ftab[19])(ctx,2,local+16,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[16]= w;
	if (local[8]==NIL) goto IF20816;
	local[17]= local[8];
	goto IF20817;
IF20816:
	local[17]= fqv[399];
	local[18]= argv[2];
	ctx->vsp=local+19;
	w=(*ftab[19])(ctx,2,local+17,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[17]= w;
IF20817:
	if (local[8]==NIL) goto IF20829;
	local[18]= fqv[400];
	local[19]= local[8];
	ctx->vsp=local+20;
	w=(*ftab[19])(ctx,2,local+18,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[18]= w;
	goto IF20830;
IF20829:
	local[18]= fqv[401];
	local[19]= argv[2];
	ctx->vsp=local+20;
	w=(*ftab[19])(ctx,2,local+18,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[18]= w;
IF20830:
	if (local[8]==NIL) goto IF20844;
	local[19]= fqv[402];
	local[20]= local[8];
	ctx->vsp=local+21;
	w=(*ftab[19])(ctx,2,local+19,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[19]= w;
	goto IF20845;
IF20844:
	local[19]= fqv[403];
	local[20]= argv[2];
	ctx->vsp=local+21;
	w=(*ftab[19])(ctx,2,local+19,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[19]= w;
IF20845:
	local[20]= loadglobal(fqv[404]);
	local[21]= argv[2];
	ctx->vsp=local+22;
	w=(*ftab[18])(ctx,1,local+21,&ftab[18],fqv[390]); /*pathname*/
	local[21]= w;
	local[22]= fqv[405];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,2,local+21); /*send*/
	local[21]= w;
	local[22]= makeint(2);
	ctx->vsp=local+23;
	w=(pointer)ACCESS(ctx,2,local+21); /*unix:access*/
	local[21]= w;
	if (T==local[21]) goto IF20865;
	local[21]= fqv[406];
	local[22]= argv[2];
	local[23]= local[8];
	local[24]= fqv[405];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,2,local+23); /*send*/
	local[23]= w;
	ctx->vsp=local+24;
	w=(*ftab[1])(ctx,3,local+21,&ftab[1],fqv[14]); /*warn*/
	local[21]= fqv[407];
	local[22]= local[8];
	ctx->vsp=local+23;
	w=(*ftab[19])(ctx,2,local+21,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[14] = w;
	local[21]= fqv[408];
	local[22]= local[8];
	ctx->vsp=local+23;
	w=(*ftab[19])(ctx,2,local+21,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[15] = w;
	local[21]= fqv[409];
	local[22]= local[8];
	ctx->vsp=local+23;
	w=(*ftab[19])(ctx,2,local+21,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[16] = w;
	local[21]= local[16];
	goto IF20866;
IF20865:
	local[21]= NIL;
IF20866:
	local[21]= argv[2];
	ctx->vsp=local+22;
	w=(*ftab[21])(ctx,1,local+21,&ftab[21],fqv[410]); /*probe-file*/
	if (w!=NIL) goto IF20911;
	local[21]= fqv[411];
	local[22]= argv[2];
	ctx->vsp=local+23;
	w=(*ftab[19])(ctx,2,local+21,&ftab[19],fqv[393]); /*merge-pathnames*/
	argv[2] = w;
	local[21]= argv[2];
	ctx->vsp=local+22;
	w=(*ftab[21])(ctx,1,local+21,&ftab[21],fqv[410]); /*probe-file*/
	if (w!=NIL) goto IF20932;
	local[21]= fqv[412];
	local[22]= argv[2];
	ctx->vsp=local+23;
	w=(pointer)SIGERROR(ctx,2,local+21); /*error*/
	local[21]= w;
	goto IF20933;
IF20932:
	local[21]= NIL;
IF20933:
	goto IF20912;
IF20911:
	local[21]= NIL;
IF20912:
	local[21]= fqv[413];
	local[22]= argv[2];
	ctx->vsp=local+23;
	w=(*ftab[20])(ctx,1,local+22,&ftab[20],fqv[394]); /*namestring*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(*ftab[1])(ctx,2,local+21,&ftab[1],fqv[14]); /*warn*/
	local[21]= argv[2];
	ctx->vsp=local+22;
	w=(*ftab[22])(ctx,1,local+21,&ftab[22],fqv[414]); /*open*/
	local[12] = w;
	local[21]= NIL;
	storeglobal(fqv[350],local[21]);
	if (loadglobal(fqv[415])==NIL) goto IF20966;
WHL20976:
	if (T==NIL) goto WHX20977;
	local[21]= local[12];
	local[22]= NIL;
	local[23]= fqv[416];
	ctx->vsp=local+24;
	w=(pointer)READ(ctx,3,local+21); /*read*/
	local[11] = w;
	local[21]= local[11];
	if (fqv[416]!=local[21]) goto IF20994;
	w = NIL;
	ctx->vsp=local+21;
	local[21]=w;
	goto BLK20978;
	goto IF20995;
IF20994:
	local[21]= NIL;
IF20995:
	local[21]= argv[0];
	local[22]= fqv[376];
	local[23]= local[11];
	local[24]= T;
	local[25]= T;
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,5,local+21); /*send*/
	goto WHL20976;
WHX20977:
	local[21]= NIL;
BLK20978:
	local[21]= local[12];
	local[22]= makeint(0);
	ctx->vsp=local+23;
	w=(pointer)LSEEK(ctx,2,local+21); /*unix:lseek*/
	local[21]= w;
	goto IF20967;
IF20966:
	local[21]= NIL;
IF20967:
	local[21]= loadglobal(fqv[350]);
	ctx->vsp=local+22;
	w=(pointer)NREVERSE(ctx,1,local+21); /*nreverse*/
	local[21]= loadglobal(fqv[23]);
	local[22]= fqv[417];
	local[23]= argv[2];
	local[24]= local[14];
	local[25]= local[15];
	local[26]= local[7];
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,6,local+21); /*send*/
	local[21]= argv[0]->c.obj.iv[0];
	local[22]= fqv[418];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,2,local+21); /*send*/
	argv[0]->c.obj.iv[3] = NIL;
	argv[0]->c.obj.iv[2] = makeint(0);
	argv[0]->c.obj.iv[4] = NIL;
	argv[0]->c.obj.iv[7] = NIL;
WHL21050:
	if (T==NIL) goto WHX21051;
	local[21]= local[12];
	local[22]= NIL;
	local[23]= fqv[416];
	ctx->vsp=local+24;
	w=(pointer)READ(ctx,3,local+21); /*read*/
	local[11] = w;
	local[21]= local[11];
	if (fqv[416]!=local[21]) goto IF21068;
	w = NIL;
	ctx->vsp=local+21;
	local[21]=w;
	goto BLK21052;
	goto IF21069;
IF21068:
	local[21]= NIL;
IF21069:
	local[21]= argv[0];
	local[22]= fqv[376];
	local[23]= local[11];
	local[24]= T;
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,4,local+21); /*send*/
	goto WHL21050;
WHX21051:
	local[21]= NIL;
BLK21052:
	local[21]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+22;
	w=(pointer)REVERSE(ctx,1,local+21); /*reverse*/
	argv[0]->c.obj.iv[7] = w;
	local[21]= loadglobal(fqv[23]);
	local[22]= fqv[419];
	local[23]= local[7];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,3,local+21); /*send*/
	local[21]= NIL;
	local[22]= argv[0]->c.obj.iv[7];
WHL21121:
	if (local[22]==NIL) goto WHX21122;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22] = (w)->c.cons.cdr;
	w = local[23];
	local[21] = w;
	local[23]= argv[0];
	local[24]= fqv[420];
	local[25]= local[21];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,3,local+23); /*send*/
	goto WHL21121;
WHX21122:
	local[23]= NIL;
BLK21123:
	w = NIL;
	local[21]= loadglobal(fqv[23]);
	local[22]= fqv[25];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,2,local+21); /*send*/
	local[21]= loadglobal(fqv[23]);
	local[22]= fqv[345];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,2,local+21); /*send*/
	local[21]= argv[0];
	local[22]= fqv[364];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,2,local+21); /*send*/
	local[21]= loadglobal(fqv[23]);
	local[22]= fqv[421];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,2,local+21); /*send*/
	local[21]= loadglobal(fqv[23]);
	local[22]= fqv[422];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,2,local+21); /*send*/
	local[21]= *(ovafptr(local[20],fqv[423]));
	local[22]= *(ovafptr(local[20],fqv[424]));
	local[23]= makeint(0);
	ctx->vsp=local+24;
	w=(*ftab[2])(ctx,1,local+23,&ftab[2],fqv[18]); /*make-array*/
	local[23]= w;
	*(ovafptr(local[20],fqv[423])) = local[23];
	local[23]= makeint(1);
	local[24]= local[23];
	*(ovafptr(local[20],fqv[424])) = local[24];
	local[23]= loadglobal(fqv[23]);
	local[24]= fqv[425];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,2,local+23); /*send*/
	local[23]= local[21];
	*(ovafptr(local[20],fqv[423])) = local[23];
	local[23]= local[22];
	local[24]= local[23];
	*(ovafptr(local[20],fqv[424])) = local[24];
	w = local[23];
	local[21]= loadglobal(fqv[23]);
	local[22]= fqv[426];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,2,local+21); /*send*/
	local[21]= local[12];
	ctx->vsp=local+22;
	w=(pointer)CLOSE(ctx,1,local+21); /*close*/
	local[21]= loadglobal(fqv[20]);
	local[22]= loadglobal(fqv[427]);
	local[23]= fqv[428];
	if (local[8]==NIL) goto IF21268;
	local[24]= loadglobal(fqv[20]);
	local[25]= fqv[429];
	local[26]= local[8];
	ctx->vsp=local+27;
	w=(*ftab[20])(ctx,1,local+26,&ftab[20],fqv[394]); /*namestring*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)CONCATENATE(ctx,3,local+24); /*concatenate*/
	local[24]= w;
	goto IF21269;
IF21268:
	local[24]= NIL;
IF21269:
	local[25]= fqv[430];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21282;
	local[25]= fqv[432];
	goto CON21280;
CON21282:
	local[25]= fqv[433];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21293;
	local[25]= fqv[434];
	goto CON21280;
CON21293:
	local[25]= fqv[435];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21303;
	local[25]= fqv[436];
	goto CON21280;
CON21303:
	local[25]= fqv[437];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21313;
	local[25]= fqv[438];
	goto CON21280;
CON21313:
	local[25]= fqv[439];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21323;
	local[25]= fqv[440];
	goto CON21280;
CON21323:
	local[25]= fqv[441];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21333;
	local[25]= fqv[442];
	goto CON21280;
CON21333:
	local[25]= fqv[443];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21343;
	local[25]= fqv[444];
	goto CON21280;
CON21343:
	local[25]= fqv[445];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21353;
	local[25]= fqv[446];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto IF21364;
	local[25]= fqv[447];
	goto IF21365;
IF21364:
	local[25]= fqv[448];
IF21365:
	goto CON21280;
CON21353:
	local[25]= fqv[449];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21374;
	local[25]= fqv[450];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21374;
	local[25]= fqv[446];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21396;
	local[25]= fqv[451];
	goto CON21394;
CON21396:
	local[25]= fqv[452];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21406;
	local[25]= fqv[453];
	goto CON21394;
CON21406:
	local[25]= fqv[454];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21416;
	local[25]= fqv[455];
	goto CON21394;
CON21416:
	local[25]= fqv[456];
	goto CON21394;
CON21426:
	local[25]= NIL;
CON21394:
	goto CON21280;
CON21374:
	local[25]= fqv[449];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21429;
	local[25]= fqv[446];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto IF21440;
	local[25]= fqv[457];
	goto IF21441;
IF21440:
	local[25]= fqv[458];
IF21441:
	goto CON21280;
CON21429:
	local[25]= fqv[459];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21450;
	local[25]= fqv[460];
	goto CON21280;
CON21450:
	local[25]= fqv[461];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21460;
	local[25]= fqv[462];
	goto CON21280;
CON21460:
	local[25]= fqv[463];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21470;
	local[25]= fqv[464];
	goto CON21280;
CON21470:
	local[25]= fqv[465];
	ctx->vsp=local+26;
	w=(*ftab[1])(ctx,1,local+25,&ftab[1],fqv[14]); /*warn*/
	local[25]= w;
	goto CON21280;
CON21480:
	local[25]= NIL;
CON21280:
	local[26]= fqv[466];
	w = loadglobal(fqv[431]);
	if (memq(local[26],w)==NIL) goto CON21488;
	local[26]= fqv[467];
	goto CON21486;
CON21488:
	local[26]= fqv[468];
	w = loadglobal(fqv[431]);
	if (memq(local[26],w)==NIL) goto CON21498;
	local[26]= fqv[469];
	goto CON21486;
CON21498:
	local[26]= fqv[470];
	w = loadglobal(fqv[431]);
	if (memq(local[26],w)==NIL) goto CON21508;
	local[26]= fqv[471];
	goto CON21486;
CON21508:
	local[26]= fqv[472];
	goto CON21486;
CON21518:
	local[26]= NIL;
CON21486:
	local[27]= fqv[473];
	w = loadglobal(fqv[431]);
	if (memq(local[27],w)==NIL) goto IF21522;
	local[27]= fqv[474];
	goto IF21523;
IF21522:
	local[27]= NIL;
IF21523:
	local[28]= fqv[475];
	w = loadglobal(fqv[431]);
	if (memq(local[28],w)==NIL) goto IF21533;
	local[28]= fqv[476];
	goto IF21534;
IF21533:
	local[28]= NIL;
IF21534:
	local[29]= fqv[477];
	w = loadglobal(fqv[431]);
	if (memq(local[29],w)==NIL) goto IF21544;
	local[29]= fqv[478];
	goto IF21545;
IF21544:
	local[29]= NIL;
IF21545:
	local[30]= fqv[479];
	w = loadglobal(fqv[431]);
	if (memq(local[30],w)==NIL) goto IF21555;
	local[30]= fqv[480];
	goto IF21556;
IF21555:
	local[30]= NIL;
IF21556:
	if (local[5]==NIL) goto IF21566;
	local[31]= fqv[468];
	w = loadglobal(fqv[431]);
	if (memq(local[31],w)==NIL) goto CON21574;
	local[31]= fqv[481];
	goto CON21572;
CON21574:
	local[31]= fqv[461];
	w = loadglobal(fqv[431]);
	if (memq(local[31],w)==NIL) goto CON21584;
	local[31]= fqv[482];
	goto CON21572;
CON21584:
	local[31]= fqv[473];
	w = loadglobal(fqv[431]);
	if (memq(local[31],w)==NIL) goto CON21594;
	local[31]= fqv[483];
	goto CON21572;
CON21594:
	local[31]= fqv[470];
	w = loadglobal(fqv[431]);
	if (memq(local[31],w)==NIL) goto CON21604;
	local[31]= fqv[484];
	goto CON21572;
CON21604:
	local[31]= fqv[449];
	w = loadglobal(fqv[431]);
	if (memq(local[31],w)==NIL) goto CON21614;
	local[31]= fqv[485];
	goto CON21572;
CON21614:
	local[31]= fqv[435];
	w = loadglobal(fqv[431]);
	if (memq(local[31],w)==NIL) goto CON21624;
	local[31]= fqv[486];
	goto CON21572;
CON21624:
	local[31]= fqv[437];
	w = loadglobal(fqv[431]);
	if (memq(local[31],w)==NIL) goto CON21634;
	local[31]= fqv[487];
	goto CON21572;
CON21634:
	local[31]= fqv[459];
	w = loadglobal(fqv[431]);
	if (memq(local[31],w)==NIL) goto CON21644;
	local[31]= fqv[488];
	goto CON21572;
CON21644:
	local[31]= fqv[489];
	goto CON21572;
CON21654:
	local[31]= NIL;
CON21572:
	goto IF21567;
IF21566:
	local[31]= NIL;
IF21567:
	local[32]= local[0];
	local[33]= fqv[490];
	local[34]= loadglobal(fqv[491]);
	ctx->vsp=local+35;
	w=(*ftab[20])(ctx,1,local+34,&ftab[20],fqv[394]); /*namestring*/
	local[34]= w;
	local[35]= fqv[492];
	local[36]= loadglobal(fqv[388]);
	local[37]= loadglobal(fqv[493]);
	local[38]= fqv[494];
	local[39]= local[14];
	ctx->vsp=local+40;
	w=(*ftab[20])(ctx,1,local+39,&ftab[20],fqv[394]); /*namestring*/
	local[39]= w;
	local[40]= fqv[468];
	w = loadglobal(fqv[431]);
	if (memq(local[40],w)==NIL) goto IF21669;
	if (local[5]==NIL) goto IF21669;
	local[40]= loadglobal(fqv[20]);
	local[41]= fqv[495];
	local[42]= local[18];
	ctx->vsp=local+43;
	w=(*ftab[20])(ctx,1,local+42,&ftab[20],fqv[394]); /*namestring*/
	local[42]= w;
	local[43]= fqv[496];
	local[44]= local[17];
	ctx->vsp=local+45;
	w=(*ftab[20])(ctx,1,local+44,&ftab[20],fqv[394]); /*namestring*/
	local[44]= w;
	ctx->vsp=local+45;
	w=(pointer)CONCATENATE(ctx,5,local+40); /*concatenate*/
	local[40]= w;
	goto IF21670;
IF21669:
	local[40]= NIL;
IF21670:
	local[41]= fqv[435];
	w = loadglobal(fqv[431]);
	if (memq(local[41],w)!=NIL) goto OR21696;
	local[41]= fqv[437];
	w = loadglobal(fqv[431]);
	if (memq(local[41],w)!=NIL) goto OR21696;
	goto IF21693;
OR21696:
	if (local[5]==NIL) goto IF21693;
	local[41]= loadglobal(fqv[20]);
	local[42]= fqv[497];
	local[43]= local[18];
	ctx->vsp=local+44;
	w=(*ftab[20])(ctx,1,local+43,&ftab[20],fqv[394]); /*namestring*/
	local[43]= w;
	local[44]= fqv[498];
	local[45]= local[17];
	ctx->vsp=local+46;
	w=(*ftab[20])(ctx,1,local+45,&ftab[20],fqv[394]); /*namestring*/
	local[45]= w;
	ctx->vsp=local+46;
	w=(pointer)CONCATENATE(ctx,5,local+41); /*concatenate*/
	local[41]= w;
	goto IF21694;
IF21693:
	local[41]= NIL;
IF21694:
	local[42]= fqv[449];
	w = loadglobal(fqv[431]);
	if (memq(local[42],w)==NIL) goto IF21727;
	if (local[5]==NIL) goto IF21727;
	local[42]= loadglobal(fqv[20]);
	local[43]= fqv[445];
	w = loadglobal(fqv[431]);
	if (memq(local[43],w)==NIL) goto CON21746;
	local[43]= fqv[499];
	goto CON21744;
CON21746:
	local[43]= fqv[500];
	w = loadglobal(fqv[431]);
	if (memq(local[43],w)==NIL) goto CON21756;
	local[43]= fqv[501];
	goto CON21744;
CON21756:
	local[43]= fqv[502];
	w = loadglobal(fqv[431]);
	if (memq(local[43],w)==NIL) goto CON21766;
	local[43]= fqv[503];
	goto CON21744;
CON21766:
	local[43]= fqv[504];
	goto CON21744;
CON21776:
	local[43]= NIL;
CON21744:
	local[44]= local[18];
	ctx->vsp=local+45;
	w=(*ftab[20])(ctx,1,local+44,&ftab[20],fqv[394]); /*namestring*/
	local[44]= w;
	local[45]= fqv[505];
	local[46]= local[17];
	ctx->vsp=local+47;
	w=(*ftab[20])(ctx,1,local+46,&ftab[20],fqv[394]); /*namestring*/
	local[46]= w;
	ctx->vsp=local+47;
	w=(pointer)CONCATENATE(ctx,5,local+42); /*concatenate*/
	local[42]= w;
	goto IF21728;
IF21727:
	local[42]= fqv[506];
IF21728:
	local[43]= fqv[459];
	w = loadglobal(fqv[431]);
	if (memq(local[43],w)==NIL) goto IF21787;
	if (local[5]==NIL) goto IF21787;
	local[43]= loadglobal(fqv[20]);
	local[44]= fqv[507];
	local[45]= local[18];
	ctx->vsp=local+46;
	w=(*ftab[20])(ctx,1,local+45,&ftab[20],fqv[394]); /*namestring*/
	local[45]= w;
	local[46]= fqv[508];
	local[47]= local[17];
	ctx->vsp=local+48;
	w=(*ftab[20])(ctx,1,local+47,&ftab[20],fqv[394]); /*namestring*/
	local[47]= w;
	ctx->vsp=local+48;
	w=(pointer)CONCATENATE(ctx,5,local+43); /*concatenate*/
	local[43]= w;
	goto IF21788;
IF21787:
	local[43]= fqv[509];
IF21788:
	local[44]= fqv[461];
	w = loadglobal(fqv[431]);
	if (memq(local[44],w)==NIL) goto IF21811;
	if (loadglobal(fqv[510])!=NIL) goto IF21811;
	local[44]= loadglobal(fqv[20]);
	local[45]= fqv[511];
	local[46]= local[19];
	ctx->vsp=local+47;
	w=(*ftab[20])(ctx,1,local+46,&ftab[20],fqv[394]); /*namestring*/
	local[46]= w;
	local[47]= fqv[512];
	local[48]= local[17];
	ctx->vsp=local+49;
	w=(*ftab[20])(ctx,1,local+48,&ftab[20],fqv[394]); /*namestring*/
	local[48]= w;
	local[49]= fqv[513];
	local[50]= loadglobal(fqv[491]);
	local[51]= fqv[514];
	ctx->vsp=local+52;
	w=(pointer)GETENV(ctx,1,local+51); /*unix:getenv*/
	local[51]= w;
	local[52]= fqv[515];
	local[53]= fqv[516];
	local[54]= fqv[517];
	ctx->vsp=local+55;
	w=(pointer)CONCATENATE(ctx,11,local+44); /*concatenate*/
	local[44]= w;
	goto IF21812;
IF21811:
	local[44]= NIL;
IF21812:
	ctx->vsp=local+45;
	w=(pointer)CONCATENATE(ctx,24,local+21); /*concatenate*/
	local[13] = w;
	if (local[4]==NIL) goto IF21845;
	local[21]= fqv[518];
	local[22]= local[13];
	ctx->vsp=local+23;
	w=(*ftab[1])(ctx,2,local+21,&ftab[1],fqv[14]); /*warn*/
	local[21]= local[13];
	ctx->vsp=local+22;
	w=(pointer)SYSTEM(ctx,1,local+21); /*unix:system*/
	local[21]= w;
	goto IF21846;
IF21845:
	local[21]= NIL;
IF21846:
	local[21]= NIL;
	local[22]= loadglobal(fqv[350]);
WHL21879:
	if (local[22]==NIL) goto WHX21880;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22] = (w)->c.cons.cdr;
	w = local[23];
	local[21] = w;
	local[23]= local[21];
	local[24]= fqv[349];
	ctx->vsp=local+25;
	w=(*ftab[23])(ctx,2,local+23,&ftab[23],fqv[519]); /*remprop*/
	goto WHL21879;
WHX21880:
	local[23]= NIL;
BLK21881:
	w = NIL;
	local[21]= loadglobal(fqv[59]);
	ctx->vsp=local+22;
	w=(pointer)TERPRI(ctx,1,local+21); /*terpri*/
	local[0]= w;
BLK20590:
	ctx->vsp=local; return(local[0]);}

/*:specials*/
static pointer M21942compiler_specials(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[520];
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[521];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	local[0]= w;
BLK21943:
	ctx->vsp=local; return(local[0]);}

/*:copy-compiler*/
static pointer M21964compiler_copy_compiler(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[7];
	local[2]= argv[0]->c.obj.iv[6];
	argv[0]->c.obj.iv[7] = NIL;
	argv[0]->c.obj.iv[6] = NIL;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)COPYOBJ(ctx,1,local+3); /*copy-object*/
	local[0] = w;
	local[3]= local[0];
	local[4]= fqv[522];
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	argv[0]->c.obj.iv[7] = local[1];
	argv[0]->c.obj.iv[6] = local[2];
	w = local[0];
	local[0]= w;
BLK21965:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M22031compiler_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[523]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	storeglobal(fqv[23],w);
	local[0]= loadglobal(fqv[524]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[57];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = local[0];
	argv[0]->c.obj.iv[0] = w;
	argv[0]->c.obj.iv[2] = makeint(0);
	argv[0]->c.obj.iv[1] = makeint(0);
	w = argv[0];
	local[0]= w;
BLK22032:
	ctx->vsp=local; return(local[0]);}

/*dump-function*/
static pointer F7014dump_function(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST22098:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= argv[0];
	local[2]= fqv[525];
	local[3]= fqv[526];
	ctx->vsp=local+4;
	w=(*ftab[22])(ctx,3,local+1,&ftab[22],fqv[414]); /*open*/
	local[1]= w;
	ctx->vsp=local+2;
	w = makeclosure(codevec,quotevec,UWP22127,env,argv,local);
	local[2]=(pointer)(ctx->protfp); local[3]=w;
	ctx->protfp=(struct protectframe *)(local+2);
	local[4]= NIL;
	local[5]= local[0];
WHL22151:
	if (local[5]==NIL) goto WHX22152;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)SYMFUNC(ctx,1,local+6); /*symbol-function*/
	local[6]= w;
	local[7]= NIL;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= local[8];
	if (fqv[39]!=local[9]) goto IF22234;
	local[9]= fqv[347];
	local[10]= local[4];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	goto IF22235;
IF22234:
	local[9]= local[8];
	if (fqv[43]!=local[9]) goto IF22256;
	local[9]= fqv[347];
	local[10]= local[4];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	goto IF22257;
IF22256:
	local[9]= NIL;
IF22257:
IF22235:
	w = local[9];
	local[7] = w;
	local[8]= local[7];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(*ftab[24])(ctx,2,local+8,&ftab[24],fqv[527]); /*pprint*/
	goto WHL22151;
WHX22152:
	local[6]= NIL;
BLK22153:
	w = NIL;
	ctx->vsp=local+4;
	UWP22127(ctx,0,local+4,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK22096:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP22127(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[1];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*comfile*/
static pointer F7016comfile(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST22309:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= local[0];
WHL22335:
	if (local[2]==NIL) goto WHX22336;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= loadglobal(fqv[5]);
	local[4]= fqv[528];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	goto WHL22335;
WHX22336:
	local[3]= NIL;
BLK22337:
	w = NIL;
	local[0]= w;
BLK22307:
	ctx->vsp=local; return(local[0]);}

/*compile-file*/
static pointer F7018compile_file(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST22397:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= (pointer)get_sym_func(fqv[529]);
	local[2]= loadglobal(fqv[5]);
	local[3]= fqv[528];
	local[4]= argv[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	local[0]= w;
BLK22395:
	ctx->vsp=local; return(local[0]);}

/*compile*/
static pointer F7020compile(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST22422:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= fqv[530];
	ctx->vsp=local+3;
	w=(pointer)GETPID(ctx,0,local+3); /*unix:getpid*/
	local[3]= w;
	local[4]= fqv[531];
	ctx->vsp=local+5;
	w=(pointer)GENSYM(ctx,1,local+4); /*gensym*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[13])(ctx,1,local+4,&ftab[13],fqv[331]); /*symbol-name*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,4,local+1); /*format*/
	local[1]= w;
	local[2]= NIL;
	local[3]= (pointer)get_sym_func(fqv[532]);
	local[4]= local[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,3,local+3); /*apply*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F7018compile_file(ctx,1,local+3); /*compile-file*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)UNLINK(ctx,1,local+3); /*unix:unlink*/
	local[3]= fqv[533];
	local[4]= local[1];
	local[5]= fqv[97];
	local[6]= fqv[534];
	ctx->vsp=local+7;
	w=(*ftab[25])(ctx,4,local+3,&ftab[25],fqv[535]); /*make-pathname*/
	local[2] = w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(*ftab[20])(ctx,1,local+3,&ftab[20],fqv[394]); /*namestring*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)UNLINK(ctx,1,local+3); /*unix:unlink*/
	local[3]= fqv[533];
	local[4]= local[1];
	local[5]= fqv[97];
	local[6]= fqv[536];
	ctx->vsp=local+7;
	w=(*ftab[25])(ctx,4,local+3,&ftab[25],fqv[535]); /*make-pathname*/
	local[2] = w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(*ftab[20])(ctx,1,local+3,&ftab[20],fqv[394]); /*namestring*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)UNLINK(ctx,1,local+3); /*unix:unlink*/
	local[3]= fqv[533];
	local[4]= local[1];
	local[5]= fqv[97];
	local[6]= fqv[537];
	ctx->vsp=local+7;
	w=(*ftab[25])(ctx,4,local+3,&ftab[25],fqv[535]); /*make-pathname*/
	local[2] = w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(*ftab[26])(ctx,1,local+3,&ftab[26],fqv[375]); /*load*/
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(*ftab[20])(ctx,1,local+3,&ftab[20],fqv[394]); /*namestring*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)UNLINK(ctx,1,local+3); /*unix:unlink*/
	local[3]= fqv[533];
	local[4]= local[1];
	local[5]= fqv[97];
	local[6]= fqv[538];
	ctx->vsp=local+7;
	w=(*ftab[25])(ctx,4,local+3,&ftab[25],fqv[535]); /*make-pathname*/
	local[2] = w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(*ftab[20])(ctx,1,local+3,&ftab[20],fqv[394]); /*namestring*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)UNLINK(ctx,1,local+3); /*unix:unlink*/
	w = local[0];
	local[0]= w;
BLK22420:
	ctx->vsp=local; return(local[0]);}

/*compile-file-if-src-newer*/
static pointer F7022compile_file_if_src_newer(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT22557;}
	local[0]= fqv[539];
ENT22557:
ENT22556:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-2);
	local[2]= argv[0];
	local[3]= fqv[540];
	ctx->vsp=local+4;
	w=(*ftab[19])(ctx,2,local+2,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[2]= w;
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[18])(ctx,1,local+4,&ftab[18],fqv[390]); /*pathname*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[19])(ctx,2,local+3,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[3]= w;
	local[4]= fqv[541];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(*ftab[18])(ctx,1,local+5,&ftab[18],fqv[390]); /*pathname*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[19])(ctx,2,local+4,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[4]= w;
	local[5]= local[3];
	local[6]= fqv[97];
	local[7]= fqv[542];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(*ftab[21])(ctx,1,local+5,&ftab[21],fqv[410]); /*probe-file*/
	if (w==NIL) goto OR22611;
	local[5]= local[2];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(*ftab[27])(ctx,2,local+5,&ftab[27],fqv[543]); /*file-newer*/
	if (w!=NIL) goto OR22611;
	goto IF22609;
OR22611:
	local[5]= (pointer)get_sym_func(fqv[544]);
	local[6]= argv[0];
	local[7]= fqv[545];
	local[8]= local[3];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)APPLY(ctx,5,local+5); /*apply*/
	local[5]= w;
	goto IF22610;
IF22609:
	local[5]= NIL;
IF22610:
	w = argv[0];
	local[0]= w;
BLK22554:
	ctx->vsp=local; return(local[0]);}

/*comp-file-toplevel*/
static pointer F7024comp_file_toplevel(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST22646:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= fqv[546];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,1,local+1,&ftab[1],fqv[14]); /*warn*/
	local[1]= loadglobal(fqv[59]);
	ctx->vsp=local+2;
	w=(pointer)TERPRI(ctx,1,local+1); /*terpri*/
	local[1]= makeint(60000);
	ctx->vsp=local+2;
	w=(pointer)ALLOC(ctx,1,local+1); /*system:alloc*/
	local[1]= fqv[547];
	storeglobal(fqv[548],local[1]);
	local[1]= makeint(1);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= fqv[549];
	w = local[5];
	ctx->vsp=local+6;
	bindspecial(ctx,fqv[550],w);
	local[9]= local[2];
	local[10]= makeint(1);
	ctx->vsp=local+11;
	w=(pointer)LESSP(ctx,2,local+9); /*<*/
	if (w==NIL) goto CON22703;
	local[9]= (pointer)get_sym_func(fqv[551]);
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)APPLY(ctx,2,local+9); /*apply*/
	local[9]= w;
	goto CON22701;
CON22703:
	local[9]= local[2];
	local[10]= makeint(2);
	ctx->vsp=local+11;
	w=(pointer)LESSP(ctx,2,local+9); /*<*/
	if (w==NIL) goto CON22713;
	local[9]= T;
	local[10]= fqv[552];
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,2,local+9); /*format*/
	local[9]= makeint(1);
	ctx->vsp=local+10;
	w=(*ftab[28])(ctx,1,local+9,&ftab[28],fqv[553]); /*exit*/
	local[9]= w;
	goto CON22701;
CON22713:
WHL22728:
	local[9]= local[1];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)LESSP(ctx,2,local+9); /*<*/
	if (w==NIL) goto WHX22729;
	{jmp_buf jb;
	w = makeint(0);
	ctx->vsp=local+9;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT22737;}
	local[15]= local[0];
	local[16]= local[1];
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[3] = w;
	local[15]= local[3];
	ctx->vsp=local+16;
	w=(*ftab[29])(ctx,1,local+15,&ftab[29],fqv[554]); /*string-upcase*/
	local[4] = w;
	local[15]= local[1];
	ctx->vsp=local+16;
	w=(pointer)ADD1(ctx,1,local+15); /*1+*/
	local[1] = w;
	local[15]= local[4];
	local[16]= fqv[555];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22774;
	local[15]= fqv[439];
	w = loadglobal(fqv[431]);
	if (memq(local[15],w)!=NIL) goto IF22782;
	local[15]= fqv[556];
	storeglobal(fqv[388],local[15]);
	goto IF22783;
IF22782:
	local[15]= NIL;
IF22783:
	goto CON22772;
CON22774:
	local[15]= local[4];
	local[16]= fqv[557];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22796;
	local[15]= makeint(1);
	storeglobal(fqv[315],local[15]);
	goto CON22772;
CON22796:
	local[15]= local[4];
	local[16]= fqv[558];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22807;
	local[15]= makeint(2);
	storeglobal(fqv[315],local[15]);
	goto CON22772;
CON22807:
	local[15]= local[4];
	local[16]= fqv[559];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22818;
	local[15]= makeint(3);
	storeglobal(fqv[315],local[15]);
	goto CON22772;
CON22818:
	local[15]= local[4];
	local[16]= fqv[560];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22829;
	local[15]= T;
	storeglobal(fqv[342],local[15]);
	goto CON22772;
CON22829:
	local[15]= local[4];
	local[16]= fqv[561];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22840;
	local[15]= makeint(0);
	storeglobal(fqv[182],local[15]);
	goto CON22772;
CON22840:
	local[15]= local[4];
	local[16]= fqv[562];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22851;
	local[15]= makeint(1);
	storeglobal(fqv[182],local[15]);
	goto CON22772;
CON22851:
	local[15]= local[4];
	local[16]= fqv[563];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22862;
	local[15]= makeint(2);
	storeglobal(fqv[182],local[15]);
	goto CON22772;
CON22862:
	local[15]= local[4];
	local[16]= fqv[564];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22873;
	local[15]= makeint(3);
	storeglobal(fqv[182],local[15]);
	goto CON22772;
CON22873:
	local[15]= local[4];
	local[16]= fqv[565];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22884;
	local[15]= local[0];
	local[16]= local[1];
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(*ftab[30])(ctx,1,local+15,&ftab[30],fqv[566]); /*read-from-string*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)EVAL(ctx,1,local+15); /*eval*/
	local[15]= local[1];
	ctx->vsp=local+16;
	w=(pointer)ADD1(ctx,1,local+15); /*1+*/
	local[1] = w;
	local[15]= local[1];
	goto CON22772;
CON22884:
	local[15]= local[4];
	local[16]= fqv[567];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22910;
	local[15]= NIL;
	storeglobal(fqv[384],local[15]);
	goto CON22772;
CON22910:
	local[15]= local[4];
	local[16]= fqv[568];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22921;
	local[15]= local[0];
	local[16]= local[1];
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(*ftab[30])(ctx,1,local+15,&ftab[30],fqv[566]); /*read-from-string*/
	local[15]= w;
	w = loadglobal(fqv[431]);
	ctx->vsp=local+16;
	local[15]= cons(ctx,local[15],w);
	storeglobal(fqv[431],local[15]);
	local[15]= local[1];
	ctx->vsp=local+16;
	w=(pointer)ADD1(ctx,1,local+15); /*1+*/
	local[1] = w;
	local[15]= local[1];
	goto CON22772;
CON22921:
	local[15]= local[4];
	local[16]= fqv[569];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22953;
	local[15]= local[0];
	local[16]= local[1];
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(*ftab[30])(ctx,1,local+15,&ftab[30],fqv[566]); /*read-from-string*/
	local[15]= w;
	local[16]= local[15];
	ctx->vsp=local+17;
	w=(pointer)FINDPACKAGE(ctx,1,local+16); /*find-package*/
	if (w!=NIL) goto IF22978;
	local[16]= local[15];
	ctx->vsp=local+17;
	w=(*ftab[31])(ctx,1,local+16,&ftab[31],fqv[570]); /*make-package*/
	local[16]= w;
	goto IF22979;
IF22978:
	local[16]= NIL;
IF22979:
	local[16]= local[15];
	ctx->vsp=local+17;
	w=(pointer)FINDPACKAGE(ctx,1,local+16); /*find-package*/
	if (w==NIL) goto IF22995;
	local[16]= local[15];
	ctx->vsp=local+17;
	w=(pointer)FINDPACKAGE(ctx,1,local+16); /*find-package*/
	local[16]= w;
	storeglobal(fqv[404],w);
	goto IF22996;
IF22995:
	local[16]= fqv[571];
	ctx->vsp=local+17;
	w=(pointer)SIGERROR(ctx,1,local+16); /*error*/
	local[16]= w;
IF22996:
	w = local[16];
	local[15]= local[1];
	ctx->vsp=local+16;
	w=(pointer)ADD1(ctx,1,local+15); /*1+*/
	local[1] = w;
	local[15]= local[1];
	goto CON22772;
CON22953:
	local[15]= local[4];
	local[16]= fqv[572];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON23022;
	local[15]= T;
	storeglobal(fqv[385],local[15]);
	goto CON22772;
CON23022:
	local[15]= local[4];
	local[16]= fqv[573];
	ctx->vsp=local+17;
	w=(*ftab[32])(ctx,2,local+15,&ftab[32],fqv[574]); /*string-equal*/
	if (w==NIL) goto CON23033;
	local[15]= NIL;
	storeglobal(fqv[385],local[15]);
	goto CON22772;
CON23033:
	local[15]= loadglobal(fqv[5]);
	local[16]= fqv[528];
	local[17]= local[3];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,3,local+15); /*send*/
	local[15]= w;
	goto CON22772;
CON23045:
	local[15]= NIL;
CON22772:
	w = local[15];
CAT22737:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	goto WHL22728;
WHX22729:
	local[9]= NIL;
BLK22730:
	goto CON22701;
CON22724:
	local[9]= NIL;
CON22701:
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(*ftab[28])(ctx,1,local+9,&ftab[28],fqv[553]); /*exit*/
	local[9]= w;
	ctx->vsp=local+10;
	unbindx(ctx,1);
	w = local[9];
	local[0]= w;
BLK22644:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___comp(ctx,n,argv,env)
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
	local[0]= fqv[575];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF23066;
	local[0]= fqv[576];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[404],w);
	goto IF23067;
IF23066:
	local[0]= fqv[577];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF23067:
	local[0]= fqv[578];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[579];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[580],module,F6924compiled_code_p,fqv[581]);
	local[0]= fqv[388];
	local[1]= fqv[582];
	local[2]= fqv[583];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[493];
	local[1]= fqv[582];
	local[2]= fqv[584];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[350];
	local[1]= fqv[582];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[342];
	local[1]= fqv[582];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[315];
	local[1]= fqv[582];
	local[2]= makeint(2);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[182];
	local[1]= fqv[582];
	local[2]= makeint(1);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[318];
	local[1]= fqv[582];
	local[2]= makeint(0);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[384];
	local[1]= fqv[582];
	local[2]= T;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[385];
	local[1]= fqv[582];
	local[2]= T;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[510];
	local[1]= fqv[582];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[427];
	local[1]= fqv[582];
	local[2]= fqv[500];
	local[3]= loadglobal(fqv[431]);
	ctx->vsp=local+4;
	w=(*ftab[11])(ctx,2,local+2,&ftab[11],fqv[265]); /*member*/
	if (w==NIL) goto CON23184;
	local[2]= fqv[585];
	goto CON23182;
CON23184:
	local[2]= fqv[502];
	local[3]= loadglobal(fqv[431]);
	ctx->vsp=local+4;
	w=(*ftab[11])(ctx,2,local+2,&ftab[11],fqv[265]); /*member*/
	if (w==NIL) goto CON23193;
	local[2]= fqv[586];
	goto CON23182;
CON23193:
	local[2]= fqv[473];
	local[3]= loadglobal(fqv[431]);
	ctx->vsp=local+4;
	w=(*ftab[11])(ctx,2,local+2,&ftab[11],fqv[265]); /*member*/
	if (w==NIL) goto CON23202;
	local[2]= fqv[587];
	goto CON23182;
CON23202:
	local[2]= fqv[459];
	local[3]= loadglobal(fqv[431]);
	ctx->vsp=local+4;
	w=(*ftab[11])(ctx,2,local+2,&ftab[11],fqv[265]); /*member*/
	if (w==NIL) goto CON23211;
	local[2]= fqv[588];
	goto CON23182;
CON23211:
	local[2]= fqv[589];
	goto CON23182;
CON23220:
	local[2]= NIL;
CON23182:
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[5];
	local[1]= fqv[590];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF23227;
	local[0]= fqv[5];
	local[1]= fqv[590];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[5];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF23250;
	local[0]= fqv[5];
	local[1]= fqv[582];
	local[2]= NIL;
	local[3]= fqv[591];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF23251;
IF23250:
	local[0]= NIL;
IF23251:
	local[0]= fqv[5];
	goto IF23228;
IF23227:
	local[0]= NIL;
IF23228:
	local[0]= fqv[23];
	local[1]= fqv[590];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF23270;
	local[0]= fqv[23];
	local[1]= fqv[590];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[23];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF23293;
	local[0]= fqv[23];
	local[1]= fqv[582];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF23294;
IF23293:
	local[0]= NIL;
IF23294:
	local[0]= fqv[23];
	goto IF23271;
IF23270:
	local[0]= NIL;
IF23271:
	local[0]= fqv[415];
	local[1]= fqv[590];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF23313;
	local[0]= fqv[415];
	local[1]= fqv[590];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[415];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF23336;
	local[0]= fqv[415];
	local[1]= fqv[582];
	local[2]= T;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF23337;
IF23336:
	local[0]= NIL;
IF23337:
	local[0]= fqv[415];
	goto IF23314;
IF23313:
	local[0]= NIL;
IF23314:
	ctx->vsp=local+0;
	compfun(ctx,fqv[592],module,F6941ovafp,fqv[593]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[594],module,F6943class_symbolp,fqv[595]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[596],module,F6945quoted_symbolp,fqv[597]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[598],module,F6947proclaimed_special_p,fqv[599]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[600],module,F6949proclaimed_global_p,fqv[601]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[602],module,F6951object_variable_names,fqv[603]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[604],module,F6953object_variable_type,fqv[605]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[606],module,F6955coerce_type,fqv[607]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[608],module,F6957check_arg,fqv[609]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[610],module,F6959def_function_type,fqv[611]);
	local[0]= fqv[9];
	local[1]= fqv[612];
	ctx->vsp=local+2;
	w=(pointer)F6959def_function_type(ctx,2,local+0); /*def-function-type*/
	local[0]= fqv[11];
	local[1]= fqv[613];
	ctx->vsp=local+2;
	w=(pointer)F6959def_function_type(ctx,2,local+0); /*def-function-type*/
	local[0]= loadglobal(fqv[177]);
	local[1]= fqv[614];
	ctx->vsp=local+2;
	w=(pointer)F6959def_function_type(ctx,2,local+0); /*def-function-type*/
	local[0]= fqv[56];
	local[1]= fqv[582];
	local[2]= fqv[56];
	local[3]= fqv[615];
	local[4]= loadglobal(fqv[355]);
	local[5]= fqv[616];
	local[6]= fqv[617];
	local[7]= fqv[618];
	local[8]= NIL;
	local[9]= fqv[619];
	local[10]= NIL;
	local[11]= fqv[620];
	local[12]= makeint(-1);
	local[13]= fqv[621];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[33])(ctx,13,local+2,&ftab[33],fqv[622]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M7668identifier_type,fqv[97],fqv[56],fqv[623]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M7698identifier_offset,fqv[624],fqv[56],fqv[625]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M7726identifier_binding,fqv[63],fqv[56],fqv[626]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M7754identifier_init,fqv[57],fqv[56],fqv[627]);
	local[0]= fqv[524];
	local[1]= fqv[582];
	local[2]= fqv[524];
	local[3]= fqv[615];
	local[4]= loadglobal(fqv[355]);
	local[5]= fqv[616];
	local[6]= fqv[628];
	local[7]= fqv[618];
	local[8]= NIL;
	local[9]= fqv[619];
	local[10]= NIL;
	local[11]= fqv[620];
	local[12]= makeint(-1);
	local[13]= fqv[621];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[33])(ctx,13,local+2,&ftab[33],fqv[622]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M7815identifier_table_find,fqv[64],fqv[524],fqv[629]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M7851identifier_table_get,fqv[55],fqv[524],fqv[630]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M7929identifier_table_enter,fqv[17],fqv[524],fqv[631]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M7973identifier_table_enter_special,fqv[58],fqv[524],fqv[632]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M7994identifier_table_create_frame,fqv[77],fqv[524],fqv[633]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8017identifier_table_pop_frame,fqv[83],fqv[524],fqv[634]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8046identifier_table_clear_frame,fqv[635],fqv[524],fqv[636]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8064identifier_table_level,fqv[78],fqv[524],fqv[637]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8092identifier_table_frame,fqv[521],fqv[524],fqv[638]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8118identifier_table_init_frames,fqv[418],fqv[524],fqv[639]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8189identifier_table_init,fqv[57],fqv[524],fqv[640]);
	local[0]= fqv[76];
	local[1]= fqv[582];
	local[2]= fqv[76];
	local[3]= fqv[615];
	local[4]= loadglobal(fqv[355]);
	local[5]= fqv[616];
	local[6]= fqv[641];
	local[7]= fqv[618];
	local[8]= NIL;
	local[9]= fqv[619];
	local[10]= NIL;
	local[11]= fqv[620];
	local[12]= makeint(-1);
	local[13]= fqv[621];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[33])(ctx,13,local+2,&ftab[33],fqv[622]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8246stack_frame_offset,fqv[624],fqv[76],fqv[642]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8281stack_frame_special,fqv[69],fqv[76],fqv[643]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8311stack_frame_local,fqv[71],fqv[76],fqv[644]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8341stack_frame_init,fqv[57],fqv[76],fqv[645]);
	local[0]= fqv[646];
	local[1]= fqv[582];
	local[2]= fqv[646];
	local[3]= fqv[615];
	local[4]= loadglobal(fqv[355]);
	local[5]= fqv[616];
	local[6]= fqv[647];
	local[7]= fqv[618];
	local[8]= NIL;
	local[9]= fqv[619];
	local[10]= NIL;
	local[11]= fqv[620];
	local[12]= makeint(-1);
	local[13]= fqv[621];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[33])(ctx,13,local+2,&ftab[33],fqv[622]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8400compiler_genlabel,fqv[254],fqv[646],fqv[648]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8433compiler_gencname_tail,fqv[649],fqv[646],fqv[650]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8454compiler_progn,fqv[233],fqv[646],fqv[651]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8541compiler_eval,fqv[22],fqv[646],fqv[652]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8936compiler_get_function,fqv[38],fqv[646],fqv[653]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M9043compiler_call_closure,fqv[46],fqv[646],fqv[654]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M9186compiler_variable,fqv[62],fqv[646],fqv[655]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M9311compiler_var_binding,fqv[272],fqv[646],fqv[656]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M9344compiler_special_variable_p,fqv[281],fqv[646],fqv[657]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M9403compiler_enter_variable,fqv[68],fqv[646],fqv[658]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M9530compiler_bind,fqv[278],fqv[646],fqv[659]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M9726compiler_create_frame,fqv[77],fqv[646],fqv[660]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M9792compiler_delete_frame,fqv[280],fqv[646],fqv[661]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M9919compiler_load_ovaf,fqv[35],fqv[646],fqv[662]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M10032compiler_load_var,fqv[32],fqv[646],fqv[663]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M10212compiler_store_ovaf,fqv[100],fqv[646],fqv[664]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M10295compiler_store_var,fqv[274],fqv[646],fqv[665]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M10451compiler_funcall,fqv[40],fqv[646],fqv[666]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M11436compiler_vector_op,fqv[161],fqv[646],fqv[667]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M11616compiler_slot,fqv[166],fqv[646],fqv[668]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M11744compiler_setslot,fqv[169],fqv[646],fqv[669]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M11928compiler_arithmetic,fqv[163],fqv[646],fqv[670]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M12385compiler_special_form,fqv[42],fqv[646],fqv[671]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M13063compiler_conditional_jump,fqv[248],fqv[646],fqv[672]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M13098compiler_evcon,fqv[252],fqv[646],fqv[673]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M13724compiler_if,fqv[202],fqv[646],fqv[674]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M13829compiler_setq,fqv[200],fqv[646],fqv[675]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M14043compiler_let_,fqv[206],fqv[646],fqv[676]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M14324compiler_let,fqv[204],fqv[646],fqv[677]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M14823compiler_cond,fqv[208],fqv[646],fqv[678]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15040compiler_while,fqv[210],fqv[646],fqv[679]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15163compiler_and,fqv[212],fqv[646],fqv[680]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15283compiler_or,fqv[214],fqv[646],fqv[681]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15403compiler_catch,fqv[220],fqv[646],fqv[682]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15515compiler_throw,fqv[222],fqv[646],fqv[683]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15551compiler_unwind_protect,fqv[231],fqv[646],fqv[684]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15722compiler_enter_block,fqv[286],fqv[646],fqv[685]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15792compiler_leave_block,fqv[287],fqv[646],fqv[686]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15816compiler_block,fqv[216],fqv[646],fqv[687]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15864compiler_return_from,fqv[218],fqv[646],fqv[688]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15991compiler_tagbody,fqv[224],fqv[646],fqv[689]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M16195compiler_go,fqv[226],fqv[646],fqv[690]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M16294compiler_function,fqv[235],fqv[646],fqv[691]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M16419compiler_flet,fqv[228],fqv[646],fqv[692]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M16659compiler_change_flets,fqv[309],fqv[646],fqv[693]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M16681compiler_declare,fqv[277],fqv[646],fqv[694]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M17333compiler_lambda,fqv[344],fqv[646],fqv[695]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M18823compiler_lambda_block,fqv[353],fqv[646],fqv[696]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M19014compiler_def_user_entry,fqv[378],fqv[646],fqv[697]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M19086compiler_defun,fqv[367],fqv[646],fqv[698]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M19252compiler_defmethod,fqv[370],fqv[646],fqv[699]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M19651compiler_add_initcode,fqv[354],fqv[646],fqv[700]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M19677compiler_add_closure,fqv[296],fqv[646],fqv[701]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M19703compiler_closure_level,fqv[522],fqv[646],fqv[702]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M19729compiler_compile_a_closure,fqv[365],fqv[646],fqv[703]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M19820compiler_compile_closures,fqv[364],fqv[646],fqv[704]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M19936compiler_toplevel_eval,fqv[379],fqv[646],fqv[705]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M20083compiler_toplevel,fqv[376],fqv[646],fqv[706]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M20427compiler_toplevel_execution,fqv[420],fqv[646],fqv[707]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M20589compiler_compile_file,fqv[528],fqv[646],fqv[708]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M21942compiler_specials,fqv[709],fqv[646],fqv[710]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M21964compiler_copy_compiler,fqv[295],fqv[646],fqv[711]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22031compiler_init,fqv[57],fqv[646],fqv[712]);
	local[0]= loadglobal(fqv[646]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	storeglobal(fqv[5],w);
	local[0]= loadglobal(fqv[5]);
	local[1]= fqv[57];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[532],module,F7014dump_function,fqv[713]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[714],module,F7016comfile,fqv[715]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[544],module,F7018compile_file,fqv[716]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[374],module,F7020compile,fqv[717]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[718],module,F7022compile_file_if_src_newer,fqv[719]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[720],module,F7024comp_file_toplevel,fqv[721]);
	local[0]= fqv[722];
	local[1]= fqv[723];
	ctx->vsp=local+2;
	w=(*ftab[34])(ctx,2,local+0,&ftab[34],fqv[724]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<35; i++) ftab[i]=fcallx;
}
