 //***********************************************************************************
 //*
 //* 	memory.cpp
 //*	CSCI 463 Assignment 3 
 //*
 //* 	Giovanni Moscato Z1820207
 //*
 //*	Memory Simulator
 //* 	Instructor: John Winans
 //* 	Section: -0001
 //*
 //***********************************************************************************

// Local header file 
#include "memory.h"





/**
 * Memory class member function : constructor 
 *
 * The constructor for the memory class will essentially take a unsigned 32 bit integer from
 * main() method and define the SIZE public member variable rounded to mod 16. 
 * From there the function will dynamically allocate space on the heap for an 
 * 8 bit unsigned integer type array of size : SIZE. Finally an empty array is 
 * initialized with the hex value 0xa5 to represent empty values. 
 *
 * @param siz siz is a unsigned 32 bit integer type passed from main()
 *
 * @return No return, is a constructor 
 *
 * @note I have included nothrow as it is recommended to set the pointer to a 
 * nullpointer if an error occurs. I then check if there is a null pointer and 
 * output an appropriate message if this occurs. 
 *
 * @warning Size of the array is defined at runtime, and destroyed by ~memory 
 * after main() ends.
 *
 * @bug No bugs found 
 ********************************************************************************/
memory::memory(uint32_t  siz)
{
       
        // Public member variable is equated to siz mod 16 
        // This is our size to define the size of our array 
        size = (siz+15)&0xfffffff0;  // round the length up, mod-16

        // Dynamically allocate memory on the heap during runtime to an 
        // array of type uint8_t of size: SIZE  
        mem = new (std::nothrow) uint8_t[size];

        
        //  If our mem is null we have an issue 
        if (mem == nullptr)
        {       
                // NOT user input, should be displayed on std::cout 
                std::cout << "Error: memory could not be allocated" << std::endl;
        }
        else // Array was allocated properly 
        {       

                // Create empty memory on programm run time for the appropriate
                // size defined by size member variable 
                for (uint32_t n=0; n < size; ++n) // Why 32 ?
                {
                        mem[n] = 0xa5; // Initalize each spot in the array to 0xa5
                                       // This represents empty in dump()
                }
          
        } 

}

/**
 * Memory class member function : destructor 
 *
 *The destructor is called after main() loops for the first time untill it is called 
 * again. It simply deletes ( deallocates ) the array from memory and
 * removes it from the heap ensuring the pointers are also destroyed.
 *
 * @param   
 *
 * @return No return, is a destructor 
 *
 * @note  The array is destroyed after each complete iteration of the porgram and size
 * is then reset 
 *
 * @warning if not properly destroyed could leave hanging pointers or memory leak
 *
 * @bug No bugs found 
 ********************************************************************************/
memory::~memory()
{

        delete [] mem; // free the dynamically allocated array 

        mem = NULL;
        size = 0;

}

/**
 * Memory class member function : get_size() returns the size member variable  
 *
 * Instead of refering to the size public member function we can call this function
 * which will return the correct size from the class. 
 *
 * @param none 
 *
 * @return uint32_t as the correct size  
 *
 * @note will be used after we have constructed array for the rest of the member functions
 * instead of directly refering to size  
 *
 * @warning 
 *
 * @bug No bugs found 
 ********************************************************************************/
uint32_t  memory::get_size () const
{
        return size;
}


/**
 * Memory class member function : check_address will check if a given size is in range  
 *
 * This function will only be called to compare a size given against the array's defined 
 * size. If the size i is below to equal to the array size we can return true. If not 
 * we output an error message.  
 *
 * @param i siz is a unsigned 32 bit integer type that should represent a size 
 *
 * @return bool  
 *
 * @note The error message will display which address is out of range formatted
 * by the hex0x32 function defined in hex.cpp 
 *
 * @warning none
 *
 * @bug No bugs found 
 ********************************************************************************/
bool memory::check_address(uint32_t i) const
{
        // If the argument size is in range we accept this 
        if( i <= get_size() )
        {
                return true;
        }
        else // Size is not in range 
        {
                // For check_address warning message should be standard output 
                std::cout << "WARNING: Address out of range: " << hex0x32(i) << std::endl;
                return false;
        }
        
      
}



/**
 * Memory class member function : get8 will take an address given and check it against 
 * the check_address function 
 *
 * The function will take addr as an address passed to it and implement check_address(addr).
 * If the address is in given range of our memory size we return the bytes of memory 
 * that are stored at that address. If not we return 0. 
 *
 * @param addr is an address argument that needs to be an unsiged 32 bit integer 
 *
 * @return uint8_t because get 8 should return 8 bits  
 *
 * @note This function is nested often  
 *
 * @warning address must be 32 bits when taken by parameter 
 *
 * @bug No bugs found 
 ********************************************************************************/
