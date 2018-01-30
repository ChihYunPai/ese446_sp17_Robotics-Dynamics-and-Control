/*
 * RRR_arm.c
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

/* Block signals (auto storage) */
B_RRR_arm_T RRR_arm_B;

/* Continuous states */
X_RRR_arm_T RRR_arm_X;

/* Block states (auto storage) */
DW_RRR_arm_T RRR_arm_DW;

/* Real-time model */
RT_MODEL_RRR_arm_T RRR_arm_M_;
RT_MODEL_RRR_arm_T *const RRR_arm_M = &RRR_arm_M_;

/* Forward declaration for local functions */
static void RRR_arm_ppval(const real_T pp_breaks[5], const real_T pp_coefs[16],
  const real_T x[801], real_T v[801]);

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  RRR_arm_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  RRR_arm_step();
  RRR_arm_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  RRR_arm_step();
  RRR_arm_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Function for MATLAB Function: '<Root>/Creat Time Table' */
static void RRR_arm_ppval(const real_T pp_breaks[5], const real_T pp_coefs[16],
  const real_T x[801], real_T v[801])
{
  int32_T ix;
  real_T xloc;
  int32_T low_i;
  int32_T low_ip1;
  int32_T high_i;
  int32_T mid_i;
  for (ix = 0; ix < 801; ix++) {
    if (rtIsNaN(x[ix])) {
      xloc = x[ix];
    } else {
      low_i = 0;
      low_ip1 = 2;
      high_i = 5;
      while (high_i > low_ip1) {
        mid_i = ((low_i + high_i) + 1) >> 1;
        if (x[ix] >= pp_breaks[mid_i - 1]) {
          low_i = mid_i - 1;
          low_ip1 = mid_i + 1;
        } else {
          high_i = mid_i;
        }
      }

      xloc = x[ix] - pp_breaks[low_i];
      xloc = ((xloc * pp_coefs[low_i] + pp_coefs[low_i + 4]) * xloc +
              pp_coefs[low_i + 8]) * xloc + pp_coefs[low_i + 12];
    }

    v[ix] = xloc;
  }
}

