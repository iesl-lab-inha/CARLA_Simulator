/* ./gltexture.c :  entry=gltexture */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "gltexture.h"
#pragma init (register_gltexture)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___gltexture();
extern pointer build_quote_vector();
static int register_gltexture()
  { add_module_initializer("___gltexture", ___gltexture);}

static pointer F563transpose_rows();
static pointer F564load_texture_file();
static pointer F565append_image();
static pointer F566make_cube_with_texture();

/*transpose-rows*/
static pointer F563transpose_rows(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[0];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[3];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= local[0];
	local[5]= local[1];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,3,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,1,local+4,&ftab[0],fqv[4]); /*make-string*/
	local[4]= w;
	local[5]= local[2];
	local[6]= makeint(3);
	ctx->vsp=local+7;
	w=(pointer)NUMEQUAL(ctx,2,local+5); /*=*/
	if (w!=NIL) goto IF569;
	local[5]= fqv[5];
	ctx->vsp=local+6;
	w=(pointer)SIGERROR(ctx,1,local+5); /*error*/
	local[5]= w;
	goto IF570;
IF569:
	local[5]= NIL;
IF570:
	local[5]= makeint(0);
	local[6]= local[0];
WHL572:
	local[7]= local[5];
	w = local[6];
	if ((eusinteger_t)local[7] >= (eusinteger_t)w) goto WHX573;
	local[7]= makeint(0);
	local[8]= local[1];
WHL576:
	local[9]= local[7];
	w = local[8];
	if ((eusinteger_t)local[9] >= (eusinteger_t)w) goto WHX577;
	local[9]= makeint(0);
	local[10]= local[2];
WHL580:
	local[11]= local[9];
	w = local[10];
	if ((eusinteger_t)local[11] >= (eusinteger_t)w) goto WHX581;
	local[11]= local[4];
	local[12]= local[1];
	local[13]= local[7];
	local[14]= makeint(1);
	ctx->vsp=local+15;
	w=(pointer)MINUS(ctx,3,local+12); /*-*/
	local[12]= w;
	local[13]= local[0];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)TIMES(ctx,3,local+12); /***/
	local[12]= w;
	local[13]= local[5];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)TIMES(ctx,2,local+13); /***/
	local[13]= w;
	local[14]= local[9];
	ctx->vsp=local+15;
	w=(pointer)PLUS(ctx,3,local+12); /*+*/
	local[12]= w;
	local[13]= local[3];
	local[14]= local[7];
	local[15]= local[0];
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)TIMES(ctx,3,local+14); /***/
	local[14]= w;
	local[15]= local[5];
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)TIMES(ctx,2,local+15); /***/
	local[15]= w;
	local[16]= local[9];
	ctx->vsp=local+17;
	w=(pointer)PLUS(ctx,3,local+14); /*+*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SETELT(ctx,3,local+11); /*setelt*/
	local[11]= local[9];
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[9] = w;
	goto WHL580;
WHX581:
	local[11]= NIL;
BLK582:
	w = NIL;
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	local[7] = w;
	goto WHL576;
WHX577:
	local[9]= NIL;
BLK578:
	w = NIL;
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[5] = w;
	goto WHL572;
WHX573:
	local[7]= NIL;
BLK574:
	w = NIL;
	local[5]= loadglobal(fqv[6]);
	ctx->vsp=local+6;
	w=(pointer)INSTANTIATE(ctx,1,local+5); /*instantiate*/
	local[5]= w;
	local[6]= local[5];
	local[7]= fqv[7];
	local[8]= local[0];
	local[9]= local[1];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,5,local+6); /*send*/
	w = local[5];
	local[0]= w;
BLK568:
	ctx->vsp=local; return(local[0]);}

