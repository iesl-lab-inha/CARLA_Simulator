/* ./viewport.c :  entry=viewport */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "viewport.h"
#pragma init (register_viewport)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___viewport();
extern pointer build_quote_vector();
static int register_viewport()
  { add_module_initializer("___viewport", ___viewport);}

static pointer F3719draw();
static pointer F3720draw_tree();
static pointer F3721erase();
static pointer F3722draw_axis();
static pointer F3723draw_arrow();
static pointer F3724hid();
static pointer F3725hidd();
static pointer F3726cls();
static pointer F3727draw_hid();
static pointer F3728draw_step();
static pointer F3729find_viewer();
static pointer F3730view();

/*:xcenter*/
static pointer M3732viewport_xcenter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3735;}
	local[0]= NIL;
ENT3735:
ENT3734:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3736;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= makeint(0);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,3,local+1); /*aset*/
	local[1]= w;
	goto IF3737;
IF3736:
	local[1]= NIL;
IF3737:
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[0]= w;
BLK3733:
	ctx->vsp=local; return(local[0]);}

/*:ycenter*/
static pointer M3738viewport_ycenter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3741;}
	local[0]= NIL;
ENT3741:
ENT3740:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3742;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= makeint(1);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,3,local+1); /*aset*/
	local[1]= w;
	goto IF3743;
IF3742:
	local[1]= NIL;
IF3743:
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[0]= w;
BLK3739:
	ctx->vsp=local; return(local[0]);}

/*:center*/
static pointer M3744viewport_center(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3748;}
	local[0]= NIL;
ENT3748:
	if (n>=4) { local[1]=(argv[3]); goto ENT3747;}
	local[1]= local[0];
ENT3747:
ENT3746:
	if (n>4) maerror();
	w = local[0];
	if (!isnum(w)) goto CON3750;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= makeint(0);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= makeint(1);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= w;
	goto CON3749;
CON3750:
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,1,local+2,&ftab[0],fqv[0]); /*float-vector-p*/
	if (w==NIL) goto CON3751;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= makeint(0);
	local[4]= local[0];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= makeint(1);
	local[4]= local[0];
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= w;
	goto CON3749;
CON3751:
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,2,local+2); /*float-vector*/
	local[2]= w;
	goto CON3749;
CON3752:
	local[2]= NIL;
CON3749:
	w = local[2];
	local[0]= w;
BLK3745:
	ctx->vsp=local; return(local[0]);}

/*:width*/
static pointer M3753viewport_width(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3756;}
	local[0]= NIL;
ENT3756:
ENT3755:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3757;
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= makeint(0);
	local[3]= makeint(0);
	local[4]= local[0];
	local[5]= makeflt(2.00000000e+00);
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,4,local+1); /*aset*/
	local[1]= w;
	goto IF3758;
IF3757:
	local[1]= NIL;
IF3758:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= makeint(0);
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,3,local+1); /*aref*/
	local[1]= w;
	local[2]= makeflt(2.00000000e+00);
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[0]= w;
BLK3754:
	ctx->vsp=local; return(local[0]);}

/*:height*/
static pointer M3759viewport_height(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3762;}
	local[0]= NIL;
ENT3762:
ENT3761:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3763;
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= makeint(1);
	local[3]= makeint(1);
	local[4]= local[0];
	local[5]= makeflt(2.00000000e+00);
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,4,local+1); /*aset*/
	local[1]= w;
	goto IF3764;
IF3763:
	local[1]= NIL;
IF3764:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= makeint(1);
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,3,local+1); /*aref*/
	local[1]= w;
	local[2]= makeflt(2.00000000e+00);
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[0]= w;
BLK3760:
	ctx->vsp=local; return(local[0]);}

/*:size*/
static pointer M3765viewport_size(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3769;}
	local[0]= NIL;
ENT3769:
	if (n>=4) { local[1]=(argv[3]); goto ENT3768;}
	local[1]= local[0];
ENT3768:
ENT3767:
	if (n>4) maerror();
	w = local[0];
	if (!isnum(w)) goto CON3771;
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= makeint(0);
	local[4]= makeint(0);
	local[5]= local[0];
	local[6]= makeflt(2.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,4,local+2); /*aset*/
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= makeint(1);
	local[4]= makeint(1);
	local[5]= local[1];
	local[6]= makeflt(2.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,4,local+2); /*aset*/
	local[2]= w;
	goto CON3770;
CON3771:
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,1,local+2,&ftab[0],fqv[0]); /*float-vector-p*/
	if (w==NIL) goto CON3772;
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= makeint(0);
	local[4]= makeint(0);
	local[5]= local[0];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= makeflt(2.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,4,local+2); /*aset*/
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= makeint(1);
	local[4]= makeint(1);
	local[5]= local[0];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= makeflt(2.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,4,local+2); /*aset*/
	local[2]= w;
	goto CON3770;
CON3772:
	local[2]= makeflt(2.00000000e+00);
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= makeint(0);
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,3,local+3); /*aref*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= makeflt(2.00000000e+00);
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= makeint(1);
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,3,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,2,local+2); /*float-vector*/
	local[2]= w;
	goto CON3770;
CON3773:
	local[2]= NIL;
CON3770:
	w = local[2];
	local[0]= w;
BLK3766:
	ctx->vsp=local; return(local[0]);}

/*:screen-point-to-ndc*/
static pointer M3774viewport_screen_point_to_ndc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)COPYSEQ(ctx,1,local+0); /*copy-seq*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,1,local+1,&ftab[1],fqv[1]); /*inverse-matrix*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)VMINUS(ctx,3,local+2); /*v-*/
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)TRANSFORM(ctx,3,local+1); /*transform*/
	local[0]= w;
BLK3775:
	ctx->vsp=local; return(local[0]);}

/*:ndc-width-to-screen*/
static pointer M3776viewport_ndc_width_to_screen(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= makeint(0);
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,3,local+0); /*aref*/
	local[0]= w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)ABS(ctx,1,local+0); /*abs*/
	local[0]= w;
BLK3777:
	ctx->vsp=local; return(local[0]);}

/*:ndc-height-to-screen*/
static pointer M3778viewport_ndc_height_to_screen(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= makeint(1);
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,3,local+0); /*aref*/
	local[0]= w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)ABS(ctx,1,local+0); /*abs*/
	local[0]= w;
BLK3779:
	ctx->vsp=local; return(local[0]);}

/*:ndc-point-to-screen*/
static pointer M3780viewport_ndc_point_to_screen(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	if (makeint(2)!=local[0]) goto IF3782;
	local[0]= argv[2];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	local[2]= makeflt(0.00000000e+00);
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
	goto IF3783;
IF3782:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)COPYSEQ(ctx,1,local+0); /*copy-seq*/
	local[0]= w;
IF3783:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= local[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)TRANSFORM(ctx,3,local+1); /*transform*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)VPLUS(ctx,3,local+1); /*v+*/
	local[0]= w;
BLK3781:
	ctx->vsp=local; return(local[0]);}

/*:ndc-line-to-screen*/
static pointer M3784viewport_ndc_line_to_screen(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT3787;}
	local[0]= T;
ENT3787:
ENT3786:
	if (n>5) maerror();
	if (local[0]==NIL) goto IF3788;
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)HOMO_VPCLIP(ctx,2,local+1); /*homo-viewport-clip*/
	argv[2] = w;
	if (argv[2]!=NIL) goto IF3790;
	w = NIL;
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK3785;
	goto IF3791;
IF3790:
	local[1]= NIL;
IF3791:
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[3] = (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.car;
	local[1]= argv[2];
	goto IF3789;
IF3788:
	local[1]= NIL;
IF3789:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	w = makeint(3);
	if ((eusinteger_t)local[1] <= (eusinteger_t)w) goto IF3792;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)HOMO2NORMAL(ctx,1,local+1); /*homo2normal*/
	argv[2] = w;
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)HOMO2NORMAL(ctx,1,local+1); /*homo2normal*/
	argv[3] = w;
	local[1]= argv[3];
	goto IF3793;
IF3792:
	local[1]= NIL;
IF3793:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	w = makeint(3);
	if ((eusinteger_t)local[1] >= (eusinteger_t)w) goto IF3794;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)HOMOGENIZE(ctx,1,local+1); /*homogenize*/
	argv[2] = w;
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)HOMOGENIZE(ctx,1,local+1); /*homogenize*/
	argv[3] = w;
	local[1]= argv[3];
	goto IF3795;
IF3794:
	local[1]= NIL;
IF3795:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	local[3]= loadglobal(fqv[2]);
	ctx->vsp=local+4;
	w=(pointer)TRANSFORM(ctx,3,local+1); /*transform*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= loadglobal(fqv[2]);
	ctx->vsp=local+4;
	w=(pointer)VPLUS(ctx,3,local+1); /*v+*/
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[3];
	local[3]= loadglobal(fqv[3]);
	ctx->vsp=local+4;
	w=(pointer)TRANSFORM(ctx,3,local+1); /*transform*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= loadglobal(fqv[3]);
	ctx->vsp=local+4;
	w=(pointer)VPLUS(ctx,3,local+1); /*v+*/
	local[1]= loadglobal(fqv[2]);
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	local[2]= loadglobal(fqv[2]);
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,2,local+1); /*float-vector*/
	local[1]= w;
	local[2]= loadglobal(fqv[3]);
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	local[3]= loadglobal(fqv[3]);
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,2,local+2); /*float-vector*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[0]= w;
BLK3785:
	ctx->vsp=local; return(local[0]);}

/*:resize*/
static pointer M3796viewport_resize(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3798:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[4], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3799;
	local[1] = NIL;
KEY3799:
	if (n & (1<<1)) goto KEY3800;
	local[2] = NIL;
KEY3800:
	if (n & (1<<2)) goto KEY3801;
	local[3] = NIL;
KEY3801:
	if (n & (1<<3)) goto KEY3802;
	local[4] = NIL;
KEY3802:
	if (local[3]==NIL) goto IF3803;
	local[5]= argv[0];
	local[6]= fqv[5];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF3804;
IF3803:
	local[5]= NIL;
IF3804:
	if (local[4]==NIL) goto IF3805;
	local[5]= argv[0];
	local[6]= fqv[6];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF3806;
IF3805:
	local[5]= NIL;
IF3806:
	if (local[1]==NIL) goto IF3807;
	local[5]= argv[0];
	local[6]= fqv[7];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF3808;
IF3807:
	local[5]= NIL;
IF3808:
	if (local[2]==NIL) goto IF3809;
	local[5]= argv[0];
	local[6]= fqv[8];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF3810;
IF3809:
	local[5]= NIL;
IF3810:
	local[5]= argv[0];
	local[6]= fqv[9];
	local[7]= argv[0]->c.obj.iv[1];
	local[8]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	w = argv[0];
	local[0]= w;
BLK3797:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3811viewport_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3813:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[10], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3814;
	local[1] = makeint(3);
KEY3814:
	if (n & (1<<1)) goto KEY3815;
	local[2] = makeint(100);
KEY3815:
	if (n & (1<<2)) goto KEY3816;
	local[3] = makeint(100);
KEY3816:
	if (n & (1<<3)) goto KEY3817;
	local[4] = makeint(200);
KEY3817:
	if (n & (1<<4)) goto KEY3818;
	local[5] = makeint(200);
KEY3818:
	local[6]= argv[0];
	local[7]= *(ovafptr(argv[1],fqv[11]));
	local[8]= fqv[12];
	local[9]= fqv[13];
	local[10]= makeint(3);
	ctx->vsp=local+11;
	w=(pointer)SENDMESSAGE(ctx,5,local+6); /*send-message*/
	local[6]= argv[0];
	local[7]= fqv[5];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= argv[0];
	local[7]= fqv[6];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= argv[0];
	local[7]= fqv[7];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= argv[0];
	local[7]= fqv[8];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= argv[0];
	local[7]= fqv[9];
	local[8]= argv[0]->c.obj.iv[1];
	local[9]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	w = argv[0];
	local[0]= w;
BLK3812:
	ctx->vsp=local; return(local[0]);}

