# Push-Swap

We have 2 stacks named A and B
### Start 
A contains a random number of either positive or negative numbers without any duplicates. B is empty

### Goal
Sort this numbers in ascending order into stack A

### Authorized operation
* sa: swap the first 2 elements at the top of stack A
* sb: swap the first 2 elements at the top of stack B
* ss: sa and sb at the same time
* pa: take the first element at the top of B and put it at the top of A
* pb: take the first element at the top of A and put it at the top of B
* ra: shift up all elements of stack A by 1: first element becomes the last one
* rb: shift up all elements of stack B by 1: first element becomes the last one
* rr: ra and rb at the same time
* rra: shift down all elements of stack a by 1: last element becomes the first one
* rrb: shift down all elements of stack b by 1: last element becomes the first one
* rrr: rra and rrb at the same time

### There are two executable
-  push_swap receive as an argument the stack of integers. Program must display the list of instructions to sort the stack A,
the smallest number being at the top
- checker program check if the list of instructions generate with the program push_swap is actually sorting the stack properly.
If after executing those instructions, stack a is actually sorted checker display "OK".
In other case, checker must display "KO" followed

### To get started
1. Clone git repo: git clone git@github.com:Abra19/push-swap.git
2. Compile: make all
3. Running an executables `./push_swap` and `./checker`  with -help option will show possible ways to run the program
4. Running with random args: 

   `ARG=`ruby -e "puts (0..30).to_a.shuffle.join(' ')"` && ./push_swap $ARG | ./checker $ARG`

5. Running with visualisation of sorting process:

   `ARG=`ruby -e "puts (0..30).to_a.shuffle.join(' ')"` && ./push_swap $ARG | ./checker -m $ARG`
