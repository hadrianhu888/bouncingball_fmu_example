/*
 * custom_bouncing_ball_sf.c
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

#include <math.h>
#include "custom_bouncing_ball_sf.h"
#include "custom_bouncing_ball_sf_private.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *custom_bouncing_ball_malloc(SimStruct *S);

#endif

#ifndef __RTW_UTFREE__
#if defined (MATLAB_MEX_FILE)

extern void * utMalloc(size_t);
extern void utFree(void *);

#endif
#endif                                 /* #ifndef __RTW_UTFREE__ */

#if defined(MATLAB_MEX_FILE)
#include "rt_nonfinite.c"
#endif

static const char_T *RT_MEMORY_ALLOCATION_ERROR =
  "memory allocation error in generated S-Function";

/* System initialize for root system: '<Root>' */
#define MDL_INITIALIZE_CONDITIONS

static void mdlInitializeConditions(SimStruct *S)
{
  if (ssIsFirstInitCond(S)) {
    P_custom_bouncing_ball_T *_rtP;
    X_custom_bouncing_ball_T *_rtX;
    _rtX = ((X_custom_bouncing_ball_T *) ssGetContStates(S));
    _rtP = ((P_custom_bouncing_ball_T *) ssGetLocalDefaultParam(S));

    /* InitializeConditions for Memory: '<Root>/Memory' */
    ((real_T *)ssGetDWork(S, 0))[0] = _rtP->Memory_InitialCondition;

    /* InitializeConditions for SecondOrderIntegrator: '<Root>/Integrator, Second-Order' */
    _rtX->IntegratorSecondOrder_CSTATE[0] = _rtP->IntegratorSecondOrder_ICX;
    ((int_T *)ssGetDWork(S, 1))[0] = 0;
    ((boolean_T *)ssGetDWork(S, 3))[0] = true;
  } else {
    P_custom_bouncing_ball_T *_rtP;
    X_custom_bouncing_ball_T *_rtX;
    _rtX = ((X_custom_bouncing_ball_T *) ssGetContStates(S));
    _rtP = ((P_custom_bouncing_ball_T *) ssGetLocalDefaultParam(S));

    /* InitializeConditions for Memory: '<Root>/Memory' */
    ((real_T *)ssGetDWork(S, 0))[0] = _rtP->Memory_InitialCondition;

    /* InitializeConditions for SecondOrderIntegrator: '<Root>/Integrator, Second-Order' */
    _rtX->IntegratorSecondOrder_CSTATE[0] = _rtP->IntegratorSecondOrder_ICX;
    ((int_T *)ssGetDWork(S, 1))[0] = 0;
    ((boolean_T *)ssGetDWork(S, 3))[0] = true;
  }
}

/* Start for root system: '<Root>' */
#define MDL_START

