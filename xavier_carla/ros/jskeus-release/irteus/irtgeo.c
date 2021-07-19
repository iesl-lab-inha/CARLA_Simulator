/* ./irtgeo.c :  entry=irtgeo */
/* compiled by EusLisp 9.27() for Linux created on ip-10-0-1-214(Fri Apr 16 04:05:26 PST 2021) */
#include "eus.h"
#include "irtgeo.h"
#pragma init (register_irtgeo)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___irtgeo();
extern pointer build_quote_vector();
static int register_irtgeo()
  { add_module_initializer("___irtgeo", ___irtgeo);}

static pointer F63midcoords();
static pointer F64transform_coords();
static pointer F65orient_coords_to_axis();
static pointer F66face_to_triangle_aux();
static pointer F67face_to_triangle();
static pointer F68face_to_tessel_triangle();
static pointer F69face_to_triangle_rest_polygon();
static pointer F70face_to_triangle_make_simple();
static pointer F71body_to_faces();
static pointer F72body_to_triangles();
static pointer F73triangle_to_triangle();
static pointer F74make_sphere();
static pointer F75make_ring();
static pointer F76make_fan_cylinder();
static pointer F77x_of_cube();
static pointer F78y_of_cube();
static pointer F79z_of_cube();
static pointer F80height_of_cylinder();
static pointer F81radius_of_cylinder();
static pointer F82radius_of_sphere();
static pointer F83make_faceset_from_vertices();
static pointer F84matrix_to_euler_angle();
static pointer F85quaternion_from_two_vectors();

/*midcoords*/
static pointer F63midcoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= fqv[0];
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[2];
	local[4]= fqv[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,3,local+1,&ftab[0],fqv[2]); /*midpoint*/
	local[1]= w;
	local[2]= fqv[3];
	local[3]= argv[0];
	local[4]= argv[1];
	local[5]= fqv[4];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= argv[2];
	local[6]= fqv[4];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[1])(ctx,3,local+3,&ftab[1],fqv[5]); /*user::midrot*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[2])(ctx,4,local+0,&ftab[2],fqv[6]); /*make-coords*/
	local[0]= w;
BLK86:
	ctx->vsp=local; return(local[0]);}

/*:worldcoords*/
static pointer M87line_worldcoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[0];
	local[1]= makeflt(5.0000000000000000000000e-01);
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,3,local+1,&ftab[0],fqv[2]); /*midpoint*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[6]); /*make-coords*/
	local[0]= w;
BLK88:
	ctx->vsp=local; return(local[0]);}

/*:axis*/
static pointer M89coordinates_axis(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[7];
	local[2]= argv[2];
	local[3]= local[2];
	if (fqv[8]!=local[3]) goto IF92;
	local[3]= fqv[9];
	goto IF93;
IF92:
	local[3]= local[2];
	if (fqv[10]!=local[3]) goto IF94;
	local[3]= fqv[11];
	goto IF95;
IF94:
	local[3]= local[2];
	if (fqv[12]!=local[3]) goto IF96;
	local[3]= fqv[13];
	goto IF97;
IF96:
	local[3]= NIL;
IF97:
IF95:
IF93:
	w = local[3];
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK90:
	ctx->vsp=local; return(local[0]);}

/*:difference-position*/
static pointer M98coordinates_difference_position(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[14], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY100;
	local[0] = T;
KEY100:
	local[1]= argv[0];
	local[2]= fqv[15];
	local[3]= argv[2];
	local[4]= fqv[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= local[0];
	local[3]= local[2];
	w = fqv[16];
	if (memq(local[3],w)==NIL) goto IF102;
	local[3]= local[1];
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)SETELT(ctx,3,local+3); /*setelt*/
	local[3]= w;
	goto IF103;
IF102:
	local[3]= local[2];
	w = fqv[17];
	if (memq(local[3],w)==NIL) goto IF104;
	local[3]= local[1];
	local[4]= makeint((eusinteger_t)1L);
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)SETELT(ctx,3,local+3); /*setelt*/
	local[3]= w;
	goto IF105;
IF104:
	local[3]= local[2];
	w = fqv[18];
	if (memq(local[3],w)==NIL) goto IF106;
	local[3]= local[1];
	local[4]= makeint((eusinteger_t)2L);
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)SETELT(ctx,3,local+3); /*setelt*/
	local[3]= w;
	goto IF107;
IF106:
	local[3]= local[2];
	w = fqv[19];
	if (memq(local[3],w)==NIL) goto IF108;
	local[3]= local[1];
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)SETELT(ctx,3,local+3); /*setelt*/
	local[3]= local[1];
	local[4]= makeint((eusinteger_t)1L);
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)SETELT(ctx,3,local+3); /*setelt*/
	local[3]= w;
	goto IF109;
IF108:
	local[3]= local[2];
	w = fqv[20];
	if (memq(local[3],w)==NIL) goto IF110;
	local[3]= local[1];
	local[4]= makeint((eusinteger_t)1L);
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)SETELT(ctx,3,local+3); /*setelt*/
	local[3]= local[1];
	local[4]= makeint((eusinteger_t)2L);
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)SETELT(ctx,3,local+3); /*setelt*/
	local[3]= w;
	goto IF111;
IF110:
	local[3]= local[2];
	w = fqv[21];
	if (memq(local[3],w)==NIL) goto IF112;
	local[3]= local[1];
	local[4]= makeint((eusinteger_t)2L);
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)SETELT(ctx,3,local+3); /*setelt*/
	local[3]= local[1];
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)SETELT(ctx,3,local+3); /*setelt*/
	local[3]= w;
	goto IF113;
IF112:
	local[3]= NIL;
IF113:
IF111:
IF109:
IF107:
IF105:
IF103:
	w = local[3];
	w = local[1];
	local[0]= w;
BLK99:
	ctx->vsp=local; return(local[0]);}

/*:difference-rotation*/
static pointer M114coordinates_difference_rotation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[22], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY116;
	local[0] = T;
KEY116:
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,FLET117,env,argv,local);
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= local[0];
	local[7]= local[6];
	w = fqv[23];
	if (memq(local[7],w)==NIL) goto IF119;
	local[7]= argv[0];
	local[8]= fqv[24];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[4] = w;
	local[7]= argv[2];
	local[8]= fqv[24];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[5] = w;
	local[7]= argv[0];
	local[8]= fqv[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)TRANSPOSE(ctx,1,local+7); /*transpose*/
	local[7]= w;
	local[8]= local[4];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)VINNERPRODUCT(ctx,2,local+8); /*v.*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[3])(ctx,1,local+8,&ftab[3],fqv[25]); /*acos*/
	local[8]= w;
	local[9]= local[4];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+9); /*v**/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[4])(ctx,1,local+9,&ftab[4],fqv[26]); /*normalize-vector*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,2,local+8); /*scale*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)TRANSFORM(ctx,2,local+7); /*transform*/
	local[3] = w;
	local[7]= local[3];
	goto IF120;
IF119:
	local[7]= local[6];
	w = fqv[27];
	if (memq(local[7],w)==NIL) goto IF121;
	local[7]= local[0];
	local[8]= local[7];
	if (fqv[28]!=local[8]) goto IF124;
	local[8]= fqv[8];
	goto IF125;
IF124:
	local[8]= local[7];
	if (fqv[29]!=local[8]) goto IF126;
	local[8]= fqv[10];
	goto IF127;
IF126:
	local[8]= local[7];
	if (fqv[30]!=local[8]) goto IF128;
	local[8]= fqv[12];
	goto IF129;
IF128:
	local[8]= NIL;
IF129:
IF127:
IF125:
	w = local[8];
	local[7]= w;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= argv[0];
	local[11]= fqv[24];
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[8] = w;
	local[10]= argv[2];
	local[11]= fqv[24];
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[9] = w;
	local[10]= argv[0];
	local[11]= argv[2];
	local[12]= local[7];
	w = local[1];
	ctx->vsp=local+13;
	w=FLET117(ctx,3,local+10,w);
	if (w!=NIL) goto IF130;
	local[10]= local[9];
	ctx->vsp=local+11;
	w=(pointer)VMINUS(ctx,1,local+10); /*v-*/
	local[9] = w;
	local[10]= local[9];
	goto IF131;
IF130:
	local[10]= NIL;
IF131:
	local[10]= argv[0];
	local[11]= fqv[4];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)TRANSPOSE(ctx,1,local+10); /*transpose*/
	local[10]= w;
	local[11]= local[8];
	local[12]= local[9];
	ctx->vsp=local+13;
	w=(pointer)VINNERPRODUCT(ctx,2,local+11); /*v.*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[3])(ctx,1,local+11,&ftab[3],fqv[25]); /*acos*/
	local[11]= w;
	local[12]= local[8];
	local[13]= local[9];
	ctx->vsp=local+14;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+12); /*v**/
	local[12]= w;
	ctx->vsp=local+13;
	w=(*ftab[4])(ctx,1,local+12,&ftab[4],fqv[26]); /*normalize-vector*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)SCALEVEC(ctx,2,local+11); /*scale*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)TRANSFORM(ctx,2,local+10); /*transform*/
	local[3] = w;
	w = local[3];
	local[7]= w;
	goto IF122;
IF121:
	local[7]= local[6];
	w = fqv[31];
	if (memq(local[7],w)==NIL) goto IF132;
	local[7]= argv[2];
	local[8]= fqv[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= argv[0];
	local[9]= argv[2];
	local[10]= local[0];
	local[11]= local[10];
	if (fqv[32]!=local[11]) goto IF137;
	local[11]= fqv[10];
	goto IF138;
IF137:
	local[11]= local[10];
	if (fqv[33]!=local[11]) goto IF139;
	local[11]= fqv[12];
	goto IF140;
IF139:
	local[11]= local[10];
	if (fqv[34]!=local[11]) goto IF141;
	local[11]= fqv[8];
	goto IF142;
IF141:
	local[11]= NIL;
IF142:
IF140:
IF138:
	w = local[11];
	local[10]= w;
	w = local[1];
	ctx->vsp=local+11;
	w=FLET117(ctx,3,local+8,w);
	if (w!=NIL) goto IF134;
	local[8]= local[7];
	local[9]= makeflt(3.1415926535897931159980e+00);
	local[10]= local[0];
	local[11]= local[10];
	if (fqv[32]!=local[11]) goto IF144;
	local[11]= fqv[8];
	goto IF145;
IF144:
	local[11]= local[10];
	if (fqv[33]!=local[11]) goto IF146;
	local[11]= fqv[10];
	goto IF147;
IF146:
	local[11]= local[10];
	if (fqv[34]!=local[11]) goto IF148;
	local[11]= fqv[12];
	goto IF149;
IF148:
	local[11]= NIL;
IF149:
IF147:
IF145:
	w = local[11];
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)ROTMAT(ctx,3,local+8); /*rotate-matrix*/
	local[7] = w;
	local[8]= local[7];
	goto IF135;
IF134:
	local[8]= NIL;
IF135:
	local[8]= argv[0];
	local[9]= fqv[4];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)TRANSPOSE(ctx,1,local+8); /*transpose*/
	local[8]= w;
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)MATTIMES(ctx,2,local+8); /*m**/
	local[2] = w;
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(*ftab[5])(ctx,1,local+8,&ftab[5],fqv[35]); /*user::matrix-log*/
	local[3] = w;
	w = local[3];
	local[7]= w;
	goto IF133;
IF132:
	local[7]= local[6];
	if (fqv[36]!=local[7]) goto IF150;
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,3,local+7); /*float-vector*/
	local[3] = w;
	local[7]= local[3];
	goto IF151;
