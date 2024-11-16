# include <stdarg.h>






// includes the following methods:
// va_start(va_list ap, argN): enables access to variadic function arguments
//  va_list will be the pointer to the last fixed argument in the variadic function
//  argN is the last fixed argument in the variadic function

// va_arg(va_list ap, type): accesses the next variadic function argument
//  va_list points to argN
//  type indicates the data type the va_list ap should expect

// va_copy(va_list dest, va_list src): makes a copy of the variadic function arguments

// va_end(va_list ap) ends the traversal of the variadic function arguments

// va_list holds the information needed by va_start va_arg va_end va_copy