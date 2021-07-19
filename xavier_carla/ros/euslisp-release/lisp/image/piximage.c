/* ./piximage.c :  entry=piximage */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "piximage.h"
#pragma init (register_piximage)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___piximage();
extern pointer build_quote_vector();
static int register_piximage()
  { add_module_initializer("___piximage", ___piximage);}

static pointer F199make_equilevel_lut();
static pointer F200look_up2();
static pointer F201look_up_();
static pointer F202concatenate_lut();
static pointer F203color_32to24();
static pointer F204color_24to32();
static pointer F205color_24to8();
static pointer F206color_24to16();
static pointer F207color_32to8();
static pointer F208color_24to6();
static pointer F209color_32to8x3();
static pointer F210color_24to8x3();
static pointer F211swap_rgb();
static pointer F212color_to_deep();
static pointer F213copy_color_map();
static pointer F214make_ximage();
static pointer F215make_colors();

/*make-equilevel-lut*/
static pointer F199make_equilevel_lut(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT218;}
	local[0]= makeint(256);
ENT218:
ENT217:
	if (n>2) maerror();
	local[1]= loadglobal(fqv[0]);
	local[2]= makeint(256);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,2,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	local[3]= makeint(0);
	local[4]= makeint(0);
	local[5]= argv[0];
WHL220:
	local[6]= local[4];
	w = local[5];
	if ((eusinteger_t)local[6] >= (eusinteger_t)w) goto WHX221;
	local[6]= makeint(0);
	local[7]= local[2];
WHL224:
	local[8]= local[6];
	w = local[7];
	if ((eusinteger_t)local[8] >= (eusinteger_t)w) goto WHX225;
	local[8]= local[1];
	local[9]= local[3];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)ASET(ctx,3,local+8); /*aset*/
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[3] = w;
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[6] = w;
	goto WHL224;
WHX225:
	local[8]= NIL;
BLK226:
	w = NIL;
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[4] = w;
	goto WHL220;
WHX221:
	local[6]= NIL;
BLK222:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK216:
	ctx->vsp=local; return(local[0]);}

/*look-up2*/
static pointer F200look_up2(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	if (argv[1]!=NIL) goto IF228;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)GETCLASS(ctx,1,local+0); /*class*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[1]); /*make-sequence*/
	argv[1] = w;
	local[0]= argv[1];
	goto IF229;
IF228:
	local[0]= NIL;
IF229:
	local[0]= makeint(0);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
WHL231:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX232;
	local[2]= argv[1];
	local[3]= local[0];
	local[4]= argv[3];
	local[5]= argv[2];
	local[6]= argv[0];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL231;
WHX232:
	local[2]= NIL;
BLK233:
	w = NIL;
	w = argv[1];
	local[0]= w;
BLK227:
	ctx->vsp=local; return(local[0]);}

/*look-up**/
static pointer F201look_up_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	if (argv[1]!=NIL) goto IF235;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)GETCLASS(ctx,1,local+2); /*class*/
	local[2]= w;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,2,local+2,&ftab[0],fqv[1]); /*make-sequence*/
	argv[1] = w;
	local[2]= argv[1];
	goto IF236;
IF235:
	local[2]= NIL;
IF236:
	local[2]= makeint(0);
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
WHL238:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX239;
	local[4]= argv[0];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[1] = w;
	local[4]= NIL;
	local[5]= argv[2];
WHL242:
	if (local[5]==NIL) goto WHX243;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[4];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[1] = w;
	goto WHL242;
WHX243:
	local[6]= NIL;
BLK244:
	w = NIL;
	local[4]= argv[1];
	local[5]= local[2];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL238;
WHX239:
	local[4]= NIL;
BLK240:
	w = NIL;
	w = argv[1];
	local[0]= w;
BLK234:
	ctx->vsp=local; return(local[0]);}

/*concatenate-lut*/
static pointer F202concatenate_lut(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT248;}
	local[0]= makeint(256);
ENT248:
ENT247:
	if (n>3) maerror();
	local[1]= loadglobal(fqv[0]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[1]); /*make-sequence*/
	local[1]= w;
	local[2]= makeint(0);
	local[3]= makeint(256);
WHL250:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX251;
	local[4]= local[1];
	local[5]= local[2];
	local[6]= argv[1];
	local[7]= argv[0];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,2,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL250;
WHX251:
	local[4]= NIL;
BLK252:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK246:
	ctx->vsp=local; return(local[0]);}

/*:entity*/
static pointer M253image_2d_entity(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK254:
	ctx->vsp=local; return(local[0]);}

/*:width*/
static pointer M255image_2d_width(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK256:
	ctx->vsp=local; return(local[0]);}

/*:height*/
static pointer M257image_2d_height(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK258:
	ctx->vsp=local; return(local[0]);}

/*:size*/
static pointer M259image_2d_size(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
BLK260:
	ctx->vsp=local; return(local[0]);}

/*:pixel*/
static pointer M261image_2d_pixel(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= argv[3];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,3,local+0); /*aref*/
	local[0]= w;
BLK262:
	ctx->vsp=local; return(local[0]);}

/*:set-pixel*/
static pointer M263image_2d_set_pixel(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= argv[3];
	local[2]= argv[2];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,4,local+0); /*aset*/
	local[0]= w;
BLK264:
	ctx->vsp=local; return(local[0]);}

/*:duplicate*/
static pointer M265image_2d_duplicate(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST267:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)GETCLASS(ctx,1,local+1); /*class*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= (pointer)get_sym_func(fqv[2]);
	local[3]= local[1];
	local[4]= fqv[3];
	local[5]= argv[0];
	local[6]= fqv[4];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= argv[0];
	local[7]= fqv[5];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,6,local+2); /*apply*/
	w = local[1];
	local[0]= w;
BLK266:
	ctx->vsp=local; return(local[0]);}

/*:copy-from*/
static pointer M269image_2d_copy_from(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[6]); /*replace*/
	w = argv[0];
	local[0]= w;
BLK270:
	ctx->vsp=local; return(local[0]);}

/*:copy*/
static pointer M271image_2d_copy(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)COPYOBJ(ctx,1,local+0); /*copy-object*/
	local[0]= w;
BLK272:
	ctx->vsp=local; return(local[0]);}

/*:hex*/
static pointer M273image_2d_hex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT280;}
	local[0]= makeint(0);
ENT280:
	if (n>=4) { local[1]=(argv[3]); goto ENT279;}
	local[1]= makeint(0);
ENT279:
	if (n>=5) { local[2]=(argv[4]); goto ENT278;}
	local[2]= makeint(8);
ENT278:
	if (n>=6) { local[3]=(argv[5]); goto ENT277;}
	local[3]= makeint(8);
ENT277:
	if (n>=7) { local[4]=(argv[6]); goto ENT276;}
	local[4]= T;
ENT276:
ENT275:
	if (n>7) maerror();
	local[5]= makeint(0);
	local[6]= local[3];
WHL282:
	local[7]= local[5];
	w = local[6];
	if ((eusinteger_t)local[7] >= (eusinteger_t)w) goto WHX283;
	local[7]= local[4];
	local[8]= fqv[7];
	local[9]= local[1];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= makeint(0);
	local[8]= local[2];
WHL286:
	local[9]= local[7];
	w = local[8];
	if ((eusinteger_t)local[9] >= (eusinteger_t)w) goto WHX287;
	local[9]= local[4];
	local[10]= fqv[8];
	local[11]= argv[0];
	local[12]= fqv[9];
	local[13]= local[0];
	local[14]= local[7];
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,2,local+13); /*+*/
	local[13]= w;
	local[14]= local[1];
	local[15]= local[5];
	ctx->vsp=local+16;
	w=(pointer)PLUS(ctx,2,local+14); /*+*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,4,local+11); /*send*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,3,local+9); /*format*/
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	local[7] = w;
	goto WHL286;
WHX287:
	local[9]= NIL;
BLK288:
	w = NIL;
	local[7]= local[4];
	local[8]= fqv[10];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,2,local+7); /*format*/
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[5] = w;
	goto WHL282;
WHX283:
	local[7]= NIL;
BLK284:
	w = NIL;
	local[0]= w;
BLK274:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M289image_2d_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST291:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	local[1]= (pointer)get_sym_func(fqv[11]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[12]));
	local[4]= fqv[13];
	local[5]= argv[2];
	local[6]= NIL;
	local[7]= fqv[14];
	local[8]= argv[0];
	local[9]= fqv[4];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= argv[0];
	local[10]= fqv[5];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,4,local+6); /*format*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,7,local+1); /*apply*/
	local[0]= w;
BLK290:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M292image_2d_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT296;}
	local[0]= NIL;
ENT296:
	if (n>=6) { local[1]=(argv[5]); goto ENT295;}
	local[1]= makeint(8);
ENT295:
ENT294:
	if (n>6) maerror();
	if (local[0]!=NIL) goto IF297;
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= fqv[15];
	local[4]= local[1];
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)NUMEQUAL(ctx,2,local+4); /*=*/
	if (w==NIL) goto CON300;
	local[4]= fqv[16];
	goto CON299;
CON300:
	local[4]= local[1];
	local[5]= makeint(8);
	ctx->vsp=local+6;
	w=(pointer)LSEQP(ctx,2,local+4); /*<=*/
	if (w==NIL) goto CON301;
	local[4]= fqv[17];
	goto CON299;
CON301:
	local[4]= local[1];
	local[5]= makeint(32);
	ctx->vsp=local+6;
	w=(pointer)LSEQP(ctx,2,local+4); /*<=*/
	if (w==NIL) goto CON302;
	local[4]= fqv[18];
	goto CON299;
CON302:
	local[4]= fqv[19];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,1,local+4); /*error*/
	local[4]= w;
	goto CON299;
CON303:
	local[4]= NIL;
CON299:
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,3,local+2,&ftab[2],fqv[20]); /*make-array*/
	local[0] = w;
	local[2]= local[0];
	goto IF298;
IF297:
	local[2]= NIL;
IF298:
	argv[0]->c.obj.iv[2] = makeint(2);
	argv[0]->c.obj.iv[4] = makeint(0);
	argv[0]->c.obj.iv[12] = local[1];
	argv[0]->c.obj.iv[6] = argv[2];
	argv[0]->c.obj.iv[5] = argv[3];
	argv[0]->c.obj.iv[1] = local[0];
	w = argv[0];
	local[0]= w;
BLK293:
	ctx->vsp=local; return(local[0]);}

/*:fill*/
static pointer M304image_2d_fill(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,2,local+0,&ftab[3],fqv[21]); /*fill*/
	w = argv[2];
	local[0]= w;
BLK305:
	ctx->vsp=local; return(local[0]);}

/*:clear*/
static pointer M306image_2d_clear(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[22];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK307:
	ctx->vsp=local; return(local[0]);}

/*:transpose*/
static pointer M308image_2d_transpose(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT311;}
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)GETCLASS(ctx,1,local+0); /*class*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[3];
	local[3]= argv[0];
	local[4]= fqv[5];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[4];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
ENT311:
ENT310:
	if (n>3) maerror();
	local[1]= makeint(0);
	local[2]= argv[0]->c.obj.iv[6];
WHL314:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX315;
	local[3]= makeint(0);
	local[4]= argv[0]->c.obj.iv[5];
WHL318:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX319;
	local[5]= local[0];
	local[6]= fqv[23];
	local[7]= local[1];
	local[8]= local[3];
	local[9]= argv[0];
	local[10]= fqv[24];
	local[11]= local[3];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,4,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL318;
WHX319:
	local[5]= NIL;
BLK320:
	w = NIL;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL314;
WHX315:
	local[3]= NIL;
BLK316:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK309:
	ctx->vsp=local; return(local[0]);}

/*:map-picture*/
static pointer M321image_2d_map_picture(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT324;}
	local[0]= argv[0];
	local[1]= fqv[25];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
ENT324:
ENT323:
	if (n>4) maerror();
	local[1]= local[0]->c.obj.iv[1];
	local[2]= makeint(0);
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
WHL326:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX327;
	local[4]= local[1];
	local[5]= local[2];
	local[6]= argv[2];
	local[7]= argv[0]->c.obj.iv[1];
	{ register eusinteger_t i=intval(local[2]);
	  w=makeint(local[7]->c.str.chars[i]);}
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[5]); v=local[4];
	  v->c.str.chars[i]=intval(w);}
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL326;
WHX327:
	local[4]= NIL;
BLK328:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK322:
	ctx->vsp=local; return(local[0]);}

/*:map*/
static pointer M329image_2d_map(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT332;}
	local[0]= argv[0];
	local[1]= fqv[25];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
ENT332:
ENT331:
	if (n>4) maerror();
	local[1]= local[0]->c.obj.iv[1];
	local[2]= makeint(0);
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
WHL334:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX335;
	local[4]= local[1];
	local[5]= local[2];
	local[6]= argv[2];
	local[7]= argv[0]->c.obj.iv[1];
	{ register eusinteger_t i=intval(local[2]);
	  w=makeint(local[7]->c.str.chars[i]);}
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)FUNCALL(ctx,2,local+6); /*funcall*/
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[5]); v=local[4];
	  v->c.str.chars[i]=intval(w);}
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL334;
WHX335:
	local[4]= NIL;
BLK336:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK330:
	ctx->vsp=local; return(local[0]);}

/*:pixel*/
static pointer M337single_channel_image_pixel(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[3];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,3,local+0); /*aref*/
	local[0]= w;
BLK338:
	ctx->vsp=local; return(local[0]);}

/*:set-pixel*/
static pointer M339single_channel_image_set_pixel(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[3];
	local[2]= argv[2];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,4,local+0); /*aset*/
	local[0]= w;
BLK340:
	ctx->vsp=local; return(local[0]);}

/*:pixel-hex-string*/
static pointer M341single_channel_image_pixel_hex_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= fqv[26];
	local[2]= argv[0];
	local[3]= fqv[24];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK342:
	ctx->vsp=local; return(local[0]);}

/*:halve*/
static pointer M343single_channel_image_halve(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT346;}
	local[0]= NIL;
ENT346:
ENT345:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[4];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= makeint(2);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	if (local[0]!=NIL) goto IF347;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)GETCLASS(ctx,1,local+3); /*class*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[3];
	local[6]= local[1];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = local[3];
	local[0] = w;
	local[3]= local[0];
	goto IF348;
IF347:
	local[3]= NIL;
IF348:
	local[3]= argv[0];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[27]); /*halve-image*/
	w = local[0];
	local[0]= w;
BLK344:
	ctx->vsp=local; return(local[0]);}

/*:double*/
static pointer M350single_channel_image_double(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT353;}
	local[0]= NIL;
ENT353:
ENT352:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[4];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= makeint(2);
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	if (local[0]!=NIL) goto IF354;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)GETCLASS(ctx,1,local+3); /*class*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[3];
	local[6]= local[1];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = local[3];
	local[0] = w;
	local[3]= local[0];
	goto IF355;
IF354:
	local[3]= NIL;
IF355:
	local[3]= argv[0];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[5])(ctx,2,local+3,&ftab[5],fqv[28]); /*double-image*/
	w = local[0];
	local[0]= w;
BLK351:
	ctx->vsp=local; return(local[0]);}

