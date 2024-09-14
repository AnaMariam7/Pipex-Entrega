/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rel_rutes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <anmaher-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:49:04 by anmaher-          #+#    #+#             */
/*   Updated: 2024/09/14 13:49:06 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

char	*ft_lookforpath(t_pipex *pipex)
{
	int		j;
	char	*path;

	j = 0;
	path = NULL;
	while (pipex->env[j])
	{
		if (ft_strncmp(pipex->env[j++], "PATH=", 5) == 0)
		{
			path = pipex->env[--j] + 5;
			break ;
		}
	}
	return (path);
}

void	ft_lookforrute(t_pipex *pipex)
{
	int		j;
	char	*tmp_rute;

	j = 0;
	pipex->main_rute = NULL;
	while (pipex->path_rutes[j])
	{
		tmp_rute = ft_strjoin(pipex->path_rutes[j], pipex->main_cmd);
		if (access(tmp_rute, X_OK) == 0)
		{
			pipex->main_rute = tmp_rute;
			break ;
		}
		free(tmp_rute);
		j++;
	}
	if (pipex->main_rute == NULL)
	{
		ft_errors_manual(": command not found", pipex->cmd[0]);
		free(pipex->main_cmd);
		ft_free_p(pipex->path_rutes);
		ft_free_p(pipex->cmd);
		exit(errno);
	}
	return ;
}

void	ft_working_rel_rute(t_pipex *pipex, char *argv)
{
	pipex->path = ft_lookforpath(pipex);
	pipex->cmd = ft_split(argv, ' ');
	if (!pipex->path)
	{
		ft_errors_manual(": command not found", pipex->cmd[0]);
		ft_free_p(pipex->cmd);
		exit(errno);
	}
	pipex->path_rutes = ft_split(pipex->path, ':');
	pipex->main_cmd = ft_strjoin("/", pipex->cmd[0]);
	ft_lookforrute(pipex);
	return ;
}
