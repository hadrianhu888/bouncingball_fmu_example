#include "simstruc_types.h"

#include "custom_bouncing_ball.h"
#include "custom_bouncing_ball_private.h"

typedef struct {
	BuiltInDTypeId dtypeID;
	size_t size;
	void* address;
} ModelVariable;

#ifndef NO_FMI_FUNCTION_PREFIX
#define FMI3_FUNCTION_PREFIX custom_bouncing_ball_
#endif

#define MODEL_GUID       "{750dc597-aba0-4b93-b73d-8b2e19e869f6}"
#define MODEL            custom_bouncing_ball
#define MODEL_INITIALIZE custom_bouncing_ball_initialize
#define MODEL_STEP       custom_bouncing_ball_step
#define MODEL_TERMINATE  custom_bouncing_ball_terminate
#define RT_MDL_TYPE      RT_MODEL_custom_bouncing_ball_T
#define STEP_SIZE        0.2
#define NUM_TASKS        1
#define NUM_SAMPLE_TIMES 2
#define FIRST_TASK_ID    1

/* since R2019a the block parameters are defined as extern */
#ifndef rtmGetDefaultParam
#define rtmGetDefaultParam(S) (&custom_bouncing_ball_P)
#endif

/* Definitions for non-reusable models */
#define RT_MDL_INSTANCE     custom_bouncing_ball_M
#define rtmGetU(S)          (&custom_bouncing_ball_U)
#define rtmGetY(S)          (&custom_bouncing_ball_Y)
#define rtmGetBlockIO(S)    (&custom_bouncing_ball_B)

static void initializeModelVariables(RT_MDL_TYPE* S, ModelVariable modelVariables[]) {
    modelVariables[0].dtypeID = 0;
    modelVariables[0].size    = 1;
    modelVariables[0].address = &(rtmGetY(S)->Position);
    modelVariables[1].dtypeID = 0;
    modelVariables[1].size    = 1;
    modelVariables[1].address = &(rtmGetY(S)->Velocity);
    modelVariables[2].dtypeID = 0;
    modelVariables[2].size    = 1;
    modelVariables[2].address = &(rtmGetBlockIO(S)->Memory);
    modelVariables[3].dtypeID = 0;
    modelVariables[3].size    = 1;
    modelVariables[3].address = &(rtmGetBlockIO(S)->Gain);
    modelVariables[4].dtypeID = 0;
    modelVariables[4].size    = 1;
    modelVariables[4].address = &(rtmGetBlockIO(S)->InitialVelocity);
    modelVariables[5].dtypeID = 0;
    modelVariables[5].size    = 1;
    modelVariables[5].address = &(rtmGetBlockIO(S)->IntegratorSecondOrder_o1);
    modelVariables[6].dtypeID = 0;
    modelVariables[6].size    = 1;
    modelVariables[6].address = &(rtmGetBlockIO(S)->IntegratorSecondOrder_o2);
}

#define N_MODEL_VARIABLES 7
