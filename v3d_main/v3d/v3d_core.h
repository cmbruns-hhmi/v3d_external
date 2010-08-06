/*
 * Copyright (c)2006-2010  Hanchuan Peng (Janelia Farm, Howard Hughes Medical Institute).  
 * All rights reserved.
 */


/************
                                            ********* LICENSE NOTICE ************

This folder contains all source codes for the V3D project, which is subject to the following conditions if you want to use it. 

You will ***have to agree*** the following terms, *before* downloading/using/running/editing/changing any portion of codes in this package.

1. This package is free for non-profit research, but needs a special license for any commercial purpose. Please contact Hanchuan Peng for details.

2. You agree to appropriately cite this work in your related studies and publications.

Peng, H., Ruan, Z., Long, F., Simpson, J.H., and Myers, E.W. (2010) “V3D enables real-time 3D visualization and quantitative analysis of large-scale biological image data sets,” Nature Biotechnology, Vol. 28, No. 4, pp. 348-353, DOI: 10.1038/nbt.1612. ( http://penglab.janelia.org/papersall/docpdf/2010_NBT_V3D.pdf )

Peng, H, Ruan, Z., Atasoy, D., and Sternson, S. (2010) “Automatic reconstruction of 3D neuron structures using a graph-augmented deformable model,” Bioinformatics, Vol. 26, pp. i38-i46, 2010. ( http://penglab.janelia.org/papersall/docpdf/2010_Bioinfo_GD_ISMB2010.pdf )

3. This software is provided by the copyright holders (Hanchuan Peng), Howard Hughes Medical Institute, Janelia Farm Research Campus, and contributors "as is" and any express or implied warranties, including, but not limited to, any implied warranties of merchantability, non-infringement, or fitness for a particular purpose are disclaimed. In no event shall the copyright owner, Howard Hughes Medical Institute, Janelia Farm Research Campus, or contributors be liable for any direct, indirect, incidental, special, exemplary, or consequential damages (including, but not limited to, procurement of substitute goods or services; loss of use, data, or profits; reasonable royalties; or business interruption) however caused and on any theory of liability, whether in contract, strict liability, or tort (including negligence or otherwise) arising in any way out of the use of this software, even if advised of the possibility of such damage.

4. Neither the name of the Howard Hughes Medical Institute, Janelia Farm Research Campus, nor Hanchuan Peng, may be used to endorse or promote products derived from this software without specific prior written permission.

*************/




/****************************************************************************
**
by Hanchuan Peng

Feb, 26 2006
Aug 3, 2006: change to use the new stackutil.h function for 4-byte-size format
Sept 24, 2006: v3d v1.2 add raw-2-byte support
Oct 9, 2006: begin v1.3, add "save" function by pressing 'ctrl-s', and add the "roiPolygon" to each view
Oct 11, 2006: add "crop" function by "ctrl-c', 'ctrl-d', and 'ctrl-left mouse'.
Jan 2/6, 2008: add members to XFormView class "	b_moveCurrentLandmark". "ind_landmarkToBeChanged"
Jan 7, 2008: add new buttons; also separate the ptLocation.h file
Jan 10, 2008: add a wheel event for scrolling through different depth of a stack
March 2, 2008: add the path info for stackutil.h
March 2, 2008: add the function bool convert_data_to_8bit(void * &img, V3DLONG * sz, int datatype);
March 14, 2008: add worm straightening specific codes
March 18, 2008: add two new functions to Image4DSimple class
March 26, 2008: add functions for registration menu
April 2, 2008: add the new menu for all-in-one warping
April 2, 2008: add a button for image processing
April 5, 2008: add a cubic-spline display function for the backbone of worm
April 14, 2008: add xyz rez equalize func
May 3, 2008: change the resampling func
June 8, 2008: add v3d_aboutinfo()
Aug 6, 2008: add a v3d button
Aug 10, 2008: add estimateRoughAmountUsedMemory()
Aug 14, 2008: overload the closeEvent function of XFormWidget() to assume the data get freed
Aug 19, 2008: add proj_alignment_matching_1single_pt()
Aug, 21, 2008: update the iDrawExternalParameter structure
Aug 22, 2008: add a fly brain lobeseg function
Aug 24, 2008: add colormap control which is separated from wano project
Sept 25, 2008: add object files' names in the iDrawExternalParameter()
July 31, 2009: RZC: My4DImage extend to 4D time series color image packed time.
Jan 28-30, 2010: PHC. further adjusting codes for v2.440 and above
**
****************************************************************************/

#ifndef V3d_CORE_H
#define V3d_CORE_H

#include "v3d_compile_constraints.h"

#include "../basic_c_fun/v3d_message.h"

#include "../basic_c_fun/stackutil.h"
#include "../basic_c_fun/color_xyz.h"
#include "../basic_c_fun/basic_4dimage.h"
#include "../basic_c_fun/basic_landmark.h"
#include "../basic_c_fun/basic_surf_objs.h"

#include "../basic_c_fun/img_definition.h"

#include "../neuron_editing/v_neuronswc.h"

#include "colormap.h"

#include "arthurwidgets.h"

#include "../cellseg/template_matching_seg.h"
#include "template_matching_cellseg_dialog.h"


