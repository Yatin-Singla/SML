#include "Simpletron.h"

void Simpletron::Run_App(void)
{
	welcome();
	system("pause");
	program();
	system("pause");
	halt();
	end();
}

//constructor
Simpletron::Simpletron()
{
	for (int i = 0; i < 100; i++)
	{
		Memory[i] = 0;
	}
	//assigning the key
	Operation[READ] = &Simpletron::read;
	Operation[WRITE] = &Simpletron::write;
	Operation[LOAD] = &Simpletron::load; 
	Operation[STORE] = &Simpletron::store;
	Operation[ADD] = &Simpletron::add;
	Operation[SUBTRACT] = &Simpletron::subtract;
	Operation[DIVIDE] = &Simpletron::divide; 
	Operation[MULTIPLY] = &Simpletron::multiply;
	Operation[BRANCH] = &Simpletron::branch;
	Operation[BRANCHNEG] = &Simpletron::branchneg;
	Operation[BRANCHZERO] = &Simpletron::branchzero; 
	Operation[HALT] = &Simpletron::halt;

	inputfile.open("input.txt");
}

//welcome function and provides the user with information they will need to know in order to use the program
void Simpletron::welcome(void)
{
	cout << "*** Welcome to Simpletron! ***" << endl;
	cout << "*** Please enter your program one instruction ***" << endl;
	cout << "*** (or data word) at a time. I will type the ***" << endl;
	cout << "*** location number and a question mark (?). ***" << endl;
	cout << "*** You then type the word for that location. ***" << endl;
	cout << "*** Type the sentinel -99999 to stop entering ***" << endl;
	cout << "*** your program. ***" << endl;
	cout << endl;
}

//print the end message and lets the user know that program has started executing
void Simpletron::end(void)
{
	cout << endl;
	cout << "*** Program loading completed ***" << endl;
	cout << "*** Program execution begins ***" << endl;
}

//informs the user that the simpletron is finished executing th eprogram.
void Simpletron::halt(void)
{
	cout << endl;
	cout << "*** Simpletron execution terminated ***" << endl;

	cout << "REGISTERS:" << endl;

	//accumulator
	cout << "accumulator               " << showpos << setfill('0') << internal << setw(5);
			cout  << accumulator << endl;

	//instructionCOunter
	cout << "instructorCounter            " << noshowpos << setfill('0') << internal << setw(2);
	cout << instructionCounter << endl;

	//InstructionRegister
	cout << "instructorRegister        " << showpos << setfill('0') << internal << setw(5);
	cout << InstructionRegister << endl;

	//Operation
	cout << "operationCode                " << noshowpos << setfill('0') << internal << setw(2);
	cout << OperationCode << endl;

	//operation Code
	cout << "operand                      " << noshowpos << setfill('0') << internal << setw(2);
	cout << Operand << endl;
	cout << endl;
	cout << "MEMORY:" << endl;

	cout << "        0      1      2      3      4      5      6      7      8      9" << endl;
	for (int i = 0; i < 100 ; i = i + 10)
	{
		cout << std::noshowpos << std::setfill(' ') << setw(2) << i << "  ";
		for (int j = 0; j < 10; ++j)
		{
			cout << showpos;
			cout << setfill('0') << internal << setw(5) << Memory[i + j];
			cout << "  ";
		}
		cout << endl;
	}
}

void Simpletron::read(void)//number represents where in memory location
{
	//some kind of check if memory is not corrupted, available, inbounds?
	while (Memory[Operand] >= -9999 && Memory[Operand] <= 9999)
	{
		//no reprompt message
		cin >> Memory[Operand];
	}
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

void Simpletron::store(void)
{
	Memory[Operand] = accumulator;
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

//figures out which function to call and what to after everything has been gathered
void Simpletron::program(void)
{
	cout << endl;
	cout << "Press 1 to manually enter the commands else press 2 to enter commands from a file.\n";
	int var = 0, i = 0, choice = 0;
	cin >> choice;
	while (i < 100 && var != -99999)
	{
		if (i < 10)
		{
			cout << noshowpos << setfill('0') << setw(2) << i << " ? ";
		}
		else
		{
			cout << noshowpos << i << " ? ";
		}
		if (choice == 1)
		{
			cin >> var;
		}
		else
		{
			inputfile >> var;
			cout << showpos << internal << setw(5) << var << endl;
			_sleep(1000);
		}
		Memory[i] = var;
		i++;
	}
	system("pause");
	execute();

}

void Simpletron::branch(void)
{
	instructionCounter = Operand;
	//InstructionRegister = Memory[instructionCounter];
}

void Simpletron::branchneg(void)
{
	if (accumulator < 0)
	{
		instructionCounter = Operand;
	}
}

void Simpletron::branchzero(void)
{
	if (accumulator == 0)
	{
		instructionCounter = Operand;
	}
}

void Simpletron::execute(void)
{
	//grabs the word from the memory and is copied into the register so that it can be processed.
	while (OperationCode != 43)
	{
		setInstructionRegister();
		setOperand();
		setOperationCode();
		Operation[OperationCode];
		if (OperationCode != 40 && OperationCode != 41 && OperationCode != 42)
		{
			instructionCounter++;
		}
	}
}
//error checking



