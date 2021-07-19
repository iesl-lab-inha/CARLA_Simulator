/* ./irtscene.c :  entry=irtscene */
/* compiled by EusLisp 9.27() for Linux created on ip-10-0-1-214(Fri Apr 16 04:05:26 PST 2021) */
#include "eus.h"
#include "irtscene.h"
#pragma init (register_irtscene)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___irtscene();
extern pointer build_quote_vector();
static int register_irtscene()
  { add_module_initializer("___irtscene", ___irtscene);}


/*:init*/
static pointer M635scene_model_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST637:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[0], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY638;
	local[1] = fqv[1];
KEY638:
	if (n & (1<<1)) goto KEY639;
	local[2] = NIL;
KEY639:
	if (n & (1<<2)) goto KEY640;
	local[3] = NIL;
KEY640:
	local[4]= (pointer)get_sym_func(fqv[2]);
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[3]));
	local[7]= fqv[4];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,5,local+4); /*apply*/
	argv[0]->c.obj.iv[8] = fqv[5];
	argv[0]->c.obj.iv[9] = local[2];
	if (local[3]==NIL) goto IF641;
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO643,env,argv,local);
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(*ftab[0])(ctx,2,local+4,&ftab[0],fqv[6]); /*delete-if*/
	local[4]= w;
	goto IF642;
IF641:
	local[4]= argv[0]->c.obj.iv[9];
IF642:
	local[4]= NIL;
	local[5]= argv[0]->c.obj.iv[9];
WHL645:
	if (local[5]==NIL) goto WHX646;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= argv[0];
	local[7]= fqv[7];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)GETCLASS(ctx,1,local+6); /*class*/
	local[6]= w;
	if (loadglobal(fqv[8])!=local[6]) goto IF649;
	local[6]= local[4];
	local[7]= makeint((eusinteger_t)2L);
	local[8]= fqv[9];
	ctx->vsp=local+9;
	w=(pointer)PUTPROP(ctx,3,local+6); /*putprop*/
	local[6]= local[4];
	local[7]= fqv[10];
	local[8]= fqv[11];
	ctx->vsp=local+9;
	w=(pointer)PUTPROP(ctx,3,local+6); /*putprop*/
	local[6]= local[4];
	local[7]= makeint((eusinteger_t)300L);
	local[8]= fqv[12];
	ctx->vsp=local+9;
	w=(pointer)PUTPROP(ctx,3,local+6); /*putprop*/
	local[6]= w;
	goto IF650;
IF649:
	local[6]= NIL;
IF650:
	goto WHL645;
WHX646:
	local[6]= NIL;
BLK647:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK636:
	ctx->vsp=local; return(local[0]);}

/*:objects*/
static pointer M651scene_model_objects(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[9];
	local[0]= w;
BLK652:
	ctx->vsp=local; return(local[0]);}

/*:add-objects*/
static pointer M653scene_model_add_objects(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[2];
WHL656:
	if (local[1]==NIL) goto WHX657;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0];
	local[3]= fqv[13];
	local[4]= local[0];
	local[5]= fqv[5];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	if (w==NIL) goto IF660;
	local[2]= fqv[14];
	local[3]= local[0];
	local[4]= fqv[5];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,2,local+2); /*error*/
	w = NIL;
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK654;
	goto IF661;
IF660:
	local[2]= NIL;
IF661:
	goto WHL656;
WHX657:
	local[2]= NIL;
BLK658:
	w = NIL;
	local[0]= argv[0]->c.obj.iv[9];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	local[0]= w;
BLK654:
	ctx->vsp=local; return(local[0]);}

/*:add-object*/
static pointer M662scene_model_add_object(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK663:
	ctx->vsp=local; return(local[0]);}

/*:remove-objects*/
static pointer M664scene_model_remove_objects(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[2];
WHL667:
	if (local[2]==NIL) goto WHX668;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	w = local[1];
	if (!isstring(w)) goto IF671;
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF672;
IF671:
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= local[1];
	local[6]= fqv[5];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
IF672:
	if (local[3]!=NIL) goto IF673;
	local[4]= fqv[17];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SIGERROR(ctx,2,local+4); /*error*/
	w = NIL;
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK665;
	goto IF674;
IF673:
	local[4]= NIL;
IF674:
	local[4]= local[3];
	w = local[0];
	ctx->vsp=local+5;
	local[0] = cons(ctx,local[4],w);
	w = local[0];
	goto WHL667;
WHX668:
	local[3]= NIL;
BLK669:
	w = NIL;
	local[1]= argv[0]->c.obj.iv[9];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[18]); /*set-difference*/
	argv[0]->c.obj.iv[9] = w;
	w = local[0];
	local[0]= w;
BLK665:
	ctx->vsp=local; return(local[0]);}

/*:remove-object*/
static pointer M675scene_model_remove_object(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK676:
	ctx->vsp=local; return(local[0]);}

