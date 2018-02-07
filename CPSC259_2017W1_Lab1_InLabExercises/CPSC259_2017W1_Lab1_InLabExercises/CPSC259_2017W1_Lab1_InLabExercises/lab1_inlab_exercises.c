/*
File:				  lab1_inlab_exercises.c
Purpose:			Exercises for lab 1
Author:			  Michael Worobetz & Dhruv Mahajan
Student #s:		46479572 and 52355724
CS Accounts:  w9n1b and r8p1b
Date:				  9/13/2017
*/

/* Preprocessor directives */
#include "lab1_inlab_exercises.h"
#include <stdlib.h> // For system command
#include <string.h>
#include <stdio.h>
/*
Try to avoid using numbers in code.  Programmers will often call
numbers in your code 'magic numbers'.  We avoid using magic numbers
because it is easier to debug code that doesn't use them.
Define and use a constant like this instead: #define CONSTANT_NAME value
*/
#define SOME_CONSTANT 10
int func(int n, int *a, int m)
{
	int result = n - 10;
	int numCalls = a[0] + 1;
	a[0] = numCalls;
	if (n <= 98) {
		int tmp = func(n + 10, a, m);
		result = func(tmp, a, m);
	}
	if (numCalls < m) {
		a[m - numCalls] = result;
	}
	return result;
}

/*
Main function drives the program.  Every C program must have one and
only one main function.  A project will not compile without one.
PRE:    NULL (no pre-conditions)
POST:	 NULL (no side-effects)
RETURN: IF the program exits correctly
THEN 0 ELSE 1
*/
int	cost(char	*s1, unsigned	n1, char	*s2, unsigned	n2)
{
	if (n1 == 0) { return	2 * n2; }
	if (n2 == 0) { return	2 * n1; }
	int	cm = cost(s1 + 1, n1 - 1, s2 + 1, n2 - 1);
	if (*s1 != *s2) { cm = cm + 1; }
	int	c1 = cost(s1 + 1, n1 - 1, s2, n2) + 2;
	int	c2 = cost(s1, n1, s2 + 1, n2 - 1) + 2;
	int	result = (c1	<	c2) ? c1 : c2;
	result = (result	<	cm) ? result : cm;
	return	result;
}

int main(void)
{
  /* Start every function with a list of variables */
	char a[] = { "sasdssfsf"};
	char b[] = { "sasds" };

  /* Then start doing things, like invoking functions and assigning
  their return values to variables */
	int box = cost(a, 3, b, 8);
  /* The system command forces the system to pause before closing executable window */
	printf("%d", box);

  system("pause");
  return 0;
}

/*
Reverses the order of an array of integers
For example,
{ 1, 2, 3, 4 } -> {4, 3, 2, 1 }
{ 1, 2, 3 } -> { 3, 2, 1 }
{1} -> {1}
{} -> {}
PARAM:  array, an array of integers
PARAM:  length, the number of elements in array
PRE:    array is an array of integers
PRE:    length is the correct length of the array
POST:   the elements in array have been reversed in order
RETURN: N/A
*/
void reverse_array(int array[], int length) {
	int i,j;
	int temp;
	for (i=0, j=(length-1);i<(length/2);i++,j--)
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}

/*
Returns the length of the specified C string (an array of
characters that ends with the null character '\0')
PARAM:  string is a standard C array of characters that terminates
with the null character '\0'
PRE:    string is a null-terminated array of characters
POST:   NULL (no side-effects)
RETURN: number of char (excluding the terminating null) in string
*/
int length(const char string[])
{
	int i;
	for (i = 0; string[i]; ++i);
	// Replace this return statement with your own implementation
  return i;
}

/*
Returns the number of occurrences of the specified char in the specified
char array (string)
PARAM:  string is a standard C array of characters that terminates
with the null character '\0'
PARAM:  letter_sought, a char
PRE:    string is a null-terminated array of characters
POST:   NULL (no side-effects)
RETURN: number of occurences of letter_sought in string
*/
int count_letters(const char string[], char letter)
{
	char find = letter;
	int string_length = length(string);
	int i = 0,j;
	for (j=0; j < string_length; j++)
	{
		if (string[j] == find)
		{
			i++;
		}
	}

 return i;
}

/*
Determines if a string is a palindrome.  Skips spaces.
For example,
""     -> returns 1 (an empty string is a palindrome)
"the"  -> returns 0
"abba" -> returns 1
"Abba" -> returns 0
"never odd or even"
-> returns 1 ("neveroddoreven" reversed is the same!)
PARAM:  string is a standard C array of characters that terminates
with the null character '\0'
PRE:    string is a null-terminated array of characters
POST:   no side-effects, e.g., nothing is printed or changed
RETURN: IF string is a palindrome THEN 1
ELSE IF string is not a palindrome THEN 0
*/
int is_palindrome(const char string[]) {


	// This implementation is only partly correct
	int string_length = length(string);
	int i = 0, j = string_length - 1;
	if (string_length <= 1)
	{
		return 1;
	}
	for (i = 0; i < j; ++i, --j)
	{
		if (string[i] != string[j])
		{
			return 0;
		}
		
		else
		{
			return 1;
		}
	}
}