/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:24:07 by fjuras            #+#    #+#             */
/*   Updated: 2022/11/06 20:49:49 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <libft/libft.h>
#include <interface/env.h>
#include "app.h"
#include "exec_data.h"
#include "builtins.h"
#include "envops.h"

t_bltin_fun	builtin_resolve(const char *progname)
{
	if (strcmp(progname, "echo") == 0)
		return (builtin_echo);
	else if (strcmp(progname, "env") == 0)
		return (builtin_env);
	else if (strcmp(progname, "export") == 0)
		return (builtin_export);
	else if (strcmp(progname, "unset") == 0)
		return (builtin_unset);
	else
		return (NULL);
}

int	builtin_env(t_app *app, t_exec_data *ed)
{
	int	i;

	if (ed->args[1] != NULL)
	{
		ft_dprintf(2, "%s: %s: %s\n", app->name, ed->args[0], strerror(EINVAL));
		return (EINVAL);
	}
	i = 0;
	while (app->env->vars[i] != NULL)
	{
		ft_dprintf(ed->fd_out, "%s\n", app->env->vars[i]);
		++i;
	}
	return (0);
}

static int	builtin_export_noarg(t_app *app)
{
	(void)app;
	return (0);
}

int	builtin_export(t_app *app, t_exec_data *ed)
{
	int	i;

	if (ed->args[1] == NULL)
		return (builtin_export_noarg(app));
	i = 1;
	while (ed->args[i] != NULL)
		env_vars_push(app->env, ed->args[i++]);
	return (0);
}

int	builtin_unset(t_app *app, t_exec_data *ed)
{
	int	i;

	i = 0;
	while (ed->args[i] != NULL)
		env_vars_remove(app->env, ed->args[i++]);
	return (0);
}
