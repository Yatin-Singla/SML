#pragma once
#include "Tydef.h"


class Simpletron
{
public:
	//constructor
	Simpletron();
	//runs the app
	void Run_App(void);
	 

private:
	std::array<int, 100> Memory;
	
	//keeps track of the location in memory that contains the instruction being performed.
	int instructionCounter = 0;//keeps track of the location in memory that contains the instruction being performed
	/*Stores the location we are on at the time - what instruction we are on*/

	int accumulator = 0;//represenst accumulator register
	int OperationCode = 0; //opreation currently being performed
	int Operand = 0; //indicates the memory location on which current instruction operates
	int InstructionRegister = 0;//we donot execute instructions directly from memory therefore we rather transfer the NEXT instruction to be performed from the memory to a variable
	/*Instruction to be performed next so basically the whole word for the instruction*/

	void welcome(void);	
	
	void end(void);
	
    //to my understanding - returns a pointer to a function
	//typedef int(*function)();
	//std::map<int, function()> Operation;

	void read(void);//number represents where in memory
	void write(void);
	void load(void);
	void add(void);
	void subtract(void);
	void divide(void);
	void multiply(void);
	
	//transfer-of-control operations
	void branch(void);
	void branchneg(void);
	void branchzero(void);
	void halt(void);/*Register and memory dump*/

	//setters
	void setInstructionRegister(void);
	void setOperationCode(void);
	void setOperand(void);

	void program(void);

};