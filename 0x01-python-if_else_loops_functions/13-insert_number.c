#include "lists.h"

/**
 * insert_node - put a figure into a sorted list.
 * @head: points to the head of the linked list.
 * @number: insert number.
 * Return: If is function fails - NULL.
 * Otherwise - points to the new node.
 */
listint_t *insert_node(listint_t **head, int number)
{
        listint_t *node = *head, *new;

        new = malloc(sizeof(listint_t));
        if (new == NULL)
                return (NULL);
        new->n = number;

        if (node == NULL || node->n >= number)
        {
                new->next = node;
                *head = new;
                return (new);
        }

        while (node && node->next && node->next->n < number)
                node = node->next;

        new->next = node->next;
        node->next = new;

        return (new);
}
