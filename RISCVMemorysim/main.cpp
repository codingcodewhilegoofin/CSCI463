 //***********************************************************************************
 //*
 //* 	main.cpp
 //*	CSCI 463 Assignment 3 
 //*
 //* 	Giovanni Moscato Z1820207
 //*
 //*	Memory Simulator
 //* 	Instructor: John Winans
 //* 	Section: -0001
 //*
 //*    Cited Sources: http://courses.cms.caltech.edu/cs11/material/general/usage.html
 //*                   https://en.wikipedia.org/wiki/Usage_message
 //***********************************************************************************

// Include STL libraries  
#include <iostream>
#include "memory.h"
#include "hex.h"



/**
 * 	Display a proper command line error mesage 
 *
 * 	@param none
 *
 * 	@return integer 
 *
 * 	@note exits by standard method
 *
 * 	@warning none
 *
 * 	@bug none
 *         
 **/
int usage()
{
    std::cerr << "Usage: ./memory size filename" << std::endl; // Standard cerr output message

    exit(1);
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
 * 	@warning none
 *
 * 	@bug none
 *         
 **/
int main(int argc, char **argv)
{
    // If number of arguments is incorrect
    if(argc != 3)
    {
        
        usage(); // Standard usage message called
    }

    // Mem constructor will have the size converted into base 16 before being passed
    memory mem(     std::stoul(argv[1]  ,   0   ,   16  )        ); // Call mem constructor
                                                        
    mem.dump (); // Call the dump method from our memory class to display empty array


    // If we ARE NOT able to sucessfully load a file through the load_file() method
    if(!mem.load_file( argv[2] ) ) // Pass the 3rd argument
    {
        usage(); // invalid command-line arguments 
    }
    else
    {
        mem.dump(); // Call the dump method from our memory class with file input
    }
      
    // Ouput converted to hex equilvalent 
    std::cout  << mem.get_size () << std::endl; 
    std::cout  << hex32(mem.get8 (0))  << std::endl; 
    std::cout  << hex32(mem.get16 (0))  << std::endl;
    std::cout  << hex32(mem.get32 (0))  << std::endl;
    std::cout  << hex0x32(mem.get8 (0))  << std::endl;
    std::cout  << hex0x32(mem.get16 (0))  << std::endl;
    std::cout  << hex0x32(mem.get32 (0))  << std::endl;
    std::cout  << hex8(mem.get8 (0))  << std::endl;
    std::cout  << hex8(mem.get16 (0))  << std::endl;
    std::cout  << hex8(mem.get32 (0))  << std::endl;
    std::cout  << hex0x32(mem.get32(0x1000)) << std::endl; 

    // Set to certian values from address specified 
    mem.set8(0x10 , 0x12); 
    mem.set16(0x14 , 0x1234);
    mem.set32(0x18 , 0x87654321 );

    mem.dump (); // Final dump after memory has been set 

    return 0;
}