IF150:
	if (T==NIL) goto IF152;
	local[7]= argv[0];
	local[8]= fqv[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)TRANSPOSE(ctx,1,local+7); /*transpose*/
	local[7]= w;
	local[8]= argv[2];
	local[9]= fqv[4];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MATTIMES(ctx,2,local+7); /*m**/
	local[2] = w;
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(*ftab[5])(ctx,1,local+7,&ftab[5],fqv[35]); /*user::matrix-log*/
	local[3] = w;
	local[7]= local[3];
	goto IF153;
IF152:
	local[7]= NIL;
IF153:
IF151:
IF133:
IF122:
IF120:
	w = local[7];
	w = local[3];
	local[0]= w;
BLK115:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET117(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[24];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= argv[1];
	local[2]= fqv[24];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,1,local+2); /*v-*/
	local[2]= w;
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)VINNERPRODUCT(ctx,2,local+3); /*v.*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[3])(ctx,1,local+3,&ftab[3],fqv[25]); /*acos*/
	local[3]= w;
	local[4]= local[0];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+4); /*v**/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,1,local+4,&ftab[4],fqv[26]); /*normalize-vector*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SCALEVEC(ctx,2,local+3); /*scale*/
	local[3]= w;
	local[4]= local[0];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)VINNERPRODUCT(ctx,2,local+4); /*v.*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[3])(ctx,1,local+4,&ftab[3],fqv[25]); /*acos*/
	local[4]= w;
	local[5]= local[0];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+5); /*v**/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,1,local+5,&ftab[4],fqv[26]); /*normalize-vector*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SCALEVEC(ctx,2,local+4); /*scale*/
	local[4]= w;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)VNORM(ctx,1,local+5); /*norm*/
	local[5]= w;
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)VNORM(ctx,1,local+6); /*norm*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LESSP(ctx,2,local+5); /*<*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:move-to*/
static pointer M154coordinates_move_to(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT157;}
	local[0]= fqv[37];
ENT157:
ENT156:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,1,local+3,&ftab[6],fqv[38]); /*coordinates-p*/
	if (w!=NIL) goto IF158;
	local[3]= fqv[39];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
	goto IF159;
IF158:
	local[3]= NIL;
IF159:
	local[3]= local[0];
	w = fqv[40];
	if (memq(local[3],w)!=NIL) goto OR162;
	local[3]= local[0];
	if (argv[0]==local[3]) goto OR162;
	goto CON161;
OR162:
	local[3]= argv[0];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)F64transform_coords(ctx,2,local+3); /*transform-coords*/
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[41];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto CON160;
CON161:
	local[3]= local[0];
	w = fqv[42];
	if (memq(local[3],w)!=NIL) goto OR164;
	local[3]= local[0];
	local[4]= loadglobal(fqv[43]);
	ctx->vsp=local+5;
	w=(pointer)EQUAL(ctx,2,local+3); /*equal*/
	if (w!=NIL) goto OR164;
	goto CON163;
OR164:
	local[3]= argv[0];
	local[4]= fqv[41];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto CON160;
CON163:
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,1,local+3,&ftab[6],fqv[38]); /*coordinates-p*/
	if (w==NIL) goto CON165;
	local[3]= local[0];
	local[4]= fqv[44];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)F64transform_coords(ctx,2,local+3); /*transform-coords*/
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[45];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= fqv[46];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= local[2];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)F64transform_coords(ctx,3,local+3); /*transform-coords*/
	local[3]= argv[0];
	local[4]= fqv[41];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto CON160;
CON165:
	local[3]= NIL;
CON160:
	w = local[3];
	local[0]= w;
BLK155:
	ctx->vsp=local; return(local[0]);}

/*:transformation*/
static pointer M166coordinates_transformation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT169;}
	local[0]= fqv[37];
ENT169:
ENT168:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= fqv[44];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	argv[2] = w;
	local[1]= argv[0];
	local[2]= fqv[44];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[46];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= NIL;
	local[4]= local[0];
	w = fqv[47];
	if (memq(local[4],w)!=NIL) goto OR172;
	local[4]= local[0];
	if (argv[0]==local[4]) goto OR172;
	goto CON171;
OR172:
	local[4]= local[2];
	local[5]= argv[2];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F64transform_coords(ctx,3,local+4); /*transform-coords*/
	local[4]= w;
	goto CON170;
CON171:
	local[4]= local[0];
	w = fqv[48];
	if (memq(local[4],w)!=NIL) goto OR174;
	local[4]= local[0];
	if (loadglobal(fqv[43])==local[4]) goto OR174;
	goto CON173;
OR174:
	local[4]= argv[2];
	local[5]= local[2];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F64transform_coords(ctx,3,local+4); /*transform-coords*/
	local[4]= w;
	goto CON170;
CON173:
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[6])(ctx,1,local+4,&ftab[6],fqv[38]); /*coordinates-p*/
	if (w==NIL) goto CON175;
	local[4]= local[0];
	local[5]= fqv[44];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[3] = w;
	local[4]= argv[2];
	local[5]= local[2];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F64transform_coords(ctx,3,local+4); /*transform-coords*/
	local[4]= local[3];
	local[5]= fqv[46];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[2];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F64transform_coords(ctx,3,local+4); /*transform-coords*/
	local[4]= local[2];
	local[5]= local[3];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F64transform_coords(ctx,3,local+4); /*transform-coords*/
	local[4]= w;
	goto CON170;
CON175:
	local[4]= argv[0];
	local[5]= fqv[49];
	local[6]= fqv[50];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto CON170;
CON176:
	local[4]= NIL;
CON170:
	w = local[2];
	local[0]= w;
BLK167:
	ctx->vsp=local; return(local[0]);}

/*:transform*/
static pointer M177coordinates_transform(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT180;}
	local[0]= fqv[37];
ENT180:
ENT179:
	if (n>4) maerror();
	local[1]= local[0];
	w = fqv[51];
	if (memq(local[1],w)!=NIL) goto OR183;
	local[1]= local[0];
	if (argv[0]==local[1]) goto OR183;
	goto CON182;
OR183:
	local[1]= argv[0];
	local[2]= argv[2];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F64transform_coords(ctx,3,local+1); /*transform-coords*/
	local[1]= w;
	goto CON181;
CON182:
	local[1]= local[0];
	w = fqv[52];
	if (memq(local[1],w)!=NIL) goto OR185;
	local[1]= local[0];
	if (loadglobal(fqv[43])==local[1]) goto OR185;
	goto CON184;
OR185:
	local[1]= argv[2];
	local[2]= argv[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F64transform_coords(ctx,3,local+1); /*transform-coords*/
	local[1]= w;
	goto CON181;
CON184:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[38]); /*coordinates-p*/
	if (w==NIL) goto CON186;
	local[1]= local[0];
	local[2]= fqv[46];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F64transform_coords(ctx,3,local+1); /*transform-coords*/
	local[1]= argv[2];
	local[2]= argv[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F64transform_coords(ctx,3,local+1); /*transform-coords*/
	local[1]= local[0];
	local[2]= fqv[44];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F64transform_coords(ctx,3,local+1); /*transform-coords*/
	local[1]= w;
	goto CON181;
CON186:
	local[1]= argv[0];
	local[2]= fqv[49];
	local[3]= fqv[53];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON181;
CON187:
	local[1]= NIL;
CON181:
	local[1]= argv[0];
	local[2]= fqv[41];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK178:
	ctx->vsp=local; return(local[0]);}

/*:move-coords*/
static pointer M188coordinates_move_coords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[54];
	local[2]= argv[3];
	local[3]= fqv[55];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[44];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK189:
	ctx->vsp=local; return(local[0]);}

/*:worldcoords*/
static pointer M190cascaded_coords_worldcoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[7]==NIL) goto IF192;
	if (argv[0]->c.obj.iv[3]==NIL) goto IF194;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[44];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+3;
	w=(pointer)F64transform_coords(ctx,3,local+0); /*transform-coords*/
	local[0]= w;
	goto IF195;
IF194:
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= fqv[56];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
IF195:
	local[0]= argv[0];
	local[1]= fqv[57];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[7] = NIL;
	local[0]= argv[0]->c.obj.iv[7];
	goto IF193;
IF192:
	local[0]= NIL;
IF193:
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK191:
	ctx->vsp=local; return(local[0]);}

/*:transformation*/
static pointer M196cascaded_coords_transformation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT199;}
	local[0]= fqv[37];
ENT199:
ENT198:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= fqv[44];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[44];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[46];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= local[0];
	w = fqv[58];
	if (memq(local[6],w)!=NIL) goto OR202;
	local[6]= local[0];
	if (argv[0]==local[6]) goto OR202;
	goto CON201;
OR202:
	local[6]= local[3];
	local[7]= local[1];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)F64transform_coords(ctx,3,local+6); /*transform-coords*/
	local[6]= w;
	goto CON200;
CON201:
	local[6]= local[0];
	w = fqv[59];
	if (memq(local[6],w)!=NIL) goto OR204;
	local[6]= local[0];
	if (argv[0]->c.obj.iv[3]==local[6]) goto OR204;
	goto CON203;
OR204:
	local[6]= argv[0];
	local[7]= *(ovafptr(argv[1],fqv[60]));
	local[8]= fqv[46];
	ctx->vsp=local+9;
	w=(pointer)SENDMESSAGE(ctx,3,local+6); /*send-message*/
	local[4] = w;
	local[6]= local[1];
	local[7]= local[4];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)F64transform_coords(ctx,3,local+6); /*transform-coords*/
	local[6]= local[3];
	local[7]= local[4];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)F64transform_coords(ctx,3,local+6); /*transform-coords*/
	local[6]= argv[0];
	local[7]= local[4];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)F64transform_coords(ctx,3,local+6); /*transform-coords*/
	local[6]= w;
	goto CON200;
CON203:
	local[6]= local[0];
	w = fqv[61];
	if (memq(local[6],w)!=NIL) goto OR206;
	local[6]= local[0];
	local[7]= loadglobal(fqv[43]);
	ctx->vsp=local+8;
	w=(pointer)EQUAL(ctx,2,local+6); /*equal*/
	if (w!=NIL) goto OR206;
	goto CON205;
OR206:
	local[6]= local[1];
	local[7]= local[3];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)F64transform_coords(ctx,3,local+6); /*transform-coords*/
	local[6]= w;
	goto CON200;
CON205:
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[6])(ctx,1,local+6,&ftab[6],fqv[38]); /*coordinates-p*/
	if (w==NIL) goto CON207;
	local[6]= local[0];
	local[7]= fqv[44];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[5] = w;
	local[6]= local[3];
	local[7]= local[5];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)F64transform_coords(ctx,3,local+6); /*transform-coords*/
	local[6]= local[1];
	local[7]= local[3];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)F64transform_coords(ctx,3,local+6); /*transform-coords*/
	local[6]= local[5];
	local[7]= fqv[46];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= local[3];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)F64transform_coords(ctx,3,local+6); /*transform-coords*/
	local[6]= w;
	goto CON200;
CON207:
	local[6]= argv[0];
	local[7]= fqv[49];
	local[8]= fqv[62];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[6]= w;
	goto CON200;
CON208:
	local[6]= NIL;
CON200:
	w = local[6];
	local[0]= w;
BLK197:
	ctx->vsp=local; return(local[0]);}

/*:transform*/
static pointer M209cascaded_coords_transform(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT212;}
	local[0]= fqv[37];
ENT212:
ENT211:
	if (n>4) maerror();
	local[1]= local[0];
	w = fqv[63];
	if (memq(local[1],w)!=NIL) goto OR215;
	local[1]= local[0];
	if (argv[0]==local[1]) goto OR215;
	goto CON214;
OR215:
	local[1]= argv[0];
	local[2]= argv[2];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F64transform_coords(ctx,3,local+1); /*transform-coords*/
	local[1]= w;
	goto CON213;
