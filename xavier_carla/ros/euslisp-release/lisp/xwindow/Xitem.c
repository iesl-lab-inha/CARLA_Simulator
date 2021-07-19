/* ./Xitem.c :  entry=Xitem */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "Xitem.h"
#pragma init (register_Xitem)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___Xitem();
extern pointer build_quote_vector();
static int register_Xitem()
  { add_module_initializer("___Xitem", ___Xitem);}

static pointer F2136clump();
static pointer F2137replace_key_arg();
static pointer F2138make_topleft_edge_polygon();

/*clump*/
static pointer F2136clump(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)MIN(ctx,2,local+1); /*min*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MAX(ctx,2,local+0); /*max*/
	local[0]= w;
BLK2140:
	ctx->vsp=local; return(local[0]);}

/*replace-key-arg*/
static pointer F2137replace_key_arg(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
WHL2142:
	if (argv[2]==NIL) goto WHX2143;
	local[1]= argv[0];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)EQ(ctx,2,local+1); /*eql*/
	if (w==NIL) goto IF2145;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	local[1]= argv[2];
	goto IF2146;
IF2145:
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[1];
	local[1]= w;
	w = local[0];
	ctx->vsp=local+2;
	local[0] = cons(ctx,local[1],w);
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[1];
	local[1]= w;
	w = local[0];
	ctx->vsp=local+2;
	local[0] = cons(ctx,local[1],w);
	local[1]= local[0];
IF2146:
	goto WHL2142;
WHX2143:
	local[1]= NIL;
BLK2144:
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST_STAR(ctx,3,local+1); /*list**/
	local[0]= w;
BLK2141:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M2149panel_item_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
RST2151:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-5);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[0], &argv[5], n-5, local+1, 1);
	if (n & (1<<0)) goto KEY2152;
	local[1] = makeint(100);
KEY2152:
	if (n & (1<<1)) goto KEY2153;
	local[2] = local[1];
KEY2153:
	if (n & (1<<2)) goto KEY2154;
	local[3] = local[2];
KEY2154:
	if (n & (1<<3)) goto KEY2155;
	local[4] = loadglobal(fqv[1]);
KEY2155:
	argv[0]->c.obj.iv[5] = local[2];
	argv[0]->c.obj.iv[6] = local[3];
	argv[0]->c.obj.iv[15] = local[4];
	argv[0]->c.obj.iv[16] = argv[2];
	argv[0]->c.obj.iv[14] = argv[4];
	if (argv[3]==NIL) goto IF2156;
	local[5]= argv[3];
	goto IF2157;
IF2156:
	local[5]= argv[0]->c.obj.iv[7];
IF2157:
	argv[0]->c.obj.iv[13] = local[5];
	local[5]= (pointer)get_sym_func(fqv[2]);
	local[6]= argv[0];
	local[7]= *(ovafptr(argv[1],fqv[3]));
	local[8]= fqv[4];
	local[9]= fqv[5];
	local[10]= argv[2];
	local[11]= fqv[6];
	local[12]= local[2];
	local[13]= fqv[7];
	local[14]= local[3];
	local[15]= fqv[8];
	local[16]= local[4];
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)APPLY(ctx,13,local+5); /*apply*/
	local[5]= argv[0];
	local[6]= fqv[5];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[2];
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,2,local+5,&ftab[0],fqv[9]); /*textdots*/
	argv[0]->c.obj.iv[17] = w;
	w = argv[0]->c.obj.iv[17];
	local[0]= w;
BLK2150:
	ctx->vsp=local; return(local[0]);}

/*:draw-label*/
static pointer M2158panel_item_draw_label(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[10];
	local[2]= fqv[11];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[12];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= argv[0]->c.obj.iv[17];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	w = argv[0]->c.obj.iv[16];
	local[0]= w;
BLK2159:
	ctx->vsp=local; return(local[0]);}

/*:notify*/
static pointer M2160panel_item_notify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST2162:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	if (argv[0]->c.obj.iv[13]==NIL) goto IF2163;
	if (argv[0]->c.obj.iv[14]==NIL) goto IF2163;
	local[1]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+2;
	w=(pointer)LISTP(ctx,1,local+1); /*listp*/
	if (w==NIL) goto IF2165;
	local[1]= (pointer)get_sym_func(fqv[13]);
	local[2]= argv[0]->c.obj.iv[13];
	w=argv[0]->c.obj.iv[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	local[5]= argv[0];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,6,local+1); /*apply*/
	local[1]= w;
	goto IF2166;
IF2165:
	local[1]= (pointer)get_sym_func(fqv[13]);
	local[2]= argv[0]->c.obj.iv[13];
	local[3]= argv[0]->c.obj.iv[14];
	local[4]= argv[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	local[1]= w;
IF2166:
	goto IF2164;
IF2163:
	local[1]= NIL;
IF2164:
	w = local[1];
	local[0]= w;
BLK2161:
	ctx->vsp=local; return(local[0]);}

/*:keypress*/
static pointer M2167panel_item_keypress(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = NIL;
	local[0]= w;
BLK2168:
	ctx->vsp=local; return(local[0]);}

/*:keyrelease*/
static pointer M2169panel_item_keyrelease(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = NIL;
	local[0]= w;
BLK2170:
	ctx->vsp=local; return(local[0]);}

/*:buttonpress*/
static pointer M2171panel_item_buttonpress(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = NIL;
	local[0]= w;
BLK2172:
	ctx->vsp=local; return(local[0]);}

/*:motionnotify*/
static pointer M2173panel_item_motionnotify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = NIL;
	local[0]= w;
BLK2174:
	ctx->vsp=local; return(local[0]);}

/*:enternotify*/
static pointer M2175panel_item_enternotify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= NIL;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2176:
	ctx->vsp=local; return(local[0]);}

/*:leavenotify*/
static pointer M2177panel_item_leavenotify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = NIL;
	local[0]= w;
BLK2178:
	ctx->vsp=local; return(local[0]);}

/*make-topleft-edge-polygon*/
static pointer F2138make_topleft_edge_polygon(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= loadglobal(fqv[15]);
	local[1]= makeint(2);
	local[2]= makeint(2);
	{ eusinteger_t i,j;
		j=intval(makeint(6)); i=intval(local[2]);
		local[2]=(makeint(i * j));}
	{ eusinteger_t i,j;
		j=intval(local[2]); i=intval(local[1]);
		local[1]=(makeint(i * j));}
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,2,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[16];
	local[3]= argv[0];
	local[4]= argv[1];
	local[5]= argv[2];
	local[6]= makeint(0);
	local[7]= argv[4];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,1,local+7); /*-*/
	local[7]= w;
	local[8]= argv[4];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,1,local+9); /*-*/
	local[9]= w;
	local[10]= argv[4];
	local[11]= argv[4];
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,3,local+9); /*+*/
	local[9]= w;
	local[10]= makeint(0);
	local[11]= makeint(0);
	local[12]= argv[3];
	local[13]= argv[4];
	local[14]= argv[4];
	ctx->vsp=local+15;
	w=(pointer)MINUS(ctx,3,local+12); /*-*/
	local[12]= w;
	local[13]= argv[4];
	ctx->vsp=local+14;
	w=(pointer)MINUS(ctx,1,local+13); /*-*/
	local[13]= w;
	local[14]= argv[4];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,12,local+3); /*list*/
	local[3]= w;
	local[4]= makeint(0);
	local[5]= fqv[17];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK2179:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M2180button_item_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
RST2182:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-5);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[18], &argv[5], n-5, local+1, 1);
	if (n & (1<<0)) goto KEY2183;
	local[1] = NIL;
KEY2183:
	if (n & (1<<1)) goto KEY2184;
	local[2] = NIL;
KEY2184:
	if (n & (1<<2)) goto KEY2185;
	local[3] = loadglobal(fqv[19]);
KEY2185:
	if (n & (1<<3)) goto KEY2186;
	local[4] = fqv[20];
KEY2186:
	if (n & (1<<4)) goto KEY2187;
	local[5] = loadglobal(fqv[21]);
KEY2187:
	if (n & (1<<5)) goto KEY2188;
	local[6] = loadglobal(fqv[22]);
KEY2188:
	if (n & (1<<6)) goto KEY2189;
	local[7] = makeint(0);
KEY2189:
	if (n & (1<<7)) goto KEY2190;
	local[11]= local[3];
	local[12]= loadglobal(fqv[23]);
	ctx->vsp=local+13;
	w=(pointer)DERIVEDP(ctx,2,local+11); /*derivedp*/
	if (w==NIL) goto IF2191;
	local[11]= fqv[24];
	goto IF2192;
IF2191:
	local[11]= fqv[25];
IF2192:
	local[8] = local[11];
KEY2190:
	if (n & (1<<8)) goto KEY2193;
	local[9] = NIL;
KEY2193:
	if (n & (1<<9)) goto KEY2194;
	local[10] = NIL;
KEY2194:
	local[11]= NIL;
	local[12]= NIL;
	local[13]= argv[2];
	local[14]= local[5];
	ctx->vsp=local+15;
	w=(*ftab[0])(ctx,2,local+13,&ftab[0],fqv[9]); /*textdots*/
	argv[0]->c.obj.iv[17] = w;
	if (local[1]==NIL) goto IF2195;
	local[13]= local[1];
	goto IF2196;
IF2195:
	local[13]= argv[0]->c.obj.iv[17];
	local[14]= makeint(2);
	ctx->vsp=local+15;
	w=(pointer)AREF(ctx,2,local+13); /*aref*/
	local[13]= w;
	local[14]= makeint(10);
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,2,local+13); /*+*/
	local[13]= w;
IF2196:
	local[11] = local[13];
	if (local[2]==NIL) goto IF2197;
	local[13]= local[2];
	goto IF2198;
IF2197:
	local[13]= argv[0]->c.obj.iv[17];
	local[14]= makeint(0);
	ctx->vsp=local+15;
	w=(pointer)AREF(ctx,2,local+13); /*aref*/
	local[13]= w;
	local[14]= argv[0]->c.obj.iv[17];
	local[15]= makeint(1);
	ctx->vsp=local+16;
	w=(pointer)AREF(ctx,2,local+14); /*aref*/
	local[14]= w;
	local[15]= makeint(6);
	ctx->vsp=local+16;
	w=(pointer)PLUS(ctx,3,local+13); /*+*/
	local[13]= w;
