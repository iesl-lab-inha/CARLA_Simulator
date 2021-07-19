/* ./process.c :  entry=process */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "process.h"
#pragma init (register_process)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___process();
extern pointer build_quote_vector();
static int register_process()
  { add_module_initializer("___process", ___process);}

static pointer F43566pwd();
static pointer F43569ez();
static pointer F43572piped_fork();
static pointer F43575popen();
static pointer F43578xfork();
static pointer F43582dir();
static pointer F43585rusage();
static pointer F43588xterm_window();

/*cd*/
static pointer F43620(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT43624;}
	local[0]= fqv[0];
	ctx->vsp=local+1;
	w=(pointer)GETENV(ctx,1,local+0); /*unix:getenv*/
	local[0]= w;
ENT43624:
ENT43623:
	if (n>1) maerror();
	w = local[0];
	if (!issymbol(w)) goto IF43638;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[1]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,1,local+1,&ftab[1],fqv[2]); /*string-downcase*/
	local[0] = w;
	local[1]= local[0];
	goto IF43639;
IF43638:
	local[1]= NIL;
IF43639:
	local[1]= fqv[3];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK43621:
	ctx->vsp=local; return(local[0]);}

/*pwd*/
static pointer F43566pwd(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	ctx->vsp=local+0;
	w=(pointer)GETWD(ctx,0,local+0); /*unix:getwd*/
	local[0]= w;
BLK43667:
	ctx->vsp=local; return(local[0]);}

/*ez*/
static pointer F43569ez(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT43682;}
	local[0]= fqv[4];
	ctx->vsp=local+1;
	w=(pointer)GETENV(ctx,1,local+0); /*unix:getenv*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[2])(ctx,1,local+0,&ftab[2],fqv[5]); /*read-from-string*/
	local[0]= w;
ENT43682:
ENT43681:
	if (n>1) maerror();
	local[1]= local[0];
	local[2]= makeint(327680);
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MSGGET(ctx,1,local+1); /*unix:msgget*/
	local[1]= w;
	local[2]= local[0];
	local[3]= makeint(393216);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MSGGET(ctx,1,local+2); /*unix:msgget*/
	local[2]= w;
	local[3]= loadglobal(fqv[1]);
	local[4]= makeint(256);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,2,local+3); /*instantiate*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= local[1];
	local[7]= fqv[6];
	local[8]= makeint(0);
	local[9]= makeint(2);
	ctx->vsp=local+10;
	w=(pointer)MSGSND(ctx,4,local+6); /*unix:msgsnd*/
WHL43743:
	local[6]= local[2];
	local[7]= local[3];
	local[8]= makeint(0);
	ctx->vsp=local+9;
	w=(pointer)MSGRCV(ctx,3,local+6); /*unix:msgrcv*/
	local[5] = w;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= makeint(99);
	ctx->vsp=local+8;
	w=(pointer)EQUAL(ctx,2,local+6); /*equal*/
	if (w!=NIL) goto WHX43744;
	local[6]= local[4];
	local[7]= local[3];
	local[8]= makeint(0);
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	ctx->vsp=local+10;
	w=(pointer)SUBSEQ(ctx,3,local+7); /*subseq*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)NCONC(ctx,2,local+6); /*nconc*/
	local[4] = w;
	goto WHL43743;
WHX43744:
	local[6]= NIL;
BLK43745:
	if (local[4]!=NIL) goto IF43786;
	w = NIL;
	ctx->vsp=local+6;
	local[0]=w;
	goto BLK43679;
	goto IF43787;
IF43786:
	local[6]= NIL;
IF43787:
	local[6]= fqv[7];
	local[7]= loadglobal(fqv[1]);
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,3,local+6); /*apply*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[3])(ctx,1,local+6,&ftab[3],fqv[8]); /*make-string-input-stream*/
	local[4] = w;
WHL43811:
	local[6]= local[4];
	local[7]= NIL;
	local[8]= fqv[9];
	ctx->vsp=local+9;
	w=(pointer)READ(ctx,3,local+6); /*read*/
	local[5] = w;
	local[6]= local[5];
	local[7]= fqv[9];
	ctx->vsp=local+8;
	w=(pointer)EQUAL(ctx,2,local+6); /*equal*/
	if (w!=NIL) goto WHX43812;
	local[6]= local[5];
	ctx->vsp=local+7;
	w=(pointer)EVAL(ctx,1,local+6); /*eval*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)PRINT(ctx,1,local+6); /*print*/
	goto WHL43811;
