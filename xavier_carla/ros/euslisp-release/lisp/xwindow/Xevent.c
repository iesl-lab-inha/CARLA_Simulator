/* ./Xevent.c :  entry=Xevent */
/* compiled by EusLisp 9.26(65ba2fdb2) for Linux created on yong2-desktop(Wed May 19 05:22:41 KST 2021) */
#include "eus.h"
#include "Xevent.h"
#pragma init (register_Xevent)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___Xevent();
extern pointer build_quote_vector();
static int register_Xevent()
  { add_module_initializer("___Xevent", ___Xevent);}

static pointer F1760xevent_type();
static pointer F1761set_xevent_type();
static pointer F1762xevent_serial();
static pointer F1763set_xevent_serial();
static pointer F1764xevent_send_event();
static pointer F1765set_xevent_send_event();
static pointer F1766xevent_display();
static pointer F1767set_xevent_display();
static pointer F1768xevent_window();
static pointer F1769set_xevent_window();
static pointer F1770xevent_root();
static pointer F1771set_xevent_root();
static pointer F1772xevent_subwindow();
static pointer F1773set_xevent_subwindow();
static pointer F1774xevent_time();
static pointer F1775set_xevent_time();
static pointer F1776xevent_x();
static pointer F1777set_xevent_x();
static pointer F1778xevent_y();
static pointer F1779set_xevent_y();
static pointer F1780xevent_x_root();
static pointer F1781set_xevent_x_root();
static pointer F1782xevent_y_root();
static pointer F1783set_xevent_y_root();
static pointer F1784xevent_state();
static pointer F1785set_xevent_state();
static pointer F1786xevent_detail();
static pointer F1787set_xevent_detail();
static pointer F1788xevent_same_screen();
static pointer F1789set_xevent_same_screen();
static pointer F1790xevent_focus();
static pointer F1791set_xevent_focus();
static pointer F1792xevent_alt_state();
static pointer F1793set_xevent_alt_state();
static pointer F1794xevent_pad();
static pointer F1795set_xevent_pad();
static pointer F1796next_event();
static pointer F1797event_type();
static pointer F1798event_x();
static pointer F1799event_y();
static pointer F1800event_x_root();
static pointer F1801event_y_root();
static pointer F1802event_pos();
static pointer F1803event_key();
static pointer F1804event_root_pos();
static pointer F1805event_width();
static pointer F1806event_height();
static pointer F1807event_time();
static pointer F1808event_window();
static pointer F1809event_button();
static pointer F1810event_state();
static pointer F1811event_shift();
static pointer F1812event_control();
static pointer F1813event_meta();
static pointer F1814event_left();
static pointer F1815event_middle();
static pointer F1816event_right();
static pointer F1817event_pressed();
static pointer F1818print_event();
static pointer F1819display_events();
static pointer F1820process_event();
static pointer F1821window_main_one();
static pointer F1822wmlerror();
static pointer F1823window_main_thread2();
static pointer F1824window_main_thread();
static pointer F1825display_fd();
static pointer F1826repwin();

/*xevent-type*/
static pointer F1760xevent_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(0);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1827:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-type*/
static pointer F1761set_xevent_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(0);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1828:
	ctx->vsp=local; return(local[0]);}

