/* ./toplevel.c :  entry=toplevel */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "toplevel.h"
#pragma init (register_toplevel)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___toplevel();
extern pointer build_quote_vector();
static int register_toplevel()
  { add_module_initializer("___toplevel", ___toplevel);}

static pointer F69993count_up_timer();
static pointer F69996skip_blank();
static pointer F70000read_list_from_line();
static pointer F70003sigint_handler();
static pointer F70007eussig();
static pointer F70010evaluate_stream();
static pointer F70013toplevel_prompt();
static pointer F70016rep1();
static pointer F70019prompt();
static pointer F70022reploop_non_select();
static pointer F70025repsel();
static pointer F70028reploop_select();
static pointer F70031reploop();
static pointer F70034euserror();
static pointer F70037eustop();
static pointer F70040reset();

/*count-up-timer*/
static pointer F69993count_up_timer(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= loadglobal(fqv[0]);
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	local[0]= w;
	storeglobal(fqv[0],w);
	w = local[0];
	local[0]= w;
BLK70114:
	ctx->vsp=local; return(local[0]);}

/*skip-blank*/
static pointer F69996skip_blank(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT70136;}
	ctx->vsp=local+0;
	w=(pointer)GENSYM(ctx,0,local+0); /*gensym*/
	local[0]= w;
ENT70136:
ENT70135:
	if (n>2) maerror();
	local[1]= argv[0];
	local[2]= NIL;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)READCH(ctx,3,local+1); /*read-char*/
	local[1]= w;
	local[2]= local[1];
	if (local[0]!=local[2]) goto IF70166;
	w = local[0];
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK70133;
	goto IF70167;
IF70166:
	local[2]= NIL;
IF70167:
WHL70178:
	local[2]= local[1];
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,2,local+2,&ftab[0],fqv[2]); /*position*/
	if (w==NIL) goto WHX70179;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)READCH(ctx,1,local+2); /*read-char*/
	local[1] = w;
	goto WHL70178;
WHX70179:
	local[2]= NIL;
BLK70180:
	local[2]= local[1];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)UNREADCH(ctx,2,local+2); /*unread-char*/
	w = local[1];
	local[0]= w;
BLK70133:
	ctx->vsp=local; return(local[0]);}

/*read-list-from-line*/
static pointer F70000read_list_from_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT70213;}
	local[0]= loadglobal(fqv[3]);
ENT70213:
	if (n>=2) { local[1]=(argv[1]); goto ENT70212;}
	ctx->vsp=local+1;
	w=(pointer)GENSYM(ctx,0,local+1); /*gensym*/
	local[1]= w;
ENT70212:
ENT70211:
	if (n>2) maerror();
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)F69996skip_blank(ctx,2,local+6); /*skip-blank*/
	local[2] = w;
	local[6]= NIL;
	storeglobal(fqv[4],local[6]);
	local[6]= local[2];
	if (local[1]!=local[6]) goto CON70261;
	local[6]= local[1];
	goto CON70259;
CON70261:
	local[6]= local[2];
	if (makeint(40)!=local[6]) goto CON70268;
	local[6]= local[0];
	local[7]= NIL;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)READ(ctx,3,local+6); /*read*/
	local[4] = w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)READCH(ctx,1,local+6); /*read-char*/
	local[2] = w;
	local[6]= local[2];
	local[7]= makeint(10);
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w!=NIL) goto IF70294;
	local[6]= local[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)UNREADCH(ctx,2,local+6); /*unread-char*/
	local[6]= w;
	goto IF70295;
IF70294:
	local[6]= NIL;
IF70295:
	local[6]= local[4];
	goto CON70259;
CON70268:
	local[6]= local[2];
	if (makeint(44)!=local[6]) goto CON70310;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)READCH(ctx,1,local+6); /*read-char*/
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)READ(ctx,1,local+6); /*read*/
	local[4] = w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)READCH(ctx,1,local+6); /*read-char*/
	local[6]= local[4];
	goto CON70259;
CON70310:
	local[6]= local[0];
	local[7]= NIL;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)READLINE(ctx,3,local+6); /*read-line*/
	local[6]= w;
	storeglobal(fqv[4],w);
	local[6]= loadglobal(fqv[4]);
	if (local[1]!=local[6]) goto IF70346;
	w = local[1];
	ctx->vsp=local+6;
	local[0]=w;
	goto BLK70209;
	goto IF70347;
IF70346:
	local[6]= NIL;
IF70347:
	local[6]= loadglobal(fqv[4]);
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,1,local+6,&ftab[1],fqv[5]); /*make-string-input-stream*/
	local[6]= w;
	goto CON70259;
CON70333:
	local[6]= NIL;
CON70259:
	w = local[6];
	local[0]= w;
BLK70209:
	ctx->vsp=local; return(local[0]);}

/*sigint-handler*/
static pointer F70003sigint_handler(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(1);
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[7]); /*warning-message*/
	local[0]= fqv[8];
	ctx->vsp=local+1;
	w=(pointer)FBOUNDP(ctx,1,local+0); /*fboundp*/
	if (w==NIL) goto IF70381;
	local[0]= makeint(0);
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,2,local+0,&ftab[3],fqv[8]); /*unix:ualarm*/
	local[0]= w;
	goto IF70382;
IF70381:
	local[0]= makeint(0);
	ctx->vsp=local+1;
	w=(pointer)ALARM(ctx,1,local+0); /*unix:alarm*/
	local[0]= w;
IF70382:
	local[0]= loadglobal(fqv[9]);
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	local[0]= w;
	w = local[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[9],w);
	local[3]= fqv[10];
	w = local[3];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[11],w);
	{jmp_buf jb;
	w = loadglobal(fqv[9]);
	ctx->vsp=local+6;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT70412;}
	local[12]= (pointer)get_sym_func(fqv[12]);
	ctx->vsp=local+13;
	w=(pointer)F70031reploop(ctx,1,local+12); /*reploop*/
