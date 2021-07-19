/* ./viewsurface.c :  entry=viewsurface */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "viewsurface.h"
#pragma init (register_viewsurface)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___viewsurface();
extern pointer build_quote_vector();
static int register_viewsurface()
  { add_module_initializer("___viewsurface", ___viewsurface);}

static pointer F3594hls2rgb();
static pointer F3595rgb2hls();
static pointer F3596tektro_showline();
static pointer F3597tektro_clear();
static pointer F3598default_viewsurface();

/*hls2rgb*/
static pointer F3594hls2rgb(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3601;}
	local[0]= makeint(255);
ENT3601:
ENT3600:
	if (n>4) maerror();
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,FLET3602,env,argv,local);
	local[2]= makeint(0);
	local[3]= makeint(0);
	local[4]= argv[1];
	local[5]= makeflt(5.00000000e-01);
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,2,local+4); /*<*/
	if (w==NIL) goto IF3603;
	local[4]= argv[1];
	local[5]= makeint(1);
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[3] = w;
	local[4]= local[3];
	goto IF3604;
IF3603:
	local[4]= argv[1];
	local[5]= argv[2];
	local[6]= argv[1];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,1,local+6); /*-*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,3,local+4); /*+*/
	local[3] = w;
	local[4]= local[3];
IF3604:
	local[4]= makeint(2);
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,1,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[2] = w;
	local[4]= argv[2];
	local[5]= makeflt(0.00000000e+00);
	ctx->vsp=local+6;
	w=(pointer)NUMEQUAL(ctx,2,local+4); /*=*/
	if (w==NIL) goto CON3606;
	if (argv[0]!=NIL) goto IF3607;
	local[4]= argv[1];
	local[5]= argv[1];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,3,local+4); /*list*/
	local[4]= w;
	goto IF3608;
IF3607:
	local[4]= NIL;
IF3608:
	goto CON3605;
CON3606:
	local[4]= local[0];
	local[5]= local[2];
	local[6]= local[3];
	local[7]= argv[0];
	local[8]= makeint(120);
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	w = local[1];
	ctx->vsp=local+8;
	w=FLET3602(ctx,3,local+5,w);
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ROUND(ctx,1,local+4); /*round*/
	local[4]= w;
	local[5]= local[0];
	local[6]= local[2];
	local[7]= local[3];
	local[8]= argv[0];
	w = local[1];
	ctx->vsp=local+9;
	w=FLET3602(ctx,3,local+6,w);
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ROUND(ctx,1,local+5); /*round*/
	local[5]= w;
	local[6]= local[0];
	local[7]= local[2];
	local[8]= local[3];
	local[9]= argv[0];
	local[10]= makeint(120);
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,2,local+9); /*-*/
	local[9]= w;
	w = local[1];
	ctx->vsp=local+10;
	w=FLET3602(ctx,3,local+7,w);
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ROUND(ctx,1,local+6); /*round*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,3,local+4); /*list*/
	local[4]= w;
	goto CON3605;
CON3609:
	local[4]= NIL;
CON3605:
	w = local[4];
	local[0]= w;
BLK3599:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET3602(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)ROUND(ctx,1,local+0); /*round*/
	argv[2] = w;
	local[0]= argv[2];
	local[1]= makeint(360);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF3610;
	local[0]= argv[2];
	local[1]= makeint(360);
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	argv[2] = w;
	local[0]= argv[2];
	goto IF3611;
IF3610:
	local[0]= NIL;
IF3611:
	local[0]= argv[2];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF3612;
	local[0]= argv[2];
	local[1]= makeint(360);
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[2] = w;
	local[0]= argv[2];
	goto IF3613;
IF3612:
	local[0]= NIL;
IF3613:
	local[0]= argv[2];
	local[1]= makeint(60);
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
	local[1]= local[0];
	w = fqv[0];
	if (memq(local[1],w)==NIL) goto IF3615;
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,1,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= makeflt(6.00000000e+01);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[1]= w;
	goto IF3616;