#include <QBasicTimer>
#include <QPolygonF>
//#include <QMainWindow>

class HoverPoints;
class QLineEdit;
class QLabel;
class QScrollBar;
class QSpinBox;
class QRadioButton;
class QPushButton;
class QHBoxLayout;
class QGridLayout;
class QVBoxLayout;
class QCheckBox;
class QTextBrowser;
class MainWindow;
class XFormView;
class XFormWidget;
class BDB_Minus_ConfigParameter;
struct iDrawExternalParameter;
class iDrawMainWindow;
class V3D_atlas_viewerDialog;

struct CurveTracePara; //in curve_trace_para_dialog.h
struct Options_Rotate;

//#include "thread_regist.h"

typedef unsigned short int USHORTINT16;

//class RegistrationThread;
/**********************************************************/

enum ImagePlaneDisplayType {imgPlaneUndefined, imgPlaneX, imgPlaneY, imgPlaneZ};
enum AxisCode {axis_x, axis_y, axis_z, axis_c};
enum ImageResamplingCode {PRS_Z_ONLY, PRS_X_ONLY, PRS_Y_ONLY, PRS_XY_SAME, PRS_XYZ_SAME};
enum ImageMaskingCode {IMC_XYZ_INTERSECT, IMC_XYZ_UNION, IMC_XY, IMC_YZ, IMC_XZ};


//080314: add _v3d suffix for several memory functions, as they are specific to V3D interface
template <class T> int new3dpointer_v3d(T *** & p, V3DLONG sz0, V3DLONG sz1, V3DLONG sz2, unsigned char * p1d);
template <class T> void delete3dpointer_v3d(T *** & p, V3DLONG sz0, V3DLONG sz1, V3DLONG sz2);

template <class T> int new4dpointer_v3d(T **** & p, V3DLONG sz0, V3DLONG sz1, V3DLONG sz2, V3DLONG sz3, unsigned char * p1d);
template <class T> void delete4dpointer_v3d(T **** & p, V3DLONG sz0, V3DLONG sz1, V3DLONG sz2, V3DLONG sz3);


void v3d_aboutinfo();
//

template <class T> QPixmap copyRaw2QPixmap(const T ** p2d, V3DLONG sz0, V3DLONG sz1);
template <class T> QPixmap copyRaw2QPixmap(const T ** p2dRed, const unsigned char ** p2dGreen, const unsigned char ** p2dBlue, V3DLONG sz0, V3DLONG sz1);
template <class T> QPixmap copyRaw2QPixmap_xPlanes(const T **** p4d, V3DLONG sz0, V3DLONG sz1, V3DLONG sz2, V3DLONG sz3, ImageDisplayColorType Ctype, V3DLONG cpos, bool bIntensityRescale, double *p_vmax, double *p_vmin);
template <class T> QPixmap copyRaw2QPixmap_yPlanes(const T **** p4d, V3DLONG sz0, V3DLONG sz1, V3DLONG sz2, V3DLONG sz3, ImageDisplayColorType Ctype, V3DLONG cpos, bool bIntensityRescale, double *p_vmax, double *p_vmin);
template <class T> QPixmap copyRaw2QPixmap_zPlanes(const T **** p4d, V3DLONG sz0, V3DLONG sz1, V3DLONG sz2, V3DLONG sz3, ImageDisplayColorType Ctype, V3DLONG cpos, bool bIntensityRescale, double *p_vmax, double *p_vmin);
template <class T> QPixmap copyRaw2QPixmap(const T **** p4d, V3DLONG sz0, V3DLONG sz1, V3DLONG sz2, V3DLONG sz3, ImageDisplayColorType Ctype, V3DLONG cpos, ImagePlaneDisplayType disType, bool bIntensityRescale, double *p_vmax, double *p_vmin);

QPixmap copyRaw2QPixmap_colormap(const void **** p4d, ImagePixelType dtype, V3DLONG sz0, V3DLONG sz1, V3DLONG sz2, V3DLONG sz3, V3DLONG cpos, const ColorMap *pc, ImagePlaneDisplayType disType);
QPixmap copyRaw2QPixmap_xPlanes_colormap(const void **** p4d, ImagePixelType dtype, V3DLONG sz0, V3DLONG sz1, V3DLONG sz2, V3DLONG sz3, V3DLONG cpos, const ColorMap *pc);
QPixmap copyRaw2QPixmap_yPlanes_colormap(const void **** p4d, ImagePixelType dtype, V3DLONG sz0, V3DLONG sz1, V3DLONG sz2, V3DLONG sz3, V3DLONG cpos, const ColorMap *pc);
QPixmap copyRaw2QPixmap_zPlanes_colormap(const void **** p4d, ImagePixelType dtype, V3DLONG sz0, V3DLONG sz1, V3DLONG sz2, V3DLONG sz3, V3DLONG cpos, const ColorMap *pc);


bool pointInPolygon(double x, double y, const QPolygon & pg);
bool file_exist(const char * filename);

class My4DImage;
bool compute_statistics_objects(My4DImage *grayimg, V3DLONG c, My4DImage * maskimg, LocationSimple * & p_ano, V3DLONG & n_objects);
bool compute_statistics_objects(Vol3DSimple<unsigned char> *grayimg, Vol3DSimple<unsigned short int> * maskimg, LocationSimple * & p_ano, V3DLONG & n_objects);


