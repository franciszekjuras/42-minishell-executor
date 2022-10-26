/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:13:59 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/26 22:18:46 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <libft/libft.h>
#include <interface/line.h>
#include "app.h"
#include "childs.h"
#include "exec_data.h"

// int minish_execute(t_line line)
// {
// 	t_app	app;
// 	int		file_in;
// 	int		file_out;
// 	int		pipe_fds[2];

// 	app_init(&app, "minishell");
// 	if (app_pipe(&app, pipe_fds) < 0)
// 		return (app_free(&app));
// 	file_in = app_open(&app, , O_RDONLY);
// 	file_out = app_open(&app, argv[4], O_WRONLY | O_CREAT | O_TRUNC);
// 	childs_update(&app.childs,
// 		app_exec(&app, line.progs[0].args, 0, 1));
// 	app_free(&app);
// 	line_free(line);
// 	return (childs_wait_until_all_exit(&app.childs));
// }

int	minish_execute(t_line line)
{
	t_exec_data	exec_data;
	t_app		app;
	int			retval;

	app_init(&app, "minish");
	exec_data_init(&exec_data);
	exec_data.fd_in = 0;
	exec_data.fd_out = 1;
	app_fill_exec_data(&app, &exec_data, line.progs[0]);
	app_exec(&app, &exec_data);
	exec_data_free(&exec_data);
	retval = childs_wait_until_all_exit(&app.childs);
	app_free(&app);
	line_free(line);
	return (retval);
}
