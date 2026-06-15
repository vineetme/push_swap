What are my valid Inputs? 
Our program must accept:
- A list of integers: These represent the numbers to be sorted into Stack A. The first 
argument is the top of the stack.  
- Strategy Flags: Optional flags passed at execution (--simple, --medium, --complex, --adaptive) 
to force the program to use a specific sorting algorithm.  
- A Telemetry Flag: An optional --bench flag that activates a specialized benchmark monitoring mode.  
- Nothing: If no arguments are provided, the program must do nothing and cleanly exit.  

What are my expected Outputs?
- Standard Output (stdout): The program must only print the sequence of allowed operation strings
 (sa, pb, ra, etc.). Every operation must be separated by a single \n and absolutely nothing else.  
- Standard Error (stderr): 
1.  Errors: If anything invalid happens, it must display exactly "Error\n" on stderr.
2.  Benchmarks: If running in --bench mode, all the computed metrics (disorder %, total ops,
 counts of each move) must be sent strictly to stderr, leaving the regular moves clean on stdout.  

What are the absolute Constraints?
- The Non-Negotiables: Written in C, must pass the Norm check, zero memory leaks, and no 
unexpected crashes (like Segfaults).  
- Architecture Constraint: No using global variables.  
- Function Constraints: Can only use read, write, malloc, free, exit, and our own custom ft_printf
 or equivalent. No external math libraries, no shortcuts.  
- Algorithmic Architecture: Our executable must actively contain four distinct strategies. 
- Human Constraints: This project requires exactly 2 learners. Both must understand everything and
 split the work, detailing who did what in the README.md.  

Parse flags
↓
Validate input
↓
Build stack
↓
Assign indexes
↓
Compute disorder
↓
Resolve strategy
↓
Check sorted
↓
Execute strategy (if needed)
↓
Benchmark output
↓
Cleanup

## Simple Strategy — Selection-Based Stack Sorting (O(n²))

The Simple strategy is designed for small stacks and is conceptually similar to Selection Sort.

The algorithm repeatedly finds the smallest value remaining in stack A, rotates the stack until
that value reaches the top, and pushes it to stack B. This process continues until only three
elements remain in stack A. The remaining three elements are sorted using a specialized sort_three()
routine, after which all elements stored in stack B are pushed back to stack A.

### Example

Initial stack:

```text
A: 5 1 4 2 3
B:
```

The smallest value is `1`.

```text
ra
A: 1 4 2 3 5
```

Move it to B:

```text
pb
A: 4 2 3 5
B: 1
```

The process repeats for the next smallest value (`2`), then `3`, until only three elements 
remain in stack A.

### Complexity Analysis

Assume there are `n` elements.

During each iteration, the algorithm must locate the smallest remaining element. In the worst 
case, this requires scanning the entire stack.

The number of comparisons performed is therefore:

```text
n + (n - 1) + (n - 2) + ... + 2 + 1
```

This arithmetic series evaluates to:

```text
n(n + 1) / 2
```

which simplifies asymptotically to:

```text
O(n²)
```

The rotations required to move the smallest element to the top are also bounded by the current
stack size, resulting in the same quadratic growth rate.

Consequently, both the search cost and movement cost increase proportionally to the square of 
the input size, placing the algorithm firmly in the O(n²) complexity class.

### Why It Was Chosen

Although inefficient for large datasets, this approach performs extremely well on very small 
stacks. It is simple to implement, easy to verify, and generates a low number of operations 
when `n ≤ 5`, making it ideal as a dedicated small-input strategy.


## Medium Strategy — Chunk-Based Sorting (O(n√n))

The Medium strategy improves upon the quadratic behavior of the Simple strategy by processing
values in groups rather than individually.

After all values have been indexed, the index range is divided into several chunks. Instead of
searching for the globally smallest value, the algorithm searches for any value belonging to the
current chunk and moves it to stack B. Once all chunks have been transferred, stack B is restored
to stack A in descending index order.

### Chunk Construction

For a stack of size `n`, the chunk size is calculated as:

```text
chunk_size ≈ n / √n
```

which simplifies to:

```text
chunk_size ≈ √n
```

The total number of chunks therefore becomes:

```text
number_of_chunks = n / chunk_size
                 = n / √n
                 = √n
```

### Example

Assume a stack of 100 indexed elements.

```text
chunk_size ≈ 10
```

The algorithm creates approximately:

```text
0–9
10–19
20–29
...
90–99
```

For the first chunk, the algorithm searches stack A for any value whose index lies between 0 and 9.
When THE value is found, stack A is rotated until that element reaches the top and it is pushed to stack B.

This continues until no values from the current chunk remain in stack A.

