/* ./hid.c :  entry=hid */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "hid.h"
#pragma init (register_hid)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___hid();
extern pointer build_quote_vector();
static int register_hid()
  { add_module_initializer("___hid", ___hid);}

static pointer F3183check_visibility();
static pointer F3185make_face_image();
static pointer F3186set_contour_intersections();
static pointer F3187set_non_contour_intersections();
static pointer F3188curved_edge_image_p();
static pointer F3189hid2();

/*check-visibility*/
static pointer F3183check_visibility(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= NIL;
	local[1]= makeflt(0.00000000e+00);
	w = local[1];
	ctx->vsp=local+2;
	bindspecial(ctx,fqv[0],w);
	local[5]= NIL;
	local[6]= loadglobal(fqv[1]);
WHL3193:
	if (local[6]==NIL) goto WHX3194;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[0] = local[5]->c.obj.iv[2];
	local[7]= local[0];
	if (argv[0]==local[7]) goto IF3197;
	local[7]= local[0];
	if (argv[1]==local[7]) goto IF3197;
	local[7]= local[5];
	local[8]= fqv[2];
	local[9]= argv[3];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	if (w==NIL) goto IF3197;
	local[7]= local[0];
	local[8]= fqv[3];
	local[9]= argv[2];
	local[10]= argv[4];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	if (w==NIL) goto IF3197;
	w = NIL;
	ctx->vsp=local+7;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK3191;
	goto IF3198;
IF3197:
	local[7]= NIL;
IF3198:
	goto WHL3193;
WHX3194:
	local[7]= NIL;
BLK3195:
	w = NIL;
	local[5]= T;
	ctx->vsp=local+6;
	unbindx(ctx,1);
	w = local[5];
	local[0]= w;
BLK3191:
	ctx->vsp=local; return(local[0]);}

/*:edge3*/
static pointer M3200edge_image_edge3(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[0];
	local[0]= w;
BLK3201:
	ctx->vsp=local; return(local[0]);}

/*:vertices*/
static pointer M3202edge_image_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
BLK3203:
	ctx->vsp=local; return(local[0]);}

/*:color*/
static pointer M3204edge_image_color(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[4];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK3205:
	ctx->vsp=local; return(local[0]);}

/*:homo2real*/
static pointer M3206edge_image_homo2real(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	{ register eusinteger_t i=intval(makeint(3));
	  w=makeflt(local[1]->c.fvec.fv[i]);}
	{ double x,y;
		y=fltval(w); x=fltval(local[0]);
		local[0]=(makeflt(x * y));}
	local[1]= local[0];
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[2];
	{ register eusinteger_t i=intval(makeint(3));
	  w=makeflt(local[3]->c.fvec.fv[i]);}
	local[3]= w;
	local[4]= makeflt(1.00000000e+00);
	{ double x,y;
		y=fltval(argv[2]); x=fltval(local[4]);
		local[4]=(makeflt(x - y));}
	{ double x,y;
		y=fltval(local[4]); x=fltval(local[3]);
		local[3]=(makeflt(x * y));}
	{ double x,y;
		y=fltval(local[3]); x=fltval(local[2]);
		local[2]=(makeflt(x + y));}
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[0]= w;
BLK3207:
	ctx->vsp=local; return(local[0]);}

/*:add-segment*/
static pointer M3208edge_image_add_segment(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3211;}
	local[0]= NIL;
ENT3211:
ENT3210:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[1];
	{ register eusinteger_t i=intval(makeint(3));
	  w=makeflt(local[2]->c.fvec.fv[i]);}
	{ double x,y;
		y=fltval(w); x=fltval(local[1]);
		local[1]=(makeflt(x * y));}
	local[2]= local[1];
	local[3]= local[1];
	local[4]= argv[0]->c.obj.iv[2];
	{ register eusinteger_t i=intval(makeint(3));
	  w=makeflt(local[4]->c.fvec.fv[i]);}
	local[4]= w;
	local[5]= makeflt(1.00000000e+00);
	{ double x,y;
		y=fltval(makeflt(-(fltval(argv[2])))); x=fltval(local[5]);
		local[5]=(makeflt(x + y));}
	{ double x,y;
		y=fltval(local[5]); x=fltval(local[4]);
		local[4]=(makeflt(x * y));}
	{ double x,y;
		y=fltval(local[4]); x=fltval(local[3]);
		local[3]=(makeflt(x + y));}
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[1] = w;
	local[2]= local[1];
	{ double left,right;
		right=fltval(makeflt(0.00000000e+00)); left=fltval(local[2]);
	if (left < right) goto IF3212;}
	local[2]= local[1];
	{ double left,right;
		right=fltval(makeflt(1.00000000e+00)); left=fltval(local[2]);
	if (left > right) goto IF3212;}
	local[2]= argv[2];
	local[3]= local[1];
	local[4]= T;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	w = argv[0]->c.obj.iv[5];
	ctx->vsp=local+3;
	argv[0]->c.obj.iv[5] = cons(ctx,local[2],w);
	local[2]= argv[0]->c.obj.iv[5];
	goto IF3213;
