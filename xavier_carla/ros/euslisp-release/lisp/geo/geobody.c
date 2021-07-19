/* ./geobody.c :  entry=geobody */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "geobody.h"
#pragma init (register_geobody)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___geobody();
extern pointer build_quote_vector();
static int register_geobody()
  { add_module_initializer("___geobody", ___geobody);}

static pointer F1252add_wings();

/*:update*/
static pointer M1253faceset_update(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (loadglobal(fqv[0])==NIL) goto IF1255;
	local[0]= loadglobal(fqv[1]);
	local[1]= fqv[2];
	local[2]= argv[0];
	local[3]= fqv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto IF1256;
IF1255:
	local[0]= NIL;
IF1256:
	local[0]= argv[0];
	local[1]= fqv[4];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[9];
WHL1258:
	if (local[1]==NIL) goto WHX1259;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	goto WHL1258;
WHX1259:
	local[2]= NIL;
BLK1260:
	w = NIL;
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[7]); /*remprop*/
	w = argv[0];
	local[0]= w;
BLK1254:
	ctx->vsp=local; return(local[0]);}

/*:vertices*/
static pointer M1262faceset_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[11];
	local[0]= w;
BLK1263:
	ctx->vsp=local; return(local[0]);}

/*:faces*/
static pointer M1264faceset_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1266:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	if (local[0]==NIL) goto CON1268;
	local[1]= (pointer)get_sym_func(fqv[8]);
	local[2]= argv[0];
	local[3]= fqv[9];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[1]= w;
	goto CON1267;
CON1268:
	local[1]= argv[0]->c.obj.iv[9];
	goto CON1267;
CON1269:
	local[1]= NIL;
CON1267:
	w = local[1];
	local[0]= w;
BLK1265:
	ctx->vsp=local; return(local[0]);}

/*:face*/
static pointer M1270faceset_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	w=(pointer)NTH(ctx,2,local+0); /*nth*/
	local[0]= w;
BLK1271:
	ctx->vsp=local; return(local[0]);}

/*:all-edges*/
static pointer M1272faceset_all_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[10];
	local[0]= w;
BLK1273:
	ctx->vsp=local; return(local[0]);}

/*:edges*/
static pointer M1274faceset_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[10];
	local[0]= w;
BLK1275:
	ctx->vsp=local; return(local[0]);}

/*:edge*/
static pointer M1276faceset_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	w=(pointer)NTH(ctx,2,local+0); /*nth*/
	local[0]= w;
BLK1277:
	ctx->vsp=local; return(local[0]);}

/*:vertex*/
static pointer M1278faceset_vertex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[11];
	ctx->vsp=local+2;
	w=(pointer)NTH(ctx,2,local+0); /*nth*/
	local[0]= w;
BLK1279:
	ctx->vsp=local; return(local[0]);}

/*:box*/
static pointer M1280faceset_box(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK1281:
	ctx->vsp=local; return(local[0]);}

/*:color*/
static pointer M1282faceset_color(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1285;}
	local[0]= NIL;
ENT1285:
ENT1284:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1286;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[10];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= w;
	goto IF1287;
IF1286:
	local[1]= argv[0];
	local[2]= fqv[10];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[1]= w;
IF1287:
	w = local[1];
	local[0]= w;
BLK1283:
	ctx->vsp=local; return(local[0]);}

/*:reflectance*/
static pointer M1288faceset_reflectance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1291;}
	local[0]= NIL;
ENT1291:
ENT1290:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]==NIL) goto IF1292;
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= fqv[11];
	ctx->vsp=local+6;
	w=(pointer)PUTPROP(ctx,3,local+3); /*putprop*/
	local[3]= w;
	goto IF1293;
IF1292:
	local[3]= argv[0];
	local[4]= fqv[11];
	ctx->vsp=local+5;
	w=(pointer)GETPROP(ctx,2,local+3); /*get*/
	local[2] = w;
	if (local[2]==NIL) goto IF1294;
	local[3]= local[2];
	goto IF1295;
IF1294:
	local[3]= makeflt(5.00000000e-01);
IF1295:
IF1293:
	w = local[3];
	local[0]= w;
BLK1289:
	ctx->vsp=local; return(local[0]);}

/*:diffusion*/
static pointer M1296faceset_diffusion(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1299;}
	local[0]= NIL;
ENT1299:
ENT1298:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]==NIL) goto IF1300;
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)PUTPROP(ctx,3,local+3); /*putprop*/
	local[3]= w;
	goto IF1301;
IF1300:
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)GETPROP(ctx,2,local+3); /*get*/
	local[2] = w;
	if (local[2]==NIL) goto IF1302;
	local[3]= local[2];
	goto IF1303;
IF1302:
	local[3]= makeflt(5.00000000e-01);
IF1303:
IF1301:
	w = local[3];
	local[0]= w;
BLK1297:
	ctx->vsp=local; return(local[0]);}

/*:holes*/
static pointer M1304faceset_holes(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= (pointer)get_sym_func(fqv[13]);
	local[1]= argv[0]->c.obj.iv[9];
	local[2]= fqv[14];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[15]); /*send-all*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
BLK1305:
	ctx->vsp=local; return(local[0]);}

/*:visible-faces*/
static pointer M1306faceset_visible_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= loadglobal(fqv[16]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto IF1308;
	local[0]= argv[2];
	local[1]= fqv[17];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[2] = w;
	local[0]= argv[2];
	goto IF1309;
IF1308:
	local[0]= NIL;
IF1309:
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO1310,env,argv,local);
	local[1]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
BLK1307:
	ctx->vsp=local; return(local[0]);}

/*:visible-edges*/
static pointer M1311faceset_visible_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[2];
	local[4]= loadglobal(fqv[16]);
	ctx->vsp=local+5;
	w=(pointer)DERIVEDP(ctx,2,local+3); /*derivedp*/
	if (w==NIL) goto IF1313;
	local[3]= argv[2];
	local[4]= fqv[17];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	argv[2] = w;
	local[3]= argv[2];
	goto IF1314;
IF1313:
	local[3]= NIL;
IF1314:
	local[3]= argv[0];
	local[4]= fqv[6];
	ctx->vsp=local+5;
	w=(pointer)GETPROP(ctx,2,local+3); /*get*/
	local[2] = w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)EQUAL(ctx,2,local+3); /*equal*/
	if (w==NIL) goto IF1315;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	goto IF1316;
IF1315:
	local[3]= fqv[18];
	local[4]= makeflt(1.50000000e+00);
	local[5]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ROUND(ctx,1,local+4); /*round*/
	local[4]= w;
	local[5]= fqv[19];
	local[6]= (pointer)get_sym_func(fqv[20]);
	ctx->vsp=local+7;
	w=(*ftab[2])(ctx,4,local+3,&ftab[2],fqv[21]); /*make-hash-table*/
	local[3]= w;
	local[4]= NIL;
	local[5]= argv[0];
	local[6]= fqv[22];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
WHL1318:
	if (local[5]==NIL) goto WHX1319;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= NIL;
	local[7]= local[4];
	local[8]= fqv[23];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
WHL1323:
	if (local[7]==NIL) goto WHX1324;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	local[9]= local[3];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(*ftab[3])(ctx,3,local+8,&ftab[3],fqv[24]); /*sethash*/
	goto WHL1323;
WHX1324:
	local[8]= NIL;
BLK1325:
	w = NIL;
	goto WHL1318;
WHX1319:
	local[6]= NIL;
BLK1320:
	w = NIL;
	local[4]= local[3];
	local[5]= fqv[25];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[2] = w;
	local[4]= argv[0];
	local[5]= argv[2];
	w = local[2];
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[6];
	ctx->vsp=local+7;
	w=(pointer)PUTPROP(ctx,3,local+4); /*putprop*/
	local[4]= local[3]->c.obj.iv[0];
	ctx->vsp=local+5;
	w=(pointer)RECLAIM(ctx,1,local+4); /*system:reclaim*/
	local[4]= local[3]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)RECLAIM(ctx,1,local+4); /*system:reclaim*/
	w = local[2];
	local[3]= w;
IF1316:
	w = local[3];
	local[0]= w;
BLK1312:
	ctx->vsp=local; return(local[0]);}

/*:contour-edges*/
static pointer M1327faceset_contour_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[10];
WHL1330:
	if (local[4]==NIL) goto WHX1331;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3]->c.obj.iv[3];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,2,local+5,&ftab[4],fqv[26]); /*member*/
	if (w==NIL) goto CON1335;
	local[5]= local[3]->c.obj.iv[4];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,2,local+5,&ftab[4],fqv[26]); /*member*/
	if (w!=NIL) goto IF1336;
	local[5]= local[3];
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[2];
	goto IF1337;
IF1336:
	local[5]= NIL;
IF1337:
	goto CON1334;
CON1335:
	local[5]= local[3]->c.obj.iv[4];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,2,local+5,&ftab[4],fqv[26]); /*member*/
	if (w==NIL) goto CON1338;
	local[5]= local[3]->c.obj.iv[3];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,2,local+5,&ftab[4],fqv[26]); /*member*/
	if (w!=NIL) goto IF1339;
	local[5]= local[3];
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[2];
	goto IF1340;
IF1339:
	local[5]= NIL;
IF1340:
	goto CON1334;
CON1338:
	local[5]= NIL;
CON1334:
	goto WHL1330;
WHX1331:
	local[5]= NIL;
BLK1332:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK1328:
	ctx->vsp=local; return(local[0]);}

/*:non-contour-edges*/
static pointer M1341faceset_non_contour_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[10];
WHL1344:
	if (local[4]==NIL) goto WHX1345;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3]->c.obj.iv[3];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,2,local+5,&ftab[4],fqv[26]); /*member*/
	if (w==NIL) goto IF1348;
	local[5]= local[3]->c.obj.iv[4];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,2,local+5,&ftab[4],fqv[26]); /*member*/
	if (w==NIL) goto IF1348;
	local[5]= local[3];
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[2];
	goto IF1349;
IF1348:
	local[5]= NIL;
IF1349:
	goto WHL1344;
WHX1345:
	local[5]= NIL;
BLK1346:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK1342:
	ctx->vsp=local; return(local[0]);}

/*:common-box*/
static pointer M1350faceset_common_box(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1353;}
	local[0]= NIL;
ENT1353:
ENT1352:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[8];
	local[2]= fqv[27];
	local[3]= argv[2];
	local[4]= fqv[28];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK1351:
	ctx->vsp=local; return(local[0]);}

/*:newbox*/
static pointer M1354faceset_newbox(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1357;}
	local[0]= loadglobal(fqv[29]);
ENT1357:
ENT1356:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[11];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[5])(ctx,2,local+1,&ftab[5],fqv[30]); /*make-bounding-box*/
	argv[0]->c.obj.iv[8] = w;
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK1355:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1310(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[31];
	local[2]= env->c.clo.env1[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (w==NIL) goto IF1358;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF1359;
IF1358:
	local[0]= NIL;
IF1359:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:reset-vertices*/
static pointer M1360faceset_reset_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[12];
	local[1]= argv[0]->c.obj.iv[11];
	local[2]= argv[0]->c.obj.iv[5]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[5]->c.obj.iv[2];
WHL1362:
	if (local[0]==NIL) goto WHX1363;
	local[4]= local[2];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)TRANSFORM(ctx,3,local+4); /*transform*/
	local[4]= local[3];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)VPLUS(ctx,3,local+4); /*v+*/
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[4];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	goto WHL1362;
WHX1363:
	local[4]= NIL;
BLK1364:
	local[4]= argv[0]->c.obj.iv[8];
	local[5]= fqv[32];
	local[6]= argv[0]->c.obj.iv[11];
	local[7]= loadglobal(fqv[29]);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = argv[0];
	local[0]= w;
BLK1361:
	ctx->vsp=local; return(local[0]);}

/*:translate-vertices*/
static pointer M1367faceset_translate_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[12];
WHL1370:
	if (local[1]==NIL) goto WHX1371;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)VPLUS(ctx,3,local+2); /*v+*/
	goto WHL1370;
WHX1371:
	local[2]= NIL;
BLK1372:
	w = NIL;
	local[0]= argv[0];
	local[1]= fqv[33];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = argv[0];
	local[0]= w;
BLK1368:
	ctx->vsp=local; return(local[0]);}

/*:rotate-vertices*/
static pointer M1374faceset_rotate_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[34]); /*float-vector-p*/
	if (w==NIL) goto IF1376;
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(*ftab[7])(ctx,2,local+1,&ftab[7],fqv[35]); /*rotation*/
	local[0] = w;
	local[1]= local[0];
	goto IF1377;
