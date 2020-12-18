 //***********************************************************************************
 //*
 //* 	main.cpp
 //*	CSCI 463 Assignment 5 
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
#include <unistd.h>  

// Personal includes 
#include "hex.h"
#include "memory.h"
#include "rv32i.h"


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
    std::cerr  << "Usage: rv32i [-dirz] [-l -execution-limit] [-m hex -mem -size] infile" << std::endl;
    std::cerr  << "     -m specify  memory  size (default = 0x10000)" << std::endl;
    std::cerr  << "     -l execution limit  size (default = inf)" << std::endl;
    exit (1);
}


/**
 * 	Convert a 32 bit signed integer to binary, then format. 
 *
 * 	This function will take exactly 3 arguments with size being optional 
 *  If the incorrect ammount of arg's are entered by the user we print a usage() messge
 *   
 *  When determining an instruction to execute , different options may
 *  be set by the user. These options will trigger different boolean flags
 *  that set off certian functionalities
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

    uint32_t  memory_limit = 0x10000;      //  default  memory  size = 64k
    uint64_t exec_limit = 0; // default instruction limit is infinite 
    int opt;

    
    // Flags 

    bool dtrigger = false;
    bool itrigger = false;
    bool ltrigger = false;
    bool rtrigger = false;
    bool ztrigger = false;

    
    while ((opt = getopt(argc , argv , "dil:rzm:")) !=  -1) // Use unix getopt to specify memory size 
    {
        switch (opt)
        {
            case 'd': dtrigger = true;
            break;

            case 'i': itrigger = true;
            break;

            case 'l': 
            exec_limit = std::stoul(optarg ,nullptr ,16); // Allow user to choose execution size 
            ltrigger = true;
            break;

            case 'r': rtrigger = true;
            break;

            case 'z': ztrigger = true;
            break;

            case 'm':
         
            memory_limit = std::stoul(optarg ,nullptr ,16); // Allow user to choose memory size 
            break;


        default: /* ’?’ */
            usage ();
        }
    }

    if (optind  >= argc)
        usage();     //  missing  filename
    
    memory  mem(memory_limit); // Memory object with defined limit 
    
    if (!mem.load_file(argv[optind ])) // Read binary files 
        usage();
        
        
    
    rv32i  sim(&mem);// Simulate the memeory 


    // Sim after dtrigger???


    if( (rtrigger == true) && (itrigger == true) )
    {
        // For debug 
        //std::cout << rtrigger << "rtrigger value" << std::endl;

        sim.reset();
        sim.set_show_registers(true);

        //sim.dump();
    }
    
    //Triggers 
    if( dtrigger == true)
    {
        sim.set_dissasembly(true);// Show the insn printed during exec
        
        sim.disasm();// Disassemble each instruction 
        sim.reset();// Reset the PC value 
    }


    if( itrigger == true )
    {
        sim.set_show_instructions(true);// Show the insn printed during exec

    }

    if( ltrigger == true )
    {
        // Cap the number of insn executed here 
        //sim.reset();
        sim.run(exec_limit);
    }

    if( ltrigger == false )
    {
       //sim.reset();
       sim.run(exec_limit); // No cap run forever 
    }


    if( rtrigger == true )
    {
        // For debug 
        //std::cout << rtrigger << "rtrigger value" << std::endl;

        //sim.reset();
        sim.set_show_registers(true);

        //sim.dump();
    }


    if( ztrigger == true )
    {
        

        sim.set_show_dump_mem(true);// Show the insn printed during exec

        sim.dump(); // Dump of simulated memory 

        mem.dump(); // Dump of memory 
    }


    return  0;

}
