# Custom printf function 

## Difference

My custom function focuses on 7 types of conversions (%)
They are:
	1.%c
 	2.%s
  	3.%p
   	4.%d, i
    	5.%u
     	6.%x, X
Also it has support for 7 optional flags
They are:
	1. -
 	2. <space>
  	3. +
   	4. 0
    	5. *
     	6. #
      	7. '.'
They are all implemented (mimic-ed) accordingly to C documentation
Visit: https://devdocs.io/c/io/fprintf
See also: https://gcc.gnu.org/onlinedocs/gcc-14.2.0/gcc/Common-Function-Attributes.html, To understand how possible input errors are handled during compile time.

## Description

My printf tries to provide support for all given flags to be used with all possible convertion types.
For example 0 flag cannot be specified with %s in real printf, otherwise behavior is undefined.
Also my printf is not working with buffer management, but ouputs line by line, still though allocates
memory for config packet.

Return values:  It returns int n, where n > 0 is number of bytes written and n == -1 means error.


