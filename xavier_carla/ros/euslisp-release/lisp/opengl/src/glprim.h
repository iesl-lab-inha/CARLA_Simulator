static pointer CLO122();
static pointer CLO125();
static pointer FLET127();
static pointer CLO128();
static pointer CLO136();
static pointer CLO137();
static pointer CLO178();
static pointer CLO183();
static pointer (*ftab[35])();

#define QUOTE_STRINGS_SIZE 89
static char *quote_strings[QUOTE_STRINGS_SIZE]={
    ":vertices",
    ":normal",
    ":convexp",
    ":holes",
    "glbegin",
    "glnormal3fv",
    "glend",
    "*tess-obj*",
    "glubeginpolygon",
    "glunextcontour",
    "gluendpolygon",
    "unix:free",
    "gethash",
    "gltexcoord2fv",
    "glvertex3fv",
    "alloctessinfo",
    "glutessvertex",
    ":gl-displaylist-id",
    ":gl-texture2",
    ":gl-normal",
    ":gl-material",
    ":color",
    "colormaterial",
    ":opengl",
    "float-vector-p",
    "glmaterialfv",
    ":worldcoords",
    ":4x4",
    "glpushmatrix",
    "*temp-matrix*",
    "glmultmatrixf",
    "glcalllist",
    "glpopmatrix",
    "glgenlists",
    ":copy-coords",
    ":gl-texturecoordinate2",
    ":gl-texture-mapping-scheme",
    ":environment",
    "gl_ext_texture_object",
    "probe-extension",
    ":element-type",
    ":integer",
    "make-array",
    "glgentexturesext",
    "glbindtextureext",
    "glpixelstorei",
    "gltexparameteri",
    "gltexenvi",
    ":gl-texture-image",
    ":gl-texture-image-w",
    ":gl-texture-image-h",
    ":gl-texture-image-d",
    "\";; loading texture image ~a~%\"",
    "warn",
    "load-texture-file",
    ":width",
    ":height",
    ":depth",
    ":entity",
    "glteximage2d",
    ":transform",
    ":inverse-transformation",
    "glnewlist",
    "glenable",
    "gltexgeni",
    ":box",
    ":minpoint",
    ":maxpoint",
    "gltexgenfv",
    ":faces",
    "gldisable",
    "glendlist",
    "\"GL\"",
    "\"GL\"",
    "*package*",
    "\"no such package\"",
    "*guard-teximage2d*",
    ":vtype",
    ":global",
    "(4 4)",
    ":float",
    "(*tess-obj* draw-face draw-body)",
    "draw-face",
    "\"(face texture2-tbl normal-tbl)\"",
    "draw-body",
    "\"(vwr abody)\"",
    ":glprim",
    "\"@(#)$Id: glprim.l,v 1.1.1.1 2003/11/20 07:46:32 eus Exp $\"",
    "provide",
  };