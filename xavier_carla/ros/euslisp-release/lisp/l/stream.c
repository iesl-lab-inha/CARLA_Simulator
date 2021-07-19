/* ./stream.c :  entry=stream */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "stream.h"
#pragma init (register_stream)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___stream();
extern pointer build_quote_vector();
static int register_stream()
  { add_module_initializer("___stream", ___stream);}

static pointer F22088reset_stream();
static pointer F22099make_two_way_stream();
static pointer F22102make_msgq_input_stream();
static pointer F22105make_msgq_output_stream();
static pointer F22109make_string_input_stream();
static pointer F22112make_string_output_stream();
static pointer F22117get_output_stream_string();
static pointer F22120read_from_string();
static pointer F22123princ_to_string();
static pointer F22126prin1_to_string();
static pointer F22135make_socket_address();
static pointer F22144make_socket_port();
static pointer F22152make_server_socket_stream();
static pointer F22156connect_sigalarm_handler();
static pointer F22159make_client_socket_stream();
static pointer F22162make_dgram_socket();
static pointer F22165connect_server();
static pointer F22169select_stream();
static pointer F22174sigio_handler();
static pointer F22183make_broadcast_stream();
static pointer F22186read_buffer();
static pointer F22189write_buffer();

/*:instream*/
static pointer M22251io_stream_instream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT22255;}
	local[0]= NIL;
ENT22255:
ENT22254:
	if (n>3) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[0]); /*input-stream-p*/
	if (w==NIL) goto IF22271;
	argv[0]->c.obj.iv[1] = local[0];
	local[1]= argv[0]->c.obj.iv[1];
	goto IF22272;
IF22271:
	local[1]= NIL;
IF22272:
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK22252:
	ctx->vsp=local; return(local[0]);}

/*:outstream*/
static pointer M22290io_stream_outstream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT22294;}
	local[0]= NIL;
ENT22294:
ENT22293:
	if (n>3) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,1,local+1,&ftab[1],fqv[1]); /*output-stream-p*/
	if (w==NIL) goto IF22310;
	argv[0]->c.obj.iv[2] = local[0];
	local[1]= argv[0]->c.obj.iv[2];
	goto IF22311;
IF22310:
	local[1]= NIL;
IF22311:
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK22291:
	ctx->vsp=local; return(local[0]);}

/*:infd*/
static pointer M22329io_stream_infd(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[2];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK22330:
	ctx->vsp=local; return(local[0]);}

/*:outfd*/
static pointer M22348io_stream_outfd(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= fqv[3];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK22349:
	ctx->vsp=local; return(local[0]);}

/*:in*/
static pointer M22367io_stream_in(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST22370:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[4]);
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[0]= w;
BLK22368:
	ctx->vsp=local; return(local[0]);}

/*:out*/
static pointer M22391io_stream_out(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST22394:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[4]);
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[0]= w;
BLK22392:
	ctx->vsp=local; return(local[0]);}

/*:flag*/
static pointer M22415io_stream_flag(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[5];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK22416:
	ctx->vsp=local; return(local[0]);}

/*:async*/
static pointer M22434io_stream_async(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[6];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK22435:
	ctx->vsp=local; return(local[0]);}

/*:fname*/
static pointer M22456io_stream_fname(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[7];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK22457:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M22475io_stream_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	argv[0]->c.obj.iv[1] = argv[2];
	argv[0]->c.obj.iv[2] = argv[3];
	w = argv[0];
	local[0]= w;
BLK22476:
	ctx->vsp=local; return(local[0]);}

/*:reset*/
static pointer M22522stream_reset(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT22526;}
	local[0]= NIL;
ENT22526:
ENT22525:
	if (n>3) maerror();
	argv[0]->c.obj.iv[3] = makeint(0);
	if (local[0]==NIL) goto IF22546;
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	goto IF22547;
IF22546:
	local[1]= makeint(0);
IF22547:
	argv[0]->c.obj.iv[4] = local[1];
	w = argv[0];
	local[0]= w;
BLK22523:
	ctx->vsp=local; return(local[0]);}

/*:discard*/
static pointer M22561stream_discard(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT22565;}
	local[0]= makeint(1);
ENT22565:
ENT22564:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[4];
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAX(ctx,2,local+1); /*max*/
	argv[0]->c.obj.iv[3] = w;
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK22562:
	ctx->vsp=local; return(local[0]);}

/*:count*/
static pointer M22597stream_count(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK22598:
	ctx->vsp=local; return(local[0]);}

/*:tail*/
static pointer M22613stream_tail(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT22617;}
	local[0]= NIL;
ENT22617:
ENT22616:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF22633;
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	argv[0]->c.obj.iv[4] = w;
	local[1]= argv[0]->c.obj.iv[4];
	goto IF22634;
IF22633:
	local[1]= NIL;
IF22634:
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK22614:
	ctx->vsp=local; return(local[0]);}

/*:chars-left*/
static pointer M22651stream_chars_left(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	local[0]= w;
BLK22652:
	ctx->vsp=local; return(local[0]);}

/*:tail-string*/
static pointer M22671stream_tail_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+3;
	w=(pointer)SUBSEQ(ctx,3,local+0); /*subseq*/
	local[0]= w;
BLK22672:
	ctx->vsp=local; return(local[0]);}

/*:buffer*/
static pointer M22690stream_buffer(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT22695;}
	local[0]= NIL;
ENT22695:
	if (n>=4) { local[1]=(argv[3]); goto ENT22694;}
	local[1]= NIL;
ENT22694:
ENT22693:
	if (n>4) maerror();
	if (local[1]==NIL) goto CON22717;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SUBSEQ(ctx,3,local+2); /*subseq*/
	local[2]= w;
	goto CON22715;
CON22717:
	w = local[0];
	if (!isstring(w)) goto CON22727;
	argv[0]->c.obj.iv[2] = local[0];
	local[2]= argv[0]->c.obj.iv[2];
	goto CON22715;
CON22727:
	w = local[0];
	if (!isint(w)) goto CON22738;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,1,local+2,&ftab[2],fqv[8]); /*make-string*/
	argv[0]->c.obj.iv[2] = w;
	local[2]= argv[0]->c.obj.iv[2];
	goto CON22715;
CON22738:
	local[2]= argv[0]->c.obj.iv[2];
	goto CON22715;
CON22752:
	local[2]= NIL;
CON22715:
	w = local[2];
	local[0]= w;
BLK22691:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M22758stream_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT22763;}
	local[0]= NIL;
ENT22763:
	if (n>=6) { local[1]=(argv[5]); goto ENT22762;}
	local[1]= NIL;
ENT22762:
ENT22761:
	if (n>6) maerror();
	argv[0]->c.obj.iv[1] = argv[2];
	w = argv[3];
	if (!isstring(w)) goto IF22792;
	local[2]= argv[3];
	goto IF22793;
IF22792:
	local[2]= loadglobal(fqv[9]);
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,2,local+2); /*instantiate*/
	local[2]= w;
IF22793:
	argv[0]->c.obj.iv[2] = local[2];
	w = local[0];
	if (!isint(w)) goto IF22805;
	local[2]= local[0];
	goto IF22806;
IF22805:
	local[2]= makeint(0);
IF22806:
	argv[0]->c.obj.iv[3] = local[2];
	w = local[1];
	if (!isint(w)) goto IF22813;
	local[2]= local[1];
	goto IF22814;
IF22813:
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
IF22814:
	argv[0]->c.obj.iv[4] = local[2];
	w = argv[0];
	local[0]= w;
BLK22759:
	ctx->vsp=local; return(local[0]);}

/*reset-stream*/
static pointer F22088reset_stream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[10];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK22831:
	ctx->vsp=local; return(local[0]);}

/*:fd*/
static pointer M22876file_stream_fd(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK22877:
	ctx->vsp=local; return(local[0]);}

/*:instream*/
static pointer M22892file_stream_instream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	if (fqv[11]!=local[0]) goto IF22905;
	local[0]= argv[0];
	goto IF22906;
IF22905:
	local[0]= NIL;
IF22906:
	w = local[0];
	local[0]= w;
BLK22893:
	ctx->vsp=local; return(local[0]);}

/*:outstream*/
static pointer M22915file_stream_outstream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	if (fqv[12]!=local[0]) goto IF22928;
	local[0]= argv[0];
	goto IF22929;
