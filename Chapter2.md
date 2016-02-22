---
Class  : Systems Programming
Date   : 01/31/2016
Author : Enes Kemal Ergin
Subject: Chapter 2 - Bits, Bytes, and Data Types
---


## Bit Models

Learning bit models will give us an understanding of how does computer store float and integer numbers differently, or how does computer store precision of double and float.

__Small Definitions:__

  - Bit: Binary digit, there are two possible; 0 and 1 (False, True)
  - Byte: 8 Bits called together byte. (00010011 binary representation of 19)
  - Nibble: 4 bits called together is nibble.
  -


Everything in computation based on combinations of bits. When the bits come together we have to interpret them to get something meaningful and useful out of it. Several methods of interpreting is available and they are collectively called _bit models_.

### 1. Magnitude-only Bit Model

- Simplest bit model for all nonnegative whole numbers.
- Each bit represents a nonnegative integer power of 2.

```C
00010011 // 19
```
- Given 8 bits is possible to store whole number in value up to 255 (Comes from 2^8-1).
- Range of 0 to 255.
- Bits with lowest power of 2 (right most side) called __least significant bits__.
- Bits with highest power of 2 (left most side) called __most significant bits__.
- Binary addition is the same idea of decimal (base 10) addition.

> 32-bit architecture can have maximum 4 GB memory.

### 2. Sign-magnitude Bit Model

- Most significant bit allocated to be sign bit.
- If most significant bit is 0 positive number
- If most significant bit is 1 negative number

```C
10010011 // -19
```
- Given 8 bits is possible to store whole numbers in range -127 to 127
- There are two drawbacks of this model:
  - Two possible 0 representation "00000000" and "10000000"
  - Binary addition is terribly complicated.
- Because of drawbacks C does not use Sign-magnitude bit model.

### 3. Two's Complement Bit Model

This model comes up to overcome Sign-magnitude's drawbacks.

- Positive integers and 0 are represented exactly same as the Magnitude-only model.
- To get the negative numbers however, you have to follow this procedure:
    1. Write the bits for the possible version of the number
    2. Invert(flip) all the bits
    3. Add 1

```C
00000111  // positive value +7
11111000  // invert all the bits
11111001  // add 1

// Now you have the negative 7 in two's complement bit model.
```

- When two's complement number has 1 in the highest bit, that means number is negative:

```C
11111001 // unknown value -? (Unknown because knowing negative by looking is not easy)
00000110 // invert all bits
00000111 // add 1
         // We interpret and see the number at the and is 7
         // So the number at the very beginning is -7 then.
```

- Only pattern 0 is "00000000"
- in two's complement bit model range of 8 bits is -128 to +127

### 4. Floating Point Bit Model

- Storing real numbers is completely different task, some bits will represent fractional portion.
- One possible way to use some bits to denote powers of 2 that are negative. in 1 byte:

```C
1   0   0   1   0   0    1    1    // Example bit value
2^4 2^3 2^2 2^1 2^0 2^-1 2^-2 2^-3 // place value
16  8   4   2   1   0.5  0.25 0.125 // Place value (base10)

```

This approach is called a _fixed point_ bit model. This usage is usually considered as poor usage of bits so not very much common...

There is another representation using _floating-point_ bit model. The general idea is to represent the number using scientific notation.

```C
123.456 = 1.23456 × 10^2 // In base 10

18.375 (base 10) = 10010.011 (base 2) = 1.0010011× 2^4
```

- floating point bit model stores numbers in the following form: ``` ±(1*f) * (2**e)```
- The values that must be stored: (For given 4byte - 32bits)
  - Sign > 1bit
  - Fraction (f) > 23bits
  - Exponent (e) >  8bits
  - Bit places:
    - 31st place for Sign bit
    - 30 - 23 for Exponent
    - 22 - 0  for Fraction


The following steps can be used to convert a number from base 10 to binary using the floating point bit model:
  1. Write the sign bit.
  2. Write the number in fixed point binary, without the sign.
  3. Normalize, moving the radix (the decimal point) to just after the first “1” digit.
  4. Take f as the values to the right of the radix, zero padded.
  5. Take e as the given exponent, biased by adding +127.

The value −118.625 demonstrations:

```C
1 // is the sign bit
118.625 = 1110110.101 // Writing the number in fixed point binary
1110110.101 = 1.110110101 * 2**6 // Normalize
110 1101 0100 0000 0000 0000 // Get fraction from right of radix
e = 6+127 = 133 = 1000 0101  // Get exponent, biased +127

```
> double still uses 1 bit for sign, but it uses 11 bits to store the exponent and 52 bits to store the fraction

### 5.ASCII and UNICODE Bit Models

For representing nonnumeric data we use different type of bit model; ASCII or UNICODE

__ASCII__:

- 128 Bit patterns (128 characters)
- 7 Bit is used to represent a patterns and filled 8th as non used one.
- Most of the bit patterns are printable characters
- In C, ```char``` and ```unsigned char``` used ASCII bit model.
- Dual interpretation ?

__UNICODE__:

- 65,536 bit patterns (65,536 characters)
- 16 bit is used to represent the patterns
- In C, ```short int``` is commonly used to represent them.
- Firs 128 bit patterns are the same as ASCII
- 
