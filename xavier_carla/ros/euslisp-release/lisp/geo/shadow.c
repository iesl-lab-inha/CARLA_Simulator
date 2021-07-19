/* ./shadow.c :  entry=shadow */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "shadow.h"
#pragma init (register_shadow)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___shadow();
extern pointer build_quote_vector();
static int register_shadow()
  { add_module_initializer("___shadow", ___shadow);}

static pointer F4307polygon_in_contact_p();
static pointer F4308make_edges_from_vertices();
static pointer F4309orthogonally_visible_faces();
static pointer F4310make_polygon();
static pointer F4311make_face_from_edge_loop();
static pointer F4312change_to_hole();
static pointer F4313project_shadow1();
static pointer F4314remove_inner_loop();
static pointer F4315project_shadow();
static pointer F4316shadow_intersection();
static pointer F4317closest_shadow();

/*do-combination*/
static pointer F4318(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST4320:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)GENSYM(ctx,1,local+3); /*gensym*/
	local[3]= w;
	local[4]= fqv[1];
	local[5]= local[3];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	local[5]= w;
	local[6]= fqv[2];
	local[7]= fqv[3];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[1];
	local[9]= local[1];
	local[10]= fqv[4];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[9]= w;
	local[10]= fqv[5];
	local[11]= local[2];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	w = local[0];
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
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	local[0]= w;
BLK4319:
	ctx->vsp=local; return(local[0]);}

/*polygon-in-contact-p*/
static pointer F4307polygon_in_contact_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[1];
	local[2]= fqv[6];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= NIL;
	local[3]= local[0];
WHL4323:
	if (local[3]==NIL) goto WHX4324;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= NIL;
	local[5]= local[1];
WHL4328:
	if (local[5]==NIL) goto WHX4329;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[2];
	local[7]= fqv[7];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	if (w==NIL) goto IF4332;
	local[6]= local[2];
	local[7]= fqv[8];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	if (w==NIL) goto IF4332;
	w = T;
	ctx->vsp=local+6;
	local[0]=w;
	goto BLK4321;
	goto IF4333;
IF4332:
	local[6]= NIL;
IF4333:
	goto WHL4328;
WHX4329:
	local[6]= NIL;
BLK4330:
	w = NIL;
	goto WHL4323;
WHX4324:
	local[4]= NIL;
BLK4325:
	w = NIL;
	w = NIL;
	local[0]= w;
BLK4321:
	ctx->vsp=local; return(local[0]);}

/*make-edges-from-vertices*/
static pointer F4308make_edges_from_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
WHL4335:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX4336;
	local[2]= loadglobal(fqv[9]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[10];
	local[5]= fqv[11];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	local[7]= fqv[12];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	w = local[2];
	local[2]= w;
	w = local[1];
	ctx->vsp=local+3;
	local[1] = cons(ctx,local[2],w);
	goto WHL4335;
WHX4336:
	local[2]= NIL;
BLK4337:
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)NREVERSE(ctx,1,local+2); /*nreverse*/
	local[0]= w;
BLK4334:
	ctx->vsp=local; return(local[0]);}

/*orthogonally-visible-faces*/
static pointer F4309orthogonally_visible_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0];
	local[5]= fqv[13];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
WHL4342:
	if (local[4]==NIL) goto WHX4343;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= argv[1];
	local[6]= local[3]->c.obj.iv[1];
	ctx->vsp=local+7;
	w=(pointer)VINNERPRODUCT(ctx,2,local+5); /*v.*/
	local[5]= w;
	local[6]= makeflt(0.00000000e+00);
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,2,local+5,&ftab[0],fqv[14]); /*eps<*/
	if (w==NIL) goto IF4346;
	local[5]= local[3];
	w = local[1];
	ctx->vsp=local+6;
	local[1] = cons(ctx,local[5],w);
	local[5]= local[1];
	goto IF4347;
IF4346:
	local[5]= local[3];
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[2];
IF4347:
	goto WHL4342;
WHX4343:
	local[5]= NIL;
BLK4344:
	w = NIL;
	local[3]= local[1];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[15]); /*values*/
	local[0]= w;
BLK4340:
	ctx->vsp=local; return(local[0]);}

