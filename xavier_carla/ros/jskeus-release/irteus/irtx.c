/* ./irtx.c :  entry=irtx */
/* compiled by EusLisp 9.27() for Linux created on ip-10-0-1-214(Fri Apr 16 04:05:26 PST 2021) */
#include "eus.h"
#include "irtx.h"
#pragma init (register_irtx)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___irtx();
extern pointer build_quote_vector();
static int register_irtx()
  { add_module_initializer("___irtx", ___irtx);}

static pointer F61window_main_one();
static pointer F62event_far();
static pointer F63event_near();

/*window-main-one*/
static pointer F61window_main_one(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT66;}
	local[0]= NIL;
ENT66:
ENT65:
	if (n>1) maerror();
	if (loadglobal(fqv[0])==NIL) goto OR69;
	local[1]= loadglobal(fqv[0]);
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)NUMEQUAL(ctx,2,local+1); /*=*/
	if (w!=NIL) goto OR69;
	goto IF67;
OR69:
	local[1]= makeint((eusinteger_t)3L);
	local[2]= fqv[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,3,local+1,&ftab[0],fqv[2]); /*warning-message*/
	w = NIL;
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK64;
	goto IF68;
IF67:
	local[1]= NIL;
IF68:
	{jmp_buf jb;
	w = fqv[3];
	ctx->vsp=local+1;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT70;}
WHL71:
	local[7]= loadglobal(fqv[0]);
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(*ftab[1])(ctx,2,local+7,&ftab[1],fqv[4]); /*eventsqueued*/
	local[7]= w;
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)GREATERP(ctx,2,local+7); /*>*/
	if (w==NIL) goto WHX72;
	local[7]= loadglobal(fqv[0]);
	local[8]= loadglobal(fqv[5]);
	ctx->vsp=local+9;
	w=(*ftab[2])(ctx,2,local+7,&ftab[2],fqv[6]); /*nextevent*/
	if (loadglobal(fqv[7])==NIL) goto IF74;
	local[7]= loadglobal(fqv[5]);
	ctx->vsp=local+8;
	w=(*ftab[3])(ctx,1,local+7,&ftab[3],fqv[8]); /*print-event*/
	local[7]= w;
	goto IF75;
IF74:
	local[7]= NIL;
IF75:
	if (loadglobal(fqv[9])==NIL) goto IF76;
	local[7]= loadglobal(fqv[5]);
	ctx->vsp=local+8;
	w=(*ftab[4])(ctx,1,local+7,&ftab[4],fqv[10]); /*event-type*/
	local[7]= w;
	w = loadglobal(fqv[9]);
	if (memq(local[7],w)==NIL) goto IF76;
WHL78:
	local[7]= loadglobal(fqv[0]);
	ctx->vsp=local+8;
	w=(*ftab[5])(ctx,1,local+7,&ftab[5],fqv[11]); /*pending*/
	local[7]= w;
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)GREATERP(ctx,2,local+7); /*>*/
	if (w==NIL) goto WHX79;
	local[7]= loadglobal(fqv[0]);
	local[8]= loadglobal(fqv[12]);
	ctx->vsp=local+9;
	w=(*ftab[6])(ctx,2,local+7,&ftab[6],fqv[13]); /*peekevent*/
	local[7]= loadglobal(fqv[12]);
	ctx->vsp=local+8;
	w=(*ftab[4])(ctx,1,local+7,&ftab[4],fqv[10]); /*event-type*/
	local[7]= w;
	w = loadglobal(fqv[9]);
	local[7]= memq(local[7],w);
	if (local[7]==NIL) goto AND81;
	local[7]= loadglobal(fqv[5]);
	ctx->vsp=local+8;
	w=(*ftab[7])(ctx,1,local+7,&ftab[7],fqv[14]); /*xevent-type*/
	local[7]= w;
	local[8]= loadglobal(fqv[12]);
	ctx->vsp=local+9;
	w=(*ftab[7])(ctx,1,local+8,&ftab[7],fqv[14]); /*xevent-type*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)NUMEQUAL(ctx,2,local+7); /*=*/
	local[7]= w;
	if (w==NIL) goto AND81;
	local[7]= loadglobal(fqv[5]);
	ctx->vsp=local+8;
	w=(*ftab[8])(ctx,1,local+7,&ftab[8],fqv[15]); /*xevent-window*/
	local[7]= w;
	local[8]= loadglobal(fqv[12]);
	ctx->vsp=local+9;
	w=(*ftab[8])(ctx,1,local+8,&ftab[8],fqv[15]); /*xevent-window*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)NUMEQUAL(ctx,2,local+7); /*=*/
	local[7]= w;
