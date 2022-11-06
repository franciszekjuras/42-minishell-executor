/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envops2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:50:14 by fjuras            #+#    #+#             */
/*   Updated: 2022/11/06 16:27:37 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft/libft.h>
#include <interface/env.h>
#include "envops.h"

int	env_vars_size(t_env *env)
{
	int		i;

	i = 0;
	while (env->vars[i] != NULL)
		++i;
	return (i);
}

int	env_find_var(t_env *env, char *var)
{
	int		var_name_len;
	char	*var_name_end;
	int		i;

	var_name_end = ft_strchr(var, '=');
	if (var_name_end == NULL)
		return (-1);
	var_name_len = var_name_end - var;
	i = 0;
	while (env->vars[i] != NULL)
	{
		if (ft_strncmp(env->vars[i], var, var_name_len + 1) == 0)
			return (i);
		++i;
	}
	return (i);
}

void	env_dprintf_vars(t_env *env, int fd, const char *format)
{
	int	i;

	i = 0;
	while (env->vars[i] != NULL)
	{
		ft_dprintf(fd, format, env->vars[i]);
		++i;
	}
}
