/* ./irtgraph.c :  entry=irtgraph */
/* compiled by EusLisp 9.27() for Linux created on ip-10-0-1-214(Fri Apr 16 04:05:26 PST 2021) */
#include "eus.h"
#include "irtgraph.h"
#pragma init (register_irtgraph)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___irtgraph();
extern pointer build_quote_vector();
static int register_irtgraph()
  { add_module_initializer("___irtgraph", ___irtgraph);}


/*:init*/
static pointer M840node_init(ctx,n,argv,env)
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
	w = argv[0];
	local[0]= w;
BLK841:
	ctx->vsp=local; return(local[0]);}

/*:arc-list*/
static pointer M842node_arc_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK843:
	ctx->vsp=local; return(local[0]);}

/*:successors*/
static pointer M844node_successors(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO846,env,argv,local);
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	local[0]= w;
BLK845:
	ctx->vsp=local; return(local[0]);}

/*:add-arc*/
static pointer M847node_add_arc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	w = argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	argv[0]->c.obj.iv[1] = cons(ctx,local[0],w);
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK848:
	ctx->vsp=local; return(local[0]);}

/*:remove-arc*/
static pointer M849node_remove_arc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[1]); /*remove*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK850:
	ctx->vsp=local; return(local[0]);}

/*:remove-all-arcs*/
static pointer M851node_remove_all_arcs(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[1] = NIL;
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK852:
	ctx->vsp=local; return(local[0]);}

/*:unlink*/
static pointer M853node_unlink(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO855,env,argv,local);
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[2]); /*remove-if*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK854:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO846(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= argv[0];
	local[2]= fqv[3];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO855(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[2];
	local[1]= argv[0];
	local[2]= fqv[3];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = ((w)==(local[0])?T:NIL);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M856arc_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	argv[0]->c.obj.iv[1] = argv[2];
	argv[0]->c.obj.iv[2] = argv[3];
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[4];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	w = argv[0];
	local[0]= w;
BLK857:
	ctx->vsp=local; return(local[0]);}

/*:from*/
static pointer M858arc_from(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK859:
	ctx->vsp=local; return(local[0]);}

/*:to*/
static pointer M860arc_to(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK861:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M862arc_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT865;}
	local[0]= T;
ENT865:
ENT864:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-3);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[5]));
	local[4]= fqv[6];
	local[5]= local[0];
	local[6]= NIL;
	local[7]= fqv[7];
	local[8]= argv[0]->c.obj.iv[1];
	local[9]= argv[0]->c.obj.iv[2];
	local[10]= local[1];
	if (local[10]!=NIL) goto OR866;
	local[10]= fqv[8];
OR866:
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,5,local+6); /*format*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,5,local+2); /*send-message*/
	local[0]= w;
BLK863:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M867directed_graph_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0];
	local[0]= w;
BLK868:
	ctx->vsp=local; return(local[0]);}

/*:successors*/
static pointer M869directed_graph_successors(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[9],w);
RST871:
	ctx->vsp=local+3;
	local[3]= minilist(ctx,&argv[n],n-3);
	local[4]= loadglobal(fqv[9]);
	local[5]= fqv[10];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	unbindx(ctx,1);
	w = local[4];
	local[0]= w;
BLK870:
	ctx->vsp=local; return(local[0]);}

/*:node*/
static pointer M872directed_graph_node(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= fqv[11];
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO874,env,argv,local);
	local[4]= fqv[12];
	local[5]= (pointer)get_sym_func(fqv[13]);
	ctx->vsp=local+6;
	w=(*ftab[2])(ctx,6,local+0,&ftab[2],fqv[14]); /*find*/
	local[0]= w;
BLK873:
	ctx->vsp=local; return(local[0]);}

/*:nodes*/
static pointer M875directed_graph_nodes(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT878;}
	local[0]= NIL;
ENT878:
ENT877:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF879;
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[3])(ctx,2,local+2,&ftab[3],fqv[15]); /*set-difference*/
	local[2]= w;
WHL882:
	if (local[2]==NIL) goto WHX883;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[0];
	local[4]= fqv[16];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,3,local+3,&ftab[4],fqv[17]); /*send-all*/
	goto WHL882;
WHX883:
	local[3]= NIL;
BLK884:
	w = NIL;
	argv[0]->c.obj.iv[1] = local[0];
	local[1]= argv[0]->c.obj.iv[1];
	goto IF880;
IF879:
	local[1]= NIL;
IF880:
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK876:
	ctx->vsp=local; return(local[0]);}

/*:add-node*/
static pointer M886directed_graph_add_node(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	w = argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	argv[0]->c.obj.iv[1] = cons(ctx,local[0],w);
	w = argv[2];
	local[0]= w;
BLK887:
	ctx->vsp=local; return(local[0]);}

/*:remove-node*/
static pointer M888directed_graph_remove_node(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[1]); /*remove*/
	argv[0]->c.obj.iv[1] = w;
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[16];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[4])(ctx,3,local+0,&ftab[4],fqv[17]); /*send-all*/
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK889:
	ctx->vsp=local; return(local[0]);}

/*:clear-nodes*/
static pointer M890directed_graph_clear_nodes(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[17]); /*send-all*/
	argv[0]->c.obj.iv[1] = NIL;
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK891:
	ctx->vsp=local; return(local[0]);}

/*:add-arc-from-to*/
static pointer M892directed_graph_add_arc_from_to(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= loadglobal(fqv[19]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[20];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK893:
	ctx->vsp=local; return(local[0]);}

/*:remove-arc*/
static pointer M895directed_graph_remove_arc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[19],w);
	local[3]= loadglobal(fqv[19]);
	local[4]= fqv[21];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= fqv[22];
	local[5]= loadglobal(fqv[19]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK896:
	ctx->vsp=local; return(local[0]);}

/*:adjacency-matrix*/
static pointer M897directed_graph_adjacency_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= local[0];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[5])(ctx,2,local+3,&ftab[5],fqv[23]); /*make-matrix*/
	local[1] = w;
	local[3]= makeint((eusinteger_t)0L);
	local[4]= local[0];
WHL900:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX901;
	local[5]= NIL;
	local[6]= argv[0]->c.obj.iv[1];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	local[7]= fqv[24];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= fqv[3];
	ctx->vsp=local+8;
	w=(*ftab[4])(ctx,2,local+6,&ftab[4],fqv[17]); /*send-all*/
	local[6]= w;
WHL904:
	if (local[6]==NIL) goto WHX905;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[5];
	local[8]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+9;
	w=(*ftab[6])(ctx,2,local+7,&ftab[6],fqv[25]); /*position*/
	local[2] = w;
	if (local[2]==NIL) goto IF908;
	local[7]= local[1];
	local[8]= local[3];
	local[9]= local[2];
	local[10]= local[1];
	local[11]= local[3];
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,3,local+10); /*aref*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)ASET(ctx,4,local+7); /*aset*/
	local[7]= w;
	goto IF909;
IF908:
	local[7]= NIL;
IF909:
	goto WHL904;
WHX905:
	local[7]= NIL;
BLK906:
	w = NIL;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL900;
WHX901:
	local[5]= NIL;
BLK902:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK898:
	ctx->vsp=local; return(local[0]);}

/*:adjacency-list*/
static pointer M910directed_graph_adjacency_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO912,env,argv,local);
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	local[0]= w;
BLK911:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO874(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[0];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO912(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO913,env,argv,local);
	local[1]= argv[0];
	local[2]= fqv[24];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[3];
	ctx->vsp=local+3;
	w=(*ftab[4])(ctx,2,local+1,&ftab[4],fqv[17]); /*send-all*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	local[0]= w;
	local[1]= (pointer)get_sym_func(fqv[26]);
	ctx->vsp=local+2;
	w=(pointer)SORT(ctx,2,local+0); /*sort*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO913(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env0->c.clo.env1[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,2,local+0,&ftab[6],fqv[25]); /*position*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M914costed_arc_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	argv[0]->c.obj.iv[3] = argv[4];
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[5]));
	local[2]= fqv[20];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,5,local+0); /*send-message*/
	local[0]= w;
BLK915:
	ctx->vsp=local; return(local[0]);}

