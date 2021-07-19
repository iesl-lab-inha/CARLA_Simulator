/* ./irtbvh.c :  entry=irtbvh */
/* compiled by EusLisp 9.27() for Linux created on ip-10-0-1-214(Fri Apr 16 04:05:26 PST 2021) */
#include "eus.h"
#include "irtbvh.h"
#pragma init (register_irtbvh)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___irtbvh();
extern pointer build_quote_vector();
static int register_irtbvh()
  { add_module_initializer("___irtbvh", ___irtbvh);}

static pointer F4804parse_bvh_sexp();
static pointer F4805read_bvh();
static pointer F4806make_bvh_robot_model();
static pointer F4807bvh2eus();
static pointer F4808load_mcd();
static pointer F4809rikiya_bvh2eus();
static pointer F4810cmu_bvh2eus();
static pointer F4811tum_bvh2eus();
static pointer F4812rikiya_file();
static pointer F4813tum_kitchen_file();
static pointer F4814cmu_mocap_file();

/*:init*/
static pointer M4815bvh_link_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=8) maerror();
	local[0]= makeint((eusinteger_t)30L);
	local[1]= NIL;
	argv[0]->c.obj.iv[29] = argv[3];
	argv[0]->c.obj.iv[30] = argv[4];
	argv[0]->c.obj.iv[31] = argv[5];
	local[2]= local[0];
	local[3]= local[0];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,3,local+2,&ftab[0],fqv[0]); /*make-cube*/
	local[2]= w;
	local[3]= makeflt(9.9999999999999977795540e-02);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	local[4]= makeflt(5.0000000000000000000000e-01);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	local[5]= makeflt(5.0000000000000000000000e-01);
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	local[6]= fqv[1];
	local[7]= makeflt(5.9999999999999964472863e-01);
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,3,local+7); /*float-vector*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[0])(ctx,5,local+3,&ftab[0],fqv[0]); /*make-cube*/
	local[3]= w;
	local[4]= makeflt(5.0000000000000000000000e-01);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	local[5]= makeflt(5.9999999999999964472863e-01);
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[1])(ctx,2,local+4,&ftab[1],fqv[2]); /*make-cylinder*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,3,local+2); /*list*/
	local[1] = w;
	local[2]= NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
WHL4818:
	if (local[3]==NIL) goto WHX4819;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= fqv[3];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	goto WHL4818;
WHX4819:
	local[4]= NIL;
BLK4820:
	w = NIL;
	local[2]= NIL;
	local[3]= argv[7];
WHL4823:
	if (local[3]==NIL) goto WHX4824;
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
	w=(*ftab[2])(ctx,1,local+4,&ftab[2],fqv[4]); /*normalize-vector*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)VMINUS(ctx,1,local+4); /*v-*/
	local[4]= w;
	local[5]= local[0];
	local[6]= makeflt(3.0000000000000000000000e+00);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)VNORM(ctx,1,local+6); /*norm*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,2,local+5,&ftab[1],fqv[2]); /*make-cylinder*/
	local[5]= w;
	local[6]= local[4];
	local[7]= fqv[5];
	ctx->vsp=local+8;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+6); /*v**/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[2])(ctx,1,local+6,&ftab[2],fqv[4]); /*normalize-vector*/
	local[6]= w;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)VNORM(ctx,1,local+9); /*norm*/
	local[9]= w;
	local[10]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+11;
	w=(*ftab[3])(ctx,2,local+9,&ftab[3],fqv[6]); /*eps=*/
	if (w==NIL) goto IF4827;
	local[6] = fqv[7];
	local[9]= local[6];
	goto IF4828;
IF4827:
	local[9]= NIL;
IF4828:
	ctx->vsp=local+9;
	w=(*ftab[4])(ctx,0,local+9,&ftab[4],fqv[8]); /*make-coords*/
	local[9]= w;
	local[10]= fqv[9];
	local[11]= local[4];
	local[12]= fqv[10];
	ctx->vsp=local+13;
	w=(pointer)VINNERPRODUCT(ctx,2,local+11); /*v.*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[5])(ctx,1,local+11,&ftab[5],fqv[11]); /*acos*/
	local[11]= w;
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,4,local+9); /*send*/
	local[9]= w;
	local[10]= fqv[12];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[7] = w;
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)12L);
WHL4830:
	local[11]= local[9];
	w = local[10];
	if ((eusinteger_t)local[11] >= (eusinteger_t)w) goto WHX4831;
	local[11]= local[7];
	local[12]= local[0];
	local[13]= makeint((eusinteger_t)3L);
	ctx->vsp=local+14;
	w=(pointer)QUOTIENT(ctx,2,local+12); /*/*/
	local[12]= w;
	local[13]= makeflt(-6.2831853071795862319959e+00);
	local[14]= local[9];
	local[15]= makeflt(1.2000000000000000000000e+01);
	ctx->vsp=local+16;
	w=(pointer)QUOTIENT(ctx,2,local+14); /*/*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)TIMES(ctx,2,local+13); /***/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SIN(ctx,1,local+13); /*sin*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)TIMES(ctx,2,local+12); /***/
	local[12]= w;
	local[13]= local[0];
	local[14]= makeint((eusinteger_t)3L);
	ctx->vsp=local+15;
	w=(pointer)QUOTIENT(ctx,2,local+13); /*/*/
	local[13]= w;
	local[14]= makeflt(-6.2831853071795862319959e+00);
	local[15]= local[9];
	local[16]= makeflt(1.2000000000000000000000e+01);
	ctx->vsp=local+17;
	w=(pointer)QUOTIENT(ctx,2,local+15); /*/*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)TIMES(ctx,2,local+14); /***/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)COS(ctx,1,local+14); /*cos*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)TIMES(ctx,2,local+13); /***/
	local[13]= w;
	local[14]= makeint((eusinteger_t)0L);
	ctx->vsp=local+15;
	w=(pointer)MKFLTVEC(ctx,3,local+12); /*float-vector*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)TRANSFORM(ctx,2,local+11); /*transform*/
	local[11]= w;
	w = local[8];
	ctx->vsp=local+12;
	local[8] = cons(ctx,local[11],w);
	local[11]= local[9];
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[9] = w;
	goto WHL4830;
WHX4831:
	local[11]= NIL;
BLK4832:
	w = NIL;
	local[9]= local[8];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(*ftab[6])(ctx,2,local+9,&ftab[6],fqv[13]); /*make-prism*/
	local[5] = w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= fqv[3];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= local[1];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)NCONC(ctx,2,local+9); /*nconc*/
	local[1] = w;
	w = local[1];
	goto WHL4823;
WHX4824:
	local[4]= NIL;
BLK4825:
	w = NIL;
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[14]));
	local[4]= fqv[15];
	ctx->vsp=local+5;
	w=(*ftab[7])(ctx,0,local+5,&ftab[7],fqv[16]); /*make-cascoords*/
	local[5]= w;
	local[6]= fqv[17];
	local[7]= local[1];
	local[8]= fqv[18];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)SENDMESSAGE(ctx,8,local+2); /*send-message*/
	local[2]= argv[0]->c.obj.iv[29];
	local[3]= local[2];
	w = fqv[19];
	if (memq(local[3],w)==NIL) goto IF4834;
	local[3]= argv[0];
	local[4]= fqv[17];
	local[5]= fqv[20];
	local[6]= fqv[21];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF4835;
IF4834:
	local[3]= local[2];
	w = fqv[22];
	if (memq(local[3],w)==NIL) goto IF4836;
	local[3]= argv[0];
	local[4]= fqv[17];
	local[5]= fqv[20];
	local[6]= fqv[23];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF4837;
IF4836:
	if (T==NIL) goto IF4838;
	local[3]= argv[0];
	local[4]= fqv[17];
	local[5]= fqv[20];
	local[6]= fqv[24];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF4839;
IF4838:
	local[3]= NIL;
IF4839:
IF4837:
IF4835:
	w = local[3];
	local[2]= argv[0];
	local[3]= fqv[25];
	if (argv[6]==NIL) goto IF4840;
	local[4]= argv[6];
	local[5]= fqv[26];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[30];
	ctx->vsp=local+6;
	w=(pointer)VPLUS(ctx,2,local+4); /*v+*/
	local[4]= w;
	goto IF4841;
IF4840:
	local[4]= argv[0]->c.obj.iv[30];
IF4841:
	local[5]= fqv[27];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	if (argv[6]==NIL) goto IF4842;
	local[2]= argv[6];
	local[3]= fqv[3];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF4843;
IF4842:
	local[2]= NIL;
IF4843:
	local[2]= argv[0];
	local[3]= fqv[28];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	w = argv[0];
	local[0]= w;
BLK4816:
	ctx->vsp=local; return(local[0]);}

/*:type*/
static pointer M4844bvh_link_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[29];
	local[0]= w;
BLK4845:
	ctx->vsp=local; return(local[0]);}

/*:offset*/
static pointer M4846bvh_link_offset(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[30];
	local[0]= w;
BLK4847:
	ctx->vsp=local; return(local[0]);}

/*:channels*/
static pointer M4848bvh_link_channels(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[31];
	local[0]= w;
BLK4849:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M4850bvh_sphere_joint_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST4852:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[29], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY4853;
	local[3]= fqv[30];
	local[4]= fqv[31];
	local[5]= fqv[32];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[1] = w;
KEY4853:
	if (n & (1<<1)) goto KEY4854;
	local[3]= makeint((eusinteger_t)3L);
	ctx->vsp=local+4;
	w=(*ftab[8])(ctx,1,local+3,&ftab[8],fqv[33]); /*unit-matrix*/
	local[2] = w;
KEY4854:
	argv[0]->c.obj.iv[15] = local[1];
	argv[0]->c.obj.iv[16] = local[2];
	local[3]= (pointer)get_sym_func(fqv[34]);
	local[4]= argv[0];
	local[5]= *(ovafptr(argv[1],fqv[14]));
	local[6]= fqv[15];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,5,local+3); /*apply*/
	local[0]= w;
BLK4851:
	ctx->vsp=local; return(local[0]);}

/*:joint-angle-bvh*/
static pointer M4855bvh_sphere_joint_joint_angle_bvh(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4858;}
	local[0]= NIL;
ENT4858:
ENT4857:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[35];
	local[3]= local[0];
	local[4]= makeint((eusinteger_t)3L);
	ctx->vsp=local+5;
	w=(*ftab[8])(ctx,1,local+4,&ftab[8],fqv[33]); /*unit-matrix*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK4856:
	ctx->vsp=local; return(local[0]);}

/*:joint-angle-bvh-offset*/
static pointer M4859bvh_sphere_joint_joint_angle_bvh_offset(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4862;}
	local[0]= NIL;
ENT4862:
ENT4861:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[35];
	local[3]= local[0];
	local[4]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK4860:
	ctx->vsp=local; return(local[0]);}

/*:joint-angle-bvh-impl*/
static pointer M4863bvh_sphere_joint_joint_angle_bvh_impl(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= NIL;
	if (argv[2]==NIL) goto IF4865;
	local[2]= loadglobal(fqv[36]);
	local[3]= (pointer)get_sym_func(fqv[37]);
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)MAP(ctx,3,local+2); /*map*/
	local[0] = w;
	local[2]= local[0];
	local[3]= makeint((eusinteger_t)2L);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[15];
	local[4]= makeint((eusinteger_t)2L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+2); /*rotation-matrix*/
	local[1] = w;
	local[2]= local[1];
	local[3]= local[0];
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[15];
	local[5]= makeint((eusinteger_t)1L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	local[5]= T;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)ROTMAT(ctx,5,local+2); /*rotate-matrix*/
	local[2]= local[1];
	local[3]= local[0];
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[15];
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	local[5]= T;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)ROTMAT(ctx,5,local+2); /*rotate-matrix*/
	local[2]= argv[0];
	local[3]= fqv[38];
	local[4]= loadglobal(fqv[36]);
	local[5]= (pointer)get_sym_func(fqv[39]);
	local[6]= argv[3];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)MATTIMES(ctx,2,local+6); /*m**/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[9])(ctx,1,local+6,&ftab[9],fqv[40]); /*matrix-log*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MAP(ctx,3,local+4); /*map*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF4866;
IF4865:
	local[2]= NIL;
IF4866:
	local[2]= loadglobal(fqv[41]);
	local[3]= (pointer)get_sym_func(fqv[39]);
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)TRANSPOSE(ctx,1,local+4); /*transpose*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[2];
	local[6]= fqv[12];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MATTIMES(ctx,2,local+4); /*m**/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[15];
	ctx->vsp=local+6;
	w=(*ftab[10])(ctx,2,local+4,&ftab[10],fqv[42]); /*matrix-to-euler-angle*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MAP(ctx,3,local+2); /*map*/
	local[0]= w;
BLK4864:
	ctx->vsp=local; return(local[0]);}

/*:axis-order*/
static pointer M4867bvh_sphere_joint_axis_order(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[15];
	local[0]= w;
BLK4868:
	ctx->vsp=local; return(local[0]);}

/*:bvh-offset-rotation*/
static pointer M4869bvh_sphere_joint_bvh_offset_rotation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[16];
	local[0]= w;
BLK4870:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M4871bvh_6dof_joint_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST4873:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[43], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY4874;
	local[4]= fqv[31];
	local[5]= fqv[32];
	local[6]= fqv[30];
	local[7]= fqv[30];
	local[8]= fqv[31];
	local[9]= fqv[32];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,6,local+4); /*list*/
	local[1] = w;
KEY4874:
	if (n & (1<<1)) goto KEY4875;
	local[2] = NIL;
KEY4875:
	if (n & (1<<2)) goto KEY4876;
	local[4]= makeint((eusinteger_t)3L);
	ctx->vsp=local+5;
	w=(*ftab[8])(ctx,1,local+4,&ftab[8],fqv[33]); /*unit-matrix*/
	local[3] = w;
KEY4876:
	argv[0]->c.obj.iv[16] = local[1];
	if (local[2]==NIL) goto IF4877;
	local[4]= local[2];
	goto IF4878;
IF4877:
	local[4]= makeflt(1.0000000000000000000000e+00);
IF4878:
	argv[0]->c.obj.iv[15] = local[4];
	argv[0]->c.obj.iv[17] = local[3];
	local[4]= (pointer)get_sym_func(fqv[34]);
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[14]));
	local[7]= fqv[15];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,5,local+4); /*apply*/
	local[0]= w;
