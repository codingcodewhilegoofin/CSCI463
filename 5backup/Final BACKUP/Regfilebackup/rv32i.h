 //***********************************************************************************
 //*
 //* 	rv32i.h
 //*	CSCI 463 Assignment 5
 //*
 //* 	Giovanni Moscato Z1820207
 //*
 //*	Memory Simulator
 //* 	Instructor: John Winans
 //* 	Section: -0001
 //*
 //***********************************************************************************

#ifndef RV32I_H
#define RV32I_H

#include "memory.h"
#include "registerfile.h"

class rv32i
{	
	public:

        // Constructors 
		rv32i(memory *m);

        // Deconstructors 
        ~rv32i();

        // More standard member functions 
		void disasm(void);
        std::string decode(uint32_t insn) const;

        // Getter functions
        static uint32_t get_opcode(uint32_t insn);  
        static uint32_t get_rd(uint32_t insn);
        static int32_t get_imm_u(uint32_t insn);
        static uint32_t get_funct3(uint32_t insn);	
		static uint32_t get_rs1(uint32_t insn);		
		static uint32_t get_rs2(uint32_t insn);		
		static uint32_t get_funct7(uint32_t insn);	
        static int32_t get_imm_i(uint32_t insn);
        static int32_t get_shamt_i(uint32_t insn);
        static int32_t get_imm_s(uint32_t insn);
        static int32_t get_imm_b(uint32_t insn);
        static int32_t get_imm_j(uint32_t insn);

        // Personnal getter functions 
        static uint32_t get_e(uint32_t insn);
        static std::string get_pred(uint32_t insn);
        static std::string get_succ(uint32_t insn);

        // Instrucion formating render functions  
        // Default 
        std::string render_illegal_insn() const;

        // U type 
        std::string render_lui(uint32_t insn) const;
        std::string render_auipc(uint32_t insn) const;

        // R type
        std::string render_rtype(uint32_t insn, const char *mnemonic) const;

        // I type
        std::string render_jalr(uint32_t insn) const;
        std::string render_itype_load(uint32_t insn, const char *mnemonic) const; // Type 1
        std::string render_itype_alu(uint32_t insn, const char *mnemonic, int32_t imm_i) const; // Type 2

        // S type 
        std::string render_stype(uint32_t insn, const char *mnemonic) const;

        // B type 
        std::string render_btype(uint32_t insn, const char *mnemonic) const;

        // J type 
        std::string render_jal(uint32_t insn) const;

        // E type 
        std::string render_etype(uint32_t insn, const char *mnemonic) const;

        // FENCE 
        std::string render_fence(uint32_t insn) const;

        // New switch statment similar to dcode
        void dcex(uint32_t insn, std::ostream*);

        // Called by dcex
        void exec_illegal_insn(uint32_t insn, std::ostream* pos);

        // ACCESSORS
        bool is_halted() const;

        // MUTATORS
        // Set functions for instructions
        void set_show_instructions(bool b);

        // Set functions for instructions
        void set_show_registers(bool b);
        void set_dissasembly(bool b);
        void set_show_dump_mem(bool b);
        void set_limit(bool b);


        // Instruction EXECution functions

        // U type 
        void exec_lui(uint32_t  insn , std:: ostream* pos); 
	    void exec_auipc(uint32_t  insn , std:: ostream* pos); 

        // J type 
	    void exec_jal(uint32_t  insn , std:: ostream* pos); 

        // B type
	    void exec_beq(uint32_t  insn , std:: ostream* pos); 
	    void exec_bne(uint32_t  insn , std:: ostream* pos); 
	    void exec_blt(uint32_t  insn , std:: ostream* pos); 
	    void exec_bge(uint32_t  insn , std:: ostream* pos); 
	    void exec_bltu(uint32_t  insn , std:: ostream* pos); 
	    void exec_bgeu(uint32_t  insn , std:: ostream* pos); 

        // I type Special 
        void exec_jalr(uint32_t  insn , std:: ostream* pos); 

