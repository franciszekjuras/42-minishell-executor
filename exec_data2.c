/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_data2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:04:13 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/27 22:50:18 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft/libft.h>
#include "exec_data.h"

t_exec_data	*exec_data_arr_init(int size)
{
	t_exec_data	*exec_data_arr;
	int			i;

	exec_data_arr = ft_calloc(size, sizeof(t_exec_data));
	i = 0;
	while (i < size)
		exec_data_init(&exec_data_arr[i++]);
	return (exec_data_arr);
}

void	exec_data_arr_free(t_exec_data *exec_data_arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
		exec_data_free(&exec_data_arr[i++]);
	free(exec_data_arr);
}