/*:viewing*/
static pointer M3819viewer_viewing(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3821:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	if (local[0]==NIL) goto IF3822;
	local[1]= (pointer)get_sym_func(fqv[14]);
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[1]= w;
	goto IF3823;
IF3822:
	local[1]= argv[0]->c.obj.iv[1];
IF3823:
	w = local[1];
	local[0]= w;
BLK3820:
	ctx->vsp=local; return(local[0]);}

/*:viewsurface*/
static pointer M3824viewer_viewsurface(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3826:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	if (local[0]==NIL) goto IF3827;
	local[1]= (pointer)get_sym_func(fqv[14]);
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[1]= w;
	goto IF3828;
IF3827:
	local[1]= argv[0]->c.obj.iv[3];
IF3828:
	w = local[1];
	local[0]= w;
BLK3825:
	ctx->vsp=local; return(local[0]);}

/*:viewport*/
static pointer M3829viewer_viewport(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3831:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	if (local[0]==NIL) goto IF3832;
	local[1]= (pointer)get_sym_func(fqv[14]);
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[1]= w;
	goto IF3833;
IF3832:
	local[1]= argv[0]->c.obj.iv[2];
IF3833:
	w = local[1];
	local[0]= w;
BLK3830:
	ctx->vsp=local; return(local[0]);}

/*:flush*/
static pointer M3834viewer_flush(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[15];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK3835:
	ctx->vsp=local; return(local[0]);}

/*:point-to-screen*/
static pointer M3836viewer_point_to_screen(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= fqv[16];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= fqv[17];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)HOMO2NORMAL(ctx,1,local+2); /*homo2normal*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3837:
	ctx->vsp=local; return(local[0]);}

/*:draw-point-ndc*/
static pointer M3838viewer_draw_point_ndc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3841;}
	local[0]= NIL;
ENT3841:
ENT3840:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF3842;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[18];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF3843;
IF3842:
	local[1]= NIL;
IF3843:
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[16];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[2] = w;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[19];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK3839:
	ctx->vsp=local; return(local[0]);}

/*:draw-line-ndc*/
static pointer M3844viewer_draw_line_ndc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT3848;}
	local[0]= T;
ENT3848:
	if (n>=6) { local[1]=(argv[5]); goto ENT3847;}
	local[1]= NIL;
ENT3847:
ENT3846:
	if (n>6) maerror();
	if (local[1]==NIL) goto IF3849;
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= fqv[18];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF3850;
IF3849:
	local[2]= NIL;
IF3850:
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= fqv[20];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	argv[2] = w;
	if (argv[2]==NIL) goto IF3851;
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= fqv[21];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	goto IF3852;
IF3851:
	local[2]= NIL;
IF3852:
	w = NIL;
	local[0]= w;
BLK3845:
	ctx->vsp=local; return(local[0]);}

/*:draw-string-ndc*/
static pointer M3853viewer_draw_string_ndc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	w = argv[3];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[22],w);
	if (n>=5) { local[3]=(argv[4]); goto ENT3856;}
	local[3]= NIL;
ENT3856:
ENT3855:
	if (n>5) maerror();
	if (local[3]==NIL) goto IF3857;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[18];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF3858;
IF3857:
	local[4]= NIL;
IF3858:
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= fqv[16];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	argv[2] = w;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[23];
	local[6]= argv[2];
	local[7]= loadglobal(fqv[22]);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	unbindx(ctx,1);
	w = local[4];
	local[0]= w;
BLK3854:
	ctx->vsp=local; return(local[0]);}

/*:draw-image-string-ndc*/
static pointer M3859viewer_draw_image_string_ndc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	w = argv[3];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[22],w);
	if (n>=5) { local[3]=(argv[4]); goto ENT3862;}
	local[3]= NIL;
ENT3862:
ENT3861:
	if (n>5) maerror();
	if (local[3]==NIL) goto IF3863;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[18];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF3864;
IF3863:
	local[4]= NIL;
IF3864:
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= fqv[16];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	argv[2] = w;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[24];
	local[6]= argv[2];
	local[7]= loadglobal(fqv[22]);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	unbindx(ctx,1);
	w = local[4];
	local[0]= w;
BLK3860:
	ctx->vsp=local; return(local[0]);}

/*:draw-rectangle-ndc*/
static pointer M3865viewer_draw_rectangle_ndc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	if (n>=6) { local[0]=(argv[5]); goto ENT3868;}
	local[0]= NIL;
ENT3868:
ENT3867:
	if (n>6) maerror();
	if (local[0]==NIL) goto IF3869;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[18];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF3870;
IF3869:
	local[1]= NIL;
IF3870:
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[16];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[2] = w;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[25];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[3] = w;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[26];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[4] = w;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[27];
	local[3]= argv[2];
	local[4]= argv[3];
	local[5]= argv[4];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[0]= w;
BLK3866:
	ctx->vsp=local; return(local[0]);}

/*:draw-fill-rectangle-ndc*/
static pointer M3871viewer_draw_fill_rectangle_ndc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	if (n>=6) { local[0]=(argv[5]); goto ENT3874;}
	local[0]= NIL;
ENT3874:
ENT3873:
	if (n>6) maerror();
	if (local[0]==NIL) goto IF3875;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[18];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF3876;
IF3875:
	local[1]= NIL;
IF3876:
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[16];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[2] = w;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[25];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[3] = w;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[26];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[4] = w;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[28];
	local[3]= argv[2];
	local[4]= argv[3];
	local[5]= argv[4];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[0]= w;
BLK3872:
	ctx->vsp=local; return(local[0]);}

/*:draw-arc-ndc*/
static pointer M3877viewer_draw_arc_ndc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	if (n>=6) { local[0]=(argv[5]); goto ENT3882;}
	local[0]= makeint(0);
ENT3882:
	if (n>=7) { local[1]=(argv[6]); goto ENT3881;}
	local[1]= makeflt(6.28318531e+00);
ENT3881:
	if (n>=8) { local[2]=(argv[7]); goto ENT3880;}
	local[2]= NIL;
ENT3880:
ENT3879:
	if (n>8) maerror();
	if (local[2]==NIL) goto IF3883;
	local[3]= argv[0]->c.obj.iv[3];
	local[4]= fqv[18];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF3884;
IF3883:
	local[3]= NIL;
IF3884:
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= fqv[16];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	argv[2] = w;
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= fqv[25];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	argv[3] = w;
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= fqv[26];
	local[5]= argv[4];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	argv[4] = w;
	local[3]= argv[0]->c.obj.iv[3];
	local[4]= fqv[29];
	local[5]= argv[2];
	local[6]= argv[3];
	local[7]= argv[4];
	local[8]= local[0];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,7,local+3); /*send*/
	local[0]= w;
BLK3878:
	ctx->vsp=local; return(local[0]);}

/*:draw-fill-arc-ndc*/
static pointer M3885viewer_draw_fill_arc_ndc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<7) maerror();
	if (n>=8) { local[0]=(argv[7]); goto ENT3888;}
	local[0]= NIL;
ENT3888:
ENT3887:
	if (n>8) maerror();
	if (local[0]==NIL) goto IF3889;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[18];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF3890;
IF3889:
	local[1]= NIL;
IF3890:
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[16];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[2] = w;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[25];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[3] = w;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[26];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[4] = w;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[30];
	local[3]= argv[2];
	local[4]= argv[3];
	local[5]= argv[4];
	local[6]= argv[5];
	local[7]= argv[6];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,7,local+1); /*send*/
	local[0]= w;
BLK3886:
	ctx->vsp=local; return(local[0]);}

/*:draw-polyline-ndc*/
static pointer M3891viewer_draw_polyline_ndc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3894;}
	local[0]= NIL;
ENT3894:
ENT3893:
	if (n>4) maerror();
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[1];
	local[1]= w;
	local[2]= NIL;
WHL3896:
	if (argv[2]==NIL) goto WHX3897;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[3];
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[31];
	local[5]= local[1];
	local[6]= local[2];
	local[7]= T;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	local[1] = local[2];
	goto WHL3896;
WHX3897:
	local[3]= NIL;
BLK3898:
	w = local[3];
	local[0]= w;
BLK3892:
	ctx->vsp=local; return(local[0]);}

/*:draw-box-ndc*/
static pointer M3900viewer_draw_box_ndc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT3903;}
	local[0]= NIL;
ENT3903:
ENT3902:
	if (n>5) maerror();
	local[1]= argv[2];
	{ register eusinteger_t i=intval(makeint(0));
	  w=makeflt(local[1]->c.fvec.fv[i]);}
	local[1]= w;
	local[2]= argv[2];
	{ register eusinteger_t i=intval(makeint(1));
	  w=makeflt(local[2]->c.fvec.fv[i]);}
	local[2]= w;
	local[3]= argv[3];
	{ register eusinteger_t i=intval(makeint(0));
	  w=makeflt(local[3]->c.fvec.fv[i]);}
	local[3]= w;
	local[4]= argv[3];
	{ register eusinteger_t i=intval(makeint(1));
	  w=makeflt(local[4]->c.fvec.fv[i]);}
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[32];
	local[7]= local[1];
	local[8]= local[2];
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,3,local+7); /*float-vector*/
	local[7]= w;
	local[8]= local[3];
	local[9]= local[2];
	local[10]= makeint(0);
	ctx->vsp=local+11;
	w=(pointer)MKFLTVEC(ctx,3,local+8); /*float-vector*/
	local[8]= w;
	local[9]= local[3];
	local[10]= local[4];
	local[11]= makeint(0);
	ctx->vsp=local+12;
	w=(pointer)MKFLTVEC(ctx,3,local+9); /*float-vector*/
	local[9]= w;
	local[10]= local[1];
	local[11]= local[4];
	local[12]= makeint(0);
	ctx->vsp=local+13;
	w=(pointer)MKFLTVEC(ctx,3,local+10); /*float-vector*/
	local[10]= w;
	local[11]= local[1];
	local[12]= local[2];
	local[13]= makeint(0);
	ctx->vsp=local+14;
	w=(pointer)MKFLTVEC(ctx,3,local+11); /*float-vector*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,5,local+7); /*list*/
	local[7]= w;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[0]= w;
