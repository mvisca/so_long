/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:41:16 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/06/30 18:20:29 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putstr(va_list params, int *i)
{
	int		control;
	char	*value;

	value = va_arg(params, char *);
	if (value)
		control = write (1, value, ft_strlen(value));
	else
		control = write(1, "(null)", 6);
	(*i)++;
	return (control);
}
