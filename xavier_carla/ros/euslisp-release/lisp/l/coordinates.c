/* ./coordinates.c :  entry=coordinates */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "coordinates.h"
#pragma init (register_coordinates)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___coordinates();
extern pointer build_quote_vector();
static int register_coordinates()
  { add_module_initializer("___coordinates", ___coordinates);}

static pointer F80485coordinates_p();
static pointer F80505transform_coords();
static pointer F80507transform_coords_();
static pointer F80509transform_vector();
static pointer F80511make_coords();
static pointer F80513make_cascoords();
static pointer F80515coords();
static pointer F80517cascoords();
static pointer F80519wrt();
static pointer F80524coordinates_distance();

/*coordinates-p*/
static pointer F80485coordinates_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[0]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK80572:
	ctx->vsp=local; return(local[0]);}

/*:dimension*/
static pointer M80598coordinates_dimension(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
BLK80599:
	ctx->vsp=local; return(local[0]);}

/*:rot*/
static pointer M80615coordinates_rot(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK80616:
	ctx->vsp=local; return(local[0]);}

/*:pos*/
static pointer M80631coordinates_pos(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK80632:
	ctx->vsp=local; return(local[0]);}

/*:x-axis*/
static pointer M80647coordinates_x_axis(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[1]); /*matrix-row*/
	local[0]= w;
BLK80648:
	ctx->vsp=local; return(local[0]);}

/*:y-axis*/
static pointer M80665coordinates_y_axis(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[1]); /*matrix-row*/
	local[0]= w;
BLK80666:
	ctx->vsp=local; return(local[0]);}

/*:z-axis*/
static pointer M80682coordinates_z_axis(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[1]); /*matrix-row*/
	local[0]= w;
BLK80683:
	ctx->vsp=local; return(local[0]);}

/*:name*/
static pointer M80699coordinates_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT80703;}
	local[0]= NIL;
ENT80703:
ENT80702:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF80719;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[2];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= w;
	goto IF80720;
IF80719:
	local[1]= NIL;
IF80720:
	local[1]= argv[0];
	local[2]= fqv[2];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[0]= w;
BLK80700:
	ctx->vsp=local; return(local[0]);}

/*:newcoords*/
static pointer M80739coordinates_newcoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT80743;}
	local[0]= NIL;
ENT80743:
ENT80742:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF80761;
	argv[0]->c.obj.iv[1] = argv[2];
	argv[0]->c.obj.iv[2] = local[0];
	local[1]= argv[0]->c.obj.iv[2];
	goto IF80762;
IF80761:
	argv[0]->c.obj.iv[1] = argv[2]->c.obj.iv[1];
	argv[0]->c.obj.iv[2] = argv[2]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[2];
IF80762:
	w = argv[0];
	local[0]= w;
BLK80740:
	ctx->vsp=local; return(local[0]);}

/*:replace-rot*/
static pointer M80797coordinates_replace_rot(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[3]); /*replace-matrix*/
	local[0]= w;
BLK80798:
	ctx->vsp=local; return(local[0]);}

/*:replace-pos*/
static pointer M80818coordinates_replace_pos(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[4]); /*replace*/
	local[0]= w;
BLK80819:
	ctx->vsp=local; return(local[0]);}

/*:replace-coords*/
static pointer M80839coordinates_replace_coords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT80843;}
	local[0]= NIL;
ENT80843:
ENT80842:
	if (n>4) maerror();
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F80485coordinates_p(ctx,1,local+1); /*coordinates-p*/
	if (w==NIL) goto IF80862;
	local[0] = argv[2]->c.obj.iv[2];
	argv[2] = argv[2]->c.obj.iv[1];
	local[1]= argv[2];
	goto IF80863;
IF80862:
	local[1]= NIL;
IF80863:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[3]); /*replace-matrix*/
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[4]); /*replace*/
	w = argv[0];
	local[0]= w;
BLK80840:
	ctx->vsp=local; return(local[0]);}

/*:copy-rot*/
static pointer M80904coordinates_copy_rot(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(*ftab[3])(ctx,1,local+0,&ftab[3],fqv[5]); /*copy-matrix*/
	local[0]= w;
BLK80905:
	ctx->vsp=local; return(local[0]);}

/*:copy-pos*/
static pointer M80922coordinates_copy_pos(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+1;
	w=(pointer)COPYSEQ(ctx,1,local+0); /*copy-seq*/
	local[0]= w;
BLK80923:
	ctx->vsp=local; return(local[0]);}

/*:copy-coords*/
static pointer M80939coordinates_copy_coords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT80943;}
	local[0]= loadglobal(fqv[0]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[6];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = local[0];
	local[0]= w;
ENT80943:
ENT80942:
	if (n>3) maerror();
	local[1]= local[0]->c.obj.iv[2];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[4]); /*replace*/
	local[1]= local[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[3]); /*replace-matrix*/
	w = local[0];
	local[0]= w;
BLK80940:
	ctx->vsp=local; return(local[0]);}

/*:coords*/
static pointer M81007coordinates_coords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT81011;}
	local[0]= loadglobal(fqv[0]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[6];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = local[0];
	local[0]= w;
ENT81011:
ENT81010:
	if (n>3) maerror();
	local[1]= local[0]->c.obj.iv[2];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[4]); /*replace*/
	local[1]= local[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[3]); /*replace-matrix*/
	w = local[0];
	local[0]= w;
BLK81008:
	ctx->vsp=local; return(local[0]);}

/*:worldrot*/
static pointer M81075coordinates_worldrot(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK81076:
	ctx->vsp=local; return(local[0]);}

/*:worldpos*/
static pointer M81091coordinates_worldpos(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK81092:
	ctx->vsp=local; return(local[0]);}

/*:worldcoords*/
static pointer M81107coordinates_worldcoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0];
	local[0]= w;
BLK81108:
	ctx->vsp=local; return(local[0]);}

/*:copy-worldcoords*/
static pointer M81123coordinates_copy_worldcoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[7];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK81124:
	ctx->vsp=local; return(local[0]);}

/*:parentcoords*/
static pointer M81142coordinates_parentcoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = loadglobal(fqv[8]);
	local[0]= w;
BLK81143:
	ctx->vsp=local; return(local[0]);}

/*:changed*/
static pointer M81159coordinates_changed(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = NIL;
	local[0]= w;
BLK81160:
	ctx->vsp=local; return(local[0]);}

/*:reset-coords*/
static pointer M81174coordinates_reset_coords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[9]); /*array-dimension*/
	local[0]= w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,1,local+1,&ftab[5],fqv[10]); /*unit-matrix*/
	argv[0]->c.obj.iv[1] = w;
	local[1]= loadglobal(fqv[11]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,2,local+1); /*instantiate*/
	argv[0]->c.obj.iv[2] = w;
	local[1]= argv[0];
	local[2]= fqv[12];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = argv[0];
	local[0]= w;
BLK81175:
	ctx->vsp=local; return(local[0]);}

/*:move-to*/
static pointer M81228coordinates_move_to(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT81232;}
	local[0]= fqv[13];
ENT81232:
ENT81231:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)F80485coordinates_p(ctx,1,local+3); /*coordinates-p*/
	if (w!=NIL) goto IF81257;
	local[3]= fqv[14];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
	goto IF81258;
IF81257:
	local[3]= NIL;
IF81258:
	local[3]= local[0];
	w = fqv[15];
	if (memq(local[3],w)!=NIL) goto OR81274;
	local[3]= local[0];
	if (argv[0]==local[3]) goto OR81274;
	goto CON81273;
OR81274:
	local[3]= argv[0];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)F80505transform_coords(ctx,2,local+3); /*transform-coords*/
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto CON81271;
CON81273:
	local[3]= local[0];
	w = fqv[17];
	if (memq(local[3],w)!=NIL) goto OR81306;
	local[3]= local[0];
	local[4]= loadglobal(fqv[8]);
	ctx->vsp=local+5;
	w=(pointer)EQUAL(ctx,2,local+3); /*equal*/
	if (w!=NIL) goto OR81306;
	goto CON81305;
OR81306:
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto CON81271;
CON81305:
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F80485coordinates_p(ctx,1,local+3); /*coordinates-p*/
	if (w==NIL) goto CON81330;
	local[3]= local[0];
	local[4]= fqv[18];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)F80505transform_coords(ctx,2,local+3); /*transform-coords*/
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[19];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= fqv[20];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= local[2];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)F80505transform_coords(ctx,3,local+3); /*transform-coords*/
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto CON81271;
CON81330:
	local[3]= NIL;
CON81271:
	w = local[3];
	local[0]= w;
BLK81229:
	ctx->vsp=local; return(local[0]);}

/*:rotate-vector*/
static pointer M81373coordinates_rotate_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
BLK81374:
	ctx->vsp=local; return(local[0]);}

/*:transform-vector*/
static pointer M81393coordinates_transform_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)VPLUS(ctx,2,local+0); /*v+*/
	local[0]= w;
BLK81394:
	ctx->vsp=local; return(local[0]);}

/*:inverse-transform-vector*/
static pointer M81416coordinates_inverse_transform_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)TRANSPOSE(ctx,1,local+0); /*transpose*/
	local[0]= w;
	local[1]= local[0];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)TRANSFORM(ctx,2,local+1); /*transform*/
	local[1]= w;
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)TRANSFORM(ctx,2,local+2); /*transform*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[0]= w;
BLK81417:
	ctx->vsp=local; return(local[0]);}

/*:inverse-transformation*/
static pointer M81456coordinates_inverse_transformation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT81460;}
	local[0]= loadglobal(fqv[0]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[6];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = local[0];
	local[0]= w;
ENT81460:
ENT81459:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= local[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)TRANSPOSE(ctx,2,local+1); /*transpose*/
	local[1]= local[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)TRANSFORM(ctx,3,local+1); /*transform*/
	local[1]= makeflt(-1.00000000e+00);
	local[2]= local[0]->c.obj.iv[2];
	local[3]= local[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SCALEVEC(ctx,3,local+1); /*scale*/
	w = local[0];
	local[0]= w;
BLK81457:
	ctx->vsp=local; return(local[0]);}

/*:transformation*/
static pointer M81542coordinates_transformation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT81546;}
	local[0]= fqv[13];
