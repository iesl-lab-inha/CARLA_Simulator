/* ./common.c :  entry=common */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "common.h"
#pragma init (register_common)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___common();
extern pointer build_quote_vector();
static int register_common()
  { add_module_initializer("___common", ___common);}

static pointer F4132lisp_implementation_type();
static pointer F4134lisp_implementation_version();
static pointer F4138macroexpand();
static pointer F4167casebody();
static pointer F4170casehead();
static pointer F4173case1();
static pointer F4177classcasehead();
static pointer F4180classcase1();
static pointer F4183string();
static pointer F4187alias();
static pointer F4193caaar();
static pointer F4196caadr();
static pointer F4199cadar();
static pointer F4202cdaar();
static pointer F4205cdadr();
static pointer F4208cddar();
static pointer F4211cdddr();
static pointer F4217fourth();
static pointer F4220fifth();
static pointer F4223sixth();
static pointer F4226seventh();
static pointer F4229eighth();
static pointer F4232cddddr();
static pointer F4235cadddr();
static pointer F4238caaddr();
static pointer F4241cdaddr();
static pointer F4244caddddr();
static pointer F4247flatten();
static pointer F4250list_insert();
static pointer F4253list_delete();
static pointer F4256adjoin();
static pointer F4259union();
static pointer F4262intersection();
static pointer F4265set_difference();
static pointer F4268set_exclusive_or();
static pointer F4271rotate_list();
static pointer F4274last();
static pointer F4277copy_tree();
static pointer F4280copy_list();
static pointer F4283nreconc();
static pointer F4286rassoc();
static pointer F4289acons();
static pointer F4292member();
static pointer F4295assoc();
static pointer F4298subsetp();
static pointer F4301maplist();
static pointer F4304mapcon();
static pointer F4307find();
static pointer F4310find_if();
static pointer F4313find_if_not();
static pointer F4316position();
static pointer F4319position_if();
static pointer F4322position_if_not();
static pointer F4325count();
static pointer F4328count_if();
static pointer F4331count_if_not();
static pointer F4334member_if();
static pointer F4337member_if_not();
static pointer F4340collect_if();
static pointer F4343collect_instances();
static pointer F4346pairlis();
static pointer F4349transpose_list();
static pointer F4352make_list();
static pointer F4355make_sequence();
static pointer F4358fill();
static pointer F4361replace();
static pointer F4364remove();
static pointer F4367remove_if();
static pointer F4370remove_if_not();
static pointer F4373delete();
static pointer F4376delete_if();
static pointer F4379delete_if_not();
static pointer F4382substitute();
static pointer F4385substitute_if();
static pointer F4388substitute_if_not();
static pointer F4391nsubstitute();
static pointer F4394nsubstitute_if();
static pointer F4397nsubstitute_if_not();
static pointer F4400unique();
static pointer F4403remove_duplicates();
static pointer F4406extream();
static pointer F4415send_all();
static pointer F4418resend();
static pointer F4423make_instance();
static pointer F4427delete_method();
static pointer F4430make_class();
static pointer F4437readtablep();
static pointer F4440copy_readtable();
static pointer F4443set_syntax_from_char();
static pointer F4448keywordp();
static pointer F4451constantp();
static pointer F4454functionp();
static pointer F4457vector_class_p();
static pointer F4460compiled_function_p();
static pointer F4463input_stream_p();
static pointer F4466output_stream_p();
static pointer F4469io_stream_p();
static pointer F4472special_form_p();
static pointer F4475macro_function();
static pointer F4478zerop();
static pointer F4481plusp();
static pointer F4484minusp();
static pointer F4487oddp();
static pointer F4490evenp();
static pointer F4493logandc1();
static pointer F4496logandc2();
static pointer F4500every();
static pointer F4503some();
static pointer F4508reduce();
static pointer F4511merge_list();
static pointer F4514merge();
static pointer F4517expt();
static pointer F4520signum();
static pointer F4523rad2deg();
static pointer F4526deg2rad();
static pointer F4528setf_expand_1();
static pointer F4530setf_expand();

/*lisp-implementation-type*/
static pointer F4132lisp_implementation_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	w = fqv[0];
	local[0]= w;
BLK4674:
	ctx->vsp=local; return(local[0]);}

/*lisp-implementation-version*/
static pointer F4134lisp_implementation_version(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= NIL;
	local[1]= fqv[1];
	w=loadglobal(fqv[2]);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= loadglobal(fqv[2]);
	ctx->vsp=local+4;
	w=(pointer)F4211cdddr(ctx,1,local+3); /*cdddr*/
	local[3]= w;
	local[4]= loadglobal(fqv[3]);
	w=loadglobal(fqv[2]);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=loadglobal(fqv[2]);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,7,local+0); /*format*/
	local[0]= w;
BLK4684:
	ctx->vsp=local; return(local[0]);}

/*macroexpand*/
static pointer F4138macroexpand(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)MACEXPAND2(ctx,1,local+0); /*macroexpand2*/
	local[0]= w;
WHL4748:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)LISTP(ctx,1,local+1); /*listp*/
	if (w==NIL) goto WHX4749;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)F4475macro_function(ctx,1,local+1); /*macro-function*/
	if (w==NIL) goto WHX4749;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)MACEXPAND2(ctx,1,local+1); /*macroexpand2*/
	local[0] = w;
	goto WHL4748;
WHX4749:
	local[1]= NIL;
BLK4750:
	w = local[0];
	local[0]= w;
BLK4725:
	ctx->vsp=local; return(local[0]);}

/*prog1*/
static pointer F4782(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4785:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= fqv[4];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= fqv[5];
	local[3]= local[1];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[3]= w;
	local[4]= fqv[6];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[0]= w;
BLK4783:
	ctx->vsp=local; return(local[0]);}

/*loop*/
static pointer F4845(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4848:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= fqv[7];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= fqv[8];
	local[3]= fqv[9];
	local[4]= fqv[10];
	local[5]= local[1];
	local[6]= local[0];
	local[7]= fqv[11];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)APPEND(ctx,2,local+6); /*append*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[0]= w;
BLK4846:
	ctx->vsp=local; return(local[0]);}

/*unless*/
static pointer F4904(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST4907:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[12];
	local[2]= fqv[13];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	w = local[0];
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK4905:
	ctx->vsp=local; return(local[0]);}

/*until*/
static pointer F4937(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST4940:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[14];
	local[2]= fqv[13];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= local[0];
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)APPEND(ctx,2,local+3); /*append*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK4938:
	ctx->vsp=local; return(local[0]);}

/*pop*/
static pointer F4971(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[15];
	local[1]= fqv[16];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[17];
	local[3]= argv[0];
	local[4]= fqv[18];
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
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK4972:
	ctx->vsp=local; return(local[0]);}

/*push*/
static pointer F5018(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[17];
	local[1]= argv[1];
	local[2]= fqv[19];
	local[3]= argv[0];
	local[4]= argv[1];
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
BLK5019:
	ctx->vsp=local; return(local[0]);}

/*pushnew*/
static pointer F5055(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[20], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY5069;
	local[0] = NIL;
KEY5069:
	if (n & (1<<1)) goto KEY5074;
	local[1] = NIL;
KEY5074:
	if (n & (1<<2)) goto KEY5079;
	local[2] = NIL;
KEY5079:
	local[3]= fqv[6];
	local[4]= fqv[21];
	local[5]= fqv[13];
	local[6]= fqv[22];
	local[7]= argv[0];
	local[8]= argv[1];
	local[9]= fqv[23];
	local[10]= local[0];
	local[11]= fqv[24];
	local[12]= local[1];
	local[13]= fqv[25];
	local[14]= local[2];
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
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[17];
	local[7]= argv[1];
	local[8]= fqv[19];
	local[9]= argv[0];
	local[10]= argv[1];
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
	local[5]= fqv[9];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	local[0]= w;
BLK5056:
	ctx->vsp=local; return(local[0]);}

/*inc*/
static pointer F5176(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT5180;}
	local[0]= NIL;
ENT5180:
ENT5179:
	if (n>2) maerror();
	if (local[0]==NIL) goto IF5194;
	local[1]= fqv[26];
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
	goto IF5195;
IF5194:
	local[1]= fqv[27];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
IF5195:
	local[1]= fqv[28];
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[0]= w;
BLK5177:
	ctx->vsp=local; return(local[0]);}

/*dec*/
static pointer F5230(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT5234;}
	local[0]= NIL;
ENT5234:
ENT5233:
	if (n>2) maerror();
	if (local[0]==NIL) goto IF5248;
	local[1]= fqv[29];
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
	goto IF5249;
IF5248:
	local[1]= fqv[30];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
IF5249:
	local[1]= fqv[28];
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[0]= w;
BLK5231:
	ctx->vsp=local; return(local[0]);}

/*incf*/
static pointer F5284(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT5288;}
	local[0]= NIL;
ENT5288:
ENT5287:
	if (n>2) maerror();
	if (local[0]==NIL) goto IF5302;
	local[1]= fqv[26];
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
	goto IF5303;
IF5302:
	local[1]= fqv[27];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
IF5303:
	local[1]= fqv[17];
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[0]= w;
BLK5285:
	ctx->vsp=local; return(local[0]);}

/*decf*/
static pointer F5338(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT5342;}
	local[0]= NIL;
ENT5342:
ENT5341:
	if (n>2) maerror();
	if (local[0]==NIL) goto IF5356;
	local[1]= fqv[29];
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
	goto IF5357;
IF5356:
	local[1]= fqv[30];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
IF5357:
	local[1]= fqv[17];
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[0]= w;
BLK5339:
	ctx->vsp=local; return(local[0]);}

/*defvar*/
static pointer F5392(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT5397;}
	local[0]= NIL;
ENT5397:
	if (n>=3) { local[1]=(argv[2]); goto ENT5396;}
	local[1]= NIL;
ENT5396:
ENT5395:
	if (n>3) maerror();
	w = argv[0];
	if (issymbol(w)) goto IF5416;
	local[2]= makeint(20);
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,1,local+2); /*error*/
	local[2]= w;
	goto IF5417;
IF5416:
	local[2]= NIL;
IF5417:
	local[2]= fqv[12];
	local[3]= fqv[31];
	local[4]= fqv[32];
	local[5]= fqv[33];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[34];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[35];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[32];
	local[5]= fqv[33];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[34];
	local[7]= fqv[36];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[21];
	local[6]= fqv[13];
	local[7]= fqv[37];
	local[8]= fqv[33];
	local[9]= argv[0];
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
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[32];
	local[8]= fqv[33];
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[38];
	local[10]= local[0];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
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
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[33];
	local[7]= argv[0];
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
BLK5393:
	ctx->vsp=local; return(local[0]);}

/*deflocal*/
static pointer F5559(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT5564;}
	local[0]= NIL;
ENT5564:
	if (n>=3) { local[1]=(argv[2]); goto ENT5563;}
	local[1]= NIL;
ENT5563:
ENT5562:
	if (n>3) maerror();
	w = argv[0];
	if (issymbol(w)) goto IF5583;
	local[2]= makeint(20);
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,1,local+2); /*error*/
	local[2]= w;
	goto IF5584;
IF5583:
	local[2]= NIL;
IF5584:
	local[2]= fqv[6];
	local[3]= fqv[32];
	local[4]= fqv[33];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[39];
	local[6]= local[0];
	local[7]= local[1];
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
	local[4]= fqv[33];
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
	w = cons(ctx,local[2],w);
	local[0]= w;
BLK5560:
	ctx->vsp=local; return(local[0]);}

/*defparameter*/
static pointer F5640(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT5644;}
	local[0]= NIL;
ENT5644:
ENT5643:
	if (n>3) maerror();
	w = argv[0];
	if (issymbol(w)) goto IF5661;
	local[1]= makeint(20);
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF5662;
IF5661:
	local[1]= NIL;
IF5662:
	local[1]= fqv[32];
	local[2]= fqv[33];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[38];
	local[4]= argv[1];
	local[5]= local[0];
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
	local[0]= w;
BLK5641:
	ctx->vsp=local; return(local[0]);}

/*defconstant*/
static pointer F5702(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT5706;}
	local[0]= NIL;
ENT5706:
ENT5705:
	if (n>3) maerror();
	w = argv[0];
	if (issymbol(w)) goto IF5723;
	local[1]= makeint(20);
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF5724;
IF5723:
	local[1]= NIL;
IF5724:
	local[1]= fqv[32];
	local[2]= fqv[33];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[40];
	local[4]= argv[1];
	local[5]= local[0];
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
	local[0]= w;
BLK5703:
	ctx->vsp=local; return(local[0]);}

