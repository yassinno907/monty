#include "monty.h"

/**
 * pall - func that Prints all element
 * @stack: var rep ptr st
 * @ln_n: Line number assotd with
 */
void pall(stack_t **stack, unsigned int ln_n)
{
	stack_t *curr = *stack;

	(void)ln_n;
	while (curr != NULL)
	{
		printf("%d", curr->n);
		curr = curr->next;
		printf("\n");
	}
}

/**
 * pint - func that Print value
 * @stack: Pointer to the top of the stack
 * @ln_n: num associated with the operation
 */
void pint(stack_t **stack, unsigned int ln_n)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", ln_n);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pstr - func that Prints the st
 * @stack: Pointer to the top of the st
 * @ln_n: Line number inkd
 */
void pstr(stack_t **stack, unsigned int ln_n)
{
	stack_t *upnd = *stack;

	(void)ln_n;
	if ((stack == NULL) || (*stack == NULL))
	{
		printf("\n");
	}
	else
	{
		while (upnd != NULL)
		{
			if ((upnd->n > 0) && (isascii(upnd->n)))
			{
				printf("%c", upnd->n);
				upnd = upnd->next;
			}
			else
			{
				break;
			}
		}
		printf("\n");
	}
}

/**
 * pchar - func Print the character
 * @stack: Pointer to the top of the stack
 * @ln_n: Line number associated with
 */
void pchar(stack_t **stack, unsigned int ln_n)
{
	if ((stack == NULL) || ((*stack) == NULL))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", ln_n);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (!(isascii((*stack)->n)))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", ln_n);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
