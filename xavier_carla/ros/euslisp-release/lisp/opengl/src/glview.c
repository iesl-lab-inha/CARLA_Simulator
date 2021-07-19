/* ./glview.c :  entry=glview */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "glview.h"
#pragma init (register_glview)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___glview();
extern pointer build_quote_vector();
static int register_glview()
  { add_module_initializer("___glview", ___glview);}

static pointer F204geometry__default_viewsurface();
static pointer F205resetperspective();
static pointer F206gldraw();
static pointer F207swapb();
static pointer F208position_light();

/*:create*/
static pointer M209colormaterial_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[0], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY211;
	local[0] = NIL;
KEY211:
	if (n & (1<<1)) goto KEY212;
	local[8]= makeflt(3.00000000e-01);
	local[9]= makeflt(5.00000000e-01);
	local[10]= makeflt(7.00000000e-01);
	local[11]= makeint(1);
	ctx->vsp=local+12;
	w=(pointer)MKFLTVEC(ctx,4,local+8); /*float-vector*/
	local[1] = w;
KEY212:
	if (n & (1<<2)) goto KEY213;
	local[8]= makeflt(1.00000000e-01);
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,2,local+8); /*scale*/
	local[2] = w;
KEY213:
	if (n & (1<<3)) goto KEY214;
	local[8]= makeflt(1.00000000e+00);
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,2,local+8); /*scale*/
	local[3] = w;
KEY214:
	if (n & (1<<4)) goto KEY215;
	local[8]= makeflt(2.00000000e-01);
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,2,local+8); /*scale*/
	local[4] = w;
KEY215:
	if (n & (1<<5)) goto KEY216;
	local[8]= makeflt(1.00000000e-01);
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,2,local+8); /*scale*/
	local[5] = w;
KEY216:
	if (n & (1<<6)) goto KEY217;
	local[6] = makeflt(2.00000000e+01);
KEY217:
	if (n & (1<<7)) goto KEY218;
	local[7] = makeflt(0.00000000e+00);
KEY218:
	if (local[0]==NIL) goto IF219;
	local[8]= argv[0];
	local[9]= fqv[1];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	goto IF220;
IF219:
	local[8]= NIL;
IF220:
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)COPYSEQ(ctx,1,local+8); /*copy-seq*/
	argv[0]->c.obj.iv[2] = w;
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)COPYSEQ(ctx,1,local+8); /*copy-seq*/
	argv[0]->c.obj.iv[3] = w;
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)COPYSEQ(ctx,1,local+8); /*copy-seq*/
	argv[0]->c.obj.iv[4] = w;
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)COPYSEQ(ctx,1,local+8); /*copy-seq*/
	argv[0]->c.obj.iv[5] = w;
	argv[0]->c.obj.iv[6] = local[6];
	argv[0]->c.obj.iv[7] = local[7];
	w = argv[0];
	local[0]= w;
BLK210:
	ctx->vsp=local; return(local[0]);}

/*:ambient*/
static pointer M221colormaterial_ambient(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT227;}
	local[0]= NIL;
ENT227:
	if (n>=4) { local[1]=(argv[3]); goto ENT226;}
	local[1]= local[0];
ENT226:
	if (n>=5) { local[2]=(argv[4]); goto ENT225;}
	local[2]= local[0];
ENT225:
	if (n>=6) { local[3]=(argv[5]); goto ENT224;}
	local[3]= makeint(1);
ENT224:
ENT223:
	if (n>6) maerror();
	if (local[0]!=NIL) goto CON229;
	local[4]= argv[0]->c.obj.iv[2];
	goto CON228;
CON229:
	w = local[0];
	if (!isnum(w)) goto CON230;
	local[4]= local[0];
	local[5]= local[1];
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,4,local+4); /*float-vector*/
	argv[0]->c.obj.iv[2] = w;
	local[4]= argv[0]->c.obj.iv[2];
	goto CON228;
CON230:
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,1,local+4,&ftab[0],fqv[2]); /*float-vector-p*/
	if (w==NIL) goto CON231;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)COPYSEQ(ctx,1,local+4); /*copy-seq*/
	argv[0]->c.obj.iv[2] = w;
	local[4]= argv[0]->c.obj.iv[2];
	goto CON228;
CON231:
	local[4]= fqv[3];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,1,local+4); /*error*/
	local[4]= w;
	goto CON228;
CON232:
	local[4]= NIL;
CON228:
	w = local[4];
	local[0]= w;
BLK222:
	ctx->vsp=local; return(local[0]);}

/*:diffuse*/
static pointer M233colormaterial_diffuse(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT239;}
	local[0]= NIL;
ENT239:
	if (n>=4) { local[1]=(argv[3]); goto ENT238;}
	local[1]= local[0];
ENT238:
	if (n>=5) { local[2]=(argv[4]); goto ENT237;}
	local[2]= local[0];
ENT237:
	if (n>=6) { local[3]=(argv[5]); goto ENT236;}
	local[3]= makeint(1);
ENT236:
ENT235:
	if (n>6) maerror();
	if (local[0]!=NIL) goto CON241;
	local[4]= argv[0]->c.obj.iv[3];
	goto CON240;
CON241:
	w = local[0];
	if (!isnum(w)) goto CON242;
	local[4]= local[0];
	local[5]= local[1];
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,4,local+4); /*float-vector*/
	argv[0]->c.obj.iv[3] = w;
	local[4]= argv[0]->c.obj.iv[3];
	goto CON240;
CON242:
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,1,local+4,&ftab[0],fqv[2]); /*float-vector-p*/
	if (w==NIL) goto CON243;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)COPYSEQ(ctx,1,local+4); /*copy-seq*/
	argv[0]->c.obj.iv[3] = w;
	local[4]= argv[0]->c.obj.iv[3];
	goto CON240;
CON243:
	local[4]= fqv[4];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,1,local+4); /*error*/
	local[4]= w;
	goto CON240;
CON244:
	local[4]= NIL;
CON240:
	w = local[4];
	local[0]= w;
BLK234:
	ctx->vsp=local; return(local[0]);}

/*:specular*/
static pointer M245colormaterial_specular(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT251;}
	local[0]= NIL;
ENT251:
	if (n>=4) { local[1]=(argv[3]); goto ENT250;}
	local[1]= local[0];
ENT250:
	if (n>=5) { local[2]=(argv[4]); goto ENT249;}
	local[2]= local[0];
ENT249:
	if (n>=6) { local[3]=(argv[5]); goto ENT248;}
	local[3]= makeint(1);
ENT248:
ENT247:
	if (n>6) maerror();
	if (local[0]!=NIL) goto CON253;
	local[4]= argv[0]->c.obj.iv[4];
	goto CON252;
CON253:
	w = local[0];
	if (!isnum(w)) goto CON254;
	local[4]= local[0];
	local[5]= local[1];
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,4,local+4); /*float-vector*/
	argv[0]->c.obj.iv[4] = w;
	local[4]= argv[0]->c.obj.iv[4];
	goto CON252;
CON254:
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,1,local+4,&ftab[0],fqv[2]); /*float-vector-p*/
	if (w==NIL) goto CON255;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)COPYSEQ(ctx,1,local+4); /*copy-seq*/
	argv[0]->c.obj.iv[4] = w;
	local[4]= argv[0]->c.obj.iv[4];
	goto CON252;
CON255:
	local[4]= fqv[5];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,1,local+4); /*error*/
	local[4]= w;
	goto CON252;
CON256:
	local[4]= NIL;
CON252:
	w = local[4];
	local[0]= w;
BLK246:
	ctx->vsp=local; return(local[0]);}

/*:emission*/
static pointer M257colormaterial_emission(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT263;}
	local[0]= NIL;
ENT263:
	if (n>=4) { local[1]=(argv[3]); goto ENT262;}
	local[1]= local[0];
ENT262:
	if (n>=5) { local[2]=(argv[4]); goto ENT261;}
	local[2]= local[0];
ENT261:
	if (n>=6) { local[3]=(argv[5]); goto ENT260;}
	local[3]= makeint(1);
ENT260:
ENT259:
	if (n>6) maerror();
	if (local[0]!=NIL) goto CON265;
	local[4]= argv[0]->c.obj.iv[5];
	goto CON264;
CON265:
	w = local[0];
	if (!isnum(w)) goto CON266;
	local[4]= local[0];
	local[5]= local[1];
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,4,local+4); /*float-vector*/
	argv[0]->c.obj.iv[5] = w;
	local[4]= argv[0]->c.obj.iv[5];
	goto CON264;
CON266:
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,1,local+4,&ftab[0],fqv[2]); /*float-vector-p*/
	if (w==NIL) goto CON267;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)COPYSEQ(ctx,1,local+4); /*copy-seq*/
	argv[0]->c.obj.iv[5] = w;
	local[4]= argv[0]->c.obj.iv[5];
	goto CON264;
CON267:
	local[4]= fqv[6];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,1,local+4); /*error*/
	local[4]= w;
	goto CON264;
CON268:
	local[4]= NIL;
CON264:
	w = local[4];
	local[0]= w;
BLK258:
	ctx->vsp=local; return(local[0]);}

/*:shininess*/
static pointer M269colormaterial_shininess(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT272;}
	local[0]= NIL;