/*load-texture-file*/
static pointer F564load_texture_file(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[8]); /*image:read-pnm-file*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[2])(ctx,1,local+0,&ftab[2],fqv[9]); /*image:color-to-deep*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)F563transpose_rows(ctx,1,local+0); /*transpose-rows*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= local[0];
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= local[0];
	local[4]= fqv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= makeint(1);
	local[5]= local[1];
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)LOG(ctx,2,local+5); /*log*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)CEILING(ctx,1,local+5); /*ceiling*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ASH(ctx,2,local+4); /*ash*/
	local[4]= w;
	local[5]= makeint(1);
	local[6]= local[2];
	local[7]= makeint(2);
	ctx->vsp=local+8;
	w=(pointer)LOG(ctx,2,local+6); /*log*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)CEILING(ctx,1,local+6); /*ceiling*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASH(ctx,2,local+5); /*ash*/
	local[5]= w;
	local[6]= local[3];
	local[7]= local[3];
	local[8]= makeint(3);
	ctx->vsp=local+9;
	w=(pointer)NUMEQUAL(ctx,2,local+7); /*=*/
	if (w!=NIL) goto IF585;
	local[7]= fqv[10];
	ctx->vsp=local+8;
	w=(pointer)SIGERROR(ctx,1,local+7); /*error*/
	local[7]= w;
	goto IF586;
IF585:
	local[7]= NIL;
IF586:
	local[7]= local[1];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)NUMEQUAL(ctx,2,local+7); /*=*/
	if (w==NIL) goto AND589;
	local[7]= local[2];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)NUMEQUAL(ctx,2,local+7); /*=*/
	if (w==NIL) goto AND589;
	goto CON588;
AND589:
	local[7]= local[4];
	local[8]= local[5];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,3,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[0])(ctx,1,local+7,&ftab[0],fqv[4]); /*make-string*/
	local[7]= w;
	local[8]= makeint(6407);
	local[9]= local[1];
	local[10]= local[2];
	local[11]= makeint(5121);
	local[12]= local[0];
	local[13]= fqv[3];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[12]= w;
	local[13]= local[4];
	local[14]= local[5];
	local[15]= makeint(5121);
	local[16]= local[7];
	ctx->vsp=local+17;
	w=(*ftab[3])(ctx,9,local+8,&ftab[3],fqv[11]); /*gluscaleimage*/
	local[8]= loadglobal(fqv[6]);
	ctx->vsp=local+9;
	w=(pointer)INSTANTIATE(ctx,1,local+8); /*instantiate*/
	local[8]= w;
	local[9]= local[8];
	local[10]= fqv[7];
	local[11]= local[4];
	local[12]= local[5];
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,5,local+9); /*send*/
	w = local[8];
	local[7]= w;
	goto CON587;
CON588:
	local[7]= local[0];
	goto CON587;
CON591:
	local[7]= NIL;
CON587:
	w = local[7];
	local[0]= w;
BLK584:
	ctx->vsp=local; return(local[0]);}

/*append-image*/
static pointer F565append_image(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST593:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	if (local[0]==NIL) goto IF594;
	local[1]= (pointer)get_sym_func(fqv[12]);
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO596,env,argv,local);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[1]= w;
	local[2]= (pointer)get_sym_func(fqv[13]);
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO597,env,argv,local);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,2,local+2); /*apply*/
	local[2]= w;
	local[3]= makeint(3);
	local[4]= local[1];
	local[5]= local[2];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,3,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,1,local+4,&ftab[0],fqv[4]); /*make-string*/
	local[4]= w;
	local[5]= makeint(0);
	local[6]= NIL;
	local[7]= local[0];
WHL599:
	if (local[7]==NIL) goto WHX600;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	local[9]= fqv[0];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= local[6];
	local[10]= fqv[1];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	local[10]= local[6];
	local[11]= fqv[3];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	local[11]= makeint(0);
	local[12]= local[8];
WHL604:
	local[13]= local[11];
	w = local[12];
	if ((eusinteger_t)local[13] >= (eusinteger_t)w) goto WHX605;
	local[13]= makeint(0);
	local[14]= local[9];
WHL608:
	local[15]= local[13];
	w = local[14];
	if ((eusinteger_t)local[15] >= (eusinteger_t)w) goto WHX609;
	local[15]= makeint(0);
	local[16]= local[3];
