/* ./array.c :  entry=array */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "array.h"
#pragma init (register_array)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___array();
extern pointer build_quote_vector();
static int register_array()
  { add_module_initializer("___array", ___array);}

static pointer F57035fill_initial_contents();
static pointer F57038make_array();
static pointer F57041array_total_size();
static pointer F57044fill_pointer();
static pointer F57047array_rank();
static pointer F57050array_dimensions();
static pointer F57053array_dimension();
static pointer F57056array_vector();
static pointer F57059row_major_aref();
static pointer F57062list_dimensions();
static pointer F57065read_array();
static pointer F57068read_float_array();
static pointer F57071read_integer_array();
static pointer F57081float_vector_p();
static pointer F57084integer_vector_p();
static pointer F57087bit_vector_p();
static pointer F57090matrixp();
static pointer F57093make_matrix();
static pointer F57096matrix_row();
static pointer F57099matrix_column();
static pointer F57102set_matrix_row();
static pointer F57105set_matrix_column();
static pointer F57108replace_matrix();
static pointer F57111copy_matrix();
static pointer F57114scale_matrix();
static pointer F57117matrix();
static pointer F57120acos();
static pointer F57123asin();
static pointer F57126unit_matrix();
static pointer F57129m__();
static pointer F57132simultaneous_equation();
static pointer F57135inverse_matrix();
static pointer F57138vector_x();
static pointer F57141vector_y();
static pointer F57144vector_z();
static pointer F57147v_();
static pointer F57150euler_matrix();
static pointer F57153rpy_matrix();

/*:elmtype*/
static pointer M57237vectorclass_elmtype(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK57238:
	ctx->vsp=local; return(local[0]);}

/*:element-type*/
static pointer M57253vectorclass_element_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= fqv[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[1]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK57254:
	ctx->vsp=local; return(local[0]);}

/*:elmtype*/
static pointer M57288vector_elmtype(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)GETCLASS(ctx,1,local+0); /*class*/
	local[0]= w;
	local[1]= fqv[2];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK57289:
	ctx->vsp=local; return(local[0]);}

/*:element-type*/
static pointer M57309vector_element_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)GETCLASS(ctx,1,local+0); /*class*/
	local[0]= w;
	local[1]= fqv[3];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK57310:
	ctx->vsp=local; return(local[0]);}

/*:element-type*/
static pointer M57360array_element_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)F57081float_vector_p(ctx,1,local+0); /*float-vector-p*/
	if (w==NIL) goto CON57375;
	local[0]= fqv[4];
	goto CON57373;
CON57375:
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)F57084integer_vector_p(ctx,1,local+0); /*integer-vector-p*/
	if (w==NIL) goto CON57384;
	local[0]= fqv[5];
	goto CON57373;
CON57384:
	w = argv[0]->c.obj.iv[1];
	if (!isstring(w)) goto CON57393;
	local[0]= fqv[6];
	goto CON57373;
CON57393:
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)F57087bit_vector_p(ctx,1,local+0); /*bit-vector-p*/
	if (w==NIL) goto CON57400;
	local[0]= fqv[7];
	goto CON57373;
CON57400:
	local[0]= T;
	goto CON57373;
CON57409:
	local[0]= NIL;
CON57373:
	w = local[0];
	local[0]= w;
BLK57361:
	ctx->vsp=local; return(local[0]);}

/*fill-initial-contents*/
static pointer F57035fill_initial_contents(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[0];
	local[0]= w;
	local[1]= makeint(0);
	if (argv[2]==NIL) goto CON57482;
	local[2]= (pointer)get_sym_func(fqv[8]);
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,2,local+2); /*apply*/
	local[1] = w;
	local[2]= makeint(0);
	local[3]= local[0];
WHL57522:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX57523;
	local[4]= argv[0];
	local[5]= argv[1];
	local[6]= argv[2];
	local[7]= argv[3];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)F57035fill_initial_contents(ctx,4,local+4); /*fill-initial-contents*/
	local[4]= argv[1];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	argv[1] = w;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL57522;
WHX57523:
	local[4]= NIL;
BLK57524:
	w = NIL;
	local[2]= w;
	goto CON57480;
CON57482:
	local[2]= makeint(0);
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
WHL57593:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX57594;
	local[4]= argv[0];
	local[5]= argv[1];
	local[6]= argv[3];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	argv[1] = w;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[1] = w;
	local[4]= local[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)GREATERP(ctx,2,local+4); /*>*/
	if (w==NIL) goto IF57632;
	local[4]= fqv[9];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,1,local+4); /*error*/
	local[4]= w;
	goto IF57633;
