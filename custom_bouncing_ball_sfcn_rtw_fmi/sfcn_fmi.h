/*
 * sfcn_fmi.h
 *
 *  Model-specific code required to build FMI executable
 *  from Simulink model "custom_bouncing_ball".
 *
 * Generated on : Tue May 17 16:32:33 2022
 */

#ifndef SFCN_FMI_H
#define SFCN_FMI_H

/* Include header for FMI 2.0 */
#include "fmi/fmi2Functions.h"

/* Define GUID string */
char* GUIDString = "{ad0c31c0-9103-4715-bccc-269e4f609958}";

#if defined(MATLAB_MEX_FILE)
#define mexCallMATLAB                  sfcn_fmi_load_mexw64
#else

/* Code to enable global tunable parameters in stand-alone mode */
#define RTW_GENERATED_SFCN_TUNABLE_PRMS_custom_bouncing_ball_sf
#define RTW_GENERATED_S_FUNCTION
#include "simstruc.h"
#include "fixedpoint.h"
#if defined (_MSC_VER)

#pragma warning(disable:4005)

#endif

#define mxGetData(x)                   x
#define g(S)                           &(((P_custom_bouncing_ball_T *) ssGetLocalDefaultParam(S))->g)
#define r(S)                           &(((P_custom_bouncing_ball_T *) ssGetLocalDefaultParam(S))->r)
#define v(S)                           &(((P_custom_bouncing_ball_T *) ssGetLocalDefaultParam(S))->v)
#define ssFxpSetU32BitRegionCompliant(S, v)
#include "rt_nonfinite.c"
#endif

/* Include Simulink Coder-generated model code */
#include "custom_bouncing_ball_sf.c"

/* Solver settings selected in Simulink */
int_T SFCN_FMI_IS_VARIABLE_STEP_SOLVER = 0;
real_T SFCN_FMI_FIXED_STEP_SIZE = 0.2;
int_T SFCN_FMI_IS_MT = 0;
int_T SFCN_FMI_EXTRAPOLATION_ORDER = -1;
int_T SFCN_FMI_NEWTON_ITER = -1;

/* Model sizes */
int_T SFCN_FMI_ZC_LENGTH = 0;
int_T SFCN_FMI_NBR_INPUTS = 0;
int_T SFCN_FMI_NBR_OUTPUTS = 2;
int_T SFCN_FMI_NBR_PARAMS = 0;
int_T SFCN_FMI_NBR_BLOCKIO = 0;
int_T SFCN_FMI_NBR_DWORK = 0;

/* Model identifier */
char* SFCN_FMI_MODEL_IDENTIFIER = "custom_bouncing_ball_sf";

/* Loading of MEX binaries, path to MATLAB bin */
int_T SFCN_FMI_LOAD_MEX = 1;
const char* SFCN_FMI_MATLAB_BIN = "D:\\Program Files\\Matlab\\bin\\win64";
int_T SFCN_FMI_NBR_MEX = 0;
char* SFCN_FMI_MEX_NAMES[1] = { "" };

/* Register model callback routines in SimStruct */
void sfcn_fmi_registerMdlCallbacks_(SimStruct*S)
{
  ssSetmdlInitializeSizes(S, mdlInitializeSizes);
  ssSetmdlInitializeSampleTimes(S, mdlInitializeSampleTimes);

#if defined(MDL_INITIALIZE_CONDITIONS)

  ssSetmdlInitializeConditions(S, mdlInitializeConditions);

#else

  ssSetmdlInitializeConditions(S, NULL);

#endif

#if defined(MDL_START)

  ssSetmdlStart(S, mdlStart);

#else

  ssSetmdlStart(S, NULL);

#endif

#if defined(RTW_GENERATED_ENABLE)

  _ssSetRTWGeneratedEnable(S, mdlEnable);

#else

  _ssSetRTWGeneratedEnable(S, NULL);

#endif

  ssSetmdlOutputs(S,mdlOutputs);

#if defined(MDL_ZERO_CROSSINGS)

  ssSetmdlZeroCrossings(S, mdlZeroCrossings);

#else

  ssSetmdlZeroCrossings(S, NULL);

#endif

#if defined(MDL_DERIVATIVES)

  ssSetmdlDerivatives(S, mdlDerivatives);

#else

  ssSetmdlDerivatives(S, NULL);

#endif

#if defined (MDL_UPDATE)

  ssSetmdlUpdate(S, mdlUpdate);

#else

  ssSetmdlUpdate(S, NULL);

#endif

  ssSetmdlTerminate(S, mdlTerminate);
}

/* Register SolverInfo model method pointers */
extern void mdlNoOpFunc(SimStruct* S);
void sfcn_fmi_registerRTModelCallbacks_(SimStruct*S)
{

#if defined(MDL_DERIVATIVES)

  S->mdlInfo->solverInfo->modelMethodsPtr->rtmDervisFcn = (rtMdlDerivativesFcn)
    mdlDerivatives;

#else

  S->mdlInfo->solverInfo->modelMethodsPtr->rtmDervisFcn = (rtMdlProjectionFcn)
    mdlNoOpFunc;

#endif

  S->mdlInfo->solverInfo->modelMethodsPtr->rtmProjectionFcn =
    (rtMdlProjectionFcn) mdlNoOpFunc;
  S->mdlInfo->solverInfo->modelMethodsPtr->rtmOutputsFcn = (rtMdlOutputsFcn)
    mdlOutputs;
}

/* Pointers to input variables */
void sfcn_fmi_assignInputs_(SimStruct* S, void** inputs)
{
  return;                              /* No inputs */
}

