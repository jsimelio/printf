/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 10:04:17 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/01/28 15:02:09 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

long long int	ft_absolute(long long int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

int				ft_size(long long int n, int base)
{
	int size;

	size = 1;
	while (n /= base)
		size++;
	return (size);
}

char			*ft_itoa_base(long long int n, int base)
{
	char	*str;
	char	*arr;
	size_t	size;
	int		neg;

	if (base < 2 || base > 16)
		return (NULL);
	size = 0;
	neg = 0;
	arr = "0123456789abcdef";
	if (n < 0)
		neg = 1;
	n = ft_absolute(n);
	size = ft_size(n, base);
	str = malloc(sizeof(char) * (size + neg + 1));
	if (neg)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[size + neg - 1] = arr[n % base];
		size--;
		n /= base;
	}
	return (str);
}

// int		main(void)
// {
// 	char	*str;
// 	long long		n;

// 	n = 4550373275;
// 	str = ft_itoa_base(n, 16);
// 	printf("%s\n", str);
// 	free(str);
// 	return (0);
// }