ENT81546:
ENT81545:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= fqv[18];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	argv[2] = w;
	local[1]= argv[0];
	local[2]= fqv[18];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[20];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= NIL;
	local[4]= local[0];
	w = fqv[21];
	if (memq(local[4],w)!=NIL) goto OR81602;
	local[4]= local[0];
	if (argv[0]==local[4]) goto OR81602;
	goto CON81601;
OR81602:
	local[4]= local[2];
	local[5]= argv[2];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F80505transform_coords(ctx,3,local+4); /*transform-coords*/
	local[4]= w;
	goto CON81599;
CON81601:
	local[4]= local[0];
	w = fqv[22];
	if (memq(local[4],w)!=NIL) goto OR81623;
	local[4]= local[0];
	if (loadglobal(fqv[8])==local[4]) goto OR81623;
	goto CON81622;
OR81623:
	local[4]= argv[2];
	local[5]= local[2];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F80505transform_coords(ctx,3,local+4); /*transform-coords*/
	local[4]= w;
	goto CON81599;
CON81622:
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)F80485coordinates_p(ctx,1,local+4); /*coordinates-p*/
	if (w==NIL) goto CON81644;
	local[4]= local[0];
	local[5]= fqv[18];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[3] = w;
	local[4]= argv[2];
	local[5]= local[2];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F80505transform_coords(ctx,3,local+4); /*transform-coords*/
	local[4]= local[3];
	local[5]= fqv[20];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[2];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F80505transform_coords(ctx,3,local+4); /*transform-coords*/
	local[4]= local[2];
	local[5]= local[3];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F80505transform_coords(ctx,3,local+4); /*transform-coords*/
	local[4]= w;
	goto CON81599;
CON81644:
	local[4]= argv[0];
	local[5]= fqv[23];
	local[6]= fqv[24];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto CON81599;
CON81683:
	local[4]= NIL;
CON81599:
	w = local[2];
	local[0]= w;
BLK81543:
	ctx->vsp=local; return(local[0]);}

/*:transform*/
static pointer M81698coordinates_transform(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT81702;}
	local[0]= fqv[13];
ENT81702:
ENT81701:
	if (n>4) maerror();
	local[1]= local[0];
	w = fqv[25];
	if (memq(local[1],w)!=NIL) goto OR81725;
	local[1]= local[0];
	if (argv[0]==local[1]) goto OR81725;
	goto CON81724;
OR81725:
	local[1]= argv[0];
	local[2]= argv[2];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F80505transform_coords(ctx,3,local+1); /*transform-coords*/
	local[1]= w;
	goto CON81722;
CON81724:
	local[1]= local[0];
	w = fqv[26];
	if (memq(local[1],w)!=NIL) goto OR81746;
	local[1]= local[0];
	if (loadglobal(fqv[8])==local[1]) goto OR81746;
	goto CON81745;
OR81746:
	local[1]= argv[2];
	local[2]= argv[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F80505transform_coords(ctx,3,local+1); /*transform-coords*/
	local[1]= w;
	goto CON81722;
CON81745:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F80485coordinates_p(ctx,1,local+1); /*coordinates-p*/
	if (w==NIL) goto CON81767;
	local[1]= local[0];
	local[2]= fqv[20];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F80505transform_coords(ctx,3,local+1); /*transform-coords*/
	local[1]= argv[2];
	local[2]= argv[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F80505transform_coords(ctx,3,local+1); /*transform-coords*/
	local[1]= local[0];
	local[2]= fqv[18];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F80505transform_coords(ctx,3,local+1); /*transform-coords*/
	local[1]= w;
	goto CON81722;
CON81767:
	local[1]= argv[0];
	local[2]= fqv[23];
	local[3]= fqv[27];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON81722;
CON81799:
	local[1]= NIL;
CON81722:
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK81699:
	ctx->vsp=local; return(local[0]);}

/*:rotate-with-matrix*/
static pointer M81818coordinates_rotate_with_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	w = fqv[28];
	if (memq(local[0],w)!=NIL) goto OR81838;
	local[0]= argv[3];
	if (argv[0]==local[0]) goto OR81838;
	goto CON81837;
OR81838:
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)MATTIMES(ctx,3,local+0); /*m**/
	local[0]= w;
	goto CON81835;
CON81837:
	local[0]= argv[3];
	w = fqv[29];
	if (memq(local[0],w)!=NIL) goto OR81859;
	local[0]= argv[3];
	if (loadglobal(fqv[8])==local[0]) goto OR81859;
	goto CON81858;
OR81859:
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)MATTIMES(ctx,3,local+0); /*m**/
	local[0]= w;
	goto CON81835;
CON81858:
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)F80485coordinates_p(ctx,1,local+0); /*coordinates-p*/
	if (w==NIL) goto CON81880;
	local[0]= argv[3];
	local[1]= fqv[30];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)TRANSPOSE(ctx,1,local+1); /*transpose*/
	local[1]= w;
	local[2]= NIL;
	local[3]= argv[2];
	local[4]= local[1];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)MATTIMES(ctx,3,local+3); /*m**/
	local[3]= local[0];
	local[4]= local[1];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)MATTIMES(ctx,3,local+3); /*m**/
	local[3]= local[1];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)MATTIMES(ctx,3,local+3); /*m**/
	local[0]= w;
	goto CON81835;
CON81880:
	local[0]= argv[0];
	local[1]= fqv[23];
	local[2]= fqv[31];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON81835;
CON81925:
	local[0]= NIL;
CON81835:
	w = local[0];
	local[0]= w;
BLK81819:
	ctx->vsp=local; return(local[0]);}

/*:rotate*/
static pointer M81935coordinates_rotate(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT81940;}
	local[0]= NIL;
ENT81940:
	if (n>=5) { local[1]=(argv[4]); goto ENT81939;}
	local[1]= fqv[13];
ENT81939:
ENT81938:
	if (n>5) maerror();
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	if (makeint(2)!=local[2]) goto CON81966;
	w = argv[2];
	if (!isnum(w)) goto CON81976;
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[2];
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+7;
	w=(pointer)ROTMAT(ctx,5,local+2); /*rotate-matrix*/
	local[2]= w;
	goto CON81974;
CON81976:
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[6])(ctx,1,local+2,&ftab[6],fqv[32]); /*matrixp*/
	if (w==NIL) goto CON81986;
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)MATTIMES(ctx,3,local+2); /*m**/
	local[2]= w;
	goto CON81974;
CON81986:
	local[2]= fqv[33];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,1,local+2); /*error*/
	local[2]= w;
	goto CON81974;
CON81999:
	local[2]= NIL;
CON81974:
	goto CON81964;
CON81966:
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[7])(ctx,1,local+2,&ftab[7],fqv[34]); /*float-vector-p*/
	if (w==NIL) goto CON82004;
	local[2]= argv[0];
	local[3]= fqv[35];
	local[4]= argv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+4); /*rotation-matrix*/
	local[4]= w;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	goto CON81964;
CON82004:
	if (local[0]!=NIL) goto CON82022;
	local[2]= argv[0];
	local[3]= fqv[35];
	local[4]= argv[2];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	goto CON81964;
CON82022:
	local[2]= local[1];
	w = fqv[36];
	if (memq(local[2],w)!=NIL) goto OR82041;
	local[2]= local[1];
	if (argv[0]==local[2]) goto OR82041;
	goto CON82040;
OR82041:
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[2];
	local[4]= local[0];
	local[5]= NIL;
	local[6]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+7;
	w=(pointer)ROTMAT(ctx,5,local+2); /*rotate-matrix*/
	local[2]= w;
	goto CON82038;
CON82040:
	local[2]= local[1];
	w = fqv[37];
	if (memq(local[2],w)!=NIL) goto OR82063;
	local[2]= local[1];
	if (loadglobal(fqv[8])==local[2]) goto OR82063;
	goto CON82062;
OR82063:
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[2];
	local[4]= local[0];
	local[5]= T;
	local[6]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+7;
	w=(pointer)ROTMAT(ctx,5,local+2); /*rotate-matrix*/
	local[2]= w;
	goto CON82038;
CON82062:
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)F80485coordinates_p(ctx,1,local+2); /*coordinates-p*/
	if (w==NIL) goto CON82085;
	local[2]= argv[0];
	local[3]= fqv[35];
	local[4]= argv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+4); /*rotation-matrix*/
	local[4]= w;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	goto CON82038;
CON82085:
	local[2]= argv[0];
	local[3]= fqv[23];
	local[4]= fqv[38];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	goto CON82038;
CON82102:
	local[2]= NIL;
CON82038:
	goto CON81964;
CON82034:
	local[2]= NIL;
CON81964:
	local[2]= argv[0];
	local[3]= fqv[16];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[0]= w;
BLK81936:
	ctx->vsp=local; return(local[0]);}

/*:orient-with-matrix*/
static pointer M82121coordinates_orient_with_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	w = fqv[39];
	if (memq(local[0],w)!=NIL) goto OR82141;
	local[0]= argv[3];
	if (argv[0]==local[0]) goto OR82141;
	goto CON82140;
OR82141:
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)MATTIMES(ctx,3,local+0); /*m**/
	local[0]= w;
	goto CON82138;
CON82140:
	local[0]= argv[3];
	w = fqv[40];
	if (memq(local[0],w)!=NIL) goto OR82162;
	local[0]= argv[3];
	if (loadglobal(fqv[8])==local[0]) goto OR82162;
	goto CON82161;
OR82162:
	argv[0]->c.obj.iv[1] = argv[2];
	local[0]= argv[0]->c.obj.iv[1];
	goto CON82138;
