/* ./irtcollada.c :  entry=irtcollada */
/* compiled by EusLisp 9.27() for Linux created on ip-10-0-1-214(Fri Apr 16 04:05:26 PST 2021) */
#include "eus.h"
#include "irtcollada.h"
#pragma init (register_irtcollada)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___irtcollada();
extern pointer build_quote_vector();
static int register_irtcollada()
  { add_module_initializer("___irtcollada", ___irtcollada);}

static pointer F5325symbol__string();
static pointer F5326__string();
static pointer F5327string_append();
static pointer F5328make_attr();
static pointer F5329make_xml();
static pointer F5330sxml__xml();
static pointer F5331xml_output_to_string_stream();
static pointer F5332cat_normal();
static pointer F5333cat_clark();
static pointer F5334eusmodel_description();
static pointer F5335verificate_unique_strings();
static pointer F5336eusmodel_link_specs();
static pointer F5337eusmodel_joint_specs();
static pointer F5338eusmodel_link_spec();
static pointer F5339eusmodel_mesh_spec();
static pointer F5340eusmodel_joint_spec();
static pointer F5341eusmodel_limit_spec();
static pointer F5342eusmodel_endcoords_specs();
static pointer F5343eusmodel_link_description();
static pointer F5344eusmodel_joint_description();
static pointer F5345eusmodel_endcoords_description();
static pointer F5346eusmodel_description__collada();
static pointer F5347setup_collada_filesystem();
static pointer F5348range2();
static pointer F5349eus2collada();
static pointer F5350collada_node_id();
static pointer F5351collada_node_name();
static pointer F5352links_description__collada_library_materials();
static pointer F5353link_description__collada_materials();
static pointer F5354mesh_description__collada_material();
static pointer F5355links_description__collada_library_effects();
static pointer F5356link_description__collada_effects();
static pointer F5357mesh_description__collada_effect();
static pointer F5358matrix__collada_string();
static pointer F5359find_parent_liks_from_link_description();
static pointer F5360eusmodel_description__collada_node_transformations();
static pointer F5361eusmodel_description__collada_node();
static pointer F5362eusmodel_description__collada_library_visual_scenes();
static pointer F5363mesh_description__instance_material();
static pointer F5364link_description__collada_bind_material();
static pointer F5365eusmodel_description__collada_library_kinematics_scenes();
static pointer F5366eusmodel_description__collada_library_kinematics_models();
static pointer F5367eusmodel_description__collada_kinematics_model();
static pointer F5368eusmodel_description__collada_library_physics_scenes();
static pointer F5369eusmodel_description__collada_library_physics_models();
static pointer F5370find_root_link_from_joints_description();
static pointer F5371find_link_from_links_description();
static pointer F5372eusmodel_description__collada_links();
static pointer F5373find_joint_from_link_description();
static pointer F5374find_child_link_descriptions();
static pointer F5375matrix__collada_rotate_vector();
static pointer F5376eusmodel_description__collada_library_articulated_systems();
static pointer F5377eusmodel_endcoords_description__openrave_manipulator();
static pointer F5378eusmodel_description__collada_links_tree();
static pointer F5379joints_description__collada_instance_joints();
static pointer F5380joint_description__collada_instance_joint();
static pointer F5381eusmodel_description__collada_library_joints();
static pointer F5382joints_description__collada_joints();
static pointer F5383collada_joint_id();
static pointer F5384joint_description__collada_joint();
static pointer F5385linear_joint_description__collada_joint();
static pointer F5386rotational_joint_description__collada_joint();
static pointer F5387eusmodel_description__collada_scene();
static pointer F5388eusmodel_description__collada_library_geometries();
static pointer F5389collada_geometry_id_base();
static pointer F5390collada_geometry_name_base();
static pointer F5391links_description__collada_geometries();
static pointer F5392mesh_object__collada_mesh();
static pointer F5393link_description__collada_geometry();
static pointer F5394mesh__collada_indices();
static pointer F5395mesh_vertices__collada_string();
static pointer F5396mesh_normals__collada_string();
static pointer F5397float_vector__collada_string();
static pointer F5398enum_integer_list();
static pointer F5399search_minimum_rotation_matrix();
static pointer F5400estimate_class_name();
static pointer F5401remove_directory_name();
static pointer F5402convert_irtmodel_to_collada();

/*symbol->string*/
static pointer F5325symbol__string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[0]);
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[1]); /*find*/
	if (w==NIL) goto IF5404;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[2]); /*string*/
	local[0]= w;
	goto IF5405;
IF5404:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[2]); /*string*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[2])(ctx,1,local+0,&ftab[2],fqv[3]); /*string-downcase*/
	local[0]= w;
IF5405:
	w = local[0];
	local[0]= w;
BLK5403:
	ctx->vsp=local; return(local[0]);}

/*->string*/
static pointer F5326__string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= fqv[4];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK5406:
	ctx->vsp=local; return(local[0]);}

/*string-append*/
static pointer F5327string_append(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST5408:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= (pointer)get_sym_func(fqv[5]);
	local[2]= loadglobal(fqv[2]);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[0]= w;
BLK5407:
	ctx->vsp=local; return(local[0]);}

/*make-attr*/
static pointer F5328make_attr(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]!=NIL) goto IF5410;
	local[0]= argv[1];
	goto IF5411;
IF5410:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= argv[1];
	local[2]= fqv[6];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)F5325symbol__string(ctx,1,local+3); /*symbol->string*/
	local[3]= w;
	local[4]= fqv[7];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(*ftab[3])(ctx,1,local+5,&ftab[3],fqv[8]); /*cadar*/
	if (!isstring(w)) goto IF5412;
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(*ftab[3])(ctx,1,local+5,&ftab[3],fqv[8]); /*cadar*/
	local[5]= w;
	goto IF5413;
IF5412:
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(*ftab[3])(ctx,1,local+5,&ftab[3],fqv[8]); /*cadar*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)F5326__string(ctx,1,local+5); /*->string*/
	local[5]= w;
IF5413:
	local[6]= fqv[9];
	ctx->vsp=local+7;
	w=(pointer)F5327string_append(ctx,6,local+1); /*string-append*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F5328make_attr(ctx,2,local+0); /*make-attr*/
	local[0]= w;
IF5411:
	w = local[0];
	local[0]= w;
BLK5409:
	ctx->vsp=local; return(local[0]);}

/*make-xml*/
static pointer F5329make_xml(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[0];
	if (!isstring(w)) goto CON5416;
	local[0]= argv[1];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)APPEND(ctx,3,local+0); /*append*/
	local[0]= w;
	goto CON5415;
CON5416:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON5417;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!issymbol(w)) goto CON5417;
	if (argv[0]==NIL) goto CON5417;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	w=(pointer)F5325symbol__string(ctx,1,local+0); /*symbol->string*/
	local[0]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF5418;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LISTP(ctx,1,local+1); /*listp*/
	if (w==NIL) goto IF5418;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,1,local+1,&ftab[4],fqv[10]); /*caadr*/
	local[1]= w;
	if (fqv[11]!=local[1]) goto IF5418;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	local[2]= argv[1];
	local[3]= fqv[12];
	local[4]= local[0];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(*ftab[5])(ctx,1,local+5,&ftab[5],fqv[13]); /*cdadr*/
	local[5]= w;
	local[6]= fqv[14];
	ctx->vsp=local+7;
	w=(pointer)F5328make_attr(ctx,2,local+5); /*make-attr*/
	local[5]= w;
	local[6]= fqv[15];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,4,local+3); /*list*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPEND(ctx,2,local+2); /*append*/
	local[2]= w;
	local[3]= fqv[16];
	local[4]= local[0];
	local[5]= fqv[17];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[3]= w;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)APPEND(ctx,2,local+3); /*append*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)F5329make_xml(ctx,3,local+1); /*make-xml*/
	local[1]= w;
	goto IF5419;
IF5418:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	local[2]= argv[1];
	local[3]= fqv[12];
	local[4]= local[0];
	local[5]= fqv[15];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPEND(ctx,2,local+2); /*append*/
	local[2]= w;
	local[3]= fqv[16];
	local[4]= local[0];
	local[5]= fqv[17];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[3]= w;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)APPEND(ctx,2,local+3); /*append*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)F5329make_xml(ctx,3,local+1); /*make-xml*/
	local[1]= w;
IF5419:
	w = local[1];
	local[0]= w;
	goto CON5415;
CON5417:
	if (argv[0]==NIL) goto CON5420;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON5420;
	local[0]= NIL;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[1];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)F5329make_xml(ctx,3,local+1); /*make-xml*/
	local[1]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	local[3]= NIL;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)F5329make_xml(ctx,3,local+2); /*make-xml*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F5329make_xml(ctx,3,local+0); /*make-xml*/
	local[0]= w;
	goto CON5415;
CON5420:
	local[0]= argv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	local[0]= w;
	goto CON5415;
CON5421:
	local[0]= NIL;
CON5415:
	w = local[0];
	local[0]= w;
BLK5414:
	ctx->vsp=local; return(local[0]);}

/*sxml->xml*/
static pointer F5330sxml__xml(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= NIL;
	local[2]= NIL;
	ctx->vsp=local+3;
	w=(pointer)F5329make_xml(ctx,3,local+0); /*make-xml*/
	local[0]= w;
BLK5422:
	ctx->vsp=local; return(local[0]);}

/*xml-output-to-string-stream*/
static pointer F5331xml_output_to_string_stream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[1];
WHL5425:
	if (local[1]==NIL) goto WHX5426;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	w = local[0];
	if (!isstring(w)) goto IF5429;
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,2,local+2); /*format*/
	local[2]= w;
	goto IF5430;
IF5429:
	local[2]= argv[0];
	local[3]= local[0];
	local[4]= local[3];
	if (fqv[12]!=local[4]) goto IF5432;
	local[4]= fqv[18];
	goto IF5433;
IF5432:
	local[4]= local[3];
	if (fqv[16]!=local[4]) goto IF5434;
	local[4]= fqv[19];
	goto IF5435;
IF5434:
	local[4]= local[3];
	w = fqv[20];
	if (memq(local[4],w)==NIL) goto IF5436;
	local[4]= fqv[21];
	goto IF5437;
IF5436:
	local[4]= NIL;
IF5437:
IF5435:
IF5433:
	w = local[4];
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,2,local+2); /*format*/
	local[2]= w;
IF5430:
	goto WHL5425;
WHX5426:
	local[2]= NIL;
BLK5427:
	w = NIL;
	local[0]= w;
BLK5423:
	ctx->vsp=local; return(local[0]);}

/*cat-normal*/
static pointer F5332cat_normal(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]!=NIL) goto CON5440;
	local[0]= argv[1];
	goto CON5439;
CON5440:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!isstring(w)) goto CON5441;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= argv[1];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)F5327string_append(ctx,2,local+1); /*string-append*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F5332cat_normal(ctx,2,local+0); /*cat-normal*/
	local[0]= w;
	goto CON5439;
CON5441:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= argv[1];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= local[2];
	if (fqv[12]!=local[3]) goto IF5444;
	local[3]= fqv[22];
	goto IF5445;
IF5444:
	local[3]= local[2];
	if (fqv[16]!=local[3]) goto IF5446;
	local[3]= fqv[23];
	goto IF5447;
IF5446:
	local[3]= local[2];
	w = fqv[24];
	if (memq(local[3],w)==NIL) goto IF5448;
	local[3]= fqv[25];
	goto IF5449;
IF5448:
	local[3]= NIL;
IF5449:
IF5447:
IF5445:
	w = local[3];
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F5327string_append(ctx,2,local+1); /*string-append*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F5332cat_normal(ctx,2,local+0); /*cat-normal*/
	local[0]= w;
	goto CON5439;
CON5442:
	local[0]= NIL;
CON5439:
	w = local[0];
	local[0]= w;
BLK5438:
	ctx->vsp=local; return(local[0]);}

/*cat-clark*/
static pointer F5333cat_clark(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[0]!=NIL) goto CON5452;
	local[0]= argv[1];
	goto CON5451;
CON5452:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!isstring(w)) goto CON5453;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= argv[1];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)F5327string_append(ctx,2,local+1); /*string-append*/
	local[1]= w;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)F5333cat_clark(ctx,3,local+0); /*cat-clark*/
	local[0]= w;
	goto CON5451;
CON5453:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= local[0];
	if (fqv[12]!=local[1]) goto IF5456;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	local[2]= argv[1];
	local[3]= fqv[26];
	ctx->vsp=local+4;
	w=(pointer)F5327string_append(ctx,2,local+2); /*string-append*/
	local[2]= w;
	local[3]= argv[2];
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)F5333cat_clark(ctx,3,local+1); /*cat-clark*/
	local[1]= w;
	goto IF5457;
IF5456:
	local[1]= local[0];
	if (fqv[16]!=local[1]) goto IF5458;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	local[2]= argv[1];
	local[3]= fqv[27];
	ctx->vsp=local+4;
	w=(pointer)F5327string_append(ctx,2,local+2); /*string-append*/
	local[2]= w;
	local[3]= argv[2];
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)F5333cat_clark(ctx,3,local+1); /*cat-clark*/
	local[1]= w;
	goto IF5459;
IF5458:
	local[1]= local[0];
	w = fqv[28];
	if (memq(local[1],w)==NIL) goto IF5460;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	local[2]= argv[1];
	local[3]= fqv[29];
	local[4]= argv[2];
	local[5]= makeint((eusinteger_t)32L);
	ctx->vsp=local+6;
	w=(*ftab[6])(ctx,2,local+4,&ftab[6],fqv[30]); /*make-string*/
	local[4]= w;
	local[5]= fqv[31];
	ctx->vsp=local+6;
	w=(pointer)F5327string_append(ctx,4,local+2); /*string-append*/
	local[2]= w;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)F5333cat_clark(ctx,3,local+1); /*cat-clark*/
	local[1]= w;
	goto IF5461;
IF5460:
	local[1]= NIL;
IF5461:
IF5459:
IF5457:
	w = local[1];
	local[0]= w;
	goto CON5451;
CON5454:
	local[0]= NIL;
CON5451:
	w = local[0];
	local[0]= w;
BLK5450:
	ctx->vsp=local; return(local[0]);}