static void mdlStart(SimStruct *S)
{
  /* instance underlying S-Function data */
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#if defined(MATLAB_MEX_FILE)

  /* non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Check for invalid switching between solver types */
  if (ssIsVariableStepSolver(S)) {
    ssSetErrorStatus(S, "This Simulink Coder generated "
                     "S-Function cannot be used in a simulation with "
                     "a solver type of variable-step "
                     "because this S-Function was created from a model with "
                     "solver type of fixed-step and it has continuous time blocks. "
                     "See the Solver page of the simulation parameters dialog.");
    return;
  }

  if (ssGetSolverMode(S) == SOLVER_MODE_MULTITASKING) {
    ssSetErrorStatus(S, "This Simulink Coder generated "
                     "S-Function cannot be used in a simulation with "
                     "solver mode set to auto or multitasking "
                     "because this S-Function was created from a model with "
                     "solver mode set to singletasking. "
                     "See the Solver page of the simulation parameters dialog.");
    return;
  }

#endif

  custom_bouncing_ball_malloc(S);
  if (ssGetErrorStatus(S) != (NULL) ) {
    return;
  }

#endif

  {
    /* Start for InitialCondition: '<Root>/Initial Velocity ' */
    ((boolean_T *)ssGetDWork(S, 2))[0] = true;
  }
}

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  B_custom_bouncing_ball_T *_rtB;
  X_custom_bouncing_ball_T *_rtX;
  _rtX = ((X_custom_bouncing_ball_T *) ssGetContStates(S));
  _rtB = ((B_custom_bouncing_ball_T *) ssGetLocalBlockIO(S));
  if (ssIsSampleHit(S, 1, 0)) {
    /* InitialCondition: '<Root>/Initial Velocity ' */
    if (((boolean_T *)ssGetDWork(S, 2))[0]) {
      ((boolean_T *)ssGetDWork(S, 2))[0] = false;

      /* InitialCondition: '<Root>/Initial Velocity ' */
      _rtB->InitialVelocity = (*(real_T *)(mxGetData(v(S))));
    } else {
      /* InitialCondition: '<Root>/Initial Velocity ' incorporates:
       *  Gain: '<Root>/Gain'
       *  Memory: '<Root>/Memory'
       */
      _rtB->InitialVelocity = (*(real_T *)(mxGetData(r(S)))) * ((real_T *)
        ssGetDWork(S, 0))[0];
    }

    /* End of InitialCondition: '<Root>/Initial Velocity ' */
  }

  if (1) {
    /* SecondOrderIntegrator: '<Root>/Integrator, Second-Order' */
    if (((boolean_T *)ssGetDWork(S, 3))[0]) {
      _rtX->IntegratorSecondOrder_CSTATE[1] = _rtB->InitialVelocity;
    }

    /* SecondOrderIntegrator: '<Root>/Integrator, Second-Order' */
    _rtB->IntegratorSecondOrder_o2 = _rtX->IntegratorSecondOrder_CSTATE[1];

    /* Outport: '<Root>/Position' incorporates:
     *  SecondOrderIntegrator: '<Root>/Integrator, Second-Order'
     */
    ((real_T *)ssGetOutputPortSignal(S, 0))[0] =
      _rtX->IntegratorSecondOrder_CSTATE[0];

    /* Outport: '<Root>/Velocity' */
    ((real_T *)ssGetOutputPortSignal(S, 1))[0] = _rtB->IntegratorSecondOrder_o2;
  }

  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  B_custom_bouncing_ball_T *_rtB;
  _rtB = ((B_custom_bouncing_ball_T *) ssGetLocalBlockIO(S));
  if (ssIsSampleHit(S, 1, 0)) {
    /* Update for Memory: '<Root>/Memory' */
    ((real_T *)ssGetDWork(S, 0))[0] = _rtB->IntegratorSecondOrder_o2;
  }

  /* Update for SecondOrderIntegrator: '<Root>/Integrator, Second-Order' */
  ((boolean_T *)ssGetDWork(S, 3))[0] = ((!1) && ((boolean_T *)ssGetDWork(S, 3))
    [0]);
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
#define MDL_DERIVATIVES

static void mdlDerivatives(SimStruct *S)
{
  XDot_custom_bouncing_ball_T *_rtXdot;
  X_custom_bouncing_ball_T *_rtX;
  _rtXdot = ((XDot_custom_bouncing_ball_T *) ssGetdX(S));
  _rtX = ((X_custom_bouncing_ball_T *) ssGetContStates(S));

  /* Derivatives for SecondOrderIntegrator: '<Root>/Integrator, Second-Order' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (((int_T *)ssGetDWork(S, 1))[0] == 0) {
    _rtXdot->IntegratorSecondOrder_CSTATE[0] =
      _rtX->IntegratorSecondOrder_CSTATE[1];
    _rtXdot->IntegratorSecondOrder_CSTATE[1] = (*(real_T *)(mxGetData(g(S))));
  }

  /* End of Derivatives for SecondOrderIntegrator: '<Root>/Integrator, Second-Order' */
}

/* Termination for root system: '<Root>' */
static void mdlTerminate(SimStruct *S)
{

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

  if (ssGetUserData(S) != (NULL) ) {
    rt_FREE(ssGetLocalBlockIO(S));
  }

  rt_FREE(ssGetUserData(S));

#endif

}

/* This function checks the attributes of tunable parameters. */
#define MDL_CHECK_PARAMETERS
#if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)

