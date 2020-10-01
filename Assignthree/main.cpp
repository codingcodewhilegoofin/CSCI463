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
    std::cerr << "Usage: " << "WRONG" << std::endl;

    exit(0);
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
    
    if(argc != 3)
    {
        
        usage();
    }



    // Memory object "mem" will take the second command line argument as an argument
    //              Takes one argument size! Which is converted ! 
    std::cout << "Constructing memory object........." << std::endl; 
    memory mem(     std::stoul(argv[1]  ,   0   ,   16  )        );
    
    

    
    mem.dump (); // Call the dump method from our memory class 



    /* std::cout << "Loading file............" << std::endl; 
    // If we ARE NOT able to sucessfully load a file through the load_file() method
    if(!mem.load_file( argv[2] ) ) // Pass the 3rd argument
    {
        usage(); // invalid command-line arguments (e.g. an english word where a number is expected)
    }
    else
    {
        std::cout << "Dumping....." << std::endl; 
        mem.dump(); // Call the dump method from our memory class 
    } */
      




    //Output
    std::cout << "Outputing memory size............" << std::endl; 
    std::cout  << mem.get_size () << std::endl; // Call getsize() method
    //std::cout  << hex32(mem.get8 (0))  << std::endl; // Convert what the get8() method returns to a 32bit hex number
    //std::cout  << hex32(mem.get16 (0))  << std::endl;
    //std::cout  << hex32(mem.get32 (0))  << std::endl;
    //std::cout  << hex0x32(mem.get8 (0))  << std::endl;// Convert to 0x32 bit hex format
    //std::cout  << hex0x32(mem.get16 (0))  << std::endl;
    //std::cout  << hex0x32(mem.get32 (0))  << std::endl;
    //std::cout << "Calling hex8 function............" << std::endl; 
    //std::cout << "Calling from memory get8 function............" << std::endl;
    //std::cout << "Passing 0 ............" << std::endl;
    //std::cout  << hex8(mem.get8 (0))  << std::endl;// Convert to 8 bit hex value 
    //std::cout  << hex8(mem.get16 (0))  << std::endl;
    //std::cout  << hex8(mem.get32 (0))  << std::endl;
    //std::cout  << hex0x32(mem.get32(0x1000)) << std::endl; // Already converted number?






    // Save in memory 
    //std::cout << "Calling from memory set8 function............" << std::endl;
    //std::cout << "Passing address 0x10, finding adress , setting address to 0x12............" << std::endl;
    //mem.set8(0x10 , 0x12); // Mem object will call its 8 bit set method, taking 0x format hex values
    //mem.set16(0x14 , 0x1234);
    //mem.set32(0x18 , 0x87654321 );



    //std::cout << "Dumping....." << std::endl; 
    //mem.dump (); // Call the dump method from our memory class 



    return 0;
}