#include "monty.h"

/**
 * nop - func Dos do nothing
 * @stack: Double pointer to tp
 * @ln_n: the line numberd
 */
void nop(stack_t **stack, unsigned int ln_n)
{

	(void) stack;
	(void) ln_n;
}

/**
 * pop - func that Removes the top element
 * @stack: Doub potr to the top
 * @ln_n: Line number where the operations
 */
void pop(stack_t **stack, unsigned int ln_n)
{
	stack_t *begin;

	if ((*stack == NULL) || (stack == NULL))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln_n);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	begin = *stack;
	*stack = (*stack)->next;
	if (begin->next)
		begin->next->prev = NULL;
	free(begin);
}

/**
 * push - func that Pushes in element to the top
 * @stack: Double pointer to the top of the stack
 * @ln_n: Line number whr
 * @tmp: Str representings the element
 */
void push(stack_t **stack, unsigned int ln_n, char *tmp)
{
	stack_t *nw;

	(void)ln_n;
	if (tmp == NULL || _isdigit(tmp) == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln_n);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
		if (_isdigit(tmp) == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln_n);
			fclose(file);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	nw = malloc(sizeof(stack_t));
	if (nw == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		exit(EXIT_FAILURE);
	}
	nw->n = atoi(tmp);
	nw->next = NULL;
	nw->prev = NULL;
	if (*stack)
	{
		nw->next = *stack;
		(*stack)->prev = nw;
		*stack = nw;
	}
	*stack = nw;
}

/**
 * free_stack - fun taht Free stack
 * @stack: Pointer to the top of the sta
 */
void free_stack(stack_t *stack)
{
	if (stack)
	{
		free_stack(stack->next);
		free(stack);
	}
}

/**
 * swap - func that Swaps the top two element
 * @stack: dobly ptr to left
 * @ln_n: Line number where crs
 */
void swap(stack_t **stack, unsigned int ln_n)
{
	stack_t *first, *second;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln_n);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else if (*stack)
	{
		first = *stack;
		second = first->next;
		*stack = second;
		first->next = second->next;
		if (second->next != NULL)
		{
			second->next->prev = first;
		}
		second->prev = NULL;
		second->next = first;
		first->prev = second;
	}
}