uint8_t  memory::get8(uint32_t  addr) const
{
        
        if( check_address(addr) == true )
        {
                return mem[addr]; // Return value of byte in simulated memory at addr 
        }
        else
        {
                return 0; // Return 0 to the caller 
        }
            
}
        
 /**
 * Memory class member function : get16 will call get8() to get two bytes of data and 
 * combine in little endian order to get a 16 bit return value 
 *
 * This is done by first accepting an address, and calling get8() with that address twice.
 * We can store the result of the first call to that address as a 8 bit value because
 * that is what get 8 returns. Our first byte is then stored as byte1. To get our 
 * second byte we repeat the process but add 1 to get the next byte in memory because we need
 * a 16 bit number to return. Finally we return byte 2 first shifted 8 bits and THEN 
 * byte 1 because we want it in little endian order.  
 *
 * @param addr is an address argument that needs to be an unsiged 32 bit integer 
 *
 * @return uint16_t because get 16 should return 16 bits  
 *
 * @note return value is shifted by 8 bits because we need to have the second byte value
 * print before the first due to little endian order 
 *
 * @warning should not check address again, because get 8 does that for us.
 *
 * @bug None found
 ********************************************************************************/      
 uint16_t  memory::get16(uint32_t  addr) const
{

        uint8_t byte1 = get8(addr); // First 8 bytes found by get8()
        uint8_t byte2 = get8(addr + 1 ); // Second 8 bytes is the next 8 bytes so we add 1
                                        // To our address  
        
       
	return byte2 << 8 | byte1; // We want it in little endian order 
        
}

 /**
 * Memory class member function : get32 will call get16() to get four bytes of data and 
 * combine in little endian order to get a 32 bit return value 
 *
 * This is done by first accepting an address, and calling get16() with that address twice.
 * We can store the result of the first call to that address as a 16 bit value because
 * that is what get 16 returns. Our first byte is then stored as byte1 although 
 * technically at this point we actually have 2 bytes ( includes the LSB ). 
 * To get our second byte(s) we repeat the process but add 2 to get the next byte(s)
 * in memory because we need a 32 bit number to return. Finally we return byte34 first shifted 16 bits and THEN 
 * byte12 because we want it in little endian order. This will produce a total of 4 bytes
 * which is the equivalent of a 32 bit unsigned int.
 *
 * @param addr is an address argument that needs to be an unsiged 32 bit integer 
 *
 * @return uint32_t because get 32 should return 32 bits  
 *
 * @note return value is shifted by 16 bits because we need to have the second byte value
 * print before the first due to little endian order and we are now TWICE as far
 *
 * @warning should not check address again, because get 8 does that for us.
 *
 * @bug none found  
 ********************************************************************************/         
 uint32_t  memory::get32(uint32_t  addr) const
{
        uint16_t byte12 = get16(addr); // Will give us our first 2 bytes at address addr
        uint16_t byte34 = get16(addr + 2 ); // Call give us next 2 bytes in memory 
       
       
	return byte34 << 16 | byte12; // Return the 4 bytes in little endian order 
        
}  


/**
 * Memory class member function : set8 will take an address given and check it against 
 * the check_address function. If the address is in range we "set".
 *
 * The function will take addr as an address passed to it and implement check_address(addr).
 * If the address is in given range of our memory size we return the bytes of memory 
 * that are stored at that address. If valid we can then "set" the memory at the address
 * specified by addr to the value val.  
 *
 * @param addr is an address argument that needs to be an unsiged 32 bit integer 
 * 
 * @param val is an address argument that needs to be an unsiged 8 bit integer we can assign
 *            to a spot in our simulated memory 
 *
 * @return void 
 *
 * @note This function is nested often  
 *
 * @warning address must be 32 bits when taken by parameter and 8 to be able to store in our 
 * array 
 *
 * @bug none found  
 ********************************************************************************/
void  memory::set8(uint32_t  addr , uint8_t  val)
{
      
        // Check if address given is in range 
        if( check_address(addr) == true )
        {
                mem[addr]= val; // Set memory at given address to value 
        }
        else
        {
                // Discard and return nothing 
        }
        
}

/**
 * Memory class member function : set16 will take an address given and check it against 
 * the check_address function. If the address is in range we "set".
 *
 * The function will take addr as an address passed to it and implement check_address(addr).
 * If the address is in given range of our memory size we return the bytes of memory 
 * that are stored at that address. If valid we can then "set" the memory at the address
 * specified by addr to the value val. But first we need to call set8() twice in order to 
 * store the value in the furthest bits due to little endian order. This first set should
 * also be shifted by 8 bits to the right since this is our 2nd byte we want. Now we do a 
 * regular set 8 for the given value. Finally setting the value after.   
 *
 * @param addr is an address argument that needs to be an unsiged 32 bit integer 
 * 
 * @param val is an address argument that needs to be an unsiged 16 bit integer we can assign
 *            to a spot in our simulated memory 
 *
 * @return void 
 *
 * @note none
 *
 * @warning address must be 32 bits when taken by parameter and 16 to be able to store in our 
 * array 
 *
 * @bug none found  
 ********************************************************************************/
 void  memory::set16(uint32_t  addr , uint16_t  val)
{
    

        set8(addr+1, val >> 8); // little endian order requires the 2nd value to be stored 
                                // first shifted by 8 bits

	set8(addr, val); // Store next value 

	mem[addr] = val; // Combined 16 bit values are now able to be stored
       
}    