ENT272:
ENT271:
	if (n>3) maerror();
	if (local[0]!=NIL) goto CON274;
	local[1]= argv[0]->c.obj.iv[6];
	goto CON273;
CON274:
	w = local[0];
	if (!isnum(w)) goto CON275;
	argv[0]->c.obj.iv[6] = local[0];
	local[1]= argv[0]->c.obj.iv[6];
	goto CON273;
CON275:
	local[1]= fqv[7];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto CON273;
CON276:
	local[1]= NIL;
CON273:
	w = local[1];
	local[0]= w;
BLK270:
	ctx->vsp=local; return(local[0]);}

/*:transparency*/
static pointer M277colormaterial_transparency(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT280;}
	local[0]= NIL;
ENT280:
ENT279:
	if (n>3) maerror();
	if (local[0]!=NIL) goto CON282;
	local[1]= argv[0]->c.obj.iv[7];
	goto CON281;
CON282:
	w = local[0];
	if (!isnum(w)) goto CON283;
	argv[0]->c.obj.iv[7] = local[0];
	local[1]= argv[0]->c.obj.iv[7];
	goto CON281;
CON283:
	local[1]= fqv[8];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto CON281;
CON284:
	local[1]= NIL;
CON281:
	w = local[1];
	local[0]= w;
BLK278:
	ctx->vsp=local; return(local[0]);}

/*:opengl*/
static pointer M285colormaterial_opengl(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(1032);
	local[1]= makeint(4608);
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,3,local+0,&ftab[1],fqv[9]); /*glmaterialfv*/
	local[0]= makeint(1032);
	local[1]= makeint(4609);
	local[2]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,3,local+0,&ftab[1],fqv[9]); /*glmaterialfv*/
	local[0]= makeint(1032);
	local[1]= makeint(4610);
	local[2]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,3,local+0,&ftab[1],fqv[9]); /*glmaterialfv*/
	local[0]= makeint(1032);
	local[1]= makeint(5632);
	local[2]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,3,local+0,&ftab[1],fqv[9]); /*glmaterialfv*/
	local[0]= makeint(1032);
	local[1]= makeint(5633);
	local[2]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,1,local+2); /*float-vector*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,3,local+0,&ftab[1],fqv[9]); /*glmaterialfv*/
	local[0]= w;
BLK286:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M287lightsource_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[10], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY289;
	local[4]= makeflt(5.00000000e-01);
	local[5]= makeflt(5.00000000e-01);
	local[6]= makeflt(5.00000000e-01);
	local[7]= makeflt(1.00000000e+00);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,4,local+4); /*float-vector*/
	local[0] = w;
KEY289:
	if (n & (1<<1)) goto KEY290;
	local[4]= makeflt(8.00000000e-01);
	local[5]= makeflt(8.00000000e-01);
	local[6]= makeflt(8.00000000e-01);
	local[7]= makeflt(8.00000000e-01);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,4,local+4); /*float-vector*/
	local[1] = w;
KEY290:
	if (n & (1<<2)) goto KEY291;
	local[4]= makeflt(7.00000000e-01);
	local[5]= makeflt(7.00000000e-01);
	local[6]= makeflt(7.00000000e-01);
	local[7]= makeflt(1.00000000e+00);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,4,local+4); /*float-vector*/
	local[2] = w;
KEY291:
	if (n & (1<<3)) goto KEY292;
	local[4]= makeflt(1.00000000e+03);
	local[5]= makeflt(2.00000000e+03);
	local[6]= makeflt(1.00000000e+05);
	local[7]= makeflt(0.00000000e+00);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,4,local+4); /*float-vector*/
	local[3] = w;
KEY292:
	argv[0]->c.obj.iv[1] = argv[2];
	argv[0]->c.obj.iv[2] = local[0];
	argv[0]->c.obj.iv[3] = local[1];
	argv[0]->c.obj.iv[4] = local[2];
	argv[0]->c.obj.iv[5] = local[3];
	w = argv[0];
	local[0]= w;
BLK288:
	ctx->vsp=local; return(local[0]);}

/*:light-id*/
static pointer M293lightsource_light_id(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(16384);
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
BLK294:
	ctx->vsp=local; return(local[0]);}

/*:ambient*/
static pointer M295lightsource_ambient(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT301;}
	local[0]= NIL;
ENT301:
	if (n>=4) { local[1]=(argv[3]); goto ENT300;}
	local[1]= local[0];
ENT300:
	if (n>=5) { local[2]=(argv[4]); goto ENT299;}
	local[2]= local[0];
ENT299:
	if (n>=6) { local[3]=(argv[5]); goto ENT298;}
	local[3]= makeint(1);
ENT298:
ENT297:
	if (n>6) maerror();
	if (local[0]!=NIL) goto CON303;
	local[4]= argv[0]->c.obj.iv[2];
	goto CON302;
CON303:
	w = local[0];
	if (!isnum(w)) goto CON304;
	local[4]= local[0];
	local[5]= local[1];
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,4,local+4); /*float-vector*/
	argv[0]->c.obj.iv[2] = w;
	local[4]= argv[0]->c.obj.iv[2];
	goto CON302;
CON304:
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,1,local+4,&ftab[0],fqv[2]); /*float-vector-p*/
	if (w==NIL) goto CON305;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)COPYSEQ(ctx,1,local+4); /*copy-seq*/
	argv[0]->c.obj.iv[2] = w;
	local[4]= argv[0]->c.obj.iv[2];
	goto CON302;
CON305:
	local[4]= fqv[11];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,1,local+4); /*error*/
	local[4]= w;
	goto CON302;
CON306:
	local[4]= NIL;
CON302:
	w = local[4];
	local[0]= w;
BLK296:
	ctx->vsp=local; return(local[0]);}

/*:diffuse*/
static pointer M307lightsource_diffuse(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT313;}
	local[0]= NIL;
ENT313:
	if (n>=4) { local[1]=(argv[3]); goto ENT312;}
	local[1]= local[0];
ENT312:
	if (n>=5) { local[2]=(argv[4]); goto ENT311;}
	local[2]= local[0];
ENT311:
	if (n>=6) { local[3]=(argv[5]); goto ENT310;}
	local[3]= makeint(1);
ENT310:
ENT309:
	if (n>6) maerror();
	if (local[0]!=NIL) goto CON315;
	local[4]= argv[0]->c.obj.iv[3];
	goto CON314;
CON315:
	w = local[0];
	if (!isnum(w)) goto CON316;
	local[4]= local[0];
	local[5]= local[1];
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,4,local+4); /*float-vector*/
	argv[0]->c.obj.iv[3] = w;
	local[4]= argv[0]->c.obj.iv[3];
	goto CON314;
CON316:
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,1,local+4,&ftab[0],fqv[2]); /*float-vector-p*/
	if (w==NIL) goto CON317;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)COPYSEQ(ctx,1,local+4); /*copy-seq*/
	argv[0]->c.obj.iv[3] = w;
	local[4]= argv[0]->c.obj.iv[3];
	goto CON314;
CON317:
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,1,local+4); /*error*/
	local[4]= w;
	goto CON314;
CON318:
	local[4]= NIL;
CON314:
	w = local[4];
	local[0]= w;
BLK308:
	ctx->vsp=local; return(local[0]);}

/*:specular*/
static pointer M319lightsource_specular(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT325;}
	local[0]= NIL;
ENT325:
	if (n>=4) { local[1]=(argv[3]); goto ENT324;}
	local[1]= local[0];
ENT324:
	if (n>=5) { local[2]=(argv[4]); goto ENT323;}
	local[2]= local[0];
ENT323:
	if (n>=6) { local[3]=(argv[5]); goto ENT322;}
	local[3]= makeint(1);
ENT322:
ENT321:
	if (n>6) maerror();
	if (local[0]!=NIL) goto CON327;
	local[4]= argv[0]->c.obj.iv[4];
	goto CON326;
CON327:
	w = local[0];
	if (!isnum(w)) goto CON328;
	local[4]= local[0];
	local[5]= local[1];
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,4,local+4); /*float-vector*/
	argv[0]->c.obj.iv[4] = w;
	local[4]= argv[0]->c.obj.iv[4];
	goto CON326;
CON328:
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,1,local+4,&ftab[0],fqv[2]); /*float-vector-p*/
	if (w==NIL) goto CON329;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)COPYSEQ(ctx,1,local+4); /*copy-seq*/
	argv[0]->c.obj.iv[4] = w;
	local[4]= argv[0]->c.obj.iv[4];
	goto CON326;
CON329:
	local[4]= fqv[13];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,1,local+4); /*error*/
	local[4]= w;
	goto CON326;
CON330:
	local[4]= NIL;
CON326:
	w = local[4];
	local[0]= w;
BLK320:
	ctx->vsp=local; return(local[0]);}

/*:position*/
static pointer M331lightsource_position(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT334;}
	local[0]= NIL;
ENT334:
ENT333:
	if (n>3) maerror();
	if (local[0]!=NIL) goto CON336;
	local[1]= argv[0]->c.obj.iv[5];
	goto CON335;
CON336:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[2]); /*float-vector-p*/
	if (w==NIL) goto CON337;
	argv[0]->c.obj.iv[5] = local[0];
	local[1]= argv[0]->c.obj.iv[5];
	goto CON335;
CON337:
	local[1]= NIL;