/*make-polygon*/
static pointer F4310make_polygon(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4349:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= loadglobal(fqv[16]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[10];
	local[4]= fqv[17];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK4348:
	ctx->vsp=local; return(local[0]);}

/*make-face-from-edge-loop*/
static pointer F4311make_face_from_edge_loop(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[18]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= NIL;
	local[2]= argv[0];
WHL4353:
	if (local[2]==NIL) goto WHX4354;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[0];
	local[4]= local[3];
	w = local[1];
	w->c.obj.iv[3] = local[4];
	goto WHL4353;
WHX4354:
	local[3]= NIL;
BLK4355:
	w = NIL;
	local[1]= local[0];
	local[2]= fqv[10];
	local[3]= fqv[19];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK4351:
	ctx->vsp=local; return(local[0]);}

/*change-to-hole*/
static pointer F4312change_to_hole(ctx,n,argv,env)
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
	local[2]= fqv[10];
	local[3]= fqv[17];
	local[4]= argv[0];
	local[5]= fqv[17];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK4357:
	ctx->vsp=local; return(local[0]);}

/*project-shadow1*/
static pointer F4313project_shadow1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= fqv[13];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= NIL;
	w = local[3];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[21],w);
	local[6]= NIL;
	local[7]= argv[1];
	local[8]= fqv[22];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= local[7];
	ctx->vsp=local+9;
	w=(pointer)VMINUS(ctx,1,local+8); /*v-*/
	local[8]= w;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= NIL;
	local[15]= local[2];
WHL4360:
	if (local[15]==NIL) goto WHX4361;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15] = (w)->c.cons.cdr;
	w = local[16];
	local[14] = w;
	local[16]= local[7];
	local[17]= local[14]->c.obj.iv[1];
	ctx->vsp=local+18;
	w=(pointer)VINNERPRODUCT(ctx,2,local+16); /*v.*/
	local[16]= w;
	local[17]= makeflt(0.00000000e+00);
	ctx->vsp=local+18;
	w=(*ftab[0])(ctx,2,local+16,&ftab[0],fqv[14]); /*eps<*/
	if (w==NIL) goto IF4364;
	local[16]= local[14];
	w = local[0];
	ctx->vsp=local+17;
	local[0] = cons(ctx,local[16],w);
	local[16]= local[0];
	goto IF4365;
IF4364:
	local[16]= local[14];
	w = local[1];
	ctx->vsp=local+17;
	local[1] = cons(ctx,local[16],w);
	local[16]= local[1];
IF4365:
	goto WHL4360;
WHX4361:
	local[16]= NIL;
BLK4362:
	w = NIL;
	local[14]= NIL;
	local[15]= local[0];
WHL4367:
	if (local[15]==NIL) goto WHX4368;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15] = (w)->c.cons.cdr;
	w = local[16];
	local[14] = w;
	local[16]= NIL;
	local[17]= NIL;
	local[18]= NIL;
	local[19]= NIL;
	local[20]= NIL;
	local[21]= NIL;
	local[22]= local[14];
	local[23]= fqv[17];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,2,local+22); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.cdr;
WHL4372:
	if (local[22]==NIL) goto WHX4373;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22] = (w)->c.cons.cdr;
	w = local[23];
	local[21] = w;
	local[23]= argv[1];
	local[24]= fqv[23];
	local[25]= local[21];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,3,local+23); /*send*/
	local[23]= w;
	w = local[16];
	ctx->vsp=local+24;
	local[16] = cons(ctx,local[23],w);
	goto WHL4372;
WHX4373:
	local[23]= NIL;
BLK4374:
	w = NIL;
	local[21]= local[16];
	ctx->vsp=local+22;
	w=(pointer)NREVERSE(ctx,1,local+21); /*nreverse*/
	local[16] = w;
	local[21]= NIL;
	local[22]= local[14];
	local[23]= fqv[24];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,2,local+22); /*send*/
	local[22]= w;
WHL4377:
	if (local[22]==NIL) goto WHX4378;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22] = (w)->c.cons.cdr;
	w = local[23];
	local[21] = w;
	local[23]= NIL;
	local[24]= local[21];
	local[25]= fqv[17];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,2,local+24); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24]= (w)->c.cons.cdr;
WHL4382:
	if (local[24]==NIL) goto WHX4383;
	w=local[24];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25]= (w)->c.cons.car;
	w=local[24];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24] = (w)->c.cons.cdr;
	w = local[25];
	local[23] = w;
	local[25]= argv[1];
	local[26]= fqv[23];
	local[27]= local[23];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,3,local+25); /*send*/
	local[25]= w;
	w = local[17];
	ctx->vsp=local+26;
	local[17] = cons(ctx,local[25],w);
	goto WHL4382;
WHX4383:
	local[25]= NIL;
BLK4384:
	w = NIL;
	local[23]= local[17];
	ctx->vsp=local+24;
	w=(pointer)NREVERSE(ctx,1,local+23); /*nreverse*/
	local[23]= w;
	w = local[18];
	ctx->vsp=local+24;
	local[18] = cons(ctx,local[23],w);
	goto WHL4377;
WHX4378:
	local[23]= NIL;