BLK4872:
	ctx->vsp=local; return(local[0]);}

/*:joint-angle-bvh*/
static pointer M4879bvh_6dof_joint_joint_angle_bvh(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4882;}
	local[0]= NIL;
ENT4882:
ENT4881:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[35];
	local[3]= local[0];
	local[4]= makeint((eusinteger_t)3L);
	ctx->vsp=local+5;
	w=(*ftab[8])(ctx,1,local+4,&ftab[8],fqv[33]); /*unit-matrix*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK4880:
	ctx->vsp=local; return(local[0]);}

/*:joint-angle-bvh-offset*/
static pointer M4883bvh_6dof_joint_joint_angle_bvh_offset(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4886;}
	local[0]= NIL;
ENT4886:
ENT4885:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[35];
	local[3]= local[0];
	local[4]= argv[0]->c.obj.iv[17];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK4884:
	ctx->vsp=local; return(local[0]);}

/*:joint-angle-bvh-impl*/
static pointer M4887bvh_6dof_joint_joint_angle_bvh_impl(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	if (argv[2]==NIL) goto IF4889;
	local[3]= loadglobal(fqv[36]);
	local[4]= (pointer)get_sym_func(fqv[37]);
	local[5]= argv[2];
	local[6]= makeint((eusinteger_t)3L);
	local[7]= makeint((eusinteger_t)6L);
	ctx->vsp=local+8;
	w=(pointer)SUBSEQ(ctx,3,local+5); /*subseq*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MAP(ctx,3,local+3); /*map*/
	local[1] = w;
	local[3]= argv[0]->c.obj.iv[15];
	local[4]= argv[2];
	local[5]= makeint((eusinteger_t)0L);
	local[6]= makeint((eusinteger_t)3L);
	ctx->vsp=local+7;
	w=(pointer)SUBSEQ(ctx,3,local+4); /*subseq*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SCALEVEC(ctx,2,local+3); /*scale*/
	local[2] = w;
	local[3]= local[1];
	local[4]= makeint((eusinteger_t)2L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[16];
	local[5]= makeint((eusinteger_t)5L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+3); /*rotation-matrix*/
	local[0] = w;
	local[3]= local[0];
	local[4]= local[1];
	local[5]= makeint((eusinteger_t)1L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[16];
	local[6]= makeint((eusinteger_t)4L);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	local[6]= T;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)ROTMAT(ctx,5,local+3); /*rotate-matrix*/
	local[3]= local[0];
	local[4]= local[1];
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[16];
	local[6]= makeint((eusinteger_t)3L);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	local[6]= T;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)ROTMAT(ctx,5,local+3); /*rotate-matrix*/
	local[3]= argv[0];
	local[4]= fqv[38];
	local[5]= loadglobal(fqv[36]);
	local[6]= argv[3];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)TRANSFORM(ctx,2,local+6); /*transform*/
	local[6]= w;
	local[7]= loadglobal(fqv[41]);
	local[8]= (pointer)get_sym_func(fqv[39]);
	local[9]= argv[0]->c.obj.iv[17];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)MATTIMES(ctx,2,local+9); /*m**/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[9])(ctx,1,local+9,&ftab[9],fqv[40]); /*matrix-log*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MAP(ctx,3,local+7); /*map*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)CONCATENATE(ctx,3,local+5); /*concatenate*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF4890;
IF4889:
	local[3]= NIL;
IF4890:
	local[3]= loadglobal(fqv[41]);
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)TRANSPOSE(ctx,1,local+4); /*transpose*/
	local[4]= w;
	local[5]= makeflt(1.0000000000000000208167e-03);
	local[6]= argv[0]->c.obj.iv[2];
	local[7]= fqv[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SCALEVEC(ctx,2,local+5); /*scale*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)TRANSFORM(ctx,2,local+4); /*transform*/
	local[4]= w;
	local[5]= loadglobal(fqv[41]);
	local[6]= (pointer)get_sym_func(fqv[39]);
	local[7]= argv[3];
	ctx->vsp=local+8;
	w=(pointer)TRANSPOSE(ctx,1,local+7); /*transpose*/
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[2];
	local[9]= fqv[12];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MATTIMES(ctx,2,local+7); /*m**/
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[16];
	local[9]= makeint((eusinteger_t)3L);
	local[10]= makeint((eusinteger_t)6L);
	ctx->vsp=local+11;
	w=(pointer)SUBSEQ(ctx,3,local+8); /*subseq*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[10])(ctx,2,local+7,&ftab[10],fqv[42]); /*matrix-to-euler-angle*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MAP(ctx,3,local+5); /*map*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)CONCATENATE(ctx,3,local+3); /*concatenate*/
	local[0]= w;
BLK4888:
	ctx->vsp=local; return(local[0]);}

/*:axis-order*/
static pointer M4891bvh_6dof_joint_axis_order(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[16];
	local[0]= w;
BLK4892:
	ctx->vsp=local; return(local[0]);}

/*:bvh-offset-rotation*/
static pointer M4893bvh_6dof_joint_bvh_offset_rotation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[17];
	local[0]= w;
BLK4894:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M4895bvh_robot_model_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST4897:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[44], &argv[2], n-2, local+1, 0);
	if (n & (1<<0)) goto KEY4898;
	local[1] = NIL;
KEY4898:
	if (n & (1<<1)) goto KEY4899;
	local[2] = NIL;
KEY4899:
	if (n & (1<<2)) goto KEY4900;
	local[3] = NIL;
KEY4900:
	local[4]= (pointer)get_sym_func(fqv[34]);
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[14]));
	local[7]= fqv[15];
	local[8]= fqv[45];
	ctx->vsp=local+9;
	w=(*ftab[7])(ctx,0,local+9,&ftab[7],fqv[16]); /*make-cascoords*/
	local[9]= w;
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)APPLY(ctx,7,local+4); /*apply*/
	local[4]= argv[0];
	local[5]= fqv[46];
	local[6]= local[1];
	local[7]= fqv[47];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	if (local[2]==NIL) goto IF4901;
	local[4]= argv[0];
	local[5]= fqv[48];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF4902;
IF4901:
	local[4]= NIL;
IF4902:
	local[4]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+5;
	w=(pointer)REVERSE(ctx,1,local+4); /*reverse*/
	argv[0]->c.obj.iv[8] = w;
	local[4]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+5;
	w=(pointer)REVERSE(ctx,1,local+4); /*reverse*/
	argv[0]->c.obj.iv[9] = w;
	local[4]= argv[0];
	local[5]= fqv[49];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	w = argv[0];
	local[0]= w;
BLK4896:
	ctx->vsp=local; return(local[0]);}

/*:make-bvh-link*/
static pointer M4903bvh_robot_model_make_bvh_link(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[50], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY4905;
	local[0] = NIL;
KEY4905:
	if (n & (1<<1)) goto KEY4906;
	local[1] = NIL;
KEY4906:
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	if (local[1]!=NIL) goto IF4910;
	local[1] = makeflt(1.0000000000000000000000e+00);
	local[8]= local[1];
	goto IF4911;
IF4910:
	local[8]= NIL;
IF4911:
	local[8]= loadglobal(fqv[51]);
	ctx->vsp=local+9;
	w=(pointer)INSTANTIATE(ctx,1,local+8); /*instantiate*/
	local[8]= w;
	local[9]= local[8];
	local[10]= fqv[15];
	local[11]= local[3];
	local[12]= local[2];
	local[13]= local[4];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	local[15]= local[0];
	ctx->vsp=local+16;
	local[16]= makeclosure(codevec,quotevec,CLO4913,env,argv,local);
	local[17]= argv[2];
	ctx->vsp=local+18;
	w=(pointer)MAPCAR(ctx,2,local+16); /*mapcar*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,8,local+9); /*send*/
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	w = argv[0]->c.obj.iv[8];
	ctx->vsp=local+9;
	argv[0]->c.obj.iv[8] = cons(ctx,local[8],w);
	local[8]= local[2];
	local[9]= fqv[52];
	ctx->vsp=local+10;
	w=(pointer)EQ(ctx,2,local+8); /*eql*/
	if (w!=NIL) goto IF4914;
	local[8]= NIL;
	local[9]= local[2];
	local[10]= fqv[53];
	ctx->vsp=local+11;
	w=(pointer)EQ(ctx,2,local+9); /*eql*/
	if (w==NIL) goto IF4916;
	local[9]= loadglobal(fqv[54]);
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,1,local+9); /*instantiate*/
	local[9]= w;
	local[10]= local[9];
	local[11]= fqv[15];
	ctx->vsp=local+12;
	w=(*ftab[7])(ctx,0,local+12,&ftab[7],fqv[16]); /*make-cascoords*/
	local[12]= w;
	local[13]= fqv[18];
	local[14]= fqv[55];
	local[15]= fqv[17];
	local[16]= makeint((eusinteger_t)10L);
	local[17]= makeint((eusinteger_t)10L);
	local[18]= makeint((eusinteger_t)10L);
	ctx->vsp=local+19;
	w=(*ftab[0])(ctx,3,local+16,&ftab[0],fqv[0]); /*make-cube*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,7,local+10); /*send*/
	w = local[9];
	local[0] = w;
	local[9]= local[0];
	local[10]= fqv[3];
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= argv[0];
	local[10]= fqv[3];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= w;
	goto IF4917;
IF4916:
	local[9]= NIL;
IF4917:
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= local[9];
	if (fqv[56]!=local[10]) goto IF4920;
	local[8] = loadglobal(fqv[57]);
	local[10]= local[8];
	goto IF4921;
IF4920:
	local[10]= local[9];
	if (fqv[58]!=local[10]) goto IF4922;
	local[8] = loadglobal(fqv[59]);
	local[10]= local[8];
	goto IF4923;
IF4922:
	if (T==NIL) goto IF4924;
	local[10]= makeint((eusinteger_t)1L);
	local[11]= fqv[60];
	local[12]= local[5];
	ctx->vsp=local+13;
	w=(*ftab[11])(ctx,3,local+10,&ftab[11],fqv[61]); /*warning-message*/
	local[10]= w;
	goto IF4925;
IF4924:
	local[10]= NIL;
IF4925:
IF4923:
IF4921:
	w = local[10];
	local[9]= local[8];
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,1,local+9); /*instantiate*/
	local[9]= w;
	local[10]= local[9];
	local[11]= fqv[15];
	local[12]= fqv[18];
	local[13]= local[3];
	local[14]= fqv[62];
	local[15]= local[6];
	local[16]= fqv[63];
	local[17]= local[0];
	local[18]= fqv[64];
	local[19]= argv[0];
	local[20]= fqv[65];
	local[21]= local[3];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,3,local+19); /*send*/
	local[19]= w;
	local[20]= fqv[66];
	ctx->vsp=local+21;
	local[21]= makeclosure(codevec,quotevec,CLO4927,env,argv,local);
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.cdr;
	local[23]= fqv[31];
	w = fqv[67];
	ctx->vsp=local+24;
	local[23]= cons(ctx,local[23],w);
	local[24]= fqv[32];
	w = fqv[68];
	ctx->vsp=local+25;
	local[24]= cons(ctx,local[24],w);
	local[25]= fqv[30];
	w = fqv[69];
	ctx->vsp=local+26;
	local[25]= cons(ctx,local[25],w);
	ctx->vsp=local+26;
	w=(pointer)LIST(ctx,4,local+22); /*list*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(*ftab[12])(ctx,2,local+21,&ftab[12],fqv[70]); /*reduce*/
	local[21]= w;
	local[22]= fqv[47];
	local[23]= local[1];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,14,local+10); /*send*/
	w = local[9];
	local[7] = w;
	local[9]= local[7];
	w = argv[0]->c.obj.iv[9];
	ctx->vsp=local+10;
	argv[0]->c.obj.iv[9] = cons(ctx,local[9],w);
	w = argv[0]->c.obj.iv[9];
	local[8]= w;
	goto IF4915;
IF4914:
	local[8]= NIL;
IF4915:
	local[8]= NIL;
	local[9]= argv[2];
WHL4929:
	if (local[9]==NIL) goto WHX4930;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= argv[0];
	local[11]= fqv[46];
	local[12]= local[8];
	local[13]= fqv[71];
	local[14]= local[6];
	local[15]= fqv[47];
	local[16]= local[1];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,7,local+10); /*send*/
	goto WHL4929;
WHX4930:
	local[10]= NIL;
BLK4931:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK4904:
	ctx->vsp=local; return(local[0]);}

/*:angle-vector*/
static pointer M4933bvh_robot_model_angle_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4937;}
	local[0]= NIL;
ENT4937:
	if (n>=4) { local[1]=(argv[3]); goto ENT4936;}
	local[1]= loadglobal(fqv[36]);
	local[2]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+3;
	w=(*ftab[13])(ctx,1,local+2,&ftab[13],fqv[72]); /*calc-target-joint-dimension*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,2,local+1); /*instantiate*/
	local[1]= w;
ENT4936:
ENT4935:
	if (n>4) maerror();
	local[2]= makeint((eusinteger_t)0L);
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[0]->c.obj.iv[9];
WHL4939:
	if (local[5]==NIL) goto WHX4940;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	if (local[0]==NIL) goto IF4943;
	local[6]= local[4];
	local[7]= fqv[73];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= local[6];
	if (fqv[74]!=local[7]) goto IF4946;
	local[7]= local[4];
	local[8]= fqv[38];
	local[9]= local[0];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	goto IF4947;
IF4946:
	local[7]= local[6];
	if (fqv[75]!=local[7]) goto IF4948;
	local[7]= local[0];
	local[8]= local[2];
	local[9]= local[2];
	local[10]= local[4];
	local[11]= fqv[73];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SUBSEQ(ctx,3,local+7); /*subseq*/
	local[7]= w;
	local[8]= local[4];
	local[9]= fqv[76];
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[7]= w;
	goto IF4949;
IF4948:
	if (T==NIL) goto IF4950;
	local[7]= local[4];
	local[8]= fqv[76];
	local[9]= local[0];
	local[10]= local[2];
	local[11]= local[2];
	local[12]= local[4];
	local[13]= fqv[73];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)SUBSEQ(ctx,3,local+9); /*subseq*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	goto IF4951;
IF4950:
	local[7]= NIL;
IF4951:
IF4949:
IF4947:
	w = local[7];
	local[6]= w;
	goto IF4944;
IF4943:
	local[6]= NIL;
IF4944:
	local[6]= makeint((eusinteger_t)0L);
	local[7]= local[4];
	local[8]= fqv[73];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
WHL4953:
	local[8]= local[6];
	w = local[7];
	if ((eusinteger_t)local[8] >= (eusinteger_t)w) goto WHX4954;
	local[8]= local[1];
	local[9]= local[2];
	local[10]= local[4];
	local[11]= fqv[76];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)ELT(ctx,2,local+10); /*elt*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SETELT(ctx,3,local+8); /*setelt*/
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[2] = w;
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[6] = w;
	goto WHL4953;