IF57632:
	local[4]= NIL;
IF57633:
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL57593;
WHX57594:
	local[4]= NIL;
BLK57595:
	w = NIL;
	local[2]= w;
	goto CON57480;
CON57564:
	local[2]= NIL;
CON57480:
	w = argv[0];
	local[0]= w;
BLK57416:
	ctx->vsp=local; return(local[0]);}

/*make-array*/
static pointer F57038make_array(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[10], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY57677;
	local[0] = loadglobal(fqv[11]);
KEY57677:
	if (n & (1<<1)) goto KEY57684;
	local[1] = NIL;
KEY57684:
	if (n & (1<<2)) goto KEY57689;
	local[2] = NIL;
KEY57689:
	if (n & (1<<3)) goto KEY57694;
	local[3] = makeint(0);
KEY57694:
	if (n & (1<<4)) goto KEY57699;
	local[4] = NIL;
KEY57699:
	if (n & (1<<5)) goto KEY57704;
	local[5] = NIL;
KEY57704:
	if (n & (1<<6)) goto KEY57709;
	local[6] = NIL;
KEY57709:
	if (n & (1<<7)) goto KEY57714;
	local[7] = NIL;
KEY57714:
	if (n & (1<<8)) goto KEY57719;
	local[8] = NIL;
KEY57719:
	if (n & (1<<9)) goto KEY57724;
	local[9] = NIL;
KEY57724:
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= local[0];
	ctx->vsp=local+14;
	w=(pointer)CLASSP(ctx,1,local+13); /*classp*/
	if (w!=NIL) goto IF57737;
	local[13]= local[0];
	local[14]= local[13];
	w = fqv[12];
	if (memq(local[14],w)==NIL) goto IF57763;
	local[14]= loadglobal(fqv[13]);
	goto IF57764;
IF57763:
	local[14]= local[13];
	w = fqv[14];
	if (memq(local[14],w)==NIL) goto IF57776;
	local[14]= loadglobal(fqv[15]);
	goto IF57777;
IF57776:
	local[14]= local[13];
	w = fqv[16];
	if (memq(local[14],w)==NIL) goto IF57789;
	local[14]= loadglobal(fqv[17]);
	goto IF57790;
IF57789:
	local[14]= local[13];
	w = fqv[18];
	if (memq(local[14],w)==NIL) goto IF57802;
	local[14]= loadglobal(fqv[19]);
	goto IF57803;
IF57802:
	if (T==NIL) goto IF57815;
	local[14]= loadglobal(fqv[11]);
	goto IF57816;
IF57815:
	local[14]= NIL;
IF57816:
IF57803:
IF57790:
IF57777:
IF57764:
	w = local[14];
	local[0] = w;
	local[13]= local[0];
	goto IF57738;
IF57737:
	local[13]= NIL;
IF57738:
	w = argv[0];
	if (!isint(w)) goto CON57828;
	local[13]= local[0];
	local[14]= argv[0];
	ctx->vsp=local+15;
	w=(pointer)INSTANTIATE(ctx,2,local+13); /*instantiate*/
	local[11] = w;
	local[12] = local[11];
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	argv[0] = w;
	local[13]= argv[0];
	goto CON57826;
CON57828:
	local[13]= loadglobal(fqv[20]);
	ctx->vsp=local+14;
	w=(pointer)INSTANTIATE(ctx,1,local+13); /*instantiate*/
	local[12] = w;
	local[13]= makeint(0);
	local[14]= argv[0];
	ctx->vsp=local+15;
	w=(pointer)LENGTH(ctx,1,local+14); /*length*/
	local[14]= w;
	local[15]= (pointer)get_sym_func(fqv[8]);
	local[16]= argv[0];
	ctx->vsp=local+17;
	w=(pointer)APPLY(ctx,2,local+15); /*apply*/
	local[15]= w;
	local[16]= local[14];
	local[17]= makeint(7);
	ctx->vsp=local+18;
	w=(pointer)GREATERP(ctx,2,local+16); /*>*/
	if (w==NIL) goto IF57892;
	local[16]= fqv[21];
	ctx->vsp=local+17;
	w=(pointer)SIGERROR(ctx,1,local+16); /*error*/
	local[16]= w;
	goto IF57893;
IF57892:
	local[16]= NIL;
IF57893:
	local[16]= (pointer)get_sym_func(fqv[22]);
	local[17]= argv[0];
	ctx->vsp=local+18;
	w=(*ftab[1])(ctx,2,local+16,&ftab[1],fqv[23]); /*every*/
	if (w!=NIL) goto IF57902;
	local[16]= fqv[24];
	ctx->vsp=local+17;
	w=(pointer)SIGERROR(ctx,1,local+16); /*error*/
	local[16]= w;
	goto IF57903;
IF57902:
	local[16]= NIL;
IF57903:
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)VECTORP(ctx,1,local+16); /*vectorp*/
	if (w==NIL) goto CON57923;
	local[16]= local[2];
	goto CON57921;