/*dotimes*/
static pointer F5764(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST5767:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[41];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= fqv[5];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= fqv[42];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= local[1];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[43];
	local[5]= fqv[44];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[14];
	local[6]= fqv[45];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= local[0];
	local[8]= fqv[28];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= fqv[27];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)APPEND(ctx,2,local+7); /*append*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
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
BLK5765:
	ctx->vsp=local; return(local[0]);}

/*dolist*/
static pointer F5918(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST5921:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[46];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w = local[2];
	if (!iscons(w)) goto IF5952;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	if (fqv[43]!=local[3]) goto IF5952;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	local[3]= local[0];
	goto IF5953;
IF5952:
	local[2] = NIL;
	local[3]= local[2];
IF5953:
	local[3]= fqv[5];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= fqv[9];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= local[1];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= local[2];
	local[6]= fqv[14];
	local[7]= local[1];
	local[8]= fqv[28];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= fqv[47];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= local[0];
	local[10]= NIL;
	ctx->vsp=local+11;
	w=(pointer)APPEND(ctx,2,local+9); /*append*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
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
	local[0]= w;
BLK5919:
	ctx->vsp=local; return(local[0]);}

/*do-symbols*/
static pointer F6075(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST6078:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[48];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto IF6106;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	goto IF6107;
IF6106:
	local[3]= fqv[49];
IF6107:
	ctx->vsp=local+4;
	w=(pointer)GENSYM(ctx,0,local+4); /*gensym*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)GENSYM(ctx,0,local+5); /*gensym*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)GENSYM(ctx,0,local+6); /*gensym*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)GENSYM(ctx,0,local+7); /*gensym*/
	local[7]= w;
	local[8]= fqv[50];
	local[9]= local[2];
	local[10]= fqv[9];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= local[4];
	local[11]= fqv[51];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= local[5];
	local[12]= fqv[52];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= local[7];
	local[13]= local[4];
	w = fqv[53];
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= local[6];
	local[14]= fqv[54];
	local[15]= local[7];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[14];
	local[11]= fqv[45];
	local[12]= local[5];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[28];
	local[13]= local[2];
	local[14]= fqv[55];
	local[15]= local[7];
	local[16]= local[5];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[56];
	local[14]= local[5];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	local[14]= fqv[12];
	local[15]= fqv[57];
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	local[15]= cons(ctx,local[15],w);
	w = local[0];
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
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
	local[10]= cons(ctx,local[10],w);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	local[0]= w;
BLK6076:
	ctx->vsp=local; return(local[0]);}

/*do-external-symbols*/
static pointer F6302(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST6305:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[58];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto IF6333;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	goto IF6334;
IF6333:
	local[3]= fqv[49];
IF6334:
	ctx->vsp=local+4;
	w=(pointer)GENSYM(ctx,0,local+4); /*gensym*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)GENSYM(ctx,0,local+5); /*gensym*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)GENSYM(ctx,0,local+6); /*gensym*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)GENSYM(ctx,0,local+7); /*gensym*/
	local[7]= w;
	local[8]= fqv[50];
	local[9]= local[2];
	local[10]= fqv[9];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= local[4];
	local[11]= fqv[51];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= local[5];
	local[12]= fqv[59];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= local[7];
	local[13]= local[4];
	w = fqv[60];
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= local[6];
	local[14]= fqv[54];
	local[15]= local[7];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[14];
	local[11]= fqv[45];
	local[12]= local[5];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[28];
	local[13]= local[2];
	local[14]= fqv[55];
	local[15]= local[7];
	local[16]= local[5];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[56];
	local[14]= local[5];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	local[14]= fqv[12];
	local[15]= fqv[57];
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	local[15]= cons(ctx,local[15],w);
	w = local[0];
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
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
	local[10]= cons(ctx,local[10],w);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	local[0]= w;
BLK6303:
	ctx->vsp=local; return(local[0]);}

/*do-all-symbols*/
static pointer F6529(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST6532:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[61];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= fqv[62];
	local[3]= local[1];
	local[4]= fqv[63];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[4]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[64];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	w = local[0];
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[0]= w;
BLK6530:
	ctx->vsp=local; return(local[0]);}

/*psetq*/
static pointer F6606(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST6609:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
WHL6630:
	if (local[0]==NIL) goto WHX6631;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[4]= w;
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[4]= w;
	w = local[2];
	ctx->vsp=local+5;
	local[2] = cons(ctx,local[4],w);
	local[4]= fqv[65];
	ctx->vsp=local+5;
	w=(pointer)GENSYM(ctx,1,local+4); /*gensym*/
	local[4]= w;
	w = local[3];
	ctx->vsp=local+5;
	local[3] = cons(ctx,local[4],w);
	goto WHL6630;
WHX6631:
	local[4]= NIL;
BLK6632:
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)NREVERSE(ctx,1,local+4); /*nreverse*/
	local[1] = w;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)NREVERSE(ctx,1,local+4); /*nreverse*/
	local[2] = w;
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(pointer)NREVERSE(ctx,1,local+4); /*nreverse*/
	local[3] = w;
	local[4]= fqv[50];
	local[5]= (pointer)get_sym_func(fqv[66]);
	local[6]= local[3];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,3,local+5); /*mapcar*/
	local[5]= w;
	local[6]= fqv[28];
	local[7]= (pointer)get_sym_func(fqv[66]);
	local[8]= local[1];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)MAPCAN(ctx,3,local+7); /*mapcan*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[9];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	local[0]= w;
BLK6607:
	ctx->vsp=local; return(local[0]);}

/*do*/
static pointer F6796(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST6799:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[67];
	ctx->vsp=local+3;
	w=(pointer)GENSYM(ctx,1,local+2); /*gensym*/
	local[2]= w;
	w = local[1];
	if (!iscons(w)) goto IF6832;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	if (fqv[43]!=local[3]) goto IF6832;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	local[3]= local[0];
	goto IF6833;
IF6832:
	local[1] = NIL;
	local[3]= local[1];
IF6833:
	local[3]= fqv[8];
	local[4]= fqv[9];
	local[5]= fqv[5];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO6876,env,argv,local);
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[6]= w;
	local[7]= local[1];
	local[8]= fqv[10];
	local[9]= local[2];
	local[10]= fqv[21];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= fqv[68];
	local[13]= fqv[6];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= local[0];
	local[12]= fqv[69];
	ctx->vsp=local+13;
	local[13]= makeclosure(codevec,quotevec,CLO6927,env,argv,local);
	local[14]= argv[0];
	ctx->vsp=local+15;
	w=(pointer)MAPCAN(ctx,2,local+13); /*mapcan*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[11];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)APPEND(ctx,2,local+11); /*append*/
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
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	local[0]= w;
BLK6797:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO6876(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO6927(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF6995;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	goto IF6996;
IF6995:
	local[0]= NIL;
IF6996:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*do**/
static pointer F7025(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST7028:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[70];
	ctx->vsp=local+3;
	w=(pointer)GENSYM(ctx,1,local+2); /*gensym*/
	local[2]= w;
	w = local[1];
	if (!iscons(w)) goto IF7061;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	if (fqv[43]!=local[3]) goto IF7061;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	local[3]= local[0];
	goto IF7062;
IF7061:
	local[1] = NIL;
	local[3]= local[1];
IF7062:
	local[3]= fqv[8];
	local[4]= fqv[9];
	local[5]= fqv[50];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO7105,env,argv,local);
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[6]= w;
	local[7]= local[1];
	local[8]= fqv[10];
	local[9]= local[2];
	local[10]= fqv[21];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= fqv[68];
	local[13]= fqv[6];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= local[0];
	local[12]= fqv[28];
	ctx->vsp=local+13;
	local[13]= makeclosure(codevec,quotevec,CLO7156,env,argv,local);
	local[14]= argv[0];
	ctx->vsp=local+15;
	w=(pointer)MAPCAN(ctx,2,local+13); /*mapcan*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[11];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)APPEND(ctx,2,local+11); /*append*/
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
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	local[0]= w;
BLK7026:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO7105(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO7156(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF7224;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	goto IF7225;
IF7224:
	local[0]= NIL;
IF7225:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*prog*/
static pointer F7254(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST7257:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[8];
	local[2]= fqv[9];
	local[3]= fqv[5];
	local[4]= argv[0];
	local[5]= fqv[10];
	local[6]= local[0];
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)APPEND(ctx,2,local+6); /*append*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
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
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK7255:
	ctx->vsp=local; return(local[0]);}

/*prog**/
static pointer F7299(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST7302:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[8];
	local[2]= fqv[9];
	local[3]= fqv[50];
	local[4]= argv[0];
	local[5]= fqv[10];
	local[6]= local[0];
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)APPEND(ctx,2,local+6); /*append*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
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
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK7300:
	ctx->vsp=local; return(local[0]);}

/*casebody*/
static pointer F4167casebody(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF7355;
	local[0]= fqv[6];
	w = argv[0];
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	goto IF7356;
IF7355:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
IF7356:
	w = local[0];
	local[0]= w;
BLK7345:
	ctx->vsp=local; return(local[0]);}

/*casehead*/
static pointer F4170casehead(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[1];
	if (!!iscons(w)) goto IF7390;
	local[0]= argv[1];
	w = fqv[71];
	if (memq(local[0],w)==NIL) goto IF7396;
	local[0]= T;
	goto IF7397;
IF7396:
	local[0]= fqv[72];
	local[1]= argv[0];
	local[2]= fqv[33];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
IF7397:
	goto IF7391;
IF7390:
	local[0]= fqv[73];
	local[1]= argv[0];
	local[2]= fqv[33];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
IF7391:
	w = local[0];
	local[0]= w;
BLK7378:
	ctx->vsp=local; return(local[0]);}

/*case1*/
static pointer F4173case1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[1];
	if (!!iscons(w)) goto IF7441;
	local[0]= NIL;
	goto IF7442;
IF7441:
	local[0]= fqv[21];
	local[1]= argv[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)F4170casehead(ctx,2,local+1); /*casehead*/
	local[1]= w;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	ctx->vsp=local+3;
	w=(pointer)F4167casebody(ctx,1,local+2); /*casebody*/
	local[2]= w;
	local[3]= argv[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)F4173case1(ctx,2,local+3); /*case1*/
	local[3]= w;
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,5,local+0); /*list*/
	local[0]= w;
IF7442:
	w = local[0];
	local[0]= w;
BLK7429:
	ctx->vsp=local; return(local[0]);}

/*case*/
static pointer F7480(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST7483:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[74];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= NIL;
	local[3]= fqv[5];
	local[4]= local[1];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,2,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[4]= w;
	local[5]= local[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)F4173case1(ctx,2,local+5); /*case1*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[0]= w;
BLK7481:
	ctx->vsp=local; return(local[0]);}

/*classcasehead*/
static pointer F4177classcasehead(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	w = fqv[75];
	if (memq(local[0],w)==NIL) goto IF7538;
	local[0]= T;
	goto IF7539;
IF7538:
	w = argv[1];
	if (!!iscons(w)) goto IF7549;
	local[0]= fqv[76];
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	goto IF7550;
IF7549:
	local[0]= fqv[77];
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO7570,env,argv,local);
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
IF7550:
IF7539:
	w = local[0];
	local[0]= w;
BLK7526:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO7570(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[76];
	local[1]= env->c.clo.env1[0];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*classcase1*/
static pointer F4180classcase1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[1];
	if (!!iscons(w)) goto IF7612;
	local[0]= NIL;
	goto IF7613;
IF7612:
	local[0]= fqv[21];
	local[1]= argv[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)F4177classcasehead(ctx,2,local+1); /*classcasehead*/
	local[1]= w;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	ctx->vsp=local+3;
	w=(pointer)F4167casebody(ctx,1,local+2); /*casebody*/
	local[2]= w;
	local[3]= argv[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)F4180classcase1(ctx,2,local+3); /*classcase1*/
	local[3]= w;
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,5,local+0); /*list*/
	local[0]= w;
IF7613:
	w = local[0];
	local[0]= w;
BLK7600:
	ctx->vsp=local; return(local[0]);}

/*classcase*/
static pointer F7651(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST7654:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[78];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= fqv[5];
	local[3]= local[1];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[3]= w;
	local[4]= local[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)F4180classcase1(ctx,2,local+4); /*classcase1*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[0]= w;
BLK7652:
	ctx->vsp=local; return(local[0]);}

/*string*/
static pointer F4183string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!isstring(w)) goto IF7711;
	local[0]= argv[0];
	goto IF7712;
IF7711:
	w = argv[0];
	if (!issymbol(w)) goto IF7718;
	local[0]= *(ovafptr(argv[0],fqv[79]));
	ctx->vsp=local+1;
	w=(pointer)COPYSEQ(ctx,1,local+0); /*copy-seq*/
	local[0]= w;
	goto IF7719;
IF7718:
	w = argv[0];
	if (!isnum(w)) goto IF7728;
	local[0]= NIL;
	local[1]= fqv[80];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto IF7729;
IF7728:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF7729:
IF7719:
IF7712:
	w = local[0];
	local[0]= w;
BLK7701:
	ctx->vsp=local; return(local[0]);}

/*alias*/
static pointer F4187alias(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)SYMFUNC(ctx,1,local+0); /*symbol-function*/
	local[0]= w;
	local[1]= w;
	w = argv[0];
	w->c.obj.iv[3] = local[1];
	w = local[0];
	local[0]= w;
BLK7743:
	ctx->vsp=local; return(local[0]);}

/*caaar*/
static pointer F4193caaar(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK7769:
	ctx->vsp=local; return(local[0]);}

/*caadr*/
static pointer F4196caadr(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK7793:
	ctx->vsp=local; return(local[0]);}

/*cadar*/
static pointer F4199cadar(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK7817:
	ctx->vsp=local; return(local[0]);}

/*cdaar*/
static pointer F4202cdaar(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK7841:
	ctx->vsp=local; return(local[0]);}

/*cdadr*/
static pointer F4205cdadr(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK7865:
	ctx->vsp=local; return(local[0]);}

/*cddar*/
static pointer F4208cddar(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK7889:
	ctx->vsp=local; return(local[0]);}

/*cdddr*/
static pointer F4211cdddr(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK7913:
	ctx->vsp=local; return(local[0]);}

/*fourth*/
static pointer F4217fourth(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK7943:
	ctx->vsp=local; return(local[0]);}

/*fifth*/
static pointer F4220fifth(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK7969:
	ctx->vsp=local; return(local[0]);}

/*sixth*/
static pointer F4223sixth(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F4211cdddr(ctx,1,local+0); /*cdddr*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK7997:
	ctx->vsp=local; return(local[0]);}

/*seventh*/
static pointer F4226seventh(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F4232cddddr(ctx,1,local+0); /*cddddr*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK8021:
	ctx->vsp=local; return(local[0]);}

/*eighth*/
static pointer F4229eighth(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F4232cddddr(ctx,1,local+0); /*cddddr*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)F4235cadddr(ctx,1,local+0); /*cadddr*/
	local[0]= w;
BLK8045:
	ctx->vsp=local; return(local[0]);}

/*cddddr*/
static pointer F4232cddddr(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK8062:
	ctx->vsp=local; return(local[0]);}

/*cadddr*/
static pointer F4235cadddr(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK8088:
	ctx->vsp=local; return(local[0]);}

/*caaddr*/
static pointer F4238caaddr(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK8114:
	ctx->vsp=local; return(local[0]);}

/*cdaddr*/
static pointer F4241cdaddr(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK8140:
	ctx->vsp=local; return(local[0]);}

/*caddddr*/
static pointer F4244caddddr(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F4211cdddr(ctx,1,local+0); /*cdddr*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK8166:
	ctx->vsp=local; return(local[0]);}

/*flatten*/
static pointer F4247flatten(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT8191;}
	local[0]= NIL;
ENT8191:
ENT8190:
	if (n>2) maerror();
	if (argv[0]!=NIL) goto CON8207;
	local[1]= local[0];
	goto CON8205;
CON8207:
	w = argv[0];
	if (!!iscons(w)) goto CON8213;
	local[1]= argv[0];
	w = local[0];
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto CON8205;
CON8213:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F4247flatten(ctx,2,local+2); /*flatten*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F4247flatten(ctx,2,local+1); /*flatten*/
	local[1]= w;
	goto CON8205;
CON8223:
	local[1]= NIL;
CON8205:
	w = local[1];
	local[0]= w;
BLK8188:
	ctx->vsp=local; return(local[0]);}

/*list-insert*/
static pointer F4250list_insert(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[2]!=NIL) goto CON8261;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto CON8259;
CON8261:
	local[0]= argv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto CON8269;
	local[0]= argv[2];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	local[0]= w;
	goto CON8259;
CON8269:
	local[0]= argv[1];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	if (w==NIL) goto CON8283;
	local[0]= argv[0];
	w = argv[2];
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	goto CON8259;
CON8283:
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)NTHCDR(ctx,2,local+1); /*nthcdr*/
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)SUB1(ctx,1,local+1); /*1-*/
	local[1]= w;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)NTHCDR(ctx,2,local+1); /*nthcdr*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)RPLACD(ctx,2,local+1); /*rplacd*/
	w = argv[2];
	local[0]= w;
	goto CON8259;
CON8293:
	local[0]= NIL;
CON8259:
	w = local[0];
	local[0]= w;
BLK8245:
	ctx->vsp=local; return(local[0]);}

/*list-delete*/
static pointer F4253list_delete(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	if (w==NIL) goto IF8342;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	local[0]= argv[0];
	goto IF8343;
IF8342:
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)SUB1(ctx,1,local+0); /*1-*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)NTHCDR(ctx,2,local+0); /*nthcdr*/
	local[0]= w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)ADD1(ctx,1,local+1); /*1+*/
	local[1]= w;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)NTHCDR(ctx,2,local+1); /*nthcdr*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)RPLACD(ctx,2,local+0); /*rplacd*/
	local[0]= w;
IF8343:
	w = argv[0];
	local[0]= w;
BLK8330:
	ctx->vsp=local; return(local[0]);}

/*adjoin*/
static pointer F4256adjoin(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[81], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY8390;
	local[0] = (pointer)get_sym_func(fqv[72]);
KEY8390:
	if (n & (1<<1)) goto KEY8397;
	local[1] = NIL;
KEY8397:
	if (n & (1<<2)) goto KEY8402;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY8402:
	local[3]= argv[0];
	local[4]= argv[1];
	local[5]= fqv[23];
	local[6]= local[0];
	local[7]= fqv[24];
	local[8]= local[1];
	local[9]= fqv[25];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)F4292member(ctx,8,local+3); /*member*/
	if (w==NIL) goto IF8413;
	local[3]= argv[1];
	goto IF8414;
IF8413:
	local[3]= argv[0];
	w = argv[1];
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
IF8414:
	w = local[3];
	local[0]= w;
BLK8377:
	ctx->vsp=local; return(local[0]);}

/*union*/
static pointer F4259union(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[83], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY8452;
	local[0] = (pointer)get_sym_func(fqv[72]);
KEY8452:
	if (n & (1<<1)) goto KEY8459;
	local[1] = NIL;
KEY8459:
	if (n & (1<<2)) goto KEY8464;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY8464:
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[0];
WHL8501:
	if (local[5]==NIL) goto WHX8502;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[2];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)FUNCALL(ctx,2,local+6); /*funcall*/
	local[6]= w;
	local[7]= local[3];
	local[8]= fqv[23];
	local[9]= local[0];
	local[10]= fqv[24];
	local[11]= local[1];
	local[12]= fqv[25];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)F4292member(ctx,8,local+6); /*member*/
	if (w!=NIL) goto IF8551;
	local[6]= local[4];
	w = local[3];
	ctx->vsp=local+7;
	local[3] = cons(ctx,local[6],w);
	local[6]= local[3];
	goto IF8552;
IF8551:
	local[6]= NIL;
IF8552:
	goto WHL8501;
WHX8502:
	local[6]= NIL;
BLK8503:
	w = NIL;
	local[4]= NIL;
	local[5]= argv[1];
WHL8606:
	if (local[5]==NIL) goto WHX8607;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[2];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)FUNCALL(ctx,2,local+6); /*funcall*/
	local[6]= w;
	local[7]= local[3];
	local[8]= fqv[23];
	local[9]= local[0];
	local[10]= fqv[24];
	local[11]= local[1];
	local[12]= fqv[25];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)F4292member(ctx,8,local+6); /*member*/
	if (w!=NIL) goto IF8656;
	local[6]= local[4];
	w = local[3];
	ctx->vsp=local+7;
	local[3] = cons(ctx,local[6],w);
	local[6]= local[3];
	goto IF8657;
IF8656:
	local[6]= NIL;
IF8657:
	goto WHL8606;
WHX8607:
	local[6]= NIL;
BLK8608:
	w = NIL;
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(pointer)REVERSE(ctx,1,local+4); /*reverse*/
	local[0]= w;
BLK8439:
	ctx->vsp=local; return(local[0]);}

/*intersection*/
static pointer F4262intersection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[84], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY8713;
	local[0] = (pointer)get_sym_func(fqv[72]);
KEY8713:
	if (n & (1<<1)) goto KEY8720;
	local[1] = NIL;
KEY8720:
	if (n & (1<<2)) goto KEY8725;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY8725:
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[0];
WHL8762:
	if (local[5]==NIL) goto WHX8763;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[2];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)FUNCALL(ctx,2,local+6); /*funcall*/
	local[6]= w;
	local[7]= argv[1];
	local[8]= fqv[23];
	local[9]= local[0];
	local[10]= fqv[24];
	local[11]= local[1];
	local[12]= fqv[25];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)F4292member(ctx,8,local+6); /*member*/
	if (w==NIL) goto IF8811;
	local[6]= local[4];
	w = local[3];
	ctx->vsp=local+7;
	local[3] = cons(ctx,local[6],w);
	local[6]= local[3];
	goto IF8812;
IF8811:
	local[6]= NIL;
IF8812:
	goto WHL8762;
WHX8763:
	local[6]= NIL;
BLK8764:
	w = NIL;
	w = local[3];
	local[0]= w;
BLK8700:
	ctx->vsp=local; return(local[0]);}

