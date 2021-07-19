/* ./string.c :  entry=string */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "string.h"
#pragma init (register_string)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___string();
extern pointer build_quote_vector();
static int register_string()
  { add_module_initializer("___string", ___string);}

static pointer F51161read_sharp_backslash();
static pointer F51165true_string();
static pointer F51168string();
static pointer F51171make_string();
static pointer F51174string_left_trim();
static pointer F51177string_right_trim();
static pointer F51180string_trim();
static pointer F51183nstring_downcase();
static pointer F51186nstring_upcase();
static pointer F51189string_upcase();
static pointer F51192string_downcase();
static pointer F51195string_();
static pointer F51198string_equal();
static pointer F51201substringp();
static pointer F51211explode_directory_names();
static pointer F51215pathnamep();
static pointer F51218pathname();
static pointer F51221namestring();
static pointer F51224pathname_directory();
static pointer F51227pathname_name();
static pointer F51230pathname_type();
static pointer F51233directory_namestring();
static pointer F51236make_pathname();
static pointer F51239parse_namestring();
static pointer F51243null_string_p();
static pointer F51246merge_pathnames();
static pointer F51249concatenate_pathnames();
static pointer F51252truename();
static pointer F51271url_pathname();
static pointer F51273parse_url();
static pointer F51275escape_url();
static pointer F51277escaped_url_string_from_namestring();
static pointer F51279unescape_url();
static pointer F51281unescaped_url_string_from_namestring();
static pointer F51283digits_string();
static pointer F51285timed_file_name();
static pointer F51287dated_file_name();
static pointer F51289sequential_file_name();

/*read_sharp_backslash*/
static pointer F51161read_sharp_backslash(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)READCH(ctx,1,local+3); /*read-char*/
	local[0] = w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)ALPHAP(ctx,1,local+3); /*alpha-char-p*/
	if (w==NIL) goto CON51385;
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)UNREADCH(ctx,2,local+3); /*unread-char*/
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)READ(ctx,1,local+3); /*read*/
	local[1] = w;
	local[3]= *(ovafptr(local[1],fqv[0]));
	local[4]= fqv[1];
	local[5]= fqv[2];
	local[6]= (pointer)get_sym_func(fqv[3]);
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,4,local+3,&ftab[0],fqv[4]); /*assoc*/
	local[2] = w;
	if (local[2]==NIL) goto IF51424;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	goto IF51425;
IF51424:
	local[3]= *(ovafptr(local[1],fqv[0]));
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	if (makeint(1)!=local[3]) goto IF51437;
	local[3]= local[0];
	goto IF51438;
IF51437:
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
IF51438:
IF51425:
	goto CON51383;
CON51385:
	local[3]= local[0];
	goto CON51383;
CON51448:
	local[3]= NIL;
CON51383:
	w = local[3];
	local[0]= w;
BLK51347:
	ctx->vsp=local; return(local[0]);}

/*true-string*/
static pointer F51165true_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!issymbol(w)) goto IF51468;
	local[0]= argv[0]->c.obj.iv[4];
	goto IF51469;
IF51468:
	local[0]= argv[0];
IF51469:
	w = local[0];
	local[0]= w;
BLK51458:
	ctx->vsp=local; return(local[0]);}

/*string*/
static pointer F51168string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!isstring(w)) goto CON51494;
	local[0]= argv[0];
	goto CON51492;
CON51494:
	w = argv[0];
	if (!issymbol(w)) goto CON51500;
	local[0]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+1;
	w=(pointer)COPYSEQ(ctx,1,local+0); /*copy-seq*/
	local[0]= w;
	goto CON51492;
CON51500:
	w = argv[0];
	if (!isnum(w)) goto CON51512;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[6]); /*princ-to-string*/
	local[0]= w;
	goto CON51492;
CON51512:
	local[0]= fqv[7];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,2,local+0); /*error*/
	local[0]= w;
	goto CON51492;
CON51521:
	local[0]= NIL;
CON51492:
	w = local[0];
	local[0]= w;
BLK51482:
	ctx->vsp=local; return(local[0]);}

/*make-string*/
static pointer F51171make_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[8]);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,2,local+0); /*instantiate*/
	local[0]= w;
BLK51530:
	ctx->vsp=local; return(local[0]);}

/*string-left-trim*/
static pointer F51174string_left_trim(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint(0);
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F51165true_string(ctx,1,local+1); /*true-string*/
	argv[1] = w;
WHL51590:
	local[1]= argv[1];
	{ register eusinteger_t i=intval(local[0]);
	  w=makeint(local[1]->c.str.chars[i]);}
	local[1]= w;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[9]); /*position*/
	if (w==NIL) goto WHX51591;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)ADD1(ctx,1,local+1); /*1+*/
	local[0] = w;
	goto WHL51590;
WHX51591:
	local[1]= NIL;
BLK51592:
	local[1]= argv[1];
	local[2]= local[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SUBSEQ(ctx,3,local+1); /*subseq*/
	local[0]= w;
BLK51547:
	ctx->vsp=local; return(local[0]);}

/*string-right-trim*/
static pointer F51177string_right_trim(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F51165true_string(ctx,1,local+1); /*true-string*/
	argv[1] = w;
WHL51666:
	local[1]= argv[1];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)SUB1(ctx,1,local+2); /*1-*/
	{ register eusinteger_t i=intval(w);
	  w=makeint(local[1]->c.str.chars[i]);}
	local[1]= w;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[9]); /*position*/
	if (w==NIL) goto WHX51667;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)SUB1(ctx,1,local+1); /*1-*/
	local[0] = w;
	goto WHL51666;
WHX51667:
	local[1]= NIL;
BLK51668:
	local[1]= argv[1];
	local[2]= makeint(0);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SUBSEQ(ctx,3,local+1); /*subseq*/
	local[0]= w;
BLK51626:
	ctx->vsp=local; return(local[0]);}

/*string-trim*/
static pointer F51180string_trim(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)F51177string_right_trim(ctx,2,local+1); /*string-right-trim*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F51174string_left_trim(ctx,2,local+0); /*string-left-trim*/
	local[0]= w;
BLK51700:
	ctx->vsp=local; return(local[0]);}

/*nstring-downcase*/
static pointer F51183nstring_downcase(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[10], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY51744;
	local[0] = makeint(0);
KEY51744:
	if (n & (1<<1)) goto KEY51748;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[1] = w;
KEY51748:
	w = argv[0];
	if (isstring(w)) goto IF51759;
	local[2]= fqv[11];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,1,local+2); /*error*/
	local[2]= w;
	goto IF51760;
IF51759:
	local[2]= NIL;
IF51760:
WHL51768:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX51769;
	local[2]= argv[0];
	local[3]= local[0];
	local[4]= argv[0];
	{ register eusinteger_t i=intval(local[0]);
	  w=makeint(local[4]->c.str.chars[i]);}
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)CHDOWNCASE(ctx,1,local+4); /*char-downcase*/
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[3]); v=local[2];
	  v->c.str.chars[i]=intval(w);}
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL51768;
WHX51769:
	local[2]= NIL;
BLK51770:
	w = argv[0];
	local[0]= w;
BLK51721:
	ctx->vsp=local; return(local[0]);}

/*nstring-upcase*/
static pointer F51186nstring_upcase(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[12], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY51822;
	local[0] = makeint(0);
KEY51822:
	if (n & (1<<1)) goto KEY51826;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[1] = w;
KEY51826:
	w = argv[0];
	if (isstring(w)) goto IF51837;
	local[2]= fqv[13];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,1,local+2); /*error*/
	local[2]= w;
	goto IF51838;
IF51837:
	local[2]= NIL;
IF51838:
WHL51846:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX51847;
	local[2]= argv[0];
	local[3]= local[0];
	local[4]= argv[0];
	{ register eusinteger_t i=intval(local[0]);
	  w=makeint(local[4]->c.str.chars[i]);}
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)CHUPCASE(ctx,1,local+4); /*char-upcase*/
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[3]); v=local[2];
	  v->c.str.chars[i]=intval(w);}
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL51846;
WHX51847:
	local[2]= NIL;
BLK51848:
	w = argv[0];
	local[0]= w;
BLK51803:
	ctx->vsp=local; return(local[0]);}

/*string-upcase*/
static pointer F51189string_upcase(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[14], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY51891;
	local[0] = makeint(0);
KEY51891:
	if (n & (1<<1)) goto KEY51896;
	local[1] = NIL;
KEY51896:
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)F51165true_string(ctx,1,local+2); /*true-string*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)COPYSEQ(ctx,1,local+2); /*copy-seq*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[15];
	local[5]= local[0];
	local[6]= fqv[16];
	if (local[1]==NIL) goto IF51927;
	local[7]= local[1];
	goto IF51928;
IF51927:
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
IF51928:
	ctx->vsp=local+8;
	w=(pointer)F51186nstring_upcase(ctx,5,local+3); /*nstring-upcase*/
	local[0]= w;
