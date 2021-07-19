/* ./mathtran.c :  entry=mathtran */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "mathtran.h"
#pragma init (register_mathtran)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___mathtran();
extern pointer build_quote_vector();
static int register_mathtran()
  { add_module_initializer("___mathtran", ___mathtran);}

static pointer F67873expression();
static pointer F67875infix2prefix();
static pointer F67877read_aref();

/*expression*/
static pointer F67873expression(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT67901;}
	local[0]= NIL;
ENT67901:
ENT67900:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,FLET67923,env,argv,local);
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,FLET67925,env,argv,local);
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,FLET67927,env,argv,local);
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,FLET67929,env,argv,local);
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,FLET67931,env,argv,local);
	ctx->vsp=local+9;
	local[9]= makeclosure(codevec,quotevec,FLET67933,env,argv,local);
	ctx->vsp=local+10;
	local[10]= makeclosure(codevec,quotevec,FLET67935,env,argv,local);
	ctx->vsp=local+11;
	local[11]= makeclosure(codevec,quotevec,FLET67937,env,argv,local);
	local[12]= argv[0];
	w = local[10];
	ctx->vsp=local+13;
	w=FLET67935(ctx,1,local+12,w);
	local[12]= w;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	w = local[2];
	if (argv[0]==NIL) goto IF67983;
	local[12]= fqv[0];
	ctx->vsp=local+13;
	w=(pointer)SIGERROR(ctx,1,local+12); /*error*/
	local[12]= w;
	goto IF67984;
IF67983:
	local[12]= NIL;
IF67984:
	local[12]= local[2];
	w = local[11];
	ctx->vsp=local+13;
	w=FLET67937(ctx,1,local+12,w);
	local[0]= w;
BLK67898:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET67923(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env2[3];
	local[2]= fqv[1];
	local[3]= (pointer)get_sym_func(fqv[2]);
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,4,local+0,&ftab[0],fqv[3]); /*assoc*/
	local[0]= w;
	if (local[0]==NIL) goto CON68028;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)RPLACA2(ctx,2,local+1); /*rplaca2*/
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	goto CON68026;
CON68028:
	ctx->vsp=local+1;
	w=(pointer)GENSYM(ctx,0,local+1); /*gensym*/
	local[0] = w;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[1]= w;
	w = env->c.clo.env2[3];
	ctx->vsp=local+2;
	env->c.clo.env2[3] = cons(ctx,local[1],w);
	local[1]= local[0];
	goto CON68026;
CON68062:
	local[1]= NIL;
CON68026:
	w = local[1];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET67925(ctx,n,argv,env)
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
	argv[0] = (w)->c.cons.cdr;
	w = local[0];
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	w = local[0];
	if (!iscons(w)) goto CON68151;
	local[3]= local[0];
	w = env->c.clo.env2[8];
	ctx->vsp=local+4;
	w=FLET67931(ctx,1,local+3,w);
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	w = local[0];
	if (local[2]==NIL) goto IF68199;
	local[3]= fqv[4];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
	goto IF68200;
IF68199:
	local[3]= NIL;
IF68200:
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON68149;
CON68151:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!iscons(w)) goto CON68212;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	if (fqv[6]!=local[3]) goto CON68266;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	w = env->c.clo.env2[9];
	ctx->vsp=local+4;
	w=FLET67933(ctx,1,local+3,w);
	local[1] = w;
	local[3]= fqv[6];
	local[4]= local[0];
	w = local[1];
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[2] = cons(ctx,local[3],w);
	if (env->c.clo.env2[0]!=NIL) goto IF68312;
	local[3]= local[2];
	w = env->c.clo.env2[4];
	ctx->vsp=local+4;
	w=FLET67923(ctx,1,local+3,w);
	local[2] = w;
	local[3]= local[2];
	goto IF68313;
IF68312:
	local[3]= NIL;
IF68313:
	local[3]= local[2];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON68264;
