/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 16:57:34 by jsimelio      #+#    #+#                 */
/*   Updated: 2020/12/01 19:47:41 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_putchar_fd.c"
#include "ft_putnbr_fd.c"
#include "ft_putstr_fd.c"

int			main(void)
{
	int		num = -300;
	// int		num2 = 500;
	char	*str = "Hello";
	// char	*str2 = "Bye";
	char 	c = '9';

	ft_printf("int: %d, string: %s, char: %c, unsigned int: %u", num, str, c, num);
	return (0);
}

static void	ft_parse_int(va_list *ap)
{
		int	n;

		n = va_arg (*ap, int);
		ft_putnbr_fd(n, 1);
}

// This is still printing as a negative... why?
static void	ft_parse_uns(va_list *ap)
{
		unsigned int	n;

		n = va_arg (*ap, int);
		ft_putnbr_fd(n, 1);
}

static void	ft_parse_str(va_list *ap)
{
		char *str;

		str = va_arg (*ap, char*);
		ft_putstr_fd(str, 1);
}

static void	ft_parse_char(va_list *ap)
{
		char c;

		c = va_arg (*ap, int);
		ft_putchar_fd(c, 1);
}

static void	ft_parse(const char **str, va_list *ap)
{
	(*str)++;
	if (**str == 's')
		ft_parse_str(ap);
	else if (**str == 'd' || **str == 'i')
		ft_parse_int(ap);
	else if (**str == 'c')
		ft_parse_char(ap);
	else if (**str == 'u')
		ft_parse_uns(ap);
	else if (**str == '%')
		ft_putchar_fd('%', 1);
	(*str)++;
}

int			ft_printf(const char *str, ...)
{
	va_list	ap;

	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			ft_parse(&str, &ap);
		else
		{
			ft_putchar_fd(*str, 1);
			str++;
		}
	}
	return (0);
}

// Questions that arise:
// 	1. can you pass ap to another function? what happens when you updated it? Do you have to pass it by pointer? line 42

/* Mechanics of parsing input:
1. First argument is always a string.
2. Start writing the string with putchar
3. If you encounter a %d, call a function that writes the next argument in argv;
 */