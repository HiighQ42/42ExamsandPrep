#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return i;
}

int ft_isalpha(int c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
void ft_swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

int ft_strchr(const char *s, char c)
{
    int i = 0;
    while (s[i])
    {
        if (s[i] == c)
            return 1; 
        i++;
    }
    return 0; 
}

char *order_string(char *s)
{
    int len = ft_strlen(s);
    int swapped = 1;
    
    while (swapped)
    {
        swapped = 0;
        int i = 0;
        while (i < len - 1)
        {
            if (s[i] > s[i + 1])
            {
                ft_swap(&s[i], &s[i + 1]);
                swapped = 1;
            }
            i++;
        }
    }
    return s;
}

void generate_permutations(char *source, char *result, int pos)
{  
    int source_len = ft_strlen(source);
    
    if (pos == source_len)
    {
        write(1, result, source_len);
        write(1, "\n", 1);
        return;
    }
    
    int i = 0;
    while (i < source_len)
    {
        if (!ft_strchr(result, source[i]))
        {
            result[pos] = source[i];        
            generate_permutations(source, result, pos + 1);  
            result[pos] = '\0';             
        }
        i++;
    }
}

int main(int argc, char **argv)
{    
    if (argc != 2)
        return 1;
    
    if (ft_strlen(argv[1]) == 0 || (argv[1][0] == ' ' && !argv[1][1]))
        return 0;
    
    int i = 0;
    while (argv[1][i])
    {
        if (!ft_isalpha(argv[1][i]))
            return 0;
        i++;
    }
    
    int len = ft_strlen(argv[1]);
    
    char *result = calloc(len + 1, 1);
    if (!result)
        return 1;
    
    char *source = order_string(argv[1]);
    
    generate_permutations(source, result, 0);
    
    free(result);
    return 0;
}