IF2198:
	local[12] = local[13];
	local[13]= (pointer)get_sym_func(fqv[2]);
	local[14]= argv[0];
	local[15]= *(ovafptr(argv[1],fqv[3]));
	local[16]= fqv[4];
	local[17]= argv[2];
	local[18]= argv[3];
	local[19]= argv[4];
	local[20]= fqv[6];
	local[21]= local[11];
	local[22]= fqv[7];
	local[23]= local[12];
	local[24]= fqv[26];
	local[25]= local[7];
	local[26]= fqv[27];
	local[27]= local[3];
	local[28]= fqv[28];
	local[29]= local[6];
	local[30]= fqv[29];
	local[31]= local[4];
	local[32]= local[0];
	ctx->vsp=local+33;
	w=(pointer)APPLY(ctx,20,local+13); /*apply*/
	local[13]= argv[0]->c.obj.iv[4];
	local[14]= makeflt(1.40000000e+00);
	local[15]= argv[0];
	local[16]= fqv[30];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(*ftab[1])(ctx,3,local+13,&ftab[1],fqv[31]); /*get-lighter-pixel*/
	argv[0]->c.obj.iv[23] = w;
	local[13]= argv[0]->c.obj.iv[4];
	local[14]= makeflt(6.00000000e-01);
	local[15]= argv[0];
	local[16]= fqv[30];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(*ftab[1])(ctx,3,local+13,&ftab[1],fqv[31]); /*get-lighter-pixel*/
	argv[0]->c.obj.iv[22] = w;
	local[13]= makeint(0);
	local[14]= makeint(0);
	local[15]= argv[0]->c.obj.iv[5];
	local[16]= argv[0]->c.obj.iv[6];
	local[17]= makeint(2);
	ctx->vsp=local+18;
	w=(pointer)F2138make_topleft_edge_polygon(ctx,5,local+13); /*make-topleft-edge-polygon*/
	argv[0]->c.obj.iv[24] = w;
	argv[0]->c.obj.iv[21] = local[8];
	argv[0]->c.obj.iv[20] = local[9];
	local[13]= argv[0]->c.obj.iv[3];
	local[14]= fqv[8];
	local[15]= local[5];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= argv[2];
	local[14]= local[13];
	w = argv[0];
	w->c.obj.iv[16] = local[14];
	local[13]= argv[0];
	local[14]= fqv[32];
	local[15]= local[8];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[11]= local[10];
	local[12]= local[11];
	w = argv[0];
	w->c.obj.iv[19] = local[12];
	local[11]= argv[0]->c.obj.iv[3];
	local[12]= fqv[10];
	local[13]= fqv[11];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	w = argv[0];
	local[0]= w;
BLK2181:
	ctx->vsp=local; return(local[0]);}

/*:submenu*/
static pointer M2199button_item_submenu(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2202;}
	local[0]= NIL;
ENT2202:
ENT2201:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF2203;
	argv[0]->c.obj.iv[19] = local[0];
	local[1]= argv[0]->c.obj.iv[19];
	goto IF2204;
IF2203:
	local[1]= NIL;
IF2204:
	w = argv[0]->c.obj.iv[19];
	local[0]= w;
BLK2200:
	ctx->vsp=local; return(local[0]);}

/*:active-color*/
static pointer M2205button_item_active_color(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2208;}
	local[0]= NIL;
ENT2208:
ENT2207:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF2209;
	argv[0]->c.obj.iv[20] = local[0];
	local[1]= argv[0]->c.obj.iv[20];
	goto IF2210;
IF2209:
	local[1]= NIL;
IF2210:
	w = argv[0]->c.obj.iv[20];
	local[0]= w;
BLK2206:
	ctx->vsp=local; return(local[0]);}

/*:resize*/
static pointer M2211button_item_resize(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[3]));
	local[2]= fqv[33];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,5,local+0); /*send-message*/
	local[0]= makeint(0);
	local[1]= makeint(0);
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)F2138make_topleft_edge_polygon(ctx,5,local+0); /*make-topleft-edge-polygon*/
	argv[0]->c.obj.iv[24] = w;
	local[0]= argv[0];
	local[1]= fqv[32];
	local[2]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2212:
	ctx->vsp=local; return(local[0]);}

/*:label*/
static pointer M2213button_item_label(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2217;}
	local[0]= NIL;
ENT2217:
	if (n>=4) { local[1]=(argv[3]); goto ENT2216;}
	local[1]= makeint(10);
ENT2216:
ENT2215:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF2218;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[15];
	ctx->vsp=local+6;
	w=(*ftab[0])(ctx,2,local+4,&ftab[0],fqv[9]); /*textdots*/
	argv[0]->c.obj.iv[17] = w;
	local[4]= local[1];
	local[5]= argv[0]->c.obj.iv[17];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= makeint(10);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MAX(ctx,2,local+4); /*max*/
	local[2] = w;
	local[4]= argv[0]->c.obj.iv[17];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[17];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= makeint(6);
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,3,local+4); /*+*/
	local[3] = w;
	argv[0]->c.obj.iv[16] = local[0];
	local[4]= argv[0];
	local[5]= fqv[33];
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[2]= w;
	goto IF2219;
IF2218:
	local[2]= NIL;
IF2219:
	w = argv[0]->c.obj.iv[16];
	local[0]= w;
BLK2214:
	ctx->vsp=local; return(local[0]);}

/*:draw-label*/
static pointer M2220button_item_draw_label(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2226;}
	local[0]= fqv[25];
ENT2226:
	if (n>=4) { local[1]=(argv[3]); goto ENT2225;}
	local[1]= argv[0]->c.obj.iv[4];
ENT2225:
	if (n>=5) { local[2]=(argv[4]); goto ENT2224;}
	local[2]= makeint(2);
ENT2224:
	if (n>=6) { local[3]=(argv[5]); goto ENT2223;}
	local[3]= NIL;
ENT2223:
ENT2222:
	if (n>6) maerror();
	local[4]= argv[0];
	local[5]= fqv[34];
	local[6]= makeint(0);
	local[7]= makeint(0);
	local[8]= argv[0]->c.obj.iv[5];
	local[9]= argv[0]->c.obj.iv[6];
	local[10]= local[2];
	local[11]= argv[0]->c.obj.iv[23];
	local[12]= argv[0]->c.obj.iv[22];
	local[13]= argv[0]->c.obj.iv[4];
	local[14]= argv[0]->c.obj.iv[24];
	local[15]= local[0];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,12,local+4); /*send*/
	if (local[3]!=NIL) goto IF2227;
	local[4]= local[0];
	local[5]= fqv[35];
	ctx->vsp=local+6;
	w=(*ftab[2])(ctx,2,local+4,&ftab[2],fqv[36]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	local[4]= local[3];
	goto IF2228;
IF2227:
	local[4]= NIL;
IF2228:
	if (local[3]!=NIL) goto IF2229;
	local[3] = makeint(0);
	local[4]= local[3];
	goto IF2230;
IF2229:
	local[4]= NIL;
IF2230:
	local[4]= argv[0];
	local[5]= fqv[37];
	local[6]= argv[0]->c.obj.iv[5];
	local[7]= makeint(2);
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[17];
	local[8]= makeint(2);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,2,local+7); /*aref*/
	local[7]= w;
	local[8]= makeint(2);
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,1,local+7); /*-*/
	local[7]= w;
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,3,local+6); /*+*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[6];
	local[8]= makeint(2);
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[17];
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[17];
	local[10]= makeint(0);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,2,local+9); /*aref*/
	local[9]= w;
	local[10]= argv[0]->c.obj.iv[17];
	local[11]= makeint(1);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,2,local+10); /*aref*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	local[10]= makeint(2);
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,1,local+9); /*-*/
	local[9]= w;
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,4,local+7); /*+*/
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[38];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[0]= w;
BLK2221:
	ctx->vsp=local; return(local[0]);}

/*:redraw*/
static pointer M2231button_item_redraw(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[32];
	local[2]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2232:
	ctx->vsp=local; return(local[0]);}

/*:keypress*/
static pointer M2233button_item_keypress(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= NIL;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2234:
	ctx->vsp=local; return(local[0]);}

/*:keyrelease*/
static pointer M2235button_item_keyrelease(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= NIL;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2236:
	ctx->vsp=local; return(local[0]);}

/*:buttonpress*/
static pointer M2237button_item_buttonpress(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= argv[0];
	local[4]= fqv[32];
	local[5]= fqv[39];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	argv[0]->c.obj.iv[18] = T;
	local[3]= NIL;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2238:
	ctx->vsp=local; return(local[0]);}

/*:buttonrelease*/
static pointer M2239button_item_buttonrelease(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= loadglobal(fqv[14]);
	ctx->vsp=local+4;
	w=(*ftab[3])(ctx,1,local+3,&ftab[3],fqv[40]); /*event-x*/
	local[3]= w;
	local[4]= loadglobal(fqv[14]);
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,1,local+4,&ftab[4],fqv[41]); /*event-y*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[32];
	local[7]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	if (argv[0]->c.obj.iv[18]!=NIL) goto OR2243;
	local[5]= argv[0]->c.obj.iv[7];
	local[6]= loadglobal(fqv[23]);
	ctx->vsp=local+7;
	w=(pointer)DERIVEDP(ctx,2,local+5); /*derivedp*/
	if (w!=NIL) goto OR2243;
	goto IF2241;
OR2243:
	local[5]= makeint(0);
	local[6]= local[3];
	local[7]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,3,local+5); /*<*/
	if (w==NIL) goto IF2241;
	local[5]= makeint(0);
	local[6]= local[4];
	local[7]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,3,local+5); /*<*/
	if (w==NIL) goto IF2241;
	argv[0]->c.obj.iv[18] = NIL;
	if (argv[0]->c.obj.iv[19]==NIL) goto IF2244;
	local[5]= argv[0]->c.obj.iv[19];
	local[6]= fqv[42];
	local[7]= loadglobal(fqv[14]);
	ctx->vsp=local+8;
	w=(*ftab[5])(ctx,1,local+7,&ftab[5],fqv[43]); /*event-x-root*/
	local[7]= w;
	local[8]= loadglobal(fqv[14]);
	ctx->vsp=local+9;
	w=(*ftab[6])(ctx,1,local+8,&ftab[6],fqv[44]); /*event-y-root*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto IF2245;
IF2244:
	local[5]= argv[0];
	local[6]= fqv[45];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
IF2245:
	goto IF2242;
IF2241:
	local[5]= NIL;
IF2242:
	w = local[5];
	if (argv[0]->c.obj.iv[7]==NIL) goto IF2246;
	local[3]= argv[0]->c.obj.iv[7];
	local[4]= fqv[46];
	local[5]= loadglobal(fqv[14]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF2247;
IF2246:
	local[3]= NIL;
IF2247:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2240:
	ctx->vsp=local; return(local[0]);}

/*:enternotify*/
static pointer M2248button_item_enternotify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	if (argv[0]->c.obj.iv[20]==NIL) goto IF2250;
	local[3]= argv[0];
	local[4]= fqv[32];
	local[5]= fqv[25];
	local[6]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF2251;
IF2250:
	local[3]= NIL;
IF2251:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2249:
	ctx->vsp=local; return(local[0]);}

/*:leavenotify*/
static pointer M2252button_item_leavenotify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	if (argv[0]->c.obj.iv[20]==NIL) goto IF2254;
	local[3]= argv[0];
	local[4]= fqv[32];
	local[5]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF2255;
IF2254:
	local[3]= NIL;
IF2255:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2253:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M2256menu_button_item_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
RST2258:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-5);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[47], &argv[5], n-5, local+1, 1);
	if (n & (1<<0)) goto KEY2259;
	local[1] = NIL;
KEY2259:
	if (n & (1<<1)) goto KEY2260;
	local[2] = NIL;
KEY2260:
	if (n & (1<<2)) goto KEY2261;
	local[3] = fqv[24];