BLK3901:
	ctx->vsp=local; return(local[0]);}

/*:draw-star-ndc*/
static pointer M3904viewer_draw_star_ndc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3908;}
	local[0]= makeflt(2.00000000e-02);
ENT3908:
	if (n>=5) { local[1]=(argv[4]); goto ENT3907;}
	local[1]= NIL;
ENT3907:
ENT3906:
	if (n>5) maerror();
	local[2]= argv[0];
	local[3]= fqv[31];
	local[4]= argv[2];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	local[5]= argv[2];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	local[5]= argv[2];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= argv[2];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[5]= w;
	local[6]= T;
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[31];
	local[4]= argv[2];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	local[5]= argv[2];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	local[5]= argv[2];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= argv[2];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[5]= w;
	local[6]= T;
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[0]= w;
BLK3905:
	ctx->vsp=local; return(local[0]);}

/*:draw-line*/
static pointer M3909viewer_draw_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT3913;}
	local[0]= T;
ENT3913:
	if (n>=6) { local[1]=(argv[5]); goto ENT3912;}
	local[1]= NIL;
ENT3912:
ENT3911:
	if (n>6) maerror();
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= fqv[17];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	argv[2] = w;
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= fqv[17];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	argv[3] = w;
	local[2]= argv[0];
	local[3]= fqv[31];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)RECLAIM(ctx,1,local+2); /*system:reclaim*/
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)RECLAIM(ctx,1,local+2); /*system:reclaim*/
	local[0]= w;
BLK3910:
	ctx->vsp=local; return(local[0]);}

/*:draw-box*/
static pointer M3914viewer_draw_box(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3918;}
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[5];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeflt(3.00000000e+02);
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
ENT3918:
	if (n>=5) { local[1]=(argv[4]); goto ENT3917;}
	local[1]= NIL;
ENT3917:
ENT3916:
	if (n>5) maerror();
	local[2]= local[0];
	local[3]= local[0];
	local[4]= makeflt(0.00000000e+00);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[0] = w;
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= fqv[17];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)HOMO2NORMAL(ctx,1,local+2); /*homo2normal*/
	argv[2] = w;
	local[2]= argv[0];
	local[3]= fqv[33];
	local[4]= argv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)VMINUS(ctx,2,local+4); /*v-*/
	local[4]= w;
	local[5]= argv[2];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)VPLUS(ctx,2,local+5); /*v+*/
	local[5]= w;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	local[0]= w;
BLK3915:
	ctx->vsp=local; return(local[0]);}

/*:draw-polyline*/
static pointer M3919viewer_draw_polyline(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3922;}
	local[0]= NIL;
ENT3922:
ENT3921:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[32];
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO3923,env,argv,local);
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK3920:
	ctx->vsp=local; return(local[0]);}

/*:draw-arc*/
static pointer M3924viewer_draw_arc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	if (n>=6) { local[0]=(argv[5]); goto ENT3929;}
	local[0]= makeint(0);
ENT3929:
	if (n>=7) { local[1]=(argv[6]); goto ENT3928;}
	local[1]= makeflt(6.28318531e+00);
ENT3928:
	if (n>=8) { local[2]=(argv[7]); goto ENT3927;}
	local[2]= NIL;
ENT3927:
ENT3926:
	if (n>8) maerror();
	local[3]= NIL;
	local[4]= NIL;
	if (local[2]==NIL) goto IF3930;
	local[5]= argv[0]->c.obj.iv[3];
	local[6]= fqv[18];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF3931;
IF3930:
	local[5]= NIL;
IF3931:
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= fqv[17];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	argv[2] = w;
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= fqv[34];
	local[7]= argv[3];
	local[8]= argv[4];
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,2,local+7); /*float-vector*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[4] = w;
	local[5]= argv[0];
	local[6]= fqv[35];
	local[7]= argv[2];
	local[8]= local[4];
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	local[9]= local[4];
	local[10]= makeint(1);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,2,local+9); /*aref*/
	local[9]= w;
	local[10]= local[0];
	local[11]= local[1];
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,8,local+5); /*send*/
	local[0]= w;
BLK3925:
	ctx->vsp=local; return(local[0]);}

/*:draw-fill-arc*/
static pointer M3932viewer_draw_fill_arc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	if (n>=6) { local[0]=(argv[5]); goto ENT3937;}
	local[0]= makeint(0);
ENT3937:
	if (n>=7) { local[1]=(argv[6]); goto ENT3936;}
	local[1]= makeflt(6.28318531e+00);
ENT3936:
	if (n>=8) { local[2]=(argv[7]); goto ENT3935;}
	local[2]= NIL;
ENT3935:
ENT3934:
	if (n>8) maerror();
	local[3]= NIL;
	local[4]= NIL;
	if (local[2]==NIL) goto IF3938;
	local[5]= argv[0]->c.obj.iv[3];
	local[6]= fqv[18];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF3939;
IF3938:
	local[5]= NIL;
IF3939:
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= fqv[17];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	argv[2] = w;
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= fqv[34];
	local[7]= argv[3];
	local[8]= argv[4];
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,2,local+7); /*float-vector*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[4] = w;
	local[5]= argv[0];
	local[6]= fqv[36];
	local[7]= argv[2];
	local[8]= local[4];
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	local[9]= local[4];
	local[10]= makeint(1);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,2,local+9); /*aref*/
	local[9]= w;
	local[10]= local[0];
	local[11]= local[1];
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,8,local+5); /*send*/
	local[0]= w;
BLK3933:
	ctx->vsp=local; return(local[0]);}

/*:draw-arrow*/
static pointer M3940viewer_draw_arrow(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT3944;}
	local[0]= T;
ENT3944:
	if (n>=6) { local[1]=(argv[5]); goto ENT3943;}
	local[1]= NIL;
ENT3943:
ENT3942:
	ctx->vsp=local+2;
	n=parsekeyparams(fqv[37], &argv[6], n-6, local+2, 0);
	if (n & (1<<0)) goto KEY3945;
	local[2] = fqv[38];
KEY3945:
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= argv[0]->c.obj.iv[1];
	local[8]= fqv[17];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	argv[2] = w;
	local[7]= argv[0]->c.obj.iv[1];
	local[8]= fqv[17];
	local[9]= argv[3];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	argv[3] = w;
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)HOMO2NORMAL(ctx,1,local+7); /*homo2normal*/
	argv[2] = w;
	local[7]= argv[3];
	ctx->vsp=local+8;
	w=(pointer)HOMO2NORMAL(ctx,1,local+7); /*homo2normal*/
	argv[3] = w;
	local[7]= argv[2];
	local[8]= argv[3];
	ctx->vsp=local+9;
	w=(pointer)VMINUS(ctx,2,local+7); /*v-*/
	local[3] = w;
	local[7]= makeflt(3.00000000e-01);
	local[8]= local[3];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,3,local+7); /*scale*/
	local[7]= local[2];
	local[8]= makeint(1);
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	local[8]= local[3];
	local[9]= makeint(1);
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,1,local+8); /*-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	local[8]= local[2];
	local[9]= makeint(1);
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	local[9]= local[3];
	local[10]= makeint(0);
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,3,local+7); /*float-vector*/
	local[4] = w;
	local[7]= local[3];
	local[8]= makeint(2);
	local[9]= makeflt(0.00000000e+00);
	ctx->vsp=local+10;
	w=(pointer)SETELT(ctx,3,local+7); /*setelt*/
	local[7]= local[2];
	local[8]= makeint(0);
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	local[8]= local[3];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,3,local+7); /*scale*/
	local[7]= argv[3];
	local[8]= makeflt(5.00000000e-01);
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,2,local+8); /*scale*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)VPLUS(ctx,2,local+7); /*v+*/
	local[7]= w;
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)VPLUS(ctx,2,local+7); /*v+*/
	local[5] = w;
	local[7]= argv[3];
	local[8]= makeflt(-5.00000000e-01);
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,2,local+8); /*scale*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)VPLUS(ctx,2,local+7); /*v+*/
	local[7]= w;
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)VPLUS(ctx,2,local+7); /*v+*/
	local[6] = w;
	local[7]= argv[0];
	local[8]= fqv[31];
	local[9]= argv[2];
	local[10]= argv[3];
	local[11]= local[0];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,6,local+7); /*send*/
	local[7]= argv[0];
	local[8]= fqv[31];
	local[9]= local[5];
	local[10]= argv[3];
	local[11]= local[0];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,6,local+7); /*send*/
	local[7]= argv[0];
	local[8]= fqv[31];
	local[9]= local[6];
	local[10]= argv[3];
	local[11]= local[0];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,6,local+7); /*send*/
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)RECLAIM(ctx,1,local+7); /*system:reclaim*/
	local[7]= argv[3];
	ctx->vsp=local+8;
	w=(pointer)RECLAIM(ctx,1,local+7); /*system:reclaim*/
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)RECLAIM(ctx,1,local+7); /*system:reclaim*/
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)RECLAIM(ctx,1,local+7); /*system:reclaim*/
	local[7]= local[6];
	ctx->vsp=local+8;
	w=(pointer)RECLAIM(ctx,1,local+7); /*system:reclaim*/
	local[0]= w;
BLK3941:
	ctx->vsp=local; return(local[0]);}

/*:pane*/
static pointer M3946viewer_pane(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[33];
	local[2]= fqv[39];
	local[3]= fqv[40];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK3947:
	ctx->vsp=local; return(local[0]);}

/*:draw-star*/
static pointer M3948viewer_draw_star(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3952;}
	local[0]= NIL;
ENT3952:
	if (n>=5) { local[1]=(argv[4]); goto ENT3951;}
	local[1]= NIL;
ENT3951:
ENT3950:
	if (n>5) maerror();
	if (local[0]!=NIL) goto IF3953;
	local[0] = makeflt(2.00000000e-02);
	local[2]= local[0];
	goto IF3954;
IF3953:
	local[2]= NIL;
IF3954:
	local[2]= argv[0];
	local[3]= fqv[41];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= fqv[17];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)HOMO2NORMAL(ctx,1,local+4); /*homo2normal*/
	local[4]= w;
	local[5]= local[0];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	local[0]= w;
BLK3949:
	ctx->vsp=local; return(local[0]);}

/*:draw-2dlnseg*/
static pointer M3955viewer_draw_2dlnseg(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[21];
	local[2]= argv[2];
	local[3]= fqv[42];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[2];
	local[4]= fqv[43];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK3956:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3923(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0]->c.obj.iv[1];
	local[1]= fqv[17];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:draw-edge-image*/
static pointer M3957viewer_draw_edge_image(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3961;}
	local[0]= NIL;
ENT3961:
	if (n>=5) { local[1]=(argv[4]); goto ENT3960;}
	local[1]= argv[2];
	local[2]= fqv[18];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
ENT3960:
ENT3959:
	if (n>5) maerror();
	local[2]= NIL;
	local[3]= argv[2];
	local[4]= fqv[44];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
WHL3963:
	if (local[3]==NIL) goto WHX3964;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= argv[0];
	local[5]= fqv[31];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= NIL;
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,6,local+4); /*send*/
	goto WHL3963;
