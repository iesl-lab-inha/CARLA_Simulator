/* ./pbmfile.c :  entry=pbmfile */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "pbmfile.h"
#pragma init (register_pbmfile)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___pbmfile();
extern pointer build_quote_vector();
static int register_pbmfile()
  { add_module_initializer("___pbmfile", ___pbmfile);}

static pointer F69read_raw_image();
static pointer F70write_raw_image();
static pointer F71read_pbm_token();
static pointer F72read_ascii_pbm();
static pointer F73read_binary_pbm();
static pointer F74write_pgm();
static pointer F75read_ascii_pgm();
static pointer F76read_binary_pgm();
static pointer F77read_binary_ppm();
static pointer F78read_ascii_ppm();
static pointer F79write_ppm();
static pointer F80read_pnm();
static pointer F81read_pnm_file();
static pointer F82write_pnm();
static pointer F83write_pnm_file();

/*read-raw-image*/
static pointer F69read_raw_image(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT87;}
	local[0]= makeint(256);
ENT87:
	if (n>=3) { local[1]=(argv[2]); goto ENT86;}
	local[1]= local[0];
ENT86:
ENT85:
	if (n>3) maerror();
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= fqv[0];
	local[4]= fqv[1];
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,3,local+2,&ftab[0],fqv[2]); /*make-array*/
	local[2]= w;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[1])(ctx,1,local+3,&ftab[1],fqv[3]); /*open*/
	local[3]= w;
	ctx->vsp=local+4;
	w = makeclosure(codevec,quotevec,UWP88,env,argv,local);
	local[4]=(pointer)(ctx->protfp); local[5]=w;
	ctx->protfp=(struct protectframe *)(local+4);
	local[6]= local[3];
	local[7]= fqv[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)UNIXREAD(ctx,2,local+6); /*unix:uread*/
	ctx->vsp=local+6;
	UWP88(ctx,0,local+6,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	w = local[2];
	local[0]= w;
BLK84:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP88(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[3];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*write-raw-image*/
static pointer F70write_raw_image(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[3]); /*open*/
	local[0]= w;
	ctx->vsp=local+1;
	w = makeclosure(codevec,quotevec,UWP90,env,argv,local);
	local[1]=(pointer)(ctx->protfp); local[2]=w;
	ctx->protfp=(struct protectframe *)(local+1);
	local[3]= local[0];
	local[4]= fqv[5];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)UNIXWRITE(ctx,2,local+3); /*unix:write*/
	ctx->vsp=local+3;
	UWP90(ctx,0,local+3,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	w = argv[1];
	local[0]= w;
BLK89:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP90(ctx,n,argv,env)
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

/*read-pbm-token*/
static pointer F71read_pbm_token(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
TAG93:
WHL94:
	local[1]= argv[0];
	local[2]= NIL;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)READCH(ctx,3,local+1); /*read-char*/
	local[0] = w;
	local[1]= local[0];
	local[2]= fqv[6];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[7]); /*member*/
	if (w==NIL) goto WHX95;
	goto WHL94;
WHX95:
	local[1]= NIL;
BLK96:
	local[1]= local[0];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)UNREADCH(ctx,2,local+1); /*unread-char*/
	local[1]= local[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)EQ(ctx,2,local+1); /*eql*/
	if (w==NIL) goto CON98;
	w = argv[1];
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK92;
	goto CON97;
CON98:
	local[1]= local[0];
	local[2]= makeint(35);
	ctx->vsp=local+3;
	w=(pointer)EQ(ctx,2,local+1); /*eql*/
	if (w==NIL) goto CON99;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)READLINE(ctx,1,local+1); /*read-line*/
	ctx->vsp=local+1;
	goto TAG93;
	goto CON97;
CON99:
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)READ(ctx,1,local+1); /*read*/
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK92;
	goto CON97;
CON100:
	local[1]= NIL;
CON97:
	w = NIL;
	local[0]= w;
BLK92:
	w = local[0];
	local[0]= w;
BLK91:
	ctx->vsp=local; return(local[0]);}

/*read-ascii-pbm*/
static pointer F72read_ascii_pbm(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= fqv[8];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
BLK101:
	ctx->vsp=local; return(local[0]);}

/*read-binary-pbm*/
static pointer F73read_binary_pbm(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= fqv[9];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
BLK102:
	ctx->vsp=local; return(local[0]);}

/*write-pgm*/
static pointer F74write_pgm(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT107;}
	local[0]= makeint(255);
