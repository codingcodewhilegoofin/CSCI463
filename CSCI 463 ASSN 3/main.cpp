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


/* CSCI 463 Assignment 3 – Memory Simulator20 PointsAbstractIn this assignment, 
you will write a C++ program to simulate a computer system memory.  
This is the first of a multi-part assignment concluding with a simple computing machine capable ofexecuting  real  programs  compiled  with g++.  
The  purpose  is  to  gain  an  understanding  of  amachine, 
its  instruction  set  and  how  its  features  are  used  by  realistic  programs  written  inC/C++. */


int main(int argc, char **argv)
{

    //Input
    if(argc != 3)
    {
        //Yourusage()function must print an appropriate error message and terminate the program in thetraditional manner
        usage();
    }

    memory  mem(std::stoul(argv[1], 0, 16));
    mem.dump ();

    if(!mem.load_file( argv[2] ) )
        usage();
    mem.dump();

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
    std::cout  << hex0x32(mem.get32(0 x1000)) << std::endl;

    mem.set8(0x10 , 0x12);
    mem.set16(0x14 , 0x1234);
    mem.set32(0x18 , 0x87654321 );
    mem.dump ();






    return 0;
}