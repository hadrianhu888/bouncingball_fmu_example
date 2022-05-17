/*
 * custom_bouncing_ball_sf.h
 *
 * Code generation for model "custom_bouncing_ball_sf".
 *
 * Model version              : 1.4
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Tue May 17 16:32:33 2022
 *
 * Target selection: rtwsfcnfmi.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_custom_bouncing_ball_sf_h_
#define RTW_HEADER_custom_bouncing_ball_sf_h_
#include <string.h>
#include <stddef.h>
#ifndef custom_bouncing_ball_sf_COMMON_INCLUDES_
#define custom_bouncing_ball_sf_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME                custom_bouncing_ball_sf
#define S_FUNCTION_LEVEL               2
#ifndef RTW_GENERATED_S_FUNCTION
#define RTW_GENERATED_S_FUNCTION
#endif

#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if !defined(MATLAB_MEX_FILE)
#include "rt_matrx.h"
#endif

#if !defined(RTW_SFUNCTION_DEFINES)
#define RTW_SFUNCTION_DEFINES

typedef struct {
  void *blockIO;
  void *defaultParam;
  void *nonContDerivSig;
} LocalS;

#define ssSetLocalBlockIO(S, io)       ((LocalS *)ssGetUserData(S))->blockIO = ((void *)(io))
#define ssGetLocalBlockIO(S)           ((LocalS *)ssGetUserData(S))->blockIO
#define ssSetLocalDefaultParam(S, paramVector) ((LocalS *)ssGetUserData(S))->defaultParam = (paramVector)
#define ssGetLocalDefaultParam(S)      ((LocalS *)ssGetUserData(S))->defaultParam
#define ssSetLocalNonContDerivSig(S, pSig) ((LocalS *)ssGetUserData(S))->nonContDerivSig = (pSig)
#define ssGetLocalNonContDerivSig(S)   ((LocalS *)ssGetUserData(S))->nonContDerivSig
#endif
#endif                            /* custom_bouncing_ball_sf_COMMON_INCLUDES_ */

#include "custom_bouncing_ball_sf_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Block signals (default storage) */
typedef struct {
  real_T InitialVelocity;              /* '<Root>/Initial Velocity ' */
  real_T IntegratorSecondOrder_o2;     /* '<Root>/Integrator, Second-Order' */
} B_custom_bouncing_ball_T;

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

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T *Position;                    /* '<Root>/Position' */
  real_T *Velocity;                    /* '<Root>/Velocity' */
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

extern P_custom_bouncing_ball_T custom_bouncing_ball_DefaultP;

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
 * '<Root>' : 'custom_bouncing_ball_sf'
 */
#endif                               /* RTW_HEADER_custom_bouncing_ball_sf_h_ */
