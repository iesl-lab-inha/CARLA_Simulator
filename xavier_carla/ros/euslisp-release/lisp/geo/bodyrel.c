/* ./bodyrel.c :  entry=bodyrel */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "bodyrel.h"
#pragma init (register_bodyrel)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___bodyrel();
extern pointer build_quote_vector();
static int register_bodyrel()
  { add_module_initializer("___bodyrel", ___bodyrel);}

static pointer F4530coplanar_fe_intersection();
static pointer F4531find_next_segment();
static pointer F4532find_loop();
static pointer F4533punch_hole();
static pointer F4534construct_polygon();
static pointer F4535remove_non_overlapping_border();
static pointer F4536coplanar_ff_intersection();
static pointer F4537face_();
static pointer F4538face_();
static pointer F4539non_coplanar_fe_relation();
static pointer F4540ff_relation();
static pointer F4541bb_relation();
static pointer F4542make_lines();
static pointer F4543copy_face();

/*coplanar-fe-intersection*/
static pointer F4530coplanar_fe_intersection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4547;}
	local[0]= fqv[0];
ENT4547:
	if (n>=4) { local[1]=(argv[3]); goto ENT4546;}
	local[1]= loadglobal(fqv[1]);
ENT4546:
ENT4545:
	if (n>4) maerror();
	local[2]= argv[1]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)COPYSEQ(ctx,1,local+2); /*copy-seq*/
	local[2]= w;
	local[3]= argv[1]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)COPYSEQ(ctx,1,local+3); /*copy-seq*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(pointer)SQRT(ctx,1,local+10); /*sqrt*/
	local[10]= w;
	local[11]= NIL;
	local[12]= argv[0];
	local[13]= fqv[2];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[12]= w;
WHL4549:
	if (local[12]==NIL) goto WHX4550;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12] = (w)->c.cons.cdr;
	w = local[13];
	local[11] = w;
	local[13]= local[11];
	local[14]= fqv[3];
	local[15]= argv[1];
	local[16]= local[10];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,4,local+13); /*send*/
	local[5] = w;
	w = local[5];
	if (!iscons(w)) goto IF4553;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	local[14]= fqv[4];
	ctx->vsp=local+15;
	w=(pointer)EQ(ctx,2,local+13); /*eql*/
	if (w==NIL) goto IF4555;
	local[13]= local[11];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	w = local[4];
	ctx->vsp=local+14;
	local[4] = cons(ctx,local[13],w);
	local[13]= local[4];
	goto IF4556;
IF4555:
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	w = local[4];
	ctx->vsp=local+14;
	local[4] = cons(ctx,local[13],w);
	local[13]= local[4];
IF4556:
	goto IF4554;
IF4553:
	local[13]= NIL;
IF4554:
	goto WHL4549;
WHX4550:
	local[13]= NIL;
BLK4551:
	w = NIL;
	if (local[4]!=NIL) goto IF4557;
	local[11]= argv[0];
	local[12]= fqv[5];
	local[13]= argv[1]->c.obj.iv[1];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[5] = w;
	local[11]= NIL;
	local[12]= local[5];
	if (local[0]!=local[12]) goto IF4559;
	local[12]= NIL;
	local[13]= local[2];
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,3,local+12); /*list*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	local[12]= w;
	goto IF4560;
IF4559:
	local[12]= NIL;
IF4560:
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,2,local+11); /*list*/
	ctx->vsp=local+11;
	local[0]=w;
	goto BLK4544;
	goto IF4558;
IF4557:
	local[11]= NIL;
IF4558:
	local[11]= local[4];
	local[12]= (pointer)get_sym_func(fqv[6]);
	ctx->vsp=local+13;
	local[13]= makeclosure(codevec,quotevec,CLO4561,env,argv,local);
	ctx->vsp=local+14;
	w=(pointer)SORT(ctx,3,local+11); /*sort*/
	local[4] = w;
	local[11]= local[4];
	local[12]= makeflt(1.00000000e+00);
	w = NIL;
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)NCONC(ctx,2,local+11); /*nconc*/
	local[6] = makeflt(0.00000000e+00);
	local[11]= NIL;
	local[12]= local[4];
WHL4563:
	if (local[12]==NIL) goto WHX4564;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12] = (w)->c.cons.cdr;
	w = local[13];
	local[11] = w;
	w = local[11];
	if (!iscons(w)) goto IF4567;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	goto IF4568;
IF4567:
	local[13]= local[11];
IF4568:
	local[7] = local[13];
	local[13]= local[6];
	local[14]= local[7];
	local[15]= local[1];
	ctx->vsp=local+16;
	w=(*ftab[0])(ctx,3,local+13,&ftab[0],fqv[7]); /*eps<*/
	if (w==NIL) goto IF4569;
	local[13]= argv[0];
	local[14]= fqv[5];
	local[15]= argv[1];
	local[16]= fqv[8];
	local[17]= local[6];
	local[18]= local[7];
	ctx->vsp=local+19;
	w=(pointer)PLUS(ctx,2,local+17); /*+*/
	local[17]= w;
	local[18]= makeflt(2.00000000e+00);
	ctx->vsp=local+19;
	w=(pointer)QUOTIENT(ctx,2,local+17); /*/*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,3,local+15); /*send*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[5] = w;
	local[13]= local[5];
	if (local[0]!=local[13]) goto IF4571;
	local[13]= T;
	local[14]= argv[1];
	local[15]= fqv[8];
	local[16]= local[6];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[14]= w;
	local[15]= argv[1];
	local[16]= fqv[8];
	local[17]= local[7];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,3,local+15); /*send*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,3,local+13); /*list*/
	local[13]= w;
	w = local[9];
	ctx->vsp=local+14;
	local[9] = cons(ctx,local[13],w);
	local[13]= local[9];
	goto IF4572;