/*:cost*/
static pointer M916costed_arc_cost(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK917:
	ctx->vsp=local; return(local[0]);}

/*:add-arc*/
static pointer M918costed_graph_add_arc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[27], &argv[5], n-5, local+0, 0);
	if (n & (1<<0)) goto KEY920;
	local[0] = NIL;
KEY920:
	local[1]= argv[0];
	local[2]= fqv[28];
	local[3]= argv[2];
	local[4]= argv[3];
	local[5]= argv[4];
	local[6]= fqv[29];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,7,local+1); /*send*/
	local[0]= w;
BLK919:
	ctx->vsp=local; return(local[0]);}

/*:add-arc-from-to*/
static pointer M921costed_graph_add_arc_from_to(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[30], &argv[5], n-5, local+0, 0);
	if (n & (1<<0)) goto KEY923;
	local[0] = NIL;
KEY923:
	local[1]= loadglobal(fqv[31]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[20];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= argv[4];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	w = local[1];
	local[1]= w;
	if (local[0]==NIL) goto IF925;
	local[2]= local[1];
	local[3]= loadglobal(fqv[31]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[20];
	local[6]= argv[3];
	local[7]= argv[2];
	local[8]= argv[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	w = local[3];
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	goto IF926;
IF925:
	local[2]= local[1];
IF926:
	w = local[2];
	local[0]= w;
BLK922:
	ctx->vsp=local; return(local[0]);}

/*:path-cost*/
static pointer M928costed_graph_path_cost(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	w = argv[3];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[19],w);
	local[3]= loadglobal(fqv[19]);
	local[4]= fqv[32];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK929:
	ctx->vsp=local; return(local[0]);}

/*:goal-test*/
static pointer M930graph_goal_test(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	w = ((argv[2])==(local[0])?T:NIL);
	local[0]= w;
BLK931:
	ctx->vsp=local; return(local[0]);}

/*:path-cost*/
static pointer M932graph_path_cost(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	w = argv[3];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[19],w);
	local[3]= argv[2];
	local[4]= fqv[32];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= loadglobal(fqv[19]);
	local[5]= fqv[32];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK933:
	ctx->vsp=local; return(local[0]);}

/*:start-state*/
static pointer M934graph_start_state(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT937;}
	local[0]= NIL;
ENT937:
ENT936:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF938;
	argv[0]->c.obj.iv[2] = local[0];
	local[1]= argv[0]->c.obj.iv[2];
	goto IF939;
IF938:
	local[1]= NIL;
IF939:
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK935:
	ctx->vsp=local; return(local[0]);}

/*:goal-state*/
static pointer M940graph_goal_state(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT943;}
	local[0]= NIL;
ENT943:
ENT942:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF944;
	argv[0]->c.obj.iv[3] = local[0];
	local[1]= argv[0]->c.obj.iv[3];
	goto IF945;
IF944:
	local[1]= NIL;
IF945:
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK941:
	ctx->vsp=local; return(local[0]);}

/*:add-arc*/
static pointer M946graph_add_arc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[33], &argv[4], n-4, local+0, 0);
	if (n & (1<<0)) goto KEY948;
	local[0] = NIL;
KEY948:
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)LISTP(ctx,1,local+1); /*listp*/
	if (w!=NIL) goto IF949;
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	argv[3] = w;
	local[1]= argv[3];
	goto IF950;
IF949:
	local[1]= NIL;
IF950:
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO951,env,argv,local);
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[0]= w;
BLK947:
	ctx->vsp=local; return(local[0]);}

/*:add-arc-from-to*/
static pointer M952graph_add_arc_from_to(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[34], &argv[4], n-4, local+0, 0);
	if (n & (1<<0)) goto KEY954;
	local[0] = NIL;
KEY954:
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[5]));
	local[3]= fqv[28];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= makeint((eusinteger_t)1L);
	local[7]= fqv[29];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SENDMESSAGE(ctx,8,local+1); /*send-message*/
	local[0]= w;
BLK953:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO951(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= fqv[28];
	local[2]= env->c.clo.env1[2];
	local[3]= argv[0];
	local[4]= fqv[29];
	local[5]= env->c.clo.env2[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:write-to-dot-stream*/
static pointer M955directed_graph_write_to_dot_stream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT960;}
	local[0]= loadglobal(fqv[35]);
ENT960:
	if (n>=4) { local[1]=(argv[3]); goto ENT959;}
	local[1]= NIL;
ENT959:
	if (n>=5) { local[2]=(argv[4]); goto ENT958;}
	local[2]= fqv[36];
ENT958:
ENT957:
	if (n>5) maerror();
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO961,env,argv,local);
	local[4]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[37];
	local[6]= fqv[38];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[37];
	local[7]= fqv[39];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	local[6]= argv[0];
	local[7]= fqv[37];
	local[8]= fqv[40];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= ((w)==NIL?T:NIL);
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,FLET962,env,argv,local);
	local[8]= local[0];
	local[9]= fqv[41];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,3,local+8); /*format*/
	local[8]= NIL;
	local[9]= argv[0]->c.obj.iv[1];
WHL964:
	if (local[9]==NIL) goto WHX965;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= local[0];
	local[11]= fqv[42];
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,2,local+10); /*format*/
	local[10]= local[0];
	local[11]= fqv[43];
	local[12]= local[8];
	w = local[7];
	ctx->vsp=local+13;
	w=FLET962(ctx,1,local+12,w);
	local[12]= w;
	local[13]= local[8];
	local[14]= fqv[0];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,4,local+10); /*format*/
	goto WHL964;
WHX965:
	local[10]= NIL;
BLK966:
	w = NIL;
	local[8]= fqv[12];
	local[9]= (pointer)get_sym_func(fqv[13]);
	ctx->vsp=local+10;
	w=(*ftab[7])(ctx,2,local+8,&ftab[7],fqv[44]); /*make-hash-table*/
	local[8]= w;
	local[9]= fqv[12];
	local[10]= (pointer)get_sym_func(fqv[13]);
	ctx->vsp=local+11;
	w=(*ftab[7])(ctx,2,local+9,&ftab[7],fqv[44]); /*make-hash-table*/
	local[9]= w;
	local[10]= NIL;
WHL968:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[11];
	local[10] = w;
	if (local[10]==NIL) goto WHX969;
	if (local[1]==NIL) goto WHX969;
	local[11]= local[10];
	local[12]= fqv[45];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= fqv[45];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= local[8];
	local[13]= fqv[46];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(*ftab[8])(ctx,3,local+11,&ftab[8],fqv[47]); /*sethash*/
	goto WHL968;
WHX969:
	local[11]= NIL;
BLK970:
	w = local[11];
	local[10]= NIL;
	local[11]= argv[0]->c.obj.iv[1];
WHL973:
	if (local[11]==NIL) goto WHX974;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[12];
	local[10] = w;
	local[12]= argv[0];
	local[13]= fqv[10];
	local[14]= local[10];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[12]= w;
	local[13]= NIL;
	local[14]= local[12];
WHL978:
	if (local[14]==NIL) goto WHX979;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14] = (w)->c.cons.cdr;
	w = local[15];
	local[13] = w;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.cdr;
	local[17]= T;
	local[18]= NIL;
	local[19]= NIL;
	if (local[6]!=NIL) goto IF982;
	local[20]= local[10];
	w = local[16];
	ctx->vsp=local+21;
	local[20]= cons(ctx,local[20],w);
	local[21]= local[8];
	ctx->vsp=local+22;
	w=(*ftab[9])(ctx,2,local+20,&ftab[9],fqv[48]); /*gethash*/
	if (w==NIL) goto IF982;
	local[18] = T;
	local[20]= fqv[49];
	w = local[19];
	ctx->vsp=local+21;
	local[19] = cons(ctx,local[20],w);
	local[20]= local[19];
	goto IF983;
IF982:
	local[20]= NIL;