BLK51881:
	ctx->vsp=local; return(local[0]);}

/*string-downcase*/
static pointer F51192string_downcase(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[17], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY51951;
	local[0] = makeint(0);
KEY51951:
	if (n & (1<<1)) goto KEY51956;
	local[1] = NIL;
KEY51956:
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)F51165true_string(ctx,1,local+2); /*true-string*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)COPYSEQ(ctx,1,local+2); /*copy-seq*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[15];
	local[5]= local[0];
	local[6]= fqv[16];
	if (local[1]==NIL) goto IF51987;
	local[7]= local[1];
	goto IF51988;
IF51987:
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
IF51988:
	ctx->vsp=local+8;
	w=(pointer)F51183nstring_downcase(ctx,5,local+3); /*nstring-downcase*/
	local[0]= w;
BLK51941:
	ctx->vsp=local; return(local[0]);}

/*string=*/
static pointer F51195string_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[18], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY52015;
	local[0] = makeint(0);
KEY52015:
	if (n & (1<<1)) goto KEY52020;
	local[1] = makeint(100000000);
KEY52020:
	if (n & (1<<2)) goto KEY52025;
	local[2] = makeint(0);
KEY52025:
	if (n & (1<<3)) goto KEY52030;
	local[3] = makeint(100000000);
KEY52030:
	local[4]= argv[0];
	local[5]= argv[1];
	local[6]= local[0];
	local[7]= local[1];
	local[8]= local[2];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(*ftab[3])(ctx,6,local+4,&ftab[3],fqv[19]); /*stringeq*/
	local[0]= w;
BLK52001:
	ctx->vsp=local; return(local[0]);}

/*string-equal*/
static pointer F51198string_equal(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[20], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY52064;
	local[0] = makeint(0);
KEY52064:
	if (n & (1<<1)) goto KEY52069;
	local[1] = makeint(100000000);
KEY52069:
	if (n & (1<<2)) goto KEY52074;
	local[2] = makeint(0);
KEY52074:
	if (n & (1<<3)) goto KEY52079;
	local[3] = makeint(100000000);
KEY52079:
	local[4]= argv[0];
	local[5]= argv[1];
	local[6]= local[0];
	local[7]= local[1];
	local[8]= local[2];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(*ftab[4])(ctx,6,local+4,&ftab[4],fqv[21]); /*stringequal*/
	local[0]= w;
BLK52050:
	ctx->vsp=local; return(local[0]);}

/*substringp*/
static pointer F51201substringp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[0]= (pointer)((eusinteger_t)local[0] - (eusinteger_t)w);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= makeint(0);
TAG52148:
	local[3]= local[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)GREATERP(ctx,2,local+3); /*>*/
	if (w==NIL) goto IF52153;
	w = NIL;
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK52113;
	goto IF52154;
IF52153:
	local[3]= NIL;
IF52154:
	local[3]= argv[0];
	local[4]= argv[1];
	local[5]= fqv[22];
	local[6]= local[2];
	local[7]= fqv[23];
	local[8]= local[2];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)F51198string_equal(ctx,6,local+3); /*string-equal*/
	if (w==NIL) goto IF52169;
	w = T;
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK52099;
	goto IF52170;
IF52169:
	local[3]= NIL;
IF52170:
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[3]= w;
	local[2] = local[3];
	w = NIL;
	ctx->vsp=local+3;
	goto TAG52148;
	w = NIL;
	local[0]= w;
BLK52113:
	w = local[0];
	local[0]= w;
BLK52099:
	ctx->vsp=local; return(local[0]);}

/*:get*/
static pointer M52233string_get(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK52234:
	ctx->vsp=local; return(local[0]);}

/*:set*/
static pointer M52256string_set(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	w = argv[2];
	if (!isnum(w)) goto IF52275;
	local[0]= argv[2];
	local[1]= argv[0];
	local[2]= argv[3];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
	goto IF52276;
IF52275:
	local[0]= argv[4];
	local[1]= fqv[24];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[4]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= NIL;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[5])(ctx,1,local+2,&ftab[5],fqv[25]); /*flatten*/
	local[2]= w;
WHL52326:
	if (local[2]==NIL) goto WHX52327;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	w = local[1];
	if (!isnum(w)) goto CON52377;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ROUND(ctx,1,local+3); /*round*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= argv[3];
	local[6]= argv[4];
	ctx->vsp=local+7;
	w=(pointer)POKE(ctx,4,local+3); /*system:poke*/
	local[3]= argv[3];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	argv[3] = w;
	local[3]= argv[3];
	goto CON52375;
CON52377:
	local[3]= makeint(0);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
WHL52432:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX52433;
	local[5]= local[1];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ROUND(ctx,1,local+5); /*round*/
	local[5]= w;
	local[6]= argv[0];
	local[7]= argv[3];
	local[8]= argv[4];
	ctx->vsp=local+9;
	w=(pointer)POKE(ctx,4,local+5); /*system:poke*/
	local[5]= argv[3];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	argv[3] = w;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL52432;
WHX52433:
	local[5]= NIL;
BLK52434:
	w = NIL;
	local[3]= w;
	goto CON52375;
CON52403:
	local[3]= NIL;
CON52375:
	goto WHL52326;
WHX52327:
	local[3]= NIL;
BLK52328:
	w = NIL;
	local[0]= w;
IF52276:
	w = local[0];
	local[0]= w;
BLK52257:
	ctx->vsp=local; return(local[0]);}

/*explode-directory-names*/
static pointer F51211explode_directory_names(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= makeint(0);
	local[3]= NIL;
WHL52521:
	local[4]= makeint(47);
	local[5]= argv[0];
	local[6]= fqv[15];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(*ftab[2])(ctx,4,local+4,&ftab[2],fqv[9]); /*position*/
	local[3] = w;
	if (local[3]==NIL) goto WHX52522;
	local[4]= argv[0];
	local[5]= local[2];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)SUBSEQ(ctx,3,local+4); /*subseq*/
	local[0] = w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
	w = makeint(0);
	if ((eusinteger_t)local[4] <= (eusinteger_t)w) goto IF52550;
	local[4]= local[0];
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[1];
	goto IF52551;
IF52550:
	local[4]= NIL;
IF52551:
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL52521;
WHX52522:
	local[4]= NIL;
BLK52523:
	local[4]= argv[0];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SUBSEQ(ctx,2,local+4); /*subseq*/
	local[0] = w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
	w = makeint(0);
	if ((eusinteger_t)local[4] <= (eusinteger_t)w) goto IF52589;
	local[4]= local[0];
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[1];
	goto IF52590;
IF52589:
	local[4]= NIL;
IF52590:
	w = local[1];
	local[0]= w;
BLK52493:
	ctx->vsp=local; return(local[0]);}

/*:parse-namestring*/
static pointer M52630pathname_parse_namestring(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeint(0);
	local[1]= makeint(0);
	local[2]= makeint(0);
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	argv[0]->c.obj.iv[2] = NIL;
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[6])(ctx,1,local+7,&ftab[6],fqv[26]); /*zerop*/
	if (w==NIL) goto IF52672;
	argv[0]->c.obj.iv[0] = fqv[27];
	argv[0]->c.obj.iv[1] = fqv[28];
	w = argv[0];
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK52631;
	goto IF52673;
IF52672:
	local[7]= NIL;
IF52673:
	local[7]= makeint(58);
	local[8]= argv[2];
	ctx->vsp=local+9;
	w=(*ftab[2])(ctx,2,local+7,&ftab[2],fqv[9]); /*position*/
	local[6] = w;
	if (local[6]==NIL) goto IF52700;
	local[0] = local[6];
	local[7]= argv[2];
	local[8]= makeint(0);
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)SUBSEQ(ctx,3,local+7); /*subseq*/
	argv[0]->c.obj.iv[0] = w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[0] = w;
	local[7]= local[0];
	goto IF52701;
IF52700:
	local[7]= NIL;
IF52701:
	local[1] = local[0];
	local[7]= argv[2];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	local[8]= makeint(47);
	ctx->vsp=local+9;
	w=(pointer)EQ(ctx,2,local+7); /*eql*/
	if (w==NIL) goto CON52743;
	local[7]= fqv[29];
	w = argv[0]->c.obj.iv[2];
	ctx->vsp=local+8;
	argv[0]->c.obj.iv[2] = cons(ctx,local[7],w);
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[1] = w;
	local[7]= local[1];
	goto CON52741;
