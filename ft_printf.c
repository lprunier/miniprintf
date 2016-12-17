/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 12:10:41 by lprunier          #+#    #+#             */
/*   Updated: 2016/12/16 13:35:03 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printf_string(va_list pa, int fd)
{
	char *s;

	s = va_arg(pa, char *);
	ft_putstr_fd(s, fd);
	return (ft_strlen(s));
}

int	ft_printf_nb(va_list pa, int fd)
{
	int	i;

	i = va_arg(pa, int);
	ft_putnbr_fd(i, fd);
	return (ft_nblen(i, 0));
}

int	miniprintf(int fd, char *str, ...)
{
	va_list	pa;
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	va_start(pa, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] == 's' && ++i)
			ret += ft_printf_string(pa, fd);
		else if (str[i] == '%' && str[i + 1] == 'd' && ++i)
			ret += ft_printf_nb(pa, fd);
		else if (++ret)
			ft_putchar_fd(str[i], fd);
		i++;
	}
	va_end(pa);
	return (ret);
}