BLK4379:
	w = NIL;
	local[21]= local[18];
	ctx->vsp=local+22;
	w=(pointer)NREVERSE(ctx,1,local+21); /*nreverse*/
	local[18] = w;
	local[21]= NIL;
	local[22]= local[18];
WHL4387:
	if (local[22]==NIL) goto WHX4388;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22] = (w)->c.cons.cdr;
	w = local[23];
	local[21] = w;
	local[23]= loadglobal(fqv[20]);
	ctx->vsp=local+24;
	w=(pointer)INSTANTIATE(ctx,1,local+23); /*instantiate*/
	local[23]= w;
	local[24]= local[23];
	local[25]= fqv[10];
	local[26]= fqv[17];
	local[27]= local[21];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,4,local+24); /*send*/
	w = local[23];
	local[23]= w;
	w = local[19];
	ctx->vsp=local+24;
	local[19] = cons(ctx,local[23],w);
	goto WHL4387;
WHX4388:
	local[23]= NIL;
BLK4389:
	w = NIL;
	local[21]= loadglobal(fqv[18]);
	ctx->vsp=local+22;
	w=(pointer)INSTANTIATE(ctx,1,local+21); /*instantiate*/
	local[21]= w;
	local[22]= local[21];
	local[23]= fqv[10];
	local[24]= fqv[17];
	local[25]= local[16];
	local[26]= fqv[24];
	local[27]= local[19];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,6,local+22); /*send*/
	w = local[21];
	local[21]= w;
	w = local[6];
	ctx->vsp=local+22;
	local[6] = cons(ctx,local[21],w);
	w = local[6];
	goto WHL4367;
WHX4368:
	local[16]= NIL;
BLK4369:
	w = NIL;
	local[14]= local[6];
	local[15]= (pointer)get_sym_func(fqv[25]);
	ctx->vsp=local+16;
	local[16]= makeclosure(codevec,quotevec,CLO4393,env,argv,local);
	ctx->vsp=local+17;
	w=(pointer)SORT(ctx,3,local+14); /*sort*/
	local[14]= NIL;
	local[15]= NIL;
	local[16]= NIL;
	local[17]= NIL;
	local[18]= NIL;
WHL4394:
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX4395;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[19];
	local[15] = w;
	local[14] = NIL;
WHL4399:
	if (local[6]==NIL) goto WHX4400;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[19];
	local[16] = w;
	storeglobal(fqv[26],local[15]);
	local[19]= local[16];
	storeglobal(fqv[27],local[19]);
	local[19]= local[15];
	local[20]= local[16];
	ctx->vsp=local+21;
	w=(*ftab[2])(ctx,2,local+19,&ftab[2],fqv[28]); /*face+*/
	local[17] = w;
	ctx->vsp=local+19;
	local[19]= makeclosure(codevec,quotevec,CLO4405,env,argv,local);
	local[20]= local[17];
	ctx->vsp=local+21;
	w=(*ftab[3])(ctx,2,local+19,&ftab[3],fqv[29]); /*member-if*/
	if (w==NIL) goto IF4403;
	local[19]= fqv[30];
	ctx->vsp=local+20;
	w=(*ftab[4])(ctx,1,local+19,&ftab[4],fqv[31]); /*break*/
	local[19]= w;
	goto IF4404;
IF4403:
	local[19]= loadglobal(fqv[16]);
	local[20]= local[17];
	ctx->vsp=local+21;
	w=(*ftab[5])(ctx,2,local+19,&ftab[5],fqv[32]); /*collect-instances*/
	local[17] = w;
	local[19]= local[17];
IF4404:
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr!=NIL) goto CON4407;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	w = local[14];
	ctx->vsp=local+20;
	local[14] = cons(ctx,local[19],w);
	local[19]= local[14];
	local[20]= local[6];
	ctx->vsp=local+21;
	w=(pointer)NCONC(ctx,2,local+19); /*nconc*/
	w = NIL;
	ctx->vsp=local+19;
	local[19]=w;
	goto BLK4398;
	goto CON4406;
CON4407:
	local[19]= local[16];
	w = local[14];
	ctx->vsp=local+20;
	local[14] = cons(ctx,local[19],w);
	local[19]= local[14];
	goto CON4406;
CON4408:
	local[19]= NIL;
CON4406:
	goto WHL4399;
WHX4400:
	local[19]= NIL;
BLK4401:
	local[19]= fqv[33];
	ctx->vsp=local+20;
	w=(pointer)SIGERROR(ctx,1,local+19); /*error*/
	local[19]= w;
BLK4398:
	local[6] = local[14];
	goto WHL4394;
WHX4395:
	local[19]= NIL;
