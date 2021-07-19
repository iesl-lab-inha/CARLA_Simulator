/* ./compose.c :  entry=compose */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "compose.h"
#pragma init (register_compose)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___compose();
extern pointer build_quote_vector();
static int register_compose()
  { add_module_initializer("___compose", ___compose);}

static pointer F2448intersecting_edges();
static pointer F2449cut_body();
static pointer F2450insert_intersections();
static pointer F2451make_edge_segments();
static pointer F2452intersecting_segments();
static pointer F2453sort_edges_by_face();
static pointer F2454make_crossing_edges();
static pointer F2455add_alist();
static pointer F2456merge_segments();
static pointer F2457find_connecting_edge();
static pointer F2458construct_faces();
static pointer F2459initial_intersection_list();
static pointer F2460make_vertex_edge_htab();
static pointer F2461copy_add_vertex();
static pointer F2462find_colinear_int();
static pointer F2463contacting_faces();
static pointer F2464aligned_faces();
static pointer F2465find_equivalent_edge();
static pointer F2466unify_vertex();
static pointer F2467merge_edges_if_colinear();
static pointer F2468merge_contacting_faces();
static pointer F2469merge_aligned_faces();
static pointer F2470compose_body();
static pointer F2471set_original_face();
static pointer F2472body_();
static pointer F2473body_();
static pointer F2474body_();
static pointer F2475body_interference();
static pointer F2476body_();

/*intersecting-edges*/
static pointer F2448intersecting_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[1];
WHL2480:
	if (local[3]==NIL) goto WHX2481;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= argv[0];
	local[5]= fqv[0];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[1] = w;
	if (local[1]==NIL) goto IF2484;
	local[4]= makeflt(0.00000000e+00);
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= makeflt(1.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)LSEQP(ctx,3,local+4); /*<=*/
	if (w==NIL) goto IF2484;
	local[4]= local[2];
	w = local[1];
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	w = local[0];
	ctx->vsp=local+5;
	local[0] = cons(ctx,local[4],w);
	local[4]= local[0];
	goto IF2485;
IF2484:
	local[4]= NIL;
IF2485:
	goto WHL2480;
WHX2481:
	local[4]= NIL;
BLK2482:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK2478:
	ctx->vsp=local; return(local[0]);}

/*cut-body*/
static pointer F2449cut_body(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= argv[1];
	local[8]= argv[0];
	local[9]= fqv[1];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)F2448intersecting_edges(ctx,2,local+7); /*intersecting-edges*/
	local[1] = w;
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)F2453sort_edges_by_face(ctx,1,local+7); /*sort-edges-by-face*/
	local[0] = w;
	local[7]= NIL;
	local[8]= local[0];
WHL2488:
	if (local[8]==NIL) goto WHX2489;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[0])(ctx,1,local+9,&ftab[0],fqv[2]); /*oddp*/
	if (w==NIL) goto IF2492;
	local[9]= fqv[3];
	ctx->vsp=local+10;
	w=(pointer)SIGERROR(ctx,1,local+9); /*error*/
	local[9]= w;
	goto IF2493;
IF2492:
	local[9]= NIL;
IF2493:
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	local[9]= local[5];
	local[10]= fqv[4];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	local[10]= argv[1];
	local[11]= fqv[4];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+9); /*v**/
	local[3] = w;
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(*ftab[1])(ctx,1,local+9,&ftab[1],fqv[5]); /*maxindex*/
	local[2] = w;
	local[9]= local[1];
	local[10]= local[3];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,2,local+10); /*aref*/
	local[10]= w;
	local[11]= makeflt(0.00000000e+00);
	ctx->vsp=local+12;
	w=(pointer)GREATERP(ctx,2,local+10); /*>*/
	if (w==NIL) goto IF2494;
	local[10]= (pointer)get_sym_func(fqv[6]);
	goto IF2495;
IF2494:
	local[10]= (pointer)get_sym_func(fqv[7]);
IF2495:
	ctx->vsp=local+11;
	local[11]= makeclosure(codevec,quotevec,CLO2496,env,argv,local);
	ctx->vsp=local+12;
	w=(pointer)SORT(ctx,3,local+9); /*sort*/
	local[1] = w;
WHL2497:
	if (local[1]==NIL) goto WHX2498;
	local[9]= loadglobal(fqv[8]);
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,1,local+9); /*instantiate*/
	local[9]= w;
	local[10]= local[9];
	local[11]= fqv[9];
	local[12]= fqv[10];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	local[14]= fqv[11];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	local[16]= fqv[12];
	local[17]= argv[1];
	local[18]= fqv[13];
	local[19]= local[5];
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,10,local+10); /*send*/
	w = local[9];
	local[9]= w;
	w = local[4];
	ctx->vsp=local+10;
	local[4] = cons(ctx,local[9],w);
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	goto WHL2497;
WHX2498:
	local[9]= NIL;
BLK2499:
	goto WHL2488;
WHX2489:
	local[9]= NIL;
BLK2490:
	w = NIL;
	local[7]= argv[1];
	w = local[4];
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)F2458construct_faces(ctx,1,local+7); /*construct-faces*/
	local[0]= w;
BLK2486:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2496(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= env->c.clo.env2[2];
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*insert-intersections*/
static pointer F2450insert_intersections(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,FLET2502,env,argv,local);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[1];
WHL2504:
	if (local[5]==NIL) goto WHX2505;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[4];
	local[7]= fqv[14];
	local[8]= makeflt(1.00000000e-02);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	local[7]= fqv[15];
	local[8]= argv[2];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	if (w==NIL) goto IF2508;
	local[6]= NIL;
	local[7]= argv[0];
WHL2511:
	if (local[7]==NIL) goto WHX2512;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[4];
	local[9]= fqv[0];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[1] = w;
	w = local[1];
	if (!iscons(w)) goto IF2515;
	local[8]= local[4];
	local[9]= fqv[16];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	if (w!=NIL) goto IF2515;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
WHL2517:
	if (local[3]==NIL) goto WHX2518;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(*ftab[2])(ctx,2,local+8,&ftab[2],fqv[17]); /*eps=*/
	if (w==NIL) goto CON2521;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= local[4];
	w = local[0];
	ctx->vsp=local+11;
	w=FLET2502(ctx,3,local+8,w);
	w = NIL;
	ctx->vsp=local+8;
	local[8]=w;
	goto BLK2519;
	goto CON2520;
CON2521:
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)LESSP(ctx,2,local+8); /*<*/
	if (w==NIL) goto CON2522;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= makeflt(1.00000000e+00);
	ctx->vsp=local+10;
	w=(*ftab[2])(ctx,2,local+8,&ftab[2],fqv[17]); /*eps=*/
	if (w==NIL) goto IF2523;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= local[4];
	w = local[0];
	ctx->vsp=local+11;
	w=FLET2502(ctx,3,local+8,w);
	w = NIL;
	ctx->vsp=local+8;
	local[8]=w;
	goto BLK2519;
	goto IF2524;
IF2523:
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[8];
	local[8]= w;
IF2524:
	goto CON2520;
CON2522:
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)GREATERP(ctx,2,local+8); /*>*/
	if (w==NIL) goto CON2526;
	local[8]= local[3];
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)RPLACD(ctx,2,local+8); /*rplacd*/
	local[8]= local[3];
	local[9]= local[1];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)NCONC(ctx,2,local+9); /*nconc*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)RPLACA(ctx,2,local+8); /*rplaca*/
	w = NIL;
	ctx->vsp=local+8;
	local[8]=w;
	goto BLK2519;
	goto CON2520;
CON2526:
	local[8]= NIL;
CON2520:
	goto WHL2517;
WHX2518:
	local[8]= NIL;
BLK2519:
	goto IF2516;
IF2515:
	local[8]= NIL;
IF2516:
	goto WHL2511;
WHX2512:
	local[8]= NIL;
BLK2513:
	w = argv[0];
	local[6]= w;
	goto IF2509;
IF2508:
	local[6]= NIL;
IF2509:
	goto WHL2504;
WHX2505:
	local[6]= NIL;
BLK2506:
	w = NIL;
	local[0]= w;
BLK2501:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET2502(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr!=NIL) goto IF2527;
	local[0]= argv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	local[0]= w;
	goto IF2528;
IF2527:
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	local[2]= argv[2];
	local[3]= fqv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= makeflt((double)fabs(fltval(w)));
	local[2]= local[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= fqv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)VINNERPRODUCT(ctx,2,local+2); /*v.*/
	{ double left,right;
		right=fltval(makeflt((double)fabs(fltval(w)))); left=fltval(local[1]);
	if (left <= right) goto IF2529;}
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)RPLACA(ctx,2,local+1); /*rplaca*/
	local[1]= w;
	goto IF2530;
IF2529:
	local[1]= NIL;
IF2530:
	w = local[1];
	local[0]= w;
IF2528:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*make-edge-segments*/
static pointer F2451make_edge_segments(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= makeint(0);
	local[3]= makeint(0);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= argv[0];
WHL2533:
	if (local[10]==NIL) goto WHX2534;
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
	local[11]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[11];
	local[6] = w;
WHL2538:
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX2539;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[11];
	local[3] = w;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.car;
	local[11]= makeflt(5.00000000e-01);
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(*ftab[3])(ctx,4,local+11,&ftab[3],fqv[19]); /*midpoint*/
	local[11]= argv[1];
	local[12]= fqv[20];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[5] = w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.car;
	local[11]= local[5];
	if (argv[2]==local[11]) goto OR2544;
	local[11]= local[5];
	if (fqv[21]==local[11]) goto OR2544;
	goto IF2542;
OR2544:
	local[11]= loadglobal(fqv[8]);
	ctx->vsp=local+12;
	w=(pointer)INSTANTIATE(ctx,1,local+11); /*instantiate*/
	local[11]= w;
	local[12]= local[11];
	local[13]= fqv[9];
	local[14]= fqv[10];
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	local[16]= fqv[11];
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17]= (w)->c.cons.car;
	local[18]= fqv[12];
	local[19]= local[6]->c.obj.iv[3];
	local[20]= fqv[13];
	local[21]= local[6]->c.obj.iv[4];
	local[22]= fqv[22];
	local[23]= local[6]->c.obj.iv[6];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,12,local+12); /*send*/
	w = local[11];
	local[1] = w;
	local[11]= local[6];
	local[12]= local[1];
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	local[15]= local[5];
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17]= (w)->c.cons.car;
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,7,local+11); /*list*/
	local[11]= w;
	w = local[0];
	ctx->vsp=local+12;
	local[0] = cons(ctx,local[11],w);
	local[11]= local[0];
	goto IF2543;
IF2542:
	local[11]= NIL;
IF2543:
	goto WHL2538;
WHX2539:
	local[11]= NIL;
BLK2540:
	goto WHL2533;
WHX2534:
	local[11]= NIL;
BLK2535:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK2531:
	ctx->vsp=local; return(local[0]);}

/*intersecting-segments*/
static pointer F2452intersecting_segments(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO2547,env,argv,local);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
BLK2546:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2547(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car!=NIL) goto OR2550;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[4])(ctx,1,local+0,&ftab[4],fqv[23]); /*fourth*/
	if (w!=NIL) goto OR2550;
	goto IF2548;
OR2550:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[5])(ctx,1,local+0,&ftab[5],fqv[24]); /*fifth*/
	local[0]= w;
	if (fqv[21]==local[0]) goto IF2548;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF2549;
IF2548:
	local[0]= NIL;
IF2549:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*sort-edges-by-face*/
static pointer F2453sort_edges_by_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[0];
WHL2553:
	if (local[5]==NIL) goto WHX2554;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	local[6]= local[3]->c.obj.iv[3];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)ASSQ(ctx,2,local+6); /*assq*/
	local[1] = w;
	if (local[1]!=NIL) goto IF2557;
	local[6]= local[3]->c.obj.iv[3];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	w = local[0];
	ctx->vsp=local+7;
	local[0] = cons(ctx,local[6],w);
	local[6]= local[0];
	goto IF2558;
IF2557:
	local[6]= local[1];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)NCONC(ctx,2,local+6); /*nconc*/
	local[6]= w;
IF2558:
	local[6]= local[3]->c.obj.iv[4];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)ASSQ(ctx,2,local+6); /*assq*/
	local[1] = w;
	if (local[1]!=NIL) goto IF2559;
	local[6]= local[3]->c.obj.iv[4];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	w = local[0];
	ctx->vsp=local+7;
	local[0] = cons(ctx,local[6],w);
	local[6]= local[0];
	goto IF2560;
IF2559:
	local[6]= local[1];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)NCONC(ctx,2,local+6); /*nconc*/
	local[6]= w;
IF2560:
	goto WHL2553;
WHX2554:
	local[6]= NIL;
BLK2555:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK2551:
	ctx->vsp=local; return(local[0]);}

/*make-crossing-edges*/
static pointer F2454make_crossing_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= NIL;
	local[15]= NIL;
	local[16]= NIL;
	local[17]= NIL;
	local[18]= argv[0];
