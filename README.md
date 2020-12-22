# RISC-V RV32i simulator

This repository has a few projects in it. 

- Project 1 

One of the projects seen in this repository is a Hex32bit converter. This converter will take any valid number given to it and convert it to IEE-754 format for the user.  

- Project 2

A few of the folders here show the process of how the RISCV simulator was created starting with the sim. The project was built iteratively and the final result includes register files. 

## RV32i simulator explanation:

RISC-V is a instruction set architecture in which i based this simulator on. It simulates hardware components, memory, and decoding/encoding/execution of instructions given to the simulator via binary files. The simulator begins by waiting for user input and giving an appropriate usage message. The user has an array of options available to run the simulation including several dump functions, memory size limits, and instruction size limitations. 

Once the user has defined options they would like to use and given a binary file the simulator will allocate the appropriate memory size needed. It will continue to manage this memory as the simulation continues. Afterwards the file is read and decoded, and the instructions are either recongized and dumped or executed based on user option commands. The simulation also interacts with a registerfile which has simulated GPR's to hold and execute the instructions. The code is based on real architeture and so it has many functions including a tick() function to simulate a working computer clock that will sync instructions. 
