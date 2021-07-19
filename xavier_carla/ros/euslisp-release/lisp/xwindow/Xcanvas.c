/* ./Xcanvas.c :  entry=Xcanvas */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "Xcanvas.h"
#pragma init (register_Xcanvas)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___Xcanvas();
extern pointer build_quote_vector();
static int register_Xcanvas()
  { add_module_initializer("___Xcanvas", ___Xcanvas);}


/*:create*/
static pointer M3044canvas_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3046:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[0]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[1]));
	local[4]= fqv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	local[1]= loadglobal(fqv[3]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	w = local[1];
	argv[0]->c.obj.iv[15] = w;
	local[1]= argv[0]->c.obj.iv[15];
	local[2]= fqv[4];
	local[3]= loadglobal(fqv[5]);
	local[4]= fqv[6];
	local[5]= argv[0];
	local[6]= fqv[7];
	local[7]= loadglobal(fqv[8]);
	local[8]= fqv[9];
	local[9]= makeint(65535);
	local[10]= makeint(4096);
	local[11]= makeint(4096);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[15];
	local[2]= fqv[4];
	local[3]= loadglobal(fqv[5]);
	local[4]= fqv[10];
	local[5]= argv[0];
	local[6]= fqv[7];
	local[7]= loadglobal(fqv[8]);
	local[8]= fqv[9];
	local[9]= makeint(4096);
	local[10]= makeint(4096);
	local[11]= makeint(65535);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[15];
	local[2]= fqv[4];
	local[3]= loadglobal(fqv[5]);
	local[4]= fqv[11];
	local[5]= argv[0];
	local[6]= fqv[7];
	local[7]= loadglobal(fqv[8]);
	local[8]= fqv[9];
	local[9]= makeint(4096);
	local[10]= makeint(65535);
	local[11]= makeint(4096);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[15];
	local[2]= fqv[4];
	local[3]= loadglobal(fqv[5]);
	local[4]= fqv[12];
	local[5]= argv[0];
	local[6]= fqv[13];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[15];
	local[2]= fqv[4];
	local[3]= loadglobal(fqv[5]);
	local[4]= fqv[14];
	local[5]= argv[0];
	local[6]= fqv[15];
	local[7]= loadglobal(fqv[8]);
	local[8]= fqv[9];
	local[9]= makeint(65535);
	local[10]= makeint(65535);
	local[11]= makeint(65535);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[15];
	local[2]= fqv[4];
	local[3]= loadglobal(fqv[5]);
	local[4]= fqv[16];
	local[5]= argv[0];
	local[6]= fqv[15];
	local[7]= loadglobal(fqv[8]);
	local[8]= fqv[9];
	local[9]= makeint(49152);
	local[10]= makeint(49152);
	local[11]= makeint(49152);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[15];
	local[2]= fqv[4];
	local[3]= loadglobal(fqv[5]);
	local[4]= fqv[17];
	local[5]= argv[0];
	local[6]= fqv[15];
	local[7]= loadglobal(fqv[8]);
	local[8]= fqv[9];
	local[9]= makeint(16384);
	local[10]= makeint(16384);
	local[11]= makeint(16384);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[15];
	local[2]= fqv[4];
	local[3]= loadglobal(fqv[5]);
	local[4]= fqv[18];
	local[5]= argv[0];
	local[6]= fqv[15];
	local[7]= loadglobal(fqv[8]);
	local[8]= fqv[9];
	local[9]= makeint(0);
	local[10]= makeint(0);
	local[11]= makeint(0);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	w = argv[0];
	local[0]= w;
BLK3045:
	ctx->vsp=local; return(local[0]);}

/*:selection*/
static pointer M3048canvas_selection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[12];
	local[1]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
BLK3049:
	ctx->vsp=local; return(local[0]);}

/*:adjust-corners*/
static pointer M3050canvas_adjust_corners(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[12];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[13];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MIN(ctx,2,local+0); /*min*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[12];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[13];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MIN(ctx,2,local+1); /*min*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MKINTVECTOR(ctx,2,local+0); /*integer-vector*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[12];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[13];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAX(ctx,2,local+1); /*max*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[12];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[13];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MAX(ctx,2,local+2); /*max*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MKINTVECTOR(ctx,2,local+1); /*integer-vector*/
	local[1]= w;
	local[2]= local[1];
	local[3]= local[0];
	argv[0]->c.obj.iv[13] = local[2];
	argv[0]->c.obj.iv[12] = local[3];
	w = NIL;
	local[0]= w;
BLK3051:
	ctx->vsp=local; return(local[0]);}