BLK4396:
	w = local[19];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	ctx->vsp=local+15;
	unbindx(ctx,1);
	w = local[14];
	local[0]= w;
BLK4358:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4393(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[34];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4405(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[35]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*remove-inner-loop*/
static pointer F4314remove_inner_loop(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
WHL4411:
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX4412;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[3]= w;
	local[4]= NIL;
	local[5]= local[2];
WHL4416:
	if (local[5]==NIL) goto WHX4417;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[3];
	local[7]= local[3];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(*ftab[6])(ctx,2,local+7,&ftab[6],fqv[36]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w==NIL) goto OR4422;
	local[6]= local[3];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w==NIL) goto OR4422;
	local[6]= local[4];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(*ftab[7])(ctx,1,local+7,&ftab[7],fqv[37]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w==NIL) goto OR4422;
	goto IF4420;
OR4422:
	local[6]= local[3]->c.obj.iv[1];
	local[7]= local[3]->c.obj.iv[2];
	local[8]= local[4]->c.obj.iv[1];
	local[9]= local[4]->c.obj.iv[2];
	local[10]= makeflt(1.00000000e-03);
	ctx->vsp=local+11;
	w=(pointer)LINEINTERSECTION3(ctx,5,local+6); /*line-intersection3*/
	local[6]= w;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	if (local[6]==NIL) goto IF4423;
	local[9]= makeflt(0.00000000e+00);
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(*ftab[0])(ctx,2,local+9,&ftab[0],fqv[14]); /*eps<*/
	if (w==NIL) goto IF4423;
	local[9]= local[7];
	local[10]= makeflt(1.00000000e+00);
	ctx->vsp=local+11;
	w=(*ftab[0])(ctx,2,local+9,&ftab[0],fqv[14]); /*eps<*/
	if (w==NIL) goto IF4423;
	local[9]= makeflt(0.00000000e+00);
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(*ftab[0])(ctx,2,local+9,&ftab[0],fqv[14]); /*eps<*/
	if (w==NIL) goto IF4423;
	local[9]= local[8];
	local[10]= makeflt(1.00000000e+00);
	ctx->vsp=local+11;
	w=(*ftab[0])(ctx,2,local+9,&ftab[0],fqv[14]); /*eps<*/
	if (w==NIL) goto IF4423;
	local[9]= local[3];
	local[10]= local[4];
	local[11]= local[3];
	local[12]= fqv[38];
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[11]= w;
	local[12]= local[7];
	local[13]= local[8];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,5,local+9); /*list*/
	local[9]= w;
	w = local[0];
	ctx->vsp=local+10;
	local[0] = cons(ctx,local[9],w);
	local[9]= local[3];
	w = local[1];
	ctx->vsp=local+10;
	local[1] = cons(ctx,local[9],w);
	local[9]= local[4];
	w = local[1];
	ctx->vsp=local+10;
	local[1] = cons(ctx,local[9],w);
	local[9]= local[1];
	goto IF4424;
IF4423:
	local[9]= NIL;
IF4424:
	w = local[9];
	local[6]= w;
	goto IF4421;
IF4420:
	local[6]= NIL;
IF4421:
	goto WHL4416;
WHX4417:
	local[6]= NIL;
BLK4418:
	w = NIL;
	goto WHL4411;
WHX4412:
	local[3]= NIL;
BLK4413:
	w = local[3];
	local[2]= NIL;
	local[3]= local[0];
WHL4426:
	if (local[3]==NIL) goto WHX4427;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= local[4]->c.obj.iv[2];
	local[7]= local[4]->c.obj.iv[1];
	ctx->vsp=local+8;
	w=(pointer)VMINUS(ctx,2,local+6); /*v-*/
	local[6]= w;
	local[7]= local[5]->c.obj.iv[2];
	local[8]= local[5]->c.obj.iv[1];
	ctx->vsp=local+9;
	w=(pointer)VMINUS(ctx,2,local+7); /*v-*/
	local[7]= w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= NIL;
	local[10]= argv[1];
	local[11]= local[6];
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(pointer)SCA3PROD(ctx,3,local+10); /*v.**/
	local[10]= w;
	local[11]= makeint(0);
	ctx->vsp=local+12;
	w=(pointer)LESSP(ctx,2,local+10); /*<*/
	if (w==NIL) goto IF4430;
	local[10]= local[5];
	local[11]= local[4];
	local[4] = local[10];
	local[5] = local[11];
	w = NIL;
	local[10]= w;
	goto IF4431;
IF4430:
	local[10]= NIL;
IF4431:
	local[10]= local[4];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(*ftab[6])(ctx,2,local+10,&ftab[6],fqv[36]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	if (local[9]!=NIL) goto IF4434;
	local[9] = argv[0];
	local[10]= local[9];
	goto IF4435;
IF4434:
	local[10]= NIL;
IF4435:
WHL4436:
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	if (local[5]==local[10]) goto WHX4437;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(*ftab[6])(ctx,2,local+10,&ftab[6],fqv[36]); /*member*/
	if (w==NIL) goto IF4439;
	local[10]= fqv[39];
	ctx->vsp=local+11;
	w=(pointer)SIGERROR(ctx,1,local+10); /*error*/
	local[10]= w;
	goto IF4440;
IF4439:
	local[10]= NIL;
IF4440:
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= argv[0];
	local[12]= fqv[40];
	local[13]= makeint(1);
	ctx->vsp=local+14;
	w=(*ftab[8])(ctx,4,local+10,&ftab[8],fqv[41]); /*delete*/
	argv[0] = w;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	if (local[9]!=NIL) goto IF4441;
	local[9] = argv[0];
	local[10]= local[9];
	goto IF4442;
IF4441:
	local[10]= NIL;
IF4442:
	goto WHL4436;
WHX4437:
	local[10]= NIL;
BLK4438:
	local[10]= local[8];
	local[11]= local[10];
	w = local[4];
	w->c.obj.iv[2] = local[11];
	local[10]= local[8];
	local[11]= local[10];
	w = local[5];
	w->c.obj.iv[1] = local[11];
	w = local[10];
	goto WHL4426;
WHX4427:
	local[4]= NIL;
BLK4428:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK4409:
	ctx->vsp=local; return(local[0]);}

/*project-shadow*/
static pointer F4315project_shadow(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= fqv[13];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[1];
	local[7]= fqv[22];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= local[6];
	ctx->vsp=local+8;
	w=(pointer)VMINUS(ctx,1,local+7); /*v-*/
	local[7]= w;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= NIL;
	local[15]= NIL;
	local[16]= NIL;
	local[17]= local[2];
WHL4445:
	if (local[17]==NIL) goto WHX4446;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17] = (w)->c.cons.cdr;
	w = local[18];
	local[16] = w;
	local[18]= local[6];
	local[19]= local[16]->c.obj.iv[1];
	ctx->vsp=local+20;
	w=(pointer)VINNERPRODUCT(ctx,2,local+18); /*v.*/
	local[18]= w;
	local[19]= makeflt(0.00000000e+00);
	ctx->vsp=local+20;
	w=(*ftab[0])(ctx,2,local+18,&ftab[0],fqv[14]); /*eps<*/
	if (w==NIL) goto IF4449;
	local[18]= local[16];
	w = local[0];
	ctx->vsp=local+19;
	local[0] = cons(ctx,local[18],w);
	local[18]= local[0];
	goto IF4450;
IF4449:
	local[18]= local[16];
	w = local[1];
	ctx->vsp=local+19;
	local[1] = cons(ctx,local[18],w);
	local[18]= local[1];
IF4450:
	goto WHL4445;
WHX4446:
	local[18]= NIL;
BLK4447:
	w = NIL;
	local[16]= NIL;
	local[17]= argv[0];
	local[18]= fqv[19];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
WHL4452:
	if (local[17]==NIL) goto WHX4453;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17] = (w)->c.cons.cdr;
	w = local[18];
	local[16] = w;
	local[18]= local[16]->c.obj.iv[3];
	local[19]= local[16]->c.obj.iv[4];
	local[20]= local[18];
	local[21]= local[0];
	ctx->vsp=local+22;
	w=(*ftab[6])(ctx,2,local+20,&ftab[6],fqv[36]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	local[21]= local[19];
	local[22]= local[0];
	ctx->vsp=local+23;
	w=(*ftab[6])(ctx,2,local+21,&ftab[6],fqv[36]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	local[22]= NIL;
	if (local[20]==NIL) goto CON4457;
	if (local[21]!=NIL) goto CON4457;
	local[22] = local[20];
	local[23]= local[22];
	goto CON4456;
CON4457:
	if (local[20]!=NIL) goto CON4458;
	if (local[21]==NIL) goto CON4458;
	local[22] = local[21];
	local[23]= local[22];
	goto CON4456;
CON4458:
	local[22] = NIL;
	local[23]= local[22];
	goto CON4456;
CON4459:
	local[23]= NIL;
CON4456:
	if (local[22]==NIL) goto IF4460;
	local[23]= local[16];
	local[24]= local[22];
	ctx->vsp=local+25;
	w=(pointer)LIST(ctx,2,local+23); /*list*/
	local[23]= w;
	w = local[3];
	ctx->vsp=local+24;
	local[3] = cons(ctx,local[23],w);
	local[23]= local[3];
	goto IF4461;
IF4460:
	local[23]= NIL;
IF4461:
	w = local[23];
	goto WHL4452;
WHX4453:
	local[18]= NIL;
BLK4454:
	w = NIL;
	local[16]= NIL;
	local[17]= local[3];
WHL4463:
	if (local[17]==NIL) goto WHX4464;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17] = (w)->c.cons.cdr;
	w = local[18];
	local[16] = w;
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	local[19]= fqv[11];
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,3,local+18); /*send*/
	local[18]= w;
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	local[20]= fqv[12];
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,3,local+19); /*send*/
	local[19]= w;
	local[20]= local[18];
	local[21]= local[5];
	ctx->vsp=local+22;
	w=(*ftab[9])(ctx,2,local+20,&ftab[9],fqv[42]); /*assoc*/
	if (w!=NIL) goto IF4467;
	local[20]= local[18];
	local[21]= argv[1];
	local[22]= fqv[23];
	local[23]= local[18];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,3,local+21); /*send*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)LIST(ctx,2,local+20); /*list*/
	local[20]= w;
	w = local[5];
	ctx->vsp=local+21;
	local[5] = cons(ctx,local[20],w);
	local[20]= local[5];
	goto IF4468;