/**
 * Memory class member function : set32 will take an address given and check it against 
 * the check_address function. If the address is in range we "set".
 *
 * The function will take addr as an address passed to it and implement check_address(addr).
 * If the address is in given range of our memory size we return the bytes of memory 
 * that are stored at that address. If valid we can then "set" the memory at the address
 * specified by addr to the value val. But first we need to call set16() twice in order to 
 * store the value in the furthest bits due to little endian order. This first set should
 * also be shifted by 8 bits to the right since this is our 2nd byte we want. Now we do a 
 * regular set 16 for the given value except we also need to shift this 16 bits
 * over in order to keep this to form with little endian. Finally setting the value after.   
 *
 * @param addr is an address argument that needs to be an unsiged 32 bit integer 
 * 
 * @param val is an address argument that needs to be an unsiged 32 bit integer we can assign
 *            to a spot in our simulated memory 
 *
 * @return void 
 *
 * @note none
 *
 * @warning address must be 32 bits when taken by parameter and 32 to be able to store in our 
 * array 
 *
 * @bug none found
 ********************************************************************************/
void  memory::set32(uint32_t  addr , uint32_t  val)
{
        set16(addr+1, val >> 8); // Increment the address by 1 in order to set the first
                                // 2 bytes 

	set16(addr+2, val >> 16); // Increment the address by 2 in order to set the next
                                 // 2 bytes 

	mem[addr] = val; // Set the spot in simulated memory to correct value 
} 


/**
 * Memory class member function : dump() will display our simulated memory first as decimal
 * values in increments of 10. Then it will display in little endian order the hex values 
 * in our simulated memory. 
 *  
 *
 * @param none 
 * 
 * @return void 
 *
 * @note This dump should be able to handle any intput file given and correctly display it
 *
 * @warning none 
 *
 * @bug none
 ********************************************************************************/
void memory::dump () const 
{

        char ascii[17]={}; // Empty ascii formatted array to hold additional end of string

        // For the entire size of our simulated memory 
        for (uint32_t i = 0; i < get_size(); ++i)
        {
        
            // If our index is a multiple of 16 we can print the ascii section
            if( (i%16==0) && (i !=0) )
            {
                std::cout << "*" << ascii << "*" << std::endl;
            }

            // If our index is equal to 10 print the hex value 
            if( i%0x10 == 0)
            {
                std::cout<< hex32(i) <<": ";
            }

            uint8_t ch = get8(i); // Call get8 method at indexed address value 
          
            // If we are at a multiple of 8 and NOT 16 print an extra space in order to 
            // Seperate the hex values into 8 bytes at a time
            if( ( (i+1)%8==0) && (i!=0) && ( (i+1)%16 !=0)  )
            {
                std::cout << hex8(ch) << "  "; 
            }
            else
            {
                std::cout << hex8(ch) << " "; 
            }
        
            // Store the character into our ascii array IF its a valid character
            ascii[i%16] = std::isprint(ch) ? ch : '.';

            // If our index is at max size print one last line
            if( i == (get_size()-1) )
            {
                std::cout << "*" << ascii << "*" << std::endl;
            }

        }

}

            
             
/**
 * Memory class member function : load_file() will display our simulated memory first as decimal
 * values in increments of 10. Then it will display in little endian order the hex values 
 * in our simulated memory. 
 *  
 *
 * @param fname file name given from user as an command line argument 
 * 
 * @return bool  
 *
 * @note none
 *
 * @warning none 
 *
 * @bug none
 ********************************************************************************/
bool memory::load_file(const std::string& fname)
{

	char temporary; // will hold the byte untill it is placed in mem
	uint32_t i=0;
        // Read our file in binary so we can distrubute into bytes 
	std::ifstream infile(fname, std::ios::in|std::ios::binary);
        // Make sure white space is not skipped
        infile >> std::noskipws;

	// If the file was not able to open
	if(!infile)
        {
		std::cout << "Can't open file " << fname << " for reading" << std::endl;
		return false;
	}
	while( infile.get(temporary) ) // While in file given by user
        {
		
		if( check_address(i) ) // Check if the address is valid for simulated mem
                {
			
			mem[i] = temporary; // If its appropriate store that value from the 
                                            // file into our simulated memory 
		}
		else
                {       
                        // File could be too large to handle we need to close it 
			std::cerr << "Program too big." <<  std::endl;
                        infile.close();
			return false;
		}

		i++; // increment to next byte of file 
	}

	return true;
}
