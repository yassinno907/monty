#include "monty.h"

/**
 * _isdigit - func that Checks if a string represent
 * @str: Ptr to check stri
 * Return: 0 if the str rep valid positive int, 1 otherwise
 */
int _isdigit(char *s)
{

	int index = 0;

	if (s[index] == '-')
		index++;
	while (s[index] != '\0')
	{
		if (!isdigit(s[index]))
			return (1);
		index++;
	}

	return (0);
}

/**
 * rotr - func thta Rotates the stack
 * @stack: Doubly pter to top
 * @ln_n: var rep Line number associated wit
 */
void rotr(stack_t **stack, unsigned int ln_n)
{
	stack_t *begin, *finish;

	(void)ln_n;
	if ((*stack == NULL) || ((*stack)->next == NULL))
		;
	else
	{
		begin = finish = *stack;
		while (finish->next)
			finish = finish->next;
		finish->prev->next = NULL;
		finish->prev = NULL;
		finish->next = begin;
		begin->prev = finish;
		*stack = finish;
	}
}

/**
 * rotl - func  Rotates the stack to the left
 * @stack: Doubly pointer to the top
 * @ln_n: Line number associated wit
 */
void rotl(stack_t **stack, unsigned int ln_n)
{
	stack_t *begin, *finish;

	(void)ln_n;
	if ((*stack == NULL) || ((*stack)->next == NULL))
		;
	else
	{
		begin = finish = *stack;
		while (finish->next)
			finish = finish->next;
		*stack = begin->next;
		finish->next = begin;
		begin->prev = finish;
		begin->next = NULL;
		(*stack)->prev = NULL;
	}
}