/*:find-object*/
static pointer M677scene_model_find_object(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO679,env,argv,local);
	local[1]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO680,env,argv,local);
	local[2]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+3;
	w=(pointer)MAPCAN(ctx,2,local+1); /*mapcan*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	local[0]= w;
BLK678:
	ctx->vsp=local; return(local[0]);}

/*:add-spots*/
static pointer M681scene_model_add_spots(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[2];
WHL684:
	if (local[1]==NIL) goto WHX685;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	if (!isstring(w)) goto AND690;
	local[2]= local[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,1,local+2,&ftab[2],fqv[20]); /*null-string-p*/
	if (w!=NIL) goto AND690;
	goto IF688;
AND690:
	local[2]= fqv[21];
	local[3]= local[0];
	local[4]= fqv[5];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,2,local+2); /*error*/
	w = NIL;
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK682;
	goto IF689;
IF688:
	local[2]= NIL;
IF689:
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)GETCLASS(ctx,1,local+2); /*class*/
	local[2]= w;
	if (loadglobal(fqv[8])==local[2]) goto IF691;
	local[2]= fqv[22];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)GETCLASS(ctx,1,local+3); /*class*/
	local[3]= w;
	local[4]= fqv[5];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,2,local+2); /*error*/
	w = NIL;
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK682;
	goto IF692;
IF691:
	local[2]= NIL;
IF692:
	local[2]= local[0];
	local[3]= fqv[23];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	if (w==NIL) goto IF693;
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= local[0];
	local[4]= fqv[23];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= fqv[5];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	if (w==local[2]) goto IF693;
	local[2]= fqv[24];
	local[3]= local[0];
	local[4]= fqv[23];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[5];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,3,local+2); /*error*/
	w = NIL;
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK682;
	goto IF694;
IF693:
	local[2]= NIL;
IF694:
	local[2]= argv[0];
	local[3]= fqv[25];
	local[4]= local[0];
	local[5]= fqv[5];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	if (w==NIL) goto IF695;
	local[2]= fqv[26];
	local[3]= local[0];
	local[4]= fqv[5];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,2,local+2); /*error*/
	w = NIL;
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK682;
	goto IF696;
IF695:
	local[2]= NIL;
IF696:
	goto WHL684;
WHX685:
	local[2]= NIL;
BLK686:
	w = NIL;
	local[0]= NIL;
	local[1]= argv[2];
WHL698:
	if (local[1]==NIL) goto WHX699;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0];
	local[3]= fqv[7];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	goto WHL698;
WHX699:
	local[2]= NIL;
BLK700:
	w = NIL;
	local[0]= argv[0]->c.obj.iv[9];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	w = T;
	local[0]= w;
BLK682:
	ctx->vsp=local; return(local[0]);}

/*:add-spot*/
static pointer M702scene_model_add_spot(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[27];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK703:
	ctx->vsp=local; return(local[0]);}

/*:remove-spots*/
static pointer M704scene_model_remove_spots(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[2];
WHL707:
	if (local[1]==NIL) goto WHX708;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)GETCLASS(ctx,1,local+2); /*class*/
	local[2]= w;
	if (loadglobal(fqv[8])==local[2]) goto IF711;
	local[2]= fqv[28];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)GETCLASS(ctx,1,local+3); /*class*/
	local[3]= w;
	local[4]= fqv[5];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,2,local+2); /*error*/
	w = NIL;
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK705;
	goto IF712;
IF711:
	local[2]= NIL;
IF712:
	goto WHL707;
WHX708:
	local[2]= NIL;
BLK709:
	w = NIL;
	local[0]= argv[0];
	local[1]= fqv[19];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= local[0];
WHL714:
	if (local[2]==NIL) goto WHX715;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	local[4]= fqv[23];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= fqv[29];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	goto WHL714;
WHX715:
	local[3]= NIL;
BLK716:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK705:
	ctx->vsp=local; return(local[0]);}

/*:remove-spot*/
static pointer M718scene_model_remove_spot(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[30];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK719:
	ctx->vsp=local; return(local[0]);}

/*:spots*/
static pointer M720scene_model_spots(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO722,env,argv,local);
	local[1]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO723,env,argv,local);
	local[2]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,2,local+1,&ftab[3],fqv[31]); /*remove-if-not*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	local[0]= w;
BLK721:
	ctx->vsp=local; return(local[0]);}

/*:object*/
static pointer M724scene_model_object(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[13];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= local[1];
	if (fqv[32]!=local[2]) goto IF727;
	local[2]= makeint((eusinteger_t)1L);
	local[3]= fqv[33];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,3,local+2,&ftab[4],fqv[34]); /*warning-message*/
	local[2]= NIL;
	goto IF728;
IF727:
	local[2]= local[1];
	if (fqv[35]!=local[2]) goto IF729;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	goto IF730;
IF729:
	if (T==NIL) goto IF731;
	local[2]= makeint((eusinteger_t)1L);
	local[3]= fqv[36];
	local[4]= local[0];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,4,local+2,&ftab[4],fqv[34]); /*warning-message*/
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	goto IF732;
IF731:
	local[2]= NIL;
IF732:
IF730:
IF728:
	w = local[2];
	local[0]= w;
BLK725:
	ctx->vsp=local; return(local[0]);}