IF3212:
	local[2]= NIL;
IF3213:
	w = local[2];
	local[0]= w;
BLK3209:
	ctx->vsp=local; return(local[0]);}

/*:projected-point*/
static pointer M3214edge_image_projected_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeflt(1.00000000e+00);
	{ double x,y;
		y=fltval(argv[2]); x=fltval(local[0]);
		local[0]=(makeflt(x - y));}
	local[1]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+2;
	w=(pointer)SCALEVEC(ctx,2,local+0); /*scale*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,2,local+1); /*scale*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VPLUS(ctx,2,local+0); /*v+*/
	local[0]= w;
BLK3215:
	ctx->vsp=local; return(local[0]);}

/*:projected-homo-point*/
static pointer M3216edge_image_projected_homo_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeflt(1.00000000e+00);
	{ double x,y;
		y=fltval(argv[2]); x=fltval(local[0]);
		local[0]=(makeflt(x - y));}
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)SCALEVEC(ctx,2,local+0); /*scale*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,2,local+1); /*scale*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VPLUS(ctx,2,local+0); /*v+*/
	local[0]= w;
BLK3217:
	ctx->vsp=local; return(local[0]);}

/*:intersecting-point*/
static pointer M3218edge_image_intersecting_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= argv[0]->c.obj.iv[4];
	local[2]= argv[2]->c.obj.iv[3];
	local[3]= argv[2]->c.obj.iv[4];
	local[4]= T;
	ctx->vsp=local+5;
	w=(pointer)LINEINTERSECTION(ctx,5,local+0); /*line-intersection*/
	local[0]= w;
	if (local[0]==NIL) goto IF3220;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[5];
	local[3]= argv[0];
	local[4]= fqv[6];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF3221;
IF3220:
	local[1]= NIL;
IF3221:
	w = local[1];
	local[0]= w;
BLK3219:
	ctx->vsp=local; return(local[0]);}

/*:projected-intersection*/
static pointer M3222edge_image_projected_intersection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= argv[0]->c.obj.iv[4];
	local[2]= argv[2]->c.obj.iv[3];
	local[3]= argv[2]->c.obj.iv[4];
	local[4]= T;
	ctx->vsp=local+5;
	w=(pointer)LINEINTERSECTION(ctx,5,local+0); /*line-intersection*/
	local[0]= w;
	if (local[0]==NIL) goto IF3224;
	local[1]= argv[0];
	local[2]= fqv[7];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	if (argv[3]==NIL) goto IF3226;
	local[1]= argv[2];
	local[2]= fqv[7];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF3227;
IF3226:
	local[1]= NIL;
IF3227:
	goto IF3225;
IF3224:
	local[1]= NIL;
IF3225:
	w = local[1];
	local[0]= w;
BLK3223:
	ctx->vsp=local; return(local[0]);}

/*:sort-segments*/
static pointer M3228edge_image_sort_segments(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= (pointer)get_sym_func(fqv[8]);
	local[2]= (pointer)get_sym_func(fqv[9]);
	ctx->vsp=local+3;
	w=(pointer)SORT(ctx,3,local+0); /*sort*/
	argv[0]->c.obj.iv[5] = w;
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK3229:
	ctx->vsp=local; return(local[0]);}

/*:box*/
static pointer M3230edge_image_box(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[10]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[11];
	local[3]= argv[0]->c.obj.iv[3];
	local[4]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK3231:
	ctx->vsp=local; return(local[0]);}

/*:contourp*/
static pointer M3233edge_image_contourp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK3234:
	ctx->vsp=local; return(local[0]);}

/*:mark-visible-segments*/
static pointer M3235edge_image_mark_visible_segments(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[0]->c.obj.iv[3];
	local[5]= argv[0]->c.obj.iv[0]->c.obj.iv[4];
	local[6]= NIL;
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
WHL3238:
	if (local[7]==NIL) goto WHX3239;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= argv[0];
	local[9]= fqv[12];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	{ double x,y;
		y=fltval((w)->c.cons.car); x=fltval(local[10]);
		local[10]=(makeflt(x + y));}
	local[11]= makeflt(2.00000000e+00);
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[3] = w;
	local[8]= argv[0]->c.obj.iv[0];
	local[9]= fqv[5];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	{ double x,y;
		y=fltval((w)->c.cons.car); x=fltval(local[10]);
		local[10]=(makeflt(x + y));}
	local[11]= makeflt(2.00000000e+00);
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[1] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.cdr;
	local[9]= local[4];
	local[10]= local[5];
	local[11]= local[1];
	local[12]= local[3];
	local[13]= argv[2];
	ctx->vsp=local+14;
	w=(pointer)F3183check_visibility(ctx,5,local+9); /*check-visibility*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)RPLACA2(ctx,2,local+8); /*rplaca2*/
	local[0] = local[6];
	goto WHL3238;
WHX3239:
	local[8]= NIL;
BLK3240:
	w = NIL;
	local[0]= w;
BLK3236:
	ctx->vsp=local; return(local[0]);}