/*:patch-in*/
static pointer M357single_channel_image_patch_in(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= fqv[4];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[5];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[4];
	local[3]= fqv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[4]->c.obj.iv[1];
	local[4]= NIL;
	local[5]= NIL;
	local[6]= makeint(0);
	local[7]= argv[4];
	local[8]= fqv[5];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
WHL360:
	local[8]= local[6];
	w = local[7];
	if ((eusinteger_t)local[8] >= (eusinteger_t)w) goto WHX361;
	local[8]= argv[3];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[4] = w;
	local[8]= argv[0]->c.obj.iv[1];
	local[9]= local[3];
	local[10]= fqv[29];
	local[11]= local[4];
	local[12]= fqv[30];
	local[13]= local[4];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,2,local+13); /*+*/
	local[13]= w;
	local[14]= fqv[31];
	local[15]= local[6];
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)TIMES(ctx,2,local+15); /***/
	local[15]= w;
	ctx->vsp=local+16;
	w=(*ftab[1])(ctx,8,local+8,&ftab[1],fqv[6]); /*replace*/
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[6] = w;
	goto WHL360;
WHX361:
	local[8]= NIL;
BLK362:
	w = NIL;
	local[0]= w;
BLK358:
	ctx->vsp=local; return(local[0]);}

/*:xpicture*/
static pointer M363single_channel_image_xpicture(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT366;}
	local[0]= NIL;
ENT366:
ENT365:
	if (n>3) maerror();
	if (loadglobal(fqv[32])!=NIL) goto IF367;
	local[1]= loadglobal(fqv[33]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[3];
	local[4]= argv[0]->c.obj.iv[6];
	local[5]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[1]= w;
	storeglobal(fqv[32],w);
	goto IF368;
IF367:
	local[1]= NIL;
IF368:
	if (local[0]!=NIL) goto IF370;
	local[1]= argv[0];
	local[2]= fqv[34];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[0] = w;
	local[1]= local[0];
	goto IF371;
IF370:
	local[1]= NIL;
IF371:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= loadglobal(fqv[32])->c.obj.iv[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,3,local+1,&ftab[6],fqv[35]); /*look-up*/
	w = loadglobal(fqv[32]);
	local[0]= w;
BLK364:
	ctx->vsp=local; return(local[0]);}

/*:display-lut*/
static pointer M372single_channel_image_display_lut(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT375;}
	local[0]= NIL;
ENT375:
ENT374:
	if (n>3) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)VECTORP(ctx,1,local+1); /*vectorp*/
	if (w==NIL) goto IF376;
	local[1]= argv[0];
	local[2]= fqv[36];
	local[3]= local[0];
	storeglobal(fqv[37],local[3]);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF377;
IF376:
	local[1]= NIL;
IF377:
	if (loadglobal(fqv[37])==NIL) goto IF378;
	local[1]= loadglobal(fqv[37]);
	goto IF379;
IF378:
	local[1]= loadglobal(fqv[38]);
IF379:
	w = local[1];
	local[0]= w;
BLK373:
	ctx->vsp=local; return(local[0]);}

/*:display*/
static pointer M380single_channel_image_display(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT386;}
	local[0]= loadglobal(fqv[39]);
ENT386:
	if (n>=4) { local[1]=(argv[3]); goto ENT385;}
	local[1]= NIL;
ENT385:
	if (n>=5) { local[2]=(argv[4]); goto ENT384;}
	local[2]= makeint(0);
ENT384:
	if (n>=6) { local[3]=(argv[5]); goto ENT383;}
	local[3]= makeint(0);
ENT383:
ENT382:
	if (n>6) maerror();
	local[4]= local[0];
	local[5]= fqv[40];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[4];
	local[6]= local[5];
	if (fqv[41]!=local[6]) goto IF388;
	local[6]= local[0];
	local[7]= fqv[42];
	if (loadglobal(fqv[32])==NIL) goto IF390;
	local[8]= argv[0];
	local[9]= fqv[36];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w->c.obj.iv[1];
	goto IF391;
IF390:
	local[8]= argv[0]->c.obj.iv[1];
IF391:
	local[9]= fqv[43];
	local[10]= local[2];
	local[11]= fqv[44];
	local[12]= local[3];
	local[13]= fqv[4];
	local[14]= argv[0]->c.obj.iv[6];
	local[15]= fqv[5];
	local[16]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,11,local+6); /*send*/
	local[6]= w;
	goto IF389;
IF388:
	local[6]= local[5];
	if (fqv[45]!=local[6]) goto IF392;
	local[6]= local[0];
	local[7]= fqv[42];
	local[8]= argv[0];
	local[9]= fqv[46];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	goto IF393;
IF392:
	local[6]= local[5];
	if (fqv[47]!=local[6]) goto IF394;
	local[6]= local[0];
	local[7]= fqv[42];
	local[8]= argv[0];
	local[9]= fqv[48];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	goto IF395;
IF394:
	local[6]= local[5];
	if (fqv[49]!=local[6]) goto IF396;
	local[6]= local[0];
	local[7]= fqv[42];
	local[8]= argv[0];
	local[9]= fqv[50];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	goto IF397;
IF396:
	if (T==NIL) goto IF398;
	local[6]= fqv[51];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(*ftab[7])(ctx,2,local+6,&ftab[7],fqv[52]); /*warn*/
	local[6]= w;
	goto IF399;
IF398:
	local[6]= NIL;
IF399:
IF397:
IF395:
IF393:
IF389:
	w = local[6];
	w = argv[0];
	local[0]= w;
BLK381:
	ctx->vsp=local; return(local[0]);}

/*:subimage*/
static pointer M400single_channel_image_subimage(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[4];
	local[1]= argv[5];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[8])(ctx,1,local+0,&ftab[8],fqv[53]); /*make-string*/
	local[0]= w;
	local[1]= makeint(0);
	local[2]= argv[5];
WHL403:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX404;
	local[3]= local[0];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= fqv[29];
	local[6]= local[1];
	local[7]= argv[4];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	local[7]= fqv[30];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[8]= w;
	local[9]= argv[4];
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	local[9]= fqv[31];
	local[10]= argv[3];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[10]= w;
	local[11]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	local[11]= argv[2];
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[1])(ctx,8,local+3,&ftab[1],fqv[6]); /*replace*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL403;
WHX404:
	local[3]= NIL;
BLK405:
	w = NIL;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)GETCLASS(ctx,1,local+1); /*class*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[3];
	local[4]= argv[4];
	local[5]= argv[5];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK401:
	ctx->vsp=local; return(local[0]);}

/*:patch-in*/
static pointer M407single_channel_image_patch_in(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= fqv[4];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[5];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[4];
	local[3]= fqv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[4]->c.obj.iv[1];
	local[4]= NIL;
	local[5]= NIL;
	local[6]= makeint(0);
	local[7]= argv[4];
	local[8]= fqv[5];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
WHL410:
	local[8]= local[6];
	w = local[7];
	if ((eusinteger_t)local[8] >= (eusinteger_t)w) goto WHX411;
	local[8]= argv[3];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[4] = w;
	local[8]= argv[0]->c.obj.iv[1];
	local[9]= local[3];
	local[10]= fqv[29];
	local[11]= local[4];
	local[12]= fqv[30];
	local[13]= local[4];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,2,local+13); /*+*/
	local[13]= w;
	local[14]= fqv[31];
	local[15]= local[6];
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)TIMES(ctx,2,local+15); /***/
	local[15]= w;
	ctx->vsp=local+16;
	w=(*ftab[1])(ctx,8,local+8,&ftab[1],fqv[6]); /*replace*/
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[6] = w;
	goto WHL410;
WHX411:
	local[8]= NIL;
BLK412:
	w = NIL;
	local[0]= w;
BLK408:
	ctx->vsp=local; return(local[0]);}

/*:brightest-pixel*/
static pointer M413single_channel_image_brightest_pixel(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(0);
	local[1]= makeint(0);
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
WHL416:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX417;
	local[3]= argv[0]->c.obj.iv[1];
	{ register eusinteger_t i=intval(local[1]);
	  w=makeint(local[3]->c.str.chars[i]);}
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)GREATERP(ctx,2,local+3); /*>*/
	if (w==NIL) goto IF419;
	local[3]= argv[0]->c.obj.iv[1];
	{ register eusinteger_t i=intval(local[1]);
	  w=makeint(local[3]->c.str.chars[i]);}
	local[0] = w;
	local[3]= local[0];
	goto IF420;
IF419:
	local[3]= NIL;
IF420:
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL416;
WHX417:
	local[3]= NIL;
BLK418:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK414:
	ctx->vsp=local; return(local[0]);}

/*:darkest-pixel*/
static pointer M421single_channel_image_darkest_pixel(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(256);
	local[1]= makeint(0);
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
WHL424:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX425;
	local[3]= argv[0]->c.obj.iv[1];
	{ register eusinteger_t i=intval(local[1]);
	  w=makeint(local[3]->c.str.chars[i]);}
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)LESSP(ctx,2,local+3); /*<*/
	if (w==NIL) goto IF427;
	local[3]= argv[0]->c.obj.iv[1];
	{ register eusinteger_t i=intval(local[1]);
	  w=makeint(local[3]->c.str.chars[i]);}
	local[0] = w;
	local[3]= local[0];
	goto IF428;
IF427:
	local[3]= NIL;
IF428:
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL424;
WHX425:
	local[3]= NIL;
BLK426:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK422:
	ctx->vsp=local; return(local[0]);}

/*:average-pixel*/
static pointer M429single_channel_image_average_pixel(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= (pointer)get_sym_func(fqv[54]);
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(*ftab[9])(ctx,2,local+0,&ftab[9],fqv[55]); /*reduce*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)EUSFLOAT(ctx,1,local+0); /*float*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
BLK430:
	ctx->vsp=local; return(local[0]);}

/*:amplify*/
static pointer M431single_channel_image_amplify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT434;}
	local[0]= argv[0];
	local[1]= fqv[25];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
ENT434:
ENT433:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= local[0]->c.obj.iv[1];
	local[3]= makeint(0);
	local[4]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
WHL436:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX437;
	local[5]= local[2];
	local[6]= local[3];
	local[7]= makeint(255);
	local[8]= argv[2];
	local[9]= argv[0]->c.obj.iv[1];
	{ register eusinteger_t i=intval(local[3]);
	  w=makeint(local[9]->c.str.chars[i]);}
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ROUND(ctx,1,local+8); /*round*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MIN(ctx,2,local+7); /*min*/
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[6]); v=local[5];
	  v->c.str.chars[i]=intval(w);}
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL436;
WHX437:
	local[5]= NIL;
BLK438:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK432:
	ctx->vsp=local; return(local[0]);}

/*:compress-gray-scale*/
static pointer M439single_channel_image_compress_gray_scale(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT442;}
	local[0]= NIL;
ENT442:
ENT441:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]!=NIL) goto IF443;
	local[3]= argv[0];
	local[4]= fqv[25];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[0] = w;
	local[3]= local[0];
	local[4]= fqv[56];
	local[5]= NIL;
	local[6]= fqv[57];
	local[7]= argv[0];
	local[8]= fqv[56];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= argv[2];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,4,local+5); /*format*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF444;
IF443:
	local[3]= NIL;
IF444:
	local[2] = local[0]->c.obj.iv[1];
	local[3]= makeint(256);
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	argv[2] = w;
	local[3]= makeint(0);
	local[4]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
WHL446:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX447;
	local[5]= local[2];
	local[6]= local[3];
	local[7]= argv[0]->c.obj.iv[1];
	{ register eusinteger_t i=intval(local[3]);
	  w=makeint(local[7]->c.str.chars[i]);}
	local[7]= w;
	local[8]= argv[2];
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[6]); v=local[5];
	  v->c.str.chars[i]=intval(w);}
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL446;
WHX447:
	local[5]= NIL;
BLK448:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK440:
	ctx->vsp=local; return(local[0]);}

/*:lut*/
static pointer M449single_channel_image_lut(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT452;}
	local[0]= argv[0];
	local[1]= fqv[25];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
ENT452:
ENT451:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= local[0]->c.obj.iv[1];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,3,local+1,&ftab[6],fqv[35]); /*look-up*/
	w = local[0];
	local[0]= w;
BLK450:
	ctx->vsp=local; return(local[0]);}

/*:lut2*/
static pointer M453single_channel_image_lut2(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT456;}
	local[0]= argv[0];
	local[1]= fqv[25];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
ENT456:
ENT455:
	if (n>5) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= local[0]->c.obj.iv[1];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)F200look_up2(ctx,4,local+1); /*look-up2*/
	w = local[0];
	local[0]= w;
BLK454:
	ctx->vsp=local; return(local[0]);}

/*:to24*/
static pointer M457single_channel_image_to24(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[58];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(3);
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[8])(ctx,1,local+0,&ftab[8],fqv[53]); /*make-string*/
	local[0]= w;
	local[1]= makeint(0);
	local[2]= argv[0];
	local[3]= fqv[58];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
WHL460:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX461;
	local[3]= argv[0]->c.obj.iv[1];
	{ register eusinteger_t i=intval(local[1]);
	  w=makeint(local[3]->c.str.chars[i]);}
	local[3]= w;
	local[4]= local[1];
	{ eusinteger_t i,j;
		j=intval(makeint(3)); i=intval(local[4]);
		local[4]=(makeint(i * j));}
	local[5]= local[0];
	local[6]= local[4];
	w = local[3];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[6]); v=local[5];
	  v->c.str.chars[i]=intval(w);}
	local[5]= local[0];
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[6]= w;
	w = local[3];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[6]); v=local[5];
	  v->c.str.chars[i]=intval(w);}
	local[5]= local[0];
	local[6]= local[4];
	local[7]= makeint(2);
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	w = local[3];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[6]); v=local[5];
	  v->c.str.chars[i]=intval(w);}
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL460;
WHX461:
	local[3]= NIL;
BLK462:
	w = NIL;
	local[1]= loadglobal(fqv[59]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[3];
	local[4]= argv[0];
	local[5]= fqv[4];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[5];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK458:
	ctx->vsp=local; return(local[0]);}

/*:to32*/
static pointer M464single_channel_image_to32(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[48];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[50];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK465:
	ctx->vsp=local; return(local[0]);}

/*:to16*/
static pointer M466single_channel_image_to16(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[48];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[46];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK467:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M468bitmap_image_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT471;}
	local[0]= NIL;
ENT471:
ENT470:
	if (n>5) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[12]));
	local[3]= fqv[3];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= local[0];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)SENDMESSAGE(ctx,7,local+1); /*send-message*/
	local[0]= w;
BLK469:
	ctx->vsp=local; return(local[0]);}

/*:pixel-hex-string*/
static pointer M472bitmap_image_pixel_hex_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= fqv[60];
	local[2]= argv[0];
	local[3]= fqv[24];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK473:
	ctx->vsp=local; return(local[0]);}

/*color-32to24*/
static pointer F203color_32to24(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT476;}
	local[0]= argv[1];
	local[1]= argv[2];
	{ eusinteger_t i,j;
		j=intval(makeint(3)); i=intval(local[1]);
		local[1]=(makeint(i * j));}
	{ eusinteger_t i,j;
		j=intval(local[1]); i=intval(local[0]);
		local[0]=(makeint(i * j));}
	ctx->vsp=local+1;
	w=(*ftab[8])(ctx,1,local+0,&ftab[8],fqv[53]); /*make-string*/
	local[0]= w;
ENT476:
ENT475:
	if (n>4) maerror();
	local[1]= makeint(0);
	local[2]= makeint(0);
	local[3]= makeint(0);
	local[4]= argv[1];
	{ eusinteger_t i,j;
		j=intval(argv[2]); i=intval(local[4]);
		local[4]=(makeint(i * j));}
