/*
 * Arduino_Blinking_LED_data.c
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

/* Block parameters (default storage) */
P_Arduino_Blinking_LED_T Arduino_Blinking_LED_P = {
  /* Variable: Ts
   * Referenced by:
   *   '<Root>/Constant1'
   *   '<Root>/Gain4'
   *   '<S1>/Digital Input'
   *   '<S2>/Digital Input'
   */
  1.0E-6,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S4>/Out1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S4>/Constant'
   */
  1.0,

  /* Expression: 40
   * Referenced by: '<Root>/Constant'
   */
  40.0,

  /* Expression: 360
   * Referenced by: '<Root>/Constant2'
   */
  360.0,

  /* Expression: 0.0
   * Referenced by: '<Root>/Delay2'
   */
  0.0,

  /* Expression: 1/1000
   * Referenced by: '<Root>/Gain3'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<Root>/Angle Initial'
   */
  0.0,

  /* Expression: 130/72000 * 10
   * Referenced by: '<Root>/Gain'
   */
  0.018055555555555554,

  /* Expression: 0.0
   * Referenced by: '<Root>/Delay'
   */
  0.0,

  /* Expression: 130/2
   * Referenced by: '<Root>/Gain1'
   */
  65.0,

  /* Expression: 0.0
   * Referenced by: '<Root>/Delay1'
   */
  0.0,

  /* Expression: 1/2
   * Referenced by: '<Root>/Gain5'
   */
  0.5,

  /* Expression: 0.0
   * Referenced by: '<Root>/Delay3'
   */
  0.0,

  /* Expression: .0001
   * Referenced by: '<Root>/Gain2'
   */
  0.0001,

  /* Expression: 1000
   * Referenced by: '<Root>/Saturation'
   */
  1000.0,

  /* Expression: 300
   * Referenced by: '<Root>/Saturation'
   */
  300.0,

  /* Expression: 1
   * Referenced by: '<Root>/Saturation1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation1'
   */
  0.0,

  /* Computed Parameter: Delay2_DelayLength
   * Referenced by: '<Root>/Delay2'
   */
  1U,

  /* Computed Parameter: Delay_DelayLength
   * Referenced by: '<Root>/Delay'
   */
  1U,

  /* Computed Parameter: Delay1_DelayLength
   * Referenced by: '<Root>/Delay1'
   */
  1U,

  /* Computed Parameter: Delay3_DelayLength
   * Referenced by: '<Root>/Delay3'
   */
  1U,

  /* Computed Parameter: _Y0
   * Referenced by: '<S3>/ '
   */
  0U
};