WHX43812:
	local[6]= NIL;
BLK43813:
	w = local[6];
	local[0]= w;
BLK43679:
	ctx->vsp=local; return(local[0]);}

/*piped-fork*/
static pointer F43572piped_fork(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT43843;}
	local[0]= NIL;
ENT43843:
ENT43842:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+2;
	w=(pointer)PIPE(ctx,0,local+2); /*unix:pipe*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)PIPE(ctx,0,local+3); /*unix:pipe*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)FORK(ctx,0,local+4); /*unix:fork*/
	local[4]= w;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)STREAMP(ctx,1,local+11); /*streamp*/
	if (w!=NIL) goto IF43891;
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)MINUS(ctx,1,local+11); /*-*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)SYSERRLIST(ctx,1,local+11); /*unix:syserrlist*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)SIGERROR(ctx,1,local+11); /*error*/
	local[11]= w;
	goto IF43892;
IF43891:
	local[11]= NIL;
IF43892:
	local[11]= local[4];
	local[12]= makeint(0);
	ctx->vsp=local+13;
	w=(pointer)NUMEQUAL(ctx,2,local+11); /*=*/
	if (w==NIL) goto IF43912;
	local[11]= loadglobal(fqv[10]);
	ctx->vsp=local+12;
	w=(pointer)CLOSE(ctx,1,local+11); /*close*/
	local[11]= loadglobal(fqv[11]);
	ctx->vsp=local+12;
	w=(pointer)CLOSE(ctx,1,local+11); /*close*/
	local[11]= *(ovafptr(local[2],fqv[12]));
	ctx->vsp=local+12;
	w=(pointer)CLOSE(ctx,1,local+11); /*close*/
	local[11]= *(ovafptr(local[3],fqv[13]));
	ctx->vsp=local+12;
	w=(pointer)CLOSE(ctx,1,local+11); /*close*/
	local[11]= local[2];
	local[12]= fqv[14];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)DUP(ctx,1,local+11); /*unix:dup*/
	local[5] = w;
	local[11]= local[3];
	local[12]= fqv[15];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)DUP(ctx,1,local+11); /*unix:dup*/
	local[6] = w;
	local[11]= makeint(2);
	local[12]= makeint(1);
	ctx->vsp=local+13;
	w=(pointer)SIGNAL(ctx,2,local+11); /*unix:signal*/
	local[11]= loadglobal(fqv[16]);
	ctx->vsp=local+12;
	w=(pointer)INSTANTIATE(ctx,1,local+11); /*instantiate*/
	local[11]= w;
	local[12]= local[11];
	local[13]= fqv[17];
	local[14]= local[5];
	local[15]= fqv[18];
	local[16]= fqv[19];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,5,local+12); /*send*/
	w = local[11];
	storeglobal(fqv[10],w);
	local[11]= loadglobal(fqv[16]);
	ctx->vsp=local+12;
	w=(pointer)INSTANTIATE(ctx,1,local+11); /*instantiate*/
	local[11]= w;
	local[12]= local[11];
	local[13]= fqv[17];
	local[14]= local[6];
	local[15]= fqv[20];
	local[16]= fqv[21];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,5,local+12); /*send*/
	w = local[11];
	storeglobal(fqv[11],w);
	local[11]= loadglobal(fqv[10]);
	local[12]= loadglobal(fqv[11]);
	ctx->vsp=local+13;
	w=(*ftab[4])(ctx,2,local+11,&ftab[4],fqv[22]); /*make-two-way-stream*/
	local[11]= w;
	storeglobal(fqv[23],w);
	w = local[0];
	if (!isstring(w)) goto CON44038;
	local[11]= makeint(32);
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(*ftab[5])(ctx,2,local+11,&ftab[5],fqv[24]); /*position*/
	if (w==NIL) goto IF44044;
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)SYSTEM(ctx,1,local+11); /*unix:system*/
	local[11]= w;
	goto IF44045;