CON214:
	local[1]= local[0];
	w = fqv[64];
	if (memq(local[1],w)!=NIL) goto OR217;
	local[1]= local[0];
	if (argv[0]->c.obj.iv[3]==local[1]) goto OR217;
	goto CON216;
OR217:
	local[1]= argv[2];
	local[2]= argv[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F64transform_coords(ctx,3,local+1); /*transform-coords*/
	local[1]= w;
	goto CON213;
CON216:
	local[1]= local[0];
	w = fqv[65];
	if (memq(local[1],w)!=NIL) goto OR219;
	local[1]= local[0];
	local[2]= loadglobal(fqv[43]);
	ctx->vsp=local+3;
	w=(pointer)EQUAL(ctx,2,local+1); /*equal*/
	if (w!=NIL) goto OR219;
	goto CON218;
OR219:
	local[1]= argv[0];
	local[2]= fqv[45];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= local[1];
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F64transform_coords(ctx,3,local+2); /*transform-coords*/
	local[2]= argv[2];
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F64transform_coords(ctx,3,local+2); /*transform-coords*/
	local[2]= local[1];
	local[3]= fqv[46];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F64transform_coords(ctx,3,local+2); /*transform-coords*/
	local[1]= w;
	goto CON213;
CON218:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[38]); /*coordinates-p*/
	if (w==NIL) goto CON220;
	local[1]= argv[0];
	local[2]= fqv[45];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= local[1];
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F64transform_coords(ctx,3,local+2); /*transform-coords*/
	local[2]= local[0];
	local[3]= fqv[46];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F64transform_coords(ctx,3,local+2); /*transform-coords*/
	local[2]= argv[2];
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F64transform_coords(ctx,3,local+2); /*transform-coords*/
	local[2]= local[0];
	local[3]= fqv[44];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F64transform_coords(ctx,3,local+2); /*transform-coords*/
	local[2]= local[1];
	local[3]= fqv[46];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F64transform_coords(ctx,3,local+2); /*transform-coords*/
	local[1]= w;
	goto CON213;
CON220:
	local[1]= argv[0];
	local[2]= fqv[49];
	local[3]= fqv[66];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON213;
CON221:
	local[1]= NIL;
CON213:
	local[1]= argv[0];
	local[2]= fqv[41];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK210:
	ctx->vsp=local; return(local[0]);}

/*:move-to*/
static pointer M222cascaded_coords_move_to(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT225;}
	local[0]= fqv[37];
ENT225:
ENT224:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,1,local+3,&ftab[6],fqv[38]); /*coordinates-p*/
	if (w!=NIL) goto IF226;
	local[3]= fqv[67];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
	goto IF227;
IF226:
	local[3]= NIL;
IF227:
	local[3]= local[0];
	w = fqv[68];
	if (memq(local[3],w)!=NIL) goto OR230;
	local[3]= local[0];
	if (argv[0]==local[3]) goto OR230;
	goto CON229;
OR230:
	local[3]= argv[0];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)F64transform_coords(ctx,2,local+3); /*transform-coords*/
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[41];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto CON228;
CON229:
	local[3]= local[0];
	w = fqv[69];
	if (memq(local[3],w)!=NIL) goto OR232;
	local[3]= local[0];
	if (argv[0]->c.obj.iv[3]==local[3]) goto OR232;
	goto CON231;
OR232:
	local[3]= argv[0];
	local[4]= fqv[41];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto CON228;
CON231:
	local[3]= local[0];
	w = fqv[70];
	if (memq(local[3],w)!=NIL) goto OR234;
	local[3]= local[0];
	local[4]= loadglobal(fqv[43]);
	ctx->vsp=local+5;
	w=(pointer)EQUAL(ctx,2,local+3); /*equal*/
	if (w!=NIL) goto OR234;
	goto CON233;
OR234:
	local[3]= argv[0];
	local[4]= fqv[45];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= fqv[46];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)F64transform_coords(ctx,2,local+3); /*transform-coords*/
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[41];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto CON228;
CON233:
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,1,local+3,&ftab[6],fqv[38]); /*coordinates-p*/
	if (w==NIL) goto CON235;
	local[3]= local[0];
	local[4]= fqv[44];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)F64transform_coords(ctx,2,local+3); /*transform-coords*/
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[45];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= fqv[46];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= local[2];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)F64transform_coords(ctx,3,local+3); /*transform-coords*/
	local[3]= argv[0];
	local[4]= fqv[41];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto CON228;
CON235:
	local[3]= NIL;
CON228:
	w = local[3];
	local[0]= w;
BLK223:
	ctx->vsp=local; return(local[0]);}

/*transform-coords*/
static pointer F64transform_coords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT238;}
	local[0]= argv[0];
	local[1]= fqv[71];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= loadglobal(fqv[72]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[41];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[7])(ctx,1,local+4,&ftab[7],fqv[73]); /*unit-matrix*/
	local[4]= w;
	local[5]= loadglobal(fqv[74]);
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,2,local+5); /*instantiate*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[0]= w;
ENT238:
ENT237:
	if (n>3) maerror();
	local[1]= argv[0];
	if (local[0]!=local[1]) goto IF240;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[1]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)TRANSFORM(ctx,2,local+2); /*transform*/
	local[2]= w;
	local[3]= local[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)VPLUS(ctx,3,local+1); /*v+*/
	local[1]= w;
	goto IF241;
IF240:
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[1]->c.obj.iv[2];
	local[4]= local[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)TRANSFORM(ctx,3,local+2); /*transform*/
	local[2]= w;
	local[3]= local[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)VPLUS(ctx,3,local+1); /*v+*/
	local[1]= w;
IF241:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[1]->c.obj.iv[1];
	local[3]= local[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(*ftab[8])(ctx,3,local+1,&ftab[8],fqv[75]); /*user::rotm3**/
	w = local[0];
	local[0]= w;
BLK236:
	ctx->vsp=local; return(local[0]);}

/*:rotate-vector*/
static pointer M242coordinates_rotate_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT245;}
	local[0]= NIL;
ENT245:
ENT244:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF246;
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)TRANSFORM(ctx,3,local+1); /*transform*/
	local[1]= w;
	goto IF247;
IF246:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)TRANSFORM(ctx,2,local+1); /*transform*/
	local[1]= w;
IF247:
	w = local[1];
	local[0]= w;
BLK243:
	ctx->vsp=local; return(local[0]);}

/*:inverse-rotate-vector*/
static pointer M248coordinates_inverse_rotate_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT251;}
	local[0]= NIL;
ENT251:
ENT250:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF252;
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)TRANSFORM(ctx,3,local+1); /*transform*/
	local[1]= w;
	goto IF253;
IF252:
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)TRANSFORM(ctx,2,local+1); /*transform*/
	local[1]= w;
IF253:
	w = local[1];
	local[0]= w;
BLK249:
	ctx->vsp=local; return(local[0]);}

/*:rotate-vector*/
static pointer M254cascaded_coords_rotate_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT257;}
	local[0]= NIL;
ENT257:
ENT256:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[44];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[7];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK255:
	ctx->vsp=local; return(local[0]);}

/*:inverse-rotate-vector*/
static pointer M258cascaded_coords_inverse_rotate_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT261;}
	local[0]= NIL;
ENT261:
ENT260:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[44];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[76];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK259:
	ctx->vsp=local; return(local[0]);}

/*:inverse-transform-vector*/
static pointer M262coordinates_inverse_transform_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT267;}
	local[0]= NIL;
ENT267:
	if (n>=5) { local[1]=(argv[4]); goto ENT266;}
	local[1]= NIL;
ENT266:
	if (n>=6) { local[2]=(argv[5]); goto ENT265;}
	local[2]= NIL;
ENT265:
ENT264:
	if (n>6) maerror();
	if (local[2]==NIL) goto IF268;
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)TRANSPOSE(ctx,2,local+3); /*transpose*/
	local[3]= w;
	goto IF269;
IF268:
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)TRANSPOSE(ctx,1,local+3); /*transpose*/
	local[3]= w;
IF269:
	if (local[0]==NIL) goto IF270;
	if (local[1]==NIL) goto IF270;
	if (local[2]==NIL) goto IF270;
	local[4]= local[3];
	local[5]= argv[2];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)TRANSFORM(ctx,3,local+4); /*transform*/
	local[4]= w;
	local[5]= local[3];
	local[6]= argv[0]->c.obj.iv[2];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)TRANSFORM(ctx,3,local+5); /*transform*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)VMINUS(ctx,3,local+4); /*v-*/
	local[4]= w;
	goto IF271;
IF270:
	local[4]= local[3];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)TRANSFORM(ctx,2,local+4); /*transform*/
	local[4]= w;
	local[5]= local[3];
	local[6]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+7;
	w=(pointer)TRANSFORM(ctx,2,local+5); /*transform*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)VMINUS(ctx,2,local+4); /*v-*/
	local[4]= w;
IF271:
	w = local[4];
	local[0]= w;
BLK263:
	ctx->vsp=local; return(local[0]);}

/*:inverse-transform-vector*/
static pointer M272cascaded_coords_inverse_transform_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT277;}
	local[0]= NIL;
ENT277:
	if (n>=5) { local[1]=(argv[4]); goto ENT276;}
	local[1]= NIL;
ENT276:
	if (n>=6) { local[2]=(argv[5]); goto ENT275;}
	local[2]= NIL;
ENT275:
ENT274:
	if (n>6) maerror();
	local[3]= argv[0];
	local[4]= fqv[44];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= fqv[15];
	local[5]= argv[2];
	local[6]= local[0];
	local[7]= local[1];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	local[0]= w;
BLK273:
	ctx->vsp=local; return(local[0]);}

/*orient-coords-to-axis*/
static pointer F65orient_coords_to_axis(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT281;}
	local[0]= fqv[12];
ENT281:
	if (n>=4) { local[1]=(argv[3]); goto ENT280;}
	local[1]= loadglobal(fqv[77]);
ENT280:
ENT279:
	if (n>4) maerror();
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(*ftab[4])(ctx,1,local+2,&ftab[4],fqv[26]); /*normalize-vector*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[7];
	local[5]= local[0];
	local[6]= local[5];
	if (fqv[8]!=local[6]) goto IF283;
	local[6]= fqv[78];
	goto IF284;
IF283:
	local[6]= local[5];
	if (fqv[79]!=local[6]) goto IF285;
	local[6]= fqv[80];
	goto IF286;
IF285:
	local[6]= local[5];
	if (fqv[10]!=local[6]) goto IF287;
	local[6]= fqv[81];
	goto IF288;
IF287:
	local[6]= local[5];
	if (fqv[82]!=local[6]) goto IF289;
	local[6]= fqv[83];
	goto IF290;
IF289:
	local[6]= local[5];
	if (fqv[12]!=local[6]) goto IF291;
	local[6]= fqv[84];
	goto IF292;
IF291:
	local[6]= local[5];
	if (fqv[85]!=local[6]) goto IF293;
	local[6]= fqv[86];
	goto IF294;
IF293:
	if (T==NIL) goto IF295;
	local[6]= local[0];
	goto IF296;
IF295:
	local[6]= NIL;
IF296:
IF294:
IF292:
IF290:
IF288:
IF286:
IF284:
	w = local[6];
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= local[3];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+4); /*v**/
	local[4]= w;
	local[5]= local[2];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)VINNERPRODUCT(ctx,2,local+5); /*v.*/
	local[5]= w;
	local[6]= local[5];
	local[7]= makeflt(1.0000000000000000000000e+00);
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(*ftab[9])(ctx,3,local+6,&ftab[9],fqv[87]); /*eps=*/
	if (w==NIL) goto CON298;
	w = argv[0];
	ctx->vsp=local+6;
	local[0]=w;
	goto BLK278;
	goto CON297;