/*set-difference*/
static pointer F4265set_difference(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[85], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY8864;
	local[0] = (pointer)get_sym_func(fqv[72]);
KEY8864:
	if (n & (1<<1)) goto KEY8871;
	local[1] = NIL;
KEY8871:
	if (n & (1<<2)) goto KEY8876;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY8876:
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[0];
WHL8913:
	if (local[5]==NIL) goto WHX8914;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[2];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)FUNCALL(ctx,2,local+6); /*funcall*/
	local[6]= w;
	local[7]= argv[1];
	local[8]= fqv[23];
	local[9]= local[0];
	local[10]= fqv[24];
	local[11]= local[1];
	local[12]= fqv[25];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)F4292member(ctx,8,local+6); /*member*/
	if (w!=NIL) goto IF8963;
	local[6]= local[4];
	w = local[3];
	ctx->vsp=local+7;
	local[3] = cons(ctx,local[6],w);
	local[6]= local[3];
	goto IF8964;
IF8963:
	local[6]= NIL;
IF8964:
	goto WHL8913;
WHX8914:
	local[6]= NIL;
BLK8915:
	w = NIL;
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(pointer)NREVERSE(ctx,1,local+4); /*nreverse*/
	local[0]= w;
BLK8851:
	ctx->vsp=local; return(local[0]);}

/*set-exclusive-or*/
static pointer F4268set_exclusive_or(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[86], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY9021;
	local[0] = (pointer)get_sym_func(fqv[72]);
KEY9021:
	if (n & (1<<1)) goto KEY9028;
	local[1] = NIL;
KEY9028:
	if (n & (1<<2)) goto KEY9033;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY9033:
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[0];
WHL9072:
	if (local[6]==NIL) goto WHX9073;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[2];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)FUNCALL(ctx,2,local+7); /*funcall*/
	local[5] = w;
	local[7]= local[5];
	local[8]= argv[1];
	local[9]= fqv[23];
	local[10]= local[0];
	local[11]= fqv[24];
	local[12]= local[1];
	local[13]= fqv[25];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)F4292member(ctx,8,local+7); /*member*/
	if (w!=NIL) goto IF9132;
	local[7]= local[5];
	w = local[3];
	ctx->vsp=local+8;
	local[3] = cons(ctx,local[7],w);
	local[7]= local[3];
	goto IF9133;
IF9132:
	local[7]= NIL;
IF9133:
	goto WHL9072;
WHX9073:
	local[7]= NIL;
BLK9074:
	w = NIL;
	local[5]= NIL;
	local[6]= argv[1];
WHL9185:
	if (local[6]==NIL) goto WHX9186;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[2];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)FUNCALL(ctx,2,local+7); /*funcall*/
	local[5] = w;
	local[7]= local[5];
	local[8]= argv[0];
	local[9]= fqv[23];
	local[10]= local[0];
	local[11]= fqv[24];
	local[12]= local[1];
	local[13]= fqv[25];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)F4292member(ctx,8,local+7); /*member*/
	if (w!=NIL) goto IF9245;
	local[7]= local[5];
	w = local[4];
	ctx->vsp=local+8;
	local[4] = cons(ctx,local[7],w);
	local[7]= local[4];
	goto IF9246;
IF9245:
	local[7]= NIL;
IF9246:
	goto WHL9185;
WHX9186:
	local[7]= NIL;
BLK9187:
	w = NIL;
	local[5]= local[3];
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)NCONC(ctx,2,local+5); /*nconc*/
	local[0]= w;
BLK9008:
	ctx->vsp=local; return(local[0]);}

/*rotate-list*/
static pointer F4271rotate_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	local[0]= w;
BLK9288:
	ctx->vsp=local; return(local[0]);}

/*last*/
static pointer F4274last(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
WHL9324:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	if (!iscons(w)) goto WHX9325;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	goto WHL9324;
WHX9325:
	local[0]= NIL;
BLK9326:
	w = argv[0];
	local[0]= w;
BLK9314:
	ctx->vsp=local; return(local[0]);}

/*copy-tree*/
static pointer F4277copy_tree(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= T;
	local[1]= T;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SUBST(ctx,3,local+0); /*subst*/
	local[0]= w;
BLK9351:
	ctx->vsp=local; return(local[0]);}

/*copy-list*/
static pointer F4280copy_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)REVERSE(ctx,1,local+0); /*reverse*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)NREVERSE(ctx,1,local+0); /*nreverse*/
	local[0]= w;
BLK9366:
	ctx->vsp=local; return(local[0]);}

/*nreconc*/
static pointer F4283nreconc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)NREVERSE(ctx,1,local+0); /*nreverse*/
	local[0]= w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	local[0]= w;
BLK9383:
	ctx->vsp=local; return(local[0]);}

/*rassoc*/
static pointer F4286rassoc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[1];
WHL9432:
	if (local[1]==NIL) goto WHX9433;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)EQUAL(ctx,2,local+2); /*equal*/
	if (w==NIL) goto IF9481;
	w = local[0];
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK9403;
	goto IF9482;
IF9481:
	local[2]= NIL;
IF9482:
	goto WHL9432;
WHX9433:
	local[2]= NIL;
BLK9434:
	w = NIL;
	local[0]= w;
BLK9403:
	ctx->vsp=local; return(local[0]);}

/*acons*/
static pointer F4289acons(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	w = argv[1];
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	w = argv[2];
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK9503:
	ctx->vsp=local; return(local[0]);}

/*member*/
static pointer F4292member(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[87], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY9542;
	local[0] = NIL;
KEY9542:
	if (n & (1<<1)) goto KEY9547;
	local[1] = NIL;
KEY9547:
	if (n & (1<<2)) goto KEY9552;
	local[2] = NIL;
KEY9552:
	local[3]= argv[0];
	local[4]= argv[1];
	local[5]= local[0];
	local[6]= local[1];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SUPERMEMBER(ctx,5,local+3); /*supermember*/
	local[0]= w;
BLK9529:
	ctx->vsp=local; return(local[0]);}

/*assoc*/
static pointer F4295assoc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[88], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY9583;
	local[0] = NIL;
KEY9583:
	if (n & (1<<1)) goto KEY9588;
	local[1] = NIL;
KEY9588:
	if (n & (1<<2)) goto KEY9593;
	local[2] = NIL;
KEY9593:
	local[3]= argv[0];
	local[4]= argv[1];
	local[5]= local[0];
	local[6]= local[1];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SUPERASSOC(ctx,5,local+3); /*superassoc*/
	local[0]= w;
BLK9570:
	ctx->vsp=local; return(local[0]);}

/*subsetp*/
static pointer F4298subsetp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[89], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY9624;
	local[0] = NIL;
KEY9624:
	if (n & (1<<1)) goto KEY9629;
	local[1] = NIL;
KEY9629:
	if (n & (1<<2)) goto KEY9634;
	local[2] = NIL;
KEY9634:
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO9644,env,argv,local);
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F4500every(ctx,2,local+3); /*every*/
	local[0]= w;
BLK9611:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO9644(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env1[1];
	local[2]= fqv[25];
	local[3]= env->c.clo.env2[0];
	local[4]= fqv[23];
	local[5]= env->c.clo.env2[1];
	local[6]= fqv[24];
	local[7]= env->c.clo.env2[2];
	ctx->vsp=local+8;
	w=(pointer)F4292member(ctx,8,local+0); /*member*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*maplist*/
static pointer F4301maplist(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST9676:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]==NIL) goto IF9693;
	local[3]= NIL;
	local[4]= NIL;
WHL9710:
	if (argv[1]==NIL) goto WHX9711;
	local[3] = NIL;
	local[5]= argv[1];
	w = local[3];
	ctx->vsp=local+6;
	local[3] = cons(ctx,local[5],w);
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	local[4] = local[0];
WHL9754:
	if (local[4]==NIL) goto WHX9755;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w = local[3];
	ctx->vsp=local+6;
	local[3] = cons(ctx,local[5],w);
	local[5]= local[4];
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.cdr;
	ctx->vsp=local+7;
	w=(pointer)RPLACA2(ctx,2,local+5); /*rplaca2*/
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	goto WHL9754;
WHX9755:
	local[5]= NIL;
BLK9756:
	local[5]= argv[0];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)NREVERSE(ctx,1,local+6); /*nreverse*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,2,local+5); /*apply*/
	local[5]= w;
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	goto WHL9710;
WHX9711:
	local[5]= NIL;
BLK9712:
	w = local[5];
	local[3]= w;
	goto IF9694;
IF9693:
WHL9818:
	if (argv[1]==NIL) goto WHX9819;
	local[3]= argv[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)FUNCALL(ctx,2,local+3); /*funcall*/
	local[3]= w;
	w = local[2];
	ctx->vsp=local+4;
	local[2] = cons(ctx,local[3],w);
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	goto WHL9818;
WHX9819:
	local[3]= NIL;
BLK9820:
IF9694:
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	local[0]= w;
BLK9674:
	ctx->vsp=local; return(local[0]);}

/*mapcon*/
static pointer F4304mapcon(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST9859:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]==NIL) goto IF9876;
	local[3]= NIL;
	local[4]= NIL;
WHL9893:
	if (argv[1]==NIL) goto WHX9894;
	local[3] = NIL;
	local[5]= argv[1];
	w = local[3];
	ctx->vsp=local+6;
	local[3] = cons(ctx,local[5],w);
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	local[4] = local[0];
WHL9937:
	if (local[4]==NIL) goto WHX9938;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w = local[3];
	ctx->vsp=local+6;
	local[3] = cons(ctx,local[5],w);
	local[5]= local[4];
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.cdr;
	ctx->vsp=local+7;
	w=(pointer)RPLACA2(ctx,2,local+5); /*rplaca2*/
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	goto WHL9937;
WHX9938:
	local[5]= NIL;
BLK9939:
	local[5]= argv[0];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)NREVERSE(ctx,1,local+6); /*nreverse*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,2,local+5); /*apply*/
	local[5]= w;
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)NCONC(ctx,2,local+5); /*nconc*/
	local[2] = w;
	goto WHL9893;
WHX9894:
	local[5]= NIL;
BLK9895:
	w = local[5];
	local[3]= w;
	goto IF9877;
IF9876:
WHL9999:
	if (argv[1]==NIL) goto WHX10000;
	local[3]= argv[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)FUNCALL(ctx,2,local+3); /*funcall*/
	local[3]= w;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)NCONC(ctx,2,local+3); /*nconc*/
	local[2] = w;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	goto WHL9999;
WHX10000:
	local[3]= NIL;
BLK10001:
IF9877:
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	local[0]= w;
BLK9857:
	ctx->vsp=local; return(local[0]);}

/*find*/
static pointer F4307find(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[90], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10051;
	local[0] = makeint(0);
KEY10051:
	if (n & (1<<1)) goto KEY10056;
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[1] = w;
KEY10056:
	if (n & (1<<2)) goto KEY10064;
	local[2] = (pointer)get_sym_func(fqv[72]);
KEY10064:
	if (n & (1<<3)) goto KEY10071;
	local[3] = NIL;
KEY10071:
	if (n & (1<<4)) goto KEY10076;
	local[4] = (pointer)get_sym_func(fqv[82]);
KEY10076:
	local[5]= argv[0];
	local[6]= argv[1];
	local[7]= local[2];
	local[8]= local[3];
	local[9]= local[4];
	local[10]= NIL;
	local[11]= NIL;
	local[12]= local[0];
	local[13]= local[1];
	ctx->vsp=local+14;
	w=(pointer)FIND(ctx,9,local+5); /*system::raw-find*/
	local[0]= w;
BLK10036:
	ctx->vsp=local; return(local[0]);}

/*find-if*/
static pointer F4310find_if(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[91], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10111;
	local[0] = makeint(0);
KEY10111:
	if (n & (1<<1)) goto KEY10116;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[1] = w;
KEY10116:
	if (n & (1<<2)) goto KEY10124;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY10124:
	local[3]= NIL;
	local[4]= argv[1];
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[2];
	local[8]= argv[0];
	local[9]= NIL;
	local[10]= local[0];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)FIND(ctx,9,local+3); /*system::raw-find*/
	local[0]= w;
BLK10098:
	ctx->vsp=local; return(local[0]);}

/*find-if-not*/
static pointer F4313find_if_not(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[92], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10157;
	local[0] = makeint(0);
KEY10157:
	if (n & (1<<1)) goto KEY10162;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[1] = w;
KEY10162:
	if (n & (1<<2)) goto KEY10170;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY10170:
	local[3]= NIL;
	local[4]= argv[1];
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[2];
	local[8]= NIL;
	local[9]= argv[0];
	local[10]= local[0];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)FIND(ctx,9,local+3); /*system::raw-find*/
	local[0]= w;
BLK10144:
	ctx->vsp=local; return(local[0]);}

/*position*/
static pointer F4316position(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[93], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10206;
	local[0] = makeint(0);
KEY10206:
	if (n & (1<<1)) goto KEY10211;
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[1] = w;
KEY10211:
	if (n & (1<<2)) goto KEY10219;
	local[2] = makeint(1);
KEY10219:
	if (n & (1<<3)) goto KEY10224;
	local[3] = (pointer)get_sym_func(fqv[72]);
KEY10224:
	if (n & (1<<4)) goto KEY10231;
	local[4] = NIL;
KEY10231:
	if (n & (1<<5)) goto KEY10236;
	local[5] = (pointer)get_sym_func(fqv[82]);
KEY10236:
	local[6]= argv[0];
	local[7]= argv[1];
	local[8]= local[3];
	local[9]= local[4];
	local[10]= local[5];
	local[11]= NIL;
	local[12]= NIL;
	local[13]= local[0];
	local[14]= local[1];
	local[15]= local[2];
	ctx->vsp=local+16;
	w=(pointer)POSITION(ctx,10,local+6); /*system::raw-position*/
	local[0]= w;
BLK10190:
	ctx->vsp=local; return(local[0]);}

/*position-if*/
static pointer F4319position_if(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[94], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10273;
	local[0] = makeint(0);
KEY10273:
	if (n & (1<<1)) goto KEY10278;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY10278:
	if (n & (1<<2)) goto KEY10286;
	local[2] = makeint(1);
KEY10286:
	if (n & (1<<3)) goto KEY10291;
	local[3] = (pointer)get_sym_func(fqv[82]);
KEY10291:
	local[4]= NIL;
	local[5]= argv[1];
	local[6]= NIL;
	local[7]= NIL;
	local[8]= local[3];
	local[9]= argv[0];
	local[10]= NIL;
	local[11]= local[0];
	local[12]= local[1];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)POSITION(ctx,10,local+4); /*system::raw-position*/
	local[0]= w;
BLK10259:
	ctx->vsp=local; return(local[0]);}

/*position-if-not*/
static pointer F4322position_if_not(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[95], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10326;
	local[0] = makeint(0);
KEY10326:
	if (n & (1<<1)) goto KEY10331;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY10331:
	if (n & (1<<2)) goto KEY10339;
	local[2] = makeint(1);
KEY10339:
	if (n & (1<<3)) goto KEY10344;
	local[3] = (pointer)get_sym_func(fqv[82]);
KEY10344:
	local[4]= NIL;
	local[5]= argv[1];
	local[6]= NIL;
	local[7]= NIL;
	local[8]= local[3];
	local[9]= NIL;
	local[10]= argv[0];
	local[11]= local[0];
	local[12]= local[1];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)POSITION(ctx,10,local+4); /*system::raw-position*/
	local[0]= w;
BLK10312:
	ctx->vsp=local; return(local[0]);}

/*count*/
static pointer F4325count(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[96], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10380;
	local[0] = makeint(0);
KEY10380:
	if (n & (1<<1)) goto KEY10385;
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[1] = w;
KEY10385:
	if (n & (1<<2)) goto KEY10393;
	local[2] = (pointer)get_sym_func(fqv[72]);
KEY10393:
	if (n & (1<<3)) goto KEY10400;
	local[3] = NIL;
KEY10400:
	if (n & (1<<4)) goto KEY10405;
	local[4] = (pointer)get_sym_func(fqv[82]);
KEY10405:
	local[5]= argv[0];
	local[6]= argv[1];
	local[7]= local[2];
	local[8]= local[3];
	local[9]= local[4];
	local[10]= NIL;
	local[11]= NIL;
	local[12]= local[0];
	local[13]= local[1];
	ctx->vsp=local+14;
	w=(pointer)COUNT(ctx,9,local+5); /*system::raw-count*/
	local[0]= w;
BLK10365:
	ctx->vsp=local; return(local[0]);}

/*count-if*/
static pointer F4328count_if(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[97], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10440;
	local[0] = makeint(0);
KEY10440:
	if (n & (1<<1)) goto KEY10445;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[1] = w;
KEY10445:
	if (n & (1<<2)) goto KEY10453;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY10453:
	local[3]= NIL;
	local[4]= argv[1];
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[2];
	local[8]= argv[0];
	local[9]= NIL;
	local[10]= local[0];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)COUNT(ctx,9,local+3); /*system::raw-count*/
	local[0]= w;
BLK10427:
	ctx->vsp=local; return(local[0]);}

/*count-if-not*/
static pointer F4331count_if_not(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[98], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10486;
	local[0] = makeint(0);
KEY10486:
	if (n & (1<<1)) goto KEY10491;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[1] = w;
KEY10491:
	if (n & (1<<2)) goto KEY10499;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY10499:
	local[3]= NIL;
	local[4]= argv[1];
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[2];
	local[8]= NIL;
	local[9]= argv[0];
	local[10]= local[0];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)COUNT(ctx,9,local+3); /*system::raw-count*/
	local[0]= w;
