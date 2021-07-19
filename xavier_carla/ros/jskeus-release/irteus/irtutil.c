/* ./irtutil.c :  entry=irtutil */
/* compiled by EusLisp 9.27() for Linux created on ip-10-0-1-214(Fri Apr 16 04:05:26 PST 2021) */
#include "eus.h"
#include "irtutil.h"
#pragma init (register_irtutil)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___irtutil();
extern pointer build_quote_vector();
static int register_irtutil()
  { add_module_initializer("___irtutil", ___irtutil);}

static pointer F485forward_message_to();
static pointer F486forward_message_to_all();
static pointer F487permutation();
static pointer F488combination();
static pointer F489mapjoin();
static pointer F490find_extreams();
static pointer F491need_thread();
static pointer F492eus_server();
static pointer F493connect_server_until_success();
static pointer F494format_array();
static pointer F495his2rgb();
static pointer F496hvs2rgb();
static pointer F497rgb2his();
static pointer F498rgb2hvs();
static pointer F499color_category10();
static pointer F500color_category20();
static pointer F501termios_c_iflag();
static pointer F502set_termios_c_iflag();
static pointer F503termios_c_oflag();
static pointer F504set_termios_c_oflag();
static pointer F505termios_c_cflag();
static pointer F506set_termios_c_cflag();
static pointer F507termios_c_lflag();
static pointer F508set_termios_c_lflag();
static pointer F509termios_c_line();
static pointer F510set_termios_c_line();
static pointer F511termios_c_cc();
static pointer F512set_termios_c_cc();
static pointer F513termios_c_ispeed();
static pointer F514set_termios_c_ispeed();
static pointer F515termios_c_ospeed();
static pointer F516set_termios_c_ospeed();
static pointer F517kbhit();
static pointer F518piped_fork_returns_list();
static pointer F519make_robot_model_from_name();

/*forward-message-to*/
static pointer F485forward_message_to(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]==NIL) goto IF521;
	if (argv[1]==NIL) goto IF523;
	local[0]= (pointer)get_sym_func(fqv[0]);
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,3,local+0); /*apply*/
	local[0]= w;
	goto IF524;
IF523:
	local[0]= argv[0];
IF524:
	goto IF522;
IF521:
	if (loadglobal(fqv[1])==NIL) goto IF525;
	local[0]= fqv[2];
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,3,local+0,&ftab[0],fqv[3]); /*warn*/
	local[0]= w;
	goto IF526;
IF525:
	local[0]= NIL;
IF526:
IF522:
	w = local[0];
	local[0]= w;
BLK520:
	ctx->vsp=local; return(local[0]);}

/*forward-message-to-all*/
static pointer F486forward_message_to_all(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]==NIL) goto IF528;
	if (argv[1]==NIL) goto IF530;
	local[0]= (pointer)get_sym_func(fqv[4]);
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,3,local+0); /*apply*/
	local[0]= w;
	goto IF531;
IF530:
	local[0]= argv[0];
IF531:
	goto IF529;
IF528:
	if (loadglobal(fqv[1])==NIL) goto IF532;
	local[0]= fqv[5];
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,3,local+0,&ftab[0],fqv[3]); /*warn*/
	local[0]= w;
	goto IF533;
IF532:
	local[0]= NIL;
IF533:
IF529:
	w = local[0];
	local[0]= w;
BLK527:
	ctx->vsp=local; return(local[0]);}

/*send-message**/
static pointer F534(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST536:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= fqv[6];
	local[2]= fqv[7];
	local[3]= fqv[8];
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
BLK535:
	ctx->vsp=local; return(local[0]);}

/*do-until-key-with-check*/
static pointer F537(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST539:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[9];
	local[2]= fqv[10];
	local[3]= fqv[11];
	local[4]= fqv[12];
	local[5]= fqv[13];
	local[6]= fqv[14];
	local[7]= fqv[15];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[16];
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
	local[5]= fqv[17];
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
	local[3]= cons(ctx,local[3],w);
	local[4]= local[0];
	local[5]= NIL;
	ctx->vsp=local+6;
	w=(pointer)APPEND(ctx,2,local+4); /*append*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[18];
	local[4]= fqv[19];
	local[5]= fqv[20];
	local[6]= fqv[13];
	local[7]= fqv[14];
	local[8]= fqv[15];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[21];
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
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[4]= w;
	local[5]= fqv[22];
	local[6]= fqv[19];
	local[7]= fqv[23];
	local[8]= fqv[19];
	local[9]= fqv[24];
	local[10]= fqv[24];
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
BLK538:
	ctx->vsp=local; return(local[0]);}

/*do-until-key*/
static pointer F540(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST542:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= fqv[25];
	local[2]= fqv[26];
	local[3]= local[0];
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)APPEND(ctx,2,local+3); /*append*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK541:
	ctx->vsp=local; return(local[0]);}

/*do-until-key-with-timer*/
static pointer F543(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST545:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+1;
	w=(pointer)GENSYM(ctx,0,local+1); /*gensym*/
	local[1]= w;
	local[2]= fqv[18];
	local[3]= local[1];
	local[4]= fqv[27];
	local[5]= fqv[28];
	local[6]= fqv[29];
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
	local[3]= w;
	local[4]= fqv[25];
	local[5]= fqv[30];
	local[6]= fqv[0];
	local[7]= local[1];
	local[8]= fqv[31];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= local[0];
	local[7]= NIL;
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
BLK544:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M546mtimer_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[32];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = argv[0];
	local[0]= w;
BLK547:
	ctx->vsp=local; return(local[0]);}

/*:start*/
static pointer M548mtimer_start(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	w=(pointer)GETTIMEOFDAY(ctx,0,local+0); /*unix:gettimeofday*/
	argv[0]->c.obj.iv[0] = w;
	w = argv[0]->c.obj.iv[0];
	local[0]= w;
BLK549:
	ctx->vsp=local; return(local[0]);}

/*:stop*/
static pointer M550mtimer_stop(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	ctx->vsp=local+1;
	w=(pointer)GETTIMEOFDAY(ctx,0,local+1); /*unix:gettimeofday*/
	local[0] = w;
	local[1]= loadglobal(fqv[33]);
	local[2]= (pointer)get_sym_func(fqv[34]);
	local[3]= local[0];
	local[4]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+5;
	w=(pointer)MAP(ctx,4,local+1); /*map*/
	local[0] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= makeflt(1.0000000000000000000000e+06);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[0]= w;
BLK551:
	ctx->vsp=local; return(local[0]);}

/*permutation*/
static pointer F487permutation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF553;
	local[0]= fqv[35];
	goto IF554;
IF553:
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO555,env,argv,local);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
IF554:
	w = local[0];
	local[0]= w;
BLK552:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO555(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO556,env,argv,local);
	local[1]= argv[0];
	local[2]= env->c.clo.env1[0];
	local[3]= fqv[36];
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,4,local+1,&ftab[1],fqv[37]); /*remove*/
	local[1]= w;
	local[2]= env->c.clo.env1[1];
	ctx->vsp=local+3;
	w=(pointer)SUB1(ctx,1,local+2); /*1-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F487permutation(ctx,2,local+1); /*permutation*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO556(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	w = argv[0];
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*combination*/
static pointer F488combination(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF558;
	local[0]= fqv[38];
	goto IF559;
IF558:
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO560,env,argv,local);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
IF559:
	w = local[0];
	local[0]= w;
BLK557:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO560(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO561,env,argv,local);
	local[1]= argv[0];
	local[2]= env->c.clo.env1[0];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[39]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	local[2]= env->c.clo.env1[1];
	ctx->vsp=local+3;
	w=(pointer)SUB1(ctx,1,local+2); /*1-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F488combination(ctx,2,local+1); /*combination*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO561(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	w = argv[0];
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*mapjoin*/
static pointer F489mapjoin(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO563,env,argv,local);
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
BLK562:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO563(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO564,env,argv,local);
	local[1]= env->c.clo.env1[2];
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO564(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env0->c.clo.env1[0];
	local[1]= env->c.clo.env1[0];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)FUNCALL(ctx,3,local+0); /*funcall*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*find-extreams*/
static pointer F490find_extreams(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[40], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY566;
	local[0] = (pointer)get_sym_func(fqv[41]);
KEY566:
	if (n & (1<<1)) goto KEY567;
	local[1] = (pointer)get_sym_func(fqv[42]);
KEY567:
	if (n & (1<<2)) goto KEY568;
	local[2] = (pointer)get_sym_func(fqv[43]);
KEY568:
	local[3]= local[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)FUNCALL(ctx,2,local+3); /*funcall*/
	local[3]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= local[4];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	local[5]= w;
	local[6]= NIL;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
WHL570:
	if (local[7]==NIL) goto WHX571;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[0];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)FUNCALL(ctx,2,local+8); /*funcall*/
	local[8]= w;
	local[9]= local[2];
	local[10]= local[8];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)FUNCALL(ctx,3,local+9); /*funcall*/
	if (w==NIL) goto CON575;
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[5] = w;
	local[3] = local[8];
	local[4] = local[6];
	local[9]= local[4];
	goto CON574;
CON575:
	local[9]= local[1];
	local[10]= local[8];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)FUNCALL(ctx,3,local+9); /*funcall*/
	if (w==NIL) goto CON576;
	local[9]= local[6];
	w = local[5];
	ctx->vsp=local+10;
	local[5] = cons(ctx,local[9],w);
	local[9]= local[5];
	goto CON574;
CON576:
	local[9]= NIL;
CON574:
	w = local[9];
	goto WHL570;
WHX571:
	local[8]= NIL;
BLK572:
	w = NIL;
	w = local[5];
	local[0]= w;
BLK565:
	ctx->vsp=local; return(local[0]);}

/*need-thread*/
static pointer F491need_thread(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT580;}
	local[0]= makeint((eusinteger_t)512L);
	{ eusinteger_t i,j;
		j=intval(makeint((eusinteger_t)1024L)); i=intval(local[0]);
		local[0]=(makeint(i * j));}
