/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:54:11 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/26 22:19:06 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <libft/libft.h>
#include <interface/line.h>
#include "app.h"
#include "app_priv.h"
#include "exec_data.h"
#include "utils.h"

void	app_init(t_app *app, char *name)
{
	app->name = ft_strdup(name);
	app->path = extract_path_arr_from_env();
	childs_init(&app->childs);
}

int	app_free(t_app *app)
{
	free(app->name);
	ft_freeparr((void **)app->path);
	return (0);
}

// int	app_pipe(t_app *app, int pipe_fds[2])
// {
// 	if (pipe(pipe_fds) == 0)
// 	{
// 		app_track_fd(app, pipe_fds[0]);
// 		app_track_fd(app, pipe_fds[1]);
// 		return (0);
// 	}
// 	else
// 	{
// 		ft_dprintf(2, "%s: %s\n", app->name, strerror(errno));
// 		return (-1);
// 	}
// }

int	app_open(t_app *app, t_exec_data *exec_data, char *file, int mode)
{
	int	fd;

	fd = -1;
	if (mode == APP_OPEN_IN)
		fd = open(file, O_RDONLY);
	else if (mode == APP_OPEN_OUT)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		errno = EPERM;
	if (fd < 0)
	{
		ft_dprintf(2, "%s: %s: %s\n", app->name, file, strerror(errno));
		return (-1);
	}
	exec_data_track_fd(exec_data, fd);
	return (fd);
}

void	app_fill_exec_data(t_app *app, t_exec_data *exec_data, t_prog prog)
{
	if (prog.in_redir.path != NULL)
		exec_data->fd_in = app_open(app, exec_data, prog.in_redir.path,
				APP_OPEN_IN);
	if (prog.out_redir.path != NULL)
		exec_data->fd_out = app_open(app, exec_data, prog.out_redir.path,
				APP_OPEN_OUT);
	if (exec_data->fd_in < 0 || exec_data->fd_out < 0)
		return ;
	exec_data->args = prog.args;
	exec_data->prog_path = app_resolve_prog_path(app, exec_data->args[0]);
	if (exec_data->prog_path == NULL)
		return ;
	exec_data->ready = 1;
}

void	app_exec(t_app *app, t_exec_data *exec_data)
{
	pid_t		child;

	child = fork();
	if (child == 0)
		app_exec_child_side(app, exec_data);
	exec_data_free(exec_data);
	childs_update(&app->childs, child);
}