/*:visible-face*/
static pointer M3242edge_image_visible_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0]->c.obj.iv[3];
	local[1]= argv[0]->c.obj.iv[0]->c.obj.iv[4];
	local[2]= local[0];
	w = loadglobal(fqv[13]);
	if (memq(local[2],w)==NIL) goto IF3244;
	local[2]= local[0];
	goto IF3245;
IF3244:
	local[2]= local[1];
IF3245:
	w = local[2];
	local[0]= w;
BLK3243:
	ctx->vsp=local; return(local[0]);}

/*:collect-segments*/
static pointer M3246edge_image_collect_segments(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.cdr;
WHL3249:
	if (local[6]==NIL) goto WHX3250;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	if (argv[2]!=local[7]) goto IF3253;
	local[7]= argv[0];
	local[8]= fqv[14];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[2] = w;
	local[7]= argv[0];
	local[8]= fqv[14];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[3] = w;
	local[7]= local[2];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)HOMO_VPCLIP(ctx,2,local+7); /*homo-viewport-clip*/
	local[4] = w;
	if (local[4]==NIL) goto IF3255;
	local[7]= local[4];
	w = local[0];
	ctx->vsp=local+8;
	local[0] = cons(ctx,local[7],w);
	local[7]= local[0];
	goto IF3256;
IF3255:
	local[7]= NIL;
IF3256:
	goto IF3254;
IF3253:
	local[7]= NIL;
IF3254:
	local[1] = local[5];
	goto WHL3249;
WHX3250:
	local[7]= NIL;
BLK3251:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK3247:
	ctx->vsp=local; return(local[0]);}

/*:visible-segments*/
static pointer M3257edge_image_visible_segments(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= T;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3258:
	ctx->vsp=local; return(local[0]);}

/*:invisible-segments*/
static pointer M3259edge_image_invisible_segments(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= NIL;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3260:
	ctx->vsp=local; return(local[0]);}

/*:project*/
static pointer M3261edge_image_project(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT3264;}
	local[0]= argv[3];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
ENT3264:
ENT3263:
	if (n>5) maerror();
	argv[0]->c.obj.iv[0] = argv[2];
	local[1]= argv[3];
	local[2]= fqv[17];
	local[3]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[0]->c.obj.iv[1] = w;
	local[1]= argv[3];
	local[2]= fqv[17];
	local[3]= argv[2]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[0]->c.obj.iv[2] = w;
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)HOMO2NORMAL(ctx,1,local+1); /*homo2normal*/
	argv[0]->c.obj.iv[3] = w;
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)HOMO2NORMAL(ctx,1,local+1); /*homo2normal*/
	argv[0]->c.obj.iv[4] = w;
	local[1]= makeflt(0.00000000e+00);
	local[2]= makeflt(0.00000000e+00);
	local[3]= T;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[1]= w;
	local[2]= makeflt(1.00000000e+00);
	local[3]= makeflt(1.00000000e+00);
	local[4]= T;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,3,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	argv[0]->c.obj.iv[5] = w;
	local[1]= argv[2];
	local[2]= fqv[18];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[0]->c.obj.iv[6] = w;
	w = argv[0];
	local[0]= w;
BLK3262:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3265edge_image_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[19], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY3267;
	local[0] = NIL;
KEY3267:
	if (n & (1<<1)) goto KEY3268;
	local[1] = NIL;
KEY3268:
	if (n & (1<<2)) goto KEY3269;
	local[2] = NIL;
KEY3269:
	if (n & (1<<3)) goto KEY3270;
	local[3] = NIL;
KEY3270:
	if (n & (1<<4)) goto KEY3271;
	local[4] = NIL;
KEY3271:
	if (local[0]==NIL) goto IF3272;
	argv[0]->c.obj.iv[0] = local[0];
	local[5]= argv[0]->c.obj.iv[0];
	goto IF3273;
IF3272:
	local[5]= NIL;
IF3273:
	if (local[1]==NIL) goto IF3274;
	argv[0]->c.obj.iv[1] = local[1];
	local[5]= argv[0]->c.obj.iv[1];
	goto IF3275;
IF3274:
	local[5]= NIL;
IF3275:
	if (local[2]==NIL) goto IF3276;
	argv[0]->c.obj.iv[2] = local[2];
	local[5]= argv[0]->c.obj.iv[2];
	goto IF3277;
