/* ./object.c :  entry=object */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "object.h"
#pragma init (register_object)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___object();
extern pointer build_quote_vector();
static int register_object()
  { add_module_initializer("___object", ___object);}

static pointer F49286metaclass_name();
static pointer F49289metaclass_vars();

/*metaclass-name*/
static pointer F49286metaclass_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = *(ovafptr(argv[0],fqv[0]));
	local[0]= w;
BLK49319:
	ctx->vsp=local; return(local[0]);}

/*metaclass-vars*/
static pointer F49289metaclass_vars(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = *(ovafptr(argv[0],fqv[1]));
	local[0]= w;
BLK49334:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M49353object_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT49357;}
	local[0]= T;
ENT49357:
ENT49356:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-3);
	local[2]= local[0];
	local[3]= fqv[2];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)GETCLASS(ctx,1,local+4); /*class*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)F49286metaclass_name(ctx,1,local+4); /*metaclass-name*/
	local[4]= w;
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)ADDRESS(ctx,1,local+5); /*system:address*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,4,local+2); /*format*/
	local[2]= NIL;
	local[3]= local[1];
WHL49403:
	if (local[3]==NIL) goto WHX49404;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[0];
	local[5]= fqv[3];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	goto WHL49403;
WHX49404:
	local[4]= NIL;
BLK49405:
	w = NIL;
	local[2]= fqv[4];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)PRINC(ctx,2,local+2); /*princ*/
	w = argv[0];
	local[0]= w;
BLK49354:
	ctx->vsp=local; return(local[0]);}

/*:warning*/
static pointer M49467object_warning(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST49470:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	local[1]= (pointer)get_sym_func(fqv[5]);
	local[2]= argv[2];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[0]= w;
BLK49468:
	ctx->vsp=local; return(local[0]);}

/*:error*/
static pointer M49492object_error(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST49495:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[6]);
	local[2]= argv[0];
	local[3]= fqv[7];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[1]= fqv[8];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[9]); /*reploop*/
	local[0]= w;
BLK49493:
	ctx->vsp=local; return(local[0]);}

/*:slots*/
static pointer M49522object_slots(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)GETCLASS(ctx,1,local+0); /*class*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)F49289metaclass_vars(ctx,1,local+0); /*metaclass-vars*/
	local[0]= w;
	local[1]= NIL;
	local[2]= makeint(0);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
WHL49578:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX49579;
	local[4]= local[0];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)GETCLASS(ctx,1,local+6); /*class*/
	local[6]= w;
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SLOT(ctx,3,local+5); /*slot*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL49578;
WHX49579:
	local[4]= NIL;
BLK49580:
	w = NIL;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)NREVERSE(ctx,1,local+2); /*nreverse*/
	local[0]= w;
BLK49523:
	ctx->vsp=local; return(local[0]);}

/*:methods*/
static pointer M49628object_methods(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT49633;}
	local[0]= fqv[10];
ENT49633:
ENT49632:
	if (n>3) maerror();
	local[1]= (pointer)get_sym_func(fqv[11]);
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)GETCLASS(ctx,1,local+2); /*class*/
	local[2]= w;
	local[3]= fqv[12];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAPCAN(ctx,2,local+1); /*mapcan*/
	local[0]= w;
BLK49630:
	ctx->vsp=local; return(local[0]);}

/*:super*/
static pointer M49662object_super(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)GETCLASS(ctx,1,local+0); /*class*/
	local[0]= w;
	local[1]= fqv[13];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK49663:
	ctx->vsp=local; return(local[0]);}

/*:get-val*/
static pointer M49683object_get_val(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)GETCLASS(ctx,1,local+1); /*class*/
	local[1]= w;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SLOT(ctx,3,local+0); /*slot*/
	local[0]= w;
BLK49684:
	ctx->vsp=local; return(local[0]);}

/*:set-val*/
static pointer M49706object_set_val(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)GETCLASS(ctx,1,local+1); /*class*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SETSLOT(ctx,4,local+0); /*setslot*/
	local[0]= w;
BLK49707:
	ctx->vsp=local; return(local[0]);}

/*:plist*/
static pointer M49740propertied_object_plist(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT49744;}
	local[0]= NIL;
ENT49744:
ENT49743:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF49760;
	argv[0]->c.obj.iv[0] = local[0];
	local[1]= argv[0]->c.obj.iv[0];
	goto IF49761;
IF49760:
	local[1]= argv[0]->c.obj.iv[0];
IF49761:
	w = local[1];
	local[0]= w;
BLK49741:
	ctx->vsp=local; return(local[0]);}

/*:get*/
static pointer M49774propertied_object_get(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK49775:
	ctx->vsp=local; return(local[0]);}

/*:put*/
static pointer M49799propertied_object_put(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	local[0]= w;
	if (local[0]==NIL) goto IF49830;
	local[1]= local[0];
	local[2]= fqv[14];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF49831;
IF49830:
	local[1]= argv[2];
	w = argv[3];
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	w = argv[0]->c.obj.iv[0];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[0] = cons(ctx,local[1],w);
	local[1]= argv[0]->c.obj.iv[0];
IF49831:
	w = argv[3];
	local[0]= w;
BLK49800:
	ctx->vsp=local; return(local[0]);}

