/*
 * Arduino_Blinking_LED.c
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

#include "Arduino_Blinking_LED.h"
#include "Arduino_Blinking_LED_private.h"
#define Arduino_Blinking_LED_PinNumber (2.0)
#define Arduino_Blinking_LE_PinNumber_f (3.0)

/* Block states (default storage) */
DW_Arduino_Blinking_LED_T Arduino_Blinking_LED_DW;

/* Real-time model */
RT_MODEL_Arduino_Blinking_LED_T Arduino_Blinking_LED_M_;
RT_MODEL_Arduino_Blinking_LED_T *const Arduino_Blinking_LED_M =
  &Arduino_Blinking_LED_M_;

/* Forward declaration for local functions */
static void SystemProp_matlabCodegenSetAnyP(codertarget_arduinobase_block_T *obj,
  boolean_T value);
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj);
static void SystemProp_matlabCodegenSetAnyP(codertarget_arduinobase_block_T *obj,
  boolean_T value)
{
  obj->matlabCodegenIsDeleted = value;
}

static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    SystemProp_matlabCodegenSetAnyP(obj, true);
  }
}

/* Model step function */
void Arduino_Blinking_LED_step(void)
{
  real_T rtb_Add;

  /* SignalGenerator: '<Root>/Square Wave Generator' */
  rtb_Add = Arduino_Blinking_LED_P.SquareWaveGenerator_Frequency *
    Arduino_Blinking_LED_M->Timing.t[0];
  if (rtb_Add - floor(rtb_Add) >= 0.5) {
    rtb_Add = Arduino_Blinking_LED_P.SquareWaveGenerator_Amplitude;
  } else {
    rtb_Add = -Arduino_Blinking_LED_P.SquareWaveGenerator_Amplitude;
  }

  /* End of SignalGenerator: '<Root>/Square Wave Generator' */

  /* Sum: '<Root>/Add' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_Add += Arduino_Blinking_LED_P.Constant_Value;

  /* MATLABSystem: '<S1>/Digital Output' incorporates:
   *  DataTypeConversion: '<Root>/Cast To Boolean'
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   */
  writeDigitalPin((uint8_T)Arduino_Blinking_LED_PinNumber, (uint8_T)(rtb_Add !=
    0.0));

  /* MATLABSystem: '<S2>/Digital Output' incorporates:
   *  DataTypeConversion: '<Root>/Cast To Boolean'
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   *  Logic: '<Root>/NOT'
   */
  writeDigitalPin((uint8_T)Arduino_Blinking_LE_PinNumber_f, (uint8_T)!(rtb_Add
    != 0.0));

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Arduino_Blinking_LED_M->Timing.clockTick0)) {
    ++Arduino_Blinking_LED_M->Timing.clockTickH0;
  }

  Arduino_Blinking_LED_M->Timing.t[0] =
    Arduino_Blinking_LED_M->Timing.clockTick0 *
    Arduino_Blinking_LED_M->Timing.stepSize0 +
    Arduino_Blinking_LED_M->Timing.clockTickH0 *
    Arduino_Blinking_LED_M->Timing.stepSize0 * 4294967296.0;

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
    Arduino_Blinking_LED_M->Timing.clockTick1++;
    if (!Arduino_Blinking_LED_M->Timing.clockTick1) {
      Arduino_Blinking_LED_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void Arduino_Blinking_LED_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Arduino_Blinking_LED_M, 0,
                sizeof(RT_MODEL_Arduino_Blinking_LED_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Arduino_Blinking_LED_M->solverInfo,
                          &Arduino_Blinking_LED_M->Timing.simTimeStep);
    rtsiSetTPtr(&Arduino_Blinking_LED_M->solverInfo, &rtmGetTPtr
                (Arduino_Blinking_LED_M));
    rtsiSetStepSizePtr(&Arduino_Blinking_LED_M->solverInfo,
                       &Arduino_Blinking_LED_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Arduino_Blinking_LED_M->solverInfo,
                          (&rtmGetErrorStatus(Arduino_Blinking_LED_M)));
    rtsiSetRTModelPtr(&Arduino_Blinking_LED_M->solverInfo,
                      Arduino_Blinking_LED_M);
  }

  rtsiSetSimTimeStep(&Arduino_Blinking_LED_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Arduino_Blinking_LED_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Arduino_Blinking_LED_M, &Arduino_Blinking_LED_M->Timing.tArray[0]);
  Arduino_Blinking_LED_M->Timing.stepSize0 = 0.2;

  /* states (dwork) */
  (void) memset((void *)&Arduino_Blinking_LED_DW, 0,
                sizeof(DW_Arduino_Blinking_LED_T));

  /* Start for MATLABSystem: '<S1>/Digital Output' */
  Arduino_Blinking_LED_DW.obj_e.matlabCodegenIsDeleted = true;
  Arduino_Blinking_LED_DW.obj_e.isInitialized = 0L;
  Arduino_Blinking_LED_DW.obj_e.matlabCodegenIsDeleted = false;
  Arduino_Blinking_LED_DW.objisempty_i = true;
  Arduino_Blinking_LED_DW.obj_e.isSetupComplete = false;
  Arduino_Blinking_LED_DW.obj_e.isInitialized = 1L;
  digitalIOSetup((uint8_T)Arduino_Blinking_LED_PinNumber, true);
  Arduino_Blinking_LED_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/Digital Output' */
  Arduino_Blinking_LED_DW.obj.matlabCodegenIsDeleted = true;
  Arduino_Blinking_LED_DW.obj.isInitialized = 0L;
  Arduino_Blinking_LED_DW.obj.matlabCodegenIsDeleted = false;
  Arduino_Blinking_LED_DW.objisempty = true;
  Arduino_Blinking_LED_DW.obj.isSetupComplete = false;
  Arduino_Blinking_LED_DW.obj.isInitialized = 1L;
  digitalIOSetup((uint8_T)Arduino_Blinking_LE_PinNumber_f, true);
  Arduino_Blinking_LED_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void Arduino_Blinking_LED_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Digital Output' */
  matlabCodegenHandle_matlabCodeg(&Arduino_Blinking_LED_DW.obj_e);

  /* Terminate for MATLABSystem: '<S2>/Digital Output' */
  matlabCodegenHandle_matlabCodeg(&Arduino_Blinking_LED_DW.obj);
}
