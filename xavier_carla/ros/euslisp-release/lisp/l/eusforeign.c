/* ./eusforeign.c :  entry=eusforeign */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "eusforeign.h"
#pragma init (register_eusforeign)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___eusforeign();
extern pointer build_quote_vector();
static int register_eusforeign()
  { add_module_initializer("___eusforeign", ___eusforeign);}

static pointer F63296make_foreign_code();
static pointer F63298load_foreign();
static pointer F63300byte_string();
static pointer F63302pod_address();
static pointer F63304byte_size();
static pointer F63341make_foreign_string();

/*:find*/
static pointer M63386load_module_find(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[0]); /*system::find-entry*/
	local[0]= w;
BLK63387:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M63426foreign_code_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT63431;}
	local[0]= NIL;
ENT63431:
	if (n>=5) { local[1]=(argv[4]); goto ENT63430;}
	local[1]= fqv[1];
ENT63430:
ENT63429:
	if (n>5) maerror();
	argv[0]->c.obj.iv[0] = makeint(0);
	argv[0]->c.obj.iv[1] = NIL;
	w = argv[2];
	if (!iscons(w)) goto IF63461;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	goto IF63462;
IF63461:
	local[2]= argv[2];
IF63462:
	argv[0]->c.obj.iv[3] = local[2];
	w = argv[2];
	if (!iscons(w)) goto IF63474;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	goto IF63475;
IF63474:
	local[2]= NIL;
IF63475:
	argv[0]->c.obj.iv[4] = local[2];
	argv[0]->c.obj.iv[5] = local[0];
	argv[0]->c.obj.iv[6] = local[1];
	argv[0]->c.obj.iv[2] = makeint(0);
	w = argv[0];
	local[0]= w;
BLK63427:
	ctx->vsp=local; return(local[0]);}

/*make-foreign-code*/
static pointer F63296make_foreign_code(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT63507;}
	local[0]= NIL;
ENT63507:
	if (n>=3) { local[1]=(argv[2]); goto ENT63506;}
	local[1]= fqv[1];
ENT63506:
	if (n>=4) { local[2]=(argv[3]); goto ENT63505;}
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,0,local+2,&ftab[1],fqv[2]); /*system::sysmod*/
	local[2]= w;
ENT63505:
ENT63504:
	if (n>4) maerror();
	w = argv[0];
	local[3]= (isnum(w)?T:NIL);
	if (local[3]!=NIL) goto CON63534;
CON63536:
	local[3]= argv[0];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,2,local+3,&ftab[0],fqv[0]); /*system::find-entry*/
	if (w==NIL) goto CON63543;
	local[3]= argv[0];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,2,local+3,&ftab[2],fqv[3]); /*system::find-entry2*/
	argv[0] = w;
	local[3]= argv[0];
	goto CON63534;
CON63543:
	local[3]= fqv[4];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,2,local+3); /*error*/
	local[3]= w;
	goto CON63534;
CON63561:
	local[3]= NIL;
CON63534:
	local[3]= loadglobal(fqv[5]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[6];
	local[6]= argv[0];
	local[7]= local[0];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	w = local[3];
	local[0]= w;
BLK63502:
	ctx->vsp=local; return(local[0]);}

/*load-foreign*/
static pointer F63298load_foreign(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[7];
	local[2]= fqv[8];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,3,local+0,&ftab[3],fqv[9]); /*load*/
	local[0]= w;
BLK63598:
	ctx->vsp=local; return(local[0]);}

/*defforeign*/
static pointer F63615(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= fqv[10];
	local[1]= fqv[11];
	local[2]= fqv[12];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[13];
	local[3]= argv[2];
	local[4]= fqv[12];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[12];
	local[6]= argv[4];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= argv[1];
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
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK63616:
	ctx->vsp=local; return(local[0]);}

/*defvoidforeigns*/
static pointer F63689(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST63692:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[14];
	local[2]= fqv[15];
	local[3]= fqv[12];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[10];
	local[4]= fqv[11];
	local[5]= fqv[16];
	local[6]= fqv[17];
	local[7]= fqv[15];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
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
	local[5]= fqv[13];
	local[6]= fqv[15];
	local[7]= fqv[18];
	local[8]= fqv[1];
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
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
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK63690:
	ctx->vsp=local; return(local[0]);}

/*byte-string*/
static pointer F63300byte_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST63780:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= fqv[19];
	local[3]= fqv[20];
	local[4]= fqv[21];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,5,local+1,&ftab[4],fqv[22]); /*make-array*/
	local[0]= w;
BLK63778:
	ctx->vsp=local; return(local[0]);}

/*:pod-address*/
static pointer M63825foreign_pod_pod_address(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(16);
	local[1]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+2;
	w=(pointer)ADDRESS(ctx,1,local+1); /*system:address*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
BLK63826:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M63847foreign_pod_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)ADDRESS(ctx,1,local+0); /*system:address*/
	local[0]= w;
	local[1]= fqv[23];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)LISTP(ctx,1,local+1); /*listp*/
	if (w==NIL) goto CON63884;
	w=argv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	if (fqv[24]!=local[1]) goto IF63892;
	local[1]= fqv[25];
	local[2]= makeint(4);
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)NTHCDR(ctx,2,local+2); /*nthcdr*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPEND(ctx,2,local+1); /*append*/
	argv[4] = w;
	local[1]= argv[4];
	goto IF63893;
IF63892:
	local[1]= NIL;
IF63893:
	goto CON63882;
CON63884:
	local[1]= argv[4];
	local[2]= loadglobal(fqv[26]);
	ctx->vsp=local+3;
	w=(pointer)DERIVEDP(ctx,2,local+1); /*derivedp*/
	if (w==NIL) goto CON63915;
	local[1]= loadglobal(fqv[27]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= makeint(0);
	*(ovafptr(local[1],fqv[28])) = local[2];
	local[2]= *(ovafptr(argv[4],fqv[29]));
	*(ovafptr(local[1],fqv[29])) = local[2];
	local[2]= *(ovafptr(argv[4],fqv[30]));
	*(ovafptr(local[1],fqv[30])) = local[2];
	local[2]= *(ovafptr(argv[4],fqv[31]));
	local[3]= local[2];
	*(ovafptr(local[1],fqv[31])) = local[3];
	w = local[1];
	argv[4] = w;
	local[1]= argv[4];
	goto CON63882;
CON63915:
	local[1]= NIL;
CON63882:
	argv[0]->c.obj.iv[3] = argv[4];
	argv[0]->c.obj.iv[7] = argv[2];
	argv[0]->c.obj.iv[8] = argv[3];
	w = argv[0];
	local[0]= w;
BLK63848:
	ctx->vsp=local; return(local[0]);}