WHX3964:
	local[4]= NIL;
BLK3965:
	w = NIL;
	if (local[0]==NIL) goto IF3967;
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= fqv[45];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= NIL;
	local[3]= argv[2];
	local[4]= fqv[46];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
WHL3970:
	if (local[3]==NIL) goto WHX3971;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= argv[0];
	local[5]= fqv[31];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= NIL;
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,6,local+4); /*send*/
	goto WHL3970;
WHX3971:
	local[4]= NIL;
BLK3972:
	w = NIL;
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= fqv[45];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF3968;
IF3967:
	local[2]= NIL;
IF3968:
	w = local[2];
	local[0]= w;
BLK3958:
	ctx->vsp=local; return(local[0]);}

/*:draw-edge*/
static pointer M3974viewer_draw_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3977;}
	local[0]= NIL;
ENT3977:
ENT3976:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF3978;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[18];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF3979;
IF3978:
	local[1]= NIL;
IF3979:
	local[1]= argv[0];
	local[2]= fqv[21];
	local[3]= argv[2]->c.obj.iv[1];
	local[4]= argv[2]->c.obj.iv[2];
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[0]= w;
BLK3975:
	ctx->vsp=local; return(local[0]);}

/*:draw-faces*/
static pointer M3980viewer_draw_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3984;}
	local[0]= NIL;
ENT3984:
	if (n>=5) { local[1]=(argv[4]); goto ENT3983;}
	local[1]= NIL;
ENT3983:
ENT3982:
	if (n>5) maerror();
	local[2]= NIL;
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= fqv[47];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= argv[2];
WHL3986:
	if (local[7]==NIL) goto WHX3987;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	if (local[0]==NIL) goto AND3992;
	local[8]= local[6];
	local[9]= fqv[48];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	local[9]= makeflt(0.00000000e+00);
	ctx->vsp=local+10;
	w=(pointer)LESSP(ctx,2,local+8); /*<*/
	if (w==NIL) goto AND3992;
	goto IF3990;
AND3992:
	if (local[1]==NIL) goto IF3993;
	local[8]= local[1];
	goto IF3994;
IF3993:
	local[8]= local[6];
	local[9]= fqv[18];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
IF3994:
	local[5] = local[8];
	local[8]= NIL;
	local[9]= local[6];
	local[10]= fqv[49];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
WHL3996:
	if (local[9]==NIL) goto WHX3997;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= local[8];
	w = local[2];
	if (memq(local[10],w)!=NIL) goto IF4000;
	local[10]= argv[0];
	local[11]= fqv[50];
	local[12]= local[8];
	local[13]= local[5];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	local[10]= local[8];
	w = local[2];
	ctx->vsp=local+11;
	local[2] = cons(ctx,local[10],w);
	local[10]= local[2];
	goto IF4001;
IF4000:
	local[10]= NIL;
IF4001:
	goto WHL3996;
WHX3997:
	local[10]= NIL;
BLK3998:
	w = NIL;
	local[8]= w;
	goto IF3991;
IF3990:
	local[8]= NIL;
IF3991:
	goto WHL3986;
WHX3987:
	local[8]= NIL;
BLK3988:
	w = NIL;
WHL4002:
	if (local[2]==NIL) goto WHX4003;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)RECLAIM(ctx,1,local+6); /*system:reclaim*/
	local[2] = local[4];
	goto WHL4002;
WHX4003:
	local[6]= NIL;
BLK4004:
	w = local[6];
	local[0]= w;
BLK3981:
	ctx->vsp=local; return(local[0]);}

/*:draw-body*/
static pointer M4005viewer_draw_body(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT4008;}
	local[0]= T;
ENT4008:
ENT4007:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= fqv[51];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[52];
	local[3]= argv[2];
	local[4]= fqv[53];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= local[0];
	local[5]= argv[2];
	local[6]= fqv[18];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[0]= w;
BLK4006:
	ctx->vsp=local; return(local[0]);}

/*:draw-axis*/
static pointer M4009viewer_draw_axis(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT4012;}
	local[0]= NIL;
ENT4012:
ENT4011:
	if (n>4) maerror();
	if (local[0]!=NIL) goto IF4013;
	local[0] = makeflt(1.00000000e+00);
	local[1]= local[0];
	goto IF4014;
IF4013:
	local[1]= NIL;
IF4014:
	local[1]= argv[2];
	local[2]= fqv[54];
	local[3]= fqv[55];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= local[0];
	local[3]= makeflt(3.00000000e-01);
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= makeint(0);
	local[4]= makeint(0);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= fqv[54];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[21];
	local[7]= local[1];
	local[8]= argv[2];
	local[9]= fqv[54];
	local[10]= local[0];
	local[11]= makeint(0);
	local[12]= makeint(0);
	ctx->vsp=local+13;
	w=(pointer)MKFLTVEC(ctx,3,local+10); /*float-vector*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[21];
	local[7]= local[1];
	local[8]= argv[2];
	local[9]= fqv[54];
	local[10]= makeint(0);
	local[11]= local[0];
	local[12]= makeint(0);
	ctx->vsp=local+13;
	w=(pointer)MKFLTVEC(ctx,3,local+10); /*float-vector*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[21];
	local[7]= local[1];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[21];
	local[7]= local[4];
	local[8]= argv[2];
	local[9]= fqv[54];
	local[10]= local[3];
	local[11]= local[2];
	local[12]= makeint(0);
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)MINUS(ctx,1,local+13); /*-*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)MKFLTVEC(ctx,3,local+11); /*float-vector*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)VPLUS(ctx,2,local+10); /*v+*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[21];
	local[7]= local[4];
	local[8]= argv[2];
	local[9]= fqv[54];
	local[10]= local[3];
	local[11]= makeint(0);
	local[12]= local[2];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)MINUS(ctx,1,local+13); /*-*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)MKFLTVEC(ctx,3,local+11); /*float-vector*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)VPLUS(ctx,2,local+10); /*v+*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[0]= w;
BLK4010:
	ctx->vsp=local; return(local[0]);}

/*:draw-one*/
static pointer M4015viewer_draw_one(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	w = argv[2];
	if (!isnum(w)) goto CON4018;
	local[0]= NIL;
	goto CON4017;
CON4018:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON4019;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*float-vector-p*/
	if (w==NIL) goto CON4021;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= local[0];
	w = fqv[56];
	if (memq(local[1],w)==NIL) goto IF4023;
	local[1]= argv[0];
	local[2]= fqv[21];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF4024;
IF4023:
	local[1]= local[0];
	if (fqv[57]!=local[1]) goto IF4025;
	local[1]= argv[0];
	local[2]= fqv[31];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF4026;
IF4025:
	if (T==NIL) goto IF4027;
	local[1]= fqv[58];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF4028;
IF4027:
	local[1]= NIL;
IF4028:
IF4026:
IF4024:
	w = local[1];
	local[0]= w;
	goto CON4020;
CON4021:
	local[0]= NIL;
	local[1]= argv[2];
WHL4031:
	if (local[1]==NIL) goto WHX4032;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0];
	local[3]= fqv[59];
	local[4]= local[0];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	goto WHL4031;
WHX4032:
	local[2]= NIL;
BLK4033:
	w = NIL;
	local[0]= w;
	goto CON4020;
CON4029:
	local[0]= NIL;
CON4020:
	goto CON4017;
CON4019:
	local[0]= argv[2];
	local[1]= fqv[60];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[61]); /*find-method*/
	if (w==NIL) goto CON4035;
	local[0]= argv[2];
	local[1]= fqv[60];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON4017;
CON4035:
	local[0]= argv[2];
	local[1]= fqv[62];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[61]); /*find-method*/
	if (w==NIL) goto CON4036;
	local[0]= argv[2];
	local[1]= fqv[51];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[61]); /*find-method*/
	if (w==NIL) goto IF4037;
	local[0]= argv[2];
	local[1]= fqv[51];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF4038;
IF4037:
	local[0]= NIL;
IF4038:
	local[0]= argv[0];
	local[1]= fqv[59];
	local[2]= argv[2];
	local[3]= fqv[62];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON4017;
CON4036:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[63]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON4039;
	local[0]= argv[0];
	local[1]= fqv[50];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON4017;
CON4039:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[64]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON4040;
	local[0]= argv[0];
	local[1]= fqv[65];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON4017;
CON4040:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[66]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON4041;
	local[0]= argv[2];
	local[1]= fqv[51];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[2];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= argv[2];
	local[3]= fqv[67];
	local[4]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
WHL4043:
	if (local[2]==NIL) goto WHX4044;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[0];
	local[4]= fqv[50];
	local[5]= local[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	goto WHL4043;
WHX4044:
	local[3]= NIL;
BLK4045:
	w = NIL;
	local[0]= w;
	goto CON4017;
CON4041:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[68]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON4047;
	local[0]= argv[2];
	local[1]= fqv[51];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[2];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= argv[2];
	local[3]= fqv[69];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
WHL4049:
	if (local[2]==NIL) goto WHX4050;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[0];
	local[4]= fqv[50];
	local[5]= local[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	goto WHL4049;
WHX4050:
	local[3]= NIL;
BLK4051:
	w = NIL;
	local[0]= w;
	goto CON4017;
CON4047:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[70]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON4053;
	local[0]= argv[0];
	local[1]= fqv[52];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON4017;
CON4053:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[71]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON4054;
	local[0]= NIL;
	local[1]= argv[2];
	local[2]= fqv[69];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
WHL4056:
	if (local[1]==NIL) goto WHX4057;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0];
	local[3]= fqv[50];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	goto WHL4056;
WHX4057:
	local[2]= NIL;
BLK4058:
	w = NIL;
	local[0]= w;
	goto CON4017;
CON4054:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*float-vector-p*/
	if (w==NIL) goto CON4060;
	local[0]= argv[0];
	local[1]= fqv[72];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[3];
	goto CON4017;
CON4060:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[3])(ctx,1,local+0,&ftab[3],fqv[73]); /*coordinates-p*/
	if (w==NIL) goto CON4061;
	local[0]= argv[0];
	local[1]= fqv[74];
	local[2]= argv[2];
	local[3]= fqv[51];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON4017;