CON298:
	local[6]= local[5];
	local[7]= makeflt(-1.0000000000000000000000e+00);
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(*ftab[9])(ctx,3,local+6,&ftab[9],fqv[87]); /*eps=*/
	if (w==NIL) goto CON299;
	local[6]= NIL;
	local[7]= fqv[88];
	local[8]= fqv[89];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
WHL302:
	if (local[7]==NIL) goto WHX303;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[3];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)VINNERPRODUCT(ctx,2,local+8); /*v.*/
	local[8]= w;
	local[9]= local[8];
	ctx->vsp=local+10;
	w=(pointer)ABS(ctx,1,local+9); /*abs*/
	local[9]= w;
	local[10]= makeflt(1.0000000000000000000000e+00);
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(*ftab[9])(ctx,3,local+9,&ftab[9],fqv[87]); /*eps=*/
	if (w!=NIL) goto IF306;
	local[9]= local[6];
	local[10]= local[8];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)SCALEVEC(ctx,2,local+10); /*scale*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)VMINUS(ctx,2,local+9); /*v-*/
	local[4] = w;
	w = NIL;
	ctx->vsp=local+9;
	local[6]=w;
	goto BLK300;
	goto IF307;
IF306:
	local[9]= NIL;
IF307:
	w = local[9];
	goto WHL302;
WHX303:
	local[8]= NIL;
BLK304:
	w = NIL;
	local[6]= w;
BLK300:
	goto CON297;
CON299:
	local[6]= T;
	if (local[6]!=NIL) goto CON297;
CON308:
	local[6]= NIL;
CON297:
	local[6]= argv[0];
	local[7]= fqv[90];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(*ftab[3])(ctx,1,local+8,&ftab[3],fqv[25]); /*acos*/
	local[8]= w;
	local[9]= local[4];
	local[10]= fqv[91];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,5,local+6); /*send*/
	w = argv[0];
	local[0]= w;
BLK278:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M309bodyset_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST311:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[92], &argv[3], n-3, local+1, 1);
	if (n & (1<<0)) goto KEY312;
	local[3]= NIL;
	local[4]= fqv[93];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)ADDRESS(ctx,1,local+5); /*system:address*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= w;
	local[4]= fqv[94];
	ctx->vsp=local+5;
	w=(pointer)INTERN(ctx,2,local+3); /*intern*/
	local[1] = w;
KEY312:
	if (n & (1<<1)) goto KEY313;
	local[2] = NIL;
KEY313:
	local[3]= (pointer)get_sym_func(fqv[95]);
	local[4]= argv[0];
	local[5]= *(ovafptr(argv[1],fqv[60]));
	local[6]= fqv[96];
	local[7]= fqv[97];
	local[8]= local[1];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)APPLY(ctx,7,local+3); /*apply*/
	local[3]= argv[2];
	local[4]= fqv[98];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	argv[0]->c.obj.iv[8] = local[2];
	if (argv[0]->c.obj.iv[8]==NIL) goto IF314;
	local[3]= argv[0];
	local[4]= fqv[99];
	w=argv[0]->c.obj.iv[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF315;
IF314:
	local[3]= NIL;
IF315:
	local[3]= argv[0];
	local[4]= fqv[44];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	w = argv[0];
	local[0]= w;
BLK310:
	ctx->vsp=local; return(local[0]);}

/*:bodies*/
static pointer M316bodyset_bodies(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST318:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0]->c.obj.iv[8];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[10])(ctx,2,local+1,&ftab[10],fqv[100]); /*user::forward-message-to-all*/
	local[0]= w;
BLK317:
	ctx->vsp=local; return(local[0]);}

/*:faces*/
static pointer M319bodyset_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= fqv[101];
	ctx->vsp=local+2;
	w=(*ftab[11])(ctx,2,local+0,&ftab[11],fqv[102]); /*send-all*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[12])(ctx,1,local+0,&ftab[12],fqv[103]); /*flatten*/
	local[0]= w;
BLK320:
	ctx->vsp=local; return(local[0]);}

/*:worldcoords*/
static pointer M321bodyset_worldcoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[7]==NIL) goto IF323;
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[60]));
	local[2]= fqv[44];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[8];
WHL326:
	if (local[1]==NIL) goto WHX327;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= fqv[44];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	goto WHL326;
WHX327:
	local[2]= NIL;
BLK328:
	w = NIL;
	local[0]= w;
	goto IF324;
IF323:
	local[0]= NIL;
IF324:
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK322:
	ctx->vsp=local; return(local[0]);}

/*:draw-on*/
static pointer M330bodyset_draw_on(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST332:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[8];
WHL334:
	if (local[2]==NIL) goto WHX335;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= (pointer)get_sym_func(fqv[104]);
	local[4]= local[1];
	local[5]= fqv[105];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,4,local+3); /*apply*/
	goto WHL334;
WHX335:
	local[3]= NIL;
BLK336:
	w = NIL;
	local[0]= w;
BLK331:
	ctx->vsp=local; return(local[0]);}

/*face-to-triangle-aux*/
static pointer F66face_to_triangle_aux(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	if (argv[0]!=NIL) goto CON340;
	local[0]= NIL;
	goto CON339;
CON340:
	local[0]= argv[0];
	local[1]= fqv[106];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	if (makeint((eusinteger_t)3L)!=local[0]) goto CON341;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto CON339;
CON341:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F67face_to_triangle(ctx,1,local+0); /*face-to-triangle*/
	local[0]= w;
	goto CON339;
CON342:
	local[0]= NIL;
CON339:
	w = local[0];
	local[0]= w;
BLK338:
	ctx->vsp=local; return(local[0]);}

/*face-to-triangle*/
static pointer F67face_to_triangle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[107]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto IF344;
	local[0]= argv[0];
	local[1]= fqv[108];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	if (w==NIL) goto IF344;
	local[0]= argv[0];
	local[1]= fqv[108];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	if (w==NIL) goto IF346;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F70face_to_triangle_make_simple(ctx,1,local+0); /*face-to-triangle-make-simple*/
	argv[0] = w;
	local[0]= argv[0];
	goto IF347;
IF346:
	local[0]= NIL;
IF347:
	goto IF345;
IF344:
	local[0]= NIL;
IF345:
	local[0]= makeint((eusinteger_t)0L);
	local[1]= argv[0];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F68face_to_tessel_triangle(ctx,2,local+1); /*face-to-tessel-triangle*/
	local[1]= w;
WHL348:
	if (local[1]!=NIL) goto WHX349;
	local[2]= local[0];
	local[3]= argv[0];
	local[4]= fqv[109];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)GREQP(ctx,2,local+2); /*>=*/
	if (w==NIL) goto IF351;
	w = NIL;
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK343;
	goto IF352;
IF351:
	local[2]= NIL;
IF352:
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F68face_to_tessel_triangle(ctx,2,local+2); /*face-to-tessel-triangle*/
	local[1] = w;
	goto WHL348;
WHX349:
	local[2]= NIL;
BLK350:
	local[2]= local[1];
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= local[1];
	local[6]= fqv[106];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)F69face_to_triangle_rest_polygon(ctx,3,local+3); /*face-to-triangle-rest-polygon*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)F66face_to_triangle_aux(ctx,1,local+3); /*face-to-triangle-aux*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[0]= w;
BLK343:
	ctx->vsp=local; return(local[0]);}

/*face-to-tessel-triangle*/
static pointer F68face_to_tessel_triangle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[109];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= argv[1];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SUB1(ctx,1,local+2); /*1-*/
	local[2]= w;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)MOD(ctx,2,local+2); /*mod*/
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)NTH(ctx,2,local+2); /*nth*/
	local[2]= w;
	local[3]= argv[1];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)MOD(ctx,2,local+3); /*mod*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)NTH(ctx,2,local+3); /*nth*/
	local[3]= w;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[4]= w;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)MOD(ctx,2,local+4); /*mod*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)NTH(ctx,2,local+4); /*nth*/
	local[4]= w;
	local[5]= local[3];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)VMINUS(ctx,2,local+5); /*v-*/
	local[5]= w;
	local[6]= local[4];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)VMINUS(ctx,2,local+6); /*v-*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+5); /*v**/
	local[5]= w;
	local[6]= argv[0];
	local[7]= fqv[110];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)VINNERPRODUCT(ctx,2,local+5); /*v.*/
	local[5]= w;
	local[6]= makeint((eusinteger_t)0L);
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w!=NIL) goto IF354;
	w = NIL;
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK353;
	goto IF355;
IF354:
	local[5]= NIL;
IF355:
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO356,env,argv,local);
	local[6]= local[2];
	local[7]= local[3];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,3,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MAPCAR(ctx,2,local+5); /*mapcar*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[13])(ctx,1,local+5,&ftab[13],fqv[111]); /*make-face-from-vertices*/
	local[5]= w;
	local[6]= local[2];
	local[7]= local[3];
	local[8]= local[4];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(*ftab[14])(ctx,2,local+8,&ftab[14],fqv[112]); /*remove*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[14])(ctx,2,local+7,&ftab[14],fqv[112]); /*remove*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[14])(ctx,2,local+6,&ftab[14],fqv[112]); /*remove*/
	local[6]= w;
	local[7]= NIL;
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,CLO358,env,argv,local);
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(*ftab[15])(ctx,2,local+8,&ftab[15],fqv[113]); /*every*/
	local[8]= w;
	if (w==NIL) goto AND357;
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
	w = makeint((eusinteger_t)3L);
	if ((eusinteger_t)local[8] <= (eusinteger_t)w) goto IF359;
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,CLO361,env,argv,local);
	local[9]= loadglobal(fqv[107]);
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,1,local+9); /*instantiate*/
	local[9]= w;
	local[10]= local[9];
	local[11]= fqv[96];
	local[12]= fqv[109];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(pointer)BUTLAST(ctx,1,local+13); /*butlast*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	w = local[9];
	local[9]= w;
	local[10]= fqv[106];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[15])(ctx,2,local+8,&ftab[15],fqv[113]); /*every*/
	local[8]= w;
	goto IF360;
IF359:
	local[8]= T;
IF360:
AND357:
	local[7] = local[8];
	if (local[7]==NIL) goto IF363;
	local[8]= local[5];
	goto IF364;
IF363:
	local[8]= NIL;
IF364:
	w = local[8];
	local[0]= w;