CON335:
	w = local[1];
	local[0]= w;
BLK332:
	ctx->vsp=local; return(local[0]);}

/*:move*/
static pointer M338lightsource_move(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+3;
	w=(pointer)VPLUS(ctx,3,local+0); /*v+*/
	local[0]= w;
BLK339:
	ctx->vsp=local; return(local[0]);}

/*:enable*/
static pointer M340lightsource_enable(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[14];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[2])(ctx,1,local+0,&ftab[2],fqv[15]); /*glenable*/
	local[0]= w;
BLK341:
	ctx->vsp=local; return(local[0]);}

/*:disable*/
static pointer M342lightsource_disable(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[14];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[3])(ctx,1,local+0,&ftab[3],fqv[16]); /*gldisable*/
	local[0]= w;
BLK343:
	ctx->vsp=local; return(local[0]);}

/*:opengl*/
static pointer M344lightsource_opengl(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(16384);
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
	local[1]= local[0];
	local[2]= makeint(4608);
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,3,local+1,&ftab[4],fqv[17]); /*gllightfv*/
	local[1]= local[0];
	local[2]= makeint(4609);
	local[3]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,3,local+1,&ftab[4],fqv[17]); /*gllightfv*/
	local[1]= local[0];
	local[2]= makeint(4610);
	local[3]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,3,local+1,&ftab[4],fqv[17]); /*gllightfv*/
	local[1]= local[0];
	local[2]= makeint(4611);
	local[3]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,3,local+1,&ftab[4],fqv[17]); /*gllightfv*/
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,1,local+1,&ftab[2],fqv[15]); /*glenable*/
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK345:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M346glviewsurface_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST348:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[18], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY349;
	local[1] = makeint(0);
KEY349:
	if (n & (1<<1)) goto KEY350;
	local[2] = makeint(0);
KEY350:
	if (n & (1<<2)) goto KEY351;
	local[3] = makeint(256);
KEY351:
	if (n & (1<<3)) goto KEY352;
	local[4] = local[3];
KEY352:
	if (n & (1<<4)) goto KEY353;
	local[5] = local[3];
KEY353:
	if (n & (1<<5)) goto KEY354;
	local[6] = makeint(0);
KEY354:
	if (n & (1<<6)) goto KEY355;
	local[8]= fqv[19];
	ctx->vsp=local+9;
	w=(pointer)GENSYM(ctx,1,local+8); /*gensym*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[5])(ctx,1,local+8,&ftab[5],fqv[20]); /*string*/
	local[7] = w;
