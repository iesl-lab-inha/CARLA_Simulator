/* ./Xmenu.c :  entry=Xmenu */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "Xmenu.h"
#pragma init (register_Xmenu)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___Xmenu();
extern pointer build_quote_vector();
static int register_Xmenu()
  { add_module_initializer("___Xmenu", ___Xmenu);}


/*:create*/
static pointer M3160menu_panel_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3162:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[0], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3163;
	local[1] = loadglobal(fqv[1]);
KEY3163:
	if (n & (1<<1)) goto KEY3164;
	local[2] = makeint(2);
KEY3164:
	if (n & (1<<2)) goto KEY3165;
	local[3] = makeint(100);
KEY3165:
	if (n & (1<<3)) goto KEY3166;
	local[4] = loadglobal(fqv[2]);
KEY3166:
	local[5]= (pointer)get_sym_func(fqv[3]);
	local[6]= argv[0];
	local[7]= *(ovafptr(argv[1],fqv[4]));
	local[8]= fqv[5];
	local[9]= fqv[6];
	local[10]= local[1];
	local[11]= fqv[7];
	local[12]= local[4];
	local[13]= fqv[8];
	local[14]= makeint(100);
	local[15]= fqv[9];
	local[16]= local[2];
	local[17]= fqv[10];
	local[18]= NIL;
	local[19]= fqv[11];
	local[20]= T;
	local[21]= fqv[12];
	local[22]= fqv[13];
	local[23]= local[0];
	ctx->vsp=local+24;
	w=(pointer)APPLY(ctx,19,local+5); /*apply*/
	argv[0]->c.obj.iv[17] = makeint(2);
	argv[0]->c.obj.iv[18] = makeint(2);
	argv[0]->c.obj.iv[26] = NIL;
	w = argv[0];
	local[0]= w;
BLK3161:
	ctx->vsp=local; return(local[0]);}

/*:find-button*/
static pointer M3167menu_panel_find_button(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[8];
WHL3170:
	if (local[1]==NIL) goto WHX3171;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[2];
	local[3]= local[0];
	local[4]= fqv[14];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,2,local+2,&ftab[0],fqv[15]); /*string-equal*/
	if (w==NIL) goto IF3174;
	w = local[0];
	ctx->vsp=local+2;
	local[2]=w;
	goto BLK3172;
	goto IF3175;
IF3174:
	local[2]= NIL;
IF3175:
	goto WHL3170;
WHX3171:
	local[2]= NIL;
BLK3172:
	w = local[0];
	local[0]= w;
BLK3168:
	ctx->vsp=local; return(local[0]);}

/*:newsize*/
static pointer M3176menu_panel_newsize(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(4);
	local[1]= (pointer)get_sym_func(fqv[16]);
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO3178,env,argv,local);
	local[3]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[5] = w;
	local[0]= makeint(4);
	local[1]= (pointer)get_sym_func(fqv[17]);
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO3179,env,argv,local);
	local[3]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[6] = w;
	local[0]= argv[0];
	local[1]= fqv[18];
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO3180,env,argv,local);
	local[1]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	w = argv[0];
	local[0]= w;
BLK3177:
	ctx->vsp=local; return(local[0]);}

/*:create-item*/
static pointer M3181menu_panel_create_item(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<6) maerror();
RST3183:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-6);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[19], &argv[6], n-6, local+1, 1);
	if (n & (1<<0)) goto KEY3184;
	local[1] = argv[0]->c.obj.iv[14];
KEY3184:
	if (n & (1<<1)) goto KEY3185;
	local[2] = NIL;
