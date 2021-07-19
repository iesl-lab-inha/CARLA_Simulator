/* ./geopack.c :  entry=geopack */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "geopack.h"
#pragma init (register_geopack)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___geopack();
extern pointer build_quote_vector();
static int register_geopack()
  { add_module_initializer("___geopack", ___geopack);}

static pointer F71vplus();
static pointer F72vector_mean();
static pointer F73direction_vector();
static pointer F74triangle();
static pointer F75triangle_normal();
static pointer F76vector_angle();
static pointer F77face_normal_vector();
static pointer F78farthest();
static pointer F79farthest_pair();
static pointer F80maxindex();
static pointer F81random_vector();
static pointer F82random_normalized_vector();
static pointer F83random_vector2();
static pointer F84random_vectors();
static pointer F85edgep();
static pointer F86facep();
static pointer F87bodyp();
static pointer F88primitive_body_p();
static pointer F89n_2();
static pointer F90eps_();
static pointer F91eps_();
static pointer F92eps_();
static pointer F93eps__();
static pointer F94eps__();
static pointer F95eps__();
static pointer F96eps_zero();
static pointer F97eps_in_range();
static pointer F98eps_v_();
static pointer F99eps_coords_();
static pointer F100make_bounding_box();
static pointer F101make_big_bounding_box();
static pointer F102bounding_box_intersection();
static pointer F103bounding_box_union();
static pointer F106make_line();
static pointer F107winged_edge_p();
static pointer F109make_plane();
static pointer F113make_polygon();

/*vplus*/
static pointer F71vplus(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[0]);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,2,local+0); /*instantiate*/
	local[0]= w;
	local[1]= NIL;
	local[2]= argv[0];
WHL116:
	if (local[2]==NIL) goto WHX117;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	local[4]= local[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)VPLUS(ctx,3,local+3); /*v+*/
	goto WHL116;
WHX117:
	local[3]= NIL;
BLK118:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK114:
	ctx->vsp=local; return(local[0]);}

/*vector-mean*/
static pointer F72vector_mean(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeflt(1.00000000e+00);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F71vplus(ctx,1,local+1); /*vplus*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SCALEVEC(ctx,2,local+0); /*scale*/
	local[0]= w;
BLK120:
	ctx->vsp=local; return(local[0]);}

/*direction-vector*/
static pointer F73direction_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)VNORMALIZE(ctx,1,local+0); /*normalize-vector*/
	local[0]= w;
BLK121:
	ctx->vsp=local; return(local[0]);}

/*triangle*/
static pointer F74triangle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT124;}
	local[0]= fqv[1];
ENT124:
ENT123:
	if (n>4) maerror();
	local[1]= argv[1];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)VMINUS(ctx,2,local+2); /*v-*/
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SCA3PROD(ctx,3,local+1); /*v.**/
	local[0]= w;
BLK122:
	ctx->vsp=local; return(local[0]);}

/*triangle-normal*/
static pointer F75triangle_normal(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+0); /*v**/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)VNORMALIZE(ctx,1,local+0); /*normalize-vector*/
	local[0]= w;
BLK125:
	ctx->vsp=local; return(local[0]);}

/*vector-angle*/
static pointer F76vector_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT129;}
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+0); /*v**/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)VNORMALIZE(ctx,1,local+0); /*normalize-vector*/
	local[0]= w;
ENT129:
	if (n>=4) { local[1]=(argv[3]); goto ENT128;}
	local[1]= makeflt(1.00000000e-10);
ENT128:
ENT127:
	if (n>4) maerror();
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+2); /*v**/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VNORM2(ctx,1,local+2); /*norm2*/
	local[2]= w;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto IF130;
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)VINNERPRODUCT(ctx,2,local+2); /*v.*/
	local[2]= w;
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto IF132;
	local[2]= makeflt(0.00000000e+00);
	goto IF133;
IF132:
	local[2]= makeflt(3.14159265e+00);
IF133:
	w = local[2];
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK126;
	goto IF131;
IF130:
	local[2]= NIL;
IF131:
	local[2]= local[0];
	local[3]= argv[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)SCA3PROD(ctx,3,local+2); /*v.**/
	local[2]= w;
	local[3]= argv[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)VINNERPRODUCT(ctx,2,local+3); /*v.*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ATAN(ctx,2,local+2); /*atan*/
	local[0]= w;
BLK126:
	ctx->vsp=local; return(local[0]);}

/*face-normal-vector*/
static pointer F77face_normal_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= NIL;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	local[3]= makeint(0);
	local[4]= makeint(0);
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[3]= w;
	local[4]= makeint(0);
	local[5]= makeint(0);
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
WHL135:
	if (local[2]==NIL) goto WHX136;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[5];
	local[1] = w;
	local[5]= local[0];
	local[6]= local[1];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)VCROSSPRODUCT(ctx,3,local+5); /*v**/
	local[5]= w;
	local[6]= local[4];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)VPLUS(ctx,3,local+5); /*v+*/
	local[0] = local[1];
	goto WHL135;
WHX136:
	local[5]= NIL;
BLK137:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	local[5]= local[0];
	local[6]= local[1];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)VCROSSPRODUCT(ctx,3,local+5); /*v**/
	local[5]= w;
	local[6]= local[4];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)VPLUS(ctx,3,local+5); /*v+*/
	local[5]= local[4];
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)VNORMALIZE(ctx,2,local+5); /*normalize-vector*/
	local[0]= w;
BLK134:
	ctx->vsp=local; return(local[0]);}

/*farthest*/
static pointer F78farthest(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	w = local[0];
	local[0]= w;
	local[1]= argv[0];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)VDISTANCE(ctx,2,local+1); /*distance*/
	local[1]= w;
	local[2]= makeflt(0.00000000e+00);
	local[3]= NIL;
	local[4]= argv[1];
WHL142:
	if (local[4]==NIL) goto WHX143;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= argv[0];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)VDISTANCE(ctx,2,local+5); /*distance*/
	local[2] = w;
	local[5]= local[2];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto IF146;
	local[0] = local[3];
	local[1] = local[2];
	local[5]= local[1];
	goto IF147;
IF146:
	local[5]= NIL;
IF147:
	goto WHL142;
WHX143:
	local[5]= NIL;
BLK144:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK139:
	ctx->vsp=local; return(local[0]);}

/*farthest-pair*/
static pointer F79farthest_pair(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[0];
	local[0]= w;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F78farthest(ctx,2,local+2); /*farthest*/
	local[2]= w;
	local[3]= local[0];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)VDISTANCE(ctx,2,local+3); /*distance*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
WHL150:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX151;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[7];
	local[4] = w;
	local[7]= local[4];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)F78farthest(ctx,2,local+7); /*farthest*/
	local[5] = w;
	local[7]= local[4];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)VDISTANCE(ctx,2,local+7); /*distance*/
	local[6] = w;
	local[7]= local[6];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)GREATERP(ctx,2,local+7); /*>*/
	if (w==NIL) goto IF154;
	local[0] = local[4];
	local[2] = local[5];
	local[3] = local[6];
	local[7]= local[3];
	goto IF155;
IF154:
	local[7]= NIL;
IF155:
	goto WHL150;
WHX151:
	local[7]= NIL;
BLK152:
	local[7]= local[0];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[0]= w;
BLK148:
	ctx->vsp=local; return(local[0]);}

/*maxindex*/
static pointer F80maxindex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint(0);
	local[1]= argv[0];
	{ register eusinteger_t i=intval(makeint(1));
	  w=makeflt(local[1]->c.fvec.fv[i]);}
	local[1]= makeflt((double)fabs(fltval(w)));
	local[2]= argv[0];
	{ register eusinteger_t i=intval(makeint(0));
	  w=makeflt(local[2]->c.fvec.fv[i]);}
	{ double left,right;
		right=fltval(makeflt((double)fabs(fltval(w)))); left=fltval(local[1]);
	if (left <= right) goto IF157;}
	local[0] = makeint(1);
	local[1]= local[0];
	goto IF158;
IF157:
	local[1]= NIL;
IF158:
	local[1]= argv[0];
	{ register eusinteger_t i=intval(makeint(2));
	  w=makeflt(local[1]->c.fvec.fv[i]);}
	local[1]= makeflt((double)fabs(fltval(w)));
	local[2]= argv[0];
	{ register eusinteger_t i=intval(local[0]);
	  w=makeflt(local[2]->c.fvec.fv[i]);}
	{ double left,right;
		right=fltval(makeflt((double)fabs(fltval(w)))); left=fltval(local[1]);
	if (left <= right) goto IF159;}
	local[0] = makeint(2);
	local[1]= local[0];
	goto IF160;
IF159:
	local[1]= NIL;
IF160:
	w = local[0];
	local[0]= w;
BLK156:
	ctx->vsp=local; return(local[0]);}

/*random-vector*/
static pointer F81random_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT163;}
	local[0]= makeflt(1.00000000e+00);
ENT163:
ENT162:
	if (n>1) maerror();
	local[1]= local[0];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)RANDOM(ctx,1,local+2); /*random*/
	local[2]= w;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)RANDOM(ctx,1,local+3); /*random*/
	local[3]= w;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)RANDOM(ctx,1,local+4); /*random*/
	local[4]= w;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[0]= w;
BLK161:
	ctx->vsp=local; return(local[0]);}

/*random-normalized-vector*/
static pointer F82random_normalized_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= makeflt(1.00000000e+00);
	ctx->vsp=local+1;
	w=(pointer)RANDOM(ctx,1,local+0); /*random*/
	local[0]= w;
	local[1]= makeflt(1.00000000e+00);
	ctx->vsp=local+2;
	w=(pointer)RANDOM(ctx,1,local+1); /*random*/
	local[1]= w;
	local[2]= makeflt(1.00000000e+00);
	ctx->vsp=local+3;
	w=(pointer)RANDOM(ctx,1,local+2); /*random*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)VNORMALIZE(ctx,1,local+0); /*normalize-vector*/
	local[0]= w;
BLK164:
	ctx->vsp=local; return(local[0]);}

/*random-vector2*/
static pointer F83random_vector2(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT167;}
	local[0]= makeflt(1.00000000e+00);
	ctx->vsp=local+1;
	w=(pointer)RANDOM(ctx,1,local+0); /*random*/
	local[0]= w;
ENT167:
ENT166:
	if (n>1) maerror();
	local[1]= local[0];
	local[2]= makeint(1);
	local[3]= makeint(0);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	local[3]= makeflt(6.28318531e+00);
	ctx->vsp=local+4;
	w=(pointer)RANDOM(ctx,1,local+3); /*random*/
	local[3]= w;
	local[4]= fqv[2];
	ctx->vsp=local+5;
	w=(pointer)ROTVEC(ctx,3,local+2); /*rotate-vector*/
	local[2]= w;
	local[3]= makeflt(6.28318531e+00);
	ctx->vsp=local+4;
	w=(pointer)RANDOM(ctx,1,local+3); /*random*/
	local[3]= w;
	local[4]= fqv[3];
	ctx->vsp=local+5;
	w=(pointer)ROTVEC(ctx,3,local+2); /*rotate-vector*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,2,local+1); /*scale*/
	local[0]= w;
BLK165:
	ctx->vsp=local; return(local[0]);}

/*random-vectors*/
static pointer F84random_vectors(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF169;
	local[0]= NIL;
	goto IF170;
IF169:
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)F81random_vector(ctx,1,local+0); /*random-vector*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SUB1(ctx,1,local+1); /*1-*/
	local[1]= w;
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)F84random_vectors(ctx,2,local+1); /*random-vectors*/
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
IF170:
	w = local[0];
	local[0]= w;
BLK168:
	ctx->vsp=local; return(local[0]);}

/*edgep*/
static pointer F85edgep(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[4]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK171:
	ctx->vsp=local; return(local[0]);}

/*facep*/
static pointer F86facep(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[5]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK172:
	ctx->vsp=local; return(local[0]);}

/*bodyp*/
static pointer F87bodyp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[6]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK173:
	ctx->vsp=local; return(local[0]);}

/*primitive-body-p*/
static pointer F88primitive_body_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F87bodyp(ctx,1,local+0); /*bodyp*/
	local[0]= w;
	if (w==NIL) goto AND175;
	local[0]= argv[0];
	local[1]= fqv[7];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
AND175:
	w = local[0];
	local[0]= w;
BLK174:
	ctx->vsp=local; return(local[0]);}

/*n^2*/
static pointer F89n_2(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
BLK176:
	ctx->vsp=local; return(local[0]);}

/*eps=*/
static pointer F90eps_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT179;}
	local[0]= loadglobal(fqv[8]);
ENT179:
ENT178:
	if (n>3) maerror();
	local[1]= argv[0];
	{ double x,y;
		y=fltval(argv[1]); x=fltval(local[1]);
		local[1]=(makeflt(x - y));}
	local[1]= makeflt((double)fabs(fltval(local[1])));
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	local[0]= w;
BLK177:
	ctx->vsp=local; return(local[0]);}

/*eps<*/
static pointer F91eps_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT182;}
	local[0]= loadglobal(fqv[8]);
ENT182:
ENT181:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	{ double x,y;
		y=fltval(local[0]); x=fltval(local[2]);
		local[2]=(makeflt(x - y));}
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	local[0]= w;
BLK180:
	ctx->vsp=local; return(local[0]);}

/*eps>*/
static pointer F92eps_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT185;}
	local[0]= loadglobal(fqv[8]);
ENT185:
ENT184:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	{ double x,y;
		y=fltval(local[0]); x=fltval(local[2]);
		local[2]=(makeflt(x + y));}
	ctx->vsp=local+3;
	w=(pointer)GREATERP(ctx,2,local+1); /*>*/
	local[0]= w;
BLK183:
	ctx->vsp=local; return(local[0]);}

/*eps<=*/
static pointer F93eps__(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT188;}
	local[0]= loadglobal(fqv[8]);
ENT188:
ENT187:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	{ double x,y;
		y=fltval(local[0]); x=fltval(local[2]);
		local[2]=(makeflt(x + y));}
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	local[0]= w;
BLK186:
	ctx->vsp=local; return(local[0]);}

/*eps>=*/
static pointer F94eps__(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT191;}
	local[0]= loadglobal(fqv[8]);
ENT191:
ENT190:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	{ double x,y;
		y=fltval(local[0]); x=fltval(local[2]);
		local[2]=(makeflt(x - y));}
	ctx->vsp=local+3;
	w=(pointer)GREATERP(ctx,2,local+1); /*>*/
	local[0]= w;
BLK189:
	ctx->vsp=local; return(local[0]);}

/*eps<>*/
static pointer F95eps__(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT194;}
	local[0]= loadglobal(fqv[8]);
ENT194:
ENT193:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F90eps_(ctx,3,local+1); /*eps=*/
	w = ((w)==NIL?T:NIL);
	local[0]= w;
BLK192:
	ctx->vsp=local; return(local[0]);}

/*eps-zero*/
static pointer F96eps_zero(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT197;}
	local[0]= loadglobal(fqv[8]);
ENT197:
ENT196:
	if (n>2) maerror();
	local[1]= argv[0];
	local[2]= makeflt(0.00000000e+00);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F90eps_(ctx,3,local+1); /*eps=*/
	local[0]= w;
BLK195:
	ctx->vsp=local; return(local[0]);}

/*eps-in-range*/
static pointer F97eps_in_range(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT200;}
	local[0]= loadglobal(fqv[8]);
ENT200:
ENT199:
	if (n>4) maerror();
	local[1]= argv[0];
	{ double x,y;
		y=fltval(local[0]); x=fltval(local[1]);
		local[1]=(makeflt(x - y));}
	local[2]= argv[1];
	local[3]= argv[2];
	{ double x,y;
		y=fltval(local[0]); x=fltval(local[3]);
		local[3]=(makeflt(x + y));}
	ctx->vsp=local+4;
	w=(pointer)LSEQP(ctx,3,local+1); /*<=*/
	local[0]= w;
BLK198:
	ctx->vsp=local; return(local[0]);}

/*eps-v=*/
static pointer F98eps_v_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT203;}
	local[0]= loadglobal(fqv[8]);
ENT203:
ENT202:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)VDISTANCE(ctx,2,local+1); /*distance*/
	local[1]= w;
	local[2]= makeflt(0.00000000e+00);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F90eps_(ctx,3,local+1); /*eps=*/
	local[0]= w;
BLK201:
	ctx->vsp=local; return(local[0]);}

/*eps-coords=*/
static pointer F99eps_coords_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT207;}
	local[0]= loadglobal(fqv[8]);
ENT207:
	if (n>=4) { local[1]=(argv[3]); goto ENT206;}
	local[1]= local[0];
ENT206:
ENT205:
	if (n>4) maerror();
	local[2]= NIL;
	local[3]= argv[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,2,local+3,&ftab[0],fqv[9]); /*coordinates-distance*/
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,2,local+4); /*<*/
	local[4]= w;
	if (w==NIL) goto AND208;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (((w)->c.cons.car)==NIL?T:NIL);
	if (local[4]!=NIL) goto OR209;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,2,local+4); /*<*/
	local[4]= w;
OR209:
AND208:
	w = local[4];
	local[0]= w;
BLK204:
	ctx->vsp=local; return(local[0]);}

/*:box*/
static pointer M210bounding_box_box(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT213;}
	local[0]= NIL;
ENT213:
ENT212:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF214;
	local[1]= argv[0];
	local[2]= fqv[10];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF215;
IF214:
	local[1]= argv[0];
IF215:
	w = local[1];
	local[0]= w;
BLK211:
	ctx->vsp=local; return(local[0]);}

/*:minpoint*/
static pointer M216bounding_box_minpoint(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[0];
	local[0]= w;
BLK217:
	ctx->vsp=local; return(local[0]);}

/*:maxpoint*/
static pointer M218bounding_box_maxpoint(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK219:
	ctx->vsp=local; return(local[0]);}

/*:center*/
static pointer M220bounding_box_center(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeflt(5.00000000e-01);
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,3,local+0,&ftab[1],fqv[11]); /*midpoint*/
	local[0]= w;
BLK221:
	ctx->vsp=local; return(local[0]);}

/*:diagonal*/
static pointer M222bounding_box_diagonal(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
BLK223:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M224bounding_box_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT227;}
	local[0]= T;
ENT227:
ENT226:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[12]));
	local[3]= fqv[13];
	local[4]= local[0];
	local[5]= NIL;
	local[6]= fqv[14];
	local[7]= argv[0]->c.obj.iv[0];
	local[8]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,4,local+5); /*format*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	local[0]= w;
BLK225:
	ctx->vsp=local; return(local[0]);}

/*:inner*/
static pointer M228bounding_box_inner(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)VLESSP(ctx,2,local+0); /*v<*/
	local[0]= w;
	if (w==NIL) goto AND230;
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+2;
	w=(pointer)VGREATERP(ctx,2,local+0); /*v>*/
	local[0]= w;
AND230:
	w = local[0];
	local[0]= w;
BLK229:
	ctx->vsp=local; return(local[0]);}

/*:intersection*/
static pointer M231bounding_box_intersection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT234;}
	local[0]= NIL;
ENT234:
ENT233:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= argv[2]->c.obj.iv[0];
	ctx->vsp=local+3;
	w=(pointer)VMAX(ctx,2,local+1); /*vmax*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)VMIN(ctx,2,local+2); /*vmin*/
	local[2]= w;
	if (local[0]==NIL) goto IF235;
	local[3]= local[0];
	local[4]= local[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[0] = w;
	local[3]= local[1];
	local[4]= local[0];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)VMINUS(ctx,3,local+3); /*v-*/
	local[3]= local[2];
	local[4]= local[0];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)VPLUS(ctx,3,local+3); /*v+*/
	local[3]= w;
	goto IF236;
IF235:
	local[3]= NIL;
IF236:
	local[3]= local[1];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)VLESSP(ctx,2,local+3); /*v<*/
	if (w==NIL) goto IF237;
	local[3]= loadglobal(fqv[15]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[16];
	local[6]= local[1];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = local[3];
	local[3]= w;
	goto IF238;
IF237:
	local[3]= NIL;
IF238:
	w = local[3];
	local[0]= w;
BLK232:
	ctx->vsp=local; return(local[0]);}

/*:union*/
static pointer M240bounding_box_union(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT243;}
	local[0]= NIL;