KEY2261:
	local[4]= (pointer)get_sym_func(fqv[2]);
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[3]));
	local[7]= fqv[4];
	local[8]= argv[2];
	local[9]= argv[3];
	local[10]= argv[4];
	local[11]= fqv[48];
	local[12]= local[3];
	local[13]= fqv[29];
	local[14]= fqv[49];
	local[15]= local[0];
	ctx->vsp=local+16;
	w=(pointer)APPLY(ctx,12,local+4); /*apply*/
	argv[0]->c.obj.iv[30] = local[1];
	w = argv[0];
	local[0]= w;
BLK2257:
	ctx->vsp=local; return(local[0]);}

/*:label*/
static pointer M2262menu_button_item_label(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2265;}
	local[0]= NIL;
ENT2265:
ENT2264:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF2266;
	local[1]= argv[0]->c.obj.iv[5];
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[3]));
	local[4]= fqv[50];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,4,local+2); /*send-message*/
	local[2]= local[1];
	local[3]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+4;
	w=(*ftab[7])(ctx,2,local+2,&ftab[7],fqv[51]); /*/=*/
	if (w==NIL) goto IF2268;
	local[2]= argv[0]->c.obj.iv[7];
	local[3]= fqv[52];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	goto IF2269;
IF2268:
	local[2]= NIL;
IF2269:
	w = local[2];
	local[1]= w;
	goto IF2267;
IF2266:
	local[1]= NIL;
IF2267:
	w = argv[0]->c.obj.iv[16];
	local[0]= w;
BLK2263:
	ctx->vsp=local; return(local[0]);}

/*:popup-menu*/
static pointer M2270menu_button_item_popup_menu(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[32];
	local[2]= fqv[25];
	local[3]= argv[0]->c.obj.iv[4];
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[53];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[30];
	local[2]= fqv[42];
	local[3]= local[0];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	local[4]= local[0];
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[7];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[7];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[0]= w;
BLK2271:
	ctx->vsp=local; return(local[0]);}

/*:unmap-menu*/
static pointer M2272menu_button_item_unmap_menu(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[32];
	local[2]= fqv[24];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[30];
	local[1]= fqv[54];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK2273:
	ctx->vsp=local; return(local[0]);}

/*:buttonpress*/
static pointer M2274menu_button_item_buttonpress(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= argv[0];
	storeglobal(fqv[55],local[3]);
	local[3]= argv[0]->c.obj.iv[7];
	local[4]= fqv[56];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[0];
	local[4]= fqv[57];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2275:
	ctx->vsp=local; return(local[0]);}

/*:buttonrelease*/
static pointer M2276menu_button_item_buttonrelease(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= loadglobal(fqv[55]);
	if (argv[0]!=local[3]) goto IF2278;
	local[3]= NIL;
	storeglobal(fqv[55],local[3]);
	local[3]= argv[0];
	local[4]= fqv[58];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= argv[0];
	local[4]= fqv[45];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	goto IF2279;
IF2278:
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[3]));
	local[5]= fqv[46];
	local[6]= loadglobal(fqv[14]);
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,4,local+3); /*send-message*/
	local[3]= w;
IF2279:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2277:
	ctx->vsp=local; return(local[0]);}

/*:enternotify*/
static pointer M2280menu_button_item_enternotify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= loadglobal(fqv[14]);
	local[4]= T;
	ctx->vsp=local+5;
	w=(*ftab[8])(ctx,2,local+3,&ftab[8],fqv[59]); /*event-pressed*/
	if (w==NIL) goto IF2282;
	local[3]= argv[0]->c.obj.iv[7];
	local[4]= fqv[56];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF2283;
IF2282:
	local[3]= NIL;
IF2283:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2281:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M2284text_item_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
RST2286:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-5);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[60], &argv[5], n-5, local+1, 1);
	if (n & (1<<0)) goto KEY2287;
	local[1] = loadglobal(fqv[1]);
KEY2287:
	if (n & (1<<1)) goto KEY2288;
	local[2] = makeint(20);
KEY2288:
	if (n & (1<<2)) goto KEY2289;
	local[3] = NIL;
KEY2289:
	if (n & (1<<3)) goto KEY2290;
	local[4] = makeint(0);
KEY2290:
	local[5]= argv[2];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,2,local+5,&ftab[0],fqv[9]); /*textdots*/
	argv[0]->c.obj.iv[17] = w;
	local[5]= fqv[61];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,2,local+5,&ftab[0],fqv[9]); /*textdots*/
	local[5]= w;
	local[6]= local[5];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= local[5];
	local[8]= makeint(1);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,2,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	local[7]= local[5];
	local[8]= makeint(2);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,2,local+7); /*aref*/
	local[7]= w;
	local[8]= local[2];
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	local[9]= (pointer)get_sym_func(fqv[2]);
	local[10]= argv[0];
	local[11]= *(ovafptr(argv[1],fqv[3]));
	local[12]= fqv[4];
	local[13]= argv[2];
	local[14]= argv[3];
	local[15]= argv[4];
	local[16]= fqv[6];
	local[17]= argv[0]->c.obj.iv[17];
	local[18]= makeint(2);
	ctx->vsp=local+19;
	w=(pointer)AREF(ctx,2,local+17); /*aref*/
	local[17]= w;
	local[18]= makeint(8);
	local[19]= local[8];
	local[20]= makeint(4);
	ctx->vsp=local+21;
	w=(pointer)PLUS(ctx,4,local+17); /*+*/
	local[17]= w;
	local[18]= fqv[7];
	local[19]= local[6];
	local[20]= makeint(6);
	ctx->vsp=local+21;
	w=(pointer)PLUS(ctx,2,local+19); /*+*/
	local[19]= w;
	local[20]= local[0];
	ctx->vsp=local+21;
	w=(pointer)APPLY(ctx,12,local+9); /*apply*/
	local[9]= fqv[27];
	local[10]= argv[0];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)F2137replace_key_arg(ctx,3,local+9); /*replace-key-arg*/
	local[0] = w;
	local[9]= fqv[26];
	local[10]= makeint(1);
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)F2137replace_key_arg(ctx,3,local+9); /*replace-key-arg*/
	local[0] = w;
	local[9]= loadglobal(fqv[62]);
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,1,local+9); /*instantiate*/
	local[9]= w;
	local[10]= (pointer)get_sym_func(fqv[13]);
	local[11]= local[9];
	local[12]= fqv[4];
	local[13]= fqv[27];
	local[14]= argv[0];
	local[15]= fqv[63];
	local[16]= T;
	local[17]= fqv[8];
	local[18]= local[1];
	local[19]= fqv[64];
	local[20]= local[2];
	local[21]= fqv[65];
	local[22]= makeint(1);
	local[23]= fqv[29];
	local[24]= fqv[66];
	local[25]= fqv[67];
	local[26]= argv[3];
	local[27]= fqv[68];
	local[28]= argv[4];
	local[29]= local[0];
	ctx->vsp=local+30;
	w=(pointer)APPLY(ctx,20,local+10); /*apply*/
	w = local[9];
	argv[0]->c.obj.iv[19] = w;
	local[9]= argv[0]->c.obj.iv[19];
	local[10]= fqv[69];
	local[11]= argv[0]->c.obj.iv[17];
	local[12]= makeint(2);
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,2,local+11); /*aref*/
	local[11]= w;
	local[12]= makeint(4);
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[11]= w;
	local[12]= makeint(0);
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,4,local+9); /*send*/
	local[9]= argv[0]->c.obj.iv[19];
	local[10]= fqv[70];
	local[11]= fqv[71];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	if (local[3]==NIL) goto IF2292;
	local[9]= argv[0];
	local[10]= fqv[72];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= w;
	goto IF2293;
IF2292:
	local[9]= NIL;
IF2293:
	local[9]= argv[0];
	local[10]= fqv[73];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	w = argv[0];
	local[0]= w;
BLK2285:
	ctx->vsp=local; return(local[0]);}

/*:redraw*/
static pointer M2294text_item_redraw(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[32];
	local[2]= makeint(1);
	local[3]= makeint(4);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[19];
	local[1]= fqv[73];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK2295:
	ctx->vsp=local; return(local[0]);}

/*:getstring*/
static pointer M2296text_item_getstring(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[19];
	local[1]= fqv[74];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2297:
	ctx->vsp=local; return(local[0]);}

/*:value*/
static pointer M2298text_item_value(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2302;}
	local[0]= NIL;
ENT2302:
	if (n>=4) { local[1]=(argv[3]); goto ENT2301;}
	local[1]= NIL;
ENT2301:
ENT2300:
	if (n>4) maerror();
	local[2]= NIL;
	local[3]= NIL;
	w = local[0];
	if (!isstring(w)) goto IF2303;
	local[4]= argv[0]->c.obj.iv[19];
	local[5]= fqv[75];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= argv[0]->c.obj.iv[19];
	local[5]= fqv[76];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF2304;
IF2303:
	local[4]= NIL;
IF2304:
	local[4]= argv[0]->c.obj.iv[19];
	local[5]= fqv[74];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[3] = w;
	if (local[1]==NIL) goto IF2305;
	local[4]= argv[0];
	local[5]= fqv[45];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF2306;
IF2305:
	local[4]= NIL;
IF2306:
	w = local[3];
	local[0]= w;
BLK2299:
	ctx->vsp=local; return(local[0]);}

/*:leavenotify*/
static pointer M2307text_item_leavenotify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= argv[0]->c.obj.iv[19];
	local[4]= fqv[77];
	local[5]= loadglobal(fqv[14]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2308:
	ctx->vsp=local; return(local[0]);}

/*:enternotify*/
static pointer M2309text_item_enternotify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= argv[0]->c.obj.iv[19];
	local[4]= fqv[78];
	local[5]= loadglobal(fqv[14]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2310:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M2311slider_item_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
RST2313:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-5);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[79], &argv[5], n-5, local+1, 1);
	if (n & (1<<0)) goto KEY2314;
	local[1] = makeflt(0.00000000e+00);
KEY2314:
	if (n & (1<<1)) goto KEY2315;
	local[2] = makeflt(1.00000000e+00);
KEY2315:
	if (n & (1<<2)) goto KEY2316;
	local[3] = NIL;
KEY2316:
	if (n & (1<<3)) goto KEY2317;
	local[4] = NIL;
KEY2317:
	if (n & (1<<4)) goto KEY2318;
	local[5] = NIL;
KEY2318:
	if (n & (1<<5)) goto KEY2319;
	local[6] = fqv[80];
KEY2319:
	if (n & (1<<6)) goto KEY2320;
	local[7] = loadglobal(fqv[1]);
KEY2320:
	if (n & (1<<7)) goto KEY2321;
	local[8] = makeint(100);
KEY2321:
	if (n & (1<<8)) goto KEY2322;
	local[9] = makeint(0);
KEY2322:
	if (n & (1<<9)) goto KEY2323;
	local[10] = local[1];
KEY2323:
	if (n & (1<<10)) goto KEY2324;
	local[11] = T;