KEY355:
	local[8]= argv[0];
	local[9]= fqv[21];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= argv[0];
	local[9]= fqv[22];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= argv[0];
	local[9]= fqv[23];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= argv[0];
	local[9]= fqv[24];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= loadglobal(fqv[25]);
	local[9]= loadglobal(fqv[25]);
	ctx->vsp=local+10;
	w=(*ftab[6])(ctx,1,local+9,&ftab[6],fqv[26]); /*x:defaultscreen*/
	local[9]= w;
	local[10]= loadglobal(fqv[27]);
	ctx->vsp=local+11;
	w=(*ftab[7])(ctx,3,local+8,&ftab[7],fqv[28]); /*glxchoosevisual*/
	argv[0]->c.obj.iv[14] = w;
	local[8]= loadglobal(fqv[25]);
	local[9]= argv[0]->c.obj.iv[14];
	local[10]= local[6];
	local[11]= makeint(1);
	ctx->vsp=local+12;
	w=(*ftab[8])(ctx,4,local+8,&ftab[8],fqv[29]); /*glxcreatecontext*/
	argv[0]->c.obj.iv[15] = w;
	local[8]= (pointer)get_sym_func(fqv[30]);
	local[9]= argv[0];
	local[10]= *(ovafptr(argv[1],fqv[31]));
	local[11]= fqv[32];
	local[12]= fqv[33];
	local[13]= argv[0]->c.obj.iv[14];
	local[14]= makeint(20);
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,2,local+13); /*+*/
	local[13]= w;
	local[14]= fqv[34];
	ctx->vsp=local+15;
	w=(pointer)PEEK(ctx,2,local+13); /*system:peek*/
	local[13]= w;
	local[14]= fqv[35];
	local[15]= argv[0]->c.obj.iv[14];
	local[16]= fqv[36];
	ctx->vsp=local+17;
	w=(pointer)PEEK(ctx,2,local+15); /*system:peek*/
	local[15]= w;
	local[16]= fqv[37];
	local[17]= local[7];
	local[18]= local[0];
	ctx->vsp=local+19;
	w=(pointer)APPLY(ctx,11,local+8); /*apply*/
	local[8]= loadglobal(fqv[25]);
	local[9]= argv[0]->c.obj.iv[2];
	local[10]= argv[0]->c.obj.iv[15];
	ctx->vsp=local+11;
	w=(*ftab[9])(ctx,3,local+8,&ftab[9],fqv[38]); /*glxmakecurrent*/
	local[8]= argv[0];
	local[9]= fqv[39];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= loadglobal(fqv[40]);
	ctx->vsp=local+9;
	w=(pointer)INSTANTIATE(ctx,1,local+8); /*instantiate*/
	local[8]= w;
	local[9]= local[8];
	local[10]= fqv[32];
	local[11]= makeint(0);
	local[12]= fqv[41];
	local[13]= makeflt(2.00000000e-01);
	local[14]= makeflt(2.00000000e-01);
	local[15]= makeflt(2.00000000e-01);
	local[16]= makeflt(0.00000000e+00);
	ctx->vsp=local+17;
	w=(pointer)MKFLTVEC(ctx,4,local+13); /*float-vector*/
	local[13]= w;
	local[14]= fqv[42];
	local[15]= makeflt(5.00000000e-01);
	local[16]= makeflt(5.00000000e-01);
	local[17]= makeflt(5.00000000e-01);
	local[18]= makeflt(0.00000000e+00);
	ctx->vsp=local+19;
	w=(pointer)MKFLTVEC(ctx,4,local+15); /*float-vector*/
	local[15]= w;
	local[16]= fqv[43];
	local[17]= makeflt(3.00000000e-01);
	local[18]= makeflt(3.00000000e-01);
	local[19]= makeflt(3.00000000e-01);
	local[20]= makeflt(0.00000000e+00);
	ctx->vsp=local+21;
	w=(pointer)MKFLTVEC(ctx,4,local+17); /*float-vector*/
	local[17]= w;
	local[18]= fqv[44];
	local[19]= makeflt(0.00000000e+00);
	local[20]= makeflt(0.00000000e+00);
	local[21]= makeflt(1.00000000e+00);
	local[22]= makeflt(0.00000000e+00);
	ctx->vsp=local+23;
	w=(pointer)MKFLTVEC(ctx,4,local+19); /*float-vector*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,11,local+9); /*send*/
	w = local[8];
	local[8]= w;
	storeglobal(fqv[45],w);
	local[8]= loadglobal(fqv[40]);
	ctx->vsp=local+9;
	w=(pointer)INSTANTIATE(ctx,1,local+8); /*instantiate*/
	local[8]= w;
	local[9]= local[8];
	local[10]= fqv[32];
	local[11]= makeint(1);
	local[12]= fqv[41];
	local[13]= makeflt(3.00000000e-01);
	local[14]= makeflt(3.00000000e-01);
	local[15]= makeflt(3.00000000e-01);
	local[16]= makeflt(1.00000000e+00);
	ctx->vsp=local+17;
	w=(pointer)MKFLTVEC(ctx,4,local+13); /*float-vector*/
	local[13]= w;
	local[14]= fqv[42];
	local[15]= makeflt(6.00000000e-01);
	local[16]= makeflt(1.00000000e-01);
	local[17]= makeflt(1.00000000e-01);
	local[18]= makeflt(8.00000000e-01);
	ctx->vsp=local+19;
	w=(pointer)MKFLTVEC(ctx,4,local+15); /*float-vector*/
	local[15]= w;
	local[16]= fqv[43];
	local[17]= makeflt(3.00000000e-01);
	local[18]= makeflt(3.00000000e-01);
	local[19]= makeflt(3.00000000e-01);
	local[20]= makeflt(1.00000000e+00);
	ctx->vsp=local+21;
	w=(pointer)MKFLTVEC(ctx,4,local+17); /*float-vector*/
	local[17]= w;
	local[18]= fqv[44];
	local[19]= makeflt(5.00000000e+03);
	local[20]= makeflt(1.00000000e+03);
	local[21]= makeflt(7.00000000e+03);
	local[22]= makeflt(1.00000000e+00);
	ctx->vsp=local+23;
	w=(pointer)MKFLTVEC(ctx,4,local+19); /*float-vector*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,11,local+9); /*send*/
	w = local[8];
	local[8]= w;
	storeglobal(fqv[46],w);
	local[8]= loadglobal(fqv[40]);
	ctx->vsp=local+9;
	w=(pointer)INSTANTIATE(ctx,1,local+8); /*instantiate*/
	local[8]= w;
	local[9]= local[8];
	local[10]= fqv[32];
	local[11]= makeint(2);
	local[12]= fqv[41];
	local[13]= makeflt(3.00000000e-01);
	local[14]= makeflt(3.00000000e-01);
	local[15]= makeflt(3.00000000e-01);
	local[16]= makeflt(1.00000000e+00);
	ctx->vsp=local+17;
	w=(pointer)MKFLTVEC(ctx,4,local+13); /*float-vector*/
	local[13]= w;
	local[14]= fqv[42];
	local[15]= makeflt(1.00000000e-01);
	local[16]= makeflt(1.00000000e-01);
	local[17]= makeflt(7.00000000e-01);
	local[18]= makeflt(0.00000000e+00);
	ctx->vsp=local+19;
	w=(pointer)MKFLTVEC(ctx,4,local+15); /*float-vector*/
	local[15]= w;
	local[16]= fqv[43];
	local[17]= makeflt(3.00000000e-01);
	local[18]= makeflt(3.00000000e-01);
	local[19]= makeflt(3.00000000e-01);
	local[20]= makeflt(1.00000000e+00);
	ctx->vsp=local+21;
	w=(pointer)MKFLTVEC(ctx,4,local+17); /*float-vector*/
	local[17]= w;
	local[18]= fqv[44];
	local[19]= makeflt(-1.50000000e+04);
	local[20]= makeflt(0.00000000e+00);
	local[21]= makeflt(2.00000000e+03);
	local[22]= makeflt(1.00000000e+00);
	ctx->vsp=local+23;
	w=(pointer)MKFLTVEC(ctx,4,local+19); /*float-vector*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,11,local+9); /*send*/
	w = local[8];
	local[8]= w;
	storeglobal(fqv[47],w);
	local[8]= makeint(2896);
	ctx->vsp=local+9;
	w=(*ftab[2])(ctx,1,local+8,&ftab[2],fqv[15]); /*glenable*/
	local[8]= loadglobal(fqv[45]);
	local[9]= fqv[48];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= loadglobal(fqv[46]);
	local[9]= fqv[48];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= loadglobal(fqv[47]);
	local[9]= fqv[48];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= makeint(2304);
	ctx->vsp=local+9;
	w=(*ftab[10])(ctx,1,local+8,&ftab[10],fqv[49]); /*glfrontface*/
	local[8]= makeint(3456);
	ctx->vsp=local+9;
	w=(*ftab[2])(ctx,1,local+8,&ftab[2],fqv[15]); /*glenable*/
	local[8]= makeint(2977);
	ctx->vsp=local+9;
	w=(*ftab[2])(ctx,1,local+8,&ftab[2],fqv[15]); /*glenable*/
	local[8]= makeint(513);
	ctx->vsp=local+9;
	w=(*ftab[11])(ctx,1,local+8,&ftab[11],fqv[50]); /*gldepthfunc*/
	local[8]= makeint(2929);
	ctx->vsp=local+9;
	w=(*ftab[2])(ctx,1,local+8,&ftab[2],fqv[15]); /*glenable*/
	local[8]= makeint(7425);
	ctx->vsp=local+9;
	w=(*ftab[12])(ctx,1,local+8,&ftab[12],fqv[51]); /*glshademodel*/
	local[8]= makeint(3317);
	local[9]= makeint(1);
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[52]); /*glpixelstorei*/
	local[8]= makeint(3553);
	local[9]= makeint(10242);
	local[10]= makeint(10497);
	ctx->vsp=local+11;
	w=(*ftab[14])(ctx,3,local+8,&ftab[14],fqv[53]); /*gltexparameteri*/
	local[8]= makeint(3553);
	local[9]= makeint(10243);
	local[10]= makeint(10497);
	ctx->vsp=local+11;
	w=(*ftab[14])(ctx,3,local+8,&ftab[14],fqv[53]); /*gltexparameteri*/
	local[8]= makeint(3553);
	local[9]= makeint(10240);
	local[10]= makeint(9728);
	ctx->vsp=local+11;
	w=(*ftab[14])(ctx,3,local+8,&ftab[14],fqv[53]); /*gltexparameteri*/
	local[8]= makeint(3553);
	local[9]= makeint(10241);
	local[10]= makeint(9728);
	ctx->vsp=local+11;
	w=(*ftab[14])(ctx,3,local+8,&ftab[14],fqv[53]); /*gltexparameteri*/
	local[8]= makeint(8960);
	local[9]= makeint(8704);
	local[10]= makeint(8448);
	ctx->vsp=local+11;
	w=(*ftab[15])(ctx,3,local+8,&ftab[15],fqv[54]); /*gltexenvi*/
	local[8]= makeint(16384);
	w = makeint(256);
	local[8]= (pointer)((eusinteger_t)local[8] | (eusinteger_t)w);
	ctx->vsp=local+9;
	w=(*ftab[16])(ctx,1,local+8,&ftab[16],fqv[55]); /*glclear*/
	local[8]= loadglobal(fqv[25]);
	local[9]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+10;
	w=(*ftab[17])(ctx,2,local+8,&ftab[17],fqv[56]); /*glxswapbuffers*/
	local[8]= makeint(16384);
	w = makeint(256);
	local[8]= (pointer)((eusinteger_t)local[8] | (eusinteger_t)w);
	ctx->vsp=local+9;
	w=(*ftab[16])(ctx,1,local+8,&ftab[16],fqv[55]); /*glclear*/
	local[8]= loadglobal(fqv[25]);
	local[9]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+10;
	w=(*ftab[17])(ctx,2,local+8,&ftab[17],fqv[56]); /*glxswapbuffers*/
	ctx->vsp=local+8;
	w=(*ftab[18])(ctx,0,local+8,&ftab[18],fqv[57]); /*glunewtess*/
	local[8]= w;
	storeglobal(fqv[58],w);
	local[8]= loadglobal(fqv[58]);
	local[9]= makeint(100100);
	local[10]= *(ovafptr((pointer)get_sym_func(fqv[59]),fqv[60]));
	local[11]= *(ovafptr((pointer)get_sym_func(fqv[59]),fqv[61]));
	ctx->vsp=local+12;
	w=(*ftab[19])(ctx,4,local+8,&ftab[19],fqv[62]); /*glutesscallbackl*/
	local[8]= loadglobal(fqv[58]);
	local[9]= makeint(100101);
	local[10]= *(ovafptr((pointer)get_sym_func(fqv[63]),fqv[60]));
	local[11]= *(ovafptr((pointer)get_sym_func(fqv[63]),fqv[61]));
	ctx->vsp=local+12;
	w=(*ftab[19])(ctx,4,local+8,&ftab[19],fqv[62]); /*glutesscallbackl*/
	local[8]= loadglobal(fqv[58]);
	local[9]= makeint(100102);
	local[10]= *(ovafptr((pointer)get_sym_func(fqv[64]),fqv[60]));
	local[11]= *(ovafptr((pointer)get_sym_func(fqv[64]),fqv[61]));
	ctx->vsp=local+12;
	w=(*ftab[19])(ctx,4,local+8,&ftab[19],fqv[62]); /*glutesscallbackl*/
	w = argv[0];
	local[0]= w;
BLK347:
	ctx->vsp=local; return(local[0]);}

/*:material*/
static pointer M359glviewsurface_material(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT365;}
	local[0]= NIL;
ENT365:
	if (n>=5) { local[1]=(argv[4]); goto ENT364;}
	local[1]= NIL;
ENT364:
	if (n>=6) { local[2]=(argv[5]); goto ENT363;}
	local[2]= NIL;
ENT363:
	if (n>=7) { local[3]=(argv[6]); goto ENT362;}
	local[3]= NIL;
ENT362:
ENT361:
	if (n>7) maerror();
	if (local[0]!=NIL) goto IF366;
	local[0] = argv[2]->c.obj.iv[3];
	local[1] = argv[2]->c.obj.iv[4];
	local[2] = argv[2]->c.obj.iv[5];
	local[3] = argv[2]->c.obj.iv[6];
	argv[2] = argv[2]->c.obj.iv[2];
	local[4]= argv[2];
	goto IF367;
IF366:
	local[4]= NIL;
IF367:
	local[4]= makeint(1032);
	local[5]= makeint(4608);
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,3,local+4,&ftab[1],fqv[9]); /*glmaterialfv*/
	local[4]= makeint(1032);
	local[5]= makeint(4609);
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,3,local+4,&ftab[1],fqv[9]); /*glmaterialfv*/
	local[4]= makeint(1032);
	local[5]= makeint(4610);
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,3,local+4,&ftab[1],fqv[9]); /*glmaterialfv*/
	local[4]= makeint(1032);
	local[5]= makeint(5632);
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,3,local+4,&ftab[1],fqv[9]); /*glmaterialfv*/
	local[4]= makeint(1032);
	local[5]= makeint(5633);
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,1,local+6); /*float-vector*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,3,local+4,&ftab[1],fqv[9]); /*glmaterialfv*/
	local[0]= w;
BLK360:
	ctx->vsp=local; return(local[0]);}

/*:color*/
static pointer M368glviewsurface_color(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= loadglobal(fqv[65]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto IF370;
	argv[2] = argv[2]->c.obj.iv[0];
	local[0]= argv[2];
	goto IF371;
IF370:
	local[0]= NIL;
IF371:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= local[0];
	if (fqv[66]!=local[1]) goto IF373;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[20])(ctx,1,local+1,&ftab[20],fqv[67]); /*glcolor3fv*/
	local[1]= w;
	goto IF374;
IF373:
	local[1]= local[0];
	if (fqv[68]!=local[1]) goto IF375;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,1,local+1,&ftab[21],fqv[69]); /*glcolor4fv*/
	local[1]= w;
	goto IF376;