CON82161:
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)F80485coordinates_p(ctx,1,local+0); /*coordinates-p*/
	if (w==NIL) goto CON82185;
	local[0]= argv[3];
	local[1]= fqv[30];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)MATTIMES(ctx,3,local+1); /*m**/
	local[0]= w;
	goto CON82138;
CON82185:
	local[0]= argv[0];
	local[1]= fqv[23];
	local[2]= fqv[41];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON82138;
CON82211:
	local[0]= NIL;
CON82138:
	w = local[0];
	local[0]= w;
BLK82122:
	ctx->vsp=local; return(local[0]);}

/*:orient*/
static pointer M82221coordinates_orient(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT82225;}
	local[0]= fqv[13];
ENT82225:
ENT82224:
	if (n>5) maerror();
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,1,local+1,&ftab[7],fqv[34]); /*float-vector-p*/
	if (w==NIL) goto CON82249;
	local[1]= argv[0];
	local[2]= fqv[42];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+3); /*rotation-matrix*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON82247;
CON82249:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[32]); /*matrixp*/
	if (w==NIL) goto CON82266;
	local[1]= argv[0];
	local[2]= fqv[42];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON82247;
CON82266:
	local[1]= local[0];
	w = fqv[43];
	if (memq(local[1],w)!=NIL) goto OR82287;
	local[1]= local[0];
	if (argv[0]==local[1]) goto OR82287;
	goto CON82286;
OR82287:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= NIL;
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)ROTMAT(ctx,5,local+1); /*rotate-matrix*/
	local[1]= w;
	goto CON82284;
CON82286:
	local[1]= local[0];
	w = fqv[44];
	if (memq(local[1],w)!=NIL) goto OR82309;
	local[1]= local[0];
	if (loadglobal(fqv[8])==local[1]) goto OR82309;
	goto CON82308;
OR82309:
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+1); /*rotation-matrix*/
	argv[0]->c.obj.iv[1] = w;
	local[1]= argv[0]->c.obj.iv[1];
	goto CON82284;
CON82308:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F80485coordinates_p(ctx,1,local+1); /*coordinates-p*/
	if (w==NIL) goto CON82335;
	local[1]= argv[0];
	local[2]= fqv[42];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+3); /*rotation-matrix*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON82284;
CON82335:
	local[1]= argv[0];
	local[2]= fqv[23];
	local[3]= fqv[45];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON82284;
CON82352:
	local[1]= NIL;
CON82284:
	goto CON82247;
CON82280:
	local[1]= NIL;
CON82247:
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK82222:
	ctx->vsp=local; return(local[0]);}

/*:parent-vector*/
static pointer M82371coordinates_parent_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	w = fqv[46];
	if (memq(local[0],w)!=NIL) goto OR82391;
	local[0]= argv[3];
	if (argv[0]==local[0]) goto OR82391;
	goto CON82390;
OR82391:
	local[0]= argv[0];
	local[1]= fqv[47];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON82388;
CON82390:
	local[0]= argv[3];
	w = fqv[48];
	if (memq(local[0],w)!=NIL) goto OR82413;
	local[0]= argv[3];
	if (loadglobal(fqv[8])==local[0]) goto OR82413;
	goto CON82412;
OR82413:
	local[0]= argv[2];
	goto CON82388;
CON82412:
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)F80485coordinates_p(ctx,1,local+0); /*coordinates-p*/
	if (w==NIL) goto CON82430;
	local[0]= argv[3];
	local[1]= fqv[47];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON82388;
CON82430:
	local[0]= argv[0];
	local[1]= fqv[23];
	local[2]= fqv[49];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON82388;
CON82443:
	local[0]= NIL;
CON82388:
	w = local[0];
	local[0]= w;
BLK82372:
	ctx->vsp=local; return(local[0]);}

/*:parent-orientation*/
static pointer M82454coordinates_parent_orientation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	w = fqv[50];
	if (memq(local[0],w)!=NIL) goto OR82474;
	local[0]= argv[3];
	if (argv[0]==local[0]) goto OR82474;
	goto CON82473;
OR82474:
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
	goto CON82471;
CON82473:
	local[0]= argv[3];
	w = fqv[51];
	if (memq(local[0],w)!=NIL) goto OR82494;
	local[0]= argv[3];
	if (loadglobal(fqv[8])==local[0]) goto OR82494;
	goto CON82493;
OR82494:
	local[0]= argv[2];
	goto CON82471;
CON82493:
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)F80485coordinates_p(ctx,1,local+0); /*coordinates-p*/
	if (w==NIL) goto CON82511;
	local[0]= argv[3];
	local[1]= fqv[30];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
	goto CON82471;
CON82511:
	local[0]= argv[0];
	local[1]= fqv[23];
	local[2]= fqv[52];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON82471;
CON82526:
	local[0]= NIL;
CON82471:
	w = local[0];
	local[0]= w;
BLK82455:
	ctx->vsp=local; return(local[0]);}

/*:translate*/
static pointer M82537coordinates_translate(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT82541;}
	local[0]= fqv[13];
ENT82541:
ENT82540:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0];
	local[5]= fqv[53];
	local[6]= argv[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[2];
	local[6]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+7;
	w=(pointer)VPLUS(ctx,3,local+4); /*v+*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK82538:
	ctx->vsp=local; return(local[0]);}

/*:locate*/
static pointer M82579coordinates_locate(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT82583;}
	local[0]= fqv[13];
ENT82583:
ENT82582:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= argv[0];
	local[6]= fqv[54];
	local[7]= argv[2];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[2])(ctx,2,local+4,&ftab[2],fqv[4]); /*replace*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK82580:
	ctx->vsp=local; return(local[0]);}

/*:scale*/
static pointer M82620coordinates_scale(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT82624;}
	local[0]= NIL;
ENT82624:
ENT82623:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF82640;
	local[1]= local[0];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(*ftab[8])(ctx,3,local+1,&ftab[8],fqv[55]); /*scale-matrix*/
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF82641;
IF82640:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[1]); /*matrix-row*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VNORM(ctx,1,local+1); /*norm*/
	local[1]= w;
IF82641:
	w = local[1];
	local[0]= w;
BLK82621:
	ctx->vsp=local; return(local[0]);}

/*:euler*/
static pointer M82668coordinates_euler(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= fqv[16];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= argv[4];
	ctx->vsp=local+5;
	w=(*ftab[9])(ctx,3,local+2,&ftab[9],fqv[56]); /*euler-matrix*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK82669:
	ctx->vsp=local; return(local[0]);}

/*:euler-angle*/
static pointer M82700coordinates_euler_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)INV_EULER(ctx,1,local+0); /*euler-angle*/
	local[0]= w;
BLK82701:
	ctx->vsp=local; return(local[0]);}

/*:rpy*/
static pointer M82717coordinates_rpy(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= fqv[16];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= argv[4];
	ctx->vsp=local+5;
	w=(*ftab[10])(ctx,3,local+2,&ftab[10],fqv[57]); /*rpy-matrix*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK82718:
	ctx->vsp=local; return(local[0]);}

/*:rpy-angle*/
static pointer M82749coordinates_rpy_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)INV_RPY(ctx,1,local+0); /*rpy-angle*/
	local[0]= w;
BLK82750:
	ctx->vsp=local; return(local[0]);}

/*:rotation-angle*/
static pointer M82766coordinates_rotation_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)ROTANGLE(ctx,1,local+0); /*rotation-angle*/
	local[0]= w;
BLK82767:
	ctx->vsp=local; return(local[0]);}

/*:4x4*/
static pointer M82783coordinates_4x4(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT82787;}
	local[0]= NIL;
ENT82787:
ENT82786:
	if (n>3) maerror();
	if (local[0]==NIL) goto CON82805;
	local[1]= makeint(0);
	local[2]= makeint(3);
WHL82833:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX82834;
	local[3]= makeint(0);
	local[4]= makeint(3);
WHL82864:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX82865;
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= local[1];
	local[7]= local[3];
	local[8]= local[0];
	local[9]= local[1];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL82864;
WHX82865:
	local[5]= NIL;
BLK82866:
	w = NIL;
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= local[1];
	local[5]= local[0];
	local[6]= local[1];
	local[7]= makeint(3);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,3,local+5); /*aref*/
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[4]); v=local[3];
	  v->c.fvec.fv[i]=fltval(w);}
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL82833;
WHX82834:
	local[3]= NIL;
BLK82835:
	w = NIL;
	local[1]= argv[0];
	goto CON82803;
CON82805:
	local[1]= makeint(4);
	local[2]= makeint(4);
	ctx->vsp=local+3;
	w=(*ftab[11])(ctx,2,local+1,&ftab[11],fqv[58]); /*make-matrix*/
	local[0] = w;
	local[1]= local[0];
	local[2]= makeint(3);
	local[3]= makeint(3);
	local[4]= makeflt(1.00000000e+00);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,4,local+1); /*aset*/
	local[1]= makeint(0);
	local[2]= makeint(3);
WHL82960:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX82961;
	local[3]= makeint(0);
	local[4]= makeint(3);
WHL82991:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX82992;
	local[5]= local[0];
	local[6]= local[1];
	local[7]= local[3];
	local[8]= argv[0]->c.obj.iv[1];
	local[9]= local[1];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL82991;
WHX82992:
	local[5]= NIL;