/*xevent-serial*/
static pointer F1762xevent_serial(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(8);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1829:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-serial*/
static pointer F1763set_xevent_serial(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(8);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1830:
	ctx->vsp=local; return(local[0]);}

/*xevent-send-event*/
static pointer F1764xevent_send_event(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(16);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1831:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-send-event*/
static pointer F1765set_xevent_send_event(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(16);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1832:
	ctx->vsp=local; return(local[0]);}

/*xevent-display*/
static pointer F1766xevent_display(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(24);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1833:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-display*/
static pointer F1767set_xevent_display(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(24);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1834:
	ctx->vsp=local; return(local[0]);}

/*xevent-window*/
static pointer F1768xevent_window(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(32);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1835:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-window*/
static pointer F1769set_xevent_window(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(32);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1836:
	ctx->vsp=local; return(local[0]);}

/*xevent-root*/
static pointer F1770xevent_root(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(40);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1837:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-root*/
static pointer F1771set_xevent_root(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(40);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1838:
	ctx->vsp=local; return(local[0]);}

/*xevent-subwindow*/
static pointer F1772xevent_subwindow(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(48);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1839:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-subwindow*/
static pointer F1773set_xevent_subwindow(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(48);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1840:
	ctx->vsp=local; return(local[0]);}

/*xevent-time*/
static pointer F1774xevent_time(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(56);
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1841:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-time*/
static pointer F1775set_xevent_time(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(56);
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1842:
	ctx->vsp=local; return(local[0]);}

/*xevent-x*/
static pointer F1776xevent_x(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(64);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1843:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-x*/
static pointer F1777set_xevent_x(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(64);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1844:
	ctx->vsp=local; return(local[0]);}

/*xevent-y*/
static pointer F1778xevent_y(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(68);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1845:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-y*/
static pointer F1779set_xevent_y(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(68);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1846:
	ctx->vsp=local; return(local[0]);}

/*xevent-x-root*/
static pointer F1780xevent_x_root(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(72);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1847:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-x-root*/
static pointer F1781set_xevent_x_root(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(72);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1848:
	ctx->vsp=local; return(local[0]);}

/*xevent-y-root*/
static pointer F1782xevent_y_root(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(76);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1849:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-y-root*/
static pointer F1783set_xevent_y_root(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(76);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1850:
	ctx->vsp=local; return(local[0]);}

/*xevent-state*/
static pointer F1784xevent_state(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(80);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1851:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-state*/
static pointer F1785set_xevent_state(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(80);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1852:
	ctx->vsp=local; return(local[0]);}

/*xevent-detail*/
static pointer F1786xevent_detail(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(84);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1853:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-detail*/
static pointer F1787set_xevent_detail(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(84);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1854:
	ctx->vsp=local; return(local[0]);}

/*xevent-same-screen*/
static pointer F1788xevent_same_screen(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(88);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1855:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-same-screen*/
static pointer F1789set_xevent_same_screen(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(88);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1856:
	ctx->vsp=local; return(local[0]);}

/*xevent-focus*/
static pointer F1790xevent_focus(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(92);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1857:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-focus*/
static pointer F1791set_xevent_focus(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(92);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1858:
	ctx->vsp=local; return(local[0]);}

/*xevent-alt-state*/
static pointer F1792xevent_alt_state(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint(96);
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK1859:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-alt-state*/
static pointer F1793set_xevent_alt_state(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	local[2]= makeint(96);
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK1860:
	ctx->vsp=local; return(local[0]);}

/*xevent-pad*/
static pointer F1794xevent_pad(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT1863;}
	local[0]= NIL;
ENT1863:
ENT1862:
	if (n>2) maerror();
	if (local[0]==NIL) goto IF1864;
	local[1]= argv[0];
	local[2]= makeint(100);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= fqv[2];
	ctx->vsp=local+4;
	w=(pointer)PEEK(ctx,3,local+1); /*system:peek*/
	local[1]= w;
	goto IF1865;
IF1864:
	local[1]= argv[0];
	local[2]= makeint(100);
	local[3]= makeint(100);
	w = makeint(92);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[3]= (pointer)((eusinteger_t)local[3] + (eusinteger_t)w);
	ctx->vsp=local+4;
	w=(pointer)SUBSEQ(ctx,3,local+1); /*subseq*/
	local[1]= w;
IF1865:
	w = local[1];
	local[0]= w;
BLK1861:
	ctx->vsp=local; return(local[0]);}

/*set-xevent-pad*/
static pointer F1795set_xevent_pad(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1867:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	if (local[0]==NIL) goto IF1868;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= makeint(100);
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	local[3]= fqv[2];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,3,local+1); /*system:poke*/
	local[1]= w;
	goto IF1869;
IF1868:
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= fqv[3];
	local[4]= makeint(100);
	local[5]= fqv[4];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,6,local+1,&ftab[0],fqv[5]); /*replace*/
	local[1]= w;
IF1869:
	w = local[1];
	local[0]= w;
BLK1866:
	ctx->vsp=local; return(local[0]);}

/*next-event*/
static pointer F1796next_event(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= loadglobal(fqv[6]);
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[7]); /*pending*/
	local[0]= w;
	local[1]= makeint(0);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto CON1872;
	local[0]= loadglobal(fqv[6]);
	local[1]= loadglobal(fqv[8]);
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[9]); /*nextevent*/
	local[0]= loadglobal(fqv[8]);
	goto CON1871;
CON1872:
	local[0]= NIL;
CON1871:
	w = local[0];
	local[0]= w;
BLK1870:
	ctx->vsp=local; return(local[0]);}

/*event-type*/
static pointer F1797event_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[10];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F1760xevent_type(ctx,1,local+1); /*xevent-type*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
BLK1873:
	ctx->vsp=local; return(local[0]);}

/*event-x*/
static pointer F1798event_x(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1776xevent_x(ctx,1,local+0); /*xevent-x*/
	local[0]= w;
BLK1874:
	ctx->vsp=local; return(local[0]);}

/*event-y*/
static pointer F1799event_y(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1778xevent_y(ctx,1,local+0); /*xevent-y*/
	local[0]= w;
BLK1875:
	ctx->vsp=local; return(local[0]);}

/*event-x-root*/
static pointer F1800event_x_root(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1780xevent_x_root(ctx,1,local+0); /*xevent-x-root*/
	local[0]= w;
BLK1876:
	ctx->vsp=local; return(local[0]);}

/*event-y-root*/
static pointer F1801event_y_root(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1782xevent_y_root(ctx,1,local+0); /*xevent-y-root*/
	local[0]= w;
BLK1877:
	ctx->vsp=local; return(local[0]);}

/*event-pos*/
static pointer F1802event_pos(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1776xevent_x(ctx,1,local+0); /*xevent-x*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F1778xevent_y(ctx,1,local+1); /*xevent-y*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MKINTVECTOR(ctx,2,local+0); /*integer-vector*/
	local[0]= w;
BLK1878:
	ctx->vsp=local; return(local[0]);}

/*event-key*/
static pointer F1803event_key(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1786xevent_detail(ctx,1,local+0); /*xevent-detail*/
	local[0]= w;
BLK1879:
	ctx->vsp=local; return(local[0]);}

/*event-root-pos*/
static pointer F1804event_root_pos(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1780xevent_x_root(ctx,1,local+0); /*xevent-x-root*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F1782xevent_y_root(ctx,1,local+1); /*xevent-y-root*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MKINTVECTOR(ctx,2,local+0); /*integer-vector*/
	local[0]= w;
BLK1880:
	ctx->vsp=local; return(local[0]);}

/*event-width*/
static pointer F1805event_width(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)ADDRESS(ctx,1,local+0); /*system:address*/
	local[0]= w;
	local[1]= makeint(16);
	local[2]= makeint(4);
	{ eusinteger_t i,j;
		j=intval(makeint(14)); i=intval(local[2]);
		local[2]=(makeint(i * j));}
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,3,local+0); /*+*/
	local[0]= w;
	local[1]= fqv[0];
	ctx->vsp=local+2;
	w=(pointer)PEEK(ctx,2,local+0); /*system:peek*/
	local[0]= w;
BLK1881:
	ctx->vsp=local; return(local[0]);}

/*event-height*/
static pointer F1806event_height(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)ADDRESS(ctx,1,local+0); /*system:address*/
	local[0]= w;
	local[1]= makeint(16);
	local[2]= makeint(4);
	{ eusinteger_t i,j;
		j=intval(makeint(15)); i=intval(local[2]);
		local[2]=(makeint(i * j));}
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,3,local+0); /*+*/
	local[0]= w;
	local[1]= fqv[0];
	ctx->vsp=local+2;
	w=(pointer)PEEK(ctx,2,local+0); /*system:peek*/
	local[0]= w;
BLK1882:
	ctx->vsp=local; return(local[0]);}

/*event-time*/
static pointer F1807event_time(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1774xevent_time(ctx,1,local+0); /*xevent-time*/
	local[0]= w;
BLK1883:
	ctx->vsp=local; return(local[0]);}

/*event-window*/
static pointer F1808event_window(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1768xevent_window(ctx,1,local+0); /*xevent-window*/
	local[0]= w;
	local[1]= loadglobal(fqv[11]);
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,2,local+0,&ftab[3],fqv[12]); /*gethash*/
	local[0]= w;
BLK1884:
	ctx->vsp=local; return(local[0]);}

/*event-button*/
static pointer F1809event_button(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1786xevent_detail(ctx,1,local+0); /*xevent-detail*/
	local[0]= w;
BLK1885:
	ctx->vsp=local; return(local[0]);}

/*event-state*/
static pointer F1810event_state(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1784xevent_state(ctx,1,local+0); /*xevent-state*/
	local[0]= w;
	local[1]= NIL;
	local[2]= local[0];
	local[3]= makeint(3);
	ctx->vsp=local+4;
	w=(pointer)LOGTEST(ctx,2,local+2); /*logtest*/
	if (w==NIL) goto IF1887;
	local[2]= fqv[13];
	w = local[1];
	ctx->vsp=local+3;
	local[1] = cons(ctx,local[2],w);
	local[2]= local[1];
	goto IF1888;
IF1887:
	local[2]= NIL;
IF1888:
	local[2]= local[0];
	local[3]= makeint(4);
	ctx->vsp=local+4;
	w=(pointer)LOGTEST(ctx,2,local+2); /*logtest*/
	if (w==NIL) goto IF1889;
	local[2]= fqv[14];
	w = local[1];
	ctx->vsp=local+3;
	local[1] = cons(ctx,local[2],w);
	local[2]= local[1];
	goto IF1890;
IF1889:
	local[2]= NIL;
IF1890:
	local[2]= local[0];
	local[3]= makeint(8);
	ctx->vsp=local+4;
	w=(pointer)LOGTEST(ctx,2,local+2); /*logtest*/
	if (w==NIL) goto IF1891;
	local[2]= fqv[15];
	w = local[1];
	ctx->vsp=local+3;
	local[1] = cons(ctx,local[2],w);
	local[2]= local[1];
	goto IF1892;
IF1891:
	local[2]= NIL;
IF1892:
	local[2]= local[0];
	local[3]= makeint(256);
	ctx->vsp=local+4;
	w=(pointer)LOGTEST(ctx,2,local+2); /*logtest*/
	if (w==NIL) goto IF1893;
	local[2]= fqv[16];
	w = local[1];
	ctx->vsp=local+3;
	local[1] = cons(ctx,local[2],w);
	local[2]= local[1];
	goto IF1894;
IF1893:
	local[2]= NIL;
IF1894:
	local[2]= local[0];
	local[3]= makeint(512);
	ctx->vsp=local+4;
	w=(pointer)LOGTEST(ctx,2,local+2); /*logtest*/
	if (w==NIL) goto IF1895;
	local[2]= fqv[17];
	w = local[1];
	ctx->vsp=local+3;
	local[1] = cons(ctx,local[2],w);
	local[2]= local[1];
	goto IF1896;
IF1895:
	local[2]= NIL;
IF1896:
	local[2]= local[0];
	local[3]= makeint(1024);
	ctx->vsp=local+4;
	w=(pointer)LOGTEST(ctx,2,local+2); /*logtest*/
	if (w==NIL) goto IF1897;
	local[2]= fqv[18];
	w = local[1];
	ctx->vsp=local+3;
	local[1] = cons(ctx,local[2],w);
	local[2]= local[1];
	goto IF1898;
IF1897:
	local[2]= NIL;
IF1898:
	w = local[1];
	local[0]= w;
BLK1886:
	ctx->vsp=local; return(local[0]);}

/*event-shift*/
static pointer F1811event_shift(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1784xevent_state(ctx,1,local+0); /*xevent-state*/
	local[0]= w;
	local[1]= makeint(3);
	ctx->vsp=local+2;
	w=(pointer)LOGTEST(ctx,2,local+0); /*logtest*/
	local[0]= w;
BLK1899:
	ctx->vsp=local; return(local[0]);}

/*event-control*/
static pointer F1812event_control(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1784xevent_state(ctx,1,local+0); /*xevent-state*/
	local[0]= w;
	local[1]= makeint(4);
	ctx->vsp=local+2;
	w=(pointer)LOGTEST(ctx,2,local+0); /*logtest*/
	local[0]= w;
BLK1900:
	ctx->vsp=local; return(local[0]);}

/*event-meta*/
static pointer F1813event_meta(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1784xevent_state(ctx,1,local+0); /*xevent-state*/
	local[0]= w;
	local[1]= makeint(8);
	ctx->vsp=local+2;
	w=(pointer)LOGTEST(ctx,2,local+0); /*logtest*/
	local[0]= w;
BLK1901:
	ctx->vsp=local; return(local[0]);}

/*event-left*/
static pointer F1814event_left(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1784xevent_state(ctx,1,local+0); /*xevent-state*/
	local[0]= w;
	local[1]= makeint(256);
	ctx->vsp=local+2;
	w=(pointer)LOGTEST(ctx,2,local+0); /*logtest*/
	local[0]= w;
BLK1902:
	ctx->vsp=local; return(local[0]);}

/*event-middle*/
static pointer F1815event_middle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1784xevent_state(ctx,1,local+0); /*xevent-state*/
	local[0]= w;
	local[1]= makeint(512);
	ctx->vsp=local+2;
	w=(pointer)LOGTEST(ctx,2,local+0); /*logtest*/
	local[0]= w;
BLK1903:
	ctx->vsp=local; return(local[0]);}

/*event-right*/
static pointer F1816event_right(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F1784xevent_state(ctx,1,local+0); /*xevent-state*/
	local[0]= w;
	local[1]= makeint(1024);
	ctx->vsp=local+2;
	w=(pointer)LOGTEST(ctx,2,local+0); /*logtest*/
	local[0]= w;
BLK1904:
	ctx->vsp=local; return(local[0]);}

/*event-pressed*/
static pointer F1817event_pressed(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT1907;}
	local[0]= NIL;
ENT1907:
ENT1906:
	if (n>2) maerror();
	if (local[0]==NIL) goto IF1908;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F1792xevent_alt_state(ctx,1,local+1); /*xevent-alt-state*/
	local[1]= w;
	goto IF1909;
IF1908:
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F1784xevent_state(ctx,1,local+1); /*xevent-state*/
	local[1]= w;
IF1909:
	local[2]= makeint(1792);
	ctx->vsp=local+3;
	w=(pointer)LOGTEST(ctx,2,local+1); /*logtest*/
	local[0]= w;
BLK1905:
	ctx->vsp=local; return(local[0]);}

/*print-event*/
static pointer F1818print_event(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	local[3]= T;
	local[4]= fqv[19];
	local[5]= loadglobal(fqv[8]);
	ctx->vsp=local+6;
	w=(pointer)F1762xevent_serial(ctx,1,local+5); /*xevent-serial*/
	local[5]= w;
	local[6]= loadglobal(fqv[8]);
	ctx->vsp=local+7;
	w=(pointer)F1797event_type(ctx,1,local+6); /*event-type*/
	local[6]= w;
	local[7]= loadglobal(fqv[8]);
	ctx->vsp=local+8;
	w=(pointer)F1808event_window(ctx,1,local+7); /*event-window*/
	local[7]= w;
	local[8]= fqv[20];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= loadglobal(fqv[8]);
	ctx->vsp=local+9;
	w=(pointer)F1802event_pos(ctx,1,local+8); /*event-pos*/
	local[8]= w;
	local[9]= loadglobal(fqv[8]);
	ctx->vsp=local+10;
	w=(pointer)F1810event_state(ctx,1,local+9); /*event-state*/
	local[9]= w;
	local[10]= loadglobal(fqv[8]);
	ctx->vsp=local+11;
	w=(pointer)F1784xevent_state(ctx,1,local+10); /*xevent-state*/
	local[10]= w;
	local[11]= loadglobal(fqv[8]);
	ctx->vsp=local+12;
	w=(pointer)F1803event_key(ctx,1,local+11); /*event-key*/
	local[11]= w;
	local[12]= loadglobal(fqv[8]);
	ctx->vsp=local+13;
	w=(pointer)F1774xevent_time(ctx,1,local+12); /*xevent-time*/
	local[12]= w;
	local[13]= makeflt(1.00000000e+03);
	ctx->vsp=local+14;
	w=(pointer)QUOTIENT(ctx,2,local+12); /*/*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,10,local+3); /*format*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1910:
	ctx->vsp=local; return(local[0]);}

/*display-events*/
static pointer F1819display_events(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= loadglobal(fqv[6]);
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[21]); /*sync*/
WHL1912:
	if (T==NIL) goto WHX1913;
	local[0]= loadglobal(fqv[6]);
	local[1]= loadglobal(fqv[8]);
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[9]); /*nextevent*/
	local[0]= loadglobal(fqv[8]);
	ctx->vsp=local+1;
	w=(pointer)F1818print_event(ctx,1,local+0); /*print-event*/
	local[0]= loadglobal(fqv[8]);
	ctx->vsp=local+1;
	w=(pointer)F1797event_type(ctx,1,local+0); /*event-type*/
	local[0]= w;
	local[1]= fqv[22];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF1915;
	local[0]= loadglobal(fqv[8]);
	ctx->vsp=local+1;
	w=(pointer)F1803event_key(ctx,1,local+0); /*event-key*/
	local[0]= w;
	local[1]= makeint(103);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF1915;
	w = NIL;
	ctx->vsp=local+0;
	local[0]=w;
	goto BLK1911;
	goto IF1916;
IF1915:
	local[0]= NIL;
IF1916:
	goto WHL1912;
WHX1913:
	local[0]= NIL;
BLK1914:
	w = local[0];
	local[0]= w;
BLK1911:
	ctx->vsp=local; return(local[0]);}

/*:event-notify-print*/
static pointer M1917xwindow_event_notify_print(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	w = argv[3];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	local[3]= T;
	local[4]= fqv[23];
	local[5]= argv[2];
	local[6]= loadglobal(fqv[8]);
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,4,local+3); /*format*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1918:
	ctx->vsp=local; return(local[0]);}

/*:event-notify-dispatch*/
static pointer M1919xwindow_event_notify_dispatch(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	w = argv[3];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	local[3]= argv[0];
	local[4]= argv[2];
	local[5]= loadglobal(fqv[8]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1920:
	ctx->vsp=local; return(local[0]);}

/*:event-notify*/
static pointer M1921xwindow_event_notify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	w = argv[3];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	if (argv[0]->c.obj.iv[11]==NIL) goto CON1924;
	local[3]= argv[0]->c.obj.iv[11];
	local[4]= fqv[24];
	local[5]= argv[2];
	local[6]= loadglobal(fqv[8]);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto CON1923;
CON1924:
	local[3]= argv[2];
	local[4]= fqv[25];
	ctx->vsp=local+5;
	w=(*ftab[5])(ctx,2,local+3,&ftab[5],fqv[26]); /*member*/
	if (w==NIL) goto CON1925;
	local[3]= argv[0];
	local[4]= fqv[27];
	local[5]= argv[2];
	local[6]= loadglobal(fqv[8]);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto CON1923;
CON1925:
	local[3]= argv[2];
	local[4]= fqv[28];
	ctx->vsp=local+5;
	w=(*ftab[5])(ctx,2,local+3,&ftab[5],fqv[26]); /*member*/
	if (w==NIL) goto CON1926;
	local[3]= argv[2];
	if (fqv[29]!=local[3]) goto IF1927;
	local[3]= loadglobal(fqv[30]);
	local[4]= loadglobal(fqv[31]);
	ctx->vsp=local+5;
	w=(pointer)DERIVEDP(ctx,2,local+3); /*derivedp*/
	if (w==NIL) goto IF1927;
	local[3]= loadglobal(fqv[30]);
	local[4]= fqv[29];
	local[5]= loadglobal(fqv[8]);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF1928;
IF1927:
	local[3]= NIL;
IF1928:
	local[3]= argv[0];
	local[4]= fqv[27];
	local[5]= argv[2];
	local[6]= loadglobal(fqv[8]);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto CON1923;
CON1926:
	local[3]= NIL;
CON1923:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1922:
	ctx->vsp=local; return(local[0]);}

/*:keyrelease*/
static pointer M1929xwindow_keyrelease(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	if (loadglobal(fqv[32])==NIL) goto IF1931;
	local[3]= fqv[33];
	local[4]= fqv[22];
	ctx->vsp=local+5;
	w=(*ftab[6])(ctx,2,local+3,&ftab[6],fqv[34]); /*warn*/
	local[3]= w;
	goto IF1932;
IF1931:
	local[3]= NIL;
IF1932:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1930:
	ctx->vsp=local; return(local[0]);}

/*:keypress*/
static pointer M1933xwindow_keypress(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	local[3]= loadglobal(fqv[8]);
	local[4]= loadglobal(fqv[35]);
	local[5]= makeint(1);
	local[6]= makeint(0);
	local[7]= makeint(0);
	ctx->vsp=local+8;
	w=(*ftab[7])(ctx,5,local+3,&ftab[7],fqv[36]); /*lookupstring*/
	local[3]= w;
	local[4]= makeint(1);
	ctx->vsp=local+5;
	w=(pointer)NUMEQUAL(ctx,2,local+3); /*=*/
	if (w==NIL) goto IF1935;
	local[3]= argv[0];
	local[4]= fqv[37];
	local[5]= loadglobal(fqv[35]);
	{ register eusinteger_t i=intval(makeint(0));
	  w=makeint(local[5]->c.str.chars[i]);}
	local[5]= w;
	local[6]= loadglobal(fqv[8]);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF1936;
IF1935:
	local[3]= NIL;
IF1936:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1934:
	ctx->vsp=local; return(local[0]);}

/*:keyenter*/
static pointer M1937xwindow_keyenter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1940;}
	local[0]= NIL;
ENT1940:
	w = local[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
ENT1939:
	if (n>4) maerror();
	if (loadglobal(fqv[32])==NIL) goto IF1941;
	local[3]= fqv[38];
	local[4]= fqv[37];
	ctx->vsp=local+5;
	w=(*ftab[6])(ctx,2,local+3,&ftab[6],fqv[34]); /*warn*/
	local[3]= w;
	goto IF1942;
IF1941:
	local[3]= NIL;
IF1942:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1938:
	ctx->vsp=local; return(local[0]);}

/*:buttonpress*/
static pointer M1943xwindow_buttonpress(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	if (loadglobal(fqv[32])==NIL) goto IF1945;
	local[3]= fqv[39];
	local[4]= fqv[40];
	ctx->vsp=local+5;
	w=(*ftab[6])(ctx,2,local+3,&ftab[6],fqv[34]); /*warn*/
	local[3]= loadglobal(fqv[8]);
	ctx->vsp=local+4;
	w=(pointer)F1810event_state(ctx,1,local+3); /*event-state*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PRINT(ctx,1,local+3); /*print*/
	local[3]= w;
	goto IF1946;
IF1945:
	local[3]= NIL;
IF1946:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1944:
	ctx->vsp=local; return(local[0]);}

/*:buttonrelease*/
static pointer M1947xwindow_buttonrelease(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	if (loadglobal(fqv[32])==NIL) goto IF1949;
	local[3]= fqv[41];
	local[4]= fqv[29];
	ctx->vsp=local+5;
	w=(*ftab[6])(ctx,2,local+3,&ftab[6],fqv[34]); /*warn*/
	local[3]= w;
	goto IF1950;
IF1949:
	local[3]= NIL;
IF1950:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1948:
	ctx->vsp=local; return(local[0]);}

/*:motionnotify*/
static pointer M1951xwindow_motionnotify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	if (loadglobal(fqv[32])==NIL) goto IF1953;
	local[3]= fqv[42];
	local[4]= fqv[43];
	ctx->vsp=local+5;
	w=(*ftab[6])(ctx,2,local+3,&ftab[6],fqv[34]); /*warn*/
	local[3]= w;
	goto IF1954;
IF1953:
	local[3]= NIL;
IF1954:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1952:
	ctx->vsp=local; return(local[0]);}

/*:enternotify*/
static pointer M1955xwindow_enternotify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	if (loadglobal(fqv[32])==NIL) goto IF1957;
	local[3]= fqv[44];
	local[4]= fqv[45];
	ctx->vsp=local+5;
	w=(*ftab[6])(ctx,2,local+3,&ftab[6],fqv[34]); /*warn*/
	local[3]= w;
	goto IF1958;
IF1957:
	local[3]= NIL;
IF1958:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1956:
	ctx->vsp=local; return(local[0]);}

