/*
 * Arduino_Blinking_LED.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Arduino_Blinking_LED".
 *
 * Model version              : 1.16
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Sat Mar 16 12:37:34 2019
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Arduino_Blinking_LED_h_
#define RTW_HEADER_Arduino_Blinking_LED_h_
#include <stddef.h>
#include <string.h>
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
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Sum;                          /* '<S4>/Sum' */
  uint8_T In;                          /* '<S3>/In' */
} B_Arduino_Blinking_LED_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<S2>/Digital Input' */
  codertarget_arduinobase_block_T obj_l;/* '<S1>/Digital Input' */
  codertarget_arduinobase_blo_f_T obj_e;/* '<S5>/Digital Output' */
  real_T Delay_DSTATE;                 /* '<Root>/Delay' */
  real_T Delay1_DSTATE;                /* '<Root>/Delay1' */
  real_T Delay3_DSTATE;                /* '<Root>/Delay3' */
  boolean_T objisempty;                /* '<S5>/Digital Output' */
  boolean_T objisempty_m;              /* '<S2>/Digital Input' */
  boolean_T objisempty_i;              /* '<S1>/Digital Input' */
} DW_Arduino_Blinking_LED_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<Root>/Triggered Subsystem' */
  ZCSigState SampleandHold_Trig_ZCE;   /* '<Root>/Sample and Hold' */
} PrevZCX_Arduino_Blinking_LED_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T stepInterval;                 /* '<Root>/stepInterval' */
} ExtY_Arduino_Blinking_LED_T;

/* Parameters (default storage) */
struct P_Arduino_Blinking_LED_T_ {
  real_T Ts;                           /* Variable: Ts
                                        * Referenced by:
                                        *   '<Root>/Constant1'
                                        *   '<Root>/Gain4'
                                        *   '<S1>/Digital Input'
                                        *   '<S2>/Digital Input'
                                        */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S4>/Out1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Constant_Value_b;             /* Expression: 40
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant2_Value;              /* Expression: 360
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay2'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1/1000
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T AngleInitial_Value;           /* Expression: 0
                                        * Referenced by: '<Root>/Angle Initial'
                                        */
  real_T Gain_Gain;                    /* Expression: 130/72000 * 10
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay'
                                        */
  real_T Gain1_Gain;                   /* Expression: 130/2
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay1'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1/2
                                        * Referenced by: '<Root>/Gain5'
                                        */
  real_T Delay3_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay3'
                                        */
  real_T Gain2_Gain;                   /* Expression: .0001
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1000
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 300
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 1
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  uint16_T Delay2_DelayLength;         /* Computed Parameter: Delay2_DelayLength
                                        * Referenced by: '<Root>/Delay2'
                                        */
  uint16_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<Root>/Delay'
                                        */
  uint16_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<Root>/Delay1'
                                        */
  uint16_T Delay3_DelayLength;         /* Computed Parameter: Delay3_DelayLength
                                        * Referenced by: '<Root>/Delay3'
                                        */
  uint8_T _Y0;                         /* Computed Parameter: _Y0
                                        * Referenced by: '<S3>/ '
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Arduino_Blinking_LED_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_Arduino_Blinking_LED_T Arduino_Blinking_LED_P;

/* Block signals (default storage) */
extern B_Arduino_Blinking_LED_T Arduino_Blinking_LED_B;

/* Block states (default storage) */
extern DW_Arduino_Blinking_LED_T Arduino_Blinking_LED_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Arduino_Blinking_LED_T Arduino_Blinking_LED_Y;

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
 * '<S1>'   : 'Arduino_Blinking_LED/Digital Input'
 * '<S2>'   : 'Arduino_Blinking_LED/Digital Input1'
 * '<S3>'   : 'Arduino_Blinking_LED/Sample and Hold'
 * '<S4>'   : 'Arduino_Blinking_LED/Triggered Subsystem'
 * '<S5>'   : 'Arduino_Blinking_LED/dirneg'
 */
#endif                                 /* RTW_HEADER_Arduino_Blinking_LED_h_ */
