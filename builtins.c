/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:24:07 by fjuras            #+#    #+#             */
/*   Updated: 2022/11/06 18:28:22 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <libft/libft.h>
#include <interface/env.h>
#include "exec_data.h"
#include "builtins.h"
#include "envops.h"

t_bltin_fun	builtin_resolve(const char *progname)
{
	if (strcmp(progname, "echo") == 0)
		return (builtin_echo);
	else if (strcmp(progname, "env") == 0)
		return (builtin_env);
	else
		return (NULL);
}

int	builtin_echo(t_app *app, t_exec_data *ed)
{
	int	i;
	int	print_newline;

	(void)app;
	i = 1;
	print_newline = 0;
	if (ed->args[i] != NULL && ft_strcmp(ed->args[i], "-n") == 0)
		++i;
	else
		print_newline = 1;
	while (ed->args[i] != NULL)
	{
		ft_putstr_fd(ed->args[i], ed->fd_out);
		if (ed->args[i + 1] != NULL)
			ft_putchar_fd(' ', ed->fd_out);
		++i;
	}
	if (print_newline)
		ft_putchar_fd('\n', ed->fd_out);
	return (0);
}

int	builtin_env(t_app *app, t_exec_data *ed)
{
	if (ed->args[1] != NULL)
	{
		ft_dprintf(2, "%s: %s: %s\n", app->name, ed->args[0], strerror(EINVAL));
		return (EINVAL);
	}
	env_dprintf_vars(app->env, ed->fd_out, "%s\n");
	return (0);
}