CON52743:
	local[7]= argv[2];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	local[8]= makeint(126);
	ctx->vsp=local+9;
	w=(pointer)EQ(ctx,2,local+7); /*eql*/
	if (w==NIL) goto CON52775;
	local[7]= fqv[30];
	ctx->vsp=local+8;
	w=(pointer)GETENV(ctx,1,local+7); /*unix:getenv*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)F51211explode_directory_names(ctx,1,local+7); /*explode-directory-names*/
	argv[0]->c.obj.iv[2] = w;
	local[7]= argv[0]->c.obj.iv[2];
	local[8]= fqv[29];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)NCONC(ctx,2,local+7); /*nconc*/
	argv[0]->c.obj.iv[2] = w;
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[1] = w;
	local[7]= local[1];
	goto CON52741;
CON52775:
	local[7]= NIL;
CON52741:
WHL52819:
	local[7]= makeint(47);
	local[8]= argv[2];
	local[9]= fqv[15];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(*ftab[2])(ctx,4,local+7,&ftab[2],fqv[9]); /*position*/
	local[6] = w;
	if (local[6]==NIL) goto WHX52820;
	local[7]= argv[2];
	local[8]= local[1];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)SUBSEQ(ctx,3,local+7); /*subseq*/
	local[3] = w;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	w = makeint(0);
	if ((eusinteger_t)local[7] <= (eusinteger_t)w) goto IF52848;
	local[7]= local[3];
	w = argv[0]->c.obj.iv[2];
	ctx->vsp=local+8;
	argv[0]->c.obj.iv[2] = cons(ctx,local[7],w);
	local[7]= argv[0]->c.obj.iv[2];
	goto IF52849;
IF52848:
	local[7]= NIL;
IF52849:
	local[7]= local[6];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[1] = w;
	local[2] = local[1];
	goto WHL52819;
WHX52820:
	local[7]= NIL;
BLK52821:
	local[7]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+8;
	w=(pointer)NREVERSE(ctx,1,local+7); /*nreverse*/
	argv[0]->c.obj.iv[2] = w;
	local[7]= argv[2];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)SUBSEQ(ctx,2,local+7); /*subseq*/
	local[4] = w;
	local[7]= local[4];
	local[8]= fqv[31];
	ctx->vsp=local+9;
	w=(pointer)EQUAL(ctx,2,local+7); /*equal*/
	if (w==NIL) goto CON52901;
	argv[0]->c.obj.iv[3] = local[4];
	argv[0]->c.obj.iv[4] = NIL;
	local[7]= argv[0]->c.obj.iv[4];
	goto CON52899;
CON52901:
	local[7]= makeint(46);
	local[8]= argv[2];
	local[9]= fqv[15];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(*ftab[2])(ctx,4,local+7,&ftab[2],fqv[9]); /*position*/
	local[2] = w;
	if (local[2]!=NIL) goto CON52934;
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)GREATERP(ctx,2,local+7); /*>*/
	if (w==NIL) goto IF52940;
	local[7]= argv[2];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)SUBSEQ(ctx,2,local+7); /*subseq*/
	argv[0]->c.obj.iv[3] = w;
	local[7]= argv[0]->c.obj.iv[3];
	goto IF52941;
IF52940:
	local[7]= NIL;
IF52941:
	goto CON52932;
CON52934:
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[2] = w;
WHL52970:
	local[7]= makeint(46);
	local[8]= argv[2];
	local[9]= fqv[15];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(*ftab[2])(ctx,4,local+7,&ftab[2],fqv[9]); /*position*/
	local[6] = w;
	if (local[6]==NIL) goto WHX52971;
	local[7]= local[6];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[2] = w;
	goto WHL52970;
WHX52971:
	local[7]= NIL;
BLK52972:
	local[7]= argv[2];
	local[8]= local[1];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)SUB1(ctx,1,local+9); /*1-*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SUBSEQ(ctx,3,local+7); /*subseq*/
	argv[0]->c.obj.iv[3] = w;
	local[7]= argv[2];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)SUBSEQ(ctx,2,local+7); /*subseq*/
	argv[0]->c.obj.iv[4] = w;
	local[7]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+8;
	w=(pointer)F51243null_string_p(ctx,1,local+7); /*null-string-p*/
	if (w==NIL) goto IF53016;
	argv[0]->c.obj.iv[3] = NIL;
	local[7]= argv[0]->c.obj.iv[3];
	goto IF53017;
IF53016:
	local[7]= NIL;
IF53017:
	goto CON52932;
CON52957:
	local[7]= NIL;
CON52932:
	goto CON52899;
CON52916:
	local[7]= NIL;
CON52899:
	w = argv[0];
	local[0]= w;
BLK52631:
	ctx->vsp=local; return(local[0]);}

/*:directory-string*/
static pointer M53034pathname_directory_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[2];
	w=argv[0]->c.obj.iv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[29];
	ctx->vsp=local+4;
	w=(pointer)EQ(ctx,2,local+2); /*eql*/
	if (w==NIL) goto IF53061;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[2]= fqv[32];
	w = local[0];
	ctx->vsp=local+3;
	local[0] = cons(ctx,local[2],w);
	local[2]= local[0];
	goto IF53062;
IF53061:
	local[2]= NIL;
IF53062:
	local[2]= NIL;
	local[3]= local[1];
WHL53142:
	if (local[3]==NIL) goto WHX53143;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	w = local[0];
	ctx->vsp=local+5;
	local[0] = cons(ctx,local[4],w);
	local[4]= fqv[33];
	w = local[0];
	ctx->vsp=local+5;
	local[0] = cons(ctx,local[4],w);
	goto WHL53142;
WHX53143:
	local[4]= NIL;
BLK53144:
	w = NIL;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)NREVERSE(ctx,1,local+2); /*nreverse*/
	local[0] = w;
	local[2]= (pointer)get_sym_func(fqv[34]);
	local[3]= loadglobal(fqv[8]);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,3,local+2); /*apply*/
	local[0]= w;
BLK53035:
	ctx->vsp=local; return(local[0]);}

/*:namestring*/
static pointer M53234pathname_namestring(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[35];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	if (argv[0]->c.obj.iv[4]==NIL) goto IF53262;
	local[1]= loadglobal(fqv[8]);
	local[2]= fqv[36];
	local[3]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+4;
	w=(pointer)CONCATENATE(ctx,3,local+1); /*concatenate*/
	local[1]= w;
	goto IF53263;
IF53262:
	local[1]= NIL;
IF53263:
	if (argv[0]->c.obj.iv[3]==NIL) goto IF53275;
	local[2]= loadglobal(fqv[8]);
	local[3]= argv[0]->c.obj.iv[0];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= local[0];
	local[6]= argv[0]->c.obj.iv[3];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)CONCATENATE(ctx,6,local+2); /*concatenate*/
	local[2]= w;
	goto IF53276;
IF53275:
	local[2]= loadglobal(fqv[8]);
	local[3]= argv[0]->c.obj.iv[0];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= local[0];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)CONCATENATE(ctx,5,local+2); /*concatenate*/
	local[2]= w;
IF53276:
	w = local[2];
	local[0]= w;
BLK53235:
	ctx->vsp=local; return(local[0]);}

/*:host*/
static pointer M53298pathname_host(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT53302;}
	local[0]= NIL;
ENT53302:
ENT53301:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF53318;
	argv[0]->c.obj.iv[0] = local[0];
	local[1]= argv[0]->c.obj.iv[0];
	goto IF53319;
IF53318:
	local[1]= argv[0]->c.obj.iv[0];
IF53319:
	w = local[1];
	local[0]= w;
BLK53299:
	ctx->vsp=local; return(local[0]);}

/*:device*/
static pointer M53332pathname_device(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT53336;}
	local[0]= NIL;
ENT53336:
ENT53335:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF53352;
	argv[0]->c.obj.iv[1] = local[0];
	local[1]= argv[0]->c.obj.iv[1];
	goto IF53353;
IF53352:
	local[1]= argv[0]->c.obj.iv[1];
IF53353:
	w = local[1];
	local[0]= w;
BLK53333:
	ctx->vsp=local; return(local[0]);}

/*:directory*/
static pointer M53366pathname_directory(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT53370;}
	local[0]= NIL;
ENT53370:
ENT53369:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF53386;
	argv[0]->c.obj.iv[2] = local[0];
	local[1]= argv[0]->c.obj.iv[2];
	goto IF53387;
IF53386:
	local[1]= argv[0]->c.obj.iv[2];
IF53387:
	w = local[1];
	local[0]= w;