ENT580:
	if (n>=3) { local[1]=(argv[2]); goto ENT579;}
	local[1]= local[0];
ENT579:
ENT578:
	if (n>3) maerror();
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)FREE_THREADS(ctx,0,local+5); /*system::free-threads*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[2] = w;
	local[4]= local[2];
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)GREATERP(ctx,2,local+4); /*>*/
	if (w==NIL) goto IF581;
	local[4]= makeint((eusinteger_t)0L);
	local[5]= local[2];
WHL584:
	local[6]= local[4];
	w = local[5];
	if ((eusinteger_t)local[6] >= (eusinteger_t)w) goto WHX585;
	local[6]= makeint((eusinteger_t)1L);
	local[7]= local[0];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)MAKE_THREAD(ctx,3,local+6); /*system:make-thread*/
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO587,env,argv,local);
	ctx->vsp=local+7;
	w=(pointer)AFUNCALL(ctx,1,local+6); /*thread*/
	local[6]= w;
	w = local[3];
	ctx->vsp=local+7;
	local[3] = cons(ctx,local[6],w);
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[4] = w;
	goto WHL584;
WHX585:
	local[6]= NIL;
BLK586:
	w = NIL;
	local[4]= NIL;
	local[5]= local[3];
WHL589:
	if (local[5]==NIL) goto WHX590;
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
	w=(pointer)WAIT_AFUNCALL(ctx,1,local+6); /*system:wait-thread*/
	goto WHL589;
WHX590:
	local[6]= NIL;
BLK591:
	w = NIL;
	local[4]= w;
	goto IF582;
IF581:
	local[4]= NIL;
IF582:
	w = local[4];
	local[0]= w;
BLK577:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO587(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	w = NIL;
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*eus-server*/
static pointer F492eus_server(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT595;}
	local[0]= makeint((eusinteger_t)6666L);
ENT595:
ENT594:
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[44], &argv[1], n-1, local+1, 0);
	if (n & (1<<0)) goto KEY596;
	ctx->vsp=local+2;
	w=(pointer)GETHOSTNAME(ctx,0,local+2); /*unix:gethostname*/
	local[1] = w;
KEY596:
	local[2]= fqv[45];
	local[3]= local[1];
	local[4]= fqv[46];
	local[5]= makeint((eusinteger_t)2L);
	local[6]= fqv[47];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(*ftab[3])(ctx,6,local+2,&ftab[3],fqv[48]); /*make-socket-address*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[4])(ctx,1,local+2,&ftab[4],fqv[49]); /*make-socket-port*/
	local[2]= w;
	local[3]= local[2];
	local[4]= loadglobal(fqv[50]);
	ctx->vsp=local+5;
	w=(pointer)DERIVEDP(ctx,2,local+3); /*derivedp*/
	if (w==NIL) goto CON598;
	local[3]= loadglobal(fqv[51]);
	local[4]= fqv[52];
	local[5]= local[2];
	local[6]= fqv[53];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,5,local+3); /*send*/
	local[3]= w;
	goto CON597;
CON598:
	local[3]= NIL;
	local[4]= fqv[54];
	local[5]= local[0];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,4,local+3); /*format*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
	goto CON597;
CON599:
	local[3]= NIL;
CON597:
	w = local[3];
	local[0]= w;
BLK593:
	ctx->vsp=local; return(local[0]);}

/*connect-server-until-success*/
static pointer F493connect_server_until_success(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[55], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY601;
	local[2]= argv[1];
	local[3]= makeint((eusinteger_t)20L);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[0] = w;
KEY601:
	if (n & (1<<1)) goto KEY602;
	local[1] = NIL;
KEY602:
	local[2]= NIL;
	local[3]= argv[1];
WHL603:
	local[4]= argv[0];
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(*ftab[5])(ctx,2,local+4,&ftab[5],fqv[56]); /*connect-server*/
	local[2] = w;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)STREAMP(ctx,1,local+4); /*streamp*/
	if (w!=NIL) goto WHX604;
	local[4]= argv[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,2,local+4); /*<*/
	if (w==NIL) goto WHX604;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	argv[1] = w;
	goto WHL603;
WHX604:
	local[4]= NIL;
BLK605:
	local[4]= argv[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,2,local+4); /*<*/
	if (w==NIL) goto CON607;
	local[4]= fqv[57];
	local[5]= makeint((eusinteger_t)27L);
	local[6]= argv[0];
	local[7]= argv[1];
	local[8]= makeint((eusinteger_t)27L);
	ctx->vsp=local+9;
	w=(*ftab[0])(ctx,5,local+4,&ftab[0],fqv[3]); /*warn*/
	if (local[1]==NIL) goto IF608;
	local[4]= local[2];
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,2,local+4); /*list*/
	local[4]= w;
	goto IF609;
IF608:
	local[4]= local[2];
IF609:
	goto CON606;
CON607:
	local[4]= fqv[58];
	local[5]= makeint((eusinteger_t)27L);
	local[6]= argv[0];
	local[7]= local[3];
	local[8]= local[0];
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	local[9]= makeint((eusinteger_t)27L);
	ctx->vsp=local+10;
	w=(*ftab[0])(ctx,6,local+4,&ftab[0],fqv[3]); /*warn*/
	local[4]= NIL;
	goto CON606;
CON610:
	local[4]= NIL;
CON606:
	w = local[4];
	local[0]= w;
BLK600:
	ctx->vsp=local; return(local[0]);}

/*format-array*/
static pointer F494format_array(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT617;}
	local[0]= fqv[59];
ENT617:
	if (n>=3) { local[1]=(argv[2]); goto ENT616;}
	local[1]= makeint((eusinteger_t)7L);
ENT616:
	if (n>=4) { local[2]=(argv[3]); goto ENT615;}
	local[2]= makeint((eusinteger_t)3L);
ENT615:
	if (n>=5) { local[3]=(argv[4]); goto ENT614;}
	local[3]= loadglobal(fqv[60]);
ENT614:
	if (n>=6) { local[4]=(argv[5]); goto ENT613;}
	local[4]= T;
ENT613:
ENT612:
	if (n>6) maerror();
	local[5]= argv[0];
	local[6]= fqv[61];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= local[5];
	if (fqv[62]!=local[6]) goto IF619;
	local[6]= NIL;
	local[7]= fqv[63];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	goto IF620;
IF619:
	local[6]= local[5];
	if (fqv[64]!=local[6]) goto IF621;
	local[6]= NIL;
	local[7]= fqv[65];
	local[8]= local[1];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,4,local+6); /*format*/
	local[6]= w;
	goto IF622;
IF621:
	local[6]= NIL;
IF622:
IF620:
	w = local[6];
	local[5]= w;
	local[6]= NIL;
	local[7]= fqv[66];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	local[7]= NIL;
	local[8]= local[6];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	local[8]= argv[0];
	local[9]= loadglobal(fqv[67]);
	ctx->vsp=local+10;
	w=(pointer)DERIVEDP(ctx,2,local+8); /*derivedp*/
	if (w==NIL) goto CON624;
	local[8]= makeint((eusinteger_t)0L);
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	local[9]= w;
WHL626:
	local[10]= local[8];
	w = local[9];
	if ((eusinteger_t)local[10] >= (eusinteger_t)w) goto WHX627;
	local[10]= NIL;
	local[11]= local[5];
	local[12]= argv[0];
	local[13]= local[8];
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,3,local+10); /*format*/
	local[10]= w;
	w = local[7];
	ctx->vsp=local+11;
	local[7] = cons(ctx,local[10],w);
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[8] = w;
	goto WHL626;
WHX627:
	local[10]= NIL;
BLK628:
	w = NIL;
	if (local[4]==NIL) goto IF629;
	local[8]= fqv[68];
	w = local[7];
	ctx->vsp=local+9;
	local[7] = cons(ctx,local[8],w);
	local[8]= local[7];
	goto IF630;
IF629:
	local[8]= NIL;
IF630:
	goto CON623;
CON624:
	local[8]= argv[0];
	local[9]= loadglobal(fqv[69]);
	ctx->vsp=local+10;
	w=(pointer)DERIVEDP(ctx,2,local+8); /*derivedp*/
	if (w==NIL) goto CON631;
	local[8]= makeint((eusinteger_t)0L);
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(*ftab[6])(ctx,1,local+9,&ftab[6],fqv[70]); /*array-dimensions*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
WHL633:
	local[10]= local[8];
	w = local[9];
	if ((eusinteger_t)local[10] >= (eusinteger_t)w) goto WHX634;
	local[10]= local[8];
	local[11]= makeint((eusinteger_t)0L);
	ctx->vsp=local+12;
	w=(*ftab[7])(ctx,2,local+10,&ftab[7],fqv[71]); /*/=*/
	if (w==NIL) goto IF636;
	local[10]= NIL;
	local[11]= local[6];
	local[12]= fqv[72];
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,3,local+10); /*format*/
	local[10]= w;
	w = local[7];
	ctx->vsp=local+11;
	local[7] = cons(ctx,local[10],w);
	local[10]= local[7];
	goto IF637;
IF636:
	local[10]= NIL;
IF637:
	local[10]= makeint((eusinteger_t)0L);
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(*ftab[6])(ctx,1,local+11,&ftab[6],fqv[70]); /*array-dimensions*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
WHL639:
	local[12]= local[10];
	w = local[11];
	if ((eusinteger_t)local[12] >= (eusinteger_t)w) goto WHX640;
	local[12]= NIL;
	local[13]= local[5];
	local[14]= argv[0];
	local[15]= local[8];
	local[16]= local[10];
	ctx->vsp=local+17;
	w=(pointer)AREF(ctx,3,local+14); /*aref*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)XFORMAT(ctx,3,local+12); /*format*/
	local[12]= w;
	w = local[7];
	ctx->vsp=local+13;
	local[7] = cons(ctx,local[12],w);
	local[12]= local[10];
	ctx->vsp=local+13;
	w=(pointer)ADD1(ctx,1,local+12); /*1+*/
	local[10] = w;
	goto WHL639;
WHX640:
	local[12]= NIL;
