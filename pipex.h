/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <anmaher-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:51:21 by anmaher-          #+#    #+#             */
/*   Updated: 2024/09/14 16:51:55 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**env;
	int		fdtxt[2];
	int		pipefd[2];
	pid_t	pid[2];
	char	*path;
	char	**path_rutes;
	char	*main_rute;
	char	**cmd;
	char	*main_cmd;
}			t_pipex;

void	ft_open_txt(t_pipex *pipex);
char	*ft_lookforpath(t_pipex *pipex);
void	ft_lookforrute(t_pipex *pipex);
char	*check_rute(char *rute);
int		ft_absolute_rute(char *argv);
void	ft_clean_rute_abs(t_pipex *pipex, char *argv);
void	ft_lookforcmd(t_pipex *pipex, char *argv);
void	ft_working_abs_rute(t_pipex *pipex, char *argv);
void	ft_working_rel_rute(t_pipex *pipex, char *argv);
void	set_pipe(t_pipex *pipex);
void	ft_first_child(t_pipex *pipex, char *argv);
void	ft_second_child(t_pipex *pipexi, char *argv);
void	ft_errors_manual(char *s, char *argv);
void	ft_errors(char *s);
int		ft_free_p(char **str);
void	ft_error_fork(void);
void	ft_argc_check(int argc, char **argv, char **env, t_pipex pipex);

#endif
