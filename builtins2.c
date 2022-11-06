/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:24:07 by fjuras            #+#    #+#             */
/*   Updated: 2022/11/06 20:48:58 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include "exec_data.h"
#include "app.h"
#include "builtins.h"

int	builtin_echo(t_app *app, t_exec_data *ed)
{
	int	i;
	int	print_newline;

	(void)app;
	i = 1;
	print_newline = 0;
	if (ed->args[i] != NULL && ft_strcmp(ed->args[i], "-n") == 0)
		++i;
	else
		print_newline = 1;
	while (ed->args[i] != NULL)
	{
		ft_putstr_fd(ed->args[i], ed->fd_out);
		if (ed->args[i + 1] != NULL)
			ft_putchar_fd(' ', ed->fd_out);
		++i;
	}
	if (print_newline)
		ft_putchar_fd('\n', ed->fd_out);
	return (0);
}
