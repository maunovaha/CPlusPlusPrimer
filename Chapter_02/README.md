# Chapter 2

> This chapter covers the built-in types and begins our coverage of how C++ supports more complicated types.

## Exercise 2.1

> **_a)_** What are the differences between *int*, *long*, *long long*, and *short*? **_b)_** Between an unsigned and signed type? **_c)_** Between a *float* and a *double*?

**_a)_** The main difference is that they can be used to store integer values of (potentially) different sizes. The language guarantees that an *int* will be at least as large as *short*, a *long* at least as large as an *int*, and *long long* at least as large as *long*. The size of - that is, the number of bits in - the arithmetic types varies across machines.

**_b)_** A signed type represent negative or positive numbers (including zero); an unsigned type represents only values greater than or equal to zero. Hence, when negative value is assigned to unsigned type this may cause nasty bugs as the negative value is automatically converted to unsigned type. Consequently, as a programmer, it is your job to take care of not mixing signed and unsigned types when doing the calculations.

**_c)_** The main difference is that *double* has 2x the precision of *float*. And as a best practice, we should use *double* for floating-point computations; *float* usually does not have enough precision, and the cost of double-precision calculations versus single-precision is negligible. In fact, on some machines, double-precision operations are faster than single. The precision offered by *long double* usually is unnecessary and often entails considerable run-time cost. All things considered, *double* is much better for "every-day" use.