#include "shell.h"
list_t *end_node_add(list_t **head, char *dir);
void list_free(list_t *head);
alias_t *end_alias_add(alias_t **head, char *name, char *value);
void list_alias_free(alias_t *head);

/**
 * end_alias_add - Adds
 * @head: A poin
 * @name: The nam
 * @value: Th
 * Return: If a
 */
alias_t *end_alias_add(alias_t **head, char *name, char *value)
{
	alias_t *new_node = malloc(sizeof(alias_t));
	alias_t *last;

	if (!new_node)
		return (NULL);

	new_node->next = NULL;
	new_node->name = malloc(sizeof(char) * (_strlen(name) + 1));
	if (!new_node->name)
	{
		free(new_node);
		return (NULL);
	}
	new_node->value = value;
	_strcpy(new_node->name, name);

	if (*head)
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
	}
	else
		*head = new_node;

	return (new_node);
}

/**
 * end_node_add - Add
 * @head: A poin
 * @dir: The dir
 * Return: If an erro
 */
list_t *end_node_add(list_t **head, char *dir)
{
	list_t *new_node = malloc(sizeof(list_t));
	list_t *last;

	if (!new_node)
		return (NULL);

	new_node->dir = dir;
	new_node->next = NULL;

	if (*head)
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
	}
	else
		*head = new_node;

	return (new_node);
}

/**
 * list_alias_free - Fre
 * @head: THe he
 */
void list_alias_free(alias_t *head)
{
	alias_t *next;

	while (head)
	{
		next = head->next;
		free(head->name);
		free(head->value);
		free(head);
		head = next;
	}
}

/**
 * list_free - Fr
 * @head: The
 */
void list_free(list_t *head)
{
	list_t *next;

	while (head)
	{
		next = head->next;
		free(head->dir);
		free(head);
		head = next;
	}
}