WHL478:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX479;
	local[5]= local[0];
	local[6]= local[2];
	local[7]= argv[0];
	local[8]= local[1];
	w = makeint(1);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	{ register eusinteger_t i=intval((pointer)((eusinteger_t)local[8] + (eusinteger_t)w));
	  w=makeint(local[7]->c.str.chars[i]);}
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[6]); v=local[5];
	  v->c.str.chars[i]=intval(w);}
	local[5]= local[0];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= local[1];
	w = makeint(2);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	{ register eusinteger_t i=intval((pointer)((eusinteger_t)local[8] + (eusinteger_t)w));
	  w=makeint(local[7]->c.str.chars[i]);}
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[6]); v=local[5];
	  v->c.str.chars[i]=intval(w);}
	local[5]= local[0];
	local[6]= local[2];
	w = makeint(2);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[6]= (pointer)((eusinteger_t)local[6] + (eusinteger_t)w);
	local[7]= argv[0];
	local[8]= local[1];
	w = makeint(3);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	{ register eusinteger_t i=intval((pointer)((eusinteger_t)local[8] + (eusinteger_t)w));
	  w=makeint(local[7]->c.str.chars[i]);}
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[6]); v=local[5];
	  v->c.str.chars[i]=intval(w);}
	local[5]= local[1];
	w = makeint(4);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[1] = (pointer)((eusinteger_t)local[5] + (eusinteger_t)w);
	local[5]= local[2];
	w = makeint(3);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[2] = (pointer)((eusinteger_t)local[5] + (eusinteger_t)w);
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL478;
WHX479:
	local[5]= NIL;
BLK480:
	w = NIL;
	local[0]= w;
BLK474:
	ctx->vsp=local; return(local[0]);}

/*color-24to32*/
static pointer F204color_24to32(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT483;}
	local[0]= argv[1];
	local[1]= argv[2];
	{ eusinteger_t i,j;
		j=intval(makeint(4)); i=intval(local[1]);
		local[1]=(makeint(i * j));}
	{ eusinteger_t i,j;
		j=intval(local[1]); i=intval(local[0]);
		local[0]=(makeint(i * j));}
	ctx->vsp=local+1;
	w=(*ftab[8])(ctx,1,local+0,&ftab[8],fqv[53]); /*make-string*/
	local[0]= w;
ENT483:
ENT482:
	if (n>4) maerror();
	local[1]= makeint(0);
	local[2]= makeint(0);
	local[3]= makeint(0);
	local[4]= argv[1];
	{ eusinteger_t i,j;
		j=intval(argv[2]); i=intval(local[4]);
		local[4]=(makeint(i * j));}
WHL485:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX486;
	local[5]= local[0];
	local[6]= local[2];
	w = makeint(2);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[6]= (pointer)((eusinteger_t)local[6] + (eusinteger_t)w);
	local[7]= argv[0];
	local[8]= local[1];
	w = makeint(2);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	{ register eusinteger_t i=intval((pointer)((eusinteger_t)local[8] + (eusinteger_t)w));
	  w=makeint(local[7]->c.str.chars[i]);}
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[6]); v=local[5];
	  v->c.str.chars[i]=intval(w);}
	local[5]= local[0];
	local[6]= local[2];
	w = makeint(1);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[6]= (pointer)((eusinteger_t)local[6] + (eusinteger_t)w);
	local[7]= argv[0];
	local[8]= local[1];
	w = makeint(1);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	{ register eusinteger_t i=intval((pointer)((eusinteger_t)local[8] + (eusinteger_t)w));
	  w=makeint(local[7]->c.str.chars[i]);}
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[6]); v=local[5];
	  v->c.str.chars[i]=intval(w);}
	local[5]= local[0];
	local[6]= local[2];
	w = makeint(0);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[6]= (pointer)((eusinteger_t)local[6] + (eusinteger_t)w);
	local[7]= argv[0];
	local[8]= local[1];
	w = makeint(0);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	{ register eusinteger_t i=intval((pointer)((eusinteger_t)local[8] + (eusinteger_t)w));
	  w=makeint(local[7]->c.str.chars[i]);}
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[6]); v=local[5];
	  v->c.str.chars[i]=intval(w);}
	local[5]= local[1];
	w = makeint(3);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[1] = (pointer)((eusinteger_t)local[5] + (eusinteger_t)w);
	local[5]= local[2];
	w = makeint(4);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[2] = (pointer)((eusinteger_t)local[5] + (eusinteger_t)w);
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL485;
WHX486:
	local[5]= NIL;
BLK487:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK481:
	ctx->vsp=local; return(local[0]);}

/*color-24to8*/
static pointer F205color_24to8(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT491;}
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[10])(ctx,1,local+0,&ftab[10],fqv[61]); /**w*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[8])(ctx,1,local+0,&ftab[8],fqv[53]); /*make-string*/
	local[0]= w;
ENT491:
	if (n>=5) { local[1]=(argv[4]); goto ENT490;}
	local[1]= fqv[62];
ENT490:
ENT489:
	if (n>5) maerror();
	local[2]= NIL;
	local[3]= makeint(0);
	local[4]= makeint(0);
	local[5]= makeint(0);
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= NIL;
	local[15]= NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.car;
WHL492:
	local[16]= local[6];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)LOGTEST(ctx,2,local+16); /*logtest*/
	if (w!=NIL) goto WHX493;
	local[16]= local[3];
	ctx->vsp=local+17;
	w=(pointer)SUB1(ctx,1,local+16); /*1-*/
	local[3] = w;
	local[16]= local[6];
	local[17]= makeint(-1);
	ctx->vsp=local+18;
	w=(pointer)ASH(ctx,2,local+16); /*ash*/
	local[6] = w;
	goto WHL492;
WHX493:
	local[16]= NIL;
BLK494:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.car;
WHL495:
	local[16]= local[9];
	local[17]= makeint(128);
	ctx->vsp=local+18;
	w=(pointer)LOGTEST(ctx,2,local+16); /*logtest*/
	if (w!=NIL) goto WHX496;
	local[16]= local[9];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)ASH(ctx,2,local+16); /*ash*/
	local[9] = w;
	goto WHL495;
WHX496:
	local[16]= NIL;
BLK497:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.car;
WHL498:
	local[16]= local[7];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)LOGTEST(ctx,2,local+16); /*logtest*/
	if (w!=NIL) goto WHX499;
	local[16]= local[4];
	ctx->vsp=local+17;
	w=(pointer)SUB1(ctx,1,local+16); /*1-*/
	local[4] = w;
	local[16]= local[7];
	local[17]= makeint(-1);
	ctx->vsp=local+18;
	w=(pointer)ASH(ctx,2,local+16); /*ash*/
	local[7] = w;
	goto WHL498;
WHX499:
	local[16]= NIL;
BLK500:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.car;
WHL501:
	local[16]= local[10];
	local[17]= makeint(128);
	ctx->vsp=local+18;
	w=(pointer)LOGTEST(ctx,2,local+16); /*logtest*/
	if (w!=NIL) goto WHX502;
	local[16]= local[10];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)ASH(ctx,2,local+16); /*ash*/
	local[10] = w;
	goto WHL501;
WHX502:
	local[16]= NIL;
BLK503:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.car;
WHL504:
	local[16]= local[8];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)LOGTEST(ctx,2,local+16); /*logtest*/
	if (w!=NIL) goto WHX505;
	local[16]= local[5];
	ctx->vsp=local+17;
	w=(pointer)SUB1(ctx,1,local+16); /*1-*/
	local[5] = w;
	local[16]= local[8];
	local[17]= makeint(-1);
	ctx->vsp=local+18;
	w=(pointer)ASH(ctx,2,local+16); /*ash*/
	local[8] = w;
	goto WHL504;
WHX505:
	local[16]= NIL;
BLK506:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.car;
WHL507:
	local[16]= local[11];
	local[17]= makeint(128);
	ctx->vsp=local+18;
	w=(pointer)LOGTEST(ctx,2,local+16); /*logtest*/
	if (w!=NIL) goto WHX508;
	local[16]= local[11];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)ASH(ctx,2,local+16); /*ash*/
	local[11] = w;
	goto WHL507;
WHX508:
	local[16]= NIL;
BLK509:
	local[15] = makeint(0);
	local[16]= makeint(0);
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)LENGTH(ctx,1,local+17); /*length*/
	local[17]= w;
WHL511:
	local[18]= local[16];
	w = local[17];
	if ((eusinteger_t)local[18] >= (eusinteger_t)w) goto WHX512;
	local[18]= local[9];
	local[19]= argv[0];
	{ register eusinteger_t i=intval(local[15]);
	  w=makeint(local[19]->c.str.chars[i]);}
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)LOGAND(ctx,2,local+18); /*logand*/
	local[12] = w;
	local[18]= local[10];
	local[19]= argv[0];
	local[20]= local[15];
	ctx->vsp=local+21;
	w=(pointer)ADD1(ctx,1,local+20); /*1+*/
	local[15] = w;
	{ register eusinteger_t i=intval(local[15]);
	  w=makeint(local[19]->c.str.chars[i]);}
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)LOGAND(ctx,2,local+18); /*logand*/
	local[13] = w;
	local[18]= local[11];
	local[19]= argv[0];
	local[20]= local[15];
	ctx->vsp=local+21;
	w=(pointer)ADD1(ctx,1,local+20); /*1+*/
	local[15] = w;
	{ register eusinteger_t i=intval(local[15]);
	  w=makeint(local[19]->c.str.chars[i]);}
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)LOGAND(ctx,2,local+18); /*logand*/
	local[14] = w;
	local[18]= local[15];
	ctx->vsp=local+19;
	w=(pointer)ADD1(ctx,1,local+18); /*1+*/
	local[15] = w;
	local[18]= local[0];
	local[19]= local[16];
	local[20]= local[12];
	local[21]= local[3];
	ctx->vsp=local+22;
	w=(pointer)ASH(ctx,2,local+20); /*ash*/
	local[20]= w;
	local[21]= local[13];
	local[22]= local[4];
	ctx->vsp=local+23;
	w=(pointer)ASH(ctx,2,local+21); /*ash*/
	local[21]= w;
	local[22]= local[14];
	local[23]= local[5];
	ctx->vsp=local+24;
	w=(pointer)ASH(ctx,2,local+22); /*ash*/
	w = (pointer)((eusinteger_t)local[21] | (eusinteger_t)w);
	w = (pointer)((eusinteger_t)local[20] | (eusinteger_t)w);
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[19]); v=local[18];
	  v->c.str.chars[i]=intval(w);}
	local[18]= local[16];
	ctx->vsp=local+19;
	w=(pointer)ADD1(ctx,1,local+18); /*1+*/
	local[16] = w;
	goto WHL511;
WHX512:
	local[18]= NIL;
BLK513:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK488:
	ctx->vsp=local; return(local[0]);}

/*color-24to16*/
static pointer F206color_24to16(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT517;}
	local[0]= NIL;
ENT517:
	if (n>=5) { local[1]=(argv[4]); goto ENT516;}
	local[1]= fqv[63];
ENT516:
ENT515:
	if (n>5) maerror();
	if (local[0]!=NIL) goto IF518;
	local[2]= makeint(2);
	local[3]= argv[1];
	{ eusinteger_t i,j;
		j=intval(argv[2]); i=intval(local[3]);
		local[3]=(makeint(i * j));}
	{ eusinteger_t i,j;
		j=intval(local[3]); i=intval(local[2]);
		local[2]=(makeint(i * j));}
	ctx->vsp=local+3;
	w=(*ftab[8])(ctx,1,local+2,&ftab[8],fqv[53]); /*make-string*/
	local[0] = w;
	local[2]= local[0];
	goto IF519;
IF518:
	local[2]= NIL;
IF519:
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= makeint(0);
	local[6]= makeint(0);
	local[7]= makeint(0);
	local[8]= makeint(0);
	local[9]= makeint(0);
	local[10]= makeint(0);
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= NIL;
	local[15]= NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
WHL520:
	local[16]= local[2];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)LOGTEST(ctx,2,local+16); /*logtest*/
	if (w!=NIL) goto WHX521;
	local[16]= local[5];
	ctx->vsp=local+17;
	w=(pointer)ADD1(ctx,1,local+16); /*1+*/
	local[5] = w;
	local[16]= local[2];
	local[17]= makeint(-1);
	ctx->vsp=local+18;
	w=(pointer)ASH(ctx,2,local+16); /*ash*/
	local[2] = w;
	goto WHL520;
WHX521:
	local[16]= NIL;
BLK522:
WHL523:
	local[16]= local[2];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)LOGTEST(ctx,2,local+16); /*logtest*/
	if (w==NIL) goto WHX524;
	local[16]= local[8];
	ctx->vsp=local+17;
	w=(pointer)ADD1(ctx,1,local+16); /*1+*/
	local[8] = w;
	local[16]= local[2];
	local[17]= makeint(-1);
	ctx->vsp=local+18;
	w=(pointer)ASH(ctx,2,local+16); /*ash*/
	local[2] = w;
	goto WHL523;
WHX524:
	local[16]= NIL;
BLK525:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
WHL526:
	local[16]= local[3];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)LOGTEST(ctx,2,local+16); /*logtest*/
	if (w!=NIL) goto WHX527;
	local[16]= local[6];
	ctx->vsp=local+17;
	w=(pointer)ADD1(ctx,1,local+16); /*1+*/
	local[6] = w;
	local[16]= local[3];
	local[17]= makeint(-1);
	ctx->vsp=local+18;
	w=(pointer)ASH(ctx,2,local+16); /*ash*/
	local[3] = w;
	goto WHL526;
WHX527:
	local[16]= NIL;
BLK528:
WHL529:
	local[16]= local[3];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)LOGTEST(ctx,2,local+16); /*logtest*/
	if (w==NIL) goto WHX530;
	local[16]= local[9];
	ctx->vsp=local+17;
	w=(pointer)ADD1(ctx,1,local+16); /*1+*/
	local[9] = w;
	local[16]= local[3];
	local[17]= makeint(-1);
	ctx->vsp=local+18;
	w=(pointer)ASH(ctx,2,local+16); /*ash*/
	local[3] = w;
	goto WHL529;
WHX530:
	local[16]= NIL;
BLK531:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.car;
WHL532:
	local[16]= local[4];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)LOGTEST(ctx,2,local+16); /*logtest*/
	if (w!=NIL) goto WHX533;
	local[16]= local[7];
	ctx->vsp=local+17;
	w=(pointer)ADD1(ctx,1,local+16); /*1+*/
	local[7] = w;
	local[16]= local[4];
	local[17]= makeint(-1);
	ctx->vsp=local+18;
	w=(pointer)ASH(ctx,2,local+16); /*ash*/
	local[4] = w;
	goto WHL532;
WHX533:
	local[16]= NIL;
BLK534:
WHL535:
	local[16]= local[4];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)LOGTEST(ctx,2,local+16); /*logtest*/
	if (w==NIL) goto WHX536;
	local[16]= local[10];
	ctx->vsp=local+17;
	w=(pointer)ADD1(ctx,1,local+16); /*1+*/
	local[10] = w;
	local[16]= local[4];
	local[17]= makeint(-1);
	ctx->vsp=local+18;
	w=(pointer)ASH(ctx,2,local+16); /*ash*/
	local[4] = w;
	goto WHL535;
WHX536:
	local[16]= NIL;
BLK537:
	local[15] = makeint(0);
	local[16]= local[8];
	w = makeint(8);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[8] = (pointer)((eusinteger_t)local[16] - (eusinteger_t)w);
	local[16]= local[9];
	w = makeint(8);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[9] = (pointer)((eusinteger_t)local[16] - (eusinteger_t)w);
	local[16]= local[10];
	w = makeint(8);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[10] = (pointer)((eusinteger_t)local[16] - (eusinteger_t)w);
	local[16]= makeint(0);
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)LENGTH(ctx,1,local+17); /*length*/
	local[17]= w;
	local[18]= makeint(2);
	ctx->vsp=local+19;
	w=(pointer)QUOTIENT(ctx,2,local+17); /*/*/
	local[17]= w;
