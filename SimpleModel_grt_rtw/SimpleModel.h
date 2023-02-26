/*
 * SimpleModel.h
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

#ifndef RTW_HEADER_SimpleModel_h_
#define RTW_HEADER_SimpleModel_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "SimpleModel_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block states (default storage) for system '<Root>' */
struct DW_SimpleModel_T {
  real_T LTI_STATE_1_FirstOutput;      /* '<S6>/LTI_STATE_1' */
  boolean_T LTI_STATE_1_ReInit;        /* '<S6>/LTI_STATE_1' */
};

/* Real-time Model Data Structure */
struct tag_RTM_SimpleModel_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Class declaration for model SimpleModel */
class SimpleModel final
{
  /* public data and function members */
 public:
  /* Copy Constructor */
  SimpleModel(SimpleModel const&) = delete;

  /* Assignment Operator */
  SimpleModel& operator= (SimpleModel const&) & = delete;

  /* Move Constructor */
  SimpleModel(SimpleModel &&) = delete;

  /* Move Assignment Operator */
  SimpleModel& operator= (SimpleModel &&) = delete;

  /* Real-Time Model get method */
  RT_MODEL_SimpleModel_T * getRTM();

  /* Initial conditions function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  static void terminate();

  /* Constructor */
  SimpleModel();

  /* Destructor */
  ~SimpleModel();

  /* private data and function members */
 private:
  /* Block states */
  DW_SimpleModel_T SimpleModel_DW;

  /* Real-Time Model */
  RT_MODEL_SimpleModel_T SimpleModel_M;
};

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 */

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
 * '<Root>' : 'SimpleModel'
 * '<S1>'   : 'SimpleModel/PS-Simulink Converter'
 * '<S2>'   : 'SimpleModel/PS-Simulink Converter1'
 * '<S3>'   : 'SimpleModel/Solver Configuration'
 * '<S4>'   : 'SimpleModel/PS-Simulink Converter/EVAL_KEY'
 * '<S5>'   : 'SimpleModel/PS-Simulink Converter1/EVAL_KEY'
 * '<S6>'   : 'SimpleModel/Solver Configuration/EVAL_KEY'
 */
#endif                                 /* RTW_HEADER_SimpleModel_h_ */