ENT107:
	if (n>=4) { local[1]=(argv[3]); goto ENT106;}
	local[1]= argv[1];
	local[2]= fqv[10];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
ENT106:
	if (n>=5) { local[2]=(argv[4]); goto ENT105;}
	local[2]= argv[1];
	local[3]= fqv[11];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
ENT105:
ENT104:
	if (n>5) maerror();
	local[3]= argv[0];
	local[4]= fqv[12];
	local[5]= local[1];
	local[6]= local[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,5,local+3); /*format*/
	local[3]= argv[0];
	local[4]= fqv[5];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[1]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)UNIXWRITE(ctx,2,local+3); /*unix:write*/
	local[0]= w;
BLK103:
	ctx->vsp=local; return(local[0]);}

/*read-ascii-pgm*/
static pointer F75read_ascii_pgm(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	w = NIL;
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F71read_pbm_token(ctx,2,local+2); /*read-pbm-token*/
	local[2]= w;
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	local[4]= local[2];
	local[5]= makeint(255);
	ctx->vsp=local+6;
	w=(*ftab[3])(ctx,2,local+4,&ftab[3],fqv[13]); /*/=*/
	if (w==NIL) goto IF109;
	local[4]= fqv[14];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SIGERROR(ctx,2,local+4); /*error*/
	local[4]= w;
	goto IF110;
IF109:
	local[4]= NIL;
IF110:
	local[4]= makeint(0);
	local[5]= local[3];
WHL112:
	local[6]= local[4];
	w = local[5];
	if ((eusinteger_t)local[6] >= (eusinteger_t)w) goto WHX113;
	local[6]= argv[0];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)F71read_pbm_token(ctx,2,local+6); /*read-pbm-token*/
	local[1] = w;
	local[6]= local[1];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w==NIL) goto IF115;
	local[6]= fqv[15];
	ctx->vsp=local+7;
	w=(pointer)SIGERROR(ctx,1,local+6); /*error*/
	local[6]= w;
	goto IF116;
IF115:
	local[6]= NIL;
IF116:
	local[6]= argv[1];
	local[7]= local[4];
	w = local[1];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[7]); v=local[6];
	  v->c.str.chars[i]=intval(w);}
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[4] = w;
	goto WHL112;
WHX113:
	local[6]= NIL;
BLK114:
	w = NIL;
	local[4]= loadglobal(fqv[16]);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= local[4];
	local[6]= fqv[17];
	local[7]= argv[2];
	local[8]= argv[3];
	local[9]= argv[1];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	w = local[4];
	argv[1] = w;
	local[4]= argv[1];
	local[5]= fqv[18];
	local[6]= argv[0];
	local[7]= fqv[19];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	w = argv[1];
	local[0]= w;
BLK108:
	ctx->vsp=local; return(local[0]);}

/*read-binary-pgm*/
static pointer F76read_binary_pgm(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	w = NIL;
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= argv[0];
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)F71read_pbm_token(ctx,2,local+5); /*read-pbm-token*/
	local[5]= w;
	local[6]= local[5];
	local[7]= makeint(255);
	ctx->vsp=local+8;
	w=(*ftab[3])(ctx,2,local+6,&ftab[3],fqv[13]); /*/=*/
	if (w==NIL) goto IF119;
	local[6]= fqv[20];
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)SIGERROR(ctx,2,local+6); /*error*/
	local[6]= w;
	goto IF120;
IF119:
	local[6]= NIL;
IF120:
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,1,local+6,&ftab[4],fqv[21]); /*make-string*/
	argv[1] = w;
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)READCH(ctx,1,local+6); /*read-char*/
	local[6]= argv[1];
	local[7]= argv[0];
	local[8]= fqv[22];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= fqv[23];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[0] = w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(*ftab[5])(ctx,2,local+6,&ftab[5],fqv[24]); /*replace*/
	local[6]= argv[0];
	local[7]= fqv[22];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= fqv[25];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[1] = w;
WHL121:
	local[6]= local[1];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,2,local+6); /*<*/
	if (w==NIL) goto WHX122;
	local[6]= argv[0];
	local[7]= fqv[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= argv[1];
	local[8]= local[2];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)UNIXREAD(ctx,4,local+6); /*unix:uread*/
	local[3] = w;
	local[6]= local[3];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)LSEQP(ctx,2,local+6); /*<=*/
	if (w==NIL) goto IF124;
	local[6]= fqv[26];
	ctx->vsp=local+7;
	w=(pointer)SIGERROR(ctx,1,local+6); /*error*/
	local[6]= w;
	goto IF125;