WHX4954:
	local[8]= NIL;
BLK4955:
	w = NIL;
	goto WHL4939;
WHX4940:
	local[6]= NIL;
BLK4941:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK4934:
	ctx->vsp=local; return(local[0]);}

/*:dump-joints*/
static pointer M4956bvh_robot_model_dump_joints(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[77], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY4958;
	local[0] = makeint((eusinteger_t)0L);
KEY4958:
	if (n & (1<<1)) goto KEY4959;
	local[1] = loadglobal(fqv[78]);
KEY4959:
	local[2]= local[0];
	local[3]= makeint((eusinteger_t)2L);
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[14])(ctx,1,local+2,&ftab[14],fqv[79]); /*make-string*/
	local[2]= w;
	local[3]= makeint((eusinteger_t)32L);
	ctx->vsp=local+4;
	w=(*ftab[15])(ctx,2,local+2,&ftab[15],fqv[80]); /*fill*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= argv[2];
WHL4961:
	if (local[7]==NIL) goto WHX4962;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	local[9]= fqv[81];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[3] = w;
	local[8]= local[6];
	local[9]= fqv[82];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[4] = w;
	local[8]= local[6];
	local[9]= fqv[83];
	local[10]= fqv[84];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[5] = w;
	local[8]= local[1];
	local[9]= fqv[85];
	local[10]= local[2];
	local[11]= local[6];
	local[12]= fqv[86];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[16])(ctx,1,local+11,&ftab[16],fqv[87]); /*string-upcase*/
	local[11]= w;
	local[12]= local[6];
	local[13]= fqv[83];
	local[14]= fqv[18];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,5,local+8); /*format*/
	local[8]= local[1];
	local[9]= fqv[88];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,3,local+8); /*format*/
	local[8]= local[1];
	local[9]= fqv[89];
	local[10]= local[2];
	local[11]= local[3];
	local[12]= makeint((eusinteger_t)0L);
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	local[12]= local[3];
	local[13]= makeint((eusinteger_t)1L);
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[12]= w;
	local[13]= local[3];
	local[14]= makeint((eusinteger_t)2L);
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,6,local+8); /*format*/
	local[8]= local[1];
	local[9]= fqv[90];
	local[10]= local[2];
	local[11]= local[4];
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,4,local+8); /*format*/
	local[8]= NIL;
	local[9]= local[5];
WHL4966:
	if (local[9]==NIL) goto WHX4967;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= local[8];
	local[11]= local[10];
	if (fqv[31]!=local[11]) goto IF4971;
	local[11]= local[1];
	local[12]= fqv[91];
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,2,local+11); /*format*/
	local[11]= w;
	goto IF4972;
IF4971:
	local[11]= local[10];
	if (fqv[32]!=local[11]) goto IF4973;
	local[11]= local[1];
	local[12]= fqv[92];
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,2,local+11); /*format*/
	local[11]= w;
	goto IF4974;
IF4973:
	local[11]= local[10];
	if (fqv[30]!=local[11]) goto IF4975;
	local[11]= local[1];
	local[12]= fqv[93];
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,2,local+11); /*format*/
	local[11]= w;
	goto IF4976;
IF4975:
	if (T==NIL) goto IF4977;
	local[11]= local[1];
	local[12]= fqv[94];
	local[13]= local[8];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,3,local+11); /*format*/
	local[11]= w;
	goto IF4978;
IF4977:
	local[11]= NIL;
IF4978:
IF4976:
IF4974:
IF4972:
	w = local[11];
	goto WHL4966;
WHX4967:
	local[10]= NIL;
BLK4968:
	w = NIL;
	local[8]= local[1];
	local[9]= fqv[95];
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,2,local+8); /*format*/
	local[8]= local[6];
	local[9]= fqv[96];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	if (w==NIL) goto IF4979;
	local[8]= argv[0];
	local[9]= fqv[97];
	local[10]= local[6];
	local[11]= fqv[96];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)REVERSE(ctx,1,local+10); /*reverse*/
	local[10]= w;
	local[11]= fqv[98];
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)ADD1(ctx,1,local+12); /*1+*/
	local[12]= w;
	local[13]= fqv[99];
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,7,local+8); /*send*/
	local[8]= w;
	goto IF4980;
IF4979:
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,CLO4981,env,argv,local);
	local[9]= local[6];
	local[10]= fqv[100];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[17])(ctx,2,local+8,&ftab[17],fqv[101]); /*find-if*/
	local[8]= w;
	local[9]= local[8];
	local[10]= fqv[81];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	local[10]= local[1];
	local[11]= fqv[102];
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,3,local+10); /*format*/
	local[10]= local[1];
	local[11]= fqv[103];
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,3,local+10); /*format*/
	local[10]= local[1];
	local[11]= fqv[104];
	local[12]= local[2];
	local[13]= local[9];
	local[14]= makeint((eusinteger_t)0L);
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	local[14]= local[9];
	local[15]= makeint((eusinteger_t)1L);
	ctx->vsp=local+16;
	w=(pointer)ELT(ctx,2,local+14); /*elt*/
	local[14]= w;
	local[15]= local[9];
	local[16]= makeint((eusinteger_t)2L);
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)XFORMAT(ctx,6,local+10); /*format*/
	local[10]= local[1];
	local[11]= fqv[105];
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,3,local+10); /*format*/
	local[8]= w;
IF4980:
	local[8]= local[1];
	local[9]= fqv[106];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,3,local+8); /*format*/
	goto WHL4961;
WHX4962:
	local[8]= NIL;
BLK4963:
	w = NIL;
	local[0]= w;
BLK4957:
	ctx->vsp=local; return(local[0]);}

/*:dump-hierarchy*/
static pointer M4982bvh_robot_model_dump_hierarchy(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4985;}
	local[0]= loadglobal(fqv[78]);
ENT4985:
ENT4984:
	if (n>3) maerror();
	local[1]= local[0];
	local[2]= fqv[107];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,2,local+1); /*format*/
	local[1]= argv[0];
	local[2]= fqv[97];
	w=argv[0]->c.obj.iv[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[3]= w;
	local[4]= fqv[99];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= local[0];
	local[2]= fqv[108];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,2,local+1); /*format*/
	local[1]= local[0];
	local[2]= fqv[109];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,2,local+1); /*format*/
	local[1]= local[0];
	local[2]= fqv[110];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,2,local+1); /*format*/
	local[0]= w;
BLK4983:
	ctx->vsp=local; return(local[0]);}

/*:dump-motion*/
static pointer M4986bvh_robot_model_dump_motion(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4989;}
	local[0]= loadglobal(fqv[78]);
ENT4989:
ENT4988:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0]->c.obj.iv[8];
WHL4991:
	if (local[3]==NIL) goto WHX4992;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	local[5]= fqv[83];
	local[6]= fqv[111];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[1] = w;
	local[4]= makeint((eusinteger_t)0L);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
WHL4996:
	local[6]= local[4];
	w = local[5];
	if ((eusinteger_t)local[6] >= (eusinteger_t)w) goto WHX4997;
	local[6]= local[0];
	local[7]= fqv[112];
	local[8]= local[1];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[4] = w;
	goto WHL4996;
WHX4997:
	local[6]= NIL;
BLK4998:
	w = NIL;
	goto WHL4991;
WHX4992:
	local[4]= NIL;
BLK4993:
	w = NIL;
	local[2]= local[0];
	local[3]= fqv[113];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,2,local+2); /*format*/
	local[0]= w;
BLK4987:
	ctx->vsp=local; return(local[0]);}

/*:copy-state-to*/
static pointer M4999bvh_robot_model_copy_state_to(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeint((eusinteger_t)1L);
	local[1]= fqv[114];
	ctx->vsp=local+2;
	w=(*ftab[11])(ctx,2,local+0,&ftab[11],fqv[61]); /*warning-message*/
	local[0]= w;
BLK5000:
	ctx->vsp=local; return(local[0]);}

/*:fix-joint-angle*/
static pointer M5001bvh_robot_model_fix_joint_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=7) maerror();
	w = argv[6];
	local[0]= w;
BLK5002:
	ctx->vsp=local; return(local[0]);}

/*:fix-joint-order*/
static pointer M5003bvh_robot_model_fix_joint_order(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	w = argv[2];
	local[0]= w;
BLK5004:
	ctx->vsp=local; return(local[0]);}

/*:bvh-offset-rotate*/
static pointer M5005bvh_robot_model_bvh_offset_rotate(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeint((eusinteger_t)3L);
	ctx->vsp=local+1;
	w=(*ftab[8])(ctx,1,local+0,&ftab[8],fqv[33]); /*unit-matrix*/
	local[0]= w;
BLK5006:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4913(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[115];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(*ftab[18])(ctx,2,local+0,&ftab[18],fqv[116]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4927(ctx,n,argv,env)
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
	local[1]= (w)->c.cons.cdr;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[19])(ctx,3,local+0,&ftab[19],fqv[117]); /*substitute*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4981(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[51]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*parse-bvh-sexp*/
static pointer F4804parse_bvh_sexp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[118], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY5008;
	local[0] = NIL;
KEY5008:
	if (local[0]!=NIL) goto IF5009;
	local[0] = makeflt(1.0000000000000000000000e+00);
	local[1]= local[0];
	goto IF5010;
IF5009:
	local[1]= NIL;
IF5010:
	w = argv[0];
	if (!!iscons(w)) goto IF5011;
	local[1]= argv[0];
	goto IF5012;
IF5011:
	local[1]= NIL;
	local[2]= NIL;
WHL5013:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	if (local[1]==NIL) goto WHX5014;
	local[3]= local[1];
	local[4]= local[3];
	w = fqv[119];
	if (memq(local[4],w)==NIL) goto IF5018;
	local[4]= local[1];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[5];
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,2,local+4); /*list*/
	local[4]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[5];
	local[5]= w;
	local[6]= fqv[47];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)F4804parse_bvh_sexp(ctx,3,local+5); /*parse-bvh-sexp*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	w = local[2];
	ctx->vsp=local+5;
	local[2] = cons(ctx,local[4],w);
	local[4]= local[2];
	goto IF5019;
IF5018:
	local[4]= local[3];
	if (fqv[115]!=local[4]) goto IF5022;
	local[4]= local[1];
	local[5]= local[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[7];
	local[7]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[8];
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,3,local+6); /*float-vector*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SCALEVEC(ctx,2,local+5); /*scale*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,2,local+4); /*list*/
	local[4]= w;
	w = local[2];
	ctx->vsp=local+5;
	local[2] = cons(ctx,local[4],w);
	local[4]= local[2];
	goto IF5023;
IF5022:
	local[4]= local[3];
	if (fqv[120]!=local[4]) goto IF5027;
	local[4]= local[1];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[5];
	local[5]= w;
	local[6]= local[5];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	local[6]= w;
TAG5032:
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)SUB1(ctx,1,local+7); /*1-*/
	local[5] = w;
	local[7]= local[5];
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto IF5033;
	local[7]= local[6];
	ctx->vsp=local+8;
	w=(pointer)REVERSE(ctx,1,local+7); /*reverse*/
	ctx->vsp=local+7;
	local[5]=w;
	goto BLK5030;
	goto IF5034;
IF5033:
	local[7]= NIL;
IF5034:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[7];
	local[7]= w;
	w = local[6];
	ctx->vsp=local+8;
	local[6] = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	goto TAG5032;
	w = NIL;
	local[5]= w;
BLK5030:
	w = local[5];
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	w = local[2];
	ctx->vsp=local+5;
	local[2] = cons(ctx,local[4],w);
	local[4]= local[2];
	goto IF5028;
IF5027:
	if (T==NIL) goto IF5036;
	w = local[1];
	if (!issymbol(w)) goto IF5038;
	local[4]= local[1];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[5];
	local[5]= w;
	local[6]= fqv[47];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)F4804parse_bvh_sexp(ctx,3,local+5); /*parse-bvh-sexp*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	w = local[2];
	ctx->vsp=local+5;
	local[2] = cons(ctx,local[4],w);
	local[4]= local[2];
	goto IF5039;
IF5038:
	local[4]= local[1];
	w = local[2];
	ctx->vsp=local+5;
	local[2] = cons(ctx,local[4],w);
	local[4]= local[2];
IF5039:
	goto IF5037;
IF5036:
	local[4]= NIL;
IF5037:
IF5028:
IF5023:
IF5019:
	w = local[4];
	goto WHL5013;
WHX5014:
	local[3]= NIL;
BLK5015:
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)REVERSE(ctx,1,local+3); /*reverse*/
	local[1]= w;
IF5012:
	w = local[1];
	local[0]= w;
BLK5007:
	ctx->vsp=local; return(local[0]);}