/*eusmodel-description*/
static pointer F5334eusmodel_description(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[32];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[33];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= (pointer)get_sym_func(fqv[2]);
	local[3]= local[0];
	local[4]= fqv[34];
	ctx->vsp=local+5;
	w=(*ftab[7])(ctx,2,local+3,&ftab[7],fqv[35]); /*send-all*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F5335verificate_unique_strings(ctx,1,local+2); /*verificate-unique-strings*/
	local[2]= (pointer)get_sym_func(fqv[2]);
	local[3]= local[1];
	local[4]= fqv[34];
	ctx->vsp=local+5;
	w=(*ftab[7])(ctx,2,local+3,&ftab[7],fqv[35]); /*send-all*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F5335verificate_unique_strings(ctx,1,local+2); /*verificate-unique-strings*/
	local[2]= makeint((eusinteger_t)0L);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
WHL5464:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX5465;
	local[4]= local[1];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	local[5]= local[2];
	local[6]= fqv[36];
	ctx->vsp=local+7;
	w=(pointer)PUTPROP(ctx,3,local+4); /*putprop*/
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL5464;
WHX5465:
	local[4]= NIL;
BLK5466:
	w = NIL;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F5336eusmodel_link_specs(ctx,1,local+2); /*eusmodel-link-specs*/
	local[2]= w;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F5337eusmodel_joint_specs(ctx,1,local+3); /*eusmodel-joint-specs*/
	local[3]= w;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F5342eusmodel_endcoords_specs(ctx,1,local+4); /*eusmodel-endcoords-specs*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,3,local+2); /*list*/
	local[0]= w;
BLK5462:
	ctx->vsp=local; return(local[0]);}

/*verificate-unique-strings*/
static pointer F5335verificate_unique_strings(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[37];
	local[3]= (pointer)get_sym_func(fqv[38]);
	ctx->vsp=local+4;
	w=(*ftab[8])(ctx,3,local+1,&ftab[8],fqv[39]); /*remove-duplicates*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	if (w==local[0]) goto IF5468;
	local[0]= fqv[40];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,2,local+0); /*error*/
	local[0]= w;
	goto IF5469;
IF5468:
	local[0]= T;
IF5469:
	w = local[0];
	local[0]= w;
BLK5467:
	ctx->vsp=local; return(local[0]);}

/*eusmodel-link-specs*/
static pointer F5336eusmodel_link_specs(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= (pointer)get_sym_func(fqv[41]);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	local[0]= w;
BLK5470:
	ctx->vsp=local; return(local[0]);}

/*eusmodel-joint-specs*/
static pointer F5337eusmodel_joint_specs(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= (pointer)get_sym_func(fqv[42]);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	local[0]= w;
BLK5471:
	ctx->vsp=local; return(local[0]);}

/*eusmodel-link-spec*/
static pointer F5338eusmodel_link_spec(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= *(ovafptr(argv[0],fqv[43]));
	local[1]= argv[0];
	local[2]= fqv[44];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
WHL5473:
	local[3]= local[2];
	local[4]= fqv[45];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	if (w==NIL) goto WHX5474;
	local[3]= local[2];
	local[4]= fqv[45];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[2] = w;
	goto WHL5473;
WHX5474:
	local[3]= NIL;
BLK5475:
	local[3]= local[2];
	local[4]= fqv[32];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= fqv[46];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[47];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= local[3];
	local[7]= fqv[48];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= local[2];
	local[7]= fqv[49];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[3] = w;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[9])(ctx,1,local+6,&ftab[9],fqv[50]); /*user::sv-decompose*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)F5399search_minimum_rotation_matrix(ctx,1,local+6); /*search-minimum-rotation-matrix*/
	local[4] = w;
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)TRANSPOSE(ctx,1,local+6); /*transpose*/
	local[6]= w;
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)MATTIMES(ctx,2,local+6); /*m**/
	local[6]= w;
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)MATTIMES(ctx,2,local+6); /*m**/
	local[5] = w;
	local[6]= makeflt(9.9999999999999985548644e-10);
	local[7]= local[5];
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,3,local+7); /*aref*/
	local[7]= w;
	local[8]= local[5];
	local[9]= makeint((eusinteger_t)1L);
	local[10]= makeint((eusinteger_t)1L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	local[9]= local[5];
	local[10]= makeint((eusinteger_t)2L);
	local[11]= makeint((eusinteger_t)2L);
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,3,local+9); /*aref*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,3,local+7); /*float-vector*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SCALEVEC(ctx,2,local+6); /*scale*/
	local[5] = w;
	local[6]= local[3];
	local[7]= fqv[51];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= fqv[34];
	local[7]= argv[0];
	local[8]= fqv[34];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[1])(ctx,1,local+7,&ftab[1],fqv[2]); /*string*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[52];
	local[8]= argv[0];
	local[9]= fqv[45];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= local[8];
	local[10]= fqv[49];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[53];
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(pointer)F5339eusmodel_mesh_spec(ctx,1,local+9); /*eusmodel-mesh-spec*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[54];
	w = local[3];
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[55];
	local[11]= argv[0];
	local[12]= fqv[56];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	local[12]= makeflt(1.0000000000000000000000e+03);
	ctx->vsp=local+13;
	w=(pointer)QUOTIENT(ctx,2,local+11); /*/*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[57];
	w = local[5];
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,6,local+6); /*list*/
	local[0]= w;
BLK5472:
	ctx->vsp=local; return(local[0]);}

/*eusmodel-mesh-spec*/
static pointer F5339eusmodel_mesh_spec(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[58];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO5477,env,argv,local);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[0]= w;
BLK5476:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5477(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[59]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[60];
	local[3]= fqv[61];
	local[4]= argv[0];
	local[5]= NIL;
	ctx->vsp=local+6;
	w=(*ftab[10])(ctx,2,local+4,&ftab[10],fqv[62]); /*geometry:body-to-triangles*/
	local[4]= w;
	local[5]= fqv[61];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[63];
	local[3]= argv[0];
	local[4]= fqv[64];
	ctx->vsp=local+5;
	w=(pointer)GETPROP(ctx,2,local+3); /*get*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= local[0];
	local[2]= fqv[65];
	local[3]= argv[0];
	local[4]= fqv[47];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= fqv[66];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*eusmodel-joint-spec*/
static pointer F5340eusmodel_joint_spec(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[34];
	local[1]= argv[0];
	local[2]= fqv[34];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,1,local+1,&ftab[1],fqv[2]); /*string*/
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	local[1]= fqv[67];
	local[2]= argv[0];
	local[3]= loadglobal(fqv[68]);
	ctx->vsp=local+4;
	w=(pointer)DERIVEDP(ctx,2,local+2); /*derivedp*/
	if (w==NIL) goto CON5481;
	local[2]= fqv[69];
	goto CON5480;
CON5481:
	local[2]= argv[0];
	local[3]= loadglobal(fqv[70]);
	ctx->vsp=local+4;
	w=(pointer)DERIVEDP(ctx,2,local+2); /*derivedp*/
	if (w==NIL) goto CON5482;
	local[2]= fqv[71];
	goto CON5480;
CON5482:
	local[2]= NIL;
CON5480:
	w = local[2];
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[72];
	local[3]= argv[0];
	local[4]= fqv[36];
	ctx->vsp=local+5;
	w=(pointer)GETPROP(ctx,2,local+3); /*get*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[73];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F5341eusmodel_limit_spec(ctx,1,local+4); /*eusmodel-limit-spec*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[74];
	local[5]= *(ovafptr(argv[0],fqv[75]));
	local[6]= local[5];
	if (fqv[76]!=local[6]) goto IF5484;
	local[6]= fqv[77];
	goto IF5485;
IF5484:
	local[6]= local[5];
	if (fqv[78]!=local[6]) goto IF5486;
	local[6]= fqv[79];
	goto IF5487;
IF5486:
	local[6]= local[5];
	if (fqv[80]!=local[6]) goto IF5488;
	local[6]= fqv[81];
	goto IF5489;
IF5488:
	local[6]= local[5];
	if (fqv[82]!=local[6]) goto IF5490;
	local[6]= fqv[83];
	goto IF5491;
IF5490:
	local[6]= local[5];
	if (fqv[84]!=local[6]) goto IF5492;
	local[6]= fqv[85];
	goto IF5493;
IF5492:
	local[6]= local[5];
	if (fqv[86]!=local[6]) goto IF5494;
	local[6]= fqv[87];
	goto IF5495;
IF5494:
	local[6]= local[5];
	if (fqv[88]!=local[6]) goto IF5496;
	local[6]= fqv[89];
	goto IF5497;
IF5496:
	local[6]= local[5];
	if (fqv[90]!=local[6]) goto IF5498;
	local[6]= fqv[91];
	goto IF5499;
IF5498:
	local[6]= local[5];
	if (fqv[92]!=local[6]) goto IF5500;
	local[6]= fqv[93];
	goto IF5501;
IF5500:
	if (T==NIL) goto IF5502;
	local[6]= *(ovafptr(argv[0],fqv[75]));
	ctx->vsp=local+7;
	w=(pointer)LISTP(ctx,1,local+6); /*listp*/
	if (w==NIL) goto IF5504;
	local[6]= fqv[94];
	goto IF5505;
IF5504:
	local[6]= *(ovafptr(argv[0],fqv[75]));
IF5505:
	goto IF5503;
IF5502:
	local[6]= NIL;
IF5503:
IF5501:
IF5499:
IF5497:
IF5495:
IF5493:
IF5491:
IF5489:
IF5487:
IF5485:
	w = local[6];
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[45];
	local[6]= argv[0];
	local[7]= fqv[95];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= fqv[34];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,1,local+6,&ftab[1],fqv[2]); /*string*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[96];
	local[7]= argv[0];
	local[8]= fqv[97];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= fqv[34];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[1])(ctx,1,local+7,&ftab[1],fqv[2]); /*string*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,7,local+0); /*list*/
	local[0]= w;
BLK5479:
	ctx->vsp=local; return(local[0]);}

/*eusmodel-limit-spec*/
static pointer F5341eusmodel_limit_spec(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[98];
	local[1]= argv[0];
	local[2]= fqv[99];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[11])(ctx,1,local+1,&ftab[11],fqv[100]); /*deg2rad*/
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	local[1]= fqv[101];
	local[2]= argv[0];
	local[3]= fqv[102];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[11])(ctx,1,local+2,&ftab[11],fqv[100]); /*deg2rad*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
BLK5506:
	ctx->vsp=local; return(local[0]);}

/*eusmodel-endcoords-specs*/
static pointer F5342eusmodel_endcoords_specs(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,FLET5508,env,argv,local);
	local[1]= fqv[103];
	w = local[0];
	ctx->vsp=local+2;
	w=FLET5508(ctx,1,local+1,w);
	local[1]= w;
	local[2]= fqv[104];
	w = local[0];
	ctx->vsp=local+3;
	w=FLET5508(ctx,1,local+2,w);
	local[2]= w;
	local[3]= fqv[105];
	w = local[0];
	ctx->vsp=local+4;
	w=FLET5508(ctx,1,local+3,w);
	local[3]= w;
	local[4]= fqv[106];
	w = local[0];
	ctx->vsp=local+5;
	w=FLET5508(ctx,1,local+4,w);
	local[4]= w;
	local[5]= fqv[107];
	w = local[0];
	ctx->vsp=local+6;
	w=FLET5508(ctx,1,local+5,w);
	local[5]= w;
	local[6]= fqv[108];
	local[7]= (pointer)get_sym_func(fqv[2]);
	local[8]= local[1];
	local[9]= fqv[34];
	ctx->vsp=local+10;
	w=(*ftab[7])(ctx,2,local+8,&ftab[7],fqv[35]); /*send-all*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MAPCAR(ctx,2,local+7); /*mapcar*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[109];
	local[8]= (pointer)get_sym_func(fqv[2]);
	local[9]= local[2];
	local[10]= fqv[34];
	ctx->vsp=local+11;
	w=(*ftab[7])(ctx,2,local+9,&ftab[7],fqv[35]); /*send-all*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MAPCAR(ctx,2,local+8); /*mapcar*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[110];
	local[9]= (pointer)get_sym_func(fqv[2]);
	local[10]= local[3];
	local[11]= fqv[34];
	ctx->vsp=local+12;
	w=(*ftab[7])(ctx,2,local+10,&ftab[7],fqv[35]); /*send-all*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)MAPCAR(ctx,2,local+9); /*mapcar*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[111];
	local[10]= (pointer)get_sym_func(fqv[2]);
	local[11]= local[4];
	local[12]= fqv[34];
	ctx->vsp=local+13;
	w=(*ftab[7])(ctx,2,local+11,&ftab[7],fqv[35]); /*send-all*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)MAPCAR(ctx,2,local+10); /*mapcar*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[112];
	local[11]= (pointer)get_sym_func(fqv[2]);
	local[12]= local[5];
	local[13]= fqv[34];
	ctx->vsp=local+14;
	w=(*ftab[7])(ctx,2,local+12,&ftab[7],fqv[35]); /*send-all*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)MAPCAR(ctx,2,local+11); /*mapcar*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,5,local+6); /*list*/
	local[0]= w;