WHL2563:
	if (local[18]==NIL) goto WHX2564;
	w=local[18];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	w=local[18];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18] = (w)->c.cons.cdr;
	w = local[19];
	local[17] = w;
	w = local[17];
	if (iscons(w)) goto IF2567;
	local[19]= fqv[25];
	local[20]= local[17];
	ctx->vsp=local+21;
	w=(pointer)SIGERROR(ctx,2,local+19); /*error*/
	local[19]= w;
	goto IF2568;
IF2567:
	local[19]= NIL;
IF2568:
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	local[19]= local[0];
	local[20]= fqv[4];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,2,local+19); /*send*/
	local[13] = w;
	local[1] = NIL;
	local[19]= NIL;
	local[20]= local[2];
WHL2570:
	if (local[20]==NIL) goto WHX2571;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20] = (w)->c.cons.cdr;
	w = local[21];
	local[19] = w;
	w = local[19];
	if (iscons(w)) goto IF2574;
	local[21]= fqv[26];
	local[22]= local[19];
	ctx->vsp=local+23;
	w=(pointer)SIGERROR(ctx,2,local+21); /*error*/
	local[21]= w;
	goto IF2575;
IF2574:
	local[21]= NIL;
IF2575:
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto IF2576;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	local[22]= local[1];
	ctx->vsp=local+23;
	w=(*ftab[6])(ctx,2,local+21,&ftab[6],fqv[27]); /*member*/
	if (w!=NIL) goto IF2576;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w = local[1];
	ctx->vsp=local+22;
	local[1] = cons(ctx,local[21],w);
	local[21]= local[1];
	goto IF2577;
IF2576:
	local[21]= NIL;
IF2577:
	local[21]= local[19];
	ctx->vsp=local+22;
	w=(*ftab[4])(ctx,1,local+21,&ftab[4],fqv[23]); /*fourth*/
	if (w==NIL) goto IF2578;
	local[21]= local[19];
	ctx->vsp=local+22;
	w=(*ftab[4])(ctx,1,local+21,&ftab[4],fqv[23]); /*fourth*/
	local[21]= w;
	local[22]= local[1];
	ctx->vsp=local+23;
	w=(*ftab[6])(ctx,2,local+21,&ftab[6],fqv[27]); /*member*/
	if (w!=NIL) goto IF2578;
	local[21]= local[19];
	ctx->vsp=local+22;
	w=(*ftab[4])(ctx,1,local+21,&ftab[4],fqv[23]); /*fourth*/
	local[21]= w;
	w = local[1];
	ctx->vsp=local+22;
	local[1] = cons(ctx,local[21],w);
	local[21]= local[1];
	goto IF2579;
IF2578:
	local[21]= NIL;
IF2579:
	goto WHL2570;
WHX2571:
	local[21]= NIL;
BLK2572:
	w = NIL;
	local[19]= NIL;
	local[20]= local[1];
WHL2581:
	if (local[20]==NIL) goto WHX2582;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20] = (w)->c.cons.cdr;
	w = local[21];
	local[19] = w;
	local[9] = NIL;
	local[10] = NIL;
	local[21]= NIL;
	local[22]= local[2];
WHL2586:
	if (local[22]==NIL) goto WHX2587;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22] = (w)->c.cons.cdr;
	w = local[23];
	local[21] = w;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.car;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	if (local[19]!=local[23]) goto CON2591;
	local[23]= local[21];
	ctx->vsp=local+24;
	w=(*ftab[7])(ctx,1,local+23,&ftab[7],fqv[28]); /*sixth*/
	local[23]= w;
	local[24]= makeflt(0.00000000e+00);
	ctx->vsp=local+25;
	w=(*ftab[8])(ctx,2,local+23,&ftab[8],fqv[29]); /*eps<>*/
	if (w==NIL) goto CON2591;
	local[23]= local[4]->c.obj.iv[1];
	w = local[9];
	ctx->vsp=local+24;
	local[9] = cons(ctx,local[23],w);
	local[23]= local[9];
	goto CON2590;
CON2591:
	local[23]= local[21];
	ctx->vsp=local+24;
	w=(*ftab[4])(ctx,1,local+23,&ftab[4],fqv[23]); /*fourth*/
	local[23]= w;
	if (local[19]!=local[23]) goto CON2592;
	local[23]= local[21];
	ctx->vsp=local+24;
	w=(*ftab[9])(ctx,1,local+23,&ftab[9],fqv[30]); /*seventh*/
	local[23]= w;
	local[24]= makeflt(1.00000000e+00);
	ctx->vsp=local+25;
	w=(*ftab[8])(ctx,2,local+23,&ftab[8],fqv[29]); /*eps<>*/
	if (w==NIL) goto CON2592;
	local[23]= local[4]->c.obj.iv[2];
	w = local[9];
	ctx->vsp=local+24;
	local[9] = cons(ctx,local[23],w);
	local[23]= local[9];
	goto CON2590;
CON2592:
	local[23]= NIL;
CON2590:
	goto WHL2586;
WHX2587:
	local[23]= NIL;
BLK2588:
	w = NIL;
	local[21]= NIL;
	local[22]= local[19];
	local[23]= argv[1];
	ctx->vsp=local+24;
	w=(pointer)ASSQ(ctx,2,local+22); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.cdr;
WHL2594:
	if (local[22]==NIL) goto WHX2595;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22] = (w)->c.cons.cdr;
	w = local[23];
	local[21] = w;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.car;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	if (local[0]!=local[23]) goto CON2599;
	local[23]= local[21];
	ctx->vsp=local+24;
	w=(*ftab[7])(ctx,1,local+23,&ftab[7],fqv[28]); /*sixth*/
	local[23]= w;
	local[24]= makeflt(0.00000000e+00);
	ctx->vsp=local+25;
	w=(*ftab[8])(ctx,2,local+23,&ftab[8],fqv[29]); /*eps<>*/
	if (w==NIL) goto CON2599;
	local[23]= local[4]->c.obj.iv[1];
	w = local[10];
	ctx->vsp=local+24;
	local[10] = cons(ctx,local[23],w);
	local[23]= local[10];
	goto CON2598;
CON2599:
	local[23]= local[21];
	ctx->vsp=local+24;
	w=(*ftab[4])(ctx,1,local+23,&ftab[4],fqv[23]); /*fourth*/
	local[23]= w;
	if (local[0]!=local[23]) goto CON2600;
	local[23]= local[21];
	ctx->vsp=local+24;
	w=(*ftab[9])(ctx,1,local+23,&ftab[9],fqv[30]); /*seventh*/
	local[23]= w;
	local[24]= makeflt(1.00000000e+00);
	ctx->vsp=local+25;
	w=(*ftab[8])(ctx,2,local+23,&ftab[8],fqv[29]); /*eps<>*/
	if (w==NIL) goto CON2600;
	local[23]= local[4]->c.obj.iv[2];
	w = local[10];
	ctx->vsp=local+24;
	local[10] = cons(ctx,local[23],w);
	local[23]= local[10];
	goto CON2598;
CON2600:
	local[23]= NIL;
CON2598:
	goto WHL2594;
WHX2595:
	local[23]= NIL;
BLK2596:
	w = NIL;
	local[21]= *(ovafptr(local[19],fqv[31]));
	local[22]= *(ovafptr(local[0],fqv[31]));
	ctx->vsp=local+23;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+21); /*v**/
	local[5] = w;
	local[21]= local[5];
	ctx->vsp=local+22;
	w=(*ftab[1])(ctx,1,local+21,&ftab[1],fqv[5]); /*maxindex*/
	local[6] = w;
	local[21]= argv[3];
	if (fqv[32]!=local[21]) goto IF2601;
	local[21]= local[5];
	local[22]= local[6];
	ctx->vsp=local+23;
	w=(pointer)AREF(ctx,2,local+21); /*aref*/
	local[21]= w;
	local[22]= makeflt(0.00000000e+00);
	ctx->vsp=local+23;
	w=(pointer)LESSP(ctx,2,local+21); /*<*/
	if (w==NIL) goto IF2603;
	local[21]= (pointer)get_sym_func(fqv[33]);
	goto IF2604;
IF2603:
	local[21]= (pointer)get_sym_func(fqv[34]);
IF2604:
	goto IF2602;
IF2601:
	local[21]= local[5];
	local[22]= local[6];
	ctx->vsp=local+23;
	w=(pointer)AREF(ctx,2,local+21); /*aref*/
	local[21]= w;
	local[22]= makeflt(0.00000000e+00);
	ctx->vsp=local+23;
	w=(pointer)LESSP(ctx,2,local+21); /*<*/
	if (w==NIL) goto IF2605;
	local[21]= (pointer)get_sym_func(fqv[34]);
	goto IF2606;
IF2605:
	local[21]= (pointer)get_sym_func(fqv[33]);
IF2606:
IF2602:
	local[7] = local[21];
	local[21]= local[9];
	local[22]= local[10];
	ctx->vsp=local+23;
	w=(pointer)APPEND(ctx,2,local+21); /*append*/
	local[21]= w;
	local[22]= local[7];
	ctx->vsp=local+23;
	local[23]= makeclosure(codevec,quotevec,CLO2607,env,argv,local);
	ctx->vsp=local+24;
	w=(pointer)SORT(ctx,3,local+21); /*sort*/
	local[8] = w;
	local[21]= local[8];
	local[22]= fqv[35];
	local[23]= (pointer)get_sym_func(fqv[36]);
	ctx->vsp=local+24;
	w=(*ftab[10])(ctx,3,local+21,&ftab[10],fqv[37]); /*remove-duplicates*/
	local[8] = w;
	local[14] = NIL;
WHL2608:
	if (local[8]==NIL) goto WHX2609;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[21];
	local[11] = w;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[21];
	local[12] = w;
	if (local[11]==NIL) goto IF2613;
	if (local[12]==NIL) goto IF2613;
	local[21]= local[0];
	local[22]= fqv[38];
	local[23]= makeflt(5.00000000e-01);
	local[24]= local[11];
	local[25]= local[12];
	ctx->vsp=local+26;
	w=(*ftab[3])(ctx,3,local+23,&ftab[3],fqv[19]); /*midpoint*/
	local[23]= w;
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,3,local+21); /*send*/
	if (w!=NIL) goto IF2613;
	local[21]= local[19];
	local[22]= fqv[38];
	local[23]= makeflt(5.00000000e-01);
	local[24]= local[11];
	local[25]= local[12];
	ctx->vsp=local+26;
	w=(*ftab[3])(ctx,3,local+23,&ftab[3],fqv[19]); /*midpoint*/
	local[23]= w;
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,3,local+21); /*send*/
	if (w!=NIL) goto IF2613;
	if (argv[2]!=NIL) goto OR2615;
	local[21]= local[11];
	w = local[9];
	if (memq(local[21],w)==NIL) goto AND2616;
	local[21]= local[12];
	w = local[9];
	if (memq(local[21],w)==NIL) goto AND2616;
	goto OR2615;
AND2616:
	goto IF2613;
OR2615:
	local[21]= loadglobal(fqv[8]);
	ctx->vsp=local+22;
	w=(pointer)INSTANTIATE(ctx,1,local+21); /*instantiate*/
	local[21]= w;
	local[22]= local[21];
	local[23]= fqv[9];
	local[24]= fqv[10];
	local[25]= local[11];
	local[26]= fqv[11];
	local[27]= local[12];
	local[28]= fqv[12];
	local[29]= local[0];
	local[30]= fqv[13];
	local[31]= local[19];
	local[32]= fqv[39];
	local[33]= NIL;
	ctx->vsp=local+34;
	w=(pointer)SEND(ctx,12,local+22); /*send*/
	w = local[21];
	local[4] = w;
	local[21]= local[4];
	w = local[14];
	ctx->vsp=local+22;
	local[14] = cons(ctx,local[21],w);
	local[21]= local[14];
	goto IF2614;
IF2613:
	local[21]= NIL;
IF2614:
	goto WHL2608;
WHX2609:
	local[21]= NIL;
BLK2610:
	if (local[14]==NIL) goto IF2618;
	local[21]= local[0];
	w = local[14];
	ctx->vsp=local+22;
	local[21]= cons(ctx,local[21],w);
	w = local[15];
	ctx->vsp=local+22;
	local[15] = cons(ctx,local[21],w);
	local[21]= local[19];
	local[22]= local[14];
	ctx->vsp=local+23;
	w=(pointer)COPYSEQ(ctx,1,local+22); /*copy-seq*/
	ctx->vsp=local+22;
	local[21]= cons(ctx,local[21],w);
	w = local[16];
	ctx->vsp=local+22;
	local[16] = cons(ctx,local[21],w);
	local[21]= local[16];
	goto IF2619;
IF2618:
	local[21]= NIL;
IF2619:
	goto WHL2581;
WHX2582:
	local[21]= NIL;
BLK2583:
	w = NIL;
	goto WHL2563;