IF124:
	local[6]= NIL;
IF125:
	local[6]= local[1];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[1] = w;
	goto WHL121;
WHX122:
	local[6]= NIL;
BLK123:
	local[6]= loadglobal(fqv[16]);
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,1,local+6); /*instantiate*/
	local[6]= w;
	local[7]= local[6];
	local[8]= fqv[17];
	local[9]= argv[2];
	local[10]= argv[3];
	local[11]= argv[1];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	w = local[6];
	argv[1] = w;
	local[6]= argv[1];
	local[7]= fqv[18];
	local[8]= argv[0];
	local[9]= fqv[19];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	w = argv[1];
	local[0]= w;
BLK118:
	ctx->vsp=local; return(local[0]);}

/*read-binary-ppm*/
static pointer F77read_binary_ppm(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= NIL;
	w = NIL;
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= argv[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F71read_pbm_token(ctx,2,local+2); /*read-pbm-token*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= local[0];
	local[7]= makeint(3);
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	local[7]= NIL;
	local[8]= local[2];
	local[9]= makeint(255);
	ctx->vsp=local+10;
	w=(*ftab[3])(ctx,2,local+8,&ftab[3],fqv[13]); /*/=*/
	if (w==NIL) goto IF128;
	local[8]= fqv[27];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)SIGERROR(ctx,2,local+8); /*error*/
	local[8]= w;
	goto IF129;
IF128:
	local[8]= NIL;
IF129:
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)READCH(ctx,1,local+8); /*read-char*/
	local[8]= argv[1];
	local[9]= argv[0];
	local[10]= fqv[22];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	local[10]= fqv[23];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[4] = w;
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(*ftab[5])(ctx,2,local+8,&ftab[5],fqv[24]); /*replace*/
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[5] = w;
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
	local[9]= makeint(3);
	ctx->vsp=local+10;
	w=(pointer)MOD(ctx,2,local+8); /*mod*/
	local[8]= w;
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(pointer)GREATERP(ctx,2,local+8); /*>*/
	if (w==NIL) goto IF130;
	local[8]= makeint(3);
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	local[9]= w;
	local[10]= makeint(3);
	ctx->vsp=local+11;
	w=(pointer)MOD(ctx,2,local+9); /*mod*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[7] = w;
	local[8]= argv[0];
	local[9]= fqv[4];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= argv[1];
	local[10]= local[7];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)UNIXREAD(ctx,4,local+8); /*unix:uread*/
	local[8]= local[5];
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[5] = w;
	local[8]= local[5];
	goto IF131;
IF130:
	local[8]= NIL;
IF131:
WHL132:
	local[8]= argv[0];
	local[9]= fqv[4];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= argv[1];
	local[10]= local[6];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)MINUS(ctx,2,local+10); /*-*/
	local[10]= w;
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)UNIXREAD(ctx,4,local+8); /*unix:uread*/
	local[7] = w;
	local[8]= local[7];
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(pointer)GREATERP(ctx,2,local+8); /*>*/
	if (w==NIL) goto WHX133;
	local[8]= local[5];
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[5] = w;
	goto WHL132;
WHX133:
	local[8]= NIL;
BLK134:
	local[8]= loadglobal(fqv[28]);
	ctx->vsp=local+9;
	w=(pointer)INSTANTIATE(ctx,1,local+8); /*instantiate*/
	local[8]= w;
	local[9]= local[8];
	local[10]= fqv[17];
	local[11]= argv[2];
	local[12]= argv[3];
	local[13]= argv[1];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,5,local+9); /*send*/
	w = local[8];
	local[3] = w;
	local[8]= local[3];
	local[9]= fqv[18];
	local[10]= argv[0];
	local[11]= fqv[19];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	w = local[3];
	local[0]= w;
BLK127:
	ctx->vsp=local; return(local[0]);}