BLK5507:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET5508(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[12])(ctx,2,local+0,&ftab[12],fqv[113]); /*find-method*/
	if (w==NIL) goto IF5509;
	local[0]= env->c.clo.env1[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	if (local[0]==NIL) goto IF5511;
	local[1]= env->c.clo.env1[0];
	local[2]= argv[0];
	local[3]= fqv[114];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	if (w==NIL) goto IF5511;
	local[1]= env->c.clo.env1[0];
	local[2]= argv[0];
	local[3]= fqv[114];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[45];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (w==NIL) goto IF5511;
	local[1]= env->c.clo.env1[0];
	local[2]= fqv[115];
	local[3]= env->c.clo.env1[0];
	local[4]= argv[0];
	local[5]= fqv[114];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= fqv[45];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[95];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	w = local[1];
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[1]= w;
	goto IF5512;
IF5511:
	local[1]= NIL;
IF5512:
	w = local[1];
	local[0]= w;
	goto IF5510;
IF5509:
	local[0]= NIL;
IF5510:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*eusmodel-link-description*/
static pointer F5343eusmodel_link_description(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK5513:
	ctx->vsp=local; return(local[0]);}

/*eusmodel-joint-description*/
static pointer F5344eusmodel_joint_description(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK5514:
	ctx->vsp=local; return(local[0]);}

/*eusmodel-endcoords-description*/
static pointer F5345eusmodel_endcoords_description(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK5515:
	ctx->vsp=local; return(local[0]);}

/*eusmodel-description->collada*/
static pointer F5346eusmodel_description__collada(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[116], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY5517;
	local[0] = makeflt(1.0000000000000000208167e-03);
KEY5517:
	local[1]= fqv[117];
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,1,local+1,&ftab[13],fqv[118]); /*warn*/
	local[1]= fqv[119];
	local[2]= fqv[11];
	local[3]= fqv[120];
	local[4]= fqv[121];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[122];
	local[5]= fqv[123];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[124];
	local[4]= fqv[125];
	local[5]= fqv[126];
	local[6]= fqv[127];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[128];
	local[6]= fqv[11];
	local[7]= fqv[129];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[130];
	local[9]= fqv[131];
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
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[132];
	local[7]= fqv[133];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
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
	local[4]= argv[0];
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)F5362eusmodel_description__collada_library_visual_scenes(ctx,2,local+4); /*eusmodel-description->collada-library-visual-scenes*/
	local[4]= w;
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)F5381eusmodel_description__collada_library_joints(ctx,1,local+5); /*eusmodel-description->collada-library-joints*/
	local[5]= w;
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)F5343eusmodel_link_description(ctx,1,local+6); /*eusmodel-link-description*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)F5355links_description__collada_library_effects(ctx,1,local+6); /*links-description->collada-library-effects*/
	local[6]= w;
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)F5343eusmodel_link_description(ctx,1,local+7); /*eusmodel-link-description*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)F5352links_description__collada_library_materials(ctx,1,local+7); /*links-description->collada-library-materials*/
	local[7]= w;
	local[8]= argv[0];
	local[9]= argv[1];
	ctx->vsp=local+10;
	w=(pointer)F5366eusmodel_description__collada_library_kinematics_models(ctx,2,local+8); /*eusmodel-description->collada-library-kinematics-models*/
	local[8]= w;
	local[9]= argv[0];
	local[10]= argv[1];
	ctx->vsp=local+11;
	w=(pointer)F5365eusmodel_description__collada_library_kinematics_scenes(ctx,2,local+9); /*eusmodel-description->collada-library-kinematics-scenes*/
	local[9]= w;
	local[10]= argv[0];
	local[11]= argv[1];
	ctx->vsp=local+12;
	w=(pointer)F5368eusmodel_description__collada_library_physics_scenes(ctx,2,local+10); /*eusmodel-description->collada-library-physics-scenes*/
	local[10]= w;
	local[11]= argv[0];
	local[12]= argv[1];
	ctx->vsp=local+13;
	w=(pointer)F5369eusmodel_description__collada_library_physics_models(ctx,2,local+11); /*eusmodel-description->collada-library-physics-models*/
	local[11]= w;
	local[12]= argv[1];
	ctx->vsp=local+13;
	w=(pointer)F5388eusmodel_description__collada_library_geometries(ctx,1,local+12); /*eusmodel-description->collada-library-geometries*/
	local[12]= w;
	local[13]= argv[1];
	local[14]= argv[0];
	ctx->vsp=local+15;
	w=(pointer)F5376eusmodel_description__collada_library_articulated_systems(ctx,2,local+13); /*eusmodel-description->collada-library-articulated-systems*/
	local[13]= w;
	local[14]= argv[1];
	ctx->vsp=local+15;
	w=(pointer)F5387eusmodel_description__collada_scene(ctx,1,local+14); /*eusmodel-description->collada-scene*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK5516:
	ctx->vsp=local; return(local[0]);}

/*setup-collada-filesystem*/
static pointer F5347setup_collada_filesystem(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(*ftab[14])(ctx,1,local+0,&ftab[14],fqv[134]); /*probe-file*/
	local[0]= w;
	if (fqv[135]==local[0]) goto IF5519;
	local[0]= fqv[136];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,2,local+0); /*error*/
	local[0]= w;
	goto IF5520;
IF5519:
	local[0]= NIL;
IF5520:
	w = local[0];
	local[0]= w;
BLK5518:
	ctx->vsp=local; return(local[0]);}

/*range2*/
static pointer F5348range2(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	if (w==NIL) goto IF5522;
	local[0]= fqv[137];
	goto IF5523;
IF5522:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)SUB1(ctx,1,local+0); /*1-*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)F5348range2(ctx,1,local+0); /*range2*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	local[0]= w;
IF5523:
	w = local[0];
	local[0]= w;
BLK5521:
	ctx->vsp=local; return(local[0]);}

/*eus2collada*/
static pointer F5349eus2collada(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[138], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY5525;
	local[0] = makeflt(1.0000000000000000208167e-03);
KEY5525:
	if (n & (1<<1)) goto KEY5526;
	local[1] = fqv[139];
KEY5526:
	local[2]= argv[0];
	local[3]= fqv[34];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	if (local[2]!=NIL) goto IF5527;
	local[3]= fqv[140];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
	goto IF5528;
IF5527:
	local[3]= NIL;
IF5528:
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)GETCLASS(ctx,1,local+3); /*class*/
	local[3]= w;
	local[4]= fqv[34];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	if (fqv[141]==local[3]) goto OR5531;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)GETCLASS(ctx,1,local+3); /*class*/
	local[3]= w;
	local[4]= fqv[34];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	if (fqv[142]==local[3]) goto OR5531;
	goto IF5529;
OR5531:
	local[3]= loadglobal(fqv[143]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[60];
	local[6]= fqv[34];
	local[7]= argv[0];
	local[8]= fqv[34];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = local[3];
	local[3]= w;
	local[4]= loadglobal(fqv[144]);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= local[4];
	local[6]= fqv[60];
	ctx->vsp=local+7;
	w=(*ftab[15])(ctx,0,local+7,&ftab[15],fqv[145]); /*geometry:make-cascoords*/
	local[7]= w;
	local[8]= fqv[58];
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	w = local[4];
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[4]= w;
	local[5]= w;
	*(ovafptr(local[3],fqv[146])) = local[5];
	local[4]= local[3];
	local[5]= fqv[147];
	local[6]= local[3];
	local[7]= fqv[32];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= local[3];
	local[5]= fqv[148];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	w = local[3];
	argv[0] = w;
	local[3]= argv[0];
	goto IF5530;
IF5529:
	local[3]= NIL;
IF5530:
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F5334eusmodel_description(ctx,1,local+3); /*eusmodel-description*/
	local[3]= w;
	local[4]= local[2];
	local[5]= local[3];
	local[6]= fqv[149];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)F5346eusmodel_description__collada(ctx,4,local+4); /*eusmodel-description->collada*/
	local[4]= w;
	local[5]= local[2];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)F5347setup_collada_filesystem(ctx,2,local+5); /*setup-collada-filesystem*/
	local[5]= NIL;
	local[6]= fqv[150];
	local[7]= argv[1];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,4,local+5); /*format*/
	local[5]= w;
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)F5330sxml__xml(ctx,1,local+6); /*sxml->xml*/
	local[6]= w;
	local[7]= local[5];
	local[8]= fqv[151];
	local[9]= fqv[152];
	ctx->vsp=local+10;
	w=(*ftab[16])(ctx,3,local+7,&ftab[16],fqv[153]); /*open*/
	local[7]= w;
	ctx->vsp=local+8;
	w = makeclosure(codevec,quotevec,UWP5534,env,argv,local);
	local[8]=(pointer)(ctx->protfp); local[9]=w;
	ctx->protfp=(struct protectframe *)(local+8);
	local[10]= local[7];
	local[11]= fqv[154];
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,2,local+10); /*format*/
	local[10]= local[7];
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)F5331xml_output_to_string_stream(ctx,2,local+10); /*xml-output-to-string-stream*/
	w = NIL;
	ctx->vsp=local+10;
	UWP5534(ctx,0,local+10,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK5524:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP5534(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[7];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*collada-node-id*/
static pointer F5350collada_node_id(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= fqv[155];
	local[2]= fqv[34];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[17])(ctx,2,local+2,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK5535:
	ctx->vsp=local; return(local[0]);}

/*collada-node-name*/
static pointer F5351collada_node_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= fqv[157];
	local[2]= fqv[34];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[17])(ctx,2,local+2,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK5536:
	ctx->vsp=local; return(local[0]);}

/*links-description->collada-library-materials*/
static pointer F5352links_description__collada_library_materials(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[158];
	local[1]= fqv[11];
	local[2]= fqv[159];
	local[3]= fqv[160];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= (pointer)get_sym_func(fqv[161]);
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)APPEND(ctx,2,local+2); /*append*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK5537:
	ctx->vsp=local; return(local[0]);}

/*link-description->collada-materials*/
static pointer F5353link_description__collada_materials(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[53];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= NIL;
	local[2]= fqv[162];
	local[3]= fqv[34];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[17])(ctx,2,local+3,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	local[2]= NIL;
	local[3]= fqv[163];
	local[4]= fqv[34];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(*ftab[17])(ctx,2,local+4,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)F5348range2(ctx,1,local+3); /*range2*/
	local[3]= w;
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO5539,env,argv,local);
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[0]= w;
BLK5538:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5539(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= fqv[164];
	local[2]= env->c.clo.env2[1];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
	local[1]= NIL;
	local[2]= fqv[165];
	local[3]= env->c.clo.env2[2];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,4,local+1); /*format*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F5354mesh_description__collada_material(ctx,2,local+0); /*mesh-description->collada-material*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*mesh-description->collada-material*/
static pointer F5354mesh_description__collada_material(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[166];
	local[1]= fqv[11];
	local[2]= fqv[159];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[167];
	local[3]= fqv[11];
	local[4]= fqv[168];
	local[5]= NIL;
	local[6]= fqv[169];
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,3,local+5); /*format*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK5540:
	ctx->vsp=local; return(local[0]);}

/*links-description->collada-library-effects*/
static pointer F5355links_description__collada_library_effects(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[170];
	local[1]= fqv[11];
	local[2]= fqv[159];
	local[3]= fqv[171];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= (pointer)get_sym_func(fqv[172]);
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)APPEND(ctx,2,local+2); /*append*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK5541:
	ctx->vsp=local; return(local[0]);}

/*link-description->collada-effects*/
static pointer F5356link_description__collada_effects(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[53];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= NIL;
	local[2]= fqv[173];
	local[3]= fqv[34];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[17])(ctx,2,local+3,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F5348range2(ctx,1,local+2); /*range2*/
	local[2]= w;
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO5543,env,argv,local);
	local[4]= local[0];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,3,local+3); /*mapcar*/
	local[0]= w;
BLK5542:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5543(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= NIL;
	local[2]= fqv[174];
	local[3]= env->c.clo.env2[1];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,4,local+1); /*format*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F5357mesh_description__collada_effect(ctx,2,local+0); /*mesh-description->collada-effect*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*mesh-description->collada-effect*/
static pointer F5357mesh_description__collada_effect(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[64];
	ctx->vsp=local+2;
	w=(pointer)GETPROP(ctx,2,local+0); /*get*/
	if (w!=NIL) goto IF5545;
	local[0]= fqv[175];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,2,local+0); /*error*/
	local[0]= w;
	goto IF5546;
IF5545:
	local[0]= NIL;
IF5546:
	local[0]= fqv[176];
	local[1]= fqv[11];
	local[2]= fqv[159];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[177];
	local[3]= fqv[178];
	local[4]= fqv[11];
	local[5]= fqv[179];
	local[6]= fqv[180];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[181];
	local[6]= fqv[182];
	local[7]= fqv[183];
	local[8]= NIL;
	local[9]= fqv[184];
	local[10]= argv[0];
	local[11]= fqv[64];
	ctx->vsp=local+12;
	w=(pointer)GETPROP(ctx,2,local+10); /*get*/
	local[10]= w;
	local[11]= makeint((eusinteger_t)0L);
	ctx->vsp=local+12;
	w=(pointer)ELT(ctx,2,local+10); /*elt*/
	local[10]= w;
	local[11]= argv[0];
	local[12]= fqv[64];
	ctx->vsp=local+13;
	w=(pointer)GETPROP(ctx,2,local+11); /*get*/
	local[11]= w;
	local[12]= makeint((eusinteger_t)1L);
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	local[12]= argv[0];
	local[13]= fqv[64];
	ctx->vsp=local+14;
	w=(pointer)GETPROP(ctx,2,local+12); /*get*/
	local[12]= w;
	local[13]= makeint((eusinteger_t)2L);
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,5,local+8); /*format*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[185];
	local[8]= fqv[183];
	local[9]= NIL;
	local[10]= fqv[186];
	local[11]= argv[0];
	local[12]= fqv[64];
	ctx->vsp=local+13;
	w=(pointer)GETPROP(ctx,2,local+11); /*get*/
	local[11]= w;
	local[12]= makeint((eusinteger_t)0L);
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	local[12]= argv[0];
	local[13]= fqv[64];
	ctx->vsp=local+14;
	w=(pointer)GETPROP(ctx,2,local+12); /*get*/
	local[12]= w;
	local[13]= makeint((eusinteger_t)1L);
	ctx->vsp=local+14;
	w=(pointer)ELT(ctx,2,local+12); /*elt*/
	local[12]= w;
	local[13]= argv[0];
	local[14]= fqv[64];
	ctx->vsp=local+15;
	w=(pointer)GETPROP(ctx,2,local+13); /*get*/
	local[13]= w;
	local[14]= makeint((eusinteger_t)2L);
	ctx->vsp=local+15;
	w=(pointer)ELT(ctx,2,local+13); /*elt*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,5,local+9); /*format*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
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
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
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
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK5544:
	ctx->vsp=local; return(local[0]);}

/*matrix->collada-string*/
static pointer F5358matrix__collada_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[18])(ctx,1,local+0,&ftab[18],fqv[187]); /*array-dimensions*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[19])(ctx,0,local+1,&ftab[19],fqv[188]); /*make-string-output-stream*/
	local[1]= w;
	local[2]= makeint((eusinteger_t)0L);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
