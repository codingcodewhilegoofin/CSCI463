//***********************************************************************************
 //*
 //* 	registerfile.cpp
 //*	CSCI 463 Assignment 5
 //*
 //* 	Giovanni Moscato Z1820207
 //*
 //*	Memory Simulator
 //* 	Instructor: John Winans
 //* 	Section: -0001
 //*
 //***********************************************************************************


#include "registerfile.h"
    

/**
 * Initialize registerx0to zero, and all other registers to0xf0f0f0f0.
 * 
 * @param none 
 * 
 * @return void 
 *
 * @note none
 *
 * @warning none 
 *
 * @bug No bugs found 
 ********************************************************************************/  
void registerfile::reset()
{

    // Register 0 is always 0 
    GPR[0] = 0;

    // For every other GPR set to 0xf0f0f0f0
    for( int i = 1; i < 32 ; ++i )
    {
        // Convert the hex value to a 32 bit integer 
        GPR[i] = 0xf0f0f0f0;

    }


}

/**
 * Constructor that will call reset upon creation 
 * 
 * @param none 
 * 
 * @return void 
 *
 * @note none
 *
 * @warning none 
 *
 * @bug No bugs found 
 ********************************************************************************/ 
registerfile::registerfile()
{
    reset();
}


/**
 * Destructor that will delete the register array 
 * 
 * @param none 
 * 
 * @return void 
 *
 * @note none
 *
 * @warning none 
 *
 * @bug No bugs found 
 ********************************************************************************/ 
registerfile::~registerfile()
{

}


/**
 * Assign register r the given val.  If r is zero, then do nothing.
 *
 * 
 * @param r register 
 * 
 * @param val value
 *
 * @return void
 *
 * @note none
 *
 * @warning none 
 *
 * @bug No bugs found 
 ********************************************************************************/ 
void registerfile::set(uint32_t r, int32_t val)
{
    if( r == 0 )
    {

    }
    else
    {
        GPR[r] = val;
    }

}
    
/**
 * Return the value of register r.  If r is zero, then return zero.
 *
 * 
 * @param r register 
 *
 * @return void
 *
 * @note none
 *
 * @warning none 
 *
 * @bug No bugs found 
 ********************************************************************************/  
int32_t registerfile::get(uint32_t r) const
{
    if( r == 0)
    {
        return 0;
    }
    {
        return GPR[r];
    }
}

/**
 * Implement a dump of the registers. 
 * Uses hex32() utility function to simplify printing the register values
 *
 * 
 * @param r register 
 *
 * @return void
 *
 * @note none
 *
 * @warning none 
 *
 * @bug No bugs found 
 ********************************************************************************/  
void registerfile::dump() const
{
    
    std::cout << " x" << 0; // Always start with the 0th register 

    // For every register in memory 
    for ( int i = 0; i < 32; ++i )
    {

        // If our index is a multiple of 8 end the line 
        if( (i%8==0) && (i !=0))
        {
            std::cout << std::endl;
        }

        // If our index is a multiple of 8 we can print the register num
        if( (i%8==0) && (i !=0) && ( i < 15) )
        {
            std::cout << " x" << i;
        }
        else if ( (i%8==0) && (i !=0) )
        {
            std::cout << "x" << i;
        }

        // Simply output the value as a 32bit hex value using the get function
        std::cout << " " << hex32(get(i));
            
    }

    std::cout << std::endl;
}