IF1376:
	local[1]= NIL;
IF1377:
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[12];
WHL1379:
	if (local[2]==NIL) goto WHX1380;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,1,local+3,&ftab[6],fqv[34]); /*float-vector-p*/
	if (w==NIL) goto IF1383;
	local[3]= local[0];
	local[4]= local[1];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)TRANSFORM(ctx,3,local+3); /*transform*/
	local[3]= w;
	goto IF1384;
IF1383:
	local[3]= local[1];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)ROTVEC(ctx,4,local+3); /*rotate-vector*/
	local[3]= w;
IF1384:
	goto WHL1379;
WHX1380:
	local[3]= NIL;
BLK1381:
	w = NIL;
	local[0]= argv[0];
	local[1]= fqv[33];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = argv[0];
	local[0]= w;
BLK1375:
	ctx->vsp=local; return(local[0]);}

/*:magnify*/
static pointer M1385faceset_magnify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1388;}
	local[0]= NIL;
ENT1388:
ENT1387:
	if (n>4) maerror();
	if (local[0]==NIL) goto CON1390;
	local[1]= local[0];
	local[2]= fqv[36];
	ctx->vsp=local+3;
	w=(pointer)EQ(ctx,2,local+1); /*eql*/
	if (w==NIL) goto CON1392;
	local[1]= fqv[37];
	goto CON1391;
CON1392:
	local[1]= local[0];
	local[2]= fqv[38];
	ctx->vsp=local+3;
	w=(pointer)EQ(ctx,2,local+1); /*eql*/
	if (w==NIL) goto CON1393;
	local[1]= fqv[39];
	goto CON1391;
CON1393:
	local[1]= local[0];
	local[2]= fqv[40];
	ctx->vsp=local+3;
	w=(pointer)EQ(ctx,2,local+1); /*eql*/
	if (w==NIL) goto CON1394;
	local[1]= fqv[41];
	goto CON1391;
CON1394:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)VNORMALIZE(ctx,1,local+1); /*normalize-vector*/
	local[1]= w;
	goto CON1391;
CON1395:
	local[1]= NIL;
CON1391:
	local[0] = local[1];
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[12];
WHL1397:
	if (local[2]==NIL) goto WHX1398;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[2];
	local[4]= makeflt(1.00000000e+00);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	local[4]= local[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)VINNERPRODUCT(ctx,2,local+4); /*v.*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SCALEVEC(ctx,2,local+3); /*scale*/
	local[3]= w;
	local[4]= local[1];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)VPLUS(ctx,3,local+3); /*v+*/
	goto WHL1397;
WHX1398:
	local[3]= NIL;
BLK1399:
	w = NIL;
	local[1]= w;
	goto CON1389;
CON1390:
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[12];
WHL1403:
	if (local[2]==NIL) goto WHX1404;
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
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SCALEVEC(ctx,3,local+3); /*scale*/
	goto WHL1403;
WHX1404:
	local[3]= NIL;
BLK1405:
	w = NIL;
	local[1]= w;
	goto CON1389;
CON1401:
	local[1]= NIL;
CON1389:
	local[1]= argv[0];
	local[2]= fqv[33];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = argv[0];
	local[0]= w;
BLK1386:
	ctx->vsp=local; return(local[0]);}

/*:faces-intersect-with-point-vector*/
static pointer M1407faceset_faces_intersect_with_point_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	w = argv[3];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[42],w);
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[0]->c.obj.iv[9];
WHL1410:
	if (local[6]==NIL) goto WHX1411;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[5];
	local[8]= fqv[43];
	local[9]= argv[2];
	local[10]= loadglobal(fqv[42]);
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[4] = w;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	if (fqv[44]!=local[7]) goto IF1414;
	local[7]= local[5];
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	w = local[3];
	ctx->vsp=local+8;
	local[3] = cons(ctx,local[7],w);
	local[7]= local[3];
	goto IF1415;
IF1414:
	local[7]= NIL;
IF1415:
	goto WHL1410;
WHX1411:
	local[7]= NIL;
BLK1412:
	w = NIL;
	w = local[3];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1408:
	ctx->vsp=local; return(local[0]);}

/*:distance*/
static pointer M1416faceset_distance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[2];
	local[4]= loadglobal(fqv[45]);
	ctx->vsp=local+5;
	w=(pointer)DERIVEDP(ctx,2,local+3); /*derivedp*/
	if (w==NIL) goto CON1419;
	local[0] = makeflt(1.00000000e+30);
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[9];
WHL1421:
	if (local[4]==NIL) goto WHX1422;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3];
	local[6]= fqv[46];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[2] = w;
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)ABS(ctx,1,local+6); /*abs*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LESSP(ctx,2,local+5); /*<*/
	if (w==NIL) goto IF1425;
	local[0] = local[2];
	local[1] = local[3];
	local[5]= local[1];
	goto IF1426;
IF1425:
	local[5]= NIL;
IF1426:
	goto WHL1421;
WHX1422:
	local[5]= NIL;
BLK1423:
	w = NIL;
	local[3]= w;
	goto CON1418;
CON1419:
	local[3]= argv[2];
	local[4]= loadglobal(fqv[47]);
	ctx->vsp=local+5;
	w=(pointer)DERIVEDP(ctx,2,local+3); /*derivedp*/
	if (w==NIL) goto CON1427;
	local[3]= argv[2];
	local[4]= fqv[46];
	w=argv[0]->c.obj.iv[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[0] = w;
	w=argv[0]->c.obj.iv[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	local[3]= NIL;
	w=argv[0]->c.obj.iv[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
WHL1429:
	if (local[4]==NIL) goto WHX1430;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= argv[2];
	local[6]= fqv[46];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[2] = w;
	local[5]= local[2];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)LESSP(ctx,2,local+5); /*<*/
	if (w==NIL) goto IF1433;
	local[0] = local[2];
	local[1] = local[3];
	local[5]= local[1];
	goto IF1434;
IF1433:
	local[5]= NIL;
IF1434:
	goto WHL1429;
WHX1430:
	local[5]= NIL;
BLK1431:
	w = NIL;
	local[3]= w;
	goto CON1418;
CON1427:
	local[3]= NIL;
CON1418:
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(*ftab[8])(ctx,2,local+3,&ftab[8],fqv[48]); /*values*/
	local[0]= w;
BLK1417:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1435faceset_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1437:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[49], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY1438;
	local[1] = NIL;
KEY1438:
	if (n & (1<<1)) goto KEY1439;
	local[2] = NIL;
KEY1439:
	if (n & (1<<2)) goto KEY1440;
	local[3] = NIL;
KEY1440:
	if (n & (1<<3)) goto KEY1441;
	local[4] = NIL;
KEY1441:
	if (n & (1<<4)) goto KEY1442;
	local[5] = NIL;
KEY1442:
	if (n & (1<<5)) goto KEY1443;
	local[6] = NIL;
KEY1443:
	if (local[1]==NIL) goto IF1444;
	argv[0]->c.obj.iv[9] = local[1];
	if (local[2]!=NIL) goto IF1446;
	local[7]= (pointer)get_sym_func(fqv[13]);
	local[8]= local[1];
	local[9]= fqv[23];
	ctx->vsp=local+10;
	w=(*ftab[1])(ctx,2,local+8,&ftab[1],fqv[15]); /*send-all*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,2,local+7); /*apply*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[9])(ctx,1,local+7,&ftab[9],fqv[50]); /*remove-duplicates*/
	argv[0]->c.obj.iv[10] = w;
	local[7]= argv[0]->c.obj.iv[10];
	goto IF1447;
IF1446:
	local[7]= NIL;
IF1447:
	if (local[3]!=NIL) goto IF1448;
	local[7]= (pointer)get_sym_func(fqv[13]);
	local[8]= local[1];
	local[9]= fqv[51];
	ctx->vsp=local+10;
	w=(*ftab[1])(ctx,2,local+8,&ftab[1],fqv[15]); /*send-all*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,2,local+7); /*apply*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[9])(ctx,1,local+7,&ftab[9],fqv[50]); /*remove-duplicates*/
	argv[0]->c.obj.iv[11] = w;
	local[7]= argv[0]->c.obj.iv[11];
	goto IF1449;
IF1448:
	local[7]= NIL;
IF1449:
	goto IF1445;
IF1444:
	local[7]= NIL;
IF1445:
	local[7]= (pointer)get_sym_func(fqv[52]);
	local[8]= argv[0];
	local[9]= *(ovafptr(argv[1],fqv[53]));
	local[10]= fqv[32];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)APPLY(ctx,5,local+7); /*apply*/
	if (local[2]==NIL) goto IF1450;
	argv[0]->c.obj.iv[10] = local[2];
	local[7]= argv[0]->c.obj.iv[10];
	goto IF1451;
IF1450:
	local[7]= NIL;
IF1451:
	if (local[3]==NIL) goto IF1452;
	argv[0]->c.obj.iv[11] = local[3];
	local[7]= argv[0]->c.obj.iv[11];
	goto IF1453;
IF1452:
	local[7]= NIL;
IF1453:
	local[7]= loadglobal(fqv[54]);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,1,local+7); /*instantiate*/
	local[7]= w;
	local[8]= local[7];
	local[9]= fqv[32];
	local[10]= argv[0]->c.obj.iv[11];
	local[11]= loadglobal(fqv[29]);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	w = local[7];
	argv[0]->c.obj.iv[8] = w;
	if (argv[0]->c.obj.iv[12]!=NIL) goto IF1455;
	local[7]= NIL;
	goto IF1456;
IF1455:
	local[7]= NIL;
IF1456:
	local[7]= (pointer)get_sym_func(fqv[55]);
	local[8]= argv[0]->c.obj.iv[11];
	ctx->vsp=local+9;
	w=(pointer)MAPCAR(ctx,2,local+7); /*mapcar*/
	argv[0]->c.obj.iv[12] = w;
	if (local[4]==NIL) goto IF1457;
	local[7]= argv[0];
	local[8]= local[4];
	local[9]= fqv[10];
	ctx->vsp=local+10;
	w=(pointer)PUTPROP(ctx,3,local+7); /*putprop*/
	local[7]= w;
	goto IF1458;
IF1457:
	local[7]= NIL;
IF1458:
	if (local[5]==NIL) goto IF1459;
	local[7]= argv[0];
	local[8]= local[5];
	local[9]= fqv[11];
	ctx->vsp=local+10;
	w=(pointer)PUTPROP(ctx,3,local+7); /*putprop*/
	local[7]= w;
	goto IF1460;
IF1459:
	local[7]= NIL;
IF1460:
	if (local[6]==NIL) goto IF1461;
	local[7]= argv[0];
	local[8]= local[6];
	local[9]= fqv[12];
	ctx->vsp=local+10;
	w=(pointer)PUTPROP(ctx,3,local+7); /*putprop*/
	local[7]= w;
	goto IF1462;
IF1461:
	local[7]= NIL;
IF1462:
	w = argv[0];
	local[0]= w;
BLK1436:
	ctx->vsp=local; return(local[0]);}

/*:translate-vertices*/
static pointer M1463body_translate_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[53]));
	local[2]= fqv[56];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SENDMESSAGE(ctx,4,local+0); /*send-message*/
	local[0]= argv[0]->c.obj.iv[15];
	local[1]= fqv[56];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	w = argv[0];
	local[0]= w;
BLK1464:
	ctx->vsp=local; return(local[0]);}

/*:rotate-vertices*/
static pointer M1465body_rotate_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[53]));
	local[2]= fqv[57];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,5,local+0); /*send-message*/
	local[0]= argv[0]->c.obj.iv[15];
	local[1]= fqv[57];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	w = argv[0];
	local[0]= w;
BLK1466:
	ctx->vsp=local; return(local[0]);}

/*:magnify*/
static pointer M1467body_magnify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1470;}
	local[0]= NIL;
ENT1470:
ENT1469:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[53]));
	local[3]= fqv[58];
	local[4]= argv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	local[1]= argv[0]->c.obj.iv[15];
	local[2]= fqv[58];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)EUSFLOAT(ctx,1,local+3); /*float*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,3,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)NCONC(ctx,2,local+1); /*nconc*/
	w = argv[0];
	local[0]= w;
BLK1468:
	ctx->vsp=local; return(local[0]);}

