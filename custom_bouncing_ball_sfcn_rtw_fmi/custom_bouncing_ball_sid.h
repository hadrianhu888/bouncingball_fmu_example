/*
 * custom_bouncing_ball_sid.h
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
 *
 * SOURCES: custom_bouncing_ball_sf.c
 */

/* statically allocated instance data for model: custom_bouncing_ball */
{
  extern P_custom_bouncing_ball_T custom_bouncing_ball_DefaultP;

  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_custom_bouncing_ball_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_custom_bouncing_ball_T));
    }

    /* model parameters */
    ssSetLocalDefaultParam(rts, (real_T *) &custom_bouncing_ball_DefaultP);

    /* model checksums */
    ssSetChecksumVal(rts, 0, 4157450820U);
    ssSetChecksumVal(rts, 1, 518106736U);
    ssSetChecksumVal(rts, 2, 3939282046U);
    ssSetChecksumVal(rts, 3, 3211457660U);
  }
}