/*read-ascii-ppm*/
static pointer F78read_ascii_ppm(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= NIL;
	w = NIL;
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= NIL;
	local[3]= argv[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)F71read_pbm_token(ctx,2,local+3); /*read-pbm-token*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	local[5]= NIL;
	local[6]= local[3];
	local[7]= makeint(255);
	ctx->vsp=local+8;
	w=(*ftab[3])(ctx,2,local+6,&ftab[3],fqv[13]); /*/=*/
	if (w==NIL) goto IF137;
	local[6]= fqv[29];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SIGERROR(ctx,2,local+6); /*error*/
	local[6]= w;
	goto IF138;
IF137:
	local[6]= NIL;
IF138:
	local[6]= makeint(0);
	local[7]= local[4];
WHL140:
	local[8]= local[6];
	w = local[7];
	if ((eusinteger_t)local[8] >= (eusinteger_t)w) goto WHX141;
	local[8]= local[6];
	{ eusinteger_t i,j;
		j=intval(makeint(3)); i=intval(local[8]);
		local[8]=(makeint(i * j));}
	local[5] = local[8];
	local[8]= argv[0];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)F71read_pbm_token(ctx,2,local+8); /*read-pbm-token*/
	local[2] = w;
	local[8]= local[2];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)EQ(ctx,2,local+8); /*eql*/
	if (w==NIL) goto IF143;
	local[8]= fqv[30];
	ctx->vsp=local+9;
	w=(pointer)SIGERROR(ctx,1,local+8); /*error*/
	local[8]= w;
	goto IF144;
IF143:
	local[8]= NIL;
IF144:
	local[8]= argv[1];
	local[9]= local[5];
	w = local[2];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[9]); v=local[8];
	  v->c.str.chars[i]=intval(w);}
	local[8]= argv[0];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)F71read_pbm_token(ctx,2,local+8); /*read-pbm-token*/
	local[2] = w;
	local[8]= local[2];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)EQ(ctx,2,local+8); /*eql*/
	if (w==NIL) goto IF145;
	local[8]= fqv[31];
	ctx->vsp=local+9;
	w=(pointer)SIGERROR(ctx,1,local+8); /*error*/
	local[8]= w;
	goto IF146;
IF145:
	local[8]= NIL;
IF146:
	local[8]= argv[1];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	local[9]= w;
	w = local[2];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[9]); v=local[8];
	  v->c.str.chars[i]=intval(w);}
	local[8]= argv[0];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)F71read_pbm_token(ctx,2,local+8); /*read-pbm-token*/
	local[2] = w;
	local[8]= local[2];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)EQ(ctx,2,local+8); /*eql*/
	if (w==NIL) goto IF147;
	local[8]= fqv[32];
	ctx->vsp=local+9;
	w=(pointer)SIGERROR(ctx,1,local+8); /*error*/
	local[8]= w;
	goto IF148;
IF147:
	local[8]= NIL;
IF148:
	local[8]= argv[1];
	local[9]= local[5];
	local[10]= makeint(2);
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	w = local[2];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[9]); v=local[8];
	  v->c.str.chars[i]=intval(w);}
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[6] = w;
	goto WHL140;
WHX141:
	local[8]= NIL;
BLK142:
	w = NIL;
	local[6]= loadglobal(fqv[28]);
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,1,local+6); /*instantiate*/
	local[6]= w;
	local[7]= local[6];
	local[8]= fqv[17];
	local[9]= argv[2];
	local[10]= argv[3];
	local[11]= argv[1];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	w = local[6];
	local[0] = w;
	local[6]= local[0];
	local[7]= fqv[18];
	local[8]= argv[0];
	local[9]= fqv[19];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	w = local[0];
	local[0]= w;
BLK136:
	ctx->vsp=local; return(local[0]);}

/*write-ppm*/
static pointer F79write_ppm(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= fqv[33];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[1] = w;
	local[0]= argv[0];
	local[1]= fqv[34];
	local[2]= argv[1];
	local[3]= fqv[10];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[1];
	local[4]= fqv[11];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= makeint(255);
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= argv[0];
	local[1]= fqv[5];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[1];
	local[2]= fqv[35];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)UNIXWRITE(ctx,2,local+0); /*unix:write*/
	local[0]= w;
BLK150:
	ctx->vsp=local; return(local[0]);}

/*read-pnm*/
static pointer F80read_pnm(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT153;}
	local[0]= NIL;
ENT153:
ENT152:
	if (n>2) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)READCH(ctx,1,local+1); /*read-char*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	w = NIL;
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= NIL;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)CHUPCASE(ctx,1,local+6); /*char-upcase*/
	local[6]= w;
	local[7]= makeint(80);
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w!=NIL) goto IF154;
	local[6]= fqv[36];
	ctx->vsp=local+7;
	w=(pointer)SIGERROR(ctx,1,local+6); /*error*/
	local[6]= w;
	goto IF155;
IF154:
	local[6]= NIL;