WHL5549:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX5550;
	local[4]= makeint((eusinteger_t)0L);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
WHL5553:
	local[6]= local[4];
	w = local[5];
	if ((eusinteger_t)local[6] >= (eusinteger_t)w) goto WHX5554;
	local[6]= local[1];
	local[7]= fqv[189];
	local[8]= argv[0];
	local[9]= local[2];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[4] = w;
	goto WHL5553;
WHX5554:
	local[6]= NIL;
BLK5555:
	w = NIL;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL5549;
WHX5550:
	local[4]= NIL;
BLK5551:
	w = NIL;
	local[2]= local[1];
	local[3]= fqv[190];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,2,local+2); /*format*/
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[20])(ctx,1,local+2,&ftab[20],fqv[191]); /*get-output-stream-string*/
	local[0]= w;
BLK5547:
	ctx->vsp=local; return(local[0]);}

/*find-parent-liks-from-link-description*/
static pointer F5359find_parent_liks_from_link_description(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F5343eusmodel_link_description(ctx,1,local+1); /*eusmodel-link-description*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F5373find_joint_from_link_description(ctx,2,local+0); /*find-joint-from-link-description*/
	local[0]= w;
	if (local[0]!=NIL) goto IF5557;
	local[1]= NIL;
	goto IF5558;
IF5557:
	local[1]= fqv[45];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[17])(ctx,2,local+1,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	local[2]= local[1];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)F5343eusmodel_link_description(ctx,1,local+3); /*eusmodel-link-description*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)F5371find_link_from_links_description(ctx,2,local+2); /*find-link-from-links-description*/
	local[2]= w;
	local[3]= local[2];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)F5359find_parent_liks_from_link_description(ctx,2,local+3); /*find-parent-liks-from-link-description*/
	local[3]= w;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)APPEND(ctx,2,local+3); /*append*/
	local[1]= w;
IF5558:
	w = local[1];
	local[0]= w;
BLK5556:
	ctx->vsp=local; return(local[0]);}

/*eusmodel-description->collada-node-transformations*/
static pointer F5360eusmodel_description__collada_node_transformations(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F5359find_parent_liks_from_link_description(ctx,2,local+0); /*find-parent-liks-from-link-description*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	local[0]= w;
	local[1]= (pointer)get_sym_func(fqv[192]);
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO5560,env,argv,local);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[21])(ctx,2,local+1,&ftab[21],fqv[193]); /*remove-if*/
	local[0]= w;
BLK5559:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5560(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env1[1];
	ctx->vsp=local+2;
	w=(pointer)F5344eusmodel_joint_description(ctx,1,local+1); /*eusmodel-joint-description*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F5373find_joint_from_link_description(ctx,2,local+0); /*find-joint-from-link-description*/
	local[0]= w;
	if (local[0]==NIL) goto IF5561;
	local[1]= fqv[194];
	local[2]= fqv[11];
	local[3]= fqv[179];
	local[4]= NIL;
	local[5]= fqv[195];
	local[6]= fqv[34];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(*ftab[17])(ctx,2,local+6,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.cdr;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[196];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	goto IF5562;
IF5561:
	local[1]= NIL;
IF5562:
	w = local[1];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*eusmodel-description->collada-node*/
static pointer F5361eusmodel_description__collada_node(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)F5344eusmodel_joint_description(ctx,1,local+0); /*eusmodel-joint-description*/
	local[0]= w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F5343eusmodel_link_description(ctx,1,local+1); /*eusmodel-link-description*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)F5344eusmodel_joint_description(ctx,1,local+3); /*eusmodel-joint-description*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)F5373find_joint_from_link_description(ctx,2,local+2); /*find-joint-from-link-description*/
	local[2]= w;
	local[3]= fqv[53];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[17])(ctx,2,local+3,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	local[4]= fqv[52];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(*ftab[17])(ctx,2,local+4,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO5564,env,argv,local);
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)F5343eusmodel_link_description(ctx,1,local+6); /*eusmodel-link-description*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[22])(ctx,2,local+5,&ftab[22],fqv[197]); /*position-if*/
	local[5]= w;
	local[6]= fqv[198];
	local[7]= fqv[11];
	local[8]= fqv[159];
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(pointer)F5350collada_node_id(ctx,1,local+9); /*collada-node-id*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[130];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)F5351collada_node_name(ctx,1,local+10); /*collada-node-name*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[179];
	local[11]= NIL;
	local[12]= fqv[199];
	local[13]= local[5];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,3,local+11); /*format*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= argv[0];
	local[9]= argv[1];
	ctx->vsp=local+10;
	w=(pointer)F5360eusmodel_description__collada_node_transformations(ctx,2,local+8); /*eusmodel-description->collada-node-transformations*/
	local[8]= w;
	ctx->vsp=local+9;
	local[9]= makeclosure(codevec,quotevec,CLO5565,env,argv,local);
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)LENGTH(ctx,1,local+10); /*length*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)F5398enum_integer_list(ctx,1,local+10); /*enum-integer-list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)MAPCAR(ctx,2,local+9); /*mapcar*/
	local[9]= w;
	local[10]= NIL;
	ctx->vsp=local+11;
	w=(pointer)APPEND(ctx,2,local+9); /*append*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)APPEND(ctx,2,local+8); /*append*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	local[0]= w;
BLK5563:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5564(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[34];
	local[1]= env->c.clo.env1[0];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= fqv[34];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[17])(ctx,2,local+1,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(*ftab[23])(ctx,2,local+0,&ftab[23],fqv[38]); /*string=*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5565(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[200];
	local[1]= fqv[11];
	local[2]= fqv[168];
	local[3]= NIL;
	local[4]= fqv[201];
	local[5]= env->c.clo.env1[0];
	ctx->vsp=local+6;
	w=(pointer)F5389collada_geometry_id_base(ctx,1,local+5); /*collada-geometry-id-base*/
	local[5]= w;
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,4,local+3); /*format*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[202];
	local[3]= fqv[203];
	local[4]= fqv[204];
	local[5]= fqv[11];
	local[6]= fqv[205];
	local[7]= NIL;
	local[8]= fqv[206];
	local[9]= env->c.clo.env1[0];
	ctx->vsp=local+10;
	w=(pointer)F5389collada_geometry_id_base(ctx,1,local+9); /*collada-geometry-id-base*/
	local[9]= w;
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,4,local+7); /*format*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[207];
	local[8]= NIL;
	local[9]= fqv[208];
	local[10]= env->c.clo.env1[0];
	ctx->vsp=local+11;
	w=(pointer)F5389collada_geometry_id_base(ctx,1,local+10); /*collada-geometry-id-base*/
	local[10]= w;
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,4,local+8); /*format*/
	local[8]= w;
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
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*eusmodel-description->collada-library-visual-scenes*/
static pointer F5362eusmodel_description__collada_library_visual_scenes(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[209];
	local[1]= fqv[11];
	local[2]= fqv[159];
	local[3]= fqv[210];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[211];
	local[3]= fqv[11];
	local[4]= fqv[159];
	local[5]= fqv[212];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[130];
	local[6]= fqv[213];
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
	local[4]= fqv[198];
	local[5]= fqv[11];
	local[6]= fqv[159];
	local[7]= fqv[214];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[179];
	local[8]= fqv[215];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[130];
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
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO5567,env,argv,local);
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)F5343eusmodel_link_description(ctx,1,local+7); /*eusmodel-link-description*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[6]= w;
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)APPEND(ctx,2,local+6); /*append*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK5566:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5567(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env1[1];
	ctx->vsp=local+2;
	w=(pointer)F5361eusmodel_description__collada_node(ctx,2,local+0); /*eusmodel-description->collada-node*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*mesh-description->instance-material*/
static pointer F5363mesh_description__instance_material(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[204];
	local[1]= fqv[11];
	local[2]= fqv[205];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[207];
	local[4]= NIL;
	local[5]= fqv[216];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK5568:
	ctx->vsp=local; return(local[0]);}

/*link-description->collada-bind-material*/
static pointer F5364link_description__collada_bind_material(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[53];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= fqv[34];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[17])(ctx,2,local+1,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F5398enum_integer_list(ctx,1,local+2); /*enum-integer-list*/
	local[2]= w;
	local[3]= fqv[202];
	local[4]= fqv[203];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO5570,env,argv,local);
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)MAPCAR(ctx,2,local+5); /*mapcar*/
	local[5]= w;
	local[6]= NIL;
	ctx->vsp=local+7;
	w=(pointer)APPEND(ctx,2,local+5); /*append*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	local[0]= w;
BLK5569:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5570(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= fqv[217];
	local[2]= env->c.clo.env2[1];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)F5363mesh_description__instance_material(ctx,1,local+0); /*mesh-description->instance-material*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*eusmodel-description->collada-library-kinematics-scenes*/
static pointer F5365eusmodel_description__collada_library_kinematics_scenes(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[218];
	local[1]= fqv[11];
	local[2]= fqv[159];
	local[3]= fqv[219];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[220];
	local[3]= fqv[11];
	local[4]= fqv[159];
	local[5]= fqv[221];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[130];
	local[6]= fqv[222];
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
	local[4]= fqv[223];
	local[5]= fqv[11];
	local[6]= fqv[179];
	local[7]= fqv[224];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[168];
	local[8]= fqv[225];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[130];
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
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[226];
	local[7]= fqv[11];
	local[8]= fqv[179];
	local[9]= fqv[227];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[228];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO5572,env,argv,local);
	local[8]= argv[1];
	ctx->vsp=local+9;
	w=(pointer)F5344eusmodel_joint_description(ctx,1,local+8); /*eusmodel-joint-description*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MAPCAR(ctx,2,local+7); /*mapcar*/
	local[7]= w;
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,CLO5573,env,argv,local);
	local[9]= argv[1];
	ctx->vsp=local+10;
	w=(pointer)F5344eusmodel_joint_description(ctx,1,local+9); /*eusmodel-joint-description*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MAPCAR(ctx,2,local+8); /*mapcar*/
	local[8]= w;
	local[9]= NIL;
	ctx->vsp=local+10;
	w=(pointer)APPEND(ctx,2,local+8); /*append*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)APPEND(ctx,2,local+7); /*append*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK5571:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5572(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[34];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= fqv[226];
	local[2]= fqv[11];
	local[3]= fqv[179];
	local[4]= NIL;
	local[5]= fqv[229];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= NIL;
	local[4]= fqv[230];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5573(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[34];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= fqv[226];
	local[2]= fqv[11];
	local[3]= fqv[179];
	local[4]= NIL;
	local[5]= fqv[231];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= NIL;
	local[4]= fqv[232];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*eusmodel-description->collada-library-kinematics-models*/
static pointer F5366eusmodel_description__collada_library_kinematics_models(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[233];
	local[1]= fqv[11];
	local[2]= fqv[159];
	local[3]= fqv[234];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)F5367eusmodel_description__collada_kinematics_model(ctx,2,local+2); /*eusmodel-description->collada-kinematics-model*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK5574:
	ctx->vsp=local; return(local[0]);}

/*eusmodel-description->collada-kinematics-model*/
static pointer F5367eusmodel_description__collada_kinematics_model(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)F5344eusmodel_joint_description(ctx,1,local+0); /*eusmodel-joint-description*/
	local[0]= w;
	local[1]= fqv[235];
	local[2]= fqv[11];
	local[3]= fqv[159];
	local[4]= fqv[236];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[130];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[203];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)F5379joints_description__collada_instance_joints(ctx,1,local+4); /*joints-description->collada-instance-joints*/
	local[4]= w;
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)F5372eusmodel_description__collada_links(ctx,1,local+5); /*eusmodel-description->collada-links*/
	local[5]= w;
	local[6]= NIL;
	ctx->vsp=local+7;
	w=(pointer)APPEND(ctx,2,local+5); /*append*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)APPEND(ctx,2,local+4); /*append*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK5575:
	ctx->vsp=local; return(local[0]);}

/*eusmodel-description->collada-library-physics-scenes*/
static pointer F5368eusmodel_description__collada_library_physics_scenes(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[237];
	local[1]= fqv[11];
	local[2]= fqv[159];
	local[3]= fqv[238];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[239];
	local[3]= fqv[11];
	local[4]= fqv[159];
	local[5]= fqv[240];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[130];
	local[6]= fqv[241];
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
	local[4]= fqv[242];
	local[5]= fqv[11];
	local[6]= fqv[168];
	local[7]= fqv[243];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[179];
	local[8]= fqv[244];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[245];
	local[9]= fqv[246];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)F5343eusmodel_link_description(ctx,1,local+6); /*eusmodel-link-description*/
	local[6]= w;
	local[7]= local[6];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)F5398enum_integer_list(ctx,1,local+7); /*enum-integer-list*/
	local[7]= w;
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,CLO5577,env,argv,local);
	local[9]= local[7];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)MAPCAR(ctx,3,local+8); /*mapcar*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK5576:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5577(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[247];
	local[1]= fqv[11];
	local[2]= fqv[248];
	local[3]= NIL;
	local[4]= fqv[249];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[207];
	local[4]= NIL;
	local[5]= fqv[250];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)F5350collada_node_id(ctx,1,local+6); /*collada-node-id*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*eusmodel-description->collada-library-physics-models*/