IF4467:
	local[20]= NIL;
IF4468:
	local[20]= local[19];
	local[21]= local[5];
	ctx->vsp=local+22;
	w=(*ftab[9])(ctx,2,local+20,&ftab[9],fqv[42]); /*assoc*/
	if (w!=NIL) goto IF4469;
	local[20]= local[19];
	local[21]= argv[1];
	local[22]= fqv[23];
	local[23]= local[19];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,3,local+21); /*send*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)LIST(ctx,2,local+20); /*list*/
	local[20]= w;
	w = local[5];
	ctx->vsp=local+21;
	local[5] = cons(ctx,local[20],w);
	local[20]= local[5];
	goto IF4470;
IF4469:
	local[20]= NIL;
IF4470:
	w = local[20];
	goto WHL4463;
WHX4464:
	local[18]= NIL;
BLK4465:
	w = NIL;
	local[16]= NIL;
	local[17]= local[3];
WHL4472:
	if (local[17]==NIL) goto WHX4473;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17] = (w)->c.cons.cdr;
	w = local[18];
	local[16] = w;
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	local[19]= fqv[11];
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,3,local+18); /*send*/
	local[18]= w;
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	local[20]= fqv[12];
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,3,local+19); /*send*/
	local[19]= w;
	local[20]= loadglobal(fqv[9]);
	ctx->vsp=local+21;
	w=(pointer)INSTANTIATE(ctx,1,local+20); /*instantiate*/
	local[20]= w;
	local[21]= local[20];
	local[22]= fqv[10];
	local[23]= fqv[11];
	local[24]= local[18];
	local[25]= local[5];
	ctx->vsp=local+26;
	w=(*ftab[9])(ctx,2,local+24,&ftab[9],fqv[42]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24]= (w)->c.cons.car;
	local[25]= fqv[12];
	local[26]= local[19];
	local[27]= local[5];
	ctx->vsp=local+28;
	w=(*ftab[9])(ctx,2,local+26,&ftab[9],fqv[42]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,6,local+21); /*send*/
	w = local[20];
	local[20]= w;
	w = local[8];
	ctx->vsp=local+21;
	local[8] = cons(ctx,local[20],w);
	w = local[8];
	goto WHL4472;
