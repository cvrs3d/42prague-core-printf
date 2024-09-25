# Custom printf Function

## Overview

This custom `printf` function focuses on handling seven types of conversions, similar to the C standard library's `printf`.

### Supported Conversion Types

- **%c**  
- **%s**  
- **%p**  
- **%d**, **%i**  
- **%u**  
- **%x**, **%X**

### Supported Flags

Seven optional flags are supported and mimic their behavior according to C documentation:

1. `-`  
2. (space)  
3. `+`  
4. `0`  
5. `*`  
6. `#`  
7. `.`

For detailed information on flag behavior, refer to the C documentation:  
[https://devdocs.io/c/io/fprintf](https://devdocs.io/c/io/fprintf)

For handling input errors during compile time, see:  
[https://gcc.gnu.org/onlinedocs/gcc-14.2.0/gcc/Common-Function-Attributes.html](https://gcc.gnu.org/onlinedocs/gcc-14.2.0/gcc/Common-Function-Attributes.html)

## Description

This implementation of `printf` supports using all flags with all possible conversion types, following C's guidelines. For instance, the `0` flag cannot be used with the `%s` conversion in the real `printf`; otherwise, the behavior is undefined.

### Notable Differences

- **Buffer Management**: Unlike standard `printf`, this implementation does not manage output via a buffer. Instead, it outputs line by line, though memory is still allocated for a configuration packet.
  
### Return Values

- **Success**: Returns the number of bytes written (`n > 0`).
- **Error**: Returns `-1` if an error occurs.



