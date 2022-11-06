/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:23:35 by fjuras            #+#    #+#             */
/*   Updated: 2022/11/06 16:06:07 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <interface/env.h>
# include "app.h"
# include "exec_data.h"

typedef int	(*t_bltin_fun)(t_app *, t_exec_data *);

t_bltin_fun	builtin_resolve(const char *progname);
int			builtin_echo(t_app *app, t_exec_data *exec_data);
int			builtin_env(t_app *app, t_exec_data *ed);

#endif