IF983:
	if (local[5]==NIL) goto IF984;
	local[20]= NIL;
	local[21]= fqv[50];
	local[22]= local[15];
	local[23]= fqv[0];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,2,local+22); /*send*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)XFORMAT(ctx,3,local+20); /*format*/
	local[20]= w;
	w = local[19];
	ctx->vsp=local+21;
	local[19] = cons(ctx,local[20],w);
	local[20]= local[19];
	goto IF985;
IF984:
	local[20]= NIL;
IF985:
	if (local[4]!=NIL) goto IF986;
	local[20]= local[10];
	w = local[16];
	ctx->vsp=local+21;
	local[20]= cons(ctx,local[20],w);
	local[21]= local[9];
	ctx->vsp=local+22;
	w=(*ftab[9])(ctx,2,local+20,&ftab[9],fqv[48]); /*gethash*/
	if (w==NIL) goto CON989;
	local[17] = NIL;
	local[20]= local[17];
	goto CON988;
CON989:
	local[20]= local[16];
	w = local[10];
	ctx->vsp=local+21;
	local[20]= cons(ctx,local[20],w);
	local[21]= local[9];
	ctx->vsp=local+22;
	w=(*ftab[9])(ctx,2,local+20,&ftab[9],fqv[48]); /*gethash*/
	if (w==NIL) goto CON990;
	local[17] = NIL;
	local[20]= local[17];
	goto CON988;
CON990:
	local[20]= local[10];
	local[21]= (pointer)get_sym_func(fqv[51]);
	local[22]= argv[0];
	local[23]= fqv[10];
	local[24]= local[16];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)MAPCAR(ctx,2,local+21); /*mapcar*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(*ftab[10])(ctx,2,local+20,&ftab[10],fqv[52]); /*member*/
	if (w==NIL) goto CON991;
	local[20]= fqv[53];
	w = local[19];
	ctx->vsp=local+21;
	local[19] = cons(ctx,local[20],w);
	local[20]= local[19];
	goto CON988;
CON991:
	local[20]= NIL;
CON988:
	goto IF987;
IF986:
	local[20]= NIL;
IF987:
	if (local[19]!=NIL) goto IF992;
	local[19] = fqv[54];
	local[20]= local[19];
	goto IF993;
IF992:
	local[20]= NIL;
IF993:
	if (local[17]==NIL) goto IF994;
	local[20]= local[10];
	w = local[16];
	ctx->vsp=local+21;
	local[20]= cons(ctx,local[20],w);
	local[21]= local[9];
	local[22]= local[19];
	ctx->vsp=local+23;
	w=(*ftab[8])(ctx,3,local+20,&ftab[8],fqv[47]); /*sethash*/
	local[20]= w;
	goto IF995;
IF994:
	local[20]= NIL;
IF995:
	w = local[20];
	goto WHL978;
WHX979:
	local[15]= NIL;
BLK980:
	w = NIL;
	goto WHL973;
WHX974:
	local[12]= NIL;
BLK975:
	w = NIL;
	ctx->vsp=local+10;
	local[10]= makeclosure(codevec,quotevec,FLET996,env,argv,local);
	if (local[6]==NIL) goto IF997;
	local[11]= local[8];
	w = local[10];
	ctx->vsp=local+12;
	w=FLET996(ctx,1,local+11,w);
	local[11]= w;
	goto IF998;
IF997:
	local[11]= NIL;
IF998:
	local[11]= local[9];
	w = local[10];
	ctx->vsp=local+12;
	w=FLET996(ctx,1,local+11,w);
	local[10]= local[0];
	local[11]= fqv[55];
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,2,local+10); /*format*/
	w = T;
	local[0]= w;
BLK956:
	ctx->vsp=local; return(local[0]);}

/*:write-to-dot*/
static pointer M999directed_graph_write_to_dot(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1003;}
	local[0]= NIL;
ENT1003:
	if (n>=5) { local[1]=(argv[4]); goto ENT1002;}
	local[1]= fqv[56];
ENT1002:
ENT1001:
	if (n>5) maerror();
	local[2]= argv[2];
	local[3]= fqv[57];
	local[4]= fqv[58];
	ctx->vsp=local+5;
	w=(*ftab[11])(ctx,3,local+2,&ftab[11],fqv[59]); /*open*/
	local[2]= w;
	ctx->vsp=local+3;
	w = makeclosure(codevec,quotevec,UWP1004,env,argv,local);
	local[3]=(pointer)(ctx->protfp); local[4]=w;
	ctx->protfp=(struct protectframe *)(local+3);
	local[5]= argv[0];
	local[6]= fqv[60];
	local[7]= local[2];
	local[8]= local[0];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	ctx->vsp=local+5;
	UWP1004(ctx,0,local+5,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	w = T;
	local[0]= w;
BLK1000:
	ctx->vsp=local; return(local[0]);}

/*:write-to-file*/
static pointer M1005directed_graph_write_to_file(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1010;}
	local[0]= NIL;
ENT1010:
	if (n>=5) { local[1]=(argv[4]); goto ENT1009;}
	local[1]= NIL;
ENT1009:
	if (n>=6) { local[2]=(argv[5]); goto ENT1008;}
	local[2]= fqv[61];
ENT1008:
ENT1007:
	if (n>6) maerror();
	local[3]= NIL;
	local[4]= fqv[62];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[63];
	local[6]= local[3];
	local[7]= local[0];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[4]= NIL;
	local[5]= fqv[64];
	local[6]= local[3];
	local[7]= local[2];
	local[8]= NIL;
	local[9]= fqv[65];
	local[10]= argv[2];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,4,local+8); /*format*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,5,local+4); /*format*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SYSTEM(ctx,1,local+4); /*unix:system*/
	w = T;
	local[0]= w;
BLK1006:
	ctx->vsp=local; return(local[0]);}

/*:write-to-pdf*/
static pointer M1011directed_graph_write_to_pdf(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1015;}
	local[0]= NIL;
ENT1015:
	if (n>=5) { local[1]=(argv[4]); goto ENT1014;}
	local[1]= fqv[66];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[12])(ctx,2,local+1,&ftab[12],fqv[67]); /*string-right-trim*/
	local[1]= w;
ENT1014:
ENT1013:
	if (n>5) maerror();
	local[2]= fqv[68];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(*ftab[13])(ctx,2,local+2,&ftab[13],fqv[69]); /*substringp*/
	if (w==NIL) goto IF1016;
	local[2]= fqv[70];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(*ftab[12])(ctx,2,local+2,&ftab[12],fqv[67]); /*string-right-trim*/
	local[2]= w;
	local[3]= local[2];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SUB1(ctx,1,local+4); /*1-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	local[4]= makeint((eusinteger_t)46L);
	ctx->vsp=local+5;
	w=(pointer)NUMEQUAL(ctx,2,local+3); /*=*/
	if (w==NIL) goto IF1018;
	local[3]= local[2];
	local[4]= makeint((eusinteger_t)0L);
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SUB1(ctx,1,local+5); /*1-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SUBSEQ(ctx,3,local+3); /*subseq*/
	argv[2] = w;
	local[3]= argv[2];
	goto IF1019;
IF1018:
	local[3]= NIL;
IF1019:
	w = local[3];
	local[2]= w;
	goto IF1017;
IF1016:
	local[2]= NIL;
IF1017:
	local[2]= argv[0];
	local[3]= fqv[71];
	local[4]= argv[2];
	local[5]= local[0];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	local[0]= w;
BLK1012:
	ctx->vsp=local; return(local[0]);}

/*:original-draw-mode*/
static pointer M1020directed_graph_original_draw_mode(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[38];
	local[2]= NIL;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[39];
	local[2]= NIL;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[40];
	local[2]= NIL;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1021:
	ctx->vsp=local; return(local[0]);}

/*:current-draw-mode*/
static pointer M1022directed_graph_current_draw_mode(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[38];
	local[2]= T;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[39];
	local[2]= T;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[40];
	local[2]= T;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1023:
	ctx->vsp=local; return(local[0]);}

/*:draw-both-arc*/
static pointer M1024directed_graph_draw_both_arc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1027;}
	local[0]= fqv[29];