IF4571:
	local[13]= NIL;
IF4572:
	local[6] = local[7];
	local[13]= local[6];
	goto IF4570;
IF4569:
	local[13]= NIL;
IF4570:
	w = local[11];
	if (!iscons(w)) goto IF4573;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.car;
	local[13]= local[6];
	local[14]= local[7];
	local[15]= local[1];
	ctx->vsp=local+16;
	w=(*ftab[1])(ctx,3,local+13,&ftab[1],fqv[9]); /*eps<>*/
	if (w==NIL) goto IF4575;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	local[14]= argv[1];
	local[15]= argv[1];
	local[16]= fqv[8];
	local[17]= local[6];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,3,local+15); /*send*/
	local[15]= w;
	local[16]= argv[1];
	local[17]= fqv[8];
	local[18]= local[7];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,3,local+16); /*send*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,4,local+13); /*list*/
	local[13]= w;
	w = local[8];
	ctx->vsp=local+14;
	local[8] = cons(ctx,local[13],w);
	local[13]= local[8];
	goto IF4576;
IF4575:
	local[13]= NIL;
IF4576:
	local[6] = local[7];
	local[13]= local[6];
	goto IF4574;
IF4573:
	local[13]= NIL;
IF4574:
	goto WHL4563;
WHX4564:
	local[13]= NIL;
BLK4565:
	w = NIL;
	local[11]= local[8];
	local[12]= local[9];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,2,local+11); /*list*/
	local[0]= w;
BLK4544:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4561(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!isnum(w)) goto IF4577;
	local[0]= argv[0];
	goto IF4578;
IF4577:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
	local[1]= makeflt(2.00000000e+00);
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
IF4578:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*find-next-segment*/
static pointer F4531find_next_segment(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeflt(1.00000000e+20);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[1];
WHL4581:
	if (local[3]==NIL) goto WHX4582;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= argv[0];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)VDISTANCE(ctx,2,local+4); /*distance*/
	local[4]= w;
	local[5]= argv[0];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)VDISTANCE(ctx,2,local+5); /*distance*/
	local[5]= w;
	local[6]= local[4];
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)MIN(ctx,2,local+6); /*min*/
	local[6]= w;
	local[7]= local[6];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto IF4585;
	local[1] = local[2];
	local[0] = local[6];
	local[7]= local[0];
	goto IF4586;
IF4585:
	local[7]= NIL;
IF4586:
	w = local[7];
	goto WHL4581;
WHX4582:
	local[4]= NIL;
BLK4583:
	w = NIL;
	local[2]= local[0];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto IF4587;
	local[2]= local[1];
	goto IF4588;
IF4587:
	local[2]= NIL;
IF4588:
	w = local[2];
	local[0]= w;
BLK4579:
	ctx->vsp=local; return(local[0]);}

/*find-loop*/
static pointer F4532find_loop(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4591;}
	local[0]= loadglobal(fqv[10]);
ENT4591:
ENT4590:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= loadglobal(fqv[11]);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,1,local+7); /*instantiate*/
	local[7]= w;
	local[8]= NIL;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[9];
	local[2] = w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.car;
	local[9]= local[4];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,2,local+9); /*list*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[1] = w;
WHL4593:
	local[9]= local[5];
	local[10]= argv[0];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)F4531find_next_segment(ctx,3,local+9); /*find-next-segment*/
	local[6] = w;
	if (local[6]==NIL) goto WHX4594;
	local[9]= local[6];
	local[10]= argv[0];
	local[11]= fqv[12];
	local[12]= makeint(1);
	ctx->vsp=local+13;
	w=(*ftab[2])(ctx,4,local+9,&ftab[2],fqv[13]); /*delete*/
	argv[0] = w;
	local[3] = local[5];
	local[9]= local[5];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	w=(*ftab[3])(ctx,2,local+9,&ftab[3],fqv[14]); /*eps-v=*/
	if (w==NIL) goto IF4596;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.car;
	local[9]= local[5];
	goto IF4597;
IF4596:
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.car;
	local[9]= local[5];
IF4597:
	local[9]= local[3];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,2,local+9); /*list*/
	local[9]= w;
	w = local[1];
	ctx->vsp=local+10;
	local[1] = cons(ctx,local[9],w);
	goto WHL4593;
WHX4594:
	local[9]= NIL;
BLK4595:
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)NREVERSE(ctx,1,local+9); /*nreverse*/
	local[1] = w;
	local[9]= local[4];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(*ftab[3])(ctx,2,local+9,&ftab[3],fqv[14]); /*eps-v=*/
	if (w!=NIL) goto CON4599;
	local[9]= NIL;
	local[10]= local[1];
WHL4601:
	if (local[10]==NIL) goto WHX4602;
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
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	ctx->vsp=local+13;
	w=(*ftab[4])(ctx,2,local+11,&ftab[4],fqv[15]); /*make-line*/
	local[11]= w;
	w = local[8];
	ctx->vsp=local+12;
	local[8] = cons(ctx,local[11],w);
	goto WHL4601;
WHX4602:
	local[11]= NIL;
BLK4603:
	w = NIL;
	local[9]= local[8];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,2,local+9); /*list*/
	local[9]= w;
	goto CON4598;