BLK53367:
	ctx->vsp=local; return(local[0]);}

/*:name*/
static pointer M53400pathname_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT53404;}
	local[0]= NIL;
ENT53404:
ENT53403:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF53420;
	argv[0]->c.obj.iv[3] = local[0];
	local[1]= argv[0]->c.obj.iv[3];
	goto IF53421;
IF53420:
	local[1]= argv[0]->c.obj.iv[3];
IF53421:
	w = local[1];
	local[0]= w;
BLK53401:
	ctx->vsp=local; return(local[0]);}

/*:type*/
static pointer M53434pathname_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT53438;}
	local[0]= NIL;
ENT53438:
ENT53437:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF53454;
	argv[0]->c.obj.iv[4] = local[0];
	local[1]= argv[0]->c.obj.iv[4];
	goto IF53455;
IF53454:
	local[1]= argv[0]->c.obj.iv[4];
IF53455:
	w = local[1];
	local[0]= w;
BLK53435:
	ctx->vsp=local; return(local[0]);}

/*:set-type*/
static pointer M53468pathname_set_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[4] = argv[2];
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK53469:
	ctx->vsp=local; return(local[0]);}

/*:version*/
static pointer M53491pathname_version(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT53495;}
	local[0]= NIL;
ENT53495:
ENT53494:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF53511;
	argv[0]->c.obj.iv[5] = local[0];
	local[1]= argv[0]->c.obj.iv[5];
	goto IF53512;
IF53511:
	local[1]= argv[0]->c.obj.iv[5];
IF53512:
	w = local[1];
	local[0]= w;
BLK53492:
	ctx->vsp=local; return(local[0]);}

/*:merge*/
static pointer M53525pathname_merge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[0]->c.obj.iv[0]!=NIL) goto IF53540;
	argv[0]->c.obj.iv[0] = *(ovafptr(argv[2],fqv[37]));
	local[0]= argv[0]->c.obj.iv[0];
	goto IF53541;
IF53540:
	local[0]= NIL;
IF53541:
	if (argv[0]->c.obj.iv[1]!=NIL) goto IF53554;
	argv[0]->c.obj.iv[1] = *(ovafptr(argv[2],fqv[38]));
	local[0]= argv[0]->c.obj.iv[1];
	goto IF53555;
IF53554:
	local[0]= NIL;
IF53555:
	if (argv[0]->c.obj.iv[2]!=NIL) goto IF53568;
	argv[0]->c.obj.iv[2] = *(ovafptr(argv[2],fqv[39]));
	local[0]= argv[0]->c.obj.iv[2];
	goto IF53569;
IF53568:
	local[0]= NIL;
IF53569:
	if (argv[0]->c.obj.iv[3]!=NIL) goto IF53582;
	argv[0]->c.obj.iv[3] = *(ovafptr(argv[2],fqv[40]));
	local[0]= argv[0]->c.obj.iv[3];
	goto IF53583;
IF53582:
	local[0]= NIL;
IF53583:
	if (argv[0]->c.obj.iv[4]!=NIL) goto IF53596;
	argv[0]->c.obj.iv[4] = *(ovafptr(argv[2],fqv[41]));
	local[0]= argv[0]->c.obj.iv[4];
	goto IF53597;
IF53596:
	local[0]= NIL;
IF53597:
	if (argv[0]->c.obj.iv[5]!=NIL) goto IF53610;
	argv[0]->c.obj.iv[5] = *(ovafptr(argv[2],fqv[42]));
	local[0]= argv[0]->c.obj.iv[5];
	goto IF53611;
IF53610:
	local[0]= NIL;
IF53611:
	w = argv[0];
	local[0]= w;
BLK53526:
	ctx->vsp=local; return(local[0]);}

/*:add-directory*/
static pointer M53627pathname_add_directory(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= (pointer)get_sym_func(fqv[8]);
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	argv[0]->c.obj.iv[2] = w;
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK53628:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M53657pathname_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT53661;}
	local[0]= T;
ENT53661:
ENT53660:
	if (n>3) maerror();
	local[1]= local[0];
	local[2]= fqv[43];
	local[3]= argv[0];
	local[4]= fqv[44];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[0]= w;
BLK53658:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M53686pathname_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[45], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY53703;
	local[0] = NIL;
KEY53703:
	if (n & (1<<1)) goto KEY53708;
	local[1] = NIL;
KEY53708:
	if (n & (1<<2)) goto KEY53713;
	local[2] = NIL;
KEY53713:
	if (n & (1<<3)) goto KEY53718;
	local[3] = NIL;
KEY53718:
	if (n & (1<<4)) goto KEY53723;
	local[4] = NIL;
KEY53723:
	if (n & (1<<5)) goto KEY53728;
	local[5] = NIL;
KEY53728:
	if (local[0]==NIL) goto IF53737;
	argv[0]->c.obj.iv[0] = local[0];
	local[6]= argv[0]->c.obj.iv[0];
	goto IF53738;
IF53737:
	local[6]= NIL;
IF53738:
	if (local[1]==NIL) goto IF53750;
	argv[0]->c.obj.iv[1] = local[1];
	local[6]= argv[0]->c.obj.iv[1];
	goto IF53751;
IF53750:
	local[6]= NIL;
IF53751:
	if (local[2]==NIL) goto IF53763;
	argv[0]->c.obj.iv[2] = local[2];
	local[6]= argv[0]->c.obj.iv[2];
	goto IF53764;
IF53763:
	local[6]= NIL;
IF53764:
	if (local[3]==NIL) goto IF53776;
	argv[0]->c.obj.iv[3] = local[3];
	local[6]= argv[0]->c.obj.iv[3];
	goto IF53777;
IF53776:
	local[6]= NIL;
IF53777:
	if (local[4]==NIL) goto IF53789;
	argv[0]->c.obj.iv[4] = local[4];
	local[6]= argv[0]->c.obj.iv[4];
	goto IF53790;
IF53789:
	local[6]= NIL;
IF53790:
	if (local[5]==NIL) goto IF53802;
	argv[0]->c.obj.iv[5] = local[5];
	local[6]= argv[0]->c.obj.iv[5];
	goto IF53803;
IF53802:
	local[6]= NIL;
IF53803:
	w = argv[0];
	local[0]= w;
BLK53687:
	ctx->vsp=local; return(local[0]);}

/*pathnamep*/
static pointer F51215pathnamep(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[46]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK53820:
	ctx->vsp=local; return(local[0]);}

/*pathname*/
static pointer F51218pathname(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[46]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto IF53847;
	local[0]= argv[0];
	goto IF53848;
IF53847:
	if (argv[0]==NIL) goto IF53857;
	local[0]= loadglobal(fqv[46]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[47];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F51168string(ctx,1,local+3); /*string*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = local[0];
	local[0]= w;
	goto IF53858;
IF53857:
	local[0]= loadglobal(fqv[46]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
IF53858:
IF53848:
	w = local[0];
	local[0]= w;
BLK53837:
	ctx->vsp=local; return(local[0]);}

/*namestring*/
static pointer F51221namestring(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!issymbol(w)) goto CON53907;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F51168string(ctx,1,local+0); /*string*/
	local[0]= w;
	goto CON53905;
CON53907:
	w = argv[0];
	if (!isstring(w)) goto CON53915;
	local[0]= argv[0];
	goto CON53905;
CON53915:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F51215pathnamep(ctx,1,local+0); /*pathnamep*/
	if (w==NIL) goto CON53921;
	local[0]= argv[0];
	local[1]= fqv[44];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto CON53905;
CON53921:
	local[0]= fqv[48];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,2,local+0); /*error*/
	local[0]= w;
	goto CON53905;
CON53933:
	local[0]= NIL;
CON53905:
	w = local[0];
	local[0]= w;
BLK53895:
	ctx->vsp=local; return(local[0]);}

/*pathname-directory*/
static pointer F51224pathname_directory(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F51218pathname(ctx,1,local+0); /*pathname*/
	w = *(ovafptr(w,fqv[39]));
	local[0]= w;
BLK53942:
	ctx->vsp=local; return(local[0]);}

/*pathname-name*/
static pointer F51227pathname_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F51218pathname(ctx,1,local+0); /*pathname*/
	w = *(ovafptr(w,fqv[40]));
	local[0]= w;
BLK53959:
	ctx->vsp=local; return(local[0]);}

/*pathname-type*/
static pointer F51230pathname_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F51218pathname(ctx,1,local+0); /*pathname*/
	w = *(ovafptr(w,fqv[41]));
	local[0]= w;
BLK53976:
	ctx->vsp=local; return(local[0]);}