IF3615:
	local[1]= local[0];
	w = fqv[1];
	if (memq(local[1],w)==NIL) goto IF3617;
	local[1]= argv[1];
	goto IF3618;
IF3617:
	local[1]= local[0];
	w = fqv[2];
	if (memq(local[1],w)==NIL) goto IF3619;
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,1,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= makeint(240);
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,1,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= makeflt(6.00000000e+01);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[1]= w;
	goto IF3620;
IF3619:
	local[1]= local[0];
	w = fqv[3];
	if (memq(local[1],w)==NIL) goto IF3621;
	local[1]= argv[0];
	goto IF3622;
IF3621:
	local[1]= NIL;
IF3622:
IF3620:
IF3618:
IF3616:
	w = local[1];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*rgb2hls*/
static pointer F3595rgb2hls(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3625;}
	local[0]= makeflt(2.55000000e+02);
ENT3625:
ENT3624:
	if (n>4) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)EUSFLOAT(ctx,1,local+1); /*float*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	argv[0] = w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)EUSFLOAT(ctx,1,local+1); /*float*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	argv[1] = w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)EUSFLOAT(ctx,1,local+1); /*float*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	argv[2] = w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= argv[0];
	local[11]= argv[1];
	local[12]= argv[2];
	ctx->vsp=local+13;
	w=(pointer)MAX(ctx,3,local+10); /*max*/
	local[4] = w;
	local[10]= argv[0];
	local[11]= argv[1];
	local[12]= argv[2];
	ctx->vsp=local+13;
	w=(pointer)MIN(ctx,3,local+10); /*min*/
	local[5] = w;
	local[10]= local[5];
	{ double x,y;
		y=fltval(local[4]); x=fltval(local[10]);
		local[10]=(makeflt(x + y));}
	local[11]= makeflt(2.00000000e+00);
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[2] = w;
	local[10]= local[2];
	{ double left,right;
		right=fltval(makeflt(0.00000000e+00)); left=fltval(local[10]);
	if (left >= right) goto IF3626;}
	local[10]= makeflt(0.00000000e+00);
	local[11]= makeflt(0.00000000e+00);
	local[12]= makeflt(0.00000000e+00);
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,3,local+10); /*list*/
	ctx->vsp=local+10;
	local[0]=w;
	goto BLK3623;
	goto IF3627;
IF3626:
	local[10]= NIL;
IF3627:
	local[10]= local[4];
	{ double x,y;
		y=fltval(local[5]); x=fltval(local[10]);
		local[10]=(makeflt(x - y));}
	local[9] = local[10];
	local[3] = local[9];
	local[10]= local[3];
	{ double left,right;
		right=fltval(makeflt(0.00000000e+00)); left=fltval(local[10]);
	if (left > right) goto IF3628;}
	local[10]= makeflt(0.00000000e+00);
	local[11]= local[2];
	local[12]= makeflt(0.00000000e+00);
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,3,local+10); /*list*/
	ctx->vsp=local+10;
	local[0]=w;
	goto BLK3623;
	goto IF3629;
IF3628:
	local[10]= NIL;
IF3629:
	local[10]= local[3];
	local[11]= local[2];
	{ double left,right;
		right=fltval(makeflt(5.00000000e-01)); left=fltval(local[11]);
	if (left >= right) goto IF3630;}
	local[11]= local[4];
	{ double x,y;
		y=fltval(local[5]); x=fltval(local[11]);
		local[11]=(makeflt(x + y));}
	goto IF3631;
IF3630:
	local[11]= makeflt(2.00000000e+00);
	local[12]= local[4];
	{ double x,y;
		y=fltval(local[5]); x=fltval(local[12]);
		local[12]=(makeflt(x + y));}
	{ double x,y;
		y=fltval(makeflt(-(fltval(local[12])))); x=fltval(local[11]);
		local[11]=(makeflt(x + y));}