WHL539:
	local[18]= local[16];
	w = local[17];
	if ((eusinteger_t)local[18] >= (eusinteger_t)w) goto WHX540;
	local[18]= argv[0];
	{ register eusinteger_t i=intval(local[15]);
	  w=makeint(local[18]->c.str.chars[i]);}
	local[18]= w;
	local[19]= local[8];
	ctx->vsp=local+20;
	w=(pointer)ASH(ctx,2,local+18); /*ash*/
	local[12] = w;
	local[18]= argv[0];
	local[19]= local[15];
	ctx->vsp=local+20;
	w=(pointer)ADD1(ctx,1,local+19); /*1+*/
	local[15] = w;
	{ register eusinteger_t i=intval(local[15]);
	  w=makeint(local[18]->c.str.chars[i]);}
	local[18]= w;
	local[19]= local[9];
	ctx->vsp=local+20;
	w=(pointer)ASH(ctx,2,local+18); /*ash*/
	local[13] = w;
	local[18]= argv[0];
	local[19]= local[15];
	ctx->vsp=local+20;
	w=(pointer)ADD1(ctx,1,local+19); /*1+*/
	local[15] = w;
	{ register eusinteger_t i=intval(local[15]);
	  w=makeint(local[18]->c.str.chars[i]);}
	local[18]= w;
	local[19]= local[10];
	ctx->vsp=local+20;
	w=(pointer)ASH(ctx,2,local+18); /*ash*/
	local[14] = w;
	local[18]= local[15];
	ctx->vsp=local+19;
	w=(pointer)ADD1(ctx,1,local+18); /*1+*/
	local[15] = w;
	local[18]= local[12];
	local[19]= local[5];
	ctx->vsp=local+20;
	w=(pointer)ASH(ctx,2,local+18); /*ash*/
	local[18]= w;
	local[19]= local[13];
	local[20]= local[6];
	ctx->vsp=local+21;
	w=(pointer)ASH(ctx,2,local+19); /*ash*/
	local[19]= w;
	local[20]= local[14];
	local[21]= local[7];
	ctx->vsp=local+22;
	w=(pointer)ASH(ctx,2,local+20); /*ash*/
	w = (pointer)((eusinteger_t)local[19] | (eusinteger_t)w);
	local[11] = (pointer)((eusinteger_t)local[18] | (eusinteger_t)w);
	local[18]= local[11];
	local[19]= local[0];
	local[20]= local[16];
	{ eusinteger_t i,j;
		j=intval(makeint(2)); i=intval(local[20]);
		local[20]=(makeint(i * j));}
	local[21]= fqv[64];
	ctx->vsp=local+22;
	w=(pointer)POKE(ctx,4,local+18); /*system:poke*/
	local[18]= local[16];
	ctx->vsp=local+19;
	w=(pointer)ADD1(ctx,1,local+18); /*1+*/
	local[16] = w;
	goto WHL539;
WHX540:
	local[18]= NIL;
BLK541:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK514:
	ctx->vsp=local; return(local[0]);}

/*color-32to8*/
static pointer F207color_32to8(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT545;}
	local[0]= argv[1];
	{ eusinteger_t i,j;
		j=intval(argv[2]); i=intval(local[0]);
		local[0]=(makeint(i * j));}
	ctx->vsp=local+1;
	w=(*ftab[8])(ctx,1,local+0,&ftab[8],fqv[53]); /*make-string*/
	local[0]= w;
ENT545:
	if (n>=5) { local[1]=(argv[4]); goto ENT544;}
	local[1]= fqv[65];
ENT544:
ENT543:
	if (n>5) maerror();
	local[2]= NIL;
	local[3]= makeint(0);
	local[4]= makeint(0);
	local[5]= makeint(0);
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= NIL;
	local[15]= NIL;
	local[16]= NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.car;
WHL546:
	local[17]= local[9];
	local[18]= makeint(128);
	ctx->vsp=local+19;
	w=(pointer)LOGTEST(ctx,2,local+17); /*logtest*/
	if (w!=NIL) goto WHX547;
	local[17]= local[9];
	local[18]= makeint(1);
	ctx->vsp=local+19;
	w=(pointer)ASH(ctx,2,local+17); /*ash*/
	local[9] = w;
	goto WHL546;
WHX547:
	local[17]= NIL;
BLK548:
WHL549:
	local[17]= local[10];
	local[18]= makeint(128);
	ctx->vsp=local+19;
	w=(pointer)LOGTEST(ctx,2,local+17); /*logtest*/
	if (w!=NIL) goto WHX550;
	local[17]= local[10];
	local[18]= makeint(1);
	ctx->vsp=local+19;
	w=(pointer)ASH(ctx,2,local+17); /*ash*/
	local[10] = w;
	goto WHL549;
WHX550:
	local[17]= NIL;
BLK551:
WHL552:
	local[17]= local[11];
	local[18]= makeint(128);
	ctx->vsp=local+19;
	w=(pointer)LOGTEST(ctx,2,local+17); /*logtest*/
	if (w!=NIL) goto WHX553;
	local[17]= local[11];
	local[18]= makeint(1);
	ctx->vsp=local+19;
	w=(pointer)ASH(ctx,2,local+17); /*ash*/
	local[11] = w;
	goto WHL552;
WHX553:
	local[17]= NIL;
BLK554:
WHL555:
	local[17]= local[9];
	local[18]= local[3];
	ctx->vsp=local+19;
	w=(pointer)ASH(ctx,2,local+17); /*ash*/
	local[17]= w;
	local[18]= local[6];
	ctx->vsp=local+19;
	w=(pointer)EQ(ctx,2,local+17); /*eql*/
	if (w!=NIL) goto WHX556;
	local[17]= local[3];
	ctx->vsp=local+18;
	w=(pointer)SUB1(ctx,1,local+17); /*1-*/
	local[3] = w;
	goto WHL555;
WHX556:
	local[17]= NIL;
BLK557:
WHL558:
	local[17]= local[10];
	local[18]= local[4];
	ctx->vsp=local+19;
	w=(pointer)ASH(ctx,2,local+17); /*ash*/
	local[17]= w;
	local[18]= local[7];
	ctx->vsp=local+19;
	w=(pointer)EQ(ctx,2,local+17); /*eql*/
	if (w!=NIL) goto WHX559;
	local[17]= local[4];
	ctx->vsp=local+18;
	w=(pointer)SUB1(ctx,1,local+17); /*1-*/
	local[4] = w;
	goto WHL558;
WHX559:
	local[17]= NIL;
BLK560:
WHL561:
	local[17]= local[11];
	local[18]= local[5];
	ctx->vsp=local+19;
	w=(pointer)ASH(ctx,2,local+17); /*ash*/
	local[17]= w;
	local[18]= local[8];
	ctx->vsp=local+19;
	w=(pointer)EQ(ctx,2,local+17); /*eql*/
	if (w!=NIL) goto WHX562;
	local[17]= local[5];
	ctx->vsp=local+18;
	w=(pointer)SUB1(ctx,1,local+17); /*1-*/
	local[5] = w;
	goto WHL561;
WHX562:
	local[17]= NIL;
BLK563:
	local[17]= T;
	local[18]= fqv[66];
	local[19]= local[3];
	local[20]= local[9];
	local[21]= local[4];
	local[22]= local[10];
	local[23]= local[5];
	local[24]= local[11];
	ctx->vsp=local+25;
	w=(pointer)XFORMAT(ctx,8,local+17); /*format*/
	local[15] = makeint(0);
	local[17]= makeint(0);
	local[18]= local[0];
	ctx->vsp=local+19;
	w=(pointer)LENGTH(ctx,1,local+18); /*length*/
	local[18]= w;
WHL565:
	local[19]= local[17];
	w = local[18];
	if ((eusinteger_t)local[19] >= (eusinteger_t)w) goto WHX566;
	local[19]= local[15];
	w = makeint(1);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[15] = (pointer)((eusinteger_t)local[19] + (eusinteger_t)w);
	local[19]= local[11];
	local[20]= argv[0];
	{ register eusinteger_t i=intval(local[15]);
	  w=makeint(local[20]->c.str.chars[i]);}
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)LOGAND(ctx,2,local+19); /*logand*/
	local[14] = w;
	local[19]= local[10];
	local[20]= argv[0];
	local[21]= local[15];
	ctx->vsp=local+22;
	w=(pointer)ADD1(ctx,1,local+21); /*1+*/
	local[15] = w;
	{ register eusinteger_t i=intval(local[15]);
	  w=makeint(local[20]->c.str.chars[i]);}
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)LOGAND(ctx,2,local+19); /*logand*/
	local[13] = w;
	local[19]= local[9];
	local[20]= argv[0];
	local[21]= local[15];
	ctx->vsp=local+22;
	w=(pointer)ADD1(ctx,1,local+21); /*1+*/
	local[15] = w;
	{ register eusinteger_t i=intval(local[15]);
	  w=makeint(local[20]->c.str.chars[i]);}
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)LOGAND(ctx,2,local+19); /*logand*/
	local[12] = w;
	local[19]= local[15];
	w = makeint(1);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[15] = (pointer)((eusinteger_t)local[19] + (eusinteger_t)w);
	local[19]= local[0];
	local[20]= local[17];
	local[21]= local[12];
	local[22]= local[3];
	ctx->vsp=local+23;
	w=(pointer)ASH(ctx,2,local+21); /*ash*/
	local[21]= w;
	local[22]= local[13];
	local[23]= local[4];
	ctx->vsp=local+24;
	w=(pointer)ASH(ctx,2,local+22); /*ash*/
	local[22]= w;
	local[23]= local[14];
	local[24]= local[5];
	ctx->vsp=local+25;
	w=(pointer)ASH(ctx,2,local+23); /*ash*/
	w = (pointer)((eusinteger_t)local[22] | (eusinteger_t)w);
	w = (pointer)((eusinteger_t)local[21] | (eusinteger_t)w);
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[20]); v=local[19];
	  v->c.str.chars[i]=intval(w);}
	local[19]= local[17];
	ctx->vsp=local+20;
	w=(pointer)ADD1(ctx,1,local+19); /*1+*/
	local[17] = w;
	goto WHL565;
WHX566:
	local[19]= NIL;
BLK567:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK542:
	ctx->vsp=local; return(local[0]);}

/*color-24to6*/
static pointer F208color_24to6(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT570;}
	local[0]= argv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[8])(ctx,1,local+0,&ftab[8],fqv[53]); /*make-string*/
	local[0]= w;
ENT570:
ENT569:
	if (n>4) maerror();
	local[1]= makeint(0);
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= makeint(0);
	local[7]= argv[1];
	local[8]= argv[2];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
WHL572:
	local[8]= local[6];
	w = local[7];
	if ((eusinteger_t)local[8] >= (eusinteger_t)w) goto WHX573;
	local[8]= argv[0];
	local[9]= local[1];
	w = makeint(0);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[9]= (pointer)((eusinteger_t)local[9] + (eusinteger_t)w);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[3] = w;
	local[8]= argv[0];
	local[9]= local[1];
	w = makeint(1);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[9]= (pointer)((eusinteger_t)local[9] + (eusinteger_t)w);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[4] = w;
	local[8]= argv[0];
	local[9]= local[1];
	w = makeint(2);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[9]= (pointer)((eusinteger_t)local[9] + (eusinteger_t)w);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[5] = w;
	local[8]= local[1];
	w = makeint(3);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[1] = (pointer)((eusinteger_t)local[8] + (eusinteger_t)w);
	local[8]= local[3];
	local[9]= makeint(-2);
	ctx->vsp=local+10;
	w=(pointer)ASH(ctx,2,local+8); /*ash*/
	local[8]= w;
	w = makeint(48);
	local[8]= (pointer)((eusinteger_t)local[8] & (eusinteger_t)w);
	local[9]= local[4];
	local[10]= makeint(-4);
	ctx->vsp=local+11;
	w=(pointer)ASH(ctx,2,local+9); /*ash*/
	local[9]= w;
	w = makeint(12);
	local[9]= (pointer)((eusinteger_t)local[9] & (eusinteger_t)w);
	local[10]= local[5];
	local[11]= makeint(-6);
	ctx->vsp=local+12;
	w=(pointer)ASH(ctx,2,local+10); /*ash*/
	local[10]= w;
	w = makeint(3);
	w = (pointer)((eusinteger_t)local[10] & (eusinteger_t)w);
	w = (pointer)((eusinteger_t)local[9] | (eusinteger_t)w);
	local[2] = (pointer)((eusinteger_t)local[8] | (eusinteger_t)w);
	local[8]= local[0];
	local[9]= local[6];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)ASET(ctx,3,local+8); /*aset*/
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[6] = w;
	goto WHL572;
WHX573:
	local[8]= NIL;
BLK574:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK568:
	ctx->vsp=local; return(local[0]);}

/*color-32to8x3*/
static pointer F209color_32to8x3(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT579;}
	local[0]= argv[1];
	{ eusinteger_t i,j;
		j=intval(argv[2]); i=intval(local[0]);
		local[0]=(makeint(i * j));}
	ctx->vsp=local+1;
	w=(*ftab[8])(ctx,1,local+0,&ftab[8],fqv[53]); /*make-string*/
	local[0]= w;
ENT579:
	if (n>=5) { local[1]=(argv[4]); goto ENT578;}
	local[1]= argv[1];
	{ eusinteger_t i,j;
		j=intval(argv[2]); i=intval(local[1]);
		local[1]=(makeint(i * j));}
	ctx->vsp=local+2;
	w=(*ftab[8])(ctx,1,local+1,&ftab[8],fqv[53]); /*make-string*/
	local[1]= w;
ENT578:
	if (n>=6) { local[2]=(argv[5]); goto ENT577;}
	local[2]= argv[1];
	{ eusinteger_t i,j;
		j=intval(argv[2]); i=intval(local[2]);
		local[2]=(makeint(i * j));}
	ctx->vsp=local+3;
	w=(*ftab[8])(ctx,1,local+2,&ftab[8],fqv[53]); /*make-string*/
	local[2]= w;
ENT577:
ENT576:
	if (n>6) maerror();
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= makeint(0);
	local[7]= makeint(0);
	local[8]= argv[1];
	{ eusinteger_t i,j;
		j=intval(argv[2]); i=intval(local[8]);
		local[8]=(makeint(i * j));}
WHL581:
	local[9]= local[7];
	w = local[8];
	if ((eusinteger_t)local[9] >= (eusinteger_t)w) goto WHX582;
	local[9]= argv[0];
	{ register eusinteger_t i=intval(local[6]);
	  w=makeint(local[9]->c.str.chars[i]);}
	local[3] = w;
	local[9]= argv[0];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	{ register eusinteger_t i=intval(w);
	  w=makeint(local[9]->c.str.chars[i]);}
	local[4] = w;
	local[9]= argv[0];
	local[10]= local[6];
	local[11]= makeint(2);
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	{ register eusinteger_t i=intval(w);
	  w=makeint(local[9]->c.str.chars[i]);}
	local[5] = w;
	local[9]= local[2];
	local[10]= local[7];
	w = local[5];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[10]); v=local[9];
	  v->c.str.chars[i]=intval(w);}
	local[9]= local[1];
	local[10]= local[7];
	w = local[4];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[10]); v=local[9];
	  v->c.str.chars[i]=intval(w);}
	local[9]= local[0];
	local[10]= local[7];
	w = local[3];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[10]); v=local[9];
	  v->c.str.chars[i]=intval(w);}
	local[9]= local[6];
	local[10]= makeint(4);
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[6] = w;
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	local[7] = w;
	goto WHL581;
