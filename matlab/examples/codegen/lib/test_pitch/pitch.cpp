/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pitch.cpp
 *
 * Code generation for function 'pitch'
 *
 */

/* Include files */
#include "pitch.h"
#include "LHS.h"
#include "SRH.h"
#include "movmedian.h"
#include "rt_nonfinite.h"
#include "test_pitch.h"
#include <cstring>

/* Function Declarations */
static void b_stepMethod(const double x[2048], double f0[17]);
static void stepMethod(const double x[2048], double f0[17]);

/* Function Definitions */
static void b_stepMethod(const double x[2048], double f0[17])
{
  static double y[9600];
  int hop;
  int i;
  int u0;
  double d;
  int loop_ub;
  std::memset(&y[0], 0, 9600U * sizeof(double));
  for (hop = 0; hop < 48; hop++) {
    i = 40 * hop;
    u0 = 40 * hop + 200;
    if (u0 >= 2048) {
      u0 = 2048;
    }

    if (i + 1 > u0) {
      i = 0;
      u0 = -1;
    } else {
      u0--;
    }

    loop_ub = u0 - i;
    for (u0 = 0; u0 <= loop_ub; u0++) {
      y[u0 + 200 * hop] = x[i + u0];
    }
  }

  SRH(y, f0);
  for (u0 = 0; u0 < 17; u0++) {
    d = f0[u0];
    if (f0[u0] < 50.0) {
      d = 50.0;
      f0[u0] = 50.0;
    }

    if (d > 400.0) {
      f0[u0] = 400.0;
    }
  }
}

static void stepMethod(const double x[2048], double f0[17])
{
  double y[4080];
  int hop;
  int i;
  int u0;
  double d;
  int loop_ub;
  std::memset(&y[0], 0, 4080U * sizeof(double));
  for (hop = 0; hop < 17; hop++) {
    i = 120 * hop;
    u0 = 120 * hop + 240;
    if (u0 >= 2048) {
      u0 = 2048;
    }

    if (i + 1 > u0) {
      i = 0;
      u0 = -1;
    } else {
      u0--;
    }

    loop_ub = u0 - i;
    for (u0 = 0; u0 <= loop_ub; u0++) {
      y[u0 + 240 * hop] = x[i + u0];
    }
  }

  LHS(y, f0);
  for (u0 = 0; u0 < 17; u0++) {
    d = f0[u0];
    if (f0[u0] < 50.0) {
      d = 50.0;
      f0[u0] = 50.0;
    }

    if (d > 400.0) {
      f0[u0] = 400.0;
    }
  }
}

void b_pitch(const double x[2048], double f0[16])
{
  double dv[17];
  double b_f0[17];
  b_stepMethod(x, dv);
  movmedian(dv, b_f0);
  std::memcpy(&f0[0], &b_f0[0], 16U * sizeof(double));
}

void pitch(const double x[2048], double f0[16])
{
  double dv[17];
  double b_f0[17];
  stepMethod(x, dv);
  movmedian(dv, b_f0);
  std::memcpy(&f0[0], &b_f0[0], 16U * sizeof(double));
}

/* End of code generation (pitch.cpp) */