IF22928:
	local[0]= NIL;
IF22929:
	w = local[0];
	local[0]= w;
BLK22916:
	ctx->vsp=local; return(local[0]);}

/*:infd*/
static pointer M22938file_stream_infd(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	if (fqv[11]!=local[0]) goto IF22951;
	local[0]= argv[0]->c.obj.iv[5];
	goto IF22952;
IF22951:
	local[0]= NIL;
IF22952:
	w = local[0];
	local[0]= w;
BLK22939:
	ctx->vsp=local; return(local[0]);}

/*:outfd*/
static pointer M22961file_stream_outfd(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	if (fqv[12]!=local[0]) goto IF22974;
	local[0]= argv[0]->c.obj.iv[5];
	goto IF22975;
IF22974:
	local[0]= NIL;
IF22975:
	w = local[0];
	local[0]= w;
BLK22962:
	ctx->vsp=local; return(local[0]);}

/*:fname*/
static pointer M22984file_stream_fname(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK22985:
	ctx->vsp=local; return(local[0]);}

/*:flag*/
static pointer M23000file_stream_flag(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= makeint(3);
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= w;
BLK23001:
	ctx->vsp=local; return(local[0]);}

/*:async*/
static pointer M23017file_stream_async(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[2]==NIL) goto CON23034;
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= makeint(4);
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= makeint(8192);
	ctx->vsp=local+4;
	w=(pointer)LOGIOR(ctx,2,local+2); /*logior*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= makeint(8);
	ctx->vsp=local+2;
	w=(pointer)GETPID(ctx,0,local+2); /*unix:getpid*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= w;
	goto CON23032;
CON23034:
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= makeint(4);
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= makeint(8192);
	ctx->vsp=local+4;
	w=(pointer)LOGNOT(ctx,1,local+3); /*lognot*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LOGAND(ctx,2,local+2); /*logand*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= w;
	goto CON23032;
CON23057:
	local[0]= NIL;
CON23032:
	w = local[0];
	local[0]= w;
BLK23018:
	ctx->vsp=local; return(local[0]);}

/*:nonblock*/
static pointer M23076file_stream_nonblock(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[2]==NIL) goto CON23093;
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= makeint(4);
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= loadglobal(fqv[13]);
	ctx->vsp=local+4;
	w=(pointer)LOGIOR(ctx,2,local+2); /*logior*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= makeint(8);
	ctx->vsp=local+2;
	w=(pointer)GETPID(ctx,0,local+2); /*unix:getpid*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= w;
	goto CON23091;
CON23093:
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= makeint(4);
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= loadglobal(fqv[13]);
	ctx->vsp=local+4;
	w=(pointer)LOGNOT(ctx,1,local+3); /*lognot*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LOGAND(ctx,2,local+2); /*logand*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= w;
	goto CON23091;
CON23118:
	local[0]= NIL;
CON23091:
	w = local[0];
	local[0]= w;
BLK23077:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M23138file_stream_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT23142;}
	local[0]= T;
ENT23142:
ENT23141:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-3);
	local[2]= (pointer)get_sym_func(fqv[14]);
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[15]));
	local[5]= fqv[16];
	local[6]= local[0];
	local[7]= NIL;
	local[8]= fqv[17];
	local[9]= argv[0]->c.obj.iv[6];
	local[10]= argv[0]->c.obj.iv[1];
	local[11]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+12;
	w=(pointer)LENGTH(ctx,1,local+11); /*length*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,5,local+7); /*format*/
	local[7]= w;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,7,local+2); /*apply*/
	local[0]= w;
BLK23139:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M23179file_stream_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	if (n>=6) { local[0]=(argv[5]); goto ENT23183;}
	local[0]= makeint(128);
ENT23183:
ENT23182:
	if (n>6) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[15]));
	local[3]= fqv[18];
	local[4]= argv[4];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	argv[0]->c.obj.iv[5] = argv[2];
	argv[0]->c.obj.iv[6] = argv[3];
	argv[0]->c.obj.iv[4] = makeint(0);
	w = argv[0];
	local[0]= w;
BLK23180:
	ctx->vsp=local; return(local[0]);}

/*:read-bytes*/
static pointer M23255file_stream_read_bytes(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT23260;}
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[2])(ctx,1,local+0,&ftab[2],fqv[8]); /*make-string*/
	local[0]= w;
ENT23260:
	if (n>=5) { local[1]=(argv[4]); goto ENT23259;}
	local[1]= makeint(0);
ENT23259:
ENT23258:
	if (n>5) maerror();
	local[2]= NIL;
	w = local[0];
	if (isstring(w)) goto IF23293;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)LESSP(ctx,2,local+3); /*<*/
	if (w==NIL) goto IF23293;
	local[3]= fqv[19];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
	goto IF23294;
IF23293:
	local[3]= NIL;
IF23294:
	local[3]= argv[0];
	local[4]= fqv[20];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[2] = w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(*ftab[3])(ctx,1,local+3,&ftab[3],fqv[21]); /*plusp*/
	if (w==NIL) goto IF23310;
	local[3]= local[0];
	local[4]= argv[0];
	local[5]= fqv[22];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= fqv[23];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,4,local+3,&ftab[4],fqv[24]); /*replace*/
	local[3]= argv[2];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)MIN(ctx,2,local+3); /*min*/
	local[2] = w;
	local[3]= argv[0]->c.obj.iv[3];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	argv[0]->c.obj.iv[3] = w;
	local[3]= local[1];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[1] = w;
	local[3]= local[1];
	goto IF23311;
IF23310:
	local[3]= NIL;
IF23311:
WHL23380:
	local[3]= local[1];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)LESSP(ctx,2,local+3); /*<*/
	if (w==NIL) goto WHX23381;
	local[3]= argv[0]->c.obj.iv[5];
	local[4]= local[0];
	local[5]= argv[2];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)UNIXREAD(ctx,4,local+3); /*unix:uread*/
	local[2] = w;
	local[3]= local[2];
	local[4]= makeint(0);
	ctx->vsp=local+5;
	w=(pointer)LSEQP(ctx,2,local+3); /*<=*/
	if (w==NIL) goto IF23406;
	local[3]= fqv[25];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
	goto IF23407;
IF23406:
	local[3]= NIL;
IF23407:
	local[3]= local[1];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[1] = w;
	goto WHL23380;
WHX23381:
	local[3]= NIL;
BLK23382:
	w = local[0];
	local[0]= w;
BLK23256:
	ctx->vsp=local; return(local[0]);}

/*:read-bytes-eof*/
static pointer M23432file_stream_read_bytes_eof(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= fqv[20];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[1] = w;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[21]); /*plusp*/
	if (w==NIL) goto IF23456;
	local[2]= argv[0];
	local[3]= fqv[22];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[0] = w;
	local[2]= argv[0];
	local[3]= fqv[26];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	goto IF23457;
IF23456:
	local[2]= NIL;
IF23457:
WHL23495:
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)UNIXREAD(ctx,2,local+2); /*unix:uread*/
	local[1] = w;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[21]); /*plusp*/
	if (w==NIL) goto WHX23496;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= makeint(0);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SUBSEQ(ctx,3,local+2); /*subseq*/
	local[2]= w;
	w = local[0];
	ctx->vsp=local+3;
	local[0] = cons(ctx,local[2],w);
	goto WHL23495;
WHX23496:
	local[2]= NIL;
BLK23497:
	local[2]= (pointer)get_sym_func(fqv[27]);
	local[3]= loadglobal(fqv[9]);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)NREVERSE(ctx,1,local+4); /*nreverse*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,3,local+2); /*apply*/
	local[0]= w;
BLK23433:
	ctx->vsp=local; return(local[0]);}

/*make-two-way-stream*/
static pointer F22099make_two_way_stream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[28]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[18];
	local[3]= argv[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK23540:
	ctx->vsp=local; return(local[0]);}

/*make-msgq-input-stream*/
static pointer F22102make_msgq_input_stream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT23584;}
	local[0]= makeint(128);
ENT23584:
ENT23583:
	if (n>2) maerror();
	local[1]= loadglobal(fqv[29]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[18];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)MSGGET(ctx,1,local+4); /*unix:msgget*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[11];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK23581:
	ctx->vsp=local; return(local[0]);}

/*make-msgq-output-stream*/
static pointer F22105make_msgq_output_stream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT23635;}
	local[0]= makeint(128);