AND81:
	if (local[7]==NIL) goto WHX79;
	local[7]= loadglobal(fqv[0]);
	local[8]= loadglobal(fqv[5]);
	ctx->vsp=local+9;
	w=(*ftab[2])(ctx,2,local+7,&ftab[2],fqv[6]); /*nextevent*/
	local[7]= loadglobal(fqv[16]);
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[7]= w;
	storeglobal(fqv[16],w);
	goto WHL78;
WHX79:
	local[7]= NIL;
BLK80:
	goto IF77;
IF76:
	local[7]= NIL;
IF77:
	local[7]= loadglobal(fqv[5]);
	ctx->vsp=local+8;
	w=(*ftab[9])(ctx,1,local+7,&ftab[9],fqv[17]); /*process-event*/
	goto WHL71;
WHX72:
	local[7]= NIL;
BLK73:
	ctx->vsp=local+7;
	w=(*ftab[10])(ctx,0,local+7,&ftab[10],fqv[18]); /*xflush*/
CAT70:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[0]= w;
BLK64:
	ctx->vsp=local; return(local[0]);}

/*event-far*/
static pointer F62event_far(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[11])(ctx,1,local+0,&ftab[11],fqv[19]); /*xevent-state*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)2048L);
	ctx->vsp=local+2;
	w=(pointer)LOGTEST(ctx,2,local+0); /*logtest*/
	local[0]= w;
BLK82:
	ctx->vsp=local; return(local[0]);}

/*event-near*/
static pointer F63event_near(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[11])(ctx,1,local+0,&ftab[11],fqv[19]); /*xevent-state*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)4096L);
	ctx->vsp=local+2;
	w=(pointer)LOGTEST(ctx,2,local+0); /*logtest*/
	local[0]= w;
BLK83:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M84xwindow_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST86:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= (pointer)get_sym_func(fqv[20]);
	local[4]= argv[0];
	local[5]= fqv[21];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,4,local+3); /*apply*/
	local[1] = fqv[22];
	local[3]= loadglobal(fqv[0]);
	local[4]= makeint((eusinteger_t)16L);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)ADDRESS(ctx,1,local+5); /*system:address*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	local[5]= makeint((eusinteger_t)1L);
	ctx->vsp=local+6;
	w=(*ftab[12])(ctx,3,local+3,&ftab[12],fqv[23]); /*internatom*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MKINTVECTOR(ctx,1,local+3); /*integer-vector*/
	local[2] = w;
	local[3]= loadglobal(fqv[0]);
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= makeint((eusinteger_t)16L);
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)ADDRESS(ctx,1,local+6); /*system:address*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(*ftab[13])(ctx,4,local+3,&ftab[13],fqv[24]); /*setwmprotocols*/
	w = argv[0];
	local[0]= w;
BLK85:
	ctx->vsp=local; return(local[0]);}

/*:event-notify*/
static pointer M87xwindow_event_notify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	w = argv[3];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[5],w);
	local[3]= argv[2];
	local[4]= fqv[25];
	ctx->vsp=local+5;
	w=(*ftab[14])(ctx,2,local+3,&ftab[14],fqv[26]); /*member*/
	if (w==NIL) goto IF89;
	local[3]= argv[0];
	local[4]= fqv[27];
	local[5]= argv[2];
	local[6]= loadglobal(fqv[5]);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF90;
IF89:
	local[3]= argv[0];
	local[4]= fqv[28];
	local[5]= argv[2];
	local[6]= loadglobal(fqv[5]);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
IF90:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK88:
	ctx->vsp=local; return(local[0]);}

/*:quit*/
static pointer M91xwindow_quit(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST93:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0];
	local[2]= fqv[29];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= loadglobal(fqv[0]);
	local[2]= makeint((eusinteger_t)1L);
	ctx->vsp=local+3;
	w=(*ftab[15])(ctx,2,local+1,&ftab[15],fqv[30]); /*sync*/
	w = fqv[31];
	local[0]= w;