ENT243:
ENT242:
	if (n>4) maerror();
	local[1]= loadglobal(fqv[15]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[16];
	local[4]= argv[0]->c.obj.iv[0];
	local[5]= argv[2]->c.obj.iv[0];
	ctx->vsp=local+6;
	w=(pointer)VMIN(ctx,2,local+4); /*vmin*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+7;
	w=(pointer)VMAX(ctx,2,local+5); /*vmax*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK241:
	ctx->vsp=local; return(local[0]);}

/*:intersection-p*/
static pointer M245bounding_box_intersection_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= argv[2]->c.obj.iv[0];
	ctx->vsp=local+2;
	w=(pointer)VMAX(ctx,2,local+0); /*vmax*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)VMIN(ctx,2,local+1); /*vmin*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VLESSP(ctx,2,local+0); /*v<*/
	local[0]= w;
BLK246:
	ctx->vsp=local; return(local[0]);}

/*:grow*/
static pointer M247bounding_box_grow(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT250;}
	local[0]= NIL;
ENT250:
ENT249:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF251;
	local[1]= argv[2];
	local[2]= argv[2];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	local[1]= w;
	goto IF252;
IF251:
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+4;
	w=(pointer)VMINUS(ctx,2,local+2); /*v-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,2,local+1); /*scale*/
	local[1]= w;
IF252:
	argv[2] = local[1];
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+4;
	w=(pointer)VMINUS(ctx,3,local+1); /*v-*/
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)VPLUS(ctx,3,local+1); /*v+*/
	w = argv[0];
	local[0]= w;
BLK248:
	ctx->vsp=local; return(local[0]);}

/*:volume*/
static pointer M253bounding_box_volume(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	local[1]= local[0];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	local[2]= local[0];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	local[3]= local[0];
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,3,local+1); /***/
	local[0]= w;
BLK254:
	ctx->vsp=local; return(local[0]);}

/*:extream-point*/
static pointer M255bounding_box_extream_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= loadglobal(fqv[0]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,2,local+1); /*instantiate*/
	local[1]= w;
	local[2]= makeint(0);
	local[3]= local[0];
WHL258:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX259;
	local[4]= local[1];
	local[5]= local[2];
	local[6]= argv[2];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= makeflt(0.00000000e+00);
	ctx->vsp=local+8;
	w=(pointer)GREATERP(ctx,2,local+6); /*>*/
	if (w==NIL) goto IF261;
	local[6]= argv[0]->c.obj.iv[1];
	goto IF262;
IF261:
	local[6]= argv[0]->c.obj.iv[0];
IF262:
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL258;
WHX259:
	local[4]= NIL;
BLK260:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK256:
	ctx->vsp=local; return(local[0]);}

/*:below*/
static pointer M263bounding_box_below(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT266;}
	local[0]= fqv[17];
ENT266:
ENT265:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[18];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= fqv[18];
	local[4]= makeflt(-1.00000000e+00);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SCALEVEC(ctx,2,local+4); /*scale*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)VINNERPRODUCT(ctx,2,local+3); /*v.*/
	local[3]= w;
	local[4]= local[0];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)VINNERPRODUCT(ctx,2,local+4); /*v.*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LESSP(ctx,2,local+3); /*<*/
	local[0]= w;
BLK264:
	ctx->vsp=local; return(local[0]);}

/*:corners*/
static pointer M267bounding_box_corners(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	local[3]= makeint(0);
	local[4]= makeint(2);
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(*ftab[2])(ctx,2,local+4,&ftab[2],fqv[19]); /*expt*/
	local[4]= w;
WHL270:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX271;
	local[5]= loadglobal(fqv[0]);
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,2,local+5); /*instantiate*/
	local[1] = w;
	local[5]= makeint(0);
	local[6]= local[2];
WHL274:
	local[7]= local[5];
	w = local[6];
	if ((eusinteger_t)local[7] >= (eusinteger_t)w) goto WHX275;
	local[7]= local[1];
	local[8]= local[5];
	local[9]= local[5];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)LOGBITP(ctx,2,local+9); /*logbitp*/
	if (w==NIL) goto IF277;
	local[9]= argv[0]->c.obj.iv[1];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,2,local+9); /*aref*/
	local[9]= w;
	goto IF278;
IF277:
	local[9]= argv[0]->c.obj.iv[0];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,2,local+9); /*aref*/
	local[9]= w;
IF278:
	ctx->vsp=local+10;
	w=(pointer)ASET(ctx,3,local+7); /*aset*/
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[5] = w;
	goto WHL274;
WHX275:
	local[7]= NIL;
BLK276:
	w = NIL;
	local[5]= local[1];
	w = local[0];
	ctx->vsp=local+6;
	local[0] = cons(ctx,local[5],w);
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL270;
WHX271:
	local[5]= NIL;
BLK272:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK268:
	ctx->vsp=local; return(local[0]);}

/*:body*/
static pointer M279bounding_box_body(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+1;
	w=(pointer)COPYSEQ(ctx,1,local+0); /*copy-seq*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+2;
	w=(pointer)COPYSEQ(ctx,1,local+1); /*copy-seq*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+3;
	w=(pointer)COPYSEQ(ctx,1,local+2); /*copy-seq*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+4;
	w=(pointer)COPYSEQ(ctx,1,local+3); /*copy-seq*/
	local[3]= w;
	local[4]= local[1];
	local[5]= makeint(1);
	local[6]= argv[0]->c.obj.iv[1];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	local[4]= local[2];
	local[5]= makeint(1);
	local[6]= argv[0]->c.obj.iv[1];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	local[4]= local[2];
	local[5]= makeint(0);
	local[6]= argv[0]->c.obj.iv[1];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	local[4]= local[3];
	local[5]= makeint(0);
	local[6]= argv[0]->c.obj.iv[1];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	local[4]= local[0];
	local[5]= local[1];
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,4,local+4); /*list*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[0];
	local[7]= makeint(2);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[3])(ctx,2,local+4,&ftab[3],fqv[20]); /*make-prism*/
	local[0]= w;
BLK280:
	ctx->vsp=local; return(local[0]);}

/*:init2*/
static pointer M281bounding_box_init2(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT284;}
	local[0]= NIL;
ENT284:
ENT283:
	if (n>5) maerror();
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)VMIN(ctx,2,local+1); /*vmin*/
	argv[0]->c.obj.iv[0] = w;
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)VMAX(ctx,2,local+1); /*vmax*/
	argv[0]->c.obj.iv[1] = w;
	if (local[0]==NIL) goto IF285;
	local[1]= argv[0];
	local[2]= fqv[10];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF286;
IF285:
	local[1]= NIL;
IF286:
	w = argv[0];
	local[0]= w;
BLK282:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M287bounding_box_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT290;}
	local[0]= NIL;
ENT290:
ENT289:
	if (n>4) maerror();
	local[1]= (pointer)get_sym_func(fqv[21]);
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	argv[0]->c.obj.iv[0] = w;
	local[1]= (pointer)get_sym_func(fqv[22]);
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	argv[0]->c.obj.iv[1] = w;
	if (local[0]==NIL) goto IF291;
	local[1]= argv[0];
	local[2]= fqv[10];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF292;
IF291:
	local[1]= NIL;
IF292:
	w = argv[0];
	local[0]= w;
BLK288:
	ctx->vsp=local; return(local[0]);}

/*make-bounding-box*/
static pointer F100make_bounding_box(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT295;}
	local[0]= loadglobal(fqv[23]);
ENT295:
ENT294:
	if (n>2) maerror();
	local[1]= loadglobal(fqv[15]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[24];
	local[4]= argv[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK293:
	ctx->vsp=local; return(local[0]);}

/*make-big-bounding-box*/
static pointer F101make_big_bounding_box(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= makeflt(-1.00000000e+20);
	local[1]= makeflt(-1.00000000e+20);
	local[2]= makeflt(-1.00000000e+20);
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
	local[1]= makeflt(1.00000000e+20);
	local[2]= makeflt(1.00000000e+20);
	local[3]= makeflt(1.00000000e+20);
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)F100make_bounding_box(ctx,1,local+0); /*make-bounding-box*/
	local[0]= w;
BLK297:
	ctx->vsp=local; return(local[0]);}

/*bounding-box-intersection*/
static pointer F102bounding_box_intersection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT300;}
	local[0]= loadglobal(fqv[23]);
ENT300:
ENT299:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= NIL;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[3];
	local[3]= w;
	local[4]= fqv[25];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[2] = w;
	local[3]= NIL;
	local[4]= argv[0];
WHL303:
	if (local[4]==NIL) goto WHX304;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[2];
	local[6]= fqv[26];
	local[7]= local[3];
	local[8]= fqv[25];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[2] = w;
	if (local[2]!=NIL) goto IF307;
	w = NIL;
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK298;
	goto IF308;
IF307:
	local[5]= NIL;
IF308:
	goto WHL303;
WHX304:
	local[5]= NIL;
BLK305:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK298:
	ctx->vsp=local; return(local[0]);}

/*bounding-box-union*/
static pointer F103bounding_box_union(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT311;}
	local[0]= loadglobal(fqv[23]);
ENT311:
ENT310:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= NIL;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[3];
	local[3]= w;
	local[4]= fqv[25];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[2] = w;
	local[3]= NIL;
	local[4]= argv[0];
WHL314:
	if (local[4]==NIL) goto WHX315;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[2];
	local[6]= fqv[27];
	local[7]= local[3];
	local[8]= fqv[25];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[2] = w;
	goto WHL314;
WHX315:
	local[5]= NIL;
BLK316:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK309:
	ctx->vsp=local; return(local[0]);}

/*:nvertex*/
static pointer M318line_nvertex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT321;}
	local[0]= NIL;
ENT321:
ENT320:
	if (n>3) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK319:
	ctx->vsp=local; return(local[0]);}

/*:pvertex*/
static pointer M322line_pvertex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT325;}
	local[0]= NIL;
ENT325:
ENT324:
	if (n>3) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK323:
	ctx->vsp=local; return(local[0]);}

/*:vertices*/
static pointer M326line_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
BLK327:
	ctx->vsp=local; return(local[0]);}

/*:eq*/
static pointer M328line_eq(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2]->c.obj.iv[1];
	local[0]= ((argv[0]->c.obj.iv[1])==(local[0])?T:NIL);
	if (local[0]==NIL) goto AND330;
	local[0]= argv[2]->c.obj.iv[2];
	local[0]= ((argv[0]->c.obj.iv[2])==(local[0])?T:NIL);
AND330:
	w = local[0];
	local[0]= w;
BLK329:
	ctx->vsp=local; return(local[0]);}

/*:eql*/
static pointer M331line_eql(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2]->c.obj.iv[1];
	local[0]= ((argv[0]->c.obj.iv[1])==(local[0])?T:NIL);
	if (local[0]==NIL) goto AND334;
	local[0]= argv[2]->c.obj.iv[2];
	local[0]= ((argv[0]->c.obj.iv[2])==(local[0])?T:NIL);
AND334:
	if (local[0]!=NIL) goto OR333;
	local[0]= argv[2]->c.obj.iv[1];
	local[0]= ((argv[0]->c.obj.iv[2])==(local[0])?T:NIL);
	if (local[0]==NIL) goto AND335;
	local[0]= argv[2]->c.obj.iv[2];
	local[0]= ((argv[0]->c.obj.iv[1])==(local[0])?T:NIL);
AND335:
OR333:
	w = local[0];
	local[0]= w;
BLK332:
	ctx->vsp=local; return(local[0]);}

/*:equall*/
static pointer M336line_equall(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)EQUAL(ctx,2,local+0); /*equal*/
	local[0]= w;
	if (w==NIL) goto AND339;
	local[0]= argv[2]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)EQUAL(ctx,2,local+0); /*equal*/
	local[0]= w;
AND339:
	if (local[0]!=NIL) goto OR338;
	local[0]= argv[2]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)EQUAL(ctx,2,local+0); /*equal*/
	local[0]= w;
	if (w==NIL) goto AND340;
	local[0]= argv[2]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)EQUAL(ctx,2,local+0); /*equal*/
	local[0]= w;
AND340:
OR338:
	w = local[0];
	local[0]= w;
BLK337:
	ctx->vsp=local; return(local[0]);}

/*:parameter*/
static pointer M341line_parameter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[1]= w;
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)VINNERPRODUCT(ctx,2,local+2); /*v.*/
	local[2]= w;
	local[3]= local[0];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)VINNERPRODUCT(ctx,2,local+3); /*v.*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[0]= w;
BLK342:
	ctx->vsp=local; return(local[0]);}

/*:point*/
static pointer M343line_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,3,local+0,&ftab[1],fqv[11]); /*midpoint*/
	local[0]= w;
BLK344:
	ctx->vsp=local; return(local[0]);}

/*:box*/
static pointer M345line_box(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT348;}
	local[0]= NIL;
ENT348:
ENT347:
	if (n>3) maerror();
	local[1]= loadglobal(fqv[15]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[16];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= argv[0]->c.obj.iv[2];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK346:
	ctx->vsp=local; return(local[0]);}

/*:boxtest*/
static pointer M350line_boxtest(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT353;}
	local[0]= NIL;
ENT353:
ENT352:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[25];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= fqv[28];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	w = local[2];
	local[0]= w;
BLK351:
	ctx->vsp=local; return(local[0]);}

/*:length*/
static pointer M354line_length(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)VDISTANCE(ctx,2,local+0); /*distance*/
	local[0]= w;
BLK355:
	ctx->vsp=local; return(local[0]);}

/*:end-point*/
static pointer M356line_end_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	if (argv[2]!=local[0]) goto IF358;
	local[0]= argv[2];
	goto IF359;
IF358:
	local[0]= argv[0]->c.obj.iv[2];
	if (argv[2]!=local[0]) goto IF360;
	local[0]= argv[2];
	goto IF361;
IF360:
	local[0]= NIL;
IF361:
IF359:
	w = local[0];
	local[0]= w;
BLK357:
	ctx->vsp=local; return(local[0]);}

/*:direction*/
static pointer M362line_direction(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)VNORMALIZE(ctx,1,local+0); /*normalize-vector*/
	local[0]= w;
BLK363:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M364line_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,FLET366,env,argv,local);
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[12]));
	local[3]= fqv[13];
	local[4]= argv[2];
	local[5]= argv[0]->c.obj.iv[1];
	w = local[0];
	ctx->vsp=local+6;
	w=FLET366(ctx,1,local+5,w);
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[2];
	w = local[0];
	ctx->vsp=local+7;
	w=FLET366(ctx,1,local+6,w);
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,6,local+1); /*send-message*/
	local[0]= w;
BLK365:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M367line_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[29], &argv[2], n-2, local+0, 1);
	if (n & (1<<0)) goto KEY369;
	local[0] = NIL;
KEY369:
	if (n & (1<<1)) goto KEY370;
	local[1] = NIL;
KEY370:
	if (local[0]==NIL) goto IF371;
	argv[0]->c.obj.iv[1] = local[0];
	local[2]= argv[0]->c.obj.iv[1];
	goto IF372;
IF371:
	local[2]= NIL;
IF372:
	if (local[1]==NIL) goto IF373;
	argv[0]->c.obj.iv[2] = local[1];
	local[2]= argv[0]->c.obj.iv[2];
	goto IF374;
IF373:
	local[2]= NIL;
IF374:
	w = argv[0];
	local[0]= w;
BLK368:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET366(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint(30);
	ctx->vsp=local+1;
	w=(*ftab[4])(ctx,1,local+0,&ftab[4],fqv[30]); /*make-string-output-stream*/
	local[0]= w;
	local[1]= fqv[31];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)PRINC(ctx,2,local+1); /*princ*/
	local[1]= makeint(0);
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
WHL376:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX377;
	local[3]= local[0];
	local[4]= fqv[32];
	local[5]= argv[0];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL376;
WHX377:
	local[3]= NIL;
BLK378:
	w = NIL;
	local[1]= local[0]->c.obj.iv[3];
	ctx->vsp=local+2;
	w=(pointer)SUB1(ctx,1,local+1); /*1-*/
	local[1]= w;
	local[2]= w;
	w = local[0];
	w->c.obj.iv[3] = local[2];
	local[1]= fqv[33];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)PRINC(ctx,2,local+1); /*princ*/
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,1,local+1,&ftab[5],fqv[34]); /*get-output-stream-string*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:foot*/
static pointer M381line_foot(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[1]= w;
	local[2]= local[1];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)VMINUS(ctx,2,local+3); /*v-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)VINNERPRODUCT(ctx,2,local+2); /*v.*/
	local[2]= w;
	local[3]= local[1];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)VINNERPRODUCT(ctx,2,local+3); /*v.*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[0]= w;
BLK382:
	ctx->vsp=local; return(local[0]);}

/*:common-perpendicular*/
static pointer M383line_common_perpendicular(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= argv[2]->c.obj.iv[2];
	local[10]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+11;
	w=(pointer)VMINUS(ctx,2,local+9); /*v-*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)VNORM(ctx,1,local+9); /*norm*/
	local[1] = w;
	local[9]= local[1];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,1,local+9); /*-*/
	local[1] = w;
	local[9]= argv[0]->c.obj.iv[2];
	local[10]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+11;
	w=(pointer)VMINUS(ctx,2,local+9); /*v-*/
	local[9]= w;
	local[10]= argv[2]->c.obj.iv[2];
	local[11]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+12;
	w=(pointer)VMINUS(ctx,2,local+10); /*v-*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)VINNERPRODUCT(ctx,2,local+9); /*v.*/
	local[2] = w;
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,1,local+9); /*-*/
	local[3] = w;
	local[9]= argv[0]->c.obj.iv[2];
	local[10]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+11;
	w=(pointer)VMINUS(ctx,2,local+9); /*v-*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)VNORM(ctx,1,local+9); /*norm*/
	local[4] = w;
	local[9]= local[4];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[4] = w;
	local[9]= local[2];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	local[10]= local[1];
	local[11]= local[4];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[0] = w;
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)ABS(ctx,1,local+9); /*abs*/
	local[9]= w;
	local[10]= loadglobal(fqv[35]);
	ctx->vsp=local+11;
	w=(pointer)LESSP(ctx,2,local+9); /*<*/
	if (w==NIL) goto IF385;
	w = fqv[36];
	ctx->vsp=local+9;
	local[0]=w;
	goto BLK384;
	goto IF386;
IF385:
	local[9]= argv[0]->c.obj.iv[2];
	local[10]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+11;
	w=(pointer)VMINUS(ctx,2,local+9); /*v-*/
	local[9]= w;
	local[10]= argv[2]->c.obj.iv[1];
	local[11]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+12;
	w=(pointer)VMINUS(ctx,2,local+10); /*v-*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)VINNERPRODUCT(ctx,2,local+9); /*v.*/
	local[5] = w;
	local[9]= argv[2]->c.obj.iv[2];
	local[10]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+11;
	w=(pointer)VMINUS(ctx,2,local+9); /*v-*/
	local[9]= w;
	local[10]= argv[2]->c.obj.iv[1];
	local[11]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+12;
	w=(pointer)VMINUS(ctx,2,local+10); /*v-*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)VINNERPRODUCT(ctx,2,local+9); /*v.*/
	local[6] = w;
	local[9]= argv[0];
	local[10]= fqv[37];
	local[11]= local[1];
	local[12]= local[5];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	local[12]= local[2];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(pointer)TIMES(ctx,2,local+12); /***/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[11]= w;
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)QUOTIENT(ctx,2,local+11); /*/*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[7] = w;
	local[9]= argv[2];
	local[10]= fqv[37];
	local[11]= local[3];
	local[12]= local[5];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	local[12]= local[4];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(pointer)TIMES(ctx,2,local+12); /***/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[11]= w;
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)QUOTIENT(ctx,2,local+11); /*/*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[8] = w;
	local[9]= local[7];
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,2,local+9); /*list*/
	ctx->vsp=local+9;
	local[0]=w;
	goto BLK384;
IF386:
	w = local[9];
	local[0]= w;
BLK384:
	ctx->vsp=local; return(local[0]);}

/*:distance-point*/
static pointer M387line_distance_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[38];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= local[1];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto CON390;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)VDISTANCE(ctx,2,local+2); /*distance*/
	local[2]= w;
	goto CON389;
CON390:
	local[2]= local[1];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto CON391;
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)VDISTANCE(ctx,2,local+2); /*distance*/
	local[2]= w;
	goto CON389;
CON391:
	local[2]= argv[0];
	local[3]= fqv[37];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)VDISTANCE(ctx,2,local+2); /*distance*/
	local[2]= w;
	goto CON389;
CON392:
	local[2]= NIL;
CON389:
	w = local[2];
	local[0]= w;
BLK388:
	ctx->vsp=local; return(local[0]);}