BLK10473:
	ctx->vsp=local; return(local[0]);}

/*member-if*/
static pointer F4334member_if(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[99], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10530;
	local[0] = (pointer)get_sym_func(fqv[82]);
KEY10530:
WHL10541:
	if (argv[1]==NIL) goto WHX10542;
	local[1]= argv[0];
	local[2]= local[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)FUNCALL(ctx,2,local+2); /*funcall*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FUNCALL(ctx,2,local+1); /*funcall*/
	if (w==NIL) goto IF10549;
	w = argv[1];
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK10519;
	goto IF10550;
IF10549:
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	local[1]= argv[1];
IF10550:
	goto WHL10541;
WHX10542:
	local[1]= NIL;
BLK10543:
	w = local[1];
	local[0]= w;
BLK10519:
	ctx->vsp=local; return(local[0]);}

/*member-if-not*/
static pointer F4337member_if_not(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[100], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10592;
	local[0] = (pointer)get_sym_func(fqv[82]);
KEY10592:
WHL10603:
	if (argv[1]==NIL) goto WHX10604;
	local[1]= argv[0];
	local[2]= local[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)FUNCALL(ctx,2,local+2); /*funcall*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FUNCALL(ctx,2,local+1); /*funcall*/
	if (w!=NIL) goto IF10611;
	w = argv[1];
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK10581;
	goto IF10612;
IF10611:
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	local[1]= argv[1];
IF10612:
	goto WHL10603;
WHX10604:
	local[1]= NIL;
BLK10605:
	w = local[1];
	local[0]= w;
BLK10581:
	ctx->vsp=local; return(local[0]);}

/*collect-if*/
static pointer F4340collect_if(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[1];
WHL10676:
	if (local[3]==NIL) goto WHX10677;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= argv[0];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)FUNCALL(ctx,2,local+4); /*funcall*/
	if (w==NIL) goto IF10725;
	local[4]= local[2];
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[1];
	goto IF10726;
IF10725:
	local[4]= NIL;
IF10726:
	goto WHL10676;
WHX10677:
	local[4]= NIL;
BLK10678:
	w = NIL;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)NREVERSE(ctx,1,local+2); /*nreverse*/
	local[0]= w;
BLK10643:
	ctx->vsp=local; return(local[0]);}

/*collect-instances*/
static pointer F4343collect_instances(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO10767,env,argv,local);
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F4247flatten(ctx,1,local+1); /*flatten*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F4340collect_if(ctx,2,local+0); /*collect-if*/
	local[0]= w;
BLK10754:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO10767(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env1[0];
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*pairlis*/
static pointer F4346pairlis(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT10793;}
	local[0]= NIL;
ENT10793:
ENT10792:
	if (n>3) maerror();
	if (argv[0]==NIL) goto IF10809;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)F4346pairlis(ctx,3,local+2); /*pairlis*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto IF10810;
IF10809:
	local[1]= local[0];
IF10810:
	w = local[1];
	local[0]= w;
BLK10790:
	ctx->vsp=local; return(local[0]);}

/*transpose-list*/
static pointer F4349transpose_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= makeint(0);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
WHL10894:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX10895;
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO10908,env,argv,local);
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL10894;
WHX10895:
	local[3]= NIL;
BLK10896:
	w = NIL;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)NREVERSE(ctx,1,local+1); /*nreverse*/
	local[0]= w;
BLK10846:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO10908(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env2[1];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)NTH(ctx,2,local+0); /*nth*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*make-list*/
static pointer F4352make_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[101], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY10961;
	local[0] = NIL;
KEY10961:
	local[1]= NIL;
	w = argv[0];
	if (isint(w)) goto IF10980;
	local[2]= fqv[102];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,1,local+2); /*error*/
	local[2]= w;
	goto IF10981;
IF10980:
	local[2]= NIL;
IF10981:
	local[2]= makeint(0);
	local[3]= argv[0];
WHL11015:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX11016;
	local[4]= local[0];
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL11015;
WHX11016:
	local[4]= NIL;
BLK11017:
	w = local[1];
	local[0]= w;
BLK10952:
	ctx->vsp=local; return(local[0]);}

/*make-sequence*/
static pointer F4355make_sequence(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[103], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY11062;
	local[0] = NIL;
KEY11062:
	local[1]= argv[0];
	w = fqv[104];
	if (memq(local[1],w)!=NIL) goto OR11073;
	local[1]= argv[0];
	if (loadglobal(fqv[19])==local[1]) goto OR11073;
	goto IF11071;
OR11073:
	local[1]= argv[1];
	local[2]= fqv[105];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F4352make_list(ctx,3,local+1); /*make-list*/
	local[1]= w;
	goto IF11072;
IF11071:
	local[1]= argv[1];
	local[2]= fqv[106];
	local[3]= argv[0];
	local[4]= fqv[105];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[0])(ctx,5,local+1,&ftab[0],fqv[107]); /*make-array*/
	local[1]= w;
IF11072:
	w = local[1];
	local[0]= w;
BLK11051:
	ctx->vsp=local; return(local[0]);}

/*fill*/
static pointer F4358fill(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[108], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY11119;
	local[0] = makeint(0);
KEY11119:
	if (n & (1<<1)) goto KEY11124;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[1] = w;
KEY11124:
	local[2]= argv[0];
	local[3]= argv[1];
	local[4]= local[0];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)FILL(ctx,4,local+2); /*system::raw-fill*/
	local[0]= w;
BLK11107:
	ctx->vsp=local; return(local[0]);}

/*replace*/
static pointer F4361replace(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[109], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY11158;
	local[0] = makeint(0);
KEY11158:
	if (n & (1<<1)) goto KEY11163;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY11163:
	if (n & (1<<2)) goto KEY11171;
	local[2] = makeint(0);
KEY11171:
	if (n & (1<<3)) goto KEY11176;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[3] = w;
KEY11176:
	local[4]= argv[0];
	local[5]= local[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	local[6]= local[3];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MIN(ctx,2,local+5); /*min*/
	local[5]= w;
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LISTP(ctx,1,local+6); /*listp*/
	if (w==NIL) goto CON11218;
	local[6]= local[0];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)NTHCDR(ctx,2,local+6); /*nthcdr*/
	argv[0] = w;
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)LISTP(ctx,1,local+6); /*listp*/
	if (w==NIL) goto CON11238;
	local[6]= local[2];
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)NTHCDR(ctx,2,local+6); /*nthcdr*/
	argv[1] = w;
	local[6]= makeint(0);
	local[7]= local[5];
WHL11279:
	local[8]= local[6];
	w = local[7];
	if ((eusinteger_t)local[8] >= (eusinteger_t)w) goto WHX11280;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	w = local[8];
	local[8]= w;
	local[9]= w;
	*(ovafptr(argv[0],fqv[16])) = local[9];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[8];
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[6] = w;
	goto WHL11279;
WHX11280:
	local[8]= NIL;
BLK11281:
	w = NIL;
	local[6]= w;
	goto CON11236;
CON11238:
	local[6]= makeint(0);
	local[7]= local[5];
WHL11401:
	local[8]= local[6];
	w = local[7];
	if ((eusinteger_t)local[8] >= (eusinteger_t)w) goto WHX11402;
	local[8]= argv[1];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	local[9]= w;
	*(ovafptr(argv[0],fqv[16])) = local[9];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[2] = w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[8];
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[6] = w;
	goto WHL11401;
WHX11402:
	local[8]= NIL;
BLK11403:
	w = NIL;
	local[6]= w;
	goto CON11236;
CON11374:
	local[6]= NIL;
CON11236:
	goto CON11216;
CON11218:
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)LISTP(ctx,1,local+6); /*listp*/
	if (w==NIL) goto CON11475;
	local[6]= local[2];
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)NTHCDR(ctx,2,local+6); /*nthcdr*/
	argv[1] = w;
	local[6]= makeint(0);
	local[7]= local[5];
WHL11516:
	local[8]= local[6];
	w = local[7];
	if ((eusinteger_t)local[8] >= (eusinteger_t)w) goto WHX11517;
	local[8]= argv[0];
	local[9]= local[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	w = local[10];
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)ASET(ctx,3,local+8); /*aset*/
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[0] = w;
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[6] = w;
	goto WHL11516;
WHX11517:
	local[8]= NIL;
BLK11518:
	w = NIL;
	local[6]= w;
	goto CON11216;
CON11475:
	local[6]= argv[0];
	local[7]= argv[1];
	local[8]= local[0];
	local[9]= local[1];
	local[10]= local[2];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)VECREPLACE(ctx,6,local+6); /*system::vector-replace*/
	local[6]= w;
	goto CON11216;
CON11585:
	local[6]= NIL;
CON11216:
	w = local[4];
	local[0]= w;
BLK11144:
	ctx->vsp=local; return(local[0]);}

/*remove*/
static pointer F4364remove(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[110], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY11619;
	local[0] = makeint(0);
KEY11619:
	if (n & (1<<1)) goto KEY11624;
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[1] = w;
KEY11624:
	if (n & (1<<2)) goto KEY11632;
	local[2] = (pointer)get_sym_func(fqv[72]);
KEY11632:
	if (n & (1<<3)) goto KEY11639;
	local[3] = NIL;
KEY11639:
	if (n & (1<<4)) goto KEY11644;
	local[4] = makeint(1000000);
KEY11644:
	if (n & (1<<5)) goto KEY11649;
	local[5] = (pointer)get_sym_func(fqv[82]);
KEY11649:
	local[6]= argv[0];
	local[7]= argv[1];
	local[8]= local[2];
	local[9]= local[3];
	local[10]= local[5];
	local[11]= NIL;
	local[12]= NIL;
	local[13]= local[0];
	local[14]= local[1];
	local[15]= local[4];
	ctx->vsp=local+16;
	w=(pointer)UNIREMOVE(ctx,10,local+6); /*system::universal-remove*/
	local[0]= w;
BLK11603:
	ctx->vsp=local; return(local[0]);}

/*remove-if*/
static pointer F4367remove_if(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[111], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY11686;
	local[0] = makeint(0);
KEY11686:
	if (n & (1<<1)) goto KEY11691;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY11691:
	if (n & (1<<2)) goto KEY11699;
	local[2] = makeint(1000000);
KEY11699:
	if (n & (1<<3)) goto KEY11704;
	local[3] = (pointer)get_sym_func(fqv[82]);
KEY11704:
	local[4]= NIL;
	local[5]= argv[1];
	local[6]= NIL;
	local[7]= NIL;
	local[8]= local[3];
	local[9]= argv[0];
	local[10]= NIL;
	local[11]= local[0];
	local[12]= local[1];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)UNIREMOVE(ctx,10,local+4); /*system::universal-remove*/
	local[0]= w;
BLK11672:
	ctx->vsp=local; return(local[0]);}

/*remove-if-not*/
static pointer F4370remove_if_not(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[112], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY11739;
	local[0] = makeint(0);
KEY11739:
	if (n & (1<<1)) goto KEY11744;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY11744:
	if (n & (1<<2)) goto KEY11752;
	local[2] = makeint(1000000);
KEY11752:
	if (n & (1<<3)) goto KEY11757;
	local[3] = (pointer)get_sym_func(fqv[82]);
KEY11757:
	local[4]= NIL;
	local[5]= argv[1];
	local[6]= NIL;
	local[7]= NIL;
	local[8]= local[3];
	local[9]= NIL;
	local[10]= argv[0];
	local[11]= local[0];
	local[12]= local[1];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)UNIREMOVE(ctx,10,local+4); /*system::universal-remove*/
	local[0]= w;
BLK11725:
	ctx->vsp=local; return(local[0]);}

/*delete*/
static pointer F4373delete(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[113], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY11794;
	local[0] = makeint(0);
KEY11794:
	if (n & (1<<1)) goto KEY11799;
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[1] = w;
KEY11799:
	if (n & (1<<2)) goto KEY11807;
	local[2] = (pointer)get_sym_func(fqv[72]);
KEY11807:
	if (n & (1<<3)) goto KEY11814;
	local[3] = NIL;
KEY11814:
	if (n & (1<<4)) goto KEY11819;
	local[4] = makeint(1000000);
KEY11819:
	if (n & (1<<5)) goto KEY11824;
	local[5] = (pointer)get_sym_func(fqv[82]);
KEY11824:
	local[6]= argv[0];
	local[7]= argv[1];
	local[8]= local[2];
	local[9]= local[3];
	local[10]= local[5];
	local[11]= NIL;
	local[12]= NIL;
	local[13]= local[0];
	local[14]= local[1];
	local[15]= local[4];
	ctx->vsp=local+16;
	w=(pointer)DELETE(ctx,10,local+6); /*system::raw-delete*/
	local[0]= w;
BLK11778:
	ctx->vsp=local; return(local[0]);}

/*delete-if*/
static pointer F4376delete_if(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[114], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY11861;
	local[0] = makeint(0);
KEY11861:
	if (n & (1<<1)) goto KEY11866;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY11866:
	if (n & (1<<2)) goto KEY11874;
	local[2] = makeint(1000000);
KEY11874:
	if (n & (1<<3)) goto KEY11879;
	local[3] = (pointer)get_sym_func(fqv[82]);
KEY11879:
	local[4]= NIL;
	local[5]= argv[1];
	local[6]= NIL;
	local[7]= NIL;
	local[8]= local[3];
	local[9]= argv[0];
	local[10]= NIL;
	local[11]= local[0];
	local[12]= local[1];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)DELETE(ctx,10,local+4); /*system::raw-delete*/
	local[0]= w;
BLK11847:
	ctx->vsp=local; return(local[0]);}

/*delete-if-not*/
static pointer F4379delete_if_not(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[115], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY11914;
	local[0] = makeint(0);
KEY11914:
	if (n & (1<<1)) goto KEY11919;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY11919:
	if (n & (1<<2)) goto KEY11927;
	local[2] = makeint(1000000);
KEY11927:
	if (n & (1<<3)) goto KEY11932;
	local[3] = (pointer)get_sym_func(fqv[82]);
KEY11932:
	local[4]= NIL;
	local[5]= argv[1];
	local[6]= NIL;
	local[7]= NIL;
	local[8]= local[3];
	local[9]= NIL;
	local[10]= argv[0];
	local[11]= local[0];
	local[12]= local[1];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)DELETE(ctx,10,local+4); /*system::raw-delete*/
	local[0]= w;
BLK11900:
	ctx->vsp=local; return(local[0]);}

/*substitute*/
static pointer F4382substitute(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[116], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY11971;
	local[0] = makeint(0);
KEY11971:
	if (n & (1<<1)) goto KEY11976;
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[1] = w;
KEY11976:
	if (n & (1<<2)) goto KEY11984;
	local[2] = (pointer)get_sym_func(fqv[72]);
KEY11984:
	if (n & (1<<3)) goto KEY11991;
	local[3] = NIL;
KEY11991:
	if (n & (1<<4)) goto KEY11996;
	local[4] = makeint(1000000);
KEY11996:
	if (n & (1<<5)) goto KEY12001;
	local[5] = (pointer)get_sym_func(fqv[82]);
KEY12001:
	local[6]= argv[0];
	local[7]= argv[1];
	local[8]= argv[2];
	local[9]= local[2];
	local[10]= local[3];
	local[11]= local[5];
	local[12]= NIL;
	local[13]= NIL;
	local[14]= local[0];
	local[15]= local[1];
	local[16]= local[4];
	ctx->vsp=local+17;
	w=(pointer)SUBSTITUTE(ctx,11,local+6); /*system::raw-substitute*/
	local[0]= w;
BLK11953:
	ctx->vsp=local; return(local[0]);}

/*substitute-if*/
static pointer F4385substitute_if(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[117], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY12041;
	local[0] = makeint(0);
KEY12041:
	if (n & (1<<1)) goto KEY12046;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY12046:
	if (n & (1<<2)) goto KEY12054;
	local[2] = makeint(1000000);
KEY12054:
	if (n & (1<<3)) goto KEY12059;
	local[3] = (pointer)get_sym_func(fqv[82]);
KEY12059:
	local[4]= argv[0];
	local[5]= NIL;
	local[6]= argv[2];
	local[7]= NIL;
	local[8]= NIL;
	local[9]= local[3];
	local[10]= argv[1];
	local[11]= NIL;
	local[12]= local[0];
	local[13]= local[1];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)SUBSTITUTE(ctx,11,local+4); /*system::raw-substitute*/
	local[0]= w;
BLK12025:
	ctx->vsp=local; return(local[0]);}

/*substitute-if-not*/
static pointer F4388substitute_if_not(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[118], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY12097;
	local[0] = makeint(0);
KEY12097:
	if (n & (1<<1)) goto KEY12102;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY12102:
	if (n & (1<<2)) goto KEY12110;
	local[2] = makeint(1000000);
KEY12110:
	if (n & (1<<3)) goto KEY12115;
	local[3] = (pointer)get_sym_func(fqv[82]);
KEY12115:
	local[4]= argv[0];
	local[5]= NIL;
	local[6]= argv[2];
	local[7]= NIL;
	local[8]= NIL;
	local[9]= local[3];
	local[10]= NIL;
	local[11]= argv[1];
	local[12]= local[0];
	local[13]= local[1];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)SUBSTITUTE(ctx,11,local+4); /*system::raw-substitute*/
	local[0]= w;