BLK353:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO356(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO365,env,argv,local);
	local[2]= env->c.clo.env1[0];
	local[3]= fqv[106];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAPCAN(ctx,2,local+1); /*mapcan*/
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO365(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= argv[0];
	local[2]= fqv[109];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (memq(local[0],w)==NIL) goto IF366;
	local[0]= loadglobal(fqv[114]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[96];
	local[3]= fqv[115];
	local[4]= argv[0];
	local[5]= fqv[115];
	local[6]= env->c.clo.env0->c.clo.env1[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= fqv[116];
	local[6]= argv[0];
	local[7]= fqv[116];
	local[8]= env->c.clo.env0->c.clo.env1[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	w = local[0];
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF367;
IF366:
	local[0]= NIL;
IF367:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO358(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[117];
	local[1]= env->c.clo.env2[5];
	local[2]= fqv[118];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = ((((w)==(local[0])?T:NIL))==NIL?T:NIL);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO361(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env2[2];
	local[1]= env->c.clo.env2[4];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*make-line*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[120];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= ((local[1])==NIL?T:NIL);
	if (local[2]!=NIL) goto OR369;
	local[2]= local[1];
	local[2]= ((fqv[121])==(local[2])?T:NIL);
	if (local[2]!=NIL) goto OR369;
	local[2]= local[1];
	local[2]= ((fqv[122])==(local[2])?T:NIL);
	if (local[2]!=NIL) goto OR369;
	w = local[1];
	local[2]= (iscons(w)?T:NIL);
	if (local[2]==NIL) goto AND370;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[2]= ((fqv[123])==(local[2])?T:NIL);
	if (local[2]==NIL) goto AND370;
	local[2]= makeflt(0.0000000000000000000000e+00);
	local[3]= local[1];
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	local[4]= makeflt(1.0000000000000000000000e+00);
	local[5]= makeflt(-1.0000000000000000208167e-03);
	ctx->vsp=local+6;
	w=(*ftab[17])(ctx,4,local+2,&ftab[17],fqv[124]); /*eps-in-range*/
	local[2]= ((w)==NIL?T:NIL);
	if (local[2]==NIL) goto AND370;
	local[2]= makeflt(0.0000000000000000000000e+00);
	local[3]= local[1];
	local[4]= makeint((eusinteger_t)2L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	local[4]= makeflt(1.0000000000000000000000e+00);
	local[5]= makeflt(-1.0000000000000000208167e-03);
	ctx->vsp=local+6;
	w=(*ftab[17])(ctx,4,local+2,&ftab[17],fqv[124]); /*eps-in-range*/
	local[2]= ((w)==NIL?T:NIL);
AND370:
OR369:
	w = local[2];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*face-to-triangle-rest-polygon*/
static pointer F69face_to_triangle_rest_polygon(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[109];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)BUTLAST(ctx,1,local+0); /*butlast*/
	local[0]= w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= argv[1];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)MOD(ctx,2,local+2); /*mod*/
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)NTH(ctx,2,local+2); /*nth*/
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[14])(ctx,2,local+2,&ftab[14],fqv[112]); /*remove*/
	local[2]= w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	w = makeint((eusinteger_t)2L);
	if ((eusinteger_t)local[3] > (eusinteger_t)w) goto IF372;
	w = NIL;
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK371;
	goto IF373;
IF372:
	local[3]= NIL;
IF373:
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO374,env,argv,local);
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[13])(ctx,1,local+3,&ftab[13],fqv[111]); /*make-face-from-vertices*/
	local[0]= w;
BLK371:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO374(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO375,env,argv,local);
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO376,env,argv,local);
	local[3]= env->c.clo.env1[0];
	local[4]= fqv[106];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	local[3]= env->c.clo.env1[2];
	ctx->vsp=local+4;
	w=(pointer)APPEND(ctx,2,local+2); /*append*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAPCAN(ctx,2,local+1); /*mapcan*/
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO375(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= argv[0];
	local[2]= fqv[109];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (memq(local[0],w)==NIL) goto IF377;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF378;
IF377:
	local[0]= NIL;
IF378:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO376(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[114]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[96];
	local[3]= fqv[115];
	local[4]= argv[0];
	local[5]= fqv[115];
	local[6]= env->c.clo.env0->c.clo.env1[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= fqv[116];
	local[6]= argv[0];
	local[7]= fqv[116];
	local[8]= env->c.clo.env0->c.clo.env1[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*face-to-triangle-make-simple*/
static pointer F70face_to_triangle_make_simple(ctx,n,argv,env)
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
	local[5]= NIL;
	local[6]= NIL;
WHL381:
	local[7]= argv[0];
	local[8]= fqv[108];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[0] = w;
	if (local[0]==NIL) goto WHX382;
	local[3] = NIL;
	local[7]= NIL;
	local[8]= local[0];
WHL385:
	if (local[8]==NIL) goto WHX386;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= (pointer)get_sym_func(fqv[125]);
	local[10]= argv[0];
	local[11]= fqv[109];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.cdr;
	local[11]= local[7];
	local[12]= fqv[109];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.cdr;
	ctx->vsp=local+12;
	w=(*ftab[18])(ctx,3,local+9,&ftab[18],fqv[126]); /*user::mapjoin*/
	local[2] = w;
	local[9]= NIL;
	local[10]= local[2];
WHL390:
	if (local[10]==NIL) goto WHX391;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	ctx->vsp=local+11;
	local[11]= makeclosure(codevec,quotevec,CLO394,env,argv,local);
	local[12]= local[0];
	local[13]= fqv[106];
	ctx->vsp=local+14;
	w=(*ftab[11])(ctx,2,local+12,&ftab[11],fqv[102]); /*send-all*/
	local[12]= w;
	local[13]= argv[0];
	local[14]= fqv[106];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)APPEND(ctx,2,local+12); /*append*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(*ftab[12])(ctx,1,local+12,&ftab[12],fqv[103]); /*flatten*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)MAPCAN(ctx,2,local+11); /*mapcan*/
	local[6] = w;
	if (local[6]!=NIL) goto IF395;
	if (local[3]==NIL) goto IF397;
	local[11]= local[3];
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.cdr;
	ctx->vsp=local+14;
	w=(pointer)VDISTANCE(ctx,2,local+12); /*distance*/
	local[1] = w;
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)GREATERP(ctx,2,local+11); /*>*/
	if (w==NIL) goto IF399;
	local[3] = local[1];
	local[4] = local[9];
	local[5] = local[7];
	local[11]= local[5];
	goto IF400;
IF399:
	local[11]= NIL;
IF400:
	goto IF398;
IF397:
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.cdr;
	ctx->vsp=local+13;
	w=(pointer)VDISTANCE(ctx,2,local+11); /*distance*/
	local[3] = w;
	local[4] = local[9];
	local[5] = local[7];
	local[11]= local[5];
IF398:
	goto IF396;
IF395:
	local[11]= NIL;
IF396:
	goto WHL390;
WHX391:
	local[11]= NIL;
BLK392:
	w = NIL;
	goto WHL385;
WHX386:
	local[9]= NIL;
BLK387:
	w = NIL;
	if (local[3]==NIL) goto IF401;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= argv[0];
	local[9]= fqv[109];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[19])(ctx,2,local+7,&ftab[19],fqv[127]); /*position*/
	local[7]= w;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.cdr;
	local[9]= local[5];
	local[10]= fqv[109];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[19])(ctx,2,local+8,&ftab[19],fqv[127]); /*position*/
	local[8]= w;
	local[9]= loadglobal(fqv[107]);
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,1,local+9); /*instantiate*/
	local[9]= w;
	local[10]= local[9];
	local[11]= fqv[96];
	local[12]= fqv[109];
	local[13]= argv[0];
	local[14]= fqv[109];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	local[13]= w;
	local[14]= makeint((eusinteger_t)0L);
	local[15]= local[7];
	ctx->vsp=local+16;
	w=(pointer)SUBSEQ(ctx,3,local+13); /*subseq*/
	local[13]= w;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	ctx->vsp=local+15;
	w=(pointer)COPYOBJ(ctx,1,local+14); /*copy-object*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	local[14]= w;
	local[15]= local[5];
	local[16]= fqv[109];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)BUTLAST(ctx,1,local+15); /*butlast*/
	local[15]= w;
	local[16]= local[8];
	ctx->vsp=local+17;
	w=(pointer)SUBSEQ(ctx,2,local+15); /*subseq*/
	local[15]= w;
	local[16]= local[5];
	local[17]= fqv[109];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,2,local+16); /*send*/
	local[16]= w;
	local[17]= makeint((eusinteger_t)0L);
	local[18]= local[8];
	ctx->vsp=local+19;
	w=(pointer)SUBSEQ(ctx,3,local+16); /*subseq*/
	local[16]= w;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17]= (w)->c.cons.cdr;
	ctx->vsp=local+18;
	w=(pointer)COPYOBJ(ctx,1,local+17); /*copy-object*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,1,local+17); /*list*/
	local[17]= w;
	local[18]= argv[0];
	local[19]= fqv[109];
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,2,local+18); /*send*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)BUTLAST(ctx,1,local+18); /*butlast*/
	local[18]= w;
	local[19]= local[7];
	ctx->vsp=local+20;
	w=(pointer)SUBSEQ(ctx,2,local+18); /*subseq*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)NCONC(ctx,6,local+13); /*nconc*/
	local[13]= w;
	local[14]= fqv[108];
	local[15]= local[5];
	local[16]= local[0];
	ctx->vsp=local+17;
	w=(*ftab[14])(ctx,2,local+15,&ftab[14],fqv[112]); /*remove*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,6,local+10); /*send*/
	w = local[9];
	argv[0] = w;
	w = argv[0];
	local[7]= w;
	goto IF402;
IF401:
	local[7]= fqv[128];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(*ftab[20])(ctx,2,local+7,&ftab[20],fqv[129]); /*warn*/
	w = NIL;
	ctx->vsp=local+7;
	local[7]=w;
	goto BLK383;
IF402:
	goto WHL381;
WHX382:
	local[7]= NIL;
BLK383:
	w = argv[0];
	local[0]= w;
BLK380:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO394(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= *(ovafptr(argv[0],fqv[130]));
	local[1]= *(ovafptr(argv[0],fqv[131]));
	w=env->c.clo.env2[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=env->c.clo.env2[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)LINEINTERSECTION3(ctx,4,local+0); /*line-intersection3*/
	local[0]= w;
	local[1]= makeflt(0.0000000000000000000000e+00);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+4;
	w=(pointer)LSEQP(ctx,3,local+1); /*<=*/
	if (w==NIL) goto IF404;
	local[1]= makeflt(0.0000000000000000000000e+00);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,3,local+1); /*<*/
	if (w==NIL) goto IF404;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	goto IF405;
IF404:
	local[1]= NIL;
IF405:
	w = local[1];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*body-to-faces*/
static pointer F71body_to_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= NIL;
	ctx->vsp=local+2;
	w=(pointer)F72body_to_triangles(ctx,2,local+0); /*body-to-triangles*/
	local[0]= w;
BLK406:
	ctx->vsp=local; return(local[0]);}

/*body-to-triangles*/
static pointer F72body_to_triangles(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT409;}
	local[0]= makeint((eusinteger_t)50L);
ENT409:
ENT408:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= NIL;
	storeglobal(fqv[132],local[2]);
	local[2]= NIL;
	storeglobal(fqv[133],local[2]);
	local[2]= NIL;
	local[3]= argv[0];
	local[4]= fqv[101];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
WHL411:
	if (local[3]==NIL) goto WHX412;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[1];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO415,env,argv,local);
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F67face_to_triangle(ctx,1,local+6); /*face-to-triangle*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MAPCAN(ctx,2,local+5); /*mapcan*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)NCONC(ctx,2,local+4); /*nconc*/
	local[1] = w;
	goto WHL411;
WHX412:
	local[4]= NIL;
BLK413:
	w = NIL;
	local[2]= loadglobal(fqv[134]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[96];
	local[5]= fqv[101];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	w = local[2];
	local[0]= w;
BLK407:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO415(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	if (env->c.clo.env2[0]==NIL) goto IF417;
	local[0]= argv[0];
	local[1]= env->c.clo.env2[0];
	ctx->vsp=local+2;
	w=(pointer)F73triangle_to_triangle(ctx,2,local+0); /*triangle-to-triangle*/
	local[0]= w;
	goto IF418;
IF417:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
IF418:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*triangle-to-triangle*/
static pointer F73triangle_to_triangle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT421;}
	local[0]= makeint((eusinteger_t)50L);
ENT421:
ENT420:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= argv[0];
	local[11]= fqv[106];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
WHL423:
	if (local[10]==NIL) goto WHX424;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	local[11]= local[9];
	w = loadglobal(fqv[133]);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	storeglobal(fqv[133],local[11]);
	goto WHL423;
WHX424:
	local[11]= NIL;
BLK425:
	w = NIL;
	ctx->vsp=local+9;
	local[9]= makeclosure(codevec,quotevec,FLET427,env,argv,local);
	local[10]= argv[0];
	local[11]= fqv[106];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	local[11]= makeclosure(codevec,quotevec,CLO428,env,argv,local);
	local[12]= (pointer)get_sym_func(fqv[135]);
	ctx->vsp=local+13;
	w=(*ftab[21])(ctx,3,local+10,&ftab[21],fqv[136]); /*find-extream*/
	local[1] = w;
	if (local[0]==NIL) goto OR431;
	local[10]= local[1];
	local[11]= fqv[137];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)LESSP(ctx,2,local+10); /*<*/
	if (w!=NIL) goto OR431;
	goto IF429;