KEY2324:
	argv[0]->c.obj.iv[21] = local[10];
	argv[0]->c.obj.iv[24] = local[6];
	argv[0]->c.obj.iv[32] = NIL;
	local[12]= argv[0];
	local[13]= fqv[81];
	local[14]= local[1];
	local[15]= local[4];
	local[16]= local[2];
	local[17]= local[5];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,6,local+12); /*send*/
	local[12]= argv[2];
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(*ftab[0])(ctx,2,local+12,&ftab[0],fqv[9]); /*textdots*/
	argv[0]->c.obj.iv[17] = w;
	local[12]= NIL;
	local[13]= local[6];
	local[14]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+15;
	w=(pointer)XFORMAT(ctx,3,local+12); /*format*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(*ftab[0])(ctx,1,local+12,&ftab[0],fqv[9]); /*textdots*/
	argv[0]->c.obj.iv[29] = w;
	local[12]= fqv[82];
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(*ftab[0])(ctx,2,local+12,&ftab[0],fqv[9]); /*textdots*/
	argv[0]->c.obj.iv[33] = w;
	local[12]= argv[0]->c.obj.iv[33];
	local[13]= makeint(2);
	ctx->vsp=local+14;
	w=(pointer)AREF(ctx,2,local+12); /*aref*/
	argv[0]->c.obj.iv[33] = w;
	local[12]= (pointer)get_sym_func(fqv[2]);
	local[13]= argv[0];
	local[14]= *(ovafptr(argv[1],fqv[3]));
	local[15]= fqv[4];
	local[16]= argv[2];
	local[17]= argv[3];
	local[18]= argv[4];
	local[19]= fqv[26];
	local[20]= local[9];
	local[21]= fqv[6];
	local[22]= argv[0]->c.obj.iv[17];
	local[23]= makeint(2);
	ctx->vsp=local+24;
	w=(pointer)AREF(ctx,2,local+22); /*aref*/
	local[22]= w;
	local[23]= argv[0]->c.obj.iv[33];
	local[24]= argv[0]->c.obj.iv[22];
	ctx->vsp=local+25;
	w=(pointer)LENGTH(ctx,1,local+24); /*length*/
	local[24]= w;
	local[25]= argv[0]->c.obj.iv[23];
	ctx->vsp=local+26;
	w=(pointer)LENGTH(ctx,1,local+25); /*length*/
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[24]= (pointer)((eusinteger_t)local[24] + (eusinteger_t)w);
	ctx->vsp=local+25;
	w=(pointer)TIMES(ctx,2,local+23); /***/
	local[23]= w;
	local[24]= argv[0]->c.obj.iv[29];
	local[25]= makeint(2);
	ctx->vsp=local+26;
	w=(pointer)AREF(ctx,2,local+24); /*aref*/
	local[24]= w;
	local[25]= local[8];
	local[26]= makeint(60);
	ctx->vsp=local+27;
	w=(pointer)PLUS(ctx,5,local+22); /*+*/
	local[22]= w;
	local[23]= fqv[7];
	local[24]= makeint(10);
	local[25]= argv[0]->c.obj.iv[17];
	local[26]= makeint(0);
	ctx->vsp=local+27;
	w=(pointer)AREF(ctx,2,local+25); /*aref*/
	local[25]= w;
	local[26]= argv[0]->c.obj.iv[17];
	local[27]= makeint(1);
	ctx->vsp=local+28;
	w=(pointer)AREF(ctx,2,local+26); /*aref*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)PLUS(ctx,3,local+24); /*+*/
	local[24]= w;
	local[25]= fqv[8];
	local[26]= local[7];
	local[27]= local[0];
	ctx->vsp=local+28;
	w=(pointer)APPLY(ctx,16,local+12); /*apply*/
	local[12]= argv[0]->c.obj.iv[17];
	local[13]= makeint(2);
	ctx->vsp=local+14;
	w=(pointer)AREF(ctx,2,local+12); /*aref*/
	local[12]= w;
	local[13]= argv[0]->c.obj.iv[29];
	local[14]= makeint(2);
	ctx->vsp=local+15;
	w=(pointer)AREF(ctx,2,local+13); /*aref*/
	local[13]= w;
	local[14]= argv[0]->c.obj.iv[33];
	local[15]= argv[0]->c.obj.iv[22];
	ctx->vsp=local+16;
	w=(pointer)LENGTH(ctx,1,local+15); /*length*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)TIMES(ctx,2,local+14); /***/
	local[14]= w;
	local[15]= makeint(17);
	ctx->vsp=local+16;
	w=(pointer)PLUS(ctx,4,local+12); /*+*/
	argv[0]->c.obj.iv[25] = w;
	local[12]= makeint(3);
	local[13]= argv[0]->c.obj.iv[17];
	local[14]= makeint(0);
	ctx->vsp=local+15;
	w=(pointer)AREF(ctx,2,local+13); /*aref*/
	local[13]= w;
	local[14]= argv[0]->c.obj.iv[17];
	local[15]= makeint(1);
	ctx->vsp=local+16;
	w=(pointer)AREF(ctx,2,local+14); /*aref*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,2,local+13); /*+*/
	local[13]= w;
	local[14]= makeint(2);
	ctx->vsp=local+15;
	w=(pointer)QUOTIENT(ctx,2,local+13); /*/*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,2,local+12); /*+*/
	argv[0]->c.obj.iv[26] = w;
	argv[0]->c.obj.iv[27] = local[8];
	argv[0]->c.obj.iv[28] = makeint(3);
	local[12]= argv[0];
	local[13]= fqv[83];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	argv[0]->c.obj.iv[31] = w;
	local[12]= makeint(5);
	local[13]= argv[0]->c.obj.iv[17];
	local[14]= makeint(0);
	ctx->vsp=local+15;
	w=(pointer)AREF(ctx,2,local+13); /*aref*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,2,local+12); /*+*/
	argv[0]->c.obj.iv[30] = w;
	local[12]= argv[0];
	local[13]= fqv[84];
	local[14]= local[11];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[12]= argv[0];
	local[13]= fqv[73];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	w = argv[0];
	local[0]= w;
BLK2312:
	ctx->vsp=local; return(local[0]);}

/*:new-range*/
static pointer M2325slider_item_new_range(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	argv[0]->c.obj.iv[19] = argv[2];
	argv[0]->c.obj.iv[20] = argv[4];
	w = argv[3];
	if (isstring(w)) goto IF2327;
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[24];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	argv[3] = w;
	local[0]= argv[3];
	goto IF2328;
IF2327:
	local[0]= NIL;
IF2328:
	argv[0]->c.obj.iv[22] = argv[3];
	w = argv[5];
	if (isstring(w)) goto IF2329;
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[24];
	local[2]= argv[4];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	argv[5] = w;
	local[0]= argv[5];
	goto IF2330;
IF2329:
	local[0]= NIL;
IF2330:
	argv[0]->c.obj.iv[23] = argv[5];
	w = argv[0]->c.obj.iv[23];
	local[0]= w;
BLK2326:
	ctx->vsp=local; return(local[0]);}

/*:continuous-notify*/
static pointer M2331slider_item_continuous_notify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[34];
	argv[0]->c.obj.iv[34] = argv[2];
	w = local[0];
	local[0]= w;
BLK2332:
	ctx->vsp=local; return(local[0]);}

/*:redraw*/
static pointer M2334slider_item_redraw(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[85];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[86];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[12];
	local[2]= makeint(3);
	local[3]= argv[0]->c.obj.iv[30];
	local[4]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[12];
	local[2]= makeint(13);
	local[3]= argv[0]->c.obj.iv[17];
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[29];
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,3,local+2); /*+*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[30];
	local[4]= argv[0]->c.obj.iv[22];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[12];
	local[2]= makeint(23);
	local[3]= argv[0]->c.obj.iv[17];
	local[4]= makeint(2);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[29];
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[33];
	local[6]= argv[0]->c.obj.iv[22];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[27];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,5,local+2); /*+*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[30];
	local[4]= argv[0]->c.obj.iv[23];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[87];
	local[2]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK2335:
	ctx->vsp=local; return(local[0]);}

/*:display-value*/
static pointer M2336slider_item_display_value(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2339;}
	local[0]= argv[0]->c.obj.iv[21];
ENT2339:
ENT2338:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[19];
	local[2]= argv[0]->c.obj.iv[20];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)MIN(ctx,2,local+2); /*min*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAX(ctx,2,local+1); /*max*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)EUSFLOAT(ctx,1,local+1); /*float*/
	local[0] = w;
	w = argv[0]->c.obj.iv[20];
	if (!isint(w)) goto IF2340;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)ROUND(ctx,1,local+1); /*round*/
	local[0] = w;
	local[1]= local[0];
	goto IF2341;
IF2340:
	local[1]= NIL;
IF2341:
	local[1]= argv[0];
	local[2]= fqv[12];
	local[3]= makeint(7);
	local[4]= argv[0]->c.obj.iv[17];
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[30];
	local[5]= NIL;
	local[6]= argv[0]->c.obj.iv[24];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,3,local+5); /*format*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[0]= w;
BLK2337:
	ctx->vsp=local; return(local[0]);}

/*:value*/
static pointer M2342slider_item_value(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2346;}
	local[0]= NIL;
ENT2346:
	if (n>=4) { local[1]=(argv[3]); goto ENT2345;}
	local[1]= NIL;
ENT2345:
ENT2344:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF2347;
	local[2]= argv[0];
	local[3]= fqv[87];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[86];
	local[4]= argv[0]->c.obj.iv[31];
	local[5]= argv[0];
	local[6]= fqv[83];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[83];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	argv[0]->c.obj.iv[31] = w;
	argv[0]->c.obj.iv[21] = local[0];
	local[2]= argv[0]->c.obj.iv[21];
	goto IF2348;
IF2347:
	local[2]= NIL;
IF2348:
	if (local[1]==NIL) goto IF2349;
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[3]));
	local[4]= fqv[45];
	local[5]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,4,local+2); /*send-message*/
	local[2]= w;
	goto IF2350;
IF2349:
	local[2]= NIL;
IF2350:
	w = argv[0]->c.obj.iv[21];
	local[0]= w;
BLK2343:
	ctx->vsp=local; return(local[0]);}

/*:nob-x*/
static pointer M2351slider_item_nob_x(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2354;}
	local[0]= argv[0]->c.obj.iv[21];
ENT2354:
ENT2353:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[25];
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[19];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,1,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[27];
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[20];
	local[4]= argv[0]->c.obj.iv[19];
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,1,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[0]= w;
BLK2352:
	ctx->vsp=local; return(local[0]);}

/*:inside-nob-p*/
static pointer M2355slider_item_inside_nob_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[31];
	local[1]= argv[2];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[31];
	local[3]= makeint(7);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LSEQP(ctx,3,local+0); /*<=*/
	local[0]= w;
	if (w==NIL) goto AND2357;
	local[0]= argv[0]->c.obj.iv[26];
	local[1]= makeint(5);
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[26];
	local[3]= makeint(5);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LSEQP(ctx,3,local+0); /*<=*/
	local[0]= w;
AND2357:
	w = local[0];
	local[0]= w;
BLK2356:
	ctx->vsp=local; return(local[0]);}

/*:draw-bar-rectangle*/
static pointer M2358slider_item_draw_bar_rectangle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[88];
	local[2]= argv[0]->c.obj.iv[25];
	local[3]= argv[0]->c.obj.iv[26];
	local[4]= makeint(5);
	local[5]= argv[0]->c.obj.iv[27];
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[28];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,6,local+0); /*send*/
	local[0]= w;
