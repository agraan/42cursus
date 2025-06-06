/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:38:38 by aprigent          #+#    #+#             */
/*   Updated: 2025/05/30 13:44:48 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

char	*get_path(char *cmd, char *envp[]);
char	**get_args(char *argv[]);
#endif