/*:euler*/
static pointer M1471body_euler(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[11];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[14];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	local[4]= local[1];
	local[5]= makeint(-(intval(local[2])));
	local[6]= makeint(-(intval(local[0])));
	local[7]= makeint(2);
	w = local[3];
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	w = (pointer)((eusinteger_t)local[7] + (eusinteger_t)w);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	w = (pointer)((eusinteger_t)local[6] + (eusinteger_t)w);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	w = (pointer)((eusinteger_t)local[5] + (eusinteger_t)w);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[4]= (pointer)((eusinteger_t)local[4] + (eusinteger_t)w);
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[0]= w;
BLK1472:
	ctx->vsp=local; return(local[0]);}

/*:perimeter*/
static pointer M1473body_perimeter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= (pointer)get_sym_func(fqv[59]);
	local[1]= argv[0]->c.obj.iv[10];
	local[2]= fqv[60];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[15]); /*send-all*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
BLK1474:
	ctx->vsp=local; return(local[0]);}

/*:volume*/
static pointer M1475body_volume(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1478;}
	local[0]= fqv[61];
ENT1478:
ENT1477:
	if (n>3) maerror();
	local[1]= (pointer)get_sym_func(fqv[59]);
	local[2]= argv[0]->c.obj.iv[9];
	local[3]= fqv[62];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,3,local+2,&ftab[1],fqv[15]); /*send-all*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[0]= w;
BLK1476:
	ctx->vsp=local; return(local[0]);}

/*:centroid*/
static pointer M1479body_centroid(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1482;}
	local[0]= makeint(0);
	local[1]= makeint(0);
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
ENT1482:
ENT1481:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[9];
	local[2]= fqv[63];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[1])(ctx,3,local+1,&ftab[1],fqv[15]); /*send-all*/
	local[1]= w;
	local[2]= (pointer)get_sym_func(fqv[59]);
	local[3]= (pointer)get_sym_func(fqv[64]);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,2,local+2); /*apply*/
	local[2]= w;
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO1483,env,argv,local);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	local[4]= makeint(0);
	local[5]= makeint(0);
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	local[5]= NIL;
	local[6]= local[3];
WHL1485:
	if (local[6]==NIL) goto WHX1486;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[5];
	local[8]= local[4];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)VPLUS(ctx,3,local+7); /*v+*/
	goto WHL1485;
WHX1486:
	local[7]= NIL;
BLK1487:
	w = NIL;
	local[5]= makeflt(1.00000000e+00);
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= local[4];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SCALEVEC(ctx,3,local+5); /*scale*/
	w = local[4];
	local[0]= w;
BLK1480:
	ctx->vsp=local; return(local[0]);}

/*:world-centroid*/
static pointer M1489body_world_centroid(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[65];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[66];
	local[2]= argv[0];
	local[3]= fqv[63];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1490:
	ctx->vsp=local; return(local[0]);}

/*:area*/
static pointer M1491body_area(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= (pointer)get_sym_func(fqv[59]);
	local[1]= argv[0]->c.obj.iv[9];
	local[2]= fqv[67];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[15]); /*send-all*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
BLK1492:
	ctx->vsp=local; return(local[0]);}

/*:extream-point*/
static pointer M1493body_extream_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[0]->c.obj.iv[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= argv[2];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	w=argv[0]->c.obj.iv[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
WHL1496:
	if (local[4]==NIL) goto WHX1497;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= argv[2];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)VINNERPRODUCT(ctx,2,local+5); /*v.*/
	local[2] = w;
	local[5]= local[2];
	{ double left,right;
		right=fltval(local[1]); left=fltval(local[5]);
	if (left <= right) goto IF1500;}
	local[1] = local[2];
	local[0] = local[3];
	local[5]= local[0];
	goto IF1501;
IF1500:
	local[5]= NIL;
IF1501:
	goto WHL1496;
WHX1497:
	local[5]= NIL;
BLK1498:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK1494:
	ctx->vsp=local; return(local[0]);}

/*:length*/
static pointer M1502body_length(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0];
	local[2]= fqv[68];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= argv[0];
	local[3]= fqv[68];
	local[4]= makeflt(-1.00000000e+00);
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SCALEVEC(ctx,2,local+4); /*scale*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	{ double x,y;
		y=fltval(w); x=fltval(local[0]);
		local[0]=(makeflt(x - y));}
	w = local[0];
	local[0]= w;
BLK1503:
	ctx->vsp=local; return(local[0]);}

/*:supporting-faces*/
static pointer M1504body_supporting_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1507;}
	local[0]= makeflt(0.00000000e+00);
	local[1]= makeflt(0.00000000e+00);
	local[2]= makeflt(-1.00000000e+00);
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*floatvector*/
	local[0]= w;
ENT1507:
ENT1506:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[69];
	local[3]= argv[0];
	local[4]= fqv[63];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK1505:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1483(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= (pointer)get_sym_func(fqv[70]);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:possibly-interfering-faces*/
static pointer M1508body_possibly_interfering_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO1510,env,argv,local);
	local[1]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
BLK1509:
	ctx->vsp=local; return(local[0]);}

/*:possibly-interfering-edges*/
static pointer M1511body_possibly_interfering_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO1513,env,argv,local);
	local[1]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
BLK1512:
	ctx->vsp=local; return(local[0]);}

/*:intersect-face*/
static pointer M1514body_intersect_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[9];
WHL1517:
	if (local[1]==NIL) goto WHX1518;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= fqv[71];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	if (w!=NIL) goto OR1523;
	local[2]= argv[2];
	local[3]= fqv[71];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	if (w!=NIL) goto OR1523;
	goto IF1521;
OR1523:
	w = T;
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK1515;
	goto IF1522;
IF1521:
	local[2]= NIL;
IF1522:
	goto WHL1517;
WHX1518:
	local[2]= NIL;
BLK1519:
	w = NIL;
	w = NIL;
	local[0]= w;
BLK1515:
	ctx->vsp=local; return(local[0]);}

/*:intersectp*/
static pointer M1524body_intersectp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= fqv[27];
	local[2]= argv[2];
	local[3]= fqv[28];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]==NIL) goto IF1526;
	local[3]= argv[0];
	local[4]= fqv[72];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[1] = w;
	local[3]= argv[2];
	local[4]= fqv[72];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[2] = w;
	local[3]= NIL;
	local[4]= local[1];
WHL1529:
	if (local[4]==NIL) goto WHX1530;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= NIL;
	local[6]= local[2];
WHL1534:
	if (local[6]==NIL) goto WHX1535;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[3];
	local[8]= fqv[28];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= fqv[27];
	local[9]= local[5];
	local[10]= fqv[28];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[0] = w;
	local[7]= local[3];
	local[8]= fqv[71];
	local[9]= local[5];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	if (w!=NIL) goto OR1540;
	local[7]= local[5];
	local[8]= fqv[71];
	local[9]= local[3];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	if (w!=NIL) goto OR1540;
	goto IF1538;
OR1540:
	w = T;
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK1525;
	goto IF1539;
IF1538:
	local[7]= NIL;
IF1539:
	goto WHL1534;
WHX1535:
	local[7]= NIL;
BLK1536:
	w = NIL;
	goto WHL1529;
WHX1530:
	local[5]= NIL;
BLK1531:
	w = NIL;
	local[3]= w;
	goto IF1527;
IF1526:
	local[3]= NIL;
IF1527:
	w = local[3];
	local[0]= w;
BLK1525:
	ctx->vsp=local; return(local[0]);}

/*:intersectp2*/
static pointer M1541body_intersectp2(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1544;}
	local[0]= loadglobal(fqv[73]);
ENT1544:
ENT1543:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[74];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	if (local[1]==NIL) goto IF1545;
	local[10]= argv[0];
	local[11]= fqv[72];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[2] = w;
	local[10]= argv[2];
	local[11]= fqv[72];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[3] = w;
	local[10]= argv[0];
	local[11]= fqv[75];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[4] = w;
	local[10]= argv[2];
	local[11]= fqv[75];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[5] = w;
	local[10]= NIL;
	local[11]= local[2];
WHL1548:
	if (local[11]==NIL) goto WHX1549;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[12];
	local[10] = w;
	local[12]= NIL;
	local[13]= local[5];
WHL1553:
	if (local[13]==NIL) goto WHX1554;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13] = (w)->c.cons.cdr;
	w = local[14];
	local[12] = w;
	local[14]= local[10];
	local[15]= fqv[76];
	local[16]= local[12];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	if (w==NIL) goto CON1558;
	if (local[8]!=NIL) goto IF1559;
	local[14]= NIL;
	local[15]= local[10];
	local[16]= fqv[23];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
