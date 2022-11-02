/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:54:11 by fjuras            #+#    #+#             */
/*   Updated: 2022/11/02 15:08:02 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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
	app->builtin_last_retval = 0;
	childs_init(&app->childs);
}

int	app_free(t_app *app)
{
	free(app->name);
	ft_freeparr((void **)app->path);
	return (0);
}

void	app_exec_arr(t_app *app, t_exec_data *exec_data_arr, t_line line)
{
	int	i;

	i = 0;
	while (i < line.size)
	{
		if (app_pipe_exec_data_arr(app, exec_data_arr, i, line.size) == 0)
			app_fill_exec_data(app, &exec_data_arr[i], line.progs[i]);
		app_exec(app, &exec_data_arr[i]);
		if (i > 0)
			exec_data_free(&exec_data_arr[i - 1]);
		++i;
	}
	if (i > 0)
		exec_data_free(&exec_data_arr[i - 1]);
}