/*:draw-selection-rectangle*/
static pointer M3054canvas_draw_selection_rectangle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[12];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[13];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MIN(ctx,2,local+0); /*min*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[12];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[13];
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MIN(ctx,2,local+1); /*min*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MKINTVECTOR(ctx,2,local+0); /*integer-vector*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[19];
	local[3]= local[0];
	local[4]= argv[0]->c.obj.iv[13];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[12];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ABS(ctx,1,local+4); /*abs*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[13];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[12];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[0]= w;
BLK3055:
	ctx->vsp=local; return(local[0]);}

/*:buttonpress*/
static pointer M3056canvas_buttonpress(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[20],w);
	local[3]= loadglobal(fqv[20]);
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,1,local+3,&ftab[0],fqv[21]); /*event-button*/
	local[3]= w;
	local[4]= local[3];
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(pointer)LSEQP(ctx,2,local+4); /*<=*/
	if (w==NIL) goto CON3059;
	local[4]= argv[0];
	local[5]= fqv[22];
	local[6]= fqv[23];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[24];
	local[6]= makeint(127);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= loadglobal(fqv[20]);
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,1,local+4,&ftab[1],fqv[25]); /*event-pos*/
	argv[0]->c.obj.iv[12] = w;
	local[4]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+5;
	w=(pointer)COPYSEQ(ctx,1,local+4); /*copy-seq*/
	argv[0]->c.obj.iv[13] = w;
	local[4]= argv[0];
	local[5]= fqv[26];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	argv[0]->c.obj.iv[14] = T;
	local[4]= argv[0]->c.obj.iv[14];
	goto CON3058;
CON3059:
	local[4]= local[3];
	local[5]= makeint(3);
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w==NIL) goto CON3060;
	local[4]= argv[0]->c.obj.iv[15];
	local[5]= fqv[27];
	local[6]= loadglobal(fqv[20]);
	ctx->vsp=local+7;
	w=(*ftab[2])(ctx,1,local+6,&ftab[2],fqv[28]); /*event-x-root*/
	local[6]= w;
	local[7]= loadglobal(fqv[20]);
	ctx->vsp=local+8;
	w=(*ftab[3])(ctx,1,local+7,&ftab[3],fqv[29]); /*event-y-root*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto CON3058;
CON3060:
	local[4]= NIL;
CON3058:
	w = local[4];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3057:
	ctx->vsp=local; return(local[0]);}

/*:motionnotify*/
static pointer M3061canvas_motionnotify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[20],w);
	if (argv[0]->c.obj.iv[14]==NIL) goto IF3063;
	local[3]= loadglobal(fqv[20]);
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,1,local+3,&ftab[4],fqv[30]); /*event-state*/
	local[3]= w;
	local[4]= fqv[31];
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(*ftab[5])(ctx,2,local+4,&ftab[5],fqv[32]); /*member*/
	if (w==NIL) goto CON3066;
	local[4]= argv[0];
	local[5]= fqv[26];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= loadglobal(fqv[20]);
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,1,local+4,&ftab[1],fqv[25]); /*event-pos*/
	argv[0]->c.obj.iv[13] = w;
	local[4]= argv[0];
	local[5]= fqv[26];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	goto CON3065;
CON3066:
	local[4]= fqv[33];
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(*ftab[5])(ctx,2,local+4,&ftab[5],fqv[32]); /*member*/
	if (w==NIL) goto CON3067;
	local[4]= argv[0]->c.obj.iv[15];
	local[5]= fqv[34];
	local[6]= loadglobal(fqv[20]);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto CON3065;
CON3067:
	local[4]= NIL;
CON3065:
	w = local[4];
	local[3]= w;
	goto IF3064;
IF3063:
	local[3]= NIL;
IF3064:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3062:
	ctx->vsp=local; return(local[0]);}