BLK2359:
	ctx->vsp=local; return(local[0]);}

/*:draw-nob-rectangle*/
static pointer M2360slider_item_draw_nob_rectangle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2364;}
	local[0]= argv[0]->c.obj.iv[31];
ENT2364:
	if (n>=4) { local[1]=(argv[3]); goto ENT2363;}
	local[1]= argv[0]->c.obj.iv[31];
ENT2363:
ENT2362:
	if (n>4) maerror();
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= fqv[28];
	local[4]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[89];
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[26];
	local[6]= makeint(5);
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	local[6]= makeint(7);
	local[7]= makeint(13);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= fqv[28];
	local[4]= loadglobal(fqv[90]);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[85];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[89];
	local[4]= local[1];
	local[5]= argv[0]->c.obj.iv[26];
	local[6]= makeint(5);
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	local[6]= makeint(7);
	local[7]= makeint(13);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[0]= w;
BLK2361:
	ctx->vsp=local; return(local[0]);}

/*:buttonpress*/
static pointer M2365slider_item_buttonpress(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= loadglobal(fqv[14]);
	ctx->vsp=local+4;
	w=(*ftab[9])(ctx,1,local+3,&ftab[9],fqv[91]); /*event-pos*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[92];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	if (w==NIL) goto IF2367;
	local[4]= loadglobal(fqv[14]);
	ctx->vsp=local+5;
	w=(*ftab[9])(ctx,1,local+4,&ftab[9],fqv[91]); /*event-pos*/
	argv[0]->c.obj.iv[32] = w;
	local[4]= argv[0]->c.obj.iv[32];
	goto IF2368;
IF2367:
	local[4]= NIL;
IF2368:
	w = local[4];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2366:
	ctx->vsp=local; return(local[0]);}

/*:compute-value*/
static pointer M2369slider_item_compute_value(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= loadglobal(fqv[14]);
	ctx->vsp=local+4;
	w=(*ftab[9])(ctx,1,local+3,&ftab[9],fqv[91]); /*event-pos*/
	local[3]= w;
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[25];
	local[5]= makeint(3);
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,3,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)EUSFLOAT(ctx,1,local+3); /*float*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[19];
	local[5]= argv[0]->c.obj.iv[19];
	local[6]= local[3];
	local[7]= argv[0]->c.obj.iv[27];
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[20];
	local[8]= argv[0]->c.obj.iv[19];
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,1,local+8); /*-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+7;
	w=(pointer)F2136clump(ctx,3,local+4); /*clump*/
	local[4]= w;
	w = local[4];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2370:
	ctx->vsp=local; return(local[0]);}

/*:motionnotify*/
static pointer M2371slider_item_motionnotify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	if (argv[0]->c.obj.iv[32]==NIL) goto IF2373;
	local[3]= argv[0];
	local[4]= fqv[72];
	local[5]= argv[0];
	local[6]= fqv[93];
	local[7]= loadglobal(fqv[14]);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[34];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF2374;
IF2373:
	local[3]= NIL;
IF2374:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2372:
	ctx->vsp=local; return(local[0]);}

/*:buttonrelease*/
static pointer M2375slider_item_buttonrelease(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	if (argv[0]->c.obj.iv[32]==NIL) goto IF2377;
	argv[0]->c.obj.iv[32] = NIL;
	local[3]= argv[0];
	local[4]= fqv[72];
	local[5]= argv[0];
	local[6]= fqv[93];
	local[7]= loadglobal(fqv[14]);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	local[6]= T;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF2378;
IF2377:
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[3]));
	local[5]= fqv[46];
	local[6]= loadglobal(fqv[14]);
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,4,local+3); /*send-message*/
	local[3]= w;
IF2378:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2376:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M2379choice_item_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
RST2381:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-5);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[94], &argv[5], n-5, local+1, 1);
	if (n & (1<<0)) goto KEY2382;
	local[1] = loadglobal(fqv[19]);
KEY2382:
	if (n & (1<<1)) goto KEY2383;
	local[2] = fqv[95];
KEY2383:
	if (n & (1<<2)) goto KEY2384;
	local[3] = NIL;
KEY2384:
	if (n & (1<<3)) goto KEY2385;
	local[4] = makeint(0);
KEY2385:
	if (n & (1<<4)) goto KEY2386;
	local[5] = makeint(13);
KEY2386:
	if (n & (1<<5)) goto KEY2387;
	local[6] = makeint(0);
KEY2387:
	if (n & (1<<6)) goto KEY2388;
	local[7] = NIL;
KEY2388:
	if (n & (1<<7)) goto KEY2389;
	local[8] = NIL;
KEY2389:
	if (n & (1<<8)) goto KEY2390;
	local[9] = NIL;
KEY2390:
	if (n & (1<<9)) goto KEY2391;
	local[10] = NIL;
KEY2391:
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= (pointer)get_sym_func(fqv[96]);
	local[15]= local[2];
	ctx->vsp=local+16;
	w=(pointer)MAPCAR(ctx,2,local+14); /*mapcar*/
	argv[0]->c.obj.iv[19] = w;
	argv[0]->c.obj.iv[20] = local[4];
	local[14]= local[5];
	local[15]= local[14];
	w = argv[0];
	w->c.obj.iv[23] = local[15];
	if (local[3]!=NIL) goto IF2392;
	local[14]= local[1];
	local[15]= fqv[97];
	local[16]= fqv[8];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[3] = w;
	local[14]= local[3];
	goto IF2393;
IF2392:
	local[14]= NIL;
IF2393:
	local[14]= argv[2];
	local[15]= local[3];
	ctx->vsp=local+16;
	w=(*ftab[0])(ctx,2,local+14,&ftab[0],fqv[9]); /*textdots*/
	argv[0]->c.obj.iv[17] = w;
	local[14]= NIL;
	local[15]= local[2];
WHL2395:
	if (local[15]==NIL) goto WHX2396;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15] = (w)->c.cons.cdr;
	w = local[16];
	local[14] = w;
	local[16]= local[14];
	local[17]= local[3];
	ctx->vsp=local+18;
	w=(*ftab[0])(ctx,2,local+16,&ftab[0],fqv[9]); /*textdots*/
	local[16]= w;
	local[17]= makeint(2);
	ctx->vsp=local+18;
	w=(pointer)AREF(ctx,2,local+16); /*aref*/
	local[16]= w;
	w = local[13];
	ctx->vsp=local+17;
	local[13] = cons(ctx,local[16],w);
	goto WHL2395;
WHX2396:
	local[16]= NIL;
BLK2397:
	w = NIL;
	local[14]= local[13];
	ctx->vsp=local+15;
	w=(pointer)NREVERSE(ctx,1,local+14); /*nreverse*/
	local[14]= (pointer)get_sym_func(fqv[2]);
	local[15]= argv[0];
	local[16]= *(ovafptr(argv[1],fqv[3]));
	local[17]= fqv[4];
	local[18]= argv[2];
	local[19]= argv[3];
	local[20]= argv[4];
	local[21]= fqv[27];
	local[22]= local[1];
	local[23]= fqv[26];
	local[24]= local[6];
	local[25]= fqv[6];
	local[26]= argv[0]->c.obj.iv[17];
	local[27]= makeint(2);
	ctx->vsp=local+28;
	w=(pointer)AREF(ctx,2,local+26); /*aref*/
	local[26]= w;
	local[27]= (pointer)get_sym_func(fqv[98]);
	local[28]= local[13];
	ctx->vsp=local+29;
	w=(pointer)APPLY(ctx,2,local+27); /*apply*/
	local[27]= w;
	local[28]= local[2];
	ctx->vsp=local+29;
	w=(pointer)LENGTH(ctx,1,local+28); /*length*/
	local[28]= w;
	{ eusinteger_t i,j;
		j=intval(makeint(5)); i=intval(local[28]);
		local[28]=(makeint(i * j));}
	local[29]= makeint(20);
	ctx->vsp=local+30;
	w=(pointer)PLUS(ctx,4,local+26); /*+*/
	local[26]= w;
	local[27]= fqv[7];
	local[28]= makeint(10);
	local[29]= local[5];
	local[30]= argv[0]->c.obj.iv[17];
	local[31]= makeint(0);
	ctx->vsp=local+32;
	w=(pointer)AREF(ctx,2,local+30); /*aref*/
	local[30]= w;
	local[31]= argv[0]->c.obj.iv[17];
	local[32]= makeint(1);
	ctx->vsp=local+33;
	w=(pointer)AREF(ctx,2,local+31); /*aref*/
	local[31]= w;
	ctx->vsp=local+32;
	w=(pointer)PLUS(ctx,4,local+28); /*+*/
	local[28]= w;
	local[29]= fqv[8];
	local[30]= local[3];
	local[31]= fqv[29];
	local[32]= local[7];
	local[33]= fqv[99];
	ctx->vsp=local+34;
	w=(*ftab[10])(ctx,2,local+32,&ftab[10],fqv[100]); /*union*/
	local[32]= w;
	local[33]= local[0];
	ctx->vsp=local+34;
	w=(pointer)APPLY(ctx,20,local+14); /*apply*/
	local[14]= argv[0]->c.obj.iv[17];
	local[15]= makeint(0);
	ctx->vsp=local+16;
	w=(pointer)AREF(ctx,2,local+14); /*aref*/
	local[14]= w;
	local[15]= argv[0]->c.obj.iv[17];
	local[16]= makeint(1);
	ctx->vsp=local+17;
	w=(pointer)AREF(ctx,2,local+15); /*aref*/
	local[15]= w;
	local[16]= local[5];
	local[17]= makeint(2);
	ctx->vsp=local+18;
	w=(pointer)QUOTIENT(ctx,2,local+16); /*/*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)PLUS(ctx,3,local+14); /*+*/
	local[12] = w;
	local[14]= makeint(5);
	local[15]= argv[0]->c.obj.iv[17];
	local[16]= makeint(2);
	ctx->vsp=local+17;
	w=(pointer)AREF(ctx,2,local+15); /*aref*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)PLUS(ctx,2,local+14); /*+*/
	local[14]= w;
	local[15]= NIL;
	local[16]= NIL;
	local[17]= argv[0]->c.obj.iv[19];
WHL2400:
	if (local[17]==NIL) goto WHX2401;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17] = (w)->c.cons.cdr;
	w = local[18];
	local[16] = w;
	local[18]= local[16];
	local[19]= local[14];
	local[20]= argv[0]->c.obj.iv[17];
	local[21]= makeint(0);
	ctx->vsp=local+22;
	w=(pointer)AREF(ctx,2,local+20); /*aref*/
	local[20]= w;
	local[21]= makeint(3);
	ctx->vsp=local+22;
	w=(pointer)PLUS(ctx,2,local+20); /*+*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)LIST(ctx,2,local+19); /*list*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)NCONC(ctx,2,local+18); /*nconc*/
	local[18]= makeint(4);
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13] = (w)->c.cons.cdr;
	w = local[19];
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)PLUS(ctx,2,local+18); /*+*/
	local[15] = w;
	local[18]= local[16];
	local[19]= local[15];
	local[20]= makeint(2);
	ctx->vsp=local+21;
	w=(pointer)QUOTIENT(ctx,2,local+19); /*/*/
	local[19]= w;
	local[20]= local[14];
	local[21]= local[5];
	local[22]= makeint(2);
	ctx->vsp=local+23;
	w=(pointer)QUOTIENT(ctx,2,local+21); /*/*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)MINUS(ctx,1,local+21); /*-*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)PLUS(ctx,3,local+19); /*+*/
	local[19]= w;
	local[20]= local[12];
	ctx->vsp=local+21;
	w=(pointer)MKINTVECTOR(ctx,2,local+19); /*integer-vector*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)LIST(ctx,1,local+19); /*list*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)NCONC(ctx,2,local+18); /*nconc*/
	local[18]= local[14];
	local[19]= local[15];
	ctx->vsp=local+20;
	w=(pointer)PLUS(ctx,2,local+18); /*+*/
	local[14] = w;
	goto WHL2400;