WHX4473:
	local[18]= NIL;
BLK4474:
	w = NIL;
WHL4477:
	if (local[8]==NIL) goto WHX4478;
	local[13] = NIL;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[16];
	local[11] = w;
	local[16]= local[11];
	w = local[13];
	ctx->vsp=local+17;
	local[13] = cons(ctx,local[16],w);
	local[11] = local[11]->c.obj.iv[2];
WHL4481:
	ctx->vsp=local+16;
	local[16]= makeclosure(codevec,quotevec,CLO4484,env,argv,local);
	local[17]= local[8];
	ctx->vsp=local+18;
	w=(*ftab[10])(ctx,2,local+16,&ftab[10],fqv[43]); /*find-if*/
	local[12] = w;
	if (local[12]==NIL) goto WHX4482;
	local[16]= local[12];
	local[17]= local[8];
	local[18]= fqv[40];
	local[19]= makeint(1);
	ctx->vsp=local+20;
	w=(*ftab[8])(ctx,4,local+16,&ftab[8],fqv[41]); /*delete*/
	local[8] = w;
	local[11] = local[12]->c.obj.iv[2];
	local[16]= local[12];
	w = local[13];
	ctx->vsp=local+17;
	local[13] = cons(ctx,local[16],w);
	goto WHL4481;
