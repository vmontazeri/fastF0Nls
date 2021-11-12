/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * levinson.h
 *
 * Code generation for function 'levinson'
 *
 */

#ifndef LEVINSON_H
#define LEVINSON_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "test_pitch_types.h"

/* Function Declarations */
extern void levinson(const creal_T R_in[12], creal_T A_out[12]);

#endif

/* End of code generation (levinson.h) */