BLK92:
	ctx->vsp=local; return(local[0]);}

/*:clientmessage*/
static pointer M94xwindow_clientmessage(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[5],w);
	local[3]= argv[0];
	local[4]= fqv[32];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK95:
	ctx->vsp=local; return(local[0]);}

/*:set-event-proc*/
static pointer M96xwindow_set_event_proc(ctx,n,argv,env)
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
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[33];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[33];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= w;
BLK97:
	ctx->vsp=local; return(local[0]);}

/*:buttonrelease*/
static pointer M98xwindow_buttonrelease(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[5],w);
	local[3]= argv[0];
	local[4]= fqv[33];
	ctx->vsp=local+5;
	w=(pointer)GETPROP(ctx,2,local+3); /*get*/
	local[3]= w;
	local[4]= NIL;
	local[5]= loadglobal(fqv[5]);
	ctx->vsp=local+6;
	w=(*ftab[16])(ctx,1,local+5,&ftab[16],fqv[34]); /*event-left*/
	if (w==NIL) goto CON101;
	local[5]= fqv[35];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(*ftab[17])(ctx,2,local+5,&ftab[17],fqv[36]); /*assoc*/
	local[4] = w;
	local[5]= local[4];
	goto CON100;
CON101:
	local[5]= loadglobal(fqv[5]);
	ctx->vsp=local+6;
	w=(*ftab[18])(ctx,1,local+5,&ftab[18],fqv[37]); /*event-right*/
	if (w==NIL) goto CON102;
	local[5]= fqv[38];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(*ftab[17])(ctx,2,local+5,&ftab[17],fqv[36]); /*assoc*/
	local[4] = w;
	local[5]= local[4];
	goto CON100;
CON102:
	local[5]= loadglobal(fqv[5]);
	ctx->vsp=local+6;
	w=(*ftab[19])(ctx,1,local+5,&ftab[19],fqv[39]); /*event-middle*/
	if (w==NIL) goto CON103;
	local[5]= fqv[40];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(*ftab[17])(ctx,2,local+5,&ftab[17],fqv[36]); /*assoc*/
	local[4] = w;
	local[5]= local[4];
	goto CON100;
CON103:
	local[5]= loadglobal(fqv[5]);
	ctx->vsp=local+6;
	w=(pointer)F62event_far(ctx,1,local+5); /*event-far*/
	if (w==NIL) goto CON104;
	local[5]= fqv[41];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(*ftab[17])(ctx,2,local+5,&ftab[17],fqv[36]); /*assoc*/
	local[4] = w;
	local[5]= local[4];
	goto CON100;
CON104:
	local[5]= loadglobal(fqv[5]);
	ctx->vsp=local+6;
	w=(pointer)F63event_near(ctx,1,local+5); /*event-near*/
	if (w==NIL) goto CON105;
	local[5]= fqv[42];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(*ftab[17])(ctx,2,local+5,&ftab[17],fqv[36]); /*assoc*/
	local[4] = w;
	local[5]= local[4];
	goto CON100;
CON105:
	local[5]= NIL;
CON100:
	if (local[4]==NIL) goto IF106;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= loadglobal(fqv[5]);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF107;
IF106:
	local[5]= NIL;
IF107:
	w = local[5];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK99:
	ctx->vsp=local; return(local[0]);}

/*:motionnotify*/
static pointer M108xwindow_motionnotify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[5],w);
	local[3]= argv[0];
	local[4]= fqv[33];
	ctx->vsp=local+5;
	w=(pointer)GETPROP(ctx,2,local+3); /*get*/
	local[3]= w;
	local[4]= NIL;
	local[5]= loadglobal(fqv[5]);
	ctx->vsp=local+6;
	w=(*ftab[16])(ctx,1,local+5,&ftab[16],fqv[34]); /*event-left*/
	if (w==NIL) goto CON111;
	local[5]= fqv[43];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(*ftab[17])(ctx,2,local+5,&ftab[17],fqv[36]); /*assoc*/
	local[4] = w;
	local[5]= local[4];
	goto CON110;
