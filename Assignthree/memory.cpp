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

        
        std::cout <<  size << std::endl;


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
        
        if( i <= get_size())
        {
                return true;
        }
        else
        {
                
                std::cout << "WARNING: Address out of range: " << hex0x32(i) << std::endl;
                return false;
        }
        
      
}




uint8_t  memory::get8(uint32_t  addr) const
{
        
        if( check_address(addr) == true )
        {
                return mem[addr];
        }
        else
        {
                return 0;
        }
            
}
        
       
 uint16_t  memory::get16(uint32_t  addr) const
{

        uint8_t byte1 = get8(addr);
        uint8_t byte2 = get8(addr + 1 );
        
       
	return byte2 << 8 | byte1;
        
}
        
 uint32_t  memory::get32(uint32_t  addr) const
{
        uint16_t byte1 = get16(addr);
        uint16_t byte2 = get16(addr + 1 );
       
       
	return byte2 << 16 | byte1;
        
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
    

        set8(addr+1, val >> 8);

	set8(addr, val);

	mem[addr] = val;
       
}    


void  memory::set32(uint32_t  addr , uint32_t  val)
{
        set16(addr+1, val >> 8);

	set16(addr+2, val >> 16);

	mem[addr] = val;
} 


void  memory::dump()  const
{
      

        int outputcounter = 10;
        uint32_t oc2 = 0;
        unsigned int i = 0;
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

               
                for (uint32_t j = 0; j < size-32; j++)
                {

                        if ( (j % 16 == 0) && (j != 0) && !(ascii[j] == 0xa5) )
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
                i++;

        }

        

//end
}



bool memory::load_file(const std::string& fname)
{

	char temp;
	uint32_t i=0;

	std::ifstream infile(fname, std::ios::in|std::ios::binary);

	
	if(!infile)
        {
		std::cout << "File " << fname << " could not open" << std::endl;
		return false;
	}
	while(infile.get(temp))
        {
		
		if(check_address(i))
                {
			
			mem[i] = temp;
		}
		else{
			std::cerr << "Program too big." <<  std::endl;
			return false;
		}

		i++;
	
	}

	return true;
}