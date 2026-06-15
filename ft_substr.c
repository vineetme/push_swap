/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:47:21 by vmeharia          #+#    #+#             */
/*   Updated: 2026/05/11 19:47:23 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
char *ft_substr(char const *s, unsigned int start, size_t len)

Inputs: 
s: The source string from which we want to extract a segment.
start: The index in the source string where our extraction should begin.
len: The maximum number of characters we want to copy into our new substring.

Returns: A pointer to a new null-terminated string allocated on the Heap.
If allocation fails or the input string is missing, it returns NULL.

Intended Mechanics in Memory: This function does not modify the original
string s. Instead, it reads a specified portion of s, calculates exactly
how much memory that portion requires, requests a fresh block of bytes from
the Heap using malloc, copies the characters into that new block, and seals
it with a null terminator ('\0').

The Traps & Fatal Bugs

The Out-of-Bounds Start Trap: If a caller passes a start index that is
completely past the end of the string (e.g., trying to start at index 10 on
the 5-letter string "apple"), there are zero characters to copy. If you blindly
tried to read from s[start], the program would read garbage or crash.

The Over-Allocation / Read-Past-End Trap: Imagine the string is "apple"
(length 5), your start is 3 (letter 'l'), but the caller asks for a len of 100.
There are only 2 characters left in the string ('l' and 'e'). If you blindly
malloc(100 + 1), you waste massive amounts of RAM. Even worse, if your loop
tries to copy 100 times, it will read far past the end of your original string,
causinga Segmentation Fault.


Pseudocode / Logic

1. Check if source string pointer actually exists. If it is NULL, return NULL.

2. Measure the length of the source string. If the requested starting position
   is beyond that length, stop and return a fresh, empty string on the Heap.

3. Calculate how many characters are actually left from our starting point to the
   absolute end of the string (remainder).

4. Compare the requested substring length to the remainder. If the requested
   length is bigger than what actually exists, shrink our target length down to
   match the remainder exactly.

5. Request a block of memory from the Heap equal to our finalized length plus 1
   extra byte for the null terminator.

6. If the computer is out of memory and the allocation fails, return NULL.

7. Set up a counter starting at 0. Loop through the source string, copying
  characters from start + counter into the new memory block at index counter.

8. Once we have copied the requested number of characters, append a null
   terminator ('\0') to the end of our new memory block.

9. Return the memory address of the brand-new substring.

The Theory

Why Malloc is Mandated Here
When you create a standard variable or array inside a function
(like char buffer[100];), that memory is born on the Stack. The absolute rule
of the Stack is that the moment your function hits its final closing curly
bracket, its Stack frame is completely obliterated, and those variables vanish.

Because ft_substr needs to create a string that survives after the function
terminates so that main (or another function) can use it, we must bypass the
Stack entirely and request space on the Heap. Memory allocated via malloc on
the Heap stays alive indefinitely until someone explicitly calls free().*/

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	remainder;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	remainder = ft_strlen(s) - start;
	if (len > remainder)
		len = remainder;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
#include <stdio.h>

int	main()
{
	char *str;

	char const s[] = "It shall pass";
	printf("Original String: %s\n", s);
	str = ft_substr(s, 3, 9);
	printf("Substring: %s\n", str);
	free (str);
}
*/