IF44044:
	local[11]= (pointer)get_sym_func(fqv[25]);
	local[12]= local[0];
	local[13]= local[1];
	ctx->vsp=local+14;
	w=(pointer)APPLY(ctx,3,local+11); /*apply*/
	local[11]= w;
IF44045:
	goto CON44036;
CON44038:
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(*ftab[6])(ctx,1,local+11,&ftab[6],fqv[26]); /*functionp*/
	if (w==NIL) goto CON44061;
	local[11]= local[0];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)APPLY(ctx,2,local+11); /*apply*/
	local[11]= fqv[27];
	w = T;
	ctx->vsp=local+12;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	goto CON44036;
CON44061:
WHL44083:
	if (T==NIL) goto WHX44084;
	{jmp_buf jb;
	w = makeint(0);
	ctx->vsp=local+11;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT44090;}
	local[17]= makeint(0);
	storeglobal(fqv[28],local[17]);
	local[17]= fqv[29];
	ctx->vsp=local+18;
	w=(*ftab[7])(ctx,1,local+17,&ftab[7],fqv[30]); /*reploop*/
	local[17]= fqv[27];
	w = NIL;
	ctx->vsp=local+18;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	w = local[17];
CAT44090:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	goto WHL44083;
WHX44084:
	local[11]= NIL;
BLK44085:
	goto CON44036;
CON44079:
	local[11]= NIL;
CON44036:
	local[11]= makeint(1);
	ctx->vsp=local+12;
	w=(*ftab[8])(ctx,1,local+11,&ftab[8],fqv[31]); /*unix::_exit*/
	local[11]= w;
	goto IF43913;
IF43912:
	local[11]= loadglobal(fqv[32]);
	ctx->vsp=local+12;
	w=(pointer)INSTANTIATE(ctx,1,local+11); /*instantiate*/
	local[11]= w;
	local[12]= NIL;
	local[13]= NIL;
	if (loadglobal(fqv[33])==NIL) goto IF44133;
	local[14]= T;
	local[15]= fqv[34];
	local[16]= local[4];
	ctx->vsp=local+17;
	w=(pointer)XFORMAT(ctx,3,local+14); /*format*/
	local[14]= w;
	goto IF44134;
IF44133:
	local[14]= NIL;
IF44134:
	local[14]= local[11];
	local[15]= local[4];
	local[16]= fqv[35];
	ctx->vsp=local+17;
	w=(pointer)PUTPROP(ctx,3,local+14); /*putprop*/
	local[12] = *(ovafptr(local[3],fqv[13]));
	local[13] = *(ovafptr(local[2],fqv[12]));
	local[14]= local[12];
	*(ovafptr(local[11],fqv[13])) = local[14];
	local[14]= local[13];
	local[15]= local[14];
	*(ovafptr(local[11],fqv[12])) = local[15];
	local[14]= local[12];
	local[15]= local[4];
	local[16]= fqv[35];
	ctx->vsp=local+17;
	w=(pointer)PUTPROP(ctx,3,local+14); /*putprop*/
	local[14]= *(ovafptr(local[2],fqv[13]));
	ctx->vsp=local+15;
	w=(pointer)CLOSE(ctx,1,local+14); /*close*/
	local[14]= *(ovafptr(local[3],fqv[12]));
	ctx->vsp=local+15;
	w=(pointer)CLOSE(ctx,1,local+14); /*close*/
	w = local[11];
	local[11]= w;
IF43913:
	w = local[11];
	local[0]= w;
BLK43840:
	ctx->vsp=local; return(local[0]);}

