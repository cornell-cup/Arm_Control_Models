/*
 * Arduino_Blinking_LED.c
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

#include "Arduino_Blinking_LED.h"
#include "Arduino_Blinking_LED_private.h"
#define Arduino_Blinking_LED_PinNumber (18.0)
#define Arduino_Blinking_LE_PinNumber_f (19.0)
#define Arduino_Blinking_L_PinNumber_f2 (24.0)

/* Block signals (default storage) */
B_Arduino_Blinking_LED_T Arduino_Blinking_LED_B;

/* Block states (default storage) */
DW_Arduino_Blinking_LED_T Arduino_Blinking_LED_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Arduino_Blinking_LED_T Arduino_Blinking_LED_PrevZCX;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Arduino_Blinking_LED_T Arduino_Blinking_LED_Y;

/* Real-time model */
RT_MODEL_Arduino_Blinking_LED_T Arduino_Blinking_LED_M_;
RT_MODEL_Arduino_Blinking_LED_T *const Arduino_Blinking_LED_M =
  &Arduino_Blinking_LED_M_;

/* Forward declaration for local functions */
static void SystemProp_matlabCodegenSetAnyP(codertarget_arduinobase_block_T *obj,
  boolean_T value);
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj);
static void SystemProp_matlabCodegenSetA_f2(codertarget_arduinobase_blo_f_T *obj,
  boolean_T value);
static void matlabCodegenHandle_matlabCo_f2(codertarget_arduinobase_blo_f_T *obj);
static void SystemProp_matlabCodegenSetAnyP(codertarget_arduinobase_block_T *obj,
  boolean_T value)
{
  /* Start for MATLABSystem: '<S1>/Digital Input' incorporates:
   *  MATLABSystem: '<S2>/Digital Input'
   */
  obj->matlabCodegenIsDeleted = value;
}

static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj)
{
  /* Start for MATLABSystem: '<S1>/Digital Input' incorporates:
   *  MATLABSystem: '<S2>/Digital Input'
   */
  if (!obj->matlabCodegenIsDeleted) {
    SystemProp_matlabCodegenSetAnyP(obj, true);
  }

  /* End of Start for MATLABSystem: '<S1>/Digital Input' */
}

static void SystemProp_matlabCodegenSetA_f2(codertarget_arduinobase_blo_f_T *obj,
  boolean_T value)
{
  /* Start for MATLABSystem: '<S5>/Digital Output' */
  obj->matlabCodegenIsDeleted = value;
}

static void matlabCodegenHandle_matlabCo_f2(codertarget_arduinobase_blo_f_T *obj)
{
  /* Start for MATLABSystem: '<S5>/Digital Output' */
  if (!obj->matlabCodegenIsDeleted) {
    SystemProp_matlabCodegenSetA_f2(obj, true);
  }

  /* End of Start for MATLABSystem: '<S5>/Digital Output' */
}

