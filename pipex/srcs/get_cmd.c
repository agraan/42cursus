/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:45:31 by aprigent          #+#    #+#             */
/*   Updated: 2025/06/02 21:53:16 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *get_path(char *cmd, char *envp[])
{
	char	**paths;
	int		i;

	i = 0;
    while (envp[i])
    {
        if (!ft_strncmp(envp[i], "PATH=", 5))
            break ;
        i++;
    }
	if (!envp[i])
		exit(EXIT_FAILURE);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		exit(EXIT_FAILURE);
	i = 0;
	while (paths[i])
	{
		ft_strlcat(paths[i], "/", ft_strlen(paths[i]) + 2);
		ft_strlcat(paths[i], cmd, ft_strlen(paths[i]) + ft_strlen(cmd) + 2);
		if (!access(paths[i], X_OK))
			return (paths[i]);
		i++;
	}
	return (NULL);
}

char **get_args(char *argv[])
{
	char **args;

	args = malloc(sizeof(char *) * 3);
	if (!args)
		return (NULL);
	args[0] = argv[2];
	args[1] = argv[1];
	args[2] = NULL;
	return (args);
}

