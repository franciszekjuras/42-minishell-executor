/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_priv2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:54:11 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/27 22:51:28 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <interface/line.h>
#include "exec_data.h"
#include "app_priv.h"
#include "app.h"

static int	fill_redirs(t_app *app, t_exec_data *exec_data, t_prog prog)
{
	if (prog.in_redir.path != NULL)
		exec_data->fd_in = app_open(app, exec_data, prog.in_redir.path,
				APP_OPEN_IN);
	if (exec_data->fd_in < 0)
		return (-1);
	if (prog.out_redir.path != NULL)
		exec_data->fd_out = app_open(app, exec_data, prog.out_redir.path,
				APP_OPEN_OUT);
	if (exec_data->fd_out < 0)
		return (-1);
	return (0);
}

void	app_fill_exec_data(t_app *app, t_exec_data *exec_data, t_prog prog)
{
	if (fill_redirs(app, exec_data, prog) < 0)
		return ;
	exec_data->args = prog.args;
	exec_data->prog_path = app_resolve_prog_path(app, exec_data->args[0]);
	if (exec_data->prog_path == NULL)
		return ;
	exec_data->ready = 1;
}

void	app_pipe_exec_data_arr(
	t_app *app, t_exec_data *exec_data_arr, int i, int size)
{
	(void)app;
	if (i == 0)
		exec_data_arr[i].fd_in = 0;
	if (i + 1 == size)
		exec_data_arr[i].fd_out = 1;
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