WHL612:
	local[17]= local[15];
	w = local[16];
	if ((eusinteger_t)local[17] >= (eusinteger_t)w) goto WHX613;
	local[17]= local[4];
	local[18]= local[13];
	local[19]= local[5];
	ctx->vsp=local+20;
	w=(pointer)PLUS(ctx,2,local+18); /*+*/
	local[18]= w;
	local[19]= local[1];
	local[20]= local[3];
	ctx->vsp=local+21;
	w=(pointer)TIMES(ctx,3,local+18); /***/
	local[18]= w;
	local[19]= local[11];
	local[20]= local[3];
	ctx->vsp=local+21;
	w=(pointer)TIMES(ctx,2,local+19); /***/
	local[19]= w;
	local[20]= local[15];
	ctx->vsp=local+21;
	w=(pointer)PLUS(ctx,3,local+18); /*+*/
	local[18]= w;
	local[19]= local[10];
	local[20]= local[13];
	local[21]= local[8];
	local[22]= local[3];
	ctx->vsp=local+23;
	w=(pointer)TIMES(ctx,3,local+20); /***/
	local[20]= w;
	local[21]= local[11];
	local[22]= local[3];
	ctx->vsp=local+23;
	w=(pointer)TIMES(ctx,2,local+21); /***/
	local[21]= w;
	local[22]= local[15];
	ctx->vsp=local+23;
	w=(pointer)PLUS(ctx,3,local+20); /*+*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)ELT(ctx,2,local+19); /*elt*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)SETELT(ctx,3,local+17); /*setelt*/
	local[17]= local[15];
	ctx->vsp=local+18;
	w=(pointer)ADD1(ctx,1,local+17); /*1+*/
	local[15] = w;
	goto WHL612;
WHX613:
	local[17]= NIL;
BLK614:
	w = NIL;
	local[15]= local[13];
	ctx->vsp=local+16;
	w=(pointer)ADD1(ctx,1,local+15); /*1+*/
	local[13] = w;
	goto WHL608;
WHX609:
	local[15]= NIL;
BLK610:
	w = NIL;
	local[13]= local[11];
	ctx->vsp=local+14;
	w=(pointer)ADD1(ctx,1,local+13); /*1+*/
	local[11] = w;
	goto WHL604;
WHX605:
	local[13]= NIL;
BLK606:
	w = NIL;
	local[11]= local[5];
	local[12]= local[9];
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[5] = w;
	w = local[5];
	goto WHL599;
WHX600:
	local[8]= NIL;
BLK601:
	w = NIL;
	local[6]= loadglobal(fqv[6]);
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,1,local+6); /*instantiate*/
	local[6]= w;
	local[7]= local[6];
	local[8]= fqv[7];
	local[9]= local[1];
	local[10]= local[2];
	local[11]= local[4];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	w = local[6];
	local[1]= w;
	goto IF595;
IF594:
	local[1]= NIL;
IF595:
	w = local[1];
	local[0]= w;