/*defun-c-callable*/
static pointer F63985(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST63988:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO64009,env,argv,local);
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO64018,env,argv,local);
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(*ftab[5])(ctx,1,local+3,&ftab[5],fqv[32]); /*keywordp*/
	if (w==NIL) goto IF64026;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	goto IF64027;
IF64026:
	local[3]= fqv[1];
IF64027:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(*ftab[5])(ctx,1,local+4,&ftab[5],fqv[32]); /*keywordp*/
	if (w==NIL) goto IF64049;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	goto IF64050;
IF64049:
	local[4]= local[0];
IF64050:
	local[5]= fqv[33];
	local[6]= fqv[34];
	local[7]= fqv[12];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[35];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[36];
	local[8]= fqv[37];
	local[9]= fqv[38];
	local[10]= fqv[39];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[9]= w;
	local[10]= fqv[16];
	local[11]= fqv[12];
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(*ftab[6])(ctx,1,local+12,&ftab[6],fqv[40]); /*string*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[35];
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
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[6];
	local[10]= fqv[12];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[12];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[41];
	local[13]= fqv[42];
	local[14]= local[2];
	w = local[4];
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
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
	w = cons(ctx,local[5],w);
	local[0]= w;
BLK63986:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO64009(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!!iscons(w)) goto IF64199;
	local[0]= fqv[1];
	goto IF64200;
IF64199:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
IF64200:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO64018(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!!iscons(w)) goto IF64224;
	local[0]= argv[0];
	goto IF64225;
IF64224:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
IF64225:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*pod-address*/
static pointer F63302pod_address(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[43];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK64237:
	ctx->vsp=local; return(local[0]);}

/*byte-size*/
static pointer F63304byte_size(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[44]);
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK64254:
	ctx->vsp=local; return(local[0]);}

/*:slotlist*/
static pointer M64322cstructclass_slotlist(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT64326;}
	local[0]= NIL;
ENT64326:
ENT64325:
	if (n>3) maerror();
	if (local[0]!=NIL) goto IF64342;
	w = argv[0]->c.obj.iv[10];
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK64323;
	goto IF64343;
IF64342:
	local[1]= NIL;
IF64343:
	argv[0]->c.obj.iv[10] = NIL;
	local[1]= makeint(0);
	local[2]= makeint(0);
	local[3]= NIL;
	local[4]= NIL;
	local[5]= makeint(1);
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= local[0];
WHL64406:
	if (local[10]==NIL) goto WHX64407;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	w = local[3];
	if (!issymbol(w)) goto CON64470;
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(*ftab[5])(ctx,1,local+11,&ftab[5],fqv[32]); /*keywordp*/
	if (w!=NIL) goto CON64470;
	local[11]= NIL;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	ctx->vsp=local+13;
	w=(pointer)SYMVALUE(ctx,1,local+12); /*symbol-value*/
	local[12]= w;
	local[13]= fqv[45];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[12]= w;
WHL64511:
	if (local[12]==NIL) goto WHX64512;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12] = (w)->c.cons.cdr;
	w = local[13];
	local[11] = w;
	local[13]= loadglobal(fqv[40]);
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	ctx->vsp=local+15;
	w=(*ftab[6])(ctx,1,local+14,&ftab[6],fqv[40]); /*string*/
	local[14]= w;
	local[15]= fqv[46];
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	ctx->vsp=local+17;
	w=(*ftab[6])(ctx,1,local+16,&ftab[6],fqv[40]); /*string*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)CONCATENATE(ctx,4,local+13); /*concatenate*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)INTERN(ctx,1,local+13); /*intern*/
	local[13]= w;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	w = local[8];
	ctx->vsp=local+14;
	local[8] = cons(ctx,local[13],w);
	goto WHL64511;
WHX64512:
	local[13]= NIL;
BLK64513:
	w = NIL;
	local[11]= w;
	goto CON64468;
CON64470:
	local[11]= local[9];
	w = local[8];
	ctx->vsp=local+12;
	local[8] = cons(ctx,local[11],w);
	local[11]= local[8];
	goto CON64468;
CON64600:
	local[11]= NIL;
CON64468:
	goto WHL64406;
WHX64407:
	local[11]= NIL;
BLK64408:
	w = NIL;
	local[9]= local[8];
	ctx->vsp=local+10;
	w=(pointer)NREVERSE(ctx,1,local+9); /*nreverse*/
	local[8] = w;
	local[9]= NIL;
	local[10]= local[8];
WHL64645:
	if (local[10]==NIL) goto WHX64646;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)F63304byte_size(ctx,1,local+11); /*byte-size*/
	local[4] = w;
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(*ftab[5])(ctx,1,local+11,&ftab[5],fqv[32]); /*keywordp*/
	if (w!=NIL) goto IF64729;
	local[11]= fqv[47];
	ctx->vsp=local+12;
	w=(pointer)SIGERROR(ctx,1,local+11); /*error*/
	local[11]= w;
	goto IF64730;
IF64729:
	local[11]= NIL;
IF64730:
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	if (fqv[48]!=local[11]) goto IF64744;
	local[3] = fqv[49];
	local[4] = makeint(8);
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[11];
	local[11]= w;
	goto IF64745;
IF64744:
	local[11]= NIL;
IF64745:
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto IF64807;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	goto IF64808;
IF64807:
	local[11]= makeint(1);
