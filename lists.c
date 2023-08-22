#include "shell.h"
/**
 * add_node - adds a node to the start of the list
 * @h: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 * Return: size of list
 */
list_t *add_node(list_t **h, const char *str, int num)
{
list_t *new_h;
if (!h)
return (NULL);
new_h = malloc(sizeof(list_t));
if (!new_h)
return (NULL);
_memset((void *)new_h, 0, sizeof(list_t));
new_h->num = num;
if (str)
{
new_h->str = _strdup(str);
if (!new_h->str)
{
free(new_h);
return (NULL);
}
}
new_h->next = *h;
*h = new_h;
return (new_h);
}
/**
 * add_node_end - adds a node to the end of the list
 * @h: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 * Return: size of list
 */
list_t *add_node_end(list_t **h, const char *str, int num)
{
list_t *new_node, *node;
if (!h)
return (NULL);
node = *h;
new_node = malloc(sizeof(list_t));
if (!new_node)
return (NULL);
_memset((void *)new_node, 0, sizeof(list_t));
new_node->num = num;
if (str)
{
new_node->str = _strdup(str);
if (!new_node->str)
{
free(new_node);
return (NULL);
}
}
if (node)
{
while (node->next)
node = node->next;
node->next = new_node;
}
else
*h = new_node;
return (new_node);
}
/**
 * print_list_str - prints only the str element of a list_t linked list
 * @f: pointer to first node
 * Return: size of list
 */
size_t print_list_str(const list_t *f)
{
size_t i = 0;
while (f)
{
_puts(f->str ? f->str : "(nil)");
_puts("\n");
f = f->next;
i++;
}
return (i);
}
/**
 * delete_node_at_index - deletes node at given index
 * @f: address of pointer to first node
 * @index: index of node to delete
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **f, unsigned int index)
{
list_t *node, *prev_node;
unsigned int i = 0;
if (!f || !*f)
return (0);
if (!index)
{
node = *f;
*f = (*f)->next;
free(node->str);
free(node);
return (1);
}
node = *f;
while (node)
{
if (i == index)
{
prev_node->next = node->next;
free(node->str);
free(node);
return (1);
}
i++;
prev_node = node;
node = node->next;
}
return (0);
}
/**
 * free_list - frees all nodes of a list
 * @h_ptr: address of pointer to head node
 * Return: void
 */
void free_list(list_t **h_ptr)
{
list_t *node, *next_node, *h;
if (!h_ptr || !*h_ptr)
return;
h = *h_ptr;
node = h;
while (node)
{
next_node = node->next;
free(node->str);
free(node);
node = next_node;
}
*h_ptr = NULL;
}
