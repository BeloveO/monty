#include "monty.h"
/**
 *  push - Adds a new node at the beginning of the stack
 *  @stack: The head of the stack
 *  @p: The value to adds on the stack
*/
void push(stack_t **stack, unsigned int p)
{
	stack_t *n_node = NULL;

	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
		handle_error(ERR_BAD_MALL, NULL, 0, NULL);
	
	n_node->n = p;
	if (*stack)
	{
		n_node->next = *stack;
		n_node->prev = (*stack)->prev;
		(*stack)->prev = n_node;
		*stack = n_node;
		return;
	}

	n_node->next = *stack;
	n_node->prev = NULL;
	*stack = n_node;
}

/**
  * push_queue - Adds a new node at the end of the stack
  * @stack: The head of the stack
  * @p: The value to adds on the stack
  */
void push_queue(stack_t **stack, unsigned int p)
{
	stack_t *current = NULL, *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		handle_error(ERR_BAD_MALL, NULL, 0, NULL);

	new_node->n = p;
	if (*stack)
	{
		current = *stack;
		while (current->next != NULL)
			current = current->next;

		new_node->next = NULL;
		new_node->prev = current;
		current->next = new_node;
		return;
	}

	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}

/**
 * pall - Prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 *
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	(void) line_number;

	if (*stack)
	{
		current = *stack;
		while (current != NULL)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
	}
}