CON111:
	local[5]= loadglobal(fqv[5]);
	ctx->vsp=local+6;
	w=(*ftab[18])(ctx,1,local+5,&ftab[18],fqv[37]); /*event-right*/
	if (w==NIL) goto CON112;
	local[5]= fqv[44];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(*ftab[17])(ctx,2,local+5,&ftab[17],fqv[36]); /*assoc*/
	local[4] = w;
	local[5]= local[4];
	goto CON110;
CON112:
	local[5]= loadglobal(fqv[5]);
	ctx->vsp=local+6;
	w=(*ftab[19])(ctx,1,local+5,&ftab[19],fqv[39]); /*event-middle*/
	if (w==NIL) goto CON113;
	local[5]= fqv[45];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(*ftab[17])(ctx,2,local+5,&ftab[17],fqv[36]); /*assoc*/
	local[4] = w;
	local[5]= local[4];
	goto CON110;
CON113:
	local[5]= NIL;
CON110:
	if (local[4]==NIL) goto IF114;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= loadglobal(fqv[5]);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF115;
IF114:
	local[5]= NIL;
IF115:
	w = local[5];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK109:
	ctx->vsp=local; return(local[0]);}

/*:buttonpress*/
static pointer M116xwindow_buttonpress(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[5],w);
	local[3]= fqv[46];
	local[4]= argv[0];
	local[5]= fqv[33];
	ctx->vsp=local+6;
	w=(pointer)GETPROP(ctx,2,local+4); /*get*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[17])(ctx,2,local+3,&ftab[17],fqv[36]); /*assoc*/
	local[3]= w;
	if (local[3]==NIL) goto IF118;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= loadglobal(fqv[5]);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF119;
IF118:
	local[4]= NIL;
IF119:
	w = local[4];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK117:
	ctx->vsp=local; return(local[0]);}

/*:quit*/
static pointer M120panel_quit(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST122:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[47]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[48]));
	local[4]= fqv[32];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	local[0]= w;
BLK121:
	ctx->vsp=local; return(local[0]);}

/*:redraw*/
static pointer M123xscroll_bar_redraw(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[49];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK124:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M125tabbed_panel_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST127:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[47]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[48]));
	local[4]= fqv[50];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	w = argv[0];
	local[0]= w;
BLK126:
	ctx->vsp=local; return(local[0]);}

/*:add-tabbed-panel*/
static pointer M128tabbed_panel_add_tabbed_panel(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= loadglobal(fqv[51]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[50];
	local[4]= argv[2];
	local[5]= argv[0];
	local[6]= fqv[52];
	local[7]= fqv[53];
	local[8]= NIL;
	local[9]= fqv[54];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,9,local+2); /*send*/
	w = local[1];
	local[0] = w;
	local[1]= argv[0];
	local[2]= fqv[55];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= local[0];
	local[2]= fqv[56];
	local[3]= fqv[57];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[25];
	local[2]= fqv[56];
	local[3]= fqv[58];
	ctx->vsp=local+4;
	w=(*ftab[20])(ctx,3,local+1,&ftab[20],fqv[59]); /*send-all*/
	local[1]= local[0];
	w = argv[0]->c.obj.iv[25];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[25] = cons(ctx,local[1],w);
	local[1]= local[0];
	w = argv[0]->c.obj.iv[13];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[13] = cons(ctx,local[1],w);
	local[1]= loadglobal(fqv[60]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[50];
	local[4]= fqv[61];
	local[5]= makeint((eusinteger_t)1L);
	local[6]= fqv[62];
	local[7]= makeint((eusinteger_t)24L);
	local[8]= fqv[63];
	local[9]= argv[0];
	local[10]= fqv[63];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	local[10]= makeint((eusinteger_t)4L);
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,2,local+9); /*-*/
	local[9]= w;
	local[10]= fqv[64];
	local[11]= argv[0];
	local[12]= fqv[64];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	local[12]= makeint((eusinteger_t)27L);
	ctx->vsp=local+13;
	w=(pointer)MINUS(ctx,2,local+11); /*-*/
	local[11]= w;
	local[12]= fqv[65];
	local[13]= argv[2];
	local[14]= fqv[54];
	local[15]= argv[0];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,14,local+2); /*send*/
	w = local[1];
	local[0] = w;
	local[1]= local[0];
	w = argv[0]->c.obj.iv[26];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[26] = cons(ctx,local[1],w);
	local[1]= local[0];
	w = argv[0]->c.obj.iv[13];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[13] = cons(ctx,local[1],w);
	w = local[0];
	local[0]= w;
