#include "shell.h"
/**
 * interactive - returns true if shell is interactive
 * @info: struct address
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * is_delim - checks if character is delimeter
 * @d: char
 * @delim: delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char d, char *delim)
{
while (*delim)
if (*delim++ == d)
return (1);
return (0);
}
/**
 * _isalpha - check alphabetic character
 * @i: input character
 * Return: 1 for alphabetic, 0 otherwise
 */
int _isalpha(int i)
{
if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
return (1);
else
return (0);
}
/**
 * _atoi - converts string to integer
 * @c: string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */
int _atoi(char *c)
{
int i, sign = 1, flag = 0, output;
unsigned int result = 0;
for (i = 0; c[i] != '\0' && flag != 2; i++)
{
if (c[i] == '-')
sign *= -1;
if (c[i] >= '0' && c[i] <= '9')
{
flag = 1;
result *= 10;
result += (c[i] - '0');
}
else if (flag == 1)
flag = 2;
}
if (sign == -1)
output = -result;
else
output = result;
return (output);
}