BLK641:
	w = NIL;
	if (local[4]==NIL) goto IF642;
	local[10]= fqv[73];
	w = local[7];
	ctx->vsp=local+11;
	local[7] = cons(ctx,local[10],w);
	local[10]= local[7];
	goto IF643;
IF642:
	local[10]= NIL;
IF643:
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[8] = w;
	goto WHL633;
WHX634:
	local[10]= NIL;
BLK635:
	w = NIL;
	local[8]= w;
	goto CON623;
CON631:
	local[8]= NIL;
CON623:
	local[8]= local[3];
	local[9]= (pointer)get_sym_func(fqv[74]);
	local[10]= loadglobal(fqv[75]);
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)NREVERSE(ctx,1,local+11); /*nreverse*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)APPLY(ctx,3,local+9); /*apply*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,2,local+8); /*format*/
	local[8]= w;
	if (local[3]==NIL) goto IF644;
	local[9]= argv[0];
	goto IF645;
IF644:
	local[9]= local[8];
IF645:
	w = local[9];
	local[0]= w;
BLK611:
	ctx->vsp=local; return(local[0]);}

/*with-gensyms*/
static pointer F646(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST648:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[18];
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO649,env,argv,local);
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	local[3]= local[0];
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)APPEND(ctx,2,local+3); /*append*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK647:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO649(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[76];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M650interpolator_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[4] = makeflt(0.0000000000000000000000e+00);
	argv[0]->c.obj.iv[6] = makeflt(0.0000000000000000000000e+00);
	argv[0]->c.obj.iv[7] = makeint((eusinteger_t)0L);
	argv[0]->c.obj.iv[5] = makeint((eusinteger_t)0L);
	argv[0]->c.obj.iv[8] = NIL;
	w = argv[0];
	local[0]= w;
BLK651:
	ctx->vsp=local; return(local[0]);}

/*:reset*/
static pointer M652interpolator_reset(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST654:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[77], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY655;
	local[3]= argv[0];
	local[4]= fqv[78];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[1] = w;
KEY655:
	if (n & (1<<1)) goto KEY656;
	local[3]= argv[0];
	local[4]= fqv[79];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[2] = w;
KEY656:
	argv[0]->c.obj.iv[1] = local[1];
	argv[0]->c.obj.iv[2] = local[2];
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[7])(ctx,2,local+3,&ftab[7],fqv[71]); /*/=*/
	if (w==NIL) goto IF657;
	local[3]= makeint((eusinteger_t)1L);
	local[4]= fqv[80];
	ctx->vsp=local+5;
	w=(*ftab[8])(ctx,2,local+3,&ftab[8],fqv[81]); /*warning-message*/
	local[3]= w;
	goto IF658;
IF657:
	local[3]= NIL;
IF658:
	argv[0]->c.obj.iv[4] = makeflt(0.0000000000000000000000e+00);
	argv[0]->c.obj.iv[6] = makeflt(0.0000000000000000000000e+00);
	argv[0]->c.obj.iv[7] = makeint((eusinteger_t)0L);
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SUB1(ctx,1,local+3); /*1-*/
	argv[0]->c.obj.iv[5] = w;
	argv[0]->c.obj.iv[8] = NIL;
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK653:
	ctx->vsp=local; return(local[0]);}

/*:position-list*/
static pointer M659interpolator_position_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK660:
	ctx->vsp=local; return(local[0]);}

/*:position*/
static pointer M661interpolator_position(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK662:
	ctx->vsp=local; return(local[0]);}

/*:time-list*/
static pointer M663interpolator_time_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK664:
	ctx->vsp=local; return(local[0]);}

/*:time*/
static pointer M665interpolator_time(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK666:
	ctx->vsp=local; return(local[0]);}

/*:segment-time*/
static pointer M667interpolator_segment_time(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK668:
	ctx->vsp=local; return(local[0]);}

/*:segment*/
static pointer M669interpolator_segment(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[7];
	local[0]= w;
BLK670:
	ctx->vsp=local; return(local[0]);}

/*:segment-num*/
static pointer M671interpolator_segment_num(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK672:
	ctx->vsp=local; return(local[0]);}

/*:interpolatingp*/
static pointer M673interpolator_interpolatingp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK674:
	ctx->vsp=local; return(local[0]);}

/*:start-interpolation*/
static pointer M675interpolator_start_interpolation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[8] = T;
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK676:
	ctx->vsp=local; return(local[0]);}

/*:stop-interpolation*/
static pointer M677interpolator_stop_interpolation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[8] = NIL;
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK678:
	ctx->vsp=local; return(local[0]);}

/*:pass-time*/
static pointer M679interpolator_pass_time(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[0]->c.obj.iv[8]==NIL) goto IF681;
	local[0]= argv[0];
	local[1]= fqv[82];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[3] = w;
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[4] = w;
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= argv[0]->c.obj.iv[7];
	if (makeint((eusinteger_t)0L)!=local[1]) goto IF683;
	local[1]= makeint((eusinteger_t)0L);
	goto IF684;
IF683:
	local[1]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+2;
	w=(pointer)SUB1(ctx,1,local+1); /*1-*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)NTH(ctx,2,local+1); /*nth*/
	local[1]= w;
IF684:
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	argv[0]->c.obj.iv[6] = w;
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= argv[0]->c.obj.iv[7];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)NTH(ctx,2,local+1); /*nth*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF685;
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= argv[0]->c.obj.iv[7];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)NTH(ctx,2,local+1); /*nth*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	argv[0]->c.obj.iv[6] = w;
	local[0]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	argv[0]->c.obj.iv[7] = w;
	local[0]= argv[0]->c.obj.iv[7];
	goto IF686;
IF685:
	local[0]= NIL;
IF686:
	local[0]= argv[0]->c.obj.iv[7];
	w = argv[0]->c.obj.iv[5];
	if ((eusinteger_t)local[0] < (eusinteger_t)w) goto IF687;
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(*ftab[9])(ctx,1,local+0,&ftab[9],fqv[83]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[3] = (w)->c.cons.car;
	local[0]= argv[0];
	local[1]= fqv[84];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF688;
IF687:
	local[0]= NIL;
IF688:
	local[0]= argv[0]->c.obj.iv[3];
	goto IF682;
IF681:
	local[0]= NIL;
IF682:
	w = local[0];
	local[0]= w;
BLK680:
	ctx->vsp=local; return(local[0]);}

/*:interpolation*/
static pointer M689linear_interpolator_interpolation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[7];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)NTH(ctx,2,local+0); /*nth*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+2;
	w=(pointer)ADD1(ctx,1,local+1); /*1+*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)NTH(ctx,2,local+1); /*nth*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[7];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)NTH(ctx,2,local+2); /*nth*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[7];
	w = makeint((eusinteger_t)0L);
	if ((eusinteger_t)local[3] <= (eusinteger_t)w) goto IF691;
	local[3]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+4;
	w=(pointer)SUB1(ctx,1,local+3); /*1-*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)NTH(ctx,2,local+3); /*nth*/
	local[3]= w;
	goto IF692;
IF691:
	local[3]= makeint((eusinteger_t)0L);
IF692:
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[6];
	local[4]= local[2];
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	local[5]= local[4];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SCALEVEC(ctx,2,local+5); /*scale*/
	local[0] = w;
	local[5]= local[3];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SCALEVEC(ctx,2,local+5); /*scale*/
	local[1] = w;
	local[5]= local[0];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)VPLUS(ctx,2,local+5); /*v+*/
	local[0]= w;
BLK690:
	ctx->vsp=local; return(local[0]);}

/*:velocity*/
static pointer M693minjerk_interpolator_velocity(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[9];
	local[0]= w;
BLK694:
	ctx->vsp=local; return(local[0]);}

/*:velocity-list*/
static pointer M695minjerk_interpolator_velocity_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[11];
	local[0]= w;
BLK696:
	ctx->vsp=local; return(local[0]);}

/*:acceleration*/
static pointer M697minjerk_interpolator_acceleration(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[10];
	local[0]= w;
BLK698:
	ctx->vsp=local; return(local[0]);}

/*:acceleration-list*/
static pointer M699minjerk_interpolator_acceleration_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[12];
	local[0]= w;
BLK700:
	ctx->vsp=local; return(local[0]);}

/*:reset*/
static pointer M701minjerk_interpolator_reset(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST703:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[85], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY704;
	local[3]= argv[0];
	local[4]= fqv[86];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[1] = w;
KEY704:
	if (n & (1<<1)) goto KEY705;
	local[3]= argv[0];
	local[4]= fqv[87];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[2] = w;
KEY705:
	local[3]= (pointer)get_sym_func(fqv[8]);
	local[4]= argv[0];
	local[5]= *(ovafptr(argv[1],fqv[88]));
	local[6]= fqv[84];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,5,local+3); /*apply*/
	if (local[1]==NIL) goto IF706;
	local[3]= local[1];
	goto IF707;
IF706:
	local[3]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[3]= w;
	local[4]= fqv[89];
	local[5]= loadglobal(fqv[90]);
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,2,local+5); /*instantiate*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[10])(ctx,3,local+3,&ftab[10],fqv[91]); /*make-list*/
	local[3]= w;
IF707:
	argv[0]->c.obj.iv[11] = local[3];
	if (local[2]==NIL) goto IF708;
	local[3]= local[2];
	goto IF709;
IF708:
	local[3]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[3]= w;
	local[4]= fqv[89];
	local[5]= loadglobal(fqv[90]);
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,2,local+5); /*instantiate*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[10])(ctx,3,local+3,&ftab[10],fqv[91]); /*make-list*/
	local[3]= w;
IF709:
	argv[0]->c.obj.iv[12] = local[3];
	w = argv[0]->c.obj.iv[12];
	local[0]= w;
BLK702:
	ctx->vsp=local; return(local[0]);}