BLK592:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO596(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[0];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO597(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[1];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*make-cube-with-texture*/
static pointer F566make_cube_with_texture(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST617:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[14], &argv[3], n-3, local+1, 1);
	if (n & (1<<0)) goto KEY618;
	local[1] = NIL;
KEY618:
	if (n & (1<<1)) goto KEY619;
	local[2] = NIL;
KEY619:
	if (n & (1<<2)) goto KEY620;
	local[3] = NIL;
KEY620:
	if (n & (1<<3)) goto KEY621;
	local[4] = NIL;
KEY621:
	if (n & (1<<4)) goto KEY622;
	local[5] = NIL;
KEY622:
	if (n & (1<<5)) goto KEY623;
	local[6] = NIL;
KEY623:
	if (n & (1<<6)) goto KEY624;
	local[7] = NIL;
KEY624:
	if (n & (1<<7)) goto KEY625;
	local[8] = NIL;
KEY625:
	if (local[7]==NIL) goto AND629;
	local[9]= local[7];
	local[10]= makeint(1);
	local[11]= local[7];
	local[12]= makeint(2);
	ctx->vsp=local+13;
	w=(pointer)LOG(ctx,2,local+11); /*log*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)CEILING(ctx,1,local+11); /*ceiling*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)ASH(ctx,2,local+10); /*ash*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)NUMEQUAL(ctx,2,local+9); /*=*/
	if (w!=NIL) goto AND629;
	goto OR628;
AND629:
	if (local[8]==NIL) goto AND630;
	local[9]= local[8];
	local[10]= makeint(1);
	local[11]= local[8];
	local[12]= makeint(2);
	ctx->vsp=local+13;
	w=(pointer)LOG(ctx,2,local+11); /*log*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)CEILING(ctx,1,local+11); /*ceiling*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)ASH(ctx,2,local+10); /*ash*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)NUMEQUAL(ctx,2,local+9); /*=*/
	if (w!=NIL) goto AND630;
	goto OR628;
AND630:
	goto IF626;
OR628:
	local[9]= fqv[15];
	ctx->vsp=local+10;
	w=(pointer)SIGERROR(ctx,1,local+9); /*error*/
	local[9]= w;
	goto IF627;
IF626:
	local[9]= NIL;
IF627:
	local[9]= (pointer)get_sym_func(fqv[16]);
	local[10]= argv[0];
	local[11]= argv[1];
	local[12]= argv[2];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,3,local+10); /*list*/
	local[10]= w;
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)APPEND(ctx,2,local+10); /*append*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)APPLY(ctx,2,local+9); /*apply*/
	local[9]= w;
	local[10]= local[9];
	local[11]= fqv[17];
	local[12]= NIL;
	local[13]= fqv[18];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= local[9];
	local[12]= fqv[17];
	local[13]= NIL;
	local[14]= fqv[19];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,4,local+11); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= local[9];
	local[13]= fqv[17];
	local[14]= NIL;
	local[15]= fqv[20];
	local[16]= makeint(0);
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,5,local+12); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= local[9];
	local[14]= fqv[17];
	local[15]= NIL;
	local[16]= fqv[20];
	local[17]= makeint(1);
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,5,local+13); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	local[14]= local[9];
	local[15]= fqv[17];
	local[16]= NIL;
	local[17]= fqv[20];
	local[18]= makeint(2);
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,5,local+14); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	local[15]= local[9];
	local[16]= fqv[17];
	local[17]= NIL;
	local[18]= fqv[20];
	local[19]= makeint(3);
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,5,local+15); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,6,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	local[11]= makeclosure(codevec,quotevec,CLO631,env,argv,local);
	local[12]= local[1];
	local[13]= local[2];
	local[14]= local[3];
	local[15]= local[4];
	local[16]= local[5];
	local[17]= local[6];
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,6,local+12); /*list*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)MAPCAR(ctx,2,local+11); /*mapcar*/
	local[11]= w;
	local[12]= makeflt(1.00000000e+00);
	local[13]= makeflt(1.00000000e+00);
	local[14]= NIL;
	local[15]= NIL;
	local[16]= NIL;
	local[17]= (pointer)get_sym_func(fqv[21]);
	local[18]= local[11];
	ctx->vsp=local+19;
	w=(*ftab[4])(ctx,2,local+17,&ftab[4],fqv[22]); /*remove-if*/
	if (w!=NIL) goto IF632;
	w = local[9];
	ctx->vsp=local+17;
	local[0]=w;
	goto BLK616;
	goto IF633;
IF632:
	local[17]= NIL;
IF633:
	local[17]= (pointer)get_sym_func(fqv[23]);
	local[18]= (pointer)get_sym_func(fqv[21]);
	local[19]= local[11];
	ctx->vsp=local+20;
	w=(*ftab[4])(ctx,2,local+18,&ftab[4],fqv[22]); /*remove-if*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)APPLY(ctx,2,local+17); /*apply*/
	local[14] = w;
	local[17]= local[14];
	local[18]= fqv[0];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
	local[18]= local[14];
	local[19]= fqv[1];
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,2,local+18); /*send*/
	local[18]= w;
	local[19]= local[14];
	local[20]= fqv[2];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,2,local+19); /*send*/
	local[19]= w;
	local[20]= local[14];
	local[21]= fqv[3];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,2,local+20); /*send*/
	local[20]= w;
	if (local[7]==NIL) goto IF634;
	local[21]= local[7];
	goto IF635;