IF64808:
	local[5] = local[11];
	local[11]= local[4];
	local[12]= local[5];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[2] = w;
	local[11]= local[1];
	local[12]= local[4];
	local[13]= makeint(-1);
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,3,local+11); /*+*/
	local[11]= w;
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(pointer)QUOTIENT(ctx,2,local+11); /*/*/
	local[11]= w;
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[1] = w;
	local[11]= local[7];
	local[12]= local[3];
	local[13]= local[5];
	local[14]= local[4];
	local[15]= local[1];
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,6,local+11); /*list*/
	local[11]= w;
	w = argv[0]->c.obj.iv[10];
	ctx->vsp=local+12;
	argv[0]->c.obj.iv[10] = cons(ctx,local[11],w);
	local[11]= local[1];
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[1] = w;
	goto WHL64645;
WHX64646:
	local[11]= NIL;
BLK64647:
	w = NIL;
	local[9]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+10;
	w=(pointer)NREVERSE(ctx,1,local+9); /*nreverse*/
	argv[0]->c.obj.iv[10] = w;
	argv[0]->c.obj.iv[9] = local[1];
	w = argv[0]->c.obj.iv[10];
	local[0]= w;
BLK64323:
	ctx->vsp=local; return(local[0]);}

/*:size*/
static pointer M64912cstructclass_size(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[9];
	local[0]= w;
BLK64913:
	ctx->vsp=local; return(local[0]);}

/*:slot*/
static pointer M64928cstructclass_slot(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[2]==NIL) goto IF64943;
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	local[0]= w;
	goto IF64944;
IF64943:
	w=argv[0]->c.obj.iv[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
IF64944:
	w = local[0];
	local[0]= w;
BLK64929:
	ctx->vsp=local; return(local[0]);}

/*:offset*/
static pointer M64959cstructclass_offset(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT64963;}
	local[0]= NIL;
ENT64963:
ENT64962:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[50];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	if (local[1]!=NIL) goto IF64998;
	local[2]= fqv[51];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,2,local+2); /*error*/
	local[2]= w;
	goto IF64999;
IF64998:
	local[2]= NIL;
IF64999:
	if (local[0]==NIL) goto CON65013;
	local[2]= local[0];
	local[3]= local[1];
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)GREQP(ctx,2,local+2); /*>=*/
	if (w==NIL) goto IF65019;
	local[2]= fqv[52];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,1,local+2); /*error*/
	local[2]= w;
	goto IF65020;
IF65019:
	local[2]= NIL;
IF65020:
	local[2]= local[1];
	local[3]= makeint(4);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	local[3]= local[0];
	local[4]= local[1];
	local[5]= makeint(3);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	goto CON65011;
CON65013:
	local[2]= local[1];
	local[3]= makeint(4);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	goto CON65011;
CON65045:
	local[2]= NIL;
CON65011:
	w = local[2];
	local[0]= w;
BLK64960:
	ctx->vsp=local; return(local[0]);}

/*:access*/
static pointer M65054cstructclass_access(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT65058;}
	local[0]= NIL;
ENT65058:
ENT65057:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[50];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= NIL;
	if (local[1]!=NIL) goto IF65096;
	local[3]= fqv[53];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
	goto IF65097;
IF65096:
	local[3]= NIL;
IF65097:
	if (local[0]==NIL) goto CON65110;
	local[3]= local[0];
	local[4]= local[1];
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)GREQP(ctx,2,local+3); /*>=*/
	if (w==NIL) goto IF65116;
	local[3]= fqv[54];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
	goto IF65117;
IF65116:
	local[3]= NIL;
IF65117:
	local[3]= local[1];
	local[4]= makeint(4);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	local[4]= local[0];
	local[5]= local[1];
	local[6]= makeint(3);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[2] = w;
	local[3]= local[2];
	goto CON65108;
CON65110:
	local[3]= local[1];
	local[4]= makeint(4);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[2] = w;
	local[3]= local[2];
	goto CON65108;
CON65147:
	local[3]= NIL;
CON65108:
	local[3]= local[1];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[0]= w;
BLK65055:
	ctx->vsp=local; return(local[0]);}

/*:get*/
static pointer M65183cstruct_get(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT65187;}
	local[0]= NIL;
ENT65187:
ENT65186:
	if (n>4) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)GETCLASS(ctx,1,local+1); /*class*/
	local[1]= w;
	local[2]= fqv[55];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)PEEK(ctx,3,local+2); /*system:peek*/
	local[0]= w;
BLK65184:
	ctx->vsp=local; return(local[0]);}

/*:set*/
static pointer M65241cstruct_set(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT65245;}
	local[0]= NIL;
ENT65245:
ENT65244:
	if (n>5) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)GETCLASS(ctx,1,local+1); /*class*/
	local[1]= w;
	local[2]= fqv[55];
	local[3]= argv[3];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= argv[0];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)POKE(ctx,4,local+2); /*system:poke*/
	local[0]= w;
BLK65242:
	ctx->vsp=local; return(local[0]);}

/*defcstruct*/
static pointer F65303(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST65306:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= makeint(0);
	local[8]= NIL;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= NIL;
	local[15]= NIL;
	local[16]= NIL;
	local[17]= argv[0];
	ctx->vsp=local+18;
	w=(*ftab[6])(ctx,1,local+17,&ftab[6],fqv[40]); /*string*/
	local[17]= w;
	local[18]= fqv[56];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	if (fqv[57]!=local[19]) goto IF65369;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18] = (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	local[19]= local[0];
	goto IF65370;
IF65369:
	local[19]= NIL;
IF65370:
	local[19]= NIL;
	local[20]= local[0];
WHL65427:
	if (local[20]==NIL) goto WHX65428;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20] = (w)->c.cons.cdr;
	w = local[21];
	local[19] = w;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.car;
	w = local[6];
	if (!issymbol(w)) goto IF65489;
	local[21]= local[6];
	ctx->vsp=local+22;
	w=(*ftab[5])(ctx,1,local+21,&ftab[5],fqv[32]); /*keywordp*/
	if (w!=NIL) goto IF65489;
	local[21]= NIL;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	ctx->vsp=local+23;
	w=(pointer)SYMVALUE(ctx,1,local+22); /*symbol-value*/
	local[22]= w;
	local[23]= fqv[45];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,2,local+22); /*send*/
	local[22]= w;
