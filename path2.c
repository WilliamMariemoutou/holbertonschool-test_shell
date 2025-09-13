#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct PathNode - linked list node for PATH directories
 * @directory: directory string
 * @next: pointer to the next node
 */
typedef struct PathNode
{
	char *directory;
	struct PathNode *next;
} PathNode;

/**
 * freePathLinkedList - frees the linked list
 * @head: pointer to the head of the list
 */
void freePathLinkedList(PathNode *head)
{
	PathNode *current;

	while (head)
	{
		current = head;
		head = head->next;
		free(current->directory);
		free(current);
	}
}

/**
 * addPathNode - adds a new node at the end of the list
 * @head: double pointer to the head of the list
 * @dir: directory string
 *
 * Return: 0 on success, -1 on failure
 */
int addPathNode(PathNode **head, const char *dir)
{
	PathNode *newNode, *current;

	newNode = malloc(sizeof(PathNode));
	if (!newNode)
		return (-1);

	newNode->directory = strdup(dir);
	if (!newNode->directory)
	{
		free(newNode);
		return (-1);
	}
	newNode->next = NULL;

	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = newNode;
	}

	return (0);
}

/**
 * buildPathLinkedList - builds linked list of PATH directories
 *
 * Return: pointer to head of list, or NULL on failure
 */
PathNode *buildPathLinkedList(void)
{
	PathNode *head = NULL;
	char *path_env, *path_copy, *token;

	path_env = getenv("PATH");
	if (!path_env)
		return (NULL);

	path_copy = strdup(path_env);
	if (!path_copy)
		return (NULL);

	token = strtok(path_copy, ":");
	while (token)
	{
		if (addPathNode(&head, token) == -1)
		{
			free(path_copy);
			freePathLinkedList(head);
			return (NULL);
		}
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (head);
}

/**
 * main - entry point
 *
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
	PathNode *pathList;

	pathList = buildPathLinkedList();
	if (pathList)
	{
		PathNode *current = pathList;

		while (current)
		{
			printf("%s\n", current->directory);
			current = current->next;
		}
		freePathLinkedList(pathList);
	}
	else
	{
		fprintf(stderr, "Failed to build PATH list.\n");
		return (1);
	}

	return (0);
}

