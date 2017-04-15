/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 19:16:21 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/04 19:29:12 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include "libft.h"

int		ft_tolower(int c)
{
	return ((c >= 'A' && c <= 'Z') ? (c + 32) : c);
}