CON4599:
	local[9]= (pointer)get_sym_func(fqv[16]);
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(pointer)MAPCAR(ctx,2,local+9); /*mapcar*/
	local[1] = w;
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(*ftab[5])(ctx,1,local+9,&ftab[5],fqv[17]); /*face-normal-vector*/
	local[9]= w;
	local[10]= argv[1];
	ctx->vsp=local+11;
	w=(pointer)VINNERPRODUCT(ctx,2,local+9); /*v.*/
	local[9]= w;
	{ double left,right;
		right=fltval(makeflt(0.00000000e+00)); left=fltval(local[9]);
	if (left >= right) goto IF4606;}
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)NREVERSE(ctx,1,local+9); /*nreverse*/
	local[1] = w;
	local[9]= local[1];
	goto IF4607;
IF4606:
	local[9]= NIL;
IF4607:
	local[9]= loadglobal(fqv[11]);
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,1,local+9); /*instantiate*/
	local[9]= w;
	local[10]= local[9];
	local[11]= fqv[18];
	local[12]= fqv[19];
	local[13]= local[1];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	w = local[9];
	local[7] = w;
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[9]= w;
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,2,local+9); /*list*/
	local[9]= w;
	goto CON4598;
CON4605:
	local[9]= NIL;
CON4598:
	w = local[9];
	local[0]= w;
BLK4589:
	ctx->vsp=local; return(local[0]);}

/*punch-hole*/
static pointer F4533punch_hole(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= fqv[19];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	ctx->vsp=local+1;
	w=(pointer)REVERSE(ctx,1,local+0); /*reverse*/
	local[0]= w;
	local[1]= loadglobal(fqv[20]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[18];
	local[4]= fqv[19];
	local[5]= local[0];
	local[6]= fqv[21];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[22];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0]= w;
BLK4609:
	ctx->vsp=local; return(local[0]);}

/*construct-polygon*/
static pointer F4534construct_polygon(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4612;}
	local[0]= loadglobal(fqv[10]);
ENT4612:
ENT4611:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
WHL4613:
	if (argv[0]==NIL) goto WHX4614;
	local[7]= argv[0];
	local[8]= argv[1];
	ctx->vsp=local+9;
	w=(pointer)F4532find_loop(ctx,2,local+7); /*find-loop*/
	local[4] = w;
	local[7]= NIL;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
WHL4617:
	if (local[8]==NIL) goto WHX4618;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[7];
	local[10]= loadglobal(fqv[23]);
	ctx->vsp=local+11;
	w=(pointer)DERIVEDP(ctx,2,local+9); /*derivedp*/
	if (w==NIL) goto IF4621;
	local[9]= local[7];
	w = local[2];
	ctx->vsp=local+10;
	local[2] = cons(ctx,local[9],w);
	local[9]= local[2];
	goto IF4622;
IF4621:
	local[9]= local[7];
	w = local[1];
	ctx->vsp=local+10;
	local[1] = cons(ctx,local[9],w);
	local[9]= local[1];
IF4622:
	goto WHL4617;
WHX4618:
	local[9]= NIL;
BLK4619:
	w = NIL;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	goto WHL4613;
WHX4614:
	local[7]= NIL;
BLK4615:
	local[7]= NIL;
	local[8]= local[1];
WHL4623:
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX4624;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= NIL;
	local[10]= local[8];
WHL4628:
	if (local[10]==NIL) goto WHX4629;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	local[11]= local[7];
	local[12]= fqv[5];
	local[13]= local[9];
	local[14]= fqv[24];
	local[15]= makeint(0);
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[11]= w;
	local[12]= fqv[0];
	ctx->vsp=local+13;
	w=(pointer)EQ(ctx,2,local+11); /*eql*/
	if (w==NIL) goto CON4633;
	local[11]= local[7];
	local[12]= local[9];
	ctx->vsp=local+13;
	w=(pointer)F4533punch_hole(ctx,2,local+11); /*punch-hole*/
	local[11]= local[9];
	local[12]= local[1];
	local[13]= fqv[12];
	local[14]= makeint(1);
	ctx->vsp=local+15;
	w=(*ftab[2])(ctx,4,local+11,&ftab[2],fqv[13]); /*delete*/
	local[1] = w;
	local[11]= local[1];
	goto CON4632;
CON4633:
	local[11]= local[9];
	local[12]= fqv[5];
	local[13]= local[7];
	local[14]= fqv[24];
	local[15]= makeint(0);
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[11]= w;
	local[12]= fqv[0];
	ctx->vsp=local+13;
	w=(pointer)EQ(ctx,2,local+11); /*eql*/
	if (w==NIL) goto CON4634;
	local[11]= local[9];
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(pointer)F4533punch_hole(ctx,2,local+11); /*punch-hole*/
	local[11]= local[7];
	local[12]= local[1];
	local[13]= fqv[12];
	local[14]= makeint(1);
	ctx->vsp=local+15;
	w=(*ftab[2])(ctx,4,local+11,&ftab[2],fqv[13]); /*delete*/
	local[1] = w;
	local[11]= local[1];
	goto CON4632;
CON4634:
	local[11]= NIL;
CON4632:
	goto WHL4628;
WHX4629:
	local[11]= NIL;
BLK4630:
	w = NIL;
	goto WHL4623;
WHX4624:
	local[9]= NIL;
BLK4625:
	w = local[9];
	local[7]= local[1];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)NCONC(ctx,2,local+7); /*nconc*/
	local[0]= w;
BLK4610:
	ctx->vsp=local; return(local[0]);}