static pointer F5369eusmodel_description__collada_library_physics_models(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[251];
	local[1]= fqv[11];
	local[2]= fqv[159];
	local[3]= fqv[252];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[253];
	local[3]= fqv[11];
	local[4]= fqv[159];
	local[5]= fqv[254];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[130];
	local[6]= argv[0];
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
	local[4]= makeclosure(codevec,quotevec,CLO5579,env,argv,local);
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)F5343eusmodel_link_description(ctx,1,local+5); /*eusmodel-link-description*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)F5398enum_integer_list(ctx,1,local+5); /*enum-integer-list*/
	local[5]= w;
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)F5343eusmodel_link_description(ctx,1,local+6); /*eusmodel-link-description*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MAPCAR(ctx,3,local+4); /*mapcar*/
	local[4]= w;
	local[5]= NIL;
	ctx->vsp=local+6;
	w=(pointer)APPEND(ctx,2,local+4); /*append*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK5578:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5579(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[34];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= NIL;
	local[2]= fqv[255];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	local[2]= NIL;
	local[3]= fqv[256];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	local[3]= fqv[53];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(*ftab[17])(ctx,2,local+3,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	local[4]= fqv[257];
	local[5]= fqv[11];
	local[6]= fqv[159];
	local[7]= NIL;
	local[8]= fqv[258];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[179];
	local[8]= NIL;
	local[9]= fqv[259];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,3,local+8); /*format*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[130];
	local[9]= NIL;
	local[10]= fqv[260];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,3,local+9); /*format*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[203];
	local[7]= fqv[261];
	local[8]= NIL;
	local[9]= fqv[262];
	local[10]= fqv[55];
	local[11]= argv[1];
	ctx->vsp=local+12;
	w=(*ftab[17])(ctx,2,local+10,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.cdr;
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,3,local+8); /*format*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[263];
	local[9]= fqv[264];
	local[10]= fqv[54];
	local[11]= argv[1];
	ctx->vsp=local+12;
	w=(*ftab[17])(ctx,2,local+10,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.cdr;
	local[11]= fqv[265];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)F5397float_vector__collada_string(ctx,1,local+10); /*float-vector->collada-string*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[194];
	local[11]= fqv[54];
	local[12]= argv[1];
	ctx->vsp=local+13;
	w=(*ftab[17])(ctx,2,local+11,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.cdr;
	local[12]= fqv[266];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)F5375matrix__collada_rotate_vector(ctx,1,local+11); /*matrix->collada-rotate-vector*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)F5397float_vector__collada_string(ctx,1,local+11); /*float-vector->collada-string*/
	local[11]= w;
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
	local[9]= fqv[267];
	local[10]= fqv[57];
	local[11]= argv[1];
	ctx->vsp=local+12;
	w=(*ftab[17])(ctx,2,local+10,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.cdr;
	ctx->vsp=local+11;
	w=(pointer)F5397float_vector__collada_string(ctx,1,local+10); /*float-vector->collada-string*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	local[10]= makeclosure(codevec,quotevec,CLO5580,env,argv,local);
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)LENGTH(ctx,1,local+11); /*length*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)F5398enum_integer_list(ctx,1,local+11); /*enum-integer-list*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)MAPCAR(ctx,2,local+10); /*mapcar*/
	local[10]= w;
	local[11]= NIL;
	ctx->vsp=local+12;
	w=(pointer)APPEND(ctx,2,local+10); /*append*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
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
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5580(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[268];
	local[1]= fqv[200];
	local[2]= fqv[11];
	local[3]= fqv[168];
	local[4]= NIL;
	local[5]= fqv[269];
	local[6]= env->c.clo.env2[0];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,4,local+4); /*format*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[264];
	local[3]= fqv[270];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[194];
	local[4]= fqv[271];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*find-root-link-from-joints-description*/
static pointer F5370find_root_link_from_joints_description(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
WHL5583:
	if (local[2]==NIL) goto WHX5584;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= fqv[34];
	local[4]= fqv[34];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(*ftab[17])(ctx,2,local+4,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(*ftab[15])(ctx,2,local+3,&ftab[15],fqv[145]); /*geometry:make-cascoords*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[45];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[17])(ctx,2,local+5,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
	local[6]= fqv[95];
	ctx->vsp=local+7;
	w=(pointer)PUTPROP(ctx,3,local+4); /*putprop*/
	local[4]= local[3];
	local[5]= fqv[96];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[17])(ctx,2,local+5,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
	local[6]= fqv[97];
	ctx->vsp=local+7;
	w=(pointer)PUTPROP(ctx,3,local+4); /*putprop*/
	local[4]= local[3];
	w = local[0];
	ctx->vsp=local+5;
	local[0] = cons(ctx,local[4],w);
	w = local[0];
	goto WHL5583;
WHX5584:
	local[3]= NIL;
BLK5585:
	w = NIL;
	local[1]= NIL;
	local[2]= local[0];
WHL5588:
	if (local[2]==NIL) goto WHX5589;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	local[4]= fqv[95];
	ctx->vsp=local+5;
	w=(pointer)GETPROP(ctx,2,local+3); /*get*/
	local[3]= w;
	local[4]= local[3];
	local[5]= local[0];
	local[6]= fqv[37];
	local[7]= (pointer)get_sym_func(fqv[38]);
	local[8]= fqv[272];
	ctx->vsp=local+9;
	local[9]= makeclosure(codevec,quotevec,CLO5592,env,argv,local);
	ctx->vsp=local+10;
	w=(*ftab[0])(ctx,6,local+4,&ftab[0],fqv[1]); /*find*/
	local[4]= w;
	if (local[4]!=NIL) goto IF5593;
	w = local[3];
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK5581;
	goto IF5594;
IF5593:
	local[5]= NIL;
IF5594:
	w = local[5];
	goto WHL5588;
WHX5589:
	local[3]= NIL;
BLK5590:
	w = NIL;
	local[0]= w;
BLK5581:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5592(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[97];
	ctx->vsp=local+2;
	w=(pointer)GETPROP(ctx,2,local+0); /*get*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*find-link-from-links-description*/
static pointer F5371find_link_from_links_description(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= fqv[37];
	local[3]= (pointer)get_sym_func(fqv[38]);
	local[4]= fqv[272];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO5596,env,argv,local);
	ctx->vsp=local+6;
	w=(*ftab[0])(ctx,6,local+0,&ftab[0],fqv[1]); /*find*/
	local[0]= w;
BLK5595:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5596(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[34];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*eusmodel-description->collada-links*/
static pointer F5372eusmodel_description__collada_links(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F5344eusmodel_joint_description(ctx,1,local+0); /*eusmodel-joint-description*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F5343eusmodel_link_description(ctx,1,local+1); /*eusmodel-link-description*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F5370find_root_link_from_joints_description(ctx,1,local+2); /*find-root-link-from-joints-description*/
	local[2]= w;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F5371find_link_from_links_description(ctx,2,local+2); /*find-link-from-links-description*/
	local[2]= w;
	local[3]= local[2];
	local[4]= local[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)F5378eusmodel_description__collada_links_tree(ctx,3,local+3); /*eusmodel-description->collada-links-tree*/
	local[0]= w;
BLK5597:
	ctx->vsp=local; return(local[0]);}

/*find-joint-from-link-description*/
static pointer F5373find_joint_from_link_description(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[34];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= argv[1];
	local[2]= fqv[37];
	local[3]= (pointer)get_sym_func(fqv[38]);
	local[4]= fqv[272];
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO5599,env,argv,local);
	ctx->vsp=local+6;
	w=(*ftab[0])(ctx,6,local+0,&ftab[0],fqv[1]); /*find*/
	local[0]= w;
BLK5598:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5599(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[96];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*find-child-link-descriptions*/
static pointer F5374find_child_link_descriptions(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO5601,env,argv,local);
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[24])(ctx,2,local+0,&ftab[24],fqv[273]); /*remove-if-not*/
	local[0]= w;
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO5602,env,argv,local);
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[24])(ctx,2,local+1,&ftab[24],fqv[273]); /*remove-if-not*/
	local[1]= w;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO5603,env,argv,local);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO5604,env,argv,local);
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[0]= w;
BLK5600:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5601(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[45];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5602(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[45];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= fqv[34];
	local[2]= env->c.clo.env1[0];
	ctx->vsp=local+3;
	w=(*ftab[17])(ctx,2,local+1,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(*ftab[23])(ctx,2,local+0,&ftab[23],fqv[38]); /*string=*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5603(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[96];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5604(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env1[1];
	ctx->vsp=local+2;
	w=(pointer)F5371find_link_from_links_description(ctx,2,local+0); /*find-link-from-links-description*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*matrix->collada-rotate-vector*/
static pointer F5375matrix__collada_rotate_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[25])(ctx,1,local+0,&ftab[25],fqv[274]); /*user::matrix2quaternion*/
	local[0]= w;
	local[1]= local[0];
	local[2]= makeint((eusinteger_t)1L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= local[0];
	local[3]= makeint((eusinteger_t)2L);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	local[3]= local[0];
	local[4]= makeint((eusinteger_t)3L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[26])(ctx,1,local+1,&ftab[26],fqv[275]); /*normalize-vector*/
	local[1]= w;
	local[2]= local[0];
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	local[3]= local[1];
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	local[4]= local[1];
	local[5]= makeint((eusinteger_t)1L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	local[5]= local[1];
	local[6]= makeint((eusinteger_t)2L);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	local[6]= makeflt(2.0000000000000000000000e+00);
	local[7]= local[0];
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	local[8]= makeint((eusinteger_t)2L);
	ctx->vsp=local+9;
	w=(*ftab[27])(ctx,2,local+7,&ftab[27],fqv[276]); /*expt*/
	local[7]= w;
	local[8]= local[0];
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(*ftab[27])(ctx,2,local+8,&ftab[27],fqv[276]); /*expt*/
	local[8]= w;
	local[9]= local[0];
	local[10]= makeint((eusinteger_t)3L);
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	local[10]= makeint((eusinteger_t)2L);
	ctx->vsp=local+11;
	w=(*ftab[27])(ctx,2,local+9,&ftab[27],fqv[276]); /*expt*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,3,local+7); /*+*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SQRT(ctx,1,local+7); /*sqrt*/
	local[7]= w;
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)ATAN(ctx,2,local+7); /*atan*/
	{ double x,y;
		y=fltval(w); x=fltval(local[6]);
		local[6]=(makeflt(x * y));}
	ctx->vsp=local+7;
	w=(*ftab[28])(ctx,1,local+6,&ftab[28],fqv[277]); /*rad2deg*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,4,local+3); /*float-vector*/
	local[0]= w;
BLK5605:
	ctx->vsp=local; return(local[0]);}

/*eusmodel-description->collada-library-articulated-systems*/
static pointer F5376eusmodel_description__collada_library_articulated_systems(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[278];
	local[1]= fqv[11];
	local[2]= fqv[159];
	local[3]= fqv[279];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[280];
	local[3]= fqv[11];
	local[4]= fqv[159];
	local[5]= fqv[281];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[282];
	local[5]= fqv[223];
	local[6]= fqv[11];
	local[7]= fqv[168];
	local[8]= fqv[283];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[226];
	local[8]= fqv[11];
	local[9]= fqv[179];
	local[10]= fqv[284];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[285];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,CLO5607,env,argv,local);
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(pointer)F5344eusmodel_joint_description(ctx,1,local+9); /*eusmodel-joint-description*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MAPCAR(ctx,2,local+8); /*mapcar*/
	local[8]= w;
	ctx->vsp=local+9;
	local[9]= makeclosure(codevec,quotevec,CLO5608,env,argv,local);
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)F5344eusmodel_joint_description(ctx,1,local+10); /*eusmodel-joint-description*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)MAPCAR(ctx,2,local+9); /*mapcar*/
	local[9]= w;
	local[10]= NIL;
	ctx->vsp=local+11;
	w=(pointer)APPEND(ctx,2,local+9); /*append*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)APPEND(ctx,2,local+8); /*append*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[203];
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO5609,env,argv,local);
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)F5344eusmodel_joint_description(ctx,1,local+8); /*eusmodel-joint-description*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MAPCAR(ctx,2,local+7); /*mapcar*/
	local[7]= w;
	local[8]= NIL;
	ctx->vsp=local+9;
	w=(pointer)APPEND(ctx,2,local+7); /*append*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO5610,env,argv,local);
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)F5345eusmodel_endcoords_description(ctx,1,local+6); /*eusmodel-endcoords-description*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MAPCAR(ctx,2,local+5); /*mapcar*/
	local[5]= w;
	local[6]= NIL;
	ctx->vsp=local+7;
	w=(pointer)APPEND(ctx,2,local+5); /*append*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[280];
	local[4]= fqv[11];
	local[5]= fqv[159];
	local[6]= fqv[286];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[287];
	local[6]= fqv[288];
	local[7]= fqv[11];
	local[8]= fqv[168];
	local[9]= fqv[289];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[179];
	local[10]= fqv[290];
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
	local[8]= fqv[226];
	local[9]= fqv[11];
	local[10]= fqv[179];
	local[11]= fqv[291];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[292];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	local[9]= makeclosure(codevec,quotevec,CLO5611,env,argv,local);
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)F5344eusmodel_joint_description(ctx,1,local+10); /*eusmodel-joint-description*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)MAPCAR(ctx,2,local+9); /*mapcar*/
	local[9]= w;
	ctx->vsp=local+10;
	local[10]= makeclosure(codevec,quotevec,CLO5612,env,argv,local);
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)F5344eusmodel_joint_description(ctx,1,local+11); /*eusmodel-joint-description*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)MAPCAR(ctx,2,local+10); /*mapcar*/
	local[10]= w;
	local[11]= NIL;
	ctx->vsp=local+12;
	w=(pointer)APPEND(ctx,2,local+10); /*append*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)APPEND(ctx,2,local+9); /*append*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[203];
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,CLO5613,env,argv,local);
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(pointer)F5344eusmodel_joint_description(ctx,1,local+9); /*eusmodel-joint-description*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MAPCAR(ctx,2,local+8); /*mapcar*/
	local[8]= w;
	local[9]= NIL;
	ctx->vsp=local+10;
	w=(pointer)APPEND(ctx,2,local+8); /*append*/
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
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK5606:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5607(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[34];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= fqv[226];
	local[2]= fqv[11];
	local[3]= fqv[179];
	local[4]= NIL;
	local[5]= fqv[293];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= NIL;
	local[4]= fqv[294];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5608(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[34];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= fqv[226];
	local[2]= fqv[11];
	local[3]= fqv[179];
	local[4]= NIL;
	local[5]= fqv[295];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= NIL;
	local[4]= fqv[296];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5609(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[34];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= fqv[297];
	local[2]= fqv[11];
	local[3]= fqv[298];
	local[4]= NIL;
	local[5]= fqv[299];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5610(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env1[0];
	ctx->vsp=local+2;
	w=(pointer)F5377eusmodel_endcoords_description__openrave_manipulator(ctx,2,local+0); /*eusmodel-endcoords-description->openrave-manipulator*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5611(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[34];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= fqv[226];
	local[2]= fqv[11];
	local[3]= fqv[179];
	local[4]= NIL;
	local[5]= fqv[300];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= NIL;
	local[4]= fqv[301];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5612(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[34];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= fqv[226];
	local[2]= fqv[11];
	local[3]= fqv[179];
	local[4]= NIL;
	local[5]= fqv[302];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[303];
	local[4]= fqv[304];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5613(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[34];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= fqv[297];
	local[2]= fqv[11];
	local[3]= fqv[298];
	local[4]= NIL;
	local[5]= fqv[305];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[179];
	local[5]= NIL;
	local[6]= fqv[306];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,3,local+5); /*format*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*eusmodel-endcoords-description->openrave-manipulator*/
static pointer F5377eusmodel_endcoords_description__openrave_manipulator(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	ctx->vsp=local+3;
	w=(*ftab[29])(ctx,1,local+2,&ftab[29],fqv[307]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[308];
	local[4]= fqv[11];
	local[5]= fqv[130];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[309];
	local[7]= fqv[310];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[178];
	local[6]= fqv[11];
	local[7]= fqv[311];
	local[8]= fqv[312];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[313];
	local[8]= fqv[11];
	local[9]= fqv[314];
	local[10]= NIL;
	local[11]= fqv[315];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,3,local+10); /*format*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[316];
	local[9]= fqv[11];
	local[10]= fqv[314];
	local[11]= NIL;
	local[12]= fqv[317];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,3,local+11); /*format*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	local[0]= w;
BLK5614:
	ctx->vsp=local; return(local[0]);}

/*eusmodel-description->collada-links-tree*/
static pointer F5378eusmodel_description__collada_links_tree(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)F5374find_child_link_descriptions(ctx,3,local+0); /*find-child-link-descriptions*/
	local[0]= w;
	local[1]= fqv[34];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[17])(ctx,2,local+1,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	local[2]= fqv[314];
	local[3]= fqv[11];
	local[4]= fqv[179];
	local[5]= NIL;
	local[6]= fqv[318];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,3,local+5); /*format*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[130];
	local[6]= NIL;
	local[7]= fqv[319];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
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
	local[4]= makeclosure(codevec,quotevec,CLO5616,env,argv,local);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[4]= w;
	local[5]= NIL;
	ctx->vsp=local+6;
	w=(pointer)APPEND(ctx,2,local+4); /*append*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[0]= w;
BLK5615:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5616(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[52];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= argv[0];
	local[2]= env->c.clo.env1[2];
	ctx->vsp=local+3;
	w=(pointer)F5373find_joint_from_link_description(ctx,2,local+1); /*find-joint-from-link-description*/
	local[1]= w;
	local[2]= fqv[320];
	local[3]= fqv[11];
	local[4]= fqv[321];
	local[5]= NIL;
	local[6]= fqv[322];
	local[7]= fqv[34];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(*ftab[17])(ctx,2,local+7,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,3,local+5); /*format*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[264];
	local[5]= local[0];
	local[6]= fqv[265];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)F5397float_vector__collada_string(ctx,1,local+5); /*float-vector->collada-string*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[194];
	local[6]= local[0];
	local[7]= fqv[266];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)F5375matrix__collada_rotate_vector(ctx,1,local+6); /*matrix->collada-rotate-vector*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)F5397float_vector__collada_string(ctx,1,local+6); /*float-vector->collada-string*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= argv[0];
	local[7]= env->c.clo.env1[1];
	local[8]= env->c.clo.env1[2];
	ctx->vsp=local+9;
	w=(pointer)F5378eusmodel_description__collada_links_tree(ctx,3,local+6); /*eusmodel-description->collada-links-tree*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*joints-description->collada-instance-joints*/
static pointer F5379joints_description__collada_instance_joints(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= (pointer)get_sym_func(fqv[323]);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	local[0]= w;
BLK5617:
	ctx->vsp=local; return(local[0]);}

/*joint-description->collada-instance-joint*/
static pointer F5380joint_description__collada_instance_joint(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[34];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= fqv[324];
	local[2]= fqv[11];
	local[3]= fqv[168];
	local[4]= NIL;
	local[5]= fqv[325];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[179];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK5618:
	ctx->vsp=local; return(local[0]);}

/*eusmodel-description->collada-library-joints*/
static pointer F5381eusmodel_description__collada_library_joints(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[326];
	local[1]= fqv[11];
	local[2]= fqv[159];
	local[3]= fqv[327];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)F5344eusmodel_joint_description(ctx,1,local+2); /*eusmodel-joint-description*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F5382joints_description__collada_joints(ctx,1,local+2); /*joints-description->collada-joints*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)APPEND(ctx,2,local+2); /*append*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK5619:
	ctx->vsp=local; return(local[0]);}

/*joints-description->collada-joints*/
static pointer F5382joints_description__collada_joints(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= (pointer)get_sym_func(fqv[328]);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	local[0]= w;
BLK5620:
	ctx->vsp=local; return(local[0]);}

/*collada-joint-id*/
static pointer F5383collada_joint_id(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= fqv[329];
	local[2]= fqv[34];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[17])(ctx,2,local+2,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK5621:
	ctx->vsp=local; return(local[0]);}

/*joint-description->collada-joint*/
static pointer F5384joint_description__collada_joint(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F5383collada_joint_id(ctx,1,local+0); /*collada-joint-id*/
	local[0]= w;
	local[1]= fqv[34];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[17])(ctx,2,local+1,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	local[2]= fqv[321];
	local[3]= fqv[11];
	local[4]= fqv[159];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[130];
	local[6]= NIL;
	local[7]= fqv[330];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[179];
	local[7]= NIL;
	local[8]= fqv[331];
	local[9]= fqv[72];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(*ftab[17])(ctx,2,local+9,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
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
	local[4]= fqv[67];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(*ftab[17])(ctx,2,local+4,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	if (fqv[71]!=local[4]) goto CON5624;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F5385linear_joint_description__collada_joint(ctx,1,local+4); /*linear-joint-description->collada-joint*/
	local[4]= w;
	goto CON5623;
CON5624:
	local[4]= fqv[67];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(*ftab[17])(ctx,2,local+4,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	if (fqv[69]!=local[4]) goto CON5625;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F5386rotational_joint_description__collada_joint(ctx,1,local+4); /*rotational-joint-description->collada-joint*/
	local[4]= w;
	goto CON5623;
CON5625:
	local[4]= fqv[332];
	local[5]= fqv[67];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(*ftab[17])(ctx,2,local+5,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
	ctx->vsp=local+6;
	w=(pointer)SIGERROR(ctx,2,local+4); /*error*/
	local[4]= w;
	goto CON5623;
CON5626:
	local[4]= NIL;
CON5623:
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[0]= w;
BLK5622:
	ctx->vsp=local; return(local[0]);}

/*linear-joint-description->collada-joint*/
static pointer F5385linear_joint_description__collada_joint(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[73];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= fqv[333];
	local[2]= fqv[11];
	local[3]= fqv[179];
	local[4]= fqv[334];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[298];
	local[4]= fqv[74];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(*ftab[17])(ctx,2,local+4,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)F5397float_vector__collada_string(ctx,1,local+4); /*float-vector->collada-string*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[335];
	local[5]= fqv[336];
	local[6]= NIL;
	local[7]= fqv[337];
	local[8]= fqv[101];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(*ftab[17])(ctx,2,local+8,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.cdr;
	ctx->vsp=local+9;
	w=(*ftab[28])(ctx,1,local+8,&ftab[28],fqv[277]); /*rad2deg*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[338];
	local[7]= NIL;
	local[8]= fqv[339];
	local[9]= fqv[98];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(*ftab[17])(ctx,2,local+9,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
	ctx->vsp=local+10;
	w=(*ftab[28])(ctx,1,local+9,&ftab[28],fqv[277]); /*rad2deg*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK5627:
	ctx->vsp=local; return(local[0]);}

/*rotational-joint-description->collada-joint*/
static pointer F5386rotational_joint_description__collada_joint(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[73];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= fqv[340];
	local[2]= fqv[11];
	local[3]= fqv[179];
	local[4]= fqv[341];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[298];
	local[4]= fqv[74];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(*ftab[17])(ctx,2,local+4,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)F5397float_vector__collada_string(ctx,1,local+4); /*float-vector->collada-string*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[335];
	local[5]= fqv[336];
	local[6]= NIL;
	local[7]= fqv[342];
	local[8]= fqv[101];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(*ftab[17])(ctx,2,local+8,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.cdr;
	ctx->vsp=local+9;
	w=(*ftab[28])(ctx,1,local+8,&ftab[28],fqv[277]); /*rad2deg*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[338];
	local[7]= NIL;
	local[8]= fqv[343];
	local[9]= fqv[98];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(*ftab[17])(ctx,2,local+9,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
	ctx->vsp=local+10;
	w=(*ftab[28])(ctx,1,local+9,&ftab[28],fqv[277]); /*rad2deg*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK5628:
	ctx->vsp=local; return(local[0]);}

/*eusmodel-description->collada-scene*/
static pointer F5387eusmodel_description__collada_scene(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[344];
	local[1]= fqv[345];
	local[2]= fqv[11];
	local[3]= fqv[168];
	local[4]= fqv[346];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[347];
	local[3]= fqv[11];
	local[4]= fqv[168];
	local[5]= fqv[348];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[349];
	local[4]= fqv[11];
	local[5]= fqv[168];
	local[6]= fqv[350];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[351];
	local[6]= fqv[11];
	local[7]= fqv[198];
	local[8]= fqv[352];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[353];
	local[8]= fqv[354];
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
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO5630,env,argv,local);
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)F5344eusmodel_joint_description(ctx,1,local+7); /*eusmodel-joint-description*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[6]= w;
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)APPEND(ctx,2,local+6); /*append*/
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
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK5629:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5630(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[355];
	local[1]= fqv[11];
	local[2]= fqv[207];
	local[3]= NIL;
	local[4]= fqv[356];
	local[5]= fqv[96];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(*ftab[17])(ctx,2,local+5,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
	local[6]= fqv[34];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(*ftab[17])(ctx,2,local+6,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.cdr;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,4,local+3); /*format*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[298];
	local[3]= fqv[353];
	local[4]= NIL;
	local[5]= fqv[357];
	local[6]= fqv[34];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(*ftab[17])(ctx,2,local+6,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.cdr;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[358];
	local[4]= fqv[353];
	local[5]= NIL;
	local[6]= fqv[359];
	local[7]= fqv[34];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(*ftab[17])(ctx,2,local+7,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,3,local+5); /*format*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*eusmodel-description->collada-library-geometries*/
static pointer F5388eusmodel_description__collada_library_geometries(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[360];
	local[1]= fqv[11];
	local[2]= fqv[159];
	local[3]= fqv[361];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)F5343eusmodel_link_description(ctx,1,local+2); /*eusmodel-link-description*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F5391links_description__collada_geometries(ctx,1,local+2); /*links-description->collada-geometries*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)APPEND(ctx,2,local+2); /*append*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK5631:
	ctx->vsp=local; return(local[0]);}

/*collada-geometry-id-base*/
static pointer F5389collada_geometry_id_base(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[34];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= NIL;
	local[2]= fqv[362];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[0]= w;
BLK5632:
	ctx->vsp=local; return(local[0]);}

/*collada-geometry-name-base*/
static pointer F5390collada_geometry_name_base(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[34];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,2,local+0,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= NIL;
	local[2]= fqv[363];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[0]= w;
BLK5633:
	ctx->vsp=local; return(local[0]);}

/*links-description->collada-geometries*/
static pointer F5391links_description__collada_geometries(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= (pointer)get_sym_func(fqv[364]);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	local[0]= w;
BLK5634:
	ctx->vsp=local; return(local[0]);}

/*mesh-object->collada-mesh*/
static pointer F5392mesh_object__collada_mesh(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[365];
	local[1]= fqv[366];
	local[2]= fqv[11];
	local[3]= fqv[159];
	local[4]= NIL;
	local[5]= fqv[367];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[368];
	local[4]= fqv[11];
	local[5]= fqv[159];
	local[6]= NIL;
	local[7]= fqv[369];
	local[8]= argv[1];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[370];
	local[7]= makeint((eusinteger_t)3L);
	local[8]= makeint((eusinteger_t)3L);
	local[9]= argv[0];
	local[10]= fqv[61];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	{ eusinteger_t i,j;
		j=intval(w); i=intval(local[8]);
		local[8]=(makeint(i * j));}
	{ eusinteger_t i,j;
		j=intval(local[8]); i=intval(local[7]);
		local[7]=(makeint(i * j));}
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)F5395mesh_vertices__collada_string(ctx,1,local+5); /*mesh-vertices->collada-string*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[203];
	local[5]= fqv[371];
	local[6]= fqv[11];
	local[7]= fqv[366];
	local[8]= NIL;
	local[9]= fqv[372];
	local[10]= argv[1];
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,3,local+8); /*format*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[370];
	local[9]= makeint((eusinteger_t)3L);
	local[10]= argv[0];
	local[11]= fqv[61];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LENGTH(ctx,1,local+10); /*length*/
	{ eusinteger_t i,j;
		j=intval(w); i=intval(local[9]);
		local[9]=(makeint(i * j));}
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[373];
	local[10]= fqv[374];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
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
	local[7]= fqv[353];
	local[8]= fqv[11];
	local[9]= fqv[130];
	local[10]= fqv[375];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[309];
	local[11]= fqv[376];
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
	local[8]= fqv[353];
	local[9]= fqv[11];
	local[10]= fqv[130];
	local[11]= fqv[377];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[309];
	local[12]= fqv[378];
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
	local[9]= fqv[353];
	local[10]= fqv[11];
	local[11]= fqv[130];
	local[12]= fqv[379];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[309];
	local[13]= fqv[380];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
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
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[366];
	local[3]= fqv[11];
	local[4]= fqv[159];
	local[5]= NIL;
	local[6]= fqv[381];
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,3,local+5); /*format*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[368];
	local[5]= fqv[11];
	local[6]= fqv[159];
	local[7]= NIL;
	local[8]= fqv[382];
	local[9]= argv[1];
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[370];
	local[8]= makeint((eusinteger_t)3L);
	local[9]= argv[0];
	local[10]= fqv[61];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	{ eusinteger_t i,j;
		j=intval(w); i=intval(local[8]);
		local[8]=(makeint(i * j));}
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
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)F5396mesh_normals__collada_string(ctx,1,local+6); /*mesh-normals->collada-string*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[203];
	local[6]= fqv[371];
	local[7]= fqv[11];
	local[8]= fqv[366];
	local[9]= NIL;
	local[10]= fqv[383];
	local[11]= argv[1];
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,3,local+9); /*format*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[370];
	local[10]= argv[0];
	local[11]= fqv[61];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LENGTH(ctx,1,local+10); /*length*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[373];
	local[11]= fqv[384];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[353];
	local[9]= fqv[11];
	local[10]= fqv[130];
	local[11]= fqv[385];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[309];
	local[12]= fqv[386];
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
	local[9]= fqv[353];
	local[10]= fqv[11];
	local[11]= fqv[130];
	local[12]= fqv[387];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[309];
	local[13]= fqv[388];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
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
	local[10]= fqv[353];
	local[11]= fqv[11];
	local[12]= fqv[130];
	local[13]= fqv[389];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[309];
	local[14]= fqv[390];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[391];
	local[4]= fqv[11];
	local[5]= fqv[159];
	local[6]= NIL;
	local[7]= fqv[392];
	local[8]= argv[1];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[393];
	local[6]= fqv[11];
	local[7]= fqv[394];
	local[8]= fqv[395];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[366];
	local[9]= NIL;
	local[10]= fqv[396];
	local[11]= argv[1];
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,3,local+9); /*format*/
	local[9]= w;
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
	local[4]= fqv[397];
	local[5]= fqv[11];
	local[6]= fqv[370];
	local[7]= argv[0];
	local[8]= fqv[61];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[166];
	local[8]= NIL;
	local[9]= fqv[398];
	local[10]= argv[1];
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,3,local+8); /*format*/
	local[8]= w;
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
	local[6]= fqv[393];
	local[7]= fqv[11];
	local[8]= fqv[399];
	local[9]= fqv[400];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[394];
	local[10]= fqv[401];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[366];
	local[11]= NIL;
	local[12]= fqv[402];
	local[13]= argv[1];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,3,local+11); /*format*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[393];
	local[8]= fqv[11];
	local[9]= fqv[399];
	local[10]= fqv[403];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[394];
	local[11]= fqv[404];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[366];
	local[12]= NIL;
	local[13]= fqv[405];
	local[14]= argv[1];
	ctx->vsp=local+15;
	w=(pointer)XFORMAT(ctx,3,local+12); /*format*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)F5394mesh__collada_indices(ctx,1,local+8); /*mesh->collada-indices*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK5635:
	ctx->vsp=local; return(local[0]);}

/*link-description->collada-geometry*/
static pointer F5393link_description__collada_geometry(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F5389collada_geometry_id_base(ctx,1,local+0); /*collada-geometry-id-base*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F5390collada_geometry_name_base(ctx,1,local+1); /*collada-geometry-name-base*/
	local[1]= w;
	local[2]= fqv[53];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[17])(ctx,2,local+2,&ftab[17],fqv[156]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)F5398enum_integer_list(ctx,1,local+3); /*enum-integer-list*/
	local[3]= w;
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO5637,env,argv,local);
	local[5]= local[3];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)MAPCAR(ctx,3,local+4); /*mapcar*/
	local[0]= w;
BLK5636:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO5637(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= fqv[406];
	local[2]= env->c.clo.env2[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
	local[1]= NIL;
	local[2]= fqv[407];
	local[3]= env->c.clo.env2[1];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,4,local+1); /*format*/
	local[1]= w;
	local[2]= fqv[408];
	local[3]= fqv[11];
	local[4]= fqv[159];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[130];
	local[6]= local[1];
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
	local[4]= argv[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)F5392mesh_object__collada_mesh(ctx,2,local+4); /*mesh-object->collada-mesh*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*mesh->collada-indices*/
static pointer F5394mesh__collada_indices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[61];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[19])(ctx,0,local+1,&ftab[19],fqv[188]); /*make-string-output-stream*/
	local[1]= w;
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	local[4]= local[1];
	local[5]= fqv[409];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,2,local+4); /*format*/
	local[4]= makeint((eusinteger_t)0L);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
WHL5640:
	local[6]= local[4];
	w = local[5];
	if ((eusinteger_t)local[6] >= (eusinteger_t)w) goto WHX5641;
	local[6]= local[0];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	local[7]= local[6];
	local[8]= fqv[410];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	local[8]= makeint((eusinteger_t)0L);
	local[9]= local[7];
WHL5644:
	local[10]= local[8];
	w = local[9];
	if ((eusinteger_t)local[10] >= (eusinteger_t)w) goto WHX5645;
	local[10]= local[1];
	local[11]= fqv[411];
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,3,local+10); /*format*/
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[2] = w;
	local[10]= local[1];
	local[11]= fqv[412];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,3,local+10); /*format*/
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[8] = w;
	goto WHL5644;
WHX5645:
	local[10]= NIL;
BLK5646:
	w = NIL;
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[3] = w;
	w = local[3];
	local[7]= local[1];
	local[8]= fqv[413];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,2,local+7); /*format*/
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[4] = w;
	goto WHL5640;
WHX5641:
	local[6]= NIL;
BLK5642:
	w = NIL;
	local[4]= local[1];
	local[5]= fqv[414];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,2,local+4); /*format*/
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(*ftab[20])(ctx,1,local+4,&ftab[20],fqv[191]); /*get-output-stream-string*/
	local[0]= w;
BLK5638:
	ctx->vsp=local; return(local[0]);}

/*mesh-vertices->collada-string*/
static pointer F5395mesh_vertices__collada_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[61];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[19])(ctx,0,local+1,&ftab[19],fqv[188]); /*make-string-output-stream*/
	local[1]= w;
	local[2]= NIL;
	local[3]= local[0];
