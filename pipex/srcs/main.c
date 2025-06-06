/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:18:59 by aprigent          #+#    #+#             */
/*   Updated: 2025/06/02 18:51:45 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	ft_pipe(char *argv[], char *envp[], char **args)
{

	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	*path;
	char	*temp;

	if (pipe(pipefd) == -1)
		perror("pipe");
	pid1 = fork();
	if (pid1 == -1)
		return (perror("error"), -1);
	else if (pid1 == 0)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		path = get_path(argv[2], envp);
		if (!path)
			perror("access");
		execve(path, args, envp);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	pid2 = fork();
	if (pid2 == -1)
		return (perror("error"), -1);
	else if (pid2 == 0)
	{
		waitpid(pid1, NULL, 0);
		close(pipefd[1]);
		pipefd[1] = open(argv[4], O_CREAT);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		path = get_path(argv[3], envp);
		if (!path)
			perror("access");
		args = get_args(argv[3], pipefd[0]);
		if (!args)
			exit(EXIT_FAILURE);
		execve(path, args, envp);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		close(pipefd[1]);
		temp = get_next_line(pipefd[0]);
		while (temp)
		{
			ft_printf("%s", temp);
			free(temp);
			temp = get_next_line(pipefd[0]);
		}
		free(temp);
		close(pipefd[0]);
	}
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

int main(int argc, char *argv[], char *envp[])
{
	char	**args;

	if (argc != 5)
		return (write(2, "Error\n", 6), 1);
	args = get_args(argv[2], argv[1]);
	if (!args)
		exit(EXIT_FAILURE);
	if (access(argv[1], R_OK))
		exit(EXIT_FAILURE);
	if (ft_pipe(argv, envp, args) == -1)
		exit(EXIT_FAILURE);
	return (0);
}