/*remove-non-overlapping-border*/
static pointer F4535remove_non_overlapping_border(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[25];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[1];
	local[2]= fqv[25];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[2];
WHL4637:
	if (local[4]==NIL) goto WHX4638;
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
	local[5]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= local[5];
	local[8]= fqv[26];
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+7); /*v**/
	local[7]= w;
	local[8]= local[6];
	local[9]= fqv[26];
	local[10]= argv[1];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+8); /*v**/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)VINNERPRODUCT(ctx,2,local+7); /*v.*/
	local[7]= w;
	{ double left,right;
		right=fltval(makeflt(0.00000000e+00)); left=fltval(local[7]);
	if (left <= right) goto IF4641;}
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
	w = local[2];
	ctx->vsp=local+8;
	local[2] = cons(ctx,local[7],w);
	local[7]= local[2];
	goto IF4642;
IF4641:
	local[7]= NIL;
IF4642:
	w = local[7];
	goto WHL4637;
WHX4638:
	local[5]= NIL;
BLK4639:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK4635:
	ctx->vsp=local; return(local[0]);}

/*coplanar-ff-intersection*/
static pointer F4536coplanar_ff_intersection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4646;}
	local[0]= fqv[0];
ENT4646:
	if (n>=4) { local[1]=(argv[3]); goto ENT4645;}
	local[1]= loadglobal(fqv[1]);
ENT4645:
ENT4644:
	if (n>4) maerror();
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= argv[0];
	local[10]= fqv[2];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
WHL4648:
	if (local[9]==NIL) goto WHX4649;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= argv[1];
	local[11]= local[8];
	local[12]= local[0];
	local[13]= local[1];
	ctx->vsp=local+14;
	w=(pointer)F4530coplanar_fe_intersection(ctx,4,local+10); /*coplanar-fe-intersection*/
	local[6] = w;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto IF4652;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= local[4];
	ctx->vsp=local+12;
	w=(pointer)NCONC(ctx,2,local+10); /*nconc*/
	local[4] = w;
	local[10]= local[4];
	goto IF4653;
IF4652:
	local[10]= NIL;
IF4653:
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto IF4654;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)NCONC(ctx,2,local+10); /*nconc*/
	local[2] = w;
	local[10]= local[2];
	goto IF4655;
IF4654:
	local[10]= NIL;
IF4655:
	goto WHL4648;
WHX4649:
	local[10]= NIL;
BLK4650:
	w = NIL;
	if (local[4]==NIL) goto IF4656;
	local[7] = T;
	local[8]= local[7];
	goto IF4657;
IF4656:
	local[8]= NIL;
IF4657:
	if (T==NIL) goto IF4658;
	local[8]= argv[1];
	local[9]= argv[0];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)F4535remove_non_overlapping_border(ctx,3,local+8); /*remove-non-overlapping-border*/
	local[4] = w;
	local[8]= local[4];
	goto IF4659;
IF4658:
	local[8]= (pointer)get_sym_func(fqv[27]);
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)MAPCAR(ctx,2,local+8); /*mapcar*/
	local[4] = w;
	local[8]= local[4];
IF4659:
	local[8]= NIL;
	local[9]= argv[1];
	local[10]= fqv[2];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
WHL4661:
	if (local[9]==NIL) goto WHX4662;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= argv[0];
	local[11]= local[8];
	local[12]= local[0];
	local[13]= local[1];
	ctx->vsp=local+14;
	w=(pointer)F4530coplanar_fe_intersection(ctx,4,local+10); /*coplanar-fe-intersection*/
	local[6] = w;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto IF4665;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)NCONC(ctx,2,local+10); /*nconc*/
	local[5] = w;
	local[10]= local[5];
	goto IF4666;
IF4665:
	local[10]= NIL;
IF4666:
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto IF4667;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)NCONC(ctx,2,local+10); /*nconc*/
	local[2] = w;
	local[10]= local[2];
	goto IF4668;
IF4667:
	local[10]= NIL;
IF4668:
	goto WHL4661;
WHX4662:
	local[10]= NIL;
BLK4663:
	w = NIL;
	if (local[5]==NIL) goto IF4669;
	local[7] = T;
	local[8]= local[7];
	goto IF4670;
IF4669:
	local[8]= NIL;
IF4670:
	if (T==NIL) goto IF4671;
	local[8]= argv[0];
	local[9]= argv[1];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)F4535remove_non_overlapping_border(ctx,3,local+8); /*remove-non-overlapping-border*/
	local[5] = w;
	local[8]= local[5];
	goto IF4672;
IF4671:
	local[8]= (pointer)get_sym_func(fqv[27]);
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)MAPCAR(ctx,2,local+8); /*mapcar*/
	local[5] = w;
	local[8]= local[5];
IF4672:
	local[8]= local[4];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)NCONC(ctx,2,local+8); /*nconc*/
	local[3] = w;
	local[8]= local[3];
	local[9]= fqv[28];
	ctx->vsp=local+10;
	local[10]= makeclosure(codevec,quotevec,CLO4673,env,argv,local);
	ctx->vsp=local+11;
	w=(*ftab[6])(ctx,3,local+8,&ftab[6],fqv[29]); /*remove-duplicates*/
	local[3] = w;
	if (local[7]!=NIL) goto CON4675;
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,CLO4676,env,argv,local);
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(*ftab[7])(ctx,2,local+8,&ftab[7],fqv[30]); /*every*/
	if (w==NIL) goto CON4675;
	local[8]= argv[0];
	local[9]= fqv[5];
	local[10]= argv[1];
	local[11]= fqv[24];
	local[12]= makeint(0);
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	local[11]= makeflt(1.00000000e-03);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= w;
	local[9]= argv[1];
	local[10]= fqv[5];
	local[11]= argv[0];
	local[12]= fqv[24];
	local[13]= makeint(0);
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[11]= w;
	local[12]= makeflt(1.00000000e-03);
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,4,local+9); /*send*/
	local[9]= w;
	local[10]= local[0];
	local[11]= fqv[0];
	ctx->vsp=local+12;
	w=(pointer)EQ(ctx,2,local+10); /*eql*/
	if (w==NIL) goto CON4678;
	local[10]= local[8];
	local[11]= fqv[0];
	ctx->vsp=local+12;
	w=(pointer)EQ(ctx,2,local+10); /*eql*/
	if (w==NIL) goto CON4680;
	local[10]= argv[1];
	goto CON4679;