WHL1562:
	if (local[15]==NIL) goto WHX1563;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15] = (w)->c.cons.cdr;
	w = local[16];
	local[14] = w;
	local[16]= local[14];
	local[17]= fqv[77];
	local[18]= local[12];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,3,local+16); /*send*/
	if (!iscons(w)) goto IF1566;
	local[16]= local[10];
	local[17]= fqv[78];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,2,local+16); /*send*/
	local[16]= w;
	local[17]= makeflt(1.00000000e+00);
	local[18]= local[16];
	local[19]= local[12]->c.obj.iv[3];
	local[20]= fqv[78];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,2,local+19); /*send*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)VINNERPRODUCT(ctx,2,local+18); /*v.*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(*ftab[10])(ctx,2,local+17,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1570;
	local[17]= makeflt(1.00000000e+00);
	local[18]= local[16];
	local[19]= local[12]->c.obj.iv[4];
	local[20]= fqv[78];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,2,local+19); /*send*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)VINNERPRODUCT(ctx,2,local+18); /*v.*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(*ftab[10])(ctx,2,local+17,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1570;
	goto IF1568;
OR1570:
	w = fqv[80];
	ctx->vsp=local+17;
	local[0]=w;
	goto BLK1542;
	goto IF1569;
IF1568:
	local[8] = fqv[81];
	w = local[8];
	ctx->vsp=local+17;
	local[16]=w;
	goto BLK1564;
IF1569:
	w = local[17];
	local[16]= w;
	goto IF1567;
IF1566:
	local[16]= NIL;
IF1567:
	goto WHL1562;
WHX1563:
	local[16]= NIL;
BLK1564:
	w = NIL;
	local[14]= local[10];
	local[15]= fqv[82];
	local[16]= local[12]->c.obj.iv[1];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	if (w==NIL) goto IF1571;
	local[14]= local[10];
	local[15]= fqv[78];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,2,local+14); /*send*/
	local[14]= w;
	local[15]= makeflt(1.00000000e+00);
	local[16]= local[14];
	local[17]= local[12]->c.obj.iv[3];
	local[18]= fqv[78];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)VINNERPRODUCT(ctx,2,local+16); /*v.*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(*ftab[10])(ctx,2,local+15,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1575;
	local[15]= makeflt(1.00000000e+00);
	local[16]= local[14];
	local[17]= local[12]->c.obj.iv[4];
	local[18]= fqv[78];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)VINNERPRODUCT(ctx,2,local+16); /*v.*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(*ftab[10])(ctx,2,local+15,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1575;
	goto IF1573;
OR1575:
	w = fqv[80];
	ctx->vsp=local+15;
	local[0]=w;
	goto BLK1542;
	goto IF1574;
IF1573:
	local[8] = fqv[81];
	local[15]= local[8];
IF1574:
	w = local[15];
	local[14]= w;
	goto IF1572;
IF1571:
	local[14]= NIL;
IF1572:
	goto IF1560;
IF1559:
	local[14]= NIL;
IF1560:
	goto CON1557;
CON1558:
	local[14]= local[10];
	local[15]= fqv[27];
	local[16]= local[12]->c.obj.iv[1];
	local[17]= local[12]->c.obj.iv[2];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,4,local+14); /*send*/
	local[6] = w;
	local[14]= local[6];
	if (loadglobal(fqv[83])==local[14]) goto IF1577;
	local[14]= makeflt(0.00000000e+00);
	local[15]= local[6];
	local[16]= makeflt(1.00000000e+00);
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(*ftab[11])(ctx,4,local+14,&ftab[11],fqv[84]); /*eps-in-range*/
	if (w==NIL) goto IF1577;
	local[14]= local[12];
	local[15]= fqv[85];
	local[16]= local[6];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[7] = w;
	local[14]= local[10];
	local[15]= fqv[82];
	local[16]= local[7];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[9] = w;
	local[14]= local[6];
	local[15]= makeflt(0.00000000e+00);
	local[16]= local[0];
	ctx->vsp=local+17;
	w=(*ftab[10])(ctx,3,local+14,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1581;
	local[14]= local[6];
	local[15]= makeflt(1.00000000e+00);
	local[16]= local[0];
	ctx->vsp=local+17;
	w=(*ftab[10])(ctx,3,local+14,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1581;
	goto CON1580;
OR1581:
	local[14]= local[9];
	local[15]= fqv[86];
	ctx->vsp=local+16;
	w=(*ftab[4])(ctx,2,local+14,&ftab[4],fqv[26]); /*member*/
	if (w==NIL) goto CON1580;
	local[8] = fqv[81];
	local[14]= local[8];
	goto CON1579;
CON1580:
	local[14]= local[9];
	local[15]= local[14];
	if (fqv[44]!=local[15]) goto IF1584;
	w = fqv[80];
	ctx->vsp=local+15;
	local[0]=w;
	goto BLK1542;
	goto IF1585;
IF1584:
	local[15]= local[14];
	if (fqv[87]!=local[15]) goto IF1586;
	local[8] = fqv[81];
	local[15]= local[8];
	goto IF1587;
IF1586:
	local[15]= NIL;
IF1587:
IF1585:
	w = local[15];
	local[14]= w;
	goto CON1579;
CON1582:
	local[14]= NIL;
CON1579:
	goto IF1578;
IF1577:
	local[14]= NIL;
IF1578:
	goto CON1557;
CON1576:
	local[14]= NIL;
CON1557:
	goto WHL1553;
WHX1554:
	local[14]= NIL;
BLK1555:
	w = NIL;
	goto WHL1548;
WHX1549:
	local[12]= NIL;
BLK1550:
	w = NIL;
	local[10]= NIL;
	local[11]= local[3];
WHL1589:
	if (local[11]==NIL) goto WHX1590;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[12];
	local[10] = w;
	local[12]= NIL;
	local[13]= local[5];
WHL1594:
	if (local[13]==NIL) goto WHX1595;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13] = (w)->c.cons.cdr;
	w = local[14];
	local[12] = w;
	local[14]= local[10];
	local[15]= fqv[76];
	local[16]= local[12];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	if (w==NIL) goto CON1599;
	if (local[8]!=NIL) goto IF1600;
	local[14]= NIL;
	local[15]= local[10];
	local[16]= fqv[23];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
WHL1603:
	if (local[15]==NIL) goto WHX1604;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15] = (w)->c.cons.cdr;
	w = local[16];
	local[14] = w;
	local[16]= local[14];
	local[17]= fqv[77];
	local[18]= local[12];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,3,local+16); /*send*/
	if (!iscons(w)) goto IF1607;
	local[16]= local[10];
	local[17]= fqv[78];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,2,local+16); /*send*/
	local[16]= w;
	local[17]= makeflt(1.00000000e+00);
	local[18]= local[16];
	local[19]= local[12]->c.obj.iv[3];
	local[20]= fqv[78];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,2,local+19); /*send*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)VINNERPRODUCT(ctx,2,local+18); /*v.*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(*ftab[10])(ctx,2,local+17,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1611;
	local[17]= makeflt(1.00000000e+00);
	local[18]= local[16];
	local[19]= local[12]->c.obj.iv[4];
	local[20]= fqv[78];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,2,local+19); /*send*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)VINNERPRODUCT(ctx,2,local+18); /*v.*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(*ftab[10])(ctx,2,local+17,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1611;
	goto IF1609;
OR1611:
	w = fqv[80];
	ctx->vsp=local+17;
	local[0]=w;
	goto BLK1542;
	goto IF1610;
IF1609:
	local[8] = fqv[81];
	w = local[8];
	ctx->vsp=local+17;
	local[16]=w;
	goto BLK1605;
IF1610:
	w = local[17];
	local[16]= w;
	goto IF1608;
IF1607:
	local[16]= NIL;
IF1608:
	goto WHL1603;
WHX1604:
	local[16]= NIL;
BLK1605:
	w = NIL;
	local[14]= local[10];
	local[15]= fqv[82];
	local[16]= local[12]->c.obj.iv[1];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	if (w==NIL) goto IF1612;
	local[14]= local[10];
	local[15]= fqv[78];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,2,local+14); /*send*/
	local[14]= w;
	local[15]= makeflt(1.00000000e+00);
	local[16]= local[14];
	local[17]= local[12]->c.obj.iv[3];
	local[18]= fqv[78];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)VINNERPRODUCT(ctx,2,local+16); /*v.*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(*ftab[10])(ctx,2,local+15,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1616;
	local[15]= makeflt(1.00000000e+00);
	local[16]= local[14];
	local[17]= local[12]->c.obj.iv[4];
	local[18]= fqv[78];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)VINNERPRODUCT(ctx,2,local+16); /*v.*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(*ftab[10])(ctx,2,local+15,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1616;
	goto IF1614;
OR1616:
	w = fqv[80];
	ctx->vsp=local+15;
	local[0]=w;
	goto BLK1542;
	goto IF1615;
IF1614:
	local[8] = fqv[81];
	local[15]= local[8];
IF1615:
	w = local[15];
	local[14]= w;
	goto IF1613;
IF1612:
	local[14]= NIL;
IF1613:
	goto IF1601;
IF1600:
	local[14]= NIL;
IF1601:
	goto CON1598;
CON1599:
	local[14]= local[10];
	local[15]= fqv[27];
	local[16]= local[12]->c.obj.iv[1];
	local[17]= local[12]->c.obj.iv[2];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,4,local+14); /*send*/
	local[6] = w;
	local[14]= local[6];
	if (loadglobal(fqv[83])==local[14]) goto IF1618;
	local[14]= makeflt(0.00000000e+00);
	local[15]= local[6];
	local[16]= makeflt(1.00000000e+00);
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(*ftab[11])(ctx,4,local+14,&ftab[11],fqv[84]); /*eps-in-range*/
	if (w==NIL) goto IF1618;
	local[14]= local[12];
	local[15]= fqv[85];
	local[16]= local[6];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[7] = w;
	local[14]= local[10];
	local[15]= fqv[82];
	local[16]= local[7];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[9] = w;
	local[14]= local[6];
	local[15]= makeflt(0.00000000e+00);
	local[16]= local[0];
	ctx->vsp=local+17;
	w=(*ftab[10])(ctx,3,local+14,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1622;
	local[14]= local[6];
	local[15]= makeflt(1.00000000e+00);
	local[16]= local[0];
	ctx->vsp=local+17;
	w=(*ftab[10])(ctx,3,local+14,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1622;
	goto CON1621;
OR1622:
	local[14]= local[9];
	local[15]= fqv[88];
	ctx->vsp=local+16;
	w=(*ftab[4])(ctx,2,local+14,&ftab[4],fqv[26]); /*member*/
	if (w==NIL) goto CON1621;
	local[8] = fqv[81];
	local[14]= local[8];
	goto CON1620;
CON1621:
	local[14]= local[9];
	local[15]= local[14];
	if (fqv[44]!=local[15]) goto IF1625;
	w = fqv[80];
	ctx->vsp=local+15;
	local[0]=w;
	goto BLK1542;
	goto IF1626;
IF1625:
	local[15]= local[14];
	if (fqv[87]!=local[15]) goto IF1627;
	local[8] = fqv[81];
	local[15]= local[8];
	goto IF1628;
IF1627:
	local[15]= NIL;
IF1628:
IF1626:
	w = local[15];
	local[14]= w;
	goto CON1620;
CON1623:
	local[14]= NIL;
CON1620:
	goto IF1619;
IF1618:
	local[14]= NIL;
IF1619:
	goto CON1598;
CON1617:
	local[14]= NIL;
CON1598:
	goto WHL1594;
WHX1595:
	local[14]= NIL;
BLK1596:
	w = NIL;
	goto WHL1589;
WHX1590:
	local[12]= NIL;
BLK1591:
	w = NIL;
	local[10]= local[8];
	goto IF1546;
IF1545:
	local[10]= NIL;
IF1546:
	w = local[10];
	local[0]= w;
BLK1542:
	ctx->vsp=local; return(local[0]);}

/*:insidep*/
static pointer M1629body_insidep(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1632;}
	local[0]= loadglobal(fqv[89]);
ENT1632:
ENT1631:
	if (n>4) maerror();
	if (argv[0]->c.obj.iv[14]!=NIL) goto IF1633;
	local[1]= argv[0]->c.obj.iv[8];
	local[2]= fqv[90];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	if (w!=NIL) goto IF1633;
	w = fqv[91];
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK1630;
	goto IF1634;
IF1633:
	local[1]= NIL;
IF1634:
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	if (argv[0]->c.obj.iv[13]==NIL) goto CON1636;
	local[5]= NIL;
	local[6]= argv[0]->c.obj.iv[9];
WHL1638:
	if (local[6]==NIL) goto WHX1639;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[5];
	local[8]= fqv[92];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[1] = w;
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)ABS(ctx,1,local+7); /*abs*/
	local[7]= w;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto CON1643;
	local[7]= local[5];
	local[8]= fqv[82];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[3] = w;
	local[7]= local[3];
	if (fqv[91]!=local[7]) goto IF1644;
	w = fqv[91];
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK1630;
	goto IF1645;
IF1644:
	w = fqv[87];
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK1630;
IF1645:
	goto CON1642;
CON1643:
	local[7]= local[1];
	local[8]= makeflt(0.00000000e+00);
	ctx->vsp=local+9;
	w=(pointer)GREATERP(ctx,2,local+7); /*>*/
	if (w==NIL) goto CON1646;
	w = fqv[91];
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK1630;
	goto CON1642;
CON1646:
	local[7]= NIL;
CON1642:
	goto WHL1638;
WHX1639:
	local[7]= NIL;
BLK1640:
	w = NIL;
	local[5]= fqv[44];
	goto CON1635;
CON1636:
	local[3] = NIL;
WHL1648:
	if (local[3]!=NIL) goto WHX1649;
	ctx->vsp=local+5;
	w=(*ftab[12])(ctx,0,local+5,&ftab[12],fqv[93]); /*random-normalized-vector*/
	local[2] = w;
	local[4] = makeint(0);
	local[5]= NIL;
	local[6]= argv[0]->c.obj.iv[9];
WHL1652:
	if (local[6]==NIL) goto WHX1653;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[5];
	local[8]= fqv[92];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)ABS(ctx,1,local+7); /*abs*/
	local[7]= w;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto IF1656;
	local[7]= local[5];
	local[8]= fqv[82];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	if (fqv[91]==local[7]) goto IF1656;
	w = fqv[87];
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK1630;
	goto IF1657;
IF1656:
	local[7]= NIL;
IF1657:
	local[7]= local[5];
	local[8]= fqv[43];
	local[9]= argv[2];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[3] = w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= local[7];
	if (fqv[44]!=local[8]) goto IF1659;
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[4] = w;
	local[8]= local[4];
	goto IF1660;
IF1659:
	local[8]= local[7];
	if (fqv[91]!=local[8]) goto IF1661;
	local[8]= NIL;
	goto IF1662;
IF1661:
	if (T==NIL) goto IF1663;
	local[3] = NIL;
	w = NIL;
	ctx->vsp=local+8;
	local[7]=w;
	goto BLK1654;
	goto IF1664;
IF1663:
	local[8]= NIL;
IF1664:
IF1662:
IF1660:
	w = local[8];
	goto WHL1652;
WHX1653:
	local[7]= NIL;
BLK1654:
	w = NIL;
	goto WHL1648;
WHX1649:
	local[5]= NIL;
BLK1650:
	if (argv[0]->c.obj.iv[14]!=NIL) goto IF1665;
	local[5]= local[4];
	ctx->vsp=local+6;
	w=(*ftab[13])(ctx,1,local+5,&ftab[13],fqv[94]); /*oddp*/
	if (w==NIL) goto IF1667;
	local[5]= fqv[44];
	goto IF1668;
IF1667:
	local[5]= fqv[91];
IF1668:
	goto IF1666;
IF1665:
	local[5]= local[4];
	ctx->vsp=local+6;
	w=(*ftab[13])(ctx,1,local+5,&ftab[13],fqv[94]); /*oddp*/
	if (w==NIL) goto IF1669;
	local[5]= fqv[91];
	goto IF1670;
IF1669:
	local[5]= fqv[44];
IF1670:
IF1666:
	goto CON1635;
CON1647:
	local[5]= NIL;
CON1635:
	w = local[5];
	local[0]= w;
BLK1630:
	ctx->vsp=local; return(local[0]);}

