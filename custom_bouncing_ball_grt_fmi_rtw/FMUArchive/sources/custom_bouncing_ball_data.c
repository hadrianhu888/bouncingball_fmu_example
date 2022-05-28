/*
 * custom_bouncing_ball_data.c
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

#include "custom_bouncing_ball.h"
#include "custom_bouncing_ball_private.h"

/* Block parameters (default storage) */
P_custom_bouncing_ball_T custom_bouncing_ball_P = {
  /* Variable: g
   * Referenced by: '<Root>/Constant'
   */
  -9.81,

  /* Variable: r
   * Referenced by: '<Root>/Gain'
   */
  0.8,

  /* Variable: v
   * Referenced by: '<Root>/Initial Velocity '
   */
  15.0,

  /* Expression: 0
   * Referenced by: '<Root>/Memory'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<Root>/Integrator, Second-Order'
   */
  0.0
};