CON4680:
	local[10]= local[9];
	local[11]= fqv[0];
	ctx->vsp=local+12;
	w=(pointer)EQ(ctx,2,local+10); /*eql*/
	if (w==NIL) goto CON4681;
	local[10]= argv[0];
	goto CON4679;
CON4681:
	local[10]= NIL;
	goto CON4679;
CON4682:
	local[10]= NIL;
CON4679:
	goto CON4677;
CON4678:
	local[10]= local[0];
	local[11]= fqv[31];
	ctx->vsp=local+12;
	w=(pointer)EQ(ctx,2,local+10); /*eql*/
	if (w==NIL) goto CON4683;
	local[10]= local[8];
	local[11]= fqv[0];
	ctx->vsp=local+12;
	w=(pointer)EQ(ctx,2,local+10); /*eql*/
	if (w==NIL) goto CON4685;
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	local[10]= w;
	goto CON4684;
CON4685:
	local[10]= local[9];
	local[11]= fqv[0];
	ctx->vsp=local+12;
	w=(pointer)EQ(ctx,2,local+10); /*eql*/
	if (w==NIL) goto CON4686;
	local[10]= argv[1];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	local[10]= w;
	goto CON4684;
CON4686:
	local[10]= argv[0];
	local[11]= argv[1];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,2,local+10); /*list*/
	local[10]= w;
	goto CON4684;
CON4687:
	local[10]= NIL;
CON4684:
	goto CON4677;
CON4683:
	local[10]= NIL;
CON4677:
	w = local[10];
	local[8]= w;
	goto CON4674;
CON4675:
	local[8]= (pointer)get_sym_func(fqv[32]);
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)MAPCAR(ctx,2,local+8); /*mapcar*/
	local[8]= w;
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)NCONC(ctx,2,local+8); /*nconc*/
	local[8]= w;
	local[9]= argv[0];
	local[10]= fqv[25];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)F4534construct_polygon(ctx,2,local+8); /*construct-polygon*/
	local[8]= w;
	goto CON4674;
CON4688:
	local[8]= NIL;
CON4674:
	w = local[8];
	local[0]= w;
BLK4643:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4673(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= env->c.clo.env2[1];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,3,local+0,&ftab[3],fqv[14]); /*eps-v=*/
	local[0]= w;
	if (w==NIL) goto AND4690;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= env->c.clo.env2[1];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,3,local+0,&ftab[3],fqv[14]); /*eps-v=*/
	local[0]= w;
AND4690:
	if (local[0]!=NIL) goto OR4689;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= env->c.clo.env2[1];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,3,local+0,&ftab[3],fqv[14]); /*eps-v=*/
	local[0]= w;
	if (w==NIL) goto AND4691;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= env->c.clo.env2[1];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,3,local+0,&ftab[3],fqv[14]); /*eps-v=*/
	local[0]= w;
AND4691:
OR4689:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4676(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (((w)->c.cons.car)==NIL?T:NIL);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*face**/
static pointer F4537face_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4694;}
	local[0]= loadglobal(fqv[1]);
ENT4694:
ENT4693:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= fqv[0];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)F4536coplanar_ff_intersection(ctx,4,local+1); /*coplanar-ff-intersection*/
	local[0]= w;
BLK4692:
	ctx->vsp=local; return(local[0]);}

/*face+*/
static pointer F4538face_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4697;}
	local[0]= loadglobal(fqv[1]);
ENT4697:
ENT4696:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= fqv[31];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)F4536coplanar_ff_intersection(ctx,4,local+1); /*coplanar-ff-intersection*/
	local[0]= w;
BLK4695:
	ctx->vsp=local; return(local[0]);}

/*non-coplanar-fe-relation*/
static pointer F4539non_coplanar_fe_relation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4700;}
	local[0]= loadglobal(fqv[1]);
ENT4700:
ENT4699:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[33];
	local[3]= argv[1]->c.obj.iv[1];
	local[4]= argv[1]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	local[2]= argv[1];
	local[3]= fqv[8];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= NIL;
	local[4]= local[1];
	local[5]= makeflt(0.00000000e+00);
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[8])(ctx,3,local+4,&ftab[8],fqv[34]); /*eps=*/
	if (w!=NIL) goto OR4703;
	local[4]= local[1];
	local[5]= makeflt(1.00000000e+00);
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[8])(ctx,3,local+4,&ftab[8],fqv[34]); /*eps=*/
	if (w!=NIL) goto OR4703;
	goto CON4702;