KEY3185:
	local[3]= NIL;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= (pointer)get_sym_func(fqv[20]);
	local[6]= local[4];
	local[7]= fqv[5];
	local[8]= argv[3];
	local[9]= argv[4];
	local[10]= argv[5];
	local[11]= fqv[21];
	local[12]= fqv[22];
	local[13]= fqv[23];
	local[14]= argv[0]->c.obj.iv[4];
	local[15]= fqv[6];
	local[16]= local[1];
	local[17]= fqv[24];
	local[18]= argv[0];
	local[19]= fqv[12];
	local[20]= fqv[25];
	local[21]= local[0];
	ctx->vsp=local+22;
	w=(pointer)APPLY(ctx,17,local+5); /*apply*/
	w = local[4];
	local[3] = w;
	local[4]= local[3];
	local[5]= fqv[26];
	local[6]= local[3]->c.obj.iv[4];
	local[7]= makeflt(1.20000000e+00);
	local[8]= local[3];
	local[9]= fqv[27];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[1])(ctx,3,local+6,&ftab[1],fqv[28]); /*get-redish-pixel*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[29];
	local[6]= local[3];
	local[7]= argv[0]->c.obj.iv[17];
	local[8]= argv[0]->c.obj.iv[18];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[30];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[8];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	argv[0]->c.obj.iv[18] = w;
	argv[0]->c.obj.iv[17] = makeint(2);
	w = local[3];
	local[0]= w;
BLK3182:
	ctx->vsp=local; return(local[0]);}

/*:draw-panel*/
static pointer M3187menu_panel_draw_panel(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO3189,env,argv,local);
	local[1]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	local[0]= w;
BLK3188:
	ctx->vsp=local; return(local[0]);}

/*:popup*/
static pointer M3190menu_panel_popup(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT3193;}
	local[0]= makeint(20);
ENT3193:
ENT3192:
	if (n>5) maerror();
	local[1]= argv[0];
	local[2]= fqv[31];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[32];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	argv[0]->c.obj.iv[25] = local[0];
	local[1]= argv[0];
	local[2]= fqv[10];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[33];
	local[3]= makeint(0);
	local[4]= makeint(0);
	local[5]= argv[0]->c.obj.iv[5];
	local[6]= argv[0]->c.obj.iv[6];
	local[7]= makeint(2);
	local[8]= argv[0]->c.obj.iv[22];
	local[9]= argv[0]->c.obj.iv[21];
	local[10]= argv[0]->c.obj.iv[4];
	local[11]= argv[0]->c.obj.iv[23];
	local[12]= fqv[34];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,12,local+1); /*send*/
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO3194,env,argv,local);
	local[2]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[0]= w;
BLK3191:
	ctx->vsp=local; return(local[0]);}

/*:buttonrelease*/
static pointer M3195menu_panel_buttonrelease(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[35],w);
	local[3]= loadglobal(fqv[36]);
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w==NIL) goto IF3197;
	local[3]= NIL;
	storeglobal(fqv[36],local[3]);
	goto IF3198;
IF3197:
	local[3]= NIL;
IF3198:
	local[3]= argv[0];
	local[4]= fqv[37];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3196:
	ctx->vsp=local; return(local[0]);}

/*:mapnotify*/
static pointer M3199menu_panel_mapnotify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[35],w);
	local[3]= NIL;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK3200:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3178(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[38];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3179(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[8];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3180(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	local[2]= env->c.clo.env1[0]->c.obj.iv[5];
	local[3]= makeint(4);
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[8];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3189(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[39];
	local[2]= fqv[22];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3194(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[39];
	local[2]= fqv[22];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___Xmenu(ctx,n,argv,env)
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
	local[0]= fqv[40];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= fqv[41];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF3201;
	local[0]= fqv[42];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[43],w);
	goto IF3202;
IF3201:
	local[0]= fqv[44];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF3202:
	local[0]= fqv[45];
	local[1]= fqv[46];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[47]); /*require*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3160menu_panel_create,fqv[5],fqv[48],fqv[49]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3167menu_panel_find_button,fqv[50],fqv[48],fqv[51]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3176menu_panel_newsize,fqv[30],fqv[48],fqv[52]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3181menu_panel_create_item,fqv[53],fqv[48],fqv[54]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3187menu_panel_draw_panel,fqv[55],fqv[48],fqv[56]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3190menu_panel_popup,fqv[57],fqv[48],fqv[58]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3195menu_panel_buttonrelease,fqv[59],fqv[48],fqv[60]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3199menu_panel_mapnotify,fqv[61],fqv[48],fqv[62]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<3; i++) ftab[i]=fcallx;
}