IF634:
	local[21]= makeint(1);
	local[22]= local[17];
	local[23]= makeint(2);
	ctx->vsp=local+24;
	w=(pointer)LOG(ctx,2,local+22); /*log*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)CEILING(ctx,1,local+22); /*ceiling*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)ASH(ctx,2,local+21); /*ash*/
	local[21]= w;
IF635:
	if (local[8]==NIL) goto IF636;
	local[22]= local[8];
	goto IF637;
IF636:
	local[22]= makeint(1);
	local[23]= local[18];
	local[24]= makeint(2);
	ctx->vsp=local+25;
	w=(pointer)LOG(ctx,2,local+23); /*log*/
	local[23]= w;
	ctx->vsp=local+24;
	w=(pointer)CEILING(ctx,1,local+23); /*ceiling*/
	local[23]= w;
	ctx->vsp=local+24;
	w=(pointer)ASH(ctx,2,local+22); /*ash*/
	local[22]= w;
IF637:
	local[23]= local[19];
	local[24]= local[20];
	local[25]= local[18];
	local[26]= local[22];
	ctx->vsp=local+27;
	w=(pointer)NUMEQUAL(ctx,2,local+25); /*=*/
	if (w==NIL) goto OR640;
	local[25]= local[17];
	local[26]= local[21];
	ctx->vsp=local+27;
	w=(pointer)NUMEQUAL(ctx,2,local+25); /*=*/
	if (w==NIL) goto OR640;
	goto IF638;
OR640:
	local[25]= fqv[24];
	local[26]= local[21];
	local[27]= local[22];
	local[28]= local[17];
	local[29]= local[18];
	ctx->vsp=local+30;
	w=(*ftab[5])(ctx,5,local+25,&ftab[5],fqv[25]); /*warn*/
	local[25]= local[21];
	local[26]= local[22];
	local[27]= local[19];
	ctx->vsp=local+28;
	w=(pointer)TIMES(ctx,3,local+25); /***/
	local[25]= w;
	ctx->vsp=local+26;
	w=(*ftab[0])(ctx,1,local+25,&ftab[0],fqv[4]); /*make-string*/
	local[24] = w;
	local[25]= local[21];
	ctx->vsp=local+26;
	w=(pointer)EUSFLOAT(ctx,1,local+25); /*float*/
	local[25]= w;
	local[26]= local[17];
	ctx->vsp=local+27;
	w=(pointer)EUSFLOAT(ctx,1,local+26); /*float*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)QUOTIENT(ctx,2,local+25); /*/*/
	local[12] = w;
	local[25]= local[22];
	ctx->vsp=local+26;
	w=(pointer)EUSFLOAT(ctx,1,local+25); /*float*/
	local[25]= w;
	local[26]= local[18];
	ctx->vsp=local+27;
	w=(pointer)EUSFLOAT(ctx,1,local+26); /*float*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)QUOTIENT(ctx,2,local+25); /*/*/
	local[13] = w;
	local[25]= local[19];
	local[26]= makeint(3);
	ctx->vsp=local+27;
	w=(pointer)NUMEQUAL(ctx,2,local+25); /*=*/
	if (w==NIL) goto IF641;
	local[25]= makeint(6407);
	goto IF642;
IF641:
	local[25]= makeint(6409);
IF642:
	local[26]= local[25];
	local[27]= local[17];
	local[28]= local[18];
	local[29]= makeint(5121);
	local[30]= local[20];
	local[31]= local[21];
	local[32]= local[22];
	local[33]= makeint(5121);
	local[34]= local[24];
	ctx->vsp=local+35;
	w=(*ftab[3])(ctx,9,local+26,&ftab[3],fqv[11]); /*gluscaleimage*/
	local[25]= loadglobal(fqv[6]);
	ctx->vsp=local+26;
	w=(pointer)INSTANTIATE(ctx,1,local+25); /*instantiate*/
	local[25]= w;
	local[26]= local[25];
	local[27]= fqv[7];
	local[28]= local[21];
	local[29]= local[22];
	local[30]= local[24];
	ctx->vsp=local+31;
	w=(pointer)SEND(ctx,5,local+26); /*send*/
	w = local[25];
	local[14] = w;
	local[25]= local[14];
	goto IF639;
