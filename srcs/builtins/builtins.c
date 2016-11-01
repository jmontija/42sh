/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <jmontija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 14:50:41 by jmontija          #+#    #+#             */
/*   Updated: 2016/10/30 17:04:16 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fortytwo.h"

int	builtin_setenv(t_group *grp)
{
	char	**cmdsplit;
	t_bool	error;
	int		i;

	i = 0;
	cmdsplit = grp->parselst->cmdsplit;
	error = cmdsplit[1] != NULL ? false : true;
	while (cmdsplit[++i] != NULL)
	{
		if (!ft_strncmp(cmdsplit[i], "_", 1) ||
			!ft_strncmp(cmdsplit[i], "SHLVL", 5))
		{
			ft_putendl_fd("setenv: \"SHLVL\" and \"_\" can't be modify", 2);
			break ;
		}
		else if (insert_env(grp, cmdsplit[i]) < 0)
		{
			ft_putstr_fd("setenv: bad synthax -> ", 2);
			ft_putendl_fd(cmdsplit[i], 2);
			error = true;
		}
	}
	error ? ft_putendl_fd("setenv: synthax -> key=value or key=", 2) : 0;
	return (1);
}

int	builtin_unsetenv(t_group *grp)
{
	char	**cmdsplit;
	t_bool	error;
	int		i;

	i = 0;
	cmdsplit = grp->parselst->cmdsplit;
	error = cmdsplit[1] != NULL ? false : true;
	while (cmdsplit[++i] != NULL)
	{
		if (!ft_strncmp(cmdsplit[i], "_", 1) ||
			!ft_strncmp(cmdsplit[i], "SHLVL", 5))
		{
			ft_putendl_fd("setenv: 'SHLVL', '_' can't be modify", 2);
			break ;
		}
		else if (unset_env(grp, cmdsplit[i]) < 0)
		{
			ft_putstr_fd("unsetenv: unfound key -> ", 2);
			ft_putendl_fd(cmdsplit[i], 2);
			error = true;
		}
	}
	error ? ft_putendl_fd("unsetenv: synthax -> key", 2) : 0;
	return (1);
}

int	builtins(t_group *grp)
{
	int		ret;
	char	**cmd;

	ret = 0;
	cmd = grp->parselst->cmdsplit;
	if (ft_strcmp(*cmd, "env") == 0)
		ret = builtin_env(grp);
	else if (ft_strcmp(*cmd, "cd") == 0)
		ret = builtin_cd(grp);
	else if (ft_strcmp(*cmd, "setenv") == 0)
		ret = builtin_setenv(grp);
	else if (ft_strcmp(*cmd, "unsetenv") == 0)
		ret = builtin_unsetenv(grp);
	else if (ft_strcmp(*cmd, "history") == 0)
		ret = builtin_history(grp);
	else if (ft_strcmp(*cmd, "echo") == 0)
	{
		ret = builtin_echo(grp);
	}
	else if (ft_strcmp(*cmd, "exit") == 0)
	{
		ret = 1;
		printf("You are locked :D \n");
	}
	return (ret);
}