/* ./irtgl.c :  entry=irtgl */
/* compiled by EusLisp 9.27() for Linux created on ip-10-0-1-214(Fri Apr 16 04:05:26 PST 2021) */
#include "eus.h"
#include "irtgl.h"
#pragma init (register_irtgl)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___irtgl();
extern pointer build_quote_vector();
static int register_irtgl()
  { add_module_initializer("___irtgl", ___irtgl);}

static pointer F976set_stereo_gl_attribute();
static pointer F977reset_gl_attribute();
static pointer F978delete_displaylist_id();
static pointer F979transpose_image_rows();
static pointer F980draw_globjects();
static pointer F981draw_glbody();
static pointer F982find_color();
static pointer F983transparent();
static pointer F984make_glvertices_from_faceset();
static pointer F985make_glvertices_from_faces();
static pointer F986_dump_wrl_shape();
static pointer F987write_wrl_from_glvertices();

/*set-stereo-gl-attribute*/
static pointer F976set_stereo_gl_attribute(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	ctx->vsp=local+0;
	w=(pointer)F977reset_gl_attribute(ctx,0,local+0); /*reset-gl-attribute*/
	local[0]= loadglobal(fqv[0]);
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	local[0]= w;
	local[1]= fqv[1];
	local[2]= fqv[2];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,3,local+0,&ftab[0],fqv[3]); /*make-array*/
	local[0]= w;
	local[1]= local[0];
	local[2]= loadglobal(fqv[0]);
	ctx->vsp=local+3;
	w=(pointer)VECREPLACE(ctx,2,local+1); /*system::vector-replace*/
	local[1]= local[0];
	local[2]= loadglobal(fqv[0]);
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SUB1(ctx,1,local+2); /*1-*/
	local[2]= w;
	local[3]= makeint((eusinteger_t)6L);
	ctx->vsp=local+4;
	w=(pointer)SETELT(ctx,3,local+1); /*setelt*/
	local[1]= local[0];
	storeglobal(fqv[0],local[1]);
	w = local[1];
	local[0]= w;
BLK988:
	ctx->vsp=local; return(local[0]);}

/*reset-gl-attribute*/
static pointer F977reset_gl_attribute(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= makeint((eusinteger_t)4L);
	local[1]= makeint((eusinteger_t)8L);
	local[2]= makeint((eusinteger_t)1L);
	local[3]= makeint((eusinteger_t)9L);
	local[4]= makeint((eusinteger_t)1L);
	local[5]= makeint((eusinteger_t)10L);
	local[6]= makeint((eusinteger_t)1L);
	local[7]= makeint((eusinteger_t)5L);
	local[8]= makeint((eusinteger_t)12L);
	local[9]= makeint((eusinteger_t)1L);
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)MKINTVECTOR(ctx,11,local+0); /*integer-vector*/
	local[0]= w;
	storeglobal(fqv[0],w);
	w = local[0];
	local[0]= w;
BLK989:
	ctx->vsp=local; return(local[0]);}

/*delete-displaylist-id*/
static pointer F978delete_displaylist_id(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!isnum(w)) goto CON992;
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[4]); /*gldeletelists*/
	local[0]= w;
	goto CON991;
CON992:
	local[0]= NIL;
	local[1]= argv[0];
WHL995:
	if (local[1]==NIL) goto WHX996;
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
	local[3]= loadglobal(fqv[5]);
	local[4]= fqv[6];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO999,env,argv,local);
	ctx->vsp=local+6;
	w=(*ftab[2])(ctx,4,local+2,&ftab[2],fqv[7]); /*find*/
	local[2]= w;
	if (local[2]==NIL) goto IF1000;
	local[3]= local[2];
	local[4]= fqv[8];
	local[5]= fqv[9];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(*ftab[3])(ctx,1,local+3,&ftab[3],fqv[10]); /*glislist*/
	if (w==NIL) goto CON1003;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[4]); /*gldeletelists*/
	local[3]= w;
	goto CON1002;
CON1003:
	local[3]= fqv[11];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,2,local+3); /*error*/
	local[3]= w;
	goto CON1002;
CON1004:
	local[3]= NIL;
CON1002:
	goto IF1001;
IF1000:
	local[3]= fqv[12];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,2,local+3); /*error*/
	local[3]= w;
IF1001:
	w = local[3];
	goto WHL995;
WHX996:
	local[2]= NIL;
BLK997:
	w = NIL;
	local[0]= w;
	goto CON991;
CON993:
	local[0]= NIL;
CON991:
	w = local[0];
	local[0]= w;
BLK990:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO999(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[8];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = *(ovafptr(w,fqv[13]));
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*transpose-image-rows*/
static pointer F979transpose_image_rows(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT1007;}
	local[0]= NIL;
ENT1007:
ENT1006:
	if (n>2) maerror();
	local[1]= argv[0];
	local[2]= fqv[14];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[15];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[16];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[17];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	if (local[0]==NIL) goto CON1009;
	local[4]= argv[0];
	local[5]= fqv[14];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[0];
	local[6]= fqv[14];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	if (w!=local[4]) goto AND1012;
	local[4]= argv[0];
	local[5]= fqv[15];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[0];
	local[6]= fqv[15];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	if (w!=local[4]) goto AND1012;
	local[4]= argv[0];
	local[5]= fqv[16];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[0];
	local[6]= fqv[16];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	if (w!=local[4]) goto AND1012;
	goto IF1010;
AND1012:
	local[4]= fqv[18];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,1,local+4); /*error*/
	local[4]= w;
	goto IF1011;
IF1010:
	local[4]= NIL;
IF1011:
	local[4]= local[1];
	local[5]= local[2];
	local[6]= local[3];
	local[7]= local[0];
	local[8]= fqv[17];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[4])(ctx,4,local+4,&ftab[4],fqv[19]); /*ctranspose-image-rows*/
	local[4]= local[0];
	goto CON1008;
CON1009:
	local[4]= local[1];
	local[5]= local[2];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,3,local+4,&ftab[4],fqv[19]); /*ctranspose-image-rows*/
	local[4]= argv[0];
	goto CON1008;
CON1013:
	local[4]= NIL;
CON1008:
	w = local[4];
	local[0]= w;
BLK1005:
	ctx->vsp=local; return(local[0]);}

/*:color*/
static pointer M1014glviewsurface_color(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1017;}
	local[0]= NIL;
ENT1017:
ENT1016:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1018;
	local[1]= argv[0];
	local[2]= fqv[20];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF1019;
IF1018:
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,4,local+1); /*float-vector*/
	local[1]= w;
	local[2]= makeint((eusinteger_t)2816L);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(*ftab[5])(ctx,2,local+2,&ftab[5],fqv[21]); /*glgetfloatv*/
	local[2]= local[1];
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)3L);
	ctx->vsp=local+5;
	w=(pointer)SUBSEQ(ctx,3,local+2); /*subseq*/
	local[1]= w;
IF1019:
	w = local[1];
	local[0]= w;
BLK1015:
	ctx->vsp=local; return(local[0]);}

/*:line-width*/
static pointer M1020glviewsurface_line_width(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1023;}
	local[0]= NIL;
ENT1023:
ENT1022:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1024;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)EUSFLOAT(ctx,1,local+1); /*float*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[22]); /*gllinewidth*/
	local[1]= w;
	goto IF1025;
IF1024:
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)MKFLTVEC(ctx,1,local+1); /*float-vector*/
	local[1]= w;
	local[2]= makeint((eusinteger_t)2849L);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(*ftab[5])(ctx,2,local+2,&ftab[5],fqv[21]); /*glgetfloatv*/
	local[2]= local[1];
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[1]= w;
IF1025:
	w = local[1];
	local[0]= w;
BLK1021:
	ctx->vsp=local; return(local[0]);}

/*:point-size*/
static pointer M1026glviewsurface_point_size(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1029;}
	local[0]= NIL;
ENT1029:
ENT1028:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1030;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)EUSFLOAT(ctx,1,local+1); /*float*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,1,local+1,&ftab[7],fqv[23]); /*glpointsize*/
	local[1]= w;
	goto IF1031;
IF1030:
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)MKFLTVEC(ctx,1,local+1); /*float-vector*/
	local[1]= w;
	local[2]= makeint((eusinteger_t)2833L);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(*ftab[5])(ctx,2,local+2,&ftab[5],fqv[21]); /*glgetfloatv*/
	local[2]= local[1];
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[1]= w;
IF1031:
	w = local[1];
	local[0]= w;
BLK1027:
	ctx->vsp=local; return(local[0]);}

/*:3d-point*/
static pointer M1032glviewsurface_3d_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[24], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY1034;
	local[0] = T;
KEY1034:
	if (n & (1<<1)) goto KEY1035;
	local[1] = T;
KEY1035:
	if (local[0]==NIL) goto IF1036;
	local[2]= makeint((eusinteger_t)2929L);
	ctx->vsp=local+3;
	w=(*ftab[8])(ctx,1,local+2,&ftab[8],fqv[25]); /*gldisable*/
	local[2]= w;
	goto IF1037;
IF1036:
	local[2]= NIL;
IF1037:
	if (local[1]==NIL) goto IF1038;
	local[2]= makeint((eusinteger_t)2896L);
	ctx->vsp=local+3;
	w=(*ftab[8])(ctx,1,local+2,&ftab[8],fqv[25]); /*gldisable*/
	local[2]= w;
	goto IF1039;
IF1038:
	local[2]= NIL;
IF1039:
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(*ftab[9])(ctx,1,local+2,&ftab[9],fqv[26]); /*glbegin*/
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[10])(ctx,1,local+2,&ftab[10],fqv[27]); /*glvertex3fv*/
	ctx->vsp=local+2;
	w=(*ftab[11])(ctx,0,local+2,&ftab[11],fqv[28]); /*glend*/
	if (local[0]==NIL) goto IF1040;
	local[2]= makeint((eusinteger_t)2929L);
	ctx->vsp=local+3;
	w=(*ftab[12])(ctx,1,local+2,&ftab[12],fqv[29]); /*glenable*/
	local[2]= w;
	goto IF1041;
IF1040:
	local[2]= NIL;
IF1041:
	if (local[1]==NIL) goto IF1042;
	local[2]= makeint((eusinteger_t)2896L);
	ctx->vsp=local+3;
	w=(*ftab[12])(ctx,1,local+2,&ftab[12],fqv[29]); /*glenable*/
	local[2]= w;
	goto IF1043;
IF1042:
	local[2]= NIL;
IF1043:
	w = local[2];
	local[0]= w;
BLK1033:
	ctx->vsp=local; return(local[0]);}

/*:3d-line*/
static pointer M1044glviewsurface_3d_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[30], &argv[4], n-4, local+0, 0);
	if (n & (1<<0)) goto KEY1046;
	local[0] = T;
KEY1046:
	if (n & (1<<1)) goto KEY1047;
	local[1] = T;
KEY1047:
	if (local[0]==NIL) goto IF1048;
	local[2]= makeint((eusinteger_t)2929L);
	ctx->vsp=local+3;
	w=(*ftab[8])(ctx,1,local+2,&ftab[8],fqv[25]); /*gldisable*/
	local[2]= w;
	goto IF1049;
IF1048:
	local[2]= NIL;
IF1049:
	if (local[1]==NIL) goto IF1050;
	local[2]= makeint((eusinteger_t)2896L);
	ctx->vsp=local+3;
	w=(*ftab[8])(ctx,1,local+2,&ftab[8],fqv[25]); /*gldisable*/
	local[2]= w;
	goto IF1051;
IF1050:
	local[2]= NIL;
IF1051:
	local[2]= makeint((eusinteger_t)3L);
	ctx->vsp=local+3;
	w=(*ftab[9])(ctx,1,local+2,&ftab[9],fqv[26]); /*glbegin*/
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[10])(ctx,1,local+2,&ftab[10],fqv[27]); /*glvertex3fv*/
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(*ftab[10])(ctx,1,local+2,&ftab[10],fqv[27]); /*glvertex3fv*/
	ctx->vsp=local+2;
	w=(*ftab[11])(ctx,0,local+2,&ftab[11],fqv[28]); /*glend*/
	if (local[0]==NIL) goto IF1052;
	local[2]= makeint((eusinteger_t)2929L);
	ctx->vsp=local+3;
	w=(*ftab[12])(ctx,1,local+2,&ftab[12],fqv[29]); /*glenable*/
	local[2]= w;
	goto IF1053;
IF1052:
	local[2]= NIL;
IF1053:
	if (local[1]==NIL) goto IF1054;
	local[2]= makeint((eusinteger_t)2896L);
	ctx->vsp=local+3;
	w=(*ftab[12])(ctx,1,local+2,&ftab[12],fqv[29]); /*glenable*/
	local[2]= w;
	goto IF1055;
IF1054:
	local[2]= NIL;
IF1055:
	w = local[2];
	local[0]= w;
BLK1045:
	ctx->vsp=local; return(local[0]);}

/*:3d-lines*/
static pointer M1056glviewsurface_3d_lines(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[31], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY1058;
	local[0] = T;
KEY1058:
	if (n & (1<<1)) goto KEY1059;
	local[1] = T;
KEY1059:
	if (local[0]==NIL) goto IF1060;
	local[2]= makeint((eusinteger_t)2929L);
	ctx->vsp=local+3;
	w=(*ftab[8])(ctx,1,local+2,&ftab[8],fqv[25]); /*gldisable*/
	local[2]= w;
	goto IF1061;
IF1060:
	local[2]= NIL;
IF1061:
	if (local[1]==NIL) goto IF1062;
	local[2]= makeint((eusinteger_t)2896L);
	ctx->vsp=local+3;
	w=(*ftab[8])(ctx,1,local+2,&ftab[8],fqv[25]); /*gldisable*/
	local[2]= w;
	goto IF1063;
IF1062:
	local[2]= NIL;
IF1063:
	local[2]= makeint((eusinteger_t)3L);
	ctx->vsp=local+3;
	w=(*ftab[9])(ctx,1,local+2,&ftab[9],fqv[26]); /*glbegin*/
	local[2]= NIL;
	local[3]= argv[2];
WHL1065:
	if (local[3]==NIL) goto WHX1066;
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
	w=(*ftab[10])(ctx,1,local+4,&ftab[10],fqv[27]); /*glvertex3fv*/
	goto WHL1065;
WHX1066:
	local[4]= NIL;
BLK1067:
	w = NIL;
	ctx->vsp=local+2;
	w=(*ftab[11])(ctx,0,local+2,&ftab[11],fqv[28]); /*glend*/
	if (local[0]==NIL) goto IF1069;
	local[2]= makeint((eusinteger_t)2929L);
	ctx->vsp=local+3;
	w=(*ftab[12])(ctx,1,local+2,&ftab[12],fqv[29]); /*glenable*/
	local[2]= w;
	goto IF1070;
IF1069:
	local[2]= NIL;
IF1070:
	if (local[1]==NIL) goto IF1071;
	local[2]= makeint((eusinteger_t)2896L);
	ctx->vsp=local+3;
	w=(*ftab[12])(ctx,1,local+2,&ftab[12],fqv[29]); /*glenable*/
	local[2]= w;
	goto IF1072;
IF1071:
	local[2]= NIL;
IF1072:
	w = local[2];
	local[0]= w;
BLK1057:
	ctx->vsp=local; return(local[0]);}

/*:makecurrent*/
static pointer M1073glviewsurface_makecurrent(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[32]);
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= argv[0]->c.obj.iv[15];
	ctx->vsp=local+3;
	w=(*ftab[13])(ctx,3,local+0,&ftab[13],fqv[33]); /*glxmakecurrent*/
	local[0]= w;
BLK1074:
	ctx->vsp=local; return(local[0]);}

/*:redraw*/
static pointer M1075glviewsurface_redraw(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1077:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0];
	local[2]= fqv[34];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[0]= w;
BLK1076:
	ctx->vsp=local; return(local[0]);}

/*:flush*/
static pointer M1078glviewsurface_flush(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[9];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[35];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[36]));
	local[2]= fqv[34];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= w;
BLK1079:
	ctx->vsp=local; return(local[0]);}

/*:write-to-image-file*/
static pointer M1080glviewsurface_write_to_image_file(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[37], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY1082;
	local[0] = makeint((eusinteger_t)0L);
KEY1082:
	if (n & (1<<1)) goto KEY1083;
	local[1] = makeint((eusinteger_t)0L);
KEY1083:
	if (n & (1<<2)) goto KEY1084;
	local[2] = argv[0]->c.obj.iv[5];
KEY1084:
	if (n & (1<<3)) goto KEY1085;
	local[3] = argv[0]->c.obj.iv[6];
KEY1085:
	local[4]= argv[0];
	local[5]= fqv[38];
	local[6]= fqv[39];
	local[7]= local[0];
	local[8]= fqv[40];
	local[9]= local[1];
	local[10]= fqv[15];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)SUB1(ctx,1,local+11); /*1-*/
	local[11]= w;
	local[12]= fqv[14];
	local[13]= local[3];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,10,local+4); /*send*/
	local[4]= w;
	local[5]= argv[2];
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(*ftab[14])(ctx,2,local+5,&ftab[14],fqv[41]); /*image::write-image-file*/
	local[0]= w;
BLK1081:
	ctx->vsp=local; return(local[0]);}

/*:getglimage*/
static pointer M1086glviewsurface_getglimage(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[42], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY1088;
	local[0] = makeint((eusinteger_t)0L);
KEY1088:
	if (n & (1<<1)) goto KEY1089;
	local[1] = makeint((eusinteger_t)0L);
KEY1089:
	if (n & (1<<2)) goto KEY1090;
	local[2] = argv[0]->c.obj.iv[5];
KEY1090:
	if (n & (1<<3)) goto KEY1091;
	local[3] = argv[0]->c.obj.iv[6];
KEY1091:
	if (n & (1<<4)) goto KEY1092;
	local[6]= local[2];
	local[7]= local[3];
	local[8]= makeint((eusinteger_t)3L);
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,3,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[15])(ctx,1,local+6,&ftab[15],fqv[43]); /*make-string*/
	local[4] = w;
KEY1092:
	if (n & (1<<5)) goto KEY1093;
	local[5] = NIL;
KEY1093:
	local[6]= loadglobal(fqv[44]);
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,1,local+6); /*instantiate*/
	local[6]= w;
	local[7]= local[6];
	local[8]= fqv[45];
	local[9]= local[2];
	local[10]= local[3];
	local[11]= local[4];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	w = local[6];
	local[6]= w;
	local[7]= argv[0];
	local[8]= fqv[9];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= makeint((eusinteger_t)1028L);
	ctx->vsp=local+8;
	w=(*ftab[16])(ctx,1,local+7,&ftab[16],fqv[46]); /*glreadbuffer*/
	local[7]= makeint((eusinteger_t)3333L);
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(*ftab[17])(ctx,2,local+7,&ftab[17],fqv[47]); /*glpixelstorei*/
	local[7]= local[0];
	local[8]= local[1];
	local[9]= local[2];
	local[10]= local[3];
	local[11]= makeint((eusinteger_t)6407L);
	local[12]= makeint((eusinteger_t)5121L);
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(*ftab[18])(ctx,7,local+7,&ftab[18],fqv[48]); /*glreadpixels*/
	if (local[5]==NIL) goto IF1095;
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(*ftab[19])(ctx,1,local+7,&ftab[19],fqv[49]); /*user::dvector2float-bytestring*/
	local[7]= w;
	local[8]= local[0];
	local[9]= local[1];
	local[10]= local[2];
	local[11]= local[3];
	local[12]= makeint((eusinteger_t)6402L);
	local[13]= makeint((eusinteger_t)5126L);
	local[14]= local[7];
	ctx->vsp=local+15;
	w=(*ftab[18])(ctx,7,local+8,&ftab[18],fqv[48]); /*glreadpixels*/
	local[8]= local[7];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(*ftab[20])(ctx,2,local+8,&ftab[20],fqv[50]); /*user::float-bytestring2dvector*/
	local[7]= w;
	goto IF1096;
IF1095:
	local[7]= NIL;
IF1096:
	local[7]= local[6];
	ctx->vsp=local+8;
	w=(pointer)F979transpose_image_rows(ctx,1,local+7); /*transpose-image-rows*/
	w = local[6];
	local[0]= w;
BLK1087:
	ctx->vsp=local; return(local[0]);}

/*draw-globjects*/
static pointer F980draw_globjects(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[51], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY1098;
	local[0] = T;
KEY1098:
	if (n & (1<<1)) goto KEY1099;
	local[1] = T;
KEY1099:
	if (n & (1<<2)) goto KEY1100;
	local[2] = makeint((eusinteger_t)150L);
KEY1100:
	if (n & (1<<3)) goto KEY1101;
	local[3] = NIL;
KEY1101:
	if (n & (1<<4)) goto KEY1102;
	local[4] = fqv[52];
KEY1102:
	local[5]= NIL;
	local[6]= argv[0];
	local[7]= fqv[53];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= fqv[8];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[21])(ctx,2,local+6,&ftab[21],fqv[54]); /*resetperspective*/
	if (local[0]==NIL) goto IF1103;
	local[6]= argv[0];
	local[7]= fqv[8];
	local[8]= fqv[55];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	goto IF1104;
IF1103:
	local[6]= NIL;
IF1104:
	local[6]= argv[0];
	local[7]= fqv[8];
	local[8]= fqv[56];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[5] = w;
	if (local[2]==NIL) goto IF1105;
	w = local[2];
	if (!isnum(w)) goto IF1107;
	local[6]= local[2];
	goto IF1108;
IF1107:
	local[6]= makeint((eusinteger_t)150L);
IF1108:
	local[7]= makeint((eusinteger_t)2896L);
	ctx->vsp=local+8;
	w=(*ftab[8])(ctx,1,local+7,&ftab[8],fqv[25]); /*gldisable*/
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(*ftab[9])(ctx,1,local+7,&ftab[9],fqv[26]); /*glbegin*/
	local[7]= fqv[57];
	ctx->vsp=local+8;
	w=(*ftab[22])(ctx,1,local+7,&ftab[22],fqv[58]); /*glcolor3fv*/
	local[7]= fqv[59];
	ctx->vsp=local+8;
	w=(*ftab[10])(ctx,1,local+7,&ftab[10],fqv[27]); /*glvertex3fv*/
	local[7]= local[6];
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,3,local+7); /*float-vector*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[10])(ctx,1,local+7,&ftab[10],fqv[27]); /*glvertex3fv*/
	local[7]= fqv[60];
	ctx->vsp=local+8;
	w=(*ftab[22])(ctx,1,local+7,&ftab[22],fqv[58]); /*glcolor3fv*/
	local[7]= fqv[61];
	ctx->vsp=local+8;
	w=(*ftab[10])(ctx,1,local+7,&ftab[10],fqv[27]); /*glvertex3fv*/
	local[7]= makeint((eusinteger_t)0L);
	local[8]= local[6];
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,3,local+7); /*float-vector*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[10])(ctx,1,local+7,&ftab[10],fqv[27]); /*glvertex3fv*/
	local[7]= fqv[62];
	ctx->vsp=local+8;
	w=(*ftab[22])(ctx,1,local+7,&ftab[22],fqv[58]); /*glcolor3fv*/
	local[7]= fqv[63];
	ctx->vsp=local+8;
	w=(*ftab[10])(ctx,1,local+7,&ftab[10],fqv[27]); /*glvertex3fv*/
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)0L);
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,3,local+7); /*float-vector*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[10])(ctx,1,local+7,&ftab[10],fqv[27]); /*glvertex3fv*/
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(*ftab[11])(ctx,1,local+7,&ftab[11],fqv[28]); /*glend*/
	local[7]= makeint((eusinteger_t)2896L);
	ctx->vsp=local+8;
	w=(*ftab[12])(ctx,1,local+7,&ftab[12],fqv[29]); /*glenable*/
	local[6]= w;
	goto IF1106;
IF1105:
	local[6]= NIL;
IF1106:
	if (local[3]==NIL) goto IF1109;
	w = local[3];
	if (!isnum(w)) goto IF1111;
	local[6]= local[3];
	goto IF1112;
IF1111:
	local[6]= makeint((eusinteger_t)1000L);
IF1112:
	local[7]= makeint((eusinteger_t)5000L);
	local[8]= local[7];
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,1,local+8); /*-*/
	local[8]= w;
	local[9]= makeint((eusinteger_t)2896L);
	ctx->vsp=local+10;
	w=(*ftab[8])(ctx,1,local+9,&ftab[8],fqv[25]); /*gldisable*/
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(*ftab[9])(ctx,1,local+9,&ftab[9],fqv[26]); /*glbegin*/
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(*ftab[22])(ctx,1,local+9,&ftab[22],fqv[58]); /*glcolor3fv*/
	local[9]= local[8];
TAG1115:
	local[10]= local[9];
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)GREATERP(ctx,2,local+10); /*>*/
	if (w==NIL) goto IF1116;
	w = NIL;
	ctx->vsp=local+10;
	local[9]=w;
	goto BLK1114;
	goto IF1117;
IF1116:
	local[10]= NIL;
IF1117:
	local[10]= local[8];
TAG1120:
	local[11]= local[10];
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(pointer)GREATERP(ctx,2,local+11); /*>*/
	if (w==NIL) goto IF1121;
	w = NIL;
	ctx->vsp=local+11;
	local[10]=w;
	goto BLK1119;
	goto IF1122;
IF1121:
	local[11]= NIL;
IF1122:
	local[11]= local[10];
	local[12]= local[8];
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(pointer)MKFLTVEC(ctx,3,local+11); /*float-vector*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[10])(ctx,1,local+11,&ftab[10],fqv[27]); /*glvertex3fv*/
	local[11]= local[10];
	local[12]= local[7];
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(pointer)MKFLTVEC(ctx,3,local+11); /*float-vector*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[10])(ctx,1,local+11,&ftab[10],fqv[27]); /*glvertex3fv*/
	local[11]= local[8];
	local[12]= local[9];
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(pointer)MKFLTVEC(ctx,3,local+11); /*float-vector*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[10])(ctx,1,local+11,&ftab[10],fqv[27]); /*glvertex3fv*/
	local[11]= local[7];
	local[12]= local[9];
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(pointer)MKFLTVEC(ctx,3,local+11); /*float-vector*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[10])(ctx,1,local+11,&ftab[10],fqv[27]); /*glvertex3fv*/
	local[11]= local[10];
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[11]= w;
	local[10] = local[11];
	w = NIL;
	ctx->vsp=local+11;
	goto TAG1120;
	w = NIL;
	local[10]= w;
BLK1119:
	local[10]= local[9];
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[10]= w;
	local[9] = local[10];
	w = NIL;
	ctx->vsp=local+10;
	goto TAG1115;
	w = NIL;
	local[9]= w;
BLK1114:
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(*ftab[11])(ctx,1,local+9,&ftab[11],fqv[28]); /*glend*/
	local[9]= makeint((eusinteger_t)2896L);
	ctx->vsp=local+10;
	w=(*ftab[12])(ctx,1,local+9,&ftab[12],fqv[29]); /*glenable*/
	local[6]= w;
	goto IF1110;
IF1109:
	local[6]= NIL;