/*popen*/
static pointer F43575popen(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST44199:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+1;
	w=(pointer)PIPE(ctx,0,local+1); /*unix:pipe*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)PIPE(ctx,0,local+2); /*unix:pipe*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)FORK(ctx,0,local+4); /*unix:fork*/
	local[3] = w;
	local[4]= local[3];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)NUMEQUAL(ctx,2,local+4); /*=*/
	if (w==NIL) goto IF44229;
	local[4]= loadglobal(fqv[10]);
	ctx->vsp=local+5;
	w=(pointer)CLOSE(ctx,1,local+4); /*close*/
	local[4]= loadglobal(fqv[11]);
	ctx->vsp=local+5;
	w=(pointer)CLOSE(ctx,1,local+4); /*close*/
	local[4]= *(ovafptr(local[1],fqv[12]));
	ctx->vsp=local+5;
	w=(pointer)CLOSE(ctx,1,local+4); /*close*/
	local[4]= *(ovafptr(local[2],fqv[13]));
	ctx->vsp=local+5;
	w=(pointer)CLOSE(ctx,1,local+4); /*close*/
	local[4]= local[1];
	local[5]= fqv[14];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)DUP(ctx,1,local+4); /*unix:dup*/
	local[4]= local[2];
	local[5]= fqv[15];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)DUP(ctx,1,local+4); /*unix:dup*/
	local[4]= makeint(32);
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(*ftab[5])(ctx,2,local+4,&ftab[5],fqv[24]); /*position*/
	if (w==NIL) goto IF44278;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)SYSTEM(ctx,1,local+4); /*unix:system*/
	local[4]= w;
	goto IF44279;
IF44278:
	local[4]= (pointer)get_sym_func(fqv[25]);
	local[5]= argv[0];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,3,local+4); /*apply*/
	local[4]= w;
IF44279:
	goto IF44230;
IF44229:
	local[4]= loadglobal(fqv[32]);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= NIL;
	local[6]= NIL;
	if (loadglobal(fqv[33])==NIL) goto IF44312;
	local[7]= T;
	local[8]= fqv[36];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= w;
	goto IF44313;
IF44312:
	local[7]= NIL;
IF44313:
	local[7]= local[4];
	local[8]= local[3];
	local[9]= fqv[35];
	ctx->vsp=local+10;
	w=(pointer)PUTPROP(ctx,3,local+7); /*putprop*/
	local[5] = *(ovafptr(local[2],fqv[13]));
	local[6] = *(ovafptr(local[1],fqv[12]));
	local[7]= local[5];
	*(ovafptr(local[4],fqv[13])) = local[7];
	local[7]= local[6];
	local[8]= local[7];
	*(ovafptr(local[4],fqv[12])) = local[8];
	local[7]= local[5];
	local[8]= local[3];
	local[9]= fqv[35];
	ctx->vsp=local+10;
	w=(pointer)PUTPROP(ctx,3,local+7); /*putprop*/
	local[7]= *(ovafptr(local[1],fqv[13]));
	ctx->vsp=local+8;
	w=(pointer)CLOSE(ctx,1,local+7); /*close*/
	local[7]= *(ovafptr(local[2],fqv[12]));
	ctx->vsp=local+8;
	w=(pointer)CLOSE(ctx,1,local+7); /*close*/
	w = local[4];
	local[4]= w;
IF44230:
	w = local[4];
	local[0]= w;
BLK44197:
	ctx->vsp=local; return(local[0]);}

/*xfork*/
static pointer F43578xfork(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[37], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY44387;
	local[0] = loadglobal(fqv[10]);
KEY44387:
	if (n & (1<<1)) goto KEY44393;
	local[1] = loadglobal(fqv[11]);
KEY44393:
	if (n & (1<<2)) goto KEY44399;
	local[2] = loadglobal(fqv[38]);
KEY44399:
	if (n & (1<<3)) goto KEY44406;
	local[3] = NIL;
KEY44406:
	ctx->vsp=local+4;
	w=(pointer)FORK(ctx,0,local+4); /*unix:fork*/
	local[4]= w;
	local[5]= NIL;
	local[6]= local[4];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)NUMEQUAL(ctx,2,local+6); /*=*/
	if (w==NIL) goto CON44432;
	local[6]= local[0];
	local[7]= fqv[14];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)NUMEQUAL(ctx,2,local+6); /*=*/
	if (w!=NIL) goto IF44439;
	local[6]= local[0];
	local[7]= fqv[14];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)DUP2(ctx,2,local+6); /*unix:dup2*/
	local[6]= w;
	goto IF44440;
IF44439:
	local[6]= NIL;
IF44440:
	local[6]= local[1];
	local[7]= fqv[15];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)NUMEQUAL(ctx,2,local+6); /*=*/
	if (w!=NIL) goto IF44461;
	local[6]= local[1];
	local[7]= fqv[15];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)DUP2(ctx,2,local+6); /*unix:dup2*/
	local[6]= w;
	goto IF44462;