WHL65530:
	if (local[22]==NIL) goto WHX65531;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22] = (w)->c.cons.cdr;
	w = local[23];
	local[21] = w;
	local[23]= loadglobal(fqv[40]);
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24]= (w)->c.cons.car;
	ctx->vsp=local+25;
	w=(*ftab[6])(ctx,1,local+24,&ftab[6],fqv[40]); /*string*/
	local[24]= w;
	local[25]= fqv[58];
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	ctx->vsp=local+27;
	w=(*ftab[6])(ctx,1,local+26,&ftab[6],fqv[40]); /*string*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)CONCATENATE(ctx,4,local+23); /*concatenate*/
	local[23]= w;
	ctx->vsp=local+24;
	w=(pointer)INTERN(ctx,1,local+23); /*intern*/
	local[23]= w;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24]= (w)->c.cons.car;
	ctx->vsp=local+25;
	w=(pointer)LIST(ctx,2,local+23); /*list*/
	local[23]= w;
	w = local[11];
	ctx->vsp=local+24;
	local[11] = cons(ctx,local[23],w);
	goto WHL65530;
WHX65531:
	local[23]= NIL;
BLK65532:
	w = NIL;
	local[21]= w;
	goto IF65490;
IF65489:
	local[21]= local[19];
	w = local[11];
	ctx->vsp=local+22;
	local[11] = cons(ctx,local[21],w);
	local[21]= local[11];
IF65490:
	goto WHL65427;
WHX65428:
	local[21]= NIL;
BLK65429:
	w = NIL;
	local[19]= NIL;
	local[20]= local[11];
	ctx->vsp=local+21;
	w=(pointer)NREVERSE(ctx,1,local+20); /*nreverse*/
	local[20]= w;
WHL65654:
	if (local[20]==NIL) goto WHX65655;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20] = (w)->c.cons.cdr;
	w = local[21];
	local[19] = w;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	ctx->vsp=local+22;
	w=(*ftab[6])(ctx,1,local+21,&ftab[6],fqv[40]); /*string*/
	local[2] = w;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.car;
	local[21]= loadglobal(fqv[40]);
	local[22]= local[17];
	local[23]= fqv[59];
	local[24]= local[2];
	ctx->vsp=local+25;
	w=(pointer)CONCATENATE(ctx,4,local+21); /*concatenate*/
	local[16] = w;
	local[21]= local[16];
	ctx->vsp=local+22;
	w=(pointer)INTERN(ctx,1,local+21); /*intern*/
	local[14] = w;
	local[21]= loadglobal(fqv[40]);
	local[22]= fqv[60];
	local[23]= local[16];
	ctx->vsp=local+24;
	w=(pointer)CONCATENATE(ctx,3,local+21); /*concatenate*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)INTERN(ctx,1,local+21); /*intern*/
	local[15] = w;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19] = (w)->c.cons.cdr;
	if (local[19]!=NIL) goto CON65756;
	local[21]= local[6];
	ctx->vsp=local+22;
	w=(pointer)F63304byte_size(ctx,1,local+21); /*byte-size*/
	local[9] = w;
	local[21]= local[7];
	local[22]= local[9];
	local[23]= makeint(-1);
	ctx->vsp=local+24;
	w=(pointer)PLUS(ctx,3,local+21); /*+*/
	local[21]= w;
	local[22]= local[9];
	ctx->vsp=local+23;
	w=(pointer)QUOTIENT(ctx,2,local+21); /*/*/
	local[21]= w;
	local[22]= local[9];
	ctx->vsp=local+23;
	w=(pointer)TIMES(ctx,2,local+21); /***/
	local[7] = w;
	local[21]= fqv[61];
	local[22]= local[14];
	local[23]= fqv[62];
	ctx->vsp=local+24;
	w=(pointer)LIST(ctx,1,local+23); /*list*/
	local[23]= w;
	local[24]= fqv[63];
	local[25]= fqv[62];
	local[26]= local[7];
	local[27]= local[6];
	ctx->vsp=local+28;
	w=(pointer)LIST(ctx,1,local+27); /*list*/
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
	w = cons(ctx,local[22],w);
	ctx->vsp=local+22;
	local[3] = cons(ctx,local[21],w);
	local[21]= fqv[64];
	local[22]= local[14];
	local[23]= local[15];
	ctx->vsp=local+24;
	w=(pointer)LIST(ctx,1,local+23); /*list*/
	ctx->vsp=local+23;
	w = cons(ctx,local[22],w);
	ctx->vsp=local+22;
	local[4] = cons(ctx,local[21],w);
	local[21]= fqv[61];
	local[22]= local[15];
	local[23]= fqv[62];
	local[24]= fqv[65];
	ctx->vsp=local+25;
	w=(pointer)LIST(ctx,1,local+24); /*list*/
	ctx->vsp=local+24;
	local[23]= cons(ctx,local[23],w);
	local[24]= fqv[66];
	local[25]= fqv[65];
	local[26]= fqv[62];
	local[27]= local[7];
	local[28]= local[6];
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
	w = cons(ctx,local[22],w);
	ctx->vsp=local+22;
	local[5] = cons(ctx,local[21],w);
	local[21]= local[5];
	goto CON65754;
CON65756:
	local[12] = local[6];
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	if (fqv[48]!=local[21]) goto IF65889;
	local[12] = fqv[67];
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19] = (w)->c.cons.cdr;
	w = local[21];
	local[21]= w;
	goto IF65890;
IF65889:
	local[21]= NIL;
IF65890:
	local[21]= local[12];
	ctx->vsp=local+22;
	w=(pointer)F63304byte_size(ctx,1,local+21); /*byte-size*/
	local[13] = w;
	local[21]= local[13];
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto IF65957;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	goto IF65958;
IF65957:
	local[22]= makeint(1);