/*:evert*/
static pointer M1671body_evert(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[9];
	local[1]= fqv[95];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[15]); /*send-all*/
	local[0]= argv[0]->c.obj.iv[10];
	local[1]= fqv[95];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[15]); /*send-all*/
	argv[0]->c.obj.iv[14] = ((argv[0]->c.obj.iv[14])==NIL?T:NIL);
	if (argv[0]->c.obj.iv[14]==NIL) goto CON1674;
	local[0]= loadglobal(fqv[54]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[96];
	local[3]= makeflt(-1.00000000e+10);
	local[4]= makeflt(-1.00000000e+10);
	local[5]= makeflt(-1.00000000e+10);
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[3]= w;
	local[4]= makeflt(1.00000000e+10);
	local[5]= makeflt(1.00000000e+10);
	local[6]= makeflt(1.00000000e+10);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	argv[0]->c.obj.iv[8] = w;
	argv[0]->c.obj.iv[13] = NIL;
	local[0]= argv[0]->c.obj.iv[13];
	goto CON1673;
CON1674:
	local[0]= argv[0];
	local[1]= fqv[97];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[98];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto CON1673;
CON1676:
	local[0]= NIL;
CON1673:
	w = argv[0]->c.obj.iv[14];
	local[0]= w;
BLK1672:
	ctx->vsp=local; return(local[0]);}

/*:set-convexp*/
static pointer M1677body_set_convexp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO1681,env,argv,local);
	local[1]= argv[0]->c.obj.iv[10];
	local[2]= fqv[99];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[15]); /*send-all*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[14])(ctx,2,local+0,&ftab[14],fqv[100]); /*every*/
	if (w==NIL) goto IF1679;
	argv[0]->c.obj.iv[13] = T;
	local[0]= argv[0]->c.obj.iv[13];
	goto IF1680;
IF1679:
	local[0]= NIL;
IF1680:
	local[0]= argv[0]->c.obj.iv[9];
	local[1]= fqv[98];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[15]); /*send-all*/
	w = argv[0];
	local[0]= w;
BLK1678:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1510(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[101];
	local[2]= env->c.clo.env1[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (w==NIL) goto IF1682;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF1683;
IF1682:
	local[0]= NIL;
IF1683:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1513(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[101];
	local[2]= env->c.clo.env1[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (w==NIL) goto IF1684;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF1685;
IF1684:
	local[0]= NIL;
IF1685:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1681(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeflt(0.00000000e+00);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:get-face*/
static pointer M1686body_get_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1691;}
	local[0]= NIL;
ENT1691:
	if (n>=4) { local[1]=(argv[3]); goto ENT1690;}
	local[1]= NIL;
ENT1690:
	if (n>=5) { local[2]=(argv[4]); goto ENT1689;}
	local[2]= NIL;
ENT1689:
ENT1688:
	if (n>5) maerror();
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(*ftab[15])(ctx,1,local+7,&ftab[15],fqv[102]); /*bodyp*/
	if (w==NIL) goto CON1693;
	local[7]= NIL;
	local[8]= argv[0]->c.obj.iv[9];
WHL1695:
	if (local[8]==NIL) goto WHX1696;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[7];
	local[10]= fqv[103];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	if (local[0]!=local[9]) goto IF1699;
	local[9]= local[7];
	w = local[3];
	ctx->vsp=local+10;
	local[3] = cons(ctx,local[9],w);
	local[9]= local[3];
	goto IF1700;
IF1699:
	local[9]= NIL;
IF1700:
	goto WHL1695;
WHX1696:
	local[9]= NIL;
BLK1697:
	w = NIL;
	local[7]= w;
	goto CON1692;
CON1693:
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(*ftab[16])(ctx,1,local+7,&ftab[16],fqv[104]); /*keywordp*/
	if (w==NIL) goto CON1701;
	local[7]= NIL;
	local[8]= argv[0]->c.obj.iv[9];
WHL1703:
	if (local[8]==NIL) goto WHX1704;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[7];
	local[10]= fqv[105];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	if (local[0]!=local[9]) goto IF1707;
	local[9]= local[7];
	w = local[3];
	ctx->vsp=local+10;
	local[3] = cons(ctx,local[9],w);
	local[9]= local[3];
	goto IF1708;
IF1707:
	local[9]= NIL;
IF1708:
	goto WHL1703;
WHX1704:
	local[9]= NIL;
BLK1705:
	w = NIL;
	local[7]= w;
	goto CON1692;
CON1701:
	local[7]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+8;
	w=(pointer)COPYSEQ(ctx,1,local+7); /*copy-seq*/
	local[3] = w;
	local[7]= local[3];
	goto CON1692;
CON1709:
	local[7]= NIL;
CON1692:
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[17])(ctx,1,local+7,&ftab[17],fqv[106]); /*facep*/
	if (w==NIL) goto CON1711;
	local[7]= NIL;
	local[8]= local[3];
WHL1713:
	if (local[8]==NIL) goto WHX1714;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[7];
	local[10]= fqv[107];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	if (local[1]!=local[9]) goto IF1717;
	local[9]= local[7];
	w = local[4];
	ctx->vsp=local+10;
	local[4] = cons(ctx,local[9],w);
	local[9]= local[4];
	goto IF1718;
IF1717:
	local[9]= NIL;
IF1718:
	goto WHL1713;
WHX1714:
	local[9]= NIL;
BLK1715:
	w = NIL;
	local[7]= w;
	goto CON1710;
CON1711:
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[16])(ctx,1,local+7,&ftab[16],fqv[104]); /*keywordp*/
	if (w==NIL) goto CON1719;
	local[7]= NIL;
	local[8]= local[3];
WHL1721:
	if (local[8]==NIL) goto WHX1722;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[7];
	local[10]= fqv[108];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.car;
	local[9]= local[6];
	if (local[1]==local[9]) goto OR1727;
	local[9]= local[1];
	if (fqv[109]!=local[9]) goto AND1728;
	local[9]= local[6];
	local[10]= fqv[110];
	ctx->vsp=local+11;
	w=(*ftab[4])(ctx,2,local+9,&ftab[4],fqv[26]); /*member*/
	if (w==NIL) goto AND1728;
	goto OR1727;
AND1728:
	goto IF1725;
OR1727:
	local[9]= local[7];
	w = local[4];
	ctx->vsp=local+10;
	local[4] = cons(ctx,local[9],w);
	local[9]= local[4];
	goto IF1726;
IF1725:
	local[9]= NIL;
IF1726:
	goto WHL1721;
WHX1722:
	local[9]= NIL;
BLK1723:
	w = NIL;
	local[7]= w;
	goto CON1710;
CON1719:
	local[4] = local[3];
	local[7]= local[4];
	goto CON1710;
CON1729:
	local[7]= NIL;
CON1710:
	if (local[2]==NIL) goto CON1731;
	local[7]= NIL;
	local[8]= local[4];
WHL1733:
	if (local[8]==NIL) goto WHX1734;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[7];
	local[10]= fqv[108];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	if (local[2]!=local[9]) goto IF1737;
	local[9]= local[7];
	w = local[5];
	ctx->vsp=local+10;
	local[5] = cons(ctx,local[9],w);
	local[9]= local[5];
	goto IF1738;
IF1737:
	local[9]= NIL;
IF1738:
	goto WHL1733;
WHX1734:
	local[9]= NIL;
BLK1735:
	w = NIL;
	local[7]= local[5];
	goto CON1730;
CON1731:
	local[7]= local[4];
	goto CON1730;
CON1739:
	local[7]= NIL;
CON1730:
	w = local[7];
	local[0]= w;
BLK1687:
	ctx->vsp=local; return(local[0]);}

/*:primitive-body-p*/
static pointer M1740body_primitive_body_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= (iscons(w)?T:NIL);
	if (local[0]==NIL) goto AND1742;
	w=argv[0]->c.obj.iv[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	w=(*ftab[16])(ctx,1,local+0,&ftab[16],fqv[104]); /*keywordp*/
	local[0]= w;
AND1742:
	w = local[0];
	local[0]= w;
BLK1741:
	ctx->vsp=local; return(local[0]);}

/*:primitive-bodies*/
static pointer M1743body_primitive_bodies(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1747;}
	local[0]= NIL;
ENT1747:
	if (n>=4) { local[1]=(argv[3]); goto ENT1746;}
	local[1]= NIL;
ENT1746:
ENT1745:
	if (n>4) maerror();
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,FLET1748,env,argv,local);
	local[3]= NIL;
	local[4]= local[0];
	local[5]= local[4];
	if (fqv[111]!=local[5]) goto IF1750;
	local[5]= argv[0];
	local[6]= fqv[112];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	local[5]= local[3];
	goto IF1751;
IF1750:
	local[5]= local[4];
	if (fqv[113]!=local[5]) goto IF1752;
	local[5]= argv[0];
	local[6]= fqv[112];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	local[5]= local[3];
	goto IF1753;
IF1752:
	if (T==NIL) goto IF1754;
	local[5]= argv[0];
	w = local[2];
	ctx->vsp=local+6;
	w=FLET1748(ctx,1,local+5,w);
	local[3] = w;
	local[5]= local[3];
	goto IF1755;
IF1754:
	local[5]= NIL;
IF1755:
IF1753:
IF1751:
	w = local[5];
	if (local[1]==NIL) goto CON1757;
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO1758,env,argv,local);
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(*ftab[18])(ctx,2,local+4,&ftab[18],fqv[114]); /*collect-if*/
	local[4]= w;
	goto CON1756;
CON1757:
	local[4]= local[3];
	goto CON1756;
CON1759:
	local[4]= NIL;
CON1756:
	w = local[4];
	local[0]= w;
BLK1744:
	ctx->vsp=local; return(local[0]);}

/*:csg*/
static pointer M1760body_csg(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1763;}
	local[0]= NIL;
ENT1763:
ENT1762:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1764;
	argv[0]->c.obj.iv[15] = local[0];
	local[1]= argv[0]->c.obj.iv[15];
	goto IF1765;
IF1764:
	local[1]= argv[0]->c.obj.iv[15];
IF1765:
	w = local[1];
	local[0]= w;
BLK1761:
	ctx->vsp=local; return(local[0]);}

/*:copy-csg*/
static pointer M1766body_copy_csg(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,FLET1768,env,argv,local);
	local[1]= argv[0];
	local[2]= fqv[115];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (w==NIL) goto IF1769;
	local[1]= argv[0];
	w = local[0];
	ctx->vsp=local+2;
	w=FLET1768(ctx,1,local+1,w);
	local[1]= w;
	goto IF1770;
IF1769:
	local[1]= argv[0]->c.obj.iv[15];
	w = local[0];
	ctx->vsp=local+2;
	w=FLET1768(ctx,1,local+1,w);
	local[1]= w;
IF1770:
	w = local[1];
	local[0]= w;
BLK1767:
	ctx->vsp=local; return(local[0]);}

/*:body-type*/
static pointer M1771body_body_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= fqv[116];
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[26]); /*member*/
	if (w==NIL) goto IF1773;
	local[0]= fqv[117];
	w=argv[0]->c.obj.iv[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	goto IF1774;
IF1773:
	w=argv[0]->c.obj.iv[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
IF1774:
	w = local[0];
	local[0]= w;
BLK1772:
	ctx->vsp=local; return(local[0]);}

/*:creation-form*/
static pointer M1775body_creation_form(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,FLET1777,env,argv,local);
	local[1]= argv[0];
	local[2]= fqv[115];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (w==NIL) goto IF1778;
	local[1]= argv[0];
	w = local[0];
	ctx->vsp=local+2;
	w=FLET1777(ctx,1,local+1,w);
	local[1]= w;
	goto IF1779;
IF1778:
	local[1]= argv[0]->c.obj.iv[15];
	w = local[0];
	ctx->vsp=local+2;
	w=FLET1777(ctx,1,local+1,w);
	local[1]= w;
IF1779:
	w = local[1];
	local[0]= w;
BLK1776:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M1780body_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[53]));
	local[2]= fqv[118];
	local[3]= argv[2];
	local[4]= argv[0];
	local[5]= fqv[119];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,5,local+0); /*send-message*/
	local[0]= w;
BLK1781:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1782body_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1784:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[120], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY1785;
	local[1] = NIL;
KEY1785:
	if (n & (1<<1)) goto KEY1786;
	local[2] = NIL;
KEY1786:
	if (n & (1<<2)) goto KEY1787;
	local[3] = NIL;
KEY1787:
	local[4]= (pointer)get_sym_func(fqv[52]);
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[53]));
	local[7]= fqv[32];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,5,local+4); /*apply*/
	local[4]= argv[0]->c.obj.iv[10];
	local[5]= fqv[121];
	ctx->vsp=local+6;
	w=(*ftab[1])(ctx,2,local+4,&ftab[1],fqv[15]); /*send-all*/
	if (local[1]==NIL) goto IF1788;
	local[4]= argv[0]->c.obj.iv[10];
	local[5]= fqv[122];
	ctx->vsp=local+6;
	w=(*ftab[1])(ctx,2,local+4,&ftab[1],fqv[15]); /*send-all*/
	local[4]= w;
	goto IF1789;