IF3276:
	local[5]= NIL;
IF3277:
	if (local[3]==NIL) goto IF3278;
	argv[0]->c.obj.iv[3] = local[3];
	local[5]= argv[0]->c.obj.iv[3];
	goto IF3279;
IF3278:
	local[5]= NIL;
IF3279:
	if (local[4]==NIL) goto IF3280;
	argv[0]->c.obj.iv[4] = local[4];
	local[5]= argv[0]->c.obj.iv[4];
	goto IF3281;
IF3280:
	local[5]= NIL;
IF3281:
	w = argv[0];
	local[0]= w;
BLK3266:
	ctx->vsp=local; return(local[0]);}

/*:face3d*/
static pointer M3282face_image_face3d(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK3283:
	ctx->vsp=local; return(local[0]);}

/*:possibly-hiding*/
static pointer M3284face_image_possibly_hiding(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[20];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3285:
	ctx->vsp=local; return(local[0]);}

/*:boxtest*/
static pointer M3286face_image_boxtest(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[21];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3287:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3288face_image_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[3];
WHL3291:
	if (local[2]==NIL) goto WHX3292;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	if (local[1]==NIL) goto IF3295;
	local[3]= local[1];
	local[4]= fqv[22];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	local[3]= local[0];
	goto IF3296;
IF3295:
	local[3]= NIL;
IF3296:
	goto WHL3291;
WHX3292:
	local[3]= NIL;
BLK3293:
	w = NIL;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[23]); /*flatten*/
	local[0] = w;
	argv[0]->c.obj.iv[2] = argv[2];
	argv[0]->c.obj.iv[1] = argv[3];
	local[1]= loadglobal(fqv[10]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[24];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	w = local[1];
	argv[0]->c.obj.iv[0] = w;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[25];
	local[3]= makeflt(1.00000000e-02);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[0]->c.obj.iv[1];
	local[2]= makeint(2);
	local[3]= makeflt(1.00000000e+20);
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,3,local+1); /*aset*/
	w = argv[0];
	local[0]= w;
BLK3289:
	ctx->vsp=local; return(local[0]);}

/*make-face-image*/
static pointer F3185make_face_image(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= loadglobal(fqv[26]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[24];
	local[3]= argv[0];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO3300,env,argv,local);
	local[5]= argv[0];
	local[6]= fqv[27];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[4]= w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK3298:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3300(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env1[1];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[28]); /*gethash*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*set-contour-intersections*/
static pointer F3186set_contour_intersections(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
WHL3302:
	if (argv[0]==NIL) goto WHX3303;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[0];
	local[0]= w;
	local[1]= local[0]->c.obj.iv[0];
	local[2]= local[1]->c.obj.iv[3];
	local[3]= local[1]->c.obj.iv[4];
	if (local[2]==NIL) goto IF3306;
	local[4]= local[2]->c.obj.iv[4];
	goto IF3307;
IF3306:
	local[4]= NIL;
IF3307:
	if (local[3]==NIL) goto IF3308;
	local[5]= local[3]->c.obj.iv[4];
	goto IF3309;
IF3308:
	local[5]= NIL;
IF3309:
	local[6]= NIL;
	local[7]= argv[0];
WHL3311:
	if (local[7]==NIL) goto WHX3312;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6]->c.obj.iv[0];
	w = local[4];
	if (memq(local[8],w)!=NIL) goto IF3315;
	local[8]= local[6]->c.obj.iv[0];
	w = local[5];
	if (memq(local[8],w)!=NIL) goto IF3315;
	local[8]= local[0];
	local[9]= fqv[29];
	local[10]= local[6];
	local[11]= T;
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= w;
	goto IF3316;
IF3315:
	local[8]= NIL;
IF3316:
	goto WHL3311;
WHX3312:
	local[8]= NIL;
BLK3313:
	w = NIL;
	goto WHL3302;
WHX3303:
	local[0]= NIL;
BLK3304:
	w = local[0];
	local[0]= w;
BLK3301:
	ctx->vsp=local; return(local[0]);}

/*set-non-contour-intersections*/
static pointer F3187set_non_contour_intersections(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0];
WHL3319:
	if (local[1]==NIL) goto WHX3320;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0]->c.obj.iv[0];
	local[3]= local[2]->c.obj.iv[3];
	local[4]= local[2]->c.obj.iv[4];
	if (local[3]==NIL) goto IF3323;
	local[5]= local[3]->c.obj.iv[4];
	goto IF3324;
IF3323:
	local[5]= NIL;
IF3324:
	if (local[4]==NIL) goto IF3325;
	local[6]= local[4]->c.obj.iv[4];
	goto IF3326;
IF3325:
	local[6]= NIL;