IF155:
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)READCH(ctx,1,local+6); /*read-char*/
	local[1] = w;
	local[6]= argv[0];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)F71read_pbm_token(ctx,2,local+6); /*read-pbm-token*/
	local[2] = w;
	local[6]= argv[0];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)F71read_pbm_token(ctx,2,local+6); /*read-pbm-token*/
	local[3] = w;
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[5] = w;
	local[6]= local[5];
	local[7]= makeint(4096);
	{ eusinteger_t i,j;
		j=intval(makeint(4096)); i=intval(local[7]);
		local[7]=(makeint(i * j));}
	ctx->vsp=local+8;
	w=(pointer)GREATERP(ctx,2,local+6); /*>*/
	if (w!=NIL) goto OR158;
	local[6]= local[5];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,2,local+6); /*<*/
	if (w!=NIL) goto OR158;
	goto IF156;
OR158:
	local[6]= fqv[37];
	ctx->vsp=local+7;
	w=(pointer)SIGERROR(ctx,1,local+6); /*error*/
	local[6]= w;
	goto IF157;
IF156:
	local[6]= NIL;
IF157:
	if (local[0]!=NIL) goto IF159;
	local[6]= local[1];
	local[7]= local[6];
	w = fqv[38];
	if (memq(local[7],w)==NIL) goto IF162;
	local[7]= local[5];
	local[8]= makeint(7);
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	local[8]= makeint(8);
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[4])(ctx,1,local+7,&ftab[4],fqv[21]); /*make-string*/
	local[0] = w;
	local[7]= local[0];
	goto IF163;
IF162:
	local[7]= local[6];
	w = fqv[39];
	if (memq(local[7],w)==NIL) goto IF164;
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(*ftab[4])(ctx,1,local+7,&ftab[4],fqv[21]); /*make-string*/
	local[0] = w;
	local[7]= local[0];
	goto IF165;
IF164:
	local[7]= local[6];
	w = fqv[40];
	if (memq(local[7],w)==NIL) goto IF166;
	local[7]= local[5];
	local[8]= makeint(3);
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[4])(ctx,1,local+7,&ftab[4],fqv[21]); /*make-string*/
	local[0] = w;
	local[7]= local[0];
	goto IF167;
IF166:
	local[7]= NIL;
IF167:
IF165:
IF163:
	w = local[7];
	local[6]= w;
	goto IF160;
IF159:
	local[6]= NIL;
IF160:
	local[6]= local[1];
	local[7]= local[6];
	if (fqv[41]!=local[7]) goto IF169;
	local[7]= argv[0];
	local[8]= local[0];
	local[9]= local[2];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)F72read_ascii_pbm(ctx,4,local+7); /*read-ascii-pbm*/
	local[7]= w;
	goto IF170;
IF169:
	local[7]= local[6];
	if (fqv[42]!=local[7]) goto IF171;
	local[7]= argv[0];
	local[8]= local[0];
	local[9]= local[2];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)F75read_ascii_pgm(ctx,4,local+7); /*read-ascii-pgm*/
	local[7]= w;
	goto IF172;
IF171:
	local[7]= local[6];
	if (fqv[43]!=local[7]) goto IF173;
	local[7]= argv[0];
	local[8]= local[0];
	local[9]= local[2];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)F78read_ascii_ppm(ctx,4,local+7); /*read-ascii-ppm*/
	local[7]= w;
	goto IF174;
IF173:
	local[7]= local[6];
	if (fqv[44]!=local[7]) goto IF175;
	local[7]= argv[0];
	local[8]= local[0];
	local[9]= local[2];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)F73read_binary_pbm(ctx,4,local+7); /*read-binary-pbm*/
	local[7]= w;
	goto IF176;
IF175:
	local[7]= local[6];
	if (fqv[45]!=local[7]) goto IF177;
	local[7]= argv[0];
	local[8]= local[0];
	local[9]= local[2];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)F76read_binary_pgm(ctx,4,local+7); /*read-binary-pgm*/
	local[7]= w;
	goto IF178;
IF177:
	local[7]= local[6];
	if (fqv[46]!=local[7]) goto IF179;
	local[7]= argv[0];
	local[8]= local[0];
	local[9]= local[2];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)F77read_binary_ppm(ctx,4,local+7); /*read-binary-ppm*/
	local[7]= w;
	goto IF180;
IF179:
	if (T==NIL) goto IF181;
	local[7]= fqv[47];
	ctx->vsp=local+8;
	w=(pointer)SIGERROR(ctx,1,local+7); /*error*/
	local[7]= w;
	goto IF182;