/* Pointers to output variables */
void sfcn_fmi_assignOutputs_(SimStruct* S, void** outputs)
{
  outputs[0] = &(((real_T *) ssGetOutputPortSignal(S, 0))[0]);
  outputs[1] = &(((real_T *) ssGetOutputPortSignal(S, 1))[0]);
}

/* Pointers to model parameters */
void sfcn_fmi_assignParameters_(SimStruct* S, void** parameters)
{
  return;                /* No parameters in model (probably due to inlining) */
}

/* Copy parameter values to S-function mxArrays */
void sfcn_fmi_copyToSFcnParams_(SimStruct* S)
{
  return;                /* No parameters in model (probably due to inlining) */
}

/* Return pointer to parameter struct in UserData */
void* sfcn_fmi_getParametersP_(SimStruct* S)
{
  return 0;
}

/* Handle mxArrays for global tunable parameters */
void sfcn_fmi_mxGlobalTunable_(SimStruct* S, int_T create, int_T update)
{
  mxArray *param;
  int_T i;
  if (create && !update) {
    S->sfcnParams.dlgParams = (mxArray**) allocateMemory0(3, sizeof(mxArray*));
  }

  if (create) {
    {
      real_T *vals0;
      if (update) {
        param = _ssGetSFcnParam(S, 0);
        vals0 = (real_T *) &(((P_custom_bouncing_ball_T *)
                              ssGetLocalDefaultParam(S))->g);
      } else {
        param = mxCreateNumericMatrix(1, 1, mxDOUBLE_CLASS, mxREAL);
        mexMakeArrayPersistent(param);
        _ssSetSFcnParam(S, 0, param);
        vals0 = (real_T *) &(custom_bouncing_ball_DefaultP.g);
      }

      for (i=0;i< 1 * 1;i++) {
        ((real_T*)mxGetData(param))[i] = vals0[i];
      }
    }
  } else {
    mxDestroyArray(_ssGetSFcnParam(S, 0));
  }

  if (create) {
    {
      real_T *vals1;
      if (update) {
        param = _ssGetSFcnParam(S, 1);
        vals1 = (real_T *) &(((P_custom_bouncing_ball_T *)
                              ssGetLocalDefaultParam(S))->r);
      } else {
        param = mxCreateNumericMatrix(1, 1, mxDOUBLE_CLASS, mxREAL);
        mexMakeArrayPersistent(param);
        _ssSetSFcnParam(S, 1, param);
        vals1 = (real_T *) &(custom_bouncing_ball_DefaultP.r);
      }

      for (i=0;i< 1 * 1;i++) {
        ((real_T*)mxGetData(param))[i] = vals1[i];
      }
    }
  } else {
    mxDestroyArray(_ssGetSFcnParam(S, 1));
  }

  if (create) {
    {
      real_T *vals2;
      if (update) {
        param = _ssGetSFcnParam(S, 2);
        vals2 = (real_T *) &(((P_custom_bouncing_ball_T *)
                              ssGetLocalDefaultParam(S))->v);
      } else {
        param = mxCreateNumericMatrix(1, 1, mxDOUBLE_CLASS, mxREAL);
        mexMakeArrayPersistent(param);
        _ssSetSFcnParam(S, 2, param);
        vals2 = (real_T *) &(custom_bouncing_ball_DefaultP.v);
      }

      for (i=0;i< 1 * 1;i++) {
        ((real_T*)mxGetData(param))[i] = vals2[i];
      }
    }
  } else {
    mxDestroyArray(_ssGetSFcnParam(S, 2));
  }
}

/* Pointers to block output variables */
void sfcn_fmi_assignBlockOutputs_(SimStruct* S, void** blockoutputs)
{
  return;                              /* No global block outputs */
}

/* Pointers to DWork variables for discrete states */
void sfcn_fmi_assignDWork_(SimStruct* S, void** dwork)
{
  return;                           /* No DWork variables for discrete states */
}

/* Sizes of bus I/O structs for allocation in FMU */
void* sfcn_fmi_allocateBusObject(int_T isInput, int_T portid, int_T width)
{
  return 0;
}

#if !defined(MATLAB_MEX_FILE)

int_T _ssSetInputPortMatrixDimensions(SimStruct *S, int_T port, int_T m, int_T n)
{
  extern int_T _ssSetInputPortMatrixDimensions_FMI(SimStruct *S, int_T port,
    int_T m, int_T n);
  return _ssSetInputPortMatrixDimensions_FMI(S, port, m, n);
}

int_T _ssSetOutputPortMatrixDimensions(SimStruct *S, int_T port, int_T m, int_T
  n)
{
  extern int_T _ssSetOutputPortMatrixDimensions_FMI(SimStruct *S, int_T port,
    int_T m, int_T n);
  return _ssSetOutputPortMatrixDimensions_FMI(S, port, m, n);
}

int_T _ssSetInputPortVectorDimension(SimStruct *S, int_T port, int_T m)
{
  extern int_T _ssSetInputPortVectorDimension_FMI(SimStruct *S, int_T port,
    int_T m);
  return _ssSetInputPortVectorDimension_FMI(S, port, m);
}

int_T _ssSetOutputPortVectorDimension(SimStruct *S, int_T port, int_T m)
{
  extern int_T _ssSetOutputPortVectorDimension_FMI(SimStruct *S, int_T port,
    int_T m);
  return _ssSetOutputPortVectorDimension_FMI(S, port, m);
}

#endif
#endif