/*:name*/
static pointer M49864propertied_object_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT49868;}
	local[0]= NIL;
ENT49868:
ENT49867:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF49884;
	local[1]= argv[0];
	local[2]= fqv[15];
	local[3]= fqv[16];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF49885;
IF49884:
	local[1]= argv[0];
	local[2]= fqv[17];
	local[3]= fqv[16];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
IF49885:
	w = local[1];
	local[0]= w;
BLK49865:
	ctx->vsp=local; return(local[0]);}

/*:remprop*/
static pointer M49906propertied_object_remprop(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	local[0]= w;
	if (local[0]==NIL) goto IF49935;
	local[1]= local[0];
	local[2]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[18]); /*delete*/
	argv[0]->c.obj.iv[0] = w;
	local[1]= argv[0]->c.obj.iv[0];
	goto IF49936;
IF49935:
	local[1]= NIL;
IF49936:
	w = local[1];
	local[0]= w;
BLK49907:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M49953propertied_object_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT49957;}
	local[0]= T;
ENT49957:
ENT49956:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-3);
	local[2]= NIL;
	local[3]= argv[0];
	local[4]= fqv[16];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	if (local[3]==NIL) goto IF49983;
	local[4]= (pointer)get_sym_func(fqv[19]);
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[20]));
	local[7]= fqv[21];
	local[8]= local[0];
	local[9]= local[3];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(pointer)APPLY(ctx,7,local+4); /*apply*/
	local[4]= w;
	goto IF49984;
IF49983:
	local[4]= (pointer)get_sym_func(fqv[19]);
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[20]));
	local[7]= fqv[21];
	local[8]= local[0];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)APPLY(ctx,6,local+4); /*apply*/
	local[4]= w;
IF49984:
	w = local[4];
	local[0]= w;
BLK49954:
	ctx->vsp=local; return(local[0]);}

/*:new*/
static pointer M50037metaclass_new(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
BLK50038:
	ctx->vsp=local; return(local[0]);}

/*:super*/
static pointer M50054metaclass_super(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK50055:
	ctx->vsp=local; return(local[0]);}

/*:methods*/
static pointer M50070metaclass_methods(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[7];
	local[0]= w;
BLK50071:
	ctx->vsp=local; return(local[0]);}

/*:method*/
static pointer M50086metaclass_method(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[22]); /*assoc*/
	local[0]= w;
BLK50087:
	ctx->vsp=local; return(local[0]);}

/*:method-names*/
static pointer M50107metaclass_method_names(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT50111;}
	local[0]= fqv[23];
ENT50111:
ENT50110:
	if (n>3) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[24]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,1,local+1,&ftab[4],fqv[25]); /*string-upcase*/
	local[0] = w;
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO50141,env,argv,local);
	local[2]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+3;
	w=(pointer)MAPCAN(ctx,2,local+1); /*mapcan*/
	local[0]= w;
BLK50108:
	ctx->vsp=local; return(local[0]);}

/*:all-methods*/
static pointer M50147metaclass_all_methods(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[2]==NIL) goto IF50160;
	local[0]= argv[0]->c.obj.iv[7];
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[26];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	local[0]= w;
	goto IF50161;
IF50160:
	local[0]= argv[0]->c.obj.iv[7];
IF50161:
	w = local[0];
	local[0]= w;
BLK50148:
	ctx->vsp=local; return(local[0]);}

/*:all-method-names*/
static pointer M50176metaclass_all_method_names(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT50180;}
	local[0]= fqv[27];
ENT50180:
ENT50179:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[0];
	local[3]= fqv[28];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[1]= w;
	if (argv[0]->c.obj.iv[2]==NIL) goto IF50215;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= fqv[12];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF50216;
IF50215:
	local[2]= NIL;
IF50216:
	local[3]= local[1];
	w = local[2];
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	local[0]= w;
BLK50177:
	ctx->vsp=local; return(local[0]);}

/*:slots*/
static pointer M50238metaclass_slots(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK50239:
	ctx->vsp=local; return(local[0]);}

/*:name*/
static pointer M50254metaclass_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK50255:
	ctx->vsp=local; return(local[0]);}

/*:cid*/
static pointer M50270metaclass_cid(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK50271:
	ctx->vsp=local; return(local[0]);}

/*:cix*/
static pointer M50286metaclass_cix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK50287:
	ctx->vsp=local; return(local[0]);}

/*:sub*/
static pointer M50302metaclass_sub(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	ctx->vsp=local+2;
	w=(pointer)LISTALLCLASSES(ctx,0,local+2); /*system:list-all-classes*/
	local[2]= w;
WHL50342:
	if (local[2]==NIL) goto WHX50343;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	local[4]= fqv[13];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w==NIL) goto IF50391;
	local[3]= local[1];
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	local[3]= local[0];
	goto IF50392;