WHX4482:
	local[16]= NIL;
BLK4483:
	local[16]= local[13];
	ctx->vsp=local+17;
	w=(pointer)NREVERSE(ctx,1,local+16); /*nreverse*/
	local[16]= w;
	w = local[4];
	ctx->vsp=local+17;
	local[4] = cons(ctx,local[16],w);
	goto WHL4477;
WHX4478:
	local[16]= NIL;
BLK4479:
	local[16]= local[4];
	ctx->vsp=local+17;
	w=(pointer)NREVERSE(ctx,1,local+16); /*nreverse*/
	local[4] = w;
	local[16]= NIL;
	local[17]= local[4];
WHL4486:
	if (local[17]==NIL) goto WHX4487;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17] = (w)->c.cons.cdr;
	w = local[18];
	local[16] = w;
	local[18]= local[16];
	local[19]= local[6];
	ctx->vsp=local+20;
	w=(pointer)F4314remove_inner_loop(ctx,2,local+18); /*remove-inner-loop*/
	local[18]= w;
	w = local[9];
	ctx->vsp=local+19;
	local[9] = cons(ctx,local[18],w);
	goto WHL4486;
WHX4487:
	local[18]= NIL;
BLK4488:
	w = NIL;
	local[4] = local[9];
	local[16]= local[4];
	storeglobal(fqv[44],local[16]);
	local[14] = NIL;
	local[15] = NIL;
	local[16]= NIL;
	local[17]= local[4];
WHL4491:
	if (local[17]==NIL) goto WHX4492;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17] = (w)->c.cons.cdr;
	w = local[18];
	local[16] = w;
	local[18]= local[16];
	ctx->vsp=local+19;
	w=(pointer)F4311make_face_from_edge_loop(ctx,1,local+18); /*make-face-from-edge-loop*/
	local[18]= w;
	local[19]= local[6];
	local[20]= local[18];
	local[21]= fqv[22];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,2,local+20); /*send*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)VINNERPRODUCT(ctx,2,local+19); /*v.*/
	local[19]= w;
	{ double left,right;
		right=fltval(makeflt(0.00000000e+00)); left=fltval(local[19]);
	if (left >= right) goto IF4495;}
	local[19]= local[18];
	w = local[15];
	ctx->vsp=local+20;
	local[15] = cons(ctx,local[19],w);
	local[19]= local[15];
	goto IF4496;
IF4495:
	local[19]= local[18];
	ctx->vsp=local+20;
	w=(pointer)F4312change_to_hole(ctx,1,local+19); /*change-to-hole*/
	local[19]= w;
	w = local[14];
	ctx->vsp=local+20;
	local[14] = cons(ctx,local[19],w);
	local[19]= local[14];
IF4496:
	w = local[19];
	goto WHL4491;
WHX4492:
	local[18]= NIL;
BLK4493:
	w = NIL;
	local[16]= NIL;
	local[17]= local[14];
WHL4498:
	if (local[17]==NIL) goto WHX4499;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17] = (w)->c.cons.cdr;
	w = local[18];
	local[16] = w;
	local[18]= NIL;
	local[19]= local[15];
WHL4504:
	if (local[19]==NIL) goto WHX4505;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19] = (w)->c.cons.cdr;
	w = local[20];
	local[18] = w;
	ctx->vsp=local+20;
	local[20]= makeclosure(codevec,quotevec,CLO4510,env,argv,local);
	local[21]= local[16];
	local[22]= fqv[17];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,2,local+21); /*send*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(*ftab[11])(ctx,2,local+20,&ftab[11],fqv[45]); /*every*/
	if (w==NIL) goto IF4508;
	local[20]= local[18];
	local[21]= fqv[46];
	local[22]= local[16];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= local[16];
	local[21]= fqv[47];
	local[22]= local[18];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	w = NIL;
	ctx->vsp=local+20;
	local[18]=w;
	goto BLK4502;
	goto IF4509;
IF4508:
	local[20]= NIL;
IF4509:
	goto WHL4504;
WHX4505:
	local[20]= NIL;
BLK4506:
	w = NIL;
	local[18]= w;
BLK4502:
	goto WHL4498;
WHX4499:
	local[18]= NIL;
BLK4500:
	w = NIL;
	local[10] = local[15];
	local[16]= local[10];
	ctx->vsp=local+17;
	w=(pointer)COPYSEQ(ctx,1,local+16); /*copy-seq*/
	local[16]= w;
	storeglobal(fqv[48],w);
	local[16]= NIL;
	local[17]= NIL;
	local[18]= NIL;
	local[19]= NIL;
	local[20]= NIL;
