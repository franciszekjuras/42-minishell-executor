/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:13:59 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/27 23:06:55 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interface/line.h>
#include "app.h"
#include "childs.h"
#include "exec_data.h"

int	minish_execute(t_line line)
{
	t_exec_data	*exec_data_arr;
	t_app		app;
	int			retval;

	app_init(&app, "minish");
	exec_data_arr = exec_data_arr_init(line.size);
	app_exec_arr(&app, exec_data_arr, line);
	exec_data_arr_free(exec_data_arr, line.size);
	retval = childs_wait_until_all_exit(&app.childs);
	app_free(&app);
	line_free(line);
	return (retval);
}