CAT70412:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[6]= w;
	ctx->vsp=local+7;
	unbindx(ctx,2);
	w = local[6];
	local[0]= w;
BLK70365:
	ctx->vsp=local; return(local[0]);}

/*eussig*/
static pointer F70007eussig(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST70430:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= NIL;
	local[2]= loadglobal(fqv[13]);
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	if (local[2]==NIL) goto CON70452;
	local[3]= local[2];
	local[4]= argv[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)FUNCALL(ctx,3,local+3); /*funcall*/
	local[3]= w;
	goto CON70450;
CON70452:
	local[3]= fqv[8];
	ctx->vsp=local+4;
	w=(pointer)FBOUNDP(ctx,1,local+3); /*fboundp*/
	if (w==NIL) goto IF70466;
	local[3]= makeint(0);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(*ftab[3])(ctx,2,local+3,&ftab[3],fqv[8]); /*unix:ualarm*/
	local[3]= w;
	goto IF70467;
IF70466:
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)ALARM(ctx,1,local+3); /*unix:alarm*/
	local[3]= w;
IF70467:
	local[3]= makeint(1);
	local[4]= fqv[14];
	local[5]= argv[0];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[2])(ctx,4,local+3,&ftab[2],fqv[7]); /*warning-message*/
	local[3]= loadglobal(fqv[9]);
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[3]= w;
	w = local[3];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[9],w);
	local[6]= fqv[15];
	w = local[6];
	ctx->vsp=local+6;
	bindspecial(ctx,fqv[11],w);
	{jmp_buf jb;
	w = loadglobal(fqv[9]);
	ctx->vsp=local+9;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT70500;}
	local[15]= (pointer)get_sym_func(fqv[12]);
	ctx->vsp=local+16;
	w=(pointer)F70031reploop(ctx,1,local+15); /*reploop*/
CAT70500:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[9]= w;
	ctx->vsp=local+10;
	unbindx(ctx,2);
	w = local[9];
	local[3]= w;
	goto CON70450;
CON70462:
	local[3]= NIL;
CON70450:
	w = local[3];
	local[0]= w;
BLK70428:
	ctx->vsp=local; return(local[0]);}

/*evaluate-stream*/
static pointer F70010evaluate_stream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	w = NIL;
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	local[1]= argv[0];
	local[2]= NIL;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)READ(ctx,3,local+1); /*read*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= local[1];
	local[5]= ((local[0])==(local[5])?T:NIL);
	if (local[5]!=NIL) goto CON70547;
CON70549:
	w = local[1];
	if (!issymbol(w)) goto CON70557;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)FBOUNDP(ctx,1,local+5); /*fboundp*/
	if (w==NIL) goto CON70565;
	local[2] = NIL;
WHL70579:
	local[5]= argv[0];
	local[6]= NIL;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)READ(ctx,3,local+5); /*read*/
	local[3] = w;
	local[5]= local[3];
	if (local[0]==local[5]) goto WHX70580;
	local[5]= local[3];
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	goto WHL70579;
WHX70580:
	local[5]= NIL;
BLK70581:
	local[5]= local[1];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)NREVERSE(ctx,1,local+6); /*nreverse*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	storeglobal(fqv[16],local[5]);
	local[5]= loadglobal(fqv[16]);
	ctx->vsp=local+6;
	w=(pointer)EVAL(ctx,1,local+5); /*eval*/
	local[4] = w;
	local[5]= local[4];
	goto CON70563;
CON70565:
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)BOUNDP(ctx,1,local+5); /*boundp*/
	if (w==NIL) goto CON70627;
	local[5]= argv[0];
	local[6]= NIL;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)READ(ctx,3,local+5); /*read*/
	local[5]= w;
	if (local[0]!=local[5]) goto CON70627;
	local[5]= local[1];
	storeglobal(fqv[16],local[5]);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)EVAL(ctx,1,local+5); /*eval*/
	local[4] = w;
	local[5]= local[4];
	goto CON70563;
CON70627:
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,1,local+5,&ftab[4],fqv[17]); /*string*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)FINDPACKAGE(ctx,1,local+5); /*find-package*/
	if (w==NIL) goto CON70656;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,1,local+5,&ftab[4],fqv[17]); /*string*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)FINDPACKAGE(ctx,1,local+5); /*find-package*/
	if (w==NIL) goto IF70668;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,1,local+5,&ftab[4],fqv[17]); /*string*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)FINDPACKAGE(ctx,1,local+5); /*find-package*/
	local[5]= w;
	storeglobal(fqv[18],w);
	goto IF70669;
IF70668:
	local[5]= fqv[19];
	ctx->vsp=local+6;
	w=(pointer)SIGERROR(ctx,1,local+5); /*error*/
	local[5]= w;
IF70669:
	goto CON70563;
CON70656:
	if (loadglobal(fqv[20])==NIL) goto CON70689;
	local[5]= fqv[21];
	local[6]= *(ovafptr(argv[0],fqv[22]));
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,2,local+5); /*list*/
	local[5]= w;
	storeglobal(fqv[16],w);
	local[5]= *(ovafptr(argv[0],fqv[22]));
	ctx->vsp=local+6;
	w=(pointer)SYSTEM(ctx,1,local+5); /*unix:system*/
	local[4] = w;
	local[5]= local[4];
	goto CON70563;
CON70689:
	local[5]= fqv[23];
	ctx->vsp=local+6;
	w=(*ftab[5])(ctx,1,local+5,&ftab[5],fqv[24]); /*warn*/
	local[5]= w;
	goto CON70563;
CON70715:
	local[5]= NIL;
CON70563:
	goto CON70547;
CON70557:
	local[5]= local[1];
	storeglobal(fqv[16],local[5]);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)EVAL(ctx,1,local+5); /*eval*/
	local[4] = w;
	local[5]= local[4];
	goto CON70547;