BLK129:
	ctx->vsp=local; return(local[0]);}

/*:change-tabbed-panel*/
static pointer M132tabbed_panel_change_tabbed_panel(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[66];
	w = argv[2];
	if (!isstring(w)) goto IF134;
	local[3]= argv[2];
	goto IF135;
IF134:
	local[3]= argv[2];
	local[4]= fqv[65];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
IF135:
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[0]->c.obj.iv[27] = w;
	if (argv[0]->c.obj.iv[27]==NIL) goto IF136;
	local[1]= argv[0]->c.obj.iv[26];
	local[2]= fqv[67];
	ctx->vsp=local+3;
	w=(*ftab[20])(ctx,2,local+1,&ftab[20],fqv[59]); /*send-all*/
	local[1]= argv[0]->c.obj.iv[27];
	local[2]= fqv[53];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF137;
IF136:
	local[1]= NIL;
IF137:
	local[1]= argv[0]->c.obj.iv[25];
	local[2]= fqv[68];
	local[3]= fqv[58];
	ctx->vsp=local+4;
	w=(*ftab[20])(ctx,3,local+1,&ftab[20],fqv[59]); /*send-all*/
	local[1]= argv[0];
	local[2]= fqv[69];
	w = argv[2];
	if (!isstring(w)) goto IF138;
	local[3]= argv[2];
	goto IF139;
IF138:
	local[3]= argv[2];
	local[4]= fqv[65];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
IF139:
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0] = w;
	if (local[0]==NIL) goto IF140;
	local[1]= local[0];
	local[2]= fqv[68];
	local[3]= fqv[57];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF141;
IF140:
	local[1]= NIL;
IF141:
	w = local[0];
	local[0]= w;
BLK133:
	ctx->vsp=local; return(local[0]);}

/*:tabbed-button*/
static pointer M142tabbed_panel_tabbed_button(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST144:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	local[1]= NIL;
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[25];
	local[4]= fqv[70];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO145,env,argv,local);
	local[6]= fqv[71];
	local[7]= (pointer)get_sym_func(fqv[72]);
	ctx->vsp=local+8;
	w=(*ftab[14])(ctx,6,local+2,&ftab[14],fqv[26]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	if (local[1]==NIL) goto IF146;
	if (local[0]==NIL) goto IF146;
	local[2]= (pointer)get_sym_func(fqv[20]);
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,3,local+2); /*apply*/
	local[2]= w;
	goto IF147;
IF146:
	local[2]= local[1];
IF147:
	w = local[2];
	local[0]= w;
BLK143:
	ctx->vsp=local; return(local[0]);}

/*:tabbed-panel*/
static pointer M148tabbed_panel_tabbed_panel(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST150:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	local[1]= NIL;
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[26];
	local[4]= fqv[70];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO151,env,argv,local);
	local[6]= fqv[71];
	local[7]= (pointer)get_sym_func(fqv[72]);
	ctx->vsp=local+8;
	w=(*ftab[14])(ctx,6,local+2,&ftab[14],fqv[26]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	if (local[1]==NIL) goto IF152;
	if (local[0]==NIL) goto IF152;
	local[2]= (pointer)get_sym_func(fqv[20]);
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,3,local+2); /*apply*/
	local[2]= w;
	goto IF153;
IF152:
	local[2]= local[1];
IF153:
	w = local[2];
	local[0]= w;
BLK149:
	ctx->vsp=local; return(local[0]);}

/*:resize*/
static pointer M154tabbed_panel_resize(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[48]));
	local[2]= fqv[73];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,5,local+0); /*send-message*/
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[26];
WHL157:
	if (local[1]==NIL) goto WHX158;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= fqv[73];
	local[4]= argv[2];
	local[5]= makeint((eusinteger_t)4L);
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	local[5]= argv[3];
	local[6]= makeint((eusinteger_t)34L);
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	goto WHL157;
WHX158:
	local[2]= NIL;