/*:buttonrelease*/
static pointer M3068canvas_buttonrelease(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[20],w);
	if (argv[0]->c.obj.iv[14]==NIL) goto CON3071;
	local[3]= loadglobal(fqv[20]);
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,1,local+3,&ftab[4],fqv[30]); /*event-state*/
	local[3]= w;
	local[4]= fqv[35];
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(*ftab[5])(ctx,2,local+4,&ftab[5],fqv[32]); /*member*/
	if (w==NIL) goto CON3073;
	local[4]= fqv[33];
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(*ftab[5])(ctx,2,local+4,&ftab[5],fqv[32]); /*member*/
	if (w==NIL) goto CON3073;
	local[4]= argv[0];
	local[5]= fqv[36];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[22];
	local[6]= fqv[37];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto CON3072;
CON3073:
	local[4]= fqv[33];
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(*ftab[5])(ctx,2,local+4,&ftab[5],fqv[32]); /*member*/
	if (w==NIL) goto CON3074;
	local[4]= argv[0]->c.obj.iv[15];
	storeglobal(fqv[38],local[4]);
	goto CON3072;
CON3074:
	local[4]= argv[0];
	local[5]= fqv[26];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[22];
	local[6]= fqv[37];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= loadglobal(fqv[20]);
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,1,local+4,&ftab[1],fqv[25]); /*event-pos*/
	argv[0]->c.obj.iv[13] = w;
	argv[0]->c.obj.iv[14] = NIL;
	local[4]= argv[0]->c.obj.iv[14];
	goto CON3072;
CON3075:
	local[4]= NIL;
CON3072:
	w = local[4];
	local[3]= w;
	goto CON3070;
CON3071:
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[1]));
	local[5]= fqv[39];
	local[6]= loadglobal(fqv[20]);
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,4,local+3); /*send-message*/
	local[3]= w;
	goto CON3070;
CON3076:
	local[3]= NIL;
CON3070:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3069:
	ctx->vsp=local; return(local[0]);}

/*:clear-event*/
static pointer M3077canvas_clear_event(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[36];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK3078:
	ctx->vsp=local; return(local[0]);}

/*:color-event*/
static pointer M3079canvas_color_event(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[24];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3080:
	ctx->vsp=local; return(local[0]);}

/*:background-event*/
static pointer M3081canvas_background_event(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[40];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3082:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M3083graph_canvas_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3085:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[41], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3086;
	local[1] = makeflt(1.00000000e+00);
KEY3086:
	if (n & (1<<1)) goto KEY3087;
	local[2] = makeflt(-1.00000000e+00);
KEY3087:
	if (n & (1<<2)) goto KEY3088;
	local[3] = loadglobal(fqv[42]);
KEY3088:
	if (n & (1<<3)) goto KEY3089;
	local[4] = makeint(1);
KEY3089:
	if (n & (1<<4)) goto KEY3090;
	local[5] = NIL;
KEY3090:
	if (n & (1<<5)) goto KEY3091;
	local[6] = loadglobal(fqv[43]);
KEY3091:
	local[7]= (pointer)get_sym_func(fqv[0]);
	local[8]= argv[0];
	local[9]= *(ovafptr(argv[1],fqv[1]));
	local[10]= fqv[2];
	local[11]= fqv[40];
	local[12]= local[3];
	local[13]= local[0];
	ctx->vsp=local+14;
	w=(pointer)APPLY(ctx,7,local+7); /*apply*/
	local[7]= argv[0];
	local[8]= fqv[44];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= argv[0];
	local[8]= fqv[45];
	local[9]= local[1];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[7]= argv[0];
	local[8]= fqv[46];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	if (local[5]==NIL) goto CON3093;
	local[7]= argv[0];
	local[8]= fqv[47];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	goto CON3092;
CON3093:
	if (local[6]==NIL) goto CON3094;
	local[7]= local[4];
	local[8]= fqv[48];
	local[9]= local[6];
	local[10]= loadglobal(fqv[49]);
	ctx->vsp=local+11;
	w=(pointer)DERIVEDP(ctx,2,local+9); /*derivedp*/
	if (w==NIL) goto IF3095;
	local[9]= local[6];
	goto IF3096;
IF3095:
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(*ftab[6])(ctx,1,local+9,&ftab[6],fqv[50]); /*make-color-gc*/
	local[9]= w;
IF3096:
	ctx->vsp=local+10;
	w=(*ftab[7])(ctx,3,local+7,&ftab[7],fqv[51]); /*make-array*/
	argv[0]->c.obj.iv[23] = w;
	local[7]= argv[0]->c.obj.iv[23];
	goto CON3092;
CON3094:
	local[7]= NIL;
CON3092:
	argv[0]->c.obj.iv[24] = makeint(0);
	local[7]= argv[0];
	local[8]= fqv[36];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	w = argv[0];
	local[0]= w;
BLK3084:
	ctx->vsp=local; return(local[0]);}

