/* ./loader.c :  entry=loader */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "loader.h"
#pragma init (register_loader)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___loader();
extern pointer build_quote_vector();
static int register_loader()
  { add_module_initializer("___loader", ___loader);}

static pointer F28918file_write_date();
static pointer F28921file_newer();
static pointer F28924open();
static pointer F28929probe_file();
static pointer F28933object_file_p();
static pointer F28936path_list();
static pointer F28939find_executable();
static pointer F28942system__txtload();
static pointer F28952load_module_file_name();
static pointer F28955gencname_tail();
static pointer F28958load();
static pointer F28961load_files();
static pointer F28964read_file();
static pointer F28967read_strings();
static pointer F28970read_lines();
static pointer F28973read_lists();
static pointer F28976read_binary_file();
static pointer F28979read_lines_till_eof();
static pointer F28984load_library();
static pointer F28987dump_object();
static pointer F28990dump_structure();
static pointer F28994file_size();
static pointer F28997directory_p();
static pointer F29000map_file();
static pointer F29002provide();
static pointer F29004require();

/*file-write-date*/
static pointer F28918file_write_date(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint(9);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[0]); /*namestring*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)STAT(ctx,1,local+1); /*unix:stat*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)NTH(ctx,2,local+0); /*nth*/
	local[0]= w;
BLK29054:
	ctx->vsp=local; return(local[0]);}

/*file-newer*/
static pointer F28921file_newer(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)F28929probe_file(ctx,1,local+0); /*probe-file*/
	local[0]= ((w)==NIL?T:NIL);
	if (local[0]!=NIL) goto OR29086;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F28929probe_file(ctx,1,local+0); /*probe-file*/
	local[0]= ((w)==NIL?T:NIL);
	if (local[0]!=NIL) goto OR29086;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F28918file_write_date(ctx,1,local+0); /*file-write-date*/
	local[0]= w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F28918file_write_date(ctx,1,local+1); /*file-write-date*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	local[0]= w;
OR29086:
	w = local[0];
	local[0]= w;
BLK29074:
	ctx->vsp=local; return(local[0]);}

/*open*/
static pointer F28924open(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[1], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY29128;
	local[0] = fqv[2];
KEY29128:
	if (n & (1<<1)) goto KEY29135;
	local[1] = fqv[3];
KEY29135:
	if (n & (1<<2)) goto KEY29142;
	local[2] = fqv[4];
KEY29142:
	if (n & (1<<3)) goto KEY29149;
	local[3] = makeint(420);
KEY29149:
	if (n & (1<<4)) goto KEY29154;
	local[4] = makeint(512);
KEY29154:
	local[5]= makeint(0);
	local[6]= NIL;
	local[7]= NIL;
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)STREAMP(ctx,1,local+8); /*streamp*/
	if (w==NIL) goto IF29179;
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(*ftab[1])(ctx,1,local+8,&ftab[1],fqv[5]); /*io-stream-p*/
	if (w==NIL) goto IF29187;
	local[7] = *(ovafptr(*(ovafptr(argv[0],fqv[6])),fqv[7]));
	local[8]= local[7];
	goto IF29188;
IF29187:
	local[7] = *(ovafptr(argv[0],fqv[7]));
	local[8]= local[7];
IF29188:
	goto IF29180;
IF29179:
	local[7] = argv[0];
	local[8]= local[7];
IF29180:
	local[8]= local[7];
	ctx->vsp=local+9;
	w=(*ftab[0])(ctx,1,local+8,&ftab[0],fqv[0]); /*namestring*/
	local[7] = w;
	local[8]= local[0];
	local[9]= local[8];
	if (fqv[2]!=local[9]) goto IF29240;
	local[5] = makeint(0);
	local[9]= local[2];
	if (fqv[4]!=local[9]) goto IF29257;
	local[2] = fqv[8];
	local[9]= local[2];
	goto IF29258;
IF29257:
	local[9]= NIL;
IF29258:
	local[9]= local[2];
	if (fqv[9]!=local[9]) goto IF29273;
	local[9]= local[5];
	local[10]= makeint(64);
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[5] = w;
	local[9]= local[5];
	goto IF29274;
IF29273:
	local[9]= NIL;
IF29274:
	local[9]= local[7];
	local[10]= local[5];
	local[11]= local[3];
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(*ftab[2])(ctx,4,local+9,&ftab[2],fqv[10]); /*system:openfile*/
	local[6] = w;
	local[9]= local[6];
	goto IF29241;
IF29240:
	local[9]= local[8];
	w = fqv[11];
	if (memq(local[9],w)==NIL) goto IF29305;
	local[9]= local[0];
	if (fqv[12]!=local[9]) goto IF29319;
	local[5] = makeint(2);
	local[9]= local[5];
	goto IF29320;
IF29319:
	local[5] = makeint(1);
	local[9]= local[5];
IF29320:
	local[9]= local[1];
	local[10]= local[9];
	if (fqv[13]!=local[10]) goto IF29351;
	local[10]= local[5];
	local[11]= makeint(1024);
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[5] = w;
	local[10]= local[5];
	goto IF29352;
IF29351:
	local[10]= local[9];
	w = fqv[14];
	if (memq(local[10],w)==NIL) goto IF29370;
	local[10]= local[5];
	local[11]= makeint(64);
	local[12]= makeint(512);
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,3,local+10); /*+*/
	local[5] = w;
	local[10]= local[5];
	goto IF29371;
IF29370:
	local[10]= local[9];
	if (fqv[15]!=local[10]) goto IF29391;
	local[10]= local[5];
	local[11]= makeint(64);
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[5] = w;
	local[10]= local[5];
	goto IF29392;
IF29391:
	local[10]= local[9];
	w = fqv[16];
	if (memq(local[10],w)==NIL) goto IF29410;
	local[10]= local[5];
	local[11]= makeint(64);
	local[12]= makeint(128);
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,3,local+10); /*+*/
	local[5] = w;
	local[10]= local[5];
	goto IF29411;
IF29410:
	if (T==NIL) goto IF29431;
	local[10]= fqv[17];
	ctx->vsp=local+11;
	w=(pointer)SIGERROR(ctx,1,local+10); /*error*/
	local[10]= w;
	goto IF29432;
IF29431:
	local[10]= NIL;
IF29432:
IF29411:
IF29392:
IF29371:
IF29352:
	w = local[10];
	local[9]= local[2];
	local[10]= local[9];
	if (fqv[8]!=local[10]) goto IF29453;
	local[10]= local[5];
	local[11]= makeint(64);
	ctx->vsp=local+12;
	w=(pointer)LOGNOT(ctx,1,local+11); /*lognot*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)LOGAND(ctx,2,local+10); /*logand*/
	local[5] = w;
	local[10]= local[5];
	goto IF29454;
IF29453:
	local[10]= local[9];
	if (fqv[9]!=local[10]) goto IF29473;
	local[10]= local[5];
	local[11]= makeint(64);
	ctx->vsp=local+12;
	w=(pointer)LOGIOR(ctx,2,local+10); /*logior*/
	local[5] = w;
	local[10]= local[5];
	goto IF29474;
IF29473:
	local[10]= local[9];
	if (fqv[4]!=local[10]) goto IF29491;
	local[10]= local[1];
	w = fqv[18];
	if (memq(local[10],w)!=NIL) goto IF29499;
	local[10]= local[5];
	local[11]= makeint(64);
	ctx->vsp=local+12;
	w=(pointer)LOGIOR(ctx,2,local+10); /*logior*/
	local[5] = w;
	local[10]= local[5];
	goto IF29500;
IF29499:
	local[10]= NIL;
IF29500:
	goto IF29492;
IF29491:
	local[10]= local[9];
	if (fqv[19]!=local[10]) goto IF29520;
	local[10]= NIL;
	goto IF29521;