WHX2564:
	local[19]= NIL;
BLK2565:
	w = NIL;
	local[17]= local[15];
	local[18]= local[16];
	ctx->vsp=local+19;
	w=(pointer)LIST(ctx,2,local+17); /*list*/
	local[0]= w;
BLK2561:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2607(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env2[6];
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*add-alist*/
static pointer F2455add_alist(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	local[0]= w;
	if (local[0]!=NIL) goto IF2621;
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(*ftab[11])(ctx,3,local+1,&ftab[11],fqv[40]); /*acons*/
	local[1]= w;
	goto IF2622;
IF2621:
	local[1]= local[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)NCONC(ctx,2,local+1); /*nconc*/
	local[1]= argv[2];
IF2622:
	w = local[1];
	local[0]= w;
BLK2620:
	ctx->vsp=local; return(local[0]);}

/*merge-segments*/
static pointer F2456merge_segments(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0];
WHL2625:
	if (local[1]==NIL) goto WHX2626;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= (pointer)get_sym_func(fqv[41]);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)RPLACD(ctx,2,local+2); /*rplacd*/
	goto WHL2625;
WHX2626:
	local[2]= NIL;
BLK2627:
	w = NIL;
	local[0]= NIL;
	local[1]= argv[1];
WHL2630:
	if (local[1]==NIL) goto WHX2631;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F2455add_alist(ctx,3,local+2); /*add-alist*/
	argv[0] = w;
	goto WHL2630;
WHX2631:
	local[2]= NIL;
BLK2632:
	w = NIL;
	local[0]= NIL;
	local[1]= argv[2];
WHL2635:
	if (local[1]==NIL) goto WHX2636;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F2455add_alist(ctx,3,local+2); /*add-alist*/
	argv[0] = w;
	goto WHL2635;
WHX2636:
	local[2]= NIL;
BLK2637:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK2623:
	ctx->vsp=local; return(local[0]);}

/*find-connecting-edge*/
static pointer F2457find_connecting_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2641;}
	local[0]= (pointer)get_sym_func(fqv[42]);
ENT2641:
ENT2640:
	if (n>3) maerror();
	local[1]= local[0];
	if ((pointer)get_sym_func(fqv[42])!=local[1]) goto IF2642;
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO2644,env,argv,local);
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(*ftab[12])(ctx,2,local+1,&ftab[12],fqv[43]); /*find-if*/
	local[1]= w;
	goto IF2643;
IF2642:
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO2645,env,argv,local);
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(*ftab[12])(ctx,2,local+1,&ftab[12],fqv[43]); /*find-if*/
	local[1]= w;
IF2643:
	w = local[1];
	local[0]= w;
BLK2639:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2644(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[0]= ((env->c.clo.env1[0])==(local[0])?T:NIL);
	if (local[0]!=NIL) goto OR2646;
	local[0]= argv[0]->c.obj.iv[2];
	local[0]= ((env->c.clo.env1[0])==(local[0])?T:NIL);
OR2646:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2645(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env2[0];
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= env->c.clo.env1[0];
	ctx->vsp=local+3;
	w=(pointer)FUNCALL(ctx,3,local+0); /*funcall*/
	local[0]= w;
	if (w!=NIL) goto OR2647;
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= env->c.clo.env1[0];
	ctx->vsp=local+2;
	w=(pointer)FUNCALL(ctx,2,local+0); /*funcall*/
	local[0]= w;
OR2647:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*construct-faces*/
static pointer F2458construct_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)COPYSEQ(ctx,1,local+0); /*copy-seq*/
	local[0]= w;
	storeglobal(fqv[44],w);
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
WHL2649:
	if (local[4]==NIL) goto WHX2650;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[5]= w;
	local[6]= local[5];
	local[7]= fqv[10];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	local[7]= local[6];
	local[8]= NIL;
	local[9]= NIL;
	local[10]= loadglobal(fqv[45]);
	ctx->vsp=local+11;
	w=(pointer)INSTANTIATE(ctx,1,local+10); /*instantiate*/
	local[10]= w;
	local[11]= NIL;
WHL2653:
	if (local[5]==NIL) goto WHX2654;
	local[12]= local[5];
	local[13]= fqv[11];
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[8] = w;
	local[12]= local[5];
	local[13]= fqv[46];
	local[14]= local[7];
	local[15]= local[8];
	local[16]= local[10];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,5,local+12); /*send*/
	local[12]= local[5];
	w = local[9];
	ctx->vsp=local+13;
	local[9] = cons(ctx,local[12],w);
	local[12]= local[5];
	local[13]= local[4];
	local[14]= fqv[47];
	local[15]= makeint(1);
	ctx->vsp=local+16;
	w=(*ftab[13])(ctx,4,local+12,&ftab[13],fqv[48]); /*delete*/
	local[4] = w;
	local[12]= local[8];
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)F2457find_connecting_edge(ctx,2,local+12); /*find-connecting-edge*/
	local[5] = w;
	local[7] = local[8];
	goto WHL2653;
WHX2654:
	local[12]= NIL;
BLK2655:
	local[12]= local[9];
	ctx->vsp=local+13;
	w=(pointer)NREVERSE(ctx,1,local+12); /*nreverse*/
	local[9] = w;
	local[12]= local[3];
	local[13]= fqv[49];
	ctx->vsp=local+14;
	w=(*ftab[14])(ctx,2,local+12,&ftab[14],fqv[50]); /*find-method*/
	if (w==NIL) goto IF2656;
	local[12]= local[3];
	local[13]= fqv[49];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[11] = w;
	local[12]= local[11];
	goto IF2657;
IF2656:
	local[12]= NIL;
IF2657:
	local[12]= local[10];
	local[13]= fqv[9];
	local[14]= fqv[1];
	local[15]= local[9];
	local[16]= fqv[49];
	local[17]= local[11];
	local[18]= fqv[51];
	if (local[11]==NIL) goto IF2658;
	local[19]= local[11];
	local[20]= fqv[51];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,2,local+19); /*send*/
	local[19]= w;
	goto IF2659;
IF2658:
	local[19]= NIL;
IF2659:
	local[20]= fqv[52];
	local[21]= local[3];
	local[22]= fqv[52];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,2,local+21); /*send*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,10,local+12); /*send*/
	local[12]= local[3];
	local[13]= fqv[4];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[12]= w;
	local[13]= local[10];
	local[14]= fqv[4];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)VINNERPRODUCT(ctx,2,local+12); /*v.*/
	local[12]= w;
	{ double left,right;
		right=fltval(makeflt(0.00000000e+00)); left=fltval(local[12]);
	if (left >= right) goto CON2661;}
	local[12]= local[10];
	w = local[9];
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	w = local[1];
	ctx->vsp=local+13;
	local[1] = cons(ctx,local[12],w);
	local[12]= local[1];
	goto CON2660;
CON2661:
	local[12]= local[10];
	w = local[0];
	ctx->vsp=local+13;
	local[0] = cons(ctx,local[12],w);
	local[12]= local[0];
	goto CON2660;
CON2662:
	local[12]= NIL;
CON2660:
	w = local[12];
	goto WHL2649;
WHX2650:
	local[5]= NIL;
BLK2651:
	if (local[1]==NIL) goto IF2663;
	if (loadglobal(fqv[53])==NIL) goto IF2665;
	local[5]= T;
	local[6]= fqv[54];
	local[7]= local[0];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,4,local+5); /*format*/
	local[5]= w;
	goto IF2666;
IF2665:
	local[5]= NIL;
IF2666:
	local[5]= NIL;
	local[6]= local[1];
WHL2668:
	if (local[6]==NIL) goto WHX2669;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= NIL;
	local[8]= local[0];
WHL2674:
	if (local[8]==NIL) goto WHX2675;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[7];
	local[10]= fqv[20];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= *(ovafptr((w)->c.cons.car,fqv[55]));
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= w;
	if (fqv[56]!=local[9]) goto IF2678;
	local[9]= NIL;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.cdr;
WHL2681:
	if (local[10]==NIL) goto WHX2682;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	local[11]= local[9];
	local[12]= fqv[46];
	local[13]= local[9];
	local[14]= fqv[10];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= w;
	local[14]= local[9];
	local[15]= fqv[11];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[14]= w;
	local[15]= local[7];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,5,local+11); /*send*/
	goto WHL2681;
WHX2682:
	local[11]= NIL;
BLK2683:
	w = NIL;
	local[9]= loadglobal(fqv[57]);
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,1,local+9); /*instantiate*/
	local[9]= w;
	local[10]= local[9];
	local[11]= fqv[9];
	local[12]= fqv[1];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.cdr;
	local[14]= fqv[58];
	local[15]= local[7];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,6,local+10); /*send*/
	w = local[9];
	local[2] = w;
	local[9]= local[7];
	local[10]= fqv[59];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	w = NIL;
	ctx->vsp=local+9;
	local[7]=w;
	goto BLK2672;
	goto IF2679;
IF2678:
	local[9]= NIL;
IF2679:
	goto WHL2674;
WHX2675:
	local[9]= NIL;
BLK2676:
	w = NIL;
	local[7]= local[0];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	storeglobal(fqv[60],w);
	local[7]= fqv[61];
	ctx->vsp=local+8;
	w=(pointer)SIGERROR(ctx,1,local+7); /*error*/
	local[7]= w;
BLK2672:
	goto WHL2668;
WHX2669:
	local[7]= NIL;
BLK2670:
	w = NIL;
	local[5]= w;
	goto IF2664;
IF2663:
	local[5]= NIL;
IF2664:
	w = local[0];
	local[0]= w;
BLK2648:
	ctx->vsp=local; return(local[0]);}

/*initial-intersection-list*/
static pointer F2459initial_intersection_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
WHL2688:
	if (local[3]==NIL) goto WHX2689;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	local[5]= makeflt(0.00000000e+00);
	local[6]= local[2]->c.obj.iv[1];
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(*ftab[15])(ctx,2,local+6,&ftab[15],fqv[62]); /*gethash*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,2,local+5); /*list*/
	local[5]= w;
	local[6]= makeflt(1.00000000e+00);
	local[7]= local[2]->c.obj.iv[2];
	local[8]= argv[1];
	ctx->vsp=local+9;
	w=(*ftab[15])(ctx,2,local+7,&ftab[15],fqv[62]); /*gethash*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,3,local+4); /*list*/
	local[4]= w;
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	goto WHL2688;
WHX2689:
	local[4]= NIL;
BLK2690:
	w = local[1];
	local[0]= w;
BLK2686:
	ctx->vsp=local; return(local[0]);}

/*make-vertex-edge-htab*/
static pointer F2460make_vertex_edge_htab(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(*ftab[16])(ctx,1,local+5,&ftab[16],fqv[63]); /*bodyp*/
	if (w==NIL) goto CON2694;
	local[1] = argv[0]->c.obj.iv[11];
	local[0] = argv[0]->c.obj.iv[10];
	local[5]= local[0];
	goto CON2693;
CON2694:
	local[5]= (pointer)get_sym_func(fqv[64]);
	local[6]= argv[0];
	local[7]= fqv[65];
	ctx->vsp=local+8;
	w=(*ftab[17])(ctx,2,local+6,&ftab[17],fqv[66]); /*send-all*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,2,local+5); /*apply*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[10])(ctx,1,local+5,&ftab[10],fqv[37]); /*remove-duplicates*/
	local[1] = w;
	local[5]= (pointer)get_sym_func(fqv[64]);
	local[6]= argv[0];
	local[7]= fqv[67];
	ctx->vsp=local+8;
	w=(*ftab[17])(ctx,2,local+6,&ftab[17],fqv[66]); /*send-all*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,2,local+5); /*apply*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[10])(ctx,1,local+5,&ftab[10],fqv[37]); /*remove-duplicates*/
	local[0] = w;
	local[5]= local[0];
	goto CON2693;
CON2695:
	local[5]= NIL;
CON2693:
	local[5]= fqv[68];
	local[6]= makeint(2);
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	{ eusinteger_t i,j;
		j=intval(w); i=intval(local[6]);
		local[6]=(makeint(i * j));}
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[18])(ctx,2,local+5,&ftab[18],fqv[69]); /*make-hash-table*/
	local[2] = w;
	local[5]= NIL;
	local[6]= local[0];
WHL2697:
	if (local[6]==NIL) goto WHX2698;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[3] = local[5]->c.obj.iv[1];
	local[4] = local[5]->c.obj.iv[2];
	local[7]= local[3];
	local[8]= local[2];
	local[9]= local[5];
	local[10]= local[3];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(*ftab[15])(ctx,2,local+10,&ftab[15],fqv[62]); /*gethash*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(*ftab[19])(ctx,3,local+7,&ftab[19],fqv[70]); /*sethash*/
	local[7]= local[4];
	local[8]= local[2];
	local[9]= local[5];
	local[10]= local[4];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(*ftab[15])(ctx,2,local+10,&ftab[15],fqv[62]); /*gethash*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(*ftab[19])(ctx,3,local+7,&ftab[19],fqv[70]); /*sethash*/
	goto WHL2697;
