/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:41:38 by vmeharia          #+#    #+#             */
/*   Updated: 2026/05/11 19:41:40 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function Signature: char ft_split(char const *s, char c)

Inputs:
s: The source string containing the text we want to chop up.
c: The delimiter character used as the knife to slice the string.

Returns: A new, heap-allocated array of strings (a double pointer: char**).
The final element of this array is explicitly set to NULL so callers know
where it ends. If memory allocation fails or s is missing, it returns NULL.

Intended Mechanics in Memory: This function constructs a 2D matrix structure
on the Heap. It first scans s to determine how many separate text chunks
(words) exist. It then allocates a "master tray" of pointers. Finally, it
loops back through s, carves out each individual word using your ft_substr,
and places the address of each word inside the tray.

The Traps & Fatal Bugs:

The Cascading Memory Leak Trap (Partial Allocation Failure): Suppose your
master array allocates perfectly. Words 1 through 45 allocate perfectly.
Suddenly, on word 46, the computer runs out of RAM and malloc 
(inside ft_substr) returns NULL. If your function simply returns NULL at
that moment, words 1 through 45 remain trapped on the Heap forever, creating
a massive memory leak. You need a free_array helper function to neutralizes
this trap. By passing the index j to free_array, it explicitly loops backward,
cleans words 1 to 45, frees the master tray, and only then bails out safely.

The Trailing Array Boundary Crash: An array of pointers in C does not know
its own size. Callers iterate through your split array using a loop like while
(res[i] != NULL). If you forget to place a NULL pointer in the very last slot
of your master tray, the caller's loop will drive off the edge of the memory
cliff and crash.

Pseudocode / Logic
Phase 1: Counting (count_words)

1.Walk through the string character by character.

2.Use a toggle flag (in_word) to keep track of state. If the current character
  is not the delimiter and we aren't already tracking a word, flip the flag to
  1 and increment our word count.

3.If we hit a delimiter, flip the flag back to 0.

4.Return the total count.

Phase 2: Protecting Memory (free_array)
If anything breaks during execution, take the array and the number of
successfully allocated words so far.

Loop through and free each individual string slice up to that count.

Finally, free the master tray pointer itself.

Phase 3: Slicing and Assembly (fill_array & ft_split)
Guard against a NULL input string.

Count the total words to calculate the size of the master tray.

Allocate the master tray using malloc((words + 1) * sizeof(char *)).

Walk through s. When a non-delimiter character is found, mark the index (start).

Advance forward until you hit a delimiter or the end of the string.

Calculate the word length (current index - start) and call ft_substr to clone
that exact slice onto the Heap.

If the clone fails, immediately run the free_array rescue routine. Otherwise,
place it in the tray and repeat.

Seal the final tray slot with NULL.*/

#include "push_swap.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;
	int		in_word;

	i = 0;
	words = 0;
	in_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			words++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (words);
}

static void	*free_array(char **strs, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static char	**fill_array(char const *s, char c, char **res)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != '\0' && s[i] != c)
				i++;
			res[j] = ft_substr(s, start, i - start);
			if (res[j] == NULL)
				return (free_array(res, j));
			j++;
		}
		else
			i++;
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	return (fill_array(s, c, res));
}
/*
#include <stdio.h>

int	main()
{
	size_t	j;
	size_t	i;
	char **strngs;

	char str[] = "maga dudu mumu";
	char c = ' ';

	strngs = ft_split(str, c);

	i = 0;
	while (strngs[i] != NULL)
	{
		printf("%s\n", strngs[i]);
		i++;
	}

	i = 0;
	while (strngs[i] != NULL)
	{
		free(strngs[i]);
		i++;
	}
	free(strngs);
}
*/