WHX582:
	local[9]= NIL;
BLK583:
	w = NIL;
	local[0]= w;
BLK575:
	ctx->vsp=local; return(local[0]);}

/*color-24to8x3*/
static pointer F210color_24to8x3(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT588;}
	local[0]= argv[1];
	{ eusinteger_t i,j;
		j=intval(argv[2]); i=intval(local[0]);
		local[0]=(makeint(i * j));}
	ctx->vsp=local+1;
	w=(*ftab[8])(ctx,1,local+0,&ftab[8],fqv[53]); /*make-string*/
	local[0]= w;
ENT588:
	if (n>=5) { local[1]=(argv[4]); goto ENT587;}
	local[1]= argv[1];
	{ eusinteger_t i,j;
		j=intval(argv[2]); i=intval(local[1]);
		local[1]=(makeint(i * j));}
	ctx->vsp=local+2;
	w=(*ftab[8])(ctx,1,local+1,&ftab[8],fqv[53]); /*make-string*/
	local[1]= w;
ENT587:
	if (n>=6) { local[2]=(argv[5]); goto ENT586;}
	local[2]= argv[1];
	{ eusinteger_t i,j;
		j=intval(argv[2]); i=intval(local[2]);
		local[2]=(makeint(i * j));}
	ctx->vsp=local+3;
	w=(*ftab[8])(ctx,1,local+2,&ftab[8],fqv[53]); /*make-string*/
	local[2]= w;
ENT586:
ENT585:
	if (n>6) maerror();
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= makeint(0);
	local[7]= makeint(0);
	local[8]= argv[1];
	{ eusinteger_t i,j;
		j=intval(argv[2]); i=intval(local[8]);
		local[8]=(makeint(i * j));}
WHL590:
	local[9]= local[7];
	w = local[8];
	if ((eusinteger_t)local[9] >= (eusinteger_t)w) goto WHX591;
	local[9]= argv[0];
	{ register eusinteger_t i=intval(local[6]);
	  w=makeint(local[9]->c.str.chars[i]);}
	local[3] = w;
	local[9]= argv[0];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	{ register eusinteger_t i=intval(w);
	  w=makeint(local[9]->c.str.chars[i]);}
	local[4] = w;
	local[9]= argv[0];
	local[10]= local[6];
	local[11]= makeint(2);
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	{ register eusinteger_t i=intval(w);
	  w=makeint(local[9]->c.str.chars[i]);}
	local[5] = w;
	local[9]= local[2];
	local[10]= local[7];
	w = local[5];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[10]); v=local[9];
	  v->c.str.chars[i]=intval(w);}
	local[9]= local[1];
	local[10]= local[7];
	w = local[4];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[10]); v=local[9];
	  v->c.str.chars[i]=intval(w);}
	local[9]= local[0];
	local[10]= local[7];
	w = local[3];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[10]); v=local[9];
	  v->c.str.chars[i]=intval(w);}
	local[9]= local[6];
	local[10]= makeint(3);
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[6] = w;
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	local[7] = w;
	goto WHL590;
WHX591:
	local[9]= NIL;
BLK592:
	w = NIL;
	local[0]= w;
BLK584:
	ctx->vsp=local; return(local[0]);}

/*swap-rgb*/
static pointer F211swap_rgb(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT595;}
	local[0]= makeint(3);
ENT595:
ENT594:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[1] = argv[0]->c.obj.iv[1];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	local[2] = w;
	local[7]= makeint(0);
	local[8]= local[2];
WHL597:
	local[9]= local[7];
	w = local[8];
	if ((eusinteger_t)local[9] >= (eusinteger_t)w) goto WHX598;
	local[9]= local[7];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[3] = w;
	local[9]= local[1];
	{ register eusinteger_t i=intval(local[3]);
	  w=makeint(local[9]->c.str.chars[i]);}
	local[4] = w;
	local[9]= local[1];
	local[10]= local[3];
	w = makeint(2);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	{ register eusinteger_t i=intval((pointer)((eusinteger_t)local[10] + (eusinteger_t)w));
	  w=makeint(local[9]->c.str.chars[i]);}
	local[6] = w;
	local[9]= local[1];
	local[10]= local[3];
	w = makeint(2);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[10]= (pointer)((eusinteger_t)local[10] + (eusinteger_t)w);
	w = local[4];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[10]); v=local[9];
	  v->c.str.chars[i]=intval(w);}
	local[9]= local[1];
	local[10]= local[3];
	w = local[6];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[10]); v=local[9];
	  v->c.str.chars[i]=intval(w);}
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	local[7] = w;
	goto WHL597;
WHX598:
	local[9]= NIL;
BLK599:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK593:
	ctx->vsp=local; return(local[0]);}

/*:components*/
static pointer M600multi_channel_image_components(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[13];
	local[0]= w;
BLK601:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M602color_image_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT607;}
	local[0]= NIL;
ENT607:
	if (n>=6) { local[1]=(argv[5]); goto ENT606;}
	local[1]= makeint(24);
ENT606:
	if (n>=7) { local[2]=(argv[6]); goto ENT605;}
	local[2]= makeint(3);
ENT605:
ENT604:
	if (n>7) maerror();
	argv[0]->c.obj.iv[12] = local[1];
	argv[0]->c.obj.iv[13] = local[2];
	local[3]= argv[0]->c.obj.iv[12];
	local[4]= makeint(8);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	argv[0]->c.obj.iv[14] = w;
	if (local[0]!=NIL) goto IF608;
	local[3]= argv[2];
	local[4]= argv[3];
	local[5]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,3,local+3); /***/
	local[3]= w;
	local[4]= fqv[15];
	local[5]= fqv[17];
	ctx->vsp=local+6;
	w=(*ftab[2])(ctx,3,local+3,&ftab[2],fqv[20]); /*make-array*/
	local[0] = w;
	local[3]= local[0];
	goto IF609;
IF608:
	local[3]= NIL;
IF609:
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[12]));
	local[5]= fqv[3];
	local[6]= argv[2];
	local[7]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	local[7]= argv[3];
	local[8]= local[0];
	local[9]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+10;
	w=(pointer)SENDMESSAGE(ctx,7,local+3); /*send-message*/
	w = argv[0];
	local[0]= w;
BLK603:
	ctx->vsp=local; return(local[0]);}

/*:depth*/
static pointer M610color_image_depth(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[12];
	local[0]= w;
BLK611:
	ctx->vsp=local; return(local[0]);}

/*:byte-depth*/
static pointer M612color_image_byte_depth(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[14];
	local[0]= w;
BLK613:
	ctx->vsp=local; return(local[0]);}

/*:width*/
static pointer M614color_image_width(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[6];
	local[1]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
BLK615:
	ctx->vsp=local; return(local[0]);}

/*:pixel*/
static pointer M616color_image_pixel(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= makeint(0);
	local[2]= makeint(0);
	local[3]= argv[0]->c.obj.iv[13];
WHL619:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX620;
	local[4]= local[1];
	local[5]= makeint(8);
	ctx->vsp=local+6;
	w=(pointer)ASH(ctx,2,local+4); /*ash*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= argv[3];
	local[7]= local[0];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,3,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LOGIOR(ctx,2,local+4); /*logior*/
	local[1] = w;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL619;
WHX620:
	local[4]= NIL;
BLK621:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK617:
	ctx->vsp=local; return(local[0]);}

/*:pixel-hex-string*/
static pointer M622color_image_pixel_hex_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= fqv[67];
	local[2]= argv[0];
	local[3]= fqv[24];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK623:
	ctx->vsp=local; return(local[0]);}

/*:pixel-list*/
static pointer M624color_image_pixel_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= makeint(0);
	local[2]= argv[0]->c.obj.iv[14];
WHL627:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX628;
	local[3]= argv[0];
	local[4]= argv[3];
	local[5]= local[1];
	local[6]= argv[2];
	local[7]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,3,local+3); /*aref*/
	local[3]= w;
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL627;
WHX628:
	local[3]= NIL;
BLK629:
	w = NIL;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)NREVERSE(ctx,1,local+1); /*nreverse*/
	local[0]= w;
BLK625:
	ctx->vsp=local; return(local[0]);}

/*:patch-in*/
static pointer M630color_image_patch_in(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= fqv[4];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[5];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[4];
	local[3]= fqv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[4]->c.obj.iv[1];
	local[4]= NIL;
	local[5]= NIL;
	local[6]= makeint(0);
	local[7]= argv[4];
	local[8]= fqv[5];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
WHL633:
	local[8]= local[6];
	w = local[7];
	if ((eusinteger_t)local[8] >= (eusinteger_t)w) goto WHX634;
	local[8]= argv[0]->c.obj.iv[12];
	local[9]= argv[3];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	local[10]= argv[2];
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[4] = w;
	local[8]= argv[0]->c.obj.iv[1];
	local[9]= local[3];
	local[10]= fqv[29];
	local[11]= local[4];
	local[12]= fqv[30];
	local[13]= local[4];
	local[14]= argv[0]->c.obj.iv[12];
	local[15]= local[2];
	ctx->vsp=local+16;
	w=(pointer)TIMES(ctx,2,local+14); /***/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,2,local+13); /*+*/
	local[13]= w;
	local[14]= fqv[31];
	local[15]= argv[0]->c.obj.iv[12];
	local[16]= local[6];
	local[17]= local[2];
	ctx->vsp=local+18;
	w=(pointer)TIMES(ctx,3,local+15); /***/
	local[15]= w;
	ctx->vsp=local+16;
	w=(*ftab[1])(ctx,8,local+8,&ftab[1],fqv[6]); /*replace*/
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[6] = w;
	goto WHL633;
WHX634:
	local[8]= NIL;
BLK635:
	w = NIL;
	local[0]= w;
BLK631:
	ctx->vsp=local; return(local[0]);}

/*:subimage*/
static pointer M636color_image_subimage(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[4];
	local[1]= argv[5];
	local[2]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,3,local+0); /***/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[8])(ctx,1,local+0,&ftab[8],fqv[53]); /*make-string*/
	local[0]= w;
	local[1]= makeint(0);
	local[2]= argv[5];
WHL639:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX640;
	local[3]= local[0];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= fqv[29];
	local[6]= local[1];
	local[7]= argv[4];
	local[8]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,3,local+6); /***/
	local[6]= w;
	local[7]= fqv[30];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[8]= w;
	local[9]= argv[4];
	local[10]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,3,local+8); /***/
	local[8]= w;
	local[9]= fqv[31];
	local[10]= argv[3];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[10]= w;
	local[11]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	local[11]= argv[0]->c.obj.iv[14];
	local[12]= argv[2];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[1])(ctx,8,local+3,&ftab[1],fqv[6]); /*replace*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL639;
WHX640:
	local[3]= NIL;
BLK641:
	w = NIL;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)GETCLASS(ctx,1,local+1); /*class*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[3];
	local[4]= argv[4];
	local[5]= argv[5];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK637:
	ctx->vsp=local; return(local[0]);}

/*:halve*/
static pointer M643color_image_halve(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT646;}
	local[0]= NIL;
ENT646:
ENT645:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[4];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= makeint(2);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	if (local[0]!=NIL) goto IF647;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[3];
	local[6]= local[1];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = local[3];
	local[0] = w;
	local[3]= local[0];
	goto IF648;
IF647:
	local[3]= NIL;
IF648:
	local[3]= argv[0];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,2,local+3,&ftab[4],fqv[27]); /*halve-image*/
	w = local[0];
	local[0]= w;
BLK644:
	ctx->vsp=local; return(local[0]);}

/*:double*/
static pointer M650color_image_double(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT653;}
	local[0]= NIL;
ENT653:
ENT652:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[4];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= makeint(2);
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	if (local[0]!=NIL) goto IF654;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)GETCLASS(ctx,1,local+3); /*class*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[3];
	local[6]= local[1];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = local[3];
	local[0] = w;
	local[3]= local[0];
	goto IF655;
IF654:
	local[3]= NIL;
IF655:
	local[3]= argv[0];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[5])(ctx,2,local+3,&ftab[5],fqv[28]); /*double-image*/
	w = local[0];
	local[0]= w;
BLK651:
	ctx->vsp=local; return(local[0]);}

/*:display*/
static pointer M657color_image_display(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT662;}
	local[0]= loadglobal(fqv[39]);
ENT662:
	if (n>=4) { local[1]=(argv[3]); goto ENT661;}
	local[1]= makeint(0);
ENT661:
	if (n>=5) { local[2]=(argv[4]); goto ENT660;}
	local[2]= makeint(0);
ENT660:
ENT659:
	if (n>5) maerror();
	local[3]= local[0];
	local[4]= fqv[40];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= local[3];
	local[5]= local[4];
	if (fqv[68]!=local[5]) goto IF664;
	local[5]= local[0];
	local[6]= fqv[42];
	if (loadglobal(fqv[32])==NIL) goto IF666;
	local[7]= argv[0];
	local[8]= fqv[36];
	local[9]= loadglobal(fqv[69]);
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w->c.obj.iv[1];
	goto IF667;
IF666:
	local[7]= argv[0]->c.obj.iv[1];
IF667:
	local[8]= fqv[43];
	local[9]= local[1];
	local[10]= fqv[44];
	local[11]= local[2];
	local[12]= fqv[4];
	local[13]= argv[0]->c.obj.iv[6];
	local[14]= fqv[5];
	local[15]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,11,local+5); /*send*/
	local[5]= w;
	goto IF665;
IF664:
	local[5]= local[4];
	if (fqv[70]!=local[5]) goto IF668;
	local[5]= local[0];
	local[6]= fqv[42];
	local[7]= argv[0];
	local[8]= fqv[46];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF669;
IF668:
	local[5]= local[4];
	if (fqv[71]!=local[5]) goto IF670;
	local[5]= local[0];
	local[6]= fqv[42];
	local[7]= argv[0];
	local[8]= fqv[48];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF671;
IF670:
	local[5]= local[4];
	if (fqv[72]!=local[5]) goto IF672;
	local[5]= local[0];
	local[6]= fqv[42];
	local[7]= argv[0];
	local[8]= fqv[50];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF673;
IF672:
	if (T==NIL) goto IF674;
	local[5]= fqv[73];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(*ftab[7])(ctx,2,local+5,&ftab[7],fqv[52]); /*warn*/
	local[5]= w;
	goto IF675;
IF674:
	local[5]= NIL;
IF675:
IF673:
IF671:
IF669:
IF665:
	w = local[5];
	w = argv[0];
	local[0]= w;
BLK658:
	ctx->vsp=local; return(local[0]);}

/*:component*/
static pointer M676color_image_component(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT679;}
	local[0]= NIL;
ENT679:
ENT678:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= argv[2];
	local[3]= argv[0];
	local[4]= fqv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[5];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	if (local[0]!=NIL) goto IF680;
	local[5]= loadglobal(fqv[74]);
	ctx->vsp=local+6;
	w=(pointer)INSTANTIATE(ctx,1,local+5); /*instantiate*/
	local[5]= w;
	local[6]= local[5];
	local[7]= fqv[3];
	local[8]= local[3];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	w = local[5];
	local[0] = w;
	local[5]= local[0];
	goto IF681;
IF680:
	local[5]= NIL;
IF681:
	local[5]= local[0];
	local[6]= fqv[75];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[1] = w;
	local[5]= makeint(0);
	local[6]= local[3];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