/*:distance-line*/
static pointer M393line_distance_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= *(ovafptr(argv[2],fqv[39]));
	local[1]= *(ovafptr(argv[2],fqv[40]));
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
	local[14]= argv[0]->c.obj.iv[2];
	local[15]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+16;
	w=(pointer)VMINUS(ctx,2,local+14); /*v-*/
	local[14]= w;
	local[15]= local[1];
	local[16]= local[0];
	ctx->vsp=local+17;
	w=(pointer)VMINUS(ctx,2,local+15); /*v-*/
	local[15]= w;
	local[16]= local[14];
	local[17]= local[15];
	ctx->vsp=local+18;
	w=(pointer)VINNERPRODUCT(ctx,2,local+16); /*v.*/
	local[16]= w;
	local[17]= local[14];
	local[18]= local[14];
	ctx->vsp=local+19;
	w=(pointer)VINNERPRODUCT(ctx,2,local+17); /*v.*/
	local[17]= w;
	local[18]= local[15];
	local[19]= local[15];
	ctx->vsp=local+20;
	w=(pointer)VINNERPRODUCT(ctx,2,local+18); /*v.*/
	local[18]= w;
	local[19]= argv[0]->c.obj.iv[1];
	local[20]= local[0];
	ctx->vsp=local+21;
	w=(pointer)VMINUS(ctx,2,local+19); /*v-*/
	local[19]= w;
	local[20]= local[16];
	{ double x,y;
		y=fltval(local[16]); x=fltval(local[20]);
		local[20]=(makeflt(x * y));}
	local[21]= local[17];
	{ double x,y;
		y=fltval(local[18]); x=fltval(local[21]);
		local[21]=(makeflt(x * y));}
	{ double x,y;
		y=fltval(local[21]); x=fltval(local[20]);
		local[20]=(makeflt(x - y));}
	local[7] = local[20];
	local[20]= local[7];
	ctx->vsp=local+21;
	w=(pointer)ABS(ctx,1,local+20); /*abs*/
	local[20]= w;
	local[21]= makeflt(1.00000000e-04);
	ctx->vsp=local+22;
	w=(pointer)GREATERP(ctx,2,local+20); /*>*/
	if (w==NIL) goto IF395;
	local[20]= local[19];
	local[21]= local[14];
	ctx->vsp=local+22;
	w=(pointer)VINNERPRODUCT(ctx,2,local+20); /*v.*/
	local[12] = w;
	local[20]= local[19];
	local[21]= local[15];
	ctx->vsp=local+22;
	w=(pointer)VINNERPRODUCT(ctx,2,local+20); /*v.*/
	local[13] = w;
	local[20]= local[18];
	local[21]= local[12];
	ctx->vsp=local+22;
	w=(pointer)TIMES(ctx,2,local+20); /***/
	local[20]= w;
	local[21]= local[16];
	local[22]= local[13];
	ctx->vsp=local+23;
	w=(pointer)TIMES(ctx,2,local+21); /***/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)MINUS(ctx,1,local+21); /*-*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)PLUS(ctx,2,local+20); /*+*/
	local[20]= w;
	local[21]= local[7];
	ctx->vsp=local+22;
	w=(pointer)QUOTIENT(ctx,2,local+20); /*/*/
	local[2] = w;
	local[20]= local[16];
	local[21]= local[12];
	ctx->vsp=local+22;
	w=(pointer)TIMES(ctx,2,local+20); /***/
	local[20]= w;
	local[21]= local[17];
	local[22]= local[13];
	ctx->vsp=local+23;
	w=(pointer)TIMES(ctx,2,local+21); /***/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)MINUS(ctx,1,local+21); /*-*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)PLUS(ctx,2,local+20); /*+*/
	local[20]= w;
	local[21]= local[7];
	ctx->vsp=local+22;
	w=(pointer)QUOTIENT(ctx,2,local+20); /*/*/
	local[3] = w;
	local[20]= makeflt(0.00000000e+00);
	local[21]= local[2];
	local[22]= makeflt(1.00000000e+00);
	ctx->vsp=local+23;
	w=(pointer)LESSP(ctx,3,local+20); /*<*/
	if (w==NIL) goto IF397;
	local[20]= makeflt(0.00000000e+00);
	local[21]= local[3];
	local[22]= makeflt(1.00000000e+00);
	ctx->vsp=local+23;
	w=(pointer)LESSP(ctx,3,local+20); /*<*/
	if (w==NIL) goto IF397;
	local[20]= argv[0];
	local[21]= fqv[37];
	local[22]= local[2];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= w;
	local[21]= argv[2];
	local[22]= fqv[37];
	local[23]= local[3];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,3,local+21); /*send*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)VDISTANCE(ctx,2,local+20); /*distance*/
	ctx->vsp=local+20;
	local[0]=w;
	goto BLK394;
	goto IF398;
IF397:
	local[20]= NIL;
IF398:
	goto IF396;
IF395:
	local[20]= NIL;
IF396:
	local[20]= argv[0];
	local[21]= fqv[41];
	local[22]= local[0];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[8] = w;
	local[20]= argv[0];
	local[21]= fqv[41];
	local[22]= local[1];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[9] = w;
	local[20]= argv[2];
	local[21]= fqv[41];
	local[22]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[10] = w;
	local[20]= argv[2];
	local[21]= fqv[41];
	local[22]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[11] = w;
	local[20]= local[8];
	local[21]= local[9];
	local[22]= local[10];
	local[23]= local[11];
	ctx->vsp=local+24;
	w=(pointer)MIN(ctx,4,local+20); /*min*/
	local[0]= w;
BLK394:
	ctx->vsp=local; return(local[0]);}

/*:distance*/
static pointer M399line_distance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0];
	local[2]= fqv[37];
	local[3]= argv[0];
	local[4]= fqv[38];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VDISTANCE(ctx,2,local+0); /*distance*/
	local[0]= w;
BLK400:
	ctx->vsp=local; return(local[0]);}

/*:distance*/
static pointer M401line_distance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[6])(ctx,1,local+0,&ftab[6],fqv[42]); /*float-vector-p*/
	if (w==NIL) goto CON404;
	local[0]= argv[0];
	local[1]= fqv[41];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON403;
CON404:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[43]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON405;
	local[0]= argv[0];
	local[1]= fqv[44];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON403;
CON405:
	local[0]= NIL;
CON403:
	w = local[0];
	local[0]= w;
BLK402:
	ctx->vsp=local; return(local[0]);}

/*:colinear-point*/
static pointer M406line_colinear_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT409;}
	local[0]= loadglobal(fqv[45]);
ENT409:
ENT408:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[7])(ctx,4,local+1,&ftab[7],fqv[46]); /*colinear-p*/
	local[0]= w;
BLK407:
	ctx->vsp=local; return(local[0]);}

/*:on-line-point*/
static pointer M410line_on_line_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT413;}
	local[0]= loadglobal(fqv[45]);
ENT413:
ENT412:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)VDISTANCE(ctx,2,local+3); /*distance*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+6;
	w=(pointer)VDISTANCE(ctx,2,local+4); /*distance*/
	{ double x,y;
		y=fltval(w); x=fltval(local[3]);
		local[3]=(makeflt(x + y));}
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+6;
	w=(pointer)VDISTANCE(ctx,2,local+4); /*distance*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)F93eps__(ctx,3,local+3); /*eps<=*/
	local[0]= w;
BLK411:
	ctx->vsp=local; return(local[0]);}

/*:colinear-line*/
static pointer M414line_colinear_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT417;}
	local[0]= loadglobal(fqv[45]);
ENT417:
ENT416:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[47];
	local[3]= argv[2]->c.obj.iv[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[47];
	local[4]= argv[2]->c.obj.iv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	local[3]= local[1];
	if (local[3]==NIL) goto AND418;
	local[3]= local[2];
	if (local[3]==NIL) goto AND418;
	local[3]= T;
AND418:
	w = local[3];
	local[0]= w;
BLK415:
	ctx->vsp=local; return(local[0]);}

/*:colinear-line-intersection*/
static pointer M419line_colinear_line_intersection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2]->c.obj.iv[1];
	local[1]= argv[2]->c.obj.iv[2];
	local[2]= argv[0];
	local[3]= fqv[48];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[48];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)GREATERP(ctx,2,local+6); /*>*/
	if (w==NIL) goto IF421;
	local[6]= local[2];
	local[7]= local[3];
	local[3] = local[6];
	local[2] = local[7];
	w = NIL;
	local[6]= w;
	goto IF422;
IF421:
	local[6]= NIL;
IF422:
	local[6]= local[3];
	local[7]= makeflt(0.00000000e+00);
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,2,local+6); /*<*/
	if (w!=NIL) goto OR427;
	local[6]= local[2];
	local[7]= makeflt(1.00000000e+00);
	ctx->vsp=local+8;
	w=(pointer)GREATERP(ctx,2,local+6); /*>*/
	if (w!=NIL) goto OR427;
	goto CON426;
OR427:
	local[6]= NIL;
	goto CON425;
CON426:
	local[6]= makeflt(0.00000000e+00);
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)MAX(ctx,2,local+6); /*max*/
	local[4] = w;
	local[6]= makeflt(1.00000000e+00);
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)MIN(ctx,2,local+6); /*min*/
	local[5] = w;
	local[6]= argv[0];
	local[7]= fqv[37];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= fqv[37];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)F106make_line(ctx,2,local+6); /*make-line*/
	local[6]= w;
	goto CON425;
CON428:
	local[6]= NIL;
CON425:
	w = local[6];
	local[0]= w;
BLK420:
	ctx->vsp=local; return(local[0]);}

/*:coplanar*/
static pointer M429line_coplanar(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT432;}
	local[0]= loadglobal(fqv[45]);
ENT432:
ENT431:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= argv[2]->c.obj.iv[1];
	local[4]= argv[2]->c.obj.iv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[8])(ctx,5,local+1,&ftab[8],fqv[49]); /*coplanar-p*/
	local[0]= w;
BLK430:
	ctx->vsp=local; return(local[0]);}

/*:project*/
static pointer M433line_project(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[50];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= fqv[50];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
BLK434:
	ctx->vsp=local; return(local[0]);}

/*:intersection*/
static pointer M435line_intersection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= argv[2]->c.obj.iv[1];
	local[3]= argv[2]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)LINEINTERSECTION3(ctx,4,local+0); /*line-intersection3*/
	local[0]= w;
BLK436:
	ctx->vsp=local; return(local[0]);}

/*:intersect-line*/
static pointer M437line_intersect_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT440;}
	local[0]= loadglobal(fqv[35]);
ENT440:
ENT439:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= argv[2]->c.obj.iv[1];
	local[4]= argv[2]->c.obj.iv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LINEINTERSECTION3(ctx,5,local+1); /*line-intersection3*/
	local[1]= w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	if (local[1]!=NIL) goto CON442;
	local[8]= argv[0];
	local[9]= fqv[47];
	local[10]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[2] = w;
	if (local[2]!=NIL) goto IF443;
	w = fqv[36];
	ctx->vsp=local+8;
	local[0]=w;
	goto BLK438;
	goto IF444;
IF443:
	local[8]= NIL;
IF444:
	local[8]= argv[0];
	local[9]= fqv[47];
	local[10]= argv[2]->c.obj.iv[2];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[3] = w;
	if (local[3]!=NIL) goto IF445;
	w = fqv[36];
	ctx->vsp=local+8;
	local[0]=w;
	goto BLK438;
	goto IF446;
IF445:
	local[8]= NIL;
IF446:
	local[8]= local[3];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)LESSP(ctx,2,local+8); /*<*/
	if (w==NIL) goto IF447;
	local[8]= local[3];
	local[9]= local[2];
	local[2] = local[8];
	local[3] = local[9];
	w = NIL;
	local[8]= w;
	goto IF448;
IF447:
	local[8]= NIL;
IF448:
	local[8]= local[3];
	local[9]= makeflt(0.00000000e+00);
	ctx->vsp=local+10;
	w=(pointer)F91eps_(ctx,2,local+8); /*eps<*/
	if (w!=NIL) goto OR453;
	local[8]= local[2];
	local[9]= makeflt(1.00000000e+00);
	ctx->vsp=local+10;
	w=(pointer)F92eps_(ctx,2,local+8); /*eps>*/
	if (w!=NIL) goto OR453;
	goto IF451;
OR453:
	w = fqv[51];
	ctx->vsp=local+8;
	local[0]=w;
	goto BLK438;
	goto IF452;
IF451:
	local[8]= NIL;
IF452:
	local[8]= argv[2];
	local[9]= fqv[47];
	local[10]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[6] = w;
	local[8]= argv[2];
	local[9]= fqv[47];
	local[10]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[7] = w;
	if (local[6]==NIL) goto AND456;
	if (local[7]==NIL) goto AND456;
	goto IF454;
AND456:
	w = fqv[36];
	ctx->vsp=local+8;
	local[0]=w;
	goto BLK438;
	goto IF455;
IF454:
	local[8]= NIL;
IF455:
	local[8]= local[7];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)LESSP(ctx,2,local+8); /*<*/
	if (w==NIL) goto IF457;
	local[8]= local[7];
	local[9]= local[6];
	local[6] = local[8];
	local[7] = local[9];
	w = NIL;
	local[8]= w;
	goto IF458;
IF457:
	local[8]= NIL;
IF458:
	local[8]= fqv[52];
	local[9]= makeflt(0.00000000e+00);
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)MAX(ctx,2,local+9); /*max*/
	local[9]= w;
	local[10]= makeflt(1.00000000e+00);
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)MIN(ctx,2,local+10); /*min*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,2,local+9); /*list*/
	local[9]= w;
	local[10]= makeflt(0.00000000e+00);
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)MAX(ctx,2,local+10); /*max*/
	local[10]= w;
	local[11]= makeflt(1.00000000e+00);
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(pointer)MIN(ctx,2,local+11); /*min*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,2,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,3,local+8); /*list*/
	local[8]= w;
	goto CON441;
CON442:
	local[8]= makeflt(0.00000000e+00);
	local[9]= local[2];
	local[10]= makeflt(1.00000000e+00);
	ctx->vsp=local+11;
	w=(pointer)F97eps_in_range(ctx,3,local+8); /*eps-in-range*/
	if (w==NIL) goto CON461;
	local[8]= makeflt(0.00000000e+00);
	local[9]= local[3];
	local[10]= makeflt(1.00000000e+00);
	ctx->vsp=local+11;
	w=(pointer)F97eps_in_range(ctx,3,local+8); /*eps-in-range*/
	if (w==NIL) goto CON461;
	local[8]= fqv[53];
	local[9]= local[2];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,3,local+8); /*list*/
	local[8]= w;
	goto CON441;
CON461:
	local[8]= NIL;
	goto CON441;
CON462:
	local[8]= NIL;
CON441:
	w = local[8];
	local[0]= w;
BLK438:
	ctx->vsp=local; return(local[0]);}

/*make-line*/
static pointer F106make_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[43]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[24];
	local[3]= fqv[54];
	local[4]= argv[0];
	local[5]= fqv[55];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK463:
	ctx->vsp=local; return(local[0]);}

/*:faces*/
static pointer M465edge_faces(ctx,n,argv,env)
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
BLK466:
	ctx->vsp=local; return(local[0]);}

/*:pvertex*/
static pointer M467edge_pvertex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[3]!=local[0]) goto CON470;
	local[0]= argv[0]->c.obj.iv[1];
	goto CON469;
CON470:
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[4]!=local[0]) goto CON471;
	local[0]= argv[0]->c.obj.iv[2];
	goto CON469;
CON471:
	local[0]= fqv[56];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto CON469;
CON472:
	local[0]= NIL;
CON469:
	w = local[0];
	local[0]= w;
BLK468:
	ctx->vsp=local; return(local[0]);}

/*:nvertex*/
static pointer M473edge_nvertex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[3]!=local[0]) goto CON476;
	local[0]= argv[0]->c.obj.iv[2];
	goto CON475;
CON476:
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[4]!=local[0]) goto CON477;
	local[0]= argv[0]->c.obj.iv[1];
	goto CON475;
CON477:
	local[0]= fqv[57];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto CON475;
CON478:
	local[0]= NIL;
CON475:
	w = local[0];
	local[0]= w;
BLK474:
	ctx->vsp=local; return(local[0]);}

/*:next-edge*/
static pointer M479edge_next_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[58];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK480:
	ctx->vsp=local; return(local[0]);}

/*:next-vertex*/
static pointer M481edge_next_vertex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[58];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[55];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK482:
	ctx->vsp=local; return(local[0]);}

/*:direction*/
static pointer M483edge_direction(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT486;}
	local[0]= argv[0]->c.obj.iv[3];
ENT486:
ENT485:
	if (n>3) maerror();
	local[1]= local[0];
	if (argv[0]->c.obj.iv[3]!=local[1]) goto CON488;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VNORMALIZE(ctx,1,local+1); /*normalize-vector*/
	local[1]= w;
	goto CON487;
CON488:
	local[1]= local[0];
	if (argv[0]->c.obj.iv[4]!=local[1]) goto CON489;
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VNORMALIZE(ctx,1,local+1); /*normalize-vector*/
	local[1]= w;
	goto CON487;
CON489:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F86facep(ctx,1,local+1); /*facep*/
	if (w==NIL) goto CON490;
	local[1]= NIL;
	local[2]= local[0];
	local[3]= fqv[59];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
WHL492:
	if (local[2]==NIL) goto WHX493;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[0];
	local[4]= local[1];
	local[5]= fqv[60];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	if (memq(local[3],w)==NIL) goto IF496;
	local[3]= argv[0];
	local[4]= fqv[61];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK484;
	goto IF497;
IF496:
	local[3]= NIL;
IF497:
	goto WHL492;
WHX493:
	local[3]= NIL;
BLK494:
	w = NIL;
	local[1]= fqv[62];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto CON487;
CON490:
	local[1]= fqv[63];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto CON487;
CON498:
	local[1]= NIL;
CON487:
	w = local[1];
	local[0]= w;
BLK484:
	ctx->vsp=local; return(local[0]);}

/*:next-edge-angle*/
static pointer M499edge_next_edge_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[61];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= fqv[58];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[61];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= fqv[64];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F76vector_angle(ctx,3,local+0); /*vector-angle*/
	local[0]= w;
BLK500:
	ctx->vsp=local; return(local[0]);}

/*:previous-edge-angle*/
static pointer M501edge_previous_edge_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[61];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= fqv[65];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[61];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= fqv[64];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F76vector_angle(ctx,3,local+0); /*vector-angle*/
	local[0]= w;
BLK502:
	ctx->vsp=local; return(local[0]);}

/*:body*/
static pointer M503edge_body(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[3]==NIL) goto CON506;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[66];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto CON505;
CON506:
	if (argv[0]->c.obj.iv[4]==NIL) goto CON507;
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= fqv[66];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto CON505;
CON507:
	local[0]= NIL;
CON505:
	w = local[0];
	local[0]= w;
BLK504:
	ctx->vsp=local; return(local[0]);}

/*:pface*/
static pointer M508edge_pface(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON511;
	local[0]= argv[3];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON511;
	local[0]= argv[0]->c.obj.iv[3];
	goto CON510;
CON511:
	local[0]= argv[3];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON512;
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON512;
	local[0]= argv[0]->c.obj.iv[4];
	goto CON510;
CON512:
	local[0]= fqv[67];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto CON510;
CON513:
	local[0]= NIL;
CON510:
	w = local[0];
	local[0]= w;
BLK509:
	ctx->vsp=local; return(local[0]);}

/*:nface*/
static pointer M514edge_nface(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON517;
	local[0]= argv[3];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON517;
	local[0]= argv[0]->c.obj.iv[4];
	goto CON516;
CON517:
	local[0]= argv[3];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON518;
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON518;
	local[0]= argv[0]->c.obj.iv[3];
	goto CON516;
CON518:
	local[0]= fqv[68];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto CON516;
CON519:
	local[0]= NIL;
CON516:
	w = local[0];
	local[0]= w;
BLK515:
	ctx->vsp=local; return(local[0]);}

/*:another-face*/
static pointer M520edge_another_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[3]!=local[0]) goto IF522;
	local[0]= argv[0]->c.obj.iv[4];
	goto IF523;
IF522:
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[4]!=local[0]) goto IF524;
	local[0]= argv[0]->c.obj.iv[3];
	goto IF525;
IF524:
	local[0]= fqv[69];
	ctx->vsp=local+1;
	w=(*ftab[9])(ctx,1,local+0,&ftab[9],fqv[70]); /*warn*/
	local[0]= w;
IF525:
IF523:
	w = local[0];
	local[0]= w;
BLK521:
	ctx->vsp=local; return(local[0]);}

/*:binormal*/
static pointer M526edge_binormal(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[3]!=local[0]) goto CON529;
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	goto CON528;
CON529:
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[4]!=local[0]) goto CON530;
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	goto CON528;
CON530:
	local[0]= argv[0];
	local[1]= fqv[71];
	local[2]= fqv[72];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON528;
CON531:
	local[0]= NIL;