OR431:
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[0]=w;
	goto BLK419;
	goto IF430;
IF429:
	local[10]= local[1];
	local[11]= fqv[109];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	local[11]= argv[0];
	local[12]= fqv[109];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.cdr;
	local[12]= fqv[138];
	local[13]= (pointer)get_sym_func(fqv[139]);
	ctx->vsp=local+14;
	w=(*ftab[22])(ctx,4,local+10,&ftab[22],fqv[140]); /*set-exclusive-or*/
	local[2] = w;
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)LENGTH(ctx,1,local+10); /*length*/
	local[10]= w;
	if (makeint((eusinteger_t)1L)==local[10]) goto IF432;
	local[10]= fqv[141];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(*ftab[20])(ctx,2,local+10,&ftab[20],fqv[129]); /*warn*/
	local[10]= w;
	goto IF433;
IF432:
	local[10]= NIL;
IF433:
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w = local[9];
	ctx->vsp=local+11;
	w=FLET427(ctx,1,local+10,w);
	local[3] = w;
	local[10]= local[1];
	local[11]= fqv[115];
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	w = local[9];
	ctx->vsp=local+11;
	w=FLET427(ctx,1,local+10,w);
	local[5] = w;
	local[10]= local[1];
	local[11]= fqv[116];
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	w = local[9];
	ctx->vsp=local+11;
	w=FLET427(ctx,1,local+10,w);
	local[6] = w;
	local[10]= local[1];
	local[11]= fqv[142];
	local[12]= makeflt(5.0000000000000000000000e-01);
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[7] = w;
	local[10]= local[7];
	local[11]= loadglobal(fqv[132]);
	local[12]= fqv[138];
	local[13]= (pointer)get_sym_func(fqv[143]);
	ctx->vsp=local+14;
	w=(*ftab[23])(ctx,4,local+10,&ftab[23],fqv[144]); /*member*/
	if (w==NIL) goto IF434;
	local[10]= local[7];
	local[11]= loadglobal(fqv[132]);
	local[12]= fqv[138];
	local[13]= (pointer)get_sym_func(fqv[143]);
	ctx->vsp=local+14;
	w=(*ftab[23])(ctx,4,local+10,&ftab[23],fqv[144]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.car;
	local[10]= local[7];
	goto IF435;
IF434:
	local[10]= NIL;
IF435:
	local[10]= local[7];
	w = loadglobal(fqv[132]);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	storeglobal(fqv[132],local[10]);
	local[10]= local[7];
	w = local[9];
	ctx->vsp=local+11;
	w=FLET427(ctx,1,local+10,w);
	local[4] = w;
	local[10]= local[5];
	local[11]= local[4];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,3,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[13])(ctx,1,local+10,&ftab[13],fqv[111]); /*make-face-from-vertices*/
	local[10]= w;
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)F73triangle_to_triangle(ctx,2,local+10); /*triangle-to-triangle*/
	local[10]= w;
	local[11]= local[6];
	local[12]= local[3];
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,3,local+11); /*list*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,1,local+11,&ftab[13],fqv[111]); /*make-face-from-vertices*/
	local[11]= w;
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)F73triangle_to_triangle(ctx,2,local+11); /*triangle-to-triangle*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)NCONC(ctx,2,local+10); /*nconc*/
	local[10]= w;
IF430:
	w = local[10];
	local[0]= w;
BLK419:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET427(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO436,env,argv,local);
	local[2]= loadglobal(fqv[133]);
	ctx->vsp=local+3;
	w=(pointer)MAPCAN(ctx,2,local+1); /*mapcan*/
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO436(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= argv[0];
	local[2]= fqv[109];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (memq(local[0],w)==NIL) goto IF437;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF438;
IF437:
	local[0]= NIL;
IF438:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO428(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[137];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*make-sphere*/
static pointer F74make_sphere(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST440:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[24])(ctx,1,local+1,&ftab[24],fqv[145]); /*make-icosahedron*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[25])(ctx,1,local+1,&ftab[25],fqv[146]); /*make-gdome*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[41];
	local[4]= (pointer)get_sym_func(fqv[6]);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,2,local+4); /*apply*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= local[1];
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= local[1];
	local[3]= fqv[147];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= fqv[148];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)NCONC(ctx,2,local+2); /*nconc*/
	w = local[1];
	local[0]= w;
BLK439:
	ctx->vsp=local; return(local[0]);}

/*make-ring*/
static pointer F75make_ring(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST442:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[149], &argv[2], n-2, local+1, 0);
	if (n & (1<<0)) goto KEY443;
	local[1] = makeint((eusinteger_t)16L);
KEY443:
	local[2]= NIL;
	local[3]= makeflt(6.2831853071795862319959e+00);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	local[4]= makeint((eusinteger_t)0L);
	local[5]= local[1];
WHL445:
	local[6]= local[4];
	w = local[5];
	if ((eusinteger_t)local[6] >= (eusinteger_t)w) goto WHX446;
	local[6]= argv[1];
	local[7]= local[4];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)COS(ctx,1,local+7); /*cos*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	local[7]= makeint((eusinteger_t)0L);
	local[8]= argv[1];
	local[9]= local[4];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SIN(ctx,1,local+9); /*sin*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,3,local+6); /*float-vector*/
	local[6]= w;
	w = local[2];
	ctx->vsp=local+7;
	local[2] = cons(ctx,local[6],w);
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[4] = w;
	goto WHL445;
WHX446:
	local[6]= NIL;
BLK447:
	w = NIL;
	local[4]= (pointer)get_sym_func(fqv[150]);
	local[5]= local[2];
	local[6]= fqv[151];
	local[7]= local[1];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,5,local+4); /*apply*/
	local[0]= w;
BLK441:
	ctx->vsp=local; return(local[0]);}

/*make-fan-cylinder*/
static pointer F76make_fan_cylinder(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST449:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[152], &argv[2], n-2, local+1, 0);
	if (n & (1<<0)) goto KEY450;
	local[1] = makeint((eusinteger_t)12L);
KEY450:
	if (n & (1<<1)) goto KEY451;
	local[2] = makeflt(6.2831853071795862319959e+00);
KEY451:
	if (n & (1<<2)) goto KEY452;
	local[4]= local[2];
	local[5]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[3] = w;
KEY452:
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO453,env,argv,local);
	local[5]= makeint((eusinteger_t)-1L);
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO454,env,argv,local);
	local[7]= local[1];
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[26])(ctx,1,local+7,&ftab[26],fqv[153]); /*make-list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[4]= w;
	local[5]= local[2];
	local[6]= makeflt(6.2831853071795862319959e+00);
	ctx->vsp=local+7;
	w=(*ftab[9])(ctx,2,local+5,&ftab[9],fqv[87]); /*eps=*/
	if (w==NIL) goto IF455;
	local[5]= local[4];
	ctx->vsp=local+6;
	w=(pointer)REVERSE(ctx,1,local+5); /*reverse*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
	goto IF456;
IF455:
	local[5]= makeint((eusinteger_t)0L);
	local[6]= makeint((eusinteger_t)0L);
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[5]= w;
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)REVERSE(ctx,1,local+6); /*reverse*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
IF456:
	local[6]= argv[1];
	local[7]= fqv[154];
	local[8]= fqv[155];
	local[9]= argv[0];
	local[10]= argv[1];
	local[11]= local[1];
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,5,local+8); /*list*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[27])(ctx,4,local+5,&ftab[27],fqv[156]); /*make-prism*/
	local[0]= w;
BLK448:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO453(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env2[2];
	local[2]= env->c.clo.env2[1];
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= env->c.clo.env2[3];
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	local[0]= w;
	local[1]= env->c.clo.env1[0];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)COS(ctx,1,local+2); /*cos*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	local[2]= env->c.clo.env1[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SIN(ctx,1,local+3); /*sin*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO454(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env2[5];
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	env->c.clo.env2[5] = w;
	w = env->c.clo.env2[5];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*x-of-cube*/
static pointer F77x_of_cube(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[147];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[157];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[28])(ctx,2,local+1,&ftab[28],fqv[158]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK457:
	ctx->vsp=local; return(local[0]);}

/*y-of-cube*/
static pointer F78y_of_cube(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[147];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[157];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[28])(ctx,2,local+1,&ftab[28],fqv[158]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK458:
	ctx->vsp=local; return(local[0]);}

/*z-of-cube*/
static pointer F79z_of_cube(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[147];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[157];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[28])(ctx,2,local+1,&ftab[28],fqv[158]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK459:
	ctx->vsp=local; return(local[0]);}

/*height-of-cylinder*/
static pointer F80height_of_cylinder(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[147];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[155];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[28])(ctx,2,local+1,&ftab[28],fqv[158]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK460:
	ctx->vsp=local; return(local[0]);}

/*radius-of-cylinder*/
static pointer F81radius_of_cylinder(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[147];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[155];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[28])(ctx,2,local+1,&ftab[28],fqv[158]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK461:
	ctx->vsp=local; return(local[0]);}

/*radius-of-sphere*/
static pointer F82radius_of_sphere(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[147];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[148];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[28])(ctx,2,local+1,&ftab[28],fqv[158]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK462:
	ctx->vsp=local; return(local[0]);}

/*make-faceset-from-vertices*/
static pointer F83make_faceset_from_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
WHL464:
	if (argv[0]==NIL) goto WHX465;
	local[1]= argv[0];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= makeint((eusinteger_t)1L);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= makeint((eusinteger_t)2L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)PRINT(ctx,1,local+1); /*print*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[1];
	local[1]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[2];
	local[2]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[3];
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,1,local+1,&ftab[13],fqv[111]); /*make-face-from-vertices*/
	local[1]= w;
	w = local[0];
	ctx->vsp=local+2;
	local[0] = cons(ctx,local[1],w);
	goto WHL464;
WHX465:
	local[1]= NIL;
BLK466:
	local[1]= loadglobal(fqv[134]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[96];
	local[4]= fqv[101];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK463:
	ctx->vsp=local; return(local[0]);}

/*matrix-to-euler-angle*/
static pointer F84matrix_to_euler_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= makeflt(9.9999999999999974298988e-07);
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[29])(ctx,1,local+4,&ftab[29],fqv[159]); /*matrixp*/
	if (w==NIL) goto AND474;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[30])(ctx,1,local+4,&ftab[30],fqv[160]); /*array-dimensions*/
	local[4]= w;
	local[5]= fqv[161];
	ctx->vsp=local+6;
	w=(pointer)EQUAL(ctx,2,local+4); /*equal*/
	if (w==NIL) goto AND474;
	goto IF472;
AND474:
	local[4]= fqv[162];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)SIGERROR(ctx,2,local+4); /*error*/
	local[4]= w;
	goto IF473;
IF472:
	local[4]= NIL;