IF1110:
	local[6]= makeint((eusinteger_t)3042L);
	ctx->vsp=local+7;
	w=(*ftab[8])(ctx,1,local+6,&ftab[8],fqv[25]); /*gldisable*/
	local[6]= argv[0];
	local[7]= fqv[8];
	local[8]= fqv[56];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[6]= NIL;
	local[7]= argv[1];
WHL1126:
	if (local[7]==NIL) goto WHX1127;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	local[9]= fqv[64];
	ctx->vsp=local+10;
	w=(*ftab[23])(ctx,2,local+8,&ftab[23],fqv[65]); /*find-method*/
	if (w==NIL) goto CON1131;
	local[8]= local[6];
	local[9]= fqv[64];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	goto CON1130;
CON1131:
	local[8]= local[6];
	local[9]= loadglobal(fqv[66]);
	ctx->vsp=local+10;
	w=(pointer)DERIVEDP(ctx,2,local+8); /*derivedp*/
	if (w==NIL) goto CON1132;
	local[8]= argv[0];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)F981draw_glbody(ctx,2,local+8); /*draw-glbody*/
	local[8]= w;
	goto CON1130;
CON1132:
	local[8]= local[6];
	local[9]= fqv[67];
	ctx->vsp=local+10;
	w=(*ftab[23])(ctx,2,local+8,&ftab[23],fqv[65]); /*find-method*/
	if (w==NIL) goto CON1133;
	local[8]= local[6];
	local[9]= fqv[67];
	local[10]= fqv[68];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= w;
	goto CON1130;
CON1133:
	local[8]= fqv[69];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(*ftab[24])(ctx,2,local+8,&ftab[24],fqv[70]); /*warn*/
	local[8]= w;
	goto CON1130;
CON1134:
	local[8]= NIL;
CON1130:
	goto WHL1126;
WHX1127:
	local[8]= NIL;
BLK1128:
	w = NIL;
	if (local[1]==NIL) goto IF1135;
	local[6]= argv[0];
	local[7]= fqv[8];
	local[8]= fqv[34];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	goto IF1136;
IF1135:
	local[6]= NIL;
IF1136:
	w = local[6];
	local[0]= w;
BLK1097:
	ctx->vsp=local; return(local[0]);}

/*draw-glbody*/
static pointer F981draw_glbody(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[8];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= *(ovafptr(w,fqv[13]));
	local[1]= local[0];
	local[2]= argv[1];
	local[3]= fqv[71];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ASSQ(ctx,2,local+1); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	local[2]= local[0];
	local[3]= argv[1];
	local[4]= fqv[72];
	ctx->vsp=local+5;
	w=(pointer)GETPROP(ctx,2,local+3); /*get*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ASSQ(ctx,2,local+2); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	local[3]= argv[1];
	local[4]= fqv[73];
	ctx->vsp=local+5;
	w=(pointer)GETPROP(ctx,2,local+3); /*get*/
	local[3]= w;
	if (local[3]!=NIL) goto IF1138;
	local[4]= makeflt(5.0000000000000000000000e-01);
	local[5]= makeflt(5.0000000000000000000000e-01);
	local[6]= makeflt(5.0000000000000000000000e-01);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[3] = w;
	local[4]= local[3];
	goto IF1139;
IF1138:
	local[4]= NIL;
IF1139:
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(pointer)VECTORP(ctx,1,local+4); /*vectorp*/
	if (w!=NIL) goto IF1140;
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(pointer)F982find_color(ctx,1,local+4); /*find-color*/
	local[3] = w;
	local[4]= argv[1];
	local[5]= local[3];
	local[6]= fqv[73];
	ctx->vsp=local+7;
	w=(pointer)PUTPROP(ctx,3,local+4); /*putprop*/
	local[4]= w;
	goto IF1141;
IF1140:
	local[4]= NIL;
IF1141:
	if (local[1]==NIL) goto CON1143;
	local[4]= argv[1];
	local[5]= fqv[74];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= fqv[75];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[25])(ctx,0,local+5,&ftab[25],fqv[76]); /*glpushmatrix*/
	local[5]= local[4];
	local[6]= loadglobal(fqv[77]);
	ctx->vsp=local+7;
	w=(pointer)TRANSPOSE(ctx,2,local+5); /*transpose*/
	local[5]= w->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(*ftab[26])(ctx,1,local+5,&ftab[26],fqv[78]); /*glmultmatrixf*/
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(*ftab[27])(ctx,1,local+5,&ftab[27],fqv[79]); /*glcalllist*/
	ctx->vsp=local+5;
	w=(*ftab[28])(ctx,0,local+5,&ftab[28],fqv[80]); /*glpopmatrix*/
	local[4]= w;
	goto CON1142;
CON1143:
	if (local[2]==NIL) goto CON1144;
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(*ftab[29])(ctx,1,local+4,&ftab[29],fqv[81]); /*glgenlists*/
	local[4]= w;
	local[5]= local[4];
	local[6]= makeint((eusinteger_t)4864L);
	ctx->vsp=local+7;
	w=(*ftab[30])(ctx,2,local+5,&ftab[30],fqv[82]); /*glnewlist*/
	local[5]= makeint((eusinteger_t)4294967295L);
	ctx->vsp=local+6;
	w=(*ftab[31])(ctx,1,local+5,&ftab[31],fqv[83]); /*glpushattrib*/
	local[5]= makeint((eusinteger_t)2929L);
	ctx->vsp=local+6;
	w=(*ftab[32])(ctx,1,local+5,&ftab[32],fqv[84]); /*gldepthfunc*/
	local[5]= makeint((eusinteger_t)2896L);
	ctx->vsp=local+6;
	w=(*ftab[8])(ctx,1,local+5,&ftab[8],fqv[25]); /*gldisable*/
	local[5]= fqv[85];
	ctx->vsp=local+6;
	w=(*ftab[22])(ctx,1,local+5,&ftab[22],fqv[58]); /*glcolor3fv*/
	local[5]= NIL;
	local[6]= argv[1];
	local[7]= fqv[86];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
WHL1146:
	if (local[6]==NIL) goto WHX1147;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= makeint((eusinteger_t)3L);
	ctx->vsp=local+8;
	w=(*ftab[9])(ctx,1,local+7,&ftab[9],fqv[26]); /*glbegin*/
	local[7]= NIL;
	local[8]= local[5];
	local[9]= fqv[87];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
WHL1151:
	if (local[8]==NIL) goto WHX1152;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= argv[1];
	local[10]= fqv[88];
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[10])(ctx,1,local+9,&ftab[10],fqv[27]); /*glvertex3fv*/
	goto WHL1151;
WHX1152:
	local[9]= NIL;
BLK1153:
	w = NIL;
	ctx->vsp=local+7;
	w=(*ftab[11])(ctx,0,local+7,&ftab[11],fqv[28]); /*glend*/
	goto WHL1146;
WHX1147:
	local[7]= NIL;
BLK1148:
	w = NIL;
	local[5]= makeint((eusinteger_t)32823L);
	ctx->vsp=local+6;
	w=(*ftab[12])(ctx,1,local+5,&ftab[12],fqv[29]); /*glenable*/
	local[5]= makeint((eusinteger_t)1032L);
	local[6]= makeint((eusinteger_t)6914L);
	ctx->vsp=local+7;
	w=(*ftab[33])(ctx,2,local+5,&ftab[33],fqv[89]); /*glpolygonmode*/
	local[5]= makeflt(1.0000000000000000000000e+00);
	local[6]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+7;
	w=(*ftab[34])(ctx,2,local+5,&ftab[34],fqv[90]); /*glpolygonoffset*/
	local[5]= fqv[91];
	ctx->vsp=local+6;
	w=(*ftab[22])(ctx,1,local+5,&ftab[22],fqv[58]); /*glcolor3fv*/
	local[5]= makeint((eusinteger_t)2884L);
	ctx->vsp=local+6;
	w=(*ftab[12])(ctx,1,local+5,&ftab[12],fqv[29]); /*glenable*/
	local[5]= makeint((eusinteger_t)1028L);
	ctx->vsp=local+6;
	w=(*ftab[35])(ctx,1,local+5,&ftab[35],fqv[92]); /*glcullface*/
	local[5]= NIL;
	local[6]= argv[1];
	local[7]= fqv[86];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
WHL1156:
	if (local[6]==NIL) goto WHX1157;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= makeint((eusinteger_t)9L);
	ctx->vsp=local+8;
	w=(*ftab[9])(ctx,1,local+7,&ftab[9],fqv[26]); /*glbegin*/
	local[7]= argv[1];
	local[8]= fqv[93];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)TRANSPOSE(ctx,1,local+7); /*transpose*/
	local[7]= w;
	local[8]= local[5];
	local[9]= fqv[94];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)TRANSFORM(ctx,2,local+7); /*transform*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[36])(ctx,1,local+7,&ftab[36],fqv[95]); /*glnormal3fv*/
	local[7]= NIL;
	local[8]= local[5];
	local[9]= fqv[96];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
WHL1161:
	if (local[8]==NIL) goto WHX1162;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= argv[1];
	local[10]= fqv[88];
	local[11]= local[7];
	local[12]= fqv[97];
	local[13]= local[5];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[10])(ctx,1,local+9,&ftab[10],fqv[27]); /*glvertex3fv*/
	goto WHL1161;
WHX1162:
	local[9]= NIL;
BLK1163:
	w = NIL;
	ctx->vsp=local+7;
	w=(*ftab[11])(ctx,0,local+7,&ftab[11],fqv[28]); /*glend*/
	goto WHL1156;
WHX1157:
	local[7]= NIL;
BLK1158:
	w = NIL;
	local[5]= makeint((eusinteger_t)2884L);
	ctx->vsp=local+6;
	w=(*ftab[8])(ctx,1,local+5,&ftab[8],fqv[25]); /*gldisable*/
	local[5]= makeint((eusinteger_t)32823L);
	ctx->vsp=local+6;
	w=(*ftab[8])(ctx,1,local+5,&ftab[8],fqv[25]); /*gldisable*/
	local[5]= makeint((eusinteger_t)2896L);
	ctx->vsp=local+6;
	w=(*ftab[12])(ctx,1,local+5,&ftab[12],fqv[29]); /*glenable*/
	ctx->vsp=local+5;
	w=(*ftab[37])(ctx,0,local+5,&ftab[37],fqv[98]); /*glpopattrib*/
	ctx->vsp=local+5;
	w=(*ftab[38])(ctx,0,local+5,&ftab[38],fqv[99]); /*glendlist*/
	local[5]= argv[1];
	local[6]= local[0];
	w = local[4];
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= argv[1];
	local[8]= fqv[71];
	ctx->vsp=local+9;
	w=(pointer)GETPROP(ctx,2,local+7); /*get*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[71];
	ctx->vsp=local+8;
	w=(pointer)PUTPROP(ctx,3,local+5); /*putprop*/
	local[5]= argv[0];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)F981draw_glbody(ctx,2,local+5); /*draw-glbody*/
	local[4]= w;
	goto CON1142;
CON1144:
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(*ftab[29])(ctx,1,local+4,&ftab[29],fqv[81]); /*glgenlists*/
	local[4]= w;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	local[6]= makeint((eusinteger_t)4L);
	ctx->vsp=local+7;
	w=(pointer)NUMEQUAL(ctx,2,local+5); /*=*/
	local[5]= w;
	if (w==NIL) goto AND1166;
	local[5]= local[3];
	local[6]= makeint((eusinteger_t)3L);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	local[6]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+7;
	w=(pointer)LESSP(ctx,2,local+5); /*<*/
	local[5]= w;
AND1166:
	local[6]= argv[1];
	local[7]= fqv[100];
	ctx->vsp=local+8;
	w=(pointer)GETPROP(ctx,2,local+6); /*get*/
	if (w==NIL) goto IF1167;
	local[6]= loadglobal(fqv[101]);
	local[7]= argv[1];
	local[8]= fqv[100];
	ctx->vsp=local+9;
	w=(pointer)GETPROP(ctx,2,local+7); /*get*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,2,local+6); /*instantiate*/
	local[6]= w;
	goto IF1168;
IF1167:
	local[6]= NIL;
IF1168:
	local[7]= NIL;
	local[8]= local[4];
	local[9]= makeint((eusinteger_t)4864L);
	ctx->vsp=local+10;
	w=(*ftab[30])(ctx,2,local+8,&ftab[30],fqv[82]); /*glnewlist*/
	if (local[5]==NIL) goto IF1169;
	local[8]= makeint((eusinteger_t)3042L);
	ctx->vsp=local+9;
	w=(*ftab[12])(ctx,1,local+8,&ftab[12],fqv[29]); /*glenable*/
	local[8]= makeint((eusinteger_t)770L);
	local[9]= makeint((eusinteger_t)771L);
	ctx->vsp=local+10;
	w=(*ftab[39])(ctx,2,local+8,&ftab[39],fqv[102]); /*glblendfunc*/
	local[8]= w;
	goto IF1170;
IF1169:
	local[8]= NIL;
IF1170:
	local[8]= makeint((eusinteger_t)1032L);
	local[9]= makeint((eusinteger_t)5634L);
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(*ftab[40])(ctx,3,local+8,&ftab[40],fqv[103]); /*glmaterialfv*/
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
	w = makeint((eusinteger_t)0L);
	if ((eusinteger_t)local[8] <= (eusinteger_t)w) goto IF1171;
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(*ftab[41])(ctx,2,local+8,&ftab[41],fqv[104]); /*glgentexturesext*/
	local[8]= w;
	goto IF1172;
IF1171:
	local[8]= NIL;
IF1172:
	local[8]= NIL;
	local[9]= argv[1];
	local[10]= fqv[86];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
WHL1174:
	if (local[9]==NIL) goto WHX1175;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= local[8];
	local[11]= fqv[105];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	if (w==NIL) goto CON1179;
	local[10]= local[8];
	local[11]= fqv[106];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	if (w!=NIL) goto CON1179;
	local[10]= local[8];
	local[11]= fqv[100];
	ctx->vsp=local+12;
	w=(pointer)GETPROP(ctx,2,local+10); /*get*/
	local[10]= w;
	local[11]= local[8];
	local[12]= fqv[107];
	ctx->vsp=local+13;
	w=(pointer)GETPROP(ctx,2,local+11); /*get*/
	local[11]= w;
	local[12]= local[10];
	local[13]= loadglobal(fqv[44]);
	ctx->vsp=local+14;
	w=(pointer)DERIVEDP(ctx,2,local+12); /*derivedp*/
	if (w==NIL) goto CON1181;
	local[12]= makeint((eusinteger_t)6407L);
	goto CON1180;
CON1181:
	local[12]= local[10];
	local[13]= loadglobal(fqv[108]);
	ctx->vsp=local+14;
	w=(pointer)DERIVEDP(ctx,2,local+12); /*derivedp*/
	if (w==NIL) goto CON1182;
	local[12]= makeint((eusinteger_t)6409L);
	goto CON1180;
CON1182:
	local[12]= NIL;
CON1180:
	if (local[10]==NIL) goto IF1183;
	local[13]= local[10];
	local[14]= fqv[109];
	ctx->vsp=local+15;
	w=(pointer)GETPROP(ctx,2,local+13); /*get*/
	if (w!=NIL) goto IF1185;
	local[13]= local[6];
	local[14]= local[10];
	local[15]= argv[1];
	local[16]= fqv[100];
	ctx->vsp=local+17;
	w=(pointer)GETPROP(ctx,2,local+15); /*get*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(*ftab[42])(ctx,2,local+14,&ftab[42],fqv[110]); /*position*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	local[14]= local[10];
	local[15]= fqv[15];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,2,local+14); /*send*/
	local[14]= w;
	local[15]= local[10];
	local[16]= fqv[14];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
	local[16]= local[10];
	local[17]= fqv[111];
	ctx->vsp=local+18;
	w=(pointer)GETPROP(ctx,2,local+16); /*get*/
	local[16]= w;
	if (w!=NIL) goto OR1187;
	local[16]= makeint((eusinteger_t)256L);
OR1187:
	local[17]= local[10];
	local[18]= fqv[112];
	ctx->vsp=local+19;
	w=(pointer)GETPROP(ctx,2,local+17); /*get*/
	local[17]= w;
	if (w!=NIL) goto OR1188;
	local[17]= makeint((eusinteger_t)256L);
OR1188:
	local[18]= makeint((eusinteger_t)1L);
	local[19]= local[14];
	local[20]= makeint((eusinteger_t)2L);
	ctx->vsp=local+21;
	w=(pointer)LOG(ctx,2,local+19); /*log*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)CEILING(ctx,1,local+19); /*ceiling*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)ASH(ctx,2,local+18); /*ash*/
	local[18]= w;
	local[19]= makeint((eusinteger_t)1L);
	local[20]= local[15];
	local[21]= makeint((eusinteger_t)2L);
	ctx->vsp=local+22;
	w=(pointer)LOG(ctx,2,local+20); /*log*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)CEILING(ctx,1,local+20); /*ceiling*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)ASH(ctx,2,local+19); /*ash*/
	local[19]= w;
	local[20]= local[10];
	local[21]= local[14];
	local[22]= local[18];
	ctx->vsp=local+23;
	w=(pointer)NUMEQUAL(ctx,2,local+21); /*=*/
	if (w==NIL) goto AND1191;
	local[21]= local[15];
	local[22]= local[19];
	ctx->vsp=local+23;
	w=(pointer)NUMEQUAL(ctx,2,local+21); /*=*/
	if (w==NIL) goto AND1191;
	goto IF1189;
AND1191:
	local[21]= NIL;
	local[22]= NIL;
	local[23]= local[20];
	local[24]= fqv[113];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,2,local+23); /*send*/
	local[23]= w;
	local[24]= NIL;
	local[25]= local[12];
	local[26]= makeint((eusinteger_t)6407L);
	ctx->vsp=local+27;
	w=(pointer)NUMEQUAL(ctx,2,local+25); /*=*/
	if (w==NIL) goto CON1193;
	local[25]= local[20];
	local[26]= fqv[114];
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,2,local+25); /*send*/
	local[25]= w;
	local[26]= makeint((eusinteger_t)8L);
	ctx->vsp=local+27;
	w=(pointer)QUOTIENT(ctx,2,local+25); /*/*/
	local[22] = w;
	local[25]= local[22];
	local[26]= makeint((eusinteger_t)3L);
	ctx->vsp=local+27;
	w=(pointer)NUMEQUAL(ctx,2,local+25); /*=*/
	if (w!=NIL) goto IF1194;
	local[25]= fqv[115];
	ctx->vsp=local+26;
	w=(pointer)SIGERROR(ctx,1,local+25); /*error*/
	local[25]= w;
	goto IF1195;
IF1194:
	local[25]= NIL;
IF1195:
	goto CON1192;
CON1193:
	local[25]= local[12];
	local[26]= makeint((eusinteger_t)6409L);
	ctx->vsp=local+27;
	w=(pointer)NUMEQUAL(ctx,2,local+25); /*=*/
	if (w==NIL) goto CON1196;
	local[22] = makeint((eusinteger_t)1L);
	local[25]= local[22];
	goto CON1192;
CON1196:
	local[25]= fqv[116];
	local[26]= local[12];
	local[27]= local[20];
	ctx->vsp=local+28;
	w=(pointer)SIGERROR(ctx,3,local+25); /*error*/
	local[25]= w;
	goto CON1192;
CON1197:
	local[25]= NIL;
CON1192:
	local[25]= local[18];
	local[26]= local[19];
	ctx->vsp=local+27;
	w=(pointer)TIMES(ctx,2,local+25); /***/
	local[25]= w;
	local[26]= local[16];
	local[27]= local[17];
	ctx->vsp=local+28;
	w=(pointer)TIMES(ctx,2,local+26); /***/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)QUOTIENT(ctx,2,local+25); /*/*/
	local[25]= w;
	ctx->vsp=local+26;
	w=(pointer)SQRT(ctx,1,local+25); /*sqrt*/
	local[25]= w;
	ctx->vsp=local+26;
	w=(pointer)ROUND(ctx,1,local+25); /*round*/
	local[24] = w;
	local[25]= local[24];
	w = makeint((eusinteger_t)1L);
	if ((eusinteger_t)local[25] <= (eusinteger_t)w) goto IF1198;
	local[25]= makeint((eusinteger_t)1L);
	local[26]= local[18];
	local[27]= local[24];
	ctx->vsp=local+28;
	w=(pointer)QUOTIENT(ctx,2,local+26); /*/*/
	local[26]= w;
	local[27]= makeint((eusinteger_t)2L);
	ctx->vsp=local+28;
	w=(pointer)LOG(ctx,2,local+26); /*log*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)CEILING(ctx,1,local+26); /*ceiling*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)ASH(ctx,2,local+25); /*ash*/
	local[18] = w;
	local[25]= makeint((eusinteger_t)1L);
	local[26]= local[19];
	local[27]= local[24];
	ctx->vsp=local+28;
	w=(pointer)QUOTIENT(ctx,2,local+26); /*/*/
	local[26]= w;
	local[27]= makeint((eusinteger_t)2L);
	ctx->vsp=local+28;
	w=(pointer)LOG(ctx,2,local+26); /*log*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)CEILING(ctx,1,local+26); /*ceiling*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)ASH(ctx,2,local+25); /*ash*/
	local[19] = w;
	local[25]= local[19];
	goto IF1199;
IF1198:
	local[25]= NIL;
IF1199:
	local[25]= local[18];
	local[26]= local[19];
	local[27]= local[22];
	ctx->vsp=local+28;
	w=(pointer)TIMES(ctx,3,local+25); /***/
	local[25]= w;
	ctx->vsp=local+26;
	w=(*ftab[15])(ctx,1,local+25,&ftab[15],fqv[43]); /*make-string*/
	local[21] = w;
	local[25]= local[12];
	local[26]= local[14];
	local[27]= local[15];
	local[28]= makeint((eusinteger_t)5121L);
	local[29]= local[20];
	local[30]= fqv[17];
	ctx->vsp=local+31;
	w=(pointer)SEND(ctx,2,local+29); /*send*/
	local[29]= w;
	local[30]= local[18];
	local[31]= local[19];
	local[32]= makeint((eusinteger_t)5121L);
	local[33]= local[21];
	ctx->vsp=local+34;
	w=(*ftab[43])(ctx,9,local+25,&ftab[43],fqv[117]); /*gluscaleimage*/
	local[25]= local[20];
	ctx->vsp=local+26;
	w=(pointer)GETCLASS(ctx,1,local+25); /*class*/
	local[25]= w;
	ctx->vsp=local+26;
	w=(pointer)INSTANTIATE(ctx,1,local+25); /*instantiate*/
	local[25]= w;
	local[26]= local[25];
	local[27]= fqv[45];
	local[28]= local[18];
	local[29]= local[19];
	local[30]= local[21];
	ctx->vsp=local+31;
	w=(pointer)SEND(ctx,5,local+26); /*send*/
	w = local[25];
	local[20] = w;
	local[25]= local[20];
	local[26]= fqv[113];
	local[27]= local[23];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,3,local+25); /*send*/
	local[21]= w;
	goto IF1190;
IF1189:
	local[21]= NIL;
IF1190:
	local[21]= makeint((eusinteger_t)3553L);
	local[22]= local[13];
	ctx->vsp=local+23;
	w=(*ftab[44])(ctx,2,local+21,&ftab[44],fqv[118]); /*glbindtextureext*/
	local[21]= makeint((eusinteger_t)3553L);
	local[22]= makeint((eusinteger_t)0L);
	local[23]= makeint((eusinteger_t)6407L);
	local[24]= local[20];
	local[25]= fqv[15];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,2,local+24); /*send*/
	local[24]= w;
	local[25]= local[20];
	local[26]= fqv[14];
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,2,local+25); /*send*/
	local[25]= w;
	local[26]= makeint((eusinteger_t)0L);
	local[27]= local[12];
	local[28]= makeint((eusinteger_t)5121L);
	local[29]= local[20];
	local[30]= fqv[17];
	ctx->vsp=local+31;
	w=(pointer)SEND(ctx,2,local+29); /*send*/
	local[29]= w;
	ctx->vsp=local+30;
	w=(*ftab[45])(ctx,9,local+21,&ftab[45],fqv[119]); /*glteximage2d*/
	local[21]= local[10];
	local[22]= local[13];
	local[23]= fqv[109];
	ctx->vsp=local+24;
	w=(pointer)PUTPROP(ctx,3,local+21); /*putprop*/
	local[13]= w;
	goto IF1186;
IF1185:
	local[13]= NIL;
IF1186:
	local[13]= makeint((eusinteger_t)3317L);
	local[14]= makeint((eusinteger_t)1L);
	ctx->vsp=local+15;
	w=(*ftab[17])(ctx,2,local+13,&ftab[17],fqv[47]); /*glpixelstorei*/
	local[13]= makeint((eusinteger_t)3553L);
	local[14]= makeint((eusinteger_t)10242L);
	local[15]= makeint((eusinteger_t)10497L);
	ctx->vsp=local+16;
	w=(*ftab[46])(ctx,3,local+13,&ftab[46],fqv[120]); /*gltexparameteri*/
	local[13]= makeint((eusinteger_t)3553L);
	local[14]= makeint((eusinteger_t)10243L);
	local[15]= makeint((eusinteger_t)10497L);
	ctx->vsp=local+16;
	w=(*ftab[46])(ctx,3,local+13,&ftab[46],fqv[120]); /*gltexparameteri*/
	local[13]= makeint((eusinteger_t)3553L);
	local[14]= makeint((eusinteger_t)10241L);
	local[15]= makeint((eusinteger_t)9728L);
	ctx->vsp=local+16;
	w=(*ftab[46])(ctx,3,local+13,&ftab[46],fqv[120]); /*gltexparameteri*/
	local[13]= makeint((eusinteger_t)3553L);
	local[14]= makeint((eusinteger_t)10240L);
	local[15]= makeint((eusinteger_t)9728L);
	ctx->vsp=local+16;
	w=(*ftab[46])(ctx,3,local+13,&ftab[46],fqv[120]); /*gltexparameteri*/
	local[13]= makeint((eusinteger_t)8960L);
	local[14]= makeint((eusinteger_t)8704L);
	local[15]= makeint((eusinteger_t)8449L);
	ctx->vsp=local+16;
	w=(*ftab[47])(ctx,3,local+13,&ftab[47],fqv[121]); /*gltexenvi*/
	local[13]= makeint((eusinteger_t)3553L);
	ctx->vsp=local+14;
	w=(*ftab[12])(ctx,1,local+13,&ftab[12],fqv[29]); /*glenable*/
	local[13]= makeint((eusinteger_t)3553L);
	local[14]= local[10];
	local[15]= fqv[109];
	ctx->vsp=local+16;
	w=(pointer)GETPROP(ctx,2,local+14); /*get*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(*ftab[44])(ctx,2,local+13,&ftab[44],fqv[118]); /*glbindtextureext*/
	local[13]= w;
	goto IF1184;
IF1183:
	local[13]= NIL;
IF1184:
	local[13]= makeint((eusinteger_t)9L);
	ctx->vsp=local+14;
	w=(*ftab[9])(ctx,1,local+13,&ftab[9],fqv[26]); /*glbegin*/
	local[13]= argv[1];
	local[14]= fqv[93];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)TRANSPOSE(ctx,1,local+13); /*transpose*/
	local[13]= w;
	local[14]= local[8];
	local[15]= fqv[94];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,2,local+14); /*send*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)TRANSFORM(ctx,2,local+13); /*transform*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(*ftab[36])(ctx,1,local+13,&ftab[36],fqv[95]); /*glnormal3fv*/
	local[13]= NIL;
	local[14]= local[8];
	local[15]= fqv[96];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,2,local+14); /*send*/
	local[14]= w;