CON57923:
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)ARRAYP(ctx,1,local+16); /*arrayp*/
	if (w==NIL) goto CON57931;
	local[16]= local[2]->c.obj.iv[1];
	goto CON57921;
CON57931:
	local[16]= local[0];
	local[17]= makeint(1);
	local[18]= local[15];
	ctx->vsp=local+19;
	w=(pointer)MAX(ctx,2,local+17); /*max*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)INSTANTIATE(ctx,2,local+16); /*instantiate*/
	local[16]= w;
	goto CON57921;
CON57943:
	local[16]= NIL;
CON57921:
	local[11] = local[16];
	local[16]= local[14];
	local[17]= local[16];
	*(ovafptr(local[12],fqv[25])) = local[17];
	local[16]= local[11];
	local[17]= local[16];
	w = local[12];
	w->c.obj.iv[1] = local[17];
	w = local[1];
	if (!isnum(w)) goto IF57972;
	local[16]= local[1];
	goto IF57973;
IF57972:
	if (local[1]==NIL) goto IF57979;
	local[16]= local[15];
	goto IF57980;
IF57979:
	local[16]= NIL;
IF57980:
IF57973:
	local[17]= local[16];
	w = local[12];
	w->c.obj.iv[3] = local[17];
	local[16]= local[3];
	local[17]= local[16];
	w = local[12];
	w->c.obj.iv[4] = local[17];
	local[16]= makeint(0);
TAG58013:
	local[17]= local[16];
	local[18]= local[14];
	ctx->vsp=local+19;
	w=(pointer)GREQP(ctx,2,local+17); /*>=*/
	if (w==NIL) goto IF58018;
	w = NIL;
	ctx->vsp=local+17;
	local[16]=w;
	goto BLK57998;
	goto IF58019;
IF58018:
	local[17]= NIL;
IF58019:
	local[17]= local[12];
	local[18]= loadglobal(fqv[20]);
	local[19]= local[16];
	local[20]= makeint(5);
	ctx->vsp=local+21;
	w=(pointer)PLUS(ctx,2,local+19); /*+*/
	local[19]= w;
	local[20]= argv[0];
	local[21]= local[16];
	ctx->vsp=local+22;
	w=(pointer)ELT(ctx,2,local+20); /*elt*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)SETSLOT(ctx,4,local+17); /*setslot*/
	local[17]= local[16];
	ctx->vsp=local+18;
	w=(pointer)ADD1(ctx,1,local+17); /*1+*/
	local[17]= w;
	local[16] = local[17];
	w = NIL;
	ctx->vsp=local+17;
	goto TAG58013;
	w = NIL;
	local[16]= w;
BLK57998:
	w = local[16];
	local[13]= w;
	goto CON57826;
CON57858:
	local[13]= NIL;
CON57826:
	if (local[6]==NIL) goto IF58078;
	local[13]= local[11];
	local[14]= local[6];
	ctx->vsp=local+15;
	w=(*ftab[2])(ctx,2,local+13,&ftab[2],fqv[26]); /*fill*/
	local[13]= w;
	goto IF58079;
IF58078:
	local[13]= NIL;
IF58079:
	if (local[5]==NIL) goto IF58094;
	local[13]= local[11];
	local[14]= makeint(0);
	local[15]= argv[0];
	local[16]= local[5];
	ctx->vsp=local+17;
	w=(pointer)F57035fill_initial_contents(ctx,4,local+13); /*fill-initial-contents*/
	local[13]= w;
	goto IF58095;
IF58094:
	local[13]= NIL;
IF58095:
	w = local[12];
	local[0]= w;
BLK57659:
	ctx->vsp=local; return(local[0]);}

