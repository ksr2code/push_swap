/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:39:13 by ksmailov          #+#    #+#             */
/*   Updated: 2025/06/15 16:06:54 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	unsigned char	*cptr;

	cptr = (unsigned char *)ptr;
	while (len > 0)
	{
		*cptr = (unsigned char)value;
		cptr++;
		len--;
	}
	return (ptr);
}