CON70721:
	local[5]= NIL;
CON70547:
	w = local[4];
	local[0]= w;
BLK70514:
	ctx->vsp=local; return(local[0]);}

/*toplevel-prompt*/
static pointer F70013toplevel_prompt(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	if (loadglobal(fqv[25])==NIL) goto IF70755;
	local[0]= argv[0];
	local[1]= fqv[26];
	local[2]= loadglobal(fqv[27]);
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto IF70756;
IF70755:
	local[0]= NIL;
IF70756:
	local[0]= loadglobal(fqv[9]);
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF70770;
	local[0]= argv[0];
	local[1]= fqv[28];
	local[2]= loadglobal(fqv[11]);
	local[3]= loadglobal(fqv[9]);
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
	goto IF70771;
IF70770:
	local[0]= NIL;
IF70771:
	local[0]= loadglobal(fqv[18]);
	local[1]= loadglobal(fqv[29]);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w!=NIL) goto IF70783;
	local[0]= argv[0];
	local[1]= fqv[30];
	local[2]= loadglobal(fqv[18]);
	ctx->vsp=local+3;
	w=(*ftab[6])(ctx,1,local+2,&ftab[6],fqv[31]); /*package-name*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto IF70784;
IF70783:
	local[0]= NIL;
IF70784:
	local[0]= argv[0];
	local[1]= fqv[32];
	local[2]= loadglobal(fqv[33]);
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK70745:
	ctx->vsp=local; return(local[0]);}

/*rep1*/
static pointer F70016rep1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT70811;}
	local[0]= T;
ENT70811:
ENT70810:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)F70000read_list_from_line(ctx,2,local+1); /*read-list-from-line*/
	local[1]= w;
	local[2]= NIL;
	local[3]= local[1];
	if (argv[1]!=local[3]) goto IF70845;
	w = argv[1];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK70808;
	goto IF70846;
IF70845:
	local[3]= NIL;
IF70846:
	if (local[1]==NIL) goto IF70858;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)STREAMP(ctx,1,local+3); /*streamp*/
	if (w==NIL) goto OR70864;
	local[3]= local[1];
	local[4]= fqv[34];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	w = makeint(0);
	if ((eusinteger_t)local[3] > (eusinteger_t)w) goto OR70864;
	goto IF70858;
OR70864:
	if (loadglobal(fqv[25])==NIL) goto IF70885;
	w = local[1];
	if (!iscons(w)) goto CON70897;
	local[3]= NIL;
	local[4]= fqv[35];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= w;
	goto CON70895;
CON70897:
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)STREAMP(ctx,1,local+3); /*streamp*/
	if (w==NIL) goto CON70905;
	local[3]= local[1];
	local[4]= fqv[34];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	goto CON70895;
CON70905:
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,1,local+3,&ftab[4],fqv[17]); /*string*/
	local[3]= w;
	goto CON70895;
CON70917:
	local[3]= NIL;
CON70895:
	ctx->vsp=local+4;
	w=(*ftab[7])(ctx,1,local+3,&ftab[7],fqv[36]); /*add-history*/
	local[3]= w;
	goto IF70886;
IF70885:
	local[3]= NIL;
IF70886:
	if (loadglobal(fqv[37])==NIL) goto IF70927;
	local[3]= loadglobal(fqv[37]);
	ctx->vsp=local+4;
	w=(pointer)FUNCALL(ctx,1,local+3); /*funcall*/
	local[3]= w;
	goto IF70928;
IF70927:
	local[3]= NIL;
IF70928:
	goto IF70859;
IF70858:
	local[3]= NIL;
IF70859:
	if (local[1]!=NIL) goto CON70940;
	local[3]= NIL;
	goto CON70938;
CON70940:
	w = local[1];
	if (!issymbol(w)) goto CON70945;
	storeglobal(fqv[16],local[1]);
	local[3]= loadglobal(fqv[9]);
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)GREATERP(ctx,2,local+3); /*>*/
	if (w==NIL) goto CON70958;
	local[3]= local[1];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(*ftab[8])(ctx,2,local+3,&ftab[8],fqv[38]); /*eval-dynamic*/
	local[3]= w;
	goto CON70956;
CON70958:
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)BOUNDP(ctx,1,local+3); /*boundp*/
	if (w==NIL) goto CON70968;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)EVAL(ctx,1,local+3); /*eval*/
	local[3]= w;
	goto CON70956;
CON70968:
	local[3]= fqv[39];
	goto CON70956;
CON70978:
	local[3]= NIL;
CON70956:
	local[2] = local[3];
	local[3]= local[2];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)PRINT(ctx,2,local+3); /*print*/
	local[3]= w;
	goto CON70938;
CON70945:
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)STREAMP(ctx,1,local+3); /*streamp*/
	if (w==NIL) goto OR70991;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)LISTP(ctx,1,local+3); /*listp*/
	if (w!=NIL) goto OR70991;
	goto CON70990;
OR70991:
	local[3]= local[1];
	storeglobal(fqv[16],local[3]);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)EVAL(ctx,1,local+3); /*eval*/
	local[2] = w;
	local[3]= local[2];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)PRINT(ctx,2,local+3); /*print*/
	local[3]= w;
	goto CON70938;
CON70990:
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)STREAMP(ctx,1,local+3); /*streamp*/
	if (w==NIL) goto CON71023;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F70010evaluate_stream(ctx,1,local+3); /*evaluate-stream*/
	local[2] = w;
	local[3]= local[2];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)PRINT(ctx,2,local+3); /*print*/
	local[3]= w;
	goto CON70938;
CON71023:
	local[3]= fqv[40];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)PRINT(ctx,2,local+3); /*print*/
	local[3]= w;
	goto CON70938;
CON71043:
	local[3]= NIL;