CON4061:
	local[0]= fqv[75];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w==NIL) goto CON4062;
	local[0]= argv[2];
	local[1]= loadglobal(fqv[75]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON4062;
	local[0]= argv[0];
	local[1]= fqv[76];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON4017;
CON4062:
	local[0]= fqv[77];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w==NIL) goto CON4063;
	local[0]= argv[2];
	local[1]= loadglobal(fqv[77]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON4063;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[78];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON4017;
CON4063:
	local[0]= fqv[79];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w==NIL) goto CON4064;
	local[0]= argv[2];
	local[1]= loadglobal(fqv[79]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON4064;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[18];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON4017;
CON4064:
	local[0]= NIL;
CON4017:
	w = local[0];
	local[0]= w;
BLK4016:
	ctx->vsp=local; return(local[0]);}

/*:draw*/
static pointer M4065viewer_draw(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT4068;}
	local[0]= NIL;
ENT4068:
ENT4067:
	if (n>4) maerror();
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)LISTP(ctx,1,local+1); /*listp*/
	if (w==NIL) goto CON4070;
	local[1]= NIL;
	local[2]= argv[2];
WHL4072:
	if (local[2]==NIL) goto WHX4073;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[0];
	local[4]= fqv[59];
	local[5]= local[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	goto WHL4072;
WHX4073:
	local[3]= NIL;
BLK4074:
	w = NIL;
	local[1]= w;
	goto CON4069;
CON4070:
	if (argv[2]==NIL) goto CON4076;
	local[1]= argv[0];
	local[2]= fqv[59];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON4069;
CON4076:
	local[1]= NIL;
CON4069:
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[15];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = T;
	local[0]= w;
BLK4066:
	ctx->vsp=local; return(local[0]);}

/*:erase*/
static pointer M4077viewer_erase(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[80];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[60];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[81];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK4078:
	ctx->vsp=local; return(local[0]);}

/*:clear*/
static pointer M4079viewer_clear(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[82];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[15];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK4080:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M4081viewer_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[83], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY4083;
	local[0] = NIL;
KEY4083:
	if (n & (1<<1)) goto KEY4084;
	local[1] = NIL;
KEY4084:
	if (n & (1<<2)) goto KEY4085;
	local[2] = NIL;
KEY4085:
	if (n & (1<<3)) goto KEY4086;
	local[3] = NIL;
KEY4086:
	if (n & (1<<4)) goto KEY4087;
	local[4] = NIL;
KEY4087:
	local[5]= argv[0];
	local[6]= local[4];
	local[7]= fqv[84];
	ctx->vsp=local+8;
	w=(pointer)PUTPROP(ctx,3,local+5); /*putprop*/
	argv[0]->c.obj.iv[1] = local[0];
	argv[0]->c.obj.iv[2] = local[1];
	argv[0]->c.obj.iv[3] = local[2];
	local[5]= local[3];
	storeglobal(fqv[85],local[5]);
	local[5]= argv[0];
	w = loadglobal(fqv[86]);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	storeglobal(fqv[86],local[5]);
	w = argv[0];
	local[0]= w;
BLK4082:
	ctx->vsp=local; return(local[0]);}

/*:adjust-viewport*/
static pointer M4088viewer_adjust_viewport(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4094;}
	local[0]= NIL;
ENT4094:
	if (n>=4) { local[1]=(argv[3]); goto ENT4093;}
	local[1]= NIL;
ENT4093:
	if (n>=5) { local[2]=(argv[4]); goto ENT4092;}
	local[2]= local[0];
	local[3]= makeint(2);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
ENT4092:
	if (n>=6) { local[3]=(argv[5]); goto ENT4091;}
	local[3]= local[1];
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
ENT4091:
ENT4090:
	if (n>6) maerror();
	if (local[0]!=NIL) goto IF4095;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[5];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[0] = w;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[6];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[1] = w;
	local[4]= local[1];
	goto IF4096;
IF4095:
	local[4]= NIL;
IF4096:
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= fqv[87];
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= fqv[88];
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,1,local+7); /*-*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[0]= w;
BLK4089:
	ctx->vsp=local; return(local[0]);}

/*:resize*/
static pointer M4097viewer_resize(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT4100;}
	local[0]= argv[2];
ENT4100:
ENT4099:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[89];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[15];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[90];
	local[3]= argv[2];
	local[4]= local[0];
	local[5]= argv[2];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= local[0];
	local[7]= makeint(2);
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= fqv[91];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)EUSFLOAT(ctx,1,local+3); /*float*/
	local[3]= w;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK4098:
	ctx->vsp=local; return(local[0]);}

/*draw*/
static pointer F3719draw(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4102:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= loadglobal(fqv[92]);
	ctx->vsp=local+6;
	w=(pointer)DERIVEDP(ctx,2,local+4); /*derivedp*/
	if (w==NIL) goto IF4103;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[4]= w;
	goto IF4104;
IF4103:
	local[4]= loadglobal(fqv[93]);
IF4104:
	local[2] = local[4];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!isint(w)) goto IF4106;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[3] = w;
	local[4]= local[2];
	local[5]= fqv[94];
	local[6]= fqv[95];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto IF4107;
IF4106:
	local[4]= NIL;
IF4107:
	local[4]= NIL;
	local[5]= local[0];
WHL4110:
	if (local[5]==NIL) goto WHX4111;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[2];
	local[7]= fqv[60];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	goto WHL4110;
WHX4111:
	local[6]= NIL;
BLK4112:
	w = NIL;
	w = local[3];
	if (!isint(w)) goto IF4114;
	local[4]= local[2];
	local[5]= fqv[94];
	local[6]= fqv[95];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto IF4115;
IF4114:
	local[4]= NIL;
IF4115:
	w = local[4];
	local[0]= w;
BLK4101:
	ctx->vsp=local; return(local[0]);}

/*draw-tree*/
static pointer F3720draw_tree(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4117:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= NIL;
WHL4118:
	if (local[0]==NIL) goto WHX4119;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	local[4]= loadglobal(fqv[68]);
	ctx->vsp=local+5;
	w=(pointer)DERIVEDP(ctx,2,local+3); /*derivedp*/
	if (w==NIL) goto IF4122;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F3719draw(ctx,1,local+3); /*draw*/
	local[3]= w;
	goto IF4123;
IF4122:
	local[3]= NIL;
IF4123:
	local[3]= local[1];
	local[4]= fqv[96];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[2] = w;
	local[3]= NIL;
	local[4]= local[2];
WHL4125:
	if (local[4]==NIL) goto WHX4126;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3];
	w = local[0];
	ctx->vsp=local+6;
	local[0] = cons(ctx,local[5],w);
	goto WHL4125;
WHX4126:
	local[5]= NIL;
BLK4127:
	w = NIL;
	goto WHL4118;
WHX4119:
	local[3]= NIL;
BLK4120:
	w = local[3];
	local[0]= w;
BLK4116:
	ctx->vsp=local; return(local[0]);}

/*erase*/
static pointer F3721erase(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4130:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= loadglobal(fqv[93]);
	local[3]= NIL;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= loadglobal(fqv[92]);
	ctx->vsp=local+6;
	w=(pointer)DERIVEDP(ctx,2,local+4); /*derivedp*/
	if (w==NIL) goto IF4131;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	goto IF4132;
IF4131:
	local[4]= NIL;
IF4132:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!isint(w)) goto IF4134;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[3] = w;
	local[4]= local[2];
	local[5]= fqv[94];
	local[6]= fqv[95];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto IF4135;
IF4134:
	local[4]= NIL;
IF4135:
	local[4]= local[2];
	local[5]= fqv[97];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	w = local[3];
	if (!isint(w)) goto IF4137;
	local[4]= local[2];
	local[5]= fqv[94];
	local[6]= fqv[95];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto IF4138;
IF4137:
	local[4]= NIL;
IF4138:
	w = local[4];
	local[0]= w;
BLK4129:
	ctx->vsp=local; return(local[0]);}

/*draw-axis*/
static pointer F3722draw_axis(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4140:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= loadglobal(fqv[93]);
	local[3]= makeflt(1.00000000e+01);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= loadglobal(fqv[92]);
	ctx->vsp=local+6;
	w=(pointer)DERIVEDP(ctx,2,local+4); /*derivedp*/
	if (w==NIL) goto IF4141;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	goto IF4142;
IF4141:
	local[4]= NIL;
IF4142:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!isnum(w)) goto IF4144;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[3] = w;
	local[4]= local[3];
	goto IF4145;
IF4144:
	local[4]= NIL;
IF4145:
	local[4]= NIL;
	local[5]= local[0];
WHL4148:
	if (local[5]==NIL) goto WHX4149;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[2];
	local[7]= fqv[74];
	local[8]= local[4];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	goto WHL4148;
WHX4149:
	local[6]= NIL;
BLK4150:
	w = NIL;
	local[4]= local[2];
	local[5]= fqv[94];
	local[6]= fqv[15];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[0]= w;
BLK4139:
	ctx->vsp=local; return(local[0]);}

/*draw-arrow*/
static pointer F3723draw_arrow(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[93]);
	local[1]= fqv[98];
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= loadglobal(fqv[99]);
	local[1]= fqv[15];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK4152:
	ctx->vsp=local; return(local[0]);}

/*hid*/
static pointer F3724hid(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4154:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= loadglobal(fqv[93]);
	local[3]= NIL;
	local[4]= NIL;
	local[5]= T;
	local[6]= makeflt(0.00000000e+00);
	local[7]= makeflt(0.00000000e+00);
	local[8]= makeflt(0.00000000e+00);
	local[9]= makeflt(0.00000000e+00);
	w = local[9];
	ctx->vsp=local+10;
	bindspecial(ctx,fqv[100],w);
	w = local[8];
	ctx->vsp=local+13;
	bindspecial(ctx,fqv[101],w);
	w = local[7];
	ctx->vsp=local+16;
	bindspecial(ctx,fqv[102],w);
	w = local[6];
	ctx->vsp=local+19;
	bindspecial(ctx,fqv[103],w);
	w = local[5];
	ctx->vsp=local+22;
	bindspecial(ctx,fqv[104],w);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25]= (w)->c.cons.car;
	local[26]= loadglobal(fqv[92]);
	ctx->vsp=local+27;
	w=(pointer)DERIVEDP(ctx,2,local+25); /*derivedp*/
	if (w==NIL) goto IF4155;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[25];
	local[2] = w;
	local[25]= local[2];
	goto IF4156;
IF4155:
	local[25]= NIL;
IF4156:
	local[25]= NIL;
	local[26]= local[0];
	ctx->vsp=local+27;
	w=(*ftab[4])(ctx,1,local+26,&ftab[4],fqv[105]); /*flatten*/
	local[26]= w;
WHL4159:
	if (local[26]==NIL) goto WHX4160;
	w=local[26];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[27]= (w)->c.cons.car;
	w=local[26];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26] = (w)->c.cons.cdr;
	w = local[27];
	local[25] = w;
	local[27]= local[25];
	local[28]= fqv[62];
	ctx->vsp=local+29;
	w=(*ftab[2])(ctx,2,local+27,&ftab[2],fqv[61]); /*find-method*/
	if (w==NIL) goto IF4163;
	local[27]= local[25];
	local[28]= fqv[62];
	ctx->vsp=local+29;
	w=(pointer)SEND(ctx,2,local+27); /*send*/
	local[27]= w;
	local[28]= local[3];
	ctx->vsp=local+29;
	w=(pointer)APPEND(ctx,2,local+27); /*append*/
	local[3] = w;
	local[27]= local[3];
	goto IF4164;