/*:interpolation*/
static pointer M710minjerk_interpolator_interpolation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[7];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)NTH(ctx,2,local+0); /*nth*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+2;
	w=(pointer)ADD1(ctx,1,local+1); /*1+*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)NTH(ctx,2,local+1); /*nth*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[7];
	local[3]= argv[0]->c.obj.iv[11];
	ctx->vsp=local+4;
	w=(pointer)NTH(ctx,2,local+2); /*nth*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[11];
	ctx->vsp=local+5;
	w=(pointer)NTH(ctx,2,local+3); /*nth*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[7];
	local[5]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+6;
	w=(pointer)NTH(ctx,2,local+4); /*nth*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+7;
	w=(pointer)NTH(ctx,2,local+5); /*nth*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[7];
	local[7]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+8;
	w=(pointer)NTH(ctx,2,local+6); /*nth*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[7];
	w = makeint((eusinteger_t)0L);
	if ((eusinteger_t)local[7] <= (eusinteger_t)w) goto IF712;
	local[7]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+8;
	w=(pointer)SUB1(ctx,1,local+7); /*1-*/
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+9;
	w=(pointer)NTH(ctx,2,local+7); /*nth*/
	local[7]= w;
	goto IF713;
IF712:
	local[7]= makeint((eusinteger_t)0L);
IF713:
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	local[7]= makeflt(1.0000000000000000000000e+00);
	local[8]= local[6];
	local[9]= local[6];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,3,local+8); /***/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	local[7]= w;
	local[8]= local[1];
	local[9]= (pointer)get_sym_func(fqv[92]);
	local[10]= local[0];
	local[11]= local[6];
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)SCALEVEC(ctx,2,local+11); /*scale*/
	local[11]= w;
	local[12]= local[6];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(pointer)TIMES(ctx,2,local+12); /***/
	local[12]= w;
	local[13]= makeflt(5.0000000000000000000000e-01);
	local[14]= local[4];
	ctx->vsp=local+15;
	w=(pointer)SCALEVEC(ctx,2,local+13); /*scale*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SCALEVEC(ctx,2,local+12); /*scale*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,3,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[11])(ctx,2,local+9,&ftab[11],fqv[93]); /*reduce*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)VMINUS(ctx,2,local+8); /*v-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SCALEVEC(ctx,2,local+7); /*scale*/
	local[7]= w;
	local[8]= makeflt(1.0000000000000000000000e+00);
	local[9]= local[6];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	local[9]= local[3];
	local[10]= local[2];
	local[11]= local[6];
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(pointer)SCALEVEC(ctx,2,local+11); /*scale*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)VPLUS(ctx,2,local+10); /*v+*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)VMINUS(ctx,2,local+9); /*v-*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,2,local+8); /*scale*/
	local[8]= w;
	local[9]= makeflt(1.0000000000000000000000e+00);
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,1,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	local[10]= local[5];
	local[11]= local[4];
	ctx->vsp=local+12;
	w=(pointer)VMINUS(ctx,2,local+10); /*v-*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SCALEVEC(ctx,2,local+9); /*scale*/
	local[9]= w;
	local[10]= local[0];
	local[11]= local[2];
	local[12]= makeflt(5.0000000000000000000000e-01);
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)SCALEVEC(ctx,2,local+12); /*scale*/
	local[12]= w;
	local[13]= makeint((eusinteger_t)10L);
	local[14]= local[7];
	ctx->vsp=local+15;
	w=(pointer)SCALEVEC(ctx,2,local+13); /*scale*/
	local[13]= w;
	local[14]= makeint((eusinteger_t)4L);
	local[15]= local[8];
	ctx->vsp=local+16;
	w=(pointer)SCALEVEC(ctx,2,local+14); /*scale*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)VMINUS(ctx,2,local+13); /*v-*/
	local[13]= w;
	local[14]= makeflt(5.0000000000000000000000e-01);
	local[15]= local[9];
	ctx->vsp=local+16;
	w=(pointer)SCALEVEC(ctx,2,local+14); /*scale*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)VPLUS(ctx,2,local+13); /*v+*/
	local[13]= w;
	local[14]= makeflt(1.0000000000000000000000e+00);
	local[15]= local[6];
	ctx->vsp=local+16;
	w=(pointer)QUOTIENT(ctx,2,local+14); /*/*/
	local[14]= w;
	local[15]= makeint((eusinteger_t)-15L);
	local[16]= local[7];
	ctx->vsp=local+17;
	w=(pointer)SCALEVEC(ctx,2,local+15); /*scale*/
	local[15]= w;
	local[16]= makeint((eusinteger_t)7L);
	local[17]= local[8];
	ctx->vsp=local+18;
	w=(pointer)SCALEVEC(ctx,2,local+16); /*scale*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)VPLUS(ctx,2,local+15); /*v+*/
	local[15]= w;
	local[16]= local[9];
	ctx->vsp=local+17;
	w=(pointer)VMINUS(ctx,2,local+15); /*v-*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)SCALEVEC(ctx,2,local+14); /*scale*/
	local[14]= w;
	local[15]= makeflt(1.0000000000000000000000e+00);
	local[16]= local[6];
	local[17]= local[6];
	ctx->vsp=local+18;
	w=(pointer)QUOTIENT(ctx,3,local+15); /*/*/
	local[15]= w;
	local[16]= makeint((eusinteger_t)6L);
	local[17]= local[7];
	ctx->vsp=local+18;
	w=(pointer)SCALEVEC(ctx,2,local+16); /*scale*/
	local[16]= w;
	local[17]= makeint((eusinteger_t)-3L);
	local[18]= local[8];
	ctx->vsp=local+19;
	w=(pointer)SCALEVEC(ctx,2,local+17); /*scale*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)VPLUS(ctx,2,local+16); /*v+*/
	local[16]= w;
	local[17]= makeflt(5.0000000000000000000000e-01);
	local[18]= local[9];
	ctx->vsp=local+19;
	w=(pointer)SCALEVEC(ctx,2,local+17); /*scale*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)VPLUS(ctx,2,local+16); /*v+*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)SCALEVEC(ctx,2,local+15); /*scale*/
	local[15]= w;
	local[16]= (pointer)get_sym_func(fqv[92]);
	local[17]= local[10];
	local[18]= argv[0]->c.obj.iv[6];
	local[19]= makeint((eusinteger_t)1L);
	ctx->vsp=local+20;
	w=(*ftab[12])(ctx,2,local+18,&ftab[12],fqv[94]); /*expt*/
	local[18]= w;
	local[19]= local[11];
	ctx->vsp=local+20;
	w=(pointer)SCALEVEC(ctx,2,local+18); /*scale*/
	local[18]= w;
	local[19]= argv[0]->c.obj.iv[6];
	local[20]= makeint((eusinteger_t)2L);
	ctx->vsp=local+21;
	w=(*ftab[12])(ctx,2,local+19,&ftab[12],fqv[94]); /*expt*/
	local[19]= w;
	local[20]= local[12];
	ctx->vsp=local+21;
	w=(pointer)SCALEVEC(ctx,2,local+19); /*scale*/
	local[19]= w;
	local[20]= argv[0]->c.obj.iv[6];
	local[21]= makeint((eusinteger_t)3L);
	ctx->vsp=local+22;
	w=(*ftab[12])(ctx,2,local+20,&ftab[12],fqv[94]); /*expt*/
	local[20]= w;
	local[21]= local[13];
	ctx->vsp=local+22;
	w=(pointer)SCALEVEC(ctx,2,local+20); /*scale*/
	local[20]= w;
	local[21]= argv[0]->c.obj.iv[6];
	local[22]= makeint((eusinteger_t)4L);
	ctx->vsp=local+23;
	w=(*ftab[12])(ctx,2,local+21,&ftab[12],fqv[94]); /*expt*/
	local[21]= w;
	local[22]= local[14];
	ctx->vsp=local+23;
	w=(pointer)SCALEVEC(ctx,2,local+21); /*scale*/
	local[21]= w;
	local[22]= argv[0]->c.obj.iv[6];
	local[23]= makeint((eusinteger_t)5L);
	ctx->vsp=local+24;
	w=(*ftab[12])(ctx,2,local+22,&ftab[12],fqv[94]); /*expt*/
	local[22]= w;
	local[23]= local[15];
	ctx->vsp=local+24;
	w=(pointer)SCALEVEC(ctx,2,local+22); /*scale*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)LIST(ctx,6,local+17); /*list*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(*ftab[11])(ctx,2,local+16,&ftab[11],fqv[93]); /*reduce*/
	argv[0]->c.obj.iv[3] = w;
	local[16]= (pointer)get_sym_func(fqv[92]);
	local[17]= local[11];
	local[18]= argv[0]->c.obj.iv[6];
	local[19]= makeint((eusinteger_t)1L);
	ctx->vsp=local+20;
	w=(*ftab[12])(ctx,2,local+18,&ftab[12],fqv[94]); /*expt*/
	local[18]= w;
	local[19]= local[12];
	ctx->vsp=local+20;
	w=(pointer)SCALEVEC(ctx,2,local+18); /*scale*/
	local[18]= w;
	local[19]= argv[0]->c.obj.iv[6];
	local[20]= makeint((eusinteger_t)2L);
	ctx->vsp=local+21;
	w=(*ftab[12])(ctx,2,local+19,&ftab[12],fqv[94]); /*expt*/
	local[19]= w;
	local[20]= local[13];
	ctx->vsp=local+21;
	w=(pointer)SCALEVEC(ctx,2,local+19); /*scale*/
	local[19]= w;
	local[20]= argv[0]->c.obj.iv[6];
	local[21]= makeint((eusinteger_t)3L);
	ctx->vsp=local+22;
	w=(*ftab[12])(ctx,2,local+20,&ftab[12],fqv[94]); /*expt*/
	local[20]= w;
	local[21]= local[14];
	ctx->vsp=local+22;
	w=(pointer)SCALEVEC(ctx,2,local+20); /*scale*/
	local[20]= w;
	local[21]= argv[0]->c.obj.iv[6];
	local[22]= makeint((eusinteger_t)4L);
	ctx->vsp=local+23;
	w=(*ftab[12])(ctx,2,local+21,&ftab[12],fqv[94]); /*expt*/
	local[21]= w;
	local[22]= local[15];
	ctx->vsp=local+23;
	w=(pointer)SCALEVEC(ctx,2,local+21); /*scale*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)LIST(ctx,5,local+17); /*list*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(*ftab[11])(ctx,2,local+16,&ftab[11],fqv[93]); /*reduce*/
	argv[0]->c.obj.iv[9] = w;
	local[16]= (pointer)get_sym_func(fqv[92]);
	local[17]= local[12];
	local[18]= argv[0]->c.obj.iv[6];
	local[19]= makeint((eusinteger_t)1L);
	ctx->vsp=local+20;
	w=(*ftab[12])(ctx,2,local+18,&ftab[12],fqv[94]); /*expt*/
	local[18]= w;
	local[19]= local[13];
	ctx->vsp=local+20;
	w=(pointer)SCALEVEC(ctx,2,local+18); /*scale*/
	local[18]= w;
	local[19]= argv[0]->c.obj.iv[6];
	local[20]= makeint((eusinteger_t)2L);
	ctx->vsp=local+21;
	w=(*ftab[12])(ctx,2,local+19,&ftab[12],fqv[94]); /*expt*/
	local[19]= w;
	local[20]= local[14];
	ctx->vsp=local+21;
	w=(pointer)SCALEVEC(ctx,2,local+19); /*scale*/
	local[19]= w;
	local[20]= argv[0]->c.obj.iv[6];
	local[21]= makeint((eusinteger_t)3L);
	ctx->vsp=local+22;
	w=(*ftab[12])(ctx,2,local+20,&ftab[12],fqv[94]); /*expt*/
	local[20]= w;
	local[21]= local[15];
	ctx->vsp=local+22;
	w=(pointer)SCALEVEC(ctx,2,local+20); /*scale*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)LIST(ctx,4,local+17); /*list*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(*ftab[11])(ctx,2,local+16,&ftab[11],fqv[93]); /*reduce*/
	argv[0]->c.obj.iv[10] = w;
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK711:
	ctx->vsp=local; return(local[0]);}

