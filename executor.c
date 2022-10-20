/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:13:59 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/20 20:20:24 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include "app.h"
#include "childs.h"
#include <libft/libft.h>
#include <interface/line.h>

int minish_execute(t_line line)
{
	t_app	app;
	// int		file_in;
	// int		file_out;
	// int		pipe_fds[2];

	app_init(&app, "minishell");
	// if (app_pipe(&app, pipe_fds) < 0)
	// 	return (app_free(&app));
	// file_in = app_open(&app, , O_RDONLY);
	// file_out = app_open(&app, argv[4], O_WRONLY | O_CREAT | O_TRUNC);
	childs_update(&app.childs,
		app_exec(&app, line.progs[0].args, 0, 1));
	app_free(&app);
	return (childs_wait_until_all_exit(&app.childs));
}

