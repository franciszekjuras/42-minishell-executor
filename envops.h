/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envops.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:07:41 by fjuras            #+#    #+#             */
/*   Updated: 2022/11/04 14:44:25 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVOPS_H
# define ENVOPS_H

void	env_free(t_env env);
void	env_update_path(t_env *env);
void	env_init(t_env *env, char **parent_environ);

#endif