IF375:
	if (T==NIL) goto IF377;
	local[1]= fqv[70];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF378;
IF377:
	local[1]= NIL;
IF378:
IF376:
IF374:
	w = local[1];
	local[0]= w;
BLK369:
	ctx->vsp=local; return(local[0]);}

/*:window*/
static pointer M379glviewsurface_window(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK380:
	ctx->vsp=local; return(local[0]);}

/*:3d-mode*/
static pointer M381glviewsurface_3d_mode(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF383;
	local[0]= makeint(0);
	local[1]= argv[0]->c.obj.iv[5];
	local[2]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,1,local+1); /*-*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[5];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[22])(ctx,4,local+0,&ftab[22],fqv[71]); /*glviewport*/
	local[0]= w;
	goto IF384;
IF383:
	local[0]= argv[0]->c.obj.iv[6];
	local[1]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	local[0]= w;
	local[1]= makeint(2);
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)MINUS(ctx,1,local+0); /*-*/
	local[0]= w;
	local[1]= makeint(0);
	local[2]= argv[0]->c.obj.iv[6];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[6];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[22])(ctx,4,local+0,&ftab[22],fqv[71]); /*glviewport*/
	local[0]= w;
IF384:
	local[0]= makeint(5889);
	ctx->vsp=local+1;
	w=(*ftab[23])(ctx,1,local+0,&ftab[23],fqv[72]); /*glmatrixmode*/
	ctx->vsp=local+0;
	w=(*ftab[24])(ctx,0,local+0,&ftab[24],fqv[73]); /*glloadidentity*/
	local[0]= makeint(2929);
	ctx->vsp=local+1;
	w=(*ftab[2])(ctx,1,local+0,&ftab[2],fqv[15]); /*glenable*/
	local[0]= makeint(2896);
	ctx->vsp=local+1;
	w=(*ftab[2])(ctx,1,local+0,&ftab[2],fqv[15]); /*glenable*/
	local[0]= makeint(5888);
	ctx->vsp=local+1;
	w=(*ftab[23])(ctx,1,local+0,&ftab[23],fqv[72]); /*glmatrixmode*/
	ctx->vsp=local+0;
	w=(*ftab[24])(ctx,0,local+0,&ftab[24],fqv[73]); /*glloadidentity*/
	local[0]= w;
BLK382:
	ctx->vsp=local; return(local[0]);}

/*:2d-mode*/
static pointer M385glviewsurface_2d_mode(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[74], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY387;
	local[0] = NIL;
KEY387:
	local[1]= makeint(0);
	local[2]= makeint(0);
	local[3]= argv[0]->c.obj.iv[5];
	local[4]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+5;
	w=(*ftab[22])(ctx,4,local+1,&ftab[22],fqv[71]); /*glviewport*/
	local[1]= makeint(5889);
	ctx->vsp=local+2;
	w=(*ftab[23])(ctx,1,local+1,&ftab[23],fqv[72]); /*glmatrixmode*/
	if (local[0]==NIL) goto IF388;
	ctx->vsp=local+1;
	w=(*ftab[25])(ctx,0,local+1,&ftab[25],fqv[75]); /*glpushmatrix*/
	local[1]= w;
	goto IF389;
IF388:
	local[1]= NIL;
IF389:
	ctx->vsp=local+1;
	w=(*ftab[24])(ctx,0,local+1,&ftab[24],fqv[73]); /*glloadidentity*/
	local[1]= makeint(0);
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= makeint(0);
	local[4]= argv[0]->c.obj.iv[6];
	local[5]= makeflt(-1.00000000e+00);
	local[6]= makeflt(1.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,6,local+1); /*float-vector*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[26])(ctx,1,local+1,&ftab[26],fqv[76]); /*glorthofv*/
	local[1]= makeint(2929);
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[16]); /*gldisable*/
	local[1]= makeint(2896);
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[16]); /*gldisable*/
	local[1]= makeint(5888);
	ctx->vsp=local+2;
	w=(*ftab[23])(ctx,1,local+1,&ftab[23],fqv[72]); /*glmatrixmode*/
	if (local[0]==NIL) goto IF390;
	ctx->vsp=local+1;
	w=(*ftab[25])(ctx,0,local+1,&ftab[25],fqv[75]); /*glpushmatrix*/
	local[1]= w;
	goto IF391;
IF390:
	local[1]= NIL;
IF391:
	ctx->vsp=local+1;
	w=(*ftab[24])(ctx,0,local+1,&ftab[24],fqv[73]); /*glloadidentity*/
	local[0]= w;
BLK386:
	ctx->vsp=local; return(local[0]);}

/*:pop-mode*/
static pointer M392glviewsurface_pop_mode(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(5889);
	ctx->vsp=local+1;
	w=(*ftab[23])(ctx,1,local+0,&ftab[23],fqv[72]); /*glmatrixmode*/
	ctx->vsp=local+0;
	w=(*ftab[27])(ctx,0,local+0,&ftab[27],fqv[77]); /*glpopmatrix*/
	local[0]= makeint(5888);
	ctx->vsp=local+1;
	w=(*ftab[23])(ctx,1,local+0,&ftab[23],fqv[72]); /*glmatrixmode*/
	ctx->vsp=local+0;
	w=(*ftab[27])(ctx,0,local+0,&ftab[27],fqv[77]); /*glpopmatrix*/
	local[0]= w;
BLK393:
	ctx->vsp=local; return(local[0]);}

/*:height*/
static pointer M394glviewsurface_height(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT397;}
	local[0]= NIL;
ENT397:
ENT396:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF398;
	argv[0]->c.obj.iv[6] = local[0];
	local[1]= argv[0]->c.obj.iv[6];
	goto IF399;
IF398:
	local[1]= NIL;
IF399:
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK395:
	ctx->vsp=local; return(local[0]);}

/*:width*/
static pointer M400glviewsurface_width(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT403;}
	local[0]= NIL;
ENT403:
ENT402:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF404;
	argv[0]->c.obj.iv[5] = local[0];
	local[1]= argv[0]->c.obj.iv[5];
	goto IF405;
IF404:
	local[1]= NIL;
IF405:
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK401:
	ctx->vsp=local; return(local[0]);}

/*:pos*/
static pointer M406glviewsurface_pos(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[12];
	local[1]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+2;
	w=(pointer)MKINTVECTOR(ctx,2,local+0); /*integer-vector*/
	local[0]= w;
BLK407:
	ctx->vsp=local; return(local[0]);}

/*:x*/
static pointer M408glviewsurface_x(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT411;}
	local[0]= NIL;
ENT411:
ENT410:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF412;
	argv[0]->c.obj.iv[12] = local[0];
	local[1]= argv[0]->c.obj.iv[12];
	goto IF413;
IF412:
	local[1]= NIL;
IF413:
	w = argv[0]->c.obj.iv[12];
	local[0]= w;
BLK409:
	ctx->vsp=local; return(local[0]);}

/*:y*/
static pointer M414glviewsurface_y(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT417;}
	local[0]= NIL;
ENT417:
ENT416:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF418;
	argv[0]->c.obj.iv[13] = local[0];
	local[1]= argv[0]->c.obj.iv[13];
	goto IF419;
IF418:
	local[1]= NIL;
IF419:
	w = argv[0]->c.obj.iv[13];
	local[0]= w;
BLK415:
	ctx->vsp=local; return(local[0]);}

/*:clear*/
static pointer M420glviewsurface_clear(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(16384);
	w = makeint(256);
	local[0]= (pointer)((eusinteger_t)local[0] | (eusinteger_t)w);
	ctx->vsp=local+1;
	w=(*ftab[16])(ctx,1,local+0,&ftab[16],fqv[55]); /*glclear*/
	local[0]= w;
BLK421:
	ctx->vsp=local; return(local[0]);}

/*:glflush*/
static pointer M422glviewsurface_glflush(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	w=(*ftab[28])(ctx,0,local+0,&ftab[28],fqv[78]); /*glflush*/
	local[0]= loadglobal(fqv[25]);
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[56]); /*glxswapbuffers*/
	local[0]= w;
BLK423:
	ctx->vsp=local; return(local[0]);}

/*:point*/
static pointer M424glviewsurface_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[79];
	local[2]= fqv[80];
	local[3]= T;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= makeint(0);
	ctx->vsp=local+1;
	w=(*ftab[29])(ctx,1,local+0,&ftab[29],fqv[59]); /*glbegin*/
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[6];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MKFLTVEC(ctx,2,local+0); /*float-vector*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[30])(ctx,1,local+0,&ftab[30],fqv[81]); /*glvertex2fv*/
	ctx->vsp=local+0;
	w=(*ftab[31])(ctx,0,local+0,&ftab[31],fqv[64]); /*glend*/
	local[0]= argv[0];
	local[1]= fqv[39];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[82];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK425:
	ctx->vsp=local; return(local[0]);}