/*array-total-size*/
static pointer F57041array_total_size(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= *(ovafptr(argv[0],fqv[25]));
	local[1]= makeint(1);
	local[2]= makeint(0);
	local[3]= local[0];
WHL58161:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX58162;
	local[4]= local[1];
	local[5]= argv[0];
	local[6]= loadglobal(fqv[20]);
	local[7]= makeint(5);
	w = local[2];
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[7]= (pointer)((eusinteger_t)local[7] + (eusinteger_t)w);
	ctx->vsp=local+8;
	w=(pointer)SLOT(ctx,3,local+5); /*slot*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[1] = w;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL58161;
WHX58162:
	local[4]= NIL;
BLK58163:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK58113:
	ctx->vsp=local; return(local[0]);}

/*fill-pointer*/
static pointer F57044fill_pointer(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)ARRAYP(ctx,1,local+0); /*arrayp*/
	if (w==NIL) goto IF58218;
	local[0]= *(ovafptr(argv[0],fqv[27]));
	goto IF58219;
IF58218:
	local[0]= fqv[28];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF58219:
	w = local[0];
	local[0]= w;
BLK58208:
	ctx->vsp=local; return(local[0]);}

/*array-rank*/
static pointer F57047array_rank(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = *(ovafptr(argv[0],fqv[25]));
	local[0]= w;
BLK58232:
	ctx->vsp=local; return(local[0]);}

/*array-dimensions*/
static pointer F57050array_dimensions(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= *(ovafptr(argv[0],fqv[25]));
	local[1]= NIL;
WHL58271:
	local[2]= local[0];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto WHX58272;
	local[2]= argv[0];
	local[3]= loadglobal(fqv[20]);
	local[4]= makeint(5);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SUB1(ctx,1,local+5); /*1-*/
	local[0] = w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SLOT(ctx,3,local+2); /*slot*/
	local[2]= w;
	w = local[1];
	ctx->vsp=local+3;
	local[1] = cons(ctx,local[2],w);
	goto WHL58271;
WHX58272:
	local[2]= NIL;
BLK58273:
	w = local[1];
	local[0]= w;
BLK58247:
	ctx->vsp=local; return(local[0]);}

/*array-dimension*/
static pointer F57053array_dimension(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)ARRAYP(ctx,1,local+0); /*arrayp*/
	if (w==NIL) goto IF58324;
	local[0]= argv[0];
	local[1]= loadglobal(fqv[20]);
	local[2]= makeint(5);
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SLOT(ctx,3,local+0); /*slot*/
	local[0]= w;
	goto IF58325;
IF58324:
	local[0]= NIL;
IF58325:
	w = local[0];
	local[0]= w;
BLK58312:
	ctx->vsp=local; return(local[0]);}

/*array-vector*/
static pointer F57056array_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)VECTORP(ctx,1,local+0); /*vectorp*/
	if (w==NIL) goto CON58356;
	local[0]= argv[0];
	goto CON58354;
CON58356:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)ARRAYP(ctx,1,local+0); /*arrayp*/
	if (w==NIL) goto CON58364;
	local[0]= argv[0]->c.obj.iv[1];
	goto CON58354;
CON58364:
	local[0]= fqv[29];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto CON58354;
CON58376:
	local[0]= NIL;
CON58354:
	w = local[0];
	local[0]= w;
BLK58344:
	ctx->vsp=local; return(local[0]);}

/*row-major-aref*/
static pointer F57059row_major_aref(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
BLK58384:
	ctx->vsp=local; return(local[0]);}

/*list-dimensions*/
static pointer F57062list_dimensions(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!iscons(w)) goto CON58418;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)F57062list_dimensions(ctx,1,local+1); /*list-dimensions*/
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	goto CON58416;
CON58418:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto CON58416;
CON58439:
	local[0]= NIL;
CON58416:
	w = local[0];
	local[0]= w;
BLK58406:
	ctx->vsp=local; return(local[0]);}

/*read-array*/
static pointer F57065read_array(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= T;
	local[2]= T;
	local[3]= T;
	ctx->vsp=local+4;
	w=(pointer)READ(ctx,4,local+0); /*read*/
	local[0]= w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F57062list_dimensions(ctx,1,local+1); /*list-dimensions*/
	local[1]= w;
	local[2]= fqv[30];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F57038make_array(ctx,3,local+1); /*make-array*/
	local[0]= w;
BLK58450:
	ctx->vsp=local; return(local[0]);}

/*read-float-array*/
static pointer F57068read_float_array(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= T;
	local[2]= T;
	local[3]= T;
	ctx->vsp=local+4;
	w=(pointer)READ(ctx,4,local+0); /*read*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)NUMEQUAL(ctx,2,local+1); /*=*/
	if (w==NIL) goto IF58515;
	local[1]= fqv[17];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[1]= w;
	goto IF58516;
IF58515:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F57062list_dimensions(ctx,1,local+1); /*list-dimensions*/
	local[1]= w;
	local[2]= fqv[3];
	local[3]= fqv[4];
	local[4]= fqv[30];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)F57038make_array(ctx,5,local+1); /*make-array*/
	local[1]= w;