bool convert_data_to_8bit(void * &img, V3DLONG * sz, int datatype); //080302

QList <LocationSimple> readPosFile(const char * posFile); //080107. obsolete. try not to use. 090725
QList <LocationSimple> readPosFile_usingMarkerCode(const char * posFile); //added 090725
bool readSingleImageFile(char *imgSrcFile, unsigned char * & data1d, V3DLONG * & sz, ImagePixelType & datatype); //080318, added for convenience

QStringList importSeriesFileList_addnumbersort(const QString & individualFileName, TimePackType & timepacktype); //sort file name sbased inserting some number. written by Yu Yang


struct InvidualAtlasFileInfo
{
	int n;			  // index
	QString category; //the name of the GAL4 line, or other categorical info
	QString imgfile;  //the name of the actual image file
	bool exist;       //if the file exist or not
	RGBA8 color;
	bool on;
};

QList <InvidualAtlasFileInfo> readAtlasFormatFile(const char * filename); //081124


class V3dR_GLWidget;
class Renderer_tex2;

int mergeback_mmunits_to_neuron_path(int n_end_nodes, vector< vector<V_NeuronSWC_unit> > & mmUnit, V_NeuronSWC_list & tNeuron);

class My4DImage : public Image4DSimple
{
public:
	double at(int x, int y, int z, int c=0); //return a double number because it can always be converted back to UINT8 and UINT16 without information loss
	void **** getData(ImagePixelType & dtype);
	void **** getData() {return data4d_virtual;}
	bool isEmpty() {return (!data4d_virtual) ?  true : false; }

	bool valid() {
    return (!data4d_virtual || this->Image4DSimple::valid() ) ?  false : true;
    }

	void loadImage(char filename[]);
	void setupData4D();
	bool updateminmaxvalues();
	void loadImage(V3DLONG imgsz0, V3DLONG imgsz1, V3DLONG imgsz2, V3DLONG imgsz3, int imgdatatype); //an overloaded function to create a blank image

	void setFocusX(int x) {curFocusX = (x>=1 && x <= this->getXDim()) ? x-1 : -1;}
	void setFocusY(int y) {curFocusY = (y>=1 && y <= this->getYDim()) ? y-1 : -1;}
	void setFocusZ(int z) {curFocusZ = (z>=1 && z <= this->getZDim()) ? z-1 : -1;}

	My4DImage();
	~My4DImage();

	//private:   // FIXME: It should be private 
	float **** data4d_float32;
	USHORTINT16 **** data4d_uint16;
	unsigned char **** data4d_uint8;
	void **** data4d_virtual;

	void updateViews();	//090211

	bool reshape(V3DLONG rsz0, V3DLONG rsz1, V3DLONG rsz2, V3DLONG rsz3);	//080930
	bool permute(V3DLONG dimorder[4]); //081001

	double * p_vmax, * p_vmin; //whole volume max/min values. Use pointer to handle multiple channels separately
	double getChannalMinIntensity(V3DLONG channo);
	double getChannalMaxIntensity(V3DLONG channo);

	bool bLinkFocusViews;
	bool bDisplayFocusCross;
	bool bImgValScaleDisplay;
	bool bLookingGlass;

	ColorMap *colorMap; //080824: copied from wano  // FIXME: It should be private.

	void createColorMap(int len, ImageDisplayColorType c=colorPseudoMaskColor);
	void switchColorMap(int len, ImageDisplayColorType c);
	void getColorMapInfo(int &len, ImageDisplayColorType &c);

	int curFocusX, curFocusY, curFocusZ;
	XFormView *p_xy_view, *p_yz_view, *p_zx_view;

	QTextBrowser *p_focusPointFeatureWidget;

	XFormWidget *p_mainWidget;

	void cleanExistData_butKeepFileName();
	void cleanExistData();
	void cleanExistData_only4Dpointers();
	bool setNewImageData(unsigned char *ndata1d, V3DLONG nsz0, V3DLONG nsz1, V3DLONG nsz2, V3DLONG nsz3, ImagePixelType ndatatype, V3DLONG nszt=-1, TimePackType tpk=TIME_PACK_NONE);//nszt==-1 will not reset the ntimepoints and pack type

	void set_xy_view(XFormView *p) {p_xy_view = p;}
	void set_yz_view(XFormView *p) {p_yz_view = p;}
	void set_zx_view(XFormView *p) {p_zx_view = p;}
	XFormView * get_xy_view() {return p_xy_view;}
	XFormView * get_yz_view() {return p_yz_view;}
	XFormView * get_zx_view() {return p_zx_view;}

	void setFocusFeatureView(QTextBrowser *p) {p_focusPointFeatureWidget = p;}
	QTextBrowser *getFocusFeatureView() {return p_focusPointFeatureWidget;}
	void setFocusFeatureViewText();

	void setMainWidget(XFormWidget *p) {p_mainWidget=p;}
	XFormWidget * getXWidget() {return p_mainWidget;}

