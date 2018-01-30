/*
 * RRR_arm_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "RRR_arm".
 *
 * Model version              : 1.142
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Wed May  3 12:04:40 2017
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "RRR_arm.h"
#include "RRR_arm_private.h"

/* Block parameters (auto storage) */
P_RRR_arm_T RRR_arm_P = {
  300.0,                               /* Variable: Kp
                                        * Referenced by:
                                        *   '<Root>/Kp'
                                        *   '<Root>/Kv'
                                        */
  30.0,                                /* Expression: 30
                                        * Referenced by: '<Root>/q1_ref1'
                                        */
  30.0,                                /* Expression: 30
                                        * Referenced by: '<Root>/q2_ref1'
                                        */
  30.0,                                /* Expression: 30
                                        * Referenced by: '<Root>/q3_ref1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/theta1_initial'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/theta1dot_initial'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/theta2_initial'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/theta2dot_initial'
                                        */
  90.0,                                /* Expression: 90
                                        * Referenced by: '<Root>/theta3_initial'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/theta3dot_initial'
                                        */
  0.0175,                              /* Expression: 0.0175
                                        * Referenced by: '<Root>/deg to rad'
                                        */
  57.2958,                             /* Expression: 57.2958
                                        * Referenced by: '<Root>/rad to deg2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Step1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Step2'
                                        */
  0.0175,                              /* Expression: 0.0175
                                        * Referenced by: '<Root>/deg to rad3'
                                        */
  57.2958,                             /* Expression: 57.2958
                                        * Referenced by: '<Root>/rad to deg5'
                                        */
  57.2958,                             /* Expression: 57.2958
                                        * Referenced by: '<Root>/rad to deg1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/qd1_ref'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/qd2_ref'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/qd3_ref'
                                        */
  0.0175,                              /* Expression: 0.0175
                                        * Referenced by: '<Root>/deg to rad2'
                                        */
  57.2958,                             /* Expression: 57.2958
                                        * Referenced by: '<Root>/rad to deg4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/SFric1'
                                        */
  200.0,                               /* Expression: 200
                                        * Referenced by: '<Root>/DFric1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/SFric2'
                                        */
  150.0,                               /* Expression: 150
                                        * Referenced by: '<Root>/DFric2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/SFric3'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<Root>/DFric3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/qdd1_ref'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/qdd2_ref'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/qdd3_ref'
                                        */
  0.0175,                              /* Expression: 0.0175
                                        * Referenced by: '<Root>/deg to rad1'
                                        */
  57.2958,                             /* Expression: 57.2958
                                        * Referenced by: '<Root>/rad to deg3'
                                        */
  1U,                                  /* Computed Parameter: MS1_CurrentSetting
                                        * Referenced by: '<Root>/MS1'
                                        */
  1U,                                  /* Computed Parameter: MS2_CurrentSetting
                                        * Referenced by: '<Root>/MS2'
                                        */
  1U,                                  /* Computed Parameter: MS3_CurrentSetting
                                        * Referenced by: '<Root>/MS3'
                                        */
  0U                                   /* Computed Parameter: MS4_CurrentSetting
                                        * Referenced by: '<Root>/MS4'
                                        */
};