IF1788:
	local[4]= NIL;
IF1789:
	local[4]= (pointer)get_sym_func(fqv[123]);
	local[5]= argv[0]->c.obj.iv[10];
	local[6]= fqv[99];
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,2,local+5,&ftab[1],fqv[15]); /*send-all*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[14])(ctx,2,local+4,&ftab[14],fqv[100]); /*every*/
	if (w==NIL) goto IF1790;
	argv[0]->c.obj.iv[13] = T;
	local[4]= argv[0]->c.obj.iv[13];
	goto IF1791;
IF1790:
	local[4]= NIL;
IF1791:
	if (argv[0]->c.obj.iv[11]==NIL) goto IF1792;
	if (argv[0]->c.obj.iv[9]==NIL) goto IF1792;
	local[4]= argv[0];
	local[5]= argv[0];
	local[6]= fqv[63];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= fqv[63];
	ctx->vsp=local+7;
	w=(pointer)PUTPROP(ctx,3,local+4); /*putprop*/
	local[4]= argv[0];
	local[5]= argv[0];
	local[6]= fqv[62];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= fqv[62];
	ctx->vsp=local+7;
	w=(pointer)PUTPROP(ctx,3,local+4); /*putprop*/
	local[4]= w;
	goto IF1793;
IF1792:
	local[4]= NIL;
IF1793:
	if (local[2]==NIL) goto IF1794;
	local[4]= argv[0]->c.obj.iv[9];
	local[5]= fqv[124];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,3,local+4,&ftab[1],fqv[15]); /*send-all*/
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	argv[0]->c.obj.iv[15] = w;
	local[4]= argv[0]->c.obj.iv[15];
	goto IF1795;
IF1794:
	local[4]= NIL;
IF1795:
	w = argv[0];
	local[0]= w;
BLK1783:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET1748(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[19])(ctx,1,local+0,&ftab[19],fqv[125]); /*primitive-body-p*/
	if (w==NIL) goto CON1797;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto CON1796;
CON1797:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON1798;
	local[0]= env->c.clo.env2[2];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LISTP(ctx,1,local+1); /*listp*/
	if (w==NIL) goto CON1800;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	goto CON1799;
CON1800:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	goto CON1799;
CON1801:
	local[1]= NIL;
CON1799:
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
	goto CON1796;
CON1798:
	local[0]= env->c.clo.env2[2];
	local[1]= argv[0];
	local[2]= fqv[126];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
	goto CON1796;
CON1802:
	local[0]= NIL;
CON1796:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1758(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[119];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w = env->c.clo.env2[1];
	if (!iscons(w)) goto IF1803;
	local[2]= local[1];
	local[3]= env->c.clo.env2[1];
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,2,local+2,&ftab[4],fqv[26]); /*member*/
	local[2]= w;
	goto IF1804;
IF1803:
	local[2]= env->c.clo.env2[1];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)EQ(ctx,2,local+2); /*eql*/
	local[2]= w;
IF1804:
	w = local[2];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET1768(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON1806;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO1807,env,argv,local);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	goto CON1805;
CON1806:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[15])(ctx,1,local+0,&ftab[15],fqv[102]); /*bodyp*/
	if (w==NIL) goto CON1808;
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	local[4]= fqv[65];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= argv[0];
	local[4]= fqv[127];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[1] = w;
	if (local[1]==NIL) goto IF1809;
	local[3]= local[1];
	local[4]= fqv[128];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF1810;
IF1809:
	local[3]= NIL;
IF1810:
	local[3]= argv[0];
	local[4]= fqv[129];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[130];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)COPYOBJ(ctx,1,local+3); /*copy-object*/
	local[0] = w;
	if (local[1]==NIL) goto IF1811;
	local[3]= local[1];
	local[4]= fqv[131];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF1812;
IF1811:
	local[3]= NIL;
IF1812:
	local[3]= NIL;
	local[4]= local[2];
WHL1814:
	if (local[4]==NIL) goto WHX1815;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= argv[0];
	local[6]= fqv[131];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	goto WHL1814;
WHX1815:
	local[5]= NIL;
BLK1816:
	w = NIL;
	local[3]= local[0];
	local[4]= fqv[65];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= NIL;
	local[4]= local[0]->c.obj.iv[9];
WHL1819:
	if (local[4]==NIL) goto WHX1820;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3];
	local[6]= fqv[107];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	goto WHL1819;
WHX1820:
	local[5]= NIL;
BLK1821:
	w = NIL;
	local[3]= local[0];
	local[4]= argv[0];
	local[5]= fqv[132];
	ctx->vsp=local+6;
	w=(pointer)PUTPROP(ctx,3,local+3); /*putprop*/
	w = local[0];
	local[0]= w;
	goto CON1805;
CON1808:
	local[0]= NIL;
CON1805:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1807(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = env->c.clo.env0->c.clo.env2[0];
	ctx->vsp=local+1;
	w=FLET1768(ctx,1,local+0,w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET1777(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON1824;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[59]!=local[0]) goto CON1826;
	local[0]= fqv[133];
	local[1]= env->c.clo.env2[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LIST_STAR(ctx,2,local+0); /*list**/
	local[0]= w;
	goto CON1825;
CON1826:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[134]!=local[0]) goto CON1827;
	local[0]= fqv[135];
	local[1]= env->c.clo.env2[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LIST_STAR(ctx,2,local+0); /*list**/
	local[0]= w;
	goto CON1825;
CON1827:
	local[0]= NIL;
CON1825:
	goto CON1823;
CON1824:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[15])(ctx,1,local+0,&ftab[15],fqv[102]); /*bodyp*/
	if (w==NIL) goto CON1828;
	local[0]= argv[0];
	local[1]= fqv[126];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= local[1];
	if (fqv[136]!=local[2]) goto IF1830;
	local[2]= fqv[137];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	goto IF1831;
IF1830:
	local[2]= local[1];
	if (fqv[138]!=local[2]) goto IF1832;
	local[2]= fqv[139];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= fqv[140];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[20])(ctx,1,local+6,&ftab[20],fqv[141]); /*cdddr*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST_STAR(ctx,5,local+2); /*list**/
	local[2]= w;
	goto IF1833;
IF1832:
	if (T==NIL) goto IF1834;
	local[2]= fqv[142];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,2,local+2); /*error*/
	local[2]= w;
	goto IF1835;
IF1834:
	local[2]= NIL;
IF1835:
IF1833:
IF1831:
	w = local[2];
	local[0] = w;
	local[1]= local[0];
	local[2]= fqv[3];
	local[3]= argv[0];
	local[4]= fqv[3];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPEND(ctx,2,local+1); /*append*/
	local[1]= fqv[8];
	local[2]= local[0];
	local[3]= fqv[143];
	local[4]= argv[0];
	local[5]= fqv[65];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= fqv[144];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
	goto CON1823;
CON1828:
	local[0]= NIL;
CON1823:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:replace-shape*/
static pointer M1836body_replace_shape(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[4];
WHL1839:
	if (local[1]==NIL) goto WHX1840;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= fqv[132];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	if (w==NIL) goto IF1843;
	local[2]= argv[0];
	local[3]= fqv[128];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF1844;
IF1843:
	local[2]= NIL;
IF1844:
	goto WHL1839;
WHX1840:
	local[2]= NIL;
BLK1841:
	w = NIL;
	argv[0]->c.obj.iv[9] = argv[2]->c.obj.iv[9];
	argv[0]->c.obj.iv[10] = argv[2]->c.obj.iv[10];
	argv[0]->c.obj.iv[11] = argv[2]->c.obj.iv[11];
	argv[0]->c.obj.iv[12] = argv[2]->c.obj.iv[12];
	argv[0]->c.obj.iv[8] = argv[2]->c.obj.iv[8];
	argv[0]->c.obj.iv[13] = argv[2]->c.obj.iv[13];
	argv[0]->c.obj.iv[15] = argv[2]->c.obj.iv[15];
	local[0]= argv[0];
	local[1]= NIL;
	local[2]= fqv[6];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= argv[0];
	local[1]= fqv[65];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[145];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[12];
WHL1845:
	if (local[1]==NIL) goto WHX1846;
	local[2]= local[1];
	local[3]= local[0];
	local[4]= fqv[66];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)RPLACA2(ctx,2,local+2); /*rplaca2*/
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	goto WHL1845;
WHX1846:
	local[2]= NIL;
BLK1847:
	w = local[2];
	local[0]= argv[0]->c.obj.iv[9];
	local[1]= fqv[124];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,3,local+0,&ftab[1],fqv[15]); /*send-all*/
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[146];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
WHL1849:
	if (local[1]==NIL) goto WHX1850;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0];
	local[3]= fqv[131];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	goto WHL1849;
WHX1850:
	local[2]= NIL;
BLK1851:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK1837:
	ctx->vsp=local; return(local[0]);}

/*:+*/
static pointer M1853body__(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1855:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0];
	local[2]= fqv[147];
	local[3]= (pointer)get_sym_func(fqv[133]);
	local[4]= argv[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,3,local+3); /*apply*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK1854:
	ctx->vsp=local; return(local[0]);}

/*:-*/
static pointer M1856body__(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1858:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0];
	local[2]= fqv[147];
	local[3]= (pointer)get_sym_func(fqv[135]);
	local[4]= argv[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,3,local+3); /*apply*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK1857:
	ctx->vsp=local; return(local[0]);}

/*:**/
static pointer M1859body__(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1861:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0];
	local[2]= fqv[147];
	local[3]= (pointer)get_sym_func(fqv[148]);
	local[4]= argv[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,3,local+3); /*apply*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK1860:
	ctx->vsp=local; return(local[0]);}

/*:primitive-groups*/
static pointer M1862body_primitive_groups(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,FLET1864,env,argv,local);
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,FLET1865,env,argv,local);
	local[2]= argv[0];
	local[3]= fqv[115];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	if (w==NIL) goto IF1866;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	goto IF1867;
IF1866:
	local[2]= argv[0]->c.obj.iv[15];
	w = local[0];
	ctx->vsp=local+3;
	w=FLET1864(ctx,1,local+2,w);
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[15];
	w = local[1];
	ctx->vsp=local+4;
	w=FLET1865(ctx,1,local+3,w);
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
IF1867:
	w = local[2];
	local[0]= w;
BLK1863:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET1864(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON1869;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[59]!=local[0]) goto CON1871;
	local[0]= env->c.clo.env2[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
	goto CON1870;
CON1871:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[134]!=local[0]) goto CON1872;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[21])(ctx,1,local+0,&ftab[21],fqv[149]); /*caadr*/
	local[0]= w;
	w = env->c.clo.env2[0];
	ctx->vsp=local+1;
	w=FLET1864(ctx,1,local+0,w);
	local[0]= w;
	local[1]= env->c.clo.env2[1];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[22])(ctx,1,local+2,&ftab[22],fqv[150]); /*cdadr*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAPCAN(ctx,2,local+1); /*mapcan*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	local[0]= w;
	goto CON1870;
CON1872:
	local[0]= NIL;
CON1870:
	goto CON1868;
CON1869:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[19])(ctx,1,local+0,&ftab[19],fqv[125]); /*primitive-body-p*/
	if (w==NIL) goto CON1873;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto CON1868;
CON1873:
	local[0]= NIL;
CON1868:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET1865(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto IF1874;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[59]!=local[0]) goto CON1877;
	local[0]= env->c.clo.env2[1];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
	goto CON1876;
