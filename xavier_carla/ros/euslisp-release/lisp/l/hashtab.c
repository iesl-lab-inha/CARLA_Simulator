/* ./hashtab.c :  entry=hashtab */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "hashtab.h"
#pragma init (register_hashtab)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___hashtab();
extern pointer build_quote_vector();
static int register_hashtab()
  { add_module_initializer("___hashtab", ___hashtab);}

static pointer F60567make_hash_table();
static pointer F60570gethash();
static pointer F60573sethash();
static pointer F60576remhash();
static pointer F60579hash_table_p();
static pointer F60582maphash();
static pointer F60585clrhash();

/*:size*/
static pointer M60672hash_table_size(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK60673:
	ctx->vsp=local; return(local[0]);}

/*:find*/
static pointer M60688hash_table_find(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)FUNCALL(ctx,2,local+0); /*funcall*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)MOD(ctx,2,local+0); /*mod*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)ABS(ctx,1,local+0); /*abs*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
WHL60724:
	if (T==NIL) goto WHX60725;
	local[3]= argv[0]->c.obj.iv[0];
	{ register eusinteger_t i=intval(local[0]);
	  w=(local[3]->c.vec.v[i]);}
	local[1] = w;
	local[3]= argv[0]->c.obj.iv[5];
	local[4]= local[1];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)FUNCALL(ctx,3,local+3); /*funcall*/
	if (w==NIL) goto IF60742;
	w = local[0];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK60689;
	goto IF60743;
IF60742:
	local[3]= NIL;
IF60743:
	local[3]= local[1];
	if (argv[0]->c.obj.iv[7]!=local[3]) goto IF60758;
	if (local[2]!=NIL) goto IF60768;
	local[2] = local[0];
	local[3]= local[2];
	goto IF60769;
IF60768:
	local[3]= NIL;
IF60769:
	local[3]= local[2];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK60689;
	goto IF60759;
IF60758:
	local[3]= NIL;
IF60759:
	local[3]= local[1];
	if (argv[0]->c.obj.iv[8]!=local[3]) goto IF60791;
	if (local[2]!=NIL) goto IF60801;
	local[2] = local[0];
	local[3]= local[2];
	goto IF60802;
IF60801:
	local[3]= NIL;
IF60802:
	goto IF60792;
IF60791:
	local[3]= NIL;
IF60792:
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[0] = w;
	local[3]= local[0];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)GREQP(ctx,2,local+3); /*>=*/
	if (w==NIL) goto IF60814;
	local[0] = makeint(0);
	local[3]= local[0];
	goto IF60815;
IF60814:
	local[3]= NIL;
IF60815:
	goto WHL60724;
WHX60725:
	local[3]= NIL;
BLK60726:
	w = NIL;
	local[0]= w;
BLK60689:
	ctx->vsp=local; return(local[0]);}

/*:get*/
static pointer M60838hash_table_get(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)GREQP(ctx,2,local+1); /*>=*/
	if (w==NIL) goto IF60869;
	local[1]= argv[0]->c.obj.iv[9];
	goto IF60870;
IF60869:
	local[1]= argv[0]->c.obj.iv[1];
	{ register eusinteger_t i=intval(local[0]);
	  w=(local[1]->c.vec.v[i]);}
	local[1]= w;
IF60870:
	w = local[1];
	local[0]= w;
BLK60839:
	ctx->vsp=local; return(local[0]);}

/*:enter*/
static pointer M60884hash_table_enter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)GREQP(ctx,2,local+1); /*>=*/
	if (w==NIL) goto IF60918;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)GREATERP(ctx,2,local+1); /*>*/
	if (w==NIL) goto IF60929;
	local[1]= argv[0];
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0] = w;
	local[1]= local[0];
	goto IF60930;
IF60929:
	local[1]= NIL;
IF60930:
	local[1]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+2;
	w=(pointer)ADD1(ctx,1,local+1); /*1+*/
	argv[0]->c.obj.iv[3] = w;
	local[1]= local[0];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[0] = w;
	local[1]= local[0];
	goto IF60919;
IF60918:
	local[1]= NIL;
IF60919:
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= local[0];
	w = argv[2];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[2]); v=local[1];
	  v->c.vec.v[i]=w;}
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= local[0];
	w = argv[3];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[2]); v=local[1];
	  v->c.vec.v[i]=w;}
	w = argv[3];
	local[0]= w;
