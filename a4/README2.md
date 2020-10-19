# Program Breakdown:

## Goal: Load & Disassemble a binary RV32I executable file

## Goal2: Understand the RV32I instruction set 

### Program Description: 
1: Load binary file into simulated memory
2: Decode 32-bit instructions from address 0 - max

# Main() and Usage():
### Main() will take 2 arguments with 1 optional memory size argument.

#### Usage() will simply print an standard cerror message stating the correct way to run the program:

Usage: rv32i [-m hex -mem -size] infile

#### and then simply exiting with a standard exit code of 1.

### Main() will then define the default memory size limit.
uint32_t  memory_limit = 0x1000;
***
### this is an unsigned 32-bit ( 4 byte / 2 word) integer with a hex value of 0x1000.
***
### In hex we can think of this as 0x00001000 or 
### 0x [10] [00]
***
***
### OR in binary
### 1000000000000
### 0001 0000 0000 0000 ( 16 bits of 32 total )
***
### OR decimal: 4096 ( unsigned )
***
### Now we can declare an integer called opt. This will consider what operation we want? We have a while loop that calls getopt()? Where is this defined? Getopt() will take 3 arguments. argc ( the ammount of arguments entered) , argv(the actual argument values in an array), and a string simply indicating the 3rd optional argument.
### While the opt code is NOT -1 we choose through a switch statment which code we want. If the case was the string 'm' we define a new memory_limit size of optarg? Through stoul again. 

### Then we break out of the while loop, else our default case is the usage statment.

### Now we check if the operation ammount? is greater than or equal to the ammount of arguments enetered. If it is we print usage() else we declare our memory object's (simulated memory) size to be the size of memory_limit. This is either the default or user requested memory size.

#### If we can not load the file with the operation code? then we print a usage() statment

### Else we now do something? with rv32i ( assuming this is another object) to declare sim's something with a reference to our simulated memory address. 

### Afterwards we dissasemble the "sim"? and then do a memory dump()

# Finaly main() ends with a standard return value 
***
***
***
# Input:
## Main() accepts 1 or 2 arguments, the executable, optional memory size, and file to load as a executable program 
***
# Output:
## Is a disassembly of the loaded file folloed by a dump. 

### This is a mix of decimal and hex values
- Far left column is 32- bit address printed in hex
- Second column is 32-bit hex full-word ( 4 bytes ) representation of the instruction fetched from memory at address in column 1
- 3rd column is instruction mnemonic 
- 4th column depends on type of instruction ( I, R ?)
- Register numbers are printed as x0 - x31
- Hexadecimal literals are printed 0x.....
- Decimal literalas are printed with the first character being a number (1-9) 
- Watch out for x! Both hex and registers use it 

***
# Hints( For class delete later)
- Should be written in parts
- Start by updating main.cpp and STUB in rv32i::disam() to do NOTHING but return to verify it is running OK
- Implement rv32i::disasm() loop to print the PC and fetched instruction-word values.
- Add the call to rv32i::decode() then STUB to treat all instructions illegal 
- Add each instruction OPCODE starting with LUI
- Write the get_xxx() methods as NEEDED.
- EXTRACT the field data in get_xxx() methods by using bitwise &, | , or SHIFT operators 
- Implement and test ONE OPCODE at a time using the REFERENCE CARD and the DIAGRAMS showing how they are DECODED in RISC-V manual
- Do U-type and R-type FIRST that appear in tinyprog.bin example before the REST OF THEM 
***
***
# rv32i.h and rv32i.cpp
# Member Variables:

#### rv32i class must include memebers below and DOCUMENTATION

### rv32i.h:
### memory * mem is a pointer to a memory object, used by disassembler to fetch instructions
***
### uint32_t pc Is the PROGRAM COUNTER (PC) which keeps track of what memory ADDRESS we are currently ON. ( THE INSTRUCTION BEING DECODED) When decoding instructions that refer to the PC register to calculate a TARGET ADDRESS , use this value when calculating memory addresses that appear in the OPERANDS
# INITALIZE PC TO ZERO 0 
*** 
### static constexpr uint32_t XLEN = 32;
### XLEN represents the number of bits in CPU registers
***
### NOTE
### Define additional constants along lines of XLEN such as OPCODE, FUNCT3, and FUCNT7 values with appropriate WIDTHS. ( THERES A TEST FILE WITH THESE)
***
# MEMBER FUNCTIONS
### rv32i(memory *m) saves the m argument in the mem member variable for use later when disassembling

### void disasm(void) will be used to DISASSEMBLE the instructions in the simulated memory.

# TO DO THIS:
- Set PC = 0 , for each 32-bit word in memory:
    - print 32-bit HEX address IN the PC register
    - FETCH the 32-bit instruction form memory AT the address in the PC register
    - Print the instruction as a 32-bit HEX value
    - pass the fetched instruction to decode() to DECODE and render as a string
    - print the DECODED instruction STRING returned from decode()
    - increment PC by 4 ( POINT TO NEXT INSTRUCTION)
- Continue until you have feched, decoded, and printed every word from your simulated memory.

### std::string decode(uint32_t insn) const
### This function must handle ANY insn value
### The function should return a tring containing the disassembled instruction text, THIS FUNCITON DOES NOT PRINT
 
### This is done: with a SWITCH statment. For this function, use the value of the OP CODE extracted by get_opcode(insn) for the SWITCH expression! 

### For each switch case, format the instruction and its arguments ( different for I types! ) or use a sub-switch ( for I types ) to decode stuff like funct3 and then format the decoded instruction

### For INVALID instrucitons return a string with error message: RRROR: UNIMPLEMENTED INSTRUCTION

### For each UNIQUE OP CODE value, the instruciton format is the same. ALL OF THE store instructions have the same exact OP CODE. Differeing only in mnemonic. String format should take advantage of this. 

## If you factor ALL instruction formatting it'll be easier to reuse, 