CON1877:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[134]!=local[0]) goto CON1878;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[21])(ctx,1,local+0,&ftab[21],fqv[149]); /*caadr*/
	local[0]= w;
	w = env->c.clo.env2[1];
	ctx->vsp=local+1;
	w=FLET1865(ctx,1,local+0,w);
	local[0]= w;
	local[1]= env->c.clo.env2[0];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[22])(ctx,1,local+2,&ftab[22],fqv[150]); /*cdadr*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAPCAN(ctx,2,local+1); /*mapcan*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	local[0]= w;
	goto CON1876;
CON1878:
	local[0]= NIL;
CON1876:
	goto IF1875;
IF1874:
	local[0]= NIL;
IF1875:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:constraint*/
static pointer M1879body_constraint(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[27];
	local[4]= argv[2];
	local[5]= fqv[28];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	if (w==NIL) goto IF1881;
	local[2]= argv[0];
	local[3]= fqv[151];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[152];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)NCONC(ctx,2,local+2); /*nconc*/
	local[0] = w;
	local[2]= argv[2];
	local[3]= fqv[151];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[2];
	local[4]= fqv[152];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)NCONC(ctx,2,local+2); /*nconc*/
	local[1] = w;
	local[2]= loadglobal(fqv[153]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[32];
	local[5]= fqv[154];
	local[6]= argv[0];
	local[7]= fqv[155];
	local[8]= argv[2];
	local[9]= fqv[156];
	local[10]= local[0];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(*ftab[23])(ctx,2,local+10,&ftab[23],fqv[157]); /*contact-to-constraint*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,8,local+3); /*send*/
	w = local[2];
	local[2]= w;
	goto IF1882;
IF1881:
	local[2]= NIL;
IF1882:
	w = local[2];
	local[0]= w;
BLK1880:
	ctx->vsp=local; return(local[0]);}

/*:contact-vertices*/
static pointer M1884body_contact_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= fqv[27];
	local[2]= argv[2];
	local[3]= fqv[28];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	if (local[0]==NIL) goto IF1886;
	local[1]= argv[0];
	local[2]= fqv[158];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= fqv[159];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[1];
WHL1889:
	if (local[7]==NIL) goto WHX1890;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= NIL;
	local[9]= local[2];
WHL1894:
	if (local[9]==NIL) goto WHX1895;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= local[8];
	local[11]= fqv[160];
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	if (fqv[91]==local[10]) goto IF1898;
	local[10]= loadglobal(fqv[161]);
	ctx->vsp=local+11;
	w=(pointer)INSTANTIATE(ctx,1,local+10); /*instantiate*/
	local[10]= w;
	local[11]= local[10];
	local[12]= fqv[32];
	local[13]= fqv[162];
	local[14]= local[6];
	local[15]= fqv[163];
	local[16]= local[8];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,6,local+11); /*send*/
	w = local[10];
	local[10]= w;
	w = local[3];
	ctx->vsp=local+11;
	local[3] = cons(ctx,local[10],w);
	w = local[3];
	ctx->vsp=local+10;
	local[10]=w;
	goto BLK1896;
	goto IF1899;
IF1898:
	local[10]= NIL;
IF1899:
	goto WHL1894;
WHX1895:
	local[10]= NIL;
BLK1896:
	w = NIL;
	goto WHL1889;
WHX1890:
	local[8]= NIL;
BLK1891:
	w = NIL;
	local[6]= NIL;
	local[7]= local[3];
WHL1902:
	if (local[7]==NIL) goto WHX1903;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= NIL;
	local[9]= argv[0]->c.obj.iv[10];
WHL1907:
	if (local[9]==NIL) goto WHX1908;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= local[6]->c.obj.iv[0];
	local[11]= local[8]->c.obj.iv[1];
	ctx->vsp=local+12;
	w=(pointer)EQUAL(ctx,2,local+10); /*equal*/
	if (w!=NIL) goto OR1913;
	local[10]= local[6]->c.obj.iv[0];
	local[11]= local[8]->c.obj.iv[2];
	ctx->vsp=local+12;
	w=(pointer)EQUAL(ctx,2,local+10); /*equal*/
	if (w!=NIL) goto OR1913;
	goto IF1911;
OR1913:
	local[10]= local[8];
	w = local[6]->c.obj.iv[3];
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= local[10];
	w = local[6];
	w->c.obj.iv[3] = local[11];
	goto IF1912;
IF1911:
	local[10]= NIL;
IF1912:
	goto WHL1907;
WHX1908:
	local[10]= NIL;
BLK1909:
	w = NIL;
	goto WHL1902;
WHX1903:
	local[8]= NIL;
BLK1904:
	w = NIL;
	local[6]= NIL;
	local[7]= local[3];
WHL1915:
	if (local[7]==NIL) goto WHX1916;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	local[9]= fqv[164];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	goto WHL1915;
WHX1916:
	local[8]= NIL;
BLK1917:
	w = NIL;
	w = local[3];
	local[1]= w;
	goto IF1887;
IF1886:
	local[1]= NIL;
IF1887:
	w = local[1];
	local[0]= w;
BLK1885:
	ctx->vsp=local; return(local[0]);}

/*:contact-edges*/
static pointer M1919body_contact_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= fqv[27];
	local[2]= argv[2];
	local[3]= fqv[28];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	if (local[0]==NIL) goto IF1921;
	local[1]= argv[0];
	local[2]= fqv[165];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= fqv[159];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[1];
WHL1924:
	if (local[7]==NIL) goto WHX1925;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= NIL;
	local[9]= local[2];
WHL1929:
	if (local[9]==NIL) goto WHX1930;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= local[8];
	local[11]= fqv[166];
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[3] = w;
	if (local[3]==NIL) goto IF1933;
	local[10]= local[3];
	local[11]= local[4];
	local[12]= fqv[167];
	ctx->vsp=local+13;
	local[13]= makeclosure(codevec,quotevec,CLO1935,env,argv,local);
	ctx->vsp=local+14;
	w=(*ftab[24])(ctx,4,local+10,&ftab[24],fqv[168]); /*find*/
	if (w!=NIL) goto IF1933;
	local[10]= local[6]->c.obj.iv[5];
	ctx->vsp=local+11;
	w=(*ftab[25])(ctx,1,local+10,&ftab[25],fqv[123]); /*plusp*/
	if (w==NIL) goto IF1936;
	local[10]= loadglobal(fqv[161]);
	ctx->vsp=local+11;
	w=(pointer)INSTANTIATE(ctx,1,local+10); /*instantiate*/
	local[10]= w;
	local[11]= local[10];
	local[12]= fqv[32];
	local[13]= fqv[162];
	local[14]= local[3];
	local[15]= fqv[163];
	local[16]= local[8];
	local[17]= fqv[169];
	local[18]= local[6];
	ctx->vsp=local+19;
	w=(pointer)LIST(ctx,1,local+18); /*list*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)LIST(ctx,1,local+18); /*list*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,8,local+11); /*send*/
	w = local[10];
	local[10]= w;
	w = local[4];
	ctx->vsp=local+11;
	local[4] = cons(ctx,local[10],w);
	local[10]= local[4];
	goto IF1937;
IF1936:
	local[10]= loadglobal(fqv[161]);
	ctx->vsp=local+11;
	w=(pointer)INSTANTIATE(ctx,1,local+10); /*instantiate*/
	local[10]= w;
	local[11]= local[10];
	local[12]= fqv[32];
	local[13]= fqv[162];
	local[14]= local[3];
	local[15]= fqv[163];
	local[16]= local[8];
	local[17]= fqv[169];
	local[18]= local[6]->c.obj.iv[3];
	ctx->vsp=local+19;
	w=(pointer)LIST(ctx,1,local+18); /*list*/
	local[18]= w;
	local[19]= local[6]->c.obj.iv[4];
	ctx->vsp=local+20;
	w=(pointer)LIST(ctx,1,local+19); /*list*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)LIST(ctx,2,local+18); /*list*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,8,local+11); /*send*/
	w = local[10];
	local[10]= w;
	w = local[4];
	ctx->vsp=local+11;
	local[4] = cons(ctx,local[10],w);
	local[10]= local[4];
IF1937:
	goto IF1934;
IF1933:
	local[10]= NIL;
IF1934:
	goto WHL1929;
WHX1930:
	local[10]= NIL;
BLK1931:
	w = NIL;
	goto WHL1924;
WHX1925:
	local[8]= NIL;
BLK1926:
	w = NIL;
	w = local[4];
	local[1]= w;
	goto IF1922;
IF1921:
	local[1]= NIL;
IF1922:
	w = local[1];
	local[0]= w;
BLK1920:
	ctx->vsp=local; return(local[0]);}

/*:possibly-contacting-vertices*/
static pointer M1940body_possibly_contacting_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO1942,env,argv,local);
	local[1]= argv[0]->c.obj.iv[11];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
BLK1941:
	ctx->vsp=local; return(local[0]);}

/*:possibly-contacting-edges*/
static pointer M1943body_possibly_contacting_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO1945,env,argv,local);
	local[1]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
BLK1944:
	ctx->vsp=local; return(local[0]);}

/*:possibly-contacting-faces*/
static pointer M1946body_possibly_contacting_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO1948,env,argv,local);
	local[1]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
BLK1947:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1935(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1]->c.obj.iv[0];
	local[2]= loadglobal(fqv[29]);
	ctx->vsp=local+3;
	w=(*ftab[26])(ctx,3,local+0,&ftab[26],fqv[170]); /*eps-v=*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1942(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[2];
	local[1]= fqv[90];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (w==NIL) goto IF1949;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF1950;
IF1949:
	local[0]= NIL;
IF1950:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1945(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[101];
	local[2]= env->c.clo.env1[2];
	local[3]= loadglobal(fqv[29]);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	if (w==NIL) goto IF1951;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF1952;
IF1951:
	local[0]= NIL;
IF1952:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1948(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[101];
	local[2]= env->c.clo.env1[2];
	local[3]= loadglobal(fqv[29]);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	if (w==NIL) goto IF1953;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF1954;
IF1953:
	local[0]= NIL;
IF1954:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:radius*/
static pointer M1957sphere_radius(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1960;}
	local[0]= NIL;
ENT1960:
ENT1959:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1961;
	argv[0]->c.obj.iv[8] = local[0];
	local[1]= argv[0]->c.obj.iv[8];
	goto IF1962;
IF1961:
	local[1]= NIL;
IF1962:
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK1958:
	ctx->vsp=local; return(local[0]);}

/*:inner*/
static pointer M1963sphere_inner(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)VDISTANCE(ctx,2,local+0); /*distance*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	local[0]= w;
BLK1964:
	ctx->vsp=local; return(local[0]);}

/*:volume*/
static pointer M1965sphere_volume(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeflt(4.00000000e+00);
	local[1]= makeflt(3.14159265e+00);
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= argv[0]->c.obj.iv[8];
	local[4]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,5,local+0); /***/
	local[0]= w;
	local[1]= makeint(3);
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
BLK1966:
	ctx->vsp=local; return(local[0]);}

/*:intersect-line*/
static pointer M1967sphere_intersect_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[171];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= local[0];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)VMINUS(ctx,2,local+3); /*v-*/
	local[3]= w;
	local[4]= local[1];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)VINNERPRODUCT(ctx,2,local+4); /*v.*/
	local[4]= w;
	local[5]= local[1];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)VINNERPRODUCT(ctx,2,local+5); /*v.*/
	local[5]= w;
	local[6]= local[3];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)VINNERPRODUCT(ctx,2,local+6); /*v.*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[8];
	local[8]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	local[7]= local[5];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	local[8]= local[4];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,1,local+8); /*-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	local[8]= local[7];
	local[9]= makeflt(0.00000000e+00);
	ctx->vsp=local+10;
	w=(pointer)LESSP(ctx,2,local+8); /*<*/
	if (w==NIL) goto IF1969;
	local[8]= NIL;
	goto IF1970;
IF1969:
	local[8]= local[5];
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)SQRT(ctx,1,local+9); /*sqrt*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	local[9]= argv[2];
	local[10]= argv[3];
	ctx->vsp=local+11;
	w=(*ftab[27])(ctx,3,local+8,&ftab[27],fqv[172]); /*midpoint*/
	local[8]= w;
	local[9]= local[5];
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)SQRT(ctx,1,local+10); /*sqrt*/
	local[10]= makeflt(-(fltval(w)));
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	local[10]= argv[2];
	local[11]= argv[3];
	ctx->vsp=local+12;
	w=(*ftab[27])(ctx,3,local+9,&ftab[27],fqv[172]); /*midpoint*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,2,local+8); /*list*/
	local[8]= w;
IF1970:
	w = local[8];
	local[0]= w;
BLK1968:
	ctx->vsp=local; return(local[0]);}

/*:closest-point*/
static pointer M1971sphere_closest_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[171];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[8];
	local[2]= argv[2];
	local[3]= argv[0];
	local[4]= fqv[171];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)VMINUS(ctx,2,local+2); /*v-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VNORMALIZE(ctx,1,local+2); /*normalize-vector*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,2,local+1); /*scale*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VPLUS(ctx,2,local+0); /*v+*/
	local[0]= w;
BLK1972:
	ctx->vsp=local; return(local[0]);}

