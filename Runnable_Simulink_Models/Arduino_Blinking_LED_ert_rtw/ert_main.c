#include "Arduino_Blinking_LED.h"
#include "rtwtypes.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  Arduino_Blinking_LED_step();

  /* Get model outputs here */
#ifndef _MW_ARDUINO_LOOP_

  cli();

#endif;

  OverrunFlag--;
}

volatile boolean_T stopRequested = false;
int main(void)
{
  volatile boolean_T runModel = true;
  float modelBaseRate = 1.0E-6;
  float systemClock = 0;
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(Arduino_Blinking_LED_M, 0);
  Arduino_Blinking_LED_initialize();
  configureArduinoAVRTimer();
  runModel =
    rtmGetErrorStatus(Arduino_Blinking_LED_M) == (NULL);

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  sei();
  while (runModel) {
    stopRequested = !(
                      rtmGetErrorStatus(Arduino_Blinking_LED_M) == (NULL));
    runModel = !(stopRequested);
    runModel = runModel && MW_Arduino_Loop();
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  Arduino_Blinking_LED_terminate();
  cli();
  return 0;
}
