#ifndef  memory_H
#define  memory_H

#include  <string >
#include  <stdint.h>

// Class doc??
class  memory
{

    public:
        
        // Constructor 

        /*
            For debug 

            memory(uint32_t siz);Save thesizargument in thesizemember variable.  
            Then allocatesizbytes for thememarray and initialize every byte to0xa5.
            Youmayimplement the following rounding logic to make the job of formatting and aligningyour last line of output in yourdump()method easier:siz = (siz+15)&0xfffffff0;  
             //round the length up, mod-16
        
        */
        memory(uint32_t  siz);

        // Destructor 

        /*
           In  the  destructor,  free  the  memory  that  was  allocated  in  the  constructor  to  represent  thesimulated memory.
        
        */
        ~memory ();

        // Check stuff...
        //Note thatcheck_address()warnings are not simulator or user errors and therefore they must bewritten to stdout.)
        /*
           Return true if the given address is in your simulated memory. 
            If the given address is not inyour simulated memory then print a warning message to stdout formatted 
            as shown below:WARNING: Address out of range: 0x00001000and return false.
            Obviously, formatting this warning message will involve using yourhex0x32()function.
        
        */
        bool  check_address(uint32_t i) const;

        // Getter methods
        /*
           Return the (possibly rounded up)sizvalue.
        
        */
        uint32_t  get_size () const;
        /*
           Check to see if the givenaddris in yourmemby callingcheck_address().
             Ifaddris in thevalid  range,  return  the  value  of  the  byte  from  your  simulated  memory  at  that  address.  
              Ifaddrisnotin the valid range then return zero to the caller.
        
        */
        uint8_t  get8(uint32_t  addr) const;
        /*
           This function must call yourget8()function twice to get two bytes and then 
           combine themin  little-endian  order  to  create  a  16-bit  return  value. 
           
             Because  you  are  using  yourget8()function, the job of validating the 
             addresses of the two bytes will be taken care of there. 
             
              Donot redundantly check the validity in this function.
              
              https://en.wikipedia.org/wiki/Endianness
        */
        uint16_t  get16(uint32_t  addr) const;
        /*
           This function must callget16()function twice and combine the
            results in little-endian ordersimilar to the implementation ofget16().
        
        */
        uint32_t  get32(uint32_t  addr) const;

        // Setter methods 

        /*
           This function will callcheck_address()to verify the theaddrargument is valid. 
            Ifaddrisvalid then set the byte in the simulated memory at that address to the 
            givenval.  
            
            Ifaddrisnot valid then discard the data and return to the caller.
        
        */
        void  set8(uint32_t  addr , uint8_t  val);
        /*
           This  function  will  callset8()twice  to  store  the  givenvalin 
            little-endian  order  into  thesimulated memory starting at the address given 
            in theaddrargument
        
        */
        void  set16(uint32_t  addr , uint16_t  val);
        /*
           This function will callset16()twice to store the givenvalin little-endian order 
           into thesimulated memory starting at the address given in theaddrargument.
        
        */
        void  set32(uint32_t  addr , uint32_t  val);




        // Dump method
        void  dump()  const;

        // Load file method 
        bool  load_file(const std::string &fname );

    private:

        // Class variables 
        /*
           An array of bytes representing the simulated memory. 
            Allocate it with the given size in yourconstructor and de-allocate 
            it in the destructor.
        
        */
        uint8_t *mem;         // the  actual  memory  buffer
        /*
           Use  this  to  retain  the  number  of  bytes  that  you  allocated  formem. 
             It  will  be  needed  toimplementcheck_address()and determine how many bytes 
             to display indump().
        
        */
        uint32_t  size;

};

#endif