BLK159:
	w = NIL;
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= fqv[74];
	local[2]= NIL;
	ctx->vsp=local+3;
	w=(*ftab[20])(ctx,3,local+0,&ftab[20],fqv[59]); /*send-all*/
	local[0]= w;
BLK155:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO145(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[65];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO151(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[65];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:draw-label*/
static pointer M161panel_tab_button_item_draw_label(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT165;}
	local[0]= fqv[57];
ENT165:
	if (n>=4) { local[1]=(argv[3]); goto ENT164;}
	local[1]= makeint((eusinteger_t)0L);
ENT164:
ENT163:
	if (n>4) maerror();
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= fqv[75];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	argv[0]->c.obj.iv[21] = local[0];
	local[3]= local[0];
	if (fqv[57]!=local[3]) goto IF166;
	local[3]= argv[0]->c.obj.iv[3];
	local[4]= fqv[75];
	local[5]= loadglobal(fqv[76]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF167;
IF166:
	local[3]= argv[0]->c.obj.iv[3];
	local[4]= fqv[75];
	local[5]= argv[0]->c.obj.iv[22];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
IF167:
	local[3]= argv[0];
	local[4]= fqv[77];
	local[5]= makeint((eusinteger_t)0L);
	local[6]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,2,local+5); /*float-vector*/
	local[5]= w;
	local[6]= makeint((eusinteger_t)0L);
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,2,local+6); /*float-vector*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+8;
	w=(pointer)SUB1(ctx,1,local+7); /*1-*/
	local[7]= w;
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,2,local+7); /*float-vector*/
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+9;
	w=(pointer)SUB1(ctx,1,local+8); /*1-*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,2,local+8); /*float-vector*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,4,local+5); /*list*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[0];
	local[4]= fqv[78];
	local[5]= argv[0]->c.obj.iv[5];
	local[6]= makeint((eusinteger_t)2L);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[17];
	local[7]= makeint((eusinteger_t)2L);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= makeint((eusinteger_t)2L);
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,1,local+6); /*-*/
	local[6]= w;
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,3,local+5); /*+*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[6];
	local[7]= makeint((eusinteger_t)2L);
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[17];
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,2,local+7); /*aref*/
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[17];
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[17];
	local[10]= makeint((eusinteger_t)1L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,2,local+9); /*aref*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,1,local+8); /*-*/
	local[8]= w;
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,4,local+6); /*+*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,5,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[3];
	local[4]= fqv[75];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[0];
	local[4]= fqv[79];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[0]= w;
BLK162:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___irtx(ctx,n,argv,env)
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
	local[0]= fqv[80];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF168;
	local[0]= fqv[81];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[82],w);
	goto IF169;
IF168:
	local[0]= fqv[83];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF169:
	local[0]= fqv[84];
	local[1]= fqv[85];
	local[2]= fqv[74];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
	storeglobal(fqv[9],w);
	ctx->vsp=local+0;
	compfun(ctx,fqv[86],module,F61window_main_one,fqv[87]);
	if (loadglobal(fqv[88])==NIL) goto IF170;
	if (loadglobal(fqv[0])==NIL) goto IF170;
	local[0]= loadglobal(fqv[0]);
	if (makeint((eusinteger_t)0L)==local[0]) goto IF170;
	local[0]= loadglobal(fqv[89]);
	local[1]= fqv[90];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,0,local+2,&ftab[21],fqv[91]); /*display-fd*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= loadglobal(fqv[89]);
	local[1]= fqv[92];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,0,local+2,&ftab[21],fqv[91]); /*display-fd*/
	local[2]= w;
	local[3]= (pointer)get_sym_func(fqv[86]);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF171;
IF170:
	local[0]= NIL;
IF171:
	local[0]= NIL;
	local[1]= NIL;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[22])(ctx,1,local+2,&ftab[22],fqv[93]); /*probe-file*/
	if (w==NIL) goto IF172;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[23])(ctx,1,local+2,&ftab[23],fqv[94]); /*load-foreign*/
	local[0] = w;
	local[2]= local[0];
	goto IF173;
IF172:
	ctx->vsp=local+2;
	w=(*ftab[24])(ctx,0,local+2,&ftab[24],fqv[95]); /*system::sysmod*/
	local[0] = w;
	local[2]= local[0];
