/*
 * RRR_arm.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "RRR_arm".
 *
 * Model version              : 1.142
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Wed May  3 12:04:40 2017
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_RRR_arm_h_
#define RTW_HEADER_RRR_arm_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef RRR_arm_COMMON_INCLUDES_
# define RRR_arm_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* RRR_arm_COMMON_INCLUDES_ */

#include "RRR_arm_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T degtorad[6];                  /* '<Root>/deg to rad' */
  real_T radtodeg2[3];                 /* '<Root>/rad to deg2' */
  real_T radtodeg5[6];                 /* '<Root>/rad to deg5' */
  real_T radtodeg1[3];                 /* '<Root>/rad to deg1' */
  real_T degtorad2[3];                 /* '<Root>/deg to rad2' */
  real_T radtodeg4[6];                 /* '<Root>/rad to deg4' */
  real_T degtorad1[3];                 /* '<Root>/deg to rad1' */
  real_T radtodeg3[3];                 /* '<Root>/rad to deg3' */
  real_T Xd[6];                        /* '<Root>/Xdot' */
  real_T TimeLineTable[3204];          /* '<Root>/Creat Time Table' */
  real_T y[801];
  real_T dv0[801];
  real_T dv1[801];
} B_RRR_arm_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } q_PWORK;                           /* '<Root>/q' */

  struct {
    void *LoggedData;
  } qAandqD_PWORK;                     /* '<Root>/qA and qD' */

  struct {
    void *LoggedData;
  } qdot_PWORK;                        /* '<Root>/qdot' */

  struct {
    void *LoggedData;
  } qdotAandqdotD_PWORK;               /* '<Root>/qdotA and qdotD' */

  struct {
    void *LoggedData;
  } qdotdot_PWORK;                     /* '<Root>/qdotdot' */

  int_T Integrator_IWORK;              /* '<Root>/Integrator' */
} DW_RRR_arm_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE[6];         /* '<Root>/Integrator' */
} X_RRR_arm_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE[6];         /* '<Root>/Integrator' */
} XDot_RRR_arm_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE[6];      /* '<Root>/Integrator' */
} XDis_RRR_arm_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (auto storage) */
struct P_RRR_arm_T_ {
  real_T Kp;                           /* Variable: Kp
                                        * Referenced by:
                                        *   '<Root>/Kp'
                                        *   '<Root>/Kv'
                                        */
  real_T q1_ref1_Gain;                 /* Expression: 30
                                        * Referenced by: '<Root>/q1_ref1'
                                        */
  real_T q2_ref1_Gain;                 /* Expression: 30
                                        * Referenced by: '<Root>/q2_ref1'
                                        */
  real_T q3_ref1_Gain;                 /* Expression: 30
                                        * Referenced by: '<Root>/q3_ref1'
                                        */
  real_T theta1_initial_Value;         /* Expression: 0
                                        * Referenced by: '<Root>/theta1_initial'
                                        */
  real_T theta1dot_initial_Value;      /* Expression: 0
                                        * Referenced by: '<Root>/theta1dot_initial'
                                        */
  real_T theta2_initial_Value;         /* Expression: 0
                                        * Referenced by: '<Root>/theta2_initial'
                                        */
  real_T theta2dot_initial_Value;      /* Expression: 0
                                        * Referenced by: '<Root>/theta2dot_initial'
                                        */
  real_T theta3_initial_Value;         /* Expression: 90
                                        * Referenced by: '<Root>/theta3_initial'
                                        */
  real_T theta3dot_initial_Value;      /* Expression: 0
                                        * Referenced by: '<Root>/theta3dot_initial'
                                        */
  real_T degtorad_Gain;                /* Expression: 0.0175
                                        * Referenced by: '<Root>/deg to rad'
                                        */
  real_T radtodeg2_Gain;               /* Expression: 57.2958
                                        * Referenced by: '<Root>/rad to deg2'
                                        */
  real_T Step_Time;                    /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/constant'
                                        */
  real_T Step1_Time;                   /* Expression: 0
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step1_Y0;                     /* Expression: 0
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step1_YFinal;                 /* Expression: 1
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step2_Time;                   /* Expression: 0
                                        * Referenced by: '<Root>/Step2'
                                        */
  real_T Step2_Y0;                     /* Expression: 0
                                        * Referenced by: '<Root>/Step2'
                                        */
  real_T Step2_YFinal;                 /* Expression: 1
                                        * Referenced by: '<Root>/Step2'
                                        */
  real_T degtorad3_Gain;               /* Expression: 0.0175
                                        * Referenced by: '<Root>/deg to rad3'
                                        */
  real_T radtodeg5_Gain;               /* Expression: 57.2958
                                        * Referenced by: '<Root>/rad to deg5'
                                        */
  real_T radtodeg1_Gain;               /* Expression: 57.2958
                                        * Referenced by: '<Root>/rad to deg1'
                                        */
  real_T qd1_ref_Value;                /* Expression: 0
                                        * Referenced by: '<Root>/qd1_ref'
                                        */
  real_T qd2_ref_Value;                /* Expression: 0
                                        * Referenced by: '<Root>/qd2_ref'
                                        */
  real_T qd3_ref_Value;                /* Expression: 0
                                        * Referenced by: '<Root>/qd3_ref'
                                        */
  real_T degtorad2_Gain;               /* Expression: 0.0175
                                        * Referenced by: '<Root>/deg to rad2'
                                        */
  real_T radtodeg4_Gain;               /* Expression: 57.2958
                                        * Referenced by: '<Root>/rad to deg4'
                                        */
  real_T SFric1_Value;                 /* Expression: 0
                                        * Referenced by: '<Root>/SFric1'
                                        */
  real_T DFric1_Value;                 /* Expression: 200
                                        * Referenced by: '<Root>/DFric1'
                                        */
  real_T SFric2_Value;                 /* Expression: 0
                                        * Referenced by: '<Root>/SFric2'
                                        */
  real_T DFric2_Value;                 /* Expression: 150
                                        * Referenced by: '<Root>/DFric2'
                                        */
  real_T SFric3_Value;                 /* Expression: 0
                                        * Referenced by: '<Root>/SFric3'
                                        */
  real_T DFric3_Value;                 /* Expression: 100
                                        * Referenced by: '<Root>/DFric3'
                                        */
  real_T qdd1_ref_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/qdd1_ref'
                                        */
  real_T qdd2_ref_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/qdd2_ref'
                                        */
  real_T qdd3_ref_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/qdd3_ref'
                                        */
  real_T degtorad1_Gain;               /* Expression: 0.0175
                                        * Referenced by: '<Root>/deg to rad1'
                                        */
  real_T radtodeg3_Gain;               /* Expression: 57.2958
                                        * Referenced by: '<Root>/rad to deg3'
                                        */
  uint8_T MS1_CurrentSetting;          /* Computed Parameter: MS1_CurrentSetting
                                        * Referenced by: '<Root>/MS1'
                                        */
  uint8_T MS2_CurrentSetting;          /* Computed Parameter: MS2_CurrentSetting
                                        * Referenced by: '<Root>/MS2'
                                        */
  uint8_T MS3_CurrentSetting;          /* Computed Parameter: MS3_CurrentSetting
                                        * Referenced by: '<Root>/MS3'
                                        */
  uint8_T MS4_CurrentSetting;          /* Computed Parameter: MS4_CurrentSetting
                                        * Referenced by: '<Root>/MS4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_RRR_arm_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_RRR_arm_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T blkStateChange;
  real_T odeY[6];
  real_T odeF[3][6];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    boolean_T firstInitCondFlag;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_RRR_arm_T RRR_arm_P;

/* Block signals (auto storage) */
extern B_RRR_arm_T RRR_arm_B;

/* Continuous states (auto storage) */
extern X_RRR_arm_T RRR_arm_X;

/* Block states (auto storage) */
extern DW_RRR_arm_T RRR_arm_DW;

/* Model entry point functions */
extern void RRR_arm_initialize(void);
extern void RRR_arm_step(void);
extern void RRR_arm_terminate(void);

/* Real-time Model object */
extern RT_MODEL_RRR_arm_T *const RRR_arm_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'RRR_arm'
 * '<S1>'   : 'RRR_arm/CBGF'
 * '<S2>'   : 'RRR_arm/Creat Time Table'
 * '<S3>'   : 'RRR_arm/M'
 * '<S4>'   : 'RRR_arm/X to q and qdot'
 * '<S5>'   : 'RRR_arm/Xd to qdd'
 * '<S6>'   : 'RRR_arm/Xdot'
 * '<S7>'   : 'RRR_arm/graph'
 * '<S8>'   : 'RRR_arm/path_trajectory'
 */
#endif                                 /* RTW_HEADER_RRR_arm_h_ */
