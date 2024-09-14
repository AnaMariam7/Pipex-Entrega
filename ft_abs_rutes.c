#include "libft/libft.h"
#include "pipex.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

char	*check_rute(char *rute)
{
	if (access(rute, X_OK) == 0)
	{
		return (rute);
	}
	return (0);
}

int	ft_absolute_rute(char *argv)
{
	if (ft_strncmp(argv, "../", 3) == 0)
		return (1);
	else if (ft_strncmp(argv, "./", 2) == 0)
		return (1);
	else if (ft_strncmp(argv, "/", 1) == 0)
		return (1);
	else
		return (0);
}

void	ft_clean_rute_abs(t_pipex *pipex, char *argv)
{
	char	**matrix;

	matrix = ft_split(argv, ' ');
	pipex->main_rute = ft_strdup(matrix[0]);
	ft_free_p(matrix);
	return ;
}

void	ft_lookforcmd(t_pipex *pipex, char *argv)
{
	char	**matrix;
	int		i;
	
	matrix = ft_split(argv, '/');
	i = 0;
	while (matrix[i] != 0)
		i++;
	pipex->cmd = ft_split(matrix[--i], ' ');
	pipex->main_cmd = pipex->cmd[0];
	return ;
}

void	ft_working_abs_rute(t_pipex *pipex, char *argv)
{
	ft_clean_rute_abs(pipex, argv);
	if (!check_rute(pipex->main_rute))
	{
		ft_errors_manual(": No such file or directory", pipex->main_rute);
		exit(errno);
	}
	ft_lookforcmd(pipex, argv);
}
