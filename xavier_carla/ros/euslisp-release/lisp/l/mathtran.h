static pointer FLET67923();
static pointer FLET67925();
static pointer FLET67927();
static pointer FLET67929();
static pointer FLET67931();
static pointer FLET67933();
static pointer FLET67935();
static pointer FLET67937();
static pointer (*ftab[6])();

#define QUOTE_STRINGS_SIZE 41
static char *quote_strings[QUOTE_STRINGS_SIZE]={
    "\"illegal expression in % macro\"",
    ":test",
    "equal",
    "assoc",
    "\"illegal math expression for % macro\"",
    "values",
    "aref",
    "**",
    "*",
    "temp",
    "let",
    "expt",
    "(* /)",
    "(* /)",
    "(+ -)",
    "-",
    "(+ -)",
    "+",
    "(+ -)",
    "(== != /= < > <= >=)",
    "((== =) (!= /=) (/= /=) (< <) (<= <=) (> >) (>= >=))",
    "let*",
    "=",
    "setq",
    "setf",
    "cdddr",
    "read-delimited-list",
    "\"LISP\"",
    "\"LISP\"",
    "*package*",
    "\"no such package\"",
    "expression",
    "\"(exp &optional (lhs nil) &aux result letvar-alist)\"",
    "infix2prefix",
    "\"(file &optional char)\"",
    "read-aref",
    "\"(file &optional char)\"",
    "set-syntax-from-char",
    ":mathtran",
    "\"@(#)$Id: mathtran.l,v 1.1.1.1 2003/11/20 07:46:31 eus Exp $\"",
    "provide",
  };