/*directory-namestring*/
static pointer F51233directory_namestring(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F51218pathname(ctx,1,local+0); /*pathname*/
	local[0]= w;
	local[1]= fqv[35];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK53993:
	ctx->vsp=local; return(local[0]);}

/*make-pathname*/
static pointer F51236make_pathname(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[49], &argv[0], n-0, local+0, 0);
	if (n & (1<<0)) goto KEY54025;
	local[0] = NIL;
KEY54025:
	if (n & (1<<1)) goto KEY54030;
	local[1] = NIL;
KEY54030:
	if (n & (1<<2)) goto KEY54035;
	local[2] = NIL;
KEY54035:
	if (n & (1<<3)) goto KEY54040;
	local[3] = NIL;
KEY54040:
	if (n & (1<<4)) goto KEY54045;
	local[4] = NIL;
KEY54045:
	if (n & (1<<5)) goto KEY54050;
	local[5] = NIL;
KEY54050:
	if (n & (1<<6)) goto KEY54055;
	local[6] = NIL;
KEY54055:
	local[7]= loadglobal(fqv[46]);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,1,local+7); /*instantiate*/
	local[7]= w;
	local[8]= local[7];
	local[9]= fqv[50];
	local[10]= fqv[51];
	local[11]= local[0];
	local[12]= fqv[52];
	local[13]= local[1];
	local[14]= fqv[53];
	local[15]= local[2];
	local[16]= fqv[54];
	local[17]= local[3];
	local[18]= fqv[55];
	local[19]= local[4];
	local[20]= fqv[56];
	local[21]= local[5];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,14,local+8); /*send*/
	w = local[7];
	local[7]= w;
	local[8]= fqv[57];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)F51218pathname(ctx,1,local+9); /*pathname*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[0]= w;
BLK54012:
	ctx->vsp=local; return(local[0]);}

/*parse-namestring*/
static pointer F51239parse_namestring(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F51218pathname(ctx,1,local+0); /*pathname*/
	local[0]= w;
BLK54115:
	ctx->vsp=local; return(local[0]);}

/*null-string-p*/
static pointer F51243null_string_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[58];
	ctx->vsp=local+2;
	w=(pointer)EQUAL(ctx,2,local+0); /*equal*/
	local[0]= w;
BLK54132:
	ctx->vsp=local; return(local[0]);}

/*merge-pathnames*/
static pointer F51246merge_pathnames(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT54150;}
	local[0]= loadglobal(fqv[59]);
ENT54150:
ENT54149:
	if (n>2) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F51215pathnamep(ctx,1,local+1); /*pathnamep*/
	if (w==NIL) goto IF54168;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)COPYOBJ(ctx,1,local+1); /*copy-object*/
	local[1]= w;
	goto IF54169;
IF54168:
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F51218pathname(ctx,1,local+1); /*pathname*/
	local[1]= w;
IF54169:
	argv[0] = local[1];
	local[1]= argv[0];
	local[2]= fqv[57];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F51218pathname(ctx,1,local+3); /*pathname*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK54147:
	ctx->vsp=local; return(local[0]);}

/*concatenate-pathnames*/
static pointer F51249concatenate_pathnames(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST54197:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= (pointer)get_sym_func(fqv[34]);
	local[2]= loadglobal(fqv[8]);
	local[3]= (pointer)get_sym_func(fqv[60]);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F51218pathname(ctx,1,local+1); /*pathname*/
	local[0]= w;
BLK54195:
	ctx->vsp=local; return(local[0]);}

/*truename*/
static pointer F51252truename(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F51218pathname(ctx,1,local+0); /*pathname*/
	argv[0] = w;
	ctx->vsp=local+0;
	w=(pointer)GETWD(ctx,0,local+0); /*unix:getwd*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[35];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= T;
	if (local[1]==NIL) goto IF54259;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)CHDIR(ctx,1,local+3); /*unix:chdir*/
	local[2] = w;
	local[3]= local[2];
	goto IF54260;
IF54259:
	local[3]= NIL;
IF54260:
	local[3]= local[2];
	if (T!=local[3]) goto CON54276;
	ctx->vsp=local+3;
	w=(pointer)GETWD(ctx,0,local+3); /*unix:getwd*/
	local[2] = w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	w = makeint(1);
	if ((eusinteger_t)local[3] <= (eusinteger_t)w) goto IF54290;
	local[3]= loadglobal(fqv[8]);
	local[4]= local[2];
	local[5]= fqv[61];
	ctx->vsp=local+6;
	w=(pointer)CONCATENATE(ctx,3,local+3); /*concatenate*/
	local[2] = w;
	local[3]= local[2];
	goto IF54291;
IF54290:
	local[3]= NIL;
IF54291:
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)CHDIR(ctx,1,local+3); /*unix:chdir*/
	local[3]= fqv[54];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F51227pathname_name(ctx,1,local+4); /*pathname-name*/
	local[4]= w;
	local[5]= fqv[55];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)F51230pathname_type(ctx,1,local+6); /*pathname-type*/
	local[6]= w;
	local[7]= fqv[53];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)F51224pathname_directory(ctx,1,local+8); /*pathname-directory*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)F51236make_pathname(ctx,6,local+3); /*make-pathname*/
	local[3]= w;
	goto CON54274;
CON54276:
	local[3]= fqv[62];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
	goto CON54274;
CON54328:
	local[3]= NIL;
CON54274:
	w = local[3];
	local[0]= w;
BLK54221:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M54377url_pathname_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[63];
	local[2]= argv[1];
	local[3]= fqv[54];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)ADDRESS(ctx,1,local+3); /*system:address*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[64];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= w;
BLK54378:
	ctx->vsp=local; return(local[0]);}

/*:string*/
static pointer M54409url_pathname_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= fqv[65];
	local[2]= argv[0]->c.obj.iv[6];
	local[3]= argv[0]->c.obj.iv[7];
	local[4]= argv[0]->c.obj.iv[8];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)F51221namestring(ctx,1,local+5); /*namestring*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,6,local+0); /*format*/
	local[0]= w;
BLK54410:
	ctx->vsp=local; return(local[0]);}

/*:string2*/
static pointer M54431url_pathname_string2(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= fqv[66];
	local[2]= argv[0]->c.obj.iv[6];
	local[3]= argv[0]->c.obj.iv[7];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F51221namestring(ctx,1,local+4); /*namestring*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= w;
BLK54432:
	ctx->vsp=local; return(local[0]);}

/*:port*/
static pointer M54452url_pathname_port(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT54456;}
	local[0]= NIL;
ENT54456:
ENT54455:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF54472;
	argv[0]->c.obj.iv[8] = local[0];
	local[1]= argv[0]->c.obj.iv[8];
	goto IF54473;
IF54472:
	local[1]= NIL;
IF54473:
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK54453:
	ctx->vsp=local; return(local[0]);}

/*:server*/
static pointer M54488url_pathname_server(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT54492;}
	local[0]= NIL;
ENT54492:
ENT54491:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF54508;
	argv[0]->c.obj.iv[7] = local[0];
	local[1]= argv[0]->c.obj.iv[7];
	goto IF54509;
IF54508:
	local[1]= NIL;
IF54509:
	w = argv[0]->c.obj.iv[7];
	local[0]= w;
BLK54489:
	ctx->vsp=local; return(local[0]);}

/*:connect*/
static pointer M54524url_pathname_connect(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT54528;}
	local[0]= makeint(5);
ENT54528:
ENT54527:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[7];
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[7])(ctx,3,local+1,&ftab[7],fqv[67]); /*connect-server*/
	local[0]= w;
BLK54525:
	ctx->vsp=local; return(local[0]);}

/*:host*/
static pointer M54551url_pathname_host(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT54555;}
	local[0]= NIL;
ENT54555:
ENT54554:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF54571;
	argv[0]->c.obj.iv[7] = local[0];
	local[1]= argv[0]->c.obj.iv[7];
	goto IF54572;
IF54571:
	local[1]= NIL;
IF54572:
	w = argv[0]->c.obj.iv[7];
	local[0]= w;
BLK54552:
	ctx->vsp=local; return(local[0]);}

/*:protocol*/
static pointer M54587url_pathname_protocol(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT54591;}
	local[0]= NIL;
ENT54591:
ENT54590:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF54607;
	argv[0]->c.obj.iv[6] = local[0];
	local[1]= argv[0]->c.obj.iv[6];
	goto IF54608;
IF54607:
	local[1]= NIL;
IF54608:
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK54588:
	ctx->vsp=local; return(local[0]);}