BLK60885:
	ctx->vsp=local; return(local[0]);}

/*:delete*/
static pointer M61000hash_table_delete(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(0);
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto IF61035;
	local[2]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+3;
	w=(pointer)SUB1(ctx,1,local+2); /*1-*/
	argv[0]->c.obj.iv[3] = w;
	local[2]= argv[0]->c.obj.iv[0];
	local[3]= local[0];
	w = argv[0]->c.obj.iv[8];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[3]); v=local[2];
	  v->c.vec.v[i]=w;}
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= local[0];
	w = NIL;
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[3]); v=local[2];
	  v->c.vec.v[i]=w;}
	local[2]= w;
	goto IF61036;
IF61035:
	local[2]= NIL;
IF61036:
	w = local[2];
	local[0]= w;
BLK61001:
	ctx->vsp=local; return(local[0]);}

/*:extend*/
static pointer M61069hash_table_extend(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(2);
	{ eusinteger_t i,j;
		j=intval(argv[0]->c.obj.iv[2]); i=intval(local[0]);
		local[0]=(makeint(i * j));}
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[2]); /*make-array*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,1,local+2,&ftab[0],fqv[2]); /*make-array*/
	local[2]= w;
	local[3]= NIL;
	local[4]= makeint(0);
	local[5]= local[0];
WHL61132:
	local[6]= local[4];
	w = local[5];
	if ((eusinteger_t)local[6] >= (eusinteger_t)w) goto WHX61133;
	local[6]= local[1];
	local[7]= local[4];
	w = argv[0]->c.obj.iv[7];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[7]); v=local[6];
	  v->c.vec.v[i]=w;}
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[4] = w;
	goto WHL61132;
WHX61133:
	local[6]= NIL;
BLK61134:
	w = NIL;
	local[3] = argv[0]->c.obj.iv[0];
	argv[0]->c.obj.iv[0] = local[1];
	local[1] = local[3];
	local[3] = argv[0]->c.obj.iv[1];
	argv[0]->c.obj.iv[1] = local[2];
	local[2] = local[3];
	local[3] = argv[0]->c.obj.iv[2];
	argv[0]->c.obj.iv[2] = local[0];
	local[0] = local[3];
	argv[0]->c.obj.iv[3] = makeint(0);
	local[4]= makeint(0);
	local[5]= local[0];
WHL61216:
	local[6]= local[4];
	w = local[5];
	if ((eusinteger_t)local[6] >= (eusinteger_t)w) goto WHX61217;
	local[6]= local[1];
	{ register eusinteger_t i=intval(local[4]);
	  w=(local[6]->c.vec.v[i]);}
	local[3] = w;
	local[6]= local[3];
	if (argv[0]->c.obj.iv[7]==local[6]) goto IF61236;
	local[6]= local[3];
	if (argv[0]->c.obj.iv[8]==local[6]) goto IF61236;
	local[6]= argv[0];
	local[7]= fqv[3];
	local[8]= local[3];
	local[9]= local[2];
	{ register eusinteger_t i=intval(local[4]);
	  w=(local[9]->c.vec.v[i]);}
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[6]= w;
	goto IF61237;
IF61236:
	local[6]= NIL;
IF61237:
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[4] = w;
	goto WHL61216;
WHX61217:
	local[6]= NIL;
BLK61218:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK61070:
	ctx->vsp=local; return(local[0]);}

/*:hash*/
static pointer M61276hash_table_hash(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[4]); /*string*/
	argv[2] = w;
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,1,local+1,&ftab[1],fqv[4]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)FUNCALL(ctx,2,local+0); /*funcall*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)MOD(ctx,2,local+0); /*mod*/
	local[0]= w;
BLK61277:
	ctx->vsp=local; return(local[0]);}

/*:map*/
static pointer M61311hash_table_map(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= makeint(0);
	local[3]= argv[0]->c.obj.iv[2];
WHL61361:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX61362;
	local[4]= argv[0]->c.obj.iv[0];
	{ register eusinteger_t i=intval(local[2]);
	  w=(local[4]->c.vec.v[i]);}
	local[0] = w;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w!=NIL) goto IF61382;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w!=NIL) goto IF61382;
	local[4]= argv[2];
	local[5]= local[0];
	local[6]= argv[0]->c.obj.iv[1];
	{ register eusinteger_t i=intval(local[2]);
	  w=(local[6]->c.vec.v[i]);}
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)FUNCALL(ctx,3,local+4); /*funcall*/
	local[4]= w;
	goto IF61383;
