/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_childs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <anmaher-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:49:16 by anmaher-          #+#    #+#             */
/*   Updated: 2024/09/14 13:49:18 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void	ft_first_child(t_pipex *pipex, char *argv)
{
	if (ft_absolute_rute(argv) == 1)
		ft_working_abs_rute(pipex, argv);
	else
		ft_working_rel_rute(pipex, argv);
	close(pipex->fdtxt[1]);
	close(pipex->pipefd[0]);
	dup2(pipex->fdtxt[0], 0);
	dup2(pipex->pipefd[1], 1);
	close(pipex->fdtxt[0]);
	close(pipex->pipefd[1]);
	execve(pipex->main_rute, pipex->cmd, pipex->env);
	return ;
}

void	ft_second_child(t_pipex *pipex, char *argv)
{
	if (ft_absolute_rute(argv) == 1)
		ft_working_abs_rute(pipex, argv);
	else
		ft_working_rel_rute(pipex, argv);
	close(pipex->fdtxt[0]);
	close(pipex->pipefd[1]);
	dup2(pipex->fdtxt[1], 1);
	dup2(pipex->pipefd[0], 0);
	close(pipex->fdtxt[1]);
	close(pipex->pipefd[0]);
	execve(pipex->main_rute, pipex->cmd, pipex->env);
	exit(1);
	return ;
}
