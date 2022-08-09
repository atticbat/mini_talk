/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:17:34 by khatlas           #+#    #+#             */
/*   Updated: 2022/06/26 09:01:31 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdlib.h>

char	*ft_parse_i(va_list args)
{
	int	buffer;

	buffer = 0;
	buffer = va_arg(args, int);
	return (ft_itoa (buffer));
}
