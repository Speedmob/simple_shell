#include "main.h"
/**
 * strtow - splits a String into words.
 * @str: String to split
 * @sep: delimiter
 *
 * Return: 2d array
*/
char **strtow(char *str, char sep)
{
	int c = 0, chck = 1, m = 0, a, o = 0, p = 0, k = 0, len;
	char **arr;

	if (str == NULL)
		return (NULL);
	for (m = 0; str[m]; m++)
	{
		if (str[m] != sep && chck)
		{
			chck = 0;
			c++;
		}
		else if (str[m] == sep)
			chck = 1;
	}
	if (c == 0)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (c + 1));
	for (a = 0; a < c; a++)
	{
		for (; str[o] == sep && str[o]; o++)
			;
		for (k = o, len = 0; str[k] != sep && str[k]; k++, len++)
			;
		arr[a] = malloc(sizeof(char) * (len + 1));
		if (arr[a] == NULL)
		{
			for (m = 0; m < a; m++)
				free(arr[m]);
			free(arr);
			return (NULL);
		}
		for (p = 0; str[o] != sep && str[o]; o++, p++)
			arr[a][p] = str[o];
		arr[a][p] = '\0';
	}
	arr[a] = NULL;
	return (arr);
}
/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: num of matched chars
*/
int _strcmp(char *s1, char *s2)
{
	int len = 0;

	while (s2[len] && s1[len] == s2[len])
	{
		len++;
	}
	return (len);
}
/**
 * str_concat - concats two Strings
 * @s1: First String
 * @s2: Second String
 *
 * Return: concat of two Strings, NULL.
*/
char *str_concat(char *s1, char *s2)
{
	int i = 0, m = 0, a;
	char *str_mix;

	if (s1 != NULL)
		for (; s1[i]; i++)
			;
	if (s2 != NULL)
		for (; s2[m]; m++)
			;
	str_mix = malloc(sizeof(char) * (i + m) + 1);
	if (str_mix == NULL)
		return (NULL);
	for (a = 0; a < i; a++)
		str_mix[a] = s1[a];
	for (; a < m + i; a++)
		str_mix[a] = s2[a - i];
	str_mix[a] = '\0';
	return (str_mix);
}
/**
 * _strlen - returns the length of a string
 * @s: the array
 *
 * Return: retuns length of string
*/
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
	{
		i++;
	}
	return (i);
}
/**
 * cgrid - counts grid
 * @grid: grid to count
 *
 * Return: num of elements in grid
*/
int cgrid(char **grid)
{
	int i, c = 0;

	for (i = 0; grid[i]; i++, c++)
		;
	return (c);
}
