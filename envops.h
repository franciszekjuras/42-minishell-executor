/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envops.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:07:41 by fjuras            #+#    #+#             */
/*   Updated: 2022/11/06 18:54:22 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVOPS_H
# define ENVOPS_H

void	env_free(t_env env);
void	env_update_path(t_env *env);
void	env_init(t_env *env, char **parent_environ);
int		env_vars_size(t_env *env);
int		env_find_var(t_env *env, char *var);
void	env_dprintf_vars(t_env *env, int fd, const char *format);

#endif
