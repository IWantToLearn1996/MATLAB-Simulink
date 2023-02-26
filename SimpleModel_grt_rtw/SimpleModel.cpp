/*
 * SimpleModel.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "SimpleModel".
 *
 * Model version              : 7.0
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C++ source code generated on : Sun Feb 26 14:39:22 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "SimpleModel.h"
#include "SimpleModel_private.h"

/* Model step function */
void SimpleModel::step()
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  (&SimpleModel_M)->Timing.t[0] =
    ((time_T)(++(&SimpleModel_M)->Timing.clockTick0)) * (&SimpleModel_M)
    ->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.2s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.2, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    (&SimpleModel_M)->Timing.clockTick1++;
  }
}

/* Model initialize function */
void SimpleModel::initialize()
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&(&SimpleModel_M)->solverInfo, &(&SimpleModel_M)
                          ->Timing.simTimeStep);
    rtsiSetTPtr(&(&SimpleModel_M)->solverInfo, &rtmGetTPtr((&SimpleModel_M)));
    rtsiSetStepSizePtr(&(&SimpleModel_M)->solverInfo, &(&SimpleModel_M)
                       ->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&(&SimpleModel_M)->solverInfo, (&rtmGetErrorStatus
      ((&SimpleModel_M))));
    rtsiSetRTModelPtr(&(&SimpleModel_M)->solverInfo, (&SimpleModel_M));
  }

  rtsiSetSimTimeStep(&(&SimpleModel_M)->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&(&SimpleModel_M)->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr((&SimpleModel_M), &(&SimpleModel_M)->Timing.tArray[0]);
  (&SimpleModel_M)->Timing.stepSize0 = 0.2;
}

/* Model terminate function */
void SimpleModel::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
SimpleModel::SimpleModel() :
  SimpleModel_DW(),
  SimpleModel_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
SimpleModel::~SimpleModel()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_SimpleModel_T * SimpleModel::getRTM()
{
  return (&SimpleModel_M);
}