IF58516:
	w = local[1];
	local[0]= w;
BLK58488:
	ctx->vsp=local; return(local[0]);}

/*read-integer-array*/
static pointer F57071read_integer_array(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= T;
	local[2]= T;
	local[3]= T;
	ctx->vsp=local+4;
	w=(pointer)READ(ctx,4,local+0); /*read*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)NUMEQUAL(ctx,2,local+1); /*=*/
	if (w==NIL) goto IF58568;
	local[1]= fqv[19];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[1]= w;
	goto IF58569;
IF58568:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F57062list_dimensions(ctx,1,local+1); /*list-dimensions*/
	local[1]= w;
	local[2]= fqv[3];
	local[3]= fqv[5];
	local[4]= fqv[30];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)F57038make_array(ctx,5,local+1); /*make-array*/
	local[1]= w;
IF58569:
	w = local[1];
	local[0]= w;
BLK58541:
	ctx->vsp=local; return(local[0]);}

/*float-vector-p*/
static pointer F57081float_vector_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[17]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK58604:
	ctx->vsp=local; return(local[0]);}

/*integer-vector-p*/
static pointer F57084integer_vector_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[19]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK58620:
	ctx->vsp=local; return(local[0]);}

/*bit-vector-p*/
static pointer F57087bit_vector_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[15]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK58636:
	ctx->vsp=local; return(local[0]);}

/*matrixp*/
static pointer F57090matrixp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[20]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
	if (w==NIL) goto AND58662;
	local[0]= *(ovafptr(argv[0],fqv[31]));
	ctx->vsp=local+1;
	w=(pointer)F57081float_vector_p(ctx,1,local+0); /*float-vector-p*/
	local[0]= w;
AND58662:
	w = local[0];
	local[0]= w;
BLK58652:
	ctx->vsp=local; return(local[0]);}

/*make-matrix*/
static pointer F57093make_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT58680;}
	local[0]= NIL;
ENT58680:
ENT58679:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[1]= w;
	local[2]= fqv[3];
	local[3]= fqv[4];
	local[4]= fqv[30];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)F57038make_array(ctx,5,local+1); /*make-array*/
	local[0]= w;
BLK58677:
	ctx->vsp=local; return(local[0]);}

/*matrix-row*/
static pointer F57096matrix_row(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F57047array_rank(ctx,1,local+0); /*array-rank*/
	local[0]= w;
	if (makeint(2)!=local[0]) goto IF58724;
	local[0]= *(ovafptr(argv[0],fqv[31]));
	local[1]= *(ovafptr(argv[0],fqv[32]));
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	local[2]= *(ovafptr(argv[0],fqv[32]));
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SUBSEQ(ctx,3,local+0); /*subseq*/
	local[0]= w;
	goto IF58725;
IF58724:
	local[0]= NIL;
IF58725:
	w = local[0];
	local[0]= w;
BLK58711:
	ctx->vsp=local; return(local[0]);}

/*matrix-column*/
static pointer F57099matrix_column(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F57047array_rank(ctx,1,local+0); /*array-rank*/
	local[0]= w;
	if (makeint(2)!=local[0]) goto IF58770;
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= argv[0]->c.obj.iv[6];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)GETCLASS(ctx,1,local+3); /*class*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,2,local+3); /*instantiate*/
	local[3]= w;
	local[4]= makeint(0);
	local[5]= local[0];
WHL58843:
	local[6]= local[4];
	w = local[5];
	if ((eusinteger_t)local[6] >= (eusinteger_t)w) goto WHX58844;
	local[6]= local[3];
	local[7]= local[4];
	local[8]= local[2];
	local[9]= argv[1];
	local[10]= local[4];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,3,local+6); /*aset*/
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[4] = w;
	goto WHL58843;
WHX58844:
	local[6]= NIL;
BLK58845:
	w = NIL;
	w = local[3];
	local[0]= w;
	goto IF58771;
IF58770:
	local[0]= NIL;
IF58771:
	w = local[0];
	local[0]= w;
BLK58757:
	ctx->vsp=local; return(local[0]);}

/*set-matrix-row*/
static pointer F57102set_matrix_row(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F57047array_rank(ctx,1,local+0); /*array-rank*/
	local[0]= w;
	if (makeint(2)!=local[0]) goto IF58905;
	local[0]= *(ovafptr(argv[0],fqv[31]));
	local[1]= argv[2];
	local[2]= fqv[33];
	local[3]= *(ovafptr(argv[0],fqv[32]));
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	local[4]= fqv[34];
	local[5]= *(ovafptr(argv[0],fqv[32]));
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[3])(ctx,6,local+0,&ftab[3],fqv[35]); /*replace*/
	local[0]= w;
	goto IF58906;