IF61382:
	local[4]= NIL;
IF61383:
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL61361;
WHX61362:
	local[4]= NIL;
BLK61363:
	w = NIL;
	local[0]= w;
BLK61313:
	ctx->vsp=local; return(local[0]);}

/*:list-values*/
static pointer M61424hash_table_list_values(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= makeint(0);
	local[3]= argv[0]->c.obj.iv[2];
WHL61471:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX61472;
	local[4]= argv[0]->c.obj.iv[0];
	{ register eusinteger_t i=intval(local[2]);
	  w=(local[4]->c.vec.v[i]);}
	local[0] = w;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w!=NIL) goto IF61492;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w!=NIL) goto IF61492;
	local[4]= argv[0]->c.obj.iv[1];
	{ register eusinteger_t i=intval(local[2]);
	  w=(local[4]->c.vec.v[i]);}
	local[4]= w;
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[1];
	goto IF61493;
IF61492:
	local[4]= NIL;
IF61493:
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL61471;
WHX61472:
	local[4]= NIL;
BLK61473:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK61425:
	ctx->vsp=local; return(local[0]);}

/*:list-keys*/
static pointer M61543hash_table_list_keys(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= makeint(0);
	local[3]= argv[0]->c.obj.iv[2];
WHL61590:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX61591;
	local[4]= argv[0]->c.obj.iv[0];
	{ register eusinteger_t i=intval(local[2]);
	  w=(local[4]->c.vec.v[i]);}
	local[0] = w;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w!=NIL) goto IF61611;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w!=NIL) goto IF61611;
	local[4]= local[0];
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[1];
	goto IF61612;
IF61611:
	local[4]= NIL;
IF61612:
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL61590;
WHX61591:
	local[4]= NIL;
BLK61592:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK61544:
	ctx->vsp=local; return(local[0]);}

/*:list*/
static pointer M61658hash_table_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= makeint(0);
	local[3]= argv[0]->c.obj.iv[2];
WHL61705:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX61706;
	local[4]= argv[0]->c.obj.iv[0];
	{ register eusinteger_t i=intval(local[2]);
	  w=(local[4]->c.vec.v[i]);}
	local[0] = w;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w!=NIL) goto IF61726;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w!=NIL) goto IF61726;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[1];
	{ register eusinteger_t i=intval(local[2]);
	  w=(local[5]->c.vec.v[i]);}
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[1];
	goto IF61727;
IF61726:
	local[4]= NIL;
IF61727:
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL61705;
WHX61706:
	local[4]= NIL;
BLK61707:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK61659:
	ctx->vsp=local; return(local[0]);}

/*:hash-function*/
static pointer M61780hash_table_hash_function(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT61784;}
	local[0]= NIL;
ENT61784:
ENT61783:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF61800;
	argv[0]->c.obj.iv[4] = local[0];
	local[1]= argv[0]->c.obj.iv[4];
	goto IF61801;
IF61800:
	local[1]= NIL;
IF61801:
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK61781:
	ctx->vsp=local; return(local[0]);}

/*:clear*/
static pointer M61816hash_table_clear(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(0);
	local[1]= argv[0]->c.obj.iv[2];
WHL61852:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX61853;
	local[2]= argv[0]->c.obj.iv[0];
	local[3]= local[0];
	w = argv[0]->c.obj.iv[7];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[3]); v=local[2];
	  v->c.vec.v[i]=w;}
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= local[0];
	w = NIL;
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[3]); v=local[2];
	  v->c.vec.v[i]=w;}
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL61852;
WHX61853:
	local[2]= NIL;
BLK61854:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK61817:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M61895hash_table_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT61899;}
	local[0]= T;
ENT61899:
ENT61898:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-3);
	local[2]= (pointer)get_sym_func(fqv[5]);
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[6]));
	local[5]= fqv[7];
	local[6]= local[0];
	local[7]= NIL;
	local[8]= fqv[8];
	local[9]= argv[0]->c.obj.iv[3];
	local[10]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,4,local+7); /*format*/
	local[7]= w;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,7,local+2); /*apply*/
	local[0]= w;