IF638:
	local[25]= NIL;
IF639:
	local[25]= makeint(0);
	local[26]= local[14];
	local[27]= fqv[0];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,2,local+26); /*send*/
	local[26]= w;
	local[27]= local[14];
	local[28]= fqv[1];
	ctx->vsp=local+29;
	w=(pointer)SEND(ctx,2,local+27); /*send*/
	local[27]= w;
	ctx->vsp=local+28;
	local[28]= makeclosure(codevec,quotevec,CLO644,env,argv,local);
	local[29]= local[11];
	ctx->vsp=local+30;
	w=(pointer)MAPCAR(ctx,2,local+28); /*mapcar*/
	local[15] = w;
	local[25]= fqv[26];
	local[26]= (pointer)get_sym_func(fqv[27]);
	ctx->vsp=local+27;
	w=(*ftab[6])(ctx,2,local+25,&ftab[6],fqv[28]); /*make-hash-table*/
	local[16] = w;
	local[25]= makeint(0);
	local[26]= makeint(6);
WHL646:
	local[27]= local[25];
	w = local[26];
	if ((eusinteger_t)local[27] >= (eusinteger_t)w) goto WHX647;
	local[27]= local[10];
	local[28]= local[25];
	ctx->vsp=local+29;
	w=(pointer)ELT(ctx,2,local+27); /*elt*/
	local[27]= w;
	local[28]= local[15];
	local[29]= local[25];
	ctx->vsp=local+30;
	w=(pointer)ELT(ctx,2,local+28); /*elt*/
	local[28]= w;
	local[29]= local[27];
	local[30]= fqv[29];
	ctx->vsp=local+31;
	w=(pointer)SEND(ctx,2,local+29); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[29]= (w)->c.cons.cdr;
	if (local[28]==NIL) goto IF649;
	local[30]= makeint(0);
	local[31]= makeint(4);
WHL652:
	local[32]= local[30];
	w = local[31];
	if ((eusinteger_t)local[32] >= (eusinteger_t)w) goto WHX653;
	local[32]= local[29];
	local[33]= local[30];
	ctx->vsp=local+34;
	w=(pointer)ELT(ctx,2,local+32); /*elt*/
	local[32]= w;
	local[33]= local[29];
	ctx->vsp=local+34;
	w=(pointer)LIST(ctx,2,local+32); /*list*/
	local[32]= w;
	local[33]= local[16];
	local[34]= local[28];
	local[35]= local[30];
	ctx->vsp=local+36;
	w=(pointer)ELT(ctx,2,local+34); /*elt*/
	local[34]= w;
	ctx->vsp=local+35;
	w=(*ftab[7])(ctx,3,local+32,&ftab[7],fqv[30]); /*sethash*/
	local[32]= local[30];
	ctx->vsp=local+33;
	w=(pointer)ADD1(ctx,1,local+32); /*1+*/
	local[30] = w;
	goto WHL652;
WHX653:
	local[32]= NIL;
BLK654:
	w = NIL;
	local[30]= w;
	goto IF650;
IF649:
	local[30]= NIL;
IF650:
	w = local[30];
	local[27]= local[25];
	ctx->vsp=local+28;
	w=(pointer)ADD1(ctx,1,local+27); /*1+*/
	local[25] = w;
	goto WHL646;
WHX647:
	local[27]= NIL;
