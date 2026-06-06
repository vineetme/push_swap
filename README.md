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