IF3326:
	local[7]= NIL;
	local[8]= argv[1];
WHL3328:
	if (local[8]==NIL) goto WHX3329;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[7]->c.obj.iv[0];
	w = local[5];
	if (memq(local[9],w)!=NIL) goto IF3332;
	local[9]= local[7]->c.obj.iv[0];
	w = local[6];
	if (memq(local[9],w)!=NIL) goto IF3332;
	local[9]= local[0];
	local[10]= fqv[29];
	local[11]= local[7];
	local[12]= NIL;
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,4,local+9); /*send*/
	local[9]= w;
	goto IF3333;
IF3332:
	local[9]= NIL;
IF3333:
	goto WHL3328;
WHX3329:
	local[9]= NIL;
BLK3330:
	w = NIL;
	goto WHL3319;
WHX3320:
	local[2]= NIL;
BLK3321:
	w = NIL;
	local[0]= w;
BLK3317:
	ctx->vsp=local; return(local[0]);}

/*curved-edge-image-p*/
static pointer F3188curved_edge_image_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[30]);
	if (local[0]==NIL) goto AND3335;
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[31];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
AND3335:
	w = local[0];
	local[0]= w;
BLK3334:
	ctx->vsp=local; return(local[0]);}

/*hid2*/
static pointer F3189hid2(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3338;}
	local[0]= NIL;
ENT3338:
ENT3337:
	if (n>3) maerror();
	local[1]= fqv[32];
	local[2]= makeint(100);
	local[3]= fqv[33];
	local[4]= (pointer)get_sym_func(fqv[34]);
	local[5]= fqv[35];
	local[6]= (pointer)get_sym_func(fqv[36]);
	ctx->vsp=local+7;
	w=(*ftab[2])(ctx,6,local+1,&ftab[2],fqv[37]); /*make-hash-table*/
	local[1]= w;
	local[2]= argv[1];
	local[3]= fqv[16];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)RUNTIME(ctx,0,local+3); /*unix:runtime*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	storeglobal(fqv[13],NIL);
	storeglobal(fqv[1],NIL);
	storeglobal(fqv[38],NIL);
	storeglobal(fqv[39],NIL);
	storeglobal(fqv[40],NIL);
	storeglobal(fqv[41],NIL);
	storeglobal(fqv[42],NIL);
	local[8]= NIL;
	storeglobal(fqv[43],local[8]);
	local[8]= NIL;
	local[9]= argv[0];
WHL3340:
	if (local[9]==NIL) goto WHX3341;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= local[8];
	local[13]= loadglobal(fqv[44]);
	ctx->vsp=local+14;
	w=(pointer)DERIVEDP(ctx,2,local+12); /*derivedp*/
	if (w==NIL) goto IF3344;
	local[12]= local[8];
	local[13]= fqv[45];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[12]= w;
	goto IF3345;
IF3344:
	local[12]= NIL;
IF3345:
	local[12]= NIL;
	local[13]= local[8];
	local[14]= loadglobal(fqv[44]);
	ctx->vsp=local+15;
	w=(pointer)DERIVEDP(ctx,2,local+13); /*derivedp*/
	if (w==NIL) goto IF3347;
	local[13]= local[8];
	local[14]= fqv[46];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	local[13]= w;
	goto IF3348;
IF3347:
	local[13]= local[8];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	local[13]= w;
IF3348:
WHL3349:
	if (local[13]==NIL) goto WHX3350;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13] = (w)->c.cons.cdr;
	w = local[14];
	local[12] = w;
	local[14]= local[12];
	local[15]= fqv[47];
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[14]= w;
	local[15]= makeflt(0.00000000e+00);
	ctx->vsp=local+16;
	w=(pointer)GREATERP(ctx,2,local+14); /*>*/
	if (w==NIL) goto IF3353;
	local[14]= local[12];
	w = local[10];
	ctx->vsp=local+15;
	local[10] = cons(ctx,local[14],w);
	local[14]= local[10];
	goto IF3354;
IF3353:
	local[14]= NIL;
IF3354:
	goto WHL3349;
WHX3350:
	local[14]= NIL;
