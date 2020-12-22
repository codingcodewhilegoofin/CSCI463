

// Preprocessor directives to define this file ONCE
#ifndef  hex_H
#define  hex_H

// Appropriate libraries
#include  <string>
#include  <stdint.h>

std::string  hex8(uint8_t i); 
std::string  hex32(uint32_t i);
std::string  hex0x32(uint32_t i);

#endif