	void setFlagLinkFocusViews(bool t) {bLinkFocusViews = t;}
	bool getFlagLinkFocusViews() {return bLinkFocusViews;}
	void setFlagDisplayFocusCross(bool t) {bDisplayFocusCross = t;}
	bool getFlagDisplayFocusCross() {return bDisplayFocusCross;}

	void setFlagImgValScaleDisplay(bool t) {bImgValScaleDisplay=t;}
	bool getFlagImgValScaleDisplay() {return bImgValScaleDisplay;}

	void setFlagLookingGlass(bool t) {bLookingGlass=t;}
	bool getFlagLookingGlass() {return bLookingGlass;}

	void recordFocusProperty(PxLocationUsefulness t);
	V3DLONG find_closest_control_pt(int sx, int sy, int sz, double & dmin);
	V3DLONG find_closest_control_pt_thres(int sx, int sy, int sz, double rr, double & dmin);

	QList <LocationSimple> listLandmarks; //listUserDefinedLocation;
	QList <PtIndexAndParents> listLocationRelationship;
	QList <InvidualAtlasFileInfo> listAtlasFiles; //081123
	int atlasColorBlendChannel; //081206
	bool bUseFirstImgAsMask; //081207
	QString curSearchText; //081207

	bool compute_rgn_stat(LocationSimple & pt, int channo);
	void loadLandmarkFromFile();
	void saveLandmarkToFile();
	void exportLandmarkToPointCloudAPOFile();
	void exportLandmarkandRelationToSWCFile();
	void exportNeuronToSWCFile();

	//int landmarkMatchingMethod; //080820: should be PointMatchMethodType but I will force to convert to that type in the code
	//BDB_Minus_ConfigParameter * p_flybrain_lobeseg_para; //080822

	void computePointNeighborMoment(int x, int y, int z, int c, double & curptval, double & ave, double & sdev, double & skew, double & curt);
	void computePointNeighborMoment(LocationSimple & L, int c); //overload for convenience

	bool saveVANO_data(); //081213
	bool saveMovie(); //081213
	bool saveFile(); //061009
	bool saveFile(char filename[]); //061010, provided for convenience
	void crop(int landmark_crop_opt); //061010
	void crop(V3DLONG bpos_x, V3DLONG epos_x, V3DLONG bpos_y, V3DLONG epos_y, V3DLONG bpos_z, V3DLONG epos_z, V3DLONG bpos_c, V3DLONG epos_c, int landmark_crop_opt);
	bool maskBW_roi_bbox(unsigned char tval, V3DLONG c_min, V3DLONG c_max, ImageMaskingCode my_maskcode, bool b_inside);
	bool maskBW_roi(unsigned char tval, V3DLONG c_min, V3DLONG c_max, ImageMaskingCode my_maskcode, bool b_inside);
	bool maskBW_channel(V3DLONG mask_channel_no);

	bool invertcolor(int channo); //channo < 0 will invert all channels. Only works for uint8
	bool scaleintensity(int channo, double lower_th, double higher_th, double target_min, double target_max); //map the value linear from [lower_th, higher_th] to [target_min, target_max].
	bool thresholdintensity(int channo, double th); //anything < th will be 0, others unchanged
	bool binarizeintensity(int channo, double th); //anything < th will be 0, others will be 1

	//  void rotate(double a_xy, double a_yz, double a_zx); //061010
	bool rotate(ImagePlaneDisplayType ptype, const Options_Rotate & r_opt);
	bool flip(AxisCode my_axiscode); //080930

	//080314: add worm project specific codes

	bool b_proj_worm_mst_diameter_set;

/*	bool proj_worm_random_landmarking(int kch, double Kfactor, V3DLONG KK);
	bool proj_worm_mst_diameter(bool b_keepDiameterOnly);
	bool proj_worm_bdb_backbone();
	//  bool proj_worm_cubic_spline_backbone();
	bool proj_worm_straightening(bool b_Restacking, int OutWid);
*/


	V_NeuronSWC_list tracedNeuron; //090117, 090207 changed from V_NeuronSWC
	V3DLONG last_hit_landmark, cur_hit_landmark;
	BoundingBox trace_bounding_box; //090727 RZC: for trace from local view
	float trace_z_thickness; //090727 RZC: weight for z-distance of graph

	bool proj_trace_deformablepath_one_point(V3DLONG startmark_id); // 090603 RZC: output a shortest path tree
	bool proj_trace_deformablepath_one_point_to_allotherpoints(V3DLONG startmark_id); //090609: phc. one pt to all other points
	bool proj_trace_deformablepath_two_points(V3DLONG startmark_id, V3DLONG endmark_id, bool b_select_para=false, int method_code=0); //method code = 0 for shortest path and 1 for deformable model only
	bool proj_trace_deformablepath_two_points(V3DLONG startmark_id, V3DLONG endmark_id, int npoints, bool b_select_para, bool b_fitradius, int method_code); //overloading function provided for convenience
	bool proj_trace_deformablepath_two_points_basic(LocationSimple & p1, LocationSimple & p2, CurveTracePara & trace_para);
	bool proj_trace_deformablepath_two_points_adaptive(LocationSimple & p1, LocationSimple & p2, CurveTracePara & trace_para);
	int proj_trace_deformablepath_two_points_shortestdist(LocationSimple & p1, LocationSimple & p2, CurveTracePara & trace_para);
	int proj_trace_deformablepath_all_points_shortestdist(LocationSimple & p0, vector<LocationSimple> & pp, CurveTracePara & trace_para) ;
	bool proj_trace_smooth_downsample_last_traced_neuron(CurveTracePara & trace_para, int seg_begin, int seg_end);
	bool proj_trace_shortestpath_rgnaroundcurve(CurveTracePara & trace_para, int seg_begin, int seg_end);
	bool proj_trace_compute_radius_of_last_traced_neuron(CurveTracePara & trace_para, int seg_begin, int seg_end, float myzthickness);
	bool proj_trace_add_curve_segment(vector<XYZ> &loc_list, int chno);

//	int mergeback_mmunits_to_neuron_path(int n_end_nodes, vector< vector<V_NeuronSWC_unit> > & mmUnit, V_NeuronSWC_list & tNeuron);