WHX2698:
	local[7]= NIL;
BLK2699:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK2692:
	ctx->vsp=local; return(local[0]);}

/*copy-add-vertex*/
static pointer F2461copy_add_vertex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO2702,env,argv,local);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[20])(ctx,2,local+0,&ftab[20],fqv[71]); /*maphash*/
	local[0]= w;
BLK2701:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2702(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env1[0];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)COPYSEQ(ctx,1,local+2); /*copy-seq*/
	local[2]= w;
	w = argv[1];
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(*ftab[19])(ctx,3,local+0,&ftab[19],fqv[70]); /*sethash*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*find-colinear-int*/
static pointer F2462find_colinear_int(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
WHL2705:
	if (local[2]==NIL) goto WHX2706;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
WHL2710:
	if (local[4]==NIL) goto WHX2711;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= fqv[72];
	ctx->vsp=local+7;
	w=(pointer)EQ(ctx,2,local+5); /*eql*/
	if (w==NIL) goto IF2714;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)LIST_STAR(ctx,2,local+5); /*list**/
	local[5]= w;
	w = local[0];
	ctx->vsp=local+6;
	local[0] = cons(ctx,local[5],w);
	local[5]= local[0];
	goto IF2715;
IF2714:
	local[5]= NIL;
IF2715:
	goto WHL2710;
WHX2711:
	local[5]= NIL;
BLK2712:
	w = NIL;
	goto WHL2705;
WHX2706:
	local[3]= NIL;
BLK2707:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK2703:
	ctx->vsp=local; return(local[0]);}

/*contacting-faces*/
static pointer F2463contacting_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= argv[0];
	local[9]= loadglobal(fqv[73]);
	ctx->vsp=local+10;
	w=(pointer)DERIVEDP(ctx,2,local+8); /*derivedp*/
	if (w==NIL) goto IF2717;
	local[0] = argv[0]->c.obj.iv[9];
	local[8]= local[0];
	goto IF2718;
IF2717:
	local[8]= NIL;
IF2718:
	local[8]= argv[1];
	local[9]= loadglobal(fqv[73]);
	ctx->vsp=local+10;
	w=(pointer)DERIVEDP(ctx,2,local+8); /*derivedp*/
	if (w==NIL) goto IF2719;
	local[1] = argv[1]->c.obj.iv[9];
	local[8]= local[1];
	goto IF2720;
IF2719:
	local[8]= NIL;
IF2720:
	local[8]= NIL;
	local[9]= local[0];
WHL2722:
	if (local[9]==NIL) goto WHX2723;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= NIL;
	local[11]= local[1];
WHL2727:
	if (local[11]==NIL) goto WHX2728;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[12];
	local[10] = w;
	local[12]= local[8];
	local[13]= fqv[74];
	local[14]= local[10];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[2] = w;
	if (local[2]==NIL) goto IF2731;
	local[12]= (pointer)get_sym_func(fqv[75]);
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)MAPCAR(ctx,2,local+12); /*mapcar*/
	local[6] = w;
	local[12]= (pointer)get_sym_func(fqv[75]);
	local[13]= (pointer)get_sym_func(fqv[64]);
	local[14]= (pointer)get_sym_func(fqv[76]);
	local[15]= local[2];
	ctx->vsp=local+16;
	w=(pointer)MAPCAR(ctx,2,local+14); /*mapcar*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)APPLY(ctx,2,local+13); /*apply*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)MAPCAR(ctx,2,local+12); /*mapcar*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(*ftab[10])(ctx,1,local+12,&ftab[10],fqv[37]); /*remove-duplicates*/
	local[7] = w;
	local[12]= local[2];
	w = fqv[77];
	if (memq(local[12],w)==NIL) goto CON2734;
	local[12]= local[8];
	local[13]= local[10];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,3,local+12); /*list*/
	local[12]= w;
	w = local[5];
	ctx->vsp=local+13;
	local[5] = cons(ctx,local[12],w);
	local[12]= local[5];
	goto CON2733;
CON2734:
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)LENGTH(ctx,1,local+12); /*length*/
	local[12]= w;
	if (makeint(1)==local[12]) goto OR2736;
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(pointer)LENGTH(ctx,1,local+12); /*length*/
	local[12]= w;
	if (makeint(1)==local[12]) goto OR2736;
	goto CON2735;
OR2736:
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)F2462find_colinear_int(ctx,1,local+12); /*find-colinear-int*/
	local[4] = w;
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(pointer)LENGTH(ctx,1,local+12); /*length*/
	local[12]= w;
	if (makeint(1)!=local[12]) goto IF2737;
	local[12]= T;
	local[13]= fqv[78];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,2,local+12); /*format*/
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.car;
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(*ftab[4])(ctx,1,local+12,&ftab[4],fqv[23]); /*fourth*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= makeflt(0.00000000e+00);
	ctx->vsp=local+14;
	w=(*ftab[2])(ctx,2,local+12,&ftab[2],fqv[17]); /*eps=*/
	if (w==NIL) goto CON2740;
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(*ftab[4])(ctx,1,local+12,&ftab[4],fqv[23]); /*fourth*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= makeflt(1.00000000e+00);
	ctx->vsp=local+14;
	w=(*ftab[2])(ctx,2,local+12,&ftab[2],fqv[17]); /*eps=*/
	if (w==NIL) goto CON2740;
	local[12]= local[10];
	local[13]= fqv[20];
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	local[15]= fqv[79];
	local[16]= local[8];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[12]= w;
	local[13]= fqv[56];
	ctx->vsp=local+14;
	w=(pointer)EQ(ctx,2,local+12); /*eql*/
	if (w==NIL) goto CON2740;
	local[12]= local[8];
	local[13]= local[10];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)LIST_STAR(ctx,3,local+12); /*list**/
	local[12]= w;
	w = local[5];
	ctx->vsp=local+13;
	local[5] = cons(ctx,local[12],w);
	local[12]= local[5];
	goto CON2739;
CON2740:
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(*ftab[5])(ctx,1,local+12,&ftab[5],fqv[24]); /*fifth*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= makeflt(0.00000000e+00);
	ctx->vsp=local+14;
	w=(*ftab[2])(ctx,2,local+12,&ftab[2],fqv[17]); /*eps=*/
	if (w==NIL) goto CON2741;
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(*ftab[5])(ctx,1,local+12,&ftab[5],fqv[24]); /*fifth*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= makeflt(1.00000000e+00);
	ctx->vsp=local+14;
	w=(*ftab[2])(ctx,2,local+12,&ftab[2],fqv[17]); /*eps=*/
	if (w==NIL) goto CON2741;
	local[12]= local[8];
	local[13]= fqv[20];
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	local[15]= fqv[79];
	local[16]= local[10];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[12]= w;
	local[13]= fqv[56];
	ctx->vsp=local+14;
	w=(pointer)EQ(ctx,2,local+12); /*eql*/
	if (w==NIL) goto CON2741;
	local[12]= local[8];
	local[13]= local[10];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)LIST_STAR(ctx,3,local+12); /*list**/
	local[12]= w;
	w = local[5];
	ctx->vsp=local+13;
	local[5] = cons(ctx,local[12],w);
	local[12]= local[5];
	goto CON2739;
CON2741:
	local[12]= NIL;
CON2739:
	goto IF2738;
IF2737:
	local[12]= local[8];
	local[13]= local[10];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)LIST_STAR(ctx,3,local+12); /*list**/
	local[12]= w;
	w = local[5];
	ctx->vsp=local+13;
	local[5] = cons(ctx,local[12],w);
	local[12]= local[5];
IF2738:
	goto CON2733;
CON2735:
	local[12]= local[8];
	local[13]= local[10];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)LIST_STAR(ctx,3,local+12); /*list**/
	local[12]= w;
	w = local[5];
	ctx->vsp=local+13;
	local[5] = cons(ctx,local[12],w);
	local[12]= local[5];
	goto CON2733;
CON2742:
	local[12]= NIL;
CON2733:
	goto IF2732;
IF2731:
	local[12]= NIL;
IF2732:
	goto WHL2727;
WHX2728:
	local[12]= NIL;
BLK2729:
	w = NIL;
	goto WHL2722;
WHX2723:
	local[10]= NIL;
BLK2724:
	w = NIL;
	w = local[5];
	local[0]= w;
BLK2716:
	ctx->vsp=local; return(local[0]);}

/*aligned-faces*/
static pointer F2464aligned_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= argv[0];
	local[8]= loadglobal(fqv[73]);
	ctx->vsp=local+9;
	w=(pointer)DERIVEDP(ctx,2,local+7); /*derivedp*/
	if (w==NIL) goto IF2744;
	local[0] = argv[0]->c.obj.iv[9];
	local[7]= local[0];
	goto IF2745;
IF2744:
	local[7]= NIL;
IF2745:
	local[7]= argv[1];
	local[8]= loadglobal(fqv[73]);
	ctx->vsp=local+9;
	w=(pointer)DERIVEDP(ctx,2,local+7); /*derivedp*/
	if (w==NIL) goto IF2746;
	local[1] = argv[1]->c.obj.iv[9];
	local[7]= local[1];
	goto IF2747;
IF2746:
	local[7]= NIL;
IF2747:
	local[7]= NIL;
	local[8]= local[0];
WHL2749:
	if (local[8]==NIL) goto WHX2750;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= NIL;
	local[10]= local[1];
WHL2754:
	if (local[10]==NIL) goto WHX2755;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	local[11]= local[7];
	local[12]= fqv[80];
	local[13]= local[9];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[2] = w;
	if (local[2]==NIL) goto IF2758;
	local[11]= local[7];
	local[12]= local[9];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,2,local+11); /*list*/
	local[11]= w;
	w = local[4];
	ctx->vsp=local+12;
	local[4] = cons(ctx,local[11],w);
	local[11]= local[4];
	goto IF2759;
IF2758:
	local[11]= NIL;
IF2759:
	goto WHL2754;
WHX2755:
	local[11]= NIL;
BLK2756:
	w = NIL;
	goto WHL2749;
WHX2750:
	local[9]= NIL;
BLK2751:
	w = NIL;
	w = local[4];
	local[0]= w;
BLK2743:
	ctx->vsp=local; return(local[0]);}

/*find-equivalent-edge*/
static pointer F2465find_equivalent_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[1];
WHL2762:
	if (local[1]==NIL) goto WHX2763;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= local[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(*ftab[21])(ctx,2,local+2,&ftab[21],fqv[36]); /*eps-v=*/
	if (w==NIL) goto AND2769;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(*ftab[21])(ctx,2,local+2,&ftab[21],fqv[36]); /*eps-v=*/
	if (w==NIL) goto AND2769;
	goto OR2768;
AND2769:
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= local[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(*ftab[21])(ctx,2,local+2,&ftab[21],fqv[36]); /*eps-v=*/
	if (w==NIL) goto AND2770;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(*ftab[21])(ctx,2,local+2,&ftab[21],fqv[36]); /*eps-v=*/
	if (w==NIL) goto AND2770;
	goto OR2768;
AND2770:
	goto IF2766;
OR2768:
	w = local[0];
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK2760;
	goto IF2767;
IF2766:
	local[2]= NIL;
IF2767:
	goto WHL2762;
WHX2763:
	local[2]= NIL;
BLK2764:
	w = NIL;
	local[0]= w;
BLK2760:
	ctx->vsp=local; return(local[0]);}

/*unify-vertex*/
static pointer F2466unify_vertex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= (pointer)get_sym_func(fqv[64]);
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO2772,env,argv,local);
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
	local[1]= fqv[35];
	local[2]= (pointer)get_sym_func(fqv[36]);
	ctx->vsp=local+3;
	w=(*ftab[10])(ctx,3,local+0,&ftab[10],fqv[37]); /*remove-duplicates*/
	local[0]= w;
	local[1]= NIL;
	local[2]= argv[0];
