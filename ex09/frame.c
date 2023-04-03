#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


static size_t	skip_left(char const *s1, char c)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == c)
		i++;
	return (i);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 1;
	count = 0;
	if (s[0] != c)
		count++;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static char	*allocate_cpy(const char *src, size_t len)
{
	char	*p;

	p = (char *)malloc(len);
	if (!p)
		return (NULL);
	strlcpy(p, src, len);
	return (p);
}

static void	fill_split(char const *s, char c, char **res)
{
	size_t	strnb;
	size_t	i;
	size_t	sindex;

	strnb = 0;
	i = 0;
	sindex = 0;
	while (strnb < count_words(s, c))
	{
		i = i + skip_left(s + i, c);
		sindex = i;
		while (s[i] && s[i] != c)
			i++;
		res[strnb] = allocate_cpy(s + sindex, i - sindex + 1);
		if (res[strnb] == NULL)
		{
			while (strnb > 0)
				free(res[strnb--]);
			free(res[strnb]);
			free(res);
			return ;
		}
		strnb++;
	}
	res[strnb] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (0);
	if ((!strlen(s) && !c) || (!strlen(s)))
	{
		res = malloc(1 * sizeof(char *));
		res[0] = NULL;
		return (res);
	}
	res = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	fill_split(s, c, res);
	return (res);
}




int max(int a, int b) 
{
    if(a > b) return a;
    return (b);
}

int main(int argc, char **argv)
{
    if(argc == 1)
        return 0;
    int large = 0;
    char **splitt = ft_split(argv[1],' ');
    
    for(int i = 0; splitt[i] != NULL; i++)
        large = max(strlen(splitt[i]), large);
    for(int i = 0; i < large + 4; i++)
        printf("*");
    printf("\n");
    for(int i = 0; splitt[i] != NULL; i++)
    {
        printf("* ");
        printf("%s",splitt[i]);
        int extra = large - (int)strlen(splitt[i]);
        for(int i = 0 ; i < extra; i++)
            printf(" ");
        printf(" *");
        printf("\n");   
    }
    for(int i = 0; i < large + 4; i++)
        printf("*");

    for(int i = 0; splitt[i] != NULL; i++)
        free(splitt[i]);
    free(splitt);
}