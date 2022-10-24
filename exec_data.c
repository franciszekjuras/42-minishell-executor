/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:04:13 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/24 18:13:24 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft/libft.h>
#include "exec_data.h"

void	exec_data_init(t_exec_data *exec_data)
{
	exec_data->ready = 0;
	exec_data->prog_path = NULL;
	exec_data->args = NULL;
	exec_data->fd_in = -1;
	exec_data->fd_out = -1;
	exec_data->fds_end = 0;
}

void	exec_data_track_fd(t_exec_data *exec_data, int fd)
{
	if (fd >= 0)
		exec_data->fds[exec_data->fds_end++] = fd;
}

void	exec_data_close_tracked_fds(t_exec_data *exec_data)
{
	int	i;

	i = 0;
	while (i < exec_data->fds_end)
		close(exec_data->fds[i++]);
	exec_data->fds_end = 0;
}

void	exec_data_free(t_exec_data *exec_data)
{
	free(exec_data->prog_path);
	exec_data->prog_path = NULL;
	exec_data->args = NULL;
	exec_data_close_tracked_fds(exec_data);
	exec_data->ready = 0;
}