/*:line*/
static pointer M426glviewsurface_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[0];
	local[1]= fqv[79];
	local[2]= fqv[80];
	local[3]= T;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= makeint(1);
	ctx->vsp=local+1;
	w=(*ftab[29])(ctx,1,local+0,&ftab[29],fqv[59]); /*glbegin*/
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[6];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MKFLTVEC(ctx,2,local+0); /*float-vector*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[30])(ctx,1,local+0,&ftab[30],fqv[81]); /*glvertex2fv*/
	local[0]= argv[4];
	local[1]= argv[0]->c.obj.iv[6];
	local[2]= argv[5];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MKFLTVEC(ctx,2,local+0); /*float-vector*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[30])(ctx,1,local+0,&ftab[30],fqv[81]); /*glvertex2fv*/
	ctx->vsp=local+0;
	w=(*ftab[31])(ctx,0,local+0,&ftab[31],fqv[64]); /*glend*/
	local[0]= argv[0];
	local[1]= fqv[39];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[82];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK427:
	ctx->vsp=local; return(local[0]);}

/*:3d-point*/
static pointer M428glviewsurface_3d_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeint(2929);
	ctx->vsp=local+1;
	w=(*ftab[3])(ctx,1,local+0,&ftab[3],fqv[16]); /*gldisable*/
	local[0]= makeint(2896);
	ctx->vsp=local+1;
	w=(*ftab[3])(ctx,1,local+0,&ftab[3],fqv[16]); /*gldisable*/
	local[0]= makeint(0);
	ctx->vsp=local+1;
	w=(*ftab[29])(ctx,1,local+0,&ftab[29],fqv[59]); /*glbegin*/
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[32])(ctx,1,local+0,&ftab[32],fqv[83]); /*glvertex3fv*/
	ctx->vsp=local+0;
	w=(*ftab[31])(ctx,0,local+0,&ftab[31],fqv[64]); /*glend*/
	local[0]= makeint(2929);
	ctx->vsp=local+1;
	w=(*ftab[2])(ctx,1,local+0,&ftab[2],fqv[15]); /*glenable*/
	local[0]= makeint(2896);
	ctx->vsp=local+1;
	w=(*ftab[2])(ctx,1,local+0,&ftab[2],fqv[15]); /*glenable*/
	local[0]= w;
BLK429:
	ctx->vsp=local; return(local[0]);}

/*:3d-line*/
static pointer M430glviewsurface_3d_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= makeint(2896);
	ctx->vsp=local+1;
	w=(*ftab[3])(ctx,1,local+0,&ftab[3],fqv[16]); /*gldisable*/
	local[0]= makeint(1);
	ctx->vsp=local+1;
	w=(*ftab[29])(ctx,1,local+0,&ftab[29],fqv[59]); /*glbegin*/
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[32])(ctx,1,local+0,&ftab[32],fqv[83]); /*glvertex3fv*/
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(*ftab[32])(ctx,1,local+0,&ftab[32],fqv[83]); /*glvertex3fv*/
	ctx->vsp=local+0;
	w=(*ftab[31])(ctx,0,local+0,&ftab[31],fqv[64]); /*glend*/
	local[0]= makeint(2896);
	ctx->vsp=local+1;
	w=(*ftab[2])(ctx,1,local+0,&ftab[2],fqv[15]); /*glenable*/
	local[0]= w;
BLK431:
	ctx->vsp=local; return(local[0]);}

/*:draw-faces*/
static pointer M432glviewsurface_draw_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO434,env,argv,local);
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)MAPC(ctx,2,local+0); /*mapc*/
	local[0]= w;
BLK433:
	ctx->vsp=local; return(local[0]);}

/*:rectangle*/
static pointer M435glviewsurface_rectangle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[0];
	local[1]= fqv[79];
	local[2]= fqv[80];
	local[3]= T;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= makeint(9);
	ctx->vsp=local+1;
	w=(*ftab[29])(ctx,1,local+0,&ftab[29],fqv[59]); /*glbegin*/
	local[0]= argv[2];
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)MKFLTVEC(ctx,2,local+0); /*float-vector*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[30])(ctx,1,local+0,&ftab[30],fqv[81]); /*glvertex2fv*/
	local[0]= argv[2];
	local[1]= argv[3];
	local[2]= argv[5];
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MKFLTVEC(ctx,2,local+0); /*float-vector*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[30])(ctx,1,local+0,&ftab[30],fqv[81]); /*glvertex2fv*/
	local[0]= argv[2];
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
	local[1]= argv[3];
	local[2]= argv[5];
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MKFLTVEC(ctx,2,local+0); /*float-vector*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[30])(ctx,1,local+0,&ftab[30],fqv[81]); /*glvertex2fv*/
	local[0]= argv[2];
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)MKFLTVEC(ctx,2,local+0); /*float-vector*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[30])(ctx,1,local+0,&ftab[30],fqv[81]); /*glvertex2fv*/
	ctx->vsp=local+0;
	w=(*ftab[31])(ctx,0,local+0,&ftab[31],fqv[64]); /*glend*/
	local[0]= argv[0];
	local[1]= fqv[39];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[82];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK436:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO434(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= NIL;
	local[2]= NIL;
	ctx->vsp=local+3;
	w=(*ftab[33])(ctx,3,local+0,&ftab[33],fqv[84]); /*draw-face*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*geometry::default-viewsurface*/
static pointer F204geometry__default_viewsurface(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST438:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= (pointer)get_sym_func(fqv[85]);
	local[2]= loadglobal(fqv[86]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= fqv[32];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[0]= w;
BLK437:
	ctx->vsp=local; return(local[0]);}

/*:draw-point*/
static pointer M439glviewsurface_draw_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[87];
	local[2]= argv[2];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	local[3]= argv[2];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK440:
	ctx->vsp=local; return(local[0]);}

/*:draw-line*/
static pointer M441glviewsurface_draw_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[88];
	local[2]= argv[2];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	local[3]= argv[2];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	local[4]= argv[3];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	local[5]= argv[3];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	local[0]= w;
BLK442:
	ctx->vsp=local; return(local[0]);}

/*:draw-rectangle*/
static pointer M443glviewsurface_draw_rectangle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= fqv[89];
	local[2]= argv[2];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	local[3]= argv[2];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	local[4]= argv[3];
	local[5]= argv[4];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	local[0]= w;
BLK444:
	ctx->vsp=local; return(local[0]);}

/*:draw-one*/
static pointer M445geometry_viewer_draw_one(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	w = argv[2];
	if (!isnum(w)) goto CON448;
	local[0]= NIL;
	goto CON447;
CON448:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON449;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[2]); /*float-vector-p*/
	if (w==NIL) goto CON451;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= local[0];
	if (fqv[90]!=local[1]) goto IF453;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[88];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= w;
	goto IF454;
IF453:
	local[1]= local[0];
	if (fqv[91]!=local[1]) goto IF455;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[92];
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
	goto IF456;
IF455:
	if (T==NIL) goto IF457;
	local[1]= fqv[93];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF458;
IF457:
	local[1]= NIL;
IF458:
IF456:
IF454:
	w = local[1];
	local[0]= w;
	goto CON450;
CON451:
	local[0]= NIL;
	local[1]= argv[2];
WHL461:
	if (local[1]==NIL) goto WHX462;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0];
	local[3]= fqv[94];
	local[4]= local[0];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	goto WHL461;
WHX462:
	local[2]= NIL;
BLK463:
	w = NIL;
	local[0]= w;
	goto CON450;
CON459:
	local[0]= NIL;
CON450:
	goto CON447;
CON449:
	local[0]= argv[2];
	local[1]= fqv[95];
	ctx->vsp=local+2;
	w=(*ftab[34])(ctx,2,local+0,&ftab[34],fqv[96]); /*find-method*/
	if (w==NIL) goto CON465;
	local[0]= argv[2];
	local[1]= fqv[95];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON447;
CON465:
	local[0]= argv[2];
	local[1]= fqv[97];
	ctx->vsp=local+2;
	w=(*ftab[34])(ctx,2,local+0,&ftab[34],fqv[96]); /*find-method*/
	if (w==NIL) goto CON466;
	local[0]= argv[2];
	local[1]= fqv[98];
	ctx->vsp=local+2;
	w=(*ftab[34])(ctx,2,local+0,&ftab[34],fqv[96]); /*find-method*/
	if (w==NIL) goto IF467;
	local[0]= argv[2];
	local[1]= fqv[98];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF468;
IF467:
	local[0]= NIL;
IF468:
	local[0]= argv[0];
	local[1]= fqv[94];
	local[2]= argv[2];
	local[3]= fqv[97];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON447;
CON466:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[99]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON469;
	local[0]= argv[2];
	local[1]= fqv[48];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto CON447;
CON469:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[65]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON470;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[100];
	local[2]= argv[2]->c.obj.iv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON447;
CON470:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[101]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON471;
	local[0]= argv[0];
	local[1]= fqv[102];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON447;
CON471:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[103]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON472;
	local[0]= argv[0];
	local[1]= fqv[104];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON447;
CON472:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[40]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON473;
	local[0]= fqv[40];
	ctx->vsp=local+1;
	w=(pointer)PRINT(ctx,1,local+0); /*print*/
	local[0]= argv[2];
	local[1]= fqv[48];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto CON447;
CON473:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[105]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON474;
	local[0]= argv[2];
	local[1]= fqv[98];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= loadglobal(fqv[86]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto IF475;
	local[0]= argv[0];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[35])(ctx,2,local+0,&ftab[35],fqv[106]); /*draw-body*/
	local[0]= w;
	goto IF476;