IF3631:
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[3] = w;
	local[10]= local[4];
	{ double x,y;
		y=fltval(makeflt(-(fltval(argv[0])))); x=fltval(local[10]);
		local[10]=(makeflt(x + y));}
	local[11]= local[9];
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[6] = w;
	local[10]= local[4];
	{ double x,y;
		y=fltval(makeflt(-(fltval(argv[1])))); x=fltval(local[10]);
		local[10]=(makeflt(x + y));}
	local[11]= local[9];
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[7] = w;
	local[10]= local[4];
	{ double x,y;
		y=fltval(makeflt(-(fltval(argv[2])))); x=fltval(local[10]);
		local[10]=(makeflt(x + y));}
	local[11]= local[9];
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[8] = w;
	local[10]= argv[0];
	if (local[4]!=local[10]) goto CON3633;
	local[10]= argv[1];
	if (local[5]!=local[10]) goto IF3634;
	local[10]= makeflt(5.00000000e+00);
	{ double x,y;
		y=fltval(local[8]); x=fltval(local[10]);
		local[10]=(makeflt(x + y));}
	goto IF3635;
IF3634:
	local[10]= makeflt(1.00000000e+00);
	{ double x,y;
		y=fltval(local[7]); x=fltval(local[10]);
		local[10]=(makeflt(x - y));}
IF3635:
	local[1] = local[10];
	local[10]= local[1];
	goto CON3632;
CON3633:
	local[10]= argv[1];
	if (local[4]!=local[10]) goto CON3636;
	local[10]= argv[2];
	if (local[5]!=local[10]) goto IF3637;
	local[10]= makeflt(1.00000000e+00);
	{ double x,y;
		y=fltval(local[6]); x=fltval(local[10]);
		local[10]=(makeflt(x + y));}
	goto IF3638;
IF3637:
	local[10]= makeflt(3.00000000e+00);
	{ double x,y;
		y=fltval(local[8]); x=fltval(local[10]);
		local[10]=(makeflt(x - y));}
IF3638:
	local[1] = local[10];
	local[10]= local[1];
	goto CON3632;
CON3636:
	local[10]= argv[0];
	if (local[5]!=local[10]) goto IF3640;
	local[10]= makeflt(3.00000000e+00);
	{ double x,y;
		y=fltval(local[7]); x=fltval(local[10]);
		local[10]=(makeflt(x + y));}
	goto IF3641;
IF3640:
	local[10]= makeflt(5.00000000e+00);
	{ double x,y;
		y=fltval(local[6]); x=fltval(local[10]);
		local[10]=(makeflt(x - y));}
IF3641:
	local[1] = local[10];
	local[10]= local[1];
	goto CON3632;
CON3639:
	local[10]= NIL;
CON3632:
	local[10]= local[1];
	local[11]= makeflt(6.00000000e+00);
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[1] = w;
	local[10]= makeflt(3.60000000e+02);
	{ double x,y;
		y=fltval(local[1]); x=fltval(local[10]);
		local[10]=(makeflt(x * y));}
	local[11]= local[2];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,3,local+10); /*list*/
	local[0]= w;
BLK3623:
	ctx->vsp=local; return(local[0]);}

/*:drawline-primitive*/
static pointer M3642viewsurface_drawline_primitive(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<6) maerror();
	if (n>=7) { local[0]=(argv[6]); goto ENT3645;}
	local[0]= NIL;
ENT3645:
ENT3644:
	if (n>7) maerror();
	local[1]= T;
	local[2]= fqv[4];
	local[3]= argv[2];
	local[4]= argv[5];
	local[5]= argv[4];
	local[6]= argv[5];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,6,local+1); /*format*/
	local[0]= w;
BLK3643:
	ctx->vsp=local; return(local[0]);}

/*:draw-line*/
static pointer M3646viewsurface_draw_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT3649;}
	local[0]= NIL;
ENT3649:
ENT3648:
	if (n>5) maerror();
	local[1]= argv[0];
	local[2]= fqv[5];
	local[3]= argv[2];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= makeint(1);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	local[5]= argv[3];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= argv[3];
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,7,local+1); /*send*/
	local[0]= w;