/*:parse-namestring*/
static pointer M54623url_pathname_parse_namestring(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeint(0);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= makeint(58);
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,2,local+3,&ftab[2],fqv[9]); /*position*/
	local[0] = w;
	if (local[0]==NIL) goto IF54654;
	local[3]= argv[2];
	local[4]= makeint(0);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SUBSEQ(ctx,3,local+3); /*subseq*/
	argv[0]->c.obj.iv[6] = w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[0] = w;
	local[3]= local[0];
	goto IF54655;
IF54654:
	argv[0]->c.obj.iv[6] = fqv[68];
	local[0] = makeint(0);
	local[3]= local[0];
IF54655:
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	local[4]= makeint(47);
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w==NIL) goto CON54691;
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	local[4]= makeint(47);
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w==NIL) goto CON54691;
	local[3]= makeint(47);
	local[4]= argv[2];
	local[5]= fqv[15];
	local[6]= makeint(3);
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[2])(ctx,4,local+3,&ftab[2],fqv[9]); /*position*/
	local[2] = w;
	if (local[2]!=NIL) goto IF54731;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[2] = w;
	local[3]= local[2];
	goto IF54732;
IF54731:
	local[3]= NIL;
IF54732:
	local[3]= argv[2];
	local[4]= makeint(2);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SUBSEQ(ctx,3,local+3); /*subseq*/
	argv[0]->c.obj.iv[7] = w;
	local[3]= makeint(58);
	local[4]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,2,local+3,&ftab[2],fqv[9]); /*position*/
	local[1] = w;
	if (local[1]==NIL) goto IF54765;
	local[3]= argv[0]->c.obj.iv[7];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SUBSEQ(ctx,2,local+3); /*subseq*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[8])(ctx,1,local+3,&ftab[8],fqv[69]); /*read-from-string*/
	argv[0]->c.obj.iv[8] = w;
	local[3]= argv[0]->c.obj.iv[7];
	local[4]= makeint(0);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SUBSEQ(ctx,3,local+3); /*subseq*/
	argv[0]->c.obj.iv[7] = w;
	local[3]= argv[0]->c.obj.iv[7];
	goto IF54766;
IF54765:
	argv[0]->c.obj.iv[8] = makeint(80);
	local[3]= argv[0]->c.obj.iv[8];
IF54766:
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[70]));
	local[5]= fqv[47];
	local[6]= argv[2];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SUBSEQ(ctx,2,local+6); /*subseq*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,4,local+3); /*send-message*/
	local[3]= fqv[71];
	w=argv[0]->c.obj.iv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)APPEND(ctx,2,local+3); /*append*/
	argv[0]->c.obj.iv[2] = w;
	local[3]= argv[0];
	goto CON54689;
CON54691:
	local[3]= fqv[72];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,2,local+3); /*error*/
	local[3]= w;
	goto CON54689;
CON54832:
	local[3]= NIL;
CON54689:
	w = local[3];
	local[0]= w;
BLK54624:
	ctx->vsp=local; return(local[0]);}

/*:percent-escape*/
static pointer M54841url_pathname_percent_escape(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[73], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY54854;
	local[0] = T;
KEY54854:
	if (n & (1<<1)) goto KEY54859;
	local[1] = NIL;
KEY54859:
	local[2]= argv[0];
	local[3]= fqv[47];
	if (local[1]==NIL) goto IF54872;
	local[4]= argv[0];
	local[5]= fqv[64];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)F51281unescaped_url_string_from_namestring(ctx,2,local+4); /*unescaped-url-string-from-namestring*/
	local[4]= w;
	goto IF54873;
IF54872:
	local[4]= argv[0];
	local[5]= fqv[64];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)F51277escaped_url_string_from_namestring(ctx,2,local+4); /*escaped-url-string-from-namestring*/
	local[4]= w;
IF54873:
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0]= w;
BLK54842:
	ctx->vsp=local; return(local[0]);}

/*url-pathname*/
static pointer F51271url_pathname(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[74]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto IF54907;
	local[0]= argv[0];
	goto IF54908;
IF54907:
	if (argv[0]==NIL) goto IF54918;
	local[0]= loadglobal(fqv[74]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[47];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F51168string(ctx,1,local+3); /*string*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = local[0];
	local[0]= w;
	goto IF54919;
IF54918:
	local[0]= loadglobal(fqv[74]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
IF54919:
IF54908:
	w = local[0];
	local[0]= w;
BLK54897:
	ctx->vsp=local; return(local[0]);}

/*parse-url*/
static pointer F51273parse_url(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[75];
	local[1]= NIL;
	local[2]= NIL;
	local[3]= makeint(80);
	local[4]= makeint(0);
	local[5]= NIL;
	local[6]= makeint(58);
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(*ftab[2])(ctx,2,local+6,&ftab[2],fqv[9]); /*position*/
	local[4] = w;
	if (local[4]==NIL) goto IF54990;
	local[6]= argv[0];
	local[7]= makeint(0);
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SUBSEQ(ctx,3,local+6); /*subseq*/
	local[0] = w;
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[4] = w;
	local[6]= local[4];
	goto IF54991;
IF54990:
	local[4] = makeint(0);
	local[6]= local[4];
IF54991:
	local[6]= argv[0];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= makeint(47);
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w==NIL) goto CON55025;
	local[6]= argv[0];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= makeint(47);
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w==NIL) goto CON55025;
	local[6]= argv[0];
	local[7]= makeint(2);
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	local[8]= makeint(47);
	local[9]= argv[0];
	local[10]= fqv[15];
	local[11]= makeint(3);
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[2])(ctx,4,local+8,&ftab[2],fqv[9]); /*position*/
	local[4] = w;
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SUBSEQ(ctx,3,local+6); /*subseq*/
	local[1] = w;
	local[6]= makeint(58);
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[2])(ctx,2,local+6,&ftab[2],fqv[9]); /*position*/
	local[5] = w;
	if (local[5]==NIL) goto IF55078;
	local[6]= local[1];
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SUBSEQ(ctx,2,local+6); /*subseq*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[8])(ctx,1,local+6,&ftab[8],fqv[69]); /*read-from-string*/
	local[3] = w;
	local[6]= local[1];
	local[7]= makeint(0);
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)SUBSEQ(ctx,3,local+6); /*subseq*/
	local[1] = w;
	local[6]= local[1];
	goto IF55079;
IF55078:
	local[3] = makeint(80);
	local[6]= local[3];
IF55079:
	local[6]= argv[0];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SUBSEQ(ctx,2,local+6); /*subseq*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)F51218pathname(ctx,1,local+6); /*pathname*/
	local[2] = w;
	local[6]= local[2];
	local[7]= fqv[53];
	local[8]= fqv[76];
	local[9]= local[2];
	local[10]= fqv[53];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
	ctx->vsp=local+10;
	w=(pointer)APPEND(ctx,2,local+8); /*append*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= local[0];
	local[7]= local[1];
	local[8]= local[3];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,4,local+6); /*list*/
	local[6]= w;
	goto CON55023;
CON55025:
	local[6]= fqv[77];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)SIGERROR(ctx,2,local+6); /*error*/
	local[6]= w;
	goto CON55023;
CON55152:
	local[6]= NIL;
CON55023:
	w = local[6];
	local[0]= w;
BLK54955:
	ctx->vsp=local; return(local[0]);}

/*escape-url*/
static pointer F51275escape_url(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT55167;}
	local[0]= loadglobal(fqv[78]);
ENT55167:
	if (n>=3) { local[1]=(argv[2]); goto ENT55166;}
	local[1]= T;
ENT55166:
ENT55165:
	if (n>3) maerror();
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,FLET55189,env,argv,local);
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,FLET55191,env,argv,local);
	local[4]= NIL;
	local[5]= argv[0];
	local[6]= loadglobal(fqv[79]);
	ctx->vsp=local+7;
	w=(pointer)COERCE(ctx,2,local+5); /*coerce*/
	local[5]= w;
WHL55216:
	if (local[5]==NIL) goto WHX55217;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[4];
	w = local[2];
	ctx->vsp=local+7;
	w=FLET55189(ctx,1,local+6,w);
	if (w==NIL) goto CON55267;
	local[6]= local[4];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)WRTBYTE(ctx,2,local+6); /*write-byte*/
	local[6]= w;
	goto CON55265;
CON55267:
	local[6]= local[4];
	local[7]= makeint(13);
	ctx->vsp=local+8;
	w=(*ftab[9])(ctx,2,local+6,&ftab[9],fqv[80]); /*char=*/
	if (w==NIL) goto CON55280;
	local[6]= makeint(10);
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)WRTBYTE(ctx,2,local+6); /*write-byte*/
	local[6]= w;
	goto CON55265;
