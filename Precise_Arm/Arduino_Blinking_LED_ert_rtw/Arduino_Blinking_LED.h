/*
 * Arduino_Blinking_LED.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Arduino_Blinking_LED".
 *
 * Model version              : 1.7
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Sat Feb 16 18:13:06 2019
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Arduino_Blinking_LED_h_
#define RTW_HEADER_Arduino_Blinking_LED_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Arduino_Blinking_LED_COMMON_INCLUDES_
# define Arduino_Blinking_LED_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_digitalio.h"
#endif                                 /* Arduino_Blinking_LED_COMMON_INCLUDES_ */

#include "Arduino_Blinking_LED_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<S2>/Digital Output' */
  codertarget_arduinobase_block_T obj_e;/* '<S1>/Digital Output' */
  boolean_T objisempty;                /* '<S2>/Digital Output' */
  boolean_T objisempty_i;              /* '<S1>/Digital Output' */
} DW_Arduino_Blinking_LED_T;

/* Parameters (default storage) */
struct P_Arduino_Blinking_LED_T_ {
  real_T Constant_Value;               /* Expression: .5
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T SquareWaveGenerator_Amplitude;/* Expression: .5
                                        * Referenced by: '<Root>/Square Wave Generator'
                                        */
  real_T SquareWaveGenerator_Frequency;/* Expression: .5
                                        * Referenced by: '<Root>/Square Wave Generator'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Arduino_Blinking_LED_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

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
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Arduino_Blinking_LED_T Arduino_Blinking_LED_P;

/* Block states (default storage) */
extern DW_Arduino_Blinking_LED_T Arduino_Blinking_LED_DW;

/* Model entry point functions */
extern void Arduino_Blinking_LED_initialize(void);
extern void Arduino_Blinking_LED_step(void);
extern void Arduino_Blinking_LED_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Arduino_Blinking_LED_T *const Arduino_Blinking_LED_M;

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
 * '<Root>' : 'Arduino_Blinking_LED'
 * '<S1>'   : 'Arduino_Blinking_LED/Digital Output'
 * '<S2>'   : 'Arduino_Blinking_LED/Digital Output1'
 */
#endif                                 /* RTW_HEADER_Arduino_Blinking_LED_h_ */