BLK3647:
	ctx->vsp=local; return(local[0]);}

/*:line-style*/
static pointer M3650viewsurface_line_style(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= local[0];
	if (fqv[6]!=local[1]) goto IF3653;
	local[1]= fqv[7];
	goto IF3654;
IF3653:
	local[1]= local[0];
	if (fqv[8]!=local[1]) goto IF3655;
	local[1]= fqv[9];
	goto IF3656;
IF3655:
	local[1]= NIL;
IF3656:
IF3654:
	w = local[1];
	local[0]= w;
BLK3651:
	ctx->vsp=local; return(local[0]);}

/*:line-width*/
static pointer M3657viewsurface_line_width(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= T;
	local[1]= fqv[10];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK3658:
	ctx->vsp=local; return(local[0]);}

/*:nomethod*/
static pointer M3659viewsurface_nomethod(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3661:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= fqv[11];
	local[2]= local[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,3,local+1,&ftab[0],fqv[12]); /*warn*/
	local[0]= w;
BLK3660:
	ctx->vsp=local; return(local[0]);}

/*:set-erase-mode*/
static pointer M3662viewsurface_set_erase_mode(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = NIL;
	local[0]= w;
BLK3663:
	ctx->vsp=local; return(local[0]);}

/*:set-show-mode*/
static pointer M3664viewsurface_set_show_mode(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = NIL;
	local[0]= w;
BLK3665:
	ctx->vsp=local; return(local[0]);}

/*:flush*/
static pointer M3666viewsurface_flush(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = T;
	local[0]= w;
BLK3667:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3668viewsurface_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3670:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	w = argv[0];
	local[0]= w;
BLK3669:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3671tektro_viewsurface_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3673:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[13], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3674;
	local[1] = makeint(0);
KEY3674:
	if (n & (1<<1)) goto KEY3675;
	local[2] = makeint(768);
KEY3675:
	if (n & (1<<2)) goto KEY3676;
	local[3] = makeint(512);
KEY3676:
	argv[0]->c.obj.iv[3] = local[1];
	argv[0]->c.obj.iv[2] = local[3];
	argv[0]->c.obj.iv[1] = local[3];
	w = argv[0];
	local[0]= w;
BLK3672:
	ctx->vsp=local; return(local[0]);}

/*:clear*/
static pointer M3677tektro_viewsurface_clear(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	w=(pointer)F3597tektro_clear(ctx,0,local+0); /*tektro-clear*/
	local[0]= w;
BLK3678:
	ctx->vsp=local; return(local[0]);}

/*:width*/
static pointer M3679tektro_viewsurface_width(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3682;}
	local[0]= NIL;
ENT3682:
ENT3681:
	if (n>3) maerror();
	w = local[0];
	if (!isnum(w)) goto IF3683;
	argv[0]->c.obj.iv[1] = local[0];
	local[1]= argv[0]->c.obj.iv[1];
	goto IF3684;
IF3683:
	local[1]= NIL;
IF3684:
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK3680:
	ctx->vsp=local; return(local[0]);}

/*:height*/
static pointer M3685tektro_viewsurface_height(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3688;}
	local[0]= NIL;
ENT3688:
ENT3687:
	if (n>3) maerror();
	w = local[0];
	if (!isnum(w)) goto IF3689;
	argv[0]->c.obj.iv[2] = local[0];
	local[1]= argv[0]->c.obj.iv[2];
	goto IF3690;
IF3689:
	local[1]= NIL;
IF3690:
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK3686:
	ctx->vsp=local; return(local[0]);}

/*:resize*/
static pointer M3691tektro_viewsurface_resize(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[14];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[15];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3692:
	ctx->vsp=local; return(local[0]);}

/*:drawline-primitive*/
static pointer M3693tektro_viewsurface_drawline_primitive(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<6) maerror();
	if (n>=7) { local[0]=(argv[6]); goto ENT3696;}
	local[0]= NIL;