/*:leavenotify*/
static pointer M1959xwindow_leavenotify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	if (loadglobal(fqv[32])==NIL) goto IF1961;
	local[3]= fqv[46];
	local[4]= fqv[47];
	ctx->vsp=local+5;
	w=(*ftab[6])(ctx,2,local+3,&ftab[6],fqv[34]); /*warn*/
	local[3]= w;
	goto IF1962;
IF1961:
	local[3]= NIL;
IF1962:
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1960:
	ctx->vsp=local; return(local[0]);}

/*:configurenotify*/
static pointer M1963xwindow_configurenotify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	if (loadglobal(fqv[32])==NIL) goto IF1965;
	local[3]= fqv[48];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[6])(ctx,2,local+3,&ftab[6],fqv[34]); /*warn*/
	local[3]= w;
	goto IF1966;
IF1965:
	local[3]= NIL;
IF1966:
	local[3]= argv[0];
	local[4]= fqv[49];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[50];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	if (T==NIL) goto IF1967;
	local[5]= local[3];
	local[6]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+7;
	w=(*ftab[8])(ctx,2,local+5,&ftab[8],fqv[51]); /*/=*/
	local[5]= w;
	if (w!=NIL) goto OR1969;
	local[5]= local[4];
	local[6]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+7;
	w=(*ftab[8])(ctx,2,local+5,&ftab[8],fqv[51]); /*/=*/
	local[5]= w;