	bool proj_trace_deformNeuronSeg(V3DLONG node_id, NeuronTree *p_tree, bool b_select_para=true);
	bool proj_trace_profileNeuronSeg(V3DLONG node_id, NeuronTree *p_tree, bool b_dispfig);

	bool proj_trace_mergeOneClosebyNeuronSeg(V3DLONG node_id, NeuronTree *p_tree);
	bool proj_trace_mergeAllClosebyNeuronNodes(NeuronTree *p_tree);
	bool proj_trace_mergeAllClosebyNeuronNodes();

	QList <V_NeuronSWC_list> tracedNeuron_historylist;//090119, 090207 changed from V_NeuronSWC
	static const int MAX_history = 20;
	int cur_history;
	void proj_trace_history_append(V_NeuronSWC_list & tNeuron);
	void proj_trace_history_append();
	void proj_trace_history_undo(V_NeuronSWC_list & tNeuron);
	void proj_trace_history_undo();
	void proj_trace_history_redo(V_NeuronSWC_list & tNeuron);
	void proj_trace_history_redo();

	bool proj_trace_changeNeuronSegType(V3DLONG node_id, NeuronTree *p_tree);
	bool proj_trace_changeNeuronSegRadius(V3DLONG node_id, NeuronTree *p_tree);
	bool proj_trace_reverseNeuronSeg(V3DLONG node_id, NeuronTree *p_tree);
	bool proj_trace_deleteNeuronSeg(V3DLONG node_id, NeuronTree *p_tree);
	double proj_trace_measureLengthNeuronSeg(V3DLONG node_id, NeuronTree *p_tree);
	bool proj_trace_breakNeuronSeg(V3DLONG node_id, NeuronTree *p_tree);
	bool proj_trace_joinNearbyNeuronSegs_pathclick(V3DLONG node_id, NeuronTree *p_tree);
	bool proj_trace_joinNearbyNeuronSegs_markclick(V3DLONG node_id, NeuronTree *p_tree);
	bool proj_trace_joinAllNeuronSegs(V3DLONG node_id, NeuronTree *p_tree);
	// load traced neuron to 3D view
	void update_3drenderer_neuron_view();
	void update_3drenderer_neuron_view(V3dR_GLWidget* glwidget, Renderer_tex2* renderer);


	bool proj_general_principal_axis(ImagePlaneDisplayType ptype);
	bool proj_general_resampling(ImageResamplingCode mycode, double target_rez, double cur_rez, int interp_method);
	bool proj_general_resampling_landmark_only(ImageResamplingCode mycode, double target_rez, double cur_rez);
	bool proj_general_landmark_plusminus_constant(ImageResamplingCode mycode, double cval);
	bool proj_general_projection(AxisCode myaxis, V3DLONG mincoord, V3DLONG maxcoord);
	bool proj_general_blend_channel_real(My4DImage * pBlendDstImg, My4DImage * pBlendSrcImg, V3DLONG chnoBlendSrcImg, double rr, double gg, double bb, bool b_assignVal_NoComparison);
	bool proj_general_blend_channels();
	bool proj_general_blend_atlasfiles();	//081124
	bool proj_general_split_channels(bool b_keepallchannels, int chno);
	bool proj_general_stitchTwoImages(V3DLONG channo);
	bool proj_general_hist_display();
	bool proj_general_linear_adjustment();
	bool proj_general_hist_equalization(unsigned char lowerbound, unsigned char higherbound);
	bool proj_general_convertIndexedImg2RGB();
	bool proj_general_scaleandconvert28bit(int lb, int ub); //lb, ub: lower bound, upper bound
	bool proj_general_convert16bit_to_8bit(int shiftnbits);
	bool proj_general_convert32bit_to_8bit(int shiftnbits);
	bool proj_general_maskBlue2Zero();


