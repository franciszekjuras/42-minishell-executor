/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:50:14 by fjuras            #+#    #+#             */
/*   Updated: 2022/11/06 22:00:15 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <libft/libft.h>
#include "var_valid.h"

int	var_is_valid_name(char *var)
{
	int	i;

	i = 0;
	while (var[i] != '\0')
	{
		if (!ft_isalnum(var[i]))
			return (0);
		++i;
	}
	return (1);
}

int	var_is_assignment(char *var)
{
	char	*var_name_end;
	int		is_valid_name;

	var_name_end = ft_strchr(var, '=');
	if (var_name_end == NULL)
		return (0);
	*var_name_end = '\0';
	is_valid_name = var_is_valid_name(var);
	*var_name_end = '=';
	return (is_valid_name);
}