OR1969:
	argv[0]->c.obj.iv[5] = local[3];
	argv[0]->c.obj.iv[6] = local[4];
	local[5]= argv[0];
	local[6]= fqv[52];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	goto IF1968;
IF1967:
	local[5]= NIL;
IF1968:
	w = local[5];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1964:
	ctx->vsp=local; return(local[0]);}

/*:configurerequest*/
static pointer M1970xwindow_configurerequest(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	local[3]= fqv[53];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[6])(ctx,2,local+3,&ftab[6],fqv[34]); /*warn*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1971:
	ctx->vsp=local; return(local[0]);}

/*:expose*/
static pointer M1972xwindow_expose(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	local[3]= argv[0];
	local[4]= fqv[52];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1973:
	ctx->vsp=local; return(local[0]);}

/*:visibilitynotify*/
static pointer M1974xwindow_visibilitynotify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	local[3]= NIL;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1975:
	ctx->vsp=local; return(local[0]);}

/*:redraw*/
static pointer M1976xwindow_redraw(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[54];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,2,local+0,&ftab[6],fqv[34]); /*warn*/
	local[0]= w;
BLK1977:
	ctx->vsp=local; return(local[0]);}

/*process-event*/
static pointer F1820process_event(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
	local[3]= loadglobal(fqv[8]);
	ctx->vsp=local+4;
	w=(pointer)F1808event_window(ctx,1,local+3); /*event-window*/
	local[3]= w;
	local[4]= loadglobal(fqv[8]);
	ctx->vsp=local+5;
	w=(pointer)F1797event_type(ctx,1,local+4); /*event-type*/
	local[4]= w;
	if (loadglobal(fqv[32])==NIL) goto IF1979;
	local[5]= loadglobal(fqv[8]);
	ctx->vsp=local+6;
	w=(pointer)F1818print_event(ctx,1,local+5); /*print-event*/
	local[5]= w;
	goto IF1980;
IF1979:
	local[5]= NIL;
IF1980:
	local[5]= local[3];
	local[6]= loadglobal(fqv[31]);
	ctx->vsp=local+7;
	w=(pointer)DERIVEDP(ctx,2,local+5); /*derivedp*/
	if (w==NIL) goto IF1981;
	local[5]= local[3];
	local[6]= fqv[24];
	local[7]= local[4];
	local[8]= loadglobal(fqv[8]);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto IF1982;
IF1981:
	local[5]= NIL;
IF1982:
	w = local[5];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1978:
	ctx->vsp=local; return(local[0]);}

