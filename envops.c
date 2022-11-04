/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:50:14 by fjuras            #+#    #+#             */
/*   Updated: 2022/11/04 14:46:41 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft/libft.h>
#include <interface/env.h>
#include "envops.h"
#include "utils.h"

static void	strarr_free(char **strarr)
{
	int	i;

	i = 0;
	while (strarr[i] != 0)
		free(strarr[i++]);
	free(strarr);
}

void	env_free(t_env env)
{
	if (env.vars != NULL)
		strarr_free(env.vars);
	if (env.path != NULL)
		strarr_free(env.path);
}

static void	env_init_vars(t_env *env, char **parent_environ)
{
	int	vars_size;
	int	i;

	vars_size = 0;
	if (parent_environ != NULL)
	{
		while (parent_environ[vars_size] != NULL)
			vars_size++;
	}
	env->vars = ft_calloc(vars_size + 1, sizeof(char *));
	i = 0;
	while (i < vars_size)
	{
		env->vars[i] = ft_strdup(parent_environ[i]);
		++i;
	}
	env->vars[i] = NULL;
}

void	env_update_path(t_env *env)
{
	if (env->path != NULL)
		env->path = ft_freeparr((void **)env->path);
	env->path = extract_path_arr_from_env(env->vars);
}

void	env_init(t_env *env, char **parent_environ)
{
	env_init_vars(env, parent_environ);
	env->path = NULL;
	env->last_exit_status = 0;
	env_update_path(env);
}