CON528:
	local[1]= argv[2];
	local[2]= fqv[64];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+0); /*v**/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)VNORMALIZE(ctx,1,local+0); /*normalize-vector*/
	local[0]= w;
BLK527:
	ctx->vsp=local; return(local[0]);}

/*:angle*/
static pointer M532edge_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK533:
	ctx->vsp=local; return(local[0]);}

/*:approximated-p*/
static pointer M534edge_approximated_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[6];
	w = makeint(1);
	local[0]= (pointer)((eusinteger_t)local[0] & (eusinteger_t)w);
	w = ((makeint(1))==(local[0])?T:NIL);
	local[0]= w;
BLK535:
	ctx->vsp=local; return(local[0]);}

/*:flags*/
static pointer M536edge_flags(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK537:
	ctx->vsp=local; return(local[0]);}

/*:contourp*/
static pointer M538edge_contourp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[0]->c.obj.iv[3]==NIL) goto IF540;
	if (argv[0]->c.obj.iv[4]==NIL) goto IF540;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[73];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[4];
	local[2]= fqv[73];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= local[0];
	local[3]= makeflt(0.00000000e+00);
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	local[2]= w;
	if (w==NIL) goto AND543;
	local[2]= local[1];
	local[3]= makeflt(0.00000000e+00);
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	local[2]= w;
AND543:
	if (local[2]!=NIL) goto OR542;
	local[2]= local[0];
	local[3]= makeflt(0.00000000e+00);
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	local[2]= w;
	if (w==NIL) goto AND544;
	local[2]= local[1];
	local[3]= makeflt(0.00000000e+00);
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	local[2]= w;
AND544:
OR542:
	w = local[2];
	local[0]= w;
	goto IF541;
IF540:
	local[0]= T;
IF541:
	w = local[0];
	local[0]= w;
BLK539:
	ctx->vsp=local; return(local[0]);}

/*:set-approximated-flag*/
static pointer M545edge_set_approximated_flag(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT548;}
	local[0]= makeflt(7.00000000e-01);
ENT548:
ENT547:
	if (n>3) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,1,local+1); /*-*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,3,local+1); /*<*/
	if (w==NIL) goto IF549;
	local[1]= argv[0]->c.obj.iv[6];
	w = makeint(1);
	argv[0]->c.obj.iv[6] = (pointer)((eusinteger_t)local[1] | (eusinteger_t)w);
	local[1]= argv[0]->c.obj.iv[6];
	goto IF550;
IF549:
	local[1]= argv[0]->c.obj.iv[6];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)LOGNOT(ctx,1,local+2); /*lognot*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LOGAND(ctx,2,local+1); /*logand*/
	argv[0]->c.obj.iv[6] = w;
	local[1]= argv[0]->c.obj.iv[6];
IF550:
	w = local[1];
	local[0]= w;
BLK546:
	ctx->vsp=local; return(local[0]);}

/*:invert*/
static pointer M551edge_invert(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[0] = argv[0]->c.obj.iv[4];
	argv[0]->c.obj.iv[4] = argv[0]->c.obj.iv[3];
	argv[0]->c.obj.iv[3] = local[0];
	w = argv[0]->c.obj.iv[3];
	w = argv[0];
	local[0]= w;
BLK552:
	ctx->vsp=local; return(local[0]);}

/*:set-angle*/
static pointer M553edge_set_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[3]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[4]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)VMINUS(ctx,2,local+2); /*v-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VNORMALIZE(ctx,1,local+2); /*normalize-vector*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F76vector_angle(ctx,3,local+0); /*vector-angle*/
	argv[0]->c.obj.iv[5] = w;
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK554:
	ctx->vsp=local; return(local[0]);}

/*:set-face*/
static pointer M555edge_set_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[1]!=local[0]) goto CON558;
	local[0]= argv[3];
	if (argv[0]->c.obj.iv[2]!=local[0]) goto CON558;
	argv[0]->c.obj.iv[3] = argv[4];
	local[0]= argv[0]->c.obj.iv[3];
	goto CON557;
CON558:
	local[0]= argv[3];
	if (argv[0]->c.obj.iv[1]!=local[0]) goto CON559;
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[2]!=local[0]) goto CON559;
	argv[0]->c.obj.iv[4] = argv[4];
	local[0]= argv[0]->c.obj.iv[4];
	goto CON557;
CON559:
	local[0]= argv[0];
	local[1]= fqv[71];
	local[2]= fqv[74];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON557;
CON560:
	local[0]= NIL;
CON557:
	w = local[0];
	local[0]= w;
BLK556:
	ctx->vsp=local; return(local[0]);}

/*:contact*/
static pointer M561edge_contact(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[75];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= loadglobal(fqv[23]);
	local[2]= loadglobal(fqv[76]);
	local[3]= local[0];
	if (fqv[36]==local[3]) goto IF563;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)VMINUS(ctx,2,local+3); /*v-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)VNORM(ctx,1,local+3); /*norm*/
	local[3]= w;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)LESSP(ctx,2,local+3); /*<*/
	if (w==NIL) goto IF565;
	local[3]= local[2];
	local[4]= argv[0];
	local[5]= fqv[48];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= makeflt(1.00000000e+00);
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,3,local+3); /*<*/
	if (w==NIL) goto IF565;
	local[3]= makeflt(-1.00000000e+00);
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	local[4]= argv[2];
	local[5]= fqv[48];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= makeflt(1.00000000e+00);
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,3,local+3); /*<*/
	if (w==NIL) goto IF565;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	goto IF566;
IF565:
	local[3]= NIL;
IF566:
	goto IF564;
IF563:
	local[3]= NIL;
IF564:
	w = local[3];
	local[0]= w;
BLK562:
	ctx->vsp=local; return(local[0]);}

/*:neighborpoints*/
static pointer M567edge_neighborpoints(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[77];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= makeflt(2.00000000e+00);
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,2,local+1); /*scale*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[77];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= *(ovafptr(argv[0]->c.obj.iv[3],fqv[78]));
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)VMINUS(ctx,2,local+4); /*v-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+3); /*v**/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)VPLUS(ctx,2,local+2); /*v+*/
	local[2]= w;
	local[3]= argv[2];
	local[4]= *(ovafptr(argv[0]->c.obj.iv[4],fqv[78]));
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+7;
	w=(pointer)VMINUS(ctx,2,local+5); /*v-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+4); /*v**/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)VPLUS(ctx,2,local+3); /*v+*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,4,local+0); /*list*/
	local[0]= w;
BLK568:
	ctx->vsp=local; return(local[0]);}

/*:anothervertex*/
static pointer M569edge_anothervertex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)VNORM(ctx,1,local+0); /*norm*/
	local[0]= makeflt((double)fabs(fltval(w)));
	local[1]= loadglobal(fqv[79]);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF571;
	local[0]= argv[0]->c.obj.iv[1];
	goto IF572;
IF571:
	local[0]= argv[0]->c.obj.iv[2];
IF572:
	w = local[0];
	local[0]= w;
BLK570:
	ctx->vsp=local; return(local[0]);}

/*:color*/
static pointer M573edge_color(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT576;}
	local[0]= NIL;
ENT576:
ENT575:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF577;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[80];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= w;
	goto IF578;
IF577:
	local[1]= argv[0];
	local[2]= fqv[80];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[0] = w;
	if (local[0]==NIL) goto IF579;
	local[1]= local[0];
	goto IF580;
IF579:
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[80];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
IF580:
IF578:
	w = local[1];
	local[0]= w;
BLK574:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M581edge_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST583:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[81], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY584;
	local[1] = NIL;
KEY584:
	if (n & (1<<1)) goto KEY585;
	local[2] = NIL;
KEY585:
	if (n & (1<<2)) goto KEY586;
	local[3] = NIL;
KEY586:
	if (n & (1<<3)) goto KEY587;
	local[4] = NIL;
KEY587:
	if (n & (1<<4)) goto KEY588;
	local[5] = makeint(0);
KEY588:
	local[6]= (pointer)get_sym_func(fqv[82]);
	local[7]= argv[0];
	local[8]= *(ovafptr(argv[1],fqv[12]));
	local[9]= fqv[24];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)APPLY(ctx,5,local+6); /*apply*/
	if (local[1]==NIL) goto IF589;
	argv[0]->c.obj.iv[3] = local[1];
	local[6]= argv[0]->c.obj.iv[3];
	goto IF590;
IF589:
	local[6]= NIL;
IF590:
	if (local[2]==NIL) goto IF591;
	argv[0]->c.obj.iv[4] = local[2];
	local[6]= argv[0]->c.obj.iv[4];
	goto IF592;
IF591:
	local[6]= NIL;
IF592:
	if (local[3]==NIL) goto IF593;
	argv[0]->c.obj.iv[5] = local[3];
	local[6]= argv[0]->c.obj.iv[5];
	goto IF594;
IF593:
	local[6]= NIL;
IF594:
	argv[0]->c.obj.iv[6] = local[5];
	if (local[4]==NIL) goto IF595;
	local[6]= argv[0];
	local[7]= fqv[83];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	goto IF596;
IF595:
	local[6]= NIL;
IF596:
	w = argv[0];
	local[0]= w;
BLK582:
	ctx->vsp=local; return(local[0]);}

/*:center-coordinates*/
static pointer M597edge_center_coordinates(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)VNORMALIZE(ctx,1,local+0); /*normalize-vector*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[84];
	ctx->vsp=local+3;
	w=(pointer)VDISTANCE(ctx,2,local+1); /*distance*/
	local[1]= w;
	{ double left,right;
		right=fltval(makeflt(1.00000000e-04)); left=fltval(local[1]);
	if (left >= right) goto IF599;}
	local[1]= fqv[85];
	goto IF600;
IF599:
	local[1]= fqv[86];
IF600:
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+2); /*v**/
	local[2]= w;
	local[3]= local[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+3); /*v**/
	local[1] = w;
	local[3]= loadglobal(fqv[87]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[24];
	local[6]= fqv[88];
	local[7]= local[1];
	local[8]= local[2];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(*ftab[10])(ctx,3,local+7,&ftab[10],fqv[89]); /*matrix*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)TRANSPOSE(ctx,1,local+7); /*transpose*/
	local[7]= w;
	local[8]= fqv[90];
	local[9]= makeflt(5.00000000e-01);
	local[10]= argv[0]->c.obj.iv[2];
	local[11]= argv[0]->c.obj.iv[1];
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)VPLUS(ctx,3,local+10); /*v+*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SCALEVEC(ctx,2,local+9); /*scale*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,6,local+4); /*send*/
	w = local[3];
	local[0]= w;
BLK598:
	ctx->vsp=local; return(local[0]);}

/*:pwing*/
static pointer M602edge_pwing(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[91];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= local[0];
WHL605:
	if (local[2]==NIL) goto WHX606;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	if (argv[0]==local[3]) goto IF609;
	local[3]= local[1]->c.obj.iv[1];
	if (argv[0]->c.obj.iv[1]==local[3]) goto OR611;
	local[3]= local[1]->c.obj.iv[2];
	if (argv[0]->c.obj.iv[1]==local[3]) goto OR611;
	goto IF609;
OR611:
	w = local[1];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK603;
	goto IF610;
IF609:
	local[3]= NIL;
IF610:
	goto WHL605;
WHX606:
	local[3]= NIL;
BLK607:
	w = NIL;
	local[1]= fqv[92];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[0]= w;
BLK603:
	ctx->vsp=local; return(local[0]);}

/*:pcwing*/
static pointer M612edge_pcwing(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[91];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= local[0];
WHL615:
	if (local[2]==NIL) goto WHX616;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	if (argv[0]==local[3]) goto IF619;
	local[3]= local[1]->c.obj.iv[1];
	if (argv[0]->c.obj.iv[2]==local[3]) goto OR621;
	local[3]= local[1]->c.obj.iv[2];
	if (argv[0]->c.obj.iv[2]==local[3]) goto OR621;
	goto IF619;
OR621:
	w = local[1];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK613;
	goto IF620;
IF619:
	local[3]= NIL;
IF620:
	goto WHL615;
WHX616:
	local[3]= NIL;
BLK617:
	w = NIL;
	local[1]= fqv[93];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[0]= w;
BLK613:
	ctx->vsp=local; return(local[0]);}

/*:nwing*/
static pointer M622edge_nwing(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= fqv[91];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= local[0];
WHL625:
	if (local[2]==NIL) goto WHX626;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	if (argv[0]==local[3]) goto IF629;
	local[3]= local[1]->c.obj.iv[1];
	if (argv[0]->c.obj.iv[2]==local[3]) goto OR631;
	local[3]= local[1]->c.obj.iv[2];
	if (argv[0]->c.obj.iv[2]==local[3]) goto OR631;
	goto IF629;
OR631:
	w = local[1];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK623;
	goto IF630;
IF629:
	local[3]= NIL;
IF630:
	goto WHL625;
WHX626:
	local[3]= NIL;
BLK627:
	w = NIL;
	local[1]= fqv[94];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[0]= w;
BLK623:
	ctx->vsp=local; return(local[0]);}

/*:ncwing*/
static pointer M632edge_ncwing(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= fqv[91];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= local[0];
WHL635:
	if (local[2]==NIL) goto WHX636;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	if (argv[0]==local[3]) goto IF639;
	local[3]= local[1]->c.obj.iv[1];
	if (argv[0]->c.obj.iv[1]==local[3]) goto OR641;
	local[3]= local[1]->c.obj.iv[2];
	if (argv[0]->c.obj.iv[1]==local[3]) goto OR641;
	goto IF639;
OR641:
	w = local[1];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK633;
	goto IF640;
IF639:
	local[3]= NIL;
IF640:
	goto WHL635;
WHX636:
	local[3]= NIL;
BLK637:
	w = NIL;
	local[1]= fqv[95];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[0]= w;
BLK633:
	ctx->vsp=local; return(local[0]);}

/*:connected-vertex*/
static pointer M642edge_connected_vertex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2]->c.obj.iv[1];
	if (argv[0]->c.obj.iv[1]!=local[0]) goto CON645;
	local[0]= argv[0]->c.obj.iv[1];
	goto CON644;
CON645:
	local[0]= argv[2]->c.obj.iv[1];
	if (argv[0]->c.obj.iv[2]!=local[0]) goto CON646;
	local[0]= argv[0]->c.obj.iv[2];
	goto CON644;
CON646:
	local[0]= argv[2]->c.obj.iv[2];
	if (argv[0]->c.obj.iv[1]!=local[0]) goto CON647;
	local[0]= argv[0]->c.obj.iv[1];
	goto CON644;
CON647:
	local[0]= argv[2]->c.obj.iv[2];
	if (argv[0]->c.obj.iv[2]!=local[0]) goto CON648;
	local[0]= argv[0]->c.obj.iv[2];
	goto CON644;
CON648:
	local[0]= fqv[96];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto CON644;
CON649:
	local[0]= NIL;
CON644:
	w = local[0];
	local[0]= w;
BLK643:
	ctx->vsp=local; return(local[0]);}

/*:replace-face*/
static pointer M650edge_replace_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON653;
	argv[0]->c.obj.iv[3] = argv[3];
	local[0]= argv[0]->c.obj.iv[3];
	goto CON652;
CON653:
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON654;
	argv[0]->c.obj.iv[4] = argv[3];
	local[0]= argv[0]->c.obj.iv[4];
	goto CON652;
CON654:
	local[0]= fqv[97];
	local[1]= argv[0];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,3,local+0); /*error*/
	local[0]= w;
	goto CON652;
CON655:
	local[0]= NIL;
CON652:
	w = local[0];
	local[0]= w;
BLK651:
	ctx->vsp=local; return(local[0]);}

/*winged-edge-p*/
static pointer F107winged_edge_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[98]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK656:
	ctx->vsp=local; return(local[0]);}

/*:set-wings*/
static pointer M657winged_edge_set_wings(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[12]));
	local[2]= fqv[99];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	argv[0]->c.obj.iv[7] = w;
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[12]));
	local[2]= fqv[100];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	argv[0]->c.obj.iv[9] = w;
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[12]));
	local[2]= fqv[101];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	argv[0]->c.obj.iv[8] = w;
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[12]));
	local[2]= fqv[102];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	argv[0]->c.obj.iv[10] = w;
	w = argv[0];
	local[0]= w;
BLK658:
	ctx->vsp=local; return(local[0]);}

/*:pwing*/
static pointer M659winged_edge_pwing(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[7];
	local[0]= w;
BLK660:
	ctx->vsp=local; return(local[0]);}

/*:nwing*/
static pointer M661winged_edge_nwing(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[9];
	local[0]= w;
BLK662:
	ctx->vsp=local; return(local[0]);}

/*:pcwing*/
static pointer M663winged_edge_pcwing(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK664:
	ctx->vsp=local; return(local[0]);}

/*:ncwing*/
static pointer M665winged_edge_ncwing(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[10];
	local[0]= w;
BLK666:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M667winged_edge_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST669:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[103], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY670;
	local[1] = NIL;
KEY670:
	if (n & (1<<1)) goto KEY671;
	local[2] = NIL;
KEY671:
	if (n & (1<<2)) goto KEY672;
	local[3] = NIL;
KEY672:
	if (n & (1<<3)) goto KEY673;
	local[4] = NIL;
KEY673:
	local[5]= (pointer)get_sym_func(fqv[82]);
	local[6]= argv[0];
	local[7]= *(ovafptr(argv[1],fqv[12]));
	local[8]= fqv[24];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)APPLY(ctx,5,local+5); /*apply*/
	if (local[1]==NIL) goto IF674;
	argv[0]->c.obj.iv[7] = local[1];
	local[5]= argv[0]->c.obj.iv[7];
	goto IF675;
IF674:
	local[5]= NIL;
IF675:
	if (local[2]==NIL) goto IF676;
	argv[0]->c.obj.iv[9] = local[2];
	local[5]= argv[0]->c.obj.iv[9];
	goto IF677;
IF676:
	local[5]= NIL;
IF677:
	if (local[3]==NIL) goto IF678;
	argv[0]->c.obj.iv[8] = local[3];
	local[5]= argv[0]->c.obj.iv[8];
	goto IF679;
IF678:
	local[5]= NIL;
IF679:
	if (local[4]==NIL) goto IF680;
	argv[0]->c.obj.iv[10] = local[4];
	local[5]= argv[0]->c.obj.iv[10];
	goto IF681;
IF680:
	local[5]= NIL;
IF681:
	w = argv[0];
	local[0]= w;
BLK668:
	ctx->vsp=local; return(local[0]);}

/*:id*/
static pointer M683plane_id(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = NIL;
	local[0]= w;
BLK684:
	ctx->vsp=local; return(local[0]);}

/*:normal*/
static pointer M685plane_normal(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK686:
	ctx->vsp=local; return(local[0]);}

/*:distance*/
static pointer M687plane_distance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	local[0]= w;
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[2]); x=fltval(local[0]);
		local[0]=(makeflt(x + y));}
	w = local[0];
	local[0]= w;
BLK688:
	ctx->vsp=local; return(local[0]);}

/*:plane-distance*/
static pointer M689plane_plane_distance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	local[0]= w;
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[2]); x=fltval(local[0]);
		local[0]=(makeflt(x + y));}
	w = local[0];
	local[0]= w;
BLK690:
	ctx->vsp=local; return(local[0]);}

/*:on-plane-p*/
static pointer M691plane_on_plane_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT694;}
	local[0]= loadglobal(fqv[8]);
ENT694:
ENT693:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[104];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)ABS(ctx,1,local+1); /*abs*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F93eps__(ctx,2,local+1); /*eps<=*/
	local[0]= w;
BLK692:
	ctx->vsp=local; return(local[0]);}

/*:coplanar-point*/
static pointer M695plane_coplanar_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT698;}
	local[0]= loadglobal(fqv[45]);
ENT698:
ENT697:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= w;
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[2]); x=fltval(local[1]);
		local[1]=(makeflt(x + y));}
	local[2]= makeflt(0.00000000e+00);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F90eps_(ctx,3,local+1); /*eps=*/
	local[0]= w;
BLK696:
	ctx->vsp=local; return(local[0]);}

/*:coplanar-line*/
static pointer M699plane_coplanar_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT702;}
	local[0]= loadglobal(fqv[45]);
ENT702:
ENT701:
	if (n>4) maerror();
	local[1]= argv[2]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= w;
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[2]); x=fltval(local[1]);
		local[1]=(makeflt(x + y));}
	local[2]= makeflt(0.00000000e+00);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F90eps_(ctx,3,local+1); /*eps=*/
	local[1]= w;
	if (w==NIL) goto AND703;
	local[1]= argv[2]->c.obj.iv[2];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= w;
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[2]); x=fltval(local[1]);
		local[1]=(makeflt(x + y));}
	local[2]= makeflt(0.00000000e+00);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F90eps_(ctx,3,local+1); /*eps=*/
	local[1]= w;