/*read-bvh*/
static pointer F4805read_bvh(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[121], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY5042;
	local[0] = NIL;
KEY5042:
	ctx->vsp=local+1;
	w=(*ftab[20])(ctx,0,local+1,&ftab[20],fqv[122]); /*copy-readtable*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,0,local+2); /*gensym*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	w = local[1];
	ctx->vsp=local+7;
	bindspecial(ctx,fqv[123],w);
	local[10]= makeint((eusinteger_t)35L);
	local[11]= makeint((eusinteger_t)59L);
	ctx->vsp=local+12;
	w=(*ftab[21])(ctx,2,local+10,&ftab[21],fqv[124]); /*set-syntax-from-char*/
	local[10]= makeint((eusinteger_t)58L);
	local[11]= makeint((eusinteger_t)32L);
	ctx->vsp=local+12;
	w=(*ftab[21])(ctx,2,local+10,&ftab[21],fqv[124]); /*set-syntax-from-char*/
	local[10]= makeint((eusinteger_t)125L);
	local[11]= makeint((eusinteger_t)41L);
	ctx->vsp=local+12;
	w=(*ftab[21])(ctx,2,local+10,&ftab[21],fqv[124]); /*set-syntax-from-char*/
	local[10]= makeint((eusinteger_t)123L);
	ctx->vsp=local+11;
	local[11]= makeclosure(codevec,quotevec,CLO5043,env,argv,local);
	ctx->vsp=local+12;
	w=(pointer)SETMACROCH(ctx,2,local+10); /*set-macro-character*/
	local[10]= argv[0];
	local[11]= fqv[125];
	local[12]= fqv[126];
	ctx->vsp=local+13;
	w=(*ftab[22])(ctx,3,local+10,&ftab[22],fqv[127]); /*open*/
	local[10]= w;
	ctx->vsp=local+11;
	w = makeclosure(codevec,quotevec,UWP5044,env,argv,local);
	local[11]=(pointer)(ctx->protfp); local[12]=w;
	ctx->protfp=(struct protectframe *)(local+11);
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(pointer)READ(ctx,1,local+13); /*read*/
	local[13]= NIL;
TAG5047:
	local[14]= local[13];
	local[15]= local[2];
	ctx->vsp=local+16;
	w=(pointer)EQ(ctx,2,local+14); /*eql*/
	if (w!=NIL) goto OR5050;
	local[14]= local[13];
	local[15]= fqv[128];
	ctx->vsp=local+16;
	w=(pointer)EQ(ctx,2,local+14); /*eql*/
	if (w!=NIL) goto OR5050;
	goto IF5048;
OR5050:
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(pointer)NREVERSE(ctx,1,local+14); /*nreverse*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[3];
	ctx->vsp=local+14;
	local[13]=w;
	goto BLK5046;
	goto IF5049;
IF5048:
	local[14]= NIL;
IF5049:
	local[14]= local[13];
	w = local[3];
	ctx->vsp=local+15;
	local[3] = cons(ctx,local[14],w);
	local[14]= local[10];
	local[15]= NIL;
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)READ(ctx,3,local+14); /*read*/
	local[13] = w;
	ctx->vsp=local+14;
	goto TAG5047;
	w = NIL;
	local[13]= w;
BLK5046:
	local[13]= local[3];
	local[14]= fqv[47];
	local[15]= local[0];
	ctx->vsp=local+16;
	w=(pointer)F4804parse_bvh_sexp(ctx,3,local+13); /*parse-bvh-sexp*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(pointer)READ(ctx,1,local+13); /*read*/
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(pointer)READ(ctx,1,local+13); /*read*/
	local[5] = w;
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(pointer)READ(ctx,1,local+13); /*read*/
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(pointer)READ(ctx,1,local+13); /*read*/
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(pointer)READ(ctx,1,local+13); /*read*/
	local[6] = w;
	local[13]= fqv[129];
	w = local[13];
	ctx->vsp=local+13;
	bindspecial(ctx,fqv[130],w);
TAG5053:
	if (loadglobal(fqv[130])!=NIL) goto IF5054;
	w = NIL;
	ctx->vsp=local+16;
	unwind(ctx,local+13);
	local[13]=w;
	goto BLK5052;
	goto IF5055;
IF5054:
	local[16]= NIL;
IF5055:
	local[16]= NIL;
	local[17]= fqv[131];
	local[18]= loadglobal(fqv[130]);
	ctx->vsp=local+19;
	w=(pointer)XFORMAT(ctx,3,local+16); /*format*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(*ftab[23])(ctx,1,local+16,&ftab[23],fqv[132]); /*read-from-string*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)EVAL(ctx,1,local+16); /*eval*/
	local[16]= w;
	local[17]= local[16];
	ctx->vsp=local+18;
	w=(pointer)LENGTH(ctx,1,local+17); /*length*/
	local[17]= w;
	w = makeint((eusinteger_t)0L);
	if ((eusinteger_t)local[17] <= (eusinteger_t)w) goto IF5056;
	local[17]= local[16];
	w = local[4];
	ctx->vsp=local+18;
	local[4] = cons(ctx,local[17],w);
	local[17]= local[4];
	goto IF5057;
IF5056:
	local[17]= NIL;
IF5057:
	w = local[17];
	local[16]= local[10];
	local[17]= NIL;
	local[18]= NIL;
	ctx->vsp=local+19;
	w=(pointer)READLINE(ctx,3,local+16); /*read-line*/
	local[16]= w;
	storeglobal(fqv[130],w);
	ctx->vsp=local+16;
	goto TAG5053;
	local[16]= NIL;
	ctx->vsp=local+17;
	unbindx(ctx,1);
	w = local[16];
	local[13]= w;
BLK5052:
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)NREVERSE(ctx,1,local+13); /*nreverse*/
	local[4] = w;
	local[13]= makeint((eusinteger_t)2L);
	local[14]= fqv[133];
	local[15]= argv[0];
	ctx->vsp=local+16;
	w=(*ftab[11])(ctx,3,local+13,&ftab[11],fqv[61]); /*warning-message*/
	local[13]= makeint((eusinteger_t)2L);
	local[14]= fqv[134];
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	ctx->vsp=local+16;
	w=(pointer)LENGTH(ctx,1,local+15); /*length*/
	local[15]= w;
	local[16]= local[4];
	ctx->vsp=local+17;
	w=(pointer)LENGTH(ctx,1,local+16); /*length*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(*ftab[11])(ctx,4,local+13,&ftab[11],fqv[61]); /*warning-message*/
	local[13]= fqv[135];
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	local[14]= fqv[136];
	local[15]= fqv[137];
	local[16]= local[5];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	local[15]= cons(ctx,local[15],w);
	local[16]= fqv[138];
	local[17]= local[6];
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,1,local+17); /*list*/
	ctx->vsp=local+17;
	local[16]= cons(ctx,local[16],w);
	local[17]= local[4];
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,1,local+17); /*list*/
	ctx->vsp=local+17;
	w = cons(ctx,local[16],w);
	ctx->vsp=local+16;
	local[15]= cons(ctx,local[15],w);
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	UWP5044(ctx,0,local+13,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[10]= w;
	ctx->vsp=local+11;
	unbindx(ctx,1);
	w = local[10];
	local[0]= w;
BLK5041:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5043(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint((eusinteger_t)125L);
	local[1]= argv[0];
	local[2]= T;
	ctx->vsp=local+3;
	w=(*ftab[24])(ctx,3,local+0,&ftab[24],fqv[139]); /*read-delimited-list*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP5044(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[10];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*make-bvh-robot-model*/
static pointer F4806make_bvh_robot_model(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST5059:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= loadglobal(fqv[140]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= (pointer)get_sym_func(fqv[141]);
	local[3]= local[1];
	local[4]= fqv[15];
	local[5]= fqv[142];
	local[6]= argv[0];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,6,local+2); /*apply*/
	w = local[1];
	local[0]= w;
BLK5058:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M5061motion_capture_data_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[143], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY5063;
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,0,local+2,&ftab[4],fqv[8]); /*make-coords*/
	local[0] = w;
KEY5063:
	if (n & (1<<1)) goto KEY5064;
	local[1] = NIL;
KEY5064:
	local[2]= NIL;
	local[3]= argv[2];
	local[4]= fqv[47];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)F4805read_bvh(ctx,3,local+3); /*read-bvh*/
	local[2] = w;
	local[3]= fqv[135];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(*ftab[18])(ctx,2,local+3,&ftab[18],fqv[116]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= fqv[45];
	local[5]= local[0];
	local[6]= fqv[47];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)F4806make_bvh_robot_model(ctx,5,local+3); /*make-bvh-robot-model*/
	argv[0]->c.obj.iv[2] = w;
	local[3]= fqv[136];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(*ftab[18])(ctx,2,local+3,&ftab[18],fqv[116]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(*ftab[25])(ctx,1,local+3,&ftab[25],fqv[144]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[3] = (w)->c.cons.car;
	argv[0]->c.obj.iv[1] = makeint((eusinteger_t)0L);
	w = argv[0];
	local[0]= w;
BLK5062:
	ctx->vsp=local; return(local[0]);}

/*:model*/
static pointer M5065motion_capture_data_model(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST5067:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[26])(ctx,2,local+1,&ftab[26],fqv[145]); /*forward-message-to*/
	local[0]= w;
BLK5066:
	ctx->vsp=local; return(local[0]);}

/*:animation*/
static pointer M5068motion_capture_data_animation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST5070:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[26])(ctx,2,local+1,&ftab[26],fqv[145]); /*forward-message-to*/
	local[0]= w;
BLK5069:
	ctx->vsp=local; return(local[0]);}

/*:frame*/
static pointer M5071motion_capture_data_frame(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT5074;}
	local[0]= NIL;
ENT5074:
ENT5073:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF5075;
	argv[0]->c.obj.iv[1] = local[0];
	local[1]= argv[0]->c.obj.iv[1];
	goto IF5076;
IF5075:
	local[1]= NIL;
IF5076:
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= makeint((eusinteger_t)0L);
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= fqv[146];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
WHL5078:
	if (local[4]==NIL) goto WHX5079;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3];
	local[6]= fqv[111];
	local[7]= local[1];
	local[8]= local[2];
	local[9]= local[2];
	local[10]= local[3];
	local[11]= fqv[73];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[2] = w;
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)SUBSEQ(ctx,3,local+7); /*subseq*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	goto WHL5078;
WHX5079:
	local[5]= NIL;
BLK5080:
	w = NIL;
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK5072:
	ctx->vsp=local; return(local[0]);}

/*:frame-length*/
static pointer M5082motion_capture_data_frame_length(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
BLK5083:
	ctx->vsp=local; return(local[0]);}

/*:animate*/
static pointer M5084motion_capture_data_animate(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST5086:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[147], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY5087;
	local[1] = makeint((eusinteger_t)0L);
KEY5087:
	if (n & (1<<1)) goto KEY5088;
	local[2] = makeint((eusinteger_t)1L);
KEY5088:
	if (n & (1<<2)) goto KEY5089;
	local[5]= argv[0];
	local[6]= fqv[148];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[3] = w;
KEY5089:
	if (n & (1<<3)) goto KEY5090;
	local[4] = makeint((eusinteger_t)20L);
KEY5090:
	local[5]= argv[0];
	local[6]= fqv[149];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	{jmp_buf jb;
	w = fqv[150];
	ctx->vsp=local+5;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT5091;}
WHL5092:
	if (T==NIL) goto WHX5093;
	local[11]= argv[0];
	local[12]= fqv[149];
	local[13]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[11]= loadglobal(fqv[151]);
	local[12]= fqv[152];
	ctx->vsp=local+13;
	w=(pointer)GETPROP(ctx,2,local+11); /*get*/
	local[11]= w;
	local[12]= fqv[153];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= NIL;
	ctx->vsp=local+12;
	w=(*ftab[27])(ctx,0,local+12,&ftab[27],fqv[154]); /*objects*/
	local[12]= w;
WHL5096:
	if (local[12]==NIL) goto WHX5097;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12] = (w)->c.cons.cdr;
	w = local[13];
	local[11] = w;
	local[13]= local[11];
	local[14]= loadglobal(fqv[140]);
	ctx->vsp=local+15;
	w=(pointer)DERIVEDP(ctx,2,local+13); /*derivedp*/
	if (w!=NIL) goto IF5100;
	local[13]= local[11];
	local[14]= loadglobal(fqv[155]);
	ctx->vsp=local+15;
	w=(pointer)DERIVEDP(ctx,2,local+13); /*derivedp*/
	if (w==NIL) goto IF5100;
	local[13]= argv[0];
	local[14]= fqv[156];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	local[13]= w;
	local[14]= fqv[157];
	local[15]= local[11];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= w;
	goto IF5101;
IF5100:
	local[13]= NIL;
IF5101:
	goto WHL5096;
WHX5097:
	local[13]= NIL;
BLK5098:
	w = NIL;
	local[11]= argv[0]->c.obj.iv[1];
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	argv[0]->c.obj.iv[1] = w;
	local[11]= argv[0]->c.obj.iv[1];
	local[12]= argv[0];
	local[13]= fqv[148];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)GREQP(ctx,2,local+11); /*>=*/
	if (w==NIL) goto IF5102;
	local[11]= fqv[150];
	w = NIL;
	ctx->vsp=local+12;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	goto IF5103;
IF5102:
	local[11]= NIL;
IF5103:
	local[11]= loadglobal(fqv[158]);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	local[11]= w;
	local[12]= makeflt(9.9999999999999969005032e-09);
	ctx->vsp=local+13;
	w=(*ftab[28])(ctx,2,local+11,&ftab[28],fqv[159]); /*select-stream*/
	if (w==NIL) goto IF5104;
	local[11]= fqv[150];
	w = NIL;
	ctx->vsp=local+12;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	goto IF5105;
IF5104:
	local[11]= NIL;
IF5105:
	if (local[4]==NIL) goto IF5106;
	local[11]= makeint((eusinteger_t)1000L);
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[29])(ctx,1,local+11,&ftab[29],fqv[160]); /*unix:usleep*/
	local[11]= w;
	goto IF5107;
IF5106:
	local[11]= NIL;
IF5107:
	ctx->vsp=local+11;
	w=(*ftab[30])(ctx,0,local+11,&ftab[30],fqv[161]); /*x::window-main-one*/
	goto WHL5092;
WHX5093:
	local[11]= NIL;
BLK5094:
	w = local[11];
CAT5091:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[0]= w;
BLK5085:
	ctx->vsp=local; return(local[0]);}

/*bvh2eus*/
static pointer F4807bvh2eus(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST5109:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[162], &argv[1], n-1, local+1, 1);
	if (n & (1<<0)) goto KEY5110;
	local[1] = NIL;
KEY5110:
	local[2]= NIL;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)LISTP(ctx,1,local+3); /*listp*/
	if (w!=NIL) goto IF5111;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[1] = w;
	local[3]= local[1];
	goto IF5112;
IF5111:
	local[3]= NIL;
IF5112:
	local[3]= (pointer)get_sym_func(fqv[163]);
	local[4]= argv[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,3,local+3); /*apply*/
	local[2] = w;
	local[3]= local[2];
	local[4]= fqv[156];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[3]= w;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)APPEND(ctx,2,local+3); /*append*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[27])(ctx,1,local+3,&ftab[27],fqv[154]); /*objects*/
	local[3]= local[2];
	local[4]= fqv[150];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	w = local[2];
	local[0]= w;
BLK5108:
	ctx->vsp=local; return(local[0]);}