### Complexity Analysis

For each chunk, elements may need to be searched within stack A.

In the worst case, locating a suitable element may require traversing a large portion of the stack.
Since approximately `n` elements are processed across `√n` chunks, the total work grows proportionally to:

```text
n × √n
```

which yields:

```text
O(n√n)
```

This represents a substantial improvement over the O(n²) behavior of the Simple strategy.

For example:

```text
n = 500

Simple:
500² = 250,000 units of work

Chunk:
500 × √500 ≈ 11,180 units of work
```

Although these numbers are illustrative rather than exact operation counts, they demonstrate the
significantly slower growth rate of the chunk-based approach.

### Optimization of Stack B

After pushing an element to stack B, the algorithm checks whether the element belongs to the lower
half of the current chunk.

If it does, stack B is rotated:

```c
if ((*b)->index < ((chunk_start + chunk_end) / 2))
	rb(b, stats);
```

This distributes smaller indexes toward the bottom of stack B and larger indexes toward the top,
reducing the number of rotations required during restoration.

### Why It Was Chosen

Chunk sorting provides a strong balance between implementation complexity and performance. It is 
significantly more efficient than repeatedly searching for individual minimum values, while remaining
easier to reason about than more advanced algorithms. For medium-sized stacks it often produces
substantially fewer operations than quadratic approaches and serves as an effective bridge between
simple selection-based sorting and full radix sorting.


## Complex Strategy — Binary Radix Sort (O(n log n))

The Complex strategy is based on a binary Least Significant Bit (LSB) radix sort operating on
compressed indexes rather than raw integer values.

Before sorting begins, every value is assigned an index representing its position in the sorted order. Ex:

```text
Original values:
42  17  91  5

Sorted order:
5   17  42  91

Assigned indexes:
2   1   3   0
```

Once indexing is complete, the algorithm sorts according to the binary representation of these indexes.

### How the Algorithm Works

The algorithm processes one bit position at a time, beginning with the least significant bit.

Consider the indexed sequence:

```text
0 1 2 3 4 5 6 7
```

Binary representation:

```text
0 = 000
1 = 001
2 = 010
3 = 011
4 = 100
5 = 101
6 = 110
7 = 111
```

### Pass 1 — Bit 0

The algorithm examines the rightmost bit of every index.

```text
Bit = 0  → pb
Bit = 1  → ra
```

After every element has been processed:

```text
pa
```

is repeatedly executed until stack B becomes empty.

At this point all elements with a zero in bit position 0 appear before elements with a one in bit position 0.

### Pass 2 — Bit 1

The same procedure is repeated using the next bit position.

```text
Bit = 0  → pb
Bit = 1  → ra
```

Elements are partitioned according to the second bit.

### Pass 3 — Bit 2

The process repeats again for the third bit.

After the final bit has been processed, all indexes are fully ordered and stack A is sorted.

### Why Index Compression Is Used

Radix sort operates most efficiently on small consecutive integers.

Without compression, values such as:

```text
-2147483648
2147483647
```

would require processing many unnecessary bit positions.

By converting every value to its rank:

```text
0 ... n - 1
```

the algorithm guarantees that only the minimum number of bits required to represent the dataset are processed.

For a stack containing `n` elements:

```text
largest_index = n - 1
```

Therefore the number of bits required is:

```text
⌈log₂(n)⌉
```

### Complexity Analysis

Let:

```text
n = number of elements
b = number of bits required
```

For each bit position:

1. Every element is examined exactly once.
2. Each examination results in either:

   * one rotation (`ra`)
   * or one push (`pb`)
3. Every pushed element is eventually restored using `pa`.

Therefore each pass performs a number of operations proportional to `n`.

```text
Work per pass = O(n)
```

The number of passes equals the number of bits required to represent the largest index:

```text
b = ⌈log₂(n)⌉
```

The total work is therefore:

```text
O(n) × O(log n)
```

which gives:

```text
O(n log n)
```

### Example

For:

```text
n = 500
```

the largest index is:

```text
499
```

and:

```text
log₂(500) ≈ 9
```

Therefore only about nine bit passes are required.

Each pass processes all 500 elements once:

```text
500 × 9 = 4500
```

which explains why radix sort scales dramatically better than quadratic algorithms as input size grows.

### Why It Was Chosen

Binary radix sort is particularly well suited to the push_swap instruction set because it requires
only rotations and pushes. Unlike comparison-based algorithms, its behavior is deterministic and 
independent of the initial ordering of the data.

The operation count grows approximately in proportion to `n log n`, making it highly effective for 
large stacks and significantly more scalable than selection-based or chunk-based approaches.

