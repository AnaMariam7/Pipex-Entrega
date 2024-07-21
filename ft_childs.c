#include "libft/libft.h"
#include "pipex.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void  ft_first_child(t_pipex *pipex, char *argv)
{
    //printf("ENTRA AL HIJO1");
    if(ft_absolute_rute(argv) == 1)
        ft_working_abs_rute(pipex, argv);
    else
        ft_working_rel_rute(pipex, argv);
   /* {   
        pipex->path = ft_lookforpath(pipex);
		pipex->path_rutes = ft_split( pipex->path, ':');
	    pipex->cmd = ft_split(pipex->argv[2], ' ');
	    pipex->main_cmd = ft_strjoin("/", pipex->cmd[0]);
        ft_lookforrute(pipex, pipex->argv[2]);
    }*/
    close(pipex->fdtxt[1]);
    close(pipex->pipefd[0]);
    dup2(pipex->fdtxt[0], 0); 
    dup2(pipex->pipefd[1], 1);
    close(pipex->fdtxt[0]);
    close(pipex->pipefd[1]);
    execve(pipex->main_rute, pipex->cmd, pipex->env);
    return;
}

void  ft_second_child(t_pipex *pipex, char *argv)
{
    if(ft_absolute_rute(argv) == 1)
        ft_working_abs_rute(pipex, argv);
    else
        ft_working_rel_rute(pipex, argv);
   /*{   
        pipex->path = ft_lookforpath(pipex);
		pipex->path_rutes = ft_split( pipex->path, ':');
	    pipex->cmd = ft_split(pipex->argv[3], ' ');
	    pipex->main_cmd = ft_strjoin("/", pipex->cmd[0]);
        ft_lookforrute(pipex, pipex->argv[3]);
    }*/
    /*printf("infile = %d\n", pipex->fdtxt[0]);*/
    /*printf("outfile = %d\n", pipex->fdtxt[1]);*/
    close(pipex->fdtxt[0]);
    close(pipex->pipefd[1]);
    dup2(pipex->fdtxt[1], 1); 
    dup2(pipex->pipefd[0], 0);
    close(pipex->fdtxt[1]);
    close(pipex->pipefd[0]);
    execve(pipex->main_rute, pipex->cmd, pipex->env);
    exit(1);
    return;
}