CON70938:
	storeglobal(fqv[42],loadglobal(fqv[41]));
	storeglobal(fqv[41],loadglobal(fqv[43]));
	local[3]= loadglobal(fqv[16]);
	storeglobal(fqv[43],local[3]);
	storeglobal(fqv[45],loadglobal(fqv[44]));
	storeglobal(fqv[44],loadglobal(fqv[46]));
	local[3]= local[2];
	storeglobal(fqv[46],local[3]);
	w = local[3];
	local[0]= w;
BLK70808:
	ctx->vsp=local; return(local[0]);}

/*prompt*/
static pointer F70019prompt(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = loadglobal(fqv[47]);
	if (!isstring(w)) goto CON71095;
	local[0]= loadglobal(fqv[47]);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)PRINC(ctx,2,local+0); /*princ*/
	local[0]= w;
	goto CON71093;
CON71095:
	local[0]= loadglobal(fqv[47]);
	ctx->vsp=local+1;
	w=(*ftab[9])(ctx,1,local+0,&ftab[9],fqv[48]); /*functionp*/
	if (w==NIL) goto CON71105;
	local[0]= loadglobal(fqv[47]);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)FUNCALL(ctx,2,local+0); /*funcall*/
	local[0]= w;
	goto CON71093;
CON71105:
	local[0]= argv[0];
	local[1]= fqv[49];
	local[2]= loadglobal(fqv[33]);
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto CON71093;
CON71117:
	local[0]= NIL;
CON71093:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FINOUT(ctx,1,local+0); /*finish-output*/
	local[0]= w;
BLK71083:
	ctx->vsp=local; return(local[0]);}

/*reploop-non-select*/
static pointer F70022reploop_non_select(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT71135;}
	local[0]= loadglobal(fqv[50]);
ENT71135:
	if (n>=2) { local[1]=(argv[1]); goto ENT71134;}
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)ISATTY(ctx,1,local+1); /*unix:isatty*/
	local[1]= w;
ENT71134:
ENT71133:
	if (n>2) maerror();
	local[2]= fqv[51];
	w = local[2];
	ctx->vsp=local+2;
	bindspecial(ctx,fqv[52],w);
	ctx->vsp=local+5;
	w=(pointer)GENSYM(ctx,0,local+5); /*gensym*/
	local[5]= w;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= loadglobal(fqv[9]);
	local[10]= makeint(0);
	ctx->vsp=local+11;
	w=(pointer)GREATERP(ctx,2,local+9); /*>*/
	if (w==NIL) goto IF71177;
	ctx->vsp=local+9;
	w=(pointer)LISTBINDINGS(ctx,0,local+9); /*system:list-all-bindings*/
	local[7] = w;
	local[9]= local[7];
	goto IF71178;
IF71177:
	local[9]= NIL;
IF71178:
WHL71191:
	if (T==NIL) goto WHX71192;
	{jmp_buf jb;
	w = fqv[53];
	ctx->vsp=local+9;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT71198;}
	if (local[1]==NIL) goto IF71205;
	local[15]= local[0];
	ctx->vsp=local+16;
	w=(pointer)F70019prompt(ctx,1,local+15); /*prompt*/
	local[15]= w;
	goto IF71206;
IF71205:
	local[15]= NIL;
IF71206:
	local[15]= local[0];
	local[16]= local[5];
	local[17]= local[7];
	local[18]= local[1];
	ctx->vsp=local+19;
	w=(pointer)F70016rep1(ctx,4,local+15); /*rep1*/
	local[15]= w;
	local[16]= local[5];
	ctx->vsp=local+17;
	w=(pointer)EQ(ctx,2,local+15); /*eql*/
	if (w==NIL) goto IF71215;
	w = NIL;
	ctx->vsp=local+15;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK71131;
	goto IF71216;
IF71215:
	local[15]= NIL;
IF71216:
	w = local[15];
CAT71198:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	goto WHL71191;
WHX71192:
	local[9]= NIL;
BLK71193:
	ctx->vsp=local+10;
	unbindx(ctx,1);
	w = local[9];
	local[0]= w;
BLK71131:
	ctx->vsp=local; return(local[0]);}

/*repsel*/
static pointer F70025repsel(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= argv[3];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)F70016rep1(ctx,4,local+0); /*rep1*/
	local[0]= w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF71252;
	local[0]= fqv[54];
	w = NIL;
	ctx->vsp=local+1;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	goto IF71253;
IF71252:
	local[0]= NIL;
IF71253:
	if (argv[2]==NIL) goto IF71272;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F70019prompt(ctx,1,local+0); /*prompt*/
	local[0]= w;
	goto IF71273;
IF71272:
	local[0]= NIL;
IF71273:
	w = local[0];
	local[0]= w;
BLK71236:
	ctx->vsp=local; return(local[0]);}

/*reploop-select*/
static pointer F70028reploop_select(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT71287;}
	local[0]= loadglobal(fqv[50]);
ENT71287:
	if (n>=2) { local[1]=(argv[1]); goto ENT71286;}
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)ISATTY(ctx,1,local+1); /*unix:isatty*/
	local[1]= w;
ENT71286:
ENT71285:
	if (n>2) maerror();
	local[2]= fqv[51];
	w = local[2];
	ctx->vsp=local+2;
	bindspecial(ctx,fqv[52],w);
	ctx->vsp=local+5;
	w=(pointer)GENSYM(ctx,0,local+5); /*gensym*/
	local[5]= w;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	if (local[1]==NIL) goto IF71328;
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)F70019prompt(ctx,1,local+9); /*prompt*/
	local[9]= w;
	goto IF71329;
IF71328:
	local[9]= NIL;
IF71329:
	local[9]= loadglobal(fqv[9]);
	local[10]= makeint(0);
	ctx->vsp=local+11;
	w=(pointer)GREATERP(ctx,2,local+9); /*>*/
	if (w==NIL) goto IF71338;
	ctx->vsp=local+9;
	w=(pointer)LISTBINDINGS(ctx,0,local+9); /*system:list-all-bindings*/
	local[7] = w;
	local[9]= local[7];
	goto IF71339;