IF29520:
	if (T==NIL) goto IF29528;
	local[10]= fqv[20];
	ctx->vsp=local+11;
	w=(pointer)SIGERROR(ctx,1,local+10); /*error*/
	local[10]= w;
	goto IF29529;
IF29528:
	local[10]= NIL;
IF29529:
IF29521:
IF29492:
IF29474:
IF29454:
	w = local[10];
	local[9]= local[7];
	local[10]= local[5];
	local[11]= local[3];
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(*ftab[2])(ctx,4,local+9,&ftab[2],fqv[10]); /*system:openfile*/
	local[6] = w;
	local[9]= local[6];
	goto IF29306;
IF29305:
	if (T==NIL) goto IF29548;
	local[9]= fqv[21];
	ctx->vsp=local+10;
	w=(pointer)SIGERROR(ctx,1,local+9); /*error*/
	local[9]= w;
	goto IF29549;
IF29548:
	local[9]= NIL;
IF29549:
IF29306:
IF29241:
	w = local[9];
	w = local[6];
	if (!isnum(w)) goto IF29558;
	if (local[2]!=NIL) goto IF29567;
	w = NIL;
	ctx->vsp=local+8;
	local[0]=w;
	goto BLK29115;
	goto IF29568;
IF29567:
	local[8]= loadglobal(fqv[22]);
	local[9]= fqv[23];
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)CONCATENATE(ctx,3,local+8); /*concatenate*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SIGERROR(ctx,1,local+8); /*error*/
	local[8]= w;
IF29568:
	goto IF29559;
IF29558:
	local[8]= NIL;
IF29559:
	w = local[6];
	local[0]= w;
BLK29115:
	ctx->vsp=local; return(local[0]);}

/*with-open-file*/
static pointer F29590(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST29593:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[24];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[25];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	local[5]= NIL;
	ctx->vsp=local+6;
	w=(pointer)APPEND(ctx,2,local+4); /*append*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	local[3]= fqv[26];
	local[4]= fqv[27];
	local[5]= local[0];
	local[6]= NIL;
	ctx->vsp=local+7;
	w=(pointer)APPEND(ctx,2,local+5); /*append*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[28];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK29591:
	ctx->vsp=local; return(local[0]);}

/*probe-file*/
static pointer F28929probe_file(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*namestring*/
	local[0]= w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)STAT(ctx,1,local+1); /*unix:stat*/
	local[1]= w;
	w = local[1];
	if (!iscons(w)) goto IF29691;
	local[2]= makeint(61440);
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)LOGAND(ctx,2,local+2); /*logand*/
	local[2]= w;
	local[3]= local[2];
	if (fqv[29]!=local[3]) goto IF29719;
	local[3]= fqv[30];
	goto IF29720;
IF29719:
	local[3]= local[2];
	if (fqv[31]!=local[3]) goto IF29729;
	local[3]= fqv[32];
	goto IF29730;
IF29729:
	local[3]= local[2];
	if (fqv[33]!=local[3]) goto IF29739;
	local[3]= fqv[34];
	goto IF29740;
IF29739:
	local[3]= local[2];
	if (fqv[35]!=local[3]) goto IF29749;
	local[3]= fqv[36];
	goto IF29750;
IF29749:
	local[3]= local[2];
	if (fqv[37]!=local[3]) goto IF29759;
	local[3]= fqv[38];
	goto IF29760;
IF29759:
	local[3]= local[2];
	if (fqv[39]!=local[3]) goto IF29769;
	local[3]= fqv[40];
	goto IF29770;
IF29769:
	local[3]= local[2];
	if (fqv[41]!=local[3]) goto IF29779;
	local[3]= fqv[42];
	goto IF29780;
IF29779:
	local[3]= NIL;
IF29780:
IF29770:
IF29760:
IF29750:
IF29740:
IF29730:
IF29720:
	w = local[3];
	local[2]= w;
	goto IF29692;
IF29691:
	local[2]= NIL;
IF29692:
	w = local[2];
	local[0]= w;
BLK29665:
	ctx->vsp=local; return(local[0]);}

/*object-file-p*/
static pointer F28933object_file_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,FLET29807,env,argv,local);
	local[1]= argv[0];
	w = local[0];
	ctx->vsp=local+2;
	w=FLET29807(ctx,1,local+1,w);
	local[1]= w;
	local[2]= loadglobal(fqv[43]);
	local[3]= local[1];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	local[4]= makeint(1);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	local[7]= T;
	local[8]= NIL;
TAG29904:
	if (local[2]==NIL) goto OR29911;
	local[9]= local[4];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)GREQP(ctx,2,local+9); /*>=*/
	if (w!=NIL) goto OR29911;
	if (local[8]!=NIL) goto OR29911;
	goto IF29909;
OR29911:
	w = local[7];
	ctx->vsp=local+9;
	local[3]=w;
	goto BLK29833;
	goto IF29910;
IF29909:
	local[9]= NIL;
IF29910:
	if (local[6]==NIL) goto IF29933;
	local[9]= local[3];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)EQ(ctx,2,local+9); /*eql*/
	if (w!=NIL) goto IF29933;
	local[9]= local[3];
	w = local[6];
	if (memq(local[9],w)!=NIL) goto IF29933;
	local[7] = NIL;
	local[8] = T;
	local[9]= local[8];
	goto IF29934;
IF29933:
	local[9]= NIL;
IF29934:
	local[9]= local[1];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[10]= w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[11];
	local[11]= w;
	local[3] = local[9];
	local[4] = local[10];
	local[6] = local[11];
	w = NIL;
	ctx->vsp=local+9;
	goto TAG29904;
	w = NIL;
	local[3]= w;
BLK29833:
	w = local[3];
	local[0]= w;
BLK29795:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET29807(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint(4);
	ctx->vsp=local+1;
	w=(*ftab[3])(ctx,1,local+0,&ftab[3],fqv[44]); /*make-string*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F28924open(ctx,1,local+1); /*open*/
	local[1]= w;
	ctx->vsp=local+2;
	w = makeclosure(codevec,quotevec,UWP30083,env,argv,local);
	local[2]=(pointer)(ctx->protfp); local[3]=w;
	ctx->protfp=(struct protectframe *)(local+2);
	local[4]= local[1]->c.obj.iv[5];
	local[5]= local[0];
	local[6]= makeint(4);
	ctx->vsp=local+7;
	w=(pointer)UNIXREAD(ctx,3,local+4); /*unix:uread*/
	ctx->vsp=local+4;
	UWP30083(ctx,0,local+4,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP30083(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[1];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*path-list*/
static pointer F28936path_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT30120;}
	local[0]= fqv[45];
	ctx->vsp=local+1;
	w=(pointer)GETENV(ctx,1,local+0); /*unix:getenv*/
	local[0]= w;
ENT30120:
ENT30119:
	if (n>1) maerror();
	local[1]= NIL;
	local[2]= makeint(0);
	local[3]= NIL;
	local[4]= NIL;
WHL30150:
	local[5]= makeint(58);
	local[6]= local[0];
	local[7]= fqv[46];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(*ftab[4])(ctx,4,local+5,&ftab[4],fqv[47]); /*position*/
	local[3] = w;
	if (local[3]==NIL) goto WHX30151;
	local[5]= local[0];
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SUBSEQ(ctx,3,local+5); /*subseq*/
	local[4] = w;
	local[5]= loadglobal(fqv[22]);
	local[6]= local[4];
	local[7]= fqv[48];
	ctx->vsp=local+8;
	w=(pointer)CONCATENATE(ctx,3,local+5); /*concatenate*/
	local[5]= w;
	w = local[1];
	ctx->vsp=local+6;
	local[1] = cons(ctx,local[5],w);
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[2] = w;
	goto WHL30150;
WHX30151:
	local[5]= NIL;
BLK30152:
	local[5]= loadglobal(fqv[22]);
	local[6]= local[0];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SUBSEQ(ctx,2,local+6); /*subseq*/
	local[6]= w;
	local[7]= fqv[49];
	ctx->vsp=local+8;
	w=(pointer)CONCATENATE(ctx,3,local+5); /*concatenate*/
	local[5]= w;
	w = local[1];
	ctx->vsp=local+6;
	local[1] = cons(ctx,local[5],w);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)NREVERSE(ctx,1,local+5); /*nreverse*/
	local[0]= w;
BLK30117:
	ctx->vsp=local; return(local[0]);}