IF58905:
	local[0]= NIL;
IF58906:
	w = argv[0];
	local[0]= w;
BLK58890:
	ctx->vsp=local; return(local[0]);}

/*set-matrix-column*/
static pointer F57105set_matrix_column(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F57047array_rank(ctx,1,local+0); /*array-rank*/
	local[0]= w;
	if (makeint(2)!=local[0]) goto IF58962;
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= argv[0]->c.obj.iv[6];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= makeint(0);
	local[4]= local[0];
WHL59023:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX59024;
	local[5]= local[2];
	local[6]= argv[1];
	local[7]= local[3];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	local[7]= argv[2];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)ASET(ctx,3,local+5); /*aset*/
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL59023;
WHX59024:
	local[5]= NIL;
BLK59025:
	w = NIL;
	local[0]= w;
	goto IF58963;
IF58962:
	local[0]= NIL;
IF58963:
	w = argv[0];
	local[0]= w;
BLK58947:
	ctx->vsp=local; return(local[0]);}

/*replace-matrix*/
static pointer F57108replace_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[1]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,2,local+0,&ftab[3],fqv[35]); /*replace*/
	w = argv[0];
	local[0]= w;
BLK59070:
	ctx->vsp=local; return(local[0]);}

/*copy-matrix*/
static pointer F57111copy_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+2;
	w=(pointer)F57093make_matrix(ctx,2,local+0); /*make-matrix*/
	local[0]= w;
	local[1]= local[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,2,local+1,&ftab[3],fqv[35]); /*replace*/
	w = local[0];
	local[0]= w;
BLK59099:
	ctx->vsp=local; return(local[0]);}

/*scale-matrix*/
static pointer F57114scale_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT59150;}
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)F57111copy_matrix(ctx,1,local+0); /*copy-matrix*/
	local[0]= w;
ENT59150:
ENT59149:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1]->c.obj.iv[1];
	local[3]= local[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)SCALEVEC(ctx,3,local+1); /*scale*/
	w = local[0];
	local[0]= w;
BLK59147:
	ctx->vsp=local; return(local[0]);}

/*matrix*/
static pointer F57117matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST59189:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= (pointer)get_sym_func(fqv[36]);
	local[3]= (pointer)get_sym_func(fqv[37]);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,2,local+2); /*apply*/
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F57093make_matrix(ctx,3,local+1); /*make-matrix*/
	local[0]= w;
BLK59187:
	ctx->vsp=local; return(local[0]);}

/*acos*/
static pointer F57120acos(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeflt(1.00000000e+00);
	local[1]= argv[0];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)SQRT(ctx,1,local+0); /*sqrt*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)ATAN(ctx,2,local+0); /*atan*/
	local[0]= w;
BLK59215:
	ctx->vsp=local; return(local[0]);}

/*asin*/
static pointer F57123asin(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeflt(1.00000000e+00);
	local[2]= argv[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SQRT(ctx,1,local+1); /*sqrt*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)ATAN(ctx,2,local+0); /*atan*/
	local[0]= w;
BLK59243:
	ctx->vsp=local; return(local[0]);}

/*unit-matrix*/
static pointer F57126unit_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT59274;}
	local[0]= makeint(3);
ENT59274:
ENT59273:
	if (n>1) maerror();
	local[1]= local[0];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F57093make_matrix(ctx,2,local+1); /*make-matrix*/
	local[1]= w;
	local[2]= makeint(0);
	local[3]= local[0];
WHL59323:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX59324;
	local[4]= local[1];
	local[5]= local[2];
	local[6]= local[2];
	local[7]= makeflt(1.00000000e+00);
	ctx->vsp=local+8;
	w=(pointer)ASET(ctx,4,local+4); /*aset*/
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL59323;
WHX59324:
	local[4]= NIL;
BLK59325:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK59271:
	ctx->vsp=local; return(local[0]);}

/*m***/
static pointer F57129m__(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST59357:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)MATTIMES(ctx,2,local+3); /*m**/
	local[2] = w;
	local[3]= NIL;
	local[4]= local[0];
WHL59401:
	if (local[4]==NIL) goto WHX59402;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[2];
	local[6]= local[3];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)MATTIMES(ctx,3,local+5); /*m**/
	goto WHL59401;
