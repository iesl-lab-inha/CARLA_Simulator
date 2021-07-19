/* ./irtmodel.c :  entry=irtmodel */
/* compiled by EusLisp 9.27() for Linux created on ip-10-0-1-214(Fri Apr 16 04:05:26 PST 2021) */
#include "eus.h"
#include "irtmodel.h"
#pragma init (register_irtmodel)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___irtmodel();
extern pointer build_quote_vector();
static int register_irtmodel()
  { add_module_initializer("___irtmodel", ___irtmodel);}

static pointer F760calc_jacobian_default_rotate_vector();
static pointer F761calc_jacobian_rotational();
static pointer F762calc_jacobian_linear();
static pointer F763calc_angle_speed_gain_scalar();
static pointer F764calc_angle_speed_gain_vector();
static pointer F765all_child_links();
static pointer F766calc_dif_with_axis();
static pointer F767calc_target_joint_dimension();
static pointer F768calc_joint_angle_min_max_for_limit_calculation();
static pointer F769joint_angle_limit_weight();
static pointer F770joint_angle_limit_nspace();
static pointer F771calc_jacobian_from_link_list_including_robot_and_obj_virtual_joint();
static pointer F772append_obj_virtual_joint();
static pointer F773append_multiple_obj_virtual_joint();
static pointer F774eusmodel_validity_check_one();
static pointer F775eusmodel_validity_check();

/*:init*/
static pointer M776joint_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[0], &argv[2], n-2, local+0, 1);
	if (n & (1<<0)) goto KEY778;
	local[9]= NIL;
	local[10]= fqv[1];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)ADDRESS(ctx,1,local+11); /*system:address*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,3,local+9); /*format*/
	local[9]= w;
	local[10]= fqv[2];
	ctx->vsp=local+11;
	w=(pointer)INTERN(ctx,2,local+9); /*intern*/
	local[0] = w;
KEY778:
	if (n & (1<<1)) goto KEY779;
	local[1] = NIL;
KEY779:
	if (n & (1<<2)) goto KEY780;
	local[2] = NIL;
KEY780:
	if (n & (1<<3)) goto KEY781;
	local[3] = makeint((eusinteger_t)-90L);
KEY781:
	if (n & (1<<4)) goto KEY782;
	local[4] = makeint((eusinteger_t)90L);
KEY782:
	if (n & (1<<5)) goto KEY783;
	local[5] = NIL;
KEY783:
	if (n & (1<<6)) goto KEY784;
	local[6] = NIL;
KEY784:
	if (n & (1<<7)) goto KEY785;
	local[7] = NIL;
KEY785:
	if (n & (1<<8)) goto KEY786;
	local[8] = NIL;
KEY786:
	local[9]= argv[0];
	local[10]= fqv[3];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	argv[0]->c.obj.iv[1] = local[2];
	argv[0]->c.obj.iv[2] = local[1];
	argv[0]->c.obj.iv[4] = local[3];
	argv[0]->c.obj.iv[5] = local[4];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(*ftab[0])(ctx,1,local+9,&ftab[0],fqv[4]); /*float-vector-p*/
	if (w==NIL) goto AND790;
	local[9]= local[5];
	local[10]= loadglobal(fqv[5]);
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)LENGTH(ctx,1,local+11); /*length*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)INSTANTIATE(ctx,2,local+10); /*instantiate*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)VGREATERP(ctx,2,local+9); /*v>*/
	if (w!=NIL) goto AND790;
	goto OR789;
AND790:
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(*ftab[0])(ctx,1,local+9,&ftab[0],fqv[4]); /*float-vector-p*/
	if (w!=NIL) goto AND791;
	local[9]= local[5];
	local[10]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+11;
	w=(pointer)LESSP(ctx,2,local+9); /*<*/
	if (w==NIL) goto AND791;
	goto OR789;
AND791:
	goto IF787;
OR789:
	local[9]= fqv[6];
	local[10]= local[0];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)SIGERROR(ctx,3,local+9); /*error*/
	local[9]= w;
	goto IF788;
IF787:
	local[9]= NIL;
IF788:
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(*ftab[0])(ctx,1,local+9,&ftab[0],fqv[4]); /*float-vector-p*/
	if (w==NIL) goto AND795;
	local[9]= local[6];
	local[10]= loadglobal(fqv[5]);
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)LENGTH(ctx,1,local+11); /*length*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)INSTANTIATE(ctx,2,local+10); /*instantiate*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)VGREATERP(ctx,2,local+9); /*v>*/
	if (w!=NIL) goto AND795;
	goto OR794;
AND795:
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(*ftab[0])(ctx,1,local+9,&ftab[0],fqv[4]); /*float-vector-p*/
	if (w!=NIL) goto AND796;
	local[9]= local[6];
	local[10]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+11;
	w=(pointer)LESSP(ctx,2,local+9); /*<*/
	if (w==NIL) goto AND796;
	goto OR794;
AND796:
	goto IF792;
OR794:
	local[9]= fqv[7];
	local[10]= local[0];
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)SIGERROR(ctx,3,local+9); /*error*/
	local[9]= w;
	goto IF793;
IF792:
	local[9]= NIL;
IF793:
	local[9]= argv[0];
	local[10]= fqv[8];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= argv[0];
	local[10]= fqv[9];
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= argv[0];
	local[10]= fqv[10];
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= argv[0];
	local[10]= fqv[11];
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= argv[0]->c.obj.iv[2];
	local[10]= fqv[12];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	argv[0]->c.obj.iv[6] = w;
	w = argv[0];
	local[0]= w;
BLK777:
	ctx->vsp=local; return(local[0]);}

/*:min-angle*/
static pointer M797joint_min_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT800;}
	local[0]= NIL;
ENT800:
ENT799:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF801;
	argv[0]->c.obj.iv[4] = local[0];
	local[1]= argv[0]->c.obj.iv[4];
	goto IF802;
IF801:
	local[1]= NIL;
IF802:
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK798:
	ctx->vsp=local; return(local[0]);}

/*:max-angle*/
static pointer M803joint_max_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT806;}
	local[0]= NIL;
ENT806:
ENT805:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF807;
	argv[0]->c.obj.iv[5] = local[0];
	local[1]= argv[0]->c.obj.iv[5];
	goto IF808;
IF807:
	local[1]= NIL;
IF808:
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK804:
	ctx->vsp=local; return(local[0]);}

/*:parent-link*/
static pointer M809joint_parent_link(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST811:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[13]); /*forward-message-to*/
	local[0]= w;
BLK810:
	ctx->vsp=local; return(local[0]);}

/*:child-link*/
static pointer M812joint_child_link(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST814:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[13]); /*forward-message-to*/
	local[0]= w;
BLK813:
	ctx->vsp=local; return(local[0]);}

/*:calc-dav-gain*/
static pointer M815joint_calc_dav_gain(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= fqv[14];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[15]); /*warn*/
	local[0]= w;
BLK816:
	ctx->vsp=local; return(local[0]);}

/*:joint-dof*/
static pointer M817joint_joint_dof(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[16];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[15]); /*warn*/
	local[0]= w;
BLK818:
	ctx->vsp=local; return(local[0]);}

/*:speed-to-angle*/
static pointer M819joint_speed_to_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST821:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= fqv[17];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[15]); /*warn*/
	local[0]= w;
BLK820:
	ctx->vsp=local; return(local[0]);}

/*:angle-to-speed*/
static pointer M822joint_angle_to_speed(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST824:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= fqv[18];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[15]); /*warn*/
	local[0]= w;
BLK823:
	ctx->vsp=local; return(local[0]);}

/*:calc-jacobian*/
static pointer M825joint_calc_jacobian(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST827:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= fqv[19];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[15]); /*warn*/
	local[0]= w;
BLK826:
	ctx->vsp=local; return(local[0]);}

/*:joint-velocity*/
static pointer M828joint_joint_velocity(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT831;}
	local[0]= NIL;
ENT831:
ENT830:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF832;
	argv[0]->c.obj.iv[7] = local[0];
	local[1]= argv[0]->c.obj.iv[7];
	goto IF833;
IF832:
	local[1]= argv[0]->c.obj.iv[7];
IF833:
	w = local[1];
	local[0]= w;
BLK829:
	ctx->vsp=local; return(local[0]);}

/*:joint-acceleration*/
static pointer M834joint_joint_acceleration(ctx,n,argv,env)
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
	argv[0]->c.obj.iv[8] = local[0];
	local[1]= argv[0]->c.obj.iv[8];
	goto IF839;
IF838:
	local[1]= argv[0]->c.obj.iv[8];
IF839:
	w = local[1];
	local[0]= w;
BLK835:
	ctx->vsp=local; return(local[0]);}

/*:joint-torque*/
static pointer M840joint_joint_torque(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT843;}
	local[0]= NIL;
ENT843:
ENT842:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF844;
	argv[0]->c.obj.iv[9] = local[0];
	local[1]= argv[0]->c.obj.iv[9];
	goto IF845;
IF844:
	local[1]= argv[0]->c.obj.iv[9];
IF845:
	w = local[1];
	local[0]= w;
BLK841:
	ctx->vsp=local; return(local[0]);}

/*:max-joint-velocity*/
static pointer M846joint_max_joint_velocity(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT849;}
	local[0]= NIL;
ENT849:
ENT848:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF850;
	argv[0]->c.obj.iv[10] = local[0];
	local[1]= argv[0]->c.obj.iv[10];
	goto IF851;
IF850:
	local[1]= argv[0]->c.obj.iv[10];
IF851:
	w = local[1];
	local[0]= w;
BLK847:
	ctx->vsp=local; return(local[0]);}

/*:max-joint-torque*/
static pointer M852joint_max_joint_torque(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT855;}
	local[0]= NIL;
ENT855:
ENT854:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF856;
	argv[0]->c.obj.iv[11] = local[0];
	local[1]= argv[0]->c.obj.iv[11];
	goto IF857;
IF856:
	local[1]= argv[0]->c.obj.iv[11];
IF857:
	w = local[1];
	local[0]= w;
BLK853:
	ctx->vsp=local; return(local[0]);}

/*:joint-min-max-table*/
static pointer M858joint_joint_min_max_table(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT861;}
	local[0]= NIL;
ENT861:
ENT860:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF862;
	argv[0]->c.obj.iv[12] = local[0];
	local[1]= argv[0]->c.obj.iv[12];
	goto IF863;
IF862:
	local[1]= argv[0]->c.obj.iv[12];
IF863:
	w = local[1];
	local[0]= w;
BLK859:
	ctx->vsp=local; return(local[0]);}

/*:joint-min-max-target*/
static pointer M864joint_joint_min_max_target(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT867;}
	local[0]= NIL;
ENT867:
ENT866:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF868;
	argv[0]->c.obj.iv[13] = local[0];
	local[1]= argv[0]->c.obj.iv[13];
	goto IF869;
IF868:
	local[1]= argv[0]->c.obj.iv[13];
IF869:
	w = local[1];
	local[0]= w;
BLK865:
	ctx->vsp=local; return(local[0]);}

/*:joint-min-max-table-angle-interpolate*/
static pointer M870joint_joint_min_max_table_angle_interpolate(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)FLOOR(ctx,1,local+0); /*floor*/
	local[0]= w;
	local[1]= local[0];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO872,env,argv,local);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)EUSFLOAT(ctx,1,local+4); /*float*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= makeint((eusinteger_t)1L);
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[0]= w;
BLK871:
	ctx->vsp=local; return(local[0]);}

/*:joint-min-max-table-min-angle*/
static pointer M873joint_joint_min_max_table_min_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT876;}
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= fqv[20];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
ENT876:
ENT875:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[21];
	local[3]= local[0];
	local[4]= fqv[22];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK874:
	ctx->vsp=local; return(local[0]);}

/*:joint-min-max-table-max-angle*/
static pointer M877joint_joint_min_max_table_max_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT880;}
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= fqv[20];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
ENT880:
ENT879:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[21];
	local[3]= local[0];
	local[4]= fqv[23];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK878:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO872(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0]->c.obj.iv[12];
	local[1]= env->c.clo.env1[3];
	local[2]= local[1];
	if (fqv[22]!=local[2]) goto IF882;
	local[2]= makeint((eusinteger_t)1L);
	goto IF883;
IF882:
	local[2]= local[1];
	if (fqv[23]!=local[2]) goto IF884;
	local[2]= makeint((eusinteger_t)2L);
	goto IF885;
IF884:
	if (T==NIL) goto IF886;
	local[2]= NIL;
	goto IF887;
IF886:
	local[2]= NIL;
IF887:
IF885:
IF883:
	w = local[2];
	local[1]= w;
	local[2]= env->c.clo.env1[0]->c.obj.iv[12];
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,3,local+2); /*aref*/
	local[2]= w;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)MAX(ctx,2,local+2); /*max*/
	local[2]= w;
	local[3]= env->c.clo.env1[0]->c.obj.iv[12];
	local[4]= makeint((eusinteger_t)0L);
	local[5]= env->c.clo.env1[0]->c.obj.iv[12];
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(*ftab[3])(ctx,2,local+5,&ftab[3],fqv[24]); /*array-dimension*/
	local[5]= w;
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,3,local+3); /*aref*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MIN(ctx,2,local+2); /*min*/
	local[2]= w;
	local[3]= env->c.clo.env1[0]->c.obj.iv[12];
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,3,local+3); /*aref*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ROUND(ctx,1,local+2); /*round*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,3,local+0); /*aref*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*calc-jacobian-default-rotate-vector*/
static pointer F760calc_jacobian_default_rotate_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	if (argv[2]==NIL) goto IF889;
	local[0]= makeflt(-1.0000000000000000000000e+00);
	goto IF890;
IF889:
	local[0]= makeflt(1.0000000000000000000000e+00);
IF890:
	local[1]= argv[1];
	local[2]= fqv[25];
	local[3]= argv[0];
	local[4]= argv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	local[2]= argv[4];
	ctx->vsp=local+3;
	w=(*ftab[4])(ctx,2,local+1,&ftab[4],fqv[26]); /*normalize-vector*/
	local[1]= w;
	local[2]= argv[4];
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,3,local+0); /*scale*/
	argv[4] = w;
	local[0]= argv[3];
	local[1]= fqv[27];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[5];
	ctx->vsp=local+2;
	w=(pointer)TRANSPOSE(ctx,2,local+0); /*transpose*/
	local[0]= w;
	local[1]= argv[4];
	local[2]= argv[4];
	ctx->vsp=local+3;
	w=(pointer)TRANSFORM(ctx,3,local+0); /*transform*/
	local[0]= w;
BLK888:
	ctx->vsp=local; return(local[0]);}

/*calc-jacobian-rotational*/
static pointer F761calc_jacobian_rotational(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=19) maerror();
	w = argv[3];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[28],w);
	local[3]= argv[4];
	local[4]= argv[6];
	local[5]= argv[7];
	local[6]= argv[9];
	local[7]= argv[15];
	local[8]= argv[18];
	ctx->vsp=local+9;
	w=(pointer)F760calc_jacobian_default_rotate_vector(ctx,6,local+3); /*calc-jacobian-default-rotate-vector*/
	local[3]= w;
	local[4]= makeflt(1.0000000000000000208167e-03);
	local[5]= argv[9];
	local[6]= fqv[27];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= argv[18];
	ctx->vsp=local+7;
	w=(pointer)TRANSPOSE(ctx,2,local+5); /*transpose*/
	local[5]= w;
	local[6]= argv[8];
	local[7]= fqv[29];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= argv[5];
	local[8]= fqv[29];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= argv[16];
	ctx->vsp=local+9;
	w=(pointer)VMINUS(ctx,3,local+6); /*v-*/
	local[6]= w;
	local[7]= argv[16];
	ctx->vsp=local+8;
	w=(pointer)TRANSFORM(ctx,3,local+5); /*transform*/
	local[5]= w;
	local[6]= argv[16];
	ctx->vsp=local+7;
	w=(pointer)SCALEVEC(ctx,3,local+4); /*scale*/
	local[4]= w;
	local[5]= local[3];
	local[6]= local[4];
	local[7]= argv[17];
	ctx->vsp=local+8;
	w=(pointer)VCROSSPRODUCT(ctx,3,local+5); /*v**/
	local[5]= w;
	local[6]= local[5];
	local[7]= argv[11];
	local[8]= argv[12];
	local[9]= argv[13];
	local[10]= argv[14];
	ctx->vsp=local+11;
	w=(pointer)F766calc_dif_with_axis(ctx,5,local+6); /*calc-dif-with-axis*/
	local[5] = w;
	local[6]= makeint((eusinteger_t)0L);
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
WHL893:
	local[8]= local[6];
	w = local[7];
	if ((eusinteger_t)local[8] >= (eusinteger_t)w) goto WHX894;
	local[8]= argv[0];
	local[9]= local[6];
	local[10]= argv[1];
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	local[10]= argv[2];
	local[11]= local[5];
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)ASET(ctx,4,local+8); /*aset*/
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[6] = w;
	goto WHL893;
WHX894:
	local[8]= NIL;
BLK895:
	w = NIL;
	local[6]= local[3];
	local[7]= argv[10];
	local[8]= argv[12];
	local[9]= argv[13];
	local[10]= argv[14];
	ctx->vsp=local+11;
	w=(pointer)F766calc_dif_with_axis(ctx,5,local+6); /*calc-dif-with-axis*/
	local[3] = w;
	local[6]= makeint((eusinteger_t)0L);
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
WHL897:
	local[8]= local[6];
	w = local[7];
	if ((eusinteger_t)local[8] >= (eusinteger_t)w) goto WHX898;
	local[8]= argv[0];
	local[9]= local[6];
	local[10]= argv[1];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)LENGTH(ctx,1,local+11); /*length*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,3,local+9); /*+*/
	local[9]= w;
	local[10]= argv[2];
	local[11]= local[3];
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)ASET(ctx,4,local+8); /*aset*/
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[6] = w;
	goto WHL897;
WHX898:
	local[8]= NIL;
BLK899:
	w = NIL;
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK891:
	ctx->vsp=local; return(local[0]);}

/*calc-jacobian-linear*/
static pointer F762calc_jacobian_linear(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=19) maerror();
	w = argv[3];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[28],w);
	local[3]= argv[4];
	local[4]= argv[6];
	local[5]= argv[7];
	local[6]= argv[9];
	local[7]= argv[15];
	local[8]= argv[18];
	ctx->vsp=local+9;
	w=(pointer)F760calc_jacobian_default_rotate_vector(ctx,6,local+3); /*calc-jacobian-default-rotate-vector*/
	local[3]= w;
	local[4]= fqv[30];
	local[5]= local[3];
	local[6]= argv[11];
	local[7]= argv[12];
	local[8]= argv[13];
	local[9]= argv[14];
	ctx->vsp=local+10;
	w=(pointer)F766calc_dif_with_axis(ctx,5,local+5); /*calc-dif-with-axis*/
	local[3] = w;
	local[5]= makeint((eusinteger_t)0L);
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
WHL902:
	local[7]= local[5];
	w = local[6];
	if ((eusinteger_t)local[7] >= (eusinteger_t)w) goto WHX903;
	local[7]= argv[0];
	local[8]= local[5];
	local[9]= argv[1];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	local[9]= argv[2];
	local[10]= local[3];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)ELT(ctx,2,local+10); /*elt*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)ASET(ctx,4,local+7); /*aset*/
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[5] = w;
	goto WHL902;
WHX903:
	local[7]= NIL;
BLK904:
	w = NIL;
	local[5]= local[4];
	local[6]= argv[10];
	local[7]= argv[12];
	local[8]= argv[13];
	local[9]= argv[14];
	ctx->vsp=local+10;
	w=(pointer)F766calc_dif_with_axis(ctx,5,local+5); /*calc-dif-with-axis*/
	local[4] = w;
	local[5]= makeint((eusinteger_t)0L);
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
WHL906:
	local[7]= local[5];
	w = local[6];
	if ((eusinteger_t)local[7] >= (eusinteger_t)w) goto WHX907;
	local[7]= argv[0];
	local[8]= local[5];
	local[9]= argv[1];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)LENGTH(ctx,1,local+10); /*length*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,3,local+8); /*+*/
	local[8]= w;
	local[9]= argv[2];
	local[10]= local[4];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)ELT(ctx,2,local+10); /*elt*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)ASET(ctx,4,local+7); /*aset*/
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[5] = w;
	goto WHL906;
WHX907:
	local[7]= NIL;
BLK908:
	w = NIL;
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK900:
	ctx->vsp=local; return(local[0]);}

/*calc-angle-speed-gain-scalar*/
static pointer F763calc_angle_speed_gain_scalar(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[8];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)ABS(ctx,1,local+0); /*abs*/
	local[0]= w;
	local[1]= local[0];
	local[2]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto IF910;
	local[1]= local[0];
	goto IF911;
IF910:
	local[1]= makeflt(1.0000000000000000000000e+00);
IF911:
	w = local[1];
	local[0]= w;
BLK909:
	ctx->vsp=local; return(local[0]);}

/*calc-angle-speed-gain-vector*/
static pointer F764calc_angle_speed_gain_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= makeflt(1.0000000000000000000000e+00);
	local[1]= makeint((eusinteger_t)0L);
	local[2]= argv[0];
	local[3]= fqv[31];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
WHL914:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX915;
	local[3]= argv[0];
	local[4]= fqv[8];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	local[4]= argv[1];
	local[5]= local[1];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ABS(ctx,1,local+3); /*abs*/
	local[3]= w;
	local[4]= local[3];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,2,local+4); /*<*/
	if (w==NIL) goto IF917;
	local[0] = local[3];
	local[4]= local[0];
	goto IF918;
IF917:
	local[4]= NIL;
IF918:
	w = local[4];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL914;
WHX915:
	local[3]= NIL;
BLK916:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK912:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M919rotational_joint_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST921:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[32], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY922;
	local[1] = fqv[33];
KEY922:
	if (n & (1<<1)) goto KEY923;
	local[2] = makeint((eusinteger_t)5L);
KEY923:
	if (n & (1<<2)) goto KEY924;
	local[3] = makeint((eusinteger_t)100L);
KEY924:
	argv[0]->c.obj.iv[14] = local[1];
	argv[0]->c.obj.iv[3] = makeflt(0.0000000000000000000000e+00);
	local[4]= (pointer)get_sym_func(fqv[34]);
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[35]));
	local[7]= fqv[36];
	local[8]= fqv[8];
	local[9]= local[2];
	local[10]= fqv[9];
	local[11]= local[3];
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)APPLY(ctx,9,local+4); /*apply*/
	if (argv[0]->c.obj.iv[4]!=NIL) goto IF925;
	argv[0]->c.obj.iv[4] = makeflt(-9.0000000000000000000000e+01);
	local[4]= argv[0]->c.obj.iv[4];
	goto IF926;
IF925:
	local[4]= NIL;
IF926:
	if (argv[0]->c.obj.iv[5]!=NIL) goto IF927;
	local[4]= makeflt(1.8000000000000000000000e+02);
	local[5]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	argv[0]->c.obj.iv[5] = w;
	local[4]= argv[0]->c.obj.iv[5];
	goto IF928;
IF927:
	local[4]= NIL;
IF928:
	local[4]= argv[0];
	local[5]= fqv[37];
	local[6]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[38];
	local[6]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[39];
	local[6]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	w = argv[0];
	local[0]= w;
BLK920:
	ctx->vsp=local; return(local[0]);}

/*:joint-angle*/
static pointer M929rotational_joint_joint_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT932;}
	local[0]= NIL;
ENT932:
ENT931:
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[40], &argv[3], n-3, local+1, 1);
	if (n & (1<<0)) goto KEY933;
	local[1] = NIL;
KEY933:
	if (local[0]==NIL) goto IF934;
	if (argv[0]->c.obj.iv[12]==NIL) goto IF936;
	if (argv[0]->c.obj.iv[13]==NIL) goto IF936;
	local[2]= argv[0];
	local[3]= fqv[41];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	argv[0]->c.obj.iv[4] = w;
	local[2]= argv[0];
	local[3]= fqv[42];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	argv[0]->c.obj.iv[5] = w;
	local[2]= argv[0]->c.obj.iv[5];
	goto IF937;
IF936:
	local[2]= NIL;
IF937:
	if (local[1]==NIL) goto IF938;
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[0] = w;
	local[2]= local[0];
	goto IF939;
IF938:
	local[2]= NIL;
IF939:
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto CON941;
	if (local[1]!=NIL) goto IF942;
	local[2]= makeint((eusinteger_t)3L);
	local[3]= fqv[43];
	local[4]= argv[0];
	local[5]= local[0];
	local[6]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+7;
	w=(*ftab[5])(ctx,5,local+2,&ftab[5],fqv[44]); /*warning-message*/
	local[2]= w;
	goto IF943;
IF942:
	local[2]= NIL;
IF943:
	local[0] = argv[0]->c.obj.iv[5];
	local[2]= local[0];
	goto CON940;
CON941:
	local[2]= NIL;
CON940:
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto CON945;
	if (local[1]!=NIL) goto IF946;
	local[2]= makeint((eusinteger_t)3L);
	local[3]= fqv[45];
	local[4]= argv[0];
	local[5]= local[0];
	local[6]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+7;
	w=(*ftab[5])(ctx,5,local+2,&ftab[5],fqv[44]); /*warning-message*/
	local[2]= w;
	goto IF947;
IF946:
	local[2]= NIL;
IF947:
	local[0] = argv[0]->c.obj.iv[4];
	local[2]= local[0];
	goto CON944;
CON945:
	local[2]= NIL;
CON944:
	argv[0]->c.obj.iv[3] = local[0];
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= fqv[46];
	local[4]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= fqv[47];
	local[4]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+5;
	w=(*ftab[6])(ctx,1,local+4,&ftab[6],fqv[48]); /*deg2rad*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	goto IF935;
IF934:
	local[2]= NIL;
IF935:
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK930:
	ctx->vsp=local; return(local[0]);}

/*:joint-dof*/
static pointer M948rotational_joint_joint_dof(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = makeint((eusinteger_t)1L);
	local[0]= w;
BLK949:
	ctx->vsp=local; return(local[0]);}

/*:calc-angle-speed-gain*/
static pointer M950rotational_joint_calc_angle_speed_gain(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= argv[2];
	local[2]= argv[3];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)F763calc_angle_speed_gain_scalar(ctx,4,local+0); /*calc-angle-speed-gain-scalar*/
	local[0]= w;
BLK951:
	ctx->vsp=local; return(local[0]);}

/*:speed-to-angle*/
static pointer M952rotational_joint_speed_to_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[7])(ctx,1,local+0,&ftab[7],fqv[49]); /*rad2deg*/
	local[0]= w;
BLK953:
	ctx->vsp=local; return(local[0]);}

/*:angle-to-speed*/
static pointer M954rotational_joint_angle_to_speed(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[6])(ctx,1,local+0,&ftab[6],fqv[48]); /*deg2rad*/
	local[0]= w;
BLK955:
	ctx->vsp=local; return(local[0]);}

/*:calc-jacobian*/
static pointer M956rotational_joint_calc_jacobian(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST958:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[50]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[0]= w;
BLK957:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M959linear_joint_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST961:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[51], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY962;
	local[1] = fqv[33];
KEY962:
	if (n & (1<<1)) goto KEY963;
	local[4]= makeflt(3.1415926535897931159980e+00);
	local[5]= makeint((eusinteger_t)4L);
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[2] = w;
KEY963:
	if (n & (1<<2)) goto KEY964;
	local[3] = makeint((eusinteger_t)100L);
KEY964:
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,1,local+4,&ftab[0],fqv[4]); /*float-vector-p*/
	if (w==NIL) goto IF965;
	local[4]= local[1];
	goto IF966;
IF965:
	local[4]= local[1];
	local[5]= local[4];
	if (fqv[52]!=local[5]) goto IF968;
	local[5]= makeint((eusinteger_t)1L);
	local[6]= makeint((eusinteger_t)0L);
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[5]= w;
	goto IF969;
IF968:
	local[5]= local[4];
	if (fqv[53]!=local[5]) goto IF970;
	local[5]= makeint((eusinteger_t)-1L);
	local[6]= makeint((eusinteger_t)0L);
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[5]= w;
	goto IF971;
IF970:
	local[5]= local[4];
	if (fqv[54]!=local[5]) goto IF972;
	local[5]= makeint((eusinteger_t)0L);
	local[6]= makeint((eusinteger_t)1L);
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[5]= w;
	goto IF973;
IF972:
	local[5]= local[4];
	if (fqv[55]!=local[5]) goto IF974;
	local[5]= makeint((eusinteger_t)0L);
	local[6]= makeint((eusinteger_t)-1L);
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[5]= w;
	goto IF975;
IF974:
	local[5]= local[4];
	if (fqv[33]!=local[5]) goto IF976;
	local[5]= makeint((eusinteger_t)0L);
	local[6]= makeint((eusinteger_t)0L);
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[5]= w;
	goto IF977;
IF976:
	local[5]= local[4];
	if (fqv[56]!=local[5]) goto IF978;
	local[5]= makeint((eusinteger_t)0L);
	local[6]= makeint((eusinteger_t)0L);
	local[7]= makeint((eusinteger_t)-1L);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[5]= w;
	goto IF979;
IF978:
	local[5]= NIL;
IF979:
IF977:
IF975:
IF973:
IF971:
IF969:
	w = local[5];
	local[4]= w;
IF966:
	argv[0]->c.obj.iv[14] = local[4];
	argv[0]->c.obj.iv[3] = makeflt(0.0000000000000000000000e+00);
	local[4]= (pointer)get_sym_func(fqv[34]);
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[35]));
	local[7]= fqv[36];
	local[8]= fqv[8];
	local[9]= local[2];
	local[10]= fqv[9];
	local[11]= local[3];
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)APPLY(ctx,9,local+4); /*apply*/
	if (argv[0]->c.obj.iv[4]!=NIL) goto IF980;
	argv[0]->c.obj.iv[4] = makeflt(-9.0000000000000000000000e+01);
	local[4]= argv[0]->c.obj.iv[4];
	goto IF981;
IF980:
	local[4]= NIL;
IF981:
	if (argv[0]->c.obj.iv[5]!=NIL) goto IF982;
	argv[0]->c.obj.iv[5] = makeflt(9.0000000000000000000000e+01);
	local[4]= argv[0]->c.obj.iv[5];
	goto IF983;
IF982:
	local[4]= NIL;
IF983:
	local[4]= argv[0];
	local[5]= fqv[37];
	local[6]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[38];
	local[6]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[39];
	local[6]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	w = argv[0];
	local[0]= w;
BLK960:
	ctx->vsp=local; return(local[0]);}

/*:joint-angle*/
static pointer M984linear_joint_joint_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT987;}
	local[0]= NIL;
ENT987:
ENT986:
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[57], &argv[3], n-3, local+1, 1);
	if (n & (1<<0)) goto KEY988;
	local[1] = NIL;
KEY988:
	if (local[0]==NIL) goto IF989;
	if (local[1]==NIL) goto IF991;
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[0] = w;
	local[2]= local[0];
	goto IF992;
IF991:
	local[2]= NIL;
IF992:
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto IF993;
	if (local[1]!=NIL) goto IF995;
	local[2]= makeint((eusinteger_t)3L);
	local[3]= fqv[58];
	local[4]= argv[0];
	local[5]= local[0];
	local[6]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+7;
	w=(*ftab[5])(ctx,5,local+2,&ftab[5],fqv[44]); /*warning-message*/
	local[2]= w;
	goto IF996;
IF995:
	local[2]= NIL;
IF996:
	local[0] = argv[0]->c.obj.iv[5];
	local[2]= local[0];
	goto IF994;
IF993:
	local[2]= NIL;
IF994:
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto IF997;
	if (local[1]!=NIL) goto IF999;
	local[2]= makeint((eusinteger_t)3L);
	local[3]= fqv[59];
	local[4]= argv[0];
	local[5]= local[0];
	local[6]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+7;
	w=(*ftab[5])(ctx,5,local+2,&ftab[5],fqv[44]); /*warning-message*/
	local[2]= w;
	goto IF1000;
IF999:
	local[2]= NIL;
IF1000:
	local[0] = argv[0]->c.obj.iv[4];
	local[2]= local[0];
	goto IF998;
IF997:
	local[2]= NIL;
IF998:
	argv[0]->c.obj.iv[3] = local[0];
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= fqv[46];
	local[4]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= fqv[60];
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+6;
	w=(pointer)SCALEVEC(ctx,2,local+4); /*scale*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF990;
IF989:
	local[2]= NIL;
IF990:
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK985:
	ctx->vsp=local; return(local[0]);}

/*:joint-dof*/
static pointer M1001linear_joint_joint_dof(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = makeint((eusinteger_t)1L);
	local[0]= w;
BLK1002:
	ctx->vsp=local; return(local[0]);}

/*:calc-angle-speed-gain*/
static pointer M1003linear_joint_calc_angle_speed_gain(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= argv[2];
	local[2]= argv[3];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)F763calc_angle_speed_gain_scalar(ctx,4,local+0); /*calc-angle-speed-gain-scalar*/
	local[0]= w;
BLK1004:
	ctx->vsp=local; return(local[0]);}

/*:speed-to-angle*/
static pointer M1005linear_joint_speed_to_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeint((eusinteger_t)1000L);
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
BLK1006:
	ctx->vsp=local; return(local[0]);}

/*:angle-to-speed*/
static pointer M1007linear_joint_angle_to_speed(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeflt(1.0000000000000000208167e-03);
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
BLK1008:
	ctx->vsp=local; return(local[0]);}

/*:calc-jacobian*/
static pointer M1009linear_joint_calc_jacobian(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1011:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[61]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[0]= w;
BLK1010:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1012wheel_joint_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1014:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[62], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY1015;
	local[5]= loadglobal(fqv[63]);
	local[6]= loadglobal(fqv[63]);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,2,local+5); /*float-vector*/
	local[1] = w;
KEY1015:
	if (n & (1<<1)) goto KEY1016;
	local[5]= loadglobal(fqv[64]);
	local[6]= loadglobal(fqv[64]);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,2,local+5); /*float-vector*/
	local[2] = w;
KEY1016:
	if (n & (1<<2)) goto KEY1017;
	local[5]= makeflt(7.9999999999999960031971e-02);
	local[6]= makeflt(4.9999999999999988897770e-02);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= makeflt(3.1415926535897931159980e+00);
	local[7]= makeint((eusinteger_t)4L);
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,2,local+5); /*float-vector*/
	local[3] = w;
KEY1017:
	if (n & (1<<3)) goto KEY1018;
	local[5]= makeint((eusinteger_t)100L);
	local[6]= makeint((eusinteger_t)100L);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,2,local+5); /*float-vector*/
	local[4] = w;
KEY1018:
	local[5]= makeint((eusinteger_t)0L);
	local[6]= makeint((eusinteger_t)0L);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,2,local+5); /*float-vector*/
	argv[0]->c.obj.iv[3] = w;
	local[5]= fqv[65];
	local[6]= fqv[33];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,2,local+5); /*list*/
	argv[0]->c.obj.iv[14] = w;
	local[5]= (pointer)get_sym_func(fqv[34]);
	local[6]= argv[0];
	local[7]= *(ovafptr(argv[1],fqv[35]));
	local[8]= fqv[36];
	local[9]= fqv[66];
	local[10]= local[1];
	local[11]= fqv[67];
	local[12]= local[2];
	local[13]= fqv[8];
	local[14]= local[3];
	local[15]= fqv[9];
	local[16]= local[4];
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)APPLY(ctx,13,local+5); /*apply*/
	w = argv[0];
	local[0]= w;
BLK1013:
	ctx->vsp=local; return(local[0]);}

/*:joint-angle*/
static pointer M1019wheel_joint_joint_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1022;}
	local[0]= NIL;
ENT1022:
ENT1021:
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[68], &argv[3], n-3, local+1, 1);
	if (n & (1<<0)) goto KEY1023;
	local[1] = NIL;
KEY1023:
	local[2]= NIL;
	local[3]= NIL;
	if (local[1]!=NIL) goto IF1024;
	if (local[0]==NIL) goto IF1026;
	local[4]= fqv[69];
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,1,local+4,&ftab[2],fqv[15]); /*warn*/
	local[4]= w;
	goto IF1027;
IF1026:
	local[4]= NIL;
IF1027:
	w = argv[0]->c.obj.iv[3];
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK1020;
	goto IF1025;
IF1024:
	local[4]= NIL;
IF1025:
	if (local[0]==NIL) goto IF1028;
	local[4]= local[0];
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[2] = w;
	local[4]= local[0];
	local[5]= makeint((eusinteger_t)1L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[3] = w;
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= fqv[60];
	local[6]= local[2];
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,3,local+6); /*float-vector*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= fqv[47];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(*ftab[6])(ctx,1,local+6,&ftab[6],fqv[48]); /*deg2rad*/
	local[6]= w;
	local[7]= fqv[33];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto IF1029;
IF1028:
	local[4]= NIL;
IF1029:
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK1020:
	ctx->vsp=local; return(local[0]);}

/*:joint-dof*/
static pointer M1030wheel_joint_joint_dof(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = makeint((eusinteger_t)2L);
	local[0]= w;
BLK1031:
	ctx->vsp=local; return(local[0]);}

/*:calc-angle-speed-gain*/
static pointer M1032wheel_joint_calc_angle_speed_gain(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= argv[2];
	local[2]= argv[3];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)F764calc_angle_speed_gain_vector(ctx,4,local+0); /*calc-angle-speed-gain-vector*/
	local[0]= w;
BLK1033:
	ctx->vsp=local; return(local[0]);}

/*:speed-to-angle*/
static pointer M1034wheel_joint_speed_to_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeint((eusinteger_t)1000L);
	local[1]= argv[2];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= argv[2];
	local[2]= makeint((eusinteger_t)1L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,1,local+1,&ftab[7],fqv[49]); /*rad2deg*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MKFLTVEC(ctx,2,local+0); /*float-vector*/
	local[0]= w;
BLK1035:
	ctx->vsp=local; return(local[0]);}

/*:angle-to-speed*/
static pointer M1036wheel_joint_angle_to_speed(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeflt(1.0000000000000000208167e-03);
	local[1]= argv[2];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= argv[2];
	local[2]= makeint((eusinteger_t)1L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[48]); /*deg2rad*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MKFLTVEC(ctx,2,local+0); /*float-vector*/
	local[0]= w;
BLK1037:
	ctx->vsp=local; return(local[0]);}

/*:calc-jacobian*/
static pointer M1038wheel_joint_calc_jacobian(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=21) maerror();
	w = argv[5];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[28],w);
	local[3]= argv[2];
	local[4]= argv[3];
	local[5]= argv[4];
	local[6]= loadglobal(fqv[28]);
	local[7]= fqv[70];
	local[8]= argv[7];
	local[9]= argv[8];
	local[10]= argv[9];
	local[11]= argv[10];
	local[12]= argv[11];
	local[13]= argv[12];
	local[14]= argv[13];
	local[15]= argv[14];
	local[16]= argv[15];
	local[17]= argv[16];
	local[18]= argv[17];
	local[19]= argv[18];
	local[20]= argv[19];
	local[21]= argv[20];
	ctx->vsp=local+22;
	w=(pointer)F762calc_jacobian_linear(ctx,19,local+3); /*calc-jacobian-linear*/
	local[3]= argv[2];
	local[4]= argv[3];
	local[5]= argv[4];
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= loadglobal(fqv[28]);
	local[7]= fqv[71];
	local[8]= argv[7];
	local[9]= argv[8];
	local[10]= argv[9];
	local[11]= argv[10];
	local[12]= argv[11];
	local[13]= argv[12];
	local[14]= argv[13];
	local[15]= argv[14];
	local[16]= argv[15];
	local[17]= argv[16];
	local[18]= argv[17];
	local[19]= argv[18];
	local[20]= argv[19];
	local[21]= argv[20];
	ctx->vsp=local+22;
	w=(pointer)F761calc_jacobian_rotational(ctx,19,local+3); /*calc-jacobian-rotational*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1039:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1040omniwheel_joint_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1042:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[72], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY1043;
	local[5]= loadglobal(fqv[63]);
	local[6]= loadglobal(fqv[63]);
	local[7]= loadglobal(fqv[63]);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[1] = w;
KEY1043:
	if (n & (1<<1)) goto KEY1044;
	local[5]= loadglobal(fqv[64]);
	local[6]= loadglobal(fqv[64]);
	local[7]= loadglobal(fqv[64]);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[2] = w;
KEY1044:
	if (n & (1<<2)) goto KEY1045;
	local[5]= makeflt(7.9999999999999960031971e-02);
	local[6]= makeflt(4.9999999999999988897770e-02);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= makeflt(7.9999999999999960031971e-02);
	local[7]= makeflt(4.9999999999999988897770e-02);
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	local[7]= makeflt(3.1415926535897931159980e+00);
	local[8]= makeint((eusinteger_t)4L);
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[3] = w;
KEY1045:
	if (n & (1<<3)) goto KEY1046;
	local[5]= makeint((eusinteger_t)100L);
	local[6]= makeint((eusinteger_t)100L);
	local[7]= makeint((eusinteger_t)100L);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[4] = w;
KEY1046:
	local[5]= makeint((eusinteger_t)0L);
	local[6]= makeint((eusinteger_t)0L);
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	argv[0]->c.obj.iv[3] = w;
	local[5]= fqv[73];
	local[6]= fqv[74];
	local[7]= fqv[33];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,3,local+5); /*list*/
	argv[0]->c.obj.iv[14] = w;
	local[5]= (pointer)get_sym_func(fqv[34]);
	local[6]= argv[0];
	local[7]= *(ovafptr(argv[1],fqv[35]));
	local[8]= fqv[36];
	local[9]= fqv[66];
	local[10]= local[1];
	local[11]= fqv[67];
	local[12]= local[2];
	local[13]= fqv[8];
	local[14]= local[3];
	local[15]= fqv[9];
	local[16]= local[4];
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)APPLY(ctx,13,local+5); /*apply*/
	w = argv[0];
	local[0]= w;
BLK1041:
	ctx->vsp=local; return(local[0]);}

/*:joint-angle*/
static pointer M1047omniwheel_joint_joint_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1050;}
	local[0]= NIL;
ENT1050:
ENT1049:
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[75], &argv[3], n-3, local+1, 1);
	if (n & (1<<0)) goto KEY1051;
	local[1] = NIL;
KEY1051:
	if (local[0]==NIL) goto IF1052;
	if (local[1]==NIL) goto IF1054;
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+4;
	w=(pointer)VPLUS(ctx,2,local+2); /*v+*/
	local[0] = w;
	local[2]= local[0];
	goto IF1055;
IF1054:
	local[2]= NIL;
IF1055:
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+4;
	w=(pointer)VMAX(ctx,2,local+2); /*vmax*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+4;
	w=(pointer)VMIN(ctx,2,local+2); /*vmin*/
	argv[0]->c.obj.iv[3] = w;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= fqv[46];
	local[4]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= fqv[60];
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[3];
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	local[6]= makeint((eusinteger_t)0L);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= fqv[47];
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= makeint((eusinteger_t)2L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[6])(ctx,1,local+4,&ftab[6],fqv[48]); /*deg2rad*/
	local[4]= w;
	local[5]= fqv[33];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	goto IF1053;
IF1052:
	local[2]= NIL;
IF1053:
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK1048:
	ctx->vsp=local; return(local[0]);}

/*:joint-dof*/
static pointer M1056omniwheel_joint_joint_dof(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = makeint((eusinteger_t)3L);
	local[0]= w;
BLK1057:
	ctx->vsp=local; return(local[0]);}

/*:calc-angle-speed-gain*/
static pointer M1058omniwheel_joint_calc_angle_speed_gain(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= argv[2];
	local[2]= argv[3];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)F764calc_angle_speed_gain_vector(ctx,4,local+0); /*calc-angle-speed-gain-vector*/
	local[0]= w;
BLK1059:
	ctx->vsp=local; return(local[0]);}

/*:speed-to-angle*/
static pointer M1060omniwheel_joint_speed_to_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeint((eusinteger_t)1000L);
	local[1]= argv[2];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1000L);
	local[2]= argv[2];
	local[3]= makeint((eusinteger_t)1L);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	local[2]= argv[2];
	local[3]= makeint((eusinteger_t)2L);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[7])(ctx,1,local+2,&ftab[7],fqv[49]); /*rad2deg*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
BLK1061:
	ctx->vsp=local; return(local[0]);}

/*:angle-to-speed*/
static pointer M1062omniwheel_joint_angle_to_speed(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeflt(1.0000000000000000208167e-03);
	local[1]= argv[2];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= makeflt(1.0000000000000000208167e-03);
	local[2]= argv[2];
	local[3]= makeint((eusinteger_t)1L);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	local[2]= argv[2];
	local[3]= makeint((eusinteger_t)2L);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[6])(ctx,1,local+2,&ftab[6],fqv[48]); /*deg2rad*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
BLK1063:
	ctx->vsp=local; return(local[0]);}

/*:calc-jacobian*/
static pointer M1064omniwheel_joint_calc_jacobian(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=21) maerror();
	w = argv[5];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[28],w);
	local[3]= argv[2];
	local[4]= argv[3];
	local[5]= argv[4];
	local[6]= loadglobal(fqv[28]);
	local[7]= fqv[76];
	local[8]= argv[7];
	local[9]= argv[8];
	local[10]= argv[9];
	local[11]= argv[10];
	local[12]= argv[11];
	local[13]= argv[12];
	local[14]= argv[13];
	local[15]= argv[14];
	local[16]= argv[15];
	local[17]= argv[16];
	local[18]= argv[17];
	local[19]= argv[18];
	local[20]= argv[19];
	local[21]= argv[20];
	ctx->vsp=local+22;
	w=(pointer)F762calc_jacobian_linear(ctx,19,local+3); /*calc-jacobian-linear*/
	local[3]= argv[2];
	local[4]= argv[3];
	local[5]= argv[4];
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= loadglobal(fqv[28]);
	local[7]= fqv[77];
	local[8]= argv[7];
	local[9]= argv[8];
	local[10]= argv[9];
	local[11]= argv[10];
	local[12]= argv[11];
	local[13]= argv[12];
	local[14]= argv[13];
	local[15]= argv[14];
	local[16]= argv[15];
	local[17]= argv[16];
	local[18]= argv[17];
	local[19]= argv[18];
	local[20]= argv[19];
	local[21]= argv[20];
	ctx->vsp=local+22;
	w=(pointer)F762calc_jacobian_linear(ctx,19,local+3); /*calc-jacobian-linear*/
	local[3]= argv[2];
	local[4]= argv[3];
	local[5]= argv[4];
	local[6]= makeint((eusinteger_t)2L);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= loadglobal(fqv[28]);
	local[7]= fqv[78];
	local[8]= argv[7];
	local[9]= argv[8];
	local[10]= argv[9];
	local[11]= argv[10];
	local[12]= argv[11];
	local[13]= argv[12];
	local[14]= argv[13];
	local[15]= argv[14];
	local[16]= argv[15];
	local[17]= argv[16];
	local[18]= argv[17];
	local[19]= argv[18];
	local[20]= argv[19];
	local[21]= argv[20];
	ctx->vsp=local+22;
	w=(pointer)F761calc_jacobian_rotational(ctx,19,local+3); /*calc-jacobian-rotational*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1065:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1066sphere_joint_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1068:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[79], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY1069;
	local[5]= loadglobal(fqv[63]);
	local[6]= loadglobal(fqv[63]);
	local[7]= loadglobal(fqv[63]);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[1] = w;
KEY1069:
	if (n & (1<<1)) goto KEY1070;
	local[5]= loadglobal(fqv[64]);
	local[6]= loadglobal(fqv[64]);
	local[7]= loadglobal(fqv[64]);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[2] = w;
KEY1070:
	if (n & (1<<2)) goto KEY1071;
	local[5]= makeflt(3.1415926535897931159980e+00);
	local[6]= makeint((eusinteger_t)4L);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= makeflt(3.1415926535897931159980e+00);
	local[7]= makeint((eusinteger_t)4L);
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	local[7]= makeflt(3.1415926535897931159980e+00);
	local[8]= makeint((eusinteger_t)4L);
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[3] = w;
KEY1071:
	if (n & (1<<3)) goto KEY1072;
	local[5]= makeint((eusinteger_t)100L);
	local[6]= makeint((eusinteger_t)100L);
	local[7]= makeint((eusinteger_t)100L);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[4] = w;
KEY1072:
	local[5]= fqv[52];
	local[6]= fqv[54];
	local[7]= fqv[33];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,3,local+5); /*list*/
	argv[0]->c.obj.iv[14] = w;
	local[5]= (pointer)get_sym_func(fqv[34]);
	local[6]= argv[0];
	local[7]= *(ovafptr(argv[1],fqv[35]));
	local[8]= fqv[36];
	local[9]= fqv[66];
	local[10]= local[1];
	local[11]= fqv[67];
	local[12]= local[2];
	local[13]= fqv[8];
	local[14]= local[3];
	local[15]= fqv[9];
	local[16]= local[4];
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)APPLY(ctx,13,local+5); /*apply*/
	local[5]= makeint((eusinteger_t)0L);
	local[6]= makeint((eusinteger_t)0L);
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	argv[0]->c.obj.iv[3] = w;
	w = argv[0];
	local[0]= w;
BLK1067:
	ctx->vsp=local; return(local[0]);}

/*:joint-angle*/
static pointer M1073sphere_joint_joint_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1076;}
	local[0]= NIL;
ENT1076:
ENT1075:
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[80], &argv[3], n-3, local+1, 1);
	if (n & (1<<0)) goto KEY1077;
	local[1] = NIL;
KEY1077:
	if (local[0]==NIL) goto IF1078;
	if (local[1]==NIL) goto CON1081;
	local[2]= loadglobal(fqv[5]);
	local[3]= (pointer)get_sym_func(fqv[48]);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)MAP(ctx,3,local+2); /*map*/
	local[2]= w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)VNORM(ctx,1,local+3); /*norm*/
	local[3]= w;
	local[4]= makeflt(0.0000000000000000000000e+00);
	local[5]= makeflt(9.9999999999999949376344e-21);
	ctx->vsp=local+6;
	w=(*ftab[8])(ctx,3,local+3,&ftab[8],fqv[81]); /*eps=*/
	if (w!=NIL) goto IF1082;
	local[3]= loadglobal(fqv[5]);
	local[4]= (pointer)get_sym_func(fqv[48]);
	local[5]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+6;
	w=(pointer)MAP(ctx,3,local+3); /*map*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[9])(ctx,1,local+3,&ftab[9],fqv[82]); /*matrix-exponent*/
	local[3]= w;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)VNORM(ctx,1,local+4); /*norm*/
	local[4]= w;
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,1,local+5,&ftab[4],fqv[26]); /*normalize-vector*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+4); /*rotation-matrix*/
	local[4]= w;
	local[5]= local[3];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)MATTIMES(ctx,3,local+4); /*m**/
	local[4]= loadglobal(fqv[5]);
	local[5]= (pointer)get_sym_func(fqv[49]);
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(*ftab[10])(ctx,1,local+6,&ftab[10],fqv[83]); /*matrix-log*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MAP(ctx,3,local+4); /*map*/
	argv[0]->c.obj.iv[3] = w;
	w = argv[0]->c.obj.iv[3];
	local[3]= w;
	goto IF1083;
IF1082:
	local[3]= NIL;
IF1083:
	w = local[3];
	local[2]= w;
	goto CON1080;
CON1081:
	argv[0]->c.obj.iv[3] = local[0];
	local[2]= argv[0]->c.obj.iv[3];
	goto CON1080;
CON1084:
	local[2]= NIL;
CON1080:
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+4;
	w=(pointer)VMAX(ctx,2,local+2); /*vmax*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+4;
	w=(pointer)VMIN(ctx,2,local+2); /*vmin*/
	argv[0]->c.obj.iv[3] = w;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= fqv[46];
	local[4]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= fqv[84];
	local[4]= fqv[85];
	local[5]= loadglobal(fqv[5]);
	local[6]= (pointer)get_sym_func(fqv[48]);
	local[7]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+8;
	w=(pointer)MAP(ctx,3,local+5); /*map*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[9])(ctx,1,local+5,&ftab[9],fqv[82]); /*matrix-exponent*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[11])(ctx,2,local+4,&ftab[11],fqv[86]); /*make-coords*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF1079;
IF1078:
	local[2]= NIL;
IF1079:
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK1074:
	ctx->vsp=local; return(local[0]);}

/*:joint-angle-rpy*/
static pointer M1085sphere_joint_joint_angle_rpy(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1088;}
	local[0]= NIL;
ENT1088:
ENT1087:
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[87], &argv[3], n-3, local+1, 0);
	if (n & (1<<0)) goto KEY1089;
	local[1] = NIL;
KEY1089:
	if (local[0]==NIL) goto IF1090;
	if (local[1]==NIL) goto IF1092;
	local[2]= loadglobal(fqv[5]);
	local[3]= (pointer)get_sym_func(fqv[48]);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)MAP(ctx,3,local+2); /*map*/
	local[2]= w;
	local[3]= loadglobal(fqv[5]);
	local[4]= (pointer)get_sym_func(fqv[48]);
	local[5]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+6;
	w=(pointer)MAP(ctx,3,local+3); /*map*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[9])(ctx,1,local+3,&ftab[9],fqv[82]); /*matrix-exponent*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)INV_RPY(ctx,1,local+3); /*rpy-angle*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= loadglobal(fqv[5]);
	ctx->vsp=local+5;
	w=(pointer)COERCE(ctx,2,local+3); /*coerce*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)VPLUS(ctx,2,local+2); /*v+*/
	local[2]= w;
	goto IF1093;
IF1092:
	local[2]= loadglobal(fqv[5]);
	local[3]= (pointer)get_sym_func(fqv[48]);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)MAP(ctx,3,local+2); /*map*/
	local[2]= w;
IF1093:
	local[3]= argv[0];
	local[4]= fqv[20];
	local[5]= loadglobal(fqv[88]);
	local[6]= (pointer)get_sym_func(fqv[49]);
	local[7]= local[2];
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	local[8]= local[2];
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	local[9]= local[2];
	local[10]= makeint((eusinteger_t)2L);
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[12])(ctx,3,local+7,&ftab[12],fqv[89]); /*rpy-matrix*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[10])(ctx,1,local+7,&ftab[10],fqv[83]); /*matrix-log*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MAP(ctx,3,local+5); /*map*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[2]= w;
	goto IF1091;
IF1090:
	local[2]= NIL;
IF1091:
	local[2]= loadglobal(fqv[5]);
	local[3]= (pointer)get_sym_func(fqv[49]);
	local[4]= loadglobal(fqv[5]);
	local[5]= (pointer)get_sym_func(fqv[48]);
	local[6]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+7;
	w=(pointer)MAP(ctx,3,local+4); /*map*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[9])(ctx,1,local+4,&ftab[9],fqv[82]); /*matrix-exponent*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)INV_RPY(ctx,1,local+4); /*rpy-angle*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)MAP(ctx,3,local+2); /*map*/
	local[0]= w;
BLK1086:
	ctx->vsp=local; return(local[0]);}

/*:joint-dof*/
static pointer M1094sphere_joint_joint_dof(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = makeint((eusinteger_t)3L);
	local[0]= w;
BLK1095:
	ctx->vsp=local; return(local[0]);}

/*:calc-angle-speed-gain*/
static pointer M1096sphere_joint_calc_angle_speed_gain(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= argv[2];
	local[2]= argv[3];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)F764calc_angle_speed_gain_vector(ctx,4,local+0); /*calc-angle-speed-gain-vector*/
	local[0]= w;
BLK1097:
	ctx->vsp=local; return(local[0]);}

/*:speed-to-angle*/
static pointer M1098sphere_joint_speed_to_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[7])(ctx,1,local+0,&ftab[7],fqv[49]); /*rad2deg*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= makeint((eusinteger_t)1L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,1,local+1,&ftab[7],fqv[49]); /*rad2deg*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= makeint((eusinteger_t)2L);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[7])(ctx,1,local+2,&ftab[7],fqv[49]); /*rad2deg*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
BLK1099:
	ctx->vsp=local; return(local[0]);}

/*:angle-to-speed*/
static pointer M1100sphere_joint_angle_to_speed(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[6])(ctx,1,local+0,&ftab[6],fqv[48]); /*deg2rad*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= makeint((eusinteger_t)1L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[48]); /*deg2rad*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= makeint((eusinteger_t)2L);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[6])(ctx,1,local+2,&ftab[6],fqv[48]); /*deg2rad*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
BLK1101:
	ctx->vsp=local; return(local[0]);}

/*:calc-jacobian*/
static pointer M1102sphere_joint_calc_jacobian(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=21) maerror();
	w = argv[5];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[28],w);
	local[3]= argv[2];
	local[4]= argv[3];
	local[5]= argv[4];
	local[6]= loadglobal(fqv[28]);
	local[7]= fqv[90];
	local[8]= argv[7];
	local[9]= argv[8];
	local[10]= argv[9];
	local[11]= argv[10];
	local[12]= argv[11];
	local[13]= argv[12];
	local[14]= argv[13];
	local[15]= argv[14];
	local[16]= argv[15];
	local[17]= argv[16];
	local[18]= argv[17];
	local[19]= argv[18];
	local[20]= argv[19];
	local[21]= argv[20];
	ctx->vsp=local+22;
	w=(pointer)F761calc_jacobian_rotational(ctx,19,local+3); /*calc-jacobian-rotational*/
	local[3]= argv[2];
	local[4]= argv[3];
	local[5]= argv[4];
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= loadglobal(fqv[28]);
	local[7]= fqv[91];
	local[8]= argv[7];
	local[9]= argv[8];
	local[10]= argv[9];
	local[11]= argv[10];
	local[12]= argv[11];
	local[13]= argv[12];
	local[14]= argv[13];
	local[15]= argv[14];
	local[16]= argv[15];
	local[17]= argv[16];
	local[18]= argv[17];
	local[19]= argv[18];
	local[20]= argv[19];
	local[21]= argv[20];
	ctx->vsp=local+22;
	w=(pointer)F761calc_jacobian_rotational(ctx,19,local+3); /*calc-jacobian-rotational*/
	local[3]= argv[2];
	local[4]= argv[3];
	local[5]= argv[4];
	local[6]= makeint((eusinteger_t)2L);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= loadglobal(fqv[28]);
	local[7]= fqv[92];
	local[8]= argv[7];
	local[9]= argv[8];
	local[10]= argv[9];
	local[11]= argv[10];
	local[12]= argv[11];
	local[13]= argv[12];
	local[14]= argv[13];
	local[15]= argv[14];
	local[16]= argv[15];
	local[17]= argv[16];
	local[18]= argv[17];
	local[19]= argv[18];
	local[20]= argv[19];
	local[21]= argv[20];
	ctx->vsp=local+22;
	w=(pointer)F761calc_jacobian_rotational(ctx,19,local+3); /*calc-jacobian-rotational*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1103:
	ctx->vsp=local; return(local[0]);}

/*:joint-euler-angle*/
static pointer M1104sphere_joint_joint_euler_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[93], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY1106;
	local[0] = fqv[94];
KEY1106:
	if (n & (1<<1)) goto KEY1107;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= fqv[85];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[1] = w;
KEY1107:
	local[2]= loadglobal(fqv[88]);
	local[3]= (pointer)get_sym_func(fqv[49]);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
	local[5]= local[4];
	if (fqv[95]!=local[5]) goto IF1109;
	local[5]= local[0];
	local[6]= makeint((eusinteger_t)0L);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	local[6]= local[5];
	if (fqv[54]!=local[6]) goto IF1112;
	local[6]= local[1];
	local[7]= makeint((eusinteger_t)2L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,1,local+6); /*-*/
	local[6]= w;
	local[7]= local[1];
	local[8]= makeint((eusinteger_t)2L);
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[13])(ctx,2,local+6,&ftab[13],fqv[96]); /*atan2*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	local[6]= w;
	goto IF1113;
IF1112:
	local[6]= local[5];
	if (fqv[52]!=local[6]) goto IF1114;
	local[6]= local[1];
	local[7]= makeint((eusinteger_t)2L);
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= local[1];
	local[8]= makeint((eusinteger_t)2L);
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[13])(ctx,2,local+6,&ftab[13],fqv[96]); /*atan2*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	local[6]= w;
	goto IF1115;
IF1114:
	local[6]= local[5];
	if (fqv[33]!=local[6]) goto IF1116;
	local[6]= local[1];
	local[7]= makeint((eusinteger_t)1L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,3,local+6); /*aref*/
	local[6]= w;
	local[7]= local[1];
	local[8]= makeint((eusinteger_t)1L);
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[13])(ctx,2,local+6,&ftab[13],fqv[96]); /*atan2*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	local[6]= w;
	goto IF1117;
IF1116:
	local[6]= NIL;
IF1117:
IF1115:
IF1113:
	w = local[6];
	local[5]= w;
	goto IF1110;
IF1109:
	local[5]= local[4];
	if (fqv[97]!=local[5]) goto IF1118;
	local[5]= local[0];
	local[6]= makeint((eusinteger_t)0L);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	local[6]= local[5];
	if (fqv[54]!=local[6]) goto IF1121;
	local[6]= local[0];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	local[7]= local[6];
	if (fqv[52]!=local[7]) goto IF1124;
	local[7]= local[1];
	local[8]= makeint((eusinteger_t)2L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,1,local+7); /*-*/
	local[7]= w;
	local[8]= local[1];
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[13])(ctx,2,local+7,&ftab[13],fqv[96]); /*atan2*/
	local[7]= w;
	local[8]= local[1];
	local[9]= makeint((eusinteger_t)1L);
	local[10]= makeint((eusinteger_t)2L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,1,local+8); /*-*/
	local[8]= w;
	local[9]= local[1];
	local[10]= makeint((eusinteger_t)1L);
	local[11]= makeint((eusinteger_t)1L);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,3,local+9); /*aref*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[96]); /*atan2*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	goto IF1125;
IF1124:
	local[7]= local[6];
	if (fqv[33]!=local[7]) goto IF1126;
	local[7]= local[1];
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	local[8]= local[1];
	local[9]= makeint((eusinteger_t)2L);
	local[10]= makeint((eusinteger_t)2L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[13])(ctx,2,local+7,&ftab[13],fqv[96]); /*atan2*/
	local[7]= w;
	local[8]= local[1];
	local[9]= makeint((eusinteger_t)1L);
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	local[9]= local[1];
	local[10]= makeint((eusinteger_t)1L);
	local[11]= makeint((eusinteger_t)1L);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,3,local+9); /*aref*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[96]); /*atan2*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	goto IF1127;
IF1126:
	local[7]= local[6];
	if (fqv[54]!=local[7]) goto IF1128;
	local[7]= makeint((eusinteger_t)0L);
	local[8]= local[1];
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)2L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	local[9]= local[1];
	local[10]= makeint((eusinteger_t)0L);
	local[11]= makeint((eusinteger_t)0L);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,3,local+9); /*aref*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[96]); /*atan2*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	goto IF1129;
IF1128:
	local[7]= NIL;
IF1129:
IF1127:
IF1125:
	w = local[7];
	local[6]= w;
	goto IF1122;
IF1121:
	local[6]= local[5];
	if (fqv[52]!=local[6]) goto IF1130;
	local[6]= local[0];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	local[7]= local[6];
	if (fqv[54]!=local[7]) goto IF1133;
	local[7]= local[1];
	local[8]= makeint((eusinteger_t)2L);
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	local[8]= local[1];
	local[9]= makeint((eusinteger_t)1L);
	local[10]= makeint((eusinteger_t)1L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[13])(ctx,2,local+7,&ftab[13],fqv[96]); /*atan2*/
	local[7]= w;
	local[8]= local[1];
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)2L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	local[9]= local[1];
	local[10]= makeint((eusinteger_t)0L);
	local[11]= makeint((eusinteger_t)0L);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,3,local+9); /*aref*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[96]); /*atan2*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	goto IF1134;
IF1133:
	local[7]= local[6];
	if (fqv[33]!=local[7]) goto IF1135;
	local[7]= local[1];
	local[8]= makeint((eusinteger_t)1L);
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,1,local+7); /*-*/
	local[7]= w;
	local[8]= local[1];
	local[9]= makeint((eusinteger_t)2L);
	local[10]= makeint((eusinteger_t)2L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[13])(ctx,2,local+7,&ftab[13],fqv[96]); /*atan2*/
	local[7]= w;
	local[8]= local[1];
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)1L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,1,local+8); /*-*/
	local[8]= w;
	local[9]= local[1];
	local[10]= makeint((eusinteger_t)0L);
	local[11]= makeint((eusinteger_t)0L);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,3,local+9); /*aref*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[96]); /*atan2*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	goto IF1136;
IF1135:
	local[7]= local[6];
	if (fqv[52]!=local[7]) goto IF1137;
	local[7]= makeint((eusinteger_t)0L);
	local[8]= local[1];
	local[9]= makeint((eusinteger_t)2L);
	local[10]= makeint((eusinteger_t)1L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	local[9]= local[1];
	local[10]= makeint((eusinteger_t)2L);
	local[11]= makeint((eusinteger_t)2L);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,3,local+9); /*aref*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[96]); /*atan2*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	goto IF1138;
IF1137:
	local[7]= NIL;
IF1138:
IF1136:
IF1134:
	w = local[7];
	local[6]= w;
	goto IF1131;
IF1130:
	local[6]= local[5];
	if (fqv[33]!=local[6]) goto IF1139;
	local[6]= local[0];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	local[7]= local[6];
	if (fqv[54]!=local[7]) goto IF1142;
	local[7]= local[1];
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,1,local+7); /*-*/
	local[7]= w;
	local[8]= local[1];
	local[9]= makeint((eusinteger_t)1L);
	local[10]= makeint((eusinteger_t)1L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[13])(ctx,2,local+7,&ftab[13],fqv[96]); /*atan2*/
	local[7]= w;
	local[8]= local[1];
	local[9]= makeint((eusinteger_t)2L);
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,1,local+8); /*-*/
	local[8]= w;
	local[9]= local[1];
	local[10]= makeint((eusinteger_t)2L);
	local[11]= makeint((eusinteger_t)2L);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,3,local+9); /*aref*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[96]); /*atan2*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	goto IF1143;
IF1142:
	local[7]= local[6];
	if (fqv[52]!=local[7]) goto IF1144;
	local[7]= local[1];
	local[8]= makeint((eusinteger_t)1L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	local[8]= local[1];
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[13])(ctx,2,local+7,&ftab[13],fqv[96]); /*atan2*/
	local[7]= w;
	local[8]= local[1];
	local[9]= makeint((eusinteger_t)2L);
	local[10]= makeint((eusinteger_t)1L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	local[9]= local[1];
	local[10]= makeint((eusinteger_t)2L);
	local[11]= makeint((eusinteger_t)2L);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,3,local+9); /*aref*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[96]); /*atan2*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	goto IF1145;
IF1144:
	local[7]= local[6];
	if (fqv[33]!=local[7]) goto IF1146;
	local[7]= makeint((eusinteger_t)0L);
	local[8]= local[1];
	local[9]= makeint((eusinteger_t)1L);
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	local[9]= local[1];
	local[10]= makeint((eusinteger_t)1L);
	local[11]= makeint((eusinteger_t)1L);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,3,local+9); /*aref*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[96]); /*atan2*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	goto IF1147;
IF1146:
	local[7]= NIL;
IF1147:
IF1145:
IF1143:
	w = local[7];
	local[6]= w;
	goto IF1140;
IF1139:
	local[6]= NIL;
IF1140:
IF1131:
IF1122:
	w = local[6];
	local[5]= w;
	goto IF1119;
IF1118:
	local[5]= local[4];
	if (fqv[98]!=local[5]) goto IF1148;
	local[5]= local[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[14])(ctx,2,local+5,&ftab[14],fqv[99]); /*matrix-to-euler-angle*/
	local[5]= w;
	goto IF1149;
IF1148:
	local[5]= NIL;
IF1149:
IF1119:
IF1110:
	w = local[5];
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MAP(ctx,3,local+2); /*map*/
	local[0]= w;
BLK1105:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M11506dof_joint_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1152:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[100], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY1153;
	local[6]= loadglobal(fqv[63]);
	local[7]= loadglobal(fqv[63]);
	local[8]= loadglobal(fqv[63]);
	local[9]= loadglobal(fqv[63]);
	local[10]= loadglobal(fqv[63]);
	local[11]= loadglobal(fqv[63]);
	ctx->vsp=local+12;
	w=(pointer)MKFLTVEC(ctx,6,local+6); /*float-vector*/
	local[1] = w;
KEY1153:
	if (n & (1<<1)) goto KEY1154;
	local[6]= loadglobal(fqv[64]);
	local[7]= loadglobal(fqv[64]);
	local[8]= loadglobal(fqv[64]);
	local[9]= loadglobal(fqv[64]);
	local[10]= loadglobal(fqv[64]);
	local[11]= loadglobal(fqv[64]);
	ctx->vsp=local+12;
	w=(pointer)MKFLTVEC(ctx,6,local+6); /*float-vector*/
	local[2] = w;
KEY1154:
	if (n & (1<<2)) goto KEY1155;
	local[6]= makeflt(7.9999999999999960031971e-02);
	local[7]= makeflt(4.9999999999999988897770e-02);
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	local[7]= makeflt(7.9999999999999960031971e-02);
	local[8]= makeflt(4.9999999999999988897770e-02);
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	local[7]= w;
	local[8]= makeflt(7.9999999999999960031971e-02);
	local[9]= makeflt(4.9999999999999988897770e-02);
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	local[9]= makeflt(3.1415926535897931159980e+00);
	local[10]= makeint((eusinteger_t)4L);
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	local[10]= makeflt(3.1415926535897931159980e+00);
	local[11]= makeint((eusinteger_t)4L);
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[10]= w;
	local[11]= makeflt(3.1415926535897931159980e+00);
	local[12]= makeint((eusinteger_t)4L);
	ctx->vsp=local+13;
	w=(pointer)QUOTIENT(ctx,2,local+11); /*/*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)MKFLTVEC(ctx,6,local+6); /*float-vector*/
	local[3] = w;
KEY1155:
	if (n & (1<<3)) goto KEY1156;
	local[6]= makeint((eusinteger_t)100L);
	local[7]= makeint((eusinteger_t)100L);
	local[8]= makeint((eusinteger_t)100L);
	local[9]= makeint((eusinteger_t)100L);
	local[10]= makeint((eusinteger_t)100L);
	local[11]= makeint((eusinteger_t)100L);
	ctx->vsp=local+12;
	w=(pointer)MKFLTVEC(ctx,6,local+6); /*float-vector*/
	local[4] = w;
KEY1156:
	if (n & (1<<4)) goto KEY1157;
	local[5] = NIL;
KEY1157:
	local[6]= fqv[101];
	local[7]= fqv[102];
	local[8]= fqv[103];
	local[9]= fqv[52];
	local[10]= fqv[54];
	local[11]= fqv[33];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,6,local+6); /*list*/
	argv[0]->c.obj.iv[14] = w;
	local[6]= (pointer)get_sym_func(fqv[34]);
	local[7]= argv[0];
	local[8]= *(ovafptr(argv[1],fqv[35]));
	local[9]= fqv[36];
	local[10]= fqv[66];
	local[11]= local[1];
	local[12]= fqv[67];
	local[13]= local[2];
	local[14]= fqv[8];
	local[15]= local[3];
	local[16]= fqv[9];
	local[17]= local[4];
	local[18]= local[0];
	ctx->vsp=local+19;
	w=(pointer)APPLY(ctx,13,local+6); /*apply*/
	if (local[5]==NIL) goto IF1158;
	local[6]= argv[0]->c.obj.iv[1];
	local[7]= fqv[104];
	local[8]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	local[7]= fqv[105];
	local[8]= argv[0]->c.obj.iv[6];
	local[9]= fqv[29];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[11])(ctx,2,local+7,&ftab[11],fqv[86]); /*make-coords*/
	local[7]= w;
	local[8]= local[7];
	local[9]= fqv[106];
	local[10]= local[6];
	local[11]= fqv[29];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	local[9]= local[7];
	local[10]= fqv[27];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)TRANSPOSE(ctx,1,local+9); /*transpose*/
	local[9]= w;
	local[10]= local[6];
	local[11]= fqv[27];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)MATTIMES(ctx,2,local+9); /*m**/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[10])(ctx,1,local+9,&ftab[10],fqv[83]); /*matrix-log*/
	local[9]= w;
	local[10]= local[8];
	local[11]= makeint((eusinteger_t)0L);
	ctx->vsp=local+12;
	w=(pointer)ELT(ctx,2,local+10); /*elt*/
	local[10]= w;
	local[11]= local[8];
	local[12]= makeint((eusinteger_t)1L);
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	local[12]= local[8];
	local[13]= makeint((eusinteger_t)2L);
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[12]= w;
	local[13]= local[9];
	local[14]= makeint((eusinteger_t)0L);
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(*ftab[7])(ctx,1,local+13,&ftab[7],fqv[49]); /*rad2deg*/
	local[13]= w;
	local[14]= local[9];
	local[15]= makeint((eusinteger_t)1L);
	ctx->vsp=local+16;
	w=(pointer)ELT(ctx,2,local+14); /*elt*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(*ftab[7])(ctx,1,local+14,&ftab[7],fqv[49]); /*rad2deg*/
	local[14]= w;
	local[15]= local[9];
	local[16]= makeint((eusinteger_t)2L);
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(*ftab[7])(ctx,1,local+15,&ftab[7],fqv[49]); /*rad2deg*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)MKFLTVEC(ctx,6,local+10); /*float-vector*/
	argv[0]->c.obj.iv[3] = w;
	argv[0]->c.obj.iv[6] = local[7];
	w = argv[0]->c.obj.iv[6];
	local[6]= w;
	goto IF1159;
IF1158:
	local[6]= makeint((eusinteger_t)0L);
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)0L);
	local[11]= makeint((eusinteger_t)0L);
	ctx->vsp=local+12;
	w=(pointer)MKFLTVEC(ctx,6,local+6); /*float-vector*/
	argv[0]->c.obj.iv[3] = w;
	local[6]= argv[0]->c.obj.iv[3];
IF1159:
	w = argv[0];
	local[0]= w;
BLK1151:
	ctx->vsp=local; return(local[0]);}

/*:joint-angle*/
static pointer M11606dof_joint_joint_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1163;}
	local[0]= NIL;
ENT1163:
ENT1162:
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[107], &argv[3], n-3, local+1, 1);
	if (n & (1<<0)) goto KEY1164;
	local[1] = NIL;
KEY1164:
	if (local[0]==NIL) goto IF1165;
	local[2]= NIL;
	local[3]= NIL;
	if (local[1]==NIL) goto IF1167;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= makeint((eusinteger_t)0L);
	local[6]= makeint((eusinteger_t)3L);
	ctx->vsp=local+7;
	w=(pointer)SUBSEQ(ctx,3,local+4); /*subseq*/
	local[4]= w;
	local[5]= local[0];
	local[6]= makeint((eusinteger_t)0L);
	local[7]= makeint((eusinteger_t)3L);
	ctx->vsp=local+8;
	w=(pointer)SUBSEQ(ctx,3,local+5); /*subseq*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)VPLUS(ctx,2,local+4); /*v+*/
	local[4]= w;
	goto IF1168;
IF1167:
	local[4]= local[0];
	local[5]= makeint((eusinteger_t)0L);
	local[6]= makeint((eusinteger_t)3L);
	ctx->vsp=local+7;
	w=(pointer)SUBSEQ(ctx,3,local+4); /*subseq*/
	local[4]= w;
IF1168:
	local[2] = local[4];
	if (local[1]==NIL) goto CON1170;
	local[4]= loadglobal(fqv[5]);
	local[5]= (pointer)get_sym_func(fqv[48]);
	local[6]= local[0];
	local[7]= makeint((eusinteger_t)3L);
	local[8]= makeint((eusinteger_t)6L);
	ctx->vsp=local+9;
	w=(pointer)SUBSEQ(ctx,3,local+6); /*subseq*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MAP(ctx,3,local+4); /*map*/
	local[4]= w;
	local[5]= local[4];
	ctx->vsp=local+6;
	w=(pointer)VNORM(ctx,1,local+5); /*norm*/
	local[5]= w;
	local[6]= makeflt(0.0000000000000000000000e+00);
	local[7]= makeflt(9.9999999999999949376344e-21);
	ctx->vsp=local+8;
	w=(*ftab[8])(ctx,3,local+5,&ftab[8],fqv[81]); /*eps=*/
	if (w==NIL) goto IF1171;
	local[5]= argv[0]->c.obj.iv[3];
	local[6]= makeint((eusinteger_t)3L);
	local[7]= makeint((eusinteger_t)6L);
	ctx->vsp=local+8;
	w=(pointer)SUBSEQ(ctx,3,local+5); /*subseq*/
	local[3] = w;
	local[5]= local[3];
	goto IF1172;
IF1171:
	local[5]= loadglobal(fqv[5]);
	local[6]= (pointer)get_sym_func(fqv[48]);
	local[7]= argv[0]->c.obj.iv[3];
	local[8]= makeint((eusinteger_t)3L);
	local[9]= makeint((eusinteger_t)6L);
	ctx->vsp=local+10;
	w=(pointer)SUBSEQ(ctx,3,local+7); /*subseq*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MAP(ctx,3,local+5); /*map*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[9])(ctx,1,local+5,&ftab[9],fqv[82]); /*matrix-exponent*/
	local[5]= w;
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)VNORM(ctx,1,local+6); /*norm*/
	local[6]= w;
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(*ftab[4])(ctx,1,local+7,&ftab[4],fqv[26]); /*normalize-vector*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+6); /*rotation-matrix*/
	local[6]= w;
	local[7]= local[5];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)MATTIMES(ctx,3,local+6); /*m**/
	local[6]= loadglobal(fqv[5]);
	local[7]= (pointer)get_sym_func(fqv[49]);
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(*ftab[10])(ctx,1,local+8,&ftab[10],fqv[83]); /*matrix-log*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MAP(ctx,3,local+6); /*map*/
	local[3] = w;
	w = local[3];
	local[5]= w;
IF1172:
	w = local[5];
	local[4]= w;
	goto CON1169;
CON1170:
	local[4]= local[0];
	local[5]= makeint((eusinteger_t)3L);
	local[6]= makeint((eusinteger_t)6L);
	ctx->vsp=local+7;
	w=(pointer)SUBSEQ(ctx,3,local+4); /*subseq*/
	local[3] = w;
	local[4]= local[3];
	goto CON1169;
CON1173:
	local[4]= NIL;
CON1169:
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)3L);
WHL1175:
	local[6]= local[4];
	w = local[5];
	if ((eusinteger_t)local[6] >= (eusinteger_t)w) goto WHX1176;
	local[6]= argv[0]->c.obj.iv[3];
	local[7]= local[4];
	local[8]= local[2];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SETELT(ctx,3,local+6); /*setelt*/
	local[6]= argv[0]->c.obj.iv[3];
	local[7]= local[4];
	w = makeint((eusinteger_t)3L);
#if sun4 || vax || mips || alpha || Linux
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[7]= (pointer)((eusinteger_t)local[7] + (eusinteger_t)w);
	local[8]= local[3];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SETELT(ctx,3,local+6); /*setelt*/
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[4] = w;
	goto WHL1175;
WHX1176:
	local[6]= NIL;
BLK1177:
	w = NIL;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+6;
	w=(pointer)VMAX(ctx,2,local+4); /*vmax*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+6;
	w=(pointer)VMIN(ctx,2,local+4); /*vmin*/
	argv[0]->c.obj.iv[3] = w;
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= fqv[46];
	local[6]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= fqv[84];
	local[6]= fqv[85];
	local[7]= loadglobal(fqv[5]);
	local[8]= (pointer)get_sym_func(fqv[48]);
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)MAP(ctx,3,local+7); /*map*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[9])(ctx,1,local+7,&ftab[9],fqv[82]); /*matrix-exponent*/
	local[7]= w;
	local[8]= fqv[105];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(*ftab[11])(ctx,4,local+6,&ftab[11],fqv[86]); /*make-coords*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[2]= w;
	goto IF1166;
IF1165:
	local[2]= NIL;
IF1166:
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK1161:
	ctx->vsp=local; return(local[0]);}

/*:joint-angle-rpy*/
static pointer M11786dof_joint_joint_angle_rpy(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1181;}
	local[0]= NIL;
ENT1181:
ENT1180:
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[108], &argv[3], n-3, local+1, 0);
	if (n & (1<<0)) goto KEY1182;
	local[1] = NIL;
KEY1182:
	if (local[0]==NIL) goto IF1183;
	if (local[1]==NIL) goto IF1185;
	local[2]= loadglobal(fqv[5]);
	local[3]= (pointer)get_sym_func(fqv[48]);
	local[4]= local[0];
	local[5]= makeint((eusinteger_t)3L);
	local[6]= makeint((eusinteger_t)6L);
	ctx->vsp=local+7;
	w=(pointer)SUBSEQ(ctx,3,local+4); /*subseq*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MAP(ctx,3,local+2); /*map*/
	local[2]= w;
	local[3]= loadglobal(fqv[5]);
	local[4]= (pointer)get_sym_func(fqv[48]);
	local[5]= argv[0]->c.obj.iv[3];
	local[6]= makeint((eusinteger_t)3L);
	local[7]= makeint((eusinteger_t)6L);
	ctx->vsp=local+8;
	w=(pointer)SUBSEQ(ctx,3,local+5); /*subseq*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MAP(ctx,3,local+3); /*map*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[9])(ctx,1,local+3,&ftab[9],fqv[82]); /*matrix-exponent*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)INV_RPY(ctx,1,local+3); /*rpy-angle*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= loadglobal(fqv[5]);
	ctx->vsp=local+5;
	w=(pointer)COERCE(ctx,2,local+3); /*coerce*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)VPLUS(ctx,2,local+2); /*v+*/
	local[2]= w;
	goto IF1186;
IF1185:
	local[2]= loadglobal(fqv[5]);
	local[3]= (pointer)get_sym_func(fqv[48]);
	local[4]= local[0];
	local[5]= makeint((eusinteger_t)3L);
	local[6]= makeint((eusinteger_t)6L);
	ctx->vsp=local+7;
	w=(pointer)SUBSEQ(ctx,3,local+4); /*subseq*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MAP(ctx,3,local+2); /*map*/
	local[2]= w;
IF1186:
	local[3]= argv[0];
	local[4]= fqv[20];
	local[5]= loadglobal(fqv[5]);
	local[6]= local[0];
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)3L);
	ctx->vsp=local+9;
	w=(pointer)SUBSEQ(ctx,3,local+6); /*subseq*/
	local[6]= w;
	local[7]= loadglobal(fqv[88]);
	local[8]= (pointer)get_sym_func(fqv[49]);
	local[9]= local[2];
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	local[10]= local[2];
	local[11]= makeint((eusinteger_t)1L);
	ctx->vsp=local+12;
	w=(pointer)ELT(ctx,2,local+10); /*elt*/
	local[10]= w;
	local[11]= local[2];
	local[12]= makeint((eusinteger_t)2L);
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[12])(ctx,3,local+9,&ftab[12],fqv[89]); /*rpy-matrix*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[10])(ctx,1,local+9,&ftab[10],fqv[83]); /*matrix-log*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MAP(ctx,3,local+7); /*map*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)CONCATENATE(ctx,3,local+5); /*concatenate*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[2]= w;
	goto IF1184;
IF1183:
	local[2]= NIL;
IF1184:
	local[2]= loadglobal(fqv[5]);
	local[3]= argv[0]->c.obj.iv[3];
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)3L);
	ctx->vsp=local+6;
	w=(pointer)SUBSEQ(ctx,3,local+3); /*subseq*/
	local[3]= w;
	local[4]= loadglobal(fqv[5]);
	local[5]= (pointer)get_sym_func(fqv[49]);
	local[6]= loadglobal(fqv[5]);
	local[7]= (pointer)get_sym_func(fqv[48]);
	local[8]= argv[0]->c.obj.iv[3];
	local[9]= makeint((eusinteger_t)3L);
	local[10]= makeint((eusinteger_t)6L);
	ctx->vsp=local+11;
	w=(pointer)SUBSEQ(ctx,3,local+8); /*subseq*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MAP(ctx,3,local+6); /*map*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[9])(ctx,1,local+6,&ftab[9],fqv[82]); /*matrix-exponent*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)INV_RPY(ctx,1,local+6); /*rpy-angle*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)MAP(ctx,3,local+4); /*map*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)CONCATENATE(ctx,3,local+2); /*concatenate*/
	local[0]= w;
BLK1179:
	ctx->vsp=local; return(local[0]);}

/*:joint-dof*/
static pointer M11876dof_joint_joint_dof(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = makeint((eusinteger_t)6L);
	local[0]= w;
BLK1188:
	ctx->vsp=local; return(local[0]);}

/*:calc-angle-speed-gain*/
static pointer M11896dof_joint_calc_angle_speed_gain(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= argv[2];
	local[2]= argv[3];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)F764calc_angle_speed_gain_vector(ctx,4,local+0); /*calc-angle-speed-gain-vector*/
	local[0]= w;
BLK1190:
	ctx->vsp=local; return(local[0]);}

/*:speed-to-angle*/
static pointer M11916dof_joint_speed_to_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeint((eusinteger_t)1000L);
	local[1]= argv[2];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1000L);
	local[2]= argv[2];
	local[3]= makeint((eusinteger_t)1L);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	local[2]= makeint((eusinteger_t)1000L);
	local[3]= argv[2];
	local[4]= makeint((eusinteger_t)2L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= argv[2];
	local[4]= makeint((eusinteger_t)3L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[7])(ctx,1,local+3,&ftab[7],fqv[49]); /*rad2deg*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= makeint((eusinteger_t)4L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[7])(ctx,1,local+4,&ftab[7],fqv[49]); /*rad2deg*/
	local[4]= w;
	local[5]= argv[2];
	local[6]= makeint((eusinteger_t)5L);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[7])(ctx,1,local+5,&ftab[7],fqv[49]); /*rad2deg*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,6,local+0); /*float-vector*/
	local[0]= w;
BLK1192:
	ctx->vsp=local; return(local[0]);}

/*:angle-to-speed*/
static pointer M11936dof_joint_angle_to_speed(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeflt(1.0000000000000000208167e-03);
	local[1]= argv[2];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= makeflt(1.0000000000000000208167e-03);
	local[2]= argv[2];
	local[3]= makeint((eusinteger_t)1L);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	local[2]= makeflt(1.0000000000000000208167e-03);
	local[3]= argv[2];
	local[4]= makeint((eusinteger_t)2L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= argv[2];
	local[4]= makeint((eusinteger_t)3L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,1,local+3,&ftab[6],fqv[48]); /*deg2rad*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= makeint((eusinteger_t)4L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[6])(ctx,1,local+4,&ftab[6],fqv[48]); /*deg2rad*/
	local[4]= w;
	local[5]= argv[2];
	local[6]= makeint((eusinteger_t)5L);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[6])(ctx,1,local+5,&ftab[6],fqv[48]); /*deg2rad*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,6,local+0); /*float-vector*/
	local[0]= w;
BLK1194:
	ctx->vsp=local; return(local[0]);}

/*:calc-jacobian*/
static pointer M11956dof_joint_calc_jacobian(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=21) maerror();
	w = argv[5];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[28],w);
	local[3]= argv[2];
	local[4]= argv[3];
	local[5]= argv[4];
	local[6]= loadglobal(fqv[28]);
	local[7]= fqv[109];
	local[8]= argv[7];
	local[9]= argv[8];
	local[10]= argv[9];
	local[11]= argv[10];
	local[12]= argv[11];
	local[13]= argv[12];
	local[14]= argv[13];
	local[15]= argv[14];
	local[16]= argv[15];
	local[17]= argv[16];
	local[18]= argv[17];
	local[19]= argv[18];
	local[20]= argv[19];
	local[21]= argv[20];
	ctx->vsp=local+22;
	w=(pointer)F762calc_jacobian_linear(ctx,19,local+3); /*calc-jacobian-linear*/
	local[3]= argv[2];
	local[4]= argv[3];
	local[5]= argv[4];
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= loadglobal(fqv[28]);
	local[7]= fqv[110];
	local[8]= argv[7];
	local[9]= argv[8];
	local[10]= argv[9];
	local[11]= argv[10];
	local[12]= argv[11];
	local[13]= argv[12];
	local[14]= argv[13];
	local[15]= argv[14];
	local[16]= argv[15];
	local[17]= argv[16];
	local[18]= argv[17];
	local[19]= argv[18];
	local[20]= argv[19];
	local[21]= argv[20];
	ctx->vsp=local+22;
	w=(pointer)F762calc_jacobian_linear(ctx,19,local+3); /*calc-jacobian-linear*/
	local[3]= argv[2];
	local[4]= argv[3];
	local[5]= argv[4];
	local[6]= makeint((eusinteger_t)2L);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= loadglobal(fqv[28]);
	local[7]= fqv[111];
	local[8]= argv[7];
	local[9]= argv[8];
	local[10]= argv[9];
	local[11]= argv[10];
	local[12]= argv[11];
	local[13]= argv[12];
	local[14]= argv[13];
	local[15]= argv[14];
	local[16]= argv[15];
	local[17]= argv[16];
	local[18]= argv[17];
	local[19]= argv[18];
	local[20]= argv[19];
	local[21]= argv[20];
	ctx->vsp=local+22;
	w=(pointer)F762calc_jacobian_linear(ctx,19,local+3); /*calc-jacobian-linear*/
	local[3]= argv[2];
	local[4]= argv[3];
	local[5]= argv[4];
	local[6]= makeint((eusinteger_t)3L);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= loadglobal(fqv[28]);
	local[7]= fqv[112];
	local[8]= argv[7];
	local[9]= argv[8];
	local[10]= argv[9];
	local[11]= argv[10];
	local[12]= argv[11];
	local[13]= argv[12];
	local[14]= argv[13];
	local[15]= argv[14];
	local[16]= argv[15];
	local[17]= argv[16];
	local[18]= argv[17];
	local[19]= argv[18];
	local[20]= argv[19];
	local[21]= argv[20];
	ctx->vsp=local+22;
	w=(pointer)F761calc_jacobian_rotational(ctx,19,local+3); /*calc-jacobian-rotational*/
	local[3]= argv[2];
	local[4]= argv[3];
	local[5]= argv[4];
	local[6]= makeint((eusinteger_t)4L);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= loadglobal(fqv[28]);
	local[7]= fqv[113];
	local[8]= argv[7];
	local[9]= argv[8];
	local[10]= argv[9];
	local[11]= argv[10];
	local[12]= argv[11];
	local[13]= argv[12];
	local[14]= argv[13];
	local[15]= argv[14];
	local[16]= argv[15];
	local[17]= argv[16];
	local[18]= argv[17];
	local[19]= argv[18];
	local[20]= argv[19];
	local[21]= argv[20];
	ctx->vsp=local+22;
	w=(pointer)F761calc_jacobian_rotational(ctx,19,local+3); /*calc-jacobian-rotational*/
	local[3]= argv[2];
	local[4]= argv[3];
	local[5]= argv[4];
	local[6]= makeint((eusinteger_t)5L);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= loadglobal(fqv[28]);
	local[7]= fqv[114];
	local[8]= argv[7];
	local[9]= argv[8];
	local[10]= argv[9];
	local[11]= argv[10];
	local[12]= argv[11];
	local[13]= argv[12];
	local[14]= argv[13];
	local[15]= argv[14];
	local[16]= argv[15];
	local[17]= argv[16];
	local[18]= argv[17];
	local[19]= argv[18];
	local[20]= argv[19];
	local[21]= argv[20];
	ctx->vsp=local+22;
	w=(pointer)F761calc_jacobian_rotational(ctx,19,local+3); /*calc-jacobian-rotational*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1196:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1197bodyset_link_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST1199:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[115], &argv[3], n-3, local+1, 1);
	if (n & (1<<0)) goto KEY1200;
	local[1] = fqv[116];
KEY1200:
	if (n & (1<<1)) goto KEY1201;
	local[2] = makeint((eusinteger_t)1L);
KEY1201:
	if (n & (1<<2)) goto KEY1202;
	local[3] = fqv[117];
KEY1202:
	if (n & (1<<3)) goto KEY1203;
	local[5]= makeint((eusinteger_t)3L);
	ctx->vsp=local+6;
	w=(*ftab[15])(ctx,1,local+5,&ftab[15],fqv[118]); /*unit-matrix*/
	local[4] = w;
KEY1203:
	argv[0]->c.obj.iv[12] = local[1];
	argv[0]->c.obj.iv[14] = local[2];
	argv[0]->c.obj.iv[16] = local[4];
	argv[0]->c.obj.iv[15] = local[3];
	local[5]= argv[0];
	local[6]= fqv[119];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= (pointer)get_sym_func(fqv[34]);
	local[6]= argv[0];
	local[7]= *(ovafptr(argv[1],fqv[35]));
	local[8]= fqv[36];
	local[9]= argv[2];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)APPLY(ctx,6,local+5); /*apply*/
	local[0]= w;
BLK1198:
	ctx->vsp=local; return(local[0]);}

/*:worldcoords*/
static pointer M1204bodyset_link_worldcoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1207;}
	local[0]= argv[0]->c.obj.iv[12];
ENT1207:
ENT1206:
	if (n>3) maerror();
	local[1]= local[0];
	local[2]= local[1];
	if (fqv[120]!=local[2]) goto IF1209;
	local[2]= argv[0];
	local[3]= loadglobal(fqv[121]);
	local[4]= fqv[122];
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,3,local+2); /*send-message*/
	local[2]= w;
	goto IF1210;
IF1209:
	if (T==NIL) goto IF1211;
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[35]));
	local[4]= fqv[122];
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,3,local+2); /*send-message*/
	local[2]= w;
	goto IF1212;
IF1211:
	local[2]= NIL;
IF1212:
IF1210:
	w = local[2];
	local[0]= w;
BLK1205:
	ctx->vsp=local; return(local[0]);}

/*:analysis-level*/
static pointer M1213bodyset_link_analysis_level(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1216;}
	local[0]= NIL;
ENT1216:
ENT1215:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1217;
	argv[0]->c.obj.iv[12] = local[0];
	local[1]= argv[0]->c.obj.iv[12];
	goto IF1218;
IF1217:
	local[1]= NIL;
IF1218:
	w = argv[0]->c.obj.iv[12];
	local[0]= w;
BLK1214:
	ctx->vsp=local; return(local[0]);}

/*:weight*/
static pointer M1219bodyset_link_weight(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1222;}
	local[0]= NIL;
ENT1222:
ENT1221:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1223;
	argv[0]->c.obj.iv[14] = local[0];
	local[1]= argv[0]->c.obj.iv[14];
	goto IF1224;
IF1223:
	local[1]= NIL;
IF1224:
	w = argv[0]->c.obj.iv[14];
	local[0]= w;
BLK1220:
	ctx->vsp=local; return(local[0]);}

/*:centroid*/
static pointer M1225bodyset_link_centroid(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1228;}
	local[0]= NIL;
ENT1228:
ENT1227:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1229;
	argv[0]->c.obj.iv[15] = local[0];
	local[1]= argv[0]->c.obj.iv[15];
	goto IF1230;
IF1229:
	local[1]= NIL;
IF1230:
	local[1]= argv[0];
	local[2]= fqv[122];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[123];
	local[3]= argv[0]->c.obj.iv[15];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK1226:
	ctx->vsp=local; return(local[0]);}

/*:inertia-tensor*/
static pointer M1231bodyset_link_inertia_tensor(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1234;}
	local[0]= NIL;
ENT1234:
ENT1233:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1235;
	argv[0]->c.obj.iv[16] = local[0];
	local[1]= argv[0]->c.obj.iv[16];
	goto IF1236;
IF1235:
	local[1]= NIL;
IF1236:
	w = argv[0]->c.obj.iv[16];
	local[0]= w;
BLK1232:
	ctx->vsp=local; return(local[0]);}

/*:joint*/
static pointer M1237bodyset_link_joint(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1239:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0]->c.obj.iv[9];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[13]); /*forward-message-to*/
	local[0]= w;
BLK1238:
	ctx->vsp=local; return(local[0]);}

/*:add-joint*/
static pointer M1240bodyset_link_add_joint(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[9] = argv[2];
	w = argv[0]->c.obj.iv[9];
	local[0]= w;
BLK1241:
	ctx->vsp=local; return(local[0]);}

/*:del-joint*/
static pointer M1242bodyset_link_del_joint(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[9] = NIL;
	w = argv[0]->c.obj.iv[9];
	local[0]= w;
BLK1243:
	ctx->vsp=local; return(local[0]);}

/*:parent-link*/
static pointer M1244bodyset_link_parent_link(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[10];
	local[0]= w;
BLK1245:
	ctx->vsp=local; return(local[0]);}

/*:child-links*/
static pointer M1246bodyset_link_child_links(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[11];
	local[0]= w;
BLK1247:
	ctx->vsp=local; return(local[0]);}

/*:add-child-links*/
static pointer M1248bodyset_link_add_child_links(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[11];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[124]); /*member*/
	if (w!=NIL) goto IF1250;
	if (argv[2]==NIL) goto IF1250;
	local[0]= argv[2];
	w = argv[0]->c.obj.iv[11];
	ctx->vsp=local+1;
	argv[0]->c.obj.iv[11] = cons(ctx,local[0],w);
	local[0]= argv[0]->c.obj.iv[11];
	goto IF1251;
IF1250:
	local[0]= NIL;
IF1251:
	w = local[0];
	local[0]= w;
BLK1249:
	ctx->vsp=local; return(local[0]);}

/*:add-parent-link*/
static pointer M1252bodyset_link_add_parent_link(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[10] = argv[2];
	w = argv[0]->c.obj.iv[10];
	local[0]= w;
BLK1253:
	ctx->vsp=local; return(local[0]);}

/*:del-child-link*/
static pointer M1254bodyset_link_del_child_link(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[11];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[125]); /*delete*/
	argv[0]->c.obj.iv[11] = w;
	w = argv[0]->c.obj.iv[11];
	local[0]= w;
BLK1255:
	ctx->vsp=local; return(local[0]);}

/*:del-parent-link*/
static pointer M1256bodyset_link_del_parent_link(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[10] = NIL;
	w = argv[0]->c.obj.iv[10];
	local[0]= w;
BLK1257:
	ctx->vsp=local; return(local[0]);}

/*:default-coords*/
static pointer M1258bodyset_link_default_coords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1261;}
	local[0]= NIL;
ENT1261:
ENT1260:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1262;
	argv[0]->c.obj.iv[13] = local[0];
	local[1]= argv[0]->c.obj.iv[13];
	goto IF1263;
IF1262:
	local[1]= NIL;
IF1263:
	w = argv[0]->c.obj.iv[13];
	local[0]= w;
BLK1259:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1264cascaded_link_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1266:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[126], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY1267;
	local[1] = NIL;
KEY1267:
	local[2]= (pointer)get_sym_func(fqv[34]);
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[35]));
	local[5]= fqv[36];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,5,local+2); /*apply*/
	w = argv[0];
	local[0]= w;
BLK1265:
	ctx->vsp=local; return(local[0]);}

/*:init-ending*/
static pointer M1268cascaded_link_init_ending(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= fqv[127];
	ctx->vsp=local+2;
	w=(*ftab[18])(ctx,2,local+0,&ftab[18],fqv[128]); /*send-all*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[19])(ctx,1,local+0,&ftab[19],fqv[129]); /*flatten*/
	argv[0]->c.obj.iv[10] = w;
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[9];
WHL1271:
	if (local[1]==NIL) goto WHX1272;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= fqv[130];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= fqv[131];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= local[0];
	local[3]= fqv[130];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= fqv[132];
	local[4]= local[0];
	local[5]= fqv[133];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= local[0];
	local[3]= fqv[133];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= fqv[134];
	local[4]= local[0];
	local[5]= fqv[130];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	goto WHL1271;
WHX1272:
	local[2]= NIL;
BLK1273:
	w = NIL;
	local[0]= argv[0];
	local[1]= fqv[135];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[136];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
WHL1276:
	if (local[1]==NIL) goto WHX1277;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= fqv[137];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	goto WHL1276;
WHX1277:
	local[2]= NIL;
BLK1278:
	w = NIL;
	local[0]= w;
BLK1269:
	ctx->vsp=local; return(local[0]);}

/*:links*/
static pointer M1280cascaded_link_links(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1282:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0]->c.obj.iv[8];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[20])(ctx,2,local+1,&ftab[20],fqv[138]); /*forward-message-to-all*/
	local[0]= w;
BLK1281:
	ctx->vsp=local; return(local[0]);}

/*:joint-list*/
static pointer M1283cascaded_link_joint_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1285:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0]->c.obj.iv[9];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[20])(ctx,2,local+1,&ftab[20],fqv[138]); /*forward-message-to-all*/
	local[0]= w;
BLK1284:
	ctx->vsp=local; return(local[0]);}

/*:link*/
static pointer M1286cascaded_link_link(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[8];
	local[2]= fqv[139];
	local[3]= (pointer)get_sym_func(fqv[140]);
	local[4]= fqv[141];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO1288,env,argv,local);
	ctx->vsp=local+6;
	w=(*ftab[21])(ctx,6,local+0,&ftab[21],fqv[142]); /*find*/
	local[0]= w;
BLK1287:
	ctx->vsp=local; return(local[0]);}

/*:joint*/
static pointer M1289cascaded_link_joint(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[9];
	local[2]= fqv[139];
	local[3]= (pointer)get_sym_func(fqv[140]);
	local[4]= fqv[141];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO1291,env,argv,local);
	ctx->vsp=local+6;
	w=(*ftab[21])(ctx,6,local+0,&ftab[21],fqv[142]); /*find*/
	local[0]= w;
BLK1290:
	ctx->vsp=local; return(local[0]);}

/*:end-coords*/
static pointer M1292cascaded_link_end_coords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[12];
	local[2]= fqv[139];
	local[3]= (pointer)get_sym_func(fqv[140]);
	local[4]= fqv[141];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO1294,env,argv,local);
	ctx->vsp=local+6;
	w=(*ftab[21])(ctx,6,local+0,&ftab[21],fqv[142]); /*find*/
	local[0]= w;
BLK1293:
	ctx->vsp=local; return(local[0]);}

/*:bodies*/
static pointer M1295cascaded_link_bodies(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1297:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0]->c.obj.iv[10];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[20])(ctx,2,local+1,&ftab[20],fqv[138]); /*forward-message-to-all*/
	local[0]= w;
BLK1296:
	ctx->vsp=local; return(local[0]);}

/*:faces*/
static pointer M1298cascaded_link_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[10];
	local[1]= fqv[143];
	ctx->vsp=local+2;
	w=(*ftab[18])(ctx,2,local+0,&ftab[18],fqv[128]); /*send-all*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[19])(ctx,1,local+0,&ftab[19],fqv[129]); /*flatten*/
	local[0]= w;
BLK1299:
	ctx->vsp=local; return(local[0]);}

/*:update-descendants*/
static pointer M1300cascaded_link_update_descendants(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1302:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0]->c.obj.iv[8];
	local[2]= fqv[122];
	ctx->vsp=local+3;
	w=(*ftab[18])(ctx,2,local+1,&ftab[18],fqv[128]); /*send-all*/
	local[0]= w;
BLK1301:
	ctx->vsp=local; return(local[0]);}

/*:angle-vector*/
static pointer M1303cascaded_link_angle_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1307;}
	local[0]= NIL;
ENT1307:
	if (n>=4) { local[1]=(argv[3]); goto ENT1306;}
	local[1]= loadglobal(fqv[5]);
	local[2]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+3;
	w=(pointer)F767calc_target_joint_dimension(ctx,1,local+2); /*calc-target-joint-dimension*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,2,local+1); /*instantiate*/
	local[1]= w;
ENT1306:
ENT1305:
	if (n>4) maerror();
	local[2]= makeint((eusinteger_t)0L);
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[9];
WHL1309:
	if (local[4]==NIL) goto WHX1310;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	if (local[0]==NIL) goto IF1313;
	local[5]= local[3];
	local[6]= fqv[10];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	if (w==NIL) goto IF1315;
	local[5]= local[3];
	local[6]= fqv[11];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	if (w==NIL) goto IF1315;
	local[5]= local[3];
	local[6]= fqv[31];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(pointer)NUMEQUAL(ctx,2,local+5); /*=*/
	if (w==NIL) goto IF1317;
	local[5]= local[3];
	local[6]= fqv[11];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= fqv[31];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(pointer)NUMEQUAL(ctx,2,local+5); /*=*/
	if (w==NIL) goto IF1317;
	local[5]= makeint((eusinteger_t)0L);
	local[6]= argv[0]->c.obj.iv[9];
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	local[7]= makeint((eusinteger_t)0L);
	local[8]= NIL;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
WHL1319:
	local[14]= local[6];
	local[15]= local[3];
	local[16]= fqv[11];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	if (w==local[14]) goto WHX1320;
	local[14]= local[5];
	ctx->vsp=local+15;
	w=(pointer)ADD1(ctx,1,local+14); /*1+*/
	local[5] = w;
	local[14]= local[7];
	local[15]= local[6];
	local[16]= fqv[31];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)PLUS(ctx,2,local+14); /*+*/
	local[7] = w;
	local[14]= argv[0]->c.obj.iv[9];
	local[15]= local[5];
	ctx->vsp=local+16;
	w=(pointer)ELT(ctx,2,local+14); /*elt*/
	local[6] = w;
	goto WHL1319;
WHX1320:
	local[14]= NIL;
BLK1321:
	local[14]= local[0];
	local[15]= local[2];
	ctx->vsp=local+16;
	w=(pointer)ELT(ctx,2,local+14); /*elt*/
	local[8] = w;
	local[14]= local[0];
	local[15]= local[7];
	ctx->vsp=local+16;
	w=(pointer)ELT(ctx,2,local+14); /*elt*/
	local[11] = w;
	local[14]= local[3];
	local[15]= fqv[41];
	local[16]= local[11];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[9] = w;
	local[14]= local[3];
	local[15]= fqv[42];
	local[16]= local[11];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[10] = w;
	local[14]= local[6];
	local[15]= fqv[41];
	local[16]= local[8];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[12] = w;
	local[14]= local[6];
	local[15]= fqv[42];
	local[16]= local[8];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[13] = w;
	local[14]= local[9];
	local[15]= local[8];
	local[16]= local[10];
	ctx->vsp=local+17;
	w=(pointer)LSEQP(ctx,3,local+14); /*<=*/
	if (w==NIL) goto CON1323;
	local[14]= local[8];
	*(ovafptr(local[3],fqv[144])) = local[14];
	local[14]= local[11];
	local[15]= local[14];
	*(ovafptr(local[6],fqv[144])) = local[15];
	goto CON1322;
CON1323:
	local[14]= makeint((eusinteger_t)0L);
TAG1327:
	local[15]= local[14];
	local[16]= makeint((eusinteger_t)1L);
	ctx->vsp=local+17;
	w=(pointer)GREATERP(ctx,2,local+15); /*>*/
	if (w==NIL) goto IF1328;
	w = NIL;
	ctx->vsp=local+15;
	local[14]=w;
	goto BLK1326;
	goto IF1329;
IF1328:
	local[15]= NIL;
IF1329:
	local[15]= local[3];
	local[16]= fqv[41];
	local[17]= local[11];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,3,local+15); /*send*/
	local[9] = w;
	local[15]= local[3];
	local[16]= fqv[42];
	local[17]= local[11];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,3,local+15); /*send*/
	local[10] = w;
	local[15]= local[6];
	local[16]= fqv[41];
	local[17]= local[8];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,3,local+15); /*send*/
	local[12] = w;
	local[15]= local[6];
	local[16]= fqv[42];
	local[17]= local[8];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,3,local+15); /*send*/
	local[13] = w;
	local[15]= local[8];
	local[16]= local[9];
	ctx->vsp=local+17;
	w=(pointer)LESSP(ctx,2,local+15); /*<*/
	if (w==NIL) goto IF1330;
	local[15]= local[8];
	local[16]= local[9];
	local[17]= local[8];
	ctx->vsp=local+18;
	w=(pointer)MINUS(ctx,2,local+16); /*-*/
	local[16]= w;
	local[17]= local[14];
	ctx->vsp=local+18;
	w=(pointer)TIMES(ctx,2,local+16); /***/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)PLUS(ctx,2,local+15); /*+*/
	local[8] = w;
	local[15]= local[8];
	goto IF1331;
IF1330:
	local[15]= NIL;
IF1331:
	local[15]= local[8];
	local[16]= local[10];
	ctx->vsp=local+17;
	w=(pointer)GREATERP(ctx,2,local+15); /*>*/
	if (w==NIL) goto IF1332;
	local[15]= local[8];
	local[16]= local[10];
	local[17]= local[8];
	ctx->vsp=local+18;
	w=(pointer)MINUS(ctx,2,local+16); /*-*/
	local[16]= w;
	local[17]= local[14];
	ctx->vsp=local+18;
	w=(pointer)TIMES(ctx,2,local+16); /***/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)PLUS(ctx,2,local+15); /*+*/
	local[8] = w;
	local[15]= local[8];
	goto IF1333;
IF1332:
	local[15]= NIL;
IF1333:
	local[15]= local[11];
	local[16]= local[12];
	ctx->vsp=local+17;
	w=(pointer)LESSP(ctx,2,local+15); /*<*/
	if (w==NIL) goto IF1334;
	local[15]= local[11];
	local[16]= local[12];
	local[17]= local[11];
	ctx->vsp=local+18;
	w=(pointer)MINUS(ctx,2,local+16); /*-*/
	local[16]= w;
	local[17]= local[14];
	ctx->vsp=local+18;
	w=(pointer)TIMES(ctx,2,local+16); /***/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)PLUS(ctx,2,local+15); /*+*/
	local[11] = w;
	local[15]= local[11];
	goto IF1335;
IF1334:
	local[15]= NIL;
IF1335:
	local[15]= local[11];
	local[16]= local[13];
	ctx->vsp=local+17;
	w=(pointer)GREATERP(ctx,2,local+15); /*>*/
	if (w==NIL) goto IF1336;
	local[15]= local[11];
	local[16]= local[13];
	local[17]= local[11];
	ctx->vsp=local+18;
	w=(pointer)MINUS(ctx,2,local+16); /*-*/
	local[16]= w;
	local[17]= local[14];
	ctx->vsp=local+18;
	w=(pointer)TIMES(ctx,2,local+16); /***/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)PLUS(ctx,2,local+15); /*+*/
	local[11] = w;
	local[15]= local[11];
	goto IF1337;
IF1336:
	local[15]= NIL;
IF1337:
	local[15]= local[14];
	local[16]= makeflt(9.9999999999999977795540e-02);
	ctx->vsp=local+17;
	w=(pointer)PLUS(ctx,2,local+15); /*+*/
	local[14] = w;
	local[15]= local[14];
	local[14] = local[15];
	w = NIL;
	ctx->vsp=local+15;
	goto TAG1327;
	w = NIL;
	local[14]= w;
BLK1326:
	local[14]= local[8];
	*(ovafptr(local[3],fqv[144])) = local[14];
	local[14]= local[11];
	local[15]= local[14];
	*(ovafptr(local[6],fqv[144])) = local[15];
	local[14]= local[0];
	local[15]= local[2];
	local[16]= local[8];
	ctx->vsp=local+17;
	w=(pointer)SETELT(ctx,3,local+14); /*setelt*/
	local[14]= local[0];
	local[15]= local[7];
	local[16]= local[11];
	ctx->vsp=local+17;
	w=(pointer)SETELT(ctx,3,local+14); /*setelt*/
	local[14]= w;
	goto CON1322;
CON1324:
	local[14]= NIL;
CON1322:
	w = local[14];
	local[5]= w;
	goto IF1318;
IF1317:
	local[5]= NIL;
IF1318:
	goto IF1316;
IF1315:
	local[5]= NIL;
IF1316:
	local[5]= local[3];
	local[6]= fqv[31];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= local[5];
	if (fqv[145]!=local[6]) goto IF1340;
	local[6]= local[3];
	local[7]= fqv[20];
	local[8]= local[0];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	goto IF1341;
IF1340:
	if (T==NIL) goto IF1342;
	local[6]= local[3];
	local[7]= fqv[20];
	local[8]= local[0];
	local[9]= local[2];
	local[10]= local[2];
	local[11]= local[3];
	local[12]= fqv[31];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SUBSEQ(ctx,3,local+8); /*subseq*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	goto IF1343;
IF1342:
	local[6]= NIL;
IF1343:
IF1341:
	w = local[6];
	local[5]= w;
	goto IF1314;
IF1313:
	local[5]= NIL;
IF1314:
	local[5]= makeint((eusinteger_t)0L);
	local[6]= local[3];
	local[7]= fqv[31];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
WHL1345:
	local[7]= local[5];
	w = local[6];
	if ((eusinteger_t)local[7] >= (eusinteger_t)w) goto WHX1346;
	local[7]= local[1];
	local[8]= local[2];
	local[9]= local[3];
	local[10]= fqv[31];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	local[10]= local[9];
	if (fqv[146]!=local[10]) goto IF1349;
	local[10]= local[3];
	local[11]= fqv[20];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	goto IF1350;
IF1349:
	if (T==NIL) goto IF1351;
	local[10]= local[3];
	local[11]= fqv[20];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)ELT(ctx,2,local+10); /*elt*/
	local[10]= w;
	goto IF1352;
IF1351:
	local[10]= NIL;
IF1352:
IF1350:
	w = local[10];
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SETELT(ctx,3,local+7); /*setelt*/
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[2] = w;
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[5] = w;
	goto WHL1345;
WHX1346:
	local[7]= NIL;
BLK1347:
	w = NIL;
	goto WHL1309;
WHX1310:
	local[5]= NIL;
BLK1311:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK1304:
	ctx->vsp=local; return(local[0]);}

/*:find-link-route*/
static pointer M1353cascaded_link_find_link_route(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1356;}
	local[0]= NIL;
ENT1356:
ENT1355:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= fqv[133];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	if (local[1]==NIL) goto CON1358;
	local[2]= argv[2];
	local[3]= argv[0];
	local[4]= fqv[136];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[21])(ctx,2,local+2,&ftab[21],fqv[142]); /*find*/
	if (w!=NIL) goto CON1358;
	local[2]= argv[0];
	local[3]= fqv[147];
	local[4]= local[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	goto CON1357;
CON1358:
	if (local[1]==NIL) goto CON1359;
	local[2]= argv[2];
	if (local[0]==local[2]) goto CON1359;
	local[2]= argv[0];
	local[3]= fqv[147];
	local[4]= local[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPEND(ctx,2,local+2); /*append*/
	local[2]= w;
	goto CON1357;
CON1359:
	if (local[1]==NIL) goto CON1360;
	local[2]= argv[2];
	if (local[0]!=local[2]) goto CON1360;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	goto CON1357;
CON1360:
	local[2]= NIL;
CON1357:
	w = local[2];
	local[0]= w;
BLK1354:
	ctx->vsp=local; return(local[0]);}

/*:link-list*/
static pointer M1361cascaded_link_link_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1364;}
	local[0]= NIL;
ENT1364:
ENT1363:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	local[4]= fqv[147];
	local[5]= argv[2];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[1] = w;
	if (local[0]==NIL) goto IF1365;
	local[3]= local[0];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==local[3]) goto IF1365;
	local[3]= argv[0];
	local[4]= fqv[147];
	local[5]= local[0];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[2] = w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	local[3]= w;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)NCONC(ctx,2,local+3); /*nconc*/
	local[1] = w;
	local[3]= local[1];
	goto IF1366;
IF1365:
	local[3]= NIL;
IF1366:
	w = local[1];
	local[0]= w;
BLK1362:
	ctx->vsp=local; return(local[0]);}

/*:make-joint-min-max-table*/
static pointer M1367cascaded_link_make_joint_min_max_table(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<6) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[148], &argv[6], n-6, local+0, 0);
	if (n & (1<<0)) goto KEY1369;
	local[0] = makeint((eusinteger_t)0L);
KEY1369:
	if (n & (1<<1)) goto KEY1370;
	local[1] = NIL;
KEY1370:
	if (n & (1<<2)) goto KEY1371;
	local[2] = NIL;
KEY1371:
	if (n & (1<<3)) goto KEY1372;
	local[3] = makeflt(0.0000000000000000000000e+00);
KEY1372:
	if (n & (1<<4)) goto KEY1373;
	local[4] = NIL;
KEY1373:
	if (local[2]!=NIL) goto IF1374;
	local[5]= argv[0];
	local[6]= fqv[136];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= fqv[149];
	local[7]= fqv[120];
	ctx->vsp=local+8;
	w=(*ftab[18])(ctx,3,local+5,&ftab[18],fqv[128]); /*send-all*/
	local[5]= w;
	goto IF1375;
IF1374:
	local[5]= NIL;
IF1375:
	local[5]= NIL;
	local[6]= argv[4];
	local[7]= argv[5];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
WHL1377:
	if (local[6]==NIL) goto WHX1378;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[5];
	local[8]= fqv[150];
	local[9]= fqv[151];
	local[10]= local[5];
	local[11]= fqv[22];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[7]= local[5];
	local[8]= fqv[150];
	local[9]= fqv[152];
	local[10]= local[5];
	local[11]= fqv[23];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	goto WHL1377;
WHX1378:
	local[7]= NIL;
BLK1379:
	w = NIL;
	local[5]= argv[0];
	local[6]= fqv[153];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= argv[0];
	local[7]= fqv[154];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= argv[4];
	local[8]= fqv[22];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= makeflt(9.9999999999999991239646e-05);
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,2,local+7); /*-*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)TRUNCATE(ctx,1,local+7); /*truncate*/
	local[7]= w;
	local[8]= argv[4];
	local[9]= fqv[23];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= makeflt(9.9999999999999991239646e-05);
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)TRUNCATE(ctx,1,local+8); /*truncate*/
	local[8]= w;
	local[9]= argv[5];
	local[10]= fqv[22];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	local[10]= makeflt(9.9999999999999991239646e-05);
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,2,local+9); /*-*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)TRUNCATE(ctx,1,local+9); /*truncate*/
	local[9]= w;
	local[10]= argv[5];
	local[11]= fqv[23];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	local[11]= makeflt(9.9999999999999991239646e-05);
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)TRUNCATE(ctx,1,local+10); /*truncate*/
	local[10]= w;
	local[11]= local[8];
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(pointer)MINUS(ctx,2,local+11); /*-*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)ROUND(ctx,1,local+11); /*round*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[11]= w;
	local[12]= local[10];
	local[13]= local[9];
	ctx->vsp=local+14;
	w=(pointer)MINUS(ctx,2,local+12); /*-*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)ROUND(ctx,1,local+12); /*round*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)ADD1(ctx,1,local+12); /*1+*/
	local[12]= w;
	if (local[2]==NIL) goto IF1381;
	local[13]= T;
	local[14]= fqv[155];
	local[15]= argv[4];
	local[16]= fqv[3];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
	local[16]= argv[4];
	local[17]= fqv[22];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,2,local+16); /*send*/
	local[16]= w;
	local[17]= argv[4];
	local[18]= fqv[23];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)XFORMAT(ctx,5,local+13); /*format*/
	local[13]= T;
	local[14]= fqv[156];
	local[15]= argv[5];
	local[16]= fqv[3];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
	local[16]= argv[5];
	local[17]= fqv[22];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,2,local+16); /*send*/
	local[16]= w;
	local[17]= argv[5];
	local[18]= fqv[23];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)XFORMAT(ctx,5,local+13); /*format*/
	local[13]= T;
	local[14]= fqv[157];
	local[15]= argv[4];
	local[16]= fqv[3];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
	local[16]= local[7];
	local[17]= local[8];
	ctx->vsp=local+18;
	w=(pointer)XFORMAT(ctx,5,local+13); /*format*/
	local[13]= T;
	local[14]= fqv[158];
	local[15]= argv[5];
	local[16]= fqv[3];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
	local[16]= local[9];
	local[17]= local[10];
	ctx->vsp=local+18;
	w=(pointer)XFORMAT(ctx,5,local+13); /*format*/
	local[13]= w;
	goto IF1382;
IF1381:
	local[13]= NIL;
IF1382:
	local[13]= argv[0];
	local[14]= fqv[159];
	ctx->vsp=local+15;
	w=(*ftab[11])(ctx,0,local+15,&ftab[11],fqv[86]); /*make-coords*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= argv[0];
	local[14]= fqv[160];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	if (local[4]==NIL) goto IF1383;
	local[13]= argv[2];
	local[14]= NIL;
	local[15]= fqv[161];
	ctx->vsp=local+16;
	w=(pointer)PUTPROP(ctx,3,local+13); /*putprop*/
	local[13]= argv[3];
	local[14]= NIL;
	local[15]= fqv[161];
	ctx->vsp=local+16;
	w=(pointer)PUTPROP(ctx,3,local+13); /*putprop*/
	local[13]= argv[2];
	local[14]= argv[3];
	local[15]= makeint((eusinteger_t)2L);
	local[16]= fqv[162];
	local[17]= local[0];
	local[18]= fqv[163];
	local[19]= local[1];
	ctx->vsp=local+20;
	w=(*ftab[22])(ctx,7,local+13,&ftab[22],fqv[164]); /*pqp-collision-check*/
	local[13]= w;
	goto IF1384;
IF1383:
	local[13]= NIL;
IF1384:
	local[13]= argv[0];
	local[14]= fqv[165];
	local[15]= argv[2];
	local[16]= argv[3];
	local[17]= argv[4];
	local[18]= argv[5];
	local[19]= local[11];
	local[20]= local[12];
	local[21]= local[7];
	local[22]= local[9];
	local[23]= local[0];
	local[24]= local[1];
	local[25]= local[2];
	local[26]= local[3];
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,14,local+13); /*send*/
	local[13]= argv[0];
	local[14]= fqv[154];
	local[15]= local[6];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= argv[0];
	local[14]= fqv[159];
	local[15]= local[5];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	if (local[2]!=NIL) goto IF1385;
	local[13]= argv[0];
	local[14]= fqv[136];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	local[13]= w;
	local[14]= fqv[149];
	local[15]= fqv[116];
	ctx->vsp=local+16;
	w=(*ftab[18])(ctx,3,local+13,&ftab[18],fqv[128]); /*send-all*/
	local[13]= w;
	goto IF1386;
IF1385:
	local[13]= NIL;
IF1386:
	w = NIL;
	local[0]= w;
BLK1368:
	ctx->vsp=local; return(local[0]);}

/*:make-min-max-table-using-collision-check*/
static pointer M1387cascaded_link_make_min_max_table_using_collision_check(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=14) maerror();
	local[0]= argv[7];
	local[1]= argv[6];
	ctx->vsp=local+2;
	w=(*ftab[23])(ctx,2,local+0,&ftab[23],fqv[166]); /*make-matrix*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= makeint((eusinteger_t)10L);
	local[4]= makeint((eusinteger_t)0L);
TAG1391:
	local[5]= local[4];
	local[6]= argv[7];
	ctx->vsp=local+7;
	w=(pointer)GREQP(ctx,2,local+5); /*>=*/
	if (w==NIL) goto IF1392;
	w = NIL;
	ctx->vsp=local+5;
	local[4]=w;
	goto BLK1390;
	goto IF1393;
IF1392:
	local[5]= NIL;
IF1393:
	local[5]= argv[5];
	local[6]= fqv[20];
	local[7]= local[4];
	local[8]= argv[9];
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)ROUND(ctx,1,local+7); /*round*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[1] = fqv[167];
	local[5]= local[4];
	local[6]= makeint((eusinteger_t)10L);
	ctx->vsp=local+7;
	w=(pointer)MOD(ctx,2,local+5); /*mod*/
	local[5]= w;
	local[6]= makeint((eusinteger_t)0L);
	ctx->vsp=local+7;
	w=(pointer)NUMEQUAL(ctx,2,local+5); /*=*/
	if (w==NIL) goto IF1394;
	local[5]= T;
	local[6]= fqv[168];
	local[7]= makeint((eusinteger_t)13L);
	local[8]= local[4];
	local[9]= argv[6];
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	local[9]= argv[6];
	local[10]= argv[7];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,5,local+5); /*format*/
	ctx->vsp=local+5;
	w=(pointer)FINOUT(ctx,0,local+5); /*finish-output*/
	local[5]= w;
	goto IF1395;
IF1394:
	local[5]= NIL;
IF1395:
	local[5]= makeint((eusinteger_t)0L);
TAG1398:
	local[6]= local[5];
	local[7]= argv[6];
	ctx->vsp=local+8;
	w=(pointer)GREQP(ctx,2,local+6); /*>=*/
	if (w==NIL) goto IF1399;
	w = NIL;
	ctx->vsp=local+6;
	local[5]=w;
	goto BLK1397;
	goto IF1400;
IF1399:
	local[6]= NIL;
IF1400:
	{jmp_buf jb;
	w = fqv[169];
	ctx->vsp=local+6;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT1401;}
	local[12]= argv[4];
	local[13]= fqv[20];
	local[14]= local[5];
	local[15]= argv[8];
	ctx->vsp=local+16;
	w=(pointer)PLUS(ctx,2,local+14); /*+*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)ROUND(ctx,1,local+14); /*round*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[12]= local[1];
	if (fqv[170]!=local[12]) goto CON1403;
	local[12]= local[5];
	local[13]= local[3];
	ctx->vsp=local+14;
	w=(pointer)MOD(ctx,2,local+12); /*mod*/
	local[12]= w;
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(*ftab[24])(ctx,2,local+12,&ftab[24],fqv[171]); /*/=*/
	if (w==NIL) goto CON1403;
	local[12]= local[5];
	local[13]= argv[6];
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(pointer)MINUS(ctx,2,local+13); /*-*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)LSEQP(ctx,2,local+12); /*<=*/
	if (w==NIL) goto CON1403;
	local[2] = T;
	local[12]= local[2];
	goto CON1402;
CON1403:
	local[12]= argv[2];
	local[13]= argv[3];
	local[14]= makeint((eusinteger_t)2L);
	local[15]= fqv[162];
	local[16]= argv[10];
	local[17]= fqv[163];
	local[18]= argv[11];
	ctx->vsp=local+19;
	w=(*ftab[22])(ctx,7,local+12,&ftab[22],fqv[164]); /*pqp-collision-check*/
	local[12]= w;
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(pointer)NUMEQUAL(ctx,2,local+12); /*=*/
	local[2] = w;
	local[12]= local[1];
	if (fqv[167]!=local[12]) goto CON1406;
	if (local[2]==NIL) goto CON1406;
	local[1] = fqv[170];
	local[12]= local[1];
	goto CON1405;
CON1406:
	local[12]= local[1];
	if (fqv[170]!=local[12]) goto CON1407;
	if (local[2]!=NIL) goto CON1407;
	local[1] = fqv[172];
	local[12]= local[5];
	local[13]= local[3];
	ctx->vsp=local+14;
	w=(pointer)MINUS(ctx,2,local+12); /*-*/
	local[12]= w;
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(pointer)MAX(ctx,2,local+12); /*max*/
	local[5] = w;
	local[12]= fqv[169];
	w = NIL;
	ctx->vsp=local+13;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	goto CON1405;
CON1407:
	local[12]= NIL;
CON1405:
	goto CON1402;
CON1404:
	local[12]= NIL;
CON1402:
	local[12]= local[0];
	local[13]= local[4];
	local[14]= local[5];
	if (local[2]==NIL) goto IF1408;
	local[15]= makeint((eusinteger_t)1L);
	goto IF1409;
IF1408:
	local[15]= makeint((eusinteger_t)0L);
IF1409:
	ctx->vsp=local+16;
	w=(pointer)ASET(ctx,4,local+12); /*aset*/
	if (argv[12]==NIL) goto IF1410;
	local[12]= T;
	local[13]= fqv[173];
	local[14]= argv[5];
	local[15]= fqv[3];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,2,local+14); /*send*/
	local[14]= w;
	local[15]= local[4];
	local[16]= argv[9];
	ctx->vsp=local+17;
	w=(pointer)PLUS(ctx,2,local+15); /*+*/
	local[15]= w;
	local[16]= argv[4];
	local[17]= fqv[3];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,2,local+16); /*send*/
	local[16]= w;
	local[17]= local[5];
	local[18]= argv[8];
	ctx->vsp=local+19;
	w=(pointer)PLUS(ctx,2,local+17); /*+*/
	local[17]= w;
	local[18]= local[2];
	local[19]= local[1];
	ctx->vsp=local+20;
	w=(pointer)XFORMAT(ctx,8,local+12); /*format*/
	local[12]= w;
	goto IF1411;
IF1410:
	local[12]= NIL;
IF1411:
	w = local[12];
CAT1401:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[6]= local[5];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	local[5] = local[6];
	w = NIL;
	ctx->vsp=local+6;
	goto TAG1398;
	w = NIL;
	local[5]= w;
BLK1397:
	local[5]= local[4];
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[4] = local[5];
	w = NIL;
	ctx->vsp=local+5;
	goto TAG1391;
	w = NIL;
	local[4]= w;
BLK1390:
	w = local[4];
	local[1]= T;
	local[2]= fqv[174];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,2,local+1); /*format*/
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,FLET1414,env,argv,local);
	local[2]= argv[6];
	local[3]= argv[7];
	local[4]= argv[8];
	local[5]= argv[9];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO1415,env,argv,local);
	w = local[1];
	ctx->vsp=local+7;
	w=FLET1414(ctx,5,local+2,w);
	local[2]= w;
	local[3]= argv[5];
	local[4]= fqv[11];
	local[5]= argv[4];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[5];
	local[4]= fqv[10];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[2]= argv[7];
	local[3]= argv[6];
	local[4]= argv[9];
	local[5]= argv[8];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO1416,env,argv,local);
	w = local[1];
	ctx->vsp=local+7;
	w=FLET1414(ctx,5,local+2,w);
	local[2]= w;
	local[3]= argv[4];
	local[4]= fqv[11];
	local[5]= argv[5];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[4];
	local[4]= fqv[10];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[0]= w;
BLK1388:
	ctx->vsp=local; return(local[0]);}

/*:plot-joint-min-max-table-common*/
static pointer M1417cascaded_link_plot_joint_min_max_table_common(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= loadglobal(fqv[175]);
	local[2]= loadglobal(fqv[176]);
	local[3]= NIL;
	ctx->vsp=local+4;
	w = makeclosure(codevec,quotevec,UWP1423,env,argv,local);
	local[4]=(pointer)(ctx->protfp); local[5]=w;
	ctx->protfp=(struct protectframe *)(local+4);
	local[6]= fqv[177];
	local[7]= fqv[178];
	local[8]= fqv[179];
	ctx->vsp=local+9;
	w=(*ftab[25])(ctx,3,local+6,&ftab[25],fqv[180]); /*open*/
	local[6]= w;
	ctx->vsp=local+7;
	w = makeclosure(codevec,quotevec,UWP1424,env,argv,local);
	local[7]=(pointer)(ctx->protfp); local[8]=w;
	ctx->protfp=(struct protectframe *)(local+7);
	local[9]= local[6];
	storeglobal(fqv[175],local[9]);
	local[9]= local[6];
	storeglobal(fqv[176],local[9]);
	local[9]= argv[2];
	local[10]= fqv[151];
	ctx->vsp=local+11;
	w=(pointer)GETPROP(ctx,2,local+9); /*get*/
	local[9]= w;
TAG1427:
	local[10]= local[9];
	local[11]= argv[2];
	local[12]= fqv[152];
	ctx->vsp=local+13;
	w=(pointer)GETPROP(ctx,2,local+11); /*get*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)GREATERP(ctx,2,local+10); /*>*/
	if (w==NIL) goto IF1428;
	w = NIL;
	ctx->vsp=local+10;
	local[9]=w;
	goto BLK1426;
	goto IF1429;
IF1428:
	local[10]= NIL;
IF1429:
	local[10]= argv[0];
	local[11]= fqv[160];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= argv[2];
	local[11]= fqv[20];
	local[12]= local[9];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= argv[2];
	local[11]= fqv[20];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)EUSFLOAT(ctx,1,local+10); /*float*/
	local[10]= w;
	local[11]= local[9];
	ctx->vsp=local+12;
	w=(pointer)EUSFLOAT(ctx,1,local+11); /*float*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[8])(ctx,2,local+10,&ftab[8],fqv[81]); /*eps=*/
	local[10]= w;
	local[11]= argv[3];
	local[12]= fqv[151];
	ctx->vsp=local+13;
	w=(pointer)GETPROP(ctx,2,local+11); /*get*/
	local[11]= w;
TAG1432:
	local[12]= local[11];
	local[13]= argv[3];
	local[14]= fqv[152];
	ctx->vsp=local+15;
	w=(pointer)GETPROP(ctx,2,local+13); /*get*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)GREATERP(ctx,2,local+12); /*>*/
	if (w==NIL) goto IF1433;
	w = NIL;
	ctx->vsp=local+12;
	local[11]=w;
	goto BLK1431;
	goto IF1434;
IF1433:
	local[12]= NIL;
IF1434:
	local[12]= argv[3];
	local[13]= fqv[20];
	local[14]= local[11];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[12]= argv[3];
	local[13]= fqv[20];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)EUSFLOAT(ctx,1,local+12); /*float*/
	local[12]= w;
	local[13]= local[11];
	ctx->vsp=local+14;
	w=(pointer)EUSFLOAT(ctx,1,local+13); /*float*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(*ftab[8])(ctx,2,local+12,&ftab[8],fqv[81]); /*eps=*/
	local[12]= w;
	if (local[10]==NIL) goto IF1435;
	if (local[12]==NIL) goto IF1435;
	local[13]= local[9];
	local[14]= local[11];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,2,local+13); /*list*/
	local[13]= w;
	w = local[0];
	ctx->vsp=local+14;
	local[0] = cons(ctx,local[13],w);
	local[13]= local[0];
	goto IF1436;
IF1435:
	local[13]= NIL;
IF1436:
	w = local[13];
	local[12]= makeint((eusinteger_t)1L);
	local[13]= local[11];
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,2,local+12); /*+*/
	local[12]= w;
	local[11] = local[12];
	w = NIL;
	ctx->vsp=local+12;
	goto TAG1432;
	w = NIL;
	local[11]= w;
BLK1431:
	w = local[11];
	local[10]= makeint((eusinteger_t)1L);
	local[11]= local[9];
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[10]= w;
	local[9] = local[10];
	w = NIL;
	ctx->vsp=local+10;
	goto TAG1427;
	w = NIL;
	local[9]= w;
BLK1426:
	local[3] = local[9];
	w = local[3];
	ctx->vsp=local+9;
	UWP1424(ctx,0,local+9,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	ctx->vsp=local+6;
	UWP1423(ctx,0,local+6,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)REVERSE(ctx,1,local+1); /*reverse*/
	local[0]= w;
BLK1418:
	ctx->vsp=local; return(local[0]);}

/*:plot-joint-min-max-table*/
static pointer M1439cascaded_link_plot_joint_min_max_table(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= loadglobal(fqv[181]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[182];
	local[3]= fqv[183];
	local[4]= argv[2];
	local[5]= fqv[184];
	local[6]= fqv[152];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= argv[2];
	local[6]= fqv[184];
	local[7]= fqv[151];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ROUND(ctx,1,local+4); /*round*/
	local[4]= w;
	local[5]= fqv[185];
	local[6]= argv[3];
	local[7]= fqv[184];
	local[8]= fqv[152];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	local[7]= argv[3];
	local[8]= fqv[184];
	local[9]= fqv[151];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ROUND(ctx,1,local+6); /*round*/
	local[6]= w;
	local[7]= fqv[186];
	local[8]= fqv[187];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,8,local+1); /*send*/
	w = local[0];
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[188];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	local[2]= local[0];
	local[3]= fqv[189];
	local[4]= makeint((eusinteger_t)16777215L);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= local[0];
	local[3]= fqv[190];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= local[0];
	local[3]= fqv[189];
	local[4]= makeint((eusinteger_t)16711680L);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= NIL;
	local[3]= local[1];
WHL1443:
	if (local[3]==NIL) goto WHX1444;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[0];
	local[5]= fqv[191];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)ROUND(ctx,1,local+6); /*round*/
	local[6]= w;
	local[7]= argv[2];
	local[8]= fqv[151];
	ctx->vsp=local+9;
	w=(pointer)GETPROP(ctx,2,local+7); /*get*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)ROUND(ctx,1,local+7); /*round*/
	local[7]= w;
	local[8]= argv[3];
	local[9]= fqv[151];
	ctx->vsp=local+10;
	w=(pointer)GETPROP(ctx,2,local+8); /*get*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,2,local+7); /*-*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,2,local+6); /*float-vector*/
	local[6]= w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)ROUND(ctx,1,local+7); /*round*/
	local[7]= w;
	local[8]= argv[2];
	local[9]= fqv[151];
	ctx->vsp=local+10;
	w=(pointer)GETPROP(ctx,2,local+8); /*get*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,2,local+7); /*-*/
	local[7]= w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)ROUND(ctx,1,local+8); /*round*/
	local[8]= w;
	local[9]= argv[3];
	local[10]= fqv[151];
	ctx->vsp=local+11;
	w=(pointer)GETPROP(ctx,2,local+9); /*get*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,2,local+7); /*float-vector*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	goto WHL1443;
WHX1444:
	local[4]= NIL;
BLK1445:
	w = NIL;
	local[2]= local[0];
	local[3]= fqv[190];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[0]= w;
BLK1440:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1288(ctx,n,argv,env)
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
static pointer CLO1291(ctx,n,argv,env)
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
static pointer CLO1294(ctx,n,argv,env)
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
static pointer FLET1414(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= makeint((eusinteger_t)3L);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[23])(ctx,2,local+0,&ftab[23],fqv[166]); /*make-matrix*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)0L);
	local[2]= argv[0];
WHL1448:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX1449;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[3]= w;
	local[4]= makeint((eusinteger_t)0L);
	local[5]= NIL;
	local[6]= makeint((eusinteger_t)0L);
	local[7]= argv[1];
WHL1452:
	local[8]= local[6];
	w = local[7];
	if ((eusinteger_t)local[8] >= (eusinteger_t)w) goto WHX1453;
	local[8]= argv[4];
	local[9]= env->c.clo.env2[0];
	local[10]= local[1];
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)FUNCALL(ctx,4,local+8); /*funcall*/
	local[8]= w;
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)NUMEQUAL(ctx,2,local+8); /*=*/
	if (w==NIL) goto IF1455;
	local[5] = T;
	local[8]= local[6];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)LESSP(ctx,2,local+8); /*<*/
	if (w==NIL) goto IF1457;
	local[3] = local[6];
	local[8]= local[3];
	goto IF1458;
IF1457:
	local[8]= NIL;
IF1458:
	local[8]= local[6];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)GREATERP(ctx,2,local+8); /*>*/
	if (w==NIL) goto IF1459;
	local[4] = local[6];
	local[8]= local[4];
	goto IF1460;
IF1459:
	local[8]= NIL;
IF1460:
	goto IF1456;
IF1455:
	local[8]= NIL;
IF1456:
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[6] = w;
	goto WHL1452;
WHX1453:
	local[8]= NIL;
BLK1454:
	w = NIL;
	if (local[5]!=NIL) goto IF1461;
	local[6]= argv[3];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,1,local+6); /*-*/
	local[3] = w;
	local[6]= argv[3];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,1,local+6); /*-*/
	local[4] = w;
	local[6]= local[4];
	goto IF1462;
IF1461:
	local[6]= NIL;
IF1462:
	local[6]= local[0];
	local[7]= makeint((eusinteger_t)0L);
	local[8]= local[1];
	local[9]= argv[2];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)ROUND(ctx,1,local+9); /*round*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)ASET(ctx,4,local+6); /*aset*/
	local[6]= local[0];
	local[7]= makeint((eusinteger_t)1L);
	local[8]= local[1];
	local[9]= env->c.clo.env1[13];
	local[10]= argv[3];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,3,local+9); /*+*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)ROUND(ctx,1,local+9); /*round*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)ASET(ctx,4,local+6); /*aset*/
	local[6]= local[0];
	local[7]= makeint((eusinteger_t)2L);
	local[8]= local[1];
	local[9]= env->c.clo.env1[13];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,1,local+9); /*-*/
	local[9]= w;
	local[10]= argv[3];
	local[11]= local[4];
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,3,local+9); /*+*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)ROUND(ctx,1,local+9); /*round*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)ASET(ctx,4,local+6); /*aset*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL1448;
WHX1449:
	local[3]= NIL;
BLK1450:
	w = NIL;
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1415(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= argv[2];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,3,local+0); /*aref*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1416(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,3,local+0); /*aref*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP1423(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[1];
	storeglobal(fqv[175],local[0]);
	local[0]= env->c.clo.env2[1];
	storeglobal(fqv[176],local[0]);
	w = env->c.clo.env2[3];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP1424(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[6];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:calc-target-axis-dimension*/
static pointer M1463cascaded_link_calc_target_axis_dimension(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= makeint((eusinteger_t)6L);
	w = argv[2];
	if (!!iscons(w)) goto IF1465;
	local[1]= makeint((eusinteger_t)1L);
	goto IF1466;
IF1465:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
IF1466:
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= NIL;
	w = argv[3];
	if (!!iscons(w)) goto IF1468;
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	goto IF1469;
IF1468:
	local[2]= argv[3];
IF1469:
	w = argv[2];
	if (!!iscons(w)) goto IF1470;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[3]= w;
	goto IF1471;
IF1470:
	local[3]= argv[2];
IF1471:
	ctx->vsp=local+4;
	w=(pointer)APPEND(ctx,2,local+2); /*append*/
	local[2]= w;
WHL1472:
	if (local[2]==NIL) goto WHX1473;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	local[4]= local[3];
	w = fqv[192];
	if (memq(local[4],w)==NIL) goto IF1477;
	local[4]= local[0];
	local[5]= makeint((eusinteger_t)1L);
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[0] = w;
	local[4]= local[0];
	goto IF1478;
IF1477:
	local[4]= local[3];
	w = fqv[193];
	if (memq(local[4],w)==NIL) goto IF1479;
	local[4]= local[0];
	local[5]= makeint((eusinteger_t)2L);
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[0] = w;
	local[4]= local[0];
	goto IF1480;
IF1479:
	local[4]= local[3];
	if (fqv[194]!=local[4]) goto IF1481;
	local[4]= local[0];
	local[5]= makeint((eusinteger_t)3L);
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[0] = w;
	local[4]= local[0];
	goto IF1482;
IF1481:
	local[4]= NIL;
IF1482:
IF1480:
IF1478:
	w = local[4];
	goto WHL1472;
WHX1473:
	local[3]= NIL;
BLK1474:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK1464:
	ctx->vsp=local; return(local[0]);}

/*:calc-union-link-list*/
static pointer M1483cascaded_link_calc_union_link_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!!iscons(w)) goto CON1486;
	local[0]= argv[2];
	goto CON1485;
CON1486:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	if (makeint((eusinteger_t)1L)!=local[0]) goto CON1487;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	goto CON1485;
CON1487:
	local[0]= (pointer)get_sym_func(fqv[195]);
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[26])(ctx,2,local+0,&ftab[26],fqv[196]); /*reduce*/
	local[0]= w;
	goto CON1485;
CON1488:
	local[0]= NIL;
CON1485:
	w = local[0];
	local[0]= w;
BLK1484:
	ctx->vsp=local; return(local[0]);}

/*:calc-target-joint-dimension*/
static pointer M1489cascaded_link_calc_target_joint_dimension(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[197];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[198];
	ctx->vsp=local+2;
	w=(*ftab[18])(ctx,2,local+0,&ftab[18],fqv[128]); /*send-all*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)F767calc_target_joint_dimension(ctx,1,local+0); /*calc-target-joint-dimension*/
	local[0]= w;
BLK1490:
	ctx->vsp=local; return(local[0]);}

/*:calc-inverse-jacobian*/
static pointer M1491cascaded_link_calc_inverse_jacobian(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST1493:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[199], &argv[3], n-3, local+1, 1);
	if (n & (1<<0)) goto KEY1494;
	local[1] = makeflt(9.9999999999999977795540e-02);
KEY1494:
	if (n & (1<<1)) goto KEY1495;
	local[2] = makeflt(1.0000000000000000208167e-03);
KEY1495:
	if (n & (1<<2)) goto KEY1496;
	local[3] = NIL;
KEY1496:
	if (n & (1<<3)) goto KEY1497;
	local[4] = NIL;
KEY1497:
	if (n & (1<<4)) goto KEY1498;
	local[5] = NIL;
KEY1498:
	if (n & (1<<5)) goto KEY1499;
	local[6] = NIL;
KEY1499:
	if (n & (1<<6)) goto KEY1500;
	local[7] = NIL;
KEY1500:
	if (n & (1<<7)) goto KEY1501;
	local[8] = NIL;
KEY1501:
	if (n & (1<<8)) goto KEY1502;
	local[9] = NIL;
KEY1502:
	if (n & (1<<9)) goto KEY1503;
	local[10] = NIL;
KEY1503:
	if (n & (1<<10)) goto KEY1504;
	local[11] = NIL;
KEY1504:
	if (n & (1<<11)) goto KEY1505;
	local[12] = NIL;
KEY1505:
	if (n & (1<<12)) goto KEY1506;
	local[13] = NIL;
KEY1506:
	local[14]= NIL;
	local[15]= NIL;
	local[16]= NIL;
	local[17]= makeint((eusinteger_t)0L);
	local[18]= argv[2];
	local[19]= local[12];
	local[20]= local[7];
	ctx->vsp=local+21;
	w=(*ftab[27])(ctx,3,local+18,&ftab[27],fqv[200]); /*manipulability*/
	local[15] = w;
	local[18]= local[15];
	local[19]= local[1];
	ctx->vsp=local+20;
	w=(pointer)LESSP(ctx,2,local+18); /*<*/
	if (w==NIL) goto IF1507;
	local[18]= local[2];
	local[19]= makeflt(1.0000000000000000000000e+00);
	local[20]= local[15];
	local[21]= local[1];
	ctx->vsp=local+22;
	w=(pointer)QUOTIENT(ctx,2,local+20); /*/*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)MINUS(ctx,2,local+19); /*-*/
	local[19]= w;
	local[20]= makeint((eusinteger_t)2L);
	ctx->vsp=local+21;
	w=(*ftab[28])(ctx,2,local+19,&ftab[28],fqv[201]); /*expt*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)TIMES(ctx,2,local+18); /***/
	local[17] = w;
	local[18]= local[17];
	goto IF1508;
IF1507:
	local[18]= NIL;
IF1508:
	if (local[4]==NIL) goto IF1509;
	local[18]= fqv[202];
	w = local[4];
	if (memq(local[18],w)!=NIL) goto IF1509;
	local[18]= fqv[203];
	local[19]= local[17];
	local[20]= local[15];
	local[21]= local[2];
	local[22]= local[1];
	local[23]= argv[2];
	ctx->vsp=local+24;
	w=(*ftab[29])(ctx,1,local+23,&ftab[29],fqv[204]); /*array-dimensions*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	ctx->vsp=local+24;
	w=(*ftab[2])(ctx,6,local+18,&ftab[2],fqv[15]); /*warn*/
	local[18]= w;
	goto IF1510;
IF1509:
	local[18]= NIL;
IF1510:
	local[18]= argv[2];
	local[19]= local[17];
	local[20]= local[3];
	local[21]= local[5];
	local[22]= local[6];
	local[23]= local[7];
	local[24]= local[8];
	local[25]= local[9];
	local[26]= local[10];
	local[27]= local[11];
	local[28]= local[12];
	local[29]= local[13];
	ctx->vsp=local+30;
	w=(*ftab[30])(ctx,12,local+18,&ftab[30],fqv[205]); /*sr-inverse*/
	local[14] = w;
	w = local[14];
	local[0]= w;
BLK1492:
	ctx->vsp=local; return(local[0]);}

/*:calc-gradh-from-link-list*/
static pointer M1511cascaded_link_calc_gradh_from_link_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1514;}
	local[0]= loadglobal(fqv[5]);
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,2,local+0); /*instantiate*/
	local[0]= w;
ENT1514:
ENT1513:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= fqv[198];
	ctx->vsp=local+3;
	w=(*ftab[18])(ctx,2,local+1,&ftab[18],fqv[128]); /*send-all*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[20];
	ctx->vsp=local+4;
	w=(*ftab[18])(ctx,2,local+2,&ftab[18],fqv[128]); /*send-all*/
	local[2]= w;
	local[3]= local[1];
	local[4]= fqv[22];
	ctx->vsp=local+5;
	w=(*ftab[18])(ctx,2,local+3,&ftab[18],fqv[128]); /*send-all*/
	local[3]= w;
	local[4]= local[1];
	local[5]= fqv[23];
	ctx->vsp=local+6;
	w=(*ftab[18])(ctx,2,local+4,&ftab[18],fqv[128]); /*send-all*/
	local[4]= w;
	local[5]= loadglobal(fqv[88]);
	local[6]= (pointer)get_sym_func(fqv[206]);
	local[7]= local[4];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)MAP(ctx,4,local+5); /*map*/
	local[5]= w;
	local[6]= loadglobal(fqv[88]);
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO1515,env,argv,local);
	local[8]= local[4];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)MAP(ctx,4,local+6); /*map*/
	local[6]= w;
	local[7]= makeint((eusinteger_t)0L);
	local[8]= argv[2];
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
WHL1517:
	local[9]= local[7];
	w = local[8];
	if ((eusinteger_t)local[9] >= (eusinteger_t)w) goto WHX1518;
	local[9]= local[0];
	local[10]= local[7];
	local[11]= local[6];
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	local[12]= local[2];
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)MINUS(ctx,2,local+11); /*-*/
	local[11]= w;
	local[12]= local[5];
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)QUOTIENT(ctx,2,local+11); /*/*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)SETELT(ctx,3,local+9); /*setelt*/
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	local[7] = w;
	goto WHL1517;
WHX1518:
	local[9]= NIL;
BLK1519:
	w = local[0];
	w = local[0];
	local[0]= w;
BLK1512:
	ctx->vsp=local; return(local[0]);}

/*:calc-jacobian-from-link-list*/
static pointer M1520cascaded_link_calc_jacobian_from_link_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST1522:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[207], &argv[3], n-3, local+1, 1);
	if (n & (1<<0)) goto KEY1523;
	local[1] = NIL;
KEY1523:
	if (n & (1<<1)) goto KEY1524;
	local[2] = local[1];
KEY1524:
	if (n & (1<<2)) goto KEY1525;
	w = local[1];
	if (!!iscons(w)) goto CON1527;
	local[16]= NIL;
	goto CON1526;
CON1527:
	local[16]= local[1];
	ctx->vsp=local+17;
	w=(pointer)LENGTH(ctx,1,local+16); /*length*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(*ftab[31])(ctx,1,local+16,&ftab[31],fqv[208]); /*make-list*/
	local[16]= w;
	goto CON1526;
CON1528:
	local[16]= NIL;
CON1526:
	local[3] = local[16];
KEY1525:
	if (n & (1<<3)) goto KEY1529;
	w = local[1];
	if (!!iscons(w)) goto CON1531;
	local[16]= T;
	goto CON1530;
CON1531:
	local[16]= local[1];
	ctx->vsp=local+17;
	w=(pointer)LENGTH(ctx,1,local+16); /*length*/
	local[16]= w;
	local[17]= fqv[209];
	local[18]= T;
	ctx->vsp=local+19;
	w=(*ftab[31])(ctx,3,local+16,&ftab[31],fqv[208]); /*make-list*/
	local[16]= w;
	goto CON1530;
CON1532:
	local[16]= NIL;
CON1530:
	local[4] = local[16];
KEY1529:
	if (n & (1<<4)) goto KEY1533;
	local[5] = makeint((eusinteger_t)0L);
KEY1533:
	if (n & (1<<5)) goto KEY1534;
	local[16]= argv[0];
	local[17]= fqv[210];
	local[18]= local[3];
	local[19]= local[4];
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,4,local+16); /*send*/
	local[6] = w;
KEY1534:
	if (n & (1<<6)) goto KEY1535;
	local[16]= argv[0];
	local[17]= fqv[211];
	local[18]= argv[2];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,3,local+16); /*send*/
	local[7] = w;
KEY1535:
	if (n & (1<<7)) goto KEY1536;
	local[8] = NIL;
KEY1536:
	if (n & (1<<8)) goto KEY1537;
	local[16]= loadglobal(fqv[5]);
	local[17]= makeint((eusinteger_t)0L);
	ctx->vsp=local+18;
	w=(pointer)INSTANTIATE(ctx,2,local+16); /*instantiate*/
	local[9] = w;
KEY1537:
	if (n & (1<<9)) goto KEY1538;
	local[16]= loadglobal(fqv[5]);
	local[17]= makeint((eusinteger_t)1L);
	ctx->vsp=local+18;
	w=(pointer)INSTANTIATE(ctx,2,local+16); /*instantiate*/
	local[10] = w;
KEY1538:
	if (n & (1<<10)) goto KEY1539;
	local[16]= loadglobal(fqv[5]);
	local[17]= makeint((eusinteger_t)2L);
	ctx->vsp=local+18;
	w=(pointer)INSTANTIATE(ctx,2,local+16); /*instantiate*/
	local[11] = w;
KEY1539:
	if (n & (1<<11)) goto KEY1540;
	local[16]= loadglobal(fqv[5]);
	local[17]= makeint((eusinteger_t)3L);
	ctx->vsp=local+18;
	w=(pointer)INSTANTIATE(ctx,2,local+16); /*instantiate*/
	local[12] = w;
KEY1540:
	if (n & (1<<12)) goto KEY1541;
	local[16]= loadglobal(fqv[5]);
	local[17]= makeint((eusinteger_t)3L);
	ctx->vsp=local+18;
	w=(pointer)INSTANTIATE(ctx,2,local+16); /*instantiate*/
	local[13] = w;
KEY1541:
	if (n & (1<<13)) goto KEY1542;
	local[16]= loadglobal(fqv[5]);
	local[17]= makeint((eusinteger_t)3L);
	ctx->vsp=local+18;
	w=(pointer)INSTANTIATE(ctx,2,local+16); /*instantiate*/
	local[14] = w;
KEY1542:
	if (n & (1<<14)) goto KEY1543;
	local[16]= makeint((eusinteger_t)3L);
	local[17]= makeint((eusinteger_t)3L);
	ctx->vsp=local+18;
	w=(*ftab[23])(ctx,2,local+16,&ftab[23],fqv[166]); /*make-matrix*/
	local[15] = w;
KEY1543:
	local[16]= NIL;
	local[17]= NIL;
	local[18]= NIL;
	local[19]= NIL;
	local[20]= NIL;
	local[21]= NIL;
	local[22]= NIL;
	if (local[8]!=NIL) goto IF1544;
	local[23]= local[6];
	local[24]= local[7];
	ctx->vsp=local+25;
	w=(*ftab[23])(ctx,2,local+23,&ftab[23],fqv[166]); /*make-matrix*/
	local[8] = w;
	local[23]= local[8];
	goto IF1545;
IF1544:
	local[23]= NIL;
IF1545:
	local[23]= argv[0];
	local[24]= fqv[197];
	local[25]= argv[2];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,3,local+23); /*send*/
	local[20] = w;
	local[23]= argv[0];
	local[24]= fqv[211];
	local[25]= local[20];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,3,local+23); /*send*/
	local[22] = w;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!!iscons(w)) goto IF1546;
	local[23]= argv[2];
	ctx->vsp=local+24;
	w=(pointer)LIST(ctx,1,local+23); /*list*/
	argv[2] = w;
	local[23]= argv[2];
	goto IF1547;
IF1546:
	local[23]= NIL;
IF1547:
	w = local[1];
	if (!!iscons(w)) goto IF1548;
	local[23]= local[1];
	ctx->vsp=local+24;
	w=(pointer)LIST(ctx,1,local+23); /*list*/
	local[1] = w;
	local[23]= local[1];
	goto IF1549;
IF1548:
	local[23]= NIL;
IF1549:
	w = local[2];
	if (!!iscons(w)) goto IF1550;
	local[23]= local[2];
	ctx->vsp=local+24;
	w=(pointer)LIST(ctx,1,local+23); /*list*/
	local[2] = w;
	local[23]= local[2];
	goto IF1551;
IF1550:
	local[23]= NIL;
IF1551:
	w = local[3];
	if (!!iscons(w)) goto IF1552;
	local[23]= local[3];
	ctx->vsp=local+24;
	w=(pointer)LIST(ctx,1,local+23); /*list*/
	local[3] = w;
	local[23]= local[3];
	goto IF1553;
IF1552:
	local[23]= NIL;
IF1553:
	w = local[4];
	if (!!iscons(w)) goto IF1554;
	local[23]= local[4];
	ctx->vsp=local+24;
	w=(pointer)LIST(ctx,1,local+23); /*list*/
	local[4] = w;
	local[23]= local[4];
	goto IF1555;
IF1554:
	local[23]= NIL;
IF1555:
	local[23]= local[5];
	local[24]= makeint((eusinteger_t)0L);
TAG1558:
	local[25]= local[23];
	local[26]= local[5];
	local[27]= local[22];
	ctx->vsp=local+28;
	w=(pointer)PLUS(ctx,2,local+26); /*+*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)GREQP(ctx,2,local+25); /*>=*/
	if (w==NIL) goto IF1559;
	w = NIL;
	ctx->vsp=local+25;
	local[23]=w;
	goto BLK1557;
	goto IF1560;
IF1559:
	local[25]= NIL;
IF1560:
	local[25]= local[20];
	local[26]= local[24];
	ctx->vsp=local+27;
	w=(pointer)ELT(ctx,2,local+25); /*elt*/
	local[17] = w;
	local[18] = makeint((eusinteger_t)0L);
	local[25]= makeint((eusinteger_t)0L);
	local[26]= argv[2];
	ctx->vsp=local+27;
	w=(pointer)LENGTH(ctx,1,local+26); /*length*/
	local[26]= w;
WHL1562:
	local[27]= local[25];
	w = local[26];
	if ((eusinteger_t)local[27] >= (eusinteger_t)w) goto WHX1563;
	local[27]= argv[2];
	local[28]= local[25];
	ctx->vsp=local+29;
	w=(pointer)ELT(ctx,2,local+27); /*elt*/
	local[27]= w;
	local[28]= local[1];
	local[29]= local[25];
	ctx->vsp=local+30;
	w=(pointer)ELT(ctx,2,local+28); /*elt*/
	local[28]= w;
	local[29]= local[2];
	local[30]= local[25];
	ctx->vsp=local+31;
	w=(pointer)ELT(ctx,2,local+29); /*elt*/
	local[29]= w;
	local[30]= local[3];
	local[31]= local[25];
	ctx->vsp=local+32;
	w=(pointer)ELT(ctx,2,local+30); /*elt*/
	local[30]= w;
	local[31]= local[4];
	local[32]= local[25];
	ctx->vsp=local+33;
	w=(pointer)ELT(ctx,2,local+31); /*elt*/
	local[31]= w;
	local[32]= NIL;
	local[33]= local[17];
	local[34]= local[27];
	local[35]= fqv[139];
	local[36]= (pointer)get_sym_func(fqv[140]);
	ctx->vsp=local+37;
	w=(*ftab[16])(ctx,4,local+33,&ftab[16],fqv[124]); /*member*/
	if (w==NIL) goto IF1565;
	local[33]= local[27];
	ctx->vsp=local+34;
	w=(pointer)LENGTH(ctx,1,local+33); /*length*/
	local[16] = w;
	local[33]= local[17];
	local[34]= local[27];
	local[35]= fqv[139];
	local[36]= (pointer)get_sym_func(fqv[140]);
	ctx->vsp=local+37;
	w=(*ftab[32])(ctx,4,local+33,&ftab[32],fqv[213]); /*position*/
	local[32] = w;
	local[33]= local[17];
	local[34]= fqv[198];
	ctx->vsp=local+35;
	w=(pointer)SEND(ctx,2,local+33); /*send*/
	local[21] = w;
	ctx->vsp=local+33;
	local[33]= makeclosure(codevec,quotevec,FLET1567,env,argv,local);
	local[34]= local[21];
	local[35]= fqv[130];
	ctx->vsp=local+36;
	w=(pointer)SEND(ctx,2,local+34); /*send*/
	local[34]= w;
	local[35]= loadglobal(fqv[214]);
	ctx->vsp=local+36;
	w=(pointer)DERIVEDP(ctx,2,local+34); /*derivedp*/
	if (w!=NIL) goto CON1569;
	local[19] = NIL;
	local[34]= local[19];
	goto CON1568;
CON1569:
	local[34]= local[32];
	local[35]= makeint((eusinteger_t)1L);
	ctx->vsp=local+36;
	w=(pointer)PLUS(ctx,2,local+34); /*+*/
	local[34]= w;
	local[35]= local[16];
	ctx->vsp=local+36;
	w=(pointer)LESSP(ctx,2,local+34); /*<*/
	if (w==NIL) goto AND1572;
	local[34]= local[21];
	local[35]= fqv[130];
	ctx->vsp=local+36;
	w=(pointer)SEND(ctx,2,local+34); /*send*/
	local[34]= w;
	local[35]= local[27];
	local[36]= local[32];
	local[37]= makeint((eusinteger_t)1L);
	ctx->vsp=local+38;
	w=(pointer)PLUS(ctx,2,local+36); /*+*/
	local[36]= w;
	ctx->vsp=local+37;
	w=(pointer)ELT(ctx,2,local+35); /*elt*/
	local[35]= w;
	local[36]= fqv[133];
	ctx->vsp=local+37;
	w=(pointer)SEND(ctx,2,local+35); /*send*/
	local[35]= w;
	local[36]= local[27];
	w = local[33];
	ctx->vsp=local+37;
	w=FLET1567(ctx,2,local+35,w);
	if (w==local[34]) goto AND1572;
	goto OR1571;
AND1572:
	local[34]= local[16];
	local[35]= local[32];
	local[36]= makeint((eusinteger_t)1L);
	ctx->vsp=local+37;
	w=(pointer)PLUS(ctx,2,local+35); /*+*/
	local[35]= w;
	ctx->vsp=local+36;
	w=(pointer)NUMEQUAL(ctx,2,local+34); /*=*/
	if (w==NIL) goto AND1573;
	local[34]= local[21];
	local[35]= fqv[130];
	ctx->vsp=local+36;
	w=(pointer)SEND(ctx,2,local+34); /*send*/
	local[34]= w;
	local[35]= local[28];
	local[36]= fqv[215];
	ctx->vsp=local+37;
	w=(pointer)SEND(ctx,2,local+35); /*send*/
	local[35]= w;
	local[36]= local[27];
	w = local[33];
	ctx->vsp=local+37;
	w=FLET1567(ctx,2,local+35,w);
	if (w==local[34]) goto AND1573;
	goto OR1571;
AND1573:
	goto CON1570;
OR1571:
	local[19] = T;
	local[34]= local[19];
	goto CON1568;
CON1570:
	local[19] = NIL;
	local[34]= local[19];
	goto CON1568;
CON1574:
	local[34]= NIL;
CON1568:
	w = local[34];
	local[33]= *(ovafptr(local[21],fqv[216]));
	local[34]= local[33];
	if (fqv[52]!=local[34]) goto IF1576;
	local[34]= fqv[217];
	goto IF1577;
IF1576:
	local[34]= local[33];
	if (fqv[54]!=local[34]) goto IF1578;
	local[34]= fqv[218];
	goto IF1579;
IF1578:
	local[34]= local[33];
	if (fqv[33]!=local[34]) goto IF1580;
	local[34]= fqv[219];
	goto IF1581;
IF1580:
	local[34]= local[33];
	if (fqv[220]!=local[34]) goto IF1582;
	local[34]= fqv[221];
	goto IF1583;
IF1582:
	local[34]= local[33];
	if (fqv[222]!=local[34]) goto IF1584;
	local[34]= fqv[223];
	goto IF1585;
IF1584:
	local[34]= local[33];
	if (fqv[224]!=local[34]) goto IF1586;
	local[34]= fqv[225];
	goto IF1587;
IF1586:
	local[34]= local[33];
	if (fqv[53]!=local[34]) goto IF1588;
	local[34]= fqv[226];
	goto IF1589;
IF1588:
	local[34]= local[33];
	if (fqv[55]!=local[34]) goto IF1590;
	local[34]= fqv[227];
	goto IF1591;
IF1590:
	local[34]= local[33];
	if (fqv[56]!=local[34]) goto IF1592;
	local[34]= fqv[228];
	goto IF1593;
IF1592:
	if (T==NIL) goto IF1594;
	local[34]= *(ovafptr(local[21],fqv[216]));
	goto IF1595;
IF1594:
	local[34]= NIL;
IF1595:
IF1593:
IF1591:
IF1589:
IF1587:
IF1585:
IF1583:
IF1581:
IF1579:
IF1577:
	w = local[34];
	local[33]= w;
	local[34]= local[21];
	local[35]= fqv[130];
	ctx->vsp=local+36;
	w=(pointer)SEND(ctx,2,local+34); /*send*/
	local[34]= w;
	local[35]= local[21];
	local[36]= fqv[133];
	ctx->vsp=local+37;
	w=(pointer)SEND(ctx,2,local+35); /*send*/
	local[35]= w;
	local[36]= *(ovafptr(local[21],fqv[229]));
	local[37]= local[35];
	local[38]= fqv[153];
	ctx->vsp=local+39;
	w=(pointer)SEND(ctx,2,local+37); /*send*/
	local[37]= w;
	local[38]= fqv[84];
	local[39]= local[36];
	ctx->vsp=local+40;
	w=(pointer)SEND(ctx,3,local+37); /*send*/
	local[37]= w;
	local[38]= local[21];
	local[39]= fqv[230];
	local[40]= local[8];
	local[41]= local[18];
	local[42]= local[23];
	local[43]= local[21];
	local[44]= local[33];
	local[45]= local[34];
	local[46]= local[37];
	local[47]= local[19];
	local[48]= local[28];
	local[49]= local[29];
	local[50]= local[30];
	local[51]= local[31];
	local[52]= local[9];
	local[53]= local[10];
	local[54]= local[11];
	local[55]= local[12];
	local[56]= local[13];
	local[57]= local[14];
	local[58]= local[15];
	ctx->vsp=local+59;
	w=(pointer)SEND(ctx,21,local+38); /*send*/
	local[33]= w;
	goto IF1566;
IF1565:
	local[33]= NIL;
IF1566:
	local[33]= local[18];
	local[34]= argv[0];
	local[35]= fqv[210];
	local[36]= local[30];
	local[37]= local[31];
	ctx->vsp=local+38;
	w=(pointer)SEND(ctx,4,local+34); /*send*/
	local[34]= w;
	ctx->vsp=local+35;
	w=(pointer)PLUS(ctx,2,local+33); /*+*/
	local[18] = w;
	w = local[18];
	local[27]= local[25];
	ctx->vsp=local+28;
	w=(pointer)ADD1(ctx,1,local+27); /*1+*/
	local[25] = w;
	goto WHL1562;
WHX1563:
	local[27]= NIL;
BLK1564:
	w = NIL;
	local[25]= local[23];
	local[26]= local[21];
	local[27]= fqv[31];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,2,local+26); /*send*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)PLUS(ctx,2,local+25); /*+*/
	local[25]= w;
	local[26]= local[24];
	ctx->vsp=local+27;
	w=(pointer)ADD1(ctx,1,local+26); /*1+*/
	local[26]= w;
	local[23] = local[25];
	local[24] = local[26];
	w = NIL;
	ctx->vsp=local+25;
	goto TAG1558;
	w = NIL;
	local[23]= w;
BLK1557:
	w = local[8];
	local[0]= w;
BLK1521:
	ctx->vsp=local; return(local[0]);}

/*:calc-joint-angle-speed*/
static pointer M1598cascaded_link_calc_joint_angle_speed(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST1600:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[231], &argv[3], n-3, local+1, 1);
	if (n & (1<<0)) goto KEY1601;
	local[1] = NIL;
KEY1601:
	if (n & (1<<1)) goto KEY1602;
	local[2] = makeflt(5.0000000000000000000000e-01);
KEY1602:
	if (n & (1<<2)) goto KEY1603;
	local[3] = NIL;
KEY1603:
	if (n & (1<<3)) goto KEY1604;
	local[4] = NIL;
KEY1604:
	if (n & (1<<4)) goto KEY1605;
	local[5] = NIL;
KEY1605:
	if (n & (1<<5)) goto KEY1606;
	local[6] = NIL;
KEY1606:
	if (n & (1<<6)) goto KEY1607;
	local[7] = NIL;
KEY1607:
	if (n & (1<<7)) goto KEY1608;
	local[8] = NIL;
KEY1608:
	if (n & (1<<8)) goto KEY1609;
	local[9] = NIL;
KEY1609:
	if (n & (1<<9)) goto KEY1610;
	local[10] = NIL;
KEY1610:
	if (n & (1<<10)) goto KEY1611;
	local[11] = NIL;
KEY1611:
	if (n & (1<<11)) goto KEY1612;
	local[12] = NIL;
KEY1612:
	if (local[3]==NIL) goto OR1615;
	if (local[4]==NIL) goto OR1615;
	goto IF1613;
OR1615:
	local[13]= fqv[232];
	ctx->vsp=local+14;
	w=(*ftab[2])(ctx,1,local+13,&ftab[2],fqv[15]); /*warn*/
	w = local[5];
	ctx->vsp=local+13;
	local[0]=w;
	goto BLK1599;
	goto IF1614;
IF1613:
	local[13]= NIL;
IF1614:
	if (local[12]!=NIL) goto IF1616;
	local[13]= local[3];
	ctx->vsp=local+14;
	w=(*ftab[29])(ctx,1,local+13,&ftab[29],fqv[204]); /*array-dimensions*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12] = (w)->c.cons.car;
	local[13]= local[12];
	goto IF1617;
IF1616:
	local[13]= NIL;
IF1617:
	if (local[10]!=NIL) goto IF1618;
	local[13]= loadglobal(fqv[5]);
	local[14]= local[12];
	ctx->vsp=local+15;
	w=(pointer)INSTANTIATE(ctx,2,local+13); /*instantiate*/
	local[10] = w;
	local[13]= local[10];
	goto IF1619;
IF1618:
	local[13]= NIL;
IF1619:
	if (local[11]!=NIL) goto IF1620;
	local[13]= loadglobal(fqv[5]);
	local[14]= local[12];
	ctx->vsp=local+15;
	w=(pointer)INSTANTIATE(ctx,2,local+13); /*instantiate*/
	local[11] = w;
	local[13]= local[11];
	goto IF1621;
IF1620:
	local[13]= NIL;
IF1621:
	local[13]= local[4];
	local[14]= argv[2];
	local[15]= local[10];
	ctx->vsp=local+16;
	w=(pointer)TRANSFORM(ctx,3,local+13); /*transform*/
	local[13]= w;
	if (local[7]==NIL) goto IF1622;
	local[14]= fqv[202];
	w = local[7];
	if (memq(local[14],w)!=NIL) goto IF1622;
	local[14]= local[3];
	local[15]= fqv[233];
	ctx->vsp=local+16;
	w=(*ftab[33])(ctx,2,local+14,&ftab[33],fqv[234]); /*format-array*/
	local[14]= fqv[235];
	local[15]= local[3];
	local[16]= local[3];
	ctx->vsp=local+17;
	w=(pointer)TRANSPOSE(ctx,1,local+16); /*transpose*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)MATTIMES(ctx,2,local+15); /*m**/
	local[15]= w;
	ctx->vsp=local+16;
	w=(*ftab[34])(ctx,1,local+15,&ftab[34],fqv[236]); /*matrix-determinant*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(*ftab[2])(ctx,2,local+14,&ftab[2],fqv[15]); /*warn*/
	local[14]= local[4];
	ctx->vsp=local+15;
	w=(pointer)TRANSPOSE(ctx,1,local+14); /*transpose*/
	local[14]= w;
	local[15]= fqv[237];
	ctx->vsp=local+16;
	w=(*ftab[33])(ctx,2,local+14,&ftab[33],fqv[234]); /*format-array*/
	local[14]= argv[2];
	local[15]= fqv[238];
	ctx->vsp=local+16;
	w=(*ftab[33])(ctx,2,local+14,&ftab[33],fqv[234]); /*format-array*/
	local[14]= loadglobal(fqv[5]);
	local[15]= (pointer)get_sym_func(fqv[49]);
	local[16]= local[13];
	ctx->vsp=local+17;
	w=(pointer)MAP(ctx,3,local+14); /*map*/
	local[14]= w;
	local[15]= fqv[239];
	ctx->vsp=local+16;
	w=(*ftab[33])(ctx,2,local+14,&ftab[33],fqv[234]); /*format-array*/
	local[14]= w;
	goto IF1623;
IF1622:
	local[14]= NIL;
IF1623:
	if (local[1]==NIL) goto IF1624;
	local[14]= local[2];
	local[15]= local[13];
	local[16]= local[1];
	local[17]= local[13];
	ctx->vsp=local+18;
	w=(*ftab[35])(ctx,4,local+14,&ftab[35],fqv[240]); /*midpoint*/
	local[13] = w;
	if (local[7]==NIL) goto IF1626;
	local[14]= fqv[202];
	w = local[7];
	if (memq(local[14],w)!=NIL) goto IF1626;
	local[14]= loadglobal(fqv[5]);
	local[15]= (pointer)get_sym_func(fqv[49]);
	local[16]= local[1];
	ctx->vsp=local+17;
	w=(pointer)MAP(ctx,3,local+14); /*map*/
	local[14]= w;
	local[15]= fqv[241];
	ctx->vsp=local+16;
	w=(*ftab[33])(ctx,2,local+14,&ftab[33],fqv[234]); /*format-array*/
	local[14]= loadglobal(fqv[5]);
	local[15]= (pointer)get_sym_func(fqv[49]);
	local[16]= local[13];
	ctx->vsp=local+17;
	w=(pointer)MAP(ctx,3,local+14); /*map*/
	local[14]= w;
	local[15]= fqv[242];
	ctx->vsp=local+16;
	w=(*ftab[33])(ctx,2,local+14,&ftab[33],fqv[234]); /*format-array*/
	local[14]= w;
	goto IF1627;
IF1626:
	local[14]= NIL;
IF1627:
	goto IF1625;
IF1624:
	local[14]= NIL;
IF1625:
	local[14]= local[5];
	ctx->vsp=local+15;
	w=(pointer)VECTORP(ctx,1,local+14); /*vectorp*/
	if (w==NIL) goto IF1628;
	local[14]= local[12];
	local[15]= local[5];
	ctx->vsp=local+16;
	w=(pointer)LENGTH(ctx,1,local+15); /*length*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)NUMEQUAL(ctx,2,local+14); /*=*/
	if (w==NIL) goto IF1628;
	if (local[6]==NIL) goto IF1628;
	if (local[8]!=NIL) goto IF1630;
	local[14]= loadglobal(fqv[5]);
	local[15]= local[12];
	ctx->vsp=local+16;
	w=(pointer)INSTANTIATE(ctx,2,local+14); /*instantiate*/
	local[14]= w;
	local[15]= makeint((eusinteger_t)1L);
	ctx->vsp=local+16;
	w=(*ftab[36])(ctx,2,local+14,&ftab[36],fqv[243]); /*fill*/
	local[8] = w;
	local[14]= local[8];
	goto IF1631;
IF1630:
	local[14]= NIL;
IF1631:
	if (local[9]!=NIL) goto IF1632;
	local[14]= local[12];
	local[15]= local[12];
	ctx->vsp=local+16;
	w=(*ftab[23])(ctx,2,local+14,&ftab[23],fqv[166]); /*make-matrix*/
	local[9] = w;
	local[14]= local[9];
	goto IF1633;
IF1632:
	local[14]= NIL;
IF1633:
	local[14]= makeint((eusinteger_t)0L);
	local[15]= local[12];
WHL1635:
	local[16]= local[14];
	w = local[15];
	if ((eusinteger_t)local[16] >= (eusinteger_t)w) goto WHX1636;
	local[16]= local[9];
	local[17]= local[14];
	local[18]= local[14];
	local[19]= local[8];
	local[20]= local[14];
	ctx->vsp=local+21;
	w=(pointer)AREF(ctx,2,local+19); /*aref*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)ASET(ctx,4,local+16); /*aset*/
	local[16]= local[14];
	ctx->vsp=local+17;
	w=(pointer)ADD1(ctx,1,local+16); /*1+*/
	local[14] = w;
	goto WHL1635;
WHX1636:
	local[16]= NIL;
BLK1637:
	w = NIL;
	local[14]= local[13];
	local[15]= local[6];
	local[16]= local[5];
	local[17]= local[11];
	ctx->vsp=local+18;
	w=(pointer)TRANSFORM(ctx,3,local+15); /*transform*/
	local[15]= w;
	local[16]= local[13];
	ctx->vsp=local+17;
	w=(pointer)VPLUS(ctx,3,local+14); /*v+*/
	if (local[7]==NIL) goto IF1638;
	local[14]= fqv[202];
	w = local[7];
	if (memq(local[14],w)!=NIL) goto IF1638;
	local[14]= loadglobal(fqv[5]);
	local[15]= (pointer)get_sym_func(fqv[49]);
	local[16]= local[11];
	ctx->vsp=local+17;
	w=(pointer)MAP(ctx,3,local+14); /*map*/
	local[14]= w;
	local[15]= fqv[244];
	ctx->vsp=local+16;
	w=(*ftab[33])(ctx,2,local+14,&ftab[33],fqv[234]); /*format-array*/
	local[14]= loadglobal(fqv[5]);
	local[15]= (pointer)get_sym_func(fqv[49]);
	local[16]= local[13];
	ctx->vsp=local+17;
	w=(pointer)MAP(ctx,3,local+14); /*map*/
	local[14]= w;
	local[15]= fqv[245];
	ctx->vsp=local+16;
	w=(*ftab[33])(ctx,2,local+14,&ftab[33],fqv[234]); /*format-array*/
	local[14]= w;
	goto IF1639;
IF1638:
	local[14]= NIL;
IF1639:
	goto IF1629;
IF1628:
	local[14]= NIL;
IF1629:
	w = local[13];
	local[0]= w;
BLK1599:
	ctx->vsp=local; return(local[0]);}

/*:calc-joint-angle-speed-gain*/
static pointer M1640cascaded_link_calc_joint_angle_speed_gain(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= fqv[211];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= loadglobal(fqv[5]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,2,local+1); /*instantiate*/
	local[1]= w;
	local[2]= NIL;
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
TAG1644:
	local[5]= local[4];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)GREQP(ctx,2,local+5); /*>=*/
	if (w==NIL) goto IF1645;
	w = NIL;
	ctx->vsp=local+5;
	local[3]=w;
	goto BLK1643;
	goto IF1646;
IF1645:
	local[5]= NIL;
IF1646:
	local[5]= argv[2];
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	local[6]= fqv[198];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[2] = w;
	local[5]= makeint((eusinteger_t)0L);
	local[6]= local[2];
	local[7]= fqv[31];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
WHL1648:
	local[7]= local[5];
	w = local[6];
	if ((eusinteger_t)local[7] >= (eusinteger_t)w) goto WHX1649;
	local[7]= local[1];
	local[8]= local[3];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	local[9]= local[2];
	local[10]= fqv[246];
	local[11]= argv[3];
	local[12]= local[3];
	local[13]= argv[4];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,5,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SETELT(ctx,3,local+7); /*setelt*/
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[5] = w;
	goto WHL1648;
WHX1649:
	local[7]= NIL;
BLK1650:
	w = NIL;
	local[5]= local[3];
	local[6]= local[2];
	local[7]= fqv[31];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[3] = w;
	local[5]= local[4];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[4] = w;
	ctx->vsp=local+5;
	goto TAG1644;
	w = NIL;
	local[3]= w;
BLK1643:
	w = local[1];
	local[0]= w;
BLK1641:
	ctx->vsp=local; return(local[0]);}

/*:collision-avoidance-links*/
static pointer M1651cascaded_link_collision_avoidance_links(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1654;}
	local[0]= NIL;
ENT1654:
ENT1653:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1655;
	argv[0]->c.obj.iv[11] = local[0];
	local[1]= argv[0]->c.obj.iv[11];
	goto IF1656;
IF1655:
	local[1]= NIL;
IF1656:
	w = argv[0]->c.obj.iv[11];
	local[0]= w;
BLK1652:
	ctx->vsp=local; return(local[0]);}

/*:collision-avoidance-link-pair-from-link-list*/
static pointer M1657cascaded_link_collision_avoidance_link_pair_from_link_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[247], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY1659;
	local[0] = NIL;
KEY1659:
	if (n & (1<<1)) goto KEY1660;
	local[1] = argv[0]->c.obj.iv[11];
KEY1660:
	if (n & (1<<2)) goto KEY1661;
	local[2] = NIL;
KEY1661:
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO1662,env,argv,local);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	local[8]= NIL;
	local[9]= NIL;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!!iscons(w)) goto IF1663;
	local[10]= argv[2];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	argv[2] = w;
	local[10]= argv[2];
	goto IF1664;
IF1663:
	local[10]= NIL;
IF1664:
	if (local[2]==NIL) goto IF1665;
	local[10]= fqv[202];
	w = local[2];
	if (memq(local[10],w)!=NIL) goto IF1665;
	local[10]= fqv[248];
	local[11]= local[1];
	local[12]= fqv[3];
	ctx->vsp=local+13;
	w=(*ftab[18])(ctx,2,local+11,&ftab[18],fqv[128]); /*send-all*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[2])(ctx,2,local+10,&ftab[2],fqv[15]); /*warn*/
	local[10]= fqv[249];
	local[11]= local[3];
	local[12]= fqv[3];
	ctx->vsp=local+13;
	w=(*ftab[18])(ctx,2,local+11,&ftab[18],fqv[128]); /*send-all*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[2])(ctx,2,local+10,&ftab[2],fqv[15]); /*warn*/
	local[10]= w;
	goto IF1666;
IF1665:
	local[10]= NIL;
IF1666:
	local[10]= NIL;
	local[11]= argv[2];
WHL1668:
	if (local[11]==NIL) goto WHX1669;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[12];
	local[10] = w;
	local[12]= local[10];
	local[13]= makeint((eusinteger_t)1L);
TAG1674:
	local[14]= local[13];
	local[15]= local[10];
	ctx->vsp=local+16;
	w=(pointer)LENGTH(ctx,1,local+15); /*length*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)SUB1(ctx,1,local+15); /*1-*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)LESSP(ctx,2,local+14); /*<*/
	if (w==NIL) goto AND1677;
	local[14]= local[10];
	local[15]= makeint((eusinteger_t)0L);
	ctx->vsp=local+16;
	w=(pointer)ELT(ctx,2,local+14); /*elt*/
	local[14]= w;
	local[15]= fqv[29];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,2,local+14); /*send*/
	local[14]= w;
	local[15]= local[10];
	local[16]= local[13];
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	local[16]= fqv[29];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)VDISTANCE(ctx,2,local+14); /*distance*/
	local[14]= w;
	local[15]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+16;
	w=(*ftab[8])(ctx,2,local+14,&ftab[8],fqv[81]); /*eps=*/
	if (w==NIL) goto AND1677;
	goto IF1675;
AND1677:
	local[14]= local[13];
	ctx->vsp=local+15;
	w=(pointer)SUB1(ctx,1,local+14); /*1-*/
	ctx->vsp=local+14;
	local[13]=w;
	goto BLK1673;
	goto IF1676;
IF1675:
	local[14]= NIL;
IF1676:
	local[14]= local[13];
	ctx->vsp=local+15;
	w=(pointer)ADD1(ctx,1,local+14); /*1+*/
	local[14]= w;
	local[13] = local[14];
	w = NIL;
	ctx->vsp=local+14;
	goto TAG1674;
	w = NIL;
	local[13]= w;
BLK1673:
	ctx->vsp=local+14;
	w=(pointer)SUBSEQ(ctx,2,local+12); /*subseq*/
	local[5] = w;
	ctx->vsp=local+12;
	local[12]= makeclosure(codevec,quotevec,CLO1679,env,argv,local);
	local[13]= local[1];
	ctx->vsp=local+14;
	w=(pointer)MAPCAR(ctx,2,local+12); /*mapcar*/
	local[6] = w;
	if (local[2]==NIL) goto IF1680;
	local[12]= fqv[202];
	w = local[2];
	if (memq(local[12],w)!=NIL) goto IF1680;
	local[12]= fqv[250];
	local[13]= local[5];
	local[14]= fqv[3];
	ctx->vsp=local+15;
	w=(*ftab[18])(ctx,2,local+13,&ftab[18],fqv[128]); /*send-all*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(*ftab[2])(ctx,2,local+12,&ftab[2],fqv[15]); /*warn*/
	local[12]= fqv[251];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(*ftab[2])(ctx,2,local+12,&ftab[2],fqv[15]); /*warn*/
	local[12]= w;
	goto IF1681;
IF1680:
	local[12]= NIL;
IF1681:
	local[12]= makeint((eusinteger_t)0L);
	local[13]= local[7];
WHL1683:
	local[14]= local[12];
	w = local[13];
	if ((eusinteger_t)local[14] >= (eusinteger_t)w) goto WHX1684;
	local[14]= local[12];
	ctx->vsp=local+15;
	w=(pointer)ADD1(ctx,1,local+14); /*1+*/
	local[14]= w;
TAG1688:
	local[15]= local[14];
	local[16]= local[7];
	ctx->vsp=local+17;
	w=(pointer)GREQP(ctx,2,local+15); /*>=*/
	if (w==NIL) goto IF1689;
	w = NIL;
	ctx->vsp=local+15;
	local[14]=w;
	goto BLK1687;
	goto IF1690;
IF1689:
	local[15]= NIL;
IF1690:
	local[15]= local[6];
	local[16]= local[12];
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[8] = w;
	if (local[8]!=NIL) goto OR1693;
	local[15]= local[6];
	local[16]= local[14];
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	if (w!=NIL) goto OR1693;
	goto IF1691;
OR1693:
	local[15]= local[3];
	local[16]= local[12];
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	local[16]= local[1];
	local[17]= local[14];
	ctx->vsp=local+18;
	w=(pointer)ELT(ctx,2,local+16); /*elt*/
	if (w==local[15]) goto IF1691;
	local[15]= local[3];
	local[16]= local[14];
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	local[16]= local[1];
	local[17]= local[12];
	ctx->vsp=local+18;
	w=(pointer)ELT(ctx,2,local+16); /*elt*/
	if (w==local[15]) goto IF1691;
	local[15]= local[3];
	local[16]= local[14];
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	local[16]= local[3];
	local[17]= local[12];
	ctx->vsp=local+18;
	w=(pointer)ELT(ctx,2,local+16); /*elt*/
	if (w==local[15]) goto IF1691;
	local[15]= local[1];
	if (local[8]==NIL) goto IF1694;
	local[16]= local[12];
	goto IF1695;
IF1694:
	local[16]= local[14];
IF1695:
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	local[16]= local[1];
	if (local[8]==NIL) goto IF1696;
	local[17]= local[14];
	goto IF1697;
IF1696:
	local[17]= local[12];
IF1697:
	ctx->vsp=local+18;
	w=(pointer)ELT(ctx,2,local+16); /*elt*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,2,local+15); /*list*/
	local[15]= w;
	w = local[9];
	ctx->vsp=local+16;
	local[9] = cons(ctx,local[15],w);
	local[15]= local[9];
	goto IF1692;
IF1691:
	local[15]= NIL;
IF1692:
	local[15]= local[14];
	ctx->vsp=local+16;
	w=(pointer)ADD1(ctx,1,local+15); /*1+*/
	local[15]= w;
	local[14] = local[15];
	w = NIL;
	ctx->vsp=local+15;
	goto TAG1688;
	w = NIL;
	local[14]= w;
BLK1687:
	local[14]= local[12];
	ctx->vsp=local+15;
	w=(pointer)ADD1(ctx,1,local+14); /*1+*/
	local[12] = w;
	goto WHL1683;
WHX1684:
	local[14]= NIL;
BLK1685:
	w = NIL;
	if (local[0]==NIL) goto IF1699;
	w = local[0];
	if (!!iscons(w)) goto IF1701;
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	local[0] = w;
	local[12]= local[0];
	goto IF1702;
IF1701:
	local[12]= NIL;
IF1702:
	local[12]= makeint((eusinteger_t)0L);
	local[13]= local[7];
WHL1704:
	local[14]= local[12];
	w = local[13];
	if ((eusinteger_t)local[14] >= (eusinteger_t)w) goto WHX1705;
	local[14]= local[6];
	local[15]= local[12];
	ctx->vsp=local+16;
	w=(pointer)ELT(ctx,2,local+14); /*elt*/
	if (w==NIL) goto IF1707;
	local[14]= NIL;
	local[15]= local[0];
WHL1710:
	if (local[15]==NIL) goto WHX1711;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15] = (w)->c.cons.cdr;
	w = local[16];
	local[14] = w;
	local[16]= local[1];
	local[17]= local[12];
	ctx->vsp=local+18;
	w=(pointer)ELT(ctx,2,local+16); /*elt*/
	local[16]= w;
	local[17]= local[14];
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,2,local+16); /*list*/
	local[16]= w;
	w = local[9];
	ctx->vsp=local+17;
	local[9] = cons(ctx,local[16],w);
	goto WHL1710;
WHX1711:
	local[16]= NIL;
BLK1712:
	w = NIL;
	local[14]= w;
	goto IF1708;
IF1707:
	local[14]= NIL;
IF1708:
	local[14]= local[12];
	ctx->vsp=local+15;
	w=(pointer)ADD1(ctx,1,local+14); /*1+*/
	local[12] = w;
	goto WHL1704;
WHX1705:
	local[14]= NIL;
BLK1706:
	w = NIL;
	local[12]= w;
	goto IF1700;
IF1699:
	local[12]= NIL;
IF1700:
	goto WHL1668;
WHX1669:
	local[12]= NIL;
BLK1670:
	w = NIL;
	w = local[9];
	local[0]= w;
BLK1658:
	ctx->vsp=local; return(local[0]);}

/*:collision-avoidance-calc-distance*/
static pointer M1714cascaded_link_collision_avoidance_calc_distance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1716:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[252], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY1717;
	local[1] = NIL;
KEY1717:
	if (n & (1<<1)) goto KEY1718;
	local[2] = T;
KEY1718:
	if (n & (1<<2)) goto KEY1719;
	local[3] = NIL;
KEY1719:
	if (n & (1<<3)) goto KEY1720;
	local[4] = makeint((eusinteger_t)10L);
KEY1720:
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	local[6]= argv[0];
	local[7]= fqv[184];
	local[8]= fqv[253];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	local[7]= NIL;
	local[8]= NIL;
	if (local[1]==NIL) goto OR1723;
	local[9]= local[5];
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)NUMEQUAL(ctx,2,local+9); /*=*/
	if (w!=NIL) goto OR1723;
	goto IF1721;
OR1723:
	w = NIL;
	ctx->vsp=local+9;
	local[0]=w;
	goto BLK1715;
	goto IF1722;
IF1721:
	local[9]= NIL;
IF1722:
	if (local[6]==NIL) goto OR1726;
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	local[9]= w;
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(*ftab[24])(ctx,2,local+9,&ftab[24],fqv[171]); /*/=*/
	if (w!=NIL) goto OR1726;
	goto IF1724;
OR1726:
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(*ftab[31])(ctx,1,local+9,&ftab[31],fqv[208]); /*make-list*/
	local[6] = w;
	local[9]= local[6];
	goto IF1725;
IF1724:
	local[9]= NIL;
IF1725:
	local[9]= makeint((eusinteger_t)0L);
	local[10]= local[5];
WHL1728:
	local[11]= local[9];
	w = local[10];
	if ((eusinteger_t)local[11] >= (eusinteger_t)w) goto WHX1729;
	local[11]= local[3];
	local[12]= local[9];
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[8] = w;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w = local[1];
	if (memq(local[11],w)!=NIL) goto IF1731;
	local[11]= fqv[254];
	local[12]= local[8];
	local[13]= fqv[3];
	ctx->vsp=local+14;
	w=(*ftab[18])(ctx,2,local+12,&ftab[18],fqv[128]); /*send-all*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(*ftab[2])(ctx,2,local+11,&ftab[2],fqv[15]); /*warn*/
	local[11]= local[6];
	local[12]= local[9];
	local[13]= NIL;
	ctx->vsp=local+14;
	w=(pointer)SETELT(ctx,3,local+11); /*setelt*/
	local[11]= w;
	goto IF1732;
IF1731:
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= fqv[255];
	local[14]= makeint((eusinteger_t)2L);
	ctx->vsp=local+15;
	w=(*ftab[37])(ctx,4,local+11,&ftab[37],fqv[256]); /*pqp-collision-distance*/
	local[11]= w;
	local[12]= makeint((eusinteger_t)0L);
	local[13]= makeint((eusinteger_t)0L);
	local[14]= makeint((eusinteger_t)0L);
	ctx->vsp=local+15;
	w=(pointer)MKFLTVEC(ctx,3,local+12); /*float-vector*/
	local[12]= w;
	local[13]= local[9];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,2,local+12); /*list*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)NCONC(ctx,2,local+11); /*nconc*/
	local[7] = w;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(pointer)LSEQP(ctx,2,local+11); /*<=*/
	if (w==NIL) goto IF1733;
	if (local[2]==NIL) goto IF1735;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+13;
	w=(pointer)LESSP(ctx,2,local+11); /*<*/
	if (w==NIL) goto IF1735;
	local[11]= fqv[257];
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= fqv[3];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[12]= w;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	local[14]= fqv[3];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	local[13]= w;
	local[14]= local[7];
	ctx->vsp=local+15;
	w=(*ftab[2])(ctx,4,local+11,&ftab[2],fqv[15]); /*warn*/
	local[11]= w;
	goto IF1736;
IF1735:
	local[11]= NIL;
IF1736:
	local[11]= local[7];
	local[12]= makeint((eusinteger_t)1L);
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	local[14]= fqv[258];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SETELT(ctx,3,local+11); /*setelt*/
	local[11]= local[6];
	local[12]= local[9];
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(pointer)SETELT(ctx,3,local+11); /*setelt*/
	local[11]= local[6];
	local[12]= local[9];
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	local[12]= makeint((eusinteger_t)0L);
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)SETELT(ctx,3,local+11); /*setelt*/
	local[11]= w;
	goto IF1734;
IF1733:
	local[11]= local[6];
	local[12]= local[9];
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(pointer)SETELT(ctx,3,local+11); /*setelt*/
	local[11]= w;
IF1734:
	local[11]= makeflt(1.0000000000000000208167e-03);
	local[12]= local[7];
	local[13]= makeint((eusinteger_t)1L);
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[12]= w;
	local[13]= local[7];
	local[14]= makeint((eusinteger_t)2L);
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	local[14]= local[7];
	local[15]= makeint((eusinteger_t)3L);
	ctx->vsp=local+16;
	w=(pointer)ELT(ctx,2,local+14); /*elt*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)VMINUS(ctx,3,local+12); /*v-*/
	local[12]= w;
	local[13]= local[7];
	local[14]= makeint((eusinteger_t)3L);
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(*ftab[4])(ctx,2,local+12,&ftab[4],fqv[26]); /*normalize-vector*/
	local[12]= w;
	local[13]= local[7];
	local[14]= makeint((eusinteger_t)3L);
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SCALEVEC(ctx,3,local+11); /*scale*/
	local[11]= w;
IF1732:
	local[11]= local[9];
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[9] = w;
	goto WHL1728;
WHX1729:
	local[11]= NIL;
BLK1730:
	w = NIL;
	local[9]= local[6];
	local[10]= (pointer)get_sym_func(fqv[259]);
	ctx->vsp=local+11;
	local[11]= makeclosure(codevec,quotevec,CLO1737,env,argv,local);
	ctx->vsp=local+12;
	w=(pointer)SORT(ctx,3,local+9); /*sort*/
	local[9]= argv[0];
	local[10]= fqv[150];
	local[11]= fqv[253];
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,4,local+9); /*send*/
	w = T;
	local[0]= w;
BLK1715:
	ctx->vsp=local; return(local[0]);}

/*:collision-avoidance-args*/
static pointer M1738cascaded_link_collision_avoidance_args(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[184];
	local[2]= fqv[260];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[261];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[211];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= NIL;
	local[4]= local[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)GREATERP(ctx,2,local+4); /*>*/
	if (w==NIL) goto IF1740;
	local[4]= local[0];
	local[5]= local[2];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[31])(ctx,1,local+5,&ftab[31],fqv[208]); /*make-list*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)NCONC(ctx,2,local+4); /*nconc*/
	local[0] = w;
	local[4]= local[0];
	goto IF1741;
IF1740:
	local[4]= NIL;
IF1741:
	local[4]= local[0];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SUB1(ctx,1,local+5); /*1-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[3] = w;
	if (local[3]!=NIL) goto IF1742;
	local[4]= local[2];
	local[5]= makeint((eusinteger_t)3L);
	local[6]= local[4];
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(*ftab[23])(ctx,2,local+6,&ftab[23],fqv[166]); /*make-matrix*/
	local[6]= w;
	local[7]= local[4];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(*ftab[23])(ctx,2,local+7,&ftab[23],fqv[166]); /*make-matrix*/
	local[7]= w;
	local[8]= local[4];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(*ftab[23])(ctx,2,local+8,&ftab[23],fqv[166]); /*make-matrix*/
	local[8]= w;
	local[9]= local[5];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(*ftab[23])(ctx,2,local+9,&ftab[23],fqv[166]); /*make-matrix*/
	local[9]= w;
	local[10]= local[5];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(*ftab[23])(ctx,2,local+10,&ftab[23],fqv[166]); /*make-matrix*/
	local[10]= w;
	local[11]= local[4];
	local[12]= local[5];
	ctx->vsp=local+13;
	w=(*ftab[23])(ctx,2,local+11,&ftab[23],fqv[166]); /*make-matrix*/
	local[11]= w;
	local[12]= local[4];
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(*ftab[23])(ctx,2,local+12,&ftab[23],fqv[166]); /*make-matrix*/
	local[12]= w;
	local[13]= local[4];
	local[14]= local[4];
	ctx->vsp=local+15;
	w=(*ftab[23])(ctx,2,local+13,&ftab[23],fqv[166]); /*make-matrix*/
	local[13]= w;
	local[14]= local[5];
	local[15]= local[4];
	ctx->vsp=local+16;
	w=(*ftab[23])(ctx,2,local+14,&ftab[23],fqv[166]); /*make-matrix*/
	local[14]= w;
	local[15]= local[5];
	local[16]= local[5];
	ctx->vsp=local+17;
	w=(*ftab[23])(ctx,2,local+15,&ftab[23],fqv[166]); /*make-matrix*/
	local[15]= w;
	local[16]= local[5];
	local[17]= local[5];
	ctx->vsp=local+18;
	w=(*ftab[23])(ctx,2,local+16,&ftab[23],fqv[166]); /*make-matrix*/
	local[16]= w;
	local[17]= local[5];
	local[18]= local[4];
	ctx->vsp=local+19;
	w=(*ftab[23])(ctx,2,local+17,&ftab[23],fqv[166]); /*make-matrix*/
	local[17]= w;
	local[18]= loadglobal(fqv[5]);
	local[19]= makeint((eusinteger_t)0L);
	ctx->vsp=local+20;
	w=(pointer)INSTANTIATE(ctx,2,local+18); /*instantiate*/
	local[18]= w;
	local[19]= loadglobal(fqv[5]);
	local[20]= makeint((eusinteger_t)1L);
	ctx->vsp=local+21;
	w=(pointer)INSTANTIATE(ctx,2,local+19); /*instantiate*/
	local[19]= w;
	local[20]= loadglobal(fqv[5]);
	local[21]= makeint((eusinteger_t)2L);
	ctx->vsp=local+22;
	w=(pointer)INSTANTIATE(ctx,2,local+20); /*instantiate*/
	local[20]= w;
	local[21]= loadglobal(fqv[5]);
	local[22]= makeint((eusinteger_t)3L);
	ctx->vsp=local+23;
	w=(pointer)INSTANTIATE(ctx,2,local+21); /*instantiate*/
	local[21]= w;
	local[22]= loadglobal(fqv[5]);
	local[23]= makeint((eusinteger_t)3L);
	ctx->vsp=local+24;
	w=(pointer)INSTANTIATE(ctx,2,local+22); /*instantiate*/
	local[22]= w;
	local[23]= loadglobal(fqv[5]);
	local[24]= makeint((eusinteger_t)3L);
	ctx->vsp=local+25;
	w=(pointer)INSTANTIATE(ctx,2,local+23); /*instantiate*/
	local[23]= w;
	local[24]= loadglobal(fqv[5]);
	local[25]= makeint((eusinteger_t)3L);
	ctx->vsp=local+26;
	w=(pointer)INSTANTIATE(ctx,2,local+24); /*instantiate*/
	local[24]= w;
	local[25]= makeint((eusinteger_t)3L);
	local[26]= makeint((eusinteger_t)3L);
	ctx->vsp=local+27;
	w=(*ftab[23])(ctx,2,local+25,&ftab[23],fqv[166]); /*make-matrix*/
	local[25]= w;
	local[26]= loadglobal(fqv[5]);
	local[27]= local[5];
	ctx->vsp=local+28;
	w=(pointer)INSTANTIATE(ctx,2,local+26); /*instantiate*/
	local[26]= w;
	local[27]= loadglobal(fqv[5]);
	local[28]= local[4];
	ctx->vsp=local+29;
	w=(pointer)INSTANTIATE(ctx,2,local+27); /*instantiate*/
	local[27]= w;
	local[28]= loadglobal(fqv[5]);
	local[29]= local[4];
	ctx->vsp=local+30;
	w=(pointer)INSTANTIATE(ctx,2,local+28); /*instantiate*/
	local[28]= w;
	local[29]= loadglobal(fqv[5]);
	local[30]= makeint((eusinteger_t)3L);
	ctx->vsp=local+31;
	w=(pointer)INSTANTIATE(ctx,2,local+29); /*instantiate*/
	local[29]= w;
	local[30]= loadglobal(fqv[5]);
	local[31]= makeint((eusinteger_t)3L);
	ctx->vsp=local+32;
	w=(pointer)INSTANTIATE(ctx,2,local+30); /*instantiate*/
	local[30]= w;
	local[31]= fqv[262];
	local[32]= local[6];
	local[33]= fqv[263];
	local[34]= local[7];
	local[35]= fqv[264];
	local[36]= local[8];
	local[37]= fqv[265];
	local[38]= local[9];
	local[39]= fqv[266];
	local[40]= local[10];
	local[41]= fqv[267];
	local[42]= local[11];
	local[43]= fqv[268];
	local[44]= local[12];
	local[45]= fqv[269];
	local[46]= local[13];
	local[47]= fqv[270];
	local[48]= local[14];
	local[49]= fqv[271];
	local[50]= local[15];
	local[51]= fqv[272];
	local[52]= local[16];
	local[53]= fqv[273];
	local[54]= local[17];
	local[55]= fqv[274];
	local[56]= NIL;
	local[57]= fqv[275];
	local[58]= local[18];
	local[59]= fqv[276];
	local[60]= local[19];
	local[61]= fqv[277];
	local[62]= local[20];
	local[63]= fqv[278];
	local[64]= local[21];
	local[65]= fqv[279];
	local[66]= local[22];
	local[67]= fqv[280];
	local[68]= local[23];
	local[69]= fqv[281];
	local[70]= local[24];
	local[71]= fqv[282];
	local[72]= local[25];
	local[73]= fqv[283];
	local[74]= local[26];
	local[75]= fqv[284];
	local[76]= local[27];
	local[77]= fqv[285];
	local[78]= local[28];
	local[79]= fqv[286];
	local[80]= local[29];
	local[81]= fqv[287];
	local[82]= local[30];
	ctx->vsp=local+83;
	w=(pointer)LIST(ctx,52,local+31); /*list*/
	local[3] = w;
	local[31]= local[0];
	local[32]= local[2];
	ctx->vsp=local+33;
	w=(pointer)SUB1(ctx,1,local+32); /*1-*/
	local[32]= w;
	local[33]= local[3];
	ctx->vsp=local+34;
	w=(pointer)SETELT(ctx,3,local+31); /*setelt*/
	local[31]= argv[0];
	local[32]= fqv[150];
	local[33]= fqv[260];
	local[34]= local[0];
	ctx->vsp=local+35;
	w=(pointer)SEND(ctx,4,local+31); /*send*/
	local[4]= w;
	goto IF1743;
IF1742:
	local[4]= NIL;
IF1743:
	w = local[3];
	local[0]= w;
BLK1739:
	ctx->vsp=local; return(local[0]);}

/*:collision-avoidance*/
static pointer M1744cascaded_link_collision_avoidance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1746:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[288], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY1747;
	local[1] = NIL;
KEY1747:
	if (n & (1<<1)) goto KEY1748;
	local[2] = NIL;
KEY1748:
	if (n & (1<<2)) goto KEY1749;
	local[3] = NIL;
KEY1749:
	if (n & (1<<3)) goto KEY1750;
	local[4] = NIL;
KEY1750:
	if (n & (1<<4)) goto KEY1751;
	local[5] = NIL;
KEY1751:
	if (n & (1<<5)) goto KEY1752;
	local[6] = NIL;
KEY1752:
	if (n & (1<<6)) goto KEY1753;
	local[7] = NIL;
KEY1753:
	if (n & (1<<7)) goto KEY1754;
	local[10]= argv[0];
	local[11]= fqv[211];
	local[12]= local[5];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[8] = w;
KEY1754:
	if (n & (1<<8)) goto KEY1755;
	local[9] = NIL;
KEY1755:
	local[10]= (pointer)get_sym_func(fqv[289]);
	local[11]= argv[0];
	local[12]= fqv[290];
	local[13]= local[0];
	ctx->vsp=local+14;
	w=(pointer)APPLY(ctx,4,local+10); /*apply*/
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)LENGTH(ctx,1,local+10); /*length*/
	local[10]= w;
	local[11]= makeint((eusinteger_t)0L);
	local[12]= loadglobal(fqv[5]);
	local[13]= local[8];
	ctx->vsp=local+14;
	w=(pointer)INSTANTIATE(ctx,2,local+12); /*instantiate*/
	local[12]= w;
	local[13]= argv[0];
	local[14]= fqv[150];
	local[15]= fqv[291];
	local[16]= local[4];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,4,local+13); /*send*/
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!!iscons(w)) goto IF1756;
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	local[6] = w;
	local[13]= local[6];
	goto IF1757;
IF1756:
	local[13]= NIL;
IF1757:
WHL1758:
	local[13]= local[11];
	local[14]= local[10];
	ctx->vsp=local+15;
	w=(pointer)LESSP(ctx,2,local+13); /*<*/
	if (w==NIL) goto WHX1759;
	local[13]= argv[0];
	local[14]= fqv[184];
	local[15]= fqv[253];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= w;
	local[14]= local[11];
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	local[14]= local[4];
	local[15]= local[13];
	ctx->vsp=local+16;
	w=(*ftab[38])(ctx,1,local+15,&ftab[38],fqv[292]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	ctx->vsp=local+16;
	w=(pointer)ELT(ctx,2,local+14); /*elt*/
	local[14]= w;
	local[15]= local[11];
	ctx->vsp=local+16;
	w=(pointer)ADD1(ctx,1,local+15); /*1+*/
	local[11] = w;
	if (local[9]==NIL) goto IF1761;
	local[15]= fqv[202];
	w = local[9];
	if (memq(local[15],w)!=NIL) goto IF1761;
	local[15]= local[13];
	local[16]= makeint((eusinteger_t)1L);
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	local[16]= local[13];
	local[17]= makeint((eusinteger_t)2L);
	ctx->vsp=local+18;
	w=(pointer)ELT(ctx,2,local+16); /*elt*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)VMINUS(ctx,2,local+15); /*v-*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(*ftab[4])(ctx,1,local+15,&ftab[4],fqv[26]); /*normalize-vector*/
	local[15]= w;
	local[16]= fqv[293];
	local[17]= local[13];
	local[18]= makeint((eusinteger_t)0L);
	ctx->vsp=local+19;
	w=(pointer)ELT(ctx,2,local+17); /*elt*/
	local[17]= w;
	local[18]= local[1];
	ctx->vsp=local+19;
	w=(*ftab[2])(ctx,3,local+16,&ftab[2],fqv[15]); /*warn*/
	local[16]= makeint((eusinteger_t)0L);
	local[17]= makeint((eusinteger_t)3L);
WHL1764:
	local[18]= local[16];
	w = local[17];
	if ((eusinteger_t)local[18] >= (eusinteger_t)w) goto WHX1765;
	local[18]= fqv[294];
	local[19]= local[15];
	local[20]= local[16];
	ctx->vsp=local+21;
	w=(pointer)ELT(ctx,2,local+19); /*elt*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(*ftab[2])(ctx,2,local+18,&ftab[2],fqv[15]); /*warn*/
	local[18]= local[16];
	ctx->vsp=local+19;
	w=(pointer)ADD1(ctx,1,local+18); /*1+*/
	local[16] = w;
	goto WHL1764;
WHX1765:
	local[18]= NIL;
BLK1766:
	w = NIL;
	local[16]= fqv[295];
	local[17]= local[14];
	local[18]= fqv[3];
	ctx->vsp=local+19;
	w=(*ftab[18])(ctx,2,local+17,&ftab[18],fqv[128]); /*send-all*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(*ftab[2])(ctx,2,local+16,&ftab[2],fqv[15]); /*warn*/
	local[15]= w;
	goto IF1762;
IF1761:
	local[15]= NIL;
IF1762:
	local[15]= local[13];
	local[16]= makeint((eusinteger_t)0L);
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	local[16]= local[1];
	ctx->vsp=local+17;
	w=(pointer)GREQP(ctx,2,local+15); /*>=*/
	if (w!=NIL) goto IF1767;
	ctx->vsp=local+15;
	local[15]= makeclosure(codevec,quotevec,CLO1769,env,argv,local);
	local[16]= local[6];
	ctx->vsp=local+17;
	w=(*ftab[39])(ctx,2,local+15,&ftab[39],fqv[296]); /*find-if*/
	local[15]= w;
	local[16]= argv[0];
	local[17]= fqv[297];
	local[18]= local[14];
	local[19]= local[15];
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,4,local+16); /*send*/
	local[16]= w;
	local[17]= fqv[105];
	local[18]= local[13];
	local[19]= makeint((eusinteger_t)1L);
	ctx->vsp=local+20;
	w=(pointer)ELT(ctx,2,local+18); /*elt*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(*ftab[40])(ctx,2,local+17,&ftab[40],fqv[298]); /*make-cascoords*/
	local[17]= w;
	local[18]= argv[0];
	local[19]= fqv[261];
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,4,local+18); /*send*/
	local[18]= w;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	local[20]= fqv[299];
	local[21]= local[17];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,3,local+19); /*send*/
	local[19]= (pointer)get_sym_func(fqv[289]);
	local[20]= argv[0];
	local[21]= fqv[300];
	local[22]= local[18];
	local[23]= fqv[301];
	local[24]= local[17];
	local[25]= local[16];
	ctx->vsp=local+26;
	w=(pointer)APPLY(ctx,7,local+19); /*apply*/
	local[19]= w;
	local[20]= local[19];
	ctx->vsp=local+21;
	w=(pointer)TRANSPOSE(ctx,1,local+20); /*transpose*/
	local[20]= w;
	local[21]= local[13];
	local[22]= makeint((eusinteger_t)3L);
	ctx->vsp=local+23;
	w=(pointer)ELT(ctx,2,local+21); /*elt*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)TRANSFORM(ctx,2,local+20); /*transform*/
	local[20]= w;
	local[21]= local[1];
	local[22]= local[13];
	local[23]= makeint((eusinteger_t)0L);
	ctx->vsp=local+24;
	w=(pointer)ELT(ctx,2,local+22); /*elt*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)QUOTIENT(ctx,2,local+21); /*/*/
	local[21]= w;
	local[22]= makeint((eusinteger_t)1L);
	ctx->vsp=local+23;
	w=(pointer)MINUS(ctx,2,local+21); /*-*/
	local[21]= w;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	local[23]= fqv[302];
	local[24]= local[17];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[22]= NIL;
	local[23]= local[18];
WHL1771:
	if (local[23]==NIL) goto WHX1772;
	w=local[23];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24]= (w)->c.cons.car;
	w=local[23];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23] = (w)->c.cons.cdr;
	w = local[24];
	local[22] = w;
	ctx->vsp=local+24;
	local[24]= makeclosure(codevec,quotevec,FLET1775,env,argv,local);
	local[25]= local[22];
	local[26]= local[5];
	w = local[24];
	ctx->vsp=local+27;
	w=FLET1775(ctx,2,local+25,w);
	local[25]= w;
	local[26]= local[22];
	local[27]= local[18];
	w = local[24];
	ctx->vsp=local+28;
	w=FLET1775(ctx,2,local+26,w);
	local[26]= w;
	local[27]= makeint((eusinteger_t)0L);
	local[28]= local[22];
	local[29]= fqv[198];
	ctx->vsp=local+30;
	w=(pointer)SEND(ctx,2,local+28); /*send*/
	local[28]= w;
	ctx->vsp=local+29;
	w=(pointer)LIST(ctx,1,local+28); /*list*/
	local[28]= w;
	ctx->vsp=local+29;
	w=(pointer)F767calc_target_joint_dimension(ctx,1,local+28); /*calc-target-joint-dimension*/
	local[28]= w;
WHL1777:
	local[29]= local[27];
	w = local[28];
	if ((eusinteger_t)local[29] >= (eusinteger_t)w) goto WHX1778;
	local[29]= local[12];
	local[30]= local[27];
	local[31]= local[25];
	ctx->vsp=local+32;
	w=(pointer)PLUS(ctx,2,local+30); /*+*/
	local[30]= w;
	local[31]= local[12];
	local[32]= local[27];
	local[33]= local[25];
	ctx->vsp=local+34;
	w=(pointer)PLUS(ctx,2,local+32); /*+*/
	local[32]= w;
	ctx->vsp=local+33;
	w=(pointer)ELT(ctx,2,local+31); /*elt*/
	local[31]= w;
	local[32]= local[21];
	local[33]= local[20];
	local[34]= local[26];
	local[35]= local[27];
	ctx->vsp=local+36;
	w=(pointer)PLUS(ctx,2,local+34); /*+*/
	local[34]= w;
	ctx->vsp=local+35;
	w=(pointer)ELT(ctx,2,local+33); /*elt*/
	local[33]= w;
	ctx->vsp=local+34;
	w=(pointer)TIMES(ctx,2,local+32); /***/
	local[32]= w;
	ctx->vsp=local+33;
	w=(pointer)PLUS(ctx,2,local+31); /*+*/
	local[31]= w;
	ctx->vsp=local+32;
	w=(pointer)SETELT(ctx,3,local+29); /*setelt*/
	local[29]= local[27];
	ctx->vsp=local+30;
	w=(pointer)ADD1(ctx,1,local+29); /*1+*/
	local[27] = w;
	goto WHL1777;
WHX1778:
	local[29]= NIL;
BLK1779:
	w = NIL;
	goto WHL1771;
WHX1772:
	local[24]= NIL;
BLK1773:
	w = NIL;
	local[15]= w;
	goto IF1768;
IF1767:
	local[15]= NIL;
IF1768:
	w = local[15];
	goto WHL1758;
WHX1759:
	local[13]= NIL;
BLK1760:
	local[13]= makeint((eusinteger_t)0L);
	local[14]= local[8];
WHL1781:
	local[15]= local[13];
	w = local[14];
	if ((eusinteger_t)local[15] >= (eusinteger_t)w) goto WHX1782;
	local[15]= local[12];
	local[16]= local[13];
	local[17]= local[12];
	local[18]= local[13];
	ctx->vsp=local+19;
	w=(pointer)ELT(ctx,2,local+17); /*elt*/
	local[17]= w;
	local[18]= local[7];
	local[19]= local[13];
	ctx->vsp=local+20;
	w=(pointer)ELT(ctx,2,local+18); /*elt*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)TIMES(ctx,2,local+17); /***/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)SETELT(ctx,3,local+15); /*setelt*/
	local[15]= local[13];
	ctx->vsp=local+16;
	w=(pointer)ADD1(ctx,1,local+15); /*1+*/
	local[13] = w;
	goto WHL1781;
WHX1782:
	local[15]= NIL;
BLK1783:
	w = NIL;
	local[13]= argv[0];
	local[14]= fqv[150];
	local[15]= fqv[303];
	local[16]= local[3];
	local[17]= local[12];
	ctx->vsp=local+18;
	w=(pointer)SCALEVEC(ctx,2,local+16); /*scale*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,4,local+13); /*send*/
	local[13]= argv[0];
	local[14]= fqv[150];
	local[15]= fqv[304];
	local[16]= local[2];
	local[17]= local[12];
	ctx->vsp=local+18;
	w=(pointer)SCALEVEC(ctx,2,local+16); /*scale*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,4,local+13); /*send*/
	if (local[9]==NIL) goto IF1784;
	local[13]= fqv[202];
	w = local[9];
	if (memq(local[13],w)!=NIL) goto IF1784;
	local[13]= loadglobal(fqv[5]);
	local[14]= (pointer)get_sym_func(fqv[49]);
	local[15]= argv[0];
	local[16]= fqv[184];
	local[17]= fqv[304];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,3,local+15); /*send*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)MAP(ctx,3,local+13); /*map*/
	local[13]= w;
	local[14]= fqv[305];
	ctx->vsp=local+15;
	w=(*ftab[33])(ctx,2,local+13,&ftab[33],fqv[234]); /*format-array*/
	local[13]= loadglobal(fqv[5]);
	local[14]= (pointer)get_sym_func(fqv[49]);
	local[15]= argv[0];
	local[16]= fqv[184];
	local[17]= fqv[303];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,3,local+15); /*send*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)MAP(ctx,3,local+13); /*map*/
	local[13]= w;
	local[14]= fqv[306];
	ctx->vsp=local+15;
	w=(*ftab[33])(ctx,2,local+13,&ftab[33],fqv[234]); /*format-array*/
	local[13]= w;
	goto IF1785;
IF1784:
	local[13]= NIL;
IF1785:
	w = local[13];
	local[10]= argv[0];
	local[11]= fqv[184];
	local[12]= fqv[304];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[0]= w;
BLK1745:
	ctx->vsp=local; return(local[0]);}

/*:move-joints*/
static pointer M1786cascaded_link_move_joints(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST1788:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[307], &argv[3], n-3, local+1, 1);
	if (n & (1<<0)) goto KEY1789;
	local[1] = NIL;
KEY1789:
	if (n & (1<<1)) goto KEY1790;
	local[2] = makeflt(4.9999999999999988897770e-02);
KEY1790:
	if (n & (1<<2)) goto KEY1791;
	local[3] = NIL;
KEY1791:
	if (n & (1<<3)) goto KEY1792;
	local[4] = NIL;
KEY1792:
	if (n & (1<<4)) goto KEY1793;
	local[5] = NIL;
KEY1793:
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	if (local[4]==NIL) goto IF1794;
	w = local[4];
	if (!!iscons(w)) goto IF1794;
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[4] = w;
	local[9]= local[4];
	goto IF1795;
IF1794:
	local[9]= NIL;
IF1795:
	local[9]= (pointer)get_sym_func(fqv[289]);
	local[10]= argv[0];
	local[11]= fqv[308];
	local[12]= argv[2];
	local[13]= local[0];
	ctx->vsp=local+14;
	w=(pointer)APPLY(ctx,5,local+9); /*apply*/
	local[6] = w;
	local[9]= argv[0];
	local[10]= fqv[309];
	local[11]= local[1];
	local[12]= local[6];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,5,local+9); /*send*/
	local[9]= w;
	local[10]= makeflt(1.0000000000000000000000e+00);
	local[11]= makeint((eusinteger_t)0L);
	local[12]= local[9];
	ctx->vsp=local+13;
	w=(pointer)LENGTH(ctx,1,local+12); /*length*/
	local[12]= w;
WHL1797:
	local[13]= local[11];
	w = local[12];
	if ((eusinteger_t)local[13] >= (eusinteger_t)w) goto WHX1798;
	local[13]= local[9];
	local[14]= local[11];
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	local[14]= local[10];
	ctx->vsp=local+15;
	w=(pointer)LESSP(ctx,2,local+13); /*<*/
	if (w==NIL) goto IF1800;
	local[13]= local[9];
	local[14]= local[11];
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[10] = w;
	local[13]= local[10];
	goto IF1801;
IF1800:
	local[13]= NIL;
IF1801:
	local[13]= local[11];
	ctx->vsp=local+14;
	w=(pointer)ADD1(ctx,1,local+13); /*1+*/
	local[11] = w;
	goto WHL1797;
WHX1798:
	local[13]= NIL;
BLK1799:
	w = NIL;
	local[11]= local[10];
	local[12]= local[6];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(pointer)SCALEVEC(ctx,3,local+11); /*scale*/
	local[6] = w;
	w = local[6];
	if (local[4]==NIL) goto IF1802;
	local[9]= fqv[202];
	w = local[4];
	if (memq(local[9],w)!=NIL) goto IF1802;
	local[9]= loadglobal(fqv[5]);
	local[10]= (pointer)get_sym_func(fqv[49]);
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)MAP(ctx,3,local+9); /*map*/
	local[9]= w;
	local[10]= fqv[310];
	ctx->vsp=local+11;
	w=(*ftab[33])(ctx,2,local+9,&ftab[33],fqv[234]); /*format-array*/
	local[9]= w;
	goto IF1803;
IF1802:
	local[9]= NIL;
IF1803:
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)0L);
TAG1806:
	local[11]= local[10];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)LENGTH(ctx,1,local+12); /*length*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)GREQP(ctx,2,local+11); /*>=*/
	if (w==NIL) goto IF1807;
	w = NIL;
	ctx->vsp=local+11;
	local[9]=w;
	goto BLK1805;
	goto IF1808;
IF1807:
	local[11]= NIL;
IF1808:
	local[11]= local[1];
	local[12]= local[10];
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	local[12]= fqv[198];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[8] = w;
	local[11]= local[8];
	local[12]= fqv[31];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	local[12]= local[11];
	if (fqv[311]!=local[12]) goto IF1810;
	local[12]= local[8];
	local[13]= fqv[312];
	local[14]= local[6];
	local[15]= local[9];
	ctx->vsp=local+16;
	w=(pointer)ELT(ctx,2,local+14); /*elt*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[7] = w;
	local[12]= local[7];
	goto IF1811;
IF1810:
	if (T==NIL) goto IF1812;
	local[12]= local[8];
	local[13]= fqv[312];
	local[14]= local[6];
	local[15]= local[9];
	local[16]= local[9];
	local[17]= local[8];
	local[18]= fqv[31];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)PLUS(ctx,2,local+16); /*+*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)SUBSEQ(ctx,3,local+14); /*subseq*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[7] = w;
	local[12]= local[7];
	goto IF1813;
IF1812:
	local[12]= NIL;
IF1813:
IF1811:
	w = local[12];
	local[11]= (pointer)get_sym_func(fqv[289]);
	local[12]= local[1];
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[12]= w;
	local[13]= fqv[198];
	local[14]= fqv[20];
	local[15]= local[7];
	local[16]= fqv[313];
	local[17]= T;
	local[18]= local[3];
	ctx->vsp=local+19;
	w=(pointer)APPLY(ctx,8,local+11); /*apply*/
	local[11]= local[9];
	local[12]= local[8];
	local[13]= fqv[31];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[11]= w;
	local[12]= local[10];
	ctx->vsp=local+13;
	w=(pointer)ADD1(ctx,1,local+12); /*1+*/
	local[12]= w;
	local[9] = local[11];
	local[10] = local[12];
	w = NIL;
	ctx->vsp=local+11;
	goto TAG1806;
	w = NIL;
	local[9]= w;
BLK1805:
	if (local[5]==NIL) goto IF1816;
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)FUNCALL(ctx,1,local+9); /*funcall*/
	local[9]= w;
	goto IF1817;
IF1816:
	local[9]= NIL;
IF1817:
	w = T;
	local[0]= w;
BLK1787:
	ctx->vsp=local; return(local[0]);}

/*:find-joint-angle-limit-weight-old-from-union-link-list*/
static pointer M1818cascaded_link_find_joint_angle_limit_weight_old_from_union_link_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[3];
	ctx->vsp=local+2;
	w=(*ftab[18])(ctx,2,local+0,&ftab[18],fqv[128]); /*send-all*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[314];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[1]= w;
	local[2]= fqv[139];
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO1820,env,argv,local);
	ctx->vsp=local+4;
	w=(*ftab[41])(ctx,4,local+0,&ftab[41],fqv[315]); /*assoc*/
	local[0]= w;
BLK1819:
	ctx->vsp=local; return(local[0]);}

/*:reset-joint-angle-limit-weight-old*/
static pointer M1821cascaded_link_reset_joint_angle_limit_weight_old(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[316];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	if (local[0]==NIL) goto IF1823;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	local[2]= NIL;
	ctx->vsp=local+3;
	w=(pointer)RPLACA2(ctx,2,local+1); /*rplaca2*/
	local[1]= w;
	goto IF1824;
IF1823:
	local[1]= NIL;
IF1824:
	w = local[1];
	local[0]= w;
BLK1822:
	ctx->vsp=local; return(local[0]);}

/*:calc-weight-from-joint-limit*/
static pointer M1825cascaded_link_calc_weight_from_joint_limit(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=10) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= fqv[316];
	local[4]= argv[5];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	if (local[2]!=NIL) goto IF1827;
	local[3]= argv[0];
	local[4]= fqv[150];
	local[5]= fqv[314];
	local[6]= argv[5];
	local[7]= fqv[3];
	ctx->vsp=local+8;
	w=(*ftab[18])(ctx,2,local+6,&ftab[18],fqv[128]); /*send-all*/
	local[6]= w;
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= fqv[314];
	ctx->vsp=local+9;
	w=(pointer)GETPROP(ctx,2,local+7); /*get*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= argv[0];
	local[4]= fqv[316];
	local[5]= argv[5];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[2] = w;
	local[3]= local[2];
	goto IF1828;
IF1827:
	local[3]= NIL;
IF1828:
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car!=NIL) goto IF1829;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	local[4]= loadglobal(fqv[5]);
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)INSTANTIATE(ctx,2,local+4); /*instantiate*/
	local[4]= w;
	local[5]= makeflt(1.0000000000000000000000e+20);
	ctx->vsp=local+6;
	w=(*ftab[36])(ctx,2,local+4,&ftab[36],fqv[243]); /*fill*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)RPLACA2(ctx,2,local+3); /*rplaca2*/
	local[3]= w;
	goto IF1830;
IF1829:
	local[3]= NIL;
IF1830:
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	w = local[0];
	local[2]= argv[2];
	local[3]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto IF1831;
	local[2]= argv[2];
	local[3]= argv[5];
	local[4]= fqv[198];
	ctx->vsp=local+5;
	w=(*ftab[18])(ctx,2,local+3,&ftab[18],fqv[128]); /*send-all*/
	local[3]= w;
	local[4]= argv[9];
	ctx->vsp=local+5;
	w=(pointer)F769joint_angle_limit_weight(ctx,2,local+3); /*joint-angle-limit-weight*/
	local[3]= w;
	local[4]= argv[9];
	ctx->vsp=local+5;
	w=(pointer)SCALEVEC(ctx,3,local+2); /*scale*/
	local[1] = w;
	if (argv[6]==NIL) goto IF1833;
	local[2]= fqv[202];
	w = argv[6];
	if (memq(local[2],w)!=NIL) goto IF1833;
	local[2]= local[0];
	local[3]= fqv[317];
	ctx->vsp=local+4;
	w=(*ftab[33])(ctx,2,local+2,&ftab[33],fqv[234]); /*format-array*/
	local[2]= local[1];
	local[3]= fqv[318];
	ctx->vsp=local+4;
	w=(*ftab[33])(ctx,2,local+2,&ftab[33],fqv[234]); /*format-array*/
	local[2]= w;
	goto IF1834;
IF1833:
	local[2]= NIL;
IF1834:
	local[2]= makeint((eusinteger_t)0L);
	local[3]= argv[3];
WHL1836:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX1837;
	local[4]= argv[8];
	local[5]= local[2];
	local[6]= local[1];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	local[7]= local[0];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	local[7]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+8;
	w=(pointer)GREQP(ctx,2,local+6); /*>=*/
	if (w==NIL) goto IF1839;
	local[6]= makeflt(1.0000000000000000000000e+00);
	local[7]= makeflt(1.0000000000000000000000e+00);
	local[8]= local[1];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	goto IF1840;
IF1839:
	local[6]= makeflt(1.0000000000000000000000e+00);
IF1840:
	ctx->vsp=local+7;
	w=(pointer)SETELT(ctx,3,local+4); /*setelt*/
	local[4]= local[0];
	local[5]= local[2];
	local[6]= local[1];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SETELT(ctx,3,local+4); /*setelt*/
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL1836;
WHX1837:
	local[4]= NIL;
BLK1838:
	w = NIL;
	local[2]= w;
	goto IF1832;
IF1831:
	local[2]= NIL;
IF1832:
	local[2]= argv[2];
	local[3]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+4;
	w=(pointer)NUMEQUAL(ctx,2,local+2); /*=*/
	if (w==NIL) goto IF1841;
	local[2]= makeint((eusinteger_t)0L);
	local[3]= argv[3];
WHL1844:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX1845;
	local[4]= argv[8];
	local[5]= local[2];
	local[6]= argv[7];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SETELT(ctx,3,local+4); /*setelt*/
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL1844;
WHX1845:
	local[4]= NIL;
BLK1846:
	w = NIL;
	local[2]= w;
	goto IF1842;
IF1841:
	local[2]= NIL;
IF1842:
	local[2]= makeint((eusinteger_t)0L);
	local[3]= NIL;
	local[4]= argv[5];
WHL1848:
	if (local[4]==NIL) goto WHX1849;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO1852,env,argv,local);
	local[6]= argv[4];
	ctx->vsp=local+7;
	w=(*ftab[42])(ctx,2,local+5,&ftab[42],fqv[319]); /*count-if*/
	local[5]= w;
	local[6]= local[3];
	local[7]= fqv[198];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)F767calc_target_joint_dimension(ctx,1,local+6); /*calc-target-joint-dimension*/
	local[6]= w;
	local[7]= local[5];
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)GREATERP(ctx,2,local+7); /*>*/
	if (w==NIL) goto IF1853;
	local[7]= makeint((eusinteger_t)0L);
	local[8]= local[6];
WHL1856:
	local[9]= local[7];
	w = local[8];
	if ((eusinteger_t)local[9] >= (eusinteger_t)w) goto WHX1857;
	local[9]= argv[8];
	local[10]= local[2];
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[10]= w;
	local[11]= argv[8];
	local[12]= local[2];
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,2,local+12); /*+*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	local[12]= local[5];
	ctx->vsp=local+13;
	w=(pointer)QUOTIENT(ctx,2,local+11); /*/*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)SETELT(ctx,3,local+9); /*setelt*/
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	local[7] = w;
	goto WHL1856;
WHX1857:
	local[9]= NIL;
BLK1858:
	w = NIL;
	local[7]= w;
	goto IF1854;
IF1853:
	local[7]= NIL;
IF1854:
	local[7]= local[2];
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[2] = w;
	w = local[2];
	goto WHL1848;
WHX1849:
	local[5]= NIL;
BLK1850:
	w = NIL;
	w = argv[8];
	local[0]= w;
BLK1826:
	ctx->vsp=local; return(local[0]);}

/*:calc-inverse-kinematics-weight-from-link-list*/
static pointer M1859cascaded_link_calc_inverse_kinematics_weight_from_link_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[320], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY1861;
	local[0] = makeflt(1.0000000000000000000000e+00);
KEY1861:
	if (n & (1<<1)) goto KEY1862;
	local[8]= argv[0];
	local[9]= fqv[197];
	local[10]= argv[2];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[1] = w;
KEY1862:
	if (n & (1<<2)) goto KEY1863;
	local[8]= argv[0];
	local[9]= fqv[211];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[2] = w;
KEY1863:
	if (n & (1<<3)) goto KEY1864;
	local[8]= loadglobal(fqv[5]);
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,2,local+8); /*instantiate*/
	local[8]= w;
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(*ftab[36])(ctx,2,local+8,&ftab[36],fqv[243]); /*fill*/
	local[3] = w;
KEY1864:
	if (n & (1<<4)) goto KEY1865;
	local[4] = NIL;
KEY1865:
	if (n & (1<<5)) goto KEY1866;
	local[5] = NIL;
KEY1866:
	if (n & (1<<6)) goto KEY1867;
	local[8]= loadglobal(fqv[5]);
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,2,local+8); /*instantiate*/
	local[6] = w;
KEY1867:
	if (n & (1<<7)) goto KEY1868;
	local[8]= loadglobal(fqv[5]);
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,2,local+8); /*instantiate*/
	local[7] = w;
KEY1868:
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[43])(ctx,1,local+8,&ftab[43],fqv[321]); /*functionp*/
	if (w==NIL) goto CON1870;
	local[8]= local[3];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)FUNCALL(ctx,2,local+8); /*funcall*/
	local[3] = w;
	local[8]= local[3];
	goto CON1869;
CON1870:
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)LISTP(ctx,1,local+8); /*listp*/
	if (w==NIL) goto CON1871;
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)EVAL(ctx,1,local+8); /*eval*/
	local[3] = w;
	local[8]= local[3];
	goto CON1869;
CON1871:
	local[8]= NIL;
CON1869:
	if (local[5]==NIL) goto IF1872;
	local[8]= fqv[202];
	w = local[5];
	if (memq(local[8],w)!=NIL) goto IF1872;
	local[8]= local[3];
	local[9]= fqv[322];
	ctx->vsp=local+10;
	w=(*ftab[33])(ctx,2,local+8,&ftab[33],fqv[234]); /*format-array*/
	local[8]= w;
	goto IF1873;
IF1872:
	local[8]= NIL;
IF1873:
	local[8]= NIL;
	local[9]= local[4];
WHL1875:
	if (local[9]==NIL) goto WHX1876;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= local[1];
	local[12]= fqv[139];
	local[13]= (pointer)get_sym_func(fqv[140]);
	ctx->vsp=local+14;
	w=(*ftab[32])(ctx,4,local+10,&ftab[32],fqv[213]); /*position*/
	local[10]= w;
	if (local[10]==NIL) goto IF1879;
	local[11]= (pointer)get_sym_func(fqv[323]);
	local[12]= local[1];
	local[13]= makeint((eusinteger_t)0L);
	local[14]= local[10];
	ctx->vsp=local+15;
	w=(pointer)SUBSEQ(ctx,3,local+12); /*subseq*/
	local[12]= w;
	local[13]= fqv[198];
	ctx->vsp=local+14;
	w=(*ftab[18])(ctx,2,local+12,&ftab[18],fqv[128]); /*send-all*/
	local[12]= w;
	local[13]= fqv[31];
	ctx->vsp=local+14;
	w=(*ftab[18])(ctx,2,local+12,&ftab[18],fqv[128]); /*send-all*/
	local[12]= w;
	local[13]= fqv[324];
	local[14]= makeint((eusinteger_t)0L);
	ctx->vsp=local+15;
	w=(*ftab[26])(ctx,4,local+11,&ftab[26],fqv[196]); /*reduce*/
	local[11]= w;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	ctx->vsp=local+13;
	w=(*ftab[43])(ctx,1,local+12,&ftab[43],fqv[321]); /*functionp*/
	if (w==NIL) goto IF1881;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	ctx->vsp=local+13;
	w=(pointer)FUNCALL(ctx,1,local+12); /*funcall*/
	local[12]= w;
	goto IF1882;
IF1881:
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
IF1882:
	local[13]= makeint((eusinteger_t)0L);
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	local[15]= fqv[198];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,2,local+14); /*send*/
	local[14]= w;
	local[15]= fqv[31];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,2,local+14); /*send*/
	local[14]= w;
WHL1884:
	local[15]= local[13];
	w = local[14];
	if ((eusinteger_t)local[15] >= (eusinteger_t)w) goto WHX1885;
	local[15]= local[3];
	local[16]= local[13];
	local[17]= local[11];
	ctx->vsp=local+18;
	w=(pointer)PLUS(ctx,2,local+16); /*+*/
	local[16]= w;
	local[17]= local[3];
	local[18]= local[13];
	local[19]= local[11];
	ctx->vsp=local+20;
	w=(pointer)PLUS(ctx,2,local+18); /*+*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)ELT(ctx,2,local+17); /*elt*/
	local[17]= w;
	local[18]= local[12];
	ctx->vsp=local+19;
	w=(*ftab[0])(ctx,1,local+18,&ftab[0],fqv[4]); /*float-vector-p*/
	if (w==NIL) goto IF1887;
	local[18]= local[12];
	local[19]= local[13];
	ctx->vsp=local+20;
	w=(pointer)ELT(ctx,2,local+18); /*elt*/
	local[18]= w;
	goto IF1888;
IF1887:
	local[18]= local[12];
IF1888:
	ctx->vsp=local+19;
	w=(pointer)TIMES(ctx,2,local+17); /***/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)SETELT(ctx,3,local+15); /*setelt*/
	local[15]= local[13];
	ctx->vsp=local+16;
	w=(pointer)ADD1(ctx,1,local+15); /*1+*/
	local[13] = w;
	goto WHL1884;
WHX1885:
	local[15]= NIL;
BLK1886:
	w = NIL;
	local[11]= w;
	goto IF1880;
IF1879:
	local[11]= NIL;
IF1880:
	w = local[11];
	goto WHL1875;
WHX1876:
	local[10]= NIL;
BLK1877:
	w = NIL;
	if (local[5]==NIL) goto IF1889;
	local[8]= fqv[202];
	w = local[5];
	if (memq(local[8],w)!=NIL) goto IF1889;
	if (local[4]==NIL) goto IF1889;
	local[8]= local[3];
	local[9]= fqv[325];
	ctx->vsp=local+10;
	w=(*ftab[33])(ctx,2,local+8,&ftab[33],fqv[234]); /*format-array*/
	local[8]= w;
	goto IF1890;
IF1889:
	local[8]= NIL;
IF1890:
	local[8]= argv[0];
	local[9]= fqv[326];
	local[10]= local[0];
	local[11]= local[2];
	local[12]= argv[2];
	local[13]= local[1];
	local[14]= local[5];
	local[15]= local[3];
	local[16]= local[6];
	local[17]= local[7];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,10,local+8); /*send*/
	local[6] = w;
	local[8]= makeint((eusinteger_t)0L);
	local[9]= local[2];
WHL1892:
	local[10]= local[8];
	w = local[9];
	if ((eusinteger_t)local[10] >= (eusinteger_t)w) goto WHX1893;
	local[10]= local[6];
	local[11]= local[8];
	local[12]= local[3];
	local[13]= local[8];
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[12]= w;
	local[13]= local[6];
	local[14]= local[8];
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)TIMES(ctx,2,local+12); /***/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)SETELT(ctx,3,local+10); /*setelt*/
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[8] = w;
	goto WHL1892;
WHX1893:
	local[10]= NIL;
BLK1894:
	w = NIL;
	if (local[5]==NIL) goto IF1895;
	local[8]= fqv[202];
	w = local[5];
	if (memq(local[8],w)!=NIL) goto IF1895;
	local[8]= local[6];
	local[9]= fqv[327];
	ctx->vsp=local+10;
	w=(*ftab[33])(ctx,2,local+8,&ftab[33],fqv[234]); /*format-array*/
	local[8]= w;
	goto IF1896;
IF1895:
	local[8]= NIL;
IF1896:
	w = local[6];
	local[0]= w;
BLK1860:
	ctx->vsp=local; return(local[0]);}

/*:calc-nspace-from-joint-limit*/
static pointer M1897cascaded_link_calc_nspace_from_joint_limit(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=7) maerror();
	local[0]= argv[2];
	local[1]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF1899;
	local[0]= argv[2];
	local[1]= argv[3];
	local[2]= fqv[198];
	ctx->vsp=local+3;
	w=(*ftab[18])(ctx,2,local+1,&ftab[18],fqv[128]); /*send-all*/
	local[1]= w;
	local[2]= argv[6];
	ctx->vsp=local+3;
	w=(pointer)F770joint_angle_limit_nspace(ctx,2,local+1); /*joint-angle-limit-nspace*/
	local[1]= w;
	local[2]= argv[6];
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,3,local+0); /*scale*/
	argv[6] = w;
	local[0]= makeint((eusinteger_t)0L);
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
WHL1902:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX1903;
	local[2]= argv[6];
	local[3]= local[0];
	local[4]= argv[6];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	local[5]= argv[4];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SETELT(ctx,3,local+2); /*setelt*/
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL1902;
WHX1903:
	local[2]= NIL;
BLK1904:
	w = NIL;
	if (argv[5]==NIL) goto IF1905;
	local[0]= fqv[202];
	w = argv[5];
	if (memq(local[0],w)!=NIL) goto IF1905;
	local[0]= loadglobal(fqv[5]);
	local[1]= (pointer)get_sym_func(fqv[49]);
	local[2]= argv[6];
	ctx->vsp=local+3;
	w=(pointer)MAP(ctx,3,local+0); /*map*/
	local[0]= w;
	local[1]= fqv[328];
	ctx->vsp=local+2;
	w=(*ftab[33])(ctx,2,local+0,&ftab[33],fqv[234]); /*format-array*/
	local[0]= w;
	goto IF1906;
IF1905:
	local[0]= NIL;
IF1906:
	goto IF1900;
IF1899:
	local[0]= NIL;
IF1900:
	w = argv[6];
	local[0]= w;
BLK1898:
	ctx->vsp=local; return(local[0]);}

/*:calc-inverse-kinematics-nspace-from-link-list*/
static pointer M1907cascaded_link_calc_inverse_kinematics_nspace_from_link_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[329], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY1909;
	local[0] = makeflt(9.9999999999999950039964e-03);
KEY1909:
	if (n & (1<<1)) goto KEY1910;
	local[14]= argv[0];
	local[15]= fqv[197];
	local[16]= argv[2];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[1] = w;
KEY1910:
	if (n & (1<<2)) goto KEY1911;
	local[14]= argv[0];
	local[15]= fqv[211];
	local[16]= local[1];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[2] = w;
KEY1911:
	if (n & (1<<3)) goto KEY1912;
	local[3] = NIL;
KEY1912:
	if (n & (1<<4)) goto KEY1913;
	local[4] = NIL;
KEY1913:
	if (n & (1<<5)) goto KEY1914;
	local[5] = NIL;
KEY1914:
	if (n & (1<<6)) goto KEY1915;
	local[6] = makeflt(0.0000000000000000000000e+00);
KEY1915:
	if (n & (1<<7)) goto KEY1916;
	local[7] = NIL;
KEY1916:
	if (n & (1<<8)) goto KEY1917;
	local[8] = NIL;
KEY1917:
	if (n & (1<<9)) goto KEY1918;
	local[9] = fqv[33];
KEY1918:
	if (n & (1<<10)) goto KEY1919;
	local[10] = NIL;
KEY1919:
	if (n & (1<<11)) goto KEY1920;
	local[14]= loadglobal(fqv[5]);
	local[15]= local[2];
	ctx->vsp=local+16;
	w=(pointer)INSTANTIATE(ctx,2,local+14); /*instantiate*/
	local[14]= w;
	local[15]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+16;
	w=(*ftab[36])(ctx,2,local+14,&ftab[36],fqv[243]); /*fill*/
	local[11] = w;
KEY1920:
	if (n & (1<<12)) goto KEY1921;
	local[12] = T;
KEY1921:
	if (n & (1<<13)) goto KEY1922;
	local[14]= loadglobal(fqv[5]);
	local[15]= local[2];
	ctx->vsp=local+16;
	w=(pointer)INSTANTIATE(ctx,2,local+14); /*instantiate*/
	local[13] = w;
KEY1922:
	local[14]= argv[0];
	local[15]= fqv[330];
	local[16]= local[0];
	local[17]= local[1];
	local[18]= local[11];
	local[19]= local[4];
	local[20]= local[13];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,7,local+14); /*send*/
	local[13] = w;
	if (local[10]==NIL) goto IF1923;
	local[14]= local[6];
	local[15]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+16;
	w=(pointer)GREATERP(ctx,2,local+14); /*>*/
	if (w==NIL) goto IF1925;
	if (local[7]==NIL) goto IF1925;
	local[14]= argv[0];
	local[15]= fqv[331];
	local[16]= local[1];
	local[17]= fqv[274];
	local[18]= local[11];
	local[19]= fqv[332];
	local[20]= local[8];
	local[21]= fqv[333];
	local[22]= local[12];
	local[23]= fqv[334];
	local[24]= local[7];
	local[25]= fqv[335];
	local[26]= local[6];
	local[27]= fqv[336];
	local[28]= local[9];
	ctx->vsp=local+29;
	w=(pointer)SEND(ctx,15,local+14); /*send*/
	local[14]= w;
	local[15]= local[13];
	local[16]= local[13];
	ctx->vsp=local+17;
	w=(pointer)VPLUS(ctx,3,local+14); /*v+*/
	local[13] = w;
	local[14]= local[13];
	goto IF1926;
IF1925:
	local[14]= NIL;
IF1926:
	goto IF1924;
IF1923:
	local[14]= NIL;
IF1924:
	local[14]= NIL;
	local[15]= local[5];
WHL1928:
	if (local[15]==NIL) goto WHX1929;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15] = (w)->c.cons.cdr;
	w = local[16];
	local[14] = w;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	local[17]= local[1];
	local[18]= fqv[139];
	local[19]= (pointer)get_sym_func(fqv[140]);
	ctx->vsp=local+20;
	w=(*ftab[32])(ctx,4,local+16,&ftab[32],fqv[213]); /*position*/
	local[16]= w;
	if (local[16]==NIL) goto IF1932;
	local[17]= (pointer)get_sym_func(fqv[323]);
	local[18]= local[1];
	local[19]= makeint((eusinteger_t)0L);
	local[20]= local[16];
	ctx->vsp=local+21;
	w=(pointer)SUBSEQ(ctx,3,local+18); /*subseq*/
	local[18]= w;
	local[19]= fqv[198];
	ctx->vsp=local+20;
	w=(*ftab[18])(ctx,2,local+18,&ftab[18],fqv[128]); /*send-all*/
	local[18]= w;
	local[19]= fqv[31];
	ctx->vsp=local+20;
	w=(*ftab[18])(ctx,2,local+18,&ftab[18],fqv[128]); /*send-all*/
	local[18]= w;
	local[19]= fqv[324];
	local[20]= makeint((eusinteger_t)0L);
	ctx->vsp=local+21;
	w=(*ftab[26])(ctx,4,local+17,&ftab[26],fqv[196]); /*reduce*/
	local[17]= w;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	ctx->vsp=local+19;
	w=(*ftab[43])(ctx,1,local+18,&ftab[43],fqv[321]); /*functionp*/
	if (w==NIL) goto IF1934;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	ctx->vsp=local+19;
	w=(pointer)FUNCALL(ctx,1,local+18); /*funcall*/
	local[18]= w;
	goto IF1935;
IF1934:
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
IF1935:
	local[19]= makeint((eusinteger_t)0L);
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	local[21]= fqv[198];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,2,local+20); /*send*/
	local[20]= w;
	local[21]= fqv[31];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,2,local+20); /*send*/
	local[20]= w;
WHL1937:
	local[21]= local[19];
	w = local[20];
	if ((eusinteger_t)local[21] >= (eusinteger_t)w) goto WHX1938;
	local[21]= local[13];
	local[22]= local[19];
	local[23]= local[17];
	ctx->vsp=local+24;
	w=(pointer)PLUS(ctx,2,local+22); /*+*/
	local[22]= w;
	local[23]= local[13];
	local[24]= local[19];
	local[25]= local[17];
	ctx->vsp=local+26;
	w=(pointer)PLUS(ctx,2,local+24); /*+*/
	local[24]= w;
	ctx->vsp=local+25;
	w=(pointer)ELT(ctx,2,local+23); /*elt*/
	local[23]= w;
	local[24]= local[18];
	ctx->vsp=local+25;
	w=(*ftab[0])(ctx,1,local+24,&ftab[0],fqv[4]); /*float-vector-p*/
	if (w==NIL) goto IF1940;
	local[24]= local[18];
	local[25]= local[19];
	ctx->vsp=local+26;
	w=(pointer)ELT(ctx,2,local+24); /*elt*/
	local[24]= w;
	goto IF1941;
IF1940:
	local[24]= local[18];
IF1941:
	local[25]= local[11];
	local[26]= local[19];
	local[27]= local[17];
	ctx->vsp=local+28;
	w=(pointer)PLUS(ctx,2,local+26); /*+*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)ELT(ctx,2,local+25); /*elt*/
	local[25]= w;
	ctx->vsp=local+26;
	w=(pointer)TIMES(ctx,2,local+24); /***/
	local[24]= w;
	ctx->vsp=local+25;
	w=(pointer)PLUS(ctx,2,local+23); /*+*/
	local[23]= w;
	ctx->vsp=local+24;
	w=(pointer)SETELT(ctx,3,local+21); /*setelt*/
	local[21]= local[19];
	ctx->vsp=local+22;
	w=(pointer)ADD1(ctx,1,local+21); /*1+*/
	local[19] = w;
	goto WHL1937;
WHX1938:
	local[21]= NIL;
BLK1939:
	w = NIL;
	local[17]= w;
	goto IF1933;
IF1932:
	local[17]= NIL;
IF1933:
	w = local[17];
	goto WHL1928;
WHX1929:
	local[16]= NIL;
BLK1930:
	w = NIL;
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(*ftab[43])(ctx,1,local+14,&ftab[43],fqv[321]); /*functionp*/
	if (w==NIL) goto CON1943;
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(pointer)FUNCALL(ctx,1,local+14); /*funcall*/
	local[3] = w;
	local[14]= local[3];
	goto CON1942;
CON1943:
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(pointer)LISTP(ctx,1,local+14); /*listp*/
	if (w==NIL) goto CON1944;
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(pointer)EVAL(ctx,1,local+14); /*eval*/
	local[3] = w;
	local[14]= local[3];
	goto CON1942;
CON1944:
	local[14]= NIL;
CON1942:
	if (local[3]==NIL) goto IF1945;
	local[14]= local[3];
	local[15]= local[13];
	local[16]= local[13];
	ctx->vsp=local+17;
	w=(pointer)VPLUS(ctx,3,local+14); /*v+*/
	local[13] = w;
	local[14]= local[13];
	goto IF1946;
IF1945:
	local[14]= NIL;
IF1946:
	w = local[13];
	local[0]= w;
BLK1908:
	ctx->vsp=local; return(local[0]);}

/*:move-joints-avoidance*/
static pointer M1947cascaded_link_move_joints_avoidance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST1949:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[337], &argv[3], n-3, local+1, 1);
	if (n & (1<<0)) goto KEY1950;
	local[1] = NIL;
KEY1950:
	if (n & (1<<1)) goto KEY1951;
	local[2] = NIL;
KEY1951:
	if (n & (1<<2)) goto KEY1952;
	local[27]= argv[0];
	local[28]= fqv[211];
	local[29]= local[1];
	ctx->vsp=local+30;
	w=(pointer)SEND(ctx,3,local+27); /*send*/
	local[3] = w;
KEY1952:
	if (n & (1<<3)) goto KEY1953;
	local[27]= loadglobal(fqv[5]);
	local[28]= local[3];
	ctx->vsp=local+29;
	w=(pointer)INSTANTIATE(ctx,2,local+27); /*instantiate*/
	local[27]= w;
	local[28]= makeint((eusinteger_t)1L);
	ctx->vsp=local+29;
	w=(*ftab[36])(ctx,2,local+27,&ftab[36],fqv[243]); /*fill*/
	local[4] = w;
KEY1953:
	if (n & (1<<4)) goto KEY1954;
	local[5] = NIL;
KEY1954:
	if (n & (1<<5)) goto KEY1955;
	local[6] = makeflt(9.9999999999999950039964e-03);
KEY1955:
	if (n & (1<<6)) goto KEY1956;
	local[7] = makeflt(1.0000000000000000000000e+00);
KEY1956:
	if (n & (1<<7)) goto KEY1957;
	local[8] = makeint((eusinteger_t)200L);
KEY1957:
	if (n & (1<<8)) goto KEY1958;
	local[9] = makeflt(1.0000000000000000000000e+00);
KEY1958:
	if (n & (1<<9)) goto KEY1959;
	local[10] = makeflt(1.0000000000000000000000e+00);
KEY1959:
	if (n & (1<<10)) goto KEY1960;
	local[27]= argv[0];
	local[28]= fqv[338];
	local[29]= local[2];
	local[30]= fqv[339];
	local[31]= fqv[339];
	w = local[0];
	w=memq(local[31],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[31]= (w)->c.cons.car;
	local[32]= fqv[340];
	local[33]= fqv[341];
	w = local[0];
	w=memq(local[33],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[33]= (w)->c.cons.car;
	ctx->vsp=local+34;
	w=(pointer)SEND(ctx,7,local+27); /*send*/
	local[11] = w;
KEY1960:
	if (n & (1<<11)) goto KEY1961;
	local[12] = makeflt(0.0000000000000000000000e+00);
KEY1961:
	if (n & (1<<12)) goto KEY1962;
	local[13] = NIL;
KEY1962:
	if (n & (1<<13)) goto KEY1963;
	local[14] = NIL;
KEY1963:
	if (n & (1<<14)) goto KEY1964;
	local[15] = fqv[33];
KEY1964:
	if (n & (1<<15)) goto KEY1965;
	local[16] = NIL;
KEY1965:
	if (n & (1<<16)) goto KEY1966;
	local[17] = NIL;
KEY1966:
	if (n & (1<<17)) goto KEY1967;
	local[18] = NIL;
KEY1967:
	if (n & (1<<18)) goto KEY1968;
	local[27]= loadglobal(fqv[5]);
	local[28]= local[3];
	ctx->vsp=local+29;
	w=(pointer)INSTANTIATE(ctx,2,local+27); /*instantiate*/
	local[19] = w;
KEY1968:
	if (n & (1<<19)) goto KEY1969;
	local[27]= loadglobal(fqv[5]);
	local[28]= local[3];
	ctx->vsp=local+29;
	w=(pointer)INSTANTIATE(ctx,2,local+27); /*instantiate*/
	local[20] = w;
KEY1969:
	if (n & (1<<20)) goto KEY1970;
	local[27]= loadglobal(fqv[5]);
	local[28]= local[3];
	ctx->vsp=local+29;
	w=(pointer)INSTANTIATE(ctx,2,local+27); /*instantiate*/
	local[21] = w;
KEY1970:
	if (n & (1<<21)) goto KEY1971;
	local[27]= loadglobal(fqv[5]);
	local[28]= local[3];
	ctx->vsp=local+29;
	w=(pointer)INSTANTIATE(ctx,2,local+27); /*instantiate*/
	local[22] = w;
KEY1971:
	if (n & (1<<22)) goto KEY1972;
	local[27]= local[3];
	local[28]= local[3];
	ctx->vsp=local+29;
	w=(*ftab[23])(ctx,2,local+27,&ftab[23],fqv[166]); /*make-matrix*/
	local[23] = w;
KEY1972:
	if (n & (1<<23)) goto KEY1973;
	local[27]= local[3];
	local[28]= local[3];
	ctx->vsp=local+29;
	w=(*ftab[23])(ctx,2,local+27,&ftab[23],fqv[166]); /*make-matrix*/
	local[24] = w;
KEY1973:
	if (n & (1<<24)) goto KEY1974;
	local[25] = NIL;
KEY1974:
	if (n & (1<<25)) goto KEY1975;
	local[26] = NIL;
KEY1975:
	local[27]= NIL;
	local[28]= NIL;
	local[29]= NIL;
	local[30]= NIL;
	local[31]= NIL;
	local[32]= makeflt(0.0000000000000000000000e+00);
	local[33]= NIL;
	local[34]= NIL;
	local[35]= NIL;
	if (local[26]!=NIL) goto IF1976;
	local[36]= fqv[342];
	ctx->vsp=local+37;
	w=(*ftab[2])(ctx,1,local+36,&ftab[2],fqv[15]); /*warn*/
	w = T;
	ctx->vsp=local+36;
	local[0]=w;
	goto BLK1948;
	goto IF1977;
IF1976:
	local[36]= NIL;
IF1977:
	if (local[25]==NIL) goto IF1978;
	w = local[25];
	if (!!iscons(w)) goto IF1978;
	local[36]= local[25];
	ctx->vsp=local+37;
	w=(pointer)LIST(ctx,1,local+36); /*list*/
	local[25] = w;
	local[36]= local[25];
	goto IF1979;
IF1978:
	local[36]= NIL;
IF1979:
	if (local[25]==NIL) goto IF1980;
	local[36]= fqv[202];
	w = local[25];
	if (memq(local[36],w)!=NIL) goto IF1980;
	local[36]= fqv[343];
	ctx->vsp=local+37;
	w=(*ftab[2])(ctx,1,local+36,&ftab[2],fqv[15]); /*warn*/
	local[36]= NIL;
	local[37]= local[1];
	local[38]= fqv[198];
	ctx->vsp=local+39;
	w=(*ftab[18])(ctx,2,local+37,&ftab[18],fqv[128]); /*send-all*/
	local[37]= w;
WHL1983:
	if (local[37]==NIL) goto WHX1984;
	w=local[37];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[38]= (w)->c.cons.car;
	w=local[37];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[37] = (w)->c.cons.cdr;
	w = local[38];
	local[36] = w;
	local[38]= local[36];
	local[39]= fqv[20];
	ctx->vsp=local+40;
	w=(pointer)SEND(ctx,2,local+38); /*send*/
	local[38]= w;
	local[39]= local[38];
	ctx->vsp=local+40;
	w=(pointer)VECTORP(ctx,1,local+39); /*vectorp*/
	if (w==NIL) goto IF1987;
	local[39]= makeint((eusinteger_t)0L);
	local[40]= local[38];
	ctx->vsp=local+41;
	w=(pointer)LENGTH(ctx,1,local+40); /*length*/
	local[40]= w;
WHL1990:
	local[41]= local[39];
	w = local[40];
	if ((eusinteger_t)local[41] >= (eusinteger_t)w) goto WHX1991;
	local[41]= fqv[344];
	local[42]= local[38];
	local[43]= local[39];
	ctx->vsp=local+44;
	w=(pointer)ELT(ctx,2,local+42); /*elt*/
	local[42]= w;
	ctx->vsp=local+43;
	w=(*ftab[2])(ctx,2,local+41,&ftab[2],fqv[15]); /*warn*/
	local[41]= local[39];
	ctx->vsp=local+42;
	w=(pointer)ADD1(ctx,1,local+41); /*1+*/
	local[39] = w;
	goto WHL1990;
WHX1991:
	local[41]= NIL;
BLK1992:
	w = NIL;
	local[39]= w;
	goto IF1988;
IF1987:
	local[39]= fqv[345];
	local[40]= local[38];
	ctx->vsp=local+41;
	w=(*ftab[2])(ctx,2,local+39,&ftab[2],fqv[15]); /*warn*/
	local[39]= w;
IF1988:
	w = local[39];
	goto WHL1983;
WHX1984:
	local[38]= NIL;
BLK1985:
	w = NIL;
	local[36]= fqv[346];
	ctx->vsp=local+37;
	w=(*ftab[2])(ctx,1,local+36,&ftab[2],fqv[15]); /*warn*/
	local[36]= fqv[347];
	ctx->vsp=local+37;
	w=(*ftab[2])(ctx,1,local+36,&ftab[2],fqv[15]); /*warn*/
	local[36]= NIL;
	local[37]= local[1];
	local[38]= fqv[198];
	ctx->vsp=local+39;
	w=(*ftab[18])(ctx,2,local+37,&ftab[18],fqv[128]); /*send-all*/
	local[37]= w;
WHL1994:
	if (local[37]==NIL) goto WHX1995;
	w=local[37];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[38]= (w)->c.cons.car;
	w=local[37];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[37] = (w)->c.cons.cdr;
	w = local[38];
	local[36] = w;
	local[38]= local[36];
	local[39]= fqv[22];
	ctx->vsp=local+40;
	w=(pointer)SEND(ctx,2,local+38); /*send*/
	local[38]= w;
	local[39]= local[38];
	ctx->vsp=local+40;
	w=(pointer)VECTORP(ctx,1,local+39); /*vectorp*/
	if (w==NIL) goto IF1998;
	local[39]= makeint((eusinteger_t)0L);
	local[40]= local[38];
	ctx->vsp=local+41;
	w=(pointer)LENGTH(ctx,1,local+40); /*length*/
	local[40]= w;
WHL2001:
	local[41]= local[39];
	w = local[40];
	if ((eusinteger_t)local[41] >= (eusinteger_t)w) goto WHX2002;
	local[41]= fqv[348];
	local[42]= local[38];
	local[43]= local[39];
	ctx->vsp=local+44;
	w=(pointer)ELT(ctx,2,local+42); /*elt*/
	local[42]= w;
	ctx->vsp=local+43;
	w=(*ftab[2])(ctx,2,local+41,&ftab[2],fqv[15]); /*warn*/
	local[41]= local[39];
	ctx->vsp=local+42;
	w=(pointer)ADD1(ctx,1,local+41); /*1+*/
	local[39] = w;
	goto WHL2001;
WHX2002:
	local[41]= NIL;
BLK2003:
	w = NIL;
	local[39]= w;
	goto IF1999;
IF1998:
	local[39]= fqv[349];
	local[40]= local[38];
	ctx->vsp=local+41;
	w=(*ftab[2])(ctx,2,local+39,&ftab[2],fqv[15]); /*warn*/
	local[39]= w;
IF1999:
	w = local[39];
	goto WHL1994;
WHX1995:
	local[38]= NIL;
BLK1996:
	w = NIL;
	local[36]= fqv[350];
	ctx->vsp=local+37;
	w=(*ftab[2])(ctx,1,local+36,&ftab[2],fqv[15]); /*warn*/
	local[36]= fqv[351];
	ctx->vsp=local+37;
	w=(*ftab[2])(ctx,1,local+36,&ftab[2],fqv[15]); /*warn*/
	local[36]= NIL;
	local[37]= local[1];
	local[38]= fqv[198];
	ctx->vsp=local+39;
	w=(*ftab[18])(ctx,2,local+37,&ftab[18],fqv[128]); /*send-all*/
	local[37]= w;
WHL2005:
	if (local[37]==NIL) goto WHX2006;
	w=local[37];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[38]= (w)->c.cons.car;
	w=local[37];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[37] = (w)->c.cons.cdr;
	w = local[38];
	local[36] = w;
	local[38]= local[36];
	local[39]= fqv[23];
	ctx->vsp=local+40;
	w=(pointer)SEND(ctx,2,local+38); /*send*/
	local[38]= w;
	local[39]= local[38];
	ctx->vsp=local+40;
	w=(pointer)VECTORP(ctx,1,local+39); /*vectorp*/
	if (w==NIL) goto IF2009;
	local[39]= makeint((eusinteger_t)0L);
	local[40]= local[38];
	ctx->vsp=local+41;
	w=(pointer)LENGTH(ctx,1,local+40); /*length*/
	local[40]= w;
WHL2012:
	local[41]= local[39];
	w = local[40];
	if ((eusinteger_t)local[41] >= (eusinteger_t)w) goto WHX2013;
	local[41]= fqv[352];
	local[42]= local[38];
	local[43]= local[39];
	ctx->vsp=local+44;
	w=(pointer)ELT(ctx,2,local+42); /*elt*/
	local[42]= w;
	ctx->vsp=local+43;
	w=(*ftab[2])(ctx,2,local+41,&ftab[2],fqv[15]); /*warn*/
	local[41]= local[39];
	ctx->vsp=local+42;
	w=(pointer)ADD1(ctx,1,local+41); /*1+*/
	local[39] = w;
	goto WHL2012;
WHX2013:
	local[41]= NIL;
BLK2014:
	w = NIL;
	local[39]= w;
	goto IF2010;
IF2009:
	local[39]= fqv[353];
	local[40]= local[38];
	ctx->vsp=local+41;
	w=(*ftab[2])(ctx,2,local+39,&ftab[2],fqv[15]); /*warn*/
	local[39]= w;
IF2010:
	w = local[39];
	goto WHL2005;
WHX2006:
	local[38]= NIL;
BLK2007:
	w = NIL;
	local[36]= fqv[354];
	ctx->vsp=local+37;
	w=(*ftab[2])(ctx,1,local+36,&ftab[2],fqv[15]); /*warn*/
	local[36]= w;
	goto IF1981;
IF1980:
	local[36]= NIL;
IF1981:
	local[36]= argv[0];
	local[37]= fqv[355];
	local[38]= local[2];
	local[39]= fqv[274];
	local[40]= local[4];
	local[41]= fqv[356];
	local[42]= local[3];
	local[43]= fqv[357];
	local[44]= local[7];
	local[45]= fqv[358];
	local[46]= local[1];
	local[47]= fqv[341];
	local[48]= local[25];
	local[49]= fqv[284];
	local[50]= local[19];
	local[51]= fqv[359];
	local[52]= local[21];
	local[53]= fqv[360];
	local[54]= local[17];
	ctx->vsp=local+55;
	w=(pointer)SEND(ctx,19,local+36); /*send*/
	local[4] = w;
	local[36]= (pointer)get_sym_func(fqv[289]);
	local[37]= argv[0];
	local[38]= fqv[361];
	local[39]= local[26];
	local[40]= fqv[274];
	local[41]= local[4];
	local[42]= local[0];
	ctx->vsp=local+43;
	w=(pointer)APPLY(ctx,7,local+36); /*apply*/
	local[34] = w;
	local[36]= local[23]->c.obj.iv[1];
	local[37]= makeint((eusinteger_t)0L);
	ctx->vsp=local+38;
	w=(*ftab[36])(ctx,2,local+36,&ftab[36],fqv[243]); /*fill*/
	local[36]= makeint((eusinteger_t)0L);
	local[37]= local[3];
WHL2016:
	local[38]= local[36];
	w = local[37];
	if ((eusinteger_t)local[38] >= (eusinteger_t)w) goto WHX2017;
	local[38]= local[23];
	local[39]= local[36];
	local[40]= local[36];
	local[41]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+42;
	w=(pointer)ASET(ctx,4,local+38); /*aset*/
	local[38]= local[36];
	ctx->vsp=local+39;
	w=(pointer)ADD1(ctx,1,local+38); /*1+*/
	local[36] = w;
	goto WHL2016;
WHX2017:
	local[38]= NIL;
BLK2018:
	w = NIL;
	local[36]= local[23];
	local[37]= local[34];
	local[38]= local[26];
	local[39]= local[24];
	ctx->vsp=local+40;
	w=(pointer)MATTIMES(ctx,3,local+37); /*m**/
	local[37]= w;
	local[38]= local[23];
	ctx->vsp=local+39;
	w=(*ftab[44])(ctx,3,local+36,&ftab[44],fqv[362]); /*m-*/
	local[35] = w;
	local[36]= argv[0];
	local[37]= fqv[150];
	local[38]= fqv[303];
	local[39]= NIL;
	ctx->vsp=local+40;
	w=(pointer)SEND(ctx,4,local+36); /*send*/
	local[36]= argv[0];
	local[37]= fqv[150];
	local[38]= fqv[304];
	local[39]= NIL;
	ctx->vsp=local+40;
	w=(pointer)SEND(ctx,4,local+36); /*send*/
	if (local[11]==NIL) goto IF2019;
	local[36]= local[8];
	local[37]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+38;
	w=(pointer)GREATERP(ctx,2,local+36); /*>*/
	if (w==NIL) goto IF2019;
	local[36]= local[10];
	local[37]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+38;
	w=(pointer)GREATERP(ctx,2,local+36); /*>*/
	if (w!=NIL) goto OR2021;
	local[36]= local[9];
	local[37]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+38;
	w=(pointer)GREATERP(ctx,2,local+36); /*>*/
	if (w!=NIL) goto OR2021;
	goto IF2019;
OR2021:
	local[36]= (pointer)get_sym_func(fqv[289]);
	local[37]= argv[0];
	local[38]= fqv[363];
	local[39]= fqv[364];
	local[40]= local[8];
	local[41]= fqv[365];
	local[42]= local[9];
	local[43]= fqv[366];
	local[44]= local[10];
	local[45]= fqv[274];
	local[46]= local[4];
	local[47]= fqv[367];
	local[48]= local[11];
	local[49]= local[0];
	ctx->vsp=local+50;
	w=(pointer)APPLY(ctx,14,local+36); /*apply*/
	local[31] = w;
	local[36]= argv[0];
	local[37]= fqv[184];
	local[38]= fqv[253];
	ctx->vsp=local+39;
	w=(pointer)SEND(ctx,3,local+36); /*send*/
	local[36]= w;
	local[37]= makeint((eusinteger_t)0L);
	ctx->vsp=local+38;
	w=(pointer)ELT(ctx,2,local+36); /*elt*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[33] = (w)->c.cons.car;
	local[36]= local[10];
	local[37]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+38;
	w=(pointer)LSEQP(ctx,2,local+36); /*<=*/
	if (w==NIL) goto CON2023;
	local[36]= makeflt(0.0000000000000000000000e+00);
	goto CON2022;
CON2023:
	local[36]= local[33];
	local[37]= makeflt(9.9999999999999977795540e-02);
	local[38]= local[8];
	ctx->vsp=local+39;
	w=(pointer)TIMES(ctx,2,local+37); /***/
	local[37]= w;
	ctx->vsp=local+38;
	w=(pointer)LESSP(ctx,2,local+36); /*<*/
	if (w==NIL) goto CON2024;
	local[36]= makeflt(1.0000000000000000000000e+00);
	goto CON2022;
CON2024:
	local[36]= local[33];
	local[37]= local[8];
	ctx->vsp=local+38;
	w=(pointer)LESSP(ctx,2,local+36); /*<*/
	if (w==NIL) goto CON2025;
	local[36]= local[8];
	local[37]= local[33];
	ctx->vsp=local+38;
	w=(pointer)MINUS(ctx,2,local+36); /*-*/
	local[36]= w;
	local[37]= makeflt(8.9999999999999991118216e-01);
	local[38]= local[8];
	ctx->vsp=local+39;
	w=(pointer)TIMES(ctx,2,local+37); /***/
	local[37]= w;
	ctx->vsp=local+38;
	w=(pointer)QUOTIENT(ctx,2,local+36); /*/*/
	local[36]= w;
	goto CON2022;
CON2025:
	local[36]= makeflt(0.0000000000000000000000e+00);
	goto CON2022;
CON2026:
	local[36]= NIL;
CON2022:
	local[32] = local[36];
	if (local[25]==NIL) goto IF2027;
	local[36]= fqv[202];
	w = local[25];
	if (memq(local[36],w)!=NIL) goto IF2027;
	local[36]= loadglobal(fqv[5]);
	local[37]= (pointer)get_sym_func(fqv[49]);
	local[38]= local[31];
	ctx->vsp=local+39;
	w=(pointer)MAP(ctx,3,local+36); /*map*/
	local[36]= w;
	local[37]= fqv[368];
	ctx->vsp=local+38;
	w=(*ftab[33])(ctx,2,local+36,&ftab[33],fqv[234]); /*format-array*/
	local[36]= fqv[369];
	local[37]= local[32];
	ctx->vsp=local+38;
	w=(*ftab[2])(ctx,2,local+36,&ftab[2],fqv[15]); /*warn*/
	local[36]= w;
	goto IF2028;
IF2027:
	local[36]= NIL;
IF2028:
	goto IF2020;
IF2019:
	local[36]= NIL;
IF2020:
	local[36]= argv[0];
	local[37]= fqv[370];
	local[38]= local[2];
	local[39]= fqv[358];
	local[40]= local[1];
	local[41]= fqv[371];
	local[42]= local[6];
	local[43]= fqv[341];
	local[44]= local[25];
	local[45]= fqv[335];
	local[46]= local[12];
	local[47]= fqv[334];
	local[48]= local[13];
	local[49]= fqv[332];
	local[50]= local[14];
	local[51]= fqv[372];
	local[52]= local[16];
	local[53]= fqv[333];
	local[54]= NIL;
	local[55]= fqv[373];
	local[56]= local[15];
	local[57]= fqv[274];
	local[58]= local[4];
	local[59]= fqv[356];
	local[60]= local[3];
	local[61]= fqv[374];
	local[62]= local[5];
	local[63]= fqv[375];
	local[64]= local[22];
	local[65]= fqv[376];
	local[66]= local[18];
	ctx->vsp=local+67;
	w=(pointer)SEND(ctx,31,local+36); /*send*/
	local[22] = w;
	local[36]= argv[0];
	local[37]= fqv[184];
	local[38]= fqv[303];
	ctx->vsp=local+39;
	w=(pointer)SEND(ctx,3,local+36); /*send*/
	if (w==NIL) goto IF2029;
	local[36]= local[22];
	local[37]= argv[0];
	local[38]= fqv[184];
	local[39]= fqv[303];
	ctx->vsp=local+40;
	w=(pointer)SEND(ctx,3,local+37); /*send*/
	local[37]= w;
	local[38]= local[22];
	ctx->vsp=local+39;
	w=(pointer)VPLUS(ctx,3,local+36); /*v+*/
	local[36]= w;
	goto IF2030;
IF2029:
	local[36]= NIL;
IF2030:
	local[36]= (pointer)get_sym_func(fqv[34]);
	local[37]= argv[0];
	local[38]= loadglobal(fqv[377]);
	local[39]= fqv[378];
	local[40]= argv[2];
	local[41]= fqv[358];
	local[42]= local[1];
	local[43]= fqv[374];
	local[44]= local[22];
	local[45]= fqv[379];
	local[46]= local[31];
	local[47]= fqv[380];
	local[48]= local[32];
	local[49]= fqv[274];
	local[50]= local[4];
	local[51]= fqv[381];
	local[52]= local[34];
	local[53]= fqv[382];
	local[54]= local[35];
	local[55]= local[0];
	ctx->vsp=local+56;
	w=(pointer)APPLY(ctx,20,local+36); /*apply*/
	w = T;
	local[0]= w;
BLK1948:
	ctx->vsp=local; return(local[0]);}

/*:inverse-kinematics-args*/
static pointer M2031cascaded_link_inverse_kinematics_args(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST2033:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[383], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY2034;
	local[1] = NIL;
KEY2034:
	if (n & (1<<1)) goto KEY2035;
	local[2] = NIL;
KEY2035:
	if (n & (1<<2)) goto KEY2036;
	local[3] = NIL;
KEY2036:
	if (n & (1<<3)) goto KEY2037;
	local[4] = NIL;
KEY2037:
	local[5]= argv[0];
	local[6]= fqv[211];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	local[6]= argv[0];
	local[7]= fqv[210];
	local[8]= local[2];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[6]= w;
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	local[7]= local[6];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(*ftab[23])(ctx,2,local+7,&ftab[23],fqv[166]); /*make-matrix*/
	local[7]= w;
	local[8]= local[5];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(*ftab[23])(ctx,2,local+8,&ftab[23],fqv[166]); /*make-matrix*/
	local[8]= w;
	local[9]= local[5];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(*ftab[23])(ctx,2,local+9,&ftab[23],fqv[166]); /*make-matrix*/
	local[9]= w;
	local[10]= local[5];
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(*ftab[23])(ctx,2,local+10,&ftab[23],fqv[166]); /*make-matrix*/
	local[10]= w;
	local[11]= local[6];
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(*ftab[23])(ctx,2,local+11,&ftab[23],fqv[166]); /*make-matrix*/
	local[11]= w;
	local[12]= local[6];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(*ftab[23])(ctx,2,local+12,&ftab[23],fqv[166]); /*make-matrix*/
	local[12]= w;
	local[13]= local[5];
	local[14]= local[6];
	ctx->vsp=local+15;
	w=(*ftab[23])(ctx,2,local+13,&ftab[23],fqv[166]); /*make-matrix*/
	local[13]= w;
	local[14]= local[5];
	local[15]= local[5];
	ctx->vsp=local+16;
	w=(*ftab[23])(ctx,2,local+14,&ftab[23],fqv[166]); /*make-matrix*/
	local[14]= w;
	local[15]= local[5];
	local[16]= local[5];
	ctx->vsp=local+17;
	w=(*ftab[23])(ctx,2,local+15,&ftab[23],fqv[166]); /*make-matrix*/
	local[15]= w;
	local[16]= local[6];
	local[17]= local[6];
	ctx->vsp=local+18;
	w=(*ftab[23])(ctx,2,local+16,&ftab[23],fqv[166]); /*make-matrix*/
	local[16]= w;
	local[17]= local[6];
	local[18]= local[5];
	ctx->vsp=local+19;
	w=(*ftab[23])(ctx,2,local+17,&ftab[23],fqv[166]); /*make-matrix*/
	local[17]= w;
	local[18]= loadglobal(fqv[5]);
	local[19]= makeint((eusinteger_t)0L);
	ctx->vsp=local+20;
	w=(pointer)INSTANTIATE(ctx,2,local+18); /*instantiate*/
	local[18]= w;
	local[19]= loadglobal(fqv[5]);
	local[20]= makeint((eusinteger_t)1L);
	ctx->vsp=local+21;
	w=(pointer)INSTANTIATE(ctx,2,local+19); /*instantiate*/
	local[19]= w;
	local[20]= loadglobal(fqv[5]);
	local[21]= makeint((eusinteger_t)2L);
	ctx->vsp=local+22;
	w=(pointer)INSTANTIATE(ctx,2,local+20); /*instantiate*/
	local[20]= w;
	local[21]= loadglobal(fqv[5]);
	local[22]= makeint((eusinteger_t)3L);
	ctx->vsp=local+23;
	w=(pointer)INSTANTIATE(ctx,2,local+21); /*instantiate*/
	local[21]= w;
	local[22]= loadglobal(fqv[5]);
	local[23]= makeint((eusinteger_t)3L);
	ctx->vsp=local+24;
	w=(pointer)INSTANTIATE(ctx,2,local+22); /*instantiate*/
	local[22]= w;
	local[23]= loadglobal(fqv[5]);
	local[24]= makeint((eusinteger_t)3L);
	ctx->vsp=local+25;
	w=(pointer)INSTANTIATE(ctx,2,local+23); /*instantiate*/
	local[23]= w;
	local[24]= loadglobal(fqv[5]);
	local[25]= makeint((eusinteger_t)3L);
	ctx->vsp=local+26;
	w=(pointer)INSTANTIATE(ctx,2,local+24); /*instantiate*/
	local[24]= w;
	local[25]= makeint((eusinteger_t)3L);
	local[26]= makeint((eusinteger_t)3L);
	ctx->vsp=local+27;
	w=(*ftab[23])(ctx,2,local+25,&ftab[23],fqv[166]); /*make-matrix*/
	local[25]= w;
	local[26]= loadglobal(fqv[5]);
	local[27]= local[6];
	ctx->vsp=local+28;
	w=(pointer)INSTANTIATE(ctx,2,local+26); /*instantiate*/
	local[26]= w;
	local[27]= NIL;
	local[28]= loadglobal(fqv[5]);
	local[29]= local[5];
	ctx->vsp=local+30;
	w=(pointer)INSTANTIATE(ctx,2,local+28); /*instantiate*/
	local[28]= w;
	local[29]= loadglobal(fqv[5]);
	local[30]= local[5];
	ctx->vsp=local+31;
	w=(pointer)INSTANTIATE(ctx,2,local+29); /*instantiate*/
	local[29]= w;
	local[30]= loadglobal(fqv[5]);
	local[31]= makeint((eusinteger_t)3L);
	ctx->vsp=local+32;
	w=(pointer)INSTANTIATE(ctx,2,local+30); /*instantiate*/
	local[30]= w;
	local[31]= loadglobal(fqv[5]);
	local[32]= makeint((eusinteger_t)3L);
	ctx->vsp=local+33;
	w=(pointer)INSTANTIATE(ctx,2,local+31); /*instantiate*/
	local[31]= w;
	local[32]= makeint((eusinteger_t)0L);
	local[33]= local[2];
	ctx->vsp=local+34;
	w=(pointer)LENGTH(ctx,1,local+33); /*length*/
	local[33]= w;
WHL2039:
	local[34]= local[32];
	w = local[33];
	if ((eusinteger_t)local[34] >= (eusinteger_t)w) goto WHX2040;
	local[34]= loadglobal(fqv[5]);
	local[35]= argv[0];
	local[36]= fqv[210];
	local[37]= local[2];
	local[38]= local[32];
	ctx->vsp=local+39;
	w=(pointer)ELT(ctx,2,local+37); /*elt*/
	local[37]= w;
	local[38]= local[3];
	local[39]= local[32];
	ctx->vsp=local+40;
	w=(pointer)ELT(ctx,2,local+38); /*elt*/
	local[38]= w;
	ctx->vsp=local+39;
	w=(pointer)SEND(ctx,4,local+35); /*send*/
	local[35]= w;
	ctx->vsp=local+36;
	w=(pointer)INSTANTIATE(ctx,2,local+34); /*instantiate*/
	local[34]= w;
	w = local[27];
	ctx->vsp=local+35;
	local[27] = cons(ctx,local[34],w);
	local[34]= local[32];
	ctx->vsp=local+35;
	w=(pointer)ADD1(ctx,1,local+34); /*1+*/
	local[32] = w;
	goto WHL2039;
WHX2040:
	local[34]= NIL;
BLK2041:
	w = NIL;
	local[32]= local[27];
	ctx->vsp=local+33;
	w=(pointer)NREVERSE(ctx,1,local+32); /*nreverse*/
	local[32]= fqv[384];
	local[33]= local[6];
	local[34]= fqv[356];
	local[35]= local[5];
	local[36]= fqv[273];
	local[37]= local[7];
	local[38]= fqv[262];
	local[39]= local[8];
	local[40]= fqv[263];
	local[41]= local[9];
	local[42]= fqv[264];
	local[43]= local[10];
	local[44]= fqv[265];
	local[45]= local[11];
	local[46]= fqv[266];
	local[47]= local[12];
	local[48]= fqv[267];
	local[49]= local[13];
	local[50]= fqv[268];
	local[51]= local[14];
	local[52]= fqv[269];
	local[53]= local[15];
	local[54]= fqv[271];
	local[55]= local[16];
	local[56]= fqv[270];
	local[57]= local[17];
	local[58]= fqv[275];
	local[59]= local[18];
	local[60]= fqv[276];
	local[61]= local[19];
	local[62]= fqv[277];
	local[63]= local[20];
	local[64]= fqv[278];
	local[65]= local[21];
	local[66]= fqv[279];
	local[67]= local[22];
	local[68]= fqv[280];
	local[69]= local[23];
	local[70]= fqv[281];
	local[71]= local[24];
	local[72]= fqv[282];
	local[73]= local[25];
	local[74]= fqv[283];
	local[75]= local[26];
	local[76]= fqv[385];
	local[77]= local[27];
	local[78]= fqv[284];
	local[79]= local[28];
	local[80]= fqv[285];
	local[81]= local[29];
	local[82]= fqv[286];
	local[83]= local[30];
	local[84]= fqv[287];
	local[85]= local[31];
	ctx->vsp=local+86;
	w=(pointer)LIST(ctx,54,local+32); /*list*/
	local[0]= w;
BLK2032:
	ctx->vsp=local; return(local[0]);}

/*:draw-collision-debug-view*/
static pointer M2042cascaded_link_draw_collision_debug_view(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[184];
	local[2]= fqv[291];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (w==NIL) goto IF2044;
	local[0]= loadglobal(fqv[386]);
	local[1]= fqv[387];
	local[2]= fqv[388];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= loadglobal(fqv[386]);
	local[2]= fqv[387];
	local[3]= fqv[389];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= loadglobal(fqv[386]);
	local[3]= fqv[387];
	local[4]= fqv[189];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[184];
	local[5]= fqv[291];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[184];
	local[6]= fqv[253];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= NIL;
	local[6]= loadglobal(fqv[386]);
	local[7]= fqv[387];
	local[8]= fqv[189];
	local[9]= fqv[390];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[6]= loadglobal(fqv[386]);
	local[7]= fqv[387];
	local[8]= fqv[388];
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[6]= loadglobal(fqv[386]);
	local[7]= fqv[387];
	local[8]= fqv[389];
	local[9]= makeint((eusinteger_t)3L);
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[6]= makeint((eusinteger_t)0L);
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
WHL2047:
	local[8]= local[6];
	w = local[7];
	if ((eusinteger_t)local[8] >= (eusinteger_t)w) goto WHX2048;
	local[8]= argv[0];
	local[9]= fqv[184];
	local[10]= fqv[253];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[5] = w;
	if (local[5]!=NIL) goto IF2050;
	local[8]= fqv[391];
	local[9]= local[3];
	local[10]= fqv[3];
	ctx->vsp=local+11;
	w=(*ftab[18])(ctx,2,local+9,&ftab[18],fqv[128]); /*send-all*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[2])(ctx,2,local+8,&ftab[2],fqv[15]); /*warn*/
	w = NIL;
	ctx->vsp=local+8;
	local[8]=w;
	goto BLK2049;
	goto IF2051;
IF2050:
	local[8]= NIL;
IF2051:
	local[8]= loadglobal(fqv[386]);
	local[9]= fqv[387];
	local[10]= fqv[189];
	local[11]= fqv[392];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= loadglobal(fqv[386]);
	local[9]= fqv[387];
	local[10]= fqv[388];
	local[11]= makeint((eusinteger_t)1L);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= loadglobal(fqv[386]);
	local[9]= fqv[387];
	local[10]= fqv[389];
	local[11]= makeint((eusinteger_t)2L);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= loadglobal(fqv[386]);
	local[9]= fqv[387];
	local[10]= fqv[393];
	local[11]= local[5];
	local[12]= makeint((eusinteger_t)1L);
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	local[12]= fqv[394];
	local[13]= T;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,6,local+8); /*send*/
	local[8]= loadglobal(fqv[386]);
	local[9]= fqv[387];
	local[10]= fqv[393];
	local[11]= local[5];
	local[12]= makeint((eusinteger_t)2L);
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	local[12]= fqv[394];
	local[13]= T;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,6,local+8); /*send*/
	local[8]= loadglobal(fqv[386]);
	local[9]= fqv[387];
	local[10]= fqv[395];
	local[11]= local[5];
	local[12]= makeint((eusinteger_t)1L);
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	local[12]= local[5];
	local[13]= makeint((eusinteger_t)2L);
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[12]= w;
	local[13]= fqv[394];
	local[14]= T;
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,7,local+8); /*send*/
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= makeint((eusinteger_t)200L);
	ctx->vsp=local+10;
	w=(pointer)LESSP(ctx,2,local+8); /*<*/
	if (w==NIL) goto IF2052;
	local[8]= loadglobal(fqv[386]);
	local[9]= fqv[387];
	local[10]= fqv[388];
	local[11]= makeint((eusinteger_t)4L);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= loadglobal(fqv[386]);
	local[9]= fqv[387];
	local[10]= fqv[389];
	local[11]= makeint((eusinteger_t)6L);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= w;
	goto IF2053;
IF2052:
	local[8]= loadglobal(fqv[386]);
	local[9]= fqv[387];
	local[10]= fqv[388];
	local[11]= makeint((eusinteger_t)2L);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= loadglobal(fqv[386]);
	local[9]= fqv[387];
	local[10]= fqv[389];
	local[11]= makeint((eusinteger_t)3L);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= w;
IF2053:
	local[8]= loadglobal(fqv[386]);
	local[9]= fqv[387];
	local[10]= fqv[189];
	local[11]= local[4];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+14;
	w=(*ftab[8])(ctx,3,local+11,&ftab[8],fqv[81]); /*eps=*/
	if (w==NIL) goto IF2054;
	local[11]= fqv[396];
	goto IF2055;
IF2054:
	local[11]= fqv[397];
IF2055:
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= loadglobal(fqv[386]);
	local[9]= fqv[387];
	local[10]= fqv[395];
	local[11]= local[5];
	local[12]= makeint((eusinteger_t)1L);
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	local[12]= local[5];
	local[13]= makeint((eusinteger_t)2L);
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[12]= w;
	local[13]= fqv[394];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,7,local+8); /*send*/
	local[8]= loadglobal(fqv[386]);
	local[9]= fqv[387];
	local[10]= fqv[393];
	local[11]= local[5];
	local[12]= makeint((eusinteger_t)1L);
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	local[12]= fqv[394];
	local[13]= NIL;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,6,local+8); /*send*/
	local[8]= loadglobal(fqv[386]);
	local[9]= fqv[387];
	local[10]= fqv[393];
	local[11]= local[5];
	local[12]= makeint((eusinteger_t)2L);
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	local[12]= fqv[394];
	local[13]= NIL;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,6,local+8); /*send*/
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+10;
	w=(pointer)LSEQP(ctx,2,local+8); /*<=*/
	if (w==NIL) goto IF2056;
	local[8]= NIL;
	local[9]= local[3];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(*ftab[38])(ctx,1,local+10,&ftab[38],fqv[292]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
WHL2059:
	if (local[9]==NIL) goto WHX2060;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= local[8];
	local[11]= loadglobal(fqv[214]);
	ctx->vsp=local+12;
	w=(pointer)DERIVEDP(ctx,2,local+10); /*derivedp*/
	if (w==NIL) goto IF2063;
	local[10]= local[8];
	local[11]= fqv[149];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	if (fqv[120]!=local[10]) goto IF2063;
	local[10]= *(ovafptr(local[8],fqv[398]));
	local[11]= fqv[122];
	ctx->vsp=local+12;
	w=(*ftab[18])(ctx,2,local+10,&ftab[18],fqv[128]); /*send-all*/
	local[10]= w;
	goto IF2064;
IF2063:
	local[10]= NIL;
IF2064:
	local[10]= NIL;
	local[11]= local[8];
	local[12]= fqv[399];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.cdr;
WHL2066:
	if (local[11]==NIL) goto WHX2067;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[12];
	local[10] = w;
	local[12]= loadglobal(fqv[386]);
	local[13]= fqv[387];
	local[14]= fqv[395];
	local[15]= *(ovafptr(local[10],fqv[400]));
	local[16]= *(ovafptr(local[10],fqv[401]));
	local[17]= fqv[394];
	local[18]= T;
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,7,local+12); /*send*/
	goto WHL2066;
WHX2067:
	local[12]= NIL;
BLK2068:
	w = NIL;
	goto WHL2059;
WHX2060:
	local[10]= NIL;
BLK2061:
	w = NIL;
	local[8]= w;
	goto IF2057;
IF2056:
	local[8]= NIL;
IF2057:
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[6] = w;
	goto WHL2047;
WHX2048:
	local[8]= NIL;
BLK2049:
	w = NIL;
	local[6]= loadglobal(fqv[386]);
	local[7]= fqv[387];
	local[8]= fqv[388];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[6]= loadglobal(fqv[386]);
	local[7]= fqv[387];
	local[8]= fqv[389];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[6]= loadglobal(fqv[386]);
	local[7]= fqv[387];
	local[8]= fqv[189];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[0]= w;
	goto IF2045;
IF2044:
	local[0]= NIL;
IF2045:
	w = local[0];
	local[0]= w;
BLK2043:
	ctx->vsp=local; return(local[0]);}

/*:inverse-kinematics-loop*/
static pointer M2070cascaded_link_inverse_kinematics_loop(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
RST2072:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-4);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[402], &argv[4], n-4, local+1, 1);
	if (n & (1<<0)) goto KEY2073;
	local[1] = makeint((eusinteger_t)1L);
KEY2073:
	if (n & (1<<1)) goto KEY2074;
	local[2] = makeint((eusinteger_t)0L);
KEY2074:
	if (n & (1<<2)) goto KEY2075;
	local[3] = NIL;
KEY2075:
	if (n & (1<<3)) goto KEY2076;
	local[4] = NIL;
KEY2076:
	if (n & (1<<4)) goto KEY2077;
	w = local[4];
	if (!!iscons(w)) goto CON2079;
	local[26]= T;
	goto CON2078;
CON2079:
	local[26]= local[4];
	ctx->vsp=local+27;
	w=(pointer)LENGTH(ctx,1,local+26); /*length*/
	local[26]= w;
	local[27]= fqv[209];
	local[28]= T;
	ctx->vsp=local+29;
	w=(*ftab[31])(ctx,3,local+26,&ftab[31],fqv[208]); /*make-list*/
	local[26]= w;
	goto CON2078;
CON2080:
	local[26]= NIL;
CON2078:
	local[5] = local[26];
KEY2077:
	if (n & (1<<5)) goto KEY2081;
	w = local[4];
	if (!!iscons(w)) goto CON2083;
	local[26]= T;
	goto CON2082;
CON2083:
	local[26]= local[4];
	ctx->vsp=local+27;
	w=(pointer)LENGTH(ctx,1,local+26); /*length*/
	local[26]= w;
	local[27]= fqv[209];
	local[28]= T;
	ctx->vsp=local+29;
	w=(*ftab[31])(ctx,3,local+26,&ftab[31],fqv[208]); /*make-list*/
	local[26]= w;
	goto CON2082;
CON2084:
	local[26]= NIL;
CON2082:
	local[6] = local[26];
KEY2081:
	if (n & (1<<6)) goto KEY2085;
	w = local[4];
	if (!!iscons(w)) goto CON2087;
	local[26]= makeint((eusinteger_t)1L);
	goto CON2086;
CON2087:
	local[26]= local[4];
	ctx->vsp=local+27;
	w=(pointer)LENGTH(ctx,1,local+26); /*length*/
	local[26]= w;
	local[27]= fqv[209];
	local[28]= makeint((eusinteger_t)1L);
	ctx->vsp=local+29;
	w=(*ftab[31])(ctx,3,local+26,&ftab[31],fqv[208]); /*make-list*/
	local[26]= w;
	goto CON2086;
CON2088:
	local[26]= NIL;
CON2086:
	local[7] = local[26];
KEY2085:
	if (n & (1<<7)) goto KEY2089;
	w = local[4];
	if (!!iscons(w)) goto CON2091;
	local[26]= makeint((eusinteger_t)1L);
	ctx->vsp=local+27;
	w=(*ftab[6])(ctx,1,local+26,&ftab[6],fqv[48]); /*deg2rad*/
	local[26]= w;
	goto CON2090;
CON2091:
	local[26]= local[4];
	ctx->vsp=local+27;
	w=(pointer)LENGTH(ctx,1,local+26); /*length*/
	local[26]= w;
	local[27]= fqv[209];
	local[28]= makeint((eusinteger_t)1L);
	ctx->vsp=local+29;
	w=(*ftab[6])(ctx,1,local+28,&ftab[6],fqv[48]); /*deg2rad*/
	local[28]= w;
	ctx->vsp=local+29;
	w=(*ftab[31])(ctx,3,local+26,&ftab[31],fqv[208]); /*make-list*/
	local[26]= w;
	goto CON2090;
CON2092:
	local[26]= NIL;
CON2090:
	local[8] = local[26];
KEY2089:
	if (n & (1<<8)) goto KEY2093;
	local[9] = makeflt(1.0000000000000000000000e+00);
KEY2093:
	if (n & (1<<9)) goto KEY2094;
	local[10] = makeflt(1.0000000000000000000000e+00);
KEY2094:
	if (n & (1<<10)) goto KEY2095;
	local[11] = NIL;
KEY2095:
	if (n & (1<<11)) goto KEY2096;
	local[12] = NIL;
KEY2096:
	if (n & (1<<12)) goto KEY2097;
	local[13] = NIL;
KEY2097:
	if (n & (1<<13)) goto KEY2098;
	local[14] = NIL;
KEY2098:
	if (n & (1<<14)) goto KEY2099;
	local[15] = NIL;
KEY2099:
	if (n & (1<<15)) goto KEY2100;
	local[16] = NIL;
KEY2100:
	if (n & (1<<16)) goto KEY2101;
	local[17] = makeflt(1.0000000000000000000000e+00);
KEY2101:
	if (n & (1<<17)) goto KEY2102;
	local[18] = NIL;
KEY2102:
	if (n & (1<<18)) goto KEY2103;
	local[19] = NIL;
KEY2103:
	if (n & (1<<19)) goto KEY2104;
	local[20] = fqv[33];
KEY2104:
	if (n & (1<<20)) goto KEY2105;
	local[21] = NIL;
KEY2105:
	if (n & (1<<21)) goto KEY2106;
	local[22] = makeflt(1.0000000000000000000000e+00);
KEY2106:
	if (n & (1<<22)) goto KEY2107;
	local[26]= local[1];
	local[27]= makeint((eusinteger_t)10L);
	ctx->vsp=local+28;
	w=(pointer)QUOTIENT(ctx,2,local+26); /*/*/
	local[23] = w;
KEY2107:
	if (n & (1<<23)) goto KEY2108;
	local[24] = NIL;
KEY2108:
	if (n & (1<<24)) goto KEY2109;
	local[25] = NIL;
KEY2109:
	if (local[18]==NIL) goto IF2110;
	local[26]= argv[0];
	local[27]= fqv[333];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,2,local+26); /*send*/
	local[26]= w;
	goto IF2111;
IF2110:
	local[26]= NIL;
IF2111:
	local[26]= NIL;
	local[27]= NIL;
	local[28]= makeint((eusinteger_t)0L);
	local[29]= T;
	local[30]= local[0];
	local[31]= local[25];
	ctx->vsp=local+32;
	w=(pointer)NCONC(ctx,2,local+30); /*nconc*/
	local[30]= w;
	local[31]= fqv[403];
	w = local[0];
	w=memq(local[31],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[31]= (w)->c.cons.car;
	local[32]= fqv[404];
	w = local[0];
	w=memq(local[32],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[32]= (w)->c.cons.car;
	if (local[11]!=NIL) goto IF2112;
	local[33]= argv[0];
	local[34]= fqv[197];
	local[35]= local[3];
	ctx->vsp=local+36;
	w=(pointer)SEND(ctx,3,local+33); /*send*/
	local[11] = w;
	local[33]= local[11];
	ctx->vsp=local+34;
	w=(pointer)LENGTH(ctx,1,local+33); /*length*/
	local[33]= w;
	local[34]= local[3];
	ctx->vsp=local+35;
	w=(pointer)LENGTH(ctx,1,local+34); /*length*/
	local[34]= w;
	ctx->vsp=local+35;
	w=(*ftab[24])(ctx,2,local+33,&ftab[24],fqv[171]); /*/=*/
	if (w==NIL) goto IF2114;
	local[33]= argv[0];
	local[34]= fqv[405];
	local[35]= local[11];
	ctx->vsp=local+36;
	w=(pointer)SEND(ctx,3,local+33); /*send*/
	local[33]= w;
	goto IF2115;
IF2114:
	local[33]= NIL;
IF2115:
	goto IF2113;
IF2112:
	local[33]= NIL;
IF2113:
	if (local[24]==NIL) goto IF2116;
	w = local[24];
	if (!!iscons(w)) goto IF2116;
	local[33]= local[24];
	ctx->vsp=local+34;
	w=(pointer)LIST(ctx,1,local+33); /*list*/
	local[24] = w;
	local[33]= local[24];
	goto IF2117;
IF2116:
	local[33]= NIL;
IF2117:
	if (local[24]==NIL) goto IF2118;
	local[33]= local[24];
	local[34]= fqv[406];
	ctx->vsp=local+35;
	w=(pointer)EQUAL(ctx,2,local+33); /*equal*/
	if (w!=NIL) goto IF2118;
	if (loadglobal(fqv[386])==NIL) goto IF2118;
	local[33]= loadglobal(fqv[386]);
	local[34]= fqv[387];
	local[35]= fqv[407];
	ctx->vsp=local+36;
	w=(pointer)SEND(ctx,3,local+33); /*send*/
	local[33]= w;
	goto IF2119;
IF2118:
	local[33]= NIL;
IF2119:
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!!iscons(w)) goto IF2120;
	local[33]= local[3];
	ctx->vsp=local+34;
	w=(pointer)LIST(ctx,1,local+33); /*list*/
	local[3] = w;
	local[33]= local[3];
	goto IF2121;
IF2120:
	local[33]= NIL;
IF2121:
	w = local[4];
	if (!!iscons(w)) goto IF2122;
	local[33]= local[4];
	ctx->vsp=local+34;
	w=(pointer)LIST(ctx,1,local+33); /*list*/
	local[4] = w;
	local[33]= local[4];
	goto IF2123;
IF2122:
	local[33]= NIL;
IF2123:
	w = local[12];
	if (!iscons(w)) goto OR2126;
	local[33]= local[12];
	ctx->vsp=local+34;
	w=(*ftab[43])(ctx,1,local+33,&ftab[43],fqv[321]); /*functionp*/
	if (w!=NIL) goto OR2126;
	goto IF2124;
OR2126:
	local[33]= local[12];
	ctx->vsp=local+34;
	w=(pointer)LIST(ctx,1,local+33); /*list*/
	local[12] = w;
	local[33]= local[12];
	goto IF2125;
IF2124:
	local[33]= NIL;
IF2125:
	w = argv[2];
	if (!!iscons(w)) goto IF2127;
	local[33]= argv[2];
	ctx->vsp=local+34;
	w=(pointer)LIST(ctx,1,local+33); /*list*/
	argv[2] = w;
	local[33]= argv[2];
	goto IF2128;
IF2127:
	local[33]= NIL;
IF2128:
	w = argv[3];
	if (!!iscons(w)) goto IF2129;
	local[33]= argv[3];
	ctx->vsp=local+34;
	w=(pointer)LIST(ctx,1,local+33); /*list*/
	argv[3] = w;
	local[33]= argv[3];
	goto IF2130;
IF2129:
	local[33]= NIL;
IF2130:
	w = local[5];
	if (!!iscons(w)) goto IF2131;
	local[33]= local[5];
	ctx->vsp=local+34;
	w=(pointer)LIST(ctx,1,local+33); /*list*/
	local[5] = w;
	local[33]= local[5];
	goto IF2132;
IF2131:
	local[33]= NIL;
IF2132:
	w = local[6];
	if (!!iscons(w)) goto IF2133;
	local[33]= local[6];
	ctx->vsp=local+34;
	w=(pointer)LIST(ctx,1,local+33); /*list*/
	local[6] = w;
	local[33]= local[6];
	goto IF2134;
IF2133:
	local[33]= NIL;
IF2134:
	w = local[7];
	if (!!iscons(w)) goto IF2135;
	local[33]= local[7];
	ctx->vsp=local+34;
	w=(pointer)LIST(ctx,1,local+33); /*list*/
	local[7] = w;
	local[33]= local[7];
	goto IF2136;
IF2135:
	local[33]= NIL;
IF2136:
	w = local[8];
	if (!!iscons(w)) goto IF2137;
	local[33]= local[8];
	ctx->vsp=local+34;
	w=(pointer)LIST(ctx,1,local+33); /*list*/
	local[8] = w;
	local[33]= local[8];
	goto IF2138;
IF2137:
	local[33]= NIL;
IF2138:
	local[33]= local[6];
	ctx->vsp=local+34;
	w=(pointer)LENGTH(ctx,1,local+33); /*length*/
	local[33]= w;
	local[34]= local[5];
	ctx->vsp=local+35;
	w=(pointer)LENGTH(ctx,1,local+34); /*length*/
	local[34]= w;
	local[35]= local[4];
	ctx->vsp=local+36;
	w=(pointer)LENGTH(ctx,1,local+35); /*length*/
	local[35]= w;
	local[36]= local[3];
	ctx->vsp=local+37;
	w=(pointer)LENGTH(ctx,1,local+36); /*length*/
	local[36]= w;
	local[37]= argv[2];
	ctx->vsp=local+38;
	w=(pointer)LENGTH(ctx,1,local+37); /*length*/
	local[37]= w;
	local[38]= argv[3];
	ctx->vsp=local+39;
	w=(pointer)LENGTH(ctx,1,local+38); /*length*/
	local[38]= w;
	ctx->vsp=local+39;
	w=(pointer)NUMEQUAL(ctx,6,local+33); /*=*/
	if (w!=NIL) goto IF2139;
	local[33]= fqv[408];
	local[34]= local[6];
	ctx->vsp=local+35;
	w=(pointer)LENGTH(ctx,1,local+34); /*length*/
	local[34]= w;
	local[35]= local[5];
	ctx->vsp=local+36;
	w=(pointer)LENGTH(ctx,1,local+35); /*length*/
	local[35]= w;
	local[36]= local[4];
	ctx->vsp=local+37;
	w=(pointer)LENGTH(ctx,1,local+36); /*length*/
	local[36]= w;
	local[37]= local[3];
	ctx->vsp=local+38;
	w=(pointer)LENGTH(ctx,1,local+37); /*length*/
	local[37]= w;
	local[38]= argv[2];
	ctx->vsp=local+39;
	w=(pointer)LENGTH(ctx,1,local+38); /*length*/
	local[38]= w;
	local[39]= argv[3];
	ctx->vsp=local+40;
	w=(pointer)LENGTH(ctx,1,local+39); /*length*/
	local[39]= w;
	ctx->vsp=local+40;
	w=(*ftab[2])(ctx,7,local+33,&ftab[2],fqv[15]); /*warn*/
	w = fqv[409];
	ctx->vsp=local+33;
	local[0]=w;
	goto BLK2071;
	goto IF2140;
IF2139:
	local[33]= NIL;
IF2140:
	local[33]= fqv[385];
	w = local[25];
	if (memq(local[33],w)==NIL) goto IF2141;
	local[33]= fqv[385];
	w = local[25];
	w=memq(local[33],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[27] = (w)->c.cons.car;
	local[33]= local[27];
	goto IF2142;
IF2141:
	local[33]= makeint((eusinteger_t)0L);
	local[34]= local[5];
	ctx->vsp=local+35;
	w=(pointer)LENGTH(ctx,1,local+34); /*length*/
	local[34]= w;
WHL2144:
	local[35]= local[33];
	w = local[34];
	if ((eusinteger_t)local[35] >= (eusinteger_t)w) goto WHX2145;
	local[35]= loadglobal(fqv[5]);
	local[36]= argv[0];
	local[37]= fqv[210];
	local[38]= local[5];
	local[39]= local[33];
	ctx->vsp=local+40;
	w=(pointer)ELT(ctx,2,local+38); /*elt*/
	local[38]= w;
	local[39]= local[6];
	local[40]= local[33];
	ctx->vsp=local+41;
	w=(pointer)ELT(ctx,2,local+39); /*elt*/
	local[39]= w;
	ctx->vsp=local+40;
	w=(pointer)SEND(ctx,4,local+36); /*send*/
	local[36]= w;
	ctx->vsp=local+37;
	w=(pointer)INSTANTIATE(ctx,2,local+35); /*instantiate*/
	local[35]= w;
	w = local[27];
	ctx->vsp=local+36;
	local[27] = cons(ctx,local[35],w);
	local[35]= local[33];
	ctx->vsp=local+36;
	w=(pointer)ADD1(ctx,1,local+35); /*1+*/
	local[33] = w;
	goto WHL2144;
WHX2145:
	local[35]= NIL;
BLK2146:
	w = NIL;
	local[33]= local[27];
	ctx->vsp=local+34;
	w=(pointer)NREVERSE(ctx,1,local+33); /*nreverse*/
	local[27] = w;
	local[33]= local[27];
IF2142:
	local[33]= fqv[283];
	w = local[25];
	if (memq(local[33],w)==NIL) goto IF2147;
	local[33]= fqv[283];
	w = local[25];
	w=memq(local[33],w);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26] = (w)->c.cons.car;
	local[33]= local[26];
	goto IF2148;
IF2147:
	local[33]= loadglobal(fqv[5]);
	local[34]= argv[0];
	local[35]= fqv[210];
	local[36]= local[5];
	local[37]= local[6];
	ctx->vsp=local+38;
	w=(pointer)SEND(ctx,4,local+34); /*send*/
	local[34]= w;
	ctx->vsp=local+35;
	w=(pointer)INSTANTIATE(ctx,2,local+33); /*instantiate*/
	local[26] = w;
	local[33]= local[26];
IF2148:
	local[33]= local[13];
	ctx->vsp=local+34;
	w=(*ftab[43])(ctx,1,local+33,&ftab[43],fqv[321]); /*functionp*/
	if (w==NIL) goto IF2149;
	local[33]= local[13];
	local[34]= local[3];
	local[35]= local[4];
	local[36]= local[6];
	local[37]= local[5];
	ctx->vsp=local+38;
	w=(pointer)FUNCALL(ctx,5,local+33); /*funcall*/
	local[13] = w;
	local[33]= local[13];
	goto IF2150;
IF2149:
	local[33]= NIL;
IF2150:
	if (local[13]!=NIL) goto IF2151;
	local[33]= (pointer)get_sym_func(fqv[289]);
	local[34]= argv[0];
	local[35]= fqv[300];
	local[36]= local[3];
	local[37]= fqv[336];
	local[38]= local[6];
	local[39]= fqv[410];
	local[40]= local[5];
	local[41]= fqv[301];
	local[42]= local[4];
	local[43]= local[30];
	ctx->vsp=local+44;
	w=(pointer)APPLY(ctx,11,local+33); /*apply*/
	local[13] = w;
	local[33]= local[13];
	goto IF2152;
IF2151:
	local[33]= NIL;
IF2152:
	if (local[24]==NIL) goto IF2153;
	local[33]= fqv[202];
	w = local[24];
	if (memq(local[33],w)!=NIL) goto IF2153;
	local[33]= fqv[411];
	local[34]= local[2];
	ctx->vsp=local+35;
	w=(*ftab[2])(ctx,2,local+33,&ftab[2],fqv[15]); /*warn*/
	local[33]= fqv[412];
	local[34]= local[11];
	local[35]= fqv[3];
	ctx->vsp=local+36;
	w=(*ftab[18])(ctx,2,local+34,&ftab[18],fqv[128]); /*send-all*/
	local[34]= w;
	ctx->vsp=local+35;
	w=(*ftab[2])(ctx,2,local+33,&ftab[2],fqv[15]); /*warn*/
	local[33]= fqv[413];
	local[34]= local[4];
	ctx->vsp=local+35;
	w=(*ftab[2])(ctx,2,local+33,&ftab[2],fqv[15]); /*warn*/
	local[33]= fqv[414];
	local[34]= local[12];
	ctx->vsp=local+35;
	w=(*ftab[2])(ctx,2,local+33,&ftab[2],fqv[15]); /*warn*/
	local[33]= w;
	goto IF2154;
IF2153:
	local[33]= NIL;
IF2154:
	local[33]= argv[0];
	local[34]= fqv[415];
	if (local[23]==NIL) goto IF2155;
	local[35]= local[2];
	local[36]= local[23];
	ctx->vsp=local+37;
	w=(pointer)GREQP(ctx,2,local+35); /*>=*/
	local[35]= w;
	goto IF2156;
IF2155:
	local[35]= T;
IF2156:
	local[36]= argv[2];
	local[37]= argv[3];
	local[38]= local[5];
	local[39]= local[6];
	local[40]= local[7];
	local[41]= local[8];
	local[42]= local[17];
	local[43]= local[18];
	local[44]= local[19];
	local[45]= local[20];
	local[46]= fqv[333];
	local[47]= NIL;
	ctx->vsp=local+48;
	w=(pointer)SEND(ctx,15,local+33); /*send*/
	local[29] = w;
	if (local[14]==NIL) goto IF2157;
	local[33]= local[29];
	if (local[33]==NIL) goto AND2159;
	local[33]= local[14];
	ctx->vsp=local+34;
	w=(pointer)FUNCALL(ctx,1,local+33); /*funcall*/
	local[33]= w;
AND2159:
	local[29] = local[33];
	local[33]= local[29];
	goto IF2158;
IF2157:
	local[33]= NIL;
IF2158:
	local[33]= makeint((eusinteger_t)0L);
	local[34]= local[4];
	ctx->vsp=local+35;
	w=(pointer)LENGTH(ctx,1,local+34); /*length*/
	local[34]= w;
WHL2161:
	local[35]= local[33];
	w = local[34];
	if ((eusinteger_t)local[35] >= (eusinteger_t)w) goto WHX2162;
	local[35]= local[27];
	local[36]= local[33];
	ctx->vsp=local+37;
	w=(pointer)ELT(ctx,2,local+35); /*elt*/
	local[35]= w;
	local[36]= (pointer)get_sym_func(fqv[289]);
	local[37]= argv[0];
	local[38]= fqv[416];
	local[39]= argv[2];
	local[40]= local[33];
	ctx->vsp=local+41;
	w=(pointer)ELT(ctx,2,local+39); /*elt*/
	local[39]= w;
	local[40]= local[6];
	local[41]= local[33];
	ctx->vsp=local+42;
	w=(pointer)ELT(ctx,2,local+40); /*elt*/
	local[40]= w;
	if (local[31]==NIL) goto IF2164;
	local[41]= fqv[403];
	local[42]= local[31];
	ctx->vsp=local+43;
	w=(pointer)LIST(ctx,2,local+41); /*list*/
	local[41]= w;
	goto IF2165;
IF2164:
	local[41]= NIL;
IF2165:
	ctx->vsp=local+42;
	w=(pointer)APPLY(ctx,6,local+36); /*apply*/
	local[36]= w;
	local[37]= (pointer)get_sym_func(fqv[289]);
	local[38]= argv[0];
	local[39]= fqv[417];
	local[40]= argv[3];
	local[41]= local[33];
	ctx->vsp=local+42;
	w=(pointer)ELT(ctx,2,local+40); /*elt*/
	local[40]= w;
	local[41]= local[5];
	local[42]= local[33];
	ctx->vsp=local+43;
	w=(pointer)ELT(ctx,2,local+41); /*elt*/
	local[41]= w;
	if (local[32]==NIL) goto IF2166;
	local[42]= fqv[404];
	local[43]= local[32];
	ctx->vsp=local+44;
	w=(pointer)LIST(ctx,2,local+42); /*list*/
	local[42]= w;
	goto IF2167;
IF2166:
	local[42]= NIL;
IF2167:
	ctx->vsp=local+43;
	w=(pointer)APPLY(ctx,6,local+37); /*apply*/
	local[37]= w;
	if (local[24]==NIL) goto IF2168;
	local[38]= fqv[202];
	w = local[24];
	if (memq(local[38],w)!=NIL) goto IF2168;
	local[38]= makeflt(1.0000000000000000000000e+03);
	local[39]= local[36];
	ctx->vsp=local+40;
	w=(pointer)SCALEVEC(ctx,2,local+38); /*scale*/
	local[38]= w;
	local[39]= fqv[418];
	ctx->vsp=local+40;
	w=(*ftab[33])(ctx,2,local+38,&ftab[33],fqv[234]); /*format-array*/
	local[38]= local[37];
	local[39]= fqv[419];
	ctx->vsp=local+40;
	w=(*ftab[33])(ctx,2,local+38,&ftab[33],fqv[234]); /*format-array*/
	local[38]= fqv[420];
	local[39]= makeflt(1.0000000000000000000000e+03);
	local[40]= local[36];
	ctx->vsp=local+41;
	w=(pointer)VNORM(ctx,1,local+40); /*norm*/
	{ double x,y;
		y=fltval(w); x=fltval(local[39]);
		local[39]=(makeflt(x * y));}
	local[40]= local[7];
	local[41]= local[33];
	ctx->vsp=local+42;
	w=(pointer)ELT(ctx,2,local+40); /*elt*/
	local[40]= w;
	local[41]= local[37];
	ctx->vsp=local+42;
	w=(pointer)VNORM(ctx,1,local+41); /*norm*/
	local[41]= w;
	local[42]= local[8];
	local[43]= local[33];
	ctx->vsp=local+44;
	w=(pointer)ELT(ctx,2,local+42); /*elt*/
	local[42]= w;
	ctx->vsp=local+43;
	w=(*ftab[2])(ctx,5,local+38,&ftab[2],fqv[15]); /*warn*/
	local[38]= w;
	goto IF2169;
IF2168:
	local[38]= NIL;
IF2169:
	local[38]= makeint((eusinteger_t)0L);
	local[39]= local[36];
	ctx->vsp=local+40;
	w=(pointer)LENGTH(ctx,1,local+39); /*length*/
	local[39]= w;
WHL2171:
	local[40]= local[38];
	w = local[39];
	if ((eusinteger_t)local[40] >= (eusinteger_t)w) goto WHX2172;
	local[40]= local[35];
	local[41]= local[38];
	local[42]= local[9];
	local[43]= local[36];
	local[44]= local[38];
	ctx->vsp=local+45;
	w=(pointer)ELT(ctx,2,local+43); /*elt*/
	local[43]= w;
	ctx->vsp=local+44;
	w=(pointer)TIMES(ctx,2,local+42); /***/
	local[42]= w;
	ctx->vsp=local+43;
	w=(pointer)SETELT(ctx,3,local+40); /*setelt*/
	local[40]= local[38];
	ctx->vsp=local+41;
	w=(pointer)ADD1(ctx,1,local+40); /*1+*/
	local[38] = w;
	goto WHL2171;
WHX2172:
	local[40]= NIL;
BLK2173:
	w = NIL;
	local[38]= makeint((eusinteger_t)0L);
	local[39]= local[37];
	ctx->vsp=local+40;
	w=(pointer)LENGTH(ctx,1,local+39); /*length*/
	local[39]= w;
WHL2175:
	local[40]= local[38];
	w = local[39];
	if ((eusinteger_t)local[40] >= (eusinteger_t)w) goto WHX2176;
	local[40]= local[35];
	local[41]= local[38];
	local[42]= local[36];
	ctx->vsp=local+43;
	w=(pointer)LENGTH(ctx,1,local+42); /*length*/
#if sun4 || vax || mips || alpha || Linux
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[41]= (pointer)((eusinteger_t)local[41] + (eusinteger_t)w);
	local[42]= local[10];
	local[43]= local[37];
	local[44]= local[38];
	ctx->vsp=local+45;
	w=(pointer)ELT(ctx,2,local+43); /*elt*/
	local[43]= w;
	ctx->vsp=local+44;
	w=(pointer)TIMES(ctx,2,local+42); /***/
	local[42]= w;
	ctx->vsp=local+43;
	w=(pointer)SETELT(ctx,3,local+40); /*setelt*/
	local[40]= local[38];
	ctx->vsp=local+41;
	w=(pointer)ADD1(ctx,1,local+40); /*1+*/
	local[38] = w;
	goto WHL2175;
WHX2176:
	local[40]= NIL;
BLK2177:
	w = NIL;
	local[38]= argv[0];
	local[39]= fqv[184];
	local[40]= fqv[421];
	ctx->vsp=local+41;
	w=(pointer)SEND(ctx,3,local+38); /*send*/
	if (w==NIL) goto IF2178;
	local[38]= NIL;
	local[39]= fqv[422];
	local[40]= local[33];
	ctx->vsp=local+41;
	w=(pointer)XFORMAT(ctx,3,local+38); /*format*/
	local[38]= w;
	ctx->vsp=local+39;
	w=(*ftab[45])(ctx,1,local+38,&ftab[45],fqv[423]); /*read-from-string*/
	local[38]= w;
	local[39]= argv[0];
	local[40]= fqv[184];
	local[41]= fqv[421];
	ctx->vsp=local+42;
	w=(pointer)SEND(ctx,3,local+39); /*send*/
	local[39]= w;
	ctx->vsp=local+40;
	w=(*ftab[41])(ctx,2,local+38,&ftab[41],fqv[315]); /*assoc*/
	local[38]= w;
	local[39]= local[36];
	local[40]= local[37];
	ctx->vsp=local+41;
	w=(pointer)LIST(ctx,2,local+39); /*list*/
	local[39]= w;
	local[40]= NIL;
	local[41]= fqv[424];
	local[42]= local[33];
	ctx->vsp=local+43;
	w=(pointer)XFORMAT(ctx,3,local+40); /*format*/
	local[40]= w;
	ctx->vsp=local+41;
	w=(*ftab[45])(ctx,1,local+40,&ftab[45],fqv[423]); /*read-from-string*/
	local[40]= w;
	local[41]= argv[0];
	local[42]= fqv[184];
	local[43]= fqv[421];
	ctx->vsp=local+44;
	w=(pointer)SEND(ctx,3,local+41); /*send*/
	local[41]= w;
	ctx->vsp=local+42;
	w=(*ftab[41])(ctx,2,local+40,&ftab[41],fqv[315]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+40;
	local[39]= cons(ctx,local[39],w);
	ctx->vsp=local+40;
	w=(pointer)RPLACD2(ctx,2,local+38); /*rplacd2*/
	local[38]= w;
	goto IF2179;
IF2178:
	local[38]= NIL;
IF2179:
	w = local[38];
	local[35]= local[33];
	ctx->vsp=local+36;
	w=(pointer)ADD1(ctx,1,local+35); /*1+*/
	local[33] = w;
	goto WHL2161;
WHX2162:
	local[35]= NIL;
BLK2163:
	w = NIL;
	local[33]= makeint((eusinteger_t)0L);
	local[34]= local[27];
	ctx->vsp=local+35;
	w=(pointer)LENGTH(ctx,1,local+34); /*length*/
	local[34]= w;
WHL2181:
	local[35]= local[33];
	w = local[34];
	if ((eusinteger_t)local[35] >= (eusinteger_t)w) goto WHX2182;
	local[35]= makeint((eusinteger_t)0L);
	local[36]= local[27];
	local[37]= local[33];
	ctx->vsp=local+38;
	w=(pointer)ELT(ctx,2,local+36); /*elt*/
	local[36]= w;
	ctx->vsp=local+37;
	w=(pointer)LENGTH(ctx,1,local+36); /*length*/
	local[36]= w;
WHL2185:
	local[37]= local[35];
	w = local[36];
	if ((eusinteger_t)local[37] >= (eusinteger_t)w) goto WHX2186;
	local[37]= local[26];
	local[38]= local[35];
	local[39]= local[28];
	ctx->vsp=local+40;
	w=(pointer)PLUS(ctx,2,local+38); /*+*/
	local[38]= w;
	local[39]= local[27];
	local[40]= local[33];
	ctx->vsp=local+41;
	w=(pointer)ELT(ctx,2,local+39); /*elt*/
	local[39]= w;
	local[40]= local[35];
	ctx->vsp=local+41;
	w=(pointer)ELT(ctx,2,local+39); /*elt*/
	local[39]= w;
	ctx->vsp=local+40;
	w=(pointer)SETELT(ctx,3,local+37); /*setelt*/
	local[37]= local[35];
	ctx->vsp=local+38;
	w=(pointer)ADD1(ctx,1,local+37); /*1+*/
	local[35] = w;
	goto WHL2185;
WHX2186:
	local[37]= NIL;
BLK2187:
	w = NIL;
	local[35]= local[28];
	local[36]= local[27];
	local[37]= local[33];
	ctx->vsp=local+38;
	w=(pointer)ELT(ctx,2,local+36); /*elt*/
	local[36]= w;
	ctx->vsp=local+37;
	w=(pointer)LENGTH(ctx,1,local+36); /*length*/
	local[36]= w;
	ctx->vsp=local+37;
	w=(pointer)PLUS(ctx,2,local+35); /*+*/
	local[28] = w;
	local[35]= local[33];
	ctx->vsp=local+36;
	w=(pointer)ADD1(ctx,1,local+35); /*1+*/
	local[33] = w;
	goto WHL2181;
WHX2182:
	local[35]= NIL;
BLK2183:
	w = NIL;
	if (local[21]!=NIL) goto IF2188;
	if (local[18]==NIL) goto IF2188;
	local[33]= argv[0];
	local[34]= fqv[425];
	local[35]= fqv[333];
	local[36]= NIL;
	local[37]= fqv[261];
	local[38]= local[11];
	local[39]= fqv[336];
	local[40]= local[20];
	ctx->vsp=local+41;
	w=(pointer)SEND(ctx,8,local+33); /*send*/
	local[33]= w;
	ctx->vsp=local+34;
	w=(pointer)LIST(ctx,1,local+33); /*list*/
	local[33]= w;
	local[34]= local[15];
	ctx->vsp=local+35;
	w=(pointer)APPEND(ctx,2,local+33); /*append*/
	local[15] = w;
	local[33]= local[22];
	local[34]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+35;
	w=(pointer)GREATERP(ctx,2,local+33); /*>*/
	if (w==NIL) goto IF2190;
	local[33]= makeflt(1.0000000000000000000000e+00);
	goto IF2191;
IF2190:
	local[33]= local[22];
IF2191:
	local[34]= argv[0];
	local[35]= fqv[426];
	local[36]= local[33];
	local[37]= local[20];
	local[38]= local[18];
	local[39]= fqv[332];
	local[40]= local[19];
	local[41]= fqv[333];
	local[42]= NIL;
	ctx->vsp=local+43;
	w=(pointer)SEND(ctx,9,local+34); /*send*/
	local[34]= w;
	ctx->vsp=local+35;
	w=(pointer)LIST(ctx,1,local+34); /*list*/
	local[34]= w;
	local[35]= local[16];
	ctx->vsp=local+36;
	w=(pointer)APPEND(ctx,2,local+34); /*append*/
	local[16] = w;
	local[34]= argv[0];
	local[35]= fqv[184];
	local[36]= fqv[421];
	ctx->vsp=local+37;
	w=(pointer)SEND(ctx,3,local+34); /*send*/
	if (w==NIL) goto IF2192;
	local[34]= fqv[258];
	local[35]= argv[0];
	local[36]= fqv[184];
	local[37]= fqv[421];
	ctx->vsp=local+38;
	w=(pointer)SEND(ctx,3,local+35); /*send*/
	local[35]= w;
	ctx->vsp=local+36;
	w=(*ftab[41])(ctx,2,local+34,&ftab[41],fqv[315]); /*assoc*/
	local[34]= w;
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[35]= (w)->c.cons.car;
	local[36]= fqv[258];
	local[37]= argv[0];
	local[38]= fqv[184];
	local[39]= fqv[421];
	ctx->vsp=local+40;
	w=(pointer)SEND(ctx,3,local+37); /*send*/
	local[37]= w;
	ctx->vsp=local+38;
	w=(*ftab[41])(ctx,2,local+36,&ftab[41],fqv[315]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+36;
	local[35]= cons(ctx,local[35],w);
	ctx->vsp=local+36;
	w=(pointer)RPLACD2(ctx,2,local+34); /*rplacd2*/
	local[34]= w;
	goto IF2193;
IF2192:
	local[34]= NIL;
IF2193:
	w = local[34];
	local[33]= w;
	goto IF2189;
IF2188:
	local[33]= NIL;
IF2189:
	local[33]= NIL;
	local[34]= NIL;
	local[35]= NIL;
	local[36]= NIL;
	if (local[15]==NIL) goto IF2194;
	ctx->vsp=local+37;
	local[37]= makeclosure(codevec,quotevec,CLO2196,env,argv,local);
	local[38]= local[16];
	ctx->vsp=local+39;
	w=(pointer)MAPCAR(ctx,2,local+37); /*mapcar*/
	local[33] = w;
	local[37]= local[26];
	ctx->vsp=local+38;
	w=(pointer)LENGTH(ctx,1,local+37); /*length*/
	local[37]= w;
	local[38]= (pointer)get_sym_func(fqv[323]);
	local[39]= (pointer)get_sym_func(fqv[427]);
	local[40]= local[33];
	ctx->vsp=local+41;
	w=(pointer)MAPCAR(ctx,2,local+39); /*mapcar*/
	local[39]= w;
	ctx->vsp=local+40;
	w=(*ftab[26])(ctx,2,local+38,&ftab[26],fqv[196]); /*reduce*/
	local[38]= w;
	ctx->vsp=local+39;
	w=(pointer)MINUS(ctx,2,local+37); /*-*/
	local[34] = w;
	local[37]= makeint((eusinteger_t)0L);
	local[38]= local[15];
	ctx->vsp=local+39;
	w=(pointer)LENGTH(ctx,1,local+38); /*length*/
	local[38]= w;
WHL2198:
	local[39]= local[37];
	w = local[38];
	if ((eusinteger_t)local[39] >= (eusinteger_t)w) goto WHX2199;
	local[39]= local[15];
	local[40]= local[37];
	ctx->vsp=local+41;
	w=(pointer)ELT(ctx,2,local+39); /*elt*/
	local[36] = w;
	local[39]= local[36];
	ctx->vsp=local+40;
	w=(*ftab[43])(ctx,1,local+39,&ftab[43],fqv[321]); /*functionp*/
	if (w==NIL) goto IF2201;
	local[39]= local[36];
	local[40]= local[3];
	ctx->vsp=local+41;
	w=(pointer)FUNCALL(ctx,2,local+39); /*funcall*/
	local[39]= w;
	goto IF2202;
IF2201:
	local[39]= local[36];
IF2202:
	local[36] = local[39];
	local[39]= local[33];
	local[40]= local[37];
	ctx->vsp=local+41;
	w=(pointer)ELT(ctx,2,local+39); /*elt*/
	local[35] = w;
	local[39]= makeint((eusinteger_t)0L);
	local[40]= local[36];
	local[41]= makeint((eusinteger_t)0L);
	ctx->vsp=local+42;
	w=(*ftab[3])(ctx,2,local+40,&ftab[3],fqv[24]); /*array-dimension*/
	local[40]= w;
WHL2204:
	local[41]= local[39];
	w = local[40];
	if ((eusinteger_t)local[41] >= (eusinteger_t)w) goto WHX2205;
	local[41]= makeint((eusinteger_t)0L);
	local[42]= local[13];
	local[43]= makeint((eusinteger_t)1L);
	ctx->vsp=local+44;
	w=(*ftab[3])(ctx,2,local+42,&ftab[3],fqv[24]); /*array-dimension*/
	local[42]= w;
WHL2208:
	local[43]= local[41];
	w = local[42];
	if ((eusinteger_t)local[43] >= (eusinteger_t)w) goto WHX2209;
	local[43]= local[13];
	local[44]= local[34];
	local[45]= local[39];
	ctx->vsp=local+46;
	w=(pointer)PLUS(ctx,2,local+44); /*+*/
	local[44]= w;
	local[45]= local[41];
	local[46]= local[36];
	local[47]= local[39];
	local[48]= local[41];
	ctx->vsp=local+49;
	w=(pointer)AREF(ctx,3,local+46); /*aref*/
	local[46]= w;
	ctx->vsp=local+47;
	w=(pointer)ASET(ctx,4,local+43); /*aset*/
	local[43]= local[41];
	ctx->vsp=local+44;
	w=(pointer)ADD1(ctx,1,local+43); /*1+*/
	local[41] = w;
	goto WHL2208;
WHX2209:
	local[43]= NIL;
BLK2210:
	w = NIL;
	local[41]= local[26];
	local[42]= local[34];
	local[43]= local[39];
	ctx->vsp=local+44;
	w=(pointer)PLUS(ctx,2,local+42); /*+*/
	local[42]= w;
	local[43]= local[35];
	local[44]= local[39];
	ctx->vsp=local+45;
	w=(pointer)ELT(ctx,2,local+43); /*elt*/
	local[43]= w;
	ctx->vsp=local+44;
	w=(pointer)SETELT(ctx,3,local+41); /*setelt*/
	local[41]= local[39];
	ctx->vsp=local+42;
	w=(pointer)ADD1(ctx,1,local+41); /*1+*/
	local[39] = w;
	goto WHL2204;
WHX2205:
	local[41]= NIL;
BLK2206:
	w = NIL;
	local[39]= local[34];
	local[40]= local[35];
	ctx->vsp=local+41;
	w=(pointer)LENGTH(ctx,1,local+40); /*length*/
	local[40]= w;
	ctx->vsp=local+41;
	w=(pointer)PLUS(ctx,2,local+39); /*+*/
	local[34] = w;
	if (local[24]==NIL) goto IF2211;
	local[39]= fqv[202];
	w = local[24];
	if (memq(local[39],w)!=NIL) goto IF2211;
	local[39]= local[36];
	local[40]= NIL;
	local[41]= fqv[428];
	local[42]= local[37];
	ctx->vsp=local+43;
	w=(pointer)XFORMAT(ctx,3,local+40); /*format*/
	local[40]= w;
	ctx->vsp=local+41;
	w=(*ftab[33])(ctx,2,local+39,&ftab[33],fqv[234]); /*format-array*/
	local[39]= local[35];
	local[40]= NIL;
	local[41]= fqv[429];
	local[42]= local[37];
	ctx->vsp=local+43;
	w=(pointer)XFORMAT(ctx,3,local+40); /*format*/
	local[40]= w;
	ctx->vsp=local+41;
	w=(*ftab[33])(ctx,2,local+39,&ftab[33],fqv[234]); /*format-array*/
	local[39]= w;
	goto IF2212;
IF2211:
	local[39]= NIL;
IF2212:
	local[39]= argv[0];
	local[40]= fqv[184];
	local[41]= fqv[421];
	ctx->vsp=local+42;
	w=(pointer)SEND(ctx,3,local+39); /*send*/
	if (w==NIL) goto IF2213;
	if (local[21]!=NIL) goto IF2215;
	if (local[18]==NIL) goto IF2215;
	local[39]= local[37];
	local[40]= makeint((eusinteger_t)0L);
	ctx->vsp=local+41;
	w=(*ftab[24])(ctx,2,local+39,&ftab[24],fqv[171]); /*/=*/
	if (w==NIL) goto IF2215;
	local[39]= NIL;
	local[40]= fqv[430];
	local[41]= local[37];
	w = makeint((eusinteger_t)1L);
#if sun4 || vax || mips || alpha || Linux
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[41]= (pointer)((eusinteger_t)local[41] - (eusinteger_t)w);
	ctx->vsp=local+42;
	w=(pointer)XFORMAT(ctx,3,local+39); /*format*/
	local[39]= w;
	ctx->vsp=local+40;
	w=(*ftab[45])(ctx,1,local+39,&ftab[45],fqv[423]); /*read-from-string*/
	local[39]= w;
	local[40]= argv[0];
	local[41]= fqv[184];
	local[42]= fqv[421];
	ctx->vsp=local+43;
	w=(pointer)SEND(ctx,3,local+40); /*send*/
	local[40]= w;
	ctx->vsp=local+41;
	w=(*ftab[41])(ctx,2,local+39,&ftab[41],fqv[315]); /*assoc*/
	local[39]= w;
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[40]= (w)->c.cons.car;
	local[41]= NIL;
	local[42]= fqv[431];
	local[43]= local[37];
	w = makeint((eusinteger_t)1L);
#if sun4 || vax || mips || alpha || Linux
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[43]= (pointer)((eusinteger_t)local[43] - (eusinteger_t)w);
	ctx->vsp=local+44;
	w=(pointer)XFORMAT(ctx,3,local+41); /*format*/
	local[41]= w;
	ctx->vsp=local+42;
	w=(*ftab[45])(ctx,1,local+41,&ftab[45],fqv[423]); /*read-from-string*/
	local[41]= w;
	local[42]= argv[0];
	local[43]= fqv[184];
	local[44]= fqv[421];
	ctx->vsp=local+45;
	w=(pointer)SEND(ctx,3,local+42); /*send*/
	local[42]= w;
	ctx->vsp=local+43;
	w=(*ftab[41])(ctx,2,local+41,&ftab[41],fqv[315]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+41;
	local[40]= cons(ctx,local[40],w);
	ctx->vsp=local+41;
	w=(pointer)RPLACD2(ctx,2,local+39); /*rplacd2*/
	local[39]= w;
	goto IF2216;
IF2215:
	local[39]= NIL;
IF2216:
	goto IF2214;
IF2213:
	local[39]= NIL;
IF2214:
	local[39]= local[37];
	ctx->vsp=local+40;
	w=(pointer)ADD1(ctx,1,local+39); /*1+*/
	local[37] = w;
	goto WHL2198;
WHX2199:
	local[39]= NIL;
BLK2200:
	w = NIL;
	local[37]= w;
	goto IF2195;
IF2194:
	local[37]= NIL;
IF2195:
	w = local[37];
	if (local[29]==NIL) goto IF2217;
	local[33]= argv[0];
	local[34]= fqv[150];
	local[35]= fqv[432];
	local[36]= NIL;
	ctx->vsp=local+37;
	w=(pointer)SEND(ctx,4,local+33); /*send*/
	local[33]= fqv[433];
	goto IF2218;
IF2217:
	if (local[24]==NIL) goto IF2219;
	local[33]= fqv[406];
	w = local[24];
	if (memq(local[33],w)!=NIL) goto IF2219;
	if (loadglobal(fqv[386])==NIL) goto IF2219;
	local[33]= loadglobal(fqv[386]);
	local[34]= fqv[387];
	local[35]= fqv[407];
	ctx->vsp=local+36;
	w=(pointer)SEND(ctx,3,local+33); /*send*/
	local[33]= w;
	goto IF2220;
IF2219:
	local[33]= NIL;
IF2220:
	local[33]= argv[0];
	local[34]= fqv[150];
	local[35]= fqv[291];
	local[36]= NIL;
	ctx->vsp=local+37;
	w=(pointer)SEND(ctx,4,local+33); /*send*/
	local[33]= (pointer)get_sym_func(fqv[34]);
	local[34]= argv[0];
	local[35]= loadglobal(fqv[377]);
	local[36]= fqv[434];
	local[37]= local[26];
	local[38]= fqv[358];
	local[39]= local[11];
	local[40]= fqv[410];
	local[41]= local[5];
	local[42]= fqv[336];
	local[43]= local[6];
	local[44]= fqv[435];
	local[45]= local[13];
	local[46]= fqv[341];
	local[47]= local[24];
	local[48]= local[30];
	ctx->vsp=local+49;
	w=(pointer)APPLY(ctx,16,local+33); /*apply*/
	if (local[24]==NIL) goto IF2221;
	if (loadglobal(fqv[386])==NIL) goto IF2221;
	local[33]= loadglobal(fqv[386]);
	local[34]= fqv[436];
	local[35]= fqv[407];
	local[36]= NIL;
	local[37]= fqv[190];
	local[38]= NIL;
	ctx->vsp=local+39;
	w=(pointer)SEND(ctx,6,local+33); /*send*/
	local[33]= argv[0];
	local[34]= fqv[437];
	ctx->vsp=local+35;
	w=(pointer)SEND(ctx,2,local+33); /*send*/
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto IF2223;
	local[33]= makeint((eusinteger_t)0L);
	local[34]= local[12];
	ctx->vsp=local+35;
	w=(pointer)LENGTH(ctx,1,local+34); /*length*/
	local[34]= w;
WHL2226:
	local[35]= local[33];
	w = local[34];
	if ((eusinteger_t)local[35] >= (eusinteger_t)w) goto WHX2227;
	local[35]= local[4];
	local[36]= local[33];
	ctx->vsp=local+37;
	w=(pointer)ELT(ctx,2,local+35); /*elt*/
	local[35]= w;
	local[36]= loadglobal(fqv[438]);
	local[37]= fqv[439];
	local[38]= fqv[190];
	local[39]= NIL;
	local[40]= fqv[440];
	local[41]= makeint((eusinteger_t)100L);
	ctx->vsp=local+42;
	w=(pointer)SENDMESSAGE(ctx,7,local+35); /*send-message*/
	local[35]= local[12];
	local[36]= local[33];
	ctx->vsp=local+37;
	w=(pointer)ELT(ctx,2,local+35); /*elt*/
	local[35]= w;
	local[36]= fqv[439];
	local[37]= fqv[190];
	local[38]= NIL;
	local[39]= fqv[189];
	local[40]= fqv[441];
	ctx->vsp=local+41;
	w=(pointer)SEND(ctx,6,local+35); /*send*/
	local[35]= local[33];
	ctx->vsp=local+36;
	w=(pointer)ADD1(ctx,1,local+35); /*1+*/
	local[33] = w;
	goto WHL2226;
WHX2227:
	local[35]= NIL;
BLK2228:
	w = NIL;
	local[33]= w;
	goto IF2224;
IF2223:
	local[33]= NIL;
IF2224:
	local[33]= NIL;
	local[34]= argv[0];
	local[35]= fqv[184];
	local[36]= fqv[432];
	ctx->vsp=local+37;
	w=(pointer)SEND(ctx,3,local+34); /*send*/
	local[34]= w;
WHL2230:
	if (local[34]==NIL) goto WHX2231;
	w=local[34];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[35]= (w)->c.cons.car;
	w=local[34];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[34] = (w)->c.cons.cdr;
	w = local[35];
	local[33] = w;
	local[35]= (pointer)get_sym_func(fqv[289]);
	w=local[33];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[36]= (w)->c.cons.car;
	local[37]= fqv[439];
	local[38]= fqv[190];
	local[39]= NIL;
	w=local[33];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[40]= (w)->c.cons.cdr;
	ctx->vsp=local+41;
	w=(pointer)APPLY(ctx,6,local+35); /*apply*/
	goto WHL2230;
WHX2231:
	local[35]= NIL;
BLK2232:
	w = NIL;
	local[33]= fqv[442];
	w = local[24];
	if (memq(local[33],w)!=NIL) goto IF2234;
	local[33]= loadglobal(fqv[386]);
	local[34]= fqv[387];
	local[35]= fqv[190];
	ctx->vsp=local+36;
	w=(pointer)SEND(ctx,3,local+33); /*send*/
	local[33]= w;
	goto IF2235;
IF2234:
	local[33]= NIL;
IF2235:
	ctx->vsp=local+33;
	w=(*ftab[46])(ctx,0,local+33,&ftab[46],fqv[443]); /*x::window-main-one*/
	local[33]= w;
	goto IF2222;
IF2221:
	local[33]= NIL;
IF2222:
	local[33]= argv[0];
	local[34]= fqv[150];
	local[35]= fqv[432];
	local[36]= NIL;
	ctx->vsp=local+37;
	w=(pointer)SEND(ctx,4,local+33); /*send*/
	local[33]= fqv[409];
IF2218:
	w = local[33];
	local[0]= w;
BLK2071:
	ctx->vsp=local; return(local[0]);}

/*:inverse-kinematics*/
static pointer M2236cascaded_link_inverse_kinematics(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST2238:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[444], &argv[3], n-3, local+1, 1);
	if (n & (1<<0)) goto KEY2239;
	local[1] = makeint((eusinteger_t)50L);
KEY2239:
	if (n & (1<<1)) goto KEY2240;
	local[2] = NIL;
KEY2240:
	if (n & (1<<2)) goto KEY2241;
	local[3] = NIL;
KEY2241:
	if (n & (1<<3)) goto KEY2242;
	local[4] = NIL;
KEY2242:
	if (n & (1<<4)) goto KEY2243;
	local[5] = T;
KEY2243:
	if (n & (1<<5)) goto KEY2244;
	local[6] = T;
KEY2244:
	if (n & (1<<6)) goto KEY2245;
	w = local[3];
	if (!!iscons(w)) goto CON2247;
	local[23]= T;
	goto CON2246;
CON2247:
	local[23]= local[3];
	ctx->vsp=local+24;
	w=(pointer)LENGTH(ctx,1,local+23); /*length*/
	local[23]= w;
	local[24]= fqv[209];
	local[25]= T;
	ctx->vsp=local+26;
	w=(*ftab[31])(ctx,3,local+23,&ftab[31],fqv[208]); /*make-list*/
	local[23]= w;
	goto CON2246;
CON2248:
	local[23]= NIL;
CON2246:
	local[7] = local[23];
KEY2245:
	if (n & (1<<7)) goto KEY2249;
	w = local[3];
	if (!!iscons(w)) goto CON2251;
	local[23]= T;
	goto CON2250;
CON2251:
	local[23]= local[3];
	ctx->vsp=local+24;
	w=(pointer)LENGTH(ctx,1,local+23); /*length*/
	local[23]= w;
	local[24]= fqv[209];
	local[25]= T;
	ctx->vsp=local+26;
	w=(*ftab[31])(ctx,3,local+23,&ftab[31],fqv[208]); /*make-list*/
	local[23]= w;
	goto CON2250;
CON2252:
	local[23]= NIL;
CON2250:
	local[8] = local[23];
KEY2249:
	if (n & (1<<8)) goto KEY2253;
	local[9] = NIL;
KEY2253:
	if (n & (1<<9)) goto KEY2254;
	w = local[3];
	if (!!iscons(w)) goto CON2256;
	local[23]= makeint((eusinteger_t)1L);
	goto CON2255;
CON2256:
	local[23]= local[3];
	ctx->vsp=local+24;
	w=(pointer)LENGTH(ctx,1,local+23); /*length*/
	local[23]= w;
	local[24]= fqv[209];
	local[25]= makeint((eusinteger_t)1L);
	ctx->vsp=local+26;
	w=(*ftab[31])(ctx,3,local+23,&ftab[31],fqv[208]); /*make-list*/
	local[23]= w;
	goto CON2255;
CON2257:
	local[23]= NIL;
CON2255:
	local[10] = local[23];
KEY2254:
	if (n & (1<<10)) goto KEY2258;
	w = local[3];
	if (!!iscons(w)) goto CON2260;
	local[23]= makeint((eusinteger_t)1L);
	ctx->vsp=local+24;
	w=(*ftab[6])(ctx,1,local+23,&ftab[6],fqv[48]); /*deg2rad*/
	local[23]= w;
	goto CON2259;
CON2260:
	local[23]= local[3];
	ctx->vsp=local+24;
	w=(pointer)LENGTH(ctx,1,local+23); /*length*/
	local[23]= w;
	local[24]= fqv[209];
	local[25]= makeint((eusinteger_t)1L);
	ctx->vsp=local+26;
	w=(*ftab[6])(ctx,1,local+25,&ftab[6],fqv[48]); /*deg2rad*/
	local[25]= w;
	ctx->vsp=local+26;
	w=(*ftab[31])(ctx,3,local+23,&ftab[31],fqv[208]); /*make-list*/
	local[23]= w;
	goto CON2259;
CON2261:
	local[23]= NIL;
CON2259:
	local[11] = local[23];
KEY2258:
	if (n & (1<<11)) goto KEY2262;
	local[12] = NIL;
KEY2262:
	if (n & (1<<12)) goto KEY2263;
	local[13] = makeflt(1.0000000000000000000000e+00);
KEY2263:
	if (n & (1<<13)) goto KEY2264;
	local[14] = NIL;
KEY2264:
	if (n & (1<<14)) goto KEY2265;
	local[15] = NIL;
KEY2265:
	if (n & (1<<15)) goto KEY2266;
	local[16] = fqv[33];
KEY2266:
	if (n & (1<<16)) goto KEY2267;
	local[17] = NIL;
KEY2267:
	if (n & (1<<17)) goto KEY2268;
	local[18] = fqv[445];
KEY2268:
	if (n & (1<<18)) goto KEY2269;
	local[19] = makeflt(5.0000000000000000000000e-01);
KEY2269:
	if (n & (1<<19)) goto KEY2270;
	local[20] = NIL;
KEY2270:
	if (n & (1<<20)) goto KEY2271;
	local[21] = NIL;
KEY2271:
	if (n & (1<<21)) goto KEY2272;
	local[22] = NIL;
KEY2272:
	w = argv[2];
	if (!iscons(w)) goto OR2275;
	local[23]= argv[2];
	ctx->vsp=local+24;
	w=(*ftab[43])(ctx,1,local+23,&ftab[43],fqv[321]); /*functionp*/
	if (w!=NIL) goto OR2275;
	goto IF2273;
OR2275:
	local[23]= argv[2];
	ctx->vsp=local+24;
	w=(pointer)LIST(ctx,1,local+23); /*list*/
	argv[2] = w;
	local[23]= argv[2];
	goto IF2274;
IF2273:
	local[23]= NIL;
IF2274:
	local[23]= makeint((eusinteger_t)0L);
	local[24]= local[12];
	ctx->vsp=local+25;
	w=(*ftab[43])(ctx,1,local+24,&ftab[43],fqv[321]); /*functionp*/
	if (w==NIL) goto IF2276;
	local[24]= local[12];
	local[25]= local[2];
	ctx->vsp=local+26;
	w=(pointer)FUNCALL(ctx,2,local+24); /*funcall*/
	local[24]= w;
	goto IF2277;
IF2276:
	local[24]= argv[0];
	local[25]= fqv[197];
	local[26]= local[2];
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,3,local+24); /*send*/
	local[24]= w;
IF2277:
	local[25]= local[24];
	local[26]= fqv[198];
	ctx->vsp=local+27;
	w=(*ftab[18])(ctx,2,local+25,&ftab[18],fqv[128]); /*send-all*/
	local[25]= w;
	local[26]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+27;
	w=(pointer)APPEND(ctx,2,local+25); /*append*/
	local[25]= w;
	ctx->vsp=local+26;
	w=(*ftab[47])(ctx,1,local+25,&ftab[47],fqv[446]); /*remove-duplicates*/
	local[25]= w;
	local[26]= fqv[20];
	ctx->vsp=local+27;
	w=(*ftab[18])(ctx,2,local+25,&ftab[18],fqv[128]); /*send-all*/
	local[25]= w;
	local[26]= argv[0];
	local[27]= fqv[215];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,2,local+26); /*send*/
	if (w!=NIL) goto IF2278;
	local[26]= argv[0];
	local[27]= fqv[153];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,2,local+26); /*send*/
	local[26]= w;
	goto IF2279;
IF2278:
	local[26]= NIL;
IF2279:
	local[27]= argv[2];
	local[28]= NIL;
	local[29]= NIL;
	local[30]= T;
	local[31]= local[24];
	local[32]= fqv[149];
	ctx->vsp=local+33;
	w=(*ftab[18])(ctx,2,local+31,&ftab[18],fqv[128]); /*send-all*/
	local[31]= w;
	local[32]= NIL;
	local[33]= NIL;
	local[34]= NIL;
	local[35]= NIL;
	local[36]= NIL;
	local[37]= NIL;
	local[38]= NIL;
	local[39]= NIL;
	local[40]= local[24];
	local[41]= fqv[149];
	local[42]= fqv[120];
	ctx->vsp=local+43;
	w=(*ftab[18])(ctx,3,local+40,&ftab[18],fqv[128]); /*send-all*/
	if (local[2]==NIL) goto OR2282;
	if (local[3]==NIL) goto OR2282;
	goto IF2280;
OR2282:
	local[40]= fqv[447];
	ctx->vsp=local+41;
	w=(*ftab[2])(ctx,1,local+40,&ftab[2],fqv[15]); /*warn*/
	w = T;
	ctx->vsp=local+40;
	local[0]=w;
	goto BLK2237;
	goto IF2281;
IF2280:
	local[40]= NIL;
IF2281:
	if (local[8]!=NIL) goto IF2283;
	if (local[7]!=NIL) goto IF2283;
	w = T;
	ctx->vsp=local+40;
	local[0]=w;
	goto BLK2237;
	goto IF2284;
IF2283:
	local[40]= NIL;
IF2284:
	if (local[18]==NIL) goto IF2285;
	local[40]= NIL;
	local[41]= fqv[448];
	if (local[30]==NIL) goto IF2287;
	local[42]= fqv[449];
	goto IF2288;
IF2287:
	local[42]= fqv[450];
IF2288:
	local[43]= fqv[451];
	ctx->vsp=local+44;
	w=(pointer)LOCALTIME(ctx,0,local+44); /*unix:localtime*/
	local[44]= w;
	ctx->vsp=local+45;
	w=(pointer)ASCTIME(ctx,1,local+44); /*unix:asctime*/
	local[44]= w;
	ctx->vsp=local+45;
	w=(*ftab[48])(ctx,2,local+43,&ftab[48],fqv[452]); /*string-trim*/
	local[43]= w;
	local[44]= loadglobal(fqv[453]);
	ctx->vsp=local+45;
	w=(pointer)XFORMAT(ctx,5,local+40); /*format*/
	local[39] = w;
	local[40]= NIL;
	local[41]= fqv[454];
	local[42]= local[39];
	local[43]= local[2];
	ctx->vsp=local+44;
	w=(pointer)XFORMAT(ctx,4,local+40); /*format*/
	local[39] = w;
	local[40]= NIL;
	local[41]= fqv[455];
	local[42]= local[39];
	local[43]= local[3];
	ctx->vsp=local+44;
	w=(pointer)XFORMAT(ctx,4,local+40); /*format*/
	local[39] = w;
	local[40]= NIL;
	local[41]= fqv[456];
	local[42]= local[39];
	local[43]= local[7];
	local[44]= local[8];
	ctx->vsp=local+45;
	w=(pointer)XFORMAT(ctx,5,local+40); /*format*/
	local[39] = w;
	local[40]= NIL;
	local[41]= fqv[457];
	local[42]= local[39];
	local[43]= local[10];
	local[44]= local[11];
	local[45]= local[1];
	ctx->vsp=local+46;
	w=(pointer)XFORMAT(ctx,6,local+40); /*format*/
	local[39] = w;
	local[40]= fqv[458];
	local[41]= fqv[459];
	local[42]= fqv[460];
	ctx->vsp=local+43;
	local[43]= makeclosure(codevec,quotevec,CLO2289,env,argv,local);
	local[44]= argv[2];
	ctx->vsp=local+45;
	w=(pointer)MAPCAR(ctx,2,local+43); /*mapcar*/
	local[43]= w;
	ctx->vsp=local+44;
	w=(pointer)LIST(ctx,1,local+43); /*list*/
	ctx->vsp=local+43;
	local[42]= cons(ctx,local[42],w);
	ctx->vsp=local+43;
	w=(pointer)LIST(ctx,1,local+42); /*list*/
	ctx->vsp=local+42;
	w = cons(ctx,local[41],w);
	ctx->vsp=local+41;
	local[37] = cons(ctx,local[40],w);
	local[40]= fqv[458];
	local[41]= fqv[461];
	local[42]= argv[0];
	local[43]= fqv[154];
	ctx->vsp=local+44;
	w=(pointer)SEND(ctx,2,local+42); /*send*/
	local[42]= w;
	ctx->vsp=local+43;
	w=(pointer)LIST(ctx,1,local+42); /*list*/
	ctx->vsp=local+42;
	w = cons(ctx,local[41],w);
	ctx->vsp=local+41;
	local[38] = cons(ctx,local[40],w);
	local[40]= local[38];
	goto IF2286;
IF2285:
	local[40]= NIL;
IF2286:
	if (local[4]==NIL) goto IF2290;
	w = local[4];
	if (!!iscons(w)) goto IF2292;
	local[40]= local[4];
	ctx->vsp=local+41;
	w=(pointer)LIST(ctx,1,local+40); /*list*/
	local[4] = w;
	local[40]= local[4];
	goto IF2293;
IF2292:
	local[40]= NIL;
IF2293:
	local[40]= fqv[406];
	w = local[4];
	if (memq(local[40],w)==NIL) goto IF2294;
	local[40]= fqv[406];
	w = local[4];
	ctx->vsp=local+41;
	local[4] = cons(ctx,local[40],w);
	local[40]= local[4];
	goto IF2295;
IF2294:
	local[40]= NIL;
IF2295:
	local[40]= fqv[442];
	w = local[4];
	if (memq(local[40],w)==NIL) goto IF2296;
	local[40]= fqv[442];
	w = local[4];
	ctx->vsp=local+41;
	local[4] = cons(ctx,local[40],w);
	local[40]= local[4];
	goto IF2297;
IF2296:
	local[40]= NIL;
IF2297:
	goto IF2291;
IF2290:
	local[40]= NIL;
IF2291:
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!!iscons(w)) goto IF2298;
	local[40]= local[2];
	ctx->vsp=local+41;
	w=(pointer)LIST(ctx,1,local+40); /*list*/
	local[2] = w;
	local[40]= local[2];
	goto IF2299;
IF2298:
	local[40]= NIL;
IF2299:
	w = local[3];
	if (!!iscons(w)) goto IF2300;
	local[40]= local[3];
	ctx->vsp=local+41;
	w=(pointer)LIST(ctx,1,local+40); /*list*/
	local[3] = w;
	local[40]= local[3];
	goto IF2301;
IF2300:
	local[40]= NIL;
IF2301:
	w = local[7];
	if (!!iscons(w)) goto IF2302;
	local[40]= local[7];
	ctx->vsp=local+41;
	w=(pointer)LIST(ctx,1,local+40); /*list*/
	local[7] = w;
	local[40]= local[7];
	goto IF2303;
IF2302:
	local[40]= NIL;
IF2303:
	w = local[8];
	if (!!iscons(w)) goto IF2304;
	local[40]= local[8];
	ctx->vsp=local+41;
	w=(pointer)LIST(ctx,1,local+40); /*list*/
	local[8] = w;
	local[40]= local[8];
	goto IF2305;
IF2304:
	local[40]= NIL;
IF2305:
	w = local[10];
	if (!!iscons(w)) goto IF2306;
	local[40]= local[10];
	ctx->vsp=local+41;
	w=(pointer)LIST(ctx,1,local+40); /*list*/
	local[10] = w;
	local[40]= local[10];
	goto IF2307;
IF2306:
	local[40]= NIL;
IF2307:
	w = local[11];
	if (!!iscons(w)) goto IF2308;
	local[40]= local[11];
	ctx->vsp=local+41;
	w=(pointer)LIST(ctx,1,local+40); /*list*/
	local[11] = w;
	local[40]= local[11];
	goto IF2309;
IF2308:
	local[40]= NIL;
IF2309:
	if (local[21]==NIL) goto IF2310;
	w = local[21];
	if (!iscons(w)) goto OR2312;
	local[40]= local[21];
	ctx->vsp=local+41;
	w=(*ftab[43])(ctx,1,local+40,&ftab[43],fqv[321]); /*functionp*/
	if (w!=NIL) goto OR2312;
	goto IF2310;
OR2312:
	local[40]= local[21];
	ctx->vsp=local+41;
	w=(pointer)LIST(ctx,1,local+40); /*list*/
	local[21] = w;
	local[40]= local[21];
	goto IF2311;
IF2310:
	local[40]= NIL;
IF2311:
	if (local[22]==NIL) goto IF2313;
	w = local[22];
	if (!iscons(w)) goto OR2315;
	local[40]= local[22];
	ctx->vsp=local+41;
	w=(*ftab[43])(ctx,1,local+40,&ftab[43],fqv[321]); /*functionp*/
	if (w!=NIL) goto OR2315;
	goto IF2313;
OR2315:
	local[40]= local[22];
	ctx->vsp=local+41;
	w=(pointer)LIST(ctx,1,local+40); /*list*/
	local[22] = w;
	local[40]= local[22];
	goto IF2314;
IF2313:
	local[40]= NIL;
IF2314:
	local[40]= local[8];
	ctx->vsp=local+41;
	w=(pointer)LENGTH(ctx,1,local+40); /*length*/
	local[40]= w;
	local[41]= local[7];
	ctx->vsp=local+42;
	w=(pointer)LENGTH(ctx,1,local+41); /*length*/
	local[41]= w;
	local[42]= local[3];
	ctx->vsp=local+43;
	w=(pointer)LENGTH(ctx,1,local+42); /*length*/
	local[42]= w;
	local[43]= local[2];
	ctx->vsp=local+44;
	w=(pointer)LENGTH(ctx,1,local+43); /*length*/
	local[43]= w;
	local[44]= argv[2];
	ctx->vsp=local+45;
	w=(pointer)LENGTH(ctx,1,local+44); /*length*/
	local[44]= w;
	ctx->vsp=local+45;
	w=(pointer)NUMEQUAL(ctx,5,local+40); /*=*/
	if (w!=NIL) goto IF2316;
	local[40]= fqv[462];
	local[41]= local[8];
	ctx->vsp=local+42;
	w=(pointer)LENGTH(ctx,1,local+41); /*length*/
	local[41]= w;
	local[42]= local[7];
	ctx->vsp=local+43;
	w=(pointer)LENGTH(ctx,1,local+42); /*length*/
	local[42]= w;
	local[43]= local[3];
	ctx->vsp=local+44;
	w=(pointer)LENGTH(ctx,1,local+43); /*length*/
	local[43]= w;
	local[44]= local[2];
	ctx->vsp=local+45;
	w=(pointer)LENGTH(ctx,1,local+44); /*length*/
	local[44]= w;
	local[45]= argv[2];
	ctx->vsp=local+46;
	w=(pointer)LENGTH(ctx,1,local+45); /*length*/
	local[45]= w;
	ctx->vsp=local+46;
	w=(*ftab[2])(ctx,6,local+40,&ftab[2],fqv[15]); /*warn*/
	w = T;
	ctx->vsp=local+40;
	local[0]=w;
	goto BLK2237;
	goto IF2317;
IF2316:
	local[40]= NIL;
IF2317:
	local[40]= local[21];
	ctx->vsp=local+41;
	w=(pointer)LENGTH(ctx,1,local+40); /*length*/
	local[40]= w;
	local[41]= local[22];
	ctx->vsp=local+42;
	w=(pointer)LENGTH(ctx,1,local+41); /*length*/
	if (w==local[40]) goto IF2318;
	local[40]= fqv[463];
	local[41]= local[21];
	ctx->vsp=local+42;
	w=(pointer)LENGTH(ctx,1,local+41); /*length*/
	local[41]= w;
	local[42]= local[22];
	ctx->vsp=local+43;
	w=(pointer)LENGTH(ctx,1,local+42); /*length*/
	local[42]= w;
	ctx->vsp=local+43;
	w=(*ftab[2])(ctx,3,local+40,&ftab[2],fqv[15]); /*warn*/
	w = T;
	ctx->vsp=local+40;
	local[0]=w;
	goto BLK2237;
	goto IF2319;
IF2318:
	local[40]= NIL;
IF2319:
	ctx->vsp=local+40;
	local[40]= makeclosure(codevec,quotevec,CLO2320,env,argv,local);
	local[41]= local[21];
	ctx->vsp=local+42;
	w=(pointer)MAPCAR(ctx,2,local+40); /*mapcar*/
	local[40]= w;
	local[41]= (pointer)get_sym_func(fqv[289]);
	local[42]= argv[0];
	local[43]= fqv[464];
	local[44]= fqv[336];
	local[45]= local[8];
	local[46]= fqv[410];
	local[47]= local[7];
	local[48]= fqv[465];
	if (local[17]!=NIL) goto IF2321;
	if (local[14]==NIL) goto IF2321;
	local[49]= argv[0];
	local[50]= fqv[210];
	local[51]= NIL;
	local[52]= local[16];
	ctx->vsp=local+53;
	w=(pointer)SEND(ctx,4,local+49); /*send*/
	local[49]= w;
	goto IF2322;
IF2321:
	local[49]= makeint((eusinteger_t)0L);
IF2322:
	local[50]= (pointer)get_sym_func(fqv[323]);
	ctx->vsp=local+51;
	local[51]= makeclosure(codevec,quotevec,CLO2323,env,argv,local);
	local[52]= local[40];
	ctx->vsp=local+53;
	w=(pointer)MAPCAR(ctx,2,local+51); /*mapcar*/
	local[51]= w;
	ctx->vsp=local+52;
	w=(*ftab[26])(ctx,2,local+50,&ftab[26],fqv[196]); /*reduce*/
	local[50]= w;
	ctx->vsp=local+51;
	w=(pointer)PLUS(ctx,2,local+49); /*+*/
	local[49]= w;
	local[50]= fqv[358];
	local[51]= local[24];
	local[52]= local[0];
	ctx->vsp=local+53;
	w=(pointer)APPLY(ctx,12,local+41); /*apply*/
	local[41]= w;
	local[42]= local[0];
	ctx->vsp=local+43;
	w=(pointer)NCONC(ctx,2,local+41); /*nconc*/
	local[32] = w;
	w = local[32];
	local[40]= argv[0];
	local[41]= fqv[405];
	local[42]= local[24];
	ctx->vsp=local+43;
	w=(pointer)SEND(ctx,3,local+40); /*send*/
	local[40]= local[18];
	w = fqv[466];
	if (memq(local[40],w)==NIL) goto IF2324;
	local[40]= argv[0];
	local[41]= fqv[150];
	local[42]= fqv[421];
	local[43]= makeint((eusinteger_t)-1L);
	ctx->vsp=local+44;
	local[44]= makeclosure(codevec,quotevec,CLO2326,env,argv,local);
	local[45]= argv[2];
	ctx->vsp=local+46;
	w=(pointer)LENGTH(ctx,1,local+45); /*length*/
	local[45]= w;
	ctx->vsp=local+46;
	w=(*ftab[31])(ctx,1,local+45,&ftab[31],fqv[208]); /*make-list*/
	local[45]= w;
	ctx->vsp=local+46;
	w=(pointer)MAPCAR(ctx,2,local+44); /*mapcar*/
	local[43]= w;
	if (local[14]==NIL) goto IF2327;
	local[44]= fqv[258];
	ctx->vsp=local+45;
	w=(pointer)LIST(ctx,1,local+44); /*list*/
	local[44]= w;
	ctx->vsp=local+45;
	w=(pointer)LIST(ctx,1,local+44); /*list*/
	local[44]= w;
	goto IF2328;
IF2327:
	local[44]= NIL;
IF2328:
	local[45]= makeint((eusinteger_t)-1L);
	ctx->vsp=local+46;
	local[46]= makeclosure(codevec,quotevec,CLO2329,env,argv,local);
	local[47]= local[22];
	ctx->vsp=local+48;
	w=(pointer)LENGTH(ctx,1,local+47); /*length*/
	local[47]= w;
	ctx->vsp=local+48;
	w=(*ftab[31])(ctx,1,local+47,&ftab[31],fqv[208]); /*make-list*/
	local[47]= w;
	ctx->vsp=local+48;
	w=(pointer)MAPCAR(ctx,2,local+46); /*mapcar*/
	local[45]= w;
	ctx->vsp=local+46;
	w=(pointer)APPEND(ctx,3,local+43); /*append*/
	local[43]= w;
	ctx->vsp=local+44;
	w=(pointer)SEND(ctx,4,local+40); /*send*/
	local[40]= w;
	goto IF2325;
IF2324:
	local[40]= NIL;
IF2325:
WHL2330:
	local[40]= local[23];
	ctx->vsp=local+41;
	w=(pointer)ADD1(ctx,1,local+40); /*1+*/
	local[23] = w;
	local[40]= local[23];
	local[41]= local[1];
	ctx->vsp=local+42;
	w=(pointer)LESSP(ctx,2,local+40); /*<*/
	if (w==NIL) goto WHX2331;
	ctx->vsp=local+40;
	local[40]= makeclosure(codevec,quotevec,CLO2333,env,argv,local);
	local[41]= argv[2];
	ctx->vsp=local+42;
	w=(pointer)MAPCAR(ctx,2,local+40); /*mapcar*/
	local[40]= w;
	ctx->vsp=local+41;
	local[41]= makeclosure(codevec,quotevec,CLO2334,env,argv,local);
	local[42]= local[3];
	local[43]= local[40];
	local[44]= local[8];
	ctx->vsp=local+45;
	w=(pointer)MAPCAR(ctx,4,local+41); /*mapcar*/
	local[41]= w;
	ctx->vsp=local+42;
	local[42]= makeclosure(codevec,quotevec,CLO2335,env,argv,local);
	local[43]= local[3];
	local[44]= local[40];
	local[45]= local[7];
	ctx->vsp=local+46;
	w=(pointer)MAPCAR(ctx,4,local+42); /*mapcar*/
	local[42]= w;
	local[43]= (pointer)get_sym_func(fqv[289]);
	local[44]= argv[0];
	local[45]= fqv[467];
	local[46]= local[41];
	local[47]= local[42];
	local[48]= fqv[468];
	local[49]= local[40];
	local[50]= fqv[469];
	local[51]= local[19];
	local[52]= fqv[470];
	local[53]= local[1];
	local[54]= fqv[471];
	local[55]= local[23];
	local[56]= fqv[410];
	local[57]= local[7];
	local[58]= fqv[336];
	local[59]= local[8];
	local[60]= fqv[301];
	local[61]= local[3];
	local[62]= fqv[358];
	local[63]= local[24];
	local[64]= fqv[472];
	local[65]= local[10];
	local[66]= fqv[473];
	local[67]= local[11];
	local[68]= fqv[474];
	local[69]= local[21];
	local[70]= fqv[475];
	local[71]= local[22];
	local[72]= fqv[341];
	local[73]= local[4];
	local[74]= fqv[476];
	local[75]= local[32];
	local[76]= local[0];
	ctx->vsp=local+77;
	w=(pointer)APPLY(ctx,34,local+43); /*apply*/
	local[30] = w;
	local[43]= local[30];
	if (fqv[433]!=local[43]) goto IF2336;
	local[30] = T;
	w = NIL;
	ctx->vsp=local+43;
	local[40]=w;
	goto BLK2332;
	goto IF2337;
IF2336:
	local[43]= NIL;
IF2337:
	w = local[43];
	goto WHL2330;
WHX2331:
	local[40]= NIL;
BLK2332:
	if (local[14]==NIL) goto IF2338;
	local[40]= argv[0];
	local[41]= fqv[333];
	ctx->vsp=local+42;
	w=(pointer)SEND(ctx,2,local+40); /*send*/
	local[40]= w;
	goto IF2339;
IF2338:
	local[40]= NIL;
IF2339:
	ctx->vsp=local+40;
	local[40]= makeclosure(codevec,quotevec,CLO2340,env,argv,local);
	local[41]= argv[2];
	ctx->vsp=local+42;
	w=(pointer)MAPCAR(ctx,2,local+40); /*mapcar*/
	local[40]= w;
	ctx->vsp=local+41;
	local[41]= makeclosure(codevec,quotevec,CLO2341,env,argv,local);
	local[42]= local[3];
	local[43]= local[40];
	local[44]= local[8];
	ctx->vsp=local+45;
	w=(pointer)MAPCAR(ctx,4,local+41); /*mapcar*/
	local[28] = w;
	ctx->vsp=local+41;
	local[41]= makeclosure(codevec,quotevec,CLO2342,env,argv,local);
	local[42]= local[3];
	local[43]= local[40];
	local[44]= local[7];
	ctx->vsp=local+45;
	w=(pointer)MAPCAR(ctx,4,local+41); /*mapcar*/
	local[29] = w;
	local[41]= argv[0];
	local[42]= fqv[415];
	local[43]= local[30];
	local[44]= local[28];
	local[45]= local[29];
	local[46]= local[7];
	local[47]= local[8];
	local[48]= local[10];
	local[49]= local[11];
	local[50]= local[13];
	local[51]= local[14];
	local[52]= local[15];
	local[53]= local[16];
	local[54]= fqv[333];
	local[55]= NIL;
	ctx->vsp=local+56;
	w=(pointer)SEND(ctx,15,local+41); /*send*/
	local[30] = w;
	w = local[30];
	ctx->vsp=local+40;
	local[40]= makeclosure(codevec,quotevec,CLO2343,env,argv,local);
	local[41]= local[24];
	local[42]= local[31];
	ctx->vsp=local+43;
	w=(pointer)MAPCAR(ctx,3,local+40); /*mapcar*/
	local[40]= argv[0];
	local[41]= fqv[405];
	local[42]= local[24];
	ctx->vsp=local+43;
	w=(pointer)SEND(ctx,3,local+40); /*send*/
	if (local[20]==NIL) goto IF2344;
	local[40]= argv[0];
	local[41]= fqv[477];
	ctx->vsp=local+42;
	w=(pointer)SEND(ctx,2,local+40); /*send*/
	local[33] = w;
	local[40]= local[33];
	goto IF2345;
IF2344:
	local[40]= NIL;
IF2345:
	local[40]= local[30];
	if (local[40]!=NIL) goto OR2347;
	local[40]= ((local[6])==NIL?T:NIL);
OR2347:
	if (local[40]==NIL) goto AND2346;
	local[40]= ((local[33])==NIL?T:NIL);
AND2346:
	local[30] = local[40];
	local[40]= local[18];
	w = fqv[478];
	if (memq(local[40],w)!=NIL) goto OR2350;
	local[40]= local[18];
	w = fqv[479];
	if (memq(local[40],w)==NIL) goto AND2351;
	if (local[30]!=NIL) goto AND2351;
	goto OR2350;
AND2351:
	goto IF2348;
OR2350:
	local[40]= NIL;
	local[41]= fqv[480];
	ctx->vsp=local+42;
	w=(pointer)GETPID(ctx,0,local+42); /*unix:getpid*/
	local[42]= w;
	ctx->vsp=local+43;
	w=(pointer)XFORMAT(ctx,3,local+40); /*format*/
	local[34] = w;
	ctx->vsp=local+40;
	w=(pointer)LOCALTIME(ctx,0,local+40); /*unix:localtime*/
	local[40]= w;
	ctx->vsp=local+41;
	w=(pointer)GETTIMEOFDAY(ctx,0,local+41); /*unix:gettimeofday*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[41]= (w)->c.cons.car;
	local[42]= makeint((eusinteger_t)48L);
	local[43]= makeint((eusinteger_t)32L);
	local[44]= NIL;
	local[45]= fqv[481];
	local[46]= argv[0];
	ctx->vsp=local+47;
	w=(pointer)GETCLASS(ctx,1,local+46); /*class*/
	local[46]= w;
	local[47]= fqv[3];
	ctx->vsp=local+48;
	w=(pointer)SEND(ctx,2,local+46); /*send*/
	local[46]= w;
	local[47]= makeint((eusinteger_t)1900L);
	local[48]= local[40];
	local[49]= makeint((eusinteger_t)5L);
	ctx->vsp=local+50;
	w=(pointer)ELT(ctx,2,local+48); /*elt*/
	local[48]= w;
	ctx->vsp=local+49;
	w=(pointer)PLUS(ctx,2,local+47); /*+*/
	local[47]= w;
	local[48]= makeint((eusinteger_t)1L);
	local[49]= local[40];
	local[50]= makeint((eusinteger_t)4L);
	ctx->vsp=local+51;
	w=(pointer)ELT(ctx,2,local+49); /*elt*/
	local[49]= w;
	ctx->vsp=local+50;
	w=(pointer)PLUS(ctx,2,local+48); /*+*/
	local[48]= w;
	local[49]= local[40];
	local[50]= makeint((eusinteger_t)3L);
	ctx->vsp=local+51;
	w=(pointer)ELT(ctx,2,local+49); /*elt*/
	local[49]= w;
	local[50]= local[40];
	local[51]= makeint((eusinteger_t)2L);
	ctx->vsp=local+52;
	w=(pointer)ELT(ctx,2,local+50); /*elt*/
	local[50]= w;
	local[51]= local[40];
	local[52]= makeint((eusinteger_t)1L);
	ctx->vsp=local+53;
	w=(pointer)ELT(ctx,2,local+51); /*elt*/
	local[51]= w;
	local[52]= local[40];
	local[53]= makeint((eusinteger_t)0L);
	ctx->vsp=local+54;
	w=(pointer)ELT(ctx,2,local+52); /*elt*/
	local[52]= w;
	local[53]= NIL;
	local[54]= fqv[482];
	local[55]= local[41];
	ctx->vsp=local+56;
	w=(pointer)XFORMAT(ctx,3,local+53); /*format*/
	local[53]= w;
	local[54]= makeint((eusinteger_t)0L);
	local[55]= makeint((eusinteger_t)2L);
	ctx->vsp=local+56;
	w=(pointer)SUBSEQ(ctx,3,local+53); /*subseq*/
	local[53]= w;
	local[54]= NIL;
	local[55]= fqv[483];
	local[56]= local[41];
	ctx->vsp=local+57;
	w=(pointer)XFORMAT(ctx,3,local+54); /*format*/
	local[54]= w;
	local[55]= makeint((eusinteger_t)2L);
	local[56]= makeint((eusinteger_t)4L);
	ctx->vsp=local+57;
	w=(pointer)SUBSEQ(ctx,3,local+54); /*subseq*/
	local[54]= w;
	local[55]= NIL;
	local[56]= fqv[484];
	local[57]= local[41];
	ctx->vsp=local+58;
	w=(pointer)XFORMAT(ctx,3,local+55); /*format*/
	local[55]= w;
	local[56]= makeint((eusinteger_t)4L);
	ctx->vsp=local+57;
	w=(pointer)SUBSEQ(ctx,2,local+55); /*subseq*/
	local[55]= w;
	ctx->vsp=local+56;
	w=(pointer)XFORMAT(ctx,12,local+44); /*format*/
	local[44]= w;
	ctx->vsp=local+45;
	w=(*ftab[49])(ctx,3,local+42,&ftab[49],fqv[485]); /*substitute*/
	local[36] = w;
	local[40]= NIL;
	local[41]= fqv[486];
	local[42]= local[34];
	local[43]= local[36];
	if (local[30]==NIL) goto IF2352;
	local[44]= fqv[487];
	goto IF2353;
IF2352:
	local[44]= fqv[488];
IF2353:
	ctx->vsp=local+45;
	w=(pointer)XFORMAT(ctx,5,local+40); /*format*/
	local[35] = w;
	local[40]= local[34];
	ctx->vsp=local+41;
	w=(*ftab[50])(ctx,1,local+40,&ftab[50],fqv[489]); /*unix:mkdir*/
	local[40]= local[35];
	local[41]= fqv[178];
	local[42]= fqv[179];
	ctx->vsp=local+43;
	w=(*ftab[25])(ctx,3,local+40,&ftab[25],fqv[180]); /*open*/
	local[40]= w;
	ctx->vsp=local+41;
	w = makeclosure(codevec,quotevec,UWP2354,env,argv,local);
	local[41]=(pointer)(ctx->protfp); local[42]=w;
	ctx->protfp=(struct protectframe *)(local+41);
	local[43]= local[40];
	local[44]= fqv[490];
	local[45]= local[39];
	ctx->vsp=local+46;
	w=(pointer)XFORMAT(ctx,3,local+43); /*format*/
	local[43]= local[40];
	local[44]= local[37];
	ctx->vsp=local+45;
	w=(*ftab[51])(ctx,2,local+43,&ftab[51],fqv[491]); /*dump-structure*/
	local[43]= local[40];
	local[44]= local[38];
	ctx->vsp=local+45;
	w=(*ftab[51])(ctx,2,local+43,&ftab[51],fqv[491]); /*dump-structure*/
	ctx->vsp=local+43;
	UWP2354(ctx,0,local+43,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[40]= local[18];
	w = fqv[492];
	if (memq(local[40],w)==NIL) goto IF2355;
	local[40]= NIL;
	local[41]= fqv[493];
	local[42]= local[34];
	local[43]= local[36];
	if (local[30]==NIL) goto IF2357;
	local[44]= fqv[494];
	goto IF2358;
IF2357:
	local[44]= fqv[495];
IF2358:
	ctx->vsp=local+45;
	w=(pointer)XFORMAT(ctx,5,local+40); /*format*/
	local[40]= w;
	local[41]= fqv[178];
	local[42]= fqv[179];
	ctx->vsp=local+43;
	w=(*ftab[25])(ctx,3,local+40,&ftab[25],fqv[180]); /*open*/
	local[40]= w;
	ctx->vsp=local+41;
	w = makeclosure(codevec,quotevec,UWP2359,env,argv,local);
	local[41]=(pointer)(ctx->protfp); local[42]=w;
	ctx->protfp=(struct protectframe *)(local+41);
	local[43]= local[40];
	local[44]= fqv[496];
	local[45]= local[23];
	ctx->vsp=local+46;
	w=(pointer)XFORMAT(ctx,3,local+43); /*format*/
	local[43]= local[40];
	local[44]= fqv[497];
	ctx->vsp=local+45;
	local[45]= makeclosure(codevec,quotevec,CLO2360,env,argv,local);
	local[46]= argv[0];
	local[47]= fqv[184];
	local[48]= fqv[421];
	ctx->vsp=local+49;
	w=(pointer)SEND(ctx,3,local+46); /*send*/
	local[46]= w;
	ctx->vsp=local+47;
	w=(pointer)MAPCAR(ctx,2,local+45); /*mapcar*/
	local[45]= w;
	ctx->vsp=local+46;
	w=(pointer)XFORMAT(ctx,3,local+43); /*format*/
	local[43]= local[40];
	local[44]= fqv[498];
	local[45]= makeint((eusinteger_t)-1L);
	ctx->vsp=local+46;
	local[46]= makeclosure(codevec,quotevec,CLO2361,env,argv,local);
	local[47]= local[10];
	local[48]= local[11];
	ctx->vsp=local+49;
	w=(pointer)MAPCAR(ctx,3,local+46); /*mapcar*/
	local[45]= w;
	if (local[14]==NIL) goto IF2362;
	local[46]= fqv[258];
	local[47]= makeflt(1.0000000000000000208167e-03);
	local[48]= local[13];
	ctx->vsp=local+49;
	w=(pointer)TIMES(ctx,2,local+47); /***/
	local[47]= w;
	ctx->vsp=local+48;
	w=(pointer)LIST(ctx,2,local+46); /*list*/
	local[46]= w;
	ctx->vsp=local+47;
	w=(pointer)LIST(ctx,1,local+46); /*list*/
	local[46]= w;
	goto IF2363;
IF2362:
	local[46]= NIL;
IF2363:
	ctx->vsp=local+47;
	w=(pointer)APPEND(ctx,2,local+45); /*append*/
	local[45]= w;
	ctx->vsp=local+46;
	w=(pointer)XFORMAT(ctx,3,local+43); /*format*/
	local[43]= argv[0];
	local[44]= fqv[421];
	ctx->vsp=local+45;
	w=(*ftab[52])(ctx,2,local+43,&ftab[52],fqv[499]); /*remprop*/
	ctx->vsp=local+43;
	UWP2359(ctx,0,local+43,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[40]= w;
	goto IF2356;
IF2355:
	local[40]= NIL;
IF2356:
	goto IF2349;
IF2348:
	local[40]= NIL;
IF2349:
	if (local[30]==NIL) goto IF2364;
	local[40]= argv[0];
	local[41]= fqv[154];
	ctx->vsp=local+42;
	w=(pointer)SEND(ctx,2,local+40); /*send*/
	local[40]= w;
	goto IF2365;
IF2364:
	if (local[5]==NIL) goto IF2366;
	local[40]= fqv[500];
	ctx->vsp=local+41;
	w=(*ftab[2])(ctx,1,local+40,&ftab[2],fqv[15]); /*warn*/
	local[40]= makeint((eusinteger_t)0L);
	local[41]= local[3];
	ctx->vsp=local+42;
	w=(pointer)LENGTH(ctx,1,local+41); /*length*/
	local[41]= w;
WHL2369:
	local[42]= local[40];
	w = local[41];
	if ((eusinteger_t)local[42] >= (eusinteger_t)w) goto WHX2370;
	local[42]= fqv[501];
	local[43]= local[28];
	local[44]= local[40];
	ctx->vsp=local+45;
	w=(pointer)ELT(ctx,2,local+43); /*elt*/
	local[43]= w;
	local[44]= local[28];
	local[45]= local[40];
	ctx->vsp=local+46;
	w=(pointer)ELT(ctx,2,local+44); /*elt*/
	local[44]= w;
	ctx->vsp=local+45;
	w=(pointer)VNORM(ctx,1,local+44); /*norm*/
	local[44]= w;
	local[45]= local[10];
	local[46]= local[40];
	ctx->vsp=local+47;
	w=(pointer)ELT(ctx,2,local+45); /*elt*/
	local[45]= w;
	ctx->vsp=local+46;
	w=(*ftab[2])(ctx,4,local+42,&ftab[2],fqv[15]); /*warn*/
	local[42]= fqv[502];
	local[43]= local[29];
	local[44]= local[40];
	ctx->vsp=local+45;
	w=(pointer)ELT(ctx,2,local+43); /*elt*/
	local[43]= w;
	local[44]= local[29];
	local[45]= local[40];
	ctx->vsp=local+46;
	w=(pointer)ELT(ctx,2,local+44); /*elt*/
	local[44]= w;
	ctx->vsp=local+45;
	w=(pointer)VNORM(ctx,1,local+44); /*norm*/
	local[44]= w;
	local[45]= local[11];
	local[46]= local[40];
	ctx->vsp=local+47;
	w=(pointer)ELT(ctx,2,local+45); /*elt*/
	local[45]= w;
	ctx->vsp=local+46;
	w=(*ftab[2])(ctx,4,local+42,&ftab[2],fqv[15]); /*warn*/
	local[42]= local[40];
	ctx->vsp=local+43;
	w=(pointer)ADD1(ctx,1,local+42); /*1+*/
	local[40] = w;
	goto WHL2369;
WHX2370:
	local[42]= NIL;
BLK2371:
	w = NIL;
	if (local[14]==NIL) goto IF2372;
	local[40]= argv[0];
	local[41]= fqv[503];
	local[42]= local[14];
	local[43]= fqv[332];
	local[44]= local[15];
	local[45]= fqv[336];
	local[46]= local[16];
	local[47]= fqv[333];
	local[48]= NIL;
	ctx->vsp=local+49;
	w=(pointer)SEND(ctx,9,local+40); /*send*/
	local[40]= w;
	local[41]= fqv[504];
	local[42]= local[40];
	local[43]= local[40];
	ctx->vsp=local+44;
	w=(pointer)VNORM(ctx,1,local+43); /*norm*/
	local[43]= w;
	local[44]= local[13];
	ctx->vsp=local+45;
	w=(*ftab[2])(ctx,4,local+41,&ftab[2],fqv[15]); /*warn*/
	local[40]= w;
	goto IF2373;
IF2372:
	local[40]= NIL;
IF2373:
	local[40]= fqv[505];
	local[41]= argv[0];
WHL2374:
	local[42]= local[41];
	local[43]= fqv[215];
	ctx->vsp=local+44;
	w=(pointer)SEND(ctx,2,local+42); /*send*/
	if (w==NIL) goto WHX2375;
	local[42]= local[41];
	local[43]= fqv[215];
	ctx->vsp=local+44;
	w=(pointer)SEND(ctx,2,local+42); /*send*/
	local[41] = w;
	goto WHL2374;
WHX2375:
	local[42]= NIL;
BLK2376:
	w = local[41];
	local[41]= w;
	local[42]= fqv[122];
	ctx->vsp=local+43;
	w=(pointer)SEND(ctx,2,local+41); /*send*/
	local[41]= w;
	ctx->vsp=local+42;
	w=(*ftab[2])(ctx,2,local+40,&ftab[2],fqv[15]); /*warn*/
	local[40]= fqv[506];
	local[41]= local[25];
	ctx->vsp=local+42;
	w=(*ftab[2])(ctx,2,local+40,&ftab[2],fqv[15]); /*warn*/
	if (local[20]==NIL) goto IF2377;
	local[40]= fqv[507];
	local[41]= local[33];
	ctx->vsp=local+42;
	w=(*ftab[2])(ctx,2,local+40,&ftab[2],fqv[15]); /*warn*/
	local[40]= w;
	goto IF2378;
IF2377:
	local[40]= NIL;
IF2378:
	local[40]= fqv[508];
	local[41]= argv[2];
	ctx->vsp=local+42;
	w=(pointer)LIST(ctx,1,local+41); /*list*/
	local[41]= w;
	local[42]= local[0];
	ctx->vsp=local+43;
	w=(pointer)APPEND(ctx,2,local+41); /*append*/
	local[41]= w;
	ctx->vsp=local+42;
	w=(*ftab[2])(ctx,2,local+40,&ftab[2],fqv[15]); /*warn*/
	if (local[18]==NIL) goto IF2379;
	local[40]= NIL;
	local[41]= NIL;
	local[42]= NIL;
	local[43]= NIL;
	local[44]= NIL;
	ctx->vsp=local+45;
	local[45]= makeclosure(codevec,quotevec,FLET2381,env,argv,local);
	ctx->vsp=local+46;
	local[46]= makeclosure(codevec,quotevec,FLET2382,env,argv,local);
	ctx->vsp=local+47;
	local[47]= makeclosure(codevec,quotevec,FLET2383,env,argv,local);
	ctx->vsp=local+48;
	local[48]= makeclosure(codevec,quotevec,FLET2384,env,argv,local);
	ctx->vsp=local+49;
	local[49]= makeclosure(codevec,quotevec,FLET2385,env,argv,local);
	ctx->vsp=local+50;
	local[50]= makeclosure(codevec,quotevec,FLET2386,env,argv,local);
	local[51]= local[0];
	w = local[50];
	ctx->vsp=local+52;
	w=FLET2386(ctx,1,local+51,w);
	local[41] = w;
	local[51]= makeint((eusinteger_t)0L);
	local[52]= local[41];
	ctx->vsp=local+53;
	w=(pointer)LENGTH(ctx,1,local+52); /*length*/
	local[52]= w;
	local[53]= makeint((eusinteger_t)2L);
	ctx->vsp=local+54;
	w=(pointer)QUOTIENT(ctx,2,local+52); /*/*/
	local[52]= w;
WHL2388:
	local[53]= local[51];
	w = local[52];
	if ((eusinteger_t)local[53] >= (eusinteger_t)w) goto WHX2389;
	local[53]= local[41];
	local[54]= makeint((eusinteger_t)2L);
	{ eusinteger_t i,j;
		j=intval(local[51]); i=intval(local[54]);
		local[54]=(makeint(i * j));}
	ctx->vsp=local+55;
	w=(pointer)ELT(ctx,2,local+53); /*elt*/
	local[53]= w;
	if (fqv[301]==local[53]) goto IF2391;
	local[53]= local[41];
	local[54]= makeint((eusinteger_t)1L);
	local[55]= makeint((eusinteger_t)2L);
	{ eusinteger_t i,j;
		j=intval(local[51]); i=intval(local[55]);
		local[55]=(makeint(i * j));}
	w = local[55];
#if sun4 || vax || mips || alpha || Linux
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[54]= (pointer)((eusinteger_t)local[54] + (eusinteger_t)w);
	w = local[46];
	ctx->vsp=local+55;
	w=FLET2382(ctx,2,local+53,w);
	local[53]= w;
	goto IF2392;
IF2391:
	local[53]= NIL;
IF2392:
	local[53]= local[51];
	ctx->vsp=local+54;
	w=(pointer)ADD1(ctx,1,local+53); /*1+*/
	local[51] = w;
	goto WHL2388;
WHX2389:
	local[53]= NIL;
BLK2390:
	w = NIL;
	local[51]= makeint((eusinteger_t)0L);
	local[52]= local[41];
	ctx->vsp=local+53;
	w=(pointer)LENGTH(ctx,1,local+52); /*length*/
	local[52]= w;
WHL2394:
	local[53]= local[51];
	w = local[52];
	if ((eusinteger_t)local[53] >= (eusinteger_t)w) goto WHX2395;
	local[53]= local[41];
	local[54]= local[51];
	w = local[47];
	ctx->vsp=local+55;
	w=FLET2383(ctx,2,local+53,w);
	local[53]= local[51];
	ctx->vsp=local+54;
	w=(pointer)ADD1(ctx,1,local+53); /*1+*/
	local[51] = w;
	goto WHL2394;
WHX2395:
	local[53]= NIL;
BLK2396:
	w = NIL;
	local[51]= makeint((eusinteger_t)0L);
	local[52]= fqv[301];
	local[53]= local[41];
	ctx->vsp=local+54;
	w=(*ftab[53])(ctx,2,local+52,&ftab[53],fqv[509]); /*count*/
	local[52]= w;
WHL2398:
	local[53]= local[51];
	w = local[52];
	if ((eusinteger_t)local[53] >= (eusinteger_t)w) goto WHX2399;
	local[53]= fqv[301];
	local[54]= local[41];
	local[55]= fqv[510];
	local[56]= local[51];
	ctx->vsp=local+57;
	w=(pointer)ADD1(ctx,1,local+56); /*1+*/
	local[56]= w;
	ctx->vsp=local+57;
	w=(*ftab[32])(ctx,4,local+53,&ftab[32],fqv[213]); /*position*/
	local[40] = w;
	if (local[40]==NIL) goto IF2401;
	local[53]= local[41];
	local[54]= local[40];
	local[55]= makeint((eusinteger_t)1L);
	ctx->vsp=local+56;
	w=(pointer)PLUS(ctx,2,local+54); /*+*/
	local[54]= w;
	ctx->vsp=local+55;
	w=(pointer)ELT(ctx,2,local+53); /*elt*/
	if (!!iscons(w)) goto CON2404;
	local[53]= local[41];
	local[54]= local[40];
	local[55]= makeint((eusinteger_t)1L);
	ctx->vsp=local+56;
	w=(pointer)PLUS(ctx,2,local+54); /*+*/
	local[54]= w;
	local[55]= local[41];
	local[56]= local[40];
	local[57]= makeint((eusinteger_t)1L);
	ctx->vsp=local+58;
	w=(pointer)PLUS(ctx,2,local+56); /*+*/
	local[56]= w;
	ctx->vsp=local+57;
	w=(pointer)ELT(ctx,2,local+55); /*elt*/
	local[55]= w;
	w = local[49];
	ctx->vsp=local+56;
	w=FLET2385(ctx,1,local+55,w);
	local[55]= w;
	ctx->vsp=local+56;
	w=(pointer)SETELT(ctx,3,local+53); /*setelt*/
	local[53]= w;
	goto CON2403;
CON2404:
	local[53]= local[41];
	local[54]= local[40];
	local[55]= makeint((eusinteger_t)1L);
	ctx->vsp=local+56;
	w=(pointer)PLUS(ctx,2,local+54); /*+*/
	local[54]= w;
	local[55]= fqv[511];
	ctx->vsp=local+56;
	local[56]= makeclosure(codevec,quotevec,CLO2406,env,argv,local);
	local[57]= local[41];
	local[58]= local[40];
	local[59]= makeint((eusinteger_t)1L);
	ctx->vsp=local+60;
	w=(pointer)PLUS(ctx,2,local+58); /*+*/
	local[58]= w;
	ctx->vsp=local+59;
	w=(pointer)ELT(ctx,2,local+57); /*elt*/
	local[57]= w;
	ctx->vsp=local+58;
	w=(pointer)MAPCAR(ctx,2,local+56); /*mapcar*/
	local[56]= w;
	ctx->vsp=local+57;
	w=(pointer)APPEND(ctx,2,local+55); /*append*/
	local[55]= w;
	ctx->vsp=local+56;
	w=(pointer)SETELT(ctx,3,local+53); /*setelt*/
	local[53]= w;
	goto CON2403;
CON2405:
	local[53]= NIL;
CON2403:
	goto IF2402;
IF2401:
	local[53]= NIL;
IF2402:
	local[53]= local[51];
	ctx->vsp=local+54;
	w=(pointer)ADD1(ctx,1,local+53); /*1+*/
	local[51] = w;
	goto WHL2398;
WHX2399:
	local[53]= NIL;
BLK2400:
	w = NIL;
	local[51]= fqv[512];
	local[52]= argv[0];
	ctx->vsp=local+53;
	w=(pointer)GETCLASS(ctx,1,local+52); /*class*/
	local[52]= w;
	local[53]= fqv[3];
	ctx->vsp=local+54;
	w=(pointer)SEND(ctx,2,local+52); /*send*/
	local[52]= w;
	local[53]= fqv[36];
	ctx->vsp=local+54;
	w=(pointer)LIST(ctx,1,local+53); /*list*/
	ctx->vsp=local+53;
	w = cons(ctx,local[52],w);
	ctx->vsp=local+52;
	local[42] = cons(ctx,local[51],w);
	local[51]= fqv[513];
	local[52]= fqv[289];
	local[53]= fqv[514];
	local[54]= fqv[159];
	local[55]= fqv[86];
	local[56]= fqv[515];
	local[57]= argv[0];
	local[58]= fqv[515];
	ctx->vsp=local+59;
	w=(pointer)SEND(ctx,2,local+57); /*send*/
	local[57]= w;
	ctx->vsp=local+58;
	w=(pointer)LIST(ctx,1,local+57); /*list*/
	ctx->vsp=local+57;
	w = cons(ctx,local[56],w);
	ctx->vsp=local+56;
	local[55]= cons(ctx,local[55],w);
	ctx->vsp=local+56;
	w=(pointer)LIST(ctx,1,local+55); /*list*/
	ctx->vsp=local+55;
	w = cons(ctx,local[54],w);
	ctx->vsp=local+54;
	w = cons(ctx,local[53],w);
	ctx->vsp=local+53;
	local[52]= cons(ctx,local[52],w);
	local[53]= fqv[516];
	local[54]= fqv[517];
	local[55]= fqv[518];
	local[56]= fqv[519];
	local[57]= fqv[520];
	ctx->vsp=local+58;
	w=(pointer)LIST(ctx,1,local+57); /*list*/
	ctx->vsp=local+57;
	local[56]= cons(ctx,local[56],w);
	local[57]= fqv[521];
	local[58]= fqv[519];
	local[59]= fqv[20];
	local[60]= fqv[520];
	local[61]= local[9];
	ctx->vsp=local+62;
	w=(pointer)LIST(ctx,1,local+61); /*list*/
	ctx->vsp=local+61;
	w = cons(ctx,local[60],w);
	ctx->vsp=local+60;
	w = cons(ctx,local[59],w);
	ctx->vsp=local+59;
	w = cons(ctx,local[58],w);
	ctx->vsp=local+58;
	local[57]= cons(ctx,local[57],w);
	ctx->vsp=local+58;
	w=(pointer)LIST(ctx,1,local+57); /*list*/
	ctx->vsp=local+57;
	w = cons(ctx,local[56],w);
	ctx->vsp=local+56;
	local[55]= cons(ctx,local[55],w);
	ctx->vsp=local+56;
	w=(pointer)LIST(ctx,1,local+55); /*list*/
	ctx->vsp=local+55;
	local[54]= cons(ctx,local[54],w);
	local[55]= fqv[522];
	ctx->vsp=local+56;
	local[56]= makeclosure(codevec,quotevec,CLO2407,env,argv,local);
	local[57]= local[24];
	local[58]= fqv[198];
	ctx->vsp=local+59;
	w=(*ftab[18])(ctx,2,local+57,&ftab[18],fqv[128]); /*send-all*/
	local[57]= w;
	local[58]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+59;
	w=(pointer)APPEND(ctx,2,local+57); /*append*/
	local[57]= w;
	ctx->vsp=local+58;
	w=(*ftab[47])(ctx,1,local+57,&ftab[47],fqv[446]); /*remove-duplicates*/
	local[57]= w;
	local[58]= fqv[3];
	ctx->vsp=local+59;
	w=(*ftab[18])(ctx,2,local+57,&ftab[18],fqv[128]); /*send-all*/
	local[57]= w;
	ctx->vsp=local+58;
	w=(pointer)MAPCAR(ctx,2,local+56); /*mapcar*/
	ctx->vsp=local+56;
	local[55]= cons(ctx,local[55],w);
	local[56]= fqv[460];
	local[57]= local[25];
	ctx->vsp=local+58;
	w=(pointer)LIST(ctx,2,local+56); /*list*/
	local[56]= w;
	ctx->vsp=local+57;
	w=(pointer)LIST(ctx,1,local+56); /*list*/
	ctx->vsp=local+56;
	w = cons(ctx,local[55],w);
	ctx->vsp=local+55;
	w = cons(ctx,local[54],w);
	ctx->vsp=local+54;
	local[53]= cons(ctx,local[53],w);
	local[54]= fqv[523];
	local[55]= fqv[522];
	local[56]= fqv[514];
	ctx->vsp=local+57;
	w=(pointer)LIST(ctx,1,local+56); /*list*/
	ctx->vsp=local+56;
	local[55]= cons(ctx,local[55],w);
	ctx->vsp=local+56;
	w=(pointer)LIST(ctx,1,local+55); /*list*/
	ctx->vsp=local+55;
	local[54]= cons(ctx,local[54],w);
	ctx->vsp=local+55;
	w=(pointer)LIST(ctx,1,local+54); /*list*/
	ctx->vsp=local+54;
	w = cons(ctx,local[53],w);
	ctx->vsp=local+53;
	w = cons(ctx,local[52],w);
	ctx->vsp=local+52;
	local[43] = cons(ctx,local[51],w);
	local[51]= fqv[524];
	ctx->vsp=local+52;
	local[52]= makeclosure(codevec,quotevec,CLO2408,env,argv,local);
	local[53]= argv[2];
	ctx->vsp=local+54;
	w=(pointer)MAPCAR(ctx,2,local+52); /*mapcar*/
	local[52]= w;
	local[53]= NIL;
	ctx->vsp=local+54;
	w=(pointer)APPEND(ctx,2,local+52); /*append*/
	local[52]= w;
	ctx->vsp=local+53;
	w=(pointer)LIST(ctx,1,local+52); /*list*/
	local[52]= w;
	local[53]= fqv[525];
	local[54]= NIL;
	local[55]= fqv[341];
	local[56]= T;
	ctx->vsp=local+57;
	w=(pointer)LIST(ctx,4,local+53); /*list*/
	local[53]= w;
	local[54]= local[41];
	ctx->vsp=local+55;
	w=(pointer)APPEND(ctx,4,local+51); /*append*/
	local[44] = w;
	local[51]= local[44];
	local[52]= makeint((eusinteger_t)1L);
	local[53]= fqv[526];
	local[54]= local[44];
	local[55]= makeint((eusinteger_t)1L);
	ctx->vsp=local+56;
	w=(pointer)ELT(ctx,2,local+54); /*elt*/
	local[54]= w;
	ctx->vsp=local+55;
	w=(pointer)APPEND(ctx,2,local+53); /*append*/
	local[53]= w;
	ctx->vsp=local+54;
	w=(pointer)SETELT(ctx,3,local+51); /*setelt*/
	local[45]= fqv[527];
	local[46]= fqv[528];
	local[47]= fqv[514];
	local[48]= local[42];
	ctx->vsp=local+49;
	w=(pointer)LIST(ctx,1,local+48); /*list*/
	ctx->vsp=local+48;
	local[47]= cons(ctx,local[47],w);
	ctx->vsp=local+48;
	w=(pointer)LIST(ctx,1,local+47); /*list*/
	local[47]= w;
	local[48]= local[43];
	local[49]= fqv[521];
	local[50]= fqv[514];
	local[51]= fqv[529];
	local[52]= local[44];
	ctx->vsp=local+53;
	w=(pointer)LIST(ctx,1,local+52); /*list*/
	ctx->vsp=local+52;
	w = cons(ctx,local[51],w);
	ctx->vsp=local+51;
	w = cons(ctx,local[50],w);
	ctx->vsp=local+50;
	local[49]= cons(ctx,local[49],w);
	ctx->vsp=local+50;
	w=(pointer)LIST(ctx,1,local+49); /*list*/
	ctx->vsp=local+49;
	w = cons(ctx,local[48],w);
	ctx->vsp=local+48;
	w = cons(ctx,local[47],w);
	ctx->vsp=local+47;
	local[46]= cons(ctx,local[46],w);
	ctx->vsp=local+47;
	w=(*ftab[2])(ctx,2,local+45,&ftab[2],fqv[15]); /*warn*/
	local[45]= fqv[530];
	local[46]= local[35];
	ctx->vsp=local+47;
	w=(*ftab[2])(ctx,2,local+45,&ftab[2],fqv[15]); /*warn*/
	local[45]= fqv[531];
	local[46]= local[35];
	ctx->vsp=local+47;
	w=(*ftab[2])(ctx,2,local+45,&ftab[2],fqv[15]); /*warn*/
	local[45]= local[35];
	local[46]= fqv[178];
	local[47]= fqv[179];
	local[48]= fqv[532];
	local[49]= fqv[533];
	ctx->vsp=local+50;
	w=(*ftab[25])(ctx,5,local+45,&ftab[25],fqv[180]); /*open*/
	local[45]= w;
	ctx->vsp=local+46;
	w = makeclosure(codevec,quotevec,UWP2409,env,argv,local);
	local[46]=(pointer)(ctx->protfp); local[47]=w;
	ctx->protfp=(struct protectframe *)(local+46);
	local[48]= local[45];
	local[49]= fqv[534];
	local[50]= local[36];
	local[51]= local[42];
	local[52]= local[43];
	ctx->vsp=local+53;
	w=(pointer)XFORMAT(ctx,5,local+48); /*format*/
	local[48]= local[45];
	local[49]= fqv[535];
	local[50]= local[36];
	local[51]= local[44];
	ctx->vsp=local+52;
	w=(pointer)XFORMAT(ctx,4,local+48); /*format*/
	local[48]= local[45];
	local[49]= fqv[536];
	local[50]= local[36];
	ctx->vsp=local+51;
	w=(pointer)XFORMAT(ctx,3,local+48); /*format*/
	local[48]= local[45];
	local[49]= fqv[537];
	local[50]= local[36];
	ctx->vsp=local+51;
	w=(pointer)XFORMAT(ctx,3,local+48); /*format*/
	local[48]= local[45];
	local[49]= fqv[538];
	ctx->vsp=local+50;
	w=(pointer)XFORMAT(ctx,2,local+48); /*format*/
	local[48]= local[45];
	local[49]= fqv[539];
	local[50]= local[28];
	local[51]= local[29];
	ctx->vsp=local+52;
	w=(pointer)XFORMAT(ctx,4,local+48); /*format*/
	if (local[14]==NIL) goto IF2410;
	local[48]= local[45];
	local[49]= fqv[540];
	local[50]= argv[0];
	local[51]= fqv[503];
	local[52]= local[14];
	local[53]= fqv[332];
	local[54]= local[15];
	local[55]= fqv[336];
	local[56]= local[16];
	local[57]= fqv[333];
	local[58]= NIL;
	ctx->vsp=local+59;
	w=(pointer)SEND(ctx,9,local+50); /*send*/
	local[50]= w;
	ctx->vsp=local+51;
	w=(pointer)XFORMAT(ctx,3,local+48); /*format*/
	local[48]= w;
	goto IF2411;
IF2410:
	local[48]= NIL;
IF2411:
	local[48]= local[45];
	local[49]= fqv[541];
	ctx->vsp=local+50;
	w=(pointer)XFORMAT(ctx,2,local+48); /*format*/
	ctx->vsp=local+48;
	UWP2409(ctx,0,local+48,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[40]= w;
	goto IF2380;
IF2379:
	local[40]= NIL;
IF2380:
	goto IF2367;
IF2366:
	local[40]= NIL;
IF2367:
	ctx->vsp=local+40;
	local[40]= makeclosure(codevec,quotevec,CLO2412,env,argv,local);
	local[41]= local[24];
	local[42]= fqv[198];
	ctx->vsp=local+43;
	w=(*ftab[18])(ctx,2,local+41,&ftab[18],fqv[128]); /*send-all*/
	local[41]= w;
	local[42]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+43;
	w=(pointer)APPEND(ctx,2,local+41); /*append*/
	local[41]= w;
	ctx->vsp=local+42;
	w=(*ftab[47])(ctx,1,local+41,&ftab[47],fqv[446]); /*remove-duplicates*/
	local[41]= w;
	local[42]= local[25];
	ctx->vsp=local+43;
	w=(pointer)MAPC(ctx,3,local+40); /*mapc*/
	if (local[26]==NIL) goto IF2413;
	local[40]= argv[0];
	local[41]= fqv[159];
	local[42]= local[26];
	ctx->vsp=local+43;
	w=(pointer)SEND(ctx,3,local+40); /*send*/
	local[40]= w;
	goto IF2414;
IF2413:
	local[40]= NIL;
IF2414:
	local[40]= NIL;
IF2365:
	w = local[40];
	local[0]= w;
BLK2237:
	ctx->vsp=local; return(local[0]);}

/*:ik-convergence-check*/
static pointer M2415cascaded_link_ik_convergence_check(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<13) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[542], &argv[13], n-13, local+0, 0);
	if (n & (1<<0)) goto KEY2417;
	local[0] = T;
KEY2417:
	local[1]= makeint((eusinteger_t)0L);
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
WHL2419:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX2420;
	local[3]= argv[2];
	if (local[3]==NIL) goto AND2422;
	local[3]= argv[6];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	if (w==NIL) goto IF2423;
	local[3]= argv[3];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)VNORM(ctx,1,local+3); /*norm*/
	local[3]= w;
	local[4]= argv[7];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LESSP(ctx,2,local+3); /*<*/
	local[3]= w;
	goto IF2424;
IF2423:
	local[3]= T;
IF2424:
	if (local[3]==NIL) goto AND2422;
	local[3]= argv[5];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	if (w==NIL) goto IF2425;
	local[3]= argv[4];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)VNORM(ctx,1,local+3); /*norm*/
	local[3]= w;
	local[4]= argv[8];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LESSP(ctx,2,local+3); /*<*/
	local[3]= w;
	goto IF2426;
IF2425:
	local[3]= T;
IF2426:
AND2422:
	argv[2] = local[3];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL2419;
WHX2420:
	local[3]= NIL;
BLK2421:
	w = NIL;
	if (argv[10]==NIL) goto IF2427;
	local[1]= argv[2];
	if (local[1]==NIL) goto AND2429;
	local[1]= argv[0];
	local[2]= fqv[543];
	local[3]= argv[9];
	local[4]= argv[10];
	local[5]= fqv[332];
	local[6]= argv[11];
	local[7]= fqv[336];
	local[8]= argv[12];
	local[9]= fqv[333];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,10,local+1); /*send*/
	local[1]= w;
AND2429:
	argv[2] = local[1];
	local[1]= argv[2];
	goto IF2428;
IF2427:
	local[1]= NIL;
IF2428:
	w = argv[2];
	local[0]= w;
BLK2416:
	ctx->vsp=local; return(local[0]);}

/*:calc-vel-from-pos*/
static pointer M2430cascaded_link_calc_vel_from_pos(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
RST2432:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-4);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[544], &argv[4], n-4, local+1, 1);
	if (n & (1<<0)) goto KEY2433;
	local[1] = makeflt(1.0000000000000000000000e+02);
KEY2433:
	if (n & (1<<1)) goto KEY2434;
	local[6]= loadglobal(fqv[5]);
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,2,local+6); /*instantiate*/
	local[2] = w;
KEY2434:
	if (n & (1<<2)) goto KEY2435;
	local[6]= loadglobal(fqv[5]);
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,2,local+6); /*instantiate*/
	local[3] = w;
KEY2435:
	if (n & (1<<3)) goto KEY2436;
	local[6]= loadglobal(fqv[5]);
	local[7]= makeint((eusinteger_t)2L);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,2,local+6); /*instantiate*/
	local[4] = w;
KEY2436:
	if (n & (1<<4)) goto KEY2437;
	local[6]= loadglobal(fqv[5]);
	local[7]= makeint((eusinteger_t)3L);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,2,local+6); /*instantiate*/
	local[5] = w;
KEY2437:
	local[6]= NIL;
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)VNORM(ctx,1,local+7); /*norm*/
	local[7]= w;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)GREATERP(ctx,2,local+7); /*>*/
	if (w==NIL) goto IF2438;
	local[7]= local[1];
	local[8]= argv[2];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(*ftab[4])(ctx,2,local+8,&ftab[4],fqv[26]); /*normalize-vector*/
	local[8]= w;
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,3,local+7); /*scale*/
	argv[2] = w;
	local[7]= argv[2];
	goto IF2439;
IF2438:
	local[7]= NIL;
IF2439:
	local[7]= makeflt(1.0000000000000000208167e-03);
	local[8]= argv[2];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,3,local+7); /*scale*/
	argv[2] = w;
	local[7]= argv[2];
	local[8]= argv[3];
	local[9]= local[2];
	local[10]= local[3];
	local[11]= local[4];
	ctx->vsp=local+12;
	w=(pointer)F766calc_dif_with_axis(ctx,5,local+7); /*calc-dif-with-axis*/
	local[6] = w;
	w = local[6];
	local[0]= w;
BLK2431:
	ctx->vsp=local; return(local[0]);}

/*:calc-vel-from-rot*/
static pointer M2440cascaded_link_calc_vel_from_rot(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
RST2442:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-4);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[545], &argv[4], n-4, local+1, 1);
	if (n & (1<<0)) goto KEY2443;
	local[1] = makeflt(5.0000000000000000000000e-01);
KEY2443:
	if (n & (1<<1)) goto KEY2444;
	local[6]= loadglobal(fqv[5]);
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,2,local+6); /*instantiate*/
	local[2] = w;
KEY2444:
	if (n & (1<<2)) goto KEY2445;
	local[6]= loadglobal(fqv[5]);
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,2,local+6); /*instantiate*/
	local[3] = w;
KEY2445:
	if (n & (1<<3)) goto KEY2446;
	local[6]= loadglobal(fqv[5]);
	local[7]= makeint((eusinteger_t)2L);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,2,local+6); /*instantiate*/
	local[4] = w;
KEY2446:
	if (n & (1<<4)) goto KEY2447;
	local[6]= loadglobal(fqv[5]);
	local[7]= makeint((eusinteger_t)3L);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,2,local+6); /*instantiate*/
	local[5] = w;
KEY2447:
	local[6]= NIL;
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)VNORM(ctx,1,local+7); /*norm*/
	local[7]= w;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)GREATERP(ctx,2,local+7); /*>*/
	if (w==NIL) goto IF2448;
	local[7]= local[1];
	local[8]= argv[2];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(*ftab[4])(ctx,2,local+8,&ftab[4],fqv[26]); /*normalize-vector*/
	local[8]= w;
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,3,local+7); /*scale*/
	argv[2] = w;
	local[7]= argv[2];
	goto IF2449;
IF2448:
	local[7]= NIL;
IF2449:
	local[7]= argv[2];
	local[8]= argv[3];
	local[9]= local[2];
	local[10]= local[3];
	local[11]= local[4];
	ctx->vsp=local+12;
	w=(pointer)F766calc_dif_with_axis(ctx,5,local+7); /*calc-dif-with-axis*/
	local[6] = w;
	w = local[6];
	local[0]= w;
BLK2441:
	ctx->vsp=local; return(local[0]);}

/*:collision-check-pairs*/
static pointer M2450cascaded_link_collision_check_pairs(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[546], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY2452;
	w=argv[0]->c.obj.iv[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)F765all_child_links(ctx,1,local+2); /*all-child-links*/
	ctx->vsp=local+2;
	local[0] = cons(ctx,local[1],w);
KEY2452:
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
WHL2453:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	if (local[2]==NIL) goto WHX2454;
	local[4]= NIL;
	local[5]= local[2];
	local[6]= fqv[547];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= local[2];
	local[7]= fqv[548];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= local[2];
	local[8]= fqv[133];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= local[2];
	local[9]= fqv[215];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)APPEND(ctx,3,local+5); /*append*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[54])(ctx,2,local+4,&ftab[54],fqv[549]); /*remove*/
	local[3] = w;
	local[4]= NIL;
	local[5]= local[0];
WHL2458:
	if (local[5]==NIL) goto WHX2459;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[4];
	w = local[3];
	if (memq(local[6],w)!=NIL) goto IF2462;
	local[6]= local[2];
	w = local[4];
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	w = local[1];
	ctx->vsp=local+7;
	local[1] = cons(ctx,local[6],w);
	local[6]= local[1];
	goto IF2463;
IF2462:
	local[6]= NIL;
IF2463:
	goto WHL2458;
WHX2459:
	local[6]= NIL;
BLK2460:
	w = NIL;
	goto WHL2453;
WHX2454:
	local[4]= NIL;
BLK2455:
	w = local[1];
	local[0]= w;
BLK2451:
	ctx->vsp=local; return(local[0]);}

/*:self-collision-check*/
static pointer M2464cascaded_link_self_collision_check(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[550], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY2466;
	local[0] = fqv[551];
KEY2466:
	if (n & (1<<1)) goto KEY2467;
	local[3]= argv[0];
	local[4]= fqv[552];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[1] = w;
KEY2467:
	if (n & (1<<2)) goto KEY2468;
	local[2] = fqv[164];
KEY2468:
	local[3]= NIL;
	local[4]= makeint((eusinteger_t)0L);
	local[5]= NIL;
	local[6]= local[1];
WHL2470:
	if (local[6]==NIL) goto WHX2471;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[2];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
	ctx->vsp=local+10;
	w=(pointer)FUNCALL(ctx,3,local+7); /*funcall*/
	local[7]= w;
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(*ftab[24])(ctx,2,local+7,&ftab[24],fqv[171]); /*/=*/
	local[7]= w;
	if (local[7]==NIL) goto IF2474;
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[4] = w;
	local[8]= local[0];
	if (fqv[553]!=local[8]) goto IF2476;
	w = local[5];
	ctx->vsp=local+8;
	local[0]=w;
	goto BLK2465;
	goto IF2477;
IF2476:
	local[8]= local[5];
	w = local[3];
	ctx->vsp=local+9;
	local[3] = cons(ctx,local[8],w);
	local[8]= local[3];
IF2477:
	goto IF2475;
IF2474:
	local[8]= NIL;
IF2475:
	w = local[8];
	goto WHL2470;
WHX2471:
	local[7]= NIL;
BLK2472:
	w = NIL;
	w = local[3];
	local[0]= w;
BLK2465:
	ctx->vsp=local; return(local[0]);}

/*:calc-grasp-matrix*/
static pointer M2478cascaded_link_calc_grasp_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[554], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY2480;
	local[2]= makeint((eusinteger_t)6L);
	local[3]= makeint((eusinteger_t)6L);
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	{ eusinteger_t i,j;
		j=intval(w); i=intval(local[3]);
		local[3]=(makeint(i * j));}
	ctx->vsp=local+4;
	w=(*ftab[23])(ctx,2,local+2,&ftab[23],fqv[166]); /*make-matrix*/
	local[0] = w;
KEY2480:
	if (n & (1<<1)) goto KEY2481;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO2482,env,argv,local);
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[1] = w;
KEY2481:
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO2483,env,argv,local);
	local[3]= argv[2];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,3,local+2); /*mapcar*/
	local[2]= w;
	local[3]= makeint((eusinteger_t)0L);
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
WHL2485:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX2486;
	local[5]= makeint((eusinteger_t)0L);
	local[6]= makeint((eusinteger_t)3L);
WHL2489:
	local[7]= local[5];
	w = local[6];
	if ((eusinteger_t)local[7] >= (eusinteger_t)w) goto WHX2490;
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)3L);
WHL2493:
	local[9]= local[7];
	w = local[8];
	if ((eusinteger_t)local[9] >= (eusinteger_t)w) goto WHX2494;
	local[9]= local[0];
	local[10]= local[5];
	local[11]= local[3];
	{ eusinteger_t i,j;
		j=intval(makeint((eusinteger_t)6L)); i=intval(local[11]);
		local[11]=(makeint(i * j));}
	w = local[7];
#if sun4 || vax || mips || alpha || Linux
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[11]= (pointer)((eusinteger_t)local[11] + (eusinteger_t)w);
	local[12]= local[1];
	local[13]= local[3];
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[12]= w;
	local[13]= local[5];
	local[14]= local[7];
	ctx->vsp=local+15;
	w=(pointer)AREF(ctx,3,local+12); /*aref*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)ASET(ctx,4,local+9); /*aset*/
	local[9]= local[0];
	local[10]= makeint((eusinteger_t)3L);
	w = local[5];
#if sun4 || vax || mips || alpha || Linux
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[10]= (pointer)((eusinteger_t)local[10] + (eusinteger_t)w);
	local[11]= local[3];
	{ eusinteger_t i,j;
		j=intval(makeint((eusinteger_t)6L)); i=intval(local[11]);
		local[11]=(makeint(i * j));}
	local[12]= makeint((eusinteger_t)3L);
	w = local[7];
#if sun4 || vax || mips || alpha || Linux
	w=(pointer)((eusinteger_t)w-2);
#endif
	w = (pointer)((eusinteger_t)local[12] + (eusinteger_t)w);
#if sun4 || vax || mips || alpha || Linux
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[11]= (pointer)((eusinteger_t)local[11] + (eusinteger_t)w);
	local[12]= local[1];
	local[13]= local[3];
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[12]= w;
	local[13]= local[5];
	local[14]= local[7];
	ctx->vsp=local+15;
	w=(pointer)AREF(ctx,3,local+12); /*aref*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)ASET(ctx,4,local+9); /*aset*/
	local[9]= local[0];
	local[10]= makeint((eusinteger_t)3L);
	w = local[5];
#if sun4 || vax || mips || alpha || Linux
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[10]= (pointer)((eusinteger_t)local[10] + (eusinteger_t)w);
	local[11]= local[3];
	{ eusinteger_t i,j;
		j=intval(makeint((eusinteger_t)6L)); i=intval(local[11]);
		local[11]=(makeint(i * j));}
	w = local[7];
#if sun4 || vax || mips || alpha || Linux
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[11]= (pointer)((eusinteger_t)local[11] + (eusinteger_t)w);
	local[12]= local[2];
	local[13]= local[3];
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[12]= w;
	local[13]= local[5];
	local[14]= local[7];
	ctx->vsp=local+15;
	w=(pointer)AREF(ctx,3,local+12); /*aref*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)ASET(ctx,4,local+9); /*aset*/
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	local[7] = w;
	goto WHL2493;
WHX2494:
	local[9]= NIL;
BLK2495:
	w = NIL;
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[5] = w;
	goto WHL2489;
WHX2490:
	local[7]= NIL;
BLK2491:
	w = NIL;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL2485;
WHX2486:
	local[5]= NIL;
BLK2487:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK2479:
	ctx->vsp=local; return(local[0]);}

/*:inverse-kinematics-for-closed-loop-forward-kinematics*/
static pointer M2496cascaded_link_inverse_kinematics_for_closed_loop_forward_kinematics(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST2498:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[555], &argv[3], n-3, local+1, 1);
	if (n & (1<<0)) goto KEY2499;
	local[1] = NIL;
KEY2499:
	if (n & (1<<1)) goto KEY2500;
	local[2] = NIL;
KEY2500:
	if (n & (1<<2)) goto KEY2501;
	local[3] = NIL;
KEY2501:
	if (n & (1<<3)) goto KEY2502;
	local[4] = NIL;
KEY2502:
	if (n & (1<<4)) goto KEY2503;
	local[5] = NIL;
KEY2503:
	if (n & (1<<5)) goto KEY2504;
	local[6] = NIL;
KEY2504:
	if (n & (1<<6)) goto KEY2505;
	local[7] = makeint((eusinteger_t)2L);
KEY2505:
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,CLO2506,env,argv,local);
	local[9]= local[5];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)MAPCAR(ctx,3,local+8); /*mapcar*/
	local[8]= (pointer)get_sym_func(fqv[289]);
	local[9]= argv[0];
	local[10]= fqv[529];
	local[11]= argv[2];
	local[12]= fqv[301];
	local[13]= local[1];
	local[14]= fqv[261];
	local[15]= local[2];
	local[16]= fqv[556];
	ctx->vsp=local+17;
	local[17]= makeclosure(codevec,quotevec,CLO2507,env,argv,local);
	local[18]= fqv[360];
	local[19]= local[4];
	ctx->vsp=local+20;
	local[20]= makeclosure(codevec,quotevec,CLO2508,env,argv,local);
	local[21]= local[5];
	ctx->vsp=local+22;
	w=(pointer)MAPCAR(ctx,2,local+20); /*mapcar*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)APPEND(ctx,2,local+19); /*append*/
	local[19]= w;
	local[20]= fqv[557];
	local[21]= local[7];
	local[22]= local[0];
	ctx->vsp=local+23;
	w=(pointer)APPLY(ctx,15,local+8); /*apply*/
	local[0]= w;
BLK2497:
	ctx->vsp=local; return(local[0]);}

/*:calc-jacobian-for-interlocking-joints*/
static pointer M2509cascaded_link_calc_jacobian_for_interlocking_joints(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[558], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY2511;
	local[1]= argv[0];
	local[2]= fqv[559];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[0] = w;
KEY2511:
	local[1]= argv[0];
	local[2]= fqv[197];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[198];
	ctx->vsp=local+4;
	w=(*ftab[18])(ctx,2,local+2,&ftab[18],fqv[128]); /*send-all*/
	local[2]= w;
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO2512,env,argv,local);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[55])(ctx,2,local+3,&ftab[55],fqv[560]); /*remove-if-not*/
	local[3]= w;
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[211];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[23])(ctx,2,local+4,&ftab[23],fqv[166]); /*make-matrix*/
	local[4]= w;
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO2513,env,argv,local);
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)MAPCAR(ctx,2,local+5); /*mapcar*/
	w = local[4];
	local[0]= w;
BLK2510:
	ctx->vsp=local; return(local[0]);}

/*:calc-vel-for-interlocking-joints*/
static pointer M2514cascaded_link_calc_vel_for_interlocking_joints(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[561], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY2516;
	local[1]= argv[0];
	local[2]= fqv[559];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[0] = w;
KEY2516:
	local[1]= argv[0];
	local[2]= fqv[197];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[198];
	ctx->vsp=local+3;
	w=(*ftab[18])(ctx,2,local+1,&ftab[18],fqv[128]); /*send-all*/
	local[1]= w;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO2517,env,argv,local);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[55])(ctx,2,local+2,&ftab[55],fqv[560]); /*remove-if-not*/
	local[2]= w;
	local[3]= loadglobal(fqv[5]);
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,2,local+3); /*instantiate*/
	local[3]= w;
	w = local[3];
	local[0]= w;
BLK2515:
	ctx->vsp=local; return(local[0]);}

/*:set-midpoint-for-interlocking-joints*/
static pointer M2518cascaded_link_set_midpoint_for_interlocking_joints(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[562], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY2520;
	local[1]= argv[0];
	local[2]= fqv[559];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[0] = w;
KEY2520:
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO2521,env,argv,local);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[0]= w;
BLK2519:
	ctx->vsp=local; return(local[0]);}

/*:interlocking-joint-pairs*/
static pointer M2522cascaded_link_interlocking_joint_pairs(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = fqv[563];
	local[0]= w;
BLK2523:
	ctx->vsp=local; return(local[0]);}

/*:check-interlocking-joint-angle-validity*/
static pointer M2524cascaded_link_check_interlocking_joint_angle_validity(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[564], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY2526;
	local[0] = makeflt(1.0000000000000000208167e-03);
KEY2526:
	if (n & (1<<1)) goto KEY2527;
	local[2]= argv[0];
	local[3]= fqv[559];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[1] = w;
KEY2527:
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO2528,env,argv,local);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	local[3]= (pointer)get_sym_func(fqv[565]);
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(*ftab[56])(ctx,2,local+3,&ftab[56],fqv[566]); /*every*/
	local[0]= w;
BLK2525:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1515(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
	local[1]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET1567(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[142]); /*find*/
	if (w!=NIL) goto OR2531;
	if (argv[0]==NIL) goto OR2531;
	goto IF2529;
OR2531:
	local[0]= argv[0];
	goto IF2530;
IF2529:
	local[0]= argv[0];
	local[1]= fqv[215];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[1];
	w = env->c.clo.env2[33];
	ctx->vsp=local+2;
	w=FLET1567(ctx,2,local+0,w);
	local[0]= w;
IF2530:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1662(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
WHL2532:
	if (local[0]==NIL) goto WHX2533;
	local[1]= local[0];
	local[2]= fqv[133];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (w==NIL) goto WHX2533;
	local[1]= argv[0];
	local[2]= fqv[29];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= local[0];
	local[3]= fqv[133];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= fqv[29];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VDISTANCE(ctx,2,local+1); /*distance*/
	local[1]= w;
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(*ftab[8])(ctx,2,local+1,&ftab[8],fqv[81]); /*eps=*/
	if (w==NIL) goto WHX2533;
	local[1]= local[0];
	local[2]= fqv[133];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[0] = w;
	goto WHL2532;
WHX2533:
	local[1]= NIL;
BLK2534:
	local[1]= local[0];
	local[2]= fqv[133];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1679(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env2[5];
	ctx->vsp=local+2;
	w=(*ftab[32])(ctx,2,local+0,&ftab[32],fqv[213]); /*position*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1737(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1769(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=env->c.clo.env2[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= argv[0];
	local[2]= fqv[139];
	local[3]= (pointer)get_sym_func(fqv[140]);
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,4,local+0,&ftab[16],fqv[124]); /*member*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET1775(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= makeint((eusinteger_t)0L);
	local[2]= argv[0];
	local[3]= argv[1];
	local[4]= fqv[139];
	local[5]= (pointer)get_sym_func(fqv[140]);
	ctx->vsp=local+6;
	w=(*ftab[32])(ctx,4,local+2,&ftab[32],fqv[213]); /*position*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SUBSEQ(ctx,3,local+0); /*subseq*/
	local[0]= w;
	local[1]= fqv[198];
	ctx->vsp=local+2;
	w=(*ftab[18])(ctx,2,local+0,&ftab[18],fqv[128]); /*send-all*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)F767calc_target_joint_dimension(ctx,1,local+0); /*calc-target-joint-dimension*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1820(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	local[0]= w;
	if (w==NIL) goto AND2535;
	local[0]= (pointer)get_sym_func(fqv[565]);
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO2536,env,argv,local);
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,3,local+1); /*mapcar*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[56])(ctx,2,local+0,&ftab[56],fqv[566]); /*every*/
	local[0]= w;
AND2535:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2536(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0];
	if (!issymbol(w)) goto CON2538;
	w = argv[1];
	if (!issymbol(w)) goto CON2538;
	local[0]= argv[0];
	local[0]= ((argv[1])==(local[0])?T:NIL);
	goto CON2537;
CON2538:
	w = argv[0];
	if (!isstring(w)) goto CON2539;
	w = argv[1];
	if (!isstring(w)) goto CON2539;
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(*ftab[57])(ctx,2,local+0,&ftab[57],fqv[567]); /*string=*/
	local[0]= w;
	goto CON2537;
CON2539:
	local[0]= T;
	if (local[0]!=NIL) goto CON2537;
CON2540:
	local[0]= NIL;
CON2537:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1852(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env2[3];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[124]); /*member*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2196(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[43])(ctx,1,local+0,&ftab[43],fqv[321]); /*functionp*/
	if (w==NIL) goto IF2541;
	local[0]= argv[0];
	local[1]= env->c.clo.env2[3];
	ctx->vsp=local+2;
	w=(pointer)FUNCALL(ctx,2,local+0); /*funcall*/
	local[0]= w;
	goto IF2542;
IF2541:
	local[0]= argv[0];
IF2542:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2289(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2320(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[43])(ctx,1,local+0,&ftab[43],fqv[321]); /*functionp*/
	if (w==NIL) goto IF2543;
	local[0]= argv[0];
	local[1]= env->c.clo.env2[2];
	ctx->vsp=local+2;
	w=(pointer)FUNCALL(ctx,2,local+0); /*funcall*/
	local[0]= w;
	goto IF2544;
IF2543:
	local[0]= argv[0];
IF2544:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2323(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[43])(ctx,1,local+0,&ftab[43],fqv[321]); /*functionp*/
	if (w==NIL) goto IF2545;
	local[0]= argv[0];
	local[1]= env->c.clo.env2[2];
	ctx->vsp=local+2;
	w=(pointer)FUNCALL(ctx,2,local+0); /*funcall*/
	local[0]= w;
	goto IF2546;
IF2545:
	local[0]= argv[0];
IF2546:
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,2,local+0,&ftab[3],fqv[24]); /*array-dimension*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2326(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= fqv[568];
	local[2]= env->c.clo.env2[43];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	env->c.clo.env2[43] = w;
	local[2]= env->c.clo.env2[43];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[45])(ctx,1,local+0,&ftab[45],fqv[423]); /*read-from-string*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2329(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= fqv[569];
	local[2]= env->c.clo.env2[45];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	env->c.clo.env2[45] = w;
	local[2]= env->c.clo.env2[45];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[45])(ctx,1,local+0,&ftab[45],fqv[423]); /*read-from-string*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2333(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[43])(ctx,1,local+0,&ftab[43],fqv[321]); /*functionp*/
	if (w==NIL) goto IF2547;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FUNCALL(ctx,1,local+0); /*funcall*/
	local[0]= w;
	goto IF2548;
IF2547:
	local[0]= argv[0];
IF2548:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2334(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[570];
	local[2]= argv[1];
	local[3]= fqv[336];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2335(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[571];
	local[2]= argv[1];
	local[3]= fqv[410];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2340(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[43])(ctx,1,local+0,&ftab[43],fqv[321]); /*functionp*/
	if (w==NIL) goto IF2549;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FUNCALL(ctx,1,local+0); /*funcall*/
	local[0]= w;
	goto IF2550;
IF2549:
	local[0]= argv[0];
IF2550:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2341(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[570];
	local[2]= argv[1];
	local[3]= fqv[336];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2342(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[571];
	local[2]= argv[1];
	local[3]= fqv[410];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2343(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[149];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP2354(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[40];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP2359(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[40];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2360(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(pointer)REVERSE(ctx,1,local+1); /*reverse*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2361(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= fqv[572];
	local[2]= env->c.clo.env2[45];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	env->c.clo.env2[45] = w;
	local[2]= env->c.clo.env2[45];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[45])(ctx,1,local+0,&ftab[45],fqv[423]); /*read-from-string*/
	local[0]= w;
	local[1]= makeflt(1.0000000000000000208167e-03);
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET2381(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!isstring(w)) goto IF2551;
	local[0]= NIL;
	local[1]= fqv[573];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto IF2552;
IF2551:
	local[0]= argv[0];
IF2552:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET2382(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	if (!iscons(w)) goto IF2553;
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= fqv[574];
	local[3]= argv[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPEND(ctx,2,local+2); /*append*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SETELT(ctx,3,local+0); /*setelt*/
	local[0]= makeint((eusinteger_t)0L);
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
WHL2556:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX2557;
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	local[3]= local[0];
	w = env->c.clo.env2[46];
	ctx->vsp=local+4;
	w=FLET2382(ctx,2,local+2,w);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL2556;
WHX2557:
	local[2]= NIL;
BLK2558:
	w = NIL;
	local[0]= w;
	goto IF2554;
IF2553:
	local[0]= NIL;
IF2554:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET2383(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	local[1]= loadglobal(fqv[214]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto IF2559;
	local[0]= env->c.clo.env1[0];
	local[1]= fqv[575];
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	local[3]= fqv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (w==NIL) goto IF2559;
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= fqv[289];
	local[3]= fqv[514];
	local[4]= fqv[575];
	local[5]= argv[0];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	local[6]= fqv[3];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	w = env->c.clo.env2[45];
	ctx->vsp=local+6;
	w=FLET2381(ctx,1,local+5,w);
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)SETELT(ctx,3,local+0); /*setelt*/
	local[0]= w;
	goto IF2560;
IF2559:
	local[0]= NIL;
IF2560:
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	if (!iscons(w)) goto IF2561;
	local[0]= makeint((eusinteger_t)0L);
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
WHL2564:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX2565;
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	local[3]= local[0];
	w = env->c.clo.env2[47];
	ctx->vsp=local+4;
	w=FLET2383(ctx,2,local+2,w);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL2564;
WHX2565:
	local[2]= NIL;
BLK2566:
	w = NIL;
	local[0]= w;
	goto IF2562;
IF2561:
	local[0]= NIL;
IF2562:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET2384(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[215];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= env->c.clo.env1[0];
	local[2]= fqv[136];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[142]); /*find*/
	if (w==NIL) goto IF2567;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF2568;
IF2567:
	local[0]= argv[0];
	local[1]= fqv[215];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	w = env->c.clo.env2[48];
	ctx->vsp=local+1;
	w=FLET2384(ctx,1,local+0,w);
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	local[0]= w;
IF2568:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET2385(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = env->c.clo.env2[48];
	ctx->vsp=local+1;
	w=FLET2384(ctx,1,local+0,w);
	local[0]= w;
	local[1]= fqv[576];
	local[2]= fqv[577];
	local[3]= fqv[289];
	local[4]= fqv[514];
	local[5]= fqv[575];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= fqv[215];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= fqv[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	w = env->c.clo.env2[45];
	ctx->vsp=local+7;
	w=FLET2381(ctx,1,local+6,w);
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[578];
	local[4]= fqv[298];
	local[5]= fqv[120];
	local[6]= fqv[289];
	local[7]= fqv[289];
	local[8]= fqv[577];
	local[9]= fqv[153];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[84];
	local[9]= fqv[86];
	local[10]= fqv[515];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= fqv[215];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	local[12]= fqv[104];
	local[13]= local[0];
	ctx->vsp=local+14;
	w=(*ftab[38])(ctx,1,local+13,&ftab[38],fqv[292]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[11]= w;
	local[12]= fqv[515];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[289];
	local[4]= fqv[577];
	local[5]= fqv[299];
	local[6]= fqv[578];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[578];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET2386(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO2569,env,argv,local);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2569(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!iscons(w)) goto IF2570;
	local[0]= argv[0];
	w = env->c.clo.env0->c.clo.env2[50];
	ctx->vsp=local+1;
	w=FLET2386(ctx,1,local+0,w);
	local[0]= w;
	goto IF2571;
IF2570:
	local[0]= argv[0];
IF2571:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2406(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = env->c.clo.env2[49];
	ctx->vsp=local+1;
	w=FLET2385(ctx,1,local+0,w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2407(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[289];
	local[1]= fqv[514];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[58])(ctx,1,local+2,&ftab[58],fqv[579]); /*string-upcase*/
	local[2]= w;
	local[3]= loadglobal(fqv[580]);
	ctx->vsp=local+4;
	w=(pointer)INTERN(ctx,2,local+2); /*intern*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2408(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[86];
	local[1]= fqv[105];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[43])(ctx,1,local+2,&ftab[43],fqv[321]); /*functionp*/
	if (w==NIL) goto IF2572;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)FUNCALL(ctx,1,local+2); /*funcall*/
	local[2]= w;
	goto IF2573;
IF2572:
	local[2]= argv[0];
IF2573:
	local[3]= fqv[29];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= fqv[85];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[43])(ctx,1,local+4,&ftab[43],fqv[321]); /*functionp*/
	if (w==NIL) goto IF2574;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)FUNCALL(ctx,1,local+4); /*funcall*/
	local[4]= w;
	goto IF2575;
IF2574:
	local[4]= argv[0];
IF2575:
	local[5]= fqv[27];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP2409(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[45];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2412(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= (pointer)get_sym_func(fqv[289]);
	local[1]= argv[0];
	local[2]= fqv[20];
	local[3]= argv[1];
	local[4]= env->c.clo.env2[9];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,5,local+0); /*apply*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2482(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint((eusinteger_t)3L);
	ctx->vsp=local+1;
	w=(*ftab[15])(ctx,1,local+0,&ftab[15],fqv[118]); /*unit-matrix*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2483(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeflt(1.0000000000000000208167e-03);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SCALEVEC(ctx,2,local+0); /*scale*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[59])(ctx,1,local+0,&ftab[59],fqv[581]); /*outer-product-matrix*/
	local[0]= w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)MATTIMES(ctx,2,local+0); /*m**/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2506(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[20];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2507(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO2576,env,argv,local);
	local[1]= env->c.clo.env2[5];
	local[2]= env->c.clo.env2[6];
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,3,local+0); /*mapcar*/
	local[0]= env->c.clo.env2[3];
	ctx->vsp=local+1;
	w=(*ftab[43])(ctx,1,local+0,&ftab[43],fqv[321]); /*functionp*/
	if (w==NIL) goto IF2577;
	local[0]= env->c.clo.env2[3];
	ctx->vsp=local+1;
	w=(pointer)FUNCALL(ctx,1,local+0); /*funcall*/
	local[0]= w;
	goto IF2578;
IF2577:
	local[0]= NIL;
IF2578:
	w = NIL;
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2576(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[20];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2508(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[130];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2512(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= env->c.clo.env2[2];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[142]); /*find*/
	local[0]= w;
	if (w==NIL) goto AND2579;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= env->c.clo.env2[2];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[142]); /*find*/
	local[0]= w;
AND2579:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2513(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= (pointer)get_sym_func(fqv[323]);
	local[1]= env->c.clo.env2[2];
	local[2]= makeint((eusinteger_t)0L);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= env->c.clo.env2[2];
	ctx->vsp=local+5;
	w=(*ftab[32])(ctx,2,local+3,&ftab[32],fqv[213]); /*position*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SUBSEQ(ctx,3,local+1); /*subseq*/
	local[1]= w;
	local[2]= fqv[31];
	ctx->vsp=local+3;
	w=(*ftab[18])(ctx,2,local+1,&ftab[18],fqv[128]); /*send-all*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[26])(ctx,2,local+0,&ftab[26],fqv[196]); /*reduce*/
	local[0]= w;
	local[1]= env->c.clo.env2[4];
	local[2]= argv[0];
	local[3]= env->c.clo.env2[3];
	ctx->vsp=local+4;
	w=(*ftab[32])(ctx,2,local+2,&ftab[32],fqv[213]); /*position*/
	local[2]= w;
	local[3]= local[0];
	local[4]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,4,local+1); /*aset*/
	local[0]= (pointer)get_sym_func(fqv[323]);
	local[1]= env->c.clo.env2[2];
	local[2]= makeint((eusinteger_t)0L);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	local[4]= env->c.clo.env2[2];
	ctx->vsp=local+5;
	w=(*ftab[32])(ctx,2,local+3,&ftab[32],fqv[213]); /*position*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SUBSEQ(ctx,3,local+1); /*subseq*/
	local[1]= w;
	local[2]= fqv[31];
	ctx->vsp=local+3;
	w=(*ftab[18])(ctx,2,local+1,&ftab[18],fqv[128]); /*send-all*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[26])(ctx,2,local+0,&ftab[26],fqv[196]); /*reduce*/
	local[0]= w;
	local[1]= env->c.clo.env2[4];
	local[2]= argv[0];
	local[3]= env->c.clo.env2[3];
	ctx->vsp=local+4;
	w=(*ftab[32])(ctx,2,local+2,&ftab[32],fqv[213]); /*position*/
	local[2]= w;
	local[3]= local[0];
	local[4]= makeflt(-1.0000000000000000000000e+00);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,4,local+1); /*aset*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2517(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= env->c.clo.env2[1];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[142]); /*find*/
	local[0]= w;
	if (w==NIL) goto AND2580;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= env->c.clo.env2[1];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[142]); /*find*/
	local[0]= w;
AND2580:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2521(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeflt(5.0000000000000000000000e-01);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[20];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	local[3]= fqv[20];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[20];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	local[2]= fqv[20];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2528(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env2[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[20];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	local[3]= fqv[20];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)ABS(ctx,1,local+1); /*abs*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*all-child-links*/
static pointer F765all_child_links(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT2583;}
	local[0]= (pointer)get_sym_func(fqv[565]);
ENT2583:
ENT2582:
	if (n>2) maerror();
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO2584,env,argv,local);
	local[2]= argv[0];
	local[3]= fqv[548];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAPCAN(ctx,2,local+1); /*mapcan*/
	local[1]= w;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO2585,env,argv,local);
	local[3]= argv[0];
	local[4]= fqv[548];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MAPCAN(ctx,2,local+2); /*mapcan*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPEND(ctx,2,local+1); /*append*/
	local[0]= w;
BLK2581:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2584(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env2[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)FUNCALL(ctx,2,local+0); /*funcall*/
	if (w==NIL) goto IF2586;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF2587;
IF2586:
	local[0]= NIL;
IF2587:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2585(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env2[0];
	ctx->vsp=local+2;
	w=(pointer)F765all_child_links(ctx,2,local+0); /*all-child-links*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*calc-dif-with-axis*/
static pointer F766calc_dif_with_axis(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2592;}
	local[0]= NIL;
ENT2592:
	if (n>=4) { local[1]=(argv[3]); goto ENT2591;}
	local[1]= NIL;
ENT2591:
	if (n>=5) { local[2]=(argv[4]); goto ENT2590;}
	local[2]= NIL;
ENT2590:
ENT2589:
	if (n>5) maerror();
	local[3]= argv[1];
	local[4]= local[3];
	w = fqv[582];
	if (memq(local[4],w)==NIL) goto IF2594;
	if (local[2]==NIL) goto IF2596;
	local[4]= local[2];
	local[5]= makeint((eusinteger_t)0L);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SETELT(ctx,3,local+4); /*setelt*/
	local[4]= local[2];
	local[5]= makeint((eusinteger_t)1L);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)2L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SETELT(ctx,3,local+4); /*setelt*/
	local[4]= local[2];
	goto IF2597;
IF2596:
	local[4]= argv[0];
	local[5]= makeint((eusinteger_t)1L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= makeint((eusinteger_t)2L);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,2,local+4); /*float-vector*/
	local[4]= w;
IF2597:
	goto IF2595;
IF2594:
	local[4]= local[3];
	w = fqv[583];
	if (memq(local[4],w)==NIL) goto IF2598;
	if (local[2]==NIL) goto IF2600;
	local[4]= local[2];
	local[5]= makeint((eusinteger_t)0L);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SETELT(ctx,3,local+4); /*setelt*/
	local[4]= local[2];
	local[5]= makeint((eusinteger_t)1L);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)2L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SETELT(ctx,3,local+4); /*setelt*/
	local[4]= local[2];
	goto IF2601;
IF2600:
	local[4]= argv[0];
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= makeint((eusinteger_t)2L);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,2,local+4); /*float-vector*/
	local[4]= w;
IF2601:
	goto IF2599;
IF2598:
	local[4]= local[3];
	w = fqv[584];
	if (memq(local[4],w)==NIL) goto IF2602;
	if (local[2]==NIL) goto IF2604;
	local[4]= local[2];
	local[5]= makeint((eusinteger_t)0L);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SETELT(ctx,3,local+4); /*setelt*/
	local[4]= local[2];
	local[5]= makeint((eusinteger_t)1L);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SETELT(ctx,3,local+4); /*setelt*/
	local[4]= local[2];
	goto IF2605;
IF2604:
	local[4]= argv[0];
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,2,local+4); /*float-vector*/
	local[4]= w;
IF2605:
	goto IF2603;
IF2602:
	local[4]= local[3];
	w = fqv[585];
	if (memq(local[4],w)==NIL) goto IF2606;
	if (local[1]==NIL) goto IF2608;
	local[4]= local[1];
	local[5]= makeint((eusinteger_t)0L);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)2L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SETELT(ctx,3,local+4); /*setelt*/
	local[4]= local[1];
	goto IF2609;
IF2608:
	local[4]= argv[0];
	local[5]= makeint((eusinteger_t)2L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,1,local+4); /*float-vector*/
	local[4]= w;
IF2609:
	goto IF2607;
IF2606:
	local[4]= local[3];
	w = fqv[586];
	if (memq(local[4],w)==NIL) goto IF2610;
	if (local[1]==NIL) goto IF2612;
	local[4]= local[1];
	local[5]= makeint((eusinteger_t)0L);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SETELT(ctx,3,local+4); /*setelt*/
	local[4]= local[1];
	goto IF2613;
IF2612:
	local[4]= argv[0];
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,1,local+4); /*float-vector*/
	local[4]= w;
IF2613:
	goto IF2611;
IF2610:
	local[4]= local[3];
	w = fqv[587];
	if (memq(local[4],w)==NIL) goto IF2614;
	if (local[1]==NIL) goto IF2616;
	local[4]= local[1];
	local[5]= makeint((eusinteger_t)0L);
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SETELT(ctx,3,local+4); /*setelt*/
	local[4]= local[1];
	goto IF2617;
IF2616:
	local[4]= argv[0];
	local[5]= makeint((eusinteger_t)1L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,1,local+4); /*float-vector*/
	local[4]= w;
IF2617:
	goto IF2615;
IF2614:
	local[4]= local[3];
	if (fqv[194]!=local[4]) goto IF2618;
	if (local[0]==NIL) goto IF2620;
	local[4]= local[0];
	goto IF2621;
IF2620:
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,0,local+4); /*float-vector*/
	local[4]= w;
IF2621:
	goto IF2619;
IF2618:
	local[4]= local[3];
	w = fqv[588];
	if (memq(local[4],w)==NIL) goto IF2622;
	local[4]= argv[0];
	goto IF2623;
IF2622:
	if (T==NIL) goto IF2624;
	local[4]= argv[0];
	goto IF2625;
IF2624:
	local[4]= NIL;
IF2625:
IF2623:
IF2619:
IF2615:
IF2611:
IF2607:
IF2603:
IF2599:
IF2595:
	w = local[4];
	local[0]= w;
BLK2588:
	ctx->vsp=local; return(local[0]);}

/*calc-target-joint-dimension*/
static pointer F767calc_target_joint_dimension(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint((eusinteger_t)0L);
	local[1]= NIL;
	local[2]= argv[0];
WHL2628:
	if (local[2]==NIL) goto WHX2629;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[0];
	local[4]= local[1];
	local[5]= fqv[31];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[0] = w;
	goto WHL2628;
WHX2629:
	local[3]= NIL;
BLK2630:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK2626:
	ctx->vsp=local; return(local[0]);}

/*calc-joint-angle-min-max-for-limit-calculation*/
static pointer F768calc_joint_angle_min_max_for_limit_calculation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[20];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)VECTORP(ctx,1,local+0); /*vectorp*/
	if (w==NIL) goto CON2634;
	local[0]= argv[2];
	local[1]= makeint((eusinteger_t)0L);
	local[2]= argv[0];
	local[3]= fqv[589];
	local[4]= argv[0];
	local[5]= fqv[20];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SETELT(ctx,3,local+0); /*setelt*/
	local[0]= argv[2];
	local[1]= makeint((eusinteger_t)1L);
	local[2]= argv[0];
	local[3]= fqv[589];
	local[4]= argv[0];
	local[5]= fqv[23];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SETELT(ctx,3,local+0); /*setelt*/
	local[0]= argv[2];
	local[1]= makeint((eusinteger_t)2L);
	local[2]= argv[0];
	local[3]= fqv[589];
	local[4]= argv[0];
	local[5]= fqv[22];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SETELT(ctx,3,local+0); /*setelt*/
	local[0]= w;
	goto CON2633;
CON2634:
	local[0]= argv[2];
	local[1]= makeint((eusinteger_t)0L);
	local[2]= argv[0];
	local[3]= fqv[589];
	local[4]= argv[0];
	local[5]= fqv[20];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SETELT(ctx,3,local+0); /*setelt*/
	local[0]= argv[2];
	local[1]= makeint((eusinteger_t)1L);
	local[2]= argv[0];
	local[3]= fqv[589];
	local[4]= argv[0];
	local[5]= fqv[23];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SETELT(ctx,3,local+0); /*setelt*/
	local[0]= argv[2];
	local[1]= makeint((eusinteger_t)2L);
	local[2]= argv[0];
	local[3]= fqv[589];
	local[4]= argv[0];
	local[5]= fqv[22];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SETELT(ctx,3,local+0); /*setelt*/
	local[0]= w;
	goto CON2633;
CON2635:
	local[0]= NIL;
CON2633:
	w = argv[2];
	local[0]= w;
BLK2632:
	ctx->vsp=local; return(local[0]);}

/*joint-angle-limit-weight*/
static pointer F769joint_angle_limit_weight(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT2638;}
	local[0]= loadglobal(fqv[5]);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F767calc_target_joint_dimension(ctx,1,local+1); /*calc-target-joint-dimension*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,2,local+0); /*instantiate*/
	local[0]= w;
ENT2638:
ENT2637:
	if (n>2) maerror();
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[3]= w;
	local[4]= makeint((eusinteger_t)0L);
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)F767calc_target_joint_dimension(ctx,1,local+5); /*calc-target-joint-dimension*/
	local[5]= w;
WHL2640:
	local[6]= local[4];
	w = local[5];
	if ((eusinteger_t)local[6] >= (eusinteger_t)w) goto WHX2641;
	local[6]= argv[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	local[7]= local[6];
	local[8]= local[2];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)F768calc_joint_angle_min_max_for_limit_calculation(ctx,3,local+7); /*calc-joint-angle-min-max-for-limit-calculation*/
	local[7]= local[3];
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	local[8]= local[3];
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	local[9]= local[3];
	local[10]= makeint((eusinteger_t)2L);
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	local[10]= makeint((eusinteger_t)1L);
	ctx->vsp=local+11;
	w=(*ftab[6])(ctx,1,local+10,&ftab[6],fqv[48]); /*deg2rad*/
	local[10]= w;
	local[11]= local[6];
	local[12]= fqv[20];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)VECTORP(ctx,1,local+11); /*vectorp*/
	if (w==NIL) goto IF2643;
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[2] = w;
	local[11]= local[2];
	local[12]= local[6];
	local[13]= fqv[20];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)LENGTH(ctx,1,local+12); /*length*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)GREQP(ctx,2,local+11); /*>=*/
	if (w==NIL) goto IF2645;
	local[2] = makeint((eusinteger_t)0L);
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[1] = w;
	local[11]= local[1];
	goto IF2646;
IF2645:
	local[11]= NIL;
IF2646:
	goto IF2644;
IF2643:
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[1] = w;
	local[11]= local[1];
IF2644:
	local[11]= local[7];
	local[12]= local[8];
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(*ftab[8])(ctx,3,local+11,&ftab[8],fqv[81]); /*eps=*/
	local[11]= w;
	if (w==NIL) goto AND2649;
	local[11]= local[7];
	local[12]= local[9];
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(*ftab[8])(ctx,3,local+11,&ftab[8],fqv[81]); /*eps=*/
	local[11]= w;
AND2649:
	if (local[11]!=NIL) goto CON2647;
CON2648:
	local[11]= local[7];
	local[12]= local[8];
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(*ftab[8])(ctx,3,local+11,&ftab[8],fqv[81]); /*eps=*/
	if (w==NIL) goto CON2650;
	local[11]= local[8];
	local[12]= local[10];
	ctx->vsp=local+13;
	w=(pointer)MINUS(ctx,2,local+11); /*-*/
	local[7] = w;
	local[11]= local[7];
	goto CON2647;
CON2650:
	local[11]= local[7];
	local[12]= local[9];
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(*ftab[8])(ctx,3,local+11,&ftab[8],fqv[81]); /*eps=*/
	if (w==NIL) goto CON2651;
	local[11]= local[9];
	local[12]= local[10];
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[7] = w;
	local[11]= local[7];
	goto CON2647;
CON2651:
	local[11]= NIL;
CON2647:
	local[11]= local[6];
	local[12]= fqv[3];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	if (fqv[590]==local[11]) goto OR2654;
	local[11]= local[6];
	local[12]= fqv[3];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	if (fqv[591]==local[11]) goto OR2654;
	goto CON2653;
OR2654:
	local[11]= makeflt(0.0000000000000000000000e+00);
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(pointer)NUMEQUAL(ctx,2,local+11); /*=*/
	if (w==NIL) goto CON2656;
	local[11]= local[8];
	local[12]= local[10];
	ctx->vsp=local+13;
	w=(pointer)MINUS(ctx,2,local+11); /*-*/
	local[11]= w;
	goto CON2655;
CON2656:
	local[11]= makeflt(0.0000000000000000000000e+00);
	local[12]= local[9];
	ctx->vsp=local+13;
	w=(pointer)NUMEQUAL(ctx,2,local+11); /*=*/
	if (w==NIL) goto CON2657;
	local[11]= local[9];
	local[12]= local[10];
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[11]= w;
	goto CON2655;
CON2657:
	local[11]= makeflt(0.0000000000000000000000e+00);
	goto CON2655;
CON2658:
	local[11]= NIL;
CON2655:
	local[12]= local[7];
	local[13]= local[11];
	ctx->vsp=local+14;
	w=(pointer)GREATERP(ctx,2,local+12); /*>*/
	if (w==NIL) goto IF2659;
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(pointer)ABS(ctx,1,local+12); /*abs*/
	local[12]= w;
	goto IF2660;
IF2659:
	local[12]= local[9];
	ctx->vsp=local+13;
	w=(pointer)ABS(ctx,1,local+12); /*abs*/
	local[12]= w;
IF2660:
	local[13]= local[0];
	local[14]= local[4];
	local[15]= makeint((eusinteger_t)2L);
	local[16]= local[12];
	ctx->vsp=local+17;
	w=(pointer)TIMES(ctx,2,local+15); /***/
	local[15]= w;
	local[16]= makeint((eusinteger_t)2L);
	ctx->vsp=local+17;
	w=(*ftab[28])(ctx,2,local+15,&ftab[28],fqv[201]); /*expt*/
	local[15]= w;
	local[16]= makeint((eusinteger_t)2L);
	local[17]= local[7];
	local[18]= local[11];
	ctx->vsp=local+19;
	w=(pointer)MINUS(ctx,2,local+17); /*-*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)TIMES(ctx,2,local+16); /***/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)TIMES(ctx,2,local+15); /***/
	local[15]= w;
	local[16]= makeint((eusinteger_t)4L);
	local[17]= local[12];
	local[18]= local[12];
	ctx->vsp=local+19;
	w=(pointer)TIMES(ctx,2,local+17); /***/
	local[17]= w;
	local[18]= local[7];
	local[19]= local[7];
	ctx->vsp=local+20;
	w=(pointer)TIMES(ctx,2,local+18); /***/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)MINUS(ctx,2,local+17); /*-*/
	local[17]= w;
	local[18]= makeint((eusinteger_t)2L);
	ctx->vsp=local+19;
	w=(*ftab[28])(ctx,2,local+17,&ftab[28],fqv[201]); /*expt*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)TIMES(ctx,2,local+16); /***/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)QUOTIENT(ctx,2,local+15); /*/*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)ABS(ctx,1,local+15); /*abs*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)SETELT(ctx,3,local+13); /*setelt*/
	local[11]= w;
	goto CON2652;
CON2653:
	local[11]= local[7];
	local[12]= local[8];
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(*ftab[8])(ctx,3,local+11,&ftab[8],fqv[81]); /*eps=*/
	if (w==NIL) goto CON2661;
	local[11]= local[7];
	local[12]= local[9];
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(*ftab[8])(ctx,3,local+11,&ftab[8],fqv[81]); /*eps=*/
	if (w==NIL) goto CON2661;
	local[11]= local[0];
	local[12]= local[4];
	local[13]= loadglobal(fqv[64]);
	ctx->vsp=local+14;
	w=(pointer)SETELT(ctx,3,local+11); /*setelt*/
	local[11]= w;
	goto CON2652;
CON2661:
	local[11]= local[8];
	local[12]= local[9];
	ctx->vsp=local+13;
	w=(pointer)MINUS(ctx,2,local+11); /*-*/
	local[11]= w;
	local[12]= makeint((eusinteger_t)2L);
	ctx->vsp=local+13;
	w=(*ftab[28])(ctx,2,local+11,&ftab[28],fqv[201]); /*expt*/
	local[11]= w;
	local[12]= makeint((eusinteger_t)2L);
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(pointer)TIMES(ctx,2,local+12); /***/
	local[12]= w;
	local[13]= local[8];
	local[14]= local[9];
	ctx->vsp=local+15;
	w=(pointer)MINUS(ctx,3,local+12); /*-*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	local[12]= makeint((eusinteger_t)4L);
	local[13]= local[8];
	local[14]= local[7];
	ctx->vsp=local+15;
	w=(pointer)MINUS(ctx,2,local+13); /*-*/
	local[13]= w;
	local[14]= makeint((eusinteger_t)2L);
	ctx->vsp=local+15;
	w=(*ftab[28])(ctx,2,local+13,&ftab[28],fqv[201]); /*expt*/
	local[13]= w;
	local[14]= local[7];
	local[15]= local[9];
	ctx->vsp=local+16;
	w=(pointer)MINUS(ctx,2,local+14); /*-*/
	local[14]= w;
	local[15]= makeint((eusinteger_t)2L);
	ctx->vsp=local+16;
	w=(*ftab[28])(ctx,2,local+14,&ftab[28],fqv[201]); /*expt*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)TIMES(ctx,3,local+12); /***/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)QUOTIENT(ctx,2,local+11); /*/*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)ABS(ctx,1,local+11); /*abs*/
	local[11]= w;
	local[12]= local[11];
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(pointer)GREATERP(ctx,2,local+12); /*>*/
	if (w==NIL) goto IF2663;
	local[12]= local[11];
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(pointer)LESSP(ctx,2,local+12); /*<*/
	if (w==NIL) goto IF2663;
	local[11] = makeflt(0.0000000000000000000000e+00);
	local[12]= local[11];
	goto IF2664;
IF2663:
	local[12]= NIL;
IF2664:
	local[12]= local[0];
	local[13]= local[4];
	local[14]= local[11];
	ctx->vsp=local+15;
	w=(pointer)SETELT(ctx,3,local+12); /*setelt*/
	local[11]= w;
	goto CON2652;
CON2662:
	local[11]= NIL;
CON2652:
	w = local[11];
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[4] = w;
	goto WHL2640;
WHX2641:
	local[6]= NIL;
BLK2642:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK2636:
	ctx->vsp=local; return(local[0]);}

/*joint-angle-limit-nspace*/
static pointer F770joint_angle_limit_nspace(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT2667;}
	local[0]= loadglobal(fqv[5]);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F767calc_target_joint_dimension(ctx,1,local+1); /*calc-target-joint-dimension*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,2,local+0); /*instantiate*/
	local[0]= w;
ENT2667:
ENT2666:
	if (n>2) maerror();
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[3]= w;
	local[4]= makeint((eusinteger_t)0L);
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)F767calc_target_joint_dimension(ctx,1,local+5); /*calc-target-joint-dimension*/
	local[5]= w;
WHL2669:
	local[6]= local[4];
	w = local[5];
	if ((eusinteger_t)local[6] >= (eusinteger_t)w) goto WHX2670;
	local[6]= argv[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	local[7]= local[6];
	local[8]= local[2];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)F768calc_joint_angle_min_max_for_limit_calculation(ctx,3,local+7); /*calc-joint-angle-min-max-for-limit-calculation*/
	local[7]= local[3];
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	local[8]= local[3];
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	local[9]= local[3];
	local[10]= makeint((eusinteger_t)2L);
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	local[10]= makeint((eusinteger_t)1L);
	ctx->vsp=local+11;
	w=(*ftab[6])(ctx,1,local+10,&ftab[6],fqv[48]); /*deg2rad*/
	local[10]= w;
	local[11]= local[6];
	local[12]= fqv[20];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)VECTORP(ctx,1,local+11); /*vectorp*/
	if (w==NIL) goto IF2672;
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[2] = w;
	local[11]= local[2];
	local[12]= local[6];
	local[13]= fqv[20];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)LENGTH(ctx,1,local+12); /*length*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)GREQP(ctx,2,local+11); /*>=*/
	if (w==NIL) goto IF2674;
	local[2] = makeint((eusinteger_t)0L);
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[1] = w;
	local[11]= local[1];
	goto IF2675;
IF2674:
	local[11]= NIL;
IF2675:
	goto IF2673;
IF2672:
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[1] = w;
	local[11]= local[1];
IF2673:
	local[11]= local[6];
	local[12]= fqv[3];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	if (fqv[590]==local[11]) goto OR2678;
	local[11]= local[6];
	local[12]= fqv[3];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	if (fqv[591]==local[11]) goto OR2678;
	goto CON2677;
OR2678:
	local[11]= makeflt(0.0000000000000000000000e+00);
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(pointer)NUMEQUAL(ctx,2,local+11); /*=*/
	if (w==NIL) goto CON2680;
	local[11]= local[8];
	local[12]= local[10];
	ctx->vsp=local+13;
	w=(pointer)MINUS(ctx,2,local+11); /*-*/
	local[11]= w;
	goto CON2679;
CON2680:
	local[11]= makeflt(0.0000000000000000000000e+00);
	local[12]= local[9];
	ctx->vsp=local+13;
	w=(pointer)NUMEQUAL(ctx,2,local+11); /*=*/
	if (w==NIL) goto CON2681;
	local[11]= local[9];
	local[12]= local[10];
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[11]= w;
	goto CON2679;
CON2681:
	local[11]= makeflt(0.0000000000000000000000e+00);
	goto CON2679;
CON2682:
	local[11]= NIL;
CON2679:
	local[12]= local[0];
	local[13]= local[4];
	local[14]= local[7];
	local[15]= local[11];
	ctx->vsp=local+16;
	w=(pointer)GREATERP(ctx,2,local+14); /*>*/
	if (w==NIL) goto IF2683;
	local[14]= local[11];
	local[15]= local[7];
	ctx->vsp=local+16;
	w=(pointer)MINUS(ctx,2,local+14); /*-*/
	local[14]= w;
	local[15]= local[8];
	local[16]= local[11];
	ctx->vsp=local+17;
	w=(pointer)MINUS(ctx,2,local+15); /*-*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)QUOTIENT(ctx,2,local+14); /*/*/
	local[14]= w;
	goto IF2684;
IF2683:
	local[14]= local[11];
	local[15]= local[7];
	ctx->vsp=local+16;
	w=(pointer)MINUS(ctx,2,local+14); /*-*/
	local[14]= w;
	local[15]= makeflt(5.0000000000000000000000e+00);
	local[16]= local[11];
	local[17]= local[9];
	ctx->vsp=local+18;
	w=(pointer)MINUS(ctx,2,local+16); /*-*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)TIMES(ctx,2,local+15); /***/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)QUOTIENT(ctx,2,local+14); /*/*/
	local[14]= w;
IF2684:
	ctx->vsp=local+15;
	w=(pointer)SETELT(ctx,3,local+12); /*setelt*/
	local[11]= w;
	goto CON2676;
CON2677:
	local[11]= local[0];
	local[12]= local[4];
	local[13]= local[8];
	local[14]= local[9];
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,2,local+13); /*+*/
	local[13]= w;
	local[14]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+15;
	w=(pointer)QUOTIENT(ctx,2,local+13); /*/*/
	local[13]= w;
	local[14]= local[7];
	ctx->vsp=local+15;
	w=(pointer)MINUS(ctx,2,local+13); /*-*/
	local[13]= w;
	local[14]= local[8];
	local[15]= local[9];
	ctx->vsp=local+16;
	w=(pointer)MINUS(ctx,2,local+14); /*-*/
	local[14]= w;
	local[15]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+16;
	w=(pointer)QUOTIENT(ctx,2,local+14); /*/*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)QUOTIENT(ctx,2,local+13); /*/*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SETELT(ctx,3,local+11); /*setelt*/
	local[11]= w;
	goto CON2676;
CON2685:
	local[11]= NIL;
CON2676:
	local[11]= local[0];
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[60])(ctx,1,local+11,&ftab[60],fqv[592]); /*plusp*/
	if (w==NIL) goto IF2686;
	local[11]= makeint((eusinteger_t)1L);
	goto IF2687;
IF2686:
	local[11]= makeint((eusinteger_t)-1L);
IF2687:
	local[12]= local[0];
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[12]= w;
	local[13]= makeint((eusinteger_t)2L);
	ctx->vsp=local+14;
	w=(*ftab[28])(ctx,2,local+12,&ftab[28],fqv[201]); /*expt*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	local[12]= local[11];
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(pointer)GREATERP(ctx,2,local+12); /*>*/
	if (w==NIL) goto AND2691;
	local[12]= local[11];
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(pointer)LESSP(ctx,2,local+12); /*<*/
	if (w==NIL) goto AND2691;
	goto OR2690;
AND2691:
	local[12]= local[11];
	if (loadglobal(fqv[64])==local[12]) goto OR2690;
	local[12]= local[11];
	if (loadglobal(fqv[63])==local[12]) goto OR2690;
	goto IF2688;
OR2690:
	local[11] = makeflt(0.0000000000000000000000e+00);
	local[12]= local[11];
	goto IF2689;
IF2688:
	local[12]= NIL;
IF2689:
	local[12]= local[0];
	local[13]= local[4];
	local[14]= local[11];
	ctx->vsp=local+15;
	w=(pointer)SETELT(ctx,3,local+12); /*setelt*/
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[4] = w;
	goto WHL2669;
WHX2670:
	local[6]= NIL;
BLK2671:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK2665:
	ctx->vsp=local; return(local[0]);}

/*calc-jacobian-from-link-list-including-robot-and-obj-virtual-joint*/
static pointer F771calc_jacobian_from_link_list_including_robot_and_obj_virtual_joint(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[593], &argv[4], n-4, local+0, 0);
	if (n & (1<<0)) goto KEY2693;
	local[0] = fqv[594];
KEY2693:
	if (n & (1<<1)) goto KEY2694;
	local[1] = fqv[595];
KEY2694:
	if (n & (1<<2)) goto KEY2695;
	local[3]= argv[3];
	local[4]= fqv[210];
	local[5]= local[0];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	local[4]= argv[3];
	local[5]= fqv[211];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[23])(ctx,2,local+3,&ftab[23],fqv[166]); /*make-matrix*/
	local[2] = w;
KEY2695:
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO2696,env,argv,local);
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	local[4]= NIL;
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO2697,env,argv,local);
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)MAPCAR(ctx,2,local+5); /*mapcar*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[54])(ctx,2,local+4,&ftab[54],fqv[549]); /*remove*/
	local[4]= w;
	local[5]= argv[3];
	local[6]= fqv[211];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	local[6]= argv[3];
	local[7]= fqv[300];
	local[8]= local[4];
	local[9]= fqv[596];
	local[10]= local[5];
	local[11]= fqv[273];
	local[12]= local[2];
	local[13]= fqv[597];
	local[14]= argv[1];
	local[15]= fqv[301];
	local[16]= argv[2];
	local[17]= fqv[410];
	local[18]= local[0];
	local[19]= fqv[336];
	local[20]= local[1];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,15,local+6); /*send*/
	local[6]= argv[3];
	local[7]= fqv[300];
	local[8]= local[3];
	local[9]= fqv[301];
	local[10]= argv[1];
	local[11]= fqv[273];
	local[12]= local[2];
	local[13]= fqv[410];
	local[14]= local[0];
	local[15]= fqv[336];
	local[16]= local[1];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,11,local+6); /*send*/
	local[6]= makeint((eusinteger_t)0L);
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(*ftab[29])(ctx,1,local+7,&ftab[29],fqv[204]); /*array-dimensions*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
WHL2699:
	local[8]= local[6];
	w = local[7];
	if ((eusinteger_t)local[8] >= (eusinteger_t)w) goto WHX2700;
	local[8]= makeint((eusinteger_t)0L);
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(*ftab[29])(ctx,1,local+9,&ftab[29],fqv[204]); /*array-dimensions*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,2,local+9); /*-*/
	local[9]= w;
WHL2703:
	local[10]= local[8];
	w = local[9];
	if ((eusinteger_t)local[10] >= (eusinteger_t)w) goto WHX2704;
	local[10]= local[2];
	local[11]= local[6];
	local[12]= local[5];
	local[13]= local[8];
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,2,local+12); /*+*/
	local[12]= w;
	local[13]= makeflt(-1.0000000000000000000000e+00);
	local[14]= local[2];
	local[15]= local[6];
	local[16]= local[5];
	local[17]= local[8];
	ctx->vsp=local+18;
	w=(pointer)PLUS(ctx,2,local+16); /*+*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)AREF(ctx,3,local+14); /*aref*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)TIMES(ctx,2,local+13); /***/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)ASET(ctx,4,local+10); /*aset*/
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[8] = w;
	goto WHL2703;
WHX2704:
	local[10]= NIL;
BLK2705:
	w = NIL;
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[6] = w;
	goto WHL2699;
WHX2700:
	local[8]= NIL;
BLK2701:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK2692:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2696(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO2706,env,argv,local);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[55])(ctx,2,local+0,&ftab[55],fqv[560]); /*remove-if-not*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2706(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env0->c.clo.env1[3];
	local[2]= fqv[136];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[124]); /*member*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2697(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO2707,env,argv,local);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[61])(ctx,2,local+0,&ftab[61],fqv[598]); /*remove-if*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2707(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env0->c.clo.env1[3];
	local[2]= fqv[136];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[124]); /*member*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*append-obj-virtual-joint*/
static pointer F772append_obj_virtual_joint(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[599], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY2709;
	local[0] = loadglobal(fqv[600]);
KEY2709:
	if (n & (1<<1)) goto KEY2710;
	local[1] = NIL;
KEY2710:
	if (n & (1<<2)) goto KEY2711;
	local[2] = NIL;
KEY2711:
	if (n & (1<<3)) goto KEY2712;
	local[3] = NIL;
KEY2712:
	if (n & (1<<4)) goto KEY2713;
	local[4] = NIL;
KEY2713:
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,FLET2714,env,argv,local);
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO2715,env,argv,local);
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[6]= w;
	if (local[2]==NIL) goto IF2716;
	local[7]= local[2];
	goto IF2717;
IF2716:
	local[7]= fqv[601];
	if (local[3]==NIL) goto IF2718;
	local[8]= local[3];
	goto IF2719;
IF2718:
	local[8]= makeint((eusinteger_t)1L);
	local[9]= argv[1];
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	if (w!=local[8]) goto IF2720;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= fqv[153];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	goto IF2721;
IF2720:
	local[8]= (pointer)get_sym_func(fqv[602]);
	local[9]= makeflt(5.0000000000000000000000e-01);
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)APPLY(ctx,3,local+8); /*apply*/
	local[8]= w;
IF2721:
IF2719:
	w = local[5];
	ctx->vsp=local+9;
	w=FLET2714(ctx,2,local+7,w);
	local[7]= w;
IF2717:
	local[8]= fqv[603];
	if (local[4]==NIL) goto IF2722;
	local[9]= local[4];
	goto IF2723;
IF2722:
	local[9]= local[7];
	local[10]= fqv[153];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
IF2723:
	w = local[5];
	ctx->vsp=local+10;
	w=FLET2714(ctx,2,local+8,w);
	local[8]= w;
	local[9]= NIL;
	local[10]= local[6];
WHL2725:
	if (local[10]==NIL) goto WHX2726;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	local[11]= local[8];
	local[12]= fqv[299];
	local[13]= local[9];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	goto WHL2725;
WHX2726:
	local[11]= NIL;
BLK2727:
	w = NIL;
	local[9]= local[7];
	local[10]= fqv[299];
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= local[8];
	local[10]= loadglobal(fqv[214]);
	local[11]= fqv[131];
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)INSTANTIATE(ctx,1,local+12); /*instantiate*/
	local[12]= w;
	local[13]= (pointer)get_sym_func(fqv[289]);
	local[14]= local[12];
	local[15]= fqv[36];
	local[16]= fqv[130];
	local[17]= local[8];
	local[18]= fqv[133];
	local[19]= local[7];
	local[20]= local[1];
	ctx->vsp=local+21;
	w=(pointer)APPLY(ctx,8,local+13); /*apply*/
	w = local[12];
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)SENDMESSAGE(ctx,4,local+9); /*send-message*/
	local[9]= local[8];
	local[10]= fqv[132];
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= local[7];
	local[10]= fqv[134];
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	ctx->vsp=local+9;
	local[9]= makeclosure(codevec,quotevec,CLO2730,env,argv,local);
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)MAPCAR(ctx,2,local+9); /*mapcar*/
	local[9]= w;
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,2,local+9); /*list*/
	local[0]= w;
BLK2708:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET2714(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[214]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[36];
	local[3]= fqv[120];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(*ftab[40])(ctx,2,local+3,&ftab[40],fqv[298]); /*make-cascoords*/
	local[3]= w;
	local[4]= fqv[127];
	local[5]= makeint((eusinteger_t)10L);
	local[6]= makeint((eusinteger_t)10L);
	local[7]= makeint((eusinteger_t)10L);
	ctx->vsp=local+8;
	w=(*ftab[62])(ctx,3,local+5,&ftab[62],fqv[604]); /*make-cube*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	local[5]= w;
	local[6]= fqv[3];
	local[7]= argv[0];
	local[8]= fqv[274];
	local[9]= makeint((eusinteger_t)0L);
	local[10]= fqv[258];
	local[11]= fqv[605];
	local[12]= fqv[606];
	local[13]= makeint((eusinteger_t)3L);
	local[14]= makeint((eusinteger_t)3L);
	ctx->vsp=local+15;
	w=(*ftab[23])(ctx,2,local+13,&ftab[23],fqv[166]); /*make-matrix*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,13,local+1); /*send*/
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2715(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[120];
	local[1]= argv[0];
	local[2]= fqv[153];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[40])(ctx,2,local+0,&ftab[40],fqv[298]); /*make-cascoords*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2730(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env2[8];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*append-multiple-obj-virtual-joint*/
static pointer F773append_multiple_obj_virtual_joint(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[607], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY2733;
	local[0] = fqv[608];
KEY2733:
	if (n & (1<<1)) goto KEY2734;
	local[1] = fqv[609];
KEY2734:
	if (n & (1<<2)) goto KEY2735;
	local[2] = NIL;
KEY2735:
	if (n & (1<<3)) goto KEY2736;
	local[3] = NIL;
KEY2736:
	if (n & (1<<4)) goto KEY2737;
	local[4] = NIL;
KEY2737:
	local[5]= argv[0];
	local[6]= local[2];
	local[7]= local[3];
	local[8]= NIL;
	ctx->vsp=local+9;
	local[9]= makeclosure(codevec,quotevec,CLO2738,env,argv,local);
	local[10]= local[0];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)MAPCAR(ctx,3,local+9); /*mapcar*/
	w = local[8];
	local[0]= w;
BLK2732:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2738(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= env->c.clo.env2[5];
	local[1]= env->c.clo.env1[1];
	local[2]= fqv[610];
	local[3]= argv[0];
	local[4]= fqv[611];
	local[5]= argv[1];
	local[6]= fqv[612];
	local[7]= env->c.clo.env2[6];
	local[8]= fqv[613];
	local[9]= env->c.clo.env2[7];
	local[10]= fqv[614];
	local[11]= env->c.clo.env2[4];
	ctx->vsp=local+12;
	w=(pointer)F772append_obj_virtual_joint(ctx,12,local+0); /*append-obj-virtual-joint*/
	env->c.clo.env2[8] = w;
	w=env->c.clo.env2[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	env->c.clo.env2[5] = (w)->c.cons.car;
	w=env->c.clo.env2[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	w=(*ftab[38])(ctx,1,local+0,&ftab[38],fqv[292]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	env->c.clo.env2[6] = (w)->c.cons.car;
	w = env->c.clo.env2[6];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*with-difference-position-and-rotation*/
static pointer F2739(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST2741:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+1;
	w=(pointer)GENSYM(ctx,0,local+1); /*gensym*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,0,local+2); /*gensym*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)GENSYM(ctx,0,local+3); /*gensym*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)GENSYM(ctx,0,local+4); /*gensym*/
	local[4]= w;
	local[5]= fqv[528];
	local[6]= local[1];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= local[2];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(*ftab[63])(ctx,1,local+8,&ftab[63],fqv[615]); /*cadddr*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= local[4];
	local[9]= fqv[336];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(*ftab[16])(ctx,2,local+9,&ftab[16],fqv[124]); /*member*/
	if (w==NIL) goto IF2742;
	local[9]= fqv[336];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(*ftab[16])(ctx,2,local+9,&ftab[16],fqv[124]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	goto IF2743;
IF2742:
	local[9]= T;
IF2743:
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= local[3];
	local[10]= fqv[410];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(*ftab[16])(ctx,2,local+10,&ftab[16],fqv[124]); /*member*/
	if (w==NIL) goto IF2744;
	local[10]= fqv[410];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(*ftab[16])(ctx,2,local+10,&ftab[16],fqv[124]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	goto IF2745;
IF2744:
	local[10]= T;
IF2745:
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[528];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= fqv[289];
	local[10]= local[1];
	local[11]= fqv[570];
	local[12]= local[2];
	local[13]= fqv[336];
	local[14]= local[4];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= fqv[289];
	local[11]= local[1];
	local[12]= fqv[571];
	local[13]= local[2];
	local[14]= fqv[410];
	local[15]= local[3];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= local[0];
	local[10]= NIL;
	ctx->vsp=local+11;
	w=(pointer)APPEND(ctx,2,local+9); /*append*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	local[0]= w;
BLK2740:
	ctx->vsp=local; return(local[0]);}

/*with-difference-positions-and-rotations*/
static pointer F2746(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST2748:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+1;
	w=(pointer)GENSYM(ctx,0,local+1); /*gensym*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,0,local+2); /*gensym*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)GENSYM(ctx,0,local+3); /*gensym*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)GENSYM(ctx,0,local+4); /*gensym*/
	local[4]= w;
	local[5]= fqv[576];
	local[6]= local[1];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= local[2];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(*ftab[63])(ctx,1,local+8,&ftab[63],fqv[615]); /*cadddr*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= local[4];
	local[9]= fqv[616];
	local[10]= fqv[336];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(*ftab[16])(ctx,2,local+10,&ftab[16],fqv[124]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= fqv[336];
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(*ftab[16])(ctx,2,local+11,&ftab[16],fqv[124]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= fqv[208];
	local[13]= fqv[427];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	local[14]= fqv[209];
	local[15]= fqv[617];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= local[3];
	local[10]= fqv[616];
	local[11]= fqv[410];
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(*ftab[16])(ctx,2,local+11,&ftab[16],fqv[124]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= fqv[410];
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(*ftab[16])(ctx,2,local+12,&ftab[16],fqv[124]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= fqv[208];
	local[14]= fqv[427];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	local[15]= fqv[209];
	local[16]= fqv[617];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[528];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= fqv[618];
	local[10]= fqv[517];
	local[11]= fqv[518];
	local[12]= fqv[619];
	local[13]= fqv[620];
	local[14]= fqv[621];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[289];
	local[14]= fqv[619];
	local[15]= fqv[570];
	local[16]= fqv[620];
	local[17]= fqv[336];
	local[18]= fqv[621];
	ctx->vsp=local+19;
	w=(pointer)LIST(ctx,1,local+18); /*list*/
	ctx->vsp=local+18;
	w = cons(ctx,local[17],w);
	ctx->vsp=local+17;
	w = cons(ctx,local[16],w);
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= local[1];
	local[12]= local[2];
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= fqv[618];
	local[11]= fqv[517];
	local[12]= fqv[518];
	local[13]= fqv[619];
	local[14]= fqv[620];
	local[15]= fqv[622];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	local[14]= fqv[289];
	local[15]= fqv[619];
	local[16]= fqv[571];
	local[17]= fqv[620];
	local[18]= fqv[410];
	local[19]= fqv[622];
	ctx->vsp=local+20;
	w=(pointer)LIST(ctx,1,local+19); /*list*/
	ctx->vsp=local+19;
	w = cons(ctx,local[18],w);
	ctx->vsp=local+18;
	w = cons(ctx,local[17],w);
	ctx->vsp=local+17;
	w = cons(ctx,local[16],w);
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= local[1];
	local[13]= local[2];
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= local[0];
	local[10]= NIL;
	ctx->vsp=local+11;
	w=(pointer)APPEND(ctx,2,local+9); /*append*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	local[0]= w;
BLK2747:
	ctx->vsp=local; return(local[0]);}

/*with-move-target-link-list*/
static pointer F2749(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST2751:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+1;
	w=(pointer)GENSYM(ctx,0,local+1); /*gensym*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,0,local+2); /*gensym*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)GENSYM(ctx,0,local+3); /*gensym*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)GENSYM(ctx,0,local+4); /*gensym*/
	local[4]= w;
	local[5]= fqv[576];
	local[6]= local[3];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= local[4];
	local[8]= fqv[616];
	local[9]= fqv[623];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(*ftab[63])(ctx,1,local+10,&ftab[63],fqv[615]); /*cadddr*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[522];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(*ftab[63])(ctx,1,local+11,&ftab[63],fqv[615]); /*cadddr*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(*ftab[63])(ctx,1,local+11,&ftab[63],fqv[615]); /*cadddr*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= local[1];
	local[9]= fqv[624];
	local[10]= fqv[301];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(*ftab[16])(ctx,2,local+10,&ftab[16],fqv[124]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= fqv[616];
	local[12]= fqv[623];
	local[13]= fqv[301];
	local[14]= argv[0];
	ctx->vsp=local+15;
	w=(*ftab[16])(ctx,2,local+13,&ftab[16],fqv[124]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[522];
	local[14]= fqv[301];
	local[15]= argv[0];
	ctx->vsp=local+16;
	w=(*ftab[16])(ctx,2,local+14,&ftab[16],fqv[124]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	local[14]= fqv[301];
	local[15]= argv[0];
	ctx->vsp=local+16;
	w=(*ftab[16])(ctx,2,local+14,&ftab[16],fqv[124]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[617];
	local[12]= fqv[618];
	local[13]= fqv[517];
	local[14]= fqv[518];
	local[15]= fqv[625];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	local[15]= w;
	local[16]= fqv[289];
	local[17]= local[3];
	local[18]= fqv[625];
	local[19]= fqv[626];
	ctx->vsp=local+20;
	w=(pointer)LIST(ctx,1,local+19); /*list*/
	ctx->vsp=local+19;
	w = cons(ctx,local[18],w);
	ctx->vsp=local+18;
	w = cons(ctx,local[17],w);
	ctx->vsp=local+17;
	local[16]= cons(ctx,local[16],w);
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	local[14]= local[4];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= local[2];
	local[10]= fqv[618];
	local[11]= fqv[517];
	local[12]= fqv[518];
	local[13]= fqv[627];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	local[13]= w;
	local[14]= fqv[289];
	local[15]= local[3];
	local[16]= fqv[261];
	local[17]= fqv[289];
	local[18]= fqv[627];
	local[19]= fqv[215];
	ctx->vsp=local+20;
	w=(pointer)LIST(ctx,1,local+19); /*list*/
	ctx->vsp=local+19;
	w = cons(ctx,local[18],w);
	ctx->vsp=local+18;
	local[17]= cons(ctx,local[17],w);
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,1,local+17); /*list*/
	ctx->vsp=local+17;
	w = cons(ctx,local[16],w);
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[528];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= local[0];
	local[10]= NIL;
	ctx->vsp=local+11;
	w=(pointer)APPEND(ctx,2,local+9); /*append*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	local[0]= w;
BLK2750:
	ctx->vsp=local; return(local[0]);}

/*with-append-root-joint*/
static pointer F2752(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST2754:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+1;
	w=(pointer)GENSYM(ctx,0,local+1); /*gensym*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,0,local+2); /*gensym*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)GENSYM(ctx,0,local+3); /*gensym*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)GENSYM(ctx,0,local+4); /*gensym*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)GENSYM(ctx,0,local+5); /*gensym*/
	local[5]= w;
	local[6]= fqv[513];
	local[7]= fqv[528];
	local[8]= local[1];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= local[2];
	local[10]= fqv[616];
	local[11]= fqv[566];
	local[12]= fqv[517];
	local[13]= fqv[628];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= fqv[522];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= local[5];
	local[11]= fqv[611];
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(*ftab[16])(ctx,2,local+11,&ftab[16],fqv[124]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[528];
	local[10]= local[3];
	local[11]= fqv[512];
	local[12]= fqv[214];
	local[13]= fqv[36];
	local[14]= fqv[298];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	local[14]= w;
	local[15]= fqv[127];
	local[16]= fqv[522];
	local[17]= fqv[604];
	local[18]= fqv[629];
	local[19]= fqv[630];
	local[20]= fqv[631];
	ctx->vsp=local+21;
	w=(pointer)LIST(ctx,1,local+20); /*list*/
	ctx->vsp=local+20;
	w = cons(ctx,local[19],w);
	ctx->vsp=local+19;
	w = cons(ctx,local[18],w);
	ctx->vsp=local+18;
	local[17]= cons(ctx,local[17],w);
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,1,local+17); /*list*/
	ctx->vsp=local+17;
	local[16]= cons(ctx,local[16],w);
	local[17]= fqv[3];
	local[18]= fqv[460];
	local[19]= fqv[632];
	ctx->vsp=local+20;
	w=(pointer)LIST(ctx,1,local+19); /*list*/
	ctx->vsp=local+19;
	local[18]= cons(ctx,local[18],w);
	local[19]= fqv[274];
	local[20]= fqv[633];
	local[21]= fqv[258];
	local[22]= fqv[5];
	local[23]= fqv[634];
	local[24]= fqv[635];
	local[25]= fqv[636];
	ctx->vsp=local+26;
	w=(pointer)LIST(ctx,1,local+25); /*list*/
	ctx->vsp=local+25;
	w = cons(ctx,local[24],w);
	ctx->vsp=local+24;
	w = cons(ctx,local[23],w);
	ctx->vsp=local+23;
	local[22]= cons(ctx,local[22],w);
	local[23]= fqv[606];
	local[24]= fqv[166];
	local[25]= fqv[637];
	local[26]= fqv[638];
	ctx->vsp=local+27;
	w=(pointer)LIST(ctx,1,local+26); /*list*/
	ctx->vsp=local+26;
	w = cons(ctx,local[25],w);
	ctx->vsp=local+25;
	local[24]= cons(ctx,local[24],w);
	ctx->vsp=local+25;
	w=(pointer)LIST(ctx,1,local+24); /*list*/
	ctx->vsp=local+24;
	w = cons(ctx,local[23],w);
	ctx->vsp=local+23;
	w = cons(ctx,local[22],w);
	ctx->vsp=local+22;
	w = cons(ctx,local[21],w);
	ctx->vsp=local+21;
	w = cons(ctx,local[20],w);
	ctx->vsp=local+20;
	w = cons(ctx,local[19],w);
	ctx->vsp=local+19;
	w = cons(ctx,local[18],w);
	ctx->vsp=local+18;
	w = cons(ctx,local[17],w);
	ctx->vsp=local+17;
	w = cons(ctx,local[16],w);
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= local[4];
	local[12]= fqv[639];
	local[13]= fqv[289];
	local[14]= local[1];
	local[15]= fqv[136];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[34];
	local[12]= local[4];
	local[13]= fqv[214];
	local[14]= fqv[131];
	local[15]= fqv[640];
	local[16]= fqv[610];
	local[17]= argv[0];
	ctx->vsp=local+18;
	w=(*ftab[16])(ctx,2,local+16,&ftab[16],fqv[124]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	if (local[16]!=NIL) goto OR2755;
	local[16]= loadglobal(fqv[600]);
OR2755:
	local[17]= fqv[36];
	local[18]= fqv[130];
	local[19]= local[1];
	local[20]= fqv[133];
	local[21]= local[3];
	local[22]= local[5];
	ctx->vsp=local+23;
	w=(pointer)LIST(ctx,1,local+22); /*list*/
	ctx->vsp=local+22;
	w = cons(ctx,local[21],w);
	ctx->vsp=local+21;
	w = cons(ctx,local[20],w);
	ctx->vsp=local+20;
	w = cons(ctx,local[19],w);
	ctx->vsp=local+19;
	w = cons(ctx,local[18],w);
	ctx->vsp=local+18;
	w = cons(ctx,local[17],w);
	ctx->vsp=local+17;
	w = cons(ctx,local[16],w);
	ctx->vsp=local+16;
	local[15]= cons(ctx,local[15],w);
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[289];
	local[13]= local[4];
	local[14]= fqv[132];
	local[15]= local[3];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[289];
	local[14]= local[3];
	local[15]= fqv[134];
	local[16]= local[4];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	local[14]= fqv[641];
	local[15]= fqv[528];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	local[17]= fqv[618];
	local[18]= fqv[517];
	local[19]= fqv[518];
	local[20]= fqv[642];
	ctx->vsp=local+21;
	w=(pointer)LIST(ctx,1,local+20); /*list*/
	local[20]= w;
	local[21]= fqv[88];
	local[22]= local[4];
	local[23]= fqv[642];
	ctx->vsp=local+24;
	w=(pointer)LIST(ctx,1,local+23); /*list*/
	ctx->vsp=local+23;
	w = cons(ctx,local[22],w);
	ctx->vsp=local+22;
	local[21]= cons(ctx,local[21],w);
	ctx->vsp=local+22;
	w=(pointer)LIST(ctx,1,local+21); /*list*/
	ctx->vsp=local+21;
	w = cons(ctx,local[20],w);
	ctx->vsp=local+20;
	local[19]= cons(ctx,local[19],w);
	ctx->vsp=local+20;
	w=(pointer)LIST(ctx,1,local+19); /*list*/
	ctx->vsp=local+19;
	local[18]= cons(ctx,local[18],w);
	local[19]= local[2];
	ctx->vsp=local+20;
	w=(pointer)LIST(ctx,1,local+19); /*list*/
	ctx->vsp=local+19;
	w = cons(ctx,local[18],w);
	ctx->vsp=local+18;
	local[17]= cons(ctx,local[17],w);
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,1,local+17); /*list*/
	ctx->vsp=local+17;
	local[16]= cons(ctx,local[16],w);
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	local[16]= w;
	local[17]= local[0];
	local[18]= NIL;
	ctx->vsp=local+19;
	w=(pointer)APPEND(ctx,2,local+17); /*append*/
	ctx->vsp=local+17;
	w = cons(ctx,local[16],w);
	ctx->vsp=local+16;
	local[15]= cons(ctx,local[15],w);
	local[16]= fqv[289];
	local[17]= local[4];
	local[18]= fqv[643];
	ctx->vsp=local+19;
	w=(pointer)LIST(ctx,1,local+18); /*list*/
	ctx->vsp=local+18;
	w = cons(ctx,local[17],w);
	ctx->vsp=local+17;
	local[16]= cons(ctx,local[16],w);
	local[17]= fqv[289];
	local[18]= local[4];
	local[19]= fqv[644];
	ctx->vsp=local+20;
	w=(pointer)LIST(ctx,1,local+19); /*list*/
	ctx->vsp=local+19;
	w = cons(ctx,local[18],w);
	ctx->vsp=local+18;
	local[17]= cons(ctx,local[17],w);
	local[18]= fqv[289];
	local[19]= local[3];
	local[20]= fqv[645];
	local[21]= local[4];
	ctx->vsp=local+22;
	w=(pointer)LIST(ctx,1,local+21); /*list*/
	ctx->vsp=local+21;
	w = cons(ctx,local[20],w);
	ctx->vsp=local+20;
	w = cons(ctx,local[19],w);
	ctx->vsp=local+19;
	local[18]= cons(ctx,local[18],w);
	ctx->vsp=local+19;
	w=(pointer)LIST(ctx,1,local+18); /*list*/
	ctx->vsp=local+18;
	w = cons(ctx,local[17],w);
	ctx->vsp=local+17;
	w = cons(ctx,local[16],w);
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	local[0]= w;
BLK2753:
	ctx->vsp=local; return(local[0]);}

/*with-assoc-move-target*/
static pointer F2756(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST2758:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+1;
	w=(pointer)GENSYM(ctx,0,local+1); /*gensym*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,0,local+2); /*gensym*/
	local[2]= w;
	local[3]= fqv[528];
	local[4]= local[1];
	local[5]= fqv[616];
	local[6]= fqv[623];
	local[7]= fqv[301];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(*ftab[16])(ctx,2,local+7,&ftab[16],fqv[124]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[522];
	local[8]= fqv[301];
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(*ftab[16])(ctx,2,local+8,&ftab[16],fqv[124]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[301];
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(*ftab[16])(ctx,2,local+8,&ftab[16],fqv[124]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= local[2];
	local[6]= fqv[616];
	local[7]= fqv[623];
	local[8]= fqv[133];
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(*ftab[16])(ctx,2,local+8,&ftab[16],fqv[124]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[522];
	local[9]= fqv[133];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(*ftab[16])(ctx,2,local+9,&ftab[16],fqv[124]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[133];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(*ftab[16])(ctx,2,local+9,&ftab[16],fqv[124]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[458];
	local[6]= local[1];
	local[7]= fqv[618];
	local[8]= fqv[517];
	local[9]= fqv[518];
	local[10]= fqv[646];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	local[10]= w;
	local[11]= fqv[298];
	local[12]= fqv[120];
	local[13]= fqv[289];
	local[14]= fqv[646];
	local[15]= fqv[153];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[618];
	local[7]= fqv[517];
	local[8]= fqv[518];
	local[9]= fqv[647];
	local[10]= fqv[646];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[289];
	local[11]= fqv[647];
	local[12]= fqv[299];
	local[13]= fqv[646];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
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
	local[7]= cons(ctx,local[7],w);
	local[8]= local[2];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[641];
	local[8]= fqv[528];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[9]= w;
	local[10]= local[0];
	local[11]= NIL;
	ctx->vsp=local+12;
	w=(pointer)APPEND(ctx,2,local+10); /*append*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[618];
	local[10]= fqv[517];
	local[11]= fqv[518];
	local[12]= fqv[648];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	local[12]= w;
	local[13]= fqv[289];
	local[14]= fqv[289];
	local[15]= fqv[648];
	local[16]= fqv[215];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	local[15]= fqv[302];
	local[16]= fqv[648];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	local[0]= w;
BLK2757:
	ctx->vsp=local; return(local[0]);}

/*eusmodel-validity-check-one*/
static pointer F774eusmodel_validity_check_one(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[136];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
WHL2760:
	local[1]= local[0];
	local[2]= fqv[133];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (w==NIL) goto WHX2761;
	local[1]= loadglobal(fqv[176]);
	local[2]= NIL;
	local[3]= fqv[649];
	local[4]= local[0];
	local[5]= local[0];
	local[6]= fqv[133];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,4,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,2,local+1); /*format*/
	local[1]= loadglobal(fqv[176]);
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,1,local+1); /*finish-output*/
	local[1]= fqv[650];
	ctx->vsp=local+2;
	w=(*ftab[64])(ctx,1,local+1,&ftab[64],fqv[651]); /*reploop*/
	goto WHL2760;
WHX2761:
	local[1]= NIL;
BLK2762:
WHL2763:
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[215];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)EQUAL(ctx,2,local+1); /*equal*/
	if (w!=NIL) goto WHX2764;
	local[1]= loadglobal(fqv[176]);
	local[2]= NIL;
	local[3]= fqv[652];
	local[4]= local[0];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,4,local+2); /*format*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,2,local+1); /*format*/
	local[1]= loadglobal(fqv[176]);
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,1,local+1); /*finish-output*/
	local[1]= fqv[653];
	ctx->vsp=local+2;
	w=(*ftab[64])(ctx,1,local+1,&ftab[64],fqv[651]); /*reploop*/
	goto WHL2763;
WHX2764:
	local[1]= NIL;
BLK2765:
	w = local[1];
	local[0]= (pointer)get_sym_func(fqv[654]);
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO2766,env,argv,local);
	local[2]= argv[0];
	local[3]= fqv[655];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[55])(ctx,2,local+1,&ftab[55],fqv[560]); /*remove-if-not*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[656];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[47])(ctx,1,local+0,&ftab[47],fqv[446]); /*remove-duplicates*/
	local[0]= w;
	local[1]= (pointer)get_sym_func(fqv[654]);
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO2767,env,argv,local);
	local[3]= argv[0];
	local[4]= fqv[655];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[55])(ctx,2,local+2,&ftab[55],fqv[560]); /*remove-if-not*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[136];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPEND(ctx,2,local+1); /*append*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[47])(ctx,1,local+1,&ftab[47],fqv[446]); /*remove-duplicates*/
	local[1]= w;
WHL2768:
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	w = makeint((eusinteger_t)1L);
#if sun4 || vax || mips || alpha || Linux
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[2]= (pointer)((eusinteger_t)local[2] + (eusinteger_t)w);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	if (w==local[2]) goto WHX2769;
	local[2]= loadglobal(fqv[176]);
	local[3]= NIL;
	local[4]= fqv[657];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,4,local+3); /*format*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,2,local+2); /*format*/
	local[2]= loadglobal(fqv[176]);
	ctx->vsp=local+3;
	w=(pointer)FINOUT(ctx,1,local+2); /*finish-output*/
	local[2]= fqv[658];
	ctx->vsp=local+3;
	w=(*ftab[64])(ctx,1,local+2,&ftab[64],fqv[651]); /*reploop*/
	goto WHL2768;
WHX2769:
	local[2]= NIL;
BLK2770:
	local[2]= NIL;
	local[3]= local[0];
WHL2772:
	if (local[3]==NIL) goto WHX2773;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
WHL2776:
	local[4]= local[2];
	local[5]= fqv[130];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	if (w==NIL) goto AND2779;
	local[4]= local[2];
	local[5]= fqv[130];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= loadglobal(fqv[214]);
	ctx->vsp=local+6;
	w=(pointer)DERIVEDP(ctx,2,local+4); /*derivedp*/
	if (w==NIL) goto AND2779;
	goto WHX2777;
AND2779:
	local[4]= loadglobal(fqv[176]);
	local[5]= NIL;
	local[6]= fqv[659];
	local[7]= local[2];
	local[8]= local[2];
	local[9]= fqv[130];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,4,local+5); /*format*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,2,local+4); /*format*/
	local[4]= loadglobal(fqv[176]);
	ctx->vsp=local+5;
	w=(pointer)FINOUT(ctx,1,local+4); /*finish-output*/
	local[4]= fqv[660];
	ctx->vsp=local+5;
	w=(*ftab[64])(ctx,1,local+4,&ftab[64],fqv[651]); /*reploop*/
	goto WHL2776;
WHX2777:
	local[4]= NIL;
BLK2778:
WHL2780:
	local[4]= local[2];
	local[5]= fqv[133];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	if (w==NIL) goto AND2783;
	local[4]= local[2];
	local[5]= fqv[133];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= loadglobal(fqv[214]);
	ctx->vsp=local+6;
	w=(pointer)DERIVEDP(ctx,2,local+4); /*derivedp*/
	if (w==NIL) goto AND2783;
	goto WHX2781;
AND2783:
	local[4]= loadglobal(fqv[176]);
	local[5]= NIL;
	local[6]= fqv[661];
	local[7]= local[2];
	local[8]= local[2];
	local[9]= fqv[133];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,4,local+5); /*format*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,2,local+4); /*format*/
	local[4]= loadglobal(fqv[176]);
	ctx->vsp=local+5;
	w=(pointer)FINOUT(ctx,1,local+4); /*finish-output*/
	local[4]= fqv[662];
	ctx->vsp=local+5;
	w=(*ftab[64])(ctx,1,local+4,&ftab[64],fqv[651]); /*reploop*/
	goto WHL2780;
WHX2781:
	local[4]= NIL;
BLK2782:
WHL2784:
	local[4]= local[2];
	local[5]= fqv[130];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[2];
	local[6]= fqv[133];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= fqv[547];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[16])(ctx,2,local+4,&ftab[16],fqv[124]); /*member*/
	if (w==NIL) goto AND2787;
	local[4]= local[2];
	local[5]= fqv[133];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[2];
	local[6]= fqv[130];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= fqv[215];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)EQUAL(ctx,2,local+4); /*equal*/
	if (w==NIL) goto AND2787;
	goto WHX2785;
AND2787:
	local[4]= loadglobal(fqv[176]);
	local[5]= NIL;
	local[6]= fqv[663];
	local[7]= local[2];
	local[8]= local[2];
	local[9]= fqv[133];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= local[2];
	local[10]= fqv[130];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,5,local+5); /*format*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,2,local+4); /*format*/
	local[4]= loadglobal(fqv[176]);
	ctx->vsp=local+5;
	w=(pointer)FINOUT(ctx,1,local+4); /*finish-output*/
	local[4]= fqv[664];
	ctx->vsp=local+5;
	w=(*ftab[64])(ctx,1,local+4,&ftab[64],fqv[651]); /*reploop*/
	goto WHL2784;
WHX2785:
	local[4]= NIL;
BLK2786:
WHL2788:
	local[4]= local[2];
	local[5]= fqv[130];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= fqv[133];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[2];
	local[6]= fqv[133];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)EQUAL(ctx,2,local+4); /*equal*/
	if (w==NIL) goto AND2791;
	local[4]= local[2];
	local[5]= fqv[130];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[2];
	local[6]= fqv[133];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= fqv[548];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[16])(ctx,2,local+4,&ftab[16],fqv[124]); /*member*/
	if (w==NIL) goto AND2791;
	goto WHX2789;
AND2791:
	local[4]= loadglobal(fqv[176]);
	local[5]= NIL;
	local[6]= fqv[665];
	local[7]= local[2];
	local[8]= local[2];
	local[9]= fqv[130];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= local[2];
	local[10]= fqv[133];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,5,local+5); /*format*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,2,local+4); /*format*/
	local[4]= loadglobal(fqv[176]);
	ctx->vsp=local+5;
	w=(pointer)FINOUT(ctx,1,local+4); /*finish-output*/
	local[4]= fqv[666];
	ctx->vsp=local+5;
	w=(*ftab[64])(ctx,1,local+4,&ftab[64],fqv[651]); /*reploop*/
	goto WHL2788;
WHX2789:
	local[4]= NIL;
BLK2790:
	goto WHL2772;
WHX2773:
	local[4]= NIL;
BLK2774:
	w = NIL;
	local[0]= w;
BLK2759:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2766(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= loadglobal(fqv[28]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2767(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= loadglobal(fqv[214]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*eusmodel-validity-check*/
static pointer F775eusmodel_validity_check(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[667];
	local[1]= fqv[668];
	ctx->vsp=local+2;
	w=(*ftab[65])(ctx,2,local+0,&ftab[65],fqv[669]); /*require*/
	ctx->vsp=local+0;
	w=(*ftab[66])(ctx,0,local+0,&ftab[66],fqv[670]); /*init-unit-test*/
	local[0]= NIL;
	storeglobal(fqv[671],local[0]);
	local[0]= fqv[672];
	local[1]= fqv[673];
	local[2]= fqv[674];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	ctx->vsp=local+1;
	w=(pointer)EVAL(ctx,1,local+0); /*eval*/
	ctx->vsp=local+0;
	w=(*ftab[67])(ctx,0,local+0,&ftab[67],fqv[675]); /*run-all-tests*/
	local[0]= w;
BLK2792:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___irtmodel(ctx,n,argv,env)
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
	local[0]= fqv[676];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF2793;
	local[0]= fqv[677];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[678],w);
	goto IF2794;
IF2793:
	local[0]= fqv[679];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF2794:
	local[0]= fqv[680];
	ctx->vsp=local+1;
	w=(*ftab[65])(ctx,1,local+0,&ftab[65],fqv[669]); /*require*/
	local[0]= fqv[681];
	ctx->vsp=local+1;
	w=(*ftab[65])(ctx,1,local+0,&ftab[65],fqv[669]); /*require*/
	local[0]= fqv[682];
	ctx->vsp=local+1;
	w=(*ftab[65])(ctx,1,local+0,&ftab[65],fqv[669]); /*require*/
	local[0]= fqv[28];
	local[1]= fqv[683];
	local[2]= fqv[28];
	local[3]= fqv[684];
	local[4]= loadglobal(fqv[685]);
	local[5]= fqv[655];
	local[6]= fqv[686];
	local[7]= fqv[687];
	local[8]= NIL;
	local[9]= fqv[688];
	local[10]= NIL;
	local[11]= fqv[440];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[689];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[68])(ctx,13,local+2,&ftab[68],fqv[690]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M776joint_init,fqv[36],fqv[28],fqv[691]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M797joint_min_angle,fqv[22],fqv[28],fqv[692]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M803joint_max_angle,fqv[23],fqv[28],fqv[693]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M809joint_parent_link,fqv[133],fqv[28],fqv[694]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M812joint_child_link,fqv[130],fqv[28],fqv[695]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M815joint_calc_dav_gain,fqv[696],fqv[28],fqv[697]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M817joint_joint_dof,fqv[31],fqv[28],fqv[698]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M819joint_speed_to_angle,fqv[312],fqv[28],fqv[699]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M822joint_angle_to_speed,fqv[589],fqv[28],fqv[700]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M825joint_calc_jacobian,fqv[230],fqv[28],fqv[701]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M828joint_joint_velocity,fqv[37],fqv[28],fqv[702]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M834joint_joint_acceleration,fqv[38],fqv[28],fqv[703]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M840joint_joint_torque,fqv[39],fqv[28],fqv[704]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M846joint_max_joint_velocity,fqv[8],fqv[28],fqv[705]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M852joint_max_joint_torque,fqv[9],fqv[28],fqv[706]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M858joint_joint_min_max_table,fqv[10],fqv[28],fqv[707]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M864joint_joint_min_max_target,fqv[11],fqv[28],fqv[708]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M870joint_joint_min_max_table_angle_interpolate,fqv[21],fqv[28],fqv[709]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M873joint_joint_min_max_table_min_angle,fqv[41],fqv[28],fqv[710]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M877joint_joint_min_max_table_max_angle,fqv[42],fqv[28],fqv[711]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[712],module,F760calc_jacobian_default_rotate_vector,fqv[713]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[50],module,F761calc_jacobian_rotational,fqv[714]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[61],module,F762calc_jacobian_linear,fqv[715]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[716],module,F763calc_angle_speed_gain_scalar,fqv[717]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[718],module,F764calc_angle_speed_gain_vector,fqv[719]);
	local[0]= fqv[720];
	local[1]= fqv[683];
	local[2]= fqv[720];
	local[3]= fqv[684];
	local[4]= loadglobal(fqv[28]);
	local[5]= fqv[655];
	local[6]= fqv[721];
	local[7]= fqv[687];
	local[8]= NIL;
	local[9]= fqv[688];
	local[10]= NIL;
	local[11]= fqv[440];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[689];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[68])(ctx,13,local+2,&ftab[68],fqv[690]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M919rotational_joint_init,fqv[36],fqv[720],fqv[722]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M929rotational_joint_joint_angle,fqv[20],fqv[720],fqv[723]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M948rotational_joint_joint_dof,fqv[31],fqv[720],fqv[724]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M950rotational_joint_calc_angle_speed_gain,fqv[246],fqv[720],fqv[725]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M952rotational_joint_speed_to_angle,fqv[312],fqv[720],fqv[726]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M954rotational_joint_angle_to_speed,fqv[589],fqv[720],fqv[727]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M956rotational_joint_calc_jacobian,fqv[230],fqv[720],fqv[728]);
	local[0]= fqv[729];
	local[1]= fqv[683];
	local[2]= fqv[729];
	local[3]= fqv[684];
	local[4]= loadglobal(fqv[28]);
	local[5]= fqv[655];
	local[6]= fqv[730];
	local[7]= fqv[687];
	local[8]= NIL;
	local[9]= fqv[688];
	local[10]= NIL;
	local[11]= fqv[440];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[689];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[68])(ctx,13,local+2,&ftab[68],fqv[690]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M959linear_joint_init,fqv[36],fqv[729],fqv[731]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M984linear_joint_joint_angle,fqv[20],fqv[729],fqv[732]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1001linear_joint_joint_dof,fqv[31],fqv[729],fqv[733]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1003linear_joint_calc_angle_speed_gain,fqv[246],fqv[729],fqv[734]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1005linear_joint_speed_to_angle,fqv[312],fqv[729],fqv[735]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1007linear_joint_angle_to_speed,fqv[589],fqv[729],fqv[736]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1009linear_joint_calc_jacobian,fqv[230],fqv[729],fqv[737]);
	local[0]= fqv[738];
	local[1]= fqv[683];
	local[2]= fqv[738];
	local[3]= fqv[684];
	local[4]= loadglobal(fqv[28]);
	local[5]= fqv[655];
	local[6]= fqv[739];
	local[7]= fqv[687];
	local[8]= NIL;
	local[9]= fqv[688];
	local[10]= NIL;
	local[11]= fqv[440];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[689];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[68])(ctx,13,local+2,&ftab[68],fqv[690]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1012wheel_joint_init,fqv[36],fqv[738],fqv[740]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1019wheel_joint_joint_angle,fqv[20],fqv[738],fqv[741]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1030wheel_joint_joint_dof,fqv[31],fqv[738],fqv[742]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1032wheel_joint_calc_angle_speed_gain,fqv[246],fqv[738],fqv[743]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1034wheel_joint_speed_to_angle,fqv[312],fqv[738],fqv[744]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1036wheel_joint_angle_to_speed,fqv[589],fqv[738],fqv[745]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1038wheel_joint_calc_jacobian,fqv[230],fqv[738],fqv[746]);
	local[0]= fqv[747];
	local[1]= fqv[683];
	local[2]= fqv[747];
	local[3]= fqv[684];
	local[4]= loadglobal(fqv[28]);
	local[5]= fqv[655];
	local[6]= fqv[748];
	local[7]= fqv[687];
	local[8]= NIL;
	local[9]= fqv[688];
	local[10]= NIL;
	local[11]= fqv[440];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[689];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[68])(ctx,13,local+2,&ftab[68],fqv[690]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1040omniwheel_joint_init,fqv[36],fqv[747],fqv[749]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1047omniwheel_joint_joint_angle,fqv[20],fqv[747],fqv[750]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1056omniwheel_joint_joint_dof,fqv[31],fqv[747],fqv[751]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1058omniwheel_joint_calc_angle_speed_gain,fqv[246],fqv[747],fqv[752]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1060omniwheel_joint_speed_to_angle,fqv[312],fqv[747],fqv[753]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1062omniwheel_joint_angle_to_speed,fqv[589],fqv[747],fqv[754]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1064omniwheel_joint_calc_jacobian,fqv[230],fqv[747],fqv[755]);
	local[0]= fqv[756];
	local[1]= fqv[683];
	local[2]= fqv[756];
	local[3]= fqv[684];
	local[4]= loadglobal(fqv[28]);
	local[5]= fqv[655];
	local[6]= fqv[757];
	local[7]= fqv[687];
	local[8]= NIL;
	local[9]= fqv[688];
	local[10]= NIL;
	local[11]= fqv[440];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[689];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[68])(ctx,13,local+2,&ftab[68],fqv[690]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1066sphere_joint_init,fqv[36],fqv[756],fqv[758]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1073sphere_joint_joint_angle,fqv[20],fqv[756],fqv[759]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1085sphere_joint_joint_angle_rpy,fqv[760],fqv[756],fqv[761]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1094sphere_joint_joint_dof,fqv[31],fqv[756],fqv[762]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1096sphere_joint_calc_angle_speed_gain,fqv[246],fqv[756],fqv[763]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1098sphere_joint_speed_to_angle,fqv[312],fqv[756],fqv[764]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1100sphere_joint_angle_to_speed,fqv[589],fqv[756],fqv[765]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1102sphere_joint_calc_jacobian,fqv[230],fqv[756],fqv[766]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1104sphere_joint_joint_euler_angle,fqv[767],fqv[756],fqv[768]);
	local[0]= fqv[600];
	local[1]= fqv[683];
	local[2]= fqv[600];
	local[3]= fqv[684];
	local[4]= loadglobal(fqv[28]);
	local[5]= fqv[655];
	local[6]= fqv[769];
	local[7]= fqv[687];
	local[8]= NIL;
	local[9]= fqv[688];
	local[10]= NIL;
	local[11]= fqv[440];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[689];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[68])(ctx,13,local+2,&ftab[68],fqv[690]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M11506dof_joint_init,fqv[36],fqv[600],fqv[770]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M11606dof_joint_joint_angle,fqv[20],fqv[600],fqv[771]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M11786dof_joint_joint_angle_rpy,fqv[760],fqv[600],fqv[772]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M11876dof_joint_joint_dof,fqv[31],fqv[600],fqv[773]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M11896dof_joint_calc_angle_speed_gain,fqv[246],fqv[600],fqv[774]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M11916dof_joint_speed_to_angle,fqv[312],fqv[600],fqv[775]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M11936dof_joint_angle_to_speed,fqv[589],fqv[600],fqv[776]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M11956dof_joint_calc_jacobian,fqv[230],fqv[600],fqv[777]);
	local[0]= fqv[214];
	local[1]= fqv[683];
	local[2]= fqv[214];
	local[3]= fqv[684];
	local[4]= loadglobal(fqv[778]);
	local[5]= fqv[655];
	local[6]= fqv[779];
	local[7]= fqv[687];
	local[8]= NIL;
	local[9]= fqv[688];
	local[10]= NIL;
	local[11]= fqv[440];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[689];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[68])(ctx,13,local+2,&ftab[68],fqv[690]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1197bodyset_link_init,fqv[36],fqv[214],fqv[780]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1204bodyset_link_worldcoords,fqv[122],fqv[214],fqv[781]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1213bodyset_link_analysis_level,fqv[149],fqv[214],fqv[782]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1219bodyset_link_weight,fqv[274],fqv[214],fqv[783]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1225bodyset_link_centroid,fqv[258],fqv[214],fqv[784]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1231bodyset_link_inertia_tensor,fqv[606],fqv[214],fqv[785]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1237bodyset_link_joint,fqv[198],fqv[214],fqv[786]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1240bodyset_link_add_joint,fqv[131],fqv[214],fqv[787]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1242bodyset_link_del_joint,fqv[643],fqv[214],fqv[788]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1244bodyset_link_parent_link,fqv[133],fqv[214],fqv[789]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1246bodyset_link_child_links,fqv[548],fqv[214],fqv[790]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1248bodyset_link_add_child_links,fqv[134],fqv[214],fqv[791]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1252bodyset_link_add_parent_link,fqv[132],fqv[214],fqv[792]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1254bodyset_link_del_child_link,fqv[645],fqv[214],fqv[793]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1256bodyset_link_del_parent_link,fqv[644],fqv[214],fqv[794]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1258bodyset_link_default_coords,fqv[795],fqv[214],fqv[796]);
	local[0]= fqv[377];
	local[1]= fqv[683];
	local[2]= fqv[377];
	local[3]= fqv[684];
	local[4]= loadglobal(fqv[121]);
	local[5]= fqv[655];
	local[6]= fqv[797];
	local[7]= fqv[687];
	local[8]= NIL;
	local[9]= fqv[688];
	local[10]= NIL;
	local[11]= fqv[440];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[689];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[68])(ctx,13,local+2,&ftab[68],fqv[690]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1264cascaded_link_init,fqv[36],fqv[377],fqv[798]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1268cascaded_link_init_ending,fqv[799],fqv[377],fqv[800]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1280cascaded_link_links,fqv[136],fqv[377],fqv[801]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1283cascaded_link_joint_list,fqv[656],fqv[377],fqv[802]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1286cascaded_link_link,fqv[575],fqv[377],fqv[803]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1289cascaded_link_joint,fqv[198],fqv[377],fqv[804]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1292cascaded_link_end_coords,fqv[626],fqv[377],fqv[805]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1295cascaded_link_bodies,fqv[127],fqv[377],fqv[806]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1298cascaded_link_faces,fqv[143],fqv[377],fqv[807]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1300cascaded_link_update_descendants,fqv[135],fqv[377],fqv[808]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1303cascaded_link_angle_vector,fqv[154],fqv[377],fqv[809]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1353cascaded_link_find_link_route,fqv[147],fqv[377],fqv[810]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1361cascaded_link_link_list,fqv[261],fqv[377],fqv[811]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1367cascaded_link_make_joint_min_max_table,fqv[812],fqv[377],fqv[813]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1387cascaded_link_make_min_max_table_using_collision_check,fqv[165],fqv[377],fqv[814]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1417cascaded_link_plot_joint_min_max_table_common,fqv[188],fqv[377],fqv[815]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1439cascaded_link_plot_joint_min_max_table,fqv[816],fqv[377],fqv[817]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1463cascaded_link_calc_target_axis_dimension,fqv[210],fqv[377],fqv[818]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1483cascaded_link_calc_union_link_list,fqv[197],fqv[377],fqv[819]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1489cascaded_link_calc_target_joint_dimension,fqv[211],fqv[377],fqv[820]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1491cascaded_link_calc_inverse_jacobian,fqv[361],fqv[377],fqv[821]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1511cascaded_link_calc_gradh_from_link_list,fqv[822],fqv[377],fqv[823]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1520cascaded_link_calc_jacobian_from_link_list,fqv[300],fqv[377],fqv[824]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1598cascaded_link_calc_joint_angle_speed,fqv[308],fqv[377],fqv[825]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1640cascaded_link_calc_joint_angle_speed_gain,fqv[309],fqv[377],fqv[826]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1651cascaded_link_collision_avoidance_links,fqv[827],fqv[377],fqv[828]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1657cascaded_link_collision_avoidance_link_pair_from_link_list,fqv[338],fqv[377],fqv[829]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1714cascaded_link_collision_avoidance_calc_distance,fqv[290],fqv[377],fqv[830]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1738cascaded_link_collision_avoidance_args,fqv[297],fqv[377],fqv[831]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1744cascaded_link_collision_avoidance,fqv[363],fqv[377],fqv[832]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1786cascaded_link_move_joints,fqv[378],fqv[377],fqv[833]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1818cascaded_link_find_joint_angle_limit_weight_old_from_union_link_list,fqv[316],fqv[377],fqv[834]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1821cascaded_link_reset_joint_angle_limit_weight_old,fqv[405],fqv[377],fqv[835]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1825cascaded_link_calc_weight_from_joint_limit,fqv[326],fqv[377],fqv[836]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1859cascaded_link_calc_inverse_kinematics_weight_from_link_list,fqv[355],fqv[377],fqv[837]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1897cascaded_link_calc_nspace_from_joint_limit,fqv[330],fqv[377],fqv[838]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1907cascaded_link_calc_inverse_kinematics_nspace_from_link_list,fqv[370],fqv[377],fqv[839]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1947cascaded_link_move_joints_avoidance,fqv[434],fqv[377],fqv[840]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2031cascaded_link_inverse_kinematics_args,fqv[464],fqv[377],fqv[841]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2042cascaded_link_draw_collision_debug_view,fqv[437],fqv[377],fqv[842]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2070cascaded_link_inverse_kinematics_loop,fqv[467],fqv[377],fqv[843]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2236cascaded_link_inverse_kinematics,fqv[529],fqv[377],fqv[844]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2415cascaded_link_ik_convergence_check,fqv[415],fqv[377],fqv[845]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2430cascaded_link_calc_vel_from_pos,fqv[416],fqv[377],fqv[846]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2440cascaded_link_calc_vel_from_rot,fqv[417],fqv[377],fqv[847]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2450cascaded_link_collision_check_pairs,fqv[552],fqv[377],fqv[848]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2464cascaded_link_self_collision_check,fqv[477],fqv[377],fqv[849]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2478cascaded_link_calc_grasp_matrix,fqv[850],fqv[377],fqv[851]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2496cascaded_link_inverse_kinematics_for_closed_loop_forward_kinematics,fqv[852],fqv[377],fqv[853]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2509cascaded_link_calc_jacobian_for_interlocking_joints,fqv[854],fqv[377],fqv[855]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2514cascaded_link_calc_vel_for_interlocking_joints,fqv[856],fqv[377],fqv[857]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2518cascaded_link_set_midpoint_for_interlocking_joints,fqv[858],fqv[377],fqv[859]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2522cascaded_link_interlocking_joint_pairs,fqv[559],fqv[377],fqv[860]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2524cascaded_link_check_interlocking_joint_angle_validity,fqv[861],fqv[377],fqv[862]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[863],module,F765all_child_links,fqv[864]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[865],module,F766calc_dif_with_axis,fqv[866]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[867],module,F767calc_target_joint_dimension,fqv[868]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[869],module,F768calc_joint_angle_min_max_for_limit_calculation,fqv[870]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[871],module,F769joint_angle_limit_weight,fqv[872]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[873],module,F770joint_angle_limit_nspace,fqv[874]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[875],module,F771calc_jacobian_from_link_list_including_robot_and_obj_virtual_joint,fqv[876]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[877],module,F772append_obj_virtual_joint,fqv[878]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[879],module,F773append_multiple_obj_virtual_joint,fqv[880]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[881],module,F2739,fqv[882]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[883],module,F2746,fqv[884]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[885],module,F2749,fqv[886]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[887],module,F2752,fqv[888]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[889],module,F2756,fqv[890]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[674],module,F774eusmodel_validity_check_one,fqv[891]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[892],module,F775eusmodel_validity_check,fqv[893]);
	local[0]= fqv[894];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF2795;
	local[0]= fqv[895];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[678],w);
	goto IF2796;
IF2795:
	local[0]= fqv[896];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF2796:
	local[0]= fqv[897];
	local[1]= fqv[898];
	ctx->vsp=local+2;
	w=(*ftab[69])(ctx,2,local+0,&ftab[69],fqv[899]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<70; i++) ftab[i]=fcallx;
}