IF71338:
	local[9]= NIL;
IF71339:
	local[9]= loadglobal(fqv[55]);
	local[10]= fqv[56];
	local[11]= local[0];
	local[12]= fqv[57];
	local[13]= local[0];
	local[14]= local[5];
	local[15]= local[1];
	local[16]= local[7];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,8,local+9); /*send*/
	{jmp_buf jb;
	w = fqv[54];
	ctx->vsp=local+9;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT71366;}
WHL71373:
	if (T==NIL) goto WHX71374;
	local[15]= loadglobal(fqv[55]);
	local[16]= fqv[58];
	local[17]= loadglobal(fqv[59]);
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,3,local+15); /*send*/
	if (w!=NIL) goto IF71381;
	local[15]= loadglobal(fqv[60]);
	ctx->vsp=local+16;
	w=(*ftab[9])(ctx,1,local+15,&ftab[9],fqv[48]); /*functionp*/
	if (w==NIL) goto IF71396;
	local[15]= loadglobal(fqv[60]);
	ctx->vsp=local+16;
	w=(pointer)FUNCALL(ctx,1,local+15); /*funcall*/
	local[15]= w;
	goto IF71397;
IF71396:
	local[15]= NIL;
	local[16]= loadglobal(fqv[60]);
WHL71425:
	if (local[16]==NIL) goto WHX71426;
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17]= (w)->c.cons.car;
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16] = (w)->c.cons.cdr;
	w = local[17];
	local[15] = w;
	local[17]= local[15];
	ctx->vsp=local+18;
	w=(*ftab[9])(ctx,1,local+17,&ftab[9],fqv[48]); /*functionp*/
	if (w==NIL) goto IF71474;
	local[17]= local[15];
	ctx->vsp=local+18;
	w=(pointer)FUNCALL(ctx,1,local+17); /*funcall*/
	local[17]= w;
	goto IF71475;
IF71474:
	local[17]= NIL;
IF71475:
	goto WHL71425;
WHX71426:
	local[17]= NIL;
BLK71427:
	w = NIL;
	local[15]= w;
IF71397:
	goto IF71382;
IF71381:
	local[15]= NIL;
IF71382:
	goto WHL71373;
WHX71374:
	local[15]= NIL;
BLK71375:
	w = local[15];
CAT71366:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[9]= w;
	ctx->vsp=local+10;
	unbindx(ctx,1);
	w = local[9];
	local[0]= w;
BLK71283:
	ctx->vsp=local; return(local[0]);}

/*reploop*/
static pointer F70031reploop(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT71496;}
	local[0]= loadglobal(fqv[50]);
ENT71496:
	if (n>=3) { local[1]=(argv[2]); goto ENT71495;}
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)ISATTY(ctx,1,local+1); /*unix:isatty*/
	local[1]= w;
ENT71495:
ENT71494:
	if (n>3) maerror();
	local[2]= argv[0];
	w = local[2];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[47],w);
	if (loadglobal(fqv[61])==NIL) goto IF71532;
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)F70028reploop_select(ctx,2,local+6); /*reploop-select*/
	local[6]= w;
	goto IF71533;
IF71532:
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)F70022reploop_non_select(ctx,2,local+6); /*reploop-non-select*/
	local[6]= w;
IF71533:
	ctx->vsp=local+7;
	unbindx(ctx,1);
	w = local[6];
	local[0]= w;
BLK71492:
	ctx->vsp=local; return(local[0]);}

/*euserror*/
static pointer F70034euserror(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT71553;}
	local[0]= NIL;
ENT71553:
ENT71552:
	if (n>4) maerror();
	local[1]= loadglobal(fqv[62]);
	local[2]= fqv[63];
	local[3]= makeint(27);
	local[4]= makeint(1);
	w = makeint(48);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[4]= (pointer)((eusinteger_t)local[4] + (eusinteger_t)w);
	local[5]= loadglobal(fqv[64]);
	ctx->vsp=local+6;
	w=(pointer)THR_SELF(ctx,0,local+6); /*unix:thr-self*/
	local[6]= w;
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,7,local+1); /*format*/
	if (local[0]==NIL) goto IF71586;
	local[1]= loadglobal(fqv[62]);
	local[2]= fqv[65];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	goto IF71587;
IF71586:
	local[1]= NIL;
IF71587:
	if (argv[2]==NIL) goto IF71597;
	local[1]= loadglobal(fqv[62]);
	local[2]= fqv[66];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	goto IF71598;
IF71597:
	local[1]= NIL;
IF71598:
	local[1]= loadglobal(fqv[62]);
	local[2]= fqv[67];
	local[3]= makeint(27);
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= loadglobal(fqv[9]);
	ctx->vsp=local+2;
	w=(pointer)ADD1(ctx,1,local+1); /*1+*/
	local[1]= w;
	local[2]= fqv[68];
	w = local[2];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[11],w);
	w = local[1];
	ctx->vsp=local+6;
	bindspecial(ctx,fqv[9],w);
	{jmp_buf jb;
	w = loadglobal(fqv[9]);
	ctx->vsp=local+9;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT71634;}
	local[15]= (pointer)get_sym_func(fqv[12]);
	ctx->vsp=local+16;
	w=(pointer)F70031reploop(ctx,1,local+15); /*reploop*/
CAT71634:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[9]= w;
	ctx->vsp=local+10;
	unbindx(ctx,2);
	w = local[9];
	local[1]= loadglobal(fqv[9]);
	w = NIL;
	ctx->vsp=local+2;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	w = local[1];
	local[0]= w;
BLK71550:
	ctx->vsp=local; return(local[0]);}