/*:new-pixmap*/
static pointer M3097graph_canvas_new_pixmap(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3101;}
	local[0]= argv[0]->c.obj.iv[5];
ENT3101:
	if (n>=4) { local[1]=(argv[3]); goto ENT3100;}
	local[1]= argv[0]->c.obj.iv[6];
ENT3100:
ENT3099:
	if (n>4) maerror();
	local[2]= loadglobal(fqv[52]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[2];
	local[5]= fqv[53];
	local[6]= local[0];
	local[7]= fqv[54];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	w = local[2];
	argv[0]->c.obj.iv[16] = w;
	w = argv[0];
	local[0]= w;
BLK3098:
	ctx->vsp=local; return(local[0]);}

/*:range*/
static pointer M3103graph_canvas_range(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3106;}
	local[0]= makeflt(0.00000000e+00);
ENT3106:
ENT3105:
	if (n>4) maerror();
	argv[0]->c.obj.iv[17] = argv[2];
	argv[0]->c.obj.iv[18] = local[0];
	w = argv[0];
	local[0]= w;
BLK3104:
	ctx->vsp=local; return(local[0]);}

/*:lines*/
static pointer M3107graph_canvas_lines(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[48];
	local[2]= argv[0]->c.obj.iv[18];
	ctx->vsp=local+3;
	w=(*ftab[7])(ctx,3,local+0,&ftab[7],fqv[51]); /*make-array*/
	argv[0]->c.obj.iv[19] = w;
	w = argv[0]->c.obj.iv[19];
	local[0]= w;
BLK3108:
	ctx->vsp=local; return(local[0]);}

/*:colors*/
static pointer M3109graph_canvas_colors(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[19];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[7])(ctx,1,local+0,&ftab[7],fqv[51]); /*make-array*/
	argv[0]->c.obj.iv[23] = w;
	local[0]= NIL;
	local[1]= makeint(0);
	local[2]= argv[0]->c.obj.iv[19];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
WHL3112:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX3113;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[3];
	local[0] = w;
	local[3]= argv[0]->c.obj.iv[23];
	local[4]= local[1];
	local[5]= local[0];
	local[6]= loadglobal(fqv[49]);
	ctx->vsp=local+7;
	w=(pointer)DERIVEDP(ctx,2,local+5); /*derivedp*/
	if (w==NIL) goto IF3116;
	local[5]= local[0];
	goto IF3117;
IF3116:
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[6])(ctx,1,local+5,&ftab[6],fqv[50]); /*make-color-gc*/
	local[5]= w;
IF3117:
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,3,local+3); /*aset*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL3112;
WHX3113:
	local[3]= NIL;
BLK3114:
	w = NIL;
	local[0]= w;
BLK3110:
	ctx->vsp=local; return(local[0]);}

/*:graph*/
static pointer M3118graph_canvas_graph(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3120:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	argv[0]->c.obj.iv[20] = local[0];
	local[1]= (pointer)get_sym_func(fqv[0]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[1]));
	local[4]= fqv[55];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	local[1]= argv[0]->c.obj.iv[16];
	local[2]= fqv[56];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = argv[0];
	local[0]= w;
BLK3119:
	ctx->vsp=local; return(local[0]);}