WHL4511:
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX4512;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[21];
	local[17] = w;
	local[16] = NIL;
WHL4516:
	if (local[10]==NIL) goto WHX4517;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[21];
	local[18] = w;
	storeglobal(fqv[26],local[17]);
	local[21]= local[18];
	storeglobal(fqv[27],local[21]);
	local[21]= local[17];
	local[22]= local[18];
	ctx->vsp=local+23;
	w=(*ftab[2])(ctx,2,local+21,&ftab[2],fqv[28]); /*face+*/
	local[19] = w;
	ctx->vsp=local+21;
	local[21]= makeclosure(codevec,quotevec,CLO4522,env,argv,local);
	local[22]= local[19];
	ctx->vsp=local+23;
	w=(*ftab[3])(ctx,2,local+21,&ftab[3],fqv[29]); /*member-if*/
	if (w==NIL) goto IF4520;
	local[21]= fqv[49];
	ctx->vsp=local+22;
	w=(*ftab[4])(ctx,1,local+21,&ftab[4],fqv[31]); /*break*/
	local[21]= w;
	goto IF4521;
IF4520:
	local[21]= loadglobal(fqv[16]);
	local[22]= local[19];
	ctx->vsp=local+23;
	w=(*ftab[5])(ctx,2,local+21,&ftab[5],fqv[32]); /*collect-instances*/
	local[19] = w;
	local[21]= local[19];
IF4521:
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr!=NIL) goto CON4524;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w = local[16];
	ctx->vsp=local+22;
	local[16] = cons(ctx,local[21],w);
	local[21]= local[16];
	local[22]= local[10];
	ctx->vsp=local+23;
	w=(pointer)NCONC(ctx,2,local+21); /*nconc*/
	w = NIL;
	ctx->vsp=local+21;
	local[21]=w;
	goto BLK4515;
	goto CON4523;
CON4524:
	local[21]= local[18];
	w = local[16];
	ctx->vsp=local+22;
	local[16] = cons(ctx,local[21],w);
	local[21]= local[16];
	goto CON4523;
CON4525:
	local[21]= NIL;
CON4523:
	goto WHL4516;
WHX4517:
	local[21]= NIL;
BLK4518:
	local[21]= fqv[50];
	ctx->vsp=local+22;
	w=(pointer)SIGERROR(ctx,1,local+21); /*error*/
	local[21]= w;
BLK4515:
	local[10] = local[16];
	goto WHL4511;
WHX4512:
	local[21]= NIL;
BLK4513:
	w = local[21];
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK4443:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4484(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	w = ((env->c.clo.env2[11])==(local[0])?T:NIL);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4510(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env2[18];
	local[1]= fqv[51];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[52];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4522(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[35]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*shadow-intersection*/
static pointer F4316shadow_intersection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F4315project_shadow(ctx,2,local+0); /*project-shadow*/
	local[0]= w;
	local[1]= argv[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)F4315project_shadow(ctx,2,local+1); /*project-shadow*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[12])(ctx,2,local+0,&ftab[12],fqv[53]); /*face**/
	local[0]= w;
BLK4526:
	ctx->vsp=local; return(local[0]);}

/*closest-shadow*/
static pointer F4317closest_shadow(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= fqv[54];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= argv[1];
	local[3]= fqv[22];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)VMINUS(ctx,1,local+3); /*v-*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= argv[1];
	local[8]= fqv[55];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= NIL;
	w = NIL;
	local[0]= w;
BLK4527:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___shadow(ctx,n,argv,env)
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
	local[0]= fqv[56];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF4528;
	local[0]= fqv[57];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[58],w);
	goto IF4529;
IF4528:
	local[0]= fqv[59];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF4529:
	local[0]= fqv[60];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compmacro(ctx,fqv[61],module,F4318,fqv[62]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[63],module,F4307polygon_in_contact_p,fqv[64]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[65],module,F4308make_edges_from_vertices,fqv[66]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[67],module,F4309orthogonally_visible_faces,fqv[68]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[69],module,F4310make_polygon,fqv[70]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[71],module,F4311make_face_from_edge_loop,fqv[72]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[73],module,F4312change_to_hole,fqv[74]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[75],module,F4313project_shadow1,fqv[76]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[77],module,F4314remove_inner_loop,fqv[78]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[79],module,F4315project_shadow,fqv[80]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[81],module,F4316shadow_intersection,fqv[82]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[83],module,F4317closest_shadow,fqv[84]);
	local[0]= fqv[85];
	local[1]= fqv[86];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,2,local+0,&ftab[13],fqv[87]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<14; i++) ftab[i]=fcallx;
}