ENT1027:
ENT1026:
	if (n>3) maerror();
	local[1]= local[0];
	if (fqv[29]==local[1]) goto IF1028;
	local[1]= argv[0];
	local[2]= fqv[72];
	local[3]= fqv[38];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF1029;
IF1028:
	local[1]= NIL;
IF1029:
	local[1]= argv[0];
	local[2]= fqv[37];
	local[3]= fqv[38];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK1025:
	ctx->vsp=local; return(local[0]);}

/*:draw-arc-label*/
static pointer M1030directed_graph_draw_arc_label(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1033;}
	local[0]= fqv[73];
ENT1033:
ENT1032:
	if (n>3) maerror();
	local[1]= local[0];
	if (fqv[73]==local[1]) goto IF1034;
	local[1]= argv[0];
	local[2]= fqv[72];
	local[3]= fqv[39];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF1035;
IF1034:
	local[1]= NIL;
IF1035:
	local[1]= argv[0];
	local[2]= fqv[37];
	local[3]= fqv[39];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK1031:
	ctx->vsp=local; return(local[0]);}

/*:draw-merged-result*/
static pointer M1036directed_graph_draw_merged_result(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1039;}
	local[0]= fqv[74];
ENT1039:
ENT1038:
	if (n>3) maerror();
	local[1]= local[0];
	if (fqv[74]==local[1]) goto IF1040;
	local[1]= argv[0];
	local[2]= fqv[72];
	local[3]= fqv[40];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF1041;
IF1040:
	local[1]= NIL;
IF1041:
	local[1]= argv[0];
	local[2]= fqv[37];
	local[3]= fqv[40];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK1037:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO961(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)GENSYM(ctx,0,local+1); /*gensym*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[14])(ctx,1,local+1,&ftab[14],fqv[75]); /*string*/
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET962(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env2[3];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[76]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET996(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO1042,env,argv,local);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[77]); /*maphash*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1042(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= env->c.clo.env0->c.clo.env2[0];
	local[1]= fqv[78];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= env->c.clo.env0->c.clo.env2[0];
	local[1]= fqv[79];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w = env->c.clo.env0->c.clo.env2[7];
	ctx->vsp=local+3;
	w=FLET962(ctx,1,local+2,w);
	local[2]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	w = env->c.clo.env0->c.clo.env2[7];
	ctx->vsp=local+4;
	w=FLET962(ctx,1,local+3,w);
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= argv[1];
	if (fqv[54]!=local[0]) goto IF1043;
	local[0]= env->c.clo.env0->c.clo.env2[0];
	local[1]= fqv[80];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= w;
	goto IF1044;
IF1043:
	local[0]= env->c.clo.env0->c.clo.env2[0];
	local[1]= fqv[81];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= NIL;
	local[1]= argv[1];
WHL1046:
	if (local[1]==NIL) goto WHX1047;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==local[2]) goto IF1050;
	local[2]= env->c.clo.env0->c.clo.env2[0];
	local[3]= fqv[82];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,2,local+2); /*format*/
	local[2]= w;
	goto IF1051;
IF1050:
	local[2]= NIL;
IF1051:
	local[2]= env->c.clo.env0->c.clo.env2[0];
	local[3]= fqv[83];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	goto WHL1046;
WHX1047:
	local[2]= NIL;
BLK1048:
	w = NIL;
	local[0]= env->c.clo.env0->c.clo.env2[0];
	local[1]= fqv[84];
	ctx->vsp=local+2;
	w=(pointer)XFORMAT(ctx,2,local+0); /*format*/
	local[0]= w;
IF1044:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP1004(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[2];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:add-neighbor*/
static pointer M1052node_add_neighbor(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1055;}
	local[0]= NIL;
ENT1055:
ENT1054:
	if (n>4) maerror();
	local[1]= loadglobal(fqv[19]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[20];
	local[4]= argv[0];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[1]= w;
	if (local[0]==NIL) goto IF1057;
	local[2]= local[1];
	local[3]= fqv[0];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF1058;
IF1057:
	local[2]= NIL;
IF1058:
	local[2]= argv[0];
	local[3]= fqv[85];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[0]= w;
BLK1053:
	ctx->vsp=local; return(local[0]);}

/*:neighbors*/
static pointer M1059node_neighbors(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1062;}
	local[0]= NIL;
ENT1062:
ENT1061:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1063;
	local[1]= NIL;
	local[2]= local[0];
WHL1066:
	if (local[2]==NIL) goto WHX1067;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= loadglobal(fqv[19]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[20];
	local[6]= argv[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = local[3];
	goto WHL1066;
WHX1067:
	local[3]= NIL;
BLK1068:
	w = NIL;
	local[1]= w;
	goto IF1064;
IF1063:
	local[1]= NIL;
IF1064:
	local[1]= (pointer)get_sym_func(fqv[51]);
	local[2]= argv[0];
	local[3]= fqv[10];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[0]= w;
BLK1060:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1071arced_node_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[86], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY1073;
	local[0] = NIL;
KEY1073:
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[5]));
	local[3]= fqv[20];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,4,local+1); /*send-message*/
	w = argv[0];
	local[0]= w;
BLK1072:
	ctx->vsp=local; return(local[0]);}

/*:find-action*/
static pointer M1074arced_node_find_action(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= fqv[11];
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO1076,env,argv,local);
	ctx->vsp=local+4;
	w=(*ftab[2])(ctx,4,local+0,&ftab[2],fqv[14]); /*find*/
	local[0]= w;
	if (local[0]==NIL) goto IF1077;
	local[1]= local[0];
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF1078;
IF1077:
	local[1]= NIL;
IF1078:
	w = local[1];
	local[0]= w;
BLK1075:
	ctx->vsp=local; return(local[0]);}

/*:neighbor-action-alist*/
static pointer M1079arced_node_neighbor_action_alist(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO1081,env,argv,local);
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	local[0]= w;
BLK1080:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1076(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[3];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1081(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[0];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[3];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1082solver_node_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[87], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY1084;
	local[0] = makeint((eusinteger_t)0L);
KEY1084:
	if (n & (1<<1)) goto KEY1085;
	local[1] = NIL;
KEY1085:
	if (n & (1<<2)) goto KEY1086;
	local[2] = NIL;
KEY1086:
	argv[0]->c.obj.iv[1] = argv[2];
	argv[0]->c.obj.iv[2] = local[0];
	argv[0]->c.obj.iv[3] = local[1];
	argv[0]->c.obj.iv[4] = local[2];
	w = argv[0];
	local[0]= w;
BLK1083:
	ctx->vsp=local; return(local[0]);}

/*:path*/
static pointer M1087solver_node_path(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1090;}
	local[0]= NIL;
ENT1090:
ENT1089:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1091;
	local[1]= argv[0];
	local[2]= fqv[88];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (w==NIL) goto IF1093;
	local[1]= argv[0];
	local[2]= fqv[88];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[89];
	local[3]= argv[0];
	w = local[0];
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF1094;
IF1093:
	local[1]= argv[0];
	w = local[0];
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
IF1094:
	goto IF1092;
IF1091:
	if (argv[0]->c.obj.iv[5]==NIL) goto IF1095;
	local[1]= argv[0]->c.obj.iv[5];
	goto IF1096;
IF1095:
	local[1]= argv[0];
	local[2]= fqv[88];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (w==NIL) goto IF1097;
	local[1]= argv[0];
	local[2]= fqv[88];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[89];
	local[3]= argv[0];
	w = local[0];
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF1098;
IF1097:
	local[1]= argv[0];
	w = local[0];
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
IF1098:
	argv[0]->c.obj.iv[5] = local[1];
	local[1]= argv[0]->c.obj.iv[5];
IF1096:
IF1092:
	w = local[1];
	local[0]= w;
BLK1088:
	ctx->vsp=local; return(local[0]);}