/*:init-end-coords*/
static pointer M5113bvh_robot_model_init_end_coords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO5115,env,argv,local);
	local[1]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[101]); /*find-if*/
	argv[0]->c.obj.iv[13] = w;
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO5116,env,argv,local);
	local[1]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[101]); /*find-if*/
	argv[0]->c.obj.iv[14] = w;
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO5117,env,argv,local);
	local[1]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[101]); /*find-if*/
	argv[0]->c.obj.iv[15] = w;
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO5118,env,argv,local);
	local[1]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[101]); /*find-if*/
	argv[0]->c.obj.iv[16] = w;
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO5119,env,argv,local);
	local[1]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[101]); /*find-if*/
	argv[0]->c.obj.iv[18] = w;
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO5120,env,argv,local);
	local[1]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[101]); /*find-if*/
	argv[0]->c.obj.iv[17] = w;
	w = argv[0]->c.obj.iv[17];
	local[0]= w;
BLK5114:
	ctx->vsp=local; return(local[0]);}

/*:init-root-link*/
static pointer M5121bvh_robot_model_init_root_link(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[27];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[19] = (w)->c.cons.car;
	w=argv[0]->c.obj.iv[28];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[20] = (w)->c.cons.car;
	w=argv[0]->c.obj.iv[29];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[21] = (w)->c.cons.car;
	w=argv[0]->c.obj.iv[30];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[22] = (w)->c.cons.car;
	w=argv[0]->c.obj.iv[31];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[24] = (w)->c.cons.car;
	w=argv[0]->c.obj.iv[32];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[23] = (w)->c.cons.car;
	w = argv[0]->c.obj.iv[23];
	local[0]= w;
BLK5122:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5115(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[0]= ((fqv[164])==(local[0])?T:NIL);
	if (local[0]==NIL) goto AND5123;
	local[0]= argv[0];
	local[1]= fqv[71];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= env->c.clo.env1[0]->c.obj.iv[27];
	ctx->vsp=local+2;
	w=(*ftab[25])(ctx,1,local+1,&ftab[25],fqv[144]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (((w)->c.cons.car)==(local[0])?T:NIL);
AND5123:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5116(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[0]= ((fqv[164])==(local[0])?T:NIL);
	if (local[0]==NIL) goto AND5124;
	local[0]= argv[0];
	local[1]= fqv[71];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= env->c.clo.env1[0]->c.obj.iv[28];
	ctx->vsp=local+2;
	w=(*ftab[25])(ctx,1,local+1,&ftab[25],fqv[144]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (((w)->c.cons.car)==(local[0])?T:NIL);
AND5124:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5117(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[0]= ((fqv[164])==(local[0])?T:NIL);
	if (local[0]==NIL) goto AND5125;
	local[0]= argv[0];
	local[1]= fqv[71];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= env->c.clo.env1[0]->c.obj.iv[29];
	ctx->vsp=local+2;
	w=(*ftab[25])(ctx,1,local+1,&ftab[25],fqv[144]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (((w)->c.cons.car)==(local[0])?T:NIL);
AND5125:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5118(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[0]= ((fqv[164])==(local[0])?T:NIL);
	if (local[0]==NIL) goto AND5126;
	local[0]= argv[0];
	local[1]= fqv[71];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= env->c.clo.env1[0]->c.obj.iv[30];
	ctx->vsp=local+2;
	w=(*ftab[25])(ctx,1,local+1,&ftab[25],fqv[144]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (((w)->c.cons.car)==(local[0])?T:NIL);
AND5126:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5119(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[0]= ((fqv[164])==(local[0])?T:NIL);
	if (local[0]==NIL) goto AND5127;
	local[0]= argv[0];
	local[1]= fqv[71];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= env->c.clo.env1[0]->c.obj.iv[31];
	ctx->vsp=local+2;
	w=(*ftab[25])(ctx,1,local+1,&ftab[25],fqv[144]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (((w)->c.cons.car)==(local[0])?T:NIL);
AND5127:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5120(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[0]= ((fqv[164])==(local[0])?T:NIL);
	if (local[0]==NIL) goto AND5128;
	local[0]= argv[0];
	local[1]= fqv[71];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= env->c.clo.env1[0]->c.obj.iv[32];
	ctx->vsp=local+2;
	w=(*ftab[25])(ctx,1,local+1,&ftab[25],fqv[144]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (((w)->c.cons.car)==(local[0])?T:NIL);
AND5128:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M5129rikiya_bvh_robot_model_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST5131:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[34]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[14]));
	local[4]= fqv[15];
	local[5]= fqv[45];
	local[6]= fqv[165];
	local[7]= makeflt(1.5707963267948965579990e+00);
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeflt(1.5707963267948965579990e+00);
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,3,local+7); /*float-vector*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[4])(ctx,2,local+6,&ftab[4],fqv[8]); /*make-coords*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,7,local+1); /*apply*/
	local[1]= fqv[166];
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[167];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO5132,env,argv,local);
	ctx->vsp=local+5;
	w=(*ftab[31])(ctx,4,local+1,&ftab[31],fqv[168]); /*find*/
	local[1]= w;
	local[2]= fqv[169];
	local[3]= argv[0]->c.obj.iv[8];
	local[4]= fqv[167];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO5133,env,argv,local);
	ctx->vsp=local+6;
	w=(*ftab[31])(ctx,4,local+2,&ftab[31],fqv[168]); /*find*/
	local[2]= w;
	local[3]= fqv[170];
	local[4]= argv[0]->c.obj.iv[8];
	local[5]= fqv[167];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO5134,env,argv,local);
	ctx->vsp=local+7;
	w=(*ftab[31])(ctx,4,local+3,&ftab[31],fqv[168]); /*find*/
	local[3]= w;
	local[4]= fqv[171];
	local[5]= argv[0]->c.obj.iv[8];
	local[6]= fqv[167];
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO5135,env,argv,local);
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,4,local+4,&ftab[31],fqv[168]); /*find*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,4,local+1); /*list*/
	argv[0]->c.obj.iv[27] = w;
	local[1]= fqv[172];
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[167];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO5136,env,argv,local);
	ctx->vsp=local+5;
	w=(*ftab[31])(ctx,4,local+1,&ftab[31],fqv[168]); /*find*/
	local[1]= w;
	local[2]= fqv[173];
	local[3]= argv[0]->c.obj.iv[8];
	local[4]= fqv[167];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO5137,env,argv,local);
	ctx->vsp=local+6;
	w=(*ftab[31])(ctx,4,local+2,&ftab[31],fqv[168]); /*find*/
	local[2]= w;
	local[3]= fqv[174];
	local[4]= argv[0]->c.obj.iv[8];
	local[5]= fqv[167];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO5138,env,argv,local);
	ctx->vsp=local+7;
	w=(*ftab[31])(ctx,4,local+3,&ftab[31],fqv[168]); /*find*/
	local[3]= w;
	local[4]= fqv[175];
	local[5]= argv[0]->c.obj.iv[8];
	local[6]= fqv[167];
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO5139,env,argv,local);
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,4,local+4,&ftab[31],fqv[168]); /*find*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,4,local+1); /*list*/
	argv[0]->c.obj.iv[28] = w;
	local[1]= fqv[176];
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[167];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO5140,env,argv,local);
	ctx->vsp=local+5;
	w=(*ftab[31])(ctx,4,local+1,&ftab[31],fqv[168]); /*find*/
	local[1]= w;
	local[2]= fqv[177];
	local[3]= argv[0]->c.obj.iv[8];
	local[4]= fqv[167];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO5141,env,argv,local);
	ctx->vsp=local+6;
	w=(*ftab[31])(ctx,4,local+2,&ftab[31],fqv[168]); /*find*/
	local[2]= w;
	local[3]= fqv[178];
	local[4]= argv[0]->c.obj.iv[8];
	local[5]= fqv[167];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO5142,env,argv,local);
	ctx->vsp=local+7;
	w=(*ftab[31])(ctx,4,local+3,&ftab[31],fqv[168]); /*find*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	argv[0]->c.obj.iv[29] = w;
	local[1]= fqv[179];
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[167];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO5143,env,argv,local);
	ctx->vsp=local+5;
	w=(*ftab[31])(ctx,4,local+1,&ftab[31],fqv[168]); /*find*/
	local[1]= w;
	local[2]= fqv[180];
	local[3]= argv[0]->c.obj.iv[8];
	local[4]= fqv[167];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO5144,env,argv,local);
	ctx->vsp=local+6;
	w=(*ftab[31])(ctx,4,local+2,&ftab[31],fqv[168]); /*find*/
	local[2]= w;
	local[3]= fqv[181];
	local[4]= argv[0]->c.obj.iv[8];
	local[5]= fqv[167];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO5145,env,argv,local);
	ctx->vsp=local+7;
	w=(*ftab[31])(ctx,4,local+3,&ftab[31],fqv[168]); /*find*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	argv[0]->c.obj.iv[30] = w;
	local[1]= fqv[182];
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[167];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO5146,env,argv,local);
	ctx->vsp=local+5;
	w=(*ftab[31])(ctx,4,local+1,&ftab[31],fqv[168]); /*find*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	argv[0]->c.obj.iv[31] = w;
	local[1]= fqv[183];
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[167];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO5147,env,argv,local);
	ctx->vsp=local+5;
	w=(*ftab[31])(ctx,4,local+1,&ftab[31],fqv[168]); /*find*/
	local[1]= w;
	local[2]= fqv[184];
	local[3]= argv[0]->c.obj.iv[8];
	local[4]= fqv[167];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO5148,env,argv,local);
	ctx->vsp=local+6;
	w=(*ftab[31])(ctx,4,local+2,&ftab[31],fqv[168]); /*find*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	argv[0]->c.obj.iv[32] = w;
	local[1]= argv[0];
	local[2]= fqv[185];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[186];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = argv[0];
	local[0]= w;
BLK5130:
	ctx->vsp=local; return(local[0]);}

/*:larm-collar*/
static pointer M5149rikiya_bvh_robot_model_larm_collar(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST5151:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0]->c.obj.iv[27];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[26])(ctx,2,local+1,&ftab[26],fqv[145]); /*forward-message-to*/
	local[0]= w;
BLK5150:
	ctx->vsp=local; return(local[0]);}

/*:larm-shoulder*/
static pointer M5152rikiya_bvh_robot_model_larm_shoulder(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST5154:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0]->c.obj.iv[27];
	local[2]= makeint((eusinteger_t)1L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[26])(ctx,2,local+1,&ftab[26],fqv[145]); /*forward-message-to*/
	local[0]= w;
BLK5153:
	ctx->vsp=local; return(local[0]);}

/*:larm-elbow*/
static pointer M5155rikiya_bvh_robot_model_larm_elbow(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST5157:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0]->c.obj.iv[27];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[26])(ctx,2,local+1,&ftab[26],fqv[145]); /*forward-message-to*/
	local[0]= w;
BLK5156:
	ctx->vsp=local; return(local[0]);}

/*:larm-wrist*/
static pointer M5158rikiya_bvh_robot_model_larm_wrist(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST5160:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0]->c.obj.iv[27];
	local[2]= makeint((eusinteger_t)3L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[26])(ctx,2,local+1,&ftab[26],fqv[145]); /*forward-message-to*/
	local[0]= w;
BLK5159:
	ctx->vsp=local; return(local[0]);}

/*:rarm-collar*/
static pointer M5161rikiya_bvh_robot_model_rarm_collar(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST5163:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0]->c.obj.iv[28];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[26])(ctx,2,local+1,&ftab[26],fqv[145]); /*forward-message-to*/
	local[0]= w;
BLK5162:
	ctx->vsp=local; return(local[0]);}

/*:rarm-shoulder*/
static pointer M5164rikiya_bvh_robot_model_rarm_shoulder(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST5166:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0]->c.obj.iv[28];
	local[2]= makeint((eusinteger_t)1L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[26])(ctx,2,local+1,&ftab[26],fqv[145]); /*forward-message-to*/
	local[0]= w;
BLK5165:
	ctx->vsp=local; return(local[0]);}

/*:rarm-elbow*/
static pointer M5167rikiya_bvh_robot_model_rarm_elbow(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST5169:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0]->c.obj.iv[28];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[26])(ctx,2,local+1,&ftab[26],fqv[145]); /*forward-message-to*/
	local[0]= w;
BLK5168:
	ctx->vsp=local; return(local[0]);}

/*:rarm-wrist*/
static pointer M5170rikiya_bvh_robot_model_rarm_wrist(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST5172:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0]->c.obj.iv[28];
	local[2]= makeint((eusinteger_t)3L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[26])(ctx,2,local+1,&ftab[26],fqv[145]); /*forward-message-to*/
	local[0]= w;
BLK5171:
	ctx->vsp=local; return(local[0]);}

/*:lleg-crotch*/
static pointer M5173rikiya_bvh_robot_model_lleg_crotch(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST5175:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0]->c.obj.iv[29];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[26])(ctx,2,local+1,&ftab[26],fqv[145]); /*forward-message-to*/
	local[0]= w;
BLK5174:
	ctx->vsp=local; return(local[0]);}

/*:lleg-knee*/
static pointer M5176rikiya_bvh_robot_model_lleg_knee(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST5178:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0]->c.obj.iv[29];
	local[2]= makeint((eusinteger_t)1L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[26])(ctx,2,local+1,&ftab[26],fqv[145]); /*forward-message-to*/
	local[0]= w;
BLK5177:
	ctx->vsp=local; return(local[0]);}

/*:lleg-ankle*/
static pointer M5179rikiya_bvh_robot_model_lleg_ankle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST5181:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0]->c.obj.iv[29];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[26])(ctx,2,local+1,&ftab[26],fqv[145]); /*forward-message-to*/
	local[0]= w;
BLK5180:
	ctx->vsp=local; return(local[0]);}

/*:rleg-crotch*/
static pointer M5182rikiya_bvh_robot_model_rleg_crotch(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST5184:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0]->c.obj.iv[30];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[26])(ctx,2,local+1,&ftab[26],fqv[145]); /*forward-message-to*/
	local[0]= w;
BLK5183:
	ctx->vsp=local; return(local[0]);}

/*:rleg-knee*/
static pointer M5185rikiya_bvh_robot_model_rleg_knee(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST5187:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0]->c.obj.iv[30];
	local[2]= makeint((eusinteger_t)1L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[26])(ctx,2,local+1,&ftab[26],fqv[145]); /*forward-message-to*/
	local[0]= w;
BLK5186:
	ctx->vsp=local; return(local[0]);}