WHL2774:
	if (local[2]==NIL) goto WHX2775;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1]->c.obj.iv[1];
	local[4]= local[0];
	local[5]= fqv[35];
	local[6]= (pointer)get_sym_func(fqv[36]);
	ctx->vsp=local+7;
	w=(*ftab[6])(ctx,4,local+3,&ftab[6],fqv[27]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= local[3];
	w = local[1];
	w->c.obj.iv[1] = local[4];
	local[3]= local[1]->c.obj.iv[2];
	local[4]= local[0];
	local[5]= fqv[35];
	local[6]= (pointer)get_sym_func(fqv[36]);
	ctx->vsp=local+7;
	w=(*ftab[6])(ctx,4,local+3,&ftab[6],fqv[27]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= local[3];
	w = local[1];
	w->c.obj.iv[2] = local[4];
	goto WHL2774;
WHX2775:
	local[3]= NIL;
BLK2776:
	w = NIL;
	local[0]= w;
BLK2771:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2772(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[81];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*merge-edges-if-colinear*/
static pointer F2467merge_edges_if_colinear(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	if (argv[0]==NIL) goto IF2779;
	if (argv[1]==NIL) goto IF2779;
	local[0]= argv[0];
	local[1]= fqv[82];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (w==NIL) goto IF2779;
	local[0]= argv[1]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[36]); /*eps-v=*/
	if (w==NIL) goto CON2782;
	local[0]= argv[1]->c.obj.iv[2];
	local[1]= local[0];
	w = argv[0];
	w->c.obj.iv[1] = local[1];
	goto CON2781;
CON2782:
	local[0]= argv[1]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[36]); /*eps-v=*/
	if (w==NIL) goto CON2783;
	local[0]= argv[1]->c.obj.iv[2];
	local[1]= local[0];
	w = argv[0];
	w->c.obj.iv[2] = local[1];
	goto CON2781;
CON2783:
	local[0]= argv[1]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[36]); /*eps-v=*/
	if (w==NIL) goto CON2784;
	local[0]= argv[1]->c.obj.iv[1];
	local[1]= local[0];
	w = argv[0];
	w->c.obj.iv[1] = local[1];
	goto CON2781;
CON2784:
	local[0]= argv[1]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[36]); /*eps-v=*/
	if (w==NIL) goto CON2785;
	local[0]= argv[1]->c.obj.iv[1];
	local[1]= local[0];
	w = argv[0];
	w->c.obj.iv[2] = local[1];
	goto CON2781;
CON2785:
	w = NIL;
	ctx->vsp=local+0;
	local[0]=w;
	goto BLK2778;
	goto CON2781;
CON2786:
	local[0]= NIL;
CON2781:
	local[0]= NIL;
	local[1]= argv[3];
WHL2788:
	if (local[1]==NIL) goto WHX2789;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[13])(ctx,2,local+2,&ftab[13],fqv[48]); /*delete*/
	goto WHL2788;
WHX2789:
	local[2]= NIL;
BLK2790:
	w = NIL;
	local[0]= argv[1];
	goto IF2780;
IF2779:
	local[0]= NIL;
IF2780:
	w = local[0];
	local[0]= w;
BLK2778:
	ctx->vsp=local; return(local[0]);}

/*merge-contacting-faces*/
static pointer F2468merge_contacting_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[22])(ctx,2,local+0,&ftab[22],fqv[83]); /*assoc*/
	local[0]= w;
	local[1]= argv[1];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(*ftab[22])(ctx,2,local+1,&ftab[22],fqv[83]); /*assoc*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
WHL2794:
	if (local[9]==NIL) goto WHX2795;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= local[8];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.cdr;
	ctx->vsp=local+12;
	w=(pointer)F2465find_equivalent_edge(ctx,2,local+10); /*find-equivalent-edge*/
	local[2] = w;
	if (local[2]==NIL) goto CON2799;
	local[10]= local[2];
	local[11]= fqv[84];
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[3] = w;
	local[10]= local[8];
	local[11]= fqv[84];
	local[12]= argv[1];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[4] = w;
	local[10]= local[3];
	local[11]= fqv[4];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	local[11]= local[4];
	local[12]= fqv[4];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[21])(ctx,2,local+10,&ftab[21],fqv[36]); /*eps-v=*/
	if (w==NIL) goto CON2801;
	local[10]= local[3];
	local[11]= argv[2];
	ctx->vsp=local+12;
	w=(*ftab[22])(ctx,2,local+10,&ftab[22],fqv[83]); /*assoc*/
	local[5] = w;
	local[10]= local[4];
	local[11]= argv[3];
	ctx->vsp=local+12;
	w=(*ftab[22])(ctx,2,local+10,&ftab[22],fqv[83]); /*assoc*/
	local[6] = w;
	local[10]= local[2];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	local[10]= local[8];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	local[10]= local[2];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	local[10]= local[8];
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	local[10]= local[8]->c.obj.iv[1];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.cdr;
	ctx->vsp=local+12;
	w=(pointer)F2457find_connecting_edge(ctx,2,local+10); /*find-connecting-edge*/
	local[10]= w;
	local[11]= local[8]->c.obj.iv[2];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.cdr;
	ctx->vsp=local+13;
	w=(pointer)F2457find_connecting_edge(ctx,2,local+11); /*find-connecting-edge*/
	local[11]= w;
	local[12]= local[2]->c.obj.iv[1];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.cdr;
	ctx->vsp=local+14;
	w=(pointer)F2457find_connecting_edge(ctx,2,local+12); /*find-connecting-edge*/
	local[12]= w;
	local[13]= local[2]->c.obj.iv[2];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.cdr;
	ctx->vsp=local+15;
	w=(pointer)F2457find_connecting_edge(ctx,2,local+13); /*find-connecting-edge*/
	local[13]= w;
	local[14]= local[12];
	local[15]= local[10];
	local[16]= argv[2];
	local[17]= argv[3];
	ctx->vsp=local+18;
	w=(pointer)F2467merge_edges_if_colinear(ctx,4,local+14); /*merge-edges-if-colinear*/
	local[14]= local[12];
	local[15]= local[11];
	local[16]= argv[2];
	local[17]= argv[3];
	ctx->vsp=local+18;
	w=(pointer)F2467merge_edges_if_colinear(ctx,4,local+14); /*merge-edges-if-colinear*/
	local[14]= local[13];
	local[15]= local[10];
	local[16]= argv[2];
	local[17]= argv[3];
	ctx->vsp=local+18;
	w=(pointer)F2467merge_edges_if_colinear(ctx,4,local+14); /*merge-edges-if-colinear*/
	local[14]= local[13];
	local[15]= local[11];
	local[16]= argv[2];
	local[17]= argv[3];
	ctx->vsp=local+18;
	w=(pointer)F2467merge_edges_if_colinear(ctx,4,local+14); /*merge-edges-if-colinear*/
	local[10]= NIL;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.cdr;
WHL2803:
	if (local[11]==NIL) goto WHX2804;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[12];
	local[10] = w;
	local[12]= local[10]->c.obj.iv[3];
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)EQ(ctx,2,local+12); /*eql*/
	if (w!=NIL) goto OR2809;
	local[12]= local[10]->c.obj.iv[4];
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)EQ(ctx,2,local+12); /*eql*/
	if (w!=NIL) goto OR2809;
	goto IF2807;
OR2809:
	local[12]= local[10];
	local[13]= fqv[85];
	local[14]= local[4];
	local[15]= local[3];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,4,local+12); /*send*/
	local[12]= w;
	goto IF2808;
IF2807:
	local[12]= NIL;
IF2808:
	goto WHL2803;
WHX2804:
	local[12]= NIL;
BLK2805:
	w = NIL;
	local[10]= local[5];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.cdr;
	ctx->vsp=local+12;
	w=(pointer)NCONC(ctx,2,local+10); /*nconc*/
	local[10]= local[6];
	local[11]= argv[3];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	argv[3] = w;
	local[10]= local[5];
	w = local[7];
	ctx->vsp=local+11;
	local[7] = cons(ctx,local[10],w);
	local[10]= local[7];
	goto CON2800;
CON2801:
	local[10]= local[8];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	local[10]= local[2];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	local[10]= local[2];
	local[11]= fqv[85];
	local[12]= argv[0];
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	local[10]= w;
	goto CON2800;
CON2810:
	local[10]= NIL;
CON2800:
	goto CON2798;
CON2799:
	local[10]= argv[0];
	local[11]= fqv[20];
	local[12]= local[8];
	local[13]= fqv[86];
	local[14]= makeflt(5.00000000e-01);
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	local[11]= fqv[32];
	ctx->vsp=local+12;
	w=(pointer)EQ(ctx,2,local+10); /*eql*/
	local[10]= w;
	if (w!=NIL) goto CON2798;
CON2811:
	local[10]= local[8];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(*ftab[6])(ctx,2,local+10,&ftab[6],fqv[27]); /*member*/
	if (w!=NIL) goto CON2812;
	local[10]= local[8];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	local[10]= local[0];
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)NCONC(ctx,2,local+10); /*nconc*/
	local[10]= local[8];
	local[11]= fqv[85];
	local[12]= argv[1];
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	local[10]= w;
	goto CON2798;
CON2812:
	local[10]= fqv[87];
	local[11]= argv[0];
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(*ftab[23])(ctx,3,local+10,&ftab[23],fqv[88]); /*warn*/
	local[10]= w;
	goto CON2798;
CON2813:
	local[10]= NIL;
CON2798:
	goto WHL2794;
WHX2795:
	local[10]= NIL;
BLK2796:
	w = NIL;
	local[8]= NIL;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
WHL2815:
	if (local[9]==NIL) goto WHX2816;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= argv[1];
	local[11]= fqv[20];
	local[12]= local[8];
	local[13]= fqv[86];
	local[14]= makeflt(5.00000000e-01);
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	local[11]= fqv[56];
	ctx->vsp=local+12;
	w=(pointer)EQ(ctx,2,local+10); /*eql*/
	if (w==NIL) goto CON2820;
	local[10]= local[8];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	local[10]= local[1];
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)NCONC(ctx,2,local+10); /*nconc*/
	local[10]= local[8];
	local[11]= fqv[85];
	local[12]= argv[0];
	local[13]= argv[1];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	local[10]= local[8];
	local[11]= fqv[84];
	local[12]= argv[1];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	local[11]= argv[2];
	ctx->vsp=local+12;
	w=(*ftab[22])(ctx,2,local+10,&ftab[22],fqv[83]); /*assoc*/
	local[10]= w;
	w = local[7];
	ctx->vsp=local+11;
	local[7] = cons(ctx,local[10],w);
	local[10]= local[7];
	goto CON2819;
CON2820:
	local[10]= NIL;
CON2819:
	goto WHL2815;
WHX2816:
	local[10]= NIL;
BLK2817:
	w = NIL;
	local[8]= (pointer)get_sym_func(fqv[64]);
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.cdr;
	local[11]= (pointer)get_sym_func(fqv[76]);
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(pointer)MAPCAR(ctx,2,local+11); /*mapcar*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)APPLY(ctx,4,local+8); /*apply*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)F2466unify_vertex(ctx,1,local+8); /*unify-vertex*/
	w = argv[3];
	local[0]= w;
BLK2792:
	ctx->vsp=local; return(local[0]);}

/*merge-aligned-faces*/
static pointer F2469merge_aligned_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[22])(ctx,2,local+0,&ftab[22],fqv[83]); /*assoc*/
	local[0]= w;
	local[1]= argv[1];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(*ftab[22])(ctx,2,local+1,&ftab[22],fqv[83]); /*assoc*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	storeglobal(fqv[89],local[0]);
	local[6]= local[1];
	storeglobal(fqv[90],local[6]);
	if (loadglobal(fqv[53])==NIL) goto IF2822;
	local[6]= fqv[91];
	ctx->vsp=local+7;
	w=(*ftab[24])(ctx,1,local+6,&ftab[24],fqv[92]); /*break*/
	local[6]= w;
	goto IF2823;
IF2822:
	local[6]= NIL;
IF2823:
	local[6]= NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
WHL2825:
	if (local[7]==NIL) goto WHX2826;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
	ctx->vsp=local+10;
	w=(pointer)F2465find_equivalent_edge(ctx,2,local+8); /*find-equivalent-edge*/
	local[2] = w;
	if (local[2]==NIL) goto CON2830;
	local[8]= local[6];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[48]); /*delete*/
	local[8]= local[6];
	local[9]= local[6];
	local[10]= fqv[84];
	local[11]= argv[1];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= w;
	local[10]= argv[3];
	ctx->vsp=local+11;
	w=(*ftab[22])(ctx,2,local+9,&ftab[22],fqv[83]); /*assoc*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[48]); /*delete*/
	local[8]= w;
	goto CON2829;
CON2830:
	local[8]= argv[0];
	local[9]= fqv[20];
	local[10]= local[6];
	local[11]= fqv[86];
	local[12]= makeflt(5.00000000e-01);
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	local[9]= fqv[56];
	ctx->vsp=local+10;
	w=(pointer)EQ(ctx,2,local+8); /*eql*/
	if (w==NIL) goto CON2831;
	local[8]= local[6];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[48]); /*delete*/
	local[8]= local[6];
	local[9]= local[6];
	local[10]= fqv[84];
	local[11]= argv[1];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= w;
	local[10]= argv[3];
	ctx->vsp=local+11;
	w=(*ftab[22])(ctx,2,local+9,&ftab[22],fqv[83]); /*assoc*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[48]); /*delete*/
	local[8]= w;
	goto CON2829;
CON2831:
	local[8]= local[6];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[48]); /*delete*/
	local[8]= local[0];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)NCONC(ctx,2,local+8); /*nconc*/
	local[8]= local[6];
	local[9]= fqv[85];
	local[10]= argv[1];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= w;
	goto CON2829;
CON2832:
	local[8]= NIL;
CON2829:
	goto WHL2825;
WHX2826:
	local[8]= NIL;
