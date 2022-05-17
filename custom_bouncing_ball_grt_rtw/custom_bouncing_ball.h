/*
 * custom_bouncing_ball.h
 *
 * Code generation for model "custom_bouncing_ball".
 *
 * Model version              : 1.4
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Tue May 17 16:33:39 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_custom_bouncing_ball_h_
#define RTW_HEADER_custom_bouncing_ball_h_
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef custom_bouncing_ball_COMMON_INCLUDES_
#define custom_bouncing_ball_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                               /* custom_bouncing_ball_COMMON_INCLUDES_ */

#include "custom_bouncing_ball_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T InitialVelocity;              /* '<Root>/Initial Velocity ' */
  real_T IntegratorSecondOrder_o2;     /* '<Root>/Integrator, Second-Order' */
} B_custom_bouncing_ball_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  int_T IntegratorSecondOrder_MODE;    /* '<Root>/Integrator, Second-Order' */
  boolean_T InitialVelocity_FirstOutputTime;/* '<Root>/Initial Velocity ' */
  boolean_T IntegratorSecondOrder_DWORK1;/* '<Root>/Integrator, Second-Order' */
} DW_custom_bouncing_ball_T;

/* Continuous states (default storage) */
typedef struct {
  real_T IntegratorSecondOrder_CSTATE[2];/* '<Root>/Integrator, Second-Order' */
} X_custom_bouncing_ball_T;

/* State derivatives (default storage) */
typedef struct {
  real_T IntegratorSecondOrder_CSTATE[2];/* '<Root>/Integrator, Second-Order' */
} XDot_custom_bouncing_ball_T;

/* State disabled  */
typedef struct {
  boolean_T IntegratorSecondOrder_CSTATE[2];/* '<Root>/Integrator, Second-Order' */
} XDis_custom_bouncing_ball_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Position;                     /* '<Root>/Position' */
  real_T Velocity;                     /* '<Root>/Velocity' */
} ExtY_custom_bouncing_ball_T;

/* Parameters (default storage) */
struct P_custom_bouncing_ball_T_ {
  real_T g;                            /* Variable: g
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T r;                            /* Variable: r
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T v;                            /* Variable: v
                                        * Referenced by: '<Root>/Initial Velocity '
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<Root>/Memory'
                                        */
  real_T IntegratorSecondOrder_ICX;    /* Expression: 0.0
                                        * Referenced by: '<Root>/Integrator, Second-Order'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_custom_bouncing_ball_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_custom_bouncing_ball_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
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
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_custom_bouncing_ball_T custom_bouncing_ball_P;

/* Block signals (default storage) */
extern B_custom_bouncing_ball_T custom_bouncing_ball_B;

/* Continuous states (default storage) */
extern X_custom_bouncing_ball_T custom_bouncing_ball_X;

/* Block states (default storage) */
extern DW_custom_bouncing_ball_T custom_bouncing_ball_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_custom_bouncing_ball_T custom_bouncing_ball_Y;

/* Model entry point functions */
extern void custom_bouncing_ball_initialize(void);
extern void custom_bouncing_ball_step(void);
extern void custom_bouncing_ball_terminate(void);

/* Real-time Model object */
extern RT_MODEL_custom_bouncing_ball_T *const custom_bouncing_ball_M;

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
 * '<Root>' : 'custom_bouncing_ball'
 */
#endif                                 /* RTW_HEADER_custom_bouncing_ball_h_ */