/*window-main-one*/
static pointer F1821window_main_one(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT1985;}
	local[0]= NIL;
ENT1985:
ENT1984:
	if (n>1) maerror();
	{jmp_buf jb;
	w = fqv[55];
	ctx->vsp=local+1;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT1986;}
WHL1987:
	local[7]= loadglobal(fqv[6]);
	local[8]= makeint(1);
	ctx->vsp=local+9;
	w=(*ftab[9])(ctx,2,local+7,&ftab[9],fqv[56]); /*eventsqueued*/
	local[7]= w;
	local[8]= makeint(0);
	ctx->vsp=local+9;
	w=(pointer)GREATERP(ctx,2,local+7); /*>*/
	if (w==NIL) goto WHX1988;
	local[7]= loadglobal(fqv[6]);
	local[8]= loadglobal(fqv[8]);
	ctx->vsp=local+9;
	w=(*ftab[2])(ctx,2,local+7,&ftab[2],fqv[9]); /*nextevent*/
	if (loadglobal(fqv[57])==NIL) goto IF1990;
	local[7]= loadglobal(fqv[8]);
	ctx->vsp=local+8;
	w=(pointer)F1818print_event(ctx,1,local+7); /*print-event*/
	local[7]= w;
	goto IF1991;
IF1990:
	local[7]= NIL;
IF1991:
	if (loadglobal(fqv[58])==NIL) goto IF1992;
	local[7]= loadglobal(fqv[8]);
	ctx->vsp=local+8;
	w=(pointer)F1797event_type(ctx,1,local+7); /*event-type*/
	local[7]= w;
	local[8]= fqv[43];
	ctx->vsp=local+9;
	w=(pointer)EQ(ctx,2,local+7); /*eql*/
	if (w==NIL) goto IF1992;
