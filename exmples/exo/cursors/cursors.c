#include "cursors.h"

#include <stdio.h>
#include <stdlib.h>

// gemv(
//     M : size,
//     N : size,
//     A : f32[M, N] @DRAM,
//     x : f32[N] @DRAM,
//     y : f32[M] @DRAM
// )
void gemv( void *ctxt, int_fast32_t M, int_fast32_t N, const float* A, const float* x, float* y ) {
EXO_ASSUME(M % 8 == 0);
EXO_ASSUME(N % 8 == 0);
for (int_fast32_t io = 0; io < ((M) / (8)); io++) {
  for (int_fast32_t jo = 0; jo < ((N) / (8)); jo++) {
    for (int_fast32_t ii = 0; ii < 8; ii++) {
      for (int_fast32_t ji = 0; ji < 8; ji++) {
        y[8 * io + ii] += A[(8 * io + ii) * N + 8 * jo + ji] * x[8 * jo + ji];
      }
    }
  }
}
}