ENT23635:
ENT23634:
	if (n>2) maerror();
	local[1]= loadglobal(fqv[29]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[18];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)MSGGET(ctx,1,local+4); /*unix:msgget*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[12];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK23632:
	ctx->vsp=local; return(local[0]);}

/*make-string-input-stream*/
static pointer F22109make_string_input_stream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT23687;}
	local[0]= NIL;
ENT23687:
	if (n>=3) { local[1]=(argv[2]); goto ENT23686;}
	local[1]= NIL;
ENT23686:
ENT23685:
	if (n>3) maerror();
	w = argv[0];
	if (isstring(w)) goto IF23705;
	local[2]= fqv[30];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,1,local+2); /*error*/
	local[2]= w;
	goto IF23706;
IF23705:
	local[2]= NIL;
IF23706:
	local[2]= loadglobal(fqv[31]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[18];
	local[5]= fqv[11];
	local[6]= argv[0];
	local[7]= local[0];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	w = local[2];
	argv[0] = w;
	w = argv[0];
	local[0]= w;
BLK23683:
	ctx->vsp=local; return(local[0]);}

/*make-string-output-stream*/
static pointer F22112make_string_output_stream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT23759;}
	local[0]= makeint(64);
ENT23759:
	if (n>=2) { local[1]=(argv[1]); goto ENT23758;}
	local[1]= NIL;
ENT23758:
	if (n>=3) { local[2]=(argv[2]); goto ENT23757;}
	local[2]= NIL;
ENT23757:
ENT23756:
	if (n>3) maerror();
	local[3]= loadglobal(fqv[31]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[18];
	local[6]= fqv[12];
	local[7]= local[0];
	local[8]= local[1];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,6,local+4); /*send*/
	w = local[3];
	local[0] = w;
	w = local[0];
	local[0]= w;
BLK23754:
	ctx->vsp=local; return(local[0]);}

/*with-input-from-string*/
static pointer F23818(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST23821:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[32];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[33];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= fqv[34];
	local[6]= fqv[35];
	local[7]= fqv[36];
	local[8]= fqv[37];
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[38];
	local[8]= fqv[35];
	local[9]= fqv[36];
	local[10]= fqv[37];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
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
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[39];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[34];
	local[7]= fqv[35];
	local[8]= fqv[40];
	local[9]= fqv[37];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[38];
	local[9]= fqv[35];
	local[10]= fqv[40];
	local[11]= fqv[37];
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[39];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	w = local[0];
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK23819:
	ctx->vsp=local; return(local[0]);}

/*with-output-to-string*/
static pointer F23986(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST23989:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[32];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[41];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	local[3]= local[0];
	local[4]= fqv[42];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)APPEND(ctx,2,local+3); /*append*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK23987:
	ctx->vsp=local; return(local[0]);}

/*get-output-stream-string*/
static pointer F22117get_output_stream_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= makeint(0);
	local[2]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+3;
	w=(pointer)SUBSEQ(ctx,3,local+0); /*subseq*/
	local[0]= w;
BLK24047:
	ctx->vsp=local; return(local[0]);}

/*read-from-string*/
static pointer F22120read_from_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT24075;}
	local[0]= T;
ENT24075:
	if (n>=3) { local[1]=(argv[2]); goto ENT24074;}
	local[1]= NIL;
ENT24074:
ENT24073:
	if (n>3) maerror();
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)F22109make_string_input_stream(ctx,1,local+2); /*make-string-input-stream*/
	local[2]= w;
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)READ(ctx,3,local+2); /*read*/
	local[0]= w;
BLK24071:
	ctx->vsp=local; return(local[0]);}

/*princ-to-string*/
static pointer F22123princ_to_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT24105;}
	local[0]= makeint(16);
ENT24105:
ENT24104:
	if (n>2) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F22112make_string_output_stream(ctx,1,local+1); /*make-string-output-stream*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)PRINC(ctx,2,local+2); /*princ*/
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)F22117get_output_stream_string(ctx,1,local+2); /*get-output-stream-string*/
	local[0]= w;
BLK24102:
	ctx->vsp=local; return(local[0]);}

/*prin1-to-string*/
static pointer F22126prin1_to_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT24146;}
	local[0]= makeint(16);
ENT24146:
ENT24145:
	if (n>2) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F22112make_string_output_stream(ctx,1,local+1); /*make-string-output-stream*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)PRIN1(ctx,2,local+2); /*prin1*/
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)F22117get_output_stream_string(ctx,1,local+2); /*get-output-stream-string*/
	local[0]= w;
BLK24143:
	ctx->vsp=local; return(local[0]);}

/*:domain*/
static pointer M24197socket_address_domain(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= makeint(0);
	local[2]= fqv[43];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK24198:
	ctx->vsp=local; return(local[0]);}

/*:port*/
static pointer M24216socket_address_port(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= makeint(2);
	local[2]= fqv[43];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[5])(ctx,1,local+0,&ftab[5],fqv[44]); /*unix::ntohs*/
	local[0]= w;
BLK24217:
	ctx->vsp=local; return(local[0]);}

/*:host*/
static pointer M24238socket_address_host(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= makeint(4);
	local[2]= makeint(8);
	ctx->vsp=local+3;
	w=(pointer)SUBSEQ(ctx,3,local+0); /*subseq*/
	local[0]= w;
BLK24239:
	ctx->vsp=local; return(local[0]);}

/*:next-port*/
static pointer M24255socket_address_next_port(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[45];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[6])(ctx,1,local+0,&ftab[6],fqv[46]); /*unix::htons*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= makeint(2);
	local[3]= fqv[43];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK24256:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M24284socket_address_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT24288;}
	local[0]= T;
ENT24288:
ENT24287:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[15]));
	local[3]= fqv[16];
	local[4]= local[0];
	local[5]= NIL;
	local[6]= fqv[47];
	local[7]= argv[0];
	{ register eusinteger_t i=intval(makeint(4));
	  w=makeint(local[7]->c.str.chars[i]);}
	local[7]= w;
	local[8]= argv[0];
	{ register eusinteger_t i=intval(makeint(5));
	  w=makeint(local[8]->c.str.chars[i]);}
	local[8]= w;
	local[9]= argv[0];
	{ register eusinteger_t i=intval(makeint(6));
	  w=makeint(local[9]->c.str.chars[i]);}
	local[9]= w;
	local[10]= argv[0];
	{ register eusinteger_t i=intval(makeint(7));
	  w=makeint(local[10]->c.str.chars[i]);}
	local[10]= w;
	local[11]= argv[0];
	local[12]= fqv[45];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,7,local+5); /*format*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	local[0]= w;
BLK24285:
	ctx->vsp=local; return(local[0]);}

/*make-socket-address*/
static pointer F22135make_socket_address(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[48], &argv[0], n-0, local+0, 0);
	if (n & (1<<0)) goto KEY24351;
	local[0] = makeint(2);
KEY24351:
	if (n & (1<<1)) goto KEY24356;
	local[1] = NIL;
KEY24356:
	if (n & (1<<2)) goto KEY24361;
	local[2] = fqv[49];
KEY24361:
	if (n & (1<<3)) goto KEY24366;
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)GETSERVBYNAME(ctx,1,local+6); /*unix:getservbyname*/
	local[3] = w;
KEY24366:
	if (n & (1<<4)) goto KEY24374;
	local[6]= fqv[50];
	ctx->vsp=local+7;
	w=(pointer)GETENV(ctx,1,local+6); /*unix:getenv*/
	local[4] = w;
KEY24374:
	if (n & (1<<5)) goto KEY24381;
	local[5] = NIL;
KEY24381:
	local[6]= local[0];
	if (makeint(1)!=local[6]) goto CON24392;
	local[6]= loadglobal(fqv[51]);
	local[7]= makeint(16);
	local[8]= makeint(2);
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[8]= (pointer)((eusinteger_t)local[8] + (eusinteger_t)w);
	ctx->vsp=local+9;
	w=(pointer)MAX(ctx,2,local+7); /*max*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,2,local+6); /*instantiate*/
	local[6]= w;
	local[7]= local[6];
	local[8]= local[1];
	local[9]= fqv[52];
	local[10]= makeint(2);
	ctx->vsp=local+11;
	w=(*ftab[4])(ctx,4,local+7,&ftab[4],fqv[24]); /*replace*/
	local[7]= local[0];
	local[8]= local[6];
	local[9]= makeint(0);
	local[10]= fqv[43];
	ctx->vsp=local+11;
	w=(pointer)POKE(ctx,4,local+7); /*system:poke*/
	w = local[6];
	local[6]= w;
	goto CON24390;