WHL1994:
	local[7]= loadglobal(fqv[6]);
	ctx->vsp=local+8;
	w=(*ftab[1])(ctx,1,local+7,&ftab[1],fqv[7]); /*pending*/
	local[7]= w;
	local[8]= makeint(0);
	ctx->vsp=local+9;
	w=(pointer)GREATERP(ctx,2,local+7); /*>*/
	if (w==NIL) goto WHX1995;
	local[7]= loadglobal(fqv[6]);
	local[8]= loadglobal(fqv[59]);
	ctx->vsp=local+9;
	w=(*ftab[10])(ctx,2,local+7,&ftab[10],fqv[60]); /*peekevent*/
	local[7]= loadglobal(fqv[59]);
	ctx->vsp=local+8;
	w=(pointer)F1797event_type(ctx,1,local+7); /*event-type*/
	local[7]= w;
	local[8]= fqv[43];
	ctx->vsp=local+9;
	w=(pointer)EQ(ctx,2,local+7); /*eql*/
	if (w==NIL) goto WHX1995;
	local[7]= loadglobal(fqv[6]);
	local[8]= loadglobal(fqv[8]);
	ctx->vsp=local+9;
	w=(*ftab[2])(ctx,2,local+7,&ftab[2],fqv[9]); /*nextevent*/
	local[7]= loadglobal(fqv[61]);
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[7]= w;
	storeglobal(fqv[61],w);
	goto WHL1994;
WHX1995:
	local[7]= NIL;
BLK1996:
	goto IF1993;
IF1992:
	local[7]= NIL;
IF1993:
	local[7]= loadglobal(fqv[8]);
	ctx->vsp=local+8;
	w=(pointer)F1820process_event(ctx,1,local+7); /*process-event*/
	goto WHL1987;
WHX1988:
	local[7]= NIL;
BLK1989:
	ctx->vsp=local+7;
	w=(*ftab[11])(ctx,0,local+7,&ftab[11],fqv[62]); /*xflush*/
CAT1986:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[0]= w;
BLK1983:
	ctx->vsp=local; return(local[0]);}

/*window-main-loop*/
static pointer F1997(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST1999:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	if (local[0]!=NIL) goto IF2000;
	local[1]= fqv[63];
	local[2]= fqv[21];
	local[3]= fqv[6];
	local[4]= fqv[64];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[65];
	local[4]= fqv[55];
	local[5]= fqv[66];
	local[6]= fqv[67];
	local[7]= fqv[68];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[21];
	local[7]= fqv[6];
	local[8]= fqv[69];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[62];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto IF2001;
IF2000:
	local[1]= fqv[63];
	local[2]= fqv[21];
	local[3]= fqv[6];
	local[4]= fqv[70];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[65];
	local[4]= fqv[55];
	local[5]= fqv[66];
	local[6]= fqv[67];
	local[7]= fqv[71];
	local[8]= fqv[72];
	local[9]= fqv[7];
	local[10]= fqv[6];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[73];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[9];
	local[10]= fqv[6];
	local[11]= fqv[8];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[74];
	local[11]= fqv[8];
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
	local[9]= fqv[67];
	w = local[0];
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
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
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[21];
	local[5]= fqv[6];
	local[6]= fqv[75];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[62];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
IF2001:
	w = local[1];
	local[0]= w;
BLK1998:
	ctx->vsp=local; return(local[0]);}

/*wml*/
static pointer F2002(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST2004:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= fqv[76];
	w = local[0];
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK2003:
	ctx->vsp=local; return(local[0]);}

/*wmlerror*/
static pointer F1822wmlerror(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT2007;}
	local[0]= NIL;
ENT2007:
ENT2006:
	if (n>4) maerror();
	local[1]= loadglobal(fqv[77]);
	local[2]= fqv[78];
	local[3]= loadglobal(fqv[79]);
	ctx->vsp=local+4;
	w=(pointer)THR_SELF(ctx,0,local+4); /*unix:thr-self*/
	local[4]= w;
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,5,local+1); /*format*/
	if (local[0]==NIL) goto IF2008;
	local[1]= loadglobal(fqv[77]);
	local[2]= fqv[80];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	goto IF2009;
IF2008:
	local[1]= NIL;
IF2009:
	if (argv[2]==NIL) goto IF2010;
	local[1]= loadglobal(fqv[77]);
	local[2]= fqv[81];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	goto IF2011;
IF2010:
	local[1]= NIL;
IF2011:
	local[1]= loadglobal(fqv[77]);
	ctx->vsp=local+2;
	w=(pointer)TERPRI(ctx,1,local+1); /*terpri*/
	local[1]= fqv[82];
	w = NIL;
	ctx->vsp=local+2;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	w = local[1];
	local[0]= w;
BLK2005:
	ctx->vsp=local; return(local[0]);}

/*window-main-thread2*/
static pointer F1823window_main_thread2(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= makeint(0);
	local[1]= (pointer)get_sym_func(fqv[83]);
	ctx->vsp=local+2;
	w=(*ftab[12])(ctx,1,local+1,&ftab[12],fqv[84]); /*lisp::install-error-handler*/
	local[1]= loadglobal(fqv[6]);
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(*ftab[4])(ctx,2,local+1,&ftab[4],fqv[21]); /*sync*/
	{jmp_buf jb;
	w = fqv[55];
	ctx->vsp=local+1;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT2013;}
WHL2014:
	if (T==NIL) goto WHX2015;
	{jmp_buf jb;
	w = fqv[82];
	ctx->vsp=local+7;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT2017;}
	local[13]= loadglobal(fqv[6]);
	local[14]= loadglobal(fqv[8]);
	ctx->vsp=local+15;
	w=(*ftab[2])(ctx,2,local+13,&ftab[2],fqv[9]); /*nextevent*/
	if (loadglobal(fqv[32])==NIL) goto IF2018;
	local[13]= loadglobal(fqv[8]);
	ctx->vsp=local+14;
	w=(pointer)F1818print_event(ctx,1,local+13); /*print-event*/
	local[13]= w;
	goto IF2019;
IF2018:
	local[13]= NIL;
IF2019:
	local[13]= local[0];
	ctx->vsp=local+14;
	w=(pointer)ADD1(ctx,1,local+13); /*1+*/
	local[0] = w;
	local[13]= loadglobal(fqv[8]);
	ctx->vsp=local+14;
	w=(pointer)F1820process_event(ctx,1,local+13); /*process-event*/
CAT2017:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	goto WHL2014;
WHX2015:
	local[7]= NIL;
BLK2016:
	w = local[7];
CAT2013:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[1]= fqv[85];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[6])(ctx,2,local+1,&ftab[6],fqv[34]); /*warn*/
	local[1]= loadglobal(fqv[6]);
	local[2]= makeint(1);
	ctx->vsp=local+3;
	w=(*ftab[4])(ctx,2,local+1,&ftab[4],fqv[21]); /*sync*/
	ctx->vsp=local+1;
	w=(*ftab[11])(ctx,0,local+1,&ftab[11],fqv[62]); /*xflush*/
	local[0]= w;
BLK2012:
	ctx->vsp=local; return(local[0]);}

/*window-main-thread*/
static pointer F1824window_main_thread(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= (pointer)get_sym_func(fqv[86]);
	ctx->vsp=local+1;
	w=(pointer)AFUNCALL_NO_WAIT(ctx,1,local+0); /*system:thread-no-wait*/
	local[0]= w;
BLK2020:
	ctx->vsp=local; return(local[0]);}

/*display-fd*/
static pointer F1825display_fd(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT2023;}
	local[0]= loadglobal(fqv[6]);
