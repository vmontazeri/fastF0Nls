/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * test_pitch.cpp
 *
 * Code generation for function 'test_pitch'
 *
 */

/* Include files */
#include "test_pitch.h"
#include "pitch.h"
#include "randn.h"
#include "rt_nonfinite.h"
#include "test_pitch_data.h"
#include "test_pitch_initialize.h"

/* Function Definitions */
void test_pitch(double f0_LHS[16], double f0_SRH[16])
{
  double x[2048];
  if (isInitialized_test_pitch == false) {
    test_pitch_initialize();
  }

  /*  [x,fs] = audioread('roy_noisy.wav'); */
  randn(x);

  /*  tic */
  pitch(x, f0_LHS);

  /*  toc */
  /*  tic */
  b_pitch(x, f0_SRH);

  /*  toc */
  /*  tf0 = idx/fs; */
  /*   */
  /*  figure(1) */
  /*   */
  /*  stem(tf0,f0_LHS) */
  /*  hold on */
  /*  stem(tf0,f0_SRH, 'r') */
  /*  xlabel('Time (s)') */
  /*  ylabel('Pitch (Hz)') */
  /*  title('Pitch Estimations') */
  /*  axis tight */
}

/* End of code generation (test_pitch.cpp) */
