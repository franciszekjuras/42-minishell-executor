/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_priv.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:21:08 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/24 18:00:23 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_PRIV_H
# define APP_PRIV_H

# include <sys/types.h>
# include "app.h"
# include "exec_data.h"

char	*app_resolve_prog_path(t_app *app, char *prog);
void	app_exec_child_side(t_app *app, t_exec_data *exec_data);

#endif