ENT2023:
ENT2022:
	if (n>1) maerror();
	if (local[0]==NIL) goto IF2024;
	local[1]= local[0];
	local[2]= makeint(16);
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[1]= w;
	local[2]= fqv[0];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,2,local+1); /*system:peek*/
	local[1]= w;
	goto IF2025;
IF2024:
	local[1]= NIL;
IF2025:
	w = local[1];
	local[0]= w;
BLK2021:
	ctx->vsp=local; return(local[0]);}

/*repwin*/
static pointer F1826repwin(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	ctx->vsp=local+0;
	w=(pointer)F1825display_fd(ctx,0,local+0); /*display-fd*/
	local[0]= w;
	local[1]= NIL;
	local[2]= T;
WHL2027:
	if (T==NIL) goto WHX2028;
	if (local[2]==NIL) goto IF2030;
	local[3]= loadglobal(fqv[87]);
	local[4]= fqv[88];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,2,local+3); /*format*/
	local[3]= loadglobal(fqv[87]);
	ctx->vsp=local+4;
	w=(pointer)FINOUT(ctx,1,local+3); /*finish-output*/
	local[3]= w;
	goto IF2031;
IF2030:
	local[3]= NIL;
IF2031:
	local[2] = NIL;
	local[3]= loadglobal(fqv[89]);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[3]= w;
	local[4]= makeflt(1.00000000e+01);
	ctx->vsp=local+5;
	w=(*ftab[13])(ctx,2,local+3,&ftab[13],fqv[90]); /*select-stream*/
	local[1] = w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= loadglobal(fqv[89]);
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w==NIL) goto CON2033;
	local[3]= loadglobal(fqv[89]);
	ctx->vsp=local+4;
	w=(pointer)READ(ctx,1,local+3); /*read*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)EVAL(ctx,1,local+3); /*eval*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)PRINT(ctx,1,local+3); /*print*/
	local[2] = T;
	local[3]= local[2];
	goto CON2032;
CON2033:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w==NIL) goto CON2034;
	ctx->vsp=local+3;
	w=(pointer)F1821window_main_one(ctx,0,local+3); /*window-main-one*/
	local[3]= w;
	goto CON2032;
CON2034:
	local[3]= loadglobal(fqv[91]);
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[3]= w;
	storeglobal(fqv[91],w);
	goto CON2032;
CON2035:
	local[3]= NIL;
CON2032:
	goto WHL2027;
WHX2028:
	local[3]= NIL;
BLK2029:
	w = local[3];
	local[0]= w;
BLK2026:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___Xevent(ctx,n,argv,env)
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
	local[0]= fqv[92];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF2036;
	local[0]= fqv[93];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[94],w);
	goto IF2037;