/*:rleg-ankle*/
static pointer M5188rikiya_bvh_robot_model_rleg_ankle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST5190:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0]->c.obj.iv[30];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[26])(ctx,2,local+1,&ftab[26],fqv[145]); /*forward-message-to*/
	local[0]= w;
BLK5189:
	ctx->vsp=local; return(local[0]);}

/*:torso-chest*/
static pointer M5191rikiya_bvh_robot_model_torso_chest(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST5193:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0]->c.obj.iv[31];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[26])(ctx,2,local+1,&ftab[26],fqv[145]); /*forward-message-to*/
	local[0]= w;
BLK5192:
	ctx->vsp=local; return(local[0]);}

/*:head-neck*/
static pointer M5194rikiya_bvh_robot_model_head_neck(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST5196:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0]->c.obj.iv[32];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[26])(ctx,2,local+1,&ftab[26],fqv[145]); /*forward-message-to*/
	local[0]= w;
BLK5195:
	ctx->vsp=local; return(local[0]);}

/*:copy-joint-to*/
static pointer M5197rikiya_bvh_robot_model_copy_joint_to(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	w = argv[4];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[187],w);
	if (n>=6) { local[3]=(argv[5]); goto ENT5200;}
	local[3]= makeint((eusinteger_t)1L);
ENT5200:
ENT5199:
	if (n>6) maerror();
	local[4]= argv[2];
	local[5]= NIL;
	local[6]= fqv[188];
	local[7]= argv[3];
	ctx->vsp=local+8;
	w=(*ftab[32])(ctx,1,local+7,&ftab[32],fqv[189]); /*symbol-name*/
	local[7]= w;
	local[8]= loadglobal(fqv[187]);
	ctx->vsp=local+9;
	w=(*ftab[32])(ctx,1,local+8,&ftab[32],fqv[189]); /*symbol-name*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,4,local+5); /*format*/
	local[5]= w;
	local[6]= fqv[190];
	ctx->vsp=local+7;
	w=(pointer)INTERN(ctx,2,local+5); /*intern*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[33])(ctx,2,local+4,&ftab[33],fqv[191]); /*find-method*/
	if (w==NIL) goto IF5201;
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= NIL;
	local[7]= fqv[192];
	local[8]= loadglobal(fqv[187]);
	ctx->vsp=local+9;
	w=(*ftab[32])(ctx,1,local+8,&ftab[32],fqv[189]); /*symbol-name*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	local[7]= fqv[193];
	ctx->vsp=local+8;
	w=(pointer)INTERN(ctx,2,local+6); /*intern*/
	local[6]= w;
	local[7]= fqv[38];
	local[8]= local[3];
	local[9]= argv[0];
	local[10]= argv[3];
	local[11]= loadglobal(fqv[187]);
	local[12]= fqv[83];
	local[13]= fqv[38];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,5,local+9); /*send*/
	local[9]= w;
	local[10]= makeint((eusinteger_t)2L);
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[4]= w;
	goto IF5202;
IF5201:
	local[4]= NIL;
IF5202:
	local[4]= argv[2];
	local[5]= NIL;
	local[6]= fqv[194];
	local[7]= argv[3];
	ctx->vsp=local+8;
	w=(*ftab[32])(ctx,1,local+7,&ftab[32],fqv[189]); /*symbol-name*/
	local[7]= w;
	local[8]= loadglobal(fqv[187]);
	ctx->vsp=local+9;
	w=(*ftab[32])(ctx,1,local+8,&ftab[32],fqv[189]); /*symbol-name*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,4,local+5); /*format*/
	local[5]= w;
	local[6]= fqv[195];
	ctx->vsp=local+7;
	w=(pointer)INTERN(ctx,2,local+5); /*intern*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[33])(ctx,2,local+4,&ftab[33],fqv[191]); /*find-method*/
	if (w==NIL) goto IF5203;
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= NIL;
	local[7]= fqv[196];
	local[8]= loadglobal(fqv[187]);
	ctx->vsp=local+9;
	w=(*ftab[32])(ctx,1,local+8,&ftab[32],fqv[189]); /*symbol-name*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	local[7]= fqv[197];
	ctx->vsp=local+8;
	w=(pointer)INTERN(ctx,2,local+6); /*intern*/
	local[6]= w;
	local[7]= fqv[38];
	local[8]= argv[0];
	local[9]= argv[3];
	local[10]= loadglobal(fqv[187]);
	local[11]= fqv[83];
	local[12]= fqv[38];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,5,local+8); /*send*/
	local[8]= w;
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[4]= w;
	goto IF5204;
IF5203:
	local[4]= NIL;
IF5204:
	local[4]= argv[2];
	local[5]= NIL;
	local[6]= fqv[198];
	local[7]= argv[3];
	ctx->vsp=local+8;
	w=(*ftab[32])(ctx,1,local+7,&ftab[32],fqv[189]); /*symbol-name*/
	local[7]= w;
	local[8]= loadglobal(fqv[187]);
	ctx->vsp=local+9;
	w=(*ftab[32])(ctx,1,local+8,&ftab[32],fqv[189]); /*symbol-name*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,4,local+5); /*format*/
	local[5]= w;
	local[6]= fqv[199];
	ctx->vsp=local+7;
	w=(pointer)INTERN(ctx,2,local+5); /*intern*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[33])(ctx,2,local+4,&ftab[33],fqv[191]); /*find-method*/
	if (w==NIL) goto IF5205;
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= NIL;
	local[7]= fqv[200];
	local[8]= loadglobal(fqv[187]);
	ctx->vsp=local+9;
	w=(*ftab[32])(ctx,1,local+8,&ftab[32],fqv[189]); /*symbol-name*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	local[7]= fqv[201];
	ctx->vsp=local+8;
	w=(pointer)INTERN(ctx,2,local+6); /*intern*/
	local[6]= w;
	local[7]= fqv[38];
	local[8]= local[3];
	local[9]= argv[0];
	local[10]= argv[3];
	local[11]= loadglobal(fqv[187]);
	local[12]= fqv[83];
	local[13]= fqv[38];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,5,local+9); /*send*/
	local[9]= w;
	local[10]= makeint((eusinteger_t)1L);
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[4]= w;
	goto IF5206;
IF5205:
	local[4]= NIL;
IF5206:
	ctx->vsp=local+5;
	unbindx(ctx,1);
	w = local[4];
	local[0]= w;
BLK5198:
	ctx->vsp=local; return(local[0]);}

/*:copy-state-to*/
static pointer M5207rikiya_bvh_robot_model_copy_state_to(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= fqv[202];
WHL5210:
	if (local[2]==NIL) goto WHX5211;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= NIL;
	local[4]= fqv[203];
	w = local[3];
	ctx->vsp=local+5;
	bindspecial(ctx,fqv[187],w);
WHL5215:
	if (local[4]==NIL) goto WHX5216;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[8];
	local[8]= w;
	storeglobal(fqv[187],w);
	local[8]= fqv[204];
	ctx->vsp=local+9;
	w=(pointer)BOUNDP(ctx,1,local+8); /*boundp*/
	if (w==NIL) goto IF5219;
	local[8]= argv[2];
	local[9]= loadglobal(fqv[204]);
	ctx->vsp=local+10;
	w=(pointer)DERIVEDP(ctx,2,local+8); /*derivedp*/
	if (w==NIL) goto IF5219;
	local[8]= argv[0];
	local[9]= fqv[205];
	local[10]= argv[2];
	local[11]= local[1];
	local[12]= loadglobal(fqv[187]);
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,5,local+8); /*send*/
	local[8]= w;
	goto IF5220;
IF5219:
	local[8]= argv[0];
	local[9]= fqv[205];
	local[10]= argv[2];
	local[11]= local[1];
	local[12]= loadglobal(fqv[187]);
	local[13]= local[1];
	local[14]= local[13];
	if (fqv[206]!=local[14]) goto IF5222;
	local[14]= makeint((eusinteger_t)-1L);
	goto IF5223;
IF5222:
	if (T==NIL) goto IF5224;
	local[14]= makeint((eusinteger_t)1L);
	goto IF5225;
IF5224:
	local[14]= NIL;
IF5225:
IF5223:
	w = local[14];
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,6,local+8); /*send*/
	local[8]= w;
IF5220:
	goto WHL5215;
WHX5216:
	local[8]= NIL;
BLK5217:
	local[8]= NIL;
	ctx->vsp=local+9;
	unbindx(ctx,1);
	w = local[8];
	goto WHL5210;
WHX5211:
	local[3]= NIL;
BLK5212:
	w = NIL;
	local[1]= NIL;
	local[2]= fqv[207];
WHL5227:
	if (local[2]==NIL) goto WHX5228;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= NIL;
	local[4]= fqv[208];
	w = local[3];
	ctx->vsp=local+5;
	bindspecial(ctx,fqv[187],w);
WHL5232:
	if (local[4]==NIL) goto WHX5233;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[8];
	local[8]= w;
	storeglobal(fqv[187],w);
	local[8]= fqv[204];
	ctx->vsp=local+9;
	w=(pointer)BOUNDP(ctx,1,local+8); /*boundp*/
	if (w==NIL) goto IF5236;
	local[8]= argv[2];
	local[9]= loadglobal(fqv[204]);
	ctx->vsp=local+10;
	w=(pointer)DERIVEDP(ctx,2,local+8); /*derivedp*/
	if (w==NIL) goto IF5236;
	local[8]= argv[0];
	local[9]= fqv[205];
	local[10]= argv[2];
	local[11]= local[1];
	local[12]= loadglobal(fqv[187]);
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,5,local+8); /*send*/
	local[8]= w;
	goto IF5237;
IF5236:
	local[8]= argv[0];
	local[9]= fqv[205];
	local[10]= argv[2];
	local[11]= local[1];
	local[12]= loadglobal(fqv[187]);
	local[13]= local[1];
	local[14]= local[13];
	if (fqv[209]!=local[14]) goto IF5239;
	local[14]= makeint((eusinteger_t)-1L);
	goto IF5240;
IF5239:
	if (T==NIL) goto IF5241;
	local[14]= makeint((eusinteger_t)1L);
	goto IF5242;
IF5241:
	local[14]= NIL;
IF5242:
IF5240:
	w = local[14];
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,6,local+8); /*send*/
	local[8]= w;
IF5237:
	goto WHL5232;
WHX5233:
	local[8]= NIL;
BLK5234:
	local[8]= NIL;
	ctx->vsp=local+9;
	unbindx(ctx,1);
	w = local[8];
	goto WHL5227;
WHX5228:
	local[3]= NIL;