WHX2401:
	local[18]= NIL;
BLK2402:
	w = NIL;
	local[14]= argv[0];
	local[15]= fqv[73];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,2,local+14); /*send*/
	local[14]= argv[0];
	local[15]= fqv[101];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,2,local+14); /*send*/
	w = argv[0];
	local[0]= w;
BLK2380:
	ctx->vsp=local; return(local[0]);}

/*:draw-label*/
static pointer M2405choice_item_draw_label(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2408;}
	local[0]= argv[0];
	local[1]= fqv[5];
	ctx->vsp=local+2;
	w=(pointer)GETPROP(ctx,2,local+0); /*get*/
	local[0]= w;
ENT2408:
ENT2407:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[37];
	local[3]= makeint(3);
	local[4]= argv[0];
	local[5]= fqv[7];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[0]= w;
BLK2406:
	ctx->vsp=local; return(local[0]);}

/*:redraw*/
static pointer M2409choice_item_redraw(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[32];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[19];
WHL2412:
	if (local[1]==NIL) goto WHX2413;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0];
	local[3]= fqv[37];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[102];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[11])(ctx,1,local+4,&ftab[11],fqv[103]); /*fourth*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[23];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	goto WHL2412;
WHX2413:
	local[2]= NIL;
BLK2414:
	w = NIL;
	local[0]= argv[0];
	local[1]= fqv[101];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK2410:
	ctx->vsp=local; return(local[0]);}

/*:value*/
static pointer M2416choice_item_value(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2420;}
	local[0]= NIL;
ENT2420:
	if (n>=4) { local[1]=(argv[3]); goto ENT2419;}
	local[1]= NIL;
ENT2419:
ENT2418:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF2421;
	local[2]= argv[0];
	local[3]= fqv[101];
	local[4]= argv[0]->c.obj.iv[20];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	argv[0]->c.obj.iv[20] = local[0];
	local[2]= argv[0]->c.obj.iv[20];
	goto IF2422;
IF2421:
	local[2]= NIL;
IF2422:
	if (local[1]==NIL) goto IF2423;
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[3]));
	local[4]= fqv[45];
	local[5]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,4,local+2); /*send-message*/
	local[2]= w;
	goto IF2424;
IF2423:
	local[2]= NIL;
IF2424:
	w = argv[0]->c.obj.iv[20];
	local[0]= w;
BLK2417:
	ctx->vsp=local; return(local[0]);}

/*:draw-active-button*/
static pointer M2425choice_item_draw_active_button(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2429;}
	local[0]= argv[0]->c.obj.iv[20];
ENT2429:
	if (n>=4) { local[1]=(argv[3]); goto ENT2428;}
	local[1]= argv[0]->c.obj.iv[20];
ENT2428:
ENT2427:
	if (n>4) maerror();
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= fqv[28];
	local[4]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[104];
	local[4]= argv[0]->c.obj.iv[19];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[11])(ctx,1,local+4,&ftab[11],fqv[103]); /*fourth*/
	local[4]= w;
	local[5]= fqv[105];
	ctx->vsp=local+6;
	w=(pointer)VPLUS(ctx,2,local+4); /*v+*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[23];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= fqv[28];
	local[4]= loadglobal(fqv[90]);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[104];
	local[4]= argv[0]->c.obj.iv[19];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[11])(ctx,1,local+4,&ftab[11],fqv[103]); /*fourth*/
	local[4]= w;
	local[5]= fqv[106];
	ctx->vsp=local+6;
	w=(pointer)VPLUS(ctx,2,local+4); /*v+*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[23];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK2426:
	ctx->vsp=local; return(local[0]);}

/*:choice*/
static pointer M2430choice_item_choice(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= loadglobal(fqv[14]);
	ctx->vsp=local+4;
	w=(*ftab[3])(ctx,1,local+3,&ftab[3],fqv[40]); /*event-x*/
	local[3]= w;
	local[4]= loadglobal(fqv[14]);
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,1,local+4,&ftab[4],fqv[41]); /*event-y*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[19];
	local[6]= makeint(0);
WHL2432:
	if (local[5]==NIL) goto WHX2433;
	local[7]= local[3];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(*ftab[11])(ctx,1,local+8,&ftab[11],fqv[103]); /*fourth*/
	local[8]= w;
	local[9]= makeint(0);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,2,local+7); /*-*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)ABS(ctx,1,local+7); /*abs*/
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[23];
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto IF2435;
	w = local[6];
	ctx->vsp=local+7;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK2431;
	goto IF2436;
IF2435:
	local[7]= NIL;
IF2436:
	local[7]= local[6];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[6] = w;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[7];
	goto WHL2432;
WHX2433:
	local[7]= NIL;
BLK2434:
	w = NIL;
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2431:
	ctx->vsp=local; return(local[0]);}

/*:buttonpress*/
static pointer M2438choice_item_buttonpress(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= argv[0];
	local[4]= fqv[107];
	local[5]= loadglobal(fqv[14]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	argv[0]->c.obj.iv[21] = w;
	local[3]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2439:
	ctx->vsp=local; return(local[0]);}

/*:buttonrelease*/
static pointer M2440choice_item_buttonrelease(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= argv[0];
	local[4]= fqv[107];
	local[5]= loadglobal(fqv[14]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	if (local[3]==NIL) goto IF2442;
	local[4]= local[3];
	if (argv[0]->c.obj.iv[21]!=local[4]) goto IF2442;
	local[4]= argv[0];
	local[5]= fqv[72];
	local[6]= argv[0]->c.obj.iv[21];
	local[7]= T;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	argv[0]->c.obj.iv[21] = NIL;
	local[4]= argv[0]->c.obj.iv[21];
	goto IF2443;
IF2442:
	local[4]= argv[0];
	local[5]= *(ovafptr(argv[1],fqv[3]));
	local[6]= fqv[46];
	local[7]= loadglobal(fqv[14]);
	ctx->vsp=local+8;
	w=(pointer)SENDMESSAGE(ctx,4,local+4); /*send-message*/
	local[4]= w;
IF2443:
	w = local[4];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2441:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M2444joystick_item_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
RST2446:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-5);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[108], &argv[5], n-5, local+1, 1);
	if (n & (1<<0)) goto KEY2447;
	local[1] = makeint(5);
KEY2447:
	if (n & (1<<1)) goto KEY2448;
	local[2] = NIL;
KEY2448:
	if (n & (1<<2)) goto KEY2449;
	local[3] = T;
KEY2449:
	if (n & (1<<3)) goto KEY2450;
	local[4] = makeflt(-1.00000000e+00);
KEY2450:
	if (n & (1<<4)) goto KEY2451;
	local[5] = makeflt(1.00000000e+00);
KEY2451:
	if (n & (1<<5)) goto KEY2452;
	local[6] = makeflt(-1.00000000e+00);
KEY2452:
	if (n & (1<<6)) goto KEY2453;
	local[7] = makeflt(1.00000000e+00);
KEY2453:
	local[8]= (pointer)get_sym_func(fqv[2]);
	local[9]= argv[0];
	local[10]= *(ovafptr(argv[1],fqv[3]));
	local[11]= fqv[4];
	local[12]= argv[2];
	local[13]= argv[3];
	local[14]= argv[4];
	local[15]= local[0];
	ctx->vsp=local+16;
	w=(pointer)APPLY(ctx,8,local+8); /*apply*/
	local[8]= argv[0]->c.obj.iv[5];
	local[9]= makeint(2);
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	argv[0]->c.obj.iv[24] = w;
	local[8]= argv[0]->c.obj.iv[6];
	local[9]= makeint(2);
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	argv[0]->c.obj.iv[25] = w;
	argv[0]->c.obj.iv[26] = argv[0]->c.obj.iv[24];
	argv[0]->c.obj.iv[27] = argv[0]->c.obj.iv[25];
	argv[0]->c.obj.iv[30] = local[2];
	local[8]= local[4];
	local[9]= local[8];
	w = argv[0];
	w->c.obj.iv[20] = local[9];
	local[8]= local[6];
	local[9]= local[8];
	w = argv[0];
	w->c.obj.iv[21] = local[9];
	local[8]= local[5];
	local[9]= local[8];
	w = argv[0];
	w->c.obj.iv[22] = local[9];
	local[8]= local[7];
	local[9]= local[8];
	w = argv[0];
	w->c.obj.iv[23] = local[9];
	local[8]= local[1];
	local[9]= local[8];
	w = argv[0];
	w->c.obj.iv[19] = local[9];
	local[8]= local[3];
	local[9]= local[8];
	w = argv[0];
	w->c.obj.iv[34] = local[9];
	local[8]= local[4];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	local[9]= makeflt(2.00000000e+00);
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	argv[0]->c.obj.iv[28] = w;
	local[8]= local[6];
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	local[9]= makeflt(2.00000000e+00);
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	argv[0]->c.obj.iv[29] = w;
	local[8]= local[5];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+10;
	w=(pointer)EUSFLOAT(ctx,1,local+9); /*float*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	argv[0]->c.obj.iv[32] = w;
	local[8]= local[7];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	local[9]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+10;
	w=(pointer)EUSFLOAT(ctx,1,local+9); /*float*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	argv[0]->c.obj.iv[33] = w;
	argv[0]->c.obj.iv[31] = NIL;
	local[8]= argv[0];
	local[9]= fqv[73];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	w = argv[0];
	local[0]= w;
BLK2445:
	ctx->vsp=local; return(local[0]);}

/*:redraw*/
static pointer M2454joystick_item_redraw(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[109];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[110];
	local[2]= argv[0]->c.obj.iv[28];
	local[3]= argv[0]->c.obj.iv[29];
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= w;
BLK2455:
	ctx->vsp=local; return(local[0]);}

/*:draw-circles*/
static pointer M2456joystick_item_draw_circles(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= makeint(8);
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[6];
	local[2]= makeint(8);
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= fqv[10];
	local[4]= fqv[11];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[111];
	local[4]= makeint(0);
	local[5]= makeint(0);
	local[6]= argv[0]->c.obj.iv[5];
	local[7]= argv[0]->c.obj.iv[6];
	local[8]= makeint(0);
	local[9]= makeflt(6.28318531e+00);
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,8,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[111];
	local[4]= local[0];
	local[5]= local[1];
	local[6]= argv[0]->c.obj.iv[5];
	local[7]= makeflt(7.50000000e-01);
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ROUND(ctx,1,local+6); /*round*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[6];
	local[8]= makeflt(7.50000000e-01);
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)ROUND(ctx,1,local+7); /*round*/
	local[7]= w;
	local[8]= makeint(0);
	local[9]= makeflt(6.28318531e+00);
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,8,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[111];
	local[4]= makeint(2);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	local[5]= makeint(2);
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[5];
	local[7]= makeflt(5.20000000e-01);
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)CEILING(ctx,1,local+6); /*ceiling*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[6];
	local[8]= makeflt(5.20000000e-01);
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)CEILING(ctx,1,local+7); /*ceiling*/
	local[7]= w;
	local[8]= makeint(0);
	local[9]= makeflt(6.28318531e+00);
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,8,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[111];
	local[4]= makeint(3);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	local[5]= makeint(3);
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[5];
	local[7]= makeflt(2.70000000e-01);
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)CEILING(ctx,1,local+6); /*ceiling*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[6];
	local[8]= makeflt(2.70000000e-01);
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)CEILING(ctx,1,local+7); /*ceiling*/
	local[7]= w;
	local[8]= makeint(0);
	local[9]= makeflt(6.28318531e+00);
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,8,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[74];
	local[4]= makeint(0);
	local[5]= argv[0]->c.obj.iv[6];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[5];
	local[7]= argv[0]->c.obj.iv[6];
	local[8]= makeint(2);
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[74];
	local[4]= argv[0]->c.obj.iv[5];
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	local[5]= makeint(0);
	local[6]= argv[0]->c.obj.iv[5];
	local[7]= makeint(2);
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[74];
	local[4]= makeint(0);
	local[5]= argv[0]->c.obj.iv[6];
	local[6]= argv[0]->c.obj.iv[5];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[74];
	local[4]= makeint(0);
	local[5]= makeint(0);
	local[6]= argv[0]->c.obj.iv[5];
	local[7]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	w = argv[0];
	local[0]= w;