/*:intersect-with-body*/
static pointer M1973sphere_intersect_with_body(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[2];
	local[2]= fqv[173];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
WHL1976:
	if (local[1]==NIL) goto WHX1977;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)VDISTANCE(ctx,2,local+2); /*distance*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto IF1980;
	w = T;
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK1974;
	goto IF1981;
IF1980:
	local[2]= NIL;
IF1981:
	goto WHL1976;
WHX1977:
	local[2]= NIL;
BLK1978:
	w = NIL;
	w = NIL;
	local[0]= w;
BLK1974:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1982sphere_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[174], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY1984;
	local[2]= makeint(0);
	local[3]= makeint(0);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[0] = w;
KEY1984:
	if (n & (1<<1)) goto KEY1985;
	local[1] = makeflt(1.00000000e+00);
KEY1985:
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[53]));
	local[4]= fqv[32];
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,3,local+2); /*send-message*/
	argv[0]->c.obj.iv[2] = local[0];
	argv[0]->c.obj.iv[8] = local[1];
	w = argv[0];
	local[0]= w;
BLK1983:
	ctx->vsp=local; return(local[0]);}

/*add-wings*/
static pointer F1252add_wings(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[0]->c.obj.iv[10];
WHL1988:
	if (local[5]==NIL) goto WHX1989;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= loadglobal(fqv[175]);
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,1,local+6); /*instantiate*/
	local[6]= w;
	local[7]= local[6];
	local[8]= fqv[32];
	local[9]= fqv[176];
	local[10]= local[4]->c.obj.iv[3];
	local[11]= fqv[177];
	local[12]= local[4]->c.obj.iv[4];
	local[13]= fqv[178];
	local[14]= local[4]->c.obj.iv[1];
	local[15]= fqv[179];
	local[16]= local[4]->c.obj.iv[2];
	local[17]= fqv[99];
	local[18]= local[4]->c.obj.iv[5];
	local[19]= fqv[180];
	local[20]= local[4];
	local[21]= fqv[180];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,2,local+20); /*send*/
	local[20]= w;
	local[21]= fqv[181];
	local[22]= local[4];
	local[23]= fqv[181];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,2,local+22); /*send*/
	local[22]= w;
	local[23]= fqv[182];
	local[24]= local[4];
	local[25]= fqv[182];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,2,local+24); /*send*/
	local[24]= w;
	local[25]= fqv[183];
	local[26]= local[4];
	local[27]= fqv[183];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,2,local+26); /*send*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,20,local+7); /*send*/
	w = local[6];
	local[3] = w;
	local[6]= local[4];
	local[7]= local[3];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(*ftab[28])(ctx,3,local+6,&ftab[28],fqv[184]); /*acons*/
	local[1] = w;
	goto WHL1988;
WHX1989:
	local[6]= NIL;
BLK1990:
	w = NIL;
	local[4]= NIL;
	local[5]= local[1];
WHL1994:
	if (local[5]==NIL) goto WHX1995;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	local[6]= local[3];
	local[7]= fqv[32];
	local[8]= fqv[180];
	local[9]= local[3]->c.obj.iv[7];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(pointer)ASSQ(ctx,2,local+9); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
	local[10]= fqv[182];
	local[11]= local[3]->c.obj.iv[9];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)ASSQ(ctx,2,local+11); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.cdr;
	local[12]= fqv[181];
	local[13]= local[3]->c.obj.iv[8];
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)ASSQ(ctx,2,local+13); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.cdr;
	local[14]= fqv[183];
	local[15]= local[3]->c.obj.iv[10];
	local[16]= local[1];
	ctx->vsp=local+17;
	w=(pointer)ASSQ(ctx,2,local+15); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.cdr;
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,10,local+6); /*send*/
	goto WHL1994;
WHX1995:
	local[6]= NIL;
BLK1996:
	w = NIL;
	local[4]= NIL;
	local[5]= argv[0];
	local[6]= fqv[185];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
WHL1999:
	if (local[5]==NIL) goto WHX2000;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[0] = NIL;
	local[6]= NIL;
	local[7]= local[4];
	local[8]= fqv[186];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
WHL2004:
	if (local[7]==NIL) goto WHX2005;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)ASSQ(ctx,2,local+8); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.cdr;
	w = local[0];
	ctx->vsp=local+9;
	local[0] = cons(ctx,local[8],w);
	goto WHL2004;
WHX2005:
	local[8]= NIL;
BLK2006:
	w = NIL;
	local[6]= local[0];
	local[7]= local[6];
	w = local[4];
	w->c.obj.iv[4] = local[7];
	local[6]= NIL;
	local[7]= local[4];
	local[8]= fqv[14];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
WHL2009:
	if (local[7]==NIL) goto WHX2010;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[0] = NIL;
	local[8]= NIL;
	local[9]= local[6];
	local[10]= fqv[186];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
WHL2014:
	if (local[9]==NIL) goto WHX2015;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= local[8];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)ASSQ(ctx,2,local+10); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.cdr;
	w = local[0];
	ctx->vsp=local+11;
	local[0] = cons(ctx,local[10],w);
	goto WHL2014;
WHX2015:
	local[10]= NIL;
BLK2016:
	w = NIL;
	local[8]= local[0];
	local[9]= local[8];
	w = local[6];
	w->c.obj.iv[4] = local[9];
	goto WHL2009;
WHX2010:
	local[8]= NIL;
BLK2011:
	w = NIL;
	goto WHL1999;
WHX2000:
	local[6]= NIL;
BLK2001:
	w = NIL;
	local[4]= (pointer)get_sym_func(fqv[187]);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[4]= w;
	local[5]= w;
	w = argv[0];
	w->c.obj.iv[10] = local[5];
	w = argv[0];
	local[0]= w;
BLK1986:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___geobody(ctx,n,argv,env)
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
	local[0]= fqv[188];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF2018;
	local[0]= fqv[189];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[190],w);
	goto IF2019;
IF2018:
	local[0]= fqv[191];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF2019:
	local[0]= fqv[192];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[193];
	local[1]= fqv[194];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[195]); /*require*/
	local[0]= fqv[196];
	local[1]= fqv[197];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF2020;
	local[0]= fqv[196];
	local[1]= fqv[197];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[196];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF2022;
	local[0]= fqv[196];
	local[1]= fqv[198];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2023;
IF2022:
	local[0]= NIL;
IF2023:
	local[0]= fqv[196];
	goto IF2021;
IF2020:
	local[0]= NIL;
IF2021:
	local[0]= fqv[199];
	local[1]= fqv[197];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF2024;
	local[0]= fqv[199];
	local[1]= fqv[197];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[199];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF2026;
	local[0]= fqv[199];
	local[1]= fqv[198];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2027;
IF2026:
	local[0]= NIL;
IF2027:
	local[0]= fqv[199];
	goto IF2025;
IF2024:
	local[0]= NIL;
IF2025:
	local[0]= fqv[200];
	local[1]= fqv[197];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF2028;
	local[0]= fqv[200];
	local[1]= fqv[197];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[200];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF2030;
	local[0]= fqv[200];
	local[1]= fqv[198];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2031;
IF2030:
	local[0]= NIL;
IF2031:
	local[0]= fqv[200];
	goto IF2029;
IF2028:
	local[0]= NIL;
IF2029:
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1253faceset_update,fqv[33],fqv[201],fqv[202]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1262faceset_vertices,fqv[173],fqv[201],fqv[203]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1264faceset_faces,fqv[185],fqv[201],fqv[204]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1270faceset_face,fqv[205],fqv[201],fqv[206]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1272faceset_all_edges,fqv[23],fqv[201],fqv[207]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1274faceset_edges,fqv[186],fqv[201],fqv[208]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1276faceset_edge,fqv[209],fqv[201],fqv[210]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1278faceset_vertex,fqv[211],fqv[201],fqv[212]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1280faceset_box,fqv[28],fqv[201],fqv[213]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1282faceset_color,fqv[10],fqv[201],fqv[214]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1288faceset_reflectance,fqv[11],fqv[201],fqv[215]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1296faceset_diffusion,fqv[12],fqv[201],fqv[216]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1304faceset_holes,fqv[14],fqv[201],fqv[217]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1306faceset_visible_faces,fqv[22],fqv[201],fqv[218]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1311faceset_visible_edges,fqv[6],fqv[201],fqv[219]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1327faceset_contour_edges,fqv[220],fqv[201],fqv[221]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1341faceset_non_contour_edges,fqv[222],fqv[201],fqv[223]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1350faceset_common_box,fqv[74],fqv[201],fqv[224]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1354faceset_newbox,fqv[97],fqv[201],fqv[225]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1360faceset_reset_vertices,fqv[4],fqv[201],fqv[226]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1367faceset_translate_vertices,fqv[56],fqv[201],fqv[227]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1374faceset_rotate_vertices,fqv[57],fqv[201],fqv[228]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1385faceset_magnify,fqv[58],fqv[201],fqv[229]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1407faceset_faces_intersect_with_point_vector,fqv[69],fqv[201],fqv[230]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1416faceset_distance,fqv[46],fqv[201],fqv[231]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1435faceset_init,fqv[32],fqv[201],fqv[232]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1463body_translate_vertices,fqv[56],fqv[233],fqv[234]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1465body_rotate_vertices,fqv[57],fqv[233],fqv[235]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1467body_magnify,fqv[58],fqv[233],fqv[236]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1471body_euler,fqv[237],fqv[233],fqv[238]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1473body_perimeter,fqv[239],fqv[233],fqv[240]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1475body_volume,fqv[62],fqv[233],fqv[241]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1479body_centroid,fqv[63],fqv[233],fqv[242]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1489body_world_centroid,fqv[243],fqv[233],fqv[244]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1491body_area,fqv[67],fqv[233],fqv[245]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1493body_extream_point,fqv[68],fqv[233],fqv[246]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1502body_length,fqv[60],fqv[233],fqv[247]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1504body_supporting_faces,fqv[248],fqv[233],fqv[249]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1508body_possibly_interfering_faces,fqv[72],fqv[233],fqv[250]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1511body_possibly_interfering_edges,fqv[75],fqv[233],fqv[251]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1514body_intersect_face,fqv[71],fqv[233],fqv[252]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1524body_intersectp,fqv[253],fqv[233],fqv[254]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1541body_intersectp2,fqv[255],fqv[233],fqv[256]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1629body_insidep,fqv[82],fqv[233],fqv[257]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1671body_evert,fqv[258],fqv[233],fqv[259]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1677body_set_convexp,fqv[98],fqv[233],fqv[260]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1686body_get_face,fqv[9],fqv[233],fqv[261]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1740body_primitive_body_p,fqv[115],fqv[233],fqv[262]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1743body_primitive_bodies,fqv[146],fqv[233],fqv[263]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1760body_csg,fqv[126],fqv[233],fqv[264]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1766body_copy_csg,fqv[265],fqv[233],fqv[266]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1771body_body_type,fqv[119],fqv[233],fqv[267]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1775body_creation_form,fqv[268],fqv[233],fqv[269]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1780body_prin1,fqv[118],fqv[233],fqv[270]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1782body_init,fqv[32],fqv[233],fqv[271]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1836body_replace_shape,fqv[147],fqv[233],fqv[272]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1853body__,fqv[111],fqv[233],fqv[273]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1856body__,fqv[113],fqv[233],fqv[274]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1859body__,fqv[275],fqv[233],fqv[276]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1862body_primitive_groups,fqv[112],fqv[233],fqv[277]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1879body_constraint,fqv[278],fqv[233],fqv[279]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1884body_contact_vertices,fqv[151],fqv[233],fqv[280]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1919body_contact_edges,fqv[152],fqv[233],fqv[281]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1940body_possibly_contacting_vertices,fqv[158],fqv[233],fqv[282]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1943body_possibly_contacting_edges,fqv[165],fqv[233],fqv[283]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1946body_possibly_contacting_faces,fqv[159],fqv[233],fqv[284]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1957sphere_radius,fqv[285],fqv[286],fqv[287]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1963sphere_inner,fqv[90],fqv[286],fqv[288]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1965sphere_volume,fqv[62],fqv[286],fqv[289]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1967sphere_intersect_line,fqv[77],fqv[286],fqv[290]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1971sphere_closest_point,fqv[291],fqv[286],fqv[292]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1973sphere_intersect_with_body,fqv[293],fqv[286],fqv[294]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1982sphere_init,fqv[32],fqv[286],fqv[295]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[296],module,F1252add_wings,fqv[297]);
	local[0]= fqv[298];
	local[1]= fqv[299];
	ctx->vsp=local+2;
	w=(*ftab[30])(ctx,2,local+0,&ftab[30],fqv[300]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<31; i++) ftab[i]=fcallx;
}