IF65958:
	ctx->vsp=local+23;
	w=(pointer)TIMES(ctx,2,local+21); /***/
	local[9] = w;
	local[21]= local[7];
	local[22]= local[13];
	local[23]= makeint(-1);
	ctx->vsp=local+24;
	w=(pointer)PLUS(ctx,3,local+21); /*+*/
	local[21]= w;
	local[22]= local[13];
	ctx->vsp=local+23;
	w=(pointer)QUOTIENT(ctx,2,local+21); /*/*/
	local[21]= w;
	local[22]= local[13];
	ctx->vsp=local+23;
	w=(pointer)TIMES(ctx,2,local+21); /***/
	local[7] = w;
	local[21]= local[12];
	w = fqv[68];
	if (memq(local[21],w)==NIL) goto CON65997;
	local[21]= fqv[61];
	local[22]= local[14];
	local[23]= fqv[62];
	local[24]= fqv[69];
	local[25]= fqv[70];
	ctx->vsp=local+26;
	w=(pointer)LIST(ctx,1,local+25); /*list*/
	ctx->vsp=local+25;
	w = cons(ctx,local[24],w);
	ctx->vsp=local+24;
	local[23]= cons(ctx,local[23],w);
	local[24]= fqv[71];
	local[25]= fqv[70];
	local[26]= fqv[63];
	local[27]= fqv[62];
	local[28]= fqv[72];
	local[29]= local[7];
	local[30]= fqv[70];
	ctx->vsp=local+31;
	w=(pointer)LIST(ctx,1,local+30); /*list*/
	ctx->vsp=local+30;
	w = cons(ctx,local[29],w);
	ctx->vsp=local+29;
	local[28]= cons(ctx,local[28],w);
	local[29]= fqv[73];
	ctx->vsp=local+30;
	w=(pointer)LIST(ctx,1,local+29); /*list*/
	ctx->vsp=local+29;
	w = cons(ctx,local[28],w);
	ctx->vsp=local+28;
	w = cons(ctx,local[27],w);
	ctx->vsp=local+27;
	local[26]= cons(ctx,local[26],w);
	local[27]= fqv[74];
	local[28]= fqv[62];
	local[29]= local[7];
	local[30]= fqv[72];
	local[31]= local[7];
	local[32]= local[9];
	ctx->vsp=local+33;
	w=(pointer)LIST(ctx,1,local+32); /*list*/
	ctx->vsp=local+32;
	w = cons(ctx,local[31],w);
	ctx->vsp=local+31;
	local[30]= cons(ctx,local[30],w);
	ctx->vsp=local+31;
	w=(pointer)LIST(ctx,1,local+30); /*list*/
	ctx->vsp=local+30;
	w = cons(ctx,local[29],w);
	ctx->vsp=local+29;
	w = cons(ctx,local[28],w);
	ctx->vsp=local+28;
	local[27]= cons(ctx,local[27],w);
	ctx->vsp=local+28;
	w=(pointer)LIST(ctx,1,local+27); /*list*/
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
	w = cons(ctx,local[22],w);
	ctx->vsp=local+22;
	local[3] = cons(ctx,local[21],w);
	local[21]= fqv[64];
	local[22]= local[14];
	local[23]= local[15];
	ctx->vsp=local+24;
	w=(pointer)LIST(ctx,1,local+23); /*list*/
	ctx->vsp=local+23;
	w = cons(ctx,local[22],w);
	ctx->vsp=local+22;
	local[4] = cons(ctx,local[21],w);
	local[21]= fqv[61];
	local[22]= local[15];
	local[23]= fqv[62];
	local[24]= fqv[70];
	local[25]= fqv[75];
	local[26]= fqv[65];
	ctx->vsp=local+27;
	w=(pointer)LIST(ctx,1,local+26); /*list*/
	ctx->vsp=local+26;
	w = cons(ctx,local[25],w);
	ctx->vsp=local+25;
	w = cons(ctx,local[24],w);
	ctx->vsp=local+24;
	local[23]= cons(ctx,local[23],w);
	local[24]= fqv[71];
	local[25]= fqv[65];
	local[26]= fqv[66];
	local[27]= fqv[76];
	local[28]= fqv[65];
	ctx->vsp=local+29;
	w=(pointer)LIST(ctx,1,local+28); /*list*/
	ctx->vsp=local+28;
	local[27]= cons(ctx,local[27],w);
	local[28]= fqv[72];
	local[29]= local[7];
	local[30]= fqv[70];
	ctx->vsp=local+31;
	w=(pointer)LIST(ctx,1,local+30); /*list*/
	ctx->vsp=local+30;
	w = cons(ctx,local[29],w);
	ctx->vsp=local+29;
	local[28]= cons(ctx,local[28],w);
	local[29]= fqv[73];
	ctx->vsp=local+30;
	w=(pointer)LIST(ctx,1,local+29); /*list*/
	ctx->vsp=local+29;
	w = cons(ctx,local[28],w);
	ctx->vsp=local+28;
	w = cons(ctx,local[27],w);
	ctx->vsp=local+27;
	local[26]= cons(ctx,local[26],w);
	local[27]= fqv[77];
	local[28]= fqv[62];
	local[29]= fqv[70];
	local[30]= fqv[78];
	local[31]= local[7];
	local[32]= fqv[79];
	local[33]= fqv[80];
	local[34]= fqv[70];
	ctx->vsp=local+35;
	w=(pointer)LIST(ctx,1,local+34); /*list*/
	ctx->vsp=local+34;
	local[33]= cons(ctx,local[33],w);
	ctx->vsp=local+34;
	w=(pointer)LIST(ctx,1,local+33); /*list*/
	ctx->vsp=local+33;
	w = cons(ctx,local[32],w);
	ctx->vsp=local+32;
	w = cons(ctx,local[31],w);
	ctx->vsp=local+31;
	w = cons(ctx,local[30],w);
	ctx->vsp=local+30;
	w = cons(ctx,local[29],w);
	ctx->vsp=local+29;
	w = cons(ctx,local[28],w);
	ctx->vsp=local+28;
	local[27]= cons(ctx,local[27],w);
	ctx->vsp=local+28;
	w=(pointer)LIST(ctx,1,local+27); /*list*/
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
	w = cons(ctx,local[22],w);
	ctx->vsp=local+22;
	local[5] = cons(ctx,local[21],w);
	local[21]= local[5];
	goto CON65995;