BLK61896:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M61933hash_table_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[9], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY61949;
	local[0] = NIL;
KEY61949:
	if (n & (1<<1)) goto KEY61954;
	local[1] = makeint(10);
KEY61954:
	if (n & (1<<2)) goto KEY61959;
	local[2] = (pointer)get_sym_func(fqv[10]);
KEY61959:
	if (n & (1<<3)) goto KEY61966;
	local[3] = makeflt(2.00000000e+00);
KEY61966:
	if (n & (1<<4)) goto KEY61971;
	local[4] = (pointer)get_sym_func(fqv[11]);
KEY61971:
	argv[0]->c.obj.iv[2] = local[1];
	local[5]= loadglobal(fqv[12]);
	local[6]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,2,local+5); /*instantiate*/
	argv[0]->c.obj.iv[0] = w;
	local[5]= loadglobal(fqv[12]);
	local[6]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,2,local+5); /*instantiate*/
	argv[0]->c.obj.iv[1] = w;
	argv[0]->c.obj.iv[4] = local[4];
	argv[0]->c.obj.iv[5] = local[2];
	local[5]= fqv[13];
	ctx->vsp=local+6;
	w=(pointer)GENSYM(ctx,1,local+5); /*gensym*/
	argv[0]->c.obj.iv[7] = w;
	local[5]= fqv[14];
	ctx->vsp=local+6;
	w=(pointer)GENSYM(ctx,1,local+5); /*gensym*/
	argv[0]->c.obj.iv[8] = w;
	argv[0]->c.obj.iv[9] = local[0];
	argv[0]->c.obj.iv[3] = makeint(0);
	argv[0]->c.obj.iv[6] = local[3];
	local[5]= makeint(0);
	local[6]= local[1];
WHL62047:
	local[7]= local[5];
	w = local[6];
	if ((eusinteger_t)local[7] >= (eusinteger_t)w) goto WHX62048;
	local[7]= argv[0]->c.obj.iv[0];
	local[8]= local[5];
	w = argv[0]->c.obj.iv[7];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[8]); v=local[7];
	  v->c.vec.v[i]=w;}
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[5] = w;
	goto WHL62047;
WHX62048:
	local[7]= NIL;
BLK62049:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK61934:
	ctx->vsp=local; return(local[0]);}

/*make-hash-table*/
static pointer F60567make_hash_table(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[15], &argv[0], n-0, local+0, 0);
	if (n & (1<<0)) goto KEY62092;
	local[0] = makeint(10);
KEY62092:
	if (n & (1<<1)) goto KEY62097;
	local[1] = (pointer)get_sym_func(fqv[10]);
KEY62097:
	if (n & (1<<2)) goto KEY62104;
	local[2] = makeflt(1.70000000e+00);
KEY62104:
	if (n & (1<<3)) goto KEY62109;
	local[3] = (pointer)get_sym_func(fqv[11]);
KEY62109:
	if (n & (1<<4)) goto KEY62116;
	local[4] = NIL;
KEY62116:
	local[5]= loadglobal(fqv[16]);
	ctx->vsp=local+6;
	w=(pointer)INSTANTIATE(ctx,1,local+5); /*instantiate*/
	local[5]= w;
	local[6]= local[5];
	local[7]= fqv[17];
	local[8]= fqv[18];
	local[9]= local[0];
	local[10]= fqv[19];
	local[11]= local[1];
	local[12]= fqv[20];
	local[13]= local[2];
	local[14]= fqv[21];
	local[15]= local[3];
	local[16]= fqv[22];
	local[17]= local[4];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,12,local+6); /*send*/
	w = local[5];
	local[0]= w;
BLK62081:
	ctx->vsp=local; return(local[0]);}

/*gethash*/
static pointer F60570gethash(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= fqv[23];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK62167:
	ctx->vsp=local; return(local[0]);}

/*sethash*/
static pointer F60573sethash(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[1];
	local[1]= fqv[3];
	local[2]= argv[0];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK62187:
	ctx->vsp=local; return(local[0]);}