BLK82993:
	w = NIL;
	local[3]= local[0];
	local[4]= local[1];
	local[5]= makeint(3);
	local[6]= argv[0]->c.obj.iv[2];
	{ register eusinteger_t i=intval(local[1]);
	  w=makeflt(local[6]->c.fvec.fv[i]);}
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,4,local+3); /*aset*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL82960;
WHX82961:
	local[3]= NIL;
BLK82962:
	w = NIL;
	local[1]= local[0];
	goto CON82803;
CON82920:
	local[1]= NIL;
CON82803:
	w = local[1];
	local[0]= w;
BLK82784:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M83050coordinates_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT83054;}
	local[0]= T;
ENT83054:
ENT83053:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-3);
	local[2]= NIL;
	local[3]= argv[0];
	local[4]= fqv[30];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[59];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[4];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	w = makeint(2);
	if ((eusinteger_t)local[5] <= (eusinteger_t)w) goto CON83089;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)INV_RPY(ctx,1,local+5); /*rpy-angle*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[60]));
	local[7]= fqv[61];
	local[8]= local[0];
	local[9]= NIL;
	local[10]= fqv[62];
	if (local[1]==NIL) goto IF83119;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	goto IF83120;
IF83119:
	local[11]= fqv[63];
IF83120:
	local[12]= local[4];
	local[13]= makeint(0);
	ctx->vsp=local+14;
	w=(pointer)AREF(ctx,2,local+12); /*aref*/
	local[12]= w;
	local[13]= local[4];
	local[14]= makeint(1);
	ctx->vsp=local+15;
	w=(pointer)AREF(ctx,2,local+13); /*aref*/
	local[13]= w;
	local[14]= local[4];
	local[15]= makeint(2);
	ctx->vsp=local+16;
	w=(pointer)AREF(ctx,2,local+14); /*aref*/
	local[14]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17]= (w)->c.cons.car;
	ctx->vsp=local+18;
	w=(pointer)XFORMAT(ctx,9,local+9); /*format*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SENDMESSAGE(ctx,5,local+5); /*send-message*/
	local[5]= w;
	goto CON83087;
CON83089:
	local[5]= local[4];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	if (makeint(2)!=local[5]) goto CON83161;
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[60]));
	local[7]= fqv[61];
	local[8]= local[0];
	local[9]= NIL;
	local[10]= fqv[64];
	if (local[1]==NIL) goto IF83178;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	goto IF83179;
IF83178:
	local[11]= fqv[65];
IF83179:
	local[12]= local[4];
	local[13]= makeint(0);
	ctx->vsp=local+14;
	w=(pointer)AREF(ctx,2,local+12); /*aref*/
	local[12]= w;
	local[13]= local[4];
	local[14]= makeint(1);
	ctx->vsp=local+15;
	w=(pointer)AREF(ctx,2,local+13); /*aref*/
	local[13]= w;
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(pointer)ROTANGLE(ctx,1,local+14); /*rotation-angle*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)XFORMAT(ctx,6,local+9); /*format*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SENDMESSAGE(ctx,5,local+5); /*send-message*/
	local[5]= w;
	goto CON83087;
CON83161:
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[60]));
	local[7]= fqv[61];
	local[8]= local[0];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SENDMESSAGE(ctx,5,local+5); /*send-message*/
	local[5]= w;
	goto CON83087;
CON83199:
	local[5]= NIL;
CON83087:
	w = local[5];
	local[0]= w;
BLK83051:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M83214coordinates_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT83218;}
	local[0]= makeint(3);
ENT83218:
ENT83217:
	if (n>3) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,1,local+1,&ftab[5],fqv[10]); /*unit-matrix*/
	argv[0]->c.obj.iv[1] = w;
	local[1]= loadglobal(fqv[11]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,2,local+1); /*instantiate*/
	argv[0]->c.obj.iv[2] = w;
	w = argv[0];
	local[0]= w;
BLK83215:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M83252coordinates_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[66], &argv[2], n-2, local+0, 1);
	if (n & (1<<0)) goto KEY83276;
	local[0] = makeint(3);
KEY83276:
	if (n & (1<<1)) goto KEY83281;
	local[13]= loadglobal(fqv[11]);
	local[14]= local[0];
	ctx->vsp=local+15;
	w=(pointer)INSTANTIATE(ctx,2,local+13); /*instantiate*/
	local[1] = w;
KEY83281:
	if (n & (1<<2)) goto KEY83290;
	local[13]= local[0];
	ctx->vsp=local+14;
	w=(*ftab[5])(ctx,1,local+13,&ftab[5],fqv[10]); /*unit-matrix*/
	local[2] = w;
KEY83290:
	if (n & (1<<3)) goto KEY83298;
	local[3] = NIL;
KEY83298:
	if (n & (1<<4)) goto KEY83303;
	local[4] = NIL;
KEY83303:
	if (n & (1<<5)) goto KEY83308;
	local[5] = NIL;
KEY83308:
	if (n & (1<<6)) goto KEY83313;
	local[6] = NIL;
KEY83313:
	if (n & (1<<7)) goto KEY83318;
	local[7] = NIL;
KEY83318:
	if (n & (1<<8)) goto KEY83323;
	local[8] = local[7];
KEY83323:
	if (n & (1<<9)) goto KEY83329;
	local[9] = NIL;
KEY83329:
	if (n & (1<<10)) goto KEY83334;
	local[10] = fqv[13];
KEY83334:
	if (n & (1<<11)) goto KEY83341;
	local[11] = NIL;
KEY83341:
	if (n & (1<<12)) goto KEY83346;
	local[12] = NIL;
KEY83346:
	argv[0]->c.obj.iv[1] = local[2];
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(pointer)F80485coordinates_p(ctx,1,local+13); /*coordinates-p*/
	if (w==NIL) goto IF83364;
	local[13]= local[10];
	local[14]= fqv[47];
	local[15]= local[1];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= w;
	goto IF83365;
IF83364:
	local[13]= local[1];
IF83365:
	argv[0]->c.obj.iv[2] = local[13];
	if (local[3]==NIL) goto CON83384;
	local[13]= argv[0];
	local[14]= fqv[67];
	local[15]= local[3];
	local[16]= makeint(0);
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	local[16]= local[3];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)ELT(ctx,2,local+16); /*elt*/
	local[16]= w;
	local[17]= local[3];
	local[18]= makeint(2);
	ctx->vsp=local+19;
	w=(pointer)ELT(ctx,2,local+17); /*elt*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,5,local+13); /*send*/
	local[13]= w;
	goto CON83382;
CON83384:
	if (local[4]==NIL) goto CON83403;
	local[13]= argv[0];
	local[14]= fqv[68];
	local[15]= local[4];
	local[16]= makeint(0);
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	local[16]= local[4];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)ELT(ctx,2,local+16); /*elt*/
	local[16]= w;
	local[17]= local[4];
	local[18]= makeint(2);
	ctx->vsp=local+19;
	w=(pointer)ELT(ctx,2,local+17); /*elt*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,5,local+13); /*send*/
	local[13]= w;
	goto CON83382;
CON83403:
	if (local[8]==NIL) goto CON83422;
	local[13]= argv[0];
	local[14]= fqv[69];
	local[15]= local[8];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= w;
	goto CON83382;
CON83422:
	w = local[6];
	if (!iscons(w)) goto CON83433;
	local[13]= NIL;
	local[14]= local[6];
WHL83456:
	if (local[14]==NIL) goto WHX83457;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14] = (w)->c.cons.cdr;
	w = local[15];
	local[13] = w;
	local[15]= argv[0];
	local[16]= fqv[70];
	local[17]= local[13];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[18];
	local[18]= w;
	local[19]= local[10];
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,5,local+15); /*send*/
	goto WHL83456;
WHX83457:
	local[15]= NIL;
BLK83458:
	w = NIL;
	local[13]= w;
	goto CON83382;
CON83433:
	w = local[6];
	if (!isnum(w)) goto CON83549;
	local[13]= argv[0];
	local[14]= fqv[70];
	local[15]= local[6];
	local[16]= local[5];
	local[17]= local[10];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,5,local+13); /*send*/
	local[13]= w;
	goto CON83382;
CON83549:
	if (local[9]==NIL) goto CON83562;
	local[13]= argv[0];
	local[14]= fqv[71];
	local[15]= local[9];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= w;
	goto CON83382;
CON83562:
	local[13]= NIL;
CON83382:
	if (local[11]==NIL) goto IF83575;
	local[13]= argv[0];
	local[14]= fqv[2];
	local[15]= local[11];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= w;
	goto IF83576;
IF83575:
	local[13]= NIL;
IF83576:
	local[13]= NIL;
	local[14]= local[12];
WHL83605:
	if (local[14]==NIL) goto WHX83606;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14] = (w)->c.cons.cdr;
	w = local[15];
	local[13] = w;
	local[15]= argv[0];
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17]= (w)->c.cons.car;
	ctx->vsp=local+18;
	w=(pointer)PUTPROP(ctx,3,local+15); /*putprop*/
	goto WHL83605;
WHX83606:
	local[15]= NIL;
BLK83607:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK83253:
	ctx->vsp=local; return(local[0]);}

/*:parent*/
static pointer M83718cascaded_coords_parent(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK83719:
	ctx->vsp=local; return(local[0]);}

/*:descendants*/
static pointer M83734cascaded_coords_descendants(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK83735:
	ctx->vsp=local; return(local[0]);}

/*:inheritance*/
static pointer M83750cascaded_coords_inheritance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO83764,env,argv,local);
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	local[0]= w;
BLK83751:
	ctx->vsp=local; return(local[0]);}

/*:leaves*/
static pointer M83770cascaded_coords_leaves(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[4]==NIL) goto IF83783;
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= fqv[72];
	ctx->vsp=local+2;
	w=(*ftab[12])(ctx,2,local+0,&ftab[12],fqv[73]); /*send-all*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[13])(ctx,1,local+0,&ftab[13],fqv[74]); /*flatten*/
	local[0]= w;
	goto IF83784;
IF83783:
	local[0]= argv[0];
IF83784:
	w = local[0];
	local[0]= w;
BLK83771:
	ctx->vsp=local; return(local[0]);}

/*:assoc*/
static pointer M83800cascaded_coords_assoc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT83804;}
	local[0]= NIL;
ENT83804:
ENT83803:
	if (n>4) maerror();
	local[1]= argv[2];
	w = argv[0]->c.obj.iv[4];
	if (memq(local[1],w)!=NIL) goto IF83823;
	if (local[0]!=NIL) goto IF83837;
	local[1]= argv[0];
	local[2]= fqv[18];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[75];
	local[3]= argv[2];
	local[4]= fqv[18];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0] = w;
	local[1]= local[0];
	goto IF83838;