AND703:
	w = local[1];
	local[0]= w;
BLK700:
	ctx->vsp=local; return(local[0]);}

/*:intersection*/
static pointer M704plane_intersection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= w;
	local[2]= local[1];
	{ double x,y;
		y=fltval(makeflt(-(fltval(local[0])))); x=fltval(local[2]);
		local[2]=(makeflt(x + y));}
	local[3]= argv[0]->c.obj.iv[2];
	{ double x,y;
		y=fltval(local[1]); x=fltval(local[3]);
		local[3]=(makeflt(x + y));}
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[0]= w;
BLK705:
	ctx->vsp=local; return(local[0]);}

/*:intersect-edge*/
static pointer M706plane_intersect_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[26];
	local[2]= argv[2]->c.obj.iv[1];
	local[3]= argv[2]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	local[1]= makeflt(0.00000000e+00);
	local[2]= local[0];
	local[3]= makeflt(1.00000000e+00);
	ctx->vsp=local+4;
	w=(pointer)F97eps_in_range(ctx,3,local+1); /*eps-in-range*/
	if (w==NIL) goto IF708;
	local[1]= local[0];
	local[2]= argv[2];
	local[3]= fqv[37];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[1]= w;
	goto IF709;
IF708:
	local[1]= makeflt(0.00000000e+00);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)NUMEQUAL(ctx,2,local+1); /*=*/
	if (w!=NIL) goto OR712;
	local[1]= makeflt(1.00000000e+00);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)NUMEQUAL(ctx,2,local+1); /*=*/
	if (w!=NIL) goto OR712;
	goto IF710;
OR712:
	local[1]= T;
	local[2]= fqv[105];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,2,local+1); /*format*/
	local[1]= w;
	goto IF711;
IF710:
	local[1]= NIL;
IF711:
IF709:
	w = local[1];
	local[0]= w;
BLK707:
	ctx->vsp=local; return(local[0]);}

/*:foot*/
static pointer M713plane_foot(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	local[0]= w;
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[2]); x=fltval(local[0]);
		local[0]=(makeflt(x + y));}
	local[1]= argv[2];
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)SCALEVEC(ctx,2,local+2); /*scale*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[0]= w;
BLK714:
	ctx->vsp=local; return(local[0]);}

/*:original-body*/
static pointer M715plane_original_body(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = NIL;
	local[0]= w;
BLK716:
	ctx->vsp=local; return(local[0]);}

/*:brightness*/
static pointer M717plane_brightness(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeflt(1.00000000e+00);
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= w;
	local[2]= makeflt(2.00000000e+00);
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
BLK718:
	ctx->vsp=local; return(local[0]);}

/*:project*/
static pointer M719plane_project(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT722;}
	local[0]= makeint(0);
	local[1]= makeint(0);
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
ENT722:
ENT721:
	if (n>3) maerror();
	local[1]= local[0];
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0];
	local[4]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)VINNERPRODUCT(ctx,2,local+3); /*v.*/
	{ double x,y;
		y=fltval(w); x=fltval(local[2]);
		local[2]=(makeflt(x + y));}
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)SCALEVEC(ctx,2,local+2); /*scale*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[0]= w;
BLK720:
	ctx->vsp=local; return(local[0]);}

/*:separation*/
static pointer M723plane_separation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= makeint(0);
	local[2]= makeint(0);
	local[3]= NIL;
	local[4]= argv[2];
WHL726:
	if (local[4]==NIL) goto WHX727;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= argv[0];
	local[6]= fqv[73];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[0] = w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[5]= w;
	local[6]= loadglobal(fqv[79]);
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto IF730;
	local[5]= local[0];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[11])(ctx,1,local+5,&ftab[11],fqv[106]); /*minusp*/
	if (w==NIL) goto IF732;
	w = NIL;
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK724;
	goto IF733;
IF732:
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[5]= w;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)ABS(ctx,1,local+6); /*abs*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto IF734;
	local[1] = local[0];
	local[5]= local[1];
	goto IF735;
IF734:
	local[5]= NIL;
IF735:
IF733:
	goto IF731;
IF730:
	local[5]= NIL;
IF731:
	goto WHL726;
WHX727:
	local[5]= NIL;
BLK728:
	w = NIL;
	local[3]= NIL;
	local[4]= argv[3];
WHL737:
	if (local[4]==NIL) goto WHX738;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= argv[0];
	local[6]= fqv[73];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[0] = w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[5]= w;
	local[6]= loadglobal(fqv[79]);
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto IF741;
	local[5]= local[0];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[11])(ctx,1,local+5,&ftab[11],fqv[106]); /*minusp*/
	if (w==NIL) goto IF743;
	w = NIL;
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK724;
	goto IF744;
IF743:
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[5]= w;
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)ABS(ctx,1,local+6); /*abs*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto IF745;
	local[2] = local[0];
	local[5]= local[2];
	goto IF746;
IF745:
	local[5]= NIL;
IF746:
IF744:
	goto IF742;
IF741:
	local[5]= NIL;
IF742:
	goto WHL737;
WHX738:
	local[5]= NIL;
BLK739:
	w = NIL;
	local[3]= local[1];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[11])(ctx,1,local+3,&ftab[11],fqv[106]); /*minusp*/
	if (w==NIL) goto IF747;
	local[3]= local[1];
	local[4]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)SCALEVEC(ctx,2,local+3); /*scale*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)VNORMALIZE(ctx,1,local+3); /*normalize-vector*/
	local[3]= w;
	goto IF748;
IF747:
	local[3]= NIL;
IF748:
	w = local[3];
	local[0]= w;
BLK724:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M749plane_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	argv[0]->c.obj.iv[1] = argv[2];
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(*ftab[6])(ctx,1,local+0,&ftab[6],fqv[42]); /*float-vector-p*/
	if (w==NIL) goto IF751;
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	argv[0]->c.obj.iv[2] = makeflt(-(fltval(w)));
	local[0]= argv[0]->c.obj.iv[2];
	goto IF752;
IF751:
	w = argv[3];
	if (!isnum(w)) goto IF753;
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)EUSFLOAT(ctx,1,local+0); /*float*/
	argv[0]->c.obj.iv[2] = w;
	local[0]= argv[0]->c.obj.iv[2];
	goto IF754;
IF753:
	local[0]= fqv[107];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF754:
IF752:
	w = argv[0];
	local[0]= w;
BLK750:
	ctx->vsp=local; return(local[0]);}

/*:face*/
static pointer M755polygon_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0];
	local[0]= w;
BLK756:
	ctx->vsp=local; return(local[0]);}

/*:edges*/
static pointer M757polygon_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK758:
	ctx->vsp=local; return(local[0]);}

/*:edge*/
static pointer M759polygon_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(pointer)NTH(ctx,2,local+0); /*nth*/
	local[0]= w;
BLK760:
	ctx->vsp=local; return(local[0]);}

/*:all-edges*/
static pointer M761polygon_all_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK762:
	ctx->vsp=local; return(local[0]);}

/*:vertices*/
static pointer M763polygon_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK764:
	ctx->vsp=local; return(local[0]);}

/*:vertex*/
static pointer M765polygon_vertex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+2;
	w=(pointer)NTH(ctx,2,local+0); /*nth*/
	local[0]= w;
BLK766:
	ctx->vsp=local; return(local[0]);}

/*:next-edge*/
static pointer M767polygon_next_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	w = argv[0]->c.obj.iv[4];
	argv[2] = memq(local[0],w);
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF769;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	goto IF770;
IF769:
	w=argv[0]->c.obj.iv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
IF770:
	w = local[0];
	local[0]= w;
BLK768:
	ctx->vsp=local; return(local[0]);}

/*:previous-edge*/
static pointer M771polygon_previous_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[0]->c.obj.iv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (argv[2]!=local[0]) goto IF773;
	local[0]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+1;
	w=(*ftab[12])(ctx,1,local+0,&ftab[12],fqv[108]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	goto IF774;
IF773:
	local[0]= argv[0]->c.obj.iv[4];
WHL775:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX776;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)EQ(ctx,2,local+1); /*eql*/
	if (w==NIL) goto IF778;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK772;
	goto IF779;
IF778:
	local[1]= NIL;
IF779:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[1];
	goto WHL775;
WHX776:
	local[1]= NIL;
BLK777:
	w = local[1];
	local[0]= w;
IF774:
	w = local[0];
	local[0]= w;
BLK772:
	ctx->vsp=local; return(local[0]);}

/*:adjacent-faces*/
static pointer M781polygon_adjacent_faces(ctx,n,argv,env)
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
	local[5]= argv[0]->c.obj.iv[4];
WHL784:
	if (local[5]==NIL) goto WHX785;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[2] = local[4]->c.obj.iv[3];
	local[3] = local[4]->c.obj.iv[4];
	local[6]= local[2];
	if (argv[0]!=local[6]) goto IF788;
	local[6]= local[3];
	goto IF789;
IF788:
	local[6]= local[2];
IF789:
	w = local[1];
	ctx->vsp=local+7;
	local[1] = cons(ctx,local[6],w);
	goto WHL784;
WHX785:
	local[6]= NIL;
BLK786:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK782:
	ctx->vsp=local; return(local[0]);}

/*:convexp*/
static pointer M790polygon_convexp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK791:
	ctx->vsp=local; return(local[0]);}

/*:box*/
static pointer M792polygon_box(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT795;}
	local[0]= NIL;
ENT795:
ENT794:
	if (n>3) maerror();
	local[1]= loadglobal(fqv[15]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[24];
	local[4]= argv[0]->c.obj.iv[5];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK793:
	ctx->vsp=local; return(local[0]);}

/*:boxtest*/
static pointer M797polygon_boxtest(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT800;}
	local[0]= NIL;
ENT800:
ENT799:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= fqv[25];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[26];
	local[3]= loadglobal(fqv[15]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[24];
	local[6]= argv[0]->c.obj.iv[5];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = local[3];
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK798:
	ctx->vsp=local; return(local[0]);}

/*:vertices-mean*/
static pointer M802polygon_vertices_mean(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	ctx->vsp=local+1;
	w=(pointer)F72vector_mean(ctx,1,local+0); /*vector-mean*/
	local[0]= w;
BLK803:
	ctx->vsp=local; return(local[0]);}

/*:distance*/
static pointer M804polygon_distance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[104];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,1,local+1,&ftab[13],fqv[109]); /*signum*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[38];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0] = w;
	local[2]= local[1];
	local[3]= makeflt(0.00000000e+00);
	ctx->vsp=local+4;
	w=(pointer)NUMEQUAL(ctx,2,local+2); /*=*/
	if (w==NIL) goto IF806;
	local[2]= argv[0];
	local[3]= fqv[110];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	w = fqv[111];
	if (memq(local[2],w)==NIL) goto IF808;
	local[2]= makeflt(0.00000000e+00);
	goto IF809;
IF808:
	local[2]= (pointer)get_sym_func(fqv[112]);
	local[3]= argv[0]->c.obj.iv[4];
	local[4]= fqv[73];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(*ftab[14])(ctx,3,local+3,&ftab[14],fqv[113]); /*send-all*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,2,local+2); /*apply*/
	local[2]= w;
IF809:
	goto IF807;
IF806:
	local[2]= local[1];
	local[3]= argv[0];
	local[4]= fqv[110];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	w = fqv[114];
	if (memq(local[3],w)==NIL) goto IF810;
	local[3]= local[0];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)VDISTANCE(ctx,2,local+3); /*distance*/
	local[3]= w;
	goto IF811;
IF810:
	local[3]= (pointer)get_sym_func(fqv[112]);
	local[4]= argv[0]->c.obj.iv[4];
	local[5]= fqv[73];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(*ftab[14])(ctx,3,local+4,&ftab[14],fqv[113]); /*send-all*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,2,local+3); /*apply*/
	local[3]= w;
IF811:
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
IF807:
	w = local[2];
	local[0]= w;
BLK805:
	ctx->vsp=local; return(local[0]);}

/*:area*/
static pointer M812polygon_area(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F72vector_mean(ctx,1,local+1); /*vector-mean*/
	local[1]= w;
	local[2]= makeflt(0.00000000e+00);
WHL814:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX815;
	local[3]= local[2];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= local[1];
	local[7]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+8;
	w=(pointer)F74triangle(ctx,4,local+4); /*triangle*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[2] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[3];
	goto WHL814;
WHX815:
	local[3]= NIL;
BLK816:
	local[3]= local[2];
	local[4]= makeflt(2.00000000e+00);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[0]= w;
BLK813:
	ctx->vsp=local; return(local[0]);}

/*:perimeter*/
static pointer M818polygon_perimeter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= (pointer)get_sym_func(fqv[115]);
	local[1]= argv[0]->c.obj.iv[4];
	local[2]= fqv[116];
	ctx->vsp=local+3;
	w=(*ftab[14])(ctx,2,local+1,&ftab[14],fqv[113]); /*send-all*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
BLK819:
	ctx->vsp=local; return(local[0]);}

/*:volume*/
static pointer M820polygon_volume(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT823;}
	local[0]= fqv[117];
ENT823:
ENT822:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[104];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[118];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	local[2]= makeflt(-3.00000000e+00);
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[0]= w;
BLK821:
	ctx->vsp=local; return(local[0]);}

/*:centroid*/
static pointer M824polygon_centroid(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT827;}
	local[0]= NIL;
ENT827:
ENT826:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[5];
	local[2]= NIL;
	local[3]= NIL;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)F72vector_mean(ctx,1,local+4); /*vector-mean*/
	local[4]= w;
	local[5]= makeflt(0.00000000e+00);
	local[6]= makeflt(0.00000000e+00);
	local[7]= makeint(0);
	local[8]= makeint(0);
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,3,local+7); /*float-vector*/
	local[7]= w;
	local[8]= makeint(0);
	local[9]= makeint(0);
	local[10]= makeint(0);
	ctx->vsp=local+11;
	w=(pointer)MKFLTVEC(ctx,3,local+8); /*float-vector*/
	local[8]= w;
WHL828:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX829;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[9];
	local[2] = w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	local[9]= local[2];
	local[10]= local[3];
	local[11]= local[4];
	local[12]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+13;
	w=(pointer)F74triangle(ctx,4,local+9); /*triangle*/
	local[5] = w;
	local[9]= local[6];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[6] = w;
	local[9]= local[2];
	local[10]= local[3];
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(pointer)VPLUS(ctx,3,local+9); /*v+*/
	local[9]= local[4];
	local[10]= local[8];
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(pointer)VPLUS(ctx,3,local+9); /*v+*/
	local[9]= local[7];
	local[10]= local[5];
	local[11]= makeflt(3.00000000e+00);
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[10]= w;
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(pointer)SCALEVEC(ctx,2,local+10); /*scale*/
	local[10]= w;
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)VPLUS(ctx,3,local+9); /*v+*/
	goto WHL828;
WHX829:
	local[9]= NIL;
BLK830:
	local[9]= makeflt(1.00000000e+00);
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)SCALEVEC(ctx,2,local+9); /*scale*/
	local[7] = w;
	local[9]= local[6];
	local[10]= makeflt(2.00000000e+00);
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[6] = w;
	if (local[0]==NIL) goto IF832;
	local[9]= local[6];
	local[10]= argv[0];
	local[11]= fqv[104];
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	local[10]= makeflt(-3.00000000e+00);
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	local[10]= makeflt(7.50000000e-01);
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)SCALEVEC(ctx,2,local+10); /*scale*/
	local[10]= w;
	local[11]= makeflt(2.50000000e-01);
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)SCALEVEC(ctx,2,local+11); /*scale*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)VPLUS(ctx,2,local+10); /*v+*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,2,local+9); /*list*/
	local[9]= w;
	goto IF833;
IF832:
	local[9]= local[6];
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,2,local+9); /*list*/
	local[9]= w;
IF833:
	w = local[9];
	local[0]= w;
BLK825:
	ctx->vsp=local; return(local[0]);}

/*:color*/
static pointer M834polygon_color(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT837;}
	local[0]= NIL;
ENT837:
ENT836:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF838;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[80];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= w;
	goto IF839;
IF838:
	local[1]= NIL;
IF839:
	local[1]= argv[0];
	local[2]= fqv[80];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[0]= w;
BLK835:
	ctx->vsp=local; return(local[0]);}

/*:insidep*/
static pointer M840polygon_insidep(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT843;}
	local[0]= loadglobal(fqv[8]);
ENT843:
	w = local[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
ENT842:
	if (n>4) maerror();
	local[3]= NIL;
	local[4]= NIL;
	local[5]= makeflt(0.00000000e+00);
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	if (argv[0]->c.obj.iv[3]==NIL) goto CON845;
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.car;
	local[9]= NIL;
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.cdr;
WHL847:
	if (local[10]==NIL) goto WHX848;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	local[11]= local[4];
	local[12]= local[9];
	local[13]= argv[2];
	local[14]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+15;
	w=(pointer)F74triangle(ctx,4,local+11); /*triangle*/
	local[7] = w;
	local[11]= local[7];
	local[12]= local[4];
	local[13]= local[9];
	ctx->vsp=local+14;
	w=(pointer)VDISTANCE(ctx,2,local+12); /*distance*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)QUOTIENT(ctx,2,local+11); /*/*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)F96eps_zero(ctx,1,local+11); /*eps-zero*/
	if (w==NIL) goto CON852;
	local[11]= local[9];
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(pointer)VMINUS(ctx,2,local+11); /*v-*/
	local[11]= w;
	local[12]= argv[2];
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)VMINUS(ctx,2,local+12); /*v-*/
	local[12]= w;
	local[13]= local[11];
	local[14]= local[12];
	ctx->vsp=local+15;
	w=(pointer)VINNERPRODUCT(ctx,2,local+13); /*v.*/
	local[13]= w;
	local[14]= local[11];
	local[15]= local[11];
	ctx->vsp=local+16;
	w=(pointer)VINNERPRODUCT(ctx,2,local+14); /*v.*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)QUOTIENT(ctx,2,local+13); /*/*/
	local[6] = w;
	local[11]= makeflt(0.00000000e+00);
	local[12]= local[6];
	local[13]= makeflt(1.00000000e+00);
	ctx->vsp=local+14;
	w=(pointer)F97eps_in_range(ctx,3,local+11); /*eps-in-range*/
	if (w==NIL) goto IF853;
	w = fqv[119];
	ctx->vsp=local+11;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK841;
	goto IF854;
IF853:
	local[11]= NIL;
IF854:
	goto CON851;
CON852:
	local[11]= local[7];
	{ double left,right;
		right=fltval(makeflt(0.00000000e+00)); left=fltval(local[11]);
	if (left >= right) goto CON855;}
	w = fqv[51];
	ctx->vsp=local+11;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK841;
	goto CON851;
CON855:
	local[11]= NIL;
CON851:
	local[4] = local[9];
	goto WHL847;
WHX848:
	local[11]= NIL;
BLK849:
	w = NIL;
	local[9]= fqv[120];
	goto CON844;
CON845:
	local[9]= argv[0];
	local[10]= fqv[121];
	local[11]= argv[2];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	if (w==NIL) goto IF857;
	w = fqv[119];
	ctx->vsp=local+9;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK841;
	goto IF858;
IF857:
	local[9]= NIL;
IF858:
	ctx->vsp=local+9;
	local[9]= makeclosure(codevec,quotevec,CLO859,env,argv,local);
	local[10]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+11;
	w=(pointer)MAPCAR(ctx,2,local+9); /*mapcar*/
	local[8] = w;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[4] = w;
WHL861:
	if (local[8]==NIL) goto WHX862;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[3] = w;
	local[9]= local[3];
	local[10]= local[4];
	local[11]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+12;
	w=(pointer)F76vector_angle(ctx,3,local+9); /*vector-angle*/
	local[7] = w;
	local[9]= makeflt((double)fabs(fltval(local[7])));
	local[10]= makeflt(3.14159265e+00);
	ctx->vsp=local+11;
	w=(pointer)F90eps_(ctx,2,local+9); /*eps=*/
	if (w==NIL) goto IF865;
	w = fqv[119];
	ctx->vsp=local+9;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK841;
	goto IF866;
IF865:
	local[9]= NIL;
IF866:
	local[9]= local[5];
	{ double x,y;
		y=fltval(local[7]); x=fltval(local[9]);
		local[9]=(makeflt(x + y));}
	local[5] = local[9];
	local[4] = local[3];
	goto WHL861;
WHX862:
	local[9]= NIL;
