/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:24:07 by fjuras            #+#    #+#             */
/*   Updated: 2022/11/06 21:37:43 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include "builtins.h"

t_bltin_fun	builtin_resolve(const char *progname)
{
	if (ft_strcmp(progname, "echo") == 0)
		return (builtin_echo);
	else if (ft_strcmp(progname, "env") == 0)
		return (builtin_env);
	else if (ft_strcmp(progname, "export") == 0)
		return (builtin_export);
	else if (ft_strcmp(progname, "unset") == 0)
		return (builtin_unset);
	else
		return (NULL);
}