/*:incremental-graph*/
static pointer M3121graph_canvas_incremental_graph(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= loadglobal(fqv[57]);
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= argv[0]->c.obj.iv[3]->c.obj.iv[2];
	local[4]= makeint(1);
	local[5]= makeint(0);
	local[6]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+7;
	w=(pointer)SUB1(ctx,1,local+6); /*1-*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[6];
	local[8]= makeint(0);
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(*ftab[8])(ctx,10,local+0,&ftab[8],fqv[58]); /*copyarea*/
	local[0]= loadglobal(fqv[57]);
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+3;
	w=(pointer)SUB1(ctx,1,local+2); /*1-*/
	local[2]= w;
	local[3]= makeint(0);
	local[4]= makeint(1);
	local[5]= argv[0]->c.obj.iv[6];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(*ftab[9])(ctx,7,local+0,&ftab[9],fqv[59]); /*cleararea*/
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= makeint(0);
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
WHL3124:
	local[6]= local[4];
	w = local[5];
	if ((eusinteger_t)local[6] >= (eusinteger_t)w) goto WHX3125;
	local[6]= argv[0]->c.obj.iv[19];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[2] = w;
	local[6]= argv[2];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[0] = w;
	local[6]= argv[0]->c.obj.iv[6];
	local[7]= argv[0]->c.obj.iv[6];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)EUSFLOAT(ctx,1,local+8); /*float*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[17];
	local[10]= argv[0]->c.obj.iv[18];
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,2,local+9); /*-*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)ROUND(ctx,1,local+7); /*round*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[1] = w;
	local[6]= argv[0]->c.obj.iv[23];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[3] = w;
	local[6]= argv[0];
	local[7]= fqv[60];
	local[8]= argv[0]->c.obj.iv[5];
	local[9]= makeint(2);
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	local[9]= local[2];
	local[10]= argv[0]->c.obj.iv[5];
	local[11]= local[1];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,7,local+6); /*send*/
	local[6]= argv[0]->c.obj.iv[19];
	local[7]= local[4];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,3,local+6); /*aset*/
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[4] = w;
	goto WHL3124;
WHX3125:
	local[6]= NIL;
BLK3126:
	w = NIL;
	local[4]= argv[0]->c.obj.iv[24];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	argv[0]->c.obj.iv[24] = w;
	local[4]= argv[0]->c.obj.iv[24];
	local[5]= makeint(10);
	ctx->vsp=local+6;
	w=(pointer)MOD(ctx,2,local+4); /*mod*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[10])(ctx,1,local+4,&ftab[10],fqv[61]); /*zerop*/
	if (w==NIL) goto IF3127;
	local[4]= argv[0]->c.obj.iv[16];
	local[5]= fqv[56];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF3128;
IF3127:
	local[4]= NIL;
IF3128:
	w = local[4];
	local[0]= w;
BLK3122:
	ctx->vsp=local; return(local[0]);}

/*:clear*/
static pointer M3129graph_canvas_clear(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[20] = NIL;
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[1]));
	local[2]= fqv[36];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= argv[0]->c.obj.iv[16];
	local[1]= fqv[56];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3130:
	ctx->vsp=local; return(local[0]);}

/*:resize*/
static pointer M3131graph_canvas_resize(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[44];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[1]));
	local[2]= fqv[62];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,5,local+0); /*send-message*/
	local[0]= argv[0];
	local[1]= fqv[63];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK3132:
	ctx->vsp=local; return(local[0]);}

/*:redraw*/
static pointer M3133graph_canvas_redraw(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[20]==NIL) goto IF3135;
	local[0]= (pointer)get_sym_func(fqv[64]);
	local[1]= argv[0];
	local[2]= fqv[55];
	local[3]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,4,local+0); /*apply*/
	local[0]= w;
	goto IF3136;
IF3135:
	local[0]= NIL;
IF3136:
	w = local[0];
	local[0]= w;
BLK3134:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M3137pixmap_scroller_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3139:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[65], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3140;
	local[1] = NIL;
