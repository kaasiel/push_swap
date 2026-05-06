*This project has been created as part of the 42 curriculum by vrahariv, belaindr.*

# Push_swap

## Description

Push_swap is a sorting algorithm project in C. The goal is to sort a stack of integers using two stacks (`a` and `b`) and a limited set of operations, while minimizing the total number of moves.

The program receives a list of integers as arguments, then outputs the shortest possible sequence of Push_swap operations that sorts stack `a` in ascending order (smallest at the top).

The project enforces a rigorous understanding of algorithmic complexity by requiring four distinct sorting strategies: simple O(n²), medium O(n√n), complex O(n log n), and an adaptive strategy that selects the best approach based on a **disorder metric** computed before any move.

---

## Instructions

### Compilation

```bash
make        # compiles push_swap
make bonus  # also compiles the checker program
make clean  # removes object files
make fclean # removes object files and binaries
make re     # full recompile
```

### Usage

```bash
./push_swap [--simple | --medium | --complex | --adaptive] <list of integers>
```

**Strategy flags (optional):**

| Flag | Strategy | Complexity |
|------|----------|------------|
| `--simple` | Insertion sort adaptation | O(n²) |
| `--medium` | Chunk-based sorting | O(n√n) |
| `--complex` | Radix sort (LSD) | O(n log n) |
| `--adaptive` | Auto-selects based on disorder *(default)* | varies |

**Examples:**

```bash
./push_swap 3 2 1 5 4
./push_swap --complex 4 67 3 87 23

# Verify correctness with the checker (bonus):
ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker $ARG
```

**Error handling:**

```bash
./push_swap 1 2 one 4   # Error (non-integer)
./push_swap 1 2 2 4     # Error (duplicate)
./push_swap             # No output, prompt returns
```

---

## Algorithms

### Disorder metric

Before selecting a strategy, the program computes a **disorder score** between 0 and 1:

- `0` = already sorted
- `1` = completely reversed (worst case)

It counts "inversions" (pairs where a larger element appears before a smaller one) over all pairs, then divides by the total number of pairs:

```
disorder = inversions / (n * (n - 1) / 2)
```

This metric guides the adaptive strategy at runtime.

---

### 1. Simple algorithm — O(n²) : Insertion sort adaptation

**How it works:** For each element in stack `a`, we find its correct position and rotate stack `a` until the element is on top, then push it to stack `b` in sorted order. Once all elements are in `b`, we push them back to `a`.

**Why O(n²):** Each of the n insertions may require up to n rotations, giving n × n = n² operations in the worst case.

**When to use:** Small inputs (n ≤ 20) or when disorder < 0.2 in adaptive mode.

---

### 2. Medium algorithm — O(n√n) : Chunk-based sorting

**How it works:** We divide the value range of the integers into √n equal-sized chunks. Elements are pushed to stack `b` chunk by chunk (largest chunks first). Within each chunk, we always push the locally largest available element first, using rotations to bring it to the top. Finally, we push everything back to `a` in order.

**Why O(n√n):** We process √n chunks of size √n. Each chunk requires at most O(√n) rotations per element, giving O(n√n) total operations.

**When to use:** Medium inputs or when 0.2 ≤ disorder < 0.5 in adaptive mode.

---

### 3. Complex algorithm — O(n log n) : Radix sort (LSD)

**How it works:** We assign a rank (0 to n-1) to each element by coordinate compression. Then we sort by each bit from least significant to most significant (LSD radix sort). At each bit pass, elements with bit = 0 are rotated to the bottom of `a`, and elements with bit = 1 are pushed to `b`. After the pass, everything is pushed back to `a`.

**Why O(n log n):** There are log₂(n) bit passes, and each pass costs O(n) operations (one push or rotate per element), giving O(n log n) total.

**When to use:** Large inputs (n ≥ 100) or when disorder ≥ 0.5 in adaptive mode.

---

### 4. Adaptive algorithm — disorder-driven selection

The adaptive strategy measures disorder first, then delegates:

| Disorder range | Strategy used | Complexity |
|---------------|---------------|------------|
| < 0.2 | Insertion sort (simple) | O(n²) |
| 0.2 – 0.5 | Chunk-based sort (medium) | O(n√n) |
| ≥ 0.5 | Radix sort LSD (complex) | O(n log n) |

**Rationale for thresholds:**
- Below 0.2, the stack is nearly sorted: insertion sort is efficient because few rotations are needed per element, and its constant factors are low.
- Between 0.2 and 0.5, partial disorder benefits from chunk partitioning, which reduces the search space without the overhead of a full bit-pass algorithm.
- Above 0.5, the stack is substantially shuffled: the O(n log n) radix sort guarantees predictable performance regardless of input pattern.

**Space complexity (Push_swap model):** All strategies use O(n) auxiliary space (the two stacks). No additional heap structures are used beyond the stack arrays and the temporary rank array for radix sort.

This is the **default behavior** when no flag is provided.

---

## Performance targets

| Input size | Pass | Good | Excellent |
|-----------|------|------|-----------|
| 100 numbers | < 2000 ops | < 1500 ops | < 700 ops |
| 500 numbers | < 12000 ops | < 8000 ops | < 5500 ops |

---

## Contributors

| Login | Contributions |
|-------|--------------|
| `belaindr` | Stack operations, simple & medium algorithms, Makefile, error handling, benchmark, adapting printf, ft_putfloat |
| `vrahariv` | Radix sort, adaptive strategy, disorder metric, README, bonus part |

Both learners contributed to code review, testing, and defense preparation.

---

## Resources

### References
- [Visualgo — Sorting algorithms](https://visualgo.net/en/sorting) — interactive visualizations of insertion sort, radix sort, etc.
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/) — quick reference for complexity classes.
- [Push_swap tutorial by Jamie Dawson](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) — practical walkthrough for chunk-based sorting.
### AI usage
AI (Claude) was used for the following tasks in this project:
- **Algorithm research:** Asking for explanations of radix sort, chunk sort, and insertion sort adapted to a stack model.
- **Complexity analysis:** Verifying that our operation-count arguments matched the stated Big-O bounds.
- **README drafting:** Structuring and proofreading this document.

All AI-generated suggestions were reviewed, tested, and understood by both learners before being included in the project. No code was blindly copy-pasted.