WHX59402:
	local[5]= NIL;
BLK59403:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK59355:
	ctx->vsp=local; return(local[0]);}

/*simultaneous-equation*/
static pointer F57132simultaneous_equation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)F57053array_dimension(ctx,2,local+0); /*array-dimension*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)F57126unit_matrix(ctx,1,local+0); /*unit-matrix*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)LU_DECOMPOSE(ctx,2,local+1); /*lu-decompose*/
	local[1]= w;
	local[2]= local[0];
	local[3]= local[1];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LU_SOLVE(ctx,3,local+2); /*lu-solve*/
	local[0]= w;
BLK59463:
	ctx->vsp=local; return(local[0]);}

/*inverse-matrix*/
static pointer F57135inverse_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)F57053array_dimension(ctx,2,local+0); /*array-dimension*/
	local[0]= w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F57126unit_matrix(ctx,1,local+1); /*unit-matrix*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)LU_DECOMPOSE(ctx,2,local+2); /*lu-decompose*/
	local[2]= w;
	local[3]= NIL;
	local[4]= local[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)F57093make_matrix(ctx,2,local+4); /*make-matrix*/
	local[4]= w;
	local[5]= loadglobal(fqv[17]);
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,2,local+5); /*instantiate*/
	local[5]= w;
	local[6]= makeint(0);
	if (local[2]!=NIL) goto IF59550;
	w = fqv[38];
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK59502;
	goto IF59551;
IF59550:
	local[7]= NIL;
IF59551:
	local[7]= makeint(0);
	local[8]= local[0];
WHL59585:
	local[9]= local[7];
	w = local[8];
	if ((eusinteger_t)local[9] >= (eusinteger_t)w) goto WHX59586;
	local[9]= local[5];
	local[10]= local[7];
	local[11]= makeflt(1.00000000e+00);
	ctx->vsp=local+12;
	w=(pointer)ASET(ctx,3,local+9); /*aset*/
	local[9]= local[1];
	local[10]= local[2];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)LU_SOLVE(ctx,3,local+9); /*lu-solve*/
	local[3] = w;
	local[9]= makeint(0);
	local[10]= local[0];
WHL59634:
	local[11]= local[9];
	w = local[10];
	if ((eusinteger_t)local[11] >= (eusinteger_t)w) goto WHX59635;
	local[11]= local[4];
	local[12]= local[9];
	local[13]= local[7];
	local[14]= local[3];
	local[15]= local[9];
	ctx->vsp=local+16;
	w=(pointer)AREF(ctx,2,local+14); /*aref*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)ASET(ctx,4,local+11); /*aset*/
	local[11]= local[9];
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[9] = w;
	goto WHL59634;
WHX59635:
	local[11]= NIL;
BLK59636:
	w = NIL;
	local[9]= local[5];
	local[10]= local[7];
	local[11]= makeflt(0.00000000e+00);
	ctx->vsp=local+12;
	w=(pointer)ASET(ctx,3,local+9); /*aset*/
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	local[7] = w;
	goto WHL59585;
WHX59586:
	local[9]= NIL;
BLK59587:
	w = NIL;
	w = local[4];
	local[0]= w;
BLK59502:
	ctx->vsp=local; return(local[0]);}

/*vector-x*/
static pointer F57138vector_x(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	{ register eusinteger_t i=intval(makeint(0));
	  w=makeflt(local[0]->c.fvec.fv[i]);}
	local[0]= w;
BLK59688:
	ctx->vsp=local; return(local[0]);}

/*vector-y*/
static pointer F57141vector_y(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	{ register eusinteger_t i=intval(makeint(1));
	  w=makeflt(local[0]->c.fvec.fv[i]);}
	local[0]= w;
BLK59707:
	ctx->vsp=local; return(local[0]);}

/*vector-z*/
static pointer F57144vector_z(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	{ register eusinteger_t i=intval(makeint(2));
	  w=makeflt(local[0]->c.fvec.fv[i]);}
	local[0]= w;
BLK59726:
	ctx->vsp=local; return(local[0]);}

/*v=*/
static pointer F57147v_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)VDISTANCE(ctx,2,local+0); /*distance*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[4])(ctx,1,local+0,&ftab[4],fqv[39]); /*zerop*/
	local[0]= w;
BLK59745:
	ctx->vsp=local; return(local[0]);}