ENT3696:
ENT3695:
	if (n>7) maerror();
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)ROUND(ctx,1,local+1); /*round*/
	local[1]= w;
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)ROUND(ctx,1,local+2); /*round*/
	local[2]= w;
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)ROUND(ctx,1,local+3); /*round*/
	local[3]= w;
	local[4]= argv[5];
	ctx->vsp=local+5;
	w=(pointer)ROUND(ctx,1,local+4); /*round*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)F3596tektro_showline(ctx,4,local+1); /*tektro-showline*/
	local[0]= w;
BLK3694:
	ctx->vsp=local; return(local[0]);}

/*tektro-showline*/
static pointer F3596tektro_showline(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	if (loadglobal(fqv[16])==NIL) goto IF3698;
	local[0]= T;
	local[1]= fqv[17];
	local[2]= argv[0];
	local[3]= argv[1];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,6,local+0); /*format*/
	local[0]= w;
	goto IF3699;
IF3698:
	local[0]= NIL;
IF3699:
	local[0]= loadglobal(fqv[18]);
	local[1]= makeint(1);
	local[2]= makeint(32);
	local[3]= argv[1];
	local[4]= makeint(32);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[18]);
	local[1]= makeint(2);
	local[2]= makeint(96);
	local[3]= argv[1];
	local[4]= makeint(32);
	ctx->vsp=local+5;
	w=(pointer)MOD(ctx,2,local+3); /*mod*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[18]);
	local[1]= makeint(3);
	local[2]= makeint(32);
	local[3]= argv[0];
	local[4]= makeint(32);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[18]);
	local[1]= makeint(4);
	local[2]= makeint(64);
	local[3]= argv[0];
	local[4]= makeint(32);
	ctx->vsp=local+5;
	w=(pointer)MOD(ctx,2,local+3); /*mod*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[18]);
	local[1]= makeint(5);
	local[2]= makeint(32);
	local[3]= argv[3];
	local[4]= makeint(32);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[18]);
	local[1]= makeint(6);
	local[2]= makeint(96);
	local[3]= argv[3];
	local[4]= makeint(32);
	ctx->vsp=local+5;
	w=(pointer)MOD(ctx,2,local+3); /*mod*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[18]);
	local[1]= makeint(7);
	local[2]= makeint(32);
	local[3]= argv[2];
	local[4]= makeint(32);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[18]);
	local[1]= makeint(8);
	local[2]= makeint(64);
	local[3]= argv[2];
	local[4]= makeint(32);
	ctx->vsp=local+5;
	w=(pointer)MOD(ctx,2,local+3); /*mod*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[18]);
	local[1]= loadglobal(fqv[19]);
	ctx->vsp=local+2;
	w=(pointer)PRINC(ctx,2,local+0); /*princ*/
	w = T;
	local[0]= w;
BLK3697:
	ctx->vsp=local; return(local[0]);}

/*tektro-clear*/
static pointer F3597tektro_clear(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT3702;}
	local[0]= loadglobal(fqv[19]);
ENT3702:
ENT3701:
	if (n>1) maerror();
	local[1]= makeint(27);
	local[2]= makeint(12);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)WRTBYTE(ctx,2,local+1); /*write-byte*/
	local[0]= w;
BLK3700:
	ctx->vsp=local; return(local[0]);}

