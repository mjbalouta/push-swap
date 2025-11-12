# Push_swap
## A sorting algorithm

This project's purpose is to sort data using a limited set of instructions, aiming to achieve the lowest possible number of actions. To succeed, it is needed to understand and work with various algorithms and choose the most appropriate one for optimized data sorting.

### How to use:
1) Inside the directory you want: `git clone https://github.com/mjbalouta/push-swap.git`

2) Type `make` to compile the project

3) Execute the program with `./push_swap` followed by a set of numbers like `6 8 1 4 3 2`

4) And then you'll get the operations that were used to sort the set of numbers you chose.

### Rules

1) You have 2 stacks named a and b.

2) In order to sort the stack, you have the following operations at your disposal:
- sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one element or none.
- sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one element or none.
- ss: sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
- pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
- ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
- rrr : rra and rrb at the same time.

### Some notes from my Notebook:

**SORTING ALGORITHMS**:  
  
There are 2 categories:
- Comparison-based sorting (elements are compared with each other);
- Non-comparison sorting (use properties of the elements).
  

*EXAMPLES OF SORTING ALGORITHMS*
- <u>Bubble Sort</u>: inefficient (easy, but slow for large input);
- <u>Insertion Sort</u>: fast for small or nearly sorted data;
- <u>Selection Sort</u>: not efficient for large data sets;
- <u>Merge Sort</u>: uses extra memory, but very stable and predictable;
- <u>Quick Sort</u>: fast, but unstable, not ideal when memory is constrained;
- <u>Radix Sort</u>: efficient for sorting integers or fixed-length strings. (**the chosen one**)

**RADIX SORT**

- non-comparison based sorting;
- sorts numbers by processing individual digits (from least significant to most significant);
- works best when sorting integers;
- doesn't rely on operations and comparisons - it sorts the numbers based on their binary representation.

  
Radix is very efficient for large input sizes (like 100 or 500 elements), but for small inputs, it requires too many operations compared to other approaches. So, for 2, 3, 4 or 5 elements I used a different approach.

  
<u>For 2 elements</u>:
- Used just **sa** if the numbers are out of order;
  
<u>For 3 elements</u>:
- Used if's and **sa** + **rra** logic;
  
<u>For 4 or 5 elements</u>:
- Tracked the smallest element of the stack and pushed it to stack B;
- Sorted the remaining and then pushed back the smallest from B.

