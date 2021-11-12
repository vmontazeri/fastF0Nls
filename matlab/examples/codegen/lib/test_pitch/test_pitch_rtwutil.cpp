/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * test_pitch_rtwutil.cpp
 *
 * Code generation for function 'test_pitch_rtwutil'
 *
 */

/* Include files */
#include "test_pitch_rtwutil.h"
#include "rt_nonfinite.h"
#include "test_pitch.h"
#include <cmath>

/* Variable Definitions */
static test_pitchTLS *test_pitchTLSGlobal;

#pragma omp threadprivate (test_pitchTLSGlobal)

/* Function Definitions */
void emlrtFreeThreadStackData()
{
  int i;

#pragma omp parallel for schedule(static)\
 num_threads(omp_get_max_threads())

  for (i = 1; i <= omp_get_max_threads(); i++) {
    free(test_pitchTLSGlobal);
  }
}

test_pitchTLS *emlrtGetThreadStackData()
{
  return test_pitchTLSGlobal;
}

void emlrtInitThreadStackData()
{
  int i;

#pragma omp parallel for schedule(static)\
 num_threads(omp_get_max_threads())

  for (i = 1; i <= omp_get_max_threads(); i++) {
    test_pitchTLSGlobal = (test_pitchTLS *)malloc((size_t)1U * sizeof
      (test_pitchTLS));
  }
}

double rt_hypotd_snf(double u0, double u1)
{
  double y;
  double a;
  a = std::abs(u0);
  y = std::abs(u1);
  if (a < y) {
    a /= y;
    y *= std::sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = a * std::sqrt(y * y + 1.0);
  } else {
    if (!rtIsNaN(y)) {
      y = a * 1.4142135623730951;
    }
  }

  return y;
}

/* End of code generation (test_pitch_rtwutil.cpp) */
