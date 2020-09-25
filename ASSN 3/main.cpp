 //***********************************************************************************
 //*
 //* 	prog3.cpp
 //*	CSCI 463 Assignment 3 
 //*
 //* 	Giovanni Moscato Z1820207
 //*
 //*	Memory Simulator
 //* 	Instructor: John Winans
 //* 	Section: -0001
 //*
 //*    Cited Sources: http://courses.cms.caltech.edu/cs11/material/general/usage.html
 //***********************************************************************************

// Include STL libraries  
#include <iostream>
#include "memory.h"
#include "hex.h"


/* CSCI 463 Assignment 3 – Memory Simulator20 PointsAbstractIn this assignment, 
you will write a C++ program to simulate a computer system memory.  
This is the first of a multi-part assignment concluding with a simple computing machine capable ofexecuting  real  programs  compiled  with g++.  
The  purpose  is  to  gain  an  understanding  of  amachine, 
its  instruction  set  and  how  its  features  are  used  by  realistic  programs  written  inC/C++. */




/**
 * 	Display a proper command line error mesage 
 *
 * 	This function will take exactly 3 arguments
 *  If the incorrect ammount of arg's are entered by the user we print a usage() messge
 *   
 *
 * 	@param argc Number of command line arguments 
 *
 * 	@return 
 *
 * 	@note 
 *
 * 	@warning 
 *
 * 	@bug 
 *
 * 	          
 **/
int usage()
{
    std::cerr << "Usage: " /*<< argv[0]*/ << " <option(s)> SOURCES"
              << "Options:\n"
              << "\t-h,--help\t\tShow this help message\n"
              << "\t-d,--destination DESTINATION\tSpecify the destination path"
              << std::endl;

    return 1;
}



/**
 * 	Convert a 32 bit signed integer to binary, then format. 
 *
 * 	This function will take exactly 3 arguments
 *  If the incorrect ammount of arg's are entered by the user we print a usage() messge
 *   
 *
 * 	@param argc Number of command line arguments 
 *
 *  @param argv Vector of character pointer to pointer command-line argumets to be processed 
 *
 * 	@return normal return for main()
 *
 * 	@note Function usage(): will print error message and terminate 
 *
 * 	@warning 
 *
 * 	@bug 
 *
 * 	          
 **/
int main(int argc, char **argv)
{
    //The first argument is a hex number representing the amount of memory to simulate.
    //The second argument is the name of a file to load into the simulated memory

    // If user has NOT submitted a valid argument count Argv[0] is the name of the program 
    // After Argv[0],  argv[argc-1] every element is command -line arguments. 
    if(argc != 3)
    {
        // the wrong number of command-line arguments (not enough or too many)
        usage();
    }

    // Memory object "mem" will take the second command line argument as an argument
    //                    (str.c_str(), &ptr, base)
    memory  mem(std::stoul(argv[1]    , 0   , 16  ));
    
    
    mem.dump (); // Call the dump method from our memory class 

    // If we ARE NOT able to sucessfully load a file through the load_file() method
    if(!mem.load_file( argv[2] ) ) // Pass the 3rd argument
        usage(); // invalid command-line arguments (e.g. an english word where a number is expected)
    mem.dump(); // Call the dump method from our memory class 

    //Output?
    std::cout  << mem.get_size () << std::endl; // Call getsize() method
    std::cout  << hex32(mem.get8 (0))  << std::endl; // Convert what the get8() method returns to a 32bit hex number
    std::cout  << hex32(mem.get16 (0))  << std::endl;
    std::cout  << hex32(mem.get32 (0))  << std::endl;
    std::cout  << hex0x32(mem.get8 (0))  << std::endl;// Convert to 0x32 bit hex format
    std::cout  << hex0x32(mem.get16 (0))  << std::endl;
    std::cout  << hex0x32(mem.get32 (0))  << std::endl;
    std::cout  << hex8(mem.get8 (0))  << std::endl;// Convert to 8 bit hex value 
    std::cout  << hex8(mem.get16 (0))  << std::endl;
    std::cout  << hex8(mem.get32 (0))  << std::endl;
    std::cout  << hex0x32(mem.get32(0x1000)) << std::endl; // Already converted number?

    // Save in memory 
    mem.set8(0x10 , 0x12); // Mem object will call its 8 bit set method, taking 0x format hex values
    mem.set16(0x14 , 0x1234);
    mem.set32(0x18 , 0x87654321 );

    mem.dump (); // Call the dump method from our memory class 


    return 0;
}