IF83837:
	local[1]= NIL;
IF83838:
	local[1]= argv[2];
	local[2]= fqv[76];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[2];
	local[2]= fqv[16];
	local[3]= local[0]->c.obj.iv[1];
	local[4]= local[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= argv[2];
	w = argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[4] = cons(ctx,local[1],w);
	local[1]= argv[2];
	goto IF83824;
IF83823:
	local[1]= NIL;
IF83824:
	w = local[1];
	local[0]= w;
BLK83801:
	ctx->vsp=local; return(local[0]);}

/*:dissoc*/
static pointer M83903cascaded_coords_dissoc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	w = argv[0]->c.obj.iv[4];
	if (memq(local[0],w)==NIL) goto IF83919;
	local[0]= argv[2];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[77];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+3;
	w=(*ftab[14])(ctx,2,local+1,&ftab[14],fqv[78]); /*delete*/
	argv[0]->c.obj.iv[4] = w;
	local[1]= argv[2];
	local[2]= fqv[79];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[2];
	local[2]= fqv[16];
	local[3]= local[0]->c.obj.iv[1];
	local[4]= local[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = argv[2];
	local[0]= w;
	goto IF83920;
IF83919:
	local[0]= NIL;
IF83920:
	w = local[0];
	local[0]= w;
BLK83904:
	ctx->vsp=local; return(local[0]);}

/*:clear-assoc*/
static pointer M83989cascaded_coords_clear_assoc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[4];
WHL84019:
	if (local[1]==NIL) goto WHX84020;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0];
	local[3]= fqv[80];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	goto WHL84019;
WHX84020:
	local[2]= NIL;
BLK84021:
	w = NIL;
	w = NIL;
	local[0]= w;
BLK83990:
	ctx->vsp=local; return(local[0]);}

/*:obey*/
static pointer M84080cascaded_coords_obey(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[0]->c.obj.iv[3]==NIL) goto IF84095;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[80];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF84096;
IF84095:
	local[0]= NIL;
IF84096:
	argv[0]->c.obj.iv[3] = argv[2];
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK84081:
	ctx->vsp=local; return(local[0]);}

/*:disobey*/
static pointer M84117cascaded_coords_disobey(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[3]!=local[0]) goto IF84132;
	argv[0]->c.obj.iv[3] = NIL;
	local[0]= argv[0]->c.obj.iv[3];
	goto IF84133;
IF84132:
	local[0]= NIL;
IF84133:
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK84118:
	ctx->vsp=local; return(local[0]);}

/*:newcoords*/
static pointer M84148cascaded_coords_newcoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT84152;}
	local[0]= NIL;
ENT84152:
ENT84151:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[60]));
	local[3]= fqv[16];
	local[4]= argv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	local[1]= argv[0];
	local[2]= fqv[12];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = argv[0];
	local[0]= w;
BLK84149:
	ctx->vsp=local; return(local[0]);}

/*:changed*/
static pointer M84190cascaded_coords_changed(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[7]!=NIL) goto IF84204;
	argv[0]->c.obj.iv[7] = T;
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= fqv[12];
	ctx->vsp=local+2;
	w=(*ftab[12])(ctx,2,local+0,&ftab[12],fqv[73]); /*send-all*/
	local[0]= w;
	goto IF84205;
IF84204:
	local[0]= NIL;
IF84205:
	w = local[0];
	local[0]= w;
BLK84191:
	ctx->vsp=local; return(local[0]);}

/*:worldrot*/
static pointer M84226cascaded_coords_worldrot(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = w->c.obj.iv[1];
	local[0]= w;
BLK84227:
	ctx->vsp=local; return(local[0]);}

/*:worldpos*/
static pointer M84250cascaded_coords_worldpos(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = w->c.obj.iv[2];
	local[0]= w;
BLK84251:
	ctx->vsp=local; return(local[0]);}

/*:worldcoords*/
static pointer M84274cascaded_coords_worldcoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[7]==NIL) goto IF84288;
	if (argv[0]->c.obj.iv[3]==NIL) goto IF84297;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+3;
	w=(pointer)F80505transform_coords(ctx,3,local+0); /*transform-coords*/
	local[0]= w;
	goto IF84298;
IF84297:
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= fqv[69];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
IF84298:
	local[0]= argv[0];
	local[1]= fqv[81];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[7] = NIL;
	local[0]= argv[0]->c.obj.iv[7];
	goto IF84289;
IF84288:
	local[0]= NIL;
IF84289:
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK84275:
	ctx->vsp=local; return(local[0]);}

/*:copy-worldcoords*/
static pointer M84335cascaded_coords_copy_worldcoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT84339;}
	local[0]= loadglobal(fqv[0]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[6];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = local[0];
	local[0]= w;
ENT84339:
ENT84338:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[18];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= local[0]->c.obj.iv[2];
	local[2]= argv[0]->c.obj.iv[5]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[4]); /*replace*/
	local[1]= local[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[5]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[3]); /*replace-matrix*/
	w = local[0];
	local[0]= w;
BLK84336:
	ctx->vsp=local; return(local[0]);}

/*:update*/
static pointer M84417cascaded_coords_update(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = NIL;
	local[0]= w;
BLK84418:
	ctx->vsp=local; return(local[0]);}

/*:parentcoords*/
static pointer M84431cascaded_coords_parentcoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[3]==NIL) goto IF84444;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF84445;
IF84444:
	local[0]= argv[0];
	local[1]= fqv[82];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	if (fqv[83]!=local[1]) goto IF84472;
	local[1]= loadglobal(fqv[8]);
	goto IF84473;
IF84472:
	local[1]= local[0];
	if (fqv[84]!=local[1]) goto IF84482;
	local[1]= loadglobal(fqv[85]);
	goto IF84483;
IF84482:
	if (T==NIL) goto IF84492;
	local[1]= fqv[86];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF84493;
IF84492:
	local[1]= NIL;
IF84493:
IF84483:
IF84473:
	w = local[1];
	local[0]= w;
IF84445:
	w = local[0];
	local[0]= w;
BLK84432:
	ctx->vsp=local; return(local[0]);}

/*:transform-vector*/
static pointer M84501cascaded_coords_transform_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[47];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK84502:
	ctx->vsp=local; return(local[0]);}

/*:rotate-vector*/
static pointer M84527cascaded_coords_rotate_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[87];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK84528:
	ctx->vsp=local; return(local[0]);}

/*:inverse-transform-vector*/
static pointer M84553cascaded_coords_inverse_transform_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[88];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK84554:
	ctx->vsp=local; return(local[0]);}

/*:inverse-transformation*/
static pointer M84579cascaded_coords_inverse_transformation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT84583;}
	local[0]= loadglobal(fqv[0]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[6];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = local[0];
	local[0]= w;
ENT84583:
ENT84582:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[18];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[20];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK84580:
	ctx->vsp=local; return(local[0]);}

/*:transformation*/
static pointer M84634cascaded_coords_transformation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT84638;}
	local[0]= fqv[13];
ENT84638:
ENT84637:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= fqv[18];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[18];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[20];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= local[0];
	w = fqv[89];
	if (memq(local[6],w)!=NIL) goto OR84692;
	local[6]= local[0];
	if (argv[0]==local[6]) goto OR84692;
	goto CON84691;
OR84692:
	local[6]= local[3];
	local[7]= local[1];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)F80505transform_coords(ctx,3,local+6); /*transform-coords*/
	local[6]= w;
	goto CON84689;
CON84691:
	local[6]= local[0];
	w = fqv[90];
	if (memq(local[6],w)!=NIL) goto OR84713;
	local[6]= local[0];
	if (argv[0]->c.obj.iv[3]==local[6]) goto OR84713;
	goto CON84712;
OR84713:
	local[6]= argv[0];
	local[7]= *(ovafptr(argv[1],fqv[60]));
	local[8]= fqv[20];
	ctx->vsp=local+9;
	w=(pointer)SENDMESSAGE(ctx,3,local+6); /*send-message*/
	local[4] = w;
	local[6]= local[1];
	local[7]= local[4];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)F80505transform_coords(ctx,3,local+6); /*transform-coords*/
	local[6]= local[3];
	local[7]= local[4];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)F80505transform_coords(ctx,3,local+6); /*transform-coords*/
	local[6]= argv[0];
	local[7]= local[4];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)F80505transform_coords(ctx,3,local+6); /*transform-coords*/
	local[6]= w;
	goto CON84689;
CON84712:
	local[6]= local[0];
	w = fqv[91];
	if (memq(local[6],w)!=NIL) goto OR84760;
	local[6]= local[0];
	local[7]= loadglobal(fqv[8]);
	ctx->vsp=local+8;
	w=(pointer)EQUAL(ctx,2,local+6); /*equal*/
	if (w!=NIL) goto OR84760;
	goto CON84759;
OR84760:
	local[6]= local[1];
	local[7]= local[3];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)F80505transform_coords(ctx,3,local+6); /*transform-coords*/
	local[6]= w;
	goto CON84689;
CON84759:
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)F80485coordinates_p(ctx,1,local+6); /*coordinates-p*/
	if (w==NIL) goto CON84783;
	local[6]= local[0];
	local[7]= fqv[18];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[5] = w;
	local[6]= local[3];
	local[7]= local[5];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)F80505transform_coords(ctx,3,local+6); /*transform-coords*/
	local[6]= local[1];
	local[7]= local[3];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)F80505transform_coords(ctx,3,local+6); /*transform-coords*/
	local[6]= local[5];
	local[7]= fqv[20];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= local[3];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)F80505transform_coords(ctx,3,local+6); /*transform-coords*/
	local[6]= w;
	goto CON84689;
CON84783:
	local[6]= argv[0];
	local[7]= fqv[23];
	local[8]= fqv[92];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[6]= w;
	goto CON84689;
CON84822:
	local[6]= NIL;
CON84689:
	w = local[6];
	local[0]= w;
BLK84635:
	ctx->vsp=local; return(local[0]);}