/*his2rgb*/
static pointer F495his2rgb(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT718;}
	local[0]= makeflt(1.0000000000000000000000e+00);
ENT718:
	if (n>=3) { local[1]=(argv[2]); goto ENT717;}
	local[1]= makeflt(1.0000000000000000000000e+00);
ENT717:
	if (n>=4) { local[2]=(argv[3]); goto ENT716;}
	local[2]= NIL;
ENT716:
ENT715:
	if (n>4) maerror();
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= local[1];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F496hvs2rgb(ctx,4,local+3); /*hvs2rgb*/
	local[0]= w;
BLK714:
	ctx->vsp=local; return(local[0]);}

/*hvs2rgb*/
static pointer F496hvs2rgb(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT723;}
	local[0]= makeflt(1.0000000000000000000000e+00);
ENT723:
	if (n>=3) { local[1]=(argv[2]); goto ENT722;}
	local[1]= makeflt(1.0000000000000000000000e+00);
ENT722:
	if (n>=4) { local[2]=(argv[3]); goto ENT721;}
	local[2]= NIL;
ENT721:
ENT720:
	if (n>4) maerror();
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LISTP(ctx,1,local+3); /*listp*/
	if (w!=NIL) goto OR726;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)VECTORP(ctx,1,local+3); /*vectorp*/
	if (w!=NIL) goto OR726;
	goto IF724;
OR726:
	local[2] = local[0];
	local[3]= argv[0];
	local[4]= makeint((eusinteger_t)2L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[1] = w;
	local[3]= argv[0];
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[0] = w;
	local[3]= argv[0];
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	argv[0] = w;
	local[3]= argv[0];
	goto IF725;
IF724:
	local[3]= NIL;
IF725:
	local[3]= argv[0];
	local[4]= makeint((eusinteger_t)360L);
	ctx->vsp=local+5;
	w=(pointer)GREQP(ctx,2,local+3); /*>=*/
	if (w==NIL) goto IF727;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)ROUND(ctx,1,local+3); /*round*/
	local[3]= w;
	local[4]= makeint((eusinteger_t)360L);
	ctx->vsp=local+5;
	w=(pointer)MOD(ctx,2,local+3); /*mod*/
	argv[0] = w;
	local[3]= argv[0];
	goto IF728;
IF727:
	local[3]= NIL;
IF728:
	local[3]= argv[0];
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)LESSP(ctx,2,local+3); /*<*/
	if (w==NIL) goto IF729;
	local[3]= makeint((eusinteger_t)360L);
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,1,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ROUND(ctx,1,local+4); /*round*/
	local[4]= w;
	local[5]= makeint((eusinteger_t)360L);
	ctx->vsp=local+6;
	w=(pointer)MOD(ctx,2,local+4); /*mod*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	argv[0] = w;
	local[3]= argv[0];
	goto IF730;
IF729:
	local[3]= NIL;
IF730:
	local[3]= makeint((eusinteger_t)255L);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[1] = w;
	local[3]= makeint((eusinteger_t)255L);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[0] = w;
	local[3]= argv[0];
	local[4]= makeflt(6.0000000000000000000000e+01);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)FLOOR(ctx,1,local+3); /*floor*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= makeflt(6.0000000000000000000000e+01);
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	local[5]= local[0];
	local[6]= makeflt(1.0000000000000000000000e+00);
	local[7]= local[1];
	local[8]= makeflt(2.5500000000000000000000e+02);
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	local[6]= local[0];
	local[7]= makeflt(1.0000000000000000000000e+00);
	local[8]= local[4];
	local[9]= local[1];
	local[10]= makeflt(2.5500000000000000000000e+02);
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,2,local+7); /*-*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	local[7]= local[0];
	local[8]= makeflt(1.0000000000000000000000e+00);
	local[9]= makeint((eusinteger_t)1L);
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,2,local+9); /*-*/
	local[9]= w;
	local[10]= local[1];
	local[11]= makeflt(2.5500000000000000000000e+02);
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= local[3];
	local[12]= local[11];
	w = fqv[95];
	if (memq(local[12],w)==NIL) goto IF732;
	local[8] = local[0];
	local[9] = local[7];
	local[10] = local[5];
	local[12]= local[10];
	goto IF733;
IF732:
	local[12]= local[11];
	if (fqv[96]!=local[12]) goto IF734;
	local[8] = local[6];
	local[9] = local[0];
	local[10] = local[5];
	local[12]= local[10];
	goto IF735;
IF734:
	local[12]= local[11];
	if (fqv[97]!=local[12]) goto IF736;
	local[8] = local[5];
	local[9] = local[0];
	local[10] = local[7];
	local[12]= local[10];
	goto IF737;
IF736:
	local[12]= local[11];
	if (fqv[98]!=local[12]) goto IF738;
	local[8] = local[5];
	local[9] = local[6];
	local[10] = local[0];
	local[12]= local[10];
	goto IF739;
IF738:
	local[12]= local[11];
	if (fqv[99]!=local[12]) goto IF740;
	local[8] = local[7];
	local[9] = local[5];
	local[10] = local[0];
	local[12]= local[10];
	goto IF741;
IF740:
	local[12]= local[11];
	if (fqv[100]!=local[12]) goto IF742;
	local[8] = local[0];
	local[9] = local[5];
	local[10] = local[6];
	local[12]= local[10];
	goto IF743;
IF742:
	if (T==NIL) goto IF744;
	local[12]= fqv[101];
	ctx->vsp=local+13;
	w=(*ftab[0])(ctx,1,local+12,&ftab[0],fqv[3]); /*warn*/
	local[12]= w;
	goto IF745;
IF744:
	local[12]= NIL;
IF745:
IF743:
IF741:
IF739:
IF737:
IF735:
IF733:
	w = local[12];
	if (local[2]==NIL) goto CON747;
	local[11]= local[2];
	local[12]= makeint((eusinteger_t)0L);
	local[13]= local[8];
	ctx->vsp=local+14;
	w=(pointer)SETELT(ctx,3,local+11); /*setelt*/
	local[11]= local[2];
	local[12]= makeint((eusinteger_t)1L);
	local[13]= local[9];
	ctx->vsp=local+14;
	w=(pointer)SETELT(ctx,3,local+11); /*setelt*/
	local[11]= local[2];
	local[12]= makeint((eusinteger_t)2L);
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(pointer)SETELT(ctx,3,local+11); /*setelt*/
	local[11]= local[2];
	goto CON746;
CON747:
	local[11]= local[8];
	local[12]= local[9];
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,3,local+11); /*list*/
	local[11]= w;
	goto CON746;
CON748:
	local[11]= NIL;
CON746:
	w = local[11];
	local[0]= w;
BLK719:
	ctx->vsp=local; return(local[0]);}

/*rgb2his*/
static pointer F497rgb2his(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT753;}
	local[0]= NIL;
ENT753:
	if (n>=3) { local[1]=(argv[2]); goto ENT752;}
	local[1]= NIL;
ENT752:
	if (n>=4) { local[2]=(argv[3]); goto ENT751;}
	local[2]= NIL;
ENT751:
ENT750:
	if (n>4) maerror();
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= local[1];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F498rgb2hvs(ctx,4,local+3); /*rgb2hvs*/
	local[0]= w;
BLK749:
	ctx->vsp=local; return(local[0]);}

/*rgb2hvs*/
static pointer F498rgb2hvs(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT758;}
	local[0]= NIL;
ENT758:
	if (n>=3) { local[1]=(argv[2]); goto ENT757;}
	local[1]= NIL;
ENT757:
	if (n>=4) { local[2]=(argv[3]); goto ENT756;}
	local[2]= NIL;
ENT756:
ENT755:
	if (n>4) maerror();
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LISTP(ctx,1,local+3); /*listp*/
	if (w!=NIL) goto OR761;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)VECTORP(ctx,1,local+3); /*vectorp*/
	if (w!=NIL) goto OR761;
	goto IF759;
