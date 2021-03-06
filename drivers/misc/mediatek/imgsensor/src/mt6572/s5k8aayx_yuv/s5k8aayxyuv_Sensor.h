#ifndef __SENSOR_H
#define __SENSOR_H

//#define MIPI_INTERFACE  
#define PVI_INTERFACE

/*typedef enum _S5K8AAYX_OP_TYPE_ {
        S5K8AAYX_MODE_NONE,
        S5K8AAYX_MODE_PREVIEW,
        S5K8AAYX_MODE_CAPTURE,
        S5K8AAYX_MODE_QCIF_VIDEO,
        S5K8AAYX_MODE_CIF_VIDEO,
        S5K8AAYX_MODE_QVGA_VIDEO
    } S5K8AAYX_OP_TYPE;

extern S5K8AAYX_OP_TYPE S5K8AAYX_g_iS5K8AAYX_Mode;
*/

//#define S5K8AAYX_QVGA_SIZE_PREVIEW

#define S5K8AAYX_PV_BEST_FRAME_RATE_BINNING
//#define S5K8AAYX_ADJ_H_V_BLANKING

// The active sate of STBYN is determined by the TST pin, TST pin state is sampled for STANDBY polarity when RSTN goes high.
// TST:0, STBYN is active low
// TST:1, STBYN is active high.
//#define S5K8AAYX_TST_PIN_HIGH 

// Reminder: Just can un-mask one macro of these 3 macros. if mask these 3 macros, then use mclk 24Mhz, pclk 48Mhz 
// for preview & capture
//#define S5K8AAYX_JPEG_MCLK12M_PCLK24M
//#define S5K8AAYX_JPEG_MCLK24M_PCLK36M 	
//#define S5K8AAYX_JPEG_MCLK24M_PCLK40M		

// Div 10 is the actual frame rate, 300 means 30fps, 75 means 7.5fps
// Plz keep these setting un-changed
#define S5K8AAYX_CAM_NOM_MAX_FPS				300		// 30fps
#define S5K8AAYX_CAM_NOM_MIN_FPS				100		// 10.0fps
#define S5K8AAYX_CAM_NIT_MAX_FPS				300		// 30fps
#define S5K8AAYX_CAM_NIT_MIN_FPS				50		// 5.0fps
#define S5K8AAYX_MCLK                           24

#ifdef MIPI_INTERFACE
   	#define S5K8AAYX_VID_NOM_FIX_FPS		300		// 30fps
#else
	  #define S5K8AAYX_VID_NOM_FIX_FPS		250 	// 25fps
#endif
#define S5K8AAYX_VID_NIT_FIX_FPS			  150		// 15fps

///////////////////////////////////////////////////////////////////////////////
//					Configuable macro End.
//					Notices: Please don't modify the macro below this line
///////////////////////////////////////////////////////////////////////////////


// Msec / 10 is the actual frame time, 1000 means 100ms.
#define S5K8AAYX_CAM_NOM_MIN_FR_TIME			((1000 * 10 * 10) / S5K8AAYX_CAM_NOM_MAX_FPS)
#define S5K8AAYX_CAM_NOM_MAX_FR_TIME			((1000 * 10 * 10) / S5K8AAYX_CAM_NOM_MIN_FPS)
#define S5K8AAYX_CAM_NIT_MIN_FR_TIME			((1000 * 10 * 10) / S5K8AAYX_CAM_NIT_MAX_FPS)
#define S5K8AAYX_CAM_NIT_MAX_FR_TIME			((1000 * 10 * 10) / S5K8AAYX_CAM_NIT_MIN_FPS)

#define S5K8AAYX_VID_NOM_FIX_FR_TIME			((1000 * 10 * 10) / S5K8AAYX_VID_NOM_FIX_FPS)
#define S5K8AAYX_VID_NIT_FIX_FR_TIME			((1000 * 10 * 10) / S5K8AAYX_VID_NIT_FIX_FPS)



// It's for test only, must mark it when check in.
//#define __SW_VIDEO_ADV_RESIZER_SUPPORT__

/* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
#define S5K8AAYX_SXGA_PERIOD_PIXEL_NUMS       2175         
#define S5K8AAYX_SXGA_PERIOD_LINE_NUMS        1607         

/* 3M RESOLUTION SIZE */
#define S5K8AAYX_IMAGE_SENSOR_3M_WIDTH				2048
#define S5K8AAYX_IMAGE_SENSOR_3M_HEIGHT				1536
/* 2M RESOLUTION SIZE */
#define S5K8AAYX_IMAGE_SENSOR_2M_WIDTH				1600
#define S5K8AAYX_IMAGE_SENSOR_2M_HEIGHT				1200
/* 1.3M RESOLUTION SIZE */
#define S5K8AAYX_IMAGE_SENSOR_1_3M_WIDTH			1280
#define S5K8AAYX_IMAGE_SENSOR_1_3M_HEIGHT			1024
/* 1.2M RESOLUTION SIZE */
#define S5K8AAYX_IMAGE_SENSOR_1_2M_WIDTH			1280
#define S5K8AAYX_IMAGE_SENSOR_1_2M_HEIGHT			960
/* 1M RESOLUTION SIZE */
#define S5K8AAYX_IMAGE_SENSOR_1M_WIDTH				1024
#define S5K8AAYX_IMAGE_SENSOR_1M_HEIGHT				768
/* SENSOR VGA SIZE */
#define S5K8AAYX_IMAGE_SENSOR_VGA_WIDTH				640
#define S5K8AAYX_IMAGE_SENSOR_VGA_HEIGHT			480
/* SENSOR QVGA SIZE */
#define S5K8AAYX_IMAGE_SENSOR_QVGA_WIDTH			320
#define S5K8AAYX_IMAGE_SENSOR_QVGA_HEIGHT			240


// Grab Window Setting for preview mode.
#define S5K8AAYX_IMAGE_SENSOR_PV_INSERTED_PIXELS    (2)
#define S5K8AAYX_IMAGE_SENSOR_PV_INSERTED_LINES     (2)

#define S5K8AAYX_IMAGE_SENSOR_PV_WIDTH	 				    (1280-8)
#define S5K8AAYX_IMAGE_SENSOR_PV_HEIGHT					    (960-6)
	
// Grab Window Setting for capture mode.
#define S5K8AAYX_IMAGE_SENSOR_FULL_INSERTED_PIXELS	(2)
#define S5K8AAYX_IMAGE_SENSOR_FULL_INSERTED_LINES		(2)
	
#define S5K8AAYX_IMAGE_SENSOR_FULL_WIDTH			      (1280-8)
#define S5K8AAYX_IMAGE_SENSOR_FULL_HEIGHT			      (960-6)



/* DUMMY NEEDS TO BE INSERTED */
/* SETUP TIME NEED TO BE INSERTED */


/* SENSOR READ/WRITE ID */
/*
#ifdef MIPI_INTERFACE
#define S5K8AAYX_WRITE_ID		0x78		
#define S5K8AAYX_READ_ID		0x79
#else
#define S5K8AAYX_WRITE_ID		0x20		
#define S5K8AAYX_READ_ID		0x21
#endif
*/
#define S5K8AAYX_WRITE_ID		0x20
#define S5K8AAYX_READ_ID		0x21 

//format index
#define S5K8AAYX_PV_FORMAT_INDEX   1 
#define S5K8AAYX_FULL_FORMAT_INDEX 2 

#if 0
//customize
#define CAM_SIZE_QVGA_WIDTH 	320
#define CAM_SIZE_QVGA_HEIGHT 	240
#define CAM_SIZE_VGA_WIDTH 		640
#define CAM_SIZE_VGA_HEIGHT 	480
#define CAM_SIZE_05M_WIDTH 		800
#define CAM_SIZE_05M_HEIGHT 	600
#define CAM_SIZE_1M_WIDTH 		1280
#define CAM_SIZE_1M_HEIGHT 		960
#define CAM_SIZE_2M_WIDTH 		1600
#define CAM_SIZE_2M_HEIGHT 		1200
#define CAM_SIZE_3M_WIDTH 		2048
#define CAM_SIZE_3M_HEIGHT 		1536
#define CAM_SIZE_5M_WIDTH 		2592
#define CAM_SIZE_5M_HEIGHT 		1944
#endif

//
//initial config function
//
int pfInitCfg_VGA(void);
int pfInitCfg_1280X960(void);
int pfInitCfg_FULL(void);

//export functions
UINT32 S5K8AAYXOpen(void);
UINT32 S5K8AAYXControl(MSDK_SCENARIO_ID_ENUM ScenarioId, MSDK_SENSOR_EXPOSURE_WINDOW_STRUCT *pImageWindow, MSDK_SENSOR_CONFIG_STRUCT *pSensorConfigData);
UINT32 S5K8AAYXFeatureControl(MSDK_SENSOR_FEATURE_ENUM FeatureId, UINT8 *pFeaturePara,UINT32 *pFeatureParaLen);
UINT32 S5K8AAYXGetInfo(MSDK_SCENARIO_ID_ENUM ScenarioId, MSDK_SENSOR_INFO_STRUCT *pSensorInfo, MSDK_SENSOR_CONFIG_STRUCT *pSensorConfigData);
UINT32 S5K8AAYXGetResolution(MSDK_SENSOR_RESOLUTION_INFO_STRUCT *pSensorResolution);
UINT32 S5K8AAYXClose(void);

#define Sleep(ms) mdelay(ms)
#define RETAILMSG(x,...)
#define TEXT

#endif /* __SENSOR_H */
