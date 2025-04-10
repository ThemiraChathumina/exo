#include "quiz1.h"

#include <stdio.h>
#include <stdlib.h>

// vec_double(
//     N : size,
//     inp : f32[N] @DRAM,
//     out : f32[N] @DRAM
// )
void vec_double( void *ctxt, int_fast32_t N, const float* inp, float* out ) {
EXO_ASSUME(N % 8 == 0);
for (int_fast32_t i = 0; i < N; i++) {
  out[i] = 2.0f * inp[i];
}
}

// vec_double_optimized(
//     N : size,
//     inp : f32[N] @DRAM,
//     out : f32[N] @DRAM
// )
void vec_double_optimized( void *ctxt, int_fast32_t N, const float* inp, float* out ) {
EXO_ASSUME(N % 8 == 0);
float *two_vec = (float*) malloc(8 * sizeof(*two_vec));
for (int_fast32_t ii = 0; ii < 8; ii++) {
  two_vec[ii] = 2.0f;
}
for (int_fast32_t io = 0; io < ((N) / (8)); io++) {
  float *out_vec = (float*) malloc(8 * sizeof(*out_vec));
  float *inp_vec = (float*) malloc(8 * sizeof(*inp_vec));
  for (int_fast32_t i0 = 0; i0 < 8; i0++) {
    inp_vec[i0] = inp[i0 + 8 * io];
  }
  for (int_fast32_t ii = 0; ii < 8; ii++) {
    out_vec[ii] = two_vec[ii] * inp_vec[ii];
  }
  free(inp_vec);
  for (int_fast32_t i0 = 0; i0 < 8; i0++) {
    out[i0 + 8 * io] = out_vec[i0];
  }
  free(out_vec);
}
free(two_vec);
}

