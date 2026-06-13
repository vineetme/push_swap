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

ROADMAP

Phase 1: Validation
-------------------
is_valid_number()
ft_atol()
is_number_in_range()
duplicate check

Phase 2: Build data
-------------------
malloc nodes
build stack A

Phase 3: Sorting
----------------
small stack strategy
large stack strategy

Phase 4: Bonus
--------------
checker


1. INPUT PARSER
2. STRATEGY SELECTOR (simple/medium/complex/adaptive)
3. ALGORITHM EXECUTOR
4. STACK ENGINE
5. OPS SYSTEM (history + counters)
6. OUTPUT / BENCH REPORT


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


Remaining:

Phase 1
--------
Execution flow

Phase 2
--------
Data ownership
(t_config, t_statistics)

Phase 3
--------
Strategy dispatch mechanism

Phase 4
--------
Operation accounting infrastructure

Phase 5
--------
Benchmark reporting

Phase 6
--------
Actual strategies



t_config
├─ strategy requested
├─ bench enabled
├─ first_number
├─ strategy_set
└─ stats
     ├─ disorder
     ├─ strategy_name
     ├─ complexity_class
     ├─ total_ops
     └─ operation counts

main()
│
├─ parse_flags()
├─ validate_input()
├─ build_stack()
├─ assign_indexes()
├─ compute_disorder()
├─ resolve_strategy()
├─ check_sorted()
├─ execute_strategy()
├─ print_benchmark()
└─ cleanup()

Radix Algo:
max_bits = ...

for each bit
{
    size = size_of_a_at_start

    repeat size times
    {
        inspect top element

        if bit == 0
            pb
        else
            ra
    }

    while (B not empty)
        pa
}

1. Normalize values to indexes.
2. Determine max_bits.
3. For each bit:
       process original size elements
       0 -> pb
       1 -> ra
4. pa everything back.
5. Repeat for next bit.

radix_sort()
    get_max_bits()

    for each bit
        process_bit_pass()

        restore_from_b()

process_bit_pass()
    repeat original_size times

        if current bit == 0
            pb
        else
            ra