WHL1202:
	if (local[14]==NIL) goto WHX1203;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14] = (w)->c.cons.cdr;
	w = local[15];
	local[13] = w;
	if (local[11]==NIL) goto IF1206;
	local[15]= local[13];
	local[16]= local[11];
	ctx->vsp=local+17;
	w=(*ftab[48])(ctx,2,local+15,&ftab[48],fqv[122]); /*gethash*/
	local[7] = w;
	if (local[7]==NIL) goto IF1206;
	local[15]= local[7];
	ctx->vsp=local+16;
	w=(*ftab[49])(ctx,1,local+15,&ftab[49],fqv[123]); /*gltexcoord2fv*/
	local[15]= w;
	goto IF1207;
IF1206:
	local[15]= NIL;
IF1207:
	local[15]= argv[1];
	local[16]= fqv[88];
	local[17]= local[13];
	local[18]= fqv[97];
	local[19]= local[8];
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,3,local+17); /*send*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,3,local+15); /*send*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(*ftab[10])(ctx,1,local+15,&ftab[10],fqv[27]); /*glvertex3fv*/
	goto WHL1202;
WHX1203:
	local[15]= NIL;
BLK1204:
	w = NIL;
	ctx->vsp=local+13;
	w=(*ftab[11])(ctx,0,local+13,&ftab[11],fqv[28]); /*glend*/
	if (local[10]==NIL) goto IF1208;
	local[13]= makeint((eusinteger_t)3553L);
	ctx->vsp=local+14;
	w=(*ftab[8])(ctx,1,local+13,&ftab[8],fqv[25]); /*gldisable*/
	local[13]= makeint((eusinteger_t)3553L);
	local[14]= makeint((eusinteger_t)0L);
	ctx->vsp=local+15;
	w=(*ftab[44])(ctx,2,local+13,&ftab[44],fqv[118]); /*glbindtextureext*/
	local[13]= w;
	goto IF1209;
IF1208:
	local[13]= NIL;
IF1209:
	w = local[13];
	local[10]= w;
	goto CON1178;
CON1179:
	local[10]= local[8];
	local[11]= fqv[106];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	local[11]= NIL;
	ctx->vsp=local+12;
	local[12]= makeclosure(codevec,quotevec,CLO1211,env,argv,local);
	local[13]= local[8];
	local[14]= fqv[87];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.cdr;
	ctx->vsp=local+14;
	w=(pointer)MAPCAR(ctx,2,local+12); /*mapcar*/
	local[11] = w;
	local[12]= loadglobal(fqv[124]);
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(*ftab[50])(ctx,2,local+12,&ftab[50],fqv[125]); /*glutessbeginpolygon*/
	local[12]= loadglobal(fqv[124]);
	ctx->vsp=local+13;
	w=(*ftab[51])(ctx,1,local+12,&ftab[51],fqv[126]); /*glutessbegincontour*/
	local[12]= local[8];
	local[13]= fqv[94];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(*ftab[36])(ctx,1,local+12,&ftab[36],fqv[95]); /*glnormal3fv*/
	ctx->vsp=local+12;
	local[12]= makeclosure(codevec,quotevec,CLO1212,env,argv,local);
	local[13]= local[11];
	ctx->vsp=local+14;
	w=(pointer)MAPC(ctx,2,local+12); /*mapc*/
	local[12]= loadglobal(fqv[124]);
	ctx->vsp=local+13;
	w=(*ftab[52])(ctx,1,local+12,&ftab[52],fqv[127]); /*glutessendcontour*/
	local[12]= loadglobal(fqv[124]);
	ctx->vsp=local+13;
	w=(*ftab[51])(ctx,1,local+12,&ftab[51],fqv[126]); /*glutessbegincontour*/
	if (local[10]==NIL) goto IF1213;
	local[12]= NIL;
	local[13]= local[10];
	w = local[12];
	ctx->vsp=local+14;
	bindspecial(ctx,fqv[128],w);
WHL1216:
	if (local[13]==NIL) goto WHX1217;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17]= (w)->c.cons.car;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13] = (w)->c.cons.cdr;
	w = local[17];
	local[17]= w;
	storeglobal(fqv[128],w);
	ctx->vsp=local+17;
	local[17]= makeclosure(codevec,quotevec,CLO1220,env,argv,local);
	local[18]= loadglobal(fqv[128]);
	local[19]= fqv[87];
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,2,local+18); /*send*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)MAPCAR(ctx,2,local+17); /*mapcar*/
	local[17]= w;
	local[18]= loadglobal(fqv[124]);
	local[19]= makeint((eusinteger_t)100122L);
	ctx->vsp=local+20;
	w=(*ftab[53])(ctx,2,local+18,&ftab[53],fqv[129]); /*glunextcontour*/
	ctx->vsp=local+18;
	local[18]= makeclosure(codevec,quotevec,CLO1221,env,argv,local);
	local[19]= local[17];
	ctx->vsp=local+20;
	w=(pointer)MAPC(ctx,2,local+18); /*mapc*/
	local[18]= local[11];
	local[19]= local[17];
	ctx->vsp=local+20;
	w=(pointer)NCONC(ctx,2,local+18); /*nconc*/
	goto WHL1216;
WHX1217:
	local[17]= NIL;
BLK1218:
	local[17]= NIL;
	ctx->vsp=local+18;
	unbindx(ctx,1);
	w = local[17];
	local[12]= w;
	goto IF1214;
IF1213:
	local[12]= NIL;
IF1214:
	local[12]= loadglobal(fqv[124]);
	ctx->vsp=local+13;
	w=(*ftab[52])(ctx,1,local+12,&ftab[52],fqv[127]); /*glutessendcontour*/
	local[12]= loadglobal(fqv[124]);
	ctx->vsp=local+13;
	w=(*ftab[54])(ctx,1,local+12,&ftab[54],fqv[130]); /*glutessendpolygon*/
	local[12]= (pointer)get_sym_func(fqv[131]);
	local[13]= local[11];
	ctx->vsp=local+14;
	w=(pointer)MAPC(ctx,2,local+12); /*mapc*/
	local[10]= w;
	goto CON1178;
CON1210:
	local[10]= NIL;
CON1178:
	goto WHL1174;
WHX1175:
	local[10]= NIL;
BLK1176:
	w = NIL;
	if (local[5]==NIL) goto IF1222;
	local[8]= makeint((eusinteger_t)3042L);
	ctx->vsp=local+9;
	w=(*ftab[8])(ctx,1,local+8,&ftab[8],fqv[25]); /*gldisable*/
	local[8]= w;
	goto IF1223;
IF1222:
	local[8]= NIL;
IF1223:
	ctx->vsp=local+8;
	w=(*ftab[38])(ctx,0,local+8,&ftab[38],fqv[99]); /*glendlist*/
	local[8]= argv[1];
	local[9]= local[0];
	w = local[4];
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= argv[1];
	local[11]= fqv[71];
	ctx->vsp=local+12;
	w=(pointer)GETPROP(ctx,2,local+10); /*get*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[71];
	ctx->vsp=local+11;
	w=(pointer)PUTPROP(ctx,3,local+8); /*putprop*/
	local[8]= argv[0];
	local[9]= argv[1];
	ctx->vsp=local+10;
	w=(pointer)F981draw_glbody(ctx,2,local+8); /*draw-glbody*/
	local[4]= w;
	goto CON1142;
CON1165:
	local[4]= NIL;
CON1142:
	w = local[4];
	local[0]= w;
BLK1137:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1211(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[1];
	local[1]= fqv[88];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	argv[0] = w;
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)0L);
	local[2]= NIL;
	local[3]= makeint((eusinteger_t)0L);
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(*ftab[55])(ctx,5,local+0,&ftab[55],fqv[132]); /*alloctessinfo*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1212(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[124]);
	local[1]= argv[0];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[56])(ctx,3,local+0,&ftab[56],fqv[133]); /*glutessvertex*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1220(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[1];
	local[1]= fqv[88];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	argv[0] = w;
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)0L);
	local[2]= NIL;
	local[3]= makeint((eusinteger_t)0L);
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(*ftab[55])(ctx,5,local+0,&ftab[55],fqv[132]); /*alloctessinfo*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1221(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[124]);
	local[1]= argv[0];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[56])(ctx,3,local+0,&ftab[56],fqv[133]); /*glutessvertex*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*find-color*/
static pointer F982find_color(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	if (argv[0]!=NIL) goto CON1226;
	local[2]= NIL;
	goto CON1225;
CON1226:
	local[2]= argv[0];
	local[3]= loadglobal(fqv[134]);
	ctx->vsp=local+4;
	w=(pointer)DERIVEDP(ctx,2,local+2); /*derivedp*/
	if (w==NIL) goto CON1227;
	local[2]= argv[0];
	local[3]= fqv[135];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	goto CON1225;
CON1227:
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)VECTORP(ctx,1,local+2); /*vectorp*/
	if (w==NIL) goto CON1228;
	local[2]= argv[0];
	goto CON1225;
CON1228:
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LISTP(ctx,1,local+2); /*listp*/
	if (w==NIL) goto CON1229;
	local[2]= argv[0];
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	local[3]= makeflt(2.5500000000000000000000e+02);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	local[4]= makeflt(2.5500000000000000000000e+02);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= makeint((eusinteger_t)2L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	local[5]= makeflt(2.5500000000000000000000e+02);
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	goto CON1225;
CON1229:
	w = argv[0];
	if (!issymbol(w)) goto CON1230;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO1231,env,argv,local);
	local[3]= loadglobal(fqv[136]);
	ctx->vsp=local+4;
	w=(*ftab[57])(ctx,2,local+2,&ftab[57],fqv[137]); /*find-if*/
	local[1] = w;
	if (local[1]==NIL) goto IF1232;
	local[2]= local[1];
	local[3]= fqv[135];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	goto IF1233;
IF1232:
	local[2]= fqv[138];
	ctx->vsp=local+3;
	w=(*ftab[24])(ctx,1,local+2,&ftab[24],fqv[70]); /*warn*/
	local[2]= w;
IF1233:
	goto CON1225;
CON1230:
	local[2]= argv[0];
	goto CON1225;
CON1234:
	local[2]= NIL;
CON1225:
	local[0] = local[2];
	if (local[0]!=NIL) goto IF1235;
	local[2]= makeflt(5.0000000000000000000000e-01);
	local[3]= makeflt(5.0000000000000000000000e-01);
	local[4]= makeflt(5.0000000000000000000000e-01);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[0] = w;
	local[2]= local[0];
	goto IF1236;
IF1235:
	local[2]= NIL;
IF1236:
	w = local[0];
	local[0]= w;
BLK1224:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1231(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[113];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	w = ((env->c.clo.env1[0])==(local[0])?T:NIL);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*transparent*/
static pointer F983transparent(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= fqv[73];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[0] = w;
	if (local[0]==NIL) goto IF1238;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)VECTORP(ctx,1,local+2); /*vectorp*/
	if (w!=NIL) goto IF1240;
	local[2]= fqv[139];
	local[3]= argv[0];
	local[4]= argv[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[24])(ctx,4,local+2,&ftab[24],fqv[70]); /*warn*/
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F982find_color(ctx,1,local+2); /*find-color*/
	local[0] = w;
	local[2]= local[0];
	goto IF1241;
IF1240:
	local[2]= NIL;
IF1241:
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	if (makeint((eusinteger_t)3L)!=local[2]) goto IF1242;
	local[2]= loadglobal(fqv[140]);
	local[3]= local[0];
	local[4]= fqv[141];
	ctx->vsp=local+5;
	w=(pointer)CONCATENATE(ctx,3,local+2); /*concatenate*/
	local[0] = w;
	local[2]= local[0];
	goto IF1243;
IF1242:
	local[2]= NIL;
IF1243:
	local[2]= local[0];
	local[3]= makeint((eusinteger_t)3L);
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)SETELT(ctx,3,local+2); /*setelt*/
	local[2]= argv[0];
	local[3]= local[0];
	local[4]= fqv[73];
	ctx->vsp=local+5;
	w=(pointer)PUTPROP(ctx,3,local+2); /*putprop*/
	local[2]= argv[0];
	local[3]= fqv[71];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F978delete_displaylist_id(ctx,1,local+2); /*delete-displaylist-id*/
	local[2]= argv[0];
	local[3]= NIL;
	local[4]= fqv[71];
	ctx->vsp=local+5;
	w=(pointer)PUTPROP(ctx,3,local+2); /*putprop*/
	local[2]= local[0];
	goto IF1239;
IF1238:
	local[2]= NIL;
IF1239:
	w = local[2];
	local[0]= w;
BLK1237:
	ctx->vsp=local; return(local[0]);}

/*:draw-on*/
static pointer M1244polygon_draw_on(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[142], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY1246;
	local[0] = loadglobal(fqv[143]);
KEY1246:
	if (n & (1<<1)) goto KEY1247;
	local[1] = NIL;
KEY1247:
	if (n & (1<<2)) goto KEY1248;
	local[2] = makeint((eusinteger_t)1L);
KEY1248:
	if (n & (1<<3)) goto KEY1249;
	local[3] = fqv[144];
KEY1249:
	if (local[1]==NIL) goto IF1250;
	local[4]= local[0];
	local[5]= fqv[8];
	local[6]= fqv[9];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF1251;
IF1250:
	local[4]= NIL;
IF1251:
	local[4]= local[0];
	local[5]= fqv[8];
	local[6]= fqv[145];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= local[0];
	local[6]= fqv[8];
	local[7]= fqv[56];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	local[6]= makeint((eusinteger_t)0L);
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,3,local+6); /*float-vector*/
	local[6]= w;
	local[7]= local[0];
	local[8]= fqv[8];
	local[9]= fqv[145];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[7]= local[0];
	local[8]= fqv[8];
	local[9]= fqv[56];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[7]= local[0];
	local[8]= fqv[8];
	local[9]= fqv[146];
	local[10]= argv[0];
	local[11]= fqv[87];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[7]= local[0];
	local[8]= fqv[8];
	local[9]= fqv[145];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[7]= local[0];
	local[8]= fqv[8];
	local[9]= fqv[56];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	if (local[1]==NIL) goto IF1252;
	local[7]= local[0];
	local[8]= fqv[8];
	local[9]= fqv[34];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	goto IF1253;
IF1252:
	local[7]= NIL;
IF1253:
	w = local[7];
	local[0]= w;
BLK1245:
	ctx->vsp=local; return(local[0]);}

/*:draw-on*/
static pointer M1254line_draw_on(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[147], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY1256;
	local[0] = loadglobal(fqv[143]);
KEY1256:
	if (n & (1<<1)) goto KEY1257;
	local[1] = NIL;
KEY1257:
	if (n & (1<<2)) goto KEY1258;
	local[2] = makeint((eusinteger_t)1L);
KEY1258:
	if (n & (1<<3)) goto KEY1259;
	local[3] = fqv[148];
KEY1259:
	if (local[1]==NIL) goto IF1260;
	local[4]= local[0];
	local[5]= fqv[8];
	local[6]= fqv[9];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF1261;
IF1260:
	local[4]= NIL;
IF1261:
	local[4]= local[0];
	local[5]= fqv[8];
	local[6]= fqv[145];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= local[0];
	local[6]= fqv[8];
	local[7]= fqv[56];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	local[6]= makeint((eusinteger_t)0L);
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,3,local+6); /*float-vector*/
	local[6]= w;
	local[7]= local[0];
	local[8]= fqv[8];
	local[9]= fqv[145];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[7]= local[0];
	local[8]= fqv[8];
	local[9]= fqv[56];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[7]= local[0];
	local[8]= fqv[8];
	local[9]= fqv[149];
	local[10]= argv[0]->c.obj.iv[1];
	local[11]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	local[7]= local[0];
	local[8]= fqv[8];
	local[9]= fqv[145];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[7]= local[0];
	local[8]= fqv[8];
	local[9]= fqv[56];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	if (local[1]==NIL) goto IF1262;
	local[7]= local[0];
	local[8]= fqv[8];
	local[9]= fqv[34];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	goto IF1263;
IF1262:
	local[7]= NIL;
IF1263:
	w = local[7];
	local[0]= w;
BLK1255:
	ctx->vsp=local; return(local[0]);}

/*:set-color*/
static pointer M1264faceset_set_color(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1267;}
	local[0]= NIL;
ENT1267:
ENT1266:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[71];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F978delete_displaylist_id(ctx,1,local+1); /*delete-displaylist-id*/
	local[1]= argv[0];
	local[2]= NIL;
	local[3]= fqv[71];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	if (local[0]==NIL) goto CON1269;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F982find_color(ctx,1,local+1); /*find-color*/
	local[1]= w;
	local[2]= loadglobal(fqv[140]);
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,1,local+4); /*float-vector*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)CONCATENATE(ctx,3,local+2); /*concatenate*/
	local[1] = w;
	local[2]= argv[0];
	local[3]= local[1];
	local[4]= fqv[73];
	ctx->vsp=local+5;
	w=(pointer)PUTPROP(ctx,3,local+2); /*putprop*/
	local[1]= w;
	goto CON1268;
CON1269:
	local[1]= argv[0];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)F982find_color(ctx,1,local+2); /*find-color*/
	local[2]= w;
	local[3]= fqv[73];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= w;
	goto CON1268;
CON1270:
	local[1]= NIL;
CON1268:
	w = local[1];
	local[0]= w;
BLK1265:
	ctx->vsp=local; return(local[0]);}

/*:draw-on*/
static pointer M1271faceset_draw_on(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[150], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY1273;
	local[0] = loadglobal(fqv[143]);
KEY1273:
	if (n & (1<<1)) goto KEY1274;
	local[1] = NIL;
KEY1274:
	if (n & (1<<2)) goto KEY1275;
	local[2] = makeint((eusinteger_t)1L);
KEY1275:
	if (n & (1<<3)) goto KEY1276;
	local[3] = fqv[151];
KEY1276:
	if (local[1]==NIL) goto IF1277;
	local[4]= local[0];
	local[5]= fqv[8];
	local[6]= fqv[9];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF1278;
IF1277:
	local[4]= NIL;
IF1278:
	local[4]= local[0];
	local[5]= fqv[8];
	local[6]= fqv[145];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= local[0];
	local[6]= fqv[8];
	local[7]= fqv[56];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	local[6]= local[0];
	local[7]= fqv[8];
	local[8]= fqv[145];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[6]= local[0];
	local[7]= fqv[8];
	local[8]= fqv[56];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[6]= NIL;
	local[7]= argv[0];
	local[8]= fqv[86];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
WHL1280:
	if (local[7]==NIL) goto WHX1281;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[0];
	local[9]= fqv[8];
	local[10]= fqv[146];
	local[11]= local[6];
	local[12]= fqv[87];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	goto WHL1280;
WHX1281:
	local[8]= NIL;
BLK1282:
	w = NIL;
	local[6]= local[0];
	local[7]= fqv[8];
	local[8]= fqv[145];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[6]= local[0];
	local[7]= fqv[8];
	local[8]= fqv[56];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	if (local[1]==NIL) goto IF1284;
	local[6]= local[0];
	local[7]= fqv[8];
	local[8]= fqv[34];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	goto IF1285;
IF1284:
	local[6]= NIL;
IF1285:
	w = local[6];
	local[0]= w;
BLK1272:
	ctx->vsp=local; return(local[0]);}

/*:paste-texture-to-face*/
static pointer M1286faceset_paste_texture_to_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[152], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY1288;
	local[0] = NIL;
KEY1288:
	if (n & (1<<1)) goto KEY1289;
	local[1] = NIL;
KEY1289:
	if (n & (1<<2)) goto KEY1290;
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,2,local+3); /*float-vector*/
	local[3]= w;
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)1L);
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,2,local+4); /*float-vector*/
	local[4]= w;
	local[5]= makeint((eusinteger_t)1L);
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,2,local+5); /*float-vector*/
	local[5]= w;
	local[6]= makeint((eusinteger_t)1L);
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,2,local+6); /*float-vector*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,4,local+3); /*list*/
	local[2] = w;
KEY1290:
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	if (local[1]==NIL) goto CON1292;
	local[3] = local[1];
	local[9]= local[3];
	goto CON1291;
CON1292:
	local[9]= local[0];
	local[10]= argv[0];
	local[11]= fqv[100];
	ctx->vsp=local+12;
	w=(pointer)GETPROP(ctx,2,local+10); /*get*/
	local[10]= w;
	local[11]= fqv[113];
	ctx->vsp=local+12;
	w=(*ftab[58])(ctx,2,local+10,&ftab[58],fqv[153]); /*send-all*/
	local[10]= w;
	local[11]= fqv[154];
	local[12]= (pointer)get_sym_func(fqv[155]);
	ctx->vsp=local+13;
	w=(*ftab[59])(ctx,4,local+9,&ftab[59],fqv[156]); /*member*/
	if (w==NIL) goto CON1293;
	local[9]= local[0];
	local[10]= argv[0];
	local[11]= fqv[100];
	ctx->vsp=local+12;
	w=(pointer)GETPROP(ctx,2,local+10); /*get*/
	local[10]= w;
	local[11]= fqv[154];
	local[12]= (pointer)get_sym_func(fqv[155]);
	local[13]= fqv[6];
	ctx->vsp=local+14;
	local[14]= makeclosure(codevec,quotevec,CLO1294,env,argv,local);
	ctx->vsp=local+15;
	w=(*ftab[59])(ctx,6,local+9,&ftab[59],fqv[156]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	local[9]= local[3];
	goto CON1291;
CON1293:
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(*ftab[60])(ctx,1,local+9,&ftab[60],fqv[157]); /*probe-file*/
	if (w==NIL) goto CON1295;
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(*ftab[61])(ctx,1,local+9,&ftab[61],fqv[158]); /*user::read-image-file*/
	local[3] = w;
	local[9]= local[3];
	goto CON1291;
CON1295:
	local[9]= NIL;
	local[10]= fqv[159];
	local[11]= loadglobal(fqv[160]);
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,4,local+9); /*format*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[60])(ctx,1,local+9,&ftab[60],fqv[157]); /*probe-file*/
	if (w==NIL) goto CON1296;
	local[9]= NIL;
	local[10]= fqv[161];
	local[11]= loadglobal(fqv[160]);
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,4,local+9); /*format*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[61])(ctx,1,local+9,&ftab[61],fqv[158]); /*user::read-image-file*/
	local[3] = w;
	local[9]= local[3];
	goto CON1291;
CON1296:
	local[9]= NIL;
	local[10]= fqv[162];
	local[11]= loadglobal(fqv[160]);
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,4,local+9); /*format*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[60])(ctx,1,local+9,&ftab[60],fqv[157]); /*probe-file*/
	if (w==NIL) goto CON1297;
	local[9]= NIL;
	local[10]= fqv[163];
	local[11]= loadglobal(fqv[160]);
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,4,local+9); /*format*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[61])(ctx,1,local+9,&ftab[61],fqv[158]); /*user::read-image-file*/
	local[3] = w;
	local[9]= local[3];
	goto CON1291;
CON1297:
	local[9]= fqv[164];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(*ftab[24])(ctx,2,local+9,&ftab[24],fqv[70]); /*warn*/
	w = NIL;
	ctx->vsp=local+9;
	local[0]=w;
	goto BLK1287;
	goto CON1291;
CON1298:
	local[9]= NIL;
CON1291:
	local[9]= argv[2];
	local[10]= local[3];
	local[11]= fqv[100];
	ctx->vsp=local+12;
	w=(pointer)PUTPROP(ctx,3,local+9); /*putprop*/
	local[9]= local[3];
	local[10]= argv[0];
	local[11]= fqv[100];
	ctx->vsp=local+12;
	w=(pointer)GETPROP(ctx,2,local+10); /*get*/
	if (memq(local[9],w)!=NIL) goto IF1299;
	local[9]= argv[0];
	local[10]= argv[0];
	local[11]= fqv[100];
	ctx->vsp=local+12;
	w=(pointer)GETPROP(ctx,2,local+10); /*get*/
	local[10]= w;
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)APPEND(ctx,2,local+10); /*append*/
	local[10]= w;
	local[11]= fqv[100];
	ctx->vsp=local+12;
	w=(pointer)PUTPROP(ctx,3,local+9); /*putprop*/
	local[9]= w;
	goto IF1300;
IF1299:
	local[9]= NIL;
IF1300:
	local[9]= argv[2];
	local[10]= fqv[154];
	local[11]= (pointer)get_sym_func(fqv[155]);
	ctx->vsp=local+12;
	w=(*ftab[62])(ctx,2,local+10,&ftab[62],fqv[165]); /*make-hash-table*/
	local[10]= w;
	local[11]= fqv[107];
	ctx->vsp=local+12;
	w=(pointer)PUTPROP(ctx,3,local+9); /*putprop*/
	local[9]= argv[0];
	local[10]= fqv[71];
	ctx->vsp=local+11;
	w=(pointer)GETPROP(ctx,2,local+9); /*get*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)F978delete_displaylist_id(ctx,1,local+9); /*delete-displaylist-id*/
	local[9]= argv[0];
	local[10]= NIL;
	local[11]= fqv[71];
	ctx->vsp=local+12;
	w=(pointer)PUTPROP(ctx,3,local+9); /*putprop*/
	local[9]= NIL;
	local[10]= argv[2];
	local[11]= fqv[96];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
WHL1302:
	if (local[10]==NIL) goto WHX1303;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	local[11]= local[9];
	local[12]= argv[2];
	local[13]= fqv[107];
	ctx->vsp=local+14;
	w=(pointer)GETPROP(ctx,2,local+12); /*get*/
	local[12]= w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[13];
	local[13]= w;
	ctx->vsp=local+14;
	w=(*ftab[63])(ctx,3,local+11,&ftab[63],fqv[166]); /*sethash*/
	goto WHL1302;
WHX1303:
	local[11]= NIL;
BLK1304:
	w = NIL;
	local[0]= w;
BLK1287:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1294(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[113];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:vertices*/
static pointer M1307coordinates_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[167];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
BLK1308:
	ctx->vsp=local; return(local[0]);}

/*:draw-on*/
static pointer M1309coordinates_draw_on(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[168], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY1311;
	local[0] = loadglobal(fqv[143]);
KEY1311:
	if (n & (1<<1)) goto KEY1312;
	local[1] = NIL;
KEY1312:
	if (n & (1<<2)) goto KEY1313;
	local[5]= argv[0];
	local[6]= fqv[15];
	ctx->vsp=local+7;
	w=(pointer)GETPROP(ctx,2,local+5); /*get*/
	local[2] = w;
KEY1313:
	if (n & (1<<3)) goto KEY1314;
	local[5]= argv[0];
	local[6]= fqv[56];
	ctx->vsp=local+7;
	w=(pointer)GETPROP(ctx,2,local+5); /*get*/
	local[3] = w;
KEY1314:
	if (n & (1<<4)) goto KEY1315;
	local[5]= argv[0];
	local[6]= fqv[169];
	ctx->vsp=local+7;
	w=(pointer)GETPROP(ctx,2,local+5); /*get*/
	local[4] = w;
KEY1315:
	if (local[1]==NIL) goto IF1316;
	local[5]= local[0];
	local[6]= fqv[8];
	local[7]= fqv[9];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF1317;
IF1316:
	local[5]= NIL;
IF1317:
	local[5]= local[0];
	local[6]= fqv[8];
	local[7]= fqv[145];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	local[6]= local[0];
	local[7]= fqv[8];
	local[8]= fqv[56];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,3,local+7); /*float-vector*/
	local[7]= w;
	local[8]= NIL;
	if (local[2]!=NIL) goto IF1318;
	local[2] = makeint((eusinteger_t)1L);
	local[9]= local[2];
	goto IF1319;
