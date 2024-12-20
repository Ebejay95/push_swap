# push_swap

**Because `Swap_push` isn’t as natural!**

![pushswap img](https://raw.githubusercontent.com/Ebejay95/push_swap/master/push_swap.gif)

## Summary

The **push_swap** project challenges you to sort data on a stack using a limited set of operations. The objective is to achieve the sorting with the fewest moves possible. This project tests your algorithmic thinking, stack manipulation skills, and your ability to work efficiently within constraints.

---

## Features

### Core Functionality

- **Two Stacks**: Operates with `stack a` (unsorted input) and `stack b` (auxiliary).
- **Sorting Operations**:
  - `sa`, `sb`, `ss`: Swap the first two elements of a stack.
  - `pa`, `pb`: Push an element from one stack to the other.
  - `ra`, `rb`, `rr`: Rotate a stack (move the first element to the bottom).
  - `rra`, `rrb`, `rrr`: Reverse rotate a stack (move the last element to the top).
- **Optimized Sorting**:
  - Minimal instructions to sort integers in ascending order on `stack a`.
- **Robust Input Handling**:
  - Validates that all arguments are integers, checks for duplicates, and ensures values fit within the `int` range.

### Bonus Features

- **Checker Program**:
  - Validates if the instructions generated by `push_swap` properly sort the stack.
- **Flags and Benchmarking**:
  - Efficiently handles small and large stacks (e.g., ≤700 operations for 100 integers, ≤5500 for 500 integers).

---

## Structure

### Directories

#### `shared/`

- **`stack_operations.c`**:
  Implements stack manipulation commands (e.g., `sa`, `pa`, `rra`).
- **`stack_utils.c`**:
  Functions for initializing stacks, checking if a stack is sorted, and error handling.
- **`input_parsing.c`**:
  Ensures valid input and sets up the initial `stack a`.

#### `project/`

- **`push_swap.c`**:
  Drives the sorting process and determines the optimal operation sequence.
- **`sorting_algorithms.c`**:
  Implements sorting strategies tailored for small and large stacks.
- **`move_optimizer.c`**:
  Minimizes the total number of operations.

### Key Files

- **`push_swap.h`**: 
  Includes function prototypes, macros, and shared definitions.
- **Makefile**:
  Automates compilation with targets for building, cleaning, and handling bonuses.

---

## Example Usage

1. **Compile the Project**:
   ```bash
   make