OR4703:
	local[4]= argv[0];
	local[5]= fqv[5];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[3] = w;
	local[4]= local[3];
	local[5]= fqv[35];
	ctx->vsp=local+6;
	w=(*ftab[9])(ctx,2,local+4,&ftab[9],fqv[36]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	goto CON4701;
CON4702:
	local[4]= makeflt(0.00000000e+00);
	local[5]= local[1];
	local[6]= makeflt(1.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)LESSP(ctx,3,local+4); /*<*/
	if (w==NIL) goto CON4704;
	local[4]= argv[0];
	local[5]= fqv[5];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[3] = w;
	local[4]= local[3];
	local[5]= local[4];
	if (fqv[0]!=local[5]) goto IF4706;
	local[5]= argv[0];
	local[6]= fqv[37];
	local[7]= argv[1]->c.obj.iv[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	if (w==NIL) goto IF4708;
	local[5]= argv[0];
	local[6]= fqv[37];
	local[7]= argv[1]->c.obj.iv[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	if (w==NIL) goto IF4708;
	local[5]= fqv[38];
	goto IF4709;
IF4708:
	local[5]= fqv[39];
IF4709:
	goto IF4707;
IF4706:
	local[5]= local[4];
	if (fqv[40]!=local[5]) goto IF4710;
	local[5]= fqv[38];
	goto IF4711;
IF4710:
	local[5]= local[4];
	if (fqv[31]!=local[5]) goto IF4712;
	local[5]= NIL;
	goto IF4713;
IF4712:
	local[5]= NIL;
IF4713:
IF4711:
IF4707:
	w = local[5];
	local[4]= w;
	goto CON4701;
CON4704:
	local[4]= NIL;
	goto CON4701;
CON4714:
	local[4]= NIL;
CON4701:
	w = local[4];
	local[0]= w;
BLK4698:
	ctx->vsp=local; return(local[0]);}

/*ff-relation*/
static pointer F4540ff_relation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4717;}
	local[0]= loadglobal(fqv[1]);
ENT4717:
ENT4716:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[1]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= argv[1]->c.obj.iv[2];
	local[5]= argv[0]->c.obj.iv[4];
	local[6]= argv[1]->c.obj.iv[4];
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= local[1];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)VINNERPRODUCT(ctx,2,local+13); /*v.*/
	local[13]= w;
	local[14]= makeflt(1.00000000e+00);
	local[15]= local[0];
	ctx->vsp=local+16;
	w=(*ftab[8])(ctx,3,local+13,&ftab[8],fqv[34]); /*eps=*/
	if (w==NIL) goto CON4719;
	local[13]= local[3];
	local[14]= local[4];
	ctx->vsp=local+15;
	w=(*ftab[8])(ctx,2,local+13,&ftab[8],fqv[34]); /*eps=*/
	if (w==NIL) goto IF4720;
	local[13]= fqv[41];
	local[14]= fqv[42];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,2,local+13); /*list*/
	local[9] = w;
	local[13]= local[9];
	goto IF4721;
IF4720:
	w = NIL;
	ctx->vsp=local+13;
	local[0]=w;
	goto BLK4715;
IF4721:
	goto CON4718;
CON4719:
	local[13]= local[1];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)VINNERPRODUCT(ctx,2,local+13); /*v.*/
	local[13]= w;
	local[14]= makeflt(-1.00000000e+00);
	ctx->vsp=local+15;
	w=(*ftab[8])(ctx,2,local+13,&ftab[8],fqv[34]); /*eps=*/
	if (w==NIL) goto CON4722;
	local[13]= local[3];
	local[14]= local[4];
	ctx->vsp=local+15;
	w=(pointer)MINUS(ctx,1,local+14); /*-*/
	local[14]= w;
	local[15]= local[0];
	ctx->vsp=local+16;
	w=(*ftab[8])(ctx,3,local+13,&ftab[8],fqv[34]); /*eps=*/
	if (w==NIL) goto IF4723;
	local[13]= fqv[41];
	local[14]= fqv[43];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,2,local+13); /*list*/
	local[9] = w;
	local[13]= local[9];
	goto IF4724;
IF4723:
	w = NIL;
	ctx->vsp=local+13;
	local[0]=w;
	goto BLK4715;
IF4724:
	goto CON4718;
CON4722:
	local[13]= NIL;
CON4718:
	if (local[9]==NIL) goto IF4725;
	local[13]= argv[0];
	local[14]= argv[1];
	local[15]= local[0];
	ctx->vsp=local+16;
	w=(pointer)F4537face_(ctx,3,local+13); /*face**/
	local[10] = w;
	local[13]= local[10];
	local[14]= loadglobal(fqv[11]);
	ctx->vsp=local+15;
	w=(pointer)DERIVEDP(ctx,2,local+13); /*derivedp*/
	if (w==NIL) goto CON4728;
	local[13]= local[9];
	local[14]= local[10];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)APPEND(ctx,2,local+13); /*append*/
	ctx->vsp=local+13;
	local[0]=w;
	goto BLK4715;
	goto CON4727;
CON4728:
	ctx->vsp=local+13;
	local[13]= makeclosure(codevec,quotevec,CLO4730,env,argv,local);
	local[14]= local[10];
	ctx->vsp=local+15;
	w=(*ftab[10])(ctx,2,local+13,&ftab[10],fqv[44]); /*some*/
	if (w==NIL) goto CON4729;
	local[13]= local[9];
	local[14]= local[10];
	ctx->vsp=local+15;
	w=(pointer)APPEND(ctx,2,local+13); /*append*/
	ctx->vsp=local+13;
	local[0]=w;
	goto BLK4715;
	goto CON4727;
CON4729:
	ctx->vsp=local+13;
	local[13]= makeclosure(codevec,quotevec,CLO4732,env,argv,local);
	local[14]= local[10];
	ctx->vsp=local+15;
	w=(*ftab[7])(ctx,2,local+13,&ftab[7],fqv[30]); /*every*/
	if (w==NIL) goto CON4731;
	local[13]= fqv[45];
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,2,local+13); /*list*/
	ctx->vsp=local+13;
	local[0]=w;
	goto BLK4715;
	goto CON4727;