CON65997:
	local[21]= fqv[61];
	local[22]= local[14];
	local[23]= fqv[62];
	local[24]= fqv[70];
	ctx->vsp=local+25;
	w=(pointer)LIST(ctx,1,local+24); /*list*/
	ctx->vsp=local+24;
	local[23]= cons(ctx,local[23],w);
	local[24]= fqv[81];
	local[25]= fqv[82];
	local[26]= fqv[70];
	ctx->vsp=local+27;
	w=(pointer)LIST(ctx,1,local+26); /*list*/
	ctx->vsp=local+26;
	local[25]= cons(ctx,local[25],w);
	ctx->vsp=local+26;
	w=(pointer)LIST(ctx,1,local+25); /*list*/
	ctx->vsp=local+25;
	local[24]= cons(ctx,local[24],w);
	local[25]= fqv[63];
	local[26]= fqv[62];
	local[27]= fqv[72];
	local[28]= local[7];
	local[29]= fqv[48];
	local[30]= fqv[70];
	local[31]= local[13];
	ctx->vsp=local+32;
	w=(pointer)LIST(ctx,1,local+31); /*list*/
	ctx->vsp=local+31;
	w = cons(ctx,local[30],w);
	ctx->vsp=local+30;
	local[29]= cons(ctx,local[29],w);
	ctx->vsp=local+30;
	w=(pointer)LIST(ctx,1,local+29); /*list*/
	ctx->vsp=local+29;
	w = cons(ctx,local[28],w);
	ctx->vsp=local+28;
	local[27]= cons(ctx,local[27],w);
	local[28]= local[12];
	ctx->vsp=local+29;
	w=(pointer)LIST(ctx,1,local+28); /*list*/
	ctx->vsp=local+28;
	w = cons(ctx,local[27],w);
	ctx->vsp=local+27;
	w = cons(ctx,local[26],w);
	ctx->vsp=local+26;
	local[25]= cons(ctx,local[25],w);
	ctx->vsp=local+26;
	w=(pointer)LIST(ctx,1,local+25); /*list*/
	ctx->vsp=local+25;
	w = cons(ctx,local[24],w);
	ctx->vsp=local+24;
	w = cons(ctx,local[23],w);
	ctx->vsp=local+23;
	w = cons(ctx,local[22],w);
	ctx->vsp=local+22;
	local[3] = cons(ctx,local[21],w);
	local[21]= fqv[64];
	local[22]= local[14];
	local[23]= local[15];
	ctx->vsp=local+24;
	w=(pointer)LIST(ctx,1,local+23); /*list*/
	ctx->vsp=local+23;
	w = cons(ctx,local[22],w);
	ctx->vsp=local+22;
	local[4] = cons(ctx,local[21],w);
	local[21]= fqv[61];
	local[22]= local[15];
	local[23]= fqv[62];
	local[24]= fqv[70];
	local[25]= fqv[65];
	ctx->vsp=local+26;
	w=(pointer)LIST(ctx,1,local+25); /*list*/
	ctx->vsp=local+25;
	w = cons(ctx,local[24],w);
	ctx->vsp=local+24;
	local[23]= cons(ctx,local[23],w);
	local[24]= fqv[81];
	local[25]= fqv[82];
	local[26]= fqv[70];
	ctx->vsp=local+27;
	w=(pointer)LIST(ctx,1,local+26); /*list*/
	ctx->vsp=local+26;
	local[25]= cons(ctx,local[25],w);
	ctx->vsp=local+26;
	w=(pointer)LIST(ctx,1,local+25); /*list*/
	ctx->vsp=local+25;
	local[24]= cons(ctx,local[24],w);
	local[25]= fqv[66];
	local[26]= fqv[65];
	local[27]= fqv[62];
	local[28]= fqv[72];
	local[29]= local[7];
	local[30]= fqv[48];
	local[31]= fqv[70];
	local[32]= local[13];
	ctx->vsp=local+33;
	w=(pointer)LIST(ctx,1,local+32); /*list*/
	ctx->vsp=local+32;
	w = cons(ctx,local[31],w);
	ctx->vsp=local+31;
	local[30]= cons(ctx,local[30],w);
	ctx->vsp=local+31;
	w=(pointer)LIST(ctx,1,local+30); /*list*/
	ctx->vsp=local+30;
	w = cons(ctx,local[29],w);
	ctx->vsp=local+29;
	local[28]= cons(ctx,local[28],w);
	local[29]= local[12];
	ctx->vsp=local+30;
	w=(pointer)LIST(ctx,1,local+29); /*list*/
	ctx->vsp=local+29;
	w = cons(ctx,local[28],w);
	ctx->vsp=local+28;
	w = cons(ctx,local[27],w);
	ctx->vsp=local+27;
	w = cons(ctx,local[26],w);
	ctx->vsp=local+26;
	local[25]= cons(ctx,local[25],w);
	ctx->vsp=local+26;
	w=(pointer)LIST(ctx,1,local+25); /*list*/
	ctx->vsp=local+25;
	w = cons(ctx,local[24],w);
	ctx->vsp=local+24;
	w = cons(ctx,local[23],w);
	ctx->vsp=local+23;
	w = cons(ctx,local[22],w);
	ctx->vsp=local+22;
	local[5] = cons(ctx,local[21],w);
	local[21]= local[5];
	goto CON65995;
CON66242:
	local[21]= NIL;
CON65995:
	goto CON65754;
CON65877:
	local[21]= fqv[83];
	ctx->vsp=local+22;
	w=(pointer)SIGERROR(ctx,1,local+21); /*error*/
	local[21]= w;
	goto CON65754;
CON66429:
	local[21]= NIL;
CON65754:
	local[21]= local[3];
	w = local[1];
	ctx->vsp=local+22;
	local[1] = cons(ctx,local[21],w);
	local[21]= local[4];
	w = local[1];
	ctx->vsp=local+22;
	local[1] = cons(ctx,local[21],w);
	local[21]= local[5];
	w = local[1];
	ctx->vsp=local+22;
	local[1] = cons(ctx,local[21],w);
	local[21]= local[7];
	local[22]= local[9];
	ctx->vsp=local+23;
	w=(pointer)PLUS(ctx,2,local+21); /*+*/
	local[7] = w;
	goto WHL65654;