/*find-executable*/
static pointer F28939find_executable(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F28929probe_file(ctx,1,local+0); /*probe-file*/
	if (w==NIL) goto IF30238;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[5])(ctx,1,local+0,&ftab[5],fqv[50]); /*truename*/
	local[0]= w;
	goto IF30239;
IF30238:
	ctx->vsp=local+0;
	w=(pointer)F28936path_list(ctx,0,local+0); /*path-list*/
	local[0]= w;
	local[1]= NIL;
WHL30262:
	if (local[0]==NIL) goto WHX30263;
	local[2]= argv[0];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[3];
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,2,local+2,&ftab[6],fqv[51]); /*merge-pathnames*/
	local[1] = w;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,1,local+2,&ftab[0],fqv[0]); /*namestring*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F28929probe_file(ctx,1,local+2); /*probe-file*/
	if (w==NIL) goto IF30315;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[5])(ctx,1,local+2,&ftab[5],fqv[50]); /*truename*/
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK30228;
	goto IF30316;
IF30315:
	local[2]= NIL;
IF30316:
	goto WHL30262;
WHX30263:
	local[2]= NIL;
BLK30264:
	w = NIL;
	local[0]= w;
IF30239:
	w = local[0];
	local[0]= w;
BLK30228:
	ctx->vsp=local; return(local[0]);}

/*system::txtload*/
static pointer F28942system__txtload(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT30338;}
	local[0]= NIL;
ENT30338:
ENT30337:
	if (n>2) maerror();
	ctx->vsp=local+1;
	w=(pointer)GENSYM(ctx,0,local+1); /*gensym*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F28924open(ctx,1,local+4); /*open*/
	local[4]= w;
	ctx->vsp=local+5;
	w = makeclosure(codevec,quotevec,UWP30382,env,argv,local);
	local[5]=(pointer)(ctx->protfp); local[6]=w;
	ctx->protfp=(struct protectframe *)(local+5);
WHL30389:
	local[7]= local[4];
	local[8]= NIL;
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)READ(ctx,3,local+7); /*read*/
	local[2] = w;
	local[7]= local[2];
	if (local[1]==local[7]) goto WHX30390;
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)EVAL(ctx,1,local+7); /*eval*/
	local[3] = w;
	if (local[0]==NIL) goto IF30415;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)PRINT(ctx,1,local+7); /*print*/
	local[7]= w;
	goto IF30416;
IF30415:
	local[7]= NIL;
IF30416:
	goto WHL30389;
WHX30390:
	local[7]= NIL;
BLK30391:
	w = local[7];
	ctx->vsp=local+7;
	UWP30382(ctx,0,local+7,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK30335:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP30382(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[4];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*load-module-file-name*/
static pointer F28952load_module_file_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+1;
	w=(*ftab[7])(ctx,1,local+0,&ftab[7],fqv[52]); /*pathname-name*/
	local[0]= w;
BLK30452:
	ctx->vsp=local; return(local[0]);}

/*gencname-tail*/
static pointer F28955gencname_tail(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST30475:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,FLET30486,env,argv,local);
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,FLET30488,env,argv,local);
	local[3]= local[0];
	w = local[2];
	ctx->vsp=local+4;
	w=FLET30488(ctx,1,local+3,w);
	local[0]= w;
BLK30473:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET30486(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint(97);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LSEQP(ctx,2,local+0); /*<=*/
	local[0]= w;
	if (w==NIL) goto AND30511;
	local[0]= argv[0];
	local[1]= makeint(122);
	ctx->vsp=local+2;
	w=(pointer)LSEQP(ctx,2,local+0); /*<=*/
	local[0]= w;
AND30511:
	if (local[0]!=NIL) goto OR30507;
	local[0]= makeint(65);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LSEQP(ctx,2,local+0); /*<=*/
	local[0]= w;
	if (w==NIL) goto AND30524;
	local[0]= argv[0];
	local[1]= makeint(90);
	ctx->vsp=local+2;
	w=(pointer)LSEQP(ctx,2,local+0); /*<=*/
	local[0]= w;
AND30524:
	if (local[0]!=NIL) goto OR30507;
	local[0]= makeint(48);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LSEQP(ctx,2,local+0); /*<=*/
	local[0]= w;
	if (w==NIL) goto AND30537;
	local[0]= argv[0];
	local[1]= makeint(57);
	ctx->vsp=local+2;
	w=(pointer)LSEQP(ctx,2,local+0); /*<=*/
	local[0]= w;
AND30537:
	if (local[0]!=NIL) goto OR30507;
	local[0]= argv[0];
	local[1]= makeint(95);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	local[0]= w;
OR30507:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET30488(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO30570,env,argv,local);
	local[1]= argv[0];
	local[2]= fqv[53];
	local[3]= fqv[54];
	ctx->vsp=local+4;
	w=(*ftab[8])(ctx,4,local+0,&ftab[8],fqv[55]); /*reduce*/
	local[0]= w;
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO30583,env,argv,local);
	local[2]= local[0];
	local[3]= loadglobal(fqv[56]);
	ctx->vsp=local+4;
	w=(pointer)COERCE(ctx,2,local+2); /*coerce*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	local[2]= loadglobal(fqv[22]);
	ctx->vsp=local+3;
	w=(pointer)COERCE(ctx,2,local+1); /*coerce*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO30570(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= fqv[57];
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO30583(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = env->c.clo.env0->c.clo.env2[1];
	ctx->vsp=local+1;
	w=FLET30486(ctx,1,local+0,w);
	if (w==NIL) goto IF30621;
	local[0]= argv[0];
	goto IF30622;
IF30621:
	local[0]= makeint(95);
IF30622:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*load*/
static pointer F28958load(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[58], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY30650;
	local[0] = NIL;
KEY30650:
	if (n & (1<<1)) goto KEY30655;
	local[8]= loadglobal(fqv[22]);
	local[9]= fqv[59];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(*ftab[7])(ctx,1,local+10,&ftab[7],fqv[52]); /*pathname-name*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)CONCATENATE(ctx,3,local+8); /*concatenate*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)F28955gencname_tail(ctx,1,local+8); /*gencname-tail*/
	local[1] = w;
KEY30655:
	if (n & (1<<2)) goto KEY30668;
	local[2] = NIL;
KEY30668:
	if (n & (1<<3)) goto KEY30673;
	local[3] = fqv[60];
KEY30673:
	if (n & (1<<4)) goto KEY30678;
	local[4] = fqv[61];
KEY30678:
	if (n & (1<<5)) goto KEY30683;
	local[5] = loadglobal(fqv[62]);
KEY30683:
	if (n & (1<<6)) goto KEY30690;
	local[6] = NIL;
KEY30690:
	if (n & (1<<7)) goto KEY30695;
	local[7] = loadglobal(fqv[63]);
KEY30695:
	local[8]= loadglobal(fqv[63]);
	w = local[8];
	ctx->vsp=local+8;
	bindspecial(ctx,fqv[63],w);
	local[11]= NIL;
	local[12]= NIL;
	ctx->vsp=local+13;
	local[13]= makeclosure(codevec,quotevec,FLET30722,env,argv,local);
	ctx->vsp=local+14;
	local[14]= makeclosure(codevec,quotevec,FLET30724,env,argv,local);
	ctx->vsp=local+15;
	local[15]= makeclosure(codevec,quotevec,FLET30726,env,argv,local);
	local[16]= argv[0];
	ctx->vsp=local+17;
	w=(*ftab[9])(ctx,1,local+16,&ftab[9],fqv[64]); /*pathname*/
	argv[0] = w;
	local[16]= local[7];
	ctx->vsp=local+17;
	w=(pointer)FINDPACKAGE(ctx,1,local+16); /*find-package*/
	local[16]= w;
	storeglobal(fqv[63],w);
	local[16]= argv[0];
	ctx->vsp=local+17;
	w=(*ftab[10])(ctx,1,local+16,&ftab[10],fqv[65]); /*pathname-directory*/
	if (w==NIL) goto IF30748;
	local[16]= argv[0];
	ctx->vsp=local+17;
	w=(*ftab[10])(ctx,1,local+16,&ftab[10],fqv[65]); /*pathname-directory*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	local[17]= fqv[66];
	ctx->vsp=local+18;
	w=(pointer)EQ(ctx,2,local+16); /*eql*/
	if (w==NIL) goto IF30748;
	local[16]= argv[0];
	w = local[15];
	ctx->vsp=local+17;
	w=FLET30726(ctx,1,local+16,w);
	local[12] = w;
	if (local[12]!=NIL) goto IF30771;
	local[16]= fqv[67];
	local[17]= argv[0];
	ctx->vsp=local+18;
	w=(pointer)SIGERROR(ctx,2,local+16); /*error*/
	local[16]= w;
	goto IF30772;
IF30771:
	local[16]= local[12];
IF30772:
	goto IF30749;
IF30748:
	local[16]= NIL;
	local[17]= loadglobal(fqv[68]);
	local[18]= loadglobal(fqv[69]);
	local[19]= fqv[70];
	local[20]= (pointer)get_sym_func(fqv[71]);
	ctx->vsp=local+21;
	w=(*ftab[11])(ctx,4,local+17,&ftab[11],fqv[72]); /*union*/
	local[17]= w;
WHL30820:
	if (local[17]==NIL) goto WHX30821;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17] = (w)->c.cons.cdr;
	w = local[18];
	local[16] = w;
	local[18]= local[16];
	local[19]= argv[0];
	ctx->vsp=local+20;
	w=(*ftab[12])(ctx,2,local+18,&ftab[12],fqv[73]); /*concatenate-pathnames*/
	local[11] = w;
	local[18]= local[11];
	w = local[15];
	ctx->vsp=local+19;
	w=FLET30726(ctx,1,local+18,w);
	local[12] = w;
	if (local[12]==NIL) goto IF30891;
	w = local[12];
	ctx->vsp=local+18;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK30634;
	goto IF30892;