BLK5229:
	w = NIL;
	local[1]= argv[0];
	local[2]= fqv[205];
	local[3]= argv[2];
	local[4]= fqv[210];
	local[5]= fqv[211];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[205];
	local[3]= argv[2];
	local[4]= fqv[212];
	local[5]= fqv[213];
	local[6]= makeint((eusinteger_t)-1L);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[2];
	local[2]= fqv[214];
	local[3]= argv[0];
	local[4]= fqv[215];
	w=argv[0]->c.obj.iv[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= fqv[27];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK5208:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5132(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5133(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5134(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5135(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5136(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5137(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5138(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5139(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5140(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5141(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5142(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5143(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5144(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5145(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5146(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5147(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5148(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M5243tum_bvh_robot_model_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST5245:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[34]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[14]));
	local[4]= fqv[15];
	local[5]= fqv[45];
	local[6]= fqv[165];
	local[7]= makeflt(1.5707963267948965579990e+00);
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,3,local+7); /*float-vector*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[4])(ctx,2,local+6,&ftab[4],fqv[8]); /*make-coords*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,7,local+1); /*apply*/
	local[1]= fqv[216];
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[167];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO5246,env,argv,local);
	ctx->vsp=local+5;
	w=(*ftab[31])(ctx,4,local+1,&ftab[31],fqv[168]); /*find*/
	local[1]= w;
	local[2]= fqv[217];
	local[3]= argv[0]->c.obj.iv[8];
	local[4]= fqv[167];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO5247,env,argv,local);
	ctx->vsp=local+6;
	w=(*ftab[31])(ctx,4,local+2,&ftab[31],fqv[168]); /*find*/
	local[2]= w;
	local[3]= fqv[218];
	local[4]= argv[0]->c.obj.iv[8];
	local[5]= fqv[167];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO5248,env,argv,local);
	ctx->vsp=local+7;
	w=(*ftab[31])(ctx,4,local+3,&ftab[31],fqv[168]); /*find*/
	local[3]= w;
	local[4]= fqv[219];
	local[5]= argv[0]->c.obj.iv[8];
	local[6]= fqv[167];
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO5249,env,argv,local);
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,4,local+4,&ftab[31],fqv[168]); /*find*/
	local[4]= w;
	local[5]= fqv[220];
	local[6]= argv[0]->c.obj.iv[8];
	local[7]= fqv[167];
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,CLO5250,env,argv,local);
	ctx->vsp=local+9;
	w=(*ftab[31])(ctx,4,local+5,&ftab[31],fqv[168]); /*find*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,5,local+1); /*list*/
	argv[0]->c.obj.iv[27] = w;
	local[1]= fqv[221];
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[167];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO5251,env,argv,local);
	ctx->vsp=local+5;
	w=(*ftab[31])(ctx,4,local+1,&ftab[31],fqv[168]); /*find*/
	local[1]= w;
	local[2]= fqv[222];
	local[3]= argv[0]->c.obj.iv[8];
	local[4]= fqv[167];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO5252,env,argv,local);
	ctx->vsp=local+6;
	w=(*ftab[31])(ctx,4,local+2,&ftab[31],fqv[168]); /*find*/
	local[2]= w;
	local[3]= fqv[223];
	local[4]= argv[0]->c.obj.iv[8];
	local[5]= fqv[167];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO5253,env,argv,local);
	ctx->vsp=local+7;
	w=(*ftab[31])(ctx,4,local+3,&ftab[31],fqv[168]); /*find*/
	local[3]= w;
	local[4]= fqv[224];
	local[5]= argv[0]->c.obj.iv[8];
	local[6]= fqv[167];
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO5254,env,argv,local);
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,4,local+4,&ftab[31],fqv[168]); /*find*/
	local[4]= w;
	local[5]= fqv[225];
	local[6]= argv[0]->c.obj.iv[8];
	local[7]= fqv[167];
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,CLO5255,env,argv,local);
	ctx->vsp=local+9;
	w=(*ftab[31])(ctx,4,local+5,&ftab[31],fqv[168]); /*find*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,5,local+1); /*list*/
	argv[0]->c.obj.iv[28] = w;
	local[1]= fqv[226];
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[167];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO5256,env,argv,local);
	ctx->vsp=local+5;
	w=(*ftab[31])(ctx,4,local+1,&ftab[31],fqv[168]); /*find*/
	local[1]= w;
	local[2]= fqv[227];
	local[3]= argv[0]->c.obj.iv[8];
	local[4]= fqv[167];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO5257,env,argv,local);
	ctx->vsp=local+6;
	w=(*ftab[31])(ctx,4,local+2,&ftab[31],fqv[168]); /*find*/
	local[2]= w;
	local[3]= fqv[228];
	local[4]= argv[0]->c.obj.iv[8];
	local[5]= fqv[167];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO5258,env,argv,local);
	ctx->vsp=local+7;
	w=(*ftab[31])(ctx,4,local+3,&ftab[31],fqv[168]); /*find*/
	local[3]= w;
	local[4]= fqv[229];
	local[5]= argv[0]->c.obj.iv[8];
	local[6]= fqv[167];
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO5259,env,argv,local);
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,4,local+4,&ftab[31],fqv[168]); /*find*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,4,local+1); /*list*/
	argv[0]->c.obj.iv[29] = w;
	local[1]= fqv[230];
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[167];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO5260,env,argv,local);
	ctx->vsp=local+5;
	w=(*ftab[31])(ctx,4,local+1,&ftab[31],fqv[168]); /*find*/
	local[1]= w;
	local[2]= fqv[231];
	local[3]= argv[0]->c.obj.iv[8];
	local[4]= fqv[167];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO5261,env,argv,local);
	ctx->vsp=local+6;
	w=(*ftab[31])(ctx,4,local+2,&ftab[31],fqv[168]); /*find*/
	local[2]= w;
	local[3]= fqv[232];
	local[4]= argv[0]->c.obj.iv[8];
	local[5]= fqv[167];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO5262,env,argv,local);
	ctx->vsp=local+7;
	w=(*ftab[31])(ctx,4,local+3,&ftab[31],fqv[168]); /*find*/
	local[3]= w;
	local[4]= fqv[233];
	local[5]= argv[0]->c.obj.iv[8];
	local[6]= fqv[167];
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO5263,env,argv,local);
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,4,local+4,&ftab[31],fqv[168]); /*find*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,4,local+1); /*list*/
	argv[0]->c.obj.iv[30] = w;
	local[1]= fqv[234];
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[167];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO5264,env,argv,local);
	ctx->vsp=local+5;
	w=(*ftab[31])(ctx,4,local+1,&ftab[31],fqv[168]); /*find*/
	local[1]= w;
	local[2]= fqv[235];
	local[3]= argv[0]->c.obj.iv[8];
	local[4]= fqv[167];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO5265,env,argv,local);
	ctx->vsp=local+6;
	w=(*ftab[31])(ctx,4,local+2,&ftab[31],fqv[168]); /*find*/
	local[2]= w;
	local[3]= fqv[236];
	local[4]= argv[0]->c.obj.iv[8];
	local[5]= fqv[167];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO5266,env,argv,local);
	ctx->vsp=local+7;
	w=(*ftab[31])(ctx,4,local+3,&ftab[31],fqv[168]); /*find*/
	local[3]= w;
	local[4]= fqv[237];
	local[5]= argv[0]->c.obj.iv[8];
	local[6]= fqv[167];
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO5267,env,argv,local);
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,4,local+4,&ftab[31],fqv[168]); /*find*/
	local[4]= w;
	local[5]= fqv[238];
	local[6]= argv[0]->c.obj.iv[8];
	local[7]= fqv[167];
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,CLO5268,env,argv,local);
	ctx->vsp=local+9;
	w=(*ftab[31])(ctx,4,local+5,&ftab[31],fqv[168]); /*find*/
	local[5]= w;
	local[6]= fqv[239];
	local[7]= argv[0]->c.obj.iv[8];
	local[8]= fqv[167];
	ctx->vsp=local+9;
	local[9]= makeclosure(codevec,quotevec,CLO5269,env,argv,local);
	ctx->vsp=local+10;
	w=(*ftab[31])(ctx,4,local+6,&ftab[31],fqv[168]); /*find*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,6,local+1); /*list*/
	argv[0]->c.obj.iv[31] = w;
	local[1]= fqv[240];
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[167];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO5270,env,argv,local);
	ctx->vsp=local+5;
	w=(*ftab[31])(ctx,4,local+1,&ftab[31],fqv[168]); /*find*/
	local[1]= w;
	local[2]= fqv[241];
	local[3]= argv[0]->c.obj.iv[8];
	local[4]= fqv[167];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO5271,env,argv,local);
	ctx->vsp=local+6;
	w=(*ftab[31])(ctx,4,local+2,&ftab[31],fqv[168]); /*find*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	argv[0]->c.obj.iv[32] = w;
	local[1]= argv[0];
	local[2]= fqv[185];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[186];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = argv[0];
	local[0]= w;
BLK5244:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5246(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5247(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5248(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5249(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5250(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5251(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5252(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5253(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5254(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5255(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5256(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5257(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5258(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5259(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5260(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5261(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5262(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5263(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5264(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5265(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5266(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5267(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5268(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5269(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5270(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5271(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M5272cmu_bvh_robot_model_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST5274:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[34]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[14]));
	local[4]= fqv[15];
	local[5]= fqv[45];
	local[6]= fqv[165];
	local[7]= makeflt(1.5707963267948965579990e+00);
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeflt(1.5707963267948965579990e+00);
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,3,local+7); /*float-vector*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[4])(ctx,2,local+6,&ftab[4],fqv[8]); /*make-coords*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,7,local+1); /*apply*/
	local[1]= fqv[169];
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[167];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO5275,env,argv,local);
	ctx->vsp=local+5;
	w=(*ftab[31])(ctx,4,local+1,&ftab[31],fqv[168]); /*find*/
	local[1]= w;
	local[2]= fqv[242];
	local[3]= argv[0]->c.obj.iv[8];
	local[4]= fqv[167];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO5276,env,argv,local);
	ctx->vsp=local+6;
	w=(*ftab[31])(ctx,4,local+2,&ftab[31],fqv[168]); /*find*/
	local[2]= w;
	local[3]= fqv[243];
	local[4]= argv[0]->c.obj.iv[8];
	local[5]= fqv[167];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO5277,env,argv,local);
	ctx->vsp=local+7;
	w=(*ftab[31])(ctx,4,local+3,&ftab[31],fqv[168]); /*find*/
	local[3]= w;
	local[4]= fqv[244];
	local[5]= argv[0]->c.obj.iv[8];
	local[6]= fqv[167];
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO5278,env,argv,local);
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,4,local+4,&ftab[31],fqv[168]); /*find*/
	local[4]= w;
	local[5]= fqv[245];
	local[6]= argv[0]->c.obj.iv[8];
	local[7]= fqv[167];
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,CLO5279,env,argv,local);
	ctx->vsp=local+9;
	w=(*ftab[31])(ctx,4,local+5,&ftab[31],fqv[168]); /*find*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,5,local+1); /*list*/
	argv[0]->c.obj.iv[27] = w;
	local[1]= fqv[173];
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[167];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO5280,env,argv,local);
	ctx->vsp=local+5;
	w=(*ftab[31])(ctx,4,local+1,&ftab[31],fqv[168]); /*find*/
	local[1]= w;
	local[2]= fqv[246];
	local[3]= argv[0]->c.obj.iv[8];
	local[4]= fqv[167];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO5281,env,argv,local);
	ctx->vsp=local+6;
	w=(*ftab[31])(ctx,4,local+2,&ftab[31],fqv[168]); /*find*/
	local[2]= w;
	local[3]= fqv[247];
	local[4]= argv[0]->c.obj.iv[8];
	local[5]= fqv[167];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO5282,env,argv,local);
	ctx->vsp=local+7;
	w=(*ftab[31])(ctx,4,local+3,&ftab[31],fqv[168]); /*find*/
	local[3]= w;
	local[4]= fqv[248];
	local[5]= argv[0]->c.obj.iv[8];
	local[6]= fqv[167];
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO5283,env,argv,local);
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,4,local+4,&ftab[31],fqv[168]); /*find*/
	local[4]= w;
	local[5]= fqv[249];
	local[6]= argv[0]->c.obj.iv[8];
	local[7]= fqv[167];
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,CLO5284,env,argv,local);
	ctx->vsp=local+9;
	w=(*ftab[31])(ctx,4,local+5,&ftab[31],fqv[168]); /*find*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,5,local+1); /*list*/
	argv[0]->c.obj.iv[28] = w;
	local[1]= fqv[250];
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[167];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO5285,env,argv,local);
	ctx->vsp=local+5;
	w=(*ftab[31])(ctx,4,local+1,&ftab[31],fqv[168]); /*find*/
	local[1]= w;
	local[2]= fqv[251];
	local[3]= argv[0]->c.obj.iv[8];
	local[4]= fqv[167];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO5286,env,argv,local);
	ctx->vsp=local+6;
	w=(*ftab[31])(ctx,4,local+2,&ftab[31],fqv[168]); /*find*/
	local[2]= w;
	local[3]= fqv[252];
	local[4]= argv[0]->c.obj.iv[8];
	local[5]= fqv[167];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO5287,env,argv,local);
	ctx->vsp=local+7;
	w=(*ftab[31])(ctx,4,local+3,&ftab[31],fqv[168]); /*find*/
	local[3]= w;
	local[4]= fqv[253];
	local[5]= argv[0]->c.obj.iv[8];
	local[6]= fqv[167];
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO5288,env,argv,local);
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,4,local+4,&ftab[31],fqv[168]); /*find*/
	local[4]= w;
	local[5]= fqv[254];
	local[6]= argv[0]->c.obj.iv[8];
	local[7]= fqv[167];
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,CLO5289,env,argv,local);
	ctx->vsp=local+9;
	w=(*ftab[31])(ctx,4,local+5,&ftab[31],fqv[168]); /*find*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,5,local+1); /*list*/
	argv[0]->c.obj.iv[29] = w;
	local[1]= fqv[255];
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[167];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO5290,env,argv,local);
	ctx->vsp=local+5;
	w=(*ftab[31])(ctx,4,local+1,&ftab[31],fqv[168]); /*find*/
	local[1]= w;
	local[2]= fqv[256];
	local[3]= argv[0]->c.obj.iv[8];
	local[4]= fqv[167];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO5291,env,argv,local);
	ctx->vsp=local+6;
	w=(*ftab[31])(ctx,4,local+2,&ftab[31],fqv[168]); /*find*/
	local[2]= w;
	local[3]= fqv[257];
	local[4]= argv[0]->c.obj.iv[8];
	local[5]= fqv[167];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO5292,env,argv,local);
	ctx->vsp=local+7;
	w=(*ftab[31])(ctx,4,local+3,&ftab[31],fqv[168]); /*find*/
	local[3]= w;
	local[4]= fqv[258];
	local[5]= argv[0]->c.obj.iv[8];
	local[6]= fqv[167];
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO5293,env,argv,local);
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,4,local+4,&ftab[31],fqv[168]); /*find*/
	local[4]= w;
	local[5]= fqv[259];
	local[6]= argv[0]->c.obj.iv[8];
	local[7]= fqv[167];
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,CLO5294,env,argv,local);
	ctx->vsp=local+9;
	w=(*ftab[31])(ctx,4,local+5,&ftab[31],fqv[168]); /*find*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,5,local+1); /*list*/
	argv[0]->c.obj.iv[30] = w;
	local[1]= fqv[260];
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[167];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO5295,env,argv,local);
	ctx->vsp=local+5;
	w=(*ftab[31])(ctx,4,local+1,&ftab[31],fqv[168]); /*find*/
	local[1]= w;
	local[2]= fqv[261];
	local[3]= argv[0]->c.obj.iv[8];
	local[4]= fqv[167];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO5296,env,argv,local);
	ctx->vsp=local+6;
	w=(*ftab[31])(ctx,4,local+2,&ftab[31],fqv[168]); /*find*/
	local[2]= w;
	local[3]= fqv[262];
	local[4]= argv[0]->c.obj.iv[8];
	local[5]= fqv[167];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO5297,env,argv,local);
	ctx->vsp=local+7;
	w=(*ftab[31])(ctx,4,local+3,&ftab[31],fqv[168]); /*find*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	argv[0]->c.obj.iv[31] = w;
	local[1]= fqv[183];
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[167];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO5298,env,argv,local);
	ctx->vsp=local+5;
	w=(*ftab[31])(ctx,4,local+1,&ftab[31],fqv[168]); /*find*/
	local[1]= w;
	local[2]= fqv[263];
	local[3]= argv[0]->c.obj.iv[8];
	local[4]= fqv[167];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO5299,env,argv,local);
	ctx->vsp=local+6;
	w=(*ftab[31])(ctx,4,local+2,&ftab[31],fqv[168]); /*find*/
	local[2]= w;
	local[3]= fqv[184];
	local[4]= argv[0]->c.obj.iv[8];
	local[5]= fqv[167];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO5300,env,argv,local);
	ctx->vsp=local+7;
	w=(*ftab[31])(ctx,4,local+3,&ftab[31],fqv[168]); /*find*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	argv[0]->c.obj.iv[32] = w;
	local[1]= argv[0];
	local[2]= fqv[185];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[186];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = argv[0];
	local[0]= w;
BLK5273:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5275(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5276(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5277(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5278(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5279(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5280(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5281(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5282(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5283(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5284(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5285(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5286(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5287(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5288(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5289(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5290(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5291(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5292(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5293(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5294(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5295(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5296(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5297(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5298(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5299(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5300(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*load-mcd*/
static pointer F4808load_mcd(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[264], &argv[1], n-1, local+0, 1);
	if (n & (1<<0)) goto KEY5302;
	local[0] = NIL;
KEY5302:
	if (n & (1<<1)) goto KEY5303;
	local[1] = NIL;
KEY5303:
	if (n & (1<<2)) goto KEY5304;
	local[2] = loadglobal(fqv[140]);
KEY5304:
	local[3]= local[2];
	w = local[3];
	ctx->vsp=local+4;
	bindspecial(ctx,fqv[140],w);
	local[7]= loadglobal(fqv[265]);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,1,local+7); /*instantiate*/
	local[7]= w;
	local[8]= local[7];
	local[9]= fqv[15];
	local[10]= argv[0];
	local[11]= fqv[45];
	local[12]= local[1];
	local[13]= fqv[47];
	local[14]= local[0];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,7,local+8); /*send*/
	w = local[7];
	local[7]= w;
	ctx->vsp=local+8;
	unbindx(ctx,1);
	w = local[7];
	local[0]= w;