CON24392:
	local[6]= local[0];
	if (makeint(2)!=local[6]) goto CON24437;
	local[6]= loadglobal(fqv[51]);
	local[7]= makeint(16);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,2,local+6); /*instantiate*/
	local[6]= w;
	local[7]= local[0];
	local[8]= local[6];
	local[9]= makeint(0);
	local[10]= fqv[43];
	ctx->vsp=local+11;
	w=(pointer)POKE(ctx,4,local+7); /*system:poke*/
	if (local[4]==NIL) goto IF24464;
	local[7]= local[4];
	if (fqv[53]!=local[7]) goto IF24473;
	local[7]= makeint(0);
	local[8]= makeint(0);
	local[9]= makeint(0);
	local[10]= makeint(0);
	ctx->vsp=local+11;
	w=(pointer)MKINTVECTOR(ctx,4,local+7); /*integer-vector*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[4] = w;
	local[7]= local[4];
	goto IF24474;
IF24473:
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)GETHOSTBYNAME(ctx,1,local+7); /*unix:gethostbyname*/
	local[4] = w;
	local[7]= local[4];
IF24474:
	w = local[4];
	if (!isnum(w)) goto IF24499;
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,1,local+7); /*-*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SYSERRLIST(ctx,1,local+7); /*unix:syserrlist*/
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK24339;
	goto IF24500;
IF24499:
	local[7]= NIL;
IF24500:
	local[7]= local[6];
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= fqv[52];
	local[10]= makeint(4);
	ctx->vsp=local+11;
	w=(*ftab[4])(ctx,4,local+7,&ftab[4],fqv[24]); /*replace*/
	local[7]= w;
	goto IF24465;
IF24464:
	local[7]= NIL;
IF24465:
	if (local[2]==NIL) goto IF24527;
	local[7]= local[2];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)GETSERVBYNAME(ctx,2,local+7); /*unix:getservbyname*/
	local[2] = w;
	w = local[2];
	if (!isnum(w)) goto IF24546;
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,1,local+7); /*-*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SYSERRLIST(ctx,1,local+7); /*unix:syserrlist*/
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK24339;
	goto IF24547;
IF24546:
	local[7]= NIL;
IF24547:
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= local[6];
	local[9]= makeint(2);
	local[10]= fqv[43];
	ctx->vsp=local+11;
	w=(pointer)POKE(ctx,4,local+7); /*system:poke*/
	local[7]= w;
	goto IF24528;
IF24527:
	local[7]= NIL;
IF24528:
	if (local[3]==NIL) goto IF24574;
	w = local[3];
	if (!isstring(w)) goto IF24583;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)GETSERVBYNAME(ctx,1,local+7); /*unix:getservbyname*/
	local[3] = w;
	local[7]= local[3];
	goto IF24584;
IF24583:
	local[7]= NIL;
IF24584:
	w = local[3];
	if (!isint(w)) goto IF24598;
	local[7]= local[3];
	local[8]= makeint(0);
	ctx->vsp=local+9;
	w=(pointer)GREQP(ctx,2,local+7); /*>=*/
	if (w==NIL) goto IF24598;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(*ftab[6])(ctx,1,local+7,&ftab[6],fqv[46]); /*unix::htons*/
	local[7]= w;
	local[8]= local[6];
	local[9]= makeint(2);
	local[10]= fqv[43];
	ctx->vsp=local+11;
	w=(pointer)POKE(ctx,4,local+7); /*system:poke*/
	local[7]= w;
	goto IF24599;
IF24598:
	local[7]= NIL;
IF24599:
	goto IF24575;
IF24574:
	local[7]= NIL;
IF24575:
	w = local[6];
	local[6]= w;
	goto CON24390;
CON24437:
	local[6]= NIL;
CON24390:
	w = local[6];
	local[0]= w;
BLK24339:
	ctx->vsp=local; return(local[0]);}

/*:domain*/
static pointer M24638socket_port_domain(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= makeint(0);
	local[2]= fqv[43];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK24639:
	ctx->vsp=local; return(local[0]);}

/*:address*/
static pointer M24657socket_port_address(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK24658:
	ctx->vsp=local; return(local[0]);}

/*:id*/
static pointer M24673socket_port_id(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[0];
	local[0]= w;
BLK24674:
	ctx->vsp=local; return(local[0]);}

/*:fd*/
static pointer M24689socket_port_fd(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[0];
	local[0]= w;
BLK24690:
	ctx->vsp=local; return(local[0]);}

/*:infd*/
static pointer M24705socket_port_infd(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[0];
	local[0]= w;
BLK24706:
	ctx->vsp=local; return(local[0]);}

/*:listen*/
static pointer M24721socket_port_listen(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT24725;}
	local[0]= makeint(3);
ENT24725:
ENT24724:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)LISTEN(ctx,2,local+1); /*unix:listen*/
	local[0]= w;
BLK24722:
	ctx->vsp=local; return(local[0]);}

/*:accept*/
static pointer M24746socket_port_accept(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+1;
	w=(pointer)ACCEPT(ctx,1,local+0); /*unix:accept*/
	local[0]= w;
BLK24747:
	ctx->vsp=local; return(local[0]);}

/*:flag*/
static pointer M24763socket_port_flag(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= makeint(3);
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= w;
BLK24764:
	ctx->vsp=local; return(local[0]);}

/*:async*/
static pointer M24780socket_port_async(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[2]==NIL) goto CON24797;
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= makeint(4);
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= makeint(8192);
	ctx->vsp=local+4;
	w=(pointer)LOGIOR(ctx,2,local+2); /*logior*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= makeint(8);
	ctx->vsp=local+2;
	w=(pointer)GETPID(ctx,0,local+2); /*unix:getpid*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= w;
	goto CON24795;
CON24797:
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= makeint(4);
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= makeint(8192);
	ctx->vsp=local+4;
	w=(pointer)LOGNOT(ctx,1,local+3); /*lognot*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LOGAND(ctx,2,local+2); /*logand*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= w;
	goto CON24795;
CON24823:
	local[0]= NIL;
CON24795:
	w = local[0];
	local[0]= w;
BLK24781:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M24842socket_port_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[1] = argv[2];
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[54];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= makeint(1);
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)SOCKET(ctx,3,local+1); /*unix:socket*/
	argv[0]->c.obj.iv[0] = w;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto IF24886;
	w = argv[0]->c.obj.iv[0];
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK24843;
	goto IF24887;
IF24886:
	local[1]= NIL;
IF24887:
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)BIND(ctx,2,local+1); /*unix:bind*/
	local[0] = w;
	local[1]= local[0];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto CON24909;
	local[1]= fqv[55];
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,1,local+1,&ftab[7],fqv[56]); /*unix:perror*/
	local[1]= local[0];
	goto CON24907;
CON24909:
	local[1]= argv[0];
	local[2]= fqv[57];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[0] = w;
	local[1]= local[0];
	local[2]= makeint(0);
	ctx->vsp=local+3;
	w=(pointer)NUMEQUAL(ctx,2,local+1); /*=*/
	if (w==NIL) goto IF24934;
	local[1]= argv[0];
	goto IF24935;
IF24934:
	local[1]= local[0];
IF24935:
	goto CON24907;
CON24919:
	local[1]= NIL;
CON24907:
	w = local[1];
	local[0]= w;
BLK24843:
	ctx->vsp=local; return(local[0]);}

/*make-socket-port*/
static pointer F22144make_socket_port(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[58]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= fqv[18];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK24946:
	ctx->vsp=local; return(local[0]);}

/*:domain*/
static pointer M24987socket_stream_domain(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= makeint(0);
	local[2]= fqv[43];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK24988:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M25006socket_stream_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT25010;}
	local[0]= makeint(128);
