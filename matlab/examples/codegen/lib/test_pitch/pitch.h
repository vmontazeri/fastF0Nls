/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pitch.h
 *
 * Code generation for function 'pitch'
 *
 */

#ifndef PITCH_H
#define PITCH_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "test_pitch_types.h"

/* Function Declarations */
extern void b_pitch(const double x[2048], double f0[16]);
extern void pitch(const double x[2048], double f0[16]);

#endif

/* End of code generation (pitch.h) */