BLK2457:
	ctx->vsp=local; return(local[0]);}

/*:xy*/
static pointer M2458joystick_item_xy(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2462;}
	local[0]= argv[0]->c.obj.iv[28];
ENT2462:
	if (n>=4) { local[1]=(argv[3]); goto ENT2461;}
	local[1]= argv[0]->c.obj.iv[29];
ENT2461:
ENT2460:
	if (n>4) maerror();
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= local[0];
	local[4]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	local[4]= argv[0]->c.obj.iv[22];
	local[5]= argv[0]->c.obj.iv[20];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ROUND(ctx,1,local+2); /*round*/
	argv[0]->c.obj.iv[26] = w;
	local[2]= argv[0]->c.obj.iv[6];
	local[3]= argv[0]->c.obj.iv[6];
	local[4]= local[1];
	local[5]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[23];
	local[6]= argv[0]->c.obj.iv[21];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ROUND(ctx,1,local+2); /*round*/
	argv[0]->c.obj.iv[27] = w;
	w = argv[0]->c.obj.iv[27];
	local[0]= w;
BLK2459:
	ctx->vsp=local; return(local[0]);}

/*:draw-stick*/
static pointer M2463joystick_item_draw_stick(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2468;}
	local[0]= argv[0]->c.obj.iv[28];
ENT2468:
	if (n>=4) { local[1]=(argv[3]); goto ENT2467;}
	local[1]= argv[0]->c.obj.iv[29];
ENT2467:
	if (n>=5) { local[2]=(argv[4]); goto ENT2466;}
	local[2]= T;
ENT2466:
ENT2465:
	if (n>5) maerror();
	local[3]= argv[0];
	local[4]= fqv[75];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= argv[0];
	local[4]= fqv[109];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= argv[0];
	local[4]= fqv[112];
	local[5]= local[0];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= argv[0];
	local[4]= fqv[113];
	local[5]= argv[0]->c.obj.iv[26];
	local[6]= argv[0]->c.obj.iv[19];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[27];
	local[7]= argv[0]->c.obj.iv[19];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[19];
	local[8]= makeint(2);
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[19];
	local[9]= makeint(2);
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	local[9]= makeint(0);
	local[10]= makeflt(6.28318531e+00);
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,8,local+3); /*send*/
	argv[0]->c.obj.iv[28] = local[0];
	argv[0]->c.obj.iv[29] = local[1];
	w = argv[0]->c.obj.iv[29];
	local[0]= w;
BLK2464:
	ctx->vsp=local; return(local[0]);}

/*:value*/
static pointer M2469joystick_item_value(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2474;}
	local[0]= NIL;
ENT2474:
	if (n>=4) { local[1]=(argv[3]); goto ENT2473;}
	local[1]= NIL;
ENT2473:
	if (n>=5) { local[2]=(argv[4]); goto ENT2472;}
	local[2]= NIL;
ENT2472:
ENT2471:
	if (n>5) maerror();
	if (local[0]==NIL) goto IF2475;
	if (local[1]==NIL) goto IF2475;
	local[3]= argv[0]->c.obj.iv[20];
	local[4]= argv[0]->c.obj.iv[22];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)MIN(ctx,2,local+4); /*min*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MAX(ctx,2,local+3); /*max*/
	local[0] = w;
	local[3]= argv[0]->c.obj.iv[21];
	local[4]= argv[0]->c.obj.iv[23];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)MIN(ctx,2,local+4); /*min*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MAX(ctx,2,local+3); /*max*/
	local[1] = w;
	local[3]= argv[0];
	local[4]= fqv[110];
	local[5]= local[0];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF2476;
IF2475:
	local[3]= NIL;
IF2476:
	if (local[2]==NIL) goto IF2477;
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[3]));
	local[5]= fqv[45];
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SENDMESSAGE(ctx,5,local+3); /*send-message*/
	local[3]= w;
	goto IF2478;
IF2477:
	local[3]= NIL;
IF2478:
	local[3]= argv[0]->c.obj.iv[28];
	local[4]= argv[0]->c.obj.iv[29];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[0]= w;
BLK2470:
	ctx->vsp=local; return(local[0]);}

/*:buttonpress*/
static pointer M2480joystick_item_buttonpress(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	local[3]= loadglobal(fqv[14]);
	ctx->vsp=local+4;
	w=(*ftab[3])(ctx,1,local+3,&ftab[3],fqv[40]); /*event-x*/
	local[3]= w;
	local[4]= loadglobal(fqv[14]);
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,1,local+4,&ftab[4],fqv[41]); /*event-y*/
	local[4]= w;
	local[5]= local[3];
	local[6]= argv[0]->c.obj.iv[26];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	local[6]= local[4];
	local[7]= argv[0]->c.obj.iv[27];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	local[7]= local[5];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	local[8]= local[6];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SQRT(ctx,1,local+7); /*sqrt*/
	local[7]= w;
	local[8]= argv[0]->c.obj.iv[19];
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto IF2482;
	argv[0]->c.obj.iv[31] = T;
	local[7]= argv[0]->c.obj.iv[31];
	goto IF2483;
IF2482:
	local[7]= NIL;
IF2483:
	w = local[7];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2481:
	ctx->vsp=local; return(local[0]);}

/*:value-from-event*/
static pointer M2484joystick_item_value_from_event(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	if (n>=4) { local[3]=(argv[3]); goto ENT2487;}
	local[3]= argv[0]->c.obj.iv[34];
ENT2487:
ENT2486:
	if (n>4) maerror();
	local[4]= loadglobal(fqv[14]);
	ctx->vsp=local+5;
	w=(*ftab[3])(ctx,1,local+4,&ftab[3],fqv[40]); /*event-x*/
	local[4]= w;
	local[5]= loadglobal(fqv[14]);
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,1,local+5,&ftab[4],fqv[41]); /*event-y*/
	local[5]= w;
	local[6]= local[4];
	local[7]= argv[0]->c.obj.iv[26];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[27];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,2,local+7); /*-*/
	local[7]= w;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= argv[0]->c.obj.iv[28];
	local[11]= local[6];
	local[12]= argv[0]->c.obj.iv[32];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[8] = w;
	local[10]= argv[0]->c.obj.iv[29];
	local[11]= local[7];
	local[12]= argv[0]->c.obj.iv[33];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[9] = w;
	local[10]= argv[0];
	local[11]= fqv[72];
	local[12]= local[8];
	local[13]= local[9];
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,5,local+10); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	unbindx(ctx,1);
	w = local[4];
	local[0]= w;
BLK2485:
	ctx->vsp=local; return(local[0]);}

/*:motionnotify*/
static pointer M2488joystick_item_motionnotify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	if (argv[0]->c.obj.iv[31]==NIL) goto IF2490;
	local[3]= argv[0];
	local[4]= fqv[114];
	local[5]= loadglobal(fqv[14]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF2491;
IF2490:
	local[3]= NIL;
IF2491:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2489:
	ctx->vsp=local; return(local[0]);}

/*:buttonrelease*/
static pointer M2492joystick_item_buttonrelease(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[14],w);
	if (argv[0]->c.obj.iv[31]==NIL) goto IF2494;
	argv[0]->c.obj.iv[31] = NIL;
	if (argv[0]->c.obj.iv[30]==NIL) goto CON2497;
	local[3]= argv[0];
	local[4]= fqv[72];
	local[5]= argv[0]->c.obj.iv[20];
	local[6]= argv[0]->c.obj.iv[22];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= makeflt(2.00000000e+00);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[21];
	local[7]= argv[0]->c.obj.iv[23];
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	local[7]= makeflt(2.00000000e+00);
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	local[7]= T;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,5,local+3); /*send*/
	local[3]= w;
	goto CON2496;
CON2497:
	if (argv[0]->c.obj.iv[34]!=NIL) goto CON2498;
	local[3]= argv[0];
	local[4]= fqv[114];
	local[5]= loadglobal(fqv[14]);
	local[6]= T;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto CON2496;
CON2498:
	local[3]= NIL;
CON2496:
	goto IF2495;
IF2494:
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[3]));
	local[5]= fqv[46];
	local[6]= loadglobal(fqv[14]);
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,4,local+3); /*send-message*/
	local[3]= w;
IF2495:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2493:
	ctx->vsp=local; return(local[0]);}

