# Instruction Simulator

## Overview

This is a simple C++ program that simulates the instruction life cycle of a simplified computer architecture. It implements a fetch-decode-execute cycle to execute a series of instructions with different op codes.

## How to Compile and Run

1. **Compile the Program**:
   Open a terminal and navigate to the directory containing the `instruction_simulator.cpp` file. Then, compile the program using g++ (GNU Compiler for C++):

   ```bash
   g++ -o instruction_simulator instruction_simulator.cpp
   ```

2. **Run the Program**:
   After compiling successfully, you can run the program by executing the following command:

   ```bash
   ./instruction_simulator
   ```

3. **View the Output**:
   The program will execute the fetch-decode-execute cycle for a series of sample instructions and display the state of the CPU and memory at each step. You will see the output in the terminal.

## Op Codes

The program defines the following op codes to represent different operations:

- `0`: ADD
- `1`: SUB
- `2`: MULT
- `-1`: HALT

## Memory Layout

The program uses an array to represent the memory of the computer. In this case, the memory contains four instructions, each with an op code, operand1, and operand2. Here's the memory layout:

1. `Instruction(ADD, 7, 4)`
   - Op Code: 0 (ADD)
   - Operand1: 7
   - Operand2: 4

2. `Instruction(SUB, 10, 5)`
   - Op Code: 1 (SUB)
   - Operand1: 10
   - Operand2: 5

3. `Instruction(MULT, 2, 3)`
   - Op Code: 2 (MULT)
   - Operand1: 2
   - Operand2: 3

4. `Instruction(HALT, 0, 0)`
   - Op Code: -1 (HALT)
   - Operand1: 0
   - Operand2: 0

## Sample Programs

The program includes two sample programs:

1. **Program 1**:
   - Calculates the result of adding 7 and 4, subtracting 5 from the result, and finally multiplying the result by 3 and then halts.

## Program Execution

The program executes the fetch-decode-execute cycle as follows:

- **Fetch**: Fetches the next instruction from memory.
- **Decode**: Determines the operation to be performed based on the op code.
- **Execute**: Performs the operation and updates the program state accordingly.

You will see the CPU's program counter, registers, and memory contents displayed at each step of the cycle.

## Output

The program will display the following output in the terminal:

- Initial memory state with the contents of the instructions.
- Execution of each fetch, decode, and execute cycle with the CPU and memory states.
- A message indicating the execution of the halt instruction.
- Final memory state after executing all instructions.

Feel free to modify the memory layout or add more instructions to test different scenarios. Enjoy exploring the instruction simulator!
