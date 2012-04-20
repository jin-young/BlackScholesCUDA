#ifndef _gaussian_h
#define _gaussian_h
/**
 * These objects and functions help us transform uniformly distributed
 * random numbers (which come from the system's random number
 * generator or from the Mersenne Twister generator) into random
 * numbers from a Gaussian ("bell curve") distribution.  
 * 
 * @note YOU DON'T NEED TO UNDERSTAND THE MATH IN ORDER TO DO THE
 * ASSIGNMENT!  (You are, however, encouraged to learn the math.)
 */
#include "util.h"

/**
 * Current state of the Gaussian random number generator.
 */
#ifndef __gaussrand_state_t
#define __gaussrand_state_t
typedef struct __gaussrand_state_t {
  double V1, V2, S;
  int phase;
} gaussrand_state_t;
#endif


/**
 * Initialize the gaussrand_state_t object.  Call this before giving
 * "state" to gaussrand().
 */
void
init_gaussrand_state (gaussrand_state_t* state);

/**
 * Return a double-precision Gaussian random number, which is computed
 * using the given uniform random number generator f.  Here, f takes
 * no input (which means that it has internal state; therefore, this
 * function is not thread-safe!).
 *
 * @note THIS FUNCTION IS NOT THREAD-SAFE because the input function f
 *       must modify some internal state.
 * 
 * @param f [IN] A random number generating "function" which takes no
 *               inputs and returns a double as an output.
 * @param state [IN/OUT] Current state of the Gaussian generator; 
 *                       modified by this function.
 * 
 * @return A random number from the Gaussian distribution.
 */
double 
gaussrand (const double_generator_no_input_t f, 
	   gaussrand_state_t* state);

/**
 * Same as gausrand(), except that here f (the uniform random number
 * generating "function") takes a "state" input (which is read and
 * then modified by f).
 *
 * @note This function CAN be thread-safe, provided that f's "state"
 * input is modified only by one thread (at a time).  This is
 * guaranteed if f_state is local to the calling thread.
 * 
 * @param f [IN] A random number generating "function" which takes one
 *               input (a void*) and returns a double as an output.
 * @param f_state [IN/OUT] Current state of f (the uniform random number
 *                         generator); modified by f.
 * @param state [IN/OUT] Current state of the Gaussian generator; 
 *                       modified by this function.
 * 
 * @return A random number from the Gaussian distribution.
 */
double
gaussrand1 (const double_generator_one_input_t f,
	    void* f_state,
	    gaussrand_state_t* gaussrand_state);


#endif /* _gaussian_h */