CON68266:
	local[3]= local[0];
	local[4]= local[1];
	w = env->c.clo.env2[9];
	ctx->vsp=local+5;
	w=FLET67933(ctx,1,local+4,w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	w = env->c.clo.env2[4];
	ctx->vsp=local+4;
	w=FLET67923(ctx,1,local+3,w);
	local[3]= w;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON68264;
CON68336:
	local[3]= NIL;
CON68264:
	goto CON68149;
CON68212:
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON68149;
CON68354:
	local[3]= NIL;
CON68149:
	w = local[3];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET67927(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	w = env->c.clo.env2[5];
	ctx->vsp=local+4;
	w=FLET67925(ctx,1,local+3,w);
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	w = local[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	if (fqv[7]!=local[3]) goto CON68429;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	w = env->c.clo.env2[5];
	ctx->vsp=local+4;
	w=FLET67925(ctx,1,local+3,w);
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	w = local[1];
	w = local[1];
	if (!isint(w)) goto CON68489;
	local[3]= local[1];
	local[4]= makeint(10);
	ctx->vsp=local+5;
	w=(pointer)LESSP(ctx,2,local+3); /*<*/
	if (w==NIL) goto CON68489;
	local[3]= fqv[8];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[2] = w;
	w = local[0];
	if (!!iscons(w)) goto CON68512;
	local[3]= makeint(0);
	local[4]= local[1];
WHL68541:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX68542;
	local[5]= local[2];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)NCONC(ctx,2,local+5); /*nconc*/
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL68541;
WHX68542:
	local[5]= NIL;
BLK68543:
	w = NIL;
	local[3]= local[2];
	w = env->c.clo.env2[4];
	ctx->vsp=local+4;
	w=FLET67923(ctx,1,local+3,w);
	local[3]= w;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON68510;
CON68512:
	local[3]= makeint(0);
	local[4]= local[1];
WHL68603:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX68604;
	local[5]= local[2];
	local[6]= fqv[9];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)NCONC(ctx,2,local+5); /*nconc*/
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL68603;
WHX68604:
	local[5]= NIL;
BLK68605:
	w = NIL;
	local[3]= fqv[10];
	local[4]= fqv[9];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[4]= w;
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON68510;
CON68576:
	local[3]= NIL;
CON68510:
	goto CON68487;
CON68489:
	local[3]= fqv[11];
	local[4]= local[0];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[3]= w;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON68487;
CON68653:
	local[3]= NIL;
CON68487:
	goto CON68427;
CON68429:
	w = local[0];
	if (!isnum(w)) goto CON68665;
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON68427;
CON68665:
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON68427;
CON68674:
	local[3]= NIL;
CON68427:
	w = local[3];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET67929(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	w = env->c.clo.env2[6];
	ctx->vsp=local+4;
	w=FLET67927(ctx,1,local+3,w);
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	w = local[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	local[3]= local[1];
	w = fqv[12];
	if (memq(local[3],w)==NIL) goto CON68761;
WHL68772:
	local[3]= local[1];
	w = fqv[13];
	if (memq(local[3],w)==NIL) goto WHX68773;
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[0] = w;
WHL68796:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	if (local[1]!=local[3]) goto WHX68797;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	w = env->c.clo.env2[6];
	ctx->vsp=local+4;
	w=FLET67927(ctx,1,local+3,w);
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	w = local[2];
	local[3]= local[0];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)NCONC(ctx,2,local+3); /*nconc*/
	goto WHL68796;
WHX68797:
	local[3]= NIL;
BLK68798:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	goto WHL68772;
WHX68773:
	local[3]= NIL;
BLK68774:
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON68759;
CON68761:
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON68759;
CON68877:
	local[3]= NIL;
CON68759:
	w = local[3];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET67931(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= local[0];
	w = fqv[14];
	if (memq(local[3],w)==NIL) goto IF68913;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	local[3]= argv[0];
	goto IF68914;
IF68913:
	local[3]= NIL;
IF68914:
	local[3]= argv[0];
	w = env->c.clo.env2[7];
	ctx->vsp=local+4;
	w=FLET67929(ctx,1,local+3,w);
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	w = local[1];
	local[3]= local[0];
	if (fqv[15]!=local[3]) goto IF68978;
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[1] = w;
	local[3]= local[1];
	goto IF68979;
IF68978:
	local[3]= NIL;
IF68979:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w = fqv[16];
	if (memq(local[3],w)==NIL) goto IF68998;
	local[3]= fqv[17];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[1] = w;
WHL69028:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	local[3]= local[0];
	w = fqv[18];
	if (memq(local[3],w)==NIL) goto WHX69029;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	w = env->c.clo.env2[7];
	ctx->vsp=local+4;
	w=FLET67929(ctx,1,local+3,w);
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	w = local[2];
	local[3]= local[0];
	if (fqv[15]!=local[3]) goto IF69097;
	local[3]= fqv[15];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[2] = w;
	local[3]= local[2];
	goto IF69098;
IF69097:
	local[3]= NIL;
IF69098:
	local[3]= local[1];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)NCONC(ctx,2,local+3); /*nconc*/
	goto WHL69028;
WHX69029:
	local[3]= NIL;
BLK69030:
	goto IF68999;
IF68998:
	local[3]= NIL;
IF68999:
	local[3]= local[1];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET67933(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
WHL69150:
	if (argv[0]==NIL) goto WHX69151;
	local[2]= argv[0];
	w = env->c.clo.env2[8];
	ctx->vsp=local+3;
	w=FLET67931(ctx,1,local+2,w);
	local[2]= w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	w = local[0];
	local[2]= local[0];
	w = local[1];
	ctx->vsp=local+3;
	local[1] = cons(ctx,local[2],w);
	goto WHL69150;
WHX69151:
	local[2]= NIL;
BLK69152:
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)NREVERSE(ctx,1,local+2); /*nreverse*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET67935(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	w = env->c.clo.env2[8];
	ctx->vsp=local+4;
	w=FLET67931(ctx,1,local+3,w);
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	w = local[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	w = fqv[19];
	if (memq(local[3],w)==NIL) goto IF69327;
	local[3]= argv[0];
	w = env->c.clo.env2[8];
	ctx->vsp=local+4;
	w=FLET67931(ctx,1,local+3,w);
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	w = local[2];
	local[3]= local[1];
	local[4]= fqv[20];
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,2,local+3,&ftab[0],fqv[3]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= local[0];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[0] = w;
	local[3]= local[0];
	goto IF69328;
IF69327:
	local[3]= NIL;
IF69328:
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET67937(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	argv[0] = w;
	local[0]= NIL;
	local[1]= NIL;
	local[2]= env->c.clo.env2[3];
WHL69457:
	if (local[2]==NIL) goto WHX69458;
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
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)GREATERP(ctx,2,local+3); /*>*/
	if (w==NIL) goto IF69506;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[3]= w;
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	local[3]= local[0];
	goto IF69507;
IF69506:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)NSUBST(ctx,3,local+3); /*nsubst*/
	local[3]= w;
IF69507:
	goto WHL69457;
WHX69458:
	local[3]= NIL;
BLK69459:
	w = NIL;
	if (local[0]==NIL) goto IF69563;
	local[1]= fqv[21];
	local[2]= local[0];
	w = argv[0];
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto IF69564;
IF69563:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
IF69564:
	w = local[1];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*infix2prefix*/
static pointer F67875infix2prefix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT69589;}
	local[0]= NIL;
