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
 * 	Print a usage  message  and  abort  the  program.
 *
 * 	@param none
 *
 * 	@return none
 *
 * 	@note exits by standard method
 *
 * 	@warning none
 *
 * 	@bug none
 *         
 **/
static  void  usage ()
{
    std::cerr  << "Usage: rv32i [-m hex -mem -size] infile" << std::endl;
    std::cerr  << "     -m specify  memory  size (default = 0x10000)" << std::endl;
    exit (1);
}


/**
 * 	Convert a 32 bit signed integer to binary, then format. 
 *
 * 	This function will take exactly 3 arguments with size being optional 
 *  If the incorrect ammount of arg's are entered by the user we print a usage() messge
 *   
 *
 * 	@param argc Number of command line arguments 
 *
 *  @param argv Vector of character pointer to pointer command-line argumets to be processed 
 *
 * 	@return normal return for main()
 *
 * 	@note Function usage(): will print error message and terminate, the standard memory size
 *        will default to memory_limit
 *
 * 	@warning none
 *
 * 	@bug none
 *         
 **/
int  main(int argc , char **argv)
{

    uint32_t  memory_limit = 0x1000;      //  default  memory  size = 64k
    int opt;

    while ((opt = getopt(argc , argv , "m:")) !=  -1)
    {
        switch (opt)
        {
            case 'm':memory_limit = std::stoul(optarg ,nullptr ,16);
            break;
        default: /* ’?’ */
            usage ();
        }
    }

    if (optind  >= argc)
        usage();     //  missing  filename
    
    memory  mem(memory_limit);
    
    if (!mem.load_file(argv[optind ]))
        usage();
        
    rv32i  sim(&mem);
    sim.disasm ();
    mem.dump();
    return  0;

}