WHL5649:
	if (local[3]==NIL) goto WHX5650;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	local[5]= fqv[410];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	local[5]= NIL;
	local[6]= local[4];
WHL5654:
	if (local[6]==NIL) goto WHX5655;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)3L);
WHL5659:
	local[9]= local[7];
	w = local[8];
	if ((eusinteger_t)local[9] >= (eusinteger_t)w) goto WHX5660;
	local[9]= local[1];
	local[10]= fqv[415];
	local[11]= local[5];
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,3,local+9); /*format*/
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	local[7] = w;
	goto WHL5659;
WHX5660:
	local[9]= NIL;
BLK5661:
	w = NIL;
	local[7]= local[1];
	local[8]= fqv[416];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,2,local+7); /*format*/
	goto WHL5654;
WHX5655:
	local[7]= NIL;
BLK5656:
	w = NIL;
	goto WHL5649;
WHX5650:
	local[4]= NIL;
BLK5651:
	w = NIL;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[20])(ctx,1,local+2,&ftab[20],fqv[191]); /*get-output-stream-string*/
	local[0]= w;
BLK5647:
	ctx->vsp=local; return(local[0]);}

/*mesh-normals->collada-string*/
static pointer F5396mesh_normals__collada_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[61];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[19])(ctx,0,local+1,&ftab[19],fqv[188]); /*make-string-output-stream*/
	local[1]= w;
	local[2]= NIL;
	local[3]= local[0];
