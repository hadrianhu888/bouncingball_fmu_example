/*
 * custom_bouncing_ball.c
 *
 * Code generation for model "custom_bouncing_ball".
 *
 * Model version              : 1.7
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Sat May 28 17:51:11 2022
 *
 * Target selection: grtfmi.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "custom_bouncing_ball_capi.h"
#include "custom_bouncing_ball.h"
#include "custom_bouncing_ball_private.h"

/* Block signals (default storage) */
B_custom_bouncing_ball_T custom_bouncing_ball_B;

/* Continuous states */
X_custom_bouncing_ball_T custom_bouncing_ball_X;

/* Block states (default storage) */
DW_custom_bouncing_ball_T custom_bouncing_ball_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_custom_bouncing_ball_T custom_bouncing_ball_Y;

/* Real-time model */
static RT_MODEL_custom_bouncing_ball_T custom_bouncing_ball_M_;
RT_MODEL_custom_bouncing_ball_T *const custom_bouncing_ball_M =
  &custom_bouncing_ball_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  custom_bouncing_ball_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  custom_bouncing_ball_step();
  custom_bouncing_ball_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  custom_bouncing_ball_step();
  custom_bouncing_ball_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void custom_bouncing_ball_step(void)
{
  if (rtmIsMajorTimeStep(custom_bouncing_ball_M)) {
    /* set solver stop time */
    if (!(custom_bouncing_ball_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&custom_bouncing_ball_M->solverInfo,
                            ((custom_bouncing_ball_M->Timing.clockTickH0 + 1) *
        custom_bouncing_ball_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&custom_bouncing_ball_M->solverInfo,
                            ((custom_bouncing_ball_M->Timing.clockTick0 + 1) *
        custom_bouncing_ball_M->Timing.stepSize0 +
        custom_bouncing_ball_M->Timing.clockTickH0 *
        custom_bouncing_ball_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(custom_bouncing_ball_M)) {
    custom_bouncing_ball_M->Timing.t[0] = rtsiGetT
      (&custom_bouncing_ball_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(custom_bouncing_ball_M)) {
    /* Memory: '<Root>/Memory' */
    custom_bouncing_ball_B.Memory = custom_bouncing_ball_DW.Memory_PreviousInput;

    /* Gain: '<Root>/Gain' */
    custom_bouncing_ball_B.Gain = custom_bouncing_ball_P.r *
      custom_bouncing_ball_B.Memory;

    /* InitialCondition: '<Root>/Initial Velocity ' */
    if (custom_bouncing_ball_DW.InitialVelocity_FirstOutputTime) {
      custom_bouncing_ball_DW.InitialVelocity_FirstOutputTime = false;

      /* InitialCondition: '<Root>/Initial Velocity ' */
      custom_bouncing_ball_B.InitialVelocity = custom_bouncing_ball_P.v;
    } else {
      /* InitialCondition: '<Root>/Initial Velocity ' */
      custom_bouncing_ball_B.InitialVelocity = custom_bouncing_ball_B.Gain;
    }

    /* End of InitialCondition: '<Root>/Initial Velocity ' */
  }

  /* SecondOrderIntegrator: '<Root>/Integrator, Second-Order' */
  if (custom_bouncing_ball_DW.IntegratorSecondOrder_DWORK1) {
    custom_bouncing_ball_X.IntegratorSecondOrder_CSTATE[1] =
      custom_bouncing_ball_B.InitialVelocity;
  }

  /* SecondOrderIntegrator: '<Root>/Integrator, Second-Order' */
  custom_bouncing_ball_B.IntegratorSecondOrder_o1 =
    custom_bouncing_ball_X.IntegratorSecondOrder_CSTATE[0];

  /* SecondOrderIntegrator: '<Root>/Integrator, Second-Order' */
  custom_bouncing_ball_B.IntegratorSecondOrder_o2 =
    custom_bouncing_ball_X.IntegratorSecondOrder_CSTATE[1];

  /* Outport: '<Root>/Position' */
  custom_bouncing_ball_Y.Position =
    custom_bouncing_ball_B.IntegratorSecondOrder_o1;

  /* Outport: '<Root>/Velocity' */
  custom_bouncing_ball_Y.Velocity =
    custom_bouncing_ball_B.IntegratorSecondOrder_o2;
  if (rtmIsMajorTimeStep(custom_bouncing_ball_M)) {
    if (rtmIsMajorTimeStep(custom_bouncing_ball_M)) {
      /* Update for Memory: '<Root>/Memory' */
      custom_bouncing_ball_DW.Memory_PreviousInput =
        custom_bouncing_ball_B.IntegratorSecondOrder_o2;
    }

    /* Update for SecondOrderIntegrator: '<Root>/Integrator, Second-Order' */
    custom_bouncing_ball_DW.IntegratorSecondOrder_DWORK1 = false;
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(custom_bouncing_ball_M)) {
    rt_ertODEUpdateContinuousStates(&custom_bouncing_ball_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++custom_bouncing_ball_M->Timing.clockTick0)) {
      ++custom_bouncing_ball_M->Timing.clockTickH0;
    }

    custom_bouncing_ball_M->Timing.t[0] = rtsiGetSolverStopTime
      (&custom_bouncing_ball_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.2s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.2, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      custom_bouncing_ball_M->Timing.clockTick1++;
      if (!custom_bouncing_ball_M->Timing.clockTick1) {
        custom_bouncing_ball_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void custom_bouncing_ball_derivatives(void)
{
  XDot_custom_bouncing_ball_T *_rtXdot;
  _rtXdot = ((XDot_custom_bouncing_ball_T *) custom_bouncing_ball_M->derivs);

  /* Derivatives for SecondOrderIntegrator: '<Root>/Integrator, Second-Order' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (custom_bouncing_ball_DW.IntegratorSecondOrder_MODE == 0) {
    _rtXdot->IntegratorSecondOrder_CSTATE[0] =
      custom_bouncing_ball_X.IntegratorSecondOrder_CSTATE[1];
    _rtXdot->IntegratorSecondOrder_CSTATE[1] = custom_bouncing_ball_P.g;
  }

  /* End of Derivatives for SecondOrderIntegrator: '<Root>/Integrator, Second-Order' */
}

/* Model initialize function */
void custom_bouncing_ball_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)custom_bouncing_ball_M, 0,
                sizeof(RT_MODEL_custom_bouncing_ball_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&custom_bouncing_ball_M->solverInfo,
                          &custom_bouncing_ball_M->Timing.simTimeStep);
    rtsiSetTPtr(&custom_bouncing_ball_M->solverInfo, &rtmGetTPtr
                (custom_bouncing_ball_M));
    rtsiSetStepSizePtr(&custom_bouncing_ball_M->solverInfo,
                       &custom_bouncing_ball_M->Timing.stepSize0);
    rtsiSetdXPtr(&custom_bouncing_ball_M->solverInfo,
                 &custom_bouncing_ball_M->derivs);
    rtsiSetContStatesPtr(&custom_bouncing_ball_M->solverInfo, (real_T **)
                         &custom_bouncing_ball_M->contStates);
    rtsiSetNumContStatesPtr(&custom_bouncing_ball_M->solverInfo,
      &custom_bouncing_ball_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&custom_bouncing_ball_M->solverInfo,
      &custom_bouncing_ball_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&custom_bouncing_ball_M->solverInfo,
      &custom_bouncing_ball_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&custom_bouncing_ball_M->solverInfo,
      &custom_bouncing_ball_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&custom_bouncing_ball_M->solverInfo,
                          (&rtmGetErrorStatus(custom_bouncing_ball_M)));
    rtsiSetRTModelPtr(&custom_bouncing_ball_M->solverInfo,
                      custom_bouncing_ball_M);
  }

  rtsiSetSimTimeStep(&custom_bouncing_ball_M->solverInfo, MAJOR_TIME_STEP);
  custom_bouncing_ball_M->intgData.y = custom_bouncing_ball_M->odeY;
  custom_bouncing_ball_M->intgData.f[0] = custom_bouncing_ball_M->odeF[0];
  custom_bouncing_ball_M->intgData.f[1] = custom_bouncing_ball_M->odeF[1];
  custom_bouncing_ball_M->intgData.f[2] = custom_bouncing_ball_M->odeF[2];
  custom_bouncing_ball_M->contStates = ((X_custom_bouncing_ball_T *)
    &custom_bouncing_ball_X);
  rtsiSetSolverData(&custom_bouncing_ball_M->solverInfo, (void *)
                    &custom_bouncing_ball_M->intgData);
  rtsiSetSolverName(&custom_bouncing_ball_M->solverInfo,"ode3");
  rtmSetTPtr(custom_bouncing_ball_M, &custom_bouncing_ball_M->Timing.tArray[0]);
  custom_bouncing_ball_M->Timing.stepSize0 = 0.2;

  /* block I/O */
  (void) memset(((void *) &custom_bouncing_ball_B), 0,
                sizeof(B_custom_bouncing_ball_T));

  /* states (continuous) */
  {
    (void) memset((void *)&custom_bouncing_ball_X, 0,
                  sizeof(X_custom_bouncing_ball_T));
  }

  /* states (dwork) */
  (void) memset((void *)&custom_bouncing_ball_DW, 0,
                sizeof(DW_custom_bouncing_ball_T));

  /* external outputs */
  (void)memset(&custom_bouncing_ball_Y, 0, sizeof(ExtY_custom_bouncing_ball_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  custom_bouncing_ball_InitializeDataMapInfo();

  /* Start for InitialCondition: '<Root>/Initial Velocity ' */
  custom_bouncing_ball_DW.InitialVelocity_FirstOutputTime = true;

  /* InitializeConditions for Memory: '<Root>/Memory' */
  custom_bouncing_ball_DW.Memory_PreviousInput =
    custom_bouncing_ball_P.Memory_InitialCondition;

  /* InitializeConditions for SecondOrderIntegrator: '<Root>/Integrator, Second-Order' */
  custom_bouncing_ball_X.IntegratorSecondOrder_CSTATE[0] =
    custom_bouncing_ball_P.IntegratorSecondOrder_ICX;
  custom_bouncing_ball_DW.IntegratorSecondOrder_MODE = 0;
  custom_bouncing_ball_DW.IntegratorSecondOrder_DWORK1 = true;
}

/* Model terminate function */
void custom_bouncing_ball_terminate(void)
{
  /* (no terminate code required) */
}