BLK2827:
	w = NIL;
	local[6]= NIL;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
WHL2834:
	if (local[7]==NIL) goto WHX2835;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= argv[1];
	local[9]= fqv[20];
	local[10]= local[6];
	local[11]= fqv[86];
	local[12]= makeflt(5.00000000e-01);
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	local[9]= fqv[56];
	ctx->vsp=local+10;
	w=(pointer)EQ(ctx,2,local+8); /*eql*/
	if (w==NIL) goto CON2839;
	local[8]= local[6];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[48]); /*delete*/
	local[8]= local[6];
	local[9]= local[6];
	local[10]= fqv[84];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= w;
	local[10]= argv[2];
	ctx->vsp=local+11;
	w=(*ftab[22])(ctx,2,local+9,&ftab[22],fqv[83]); /*assoc*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[48]); /*delete*/
	local[8]= w;
	goto CON2838;
CON2839:
	local[8]= NIL;
CON2838:
	goto WHL2834;
WHX2835:
	local[8]= NIL;
BLK2836:
	w = NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF2840;
	local[6]= fqv[93];
	ctx->vsp=local+7;
	w=(pointer)SIGERROR(ctx,1,local+6); /*error*/
	local[6]= w;
	goto IF2841;
IF2840:
	local[6]= NIL;
IF2841:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	local[4] = local[3];
WHL2842:
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX2843;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[6];
	local[2] = w;
	local[6]= NIL;
	local[7]= NIL;
TAG2847:
	local[7] = local[3];
TAG2848:
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	if (local[6]!=NIL) goto CON2851;
	w = NIL;
	ctx->vsp=local+8;
	local[6]=w;
	goto BLK2846;
	goto CON2850;
CON2851:
	local[8]= local[2];
	local[9]= local[6];
	local[10]= argv[2];
	local[11]= argv[3];
	ctx->vsp=local+12;
	w=(pointer)F2467merge_edges_if_colinear(ctx,4,local+8); /*merge-edges-if-colinear*/
	if (w==NIL) goto CON2852;
	local[8]= local[6];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[48]); /*delete*/
	local[3] = w;
	local[8]= NIL;
	local[9]= argv[2];
WHL2854:
	if (local[9]==NIL) goto WHX2855;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= local[6];
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	goto WHL2854;
WHX2855:
	local[10]= NIL;
BLK2856:
	w = NIL;
	ctx->vsp=local+8;
	goto TAG2847;
	goto CON2850;
CON2852:
	ctx->vsp=local+8;
	goto TAG2848;
	goto CON2850;
CON2858:
	local[8]= NIL;
CON2850:
	w = NIL;
	local[6]= w;
BLK2846:
	goto WHL2842;
WHX2843:
	local[6]= NIL;
BLK2844:
	local[6]= NIL;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
WHL2860:
	if (local[7]==NIL) goto WHX2861;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	local[9]= fqv[84];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[4] = w;
	local[8]= local[4];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(*ftab[22])(ctx,2,local+8,&ftab[22],fqv[83]); /*assoc*/
	local[4] = w;
	if (local[4]==NIL) goto IF2864;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.cdr;
	w = local[5];
	ctx->vsp=local+9;
	local[5] = cons(ctx,local[8],w);
	local[8]= local[5];
	goto IF2865;
IF2864:
	local[8]= local[4];
	local[9]= argv[3];
	ctx->vsp=local+10;
	w=(*ftab[22])(ctx,2,local+8,&ftab[22],fqv[83]); /*assoc*/
	local[4] = w;
	if (local[4]==NIL) goto IF2866;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.cdr;
	w = local[5];
	ctx->vsp=local+9;
	local[5] = cons(ctx,local[8],w);
	local[8]= local[5];
	goto IF2867;
IF2866:
	local[8]= NIL;
IF2867:
IF2865:
	goto WHL2860;
WHX2861:
	local[8]= NIL;
BLK2862:
	w = NIL;
	local[6]= (pointer)get_sym_func(fqv[64]);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,3,local+6); /*apply*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[10])(ctx,1,local+6,&ftab[10],fqv[37]); /*remove-duplicates*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)F2466unify_vertex(ctx,1,local+6); /*unify-vertex*/
	if (loadglobal(fqv[53])==NIL) goto IF2868;
	local[6]= fqv[94];
	ctx->vsp=local+7;
	w=(*ftab[24])(ctx,1,local+6,&ftab[24],fqv[92]); /*break*/
	local[6]= w;
	goto IF2869;
IF2868:
	local[6]= NIL;
IF2869:
	w = local[6];
	w = argv[3];
	local[0]= w;
BLK2821:
	ctx->vsp=local; return(local[0]);}

/*compose-body*/
static pointer F2470compose_body(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[95];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[1];
	local[1]= fqv[95];
	ctx->vsp=local+2;
	w=(*ftab[14])(ctx,2,local+0,&ftab[14],fqv[50]); /*find-method*/
	if (w==NIL) goto IF2871;
	local[0]= argv[1];
	local[1]= fqv[95];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF2872;
IF2871:
	local[0]= NIL;
IF2872:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F2460make_vertex_edge_htab(ctx,1,local+0); /*make-vertex-edge-htab*/
	local[0]= w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F2460make_vertex_edge_htab(ctx,1,local+1); /*make-vertex-edge-htab*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[96];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[1];
	local[4]= fqv[96];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= argv[1];
	local[6]= fqv[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= argv[0];
	local[9]= fqv[97];
	local[10]= argv[1];
	local[11]= makeflt(1.00000000e-02);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= w;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= NIL;
	local[15]= NIL;
	local[16]= NIL;
	local[17]= NIL;
	local[18]= NIL;
	local[19]= NIL;
	local[20]= NIL;
	local[21]= NIL;
	local[22]= NIL;
	local[23]= NIL;
	ctx->vsp=local+24;
	w=(pointer)RUNTIME(ctx,0,local+24); /*unix:runtime*/
	local[16] = w;
	local[24]= local[0];
	ctx->vsp=local+25;
	w=(pointer)F2461copy_add_vertex(ctx,1,local+24); /*copy-add-vertex*/
	local[24]= local[1];
	ctx->vsp=local+25;
	w=(pointer)F2461copy_add_vertex(ctx,1,local+24); /*copy-add-vertex*/
	ctx->vsp=local+24;
	w=(pointer)RUNTIME(ctx,0,local+24); /*unix:runtime*/
	local[17] = w;
	local[24]= local[4];
	local[25]= local[0];
	ctx->vsp=local+26;
	w=(pointer)F2459initial_intersection_list(ctx,2,local+24); /*initial-intersection-list*/
	local[6] = w;
	local[24]= local[5];
	local[25]= local[1];
	ctx->vsp=local+26;
	w=(pointer)F2459initial_intersection_list(ctx,2,local+24); /*initial-intersection-list*/
	local[7] = w;
	ctx->vsp=local+24;
	w=(pointer)RUNTIME(ctx,0,local+24); /*unix:runtime*/
	local[18] = w;
	local[24]= local[6];
	local[25]= local[3];
	local[26]= local[8];
	ctx->vsp=local+27;
	w=(pointer)F2450insert_intersections(ctx,3,local+24); /*insert-intersections*/
	local[24]= local[7];
	local[25]= local[2];
	local[26]= local[8];
	ctx->vsp=local+27;
	w=(pointer)F2450insert_intersections(ctx,3,local+24); /*insert-intersections*/
	ctx->vsp=local+24;
	w=(pointer)RUNTIME(ctx,0,local+24); /*unix:runtime*/
	local[19] = w;
	storeglobal(fqv[98],local[6]);
	local[24]= local[7];
	storeglobal(fqv[99],local[24]);
	local[24]= local[6];
	local[25]= argv[1];
	local[26]= argv[2];
	ctx->vsp=local+27;
	w=(pointer)F2451make_edge_segments(ctx,3,local+24); /*make-edge-segments*/
	local[9] = w;
	local[24]= local[7];
	local[25]= argv[0];
	local[26]= argv[2];
	ctx->vsp=local+27;
	w=(pointer)F2451make_edge_segments(ctx,3,local+24); /*make-edge-segments*/
	local[10] = w;
	ctx->vsp=local+24;
	w=(pointer)RUNTIME(ctx,0,local+24); /*unix:runtime*/
	local[20] = w;
	local[24]= local[9];
	ctx->vsp=local+25;
	w=(pointer)F2452intersecting_segments(ctx,1,local+24); /*intersecting-segments*/
	local[24]= w;
	ctx->vsp=local+25;
	w=(pointer)F2453sort_edges_by_face(ctx,1,local+24); /*sort-edges-by-face*/
	local[6] = w;
	local[24]= local[10];
	ctx->vsp=local+25;
	w=(pointer)F2452intersecting_segments(ctx,1,local+24); /*intersecting-segments*/
	local[24]= w;
	ctx->vsp=local+25;
	w=(pointer)F2453sort_edges_by_face(ctx,1,local+24); /*sort-edges-by-face*/
	local[7] = w;
	ctx->vsp=local+24;
	w=(pointer)RUNTIME(ctx,0,local+24); /*unix:runtime*/
	local[21] = w;
	local[24]= local[9];
	ctx->vsp=local+25;
	w=(pointer)F2453sort_edges_by_face(ctx,1,local+24); /*sort-edges-by-face*/
	local[9] = w;
	local[24]= local[10];
	ctx->vsp=local+25;
	w=(pointer)F2453sort_edges_by_face(ctx,1,local+24); /*sort-edges-by-face*/
	local[10] = w;
	ctx->vsp=local+24;
	w=(pointer)RUNTIME(ctx,0,local+24); /*unix:runtime*/
	local[22] = w;
	local[24]= local[6];
	local[25]= local[10];
	local[26]= T;
	local[27]= argv[2];
	ctx->vsp=local+28;
	w=(pointer)F2454make_crossing_edges(ctx,4,local+24); /*make-crossing-edges*/
	local[12] = w;
	local[24]= local[7];
	local[25]= local[9];
	local[26]= NIL;
	local[27]= argv[2];
	ctx->vsp=local+28;
	w=(pointer)F2454make_crossing_edges(ctx,4,local+24); /*make-crossing-edges*/
	local[13] = w;
	storeglobal(fqv[100],local[9]);
	local[24]= local[10];
	storeglobal(fqv[101],local[24]);
	storeglobal(fqv[102],local[12]);
	local[24]= local[13];
	storeglobal(fqv[103],local[24]);
	if (loadglobal(fqv[53])==NIL) goto IF2873;
	local[24]= T;
	local[25]= fqv[104];
	ctx->vsp=local+26;
	w=(pointer)XFORMAT(ctx,2,local+24); /*format*/
	local[24]= fqv[105];
	ctx->vsp=local+25;
	w=(*ftab[24])(ctx,1,local+24,&ftab[24],fqv[92]); /*break*/
	local[24]= w;
	goto IF2874;
IF2873:
	local[24]= NIL;
IF2874:
	local[24]= local[9];
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25]= (w)->c.cons.car;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	ctx->vsp=local+27;
	w=(pointer)F2456merge_segments(ctx,3,local+24); /*merge-segments*/
	local[9] = w;
	local[24]= local[10];
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25]= (w)->c.cons.car;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	ctx->vsp=local+27;
	w=(pointer)F2456merge_segments(ctx,3,local+24); /*merge-segments*/
	local[10] = w;
	storeglobal(fqv[100],local[9]);
	local[24]= local[10];
	storeglobal(fqv[101],local[24]);
	local[24]= argv[1];
	local[25]= loadglobal(fqv[73]);
	ctx->vsp=local+26;
	w=(pointer)DERIVEDP(ctx,2,local+24); /*derivedp*/
	if (w==NIL) goto IF2875;
	local[24]= argv[0];
	local[25]= argv[1];
	ctx->vsp=local+26;
	w=(pointer)F2463contacting_faces(ctx,2,local+24); /*contacting-faces*/
	local[14] = w;
	local[24]= local[14];
	goto IF2876;
IF2875:
	local[24]= NIL;
IF2876:
	if (local[14]==NIL) goto IF2877;
	local[24]= loadglobal(fqv[106]);
	local[25]= fqv[107];
	local[26]= local[14];
	ctx->vsp=local+27;
	w=(pointer)LENGTH(ctx,1,local+26); /*length*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)XFORMAT(ctx,3,local+24); /*format*/
	if (loadglobal(fqv[53])==NIL) goto IF2879;
	local[24]= fqv[108];
	ctx->vsp=local+25;
	w=(*ftab[24])(ctx,1,local+24,&ftab[24],fqv[92]); /*break*/
	local[24]= w;
	goto IF2880;
IF2879:
	local[24]= NIL;
IF2880:
	local[24]= NIL;
	local[25]= local[14];
