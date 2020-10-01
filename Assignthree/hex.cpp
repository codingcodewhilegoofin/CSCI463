 //***********************************************************************************
 //*
 //* 	prog3.cpp
 //*	CSCI 463 Assignment 3 
 //*
 //* 	Giovanni Moscato Z1820207
 //*
 //*	Bitwise Operators & IEEE-754 Floating point number decoding
 //* 	Instructor: John Winans
 //* 	Section: -0001
 //***********************************************************************************

// Include STL libraries  
#include <iostream>
#include "hex.h"
#include <iomanip>
#include <sstream>


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

std::string hex32(uint32_t i)
{
   
	std::ostringstream os;

	os << std::hex << std::setfill('0') << std::setw(8) << static_cast<uint32_t>(i);

	return os.str();
}

std::string hex0x32(uint32_t i)
{

    std::ostringstream os;

    os << "0x" << std::hex << std::setfill('0') << std::setw(8)  << static_cast<uint32_t>(i);

    return os.str();
}