WHX65655:
	local[21]= NIL;
BLK65656:
	w = NIL;
	local[19]= fqv[33];
	local[20]= fqv[84];
	local[21]= argv[0];
	local[22]= fqv[57];
	local[23]= local[18];
	local[24]= fqv[19];
	local[25]= fqv[73];
	local[26]= fqv[85];
	local[27]= fqv[86];
	ctx->vsp=local+28;
	w=(pointer)LIST(ctx,1,local+27); /*list*/
	ctx->vsp=local+27;
	w = cons(ctx,local[26],w);
	ctx->vsp=local+26;
	w = cons(ctx,local[25],w);
	ctx->vsp=local+25;
	w = cons(ctx,local[24],w);
	ctx->vsp=local+24;
	w = cons(ctx,local[23],w);
	ctx->vsp=local+23;
	w = cons(ctx,local[22],w);
	ctx->vsp=local+22;
	w = cons(ctx,local[21],w);
	ctx->vsp=local+21;
	local[20]= cons(ctx,local[20],w);
	local[21]= fqv[36];
	local[22]= argv[0];
	local[23]= fqv[45];
	local[24]= fqv[12];
	local[25]= local[0];
	ctx->vsp=local+26;
	w=(pointer)LIST(ctx,1,local+25); /*list*/
	ctx->vsp=local+25;
	local[24]= cons(ctx,local[24],w);
	ctx->vsp=local+25;
	w=(pointer)LIST(ctx,1,local+24); /*list*/
	ctx->vsp=local+24;
	w = cons(ctx,local[23],w);
	ctx->vsp=local+23;
	w = cons(ctx,local[22],w);
	ctx->vsp=local+22;
	local[21]= cons(ctx,local[21],w);
	local[22]= local[1];
	ctx->vsp=local+23;
	w=(pointer)NREVERSE(ctx,1,local+22); /*nreverse*/
	local[22]= w;
	local[23]= fqv[12];
	local[24]= argv[0];
	ctx->vsp=local+25;
	w=(pointer)LIST(ctx,1,local+24); /*list*/
	ctx->vsp=local+24;
	local[23]= cons(ctx,local[23],w);
	ctx->vsp=local+24;
	w=(pointer)LIST(ctx,1,local+23); /*list*/
	local[23]= w;
	ctx->vsp=local+24;
	w=(pointer)APPEND(ctx,2,local+22); /*append*/
	ctx->vsp=local+22;
	w = cons(ctx,local[21],w);
	ctx->vsp=local+21;
	w = cons(ctx,local[20],w);
	ctx->vsp=local+20;
	w = cons(ctx,local[19],w);
	local[0]= w;
BLK65304:
	ctx->vsp=local; return(local[0]);}

/*:get*/
static pointer M66587carray_get(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT66591;}
	local[0]= makeint(0);
ENT66591:
ENT66590:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[87]));
	local[3]= fqv[88];
	local[4]= NIL;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	local[0]= w;
BLK66588:
	ctx->vsp=local; return(local[0]);}

/*:set*/
static pointer M66617carray_set(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT66621;}
	local[0]= makeint(0);
ENT66621:
ENT66620:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[87]));
	local[3]= fqv[89];
	local[4]= argv[2];
	local[5]= NIL;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,6,local+1); /*send-message*/
	local[0]= w;
BLK66618:
	ctx->vsp=local; return(local[0]);}

/*defcarray*/
static pointer F66651(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT66655;}
	local[0]= makeint(1);
ENT66655:
ENT66654:
	if (n>3) maerror();
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,1,local+1,&ftab[7],fqv[90]); /*symbol-name*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[7])(ctx,1,local+2,&ftab[7],fqv[90]); /*symbol-name*/
	local[2]= w;
	local[3]= loadglobal(fqv[40]);
	local[4]= local[2];
	local[5]= fqv[91];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[7])(ctx,1,local+6,&ftab[7],fqv[90]); /*symbol-name*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)CONCATENATE(ctx,4,local+3); /*concatenate*/
	local[3]= w;
	local[4]= loadglobal(fqv[40]);
	local[5]= fqv[92];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)CONCATENATE(ctx,3,local+4); /*concatenate*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)INTERN(ctx,1,local+4); /*intern*/
	local[4]= w;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)INTERN(ctx,1,local+5); /*intern*/
	local[5]= w;
	local[6]= loadglobal(fqv[40]);
	local[7]= fqv[93];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)CONCATENATE(ctx,3,local+6); /*concatenate*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)INTERN(ctx,1,local+6); /*intern*/
	local[6]= w;
	local[7]= fqv[33];
	local[8]= fqv[94];
	local[9]= argv[0];
	local[10]= fqv[57];
	local[11]= fqv[95];
	local[12]= local[1];
	local[13]= argv[1];
	local[14]= local[0];
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
	local[9]= fqv[61];
	local[10]= argv[0];
	local[11]= fqv[62];
	local[12]= fqv[69];
	local[13]= fqv[70];
	local[14]= fqv[96];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= local[5];
	local[13]= fqv[62];
	local[14]= fqv[70];
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
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[61];
	local[11]= local[4];
	local[12]= fqv[62];
	local[13]= fqv[70];
	local[14]= fqv[69];
	local[15]= fqv[65];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[71];
	local[14]= fqv[65];
	local[15]= local[6];
	local[16]= fqv[62];
	local[17]= fqv[70];
	local[18]= fqv[65];
	ctx->vsp=local+19;
	w=(pointer)LIST(ctx,1,local+18); /*list*/
	ctx->vsp=local+18;
	w = cons(ctx,local[17],w);
	ctx->vsp=local+17;
	w = cons(ctx,local[16],w);
	ctx->vsp=local+16;
	local[15]= cons(ctx,local[15],w);
	local[16]= local[6];
	local[17]= fqv[62];
	local[18]= fqv[97];
	local[19]= fqv[70];
	ctx->vsp=local+20;
	w=(pointer)LIST(ctx,1,local+19); /*list*/
	ctx->vsp=local+19;
	w = cons(ctx,local[18],w);
	ctx->vsp=local+18;
	w = cons(ctx,local[17],w);
	ctx->vsp=local+17;
	local[16]= cons(ctx,local[16],w);
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
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[64];
	local[12]= argv[0];
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[12];
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
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
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	local[0]= w;
BLK66652:
	ctx->vsp=local; return(local[0]);}