/* Model step function */
void Arduino_Blinking_LED_step(void)
{
  boolean_T rtb_DigitalInput_c_0;
  boolean_T p;
  real_T sampleTime;
  real_T rtb_Saturation1;
  boolean_T rtb_OR;
  uint8_T rtb_Saturation1_0;

  /* Start for MATLABSystem: '<S1>/Digital Input' */
  p = false;
  rtb_OR = true;
  if (!(Arduino_Blinking_LED_DW.obj_l.SampleTime == Arduino_Blinking_LED_P.Ts))
  {
    rtb_OR = false;
  }

  if (rtb_OR) {
    p = true;
  }

  if (!p) {
    Arduino_Blinking_LED_DW.obj_l.SampleTime = Arduino_Blinking_LED_P.Ts;
  }

  /* MATLABSystem: '<S1>/Digital Input' */
  rtb_DigitalInput_c_0 = readDigitalPin((uint8_T)Arduino_Blinking_LED_PinNumber);

  /* Start for MATLABSystem: '<S2>/Digital Input' */
  p = false;
  rtb_OR = true;
  if (!(Arduino_Blinking_LED_DW.obj.SampleTime == Arduino_Blinking_LED_P.Ts)) {
    rtb_OR = false;
  }

  if (rtb_OR) {
    p = true;
  }

  if (!p) {
    if (((!rtIsInf(Arduino_Blinking_LED_P.Ts)) && (!rtIsNaN
          (Arduino_Blinking_LED_P.Ts))) || rtIsInf(Arduino_Blinking_LED_P.Ts)) {
      sampleTime = Arduino_Blinking_LED_P.Ts;
    }

    Arduino_Blinking_LED_DW.obj.SampleTime = sampleTime;
  }

  /* MATLABSystem: '<S2>/Digital Input' */
  p = readDigitalPin((uint8_T)Arduino_Blinking_LE_PinNumber_f);

  /* Logic: '<Root>/OR' incorporates:
   *  MATLABSystem: '<S1>/Digital Input'
   *  MATLABSystem: '<S2>/Digital Input'
   */
  rtb_OR = rtb_DigitalInput_c_0 ^ p;

  /* Outputs for Triggered SubSystem: '<Root>/Sample and Hold' incorporates:
   *  TriggerPort: '<S3>/Trigger'
   */
  if (rtb_OR && (Arduino_Blinking_LED_PrevZCX.SampleandHold_Trig_ZCE !=
                 POS_ZCSIG)) {
    /* Signum: '<Root>/Sign1' incorporates:
     *  Inport: '<S3>/In'
     *  MATLABSystem: '<S1>/Digital Input'
     *  MATLABSystem: '<S2>/Digital Input'
     *  Sum: '<Root>/Subtract'
     */
    Arduino_Blinking_LED_B.In = (uint8_T)((uint8_T)(rtb_DigitalInput_c_0 - p) >
      0);
  }

  Arduino_Blinking_LED_PrevZCX.SampleandHold_Trig_ZCE = rtb_OR;

  /* End of Outputs for SubSystem: '<Root>/Sample and Hold' */

  /* Outputs for Triggered SubSystem: '<Root>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S4>/Trigger'
   */
  /* MATLABSystem: '<S1>/Digital Input' */
  if (rtb_DigitalInput_c_0 &&
      (Arduino_Blinking_LED_PrevZCX.TriggeredSubsystem_Trig_ZCE != POS_ZCSIG)) {
    /* Sum: '<S4>/Sum' incorporates:
     *  Constant: '<S4>/Constant'
     *  Delay: '<Root>/Delay2'
     */
    Arduino_Blinking_LED_B.Sum += Arduino_Blinking_LED_P.Constant_Value;
  }

  Arduino_Blinking_LED_PrevZCX.TriggeredSubsystem_Trig_ZCE =
    rtb_DigitalInput_c_0;

  /* End of Outputs for SubSystem: '<Root>/Triggered Subsystem' */

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Angle Initial'
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant2'
   *  Gain: '<Root>/Gain3'
   *  Product: '<Root>/Multiply'
   *  Product: '<Root>/Multiply1'
   *  Sum: '<Root>/Add'
   */
  sampleTime = Arduino_Blinking_LED_P.Constant_Value_b -
    (Arduino_Blinking_LED_P.Gain3_Gain * Arduino_Blinking_LED_B.Sum *
     Arduino_Blinking_LED_P.Constant2_Value * (real_T)Arduino_Blinking_LED_B.In
     + Arduino_Blinking_LED_P.AngleInitial_Value);

  /* Sum: '<Root>/Sum3' incorporates:
   *  Delay: '<Root>/Delay1'
   *  Delay: '<Root>/Delay3'
   *  Gain: '<Root>/Gain4'
   *  Gain: '<Root>/Gain5'
   *  Sum: '<Root>/Sum2'
   */
  Arduino_Blinking_LED_DW.Delay3_DSTATE += (sampleTime +
    Arduino_Blinking_LED_DW.Delay1_DSTATE) * Arduino_Blinking_LED_P.Gain5_Gain *
    Arduino_Blinking_LED_P.Ts;

  /* Sum: '<Root>/Add1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Delay: '<Root>/Delay'
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Gain2'
   *  Product: '<Root>/Divide'
   *  Sum: '<Root>/Sum1'
   */
  rtb_Saturation1 = ((sampleTime - Arduino_Blinking_LED_DW.Delay_DSTATE) /
                     Arduino_Blinking_LED_P.Ts *
                     Arduino_Blinking_LED_P.Gain1_Gain +
                     Arduino_Blinking_LED_P.Gain_Gain * sampleTime) +
    Arduino_Blinking_LED_P.Gain2_Gain * Arduino_Blinking_LED_DW.Delay3_DSTATE;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Saturation1 > Arduino_Blinking_LED_P.Saturation_UpperSat) {
    /* Outport: '<Root>/stepInterval' */
    Arduino_Blinking_LED_Y.stepInterval =
      Arduino_Blinking_LED_P.Saturation_UpperSat;
  } else if (rtb_Saturation1 < Arduino_Blinking_LED_P.Saturation_LowerSat) {
    /* Outport: '<Root>/stepInterval' */
    Arduino_Blinking_LED_Y.stepInterval =
      Arduino_Blinking_LED_P.Saturation_LowerSat;
  } else {
    /* Outport: '<Root>/stepInterval' */
    Arduino_Blinking_LED_Y.stepInterval = rtb_Saturation1;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Signum: '<Root>/Sign' */
  if (rtb_Saturation1 < 0.0) {
    rtb_Saturation1 = -1.0;
  } else if (rtb_Saturation1 > 0.0) {
    rtb_Saturation1 = 1.0;
  } else if (rtb_Saturation1 == 0.0) {
    rtb_Saturation1 = 0.0;
  } else {
    rtb_Saturation1 = (rtNaN);
  }

  /* End of Signum: '<Root>/Sign' */

  /* Saturate: '<Root>/Saturation1' */
  if (rtb_Saturation1 > Arduino_Blinking_LED_P.Saturation1_UpperSat) {
    rtb_Saturation1 = Arduino_Blinking_LED_P.Saturation1_UpperSat;
  } else {
    if (rtb_Saturation1 < Arduino_Blinking_LED_P.Saturation1_LowerSat) {
      rtb_Saturation1 = Arduino_Blinking_LED_P.Saturation1_LowerSat;
    }
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* DataTypeConversion: '<S5>/Data Type Conversion' */
  if (rtb_Saturation1 < 256.0) {
    if (rtb_Saturation1 >= 0.0) {
      rtb_Saturation1_0 = (uint8_T)rtb_Saturation1;
    } else {
      rtb_Saturation1_0 = 0U;
    }
  } else {
    rtb_Saturation1_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S5>/Data Type Conversion' */

  /* Start for MATLABSystem: '<S5>/Digital Output' */
  writeDigitalPin((uint8_T)Arduino_Blinking_L_PinNumber_f2, rtb_Saturation1_0);

  /* Update for Delay: '<Root>/Delay' */
  Arduino_Blinking_LED_DW.Delay_DSTATE = sampleTime;

  /* Update for Delay: '<Root>/Delay1' */
  Arduino_Blinking_LED_DW.Delay1_DSTATE = sampleTime;
}

/* Model initialize function */
void Arduino_Blinking_LED_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(Arduino_Blinking_LED_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &Arduino_Blinking_LED_B), 0,
                sizeof(B_Arduino_Blinking_LED_T));

  /* states (dwork) */
  (void) memset((void *)&Arduino_Blinking_LED_DW, 0,
                sizeof(DW_Arduino_Blinking_LED_T));

  /* external outputs */
  Arduino_Blinking_LED_Y.stepInterval = 0.0;

  {
    real_T sampleTime;
    boolean_T tmp;
    boolean_T tmp_0;

    /* Start for MATLABSystem: '<S1>/Digital Input' incorporates:
     *  MATLABSystem: '<S2>/Digital Input'
     */
    Arduino_Blinking_LED_DW.obj_l.matlabCodegenIsDeleted = true;
    Arduino_Blinking_LED_DW.obj_l.isInitialized = 0L;
    Arduino_Blinking_LED_DW.obj_l.matlabCodegenIsDeleted = false;
    Arduino_Blinking_LED_DW.objisempty_i = true;
    tmp = !rtIsInf(Arduino_Blinking_LED_P.Ts);
    tmp_0 = !rtIsNaN(Arduino_Blinking_LED_P.Ts);
    Arduino_Blinking_LED_DW.obj_l.SampleTime = Arduino_Blinking_LED_P.Ts;
    Arduino_Blinking_LED_DW.obj_l.isSetupComplete = false;
    Arduino_Blinking_LED_DW.obj_l.isInitialized = 1L;
    digitalIOSetup((uint8_T)Arduino_Blinking_LED_PinNumber, false);
    Arduino_Blinking_LED_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Input' */
    Arduino_Blinking_LED_DW.obj.matlabCodegenIsDeleted = true;
    Arduino_Blinking_LED_DW.obj.isInitialized = 0L;
    Arduino_Blinking_LED_DW.obj.matlabCodegenIsDeleted = false;
    Arduino_Blinking_LED_DW.objisempty_m = true;
    if ((tmp && tmp_0) || rtIsInf(Arduino_Blinking_LED_P.Ts)) {
      sampleTime = Arduino_Blinking_LED_P.Ts;
    }

    Arduino_Blinking_LED_DW.obj.SampleTime = sampleTime;
    Arduino_Blinking_LED_DW.obj.isSetupComplete = false;
    Arduino_Blinking_LED_DW.obj.isInitialized = 1L;
    digitalIOSetup((uint8_T)Arduino_Blinking_LE_PinNumber_f, false);
    Arduino_Blinking_LED_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Output' */
    Arduino_Blinking_LED_DW.obj_e.matlabCodegenIsDeleted = true;
    Arduino_Blinking_LED_DW.obj_e.isInitialized = 0L;
    Arduino_Blinking_LED_DW.obj_e.matlabCodegenIsDeleted = false;
    Arduino_Blinking_LED_DW.objisempty = true;
    Arduino_Blinking_LED_DW.obj_e.isSetupComplete = false;
    Arduino_Blinking_LED_DW.obj_e.isInitialized = 1L;
    digitalIOSetup((uint8_T)Arduino_Blinking_L_PinNumber_f2, true);
    Arduino_Blinking_LED_DW.obj_e.isSetupComplete = true;
  }

  Arduino_Blinking_LED_PrevZCX.SampleandHold_Trig_ZCE = POS_ZCSIG;
  Arduino_Blinking_LED_PrevZCX.TriggeredSubsystem_Trig_ZCE = POS_ZCSIG;

  /* InitializeConditions for Delay: '<Root>/Delay' */
  Arduino_Blinking_LED_DW.Delay_DSTATE =
    Arduino_Blinking_LED_P.Delay_InitialCondition;

  /* InitializeConditions for Delay: '<Root>/Delay1' */
  Arduino_Blinking_LED_DW.Delay1_DSTATE =
    Arduino_Blinking_LED_P.Delay1_InitialCondition;

  /* InitializeConditions for Delay: '<Root>/Delay3' */
  Arduino_Blinking_LED_DW.Delay3_DSTATE =
    Arduino_Blinking_LED_P.Delay3_InitialCondition;

  /* SystemInitialize for Triggered SubSystem: '<Root>/Sample and Hold' */
  /* SystemInitialize for Outport: '<S3>/ ' */
  Arduino_Blinking_LED_B.In = Arduino_Blinking_LED_P._Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/Sample and Hold' */

  /* SystemInitialize for Triggered SubSystem: '<Root>/Triggered Subsystem' */
  /* SystemInitialize for Outport: '<S4>/Out1' */
  Arduino_Blinking_LED_B.Sum = Arduino_Blinking_LED_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/Triggered Subsystem' */
}

/* Model terminate function */
void Arduino_Blinking_LED_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Digital Input' */
  matlabCodegenHandle_matlabCodeg(&Arduino_Blinking_LED_DW.obj_l);

  /* Terminate for MATLABSystem: '<S2>/Digital Input' */
  matlabCodegenHandle_matlabCodeg(&Arduino_Blinking_LED_DW.obj);

  /* Terminate for MATLABSystem: '<S5>/Digital Output' */
  matlabCodegenHandle_matlabCo_f2(&Arduino_Blinking_LED_DW.obj_e);
}