IF1318:
	local[9]= NIL;
IF1319:
	if (local[3]!=NIL) goto IF1320;
	local[3] = fqv[170];
	local[9]= local[3];
	goto IF1321;
IF1320:
	local[9]= NIL;
IF1321:
	if (local[4]!=NIL) goto IF1322;
	local[4] = makeint((eusinteger_t)50L);
	local[9]= local[4];
	goto IF1323;
IF1322:
	local[9]= NIL;
IF1323:
	local[9]= makeflt(2.9999999999999982236432e-01);
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	local[10]= makeint((eusinteger_t)0L);
	local[11]= makeflt(6.9999999999999973354647e-01);
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)MKFLTVEC(ctx,3,local+9); /*float-vector*/
	local[8] = w;
	local[9]= local[0];
	local[10]= fqv[8];
	local[11]= fqv[145];
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,4,local+9); /*send*/
	local[9]= local[0];
	local[10]= fqv[8];
	local[11]= fqv[56];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,4,local+9); /*send*/
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)3L);
WHL1325:
	local[11]= local[9];
	w = local[10];
	if ((eusinteger_t)local[11] >= (eusinteger_t)w) goto WHX1326;
	local[11]= local[7];
	local[12]= local[9];
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)SETELT(ctx,3,local+11); /*setelt*/
	local[11]= local[0];
	local[12]= fqv[8];
	local[13]= fqv[149];
	local[14]= argv[0];
	local[15]= fqv[167];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,2,local+14); /*send*/
	local[14]= w;
	local[15]= argv[0];
	local[16]= fqv[171];
	local[17]= local[7];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,3,local+15); /*send*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,5,local+11); /*send*/
	local[11]= local[7];
	local[12]= local[9];
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(pointer)SETELT(ctx,3,local+11); /*setelt*/
	local[11]= local[9];
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[9] = w;
	goto WHL1325;
WHX1326:
	local[11]= NIL;
BLK1327:
	w = NIL;
	local[9]= local[7];
	local[10]= makeint((eusinteger_t)2L);
	local[11]= local[4];
	ctx->vsp=local+12;
	w=(pointer)SETELT(ctx,3,local+9); /*setelt*/
	local[9]= local[0];
	local[10]= fqv[8];
	local[11]= fqv[149];
	local[12]= argv[0];
	local[13]= fqv[171];
	local[14]= local[7];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[12]= w;
	local[13]= argv[0];
	local[14]= fqv[171];
	local[15]= local[8];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,5,local+9); /*send*/
	local[9]= local[8];
	local[10]= makeint((eusinteger_t)1L);
	local[11]= local[8];
	local[12]= makeint((eusinteger_t)0L);
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)SETELT(ctx,3,local+9); /*setelt*/
	local[9]= local[8];
	local[10]= makeint((eusinteger_t)0L);
	local[11]= makeint((eusinteger_t)0L);
	ctx->vsp=local+12;
	w=(pointer)SETELT(ctx,3,local+9); /*setelt*/
	local[9]= local[0];
	local[10]= fqv[8];
	local[11]= fqv[149];
	local[12]= argv[0];
	local[13]= fqv[171];
	local[14]= local[7];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[12]= w;
	local[13]= argv[0];
	local[14]= fqv[171];
	local[15]= local[8];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,5,local+9); /*send*/
	local[9]= local[0];
	local[10]= fqv[8];
	local[11]= fqv[145];
	local[12]= local[5];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,4,local+9); /*send*/
	local[9]= local[0];
	local[10]= fqv[8];
	local[11]= fqv[56];
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,4,local+9); /*send*/
	if (local[1]==NIL) goto IF1328;
	local[9]= local[0];
	local[10]= fqv[8];
	local[11]= fqv[34];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= w;
	goto IF1329;
IF1328:
	local[9]= NIL;
IF1329:
	w = local[9];
	local[0]= w;
BLK1310:
	ctx->vsp=local; return(local[0]);}

/*:vertices*/
static pointer M1330float_vector_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
BLK1331:
	ctx->vsp=local; return(local[0]);}

/*:draw-on*/
static pointer M1332float_vector_draw_on(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[172], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY1334;
	local[0] = loadglobal(fqv[143]);
KEY1334:
	if (n & (1<<1)) goto KEY1335;
	local[1] = NIL;
KEY1335:
	if (n & (1<<2)) goto KEY1336;
	local[2] = makeint((eusinteger_t)1L);
KEY1336:
	if (n & (1<<3)) goto KEY1337;
	local[3] = fqv[173];
KEY1337:
	if (n & (1<<4)) goto KEY1338;
	local[4] = makeint((eusinteger_t)50L);
KEY1338:
	if (local[1]==NIL) goto IF1339;
	local[5]= local[0];
	local[6]= fqv[8];
	local[7]= fqv[9];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF1340;
IF1339:
	local[5]= NIL;
IF1340:
	local[5]= local[0];
	local[6]= fqv[8];
	local[7]= fqv[145];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	local[6]= local[0];
	local[7]= fqv[8];
	local[8]= fqv[56];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,3,local+7); /*float-vector*/
	local[7]= w;
	local[8]= local[0];
	local[9]= fqv[8];
	local[10]= fqv[145];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= local[0];
	local[9]= fqv[8];
	local[10]= fqv[56];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)3L);
WHL1342:
	local[10]= local[8];
	w = local[9];
	if ((eusinteger_t)local[10] >= (eusinteger_t)w) goto WHX1343;
	local[10]= local[7];
	local[11]= local[8];
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(pointer)SETELT(ctx,3,local+10); /*setelt*/
	local[10]= local[0];
	local[11]= fqv[8];
	local[12]= fqv[149];
	local[13]= argv[0];
	local[14]= argv[0];
	local[15]= local[7];
	ctx->vsp=local+16;
	w=(pointer)VPLUS(ctx,2,local+14); /*v+*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,5,local+10); /*send*/
	local[10]= local[7];
	local[11]= local[8];
	local[12]= makeint((eusinteger_t)0L);
	ctx->vsp=local+13;
	w=(pointer)SETELT(ctx,3,local+10); /*setelt*/
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[8] = w;
	goto WHL1342;
WHX1343:
	local[10]= NIL;
BLK1344:
	w = NIL;
	local[8]= local[0];
	local[9]= fqv[8];
	local[10]= fqv[145];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= local[0];
	local[9]= fqv[8];
	local[10]= fqv[56];
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	if (local[1]==NIL) goto IF1345;
	local[8]= local[0];
	local[9]= fqv[8];
	local[10]= fqv[34];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	goto IF1346;
IF1345:
	local[8]= NIL;
IF1346:
	w = local[8];
	local[0]= w;
BLK1333:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1347glvertices_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST1349:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[174], &argv[3], n-3, local+1, 1);
	if (n & (1<<0)) goto KEY1350;
	local[1] = NIL;
KEY1350:
	argv[0]->c.obj.iv[8] = argv[2];
	argv[0]->c.obj.iv[9] = local[1];
	local[2]= (pointer)get_sym_func(fqv[175]);
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[36]));
	local[5]= fqv[45];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,5,local+2); /*apply*/
	w = argv[0];
	local[0]= w;
BLK1348:
	ctx->vsp=local; return(local[0]);}

/*:filename*/
static pointer M1351glvertices_filename(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1354;}
	local[0]= NIL;
ENT1354:
ENT1353:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1355;
	argv[0]->c.obj.iv[9] = local[0];
	local[1]= argv[0]->c.obj.iv[9];
	goto IF1356;
IF1355:
	local[1]= NIL;
IF1356:
	w = argv[0]->c.obj.iv[9];
	local[0]= w;
BLK1352:
	ctx->vsp=local; return(local[0]);}

/*:set-color*/
static pointer M1357glvertices_set_color(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1360;}
	local[0]= NIL;
ENT1360:
ENT1359:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[71];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F978delete_displaylist_id(ctx,1,local+1); /*delete-displaylist-id*/
	local[1]= argv[0];
	local[2]= NIL;
	local[3]= fqv[71];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[176];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	if (argv[2]==NIL) goto IF1361;
	local[1]= argv[0];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)F982find_color(ctx,1,local+2); /*find-color*/
	local[2]= w;
	local[3]= fqv[73];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= w;
	goto IF1362;
IF1361:
	local[1]= argv[0];
	local[2]= NIL;
	local[3]= fqv[73];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= w;
IF1362:
	w = local[1];
	local[0]= w;
BLK1358:
	ctx->vsp=local; return(local[0]);}

/*:get-meshinfo*/
static pointer M1363glvertices_get_meshinfo(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1366;}
	local[0]= makeint((eusinteger_t)-1L);
ENT1366:
ENT1365:
	if (n>4) maerror();
	local[1]= local[0];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto IF1367;
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO1369,env,argv,local);
	local[2]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK1364;
	goto IF1368;
IF1367:
	local[1]= NIL;
IF1368:
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[64])(ctx,2,local+1,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK1364:
	ctx->vsp=local; return(local[0]);}

/*:set-meshinfo*/
static pointer M1370glvertices_set_meshinfo(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT1373;}
	local[0]= makeint((eusinteger_t)-1L);
ENT1373:
ENT1372:
	if (n>5) maerror();
	local[1]= local[0];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto IF1374;
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[8];
WHL1377:
	if (local[2]==NIL) goto WHX1378;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[2];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(*ftab[64])(ctx,2,local+3,&ftab[64],fqv[177]); /*assoc*/
	local[3]= w;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(*ftab[65])(ctx,2,local+3,&ftab[65],fqv[178]); /*delete*/
	local[3]= local[1];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,2,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)NCONC(ctx,2,local+3); /*nconc*/
	goto WHL1377;
WHX1378:
	local[3]= NIL;
BLK1379:
	w = NIL;
	w = NIL;
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK1371;
	goto IF1375;
IF1374:
	local[1]= NIL;
IF1375:
	local[1]= argv[0]->c.obj.iv[8];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(*ftab[64])(ctx,2,local+2,&ftab[64],fqv[177]); /*assoc*/
	local[2]= w;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(*ftab[65])(ctx,2,local+2,&ftab[65],fqv[178]); /*delete*/
	local[2]= local[1];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)NCONC(ctx,2,local+2); /*nconc*/
	local[2]= argv[0];
	local[3]= fqv[179];
	local[4]= argv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[0]= w;
BLK1371:
	ctx->vsp=local; return(local[0]);}

/*:get-material*/
static pointer M1381glvertices_get_material(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1384;}
	local[0]= makeint((eusinteger_t)-1L);
ENT1384:
ENT1383:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[179];
	local[3]= fqv[180];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK1382:
	ctx->vsp=local; return(local[0]);}

/*:set-material*/
static pointer M1385glvertices_set_material(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1388;}
	local[0]= makeint((eusinteger_t)-1L);
ENT1388:
ENT1387:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[181];
	local[3]= fqv[180];
	local[4]= argv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[0]= w;
BLK1386:
	ctx->vsp=local; return(local[0]);}

/*:actual-vertices*/
static pointer M1389glvertices_actual_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[8];
WHL1392:
	if (local[2]==NIL) goto WHX1393;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= fqv[87];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(*ftab[64])(ctx,2,local+3,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	if (local[3]==NIL) goto IF1396;
	local[4]= makeint((eusinteger_t)0L);
	local[5]= local[3];
	local[6]= makeint((eusinteger_t)0L);
	ctx->vsp=local+7;
	w=(*ftab[66])(ctx,2,local+5,&ftab[66],fqv[182]); /*array-dimension*/
	local[5]= w;
WHL1399:
	local[6]= local[4];
	w = local[5];
	if ((eusinteger_t)local[6] >= (eusinteger_t)w) goto WHX1400;
	local[6]= local[3];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(*ftab[67])(ctx,2,local+6,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[6]= w;
	w = local[0];
	ctx->vsp=local+7;
	local[0] = cons(ctx,local[6],w);
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[4] = w;
	goto WHL1399;
WHX1400:
	local[6]= NIL;
BLK1401:
	w = NIL;
	local[4]= w;
	goto IF1397;
IF1396:
	local[4]= NIL;
IF1397:
	w = local[4];
	goto WHL1392;
WHX1393:
	local[3]= NIL;
BLK1394:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK1390:
	ctx->vsp=local; return(local[0]);}

/*:calc-bounding-box*/
static pointer M1402glvertices_calc_bounding_box(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[184];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+2;
	w=(*ftab[68])(ctx,2,local+0,&ftab[68],fqv[185]); /*make-bounding-box*/
	argv[0]->c.obj.iv[10] = w;
	w = argv[0]->c.obj.iv[10];
	local[0]= w;
BLK1403:
	ctx->vsp=local; return(local[0]);}

/*:vertices*/
static pointer M1404glvertices_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[10]!=NIL) goto IF1406;
	local[0]= argv[0];
	local[1]= fqv[186];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF1407;
IF1406:
	local[0]= NIL;
IF1407:
	local[0]= argv[0]->c.obj.iv[10];
	local[1]= fqv[187];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[87];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK1405:
	ctx->vsp=local; return(local[0]);}

/*:reset-offset-from-parent*/
static pointer M1408glvertices_reset_offset_from_parent(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[188];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[189];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[190];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = argv[0];
	local[0]= w;
BLK1409:
	ctx->vsp=local; return(local[0]);}

/*:expand-vertices*/
static pointer M1410glvertices_expand_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[8];
WHL1413:
	if (local[2]==NIL) goto WHX1414;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[0];
	local[4]= fqv[191];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	goto WHL1413;
WHX1414:
	local[3]= NIL;
BLK1415:
	w = NIL;
	argv[0]->c.obj.iv[8] = local[0];
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK1411:
	ctx->vsp=local; return(local[0]);}

/*:expand-vertices-info*/
static pointer M1417glvertices_expand_vertices_info(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= fqv[192];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[64])(ctx,2,local+0,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= fqv[87];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[64])(ctx,2,local+1,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= loadglobal(fqv[140]);
	local[3]= makeint((eusinteger_t)3L);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,2,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	local[4]= local[1];
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(*ftab[66])(ctx,2,local+4,&ftab[66],fqv[182]); /*array-dimension*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)GREATERP(ctx,2,local+3); /*>*/
	if (w==NIL) goto IF1419;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	local[4]= makeint((eusinteger_t)3L);
	ctx->vsp=local+5;
	w=(*ftab[69])(ctx,2,local+3,&ftab[69],fqv[193]); /*make-matrix*/
	local[3]= w;
	local[4]= loadglobal(fqv[101]);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)INSTANTIATE(ctx,2,local+4); /*instantiate*/
	local[4]= w;
	local[5]= fqv[87];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(*ftab[64])(ctx,2,local+5,&ftab[64],fqv[177]); /*assoc*/
	local[5]= w;
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(*ftab[65])(ctx,2,local+5,&ftab[65],fqv[178]); /*delete*/
	argv[2] = w;
	local[5]= fqv[192];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(*ftab[64])(ctx,2,local+5,&ftab[64],fqv[177]); /*assoc*/
	local[5]= w;
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(*ftab[65])(ctx,2,local+5,&ftab[65],fqv[178]); /*delete*/
	argv[2] = w;
	local[5]= fqv[194];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(*ftab[64])(ctx,2,local+5,&ftab[64],fqv[177]); /*assoc*/
	local[5]= w;
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(*ftab[65])(ctx,2,local+5,&ftab[65],fqv[178]); /*delete*/
	argv[2] = w;
	local[5]= makeint((eusinteger_t)0L);
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
WHL1422:
	local[7]= local[5];
	w = local[6];
	if ((eusinteger_t)local[7] >= (eusinteger_t)w) goto WHX1423;
	local[7]= local[4];
	local[8]= local[5];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)SETELT(ctx,3,local+7); /*setelt*/
	local[7]= local[1];
	local[8]= local[0];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(*ftab[67])(ctx,3,local+7,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[7]= local[3];
	local[8]= local[5];
	local[9]= local[2];
	local[10]= T;
	ctx->vsp=local+11;
	w=(*ftab[67])(ctx,4,local+7,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[5] = w;
	goto WHL1422;
WHX1423:
	local[7]= NIL;
BLK1424:
	w = NIL;
	local[5]= argv[2];
	local[6]= fqv[87];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	local[7]= fqv[192];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)NCONC(ctx,2,local+5); /*nconc*/
	argv[2] = w;
	w = argv[2];
	local[3]= w;
	goto IF1420;
IF1419:
	local[3]= argv[2];
IF1420:
	w = local[3];
	local[0]= w;
BLK1418:
	ctx->vsp=local; return(local[0]);}

/*:use-flat-shader*/
static pointer M1425glvertices_use_flat_shader(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[8];
WHL1428:
	if (local[1]==NIL) goto WHX1429;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= fqv[195];
	local[4]= T;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)NCONC(ctx,2,local+2); /*nconc*/
	goto WHL1428;
WHX1429:
	local[2]= NIL;
BLK1430:
	w = NIL;
	local[0]= w;
BLK1426:
	ctx->vsp=local; return(local[0]);}

/*:use-smooth-shader*/
static pointer M1432glvertices_use_smooth_shader(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[8];
WHL1435:
	if (local[1]==NIL) goto WHX1436;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= fqv[195];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[64])(ctx,2,local+2,&ftab[64],fqv[177]); /*assoc*/
	local[2]= w;
	if (local[2]==NIL) goto IF1439;
	local[3]= local[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[65])(ctx,2,local+3,&ftab[65],fqv[178]); /*delete*/
	local[3]= w;
	goto IF1440;
IF1439:
	local[3]= NIL;
IF1440:
	w = local[3];
	goto WHL1435;
WHX1436:
	local[2]= NIL;
BLK1437:
	w = NIL;
	local[0]= w;
BLK1433:
	ctx->vsp=local; return(local[0]);}

/*:calc-normals*/
static pointer M1441glvertices_calc_normals(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1446;}
	local[0]= NIL;
ENT1446:
	if (n>=4) { local[1]=(argv[3]); goto ENT1445;}
	local[1]= T;
ENT1445:
	if (n>=5) { local[2]=(argv[4]); goto ENT1444;}
	local[2]= T;