BLK5301:
	ctx->vsp=local; return(local[0]);}

/*rikiya-bvh2eus*/
static pointer F4809rikiya_bvh2eus(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST5307:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= (pointer)get_sym_func(fqv[266]);
	local[2]= argv[0];
	local[3]= fqv[47];
	local[4]= makeflt(1.0000000000000000000000e+01);
	local[5]= fqv[267];
	local[6]= loadglobal(fqv[268]);
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,7,local+1); /*apply*/
	local[0]= w;
BLK5306:
	ctx->vsp=local; return(local[0]);}

/*cmu-bvh2eus*/
static pointer F4810cmu_bvh2eus(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST5309:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= (pointer)get_sym_func(fqv[266]);
	local[2]= argv[0];
	local[3]= fqv[47];
	local[4]= makeflt(1.0000000000000000000000e+02);
	local[5]= fqv[267];
	local[6]= loadglobal(fqv[269]);
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,7,local+1); /*apply*/
	local[0]= w;
BLK5308:
	ctx->vsp=local; return(local[0]);}

/*tum-bvh2eus*/
static pointer F4811tum_bvh2eus(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST5311:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= (pointer)get_sym_func(fqv[266]);
	local[2]= argv[0];
	local[3]= fqv[47];
	local[4]= makeflt(1.0000000000000000000000e+01);
	local[5]= fqv[267];
	local[6]= loadglobal(fqv[270]);
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,7,local+1); /*apply*/
	local[0]= w;
BLK5310:
	ctx->vsp=local; return(local[0]);}

/*rikiya-file*/
static pointer F4812rikiya_file(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[271], &argv[0], n-0, local+0, 0);
	if (n & (1<<0)) goto KEY5313;
	local[0] = makeint((eusinteger_t)1L);
KEY5313:
	if (n & (1<<1)) goto KEY5314;
	local[1] = fqv[272];
KEY5314:
	local[2]= NIL;
	local[3]= fqv[273];
	local[4]= fqv[274];
	ctx->vsp=local+5;
	w=(pointer)GETENV(ctx,1,local+4); /*unix:getenv*/
	local[4]= w;
	local[5]= local[1];
	local[6]= NIL;
	local[7]= fqv[275];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[16])(ctx,1,local+6,&ftab[16],fqv[87]); /*string-upcase*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,6,local+2); /*format*/
	local[0]= w;
BLK5312:
	ctx->vsp=local; return(local[0]);}

/*tum-kitchen-file*/
static pointer F4813tum_kitchen_file(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[276], &argv[0], n-0, local+0, 0);
	if (n & (1<<0)) goto KEY5316;
	local[0] = makeint((eusinteger_t)1L);
KEY5316:
	if (n & (1<<1)) goto KEY5317;
	local[1] = makeint((eusinteger_t)0L);
KEY5317:
	local[2]= NIL;
	local[3]= fqv[277];
	local[4]= fqv[278];
	ctx->vsp=local+5;
	w=(pointer)GETENV(ctx,1,local+4); /*unix:getenv*/
	local[4]= w;
	local[5]= local[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,5,local+2); /*format*/
	local[0]= w;
BLK5315:
	ctx->vsp=local; return(local[0]);}

/*cmu-mocap-file*/
static pointer F4814cmu_mocap_file(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[279], &argv[0], n-0, local+0, 0);
	if (n & (1<<0)) goto KEY5319;
	local[0] = makeint((eusinteger_t)1L);
KEY5319:
	if (n & (1<<1)) goto KEY5320;
	local[1] = makeint((eusinteger_t)1L);
KEY5320:
	local[2]= NIL;
	local[3]= fqv[280];
	local[4]= fqv[281];
	ctx->vsp=local+5;
	w=(pointer)GETENV(ctx,1,local+4); /*unix:getenv*/
	local[4]= w;
	local[5]= local[1];
	local[6]= local[1];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,6,local+2); /*format*/
	local[0]= w;
BLK5318:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___irtbvh(ctx,n,argv,env)
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
	local[0]= fqv[282];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF5321;
	local[0]= fqv[283];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[284],w);
	goto IF5322;
IF5321:
	local[0]= fqv[285];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF5322:
	local[0]= fqv[51];
	local[1]= fqv[286];
	local[2]= fqv[51];
	local[3]= fqv[287];
	local[4]= loadglobal(fqv[54]);
	local[5]= fqv[288];
	local[6]= fqv[289];
	local[7]= fqv[290];
	local[8]= NIL;
	local[9]= fqv[291];
	local[10]= NIL;
	local[11]= fqv[292];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[293];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[34])(ctx,13,local+2,&ftab[34],fqv[294]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4815bvh_link_init,fqv[15],fqv[51],fqv[295]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4844bvh_link_type,fqv[86],fqv[51],fqv[296]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4846bvh_link_offset,fqv[81],fqv[51],fqv[297]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4848bvh_link_channels,fqv[82],fqv[51],fqv[298]);
	local[0]= fqv[57];
	local[1]= fqv[286];
	local[2]= fqv[57];
	local[3]= fqv[287];
	local[4]= loadglobal(fqv[299]);
	local[5]= fqv[288];
	local[6]= fqv[300];
	local[7]= fqv[290];
	local[8]= NIL;
	local[9]= fqv[291];
	local[10]= NIL;
	local[11]= fqv[292];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[293];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[34])(ctx,13,local+2,&ftab[34],fqv[294]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4850bvh_sphere_joint_init,fqv[15],fqv[57],fqv[301]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4855bvh_sphere_joint_joint_angle_bvh,fqv[111],fqv[57],fqv[302]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4859bvh_sphere_joint_joint_angle_bvh_offset,fqv[76],fqv[57],fqv[303]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4863bvh_sphere_joint_joint_angle_bvh_impl,fqv[35],fqv[57],fqv[304]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4867bvh_sphere_joint_axis_order,fqv[84],fqv[57],fqv[305]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4869bvh_sphere_joint_bvh_offset_rotation,fqv[64],fqv[57],fqv[306]);
	local[0]= fqv[59];
	local[1]= fqv[286];
	local[2]= fqv[59];
	local[3]= fqv[287];
	local[4]= loadglobal(fqv[307]);
	local[5]= fqv[288];
	local[6]= fqv[308];
	local[7]= fqv[290];
	local[8]= NIL;
	local[9]= fqv[291];
	local[10]= NIL;
	local[11]= fqv[292];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[293];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[34])(ctx,13,local+2,&ftab[34],fqv[294]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4871bvh_6dof_joint_init,fqv[15],fqv[59],fqv[309]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4879bvh_6dof_joint_joint_angle_bvh,fqv[111],fqv[59],fqv[310]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4883bvh_6dof_joint_joint_angle_bvh_offset,fqv[76],fqv[59],fqv[311]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4887bvh_6dof_joint_joint_angle_bvh_impl,fqv[35],fqv[59],fqv[312]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4891bvh_6dof_joint_axis_order,fqv[84],fqv[59],fqv[313]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4893bvh_6dof_joint_bvh_offset_rotation,fqv[64],fqv[59],fqv[314]);
	local[0]= fqv[140];
	local[1]= fqv[286];
	local[2]= fqv[140];
	local[3]= fqv[287];
	local[4]= loadglobal(fqv[155]);
	local[5]= fqv[288];
	local[6]= fqv[315];
	local[7]= fqv[290];
	local[8]= NIL;
	local[9]= fqv[291];
	local[10]= NIL;
	local[11]= fqv[292];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[293];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[34])(ctx,13,local+2,&ftab[34],fqv[294]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4895bvh_robot_model_init,fqv[15],fqv[140],fqv[316]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4903bvh_robot_model_make_bvh_link,fqv[46],fqv[140],fqv[317]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4933bvh_robot_model_angle_vector,fqv[318],fqv[140],fqv[319]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4956bvh_robot_model_dump_joints,fqv[97],fqv[140],fqv[320]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4982bvh_robot_model_dump_hierarchy,fqv[321],fqv[140],fqv[322]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4986bvh_robot_model_dump_motion,fqv[323],fqv[140],fqv[324]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4999bvh_robot_model_copy_state_to,fqv[157],fqv[140],fqv[325]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5001bvh_robot_model_fix_joint_angle,fqv[326],fqv[140],fqv[327]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5003bvh_robot_model_fix_joint_order,fqv[328],fqv[140],fqv[329]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5005bvh_robot_model_bvh_offset_rotate,fqv[65],fqv[140],fqv[330]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[331],module,F4804parse_bvh_sexp,fqv[332]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[333],module,F4805read_bvh,fqv[334]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[335],module,F4806make_bvh_robot_model,fqv[336]);
	local[0]= fqv[265];
	local[1]= fqv[286];
	local[2]= fqv[265];
	local[3]= fqv[287];
	local[4]= loadglobal(fqv[337]);
	local[5]= fqv[288];
	local[6]= fqv[338];
	local[7]= fqv[290];
	local[8]= NIL;
	local[9]= fqv[291];
	local[10]= NIL;
	local[11]= fqv[292];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[293];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[34])(ctx,13,local+2,&ftab[34],fqv[294]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5061motion_capture_data_init,fqv[15],fqv[265],fqv[339]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5065motion_capture_data_model,fqv[156],fqv[265],fqv[340]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5068motion_capture_data_animation,fqv[341],fqv[265],fqv[342]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5071motion_capture_data_frame,fqv[149],fqv[265],fqv[343]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5082motion_capture_data_frame_length,fqv[148],fqv[265],fqv[344]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5084motion_capture_data_animate,fqv[150],fqv[265],fqv[345]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[266],module,F4807bvh2eus,fqv[346]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5113bvh_robot_model_init_end_coords,fqv[185],fqv[140],fqv[347]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5121bvh_robot_model_init_root_link,fqv[186],fqv[140],fqv[348]);
	local[0]= fqv[268];
	local[1]= fqv[286];
	local[2]= fqv[268];
	local[3]= fqv[287];
	local[4]= loadglobal(fqv[140]);
	local[5]= fqv[288];
	local[6]= fqv[315];
	local[7]= fqv[290];
	local[8]= NIL;
	local[9]= fqv[291];
	local[10]= NIL;
	local[11]= fqv[292];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[293];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[34])(ctx,13,local+2,&ftab[34],fqv[294]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5129rikiya_bvh_robot_model_init,fqv[15],fqv[268],fqv[349]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5149rikiya_bvh_robot_model_larm_collar,fqv[350],fqv[268],fqv[351]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5152rikiya_bvh_robot_model_larm_shoulder,fqv[352],fqv[268],fqv[353]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5155rikiya_bvh_robot_model_larm_elbow,fqv[354],fqv[268],fqv[355]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5158rikiya_bvh_robot_model_larm_wrist,fqv[356],fqv[268],fqv[357]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5161rikiya_bvh_robot_model_rarm_collar,fqv[358],fqv[268],fqv[359]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5164rikiya_bvh_robot_model_rarm_shoulder,fqv[360],fqv[268],fqv[361]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5167rikiya_bvh_robot_model_rarm_elbow,fqv[362],fqv[268],fqv[363]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5170rikiya_bvh_robot_model_rarm_wrist,fqv[364],fqv[268],fqv[365]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5173rikiya_bvh_robot_model_lleg_crotch,fqv[366],fqv[268],fqv[367]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5176rikiya_bvh_robot_model_lleg_knee,fqv[368],fqv[268],fqv[369]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5179rikiya_bvh_robot_model_lleg_ankle,fqv[370],fqv[268],fqv[371]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5182rikiya_bvh_robot_model_rleg_crotch,fqv[372],fqv[268],fqv[373]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5185rikiya_bvh_robot_model_rleg_knee,fqv[374],fqv[268],fqv[375]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5188rikiya_bvh_robot_model_rleg_ankle,fqv[376],fqv[268],fqv[377]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5191rikiya_bvh_robot_model_torso_chest,fqv[378],fqv[268],fqv[379]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5194rikiya_bvh_robot_model_head_neck,fqv[380],fqv[268],fqv[381]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5197rikiya_bvh_robot_model_copy_joint_to,fqv[205],fqv[268],fqv[382]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5207rikiya_bvh_robot_model_copy_state_to,fqv[157],fqv[268],fqv[383]);
	local[0]= fqv[270];
	local[1]= fqv[286];
	local[2]= fqv[270];
	local[3]= fqv[287];
	local[4]= loadglobal(fqv[140]);
	local[5]= fqv[288];
	local[6]= fqv[315];
	local[7]= fqv[290];
	local[8]= NIL;
	local[9]= fqv[291];
	local[10]= NIL;
	local[11]= fqv[292];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[293];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[34])(ctx,13,local+2,&ftab[34],fqv[294]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5243tum_bvh_robot_model_init,fqv[15],fqv[270],fqv[384]);
	local[0]= fqv[269];
	local[1]= fqv[286];
	local[2]= fqv[269];
	local[3]= fqv[287];
	local[4]= loadglobal(fqv[140]);
	local[5]= fqv[288];
	local[6]= fqv[315];
	local[7]= fqv[290];
	local[8]= NIL;
	local[9]= fqv[291];
	local[10]= NIL;
	local[11]= fqv[292];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[293];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[34])(ctx,13,local+2,&ftab[34],fqv[294]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5272cmu_bvh_robot_model_init,fqv[15],fqv[269],fqv[385]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[163],module,F4808load_mcd,fqv[386]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[387],module,F4809rikiya_bvh2eus,fqv[388]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[389],module,F4810cmu_bvh2eus,fqv[390]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[391],module,F4811tum_bvh2eus,fqv[392]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[393],module,F4812rikiya_file,fqv[394]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[395],module,F4813tum_kitchen_file,fqv[396]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[397],module,F4814cmu_mocap_file,fqv[398]);
	local[0]= fqv[399];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF5323;
	local[0]= fqv[400];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[284],w);
	goto IF5324;
IF5323:
	local[0]= fqv[401];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF5324:
	local[0]= fqv[402];
	local[1]= fqv[403];
	ctx->vsp=local+2;
	w=(*ftab[35])(ctx,2,local+0,&ftab[35],fqv[404]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<36; i++) ftab[i]=fcallx;
}