/*:expand*/
static pointer M1099solver_node_expand(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST1101:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	local[1]= (pointer)get_sym_func(fqv[90]);
	local[2]= argv[2];
	local[3]= fqv[10];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= local[1];
WHL1103:
	if (local[4]==NIL) goto WHX1104;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= loadglobal(fqv[91]);
	ctx->vsp=local+6;
	w=(pointer)INSTANTIATE(ctx,1,local+5); /*instantiate*/
	local[5]= w;
	local[6]= local[5];
	local[7]= fqv[20];
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.cdr;
	local[9]= fqv[88];
	local[10]= argv[0];
	local[11]= fqv[92];
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= fqv[32];
	local[14]= argv[2];
	local[15]= fqv[93];
	local[16]= argv[0];
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.cdr;
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,5,local+14); /*send*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,9,local+6); /*send*/
	w = local[5];
	local[5]= w;
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	goto WHL1103;
WHX1104:
	local[5]= NIL;
BLK1105:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK1100:
	ctx->vsp=local; return(local[0]);}

/*:state*/
static pointer M1108solver_node_state(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1111;}
	local[0]= NIL;
ENT1111:
ENT1110:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1112;
	argv[0]->c.obj.iv[1] = local[0];
	local[1]= argv[0]->c.obj.iv[1];
	goto IF1113;
IF1112:
	local[1]= NIL;
IF1113:
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK1109:
	ctx->vsp=local; return(local[0]);}

/*:cost*/
static pointer M1114solver_node_cost(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1117;}
	local[0]= NIL;
ENT1117:
ENT1116:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1118;
	argv[0]->c.obj.iv[2] = local[0];
	local[1]= argv[0]->c.obj.iv[2];
	goto IF1119;
IF1118:
	local[1]= NIL;
IF1119:
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK1115:
	ctx->vsp=local; return(local[0]);}

/*:parent*/
static pointer M1120solver_node_parent(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1123;}
	local[0]= NIL;
ENT1123:
ENT1122:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1124;
	argv[0]->c.obj.iv[3] = local[0];
	local[1]= argv[0]->c.obj.iv[3];
	goto IF1125;
IF1124:
	local[1]= NIL;
IF1125:
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK1121:
	ctx->vsp=local; return(local[0]);}

/*:action*/
static pointer M1126solver_node_action(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1129;}
	local[0]= NIL;
ENT1129:
ENT1128:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1130;
	argv[0]->c.obj.iv[4] = local[0];
	local[1]= argv[0]->c.obj.iv[4];
	goto IF1131;
IF1130:
	local[1]= NIL;
IF1131:
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK1127:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1132solver_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0];
	local[0]= w;
BLK1133:
	ctx->vsp=local; return(local[0]);}

/*:solve*/
static pointer M1134solver_solve(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = NIL;
	local[0]= w;
BLK1135:
	ctx->vsp=local; return(local[0]);}

/*:solve-by-name*/
static pointer M1136solver_solve_by_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[94], &argv[5], n-5, local+0, 0);
	if (n & (1<<0)) goto KEY1138;
	local[0] = NIL;
KEY1138:
	local[1]= argv[2];
	local[2]= fqv[95];
	local[3]= argv[2];
	local[4]= fqv[96];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[2];
	local[2]= fqv[97];
	local[3]= argv[2];
	local[4]= fqv[96];
	local[5]= argv[4];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[98];
	local[3]= argv[2];
	local[4]= fqv[99];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[0]= w;
BLK1137:
	ctx->vsp=local; return(local[0]);}

/*:solve-init*/
static pointer M1139graph_search_solver_solve_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[2] = NIL;
	local[0]= argv[0];
	local[1]= fqv[100];
	local[2]= loadglobal(fqv[91]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[20];
	local[5]= argv[2];
	local[6]= fqv[95];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= fqv[32];
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,5,local+3); /*send*/
	w = local[2];
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1140:
	ctx->vsp=local; return(local[0]);}

/*:find-node-in-close-list*/
static pointer M1142graph_search_solver_find_node_in_close_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[45];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[14]); /*find*/
	local[0]= w;
BLK1143:
	ctx->vsp=local; return(local[0]);}

/*:solve*/
static pointer M1144graph_search_solver_solve(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[101], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY1146;
	local[0] = NIL;
KEY1146:
	local[1]= argv[0];
	local[2]= fqv[102];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
WHL1147:
	local[1]= argv[0];
	local[2]= fqv[103];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (w!=NIL) goto WHX1148;
	local[1]= argv[0];
	local[2]= fqv[104];
	local[3]= fqv[105];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= fqv[106];
	local[4]= local[1];
	local[5]= fqv[45];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	if (w==NIL) goto CON1151;
	local[2]= local[1];
	local[3]= fqv[89];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK1145;
	goto CON1150;
CON1151:
	local[2]= argv[0];
	local[3]= fqv[107];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	if (w!=NIL) goto CON1152;
	local[2]= local[1];
	local[3]= fqv[45];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	w = argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	argv[0]->c.obj.iv[2] = cons(ctx,local[2],w);
	local[2]= argv[0];
	local[3]= fqv[108];
	local[4]= local[1];
	local[5]= fqv[109];
	local[6]= argv[2];
	local[7]= fqv[99];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto CON1150;
CON1152:
	local[2]= NIL;
CON1150:
	w = local[2];
	goto WHL1147;
WHX1148:
	local[1]= NIL;
BLK1149:
	local[1]= fqv[110];
	local[2]= fqv[98];
	ctx->vsp=local+3;
	w=(*ftab[17])(ctx,2,local+1,&ftab[17],fqv[111]); /*warn*/
	local[1]= fqv[112];
	local[2]= fqv[98];
	ctx->vsp=local+3;
	w=(*ftab[17])(ctx,2,local+1,&ftab[17],fqv[111]); /*warn*/
	local[1]= argv[0];
	local[2]= fqv[113];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	argv[0]->c.obj.iv[2] = NIL;
	w = NIL;
	local[0]= w;
BLK1145:
	ctx->vsp=local; return(local[0]);}

/*:add-to-open-list*/
static pointer M1153graph_search_solver_add_to_open_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto IF1155;
	local[0]= argv[0];
	local[1]= fqv[108];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF1156;
IF1155:
	local[0]= argv[0];
	local[1]= fqv[114];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
IF1156:
	w = local[0];
	local[0]= w;
BLK1154:
	ctx->vsp=local; return(local[0]);}

/*:null-open-list?*/
static pointer M1157graph_search_solver_null_open_list_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = ((argv[0]->c.obj.iv[1])==NIL?T:NIL);
	local[0]= w;
BLK1158:
	ctx->vsp=local; return(local[0]);}

/*:clear-open-list*/
static pointer M1159graph_search_solver_clear_open_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[115];
	ctx->vsp=local+1;
	w=(*ftab[17])(ctx,1,local+0,&ftab[17],fqv[111]); /*warn*/
	w = NIL;
	local[0]= w;
BLK1160:
	ctx->vsp=local; return(local[0]);}

/*:add-list-to-open-list*/
static pointer M1161graph_search_solver_add_list_to_open_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= fqv[116];
	ctx->vsp=local+1;
	w=(*ftab[17])(ctx,1,local+0,&ftab[17],fqv[111]); /*warn*/
	w = NIL;
	local[0]= w;
BLK1162:
	ctx->vsp=local; return(local[0]);}

/*:add-object-to-open-list*/
static pointer M1163graph_search_solver_add_object_to_open_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= fqv[117];
	ctx->vsp=local+1;
	w=(*ftab[17])(ctx,1,local+0,&ftab[17],fqv[111]); /*warn*/
	w = NIL;
	local[0]= w;
BLK1164:
	ctx->vsp=local; return(local[0]);}

/*:pop-from-open-list*/
static pointer M1165graph_search_solver_pop_from_open_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[118], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY1167;
	local[0] = NIL;
KEY1167:
	local[1]= fqv[119];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,1,local+1,&ftab[17],fqv[111]); /*warn*/
	w = NIL;
	local[0]= w;
BLK1166:
	ctx->vsp=local; return(local[0]);}

/*:open-list*/
static pointer M1168graph_search_solver_open_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1171;}
	local[0]= NIL;