IF44461:
	local[6]= NIL;
IF44462:
	local[6]= local[2];
	local[7]= fqv[15];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= makeint(2);
	ctx->vsp=local+8;
	w=(pointer)NUMEQUAL(ctx,2,local+6); /*=*/
	if (w!=NIL) goto IF44483;
	local[6]= local[2];
	local[7]= fqv[15];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= makeint(2);
	ctx->vsp=local+8;
	w=(pointer)DUP2(ctx,2,local+6); /*unix:dup2*/
	local[6]= w;
	goto IF44484;
IF44483:
	local[6]= NIL;
IF44484:
	local[6]= makeint(32);
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(*ftab[5])(ctx,2,local+6,&ftab[5],fqv[24]); /*position*/
	if (w==NIL) goto IF44504;
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)SYSTEM(ctx,1,local+6); /*unix:system*/
	local[6]= w;
	goto IF44505;
IF44504:
	local[6]= (pointer)get_sym_func(fqv[25]);
	local[7]= argv[0];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,3,local+6); /*apply*/
	local[6]= w;
IF44505:
	local[6]= fqv[39];
	ctx->vsp=local+7;
	w=(pointer)SIGERROR(ctx,1,local+6); /*error*/
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(*ftab[9])(ctx,1,local+6,&ftab[9],fqv[40]); /*exit*/
	local[6]= w;
	goto CON44430;
CON44432:
	if (loadglobal(fqv[33])==NIL) goto IF44531;
	local[6]= T;
	local[7]= fqv[41];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	goto IF44532;
IF44531:
	local[6]= NIL;
IF44532:
	goto CON44430;
CON44527:
	local[6]= NIL;
CON44430:
	local[6]= loadglobal(fqv[32]);
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,1,local+6); /*instantiate*/
	local[6]= w;
	local[7]= local[6];
	local[8]= fqv[17];
	local[9]= local[1];
	local[10]= fqv[42];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	local[10]= local[0];
	local[11]= fqv[43];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	w = local[6];
	local[5] = w;
	w = local[5];
	local[0]= w;
BLK44375:
	ctx->vsp=local; return(local[0]);}

/*dir*/
static pointer F43582dir(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT44591;}
	local[0]= fqv[44];
ENT44591:
ENT44590:
	if (n>1) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,1,local+1,&ftab[10],fqv[45]); /*directory*/
	local[1]= w;
	local[2]= (pointer)get_sym_func(fqv[46]);
	ctx->vsp=local+3;
	w=(pointer)SORT(ctx,2,local+1); /*sort*/
	local[1]= w;
	local[2]= local[1];
	local[3]= makeint(16);
	local[4]= (pointer)get_sym_func(fqv[47]);
	local[5]= (pointer)get_sym_func(fqv[48]);
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)MAPCAR(ctx,2,local+5); /*mapcar*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,2,local+4); /*apply*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MAX(ctx,2,local+3); /*max*/
	local[3]= w;
	local[4]= makeint(0);
	local[5]= makeint(80);
	ctx->vsp=local+6;
	w=(*ftab[11])(ctx,4,local+2,&ftab[11],fqv[49]); /*tprint*/
	local[0]= w;
BLK44588:
	ctx->vsp=local; return(local[0]);}

/*rusage*/
static pointer F43585rusage(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT44645;}
	local[0]= makeint(0);
ENT44645:
	if (n>=2) { local[1]=(argv[1]); goto ENT44644;}
	local[1]= T;
ENT44644:
ENT44643:
	if (n>2) maerror();
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)GETRUSAGE(ctx,1,local+2); /*unix:getrusage*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)GETPAGESIZE(ctx,0,local+3); /*unix:getpagesize*/
	local[3]= w;
	local[4]= makeint(1024);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	local[4]= local[1];
	local[5]= fqv[50];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[7];
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,4,local+4); /*format*/
	local[4]= local[1];
	local[5]= fqv[51];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[4];
	local[4]= local[1];
	local[5]= fqv[52];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[4];
	local[4]= local[1];
	local[5]= fqv[53];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= local[1];
	local[5]= fqv[54];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= local[1];
	local[5]= fqv[55];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= local[1];
	local[5]= fqv[56];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= local[1];
	local[5]= fqv[57];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= local[1];
	local[5]= fqv[58];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= local[1];
	local[5]= fqv[59];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= local[1];
	local[5]= fqv[60];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= local[1];
	local[5]= fqv[61];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= local[1];
	local[5]= fqv[62];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[0]= w;
