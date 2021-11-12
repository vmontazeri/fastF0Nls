/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SortedBuffer.h
 *
 * Code generation for function 'SortedBuffer'
 *
 */

#ifndef SORTEDBUFFER_H
#define SORTEDBUFFER_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "test_pitch_types.h"

/* Function Declarations */
extern void SortedBuffer_insert(coder_internal_SortedBuffer *obj, double x);
extern int SortedBuffer_locateElement(const double obj_buf[5], int obj_nbuf,
  double x);
extern void SortedBuffer_remove(coder_internal_SortedBuffer *obj, double x);

#endif

/* End of code generation (SortedBuffer.h) */