IF4163:
	local[27]= local[25];
	w = local[3];
	ctx->vsp=local+28;
	local[3] = cons(ctx,local[27],w);
	local[27]= local[3];
IF4164:
	goto WHL4159;
WHX4160:
	local[27]= NIL;
BLK4161:
	w = NIL;
	local[25]= local[3];
	local[26]= local[2];
	local[27]= fqv[106];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,2,local+26); /*send*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(*ftab[5])(ctx,2,local+25,&ftab[5],fqv[107]); /*hid2*/
	local[25]= local[2];
	local[26]= fqv[60];
	local[27]= loadglobal(fqv[108]);
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,3,local+25); /*send*/
	local[25]= w;
	ctx->vsp=local+26;
	unbindx(ctx,5);
	w = local[25];
	local[0]= w;
BLK4153:
	ctx->vsp=local; return(local[0]);}

/*hidd*/
static pointer F3725hidd(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4166:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= loadglobal(fqv[93]);
	local[3]= NIL;
	local[4]= NIL;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= loadglobal(fqv[92]);
	ctx->vsp=local+7;
	w=(pointer)DERIVEDP(ctx,2,local+5); /*derivedp*/
	if (w==NIL) goto IF4167;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[5];
	local[2] = w;
	local[5]= local[2];
	goto IF4168;
IF4167:
	local[5]= NIL;
IF4168:
	local[5]= NIL;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,1,local+6,&ftab[4],fqv[105]); /*flatten*/
	local[6]= w;
WHL4171:
	if (local[6]==NIL) goto WHX4172;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[5];
	local[8]= fqv[62];
	ctx->vsp=local+9;
	w=(*ftab[2])(ctx,2,local+7,&ftab[2],fqv[61]); /*find-method*/
	if (w==NIL) goto IF4175;
	local[7]= local[5];
	local[8]= fqv[62];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)APPEND(ctx,2,local+7); /*append*/
	local[3] = w;
	local[7]= local[3];
	goto IF4176;
IF4175:
	local[7]= local[5];
	w = local[3];
	ctx->vsp=local+8;
	local[3] = cons(ctx,local[7],w);
	local[7]= local[3];
IF4176:
	goto WHL4171;
WHX4172:
	local[7]= NIL;
BLK4173:
	w = NIL;
	local[5]= makeflt(0.00000000e+00);
	local[6]= makeflt(0.00000000e+00);
	local[7]= makeflt(0.00000000e+00);
	local[8]= makeflt(0.00000000e+00);
	w = local[8];
	ctx->vsp=local+9;
	bindspecial(ctx,fqv[100],w);
	w = local[7];
	ctx->vsp=local+12;
	bindspecial(ctx,fqv[101],w);
	w = local[6];
	ctx->vsp=local+15;
	bindspecial(ctx,fqv[102],w);
	w = local[5];
	ctx->vsp=local+18;
	bindspecial(ctx,fqv[103],w);
	local[21]= local[3];
	local[22]= local[2];
	local[23]= fqv[106];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,2,local+22); /*send*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(*ftab[5])(ctx,2,local+21,&ftab[5],fqv[107]); /*hid2*/
	local[21]= w;
	ctx->vsp=local+22;
	unbindx(ctx,4);
	w = local[21];
	local[5]= NIL;
	local[6]= loadglobal(fqv[108]);
WHL4178:
	if (local[6]==NIL) goto WHX4179;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[2];
	local[8]= fqv[65];
	local[9]= local[5];
	local[10]= T;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	goto WHL4178;
WHX4179:
	local[7]= NIL;
BLK4180:
	w = NIL;
	if (loadglobal(fqv[109])==NIL) goto IF4182;
	local[5]= local[2];
	local[6]= fqv[94];
	local[7]= fqv[45];
	local[8]= makeint(1);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= NIL;
	local[6]= loadglobal(fqv[110]);
WHL4185:
	if (local[6]==NIL) goto WHX4186;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	if (loadglobal(fqv[104])==NIL) goto AND4191;
	local[7]= local[5];
	local[8]= fqv[111];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	if (w==NIL) goto AND4191;
	goto IF4189;
AND4191:
	local[7]= local[2];
	local[8]= fqv[50];
	local[9]= local[5];
	local[10]= local[5];
	local[11]= fqv[18];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[7]= w;
	goto IF4190;
IF4189:
	local[7]= NIL;
IF4190:
	goto WHL4185;
WHX4186:
	local[7]= NIL;
BLK4187:
	w = NIL;
	local[5]= local[2];
	local[6]= fqv[94];
	local[7]= fqv[45];
	local[8]= makeint(0);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto IF4183;
IF4182:
	local[5]= NIL;
IF4183:
	local[5]= local[2];
	local[6]= fqv[94];
	local[7]= fqv[15];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[0]= w;
BLK4165:
	ctx->vsp=local; return(local[0]);}

/*cls*/
static pointer F3726cls(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT4194;}
	local[0]= loadglobal(fqv[93]);
ENT4194:
ENT4193:
	if (n>1) maerror();
	local[1]= local[0];
	local[2]= fqv[94];
	local[3]= fqv[82];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= local[0];
	local[2]= fqv[94];
	local[3]= fqv[15];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK4192:
	ctx->vsp=local; return(local[0]);}

/*draw-hid*/
static pointer F3727draw_hid(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT4197;}
	local[0]= loadglobal(fqv[93]);
ENT4197:
ENT4196:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= argv[0];
WHL4199:
	if (local[2]==NIL) goto WHX4200;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[0];
	local[4]= fqv[31];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,5,local+3); /*send*/
	goto WHL4199;
WHX4200:
	local[3]= NIL;
BLK4201:
	w = NIL;
	ctx->vsp=local+1;
	w=(*ftab[6])(ctx,0,local+1,&ftab[6],fqv[112]); /*xflush*/
	local[0]= w;
BLK4195:
	ctx->vsp=local; return(local[0]);}

/*draw-step*/
static pointer F3728draw_step(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4204:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= loadglobal(fqv[93]);
	w = local[2];
	ctx->vsp=local+2;
	bindspecial(ctx,fqv[93],w);
	local[5]= makeint(3);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= loadglobal(fqv[92]);
	ctx->vsp=local+8;
	w=(pointer)DERIVEDP(ctx,2,local+6); /*derivedp*/
	if (w==NIL) goto IF4205;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	storeglobal(fqv[93],w);
	goto IF4206;
IF4205:
	local[6]= NIL;
IF4206:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!isint(w)) goto IF4208;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[6];
	local[5] = w;
	local[6]= local[5];
	goto IF4209;
IF4208:
	local[6]= NIL;
IF4209:
	ctx->vsp=local+6;
	w = makeclosure(codevec,quotevec,UWP4211,env,argv,local);
	local[6]=(pointer)(ctx->protfp); local[7]=w;
	ctx->protfp=(struct protectframe *)(local+6);
	local[8]= NIL;
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(*ftab[4])(ctx,1,local+9,&ftab[4],fqv[105]); /*flatten*/
	local[9]= w;
WHL4213:
	if (local[9]==NIL) goto WHX4214;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= loadglobal(fqv[93]);
	local[11]= fqv[94];
	local[12]= fqv[95];
	local[13]= local[5];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	local[10]= loadglobal(fqv[93]);
	local[11]= fqv[94];
	local[12]= fqv[113];
	local[13]= makeint(6);
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)PRINT(ctx,1,local+10); /*print*/
	local[10]= loadglobal(fqv[93]);
	local[11]= fqv[60];
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	ctx->vsp=local+10;
	w=(pointer)READCH(ctx,0,local+10); /*read-char*/
	local[10]= w;
	local[11]= local[10];
	local[12]= makeint(113);
	ctx->vsp=local+13;
	w=(pointer)EQ(ctx,2,local+11); /*eql*/
	if (w==NIL) goto IF4217;
	w = local[8];
	ctx->vsp=local+11;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK4203;
	goto IF4218;
IF4217:
	local[11]= NIL;
IF4218:
	w = local[11];
	local[10]= loadglobal(fqv[93]);
	local[11]= fqv[60];
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= loadglobal(fqv[93]);
	local[11]= fqv[94];
	local[12]= fqv[95];
	local[13]= makeint(1);
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	local[10]= loadglobal(fqv[93]);
	local[11]= fqv[94];
	local[12]= fqv[113];
	local[13]= makeint(15);
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	local[10]= loadglobal(fqv[93]);
	local[11]= fqv[60];
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(pointer)F3719draw(ctx,3,local+10); /*draw*/
	goto WHL4213;
WHX4214:
	local[10]= NIL;