IF173:
	local[2]= fqv[24];
	local[3]= fqv[96];
	local[4]= fqv[97];
	local[5]= fqv[98];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[25])(ctx,4,local+3,&ftab[25],fqv[99]); /*make-foreign-code*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SETFUNC(ctx,2,local+2); /*lisp::setfunc*/
	local[0]= fqv[21];
	local[1]= loadglobal(fqv[100]);
	local[2]= fqv[101];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[36]); /*assoc*/
	if (w!=NIL) goto IF174;
	local[0]= fqv[50];
	local[1]= loadglobal(fqv[100]);
	local[2]= fqv[101];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[36]); /*assoc*/
	local[0]= w;
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)RPLACA(ctx,2,local+0); /*rplaca*/
	local[0]= w;
	goto IF175;
IF174:
	local[0]= NIL;
IF175:
	local[0]= fqv[28];
	local[1]= loadglobal(fqv[100]);
	local[2]= fqv[101];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[36]); /*assoc*/
	if (w!=NIL) goto IF176;
	local[0]= fqv[102];
	local[1]= loadglobal(fqv[100]);
	local[2]= fqv[101];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[36]); /*assoc*/
	local[0]= w;
	local[1]= fqv[28];
	ctx->vsp=local+2;
	w=(pointer)RPLACA(ctx,2,local+0); /*rplaca*/
	local[0]= w;
	goto IF177;
IF176:
	local[0]= NIL;
IF177:
	ctx->vsp=local+0;
	compfun(ctx,fqv[103],module,F62event_far,fqv[104]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[105],module,F63event_near,fqv[106]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84xwindow_create,fqv[50],fqv[100],fqv[107]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M87xwindow_event_notify,fqv[102],fqv[100],fqv[108]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M91xwindow_quit,fqv[32],fqv[100],fqv[109]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M94xwindow_clientmessage,fqv[110],fqv[100],fqv[111]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M96xwindow_set_event_proc,fqv[112],fqv[100],fqv[113]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M98xwindow_buttonrelease,fqv[114],fqv[100],fqv[115]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M108xwindow_motionnotify,fqv[84],fqv[100],fqv[116]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M116xwindow_buttonpress,fqv[46],fqv[100],fqv[117]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M120panel_quit,fqv[32],fqv[60],fqv[118]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M123xscroll_bar_redraw,fqv[119],fqv[120],fqv[121]);
	local[0]= fqv[122];
	local[1]= fqv[123];
	local[2]= fqv[122];
	local[3]= fqv[124];
	local[4]= loadglobal(fqv[60]);
	local[5]= fqv[125];
	local[6]= fqv[126];
	local[7]= fqv[127];
	local[8]= NIL;
	local[9]= fqv[128];
	local[10]= NIL;
	local[11]= fqv[129];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[130];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[26])(ctx,13,local+2,&ftab[26],fqv[131]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M125tabbed_panel_create,fqv[50],fqv[122],fqv[132]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M128tabbed_panel_add_tabbed_panel,fqv[133],fqv[122],fqv[134]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M132tabbed_panel_change_tabbed_panel,fqv[52],fqv[122],fqv[135]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M142tabbed_panel_tabbed_button,fqv[69],fqv[122],fqv[136]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M148tabbed_panel_tabbed_panel,fqv[66],fqv[122],fqv[137]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M154tabbed_panel_resize,fqv[73],fqv[122],fqv[138]);
	local[0]= fqv[51];
	local[1]= fqv[123];
	local[2]= fqv[51];
	local[3]= fqv[124];
	local[4]= loadglobal(fqv[139]);
	local[5]= fqv[125];
	local[6]= fqv[97];
	local[7]= fqv[127];
	local[8]= NIL;
	local[9]= fqv[128];
	local[10]= NIL;
	local[11]= fqv[129];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[130];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[26])(ctx,13,local+2,&ftab[26],fqv[131]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M161panel_tab_button_item_draw_label,fqv[68],fqv[51],fqv[140]);
	local[0]= fqv[141];
	local[1]= fqv[142];
	ctx->vsp=local+2;
	w=(*ftab[27])(ctx,2,local+0,&ftab[27],fqv[143]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<28; i++) ftab[i]=fcallx;
}