/*:transform*/
static pointer M84834cascaded_coords_transform(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT84838;}
	local[0]= fqv[13];
ENT84838:
ENT84837:
	if (n>4) maerror();
	local[1]= local[0];
	w = fqv[93];
	if (memq(local[1],w)!=NIL) goto OR84861;
	local[1]= local[0];
	if (argv[0]==local[1]) goto OR84861;
	goto CON84860;
OR84861:
	local[1]= argv[0];
	local[2]= argv[2];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F80505transform_coords(ctx,3,local+1); /*transform-coords*/
	local[1]= w;
	goto CON84858;
CON84860:
	local[1]= local[0];
	w = fqv[94];
	if (memq(local[1],w)!=NIL) goto OR84882;
	local[1]= local[0];
	if (argv[0]->c.obj.iv[3]==local[1]) goto OR84882;
	goto CON84881;
OR84882:
	local[1]= argv[2];
	local[2]= argv[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F80505transform_coords(ctx,3,local+1); /*transform-coords*/
	local[1]= w;
	goto CON84858;
CON84881:
	local[1]= local[0];
	w = fqv[95];
	if (memq(local[1],w)!=NIL) goto OR84903;
	local[1]= local[0];
	local[2]= loadglobal(fqv[8]);
	ctx->vsp=local+3;
	w=(pointer)EQUAL(ctx,2,local+1); /*equal*/
	if (w!=NIL) goto OR84903;
	goto CON84902;
OR84903:
	local[1]= argv[0];
	local[2]= fqv[19];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= local[1];
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F80505transform_coords(ctx,3,local+2); /*transform-coords*/
	local[2]= argv[2];
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F80505transform_coords(ctx,3,local+2); /*transform-coords*/
	local[2]= local[1];
	local[3]= fqv[20];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F80505transform_coords(ctx,3,local+2); /*transform-coords*/
	local[1]= w;
	goto CON84858;
CON84902:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F80485coordinates_p(ctx,1,local+1); /*coordinates-p*/
	if (w==NIL) goto CON84958;
	local[1]= argv[0];
	local[2]= fqv[19];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= local[1];
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F80505transform_coords(ctx,3,local+2); /*transform-coords*/
	local[2]= local[0];
	local[3]= fqv[20];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F80505transform_coords(ctx,3,local+2); /*transform-coords*/
	local[2]= argv[2];
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F80505transform_coords(ctx,3,local+2); /*transform-coords*/
	local[2]= local[0];
	local[3]= fqv[18];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F80505transform_coords(ctx,3,local+2); /*transform-coords*/
	local[2]= local[1];
	local[3]= fqv[20];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F80505transform_coords(ctx,3,local+2); /*transform-coords*/
	local[1]= w;
	goto CON84858;
CON84958:
	local[1]= argv[0];
	local[2]= fqv[23];
	local[3]= fqv[96];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON84858;
CON85022:
	local[1]= NIL;
CON84858:
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK84835:
	ctx->vsp=local; return(local[0]);}

/*:move-to*/
static pointer M85041cascaded_coords_move_to(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT85045;}
	local[0]= fqv[13];
ENT85045:
ENT85044:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)F80485coordinates_p(ctx,1,local+3); /*coordinates-p*/
	if (w!=NIL) goto IF85070;
	local[3]= fqv[97];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
	goto IF85071;
IF85070:
	local[3]= NIL;
IF85071:
	local[3]= local[0];
	w = fqv[98];
	if (memq(local[3],w)!=NIL) goto OR85087;
	local[3]= local[0];
	if (argv[0]==local[3]) goto OR85087;
	goto CON85086;
OR85087:
	local[3]= argv[0];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)F80505transform_coords(ctx,2,local+3); /*transform-coords*/
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto CON85084;
CON85086:
	local[3]= local[0];
	w = fqv[99];
	if (memq(local[3],w)!=NIL) goto OR85119;
	local[3]= local[0];
	if (argv[0]->c.obj.iv[3]==local[3]) goto OR85119;
	goto CON85118;
OR85119:
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto CON85084;
CON85118:
	local[3]= local[0];
	w = fqv[100];
	if (memq(local[3],w)!=NIL) goto OR85141;
	local[3]= local[0];
	local[4]= loadglobal(fqv[8]);
	ctx->vsp=local+5;
	w=(pointer)EQUAL(ctx,2,local+3); /*equal*/
	if (w!=NIL) goto OR85141;
	goto CON85140;
OR85141:
	local[3]= argv[0];
	local[4]= fqv[19];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= fqv[20];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)F80505transform_coords(ctx,2,local+3); /*transform-coords*/
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto CON85084;
CON85140:
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F80485coordinates_p(ctx,1,local+3); /*coordinates-p*/
	if (w==NIL) goto CON85183;
	local[3]= local[0];
	local[4]= fqv[18];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)F80505transform_coords(ctx,2,local+3); /*transform-coords*/
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[19];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= fqv[20];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= local[2];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)F80505transform_coords(ctx,3,local+3); /*transform-coords*/
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto CON85084;
CON85183:
	local[3]= NIL;
CON85084:
	w = local[3];
	local[0]= w;
BLK85042:
	ctx->vsp=local; return(local[0]);}

/*:rotate-with-matrix*/
static pointer M85226cascaded_coords_rotate_with_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	w = fqv[101];
	if (memq(local[0],w)!=NIL) goto OR85246;
	local[0]= argv[3];
	if (argv[0]==local[0]) goto OR85246;
	goto CON85245;
OR85246:
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)MATTIMES(ctx,3,local+0); /*m**/
	local[0]= argv[0];
	local[1]= fqv[16];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON85243;
CON85245:
	local[0]= argv[3];
	w = fqv[102];
	if (memq(local[0],w)!=NIL) goto OR85275;
	local[0]= argv[3];
	if (argv[0]->c.obj.iv[3]==local[0]) goto OR85275;
	goto CON85274;
OR85275:
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)MATTIMES(ctx,3,local+0); /*m**/
	local[0]= argv[0];
	local[1]= fqv[16];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON85243;
CON85274:
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[19];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= local[1]->c.obj.iv[1];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)F80485coordinates_p(ctx,1,local+3); /*coordinates-p*/
	if (w==NIL) goto IF85330;
	local[3]= argv[3];
	local[4]= fqv[30];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[0] = w;
	local[3]= local[0];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)MATTIMES(ctx,2,local+3); /*m**/
	argv[2] = w;
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)TRANSPOSE(ctx,1,local+4); /*transpose*/
	local[4]= w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)MATTIMES(ctx,3,local+3); /*m**/
	local[3]= w;
	goto IF85331;
IF85330:
	local[3]= NIL;
IF85331:
	local[3]= argv[2];
	local[4]= local[2];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)MATTIMES(ctx,3,local+3); /*m**/
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)TRANSPOSE(ctx,1,local+3); /*transpose*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)MATTIMES(ctx,3,local+3); /*m**/
	local[3]= argv[2];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)MATTIMES(ctx,3,local+3); /*m**/
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[0]= w;
	goto CON85243;
CON85303:
	local[0]= NIL;
CON85243:
	w = local[0];
	local[0]= w;
BLK85227:
	ctx->vsp=local; return(local[0]);}

/*:rotate*/
static pointer M85399cascaded_coords_rotate(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT85403;}
	local[0]= fqv[13];
ENT85403:
ENT85402:
	if (n>5) maerror();
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	if (makeint(2)!=local[1]) goto CON85427;
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[60]));
	local[3]= fqv[70];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	local[1]= w;
	goto CON85425;
CON85427:
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,1,local+1,&ftab[7],fqv[34]); /*float-vector-p*/
	if (w==NIL) goto CON85444;
	local[1]= argv[0];
	local[2]= fqv[35];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+3); /*rotation-matrix*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON85425;
CON85444:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[32]); /*matrixp*/
	if (w==NIL) goto CON85461;
	local[1]= argv[0];
	local[2]= fqv[35];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON85425;
CON85461:
	local[1]= local[0];
	w = fqv[103];
	if (memq(local[1],w)!=NIL) goto OR85482;
	local[1]= local[0];
	if (argv[0]==local[1]) goto OR85482;
	goto CON85481;
OR85482:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= NIL;
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)ROTMAT(ctx,5,local+1); /*rotate-matrix*/
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON85479;
CON85481:
	local[1]= local[0];
	w = fqv[104];
	if (memq(local[1],w)!=NIL) goto OR85512;
	local[1]= local[0];
	if (argv[0]->c.obj.iv[3]==local[1]) goto OR85512;
	goto CON85511;
OR85512:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= T;
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)ROTMAT(ctx,5,local+1); /*rotate-matrix*/
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON85479;
CON85511:
	local[1]= argv[0];
	local[2]= fqv[35];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+3); /*rotation-matrix*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON85479;
CON85541:
	local[1]= NIL;
CON85479:
	goto CON85425;
CON85475:
	local[1]= NIL;
CON85425:
	w = local[1];
	local[0]= w;
BLK85400:
	ctx->vsp=local; return(local[0]);}

/*:orient-with-matrix*/
static pointer M85556cascaded_coords_orient_with_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	w = fqv[105];
	if (memq(local[0],w)!=NIL) goto OR85576;
	local[0]= argv[3];
	if (argv[0]==local[0]) goto OR85576;
	goto CON85575;
OR85576:
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)MATTIMES(ctx,3,local+0); /*m**/
	local[0]= argv[0];
	local[1]= fqv[16];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON85573;
CON85575:
	local[0]= argv[3];
	w = fqv[106];
	if (memq(local[0],w)!=NIL) goto OR85605;
	local[0]= argv[3];
	if (argv[0]->c.obj.iv[3]==local[0]) goto OR85605;
	goto CON85604;
OR85605:
	argv[0]->c.obj.iv[1] = argv[2];
	local[0]= argv[0];
	local[1]= fqv[16];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON85573;