WHL5664:
	if (local[3]==NIL) goto WHX5665;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	local[5]= fqv[417];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= makeint((eusinteger_t)0L);
	local[6]= makeint((eusinteger_t)3L);
WHL5669:
	local[7]= local[5];
	w = local[6];
	if ((eusinteger_t)local[7] >= (eusinteger_t)w) goto WHX5670;
	local[7]= local[1];
	local[8]= fqv[418];
	local[9]= local[4];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[5] = w;
	goto WHL5669;
WHX5670:
	local[7]= NIL;
BLK5671:
	w = NIL;
	local[5]= local[1];
	local[6]= fqv[419];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,2,local+5); /*format*/
	goto WHL5664;
WHX5665:
	local[4]= NIL;
BLK5666:
	w = NIL;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[20])(ctx,1,local+2,&ftab[20],fqv[191]); /*get-output-stream-string*/
	local[0]= w;
BLK5662:
	ctx->vsp=local; return(local[0]);}

/*float-vector->collada-string*/
static pointer F5397float_vector__collada_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	w=(*ftab[19])(ctx,0,local+0,&ftab[19],fqv[188]); /*make-string-output-stream*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)0L);
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
WHL5674:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX5675;
	local[3]= local[0];
	local[4]= fqv[420];
	local[5]= argv[0];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL5674;
WHX5675:
	local[3]= NIL;
BLK5676:
	w = NIL;
	local[1]= local[0];
	local[2]= fqv[421];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,2,local+1); /*format*/
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[20])(ctx,1,local+1,&ftab[20],fqv[191]); /*get-output-stream-string*/
	local[0]= w;
BLK5672:
	ctx->vsp=local; return(local[0]);}

/*enum-integer-list*/
static pointer F5398enum_integer_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= makeint((eusinteger_t)0L);
	local[2]= argv[0];
WHL5679:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX5680;
	local[3]= local[1];
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL5679;
WHX5680:
	local[3]= NIL;
BLK5681:
	w = NIL;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)REVERSE(ctx,1,local+1); /*reverse*/
	local[0]= w;
BLK5677:
	ctx->vsp=local; return(local[0]);}

/*search-minimum-rotation-matrix*/
static pointer F5399search_minimum_rotation_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(*ftab[30])(ctx,2,local+0,&ftab[30],fqv[422]); /*matrix-column*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= makeint((eusinteger_t)1L);
	ctx->vsp=local+3;
	w=(*ftab[30])(ctx,2,local+1,&ftab[30],fqv[422]); /*matrix-column*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= makeint((eusinteger_t)2L);
	ctx->vsp=local+4;
	w=(*ftab[30])(ctx,2,local+2,&ftab[30],fqv[422]); /*matrix-column*/
	local[2]= w;
	local[3]= local[0];
	local[4]= local[1];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[3]= w;
	local[4]= makeint((eusinteger_t)1L);
	local[5]= makeint((eusinteger_t)0L);
	local[6]= makeint((eusinteger_t)0L);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	local[5]= makeint((eusinteger_t)0L);
	local[6]= makeint((eusinteger_t)1L);
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[5]= w;
	local[6]= makeint((eusinteger_t)0L);
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,3,local+6); /*float-vector*/
	local[6]= w;
	local[7]= local[4];
	local[8]= local[5];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,3,local+7); /*list*/
	local[7]= w;
	local[8]= makeint((eusinteger_t)-2L);
	local[9]= NIL;
	local[10]= NIL;
	local[11]= local[3];
WHL5684:
	if (local[11]==NIL) goto WHX5685;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[12];
	local[10] = w;
	local[12]= NIL;
	local[13]= local[7];
WHL5689:
	if (local[13]==NIL) goto WHX5690;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13] = (w)->c.cons.cdr;
	w = local[14];
	local[12] = w;
	local[14]= local[10];
	local[15]= local[12];
	ctx->vsp=local+16;
	w=(pointer)VINNERPRODUCT(ctx,2,local+14); /*v.*/
	local[14]= makeflt((double)fabs(fltval(w)));
	local[15]= local[14];
	local[16]= local[8];
	ctx->vsp=local+17;
	w=(pointer)GREATERP(ctx,2,local+15); /*>*/
	if (w==NIL) goto IF5693;
	local[8] = local[14];
	local[15]= local[10];
	w = local[12];
	ctx->vsp=local+16;
	local[9] = cons(ctx,local[15],w);
	local[15]= local[9];
	goto IF5694;
IF5693:
	local[15]= NIL;
IF5694:
	w = local[15];
	goto WHL5689;
WHX5690:
	local[14]= NIL;
BLK5691:
	w = NIL;
	goto WHL5684;
WHX5685:
	local[12]= NIL;
BLK5686:
	w = NIL;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.cdr;
	if (local[4]!=local[10]) goto CON5696;
	local[10]= (pointer)get_sym_func(fqv[423]);
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.cdr;
	ctx->vsp=local+13;
	w=(pointer)VINNERPRODUCT(ctx,2,local+11); /*v.*/
	local[11]= w;
	local[12]= makeint((eusinteger_t)0L);
	ctx->vsp=local+13;
	w=(pointer)GREATERP(ctx,2,local+11); /*>*/
	if (w==NIL) goto IF5697;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	goto IF5698;
IF5697:
	local[11]= makeflt(-1.0000000000000000000000e+00);
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	ctx->vsp=local+13;
	w=(pointer)SCALEVEC(ctx,2,local+11); /*scale*/
	local[11]= w;
IF5698:
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= local[3];
	ctx->vsp=local+14;
	w=(*ftab[31])(ctx,2,local+12,&ftab[31],fqv[424]); /*remove*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)APPLY(ctx,3,local+10); /*apply*/
	local[10]= w;
	local[11]= local[10];
	ctx->vsp=local+12;
	w=(*ftab[32])(ctx,1,local+11,&ftab[32],fqv[425]); /*user::matrix-determinant*/
	local[11]= w;
	local[12]= makeint((eusinteger_t)0L);
	ctx->vsp=local+13;
	w=(pointer)LESSP(ctx,2,local+11); /*<*/
	if (w==NIL) goto IF5699;
	local[11]= (pointer)get_sym_func(fqv[423]);
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.cdr;
	ctx->vsp=local+14;
	w=(pointer)VINNERPRODUCT(ctx,2,local+12); /*v.*/
	local[12]= w;
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(pointer)GREATERP(ctx,2,local+12); /*>*/
	if (w==NIL) goto IF5701;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	goto IF5702;
IF5701:
	local[12]= makeflt(-1.0000000000000000000000e+00);
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	ctx->vsp=local+14;
	w=(pointer)SCALEVEC(ctx,2,local+12); /*scale*/
	local[12]= w;
IF5702:
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(*ftab[31])(ctx,2,local+13,&ftab[31],fqv[424]); /*remove*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)REVERSE(ctx,1,local+13); /*reverse*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)APPLY(ctx,3,local+11); /*apply*/
	local[11]= w;
	goto IF5700;
IF5699:
	local[11]= local[10];
IF5700:
	w = local[11];
	local[10]= w;
	goto CON5695;
