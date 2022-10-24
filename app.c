/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:54:11 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/24 18:15:26 by fjuras           ###   ########.fr       */
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

// int	app_open(t_app *app, char *file, int flags)
// {
// 	int	fd;

// 	if (flags == O_RDONLY)
// 		fd = open(file, flags);
// 	else
// 		fd = open(file, flags, 0644);
// 	if (fd < 0)
// 	{
// 		ft_dprintf(2, "%s: %s: %s\n", app->name, file, strerror(errno));
// 	}
// 	app_track_fd(app, fd);
// 	return (fd);
// }

void	app_fill_exec_data(t_app *app, t_exec_data *exec_data, t_prog prog)
{
	if (exec_data->fd_in < 0 || exec_data->fd_out < 0)
		return;
	exec_data->args = prog.args;
	exec_data->prog_path = app_resolve_prog_path(app, exec_data->args[0]);
	if (exec_data->prog_path == NULL)
		return;
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