BLK3351:
	w = NIL;
	local[12]= (pointer)get_sym_func(fqv[48]);
	local[13]= local[10];
	local[14]= fqv[49];
	ctx->vsp=local+15;
	w=(*ftab[3])(ctx,2,local+13,&ftab[3],fqv[50]); /*send-all*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)APPLY(ctx,2,local+12); /*apply*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(*ftab[4])(ctx,1,local+12,&ftab[4],fqv[51]); /*remove-duplicates*/
	local[11] = w;
	local[12]= loadglobal(fqv[39]);
	local[13]= local[8];
	local[14]= fqv[49];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	local[13]= w;
	local[14]= local[11];
	ctx->vsp=local+15;
	w=(*ftab[5])(ctx,2,local+13,&ftab[5],fqv[52]); /*set-difference*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)NCONC(ctx,2,local+12); /*nconc*/
	storeglobal(fqv[39],w);
	local[12]= local[11];
	local[13]= loadglobal(fqv[38]);
	ctx->vsp=local+14;
	w=(pointer)NCONC(ctx,2,local+12); /*nconc*/
	storeglobal(fqv[38],w);
	local[12]= local[10];
	local[13]= loadglobal(fqv[13]);
	ctx->vsp=local+14;
	w=(pointer)NCONC(ctx,2,local+12); /*nconc*/
	local[12]= w;
	storeglobal(fqv[13],w);
	w = local[12];
	goto WHL3340;
WHX3341:
	local[10]= NIL;
BLK3342:
	w = NIL;
	local[8]= NIL;
	local[9]= loadglobal(fqv[38]);
WHL3356:
	if (local[9]==NIL) goto WHX3357;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= loadglobal(fqv[53]);
	ctx->vsp=local+11;
	w=(pointer)INSTANTIATE(ctx,1,local+10); /*instantiate*/
	local[10]= w;
	local[11]= local[10];
	local[12]= fqv[54];
	local[13]= local[8];
	local[14]= argv[1];
	local[15]= local[2];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,5,local+11); /*send*/
	w = local[10];
	local[10]= w;
	local[11]= local[10];
	local[12]= fqv[18];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	if (w==NIL) goto IF3361;
	local[11]= local[10];
	w = loadglobal(fqv[41]);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	storeglobal(fqv[41],local[11]);
	goto IF3362;
IF3361:
	local[11]= local[10];
	ctx->vsp=local+12;
	w=(pointer)F3188curved_edge_image_p(ctx,1,local+11); /*curved-edge-image-p*/
	if (w!=NIL) goto IF3363;
	local[11]= local[10];
	w = loadglobal(fqv[42]);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	storeglobal(fqv[42],local[11]);
	goto IF3364;
IF3363:
	local[11]= NIL;
IF3364:
IF3362:
	local[11]= local[8];
	local[12]= local[1];
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(*ftab[6])(ctx,3,local+11,&ftab[6],fqv[55]); /*sethash*/
	goto WHL3356;
WHX3357:
	local[10]= NIL;
BLK3358:
	w = NIL;
	ctx->vsp=local+8;
	w=(pointer)RUNTIME(ctx,0,local+8); /*unix:runtime*/
	local[5] = w;
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,CLO3365,env,argv,local);
	local[9]= loadglobal(fqv[13]);
	ctx->vsp=local+10;
	w=(pointer)MAPCAR(ctx,2,local+8); /*mapcar*/
	local[8]= w;
	storeglobal(fqv[1],w);
	local[8]= loadglobal(fqv[41]);
	ctx->vsp=local+9;
	w=(pointer)F3186set_contour_intersections(ctx,1,local+8); /*set-contour-intersections*/
	local[8]= loadglobal(fqv[42]);
	local[9]= loadglobal(fqv[41]);
	ctx->vsp=local+10;
	w=(pointer)F3187set_non_contour_intersections(ctx,2,local+8); /*set-non-contour-intersections*/
	local[8]= loadglobal(fqv[53]);
	ctx->vsp=local+9;
	w=(pointer)INSTANTIATE(ctx,1,local+8); /*instantiate*/
	local[8]= w;
	local[9]= local[8];
	local[10]= fqv[24];
	local[11]= fqv[56];
	local[12]= fqv[57];
	local[13]= fqv[58];
	local[14]= fqv[59];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,6,local+9); /*send*/
	w = local[8];
	local[8]= w;
	w = local[4];
	ctx->vsp=local+9;
	local[4] = cons(ctx,local[8],w);
	local[8]= loadglobal(fqv[53]);
	ctx->vsp=local+9;
	w=(pointer)INSTANTIATE(ctx,1,local+8); /*instantiate*/
	local[8]= w;
	local[9]= local[8];
	local[10]= fqv[24];
	local[11]= fqv[56];
	local[12]= fqv[60];
	local[13]= fqv[58];
	local[14]= fqv[61];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,6,local+9); /*send*/
	w = local[8];
	local[8]= w;
	w = local[4];
	ctx->vsp=local+9;
	local[4] = cons(ctx,local[8],w);
	local[8]= loadglobal(fqv[53]);
	ctx->vsp=local+9;
	w=(pointer)INSTANTIATE(ctx,1,local+8); /*instantiate*/
	local[8]= w;
	local[9]= local[8];
	local[10]= fqv[24];
	local[11]= fqv[56];
	local[12]= fqv[62];
	local[13]= fqv[58];
	local[14]= fqv[63];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,6,local+9); /*send*/
	w = local[8];
	local[8]= w;
	w = local[4];
	ctx->vsp=local+9;
	local[4] = cons(ctx,local[8],w);
	local[8]= loadglobal(fqv[53]);
	ctx->vsp=local+9;
	w=(pointer)INSTANTIATE(ctx,1,local+8); /*instantiate*/
	local[8]= w;
	local[9]= local[8];
	local[10]= fqv[24];
	local[11]= fqv[56];
	local[12]= fqv[64];
	local[13]= fqv[58];
	local[14]= fqv[65];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,6,local+9); /*send*/
	w = local[8];
	local[8]= w;
	w = local[4];
	ctx->vsp=local+9;
	local[4] = cons(ctx,local[8],w);
	local[8]= NIL;
	local[9]= local[4];