ENT25010:
ENT25009:
	if (n>5) maerror();
	argv[0]->c.obj.iv[4] = argv[2];
	local[1]= loadglobal(fqv[29]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[18];
	local[4]= argv[2];
	local[5]= fqv[59];
	local[6]= fqv[11];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	w = local[1];
	argv[0]->c.obj.iv[1] = w;
	local[1]= loadglobal(fqv[29]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[18];
	local[4]= argv[2];
	local[5]= fqv[60];
	local[6]= fqv[12];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	w = local[1];
	argv[0]->c.obj.iv[2] = w;
	argv[0]->c.obj.iv[3] = argv[3];
	w = argv[0];
	local[0]= w;
BLK25007:
	ctx->vsp=local; return(local[0]);}

/*make-server-socket-stream*/
static pointer F22152make_server_socket_stream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT25116;}
	local[0]= makeint(512);
ENT25116:
ENT25115:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= fqv[61];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[1] = w;
	w = local[1];
	if (!isnum(w)) goto IF25149;
	local[2]= local[1];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto IF25149;
	w = local[1];
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK25113;
	goto IF25150;
IF25149:
	local[2]= NIL;
IF25150:
	local[2]= loadglobal(fqv[62]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[18];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= argv[0];
	local[7]= fqv[63];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,5,local+3); /*send*/
	w = local[2];
	local[0]= w;
BLK25113:
	ctx->vsp=local; return(local[0]);}

/*connect-sigalarm-handler*/
static pointer F22156connect_sigalarm_handler(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[64];
	local[1]= loadglobal(fqv[65]);
	ctx->vsp=local+2;
	w=(*ftab[8])(ctx,2,local+0,&ftab[8],fqv[66]); /*warn*/
	local[0]= w;
BLK25205:
	ctx->vsp=local; return(local[0]);}

/*make-client-socket-stream*/
static pointer F22159make_client_socket_stream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT25228;}
	local[0]= makeint(5);
ENT25228:
	if (n>=3) { local[1]=(argv[2]); goto ENT25227;}
	local[1]= makeint(512);
ENT25227:
ENT25226:
	if (n>3) maerror();
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0];
	local[5]= fqv[54];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= makeint(1);
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)SOCKET(ctx,3,local+4); /*unix:socket*/
	local[2] = w;
	local[4]= local[2];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,2,local+4); /*<*/
	if (w==NIL) goto IF25270;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)UNIXCLOSE(ctx,1,local+4); /*unix:uclose*/
	w = local[2];
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK25224;
	goto IF25271;
IF25270:
	local[4]= NIL;
IF25271:
	local[4]= makeint(14);
	local[5]= fqv[67];
	ctx->vsp=local+6;
	w=(pointer)SIGNAL(ctx,2,local+4); /*unix:signal*/
	local[4]= w;
	storeglobal(fqv[68],w);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)ALARM(ctx,1,local+4); /*unix:alarm*/
	ctx->vsp=local+4;
	w = makeclosure(codevec,quotevec,UWP25302,env,argv,local);
	local[4]=(pointer)(ctx->protfp); local[5]=w;
	ctx->protfp=(struct protectframe *)(local+4);
	local[6]= local[2];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)CONNECT(ctx,2,local+6); /*unix:connect*/
	local[3] = w;
	w = local[3];
	ctx->vsp=local+6;
	UWP25302(ctx,0,local+6,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[4]= local[3];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,2,local+4); /*<*/
	if (w==NIL) goto IF25319;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)UNIXCLOSE(ctx,1,local+4); /*unix:uclose*/
	w = local[3];
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK25224;
	goto IF25320;
IF25319:
	local[4]= NIL;
IF25320:
	local[4]= loadglobal(fqv[62]);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= local[4];
	local[6]= fqv[18];
	local[7]= local[2];
	local[8]= argv[0];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	w = local[4];
	local[0]= w;
BLK25224:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP25302(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= makeint(0);
	ctx->vsp=local+1;
	w=(pointer)ALARM(ctx,1,local+0); /*unix:alarm*/
	local[0]= makeint(14);
	local[1]= loadglobal(fqv[68]);
	ctx->vsp=local+2;
	w=(pointer)SIGNAL(ctx,2,local+0); /*unix:signal*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*make-dgram-socket*/
static pointer F22162make_dgram_socket(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[54];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= makeint(2);
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)SOCKET(ctx,3,local+1); /*unix:socket*/
	local[0] = w;
	local[1]= local[0];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)BIND(ctx,2,local+1); /*unix:bind*/
	w = local[0];
	local[0]= w;
BLK25384:
	ctx->vsp=local; return(local[0]);}

/*connect-server*/
static pointer F22165connect_server(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT25429;}
	local[0]= makeint(5);
ENT25429:
ENT25428:
	if (n>3) maerror();
	local[1]= fqv[54];
	local[2]= makeint(2);
	local[3]= fqv[69];
	local[4]= argv[0];
	local[5]= fqv[45];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)F22135make_socket_address(ctx,6,local+1); /*make-socket-address*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F22159make_client_socket_stream(ctx,2,local+1); /*make-client-socket-stream*/
	local[0]= w;
BLK25426:
	ctx->vsp=local; return(local[0]);}

/*select-stream*/
static pointer F22169select_stream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT25466;}
	local[0]= makeflt(0.00000000e+00);
ENT25466:
ENT25465:
	if (n>2) maerror();
	local[1]= makeint(0);
	local[2]= NIL;
	local[3]= makeint(0);
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[0];
WHL25516:
	if (local[6]==NIL) goto WHX25517;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	w = local[5];
	if (!isint(w)) goto CON25569;
	local[7]= local[5];
	goto CON25567;
CON25569:
	local[7]= local[5];
	local[8]= fqv[2];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	goto CON25567;
CON25575:
	local[7]= NIL;
CON25567:
	local[4] = local[7];
	local[7]= makeint(1);
	local[8]= local[1];
	local[9]= local[4];
	local[10]= makeint(1);
	ctx->vsp=local+11;
	w=(pointer)DPB(ctx,4,local+7); /*dpb*/
	local[1] = w;
	local[7]= loadglobal(fqv[70]);
	local[8]= local[4];
	w = local[5];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[8]); v=local[7];
	  v->c.vec.v[i]=w;}
	goto WHL25516;
WHX25517:
	local[7]= NIL;
BLK25518:
	w = NIL;
	local[5]= local[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SELECT_READ(ctx,2,local+5); /*unix:select-read-fd*/
	local[1] = w;
WHL25618:
	local[5]= local[1];
	local[6]= makeint(0);
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto WHX25619;
	local[5]= local[1];
	local[6]= makeint(1);
	ctx->vsp=local+7;
	w=(pointer)LOGTEST(ctx,2,local+5); /*logtest*/
	if (w==NIL) goto IF25626;
	local[5]= loadglobal(fqv[70]);
	{ register eusinteger_t i=intval(local[3]);
	  w=(local[5]->c.vec.v[i]);}
	local[5]= w;
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[2];
	goto IF25627;
IF25626:
	local[5]= NIL;
IF25627:
	local[5]= local[1];
	local[6]= makeint(-1);
	ctx->vsp=local+7;
	w=(pointer)ASH(ctx,2,local+5); /*ash*/
	local[1] = w;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL25618;
WHX25619:
	local[5]= NIL;
BLK25620:
	w = local[2];
	local[0]= w;
BLK25463:
	ctx->vsp=local; return(local[0]);}

/*sigio-handler*/
static pointer F22174sigio_handler(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= loadglobal(fqv[71]);
	ctx->vsp=local+2;
	w=(pointer)F22169select_stream(ctx,1,local+1); /*select-stream*/
	local[1]= w;
WHL25710:
	if (local[1]==NIL) goto WHX25711;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= loadglobal(fqv[72]);
	w = local[0];
	if (!isint(w)) goto IF25763;
	local[3]= local[0];
	goto IF25764;
IF25763:
	local[3]= local[0];
	local[4]= fqv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
IF25764:
	{ register eusinteger_t i=intval(local[3]);
	  w=(local[2]->c.vec.v[i]);}
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)FUNCALL(ctx,2,local+2); /*funcall*/
	goto WHL25710;
WHX25711:
	local[2]= NIL;
BLK25712:
	w = NIL;
	local[0]= w;
BLK25678:
	ctx->vsp=local; return(local[0]);}

