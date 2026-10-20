*This project has been created as part of the 42 curriculum by kkhant-z*

# Description
`push_swap` is a 42 project that sorts a stack of integers using a limited set of operations: push, swap, and rotate across two stacks (A and B). The goal is to sort stack A in ascending order with the fewest possible moves. This implementation uses a sliding window chunking strategy combined with the Turk algorithm — normalizing values into ranks, pushing elements to stack B in ordered chunks, then greedily inserting them back into A at the lowest rotation cost.

The bonus part is a `checker` program that reads instructions from standard input, replays them on the given stack, and reports whether the result is sorted.

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

# Algorithm Design
The sort runs in four phases (`sort_stack` in `algorithm.c`). Stacks of 2 or 3 elements, and stacks that are already sorted, skip straight to the small-case handlers.

### 1. Normalization (`chunking.c`, `chunking_2.c`)
Raw values can be anything in the `int` range, which makes "is this element in the current chunk?" awkward to answer. So before sorting, every value is replaced by its **rank** (0 … n−1):
1. Copy the stack into an array.
2. Sort the array with an in-place quicksort (middle-element pivot).
3. Replace each value in the stack with its index in the sorted array, found by binary search.

That costs O(n log n) and turns the rest of the algorithm into comparisons against small, dense integers.

### 2. Sliding window chunking (`ft_sliding_chunk`)
Elements are moved from A to B through a window `[i, i + offset]`, where `i` is the number of elements pushed so far:

| Rank of A's top element | Action |
|---|---|
| `rank ≤ i` (below the window) | `pb` then `rb`, so it goes to the bottom of B |
| `i < rank ≤ i + offset` (inside the window) | `pb`, so it stays on top of B |
| `rank > i + offset` (above the window) | `ra`, to look at it later |

As `i` grows the window slides upward through the ranks. Small ranks sink to the bottom of B and larger ones pile on top, so B comes out roughly ordered in both directions. That keeps the rotations needed in phase 4 cheap. The loop stops once only 3 elements are left in A.

The window width was tuned by hand:

| Input size | `offset` |
|---|---|
| ≤ 100 | 20 |
| > 100 | 100 |

### 3. Sort the remaining three (`sort_three`)
With 3 elements left in A, the maximum is rotated to the bottom (`ra` or `rra` depending on where it is), then at most one `sa` finishes the job. That is never more than 2 moves.

### 4. Turk insertion (`do_the_turk`, `algorithm_2.c` / `algorithm_3.c`)
Elements come back from B to A one at a time, choosing the cheapest one each time:
- **Target position in A.** If the value is smaller than A's minimum, it goes above the minimum. If it is larger than A's maximum, it goes right below the maximum. Otherwise it goes right below the largest element of A that is smaller than it.
- **Signed rotation costs.** `index_calculation` turns a position into a signed rotation count. Positive means rotate (`ra`/`rb`), negative means reverse-rotate (`rra`/`rrb`), and the shorter direction is always picked.
- **Candidate selection.** Every element of B is scored by the real number of rotations it needs (`combined_cost`). If both stacks turn the same way the rotations are shared through `rr`/`rrr`, so the cost is `max(|cost_a|, |cost_b|)`. If they turn opposite ways nothing is shared, so the cost is `|cost_a| + |cost_b|`. The lowest cost wins. A's min and max are cached once per pass (`t_cache`). Since no candidate can cost less than its own B rotation, any candidate whose `|cost_b|` is already ≥ the best cost is skipped without computing its A-side position.
- **Execution.** `push_to_slot` runs combined `rr`/`rrr` while both stacks need to turn the same way, finishes the leftover rotations on each stack separately, then does `pa`.

After B is empty, A is rotated in the shorter direction until its minimum is on top.

# Implementation Highlights
- **Strict input validation.** Each argument must be an optional sign followed only by digits. Overflow is caught *before* conversion by comparing the digit string against `"2147483647"` / `"2147483648"`, ignoring leading zeros, so `-2147483648` is accepted and `2147483648` is rejected. Duplicates are rejected as well. Any invalid input prints `Error`.
- **Stacks with a tail pointer.** `t_stack` keeps `head`, `tail` and `size`, so push, swap and rotate are all O(1), and size checks never need to walk the list.
- **One instruction core for both programs.** `push_swap` and `checker` share the same `swap` / `push` / `rotate` / `rrotate` functions. The `push_swap` wrappers print each instruction. The checker calls the same functions silently, so both programs agree on how every move behaves.
- **Bonus checker.** Reads instructions line by line with `get_next_line`, applies them, and prints `OK` / `KO`. An unknown instruction prints `Error`.
- **Built on my own libraries.** Output goes through my `ft_printf` (with `libft`) and input comes from my `get_next_line`, both from earlier 42 projects.
- **Norm-compliant.** The code follows the 42 Norm (≤ 25 lines per function, ≤ 4 parameters, etc.), which is why the algorithm is split across `algorithm*.c`, `chunking*.c` and `cache.c`.

# Benchmarks
Random inputs, every run checked with `./checker` (all returned `OK`):

| Size | Runs | Min | Average | Max | 42 limit for full marks |
|---|---|---|---|---|---|
| 3 | 200 | 0 | 1.2 | 2 | 3 |
| 5 | 300 | 0 | 8.0 | 10 | 12 |
| 100 | 500 | 513 | 583.2 | 672 | 700 |
| 500 | 100 | 3787 | 4164.8 | 4412 | 5500 |

### Scoring with the real move count
An earlier version scored candidates by `|cost_a − cost_b|`. That is correct when the stacks turn in opposite directions. When they turn the same way it ignores the shared `rr`/`rrr` moves, so two `+10` rotations scored 0 even though they take 10 moves. Switching to `combined_cost` gave, on the same inputs:

| Size | Old average / worst | New average / worst | Change in average |
|---|---|---|---|
| 100 | 626.7 / 701 | 583.2 / 672 | −6.9% |
| 500 | 4560.7 / 4982 | 4164.8 / 4412 | −8.7% |

The old scoring went over the 700-move limit in 1 of 500 runs at size 100. The new one never did.

# Resources
- [Turk Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [Turk Algorithm](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)
- [Push Swap Visualizer](https://push-swap42-visualizer.vercel.app/)
# AI Usage
- Identifying chunking strategies
- Helping in implementation of Turk Algorithm and Chunking
- Debugging.
- Writing the Algorithm Design, Implementation Highlights and Benchmarks sections of this README.
- LoL
