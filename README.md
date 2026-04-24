*This project has been created as part of the 42 curriculum by kkhant-z*

# Description
`push_swap` is a 42 project that sorts a stack of integers using a limited set of operations: push, swap, and rotate across two stacks (A and B). The goal is to sort stack A in ascending order with the fewest possible moves. This implementation uses a sliding window chunking strategy combined with the Turk algorithm — normalizing values into ranks, pushing elements to stack B in ordered chunks, then greedily inserting them back into A at the lowest rotation cost.

# Instructions
### Compilation
```
make
```
### Compilation (with Bonus)
```
make bonus
```
### Re-compilation
```
make re
make re_bonus
```
Other Valid ```make``` commands - ```clean``` ```fclean```
### Testing push_swap
100 Random Numbers
```
ARG=$(python3 -c "import random; nums=random.sample(range(-1000, 1000), 100); print(' '.join(map(str, nums)))"); ./push_swap $ARG | wc -l
```
500 Random Numbers
```
ARG=$(python3 -c "import random; nums=random.sample(range(-5000, 5000), 500); print(' '.join(map(str, nums)))"); ./push_swap $ARG | wc -l
```
Expected: ≤ 700 moves for 100 numbers, ≤ 5500 for 500 numbers.

### Testing with checker(bonus)
```
ARG=$(python3 -c "import random; nums=random.sample(range(-1000, 1000), 500); print(' '.join(map(str, nums)))"); ./push_swap $ARG | ./checker $ARG

ARG=$(python3 -c "import random; nums=random.sample(range(-5000, 5000), 500); print(' '.join(map(str, nums)))"); ./push_swap $ARG | ./checker $ARG
```
Checker will output `OK` if the stack is sorted correctly, or `KO` if not.

# Resources
- [Turk Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [Turk Algorithm](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)
- [Push Swap Visualizer](https://push-swap42-visualizer.vercel.app/)
# AI Usage
- Identifying chunking strategies
- Helping in implementation of Turk Algorithm and Chunking
- Debugging.
