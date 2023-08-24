#include "shell.h"
/**
 * clear_info - initializes info_t struct
 * @add: struct address
 */
void clear_info(info_t *add)
{
add->arg = NULL;
add->argv = NULL;
add->path = NULL;
add->argc = 0;
}
/**
 * set_info - initializes info_t struct
 * @add: struct address
 * @av: argument vector
 */
void set_info(info_t *add, char **av)
{
int i = 0;
add->fname = av[0];
if (add->arg)
{
add->argv = strtow(add->arg, " \t");
if (!add->argv)
{
add->argv = malloc(sizeof(char *) * 2);
if (add->argv)
{
add->argv[0] = _strdup(add->arg);
add->argv[1] = NULL;
}
}
for (i = 0; add->argv && add->argv[i]; i++)
add->argc = i;
replace_alias(add);
replace_vars(add);
}
}
/**
 * free_info - frees info_t struct fields
 * @add: struct address
 * @all: true if freeing all fields
 */
void free_info(info_t *add, int all)
{
ffree(add->argv);
add->argv = NULL;
add->path = NULL;
if (all)
{
if (!add->cmd_buf)
free(add->arg);
if (add->env)
free_list(&(add->env));
if (add->history)
free_list(&(add->history));
if (add->alias)
free_list(&(add->alias));
ffree(add->environ);
add->environ = NULL;
bfree((void **)add->cmd_buf);
if (add->readfd > 2)
close(add->readfd);
_putchar(BUF_FLUSH);
}
}