IF475:
	local[0]= argv[2];
	local[1]= fqv[100];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= argv[2];
	local[3]= fqv[107];
	local[4]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
WHL478:
	if (local[2]==NIL) goto WHX479;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[0];
	local[4]= fqv[102];
	local[5]= local[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	goto WHL478;
WHX479:
	local[3]= NIL;
BLK480:
	w = NIL;
	local[0]= w;
IF476:
	goto CON447;
CON474:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[108]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON482;
	local[0]= argv[2];
	local[1]= fqv[98];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= loadglobal(fqv[86]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto IF483;
	local[0]= argv[0];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[35])(ctx,2,local+0,&ftab[35],fqv[106]); /*draw-body*/
	local[0]= w;
	goto IF484;
IF483:
	local[0]= argv[2];
	local[1]= fqv[100];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= argv[2];
	local[3]= fqv[109];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
WHL486:
	if (local[2]==NIL) goto WHX487;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[0];
	local[4]= fqv[102];
	local[5]= local[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	goto WHL486;
WHX487:
	local[3]= NIL;
BLK488:
	w = NIL;
	local[0]= w;
IF484:
	goto CON447;
CON482:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[110]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON490;
	local[0]= argv[0];
	local[1]= fqv[111];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON447;
CON490:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[112]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON491;
	local[0]= NIL;
	local[1]= argv[2];
	local[2]= fqv[109];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
WHL493:
	if (local[1]==NIL) goto WHX494;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0];
	local[3]= fqv[102];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	goto WHL493;
WHX494:
	local[2]= NIL;
BLK495:
	w = NIL;
	local[0]= w;
	goto CON447;
CON491:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[2]); /*float-vector-p*/
	if (w==NIL) goto CON497;
	local[0]= argv[0];
	local[1]= fqv[113];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[3];
	goto CON447;
CON497:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[36])(ctx,1,local+0,&ftab[36],fqv[114]); /*coordinates-p*/
	if (w==NIL) goto CON498;
	local[0]= argv[0];
	local[1]= fqv[115];
	local[2]= argv[2];
	local[3]= fqv[98];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON447;
CON498:
	local[0]= fqv[116];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w==NIL) goto CON499;
	local[0]= argv[2];
	local[1]= loadglobal(fqv[116]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON499;
	local[0]= argv[0];
	local[1]= fqv[117];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON447;
CON499:
	local[0]= NIL;
CON447:
	w = local[0];
	local[0]= w;
BLK446:
	ctx->vsp=local; return(local[0]);}

/*:draw-faces*/
static pointer M500geometry_viewer_draw_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT504;}
	local[0]= NIL;
ENT504:
	if (n>=5) { local[1]=(argv[4]); goto ENT503;}
	local[1]= NIL;
ENT503:
ENT502:
	if (n>5) maerror();
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO505,env,argv,local);
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)MAPC(ctx,2,local+2); /*mapc*/
	local[0]= w;
BLK501:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO505(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= NIL;
	local[2]= NIL;
	ctx->vsp=local+3;
	w=(*ftab[33])(ctx,3,local+0,&ftab[33],fqv[84]); /*draw-face*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*resetperspective*/
static pointer F205resetperspective(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(5889);
	ctx->vsp=local+1;
	w=(*ftab[23])(ctx,1,local+0,&ftab[23],fqv[72]); /*glmatrixmode*/
	ctx->vsp=local+0;
	w=(*ftab[24])(ctx,0,local+0,&ftab[24],fqv[73]); /*glloadidentity*/
	local[0]= argv[0];
	local[1]= fqv[118];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(10);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)VNORM(ctx,1,local+2); /*norm*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAX(ctx,2,local+1); /*max*/
	local[1]= w;
	local[2]= local[1];
	local[3]= argv[0];
	local[4]= fqv[119];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SCALEVEC(ctx,2,local+2); /*scale*/
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)VPLUS(ctx,2,local+2); /*v+*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[120];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[121];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[37])(ctx,1,local+4,&ftab[37],fqv[122]); /*rad2deg*/
	local[4]= w;
	local[5]= makeflt(1.00000000e+00);
	local[6]= loadglobal(fqv[123]);
	local[7]= loadglobal(fqv[124]);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,4,local+4); /*float-vector*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[38])(ctx,1,local+4,&ftab[38],fqv[125]); /*gluperspectivefv*/
	local[4]= loadglobal(fqv[126]);
	local[5]= local[0];
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)CONCATENATE(ctx,4,local+4); /*concatenate*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[39])(ctx,1,local+4,&ftab[39],fqv[127]); /*glulookatfv*/
	local[0]= makeint(5888);
	ctx->vsp=local+1;
	w=(*ftab[23])(ctx,1,local+0,&ftab[23],fqv[72]); /*glmatrixmode*/
	local[0]= w;
BLK506:
	ctx->vsp=local; return(local[0]);}

/*gldraw*/
static pointer F206gldraw(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST508:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= loadglobal(fqv[128]);
	ctx->vsp=local+3;
	w=(pointer)DERIVEDP(ctx,2,local+1); /*derivedp*/
	if (w==NIL) goto IF509;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	goto IF510;
IF509:
	local[1]= loadglobal(fqv[129]);
IF510:
	local[2]= local[1];
	local[3]= fqv[130];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= local[1];
	local[4]= fqv[131];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)F205resetperspective(ctx,2,local+2); /*resetperspective*/
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[40])(ctx,1,local+2,&ftab[40],fqv[132]); /*cls*/
	local[2]= (pointer)get_sym_func(fqv[133]);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,2,local+2); /*apply*/
	local[2]= local[1]->c.obj.iv[3];
	ctx->vsp=local+3;
	w=(pointer)F207swapb(ctx,1,local+2); /*swapb*/
	local[0]= w;
BLK507:
	ctx->vsp=local; return(local[0]);}

/*swapb*/
static pointer F207swapb(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT513;}
	local[0]= loadglobal(fqv[134]);
ENT513:
ENT512:
	if (n>1) maerror();
	local[1]= local[0];
	local[2]= fqv[135];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[0]= w;
BLK511:
	ctx->vsp=local; return(local[0]);}

/*position-light*/
static pointer F208position_light(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= local[0];
	if (fqv[136]!=local[1]) goto IF516;
	local[1]= makeint(16384);
	local[2]= makeint(4611);
	local[3]= argv[1];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= makeflt(0.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,4,local+3); /*float-vector*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,3,local+1,&ftab[4],fqv[17]); /*gllightfv*/
	local[1]= w;
	goto IF517;
IF516:
	local[1]= local[0];
	if (fqv[137]!=local[1]) goto IF518;
	local[1]= makeint(16385);
	local[2]= makeint(4611);
	local[3]= argv[1];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= makeflt(0.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,4,local+3); /*float-vector*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,3,local+1,&ftab[4],fqv[17]); /*gllightfv*/
	local[1]= w;
	goto IF519;
IF518:
	local[1]= local[0];
	if (fqv[138]!=local[1]) goto IF520;
	local[1]= makeint(16386);
	local[2]= makeint(4611);
	local[3]= argv[1];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= makeflt(0.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,4,local+3); /*float-vector*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,3,local+1,&ftab[4],fqv[17]); /*gllightfv*/
	local[1]= w;
	goto IF521;
IF520:
	local[1]= local[0];
	if (fqv[139]!=local[1]) goto IF522;
	local[1]= makeint(16387);
	local[2]= makeint(4611);
	local[3]= argv[1];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= makeflt(0.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,4,local+3); /*float-vector*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,3,local+1,&ftab[4],fqv[17]); /*gllightfv*/
	local[1]= w;
	goto IF523;
IF522:
	local[1]= local[0];
	if (fqv[140]!=local[1]) goto IF524;
	local[1]= makeint(16388);
	local[2]= makeint(4611);
	local[3]= argv[1];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= makeflt(0.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,4,local+3); /*float-vector*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,3,local+1,&ftab[4],fqv[17]); /*gllightfv*/
	local[1]= w;
	goto IF525;
IF524:
	local[1]= local[0];
	if (fqv[141]!=local[1]) goto IF526;
	local[1]= makeint(16389);
	local[2]= makeint(4611);
	local[3]= argv[1];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= makeflt(0.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,4,local+3); /*float-vector*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,3,local+1,&ftab[4],fqv[17]); /*gllightfv*/
	local[1]= w;
	goto IF527;
IF526:
	local[1]= local[0];
	if (fqv[142]!=local[1]) goto IF528;
	local[1]= makeint(16390);
	local[2]= makeint(4611);
	local[3]= argv[1];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= makeflt(0.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,4,local+3); /*float-vector*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,3,local+1,&ftab[4],fqv[17]); /*gllightfv*/
	local[1]= w;
	goto IF529;
IF528:
	local[1]= local[0];
	if (fqv[143]!=local[1]) goto IF530;
	local[1]= makeint(16391);
	local[2]= makeint(4611);
	local[3]= argv[1];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= makeflt(0.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,4,local+3); /*float-vector*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,3,local+1,&ftab[4],fqv[17]); /*gllightfv*/
	local[1]= w;
	goto IF531;
IF530:
	if (T==NIL) goto IF532;
	local[1]= NIL;
	local[2]= fqv[144];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF533;
IF532:
	local[1]= NIL;
IF533:
IF531:
IF529:
IF527:
IF525:
IF523:
IF521:
IF519:
IF517:
	w = local[1];
	local[0]= w;
BLK514:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___glview(ctx,n,argv,env)
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
	local[0]= fqv[145];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w!=NIL) goto IF534;
	local[0]= fqv[146];
	ctx->vsp=local+1;
	w=(*ftab[41])(ctx,1,local+0,&ftab[41],fqv[147]); /*make-package*/
	local[0]= w;
	goto IF535;
