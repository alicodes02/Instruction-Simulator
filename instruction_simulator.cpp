#include <iostream>
using namespace std;

struct Instruction {
    int optCode;
    int operand1;
    int operand2;

    Instruction(int optCode, int operand1, int operand2) {
        this->optCode = optCode;
        this->operand1 = operand1;
        this->operand2 = operand2;
    }

    Instruction() {
        optCode = -99;
        operand1 = 0;
        operand2 = 0;
    }

    void print() {
        std::cout << "OPT Code = " << optCode << endl;
        std::cout << "Operand1 = " << operand1 << endl;
        std::cout << "Operand2 = " << operand2 << endl;
    }
};

struct CPU {
    Instruction *registers[4];
    int programCounter;

    CPU() {
        programCounter = 0;
    }

    void print() {
        std::cout << "Program Counter = " << programCounter << endl;
        Instruction instruction = *(registers[programCounter]);
        instruction.print();
    }
};

void fetch(Instruction memory[], CPU* cpu) {

    cout << "Executing Fetch..." << endl;
    int pc = cpu->programCounter;
    cpu->registers[pc] = &memory[pc];
}

void decode(CPU* cpu, Instruction memory[]) {
    
    Instruction* currentInstruction = (cpu->registers[cpu->programCounter]);

    cout << "Executing Decode..." << endl;

    int optCode = currentInstruction->optCode;
    int operand1 = currentInstruction->operand1;
    int operand2 = currentInstruction->operand2;
}


bool execute(CPU* cpu, Instruction memory[]) {

    if (cpu->programCounter < 0 || cpu->programCounter >= 4) {
        std::cout << "Program Counter out of bounds, exiting..." << endl;  // since number of registers are only 4.
        return false;
    }

    cout << "Executing Instruction" << endl;

    Instruction* currentInstruction = (cpu->registers[cpu->programCounter]);
    int optCode = currentInstruction->optCode;
    int operand1 = currentInstruction->operand1;
    int operand2 = currentInstruction->operand2;

    switch (optCode) {
        case 0: // ADD optcode
            operand1 = operand2 + operand1;
            // Update the operands in the instruction
            currentInstruction->operand1 = operand1;
            currentInstruction->operand2 = 0; // Clear operand2 as it's not used anymore
            break;

        case 1: // SUB optcode
            operand1 -= operand2;
            currentInstruction->operand1 = operand1;
            currentInstruction->operand2 = 0; // Clear operand2 as it's not used anymore
            break;
        case 2: // MULT optcode
            operand1 *= operand2;
            currentInstruction->operand1 = operand1;
            currentInstruction->operand2 = 0; // Clear operand2 as it's not used anymore
            break;
        case -1: // HALT optcode
            std::cout << "Halt Instruction Executed" << endl;
            return false;
        default:
            std::cout << "Unknown opcode: " << optCode << endl;
            break;
    }

    cpu->programCounter++;

    return true;
}


int main() {

    CPU cpu;

    const int ADD = 0;
    const int SUB = 1;
    const int MULT = 2;
    const int DIV = 3;
    const int HALT = -1; // defined constant optcodes for multiple operations.

    // building a program by making a series of instructions....

    Instruction memory[4] = {
        Instruction(ADD, 7,4),
        Instruction(SUB, 10, 5),
        Instruction(MULT, 2, 3),
        Instruction(HALT, 0, 0)
    };
    
    // initial memory state...
    std::cout << "initial memory state..." << endl;

    for (int i = 0; i < 4; i++) {
        std::cout << "Instruction #" << i + 1 << " :";
        memory[i].print();
    }

    // executing loop for fetch, decode, and execute process.
    std::cout << "Now Executing Fetch, Decode & Execute Process" << endl;

    while (1) {

        fetch(memory, &cpu);
        decode(&cpu,memory);

        std::cout << "Cpu Registers Content : ";
        cpu.print();

        std::cout << "Memory State..." << endl;

        for (int i = 0; i < 4; i++) {
            std::cout << "Instruction #" << i + 1 << " :";
            memory[i].print();
        }

        int status = execute(&cpu, memory);

        if (status ==  false) { // false means halt statement is executed
            break;
        }
    }

    std::cout << "Final Memory State..." << endl;

        for (int i = 0; i < 4; i++) {
            std::cout << "Instruction #" << i + 1 << " :";
            memory[i].print();
        }

    return 0;
}