/*:spot*/
static pointer M733scene_model_spot(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO735,env,argv,local);
	local[1]= argv[0];
	local[2]= fqv[37];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,2,local+0,&ftab[3],fqv[31]); /*remove-if-not*/
	local[0]= w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= local[1];
	if (fqv[38]!=local[2]) goto IF737;
	local[2]= makeint((eusinteger_t)1L);
	local[3]= fqv[39];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,3,local+2,&ftab[4],fqv[34]); /*warning-message*/
	local[2]= NIL;
	goto IF738;
IF737:
	local[2]= local[1];
	if (fqv[40]!=local[2]) goto IF739;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	goto IF740;
IF739:
	if (T==NIL) goto IF741;
	local[2]= makeint((eusinteger_t)1L);
	local[3]= fqv[41];
	local[4]= local[0];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,4,local+2,&ftab[4],fqv[34]); /*warning-message*/
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	goto IF742;
IF741:
	local[2]= NIL;
IF742:
IF740:
IF738:
	w = local[2];
	local[0]= w;
BLK734:
	ctx->vsp=local; return(local[0]);}

/*:bodies*/
static pointer M743scene_model_bodies(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO745,env,argv,local);
	local[1]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[5])(ctx,1,local+0,&ftab[5],fqv[42]); /*flatten*/
	local[0]= w;
BLK744:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO643(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[5];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= (isstring(w)?T:NIL);
	if (local[0]==NIL) goto AND746;
	local[0]= fqv[43];
	local[1]= argv[0];
	local[2]= fqv[5];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,2,local+0,&ftab[6],fqv[44]); /*substringp*/
	local[0]= w;
AND746:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO679(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[45]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto IF747;
	local[0]= argv[0];
	local[1]= fqv[13];
	local[2]= env->c.clo.env1[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF748;
IF747:
	local[0]= NIL;
IF748:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO680(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[2];
	local[1]= argv[0];
	local[2]= fqv[5];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,2,local+0,&ftab[7],fqv[46]); /*string=*/
	if (w==NIL) goto IF749;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF750;
IF749:
	local[0]= NIL;
IF750:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO722(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[45]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto IF751;
	local[0]= argv[0];
	local[1]= fqv[37];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF752;
IF751:
	local[0]= NIL;
IF752:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO723(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)GETCLASS(ctx,1,local+0); /*class*/
	local[0]= w;
	w = ((loadglobal(fqv[8]))==(local[0])?T:NIL);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO735(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[2];
	local[1]= argv[0];
	local[2]= fqv[5];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,2,local+0,&ftab[7],fqv[46]); /*string=*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO745(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[47];
	ctx->vsp=local+2;
	w=(*ftab[8])(ctx,2,local+0,&ftab[8],fqv[48]); /*find-method*/
	if (w==NIL) goto IF753;
	local[0]= argv[0];
	local[1]= fqv[47];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF754;
IF753:
	local[0]= argv[0];
IF754:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___irtscene(ctx,n,argv,env)
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
	local[0]= fqv[49];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF755;
	local[0]= fqv[50];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[51],w);
	goto IF756;
IF755:
	local[0]= fqv[52];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF756:
	local[0]= fqv[45];
	local[1]= fqv[53];
	local[2]= fqv[45];
	local[3]= fqv[54];
	local[4]= loadglobal(fqv[8]);
	local[5]= fqv[55];
	local[6]= fqv[56];
	local[7]= fqv[57];
	local[8]= NIL;
	local[9]= fqv[58];
	local[10]= NIL;
	local[11]= fqv[12];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[59];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[9])(ctx,13,local+2,&ftab[9],fqv[60]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M635scene_model_init,fqv[4],fqv[45],fqv[61]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M651scene_model_objects,fqv[62],fqv[45],fqv[63]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M653scene_model_add_objects,fqv[15],fqv[45],fqv[64]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M662scene_model_add_object,fqv[65],fqv[45],fqv[66]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M664scene_model_remove_objects,fqv[19],fqv[45],fqv[67]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M675scene_model_remove_object,fqv[68],fqv[45],fqv[69]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M677scene_model_find_object,fqv[13],fqv[45],fqv[70]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M681scene_model_add_spots,fqv[27],fqv[45],fqv[71]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M702scene_model_add_spot,fqv[72],fqv[45],fqv[73]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M704scene_model_remove_spots,fqv[30],fqv[45],fqv[74]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M718scene_model_remove_spot,fqv[75],fqv[45],fqv[76]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M720scene_model_spots,fqv[37],fqv[45],fqv[77]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M724scene_model_object,fqv[16],fqv[45],fqv[78]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M733scene_model_spot,fqv[25],fqv[45],fqv[79]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M743scene_model_bodies,fqv[47],fqv[45],fqv[80]);
	local[0]= fqv[81];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF757;
	local[0]= fqv[82];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[51],w);
	goto IF758;
IF757:
	local[0]= fqv[83];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF758:
	local[0]= fqv[84];
	local[1]= fqv[85];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,2,local+0,&ftab[10],fqv[86]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<11; i++) ftab[i]=fcallx;
}