CON55280:
	if (local[1]==NIL) goto CON55291;
	local[6]= local[4];
	local[7]= makeint(32);
	ctx->vsp=local+8;
	w=(*ftab[9])(ctx,2,local+6,&ftab[9],fqv[80]); /*char=*/
	if (w==NIL) goto CON55291;
	local[6]= makeint(43);
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)WRTBYTE(ctx,2,local+6); /*write-byte*/
	local[6]= w;
	goto CON55265;
CON55291:
	local[6]= local[0];
	local[7]= fqv[81];
	local[8]= NIL;
	local[9]= fqv[82];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,3,local+8); /*format*/
	local[8]= w;
	local[9]= makeint(2);
	w = local[3];
	ctx->vsp=local+10;
	w=FLET55191(ctx,2,local+8,w);
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	goto CON55265;
CON55305:
	local[6]= NIL;
CON55265:
	goto WHL55216;
WHX55217:
	local[6]= NIL;
BLK55218:
	w = NIL;
	local[0]= w;
BLK55163:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET55189(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint(65);
	local[1]= argv[0];
	local[2]= makeint(90);
	ctx->vsp=local+3;
	w=(pointer)LSEQP(ctx,3,local+0); /*<=*/
	local[0]= w;
	if (w!=NIL) goto OR55333;
	local[0]= makeint(97);
	local[1]= argv[0];
	local[2]= makeint(122);
	ctx->vsp=local+3;
	w=(pointer)LSEQP(ctx,3,local+0); /*<=*/
	local[0]= w;
	if (w!=NIL) goto OR55333;
	local[0]= makeint(48);
	local[1]= argv[0];
	local[2]= makeint(57);
	ctx->vsp=local+3;
	w=(pointer)LSEQP(ctx,3,local+0); /*<=*/
	local[0]= w;
	if (w!=NIL) goto OR55333;
	local[0]= argv[0];
	local[1]= loadglobal(fqv[83]);
	local[2]= fqv[2];
	local[3]= (pointer)get_sym_func(fqv[80]);
	ctx->vsp=local+4;
	w=(*ftab[10])(ctx,4,local+0,&ftab[10],fqv[84]); /*find*/
	local[0]= w;
OR55333:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET55191(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	w=(*ftab[11])(ctx,0,local+0,&ftab[11],fqv[85]); /*make-string-output-stream*/
	local[0]= w;
	local[1]= makeint(0);
	local[2]= argv[1];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
WHL55417:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX55418;
	local[3]= makeint(48);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)WRTBYTE(ctx,2,local+3); /*write-byte*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL55417;
WHX55418:
	local[3]= NIL;
BLK55419:
	w = NIL;
	local[1]= local[0];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,2,local+1); /*format*/
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[12])(ctx,1,local+1,&ftab[12],fqv[86]); /*get-output-stream-string*/
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[12])(ctx,1,local+1,&ftab[12],fqv[86]); /*get-output-stream-string*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*escaped-url-string-from-namestring*/
static pointer F51277escaped_url_string_from_namestring(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT55460;}
	local[0]= T;
ENT55460:
ENT55459:
	if (n>2) maerror();
	ctx->vsp=local+1;
	w=(*ftab[11])(ctx,0,local+1,&ftab[11],fqv[85]); /*make-string-output-stream*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)F51275escape_url(ctx,3,local+2); /*escape-url*/
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[12])(ctx,1,local+2,&ftab[12],fqv[86]); /*get-output-stream-string*/
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[12])(ctx,1,local+2,&ftab[12],fqv[86]); /*get-output-stream-string*/
	local[0]= w;
BLK55457:
	ctx->vsp=local; return(local[0]);}

/*unescape-url*/
static pointer F51279unescape_url(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT55506;}
	local[0]= loadglobal(fqv[78]);
ENT55506:
	if (n>=3) { local[1]=(argv[2]); goto ENT55505;}
	local[1]= T;
ENT55505:
ENT55504:
	if (n>3) maerror();
	local[2]= argv[0];
	local[3]= fqv[15];
	local[4]= fqv[87];
	ctx->vsp=local+5;
	w=(*ftab[13])(ctx,2,local+3,&ftab[13],fqv[88]); /*member*/
	if (w==NIL) goto IF55535;
	local[3]= fqv[15];
	local[4]= fqv[89];
	ctx->vsp=local+5;
	w=(*ftab[13])(ctx,2,local+3,&ftab[13],fqv[88]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	goto IF55536;
IF55535:
	local[3]= NIL;
IF55536:
	local[4]= fqv[16];
	local[5]= fqv[90];
	ctx->vsp=local+6;
	w=(*ftab[13])(ctx,2,local+4,&ftab[13],fqv[88]); /*member*/
	if (w==NIL) goto IF55559;
	local[4]= fqv[16];
	local[5]= fqv[91];
	ctx->vsp=local+6;
	w=(*ftab[13])(ctx,2,local+4,&ftab[13],fqv[88]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	goto IF55560;
IF55559:
	local[4]= NIL;
IF55560:
	ctx->vsp=local+5;
	w=(*ftab[14])(ctx,3,local+2,&ftab[14],fqv[92]); /*make-string-input-stream*/
	local[2]= w;
WHL55587:
	local[3]= local[2];
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)PEEKCH(ctx,2,local+3); /*peek-char*/
	if (w==NIL) goto WHX55588;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)PEEKCH(ctx,1,local+3); /*peek-char*/
	local[3]= w;
	local[4]= local[3];
	if (fqv[93]!=local[4]) goto IF55612;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)READCH(ctx,1,local+4); /*read-char*/
	local[4]= makeint(35);
	local[5]= makeint(120);
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)READCH(ctx,1,local+6); /*read-char*/
	local[6]= w;
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)READCH(ctx,1,local+7); /*read-char*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,4,local+4); /*list*/
	local[4]= w;
	local[5]= loadglobal(fqv[8]);
	ctx->vsp=local+6;
	w=(pointer)COERCE(ctx,2,local+4); /*coerce*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[8])(ctx,1,local+4,&ftab[8],fqv[69]); /*read-from-string*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)WRTBYTE(ctx,2,local+4); /*write-byte*/
	local[4]= w;
	goto IF55613;
IF55612:
	local[4]= local[3];
	if (fqv[94]!=local[4]) goto IF55643;
	if (local[1]==NIL) goto IF55651;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)READCH(ctx,1,local+4); /*read-char*/
	local[4]= makeint(32);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)WRTBYTE(ctx,2,local+4); /*write-byte*/
	local[4]= w;
	goto IF55652;
IF55651:
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)READCH(ctx,1,local+4); /*read-char*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)WRTBYTE(ctx,2,local+4); /*write-byte*/
	local[4]= w;
IF55652:
	goto IF55644;
IF55643:
	if (T==NIL) goto IF55673;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)READCH(ctx,1,local+4); /*read-char*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)WRTBYTE(ctx,2,local+4); /*write-byte*/
	local[4]= w;
	goto IF55674;
IF55673:
	local[4]= NIL;
IF55674:
IF55644:
IF55613:
	w = local[4];
	goto WHL55587;
WHX55588:
	local[3]= NIL;
BLK55589:
	w = local[3];
	local[0]= w;
BLK55502:
	ctx->vsp=local; return(local[0]);}

/*unescaped-url-string-from-namestring*/
static pointer F51281unescaped_url_string_from_namestring(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT55690;}
	local[0]= T;
ENT55690:
ENT55689:
	if (n>2) maerror();
	ctx->vsp=local+1;
	w=(*ftab[11])(ctx,0,local+1,&ftab[11],fqv[85]); /*make-string-output-stream*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)F51279unescape_url(ctx,3,local+2); /*unescape-url*/
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[12])(ctx,1,local+2,&ftab[12],fqv[86]); /*get-output-stream-string*/
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[12])(ctx,1,local+2,&ftab[12],fqv[86]); /*get-output-stream-string*/
	local[0]= w;
BLK55687:
	ctx->vsp=local; return(local[0]);}

/*digits-string*/
static pointer F51283digits_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT55735;}
	local[0]= makeint(10);
ENT55735:
ENT55734:
	if (n>3) maerror();
	local[1]= argv[1];
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(pointer)LSEQP(ctx,2,local+1); /*<=*/
	if (w==NIL) goto IF55751;
	local[1]= NIL;
	local[2]= fqv[95];
	local[3]= argv[0];
	local[4]= argv[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	goto IF55752;
IF55751:
	local[1]= loadglobal(fqv[8]);
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)SUB1(ctx,1,local+3); /*1-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)F51283digits_string(ctx,2,local+2); /*digits-string*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)F51283digits_string(ctx,2,local+3); /*digits-string*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)CONCATENATE(ctx,3,local+1); /*concatenate*/
	local[1]= w;