ENT1171:
ENT1170:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1172;
	argv[0]->c.obj.iv[1] = local[0];
	local[1]= argv[0]->c.obj.iv[1];
	goto IF1173;
IF1172:
	local[1]= NIL;
IF1173:
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK1169:
	ctx->vsp=local; return(local[0]);}

/*:close-list*/
static pointer M1174graph_search_solver_close_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1177;}
	local[0]= NIL;
ENT1177:
ENT1176:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1178;
	argv[0]->c.obj.iv[2] = local[0];
	local[1]= argv[0]->c.obj.iv[2];
	goto IF1179;
IF1178:
	local[1]= NIL;
IF1179:
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK1175:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1180breadth_first_graph_search_solver_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	w=(pointer)LIST(ctx,0,local+0); /*list*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0];
	local[0]= w;
BLK1181:
	ctx->vsp=local; return(local[0]);}

/*:clear-open-list*/
static pointer M1182breadth_first_graph_search_solver_clear_open_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[1] = NIL;
	w = NIL;
	local[0]= w;
BLK1183:
	ctx->vsp=local; return(local[0]);}

/*:add-list-to-open-list*/
static pointer M1184breadth_first_graph_search_solver_add_list_to_open_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK1185:
	ctx->vsp=local; return(local[0]);}

/*:add-object-to-open-list*/
static pointer M1186breadth_first_graph_search_solver_add_object_to_open_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK1187:
	ctx->vsp=local; return(local[0]);}

/*:pop-from-open-list*/
static pointer M1188breadth_first_graph_search_solver_pop_from_open_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[120], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY1190;
	local[0] = NIL;
KEY1190:
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[1] = (w)->c.cons.cdr;
	w = local[1];
	local[0]= w;
BLK1189:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1192depth_first_graph_search_solver_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	w=(pointer)LIST(ctx,0,local+0); /*list*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0];
	local[0]= w;
BLK1193:
	ctx->vsp=local; return(local[0]);}

/*:clear-open-list*/
static pointer M1194depth_first_graph_search_solver_clear_open_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[1] = NIL;
	w = NIL;
	local[0]= w;
BLK1195:
	ctx->vsp=local; return(local[0]);}

/*:add-list-to-open-list*/
static pointer M1196depth_first_graph_search_solver_add_list_to_open_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK1197:
	ctx->vsp=local; return(local[0]);}

/*:add-object-to-open-list*/
static pointer M1198depth_first_graph_search_solver_add_object_to_open_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	w = argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	argv[0]->c.obj.iv[1] = cons(ctx,local[0],w);
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK1199:
	ctx->vsp=local; return(local[0]);}

/*:pop-from-open-list*/
static pointer M1200depth_first_graph_search_solver_pop_from_open_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[121], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY1202;
	local[0] = NIL;
KEY1202:
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[1] = (w)->c.cons.cdr;
	w = local[1];
	local[0]= w;
BLK1201:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1204best_first_graph_search_solver_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[3] = argv[2];
	ctx->vsp=local+0;
	w=(pointer)LIST(ctx,0,local+0); /*list*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0];
	local[0]= w;
BLK1205:
	ctx->vsp=local; return(local[0]);}

/*:clear-open-list*/
static pointer M1206best_first_graph_search_solver_clear_open_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[1] = NIL;
	w = NIL;
	local[0]= w;
BLK1207:
	ctx->vsp=local; return(local[0]);}

/*:add-list-to-open-list*/
static pointer M1208best_first_graph_search_solver_add_list_to_open_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK1209:
	ctx->vsp=local; return(local[0]);}

/*:add-object-to-open-list*/
static pointer M1210best_first_graph_search_solver_add_object_to_open_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	w = argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	argv[0]->c.obj.iv[1] = cons(ctx,local[0],w);
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK1211:
	ctx->vsp=local; return(local[0]);}

/*:pop-from-open-list*/
static pointer M1212best_first_graph_search_solver_pop_from_open_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[122], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY1214;
	local[0] = NIL;
KEY1214:
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= local[1];
	local[3]= fqv[37];
	local[4]= fqv[123];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	if (w!=NIL) goto OR1215;
	local[2]= local[1];
	local[3]= fqv[72];
	local[4]= fqv[123];
	local[5]= argv[0];
	local[6]= fqv[124];
	local[7]= local[1];
	local[8]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= local[1];
	local[3]= fqv[37];
	local[4]= fqv[123];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
OR1215:
	if (local[0]==NIL) goto IF1216;
	local[3]= fqv[125];
	local[4]= local[1];
	local[5]= fqv[89];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= fqv[45];
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,2,local+4,&ftab[4],fqv[17]); /*send-all*/
	local[4]= w;
	local[5]= fqv[0];
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,2,local+4,&ftab[4],fqv[17]); /*send-all*/
	local[4]= w;
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(*ftab[17])(ctx,3,local+3,&ftab[17],fqv[111]); /*warn*/
	local[3]= w;
	goto IF1217;
IF1216:
	local[3]= NIL;
IF1217:
	local[3]= NIL;
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
WHL1219:
	if (local[4]==NIL) goto WHX1220;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3];
	local[6]= fqv[123];
	ctx->vsp=local+7;
	w=(pointer)GETPROP(ctx,2,local+5); /*get*/
	local[5]= w;
	if (w!=NIL) goto OR1223;
	local[5]= local[3];
	local[6]= argv[0];
	local[7]= fqv[124];
	local[8]= local[3];
	local[9]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[6]= w;
	local[7]= fqv[123];
	ctx->vsp=local+8;
	w=(pointer)PUTPROP(ctx,3,local+5); /*putprop*/
	local[5]= local[3];
	local[6]= fqv[123];
	ctx->vsp=local+7;
	w=(pointer)GETPROP(ctx,2,local+5); /*get*/
	local[5]= w;
OR1223:
	if (local[0]==NIL) goto IF1224;
	local[6]= fqv[126];
	local[7]= local[3];
	local[8]= fqv[89];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= fqv[45];
	ctx->vsp=local+9;
	w=(*ftab[4])(ctx,2,local+7,&ftab[4],fqv[17]); /*send-all*/
	local[7]= w;
	local[8]= fqv[0];
	ctx->vsp=local+9;
	w=(*ftab[4])(ctx,2,local+7,&ftab[4],fqv[17]); /*send-all*/
	local[7]= w;
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(*ftab[17])(ctx,3,local+6,&ftab[17],fqv[111]); /*warn*/
	local[6]= w;
	goto IF1225;
IF1224:
	local[6]= NIL;
IF1225:
	local[6]= local[5];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,2,local+6); /*<*/
	if (w==NIL) goto IF1226;
	local[2] = local[5];
	local[1] = local[3];
	local[6]= local[1];
	goto IF1227;
IF1226:
	local[6]= NIL;
IF1227:
	w = local[6];
	goto WHL1219;
WHX1220:
	local[5]= NIL;
BLK1221:
	w = NIL;
	if (local[0]==NIL) goto IF1228;
	local[3]= fqv[127];
	ctx->vsp=local+4;
	w=(*ftab[17])(ctx,1,local+3,&ftab[17],fqv[111]); /*warn*/
	local[3]= fqv[128];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(*ftab[17])(ctx,2,local+3,&ftab[17],fqv[111]); /*warn*/
	local[3]= fqv[129];
	local[4]= local[1];
	local[5]= fqv[89];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= fqv[45];
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,2,local+4,&ftab[4],fqv[17]); /*send-all*/
	local[4]= w;
	local[5]= fqv[0];
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,2,local+4,&ftab[4],fqv[17]); /*send-all*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[17])(ctx,2,local+3,&ftab[17],fqv[111]); /*warn*/
	local[3]= w;
	goto IF1229;
IF1228:
	local[3]= NIL;
IF1229:
	local[3]= local[1];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= fqv[130];
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(*ftab[18])(ctx,4,local+3,&ftab[18],fqv[131]); /*delete*/
	argv[0]->c.obj.iv[1] = w;
	w = local[1];
	local[0]= w;