WHL684:
	local[7]= local[5];
	w = local[6];
	if ((eusinteger_t)local[7] >= (eusinteger_t)w) goto WHX685;
	local[7]= local[1];
	local[8]= local[5];
	local[9]= argv[0]->c.obj.iv[1];
	local[10]= local[5];
	local[11]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	{ register eusinteger_t i=intval(w);
	  w=makeint(local[9]->c.str.chars[i]);}
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[8]); v=local[7];
	  v->c.str.chars[i]=intval(w);}
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[5] = w;
	goto WHL684;
WHX685:
	local[7]= NIL;
BLK686:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK677:
	ctx->vsp=local; return(local[0]);}

/*:red*/
static pointer M687color_image_red(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[76];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK688:
	ctx->vsp=local; return(local[0]);}

/*:green*/
static pointer M689color_image_green(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[76];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK690:
	ctx->vsp=local; return(local[0]);}

/*:blue*/
static pointer M691color_image_blue(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[76];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK692:
	ctx->vsp=local; return(local[0]);}

/*:pseudo2true*/
static pointer M693color_image_pseudo2true(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[4];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= fqv[5];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= NIL;
	local[2]= argv[2];
	local[3]= fqv[75];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= makeint(0);
	local[5]= makeint(0);
	local[6]= local[0];
WHL696:
	local[7]= local[5];
	w = local[6];
	if ((eusinteger_t)local[7] >= (eusinteger_t)w) goto WHX697;
	local[7]= local[2];
	{ register eusinteger_t i=intval(local[5]);
	  w=makeint(local[7]->c.str.chars[i]);}
	local[1] = w;
	local[7]= local[5];
	local[8]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[4] = w;
	local[7]= makeint(0);
	local[8]= argv[0]->c.obj.iv[12];
WHL700:
	local[9]= local[7];
	w = local[8];
	if ((eusinteger_t)local[9] >= (eusinteger_t)w) goto WHX701;
	local[9]= local[3];
	local[10]= local[4];
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[10]= w;
	w = local[1];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[10]); v=local[9];
	  v->c.str.chars[i]=intval(w);}
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	local[7] = w;
	goto WHL700;
WHX701:
	local[9]= NIL;
BLK702:
	w = NIL;
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[5] = w;
	goto WHL696;
WHX697:
	local[7]= NIL;
BLK698:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK694:
	ctx->vsp=local; return(local[0]);}

/*:monochromize*/
static pointer M703color_image_monochromize(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT706;}
	local[0]= NIL;
ENT706:
ENT705:
	if (n>3) maerror();
	if (local[0]!=NIL) goto IF707;
	local[1]= loadglobal(fqv[74]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[3];
	local[4]= argv[0];
	local[5]= fqv[4];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[5];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[0] = w;
	local[1]= local[0];
	goto IF708;
IF707:
	local[1]= NIL;
IF708:
	local[1]= local[0];
	local[2]= fqv[75];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= makeint(0);
	local[3]= argv[0];
	local[4]= fqv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[5];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
WHL711:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX712;
	local[4]= makeint(0);
	local[5]= local[2];
	local[6]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	local[6]= makeint(0);
	local[7]= argv[0]->c.obj.iv[14];
WHL715:
	local[8]= local[6];
	w = local[7];
	if ((eusinteger_t)local[8] >= (eusinteger_t)w) goto WHX716;
	local[8]= local[4];
	local[9]= argv[0]->c.obj.iv[1];
	local[10]= local[5];
	w = local[6];
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	{ register eusinteger_t i=intval((pointer)((eusinteger_t)local[10] + (eusinteger_t)w));
	  w=makeint(local[9]->c.str.chars[i]);}
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[4] = w;
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[6] = w;
	goto WHL715;
WHX716:
	local[8]= NIL;
BLK717:
	w = NIL;
	local[6]= local[1];
	local[7]= local[2];
	local[8]= local[4];
	local[9]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[7]); v=local[6];
	  v->c.str.chars[i]=intval(w);}
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL711;
WHX712:
	local[4]= NIL;
BLK713:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK704:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M718color_image16_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT721;}
	local[0]= NIL;
ENT721:
ENT720:
	if (n>5) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[12]));
	local[3]= fqv[3];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= local[0];
	local[7]= makeint(16);
	local[8]= makeint(3);
	ctx->vsp=local+9;
	w=(pointer)SENDMESSAGE(ctx,8,local+1); /*send-message*/
	local[0]= w;
BLK719:
	ctx->vsp=local; return(local[0]);}

/*:pixel*/
static pointer M722color_image16_pixel(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	local[2]= argv[3];
	local[3]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[1]= w;
	local[2]= fqv[64];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK723:
	ctx->vsp=local; return(local[0]);}

/*:set-pixel*/
static pointer M724color_image16_set_pixel(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[4];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO726,env,argv,local);
	ctx->vsp=local+3;
	w=(*ftab[11])(ctx,0,local+3,&ftab[11],fqv[64]); /*:short*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,2,local+2); /*apply*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)POKE(ctx,3,local+0); /*system:poke*/
	local[0]= w;
BLK725:
	ctx->vsp=local; return(local[0]);}

/*:pixel-hex-string*/
static pointer M727color_image16_pixel_hex_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= fqv[77];
	local[2]= argv[0];
	local[3]= fqv[24];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK728:
	ctx->vsp=local; return(local[0]);}

/*:pixel-list*/
static pointer M729color_image16_pixel_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[24];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	local[2]= makeint(11);
	local[3]= makeint(5);
	ctx->vsp=local+4;
	w=(pointer)LDB(ctx,3,local+1); /*ldb*/
	local[1]= w;
	local[2]= local[0];
	local[3]= makeint(5);
	local[4]= makeint(6);
	ctx->vsp=local+5;
	w=(pointer)LDB(ctx,3,local+2); /*ldb*/
	local[2]= w;
	local[3]= local[0];
	local[4]= makeint(0);
	local[5]= makeint(5);
	ctx->vsp=local+6;
	w=(pointer)LDB(ctx,3,local+3); /*ldb*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[0]= w;
BLK730:
	ctx->vsp=local; return(local[0]);}

/*:to16*/
static pointer M731color_image16_to16(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0];
	local[0]= w;
BLK732:
	ctx->vsp=local; return(local[0]);}

/*:component*/
static pointer M733color_image16_component(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= fqv[78];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
BLK734:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO726(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[79],w);
	local[3]= env->c.clo.env1[3];
	local[4]= env->c.clo.env1[0]->c.obj.iv[6];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:pixel-list*/
static pointer M735color_image24_pixel_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0]->c.obj.iv[14];
	local[1]= argv[2];
	local[2]= argv[3];
	local[3]= argv[0];
	local[4]= fqv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[1];
	{ register eusinteger_t i=intval(local[0]);
	  w=makeint(local[1]->c.str.chars[i]);}
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	{ register eusinteger_t i=intval(w);
	  w=makeint(local[2]->c.str.chars[i]);}
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= local[0];
	w = makeint(2);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	{ register eusinteger_t i=intval((pointer)((eusinteger_t)local[4] + (eusinteger_t)w));
	  w=makeint(local[3]->c.str.chars[i]);}
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[0]= w;
BLK736:
	ctx->vsp=local; return(local[0]);}

/*:to24*/
static pointer M737color_image24_to24(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0];
	local[0]= w;
BLK738:
	ctx->vsp=local; return(local[0]);}

/*:to16*/
static pointer M739color_image24_to16(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[80]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[3];
	local[3]= argv[0];
	local[4]= fqv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[5];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= argv[0];
	local[7]= fqv[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= fqv[5];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)F206color_24to16(ctx,3,local+5); /*color-24to16*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK740:
	ctx->vsp=local; return(local[0]);}

/*:from32*/
static pointer M742color_image24_from32(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0];
	local[2]= fqv[4];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)F203color_32to24(ctx,4,local+0); /*color-32to24*/
	w = argv[0];
	local[0]= w;
BLK743:
	ctx->vsp=local; return(local[0]);}

/*:to32*/
static pointer M744color_image24_to32(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT747;}
	local[0]= NIL;
ENT747:
ENT746:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[4];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= local[1];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F204color_24to32(ctx,3,local+4); /*color-24to32*/
	local[3] = w;
	local[4]= loadglobal(fqv[81]);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= local[4];
	local[6]= fqv[3];
	local[7]= local[1];
	local[8]= local[2];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	w = local[4];
	local[0]= w;
BLK745:
	ctx->vsp=local; return(local[0]);}

/*:hls*/
static pointer M749color_image24_hls(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT752;}
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)GETCLASS(ctx,1,local+0); /*class*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[3];
	local[3]= argv[0];
	local[4]= fqv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[5];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
ENT752:
ENT751:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[4];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= local[0];
	local[4]= fqv[75];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= makeint(0);
	local[10]= makeint(0);
	local[11]= local[1];
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
WHL755:
	local[12]= local[10];
	w = local[11];
	if ((eusinteger_t)local[12] >= (eusinteger_t)w) goto WHX756;
	local[12]= argv[0]->c.obj.iv[1];
	{ register eusinteger_t i=intval(local[9]);
	  w=makeint(local[12]->c.str.chars[i]);}
	local[7] = w;
	local[12]= argv[0]->c.obj.iv[1];
	local[13]= local[9];
	ctx->vsp=local+14;
	w=(pointer)ADD1(ctx,1,local+13); /*1+*/
	{ register eusinteger_t i=intval(w);
	  w=makeint(local[12]->c.str.chars[i]);}
	local[6] = w;
	local[12]= argv[0]->c.obj.iv[1];
	local[13]= local[9];
	local[14]= makeint(2);
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,2,local+13); /*+*/
	{ register eusinteger_t i=intval(w);
	  w=makeint(local[12]->c.str.chars[i]);}
	local[5] = w;
	local[12]= local[5];
	local[13]= local[6];
	local[14]= local[7];
	ctx->vsp=local+15;
	w=(*ftab[12])(ctx,3,local+12,&ftab[12],fqv[82]); /*rgb-to-hls*/
	local[8] = w;
	local[12]= local[3];
	local[13]= local[9];
	local[14]= local[8];
	local[15]= makeint(16);
	local[16]= makeint(8);
	ctx->vsp=local+17;
	w=(pointer)LDB(ctx,3,local+14); /*ldb*/
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[13]); v=local[12];
	  v->c.str.chars[i]=intval(w);}
	local[12]= local[3];
	local[13]= local[9];
	ctx->vsp=local+14;
	w=(pointer)ADD1(ctx,1,local+13); /*1+*/
	local[13]= w;
	local[14]= local[8];
	local[15]= makeint(8);
	local[16]= makeint(8);
	ctx->vsp=local+17;
	w=(pointer)LDB(ctx,3,local+14); /*ldb*/
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[13]); v=local[12];
	  v->c.str.chars[i]=intval(w);}
	local[12]= local[3];
	local[13]= local[9];
	local[14]= makeint(2);
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,2,local+13); /*+*/
	local[13]= w;
	local[14]= local[8];
	local[15]= makeint(0);
	local[16]= makeint(8);
	ctx->vsp=local+17;
	w=(pointer)LDB(ctx,3,local+14); /*ldb*/
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[13]); v=local[12];
	  v->c.str.chars[i]=intval(w);}
	local[12]= local[9];
	local[13]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,2,local+12); /*+*/
	local[9] = w;
	local[12]= local[10];
	ctx->vsp=local+13;
	w=(pointer)ADD1(ctx,1,local+12); /*1+*/
	local[10] = w;
	goto WHL755;
WHX756:
	local[12]= NIL;
BLK757:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK750:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M758color_image32_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT761;}
	local[0]= NIL;
ENT761:
ENT760:
	if (n>5) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[12]));
	local[3]= fqv[3];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= local[0];
	local[7]= makeint(32);
	local[8]= makeint(4);
	ctx->vsp=local+9;
	w=(pointer)SENDMESSAGE(ctx,8,local+1); /*send-message*/
	w = argv[0];
	local[0]= w;
BLK759:
	ctx->vsp=local; return(local[0]);}

/*:from24*/
static pointer M762color_image32_from24(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0];
	local[2]= fqv[4];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)F204color_24to32(ctx,4,local+0); /*color-24to32*/
	w = argv[0];
	local[0]= w;
BLK763:
	ctx->vsp=local; return(local[0]);}

/*:to24*/
static pointer M764color_image32_to24(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT767;}
	local[0]= NIL;
ENT767:
ENT766:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[4];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= local[1];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F203color_32to24(ctx,3,local+4); /*color-32to24*/
	local[3] = w;
	local[4]= loadglobal(fqv[59]);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= local[4];
	local[6]= fqv[3];
	local[7]= local[1];
	local[8]= local[2];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	w = local[4];
	local[0]= w;
BLK765:
	ctx->vsp=local; return(local[0]);}

/*:to16*/
static pointer M769color_image32_to16(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[48];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[46];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK770:
	ctx->vsp=local; return(local[0]);}

/*:to8*/
static pointer M771color_image32_to8(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT774;}
	local[0]= NIL;
ENT774:
ENT773:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[4];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= local[1];
	local[5]= local[2];
	local[6]= local[0];
	local[7]= loadglobal(fqv[83]);
	ctx->vsp=local+8;
	w=(*ftab[13])(ctx,1,local+7,&ftab[13],fqv[84]); /*x::visual-masks*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)F207color_32to8(ctx,5,local+3); /*color-32to8*/
	local[0] = w;
	local[3]= loadglobal(fqv[74]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[3];
	local[6]= local[1];
	local[7]= local[2];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	w = local[3];
	local[0]= w;
BLK772:
	ctx->vsp=local; return(local[0]);}

/*:hls*/
static pointer M776color_image32_hls(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT779;}
	local[0]= loadglobal(fqv[81]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[3];
	local[3]= argv[0];
	local[4]= fqv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[5];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
ENT779:
ENT778:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[4];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= local[0];
	local[4]= fqv[75];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= makeint(0);
	local[9]= makeint(0);
	local[10]= local[1];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
WHL782:
	local[11]= local[9];
	w = local[10];
	if ((eusinteger_t)local[11] >= (eusinteger_t)w) goto WHX783;
	local[11]= argv[0]->c.obj.iv[1];
	{ register eusinteger_t i=intval(local[8]);
	  w=makeint(local[11]->c.str.chars[i]);}
	local[6] = w;
	local[11]= argv[0]->c.obj.iv[1];
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(pointer)ADD1(ctx,1,local+12); /*1+*/
	{ register eusinteger_t i=intval(w);
	  w=makeint(local[11]->c.str.chars[i]);}
	local[5] = w;
	local[11]= argv[0]->c.obj.iv[1];
	local[12]= local[8];
	local[13]= makeint(2);
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,2,local+12); /*+*/
	{ register eusinteger_t i=intval(w);
	  w=makeint(local[11]->c.str.chars[i]);}
	local[4] = w;
	local[11]= local[4];
	local[12]= local[5];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(*ftab[12])(ctx,3,local+11,&ftab[12],fqv[82]); /*rgb-to-hls*/
	local[7] = w;
	local[11]= local[3];
	local[12]= local[8];
	local[13]= local[7];
	local[14]= makeint(16);
	local[15]= makeint(8);
	ctx->vsp=local+16;
	w=(pointer)LDB(ctx,3,local+13); /*ldb*/
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[12]); v=local[11];
	  v->c.str.chars[i]=intval(w);}
	local[11]= local[3];
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(pointer)ADD1(ctx,1,local+12); /*1+*/
	local[12]= w;
	local[13]= local[7];
	local[14]= makeint(8);
	local[15]= makeint(8);
	ctx->vsp=local+16;
	w=(pointer)LDB(ctx,3,local+13); /*ldb*/
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[12]); v=local[11];
	  v->c.str.chars[i]=intval(w);}
	local[11]= local[3];
	local[12]= local[8];
	local[13]= makeint(2);
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,2,local+12); /*+*/
	local[12]= w;
	local[13]= local[7];
	local[14]= makeint(0);
	local[15]= makeint(8);
	ctx->vsp=local+16;
	w=(pointer)LDB(ctx,3,local+13); /*ldb*/
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[12]); v=local[11];
	  v->c.str.chars[i]=intval(w);}
	local[11]= local[8];
	local[12]= makeint(4);
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[8] = w;
	local[11]= local[9];
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[9] = w;
	goto WHL782;