WHL2882:
	if (local[25]==NIL) goto WHX2883;
	w=local[25];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	w=local[25];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25] = (w)->c.cons.cdr;
	w = local[26];
	local[24] = w;
	w=local[24];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	w=local[24];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[27]= (w)->c.cons.car;
	local[28]= local[9];
	local[29]= local[10];
	ctx->vsp=local+30;
	w=(pointer)F2468merge_contacting_faces(ctx,4,local+26); /*merge-contacting-faces*/
	local[10] = w;
	goto WHL2882;
WHX2883:
	local[26]= NIL;
BLK2884:
	w = NIL;
	local[24]= w;
	goto IF2878;
IF2877:
	local[24]= NIL;
IF2878:
	local[24]= (pointer)get_sym_func(fqv[76]);
	local[25]= local[9];
	ctx->vsp=local+26;
	w=(*ftab[25])(ctx,2,local+24,&ftab[25],fqv[109]); /*delete-if-not*/
	local[9] = w;
	local[24]= (pointer)get_sym_func(fqv[76]);
	local[25]= local[10];
	ctx->vsp=local+26;
	w=(*ftab[25])(ctx,2,local+24,&ftab[25],fqv[109]); /*delete-if-not*/
	local[10] = w;
	storeglobal(fqv[100],local[9]);
	local[24]= local[10];
	storeglobal(fqv[101],local[24]);
	local[24]= (pointer)get_sym_func(fqv[75]);
	local[25]= local[9];
	ctx->vsp=local+26;
	w=(pointer)MAPCAR(ctx,2,local+24); /*mapcar*/
	local[24]= w;
	local[25]= (pointer)get_sym_func(fqv[75]);
	local[26]= local[10];
	ctx->vsp=local+27;
	w=(pointer)MAPCAR(ctx,2,local+25); /*mapcar*/
	local[25]= w;
	ctx->vsp=local+26;
	w=(pointer)F2464aligned_faces(ctx,2,local+24); /*aligned-faces*/
	local[15] = w;
	if (local[15]==NIL) goto IF2886;
	local[24]= loadglobal(fqv[106]);
	local[25]= fqv[110];
	local[26]= local[15];
	ctx->vsp=local+27;
	w=(pointer)LENGTH(ctx,1,local+26); /*length*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)XFORMAT(ctx,3,local+24); /*format*/
	local[24]= NIL;
	local[25]= local[15];
WHL2889:
	if (local[25]==NIL) goto WHX2890;
	w=local[25];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	w=local[25];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25] = (w)->c.cons.cdr;
	w = local[26];
	local[24] = w;
	w=local[24];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	w=local[24];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[27]= (w)->c.cons.car;
	local[28]= local[9];
	local[29]= local[10];
	ctx->vsp=local+30;
	w=(pointer)F2469merge_aligned_faces(ctx,4,local+26); /*merge-aligned-faces*/
	goto WHL2889;
WHX2890:
	local[26]= NIL;
BLK2891:
	w = NIL;
	local[24]= w;
	goto IF2887;
IF2886:
	local[24]= NIL;
IF2887:
	local[24]= NIL;
	storeglobal(fqv[111],local[24]);
	if (loadglobal(fqv[53])==NIL) goto IF2893;
	local[24]= T;
	local[25]= fqv[112];
	ctx->vsp=local+26;
	w=(pointer)XFORMAT(ctx,2,local+24); /*format*/
	local[24]= fqv[113];
	ctx->vsp=local+25;
	w=(*ftab[24])(ctx,1,local+24,&ftab[24],fqv[92]); /*break*/
	local[24]= w;
	goto IF2894;
IF2893:
	local[24]= NIL;
IF2894:
	local[24]= NIL;
	local[25]= local[9];
WHL2896:
	if (local[25]==NIL) goto WHX2897;
	w=local[25];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	w=local[25];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25] = (w)->c.cons.cdr;
	w = local[26];
	local[24] = w;
	if (loadglobal(fqv[53])==NIL) goto IF2900;
	local[26]= T;
	local[27]= fqv[114];
	local[28]= loadglobal(fqv[111]);
	ctx->vsp=local+29;
	w=(pointer)LENGTH(ctx,1,local+28); /*length*/
	local[28]= w;
	ctx->vsp=local+29;
	w=(pointer)XFORMAT(ctx,3,local+26); /*format*/
	local[26]= w;
	goto IF2901;
IF2900:
	local[26]= NIL;
IF2901:
	local[26]= local[24];
	ctx->vsp=local+27;
	w=(pointer)F2458construct_faces(ctx,1,local+26); /*construct-faces*/
	local[26]= w;
	w = loadglobal(fqv[111]);
	ctx->vsp=local+27;
	local[26]= cons(ctx,local[26],w);
	storeglobal(fqv[111],local[26]);
	goto WHL2896;
WHX2897:
	local[26]= NIL;
BLK2898:
	w = NIL;
	local[24]= NIL;
	local[25]= local[10];
WHL2903:
	if (local[25]==NIL) goto WHX2904;
	w=local[25];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	w=local[25];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25] = (w)->c.cons.cdr;
	w = local[26];
	local[24] = w;
	if (loadglobal(fqv[53])==NIL) goto IF2907;
	local[26]= T;
	local[27]= fqv[115];
	local[28]= loadglobal(fqv[111]);
	ctx->vsp=local+29;
	w=(pointer)LENGTH(ctx,1,local+28); /*length*/
	local[28]= w;
	ctx->vsp=local+29;
	w=(pointer)XFORMAT(ctx,3,local+26); /*format*/
	local[26]= w;
	goto IF2908;
IF2907:
	local[26]= NIL;
IF2908:
	local[26]= local[24];
	ctx->vsp=local+27;
	w=(pointer)F2458construct_faces(ctx,1,local+26); /*construct-faces*/
	local[26]= w;
	w = loadglobal(fqv[111]);
	ctx->vsp=local+27;
	local[26]= cons(ctx,local[26],w);
	storeglobal(fqv[111],local[26]);
	goto WHL2903;
WHX2904:
	local[26]= NIL;
BLK2905:
	w = NIL;
	local[24]= loadglobal(fqv[111]);
	ctx->vsp=local+25;
	w=(pointer)NREVERSE(ctx,1,local+24); /*nreverse*/
	local[24]= w;
	ctx->vsp=local+25;
	w=(*ftab[26])(ctx,1,local+24,&ftab[26],fqv[116]); /*flatten*/
	local[24]= w;
	storeglobal(fqv[111],w);
	ctx->vsp=local+24;
	w=(pointer)RUNTIME(ctx,0,local+24); /*unix:runtime*/
	local[23] = w;
	if (loadglobal(fqv[53])==NIL) goto IF2909;
	local[24]= T;
	local[25]= fqv[117];
	local[26]= makeflt(1.67000000e-02);
	local[27]= local[17];
	local[28]= local[16];
	ctx->vsp=local+29;
	w=(pointer)MINUS(ctx,2,local+27); /*-*/
	local[27]= w;
	ctx->vsp=local+28;
	w=(pointer)TIMES(ctx,2,local+26); /***/
	local[26]= w;
	local[27]= makeflt(1.67000000e-02);
	local[28]= local[18];
	local[29]= local[17];
	ctx->vsp=local+30;
	w=(pointer)MINUS(ctx,2,local+28); /*-*/
	local[28]= w;
	ctx->vsp=local+29;
	w=(pointer)TIMES(ctx,2,local+27); /***/
	local[27]= w;
	local[28]= makeflt(1.67000000e-02);
	local[29]= local[19];
	local[30]= local[18];
	ctx->vsp=local+31;
	w=(pointer)MINUS(ctx,2,local+29); /*-*/
	local[29]= w;
	ctx->vsp=local+30;
	w=(pointer)TIMES(ctx,2,local+28); /***/
	local[28]= w;
	local[29]= makeflt(1.67000000e-02);
	local[30]= local[20];
	local[31]= local[19];
	ctx->vsp=local+32;
	w=(pointer)MINUS(ctx,2,local+30); /*-*/
	local[30]= w;
	ctx->vsp=local+31;
	w=(pointer)TIMES(ctx,2,local+29); /***/
	local[29]= w;
	local[30]= makeflt(1.67000000e-02);
	local[31]= local[21];
	local[32]= local[20];
	ctx->vsp=local+33;
	w=(pointer)MINUS(ctx,2,local+31); /*-*/
	local[31]= w;
	ctx->vsp=local+32;
	w=(pointer)TIMES(ctx,2,local+30); /***/
	local[30]= w;
	local[31]= makeflt(1.67000000e-02);
	local[32]= local[22];
	local[33]= local[21];
	ctx->vsp=local+34;
	w=(pointer)MINUS(ctx,2,local+32); /*-*/
	local[32]= w;
	ctx->vsp=local+33;
	w=(pointer)TIMES(ctx,2,local+31); /***/
	local[31]= w;
	local[32]= makeflt(1.67000000e-02);
	local[33]= local[23];
	local[34]= local[22];
	ctx->vsp=local+35;
	w=(pointer)MINUS(ctx,2,local+33); /*-*/
	local[33]= w;
	ctx->vsp=local+34;
	w=(pointer)TIMES(ctx,2,local+32); /***/
	local[32]= w;
	ctx->vsp=local+33;
	w=(pointer)XFORMAT(ctx,9,local+24); /*format*/
	local[24]= w;
	goto IF2910;
IF2909:
	local[24]= NIL;
IF2910:
	local[24]= loadglobal(fqv[118]);
	ctx->vsp=local+25;
	w=(pointer)INSTANTIATE(ctx,1,local+24); /*instantiate*/
	local[24]= w;
	local[25]= local[24];
	local[26]= fqv[9];
	local[27]= fqv[96];
	local[28]= loadglobal(fqv[111]);
	ctx->vsp=local+29;
	w=(pointer)SEND(ctx,4,local+25); /*send*/
	w = local[24];
	local[0]= w;
BLK2870:
	ctx->vsp=local; return(local[0]);}

/*set-original-face*/
static pointer F2471set_original_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[119];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[120];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO2913,env,argv,local);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[0];
	local[7]= fqv[96];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
WHL2915:
	if (local[6]==NIL) goto WHX2916;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[5];
	local[8]= fqv[51];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[3] = w;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(*ftab[27])(ctx,1,local+7,&ftab[27],fqv[121]); /*primitive-body-p*/
	if (w==NIL) goto CON2920;
	local[7]= local[3];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(*ftab[28])(ctx,2,local+7,&ftab[28],fqv[122]); /*position*/
	local[4] = w;
	if (local[4]==NIL) goto IF2921;
	local[7]= local[5];
	local[8]= fqv[49];
	local[9]= local[5];
	local[10]= fqv[49];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	local[10]= local[3];
	local[11]= fqv[96];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[28])(ctx,2,local+9,&ftab[28],fqv[122]); /*position*/
	local[9]= w;
	local[10]= local[4];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)NTH(ctx,2,local+10); /*nth*/
	local[10]= w;
	local[11]= fqv[96];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)NTH(ctx,2,local+9); /*nth*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	goto IF2922;
IF2921:
	local[7]= NIL;
IF2922:
	goto CON2919;
CON2920:
	local[7]= fqv[123];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[23])(ctx,2,local+7,&ftab[23],fqv[88]); /*warn*/
	local[7]= w;
	goto CON2919;
CON2923:
	local[7]= NIL;
CON2919:
	local[7]= local[5];
	local[8]= fqv[51];
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	goto WHL2915;
WHX2916:
	local[7]= NIL;
BLK2917:
	w = NIL;
	local[5]= NIL;
	local[6]= local[1];
WHL2925:
	if (local[6]==NIL) goto WHX2926;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[5];
	local[8]= T;
	local[9]= fqv[124];
	ctx->vsp=local+10;
	w=(pointer)PUTPROP(ctx,3,local+7); /*putprop*/
	local[7]= argv[0];
	local[8]= fqv[125];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	goto WHL2925;
WHX2926:
	local[7]= NIL;
BLK2927:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK2912:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2913(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(pointer)GETPROP(ctx,2,local+0); /*get*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*body+*/
static pointer F2472body_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST2930:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= local[1];
	local[3]= fqv[126];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	local[3]= NIL;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
WHL2932:
	if (local[4]==NIL) goto WHX2933;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[1];
	local[6]= local[3];
	local[7]= fqv[32];
	ctx->vsp=local+8;
	w=(pointer)F2470compose_body(ctx,3,local+5); /*compose-body*/
	local[1] = w;
	local[5]= local[3];
	local[6]= fqv[126];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	goto WHL2932;
WHX2933:
	local[5]= NIL;
BLK2934:
	w = NIL;
	local[3]= local[1];
	local[4]= fqv[119];
	local[5]= fqv[127];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)NREVERSE(ctx,1,local+6); /*nreverse*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F2471set_original_face(ctx,1,local+3); /*set-original-face*/
	w = local[1];
	local[0]= w;
BLK2929:
	ctx->vsp=local; return(local[0]);}

