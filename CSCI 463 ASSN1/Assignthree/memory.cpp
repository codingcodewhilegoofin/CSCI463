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




memory::memory(uint32_t  siz)
{
        //For debug
        std::cout << "In constructor......" << std::endl;
       

        // Round for last line 
        size = (siz+15)&0xfffffff0;  // round the length up, mod-16

        // Declare an array of pointers size 48 on the heap 
        mem = new (std::nothrow) uint8_t[size];


        //mem.resize(size, 0xa5);

        //  If our mem is null we have an issue 
        if (mem == nullptr)
        {
                std::cout << "Error: memory could not be allocated";
        }
        else
        {       
                // For debug
                std::cout << "Creating empty memory through for loop ........." << std::endl;
                
                // Create empty memory on programm initalization
                for (uint32_t n=0; n < size; ++n)
                {
                        mem[n] = 0xa5;
                }
          
        } 

}


memory::~memory()
{
        //For debug
        std::cout << "Destroying memory...." << std::endl;

        delete [] mem; // free the dynamically allocated array pointed to by Items

}

uint32_t  memory::get_size () const
{
        //Debug
        return size;
}

bool memory::check_address(uint32_t i) const
{
        //std::cout << "In check_address....." << std::endl << std::endl; 
        //std::cout << "Making sure its less than 48... " << i << std::endl << std::endl; 

        if( i <= get_size())
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




uint8_t  memory::get8(uint32_t  addr) const
{
        //std::cout << "In get8....." << std::endl << std::endl;  

        //std::cout << "Checking for address.. " << addr << std::endl << std::endl; 

        if( check_address(addr) == true )
        {
                //std::cout << "Returning" << mem[addr] << std::endl << std::endl; 

                return mem[addr];
        }
        else
        {
                return 0;
        }
            

}
        
       
/* uint16_t  memory::get16(uint32_t  addr) const
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

} */


void  memory::set8(uint32_t  addr , uint8_t  val)
{
        //std::cout << "In set8 function ....." << std::endl; 

        if( check_address(addr) == true )
        {
                mem[addr]= val;
        }
        
}
       
/* void  memory::set16(uint32_t  addr , uint16_t  val)
{

        //set8(addr);
        //set8(addr);

        //A little-endian system, in contrast, stores the least-significant byte at the smallest address
}    

void  memory::set32(uint32_t  addr , uint32_t  val)
{
        //set16(addr);
        //set16(addr);

        //A little-endian system, in contrast, stores the least-significant byte at the smallest address
} */

void  memory::dump()  const
{
        std::cout << "In dump ....." << std::endl;

        
        //In this code fragment, the i variable is the address counter in the loop
        // that is formatting andprinting the memory bytes one at-a-time,
        //ascii is a 17-byte character array that is used to collect the 16 print characters 
        //(plus the null-terminator) to display at the end of the currentline of hex bytes, 
        //and isprint()is a standard C library function you can read about in the 
        //on line manual or google it.

        int outputcounter = 10;
        uint32_t oc2 = 0;
        uint32_t oc3 = 0;
        unsigned int i = 0;
        uint32_t j = 0;
        std::string baseCounter = "00000000:";
        std::string newBase = "";
        unsigned char ascii[16] = { };
       

        while ( i < size/16 )
        {
               

                if( (i%16) && (i!=0) )
                {
                  newBase = baseCounter.replace(6,7,std::to_string(outputcounter));
                  newBase.append(":");

                   std::cout << newBase << " ";
                   outputcounter = outputcounter + 10;
                }
                else if ( i == 0)
                {
                   std::cout << baseCounter << " ";
                } 
                else
                {
                
                }
          
          
                for(uint32_t a = oc2; a < 16 + oc2; ++a)
                {

                  if( (a==8) || (a==40) )
                  {
                        std::cout << " ";
                  }
                  else if (a==24)
                  {
                        std::cout << " ";
                  }
                  


                  if(mem[a] == 0xa5)
                  {
                        std::cout << "a5 ";
                  }
                  else
                  {
                        std::cout << " " << hex8( (uint8_t)mem[a] );
                  }

                  
                } 

               

                for( uint32_t k = 0; k < get_size(); ++k ) 
                {

                        //std::cout << "On iteration.. " << k << std::endl << std::endl; 


                        uint8_t ch = get8(k);


                        //std::cout << "Ch  is " << ch << std::endl << std::endl; 



                        ascii[k%16] = isprint(ch) ? ch : '.';     
                }

                std::cout << "*";

               

                for ( j = j; j < size-(32-oc3); j++)
                {

                        if ((j % 16 == 0) && (j != 0) && !(ascii[j] == 0xa5))
                        {
                                std::cout << ascii;
                        }
                        else
                        {
                                std::cout << ".";
                        }
                }

                std::cout << "*";



                std::cout << std::endl;

                oc2 = oc2 + 16;
                oc3 = oc3 + 16;
                j = j + 16;
                i++;

        }

        

        std::cout << std::endl;

//end
}



bool  memory::load_file(const std::string &fname )
{       
        std::cout << "Load_file....." << std::endl; 

        char temporary = 0;

        std::ifstream infile(fname, std::ios::in|std::ios::binary);

        if(!infile)
        {
                std::cerr << "Cannot open file " << fname;

                return false;
        }
        else
        {
                //while reading from the file
                while(infile.get(temporary))
                {       
                
                     std::cout << "Inside file ....." << std::endl; 
                
                     int i = 0;   

                     //Check file one byte at a time
                     if(check_address(i) == true )
                     {
                        std::cout << "Adress exists....." << std::endl; 
                        mem[i] = temporary;
                          
                     }
                     else
                     {
                        std::cerr << "Program too big ! " << fname;

                        return false;
                     }

                     i++;
                }
                infile.close();
                return true;
        }
        

}
