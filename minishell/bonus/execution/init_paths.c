/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:27:04 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:26:44 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	initialize_hardcoded_paths(t_seer *seer)
{
	init_oldpwd(seer);
	init_path(seer);
	init_pwd(seer);
	init_shlvl(seer);
}