IF30891:
	local[18]= NIL;
IF30892:
	goto WHL30820;
WHX30821:
	local[18]= NIL;
BLK30822:
	w = NIL;
	local[16]= fqv[74];
	local[17]= argv[0];
	ctx->vsp=local+18;
	w=(pointer)SIGERROR(ctx,2,local+16); /*error*/
	local[16]= w;
IF30749:
	w = local[16];
	local[13]= w;
	ctx->vsp=local+14;
	unbindx(ctx,1);
	w = local[13];
	local[0]= w;
BLK30634:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET30722(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (env->c.clo.env2[5]==NIL) goto IF30921;
	local[0]= T;
	local[1]= fqv[75];
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,1,local+3,&ftab[0],fqv[0]); /*namestring*/
	local[3]= w;
	local[4]= loadglobal(fqv[63]);
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= w;
	goto IF30922;
IF30921:
	local[0]= NIL;
IF30922:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET30724(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[13])(ctx,1,local+0,&ftab[13],fqv[76]); /*directory-namestring*/
	local[0]= w;
	w = loadglobal(fqv[68]);
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	local[1]= NIL;
	local[2]= NIL;
	w = local[0];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[68],w);
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,1,local+6,&ftab[0],fqv[0]); /*namestring*/
	argv[0] = w;
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)F28933object_file_p(ctx,1,local+6); /*object-file-p*/
	if (w==NIL) goto CON30983;
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(*ftab[7])(ctx,1,local+6,&ftab[7],fqv[52]); /*pathname-name*/
	local[6]= w;
	local[7]= loadglobal(fqv[77]);
	local[8]= fqv[78];
	local[9]= (pointer)get_sym_func(fqv[79]);
	local[10]= fqv[70];
	local[11]= (pointer)get_sym_func(fqv[80]);
	ctx->vsp=local+12;
	w=(*ftab[14])(ctx,6,local+6,&ftab[14],fqv[81]); /*find*/
	local[1] = w;
	if (local[1]==NIL) goto IF30992;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[15])(ctx,1,local+6,&ftab[15],fqv[82]); /*system::unbinload*/
	local[6]= T;
	local[7]= fqv[83];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	goto IF30993;
IF30992:
	local[6]= NIL;
IF30993:
	local[6]= fqv[84];
	local[7]= argv[0];
	w = env->c.clo.env2[13];
	ctx->vsp=local+8;
	w=FLET30722(ctx,2,local+6,w);
	local[6]= argv[0];
	local[7]= env->c.clo.env2[1];
	ctx->vsp=local+8;
	w=(pointer)BINLOAD(ctx,2,local+6); /*system:binload*/
	local[2] = w;
	if (local[2]==NIL) goto IF31048;
	local[6]= local[2];
	w = loadglobal(fqv[77]);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	storeglobal(fqv[77],local[6]);
	goto IF31049;
IF31048:
	local[6]= NIL;
IF31049:
	local[6]= local[2];
	goto CON30981;
CON30983:
	local[6]= fqv[85];
	local[7]= argv[0];
	w = env->c.clo.env2[13];
	ctx->vsp=local+8;
	w=FLET30722(ctx,2,local+6,w);
	local[6]= argv[0];
	local[7]= env->c.clo.env2[6];
	ctx->vsp=local+8;
	w=(pointer)F28942system__txtload(ctx,2,local+6); /*system::txtload*/
	local[6]= T;
	goto CON30981;
CON31068:
	local[6]= NIL;
CON30981:
	ctx->vsp=local+7;
	unbindx(ctx,1);
	w = local[6];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET30726(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)F28929probe_file(ctx,1,local+2); /*probe-file*/
	local[2]= w;
	local[3]= fqv[86];
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,2,local+2,&ftab[16],fqv[87]); /*member*/
	if (w==NIL) goto CON31110;
	local[2]= argv[0];
	w = env->c.clo.env2[14];
	ctx->vsp=local+3;
	w=FLET30724(ctx,1,local+2,w);
	local[2]= w;
	goto CON31108;
CON31110:
	local[2]= fqv[88];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,2,local+2,&ftab[6],fqv[51]); /*merge-pathnames*/
	local[0] = w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F28929probe_file(ctx,1,local+2); /*probe-file*/
	if (w==NIL) goto CON31127;
	local[2]= local[0];
	w = env->c.clo.env2[14];
	ctx->vsp=local+3;
	w=FLET30724(ctx,1,local+2,w);
	local[2]= w;
	goto CON31108;
CON31127:
	local[2]= fqv[89];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,2,local+2,&ftab[6],fqv[51]); /*merge-pathnames*/
	local[0] = w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F28929probe_file(ctx,1,local+2); /*probe-file*/
	if (w==NIL) goto CON31146;
	local[2]= local[0];
	w = env->c.clo.env2[14];
	ctx->vsp=local+3;
	w=FLET30724(ctx,1,local+2,w);
	local[2]= w;
	goto CON31108;
CON31146:
	local[2]= fqv[90];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,2,local+2,&ftab[6],fqv[51]); /*merge-pathnames*/
	local[0] = w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F28929probe_file(ctx,1,local+2); /*probe-file*/
	if (w==NIL) goto CON31165;
	local[2]= local[0];
	w = env->c.clo.env2[14];
	ctx->vsp=local+3;
	w=FLET30724(ctx,1,local+2,w);
	local[2]= w;
	goto CON31108;