BLK863:
	local[9]= makeflt((double)fabs(fltval(local[5])));
	{ double left,right;
		right=fltval(makeflt(3.14159265e+00)); left=fltval(local[9]);
	if (left <= right) goto IF867;}
	local[9]= fqv[120];
	goto IF868;
IF867:
	local[9]= fqv[51];
IF868:
	goto CON844;
CON856:
	local[9]= NIL;
CON844:
	w = local[9];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK841:
	ctx->vsp=local; return(local[0]);}

/*:intersect-point-vector*/
static pointer M869polygon_intersect_point_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= makeflt((double)fabs(fltval(local[0])));
	local[4]= loadglobal(fqv[35]);
	ctx->vsp=local+5;
	w=(pointer)LESSP(ctx,2,local+3); /*<*/
	if (w==NIL) goto IF871;
	w = fqv[122];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK870;
	goto IF872;
IF871:
	local[3]= NIL;
IF872:
	local[3]= makeflt(0.00000000e+00);
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)VINNERPRODUCT(ctx,2,local+4); /*v.*/
	local[4]= w;
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[2]); x=fltval(local[4]);
		local[4]=(makeflt(x + y));}
	{ double x,y;
		y=fltval(makeflt(-(fltval(local[4])))); x=fltval(local[3]);
		local[3]=(makeflt(x + y));}
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[1] = w;
	local[3]= local[1];
	{ double left,right;
		right=fltval(makeflt(0.00000000e+00)); left=fltval(local[3]);
	if (left >= right) goto IF873;}
	w = fqv[123];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK870;
	goto IF874;
IF873:
	local[3]= NIL;
IF874:
	local[3]= argv[2];
	local[4]= local[1];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SCALEVEC(ctx,2,local+4); /*scale*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)VPLUS(ctx,2,local+3); /*v+*/
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[110];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[0]= w;
BLK870:
	ctx->vsp=local; return(local[0]);}

/*:intersect-line*/
static pointer M875polygon_intersect_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[26];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= makeflt(0.00000000e+00);
	local[4]= local[0];
	local[5]= makeflt(1.00000000e+00);
	ctx->vsp=local+6;
	w=(pointer)F97eps_in_range(ctx,3,local+3); /*eps-in-range*/
	if (w==NIL) goto IF877;
	local[3]= argv[0];
	local[4]= fqv[110];
	local[5]= local[0];
	local[6]= argv[2];
	local[7]= argv[3];
	ctx->vsp=local+8;
	w=(*ftab[1])(ctx,3,local+5,&ftab[1],fqv[11]); /*midpoint*/
	local[1] = w;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	w = fqv[124];
	if (memq(local[3],w)==NIL) goto IF877;
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[3]= w;
	goto IF878;
IF877:
	local[3]= NIL;
IF878:
	w = local[3];
	local[0]= w;
BLK876:
	ctx->vsp=local; return(local[0]);}

/*:intersect-edge*/
static pointer M879polygon_intersect_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[125];
	local[2]= argv[2]->c.obj.iv[1];
	local[3]= argv[2]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK880:
	ctx->vsp=local; return(local[0]);}

/*:intersect-face*/
static pointer M881polygon_intersect_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT884;}
	local[0]= argv[0];
	local[1]= fqv[25];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[26];
	local[2]= argv[2];
	local[3]= fqv[25];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
ENT884:
ENT883:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[4];
WHL886:
	if (local[2]==NIL) goto WHX887;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	if (local[0]==NIL) goto IF890;
	local[3]= local[0];
	local[4]= fqv[28];
	local[5]= local[1];
	local[6]= fqv[25];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	if (w==NIL) goto IF890;
	local[3]= argv[2];
	local[4]= fqv[126];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	if (w==NIL) goto IF890;
	w = T;
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK882;
	goto IF891;
IF890:
	local[3]= NIL;
IF891:
	goto WHL886;
WHX887:
	local[3]= NIL;
BLK888:
	w = NIL;
	w = NIL;
	local[0]= w;
BLK882:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO859(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[2];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F73direction_vector(ctx,2,local+0); /*direction-vector*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:visible*/
static pointer M892polygon_visible(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[104];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= makeflt(0.00000000e+00);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF894;
	local[0]= argv[0];
	goto IF895;
IF894:
	local[0]= NIL;
IF895:
	w = local[0];
	local[0]= w;
BLK893:
	ctx->vsp=local; return(local[0]);}

/*:transform-normal*/
static pointer M896polygon_transform_normal(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[127];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= local[0]->c.obj.iv[2];
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)VINNERPRODUCT(ctx,2,local+2); /*v.*/
	{ double x,y;
		y=fltval(w); x=fltval(local[1]);
		local[1]=(makeflt(x + y));}
	argv[0]->c.obj.iv[2] = local[1];
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= local[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)TRANSFORM(ctx,2,local+1); /*transform*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0]->c.obj.iv[1];
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK897:
	ctx->vsp=local; return(local[0]);}

/*:reset-normal*/
static pointer M898polygon_reset_normal(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	ctx->vsp=local+1;
	w=(pointer)F77face_normal_vector(ctx,1,local+0); /*face-normal-vector*/
	argv[0]->c.obj.iv[1] = w;
	local[0]= argv[0]->c.obj.iv[1];
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	argv[0]->c.obj.iv[2] = makeflt(-(fltval(w)));
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK899:
	ctx->vsp=local; return(local[0]);}

/*:set-convexp*/
static pointer M900polygon_set_convexp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	local[0]= w;
	argv[0]->c.obj.iv[3] = T;
WHL902:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX903;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[1];
	local[1]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)F74triangle(ctx,4,local+1); /*triangle*/
	local[1]= w;
	local[2]= makeflt(0.00000000e+00);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto IF905;
	argv[0]->c.obj.iv[3] = NIL;
	local[0] = NIL;
	local[1]= local[0];
	goto IF906;
IF905:
	local[1]= NIL;
IF906:
	goto WHL902;
WHX903:
	local[1]= NIL;
BLK904:
	w = local[1];
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK901:
	ctx->vsp=local; return(local[0]);}

/*:invert*/
static pointer M908polygon_invert(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+1;
	w=(pointer)NREVERSE(ctx,1,local+0); /*nreverse*/
	argv[0]->c.obj.iv[5] = w;
	local[0]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+1;
	w=(pointer)NREVERSE(ctx,1,local+0); /*nreverse*/
	argv[0]->c.obj.iv[4] = w;
	local[0]= makeflt(-1.00000000e+00);
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,3,local+0); /*scale*/
	local[0]= makeflt(-1.00000000e+00);
	local[1]= argv[0]->c.obj.iv[6];
	local[2]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,3,local+0); /*scale*/
	local[0]= makeflt(-1.00000000e+00);
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[2]); x=fltval(local[0]);
		local[0]=(makeflt(x * y));}
	argv[0]->c.obj.iv[2] = local[0];
	local[0]= makeflt(-1.00000000e+00);
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[7]); x=fltval(local[0]);
		local[0]=(makeflt(x * y));}
	argv[0]->c.obj.iv[7] = local[0];
	local[0]= argv[0];
	local[1]= fqv[128];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK909:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M910polygon_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[129], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY912;
	local[0] = NIL;
KEY912:
	if (n & (1<<1)) goto KEY913;
	local[1] = NIL;
KEY913:
	if (n & (1<<2)) goto KEY914;
	local[2] = NIL;
KEY914:
	if (n & (1<<3)) goto KEY915;
	local[3] = NIL;
KEY915:
	if (local[1]==NIL) goto CON917;
	argv[0]->c.obj.iv[4] = local[1];
	if (local[0]!=NIL) goto CON919;
	local[4]= NIL;
	local[5]= local[1];
WHL921:
	if (local[5]==NIL) goto WHX922;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[4];
	local[7]= fqv[55];
	local[8]= argv[0];
	local[9]= fqv[130];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	w = local[0];
	ctx->vsp=local+7;
	local[0] = cons(ctx,local[6],w);
	goto WHL921;
WHX922:
	local[6]= NIL;
BLK923:
	w = NIL;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)NREVERSE(ctx,1,local+4); /*nreverse*/
	local[0] = w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= fqv[54];
	local[6]= argv[0];
	local[7]= fqv[130];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	w = local[0];
	ctx->vsp=local+5;
	argv[0]->c.obj.iv[5] = cons(ctx,local[4],w);
	local[4]= argv[0]->c.obj.iv[5];
	goto CON918;
CON919:
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[12])(ctx,1,local+4,&ftab[12],fqv[108]); /*last*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPEND(ctx,2,local+4); /*append*/
	argv[0]->c.obj.iv[5] = w;
	local[4]= argv[0]->c.obj.iv[5];
	goto CON918;
CON925:
	local[4]= NIL;
CON918:
	goto CON916;
CON917:
	if (local[0]==NIL) goto CON926;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[12])(ctx,1,local+4,&ftab[12],fqv[108]); /*last*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPEND(ctx,2,local+4); /*append*/
	argv[0]->c.obj.iv[5] = w;
WHL927:
	if (local[0]==NIL) goto WHX928;
	local[4]= loadglobal(fqv[131]);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= local[4];
	local[6]= fqv[24];
	local[7]= fqv[54];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[8];
	local[8]= w;
	local[9]= fqv[55];
	if (local[0]==NIL) goto IF932;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	goto IF933;
IF932:
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
IF933:
	local[11]= fqv[132];
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,8,local+5); /*send*/
	w = local[4];
	local[4]= w;
	w = argv[0]->c.obj.iv[4];
	ctx->vsp=local+5;
	argv[0]->c.obj.iv[4] = cons(ctx,local[4],w);
	goto WHL927;
WHX928:
	local[4]= NIL;
BLK929:
	local[4]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+5;
	w=(pointer)NREVERSE(ctx,1,local+4); /*nreverse*/
	argv[0]->c.obj.iv[4] = w;
	local[4]= argv[0]->c.obj.iv[4];
	goto CON916;
CON926:
	local[4]= NIL;
CON916:
	if (local[2]==NIL) goto IF934;
	argv[0]->c.obj.iv[1] = local[2];
	local[4]= argv[0]->c.obj.iv[1];
	goto IF935;
IF934:
	local[4]= argv[0];
	local[5]= fqv[133];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
IF935:
	if (local[3]==NIL) goto IF936;
	argv[0]->c.obj.iv[2] = local[3];
	local[4]= argv[0]->c.obj.iv[2];
	goto IF937;
IF936:
	local[4]= NIL;
IF937:
	local[4]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)COPYSEQ(ctx,1,local+4); /*copy-seq*/
	argv[0]->c.obj.iv[6] = w;
	argv[0]->c.obj.iv[7] = argv[0]->c.obj.iv[2];
	local[4]= argv[0];
	local[5]= fqv[128];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	w = argv[0];
	local[0]= w;
BLK911:
	ctx->vsp=local; return(local[0]);}

/*:on-vertex*/
static pointer M938polygon_on_vertex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT941;}
	local[0]= loadglobal(fqv[23]);
ENT941:
	w = local[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
ENT940:
	if (n>4) maerror();
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.cdr;
WHL943:
	if (local[6]==NIL) goto WHX944;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= argv[2];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)F98eps_v_(ctx,2,local+7); /*eps-v=*/
	if (w==NIL) goto IF947;
	local[7]= local[5];
	w = local[4];
	ctx->vsp=local+8;
	local[4] = cons(ctx,local[7],w);
	local[7]= local[4];
	goto IF948;
IF947:
	local[7]= NIL;
IF948:
	goto WHL943;
WHX944:
	local[7]= NIL;
BLK945:
	w = NIL;
	local[5]= local[4];
	ctx->vsp=local+6;
	unbindx(ctx,1);
	w = local[5];
	local[0]= w;
BLK939:
	ctx->vsp=local; return(local[0]);}

/*:on-edge*/
static pointer M949polygon_on_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT952;}
	local[0]= loadglobal(fqv[23]);
ENT952:
ENT951:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[4];
WHL954:
	if (local[4]==NIL) goto WHX955;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3];
	local[6]= fqv[134];
	local[7]= argv[2];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	if (w==NIL) goto IF958;
	local[5]= local[3];
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[2];
	goto IF959;
IF958:
	local[5]= NIL;
IF959:
	goto WHL954;
WHX955:
	local[5]= NIL;
BLK956:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK950:
	ctx->vsp=local; return(local[0]);}

/*:coplanar-distance*/
static pointer M960polygon_coplanar_distance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[110];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[135];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[136]); /*member*/
	if (w==NIL) goto IF962;
	local[0]= fqv[120];
	goto IF963;
IF962:
	local[0]= (pointer)get_sym_func(fqv[112]);
	local[1]= argv[0]->c.obj.iv[4];
	local[2]= fqv[73];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(*ftab[14])(ctx,3,local+1,&ftab[14],fqv[113]); /*send-all*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
IF963:
	w = local[0];
	local[0]= w;
BLK961:
	ctx->vsp=local; return(local[0]);}

/*:coplanar-intersections*/
static pointer M964polygon_coplanar_intersections(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT967;}
	local[0]= loadglobal(fqv[45]);
ENT967:
ENT966:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F102bounding_box_intersection(ctx,2,local+1); /*bounding-box-intersection*/
	local[1]= w;
	local[2]= NIL;
	if (local[1]!=NIL) goto IF968;
	w = NIL;
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK965;
	goto IF969;
IF968:
	local[3]= NIL;
IF969:
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[4];
WHL971:
	if (local[4]==NIL) goto WHX972;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= argv[2];
	local[9]= fqv[60];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
WHL976:
	if (local[8]==NIL) goto WHX977;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[3];
	local[10]= fqv[125];
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[6] = w;
	w = local[6];
	if (!iscons(w)) goto IF980;
	local[9]= local[7];
	w = local[6];
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	w = local[5];
	ctx->vsp=local+10;
	local[5] = cons(ctx,local[9],w);
	local[9]= local[5];
	goto IF981;
IF980:
	local[9]= NIL;
IF981:
	goto WHL976;
WHX977:
	local[9]= NIL;
BLK978:
	w = NIL;
	if (local[5]==NIL) goto IF982;
	local[7]= local[3];
	w = local[5];
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	w = local[2];
	ctx->vsp=local+8;
	local[2] = cons(ctx,local[7],w);
	local[7]= local[2];
	goto IF983;
IF982:
	local[7]= NIL;
IF983:
	w = local[7];
	goto WHL971;
WHX972:
	local[5]= NIL;
BLK973:
	w = NIL;
	if (local[2]==NIL) goto IF984;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK965;
	goto IF985;
IF984:
	local[3]= NIL;
IF985:
	local[3]= NIL;
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
WHL987:
	if (local[4]==NIL) goto WHX988;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[1];
	local[6]= fqv[137];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	if (w==NIL) goto IF991;
	local[5]= argv[2];
	local[6]= fqv[110];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	w = fqv[138];
	if (memq(local[5],w)==NIL) goto IF991;
	w = fqv[139];
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK965;
	goto IF992;
IF991:
	local[5]= NIL;
IF992:
	goto WHL987;
WHX988:
	local[5]= NIL;
BLK989:
	w = NIL;
	local[3]= NIL;
	local[4]= argv[2];
	local[5]= fqv[140];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
WHL994:
	if (local[4]==NIL) goto WHX995;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[1];
	local[6]= fqv[137];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	if (w==NIL) goto IF998;
	local[5]= argv[0];
	local[6]= fqv[110];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	w = fqv[141];
	if (memq(local[5],w)==NIL) goto IF998;
	w = fqv[142];
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK965;
	goto IF999;
IF998:
	local[5]= NIL;
IF999:
	goto WHL994;
WHX995:
	local[5]= NIL;
BLK996:
	w = NIL;
	w = NIL;
	local[0]= w;
BLK965:
	ctx->vsp=local; return(local[0]);}

/*:contact-edge*/
static pointer M1000polygon_contact_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1003;}
	local[0]= loadglobal(fqv[23]);
ENT1003:
ENT1002:
	if (n>4) maerror();
	local[1]= argv[2]->c.obj.iv[1];
	local[2]= argv[2]->c.obj.iv[2];
	local[3]= argv[0];
	local[4]= fqv[104];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[104];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w!=NIL) goto OR1006;
	local[5]= local[4];
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w!=NIL) goto OR1006;
	local[5]= argv[0];
	local[6]= fqv[143];
	local[7]= argv[2];
	local[8]= makeflt(1.00000000e-03);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	if (w==NIL) goto OR1006;
	goto CON1005;
OR1006:
	local[5]= fqv[51];
	goto CON1004;
CON1005:
	local[5]= argv[0];
	local[6]= fqv[110];
	local[7]= local[1];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	local[6]= fqv[120];
	ctx->vsp=local+7;
	w=(pointer)EQ(ctx,2,local+5); /*eql*/
	if (w!=NIL) goto OR1008;
	local[5]= argv[0];
	local[6]= fqv[110];
	local[7]= local[2];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,1,local+5); /*eql*/
	if (w!=NIL) goto OR1008;
	goto CON1007;
OR1008:
	local[5]= T;
	goto CON1004;
CON1007:
	local[5]= NIL;
CON1004:
	w = local[5];
	local[0]= w;
BLK1001:
	ctx->vsp=local; return(local[0]);}

/*:contact-plane*/
static pointer M1009polygon_contact_plane(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1012;}
	local[0]= loadglobal(fqv[23]);
ENT1012:
ENT1011:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	local[3]= fqv[64];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= w;
	local[2]= makeflt(-1.00000000e+00);
	ctx->vsp=local+3;
	w=(pointer)F90eps_(ctx,2,local+1); /*eps=*/
	if (w==NIL) goto IF1013;
	local[1]= makeflt(-(fltval(argv[0]->c.obj.iv[2])));
	local[2]= argv[2]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)F90eps_(ctx,2,local+1); /*eps=*/
	if (w==NIL) goto IF1013;
	local[1]= argv[0];
	local[2]= fqv[144];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF1014;
IF1013:
	local[1]= NIL;
IF1014:
	w = local[1];
	local[0]= w;
BLK1010:
	ctx->vsp=local; return(local[0]);}

/*:contact-point*/
static pointer M1015polygon_contact_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1018;}
	local[0]= loadglobal(fqv[23]);
ENT1018:
ENT1017:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[104];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ABS(ctx,1,local+3); /*abs*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto IF1019;
	local[2]= fqv[51];
	goto IF1020;
IF1019:
	local[2]= argv[0];
	local[3]= fqv[110];
	local[4]= argv[2];
	local[5]= local[1];
	local[6]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+7;
	w=(pointer)SCALEVEC(ctx,2,local+5); /*scale*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)VMINUS(ctx,2,local+4); /*v-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
IF1020:
	w = local[2];
	local[0]= w;
BLK1016:
	ctx->vsp=local; return(local[0]);}

/*:contactp*/
static pointer M1021polygon_contactp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1024;}
	local[0]= loadglobal(fqv[23]);
ENT1024:
ENT1023:
	if (n>4) maerror();
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[42]); /*float-vector-p*/
	if (w==NIL) goto CON1026;
	local[1]= argv[0];
	local[2]= fqv[145];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON1025;
CON1026:
	local[1]= argv[2];
	local[2]= loadglobal(fqv[43]);
	ctx->vsp=local+3;
	w=(pointer)DERIVEDP(ctx,2,local+1); /*derivedp*/
	if (w==NIL) goto CON1027;
	local[1]= argv[0];
	local[2]= fqv[146];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON1025;
CON1027:
	local[1]= argv[2];
	local[2]= loadglobal(fqv[147]);
	ctx->vsp=local+3;
	w=(pointer)DERIVEDP(ctx,2,local+1); /*derivedp*/
	if (w==NIL) goto CON1028;
	local[1]= argv[0];
	local[2]= fqv[148];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON1025;
CON1028:
	local[1]= NIL;
CON1025:
	w = local[1];
	local[0]= w;
BLK1022:
	ctx->vsp=local; return(local[0]);}

/*:aligned-plane*/
static pointer M1029polygon_aligned_plane(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	local[2]= fqv[64];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	local[0]= w;
	local[1]= makeflt(1.00000000e+00);
	ctx->vsp=local+2;
	w=(pointer)F90eps_(ctx,2,local+0); /*eps=*/
	if (w==NIL) goto IF1031;
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[2]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)F90eps_(ctx,2,local+0); /*eps=*/
	if (w==NIL) goto IF1031;
	local[0]= argv[0];
	local[1]= fqv[144];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF1032;
IF1031:
	local[0]= NIL;
IF1032:
	w = local[0];
	local[0]= w;
BLK1030:
	ctx->vsp=local; return(local[0]);}

/*:insidep*/
static pointer M1033face_insidep(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1036;}
	local[0]= makeflt(1.00000000e-03);