/*tektro*/
static pointer F3703(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST3705:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[20];
	local[2]= fqv[19];
	local[3]= argv[0];
	local[4]= fqv[21];
	local[5]= fqv[22];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= local[0];
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)APPEND(ctx,2,local+3); /*append*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK3704:
	ctx->vsp=local; return(local[0]);}

/*default-viewsurface*/
static pointer F3598default_viewsurface(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST3707:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= (pointer)get_sym_func(fqv[23]);
	local[2]= loadglobal(fqv[24]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= fqv[25];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[0]= w;
BLK3706:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___viewsurface(ctx,n,argv,env)
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
	local[0]= fqv[26];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF3708;
	local[0]= fqv[27];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[28],w);
	goto IF3709;
IF3708:
	local[0]= fqv[29];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF3709:
	local[0]= fqv[30];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[31],module,F3594hls2rgb,fqv[32]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[33],module,F3595rgb2hls,fqv[34]);
	local[0]= fqv[35];
	local[1]= fqv[36];
	local[2]= fqv[35];
	local[3]= fqv[37];
	local[4]= loadglobal(fqv[38]);
	local[5]= fqv[39];
	local[6]= fqv[40];
	local[7]= fqv[41];
	local[8]= NIL;
	local[9]= fqv[42];
	local[10]= NIL;
	local[11]= fqv[43];
	local[12]= makeint(-1);
	local[13]= fqv[44];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[45]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3642viewsurface_drawline_primitive,fqv[5],fqv[35],fqv[46]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3646viewsurface_draw_line,fqv[47],fqv[35],fqv[48]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3650viewsurface_line_style,fqv[49],fqv[35],fqv[50]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3657viewsurface_line_width,fqv[51],fqv[35],fqv[52]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3659viewsurface_nomethod,fqv[53],fqv[35],fqv[54]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3662viewsurface_set_erase_mode,fqv[55],fqv[35],fqv[56]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3664viewsurface_set_show_mode,fqv[57],fqv[35],fqv[58]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3666viewsurface_flush,fqv[59],fqv[35],fqv[60]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3668viewsurface_init,fqv[25],fqv[35],fqv[61]);
	local[0]= fqv[24];
	local[1]= fqv[36];
	local[2]= fqv[24];
	local[3]= fqv[37];
	local[4]= loadglobal(fqv[35]);
	local[5]= fqv[39];
	local[6]= fqv[62];
	local[7]= fqv[41];
	local[8]= NIL;
	local[9]= fqv[42];
	local[10]= NIL;
	local[11]= fqv[43];
	local[12]= makeint(-1);
	local[13]= fqv[44];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[1])(ctx,13,local+2,&ftab[1],fqv[45]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3671tektro_viewsurface_init,fqv[25],fqv[24],fqv[63]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3677tektro_viewsurface_clear,fqv[64],fqv[24],fqv[65]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3679tektro_viewsurface_width,fqv[14],fqv[24],fqv[66]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3685tektro_viewsurface_height,fqv[15],fqv[24],fqv[67]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3691tektro_viewsurface_resize,fqv[68],fqv[24],fqv[69]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3693tektro_viewsurface_drawline_primitive,fqv[5],fqv[24],fqv[70]);
	local[0]= fqv[18];
	local[1]= fqv[71];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3710;
	local[0]= fqv[18];
	local[1]= fqv[71];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[18];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3712;
	local[0]= fqv[18];
	local[1]= fqv[36];
	local[2]= fqv[72];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3713;
IF3712:
	local[0]= NIL;
IF3713:
	local[0]= fqv[18];
	goto IF3711;
IF3710:
	local[0]= NIL;
IF3711:
	local[0]= loadglobal(fqv[18]);
	local[1]= makeint(0);
	local[2]= makeint(29);
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[18]);
	local[1]= makeint(9);
	local[2]= makeint(31);
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= fqv[19];
	local[1]= fqv[71];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3714;
	local[0]= fqv[19];
	local[1]= fqv[71];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[19];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3716;
	local[0]= fqv[19];
	local[1]= fqv[36];
	local[2]= T;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3717;
IF3716:
	local[0]= NIL;
IF3717:
	local[0]= fqv[19];
	goto IF3715;
IF3714:
	local[0]= NIL;
IF3715:
	ctx->vsp=local+0;
	compfun(ctx,fqv[73],module,F3596tektro_showline,fqv[74]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[75],module,F3597tektro_clear,fqv[76]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[77],module,F3703,fqv[78]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[79],module,F3598default_viewsurface,fqv[80]);
	local[0]= fqv[81];
	local[1]= fqv[82];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[83]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<3; i++) ftab[i]=fcallx;
}