CON31165:
	local[2]= fqv[91];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,2,local+2,&ftab[6],fqv[51]); /*merge-pathnames*/
	local[0] = w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F28929probe_file(ctx,1,local+2); /*probe-file*/
	if (w==NIL) goto CON31184;
	local[2]= local[0];
	w = env->c.clo.env2[14];
	ctx->vsp=local+3;
	w=FLET30724(ctx,1,local+2,w);
	local[2]= w;
	goto CON31108;
CON31184:
	local[2]= fqv[92];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,2,local+2,&ftab[6],fqv[51]); /*merge-pathnames*/
	local[1] = w;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)F28929probe_file(ctx,1,local+2); /*probe-file*/
	if (w==NIL) goto CON31203;
	local[2]= local[1];
	w = env->c.clo.env2[14];
	ctx->vsp=local+3;
	w=FLET30724(ctx,1,local+2,w);
	local[2]= w;
	goto CON31108;
CON31203:
	local[2]= NIL;
CON31108:
	w = local[2];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*load-files*/
static pointer F28961load_files(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST31228:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= local[0];
WHL31254:
	if (local[2]==NIL) goto WHX31255;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	local[4]= fqv[93];
	local[5]= T;
	ctx->vsp=local+6;
	w=(pointer)F28958load(ctx,3,local+3); /*load*/
	goto WHL31254;
WHX31255:
	local[3]= NIL;
BLK31256:
	w = NIL;
	w = T;
	local[0]= w;
BLK31226:
	ctx->vsp=local; return(local[0]);}

/*read-file*/
static pointer F28964read_file(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F28924open(ctx,1,local+0); /*open*/
	local[0]= w;
	ctx->vsp=local+1;
	w = makeclosure(codevec,quotevec,UWP31339,env,argv,local);
	local[1]=(pointer)(ctx->protfp); local[2]=w;
	ctx->protfp=(struct protectframe *)(local+1);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)READ(ctx,1,local+3); /*read*/
	ctx->vsp=local+3;
	UWP31339(ctx,0,local+3,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK31315:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP31339(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[0];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*read-strings*/
static pointer F28967read_strings(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F28924open(ctx,1,local+0); /*open*/
	local[0]= w;
	ctx->vsp=local+1;
	w = makeclosure(codevec,quotevec,UWP31388,env,argv,local);
	local[1]=(pointer)(ctx->protfp); local[2]=w;
	ctx->protfp=(struct protectframe *)(local+1);
	local[3]= NIL;
	local[4]= NIL;
	w = NIL;
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= NIL;
WHL31413:
	local[6]= local[0];
	local[7]= NIL;
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)READLINE(ctx,3,local+6); /*read-line*/
	local[3] = w;
	local[6]= local[3];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w!=NIL) goto WHX31414;
	local[6]= local[3];
	w = local[5];
	ctx->vsp=local+7;
	local[5] = cons(ctx,local[6],w);
	local[6]= fqv[94];
	w = local[5];
	ctx->vsp=local+7;
	local[5] = cons(ctx,local[6],w);
	goto WHL31413;
WHX31414:
	local[6]= NIL;
BLK31415:
	local[6]= (pointer)get_sym_func(fqv[95]);
	local[7]= loadglobal(fqv[22]);
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)NREVERSE(ctx,1,local+8); /*nreverse*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,3,local+6); /*apply*/
	ctx->vsp=local+3;
	UWP31388(ctx,0,local+3,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK31364:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP31388(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[0];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*read-lines*/
static pointer F28970read_lines(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F28924open(ctx,1,local+0); /*open*/
	local[0]= w;
	ctx->vsp=local+1;
	w = makeclosure(codevec,quotevec,UWP31503,env,argv,local);
	local[1]=(pointer)(ctx->protfp); local[2]=w;
	ctx->protfp=(struct protectframe *)(local+1);
	local[3]= NIL;
	local[4]= NIL;
	w = NIL;
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= NIL;
WHL31528:
	local[6]= local[0];
	local[7]= NIL;
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)READLINE(ctx,3,local+6); /*read-line*/
	local[3] = w;
	local[6]= local[3];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w!=NIL) goto WHX31529;
	local[6]= local[3];
	w = local[5];
	ctx->vsp=local+7;
	local[5] = cons(ctx,local[6],w);
	goto WHL31528;
WHX31529:
	local[6]= NIL;
BLK31530:
	local[6]= local[5];
	ctx->vsp=local+7;
	w=(pointer)NREVERSE(ctx,1,local+6); /*nreverse*/
	ctx->vsp=local+3;
	UWP31503(ctx,0,local+3,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK31479:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP31503(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[0];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*read-lists*/
static pointer F28973read_lists(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	w = NIL;
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F28924open(ctx,1,local+3); /*open*/
	local[3]= w;
	ctx->vsp=local+4;
	w = makeclosure(codevec,quotevec,UWP31621,env,argv,local);
	local[4]=(pointer)(ctx->protfp); local[5]=w;
	ctx->protfp=(struct protectframe *)(local+4);
WHL31628:
	local[6]= local[3];
	local[7]= NIL;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)READ(ctx,3,local+6); /*read*/
	local[1] = w;
	local[6]= local[1];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w!=NIL) goto WHX31629;
	local[6]= local[1];
	w = local[2];
	ctx->vsp=local+7;
	local[2] = cons(ctx,local[6],w);
	goto WHL31628;
WHX31629:
	local[6]= NIL;
BLK31630:
	w = local[6];
	ctx->vsp=local+6;
	UWP31621(ctx,0,local+6,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	local[0]= w;
BLK31578:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP31621(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[3];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*read-binary-file*/
static pointer F28976read_binary_file(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*namestring*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)F28994file_size(ctx,1,local+0); /*file-size*/
	local[0]= w;
	local[1]= NIL;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[44]); /*make-string*/
	local[2]= w;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F28924open(ctx,1,local+3); /*open*/
	local[3]= w;
	ctx->vsp=local+4;
	w = makeclosure(codevec,quotevec,UWP31722,env,argv,local);
	local[4]=(pointer)(ctx->protfp); local[5]=w;
	ctx->protfp=(struct protectframe *)(local+4);
	local[6]= local[3];
	local[7]= fqv[96];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= local[2];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)UNIXREAD(ctx,3,local+6); /*unix:uread*/
	local[1] = w;
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[17])(ctx,2,local+6,&ftab[17],fqv[97]); /*/=*/
	if (w==NIL) goto IF31744;
	local[6]= fqv[98];
	ctx->vsp=local+7;
	w=(pointer)SIGERROR(ctx,1,local+6); /*error*/
	local[6]= w;
	goto IF31745;
IF31744:
	local[6]= NIL;
IF31745:
	w = local[6];
	ctx->vsp=local+6;
	UWP31722(ctx,0,local+6,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	w = local[2];
	local[0]= w;
BLK31678:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP31722(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[3];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*read-lines-till-eof*/
static pointer F28979read_lines_till_eof(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	w = NIL;
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
WHL31804:
	local[3]= argv[0];
	local[4]= NIL;
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)READLINE(ctx,3,local+3); /*read-line*/
	local[1] = w;
	local[3]= local[1];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w!=NIL) goto WHX31805;
	local[3]= local[1];
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	goto WHL31804;
WHX31805:
	local[3]= NIL;
BLK31806:
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	local[0]= w;
BLK31775:
	ctx->vsp=local; return(local[0]);}

/*do-file-line*/
static pointer F31841(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST31844:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+1;
	w=(pointer)GENSYM(ctx,0,local+1); /*gensym*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,0,local+2); /*gensym*/
	local[2]= w;
	w = local[1];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[99],w);
	local[6]= fqv[100];
	local[7]= loadglobal(fqv[99]);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[24];
	local[9]= local[2];
	local[10]= fqv[56];
	local[11]= fqv[19];
	local[12]= fqv[19];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[101];
	local[11]= fqv[102];
	local[12]= fqv[103];
	local[13]= local[2];
	local[14]= fqv[104];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	local[16]= fqv[105];
	local[17]= loadglobal(fqv[99]);
	local[18]= fqv[19];
	local[19]= local[2];
	ctx->vsp=local+20;
	w=(pointer)LIST(ctx,1,local+19); /*list*/
	ctx->vsp=local+19;
	w = cons(ctx,local[18],w);
	ctx->vsp=local+18;
	w = cons(ctx,local[17],w);
	ctx->vsp=local+17;
	local[16]= cons(ctx,local[16],w);
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	w = local[0];
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	unbindx(ctx,1);
	w = local[6];
	local[0]= w;
BLK31842:
	ctx->vsp=local; return(local[0]);}