/*eustop*/
static pointer F70037eustop(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST71655:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= loadglobal(fqv[3]);
	ctx->vsp=local+2;
	w=(pointer)ISATTY(ctx,1,local+1); /*unix:isatty*/
	if (w==NIL) goto IF71665;
	local[1]= makeint(4);
	local[2]= fqv[69];
	ctx->vsp=local+3;
	w=(*ftab[10])(ctx,0,local+3,&ftab[10],fqv[70]); /*lisp-implementation-version*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[2])(ctx,3,local+1,&ftab[2],fqv[7]); /*warning-message*/
	local[1]= loadglobal(fqv[62]);
	ctx->vsp=local+2;
	w=(pointer)TERPRI(ctx,1,local+1); /*terpri*/
	local[1]= makeint(2);
	local[2]= fqv[71];
	local[3]= makeint(2);
	ctx->vsp=local+4;
	w=(pointer)SIGNAL(ctx,3,local+1); /*unix:signal*/
	local[1]= makeint(13);
	local[2]= fqv[72];
	ctx->vsp=local+3;
	w=(pointer)SIGNAL(ctx,2,local+1); /*unix:signal*/
	local[1]= fqv[73];
	ctx->vsp=local+2;
	w=(pointer)FBOUNDP(ctx,1,local+1); /*fboundp*/
	if (w==NIL) goto IF71697;
	local[1]= loadglobal(fqv[3]);
	ctx->vsp=local+2;
	w=(*ftab[11])(ctx,1,local+1,&ftab[11],fqv[73]); /*unix:tcgets*/
	local[1]= w;
	storeglobal(fqv[74],w);
	local[1]= loadglobal(fqv[75]);
	ctx->vsp=local+2;
	w=(*ftab[12])(ctx,1,local+1,&ftab[12],fqv[76]); /*new-history*/
	local[1]= w;
	goto IF71698;
IF71697:
	local[1]= NIL;
IF71698:
	goto IF71666;
IF71665:
	local[1]= NIL;
IF71666:
	if (local[0]==NIL) goto IF71725;
	local[1]= local[0];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,1,local+1,&ftab[13],fqv[77]); /*find-executable*/
	local[1]= w;
	storeglobal(fqv[78],w);
	goto IF71726;
IF71725:
	local[1]= NIL;
IF71726:
	local[1]= fqv[79];
	ctx->vsp=local+2;
	w=(pointer)GETENV(ctx,1,local+1); /*unix:getenv*/
	local[1]= w;
	storeglobal(fqv[80],w);
	local[1]= local[0];
	storeglobal(fqv[81],local[1]);
	local[1]= loadglobal(fqv[64]);
	ctx->vsp=local+2;
	w=(*ftab[14])(ctx,1,local+1,&ftab[14],fqv[82]); /*pathname-name*/
	local[1]= w;
	storeglobal(fqv[33],w);
	local[1]= fqv[83];
	ctx->vsp=local+2;
	w=(pointer)GETENV(ctx,1,local+1); /*unix:getenv*/
	local[1]= w;
	if (local[1]!=NIL) goto IF71780;
	local[2]= loadglobal(fqv[17]);
	local[3]= fqv[84];
	ctx->vsp=local+4;
	w=(pointer)GETENV(ctx,1,local+3); /*unix:getenv*/
	local[3]= w;
	local[4]= fqv[85];
	ctx->vsp=local+5;
	w=(pointer)CONCATENATE(ctx,3,local+2); /*concatenate*/
	local[1] = w;
	local[2]= local[1];
	goto IF71781;
IF71780:
	local[2]= NIL;
IF71781:
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[15])(ctx,1,local+2,&ftab[15],fqv[86]); /*probe-file*/
	if (w==NIL) goto IF71801;
	local[2]= local[1];
	local[3]= fqv[87];
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(*ftab[16])(ctx,3,local+2,&ftab[16],fqv[88]); /*load*/
	local[2]= w;
	goto IF71802;
IF71801:
	local[2]= NIL;
IF71802:
	w = local[2];
	local[1]= fqv[89];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,1,local+1,&ftab[15],fqv[86]); /*probe-file*/
	if (w==NIL) goto IF71819;
	local[1]= fqv[90];
	local[2]= fqv[87];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,3,local+1,&ftab[16],fqv[88]); /*load*/
	local[1]= w;
	goto IF71820;
IF71819:
	local[1]= NIL;
IF71820:
	if (local[0]==NIL) goto IF71835;
	local[1]= loadglobal(fqv[64]);
	ctx->vsp=local+2;
	w=(*ftab[14])(ctx,1,local+1,&ftab[14],fqv[82]); /*pathname-name*/
	local[1]= w;
	local[2]= fqv[91];
	ctx->vsp=local+3;
	w=(pointer)EQUAL(ctx,2,local+1); /*equal*/
	if (w==NIL) goto IF71835;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	w = makeint(2);
	if ((eusinteger_t)local[1] < (eusinteger_t)w) goto IF71835;
	local[1]= (pointer)get_sym_func(fqv[92]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,1,local+1,&ftab[17],fqv[93]); /*exit*/
	local[1]= w;
	goto IF71836;
IF71835:
	local[1]= NIL;
IF71836:
	if (loadglobal(fqv[94])==NIL) goto IF71867;
	local[1]= loadglobal(fqv[94]);
	local[2]= loadglobal(fqv[81]);
	ctx->vsp=local+3;
	w=(pointer)FUNCALL(ctx,2,local+1); /*funcall*/
	local[1]= w;
	goto IF71868;
IF71867:
	local[1]= NIL;
IF71868:
	local[1]= NIL;
	local[2]= makeint(0);
	local[3]= loadglobal(fqv[81]);
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SUB1(ctx,1,local+3); /*1-*/
	local[3]= w;
WHL71915:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX71916;
	local[4]= loadglobal(fqv[81]);
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[1] = w;
	local[4]= local[1];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	if (makeint(40)!=local[4]) goto CON71938;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(*ftab[18])(ctx,1,local+4,&ftab[18],fqv[95]); /*read-from-string*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)EVAL(ctx,1,local+4); /*eval*/
	local[4]= w;
	goto CON71936;