KEY3140:
	local[2]= (pointer)get_sym_func(fqv[0]);
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[1]));
	local[5]= fqv[2];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,5,local+2); /*apply*/
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)PRINT(ctx,1,local+2); /*print*/
	local[2]= loadglobal(fqv[66]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[2];
	local[5]= fqv[67];
	local[6]= argv[0];
	local[7]= fqv[53];
	local[8]= argv[0]->c.obj.iv[5];
	local[9]= makeint(15);
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	local[9]= fqv[54];
	local[10]= argv[0]->c.obj.iv[6];
	local[11]= makeint(15);
	ctx->vsp=local+12;
	w=(pointer)MINUS(ctx,2,local+10); /*-*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,8,local+3); /*send*/
	w = local[2];
	argv[0]->c.obj.iv[25] = w;
	local[2]= loadglobal(fqv[68]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[2];
	local[5]= fqv[67];
	local[6]= argv[0];
	local[7]= fqv[53];
	local[8]= makeint(10);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	w = local[2];
	argv[0]->c.obj.iv[26] = w;
	local[2]= loadglobal(fqv[69]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[2];
	local[5]= fqv[67];
	local[6]= argv[0];
	local[7]= fqv[54];
	local[8]= makeint(10);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	w = local[2];
	argv[0]->c.obj.iv[27] = w;
	local[2]= argv[0];
	local[3]= fqv[70];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	if (local[1]==NIL) goto IF3144;
	local[2]= argv[0];
	local[3]= fqv[71];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF3145;
IF3144:
	local[2]= NIL;
IF3145:
	w = argv[0];
	local[0]= w;
BLK3138:
	ctx->vsp=local; return(local[0]);}

/*:reset-subwindows*/
static pointer M3146pixmap_scroller_reset_subwindows(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[25];
	local[1]= fqv[62];
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= makeint(15);
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[6];
	local[4]= makeint(15);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[26];
	local[1]= fqv[72];
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= makeint(13);
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[27];
	local[1]= fqv[72];
	local[2]= makeint(0);
	local[3]= argv[0]->c.obj.iv[6];
	local[4]= makeint(13);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	w = argv[0];
	local[0]= w;
BLK3147:
	ctx->vsp=local; return(local[0]);}

/*:set-pixmap*/
static pointer M3148pixmap_scroller_set_pixmap(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[28] = argv[2];
	argv[0]->c.obj.iv[29] = makeint(0);
	argv[0]->c.obj.iv[30] = makeint(0);
	local[0]= argv[2];
	local[1]= fqv[53];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[31] = w;
	local[0]= argv[2];
	local[1]= fqv[54];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[32] = w;
	local[0]= argv[0]->c.obj.iv[25];
	local[1]= fqv[56];
	local[2]= argv[0]->c.obj.iv[28];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	w = argv[0]->c.obj.iv[28];
	local[0]= w;
BLK3149:
	ctx->vsp=local; return(local[0]);}

/*:scroll*/
static pointer M3150pixmap_scroller_scroll(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3153;}
	local[0]= makeint(1);
ENT3153:
ENT3152:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= local[0];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)NUMEQUAL(ctx,2,local+5); /*=*/
	if (w==NIL) goto CON3155;
	w = NIL;
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK3151;
	goto CON3154;
CON3155:
	local[5]= local[0];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto CON3156;
	local[2] = local[0];
	local[3] = makeint(0);
	local[5]= argv[0];
	local[6]= fqv[54];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= makeint(16);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[4] = w;
	local[5]= local[4];
	goto CON3154;
CON3156:
	local[2] = makeint(0);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[3] = w;
	local[4] = makeint(0);
	local[5]= local[4];
	goto CON3154;
CON3157:
	local[5]= NIL;
CON3154:
	local[5]= argv[0];
	local[6]= fqv[54];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= makeint(16);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)ABS(ctx,1,local+6); /*abs*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MIN(ctx,2,local+5); /*min*/
	local[0] = w;
	local[5]= T;
	local[6]= fqv[73];
	local[7]= local[0];
	local[8]= local[2];
	local[9]= local[3];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,6,local+5); /*format*/
	local[5]= argv[0]->c.obj.iv[25];
	local[6]= fqv[56];
	local[7]= argv[0]->c.obj.iv[25];
	local[8]= fqv[74];
	local[9]= makeint(2);
	local[10]= fqv[75];
	local[11]= makeint(2);
	local[12]= local[2];
	local[13]= makeint(12);
	ctx->vsp=local+14;
	w=(pointer)TIMES(ctx,2,local+12); /***/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[11]= w;
	local[12]= fqv[53];
	local[13]= argv[0]->c.obj.iv[5];
	local[14]= fqv[54];
	local[15]= argv[0];
	local[16]= fqv[54];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
	local[16]= makeint(16);
	ctx->vsp=local+17;
	w=(pointer)QUOTIENT(ctx,2,local+15); /*/*/
	local[15]= w;
	local[16]= local[0];
	ctx->vsp=local+17;
	w=(pointer)MINUS(ctx,2,local+15); /*-*/
	local[15]= w;
	local[16]= makeint(12);
	ctx->vsp=local+17;
	w=(pointer)TIMES(ctx,2,local+15); /***/
	local[15]= w;
	local[16]= fqv[76];
	local[17]= makeint(2);
	local[18]= fqv[77];
	local[19]= makeint(2);
	local[20]= local[3];
	local[21]= makeint(12);
	ctx->vsp=local+22;
	w=(pointer)TIMES(ctx,2,local+20); /***/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)PLUS(ctx,2,local+19); /*+*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,15,local+5); /*send*/
	local[5]= argv[0]->c.obj.iv[25];
	local[6]= fqv[78];
	local[7]= fqv[76];
	local[8]= makeint(2);
	local[9]= fqv[77];
	local[10]= makeint(2);
	local[11]= local[4];
	local[12]= makeint(12);
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[10]= w;
	local[11]= fqv[53];
	local[12]= argv[0]->c.obj.iv[5];
	local[13]= fqv[54];
	local[14]= local[0];
	local[15]= makeint(12);
	ctx->vsp=local+16;
	w=(pointer)TIMES(ctx,2,local+14); /***/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,10,local+5); /*send*/
	local[0]= w;