/*do-file-form*/
static pointer F31989(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST31992:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+1;
	w=(pointer)GENSYM(ctx,0,local+1); /*gensym*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,0,local+2); /*gensym*/
	local[2]= w;
	w = local[1];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[99],w);
	local[6]= fqv[100];
	local[7]= loadglobal(fqv[99]);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[24];
	local[9]= local[2];
	local[10]= fqv[56];
	local[11]= fqv[19];
	local[12]= fqv[19];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[101];
	local[11]= fqv[102];
	local[12]= fqv[103];
	local[13]= local[2];
	local[14]= fqv[104];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	local[16]= fqv[106];
	local[17]= loadglobal(fqv[99]);
	local[18]= fqv[19];
	local[19]= local[2];
	ctx->vsp=local+20;
	w=(pointer)LIST(ctx,1,local+19); /*list*/
	ctx->vsp=local+19;
	w = cons(ctx,local[18],w);
	ctx->vsp=local+18;
	w = cons(ctx,local[17],w);
	ctx->vsp=local+17;
	local[16]= cons(ctx,local[16],w);
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	w = local[0];
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	unbindx(ctx,1);
	w = local[6];
	local[0]= w;
BLK31990:
	ctx->vsp=local; return(local[0]);}

/*load-library*/
static pointer F28984load_library(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST32139:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[107]);
	local[2]= argv[0];
	local[3]= fqv[108];
	local[4]= NIL;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	local[1]= w;
	local[2]= local[1];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(*ftab[18])(ctx,2,local+2,&ftab[18],fqv[109]); /*system::list-module-initializers*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= local[2];
WHL32194:
	if (local[5]==NIL) goto WHX32195;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= loadglobal(fqv[110]);
	ctx->vsp=local+7;
	w=(pointer)ISATTY(ctx,1,local+6); /*unix:isatty*/
	if (w==NIL) goto IF32244;
	local[6]= loadglobal(fqv[111]);
	local[7]= fqv[112];
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= loadglobal(fqv[111]);
	ctx->vsp=local+7;
	w=(pointer)FINOUT(ctx,1,local+6); /*finish-output*/
	local[6]= w;
	goto IF32245;
IF32244:
	local[6]= NIL;
IF32245:
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)FUNCALL(ctx,2,local+6); /*funcall*/
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w = local[3];
	ctx->vsp=local+7;
	local[3] = cons(ctx,local[6],w);
	goto WHL32194;
WHX32195:
	local[6]= NIL;
BLK32196:
	w = NIL;
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(pointer)NREVERSE(ctx,1,local+4); /*nreverse*/
	local[0]= w;
BLK32137:
	ctx->vsp=local; return(local[0]);}

/*dump-object*/
static pointer F28987dump_object(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST32314:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= T;
	local[2]= T;
	local[3]= NIL;
	local[4]= NIL;
	w = local[4];
	ctx->vsp=local+5;
	bindspecial(ctx,fqv[113],w);
	w = local[3];
	ctx->vsp=local+8;
	bindspecial(ctx,fqv[114],w);
	w = local[2];
	ctx->vsp=local+11;
	bindspecial(ctx,fqv[115],w);
	w = local[1];
	ctx->vsp=local+14;
	bindspecial(ctx,fqv[116],w);
	local[17]= argv[0];
	ctx->vsp=local+18;
	w=(pointer)STREAMP(ctx,1,local+17); /*streamp*/
	if (w==NIL) goto IF32356;
	local[17]= NIL;
	local[18]= local[0];
WHL32381:
	if (local[18]==NIL) goto WHX32382;
	w=local[18];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	w=local[18];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18] = (w)->c.cons.cdr;
	w = local[19];
	local[17] = w;
	local[19]= local[17];
	local[20]= argv[0];
	ctx->vsp=local+21;
	w=(pointer)PRINT(ctx,2,local+19); /*print*/
	goto WHL32381;
WHX32382:
	local[19]= NIL;
BLK32383:
	w = NIL;
	local[17]= w;
	goto IF32357;
IF32356:
	local[17]= argv[0];
	local[18]= fqv[117];
	local[19]= fqv[118];
	ctx->vsp=local+20;
	w=(pointer)F28924open(ctx,3,local+17); /*open*/
	local[17]= w;
	ctx->vsp=local+18;
	w = makeclosure(codevec,quotevec,UWP32455,env,argv,local);
	local[18]=(pointer)(ctx->protfp); local[19]=w;
	ctx->protfp=(struct protectframe *)(local+18);
	local[20]= NIL;
	local[21]= local[0];
WHL32479:
	if (local[21]==NIL) goto WHX32480;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21] = (w)->c.cons.cdr;
	w = local[22];
	local[20] = w;
	local[22]= local[20];
	local[23]= local[17];
	ctx->vsp=local+24;
	w=(pointer)PRINT(ctx,2,local+22); /*print*/
	goto WHL32479;
WHX32480:
	local[22]= NIL;