BLK12081:
	ctx->vsp=local; return(local[0]);}

/*nsubstitute*/
static pointer F4391nsubstitute(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[119], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY12155;
	local[0] = makeint(0);
KEY12155:
	if (n & (1<<1)) goto KEY12160;
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[1] = w;
KEY12160:
	if (n & (1<<2)) goto KEY12168;
	local[2] = (pointer)get_sym_func(fqv[72]);
KEY12168:
	if (n & (1<<3)) goto KEY12175;
	local[3] = NIL;
KEY12175:
	if (n & (1<<4)) goto KEY12180;
	local[4] = makeint(1000000);
KEY12180:
	if (n & (1<<5)) goto KEY12185;
	local[5] = (pointer)get_sym_func(fqv[82]);
KEY12185:
	local[6]= argv[0];
	local[7]= argv[1];
	local[8]= argv[2];
	local[9]= local[2];
	local[10]= local[3];
	local[11]= local[5];
	local[12]= NIL;
	local[13]= NIL;
	local[14]= local[0];
	local[15]= local[1];
	local[16]= local[4];
	ctx->vsp=local+17;
	w=(pointer)NSUBSTITUTE(ctx,11,local+6); /*system::raw-nsubstitute*/
	local[0]= w;
BLK12137:
	ctx->vsp=local; return(local[0]);}

/*nsubstitute-if*/
static pointer F4394nsubstitute_if(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[120], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY12225;
	local[0] = makeint(0);
KEY12225:
	if (n & (1<<1)) goto KEY12230;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY12230:
	if (n & (1<<2)) goto KEY12238;
	local[2] = makeint(1000000);
KEY12238:
	if (n & (1<<3)) goto KEY12243;
	local[3] = (pointer)get_sym_func(fqv[82]);
KEY12243:
	local[4]= argv[0];
	local[5]= NIL;
	local[6]= argv[2];
	local[7]= NIL;
	local[8]= NIL;
	local[9]= local[3];
	local[10]= argv[1];
	local[11]= NIL;
	local[12]= local[0];
	local[13]= local[1];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)NSUBSTITUTE(ctx,11,local+4); /*system::raw-nsubstitute*/
	local[0]= w;
BLK12209:
	ctx->vsp=local; return(local[0]);}

/*nsubstitute-if-not*/
static pointer F4397nsubstitute_if_not(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[121], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY12281;
	local[0] = makeint(0);
KEY12281:
	if (n & (1<<1)) goto KEY12286;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY12286:
	if (n & (1<<2)) goto KEY12294;
	local[2] = makeint(1000000);
KEY12294:
	if (n & (1<<3)) goto KEY12299;
	local[3] = (pointer)get_sym_func(fqv[82]);
KEY12299:
	local[4]= argv[0];
	local[5]= NIL;
	local[6]= argv[2];
	local[7]= NIL;
	local[8]= NIL;
	local[9]= local[3];
	local[10]= NIL;
	local[11]= argv[1];
	local[12]= local[0];
	local[13]= local[1];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)NSUBSTITUTE(ctx,11,local+4); /*system::raw-nsubstitute*/
	local[0]= w;
BLK12265:
	ctx->vsp=local; return(local[0]);}

/*unique*/
static pointer F4400unique(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	if (!!iscons(w)) goto CON12333;
	local[0]= argv[0];
	goto CON12331;
CON12333:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	if (memq(local[0],w)==NIL) goto CON12343;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	ctx->vsp=local+1;
	w=(pointer)F4400unique(ctx,1,local+0); /*unique*/
	local[0]= w;
	goto CON12331;
CON12343:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(pointer)F4400unique(ctx,1,local+1); /*unique*/
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	goto CON12331;
CON12367:
	local[0]= NIL;
CON12331:
	w = local[0];
	local[0]= w;
BLK12321:
	ctx->vsp=local; return(local[0]);}

/*remove-duplicates*/
static pointer F4403remove_duplicates(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[122], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY12400;
	local[0] = (pointer)get_sym_func(fqv[72]);
KEY12400:
	if (n & (1<<1)) goto KEY12407;
	local[1] = NIL;
KEY12407:
	if (n & (1<<2)) goto KEY12412;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY12412:
	if (n & (1<<3)) goto KEY12419;
	local[3] = makeint(0);
KEY12419:
	if (n & (1<<4)) goto KEY12424;
	local[4] = makeint(1000000);
KEY12424:
	local[5]= argv[0];
	local[6]= local[0];
	local[7]= local[1];
	local[8]= local[2];
	local[9]= local[3];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)REMOVE_DUPLICATES(ctx,6,local+5); /*system::raw-remove-duplicates*/
	local[0]= w;
BLK12387:
	ctx->vsp=local; return(local[0]);}

/*extream*/
static pointer F4406extream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT12446;}
	local[0]= (pointer)get_sym_func(fqv[82]);
ENT12446:
ENT12445:
	if (n>3) maerror();
	if (argv[0]!=NIL) goto IF12464;
	local[1]= NIL;
	goto IF12465;
IF12464:
	local[1]= argv[0];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)FUNCALL(ctx,2,local+2); /*funcall*/
	local[2]= w;
	local[3]= NIL;
	w = argv[0];
	if (!iscons(w)) goto IF12489;
	local[4]= NIL;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
WHL12516:
	if (local[5]==NIL) goto WHX12517;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= argv[1];
	local[7]= local[0];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)FUNCALL(ctx,2,local+7); /*funcall*/
	local[7]= w;
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)FUNCALL(ctx,3,local+6); /*funcall*/
	if (w==NIL) goto IF12566;
	local[1] = local[4];
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)FUNCALL(ctx,2,local+6); /*funcall*/
	local[2] = w;
	local[6]= local[2];
	goto IF12567;
IF12566:
	local[6]= NIL;
IF12567:
	goto WHL12516;
WHX12517:
	local[6]= NIL;
BLK12518:
	w = NIL;
	local[4]= w;
	goto IF12490;
IF12489:
	local[4]= makeint(0);
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
WHL12622:
	local[6]= local[4];
	w = local[5];
	if ((eusinteger_t)local[6] >= (eusinteger_t)w) goto WHX12623;
	local[6]= argv[1];
	local[7]= local[0];
	local[8]= argv[0];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[3] = w;
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)FUNCALL(ctx,2,local+7); /*funcall*/
	local[7]= w;
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)FUNCALL(ctx,3,local+6); /*funcall*/
	if (w==NIL) goto IF12632;
	local[1] = local[3];
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)FUNCALL(ctx,2,local+6); /*funcall*/
	local[2] = w;
	local[6]= local[2];
	goto IF12633;
IF12632:
	local[6]= NIL;
IF12633:
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[4] = w;
	goto WHL12622;
WHX12623:
	local[6]= NIL;
BLK12624:
	w = NIL;
	local[4]= w;
IF12490:
	w = local[1];
	local[1]= w;
IF12465:
	w = local[1];
	local[0]= w;
BLK12443:
	ctx->vsp=local; return(local[0]);}

/*send-super-lexpr*/
static pointer F12687(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST12690:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[123];
	local[2]= fqv[124];
	local[3]= fqv[125];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[126];
	local[4]= fqv[127];
	w = fqv[128];
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= argv[0];
	w = local[0];
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
BLK12688:
	ctx->vsp=local; return(local[0]);}

/*send-super**/
static pointer F12747(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST12750:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= fqv[123];
	local[2]= fqv[124];
	local[3]= fqv[125];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[126];
	local[4]= fqv[127];
	w = fqv[128];
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	w = local[0];
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK12748:
	ctx->vsp=local; return(local[0]);}

/*send-lexpr*/
static pointer F12801(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST12804:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= fqv[123];
	local[2]= fqv[124];
	local[3]= fqv[32];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= argv[0];
	local[4]= argv[1];
	w = local[0];
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK12802:
	ctx->vsp=local; return(local[0]);}

/*send**/
static pointer F12845(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST12848:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= fqv[123];
	local[2]= fqv[124];
	local[3]= fqv[32];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	w = local[0];
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK12846:
	ctx->vsp=local; return(local[0]);}

/*send-super*/
static pointer F12877(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST12880:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[125];
	local[2]= fqv[126];
	local[3]= fqv[127];
	w = fqv[128];
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= argv[0];
	local[5]= local[0];
	local[6]= NIL;
	ctx->vsp=local+7;
	w=(pointer)APPEND(ctx,2,local+5); /*append*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK12878:
	ctx->vsp=local; return(local[0]);}

/*send-all*/
static pointer F4415send_all(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST12929:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO12941,env,argv,local);
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[0]= w;
BLK12927:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO12941(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[32];
	local[1]= argv[0];
	local[2]= env->c.clo.env2[0];
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,3,local+0); /*apply*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*resend*/
static pointer F4418resend(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[32];
	local[1]= argv[0];
	w = argv[1];
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	ctx->vsp=local+1;
	w=(pointer)EVAL(ctx,1,local+0); /*eval*/
	local[0]= w;
BLK12964:
	ctx->vsp=local; return(local[0]);}

/*instance*/
static pointer F12990(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST12993:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	if (local[0]==NIL) goto IF13004;
	local[1]= fqv[129];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= fqv[5];
	local[3]= local[1];
	local[4]= fqv[130];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[3]= w;
	local[4]= fqv[32];
	local[5]= local[1];
	local[6]= local[0];
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)APPEND(ctx,2,local+6); /*append*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[1]= w;
	goto IF13005;
IF13004:
	local[1]= fqv[130];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
IF13005:
	w = local[1];
	local[0]= w;
BLK12991:
	ctx->vsp=local; return(local[0]);}

/*instance**/
static pointer F13071(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST13074:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	if (local[0]==NIL) goto IF13085;
	local[1]= fqv[131];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= fqv[5];
	local[3]= local[1];
	local[4]= fqv[130];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[3]= w;
	local[4]= fqv[132];
	local[5]= local[1];
	local[6]= local[0];
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)APPEND(ctx,2,local+6); /*append*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[1]= w;
	goto IF13086;
IF13085:
	local[1]= fqv[130];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
IF13086:
	w = local[1];
	local[0]= w;
BLK13072:
	ctx->vsp=local; return(local[0]);}

/*make-instance*/
static pointer F4423make_instance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST13154:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
WHL13178:
	if (local[0]==NIL) goto WHX13179;
	local[2]= local[1];
	local[3]= argv[0];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)F4183string(ctx,1,local+4); /*string*/
	local[4]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[5];
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SETSLOT(ctx,4,local+2); /*setslot*/
	goto WHL13178;
WHX13179:
	local[2]= NIL;
BLK13180:
	w = local[1];
	local[0]= w;
BLK13152:
	ctx->vsp=local; return(local[0]);}

/*defclassmethod*/
static pointer F13268(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST13271:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[133];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SYMVALUE(ctx,1,local+2); /*symbol-value*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)GETCLASS(ctx,1,local+2); /*class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,1,local+2,&ftab[1],fqv[134]); /*metaclass-name*/
	local[2]= w;
	w = local[0];
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK13269:
	ctx->vsp=local; return(local[0]);}

/*delete-method*/
static pointer F4427delete_method(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0]->c.obj.iv[7];
	local[2]= fqv[25];
	local[3]= (pointer)get_sym_func(fqv[16]);
	ctx->vsp=local+4;
	w=(pointer)F4373delete(ctx,4,local+0); /*delete*/
	local[0]= w;
	local[1]= w;
	w = argv[0];
	w->c.obj.iv[7] = local[1];
	local[0]= T;
	ctx->vsp=local+1;
	w=(pointer)METHCACHE(ctx,1,local+0); /*system::method-cache*/
	local[0]= w;
BLK13302:
	ctx->vsp=local; return(local[0]);}

/*make-class*/
static pointer F4430make_class(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[135], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY13355;
	local[0] = loadglobal(fqv[136]);
KEY13355:
	if (n & (1<<1)) goto KEY13362;
	local[1] = loadglobal(fqv[136]);
KEY13362:
	if (n & (1<<2)) goto KEY13368;
	local[2] = NIL;
KEY13368:
	if (n & (1<<3)) goto KEY13373;
	local[3] = NIL;
KEY13373:
	if (n & (1<<4)) goto KEY13378;
	local[4] = NIL;
KEY13378:
	if (n & (1<<5)) goto KEY13383;
	local[5] = NIL;
KEY13383:
	if (n & (1<<6)) goto KEY13388;
	local[6] = NIL;
KEY13388:
	if (n & (1<<7)) goto KEY13393;
	local[7] = NIL;
KEY13393:
	if (n & (1<<8)) goto KEY13398;
	local[8] = makeint(-1);
KEY13398:
	if (n & (1<<9)) goto KEY13403;
	local[9] = NIL;
KEY13403:
	if (n & (1<<10)) goto KEY13408;
	local[10] = NIL;
KEY13408:
	w = local[0];
	if (!issymbol(w)) goto IF13417;
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)SYMVALUE(ctx,1,local+11); /*symbol-value*/
	local[0] = w;
	local[11]= local[0];
	goto IF13418;
IF13417:
	local[11]= NIL;
IF13418:
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)BOUNDP(ctx,1,local+11); /*boundp*/
	if (w==NIL) goto IF13439;
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)SYMVALUE(ctx,1,local+11); /*symbol-value*/
	local[11]= w;
	goto IF13440;
IF13439:
	local[11]= NIL;
IF13440:
	local[12]= NIL;
	local[13]= NIL;
	local[14]= NIL;
	local[15]= NIL;
	local[16]= makeint(0);
	local[17]= NIL;
	local[18]= NIL;
	local[19]= local[11];
	ctx->vsp=local+20;
	w=(pointer)CLASSP(ctx,1,local+19); /*classp*/
	if (w!=NIL) goto CON13476;
	local[19]= local[6];
	if (local[19]!=NIL) goto CON13484;
CON13486:
	local[19]= local[6];
	ctx->vsp=local+20;
	w=(pointer)CLASSP(ctx,1,local+19); /*classp*/
	local[19]= w;
	if (w!=NIL) goto CON13484;
CON13490:
	if (local[0]==NIL) goto CON13496;
	local[19]= local[0];
	ctx->vsp=local+20;
	w=(pointer)GETCLASS(ctx,1,local+19); /*class*/
	local[6] = w;
	local[19]= local[6];
	goto CON13484;
CON13496:
	local[19]= fqv[137];
	ctx->vsp=local+20;
	w=(pointer)SYMVALUE(ctx,1,local+19); /*symbol-value*/
	local[6] = w;
	local[19]= local[6];
	goto CON13484;
CON13509:
	local[19]= NIL;
CON13484:
	local[19]= local[6];
	ctx->vsp=local+20;
	w=(pointer)INSTANTIATE(ctx,1,local+19); /*instantiate*/
	local[11] = w;
	local[19]= local[11];
	goto CON13474;
CON13476:
	local[19]= local[11];
	ctx->vsp=local+20;
	w=(pointer)GETCLASS(ctx,1,local+19); /*class*/
	local[6] = w;
	local[19]= local[6];
	goto CON13474;
CON13530:
	local[19]= NIL;
CON13474:
	local[19]= *(ovafptr(local[0],fqv[138]));
	local[20]= loadglobal(fqv[19]);
	ctx->vsp=local+21;
	w=(pointer)COERCE(ctx,2,local+19); /*coerce*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)NREVERSE(ctx,1,local+19); /*nreverse*/
	local[12] = w;
	local[19]= *(ovafptr(local[0],fqv[139]));
	local[20]= loadglobal(fqv[19]);
	ctx->vsp=local+21;
	w=(pointer)COERCE(ctx,2,local+19); /*coerce*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)NREVERSE(ctx,1,local+19); /*nreverse*/
	local[13] = w;
	local[19]= *(ovafptr(local[0],fqv[140]));
	local[20]= loadglobal(fqv[19]);
	ctx->vsp=local+21;
	w=(pointer)COERCE(ctx,2,local+19); /*coerce*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)NREVERSE(ctx,1,local+19); /*nreverse*/
	local[14] = w;
	local[19]= NIL;
	local[20]= local[9];
WHL13591:
	if (local[20]==NIL) goto WHX13592;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20] = (w)->c.cons.cdr;
	w = local[21];
	local[19] = w;
	w = local[19];
	if (!iscons(w)) goto CON13642;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	local[22]= local[12];
	ctx->vsp=local+23;
	w=(pointer)F4292member(ctx,2,local+21); /*member*/
	if (w==NIL) goto IF13648;
	local[21]= fqv[141];
	ctx->vsp=local+22;
	w=(pointer)SIGERROR(ctx,1,local+21); /*error*/
	local[21]= w;
	goto IF13649;
IF13648:
	local[21]= NIL;
IF13649:
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w = local[12];
	ctx->vsp=local+22;
	local[12] = cons(ctx,local[21],w);
	local[21]= fqv[142];
	local[22]= local[19];
	ctx->vsp=local+23;
	w=(pointer)F4316position(ctx,2,local+21); /*position*/
	local[18] = w;
	if (local[18]==NIL) goto IF13695;
	local[21]= local[19];
	local[22]= local[18];
	ctx->vsp=local+23;
	w=(pointer)ADD1(ctx,1,local+22); /*1+*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)ELT(ctx,2,local+21); /*elt*/
	local[21]= w;
	goto IF13696;
IF13695:
	local[21]= T;