OR761:
	local[2] = local[0];
	local[3]= argv[0];
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[0] = w;
	local[3]= argv[0];
	local[4]= makeint((eusinteger_t)2L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[1] = w;
	local[3]= argv[0];
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	argv[0] = w;
	local[3]= argv[0];
	goto IF760;
IF759:
	local[3]= NIL;
IF760:
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)MAX(ctx,3,local+3); /*max*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= local[0];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)MIN(ctx,3,local+4); /*min*/
	local[4]= w;
	local[5]= local[3];
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)EUSFLOAT(ctx,1,local+5); /*float*/
	local[5]= w;
	local[6]= local[3];
	local[7]= argv[0];
	local[8]= makeflt(6.0000000000000000000000e+01);
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	local[7]= local[3];
	local[8]= local[0];
	local[9]= makeflt(6.0000000000000000000000e+01);
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,2,local+7); /*-*/
	local[7]= w;
	local[8]= local[3];
	local[9]= local[1];
	local[10]= makeflt(6.0000000000000000000000e+01);
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	local[9]= local[3];
	local[10]= makeflt(2.5500000000000000000000e+02);
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	local[10]= local[5];
	local[11]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+12;
	w=(pointer)NUMEQUAL(ctx,2,local+10); /*=*/
	if (w==NIL) goto IF762;
	local[10]= makeint((eusinteger_t)0L);
	goto IF763;
IF762:
	local[10]= makeflt(2.5500000000000000000000e+02);
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[10]= w;
IF763:
	local[11]= local[10];
	local[12]= makeint((eusinteger_t)0L);
	ctx->vsp=local+13;
	w=(pointer)NUMEQUAL(ctx,2,local+11); /*=*/
	if (w==NIL) goto IF764;
	local[11]= makeint((eusinteger_t)0L);
	goto IF765;
IF764:
	local[11]= argv[0];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)NUMEQUAL(ctx,2,local+11); /*=*/
	if (w==NIL) goto CON767;
	local[11]= local[8];
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(pointer)MINUS(ctx,2,local+11); /*-*/
	local[11]= w;
	goto CON766;
CON767:
	local[11]= local[0];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)NUMEQUAL(ctx,2,local+11); /*=*/
	if (w==NIL) goto CON768;
	local[11]= makeint((eusinteger_t)120L);
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[11]= w;
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(pointer)MINUS(ctx,2,local+11); /*-*/
	local[11]= w;
	goto CON766;
CON768:
	local[11]= makeint((eusinteger_t)240L);
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[11]= w;
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)MINUS(ctx,2,local+11); /*-*/
	local[11]= w;
	goto CON766;
CON769:
	local[11]= NIL;
CON766:
IF765:
	local[12]= local[11];
	local[13]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+14;
	w=(pointer)LESSP(ctx,2,local+12); /*<*/
	if (w==NIL) goto IF770;
	local[12]= local[11];
	local[13]= makeint((eusinteger_t)360L);
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,2,local+12); /*+*/
	local[12]= w;
	goto IF771;
IF770:
	local[12]= local[11];
IF771:
	local[13]= local[10];
	local[14]= makeflt(2.5500000000000000000000e+02);
	ctx->vsp=local+15;
	w=(pointer)QUOTIENT(ctx,2,local+13); /*/*/
	local[10] = w;
	if (local[2]==NIL) goto CON773;
	local[13]= local[2];
	local[14]= makeint((eusinteger_t)0L);
	local[15]= local[12];
	ctx->vsp=local+16;
	w=(pointer)SETELT(ctx,3,local+13); /*setelt*/
	local[13]= local[2];
	local[14]= makeint((eusinteger_t)1L);
	local[15]= local[9];
	ctx->vsp=local+16;
	w=(pointer)SETELT(ctx,3,local+13); /*setelt*/
	local[13]= local[2];
	local[14]= makeint((eusinteger_t)2L);
	local[15]= local[10];
	ctx->vsp=local+16;
	w=(pointer)SETELT(ctx,3,local+13); /*setelt*/
	local[13]= local[2];
	goto CON772;
CON773:
	local[13]= local[12];
	local[14]= local[9];
	local[15]= local[10];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,3,local+13); /*list*/
	local[13]= w;
	goto CON772;
CON774:
	local[13]= NIL;
CON772:
	w = local[13];
	local[0]= w;
BLK754:
	ctx->vsp=local; return(local[0]);}

/*color-category10*/
static pointer F499color_category10(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)10L);
	ctx->vsp=local+2;
	w=(pointer)MOD(ctx,2,local+0); /*mod*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)100L);
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= makeflt(1.0000000000000000000000e+00);
	local[2]= makeflt(7.9999999999999982236432e-01);
	ctx->vsp=local+3;
	w=(pointer)F495his2rgb(ctx,3,local+0); /*his2rgb*/
	local[0]= w;
BLK775:
	ctx->vsp=local; return(local[0]);}

/*color-category20*/
static pointer F500color_category20(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)20L);
	ctx->vsp=local+2;
	w=(pointer)MOD(ctx,2,local+0); /*mod*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)100L);
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= makeflt(1.0000000000000000000000e+00);
	local[2]= makeflt(7.9999999999999982236432e-01);
	ctx->vsp=local+3;
	w=(pointer)F495his2rgb(ctx,3,local+0); /*his2rgb*/
	local[0]= w;
BLK776:
	ctx->vsp=local; return(local[0]);}

/*bench*/
static pointer F777(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST779:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	ctx->vsp=local+1;
	w=(pointer)GENSYM(ctx,0,local+1); /*gensym*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,0,local+2); /*gensym*/
	local[2]= w;
	local[3]= fqv[18];
	local[4]= local[1];
	local[5]= fqv[27];
	local[6]= fqv[28];
	local[7]= fqv[29];
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
	local[5]= local[2];
	local[6]= fqv[102];
	w = local[0];
	if (memq(local[6],w)==NIL) goto IF780;
	local[6]= fqv[102];
	w = local[0];
	w=memq(local[6],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	goto IF781;
IF780:
	local[6]= fqv[103];
IF781:
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[0];
	local[6]= local[1];
	local[7]= fqv[32];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[9];
	local[7]= fqv[104];
	local[8]= local[0];
	local[9]= NIL;
	ctx->vsp=local+10;
	w=(pointer)APPEND(ctx,2,local+8); /*append*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[105];
	local[9]= fqv[26];
	local[10]= fqv[106];
	local[11]= local[2];
	local[12]= fqv[0];
	local[13]= local[1];
	local[14]= fqv[31];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
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
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	local[0]= w;
BLK778:
	ctx->vsp=local; return(local[0]);}

/*bench2*/
static pointer F782(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST784:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	ctx->vsp=local+1;
	w=(pointer)GENSYM(ctx,0,local+1); /*gensym*/
	local[1]= w;
	local[2]= fqv[18];
	local[3]= local[1];
	local[4]= fqv[27];
	local[5]= fqv[28];
	local[6]= fqv[29];
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
	local[3]= w;
	local[4]= fqv[0];
	local[5]= local[1];
	local[6]= fqv[32];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[104];
	local[6]= local[0];
	local[7]= fqv[0];
	local[8]= local[1];
	local[9]= fqv[31];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)APPEND(ctx,2,local+6); /*append*/
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
	local[0]= w;
BLK783:
	ctx->vsp=local; return(local[0]);}

/*null-output*/
static pointer F785(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST787:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= fqv[107];
	local[2]= fqv[108];
	local[3]= local[0];
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)APPEND(ctx,2,local+3); /*append*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK786:
	ctx->vsp=local; return(local[0]);}

/*with-all-output->file*/
static pointer F788(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST790:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+1;
	w=(pointer)GENSYM(ctx,0,local+1); /*gensym*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,0,local+2); /*gensym*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)GENSYM(ctx,0,local+3); /*gensym*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)GENSYM(ctx,0,local+4); /*gensym*/
	local[4]= w;
	local[5]= fqv[104];
	local[6]= fqv[18];
	local[7]= local[1];
	local[8]= fqv[109];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= local[2];
	local[9]= fqv[60];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= local[4];
	local[10]= fqv[24];
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
	local[8]= fqv[110];
	local[9]= fqv[111];
	local[10]= local[3];
	local[11]= argv[0];
	local[12]= fqv[112];
	local[13]= fqv[113];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[114];
	local[12]= fqv[109];
	local[13]= local[3];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[114];
	local[13]= fqv[60];
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[114];
	local[14]= local[4];
	local[15]= fqv[104];
	local[16]= local[0];
	local[17]= NIL;
	ctx->vsp=local+18;
	w=(pointer)APPEND(ctx,2,local+16); /*append*/
	ctx->vsp=local+16;
	local[15]= cons(ctx,local[15],w);
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
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
	local[10]= fqv[104];
	local[11]= fqv[114];
	local[12]= fqv[109];
	local[13]= local[1];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[114];
	local[13]= fqv[60];
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
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
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	local[0]= w;
BLK789:
	ctx->vsp=local; return(local[0]);}

/*read-char-case*/
static pointer F791(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST793:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+1;
	w=(pointer)GENSYM(ctx,0,local+1); /*gensym*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,0,local+2); /*gensym*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)GENSYM(ctx,0,local+3); /*gensym*/
	local[3]= w;
	local[4]= fqv[104];
	local[5]= fqv[18];
	local[6]= local[3];
	local[7]= fqv[115];
	local[8]= local[2];
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
	local[6]= w;
	local[7]= fqv[10];
	local[8]= fqv[116];
	local[9]= local[3];
	local[10]= fqv[115];
	local[11]= local[2];
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
	local[9]= fqv[105];
	local[10]= fqv[26];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[117];
	local[11]= fqv[109];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[114];
	local[12]= local[3];
	local[13]= fqv[18];
	local[14]= local[1];
	local[15]= fqv[118];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	local[14]= w;
	local[15]= fqv[119];
	local[16]= local[1];
	local[17]= local[0];
	local[18]= fqv[26];
	local[19]= fqv[115];
	local[20]= local[2];
	ctx->vsp=local+21;
	w=(pointer)LIST(ctx,1,local+20); /*list*/
	ctx->vsp=local+20;
	local[19]= cons(ctx,local[19],w);
	ctx->vsp=local+20;
	w=(pointer)LIST(ctx,1,local+19); /*list*/
	ctx->vsp=local+19;
	local[18]= cons(ctx,local[18],w);
	ctx->vsp=local+19;
	w=(pointer)LIST(ctx,1,local+18); /*list*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)APPEND(ctx,2,local+17); /*append*/
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
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
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
	local[7]= cons(ctx,local[7],w);
	local[8]= local[3];
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
	local[0]= w;
BLK792:
	ctx->vsp=local; return(local[0]);}

/*termios-c_iflag*/
static pointer F501termios_c_iflag(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)0L);
	local[2]= fqv[62];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK794:
	ctx->vsp=local; return(local[0]);}