BLK1213:
	ctx->vsp=local; return(local[0]);}

/*:fn*/
static pointer M1230best_first_graph_search_solver_fn(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= fqv[32];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK1231:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1232a__graph_search_solver_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[5]));
	local[2]= fqv[20];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SENDMESSAGE(ctx,4,local+0); /*send-message*/
	w = argv[0];
	local[0]= w;
BLK1233:
	ctx->vsp=local; return(local[0]);}

/*:fn*/
static pointer M1234a__graph_search_solver_fn(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[132], &argv[4], n-4, local+0, 0);
	if (n & (1<<0)) goto KEY1236;
	local[0] = NIL;
KEY1236:
	if (local[0]==NIL) goto IF1237;
	local[1]= fqv[133];
	local[2]= argv[0];
	local[3]= fqv[134];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[17])(ctx,2,local+1,&ftab[17],fqv[111]); /*warn*/
	local[1]= fqv[135];
	local[2]= argv[0];
	local[3]= fqv[136];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[17])(ctx,2,local+1,&ftab[17],fqv[111]); /*warn*/
	local[1]= w;
	goto IF1238;
IF1237:
	local[1]= NIL;
IF1238:
	local[1]= argv[0];
	local[2]= fqv[134];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[136];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[0]= w;
BLK1235:
	ctx->vsp=local; return(local[0]);}

/*:gn*/
static pointer M1239a__graph_search_solver_gn(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= fqv[32];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK1240:
	ctx->vsp=local; return(local[0]);}