IF473:
	local[4]= argv[1];
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	local[5]= local[4];
	if (fqv[8]!=local[5]) goto IF476;
	local[5]= argv[1];
	local[6]= makeint((eusinteger_t)2L);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	local[6]= local[5];
	if (fqv[8]!=local[6]) goto IF479;
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[3])(ctx,1,local+6,&ftab[3],fqv[25]); /*acos*/
	local[1] = w;
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= makeflt(1.0000000000000000000000e+00);
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[9])(ctx,3,local+6,&ftab[9],fqv[87]); /*eps=*/
	if (w==NIL) goto CON482;
	local[0] = makeint((eusinteger_t)0L);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)2L);
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)1L);
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[6]= local[2];
	goto CON481;
CON482:
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= makeflt(-1.0000000000000000000000e+00);
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[9])(ctx,3,local+6,&ftab[9],fqv[87]); /*eps=*/
	if (w==NIL) goto CON483;
	local[0] = makeint((eusinteger_t)0L);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)2L);
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)1L);
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,1,local+7); /*-*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[6]= local[2];
	goto CON481;
CON483:
	local[6]= argv[1];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	local[7]= local[6];
	if (fqv[12]!=local[7]) goto IF486;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)2L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	local[8]= argv[0];
	local[9]= makeint((eusinteger_t)1L);
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[31])(ctx,2,local+7,&ftab[31],fqv[163]); /*user::atan2*/
	local[0] = w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,1,local+7); /*-*/
	local[7]= w;
	local[8]= argv[0];
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)1L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[31])(ctx,2,local+7,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[7]= local[2];
	goto IF487;
IF486:
	local[7]= local[6];
	if (fqv[10]!=local[7]) goto IF488;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)1L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,1,local+7); /*-*/
	local[7]= w;
	local[8]= argv[0];
	local[9]= makeint((eusinteger_t)2L);
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[31])(ctx,2,local+7,&ftab[31],fqv[163]); /*user::atan2*/
	local[0] = w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	local[8]= argv[0];
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)2L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[31])(ctx,2,local+7,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[7]= local[2];
	goto IF489;
IF488:
	if (T==NIL) goto IF490;
	local[7]= fqv[164];
	ctx->vsp=local+8;
	w=(pointer)SIGERROR(ctx,1,local+7); /*error*/
	local[7]= w;
	goto IF491;
IF490:
	local[7]= NIL;
IF491:
IF489:
IF487:
	w = local[7];
	local[6]= w;
	goto CON481;
CON484:
	local[6]= NIL;
CON481:
	goto IF480;
IF479:
	local[6]= local[5];
	if (fqv[10]!=local[6]) goto IF492;
	local[6]= argv[1];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	if (fqv[12]==local[6]) goto IF494;
	local[6]= fqv[165];
	ctx->vsp=local+7;
	w=(pointer)SIGERROR(ctx,1,local+6); /*error*/
	local[6]= w;
	goto IF495;
IF494:
	local[6]= NIL;
IF495:
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[32])(ctx,1,local+6,&ftab[32],fqv[166]); /*asin*/
	local[1] = makeflt(-(fltval(w)));
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= makeflt(1.0000000000000000000000e+00);
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[9])(ctx,3,local+6,&ftab[9],fqv[87]); /*eps=*/
	if (w==NIL) goto CON497;
	local[0] = makeint((eusinteger_t)0L);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)1L);
	local[8]= makeint((eusinteger_t)2L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)1L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[6]= local[2];
	goto CON496;
CON497:
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= makeflt(-1.0000000000000000000000e+00);
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[9])(ctx,3,local+6,&ftab[9],fqv[87]); /*eps=*/
	if (w==NIL) goto CON498;
	local[0] = makeint((eusinteger_t)0L);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)1L);
	local[8]= makeint((eusinteger_t)2L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)2L);
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[6]= local[2];
	goto CON496;
CON498:
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)2L);
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)1L);
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[0] = w;
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)2L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[6]= local[2];
	goto CON496;
CON499:
	local[6]= NIL;
CON496:
	goto IF493;
IF492:
	local[6]= local[5];
	if (fqv[12]!=local[6]) goto IF500;
	local[6]= argv[1];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	if (fqv[10]==local[6]) goto IF502;
	local[6]= fqv[167];
	ctx->vsp=local+7;
	w=(pointer)SIGERROR(ctx,1,local+6); /*error*/
	local[6]= w;
	goto IF503;
IF502:
	local[6]= NIL;
IF503:
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)2L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[32])(ctx,1,local+6,&ftab[32],fqv[166]); /*asin*/
	local[1] = w;
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)2L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= makeflt(1.0000000000000000000000e+00);
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[9])(ctx,3,local+6,&ftab[9],fqv[87]); /*eps=*/
	if (w==NIL) goto CON505;
	local[0] = makeint((eusinteger_t)0L);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)1L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)1L);
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[6]= local[2];
	goto CON504;
CON505:
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)2L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= makeflt(-1.0000000000000000000000e+00);
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[9])(ctx,3,local+6,&ftab[9],fqv[87]); /*eps=*/
	if (w==NIL) goto CON506;
	local[0] = makeint((eusinteger_t)0L);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)1L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)2L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[6]= local[2];
	goto CON504;
CON506:
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)1L);
	local[8]= makeint((eusinteger_t)2L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,1,local+6); /*-*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)2L);
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[0] = w;
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,1,local+6); /*-*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[6]= local[2];
	goto CON504;
CON507:
	local[6]= NIL;
CON504:
	goto IF501;
IF500:
	local[6]= NIL;
IF501:
IF493:
IF480:
	w = local[6];
	local[5]= w;
	goto IF477;
IF476:
	local[5]= local[4];
	if (fqv[10]!=local[5]) goto IF508;
	local[5]= argv[1];
	local[6]= makeint((eusinteger_t)2L);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	local[6]= local[5];
	if (fqv[10]!=local[6]) goto IF511;
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)1L);
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[3])(ctx,1,local+6,&ftab[3],fqv[25]); /*acos*/
	local[1] = w;
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)1L);
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= makeflt(1.0000000000000000000000e+00);
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[9])(ctx,3,local+6,&ftab[9],fqv[87]); /*eps=*/
	if (w==NIL) goto CON514;
	local[0] = makeint((eusinteger_t)0L);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)2L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[6]= local[2];
	goto CON513;
CON514:
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)1L);
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= makeflt(-1.0000000000000000000000e+00);
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[9])(ctx,3,local+6,&ftab[9],fqv[87]); /*eps=*/
	if (w==NIL) goto CON515;
	local[0] = makeint((eusinteger_t)0L);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)2L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[6]= local[2];
	goto CON513;
CON515:
	local[6]= argv[1];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	local[7]= local[6];
	if (fqv[8]!=local[7]) goto IF518;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	local[8]= argv[0];
	local[9]= makeint((eusinteger_t)2L);
	local[10]= makeint((eusinteger_t)1L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[31])(ctx,2,local+7,&ftab[31],fqv[163]); /*user::atan2*/
	local[0] = w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)1L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,1,local+7); /*-*/
	local[7]= w;
	local[8]= argv[0];
	local[9]= makeint((eusinteger_t)1L);
	local[10]= makeint((eusinteger_t)2L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[31])(ctx,2,local+7,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[7]= local[2];
	goto IF519;
IF518:
	local[7]= local[6];
	if (fqv[12]!=local[7]) goto IF520;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)2L);
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,1,local+7); /*-*/
	local[7]= w;
	local[8]= argv[0];
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)1L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[31])(ctx,2,local+7,&ftab[31],fqv[163]); /*user::atan2*/
	local[0] = w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)1L);
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	local[8]= argv[0];
	local[9]= makeint((eusinteger_t)1L);
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[31])(ctx,2,local+7,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[7]= local[2];
	goto IF521;
IF520:
	if (T==NIL) goto IF522;
	local[7]= fqv[168];
	ctx->vsp=local+8;
	w=(pointer)SIGERROR(ctx,1,local+7); /*error*/
	local[7]= w;
	goto IF523;
IF522:
	local[7]= NIL;
IF523:
IF521:
IF519:
	w = local[7];
	local[6]= w;
	goto CON513;
CON516:
	local[6]= NIL;
CON513:
	goto IF512;
IF511:
	local[6]= local[5];
	if (fqv[12]!=local[6]) goto IF524;
	local[6]= argv[1];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	if (fqv[8]==local[6]) goto IF526;
	local[6]= fqv[169];
	ctx->vsp=local+7;
	w=(pointer)SIGERROR(ctx,1,local+6); /*error*/
	local[6]= w;
	goto IF527;
IF526:
	local[6]= NIL;
IF527:
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)1L);
	local[8]= makeint((eusinteger_t)2L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[32])(ctx,1,local+6,&ftab[32],fqv[166]); /*asin*/
	local[1] = makeflt(-(fltval(w)));
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)1L);
	local[8]= makeint((eusinteger_t)2L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= makeflt(1.0000000000000000000000e+00);
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[9])(ctx,3,local+6,&ftab[9],fqv[87]); /*eps=*/
	if (w==NIL) goto CON529;
	local[0] = makeint((eusinteger_t)0L);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)2L);
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[6]= local[2];
	goto CON528;
CON529:
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)1L);
	local[8]= makeint((eusinteger_t)2L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= makeflt(-1.0000000000000000000000e+00);
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[9])(ctx,3,local+6,&ftab[9],fqv[87]); /*eps=*/
	if (w==NIL) goto CON530;
	local[0] = makeint((eusinteger_t)0L);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)2L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[6]= local[2];
	goto CON528;
CON530:
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)2L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)2L);
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[0] = w;
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)1L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)1L);
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[6]= local[2];
	goto CON528;
CON531:
	local[6]= NIL;
CON528:
	goto IF525;
IF524:
	local[6]= local[5];
	if (fqv[8]!=local[6]) goto IF532;
	local[6]= argv[1];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	if (fqv[12]==local[6]) goto IF534;
	local[6]= fqv[170];
	ctx->vsp=local+7;
	w=(pointer)SIGERROR(ctx,1,local+6); /*error*/
	local[6]= w;
	goto IF535;
IF534:
	local[6]= NIL;
IF535:
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)1L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[32])(ctx,1,local+6,&ftab[32],fqv[166]); /*asin*/
	local[1] = w;
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)1L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= makeflt(1.0000000000000000000000e+00);
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[9])(ctx,3,local+6,&ftab[9],fqv[87]); /*eps=*/
	if (w==NIL) goto CON537;
	local[0] = makeint((eusinteger_t)0L);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)2L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)2L);
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[6]= local[2];
	goto CON536;
CON537:
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)1L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= makeflt(-1.0000000000000000000000e+00);
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[9])(ctx,3,local+6,&ftab[9],fqv[87]); /*eps=*/
	if (w==NIL) goto CON538;
	local[0] = makeint((eusinteger_t)0L);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)2L);
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)2L);
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[6]= local[2];
	goto CON536;
CON538:
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)2L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,1,local+6); /*-*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[0] = w;
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)1L);
	local[8]= makeint((eusinteger_t)2L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,1,local+6); /*-*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)1L);
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[6]= local[2];
	goto CON536;
CON539:
	local[6]= NIL;
CON536:
	goto IF533;
IF532:
	local[6]= NIL;
IF533:
IF525:
IF512:
	w = local[6];
	local[5]= w;
	goto IF509;
IF508:
	local[5]= local[4];
	if (fqv[12]!=local[5]) goto IF540;
	local[5]= argv[1];
	local[6]= makeint((eusinteger_t)2L);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	local[6]= local[5];
	if (fqv[12]!=local[6]) goto IF543;
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)2L);
	local[8]= makeint((eusinteger_t)2L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[3])(ctx,1,local+6,&ftab[3],fqv[25]); /*acos*/
	local[1] = w;
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)2L);
	local[8]= makeint((eusinteger_t)2L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= makeflt(1.0000000000000000000000e+00);
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[9])(ctx,3,local+6,&ftab[9],fqv[87]); /*eps=*/
	if (w==NIL) goto CON546;
	local[0] = makeint((eusinteger_t)0L);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)1L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[6]= local[2];
	goto CON545;