IF55752:
	w = local[1];
	local[0]= w;
BLK55732:
	ctx->vsp=local; return(local[0]);}

/*timed-file-name*/
static pointer F51285timed_file_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT55792;}
	ctx->vsp=local+0;
	w=(pointer)LOCALTIME(ctx,0,local+0); /*unix:localtime*/
	local[0]= w;
ENT55792:
ENT55791:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= fqv[96];
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(pointer)F51283digits_string(ctx,2,local+4); /*digits-string*/
	local[4]= w;
	local[5]= local[0];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= makeint(2);
	ctx->vsp=local+7;
	w=(pointer)F51283digits_string(ctx,2,local+5); /*digits-string*/
	local[5]= w;
	local[6]= local[0];
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= makeint(2);
	ctx->vsp=local+8;
	w=(pointer)F51283digits_string(ctx,2,local+6); /*digits-string*/
	local[6]= w;
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,7,local+1); /*format*/
	local[0]= w;
BLK55789:
	ctx->vsp=local; return(local[0]);}

/*dated-file-name*/
static pointer F51287dated_file_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT55833;}
	ctx->vsp=local+0;
	w=(pointer)LOCALTIME(ctx,0,local+0); /*unix:localtime*/
	local[0]= w;
ENT55833:
ENT55832:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= fqv[97];
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= makeint(5);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	local[5]= makeint(2);
	ctx->vsp=local+6;
	w=(pointer)F51283digits_string(ctx,2,local+4); /*digits-string*/
	local[4]= w;
	local[5]= local[0];
	local[6]= makeint(4);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= fqv[98];
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,2,local+5,&ftab[0],fqv[4]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= local[0];
	local[7]= makeint(3);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= makeint(2);
	ctx->vsp=local+8;
	w=(pointer)F51283digits_string(ctx,2,local+6); /*digits-string*/
	local[6]= w;
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,7,local+1); /*format*/
	local[0]= w;
BLK55830:
	ctx->vsp=local; return(local[0]);}

/*sequential-file-name*/
static pointer F51289sequential_file_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT55882;}
	local[0]= makeint(4);
ENT55882:
ENT55881:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= fqv[99];
	local[3]= argv[0];
	local[4]= argv[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)F51283digits_string(ctx,2,local+4); /*digits-string*/
	local[4]= w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,5,local+1); /*format*/
	local[0]= w;
BLK55879:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___string(ctx,n,argv,env)
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
	local[0]= fqv[100];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= fqv[101];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF55917;
	local[0]= fqv[102];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[103],w);
	goto IF55918;
IF55917:
	local[0]= fqv[104];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF55918:
	local[0]= fqv[105];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[106],module,F51161read_sharp_backslash,fqv[107]);
	local[0]= makeint(35);
	local[1]= makeint(92);
	local[2]= fqv[106];
	ctx->vsp=local+3;
	w=(pointer)SETDISPMACRO(ctx,3,local+0); /*set-dispatch-macro-character*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[108],module,F51165true_string,fqv[109]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[8],module,F51168string,fqv[110]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[111],module,F51171make_string,fqv[112]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[113],module,F51174string_left_trim,fqv[114]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[115],module,F51177string_right_trim,fqv[116]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[117],module,F51180string_trim,fqv[118]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[119],module,F51183nstring_downcase,fqv[120]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[121],module,F51186nstring_upcase,fqv[122]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[123],module,F51189string_upcase,fqv[124]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[125],module,F51192string_downcase,fqv[126]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[127],module,F51195string_,fqv[128]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[3],module,F51198string_equal,fqv[129]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[130],module,F51201substringp,fqv[131]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M52233string_get,fqv[132],fqv[8],fqv[133]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M52256string_set,fqv[134],fqv[8],fqv[135]);
	local[0]= fqv[46];
	local[1]= fqv[136];
	local[2]= fqv[46];
	local[3]= fqv[137];
	local[4]= loadglobal(fqv[138]);
	local[5]= fqv[139];
	local[6]= fqv[140];
	local[7]= fqv[141];
	local[8]= NIL;
	local[9]= fqv[142];
	local[10]= NIL;
	local[11]= fqv[143];
	local[12]= makeint(-1);
	local[13]= fqv[144];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[15])(ctx,13,local+2,&ftab[15],fqv[145]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[146];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[147],module,F51211explode_directory_names,fqv[148]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M52630pathname_parse_namestring,fqv[47],fqv[46],fqv[149]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M53034pathname_directory_string,fqv[35],fqv[46],fqv[150]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M53234pathname_namestring,fqv[44],fqv[46],fqv[151]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M53298pathname_host,fqv[51],fqv[46],fqv[152]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M53332pathname_device,fqv[52],fqv[46],fqv[153]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M53366pathname_directory,fqv[53],fqv[46],fqv[154]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M53400pathname_name,fqv[54],fqv[46],fqv[155]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M53434pathname_type,fqv[55],fqv[46],fqv[156]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M53468pathname_set_type,fqv[157],fqv[46],fqv[158]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M53491pathname_version,fqv[56],fqv[46],fqv[159]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M53525pathname_merge,fqv[57],fqv[46],fqv[160]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M53627pathname_add_directory,fqv[161],fqv[46],fqv[162]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M53657pathname_prin1,fqv[163],fqv[46],fqv[164]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M53686pathname_init,fqv[50],fqv[46],fqv[165]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[166],module,F51215pathnamep,fqv[167]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[46],module,F51218pathname,fqv[168]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[60],module,F51221namestring,fqv[169]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[170],module,F51224pathname_directory,fqv[171]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[172],module,F51227pathname_name,fqv[173]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[174],module,F51230pathname_type,fqv[175]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[176],module,F51233directory_namestring,fqv[177]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[178],module,F51236make_pathname,fqv[179]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[180],module,F51239parse_namestring,fqv[181]);
	local[0]= fqv[59];
	local[1]= fqv[136];
	local[2]= fqv[182];
	local[3]= fqv[183];
	local[4]= fqv[184];
	local[5]= fqv[185];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[186],module,F51243null_string_p,fqv[187]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[188],module,F51246merge_pathnames,fqv[189]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[190],module,F51249concatenate_pathnames,fqv[191]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[192],module,F51252truename,fqv[193]);
	local[0]= fqv[74];
	local[1]= fqv[136];
	local[2]= fqv[74];
	local[3]= fqv[137];
	local[4]= loadglobal(fqv[46]);
	local[5]= fqv[139];
	local[6]= fqv[194];
	local[7]= fqv[141];
	local[8]= NIL;
	local[9]= fqv[142];
	local[10]= NIL;
	local[11]= fqv[143];
	local[12]= makeint(-1);
	local[13]= fqv[144];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[15])(ctx,13,local+2,&ftab[15],fqv[145]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M54377url_pathname_prin1,fqv[163],fqv[74],fqv[195]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M54409url_pathname_string,fqv[64],fqv[74],fqv[196]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M54431url_pathname_string2,fqv[197],fqv[74],fqv[198]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M54452url_pathname_port,fqv[199],fqv[74],fqv[200]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M54488url_pathname_server,fqv[201],fqv[74],fqv[202]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M54524url_pathname_connect,fqv[203],fqv[74],fqv[204]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M54551url_pathname_host,fqv[51],fqv[74],fqv[205]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M54587url_pathname_protocol,fqv[206],fqv[74],fqv[207]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M54623url_pathname_parse_namestring,fqv[47],fqv[74],fqv[208]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M54841url_pathname_percent_escape,fqv[209],fqv[74],fqv[210]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[74],module,F51271url_pathname,fqv[211]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[212],module,F51273parse_url,fqv[213]);
	local[0]= fqv[83];
	local[1]= fqv[214];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF56131;
	local[0]= fqv[83];
	local[1]= fqv[214];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[83];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF56154;
	local[0]= fqv[83];
	local[1]= fqv[136];
	local[2]= fqv[215];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF56155;
IF56154:
	local[0]= NIL;
IF56155:
	local[0]= fqv[83];
	goto IF56132;
IF56131:
	local[0]= NIL;
IF56132:
	ctx->vsp=local+0;
	compfun(ctx,fqv[216],module,F51275escape_url,fqv[217]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[218],module,F51277escaped_url_string_from_namestring,fqv[219]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[220],module,F51279unescape_url,fqv[221]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[222],module,F51281unescaped_url_string_from_namestring,fqv[223]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[224],module,F51283digits_string,fqv[225]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[226],module,F51285timed_file_name,fqv[227]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[228],module,F51287dated_file_name,fqv[229]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[230],module,F51289sequential_file_name,fqv[231]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<16; i++) ftab[i]=fcallx;
}