IF13696:
	w = local[13];
	ctx->vsp=local+22;
	local[13] = cons(ctx,local[21],w);
	local[21]= fqv[143];
	local[22]= local[19];
	ctx->vsp=local+23;
	w=(pointer)F4316position(ctx,2,local+21); /*position*/
	local[18] = w;
	if (local[18]==NIL) goto IF13729;
	local[21]= local[19];
	local[22]= local[18];
	ctx->vsp=local+23;
	w=(pointer)ADD1(ctx,1,local+22); /*1+*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)ELT(ctx,2,local+21); /*elt*/
	local[21]= w;
	goto IF13730;
IF13729:
	local[21]= NIL;
IF13730:
	w = local[14];
	ctx->vsp=local+22;
	local[14] = cons(ctx,local[21],w);
	local[21]= local[14];
	goto CON13640;
CON13642:
	w = local[19];
	if (!issymbol(w)) goto CON13746;
	local[21]= local[19];
	local[22]= local[12];
	ctx->vsp=local+23;
	w=(pointer)F4292member(ctx,2,local+21); /*member*/
	if (w==NIL) goto IF13752;
	local[21]= fqv[144];
	ctx->vsp=local+22;
	w=(pointer)SIGERROR(ctx,1,local+21); /*error*/
	local[21]= w;
	goto IF13753;
IF13752:
	local[21]= NIL;
IF13753:
	local[21]= local[19];
	w = local[12];
	ctx->vsp=local+22;
	local[12] = cons(ctx,local[21],w);
	local[21]= T;
	w = local[13];
	ctx->vsp=local+22;
	local[13] = cons(ctx,local[21],w);
	local[21]= NIL;
	w = local[14];
	ctx->vsp=local+22;
	local[14] = cons(ctx,local[21],w);
	local[21]= local[14];
	goto CON13640;
CON13746:
	local[21]= fqv[145];
	ctx->vsp=local+22;
	w=(pointer)SIGERROR(ctx,1,local+21); /*error*/
	local[21]= w;
	goto CON13640;
CON13796:
	local[21]= NIL;
CON13640:
	goto WHL13591;
WHX13592:
	local[21]= NIL;
BLK13593:
	w = NIL;
	local[19]= local[12];
	ctx->vsp=local+20;
	w=(pointer)NREVERSE(ctx,1,local+19); /*nreverse*/
	local[19]= w;
	local[20]= loadglobal(fqv[146]);
	ctx->vsp=local+21;
	w=(pointer)COERCE(ctx,2,local+19); /*coerce*/
	local[12] = w;
	local[19]= local[13];
	ctx->vsp=local+20;
	w=(pointer)NREVERSE(ctx,1,local+19); /*nreverse*/
	local[19]= w;
	local[20]= loadglobal(fqv[146]);
	ctx->vsp=local+21;
	w=(pointer)COERCE(ctx,2,local+19); /*coerce*/
	local[13] = w;
	local[19]= local[14];
	ctx->vsp=local+20;
	w=(pointer)NREVERSE(ctx,1,local+19); /*nreverse*/
	local[19]= w;
	local[20]= loadglobal(fqv[146]);
	ctx->vsp=local+21;
	w=(pointer)COERCE(ctx,2,local+19); /*coerce*/
	local[14] = w;
	local[19]= local[7];
	local[20]= fqv[147];
	ctx->vsp=local+21;
	w=(pointer)ASSQ(ctx,2,local+19); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15] = (w)->c.cons.cdr;
	if (local[15]!=NIL) goto IF13850;
	local[19]= local[6];
	local[20]= loadglobal(fqv[148]);
	ctx->vsp=local+21;
	w=(pointer)SUBCLASSP(ctx,2,local+19); /*subclassp*/
	if (w==NIL) goto IF13858;
	local[19]= local[0]->c.obj.iv[8];
	goto IF13859;
IF13858:
	local[19]= makeint(0);
IF13859:
	local[15] = local[19];
	local[19]= local[15];
	goto IF13851;
IF13850:
	local[19]= NIL;
IF13851:
	local[19]= argv[0];
	*(ovafptr(local[11],fqv[149])) = local[19];
	local[19]= local[12];
	*(ovafptr(local[11],fqv[138])) = local[19];
	local[19]= local[13];
	*(ovafptr(local[11],fqv[139])) = local[19];
	local[19]= local[14];
	*(ovafptr(local[11],fqv[140])) = local[19];
	local[19]= local[0];
	local[20]= local[19];
	*(ovafptr(local[11],fqv[128])) = local[20];
	local[19]= local[6];
	local[20]= loadglobal(fqv[148]);
	ctx->vsp=local+21;
	w=(pointer)SUBCLASSP(ctx,2,local+19); /*subclassp*/
	if (w==NIL) goto IF13894;
	local[19]= local[15];
	*(ovafptr(local[11],fqv[150])) = local[19];
	local[19]= local[8];
	local[20]= local[19];
	*(ovafptr(local[11],fqv[151])) = local[20];
	goto IF13895;
IF13894:
	local[19]= NIL;
IF13895:
	if (*(ovafptr(local[11],fqv[152]))!=NIL) goto IF13912;
	local[19]= local[11];
	ctx->vsp=local+20;
	w=(*ftab[2])(ctx,1,local+19,&ftab[2],fqv[153]); /*enter-class*/
	local[19]= w;
	goto IF13913;
IF13912:
	local[19]= NIL;
IF13913:
	local[19]= local[11];
	local[20]= local[10];
	local[21]= fqv[154];
	ctx->vsp=local+22;
	w=(pointer)PUTPROP(ctx,3,local+19); /*putprop*/
	local[19]= local[12];
	local[20]= loadglobal(fqv[19]);
	ctx->vsp=local+21;
	w=(pointer)COERCE(ctx,2,local+19); /*coerce*/
	local[12] = w;
	local[19]= NIL;
	local[20]= local[12];
WHL13958:
	if (local[20]==NIL) goto WHX13959;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20] = (w)->c.cons.cdr;
	w = local[21];
	local[19] = w;
	local[21]= loadglobal(fqv[155]);
	local[22]= argv[0];
	ctx->vsp=local+23;
	w=(pointer)F4183string(ctx,1,local+22); /*string*/
	local[22]= w;
	local[23]= fqv[156];
	local[24]= local[19];
	ctx->vsp=local+25;
	w=(pointer)F4183string(ctx,1,local+24); /*string*/
	local[24]= w;
	ctx->vsp=local+25;
	w=(pointer)CONCATENATE(ctx,4,local+21); /*concatenate*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)INTERN(ctx,1,local+21); /*intern*/
	local[17] = w;
	local[21]= local[17];
	local[22]= fqv[157];
	local[23]= fqv[158];
	ctx->vsp=local+24;
	w=(pointer)LIST(ctx,1,local+23); /*list*/
	local[23]= w;
	local[24]= fqv[66];
	local[25]= fqv[33];
	local[26]= fqv[159];
	ctx->vsp=local+27;
	w=(pointer)LIST(ctx,1,local+26); /*list*/
	ctx->vsp=local+26;
	local[25]= cons(ctx,local[25],w);
	local[26]= fqv[158];
	local[27]= fqv[33];
	local[28]= argv[0];
	ctx->vsp=local+29;
	w=(pointer)LIST(ctx,1,local+28); /*list*/
	ctx->vsp=local+28;
	local[27]= cons(ctx,local[27],w);
	local[28]= local[16];
	ctx->vsp=local+29;
	w=(pointer)LIST(ctx,1,local+28); /*list*/
	ctx->vsp=local+28;
	w = cons(ctx,local[27],w);
	ctx->vsp=local+27;
	w = cons(ctx,local[26],w);
	ctx->vsp=local+26;
	w = cons(ctx,local[25],w);
	ctx->vsp=local+25;
	local[24]= cons(ctx,local[24],w);
	ctx->vsp=local+25;
	w=(pointer)LIST(ctx,1,local+24); /*list*/
	ctx->vsp=local+24;
	w = cons(ctx,local[23],w);
	ctx->vsp=local+23;
	local[22]= cons(ctx,local[22],w);
	ctx->vsp=local+23;
	w=(pointer)SETFUNC(ctx,2,local+21); /*setfunc*/
	local[21]= local[16];
	ctx->vsp=local+22;
	w=(pointer)ADD1(ctx,1,local+21); /*1+*/
	local[16] = w;
	goto WHL13958;
WHX13959:
	local[21]= NIL;
BLK13960:
	w = NIL;
	w = local[11];
	local[0]= w;
BLK13336:
	ctx->vsp=local; return(local[0]);}

/*defstruct*/
static pointer F14094(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST14097:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[6];
	local[2]= fqv[32];
	local[3]= fqv[33];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[38];
	local[5]= fqv[160];
	local[6]= fqv[33];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[161];
	local[8]= fqv[33];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
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
	local[3]= fqv[33];
	local[4]= argv[0];
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
BLK14095:
	ctx->vsp=local; return(local[0]);}

/*defclass*/
static pointer F14176(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[162], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY14192;
	local[0] = NIL;
KEY14192:
	if (n & (1<<1)) goto KEY14197;
	local[1] = fqv[136];
KEY14197:
	if (n & (1<<2)) goto KEY14204;
	local[2] = makeint(-1);
KEY14204:
	if (n & (1<<3)) goto KEY14209;
	local[3] = NIL;
KEY14209:
	if (n & (1<<4)) goto KEY14214;
	local[4] = NIL;
KEY14214:
	if (n & (1<<5)) goto KEY14219;
	local[5] = NIL;
KEY14219:
	if (n & (1<<6)) goto KEY14224;
	local[6] = local[5];
KEY14224:
	local[7]= fqv[6];
	local[8]= fqv[32];
	local[9]= fqv[33];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[38];
	local[11]= fqv[160];
	local[12]= fqv[33];
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[163];
	local[14]= local[1];
	local[15]= fqv[161];
	local[16]= fqv[33];
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,1,local+17); /*list*/
	ctx->vsp=local+17;
	local[16]= cons(ctx,local[16],w);
	local[17]= fqv[164];
	local[18]= local[3];
	local[19]= fqv[106];
	local[20]= local[4];
	local[21]= fqv[165];
	local[22]= local[2];
	local[23]= fqv[166];
	local[24]= local[6];
	ctx->vsp=local+25;
	w=(pointer)LIST(ctx,1,local+24); /*list*/
	ctx->vsp=local+24;
	w = cons(ctx,local[23],w);
	ctx->vsp=local+23;
	w = cons(ctx,local[22],w);
	ctx->vsp=local+22;
	w = cons(ctx,local[21],w);
	ctx->vsp=local+21;
	w = cons(ctx,local[20],w);
	ctx->vsp=local+20;
	w = cons(ctx,local[19],w);
	ctx->vsp=local+19;
	w = cons(ctx,local[18],w);
	ctx->vsp=local+18;
	w = cons(ctx,local[17],w);
	ctx->vsp=local+17;
	w = cons(ctx,local[16],w);
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
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
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[33];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	local[0]= w;
BLK14177:
	ctx->vsp=local; return(local[0]);}

/*readtablep*/
static pointer F4437readtablep(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[167]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK14349:
	ctx->vsp=local; return(local[0]);}

/*copy-readtable*/
static pointer F4440copy_readtable(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT14370;}
	local[0]= loadglobal(fqv[168]);
ENT14370:
	if (n>=2) { local[1]=(argv[1]); goto ENT14369;}
	local[1]= NIL;
ENT14369:
ENT14368:
	if (n>2) maerror();
	if (local[0]!=NIL) goto IF14389;
	local[0] = loadglobal(fqv[169]);
	local[2]= local[0];
	goto IF14390;
IF14389:
	local[2]= NIL;
IF14390:
	if (local[1]!=NIL) goto IF14407;
	local[2]= loadglobal(fqv[167]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[1] = w;
	local[2]= loadglobal(fqv[155]);
	local[3]= makeint(256);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,2,local+2); /*instantiate*/
	local[2]= w;
	local[3]= w;
	w = local[1];
	w->c.obj.iv[1] = local[3];
	local[2]= loadglobal(fqv[146]);
	local[3]= makeint(256);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,2,local+2); /*instantiate*/
	local[2]= w;
	local[3]= w;
	w = local[1];
	w->c.obj.iv[2] = local[3];
	local[2]= loadglobal(fqv[146]);
	local[3]= makeint(256);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,2,local+2); /*instantiate*/
	local[2]= w;
	local[3]= w;
	w = local[1];
	w->c.obj.iv[3] = local[3];
	goto IF14408;
IF14407:
	local[2]= NIL;
IF14408:
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F4437readtablep(ctx,1,local+2); /*readtablep*/
	if (w==NIL) goto OR14455;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)F4437readtablep(ctx,1,local+2); /*readtablep*/
	if (w==NIL) goto OR14455;
	goto IF14453;
OR14455:
	local[2]= fqv[170];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,1,local+2); /*error*/
	local[2]= w;
	goto IF14454;
IF14453:
	local[2]= NIL;
IF14454:
	local[2]= local[1]->c.obj.iv[1];
	local[3]= local[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)F4361replace(ctx,2,local+2); /*replace*/
	local[2]= local[1]->c.obj.iv[2];
	local[3]= local[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)F4361replace(ctx,2,local+2); /*replace*/
	local[2]= local[1]->c.obj.iv[3];
	local[3]= local[0]->c.obj.iv[3];
	ctx->vsp=local+4;
	w=(pointer)F4361replace(ctx,2,local+2); /*replace*/
	local[2]= local[0]->c.obj.iv[4];
	local[3]= local[2];
	w = local[1];
	w->c.obj.iv[4] = local[3];
	w = local[1];
	local[0]= w;
BLK14366:
	ctx->vsp=local; return(local[0]);}

/*set-syntax-from-char*/
static pointer F4443set_syntax_from_char(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT14529;}
	local[0]= loadglobal(fqv[168]);
ENT14529:
	if (n>=4) { local[1]=(argv[3]); goto ENT14528;}
	local[1]= loadglobal(fqv[169]);
ENT14528:
ENT14527:
	if (n>4) maerror();
	local[2]= NIL;
	local[3]= local[1]->c.obj.iv[1];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[2] = w;
	local[3]= local[0]->c.obj.iv[1];
	local[4]= argv[0];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,3,local+3); /*aset*/
	local[3]= local[2];
	if (makeint(7)==local[3]) goto OR14587;
	local[3]= local[2];
	if (makeint(8)==local[3]) goto OR14587;
	goto IF14585;
OR14587:
	local[3]= local[0]->c.obj.iv[2];
	local[4]= argv[0];
	local[5]= local[1]->c.obj.iv[2];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,3,local+3); /*aset*/
	local[3]= w;
	goto IF14586;
IF14585:
	local[3]= NIL;
IF14586:
	w = local[2];
	local[0]= w;
BLK14525:
	ctx->vsp=local; return(local[0]);}

/*keywordp*/
static pointer F4448keywordp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	local[0]= (issymbol(w)?T:NIL);
	if (local[0]==NIL) goto AND14636;
	local[0]= argv[0]->c.obj.iv[5];
	local[0]= ((loadglobal(fqv[171]))==(local[0])?T:NIL);
AND14636:
	w = local[0];
	local[0]= w;
BLK14620:
	ctx->vsp=local; return(local[0]);}

/*constantp*/
static pointer F4451constantp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!issymbol(w)) goto IF14670;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F4448keywordp(ctx,1,local+0); /*keywordp*/
	if (w!=NIL) goto OR14678;
	local[0]= argv[0]->c.obj.iv[2];
	if (makeint(0)==local[0]) goto OR14678;
	goto IF14676;
OR14678:
	local[0]= T;
	goto IF14677;
IF14676:
	local[0]= NIL;
IF14677:
	goto IF14671;
IF14670:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto IF14690;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[33]!=local[0]) goto IF14698;
	local[0]= T;
	goto IF14699;
IF14698:
	local[0]= NIL;
IF14699:
	goto IF14691;
IF14690:
	w = argv[0];
	if (!!iscons(w)) goto IF14710;
	local[0]= T;
	goto IF14711;
IF14710:
	local[0]= NIL;
IF14711:
IF14691:
IF14671:
	w = local[0];
	local[0]= w;
BLK14654:
	ctx->vsp=local; return(local[0]);}

/*functionp*/
static pointer F4454functionp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!isnum(w)) goto CON14730;
	local[0]= NIL;
	goto CON14728;
CON14730:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON14735;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w = fqv[172];
	if (memq(local[0],w)!=NIL) goto OR14745;
	goto IF14743;
OR14745:
	local[0]= T;
	goto IF14744;
IF14743:
	local[0]= NIL;
IF14744:
	goto CON14728;
CON14735:
	local[0]= argv[0];
	local[1]= loadglobal(fqv[173]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON14759;
	local[0]= argv[0]->c.obj.iv[2];
	local[0]= ((makeint(0))==(local[0])?T:NIL);
	goto CON14728;
CON14759:
	w = argv[0];
	if (!issymbol(w)) goto CON14776;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FBOUNDP(ctx,1,local+0); /*fboundp*/
	if (w==NIL) goto CON14776;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)SYMFUNC(ctx,1,local+0); /*symbol-function*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)F4454functionp(ctx,1,local+0); /*functionp*/
	local[0]= w;
	goto CON14728;
CON14776:
	local[0]= NIL;
	goto CON14728;
CON14792:
	local[0]= NIL;
CON14728:
	w = local[0];
	local[0]= w;
BLK14718:
	ctx->vsp=local; return(local[0]);}

