This project has been created as part of the 42 curriculum by mnestere and ksmailov.

### Description
* Push_swap — a program that sorts data on a stack using a limited set of instructions and aims to achieve the lowest possible number of operations.

### Instructions
* To run the program, you need to use one of the following commands in the terminal:
  * make
  * make all
  * make push_swap
* Then run the executable file push_swap with a stack as a parameter to be sorted.
* There are several flags implemented to choose the sorting algorithm or to enable benchmark:
  * --simple     Forces the use of the O(n²) algorithm.
  * --medium     Forces the use of the O(n√n) algorithm.
  * --complex    Forces the use of the O(n log n) algorithm.
  * --adaptive   Forces the use of the adaptive algorithm based on disorder.
* If no flag is given, the --adaptive mode is used by default.
* The program displays the smallest possible operations required to sort stack_a with the smallest number being at the top.
* Operations are separated by a newline (\n).
* If no parameters are specified, the program doesn't display anything and will return the prompt.
* In case of error, it displays Error on stderr.

### Errors include
* Arguments that are not integers.
* Integers outside the valid range.
* Duplicate values.

### Benchmark mode (--bench)
* When using the benchmark mode, the program will display (after sorting):
  * The computed disorder (in %, with two decimals).
  * The name of the strategy used and its theoretical complexity class.
  * The total number of operations.
  * The count of each operation type (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr).
  * The benchmark output is sent to stderr and only appears when the flag is present.

### Example usage
* ./push_swap --simple --bench <numbers>
* ARG="4 67 3 87 23"; ./push_swap --complex $ARG

### Resources
* GeeksforGeeks — for researching and understanding sorting algorithms.
* YouTube videos — as a reference for algorithm explanation and implementation ideas.
* Push Swap Visualizer — to visualize and debug stack operations in real time using a graphical interface.
* AI assistance — used for code analysis during development and also provided suggestions to help implement algorithms.

### Algorithm Explanation and Justification

#### O(n²) Algorithm – Implemented by mnestere.
* Simple, bubble-sort-like approach for small stacks.
* Swaps and pushes elements until sorted.
* Ideal for small inputs: easy to implement and debug.

#### O(n√n) Radix Sort – Implemented by ksmailov.
* Sorts elements based on their binary indices, moving them between stacks by bit position.
* Efficient for large stacks, ensuring a low number of operations.

#### O(n log n) Improved Chunk Sort – Implemented by ksmailov.
* Divides the stack into chunks, moves them strategically, and reintegrates efficiently.
* Balances speed and operation count for medium-sized stacks.

## Contributions

### Kaisar Smailov (ksmailov)
* Implemented O(n√n), O(n log n) sorting algorithms.
* Developed core stack operations and instruction logic.
* Integrated benchmarking and performance metrics.
* Led optimization and performance improvements across the project.
* Provided key architectural decisions and advanced algorithmic strategies.

### Matvii Nesterenko (mnestere)
* Developed the O(n²) sorting algorithm.
* Implemented and debugged data parsing.
* Participated in algorithm testing, analysis, and validation.
* Contributed to project structure and documentation.