BLK32481:
	w = NIL;
	ctx->vsp=local+20;
	UWP32455(ctx,0,local+20,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[17]= w;
IF32357:
	ctx->vsp=local+18;
	unbindx(ctx,4);
	w = local[17];
	local[0]= w;
BLK32312:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP32455(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[17];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*dump-structure*/
static pointer F28990dump_structure(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST32553:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= T;
	local[2]= T;
	local[3]= NIL;
	local[4]= NIL;
	w = local[4];
	ctx->vsp=local+5;
	bindspecial(ctx,fqv[113],w);
	w = local[3];
	ctx->vsp=local+8;
	bindspecial(ctx,fqv[114],w);
	w = local[2];
	ctx->vsp=local+11;
	bindspecial(ctx,fqv[115],w);
	w = local[1];
	ctx->vsp=local+14;
	bindspecial(ctx,fqv[119],w);
	local[17]= argv[0];
	ctx->vsp=local+18;
	w=(pointer)STREAMP(ctx,1,local+17); /*streamp*/
	if (w==NIL) goto IF32595;
	local[17]= NIL;
	local[18]= local[0];
WHL32620:
	if (local[18]==NIL) goto WHX32621;
	w=local[18];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	w=local[18];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18] = (w)->c.cons.cdr;
	w = local[19];
	local[17] = w;
	local[19]= local[17];
	local[20]= argv[0];
	ctx->vsp=local+21;
	w=(pointer)PRINT(ctx,2,local+19); /*print*/
	goto WHL32620;
WHX32621:
	local[19]= NIL;
BLK32622:
	w = NIL;
	local[17]= w;
	goto IF32596;
IF32595:
	local[17]= argv[0];
	local[18]= fqv[117];
	local[19]= fqv[118];
	ctx->vsp=local+20;
	w=(pointer)F28924open(ctx,3,local+17); /*open*/
	local[17]= w;
	ctx->vsp=local+18;
	w = makeclosure(codevec,quotevec,UWP32694,env,argv,local);
	local[18]=(pointer)(ctx->protfp); local[19]=w;
	ctx->protfp=(struct protectframe *)(local+18);
	local[20]= NIL;
	local[21]= local[0];
WHL32718:
	if (local[21]==NIL) goto WHX32719;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21] = (w)->c.cons.cdr;
	w = local[22];
	local[20] = w;
	local[22]= local[20];
	local[23]= local[17];
	ctx->vsp=local+24;
	w=(pointer)PRINT(ctx,2,local+22); /*print*/
	goto WHL32718;
WHX32719:
	local[22]= NIL;
BLK32720:
	w = NIL;
	ctx->vsp=local+20;
	UWP32694(ctx,0,local+20,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[17]= w;
IF32596:
	ctx->vsp=local+18;
	unbindx(ctx,4);
	w = local[17];
	local[0]= w;
BLK32551:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP32694(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[17];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*dump-loadable-structure*/
static pointer F32790(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST32793:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= local[0];
WHL32831:
	if (local[3]==NIL) goto WHX32832;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= fqv[120];
	local[5]= fqv[104];
	local[6]= local[2];
	local[7]= fqv[120];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)SYMVALUE(ctx,1,local+8); /*symbol-value*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,3,local+5); /*list*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,2,local+4); /*list*/
	local[4]= w;
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	goto WHL32831;
WHX32832:
	local[4]= NIL;
BLK32833:
	w = NIL;
	local[2]= fqv[121];
	local[3]= argv[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)REVERSE(ctx,1,local+4); /*reverse*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[0]= w;
BLK32791:
	ctx->vsp=local; return(local[0]);}

/*file-size*/
static pointer F28994file_size(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*namestring*/
	argv[0] = w;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F28929probe_file(ctx,1,local+0); /*probe-file*/
	if (w==NIL) goto IF32944;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*namestring*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)STAT(ctx,1,local+0); /*unix:stat*/
	local[0]= w;
	local[1]= makeint(7);
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	goto IF32945;
IF32944:
	local[0]= fqv[122];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,2,local+0); /*error*/
	local[0]= w;
IF32945:
	w = local[0];
	local[0]= w;
BLK32925:
	ctx->vsp=local; return(local[0]);}

/*directory-p*/
static pointer F28997directory_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)STAT(ctx,1,local+2); /*unix:stat*/
	local[1] = w;
	w = local[1];
	if (!iscons(w)) goto IF32978;
	local[2]= makeint(16384);
	local[3]= local[1];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LOGAND(ctx,2,local+2); /*logand*/
	local[2]= w;
	local[3]= makeint(16384);
	ctx->vsp=local+4;
	w=(pointer)NUMEQUAL(ctx,2,local+2); /*=*/
	local[2]= w;
	goto IF32979;
IF32978:
	local[2]= NIL;
IF32979:
	w = local[2];
	local[0]= w;
BLK32964:
	ctx->vsp=local; return(local[0]);}

/*map-file*/
static pointer F29000map_file(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[123], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY33018;
	local[0] = fqv[2];
KEY33018:
	if (n & (1<<1)) goto KEY33025;
	local[1] = makeint(0);
KEY33025:
	if (n & (1<<2)) goto KEY33030;
	local[2] = NIL;
KEY33030:
	if (n & (1<<3)) goto KEY33035;
	local[3] = NIL;
KEY33035:
	if (n & (1<<4)) goto KEY33040;
	local[4] = T;
KEY33040:
	if (n & (1<<5)) goto KEY33045;
	local[5] = NIL;
KEY33045:
	if (n & (1<<6)) goto KEY33050;
	local[6] = makeint(0);
KEY33050:
	local[7]= NIL;
	local[8]= makeint(0);
	local[9]= NIL;
	local[10]= argv[0];
	local[11]= fqv[117];
	local[12]= local[0];
	local[13]= fqv[124];
	local[14]= fqv[13];
	ctx->vsp=local+15;
	w=(pointer)F28924open(ctx,5,local+10); /*open*/
	local[7] = w;
	if (local[2]!=NIL) goto IF33088;
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)F28994file_size(ctx,1,local+10); /*file-size*/
	local[2] = w;
	local[10]= local[2];
	goto IF33089;
IF33088:
	local[10]= NIL;
IF33089:
	if (local[3]!=NIL) goto IF33107;
	local[10]= local[0];
	local[11]= fqv[125];
	ctx->vsp=local+12;
	w=(pointer)ASSQ(ctx,2,local+10); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	local[10]= local[3];
	goto IF33108;
IF33107:
	local[10]= NIL;
IF33108:
	if (local[4]==NIL) goto IF33131;
	local[8] = makeint(1);
	local[10]= local[8];
	goto IF33132;
IF33131:
	local[10]= NIL;
IF33132:
	if (local[5]==NIL) goto IF33143;
	local[8] = makeint(2);
	local[10]= local[8];
	goto IF33144;
IF33143:
	local[10]= NIL;
IF33144:
	local[10]= local[6];
	local[11]= local[2];
	local[12]= local[3];
	local[13]= local[8];
	local[14]= local[7];
	local[15]= local[1];
	ctx->vsp=local+16;
	w=(*ftab[19])(ctx,6,local+10,&ftab[19],fqv[126]); /*unix:mmap*/
	local[9] = w;
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)CLOSE(ctx,1,local+10); /*close*/
	w = local[9];
	local[0]= w;
BLK33003:
	ctx->vsp=local; return(local[0]);}

/*provide*/
static pointer F29002provide(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST33181:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[20])(ctx,1,local+1,&ftab[20],fqv[127]); /*keywordp*/
	if (w!=NIL) goto IF33193;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,1,local+1,&ftab[21],fqv[22]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[22])(ctx,1,local+1,&ftab[22],fqv[128]); /*string-upcase*/
	local[1]= w;
	local[2]= loadglobal(fqv[129]);
	ctx->vsp=local+3;
	w=(pointer)INTERN(ctx,2,local+1); /*intern*/
	argv[0] = w;
	local[1]= argv[0];
	goto IF33194;
IF33193:
	local[1]= NIL;
IF33194:
	local[1]= argv[0];
	local[2]= loadglobal(fqv[130]);
	ctx->vsp=local+3;
	w=(*ftab[23])(ctx,2,local+1,&ftab[23],fqv[131]); /*assoc*/
	if (w!=NIL) goto IF33223;
	local[1]= loadglobal(fqv[130]);
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST_STAR(ctx,2,local+2); /*list**/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)NCONC(ctx,2,local+1); /*nconc*/
	local[1]= w;
	storeglobal(fqv[130],w);
	goto IF33224;
IF33223:
	local[1]= NIL;
IF33224:
	w = argv[0];
	local[0]= w;
BLK33179:
	ctx->vsp=local; return(local[0]);}

/*require*/
static pointer F29004require(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST33256:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[20])(ctx,1,local+1,&ftab[20],fqv[127]); /*keywordp*/
	if (w!=NIL) goto IF33268;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,1,local+1,&ftab[21],fqv[22]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[22])(ctx,1,local+1,&ftab[22],fqv[128]); /*string-upcase*/
	local[1]= w;
	local[2]= loadglobal(fqv[129]);
	ctx->vsp=local+3;
	w=(pointer)INTERN(ctx,2,local+1); /*intern*/
	argv[0] = w;
	local[1]= argv[0];
	goto IF33269;
IF33268:
	local[1]= NIL;
IF33269:
	local[1]= argv[0];
	local[2]= loadglobal(fqv[130]);
	ctx->vsp=local+3;
	w=(*ftab[23])(ctx,2,local+1,&ftab[23],fqv[131]); /*assoc*/
	if (w!=NIL) goto IF33295;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (isstring(w)) goto IF33308;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,1,local+1,&ftab[21],fqv[22]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[24])(ctx,1,local+1,&ftab[24],fqv[132]); /*string-downcase*/
	local[1]= w;
	w = local[0];
	ctx->vsp=local+2;
	local[0] = cons(ctx,local[1],w);
	local[1]= local[0];
	goto IF33309;