        // I type 1 
	    void exec_lb(uint32_t  insn , std:: ostream* pos); 
	    void exec_lh(uint32_t  insn , std:: ostream* pos); 
	    void exec_lw(uint32_t  insn , std:: ostream* pos); 
	    void exec_lbu(uint32_t  insn , std:: ostream* pos); 
	    void exec_lhu(uint32_t  insn , std:: ostream* pos); 

        // I type 2 
	    void exec_addi(uint32_t  insn , std:: ostream* pos); 
	    void exec_slti(uint32_t  insn , std:: ostream* pos); 
	    void exec_sltiu(uint32_t  insn , std:: ostream* pos); 
	    void exec_xori(uint32_t  insn , std:: ostream* pos); 
	    void exec_ori(uint32_t  insn , std:: ostream* pos); 
	    void exec_andi(uint32_t  insn , std:: ostream* pos); 
	    void exec_slli(uint32_t  insn , std:: ostream* pos); 
	    void exec_srli(uint32_t  insn , std:: ostream* pos); 
	    void exec_srai(uint32_t  insn , std:: ostream* pos); 

        // S type 
	    void exec_sb(uint32_t  insn , std:: ostream* pos); 
	    void exec_sh(uint32_t  insn , std:: ostream* pos); 
	    void exec_sw(uint32_t  insn , std:: ostream* pos); 

        // R type
	    void exec_add(uint32_t  insn , std:: ostream* pos); 
	    void exec_sub(uint32_t  insn , std:: ostream* pos); 
	    void exec_sll(uint32_t  insn , std:: ostream* pos); 
	    void exec_slt(uint32_t  insn , std:: ostream* pos); 
	    void exec_sltu(uint32_t  insn , std:: ostream* pos); 
	    void exec_xor(uint32_t  insn , std:: ostream* pos); 
	    void exec_srl(uint32_t  insn , std:: ostream* pos); 
	    void exec_sra(uint32_t  insn , std:: ostream* pos); 
	    void exec_or(uint32_t  insn , std:: ostream* pos); 
	    void exec_and(uint32_t  insn , std:: ostream* pos); 

        // Other
        void exec_ebreak(uint32_t  insn , std:: ostream* pos); 
        void exec_ecall(uint32_t  insn , std:: ostream* pos); 
        void exec_fence(uint32_t  insn , std:: ostream* pos); 


        // Reset the object and registerfile 
        void reset();
        // Dump the state of hart 
        void dump() const;
        // List of things to do 
        void tick();
        // run method 
        void run(uint64_t limit);

        
    private:

        memory * mem;	// Pointer to memory object 
		uint32_t pc = 0;	// Initalize pc value 
		static constexpr uint32_t XLEN = 32; // 32 bit system

        // ASSN 5
        registerfile regs; // Registerfile object to access methods

        // Flags 

        bool halt = false;
        bool show_instructions = false; // i
        bool show_registers = false; // r

        bool show_dissasembly = false; // d
        bool show_dump_mem = false; // z
        bool limit = false; // l
      
        uint64_t insn_counter;
        
        // Additional constants
        static constexpr int mnemonic_width = 8; // mnemonic width helps with formating 
        static constexpr int instruction_width = 35;// The instruction width is used later 

        // U type opcodes
        static constexpr uint32_t opcode_lui = 0b0110111;
        static constexpr uint32_t opcode_auipc = 0b0010111;

        // R type opcode
        static constexpr uint32_t opcode_rtype = 0b0110011;

        // I type opcode
        static constexpr uint32_t opcode_jalr = 0b1100111;
        static constexpr uint32_t opcode_itype1 = 0b0000011;
        static constexpr uint32_t opcode_itype2 = 0b0010011;
       
        // S type opcode
        static constexpr uint32_t opcode_stype = 0b0100011;

        // B type opcode
        static constexpr uint32_t opcode_btype = 0b1100011;

        // J type opcode 
        static constexpr uint32_t opcode_jal = 0b1101111;

        // Ecall and ebreak 
        static constexpr uint32_t opcode_e = 0b1110011;

        // fence
        static constexpr uint32_t opcode_fence = 0b0001111;
        
};

#endif