	QList <LocationSimple> autoMarkerFromImg(V3DLONG chno);
	QList <LocationSimple> autoMarkerFromImg(V3DLONG chno, BoundingBox bbox, float zthickness);
/*
	bool proj_alignment_seed_grid(int kch);
	bool proj_alignment_seed_gradient(int kch);
	bool proj_alignment_seed_curvature(int kch);
	bool proj_alignment_seed_random(int kch, double Kfactor, V3DLONG KK);
	bool proj_alignment_seed_file(QString curfile);
	bool proj_alignment_global();
	bool proj_alignment_global_real(My4DImage * pSubjectImg);
	bool proj_alignment_affine_matching_landmarks();
	bool proj_alignment_affine_matching_landmarks_real(My4DImage * pSubjectImg);
	bool proj_alignment_flybrain_lobeseg();
	bool proj_alignment_matching_point();
	bool proj_alignment_matching_point_real(My4DImage * pSubjectImg); //the real function for computing
	bool proj_alignment_matching_1single_pt(int markerIndex_target);
	//bool proj_alignment_matching_1single_pt_real(My4DImage * pSubjectImg, int pt_ind);
	bool proj_alignment_matching_1single_pt_real(My4DImage * pSubjectImg, int markerIndex_target, int markerIndex_subject);
	bool proj_alignment_warp_using_landmarks_real(My4DImage * pSubjectImg); //the real function for computing
	bool proj_alignment_warp_using_landmarks(bool b_overwrite_original);
	bool proj_alignment_find_landmark_and_warp(bool b_overwrite_original); //the all-in-one matching and warping

	RegistrationThread reg_thread;

	bool proj_cellseg_templatematching();
	bool proj_cellseg_cellcounting(); //for Yu Yang. 090706
	bool proj_cellseg_watershed();
	bool proj_cellseg_levelset();
	bool proj_cellseg_GaussianFit_pos(V3DLONG posx, V3DLONG posy, V3DLONG posz, V3DLONG posc, int nGauss, bool b_isotropic);

*/
};


/**********************************************************/
bool getFocusCrossLinePos(int & focusPosInWidth, int & focusPosInHeight, My4DImage * imgData, ImagePlaneDisplayType Ptype);


class XFormView : public ArthurFrame //class XFormView : public QWidget
{
    Q_OBJECT

//    Q_PROPERTY(bool animation READ animation WRITE setAnimation)
//    Q_PROPERTY(double shear READ shear WRITE changeShear)
//    Q_PROPERTY(double rotation READ rotation WRITE changeRotation)
    Q_PROPERTY(double scale READ scale WRITE changeScale)

public:
    XFormView(QWidget *parent);
	void setImgData(ImagePlaneDisplayType ptype, My4DImage * pdata, ImageDisplayColorType ctype);

    void paint(QPainter *);
    void drawPixmapType(QPainter *painter);
    void drawLookingGlassMap(QPainter *painter, QPoint *curPt);
	void drawSelectedLocations(QPainter *painter, QList <LocationSimple> *curList, QList <PtIndexAndParents> * curRelation);

    void drawROI(QPainter *painter);

	int disp_width, disp_height;
	double disp_scale;
	int get_disp_width() {return disp_width;}
	int get_disp_height() {return disp_height;}
	double get_disp_scale() {return disp_scale;}
	void set_disp_width(int a) {disp_width = a;}
	void set_disp_height(int a) {disp_height = a;}
	void set_disp_scale(double a) {disp_scale = a; }

    void mousePressEvent(QMouseEvent *e);
    void mouseLeftButtonPressEvent(QMouseEvent *e);
    void mouseRightButtonPressEvent(QMouseEvent *e);

    void mouseDoubleClickEvent(QMouseEvent * e);

	void mouseMoveEvent (QMouseEvent * e);
    void enterEvent (QEvent * e);
    void leaveEvent (QEvent * e);

	void wheelEvent(QWheelEvent * e); //add this on 2008-01-10

	//void dragMoveEvent(QDragMoveEvent * e); //090212

    void dispHistogram();
	QRect getRoiBoundingRect();
	void deleteROI();
	const QPolygon & getRoi() {return roiPolygon;}

//    void resizeEvent(QResizeEvent *e);

    //QLineEdit *textEditor; //080131

    double scale() const { return m_scale; }

    int focusPlaneCoord() {return cur_focus_pos;}
	ImagePlaneDisplayType focusPlaneType() {return Ptype;}

public slots:
    void changeScale(int scale);

    void updateViewPlane() {changeFocusPlane(cur_focus_pos);} // 090504 RZC: make FocusPlane image updated from image stack

    void changeFocusPlane(int c);
    void changeColorType(ImageDisplayColorType c);

    void setPixmapType();
    void reset();

	void popupImageProcessingDialog();
	void popupImageProcessingDialog(QString item); //added on 080613

signals:
    void scaleChanged(int scale);
//    void colorTypeChanged(ImageDisplayColorType c); //probably should be deleted later
    void focusXChanged(int x_new);
    void focusYChanged(int y_new);
    void focusZChanged(int z_new);

protected:
    void keyPressEvent ( QKeyEvent * e);

public:
	QPolygon roiPolygon;//061009
private:
    enum XFormType { VectorType, PixmapType, TextType};

    double m_scale;
	QPointF curDisplayCenter;
	QPointF curDisplayCenter0;

	QPoint curMousePos;
	bool bMouseCurorIn;

	QPoint dragStartPosition;

	QCursor myCursor;

	//QPoint curMouseShiftPressPos; //080102

    XFormType Gtype;
    ImageDisplayColorType Ctype;
    ImagePlaneDisplayType Ptype;

    QPixmap pixmap; //xy plane

    int cur_focus_pos;