/*euler-matrix*/
static pointer F57150euler_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[40];
	ctx->vsp=local+2;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+0); /*rotation-matrix*/
	local[0]= w;
	local[1]= local[0];
	local[2]= argv[1];
	local[3]= fqv[41];
	local[4]= NIL;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ROTMAT(ctx,5,local+1); /*rotate-matrix*/
	local[1]= local[0];
	local[2]= argv[2];
	local[3]= fqv[40];
	local[4]= NIL;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ROTMAT(ctx,5,local+1); /*rotate-matrix*/
	w = local[0];
	local[0]= w;
BLK59767:
	ctx->vsp=local; return(local[0]);}

/*rpy-matrix*/
static pointer F57153rpy_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[42];
	ctx->vsp=local+2;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+0); /*rotation-matrix*/
	local[0]= w;
	local[1]= local[0];
	local[2]= argv[1];
	local[3]= fqv[41];
	local[4]= T;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ROTMAT(ctx,5,local+1); /*rotate-matrix*/
	local[1]= local[0];
	local[2]= argv[0];
	local[3]= fqv[40];
	local[4]= T;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ROTMAT(ctx,5,local+1); /*rotate-matrix*/
	w = local[0];
	local[0]= w;
BLK59818:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___array(ctx,n,argv,env)
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
	local[0]= fqv[43];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF59873;
	local[0]= fqv[44];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[45],w);
	goto IF59874;
IF59873:
	local[0]= fqv[46];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF59874:
	local[0]= fqv[47];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M57237vectorclass_elmtype,fqv[2],fqv[48],fqv[49]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M57253vectorclass_element_type,fqv[3],fqv[48],fqv[50]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M57288vector_elmtype,fqv[2],fqv[11],fqv[51]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M57309vector_element_type,fqv[3],fqv[11],fqv[52]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M57360array_element_type,fqv[3],fqv[20],fqv[53]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[54],module,F57035fill_initial_contents,fqv[55]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[56],module,F57038make_array,fqv[57]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[58],module,F57041array_total_size,fqv[59]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[27],module,F57044fill_pointer,fqv[60]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[61],module,F57047array_rank,fqv[62]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[63],module,F57050array_dimensions,fqv[64]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[65],module,F57053array_dimension,fqv[66]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[67],module,F57056array_vector,fqv[68]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[69],module,F57059row_major_aref,fqv[70]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[71],module,F57062list_dimensions,fqv[72]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[73],module,F57065read_array,fqv[74]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[75],module,F57068read_float_array,fqv[76]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[77],module,F57071read_integer_array,fqv[78]);
	local[0]= makeint(35);
	local[1]= makeint(65);
	local[2]= fqv[73];
	ctx->vsp=local+3;
	w=(pointer)SETDISPMACRO(ctx,3,local+0); /*set-dispatch-macro-character*/
	local[0]= makeint(35);
	local[1]= makeint(70);
	local[2]= fqv[75];
	ctx->vsp=local+3;
	w=(pointer)SETDISPMACRO(ctx,3,local+0); /*set-dispatch-macro-character*/
	local[0]= makeint(35);
	local[1]= makeint(73);
	local[2]= fqv[77];
	ctx->vsp=local+3;
	w=(pointer)SETDISPMACRO(ctx,3,local+0); /*set-dispatch-macro-character*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[79],module,F57081float_vector_p,fqv[80]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[81],module,F57084integer_vector_p,fqv[82]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[83],module,F57087bit_vector_p,fqv[84]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[85],module,F57090matrixp,fqv[86]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[87],module,F57093make_matrix,fqv[88]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[89],module,F57096matrix_row,fqv[90]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[91],module,F57099matrix_column,fqv[92]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[93],module,F57102set_matrix_row,fqv[94]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[95],module,F57105set_matrix_column,fqv[96]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[97],module,F57108replace_matrix,fqv[98]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[99],module,F57111copy_matrix,fqv[100]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[101],module,F57114scale_matrix,fqv[102]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[103],module,F57117matrix,fqv[104]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[105],module,F57120acos,fqv[106]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[107],module,F57123asin,fqv[108]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[109],module,F57126unit_matrix,fqv[110]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[111],module,F57129m__,fqv[112]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[113],module,F57132simultaneous_equation,fqv[114]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[115],module,F57135inverse_matrix,fqv[116]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[117],module,F57138vector_x,fqv[118]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[119],module,F57141vector_y,fqv[120]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[121],module,F57144vector_z,fqv[122]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[123],module,F57147v_,fqv[124]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[125],module,F57150euler_matrix,fqv[126]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[127],module,F57153rpy_matrix,fqv[128]);
	local[0]= fqv[129];
	local[1]= fqv[130];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,2,local+0,&ftab[5],fqv[131]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<6; i++) ftab[i]=fcallx;
}