BLK648:
	w = NIL;
	local[25]= local[9];
	local[26]= fqv[31];
	ctx->vsp=local+27;
	w=(pointer)GENSYM(ctx,1,local+26); /*gensym*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(*ftab[8])(ctx,1,local+26,&ftab[8],fqv[32]); /*symbol-string*/
	local[26]= w;
	local[27]= fqv[33];
	ctx->vsp=local+28;
	w=(pointer)PUTPROP(ctx,3,local+25); /*putprop*/
	local[25]= local[9];
	local[26]= local[14];
	local[27]= fqv[0];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,2,local+26); /*send*/
	local[26]= w;
	local[27]= fqv[34];
	ctx->vsp=local+28;
	w=(pointer)PUTPROP(ctx,3,local+25); /*putprop*/
	local[25]= local[9];
	local[26]= local[14];
	local[27]= fqv[1];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,2,local+26); /*send*/
	local[26]= w;
	local[27]= fqv[35];
	ctx->vsp=local+28;
	w=(pointer)PUTPROP(ctx,3,local+25); /*putprop*/
	local[25]= local[9];
	local[26]= local[14];
	local[27]= fqv[2];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,2,local+26); /*send*/
	local[26]= w;
	local[27]= fqv[36];
	ctx->vsp=local+28;
	w=(pointer)PUTPROP(ctx,3,local+25); /*putprop*/
	local[25]= local[9];
	local[26]= local[14];
	local[27]= fqv[3];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,2,local+26); /*send*/
	local[26]= w;
	local[27]= fqv[37];
	ctx->vsp=local+28;
	w=(pointer)PUTPROP(ctx,3,local+25); /*putprop*/
	local[25]= local[9];
	local[26]= local[16];
	local[27]= fqv[38];
	ctx->vsp=local+28;
	w=(pointer)PUTPROP(ctx,3,local+25); /*putprop*/
	w = local[9];
	local[0]= w;
BLK616:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO631(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	if (argv[0]==NIL) goto IF655;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F564load_texture_file(ctx,1,local+0); /*load-texture-file*/
	local[0]= w;
	goto IF656;
IF655:
	local[0]= NIL;
IF656:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO644(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	if (argv[0]==NIL) goto IF657;
	local[0]= env->c.clo.env2[12];
	local[1]= argv[0];
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= env->c.clo.env2[13];
	local[2]= argv[0];
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)EUSFLOAT(ctx,1,local+2); /*float*/
	local[2]= w;
	local[3]= env->c.clo.env2[26];
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	local[3]= env->c.clo.env2[25];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)EUSFLOAT(ctx,1,local+3); /*float*/
	local[3]= w;
	local[4]= env->c.clo.env2[27];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,2,local+2); /*float-vector*/
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)EUSFLOAT(ctx,1,local+3); /*float*/
	local[3]= w;
	local[4]= env->c.clo.env2[26];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	local[4]= env->c.clo.env2[25];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)EUSFLOAT(ctx,1,local+4); /*float*/
	local[4]= w;
	local[5]= env->c.clo.env2[27];
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,2,local+3); /*float-vector*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)EUSFLOAT(ctx,1,local+4); /*float*/
	local[4]= w;
	local[5]= env->c.clo.env2[26];
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	local[5]= env->c.clo.env2[25];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)EUSFLOAT(ctx,1,local+5); /*float*/
	local[5]= w;
	local[6]= env->c.clo.env2[27];
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,2,local+4); /*float-vector*/
	local[4]= w;
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)EUSFLOAT(ctx,1,local+5); /*float*/
	local[5]= w;
	local[6]= env->c.clo.env2[26];
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= env->c.clo.env2[25];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)EUSFLOAT(ctx,1,local+6); /*float*/
	local[6]= w;
	local[7]= env->c.clo.env2[27];
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,2,local+5); /*float-vector*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	local[3]= env->c.clo.env2[25];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	env->c.clo.env2[25] = w;
	w = local[2];
	local[0]= w;
	goto IF658;
IF657:
	local[0]= NIL;
IF658:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___gltexture(ctx,n,argv,env)
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
	local[0]= fqv[39];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF660;
	local[0]= fqv[40];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[41],w);
	goto IF661;
IF660:
	local[0]= fqv[42];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF661:
	local[0]= fqv[43];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[44],module,F563transpose_rows,fqv[45]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[46],module,F564load_texture_file,fqv[47]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[23],module,F565append_image,fqv[48]);
	local[0]= fqv[49];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[50],module,F566make_cube_with_texture,fqv[51]);
	local[0]= fqv[52];
	local[1]= fqv[53];
	ctx->vsp=local+2;
	w=(*ftab[9])(ctx,2,local+0,&ftab[9],fqv[54]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<10; i++) ftab[i]=fcallx;
}