/*def-async*/
static pointer F25783(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST25787:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= NIL;
	local[2]= NIL;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto CON25804;
	ctx->vsp=local+3;
	w=(pointer)GENSYM(ctx,0,local+3); /*gensym*/
	local[2] = w;
	local[3]= fqv[73];
	local[4]= local[2];
	w = local[0];
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	local[3]= local[0];
	goto CON25802;
CON25804:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	local[0] = NIL;
	local[3]= local[0];
	goto CON25802;
CON25836:
	local[3]= NIL;
CON25802:
	local[3]= fqv[74];
	local[4]= fqv[75];
	local[5]= argv[0];
	local[6]= fqv[71];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[76];
	local[6]= fqv[77];
	local[7]= fqv[37];
	local[8]= fqv[78];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[34];
	local[7]= fqv[79];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[74];
	local[9]= fqv[80];
	local[10]= argv[0];
	local[11]= fqv[81];
	local[12]= fqv[82];
	local[13]= fqv[80];
	local[14]= argv[0];
	local[15]= fqv[83];
	local[16]= fqv[84];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	local[14]= fqv[85];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[80];
	local[11]= argv[0];
	local[12]= fqv[86];
	local[13]= fqv[87];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
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
	local[9]= fqv[4];
	local[10]= argv[0];
	local[11]= fqv[6];
	local[12]= fqv[88];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[89];
	local[8]= fqv[90];
	local[9]= fqv[72];
	local[10]= fqv[34];
	local[11]= fqv[79];
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= argv[0];
	local[13]= fqv[4];
	local[14]= argv[0];
	local[15]= fqv[2];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
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
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	local[0]= w;
BLK25785:
	ctx->vsp=local; return(local[0]);}

/*:destinations*/
static pointer M26088broadcast_stream_destinations(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT26092;}
	local[0]= NIL;
ENT26092:
ENT26091:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF26108;
	local[1]= local[0];
	w = argv[0]->c.obj.iv[5];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[5] = cons(ctx,local[1],w);
	local[1]= argv[0]->c.obj.iv[5];
	goto IF26109;
IF26108:
	local[1]= NIL;
IF26109:
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK26089:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M26129broadcast_stream_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[15]));
	local[2]= fqv[18];
	local[3]= fqv[12];
	local[4]= makeint(256);
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,5,local+0); /*send-message*/
	argv[0]->c.obj.iv[5] = argv[2];
	w = argv[0];
	local[0]= w;
BLK26130:
	ctx->vsp=local; return(local[0]);}

/*:flush*/
static pointer M26165broadcast_stream_flush(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto IF26182;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= makeint(0);
	local[4]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+5;
	w=(pointer)SUBSEQ(ctx,3,local+2); /*subseq*/
	local[1] = w;
	local[2]= local[1];
	goto IF26183;
IF26182:
	local[1] = argv[0]->c.obj.iv[2];
	local[2]= local[1];
IF26183:
	argv[0]->c.obj.iv[3] = makeint(0);
	local[2]= NIL;
	local[3]= argv[0]->c.obj.iv[5];
WHL26230:
	if (local[3]==NIL) goto WHX26231;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[1];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)PRINC(ctx,2,local+4); /*princ*/
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)FINOUT(ctx,1,local+4); /*finish-output*/
	goto WHL26230;
WHX26231:
	local[4]= NIL;
BLK26232:
	w = NIL;
	w = T;
	local[0]= w;
BLK26166:
	ctx->vsp=local; return(local[0]);}

/*:close*/
static pointer M26293broadcast_stream_close(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[5];
WHL26323:
	if (local[1]==NIL) goto WHX26324;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)CLOSE(ctx,1,local+2); /*close*/
	goto WHL26323;
WHX26324:
	local[2]= NIL;
BLK26325:
	w = NIL;
	local[0]= w;
BLK26294:
	ctx->vsp=local; return(local[0]);}

/*make-broadcast-stream*/
static pointer F22183make_broadcast_stream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST26383:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= local[0];
WHL26413:
	if (local[4]==NIL) goto WHX26414;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)STREAMP(ctx,1,local+5); /*streamp*/
	if (w==NIL) goto IF26462;
	local[5]= local[3];
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[2];
	goto IF26463;
IF26462:
	local[5]= local[3];
	local[6]= fqv[91];
	local[7]= fqv[12];
	ctx->vsp=local+8;
	w=(*ftab[9])(ctx,3,local+5,&ftab[9],fqv[92]); /*open*/
	local[5]= w;
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[2];
IF26463:
	goto WHL26413;
WHX26414:
	local[5]= NIL;
BLK26415:
	w = NIL;
	local[3]= loadglobal(fqv[93]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[18];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	w = local[3];
	local[0]= w;
BLK26381:
	ctx->vsp=local; return(local[0]);}

/*read-buffer*/
static pointer F22186read_buffer(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT26534;}
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
ENT26534:
ENT26533:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[91];
	local[3]= fqv[11];
	ctx->vsp=local+4;
	w=(*ftab[9])(ctx,3,local+1,&ftab[9],fqv[92]); /*open*/
	local[1]= w;
	ctx->vsp=local+2;
	w = makeclosure(codevec,quotevec,UWP26571,env,argv,local);
	local[2]=(pointer)(ctx->protfp); local[3]=w;
	ctx->protfp=(struct protectframe *)(local+2);
	local[4]= makeint(0);
WHL26588:
	local[5]= local[4];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)LESSP(ctx,2,local+5); /*<*/
	if (w==NIL) goto WHX26589;
	local[5]= local[4];
	local[6]= local[1];
	local[7]= fqv[94];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= argv[1];
	local[8]= local[0];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)UNIXREAD(ctx,4,local+6); /*unix:uread*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[4] = w;
	goto WHL26588;
WHX26589:
	local[5]= NIL;
BLK26590:
	w = local[5];
	w = argv[1];
	ctx->vsp=local+4;
	UWP26571(ctx,0,local+4,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK26531:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP26571(ctx,n,argv,env)
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

/*write-buffer*/
static pointer F22189write_buffer(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT26645;}
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
ENT26645:
ENT26644:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[91];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(*ftab[9])(ctx,3,local+1,&ftab[9],fqv[92]); /*open*/
	local[1]= w;
	ctx->vsp=local+2;
	w = makeclosure(codevec,quotevec,UWP26682,env,argv,local);
	local[2]=(pointer)(ctx->protfp); local[3]=w;
	ctx->protfp=(struct protectframe *)(local+2);
	local[4]= local[1];
	local[5]= argv[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)UNIXWRITE(ctx,3,local+4); /*unix:write*/
	ctx->vsp=local+4;
	UWP26682(ctx,0,local+4,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK26642:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP26682(ctx,n,argv,env)
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

/*:init*/
static pointer M26731port_selector_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST26734:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= loadglobal(fqv[95]);
	local[2]= fqv[96];
	local[3]= fqv[97];
	ctx->vsp=local+4;
	w=(*ftab[10])(ctx,3,local+1,&ftab[10],fqv[98]); /*make-array*/
	argv[0]->c.obj.iv[1] = w;
	local[1]= loadglobal(fqv[95]);
	local[2]= fqv[96];
	local[3]= fqv[97];
	ctx->vsp=local+4;
	w=(*ftab[10])(ctx,3,local+1,&ftab[10],fqv[98]); /*make-array*/
	argv[0]->c.obj.iv[3] = w;
	local[1]= loadglobal(fqv[95]);
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,1,local+1,&ftab[10],fqv[98]); /*make-array*/
	argv[0]->c.obj.iv[2] = w;
	local[1]= NIL;
	local[2]= local[0];
WHL26793:
	if (local[2]==NIL) goto WHX26794;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= (pointer)get_sym_func(fqv[4]);
	local[4]= argv[0];
	local[5]= fqv[99];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.cdr;
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,6,local+3); /*apply*/
	goto WHL26793;
WHX26794:
	local[3]= NIL;
BLK26795:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK26732:
	ctx->vsp=local; return(local[0]);}

/*:get-stream-fd*/
static pointer M26876port_selector_get_stream_fd(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)STREAMP(ctx,1,local+1); /*streamp*/
	if (w==NIL) goto CON26905;
	local[1]= argv[2];
	local[2]= fqv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto CON26903;
CON26905:
	w = argv[2];
	if (!isnum(w)) goto CON26917;
	local[1]= argv[2];
	goto CON26903;
CON26917:
	local[1]= argv[2];
	local[2]= fqv[94];
	ctx->vsp=local+3;
	w=(*ftab[11])(ctx,2,local+1,&ftab[11],fqv[100]); /*find-method*/
	if (w==NIL) goto CON26923;
	local[1]= argv[2];
	local[2]= fqv[94];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto CON26903;
