//***********************************************************************************
 //*
 //* 	registerfile.h
 //*	CSCI 463 Assignment 5
 //*
 //* 	Giovanni Moscato Z1820207
 //*
 //*	Memory Simulator
 //* 	Instructor: John Winans
 //* 	Section: -0001
 //*
 //***********************************************************************************


#ifndef REGISTERFILE_H
#define REGISTERFILE_H

//#include "rv32i.h"
#include <iostream> 
#include "hex.h" 



class registerfile
{
    public:

    // Constructor 
    registerfile();

    // Destructor 
    ~registerfile();

    // Reset the registers 
    void reset();

    // Setters 
    void set(uint32_t r, int32_t val);
    
    // Getters 
    int32_t get(uint32_t r) const;

    // Dump of registers 
    void dump() const;

    private:
    // Array of GPR 
    int32_t GPR[32] = {};
    

};




#endif