CON85604:
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[19];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= local[1]->c.obj.iv[1];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)F80485coordinates_p(ctx,1,local+3); /*coordinates-p*/
	if (w==NIL) goto IF85662;
	local[3]= argv[3];
	local[4]= fqv[30];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[0] = w;
	local[3]= local[0];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)MATTIMES(ctx,2,local+3); /*m**/
	argv[2] = w;
	local[3]= argv[2];
	goto IF85663;
IF85662:
	local[3]= NIL;
IF85663:
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)TRANSPOSE(ctx,1,local+3); /*transpose*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)MATTIMES(ctx,3,local+3); /*m**/
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[0]= w;
	goto CON85573;
CON85635:
	local[0]= NIL;
CON85573:
	w = local[0];
	local[0]= w;
BLK85557:
	ctx->vsp=local; return(local[0]);}

/*:orient*/
static pointer M85713cascaded_coords_orient(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT85717;}
	local[0]= fqv[13];
ENT85717:
ENT85716:
	if (n>5) maerror();
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,1,local+1,&ftab[7],fqv[34]); /*float-vector-p*/
	if (w==NIL) goto CON85741;
	local[1]= argv[0];
	local[2]= fqv[42];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+3); /*rotation-matrix*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON85739;
CON85741:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[32]); /*matrixp*/
	if (w==NIL) goto CON85758;
	local[1]= argv[0];
	local[2]= fqv[42];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON85739;
CON85758:
	local[1]= local[0];
	w = fqv[107];
	if (memq(local[1],w)!=NIL) goto OR85779;
	local[1]= local[0];
	if (argv[0]==local[1]) goto OR85779;
	goto CON85778;
OR85779:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= NIL;
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)ROTMAT(ctx,5,local+1); /*rotate-matrix*/
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON85776;
CON85778:
	local[1]= local[0];
	w = fqv[108];
	if (memq(local[1],w)!=NIL) goto OR85809;
	local[1]= local[0];
	if (argv[0]->c.obj.iv[3]==local[1]) goto OR85809;
	goto CON85808;
OR85809:
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+1); /*rotation-matrix*/
	argv[0]->c.obj.iv[1] = w;
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON85776;
CON85808:
	local[1]= argv[0];
	local[2]= fqv[42];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+3); /*rotation-matrix*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON85776;
CON85842:
	local[1]= NIL;
CON85776:
	goto CON85739;
CON85772:
	local[1]= NIL;
CON85739:
	w = local[1];
	local[0]= w;
BLK85714:
	ctx->vsp=local; return(local[0]);}

/*:parent-vector*/
static pointer M85857cascaded_coords_parent_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	w = fqv[109];
	if (memq(local[0],w)!=NIL) goto OR85877;
	local[0]= argv[3];
	if (argv[0]==local[0]) goto OR85877;
	goto CON85876;
OR85877:
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[60]));
	local[2]= fqv[47];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SENDMESSAGE(ctx,4,local+0); /*send-message*/
	local[0]= w;
	goto CON85874;
CON85876:
	local[0]= argv[3];
	w = fqv[110];
	if (memq(local[0],w)!=NIL) goto OR85902;
	local[0]= argv[3];
	if (argv[0]->c.obj.iv[3]==local[0]) goto OR85902;
	goto CON85901;
OR85902:
	local[0]= argv[2];
	goto CON85874;
CON85901:
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)F80485coordinates_p(ctx,1,local+0); /*coordinates-p*/
	if (w==NIL) goto IF85922;
	local[0]= argv[3];
	local[1]= fqv[47];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	argv[2] = w;
	local[0]= argv[2];
	goto IF85923;
IF85922:
	local[0]= NIL;
IF85923:
	if (argv[0]->c.obj.iv[3]==NIL) goto IF85942;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[88];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF85943;
IF85942:
	local[0]= argv[2];
IF85943:
	goto CON85874;
CON85918:
	local[0]= NIL;
CON85874:
	w = local[0];
	local[0]= w;
BLK85858:
	ctx->vsp=local; return(local[0]);}

/*:parent-orientation*/
static pointer M85956cascaded_coords_parent_orientation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	w = fqv[111];
	if (memq(local[0],w)!=NIL) goto OR85976;
	local[0]= argv[3];
	if (argv[0]==local[0]) goto OR85976;
	goto CON85975;
OR85976:
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
	goto CON85973;
CON85975:
	local[0]= argv[3];
	w = fqv[112];
	if (memq(local[0],w)!=NIL) goto OR85996;
	local[0]= argv[3];
	if (argv[0]->c.obj.iv[3]==local[0]) goto OR85996;
	goto CON85995;
OR85996:
	local[0]= argv[2];
	goto CON85973;
CON85995:
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)F80485coordinates_p(ctx,1,local+0); /*coordinates-p*/
	if (w==NIL) goto IF86016;
	local[0]= argv[3];
	local[1]= fqv[30];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	argv[2] = w;
	local[0]= argv[2];
	goto IF86017;
IF86016:
	local[0]= NIL;
IF86017:
	if (argv[0]->c.obj.iv[3]==NIL) goto IF86038;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[30];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)TRANSPOSE(ctx,1,local+0); /*transpose*/
	local[0]= w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
	goto IF86039;
IF86038:
	local[0]= argv[2];
IF86039:
	goto CON85973;
CON86012:
	local[0]= NIL;
CON85973:
	w = local[0];
	local[0]= w;
BLK85957:
	ctx->vsp=local; return(local[0]);}

/*:manager*/
static pointer M86056cascaded_coords_manager(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT86060;}
	local[0]= NIL;
ENT86060:
ENT86059:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF86076;
	argv[0]->c.obj.iv[6] = local[0];
	local[1]= argv[0]->c.obj.iv[6];
	goto IF86077;
IF86076:
	local[1]= NIL;
IF86077:
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK86057:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M86092cascaded_coords_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST86095:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[113], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY86108;
	local[1] = NIL;
KEY86108:
	if (n & (1<<1)) goto KEY86113;
	local[2] = NIL;
KEY86113:
	local[3]= (pointer)get_sym_func(fqv[114]);
	local[4]= argv[0];
	local[5]= *(ovafptr(argv[1],fqv[60]));
	local[6]= fqv[115];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,5,local+3); /*apply*/
	argv[0]->c.obj.iv[6] = argv[0];
	argv[0]->c.obj.iv[7] = T;
	local[3]= loadglobal(fqv[0]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[115];
	local[6]= fqv[116];
	local[7]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+8;
	w=(*ftab[3])(ctx,1,local+7,&ftab[3],fqv[5]); /*copy-matrix*/
	local[7]= w;
	local[8]= fqv[117];
	local[9]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+10;
	w=(pointer)COPYSEQ(ctx,1,local+9); /*copy-seq*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,6,local+4); /*send*/
	w = local[3];
	argv[0]->c.obj.iv[5] = w;
	if (local[1]==NIL) goto IF86191;
	local[3]= local[1];
	local[4]= fqv[118];
	local[5]= argv[0];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF86192;
IF86191:
	local[3]= NIL;
IF86192:
	w = argv[0];
	local[0]= w;
BLK86093:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO83764(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= argv[0];
	local[2]= fqv[119];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*transform-coords*/
static pointer F80505transform_coords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT86231;}
	local[0]= argv[0];
	local[1]= fqv[82];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= loadglobal(fqv[0]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[16];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[5])(ctx,1,local+4,&ftab[5],fqv[10]); /*unit-matrix*/
	local[4]= w;
	local[5]= loadglobal(fqv[11]);
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,2,local+5); /*instantiate*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[0]= w;
ENT86231:
ENT86230:
	if (n>3) maerror();
	local[1]= argv[0];
	if (local[0]!=local[1]) goto IF86294;
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
	goto IF86295;
IF86294:
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
IF86295:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[1]->c.obj.iv[1];
	local[3]= local[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)MATTIMES(ctx,3,local+1); /*m**/
	w = local[0];
	local[0]= w;
BLK86228:
	ctx->vsp=local; return(local[0]);}

/*transform-coords**/
static pointer F80507transform_coords_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST86378:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)F80505transform_coords(ctx,2,local+3); /*transform-coords*/
	local[2] = w;
	local[3]= NIL;
	local[4]= local[0];
WHL86422:
	if (local[4]==NIL) goto WHX86423;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[2];
	local[6]= local[3];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)F80505transform_coords(ctx,3,local+5); /*transform-coords*/
	goto WHL86422;
WHX86423:
	local[5]= NIL;
BLK86424:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK86376:
	ctx->vsp=local; return(local[0]);}

/*transform-vector*/
static pointer F80509transform_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)VPLUS(ctx,2,local+0); /*v+*/
	local[0]= w;
BLK86483:
	ctx->vsp=local; return(local[0]);}

/*make-coords*/
static pointer F80511make_coords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST86519:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= (pointer)get_sym_func(fqv[120]);
	local[2]= loadglobal(fqv[0]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= fqv[115];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[0]= w;
BLK86517:
	ctx->vsp=local; return(local[0]);}

/*make-cascoords*/
static pointer F80513make_cascoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST86542:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= (pointer)get_sym_func(fqv[120]);
	local[2]= loadglobal(fqv[121]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= fqv[115];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[0]= w;
BLK86540:
	ctx->vsp=local; return(local[0]);}

/*coords*/
static pointer F80515coords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST86566:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= (pointer)get_sym_func(fqv[120]);
	local[2]= loadglobal(fqv[0]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= fqv[115];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[0]= w;
BLK86564:
	ctx->vsp=local; return(local[0]);}

/*cascoords*/
static pointer F80517cascoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST86589:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= (pointer)get_sym_func(fqv[120]);
	local[2]= loadglobal(fqv[121]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= fqv[115];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[0]= w;
BLK86587:
	ctx->vsp=local; return(local[0]);}

/*wrt*/
static pointer F80519wrt(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[47];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK86610:
	ctx->vsp=local; return(local[0]);}