CON26923:
	local[1]= fqv[101];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto CON26903;
CON26938:
	local[1]= NIL;
CON26903:
	local[0] = local[1];
	local[1]= local[0];
	local[2]= loadglobal(fqv[95]);
	ctx->vsp=local+3;
	w=(pointer)GREQP(ctx,2,local+1); /*>=*/
	if (w==NIL) goto IF26947;
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF26948;
IF26947:
	local[1]= NIL;
IF26948:
	w = local[0];
	local[0]= w;
BLK26877:
	ctx->vsp=local; return(local[0]);}

/*:add-port*/
static pointer M26961port_selector_add_port(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
RST26964:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-4);
	local[1]= argv[0];
	local[2]= fqv[103];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[1];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)LIST_STAR(ctx,3,local+4); /*list**/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= local[1];
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[0]= w;
BLK26962:
	ctx->vsp=local; return(local[0]);}

/*:remove-port*/
static pointer M27015port_selector_remove_port(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[103];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= local[0];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,3,local+1); /*aset*/
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= local[0];
	local[3]= makeint(0);
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,3,local+1); /*aset*/
	local[0]= w;
BLK27016:
	ctx->vsp=local; return(local[0]);}

/*:streams*/
static pointer M27059port_selector_streams(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= makeint(0);
	local[2]= loadglobal(fqv[95]);
WHL27104:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX27105;
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	if (w==NIL) goto IF27113;
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	local[3]= local[0];
	goto IF27114;
IF27113:
	local[3]= NIL;
IF27114:
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL27104;
WHX27105:
	local[3]= NIL;
BLK27106:
	w = NIL;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)NREVERSE(ctx,1,local+1); /*nreverse*/
	local[0]= w;
BLK27060:
	ctx->vsp=local; return(local[0]);}

/*:fds*/
static pointer M27154port_selector_fds(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= makeint(0);
	local[2]= loadglobal(fqv[95]);
WHL27199:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX27200;
	local[3]= makeint(1);
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)NUMEQUAL(ctx,2,local+3); /*=*/
	if (w==NIL) goto IF27208;
	local[3]= local[1];
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	local[3]= local[0];
	goto IF27209;
IF27208:
	local[3]= NIL;
IF27209:
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL27199;
WHX27200:
	local[3]= NIL;
BLK27201:
	w = NIL;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)NREVERSE(ctx,1,local+1); /*nreverse*/
	local[0]= w;
BLK27155:
	ctx->vsp=local; return(local[0]);}

/*:select*/
static pointer M27246port_selector_select(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT27250;}
	local[0]= makeflt(1.00000000e-01);
ENT27250:
ENT27249:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,2,local+4,&ftab[4],fqv[24]); /*replace*/
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SELECT(ctx,4,local+4); /*unix:select*/
	local[1] = w;
	local[4]= local[1];
	local[5]= makeint(0);
	ctx->vsp=local+6;
	w=(pointer)GREATERP(ctx,2,local+4); /*>*/
	if (w==NIL) goto IF27294;
	local[4]= makeint(0);
	local[5]= loadglobal(fqv[95]);
WHL27323:
	local[6]= local[4];
	w = local[5];
	if ((eusinteger_t)local[6] >= (eusinteger_t)w) goto WHX27324;
	local[6]= argv[0]->c.obj.iv[3];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= makeint(1);
	ctx->vsp=local+8;
	w=(pointer)NUMEQUAL(ctx,2,local+6); /*=*/
	if (w==NIL) goto IF27333;
	local[6]= argv[0]->c.obj.iv[2];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[2] = w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(*ftab[12])(ctx,1,local+6,&ftab[12],fqv[104]); /*functionp*/
	if (w==NIL) goto IF27373;
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,2,local+6); /*apply*/
	local[6]= w;
	goto IF27374;
IF27373:
	local[6]= (pointer)get_sym_func(fqv[4]);
	local[7]= local[2];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,3,local+6); /*apply*/
	local[6]= w;
IF27374:
	goto IF27334;
IF27333:
	local[6]= NIL;
IF27334:
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[4] = w;
	goto WHL27323;
WHX27324:
	local[6]= NIL;
BLK27325:
	w = T;
	local[4]= w;
	goto IF27295;
IF27294:
	local[4]= NIL;
IF27295:
	w = local[4];
	local[0]= w;
BLK27247:
	ctx->vsp=local; return(local[0]);}

/*:select-loop*/
static pointer M27407port_selector_select_loop(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT27412;}
	local[0]= makeflt(1.00000000e-01);
ENT27412:
	if (n>=4) { local[1]=(argv[3]); goto ENT27411;}
	local[1]= NIL;
ENT27411:
ENT27410:
	ctx->vsp=local+2;
	local[2]= minilist(ctx,&argv[n],n-4);
	{jmp_buf jb;
	w = fqv[105];
	ctx->vsp=local+3;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT27433;}
WHL27440:
	if (T==NIL) goto WHX27441;
	local[9]= argv[0];
	local[10]= fqv[106];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	if (local[1]==NIL) goto IF27454;
	local[9]= local[1];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)APPLY(ctx,2,local+9); /*apply*/
	local[9]= w;
	goto IF27455;
IF27454:
	local[9]= NIL;
IF27455:
	goto WHL27440;
WHX27441:
	local[9]= NIL;
BLK27442:
	w = local[9];
CAT27433:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[0]= w;
BLK27408:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___stream(ctx,n,argv,env)
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
	local[0]= fqv[107];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF27471;
	local[0]= fqv[108];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[109],w);
	goto IF27472;