IF2036:
	local[0]= fqv[95];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF2037:
	local[0]= fqv[96];
	local[1]= fqv[97];
	ctx->vsp=local+2;
	w=(*ftab[14])(ctx,2,local+0,&ftab[14],fqv[98]); /*require*/
	local[0]= fqv[99];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[57];
	local[1]= fqv[100];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[101];
	local[1]= fqv[100];
	local[2]= fqv[101];
	local[3]= fqv[102];
	local[4]= loadglobal(fqv[103]);
	local[5]= fqv[104];
	local[6]= fqv[105];
	local[7]= fqv[106];
	local[8]= loadglobal(fqv[107]);
	local[9]= fqv[108];
	local[10]= fqv[2];
	local[11]= fqv[109];
	local[12]= makeint(-1);
	local[13]= fqv[110];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[15])(ctx,13,local+2,&ftab[15],fqv[111]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= loadglobal(fqv[101]);
	local[1]= fqv[112];
	local[2]= fqv[113];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[114],module,F1760xevent_type,fqv[115]);
	local[0]= fqv[114];
	local[1]= fqv[116];
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[114];
	local[1]= fqv[118];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[114];
	local[1]= fqv[120];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[114];
	local[1]= NIL;
	local[2]= fqv[121];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[116],module,F1761set_xevent_type,fqv[122]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[123],module,F1762xevent_serial,fqv[124]);
	local[0]= fqv[123];
	local[1]= fqv[125];
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[123];
	local[1]= fqv[118];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[123];
	local[1]= fqv[120];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[123];
	local[1]= NIL;
	local[2]= fqv[121];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[125],module,F1763set_xevent_serial,fqv[126]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[127],module,F1764xevent_send_event,fqv[128]);
	local[0]= fqv[127];
	local[1]= fqv[129];
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[127];
	local[1]= fqv[118];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[127];
	local[1]= fqv[120];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[127];
	local[1]= NIL;
	local[2]= fqv[121];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[129],module,F1765set_xevent_send_event,fqv[130]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[131],module,F1766xevent_display,fqv[132]);
	local[0]= fqv[131];
	local[1]= fqv[133];
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[131];
	local[1]= fqv[118];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[131];
	local[1]= fqv[120];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[131];
	local[1]= NIL;
	local[2]= fqv[121];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[133],module,F1767set_xevent_display,fqv[134]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[135],module,F1768xevent_window,fqv[136]);
	local[0]= fqv[135];
	local[1]= fqv[137];
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[135];
	local[1]= fqv[118];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[135];
	local[1]= fqv[120];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[135];
	local[1]= NIL;
	local[2]= fqv[121];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[137],module,F1769set_xevent_window,fqv[138]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[139],module,F1770xevent_root,fqv[140]);
	local[0]= fqv[139];
	local[1]= fqv[141];
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[139];
	local[1]= fqv[118];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[139];
	local[1]= fqv[120];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[139];
	local[1]= NIL;
	local[2]= fqv[121];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[141],module,F1771set_xevent_root,fqv[142]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[143],module,F1772xevent_subwindow,fqv[144]);
	local[0]= fqv[143];
	local[1]= fqv[145];
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[143];
	local[1]= fqv[118];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[143];
	local[1]= fqv[120];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[143];
	local[1]= NIL;
	local[2]= fqv[121];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[145],module,F1773set_xevent_subwindow,fqv[146]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[147],module,F1774xevent_time,fqv[148]);
	local[0]= fqv[147];
	local[1]= fqv[149];
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[147];
	local[1]= fqv[118];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[147];
	local[1]= fqv[120];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[147];
	local[1]= NIL;
	local[2]= fqv[121];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[149],module,F1775set_xevent_time,fqv[150]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[151],module,F1776xevent_x,fqv[152]);
	local[0]= fqv[151];
	local[1]= fqv[153];
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[151];
	local[1]= fqv[118];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[151];
	local[1]= fqv[120];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[151];
	local[1]= NIL;
	local[2]= fqv[121];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[153],module,F1777set_xevent_x,fqv[154]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[155],module,F1778xevent_y,fqv[156]);
	local[0]= fqv[155];
	local[1]= fqv[157];
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[155];
	local[1]= fqv[118];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[155];
	local[1]= fqv[120];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[155];
	local[1]= NIL;
	local[2]= fqv[121];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[157],module,F1779set_xevent_y,fqv[158]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[159],module,F1780xevent_x_root,fqv[160]);
	local[0]= fqv[159];
	local[1]= fqv[161];
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[159];
	local[1]= fqv[118];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[159];
	local[1]= fqv[120];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[159];
	local[1]= NIL;
	local[2]= fqv[121];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[161],module,F1781set_xevent_x_root,fqv[162]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[163],module,F1782xevent_y_root,fqv[164]);
	local[0]= fqv[163];
	local[1]= fqv[165];
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[163];
	local[1]= fqv[118];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[163];
	local[1]= fqv[120];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[163];
	local[1]= NIL;
	local[2]= fqv[121];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[165],module,F1783set_xevent_y_root,fqv[166]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[167],module,F1784xevent_state,fqv[168]);
	local[0]= fqv[167];
	local[1]= fqv[169];
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[167];
	local[1]= fqv[118];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[167];
	local[1]= fqv[120];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[167];
	local[1]= NIL;
	local[2]= fqv[121];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[169],module,F1785set_xevent_state,fqv[170]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[171],module,F1786xevent_detail,fqv[172]);
	local[0]= fqv[171];
	local[1]= fqv[173];
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[171];
	local[1]= fqv[118];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[171];
	local[1]= fqv[120];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[171];
	local[1]= NIL;
	local[2]= fqv[121];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[173],module,F1787set_xevent_detail,fqv[174]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[175],module,F1788xevent_same_screen,fqv[176]);
	local[0]= fqv[175];
	local[1]= fqv[177];
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[175];
	local[1]= fqv[118];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[175];
	local[1]= fqv[120];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[175];
	local[1]= NIL;
	local[2]= fqv[121];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[177],module,F1789set_xevent_same_screen,fqv[178]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[179],module,F1790xevent_focus,fqv[180]);
	local[0]= fqv[179];
	local[1]= fqv[181];
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[179];
	local[1]= fqv[118];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[179];
	local[1]= fqv[120];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[179];
	local[1]= NIL;
	local[2]= fqv[121];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[181],module,F1791set_xevent_focus,fqv[182]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[183],module,F1792xevent_alt_state,fqv[184]);
	local[0]= fqv[183];
	local[1]= fqv[185];
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[183];
	local[1]= fqv[118];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[183];
	local[1]= fqv[120];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[183];
	local[1]= NIL;
	local[2]= fqv[121];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[185],module,F1793set_xevent_alt_state,fqv[186]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[187],module,F1794xevent_pad,fqv[188]);
	local[0]= fqv[187];
	local[1]= fqv[189];
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= fqv[187];
	local[1]= fqv[118];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[187];
	local[1]= fqv[120];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[119]); /*remprop*/
	local[0]= fqv[187];
	local[1]= NIL;
	local[2]= fqv[121];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[189],module,F1795set_xevent_pad,fqv[190]);
	local[0]= fqv[8];
	local[1]= fqv[100];
	local[2]= loadglobal(fqv[101]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[59];
	local[1]= fqv[100];
	local[2]= loadglobal(fqv[101]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[191],module,F1796next_event,fqv[192]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[193],module,F1797event_type,fqv[194]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[195],module,F1798event_x,fqv[196]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[197],module,F1799event_y,fqv[198]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[199],module,F1800event_x_root,fqv[200]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[201],module,F1801event_y_root,fqv[202]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[203],module,F1802event_pos,fqv[204]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[205],module,F1803event_key,fqv[206]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[207],module,F1804event_root_pos,fqv[208]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[209],module,F1805event_width,fqv[210]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[211],module,F1806event_height,fqv[212]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[213],module,F1807event_time,fqv[214]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[215],module,F1808event_window,fqv[216]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[217],module,F1809event_button,fqv[218]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[219],module,F1810event_state,fqv[220]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[221],module,F1811event_shift,fqv[222]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[223],module,F1812event_control,fqv[224]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[225],module,F1813event_meta,fqv[226]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[227],module,F1814event_left,fqv[228]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[229],module,F1815event_middle,fqv[230]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[231],module,F1816event_right,fqv[232]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[233],module,F1817event_pressed,fqv[234]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[235],module,F1818print_event,fqv[236]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[237],module,F1819display_events,fqv[238]);
	local[0]= fqv[35];
	local[1]= fqv[100];
	local[2]= makeint(3);
	ctx->vsp=local+3;
	w=(*ftab[17])(ctx,1,local+2,&ftab[17],fqv[239]); /*make-string*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1917xwindow_event_notify_print,fqv[240],fqv[31],fqv[241]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1919xwindow_event_notify_dispatch,fqv[27],fqv[31],fqv[242]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1921xwindow_event_notify,fqv[24],fqv[31],fqv[243]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1929xwindow_keyrelease,fqv[22],fqv[31],fqv[244]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1933xwindow_keypress,fqv[245],fqv[31],fqv[246]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1937xwindow_keyenter,fqv[37],fqv[31],fqv[247]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1943xwindow_buttonpress,fqv[40],fqv[31],fqv[248]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1947xwindow_buttonrelease,fqv[29],fqv[31],fqv[249]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1951xwindow_motionnotify,fqv[43],fqv[31],fqv[250]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1955xwindow_enternotify,fqv[45],fqv[31],fqv[251]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1959xwindow_leavenotify,fqv[47],fqv[31],fqv[252]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1963xwindow_configurenotify,fqv[253],fqv[31],fqv[254]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1970xwindow_configurerequest,fqv[255],fqv[31],fqv[256]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1972xwindow_expose,fqv[257],fqv[31],fqv[258]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1974xwindow_visibilitynotify,fqv[259],fqv[31],fqv[260]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1976xwindow_redraw,fqv[52],fqv[31],fqv[261]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[74],module,F1820process_event,fqv[262]);
	local[0]= fqv[61];
	local[1]= fqv[100];
	local[2]= makeint(0);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[58];
	local[1]= fqv[100];
	local[2]= T;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[68],module,F1821window_main_one,fqv[263]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[76],module,F1997,fqv[264]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[265],module,F2002,fqv[266]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[83],module,F1822wmlerror,fqv[267]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[86],module,F1823window_main_thread2,fqv[268]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[269],module,F1824window_main_thread,fqv[270]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[271],module,F1825display_fd,fqv[272]);
	local[0]= fqv[91];
	local[1]= fqv[273];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint(1);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF2038;
	local[0]= fqv[91];
	local[1]= fqv[273];
	local[2]= makeint(2);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[91];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF2040;
	local[0]= fqv[91];
	local[1]= fqv[100];
	local[2]= makeint(0);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2041;
IF2040:
	local[0]= NIL;
IF2041:
	local[0]= fqv[91];
	goto IF2039;
IF2038:
	local[0]= NIL;
IF2039:
	ctx->vsp=local+0;
	compfun(ctx,fqv[274],module,F1826repwin,fqv[275]);
	local[0]= fqv[276];
	local[1]= fqv[277];
	ctx->vsp=local+2;
	w=(*ftab[18])(ctx,2,local+0,&ftab[18],fqv[278]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<19; i++) ftab[i]=fcallx;
}