WHX783:
	local[11]= NIL;
BLK784:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK777:
	ctx->vsp=local; return(local[0]);}

/*:component*/
static pointer M785color_image32_component(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT788;}
	local[0]= loadglobal(fqv[74]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[3];
	local[3]= argv[0];
	local[4]= fqv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[5];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
ENT788:
ENT787:
	if (n>4) maerror();
	local[1]= local[0];
	local[2]= fqv[75];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= makeint(0);
	local[4]= argv[0];
	local[5]= fqv[58];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
WHL791:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX792;
	local[5]= local[1];
	local[6]= local[3];
	local[7]= argv[0]->c.obj.iv[1];
	local[8]= local[3];
	{ eusinteger_t i,j;
		j=intval(makeint(4)); i=intval(local[8]);
		local[8]=(makeint(i * j));}
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	{ register eusinteger_t i=intval(w);
	  w=makeint(local[7]->c.str.chars[i]);}
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[6]); v=local[5];
	  v->c.str.chars[i]=intval(w);}
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL791;
WHX792:
	local[5]= NIL;
BLK793:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK786:
	ctx->vsp=local; return(local[0]);}

/*:red*/
static pointer M794color_image32_red(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[76];
	local[2]= makeint(3);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK795:
	ctx->vsp=local; return(local[0]);}

/*:green*/
static pointer M796color_image32_green(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[76];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK797:
	ctx->vsp=local; return(local[0]);}

/*:blue*/
static pointer M798color_image32_blue(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[76];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK799:
	ctx->vsp=local; return(local[0]);}

/*:monochromize*/
static pointer M800color_image32_monochromize(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT803;}
	local[0]= loadglobal(fqv[74]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[3];
	local[3]= argv[0];
	local[4]= fqv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[5];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
ENT803:
ENT802:
	if (n>3) maerror();
	local[1]= local[0];
	local[2]= fqv[75];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= makeint(1);
	local[3]= makeint(0);
	local[4]= argv[0];
	local[5]= fqv[58];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
WHL806:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX807;
	local[5]= local[1];
	local[6]= local[3];
	local[7]= argv[0]->c.obj.iv[1];
	{ register eusinteger_t i=intval(local[2]);
	  w=makeint(local[7]->c.str.chars[i]);}
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[1];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	{ register eusinteger_t i=intval(w);
	  w=makeint(local[8]->c.str.chars[i]);}
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[1];
	local[10]= local[2];
	local[11]= makeint(2);
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	{ register eusinteger_t i=intval(w);
	  w=makeint(local[9]->c.str.chars[i]);}
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,3,local+7); /*+*/
	local[7]= w;
	local[8]= makeint(3);
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[6]); v=local[5];
	  v->c.str.chars[i]=intval(w);}
	local[5]= local[2];
	local[6]= makeint(4);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[2] = w;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL806;
WHX807:
	local[5]= NIL;
BLK808:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK801:
	ctx->vsp=local; return(local[0]);}

/*color-to-deep*/
static pointer F212color_to_deep(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[59]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[3];
	local[3]= argv[0];
	local[4]= fqv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[5];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK809:
	ctx->vsp=local; return(local[0]);}

/*copy-color-map*/
static pointer F213copy_color_map(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeint(0);
	local[1]= argv[2];
WHL813:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX814;
	local[2]= argv[0];
	local[3]= fqv[85];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[1];
	local[4]= fqv[86];
	local[5]= NIL;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL813;
WHX814:
	local[2]= NIL;
BLK815:
	w = NIL;
	local[0]= w;
BLK811:
	ctx->vsp=local; return(local[0]);}

/*make-ximage*/
static pointer F214make_ximage(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT818;}
	local[0]= loadglobal(fqv[38]);
ENT818:
ENT817:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= fqv[87];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[1] = w;
	local[2]= local[1];
	local[3]= fqv[88];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK816:
	ctx->vsp=local; return(local[0]);}

/*make-colors*/
static pointer F215make_colors(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	if (argv[0]==NIL) goto IF820;
	local[0]= loadglobal(fqv[89]);
	storeglobal(fqv[90],local[0]);
	goto IF821;
IF820:
	local[0]= loadglobal(fqv[91]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[92];
	local[3]= fqv[93];
	local[4]= makeint(256);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
	storeglobal(fqv[90],w);
	local[0]= loadglobal(fqv[89]);
	local[1]= loadglobal(fqv[90]);
	local[2]= makeint(32);
	ctx->vsp=local+3;
	w=(pointer)F213copy_color_map(ctx,3,local+0); /*copy-color-map*/
	local[0]= w;
IF821:
	local[0]= loadglobal(fqv[90]);
	local[1]= fqv[94];
	local[2]= fqv[95];
	local[3]= makeint(16);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	storeglobal(fqv[96],w);
	local[0]= loadglobal(fqv[90]);
	local[1]= fqv[94];
	local[2]= fqv[97];
	local[3]= makeint(32);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	storeglobal(fqv[98],w);
	local[0]= loadglobal(fqv[90]);
	local[1]= fqv[99];
	local[2]= fqv[100];
	local[3]= makeint(32);
	local[4]= makeint(0);
	local[5]= makeint(360);
	local[6]= makeflt(5.00000000e-01);
	local[7]= makeflt(1.00000000e+00);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,8,local+0); /*send*/
	local[0]= w;
	storeglobal(fqv[101],w);
	local[0]= loadglobal(fqv[90]);
	local[1]= fqv[99];
	local[2]= fqv[102];
	local[3]= makeint(16);
	local[4]= makeint(0);
	local[5]= makeint(360);
	local[6]= makeflt(5.00000000e-01);
	local[7]= makeflt(1.00000000e+00);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,8,local+0); /*send*/
	local[0]= w;
	storeglobal(fqv[103],w);
	local[0]= loadglobal(fqv[90]);
	local[1]= fqv[104];
	local[2]= fqv[105];
	local[3]= makeint(16);
	local[4]= makeint(0);
	local[5]= makeflt(1.00000000e-01);
	local[6]= makeflt(5.00000000e-01);
	local[7]= makeflt(1.00000000e+00);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,8,local+0); /*send*/
	local[0]= w;
	storeglobal(fqv[106],w);
	local[0]= loadglobal(fqv[90]);
	local[1]= fqv[104];
	local[2]= fqv[107];
	local[3]= makeint(16);
	local[4]= makeint(120);
	local[5]= makeflt(1.00000000e-01);
	local[6]= makeflt(5.00000000e-01);
	local[7]= makeflt(1.00000000e+00);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,8,local+0); /*send*/
	local[0]= w;
	storeglobal(fqv[108],w);
	local[0]= loadglobal(fqv[90]);
	local[1]= fqv[104];
	local[2]= fqv[109];
	local[3]= makeint(16);
	local[4]= makeint(240);
	local[5]= makeflt(1.00000000e-01);
	local[6]= makeflt(5.00000000e-01);
	local[7]= makeflt(1.00000000e+00);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,8,local+0); /*send*/
	local[0]= w;
	storeglobal(fqv[110],w);
	local[0]= loadglobal(fqv[90]);
	local[1]= fqv[111];
	local[2]= fqv[112];
	local[3]= fqv[113];
	local[4]= makeint(65535);
	local[5]= makeint(40000);
	local[6]= makeint(40000);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,3,local+4); /*list*/
	local[4]= w;
	local[5]= fqv[114];
	local[6]= fqv[115];
	local[7]= fqv[116];
	local[8]= fqv[117];
	local[9]= fqv[118];
	local[10]= fqv[119];
	local[11]= fqv[120];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,9,local+3); /*list*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	storeglobal(fqv[121],w);
	local[0]= makeint(8);
	ctx->vsp=local+1;
	w=(pointer)F199make_equilevel_lut(ctx,1,local+0); /*make-equilevel-lut*/
	local[0]= w;
	storeglobal(fqv[122],w);
	local[0]= makeint(16);
	ctx->vsp=local+1;
	w=(pointer)F199make_equilevel_lut(ctx,1,local+0); /*make-equilevel-lut*/
	local[0]= w;
	storeglobal(fqv[123],w);
	local[0]= makeint(32);
	ctx->vsp=local+1;
	w=(pointer)F199make_equilevel_lut(ctx,1,local+0); /*make-equilevel-lut*/
	local[0]= w;
	storeglobal(fqv[124],w);
	local[0]= loadglobal(fqv[123]);
	local[1]= loadglobal(fqv[96]);
	ctx->vsp=local+2;
	w=(pointer)F202concatenate_lut(ctx,2,local+0); /*concatenate-lut*/
	local[0]= w;
	storeglobal(fqv[125],w);
	local[0]= loadglobal(fqv[124]);
	local[1]= loadglobal(fqv[98]);
	ctx->vsp=local+2;
	w=(pointer)F202concatenate_lut(ctx,2,local+0); /*concatenate-lut*/
	local[0]= w;
	storeglobal(fqv[38],w);
	local[0]= loadglobal(fqv[123]);
	local[1]= loadglobal(fqv[103]);
	ctx->vsp=local+2;
	w=(pointer)F202concatenate_lut(ctx,2,local+0); /*concatenate-lut*/
	local[0]= w;
	storeglobal(fqv[126],w);
	local[0]= loadglobal(fqv[124]);
	local[1]= loadglobal(fqv[101]);
	ctx->vsp=local+2;
	w=(pointer)F202concatenate_lut(ctx,2,local+0); /*concatenate-lut*/
	local[0]= w;
	storeglobal(fqv[127],w);
	local[0]= loadglobal(fqv[123]);
	ctx->vsp=local+1;
	w=(pointer)REVERSE(ctx,1,local+0); /*reverse*/
	local[0]= w;
	local[1]= loadglobal(fqv[101]);
	local[2]= makeint(8);
	local[3]= makeint(24);
	ctx->vsp=local+4;
	w=(pointer)SUBSEQ(ctx,3,local+1); /*subseq*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F202concatenate_lut(ctx,2,local+0); /*concatenate-lut*/
	local[0]= w;
	storeglobal(fqv[128],w);
	local[0]= loadglobal(fqv[123]);
	local[1]= loadglobal(fqv[106]);
	ctx->vsp=local+2;
	w=(pointer)F202concatenate_lut(ctx,2,local+0); /*concatenate-lut*/
	local[0]= w;
	storeglobal(fqv[129],w);
	local[0]= loadglobal(fqv[123]);
	local[1]= loadglobal(fqv[108]);
	ctx->vsp=local+2;
	w=(pointer)F202concatenate_lut(ctx,2,local+0); /*concatenate-lut*/
	local[0]= w;
	storeglobal(fqv[130],w);
	local[0]= loadglobal(fqv[123]);
	local[1]= loadglobal(fqv[110]);
	ctx->vsp=local+2;
	w=(pointer)F202concatenate_lut(ctx,2,local+0); /*concatenate-lut*/
	local[0]= w;
	storeglobal(fqv[131],w);
	w = local[0];
	local[0]= w;
BLK819:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___piximage(ctx,n,argv,env)
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
	local[0]= fqv[132];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF823;
	local[0]= fqv[133];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[134],w);
	goto IF824;
IF823:
	local[0]= fqv[135];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF824:
	local[0]= fqv[136];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[137];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[138];
	ctx->vsp=local+1;
	w=(*ftab[14])(ctx,1,local+0,&ftab[14],fqv[139]); /*use-package*/
	local[0]= fqv[125];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF825;
	local[0]= fqv[125];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[125];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF827;
	local[0]= fqv[125];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF828;
IF827:
	local[0]= NIL;
IF828:
	local[0]= fqv[125];
	goto IF826;
IF825:
	local[0]= NIL;
IF826:
	local[0]= fqv[38];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF829;
	local[0]= fqv[38];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[38];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF831;
	local[0]= fqv[38];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF832;
IF831:
	local[0]= NIL;
IF832:
	local[0]= fqv[38];
	goto IF830;
IF829:
	local[0]= NIL;
IF830:
	local[0]= fqv[128];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF833;
	local[0]= fqv[128];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[128];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF835;
	local[0]= fqv[128];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF836;
IF835:
	local[0]= NIL;
IF836:
	local[0]= fqv[128];
	goto IF834;
IF833:
	local[0]= NIL;
IF834:
	local[0]= fqv[129];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF837;
	local[0]= fqv[129];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[129];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF839;
	local[0]= fqv[129];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF840;
IF839:
	local[0]= NIL;
IF840:
	local[0]= fqv[129];
	goto IF838;
IF837:
	local[0]= NIL;
IF838:
	local[0]= fqv[130];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF841;
	local[0]= fqv[130];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[130];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF843;
	local[0]= fqv[130];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF844;
IF843:
	local[0]= NIL;
IF844:
	local[0]= fqv[130];
	goto IF842;
IF841:
	local[0]= NIL;
IF842:
	local[0]= fqv[131];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF845;
	local[0]= fqv[131];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[131];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF847;
	local[0]= fqv[131];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF848;
IF847:
	local[0]= NIL;
IF848:
	local[0]= fqv[131];
	goto IF846;
IF845:
	local[0]= NIL;
IF846:
	local[0]= fqv[126];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF849;
	local[0]= fqv[126];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[126];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF851;
	local[0]= fqv[126];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF852;
IF851:
	local[0]= NIL;
IF852:
	local[0]= fqv[126];
	goto IF850;
IF849:
	local[0]= NIL;
IF850:
	local[0]= fqv[127];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF853;
	local[0]= fqv[127];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[127];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF855;
	local[0]= fqv[127];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF856;
IF855:
	local[0]= NIL;
IF856:
	local[0]= fqv[127];
	goto IF854;
IF853:
	local[0]= NIL;
IF854:
	local[0]= fqv[142];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF857;
	local[0]= fqv[142];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[142];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF859;
	local[0]= fqv[142];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF860;
IF859:
	local[0]= NIL;
IF860:
	local[0]= fqv[142];
	goto IF858;
IF857:
	local[0]= NIL;
IF858:
	local[0]= fqv[96];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF861;
	local[0]= fqv[96];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[96];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF863;
	local[0]= fqv[96];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF864;
IF863:
	local[0]= NIL;
IF864:
	local[0]= fqv[96];
	goto IF862;
IF861:
	local[0]= NIL;
IF862:
	local[0]= fqv[98];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF865;
	local[0]= fqv[98];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[98];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF867;
	local[0]= fqv[98];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF868;
IF867:
	local[0]= NIL;
IF868:
	local[0]= fqv[98];
	goto IF866;
IF865:
	local[0]= NIL;
IF866:
	local[0]= fqv[103];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF869;
	local[0]= fqv[103];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[103];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF871;
	local[0]= fqv[103];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF872;
IF871:
	local[0]= NIL;
IF872:
	local[0]= fqv[103];
	goto IF870;