ENT1036:
ENT1035:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[12]));
	local[3]= fqv[110];
	local[4]= argv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	local[1]= w;
	local[2]= local[1];
	if (fqv[120]==local[2]) goto IF1037;
	local[2]= local[1];
	goto IF1038;
IF1037:
	local[2]= NIL;
	local[3]= argv[0]->c.obj.iv[8];
WHL1040:
	if (local[3]==NIL) goto WHX1041;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	local[5]= fqv[110];
	local[6]= argv[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[1] = w;
	local[4]= local[1];
	if (fqv[120]!=local[4]) goto IF1044;
	w = fqv[51];
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK1034;
	goto IF1045;
IF1044:
	local[4]= local[1];
	if (fqv[119]!=local[4]) goto IF1046;
	w = fqv[119];
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK1034;
	goto IF1047;
IF1046:
	local[4]= NIL;
IF1047:
IF1045:
	goto WHL1040;
WHX1041:
	local[4]= NIL;
BLK1042:
	w = NIL;
	local[2]= fqv[120];
IF1038:
	w = local[2];
	local[0]= w;
BLK1034:
	ctx->vsp=local; return(local[0]);}

/*:distance*/
static pointer M1048face_distance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[104];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,1,local+1,&ftab[13],fqv[109]); /*signum*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[38];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0] = w;
	local[2]= local[1];
	local[3]= makeflt(0.00000000e+00);
	ctx->vsp=local+4;
	w=(pointer)NUMEQUAL(ctx,2,local+2); /*=*/
	if (w==NIL) goto IF1050;
	local[2]= argv[0];
	local[3]= fqv[110];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	w = fqv[149];
	if (memq(local[2],w)==NIL) goto IF1052;
	local[2]= makeflt(0.00000000e+00);
	goto IF1053;
IF1052:
	local[2]= (pointer)get_sym_func(fqv[112]);
	local[3]= argv[0];
	local[4]= fqv[91];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= fqv[73];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(*ftab[14])(ctx,3,local+3,&ftab[14],fqv[113]); /*send-all*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,2,local+2); /*apply*/
	local[2]= w;
IF1053:
	goto IF1051;
IF1050:
	local[2]= local[1];
	local[3]= argv[0];
	local[4]= fqv[110];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	w = fqv[150];
	if (memq(local[3],w)==NIL) goto IF1054;
	local[3]= local[0];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)VDISTANCE(ctx,2,local+3); /*distance*/
	local[3]= w;
	goto IF1055;
IF1054:
	local[3]= (pointer)get_sym_func(fqv[112]);
	local[4]= argv[0];
	local[5]= fqv[91];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= fqv[73];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(*ftab[14])(ctx,3,local+4,&ftab[14],fqv[113]); /*send-all*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,2,local+3); /*apply*/
	local[3]= w;
IF1055:
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
IF1051:
	w = local[2];
	local[0]= w;
BLK1049:
	ctx->vsp=local; return(local[0]);}

/*:area*/
static pointer M1056face_area(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[12]));
	local[2]= fqv[118];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= w;
	local[1]= (pointer)get_sym_func(fqv[115]);
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[118];
	ctx->vsp=local+4;
	w=(*ftab[14])(ctx,2,local+2,&ftab[14],fqv[113]); /*send-all*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	local[0]= w;
BLK1057:
	ctx->vsp=local; return(local[0]);}

/*:centroid*/
static pointer M1058face_centroid(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1061;}
	local[0]= NIL;
ENT1061:
ENT1060:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[12]));
	local[3]= fqv[151];
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,4,local+1); /*send-message*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[151];
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(*ftab[14])(ctx,3,local+2,&ftab[14],fqv[113]); /*send-all*/
	local[2]= w;
	local[3]= (pointer)get_sym_func(fqv[152]);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,2,local+3); /*apply*/
	local[3]= w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= (pointer)get_sym_func(fqv[115]);
	local[6]= (pointer)get_sym_func(fqv[153]);
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,2,local+5); /*apply*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	local[5]= NIL;
	local[6]= local[2];
WHL1063:
	if (local[6]==NIL) goto WHX1064;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[3];
	local[8]= (pointer)get_sym_func(fqv[152]);
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)APPLY(ctx,2,local+8); /*apply*/
	local[8]= w;
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)VMINUS(ctx,3,local+7); /*v-*/
	goto WHL1063;
WHX1064:
	local[7]= NIL;
BLK1065:
	w = NIL;
	if (local[0]==NIL) goto IF1067;
	local[5]= local[4];
	local[6]= argv[0];
	local[7]= fqv[104];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	local[6]= makeflt(-3.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= makeflt(2.50000000e-01);
	local[7]= makeflt(1.00000000e+00);
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	local[7]= w;
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)SCALEVEC(ctx,2,local+7); /*scale*/
	local[7]= w;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(*ftab[1])(ctx,3,local+6,&ftab[1],fqv[11]); /*midpoint*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,2,local+5); /*list*/
	local[5]= w;
	goto IF1068;
IF1067:
	local[5]= local[4];
	local[6]= makeflt(1.00000000e+00);
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SCALEVEC(ctx,2,local+6); /*scale*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,2,local+5); /*list*/
	local[5]= w;
IF1068:
	w = local[5];
	local[0]= w;
BLK1059:
	ctx->vsp=local; return(local[0]);}

/*:on-vertex*/
static pointer M1069face_on_vertex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1072;}
	local[0]= loadglobal(fqv[23]);
ENT1072:
	w = local[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
ENT1071:
	if (n>4) maerror();
	local[3]= NIL;
	local[4]= NIL;
	local[5]= (pointer)get_sym_func(fqv[154]);
	local[6]= argv[0];
	local[7]= *(ovafptr(argv[1],fqv[12]));
	local[8]= fqv[121];
	local[9]= argv[2];
	local[10]= loadglobal(fqv[8]);
	ctx->vsp=local+11;
	w=(pointer)SENDMESSAGE(ctx,5,local+6); /*send-message*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[8];
	local[8]= fqv[121];
	local[9]= argv[2];
	local[10]= loadglobal(fqv[8]);
	ctx->vsp=local+11;
	w=(*ftab[14])(ctx,4,local+7,&ftab[14],fqv[113]); /*send-all*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,3,local+5); /*apply*/
	local[5]= w;
	ctx->vsp=local+6;
	unbindx(ctx,1);
	w = local[5];
	local[0]= w;
BLK1070:
	ctx->vsp=local; return(local[0]);}

/*:on-edge*/
static pointer M1073face_on_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1076;}
	local[0]= loadglobal(fqv[23]);
ENT1076:
ENT1075:
	if (n>4) maerror();
	local[1]= (pointer)get_sym_func(fqv[154]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[12]));
	local[4]= fqv[155];
	local[5]= argv[2];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,5,local+2); /*send-message*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[8];
	local[4]= fqv[155];
	local[5]= argv[2];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[14])(ctx,4,local+3,&ftab[14],fqv[113]); /*send-all*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[0]= w;
BLK1074:
	ctx->vsp=local; return(local[0]);}

/*:invert*/
static pointer M1077face_invert(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[12]));
	local[2]= fqv[156];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= fqv[156];
	ctx->vsp=local+2;
	w=(*ftab[14])(ctx,2,local+0,&ftab[14],fqv[113]); /*send-all*/
	local[0]= w;
BLK1078:
	ctx->vsp=local; return(local[0]);}

/*:holes*/
static pointer M1079face_holes(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK1080:
	ctx->vsp=local; return(local[0]);}

/*:enter-hole*/
static pointer M1081face_enter_hole(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	w = argv[0]->c.obj.iv[8];
	ctx->vsp=local+1;
	argv[0]->c.obj.iv[8] = cons(ctx,local[0],w);
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK1082:
	ctx->vsp=local; return(local[0]);}

/*:transform-normal*/
static pointer M1083face_transform_normal(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[12]));
	local[2]= fqv[157];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SENDMESSAGE(ctx,4,local+0); /*send-message*/
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= fqv[157];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[14])(ctx,3,local+0,&ftab[14],fqv[113]); /*send-all*/
	local[0]= w;
BLK1084:
	ctx->vsp=local; return(local[0]);}

/*:reset-normal*/
static pointer M1085face_reset_normal(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[12]));
	local[2]= fqv[133];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= fqv[133];
	ctx->vsp=local+2;
	w=(*ftab[14])(ctx,2,local+0,&ftab[14],fqv[113]); /*send-all*/
	local[0]= w;
BLK1086:
	ctx->vsp=local; return(local[0]);}

/*:face*/
static pointer M1087face_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0];
	local[0]= w;
BLK1088:
	ctx->vsp=local; return(local[0]);}

/*:all-edges*/
static pointer M1089face_all_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= (pointer)get_sym_func(fqv[158]);
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[60];
	ctx->vsp=local+4;
	w=(*ftab[14])(ctx,2,local+2,&ftab[14],fqv[113]); /*send-all*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	local[0]= w;
BLK1090:
	ctx->vsp=local; return(local[0]);}

/*:all-vertices*/
static pointer M1091face_all_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= (pointer)get_sym_func(fqv[158]);
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[140];
	ctx->vsp=local+4;
	w=(*ftab[14])(ctx,2,local+2,&ftab[14],fqv[113]); /*send-all*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	local[0]= w;
BLK1092:
	ctx->vsp=local; return(local[0]);}

/*:body*/
static pointer M1093face_body(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1096;}
	local[0]= NIL;
ENT1096:
ENT1095:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1097;
	argv[0]->c.obj.iv[9] = local[0];
	local[1]= argv[0]->c.obj.iv[9];
	goto IF1098;
IF1097:
	local[1]= argv[0]->c.obj.iv[9];
IF1098:
	w = local[1];
	local[0]= w;
BLK1094:
	ctx->vsp=local; return(local[0]);}

/*:primitive-face*/
static pointer M1099face_primitive_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1102;}
	local[0]= NIL;
ENT1102:
ENT1101:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1103;
	argv[0]->c.obj.iv[10] = local[0];
	local[1]= argv[0]->c.obj.iv[10];
	goto IF1104;
IF1103:
	local[1]= NIL;
IF1104:
	w = argv[0]->c.obj.iv[10];
	local[0]= w;
BLK1100:
	ctx->vsp=local; return(local[0]);}

/*:primitive-body*/
static pointer M1105face_primitive_body(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[10];
	local[1]= fqv[66];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK1106:
	ctx->vsp=local; return(local[0]);}

/*:id*/
static pointer M1107face_id(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1110;}
	local[0]= NIL;
ENT1110:
ENT1109:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1111;
	argv[0]->c.obj.iv[11] = local[0];
	local[1]= argv[0]->c.obj.iv[11];
	goto IF1112;
IF1111:
	local[1]= argv[0]->c.obj.iv[11];
IF1112:
	w = local[1];
	local[0]= w;
BLK1108:
	ctx->vsp=local; return(local[0]);}

/*:face-id*/
static pointer M1113face_face_id(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[10];
	local[1]= fqv[66];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[159];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w = argv[0]->c.obj.iv[11];
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK1114:
	ctx->vsp=local; return(local[0]);}

/*:primitive-body-type*/
static pointer M1115face_primitive_body_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[10];
	local[1]= fqv[66];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[160];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK1116:
	ctx->vsp=local; return(local[0]);}

/*:body-type*/
static pointer M1117face_body_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[9];
	local[1]= fqv[160];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK1118:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M1119face_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= (pointer)get_sym_func(fqv[82]);
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[12]));
	local[3]= fqv[13];
	local[4]= argv[2];
	if (argv[0]->c.obj.iv[9]==NIL) goto IF1121;
	local[5]= argv[0]->c.obj.iv[9];
	local[6]= fqv[160];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	goto IF1122;
IF1121:
	local[5]= fqv[161];
IF1122:
	local[6]= argv[0]->c.obj.iv[11];
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,7,local+0); /*apply*/
	local[0]= w;
BLK1120:
	ctx->vsp=local; return(local[0]);}

/*:copied-primitive-face-p*/
static pointer M1123face_copied_primitive_face_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[9];
	local[1]= fqv[162];
	ctx->vsp=local+2;
	w=(pointer)GETPROP(ctx,2,local+0); /*get*/
	local[0]= w;
BLK1124:
	ctx->vsp=local; return(local[0]);}

/*:primitive-body*/
static pointer M1125face_primitive_body(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[10];
	local[1]= fqv[66];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK1126:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1127face_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[163], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY1129;
	local[0] = NIL;
KEY1129:
	if (n & (1<<1)) goto KEY1130;
	local[1] = NIL;
KEY1130:
	if (n & (1<<2)) goto KEY1131;
	local[2] = NIL;
KEY1131:
	if (n & (1<<3)) goto KEY1132;
	local[3] = NIL;
KEY1132:
	if (n & (1<<4)) goto KEY1133;
	local[4] = NIL;
KEY1133:
	if (n & (1<<5)) goto KEY1134;
	local[5] = NIL;
KEY1134:
	if (n & (1<<6)) goto KEY1135;
	local[6] = NIL;
KEY1135:
	if (n & (1<<7)) goto KEY1136;
	local[7] = argv[0];
KEY1136:
	argv[0]->c.obj.iv[8] = local[4];
	local[8]= local[4];
	local[9]= fqv[130];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(*ftab[14])(ctx,3,local+8,&ftab[14],fqv[113]); /*send-all*/
	if (local[5]==NIL) goto IF1137;
	argv[0]->c.obj.iv[11] = local[5];
	local[8]= argv[0]->c.obj.iv[11];
	goto IF1138;
IF1137:
	local[8]= NIL;
IF1138:
	argv[0]->c.obj.iv[10] = local[7];
	if (local[6]==NIL) goto IF1139;
	argv[0]->c.obj.iv[9] = local[6];
	local[8]= argv[0]->c.obj.iv[9];
	goto IF1140;
IF1139:
	local[8]= NIL;
IF1140:
	local[8]= argv[0];
	local[9]= *(ovafptr(argv[1],fqv[12]));
	local[10]= fqv[24];
	local[11]= fqv[64];
	local[12]= local[0];
	local[13]= fqv[73];
	local[14]= local[1];
	local[15]= fqv[60];
	local[16]= local[2];
	local[17]= fqv[140];
	local[18]= local[3];
	ctx->vsp=local+19;
	w=(pointer)SENDMESSAGE(ctx,11,local+8); /*send-message*/
	w = argv[0];
	local[0]= w;
BLK1128:
	ctx->vsp=local; return(local[0]);}

/*:reflectance*/
static pointer M1141face_reflectance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1144;}
	local[0]= NIL;
ENT1144:
ENT1143:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]==NIL) goto IF1145;
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= fqv[164];
	ctx->vsp=local+6;
	w=(pointer)PUTPROP(ctx,3,local+3); /*putprop*/
	local[3]= w;
	goto IF1146;
IF1145:
	local[3]= argv[0];
	local[4]= fqv[164];
	ctx->vsp=local+5;
	w=(pointer)GETPROP(ctx,2,local+3); /*get*/
	local[2] = w;
	if (local[2]==NIL) goto IF1147;
	local[3]= local[2];
	goto IF1148;
IF1147:
	local[3]= argv[0]->c.obj.iv[9];
	local[4]= fqv[164];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
IF1148:
IF1146:
	w = local[3];
	local[0]= w;
BLK1142:
	ctx->vsp=local; return(local[0]);}

/*:diffusion*/
static pointer M1149face_diffusion(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1152;}
	local[0]= NIL;
ENT1152:
ENT1151:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]==NIL) goto IF1153;
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= fqv[165];
	ctx->vsp=local+6;
	w=(pointer)PUTPROP(ctx,3,local+3); /*putprop*/
	local[3]= w;
	goto IF1154;
IF1153:
	local[3]= argv[0];
	local[4]= fqv[165];
	ctx->vsp=local+5;
	w=(pointer)GETPROP(ctx,2,local+3); /*get*/
	local[2] = w;
	if (local[2]==NIL) goto IF1155;
	local[3]= local[2];
	goto IF1156;
IF1155:
	local[3]= argv[0]->c.obj.iv[9];
	local[4]= fqv[165];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
IF1156:
IF1154:
	w = local[3];
	local[0]= w;
BLK1150:
	ctx->vsp=local; return(local[0]);}

/*:color*/
static pointer M1157face_color(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1160;}
	local[0]= NIL;
ENT1160:
ENT1159:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1161;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[80];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= w;
	goto IF1162;
IF1161:
	local[1]= argv[0];
	local[2]= fqv[80];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[0] = w;
	if (local[0]==NIL) goto IF1163;
	local[1]= local[0];
	goto IF1164;
IF1163:
	if (argv[0]->c.obj.iv[9]==NIL) goto IF1165;
	local[1]= argv[0]->c.obj.iv[9];
	local[2]= fqv[80];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF1166;
IF1165:
	local[1]= NIL;
IF1166:
IF1164:
IF1162:
	w = local[1];
	local[0]= w;
BLK1158:
	ctx->vsp=local; return(local[0]);}

/*:contact-edge*/
static pointer M1167face_contact_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= *(ovafptr(argv[0],fqv[78]));
	local[2]= argv[2]->c.obj.iv[2];
	local[3]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)VMINUS(ctx,2,local+2); /*v-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= makeflt((double)fabs(fltval(w)));
	local[2]= loadglobal(fqv[23]);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto IF1169;
	w = NIL;
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK1168;
	goto IF1170;
IF1169:
	local[1]= NIL;
IF1170:
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= fqv[91];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
WHL1172:
	if (local[2]==NIL) goto WHX1173;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[2];
	local[4]= fqv[166];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[0] = w;
	if (local[0]==NIL) goto IF1176;
	w = local[0];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK1168;
	goto IF1177;
IF1176:
	local[3]= NIL;
IF1177:
	goto WHL1172;
WHX1173:
	local[3]= NIL;
BLK1174:
	w = NIL;
	local[0]= w;
BLK1168:
	ctx->vsp=local; return(local[0]);}

/*:contact-point*/
static pointer M1178face_contact_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1181;}
	local[0]= loadglobal(fqv[23]);
ENT1181:
ENT1180:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[12]));
	local[3]= fqv[145];
	local[4]= argv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	local[1]= w;
	local[2]= local[1];
	if (fqv[120]==local[2]) goto IF1182;
	local[2]= local[1];
	goto IF1183;
IF1182:
	local[2]= NIL;
	local[3]= argv[0]->c.obj.iv[8];
WHL1185:
	if (local[3]==NIL) goto WHX1186;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	local[5]= fqv[145];
	local[6]= argv[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[1] = w;
	local[4]= local[1];
	if (fqv[120]!=local[4]) goto IF1189;
	w = fqv[51];
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK1179;
	goto IF1190;
IF1189:
	local[4]= local[1];
	if (fqv[119]!=local[4]) goto IF1191;
	w = fqv[119];
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK1179;
	goto IF1192;
IF1191:
	local[4]= NIL;
IF1192:
IF1190:
	goto WHL1185;
WHX1186:
	local[4]= NIL;
BLK1187:
	w = NIL;
	local[2]= fqv[120];
IF1183:
	w = local[2];
	local[0]= w;
BLK1179:
	ctx->vsp=local; return(local[0]);}

/*:face*/
static pointer M1193hole_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1196;}
	local[0]= NIL;
ENT1196:
ENT1195:
	if (n>3) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F86facep(ctx,1,local+1); /*facep*/
	if (w==NIL) goto IF1197;
	argv[0]->c.obj.iv[8] = local[0];
	local[1]= argv[0]->c.obj.iv[8];
	goto IF1198;
IF1197:
	local[1]= NIL;
IF1198:
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK1194:
	ctx->vsp=local; return(local[0]);}

/*:hollowed-faces*/
static pointer M1199hole_hollowed_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[4];
WHL1202:
	if (local[2]==NIL) goto WHX1203;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1]->c.obj.iv[3];
	local[4]= local[1]->c.obj.iv[4];
	local[5]= local[3];
	if (argv[0]->c.obj.iv[8]==local[5]) goto IF1206;
	local[5]= local[3];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[16])(ctx,2,local+5,&ftab[16],fqv[167]); /*adjoin*/
	local[0] = w;
	local[5]= local[0];
	goto IF1207;
IF1206:
	local[5]= NIL;
IF1207:
	local[5]= local[4];
	if (argv[0]->c.obj.iv[8]==local[5]) goto IF1208;
	local[5]= local[4];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[16])(ctx,2,local+5,&ftab[16],fqv[167]); /*adjoin*/
	local[0] = w;
	local[5]= local[0];
	goto IF1209;
IF1208:
	local[5]= NIL;
IF1209:
	w = local[5];
	goto WHL1202;
WHX1203:
	local[3]= NIL;
