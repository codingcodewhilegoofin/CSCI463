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

#include "memory.h"




memory::~memory()
{
         //For debug
                std::cout << "Destroy memory";

         delete [] mem; // free the dynamically allocated array pointed to by Items
}



memory::memory(uint32_t  siz)
{
        //For debug
        std::cout << "In constructor";

        //Save the size for chech_address() and dump()
        this->size = siz;

        // Round for last line 
        siz = (siz+15)&0xfffffff0;  // round the length up, mod-16

        //Hold the address coming from heap 
        mem = new uint8_t[siz];


        //If our mem is null we have an issue 
        if (mem == nullptr)
        {
                 //cout << "Error: memory could not be allocated";
        }
        else
        {       
                //For debug
                std::cout << "Creating memory";
                
                //Create empty memory on programm initalization
                for (int n=0; n < siz; ++n)
                {
                  
                        mem[n] = 0xa5;
                }
          
              
             

        }

}


bool memory::check_address(uint32_t i) const
{
        if( mem[] == i)
        {
                  return true;


        }
        else
        {
                //Obviously, formatting this warning message will involve using your hex0x32() function.
                std::cout << "WARNING: Address out of range:" << i;
                return false;
        }
        
      
}


uint32_t  memory::get_size () const
{
        //Debug
        return this->size;
}



uint8_t  memory::get8(uint32_t  addr) const
{
        if( check_address(addr) == true )
        {
                return mem[] = addr;
        }
        else
        {
                return 0;
        }
            

}
        
       
uint16_t  memory::get16(uint32_t  addr) const
{
        get8(addr);
        get8(addr);

        //A little-endian system, in contrast, stores the least-significant byte at the smallest address


}
        
uint32_t  memory::get32(uint32_t  addr) const
{
        get16(addr);
        get16(addr);

        //A little-endian system, in contrast, stores the least-significant byte at the smallest address

}


void  memory::set8(uint32_t  addr , uint8_t  val)
{

        if( check_address(addr) == true )
        {
                mem[addr]= val;
        }
        
}
       
void  memory::set16(uint32_t  addr , uint16_t  val)
{

        set8(addr);
        set8(addr);

        //A little-endian system, in contrast, stores the least-significant byte at the smallest address
}    

void  memory::set32(uint32_t  addr , uint32_t  val)
{
        set16(addr);
        set16(addr);

        //A little-endian system, in contrast, stores the least-significant byte at the smallest address
}

void  memory::dump()  const
{
        //uint8_t ch = get8(i);
        //ascii[i%16] = isprint(ch) ? ch : ’.’;

        //In this code fragment, the i variable is the address counter in the loop
        // that is formatting andprinting the memory bytes one at-a-time,
        //ascii is a 17-byte character array that is used to collect the 16 print characters 
        //(plus the null-terminator) to display at the end of the currentline of hex bytes, 
        //and isprint()is a standard C library function you can read about in the 
        //on line manual or google it.

}



bool  memory::load_file(const std::string &fname )
{
        std::ifstream infile(fname, std::ios::in|std::ios::binary);

        if(!infile)
        {
                std::cerr << "Cannot open file " << fname;

                return false;
        }
        else
        {
                //Check file one byte at a time
                if(//check_address(); == true )
                {
                        infile.close();
                        return true;
                }
                else
                {
                        std::cerr << "Program too big " << fname;

                        return false;
                }
                
        }
        

}