/* Model step function */
void RRR_arm_step(void)
{
  const real_T b_breaks[5] = { 0.0, 2.0, 4.0, 6.0, 8.0 };

  const real_T b_coefs[16] = { -5.2901785714285712, 6.4955357142857135,
    -7.5669642857142865, 3.1473214285714288, 18.080357142857142,
    -13.660714285714285, 25.312500000000004, -20.089285714285715, 0.0,
    8.8392857142857153, 32.142857142857139, 42.589285714285715, 0.0, 30.0, 45.0,
    150.0 };

  static const real_T Ts[801] = { 0.0, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07,
    0.08, 0.09, 0.1, 0.11, 0.12, 0.13, 0.14, 0.15, 0.16, 0.17, 0.18, 0.19, 0.2,
    0.21, 0.22, 0.23, 0.24, 0.25, 0.26, 0.27, 0.28, 0.29, 0.3, 0.31, 0.32, 0.33,
    0.34, 0.35000000000000003, 0.36, 0.37, 0.38, 0.39, 0.4, 0.41000000000000003,
    0.42, 0.43, 0.44, 0.45, 0.46, 0.47000000000000003, 0.48, 0.49, 0.5, 0.51,
    0.52, 0.53, 0.54, 0.55, 0.56, 0.57000000000000006, 0.58, 0.59, 0.6, 0.61,
    0.62, 0.63, 0.64, 0.65, 0.66, 0.67, 0.68, 0.69000000000000006,
    0.70000000000000007, 0.71, 0.72, 0.73, 0.74, 0.75, 0.76, 0.77, 0.78, 0.79,
    0.8, 0.81, 0.82000000000000006, 0.83000000000000007, 0.84, 0.85, 0.86, 0.87,
    0.88, 0.89, 0.9, 0.91, 0.92, 0.93, 0.94000000000000006, 0.95000000000000007,
    0.96, 0.97, 0.98, 0.99, 1.0, 1.01, 1.02, 1.03, 1.04, 1.05, 1.06, 1.07, 1.08,
    1.09, 1.1, 1.11, 1.12, 1.1300000000000001, 1.1400000000000001,
    1.1500000000000001, 1.16, 1.17, 1.18, 1.19, 1.2, 1.21, 1.22, 1.23, 1.24,
    1.25, 1.26, 1.27, 1.28, 1.29, 1.3, 1.31, 1.32, 1.33, 1.34, 1.35, 1.36, 1.37,
    1.3800000000000001, 1.3900000000000001, 1.4000000000000001, 1.41, 1.42, 1.43,
    1.44, 1.45, 1.46, 1.47, 1.48, 1.49, 1.5, 1.51, 1.52, 1.53, 1.54, 1.55, 1.56,
    1.57, 1.58, 1.59, 1.6, 1.61, 1.62, 1.6300000000000001, 1.6400000000000001,
    1.6500000000000001, 1.6600000000000001, 1.67, 1.68, 1.69, 1.7, 1.71, 1.72,
    1.73, 1.74, 1.75, 1.76, 1.77, 1.78, 1.79, 1.8, 1.81, 1.82, 1.83, 1.84, 1.85,
    1.86, 1.87, 1.8800000000000001, 1.8900000000000001, 1.9000000000000001,
    1.9100000000000001, 1.92, 1.93, 1.94, 1.95, 1.96, 1.97, 1.98, 1.99, 2.0,
    2.0100000000000002, 2.02, 2.0300000000000002, 2.04, 2.05, 2.06, 2.07, 2.08,
    2.09, 2.1, 2.11, 2.12, 2.13, 2.14, 2.15, 2.16, 2.17, 2.18, 2.19, 2.2, 2.21,
    2.22, 2.23, 2.24, 2.25, 2.2600000000000002, 2.27, 2.2800000000000002, 2.29,
    2.3000000000000003, 2.31, 2.32, 2.33, 2.34, 2.35, 2.36, 2.37, 2.38, 2.39,
    2.4, 2.41, 2.42, 2.43, 2.44, 2.45, 2.46, 2.47, 2.48, 2.49, 2.5,
    2.5100000000000002, 2.52, 2.5300000000000002, 2.54, 2.5500000000000003, 2.56,
    2.57, 2.58, 2.59, 2.6, 2.61, 2.62, 2.63, 2.64, 2.65, 2.66, 2.67, 2.68, 2.69,
    2.7, 2.71, 2.72, 2.73, 2.74, 2.75, 2.7600000000000002, 2.77,
    2.7800000000000002, 2.79, 2.8000000000000003, 2.81, 2.82, 2.83, 2.84, 2.85,
    2.86, 2.87, 2.88, 2.89, 2.9, 2.91, 2.92, 2.93, 2.94, 2.95, 2.96, 2.97, 2.98,
    2.99, 3.0, 3.0100000000000002, 3.02, 3.0300000000000002, 3.04,
    3.0500000000000003, 3.06, 3.0700000000000003, 3.08, 3.09, 3.1, 3.11, 3.12,
    3.13, 3.14, 3.15, 3.16, 3.17, 3.18, 3.19, 3.2, 3.21, 3.22, 3.23, 3.24, 3.25,
    3.2600000000000002, 3.27, 3.2800000000000002, 3.29, 3.3000000000000003, 3.31,
    3.3200000000000003, 3.33, 3.34, 3.35, 3.36, 3.37, 3.38, 3.39, 3.4, 3.41,
    3.42, 3.43, 3.44, 3.45, 3.46, 3.47, 3.48, 3.49, 3.5, 3.5100000000000002,
    3.52, 3.5300000000000002, 3.54, 3.5500000000000003, 3.56, 3.5700000000000003,
    3.58, 3.59, 3.6, 3.61, 3.62, 3.63, 3.64, 3.65, 3.66, 3.67, 3.68, 3.69, 3.7,
    3.71, 3.72, 3.73, 3.74, 3.75, 3.7600000000000002, 3.77, 3.7800000000000002,
    3.79, 3.8000000000000003, 3.81, 3.8200000000000003, 3.83, 3.84, 3.85, 3.86,
    3.87, 3.88, 3.89, 3.9, 3.91, 3.92, 3.93, 3.94, 3.95, 3.96, 3.97, 3.98, 3.99,
    4.0, 4.01, 4.02, 4.0299999999999994, 4.04, 4.05, 4.0600000000000005, 4.07,
    4.08, 4.09, 4.1, 4.1099999999999994, 4.12, 4.13, 4.1400000000000006, 4.15,
    4.16, 4.17, 4.18, 4.1899999999999995, 4.1999999999999993, 4.21, 4.22, 4.23,
    4.24, 4.25, 4.26, 4.27, 4.2799999999999994, 4.29, 4.3, 4.3100000000000005,
    4.32, 4.33, 4.34, 4.35, 4.3599999999999994, 4.37, 4.38, 4.3900000000000006,
    4.4, 4.41, 4.42, 4.43, 4.4399999999999995, 4.4499999999999993, 4.46, 4.47,
    4.48, 4.49, 4.5, 4.51, 4.52, 4.5299999999999994, 4.54, 4.55,
    4.5600000000000005, 4.57, 4.58, 4.59, 4.6, 4.6099999999999994, 4.62, 4.63,
    4.6400000000000006, 4.65, 4.66, 4.67, 4.68, 4.6899999999999995,
    4.6999999999999993, 4.71, 4.72, 4.73, 4.74, 4.75, 4.76, 4.77,
    4.7799999999999994, 4.79, 4.8, 4.8100000000000005, 4.82, 4.83, 4.84, 4.85,
    4.8599999999999994, 4.87, 4.88, 4.8900000000000006, 4.9, 4.91, 4.92, 4.93,
    4.9399999999999995, 4.9499999999999993, 4.96, 4.97, 4.98, 4.99, 5.0, 5.01,
    5.02, 5.0299999999999994, 5.04, 5.05, 5.0600000000000005, 5.07, 5.08, 5.09,
    5.1, 5.1099999999999994, 5.12, 5.13, 5.1400000000000006, 5.15, 5.16, 5.17,
    5.18, 5.1899999999999995, 5.1999999999999993, 5.21, 5.22, 5.23, 5.24, 5.25,
    5.26, 5.27, 5.2799999999999994, 5.29, 5.3, 5.3100000000000005, 5.32, 5.33,
    5.34, 5.35, 5.3599999999999994, 5.37, 5.38, 5.3900000000000006, 5.4, 5.41,
    5.42, 5.43, 5.4399999999999995, 5.4499999999999993, 5.46, 5.47, 5.48, 5.49,
    5.5, 5.51, 5.52, 5.5299999999999994, 5.54, 5.55, 5.5600000000000005, 5.57,
    5.58, 5.59, 5.6, 5.6099999999999994, 5.62, 5.63, 5.6400000000000006, 5.65,
    5.66, 5.67, 5.68, 5.6899999999999995, 5.6999999999999993, 5.71, 5.72, 5.73,
    5.74, 5.75, 5.76, 5.77, 5.7799999999999994, 5.79, 5.8, 5.8100000000000005,
    5.82, 5.83, 5.84, 5.85, 5.8599999999999994, 5.87, 5.88, 5.8900000000000006,
    5.9, 5.91, 5.92, 5.93, 5.9399999999999995, 5.95, 5.96, 5.97, 5.98, 5.99, 6.0,
    6.01, 6.02, 6.03, 6.04, 6.05, 6.0600000000000005, 6.07, 6.08, 6.09, 6.1,
    6.1099999999999994, 6.12, 6.13, 6.14, 6.15, 6.16, 6.17, 6.18,
    6.1899999999999995, 6.2, 6.21, 6.22, 6.23, 6.24, 6.25, 6.26, 6.27, 6.28,
    6.29, 6.3, 6.3100000000000005, 6.32, 6.33, 6.34, 6.35, 6.3599999999999994,
    6.37, 6.38, 6.39, 6.4, 6.41, 6.42, 6.43, 6.4399999999999995, 6.45, 6.46,
    6.47, 6.48, 6.49, 6.5, 6.51, 6.52, 6.53, 6.54, 6.55, 6.5600000000000005,
    6.57, 6.58, 6.59, 6.6, 6.6099999999999994, 6.62, 6.63, 6.64, 6.65, 6.66,
    6.67, 6.68, 6.6899999999999995, 6.7, 6.71, 6.72, 6.73, 6.74, 6.75, 6.76,
    6.77, 6.78, 6.79, 6.8, 6.8100000000000005, 6.82, 6.83, 6.84, 6.85,
    6.8599999999999994, 6.87, 6.88, 6.89, 6.9, 6.91, 6.92, 6.93,
    6.9399999999999995, 6.95, 6.96, 6.97, 6.98, 6.99, 7.0, 7.01, 7.02, 7.03,
    7.04, 7.05, 7.06, 7.07, 7.08, 7.09, 7.1, 7.11, 7.12, 7.13, 7.14, 7.15, 7.16,
    7.17, 7.18, 7.1899999999999995, 7.2, 7.21, 7.22, 7.23, 7.24, 7.25, 7.26,
    7.27, 7.28, 7.29, 7.3, 7.31, 7.32, 7.33, 7.34, 7.35, 7.36, 7.37, 7.38, 7.39,
    7.4, 7.41, 7.42, 7.43, 7.4399999999999995, 7.45, 7.46, 7.47, 7.48, 7.49, 7.5,
    7.51, 7.52, 7.53, 7.54, 7.55, 7.56, 7.57, 7.58, 7.59, 7.6, 7.61, 7.62, 7.63,
    7.64, 7.65, 7.66, 7.67, 7.68, 7.69, 7.7, 7.71, 7.72, 7.73, 7.74, 7.75, 7.76,
    7.77, 7.78, 7.79, 7.8, 7.81, 7.82, 7.83, 7.84, 7.85, 7.86, 7.87, 7.88, 7.89,
    7.9, 7.91, 7.92, 7.93, 7.94, 7.95, 7.96, 7.97, 7.98, 7.99, 8.0 };

  static const real_T c[801] = { 0.0, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07,
    0.08, 0.09, 0.1, 0.11, 0.12, 0.13, 0.14, 0.15, 0.16, 0.17, 0.18, 0.19, 0.2,
    0.21, 0.22, 0.23, 0.24, 0.25, 0.26, 0.27, 0.28, 0.29, 0.3, 0.31, 0.32, 0.33,
    0.34, 0.35000000000000003, 0.36, 0.37, 0.38, 0.39, 0.4, 0.41000000000000003,
    0.42, 0.43, 0.44, 0.45, 0.46, 0.47000000000000003, 0.48, 0.49, 0.5, 0.51,
    0.52, 0.53, 0.54, 0.55, 0.56, 0.57000000000000006, 0.58, 0.59, 0.6, 0.61,
    0.62, 0.63, 0.64, 0.65, 0.66, 0.67, 0.68, 0.69000000000000006,
    0.70000000000000007, 0.71, 0.72, 0.73, 0.74, 0.75, 0.76, 0.77, 0.78, 0.79,
    0.8, 0.81, 0.82000000000000006, 0.83000000000000007, 0.84, 0.85, 0.86, 0.87,
    0.88, 0.89, 0.9, 0.91, 0.92, 0.93, 0.94000000000000006, 0.95000000000000007,
    0.96, 0.97, 0.98, 0.99, 1.0, 1.01, 1.02, 1.03, 1.04, 1.05, 1.06, 1.07, 1.08,
    1.09, 1.1, 1.11, 1.12, 1.1300000000000001, 1.1400000000000001,
    1.1500000000000001, 1.16, 1.17, 1.18, 1.19, 1.2, 1.21, 1.22, 1.23, 1.24,
    1.25, 1.26, 1.27, 1.28, 1.29, 1.3, 1.31, 1.32, 1.33, 1.34, 1.35, 1.36, 1.37,
    1.3800000000000001, 1.3900000000000001, 1.4000000000000001, 1.41, 1.42, 1.43,
    1.44, 1.45, 1.46, 1.47, 1.48, 1.49, 1.5, 1.51, 1.52, 1.53, 1.54, 1.55, 1.56,
    1.57, 1.58, 1.59, 1.6, 1.61, 1.62, 1.6300000000000001, 1.6400000000000001,
    1.6500000000000001, 1.6600000000000001, 1.67, 1.68, 1.69, 1.7, 1.71, 1.72,
    1.73, 1.74, 1.75, 1.76, 1.77, 1.78, 1.79, 1.8, 1.81, 1.82, 1.83, 1.84, 1.85,
    1.86, 1.87, 1.8800000000000001, 1.8900000000000001, 1.9000000000000001,
    1.9100000000000001, 1.92, 1.93, 1.94, 1.95, 1.96, 1.97, 1.98, 1.99, 2.0,
    2.0100000000000002, 2.02, 2.0300000000000002, 2.04, 2.05, 2.06, 2.07, 2.08,
    2.09, 2.1, 2.11, 2.12, 2.13, 2.14, 2.15, 2.16, 2.17, 2.18, 2.19, 2.2, 2.21,
    2.22, 2.23, 2.24, 2.25, 2.2600000000000002, 2.27, 2.2800000000000002, 2.29,
    2.3000000000000003, 2.31, 2.32, 2.33, 2.34, 2.35, 2.36, 2.37, 2.38, 2.39,
    2.4, 2.41, 2.42, 2.43, 2.44, 2.45, 2.46, 2.47, 2.48, 2.49, 2.5,
    2.5100000000000002, 2.52, 2.5300000000000002, 2.54, 2.5500000000000003, 2.56,
    2.57, 2.58, 2.59, 2.6, 2.61, 2.62, 2.63, 2.64, 2.65, 2.66, 2.67, 2.68, 2.69,
    2.7, 2.71, 2.72, 2.73, 2.74, 2.75, 2.7600000000000002, 2.77,
    2.7800000000000002, 2.79, 2.8000000000000003, 2.81, 2.82, 2.83, 2.84, 2.85,
    2.86, 2.87, 2.88, 2.89, 2.9, 2.91, 2.92, 2.93, 2.94, 2.95, 2.96, 2.97, 2.98,
    2.99, 3.0, 3.0100000000000002, 3.02, 3.0300000000000002, 3.04,
    3.0500000000000003, 3.06, 3.0700000000000003, 3.08, 3.09, 3.1, 3.11, 3.12,
    3.13, 3.14, 3.15, 3.16, 3.17, 3.18, 3.19, 3.2, 3.21, 3.22, 3.23, 3.24, 3.25,
    3.2600000000000002, 3.27, 3.2800000000000002, 3.29, 3.3000000000000003, 3.31,
    3.3200000000000003, 3.33, 3.34, 3.35, 3.36, 3.37, 3.38, 3.39, 3.4, 3.41,
    3.42, 3.43, 3.44, 3.45, 3.46, 3.47, 3.48, 3.49, 3.5, 3.5100000000000002,
    3.52, 3.5300000000000002, 3.54, 3.5500000000000003, 3.56, 3.5700000000000003,
    3.58, 3.59, 3.6, 3.61, 3.62, 3.63, 3.64, 3.65, 3.66, 3.67, 3.68, 3.69, 3.7,
    3.71, 3.72, 3.73, 3.74, 3.75, 3.7600000000000002, 3.77, 3.7800000000000002,
    3.79, 3.8000000000000003, 3.81, 3.8200000000000003, 3.83, 3.84, 3.85, 3.86,
    3.87, 3.88, 3.89, 3.9, 3.91, 3.92, 3.93, 3.94, 3.95, 3.96, 3.97, 3.98, 3.99,
    4.0, 4.01, 4.02, 4.0299999999999994, 4.04, 4.05, 4.0600000000000005, 4.07,
    4.08, 4.09, 4.1, 4.1099999999999994, 4.12, 4.13, 4.1400000000000006, 4.15,
    4.16, 4.17, 4.18, 4.1899999999999995, 4.1999999999999993, 4.21, 4.22, 4.23,
    4.24, 4.25, 4.26, 4.27, 4.2799999999999994, 4.29, 4.3, 4.3100000000000005,
    4.32, 4.33, 4.34, 4.35, 4.3599999999999994, 4.37, 4.38, 4.3900000000000006,
    4.4, 4.41, 4.42, 4.43, 4.4399999999999995, 4.4499999999999993, 4.46, 4.47,
    4.48, 4.49, 4.5, 4.51, 4.52, 4.5299999999999994, 4.54, 4.55,
    4.5600000000000005, 4.57, 4.58, 4.59, 4.6, 4.6099999999999994, 4.62, 4.63,
    4.6400000000000006, 4.65, 4.66, 4.67, 4.68, 4.6899999999999995,
    4.6999999999999993, 4.71, 4.72, 4.73, 4.74, 4.75, 4.76, 4.77,
    4.7799999999999994, 4.79, 4.8, 4.8100000000000005, 4.82, 4.83, 4.84, 4.85,
    4.8599999999999994, 4.87, 4.88, 4.8900000000000006, 4.9, 4.91, 4.92, 4.93,
    4.9399999999999995, 4.9499999999999993, 4.96, 4.97, 4.98, 4.99, 5.0, 5.01,
    5.02, 5.0299999999999994, 5.04, 5.05, 5.0600000000000005, 5.07, 5.08, 5.09,
    5.1, 5.1099999999999994, 5.12, 5.13, 5.1400000000000006, 5.15, 5.16, 5.17,
    5.18, 5.1899999999999995, 5.1999999999999993, 5.21, 5.22, 5.23, 5.24, 5.25,
    5.26, 5.27, 5.2799999999999994, 5.29, 5.3, 5.3100000000000005, 5.32, 5.33,
    5.34, 5.35, 5.3599999999999994, 5.37, 5.38, 5.3900000000000006, 5.4, 5.41,
    5.42, 5.43, 5.4399999999999995, 5.4499999999999993, 5.46, 5.47, 5.48, 5.49,
    5.5, 5.51, 5.52, 5.5299999999999994, 5.54, 5.55, 5.5600000000000005, 5.57,
    5.58, 5.59, 5.6, 5.6099999999999994, 5.62, 5.63, 5.6400000000000006, 5.65,
    5.66, 5.67, 5.68, 5.6899999999999995, 5.6999999999999993, 5.71, 5.72, 5.73,
    5.74, 5.75, 5.76, 5.77, 5.7799999999999994, 5.79, 5.8, 5.8100000000000005,
    5.82, 5.83, 5.84, 5.85, 5.8599999999999994, 5.87, 5.88, 5.8900000000000006,
    5.9, 5.91, 5.92, 5.93, 5.9399999999999995, 5.95, 5.96, 5.97, 5.98, 5.99, 6.0,
    6.01, 6.02, 6.03, 6.04, 6.05, 6.0600000000000005, 6.07, 6.08, 6.09, 6.1,
    6.1099999999999994, 6.12, 6.13, 6.14, 6.15, 6.16, 6.17, 6.18,
    6.1899999999999995, 6.2, 6.21, 6.22, 6.23, 6.24, 6.25, 6.26, 6.27, 6.28,
    6.29, 6.3, 6.3100000000000005, 6.32, 6.33, 6.34, 6.35, 6.3599999999999994,
    6.37, 6.38, 6.39, 6.4, 6.41, 6.42, 6.43, 6.4399999999999995, 6.45, 6.46,
    6.47, 6.48, 6.49, 6.5, 6.51, 6.52, 6.53, 6.54, 6.55, 6.5600000000000005,
    6.57, 6.58, 6.59, 6.6, 6.6099999999999994, 6.62, 6.63, 6.64, 6.65, 6.66,
    6.67, 6.68, 6.6899999999999995, 6.7, 6.71, 6.72, 6.73, 6.74, 6.75, 6.76,
    6.77, 6.78, 6.79, 6.8, 6.8100000000000005, 6.82, 6.83, 6.84, 6.85,
    6.8599999999999994, 6.87, 6.88, 6.89, 6.9, 6.91, 6.92, 6.93,
    6.9399999999999995, 6.95, 6.96, 6.97, 6.98, 6.99, 7.0, 7.01, 7.02, 7.03,
    7.04, 7.05, 7.06, 7.07, 7.08, 7.09, 7.1, 7.11, 7.12, 7.13, 7.14, 7.15, 7.16,
    7.17, 7.18, 7.1899999999999995, 7.2, 7.21, 7.22, 7.23, 7.24, 7.25, 7.26,
    7.27, 7.28, 7.29, 7.3, 7.31, 7.32, 7.33, 7.34, 7.35, 7.36, 7.37, 7.38, 7.39,
    7.4, 7.41, 7.42, 7.43, 7.4399999999999995, 7.45, 7.46, 7.47, 7.48, 7.49, 7.5,
    7.51, 7.52, 7.53, 7.54, 7.55, 7.56, 7.57, 7.58, 7.59, 7.6, 7.61, 7.62, 7.63,
    7.64, 7.65, 7.66, 7.67, 7.68, 7.69, 7.7, 7.71, 7.72, 7.73, 7.74, 7.75, 7.76,
    7.77, 7.78, 7.79, 7.8, 7.81, 7.82, 7.83, 7.84, 7.85, 7.86, 7.87, 7.88, 7.89,
    7.9, 7.91, 7.92, 7.93, 7.94, 7.95, 7.96, 7.97, 7.98, 7.99, 8.0 };

  const real_T d_breaks[5] = { 0.0, 2.0, 4.0, 6.0, 8.0 };

  const real_T d_coefs[16] = { 14.151785714285714, -21.205357142857146,
    19.419642857142858, -10.223214285714285, -30.803571428571427,
    54.107142857142861, -73.125, 43.392857142857139, 0.0, 46.607142857142854,
    8.5714285714285712, -50.892857142857139, 0.0, -10.0, 130.0, 10.0 };

  const real_T e_breaks[5] = { 0.0, 2.0, 4.0, 6.0, 8.0 };

  const real_T e_coefs[16] = { -12.611607142857142, 25.959821428571427,
    -35.602678571428569, 38.325892857142861, 20.223214285714285,
    -55.446428571428569, 100.3125, -113.30357142857143, 0.0, -70.446428571428569,
    19.285714285714285, -6.6964285714285712, 90.0, 70.0, -85.0, 70.0 };

  real_T M[9];
  real_T C[9];
  real_T B[9];
  real_T G[3];
  real_T M_0[9];
  real_T G_0[3];
  int32_T r2;
  int32_T r3;
  int32_T rtemp;
  real_T rtb_q_e[3];
  real_T rtb_qdot[3];
  real_T rtb_Clock;
  int32_T i;
  real_T rtb_TmpSignalConversionAtSFun_0[3];
  real_T rtb_degtorad3_idx_0;
  real_T rtb_degtorad3_idx_1;
  real_T rtb_degtorad3_idx_2;
  real_T tmp;
  real_T tmp_0;
  real_T tmp_1;
  real_T tmp_2;
  boolean_T exitg1;
  if (rtmIsMajorTimeStep(RRR_arm_M)) {
    /* set solver stop time */
    if (!(RRR_arm_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&RRR_arm_M->solverInfo,
                            ((RRR_arm_M->Timing.clockTickH0 + 1) *
        RRR_arm_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&RRR_arm_M->solverInfo,
                            ((RRR_arm_M->Timing.clockTick0 + 1) *
        RRR_arm_M->Timing.stepSize0 + RRR_arm_M->Timing.clockTickH0 *
        RRR_arm_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(RRR_arm_M)) {
    RRR_arm_M->Timing.t[0] = rtsiGetT(&RRR_arm_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(RRR_arm_M)) {
    /* Gain: '<Root>/deg to rad' incorporates:
     *  Constant: '<Root>/theta1_initial'
     *  Constant: '<Root>/theta1dot_initial'
     *  Constant: '<Root>/theta2_initial'
     *  Constant: '<Root>/theta2dot_initial'
     *  Constant: '<Root>/theta3_initial'
     *  Constant: '<Root>/theta3dot_initial'
     */
    RRR_arm_B.degtorad[0] = RRR_arm_P.degtorad_Gain *
      RRR_arm_P.theta1_initial_Value;
    RRR_arm_B.degtorad[1] = RRR_arm_P.degtorad_Gain *
      RRR_arm_P.theta1dot_initial_Value;
    RRR_arm_B.degtorad[2] = RRR_arm_P.degtorad_Gain *
      RRR_arm_P.theta2_initial_Value;
    RRR_arm_B.degtorad[3] = RRR_arm_P.degtorad_Gain *
      RRR_arm_P.theta2dot_initial_Value;
    RRR_arm_B.degtorad[4] = RRR_arm_P.degtorad_Gain *
      RRR_arm_P.theta3_initial_Value;
    RRR_arm_B.degtorad[5] = RRR_arm_P.degtorad_Gain *
      RRR_arm_P.theta3dot_initial_Value;
  }

  /* Integrator: '<Root>/Integrator' */
  if (RRR_arm_DW.Integrator_IWORK != 0) {
    for (i = 0; i < 6; i++) {
      RRR_arm_X.Integrator_CSTATE[i] = RRR_arm_B.degtorad[i];
    }
  }

  /* Gain: '<Root>/rad to deg2' incorporates:
   *  Integrator: '<Root>/Integrator'
   *  MATLAB Function: '<Root>/X to q and qdot'
   */
  /* MATLAB Function 'X to q and qdot': '<S4>:1' */
  /* '<S4>:1:2' */
  /* '<S4>:1:3' */
  RRR_arm_B.radtodeg2[0] = RRR_arm_P.radtodeg2_Gain *
    RRR_arm_X.Integrator_CSTATE[0];
  RRR_arm_B.radtodeg2[1] = RRR_arm_P.radtodeg2_Gain *
    RRR_arm_X.Integrator_CSTATE[2];
  RRR_arm_B.radtodeg2[2] = RRR_arm_P.radtodeg2_Gain *
    RRR_arm_X.Integrator_CSTATE[4];
  if (rtmIsMajorTimeStep(RRR_arm_M)) {
    /* MATLAB Function: '<Root>/Creat Time Table' */
    /* MATLAB Function 'Creat Time Table': '<S2>:1' */
    /* '<S2>:1:8' */
    /* '<S2>:1:7' */
    /* '<S2>:1:8' */
    RRR_arm_ppval(b_breaks, b_coefs, Ts, RRR_arm_B.y);
    RRR_arm_ppval(d_breaks, d_coefs, Ts, RRR_arm_B.dv0);
    RRR_arm_ppval(e_breaks, e_coefs, Ts, RRR_arm_B.dv1);
    for (i = 0; i < 801; i++) {
      RRR_arm_B.TimeLineTable[i] = c[i];
      RRR_arm_B.TimeLineTable[i + 801] = RRR_arm_B.y[i];
      RRR_arm_B.TimeLineTable[i + 1602] = RRR_arm_B.dv0[i];
      RRR_arm_B.TimeLineTable[i + 2403] = RRR_arm_B.dv1[i];
    }

    /* End of MATLAB Function: '<Root>/Creat Time Table' */
  }

  /* Step: '<Root>/Step2' */
  rtb_degtorad3_idx_2 = RRR_arm_M->Timing.t[0];

  /* Clock: '<Root>/Clock' */
  rtb_Clock = RRR_arm_M->Timing.t[0];

  /* MATLAB Function: '<Root>/path_trajectory' */
  /* MATLAB Function 'path_trajectory': '<S8>:1' */
  /* '<S8>:1:2' */
  for (i = 0; i < 801; i++) {
    RRR_arm_B.y[i] = fabs(rtb_Clock - RRR_arm_B.TimeLineTable[i]);
  }

  i = 1;
  rtb_Clock = RRR_arm_B.y[0];
  r2 = 0;
  if (rtIsNaN(RRR_arm_B.y[0])) {
    r3 = 2;
    exitg1 = false;
    while ((!exitg1) && (r3 < 802)) {
      i = r3;
      if (!rtIsNaN(RRR_arm_B.y[r3 - 1])) {
        rtb_Clock = RRR_arm_B.y[r3 - 1];
        r2 = r3 - 1;
        exitg1 = true;
      } else {
        r3++;
      }
    }
  }

  if (i < 801) {
    while (i + 1 < 802) {
      if (RRR_arm_B.y[i] < rtb_Clock) {
        rtb_Clock = RRR_arm_B.y[i];
        r2 = i;
      }

      i++;
    }
  }

  /* ManualSwitch: '<Root>/MS4' incorporates:
   *  Gain: '<Root>/q1_ref1'
   *  Gain: '<Root>/q2_ref1'
   *  Gain: '<Root>/q3_ref1'
   *  MATLAB Function: '<Root>/path_trajectory'
   */
  /* '<S8>:1:3' */
  if (RRR_arm_P.MS4_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/MS1' incorporates:
     *  Constant: '<Root>/constant'
     */
    if (RRR_arm_P.MS1_CurrentSetting == 1) {
      /* Step: '<Root>/Step' */
      if (RRR_arm_M->Timing.t[0] < RRR_arm_P.Step_Time) {
        rtb_Clock = RRR_arm_P.Step_Y0;
      } else {
        rtb_Clock = RRR_arm_P.Step_YFinal;
      }

      /* End of Step: '<Root>/Step' */
    } else {
      rtb_Clock = RRR_arm_P.constant_Value;
    }

    /* End of ManualSwitch: '<Root>/MS1' */
    rtb_degtorad3_idx_0 = RRR_arm_P.q1_ref1_Gain * rtb_Clock;

    /* ManualSwitch: '<Root>/MS2' incorporates:
     *  Constant: '<Root>/constant'
     *  Gain: '<Root>/q1_ref1'
     */
    if (RRR_arm_P.MS2_CurrentSetting == 1) {
      /* Step: '<Root>/Step1' */
      if (RRR_arm_M->Timing.t[0] < RRR_arm_P.Step1_Time) {
        rtb_Clock = RRR_arm_P.Step1_Y0;
      } else {
        rtb_Clock = RRR_arm_P.Step1_YFinal;
      }

      /* End of Step: '<Root>/Step1' */
    } else {
      rtb_Clock = RRR_arm_P.constant_Value;
    }

    /* End of ManualSwitch: '<Root>/MS2' */
    rtb_degtorad3_idx_1 = RRR_arm_P.q2_ref1_Gain * rtb_Clock;

    /* ManualSwitch: '<Root>/MS3' incorporates:
     *  Constant: '<Root>/constant'
     *  Gain: '<Root>/q2_ref1'
     */
    if (RRR_arm_P.MS3_CurrentSetting == 1) {
      /* Step: '<Root>/Step2' */
      if (rtb_degtorad3_idx_2 < RRR_arm_P.Step2_Time) {
        rtb_Clock = RRR_arm_P.Step2_Y0;
      } else {
        rtb_Clock = RRR_arm_P.Step2_YFinal;
      }
    } else {
      rtb_Clock = RRR_arm_P.constant_Value;
    }

    /* End of ManualSwitch: '<Root>/MS3' */
    rtb_degtorad3_idx_2 = RRR_arm_P.q3_ref1_Gain * rtb_Clock;
  } else {
    rtb_degtorad3_idx_0 = RRR_arm_B.TimeLineTable[r2 + 801];
    rtb_degtorad3_idx_1 = RRR_arm_B.TimeLineTable[r2 + 1602];
    rtb_degtorad3_idx_2 = RRR_arm_B.TimeLineTable[r2 + 2403];
  }

  /* End of ManualSwitch: '<Root>/MS4' */

  /* Gain: '<Root>/deg to rad3' */
  rtb_Clock = RRR_arm_P.degtorad3_Gain * rtb_degtorad3_idx_0;

  /* Gain: '<Root>/rad to deg5' incorporates:
   *  Integrator: '<Root>/Integrator'
   *  MATLAB Function: '<Root>/X to q and qdot'
   */
  RRR_arm_B.radtodeg5[0] = RRR_arm_P.radtodeg5_Gain * rtb_Clock;
  RRR_arm_B.radtodeg5[3] = RRR_arm_P.radtodeg5_Gain *
    RRR_arm_X.Integrator_CSTATE[0];

  /* Gain: '<Root>/deg to rad3' */
  rtb_degtorad3_idx_0 = rtb_Clock;
  rtb_Clock = RRR_arm_P.degtorad3_Gain * rtb_degtorad3_idx_1;

  /* Gain: '<Root>/rad to deg5' incorporates:
   *  Integrator: '<Root>/Integrator'
   *  MATLAB Function: '<Root>/X to q and qdot'
   */
  RRR_arm_B.radtodeg5[1] = RRR_arm_P.radtodeg5_Gain * rtb_Clock;
  RRR_arm_B.radtodeg5[4] = RRR_arm_P.radtodeg5_Gain *
    RRR_arm_X.Integrator_CSTATE[2];

  /* Gain: '<Root>/deg to rad3' */
  rtb_degtorad3_idx_1 = rtb_Clock;
  rtb_Clock = RRR_arm_P.degtorad3_Gain * rtb_degtorad3_idx_2;

  /* Gain: '<Root>/rad to deg5' incorporates:
   *  Integrator: '<Root>/Integrator'
   *  MATLAB Function: '<Root>/X to q and qdot'
   */
  RRR_arm_B.radtodeg5[2] = RRR_arm_P.radtodeg5_Gain * rtb_Clock;
  RRR_arm_B.radtodeg5[5] = RRR_arm_P.radtodeg5_Gain *
    RRR_arm_X.Integrator_CSTATE[4];
  if (rtmIsMajorTimeStep(RRR_arm_M)) {
  }

  /* Gain: '<Root>/rad to deg1' incorporates:
   *  Integrator: '<Root>/Integrator'
   *  MATLAB Function: '<Root>/X to q and qdot'
   */
  RRR_arm_B.radtodeg1[0] = RRR_arm_P.radtodeg1_Gain *
    RRR_arm_X.Integrator_CSTATE[1];
  RRR_arm_B.radtodeg1[1] = RRR_arm_P.radtodeg1_Gain *
    RRR_arm_X.Integrator_CSTATE[3];
  RRR_arm_B.radtodeg1[2] = RRR_arm_P.radtodeg1_Gain *
    RRR_arm_X.Integrator_CSTATE[5];
  if (rtmIsMajorTimeStep(RRR_arm_M)) {
    /* Gain: '<Root>/deg to rad2' incorporates:
     *  Constant: '<Root>/qd1_ref'
     *  Constant: '<Root>/qd2_ref'
     *  Constant: '<Root>/qd3_ref'
     */
    RRR_arm_B.degtorad2[0] = RRR_arm_P.degtorad2_Gain * RRR_arm_P.qd1_ref_Value;
    RRR_arm_B.degtorad2[1] = RRR_arm_P.degtorad2_Gain * RRR_arm_P.qd2_ref_Value;
    RRR_arm_B.degtorad2[2] = RRR_arm_P.degtorad2_Gain * RRR_arm_P.qd3_ref_Value;
  }

  /* Gain: '<Root>/rad to deg4' incorporates:
   *  Integrator: '<Root>/Integrator'
   *  MATLAB Function: '<Root>/X to q and qdot'
   */
  RRR_arm_B.radtodeg4[0] = RRR_arm_P.radtodeg4_Gain * RRR_arm_B.degtorad2[0];
  RRR_arm_B.radtodeg4[3] = RRR_arm_P.radtodeg4_Gain *
    RRR_arm_X.Integrator_CSTATE[1];
  RRR_arm_B.radtodeg4[1] = RRR_arm_P.radtodeg4_Gain * RRR_arm_B.degtorad2[1];
  RRR_arm_B.radtodeg4[4] = RRR_arm_P.radtodeg4_Gain *
    RRR_arm_X.Integrator_CSTATE[3];
  RRR_arm_B.radtodeg4[2] = RRR_arm_P.radtodeg4_Gain * RRR_arm_B.degtorad2[2];
  RRR_arm_B.radtodeg4[5] = RRR_arm_P.radtodeg4_Gain *
    RRR_arm_X.Integrator_CSTATE[5];
  if (rtmIsMajorTimeStep(RRR_arm_M)) {
    /* Gain: '<Root>/deg to rad1' incorporates:
     *  Constant: '<Root>/qdd1_ref'
     *  Constant: '<Root>/qdd2_ref'
     *  Constant: '<Root>/qdd3_ref'
     */
    RRR_arm_B.degtorad1[0] = RRR_arm_P.degtorad1_Gain * RRR_arm_P.qdd1_ref_Value;
    RRR_arm_B.degtorad1[1] = RRR_arm_P.degtorad1_Gain * RRR_arm_P.qdd2_ref_Value;
    RRR_arm_B.degtorad1[2] = RRR_arm_P.degtorad1_Gain * RRR_arm_P.qdd3_ref_Value;
  }

  /* Gain: '<Root>/Kv' */
  rtb_degtorad3_idx_2 = 2.0 * sqrt(RRR_arm_P.Kp);

  /* Sum: '<Root>/Sum4' incorporates:
   *  Gain: '<Root>/Kp'
   *  Gain: '<Root>/Kv'
   *  Integrator: '<Root>/Integrator'
   *  MATLAB Function: '<Root>/X to q and qdot'
   *  Sum: '<Root>/Sum1'
   *  Sum: '<Root>/Sum2'
   *  Sum: '<Root>/Sum3'
   */
  rtb_qdot[0] = ((RRR_arm_B.degtorad2[0] - RRR_arm_X.Integrator_CSTATE[1]) *
                 rtb_degtorad3_idx_2 + (rtb_degtorad3_idx_0 -
    RRR_arm_X.Integrator_CSTATE[0]) * RRR_arm_P.Kp) + RRR_arm_B.degtorad1[0];
  rtb_qdot[1] = ((RRR_arm_B.degtorad2[1] - RRR_arm_X.Integrator_CSTATE[3]) *
                 rtb_degtorad3_idx_2 + (rtb_degtorad3_idx_1 -
    RRR_arm_X.Integrator_CSTATE[2]) * RRR_arm_P.Kp) + RRR_arm_B.degtorad1[1];
  rtb_degtorad3_idx_0 = ((RRR_arm_B.degtorad2[2] - RRR_arm_X.Integrator_CSTATE[5])
    * rtb_degtorad3_idx_2 + (rtb_Clock - RRR_arm_X.Integrator_CSTATE[4]) *
    RRR_arm_P.Kp) + RRR_arm_B.degtorad1[2];

  /* MATLAB Function: '<Root>/M' incorporates:
   *  Integrator: '<Root>/Integrator'
   *  MATLAB Function: '<Root>/X to q and qdot'
   */
  /* MATLAB Function 'M': '<S3>:1' */
  /*  q1=q(1); */
  /* '<S3>:1:3' */
  /* '<S3>:1:4' */
  /* '<S3>:1:6' */
  M[0] = ((cos(RRR_arm_X.Integrator_CSTATE[2] + RRR_arm_X.Integrator_CSTATE[4]) *
           80.0 + 420.0 * cos(RRR_arm_X.Integrator_CSTATE[2])) + 60.0 * cos
          (RRR_arm_X.Integrator_CSTATE[4])) + 614.55;

  /* '<S3>:1:7' */
  M[3] = ((cos(RRR_arm_X.Integrator_CSTATE[2] + RRR_arm_X.Integrator_CSTATE[4]) *
           40.0 + 210.0 * cos(RRR_arm_X.Integrator_CSTATE[2])) + 60.0 * cos
          (RRR_arm_X.Integrator_CSTATE[4])) + 134.05;

  /* '<S3>:1:8' */
  M[6] = (cos(RRR_arm_X.Integrator_CSTATE[2] + RRR_arm_X.Integrator_CSTATE[4]) *
          40.0 + 30.0 * cos(RRR_arm_X.Integrator_CSTATE[4])) + 10.1;

  /* '<S3>:1:9' */
  M[1] = ((cos(RRR_arm_X.Integrator_CSTATE[2] + RRR_arm_X.Integrator_CSTATE[4]) *
           40.0 + 210.0 * cos(RRR_arm_X.Integrator_CSTATE[2])) + 60.0 * cos
          (RRR_arm_X.Integrator_CSTATE[4])) + 134.05;

  /* '<S3>:1:10' */
  M[4] = 60.0 * cos(RRR_arm_X.Integrator_CSTATE[4]) + 53620.0;

  /* '<S3>:1:11' */
  M[7] = 30.0 * cos(RRR_arm_X.Integrator_CSTATE[4]) + 10.1;

  /* '<S3>:1:12' */
  M[2] = (cos(RRR_arm_X.Integrator_CSTATE[2] + RRR_arm_X.Integrator_CSTATE[4]) *
          40.0 + 30.0 * cos(RRR_arm_X.Integrator_CSTATE[4])) + 10.1;

  /* '<S3>:1:13' */
  M[5] = 30.0 * cos(RRR_arm_X.Integrator_CSTATE[4]) + 10.1;

  /* '<S3>:1:14' */
  M[8] = 10.1;

  /* MATLAB Function: '<Root>/CBGF' incorporates:
   *  Constant: '<Root>/DFric1'
   *  Constant: '<Root>/DFric2'
   *  Constant: '<Root>/DFric3'
   *  Constant: '<Root>/SFric1'
   *  Constant: '<Root>/SFric2'
   *  Constant: '<Root>/SFric3'
   *  Integrator: '<Root>/Integrator'
   */
  /* '<S3>:1:15' */
  /* MATLAB Function 'CBGF': '<S1>:1' */
  /* '<S1>:1:20' */
  /* '<S1>:1:2' */
  /* '<S1>:1:3' */
  /* '<S1>:1:4' */
  /* '<S1>:1:5' */
  /* '<S1>:1:6' */
  /* '<S1>:1:7' */
  /* '<S1>:1:8' */
  /* '<S1>:1:9' */
  /* '<S1>:1:10' */
  /* '<S1>:1:11' */
  /* '<S1>:1:12' */
  /* '<S1>:1:13' */
  /* '<S1>:1:14' */
  /* '<S1>:1:15' */
  /* '<S1>:1:16' */
  /* '<S1>:1:17' */
  /* '<S1>:1:18' */
  /* '<S1>:1:20' */
  /* '<S1>:1:21' */
  memset(&C[0], 0, 9U * sizeof(real_T));
  memset(&B[0], 0, 9U * sizeof(real_T));
  C[3] = sin(RRR_arm_X.Integrator_CSTATE[2] + RRR_arm_X.Integrator_CSTATE[4]) *
    -40.0 - 210.0 * sin(RRR_arm_X.Integrator_CSTATE[2]);

  /* '<S1>:1:22' */
  C[6] = sin(RRR_arm_X.Integrator_CSTATE[2] + RRR_arm_X.Integrator_CSTATE[4]) *
    -40.0 - 30.0 * sin(RRR_arm_X.Integrator_CSTATE[4]);

  /* '<S1>:1:23' */
  C[1] = sin(RRR_arm_X.Integrator_CSTATE[2] + RRR_arm_X.Integrator_CSTATE[4]) *
    40.0 + 210.0 * sin(RRR_arm_X.Integrator_CSTATE[2]);

  /* '<S1>:1:24' */
  C[7] = -30.0 * sin(RRR_arm_X.Integrator_CSTATE[4]);

  /* '<S1>:1:25' */
  C[2] = sin(RRR_arm_X.Integrator_CSTATE[2] + RRR_arm_X.Integrator_CSTATE[4]) *
    40.0 + 30.0 * sin(RRR_arm_X.Integrator_CSTATE[4]);

  /* '<S1>:1:26' */
  C[5] = 30.0 * sin(RRR_arm_X.Integrator_CSTATE[4]);

  /* '<S1>:1:28' */
  /* '<S1>:1:29' */
  B[0] = sin(RRR_arm_X.Integrator_CSTATE[2] + RRR_arm_X.Integrator_CSTATE[4]) *
    -80.0 - 420.0 * sin(RRR_arm_X.Integrator_CSTATE[2]);

  /* '<S1>:1:30' */
  B[3] = sin(RRR_arm_X.Integrator_CSTATE[2] + RRR_arm_X.Integrator_CSTATE[4]) *
    -80.0 - 60.0 * sin(RRR_arm_X.Integrator_CSTATE[4]);

  /* '<S1>:1:31' */
  B[6] = sin(RRR_arm_X.Integrator_CSTATE[2] + RRR_arm_X.Integrator_CSTATE[4]) *
    -80.0 - 60.0 * sin(RRR_arm_X.Integrator_CSTATE[4]);

  /* '<S1>:1:32' */
  B[4] = -60.0 * sin(RRR_arm_X.Integrator_CSTATE[4]);

  /* '<S1>:1:33' */
  B[7] = -60.0 * sin(RRR_arm_X.Integrator_CSTATE[4]);

  /* '<S1>:1:34' */
  B[2] = 60.0 * sin(RRR_arm_X.Integrator_CSTATE[4]);

  /* '<S1>:1:36' */
  /* '<S1>:1:37' */
  G[0] = ((cos(RRR_arm_X.Integrator_CSTATE[0] + RRR_arm_X.Integrator_CSTATE[2]) *
           3.0 / 2.0 + 4.0 * cos(RRR_arm_X.Integrator_CSTATE[0])) * 147.15 +
          ((cos((RRR_arm_X.Integrator_CSTATE[0] + RRR_arm_X.Integrator_CSTATE[2])
                + RRR_arm_X.Integrator_CSTATE[4]) + cos
            (RRR_arm_X.Integrator_CSTATE[0] + RRR_arm_X.Integrator_CSTATE[2]) *
            3.0) + 4.0 * cos(RRR_arm_X.Integrator_CSTATE[0])) *
          98.100000000000009) + 392.40000000000003 * cos
    (RRR_arm_X.Integrator_CSTATE[0]);

  /* '<S1>:1:38' */
  G[1] = (cos((RRR_arm_X.Integrator_CSTATE[0] + RRR_arm_X.Integrator_CSTATE[2])
              + RRR_arm_X.Integrator_CSTATE[4]) + cos
          (RRR_arm_X.Integrator_CSTATE[0] + RRR_arm_X.Integrator_CSTATE[2]) *
          3.0) * 98.100000000000009 + cos(RRR_arm_X.Integrator_CSTATE[0] +
    RRR_arm_X.Integrator_CSTATE[2]) * 441.45000000000005 / 2.0;

  /* '<S1>:1:39' */
  G[2] = cos((RRR_arm_X.Integrator_CSTATE[0] + RRR_arm_X.Integrator_CSTATE[2]) +
             RRR_arm_X.Integrator_CSTATE[4]) * 98.100000000000009;

  /* '<S1>:1:41' */
  rtb_degtorad3_idx_1 = RRR_arm_X.Integrator_CSTATE[1] *
    RRR_arm_X.Integrator_CSTATE[1];
  rtb_degtorad3_idx_2 = RRR_arm_X.Integrator_CSTATE[3] *
    RRR_arm_X.Integrator_CSTATE[3];
  tmp = RRR_arm_X.Integrator_CSTATE[5] * RRR_arm_X.Integrator_CSTATE[5];
  tmp_0 = RRR_arm_X.Integrator_CSTATE[1] * RRR_arm_X.Integrator_CSTATE[3];
  tmp_1 = RRR_arm_X.Integrator_CSTATE[1] * RRR_arm_X.Integrator_CSTATE[5];
  tmp_2 = RRR_arm_X.Integrator_CSTATE[3] * RRR_arm_X.Integrator_CSTATE[5];
  if (RRR_arm_X.Integrator_CSTATE[1] < 0.0) {
    rtb_Clock = -1.0;
  } else if (RRR_arm_X.Integrator_CSTATE[1] > 0.0) {
    rtb_Clock = 1.0;
  } else if (RRR_arm_X.Integrator_CSTATE[1] == 0.0) {
    rtb_Clock = 0.0;
  } else {
    rtb_Clock = RRR_arm_X.Integrator_CSTATE[1];
  }

  rtb_TmpSignalConversionAtSFun_0[0] = RRR_arm_P.SFric1_Value * rtb_Clock +
    RRR_arm_P.DFric1_Value * RRR_arm_X.Integrator_CSTATE[1];
  if (RRR_arm_X.Integrator_CSTATE[3] < 0.0) {
    rtb_Clock = -1.0;
  } else if (RRR_arm_X.Integrator_CSTATE[3] > 0.0) {
    rtb_Clock = 1.0;
  } else if (RRR_arm_X.Integrator_CSTATE[3] == 0.0) {
    rtb_Clock = 0.0;
  } else {
    rtb_Clock = RRR_arm_X.Integrator_CSTATE[3];
  }

  rtb_TmpSignalConversionAtSFun_0[1] = RRR_arm_P.SFric2_Value * rtb_Clock +
    RRR_arm_P.DFric2_Value * RRR_arm_X.Integrator_CSTATE[3];
  if (RRR_arm_X.Integrator_CSTATE[5] < 0.0) {
    rtb_Clock = -1.0;
  } else if (RRR_arm_X.Integrator_CSTATE[5] > 0.0) {
    rtb_Clock = 1.0;
  } else if (RRR_arm_X.Integrator_CSTATE[5] == 0.0) {
    rtb_Clock = 0.0;
  } else {
    rtb_Clock = RRR_arm_X.Integrator_CSTATE[5];
  }

  rtb_TmpSignalConversionAtSFun_0[2] = RRR_arm_P.SFric3_Value * rtb_Clock +
    RRR_arm_P.DFric3_Value * RRR_arm_X.Integrator_CSTATE[5];
  for (i = 0; i < 3; i++) {
    /* Sum: '<Root>/Sum' incorporates:
     *  MATLAB Function: '<Root>/M'
     */
    rtb_q_e[i] = ((M[i + 3] * rtb_qdot[1] + M[i] * rtb_qdot[0]) + M[i + 6] *
                  rtb_degtorad3_idx_0) + ((((C[i + 6] * tmp + (C[i + 3] *
      rtb_degtorad3_idx_2 + C[i] * rtb_degtorad3_idx_1)) + (B[i + 6] * tmp_2 +
      (B[i + 3] * tmp_1 + B[i] * tmp_0))) + G[i]) +
      rtb_TmpSignalConversionAtSFun_0[i]);
  }

  /* End of MATLAB Function: '<Root>/CBGF' */

  /* MATLAB Function: '<Root>/Xdot' incorporates:
   *  Constant: '<Root>/DFric1'
   *  Constant: '<Root>/DFric2'
   *  Constant: '<Root>/DFric3'
   *  Constant: '<Root>/SFric1'
   *  Constant: '<Root>/SFric2'
   *  Constant: '<Root>/SFric3'
   *  Integrator: '<Root>/Integrator'
   */
  /* MATLAB Function 'Xdot': '<S6>:1' */
  /* '<S6>:1:45' */
  /* '<S6>:1:2' */
  /* '<S6>:1:3' */
  /* '<S6>:1:4' */
  /* '<S6>:1:5' */
  /* '<S6>:1:6' */
  /* '<S6>:1:7' */
  /* '<S6>:1:8' */
  /* '<S6>:1:9' */
  /* '<S6>:1:10' */
  /* '<S6>:1:11' */
  /* '<S6>:1:13' */
  /* '<S6>:1:14' */
  /* '<S6>:1:15' */
  /* '<S6>:1:16' */
  /* '<S6>:1:17' */
  /* '<S6>:1:18' */
  /* '<S6>:1:19' */
  /* '<S6>:1:20' */
  /* '<S6>:1:21' */
  /* '<S6>:1:22' */
  /*  -----------------------------------------------------------------%% */
  /*  c1=cos(q1); */
  /*  c2=cos(q2); */
  /*  c3=cos(q3); */
  /*  s2=sin(q2); */
  /*  s3=sin(q3); */
  /*  c12=cos(q1+q2); */
  /*  c23=cos(q2+q3); */
  /*  s23=sin(q2+q3); */
  /*  c123=cos(q1+q2+q3); */
  /* '<S6>:1:35' */
  M_0[0] = ((cos(RRR_arm_X.Integrator_CSTATE[2] + RRR_arm_X.Integrator_CSTATE[4])
             * 80.0 + 420.0 * cos(RRR_arm_X.Integrator_CSTATE[2])) + 60.0 * cos
            (RRR_arm_X.Integrator_CSTATE[4])) + 614.55;

  /* '<S6>:1:36' */
  M_0[3] = ((cos(RRR_arm_X.Integrator_CSTATE[2] + RRR_arm_X.Integrator_CSTATE[4])
             * 40.0 + 210.0 * cos(RRR_arm_X.Integrator_CSTATE[2])) + 60.0 * cos
            (RRR_arm_X.Integrator_CSTATE[4])) + 134.05;

  /* '<S6>:1:37' */
  M_0[6] = (cos(RRR_arm_X.Integrator_CSTATE[2] + RRR_arm_X.Integrator_CSTATE[4])
            * 40.0 + 30.0 * cos(RRR_arm_X.Integrator_CSTATE[4])) + 10.1;

  /* '<S6>:1:38' */
  M_0[1] = ((cos(RRR_arm_X.Integrator_CSTATE[2] + RRR_arm_X.Integrator_CSTATE[4])
             * 40.0 + 210.0 * cos(RRR_arm_X.Integrator_CSTATE[2])) + 60.0 * cos
            (RRR_arm_X.Integrator_CSTATE[4])) + 134.05;

  /* '<S6>:1:39' */
  M_0[4] = 60.0 * cos(RRR_arm_X.Integrator_CSTATE[4]) + 53620.0;

  /* '<S6>:1:40' */
  M_0[7] = 30.0 * cos(RRR_arm_X.Integrator_CSTATE[4]) + 10.1;

  /* '<S6>:1:41' */
  M_0[2] = (cos(RRR_arm_X.Integrator_CSTATE[2] + RRR_arm_X.Integrator_CSTATE[4])
            * 40.0 + 30.0 * cos(RRR_arm_X.Integrator_CSTATE[4])) + 10.1;

  /* '<S6>:1:42' */
  M_0[5] = 30.0 * cos(RRR_arm_X.Integrator_CSTATE[4]) + 10.1;

  /* '<S6>:1:43' */
  M_0[8] = 10.1;

  /* '<S6>:1:45' */
  /* '<S6>:1:46' */
  memset(&C[0], 0, 9U * sizeof(real_T));
  memset(&B[0], 0, 9U * sizeof(real_T));
  C[3] = sin(RRR_arm_X.Integrator_CSTATE[2] + RRR_arm_X.Integrator_CSTATE[4]) *
    -40.0 - 210.0 * sin(RRR_arm_X.Integrator_CSTATE[2]);

  /* '<S6>:1:47' */
  C[6] = sin(RRR_arm_X.Integrator_CSTATE[2] + RRR_arm_X.Integrator_CSTATE[4]) *
    -40.0 - 30.0 * sin(RRR_arm_X.Integrator_CSTATE[4]);

  /* '<S6>:1:48' */
  C[1] = sin(RRR_arm_X.Integrator_CSTATE[2] + RRR_arm_X.Integrator_CSTATE[4]) *
    40.0 + 210.0 * sin(RRR_arm_X.Integrator_CSTATE[2]);

  /* '<S6>:1:49' */
  C[7] = -30.0 * sin(RRR_arm_X.Integrator_CSTATE[4]);

  /* '<S6>:1:50' */
  C[2] = sin(RRR_arm_X.Integrator_CSTATE[2] + RRR_arm_X.Integrator_CSTATE[4]) *
    40.0 + 30.0 * sin(RRR_arm_X.Integrator_CSTATE[4]);

  /* '<S6>:1:51' */
  C[5] = 30.0 * sin(RRR_arm_X.Integrator_CSTATE[4]);

  /* '<S6>:1:53' */
  /* '<S6>:1:54' */
  B[0] = sin(RRR_arm_X.Integrator_CSTATE[2] + RRR_arm_X.Integrator_CSTATE[4]) *
    -80.0 - 420.0 * sin(RRR_arm_X.Integrator_CSTATE[2]);

  /* '<S6>:1:55' */
  B[3] = sin(RRR_arm_X.Integrator_CSTATE[2] + RRR_arm_X.Integrator_CSTATE[4]) *
    -80.0 - 60.0 * sin(RRR_arm_X.Integrator_CSTATE[4]);

  /* '<S6>:1:56' */
  B[6] = sin(RRR_arm_X.Integrator_CSTATE[2] + RRR_arm_X.Integrator_CSTATE[4]) *
    -80.0 - 60.0 * sin(RRR_arm_X.Integrator_CSTATE[4]);

  /* '<S6>:1:57' */
  B[4] = -60.0 * sin(RRR_arm_X.Integrator_CSTATE[4]);

  /* '<S6>:1:58' */
  B[7] = -60.0 * sin(RRR_arm_X.Integrator_CSTATE[4]);

  /* '<S6>:1:59' */
  B[2] = 60.0 * sin(RRR_arm_X.Integrator_CSTATE[4]);

  /* '<S6>:1:61' */
  /* '<S6>:1:62' */
  G_0[0] = ((cos(RRR_arm_X.Integrator_CSTATE[0] + RRR_arm_X.Integrator_CSTATE[2])
             * 3.0 / 2.0 + 4.0 * cos(RRR_arm_X.Integrator_CSTATE[0])) * 147.15 +
            ((cos((RRR_arm_X.Integrator_CSTATE[0] + RRR_arm_X.Integrator_CSTATE
                   [2]) + RRR_arm_X.Integrator_CSTATE[4]) + cos
              (RRR_arm_X.Integrator_CSTATE[0] + RRR_arm_X.Integrator_CSTATE[2]) *
              3.0) + 4.0 * cos(RRR_arm_X.Integrator_CSTATE[0])) *
            98.100000000000009) + 392.40000000000003 * cos
    (RRR_arm_X.Integrator_CSTATE[0]);

  /* '<S6>:1:63' */
  G_0[1] = (cos((RRR_arm_X.Integrator_CSTATE[0] + RRR_arm_X.Integrator_CSTATE[2])
                + RRR_arm_X.Integrator_CSTATE[4]) + cos
            (RRR_arm_X.Integrator_CSTATE[0] + RRR_arm_X.Integrator_CSTATE[2]) *
            3.0) * 98.100000000000009 + cos(RRR_arm_X.Integrator_CSTATE[0] +
    RRR_arm_X.Integrator_CSTATE[2]) * 441.45000000000005 / 2.0;

  /* '<S6>:1:64' */
  G_0[2] = cos((RRR_arm_X.Integrator_CSTATE[0] + RRR_arm_X.Integrator_CSTATE[2])
               + RRR_arm_X.Integrator_CSTATE[4]) * 98.100000000000009;

  /* '<S6>:1:66' */
  rtb_degtorad3_idx_1 = RRR_arm_X.Integrator_CSTATE[1] *
    RRR_arm_X.Integrator_CSTATE[1];
  rtb_degtorad3_idx_2 = RRR_arm_X.Integrator_CSTATE[3] *
    RRR_arm_X.Integrator_CSTATE[3];
  tmp = RRR_arm_X.Integrator_CSTATE[5] * RRR_arm_X.Integrator_CSTATE[5];
  G[0] = rtb_q_e[0];
  G[1] = rtb_q_e[1];
  G[2] = rtb_q_e[2];
  tmp_0 = RRR_arm_X.Integrator_CSTATE[1] * RRR_arm_X.Integrator_CSTATE[3];
  tmp_1 = RRR_arm_X.Integrator_CSTATE[1] * RRR_arm_X.Integrator_CSTATE[5];
  tmp_2 = RRR_arm_X.Integrator_CSTATE[3] * RRR_arm_X.Integrator_CSTATE[5];
  if (RRR_arm_X.Integrator_CSTATE[1] < 0.0) {
    rtb_Clock = -1.0;
  } else if (RRR_arm_X.Integrator_CSTATE[1] > 0.0) {
    rtb_Clock = 1.0;
  } else if (RRR_arm_X.Integrator_CSTATE[1] == 0.0) {
    rtb_Clock = 0.0;
  } else {
    rtb_Clock = RRR_arm_X.Integrator_CSTATE[1];
  }

  rtb_TmpSignalConversionAtSFun_0[0] = RRR_arm_P.SFric1_Value * rtb_Clock +
    RRR_arm_P.DFric1_Value * RRR_arm_X.Integrator_CSTATE[1];
  if (RRR_arm_X.Integrator_CSTATE[3] < 0.0) {
    rtb_Clock = -1.0;
  } else if (RRR_arm_X.Integrator_CSTATE[3] > 0.0) {
    rtb_Clock = 1.0;
  } else if (RRR_arm_X.Integrator_CSTATE[3] == 0.0) {
    rtb_Clock = 0.0;
  } else {
    rtb_Clock = RRR_arm_X.Integrator_CSTATE[3];
  }

  rtb_TmpSignalConversionAtSFun_0[1] = RRR_arm_P.SFric2_Value * rtb_Clock +
    RRR_arm_P.DFric2_Value * RRR_arm_X.Integrator_CSTATE[3];
  if (RRR_arm_X.Integrator_CSTATE[5] < 0.0) {
    rtb_Clock = -1.0;
  } else if (RRR_arm_X.Integrator_CSTATE[5] > 0.0) {
    rtb_Clock = 1.0;
  } else if (RRR_arm_X.Integrator_CSTATE[5] == 0.0) {
    rtb_Clock = 0.0;
  } else {
    rtb_Clock = RRR_arm_X.Integrator_CSTATE[5];
  }

  rtb_TmpSignalConversionAtSFun_0[2] = RRR_arm_P.SFric3_Value * rtb_Clock +
    RRR_arm_P.DFric3_Value * RRR_arm_X.Integrator_CSTATE[5];
  for (i = 0; i < 3; i++) {
    rtb_qdot[i] = (((G[i] - (C[i + 6] * tmp + (C[i + 3] * rtb_degtorad3_idx_2 +
      C[i] * rtb_degtorad3_idx_1))) - ((B[i + 3] * tmp_1 + B[i] * tmp_0) + B[i +
      6] * tmp_2)) - G_0[i]) - rtb_TmpSignalConversionAtSFun_0[i];
  }

  i = 0;
  r2 = 1;
  r3 = 2;
  rtb_degtorad3_idx_2 = fabs(M_0[0]);
  rtb_Clock = fabs(M_0[1]);
  if (rtb_Clock > rtb_degtorad3_idx_2) {
    rtb_degtorad3_idx_2 = rtb_Clock;
    i = 1;
    r2 = 0;
  }

  if (fabs(M_0[2]) > rtb_degtorad3_idx_2) {
    i = 2;
    r2 = 1;
    r3 = 0;
  }

  M_0[r2] /= M_0[i];
  M_0[r3] /= M_0[i];
  M_0[3 + r2] -= M_0[3 + i] * M_0[r2];
  M_0[3 + r3] -= M_0[3 + i] * M_0[r3];
  M_0[6 + r2] -= M_0[6 + i] * M_0[r2];
  M_0[6 + r3] -= M_0[6 + i] * M_0[r3];
  if (fabs(M_0[3 + r3]) > fabs(M_0[3 + r2])) {
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }

  M_0[3 + r3] /= M_0[3 + r2];
  M_0[6 + r3] -= M_0[3 + r3] * M_0[6 + r2];
  G_0[1] = rtb_qdot[r2] - rtb_qdot[i] * M_0[r2];
  G_0[2] = (rtb_qdot[r3] - rtb_qdot[i] * M_0[r3]) - M_0[3 + r3] * G_0[1];
  G_0[2] /= M_0[6 + r3];
  G_0[0] = rtb_qdot[i] - M_0[6 + i] * G_0[2];
  G_0[1] -= M_0[6 + r2] * G_0[2];
  G_0[1] /= M_0[3 + r2];
  G_0[0] -= M_0[3 + i] * G_0[1];
  G_0[0] /= M_0[i];

  /* '<S6>:1:68' */
  /* '<S6>:1:69' */
  RRR_arm_B.Xd[0] = RRR_arm_X.Integrator_CSTATE[1];

  /* '<S6>:1:70' */
  RRR_arm_B.Xd[1] = G_0[0];

  /* '<S6>:1:71' */
  RRR_arm_B.Xd[2] = RRR_arm_X.Integrator_CSTATE[3];

  /* '<S6>:1:72' */
  RRR_arm_B.Xd[3] = G_0[1];

  /* '<S6>:1:73' */
  RRR_arm_B.Xd[4] = RRR_arm_X.Integrator_CSTATE[5];

  /* '<S6>:1:74' */
  RRR_arm_B.Xd[5] = G_0[2];

  /* End of MATLAB Function: '<Root>/Xdot' */

  /* Gain: '<Root>/rad to deg3' incorporates:
   *  MATLAB Function: '<Root>/Xd to qdd'
   */
  /* MATLAB Function 'Xd to qdd': '<S5>:1' */
  /* '<S5>:1:2' */
  /* '<S5>:1:3' */
  /* '<S5>:1:4' */
  RRR_arm_B.radtodeg3[0] = RRR_arm_P.radtodeg3_Gain * RRR_arm_B.Xd[1];
  RRR_arm_B.radtodeg3[1] = RRR_arm_P.radtodeg3_Gain * RRR_arm_B.Xd[3];
  RRR_arm_B.radtodeg3[2] = RRR_arm_P.radtodeg3_Gain * RRR_arm_B.Xd[5];
  if (rtmIsMajorTimeStep(RRR_arm_M)) {
  }

  if (rtmIsMajorTimeStep(RRR_arm_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(RRR_arm_M->rtwLogInfo, (RRR_arm_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(RRR_arm_M)) {
    /* Update for Integrator: '<Root>/Integrator' */
    RRR_arm_DW.Integrator_IWORK = 0;
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(RRR_arm_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(RRR_arm_M)!=-1) &&
          !((rtmGetTFinal(RRR_arm_M)-(((RRR_arm_M->Timing.clockTick1+
               RRR_arm_M->Timing.clockTickH1* 4294967296.0)) * 0.1)) >
            (((RRR_arm_M->Timing.clockTick1+RRR_arm_M->Timing.clockTickH1*
               4294967296.0)) * 0.1) * (DBL_EPSILON))) {
        rtmSetErrorStatus(RRR_arm_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&RRR_arm_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++RRR_arm_M->Timing.clockTick0)) {
      ++RRR_arm_M->Timing.clockTickH0;
    }

    RRR_arm_M->Timing.t[0] = rtsiGetSolverStopTime(&RRR_arm_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.1s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.1, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      RRR_arm_M->Timing.clockTick1++;
      if (!RRR_arm_M->Timing.clockTick1) {
        RRR_arm_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void RRR_arm_derivatives(void)
{
  int32_T i;
  XDot_RRR_arm_T *_rtXdot;
  _rtXdot = ((XDot_RRR_arm_T *) RRR_arm_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  for (i = 0; i < 6; i++) {
    _rtXdot->Integrator_CSTATE[i] = RRR_arm_B.Xd[i];
  }

  /* End of Derivatives for Integrator: '<Root>/Integrator' */
}

/* Model initialize function */
void RRR_arm_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)RRR_arm_M, 0,
                sizeof(RT_MODEL_RRR_arm_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&RRR_arm_M->solverInfo, &RRR_arm_M->Timing.simTimeStep);
    rtsiSetTPtr(&RRR_arm_M->solverInfo, &rtmGetTPtr(RRR_arm_M));
    rtsiSetStepSizePtr(&RRR_arm_M->solverInfo, &RRR_arm_M->Timing.stepSize0);
    rtsiSetdXPtr(&RRR_arm_M->solverInfo, &RRR_arm_M->derivs);
    rtsiSetContStatesPtr(&RRR_arm_M->solverInfo, (real_T **)
                         &RRR_arm_M->contStates);
    rtsiSetNumContStatesPtr(&RRR_arm_M->solverInfo,
      &RRR_arm_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&RRR_arm_M->solverInfo,
      &RRR_arm_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&RRR_arm_M->solverInfo,
      &RRR_arm_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&RRR_arm_M->solverInfo,
      &RRR_arm_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&RRR_arm_M->solverInfo, (&rtmGetErrorStatus(RRR_arm_M)));
    rtsiSetRTModelPtr(&RRR_arm_M->solverInfo, RRR_arm_M);
  }

  rtsiSetSimTimeStep(&RRR_arm_M->solverInfo, MAJOR_TIME_STEP);
  RRR_arm_M->intgData.y = RRR_arm_M->odeY;
  RRR_arm_M->intgData.f[0] = RRR_arm_M->odeF[0];
  RRR_arm_M->intgData.f[1] = RRR_arm_M->odeF[1];
  RRR_arm_M->intgData.f[2] = RRR_arm_M->odeF[2];
  RRR_arm_M->contStates = ((X_RRR_arm_T *) &RRR_arm_X);
  rtsiSetSolverData(&RRR_arm_M->solverInfo, (void *)&RRR_arm_M->intgData);
  rtsiSetSolverName(&RRR_arm_M->solverInfo,"ode3");
  rtmSetTPtr(RRR_arm_M, &RRR_arm_M->Timing.tArray[0]);
  rtmSetTFinal(RRR_arm_M, 10.0);
  RRR_arm_M->Timing.stepSize0 = 0.1;
  rtmSetFirstInitCond(RRR_arm_M, 1);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    RRR_arm_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(RRR_arm_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(RRR_arm_M->rtwLogInfo, (NULL));
    rtliSetLogT(RRR_arm_M->rtwLogInfo, "tout");
    rtliSetLogX(RRR_arm_M->rtwLogInfo, "");
    rtliSetLogXFinal(RRR_arm_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(RRR_arm_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(RRR_arm_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(RRR_arm_M->rtwLogInfo, 0);
    rtliSetLogDecimation(RRR_arm_M->rtwLogInfo, 1);
    rtliSetLogY(RRR_arm_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(RRR_arm_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(RRR_arm_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &RRR_arm_B), 0,
                sizeof(B_RRR_arm_T));

  /* states (continuous) */
  {
    (void) memset((void *)&RRR_arm_X, 0,
                  sizeof(X_RRR_arm_T));
  }

  /* states (dwork) */
  (void) memset((void *)&RRR_arm_DW, 0,
                sizeof(DW_RRR_arm_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(RRR_arm_M->rtwLogInfo, 0.0, rtmGetTFinal
    (RRR_arm_M), RRR_arm_M->Timing.stepSize0, (&rtmGetErrorStatus(RRR_arm_M)));

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  if (rtmIsFirstInitCond(RRR_arm_M)) {
    RRR_arm_X.Integrator_CSTATE[0] = 0.0;
    RRR_arm_X.Integrator_CSTATE[1] = 0.0;
    RRR_arm_X.Integrator_CSTATE[2] = 0.0;
    RRR_arm_X.Integrator_CSTATE[3] = 0.0;
    RRR_arm_X.Integrator_CSTATE[4] = 0.0;
    RRR_arm_X.Integrator_CSTATE[5] = 0.0;
  }

  RRR_arm_DW.Integrator_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<Root>/Integrator' */

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(RRR_arm_M)) {
    rtmSetFirstInitCond(RRR_arm_M, 0);
  }
}

/* Model terminate function */
void RRR_arm_terminate(void)
{
  /* (no terminate code required) */
}