	My4DImage * imgData; //a reference to the real data stored in the XFormWidget

	bool b_displayFocusCrossLine;
	int focusPosInWidth, focusPosInHeight;

	bool b_moveCurrentLandmark;
	V3DLONG ind_landmarkToBeChanged;
};

struct BlendingImageInfo
{
	My4DImage * pimg;
	int channo;
	double rr, gg, bb;
};

class V3dR_MainWindow;
class MainWindow;
struct iDrawExternalParameter
{
	My4DImage* image4d;
	XFormWidget *xwidget;
	V3dR_MainWindow *window3D; //pointer to 3DView main window, by RZC 080921, 090503
	QList <V3dR_MainWindow *> * p_list_3Dview_win; //by PHC, 081003. This is linked to a mainwindow, which will keep record of all generated V3dR_MainWindows
	MainWindow *V3Dmainwindow; //the pointer to the V3D main window, so that V3dR can get the global setting preferences. add on 090503

	QStringList swc_file_list;
	QStringList pointcloud_file_list;
	QString surface_file;
	QString labelfield_file;

	//some external controls for the 3d viewer
	//float zthickness; //the default z-thickness when start the 3d viewer. 100626

	int b_local; // 0,1,2
	LocationSimple local_start, local_size;//090628 RZC
	QPoint local_win_pos;
	QSize local_win_size;

	bool b_use_512x512x256;
	bool b_still_open;
	iDrawExternalParameter() {b_use_512x512x256=true; b_local=b_still_open=false; image4d=0; xwidget=0; window3D=0; p_list_3Dview_win=0; V3Dmainwindow=0; /*zthickness=1;*/}
	~iDrawExternalParameter() {if (xwidget==0 && image4d) delete image4d;}
};


class XFormWidget : public QWidget //class XFormWidget : public QMainWindow
{
    Q_OBJECT;

public:
    XFormWidget(QWidget *parent);
    XFormWidget(QWidget *parent, Qt::WidgetAttribute f); //080814 add the second arugment. This is eventually not used. Just keep here for further use
    ~XFormWidget();

    void initialize();
	void createGUI();
	void connectEventSignals();
	void disconnectEventSignals();
	void updateDataRelatedGUI();
    bool setCTypeBasedOnImageData();
	void cleanData();
	bool loadData();
	bool importLeicaData();
	bool importGeneralImgSeries(const QStringList & mylist, TimePackType timepacktype);

    bool loadFile(QString filename);
    bool importGeneralImageFile(QString filename);
    bool importLeicaFile(QString filename);
	QString userFriendlyCurrentFile() {return (openFileNameLabel);}
	QString getOpenFileNameLabel() {return openFileNameLabel;}

	bool saveData();
	bool saveFile(QString filename);

	My4DImage * getImageData() {return imgData;} //080326

	bool newProcessedImage(QString filename, unsigned char *ndata1d, V3DLONG nsz0, V3DLONG nsz1, V3DLONG nsz2, V3DLONG nsz3, ImagePixelType ndatatype); //080408
	// for replace imageData and filename
	bool setImageData(unsigned char *ndata1d, V3DLONG nsz0, V3DLONG nsz1, V3DLONG nsz2, V3DLONG nsz3, ImagePixelType ndatatype); //090818 RZC
	bool setCurrentFileName(QString cfilename);


#define __used_by_v3d_interface__
	// in mainwindow_interface.h
	bool transferImageData(Image4DSimple *img, unsigned char *a);
	QList<QPolygon> get3ViewROI();
	bool set3ViewROI(QList<QPolygon> & roi_list);
	void close3DWindow();
	void closeROI3DWindow();
	void pushObjectIn3DWindow();
	void pushImageIn3DWindow();
	int pushTimepointIn3DWindow(int timepoint);
	bool screenShot3DWindow(QString filename);
	bool screenShotROI3DWindow(QString filename);


	//for communication of windows
	void setMainControlWindow(MainWindow * p) {p_mainWindow = p;}
	MainWindow * getMainControlWindow() {return p_mainWindow;}

	void forceToChangeFocus(int x, int y, int z); //081210
	void changeFocusFromExternal(int x, int y, int z); //this should be called from external. When no cross-image communication is needed, should not use this.
    void changeFocusToExternal(int newx, int newy, int newz); // this is the function to call other image-view's changeFocusFromExternal() function

	void setWindowTitle_Prefix(char *prefix);
	void setWindowTitle_Suffix(char *sfix);

	V3DLONG estimateRoughAmountUsedMemory(); //080810


	My4DImage * selectSubjectImage();
	My4DImage * selectImage();
	QList <BlendingImageInfo> selectBlendingImages();

	void setColorType(ImageDisplayColorType myctype) {Ctype = myctype;}
	ImageDisplayColorType getColorType() {return Ctype;}

	iDrawExternalParameter mypara_3Dview;
	iDrawExternalParameter mypara_3Dlocalview;
	V3D_atlas_viewerDialog *atlasViewerDlg;

	double disp_zoom; //081114
	bool b_use_dispzoom;

	bool bDispMarkerLabel;

protected:

	void closeEvent ( QCloseEvent * event );  //080814
	//void focusInEvent ( QFocusEvent * event ); //080829

private:
	// communication of different images windows
	MainWindow * p_mainWindow;
	bool bSendSignalToExternal, bAcceptSignalFromExternal;

	My4DImage *imgData;
    ImageDisplayColorType Ctype;

	QString openFileNameLabel;

	// Interface components
	bool bExistGUI;
    bool bLinkFocusViews;
    bool bDisplayFocusCross;

	QGroupBox *dataGroup, *viewGroup, *infoGroup;
	QGroupBox *mainGroup, *coordGroup, *scaleGroup, *typeGroup;

	QScrollBar *xSlider, *ySlider, *zSlider;
	QSpinBox *xValueSpinBox, *yValueSpinBox, *zValueSpinBox;
	QLabel *xSliderLabel, *ySliderLabel, *zSliderLabel;
	QCheckBox *linkFocusCheckBox;
	QCheckBox *displayFocusCrossCheckBox;

    QScrollBar *xScaleSlider, *yScaleSlider, *zScaleSlider;
	QLabel *xScaleSliderLabel, *yScaleSliderLabel, *zScaleSliderLabel;
	QCheckBox *lookingGlassCheckBox;
	QPushButton *zoomWholeViewButton;

    QRadioButton *colorRedType, *colorGreenType, *colorBlueType, *colorAllType;
    QRadioButton *colorRed2GrayType, *colorGreen2GrayType, *colorBlue2GrayType, *colorAll2GrayType;
    QRadioButton *colorMapDispType;
	QCheckBox *imgValScaleDisplayCheckBox;

	QCheckBox * cBox_bSendSignalToExternal, * cBox_bAcceptSignalFromExternal;

    QPushButton *landmarkCopyButton, *landmarkPasteButton, *landmarkSaveButton, *landmarkLoadButton; //080107
	QPushButton *landmarkManagerButton;
	//QCheckBox *landmarkLabelDispCheckBox;

    QPushButton *resetButton, *openFileNameButton, *whatsThisButton, *imgProcessButton, *imgV3DButton; //, *imgV3DROIButton;

	QHBoxLayout *allLayout;
	  QVBoxLayout *dataGroupLayout;
	    QGridLayout *xyzViewLayout;
	    QVBoxLayout *infoGroupLayout;
	  QVBoxLayout *mainGroupLayout;
	    QGridLayout *coordGroupLayout;
	    QGridLayout *scaleGroupLayout;
	    QGridLayout *typeGroupLayout;
	    QGridLayout *LandmarkGroupLayout;

	XFormView *xy_view; //change in Z
    XFormView *yz_view; //change in X
    XFormView *zx_view; //change in Y

	QTextBrowser *focusPointFeatureWidget;

    QMenu menuTriviewZoom;
	void createMenuOfTriviewZoom();

    QMenu menu3DViewer;
	void createMenuOf3DViewer();

public slots:
//    void changeColorType(ImageDisplayColorType c);


    void setColorRedType();
    void setColorGreenType();
    void setColorBlueType();
    void setColorAllType();
    void setColorRed2GrayType();
    void setColorGreen2GrayType();
    void setColorBlue2GrayType();
    void setColorAll2GrayType();
	void setColorMapDispType();
	void switchMaskColormap();

    void toggleLinkFocusCheckBox();
    void toggleDisplayFocusCrossCheckBox();
	void toggleImgValScaleDisplay();
	void toggleLookingGlassCheckBox();

	void doMenuOfTriviewZoom();
    void triview_zoomin();
    void triview_zoomout();
	void triview_zoom1();
	void triview_zoom2();
	void triview_zoomhalf();
	void triview_setzoom(double z, bool b_multiply); //b_multiply determine is z is the target zoom, or the target zoom should be product of the current zoom multply z

	void popupImageProcessingDialog();
	void popupImageProcessingDialog(QString item);
	void doImage3DView();
	void doImage3DLocalMarkerView();
	void doImage3DLocalRoiView();
	void doImage3DView(bool tmp_b_use_512x512x256, int b_local=0);
	void doMenuOf3DViewer();
	void aboutInfo();

    void setOpenFileName();
    void reset();

	//this should be called from external. When no cross-image communication is needed, should not use this.
	void changeFocusXToExternal(int c); //will call changeFocusToExternal(int,int,int)
	void changeFocusYToExternal(int c); //will call changeFocusToExternal(int,int,int)
	void changeFocusZToExternal(int c); //will call changeFocusToExternal(int,int,int)

	void toggleCheckBox_bSendSignalToExternal();
	void toggleCheckBox_bAcceptSignalFromExternal();

	void copyLandmarkToPublicBuffer();
	void pasteLandmarkFromPublicBuffer();
	void saveLandmarkToFile();
	void loadLandmarkFromFile();
	void openLandmarkManager();

	void toggleLandmarkLabelDisp() {bDispMarkerLabel = !bDispMarkerLabel; this->updateViews();}

	void launchAtlasViewer(int curTab=0);

	void cascadeWindows();
	void updateViews(); //090615: a convenient function to call my4dimage updateViews()


signals:
    void external_focusXChanged(int c);
    void external_focusYChanged(int c);
    void external_focusZChanged(int c);
};

#endif // v3d_core.h