IF27471:
	local[0]= fqv[110];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF27472:
	local[0]= fqv[111];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22251io_stream_instream,fqv[112],fqv[28],fqv[113]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22290io_stream_outstream,fqv[114],fqv[28],fqv[115]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22329io_stream_infd,fqv[2],fqv[28],fqv[116]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22348io_stream_outfd,fqv[3],fqv[28],fqv[117]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22367io_stream_in,fqv[118],fqv[28],fqv[119]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22391io_stream_out,fqv[120],fqv[28],fqv[121]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22415io_stream_flag,fqv[5],fqv[28],fqv[122]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22434io_stream_async,fqv[6],fqv[28],fqv[123]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22456io_stream_fname,fqv[7],fqv[28],fqv[124]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22475io_stream_init,fqv[18],fqv[28],fqv[125]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22522stream_reset,fqv[10],fqv[31],fqv[126]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22561stream_discard,fqv[26],fqv[31],fqv[127]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22597stream_count,fqv[128],fqv[31],fqv[129]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22613stream_tail,fqv[130],fqv[31],fqv[131]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22651stream_chars_left,fqv[20],fqv[31],fqv[132]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22671stream_tail_string,fqv[22],fqv[31],fqv[133]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22690stream_buffer,fqv[134],fqv[31],fqv[135]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22758stream_init,fqv[18],fqv[31],fqv[136]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[137],module,F22088reset_stream,fqv[138]);
	local[0]= fqv[85];
	local[1]= fqv[139];
	local[2]= makeint(8192);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[83];
	local[1]= fqv[139];
	local[2]= makeint(3);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[81];
	local[1]= fqv[139];
	local[2]= makeint(4);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[86];
	local[1]= fqv[139];
	local[2]= makeint(8);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22876file_stream_fd,fqv[94],fqv[29],fqv[140]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22892file_stream_instream,fqv[112],fqv[29],fqv[141]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22915file_stream_outstream,fqv[114],fqv[29],fqv[142]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22938file_stream_infd,fqv[2],fqv[29],fqv[143]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22961file_stream_outfd,fqv[3],fqv[29],fqv[144]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22984file_stream_fname,fqv[7],fqv[29],fqv[145]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M23000file_stream_flag,fqv[5],fqv[29],fqv[146]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M23017file_stream_async,fqv[6],fqv[29],fqv[147]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M23076file_stream_nonblock,fqv[148],fqv[29],fqv[149]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M23138file_stream_prin1,fqv[16],fqv[29],fqv[150]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M23179file_stream_init,fqv[18],fqv[29],fqv[151]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M23255file_stream_read_bytes,fqv[152],fqv[29],fqv[153]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M23432file_stream_read_bytes_eof,fqv[154],fqv[29],fqv[155]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[156],module,F22099make_two_way_stream,fqv[157]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[158],module,F22102make_msgq_input_stream,fqv[159]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[160],module,F22105make_msgq_output_stream,fqv[161]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[33],module,F22109make_string_input_stream,fqv[162]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[41],module,F22112make_string_output_stream,fqv[163]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[164],module,F23818,fqv[165]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[166],module,F23986,fqv[167]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[42],module,F22117get_output_stream_string,fqv[168]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[169],module,F22120read_from_string,fqv[170]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[171],module,F22123princ_to_string,fqv[172]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[173],module,F22126prin1_to_string,fqv[174]);
	local[0]= fqv[51];
	local[1]= fqv[175];
	local[2]= fqv[51];
	local[3]= fqv[176];
	local[4]= loadglobal(fqv[9]);
	local[5]= fqv[177];
	local[6]= fqv[39];
	local[7]= fqv[178];
	local[8]= NIL;
	local[9]= fqv[96];
	local[10]= fqv[179];
	local[11]= fqv[180];
	local[12]= makeint(-1);
	local[13]= fqv[181];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[13])(ctx,13,local+2,&ftab[13],fqv[182]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24197socket_address_domain,fqv[54],fqv[51],fqv[183]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24216socket_address_port,fqv[45],fqv[51],fqv[184]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24238socket_address_host,fqv[69],fqv[51],fqv[185]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24255socket_address_next_port,fqv[186],fqv[51],fqv[187]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24284socket_address_prin1,fqv[16],fqv[51],fqv[188]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[189],module,F22135make_socket_address,fqv[190]);
	local[0]= fqv[58];
	local[1]= fqv[175];
	local[2]= fqv[58];
	local[3]= fqv[176];
	local[4]= loadglobal(fqv[191]);
	local[5]= fqv[177];
	local[6]= fqv[192];
	local[7]= fqv[178];
	local[8]= NIL;
	local[9]= fqv[96];
	local[10]= NIL;
	local[11]= fqv[180];
	local[12]= makeint(-1);
	local[13]= fqv[181];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[13])(ctx,13,local+2,&ftab[13],fqv[182]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[193];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24638socket_port_domain,fqv[54],fqv[58],fqv[194]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24657socket_port_address,fqv[63],fqv[58],fqv[195]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24673socket_port_id,fqv[196],fqv[58],fqv[197]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24689socket_port_fd,fqv[94],fqv[58],fqv[198]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24705socket_port_infd,fqv[2],fqv[58],fqv[199]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24721socket_port_listen,fqv[57],fqv[58],fqv[200]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24746socket_port_accept,fqv[61],fqv[58],fqv[201]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24763socket_port_flag,fqv[5],fqv[58],fqv[202]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24780socket_port_async,fqv[6],fqv[58],fqv[203]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24842socket_port_init,fqv[18],fqv[58],fqv[204]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[205],module,F22144make_socket_port,fqv[206]);
	local[0]= fqv[62];
	local[1]= fqv[175];
	local[2]= fqv[62];
	local[3]= fqv[176];
	local[4]= loadglobal(fqv[28]);
	local[5]= fqv[177];
	local[6]= fqv[207];
	local[7]= fqv[178];
	local[8]= NIL;
	local[9]= fqv[96];
	local[10]= NIL;
	local[11]= fqv[180];
	local[12]= makeint(-1);
	local[13]= fqv[181];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[13])(ctx,13,local+2,&ftab[13],fqv[182]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24987socket_stream_domain,fqv[54],fqv[62],fqv[208]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M25006socket_stream_init,fqv[18],fqv[62],fqv[209]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[210],module,F22152make_server_socket_stream,fqv[211]);
	local[0]= fqv[68];
	local[1]= fqv[212];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF27744;
	local[0]= fqv[68];
	local[1]= fqv[212];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[68];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF27767;
	local[0]= fqv[68];
	local[1]= fqv[175];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF27768;
IF27767:
	local[0]= NIL;
IF27768:
	local[0]= fqv[68];
	goto IF27745;
IF27744:
	local[0]= NIL;
IF27745:
	ctx->vsp=local+0;
	compfun(ctx,fqv[67],module,F22156connect_sigalarm_handler,fqv[213]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[214],module,F22159make_client_socket_stream,fqv[215]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[216],module,F22162make_dgram_socket,fqv[217]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[218],module,F22165connect_server,fqv[219]);
	local[0]= fqv[70];
	local[1]= fqv[212];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF27795;
	local[0]= fqv[70];
	local[1]= fqv[212];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[70];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF27818;
	local[0]= fqv[70];
	local[1]= fqv[175];
	local[2]= loadglobal(fqv[220]);
	local[3]= makeint(32);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,2,local+2); /*instantiate*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF27819;
IF27818:
	local[0]= NIL;
IF27819:
	local[0]= fqv[70];
	goto IF27796;
IF27795:
	local[0]= NIL;
IF27796:
	ctx->vsp=local+0;
	compfun(ctx,fqv[221],module,F22169select_stream,fqv[222]);
	local[0]= fqv[71];
	local[1]= fqv[212];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF27844;
	local[0]= fqv[71];
	local[1]= fqv[212];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[71];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF27867;
	local[0]= fqv[71];
	local[1]= fqv[175];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF27868;
IF27867:
	local[0]= NIL;
IF27868:
	local[0]= fqv[71];
	goto IF27845;
IF27844:
	local[0]= NIL;
IF27845:
	local[0]= fqv[72];
	local[1]= fqv[212];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF27887;
	local[0]= fqv[72];
	local[1]= fqv[212];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[72];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF27910;
	local[0]= fqv[72];
	local[1]= fqv[175];
	local[2]= loadglobal(fqv[220]);
	local[3]= makeint(32);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,2,local+2); /*instantiate*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF27911;
IF27910:
	local[0]= NIL;
IF27911:
	local[0]= fqv[72];
	goto IF27888;
IF27887:
	local[0]= NIL;
IF27888:
	ctx->vsp=local+0;
	compfun(ctx,fqv[78],module,F22174sigio_handler,fqv[223]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[224],module,F25783,fqv[225]);
	local[0]= fqv[93];
	local[1]= fqv[175];
	local[2]= fqv[93];
	local[3]= fqv[176];
	local[4]= loadglobal(fqv[31]);
	local[5]= fqv[177];
	local[6]= fqv[226];
	local[7]= fqv[178];
	local[8]= NIL;
	local[9]= fqv[96];
	local[10]= NIL;
	local[11]= fqv[180];
	local[12]= makeint(-1);
	local[13]= fqv[181];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[13])(ctx,13,local+2,&ftab[13],fqv[182]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M26088broadcast_stream_destinations,fqv[227],fqv[93],fqv[228]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M26129broadcast_stream_init,fqv[18],fqv[93],fqv[229]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M26165broadcast_stream_flush,fqv[230],fqv[93],fqv[231]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M26293broadcast_stream_close,fqv[232],fqv[93],fqv[233]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[234],module,F22183make_broadcast_stream,fqv[235]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[236],module,F22186read_buffer,fqv[237]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[238],module,F22189write_buffer,fqv[239]);
	local[0]= fqv[95];
	local[1]= fqv[175];
	local[2]= makeint(64);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[240];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[241];
	local[1]= fqv[175];
	local[2]= fqv[241];
	local[3]= fqv[176];
	local[4]= loadglobal(fqv[242]);
	local[5]= fqv[177];
	local[6]= fqv[243];
	local[7]= fqv[178];
	local[8]= NIL;
	local[9]= fqv[96];
	local[10]= NIL;
	local[11]= fqv[180];
	local[12]= makeint(-1);
	local[13]= fqv[181];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[13])(ctx,13,local+2,&ftab[13],fqv[182]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M26731port_selector_init,fqv[18],fqv[241],fqv[244]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M26876port_selector_get_stream_fd,fqv[103],fqv[241],fqv[245]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M26961port_selector_add_port,fqv[99],fqv[241],fqv[246]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M27015port_selector_remove_port,fqv[247],fqv[241],fqv[248]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M27059port_selector_streams,fqv[249],fqv[241],fqv[250]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M27154port_selector_fds,fqv[251],fqv[241],fqv[252]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M27246port_selector_select,fqv[106],fqv[241],fqv[253]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M27407port_selector_select_loop,fqv[105],fqv[241],fqv[254]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<14; i++) ftab[i]=fcallx;
}