BLK4215:
	w = NIL;
	ctx->vsp=local+8;
	UWP4211(ctx,0,local+8,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[6]= w;
	ctx->vsp=local+7;
	unbindx(ctx,1);
	w = local[6];
	local[0]= w;
BLK4203:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP4211(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= loadglobal(fqv[93]);
	local[1]= fqv[94];
	local[2]= fqv[95];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= loadglobal(fqv[93]);
	local[1]= fqv[94];
	local[2]= fqv[113];
	local[3]= makeint(15);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*find-viewer*/
static pointer F3729find_viewer(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO4220,env,argv,local);
	local[1]= loadglobal(fqv[86]);
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,2,local+0,&ftab[7],fqv[114]); /*find-if*/
	local[0]= w;
BLK4219:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4220(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= argv[0];
	local[2]= fqv[84];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[8])(ctx,2,local+0,&ftab[8],fqv[115]); /*string-equal*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*view*/
static pointer F3730view(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4222:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[116], &argv[0], n-0, local+1, 1);
	if (n & (1<<0)) goto KEY4223;
	local[1] = NIL;
KEY4223:
	if (n & (1<<1)) goto KEY4224;
	local[2] = NIL;
KEY4224:
	if (n & (1<<2)) goto KEY4225;
	local[3] = NIL;
KEY4225:
	if (n & (1<<3)) goto KEY4226;
	local[4] = makeint(3);
KEY4226:
	if (n & (1<<4)) goto KEY4227;
	local[5] = makeint(500);
KEY4227:
	if (n & (1<<5)) goto KEY4228;
	local[6] = local[5];
KEY4228:
	if (n & (1<<6)) goto KEY4229;
	local[7] = local[5];
KEY4229:
	if (n & (1<<7)) goto KEY4230;
	local[8] = makeint(100);
KEY4230:
	if (n & (1<<8)) goto KEY4231;
	local[9] = makeint(100);
KEY4231:
	if (n & (1<<9)) goto KEY4232;
	local[10] = fqv[117];
KEY4232:
	if (n & (1<<10)) goto KEY4233;
	local[11] = local[10];
KEY4233:
	if (n & (1<<11)) goto KEY4234;
	local[12] = NIL;
KEY4234:
	if (n & (1<<12)) goto KEY4235;
	local[13] = makeint(3);
KEY4235:
	if (n & (1<<13)) goto KEY4236;
	local[14] = NIL;
KEY4236:
	if (n & (1<<14)) goto KEY4237;
	local[28]= makeint(300);
	local[29]= makeint(200);
	local[30]= makeint(100);
	ctx->vsp=local+31;
	w=(pointer)MKFLTVEC(ctx,3,local+28); /*float-vector*/
	local[15] = w;
KEY4237:
	if (n & (1<<15)) goto KEY4238;
	local[28]= makeint(0);
	local[29]= makeint(0);
	local[30]= makeint(0);
	ctx->vsp=local+31;
	w=(pointer)MKFLTVEC(ctx,3,local+28); /*float-vector*/
	local[16] = w;
KEY4238:
	if (n & (1<<16)) goto KEY4239;
	local[17] = makeflt(5.00000000e+00);
KEY4239:
	if (n & (1<<17)) goto KEY4240;
	local[18] = makeflt(1.00000000e+02);
KEY4240:
	if (n & (1<<18)) goto KEY4241;
	local[19] = makeflt(1.00000000e+04);
KEY4241:
	if (n & (1<<19)) goto KEY4242;
	local[20] = makeflt(1.00000000e+00);
KEY4242:
	if (n & (1<<20)) goto KEY4243;
	local[21] = local[20];
KEY4243:
	if (n & (1<<21)) goto KEY4244;
	local[22] = local[20];
KEY4244:
	if (n & (1<<22)) goto KEY4245;
	local[28]= local[6];
	local[29]= makeflt(2.00000000e+00);
	ctx->vsp=local+30;
	w=(pointer)QUOTIENT(ctx,2,local+28); /*/*/
	local[23] = w;
KEY4245:
	if (n & (1<<23)) goto KEY4246;
	local[28]= local[7];
	local[29]= makeflt(2.00000000e+00);
	ctx->vsp=local+30;
	w=(pointer)QUOTIENT(ctx,2,local+28); /*/*/
	local[24] = w;
KEY4246:
	if (n & (1<<24)) goto KEY4247;
	local[25] = makeint(2);
KEY4247:
	if (n & (1<<25)) goto KEY4248;
	local[26] = makeint(0);
KEY4248:
	if (n & (1<<26)) goto KEY4249;
	local[27] = NIL;
KEY4249:
	local[28]= NIL;
	local[29]= NIL;
	local[30]= NIL;
	local[31]= NIL;
	if (local[2]==NIL) goto IF4250;
	local[28] = local[2];
	local[32]= local[28];
	goto IF4251;
IF4250:
	local[32]= (pointer)get_sym_func(fqv[118]);
	local[33]= fqv[119];
	local[34]= local[8];
	local[35]= fqv[120];
	local[36]= local[9];
	local[37]= fqv[5];
	local[38]= local[6];
	local[39]= fqv[6];
	local[40]= local[7];
	local[41]= fqv[121];
	local[42]= local[10];
	local[43]= fqv[122];
	local[44]= local[12];
	local[45]= fqv[123];
	local[46]= local[13];
	local[47]= fqv[124];
	local[48]= local[14];
	local[49]= fqv[125];
	local[50]= local[25];
	local[51]= fqv[126];
	local[52]= local[26];
	local[53]= fqv[84];
	local[54]= local[11];
	local[55]= local[0];
	ctx->vsp=local+56;
	w=(pointer)APPLY(ctx,24,local+32); /*apply*/
	local[28] = w;
	local[32]= local[28];
IF4251:
	if (local[1]==NIL) goto IF4252;
	local[29] = local[1];
	local[32]= local[29];
	goto IF4253;
IF4252:
	local[32]= loadglobal(fqv[127]);
	ctx->vsp=local+33;
	w=(pointer)INSTANTIATE(ctx,1,local+32); /*instantiate*/
	local[32]= w;
	local[33]= local[32];
	local[34]= fqv[12];
	local[35]= fqv[13];
	local[36]= local[4];
	local[37]= fqv[7];
	local[38]= local[23];
	local[39]= fqv[8];
	local[40]= local[24];
	local[41]= fqv[5];
	local[42]= local[6];
	local[43]= fqv[6];
	local[44]= fqv[128];
	local[45]= loadglobal(fqv[129]);
	ctx->vsp=local+46;
	w=(*ftab[9])(ctx,2,local+44,&ftab[9],fqv[130]); /*member*/
	if (w!=NIL) goto OR4257;
	local[44]= fqv[131];
	local[45]= loadglobal(fqv[129]);
	ctx->vsp=local+46;
	w=(*ftab[9])(ctx,2,local+44,&ftab[9],fqv[130]); /*member*/
	if (w!=NIL) goto OR4257;
	goto IF4255;
OR4257:
	local[44]= local[7];
	ctx->vsp=local+45;
	w=(pointer)MINUS(ctx,1,local+44); /*-*/
	local[44]= w;
	goto IF4256;
IF4255:
	local[44]= local[7];
IF4256:
	ctx->vsp=local+45;
	w=(pointer)SEND(ctx,12,local+33); /*send*/
	w = local[32];
	local[29] = w;
	local[32]= local[29];
IF4253:
	if (local[3]==NIL) goto IF4258;
	local[32]= local[3];
	goto IF4259;
IF4258:
	local[32]= local[4];
	local[33]= makeint(2);
	ctx->vsp=local+34;
	w=(pointer)NUMEQUAL(ctx,2,local+32); /*=*/
	if (w==NIL) goto IF4260;
	local[32]= loadglobal(fqv[132]);
	ctx->vsp=local+33;
	w=(pointer)INSTANTIATE(ctx,1,local+32); /*instantiate*/
	local[32]= w;
	local[33]= (pointer)get_sym_func(fqv[14]);
	local[34]= local[32];
	local[35]= fqv[12];
	local[36]= fqv[122];
	local[37]= NIL;
	local[38]= fqv[133];
	local[39]= local[15];
	local[40]= makeint(0);
	ctx->vsp=local+41;
	w=(pointer)AREF(ctx,2,local+39); /*aref*/
	local[39]= w;
	local[40]= local[15];
	local[41]= makeint(1);
	ctx->vsp=local+42;
	w=(pointer)AREF(ctx,2,local+40); /*aref*/
	local[40]= w;
	ctx->vsp=local+41;
	w=(pointer)MKFLTVEC(ctx,2,local+39); /*float-vector*/
	local[39]= w;
	local[40]= local[0];
	ctx->vsp=local+41;
	w=(pointer)APPLY(ctx,8,local+33); /*apply*/
	w = local[32];
	local[32]= w;
	goto IF4261;
IF4260:
	local[32]= loadglobal(fqv[134]);
	ctx->vsp=local+33;
	w=(pointer)INSTANTIATE(ctx,1,local+32); /*instantiate*/
	local[32]= w;
	local[33]= (pointer)get_sym_func(fqv[14]);
	local[34]= local[32];
	local[35]= fqv[12];
	local[36]= fqv[122];
	local[37]= NIL;
	local[38]= fqv[133];
	local[39]= local[15];
	local[40]= fqv[135];
	local[41]= local[16];
	local[42]= fqv[136];
	local[43]= local[17];
	local[44]= fqv[137];
	local[45]= local[18];
	local[46]= fqv[138];
	local[47]= local[19];
	local[48]= fqv[139];
	local[49]= local[21];
	local[50]= fqv[140];
	local[51]= local[22];
	local[52]= local[0];
	ctx->vsp=local+53;
	w=(pointer)APPLY(ctx,20,local+33); /*apply*/
	w = local[32];
	local[32]= w;
IF4261:
IF4259:
	local[30] = local[32];
	local[32]= local[11];
	ctx->vsp=local+33;
	w=(pointer)F3729find_viewer(ctx,1,local+32); /*find-viewer*/
	local[31] = w;
	if (local[31]!=NIL) goto IF4264;
	local[32]= loadglobal(fqv[92]);
	ctx->vsp=local+33;
	w=(pointer)INSTANTIATE(ctx,1,local+32); /*instantiate*/
	local[31] = w;
	local[32]= local[31];
	goto IF4265;
IF4264:
	local[32]= NIL;
IF4265:
	local[32]= fqv[141];
	ctx->vsp=local+33;
	w=(pointer)BOUNDP(ctx,1,local+32); /*boundp*/
	if (w==NIL) goto IF4266;
	w = loadglobal(fqv[141]);
	if (!isnum(w)) goto IF4266;
	if (local[27]==NIL) goto IF4266;
	local[32]= local[27];
	local[33]= loadglobal(fqv[142]);
	ctx->vsp=local+34;
	w=(pointer)DERIVEDP(ctx,2,local+32); /*derivedp*/
	if (w!=NIL) goto IF4266;
	local[32]= loadglobal(fqv[143]);
	ctx->vsp=local+33;
	w=(pointer)INSTANTIATE(ctx,1,local+32); /*instantiate*/
	local[32]= w;
	local[33]= local[32];
	local[34]= fqv[144];
	local[35]= fqv[5];
	local[36]= local[6];
	local[37]= fqv[6];
	local[38]= local[7];
	ctx->vsp=local+39;
	w=(pointer)SEND(ctx,6,local+33); /*send*/
	w = local[32];
	local[27] = w;
	local[32]= local[27];
	goto IF4267;
IF4266:
	local[32]= NIL;
IF4267:
	local[32]= local[31];
	local[33]= fqv[12];
	local[34]= fqv[106];
	local[35]= local[30];
	local[36]= fqv[94];
	local[37]= local[28];
	local[38]= fqv[145];
	local[39]= local[29];
	local[40]= fqv[84];
	local[41]= local[11];
	local[42]= fqv[146];
	local[43]= local[27];
	ctx->vsp=local+44;
	w=(pointer)SEND(ctx,12,local+32); /*send*/
	w = local[31];
	local[0]= w;
BLK4221:
	ctx->vsp=local; return(local[0]);}

/*with-gc*/
static pointer F4269(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST4271:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	w = argv[0];
	if (!iscons(w)) goto CON4273;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	local[4]= fqv[147];
	local[5]= fqv[148];
	local[6]= fqv[144];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[2] = cons(ctx,local[4],w);
	local[4]= fqv[14];
	local[5]= local[1];
	local[6]= fqv[149];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[3] = w;
	local[4]= local[3];
	goto CON4272;
CON4273:
	local[1] = argv[0];
	local[2] = argv[0];
	local[3] = NIL;
	local[4]= local[3];
	goto CON4272;
CON4274:
	local[4]= NIL;
CON4272:
	local[4]= fqv[150];
	local[5]= fqv[151];
	local[6]= fqv[14];
	local[7]= fqv[93];
	local[8]= fqv[94];
	local[9]= fqv[152];
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
	local[6]= local[1];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[153];
	local[7]= fqv[154];
	local[8]= fqv[14];
	local[9]= fqv[93];
	local[10]= fqv[94];
	local[11]= fqv[152];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	w = local[0];
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[14];
	local[9]= fqv[93];
	local[10]= fqv[94];
	local[11]= fqv[152];
	local[12]= fqv[151];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	w = local[3];
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
	w = cons(ctx,local[4],w);
	local[0]= w;
BLK4270:
	ctx->vsp=local; return(local[0]);}

