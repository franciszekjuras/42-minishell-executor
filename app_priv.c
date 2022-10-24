/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_priv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:22:54 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/24 18:17:20 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <libft/libft.h>
#include "app.h"
#include "exec_data.h"
#include "utils.h"

extern char	**environ;

char	*app_resolve_prog_path(t_app *app, char *prog)
{
	char	*candidate;
	char	**path;

	if (prog == NULL)
		return (NULL);
	if (ft_strchr(prog, '/') != NULL)
		return (ft_strdup(prog));
	candidate = NULL;
	path = app->path;
	while (*path != NULL)
	{
		if (check_if_path_is_executable(*path, prog, &candidate))
			break ;
		++path;
	}
	if (candidate == NULL)
		ft_dprintf(2, "%s: %s: %s\n", app->name, prog, "command not found");
	return (candidate);
}

void	app_exec_child_side(t_app *app, t_exec_data *exec_data)
{
	dup2(exec_data->fd_in, STDIN_FILENO);
	dup2(exec_data->fd_out, STDOUT_FILENO);
	exec_data_close_tracked_fds(exec_data);
	execve(exec_data->prog_path, exec_data->args, environ);
	ft_dprintf(2, "%s: %s: %s\n", app->name,
		exec_data->args[0], strerror(errno));
	exec_data_free(exec_data);
	app_free(app);
	exit(127);
}
