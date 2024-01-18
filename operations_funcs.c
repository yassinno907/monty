#include "monty.h"


/**
 * mul - func that rep multi
 * @stack: ptr point the top
 * @ln_n: line of number associ
 */
void mul(stack_t **stack, unsigned int ln_n)
{
	stack_t *one, *two;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", ln_n);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	else
	{
		one = *stack;
		two = one->next;
		two->n *= one->n;
		*stack = two;
		(*stack)->prev = NULL;
		free(one);
	}
}

/**
 * mod - fun that moded the comp
 * @stack: ptr to the top of st
 * @ln_n: Line num associ with
 */
void mod(stack_t **stack, unsigned int ln_n)
{
	stack_t *one, *two;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", ln_n);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln_n);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		one = *stack;
		two = one->next;
		two->n %= one->n;
		*stack = two;
		(*stack)->prev = NULL;
		free(one);
	}
}

/**
 * add - func that add element
 * @stack: ptr tho the right
 * @ln_n: Line number associated opd
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int ln_n)
{
	stack_t *one, *two;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", ln_n);
		fclose(file);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		one = *stack;
		two = one->next;
		two->n += one->n;
		*stack = two;
		(*stack)->prev = NULL;
		free(one);
	}
}

/**
 * _div - func that Divides the secon
 * @stack: Pointer to the top of the st
 * @ln_n: Line number associa
 */
void _div(stack_t **stack, unsigned int ln_n)
{
	stack_t *one, *two;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", ln_n);
		fclose(file);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln_n);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		one = *stack;
		two = one->next;
		two->n /= one->n;
		*stack = two;
		(*stack)->prev = NULL;
		free(one);
	}
}

/**
 * sub - func that Subtracts the top element
 * @stack: var ptr stack
 * @ln_n: lin of numbers
 */
void sub(stack_t **stack, unsigned int ln_n)
{
	stack_t *one, *two;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln_n);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		one = *stack;
		two = one->next;
		two->n -= one->n;
		*stack = two;
		(*stack)->prev = NULL;
		free(one);
	}
}