CON71938:
	local[4]= local[1];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	local[4]= ((makeint(45))==(local[4])?T:NIL);
	if (local[4]!=NIL) goto CON71936;
CON71951:
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(*ftab[16])(ctx,1,local+4,&ftab[16],fqv[88]); /*load*/
	local[4]= w;
	goto CON71936;
CON71960:
	local[4]= NIL;
CON71936:
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL71915;
WHX71916:
	local[4]= NIL;
BLK71917:
	w = NIL;
	{jmp_buf jb;
	w = fqv[96];
	ctx->vsp=local+1;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT71981;}
WHL71988:
	if (T==NIL) goto WHX71989;
	{jmp_buf jb;
	w = makeint(0);
	ctx->vsp=local+7;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT71995;}
	local[13]= makeint(0);
	local[14]= fqv[97];
	w = local[14];
	ctx->vsp=local+15;
	bindspecial(ctx,fqv[11],w);
	w = local[13];
	ctx->vsp=local+18;
	bindspecial(ctx,fqv[9],w);
	local[21]= (pointer)get_sym_func(fqv[12]);
	ctx->vsp=local+22;
	w=(pointer)F70031reploop(ctx,1,local+21); /*reploop*/
	local[21]= w;
	ctx->vsp=local+22;
	unbindx(ctx,2);
	w = local[21];
	local[13]= fqv[96];
	w = NIL;
	ctx->vsp=local+14;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	w = local[13];
CAT71995:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	goto WHL71988;
WHX71989:
	local[7]= NIL;
BLK71990:
	w = local[7];
CAT71981:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[0]= w;
BLK71653:
	ctx->vsp=local; return(local[0]);}

/*reset*/
static pointer F70040reset(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT72037;}
	local[0]= makeint(0);
ENT72037:
ENT72036:
	if (n>1) maerror();
	local[1]= local[0];
	w = NIL;
	ctx->vsp=local+2;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	w = local[1];
	local[0]= w;
BLK72034:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___toplevel(ctx,n,argv,env)
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
	local[0]= fqv[98];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF72059;
	local[0]= fqv[99];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[18],w);
	goto IF72060;
IF72059:
	local[0]= fqv[100];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF72060:
	local[0]= fqv[101];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[16];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF72082;
	local[0]= fqv[16];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[16];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF72105;
	local[0]= fqv[16];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF72106;
IF72105:
	local[0]= NIL;
IF72106:
	local[0]= fqv[16];
	goto IF72083;
IF72082:
	local[0]= NIL;
IF72083:
	local[0]= fqv[46];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF72125;
	local[0]= fqv[46];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[46];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF72148;
	local[0]= fqv[46];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF72149;
IF72148:
	local[0]= NIL;
IF72149:
	local[0]= fqv[46];
	goto IF72126;
IF72125:
	local[0]= NIL;
IF72126:
	local[0]= fqv[44];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF72168;
	local[0]= fqv[44];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[44];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF72191;
	local[0]= fqv[44];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF72192;
IF72191:
	local[0]= NIL;
IF72192:
	local[0]= fqv[44];
	goto IF72169;
IF72168:
	local[0]= NIL;
IF72169:
	local[0]= fqv[45];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF72211;
	local[0]= fqv[45];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[45];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF72234;
	local[0]= fqv[45];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF72235;
IF72234:
	local[0]= NIL;
IF72235:
	local[0]= fqv[45];
	goto IF72212;
IF72211:
	local[0]= NIL;
IF72212:
	local[0]= fqv[43];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF72254;
	local[0]= fqv[43];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[43];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF72277;
	local[0]= fqv[43];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF72278;
IF72277:
	local[0]= NIL;
IF72278:
	local[0]= fqv[43];
	goto IF72255;
IF72254:
	local[0]= NIL;
IF72255:
	local[0]= fqv[41];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF72297;
	local[0]= fqv[41];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[41];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF72320;
	local[0]= fqv[41];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF72321;
IF72320:
	local[0]= NIL;
IF72321:
	local[0]= fqv[41];
	goto IF72298;
IF72297:
	local[0]= NIL;
IF72298:
	local[0]= fqv[42];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF72340;
	local[0]= fqv[42];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[42];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF72363;
	local[0]= fqv[42];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF72364;
IF72363:
	local[0]= NIL;
IF72364:
	local[0]= fqv[42];
	goto IF72341;
IF72340:
	local[0]= NIL;
IF72341:
	local[0]= fqv[104];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF72383;
	local[0]= fqv[104];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[104];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF72406;
	local[0]= fqv[104];
	local[1]= fqv[103];
	local[2]= loadglobal(fqv[3]);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF72407;
IF72406:
	local[0]= NIL;
IF72407:
	local[0]= fqv[104];
	goto IF72384;
IF72383:
	local[0]= NIL;
IF72384:
	local[0]= fqv[105];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF72429;
	local[0]= fqv[105];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[105];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF72452;
	local[0]= fqv[105];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF72453;
IF72452:
	local[0]= NIL;
IF72453:
	local[0]= fqv[105];
	goto IF72430;
IF72429:
	local[0]= NIL;
IF72430:
	local[0]= fqv[94];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF72472;
	local[0]= fqv[94];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[94];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF72495;
	local[0]= fqv[94];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF72496;
IF72495:
	local[0]= NIL;
IF72496:
	local[0]= fqv[94];
	goto IF72473;
IF72472:
	local[0]= NIL;
IF72473:
	local[0]= fqv[47];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF72515;
	local[0]= fqv[47];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[47];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF72538;
	local[0]= fqv[47];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF72539;
IF72538:
	local[0]= NIL;
IF72539:
	local[0]= fqv[47];
	goto IF72516;
