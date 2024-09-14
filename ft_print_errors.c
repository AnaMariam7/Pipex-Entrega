/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <anmaher-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:50:02 by anmaher-          #+#    #+#             */
/*   Updated: 2024/09/14 13:50:04 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>


void	ft_errors_manual(char *s, char *argv)
{
	ft_putstr_fd(argv, 2);
	ft_putstr_fd(s, 2);
	write(2, "\n", 1);
}

void	ft_errors(char *s)
{
	perror(s);
	exit(errno);
}

void set_pipe(t_pipex *pipex)
{
    if (pipe(pipex->pipefd) == -1)
{
        printf("Error in pipe");
        exit(1);
    }
}

int ft_free_p(char **str)
{
    int i;

    i = 0;
    while(str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
    return(0);
}