IF181:
	local[7]= NIL;
IF182:
IF180:
IF178:
IF176:
IF174:
IF172:
IF170:
	w = local[7];
	local[0]= w;
BLK151:
	ctx->vsp=local; return(local[0]);}

/*read-pnm-file*/
static pointer F81read_pnm_file(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT185;}
	local[0]= NIL;
ENT185:
ENT184:
	if (n>2) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,1,local+1,&ftab[1],fqv[3]); /*open*/
	local[1]= w;
	ctx->vsp=local+2;
	w = makeclosure(codevec,quotevec,UWP186,env,argv,local);
	local[2]=(pointer)(ctx->protfp); local[3]=w;
	ctx->protfp=(struct protectframe *)(local+2);
	local[4]= local[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)F80read_pnm(ctx,2,local+4); /*read-pnm*/
	ctx->vsp=local+4;
	UWP186(ctx,0,local+4,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK183:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP186(ctx,n,argv,env)
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

/*write-pnm*/
static pointer F82write_pnm(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= loadglobal(fqv[48]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON189;
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F79write_ppm(ctx,2,local+0); /*write-ppm*/
	local[0]= w;
	goto CON188;
CON189:
	local[0]= argv[1];
	local[1]= loadglobal(fqv[48]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON190;
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F79write_ppm(ctx,2,local+0); /*write-ppm*/
	local[0]= w;
	goto CON188;
CON190:
	local[0]= argv[1];
	local[1]= loadglobal(fqv[49]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON191;
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F79write_ppm(ctx,2,local+0); /*write-ppm*/
	local[0]= w;
	goto CON188;
CON191:
	local[0]= argv[1];
	local[1]= loadglobal(fqv[16]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON192;
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F74write_pgm(ctx,2,local+0); /*write-pgm*/
	local[0]= w;
	goto CON188;
CON192:
	local[0]= NIL;
CON188:
	w = local[0];
	local[0]= w;
BLK187:
	ctx->vsp=local; return(local[0]);}

/*write-pnm-file*/
static pointer F83write_pnm_file(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[50];
	local[2]= fqv[51];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,3,local+0,&ftab[1],fqv[3]); /*open*/
	local[0]= w;
	ctx->vsp=local+1;
	w = makeclosure(codevec,quotevec,UWP194,env,argv,local);
	local[1]=(pointer)(ctx->protfp); local[2]=w;
	ctx->protfp=(struct protectframe *)(local+1);
	local[3]= local[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)F82write_pnm(ctx,2,local+3); /*write-pnm*/
	ctx->vsp=local+3;
	UWP194(ctx,0,local+3,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK193:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP194(ctx,n,argv,env)
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

/* initializer*/
pointer ___pbmfile(ctx,n,argv,env)
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
	local[0]= fqv[52];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w!=NIL) goto IF195;
	local[0]= fqv[53];
	local[1]= fqv[54];
	local[2]= fqv[55];
	ctx->vsp=local+3;
	w=(*ftab[6])(ctx,3,local+0,&ftab[6],fqv[56]); /*make-package*/
	local[0]= w;
	goto IF196;
IF195:
	local[0]= NIL;
IF196:
	local[0]= fqv[57];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF197;
	local[0]= fqv[58];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[59],w);
	goto IF198;
IF197:
	local[0]= fqv[60];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF198:
	local[0]= fqv[61];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[62],module,F69read_raw_image,fqv[63]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[64],module,F70write_raw_image,fqv[65]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[66],module,F71read_pbm_token,fqv[67]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[68],module,F72read_ascii_pbm,fqv[69]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[70],module,F73read_binary_pbm,fqv[71]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[72],module,F74write_pgm,fqv[73]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[74],module,F75read_ascii_pgm,fqv[75]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[76],module,F76read_binary_pgm,fqv[77]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[78],module,F77read_binary_ppm,fqv[79]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[80],module,F78read_ascii_ppm,fqv[81]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[82],module,F79write_ppm,fqv[83]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[84],module,F80read_pnm,fqv[85]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[86],module,F81read_pnm_file,fqv[87]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[88],module,F82write_pnm,fqv[89]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[90],module,F83write_pnm_file,fqv[91]);
	local[0]= fqv[92];
	local[1]= fqv[93];
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,2,local+0,&ftab[7],fqv[94]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<8; i++) ftab[i]=fcallx;
}