/*body**/
static pointer F2473body_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST2937:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[1];
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[126];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
WHL2939:
	if (local[0]==NIL) goto WHX2940;
	local[3]= local[1];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= fqv[56];
	ctx->vsp=local+6;
	w=(pointer)F2470compose_body(ctx,3,local+3); /*compose-body*/
	local[1] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[3];
	local[3]= w;
	local[4]= fqv[126];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	w = local[2];
	ctx->vsp=local+4;
	local[2] = cons(ctx,local[3],w);
	goto WHL2939;
WHX2940:
	local[3]= NIL;
BLK2941:
	local[3]= local[1];
	local[4]= fqv[119];
	local[5]= fqv[128];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)NREVERSE(ctx,1,local+6); /*nreverse*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F2471set_original_face(ctx,1,local+3); /*set-original-face*/
	w = local[1];
	local[0]= w;
BLK2936:
	ctx->vsp=local; return(local[0]);}

/*body-*/
static pointer F2474body_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST2944:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= argv[0];
	local[2]= NIL;
	local[3]= argv[0];
	local[4]= fqv[129];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	ctx->vsp=local+3;
	w = makeclosure(codevec,quotevec,UWP2945,env,argv,local);
	local[3]=(pointer)(ctx->protfp); local[4]=w;
	ctx->protfp=(struct protectframe *)(local+3);
WHL2946:
	if (local[0]==NIL) goto WHX2947;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= fqv[126];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[1];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	local[7]= fqv[32];
	ctx->vsp=local+8;
	w=(pointer)F2470compose_body(ctx,3,local+5); /*compose-body*/
	local[1] = w;
	local[5]= T;
	local[6]= local[5];
	*(ovafptr(local[1],fqv[130])) = local[6];
	goto WHL2946;
WHX2947:
	local[5]= NIL;
BLK2948:
	w = local[5];
	ctx->vsp=local+5;
	UWP2945(ctx,0,local+5,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[3]= local[1];
	local[4]= fqv[129];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= local[1];
	local[4]= fqv[9];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= local[1];
	local[4]= fqv[119];
	local[5]= fqv[131];
	local[6]= argv[0];
	local[7]= fqv[126];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)NREVERSE(ctx,1,local+7); /*nreverse*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F2471set_original_face(ctx,1,local+3); /*set-original-face*/
	w = local[1];
	local[0]= w;
BLK2943:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP2945(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= fqv[129];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*body-interference*/
static pointer F2475body_interference(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST2951:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= local[0];
	local[2]= fqv[95];
	ctx->vsp=local+3;
	w=(*ftab[17])(ctx,2,local+1,&ftab[17],fqv[66]); /*send-all*/
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
WHL2952:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX2953;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[1] = w;
	local[4]= NIL;
	local[5]= local[0];
WHL2957:
	if (local[5]==NIL) goto WHX2958;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[1];
	local[7]= fqv[132];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	if (w==NIL) goto IF2961;
	local[6]= local[4];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	w = local[3];
	ctx->vsp=local+7;
	local[3] = cons(ctx,local[6],w);
	local[6]= local[3];
	goto IF2962;
IF2961:
	local[6]= NIL;
IF2962:
	goto WHL2957;
WHX2958:
	local[6]= NIL;
BLK2959:
	w = NIL;
	goto WHL2952;
WHX2953:
	local[4]= NIL;
BLK2954:
	w = local[3];
	local[0]= w;
BLK2950:
	ctx->vsp=local; return(local[0]);}

/*:box*/
static pointer M2963plane_box(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[133]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[9];
	local[3]= makeflt(-1.00000000e+30);
	local[4]= makeflt(-1.00000000e+30);
	local[5]= makeflt(-1.00000000e+30);
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[3]= w;
	local[4]= makeflt(1.00000000e+30);
	local[5]= makeflt(1.00000000e+30);
	local[6]= makeflt(1.00000000e+30);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK2964:
	ctx->vsp=local; return(local[0]);}

/*:edges*/
static pointer M2966semi_space_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = NIL;
	local[0]= w;
BLK2967:
	ctx->vsp=local; return(local[0]);}

/*:faces*/
static pointer M2968semi_space_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
BLK2969:
	ctx->vsp=local; return(local[0]);}

/*:box*/
static pointer M2970semi_space_box(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2973;}
	local[0]= makeflt(0.00000000e+00);
ENT2973:
ENT2972:
	if (n>3) maerror();
	local[1]= loadglobal(fqv[133]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[134];
	local[4]= makeflt(-1.00000000e+30);
	local[5]= makeflt(-1.00000000e+30);
	local[6]= makeflt(-1.00000000e+30);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	local[5]= makeflt(1.00000000e+30);
	local[6]= makeflt(1.00000000e+30);
	local[7]= makeflt(1.00000000e+30);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK2971:
	ctx->vsp=local; return(local[0]);}

/*:insidep*/
static pointer M2975semi_space_insidep(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[135];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= makeflt(0.00000000e+00);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF2977;
	local[0]= fqv[56];
	goto IF2978;
IF2977:
	local[0]= fqv[32];
IF2978:
	w = local[0];
	local[0]= w;
BLK2976:
	ctx->vsp=local; return(local[0]);}

/*:primitive-face*/
static pointer M2979semi_space_primitive_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2982;}
	local[0]= NIL;
ENT2982:
ENT2981:
	if (n>3) maerror();
	w = argv[0];
	local[0]= w;
BLK2980:
	ctx->vsp=local; return(local[0]);}

/*:body*/
static pointer M2983semi_space_body(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2986;}
	local[0]= NIL;
ENT2986:
ENT2985:
	if (n>3) maerror();
	w = NIL;
	local[0]= w;
BLK2984:
	ctx->vsp=local; return(local[0]);}

/*:id*/
static pointer M2987semi_space_id(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2990;}
	local[0]= NIL;
ENT2990:
ENT2989:
	if (n>3) maerror();
	w = NIL;
	local[0]= w;
BLK2988:
	ctx->vsp=local; return(local[0]);}

/*:on-edge*/
static pointer M2991semi_space_on_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT2994;}
	local[0]= NIL;
ENT2994:
ENT2993:
	if (n>4) maerror();
	w = NIL;
	local[0]= w;
BLK2992:
	ctx->vsp=local; return(local[0]);}

/*body/*/
static pointer F2476body_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[136]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[9];
	local[3]= *(ovafptr(argv[1],fqv[31]));
	local[4]= *(ovafptr(argv[1],fqv[137]));
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[56];
	ctx->vsp=local+4;
	w=(pointer)F2470compose_body(ctx,3,local+1); /*compose-body*/
	local[0]= w;
BLK2995:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___compose(ctx,n,argv,env)
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
	local[0]= fqv[138];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF2997;
	local[0]= fqv[139];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[140],w);
	goto IF2998;
IF2997:
	local[0]= fqv[141];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF2998:
	local[0]= fqv[142];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[143];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[144];
	local[1]= fqv[145];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF2999;
	local[0]= fqv[144];
	local[1]= fqv[145];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[144];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3001;
	local[0]= fqv[144];
	local[1]= fqv[146];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3002;
IF3001:
	local[0]= NIL;
IF3002:
	local[0]= fqv[144];
	goto IF3000;
IF2999:
	local[0]= NIL;
IF3000:
	local[0]= fqv[147];
	local[1]= fqv[145];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3003;
	local[0]= fqv[147];
	local[1]= fqv[145];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[147];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3005;
	local[0]= fqv[147];
	local[1]= fqv[146];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3006;
IF3005:
	local[0]= NIL;
IF3006:
	local[0]= fqv[147];
	goto IF3004;
IF3003:
	local[0]= NIL;
IF3004:
	local[0]= fqv[111];
	local[1]= fqv[145];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3007;
	local[0]= fqv[111];
	local[1]= fqv[145];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[111];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3009;
	local[0]= fqv[111];
	local[1]= fqv[146];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3010;
IF3009:
	local[0]= NIL;
IF3010:
	local[0]= fqv[111];
	goto IF3008;
IF3007:
	local[0]= NIL;
IF3008:
	local[0]= fqv[148];
	local[1]= fqv[145];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3011;
	local[0]= fqv[148];
	local[1]= fqv[145];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[148];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3013;
	local[0]= fqv[148];
	local[1]= fqv[146];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3014;
IF3013:
	local[0]= NIL;
IF3014:
	local[0]= fqv[148];
	goto IF3012;
IF3011:
	local[0]= NIL;
IF3012:
	local[0]= fqv[8];
	local[1]= fqv[145];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3015;
	local[0]= fqv[8];
	local[1]= fqv[145];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[8];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3017;
	local[0]= fqv[8];
	local[1]= fqv[146];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3018;
IF3017:
	local[0]= NIL;
IF3018:
	local[0]= fqv[8];
	goto IF3016;
IF3015:
	local[0]= NIL;
IF3016:
	local[0]= fqv[45];
	local[1]= fqv[145];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3019;
	local[0]= fqv[45];
	local[1]= fqv[145];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[45];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3021;
	local[0]= fqv[45];
	local[1]= fqv[146];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3022;
IF3021:
	local[0]= NIL;
IF3022:
	local[0]= fqv[45];
	goto IF3020;
IF3019:
	local[0]= NIL;
IF3020:
	local[0]= fqv[57];
	local[1]= fqv[145];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3023;
	local[0]= fqv[57];
	local[1]= fqv[145];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[57];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3025;
	local[0]= fqv[57];
	local[1]= fqv[146];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3026;
IF3025:
	local[0]= NIL;
IF3026:
	local[0]= fqv[57];
	goto IF3024;
IF3023:
	local[0]= NIL;
IF3024:
	local[0]= fqv[118];
	local[1]= fqv[145];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3027;
	local[0]= fqv[118];
	local[1]= fqv[145];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[118];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3029;
	local[0]= fqv[118];
	local[1]= fqv[146];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3030;
IF3029:
	local[0]= NIL;
IF3030:
	local[0]= fqv[118];
	goto IF3028;
IF3027:
	local[0]= NIL;
IF3028:
	ctx->vsp=local+0;
	compfun(ctx,fqv[149],module,F2448intersecting_edges,fqv[150]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[151],module,F2449cut_body,fqv[152]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[153],module,F2450insert_intersections,fqv[154]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[155],module,F2451make_edge_segments,fqv[156]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[157],module,F2452intersecting_segments,fqv[158]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[159],module,F2453sort_edges_by_face,fqv[160]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[161],module,F2454make_crossing_edges,fqv[162]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[163],module,F2455add_alist,fqv[164]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[165],module,F2456merge_segments,fqv[166]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[167],module,F2457find_connecting_edge,fqv[168]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[169],module,F2458construct_faces,fqv[170]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[171],module,F2459initial_intersection_list,fqv[172]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[173],module,F2460make_vertex_edge_htab,fqv[174]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[175],module,F2461copy_add_vertex,fqv[176]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[177],module,F2462find_colinear_int,fqv[178]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[179],module,F2463contacting_faces,fqv[180]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[181],module,F2464aligned_faces,fqv[182]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[183],module,F2465find_equivalent_edge,fqv[184]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[185],module,F2466unify_vertex,fqv[186]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[187],module,F2467merge_edges_if_colinear,fqv[188]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[189],module,F2468merge_contacting_faces,fqv[190]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[191],module,F2469merge_aligned_faces,fqv[192]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[193],module,F2470compose_body,fqv[194]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[195],module,F2471set_original_face,fqv[196]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[197],module,F2472body_,fqv[198]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[199],module,F2473body_,fqv[200]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[201],module,F2474body_,fqv[202]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[203],module,F2475body_interference,fqv[204]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2963plane_box,fqv[14],fqv[205],fqv[206]);
	local[0]= fqv[136];
	local[1]= fqv[146];
	local[2]= fqv[136];
	local[3]= fqv[207];
	local[4]= loadglobal(fqv[205]);
	local[5]= fqv[208];
	local[6]= fqv[209];
	local[7]= fqv[210];
	local[8]= NIL;
	local[9]= fqv[211];
	local[10]= NIL;
	local[11]= fqv[68];
	local[12]= makeint(-1);
	local[13]= fqv[212];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[29])(ctx,13,local+2,&ftab[29],fqv[213]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2966semi_space_edges,fqv[1],fqv[136],fqv[214]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2968semi_space_faces,fqv[96],fqv[136],fqv[215]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2970semi_space_box,fqv[14],fqv[136],fqv[216]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2975semi_space_insidep,fqv[20],fqv[136],fqv[217]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2979semi_space_primitive_face,fqv[49],fqv[136],fqv[218]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2983semi_space_body,fqv[51],fqv[136],fqv[219]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2987semi_space_id,fqv[52],fqv[136],fqv[220]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2991semi_space_on_edge,fqv[38],fqv[136],fqv[221]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[222],module,F2476body_,fqv[223]);
	local[0]= fqv[224];
	local[1]= fqv[225];
	ctx->vsp=local+2;
	w=(*ftab[30])(ctx,2,local+0,&ftab[30],fqv[226]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<31; i++) ftab[i]=fcallx;
}