/*make-foreign-string*/
static pointer F63341make_foreign_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[98]);
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,2,local+0); /*instantiate*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= makeint(2);
	{ eusinteger_t i,j;
		j=intval(makeint(8)); i=intval(local[2]);
		local[2]=(makeint(i * j));}
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)ADDRESS(ctx,1,local+3); /*system:address*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= fqv[67];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,3,local+1); /*system:poke*/
	w = local[0];
	local[0]= w;
BLK66920:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___eusforeign(ctx,n,argv,env)
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
	local[0]= fqv[99];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF66973;
	local[0]= fqv[100];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[35],w);
	goto IF66974;
IF66973:
	local[0]= fqv[101];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF66974:
	local[0]= fqv[102];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M63386load_module_find,fqv[103],fqv[104],fqv[105]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M63426foreign_code_init,fqv[6],fqv[5],fqv[106]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[13],module,F63296make_foreign_code,fqv[107]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[108],module,F63298load_foreign,fqv[109]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[110],module,F63615,fqv[111]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[112],module,F63689,fqv[113]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[114],module,F63300byte_string,fqv[115]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M63825foreign_pod_pod_address,fqv[43],fqv[39],fqv[116]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M63847foreign_pod_init,fqv[6],fqv[39],fqv[117]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[118],module,F63985,fqv[119]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[120],module,F63302pod_address,fqv[121]);
	local[0]= fqv[44];
	local[1]= fqv[122];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF67019;
	local[0]= fqv[44];
	local[1]= fqv[122];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[44];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF67042;
	local[0]= fqv[44];
	local[1]= fqv[123];
	local[2]= fqv[49];
	local[3]= makeint(8);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[67];
	local[4]= makeint(8);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[124];
	local[5]= makeint(4);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[1];
	local[6]= makeint(4);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[125];
	local[7]= makeint(2);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[20];
	local[8]= makeint(1);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[126];
	local[9]= makeint(1);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[127];
	local[10]= makeint(4);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[128];
	local[11]= makeint(8);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[129];
	local[12]= fqv[130];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[73];
	local[13]= fqv[131];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
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
	w = cons(ctx,local[8],w);
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
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF67043;
IF67042:
	local[0]= NIL;
IF67043:
	local[0]= fqv[44];
	goto IF67020;
IF67019:
	local[0]= NIL;
IF67020:
	ctx->vsp=local+0;
	compfun(ctx,fqv[132],module,F63304byte_size,fqv[133]);
	local[0]= fqv[86];
	local[1]= fqv[123];
	local[2]= fqv[86];
	local[3]= fqv[57];
	local[4]= loadglobal(fqv[134]);
	local[5]= fqv[135];
	local[6]= fqv[136];
	local[7]= fqv[85];
	local[8]= NIL;
	local[9]= fqv[19];
	local[10]= NIL;
	local[11]= fqv[137];
	local[12]= makeint(-1);
	local[13]= fqv[138];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[8])(ctx,13,local+2,&ftab[8],fqv[139]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M64322cstructclass_slotlist,fqv[45],fqv[86],fqv[140]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M64912cstructclass_size,fqv[137],fqv[86],fqv[141]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M64928cstructclass_slot,fqv[50],fqv[86],fqv[142]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M64959cstructclass_offset,fqv[143],fqv[86],fqv[144]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M65054cstructclass_access,fqv[55],fqv[86],fqv[145]);
	local[0]= fqv[56];
	local[1]= fqv[123];
	local[2]= fqv[56];
	local[3]= fqv[57];
	local[4]= loadglobal(fqv[40]);
	local[5]= fqv[135];
	local[6]= fqv[18];
	local[7]= fqv[85];
	local[8]= NIL;
	local[9]= fqv[19];
	local[10]= fqv[73];
	local[11]= fqv[137];
	local[12]= makeint(-1);
	local[13]= fqv[138];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[8])(ctx,13,local+2,&ftab[8],fqv[139]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M65183cstruct_get,fqv[88],fqv[56],fqv[146]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M65241cstruct_set,fqv[89],fqv[56],fqv[147]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[94],module,F65303,fqv[148]);
	local[0]= fqv[95];
	local[1]= fqv[123];
	local[2]= fqv[95];
	local[3]= fqv[57];
	local[4]= loadglobal(fqv[56]);
	local[5]= fqv[135];
	local[6]= fqv[18];
	local[7]= fqv[85];
	local[8]= NIL;
	local[9]= fqv[19];
	local[10]= NIL;
	local[11]= fqv[137];
	local[12]= makeint(-1);
	local[13]= fqv[138];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[8])(ctx,13,local+2,&ftab[8],fqv[139]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M66587carray_get,fqv[88],fqv[95],fqv[149]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M66617carray_set,fqv[89],fqv[95],fqv[150]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[151],module,F66651,fqv[152]);
	local[0]= fqv[98];
	local[1]= fqv[123];
	local[2]= fqv[98];
	local[3]= fqv[57];
	local[4]= loadglobal(fqv[153]);
	local[5]= fqv[135];
	local[6]= fqv[18];
	local[7]= fqv[85];
	local[8]= NIL;
	local[9]= fqv[19];
	local[10]= fqv[154];
	local[11]= fqv[137];
	local[12]= makeint(-1);
	local[13]= fqv[138];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[8])(ctx,13,local+2,&ftab[8],fqv[139]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[155],module,F63341make_foreign_string,fqv[156]);
	local[0]= fqv[157];
	local[1]= fqv[158];
	ctx->vsp=local+2;
	w=(*ftab[9])(ctx,2,local+0,&ftab[9],fqv[159]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<10; i++) ftab[i]=fcallx;
}