BLK3151:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___Xcanvas(ctx,n,argv,env)
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
	local[0]= fqv[79];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF3158;
	local[0]= fqv[80];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[81],w);
	goto IF3159;
IF3158:
	local[0]= fqv[82];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF3159:
	local[0]= fqv[83];
	local[1]= fqv[84];
	ctx->vsp=local+2;
	w=(*ftab[11])(ctx,2,local+0,&ftab[11],fqv[85]); /*require*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3044canvas_create,fqv[2],fqv[86],fqv[87]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3048canvas_selection,fqv[88],fqv[86],fqv[89]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3050canvas_adjust_corners,fqv[90],fqv[86],fqv[91]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3054canvas_draw_selection_rectangle,fqv[26],fqv[86],fqv[92]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3056canvas_buttonpress,fqv[93],fqv[86],fqv[94]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3061canvas_motionnotify,fqv[34],fqv[86],fqv[95]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3068canvas_buttonrelease,fqv[39],fqv[86],fqv[96]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3077canvas_clear_event,fqv[13],fqv[86],fqv[97]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3079canvas_color_event,fqv[7],fqv[86],fqv[98]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3081canvas_background_event,fqv[15],fqv[86],fqv[99]);
	local[0]= fqv[100];
	local[1]= fqv[101];
	local[2]= fqv[100];
	local[3]= fqv[102];
	local[4]= loadglobal(fqv[86]);
	local[5]= fqv[103];
	local[6]= fqv[104];
	local[7]= fqv[105];
	local[8]= NIL;
	local[9]= fqv[106];
	local[10]= NIL;
	local[11]= fqv[107];
	local[12]= makeint(-1);
	local[13]= fqv[108];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[12])(ctx,13,local+2,&ftab[12],fqv[109]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3083graph_canvas_create,fqv[2],fqv[100],fqv[110]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3097graph_canvas_new_pixmap,fqv[44],fqv[100],fqv[111]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3103graph_canvas_range,fqv[45],fqv[100],fqv[112]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3107graph_canvas_lines,fqv[46],fqv[100],fqv[113]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3109graph_canvas_colors,fqv[47],fqv[100],fqv[114]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3118graph_canvas_graph,fqv[55],fqv[100],fqv[115]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3121graph_canvas_incremental_graph,fqv[116],fqv[100],fqv[117]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3129graph_canvas_clear,fqv[36],fqv[100],fqv[118]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3131graph_canvas_resize,fqv[62],fqv[100],fqv[119]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3133graph_canvas_redraw,fqv[120],fqv[100],fqv[121]);
	local[0]= fqv[122];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[123];
	local[1]= fqv[101];
	local[2]= fqv[123];
	local[3]= fqv[102];
	local[4]= loadglobal(fqv[124]);
	local[5]= fqv[103];
	local[6]= fqv[125];
	local[7]= fqv[105];
	local[8]= NIL;
	local[9]= fqv[106];
	local[10]= NIL;
	local[11]= fqv[107];
	local[12]= makeint(-1);
	local[13]= fqv[108];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[12])(ctx,13,local+2,&ftab[12],fqv[109]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3137pixmap_scroller_create,fqv[2],fqv[123],fqv[126]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3146pixmap_scroller_reset_subwindows,fqv[70],fqv[123],fqv[127]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3148pixmap_scroller_set_pixmap,fqv[71],fqv[123],fqv[128]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3150pixmap_scroller_scroll,fqv[129],fqv[123],fqv[130]);
	local[0]= fqv[131];
	local[1]= fqv[132];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,2,local+0,&ftab[13],fqv[133]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<14; i++) ftab[i]=fcallx;
}