CON4731:
	local[13]= NIL;
CON4727:
	goto IF4726;
IF4725:
	local[13]= NIL;
IF4726:
	local[13]= NIL;
	local[14]= local[5];
WHL4734:
	if (local[14]==NIL) goto WHX4735;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14] = (w)->c.cons.cdr;
	w = local[15];
	local[13] = w;
	local[15]= argv[1];
	local[16]= local[13];
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)F4539non_coplanar_fe_relation(ctx,3,local+15); /*non-coplanar-fe-relation*/
	local[11] = w;
	local[15]= local[11];
	if (fqv[39]!=local[15]) goto IF4738;
	local[15]= T;
	local[16]= fqv[46];
	local[17]= argv[1];
	local[18]= local[13];
	ctx->vsp=local+19;
	w=(pointer)XFORMAT(ctx,4,local+15); /*format*/
	local[15]= fqv[39];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	local[0]=w;
	goto BLK4715;
	goto IF4739;
IF4738:
	local[15]= NIL;
IF4739:
	if (local[11]==NIL) goto IF4740;
	local[15]= local[11];
	w = local[10];
	ctx->vsp=local+16;
	local[10] = cons(ctx,local[15],w);
	local[15]= local[10];
	goto IF4741;
IF4740:
	local[15]= NIL;
IF4741:
	goto WHL4734;
WHX4735:
	local[15]= NIL;
BLK4736:
	w = NIL;
	local[13]= NIL;
	local[14]= local[6];
WHL4743:
	if (local[14]==NIL) goto WHX4744;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14] = (w)->c.cons.cdr;
	w = local[15];
	local[13] = w;
	local[15]= argv[0];
	local[16]= local[13];
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)F4539non_coplanar_fe_relation(ctx,3,local+15); /*non-coplanar-fe-relation*/
	local[11] = w;
	local[15]= local[11];
	if (fqv[39]!=local[15]) goto IF4747;
	local[15]= T;
	local[16]= fqv[47];
	local[17]= argv[0];
	local[18]= local[13];
	ctx->vsp=local+19;
	w=(pointer)XFORMAT(ctx,4,local+15); /*format*/
	local[15]= fqv[39];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	local[0]=w;
	goto BLK4715;
	goto IF4748;
IF4747:
	local[15]= NIL;
IF4748:
	if (local[11]==NIL) goto IF4749;
	local[15]= local[11];
	w = local[10];
	ctx->vsp=local+16;
	local[10] = cons(ctx,local[15],w);
	local[15]= local[10];
	goto IF4750;
IF4749:
	local[15]= NIL;
IF4750:
	goto WHL4743;
WHX4744:
	local[15]= NIL;
BLK4745:
	w = NIL;
	ctx->vsp=local+13;
	local[13]= makeclosure(codevec,quotevec,CLO4753,env,argv,local);
	local[14]= local[10];
	ctx->vsp=local+15;
	w=(*ftab[7])(ctx,2,local+13,&ftab[7],fqv[30]); /*every*/
	if (w==NIL) goto CON4752;
	local[13]= fqv[48];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	local[13]= w;
	goto CON4751;
CON4752:
	local[13]= local[10];
	goto CON4751;
CON4754:
	local[13]= NIL;
CON4751:
	w = local[13];
	local[0]= w;
BLK4715:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4730(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[11]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4732(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[23]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4753(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = ((fqv[38])==(local[0])?T:NIL);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*bb-relation*/
static pointer F4541bb_relation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4757;}
	local[0]= loadglobal(fqv[49]);
ENT4757:
ENT4756:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[50];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= argv[0];
	local[9]= fqv[51];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= argv[1];
	local[10]= fqv[51];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	local[10]= makeint(0);
	local[11]= NIL;
	if (local[1]==NIL) goto IF4758;
	local[12]= argv[0];
	local[13]= fqv[52];
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[2] = w;
	local[12]= argv[1];
	local[13]= fqv[52];
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[3] = w;
	local[12]= local[8];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(*ftab[11])(ctx,2,local+12,&ftab[11],fqv[53]); /*intersection*/
	local[8] = w;
	local[12]= local[9];
	local[13]= local[3];
	ctx->vsp=local+14;
	w=(*ftab[11])(ctx,2,local+12,&ftab[11],fqv[53]); /*intersection*/
	local[9] = w;
	local[12]= argv[0];
	local[13]= fqv[54];
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[4] = w;
	local[12]= argv[1];
	local[13]= fqv[54];
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[5] = w;
	local[12]= NIL;
	local[13]= local[2];
WHL4761:
	if (local[13]==NIL) goto WHX4762;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13] = (w)->c.cons.cdr;
	w = local[14];
	local[12] = w;
	local[14]= local[12];
	local[15]= fqv[55];
	local[16]= local[0];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[11] = w;
	local[14]= local[11];
	local[15]= fqv[56];
	local[16]= local[0];
	local[17]= T;
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,4,local+14); /*send*/
	local[14]= NIL;
	local[15]= local[3];
WHL4766:
	if (local[15]==NIL) goto WHX4767;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15] = (w)->c.cons.cdr;
	w = local[16];
	local[14] = w;
	local[16]= local[14];
	local[17]= fqv[55];
	local[18]= local[0];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,3,local+16); /*send*/
	local[16]= w;
	local[17]= fqv[57];
	local[18]= local[11];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,3,local+16); /*send*/
	if (w==NIL) goto OR4772;
	goto IF4770;
OR4772:
	local[7] = NIL;
	local[16]= local[7];
	goto IF4771;