/*set-termios-c_iflag*/
static pointer F502set_termios_c_iflag(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint((eusinteger_t)0L);
	local[3]= fqv[62];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK795:
	ctx->vsp=local; return(local[0]);}

/*termios-c_oflag*/
static pointer F503termios_c_oflag(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)4L);
	local[2]= fqv[62];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK796:
	ctx->vsp=local; return(local[0]);}

/*set-termios-c_oflag*/
static pointer F504set_termios_c_oflag(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint((eusinteger_t)4L);
	local[3]= fqv[62];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK797:
	ctx->vsp=local; return(local[0]);}

/*termios-c_cflag*/
static pointer F505termios_c_cflag(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)8L);
	local[2]= fqv[62];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK798:
	ctx->vsp=local; return(local[0]);}

/*set-termios-c_cflag*/
static pointer F506set_termios_c_cflag(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint((eusinteger_t)8L);
	local[3]= fqv[62];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK799:
	ctx->vsp=local; return(local[0]);}

/*termios-c_lflag*/
static pointer F507termios_c_lflag(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)12L);
	local[2]= fqv[62];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK800:
	ctx->vsp=local; return(local[0]);}

/*set-termios-c_lflag*/
static pointer F508set_termios_c_lflag(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint((eusinteger_t)12L);
	local[3]= fqv[62];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK801:
	ctx->vsp=local; return(local[0]);}

/*termios-c_line*/
static pointer F509termios_c_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)16L);
	local[2]= fqv[120];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK802:
	ctx->vsp=local; return(local[0]);}

/*set-termios-c_line*/
static pointer F510set_termios_c_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint((eusinteger_t)16L);
	local[3]= fqv[120];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK803:
	ctx->vsp=local; return(local[0]);}

/*termios-c_cc*/
static pointer F511termios_c_cc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT806;}
	local[0]= NIL;
ENT806:
ENT805:
	if (n>2) maerror();
	if (local[0]==NIL) goto IF807;
	local[1]= argv[0];
	local[2]= makeint((eusinteger_t)17L);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= fqv[121];
	ctx->vsp=local+4;
	w=(pointer)PEEK(ctx,3,local+1); /*system:peek*/
	local[1]= w;
	goto IF808;
IF807:
	local[1]= argv[0];
	local[2]= makeint((eusinteger_t)17L);
	local[3]= makeint((eusinteger_t)17L);
	w = makeint((eusinteger_t)19L);
#if sun4 || vax || mips || alpha || Linux
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[3]= (pointer)((eusinteger_t)local[3] + (eusinteger_t)w);
	ctx->vsp=local+4;
	w=(pointer)SUBSEQ(ctx,3,local+1); /*subseq*/
	local[1]= w;
IF808:
	w = local[1];
	local[0]= w;
BLK804:
	ctx->vsp=local; return(local[0]);}

/*set-termios-c_cc*/
static pointer F512set_termios_c_cc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST810:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	if (local[0]==NIL) goto IF811;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= makeint((eusinteger_t)17L);
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= fqv[121];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,3,local+1); /*system:poke*/
	local[1]= w;
	goto IF812;
IF811:
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= fqv[122];
	local[4]= makeint((eusinteger_t)17L);
	local[5]= fqv[123];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[13])(ctx,6,local+1,&ftab[13],fqv[124]); /*replace*/
	local[1]= w;
IF812:
	w = local[1];
	local[0]= w;
BLK809:
	ctx->vsp=local; return(local[0]);}

/*termios-c_ispeed*/
static pointer F513termios_c_ispeed(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)36L);
	local[2]= fqv[62];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK813:
	ctx->vsp=local; return(local[0]);}

/*set-termios-c_ispeed*/
static pointer F514set_termios_c_ispeed(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint((eusinteger_t)36L);
	local[3]= fqv[62];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK814:
	ctx->vsp=local; return(local[0]);}

/*termios-c_ospeed*/
static pointer F515termios_c_ospeed(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)40L);
	local[2]= fqv[62];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK815:
	ctx->vsp=local; return(local[0]);}

/*set-termios-c_ospeed*/
static pointer F516set_termios_c_ospeed(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint((eusinteger_t)40L);
	local[3]= fqv[62];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK816:
	ctx->vsp=local; return(local[0]);}

/*kbhit*/
static pointer F517kbhit(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= makeint((eusinteger_t)0L);
	ctx->vsp=local+1;
	w=(*ftab[14])(ctx,1,local+0,&ftab[14],fqv[125]); /*unix:tcgetattr*/
	local[0]= w;
	local[1]= fqv[126];
	local[2]= NIL;
	local[3]= NIL;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[15])(ctx,1,local+4,&ftab[15],fqv[127]); /*copy-list*/
	local[2] = w;
	local[4]= local[2];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)F507termios_c_lflag(ctx,1,local+5); /*termios-c_lflag*/
	local[5]= w;
	local[6]= makeint((eusinteger_t)2L);
	ctx->vsp=local+7;
	w=(pointer)LOGNOT(ctx,1,local+6); /*lognot*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LOGAND(ctx,2,local+5); /*logand*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)F508set_termios_c_lflag(ctx,2,local+4); /*set-termios-c_lflag*/
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)0L);
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(*ftab[16])(ctx,3,local+4,&ftab[16],fqv[128]); /*unix:tcsetattr*/
	local[4]= makeint((eusinteger_t)1L);
	local[5]= makeflt(1.0000000000000000208167e-03);
	ctx->vsp=local+6;
	w=(pointer)SELECT_READ(ctx,2,local+4); /*unix:select-read-fd*/
	local[4]= w;
	local[5]= makeint((eusinteger_t)1L);
	ctx->vsp=local+6;
	w=(pointer)NUMEQUAL(ctx,2,local+4); /*=*/
	if (w==NIL) goto IF818;
	local[4]= makeint((eusinteger_t)0L);
	local[5]= local[1];
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(pointer)UNIXREAD(ctx,3,local+4); /*unix:uread*/
	local[4]= local[1];
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[3] = w;
	local[4]= local[3];
	goto IF819;
IF818:
	local[4]= NIL;
IF819:
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)0L);
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[16])(ctx,3,local+4,&ftab[16],fqv[128]); /*unix:tcsetattr*/
	w = local[3];
	local[0]= w;
BLK817:
	ctx->vsp=local; return(local[0]);}

/*piped-fork-returns-list*/
static pointer F518piped_fork_returns_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT822;}
	local[0]= NIL;
ENT822:
ENT821:
	if (n>2) maerror();
	local[1]= (pointer)get_sym_func(fqv[129]);
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[1]= w;
	ctx->vsp=local+2;
	w = makeclosure(codevec,quotevec,UWP823,env,argv,local);
	local[2]=(pointer)(ctx->protfp); local[3]=w;
	ctx->protfp=(struct protectframe *)(local+2);
	local[4]= NIL;
	local[5]= NIL;
WHL824:
	local[6]= local[1];
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)READLINE(ctx,2,local+6); /*read-line*/
	local[5] = w;
	if (local[5]==NIL) goto WHX825;
	local[6]= local[5];
	w = local[4];
	ctx->vsp=local+7;
	local[4] = cons(ctx,local[6],w);
	goto WHL824;
WHX825:
	local[6]= NIL;
BLK826:
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)REVERSE(ctx,1,local+6); /*reverse*/
	ctx->vsp=local+4;
	UWP823(ctx,0,local+4,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK820:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP823(ctx,n,argv,env)
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

/*make-robot-model-from-name*/
static pointer F519make_robot_model_from_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST828:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,1,local+1,&ftab[17],fqv[130]); /*string-downcase*/
	local[1]= w;
	local[2]= loadglobal(fqv[131]);
	local[3]= fqv[132];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[18])(ctx,1,local+2,&ftab[18],fqv[133]); /*flatten*/
	local[2]= w;
	local[3]= NIL;
	local[4]= local[2];
WHL830:
	if (local[4]==NIL) goto WHX831;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3];
	local[6]= fqv[134];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[17])(ctx,1,local+5,&ftab[17],fqv[130]); /*string-downcase*/
	local[5]= w;
	local[6]= local[5];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[19])(ctx,2,local+6,&ftab[19],fqv[135]); /*string=*/
	if (w!=NIL) goto OR836;
	local[6]= NIL;
	local[7]= fqv[136];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(*ftab[19])(ctx,2,local+6,&ftab[19],fqv[135]); /*string=*/
	if (w!=NIL) goto OR836;
	goto IF834;
OR836:
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,1,local+6); /*instantiate*/
	local[6]= w;
	local[7]= (pointer)get_sym_func(fqv[0]);
	local[8]= local[6];
	local[9]= fqv[29];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)APPLY(ctx,4,local+7); /*apply*/
	w = local[6];
	ctx->vsp=local+6;
	local[0]=w;
	goto BLK827;
	goto IF835;
IF834:
	local[6]= NIL;
IF835:
	w = local[6];
	goto WHL830;
WHX831:
	local[5]= NIL;
BLK832:
	w = NIL;
	w = NIL;
	local[0]= w;
BLK827:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___irtutil(ctx,n,argv,env)
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
	local[0]= fqv[137];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF838;
	local[0]= fqv[138];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[139],w);
	goto IF839;