CON546:
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)2L);
	local[8]= makeint((eusinteger_t)2L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= makeflt(-1.0000000000000000000000e+00);
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[9])(ctx,3,local+6,&ftab[9],fqv[87]); /*eps=*/
	if (w==NIL) goto CON547;
	local[0] = makeint((eusinteger_t)0L);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)1L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)1L);
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[6]= local[2];
	goto CON545;
CON547:
	local[6]= argv[1];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	local[7]= local[6];
	if (fqv[10]!=local[7]) goto IF550;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)1L);
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	local[8]= argv[0];
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)2L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[31])(ctx,2,local+7,&ftab[31],fqv[163]); /*user::atan2*/
	local[0] = w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)2L);
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,1,local+7); /*-*/
	local[7]= w;
	local[8]= argv[0];
	local[9]= makeint((eusinteger_t)2L);
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[31])(ctx,2,local+7,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[7]= local[2];
	goto IF551;
IF550:
	local[7]= local[6];
	if (fqv[8]!=local[7]) goto IF552;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,1,local+7); /*-*/
	local[7]= w;
	local[8]= argv[0];
	local[9]= makeint((eusinteger_t)1L);
	local[10]= makeint((eusinteger_t)2L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[31])(ctx,2,local+7,&ftab[31],fqv[163]); /*user::atan2*/
	local[0] = w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)2L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	local[8]= argv[0];
	local[9]= makeint((eusinteger_t)2L);
	local[10]= makeint((eusinteger_t)1L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[31])(ctx,2,local+7,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[7]= local[2];
	goto IF553;
IF552:
	if (T==NIL) goto IF554;
	local[7]= fqv[171];
	ctx->vsp=local+8;
	w=(pointer)SIGERROR(ctx,1,local+7); /*error*/
	local[7]= w;
	goto IF555;
IF554:
	local[7]= NIL;
IF555:
IF553:
IF551:
	w = local[7];
	local[6]= w;
	goto CON545;
CON548:
	local[6]= NIL;
CON545:
	goto IF544;
IF543:
	local[6]= local[5];
	if (fqv[8]!=local[6]) goto IF556;
	local[6]= argv[1];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	if (fqv[10]==local[6]) goto IF558;
	local[6]= fqv[172];
	ctx->vsp=local+7;
	w=(pointer)SIGERROR(ctx,1,local+6); /*error*/
	local[6]= w;
	goto IF559;
IF558:
	local[6]= NIL;
IF559:
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)2L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[32])(ctx,1,local+6,&ftab[32],fqv[166]); /*asin*/
	local[1] = makeflt(-(fltval(w)));
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)2L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= makeflt(1.0000000000000000000000e+00);
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[9])(ctx,3,local+6,&ftab[9],fqv[87]); /*eps=*/
	if (w==NIL) goto CON561;
	local[0] = makeint((eusinteger_t)0L);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)1L);
	local[8]= makeint((eusinteger_t)2L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[6]= local[2];
	goto CON560;
CON561:
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)2L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= makeflt(-1.0000000000000000000000e+00);
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[9])(ctx,3,local+6,&ftab[9],fqv[87]); /*eps=*/
	if (w==NIL) goto CON562;
	local[0] = makeint((eusinteger_t)0L);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[6]= local[2];
	goto CON560;
CON562:
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)1L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[0] = w;
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)2L);
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)2L);
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[6]= local[2];
	goto CON560;
CON563:
	local[6]= NIL;
CON560:
	goto IF557;
IF556:
	local[6]= local[5];
	if (fqv[10]!=local[6]) goto IF564;
	local[6]= argv[1];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	if (fqv[8]==local[6]) goto IF566;
	local[6]= fqv[173];
	ctx->vsp=local+7;
	w=(pointer)SIGERROR(ctx,1,local+6); /*error*/
	local[6]= w;
	goto IF567;
IF566:
	local[6]= NIL;
IF567:
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)2L);
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[32])(ctx,1,local+6,&ftab[32],fqv[166]); /*asin*/
	local[1] = w;
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)2L);
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= makeflt(1.0000000000000000000000e+00);
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[9])(ctx,3,local+6,&ftab[9],fqv[87]); /*eps=*/
	if (w==NIL) goto CON569;
	local[0] = makeint((eusinteger_t)0L);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)2L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[6]= local[2];
	goto CON568;
CON569:
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)2L);
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= makeflt(-1.0000000000000000000000e+00);
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[9])(ctx,3,local+6,&ftab[9],fqv[87]); /*eps=*/
	if (w==NIL) goto CON570;
	local[0] = makeint((eusinteger_t)0L);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)2L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[6]= local[2];
	goto CON568;
CON570:
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,1,local+6); /*-*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)1L);
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[0] = w;
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)2L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,1,local+6); /*-*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= makeint((eusinteger_t)2L);
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,2,local+6,&ftab[31],fqv[163]); /*user::atan2*/
	local[2] = w;
	local[6]= local[2];
	goto CON568;
CON571:
	local[6]= NIL;
CON568:
	goto IF565;
IF564:
	local[6]= NIL;
IF565:
IF557:
IF544:
	w = local[6];
	local[5]= w;
	goto IF541;
IF540:
	local[5]= NIL;
IF541:
IF509:
IF477:
	w = local[5];
	local[4]= local[0];
	local[5]= local[1];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,3,local+4); /*list*/
	local[0]= w;
BLK471:
	ctx->vsp=local; return(local[0]);}

/*quaternion-from-two-vectors*/
static pointer F85quaternion_from_two_vectors(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[4])(ctx,1,local+0,&ftab[4],fqv[26]); /*normalize-vector*/
	local[0]= w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,1,local+1,&ftab[4],fqv[26]); /*normalize-vector*/
	local[1]= w;
	local[2]= local[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)VINNERPRODUCT(ctx,2,local+2); /*v.*/
	local[2]= w;
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+3); /*v**/
	local[3]= w;
	local[4]= makeint((eusinteger_t)2L);
	local[5]= makeint((eusinteger_t)1L);
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SQRT(ctx,1,local+4); /*sqrt*/
	local[4]= w;
	local[5]= makeflt(1.0000000000000000000000e+00);
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= local[5];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SCALEVEC(ctx,2,local+6); /*scale*/
	local[6]= w;
	local[7]= makeflt(5.0000000000000000000000e-01);
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	local[8]= local[7];
	local[9]= local[6];
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	local[10]= local[6];
	local[11]= makeint((eusinteger_t)1L);
	ctx->vsp=local+12;
	w=(pointer)ELT(ctx,2,local+10); /*elt*/
	local[10]= w;
	local[11]= local[6];
	local[12]= makeint((eusinteger_t)2L);
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)MKFLTVEC(ctx,4,local+8); /*float-vector*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[4])(ctx,1,local+8,&ftab[4],fqv[26]); /*normalize-vector*/
	local[0]= w;
BLK572:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___irtgeo(ctx,n,argv,env)
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
	local[0]= fqv[174];
	ctx->vsp=local+1;
	w=(*ftab[33])(ctx,1,local+0,&ftab[33],fqv[175]); /*require*/
	local[0]= fqv[176];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF573;
	local[0]= fqv[177];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[178],w);
	goto IF574;
IF573:
	local[0]= fqv[179];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF574:
	local[0]= fqv[180];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[181];
	local[1]= fqv[182];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF575;
	local[0]= fqv[181];
	local[1]= fqv[182];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[181];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF577;
	local[0]= fqv[181];
	local[1]= fqv[183];
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeflt(9.8066499999999941792339e+03);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF578;
IF577:
	local[0]= NIL;
IF578:
	local[0]= fqv[181];
	goto IF576;
IF575:
	local[0]= NIL;
IF576:
	ctx->vsp=local+0;
	compfun(ctx,fqv[184],module,F63midcoords,fqv[185]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M87line_worldcoords,fqv[44],fqv[186],fqv[187]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M89coordinates_axis,fqv[24],fqv[72],fqv[188]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M98coordinates_difference_position,fqv[189],fqv[72],fqv[190]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M114coordinates_difference_rotation,fqv[191],fqv[72],fqv[192]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M154coordinates_move_to,fqv[193],fqv[72],fqv[194]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M166coordinates_transformation,fqv[55],fqv[72],fqv[195]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M177coordinates_transform,fqv[54],fqv[72],fqv[196]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M188coordinates_move_coords,fqv[197],fqv[72],fqv[198]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M190cascaded_coords_worldcoords,fqv[44],fqv[199],fqv[200]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M196cascaded_coords_transformation,fqv[55],fqv[199],fqv[201]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M209cascaded_coords_transform,fqv[54],fqv[199],fqv[202]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M222cascaded_coords_move_to,fqv[193],fqv[199],fqv[203]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[204],module,F64transform_coords,fqv[205]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M242coordinates_rotate_vector,fqv[7],fqv[72],fqv[206]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M248coordinates_inverse_rotate_vector,fqv[76],fqv[72],fqv[207]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M254cascaded_coords_rotate_vector,fqv[7],fqv[199],fqv[208]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M258cascaded_coords_inverse_rotate_vector,fqv[76],fqv[199],fqv[209]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M262coordinates_inverse_transform_vector,fqv[15],fqv[72],fqv[210]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M272cascaded_coords_inverse_transform_vector,fqv[15],fqv[199],fqv[211]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[212],module,F65orient_coords_to_axis,fqv[213]);
	local[0]= fqv[214];
	local[1]= fqv[183];
	local[2]= fqv[214];
	local[3]= fqv[215];
	local[4]= loadglobal(fqv[199]);
	local[5]= fqv[216];
	local[6]= fqv[217];
	local[7]= fqv[218];
	local[8]= NIL;
	local[9]= fqv[219];
	local[10]= NIL;
	local[11]= fqv[220];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[221];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[34])(ctx,13,local+2,&ftab[34],fqv[222]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M309bodyset_init,fqv[96],fqv[214],fqv[223]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M316bodyset_bodies,fqv[224],fqv[214],fqv[225]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M319bodyset_faces,fqv[101],fqv[214],fqv[226]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M321bodyset_worldcoords,fqv[44],fqv[214],fqv[227]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M330bodyset_draw_on,fqv[105],fqv[214],fqv[228]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[229],module,F66face_to_triangle_aux,fqv[230]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[231],module,F67face_to_triangle,fqv[232]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[233],module,F68face_to_tessel_triangle,fqv[234]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[235],module,F69face_to_triangle_rest_polygon,fqv[236]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[237],module,F70face_to_triangle_make_simple,fqv[238]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[239],module,F71body_to_faces,fqv[240]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[241],module,F72body_to_triangles,fqv[242]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[243],module,F73triangle_to_triangle,fqv[244]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[245],module,F74make_sphere,fqv[246]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[247],module,F75make_ring,fqv[248]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[249],module,F76make_fan_cylinder,fqv[250]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[251],module,F77x_of_cube,fqv[252]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[253],module,F78y_of_cube,fqv[254]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[255],module,F79z_of_cube,fqv[256]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[257],module,F80height_of_cylinder,fqv[258]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[259],module,F81radius_of_cylinder,fqv[260]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[261],module,F82radius_of_sphere,fqv[262]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[263],module,F83make_faceset_from_vertices,fqv[264]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[265],module,F84matrix_to_euler_angle,fqv[266]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[267],module,F85quaternion_from_two_vectors,fqv[268]);
	local[0]= fqv[269];
	local[1]= fqv[270];
	ctx->vsp=local+2;
	w=(*ftab[35])(ctx,2,local+0,&ftab[35],fqv[271]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<36; i++) ftab[i]=fcallx;
}
