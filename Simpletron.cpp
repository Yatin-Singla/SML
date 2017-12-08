#include "Simpletron.h"

//welcome function and provides the user with information they will need to know in order to use the program
void Simpletron::welcome(void)
{
	cout << "*** Welcome to Simpletron! ***" << endl;
	cout << "*** Please enter your program one instruction ***" << endl;
	cout << "*** (or data word) ata a time. I will type the ***" << endl;
	cout << "*** location number and a question mark (?). ***" << endl;
	cout << "*** You then type the word for that location. ***" << endl;
	cout << "*** Type the sentinel -99999 to stop entering ***" << endl;
	cout << "*** your program." << endl;
}

//print the end message and lets the user know that program has started executing
void Simpletron::end(void)
{
	cout << "*** Program loading completed ***" << endl;
	cout << "*** Program execution begins ***" << endl;
}

//informs the user that the simpletron is finished executing th eprogram.
void Simpletron::halt(void)
{
	cout << "*** Simpletron execution terminated ***" << endl;

	cout << "REGISTERS:" << endl;
	cout << "accumulator               " << accumulator << endl;
	cout << "instructorCounter         " << instructionCounter <<endl;
	cout << "instructorRegister        " << InstructionRegister <<endl;
	cout << "operationCode             " << OperationCode << endl;
	cout << "operand                   " << Operand << endl;
	cout << endl;
	cout << "MEMORY:" << endl;

	cout << "        0      1      2      3      4      5      6      7      8      9" << endl;
	for (int i = 0; i < 100 ; i = i + 10)
	{
		if(i > 9)
		{
			cout << std::noshowpos << i << "  ";
		}
		else
		{ 
			cout << std::noshowpos << std::setfill('0') << std::internal << i << "  ";
		}
		for (int j = 0; j < 10; ++j)
		{
			cout << showpos;
			// setfill( '0' )
			cout << Memory[i + j];
			cout << "  ";
		}
		cout << endl;
	}

}

void Simpletron::read(void)//number represents where in memory location
{
	//some kind of check if memory is not corrupted, available, inbounds?
	cin >> Memory[Operand];
}

//writes to the output screen
void Simpletron::write(void)
{
	cout << Memory[Operand];
}

//loads the data into the accumulator
void Simpletron::load(void)
{
	accumulator = Memory[Operand];
}

void Simpletron::add(void)
{
	accumulator += Memory[Operand];
}

void Simpletron::subtract(void)
{
	accumulator -= Memory[Operand];
}

void Simpletron::divide(void)
{
	accumulator /= Memory[Operand];
}

void Simpletron::multiply(void)
{
	accumulator *= Memory[Operand];
}

//setters
void Simpletron::setInstructionRegister(void)
{
	InstructionRegister = Memory[instructionCounter];
}

void Simpletron::setOperationCode(void)
{
	OperationCode = InstructionRegister / 100;
}

void Simpletron::setOperand(void)
{
	Operand = InstructionRegister % 100;
}

void Simpletron::Run_App(void)
{
	halt();
}

Simpletron::Simpletron()
{
	for (int i = 0; i < 100; i++)
	{
		Memory[i] = 0;
	}
}