ENT69589:
ENT69588:
	if (n>2) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)READ(ctx,1,local+1); /*read*/
	local[1]= w;
	w = local[1];
	if (!issymbol(w)) goto CON69618;
	local[2]= local[1];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)READ(ctx,1,local+3); /*read*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	local[3]= T;
	ctx->vsp=local+4;
	w=(pointer)F67873expression(ctx,2,local+2); /*expression*/
	local[2]= w;
	goto CON69616;
CON69618:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	if (fqv[22]!=local[2]) goto CON69631;
	local[2]= fqv[23];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	local[5]= NIL;
	ctx->vsp=local+6;
	w=(pointer)F67873expression(ctx,2,local+4); /*expression*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,3,local+2); /*list*/
	local[2]= w;
	goto CON69616;
CON69631:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	if (fqv[22]!=local[2]) goto CON69662;
	local[2]= fqv[24];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[3]= w;
	local[4]= T;
	ctx->vsp=local+5;
	w=(pointer)F67873expression(ctx,2,local+3); /*expression*/
	local[3]= w;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,1,local+4,&ftab[2],fqv[25]); /*cdddr*/
	local[4]= w;
	local[5]= NIL;
	ctx->vsp=local+6;
	w=(pointer)F67873expression(ctx,2,local+4); /*expression*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,3,local+2); /*list*/
	local[2]= w;
	goto CON69616;
CON69662:
	local[2]= local[1];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)F67873expression(ctx,2,local+2); /*expression*/
	local[2]= w;
	goto CON69616;
CON69703:
	local[2]= NIL;
CON69616:
	w = local[2];
	local[0]= w;
BLK69586:
	ctx->vsp=local; return(local[0]);}

/*read-aref*/
static pointer F67877read_aref(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT69715;}
	local[0]= NIL;
ENT69715:
ENT69714:
	if (n>2) maerror();
	local[1]= fqv[6];
	local[2]= makeint(93);
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[3])(ctx,2,local+2,&ftab[3],fqv[26]); /*read-delimited-list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK69712:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___mathtran(ctx,n,argv,env)
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
	local[0]= fqv[27];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF69747;
	local[0]= fqv[28];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[29],w);
	goto IF69748;
IF69747:
	local[0]= fqv[30];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF69748:
	ctx->vsp=local+0;
	compfun(ctx,fqv[31],module,F67873expression,fqv[32]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[33],module,F67875infix2prefix,fqv[34]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[35],module,F67877read_aref,fqv[36]);
	local[0]= makeint(37);
	local[1]= fqv[33];
	ctx->vsp=local+2;
	w=(pointer)SETMACROCH(ctx,2,local+0); /*set-macro-character*/
	local[0]= makeint(91);
	local[1]= fqv[35];
	ctx->vsp=local+2;
	w=(pointer)SETMACROCH(ctx,2,local+0); /*set-macro-character*/
	local[0]= makeint(93);
	local[1]= makeint(41);
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[37]); /*set-syntax-from-char*/
	local[0]= fqv[38];
	local[1]= fqv[39];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,2,local+0,&ftab[5],fqv[40]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<6; i++) ftab[i]=fcallx;
}