ENT1444:
ENT1443:
	if (n>5) maerror();
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[8];
WHL1448:
	if (local[4]==NIL) goto WHX1449;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= fqv[194];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(*ftab[64])(ctx,2,local+5,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= fqv[196];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(*ftab[64])(ctx,2,local+6,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= fqv[192];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[64])(ctx,2,local+7,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= fqv[87];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(*ftab[64])(ctx,2,local+8,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= loadglobal(fqv[140]);
	local[10]= makeint((eusinteger_t)3L);
	ctx->vsp=local+11;
	w=(pointer)INSTANTIATE(ctx,2,local+9); /*instantiate*/
	local[9]= w;
	local[10]= loadglobal(fqv[140]);
	local[11]= makeint((eusinteger_t)3L);
	ctx->vsp=local+12;
	w=(pointer)INSTANTIATE(ctx,2,local+10); /*instantiate*/
	local[10]= w;
	local[11]= loadglobal(fqv[140]);
	local[12]= makeint((eusinteger_t)3L);
	ctx->vsp=local+13;
	w=(pointer)INSTANTIATE(ctx,2,local+11); /*instantiate*/
	local[11]= w;
	local[12]= loadglobal(fqv[140]);
	local[13]= makeint((eusinteger_t)3L);
	ctx->vsp=local+14;
	w=(pointer)INSTANTIATE(ctx,2,local+12); /*instantiate*/
	local[12]= w;
	local[13]= loadglobal(fqv[140]);
	local[14]= makeint((eusinteger_t)3L);
	ctx->vsp=local+15;
	w=(pointer)INSTANTIATE(ctx,2,local+13); /*instantiate*/
	local[13]= w;
	local[14]= loadglobal(fqv[140]);
	local[15]= makeint((eusinteger_t)3L);
	ctx->vsp=local+16;
	w=(pointer)INSTANTIATE(ctx,2,local+14); /*instantiate*/
	local[14]= w;
	local[15]= local[6];
	local[16]= local[15];
	if (fqv[197]!=local[16]) goto IF1453;
	local[6] = makeint((eusinteger_t)3L);
	local[16]= local[6];
	goto IF1454;
IF1453:
	local[16]= local[15];
	if (fqv[198]!=local[16]) goto IF1455;
	local[6] = makeint((eusinteger_t)4L);
	local[16]= local[6];
	goto IF1456;
IF1455:
	local[16]= local[15];
	if (fqv[199]!=local[16]) goto IF1457;
	local[6] = makeint((eusinteger_t)2L);
	local[16]= local[6];
	goto IF1458;
IF1457:
	local[16]= local[15];
	if (fqv[200]!=local[16]) goto IF1459;
	local[6] = makeint((eusinteger_t)3L);
	local[16]= fqv[201];
	ctx->vsp=local+17;
	w=(*ftab[24])(ctx,1,local+16,&ftab[24],fqv[70]); /*warn*/
	local[16]= w;
	goto IF1460;
IF1459:
	if (T==NIL) goto IF1461;
	local[16]= fqv[202];
	ctx->vsp=local+17;
	w=(*ftab[24])(ctx,1,local+16,&ftab[24],fqv[70]); /*warn*/
	w = NIL;
	ctx->vsp=local+16;
	local[0]=w;
	goto BLK1442;
	goto IF1462;
IF1461:
	local[16]= NIL;
IF1462:
IF1460:
IF1458:
IF1456:
IF1454:
	w = local[16];
	if (local[5]==NIL) goto AND1465;
	if (local[0]!=NIL) goto AND1465;
	goto IF1463;
AND1465:
	if (local[1]==NIL) goto IF1466;
	local[15]= argv[0];
	local[16]= fqv[191];
	local[17]= local[3];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,3,local+15); /*send*/
	local[15]= fqv[192];
	local[16]= local[3];
	ctx->vsp=local+17;
	w=(*ftab[64])(ctx,2,local+15,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.car;
	local[15]= fqv[87];
	local[16]= local[3];
	ctx->vsp=local+17;
	w=(*ftab[64])(ctx,2,local+15,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.car;
	local[15]= local[8];
	goto IF1467;
IF1466:
	local[15]= NIL;
IF1467:
	if (local[5]==NIL) goto IF1468;
	local[15]= fqv[194];
	local[16]= local[3];
	ctx->vsp=local+17;
	w=(*ftab[64])(ctx,2,local+15,&ftab[64],fqv[177]); /*assoc*/
	local[15]= w;
	local[16]= local[3];
	ctx->vsp=local+17;
	w=(*ftab[65])(ctx,2,local+15,&ftab[65],fqv[178]); /*delete*/
	local[15]= w;
	goto IF1469;
IF1468:
	local[15]= NIL;
IF1469:
	local[15]= local[8];
	local[16]= makeint((eusinteger_t)0L);
	ctx->vsp=local+17;
	w=(*ftab[66])(ctx,2,local+15,&ftab[66],fqv[182]); /*array-dimension*/
	local[15]= w;
	local[16]= local[15];
	local[17]= makeint((eusinteger_t)3L);
	ctx->vsp=local+18;
	w=(*ftab[69])(ctx,2,local+16,&ftab[69],fqv[193]); /*make-matrix*/
	local[5] = w;
	if (local[7]==NIL) goto CON1471;
	local[16]= makeint((eusinteger_t)0L);
	local[17]= local[7];
	ctx->vsp=local+18;
	w=(pointer)LENGTH(ctx,1,local+17); /*length*/
	local[17]= w;
	local[18]= local[6];
	ctx->vsp=local+19;
	w=(pointer)QUOTIENT(ctx,2,local+17); /*/*/
	local[17]= w;
WHL1473:
	local[18]= local[16];
	w = local[17];
	if ((eusinteger_t)local[18] >= (eusinteger_t)w) goto WHX1474;
	local[18]= local[8];
	local[19]= local[7];
	local[20]= local[6];
	local[21]= local[16];
	ctx->vsp=local+22;
	w=(pointer)TIMES(ctx,2,local+20); /***/
	local[20]= w;
	local[21]= makeint((eusinteger_t)0L);
	ctx->vsp=local+22;
	w=(pointer)PLUS(ctx,2,local+20); /*+*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)ELT(ctx,2,local+19); /*elt*/
	local[19]= w;
	local[20]= local[9];
	ctx->vsp=local+21;
	w=(*ftab[67])(ctx,3,local+18,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[18]= local[8];
	local[19]= local[7];
	local[20]= local[6];
	local[21]= local[16];
	ctx->vsp=local+22;
	w=(pointer)TIMES(ctx,2,local+20); /***/
	local[20]= w;
	local[21]= makeint((eusinteger_t)1L);
	ctx->vsp=local+22;
	w=(pointer)PLUS(ctx,2,local+20); /*+*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)ELT(ctx,2,local+19); /*elt*/
	local[19]= w;
	local[20]= local[10];
	ctx->vsp=local+21;
	w=(*ftab[67])(ctx,3,local+18,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[18]= local[8];
	local[19]= local[7];
	local[20]= local[6];
	local[21]= local[16];
	ctx->vsp=local+22;
	w=(pointer)TIMES(ctx,2,local+20); /***/
	local[20]= w;
	local[21]= makeint((eusinteger_t)2L);
	ctx->vsp=local+22;
	w=(pointer)PLUS(ctx,2,local+20); /*+*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)ELT(ctx,2,local+19); /*elt*/
	local[19]= w;
	local[20]= local[11];
	ctx->vsp=local+21;
	w=(*ftab[67])(ctx,3,local+18,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[18]= local[10];
	local[19]= local[9];
	local[20]= local[12];
	ctx->vsp=local+21;
	w=(pointer)VMINUS(ctx,3,local+18); /*v-*/
	local[18]= w;
	local[19]= local[11];
	local[20]= local[9];
	local[21]= local[13];
	ctx->vsp=local+22;
	w=(pointer)VMINUS(ctx,3,local+19); /*v-*/
	local[19]= w;
	local[20]= local[14];
	ctx->vsp=local+21;
	w=(pointer)VCROSSPRODUCT(ctx,3,local+18); /*v**/
	local[18]= local[14];
	local[19]= local[14];
	ctx->vsp=local+20;
	w=(pointer)VNORMALIZE(ctx,2,local+18); /*normalize-vector*/
	local[18]= local[5];
	local[19]= local[7];
	local[20]= local[6];
	local[21]= local[16];
	ctx->vsp=local+22;
	w=(pointer)TIMES(ctx,2,local+20); /***/
	local[20]= w;
	local[21]= makeint((eusinteger_t)0L);
	ctx->vsp=local+22;
	w=(pointer)PLUS(ctx,2,local+20); /*+*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)ELT(ctx,2,local+19); /*elt*/
	local[19]= w;
	local[20]= local[14];
	local[21]= T;
	ctx->vsp=local+22;
	w=(*ftab[67])(ctx,4,local+18,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[18]= local[5];
	local[19]= local[7];
	local[20]= local[6];
	local[21]= local[16];
	ctx->vsp=local+22;
	w=(pointer)TIMES(ctx,2,local+20); /***/
	local[20]= w;
	local[21]= makeint((eusinteger_t)1L);
	ctx->vsp=local+22;
	w=(pointer)PLUS(ctx,2,local+20); /*+*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)ELT(ctx,2,local+19); /*elt*/
	local[19]= w;
	local[20]= local[14];
	local[21]= T;
	ctx->vsp=local+22;
	w=(*ftab[67])(ctx,4,local+18,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[18]= local[5];
	local[19]= local[7];
	local[20]= local[6];
	local[21]= local[16];
	ctx->vsp=local+22;
	w=(pointer)TIMES(ctx,2,local+20); /***/
	local[20]= w;
	local[21]= makeint((eusinteger_t)2L);
	ctx->vsp=local+22;
	w=(pointer)PLUS(ctx,2,local+20); /*+*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)ELT(ctx,2,local+19); /*elt*/
	local[19]= w;
	local[20]= local[14];
	local[21]= T;
	ctx->vsp=local+22;
	w=(*ftab[67])(ctx,4,local+18,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[18]= local[16];
	ctx->vsp=local+19;
	w=(pointer)ADD1(ctx,1,local+18); /*1+*/
	local[16] = w;
	goto WHL1473;
WHX1474:
	local[18]= NIL;
BLK1475:
	w = NIL;
	local[16]= w;
	goto CON1470;
CON1471:
	local[16]= makeint((eusinteger_t)0L);
	local[17]= local[15];
	local[18]= local[6];
	ctx->vsp=local+19;
	w=(pointer)QUOTIENT(ctx,2,local+17); /*/*/
	local[17]= w;
WHL1478:
	local[18]= local[16];
	w = local[17];
	if ((eusinteger_t)local[18] >= (eusinteger_t)w) goto WHX1479;
	local[18]= local[8];
	local[19]= local[6];
	local[20]= local[16];
	ctx->vsp=local+21;
	w=(pointer)TIMES(ctx,2,local+19); /***/
	local[19]= w;
	local[20]= makeint((eusinteger_t)0L);
	ctx->vsp=local+21;
	w=(pointer)PLUS(ctx,2,local+19); /*+*/
	local[19]= w;
	local[20]= local[9];
	ctx->vsp=local+21;
	w=(*ftab[67])(ctx,3,local+18,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[18]= local[8];
	local[19]= local[6];
	local[20]= local[16];
	ctx->vsp=local+21;
	w=(pointer)TIMES(ctx,2,local+19); /***/
	local[19]= w;
	local[20]= makeint((eusinteger_t)1L);
	ctx->vsp=local+21;
	w=(pointer)PLUS(ctx,2,local+19); /*+*/
	local[19]= w;
	local[20]= local[10];
	ctx->vsp=local+21;
	w=(*ftab[67])(ctx,3,local+18,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[18]= local[8];
	local[19]= local[6];
	local[20]= local[16];
	ctx->vsp=local+21;
	w=(pointer)TIMES(ctx,2,local+19); /***/
	local[19]= w;
	local[20]= makeint((eusinteger_t)2L);
	ctx->vsp=local+21;
	w=(pointer)PLUS(ctx,2,local+19); /*+*/
	local[19]= w;
	local[20]= local[11];
	ctx->vsp=local+21;
	w=(*ftab[67])(ctx,3,local+18,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[18]= local[10];
	local[19]= local[9];
	local[20]= local[12];
	ctx->vsp=local+21;
	w=(pointer)VMINUS(ctx,3,local+18); /*v-*/
	local[18]= w;
	local[19]= local[11];
	local[20]= local[9];
	local[21]= local[13];
	ctx->vsp=local+22;
	w=(pointer)VMINUS(ctx,3,local+19); /*v-*/
	local[19]= w;
	local[20]= local[14];
	ctx->vsp=local+21;
	w=(pointer)VCROSSPRODUCT(ctx,3,local+18); /*v**/
	local[18]= local[14];
	local[19]= local[14];
	ctx->vsp=local+20;
	w=(pointer)VNORMALIZE(ctx,2,local+18); /*normalize-vector*/
	local[18]= local[5];
	local[19]= local[7];
	local[20]= local[6];
	local[21]= local[16];
	ctx->vsp=local+22;
	w=(pointer)TIMES(ctx,2,local+20); /***/
	local[20]= w;
	local[21]= makeint((eusinteger_t)0L);
	ctx->vsp=local+22;
	w=(pointer)PLUS(ctx,2,local+20); /*+*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)ELT(ctx,2,local+19); /*elt*/
	local[19]= w;
	local[20]= local[14];
	local[21]= T;
	ctx->vsp=local+22;
	w=(*ftab[67])(ctx,4,local+18,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[18]= local[5];
	local[19]= local[7];
	local[20]= local[6];
	local[21]= local[16];
	ctx->vsp=local+22;
	w=(pointer)TIMES(ctx,2,local+20); /***/
	local[20]= w;
	local[21]= makeint((eusinteger_t)1L);
	ctx->vsp=local+22;
	w=(pointer)PLUS(ctx,2,local+20); /*+*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)ELT(ctx,2,local+19); /*elt*/
	local[19]= w;
	local[20]= local[14];
	local[21]= T;
	ctx->vsp=local+22;
	w=(*ftab[67])(ctx,4,local+18,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[18]= local[5];
	local[19]= local[7];
	local[20]= local[6];
	local[21]= local[16];
	ctx->vsp=local+22;
	w=(pointer)TIMES(ctx,2,local+20); /***/
	local[20]= w;
	local[21]= makeint((eusinteger_t)2L);
	ctx->vsp=local+22;
	w=(pointer)PLUS(ctx,2,local+20); /*+*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)ELT(ctx,2,local+19); /*elt*/
	local[19]= w;
	local[20]= local[14];
	local[21]= T;
	ctx->vsp=local+22;
	w=(*ftab[67])(ctx,4,local+18,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[18]= local[16];
	ctx->vsp=local+19;
	w=(pointer)ADD1(ctx,1,local+18); /*1+*/
	local[16] = w;
	goto WHL1478;
WHX1479:
	local[18]= NIL;
BLK1480:
	w = NIL;
	local[16]= w;
	goto CON1470;
CON1476:
	local[16]= NIL;
CON1470:
	local[16]= local[3];
	local[17]= fqv[194];
	local[18]= local[5];
	ctx->vsp=local+19;
	w=(pointer)LIST(ctx,2,local+17); /*list*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,1,local+17); /*list*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)NCONC(ctx,2,local+16); /*nconc*/
	if (local[2]==NIL) goto IF1481;
	local[16]= local[3];
	local[17]= fqv[195];
	local[18]= T;
	ctx->vsp=local+19;
	w=(pointer)LIST(ctx,2,local+17); /*list*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,1,local+17); /*list*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)NCONC(ctx,2,local+16); /*nconc*/
	local[16]= w;
	goto IF1482;
IF1481:
	local[16]= NIL;
IF1482:
	w = local[16];
	local[15]= w;
	goto IF1464;
IF1463:
	local[15]= NIL;
IF1464:
	w = local[15];
	goto WHL1448;
WHX1449:
	local[5]= NIL;
BLK1450:
	w = NIL;
	local[0]= w;
BLK1442:
	ctx->vsp=local; return(local[0]);}

/*:mirror-axis*/
static pointer M1483glvertices_mirror_axis(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[203], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY1485;
	local[0] = T;
KEY1485:
	if (n & (1<<1)) goto KEY1486;
	local[1] = T;
KEY1486:
	if (n & (1<<2)) goto KEY1487;
	local[2] = fqv[40];
KEY1487:
	local[3]= local[2];
	local[4]= local[3];
	if (fqv[39]!=local[4]) goto IF1489;
	local[2] = makeint((eusinteger_t)0L);
	local[4]= local[2];
	goto IF1490;
IF1489:
	local[4]= local[3];
	if (fqv[40]!=local[4]) goto IF1491;
	local[2] = makeint((eusinteger_t)1L);
	local[4]= local[2];
	goto IF1492;
IF1491:
	local[4]= local[3];
	if (fqv[204]!=local[4]) goto IF1493;
	local[2] = makeint((eusinteger_t)2L);
	local[4]= local[2];
	goto IF1494;
IF1493:
	local[4]= NIL;
IF1494:
IF1492:
IF1490:
	w = local[4];
	local[3]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+4;
	w=(pointer)COPYOBJ(ctx,1,local+3); /*copy-object*/
	local[3]= w;
	local[4]= loadglobal(fqv[140]);
	local[5]= makeint((eusinteger_t)3L);
	ctx->vsp=local+6;
	w=(pointer)INSTANTIATE(ctx,2,local+4); /*instantiate*/
	local[4]= w;
	local[5]= NIL;
	local[6]= local[3];
WHL1496:
	if (local[6]==NIL) goto WHX1497;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= fqv[87];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(*ftab[64])(ctx,2,local+7,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= local[7];
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(*ftab[66])(ctx,2,local+8,&ftab[66],fqv[182]); /*array-dimension*/
	local[8]= w;
	if (local[8]==NIL) goto IF1500;
	local[9]= makeint((eusinteger_t)0L);
	local[10]= local[8];
WHL1503:
	local[11]= local[9];
	w = local[10];
	if ((eusinteger_t)local[11] >= (eusinteger_t)w) goto WHX1504;
	local[11]= local[7];
	local[12]= local[9];
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(*ftab[67])(ctx,3,local+11,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[11]= local[4];
	local[12]= local[2];
	local[13]= local[4];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)MINUS(ctx,1,local+13); /*-*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SETELT(ctx,3,local+11); /*setelt*/
	local[11]= local[7];
	local[12]= local[9];
	local[13]= local[4];
	local[14]= T;
	ctx->vsp=local+15;
	w=(*ftab[67])(ctx,4,local+11,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[11]= local[9];
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[9] = w;
	goto WHL1503;
WHX1504:
	local[11]= NIL;
BLK1505:
	w = NIL;
	if (local[1]==NIL) goto IF1506;
	local[9]= fqv[192];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(*ftab[64])(ctx,2,local+9,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= local[9];
	ctx->vsp=local+11;
	w=(pointer)LENGTH(ctx,1,local+10); /*length*/
	local[10]= w;
	local[11]= makeint((eusinteger_t)3L);
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[10]= w;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= makeint((eusinteger_t)0L);
	local[15]= local[10];
WHL1509:
	local[16]= local[14];
	w = local[15];
	if ((eusinteger_t)local[16] >= (eusinteger_t)w) goto WHX1510;
	local[16]= local[9];
	local[17]= local[14];
	{ eusinteger_t i,j;
		j=intval(makeint((eusinteger_t)3L)); i=intval(local[17]);
		local[17]=(makeint(i * j));}
	ctx->vsp=local+18;
	w=(pointer)ELT(ctx,2,local+16); /*elt*/
	local[11] = w;
	local[16]= local[9];
	local[17]= local[14];
	{ eusinteger_t i,j;
		j=intval(makeint((eusinteger_t)3L)); i=intval(local[17]);
		local[17]=(makeint(i * j));}
	w = makeint((eusinteger_t)1L);
#if sun4 || vax || mips || alpha || Linux
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[17]= (pointer)((eusinteger_t)local[17] + (eusinteger_t)w);
	ctx->vsp=local+18;
	w=(pointer)ELT(ctx,2,local+16); /*elt*/
	local[12] = w;
	local[16]= local[9];
	local[17]= local[14];
	{ eusinteger_t i,j;
		j=intval(makeint((eusinteger_t)3L)); i=intval(local[17]);
		local[17]=(makeint(i * j));}
	w = makeint((eusinteger_t)2L);
#if sun4 || vax || mips || alpha || Linux
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[17]= (pointer)((eusinteger_t)local[17] + (eusinteger_t)w);
	ctx->vsp=local+18;
	w=(pointer)ELT(ctx,2,local+16); /*elt*/
	local[13] = w;
	local[16]= local[9];
	local[17]= local[14];
	{ eusinteger_t i,j;
		j=intval(makeint((eusinteger_t)3L)); i=intval(local[17]);
		local[17]=(makeint(i * j));}
	local[18]= local[13];
	ctx->vsp=local+19;
	w=(pointer)SETELT(ctx,3,local+16); /*setelt*/
	local[16]= local[9];
	local[17]= local[14];
	{ eusinteger_t i,j;
		j=intval(makeint((eusinteger_t)3L)); i=intval(local[17]);
		local[17]=(makeint(i * j));}
	w = makeint((eusinteger_t)1L);
#if sun4 || vax || mips || alpha || Linux
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[17]= (pointer)((eusinteger_t)local[17] + (eusinteger_t)w);
	local[18]= local[12];
	ctx->vsp=local+19;
	w=(pointer)SETELT(ctx,3,local+16); /*setelt*/
	local[16]= local[9];
	local[17]= local[14];
	{ eusinteger_t i,j;
		j=intval(makeint((eusinteger_t)3L)); i=intval(local[17]);
		local[17]=(makeint(i * j));}
	w = makeint((eusinteger_t)2L);
#if sun4 || vax || mips || alpha || Linux
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[17]= (pointer)((eusinteger_t)local[17] + (eusinteger_t)w);
	local[18]= local[11];
	ctx->vsp=local+19;
	w=(pointer)SETELT(ctx,3,local+16); /*setelt*/
	local[16]= local[14];
	ctx->vsp=local+17;
	w=(pointer)ADD1(ctx,1,local+16); /*1+*/
	local[14] = w;
	goto WHL1509;
WHX1510:
	local[16]= NIL;
BLK1511:
	w = NIL;
	local[9]= w;
	goto IF1507;
IF1506:
	local[9]= NIL;
IF1507:
	goto IF1501;
IF1500:
	local[9]= NIL;
IF1501:
	w = local[9];
	goto WHL1496;
WHX1497:
	local[7]= NIL;
BLK1498:
	w = NIL;
	if (local[0]==NIL) goto IF1512;
	local[5]= loadglobal(fqv[205]);
	ctx->vsp=local+6;
	w=(pointer)INSTANTIATE(ctx,1,local+5); /*instantiate*/
	local[5]= w;
	local[6]= local[5];
	local[7]= fqv[45];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	w = local[5];
	local[5]= w;
	goto IF1513;
IF1512:
	argv[0]->c.obj.iv[8] = local[3];
	local[5]= argv[0];
IF1513:
	w = local[5];
	local[0]= w;
BLK1484:
	ctx->vsp=local; return(local[0]);}

/*:convert-to-faces*/
static pointer M1515glvertices_convert_to_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1517:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[206], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY1518;
	local[1] = fqv[207];
KEY1518:
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[8];
WHL1520:
	if (local[4]==NIL) goto WHX1521;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= fqv[87];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(*ftab[64])(ctx,2,local+5,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= fqv[194];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(*ftab[64])(ctx,2,local+6,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= fqv[192];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[64])(ctx,2,local+7,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= local[7];
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
	local[9]= fqv[196];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(*ftab[64])(ctx,2,local+9,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= local[9];
	local[13]= local[12];
	if (fqv[197]!=local[13]) goto IF1525;
	local[10] = makeint((eusinteger_t)3L);
	local[13]= local[10];
	goto IF1526;
IF1525:
	local[13]= local[12];
	if (fqv[198]!=local[13]) goto IF1527;
	local[10] = makeint((eusinteger_t)4L);
	local[13]= local[10];
	goto IF1528;
IF1527:
	if (T==NIL) goto IF1529;
	local[13]= fqv[208];
	local[14]= local[9];
	ctx->vsp=local+15;
	w=(*ftab[24])(ctx,2,local+13,&ftab[24],fqv[70]); /*warn*/
	w = NIL;
	ctx->vsp=local+13;
	local[0]=w;
	goto BLK1516;
	goto IF1530;
IF1529:
	local[13]= NIL;
IF1530:
IF1528:
IF1526:
	w = local[13];
	local[12]= local[8];
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(pointer)QUOTIENT(ctx,2,local+12); /*/*/
	local[12]= w;
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(pointer)TIMES(ctx,2,local+12); /***/
	local[8] = w;
	if (local[7]==NIL) goto CON1532;
	local[12]= makeint((eusinteger_t)0L);
	local[13]= makeint((eusinteger_t)0L);
TAG1535:
	local[14]= local[13];
	local[15]= local[8];
	ctx->vsp=local+16;
	w=(pointer)GREQP(ctx,2,local+14); /*>=*/
	if (w==NIL) goto IF1536;
	w = NIL;
	ctx->vsp=local+14;
	local[12]=w;
	goto BLK1534;
	goto IF1537;
IF1536:
	local[14]= NIL;
IF1537:
	local[14]= NIL;
	local[15]= NIL;
	local[16]= makeint((eusinteger_t)0L);
	local[17]= local[10];
WHL1539:
	local[18]= local[16];
	w = local[17];
	if ((eusinteger_t)local[18] >= (eusinteger_t)w) goto WHX1540;
	local[18]= local[5];
	local[19]= local[7];
	local[20]= local[13];
	local[21]= local[16];
	ctx->vsp=local+22;
	w=(pointer)PLUS(ctx,2,local+20); /*+*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)ELT(ctx,2,local+19); /*elt*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(*ftab[67])(ctx,2,local+18,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[18]= w;
	w = local[14];
	ctx->vsp=local+19;
	local[14] = cons(ctx,local[18],w);
	if (local[6]==NIL) goto IF1542;
	local[18]= local[6];
	local[19]= local[7];
	local[20]= local[13];
	local[21]= local[16];
	ctx->vsp=local+22;
	w=(pointer)PLUS(ctx,2,local+20); /*+*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)ELT(ctx,2,local+19); /*elt*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(*ftab[67])(ctx,2,local+18,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[18]= w;
	w = local[15];
	ctx->vsp=local+19;
	local[15] = cons(ctx,local[18],w);
	local[18]= local[15];
	goto IF1543;
IF1542:
	local[18]= NIL;
IF1543:
	local[18]= local[16];
	ctx->vsp=local+19;
	w=(pointer)ADD1(ctx,1,local+18); /*1+*/
	local[16] = w;
	goto WHL1539;
WHX1540:
	local[18]= NIL;
BLK1541:
	w = NIL;
	local[16]= local[1];
	local[17]= local[16];
	if (fqv[209]!=local[17]) goto IF1545;
	ctx->vsp=local+17;
	local[17]= makeclosure(codevec,quotevec,CLO1547,env,argv,local);
	local[18]= local[14];
	ctx->vsp=local+19;
	w=(pointer)NREVERSE(ctx,1,local+18); /*nreverse*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)MAPCAR(ctx,2,local+17); /*mapcar*/
	local[17]= w;
	goto IF1546;
IF1545:
	local[17]= local[16];
	if (fqv[207]!=local[17]) goto IF1548;
	local[17]= local[14];
	ctx->vsp=local+18;
	w=(pointer)NREVERSE(ctx,1,local+17); /*nreverse*/
	local[17]= w;
	goto IF1549;
IF1548:
	if (T==NIL) goto IF1550;
	local[17]= NIL;
	goto IF1551;
IF1550:
	local[17]= NIL;
IF1551:
IF1549:
IF1546:
	w = local[17];
	local[14] = w;
	local[16]= loadglobal(fqv[210]);
	ctx->vsp=local+17;
	w=(pointer)INSTANTIATE(ctx,1,local+16); /*instantiate*/
	local[16]= w;
	local[17]= local[16];
	local[18]= fqv[45];
	local[19]= fqv[87];
	local[20]= local[14];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,4,local+17); /*send*/
	w = local[16];
	local[16]= w;
	goto CON1552;
CON1553:
	local[16]= NIL;
CON1552:
	w = local[11];
	ctx->vsp=local+17;
	local[11] = cons(ctx,local[16],w);
	w = local[11];
	local[14]= local[12];
	local[15]= makeint((eusinteger_t)1L);
	ctx->vsp=local+16;
	w=(pointer)PLUS(ctx,2,local+14); /*+*/
	local[14]= w;
	local[15]= local[13];
	local[16]= local[10];
	ctx->vsp=local+17;
	w=(pointer)PLUS(ctx,2,local+15); /*+*/
	local[15]= w;
	local[12] = local[14];
	local[13] = local[15];
	w = NIL;
	ctx->vsp=local+14;
	goto TAG1535;
	w = NIL;
	local[12]= w;
BLK1534:
	goto CON1531;
CON1532:
	local[12]= makeint((eusinteger_t)0L);
	local[13]= makeint((eusinteger_t)0L);
TAG1560:
	local[14]= local[13];
	local[15]= local[5];
	local[16]= makeint((eusinteger_t)0L);
	ctx->vsp=local+17;
	w=(*ftab[66])(ctx,2,local+15,&ftab[66],fqv[182]); /*array-dimension*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)GREQP(ctx,2,local+14); /*>=*/
	if (w==NIL) goto IF1561;
	w = NIL;
	ctx->vsp=local+14;
	local[12]=w;
	goto BLK1559;
	goto IF1562;
IF1561:
	local[14]= NIL;
IF1562:
	local[14]= NIL;
	local[15]= NIL;
	local[16]= makeint((eusinteger_t)0L);
	local[17]= local[10];
WHL1564:
	local[18]= local[16];
	w = local[17];
	if ((eusinteger_t)local[18] >= (eusinteger_t)w) goto WHX1565;
	local[18]= local[5];
	local[19]= local[13];
	local[20]= local[16];
	ctx->vsp=local+21;
	w=(pointer)PLUS(ctx,2,local+19); /*+*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(*ftab[67])(ctx,2,local+18,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[18]= w;
	w = local[14];
	ctx->vsp=local+19;
	local[14] = cons(ctx,local[18],w);
	if (local[6]==NIL) goto IF1567;
	local[18]= local[6];
	local[19]= local[13];
	local[20]= local[16];
	ctx->vsp=local+21;
	w=(pointer)PLUS(ctx,2,local+19); /*+*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(*ftab[67])(ctx,2,local+18,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[18]= w;
	w = local[15];
	ctx->vsp=local+19;
	local[15] = cons(ctx,local[18],w);
	local[18]= local[15];
	goto IF1568;
IF1567:
	local[18]= NIL;
IF1568:
	local[18]= local[16];
	ctx->vsp=local+19;
	w=(pointer)ADD1(ctx,1,local+18); /*1+*/
	local[16] = w;
	goto WHL1564;
WHX1565:
	local[18]= NIL;
BLK1566:
	w = NIL;
	local[16]= local[1];
	local[17]= local[16];
	if (fqv[209]!=local[17]) goto IF1570;
	ctx->vsp=local+17;
	local[17]= makeclosure(codevec,quotevec,CLO1572,env,argv,local);
	local[18]= local[14];
	ctx->vsp=local+19;
	w=(pointer)NREVERSE(ctx,1,local+18); /*nreverse*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)MAPCAR(ctx,2,local+17); /*mapcar*/
	local[17]= w;
	goto IF1571;
IF1570:
	local[17]= local[16];
	if (fqv[207]!=local[17]) goto IF1573;
	local[17]= local[14];
	ctx->vsp=local+18;
	w=(pointer)NREVERSE(ctx,1,local+17); /*nreverse*/
	local[17]= w;
	goto IF1574;
IF1573:
	if (T==NIL) goto IF1575;
	local[17]= NIL;
	goto IF1576;
IF1575:
	local[17]= NIL;
IF1576:
IF1574:
IF1571:
	w = local[17];
	local[14] = w;
	local[16]= loadglobal(fqv[210]);
	ctx->vsp=local+17;
	w=(pointer)INSTANTIATE(ctx,1,local+16); /*instantiate*/
	local[16]= w;
	local[17]= local[16];
	local[18]= fqv[45];
	local[19]= fqv[87];
	local[20]= local[14];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,4,local+17); /*send*/
	w = local[16];
	local[16]= w;
	goto CON1577;
CON1578:
	local[16]= NIL;
CON1577:
	w = local[11];
	ctx->vsp=local+17;
	local[11] = cons(ctx,local[16],w);
	w = local[11];
	local[14]= local[12];
	local[15]= makeint((eusinteger_t)1L);
	ctx->vsp=local+16;
	w=(pointer)PLUS(ctx,2,local+14); /*+*/
	local[14]= w;
	local[15]= local[13];
	local[16]= local[10];
	ctx->vsp=local+17;
	w=(pointer)PLUS(ctx,2,local+15); /*+*/
	local[15]= w;
	local[12] = local[14];
	local[13] = local[15];
	w = NIL;
	ctx->vsp=local+14;
	goto TAG1560;
	w = NIL;
	local[12]= w;
BLK1559:
	goto CON1531;
CON1557:
	local[12]= NIL;
CON1531:
	local[12]= local[11];
	ctx->vsp=local+13;
	w=(pointer)NREVERSE(ctx,1,local+12); /*nreverse*/
	local[12]= w;
	w = local[2];
	ctx->vsp=local+13;
	local[2] = cons(ctx,local[12],w);
	w = local[2];
	goto WHL1520;
WHX1521:
	local[5]= NIL;
BLK1522:
	w = NIL;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	local[0]= w;
BLK1516:
	ctx->vsp=local; return(local[0]);}

/*:faces*/
static pointer M1582glvertices_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[211];
	local[2]= fqv[212];
	local[3]= fqv[209];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[70])(ctx,1,local+0,&ftab[70],fqv[213]); /*flatten*/
	local[0]= w;
BLK1583:
	ctx->vsp=local; return(local[0]);}

/*:convert-to-faceset*/
static pointer M1584glvertices_convert_to_faceset(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1586:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= loadglobal(fqv[66]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[45];
	local[4]= fqv[86];
	local[5]= (pointer)get_sym_func(fqv[214]);
	local[6]= argv[0];
	local[7]= fqv[211];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,4,local+5); /*apply*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[70])(ctx,1,local+5,&ftab[70],fqv[213]); /*flatten*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[215];
	local[4]= argv[0];
	local[5]= fqv[74];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK1585:
	ctx->vsp=local; return(local[0]);}

/*:set-offset*/
static pointer M1588glvertices_set_offset(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[216], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY1590;
	local[0] = NIL;
KEY1590:
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= fqv[167];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[2];
	local[4]= fqv[93];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= NIL;
	if (local[0]==NIL) goto IF1591;
	local[5]= loadglobal(fqv[205]);
	ctx->vsp=local+6;
	w=(pointer)INSTANTIATE(ctx,1,local+5); /*instantiate*/
	local[5]= w;
	local[6]= local[5];
	local[7]= fqv[45];
	local[8]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+9;
	w=(pointer)COPYOBJ(ctx,1,local+8); /*copy-object*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	w = local[5];
	local[4] = w;
	local[5]= local[4];
	goto IF1592;
IF1591:
	local[4] = argv[0];
	local[5]= local[4];
IF1592:
	local[5]= NIL;
	local[6]= *(ovafptr(local[4],fqv[217]));
WHL1595:
	if (local[6]==NIL) goto WHX1596;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= fqv[87];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(*ftab[64])(ctx,2,local+7,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= fqv[194];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(*ftab[64])(ctx,2,local+8,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= local[2];
	local[10]= local[3];
	local[11]= local[7];
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(*ftab[71])(ctx,4,local+9,&ftab[71],fqv[218]); /*user::c-coords-transform-vector*/
	if (local[8]==NIL) goto IF1599;
	local[9]= local[1];
	local[10]= local[3];
	local[11]= local[8];
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(*ftab[71])(ctx,4,local+9,&ftab[71],fqv[218]); /*user::c-coords-transform-vector*/
	local[9]= w;
	goto IF1600;
IF1599:
	local[9]= NIL;
IF1600:
	w = local[9];
	goto WHL1595;
WHX1596:
	local[7]= NIL;
BLK1597:
	w = NIL;
	w = local[4];
	local[0]= w;
BLK1589:
	ctx->vsp=local; return(local[0]);}

/*:convert-to-world*/
static pointer M1601glvertices_convert_to_world(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[219], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY1603;
	local[0] = NIL;
KEY1603:
	local[1]= argv[0];
	local[2]= fqv[189];
	local[3]= argv[0];
	local[4]= fqv[74];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= fqv[220];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[190];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[74];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK1602:
	ctx->vsp=local; return(local[0]);}

/*:glvertices*/
static pointer M1604glvertices_glvertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1608;}
	local[0]= NIL;
ENT1608:
	if (n>=4) { local[1]=(argv[3]); goto ENT1607;}
	local[1]= (pointer)get_sym_func(fqv[221]);
ENT1607:
ENT1606:
	if (n>4) maerror();
	local[2]= NIL;
	if (local[0]==NIL) goto CON1610;
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO1611,env,argv,local);
	local[4]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+5;
	w=(*ftab[57])(ctx,2,local+3,&ftab[57],fqv[137]); /*find-if*/
	local[3]= w;
	if (local[3]==NIL) goto IF1612;
	local[4]= loadglobal(fqv[205]);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= local[4];
	local[6]= fqv[45];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	goto IF1613;
IF1612:
	local[4]= NIL;
IF1613:
	w = local[4];
	local[3]= w;
	goto CON1609;
CON1610:
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[8];
WHL1617:
	if (local[4]==NIL) goto WHX1618;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= loadglobal(fqv[205]);
	ctx->vsp=local+6;
	w=(pointer)INSTANTIATE(ctx,1,local+5); /*instantiate*/
	local[5]= w;
	local[6]= local[5];
	local[7]= fqv[45];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	w = local[5];
	local[5]= w;
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	goto WHL1617;
WHX1618:
	local[5]= NIL;
BLK1619:
	w = NIL;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	local[2] = w;
	local[3]= local[2];
	goto CON1609;
CON1615:
	local[3]= NIL;
CON1609:
	w = local[2];
	local[0]= w;
BLK1605:
	ctx->vsp=local; return(local[0]);}

/*:append-glvertices*/
static pointer M1622glvertices_append_glvertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	if (!!iscons(w)) goto IF1624;
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	argv[2] = w;
	local[0]= argv[2];
	goto IF1625;
IF1624:
	local[0]= NIL;
IF1625:
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[74];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= NIL;
	local[3]= argv[2];
WHL1627:
	if (local[3]==NIL) goto WHX1628;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= *(ovafptr(local[2],fqv[217]));
	ctx->vsp=local+5;
	w=(pointer)COPYOBJ(ctx,1,local+4); /*copy-object*/
	local[4]= w;
	local[5]= local[1];
	local[6]= fqv[222];
	local[7]= local[2];
	local[8]= fqv[74];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	local[6]= loadglobal(fqv[205]);
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,1,local+6); /*instantiate*/
	local[6]= w;
	local[7]= local[6];
	local[8]= fqv[45];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	w = local[6];
	local[6]= w;
	local[7]= local[6];
	local[8]= fqv[189];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= local[0];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)APPEND(ctx,2,local+7); /*append*/
	local[0] = w;
	w = local[0];
	goto WHL1627;
WHX1628:
	local[4]= NIL;
BLK1629:
	w = NIL;
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)APPEND(ctx,2,local+2); /*append*/
	argv[0]->c.obj.iv[8] = w;
	local[2]= argv[0];
	local[3]= fqv[186];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	w = argv[0];
	local[0]= w;
BLK1623:
	ctx->vsp=local; return(local[0]);}

/*:draw-on*/
static pointer M1632glvertices_draw_on(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[223], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY1634;
	local[0] = loadglobal(fqv[143]);
KEY1634:
	w = NIL;
	local[0]= w;
BLK1633:
	ctx->vsp=local; return(local[0]);}

/*:draw*/
static pointer M1635glvertices_draw(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST1637:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= fqv[74];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= fqv[75];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[176];
	ctx->vsp=local+5;
	w=(pointer)GETPROP(ctx,2,local+3); /*get*/
	local[3]= w;
	local[4]= NIL;
	local[5]= argv[2];
	local[6]= fqv[8];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= *(ovafptr(w,fqv[13]));
	local[6]= argv[2];
	local[7]= fqv[8];
	local[8]= fqv[9];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= makeint((eusinteger_t)4294967295L);
	ctx->vsp=local+7;
	w=(*ftab[31])(ctx,1,local+6,&ftab[31],fqv[83]); /*glpushattrib*/
	ctx->vsp=local+6;
	w=(*ftab[25])(ctx,0,local+6,&ftab[25],fqv[76]); /*glpushmatrix*/
	local[6]= local[2];
	local[7]= loadglobal(fqv[77]);
	ctx->vsp=local+8;
	w=(pointer)TRANSPOSE(ctx,2,local+6); /*transpose*/
	local[6]= w->c.obj.iv[1];
	ctx->vsp=local+7;
	w=(*ftab[26])(ctx,1,local+6,&ftab[26],fqv[78]); /*glmultmatrixf*/
	local[6]= makeint((eusinteger_t)2898L);
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(*ftab[72])(ctx,2,local+6,&ftab[72],fqv[224]); /*gllightmodeli*/
	local[6]= local[5];
	local[7]= argv[0];
	local[8]= fqv[71];
	ctx->vsp=local+9;
	w=(pointer)GETPROP(ctx,2,local+7); /*get*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)ASSQ(ctx,2,local+6); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	if (local[1]==NIL) goto CON1639;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[27])(ctx,1,local+6,&ftab[27],fqv[79]); /*glcalllist*/
	local[6]= w;
	goto CON1638;
CON1639:
	local[6]= argv[0];
	local[7]= fqv[73];
	ctx->vsp=local+8;
	w=(pointer)GETPROP(ctx,2,local+6); /*get*/
	local[4] = w;
	if (local[4]==NIL) goto IF1641;
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)VECTORP(ctx,1,local+6); /*vectorp*/
	if (w!=NIL) goto IF1641;
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)F982find_color(ctx,1,local+6); /*find-color*/
	local[4] = w;
	local[6]= argv[0];
	local[7]= local[4];
	local[8]= fqv[73];
	ctx->vsp=local+9;
	w=(pointer)PUTPROP(ctx,3,local+6); /*putprop*/
	local[6]= w;
	goto IF1642;
IF1641:
	local[6]= NIL;
IF1642:
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(*ftab[29])(ctx,1,local+6,&ftab[29],fqv[81]); /*glgenlists*/
	local[1] = w;
	local[6]= local[1];
	local[7]= makeint((eusinteger_t)4864L);
	ctx->vsp=local+8;
	w=(*ftab[30])(ctx,2,local+6,&ftab[30],fqv[82]); /*glnewlist*/
	if (local[3]==NIL) goto IF1643;
	local[6]= makeint((eusinteger_t)0L);
	ctx->vsp=local+7;
	w=(*ftab[73])(ctx,1,local+6,&ftab[73],fqv[225]); /*gldepthmask*/
	local[6]= makeint((eusinteger_t)3042L);
	ctx->vsp=local+7;
	w=(*ftab[12])(ctx,1,local+6,&ftab[12],fqv[29]); /*glenable*/
	local[6]= makeint((eusinteger_t)770L);
	local[7]= makeint((eusinteger_t)771L);
	ctx->vsp=local+8;
	w=(*ftab[39])(ctx,2,local+6,&ftab[39],fqv[102]); /*glblendfunc*/
	local[6]= w;
	goto IF1644;
IF1643:
	local[6]= NIL;
IF1644:
	local[6]= NIL;
	local[7]= argv[0]->c.obj.iv[8];
WHL1646:
	if (local[7]==NIL) goto WHX1647;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= fqv[196];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(*ftab[64])(ctx,2,local+8,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= fqv[180];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(*ftab[64])(ctx,2,local+9,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= fqv[87];
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(*ftab[64])(ctx,2,local+10,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= fqv[194];
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(*ftab[64])(ctx,2,local+11,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= fqv[192];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(*ftab[64])(ctx,2,local+12,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= fqv[226];
	local[14]= local[6];
	ctx->vsp=local+15;
	w=(*ftab[64])(ctx,2,local+13,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	local[14]= fqv[195];
	local[15]= local[6];
	ctx->vsp=local+16;
	w=(*ftab[64])(ctx,2,local+14,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	local[15]= NIL;
	if (local[14]==NIL) goto IF1650;
	local[16]= makeint((eusinteger_t)7424L);
	ctx->vsp=local+17;
	w=(*ftab[12])(ctx,1,local+16,&ftab[12],fqv[29]); /*glenable*/
	local[16]= makeint((eusinteger_t)7424L);
	ctx->vsp=local+17;
	w=(*ftab[74])(ctx,1,local+16,&ftab[74],fqv[227]); /*glshademodel*/
	local[16]= w;
	goto IF1651;
IF1650:
	local[16]= NIL;
IF1651:
	if (local[4]==NIL) goto CON1653;
	local[16]= local[4];
	ctx->vsp=local+17;
	w=(*ftab[22])(ctx,1,local+16,&ftab[22],fqv[58]); /*glcolor3fv*/
	if (local[3]==NIL) goto CON1655;
	local[16]= makeint((eusinteger_t)1029L);
	local[17]= makeint((eusinteger_t)5634L);
	local[18]= loadglobal(fqv[140]);
	local[19]= local[4];
	local[20]= local[3];
	ctx->vsp=local+21;
	w=(pointer)MKFLTVEC(ctx,1,local+20); /*float-vector*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)CONCATENATE(ctx,3,local+18); /*concatenate*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(*ftab[40])(ctx,3,local+16,&ftab[40],fqv[103]); /*glmaterialfv*/
	local[16]= makeint((eusinteger_t)1028L);
	local[17]= makeint((eusinteger_t)5634L);
	local[18]= makeint((eusinteger_t)0L);
	local[19]= makeint((eusinteger_t)0L);
	local[20]= makeint((eusinteger_t)0L);
	local[21]= makeint((eusinteger_t)0L);
	ctx->vsp=local+22;
	w=(pointer)MKFLTVEC(ctx,4,local+18); /*float-vector*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(*ftab[40])(ctx,3,local+16,&ftab[40],fqv[103]); /*glmaterialfv*/
	local[16]= w;
	goto CON1654;
CON1655:
	local[16]= makeint((eusinteger_t)1029L);
	local[17]= makeint((eusinteger_t)5634L);
	local[18]= local[4];
	ctx->vsp=local+19;
	w=(*ftab[40])(ctx,3,local+16,&ftab[40],fqv[103]); /*glmaterialfv*/
	local[16]= makeint((eusinteger_t)1028L);
	local[17]= makeint((eusinteger_t)5634L);
	local[18]= makeflt(7.9999999999999982236432e-01);
	local[19]= makeflt(0.0000000000000000000000e+00);
	local[20]= makeflt(5.4000000000000003552714e-01);
	ctx->vsp=local+21;
	w=(pointer)MKFLTVEC(ctx,3,local+18); /*float-vector*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(*ftab[40])(ctx,3,local+16,&ftab[40],fqv[103]); /*glmaterialfv*/
	local[16]= w;
	goto CON1654;
CON1656:
	local[16]= NIL;
CON1654:
	goto CON1652;
CON1653:
	if (local[9]==NIL) goto CON1657;
	local[16]= fqv[56];
	local[17]= local[9];
	ctx->vsp=local+18;
	w=(*ftab[64])(ctx,2,local+16,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	local[17]= fqv[228];
	local[18]= local[9];
	ctx->vsp=local+19;
	w=(*ftab[64])(ctx,2,local+17,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17]= (w)->c.cons.car;
	local[18]= fqv[135];
	local[19]= local[9];
	ctx->vsp=local+20;
	w=(*ftab[64])(ctx,2,local+18,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	local[19]= fqv[229];
	local[20]= local[9];
	ctx->vsp=local+21;
	w=(*ftab[64])(ctx,2,local+19,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	local[20]= fqv[230];
	local[21]= local[9];
	ctx->vsp=local+22;
	w=(*ftab[64])(ctx,2,local+20,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	local[21]= fqv[231];
	local[22]= local[9];
	ctx->vsp=local+23;
	w=(*ftab[64])(ctx,2,local+21,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	local[22]= fqv[232];
	local[23]= local[9];
	ctx->vsp=local+24;
	w=(*ftab[64])(ctx,2,local+22,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	local[23]= fqv[233];
	local[24]= local[9];
	ctx->vsp=local+25;
	w=(*ftab[64])(ctx,2,local+23,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15] = (w)->c.cons.car;
	if (local[16]==NIL) goto IF1658;
	local[23]= local[16];
	ctx->vsp=local+24;
	w=(*ftab[22])(ctx,1,local+23,&ftab[22],fqv[58]); /*glcolor3fv*/
	local[23]= makeint((eusinteger_t)1029L);
	local[24]= makeint((eusinteger_t)5634L);
	if (local[3]==NIL) goto IF1660;
	local[25]= loadglobal(fqv[140]);
	local[26]= local[16];
	local[27]= local[3];
	ctx->vsp=local+28;
	w=(pointer)MKFLTVEC(ctx,1,local+27); /*float-vector*/
	local[27]= w;
	ctx->vsp=local+28;
	w=(pointer)CONCATENATE(ctx,3,local+25); /*concatenate*/
	local[25]= w;
	goto IF1661;
IF1660:
	local[25]= local[16];
IF1661:
	ctx->vsp=local+26;
	w=(*ftab[40])(ctx,3,local+23,&ftab[40],fqv[103]); /*glmaterialfv*/
	local[23]= w;
	goto IF1659;
IF1658:
	local[23]= NIL;
IF1659:
	if (local[17]==NIL) goto IF1662;
	if (local[3]==NIL) goto IF1664;
	local[23]= local[17];
	local[24]= makeint((eusinteger_t)3L);
	local[25]= local[3];
	ctx->vsp=local+26;
	w=(pointer)SETELT(ctx,3,local+23); /*setelt*/
	local[23]= w;
	goto IF1665;
IF1664:
	local[23]= NIL;
IF1665:
	local[23]= makeint((eusinteger_t)1029L);
	local[24]= makeint((eusinteger_t)4608L);
	local[25]= local[17];
	ctx->vsp=local+26;
	w=(*ftab[40])(ctx,3,local+23,&ftab[40],fqv[103]); /*glmaterialfv*/
	local[23]= w;
	goto IF1663;
IF1662:
	local[23]= NIL;
IF1663:
	if (local[18]==NIL) goto IF1666;
	if (local[3]==NIL) goto IF1668;
	local[23]= local[18];
	local[24]= makeint((eusinteger_t)3L);
	local[25]= local[3];
	ctx->vsp=local+26;
	w=(pointer)SETELT(ctx,3,local+23); /*setelt*/
	local[23]= w;
	goto IF1669;
IF1668:
	local[23]= NIL;
IF1669:
	local[23]= makeint((eusinteger_t)1029L);
	local[24]= makeint((eusinteger_t)4609L);
	local[25]= local[18];
	ctx->vsp=local+26;
	w=(*ftab[40])(ctx,3,local+23,&ftab[40],fqv[103]); /*glmaterialfv*/
	local[23]= w;
	goto IF1667;
IF1666:
	local[23]= NIL;
IF1667:
	if (local[19]==NIL) goto IF1670;
	if (local[3]==NIL) goto IF1672;
	local[23]= local[19];
	local[24]= makeint((eusinteger_t)3L);
	local[25]= local[3];
	ctx->vsp=local+26;
	w=(pointer)SETELT(ctx,3,local+23); /*setelt*/
	local[23]= w;
	goto IF1673;
IF1672:
	local[23]= NIL;
IF1673:
	local[23]= makeint((eusinteger_t)1029L);
	local[24]= makeint((eusinteger_t)4610L);
	local[25]= local[19];
	ctx->vsp=local+26;
	w=(*ftab[40])(ctx,3,local+23,&ftab[40],fqv[103]); /*glmaterialfv*/
	local[23]= w;
	goto IF1671;
IF1670:
	local[23]= NIL;
IF1671:
	if (local[20]==NIL) goto IF1674;
	if (local[3]==NIL) goto IF1676;
	local[23]= local[20];
	local[24]= makeint((eusinteger_t)3L);
	local[25]= local[3];
	ctx->vsp=local+26;
	w=(pointer)SETELT(ctx,3,local+23); /*setelt*/
	local[23]= w;
	goto IF1677;
IF1676:
	local[23]= NIL;
IF1677:
	local[23]= makeint((eusinteger_t)1029L);
	local[24]= makeint((eusinteger_t)5632L);
	local[25]= local[20];
	ctx->vsp=local+26;
	w=(*ftab[40])(ctx,3,local+23,&ftab[40],fqv[103]); /*glmaterialfv*/
	local[23]= w;
	goto IF1675;
IF1674:
	local[23]= NIL;
IF1675:
	if (local[21]==NIL) goto CON1679;
	local[23]= makeint((eusinteger_t)1029L);
	local[24]= makeint((eusinteger_t)5633L);
	local[25]= local[21];
	ctx->vsp=local+26;
	w=(*ftab[75])(ctx,3,local+23,&ftab[75],fqv[234]); /*glmaterialf*/
	local[23]= w;
	goto CON1678;
CON1679:
	local[23]= makeint((eusinteger_t)1029L);
	local[24]= makeint((eusinteger_t)5633L);
	local[25]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+26;
	w=(*ftab[75])(ctx,3,local+23,&ftab[75],fqv[234]); /*glmaterialf*/
	local[23]= makeint((eusinteger_t)1029L);
	local[24]= makeint((eusinteger_t)4610L);
	local[25]= makeint((eusinteger_t)0L);
	local[26]= makeint((eusinteger_t)0L);
	local[27]= makeint((eusinteger_t)0L);
	local[28]= makeint((eusinteger_t)0L);
	ctx->vsp=local+29;
	w=(pointer)MKFLTVEC(ctx,4,local+25); /*float-vector*/
	local[25]= w;
	ctx->vsp=local+26;
	w=(*ftab[40])(ctx,3,local+23,&ftab[40],fqv[103]); /*glmaterialfv*/
	local[23]= w;
	goto CON1678;
CON1680:
	local[23]= NIL;
CON1678:
	if (local[15]==NIL) goto IF1681;
	if (local[13]==NIL) goto IF1681;
	local[23]= local[15];
	local[24]= fqv[15];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,2,local+23); /*send*/
	local[23]= w;
	local[24]= local[15];
	local[25]= fqv[14];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,2,local+24); /*send*/
	local[24]= w;
	local[25]= local[15];
	local[26]= fqv[17];
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,2,local+25); /*send*/
	local[25]= w;
	local[26]= makeint((eusinteger_t)3317L);
	local[27]= makeint((eusinteger_t)1L);
	ctx->vsp=local+28;
	w=(*ftab[17])(ctx,2,local+26,&ftab[17],fqv[47]); /*glpixelstorei*/
	local[26]= local[15];
	local[27]= loadglobal(fqv[108]);
	ctx->vsp=local+28;
	w=(pointer)DERIVEDP(ctx,2,local+26); /*derivedp*/
	if (w==NIL) goto CON1684;
	local[26]= makeint((eusinteger_t)3553L);
	local[27]= makeint((eusinteger_t)0L);
	local[28]= makeint((eusinteger_t)6407L);
	local[29]= local[23];
	local[30]= local[24];
	local[31]= makeint((eusinteger_t)0L);
	local[32]= makeint((eusinteger_t)6409L);
	local[33]= makeint((eusinteger_t)5121L);
	local[34]= local[25];
	ctx->vsp=local+35;
	w=(*ftab[45])(ctx,9,local+26,&ftab[45],fqv[119]); /*glteximage2d*/
	local[26]= w;
	goto CON1683;
CON1684:
	local[26]= local[15];
	local[27]= loadglobal(fqv[44]);
	ctx->vsp=local+28;
	w=(pointer)DERIVEDP(ctx,2,local+26); /*derivedp*/
	if (w==NIL) goto CON1685;
	local[26]= makeint((eusinteger_t)3553L);
	local[27]= makeint((eusinteger_t)0L);
	local[28]= makeint((eusinteger_t)6407L);
	local[29]= local[23];
	local[30]= local[24];
	local[31]= makeint((eusinteger_t)0L);
	local[32]= makeint((eusinteger_t)6407L);
	local[33]= makeint((eusinteger_t)5121L);
	local[34]= local[25];
	ctx->vsp=local+35;
	w=(*ftab[45])(ctx,9,local+26,&ftab[45],fqv[119]); /*glteximage2d*/
	local[26]= w;
	goto CON1683;
CON1685:
	local[26]= local[15];
	local[27]= loadglobal(fqv[235]);
	ctx->vsp=local+28;
	w=(pointer)DERIVEDP(ctx,2,local+26); /*derivedp*/
	if (w==NIL) goto CON1686;
	local[26]= makeint((eusinteger_t)3553L);
	local[27]= makeint((eusinteger_t)0L);
	local[28]= makeint((eusinteger_t)6408L);
	local[29]= local[23];
	local[30]= local[24];
	local[31]= makeint((eusinteger_t)0L);
	local[32]= makeint((eusinteger_t)6408L);
	local[33]= makeint((eusinteger_t)5121L);
	local[34]= local[25];
	ctx->vsp=local+35;
	w=(*ftab[45])(ctx,9,local+26,&ftab[45],fqv[119]); /*glteximage2d*/
	local[26]= w;
	goto CON1683;
CON1686:
	local[26]= NIL;
CON1683:
	local[26]= makeint((eusinteger_t)3553L);
	local[27]= makeint((eusinteger_t)10242L);
	local[28]= makeint((eusinteger_t)10497L);
	ctx->vsp=local+29;
	w=(*ftab[46])(ctx,3,local+26,&ftab[46],fqv[120]); /*gltexparameteri*/
	local[26]= makeint((eusinteger_t)3553L);
	local[27]= makeint((eusinteger_t)10243L);
	local[28]= makeint((eusinteger_t)10497L);
	ctx->vsp=local+29;
	w=(*ftab[46])(ctx,3,local+26,&ftab[46],fqv[120]); /*gltexparameteri*/
	local[26]= makeint((eusinteger_t)3553L);
	local[27]= makeint((eusinteger_t)10241L);
	local[28]= makeint((eusinteger_t)9728L);
	ctx->vsp=local+29;
	w=(*ftab[46])(ctx,3,local+26,&ftab[46],fqv[120]); /*gltexparameteri*/
	local[26]= makeint((eusinteger_t)3553L);
	local[27]= makeint((eusinteger_t)10240L);
	local[28]= makeint((eusinteger_t)9728L);
	ctx->vsp=local+29;
	w=(*ftab[46])(ctx,3,local+26,&ftab[46],fqv[120]); /*gltexparameteri*/
	local[26]= makeint((eusinteger_t)8960L);
	local[27]= makeint((eusinteger_t)8704L);
	local[28]= makeint((eusinteger_t)8448L);
	ctx->vsp=local+29;
	w=(*ftab[47])(ctx,3,local+26,&ftab[47],fqv[121]); /*gltexenvi*/
	local[26]= makeint((eusinteger_t)3553L);
	ctx->vsp=local+27;
	w=(*ftab[12])(ctx,1,local+26,&ftab[12],fqv[29]); /*glenable*/
	local[23]= w;
	goto IF1682;
IF1681:
	local[23]= NIL;
IF1682:
	if (local[3]==NIL) goto IF1687;
	local[23]= makeint((eusinteger_t)1028L);
	local[24]= makeint((eusinteger_t)5634L);
	local[25]= makeint((eusinteger_t)0L);
	local[26]= makeint((eusinteger_t)0L);
	local[27]= makeint((eusinteger_t)0L);
	local[28]= makeint((eusinteger_t)0L);
	ctx->vsp=local+29;
	w=(pointer)MKFLTVEC(ctx,4,local+25); /*float-vector*/
	local[25]= w;
	ctx->vsp=local+26;
	w=(*ftab[40])(ctx,3,local+23,&ftab[40],fqv[103]); /*glmaterialfv*/
	local[23]= w;
	goto IF1688;
IF1687:
	local[23]= NIL;
IF1688:
	w = local[23];
	local[16]= w;
	goto CON1652;
CON1657:
	local[16]= makeint((eusinteger_t)1029L);
	local[17]= makeint((eusinteger_t)4608L);
	local[18]= makeflt(1.9999999999999995559108e-01);
	local[19]= makeflt(1.9999999999999995559108e-01);
	local[20]= makeflt(1.9999999999999995559108e-01);
	local[21]= makeflt(9.9999999999999977795540e-02);
	ctx->vsp=local+22;
	w=(pointer)MKFLTVEC(ctx,4,local+18); /*float-vector*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(*ftab[40])(ctx,3,local+16,&ftab[40],fqv[103]); /*glmaterialfv*/
	local[16]= makeint((eusinteger_t)1029L);
	local[17]= makeint((eusinteger_t)4609L);
	local[18]= makeint((eusinteger_t)1L);
	local[19]= makeint((eusinteger_t)1L);
	local[20]= makeint((eusinteger_t)1L);
	local[21]= makeint((eusinteger_t)1L);
	ctx->vsp=local+22;
	w=(pointer)MKFLTVEC(ctx,4,local+18); /*float-vector*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(*ftab[40])(ctx,3,local+16,&ftab[40],fqv[103]); /*glmaterialfv*/
	local[16]= makeint((eusinteger_t)1029L);
	local[17]= makeint((eusinteger_t)4610L);
	local[18]= makeflt(1.9999999999999995559108e-01);
	local[19]= makeflt(1.9999999999999995559108e-01);
	local[20]= makeflt(1.9999999999999995559108e-01);
	local[21]= makeflt(9.9999999999999977795540e-02);
	ctx->vsp=local+22;
	w=(pointer)MKFLTVEC(ctx,4,local+18); /*float-vector*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(*ftab[40])(ctx,3,local+16,&ftab[40],fqv[103]); /*glmaterialfv*/
	local[16]= makeint((eusinteger_t)1029L);
	local[17]= makeint((eusinteger_t)5632L);
	local[18]= makeflt(9.9999999999999977795540e-02);
	local[19]= makeflt(9.9999999999999977795540e-02);
	local[20]= makeflt(9.9999999999999977795540e-02);
	local[21]= makeflt(9.9999999999999977795540e-02);
	ctx->vsp=local+22;
	w=(pointer)MKFLTVEC(ctx,4,local+18); /*float-vector*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(*ftab[40])(ctx,3,local+16,&ftab[40],fqv[103]); /*glmaterialfv*/
	local[16]= makeint((eusinteger_t)1028L);
	local[17]= makeint((eusinteger_t)4608L);
	local[18]= makeflt(7.9999999999999982236432e-01);
	local[19]= makeflt(0.0000000000000000000000e+00);
	local[20]= makeflt(5.4000000000000003552714e-01);
	local[21]= makeint((eusinteger_t)1L);
	ctx->vsp=local+22;
	w=(pointer)MKFLTVEC(ctx,4,local+18); /*float-vector*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(*ftab[40])(ctx,3,local+16,&ftab[40],fqv[103]); /*glmaterialfv*/
	local[16]= makeint((eusinteger_t)1028L);
	local[17]= makeint((eusinteger_t)4609L);
	local[18]= makeflt(7.9999999999999982236432e-01);
	local[19]= makeflt(0.0000000000000000000000e+00);
	local[20]= makeflt(5.4000000000000003552714e-01);
	local[21]= makeint((eusinteger_t)1L);
	ctx->vsp=local+22;
	w=(pointer)MKFLTVEC(ctx,4,local+18); /*float-vector*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(*ftab[40])(ctx,3,local+16,&ftab[40],fqv[103]); /*glmaterialfv*/
	local[16]= makeint((eusinteger_t)1028L);
	local[17]= makeint((eusinteger_t)4610L);
	local[18]= makeflt(1.9999999999999995559108e-01);
	local[19]= makeflt(1.9999999999999995559108e-01);
	local[20]= makeflt(1.9999999999999995559108e-01);
	local[21]= makeint((eusinteger_t)1L);
	ctx->vsp=local+22;
	w=(pointer)MKFLTVEC(ctx,4,local+18); /*float-vector*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(*ftab[40])(ctx,3,local+16,&ftab[40],fqv[103]); /*glmaterialfv*/
	local[16]= makeint((eusinteger_t)1028L);
	local[17]= makeint((eusinteger_t)5632L);
	local[18]= makeflt(9.9999999999999977795540e-02);
	local[19]= makeflt(9.9999999999999977795540e-02);
	local[20]= makeflt(9.9999999999999977795540e-02);
	local[21]= makeint((eusinteger_t)1L);
	ctx->vsp=local+22;
	w=(pointer)MKFLTVEC(ctx,4,local+18); /*float-vector*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(*ftab[40])(ctx,3,local+16,&ftab[40],fqv[103]); /*glmaterialfv*/
	local[16]= w;
	goto CON1652;
CON1689:
	local[16]= NIL;
CON1652:
	if (local[15]==NIL) goto AND1692;
	if (local[13]==NIL) goto AND1692;
	goto IF1690;
AND1692:
	local[13] = NIL;
	local[16]= local[13];
	goto IF1691;
IF1690:
	local[16]= NIL;
IF1691:
	local[16]= makeint((eusinteger_t)32884L);
	ctx->vsp=local+17;
	w=(*ftab[76])(ctx,1,local+16,&ftab[76],fqv[236]); /*glenableclientstate*/
	local[16]= makeint((eusinteger_t)3L);
	local[17]= makeint((eusinteger_t)5130L);
	local[18]= makeint((eusinteger_t)0L);
	local[19]= local[10]->c.obj.iv[1];
	ctx->vsp=local+20;
	w=(*ftab[77])(ctx,4,local+16,&ftab[77],fqv[237]); /*glvertexpointer*/
	if (local[11]==NIL) goto IF1693;
	local[16]= makeint((eusinteger_t)32885L);
	ctx->vsp=local+17;
	w=(*ftab[76])(ctx,1,local+16,&ftab[76],fqv[236]); /*glenableclientstate*/
	local[16]= makeint((eusinteger_t)5130L);
	local[17]= makeint((eusinteger_t)0L);
	local[18]= local[11]->c.obj.iv[1];
	ctx->vsp=local+19;
	w=(*ftab[78])(ctx,3,local+16,&ftab[78],fqv[238]); /*glnormalpointer*/
	local[16]= w;
	goto IF1694;
IF1693:
	local[16]= NIL;
IF1694:
	if (local[13]==NIL) goto IF1695;
	local[16]= makeint((eusinteger_t)32888L);
	ctx->vsp=local+17;
	w=(*ftab[76])(ctx,1,local+16,&ftab[76],fqv[236]); /*glenableclientstate*/
	local[16]= makeint((eusinteger_t)2L);
	local[17]= makeint((eusinteger_t)5130L);
	local[18]= makeint((eusinteger_t)0L);
	local[19]= local[13];
	ctx->vsp=local+20;
	w=(*ftab[79])(ctx,4,local+16,&ftab[79],fqv[239]); /*gltexcoordpointer*/
	local[16]= w;
	goto IF1696;
IF1695:
	local[16]= NIL;
IF1696:
	local[16]= NIL;
	local[17]= local[8];
	local[18]= local[17];
	if (fqv[197]!=local[18]) goto IF1698;
	local[16] = makeint((eusinteger_t)4L);
	local[18]= local[16];
	goto IF1699;
IF1698:
	local[18]= local[17];
	if (fqv[198]!=local[18]) goto IF1700;
	local[16] = makeint((eusinteger_t)7L);
	local[18]= local[16];
	goto IF1701;
IF1700:
	local[18]= local[17];
	if (fqv[199]!=local[18]) goto IF1702;
	local[16] = makeint((eusinteger_t)1L);
	local[18]= local[16];
	goto IF1703;
IF1702:
	local[18]= local[17];
	if (fqv[200]!=local[18]) goto IF1704;
	local[16] = makeint((eusinteger_t)4L);
	local[18]= fqv[240];
	ctx->vsp=local+19;
	w=(*ftab[24])(ctx,1,local+18,&ftab[24],fqv[70]); /*warn*/
	local[18]= w;
	goto IF1705;
IF1704:
	if (T==NIL) goto IF1706;
	local[18]= fqv[241];
	ctx->vsp=local+19;
	w=(*ftab[24])(ctx,1,local+18,&ftab[24],fqv[70]); /*warn*/
	local[18]= local[8];
	goto IF1707;
IF1706:
	local[18]= NIL;
IF1707:
IF1705:
IF1703:
IF1701:
IF1699:
	w = local[18];
	if (local[16]==NIL) goto IF1708;
	if (local[12]==NIL) goto CON1711;
	local[17]= local[16];
	local[18]= local[12];
	ctx->vsp=local+19;
	w=(pointer)LENGTH(ctx,1,local+18); /*length*/
	local[18]= w;
	local[19]= makeint((eusinteger_t)5125L);
	local[20]= local[12];
	ctx->vsp=local+21;
	w=(*ftab[80])(ctx,1,local+20,&ftab[80],fqv[242]); /*user::lvector2integer-bytestring*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(*ftab[81])(ctx,4,local+17,&ftab[81],fqv[243]); /*gldrawelements*/
	local[17]= w;
	goto CON1710;
CON1711:
	local[17]= local[16];
	local[18]= makeint((eusinteger_t)0L);
	local[19]= local[10];
	local[20]= makeint((eusinteger_t)0L);
	ctx->vsp=local+21;
	w=(*ftab[66])(ctx,2,local+19,&ftab[66],fqv[182]); /*array-dimension*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(*ftab[82])(ctx,3,local+17,&ftab[82],fqv[244]); /*gldrawarrays*/
	local[17]= w;
	goto CON1710;
CON1712:
	local[17]= NIL;
CON1710:
	goto IF1709;
IF1708:
	local[17]= NIL;
IF1709:
	w = local[17];
	if (local[13]==NIL) goto IF1713;
	local[16]= makeint((eusinteger_t)3553L);
	ctx->vsp=local+17;
	w=(*ftab[8])(ctx,1,local+16,&ftab[8],fqv[25]); /*gldisable*/
	local[16]= makeint((eusinteger_t)32888L);
	ctx->vsp=local+17;
	w=(*ftab[83])(ctx,1,local+16,&ftab[83],fqv[245]); /*gldisableclientstate*/
	local[16]= w;
	goto IF1714;
IF1713:
	local[16]= NIL;
IF1714:
	if (local[11]==NIL) goto IF1715;
	local[16]= makeint((eusinteger_t)32885L);
	ctx->vsp=local+17;
	w=(*ftab[83])(ctx,1,local+16,&ftab[83],fqv[245]); /*gldisableclientstate*/
	local[16]= w;
	goto IF1716;
IF1715:
	local[16]= NIL;
IF1716:
	local[16]= makeint((eusinteger_t)32884L);
	ctx->vsp=local+17;
	w=(*ftab[83])(ctx,1,local+16,&ftab[83],fqv[245]); /*gldisableclientstate*/
	if (local[14]==NIL) goto IF1717;
	local[16]= makeint((eusinteger_t)7425L);
	ctx->vsp=local+17;
	w=(*ftab[12])(ctx,1,local+16,&ftab[12],fqv[29]); /*glenable*/
	local[16]= makeint((eusinteger_t)7425L);
	ctx->vsp=local+17;
	w=(*ftab[74])(ctx,1,local+16,&ftab[74],fqv[227]); /*glshademodel*/
	local[16]= w;
	goto IF1718;
IF1717:
	local[16]= NIL;
IF1718:
	w = local[16];
	goto WHL1646;
WHX1647:
	local[8]= NIL;
BLK1648:
	w = NIL;
	if (local[3]==NIL) goto IF1719;
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(*ftab[73])(ctx,1,local+6,&ftab[73],fqv[225]); /*gldepthmask*/
	local[6]= makeint((eusinteger_t)3042L);
	ctx->vsp=local+7;
	w=(*ftab[8])(ctx,1,local+6,&ftab[8],fqv[25]); /*gldisable*/
	local[6]= w;
	goto IF1720;
IF1719:
	local[6]= NIL;
IF1720:
	ctx->vsp=local+6;
	w=(*ftab[38])(ctx,0,local+6,&ftab[38],fqv[99]); /*glendlist*/
	local[6]= argv[0];
	local[7]= local[5];
	w = local[1];
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= argv[0];
	local[9]= fqv[71];
	ctx->vsp=local+10;
	w=(pointer)GETPROP(ctx,2,local+8); /*get*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[71];
	ctx->vsp=local+9;
	w=(pointer)PUTPROP(ctx,3,local+6); /*putprop*/
	local[1] = NIL;
	local[6]= local[1];
	goto CON1638;
CON1640:
	local[6]= NIL;
CON1638:
	local[6]= makeint((eusinteger_t)2898L);
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(*ftab[72])(ctx,2,local+6,&ftab[72],fqv[224]); /*gllightmodeli*/
	ctx->vsp=local+6;
	w=(*ftab[28])(ctx,0,local+6,&ftab[28],fqv[80]); /*glpopmatrix*/
	ctx->vsp=local+6;
	w=(*ftab[37])(ctx,0,local+6,&ftab[37],fqv[98]); /*glpopattrib*/
	if (local[1]!=NIL) goto IF1721;
	local[6]= argv[0];
	local[7]= fqv[64];
	local[8]= argv[2];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	goto IF1722;
IF1721:
	local[6]= NIL;
IF1722:
	w = local[6];
	local[0]= w;
BLK1636:
	ctx->vsp=local; return(local[0]);}

/*:collision-check-objects*/
static pointer M1723glvertices_collision_check_objects(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1725:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	w = NIL;
	local[0]= w;
BLK1724:
	ctx->vsp=local; return(local[0]);}

/*:box*/
static pointer M1726glvertices_box(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[10]!=NIL) goto IF1728;
	local[0]= argv[0];
	local[1]= fqv[186];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF1729;
IF1728:
	local[0]= NIL;
IF1729:
	w = argv[0]->c.obj.iv[10];
	local[0]= w;
BLK1727:
	ctx->vsp=local; return(local[0]);}

/*:make-pqpmodel*/
static pointer M1730glvertices_make_pqpmodel(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[246], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY1732;
	local[0] = makeint((eusinteger_t)0L);
KEY1732:
	ctx->vsp=local+1;
	w=(*ftab[84])(ctx,0,local+1,&ftab[84],fqv[247]); /*geometry::pqpmakemodel*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= makeint((eusinteger_t)0L);
	local[6]= NIL;
	local[7]= argv[0]->c.obj.iv[8];
WHL1734:
	if (local[7]==NIL) goto WHX1735;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= fqv[196];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(*ftab[64])(ctx,2,local+8,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= local[8];
	if (fqv[197]==local[9]) goto IF1738;
	local[9]= fqv[248];
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(*ftab[24])(ctx,2,local+9,&ftab[24],fqv[70]); /*warn*/
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(*ftab[85])(ctx,1,local+9,&ftab[85],fqv[249]); /*geometry::pqpdeletemodel*/
	w = NIL;
	ctx->vsp=local+9;
	local[0]=w;
	goto BLK1731;
	goto IF1739;
IF1738:
	local[9]= NIL;
IF1739:
	w = local[9];
	goto WHL1734;
WHX1735:
	local[8]= NIL;
BLK1736:
	w = NIL;
	local[6]= makeint((eusinteger_t)0L);
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,3,local+6); /*float-vector*/
	local[2] = w;
	local[6]= makeint((eusinteger_t)0L);
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,3,local+6); /*float-vector*/
	local[3] = w;
	local[6]= makeint((eusinteger_t)0L);
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,3,local+6); /*float-vector*/
	local[4] = w;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[86])(ctx,1,local+6,&ftab[86],fqv[250]); /*geometry::pqpbeginmodel*/
	local[6]= NIL;
	local[7]= argv[0]->c.obj.iv[8];
WHL1741:
	if (local[7]==NIL) goto WHX1742;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= fqv[87];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(*ftab[64])(ctx,2,local+8,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= fqv[192];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(*ftab[64])(ctx,2,local+9,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= local[9];
	ctx->vsp=local+11;
	w=(pointer)LENGTH(ctx,1,local+10); /*length*/
	local[10]= w;
	local[11]= makeint((eusinteger_t)3L);
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[10]= w;
	local[11]= makeint((eusinteger_t)3L);
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	if (local[9]==NIL) goto CON1746;
	local[11]= makeint((eusinteger_t)0L);
TAG1749:
	local[12]= local[11];
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(pointer)GREQP(ctx,2,local+12); /*>=*/
	if (w==NIL) goto IF1750;
	w = NIL;
	ctx->vsp=local+12;
	local[11]=w;
	goto BLK1748;
	goto IF1751;
IF1750:
	local[12]= NIL;
IF1751:
	local[12]= local[8];
	local[13]= local[9];
	local[14]= local[11];
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(*ftab[67])(ctx,3,local+12,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[12]= local[8];
	local[13]= local[9];
	local[14]= local[11];
	local[15]= makeint((eusinteger_t)1L);
	ctx->vsp=local+16;
	w=(pointer)PLUS(ctx,2,local+14); /*+*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(*ftab[67])(ctx,3,local+12,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[12]= local[8];
	local[13]= local[9];
	local[14]= local[11];
	local[15]= makeint((eusinteger_t)2L);
	ctx->vsp=local+16;
	w=(pointer)PLUS(ctx,2,local+14); /*+*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	local[14]= local[4];
	ctx->vsp=local+15;
	w=(*ftab[67])(ctx,3,local+12,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[12]= local[0];
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(pointer)NUMEQUAL(ctx,2,local+12); /*=*/
	if (w!=NIL) goto IF1752;
	local[12]= local[2];
	local[13]= local[0];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)VNORMALIZE(ctx,1,local+14); /*normalize-vector*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SCALEVEC(ctx,2,local+13); /*scale*/
	local[13]= w;
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)VPLUS(ctx,3,local+12); /*v+*/
	local[12]= local[3];
	local[13]= local[0];
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(pointer)VNORMALIZE(ctx,1,local+14); /*normalize-vector*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SCALEVEC(ctx,2,local+13); /*scale*/
	local[13]= w;
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(pointer)VPLUS(ctx,3,local+12); /*v+*/
	local[12]= local[4];
	local[13]= local[0];
	local[14]= local[4];
	ctx->vsp=local+15;
	w=(pointer)VNORMALIZE(ctx,1,local+14); /*normalize-vector*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SCALEVEC(ctx,2,local+13); /*scale*/
	local[13]= w;
	local[14]= local[4];
	ctx->vsp=local+15;
	w=(pointer)VPLUS(ctx,3,local+12); /*v+*/
	local[12]= w;
	goto IF1753;
IF1752:
	local[12]= NIL;
IF1753:
	local[12]= local[1];
	local[13]= local[2];
	local[14]= local[3];
	local[15]= local[4];
	local[16]= local[5];
	ctx->vsp=local+17;
	w=(*ftab[87])(ctx,5,local+12,&ftab[87],fqv[251]); /*geometry::pqpaddtri*/
	local[12]= local[5];
	ctx->vsp=local+13;
	w=(pointer)ADD1(ctx,1,local+12); /*1+*/
	local[5] = w;
	local[12]= local[11];
	local[13]= makeint((eusinteger_t)3L);
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,2,local+12); /*+*/
	local[12]= w;
	local[11] = local[12];
	w = NIL;
	ctx->vsp=local+12;
	goto TAG1749;
	w = NIL;
	local[11]= w;
BLK1748:
	goto CON1745;
CON1746:
	local[11]= makeint((eusinteger_t)0L);
TAG1758:
	local[12]= local[11];
	local[13]= local[8];
	local[14]= makeint((eusinteger_t)0L);
	ctx->vsp=local+15;
	w=(*ftab[66])(ctx,2,local+13,&ftab[66],fqv[182]); /*array-dimension*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)GREQP(ctx,2,local+12); /*>=*/
	if (w==NIL) goto IF1759;
	w = NIL;
	ctx->vsp=local+12;
	local[11]=w;
	goto BLK1757;
	goto IF1760;
IF1759:
	local[12]= NIL;
IF1760:
	local[12]= local[8];
	local[13]= local[11];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(*ftab[67])(ctx,3,local+12,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[12]= local[8];
	local[13]= local[11];
	local[14]= makeint((eusinteger_t)1L);
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,2,local+13); /*+*/
	local[13]= w;
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(*ftab[67])(ctx,3,local+12,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[12]= local[8];
	local[13]= local[11];
	local[14]= makeint((eusinteger_t)2L);
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,2,local+13); /*+*/
	local[13]= w;
	local[14]= local[4];
	ctx->vsp=local+15;
	w=(*ftab[67])(ctx,3,local+12,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[12]= local[0];
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(pointer)NUMEQUAL(ctx,2,local+12); /*=*/
	if (w!=NIL) goto IF1761;
	local[12]= local[2];
	local[13]= local[0];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)VNORMALIZE(ctx,1,local+14); /*normalize-vector*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SCALEVEC(ctx,2,local+13); /*scale*/
	local[13]= w;
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)VPLUS(ctx,3,local+12); /*v+*/
	local[12]= local[3];
	local[13]= local[0];
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(pointer)VNORMALIZE(ctx,1,local+14); /*normalize-vector*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SCALEVEC(ctx,2,local+13); /*scale*/
	local[13]= w;
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(pointer)VPLUS(ctx,3,local+12); /*v+*/
	local[12]= local[4];
	local[13]= local[0];
	local[14]= local[4];
	ctx->vsp=local+15;
	w=(pointer)VNORMALIZE(ctx,1,local+14); /*normalize-vector*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SCALEVEC(ctx,2,local+13); /*scale*/
	local[13]= w;
	local[14]= local[4];
	ctx->vsp=local+15;
	w=(pointer)VPLUS(ctx,3,local+12); /*v+*/
	local[12]= w;
	goto IF1762;
IF1761:
	local[12]= NIL;
IF1762:
	local[12]= local[1];
	local[13]= local[2];
	local[14]= local[3];
	local[15]= local[4];
	local[16]= local[5];
	ctx->vsp=local+17;
	w=(*ftab[87])(ctx,5,local+12,&ftab[87],fqv[251]); /*geometry::pqpaddtri*/
	local[12]= local[5];
	ctx->vsp=local+13;
	w=(pointer)ADD1(ctx,1,local+12); /*1+*/
	local[5] = w;
	local[12]= local[11];
	local[13]= makeint((eusinteger_t)3L);
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,2,local+12); /*+*/
	local[12]= w;
	local[11] = local[12];
	w = NIL;
	ctx->vsp=local+12;
	goto TAG1758;
	w = NIL;
	local[11]= w;
BLK1757:
	goto CON1745;
CON1755:
	local[11]= NIL;
CON1745:
	w = local[11];
	goto WHL1741;
WHX1742:
	local[8]= NIL;
BLK1743:
	w = NIL;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[88])(ctx,1,local+6,&ftab[88],fqv[252]); /*geometry::pqpendmodel*/
	w = local[1];
	local[0]= w;
BLK1731:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1369(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[2];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[64])(ctx,2,local+0,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1547(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= fqv[171];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1572(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= fqv[171];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1611(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env2[1];
	local[1]= env->c.clo.env2[0];
	local[2]= fqv[113];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[64])(ctx,2,local+2,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)FUNCALL(ctx,3,local+0); /*funcall*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:glvertices*/
static pointer M1764glbody_glvertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1766:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0]->c.obj.iv[16];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[89])(ctx,2,local+1,&ftab[89],fqv[253]); /*user::forward-message-to*/
	local[0]= w;
BLK1765:
	ctx->vsp=local; return(local[0]);}

/*:draw*/
static pointer M1767glbody_draw(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[0]->c.obj.iv[16]==NIL) goto IF1769;
	local[0]= argv[0]->c.obj.iv[16];
	local[1]= fqv[64];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF1770;
IF1769:
	local[0]= NIL;
IF1770:
	w = local[0];
	local[0]= w;
BLK1768:
	ctx->vsp=local; return(local[0]);}

/*:set-color*/
static pointer M1771glbody_set_color(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1773:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[175]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[36]));
	local[4]= fqv[254];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	if (argv[0]->c.obj.iv[16]==NIL) goto IF1774;
	local[1]= (pointer)get_sym_func(fqv[214]);
	local[2]= argv[0]->c.obj.iv[16];
	local[3]= fqv[254];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[1]= w;
	goto IF1775;
IF1774:
	local[1]= NIL;
IF1775:
	w = local[1];
	local[0]= w;
BLK1772:
	ctx->vsp=local; return(local[0]);}

/*make-glvertices-from-faceset*/
static pointer F984make_glvertices_from_faceset(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[255], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY1777;
	local[0] = NIL;
KEY1777:
	local[1]= NIL;
	if (local[0]==NIL) goto CON1779;
	local[1] = local[0];
	local[2]= local[1];
	goto CON1778;
CON1779:
	local[2]= argv[0];
	local[3]= fqv[73];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	if (w==NIL) goto CON1780;
	local[2]= argv[0];
	local[3]= fqv[73];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)VECTORP(ctx,1,local+3); /*vectorp*/
	if (w!=NIL) goto IF1781;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)F982find_color(ctx,1,local+3); /*find-color*/
	local[2] = w;
	local[3]= local[2];
	goto IF1782;
IF1781:
	local[3]= NIL;
IF1782:
	local[3]= fqv[228];
	local[4]= local[2];
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	local[5]= local[2];
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	local[6]= local[2];
	local[7]= makeint((eusinteger_t)2L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[3]= w;
	local[4]= fqv[135];
	local[5]= local[2];
	local[6]= makeint((eusinteger_t)0L);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	local[6]= local[2];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	local[7]= local[2];
	local[8]= makeint((eusinteger_t)2L);
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,2,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[1] = w;
	w = local[1];
	local[2]= w;
	goto CON1778;
CON1780:
	local[2]= fqv[228];
	local[3]= makeflt(6.4999999999999991118216e-01);
	local[4]= makeflt(6.4999999999999991118216e-01);
	local[5]= makeflt(6.4999999999999991118216e-01);
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	local[3]= fqv[135];
	local[4]= makeflt(6.4999999999999991118216e-01);
	local[5]= makeflt(6.4999999999999991118216e-01);
	local[6]= makeflt(6.4999999999999991118216e-01);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[1] = w;
	local[2]= local[1];
	goto CON1778;
CON1783:
	local[2]= NIL;
CON1778:
	local[2]= argv[0];
	local[3]= fqv[86];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= fqv[180];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)F985make_glvertices_from_faces(ctx,3,local+2); /*make-glvertices-from-faces*/
	local[0]= w;
BLK1776:
	ctx->vsp=local; return(local[0]);}

/*make-glvertices-from-faces*/
static pointer F985make_glvertices_from_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[256], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY1785;
	local[0] = NIL;
KEY1785:
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO1786,env,argv,local);
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[70])(ctx,1,local+1,&ftab[70],fqv[213]); /*flatten*/
	argv[0] = w;
	local[1]= makeint((eusinteger_t)3L);
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	{ eusinteger_t i,j;
		j=intval(w); i=intval(local[1]);
		local[1]=(makeint(i * j));}
	local[2]= makeint((eusinteger_t)3L);
	ctx->vsp=local+3;
	w=(*ftab[69])(ctx,2,local+1,&ftab[69],fqv[193]); /*make-matrix*/
	local[1]= w;
	local[2]= makeint((eusinteger_t)3L);
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	{ eusinteger_t i,j;
		j=intval(w); i=intval(local[2]);
		local[2]=(makeint(i * j));}
	local[3]= makeint((eusinteger_t)3L);
	ctx->vsp=local+4;
	w=(*ftab[69])(ctx,2,local+2,&ftab[69],fqv[193]); /*make-matrix*/
	local[2]= w;
	local[3]= loadglobal(fqv[101]);
	local[4]= makeint((eusinteger_t)3L);
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	{ eusinteger_t i,j;
		j=intval(w); i=intval(local[4]);
		local[4]=(makeint(i * j));}
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,2,local+3); /*instantiate*/
	local[3]= w;
	local[4]= makeint((eusinteger_t)0L);
	local[5]= NIL;
	local[6]= argv[0];
WHL1788:
	if (local[6]==NIL) goto WHX1789;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[5];
	local[8]= fqv[94];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)VNORMALIZE(ctx,1,local+7); /*normalize-vector*/
	local[7]= w;
	local[8]= local[5];
	local[9]= fqv[87];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= local[1];
	local[10]= local[4];
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= T;
	ctx->vsp=local+13;
	w=(*ftab[67])(ctx,4,local+9,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[9]= local[2];
	local[10]= local[4];
	local[11]= local[7];
	local[12]= T;
	ctx->vsp=local+13;
	w=(*ftab[67])(ctx,4,local+9,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	local[4] = w;
	local[9]= local[1];
	local[10]= local[4];
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= T;
	ctx->vsp=local+13;
	w=(*ftab[67])(ctx,4,local+9,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[9]= local[2];
	local[10]= local[4];
	local[11]= local[7];
	local[12]= T;
	ctx->vsp=local+13;
	w=(*ftab[67])(ctx,4,local+9,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	local[4] = w;
	local[9]= local[1];
	local[10]= local[4];
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= T;
	ctx->vsp=local+13;
	w=(*ftab[67])(ctx,4,local+9,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[9]= local[2];
	local[10]= local[4];
	local[11]= local[7];
	local[12]= T;
	ctx->vsp=local+13;
	w=(*ftab[67])(ctx,4,local+9,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	local[4] = w;
	w = local[4];
	goto WHL1788;
WHX1789:
	local[7]= NIL;
BLK1790:
	w = NIL;
	local[5]= makeint((eusinteger_t)0L);
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
WHL1793:
	local[7]= local[5];
	w = local[6];
	if ((eusinteger_t)local[7] >= (eusinteger_t)w) goto WHX1794;
	local[7]= local[3];
	local[8]= local[5];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)SETELT(ctx,3,local+7); /*setelt*/
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[5] = w;
	goto WHL1793;
WHX1794:
	local[7]= NIL;
BLK1795:
	w = NIL;
	local[5]= fqv[196];
	local[6]= fqv[197];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,2,local+5); /*list*/
	local[5]= w;
	local[6]= fqv[87];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	local[7]= fqv[194];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	local[8]= fqv[192];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,2,local+8); /*list*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,4,local+5); /*list*/
	local[5]= w;
	if (local[0]==NIL) goto IF1796;
	local[6]= fqv[180];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	w = local[5];
	ctx->vsp=local+7;
	local[5] = cons(ctx,local[6],w);
	local[6]= local[5];
	goto IF1797;
IF1796:
	local[6]= NIL;
IF1797:
	local[6]= loadglobal(fqv[205]);
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,1,local+6); /*instantiate*/
	local[6]= w;
	local[7]= local[6];
	local[8]= fqv[45];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	w = local[6];
	local[0]= w;
BLK1784:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1786(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[90])(ctx,1,local+0,&ftab[90],fqv[257]); /*geometry::face-to-triangle-aux*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*_dump-wrl-shape*/
static pointer F986_dump_wrl_shape(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[258], &argv[2], n-2, local+0, 1);
	if (n & (1<<0)) goto KEY1800;
	local[0] = makeflt(1.0000000000000000000000e+00);
KEY1800:
	if (n & (1<<1)) goto KEY1801;
	local[1] = NIL;
KEY1801:
	if (n & (1<<2)) goto KEY1802;
	local[2] = NIL;
KEY1802:
	if (n & (1<<3)) goto KEY1803;
	local[3] = NIL;
KEY1803:
	local[4]= fqv[196];
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(*ftab[64])(ctx,2,local+4,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= fqv[192];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(*ftab[64])(ctx,2,local+5,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= fqv[87];
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(*ftab[64])(ctx,2,local+6,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= fqv[180];
	local[8]= argv[1];
	ctx->vsp=local+9;
	w=(*ftab[64])(ctx,2,local+7,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= fqv[226];
	local[9]= argv[1];
	ctx->vsp=local+10;
	w=(*ftab[64])(ctx,2,local+8,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= fqv[194];
	local[10]= argv[1];
	ctx->vsp=local+11;
	w=(*ftab[64])(ctx,2,local+9,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= local[6]->c.obj.iv[1];
	ctx->vsp=local+11;
	w=(pointer)LENGTH(ctx,1,local+10); /*length*/
	local[10]= w;
	local[11]= makeint((eusinteger_t)3L);
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[10]= w;
	local[11]= argv[0];
	local[12]= fqv[259];
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,2,local+11); /*format*/
	local[11]= fqv[56];
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(*ftab[64])(ctx,2,local+11,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= fqv[228];
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(*ftab[64])(ctx,2,local+12,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= fqv[135];
	local[14]= local[7];
	ctx->vsp=local+15;
	w=(*ftab[64])(ctx,2,local+13,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	local[14]= fqv[229];
	local[15]= local[7];
	ctx->vsp=local+16;
	w=(*ftab[64])(ctx,2,local+14,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	local[15]= fqv[230];
	local[16]= local[7];
	ctx->vsp=local+17;
	w=(*ftab[64])(ctx,2,local+15,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	local[16]= fqv[231];
	local[17]= local[7];
	ctx->vsp=local+18;
	w=(*ftab[64])(ctx,2,local+16,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	local[17]= fqv[232];
	local[18]= local[7];
	ctx->vsp=local+19;
	w=(*ftab[64])(ctx,2,local+17,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17]= (w)->c.cons.car;
	local[18]= fqv[260];
	local[19]= local[7];
	ctx->vsp=local+20;
	w=(*ftab[64])(ctx,2,local+18,&ftab[64],fqv[177]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	local[19]= argv[0];
	local[20]= fqv[261];
	ctx->vsp=local+21;
	w=(pointer)XFORMAT(ctx,2,local+19); /*format*/
	if (local[13]==NIL) goto IF1804;
	local[19]= argv[0];
	local[20]= fqv[262];
	local[21]= local[13];
	local[22]= makeint((eusinteger_t)0L);
	ctx->vsp=local+23;
	w=(pointer)ELT(ctx,2,local+21); /*elt*/
	local[21]= w;
	local[22]= local[13];
	local[23]= makeint((eusinteger_t)1L);
	ctx->vsp=local+24;
	w=(pointer)ELT(ctx,2,local+22); /*elt*/
	local[22]= w;
	local[23]= local[13];
	local[24]= makeint((eusinteger_t)2L);
	ctx->vsp=local+25;
	w=(pointer)ELT(ctx,2,local+23); /*elt*/
	local[23]= w;
	ctx->vsp=local+24;
	w=(pointer)XFORMAT(ctx,5,local+19); /*format*/
	local[19]= w;
	goto IF1805;
IF1804:
	local[19]= NIL;
IF1805:
	if (local[1]==NIL) goto IF1806;
	if (local[12]==NIL) goto IF1806;
	local[19]= argv[0];
	local[20]= fqv[263];
	local[21]= local[12];
	local[22]= makeint((eusinteger_t)0L);
	ctx->vsp=local+23;
	w=(pointer)ELT(ctx,2,local+21); /*elt*/
	local[21]= w;
	local[22]= local[12];
	local[23]= makeint((eusinteger_t)1L);
	ctx->vsp=local+24;
	w=(pointer)ELT(ctx,2,local+22); /*elt*/
	local[22]= w;
	local[23]= local[12];
	local[24]= makeint((eusinteger_t)2L);
	ctx->vsp=local+25;
	w=(pointer)ELT(ctx,2,local+23); /*elt*/
	local[23]= w;
	ctx->vsp=local+24;
	w=(pointer)XFORMAT(ctx,5,local+19); /*format*/
	local[19]= w;
	goto IF1807;
IF1806:
	local[19]= NIL;
IF1807:
	if (local[14]==NIL) goto IF1808;
	local[19]= argv[0];
	local[20]= fqv[264];
	local[21]= local[14];
	local[22]= makeint((eusinteger_t)0L);
	ctx->vsp=local+23;
	w=(pointer)ELT(ctx,2,local+21); /*elt*/
	local[21]= w;
	local[22]= local[14];
	local[23]= makeint((eusinteger_t)1L);
	ctx->vsp=local+24;
	w=(pointer)ELT(ctx,2,local+22); /*elt*/
	local[22]= w;
	local[23]= local[14];
	local[24]= makeint((eusinteger_t)2L);
	ctx->vsp=local+25;
	w=(pointer)ELT(ctx,2,local+23); /*elt*/
	local[23]= w;
	ctx->vsp=local+24;
	w=(pointer)XFORMAT(ctx,5,local+19); /*format*/
	local[19]= w;
	goto IF1809;
IF1808:
	local[19]= NIL;
IF1809:
	if (local[15]==NIL) goto IF1810;
	local[19]= argv[0];
	local[20]= fqv[265];
	local[21]= local[15];
	local[22]= makeint((eusinteger_t)0L);
	ctx->vsp=local+23;
	w=(pointer)ELT(ctx,2,local+21); /*elt*/
	local[21]= w;
	local[22]= local[15];
	local[23]= makeint((eusinteger_t)1L);
	ctx->vsp=local+24;
	w=(pointer)ELT(ctx,2,local+22); /*elt*/
	local[22]= w;
	local[23]= local[15];
	local[24]= makeint((eusinteger_t)2L);
	ctx->vsp=local+25;
	w=(pointer)ELT(ctx,2,local+23); /*elt*/
	local[23]= w;
	ctx->vsp=local+24;
	w=(pointer)XFORMAT(ctx,5,local+19); /*format*/
	local[19]= w;
	goto IF1811;
IF1810:
	local[19]= NIL;
IF1811:
	if (local[16]==NIL) goto IF1812;
	local[19]= argv[0];
	local[20]= fqv[266];
	local[21]= local[16];
	ctx->vsp=local+22;
	w=(pointer)XFORMAT(ctx,3,local+19); /*format*/
	local[19]= w;
	goto IF1813;
IF1812:
	local[19]= NIL;
IF1813:
	if (local[17]==NIL) goto IF1814;
	local[19]= argv[0];
	local[20]= fqv[267];
	local[21]= local[17];
	ctx->vsp=local+22;
	w=(pointer)XFORMAT(ctx,3,local+19); /*format*/
	local[19]= w;
	goto IF1815;
IF1814:
	local[19]= NIL;
IF1815:
	local[19]= argv[0];
	local[20]= fqv[268];
	ctx->vsp=local+21;
	w=(pointer)XFORMAT(ctx,2,local+19); /*format*/
	local[19]= argv[0];
	local[20]= fqv[269];
	ctx->vsp=local+21;
	w=(pointer)XFORMAT(ctx,2,local+19); /*format*/
	local[19]= argv[0];
	local[20]= fqv[270];
	ctx->vsp=local+21;
	w=(pointer)XFORMAT(ctx,2,local+19); /*format*/
	local[11]= argv[0];
	local[12]= fqv[271];
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,2,local+11); /*format*/
	local[11]= makeint((eusinteger_t)0L);
	local[12]= makeint((eusinteger_t)0L);
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(pointer)MKFLTVEC(ctx,3,local+11); /*float-vector*/
	local[11]= w;
	local[12]= makeint((eusinteger_t)0L);
	local[13]= local[10];
WHL1817:
	local[14]= local[12];
	w = local[13];
	if ((eusinteger_t)local[14] >= (eusinteger_t)w) goto WHX1818;
	local[14]= local[6];
	local[15]= local[12];
	local[16]= local[11];
	ctx->vsp=local+17;
	w=(*ftab[67])(ctx,3,local+14,&ftab[67],fqv[183]); /*user::c-matrix-row*/
	local[14]= argv[0];
	local[15]= fqv[272];
	local[16]= local[0];
	local[17]= local[11];
	local[18]= makeint((eusinteger_t)0L);
	ctx->vsp=local+19;
	w=(pointer)ELT(ctx,2,local+17); /*elt*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)TIMES(ctx,2,local+16); /***/
	local[16]= w;
	local[17]= local[0];
	local[18]= local[11];
	local[19]= makeint((eusinteger_t)1L);
	ctx->vsp=local+20;
	w=(pointer)ELT(ctx,2,local+18); /*elt*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)TIMES(ctx,2,local+17); /***/
	local[17]= w;
	local[18]= local[0];
	local[19]= local[11];
	local[20]= makeint((eusinteger_t)2L);
	ctx->vsp=local+21;
	w=(pointer)ELT(ctx,2,local+19); /*elt*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)TIMES(ctx,2,local+18); /***/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)XFORMAT(ctx,5,local+14); /*format*/
	local[14]= local[12];
	ctx->vsp=local+15;
	w=(pointer)ADD1(ctx,1,local+14); /*1+*/
	local[12] = w;
	goto WHL1817;
WHX1818:
	local[14]= NIL;
BLK1819:
	w = NIL;
	local[11]= argv[0];
	local[12]= fqv[273];
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,2,local+11); /*format*/
	if (local[2]==NIL) goto IF1820;
	if (local[9]==NIL) goto IF1820;
	local[11]= NIL;
	goto IF1821;
IF1820:
	local[11]= NIL;
IF1821:
	if (local[3]==NIL) goto IF1822;
	if (local[8]==NIL) goto IF1822;
	local[11]= NIL;
	goto IF1823;
IF1822:
	local[11]= NIL;
IF1823:
	local[11]= argv[0];
	local[12]= fqv[274];
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,2,local+11); /*format*/
	local[11]= makeint((eusinteger_t)0L);
	local[12]= local[5];
	ctx->vsp=local+13;
	w=(pointer)LENGTH(ctx,1,local+12); /*length*/
	local[12]= w;
	local[13]= makeint((eusinteger_t)3L);
	ctx->vsp=local+14;
	w=(pointer)QUOTIENT(ctx,2,local+12); /*/*/
	local[12]= w;
WHL1825:
	local[13]= local[11];
	w = local[12];
	if ((eusinteger_t)local[13] >= (eusinteger_t)w) goto WHX1826;
	local[13]= argv[0];
	local[14]= fqv[275];
	local[15]= local[5];
	local[16]= local[11];
	{ eusinteger_t i,j;
		j=intval(makeint((eusinteger_t)3L)); i=intval(local[16]);
		local[16]=(makeint(i * j));}
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	local[16]= local[5];
	local[17]= local[11];
	{ eusinteger_t i,j;
		j=intval(makeint((eusinteger_t)3L)); i=intval(local[17]);
		local[17]=(makeint(i * j));}
	w = makeint((eusinteger_t)1L);
#if sun4 || vax || mips || alpha || Linux
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[17]= (pointer)((eusinteger_t)local[17] + (eusinteger_t)w);
	ctx->vsp=local+18;
	w=(pointer)ELT(ctx,2,local+16); /*elt*/
	local[16]= w;
	local[17]= local[5];
	local[18]= local[11];
	{ eusinteger_t i,j;
		j=intval(makeint((eusinteger_t)3L)); i=intval(local[18]);
		local[18]=(makeint(i * j));}
	w = makeint((eusinteger_t)2L);
#if sun4 || vax || mips || alpha || Linux
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[18]= (pointer)((eusinteger_t)local[18] + (eusinteger_t)w);
	ctx->vsp=local+19;
	w=(pointer)ELT(ctx,2,local+17); /*elt*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)XFORMAT(ctx,5,local+13); /*format*/
	local[13]= local[11];
	ctx->vsp=local+14;
	w=(pointer)ADD1(ctx,1,local+13); /*1+*/
	local[11] = w;
	goto WHL1825;
WHX1826:
	local[13]= NIL;
BLK1827:
	w = NIL;
	local[11]= argv[0];
	local[12]= fqv[276];
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,2,local+11); /*format*/
	local[0]= w;
BLK1799:
	ctx->vsp=local; return(local[0]);}

/*write-wrl-from-glvertices*/
static pointer F987write_wrl_from_glvertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1829:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= *(ovafptr(argv[1],fqv[217]));
	local[2]= argv[0];
	local[3]= fqv[277];
	local[4]= fqv[278];
	ctx->vsp=local+5;
	w=(*ftab[91])(ctx,3,local+2,&ftab[91],fqv[279]); /*open*/
	local[2]= w;
	ctx->vsp=local+3;
	w = makeclosure(codevec,quotevec,UWP1830,env,argv,local);
	local[3]=(pointer)(ctx->protfp); local[4]=w;
	ctx->protfp=(struct protectframe *)(local+3);
	local[5]= local[2];
	local[6]= fqv[280];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,2,local+5); /*format*/
	local[5]= local[2];
	local[6]= fqv[281];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,2,local+5); /*format*/
	local[5]= NIL;
	local[6]= local[1];
WHL1832:
	if (local[6]==NIL) goto WHX1833;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= (pointer)get_sym_func(fqv[282]);
	local[8]= local[2];
	local[9]= local[5];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)APPLY(ctx,4,local+7); /*apply*/
	goto WHL1832;
WHX1833:
	local[7]= NIL;
BLK1834:
	w = NIL;
	local[5]= local[2];
	local[6]= fqv[283];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,2,local+5); /*format*/
	local[5]= local[2];
	local[6]= fqv[284];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,2,local+5); /*format*/
	ctx->vsp=local+5;
	UWP1830(ctx,0,local+5,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK1828:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP1830(ctx,n,argv,env)
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

/* initializer*/
pointer ___irtgl(ctx,n,argv,env)
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
	local[0]= fqv[285];
	ctx->vsp=local+1;
	w=(*ftab[92])(ctx,1,local+0,&ftab[92],fqv[286]); /*require*/
	local[0]= fqv[287];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF1836;
	local[0]= fqv[288];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[289],w);
	goto IF1837;
IF1836:
	local[0]= fqv[290];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF1837:
	local[0]= NIL;
	ctx->vsp=local+1;
	w=(*ftab[93])(ctx,0,local+1,&ftab[93],fqv[291]); /*system::sysmod*/
	local[0] = w;
	local[1]= fqv[90];
	local[2]= fqv[292];
	local[3]= fqv[200];
	local[4]= fqv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[94])(ctx,4,local+2,&ftab[94],fqv[293]); /*make-foreign-code*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SETFUNC(ctx,2,local+1); /*lisp::setfunc*/
	local[1]= fqv[294];
	local[2]= fqv[295];
	local[3]= makeint((eusinteger_t)10752L);
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= fqv[296];
	local[2]= fqv[295];
	local[3]= makeint((eusinteger_t)10753L);
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= fqv[297];
	local[2]= fqv[295];
	local[3]= makeint((eusinteger_t)10754L);
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= fqv[298];
	local[2]= fqv[295];
	local[3]= makeint((eusinteger_t)32823L);
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= fqv[299];
	local[2]= fqv[295];
	local[3]= makeint((eusinteger_t)32824L);
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= fqv[300];
	local[2]= fqv[295];
	local[3]= makeint((eusinteger_t)32823L);
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= fqv[301];
	local[2]= fqv[295];
	local[3]= makeint((eusinteger_t)32824L);
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= fqv[302];
	local[2]= fqv[295];
	local[3]= makeint((eusinteger_t)32825L);
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= fqv[236];
	local[2]= fqv[303];
	local[3]= fqv[200];
	local[4]= fqv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[94])(ctx,4,local+2,&ftab[94],fqv[293]); /*make-foreign-code*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SETFUNC(ctx,2,local+1); /*lisp::setfunc*/
	local[1]= fqv[245];
	local[2]= fqv[304];
	local[3]= fqv[200];
	local[4]= fqv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[94])(ctx,4,local+2,&ftab[94],fqv[293]); /*make-foreign-code*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SETFUNC(ctx,2,local+1); /*lisp::setfunc*/
	local[1]= fqv[237];
	local[2]= fqv[305];
	local[3]= fqv[200];
	local[4]= fqv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[94])(ctx,4,local+2,&ftab[94],fqv[293]); /*make-foreign-code*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SETFUNC(ctx,2,local+1); /*lisp::setfunc*/
	local[1]= fqv[306];
	local[2]= fqv[307];
	local[3]= fqv[200];
	local[4]= fqv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[94])(ctx,4,local+2,&ftab[94],fqv[293]); /*make-foreign-code*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SETFUNC(ctx,2,local+1); /*lisp::setfunc*/
	local[1]= fqv[238];
	local[2]= fqv[308];
	local[3]= fqv[200];
	local[4]= fqv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[94])(ctx,4,local+2,&ftab[94],fqv[293]); /*make-foreign-code*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SETFUNC(ctx,2,local+1); /*lisp::setfunc*/
	local[1]= fqv[239];
	local[2]= fqv[309];
	local[3]= fqv[200];
	local[4]= fqv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[94])(ctx,4,local+2,&ftab[94],fqv[293]); /*make-foreign-code*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SETFUNC(ctx,2,local+1); /*lisp::setfunc*/
	local[1]= fqv[243];
	local[2]= fqv[310];
	local[3]= fqv[200];
	local[4]= fqv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[94])(ctx,4,local+2,&ftab[94],fqv[293]); /*make-foreign-code*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SETFUNC(ctx,2,local+1); /*lisp::setfunc*/
	local[1]= fqv[311];
	local[2]= fqv[312];
	local[3]= fqv[200];
	local[4]= fqv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[94])(ctx,4,local+2,&ftab[94],fqv[293]); /*make-foreign-code*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SETFUNC(ctx,2,local+1); /*lisp::setfunc*/
	local[1]= fqv[244];
	local[2]= fqv[313];
	local[3]= fqv[200];
	local[4]= fqv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[94])(ctx,4,local+2,&ftab[94],fqv[293]); /*make-foreign-code*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SETFUNC(ctx,2,local+1); /*lisp::setfunc*/
	local[1]= fqv[314];
	local[2]= fqv[295];
	local[3]= makeint((eusinteger_t)32884L);
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= fqv[315];
	local[2]= fqv[295];
	local[3]= makeint((eusinteger_t)32885L);
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= fqv[316];
	local[2]= fqv[295];
	local[3]= makeint((eusinteger_t)32888L);
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= fqv[317];
	local[2]= fqv[295];
	local[3]= makeint((eusinteger_t)32889L);
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= fqv[318];
	local[2]= fqv[295];
	local[3]= makeint((eusinteger_t)32886L);
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= fqv[319];
	local[2]= fqv[295];
	local[3]= makeint((eusinteger_t)32887L);
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[320],module,F976set_stereo_gl_attribute,fqv[321]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[322],module,F977reset_gl_attribute,fqv[323]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[324],module,F978delete_displaylist_id,fqv[325]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[326],module,F979transpose_image_rows,fqv[327]);
	local[0]= fqv[20];
	local[1]= loadglobal(fqv[328]);
	local[2]= fqv[329];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[64])(ctx,2,local+0,&ftab[64],fqv[177]); /*assoc*/
	if (w!=NIL) goto IF1838;
	local[0]= fqv[56];
	local[1]= loadglobal(fqv[328]);
	local[2]= fqv[329];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[64])(ctx,2,local+0,&ftab[64],fqv[177]); /*assoc*/
	local[0]= w;
	local[1]= fqv[20];
	ctx->vsp=local+2;
	w=(pointer)RPLACA(ctx,2,local+0); /*rplaca*/
	local[0]= w;
	goto IF1839;
