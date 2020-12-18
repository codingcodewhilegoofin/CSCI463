 //***********************************************************************************
 //*
 //* 	hex.cpp
 //*	CSCI 463 Assignment 4 
 //*
 //* 	Giovanni Moscato Z1820207
 //*
 //*	Memory Simulator
 //* 	Instructor: John Winans
 //* 	Section: -0001
 //*
 //***********************************************************************************


// Include STL libraries  
#include <iostream>
#include "hex.h"
#include <iomanip>
#include <sstream>


/**
 * Hex function definition : hex8()
 *  
 * This function will return a std::string with exactly 2 hex digits 
 * representing the 8 bits of the i argument.
 * 
 *
 * @param i unsigned 8 bit integer  
 * 
 * @return string  
 *
 * @note none
 *
 * @warning none 
 *
 * @bug none
 ********************************************************************************/
std::string hex8(uint8_t i)
{
    
    //Outstring object 
    std::ostringstream os;
    
    //Put the value of i into object, converting it from an unsigned int
    // to hexidecimal with 2 places
    os << std::hex << std::setfill('0') << std::setw(2) << static_cast<uint16_t>(i);

    // Return object using method str() to display hex value
    return os.str();
    
}


/**
 * Hex function definition : hex32()
 *  
 * This function will return a std::string with 8 hex digits 
 * representing the 32 bits of the i argument.
 * 
 *
 * @param i unsigned 32 bit integer  
 * 
 * @return string  
 *
 * @note none
 *
 * @warning none 
 *
 * @bug none
 ********************************************************************************/
std::string hex32(uint32_t i)
{
   
	std::ostringstream os;

	os << std::hex << std::setfill('0') << std::setw(8) << static_cast<uint32_t>(i);

	return os.str();
}


/**
 * Hex function definition : hex0x32()
 *  
 * This function will return a std::string beginning with 0x, followed by the 8 hex  
 * digits representing the 32 bits of the i argument. Concatenated wit a 
 * 0x to represent the proper hexidecimal representation.
 * 
 *
 * @param i unsigned 32 bit integer  
 * 
 * @return string  
 *
 * @note none
 *
 * @warning none 
 *
 * @bug none
 ********************************************************************************/
std::string hex0x32(uint32_t i)
{

    std::ostringstream os;

    os << "0x" << std::hex << std::setfill('0') << std::setw(8)  << static_cast<uint32_t>(i);

    return os.str();
}