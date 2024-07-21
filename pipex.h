#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>

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
}	t_pipex;

void ft_open_txt(t_pipex *pipex);
char *ft_lookforpath(t_pipex *pipex);
void ft_lookforrute(t_pipex *pipex);
char *check_rute(char *rute);
//int	ft_stchr(const char *s, int c);
int	ft_absolute_rute(char *argv);
void ft_clean_rute_abs(t_pipex *pipex, char *argv);
void ft_lookforcmd(t_pipex *pipex, char *argv);
void ft_working_abs_rute(t_pipex *pipex, char *argv);
void ft_working_rel_rute(t_pipex *pipex, char *argv);
void set_pipe(t_pipex *pipex);
void  ft_first_child(t_pipex *pipex, char *argv);
void  ft_second_child(t_pipex *pipexi, char *argv);
void ft_errors_manual(char *s, char *argv);
void  ft_errors(char *s);
int ft_free_p(char **str);

#endif
