
#pragma once
#ifndef CURSORS_H
#define CURSORS_H

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include <stdbool.h>

// Compiler feature macros adapted from Hedley (public domain)
// https://github.com/nemequ/hedley

#if defined(__has_builtin)
#  define EXO_HAS_BUILTIN(builtin) __has_builtin(builtin)
#else
#  define EXO_HAS_BUILTIN(builtin) (0)
#endif

#if EXO_HAS_BUILTIN(__builtin_assume)
#  define EXO_ASSUME(expr) __builtin_assume(expr)
#elif EXO_HAS_BUILTIN(__builtin_unreachable)
#  define EXO_ASSUME(expr) \
      ((void)((expr) ? 1 : (__builtin_unreachable(), 1)))
#else
#  define EXO_ASSUME(expr) ((void)(expr))
#endif



// gemv(
//     M : size,
//     N : size,
//     A : f32[M, N] @DRAM,
//     x : f32[N] @DRAM,
//     y : f32[M] @DRAM
// )
void gemv( void *ctxt, int_fast32_t M, int_fast32_t N, const float* A, const float* x, float* y );



#ifdef __cplusplus
}
#endif
#endif  // CURSORS_H