/*coordinates-distance*/
static pointer F80524coordinates_distance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[75];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[59];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VNORM(ctx,1,local+2); /*norm*/
	local[2]= w;
	local[3]= local[1];
	local[4]= fqv[30];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ROTANGLE(ctx,1,local+3); /*rotation-angle*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[0]= w;
BLK86634:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___coordinates(ctx,n,argv,env)
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
	local[0]= fqv[122];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w!=NIL) goto IF86682;
	local[0]= fqv[123];
	local[1]= fqv[124];
	local[2]= fqv[125];
	ctx->vsp=local+3;
	w=(*ftab[15])(ctx,3,local+0,&ftab[15],fqv[126]); /*make-package*/
	local[0]= fqv[127];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF86701;
	local[0]= fqv[128];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[129],w);
	goto IF86702;
IF86701:
	local[0]= fqv[130];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF86702:
	local[0]= fqv[131];
	ctx->vsp=local+1;
	w=(*ftab[16])(ctx,1,local+0,&ftab[16],fqv[132]); /*use-package*/
	local[0]= w;
	goto IF86683;
IF86682:
	local[0]= NIL;
IF86683:
	local[0]= fqv[133];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF86723;
	local[0]= fqv[134];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[129],w);
	goto IF86724;
IF86723:
	local[0]= fqv[135];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF86724:
	local[0]= fqv[136];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[137];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[138];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[139];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[140];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[0];
	local[1]= fqv[141];
	local[2]= fqv[0];
	local[3]= fqv[142];
	local[4]= loadglobal(fqv[143]);
	local[5]= fqv[144];
	local[6]= fqv[145];
	local[7]= fqv[146];
	local[8]= NIL;
	local[9]= fqv[147];
	local[10]= NIL;
	local[11]= fqv[148];
	local[12]= makeint(-1);
	local[13]= fqv[149];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[17])(ctx,13,local+2,&ftab[17],fqv[150]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[151],module,F80485coordinates_p,fqv[152]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80598coordinates_dimension,fqv[82],fqv[0],fqv[153]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80615coordinates_rot,fqv[116],fqv[0],fqv[154]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80631coordinates_pos,fqv[117],fqv[0],fqv[155]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80647coordinates_x_axis,fqv[156],fqv[0],fqv[157]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80665coordinates_y_axis,fqv[158],fqv[0],fqv[159]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80682coordinates_z_axis,fqv[160],fqv[0],fqv[161]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80699coordinates_name,fqv[2],fqv[0],fqv[162]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80739coordinates_newcoords,fqv[16],fqv[0],fqv[163]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80797coordinates_replace_rot,fqv[164],fqv[0],fqv[165]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80818coordinates_replace_pos,fqv[166],fqv[0],fqv[167]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80839coordinates_replace_coords,fqv[69],fqv[0],fqv[168]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80904coordinates_copy_rot,fqv[169],fqv[0],fqv[170]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80922coordinates_copy_pos,fqv[171],fqv[0],fqv[172]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M80939coordinates_copy_coords,fqv[77],fqv[0],fqv[173]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81007coordinates_coords,fqv[7],fqv[0],fqv[174]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81075coordinates_worldrot,fqv[30],fqv[0],fqv[175]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81091coordinates_worldpos,fqv[59],fqv[0],fqv[176]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81107coordinates_worldcoords,fqv[18],fqv[0],fqv[177]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81123coordinates_copy_worldcoords,fqv[178],fqv[0],fqv[179]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81142coordinates_parentcoords,fqv[19],fqv[0],fqv[180]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81159coordinates_changed,fqv[12],fqv[0],fqv[181]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81174coordinates_reset_coords,fqv[182],fqv[0],fqv[183]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81228coordinates_move_to,fqv[184],fqv[0],fqv[185]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81373coordinates_rotate_vector,fqv[87],fqv[0],fqv[186]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81393coordinates_transform_vector,fqv[47],fqv[0],fqv[187]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81416coordinates_inverse_transform_vector,fqv[88],fqv[0],fqv[188]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81456coordinates_inverse_transformation,fqv[20],fqv[0],fqv[189]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81542coordinates_transformation,fqv[75],fqv[0],fqv[190]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81698coordinates_transform,fqv[191],fqv[0],fqv[192]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81818coordinates_rotate_with_matrix,fqv[35],fqv[0],fqv[193]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81935coordinates_rotate,fqv[70],fqv[0],fqv[194]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82121coordinates_orient_with_matrix,fqv[42],fqv[0],fqv[195]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82221coordinates_orient,fqv[196],fqv[0],fqv[197]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82371coordinates_parent_vector,fqv[54],fqv[0],fqv[198]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82454coordinates_parent_orientation,fqv[53],fqv[0],fqv[199]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82537coordinates_translate,fqv[200],fqv[0],fqv[201]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82579coordinates_locate,fqv[202],fqv[0],fqv[203]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82620coordinates_scale,fqv[204],fqv[0],fqv[205]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82668coordinates_euler,fqv[67],fqv[0],fqv[206]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82700coordinates_euler_angle,fqv[207],fqv[0],fqv[208]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82717coordinates_rpy,fqv[68],fqv[0],fqv[209]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82749coordinates_rpy_angle,fqv[210],fqv[0],fqv[211]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82766coordinates_rotation_angle,fqv[212],fqv[0],fqv[213]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82783coordinates_4x4,fqv[71],fqv[0],fqv[214]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M83050coordinates_prin1,fqv[61],fqv[0],fqv[215]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M83214coordinates_create,fqv[6],fqv[0],fqv[216]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M83252coordinates_init,fqv[115],fqv[0],fqv[217]);
	local[0]= fqv[121];
	local[1]= fqv[141];
	local[2]= fqv[121];
	local[3]= fqv[142];
	local[4]= loadglobal(fqv[0]);
	local[5]= fqv[144];
	local[6]= fqv[218];
	local[7]= fqv[146];
	local[8]= NIL;
	local[9]= fqv[147];
	local[10]= NIL;
	local[11]= fqv[148];
	local[12]= makeint(-1);
	local[13]= fqv[149];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[17])(ctx,13,local+2,&ftab[17],fqv[150]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M83718cascaded_coords_parent,fqv[219],fqv[121],fqv[220]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M83734cascaded_coords_descendants,fqv[221],fqv[121],fqv[222]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M83750cascaded_coords_inheritance,fqv[119],fqv[121],fqv[223]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M83770cascaded_coords_leaves,fqv[72],fqv[121],fqv[224]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M83800cascaded_coords_assoc,fqv[118],fqv[121],fqv[225]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M83903cascaded_coords_dissoc,fqv[80],fqv[121],fqv[226]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M83989cascaded_coords_clear_assoc,fqv[227],fqv[121],fqv[228]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84080cascaded_coords_obey,fqv[76],fqv[121],fqv[229]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84117cascaded_coords_disobey,fqv[79],fqv[121],fqv[230]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84148cascaded_coords_newcoords,fqv[16],fqv[121],fqv[231]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84190cascaded_coords_changed,fqv[12],fqv[121],fqv[232]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84226cascaded_coords_worldrot,fqv[30],fqv[121],fqv[233]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84250cascaded_coords_worldpos,fqv[59],fqv[121],fqv[234]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84274cascaded_coords_worldcoords,fqv[18],fqv[121],fqv[235]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84335cascaded_coords_copy_worldcoords,fqv[178],fqv[121],fqv[236]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84417cascaded_coords_update,fqv[81],fqv[121],fqv[237]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84431cascaded_coords_parentcoords,fqv[19],fqv[121],fqv[238]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84501cascaded_coords_transform_vector,fqv[47],fqv[121],fqv[239]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84527cascaded_coords_rotate_vector,fqv[87],fqv[121],fqv[240]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84553cascaded_coords_inverse_transform_vector,fqv[88],fqv[121],fqv[241]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84579cascaded_coords_inverse_transformation,fqv[20],fqv[121],fqv[242]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84634cascaded_coords_transformation,fqv[75],fqv[121],fqv[243]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84834cascaded_coords_transform,fqv[191],fqv[121],fqv[244]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M85041cascaded_coords_move_to,fqv[184],fqv[121],fqv[245]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M85226cascaded_coords_rotate_with_matrix,fqv[35],fqv[121],fqv[246]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M85399cascaded_coords_rotate,fqv[70],fqv[121],fqv[247]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M85556cascaded_coords_orient_with_matrix,fqv[42],fqv[121],fqv[248]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M85713cascaded_coords_orient,fqv[196],fqv[121],fqv[249]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M85857cascaded_coords_parent_vector,fqv[54],fqv[121],fqv[250]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M85956cascaded_coords_parent_orientation,fqv[53],fqv[121],fqv[251]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M86056cascaded_coords_manager,fqv[252],fqv[121],fqv[253]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M86092cascaded_coords_init,fqv[115],fqv[121],fqv[254]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[255],module,F80505transform_coords,fqv[256]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[257],module,F80507transform_coords_,fqv[258]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[259],module,F80509transform_vector,fqv[260]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[261],module,F80511make_coords,fqv[262]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[263],module,F80513make_cascoords,fqv[264]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[265],module,F80515coords,fqv[266]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[267],module,F80517cascoords,fqv[268]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[269],module,F80519wrt,fqv[270]);
	local[0]= fqv[8];
	local[1]= fqv[271];
	local[2]= loadglobal(fqv[0]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[115];
	local[5]= fqv[2];
	local[6]= fqv[8];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	w = local[2];
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[85];
	local[1]= fqv[271];
	local[2]= loadglobal(fqv[0]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[115];
	local[5]= fqv[82];
	local[6]= makeint(2);
	local[7]= fqv[2];
	local[8]= fqv[85];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	w = local[2];
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[272],module,F80524coordinates_distance,fqv[273]);
	local[0]= fqv[274];
	local[1]= fqv[275];
	ctx->vsp=local+2;
	w=(*ftab[18])(ctx,2,local+0,&ftab[18],fqv[276]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<19; i++) ftab[i]=fcallx;
}