/*with-viewsurface*/
static pointer F4275(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST4277:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[150];
	local[2]= fqv[155];
	local[3]= fqv[156];
	local[4]= fqv[93];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	local[3]= fqv[153];
	local[4]= fqv[154];
	local[5]= fqv[157];
	local[6]= fqv[156];
	local[7]= fqv[93];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	w = local[0];
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[157];
	local[6]= fqv[156];
	local[7]= fqv[93];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[155];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK4276:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___viewport(ctx,n,argv,env)
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
	local[0]= fqv[158];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF4278;
	local[0]= fqv[159];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[160],w);
	goto IF4279;
IF4278:
	local[0]= fqv[161];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF4279:
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,FLET4280,env,argv,local);
	local[1]= fqv[162];
	local[2]= fqv[163];
	w = local[0];
	ctx->vsp=local+3;
	w=FLET4280(ctx,2,local+1,w);
	local[1]= fqv[164];
	local[2]= fqv[165];
	w = local[0];
	ctx->vsp=local+3;
	w=FLET4280(ctx,2,local+1,w);
	local[1]= fqv[166];
	local[2]= fqv[167];
	w = local[0];
	ctx->vsp=local+3;
	w=FLET4280(ctx,2,local+1,w);
	local[1]= fqv[168];
	local[2]= fqv[169];
	w = local[0];
	ctx->vsp=local+3;
	w=FLET4280(ctx,2,local+1,w);
	local[1]= fqv[170];
	local[2]= fqv[171];
	w = local[0];
	ctx->vsp=local+3;
	w=FLET4280(ctx,2,local+1,w);
	local[1]= fqv[172];
	local[2]= fqv[173];
	w = local[0];
	ctx->vsp=local+3;
	w=FLET4280(ctx,2,local+1,w);
	local[0]= fqv[174];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF4281;
	local[0]= fqv[175];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[160],w);
	goto IF4282;
IF4281:
	local[0]= fqv[176];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF4282:
	local[0]= fqv[93];
	local[1]= fqv[177];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF4283;
	local[0]= fqv[93];
	local[1]= fqv[177];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[93];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF4285;
	local[0]= fqv[93];
	local[1]= fqv[178];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF4286;
IF4285:
	local[0]= NIL;
IF4286:
	local[0]= fqv[93];
	goto IF4284;
IF4283:
	local[0]= NIL;
IF4284:
	local[0]= fqv[86];
	local[1]= fqv[177];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF4287;
	local[0]= fqv[86];
	local[1]= fqv[177];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[86];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF4289;
	local[0]= fqv[86];
	local[1]= fqv[178];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF4290;
IF4289:
	local[0]= NIL;
IF4290:
	local[0]= fqv[86];
	goto IF4288;
IF4287:
	local[0]= NIL;
IF4288:
	local[0]= fqv[179];
	local[1]= fqv[177];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF4291;
	local[0]= fqv[179];
	local[1]= fqv[177];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[179];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF4293;
	local[0]= fqv[179];
	local[1]= fqv[178];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF4294;
IF4293:
	local[0]= NIL;
IF4294:
	local[0]= fqv[179];
	goto IF4292;
IF4291:
	local[0]= NIL;
IF4292:
	local[0]= fqv[99];
	local[1]= fqv[177];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF4295;
	local[0]= fqv[99];
	local[1]= fqv[177];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[99];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF4297;
	local[0]= fqv[99];
	local[1]= fqv[178];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF4298;
IF4297:
	local[0]= NIL;
IF4298:
	local[0]= fqv[99];
	goto IF4296;
IF4295:
	local[0]= NIL;
IF4296:
	local[0]= fqv[180];
	local[1]= fqv[177];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF4299;
	local[0]= fqv[180];
	local[1]= fqv[177];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[180];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF4301;
	local[0]= fqv[180];
	local[1]= fqv[178];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF4302;
IF4301:
	local[0]= NIL;
IF4302:
	local[0]= fqv[180];
	goto IF4300;
IF4299:
	local[0]= NIL;
IF4300:
	local[0]= fqv[181];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[2];
	local[1]= fqv[178];
	local[2]= makeint(0);
	local[3]= makeint(0);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[3];
	local[1]= fqv[178];
	local[2]= makeint(0);
	local[3]= makeint(0);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[127];
	local[1]= fqv[178];
	local[2]= fqv[127];
	local[3]= fqv[182];
	local[4]= loadglobal(fqv[183]);
	local[5]= fqv[184];
	local[6]= fqv[185];
	local[7]= fqv[186];
	local[8]= NIL;
	local[9]= fqv[187];
	local[10]= NIL;
	local[11]= fqv[88];
	local[12]= makeint(-1);
	local[13]= fqv[188];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[10])(ctx,13,local+2,&ftab[10],fqv[189]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3732viewport_xcenter,fqv[7],fqv[127],fqv[190]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3738viewport_ycenter,fqv[8],fqv[127],fqv[191]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3744viewport_center,fqv[87],fqv[127],fqv[192]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3753viewport_width,fqv[5],fqv[127],fqv[193]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3759viewport_height,fqv[6],fqv[127],fqv[194]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3765viewport_size,fqv[88],fqv[127],fqv[195]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3774viewport_screen_point_to_ndc,fqv[196],fqv[127],fqv[197]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3776viewport_ndc_width_to_screen,fqv[25],fqv[127],fqv[198]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3778viewport_ndc_height_to_screen,fqv[26],fqv[127],fqv[199]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3780viewport_ndc_point_to_screen,fqv[16],fqv[127],fqv[200]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3784viewport_ndc_line_to_screen,fqv[20],fqv[127],fqv[201]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3796viewport_resize,fqv[89],fqv[127],fqv[202]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3811viewport_init,fqv[12],fqv[127],fqv[203]);
	local[0]= fqv[92];
	local[1]= fqv[178];
	local[2]= fqv[92];
	local[3]= fqv[182];
	local[4]= loadglobal(fqv[204]);
	local[5]= fqv[184];
	local[6]= fqv[205];
	local[7]= fqv[186];
	local[8]= NIL;
	local[9]= fqv[187];
	local[10]= NIL;
	local[11]= fqv[88];
	local[12]= makeint(-1);
	local[13]= fqv[188];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[10])(ctx,13,local+2,&ftab[10],fqv[189]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3819viewer_viewing,fqv[106],fqv[92],fqv[206]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3824viewer_viewsurface,fqv[94],fqv[92],fqv[207]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3829viewer_viewport,fqv[145],fqv[92],fqv[208]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3834viewer_flush,fqv[15],fqv[92],fqv[209]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3836viewer_point_to_screen,fqv[210],fqv[92],fqv[211]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3838viewer_draw_point_ndc,fqv[212],fqv[92],fqv[213]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3844viewer_draw_line_ndc,fqv[31],fqv[92],fqv[214]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3853viewer_draw_string_ndc,fqv[215],fqv[92],fqv[216]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3859viewer_draw_image_string_ndc,fqv[217],fqv[92],fqv[218]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3865viewer_draw_rectangle_ndc,fqv[219],fqv[92],fqv[220]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3871viewer_draw_fill_rectangle_ndc,fqv[221],fqv[92],fqv[222]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3877viewer_draw_arc_ndc,fqv[35],fqv[92],fqv[223]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3885viewer_draw_fill_arc_ndc,fqv[36],fqv[92],fqv[224]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3891viewer_draw_polyline_ndc,fqv[32],fqv[92],fqv[225]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3900viewer_draw_box_ndc,fqv[33],fqv[92],fqv[226]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3904viewer_draw_star_ndc,fqv[41],fqv[92],fqv[227]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3909viewer_draw_line,fqv[21],fqv[92],fqv[228]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3914viewer_draw_box,fqv[229],fqv[92],fqv[230]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3919viewer_draw_polyline,fqv[231],fqv[92],fqv[232]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3924viewer_draw_arc,fqv[29],fqv[92],fqv[233]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3932viewer_draw_fill_arc,fqv[30],fqv[92],fqv[234]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3940viewer_draw_arrow,fqv[98],fqv[92],fqv[235]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3946viewer_pane,fqv[236],fqv[92],fqv[237]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3948viewer_draw_star,fqv[72],fqv[92],fqv[238]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3955viewer_draw_2dlnseg,fqv[76],fqv[92],fqv[239]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3957viewer_draw_edge_image,fqv[65],fqv[92],fqv[240]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3974viewer_draw_edge,fqv[50],fqv[92],fqv[241]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3980viewer_draw_faces,fqv[52],fqv[92],fqv[242]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4005viewer_draw_body,fqv[243],fqv[92],fqv[244]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4009viewer_draw_axis,fqv[74],fqv[92],fqv[245]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4015viewer_draw_one,fqv[59],fqv[92],fqv[246]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4065viewer_draw,fqv[60],fqv[92],fqv[247]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4077viewer_erase,fqv[97],fqv[92],fqv[248]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4079viewer_clear,fqv[82],fqv[92],fqv[249]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4081viewer_init,fqv[12],fqv[92],fqv[250]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4088viewer_adjust_viewport,fqv[90],fqv[92],fqv[251]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4097viewer_resize,fqv[89],fqv[92],fqv[252]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[253],module,F3719draw,fqv[254]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[255],module,F3720draw_tree,fqv[256]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[257],module,F3721erase,fqv[258]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[259],module,F3722draw_axis,fqv[260]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[261],module,F3723draw_arrow,fqv[262]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[263],module,F3724hid,fqv[264]);
	local[0]= fqv[109];
	local[1]= fqv[177];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF4303;
	local[0]= fqv[109];
	local[1]= fqv[177];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[109];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF4305;
	local[0]= fqv[109];
	local[1]= fqv[178];
	local[2]= T;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF4306;
IF4305:
	local[0]= NIL;
IF4306:
	local[0]= fqv[109];
	goto IF4304;
IF4303:
	local[0]= NIL;
IF4304:
	ctx->vsp=local+0;
	compfun(ctx,fqv[265],module,F3725hidd,fqv[266]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[267],module,F3726cls,fqv[268]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[269],module,F3727draw_hid,fqv[270]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[271],module,F3728draw_step,fqv[272]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[273],module,F3729find_viewer,fqv[274]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[275],module,F3730view,fqv[276]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[277],module,F4269,fqv[278]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[279],module,F4275,fqv[280]);
	local[0]= fqv[145];
	local[1]= fqv[281];
	ctx->vsp=local+2;
	w=(*ftab[11])(ctx,2,local+0,&ftab[11],fqv[282]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET4280(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= fqv[283];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<12; i++) ftab[i]=fcallx;
}