/*:hn*/
static pointer M1241a__graph_search_solver_hn(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= fqv[137];
	ctx->vsp=local+1;
	w=(*ftab[17])(ctx,1,local+0,&ftab[17],fqv[111]); /*warn*/
	w = makeflt(0.0000000000000000000000e+00);
	local[0]= w;
BLK1242:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___irtgraph(ctx,n,argv,env)
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
	local[0]= fqv[9];
	local[1]= fqv[138];
	local[2]= fqv[9];
	local[3]= fqv[139];
	local[4]= loadglobal(fqv[140]);
	local[5]= fqv[141];
	local[6]= fqv[142];
	local[7]= fqv[143];
	local[8]= NIL;
	local[9]= fqv[144];
	local[10]= NIL;
	local[11]= fqv[145];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[146];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[19])(ctx,13,local+2,&ftab[19],fqv[147]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M840node_init,fqv[20],fqv[9],fqv[148]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M842node_arc_list,fqv[24],fqv[9],fqv[149]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M844node_successors,fqv[10],fqv[9],fqv[150]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M847node_add_arc,fqv[4],fqv[9],fqv[151]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M849node_remove_arc,fqv[22],fqv[9],fqv[152]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M851node_remove_all_arcs,fqv[18],fqv[9],fqv[153]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M853node_unlink,fqv[16],fqv[9],fqv[154]);
	local[0]= fqv[19];
	local[1]= fqv[138];
	local[2]= fqv[19];
	local[3]= fqv[139];
	local[4]= loadglobal(fqv[140]);
	local[5]= fqv[141];
	local[6]= fqv[155];
	local[7]= fqv[143];
	local[8]= NIL;
	local[9]= fqv[144];
	local[10]= NIL;
	local[11]= fqv[145];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[146];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[19])(ctx,13,local+2,&ftab[19],fqv[147]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M856arc_init,fqv[20],fqv[19],fqv[156]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M858arc_from,fqv[21],fqv[19],fqv[157]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M860arc_to,fqv[3],fqv[19],fqv[158]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M862arc_prin1,fqv[6],fqv[19],fqv[159]);
	local[0]= fqv[160];
	local[1]= fqv[138];
	local[2]= fqv[160];
	local[3]= fqv[139];
	local[4]= loadglobal(fqv[140]);
	local[5]= fqv[141];
	local[6]= fqv[161];
	local[7]= fqv[143];
	local[8]= NIL;
	local[9]= fqv[144];
	local[10]= NIL;
	local[11]= fqv[145];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[146];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[19])(ctx,13,local+2,&ftab[19],fqv[147]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M867directed_graph_init,fqv[20],fqv[160],fqv[162]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M869directed_graph_successors,fqv[10],fqv[160],fqv[163]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M872directed_graph_node,fqv[96],fqv[160],fqv[164]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M875directed_graph_nodes,fqv[165],fqv[160],fqv[166]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M886directed_graph_add_node,fqv[167],fqv[160],fqv[168]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M888directed_graph_remove_node,fqv[169],fqv[160],fqv[170]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M890directed_graph_clear_nodes,fqv[171],fqv[160],fqv[172]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M892directed_graph_add_arc_from_to,fqv[28],fqv[160],fqv[173]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M895directed_graph_remove_arc,fqv[22],fqv[160],fqv[174]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M897directed_graph_adjacency_matrix,fqv[175],fqv[160],fqv[176]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M910directed_graph_adjacency_list,fqv[177],fqv[160],fqv[178]);
	local[0]= fqv[31];
	local[1]= fqv[138];
	local[2]= fqv[31];
	local[3]= fqv[139];
	local[4]= loadglobal(fqv[19]);
	local[5]= fqv[141];
	local[6]= fqv[179];
	local[7]= fqv[143];
	local[8]= NIL;
	local[9]= fqv[144];
	local[10]= NIL;
	local[11]= fqv[145];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[146];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[19])(ctx,13,local+2,&ftab[19],fqv[147]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M914costed_arc_init,fqv[20],fqv[31],fqv[180]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M916costed_arc_cost,fqv[32],fqv[31],fqv[181]);
	local[0]= fqv[182];
	local[1]= fqv[138];
	local[2]= fqv[182];
	local[3]= fqv[139];
	local[4]= loadglobal(fqv[160]);
	local[5]= fqv[141];
	local[6]= fqv[183];
	local[7]= fqv[143];
	local[8]= NIL;
	local[9]= fqv[144];
	local[10]= NIL;
	local[11]= fqv[145];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[146];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[19])(ctx,13,local+2,&ftab[19],fqv[147]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M918costed_graph_add_arc,fqv[4],fqv[182],fqv[184]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M921costed_graph_add_arc_from_to,fqv[28],fqv[182],fqv[185]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M928costed_graph_path_cost,fqv[93],fqv[182],fqv[186]);
	local[0]= fqv[187];
	local[1]= fqv[138];
	local[2]= fqv[187];
	local[3]= fqv[139];
	local[4]= loadglobal(fqv[182]);
	local[5]= fqv[141];
	local[6]= fqv[188];
	local[7]= fqv[143];
	local[8]= NIL;
	local[9]= fqv[144];
	local[10]= NIL;
	local[11]= fqv[145];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[146];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[19])(ctx,13,local+2,&ftab[19],fqv[147]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M930graph_goal_test,fqv[106],fqv[187],fqv[189]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M932graph_path_cost,fqv[93],fqv[187],fqv[190]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M934graph_start_state,fqv[95],fqv[187],fqv[191]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M940graph_goal_state,fqv[97],fqv[187],fqv[192]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M946graph_add_arc,fqv[4],fqv[187],fqv[193]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M952graph_add_arc_from_to,fqv[28],fqv[187],fqv[194]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M955directed_graph_write_to_dot_stream,fqv[60],fqv[160],fqv[195]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M999directed_graph_write_to_dot,fqv[63],fqv[160],fqv[196]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1005directed_graph_write_to_file,fqv[71],fqv[160],fqv[197]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1011directed_graph_write_to_pdf,fqv[198],fqv[160],fqv[199]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1020directed_graph_original_draw_mode,fqv[200],fqv[160],fqv[201]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1022directed_graph_current_draw_mode,fqv[202],fqv[160],fqv[203]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1024directed_graph_draw_both_arc,fqv[38],fqv[160],fqv[204]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1030directed_graph_draw_arc_label,fqv[39],fqv[160],fqv[205]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1036directed_graph_draw_merged_result,fqv[40],fqv[160],fqv[206]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1052node_add_neighbor,fqv[207],fqv[9],fqv[208]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1059node_neighbors,fqv[85],fqv[9],fqv[209]);
	local[0]= fqv[210];
	local[1]= fqv[138];
	local[2]= fqv[210];
	local[3]= fqv[139];
	local[4]= loadglobal(fqv[9]);
	local[5]= fqv[141];
	local[6]= fqv[183];
	local[7]= fqv[143];
	local[8]= NIL;
	local[9]= fqv[144];
	local[10]= NIL;
	local[11]= fqv[145];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[146];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[19])(ctx,13,local+2,&ftab[19],fqv[147]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1071arced_node_init,fqv[20],fqv[210],fqv[211]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1074arced_node_find_action,fqv[212],fqv[210],fqv[213]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1079arced_node_neighbor_action_alist,fqv[214],fqv[210],fqv[215]);
	local[0]= fqv[91];
	local[1]= fqv[138];
	local[2]= fqv[91];
	local[3]= fqv[139];
	local[4]= loadglobal(fqv[140]);
	local[5]= fqv[141];
	local[6]= fqv[216];
	local[7]= fqv[143];
	local[8]= NIL;
	local[9]= fqv[144];
	local[10]= NIL;
	local[11]= fqv[145];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[146];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[19])(ctx,13,local+2,&ftab[19],fqv[147]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1082solver_node_init,fqv[20],fqv[91],fqv[217]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1087solver_node_path,fqv[89],fqv[91],fqv[218]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1099solver_node_expand,fqv[109],fqv[91],fqv[219]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1108solver_node_state,fqv[45],fqv[91],fqv[220]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1114solver_node_cost,fqv[32],fqv[91],fqv[221]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1120solver_node_parent,fqv[88],fqv[91],fqv[222]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1126solver_node_action,fqv[92],fqv[91],fqv[223]);
	local[0]= fqv[224];
	local[1]= fqv[138];
	local[2]= fqv[224];
	local[3]= fqv[139];
	local[4]= loadglobal(fqv[140]);
	local[5]= fqv[141];
	local[6]= fqv[183];
	local[7]= fqv[143];
	local[8]= NIL;
	local[9]= fqv[144];
	local[10]= NIL;
	local[11]= fqv[145];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[146];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[19])(ctx,13,local+2,&ftab[19],fqv[147]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1132solver_init,fqv[20],fqv[224],fqv[225]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1134solver_solve,fqv[98],fqv[224],fqv[226]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1136solver_solve_by_name,fqv[227],fqv[224],fqv[228]);
	local[0]= fqv[229];
	local[1]= fqv[138];
	local[2]= fqv[229];
	local[3]= fqv[139];
	local[4]= loadglobal(fqv[224]);
	local[5]= fqv[141];
	local[6]= fqv[230];
	local[7]= fqv[143];
	local[8]= NIL;
	local[9]= fqv[144];
	local[10]= NIL;
	local[11]= fqv[145];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[146];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[19])(ctx,13,local+2,&ftab[19],fqv[147]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1139graph_search_solver_solve_init,fqv[102],fqv[229],fqv[231]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1142graph_search_solver_find_node_in_close_list,fqv[107],fqv[229],fqv[232]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1144graph_search_solver_solve,fqv[98],fqv[229],fqv[233]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1153graph_search_solver_add_to_open_list,fqv[100],fqv[229],fqv[234]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1157graph_search_solver_null_open_list_,fqv[103],fqv[229],fqv[235]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1159graph_search_solver_clear_open_list,fqv[113],fqv[229],fqv[236]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1161graph_search_solver_add_list_to_open_list,fqv[108],fqv[229],fqv[237]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1163graph_search_solver_add_object_to_open_list,fqv[114],fqv[229],fqv[238]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1165graph_search_solver_pop_from_open_list,fqv[104],fqv[229],fqv[239]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1168graph_search_solver_open_list,fqv[240],fqv[229],fqv[241]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1174graph_search_solver_close_list,fqv[242],fqv[229],fqv[243]);
	local[0]= fqv[244];
	local[1]= fqv[138];
	local[2]= fqv[244];
	local[3]= fqv[139];
	local[4]= loadglobal(fqv[229]);
	local[5]= fqv[141];
	local[6]= fqv[183];
	local[7]= fqv[143];
	local[8]= NIL;
	local[9]= fqv[144];
	local[10]= NIL;
	local[11]= fqv[145];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[146];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[19])(ctx,13,local+2,&ftab[19],fqv[147]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1180breadth_first_graph_search_solver_init,fqv[20],fqv[244],fqv[245]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1182breadth_first_graph_search_solver_clear_open_list,fqv[113],fqv[244],fqv[246]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1184breadth_first_graph_search_solver_add_list_to_open_list,fqv[108],fqv[244],fqv[247]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1186breadth_first_graph_search_solver_add_object_to_open_list,fqv[114],fqv[244],fqv[248]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1188breadth_first_graph_search_solver_pop_from_open_list,fqv[104],fqv[244],fqv[249]);
	local[0]= fqv[250];
	local[1]= fqv[138];
	local[2]= fqv[250];
	local[3]= fqv[139];
	local[4]= loadglobal(fqv[229]);
	local[5]= fqv[141];
	local[6]= fqv[183];
	local[7]= fqv[143];
	local[8]= NIL;
	local[9]= fqv[144];
	local[10]= NIL;
	local[11]= fqv[145];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[146];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[19])(ctx,13,local+2,&ftab[19],fqv[147]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1192depth_first_graph_search_solver_init,fqv[20],fqv[250],fqv[251]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1194depth_first_graph_search_solver_clear_open_list,fqv[113],fqv[250],fqv[252]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1196depth_first_graph_search_solver_add_list_to_open_list,fqv[108],fqv[250],fqv[253]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1198depth_first_graph_search_solver_add_object_to_open_list,fqv[114],fqv[250],fqv[254]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1200depth_first_graph_search_solver_pop_from_open_list,fqv[104],fqv[250],fqv[255]);
	local[0]= fqv[256];
	local[1]= fqv[138];
	local[2]= fqv[256];
	local[3]= fqv[139];
	local[4]= loadglobal(fqv[229]);
	local[5]= fqv[141];
	local[6]= fqv[257];
	local[7]= fqv[143];
	local[8]= NIL;
	local[9]= fqv[144];
	local[10]= NIL;
	local[11]= fqv[145];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[146];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[19])(ctx,13,local+2,&ftab[19],fqv[147]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1204best_first_graph_search_solver_init,fqv[20],fqv[256],fqv[258]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1206best_first_graph_search_solver_clear_open_list,fqv[113],fqv[256],fqv[259]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1208best_first_graph_search_solver_add_list_to_open_list,fqv[108],fqv[256],fqv[260]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1210best_first_graph_search_solver_add_object_to_open_list,fqv[114],fqv[256],fqv[261]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1212best_first_graph_search_solver_pop_from_open_list,fqv[104],fqv[256],fqv[262]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1230best_first_graph_search_solver_fn,fqv[124],fqv[256],fqv[263]);
	local[0]= fqv[264];
	local[1]= fqv[138];
	local[2]= fqv[264];
	local[3]= fqv[139];
	local[4]= loadglobal(fqv[256]);
	local[5]= fqv[141];
	local[6]= fqv[183];
	local[7]= fqv[143];
	local[8]= NIL;
	local[9]= fqv[144];
	local[10]= NIL;
	local[11]= fqv[145];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[146];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[19])(ctx,13,local+2,&ftab[19],fqv[147]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1232a__graph_search_solver_init,fqv[20],fqv[264],fqv[265]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1234a__graph_search_solver_fn,fqv[124],fqv[264],fqv[266]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1239a__graph_search_solver_gn,fqv[134],fqv[264],fqv[267]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1241a__graph_search_solver_hn,fqv[136],fqv[264],fqv[268]);
	local[0]= fqv[269];
	local[1]= fqv[270];
	ctx->vsp=local+2;
	w=(*ftab[20])(ctx,2,local+0,&ftab[20],fqv[271]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<21; i++) ftab[i]=fcallx;
}