IF50391:
	local[3]= NIL;
IF50392:
	goto WHL50342;
WHX50343:
	local[3]= NIL;
BLK50344:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK50303:
	ctx->vsp=local; return(local[0]);}

/*:subclasses*/
static pointer M50423metaclass_subclasses(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[29];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK50424:
	ctx->vsp=local; return(local[0]);}

/*:hierarchy*/
static pointer M50442metaclass_hierarchy(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= fqv[29];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
WHL50485:
	if (local[2]==NIL) goto WHX50486;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	local[4]= fqv[30];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	goto WHL50485;
WHX50486:
	local[3]= NIL;
BLK50487:
	w = NIL;
	local[1]= argv[0];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)NREVERSE(ctx,1,local+2); /*nreverse*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK50443:
	ctx->vsp=local; return(local[0]);}

/*:superclasses*/
static pointer M50562metaclass_superclasses(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[13];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
WHL50592:
	if (local[1]==NIL) goto WHX50593;
	local[2]= local[1];
	w = local[0];
	ctx->vsp=local+3;
	local[0] = cons(ctx,local[2],w);
	local[2]= local[1];
	local[3]= fqv[13];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[1] = w;
	goto WHL50592;
WHX50593:
	local[2]= NIL;
BLK50594:
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)NREVERSE(ctx,1,local+2); /*nreverse*/
	local[0]= w;
BLK50563:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO50141(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	local[0]= env->c.clo.env2[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,1,local+1,&ftab[5],fqv[31]); /*symbol-name*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,2,local+0,&ftab[6],fqv[32]); /*substringp*/
	if (w==NIL) goto IF50649;
	local[0]= argv[0];
	w = NIL;
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	goto IF50650;
IF50649:
	local[0]= NIL;
IF50650:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M50686load_module_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT50690;}
	local[0]= T;
ENT50690:
ENT50689:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-3);
	local[2]= (pointer)get_sym_func(fqv[19]);
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[20]));
	local[5]= fqv[21];
	local[6]= local[0];
	local[7]= loadglobal(fqv[24]);
	local[8]= fqv[33];
	local[9]= argv[0]->c.obj.iv[5];
	local[10]= fqv[34];
	ctx->vsp=local+11;
	w=(pointer)CONCATENATE(ctx,4,local+7); /*concatenate*/
	local[7]= w;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,7,local+2); /*apply*/
	local[0]= w;
BLK50687:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___object(ctx,n,argv,env)
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
	local[0]= fqv[35];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= fqv[36];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF50734;
	local[0]= fqv[37];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[38],w);
	goto IF50735;
IF50734:
	local[0]= fqv[39];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF50735:
	local[0]= fqv[40];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[41],module,F49286metaclass_name,fqv[42]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[43],module,F49289metaclass_vars,fqv[44]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49353object_prin1,fqv[21],fqv[45],fqv[46]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49467object_warning,fqv[7],fqv[45],fqv[47]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49492object_error,fqv[48],fqv[45],fqv[49]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49522object_slots,fqv[50],fqv[45],fqv[51]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49628object_methods,fqv[52],fqv[45],fqv[53]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49662object_super,fqv[13],fqv[45],fqv[54]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49683object_get_val,fqv[55],fqv[45],fqv[56]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49706object_set_val,fqv[57],fqv[45],fqv[58]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49740propertied_object_plist,fqv[59],fqv[60],fqv[61]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49774propertied_object_get,fqv[17],fqv[60],fqv[62]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49799propertied_object_put,fqv[15],fqv[60],fqv[63]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49864propertied_object_name,fqv[16],fqv[60],fqv[64]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49906propertied_object_remprop,fqv[65],fqv[60],fqv[66]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M49953propertied_object_prin1,fqv[21],fqv[60],fqv[67]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M50037metaclass_new,fqv[68],fqv[69],fqv[70]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M50054metaclass_super,fqv[13],fqv[69],fqv[71]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M50070metaclass_methods,fqv[52],fqv[69],fqv[72]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M50086metaclass_method,fqv[73],fqv[69],fqv[74]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M50107metaclass_method_names,fqv[28],fqv[69],fqv[75]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M50147metaclass_all_methods,fqv[26],fqv[69],fqv[76]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M50176metaclass_all_method_names,fqv[12],fqv[69],fqv[77]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M50238metaclass_slots,fqv[50],fqv[69],fqv[78]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M50254metaclass_name,fqv[16],fqv[69],fqv[79]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M50270metaclass_cid,fqv[80],fqv[69],fqv[81]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M50286metaclass_cix,fqv[82],fqv[69],fqv[83]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M50302metaclass_sub,fqv[29],fqv[69],fqv[84]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M50423metaclass_subclasses,fqv[85],fqv[69],fqv[86]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M50442metaclass_hierarchy,fqv[30],fqv[69],fqv[87]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M50562metaclass_superclasses,fqv[88],fqv[69],fqv[89]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M50686load_module_prin1,fqv[21],fqv[90],fqv[91]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<7; i++) ftab[i]=fcallx;
}