BLK1204:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK1200:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1210hole_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[168], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY1212;
	local[0] = NIL;
KEY1212:
	if (n & (1<<1)) goto KEY1213;
	local[1] = NIL;
KEY1213:
	if (n & (1<<2)) goto KEY1214;
	local[2] = NIL;
KEY1214:
	if (n & (1<<3)) goto KEY1215;
	local[3] = NIL;
KEY1215:
	if (n & (1<<4)) goto KEY1216;
	local[4] = NIL;
KEY1216:
	argv[0]->c.obj.iv[8] = local[4];
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[12]));
	local[7]= fqv[24];
	local[8]= fqv[64];
	local[9]= local[0];
	local[10]= fqv[73];
	local[11]= local[1];
	local[12]= fqv[60];
	local[13]= local[2];
	local[14]= fqv[140];
	local[15]= local[3];
	ctx->vsp=local+16;
	w=(pointer)SENDMESSAGE(ctx,11,local+5); /*send-message*/
	w = argv[0];
	local[0]= w;
BLK1211:
	ctx->vsp=local; return(local[0]);}

/*make-plane*/
static pointer F109make_plane(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[169], &argv[0], n-0, local+0, 0);
	if (n & (1<<0)) goto KEY1218;
	local[3]= makeint(0);
	local[4]= makeint(0);
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[0] = w;
KEY1218:
	if (n & (1<<1)) goto KEY1219;
	local[3]= makeint(0);
	local[4]= makeint(0);
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[1] = w;
KEY1219:
	if (n & (1<<2)) goto KEY1220;
	local[2] = NIL;
KEY1220:
	w = local[1];
	if (!iscons(w)) goto IF1221;
	local[3]= local[1];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)F77face_normal_vector(ctx,2,local+3); /*face-normal-vector*/
	local[0] = w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	local[3]= local[1];
	goto IF1222;
IF1221:
	local[3]= NIL;
IF1222:
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)VNORMALIZE(ctx,1,local+3); /*normalize-vector*/
	local[0] = w;
	if (local[2]==NIL) goto IF1223;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,1,local+3); /*-*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SCALEVEC(ctx,2,local+3); /*scale*/
	local[1] = w;
	local[3]= local[1];
	goto IF1224;
IF1223:
	local[3]= NIL;
IF1224:
	local[3]= loadglobal(fqv[147]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[24];
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = local[3];
	local[0]= w;
BLK1217:
	ctx->vsp=local; return(local[0]);}

/*make-polygon*/
static pointer F113make_polygon(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST1230:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= loadglobal(fqv[170]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[24];
	local[4]= fqv[140];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK1229:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___geopack(ctx,n,argv,env)
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
	local[0]= fqv[171];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF1232;
	local[0]= fqv[172];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[173],w);
	goto IF1233;
IF1232:
	local[0]= fqv[174];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF1233:
	local[0]= fqv[175];
	local[1]= fqv[176];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[177]); /*require*/
	local[0]= fqv[178];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[131];
	local[1]= fqv[179];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF1234;
	local[0]= fqv[131];
	local[1]= fqv[179];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[131];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF1236;
	local[0]= fqv[131];
	local[1]= fqv[180];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF1237;
IF1236:
	local[0]= NIL;
IF1237:
	local[0]= fqv[131];
	goto IF1235;
IF1234:
	local[0]= NIL;
IF1235:
	local[0]= fqv[181];
	local[1]= fqv[179];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF1238;
	local[0]= fqv[181];
	local[1]= fqv[179];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[181];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF1240;
	local[0]= fqv[181];
	local[1]= fqv[180];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF1241;
IF1240:
	local[0]= NIL;
IF1241:
	local[0]= fqv[181];
	goto IF1239;
IF1238:
	local[0]= NIL;
IF1239:
	local[0]= fqv[182];
	local[1]= fqv[179];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF1242;
	local[0]= fqv[182];
	local[1]= fqv[179];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[182];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF1244;
	local[0]= fqv[182];
	local[1]= fqv[180];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF1245;
IF1244:
	local[0]= NIL;
IF1245:
	local[0]= fqv[182];
	goto IF1243;
IF1242:
	local[0]= NIL;
IF1243:
	local[0]= fqv[183];
	local[1]= fqv[179];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF1246;
	local[0]= fqv[183];
	local[1]= fqv[179];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[183];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF1248;
	local[0]= fqv[183];
	local[1]= fqv[180];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF1249;
IF1248:
	local[0]= NIL;
IF1249:
	local[0]= fqv[183];
	goto IF1247;
IF1246:
	local[0]= NIL;
IF1247:
	local[0]= fqv[35];
	local[1]= fqv[184];
	local[2]= makeflt(1.00000000e-02);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[45];
	local[1]= fqv[184];
	local[2]= makeflt(1.00000000e-02);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[8];
	local[1]= fqv[184];
	local[2]= makeflt(5.00000000e-03);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[23];
	local[1]= fqv[184];
	local[2]= makeflt(8.00000000e-03);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[76];
	local[1]= fqv[184];
	local[2]= makeflt(1.00000000e-03);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[79];
	local[1]= fqv[184];
	local[2]= makeflt(1.00000000e-01);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[185];
	ctx->vsp=local+1;
	w=(pointer)PROCLAIM(ctx,1,local+0); /*proclaim*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[186],module,F71vplus,fqv[187]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[188],module,F72vector_mean,fqv[189]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[190],module,F73direction_vector,fqv[191]);
	local[0]= fqv[192];
	local[1]= fqv[180];
	local[2]= makeint(0);
	local[3]= makeint(0);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[193];
	local[1]= fqv[180];
	local[2]= makeint(0);
	local[3]= makeint(0);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[194],module,F74triangle,fqv[195]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[196],module,F75triangle_normal,fqv[197]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[198],module,F76vector_angle,fqv[199]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[200],module,F77face_normal_vector,fqv[201]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[202],module,F78farthest,fqv[203]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[204],module,F79farthest_pair,fqv[205]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[206],module,F80maxindex,fqv[207]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[208],module,F81random_vector,fqv[209]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[210],module,F82random_normalized_vector,fqv[211]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[212],module,F83random_vector2,fqv[213]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[214],module,F84random_vectors,fqv[215]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[216],module,F85edgep,fqv[217]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[218],module,F86facep,fqv[219]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[220],module,F87bodyp,fqv[221]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[222],module,F88primitive_body_p,fqv[223]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[224],module,F89n_2,fqv[225]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[226],module,F90eps_,fqv[227]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[228],module,F91eps_,fqv[229]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[230],module,F92eps_,fqv[231]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[232],module,F93eps__,fqv[233]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[234],module,F94eps__,fqv[235]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[236],module,F95eps__,fqv[237]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[238],module,F96eps_zero,fqv[239]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[240],module,F97eps_in_range,fqv[241]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[242],module,F98eps_v_,fqv[243]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[244],module,F99eps_coords_,fqv[245]);
	local[0]= loadglobal(fqv[15]);
	storeglobal(fqv[246],local[0]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M210bounding_box_box,fqv[25],fqv[15],fqv[247]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M216bounding_box_minpoint,fqv[248],fqv[15],fqv[249]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M218bounding_box_maxpoint,fqv[250],fqv[15],fqv[251]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M220bounding_box_center,fqv[252],fqv[15],fqv[253]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M222bounding_box_diagonal,fqv[254],fqv[15],fqv[255]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M224bounding_box_prin1,fqv[13],fqv[15],fqv[256]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M228bounding_box_inner,fqv[137],fqv[15],fqv[257]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M231bounding_box_intersection,fqv[26],fqv[15],fqv[258]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M240bounding_box_union,fqv[27],fqv[15],fqv[259]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M245bounding_box_intersection_p,fqv[28],fqv[15],fqv[260]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M247bounding_box_grow,fqv[10],fqv[15],fqv[261]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M253bounding_box_volume,fqv[262],fqv[15],fqv[263]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M255bounding_box_extream_point,fqv[18],fqv[15],fqv[264]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M263bounding_box_below,fqv[265],fqv[15],fqv[266]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M267bounding_box_corners,fqv[267],fqv[15],fqv[268]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M279bounding_box_body,fqv[66],fqv[15],fqv[269]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M281bounding_box_init2,fqv[16],fqv[15],fqv[270]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M287bounding_box_init,fqv[24],fqv[15],fqv[271]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[272],module,F100make_bounding_box,fqv[273]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[274],module,F101make_big_bounding_box,fqv[275]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[276],module,F102bounding_box_intersection,fqv[277]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[278],module,F103bounding_box_union,fqv[279]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M318line_nvertex,fqv[55],fqv[43],fqv[280]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M322line_pvertex,fqv[54],fqv[43],fqv[281]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M326line_vertices,fqv[140],fqv[43],fqv[282]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M328line_eq,fqv[283],fqv[43],fqv[284]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M331line_eql,fqv[285],fqv[43],fqv[286]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M336line_equall,fqv[287],fqv[43],fqv[288]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M341line_parameter,fqv[48],fqv[43],fqv[289]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M343line_point,fqv[37],fqv[43],fqv[290]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M345line_box,fqv[25],fqv[43],fqv[291]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M350line_boxtest,fqv[143],fqv[43],fqv[292]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M354line_length,fqv[116],fqv[43],fqv[293]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M356line_end_point,fqv[294],fqv[43],fqv[295]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M362line_direction,fqv[61],fqv[43],fqv[296]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M364line_prin1,fqv[13],fqv[43],fqv[297]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M367line_init,fqv[24],fqv[43],fqv[298]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M381line_foot,fqv[38],fqv[43],fqv[299]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M383line_common_perpendicular,fqv[75],fqv[43],fqv[300]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M387line_distance_point,fqv[41],fqv[43],fqv[301]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M393line_distance_line,fqv[44],fqv[43],fqv[302]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M399line_distance,fqv[73],fqv[43],fqv[303]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M401line_distance,fqv[73],fqv[43],fqv[304]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M406line_colinear_point,fqv[47],fqv[43],fqv[305]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M410line_on_line_point,fqv[134],fqv[43],fqv[306]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M414line_colinear_line,fqv[307],fqv[43],fqv[308]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M419line_colinear_line_intersection,fqv[309],fqv[43],fqv[310]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M429line_coplanar,fqv[311],fqv[43],fqv[312]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M433line_project,fqv[50],fqv[43],fqv[313]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M435line_intersection,fqv[26],fqv[43],fqv[314]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M437line_intersect_line,fqv[125],fqv[43],fqv[315]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[316],module,F106make_line,fqv[317]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M465edge_faces,fqv[318],fqv[4],fqv[319]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M467edge_pvertex,fqv[54],fqv[4],fqv[320]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M473edge_nvertex,fqv[55],fqv[4],fqv[321]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M479edge_next_edge,fqv[58],fqv[4],fqv[322]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M481edge_next_vertex,fqv[323],fqv[4],fqv[324]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M483edge_direction,fqv[61],fqv[4],fqv[325]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M499edge_next_edge_angle,fqv[326],fqv[4],fqv[327]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M501edge_previous_edge_angle,fqv[328],fqv[4],fqv[329]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M503edge_body,fqv[66],fqv[4],fqv[330]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M508edge_pface,fqv[132],fqv[4],fqv[331]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M514edge_nface,fqv[332],fqv[4],fqv[333]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M520edge_another_face,fqv[334],fqv[4],fqv[335]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M526edge_binormal,fqv[336],fqv[4],fqv[337]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M532edge_angle,fqv[338],fqv[4],fqv[339]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M534edge_approximated_p,fqv[340],fqv[4],fqv[341]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M536edge_flags,fqv[342],fqv[4],fqv[343]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M538edge_contourp,fqv[344],fqv[4],fqv[345]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M545edge_set_approximated_flag,fqv[83],fqv[4],fqv[346]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M551edge_invert,fqv[156],fqv[4],fqv[347]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M553edge_set_angle,fqv[348],fqv[4],fqv[349]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M555edge_set_face,fqv[350],fqv[4],fqv[351]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M561edge_contact,fqv[166],fqv[4],fqv[352]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M567edge_neighborpoints,fqv[353],fqv[4],fqv[354]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M569edge_anothervertex,fqv[77],fqv[4],fqv[355]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M573edge_color,fqv[80],fqv[4],fqv[356]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M581edge_init,fqv[24],fqv[4],fqv[357]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M597edge_center_coordinates,fqv[358],fqv[4],fqv[359]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M602edge_pwing,fqv[99],fqv[4],fqv[360]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M612edge_pcwing,fqv[101],fqv[4],fqv[361]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M622edge_nwing,fqv[100],fqv[4],fqv[362]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M632edge_ncwing,fqv[102],fqv[4],fqv[363]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M642edge_connected_vertex,fqv[364],fqv[4],fqv[365]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M650edge_replace_face,fqv[366],fqv[4],fqv[367]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[368],module,F107winged_edge_p,fqv[369]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M657winged_edge_set_wings,fqv[370],fqv[98],fqv[371]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M659winged_edge_pwing,fqv[99],fqv[98],fqv[372]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M661winged_edge_nwing,fqv[100],fqv[98],fqv[373]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M663winged_edge_pcwing,fqv[101],fqv[98],fqv[374]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M665winged_edge_ncwing,fqv[102],fqv[98],fqv[375]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M667winged_edge_init,fqv[24],fqv[98],fqv[376]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M683plane_id,fqv[377],fqv[147],fqv[378]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M685plane_normal,fqv[64],fqv[147],fqv[379]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M687plane_distance,fqv[73],fqv[147],fqv[380]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M689plane_plane_distance,fqv[104],fqv[147],fqv[381]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M691plane_on_plane_p,fqv[382],fqv[147],fqv[383]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M695plane_coplanar_point,fqv[384],fqv[147],fqv[385]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M699plane_coplanar_line,fqv[386],fqv[147],fqv[387]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M704plane_intersection,fqv[26],fqv[147],fqv[388]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M706plane_intersect_edge,fqv[126],fqv[147],fqv[389]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M713plane_foot,fqv[38],fqv[147],fqv[390]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M715plane_original_body,fqv[391],fqv[147],fqv[392]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M717plane_brightness,fqv[393],fqv[147],fqv[394]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M719plane_project,fqv[50],fqv[147],fqv[395]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M723plane_separation,fqv[396],fqv[147],fqv[397]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M749plane_init,fqv[24],fqv[147],fqv[398]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M755polygon_face,fqv[130],fqv[170],fqv[399]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M757polygon_edges,fqv[60],fqv[170],fqv[400]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M759polygon_edge,fqv[401],fqv[170],fqv[402]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M761polygon_all_edges,fqv[91],fqv[170],fqv[403]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M763polygon_vertices,fqv[140],fqv[170],fqv[404]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M765polygon_vertex,fqv[405],fqv[170],fqv[406]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M767polygon_next_edge,fqv[58],fqv[170],fqv[407]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M771polygon_previous_edge,fqv[65],fqv[170],fqv[408]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M781polygon_adjacent_faces,fqv[409],fqv[170],fqv[410]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M790polygon_convexp,fqv[411],fqv[170],fqv[412]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M792polygon_box,fqv[25],fqv[170],fqv[413]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M797polygon_boxtest,fqv[143],fqv[170],fqv[414]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M802polygon_vertices_mean,fqv[415],fqv[170],fqv[416]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M804polygon_distance,fqv[73],fqv[170],fqv[417]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M812polygon_area,fqv[118],fqv[170],fqv[418]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M818polygon_perimeter,fqv[419],fqv[170],fqv[420]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M820polygon_volume,fqv[262],fqv[170],fqv[421]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M824polygon_centroid,fqv[151],fqv[170],fqv[422]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M834polygon_color,fqv[80],fqv[170],fqv[423]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M840polygon_insidep,fqv[110],fqv[170],fqv[424]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M869polygon_intersect_point_vector,fqv[425],fqv[170],fqv[426]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M875polygon_intersect_line,fqv[125],fqv[170],fqv[427]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M879polygon_intersect_edge,fqv[126],fqv[170],fqv[428]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M881polygon_intersect_face,fqv[429],fqv[170],fqv[430]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M892polygon_visible,fqv[431],fqv[170],fqv[432]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M896polygon_transform_normal,fqv[157],fqv[170],fqv[433]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M898polygon_reset_normal,fqv[133],fqv[170],fqv[434]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M900polygon_set_convexp,fqv[128],fqv[170],fqv[435]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M908polygon_invert,fqv[156],fqv[170],fqv[436]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M910polygon_init,fqv[24],fqv[170],fqv[437]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M938polygon_on_vertex,fqv[121],fqv[170],fqv[438]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M949polygon_on_edge,fqv[155],fqv[170],fqv[439]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M960polygon_coplanar_distance,fqv[440],fqv[170],fqv[441]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M964polygon_coplanar_intersections,fqv[144],fqv[170],fqv[442]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1000polygon_contact_edge,fqv[146],fqv[170],fqv[443]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1009polygon_contact_plane,fqv[148],fqv[170],fqv[444]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1015polygon_contact_point,fqv[145],fqv[170],fqv[445]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1021polygon_contactp,fqv[446],fqv[170],fqv[447]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1029polygon_aligned_plane,fqv[448],fqv[170],fqv[449]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1033face_insidep,fqv[110],fqv[5],fqv[450]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1048face_distance,fqv[73],fqv[5],fqv[451]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1056face_area,fqv[118],fqv[5],fqv[452]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1058face_centroid,fqv[151],fqv[5],fqv[453]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1069face_on_vertex,fqv[121],fqv[5],fqv[454]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1073face_on_edge,fqv[155],fqv[5],fqv[455]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1077face_invert,fqv[156],fqv[5],fqv[456]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1079face_holes,fqv[59],fqv[5],fqv[457]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1081face_enter_hole,fqv[458],fqv[5],fqv[459]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1083face_transform_normal,fqv[157],fqv[5],fqv[460]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1085face_reset_normal,fqv[133],fqv[5],fqv[461]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1087face_face,fqv[130],fqv[5],fqv[462]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1089face_all_edges,fqv[91],fqv[5],fqv[463]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1091face_all_vertices,fqv[464],fqv[5],fqv[465]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1093face_body,fqv[66],fqv[5],fqv[466]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1099face_primitive_face,fqv[467],fqv[5],fqv[468]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1105face_primitive_body,fqv[469],fqv[5],fqv[470]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1107face_id,fqv[377],fqv[5],fqv[471]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1113face_face_id,fqv[472],fqv[5],fqv[473]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1115face_primitive_body_type,fqv[474],fqv[5],fqv[475]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1117face_body_type,fqv[160],fqv[5],fqv[476]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1119face_prin1,fqv[13],fqv[5],fqv[477]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1123face_copied_primitive_face_p,fqv[478],fqv[5],fqv[479]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1125face_primitive_body,fqv[469],fqv[5],fqv[480]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1127face_init,fqv[24],fqv[5],fqv[481]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1141face_reflectance,fqv[164],fqv[5],fqv[482]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1149face_diffusion,fqv[165],fqv[5],fqv[483]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1157face_color,fqv[80],fqv[5],fqv[484]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1167face_contact_edge,fqv[146],fqv[5],fqv[485]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1178face_contact_point,fqv[145],fqv[5],fqv[486]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1193hole_face,fqv[130],fqv[487],fqv[488]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1199hole_hollowed_faces,fqv[489],fqv[487],fqv[490]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1210hole_init,fqv[24],fqv[487],fqv[491]);
	local[0]= fqv[131];
	local[1]= fqv[180];
	local[2]= loadglobal(fqv[4]);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[181];
	local[1]= fqv[180];
	local[2]= loadglobal(fqv[5]);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[492];
	local[1]= fqv[180];
	local[2]= loadglobal(fqv[487]);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[182];
	local[1]= fqv[180];
	local[2]= loadglobal(fqv[6]);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[493],module,F109make_plane,fqv[494]);
	local[0]= fqv[495];
	local[1]= fqv[496];
	ctx->vsp=local+2;
	w=(pointer)F109make_plane(ctx,0,local+2); /*make-plane*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[497];
	local[1]= fqv[496];
	local[2]= fqv[64];
	local[3]= fqv[498];
	ctx->vsp=local+4;
	w=(pointer)F109make_plane(ctx,2,local+2); /*make-plane*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[499];
	local[1]= fqv[496];
	local[2]= fqv[64];
	local[3]= fqv[500];
	ctx->vsp=local+4;
	w=(pointer)F109make_plane(ctx,2,local+2); /*make-plane*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[501],module,F113make_polygon,fqv[502]);
	local[0]= fqv[503];
	local[1]= fqv[504];
	ctx->vsp=local+2;
	w=(*ftab[18])(ctx,2,local+0,&ftab[18],fqv[505]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<19; i++) ftab[i]=fcallx;
}