IF4770:
	local[16]= local[12];
	local[17]= local[14];
	local[18]= local[0];
	ctx->vsp=local+19;
	w=(pointer)F4540ff_relation(ctx,3,local+16); /*ff-relation*/
	local[7] = w;
	local[16]= local[7];
IF4771:
	if (local[7]!=NIL) goto CON4774;
	local[16]= NIL;
	goto CON4773;
CON4774:
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	if (fqv[48]!=local[16]) goto CON4775;
	local[16]= NIL;
	goto CON4773;
CON4775:
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	if (fqv[41]!=local[16]) goto CON4776;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	if (fqv[43]!=local[16]) goto CON4776;
	local[16]= fqv[58];
	local[17]= local[12];
	local[18]= local[14];
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.cdr;
	ctx->vsp=local+20;
	w=(pointer)LIST_STAR(ctx,4,local+16); /*list**/
	local[16]= w;
	w = local[6];
	ctx->vsp=local+17;
	local[6] = cons(ctx,local[16],w);
	local[16]= local[6];
	goto CON4773;
CON4776:
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	if (fqv[45]!=local[16]) goto CON4777;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	if (fqv[42]!=local[16]) goto CON4777;
	local[16]= fqv[45];
	local[17]= local[12];
	local[18]= local[14];
	ctx->vsp=local+19;
	w=(pointer)LIST(ctx,3,local+16); /*list*/
	local[16]= w;
	w = local[6];
	ctx->vsp=local+17;
	local[6] = cons(ctx,local[16],w);
	local[16]= local[6];
	goto CON4773;
CON4777:
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	if (fqv[41]!=local[16]) goto CON4778;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	if (fqv[42]!=local[16]) goto CON4778;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	local[17]= loadglobal(fqv[11]);
	ctx->vsp=local+18;
	w=(pointer)DERIVEDP(ctx,2,local+16); /*derivedp*/
	if (w==NIL) goto CON4778;
	w = fqv[39];
	ctx->vsp=local+16;
	local[0]=w;
	goto BLK4755;
	goto CON4773;
CON4778:
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	if (fqv[39]!=local[16]) goto CON4779;
	w = fqv[39];
	ctx->vsp=local+16;
	local[0]=w;
	goto BLK4755;
	goto CON4773;
CON4779:
	local[16]= local[12];
	local[17]= local[14];
	local[18]= local[7];
	ctx->vsp=local+19;
	w=(pointer)LIST_STAR(ctx,3,local+16); /*list**/
	local[16]= w;
	w = local[6];
	ctx->vsp=local+17;
	local[6] = cons(ctx,local[16],w);
	local[16]= local[6];
	goto CON4773;
CON4780:
	local[16]= NIL;
CON4773:
	goto WHL4766;
WHX4767:
	local[16]= NIL;
BLK4768:
	w = NIL;
	goto WHL4761;
WHX4762:
	local[14]= NIL;
BLK4763:
	w = NIL;
	local[12]= local[6];
	goto IF4759;
IF4758:
	local[12]= NIL;
IF4759:
	w = local[12];
	local[0]= w;
BLK4755:
	ctx->vsp=local; return(local[0]);}

/*make-lines*/
static pointer F4542make_lines(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO4782,env,argv,local);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	local[0]= w;
BLK4781:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4782(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= (pointer)get_sym_func(fqv[15]);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*copy-face*/
static pointer F4543copy_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,FLET4784,env,argv,local);
	local[1]= loadglobal(fqv[59]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[18];
	local[4]= fqv[19];
	local[5]= argv[0];
	w = local[0];
	ctx->vsp=local+6;
	w=FLET4784(ctx,1,local+5,w);
	local[5]= w;
	local[6]= fqv[60];
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO4786,env,argv,local);
	local[8]= local[0];
	local[9]= argv[0];
	local[10]= fqv[60];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MAPCAR(ctx,2,local+8); /*mapcar*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MAPCAR(ctx,2,local+7); /*mapcar*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK4783:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET4784(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	local[4]= fqv[19];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
WHL4788:
	if (local[3]==NIL) goto WHX4789;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)COPYSEQ(ctx,1,local+4); /*copy-seq*/
	local[4]= w;
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	goto WHL4788;
WHX4789:
	local[4]= NIL;
BLK4790:
	w = local[1];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4786(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[20]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[18];
	local[3]= fqv[19];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___bodyrel(ctx,n,argv,env)
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
	local[0]= fqv[61];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF4793;
	local[0]= fqv[62];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[63],w);
	goto IF4794;
IF4793:
	local[0]= fqv[64];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF4794:
	local[0]= fqv[65];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[66],module,F4530coplanar_fe_intersection,fqv[67]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[68],module,F4531find_next_segment,fqv[69]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[70],module,F4532find_loop,fqv[71]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[72],module,F4533punch_hole,fqv[73]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[74],module,F4534construct_polygon,fqv[75]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[76],module,F4535remove_non_overlapping_border,fqv[77]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[78],module,F4536coplanar_ff_intersection,fqv[79]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[80],module,F4537face_,fqv[81]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[82],module,F4538face_,fqv[83]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[84],module,F4539non_coplanar_fe_relation,fqv[85]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[86],module,F4540ff_relation,fqv[87]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[88],module,F4541bb_relation,fqv[89]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[90],module,F4542make_lines,fqv[91]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[92],module,F4543copy_face,fqv[93]);
	local[0]= fqv[94];
	local[1]= fqv[95];
	ctx->vsp=local+2;
	w=(*ftab[12])(ctx,2,local+0,&ftab[12],fqv[96]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<13; i++) ftab[i]=fcallx;
}