/*vector-class-p*/
static pointer F4457vector_class_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[148]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK14798:
	ctx->vsp=local; return(local[0]);}

/*compiled-function-p*/
static pointer F4460compiled_function_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[173]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK14814:
	ctx->vsp=local; return(local[0]);}

/*input-stream-p*/
static pointer F4463input_stream_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[174]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
	if (w==NIL) goto AND14850;
	local[0]= argv[0]->c.obj.iv[1];
	local[0]= ((fqv[175])==(local[0])?T:NIL);
AND14850:
	if (local[0]!=NIL) goto OR14846;
	local[0]= argv[0];
	local[1]= loadglobal(fqv[176]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
OR14846:
	w = local[0];
	local[0]= w;
BLK14830:
	ctx->vsp=local; return(local[0]);}

/*output-stream-p*/
static pointer F4466output_stream_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[174]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
	if (w==NIL) goto AND14895;
	local[0]= argv[0]->c.obj.iv[1];
	local[0]= ((fqv[177])==(local[0])?T:NIL);
AND14895:
	if (local[0]!=NIL) goto OR14891;
	local[0]= argv[0];
	local[1]= loadglobal(fqv[176]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
OR14891:
	w = local[0];
	local[0]= w;
BLK14875:
	ctx->vsp=local; return(local[0]);}

/*io-stream-p*/
static pointer F4469io_stream_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[176]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK14918:
	ctx->vsp=local; return(local[0]);}

/*special-form-p*/
static pointer F4472special_form_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	local[0]= (issymbol(w)?T:NIL);
	if (local[0]==NIL) goto AND14944;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FBOUNDP(ctx,1,local+0); /*fboundp*/
	local[0]= w;
	if (w==NIL) goto AND14944;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)SYMFUNC(ctx,1,local+0); /*symbol-function*/
	argv[0] = w;
	local[0]= argv[0];
	if (local[0]==NIL) goto AND14944;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F4460compiled_function_p(ctx,1,local+0); /*compiled-function-p*/
	local[0]= w;
	if (w==NIL) goto AND14944;
	local[0]= *(ovafptr(argv[0],fqv[178]));
	local[0]= ((makeint(2))==(local[0])?T:NIL);
AND14944:
	w = local[0];
	local[0]= w;
BLK14934:
	ctx->vsp=local; return(local[0]);}

/*macro-function*/
static pointer F4475macro_function(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	local[0]= (issymbol(w)?T:NIL);
	if (local[0]==NIL) goto AND14990;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FBOUNDP(ctx,1,local+0); /*fboundp*/
	local[0]= w;
	if (w==NIL) goto AND14990;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)SYMFUNC(ctx,1,local+0); /*symbol-function*/
	argv[0] = w;
	local[0]= argv[0];
	if (local[0]==NIL) goto AND14990;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F4460compiled_function_p(ctx,1,local+0); /*compiled-function-p*/
	if (w==NIL) goto IF15014;
	local[0]= *(ovafptr(argv[0],fqv[178]));
	if (makeint(1)!=local[0]) goto IF15014;
	local[0]= argv[0];
	goto IF15015;
IF15014:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto IF15028;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[157]!=local[0]) goto IF15028;
	local[0]= argv[0];
	goto IF15029;
IF15028:
	local[0]= NIL;
IF15029:
IF15015:
AND14990:
	w = local[0];
	local[0]= w;
BLK14980:
	ctx->vsp=local; return(local[0]);}

/*zerop*/
static pointer F4478zerop(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	local[0]= w;
BLK15049:
	ctx->vsp=local; return(local[0]);}

/*plusp*/
static pointer F4481plusp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	local[0]= w;
BLK15064:
	ctx->vsp=local; return(local[0]);}

/*minusp*/
static pointer F4484minusp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	local[0]= w;
BLK15079:
	ctx->vsp=local; return(local[0]);}

/*oddp*/
static pointer F4487oddp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint(0);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LOGBITP(ctx,2,local+0); /*logbitp*/
	local[0]= w;
BLK15094:
	ctx->vsp=local; return(local[0]);}

/*evenp*/
static pointer F4490evenp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint(0);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LOGBITP(ctx,2,local+0); /*logbitp*/
	w = ((w)==NIL?T:NIL);
	local[0]= w;
BLK15109:
	ctx->vsp=local; return(local[0]);}

/*logandc1*/
static pointer F4493logandc1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LOGNOT(ctx,1,local+0); /*lognot*/
	local[0]= w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)LOGAND(ctx,2,local+0); /*logand*/
	local[0]= w;
BLK15128:
	ctx->vsp=local; return(local[0]);}

/*logandc2*/
static pointer F4496logandc2(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)LOGNOT(ctx,1,local+1); /*lognot*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LOGAND(ctx,2,local+0); /*logand*/
	local[0]= w;
BLK15150:
	ctx->vsp=local; return(local[0]);}

/*ecase*/
static pointer F15172(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST15175:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= fqv[179];
	w = local[0];
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK15173:
	ctx->vsp=local; return(local[0]);}

/*every*/
static pointer F4500every(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST15195:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	if (local[0]!=NIL) goto CON15210;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)LISTP(ctx,1,local+1); /*listp*/
	if (w==NIL) goto CON15210;
WHL15222:
	if (argv[1]==NIL) goto WHX15223;
	local[1]= argv[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	w = local[2];
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FUNCALL(ctx,2,local+1); /*funcall*/
	if (w!=NIL) goto IF15231;
	w = NIL;
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK15193;
	goto IF15232;
IF15231:
	local[1]= NIL;
IF15232:
	goto WHL15222;
WHX15223:
	local[1]= NIL;
BLK15224:
	goto CON15208;
CON15210:
	local[1]= argv[1];
	w = local[0];
	ctx->vsp=local+2;
	argv[1] = cons(ctx,local[1],w);
	local[1]= makeint(0);
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
WHL15323:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX15324;
	local[3]= argv[0];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO15340,env,argv,local);
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,2,local+3); /*apply*/
	if (w!=NIL) goto IF15333;
	w = NIL;
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK15193;
	goto IF15334;
IF15333:
	local[3]= NIL;
IF15334:
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL15323;
WHX15324:
	local[3]= NIL;
BLK15325:
	w = NIL;
	local[1]= w;
	goto CON15208;
CON15279:
	local[1]= NIL;
CON15208:
	w = T;
	local[0]= w;
BLK15193:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO15340(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env2[1];
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*some*/
static pointer F4503some(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST15385:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[1];
	w = local[0];
	ctx->vsp=local+4;
	argv[1] = cons(ctx,local[3],w);
	local[3]= makeint(0);
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
WHL15442:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX15443;
	local[5]= argv[0];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO15460,env,argv,local);
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,2,local+5); /*apply*/
	local[2] = w;
	if (local[2]==NIL) goto IF15451;
	w = local[2];
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK15383;
	goto IF15452;
IF15451:
	local[5]= NIL;
IF15452:
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL15442;
WHX15443:
	local[5]= NIL;
BLK15444:
	w = NIL;
	w = NIL;
	local[0]= w;
BLK15383:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO15460(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env2[3];
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*reduce*/
static pointer F4508reduce(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[180], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY15520;
	local[0] = makeint(0);
KEY15520:
	if (n & (1<<1)) goto KEY15525;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY15525:
	if (n & (1<<2)) goto KEY15533;
	local[2] = NIL;
KEY15533:
	if (n & (1<<3)) goto KEY15538;
	local[3] = NIL;
KEY15538:
	local[4]= local[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	if (local[2]==NIL) goto IF15564;
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)REVERSE(ctx,1,local+5); /*reverse*/
	argv[1] = w;
	local[5]= argv[1];
	goto IF15565;
IF15564:
	local[5]= NIL;
IF15565:
	local[5]= local[4];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)NUMEQUAL(ctx,2,local+5); /*=*/
	if (w==NIL) goto CON15584;
	if (local[3]!=NIL) goto CON15584;
	local[5]= argv[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	goto CON15582;
CON15584:
	local[5]= local[4];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)NUMEQUAL(ctx,2,local+5); /*=*/
	if (w==NIL) goto CON15597;
	if (local[3]==NIL) goto IF15603;
	local[5]= local[3];
	goto IF15604;
IF15603:
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)FUNCALL(ctx,1,local+5); /*funcall*/
	local[5]= w;
IF15604:
	goto CON15582;
CON15597:
	if (local[3]!=NIL) goto IF15617;
	local[5]= argv[0];
	local[6]= argv[1];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	local[7]= argv[1];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[0] = w;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)FUNCALL(ctx,3,local+5); /*funcall*/
	local[3] = w;
	local[5]= local[4];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[4] = w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[0] = w;
	local[5]= local[0];
	goto IF15618;
IF15617:
	local[5]= NIL;
IF15618:
	local[5]= makeint(0);
	local[6]= local[4];
WHL15696:
	local[7]= local[5];
	w = local[6];
	if ((eusinteger_t)local[7] >= (eusinteger_t)w) goto WHX15697;
	local[7]= argv[0];
	local[8]= local[3];
	local[9]= argv[1];
	local[10]= local[0];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)FUNCALL(ctx,3,local+7); /*funcall*/
	local[3] = w;
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[5] = w;
	goto WHL15696;
WHX15697:
	local[7]= NIL;
BLK15698:
	w = NIL;
	local[5]= local[3];
	goto CON15582;
CON15612:
	local[5]= NIL;
CON15582:
	w = local[5];
	local[0]= w;
BLK15506:
	ctx->vsp=local; return(local[0]);}

/*merge-list*/
static pointer F4511merge_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
WHL15770:
	if (argv[1]==NIL) goto WHX15771;
	local[7]= argv[2];
	local[8]= argv[3];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	ctx->vsp=local+10;
	w=(pointer)FUNCALL(ctx,2,local+8); /*funcall*/
	local[8]= w;
	local[9]= argv[3];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	w=(pointer)FUNCALL(ctx,2,local+9); /*funcall*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)FUNCALL(ctx,3,local+7); /*funcall*/
	if (w!=NIL) goto WHX15771;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	w = local[7];
	local[7]= w;
	w = local[1];
	ctx->vsp=local+8;
	local[1] = cons(ctx,local[7],w);
	goto WHL15770;
WHX15771:
	local[7]= NIL;
BLK15772:
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)NREVERSE(ctx,1,local+7); /*nreverse*/
	local[1] = w;
	local[2] = argv[0];
WHL15862:
	if (argv[1]==NIL) goto WHX15863;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX15863;
	local[7]= argv[3];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)FUNCALL(ctx,2,local+7); /*funcall*/
	local[4] = w;
WHL15892:
	if (local[2]==NIL) goto WHX15893;
	local[7]= argv[2];
	local[8]= argv[3];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	ctx->vsp=local+10;
	w=(pointer)FUNCALL(ctx,2,local+8); /*funcall*/
	local[8]= w;
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)FUNCALL(ctx,3,local+7); /*funcall*/
	if (w==NIL) goto WHX15893;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[7];
	goto WHL15892;
WHX15893:
	local[7]= NIL;
BLK15894:
	if (local[2]==NIL) goto IF15954;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	local[7]= local[2];
	local[8]= argv[1];
	ctx->vsp=local+9;
	w=(pointer)RPLACD2(ctx,2,local+7); /*rplacd2*/
	local[7]= argv[1];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)RPLACD2(ctx,2,local+7); /*rplacd2*/
	local[2] = argv[1];
	argv[1] = local[6];
	local[7]= argv[1];
	goto IF15955;
IF15954:
	local[7]= NIL;
IF15955:
	goto WHL15862;
WHX15863:
	local[7]= NIL;
BLK15864:
	local[7]= local[1];
	local[8]= argv[0];
	local[9]= argv[1];
	ctx->vsp=local+10;
	w=(pointer)NCONC(ctx,3,local+7); /*nconc*/
	local[0]= w;
BLK15740:
	ctx->vsp=local; return(local[0]);}

/*merge*/
static pointer F4514merge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[181], &argv[4], n-4, local+0, 0);
	if (n & (1<<0)) goto KEY16035;
	local[0] = (pointer)get_sym_func(fqv[82]);
KEY16035:
	local[1]= argv[0];
	if (loadglobal(fqv[19])!=local[1]) goto IF16046;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)LISTP(ctx,1,local+1); /*listp*/
	if (w==NIL) goto IF16046;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)LISTP(ctx,1,local+1); /*listp*/
	if (w==NIL) goto IF16046;
	local[1]= argv[1];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)F4511merge_list(ctx,4,local+1); /*merge-list*/
	local[1]= w;
	goto IF16047;
IF16046:
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	local[3]= local[1];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)F4355make_sequence(ctx,2,local+4); /*make-sequence*/
	local[4]= w;
	local[5]= makeint(0);
	local[6]= makeint(0);
	local[7]= makeint(0);
	local[8]= NIL;
	local[9]= NIL;
	local[10]= NIL;
WHL16112:
	local[11]= local[7];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)LESSP(ctx,2,local+11); /*<*/
	if (w==NIL) goto WHX16113;
	local[11]= local[5];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)GREQP(ctx,2,local+11); /*>=*/
	if (w==NIL) goto CON16123;
	local[11]= argv[2];
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[10] = w;
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[6] = w;
	local[11]= local[6];
	goto CON16121;
CON16123:
	local[11]= local[6];
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)GREQP(ctx,2,local+11); /*>=*/
	if (w==NIL) goto CON16148;
	local[11]= argv[1];
	local[12]= local[5];
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[10] = w;
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[5] = w;
	local[11]= local[5];
	goto CON16121;
CON16148:
	local[11]= argv[1];
	local[12]= local[5];
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[8] = w;
	local[11]= argv[2];
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[9] = w;
	local[11]= argv[3];
	local[12]= local[0];
	local[13]= local[8];
	ctx->vsp=local+14;
	w=(pointer)FUNCALL(ctx,2,local+12); /*funcall*/
	local[12]= w;
	local[13]= local[0];
	local[14]= local[9];
	ctx->vsp=local+15;
	w=(pointer)FUNCALL(ctx,2,local+13); /*funcall*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)FUNCALL(ctx,3,local+11); /*funcall*/
	if (w==NIL) goto IF16193;
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[5] = w;
	local[10] = local[8];
	local[11]= local[10];
	goto IF16194;
IF16193:
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[6] = w;
	local[10] = local[9];
	local[11]= local[10];
IF16194:
	goto CON16121;
CON16173:
	local[11]= NIL;
CON16121:
	local[11]= local[4];
	local[12]= local[7];
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(pointer)SETELT(ctx,3,local+11); /*setelt*/
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[7] = w;
	goto WHL16112;
WHX16113:
	local[11]= NIL;
BLK16114:
	w = local[4];
	local[1]= w;
IF16047:
	w = local[1];
	local[0]= w;
BLK16020:
	ctx->vsp=local; return(local[0]);}

/*expt*/
static pointer F4517expt(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[1];
	if (!isint(w)) goto CON16284;
	local[0]= argv[1];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto CON16284;
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)F4478zerop(ctx,1,local+0); /*zerop*/
	if (w==NIL) goto IF16294;
	local[0]= makeint(1);
	goto IF16295;
IF16294:
	local[0]= argv[0];
	local[1]= makeint(1);
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)SUB1(ctx,1,local+2); /*1-*/
	local[2]= w;
WHL16329:
	local[3]= local[2];
	w = makeint(0);
	if ((eusinteger_t)local[3] <= (eusinteger_t)w) goto WHX16330;
	local[3]= local[2];
	w = local[1];
	if ((eusinteger_t)local[3] <= (eusinteger_t)w) goto CON16339;
	local[3]= local[0];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[0] = w;
	local[3]= local[2];
	w = local[1];
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[2] = (pointer)((eusinteger_t)local[3] - (eusinteger_t)w);
	local[3]= local[1];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)ASH(ctx,2,local+3); /*ash*/
	local[1] = w;
	local[3]= local[1];
	goto CON16337;
CON16339:
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[0] = w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)SUB1(ctx,1,local+3); /*1-*/
	local[2] = w;
	local[3]= local[2];
	goto CON16337;
CON16371:
	local[3]= NIL;
CON16337:
	goto WHL16329;
WHX16330:
	local[3]= NIL;
BLK16331:
	w = local[0];
	local[0]= w;
IF16295:
	goto CON16282;
CON16284:
	local[0]= argv[1];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LOG(ctx,1,local+1); /*log*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)EXP(ctx,1,local+0); /*exp*/
	local[0]= w;
	goto CON16282;
CON16394:
	local[0]= NIL;
CON16282:
	w = local[0];
	local[0]= w;
BLK16270:
	ctx->vsp=local; return(local[0]);}