IF33308:
	local[1]= NIL;
IF33309:
	local[1]= (pointer)get_sym_func(fqv[107]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F29002provide(ctx,1,local+1); /*provide*/
	local[1]= w;
	goto IF33296;
IF33295:
	local[1]= NIL;
IF33296:
	w = local[1];
	local[0]= w;
BLK33254:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___loader(ctx,n,argv,env)
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
	local[0]= fqv[133];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= fqv[134];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF33356;
	local[0]= fqv[135];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[63],w);
	goto IF33357;
IF33356:
	local[0]= fqv[136];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF33357:
	local[0]= fqv[137];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[138],module,F28918file_write_date,fqv[139]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[140],module,F28921file_newer,fqv[141]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[25],module,F28924open,fqv[142]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[100],module,F29590,fqv[143]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[144],module,F28929probe_file,fqv[145]);
	local[0]= fqv[43];
	local[1]= fqv[146];
	local[2]= fqv[147];
	local[3]= loadglobal(fqv[148]);
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,2,local+2,&ftab[16],fqv[87]); /*member*/
	if (w==NIL) goto CON33396;
	local[2]= makeint(7);
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	goto CON33394;
CON33396:
	local[2]= fqv[149];
	local[3]= loadglobal(fqv[148]);
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,2,local+2,&ftab[16],fqv[87]); /*member*/
	if (w==NIL) goto CON33408;
	local[2]= makeint(127);
	local[3]= makeint(69);
	local[4]= makeint(76);
	local[5]= makeint(70);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	goto CON33394;
CON33408:
	local[2]= fqv[150];
	local[3]= loadglobal(fqv[148]);
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,2,local+2,&ftab[16],fqv[87]); /*member*/
	if (w==NIL) goto CON33419;
	local[2]= makeint(127);
	local[3]= makeint(69);
	local[4]= makeint(76);
	local[5]= makeint(70);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	goto CON33394;
CON33419:
	local[2]= fqv[151];
	local[3]= loadglobal(fqv[148]);
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,2,local+2,&ftab[16],fqv[87]); /*member*/
	if (w==NIL) goto CON33430;
	local[2]= makeint(98);
	local[3]= makeint(1);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	goto CON33394;
CON33430:
	local[2]= fqv[152];
	local[3]= loadglobal(fqv[148]);
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,2,local+2,&ftab[16],fqv[87]); /*member*/
	if (w==NIL) goto CON33441;
	local[2]= makeint(127);
	local[3]= makeint(69);
	local[4]= makeint(76);
	local[5]= makeint(70);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	goto CON33394;
CON33441:
	local[2]= fqv[153];
	local[3]= loadglobal(fqv[148]);
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,2,local+2,&ftab[16],fqv[87]); /*member*/
	if (w==NIL) goto CON33452;
	local[2]= fqv[154];
	local[3]= fqv[155];
	local[4]= fqv[156];
	local[5]= fqv[157];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	goto CON33394;
CON33452:
	local[2]= fqv[158];
	local[3]= loadglobal(fqv[148]);
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,2,local+2,&ftab[16],fqv[87]); /*member*/
	if (w==NIL) goto CON33471;
	local[2]= makeint(127);
	local[3]= makeint(69);
	local[4]= makeint(76);
	local[5]= makeint(70);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	goto CON33394;
CON33471:
	local[2]= fqv[159];
	local[3]= loadglobal(fqv[148]);
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,2,local+2,&ftab[16],fqv[87]); /*member*/
	if (w==NIL) goto CON33482;
	local[2]= makeint(77);
	local[3]= makeint(90);
	local[4]= makeint(144);
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	goto CON33394;
CON33482:
	local[2]= fqv[160];
	local[3]= loadglobal(fqv[148]);
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,2,local+2,&ftab[16],fqv[87]); /*member*/
	if (w==NIL) goto CON33493;
	local[2]= makeint(131);
	local[3]= makeint(1);
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,3,local+2); /*list*/
	local[2]= w;
	goto CON33394;
CON33493:
	local[2]= NIL;
	local[3]= NIL;
	local[4]= makeint(1);
	local[5]= fqv[161];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	goto CON33394;
CON33504:
	local[2]= NIL;
CON33394:
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[162],module,F28933object_file_p,fqv[163]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[164],module,F28936path_list,fqv[165]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[166],module,F28939find_executable,fqv[167]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[168],module,F28942system__txtload,fqv[169]);
	local[0]= fqv[69];
	local[1]= fqv[170];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF33523;
	local[0]= fqv[69];
	local[1]= fqv[170];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[69];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF33546;
	local[0]= fqv[69];
	local[1]= fqv[171];
	local[2]= fqv[172];
	local[3]= loadglobal(fqv[173]);
	local[4]= NIL;
	local[5]= fqv[174];
	local[6]= loadglobal(fqv[173]);
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= w;
	local[5]= NIL;
	local[6]= fqv[175];
	local[7]= loadglobal(fqv[173]);
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,3,local+5); /*format*/
	local[5]= w;
	local[6]= NIL;
	local[7]= fqv[176];
	local[8]= loadglobal(fqv[173]);
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,5,local+2); /*list*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF33547;
IF33546:
	local[0]= NIL;
IF33547:
	local[0]= fqv[69];
	goto IF33524;
IF33523:
	local[0]= NIL;
IF33524:
	local[0]= fqv[68];
	local[1]= fqv[177];
	local[2]= fqv[178];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[62];
	local[1]= fqv[170];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF33589;
	local[0]= fqv[62];
	local[1]= fqv[170];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[62];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF33612;
	local[0]= fqv[62];
	local[1]= fqv[171];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF33613;
IF33612:
	local[0]= NIL;
IF33613:
	local[0]= fqv[62];
	goto IF33590;
IF33589:
	local[0]= NIL;
IF33590:
	local[0]= fqv[77];
	local[1]= fqv[170];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF33632;
	local[0]= fqv[77];
	local[1]= fqv[170];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[77];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF33655;
	local[0]= fqv[77];
	local[1]= fqv[171];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF33656;
IF33655:
	local[0]= NIL;
IF33656:
	local[0]= fqv[77];
	goto IF33633;
IF33632:
	local[0]= NIL;
IF33633:
	ctx->vsp=local+0;
	compfun(ctx,fqv[79],module,F28952load_module_file_name,fqv[179]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[180],module,F28955gencname_tail,fqv[181]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[107],module,F28958load,fqv[182]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[183],module,F28961load_files,fqv[184]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[185],module,F28964read_file,fqv[186]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[187],module,F28967read_strings,fqv[188]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[189],module,F28970read_lines,fqv[190]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[191],module,F28973read_lists,fqv[192]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[193],module,F28976read_binary_file,fqv[194]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[195],module,F28979read_lines_till_eof,fqv[196]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[197],module,F31841,fqv[198]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[199],module,F31989,fqv[200]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[201],module,F28984load_library,fqv[202]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[203],module,F28987dump_object,fqv[204]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[121],module,F28990dump_structure,fqv[205]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[206],module,F32790,fqv[207]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[208],module,F28994file_size,fqv[209]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[210],module,F28997directory_p,fqv[211]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[212],module,F29000map_file,fqv[213]);
	local[0]= fqv[130];
	local[1]= fqv[170];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF33713;
	local[0]= fqv[130];
	local[1]= fqv[170];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[130];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF33736;
	local[0]= fqv[130];
	local[1]= fqv[171];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF33737;
IF33736:
	local[0]= NIL;
IF33737:
	local[0]= fqv[130];
	goto IF33714;
IF33713:
	local[0]= NIL;
IF33714:
	ctx->vsp=local+0;
	compfun(ctx,fqv[214],module,F29002provide,fqv[215]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[216],module,F29004require,fqv[217]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<25; i++) ftab[i]=fcallx;
}
