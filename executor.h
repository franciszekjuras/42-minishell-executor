/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:08:33 by fjuras            #+#    #+#             */
/*   Updated: 2022/11/04 13:54:35 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include <interface/env.h>
# include <interface/line.h>

void	minish_env_init(t_env *env, char **parent_environ);
int		minish_execute(t_env *env, t_line line);

#endif