IF534:
	local[0]= NIL;
IF535:
	local[0]= fqv[148];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF536;
	local[0]= fqv[149];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[150],w);
	goto IF537;
IF536:
	local[0]= fqv[151];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF537:
	local[0]= fqv[152];
	local[1]= fqv[153];
	ctx->vsp=local+2;
	w=(*ftab[42])(ctx,2,local+0,&ftab[42],fqv[154]); /*require*/
	local[0]= fqv[155];
	local[1]= fqv[156];
	ctx->vsp=local+2;
	w=(*ftab[42])(ctx,2,local+0,&ftab[42],fqv[154]); /*require*/
	local[0]= fqv[157];
	local[1]= fqv[158];
	ctx->vsp=local+2;
	w=(*ftab[42])(ctx,2,local+0,&ftab[42],fqv[154]); /*require*/
	local[0]= fqv[159];
	local[1]= fqv[160];
	ctx->vsp=local+2;
	w=(*ftab[42])(ctx,2,local+0,&ftab[42],fqv[154]); /*require*/
	local[0]= fqv[161];
	local[1]= fqv[162];
	ctx->vsp=local+2;
	w=(*ftab[42])(ctx,2,local+0,&ftab[42],fqv[154]); /*require*/
	local[0]= fqv[163];
	local[1]= fqv[164];
	ctx->vsp=local+2;
	w=(*ftab[42])(ctx,2,local+0,&ftab[42],fqv[154]); /*require*/
	local[0]= fqv[165];
	local[1]= fqv[166];
	ctx->vsp=local+2;
	w=(*ftab[42])(ctx,2,local+0,&ftab[42],fqv[154]); /*require*/
	local[0]= fqv[167];
	local[1]= fqv[168];
	ctx->vsp=local+2;
	w=(*ftab[42])(ctx,2,local+0,&ftab[42],fqv[154]); /*require*/
	local[0]= fqv[169];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[124];
	local[1]= fqv[170];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF538;
	local[0]= fqv[124];
	local[1]= fqv[170];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[124];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF540;
	local[0]= fqv[124];
	local[1]= fqv[171];
	local[2]= makeflt(3.00000000e+04);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF541;
IF540:
	local[0]= NIL;
IF541:
	local[0]= fqv[124];
	goto IF539;
IF538:
	local[0]= NIL;
IF539:
	local[0]= fqv[123];
	local[1]= fqv[170];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF542;
	local[0]= fqv[123];
	local[1]= fqv[170];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[123];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF544;
	local[0]= fqv[123];
	local[1]= fqv[171];
	local[2]= makeflt(2.00000000e+02);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF545;
IF544:
	local[0]= NIL;
IF545:
	local[0]= fqv[123];
	goto IF543;
IF542:
	local[0]= NIL;
IF543:
	local[0]= fqv[45];
	local[1]= fqv[170];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF546;
	local[0]= fqv[45];
	local[1]= fqv[170];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[45];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF548;
	local[0]= fqv[45];
	local[1]= fqv[171];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF549;
IF548:
	local[0]= NIL;
IF549:
	local[0]= fqv[45];
	goto IF547;
IF546:
	local[0]= NIL;
IF547:
	local[0]= fqv[46];
	local[1]= fqv[170];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF550;
	local[0]= fqv[46];
	local[1]= fqv[170];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[46];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF552;
	local[0]= fqv[46];
	local[1]= fqv[171];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF553;
IF552:
	local[0]= NIL;
IF553:
	local[0]= fqv[46];
	goto IF551;
IF550:
	local[0]= NIL;
IF551:
	local[0]= fqv[47];
	local[1]= fqv[170];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF554;
	local[0]= fqv[47];
	local[1]= fqv[170];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[47];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF556;
	local[0]= fqv[47];
	local[1]= fqv[171];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF557;
IF556:
	local[0]= NIL;
IF557:
	local[0]= fqv[47];
	goto IF555;
IF554:
	local[0]= NIL;
IF555:
	local[0]= fqv[27];
	local[1]= fqv[170];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF558;
	local[0]= fqv[27];
	local[1]= fqv[170];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[27];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF560;
	local[0]= fqv[27];
	local[1]= fqv[171];
	local[2]= makeint(4);
	local[3]= makeint(8);
	local[4]= makeint(1);
	local[5]= makeint(9);
	local[6]= makeint(1);
	local[7]= makeint(10);
	local[8]= makeint(1);
	local[9]= makeint(5);
	local[10]= makeint(12);
	local[11]= makeint(1);
	local[12]= makeint(0);
	ctx->vsp=local+13;
	w=(pointer)MKINTVECTOR(ctx,11,local+2); /*integer-vector*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF561;
IF560:
	local[0]= NIL;
IF561:
	local[0]= fqv[27];
	goto IF559;
IF558:
	local[0]= NIL;
IF559:
	local[0]= fqv[172];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M209colormaterial_create,fqv[32],fqv[99],fqv[173]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M221colormaterial_ambient,fqv[41],fqv[99],fqv[174]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M233colormaterial_diffuse,fqv[42],fqv[99],fqv[175]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M245colormaterial_specular,fqv[43],fqv[99],fqv[176]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M257colormaterial_emission,fqv[177],fqv[99],fqv[178]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M269colormaterial_shininess,fqv[179],fqv[99],fqv[180]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M277colormaterial_transparency,fqv[181],fqv[99],fqv[182]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M285colormaterial_opengl,fqv[48],fqv[99],fqv[183]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M287lightsource_create,fqv[32],fqv[40],fqv[184]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M293lightsource_light_id,fqv[14],fqv[40],fqv[185]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M295lightsource_ambient,fqv[41],fqv[40],fqv[186]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M307lightsource_diffuse,fqv[42],fqv[40],fqv[187]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M319lightsource_specular,fqv[43],fqv[40],fqv[188]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M331lightsource_position,fqv[44],fqv[40],fqv[189]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M338lightsource_move,fqv[190],fqv[40],fqv[191]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M340lightsource_enable,fqv[192],fqv[40],fqv[193]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M342lightsource_disable,fqv[194],fqv[40],fqv[195]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M344lightsource_opengl,fqv[48],fqv[40],fqv[196]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M346glviewsurface_create,fqv[32],fqv[86],fqv[197]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M359glviewsurface_material,fqv[198],fqv[86],fqv[199]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M368glviewsurface_color,fqv[100],fqv[86],fqv[200]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M379glviewsurface_window,fqv[201],fqv[86],fqv[202]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M381glviewsurface_3d_mode,fqv[39],fqv[86],fqv[203]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M385glviewsurface_2d_mode,fqv[79],fqv[86],fqv[204]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M392glviewsurface_pop_mode,fqv[82],fqv[86],fqv[205]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M394glviewsurface_height,fqv[24],fqv[86],fqv[206]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M400glviewsurface_width,fqv[23],fqv[86],fqv[207]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M406glviewsurface_pos,fqv[208],fqv[86],fqv[209]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M408glviewsurface_x,fqv[21],fqv[86],fqv[210]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M414glviewsurface_y,fqv[22],fqv[86],fqv[211]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M420glviewsurface_clear,fqv[212],fqv[86],fqv[213]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M422glviewsurface_glflush,fqv[135],fqv[86],fqv[214]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M424glviewsurface_point,fqv[87],fqv[86],fqv[215]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M426glviewsurface_line,fqv[88],fqv[86],fqv[216]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M428glviewsurface_3d_point,fqv[217],fqv[86],fqv[218]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M430glviewsurface_3d_line,fqv[92],fqv[86],fqv[219]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M432glviewsurface_draw_faces,fqv[111],fqv[86],fqv[220]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M435glviewsurface_rectangle,fqv[89],fqv[86],fqv[221]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[222],module,F204geometry__default_viewsurface,fqv[223]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M439glviewsurface_draw_point,fqv[224],fqv[86],fqv[225]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M441glviewsurface_draw_line,fqv[226],fqv[86],fqv[227]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M443glviewsurface_draw_rectangle,fqv[228],fqv[86],fqv[229]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M445geometry_viewer_draw_one,fqv[94],fqv[128],fqv[230]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M500geometry_viewer_draw_faces,fqv[111],fqv[128],fqv[231]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[232],module,F205resetperspective,fqv[233]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[234],module,F206gldraw,fqv[235]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[236],module,F207swapb,fqv[237]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[238],module,F208position_light,fqv[239]);
	local[0]= fqv[240];
	local[1]= fqv[241];
	ctx->vsp=local+2;
	w=(*ftab[43])(ctx,2,local+0,&ftab[43],fqv[242]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<44; i++) ftab[i]=fcallx;
}
