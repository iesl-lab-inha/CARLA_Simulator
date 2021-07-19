/* ./tty.c :  entry=tty */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "tty.h"
#pragma init (register_tty)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___tty();
extern pointer build_quote_vector();
static int register_tty()
  { add_module_initializer("___tty", ___tty);}

static pointer F73678tty_raw();
static pointer F73680tty_cooked();
static pointer F73682backspace();
static pointer F73684cursor_up();
static pointer F73686cursor_down();
static pointer F73688cursor_forward();
static pointer F73690cursor_backward();
static pointer F73692cursor_return();
static pointer F73694cursor_pos();
static pointer F73696erase_eol();

/*tty-raw*/
static pointer F73678tty_raw(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT73727;}
	local[0]= makeint(0);
ENT73727:
ENT73726:
	if (n>1) maerror();
	local[1]= loadglobal(fqv[0]);
	ctx->vsp=local+2;
	w=(pointer)COPYSEQ(ctx,1,local+1); /*copy-seq*/
	local[1]= w;
	local[2]= local[1];
	local[3]= makeint(7);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= local[1];
	local[3]= makeint(12);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= local[1];
	local[3]= makeint(13);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= local[1];
	local[3]= makeint(14);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= local[1];
	local[3]= makeint(15);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= local[1];
	local[3]= makeint(21);
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= local[1];
	local[3]= makeint(22);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,2,local+2,&ftab[0],fqv[1]); /*unix:tcsets*/
	local[0]= w;
BLK73724:
	ctx->vsp=local; return(local[0]);}

/*tty-cooked*/
static pointer F73680tty_cooked(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT73800;}
	local[0]= makeint(0);
ENT73800:
ENT73799:
	if (n>1) maerror();
	local[1]= local[0];
	local[2]= loadglobal(fqv[0]);
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[1]); /*unix:tcsets*/
	local[0]= w;
BLK73797:
	ctx->vsp=local; return(local[0]);}

/*backspace*/
static pointer F73682backspace(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT73820;}
	local[0]= makeint(1);
ENT73820:
ENT73819:
	if (n>1) maerror();
	local[1]= makeint(0);
	local[2]= local[0];
WHL73855:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX73856;
	local[3]= makeint(8);
	local[4]= loadglobal(fqv[2]);
	ctx->vsp=local+5;
	w=(pointer)WRTBYTE(ctx,2,local+3); /*write-byte*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL73855;
WHX73856:
	local[3]= NIL;
BLK73857:
	w = NIL;
	local[1]= loadglobal(fqv[2]);
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,1,local+1); /*finish-output*/
	local[0]= w;
BLK73817:
	ctx->vsp=local; return(local[0]);}

/*cursor-up*/
static pointer F73684cursor_up(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT73888;}
	local[0]= makeint(1);
ENT73888:
ENT73887:
	if (n>1) maerror();
	local[1]= loadglobal(fqv[2]);
	local[2]= fqv[3];
	local[3]= makeint(27);
	local[4]= makeint(91);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,5,local+1); /*format*/
	local[1]= loadglobal(fqv[2]);
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,1,local+1); /*finish-output*/
	local[0]= w;
BLK73885:
	ctx->vsp=local; return(local[0]);}

/*cursor-down*/
static pointer F73686cursor_down(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT73912;}
	local[0]= makeint(1);
ENT73912:
ENT73911:
	if (n>1) maerror();
	local[1]= loadglobal(fqv[2]);
	local[2]= fqv[4];
	local[3]= makeint(27);
	local[4]= makeint(91);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,5,local+1); /*format*/
	local[1]= loadglobal(fqv[2]);
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,1,local+1); /*finish-output*/
	local[0]= w;
BLK73909:
	ctx->vsp=local; return(local[0]);}

/*cursor-forward*/
static pointer F73688cursor_forward(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT73936;}
	local[0]= makeint(1);
ENT73936:
ENT73935:
	if (n>1) maerror();
	local[1]= loadglobal(fqv[2]);
	local[2]= fqv[5];
	local[3]= makeint(27);
	local[4]= makeint(91);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,5,local+1); /*format*/
	local[1]= loadglobal(fqv[2]);
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,1,local+1); /*finish-output*/
	local[0]= w;
BLK73933:
	ctx->vsp=local; return(local[0]);}

/*cursor-backward*/
static pointer F73690cursor_backward(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT73960;}
	local[0]= makeint(1);
ENT73960:
ENT73959:
	if (n>1) maerror();
	local[1]= loadglobal(fqv[2]);
	local[2]= fqv[6];
	local[3]= makeint(27);
	local[4]= makeint(91);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,5,local+1); /*format*/
	local[1]= loadglobal(fqv[2]);
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,1,local+1); /*finish-output*/
	local[0]= w;
BLK73957:
	ctx->vsp=local; return(local[0]);}

/*cursor-return*/
static pointer F73692cursor_return(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= loadglobal(fqv[2]);
	local[1]= fqv[7];
	local[2]= makeint(13);
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= loadglobal(fqv[2]);
	ctx->vsp=local+1;
	w=(pointer)FINOUT(ctx,1,local+0); /*finish-output*/
	local[0]= w;
BLK73981:
	ctx->vsp=local; return(local[0]);}

/*cursor-pos*/
static pointer F73694cursor_pos(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	if (w==NIL) goto IF74007;
	ctx->vsp=local+0;
	w=(pointer)F73692cursor_return(ctx,0,local+0); /*cursor-return*/
	local[0]= w;
	goto IF74008;
IF74007:
	local[0]= loadglobal(fqv[2]);
	local[1]= fqv[8];
	local[2]= makeint(13);
	local[3]= makeint(27);
	local[4]= makeint(91);
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,6,local+0); /*format*/
	local[0]= w;
IF74008:
	local[0]= loadglobal(fqv[2]);
	ctx->vsp=local+1;
	w=(pointer)FINOUT(ctx,1,local+0); /*finish-output*/
	local[0]= w;
BLK73997:
	ctx->vsp=local; return(local[0]);}

/*erase-eol*/
static pointer F73696erase_eol(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= loadglobal(fqv[2]);
	local[1]= fqv[9];
	local[2]= makeint(27);
	local[3]= makeint(91);
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= loadglobal(fqv[2]);
	ctx->vsp=local+1;
	w=(pointer)FINOUT(ctx,1,local+0); /*finish-output*/
	local[0]= w;
BLK74024:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___tty(ctx,n,argv,env)
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
	local[0]= fqv[10];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[11],module,F73678tty_raw,fqv[12]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[13],module,F73680tty_cooked,fqv[14]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[15],module,F73682backspace,fqv[16]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[17],module,F73684cursor_up,fqv[18]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[19],module,F73686cursor_down,fqv[20]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[21],module,F73688cursor_forward,fqv[22]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[23],module,F73690cursor_backward,fqv[24]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[25],module,F73692cursor_return,fqv[26]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[27],module,F73694cursor_pos,fqv[28]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[29],module,F73696erase_eol,fqv[30]);
	local[0]= fqv[31];
	local[1]= fqv[32];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[33]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<2; i++) ftab[i]=fcallx;
}
