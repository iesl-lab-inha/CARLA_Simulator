static pointer CLO1310();
static pointer CLO1483();
static pointer CLO1510();
static pointer CLO1513();
static pointer CLO1681();
static pointer FLET1748();
static pointer CLO1758();
static pointer FLET1768();
static pointer CLO1807();
static pointer FLET1777();
static pointer FLET1864();
static pointer FLET1865();
static pointer CLO1935();
static pointer CLO1942();
static pointer CLO1945();
static pointer CLO1948();
static pointer (*ftab[31])();

#define QUOTE_STRINGS_SIZE 301
static char *quote_strings[QUOTE_STRINGS_SIZE]={
    "*debug*",
    "*error-output*",
    "\"updating body ~A~%\"",
    ":name",
    ":reset-vertices",
    ":reset-normal",
    ":visible-edges",
    "remprop",
    "send",
    ":get-face",
    ":color",
    ":reflectance",
    ":diffusion",
    "append",
    ":holes",
    "send-all",
    "viewing",
    ":viewpoint",
    ":size",
    ":hash",
    "system:address",
    "make-hash-table",
    ":visible-faces",
    ":all-edges",
    "sethash",
    ":list-values",
    "member",
    ":intersection",
    ":box",
    "*contact-threshold*",
    "make-bounding-box",
    ":visible",
    ":init",
    ":update",
    "float-vector-p",
    "rotation",
    ":x",
    "#f(1.0 0.0 0.0)",
    ":y",
    "#f(0.0 1.0 0.0)",
    ":z",
    "#f(0.0 0.0 1.0)",
    "vector",
    ":intersect-point-vector",
    ":inside",
    "float-vector",
    ":distance",
    "plane",
    "values",
    "#(:faces :edges :vertices :color :reflectance :diffusion)",
    "remove-duplicates",
    ":all-vertices",
    "send-message",
    "super",
    "bounding-box",
    "copy-seq",
    ":translate-vertices",
    ":rotate-vertices",
    ":magnify",
    "+",
    ":length",
    "#f(0.0 0.0 0.0)",
    ":volume",
    ":centroid",
    "car",
    ":worldcoords",
    ":transform-vector",
    ":area",
    ":extream-point",
    ":faces-intersect-with-point-vector",
    "scale",
    ":intersect-face",
    ":possibly-interfering-faces",
    "*epsilon*",
    ":common-box",
    ":possibly-interfering-edges",
    ":coplanar-line",
    ":intersect-line",
    ":normal",
    "eps=",
    ":intersect",
    ":contact",
    ":insidep",
    "*nan*",
    "eps-in-range",
    ":point",
    "(:inside :border)",
    ":border",
    "(:inside :border)",
    "*coplanar-threshold*",
    ":inner",
    ":outside",
    ":plane-distance",
    "random-normalized-vector",
    "oddp",
    ":invert",
    ":init2",
    ":newbox",
    ":set-convexp",
    ":angle",
    "every",
    ":boxtest",
    "bodyp",
    ":primitive-body",
    "keywordp",
    ":primitive-body-type",
    "facep",
    ":primitive-face",
    ":id",
    ":end",
    "(:top :bottom)",
    ":+",
    ":primitive-groups",
    ":-",
    "collect-if",
    ":primitive-body-p",
    "(+ - * /)",
    ":complex",
    ":prin1",
    ":body-type",
    "#(:approximated :primitive :csg)",
    ":set-angle",
    ":set-approximated-flag",
    "plusp",
    ":body",
    "primitive-body-p",
    ":csg",
    ":parent",
    ":dissoc",
    ":descendants",
    ":clear-assoc",
    ":assoc",
    ":copied-primitive",
    "body+",
    "-",
    "body-",
    ":cube",
    "make-cube",
    ":cylinder",
    "make-cylinder",
    ":segments",
    "cdddr",
    "\"don't know how to create ~a\"",
    ":move-to",
    ":world",
    ":inverse-transformation",
    ":primitive-bodies",
    ":replace-shape",
    "body*",
    "caadr",
    "cdadr",
    ":contact-vertices",
    ":contact-edges",
    "constraint-relation",
    ":constrained-body",
    ":constraining-body",
    ":constraints",
    "contact-to-constraint",
    ":possibly-contacting-vertices",
    ":possibly-contacting-faces",
    ":contactp",
    "constrained-point",
    ":position",
    ":hisface",
    ":to-convex",
    ":possibly-contacting-edges",
    ":contact-edge",
    ":test",
    "find",
    ":myneighborhood",
    "eps-v=",
    ":worldpos",
    "midpoint",
    ":vertices",
    "#(:center :radius)",
    "winged-edge",
    ":pface",
    ":nface",
    ":pvertex",
    ":nvertex",
    ":pwing",
    ":pcwing",
    ":nwing",
    ":ncwing",
    "acons",
    ":faces",
    ":edges",
    "cdr",
    "\"GEOMETRY\"",
    "\"GEOMETRY\"",
    "*package*",
    "\"no such package\"",
    "(add-wings)",
    ":geoclasses",
    "\"geoclasses.l\"",
    "require",
    "*edge-class*",
    ":vtype",
    ":global",
    "*face-class*",
    "*body-class*",
    "faceset",
    "\"(self class)\"",
    "\"(self class)\"",
    "\"(self class &rest x)\"",
    ":face",
    "\"(self class n)\"",
    "\"(self class)\"",
    "\"(self class)\"",
    ":edge",
    "\"(self class n)\"",
    ":vertex",
    "\"(self class n)\"",
    "\"(self class)\"",
    "\"(self class &optional new)\"",
    "\"(self class &optional new &aux ref)\"",
    "\"(self class &optional new &aux dif)\"",
    "\"(self class)\"",
    "\"(self class vp)\"",
    "\"(self class vp &aux visible-faces r)\"",
    ":contour-edges",
    "\"(self class vp &aux (visible-faces (send self :visible-faces vp)) r)\"",
    ":non-contour-edges",
    "\"(self class vp &aux (visible-faces (send self :visible-faces vp)) r)\"",
    "\"(self class b &optional (tolerance))\"",
    "\"(self class &optional (tolerance *contact-threshold*))\"",
    "\"(self class)\"",
    "\"(self class trans)\"",
    "\"(self class rad axis)\"",
    "\"(self class scale &optional (axis))\"",
    "\"args=(point vector)\nchecks intersection with a line which extends from POINT toward VECTOR direction.\"",
    "\"(self class target)\"",
    "\"(self class &rest initargs &key ((:faces f)) ((:edges e)) ((:vertices v)) (color nil) (reflectance) (diffusion) &allow-other-keys)\"",
    "body",
    "\"(self class trans)\"",
    "\"(self class rad axis)\"",
    "\"(self class scale &optional (axis))\"",
    ":euler",
    "\":euler returns the number of rings (passes)\"",
    ":perimeter",
    "\"(self class)\"",
    "\"(self class &optional (point #f(0.0 0.0 0.0)))\"",
    "\"(self class &optional (point (float-vector 0 0 0)))\"",
    ":world-centroid",
    "\"(self class)\"",
    "\"(self class)\"",
    "\":extream-point (vec) finds the farthest point along vec in vertices.\"",
    "\"length in vec direction\"",
    ":supporting-faces",
    "\"(self class &optional (gravity (floatvector 0.0 0.0 -1.0)))\"",
    "\"(self class cbox)\"",
    "\"(self class cbox)\"",
    "\"(self class f)\"",
    ":intersectp",
    "\"(self class b)\"",
    ":intersectp2",
    "\"(self class body2 &optional (tolerance *epsilon*))\"",
    "\"(self class point &optional (tolerance *coplanar-threshold*))\"",
    ":evert",
    "\"(self class)\"",
    "\"(self class)\"",
    "\"(self class &optional b f id)\"",
    "\"(self class)\"",
    "\"collects primitive bodies that defines this body in a list\"",
    "\"(self class &optional newcsg)\"",
    ":copy-csg",
    "\"(self class)\"",
    "\"(self class)\"",
    ":creation-form",
    "\"returns eus program that re-creates this body.\"",
    "\"(self class strm)\"",
    "\"(self class &rest initargs &key (approximated nil) (primitive nil) ((:csg csgform) nil) &allow-other-keys)\"",
    "\"(self class newbody)\"",
    "\"(self class &rest bodies)\"",
    "\"(self class &rest bodies)\"",
    ":*",
    "\"(self class &rest bodies)\"",
    "\"(self class)\"",
    ":constraint",
    "\"(self class b)\"",
    "\"(self class b)\"",
    "\"(self class b)\"",
    "\"(self class cbox)\"",
    "\"(self class cbox)\"",
    "\"(self class cbox)\"",
    ":radius",
    "sphere",
    "\"(self class &optional r)\"",
    "\"(self class point)\"",
    "\"(self class)\"",
    "\"(self class p1 p2)\"",
    ":closest-point",
    "\"(self class point)\"",
    ":intersect-with-body",
    "\"(self class bod)\"",
    "\"(self class &key (center (float-vector 0 0 0)) ((:radius r) 1.0))\"",
    "add-wings",
    "\"(bod)\"",
    ":geobody",
    "\"@(#)$Id: geobody.l,v 1.1.1.1 2003/11/20 07:46:28 eus Exp $\"",
    "provide",
  };