WHL3371:
	if (local[9]==NIL) goto WHX3372;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= NIL;
	local[11]= loadglobal(fqv[41]);
WHL3376:
	if (local[11]==NIL) goto WHX3377;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[12];
	local[10] = w;
	local[12]= local[10];
	local[13]= fqv[29];
	local[14]= local[8];
	local[15]= NIL;
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,4,local+12); /*send*/
	goto WHL3376;
WHX3377:
	local[12]= NIL;
BLK3378:
	w = NIL;
	local[10]= NIL;
	local[11]= loadglobal(fqv[42]);
WHL3381:
	if (local[11]==NIL) goto WHX3382;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[12];
	local[10] = w;
	local[12]= local[10];
	local[13]= fqv[29];
	local[14]= local[8];
	local[15]= NIL;
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,4,local+12); /*send*/
	goto WHL3381;
WHX3382:
	local[12]= NIL;
BLK3383:
	w = NIL;
	goto WHL3371;
WHX3372:
	local[10]= NIL;
BLK3373:
	w = NIL;
	ctx->vsp=local+8;
	w=(pointer)RUNTIME(ctx,0,local+8); /*unix:runtime*/
	local[6] = w;
	local[8]= loadglobal(fqv[41]);
	local[9]= loadglobal(fqv[42]);
	ctx->vsp=local+10;
	w=(pointer)APPEND(ctx,2,local+8); /*append*/
	local[8]= w;
	storeglobal(fqv[66],w);
	local[8]= loadglobal(fqv[66]);
	local[9]= fqv[67];
	ctx->vsp=local+10;
	w=(*ftab[3])(ctx,2,local+8,&ftab[3],fqv[50]); /*send-all*/
	local[8]= loadglobal(fqv[66]);
	local[9]= fqv[68];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(*ftab[3])(ctx,3,local+8,&ftab[3],fqv[50]); /*send-all*/
	ctx->vsp=local+8;
	w=(pointer)RUNTIME(ctx,0,local+8); /*unix:runtime*/
	local[7] = w;
	local[8]= local[5];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	local[9]= local[6];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,2,local+9); /*-*/
	local[9]= w;
	local[10]= local[7];
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)MINUS(ctx,2,local+10); /*-*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,3,local+8); /*list*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)PRINT(ctx,1,local+8); /*print*/
	local[0]= w;
