#include <stdio.h>


int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	size_t	result;

	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;	
    while (str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + (str[i++] - 48);
    result *= sign;
    if ((str[i] < '0' && str[i] > '9') || (result > INT_MAX || result < INT_MIN))
    {
        exit();
    }
    return (result);
}

int *handle_err(char **args, int k)
{
    int i;
    int j;
    int *number;

    i = 0;
    number = malloc(sizeof(int) * k);
    while (i < k)
    {
        number[i] = ft_atoi(args[i]);
        i++;
    }
    i = 0;
    j = 0;
    while (i < k - 1)
    {
        j = i + 1;
        while (j < k - 1)
        {
            if (number[i] == number[j])
                exit();
            j++;
        }
        i++;
    }
    return(number);
}