/*signum*/
static pointer F4520signum(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F4478zerop(ctx,1,local+0); /*zerop*/
	if (w==NIL) goto IF16420;
	local[0]= argv[0];
	goto IF16421;
IF16420:
	local[0]= argv[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)ABS(ctx,1,local+1); /*abs*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
IF16421:
	w = local[0];
	local[0]= w;
BLK16410:
	ctx->vsp=local; return(local[0]);}

/*rad2deg*/
static pointer F4523rad2deg(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeflt(3.60000000e+02);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= makeflt(6.28318531e+00);
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
BLK16437:
	ctx->vsp=local; return(local[0]);}

/*deg2rad*/
static pointer F4526deg2rad(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeflt(6.28318531e+00);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= makeflt(3.60000000e+02);
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
BLK16457:
	ctx->vsp=local; return(local[0]);}

/*defsetf*/
static pointer F16476(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST16479:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto CON16492;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (issymbol(w)) goto OR16501;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)F4454functionp(ctx,1,local+1); /*functionp*/
	if (w!=NIL) goto OR16501;
	goto CON16492;
OR16501:
	local[1]= fqv[6];
	local[2]= fqv[182];
	local[3]= fqv[33];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[33];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[33];
	local[6]= fqv[183];
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
	local[3]= fqv[184];
	local[4]= fqv[33];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[33];
	local[6]= fqv[185];
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
	local[4]= fqv[184];
	local[5]= fqv[33];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[33];
	local[7]= fqv[186];
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
	local[5]= fqv[182];
	local[6]= fqv[33];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
	ctx->vsp=local+8;
	w=(pointer)ENDP(ctx,1,local+7); /*endp*/
	if (w!=NIL) goto IF16627;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (isstring(w)) goto IF16643;
	local[7]= fqv[187];
	ctx->vsp=local+8;
	w=(pointer)SIGERROR(ctx,1,local+7); /*error*/
	local[7]= w;
	goto IF16644;
IF16643:
	local[7]= NIL;
IF16644:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
	ctx->vsp=local+8;
	w=(pointer)ENDP(ctx,1,local+7); /*endp*/
	if (w!=NIL) goto IF16662;
	local[7]= fqv[188];
	ctx->vsp=local+8;
	w=(pointer)SIGERROR(ctx,1,local+7); /*error*/
	local[7]= w;
	goto IF16663;
IF16662:
	local[7]= NIL;
IF16663:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	goto IF16628;
IF16627:
	local[7]= NIL;
IF16628:
	local[8]= fqv[33];
	local[9]= fqv[189];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[33];
	local[7]= argv[0];
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
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto CON16490;
CON16492:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[190]); /*list-length*/
	local[1]= w;
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)NUMEQUAL(ctx,2,local+1); /*=*/
	if (w!=NIL) goto IF16726;
	local[1]= fqv[191];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF16727;
IF16726:
	local[1]= NIL;
IF16727:
	local[1]= fqv[6];
	local[2]= fqv[182];
	local[3]= fqv[33];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[33];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[33];
	local[6]= fqv[185];
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
	local[3]= fqv[184];
	local[4]= fqv[33];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[33];
	local[6]= fqv[183];
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
	local[4]= fqv[184];
	local[5]= fqv[33];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[33];
	local[7]= fqv[186];
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
	local[5]= fqv[33];
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
	goto CON16490;
CON16721:
	local[1]= NIL;
CON16490:
	w = local[1];
	local[0]= w;
BLK16477:
	ctx->vsp=local; return(local[0]);}

/*define-setf-method*/
static pointer F16852(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST16855:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[6];
	local[2]= fqv[182];
	local[3]= fqv[33];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[124];
	local[5]= fqv[192];
	local[6]= local[0];
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)APPEND(ctx,2,local+6); /*append*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[33];
	local[6]= fqv[186];
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
	local[3]= fqv[184];
	local[4]= fqv[33];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[33];
	local[6]= fqv[185];
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
	local[4]= fqv[184];
	local[5]= fqv[33];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[33];
	local[7]= fqv[183];
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
	local[5]= fqv[33];
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
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK16853:
	ctx->vsp=local; return(local[0]);}

/*setf-expand-1*/
static pointer F4528setf_expand_1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F4138macroexpand(ctx,1,local+1); /*macroexpand*/
	argv[0] = w;
	w = argv[0];
	if (!iscons(w)) goto CON17010;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	if (fqv[193]!=local[1]) goto CON17010;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[193];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)F4528setf_expand_1(ctx,2,local+1); /*setf-expand-1*/
	local[1]= w;
	goto CON17008;
CON17010:
	w = argv[0];
	if (!issymbol(w)) goto CON17053;
	local[1]= fqv[28];
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto CON17008;
CON17053:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!issymbol(w)) goto CON17069;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[183];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[0] = w;
	if (local[0]==NIL) goto CON17069;
	local[1]= local[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPEND(ctx,2,local+2); /*append*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto CON17008;
CON17069:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!issymbol(w)) goto CON17108;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[194];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[0] = w;
	if (local[0]==NIL) goto CON17108;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[185];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	if (w==NIL) goto CON17108;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	if (fqv[66]==local[1]) goto CON17108;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	if (fqv[146]==local[1]) goto CON17108;
	local[1]= fqv[195];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[33];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	local[5]= argv[1];
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
	goto CON17008;
CON17108:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)F4475macro_function(ctx,1,local+1); /*macro-function*/
	if (w==NIL) goto CON17202;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F4138macroexpand(ctx,1,local+1); /*macroexpand*/
	local[1]= w;
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)F4528setf_expand_1(ctx,2,local+1); /*setf-expand-1*/
	local[1]= w;
	goto CON17008;
CON17202:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[185];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[0] = w;
	if (local[0]==NIL) goto CON17219;
	local[1]= fqv[196];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)APPEND(ctx,2,local+2); /*append*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)APPEND(ctx,3,local+1); /*append*/
	local[1]= w;
	local[2]= argv[1];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[1]= w;
	goto CON17008;
CON17219:
	local[1]= fqv[197];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto CON17008;
CON17272:
	local[1]= NIL;
CON17008:
	w = local[1];
	local[0]= w;
BLK16978:
	ctx->vsp=local; return(local[0]);}

/*setf-expand*/
static pointer F4530setf_expand(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)ENDP(ctx,1,local+0); /*endp*/
	if (w==NIL) goto CON17292;
	local[0]= NIL;
	goto CON17290;
CON17292:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	ctx->vsp=local+1;
	w=(pointer)ENDP(ctx,1,local+0); /*endp*/
	if (w==NIL) goto CON17299;
	local[0]= fqv[198];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,2,local+0); /*error*/
	local[0]= w;
	goto CON17290;
CON17299:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)F4528setf_expand_1(ctx,2,local+0); /*setf-expand-1*/
	local[0]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(pointer)F4530setf_expand(ctx,1,local+1); /*setf-expand*/
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	goto CON17290;
CON17313:
	local[0]= NIL;
CON17290:
	w = local[0];
	local[0]= w;
BLK17280:
	ctx->vsp=local; return(local[0]);}

/*setf*/
static pointer F17343(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST17346:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)ENDP(ctx,1,local+1); /*endp*/
	if (w==NIL) goto CON17357;
	local[1]= NIL;
	goto CON17355;
CON17357:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(pointer)ENDP(ctx,1,local+1); /*endp*/
	if (w==NIL) goto CON17364;
	local[1]= fqv[199];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,2,local+1); /*error*/
	local[1]= w;
	goto CON17355;
CON17364:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(pointer)ENDP(ctx,1,local+1); /*endp*/
	if (w==NIL) goto CON17378;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)F4528setf_expand_1(ctx,2,local+1); /*setf-expand-1*/
	local[1]= w;
	goto CON17355;
CON17378:
	local[1]= fqv[6];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F4530setf_expand(ctx,1,local+2); /*setf-expand*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto CON17355;
CON17405:
	local[1]= NIL;
CON17355:
	w = local[1];
	local[0]= w;
BLK17344:
	ctx->vsp=local; return(local[0]);}

/*multiple-value-bind*/
static pointer F17417(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST17420:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= fqv[200];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= NIL;
	local[3]= makeint(0);
	local[4]= NIL;
	local[5]= argv[0];
WHL17464:
	if (local[5]==NIL) goto WHX17465;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[4];
	local[7]= fqv[55];
	local[8]= local[1];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	w = local[2];
	ctx->vsp=local+7;
	local[2] = cons(ctx,local[6],w);
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[3] = w;
	goto WHL17464;
WHX17465:
	local[6]= NIL;
BLK17466:
	w = NIL;
	local[4]= fqv[50];
	local[5]= local[1];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	w = local[2];
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	w = local[0];
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	local[0]= w;
BLK17418:
	ctx->vsp=local; return(local[0]);}

/*multiple-value-setq*/
static pointer F17573(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(0);
	local[1]= fqv[201];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0];
WHL17620:
	if (local[4]==NIL) goto WHX17621;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[0];
	local[6]= fqv[202];
	ctx->vsp=local+7;
	w=(pointer)F4295assoc(ctx,2,local+5); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,2,local+5); /*list*/
	local[5]= w;
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[3];
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[0] = w;
	goto WHL17620;
WHX17621:
	local[5]= NIL;
BLK17622:
	w = NIL;
	local[3]= fqv[5];
	local[4]= local[1];
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[4]= w;
	local[5]= fqv[28];
	w = local[2];
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	local[0]= w;
BLK17574:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___common(ctx,n,argv,env)
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
	local[0]= fqv[203];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF17750;
	local[0]= fqv[204];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[49],w);
	goto IF17751;
IF17750:
	local[0]= fqv[205];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF17751:
	local[0]= fqv[206];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= fqv[207];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[208];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[209];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[210];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[211];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[212];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[213];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[214];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[215],module,F4132lisp_implementation_type,fqv[216]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[2],module,F4134lisp_implementation_version,fqv[217]);
	local[0]= NIL;
	storeglobal(fqv[218],local[0]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[219],module,F4138macroexpand,fqv[220]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[15],module,F4782,fqv[221]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[222],module,F4845,fqv[223]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[224],module,F4904,fqv[225]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[226],module,F4937,fqv[227]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[47],module,F4971,fqv[228]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[229],module,F5018,fqv[230]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[231],module,F5055,fqv[232]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[56],module,F5176,fqv[233]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[234],module,F5230,fqv[235]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[236],module,F5284,fqv[237]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[238],module,F5338,fqv[239]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[240],module,F5392,fqv[241]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[242],module,F5559,fqv[243]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[244],module,F5640,fqv[245]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[246],module,F5702,fqv[247]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[248],module,F5764,fqv[249]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[62],module,F5918,fqv[250]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[64],module,F6075,fqv[251]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[252],module,F6302,fqv[253]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[254],module,F6529,fqv[255]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[69],module,F6606,fqv[256]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[257],module,F6796,fqv[258]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[259],module,F7025,fqv[260]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[261],module,F7254,fqv[262]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[263],module,F7299,fqv[264]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[265],module,F4167casebody,fqv[266]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[267],module,F4170casehead,fqv[268]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[269],module,F4173case1,fqv[270]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[179],module,F7480,fqv[271]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[272],module,F4177classcasehead,fqv[273]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[274],module,F4180classcase1,fqv[275]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[276],module,F7651,fqv[277]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[155],module,F4183string,fqv[278]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[279],module,F4187alias,fqv[280]);
	local[0]= fqv[190];
	local[1]= fqv[54];
	ctx->vsp=local+2;
	w=(pointer)F4187alias(ctx,2,local+0); /*alias*/
	local[0]= fqv[281];
	local[1]= fqv[66];
	ctx->vsp=local+2;
	w=(pointer)F4187alias(ctx,2,local+0); /*alias*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[282],module,F4193caaar,fqv[283]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[284],module,F4196caadr,fqv[285]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[286],module,F4199cadar,fqv[287]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[288],module,F4202cdaar,fqv[289]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[290],module,F4205cdadr,fqv[291]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[292],module,F4208cddar,fqv[293]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[294],module,F4211cdddr,fqv[295]);
	local[0]= fqv[296];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)F4187alias(ctx,2,local+0); /*alias*/
	local[0]= fqv[297];
	local[1]= fqv[298];
	ctx->vsp=local+2;
	w=(pointer)F4187alias(ctx,2,local+0); /*alias*/
	local[0]= fqv[299];
	local[1]= fqv[300];
	ctx->vsp=local+2;
	w=(pointer)F4187alias(ctx,2,local+0); /*alias*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[301],module,F4217fourth,fqv[302]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[303],module,F4220fifth,fqv[304]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[305],module,F4223sixth,fqv[306]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[307],module,F4226seventh,fqv[308]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[309],module,F4229eighth,fqv[310]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[311],module,F4232cddddr,fqv[312]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[313],module,F4235cadddr,fqv[314]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[315],module,F4238caaddr,fqv[316]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[317],module,F4241cdaddr,fqv[318]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[319],module,F4244caddddr,fqv[320]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[321],module,F4247flatten,fqv[322]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[323],module,F4250list_insert,fqv[324]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[325],module,F4253list_delete,fqv[326]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[327],module,F4256adjoin,fqv[328]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[329],module,F4259union,fqv[330]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[331],module,F4262intersection,fqv[332]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[333],module,F4265set_difference,fqv[334]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[335],module,F4268set_exclusive_or,fqv[336]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[337],module,F4271rotate_list,fqv[338]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[339],module,F4274last,fqv[340]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[341],module,F4277copy_tree,fqv[342]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[343],module,F4280copy_list,fqv[344]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[345],module,F4283nreconc,fqv[346]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[347],module,F4286rassoc,fqv[348]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[349],module,F4289acons,fqv[350]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[22],module,F4292member,fqv[351]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[352],module,F4295assoc,fqv[353]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[354],module,F4298subsetp,fqv[355]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[356],module,F4301maplist,fqv[357]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[358],module,F4304mapcon,fqv[359]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[360],module,F4307find,fqv[361]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[362],module,F4310find_if,fqv[363]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[364],module,F4313find_if_not,fqv[365]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[366],module,F4316position,fqv[367]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[368],module,F4319position_if,fqv[369]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[370],module,F4322position_if_not,fqv[371]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[372],module,F4325count,fqv[373]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[374],module,F4328count_if,fqv[375]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[376],module,F4331count_if_not,fqv[377]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[378],module,F4334member_if,fqv[379]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[380],module,F4337member_if_not,fqv[381]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[382],module,F4340collect_if,fqv[383]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[384],module,F4343collect_instances,fqv[385]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[386],module,F4346pairlis,fqv[387]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[388],module,F4349transpose_list,fqv[389]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[390],module,F4352make_list,fqv[391]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[392],module,F4355make_sequence,fqv[393]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[394],module,F4358fill,fqv[395]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[396],module,F4361replace,fqv[397]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[398],module,F4364remove,fqv[399]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[400],module,F4367remove_if,fqv[401]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[402],module,F4370remove_if_not,fqv[403]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[404],module,F4373delete,fqv[405]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[406],module,F4376delete_if,fqv[407]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[408],module,F4379delete_if_not,fqv[409]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[410],module,F4382substitute,fqv[411]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[412],module,F4385substitute_if,fqv[413]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[414],module,F4388substitute_if_not,fqv[415]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[416],module,F4391nsubstitute,fqv[417]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[418],module,F4394nsubstitute_if,fqv[419]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[420],module,F4397nsubstitute_if_not,fqv[421]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[422],module,F4400unique,fqv[423]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[424],module,F4403remove_duplicates,fqv[425]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[426],module,F4406extream,fqv[427]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[428],module,F12687,fqv[429]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[430],module,F12747,fqv[431]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[432],module,F12801,fqv[433]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[132],module,F12845,fqv[434]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[435],module,F12877,fqv[436]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[437],module,F4415send_all,fqv[438]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[439],module,F4418resend,fqv[440]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[441],module,F12990,fqv[442]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[443],module,F13071,fqv[444]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[445],module,F4423make_instance,fqv[446]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[447],module,F13268,fqv[448]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[449],module,F4427delete_method,fqv[450]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[160],module,F4430make_class,fqv[451]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[452],module,F14094,fqv[453]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[454],module,F14176,fqv[455]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[456],module,F4437readtablep,fqv[457]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[458],module,F4440copy_readtable,fqv[459]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[460],module,F4443set_syntax_from_char,fqv[461]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[462],module,F4448keywordp,fqv[463]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[464],module,F4451constantp,fqv[465]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[466],module,F4454functionp,fqv[467]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[468],module,F4457vector_class_p,fqv[469]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[470],module,F4460compiled_function_p,fqv[471]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[472],module,F4463input_stream_p,fqv[473]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[474],module,F4466output_stream_p,fqv[475]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[476],module,F4469io_stream_p,fqv[477]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[478],module,F4472special_form_p,fqv[479]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[480],module,F4475macro_function,fqv[481]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[482],module,F4478zerop,fqv[483]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[484],module,F4481plusp,fqv[485]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[486],module,F4484minusp,fqv[487]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[488],module,F4487oddp,fqv[489]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[490],module,F4490evenp,fqv[491]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[492],module,F4493logandc1,fqv[493]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[494],module,F4496logandc2,fqv[495]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[496],module,F15172,fqv[497]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[498],module,F4500every,fqv[499]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[500],module,F4503some,fqv[501]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[502],module,F4508reduce,fqv[503]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[504],module,F4511merge_list,fqv[505]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[506],module,F4514merge,fqv[507]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[508],module,F4517expt,fqv[509]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[510],module,F4520signum,fqv[511]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[512],module,F4523rad2deg,fqv[513]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[514],module,F4526deg2rad,fqv[515]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[516],module,F16476,fqv[517]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[518],module,F16852,fqv[519]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[520],module,F4528setf_expand_1,fqv[521]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[522],module,F4530setf_expand,fqv[523]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[17],module,F17343,fqv[524]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[525],module,F17417,fqv[526]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[527],module,F17573,fqv[528]);
	local[0]= fqv[281];
	local[1]= fqv[66];
	ctx->vsp=local+2;
	w=(pointer)F4187alias(ctx,2,local+0); /*alias*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<4; i++) ftab[i]=fcallx;
}