/*:create-bitmap-from-file*/
static pointer M2499bitmap_button_item_create_bitmap_from_file(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= loadglobal(fqv[115]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= loadglobal(fqv[115]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= loadglobal(fqv[116]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= loadglobal(fqv[115]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= loadglobal(fqv[115]);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(*ftab[12])(ctx,1,local+5,&ftab[12],fqv[117]); /*probe-file*/
	if (w!=NIL) goto IF2501;
	local[5]= NIL;
	local[6]= fqv[118];
	local[7]= loadglobal(fqv[119]);
	local[8]= argv[2];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,4,local+5); /*format*/
	argv[2] = w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(*ftab[12])(ctx,1,local+5,&ftab[12],fqv[117]); /*probe-file*/
	if (w!=NIL) goto IF2503;
	local[5]= fqv[120];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SIGERROR(ctx,2,local+5); /*error*/
	local[5]= w;
	goto IF2504;
IF2503:
	local[5]= NIL;
IF2504:
	goto IF2502;
IF2501:
	local[5]= NIL;
IF2502:
	local[5]= loadglobal(fqv[121]);
	local[6]= loadglobal(fqv[121]);
	ctx->vsp=local+7;
	w=(*ftab[13])(ctx,1,local+6,&ftab[13],fqv[122]); /*defaultrootwindow*/
	local[6]= w;
	local[7]= argv[2];
	local[8]= local[0];
	local[9]= local[1];
	local[10]= local[2];
	local[11]= local[3];
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(*ftab[14])(ctx,8,local+5,&ftab[14],fqv[123]); /*readbitmapfile*/
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[15])(ctx,1,local+5,&ftab[15],fqv[115]); /*c-int*/
	argv[0]->c.obj.iv[26] = w;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(*ftab[15])(ctx,1,local+5,&ftab[15],fqv[115]); /*c-int*/
	argv[0]->c.obj.iv[27] = w;
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(*ftab[16])(ctx,1,local+5,&ftab[16],fqv[116]); /*c-long*/
	argv[0]->c.obj.iv[25] = w;
	w = argv[0]->c.obj.iv[25];
	local[0]= w;
BLK2500:
	ctx->vsp=local; return(local[0]);}

/*:redraw*/
static pointer M2505bitmap_button_item_redraw(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[32];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK2506:
	ctx->vsp=local; return(local[0]);}

/*:draw-label*/
static pointer M2507bitmap_button_item_draw_label(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2512;}
	local[0]= fqv[24];
ENT2512:
	if (n>=4) { local[1]=(argv[3]); goto ENT2511;}
	local[1]= argv[0]->c.obj.iv[4];
ENT2511:
	if (n>=5) { local[2]=(argv[4]); goto ENT2510;}
	local[2]= makeint(2);
ENT2510:
ENT2509:
	if (n>5) maerror();
	local[3]= argv[0];
	local[4]= fqv[34];
	local[5]= makeint(0);
	local[6]= makeint(0);
	local[7]= argv[0]->c.obj.iv[5];
	local[8]= argv[0]->c.obj.iv[6];
	local[9]= local[2];
	local[10]= argv[0]->c.obj.iv[23];
	local[11]= argv[0]->c.obj.iv[22];
	local[12]= argv[0]->c.obj.iv[4];
	local[13]= argv[0]->c.obj.iv[24];
	local[14]= local[0];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,12,local+3); /*send*/
	local[3]= loadglobal(fqv[121]);
	local[4]= argv[0]->c.obj.iv[25];
	local[5]= argv[0]->c.obj.iv[2];
	local[6]= argv[0]->c.obj.iv[3]->c.obj.iv[2];
	local[7]= makeint(0);
	local[8]= makeint(0);
	local[9]= argv[0]->c.obj.iv[26];
	local[10]= argv[0]->c.obj.iv[27];
	local[11]= makeint(2);
	local[12]= makeint(2);
	local[13]= makeint(1);
	ctx->vsp=local+14;
	w=(*ftab[17])(ctx,11,local+3,&ftab[17],fqv[124]); /*copyplane*/
	local[0]= w;
BLK2508:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M2513bitmap_button_item_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
RST2515:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-5);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[125], &argv[5], n-5, local+1, 1);
	if (n & (1<<0)) goto KEY2516;
	local[1] = NIL;
KEY2516:
	if (n & (1<<1)) goto KEY2517;
	local[2] = NIL;
KEY2517:
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[0];
	local[7]= fqv[126];
	local[8]= argv[2];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	if (local[1]!=NIL) goto IF2518;
	local[6]= argv[0]->c.obj.iv[26];
	local[7]= makeint(4);
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	goto IF2519;
IF2518:
	local[6]= local[1];
IF2519:
	local[4] = local[6];
	if (local[2]!=NIL) goto IF2520;
	local[6]= argv[0]->c.obj.iv[27];
	local[7]= makeint(4);
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	goto IF2521;
IF2520:
	local[6]= local[2];
IF2521:
	local[5] = local[6];
	local[6]= (pointer)get_sym_func(fqv[2]);
	local[7]= argv[0];
	local[8]= *(ovafptr(argv[1],fqv[3]));
	local[9]= fqv[4];
	local[10]= argv[2];
	local[11]= argv[3];
	local[12]= argv[4];
	local[13]= fqv[6];
	local[14]= local[4];
	local[15]= fqv[7];
	local[16]= local[5];
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)APPLY(ctx,12,local+6); /*apply*/
	local[6]= argv[2];
	local[7]= local[6];
	w = argv[0];
	w->c.obj.iv[16] = local[7];
	w = local[6];
	w = argv[0];
	local[0]= w;
BLK2514:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___Xitem(ctx,n,argv,env)
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
	local[0]= fqv[127];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF2522;
	local[0]= fqv[128];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[129],w);
	goto IF2523;
IF2522:
	local[0]= fqv[130];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF2523:
	local[0]= fqv[131];
	local[1]= fqv[132];
	ctx->vsp=local+2;
	w=(*ftab[18])(ctx,2,local+0,&ftab[18],fqv[133]); /*require*/
	local[0]= fqv[134];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[55];
	local[1]= fqv[135];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF2524;
	local[0]= fqv[55];
	local[1]= fqv[135];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[55];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF2526;
	local[0]= fqv[55];
	local[1]= fqv[136];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2527;
IF2526:
	local[0]= NIL;
IF2527:
	local[0]= fqv[55];
	goto IF2525;
IF2524:
	local[0]= NIL;
IF2525:
	ctx->vsp=local+0;
	compfun(ctx,fqv[137],module,F2136clump,fqv[138]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[139],module,F2137replace_key_arg,fqv[140]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2149panel_item_create,fqv[4],fqv[141],fqv[142]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2158panel_item_draw_label,fqv[32],fqv[141],fqv[143]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2160panel_item_notify,fqv[45],fqv[141],fqv[144]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2167panel_item_keypress,fqv[145],fqv[141],fqv[146]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2169panel_item_keyrelease,fqv[147],fqv[141],fqv[148]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2171panel_item_buttonpress,fqv[149],fqv[141],fqv[150]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2173panel_item_motionnotify,fqv[151],fqv[141],fqv[152]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2175panel_item_enternotify,fqv[78],fqv[141],fqv[153]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2177panel_item_leavenotify,fqv[77],fqv[141],fqv[154]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[155],module,F2138make_topleft_edge_polygon,fqv[156]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2180button_item_create,fqv[4],fqv[157],fqv[158]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2199button_item_submenu,fqv[159],fqv[157],fqv[160]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2205button_item_active_color,fqv[161],fqv[157],fqv[162]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2211button_item_resize,fqv[33],fqv[157],fqv[163]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2213button_item_label,fqv[50],fqv[157],fqv[164]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2220button_item_draw_label,fqv[32],fqv[157],fqv[165]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2231button_item_redraw,fqv[73],fqv[157],fqv[166]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2233button_item_keypress,fqv[145],fqv[157],fqv[167]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2235button_item_keyrelease,fqv[147],fqv[157],fqv[168]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2237button_item_buttonpress,fqv[149],fqv[157],fqv[169]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2239button_item_buttonrelease,fqv[46],fqv[157],fqv[170]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2248button_item_enternotify,fqv[78],fqv[157],fqv[171]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2252button_item_leavenotify,fqv[77],fqv[157],fqv[172]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2256menu_button_item_create,fqv[4],fqv[173],fqv[174]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2262menu_button_item_label,fqv[50],fqv[173],fqv[175]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2270menu_button_item_popup_menu,fqv[57],fqv[173],fqv[176]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2272menu_button_item_unmap_menu,fqv[58],fqv[173],fqv[177]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2274menu_button_item_buttonpress,fqv[149],fqv[173],fqv[178]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2276menu_button_item_buttonrelease,fqv[46],fqv[173],fqv[179]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2280menu_button_item_enternotify,fqv[78],fqv[173],fqv[180]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2284text_item_create,fqv[4],fqv[181],fqv[182]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2294text_item_redraw,fqv[73],fqv[181],fqv[183]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2296text_item_getstring,fqv[184],fqv[181],fqv[185]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2298text_item_value,fqv[72],fqv[181],fqv[186]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2307text_item_leavenotify,fqv[77],fqv[181],fqv[187]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2309text_item_enternotify,fqv[78],fqv[181],fqv[188]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2311slider_item_create,fqv[4],fqv[189],fqv[190]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2325slider_item_new_range,fqv[81],fqv[189],fqv[191]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2331slider_item_continuous_notify,fqv[84],fqv[189],fqv[192]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2334slider_item_redraw,fqv[73],fqv[189],fqv[193]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2336slider_item_display_value,fqv[87],fqv[189],fqv[194]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2342slider_item_value,fqv[72],fqv[189],fqv[195]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2351slider_item_nob_x,fqv[83],fqv[189],fqv[196]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2355slider_item_inside_nob_p,fqv[92],fqv[189],fqv[197]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2358slider_item_draw_bar_rectangle,fqv[85],fqv[189],fqv[198]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2360slider_item_draw_nob_rectangle,fqv[86],fqv[189],fqv[199]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2365slider_item_buttonpress,fqv[149],fqv[189],fqv[200]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2369slider_item_compute_value,fqv[93],fqv[189],fqv[201]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2371slider_item_motionnotify,fqv[151],fqv[189],fqv[202]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2375slider_item_buttonrelease,fqv[46],fqv[189],fqv[203]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2379choice_item_create,fqv[4],fqv[204],fqv[205]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2405choice_item_draw_label,fqv[32],fqv[204],fqv[206]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2409choice_item_redraw,fqv[73],fqv[204],fqv[207]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2416choice_item_value,fqv[72],fqv[204],fqv[208]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2425choice_item_draw_active_button,fqv[101],fqv[204],fqv[209]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2430choice_item_choice,fqv[107],fqv[204],fqv[210]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2438choice_item_buttonpress,fqv[149],fqv[204],fqv[211]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2440choice_item_buttonrelease,fqv[46],fqv[204],fqv[212]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2444joystick_item_create,fqv[4],fqv[213],fqv[214]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2454joystick_item_redraw,fqv[73],fqv[213],fqv[215]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2456joystick_item_draw_circles,fqv[109],fqv[213],fqv[216]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2458joystick_item_xy,fqv[112],fqv[213],fqv[217]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2463joystick_item_draw_stick,fqv[110],fqv[213],fqv[218]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2469joystick_item_value,fqv[72],fqv[213],fqv[219]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2480joystick_item_buttonpress,fqv[149],fqv[213],fqv[220]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2484joystick_item_value_from_event,fqv[114],fqv[213],fqv[221]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2488joystick_item_motionnotify,fqv[151],fqv[213],fqv[222]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2492joystick_item_buttonrelease,fqv[46],fqv[213],fqv[223]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2499bitmap_button_item_create_bitmap_from_file,fqv[126],fqv[224],fqv[225]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2505bitmap_button_item_redraw,fqv[73],fqv[224],fqv[226]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2507bitmap_button_item_draw_label,fqv[32],fqv[224],fqv[227]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2513bitmap_button_item_create,fqv[4],fqv[224],fqv[228]);
	local[0]= fqv[229];
	local[1]= fqv[230];
	ctx->vsp=local+2;
	w=(*ftab[19])(ctx,2,local+0,&ftab[19],fqv[231]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<20; i++) ftab[i]=fcallx;
}
