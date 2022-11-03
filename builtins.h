/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:23:35 by fjuras            #+#    #+#             */
/*   Updated: 2022/11/03 19:29:24 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "exec_data.h"

typedef int	(*t_bltin_fun)(const char *, t_exec_data *);

int			builtin_echo(const char *name, t_exec_data *exec_data);

t_bltin_fun	builtin_resolve(const char *progname);

#endif