IF72515:
	local[0]= NIL;
IF72516:
	local[0]= fqv[37];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF72558;
	local[0]= fqv[37];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[37];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF72581;
	local[0]= fqv[37];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF72582;
IF72581:
	local[0]= NIL;
IF72582:
	local[0]= fqv[37];
	goto IF72559;
IF72558:
	local[0]= NIL;
IF72559:
	local[0]= fqv[9];
	local[1]= fqv[106];
	local[2]= makeint(0);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[11];
	local[1]= fqv[106];
	local[2]= fqv[107];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[4];
	local[1]= fqv[106];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[33];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF72625;
	local[0]= fqv[33];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[33];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF72648;
	local[0]= fqv[33];
	local[1]= fqv[103];
	local[2]= fqv[108];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF72649;
IF72648:
	local[0]= NIL;
IF72649:
	local[0]= fqv[33];
	goto IF72626;
IF72625:
	local[0]= NIL;
IF72626:
	local[0]= fqv[25];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF72668;
	local[0]= fqv[25];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[25];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF72691;
	local[0]= fqv[25];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF72692;
IF72691:
	local[0]= NIL;
IF72692:
	local[0]= fqv[25];
	goto IF72669;
IF72668:
	local[0]= NIL;
IF72669:
	local[0]= fqv[74];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF72711;
	local[0]= fqv[74];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[74];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF72734;
	local[0]= fqv[74];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF72735;
IF72734:
	local[0]= NIL;
IF72735:
	local[0]= fqv[74];
	goto IF72712;
IF72711:
	local[0]= NIL;
IF72712:
	local[0]= fqv[81];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF72754;
	local[0]= fqv[81];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[81];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF72777;
	local[0]= fqv[81];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF72778;
IF72777:
	local[0]= NIL;
IF72778:
	local[0]= fqv[81];
	goto IF72755;
IF72754:
	local[0]= NIL;
IF72755:
	local[0]= fqv[55];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF72797;
	local[0]= fqv[55];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[55];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF72820;
	local[0]= fqv[55];
	local[1]= fqv[103];
	local[2]= loadglobal(fqv[109]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[110];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	w = local[2];
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF72821;
IF72820:
	local[0]= NIL;
IF72821:
	local[0]= fqv[55];
	goto IF72798;
IF72797:
	local[0]= NIL;
IF72798:
	local[0]= fqv[60];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF72865;
	local[0]= fqv[60];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[60];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF72888;
	local[0]= fqv[60];
	local[1]= fqv[103];
	local[2]= fqv[111];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF72889;
IF72888:
	local[0]= NIL;
IF72889:
	local[0]= fqv[60];
	goto IF72866;
IF72865:
	local[0]= NIL;
IF72866:
	local[0]= fqv[0];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF72912;
	local[0]= fqv[0];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[0];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF72935;
	local[0]= fqv[0];
	local[1]= fqv[103];
	local[2]= makeint(0);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF72936;
IF72935:
	local[0]= NIL;
IF72936:
	local[0]= fqv[0];
	goto IF72913;
IF72912:
	local[0]= NIL;
IF72913:
	local[0]= fqv[59];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF72955;
	local[0]= fqv[59];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[59];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF72978;
	local[0]= fqv[59];
	local[1]= fqv[103];
	local[2]= makeflt(1.00000000e+01);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF72979;
IF72978:
	local[0]= NIL;
IF72979:
	local[0]= fqv[59];
	goto IF72956;
IF72955:
	local[0]= NIL;
IF72956:
	local[0]= fqv[61];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF72998;
	local[0]= fqv[61];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[61];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF73021;
	local[0]= fqv[61];
	local[1]= fqv[103];
	local[2]= fqv[112];
	ctx->vsp=local+3;
	w=(pointer)GETENV(ctx,1,local+2); /*unix:getenv*/
	local[2]= ((w)==NIL?T:NIL);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF73022;
IF73021:
	local[0]= NIL;
IF73022:
	local[0]= fqv[61];
	goto IF72999;
IF72998:
	local[0]= NIL;
IF72999:
	local[0]= fqv[20];
	local[1]= fqv[103];
	local[2]= T;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[111],module,F69993count_up_timer,fqv[113]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[114],module,F69996skip_blank,fqv[115]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[116],module,F70000read_list_from_line,fqv[117]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[71],module,F70003sigint_handler,fqv[118]);
	local[0]= fqv[13];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF73062;
	local[0]= fqv[13];
	local[1]= fqv[102];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[13];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF73085;
	local[0]= fqv[13];
	local[1]= fqv[103];
	local[2]= loadglobal(fqv[119]);
	local[3]= makeint(32);
	ctx->vsp=local+4;
	w=(*ftab[19])(ctx,2,local+2,&ftab[19],fqv[120]); /*make-sequence*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF73086;
IF73085:
	local[0]= NIL;
IF73086:
	local[0]= fqv[13];
	goto IF73063;
IF73062:
	local[0]= NIL;
IF73063:
	ctx->vsp=local+0;
	compfun(ctx,fqv[72],module,F70007eussig,fqv[121]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[122],module,F70010evaluate_stream,fqv[123]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[12],module,F70013toplevel_prompt,fqv[124]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[125],module,F70016rep1,fqv[126]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[127],module,F70019prompt,fqv[128]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[129],module,F70022reploop_non_select,fqv[130]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[57],module,F70025repsel,fqv[131]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[132],module,F70028reploop_select,fqv[133]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[134],module,F70031reploop,fqv[135]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[51],module,F70034euserror,fqv[136]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[137],module,F70037eustop,fqv[138]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[139],module,F70040reset,fqv[140]);
	local[0]= fqv[141];
	local[1]= fqv[142];
	ctx->vsp=local+2;
	w=(*ftab[20])(ctx,2,local+0,&ftab[20],fqv[143]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<21; i++) ftab[i]=fcallx;
}
