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

char **get_path(char *cmd, char *envp[])
{
	char **paths;

    while (*envp)
    {
        if (!ft_strncmp(*envp, "PATH=", 5))
            break ;
        envp++;
    }
	if (!*envp)
		exit(EXIT_FAILURE);
	paths = ft_split(*envp, ':');
	if (!paths)
		exit(EXIT_FAILURE);
	while (*paths)
	{
		ft_strlcat(*paths, "/", ft_strlen(*paths) + 1);
		ft_strlcat(*paths, cmd, ft_strlen(*paths) + ft_strlen(cmd));
		paths++;
	}
	return (paths);
}

char **get_args(char *argv[])
{
	char **args;

	args = malloc(sizeof(char *) * 3);
	if (!args)
		return (NULL);
	args[0] = argv[1];
	args[1] = argv[2];
	args[2] = NULL;
	return (args);
}