/*remhash*/
static pointer F60576remhash(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= fqv[24];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK62210:
	ctx->vsp=local; return(local[0]);}

/*hash-table-p*/
static pointer F60579hash_table_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[16]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK62230:
	ctx->vsp=local; return(local[0]);}

/*maphash*/
static pointer F60582maphash(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= fqv[25];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK62246:
	ctx->vsp=local; return(local[0]);}

/*clrhash*/
static pointer F60585clrhash(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[26];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK62266:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M62299queue_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[0] = NIL;
	argv[0]->c.obj.iv[1] = NIL;
	w = argv[0];
	local[0]= w;
BLK62300:
	ctx->vsp=local; return(local[0]);}

/*:length*/
static pointer M62323queue_length(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
BLK62324:
	ctx->vsp=local; return(local[0]);}

/*:empty?*/
static pointer M62340queue_empty_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = ((argv[0]->c.obj.iv[0])==NIL?T:NIL);
	local[0]= w;
BLK62341:
	ctx->vsp=local; return(local[0]);}

/*:trim*/
static pointer M62359queue_trim(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeint(0);
	local[1]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
WHL62405:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX62406;
	local[2]= argv[0];
	local[3]= fqv[27];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL62405;
WHX62406:
	local[2]= NIL;
BLK62407:
	w = NIL;
	local[0]= w;
BLK62360:
	ctx->vsp=local; return(local[0]);}

/*:dequeue*/
static pointer M62432queue_dequeue(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT62436;}
	local[0]= NIL;
ENT62436:
ENT62435:
	if (n>3) maerror();
	if (argv[0]->c.obj.iv[0]!=NIL) goto CON62454;
	if (local[0]==NIL) goto IF62460;
	local[1]= fqv[28];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,2,local+1); /*error*/
	local[1]= w;
	goto IF62461;
IF62460:
	local[1]= NIL;
IF62461:
	goto CON62452;
CON62454:
	local[1]= argv[0]->c.obj.iv[0];
	if (argv[0]->c.obj.iv[1]!=local[1]) goto CON62468;
	w=argv[0]->c.obj.iv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	argv[0]->c.obj.iv[0] = NIL;
	argv[0]->c.obj.iv[1] = NIL;
	w = local[1];
	local[1]= w;
	goto CON62452;
CON62468:
	w=argv[0]->c.obj.iv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[0] = (w)->c.cons.cdr;
	w = local[1];
	local[1]= w;
	goto CON62452;
CON62505:
	local[1]= NIL;
CON62452:
	w = local[1];
	local[0]= w;
BLK62433:
	ctx->vsp=local; return(local[0]);}

/*:enqueue*/
static pointer M62544queue_enqueue(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[0]->c.obj.iv[1]==NIL) goto CON62561;
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	w = NIL;
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	ctx->vsp=local+2;
	w=(pointer)RPLACD2(ctx,2,local+0); /*rplacd2*/
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[1] = (w)->c.cons.cdr;
	local[0]= argv[0]->c.obj.iv[1];
	goto CON62559;
CON62561:
	local[0]= argv[2];
	w = NIL;
	ctx->vsp=local+1;
	argv[0]->c.obj.iv[1] = cons(ctx,local[0],w);
	argv[0]->c.obj.iv[0] = argv[0]->c.obj.iv[1];
	local[0]= argv[0]->c.obj.iv[0];
	goto CON62559;
CON62586:
	local[0]= NIL;
CON62559:
	w = argv[2];
	local[0]= w;
BLK62545:
	ctx->vsp=local; return(local[0]);}

/*:search*/
static pointer M62610queue_search(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT62614;}
	local[0]= (pointer)get_sym_func(fqv[29]);
ENT62614:
ENT62613:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[0];
	local[3]= fqv[19];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,4,local+1,&ftab[2],fqv[30]); /*find*/
	local[0]= w;
BLK62611:
	ctx->vsp=local; return(local[0]);}

/*:delete*/
static pointer M62643queue_delete(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT62648;}
	local[0]= (pointer)get_sym_func(fqv[29]);
ENT62648:
	if (n>=5) { local[1]=(argv[4]); goto ENT62647;}
	local[1]= makeint(1);