IF869:
	local[0]= NIL;
IF870:
	local[0]= fqv[101];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF873;
	local[0]= fqv[101];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[101];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF875;
	local[0]= fqv[101];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF876;
IF875:
	local[0]= NIL;
IF876:
	local[0]= fqv[101];
	goto IF874;
IF873:
	local[0]= NIL;
IF874:
	local[0]= fqv[106];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF877;
	local[0]= fqv[106];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[106];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF879;
	local[0]= fqv[106];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF880;
IF879:
	local[0]= NIL;
IF880:
	local[0]= fqv[106];
	goto IF878;
IF877:
	local[0]= NIL;
IF878:
	local[0]= fqv[108];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF881;
	local[0]= fqv[108];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[108];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF883;
	local[0]= fqv[108];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF884;
IF883:
	local[0]= NIL;
IF884:
	local[0]= fqv[108];
	goto IF882;
IF881:
	local[0]= NIL;
IF882:
	local[0]= fqv[110];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF885;
	local[0]= fqv[110];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[110];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF887;
	local[0]= fqv[110];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF888;
IF887:
	local[0]= NIL;
IF888:
	local[0]= fqv[110];
	goto IF886;
IF885:
	local[0]= NIL;
IF886:
	local[0]= fqv[121];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF889;
	local[0]= fqv[121];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[121];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF891;
	local[0]= fqv[121];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF892;
IF891:
	local[0]= NIL;
IF892:
	local[0]= fqv[121];
	goto IF890;
IF889:
	local[0]= NIL;
IF890:
	local[0]= fqv[122];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF893;
	local[0]= fqv[122];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[122];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF895;
	local[0]= fqv[122];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF896;
IF895:
	local[0]= NIL;
IF896:
	local[0]= fqv[122];
	goto IF894;
IF893:
	local[0]= NIL;
IF894:
	local[0]= fqv[123];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF897;
	local[0]= fqv[123];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[123];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF899;
	local[0]= fqv[123];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF900;
IF899:
	local[0]= NIL;
IF900:
	local[0]= fqv[123];
	goto IF898;
IF897:
	local[0]= NIL;
IF898:
	local[0]= fqv[124];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF901;
	local[0]= fqv[124];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[124];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF903;
	local[0]= fqv[124];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF904;
IF903:
	local[0]= NIL;
IF904:
	local[0]= fqv[124];
	goto IF902;
IF901:
	local[0]= NIL;
IF902:
	local[0]= fqv[90];
	local[1]= fqv[140];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF905;
	local[0]= fqv[90];
	local[1]= fqv[140];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[90];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF907;
	local[0]= fqv[90];
	local[1]= fqv[141];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF908;
IF907:
	local[0]= NIL;
IF908:
	local[0]= fqv[90];
	goto IF906;
IF905:
	local[0]= NIL;
IF906:
	ctx->vsp=local+0;
	compfun(ctx,fqv[143],module,F199make_equilevel_lut,fqv[144]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[145],module,F200look_up2,fqv[146]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[147],module,F201look_up_,fqv[148]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[149],module,F202concatenate_lut,fqv[150]);
	local[0]= fqv[151];
	local[1]= fqv[141];
	local[2]= fqv[151];
	local[3]= fqv[152];
	local[4]= loadglobal(fqv[153]);
	local[5]= fqv[154];
	local[6]= fqv[155];
	local[7]= fqv[156];
	local[8]= NIL;
	local[9]= fqv[15];
	local[10]= NIL;
	local[11]= fqv[58];
	local[12]= makeint(-1);
	local[13]= fqv[157];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[15])(ctx,13,local+2,&ftab[15],fqv[158]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[159];
	local[1]= fqv[141];
	local[2]= fqv[159];
	local[3]= fqv[152];
	local[4]= loadglobal(fqv[151]);
	local[5]= fqv[154];
	local[6]= fqv[160];
	local[7]= fqv[156];
	local[8]= NIL;
	local[9]= fqv[15];
	local[10]= NIL;
	local[11]= fqv[58];
	local[12]= makeint(-1);
	local[13]= fqv[157];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[15])(ctx,13,local+2,&ftab[15],fqv[158]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[161];
	local[1]= fqv[141];
	local[2]= fqv[161];
	local[3]= fqv[152];
	local[4]= loadglobal(fqv[159]);
	local[5]= fqv[154];
	local[6]= fqv[160];
	local[7]= fqv[156];
	local[8]= NIL;
	local[9]= fqv[15];
	local[10]= NIL;
	local[11]= fqv[58];
	local[12]= makeint(-1);
	local[13]= fqv[157];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[15])(ctx,13,local+2,&ftab[15],fqv[158]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[74];
	local[1]= fqv[141];
	local[2]= fqv[74];
	local[3]= fqv[152];
	local[4]= loadglobal(fqv[159]);
	local[5]= fqv[154];
	local[6]= fqv[160];
	local[7]= fqv[156];
	local[8]= NIL;
	local[9]= fqv[15];
	local[10]= NIL;
	local[11]= fqv[58];
	local[12]= makeint(-1);
	local[13]= fqv[157];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[15])(ctx,13,local+2,&ftab[15],fqv[158]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[33];
	local[1]= fqv[141];
	local[2]= fqv[33];
	local[3]= fqv[152];
	local[4]= loadglobal(fqv[159]);
	local[5]= fqv[154];
	local[6]= fqv[160];
	local[7]= fqv[156];
	local[8]= NIL;
	local[9]= fqv[15];
	local[10]= NIL;
	local[11]= fqv[58];
	local[12]= makeint(-1);
	local[13]= fqv[157];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[15])(ctx,13,local+2,&ftab[15],fqv[158]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[162];
	local[1]= fqv[141];
	local[2]= fqv[162];
	local[3]= fqv[152];
	local[4]= loadglobal(fqv[151]);
	local[5]= fqv[154];
	local[6]= fqv[163];
	local[7]= fqv[156];
	local[8]= NIL;
	local[9]= fqv[15];
	local[10]= NIL;
	local[11]= fqv[58];
	local[12]= makeint(-1);
	local[13]= fqv[157];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[15])(ctx,13,local+2,&ftab[15],fqv[158]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[164];
	local[1]= fqv[141];
	local[2]= fqv[164];
	local[3]= fqv[152];
	local[4]= loadglobal(fqv[162]);
	local[5]= fqv[154];
	local[6]= fqv[160];
	local[7]= fqv[156];
	local[8]= NIL;
	local[9]= fqv[15];
	local[10]= NIL;
	local[11]= fqv[58];
	local[12]= makeint(-1);
	local[13]= fqv[157];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[15])(ctx,13,local+2,&ftab[15],fqv[158]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[165];
	local[1]= fqv[141];
	local[2]= fqv[165];
	local[3]= fqv[152];
	local[4]= loadglobal(fqv[162]);
	local[5]= fqv[154];
	local[6]= fqv[166];
	local[7]= fqv[156];
	local[8]= NIL;
	local[9]= fqv[15];
	local[10]= NIL;
	local[11]= fqv[58];
	local[12]= makeint(-1);
	local[13]= fqv[157];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[15])(ctx,13,local+2,&ftab[15],fqv[158]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[80];
	local[1]= fqv[141];
	local[2]= fqv[80];
	local[3]= fqv[152];
	local[4]= loadglobal(fqv[165]);
	local[5]= fqv[154];
	local[6]= fqv[160];
	local[7]= fqv[156];
	local[8]= NIL;
	local[9]= fqv[15];
	local[10]= NIL;
	local[11]= fqv[58];
	local[12]= makeint(-1);
	local[13]= fqv[157];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[15])(ctx,13,local+2,&ftab[15],fqv[158]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[59];
	local[1]= fqv[141];
	local[2]= fqv[59];
	local[3]= fqv[152];
	local[4]= loadglobal(fqv[165]);
	local[5]= fqv[154];
	local[6]= fqv[160];
	local[7]= fqv[156];
	local[8]= NIL;
	local[9]= fqv[15];
	local[10]= NIL;
	local[11]= fqv[58];
	local[12]= makeint(-1);
	local[13]= fqv[157];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[15])(ctx,13,local+2,&ftab[15],fqv[158]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[81];
	local[1]= fqv[141];
	local[2]= fqv[81];
	local[3]= fqv[152];
	local[4]= loadglobal(fqv[165]);
	local[5]= fqv[154];
	local[6]= fqv[160];
	local[7]= fqv[156];
	local[8]= NIL;
	local[9]= fqv[15];
	local[10]= NIL;
	local[11]= fqv[58];
	local[12]= makeint(-1);
	local[13]= fqv[157];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[15])(ctx,13,local+2,&ftab[15],fqv[158]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M253image_2d_entity,fqv[75],fqv[151],fqv[167]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M255image_2d_width,fqv[4],fqv[151],fqv[168]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M257image_2d_height,fqv[5],fqv[151],fqv[169]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M259image_2d_size,fqv[58],fqv[151],fqv[170]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M261image_2d_pixel,fqv[24],fqv[151],fqv[171]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M263image_2d_set_pixel,fqv[23],fqv[151],fqv[172]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M265image_2d_duplicate,fqv[25],fqv[151],fqv[173]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M269image_2d_copy_from,fqv[174],fqv[151],fqv[175]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M271image_2d_copy,fqv[176],fqv[151],fqv[177]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M273image_2d_hex,fqv[178],fqv[151],fqv[179]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M289image_2d_prin1,fqv[13],fqv[151],fqv[180]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M292image_2d_init,fqv[3],fqv[151],fqv[181]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M304image_2d_fill,fqv[22],fqv[151],fqv[182]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M306image_2d_clear,fqv[183],fqv[151],fqv[184]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M308image_2d_transpose,fqv[185],fqv[151],fqv[186]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M321image_2d_map_picture,fqv[187],fqv[151],fqv[188]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M329image_2d_map,fqv[189],fqv[151],fqv[190]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M337single_channel_image_pixel,fqv[24],fqv[159],fqv[191]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M339single_channel_image_set_pixel,fqv[23],fqv[159],fqv[192]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M341single_channel_image_pixel_hex_string,fqv[9],fqv[159],fqv[193]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M343single_channel_image_halve,fqv[194],fqv[159],fqv[195]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M350single_channel_image_double,fqv[196],fqv[159],fqv[197]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M357single_channel_image_patch_in,fqv[198],fqv[159],fqv[199]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M363single_channel_image_xpicture,fqv[36],fqv[159],fqv[200]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M372single_channel_image_display_lut,fqv[34],fqv[159],fqv[201]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M380single_channel_image_display,fqv[88],fqv[159],fqv[202]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M400single_channel_image_subimage,fqv[203],fqv[159],fqv[204]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M407single_channel_image_patch_in,fqv[198],fqv[159],fqv[205]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M413single_channel_image_brightest_pixel,fqv[206],fqv[159],fqv[207]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M421single_channel_image_darkest_pixel,fqv[208],fqv[159],fqv[209]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M429single_channel_image_average_pixel,fqv[210],fqv[159],fqv[211]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M431single_channel_image_amplify,fqv[212],fqv[159],fqv[213]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M439single_channel_image_compress_gray_scale,fqv[214],fqv[159],fqv[215]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M449single_channel_image_lut,fqv[87],fqv[159],fqv[216]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M453single_channel_image_lut2,fqv[217],fqv[159],fqv[218]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M457single_channel_image_to24,fqv[48],fqv[159],fqv[219]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M464single_channel_image_to32,fqv[50],fqv[159],fqv[220]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M466single_channel_image_to16,fqv[46],fqv[159],fqv[221]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M468bitmap_image_init,fqv[3],fqv[161],fqv[222]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M472bitmap_image_pixel_hex_string,fqv[9],fqv[161],fqv[223]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[224],module,F203color_32to24,fqv[225]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[226],module,F204color_24to32,fqv[227]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[228],module,F205color_24to8,fqv[229]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[230],module,F206color_24to16,fqv[231]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[232],module,F207color_32to8,fqv[233]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[234],module,F208color_24to6,fqv[235]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[236],module,F209color_32to8x3,fqv[237]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[238],module,F210color_24to8x3,fqv[239]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[240],module,F211swap_rgb,fqv[241]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M600multi_channel_image_components,fqv[242],fqv[162],fqv[243]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M602color_image_init,fqv[3],fqv[165],fqv[244]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M610color_image_depth,fqv[40],fqv[165],fqv[245]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M612color_image_byte_depth,fqv[246],fqv[165],fqv[247]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M614color_image_width,fqv[4],fqv[165],fqv[248]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M616color_image_pixel,fqv[24],fqv[165],fqv[249]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M622color_image_pixel_hex_string,fqv[9],fqv[165],fqv[250]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M624color_image_pixel_list,fqv[251],fqv[165],fqv[252]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M630color_image_patch_in,fqv[198],fqv[165],fqv[253]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M636color_image_subimage,fqv[203],fqv[165],fqv[254]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M643color_image_halve,fqv[194],fqv[165],fqv[255]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M650color_image_double,fqv[196],fqv[165],fqv[256]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M657color_image_display,fqv[88],fqv[165],fqv[257]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M676color_image_component,fqv[76],fqv[165],fqv[258]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M687color_image_red,fqv[259],fqv[165],fqv[260]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M689color_image_green,fqv[261],fqv[165],fqv[262]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M691color_image_blue,fqv[263],fqv[165],fqv[264]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M693color_image_pseudo2true,fqv[265],fqv[165],fqv[266]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M703color_image_monochromize,fqv[267],fqv[165],fqv[268]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M718color_image16_init,fqv[3],fqv[80],fqv[269]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M722color_image16_pixel,fqv[24],fqv[80],fqv[270]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M724color_image16_set_pixel,fqv[23],fqv[80],fqv[271]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M727color_image16_pixel_hex_string,fqv[9],fqv[80],fqv[272]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M729color_image16_pixel_list,fqv[251],fqv[80],fqv[273]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M731color_image16_to16,fqv[46],fqv[80],fqv[274]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M733color_image16_component,fqv[76],fqv[80],fqv[275]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M735color_image24_pixel_list,fqv[251],fqv[59],fqv[276]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M737color_image24_to24,fqv[48],fqv[59],fqv[277]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M739color_image24_to16,fqv[46],fqv[59],fqv[278]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M742color_image24_from32,fqv[279],fqv[59],fqv[280]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M744color_image24_to32,fqv[50],fqv[59],fqv[281]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M749color_image24_hls,fqv[282],fqv[59],fqv[283]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M758color_image32_init,fqv[3],fqv[81],fqv[284]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M762color_image32_from24,fqv[285],fqv[81],fqv[286]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M764color_image32_to24,fqv[48],fqv[81],fqv[287]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M769color_image32_to16,fqv[46],fqv[81],fqv[288]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M771color_image32_to8,fqv[289],fqv[81],fqv[290]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M776color_image32_hls,fqv[282],fqv[81],fqv[291]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M785color_image32_component,fqv[76],fqv[81],fqv[292]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M794color_image32_red,fqv[259],fqv[81],fqv[293]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M796color_image32_green,fqv[261],fqv[81],fqv[294]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M798color_image32_blue,fqv[263],fqv[81],fqv[295]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M800color_image32_monochromize,fqv[267],fqv[81],fqv[296]);
	local[0]= fqv[297];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[297],module,F212color_to_deep,fqv[298]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[299],module,F213copy_color_map,fqv[300]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[301],module,F214make_ximage,fqv[302]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[303],module,F215make_colors,fqv[304]);
	local[0]= fqv[305];
	local[1]= fqv[306];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[307]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<17; i++) ftab[i]=fcallx;
}