BLK3336:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3365(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env2[1];
	local[2]= env->c.clo.env2[2];
	ctx->vsp=local+3;
	w=(pointer)F3185make_face_image(ctx,3,local+0); /*make-face-image*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___hid(ctx,n,argv,env)
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
	local[0]= fqv[69];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF3385;
	local[0]= fqv[70];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[71],w);
	goto IF3386;
IF3385:
	local[0]= fqv[72];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF3386:
	local[0]= fqv[73];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[13];
	local[1]= fqv[74];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3387;
	local[0]= fqv[13];
	local[1]= fqv[74];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[13];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3389;
	local[0]= fqv[13];
	local[1]= fqv[75];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3390;
IF3389:
	local[0]= NIL;
IF3390:
	local[0]= fqv[13];
	goto IF3388;
IF3387:
	local[0]= NIL;
IF3388:
	local[0]= fqv[1];
	local[1]= fqv[74];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3391;
	local[0]= fqv[1];
	local[1]= fqv[74];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[1];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3393;
	local[0]= fqv[1];
	local[1]= fqv[75];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3394;
IF3393:
	local[0]= NIL;
IF3394:
	local[0]= fqv[1];
	goto IF3392;
IF3391:
	local[0]= NIL;
IF3392:
	local[0]= fqv[38];
	local[1]= fqv[74];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3395;
	local[0]= fqv[38];
	local[1]= fqv[74];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[38];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3397;
	local[0]= fqv[38];
	local[1]= fqv[75];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3398;
IF3397:
	local[0]= NIL;
IF3398:
	local[0]= fqv[38];
	goto IF3396;
IF3395:
	local[0]= NIL;
IF3396:
	local[0]= fqv[41];
	local[1]= fqv[74];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3399;
	local[0]= fqv[41];
	local[1]= fqv[74];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[41];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3401;
	local[0]= fqv[41];
	local[1]= fqv[75];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3402;
IF3401:
	local[0]= NIL;
IF3402:
	local[0]= fqv[41];
	goto IF3400;
IF3399:
	local[0]= NIL;
IF3400:
	local[0]= fqv[66];
	local[1]= fqv[74];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3403;
	local[0]= fqv[66];
	local[1]= fqv[74];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[66];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3405;
	local[0]= fqv[66];
	local[1]= fqv[75];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3406;
IF3405:
	local[0]= NIL;
IF3406:
	local[0]= fqv[66];
	goto IF3404;
IF3403:
	local[0]= NIL;
IF3404:
	local[0]= fqv[43];
	local[1]= fqv[74];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3407;
	local[0]= fqv[43];
	local[1]= fqv[74];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[43];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3409;
	local[0]= fqv[43];
	local[1]= fqv[75];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3410;
IF3409:
	local[0]= NIL;
IF3410:
	local[0]= fqv[43];
	goto IF3408;
IF3407:
	local[0]= NIL;
IF3408:
	local[0]= fqv[42];
	local[1]= fqv[74];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3411;
	local[0]= fqv[42];
	local[1]= fqv[74];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[42];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3413;
	local[0]= fqv[42];
	local[1]= fqv[75];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3414;
IF3413:
	local[0]= NIL;
IF3414:
	local[0]= fqv[42];
	goto IF3412;
IF3411:
	local[0]= NIL;
IF3412:
	local[0]= fqv[39];
	local[1]= fqv[74];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3415;
	local[0]= fqv[39];
	local[1]= fqv[74];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[39];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3417;
	local[0]= fqv[39];
	local[1]= fqv[75];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3418;
IF3417:
	local[0]= NIL;
IF3418:
	local[0]= fqv[39];
	goto IF3416;
IF3415:
	local[0]= NIL;
IF3416:
	local[0]= fqv[40];
	local[1]= fqv[74];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3419;
	local[0]= fqv[40];
	local[1]= fqv[74];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[40];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3421;
	local[0]= fqv[40];
	local[1]= fqv[75];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3422;
IF3421:
	local[0]= NIL;
IF3422:
	local[0]= fqv[40];
	goto IF3420;
IF3419:
	local[0]= NIL;
IF3420:
	local[0]= fqv[30];
	local[1]= fqv[76];
	local[2]= T;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[77],module,F3183check_visibility,fqv[78]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3200edge_image_edge3,fqv[79],fqv[53],fqv[80]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3202edge_image_vertices,fqv[22],fqv[53],fqv[81]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3204edge_image_color,fqv[4],fqv[53],fqv[82]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3206edge_image_homo2real,fqv[6],fqv[53],fqv[83]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3208edge_image_add_segment,fqv[7],fqv[53],fqv[84]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3214edge_image_projected_point,fqv[12],fqv[53],fqv[85]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3216edge_image_projected_homo_point,fqv[14],fqv[53],fqv[86]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3218edge_image_intersecting_point,fqv[87],fqv[53],fqv[88]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3222edge_image_projected_intersection,fqv[29],fqv[53],fqv[89]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3228edge_image_sort_segments,fqv[67],fqv[53],fqv[90]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3230edge_image_box,fqv[91],fqv[53],fqv[92]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3233edge_image_contourp,fqv[18],fqv[53],fqv[93]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3235edge_image_mark_visible_segments,fqv[68],fqv[53],fqv[94]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3242edge_image_visible_face,fqv[95],fqv[53],fqv[96]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3246edge_image_collect_segments,fqv[15],fqv[53],fqv[97]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3257edge_image_visible_segments,fqv[98],fqv[53],fqv[99]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3259edge_image_invisible_segments,fqv[100],fqv[53],fqv[101]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3261edge_image_project,fqv[54],fqv[53],fqv[102]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3265edge_image_init,fqv[24],fqv[53],fqv[103]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3282face_image_face3d,fqv[104],fqv[26],fqv[105]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3284face_image_possibly_hiding,fqv[2],fqv[26],fqv[106]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3286face_image_boxtest,fqv[107],fqv[26],fqv[108]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3288face_image_init,fqv[24],fqv[26],fqv[109]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[110],module,F3185make_face_image,fqv[111]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[112],module,F3186set_contour_intersections,fqv[113]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[114],module,F3187set_non_contour_intersections,fqv[115]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[116],module,F3188curved_edge_image_p,fqv[117]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[118],module,F3189hid2,fqv[119]);
	local[0]= fqv[120];
	local[1]= fqv[121];
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,2,local+0,&ftab[7],fqv[122]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<8; i++) ftab[i]=fcallx;
}