IF838:
	local[0]= fqv[140];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF839:
	local[0]= fqv[141];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[142],module,F485forward_message_to,fqv[143]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[144],module,F486forward_message_to_all,fqv[145]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[146],module,F534,fqv[147]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[25],module,F537,fqv[148]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[149],module,F540,fqv[150]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[151],module,F543,fqv[152]);
	local[0]= fqv[28];
	local[1]= fqv[153];
	local[2]= fqv[28];
	local[3]= fqv[154];
	local[4]= loadglobal(fqv[155]);
	local[5]= fqv[156];
	local[6]= fqv[157];
	local[7]= fqv[158];
	local[8]= NIL;
	local[9]= fqv[61];
	local[10]= NIL;
	local[11]= fqv[159];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[160];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[20])(ctx,13,local+2,&ftab[20],fqv[161]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M546mtimer_init,fqv[29],fqv[28],fqv[162]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M548mtimer_start,fqv[32],fqv[28],fqv[163]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M550mtimer_stop,fqv[31],fqv[28],fqv[164]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[165],module,F487permutation,fqv[166]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[167],module,F488combination,fqv[168]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[169],module,F489mapjoin,fqv[170]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[171],module,F490find_extreams,fqv[172]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[173],module,F491need_thread,fqv[174]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[175],module,F492eus_server,fqv[176]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[177],module,F493connect_server_until_success,fqv[178]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[179],module,F494format_array,fqv[180]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[181],module,F646,fqv[182]);
	local[0]= fqv[183];
	local[1]= fqv[153];
	local[2]= fqv[183];
	local[3]= fqv[154];
	local[4]= loadglobal(fqv[184]);
	local[5]= fqv[156];
	local[6]= fqv[185];
	local[7]= fqv[158];
	local[8]= NIL;
	local[9]= fqv[61];
	local[10]= NIL;
	local[11]= fqv[159];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[160];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[20])(ctx,13,local+2,&ftab[20],fqv[161]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M650interpolator_init,fqv[29],fqv[183],fqv[186]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M652interpolator_reset,fqv[84],fqv[183],fqv[187]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M659interpolator_position_list,fqv[78],fqv[183],fqv[188]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M661interpolator_position,fqv[189],fqv[183],fqv[190]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M663interpolator_time_list,fqv[79],fqv[183],fqv[191]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M665interpolator_time,fqv[192],fqv[183],fqv[193]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M667interpolator_segment_time,fqv[194],fqv[183],fqv[195]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M669interpolator_segment,fqv[196],fqv[183],fqv[197]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M671interpolator_segment_num,fqv[198],fqv[183],fqv[199]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M673interpolator_interpolatingp,fqv[200],fqv[183],fqv[201]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M675interpolator_start_interpolation,fqv[202],fqv[183],fqv[203]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M677interpolator_stop_interpolation,fqv[204],fqv[183],fqv[205]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M679interpolator_pass_time,fqv[206],fqv[183],fqv[207]);
	local[0]= fqv[208];
	local[1]= fqv[153];
	local[2]= fqv[208];
	local[3]= fqv[154];
	local[4]= loadglobal(fqv[183]);
	local[5]= fqv[156];
	local[6]= fqv[24];
	local[7]= fqv[158];
	local[8]= NIL;
	local[9]= fqv[61];
	local[10]= NIL;
	local[11]= fqv[159];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[160];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[20])(ctx,13,local+2,&ftab[20],fqv[161]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M689linear_interpolator_interpolation,fqv[82],fqv[208],fqv[209]);
	local[0]= fqv[210];
	local[1]= fqv[153];
	local[2]= fqv[210];
	local[3]= fqv[154];
	local[4]= loadglobal(fqv[183]);
	local[5]= fqv[156];
	local[6]= fqv[211];
	local[7]= fqv[158];
	local[8]= NIL;
	local[9]= fqv[61];
	local[10]= NIL;
	local[11]= fqv[159];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[160];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[20])(ctx,13,local+2,&ftab[20],fqv[161]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M693minjerk_interpolator_velocity,fqv[212],fqv[210],fqv[213]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M695minjerk_interpolator_velocity_list,fqv[86],fqv[210],fqv[214]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M697minjerk_interpolator_acceleration,fqv[215],fqv[210],fqv[216]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M699minjerk_interpolator_acceleration_list,fqv[87],fqv[210],fqv[217]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M701minjerk_interpolator_reset,fqv[84],fqv[210],fqv[218]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M710minjerk_interpolator_interpolation,fqv[82],fqv[210],fqv[219]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[220],module,F495his2rgb,fqv[221]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[222],module,F496hvs2rgb,fqv[223]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[224],module,F497rgb2his,fqv[225]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[226],module,F498rgb2hvs,fqv[227]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[228],module,F499color_category10,fqv[229]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[230],module,F500color_category20,fqv[231]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[232],module,F777,fqv[233]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[234],module,F782,fqv[235]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[236],module,F785,fqv[237]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[107],module,F788,fqv[238]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[239],module,F791,fqv[240]);
	local[0]= fqv[241];
	local[1]= fqv[153];
	local[2]= fqv[241];
	local[3]= fqv[154];
	local[4]= loadglobal(fqv[242]);
	local[5]= fqv[156];
	local[6]= fqv[24];
	local[7]= fqv[158];
	local[8]= loadglobal(fqv[243]);
	local[9]= fqv[61];
	local[10]= fqv[121];
	local[11]= fqv[159];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[160];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[20])(ctx,13,local+2,&ftab[20],fqv[161]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= loadglobal(fqv[241]);
	local[1]= fqv[244];
	local[2]= fqv[245];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[246],module,F501termios_c_iflag,fqv[247]);
	local[0]= fqv[246];
	local[1]= fqv[248];
	local[2]= fqv[249];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[246];
	local[1]= fqv[250];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[251]); /*remprop*/
	local[0]= fqv[246];
	local[1]= fqv[252];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[251]); /*remprop*/
	local[0]= fqv[246];
	local[1]= NIL;
	local[2]= fqv[253];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[248],module,F502set_termios_c_iflag,fqv[254]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[255],module,F503termios_c_oflag,fqv[256]);
	local[0]= fqv[255];
	local[1]= fqv[257];
	local[2]= fqv[249];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[255];
	local[1]= fqv[250];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[251]); /*remprop*/
	local[0]= fqv[255];
	local[1]= fqv[252];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[251]); /*remprop*/
	local[0]= fqv[255];
	local[1]= NIL;
	local[2]= fqv[253];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[257],module,F504set_termios_c_oflag,fqv[258]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[259],module,F505termios_c_cflag,fqv[260]);
	local[0]= fqv[259];
	local[1]= fqv[261];
	local[2]= fqv[249];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[259];
	local[1]= fqv[250];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[251]); /*remprop*/
	local[0]= fqv[259];
	local[1]= fqv[252];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[251]); /*remprop*/
	local[0]= fqv[259];
	local[1]= NIL;
	local[2]= fqv[253];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[261],module,F506set_termios_c_cflag,fqv[262]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[263],module,F507termios_c_lflag,fqv[264]);
	local[0]= fqv[263];
	local[1]= fqv[265];
	local[2]= fqv[249];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[263];
	local[1]= fqv[250];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[251]); /*remprop*/
	local[0]= fqv[263];
	local[1]= fqv[252];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[251]); /*remprop*/
	local[0]= fqv[263];
	local[1]= NIL;
	local[2]= fqv[253];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[265],module,F508set_termios_c_lflag,fqv[266]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[267],module,F509termios_c_line,fqv[268]);
	local[0]= fqv[267];
	local[1]= fqv[269];
	local[2]= fqv[249];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[267];
	local[1]= fqv[250];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[251]); /*remprop*/
	local[0]= fqv[267];
	local[1]= fqv[252];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[251]); /*remprop*/
	local[0]= fqv[267];
	local[1]= NIL;
	local[2]= fqv[253];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[269],module,F510set_termios_c_line,fqv[270]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[271],module,F511termios_c_cc,fqv[272]);
	local[0]= fqv[271];
	local[1]= fqv[273];
	local[2]= fqv[249];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[271];
	local[1]= fqv[250];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[251]); /*remprop*/
	local[0]= fqv[271];
	local[1]= fqv[252];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[251]); /*remprop*/
	local[0]= fqv[271];
	local[1]= NIL;
	local[2]= fqv[253];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[273],module,F512set_termios_c_cc,fqv[274]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[275],module,F513termios_c_ispeed,fqv[276]);
	local[0]= fqv[275];
	local[1]= fqv[277];
	local[2]= fqv[249];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[275];
	local[1]= fqv[250];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[251]); /*remprop*/
	local[0]= fqv[275];
	local[1]= fqv[252];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[251]); /*remprop*/
	local[0]= fqv[275];
	local[1]= NIL;
	local[2]= fqv[253];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[277],module,F514set_termios_c_ispeed,fqv[278]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[279],module,F515termios_c_ospeed,fqv[280]);
	local[0]= fqv[279];
	local[1]= fqv[281];
	local[2]= fqv[249];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[279];
	local[1]= fqv[250];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[251]); /*remprop*/
	local[0]= fqv[279];
	local[1]= fqv[252];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[251]); /*remprop*/
	local[0]= fqv[279];
	local[1]= NIL;
	local[2]= fqv[253];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[281],module,F516set_termios_c_ospeed,fqv[282]);
	local[0]= fqv[283];
	local[1]= fqv[284];
	local[2]= makeint((eusinteger_t)0L);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[285];
	local[1]= fqv[284];
	local[2]= makeint((eusinteger_t)1L);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[286];
	local[1]= fqv[284];
	local[2]= makeint((eusinteger_t)2L);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[287];
	local[1]= fqv[284];
	local[2]= makeint((eusinteger_t)2L);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[288],module,F517kbhit,fqv[289]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[290],module,F518piped_fork_returns_list,fqv[291]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[292],module,F519make_robot_model_from_name,fqv[293]);
	local[0]= fqv[294];
	local[1]= fqv[295];
	ctx->vsp=local+2;
	w=(*ftab[22])(ctx,2,local+0,&ftab[22],fqv[296]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<23; i++) ftab[i]=fcallx;
}