IF1838:
	local[0]= NIL;
IF1839:
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1014glviewsurface_color,fqv[56],fqv[328],fqv[330]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1020glviewsurface_line_width,fqv[145],fqv[328],fqv[331]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1026glviewsurface_point_size,fqv[332],fqv[328],fqv[333]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1032glviewsurface_3d_point,fqv[334],fqv[328],fqv[335]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1044glviewsurface_3d_line,fqv[149],fqv[328],fqv[336]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1056glviewsurface_3d_lines,fqv[146],fqv[328],fqv[337]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1073glviewsurface_makecurrent,fqv[9],fqv[328],fqv[338]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1075glviewsurface_redraw,fqv[339],fqv[328],fqv[340]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1078glviewsurface_flush,fqv[34],fqv[328],fqv[341]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1080glviewsurface_write_to_image_file,fqv[342],fqv[328],fqv[343]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1086glviewsurface_getglimage,fqv[38],fqv[328],fqv[344]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[345],module,F980draw_globjects,fqv[346]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[347],module,F981draw_glbody,fqv[348]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[349],module,F982find_color,fqv[350]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[351],module,F983transparent,fqv[352]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1244polygon_draw_on,fqv[67],fqv[353],fqv[354]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1254line_draw_on,fqv[67],fqv[355],fqv[356]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1264faceset_set_color,fqv[254],fqv[66],fqv[357]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1271faceset_draw_on,fqv[67],fqv[66],fqv[358]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1286faceset_paste_texture_to_face,fqv[359],fqv[66],fqv[360]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1307coordinates_vertices,fqv[87],fqv[361],fqv[362]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1309coordinates_draw_on,fqv[67],fqv[361],fqv[363]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1330float_vector_vertices,fqv[87],fqv[140],fqv[364]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1332float_vector_draw_on,fqv[67],fqv[140],fqv[365]);
	local[0]= fqv[205];
	local[1]= fqv[366];
	local[2]= fqv[205];
	local[3]= fqv[367];
	local[4]= loadglobal(fqv[368]);
	local[5]= fqv[369];
	local[6]= fqv[370];
	local[7]= fqv[371];
	local[8]= NIL;
	local[9]= fqv[1];
	local[10]= NIL;
	local[11]= fqv[169];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[372];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[95])(ctx,13,local+2,&ftab[95],fqv[373]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1347glvertices_init,fqv[45],fqv[205],fqv[374]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1351glvertices_filename,fqv[260],fqv[205],fqv[375]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1357glvertices_set_color,fqv[254],fqv[205],fqv[376]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1363glvertices_get_meshinfo,fqv[179],fqv[205],fqv[377]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1370glvertices_set_meshinfo,fqv[181],fqv[205],fqv[378]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1381glvertices_get_material,fqv[379],fqv[205],fqv[380]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1385glvertices_set_material,fqv[381],fqv[205],fqv[382]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1389glvertices_actual_vertices,fqv[184],fqv[205],fqv[383]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1402glvertices_calc_bounding_box,fqv[186],fqv[205],fqv[384]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1404glvertices_vertices,fqv[87],fqv[205],fqv[385]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1408glvertices_reset_offset_from_parent,fqv[386],fqv[205],fqv[387]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1410glvertices_expand_vertices,fqv[388],fqv[205],fqv[389]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1417glvertices_expand_vertices_info,fqv[191],fqv[205],fqv[390]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1425glvertices_use_flat_shader,fqv[391],fqv[205],fqv[392]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1432glvertices_use_smooth_shader,fqv[393],fqv[205],fqv[394]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1441glvertices_calc_normals,fqv[395],fqv[205],fqv[396]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1483glvertices_mirror_axis,fqv[397],fqv[205],fqv[398]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1515glvertices_convert_to_faces,fqv[211],fqv[205],fqv[399]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1582glvertices_faces,fqv[86],fqv[205],fqv[400]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1584glvertices_convert_to_faceset,fqv[401],fqv[205],fqv[402]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1588glvertices_set_offset,fqv[189],fqv[205],fqv[403]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1601glvertices_convert_to_world,fqv[404],fqv[205],fqv[405]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1604glvertices_glvertices,fqv[406],fqv[205],fqv[407]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1622glvertices_append_glvertices,fqv[408],fqv[205],fqv[409]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1632glvertices_draw_on,fqv[67],fqv[205],fqv[410]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1635glvertices_draw,fqv[64],fqv[205],fqv[411]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1723glvertices_collision_check_objects,fqv[412],fqv[205],fqv[413]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1726glvertices_box,fqv[414],fqv[205],fqv[415]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1730glvertices_make_pqpmodel,fqv[416],fqv[205],fqv[417]);
	local[0]= fqv[418];
	local[1]= fqv[366];
	local[2]= fqv[418];
	local[3]= fqv[367];
	local[4]= loadglobal(fqv[419]);
	local[5]= fqv[369];
	local[6]= fqv[420];
	local[7]= fqv[371];
	local[8]= NIL;
	local[9]= fqv[1];
	local[10]= NIL;
	local[11]= fqv[169];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[372];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[95])(ctx,13,local+2,&ftab[95],fqv[373]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1764glbody_glvertices,fqv[406],fqv[418],fqv[421]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1767glbody_draw,fqv[64],fqv[418],fqv[422]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1771glbody_set_color,fqv[254],fqv[418],fqv[423]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[424],module,F984make_glvertices_from_faceset,fqv[425]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[426],module,F985make_glvertices_from_faces,fqv[427]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[282],module,F986_dump_wrl_shape,fqv[428]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[429],module,F987write_wrl_from_glvertices,fqv[430]);
	local[0]= fqv[431];
	local[1]= fqv[432];
	ctx->vsp=local+2;
	w=(*ftab[96])(ctx,2,local+0,&ftab[96],fqv[433]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<97; i++) ftab[i]=fcallx;
}
