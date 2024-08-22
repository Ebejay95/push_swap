![pushswap img](https://raw.githubusercontent.com/Ebejay95/push_swap/master/push_swap.gif)
# push_swap

**A project to sort a stack using a limited set of operations in C.**

This project implements a sorting algorithm for a stack, using only a specified set of operations, with the goal of doing so in the fewest moves possible. It showcases algorithmic thinking, efficient stack manipulation, and the ability to work with constraints.

## Structure

### shared/

The `shared` directory contains utility functions and data structures shared across different parts of the project:

- **stack_operations.c**: Implements basic operations like `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, and `rrr` to manipulate the stacks.
- **stack_utils.c**: Includes helper functions for stack management, such as initializing stacks, checking sorted status, and error handling.
- **input_parsing.c**: Functions for parsing and validating the input, ensuring correct stack initialization.

### project/

The `project` directory contains the core algorithm implementation:

- **push_swap.c**: The main function that drives the sorting process, determining the optimal sequence of operations.
- **sorting_algorithms.c**: Implements various sorting techniques depending on the size of the stack, including simple sorting for small stacks and more complex algorithms for larger ones.
- **move_optimizer.c**: Contains logic to optimize the sequence of operations, minimizing the total number of moves required.

### push_swap.h

The header file declares the prototypes for all functions and defines necessary macros, ensuring proper linkage between the shared utilities and the core algorithm.

### Makefile

The Makefile automates the build process, compiling all source files and linking them to create the final executable.

## Features

- **Stack Sorting**: Efficiently sorts a stack of integers with a limited set of operations.
- **Input Validation**: Robust input parsing and error handling to ensure correct initial conditions.
- **Operation Optimization**: Minimizes the number of moves required to sort the stack.

## Usage

To compile the project, run:

```bash
make