CON5696:
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.cdr;
	if (local[5]!=local[10]) goto CON5703;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(*ftab[31])(ctx,2,local+10,&ftab[31],fqv[424]); /*remove*/
	local[10]= w;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.cdr;
	ctx->vsp=local+14;
	w=(pointer)VINNERPRODUCT(ctx,2,local+12); /*v.*/
	local[12]= w;
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(pointer)GREATERP(ctx,2,local+12); /*>*/
	if (w==NIL) goto IF5704;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	goto IF5705;
IF5704:
	local[12]= makeflt(-1.0000000000000000000000e+00);
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	ctx->vsp=local+14;
	w=(pointer)SCALEVEC(ctx,2,local+12); /*scale*/
	local[12]= w;
IF5705:
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	ctx->vsp=local+14;
	w=(*ftab[33])(ctx,3,local+11,&ftab[33],fqv[423]); /*matrix*/
	local[11]= w;
	local[12]= local[11];
	ctx->vsp=local+13;
	w=(*ftab[32])(ctx,1,local+12,&ftab[32],fqv[425]); /*user::matrix-determinant*/
	local[12]= w;
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(pointer)LESSP(ctx,2,local+12); /*<*/
	if (w==NIL) goto IF5706;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.cdr;
	ctx->vsp=local+15;
	w=(pointer)VINNERPRODUCT(ctx,2,local+13); /*v.*/
	local[13]= w;
	local[14]= makeint((eusinteger_t)0L);
	ctx->vsp=local+15;
	w=(pointer)GREATERP(ctx,2,local+13); /*>*/
	if (w==NIL) goto IF5708;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	goto IF5709;
IF5708:
	local[13]= makeflt(-1.0000000000000000000000e+00);
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	ctx->vsp=local+15;
	w=(pointer)SCALEVEC(ctx,2,local+13); /*scale*/
	local[13]= w;
IF5709:
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	ctx->vsp=local+15;
	w=(*ftab[33])(ctx,3,local+12,&ftab[33],fqv[423]); /*matrix*/
	local[12]= w;
	goto IF5707;
IF5706:
	local[12]= local[11];
IF5707:
	w = local[12];
	local[10]= w;
	goto CON5695;
CON5703:
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(*ftab[31])(ctx,2,local+10,&ftab[31],fqv[424]); /*remove*/
	local[10]= w;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.cdr;
	ctx->vsp=local+15;
	w=(pointer)VINNERPRODUCT(ctx,2,local+13); /*v.*/
	local[13]= w;
	local[14]= makeint((eusinteger_t)0L);
	ctx->vsp=local+15;
	w=(pointer)GREATERP(ctx,2,local+13); /*>*/
	if (w==NIL) goto IF5711;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	goto IF5712;
IF5711:
	local[13]= makeflt(-1.0000000000000000000000e+00);
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	ctx->vsp=local+15;
	w=(pointer)SCALEVEC(ctx,2,local+13); /*scale*/
	local[13]= w;
IF5712:
	ctx->vsp=local+14;
	w=(*ftab[33])(ctx,3,local+11,&ftab[33],fqv[423]); /*matrix*/
	local[11]= w;
	local[12]= local[11];
	ctx->vsp=local+13;
	w=(*ftab[32])(ctx,1,local+12,&ftab[32],fqv[425]); /*user::matrix-determinant*/
	local[12]= w;
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(pointer)LESSP(ctx,2,local+12); /*<*/
	if (w==NIL) goto IF5713;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.cdr;
	ctx->vsp=local+16;
	w=(pointer)VINNERPRODUCT(ctx,2,local+14); /*v.*/
	local[14]= w;
	local[15]= makeint((eusinteger_t)0L);
	ctx->vsp=local+16;
	w=(pointer)GREATERP(ctx,2,local+14); /*>*/
	if (w==NIL) goto IF5715;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	goto IF5716;
IF5715:
	local[14]= makeflt(-1.0000000000000000000000e+00);
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	ctx->vsp=local+16;
	w=(pointer)SCALEVEC(ctx,2,local+14); /*scale*/
	local[14]= w;
IF5716:
	ctx->vsp=local+15;
	w=(*ftab[33])(ctx,3,local+12,&ftab[33],fqv[423]); /*matrix*/
	local[12]= w;
	goto IF5714;
IF5713:
	local[12]= NIL;
IF5714:
	w = local[12];
	local[10]= w;
	goto CON5695;
CON5710:
	local[10]= NIL;
CON5695:
	ctx->vsp=local+11;
	w=(pointer)TRANSPOSE(ctx,1,local+10); /*transpose*/
	local[0]= w;
BLK5682:
	ctx->vsp=local; return(local[0]);}

/*estimate-class-name*/
static pointer F5400estimate_class_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[34])(ctx,1,local+0,&ftab[34],fqv[426]); /*pathname*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[35])(ctx,1,local+0,&ftab[35],fqv[427]); /*pathname-name*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[36])(ctx,1,local+0,&ftab[36],fqv[428]); /*string-upcase*/
	local[0]= w;
BLK5717:
	ctx->vsp=local; return(local[0]);}

/*remove-directory-name*/
static pointer F5401remove_directory_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[34])(ctx,1,local+0,&ftab[34],fqv[426]); /*pathname*/
	local[0]= w;
	local[1]= NIL;
	local[2]= fqv[429];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[35])(ctx,1,local+3,&ftab[35],fqv[427]); /*pathname-name*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[37])(ctx,1,local+4,&ftab[37],fqv[430]); /*pathname-type*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,4,local+1); /*format*/
	local[0]= w;
BLK5718:
	ctx->vsp=local; return(local[0]);}

/*convert-irtmodel-to-collada*/
static pointer F5402convert_irtmodel_to_collada(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT5723;}
	local[0]= fqv[431];
	ctx->vsp=local+1;
	w=(*ftab[38])(ctx,1,local+0,&ftab[38],fqv[432]); /*truename*/
	local[0]= w;
	local[1]= fqv[433];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
ENT5723:
	if (n>=3) { local[1]=(argv[2]); goto ENT5722;}
	local[1]= NIL;
ENT5722:
	if (n>=4) { local[2]=(argv[3]); goto ENT5721;}
	local[2]= T;
ENT5721:
ENT5720:
	if (n>4) maerror();
	local[3]= T;
	local[4]= fqv[434];
	local[5]= argv[0];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,4,local+3); /*format*/
	local[3]= T;
	local[4]= fqv[435];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[39])(ctx,1,local+3,&ftab[39],fqv[436]); /*load*/
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F5401remove_directory_name(ctx,1,local+3); /*remove-directory-name*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)F5400estimate_class_name(ctx,1,local+3); /*estimate-class-name*/
	local[3]= w;
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(pointer)INTERN(ctx,1,local+4); /*intern*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)EVAL(ctx,1,local+4); /*eval*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= local[4];
	local[6]= fqv[60];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	w = local[4];
	local[4]= w;
	if (local[1]==NIL) goto IF5725;
	local[5]= local[4];
	local[6]= fqv[34];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF5726;
IF5725:
	local[5]= NIL;
IF5726:
	local[5]= local[4];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)F5349eus2collada(ctx,2,local+5); /*eus2collada*/
	if (local[2]==NIL) goto IF5727;
	ctx->vsp=local+3;
	w=(*ftab[40])(ctx,0,local+3,&ftab[40],fqv[437]); /*exit*/
	local[3]= w;
	goto IF5728;
IF5727:
	local[3]= NIL;
IF5728:
	w = local[3];
	local[0]= w;
BLK5719:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___irtcollada(ctx,n,argv,env)
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
	local[0]= fqv[438];
	ctx->vsp=local+1;
	w=(*ftab[41])(ctx,1,local+0,&ftab[41],fqv[439]); /*require*/
	local[0]= fqv[440];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w!=NIL) goto IF5729;
	local[0]= fqv[441];
	ctx->vsp=local+1;
	w=(*ftab[42])(ctx,1,local+0,&ftab[42],fqv[442]); /*make-package*/
	local[0]= w;
	goto IF5730;
IF5729:
	local[0]= NIL;
IF5730:
	local[0]= fqv[443];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF5731;
	local[0]= fqv[444];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[445],w);
	goto IF5732;
IF5731:
	local[0]= fqv[446];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF5732:
	local[0]= fqv[0];
	local[1]= fqv[447];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF5733;
	local[0]= fqv[0];
	local[1]= fqv[447];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[0];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF5735;
	local[0]= fqv[0];
	local[1]= fqv[448];
	local[2]= fqv[449];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF5736;
IF5735:
	local[0]= NIL;
IF5736:
	local[0]= fqv[0];
	goto IF5734;
IF5733:
	local[0]= NIL;
IF5734:
	ctx->vsp=local+0;
	compfun(ctx,fqv[450],module,F5325symbol__string,fqv[451]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[452],module,F5326__string,fqv[453]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[454],module,F5327string_append,fqv[455]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[456],module,F5328make_attr,fqv[457]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[458],module,F5329make_xml,fqv[459]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[460],module,F5330sxml__xml,fqv[461]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[462],module,F5331xml_output_to_string_stream,fqv[463]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[464],module,F5332cat_normal,fqv[465]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[466],module,F5333cat_clark,fqv[467]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[468],module,F5334eusmodel_description,fqv[469]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[470],module,F5335verificate_unique_strings,fqv[471]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[472],module,F5336eusmodel_link_specs,fqv[473]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[474],module,F5337eusmodel_joint_specs,fqv[475]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[41],module,F5338eusmodel_link_spec,fqv[476]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[477],module,F5339eusmodel_mesh_spec,fqv[478]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[42],module,F5340eusmodel_joint_spec,fqv[479]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[480],module,F5341eusmodel_limit_spec,fqv[481]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[482],module,F5342eusmodel_endcoords_specs,fqv[483]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[484],module,F5343eusmodel_link_description,fqv[485]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[486],module,F5344eusmodel_joint_description,fqv[487]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[488],module,F5345eusmodel_endcoords_description,fqv[489]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[490],module,F5346eusmodel_description__collada,fqv[491]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[492],module,F5347setup_collada_filesystem,fqv[493]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[494],module,F5348range2,fqv[495]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[496],module,F5349eus2collada,fqv[497]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[498],module,F5350collada_node_id,fqv[499]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[500],module,F5351collada_node_name,fqv[501]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[502],module,F5352links_description__collada_library_materials,fqv[503]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[161],module,F5353link_description__collada_materials,fqv[504]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[505],module,F5354mesh_description__collada_material,fqv[506]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[507],module,F5355links_description__collada_library_effects,fqv[508]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[172],module,F5356link_description__collada_effects,fqv[509]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[510],module,F5357mesh_description__collada_effect,fqv[511]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[512],module,F5358matrix__collada_string,fqv[513]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[514],module,F5359find_parent_liks_from_link_description,fqv[515]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[516],module,F5360eusmodel_description__collada_node_transformations,fqv[517]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[518],module,F5361eusmodel_description__collada_node,fqv[519]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[520],module,F5362eusmodel_description__collada_library_visual_scenes,fqv[521]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[522],module,F5363mesh_description__instance_material,fqv[523]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[524],module,F5364link_description__collada_bind_material,fqv[525]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[526],module,F5365eusmodel_description__collada_library_kinematics_scenes,fqv[527]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[528],module,F5366eusmodel_description__collada_library_kinematics_models,fqv[529]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[530],module,F5367eusmodel_description__collada_kinematics_model,fqv[531]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[532],module,F5368eusmodel_description__collada_library_physics_scenes,fqv[533]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[534],module,F5369eusmodel_description__collada_library_physics_models,fqv[535]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[536],module,F5370find_root_link_from_joints_description,fqv[537]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[538],module,F5371find_link_from_links_description,fqv[539]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[540],module,F5372eusmodel_description__collada_links,fqv[541]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[542],module,F5373find_joint_from_link_description,fqv[543]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[544],module,F5374find_child_link_descriptions,fqv[545]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[546],module,F5375matrix__collada_rotate_vector,fqv[547]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[548],module,F5376eusmodel_description__collada_library_articulated_systems,fqv[549]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[550],module,F5377eusmodel_endcoords_description__openrave_manipulator,fqv[551]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[552],module,F5378eusmodel_description__collada_links_tree,fqv[553]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[554],module,F5379joints_description__collada_instance_joints,fqv[555]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[323],module,F5380joint_description__collada_instance_joint,fqv[556]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[557],module,F5381eusmodel_description__collada_library_joints,fqv[558]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[559],module,F5382joints_description__collada_joints,fqv[560]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[561],module,F5383collada_joint_id,fqv[562]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[328],module,F5384joint_description__collada_joint,fqv[563]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[564],module,F5385linear_joint_description__collada_joint,fqv[565]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[566],module,F5386rotational_joint_description__collada_joint,fqv[567]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[568],module,F5387eusmodel_description__collada_scene,fqv[569]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[570],module,F5388eusmodel_description__collada_library_geometries,fqv[571]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[572],module,F5389collada_geometry_id_base,fqv[573]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[574],module,F5390collada_geometry_name_base,fqv[575]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[576],module,F5391links_description__collada_geometries,fqv[577]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[578],module,F5392mesh_object__collada_mesh,fqv[579]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[364],module,F5393link_description__collada_geometry,fqv[580]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[581],module,F5394mesh__collada_indices,fqv[582]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[583],module,F5395mesh_vertices__collada_string,fqv[584]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[585],module,F5396mesh_normals__collada_string,fqv[586]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[587],module,F5397float_vector__collada_string,fqv[588]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[589],module,F5398enum_integer_list,fqv[590]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[591],module,F5399search_minimum_rotation_matrix,fqv[592]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[593],module,F5400estimate_class_name,fqv[594]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[595],module,F5401remove_directory_name,fqv[596]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[597],module,F5402convert_irtmodel_to_collada,fqv[598]);
	local[0]= fqv[599];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF5737;
	local[0]= fqv[600];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[445],w);
	goto IF5738;
IF5737:
	local[0]= fqv[601];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF5738:
	local[0]= fqv[602];
	ctx->vsp=local+1;
	w=(*ftab[43])(ctx,1,local+0,&ftab[43],fqv[603]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<44; i++) ftab[i]=fcallx;
}