BLK44641:
	ctx->vsp=local; return(local[0]);}

/*xterm-window*/
static pointer F43588xterm_window(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT45311;}
	local[0]= fqv[63];
ENT45311:
	if (n>=2) { local[1]=(argv[1]); goto ENT45310;}
	local[1]= NIL;
ENT45310:
ENT45309:
	if (n>2) maerror();
	local[2]= NIL;
	local[3]= makeint(112);
	local[4]= makeint(0);
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
WHL45352:
	if (local[5]!=NIL) goto WHX45353;
	local[8]= NIL;
	local[9]= fqv[64];
	local[10]= local[3];
	local[11]= local[4];
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,4,local+8); /*format*/
	local[2] = w;
	local[8]= local[2];
	local[9]= fqv[65];
	local[10]= NIL;
	local[11]= fqv[66];
	local[12]= fqv[67];
	ctx->vsp=local+13;
	w=(*ftab[12])(ctx,5,local+8,&ftab[12],fqv[68]); /*open*/
	local[5] = w;
	if (local[5]!=NIL) goto IF45387;
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[4] = w;
	local[8]= local[4];
	local[9]= makeint(16);
	ctx->vsp=local+10;
	w=(pointer)NUMEQUAL(ctx,2,local+8); /*=*/
	if (w==NIL) goto IF45407;
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[3] = w;
	local[4] = makeint(0);
	local[8]= local[3];
	local[9]= makeint(122);
	ctx->vsp=local+10;
	w=(pointer)NUMEQUAL(ctx,2,local+8); /*=*/
	if (w==NIL) goto IF45432;
	w = NIL;
	ctx->vsp=local+8;
	local[0]=w;
	goto BLK45307;
	goto IF45433;
IF45432:
	local[8]= NIL;
IF45433:
	goto IF45408;
IF45407:
	local[8]= NIL;
IF45408:
	goto IF45388;
IF45387:
	local[8]= NIL;
IF45388:
	goto WHL45352;
WHX45353:
	local[8]= NIL;
BLK45354:
	local[8]= local[5];
	local[9]= fqv[14];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[6] = w;
	local[8]= local[6];
	local[9]= makeint(9);
	ctx->vsp=local+10;
	w=(pointer)GREATERP(ctx,2,local+8); /*>*/
	if (w==NIL) goto IF45443;
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)CLOSE(ctx,1,local+8); /*close*/
	w = NIL;
	ctx->vsp=local+8;
	local[0]=w;
	goto BLK45307;
	goto IF45444;
IF45443:
	local[8]= NIL;
IF45444:
	local[8]= local[5];
	local[9]= fqv[69];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= local[0];
	local[9]= NIL;
	local[10]= fqv[70];
	local[11]= local[3];
	local[12]= local[4];
	local[13]= makeint(0);
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,5,local+9); /*format*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)F43572piped_fork(ctx,2,local+8); /*piped-fork*/
	local[7] = w;
	local[8]= local[5];
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,2,local+8); /*list*/
	local[0]= w;
BLK45307:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___process(ctx,n,argv,env)
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
	local[0]= fqv[71];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF45501;
	local[0]= fqv[72];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[73],w);
	goto IF45502;
IF45501:
	local[0]= fqv[74];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF45502:
	local[0]= fqv[75];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compmacro(ctx,fqv[76],module,F43620,fqv[77]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[78],module,F43566pwd,fqv[79]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[80],module,F43569ez,fqv[81]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[82],module,F43572piped_fork,fqv[83]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[84],module,F43575popen,fqv[85]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[86],module,F43578xfork,fqv[87]);
	local[0]= fqv[45];
	local[1]= fqv[88];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*setfunc*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[89],module,F43582dir,fqv[90]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[91],module,F43585rusage,fqv[92]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[93],module,F43588xterm_window,fqv[94]);
	local[0]= fqv[95];
	local[1]= fqv[96];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,2,local+0,&ftab[13],fqv[97]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<14; i++) ftab[i]=fcallx;
}
