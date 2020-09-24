
// Preprocessor directives to define this file ONCE
#ifndef  hex_H
#define  hex_H

// Appropriate libraries
#include  <string >
#include  <stdint.h>

//Declaring 3 seperate strings each with different sizes.
//These are all UNSIGNED integers converted to its hex equivalent for 
// 8 , 32 , and 0x32 format
std:: string  hex8(uint8_t i);
std:: string  hex32(uint32_t i);
std:: string  hex0x32(uint32_t i);

#endif