static void mdlCheckParameters(SimStruct *S)
{
  /* Parameter check for 'g' */
  if (mxIsComplex(ssGetSFcnParam(S, 0))) {
    ssSetErrorStatus(S,"Parameter 'g' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 0))) {
    ssSetErrorStatus(S,"Parameter 'g' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 0)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 0))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 0))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'g' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'r' */
  if (mxIsComplex(ssGetSFcnParam(S, 1))) {
    ssSetErrorStatus(S,"Parameter 'r' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 1))) {
    ssSetErrorStatus(S,"Parameter 'r' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 1)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 1))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 1))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'r' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'v' */
  if (mxIsComplex(ssGetSFcnParam(S, 2))) {
    ssSetErrorStatus(S,"Parameter 'v' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 2))) {
    ssSetErrorStatus(S,"Parameter 'v' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 2)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 2))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 2))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'v' has to be a [1x1] array.");
    return;
  }
}

#endif                                 /* MDL_CHECK_PARAMETERS */

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#include "custom_bouncing_ball_mid.h"
#endif

/* Function to initialize sizes. */
static void mdlInitializeSizes(SimStruct *S)
{
  ssSetNumSampleTimes(S, 2);           /* Number of sample times */
  ssSetNumContStates(S, 2);            /* Number of continuous states */
  ssSetNumPeriodicContStates(S, 0);   /* Number of periodic continuous states */
  ssSetNumNonsampledZCs(S, 0);         /* Number of nonsampled ZCs */

  /* Number of output ports */
  if (!ssSetNumOutputPorts(S, 2))
    return;

  /* outport number: 0 */
  if (!ssSetOutputPortVectorDimension(S, 0, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 0, 0.0);
  ssSetOutputPortOffsetTime(S, 0, 0.0);
  ssSetOutputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

  /* outport number: 1 */
  if (!ssSetOutputPortVectorDimension(S, 1, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 1, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 1, 0.0);
  ssSetOutputPortOffsetTime(S, 1, 0.0);
  ssSetOutputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);

  /* Number of input ports */
  if (!ssSetNumInputPorts(S, 0))
    return;
  ssSetRTWGeneratedSFcn(S, 1);         /* Generated S-function */

  /* DWork */
  if (!ssSetNumDWork(S, 4)) {
    return;
  }

  /* '<Root>/Memory': PreviousInput */
  ssSetDWorkName(S, 0, "DWORK0");
  ssSetDWorkWidth(S, 0, 1);

  /* '<Root>/Integrator, Second-Order': MODE */
  ssSetDWorkName(S, 1, "DWORK1");
  ssSetDWorkWidth(S, 1, 1);
  ssSetDWorkDataType(S, 1, SS_INTEGER);

  /* '<Root>/Initial Velocity ': FirstOutputTime */
  ssSetDWorkName(S, 2, "DWORK2");
  ssSetDWorkWidth(S, 2, 1);
  ssSetDWorkDataType(S, 2, SS_BOOLEAN);

  /* '<Root>/Integrator, Second-Order': DWORK1 */
  ssSetDWorkName(S, 3, "DWORK3");
  ssSetDWorkWidth(S, 3, 1);
  ssSetDWorkDataType(S, 3, SS_BOOLEAN);

  /* Tunable Parameters */
  ssSetNumSFcnParams(S, 3);

  /* Number of expected parameters */
#if defined(MATLAB_MEX_FILE)

  if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {

#if defined(MDL_CHECK_PARAMETERS)

    mdlCheckParameters(S);

#endif                                 /* MDL_CHECK_PARAMETERS */

    if (ssGetErrorStatus(S) != (NULL) ) {
      return;
    }
  } else {
    return;                /* Parameter mismatch will be reported by Simulink */
  }

#endif                                 /* MATLAB_MEX_FILE */

  /* Options */
  ssSetOptions(S, (SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE |
                   SS_OPTION_PORT_SAMPLE_TIMES_ASSIGNED ));

#if SS_SFCN_FOR_SIM

  {
    ssSupportsMultipleExecInstances(S, true);
    ssHasStateInsideForEachSS(S, false);
  }

#endif

}

/* Function to initialize sample times. */
static void mdlInitializeSampleTimes(SimStruct *S)
{
  /* task periods */
  ssSetSampleTime(S, 0, 0.0);
  ssSetSampleTime(S, 1, 0.2);

  /* task offsets */
  ssSetOffsetTime(S, 0, 0.0);
  ssSetOffsetTime(S, 1, 0.0);
}

#if defined(MATLAB_MEX_FILE)
#include "fixedpoint.c"
#include "simulink.c"
#else
#undef S_FUNCTION_NAME
#define S_FUNCTION_NAME                custom_bouncing_ball_sf
#include "cg_sfun.h"
#endif                                 /* defined(MATLAB_MEX_FILE) */
