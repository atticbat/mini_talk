/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:18:14 by khatlas           #+#    #+#             */
/*   Updated: 2022/08/01 14:34:36 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

char	*ft_parse_u(va_list args)
{
	unsigned int	buffer;

	buffer = 0;
	buffer = va_arg(args, unsigned int);
	return (ft_itoa_base_u(buffer, "0123456789"));
}
