/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <anmaher-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:49:28 by anmaher-          #+#    #+#             */
/*   Updated: 2024/09/14 16:56:46 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void	ft_open_txt(t_pipex *pipex)
{
	pipex->fdtxt[0] = open(pipex->argv[1], O_RDONLY, 0644);
	if (pipex->fdtxt[0] == -1)
	{
		ft_errors_manual(": No such file or directory", pipex->argv[1]);
		exit(1);
	}
	pipex->fdtxt[1] = open(pipex->argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (pipex->fdtxt[1] == -1)
	{
		perror("Error al abrir el archivo 2");
		exit(1);
	}
	return ;
}

void	ft_argc_check(int argc, char **argv, char **env, t_pipex pipex)
{
	pipex.argc = argc;
	pipex.argv = argv;
	pipex.env = env;
	ft_open_txt(&pipex);
	set_pipe(&pipex);
	pipex.pid[0] = fork();
	if (pipex.pid[0] == -1)
		ft_error_fork();
	if (pipex.pid[0] == 0)
		ft_first_child(&pipex, argv[2]);
	pipex.pid[1] = fork();
	if (pipex.pid[1] == -1)
		ft_error_fork();
	if (pipex.pid[1] == 0)
		ft_second_child(&pipex, argv[3]);
	close(pipex.fdtxt[1]);
	close(pipex.pipefd[0]);
	close(pipex.fdtxt[0]);
	close(pipex.pipefd[1]);
	waitpid(pipex.pid[0], NULL, 0);
	waitpid(pipex.pid[1], NULL, 0);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (!env)
		return (0);
	if (argc != 5)
	{
		ft_errors_manual("invalid number of arguments", "\n");
		exit(errno);
	}
	if (argc == 5)
	{
		ft_argc_check(argc, argv, env, pipex);
	}
	else
		return (0);
}