ENT62647:
ENT62646:
	if (n>5) maerror();
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[0];
	local[4]= fqv[19];
	local[5]= local[0];
	local[6]= fqv[31];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[3])(ctx,6,local+2,&ftab[3],fqv[32]); /*delete*/
	argv[0]->c.obj.iv[0] = w;
	local[2]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+3;
	w=(*ftab[4])(ctx,1,local+2,&ftab[4],fqv[33]); /*last*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0];
	local[0]= w;
BLK62644:
	ctx->vsp=local; return(local[0]);}

/*:first*/
static pointer M62702queue_first(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK62703:
	ctx->vsp=local; return(local[0]);}

/*:last*/
static pointer M62722queue_last(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK62723:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___hashtab(ctx,n,argv,env)
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
	local[0]= fqv[34];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF62748;
	local[0]= fqv[35];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[36],w);
	goto IF62749;
IF62748:
	local[0]= fqv[37];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF62749:
	local[0]= fqv[38];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[16];
	local[1]= fqv[39];
	local[2]= fqv[16];
	local[3]= fqv[40];
	local[4]= loadglobal(fqv[41]);
	local[5]= fqv[42];
	local[6]= fqv[43];
	local[7]= fqv[44];
	local[8]= NIL;
	local[9]= fqv[45];
	local[10]= NIL;
	local[11]= fqv[18];
	local[12]= makeint(-1);
	local[13]= fqv[46];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[5])(ctx,13,local+2,&ftab[5],fqv[47]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[48];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M60672hash_table_size,fqv[18],fqv[16],fqv[49]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M60688hash_table_find,fqv[0],fqv[16],fqv[50]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M60838hash_table_get,fqv[23],fqv[16],fqv[51]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M60884hash_table_enter,fqv[3],fqv[16],fqv[52]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M61000hash_table_delete,fqv[24],fqv[16],fqv[53]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M61069hash_table_extend,fqv[1],fqv[16],fqv[54]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M61276hash_table_hash,fqv[21],fqv[16],fqv[55]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M61311hash_table_map,fqv[25],fqv[16],fqv[56]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M61424hash_table_list_values,fqv[57],fqv[16],fqv[58]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M61543hash_table_list_keys,fqv[59],fqv[16],fqv[60]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M61658hash_table_list,fqv[61],fqv[16],fqv[62]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M61780hash_table_hash_function,fqv[63],fqv[16],fqv[64]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M61816hash_table_clear,fqv[26],fqv[16],fqv[65]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M61895hash_table_prin1,fqv[7],fqv[16],fqv[66]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M61933hash_table_init,fqv[17],fqv[16],fqv[67]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[68],module,F60567make_hash_table,fqv[69]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[70],module,F60570gethash,fqv[71]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[72],module,F60573sethash,fqv[73]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[74],module,F60576remhash,fqv[75]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[76],module,F60579hash_table_p,fqv[77]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[78],module,F60582maphash,fqv[79]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[80],module,F60585clrhash,fqv[81]);
	local[0]= fqv[82];
	local[1]= fqv[39];
	local[2]= fqv[82];
	local[3]= fqv[40];
	local[4]= loadglobal(fqv[83]);
	local[5]= fqv[42];
	local[6]= fqv[84];
	local[7]= fqv[44];
	local[8]= NIL;
	local[9]= fqv[45];
	local[10]= NIL;
	local[11]= fqv[18];
	local[12]= makeint(-1);
	local[13]= fqv[46];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[5])(ctx,13,local+2,&ftab[5],fqv[47]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M62299queue_init,fqv[17],fqv[82],fqv[85]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M62323queue_length,fqv[86],fqv[82],fqv[87]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M62340queue_empty_,fqv[88],fqv[82],fqv[89]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M62359queue_trim,fqv[90],fqv[82],fqv[91]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M62432queue_dequeue,fqv[27],fqv[82],fqv[92]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M62544queue_enqueue,fqv[93],fqv[82],fqv[94]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M62610queue_search,fqv[95],fqv[82],fqv[96]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M62643queue_delete,fqv[24],fqv[82],fqv[97]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M62702queue_first,fqv[98],fqv[82],fqv[99]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M62722queue_last,fqv[100],fqv[82],fqv[101]);
	local[0]= fqv[102];
	local[1]= fqv[103];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,2,local+0,&ftab[6],fqv[104]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<7; i++) ftab[i]=fcallx;
}
