[1mdiff --git a/libft/ft_calloc.c b/libft/ft_calloc.c[m
[1mdeleted file mode 100644[m
[1mindex 4b1d356..0000000[m
[1m--- a/libft/ft_calloc.c[m
[1m+++ /dev/null[m
[36m@@ -1,26 +0,0 @@[m
[31m-/* ************************************************************************** */[m
[31m-/*                                                                            */[m
[31m-/*                                                        :::      ::::::::   */[m
[31m-/*   ft_calloc.c                                        :+:      :+:    :+:   */[m
[31m-/*                                                    +:+ +:+         +:+     */[m
[31m-/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */[m
[31m-/*                                                +#+#+#+#+#+   +#+           */[m
[31m-/*   Created: 2025/04/26 12:43:46 by aprigent          #+#    #+#             */[m
[31m-/*   Updated: 2025/04/26 17:06:55 by aprigent         ###   ########.fr       */[m
[31m-/*                                                                            */[m
[31m-/* ************************************************************************** */[m
[31m-[m
[31m-#include "libft.h"[m
[31m-[m
[31m-void *ft_calloc(size_t nmemb, size_t size)[m
[31m-{[m
[31m-    void    *ptr;[m
[31m-[m
[31m-    if (!nmemb || !size || nmemb > ((size_t) - 1) / size)l[m
[31m-        return ((void *)malloc(0));[m
[31m-    ptr = (void *)malloc(nmemb * size);[m
[31m-    if (!ptr)[m
[31m-        return (NULL);[m
[31m-    ft_bzero(ptr, size);[m
[31m-    return (ptr);[m
[31m-}[m
[1mdiff --git a/libft/ft_itoa.c b/libft/ft_itoa.c[m
[1mdeleted file mode 100644[m
[1mindex cb30103..0000000[m
[1m--- a/libft/ft_itoa.c[m
[1m+++ /dev/null[m
[36m@@ -1,51 +0,0 @@[m
[31m-/* ************************************************************************** */[m
[31m-/*                                                                            */[m
[31m-/*                                                        :::      ::::::::   */[m
[31m-/*   ft_itoa.c                                          :+:      :+:    :+:   */[m
[31m-/*                                                    +:+ +:+         +:+     */[m
[31m-/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */[m
[31m-/*                                                +#+#+#+#+#+   +#+           */[m
[31m-/*   Created: 2025/04/26 19:55:47 by aprigent          #+#    #+#             */[m
[31m-/*   Updated: 2025/04/26 21:41:08 by aprigent         ###   ########.fr       */[m
[31m-/*                                                                            */[m
[31m-/* ************************************************************************** */[m
[31m-[m
[31m-#include "libft.h"[m
[31m-[m
[31m-size_t  nb_size(long nb, size_t i)[m
[31m-{[m
[31m-    if (nb > 9) [m
[31m-        return (nb_size(nb / 10, i + 1));[m
[31m-    return (i);[m
[31m-}[m
[31m-char    *ft_itoa(int n)[m
[31m-{[m
[31m-    char    *str;[m
[31m-    long    nb;[m
[31m-    size_t  size;[m
[31m-[m
[31m-    nb = n;[m
[31m-    if (n < 0)[m
[31m-        size = nb_size(-nb, 1);[m
[31m-    else[m
[31m-        size = nb_size(nb, 0);[m
[31m-    str = malloc((size + 1) * sizeof(char));[m
[31m-    if (!str)[m
[31m-        return (NULL);[m
[31m-    if (n < 0)[m
[31m-        str[0] = '-';[m
[31m-    str[size] = 0;[m
[31m-    while (--size)[m
[31m-    {[m
[31m-        str[size] = nb % size;[m
[31m-        nb /= 10;[m
[31m-    }[m
[31m-    return (str);[m
[31m-}[m
[31m-[m
[31m-[m
[31m-[m
[31m-    [m
[31m-[m
[31m-    [m
[31m-[m
[1mdiff --git a/libft/ft_putchar_fd.c b/libft/ft_putchar_fd.c[m
[1mdeleted file mode 100644[m
[1mindex 9909f5b..0000000[m
[1m--- a/libft/ft_putchar_fd.c[m
[1m+++ /dev/null[m
[36m@@ -1,18 +0,0 @@[m
[31m-/* ************************************************************************** */[m
[31m-/*                                                                            */[m
[31m-/*                                                        :::      ::::::::   */[m
[31m-/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */[m
[31m-/*                                                    +:+ +:+         +:+     */[m
[31m-/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */[m
[31m-/*                                                +#+#+#+#+#+   +#+           */[m
[31m-/*   Created: 2025/04/26 22:03:22 by aprigent          #+#    #+#             */[m
[31m-/*   Updated: 2025/04/26 22:09:29 by aprigent         ###   ########.fr       */[m
[31m-/*                                                                            */[m
[31m-/* ************************************************************************** */[m
[31m-[m
[31m-#include "libft.h"[m
[31m-[m
[31m-void    ft_putchar_fd(char c, int fd)[m
[31m-{[m
[31m-    write(fd, &c, 1);[m
[31m-}[m
[1mdiff --git a/libft/ft_putendl_fd.c b/libft/ft_putendl_fd.c[m
[1mdeleted file mode 100644[m
[1mindex 5626850..0000000[m
[1m--- a/libft/ft_putendl_fd.c[m
[1m+++ /dev/null[m
[36m@@ -1,19 +0,0 @@[m
[31m-/* ************************************************************************** */[m
[31m-/*                                                                            */[m
[31m-/*                                                        :::      ::::::::   */[m
[31m-/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */[m
[31m-/*                                                    +:+ +:+         +:+     */[m
[31m-/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */[m
[31m-/*                                                +#+#+#+#+#+   +#+           */[m
[31m-/*   Created: 2025/04/26 22:13:36 by aprigent          #+#    #+#             */[m
[31m-/*   Updated: 2025/04/26 22:15:18 by aprigent         ###   ########.fr       */[m
[31m-/*                                                                            */[m
[31m-/* ************************************************************************** */[m
[31m-[m
[31m-#include "libft.h"[m
[31m-[m
[31m-void    ft_putendl_fd(char *s, int fd)[m
[31m-{[m
[31m-    ft_putstr_fd(s, fd);[m
[31m-    ft_putchar_fd('\n', fd);[m
[31m-}[m
[1mdiff --git a/libft/ft_putnbr_fd.c b/libft/ft_putnbr_fd.c[m
[1mdeleted file mode 100644[m
[1mindex b1642ff..0000000[m
[1m--- a/libft/ft_putnbr_fd.c[m
[1m+++ /dev/null[m
[36m@@ -1,33 +0,0 @@[m
[31m-/* ************************************************************************** */[m
[31m-/*                                                                            */[m
[31m-/*                                                        :::      ::::::::   */[m
[31m-/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */[m
[31m-/*                                                    +:+ +:+         +:+     */[m
[31m-/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */[m
[31m-/*                                                +#+#+#+#+#+   +#+           */[m
[31m-/*   Created: 2025/04/26 22:15:34 by aprigent          #+#    #+#             */[m
[31m-/*   Updated: 2025/04/26 22:19:38 by aprigent         ###   ########.fr       */[m
[31m-/*                                                                            */[m
[31m-/* ************************************************************************** */[m
[31m-[m
[31m-#include "libft.h"[m
[31m-[m
[31m-void    ft_putnbr_fd(int n, int fd)[m
[31m-{[m
[31m-    long    nb;[m
[31m-[m
[31m-    nb = n;[m
[31m-	if (nb < 0)[m
[31m-	{[m
[31m-		ft_putchar_fd('-');[m
[31m-		nb = -nb;[m
[31m-	}[m
[31m-	if (nb > 9)	[m
[31m-    {[m
[31m-		ft_putnbr_fd(nb / 10);[m
[31m-		ft_putchar_fd(nb % 10 + 48);[m
[31m-	}[m
[31m-	else[m
[31m-		ft_putchar_fd(nb + 48);[m
[31m-	}[m
[31m-}[m
[1mdiff --git a/libft/ft_putstr_fd.c b/libft/ft_putstr_fd.c[m
[1mdeleted file mode 100644[m
[1mindex 55c7c0e..0000000[m
[1m--- a/libft/ft_putstr_fd.c[m
[1m+++ /dev/null[m
[36m@@ -1,19 +0,0 @@[m
[31m-/* ************************************************************************** */[m
[31m-/*                                                                            */[m
[31m-/*                                                        :::      ::::::::   */[m
[31m-/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */[m
[31m-/*                                                    +:+ +:+         +:+     */[m
[31m-/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */[m
[31m-/*                                                +#+#+#+#+#+   +#+           */[m
[31m-/*   Created: 2025/04/26 22:09:58 by aprigent          #+#    #+#             */[m
[31m-/*   Updated: 2025/04/26 22:13:15 by aprigent         ###   ########.fr       */[m
[31m-/*                                                                            */[m
[31m-/* ************************************************************************** */[m
[31m-[m
[31m-#include "libft.h"[m
[31m-[m
[31m-void    ft_putstr_fd(char *s, int fd)[m
[31m-{[m
[31m-    while (*s)[m
[31m-        ft_putchar_fd(fd, *s++);[m
[31m-}[m
[1mdiff --git a/libft/ft_split.c b/libft/ft_split.c[m
[1mdeleted file mode 100644[m
[1mindex 05f4811..0000000[m
[1m--- a/libft/ft_split.c[m
[1m+++ /dev/null[m
[36m@@ -1,95 +0,0 @@[m
[31m-/* ************************************************************************** */[m
[31m-/*                                                                            */[m
[31m-/*                                                        :::      ::::::::   */[m
[31m-/*   ft_split.c                                         :+:      :+:    :+:   */[m
[31m-/*                                                    +:+ +:+         +:+     */[m
[31m-/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */[m
[31m-/*                                                +#+#+#+#+#+   +#+           */[m
[31m-/*   Created: 2025/04/26 19:39:10 by aprigent          #+#    #+#             */[m
[31m-/*   Updated: 2025/04/26 20:12:57 by aprigent         ###   ########.fr       */[m
[31m-/*                                                                            */[m
[31m-/* ************************************************************************** */[m
[31m-[m
[31m-#include "libft.h"[m
[31m-[m
[31m-size_t  split_strlen(char *s, char c)[m
[31m-{[m
[31m-	size_t	i;[m
[31m-[m
[31m-	i = 0;[m
[31m-	while (s[i] && s[i] != c)       [m
[31m-		i++;[m
[31m-	return (i);[m
[31m-}[m
[31m-[m
[31m-static int  count_words(char *s, char c)[m
[31m-{[m
[31m-	int	i;[m
[31m-	int	words;[m
[31m-[m
[31m-	i = 0;[m
[31m-	words = 0;[m
[31m-	while (s[i])[m
[31m-	{[m
[31m-		while (s[i] == c && s[i])[m
[31m-			i++;[m
[31m-		if (s[i] == c && s[i])[m
[31m-		{[m
[31m-			words++;[m
[31m-			while (s[i] && s[i] == c)[m
[31m-				i++;[m
[31m-		}[m
[31m-	}[m
[31m-	return (words);[m
[31m-}[m
[31m-[m
[31m-char   **malloc_split(char **arr, char *s, char c, int i;)[m
[31m-{[m
[31m-    int j;[m
[31m-[m
[31m-    j = 0;[m
[31m-	arr[i] = malloc((split_strlen(s, c) + 1 ) * sizeof(char *));[m
[31m-    if (!arr[i])[m
[31m-        return (NULL);[m
[31m-	while (!(*s == c) && *s)[m
[31m-		arr[i][j++] = *s++;[m
[31m-	arr[i][j] = 0;[m
[31m-    return (arr);[m
[31m-[m
[31m-[m
[31m-[m
[31m-void    free_split(char **arr)[m
[31m-{[m
[31m-    int i;[m
[31m-[m
[31m-    i = 0;[m
[31m-    while (arr[i])[m
[31m-        free(arr[i++]);[m
[31m-    free(arr);[m
[31m-}[m
[31m-[m
[31m-char	**ft_split(const char *s, char c)[m
[31m-{[m
[31m-	int		i;[m
[31m-	int		len;[m
[31m-	char	**arr;[m
[31m-[m
[31m-	i = 0;[m
[31m-	len = count_words(s, c);[m
[31m-	arr = malloc((len + 1) * sizeof(char *));[m
[31m-    if (!arr)[m
[31m-        return (NULL);[m
[31m-	while (i < len)[m
[31m-	{[m
[31m-		while (*s == c)[m
[31m-			s++;[m
[31m-        if (!malloc_split(arr, s, c, i))[m
[31m-        {[m
[31m-            free_split(arr);[m
[31m-            return (NULL);[m
[31m-        }[m
[31m-		i++;[m
[31m-	}[m
[31m-	arr[i] = 0;[m
[31m-	return (arr);[m
[31m-}[m
[1mdiff --git a/libft/ft_strdup.c b/libft/ft_strdup.c[m
[1mdeleted file mode 100644[m
[1mindex 39b75b8..0000000[m
[1m--- a/libft/ft_strdup.c[m
[1m+++ /dev/null[m
[36m@@ -1,37 +0,0 @@[m
[31m-/* ************************************************************************** */[m
[31m-/*                                                                            */[m
[31m-/*                                                        :::      ::::::::   */[m
[31m-/*   ft_strdup.c                                        :+:      :+:    :+:   */[m
[31m-/*                                                    +:+ +:+         +:+     */[m
[31m-/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */[m
[31m-/*                                                +#+#+#+#+#+   +#+           */[m
[31m-/*   Created: 2025/04/26 17:10:49 by aprigent          #+#    #+#             */[m
[31m-/*   Updated: 2025/04/26 17:20:02 by aprigent         ###   ########.fr       */[m
[31m-/*                                                                            */[m
[31m-/* ************************************************************************** */[m
[31m-[m
[31m-#include "libft.h"[m
[31m-[m
[31m-static char	*ft_strcpy(char *dest, char *src)[m
[31m-{[m
[31m-	int	i;[m
[31m-[m
[31m-	i = 0;[m
[31m-	while (src[i])[m
[31m-	{[m
[31m-		dest[i] = src[i];[m
[31m-		i++;[m
[31m-	}[m
[31m-	dest[i] = 0;[m
[31m-	return (dest);[m
[31m-}[m
[31m-[m
[31m-char	*ft_strdup(const char *s)[m
[31m-{[m
[31m-	char	*copy;[m
[31m-[m
[31m-	copy = malloc(ft_strlen(s) + 1);[m
[31m-	if (!copy)[m
[31m-		return (NULL);[m
[31m-	return (ft_strcpy(copy, s));[m
[31m-}[m
[1mdiff --git a/libft/ft_striteri.c b/libft/ft_striteri.c[m
[1mdeleted file mode 100644[m
[1mindex 4657953..0000000[m
[1m--- a/libft/ft_striteri.c[m
[1m+++ /dev/null[m
[36m@@ -1,22 +0,0 @@[m
[31m-/* ************************************************************************** */[m
[31m-/*                                                                            */[m
[31m-/*                                                        :::      ::::::::   */[m
[31m-/*   ft_striteri.c                                      :+:      :+:    :+:   */[m
[31m-/*                                                    +:+ +:+         +:+     */[m
[31m-/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */[m
[31m-/*                                                +#+#+#+#+#+   +#+           */[m
[31m-/*   Created: 2025/04/26 21:58:12 by aprigent          #+#    #+#             */[m
[31m-/*   Updated: 2025/04/26 22:01:51 by aprigent         ###   ########.fr       */[m
[31m-/*                                                                            */[m
[31m-/* ************************************************************************** */[m
[31m-[m
[31m-#include "libft.h"[m
[31m-[m
[31m-void    ft_striteri(char *s, void (*f)(unsigned int, char*))[m
[31m-{[m
[31m-    int i;[m
[31m-[m
[31m-    i = 0;[m
[31m-    while (s[i])[m
[31m-        f(i, &s[i++]);[m
[31m-}[m
[1mdiff --git a/libft/ft_strjoin.c b/libft/ft_strjoin.c[m
[1mdeleted file mode 100644[m
[1mindex 1153924..0000000[m
[1m--- a/libft/ft_strjoin.c[m
[1m+++ /dev/null[m
[36m@@ -1,29 +0,0 @@[m
[31m-/* ************************************************************************** */[m
[31m-/*                                                                            */[m
[31m-/*                                                        :::      ::::::::   */[m
[31m-/*   ft_strjoin.c                                       :+:      :+:    :+:   */[m
[31m-/*                                                    +:+ +:+         +:+     */[m
[31m-/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */[m
[31m-/*                                                +#+#+#+#+#+   +#+           */[m
[31m-/*   Created: 2025/04/26 17:54:02 by aprigent          #+#    #+#             */[m
[31m-/*   Updated: 2025/04/26 18:12:54 by aprigent         ###   ########.fr       */[m
[31m-/*                                                                            */[m
[31m-/* ************************************************************************** */[m
[31m-[m
[31m-#include "libft.h"[m
[31m-[m
[31m-char	*ft_strjoin(const char *s1, const char *s2)[m
[31m-{[m
[31m-    char    *str;[m
[31m-    size_t  len1;[m
[31m-    size_t  len2;[m
[31m-[m
[31m-    len1 = ft_strlen(s1);[m
[31m-    len2 = ft_strlen(s2);[m
[31m-[m
[31m-    str = malloc(len1 + len2 + 1);[m
[31m-    if (!str)[m
[31m-        return (NULL);[m
[31m-    ft_strlcat(str, s2, ft_strlcpy(str, s1, len1 + 1) + len2 + 1);[m
[31m-    return (str);[m
[31m-}[m
[1mdiff --git a/libft/ft_strlcat.c b/libft/ft_strlcat.c[m
[1mdeleted file mode 100644[m
[1mindex dec105e..0000000[m
[1m--- a/libft/ft_strlcat.c[m
[1m+++ /dev/null[m
[36m@@ -1,30 +0,0 @@[m
[31m-/* ************************************************************************** */[m
[31m-/*                                                                            */[m
[31m-/*                                                        :::      ::::::::   */[m
[31m-/*   ft_strlcat.c                                       :+:      :+:    :+:   */[m
[31m-/*                                                    +:+ +:+         +:+     */[m
[31m-/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */[m
[31m-/*                                                +#+#+#+#+#+   +#+           */[m
[31m-/*   Created: 2025/04/26 18:17:01 by aprigent          #+#    #+#             */[m
[31m-/*   Updated: 2025/04/26 18:30:10 by aprigent         ###   ########.fr       */[m
[31m-/*                                                                            */[m
[31m-/* ************************************************************************** */[m
[31m-[m
[31m-#include "libft.h"[m
[31m-[m
[31m-size_t  ft_strlcat(char *dst, const char *src, size_t size)[m
[31m-{[m
[31m-    size_t  i;[m
[31m-    int     j;[m
[31m-[m
[31m-    i = ft_strlen(dst);[m
[31m-    j = 0;[m
[31m-    while (i < size)[m
[31m-    {[m
[31m-        dst[i] = src[j];[m
[31m-        i++;[m
[31m-        j++;[m
[31m-    }[m
[31m-    dst[i] = 0;[m
[31m-    return (i);[m
[31m-}[m
[1mdiff --git a/libft/ft_strlcpy.c b/libft/ft_strlcpy.c[m
[1mdeleted file mode 100644[m
[1mindex c139dcb..0000000[m
[1m--- a/libft/ft_strlcpy.c[m
[1m+++ /dev/null[m
[36m@@ -1,26 +0,0 @@[m
[31m-/* ************************************************************************** */[m
[31m-/*                                                                            */[m
[31m-/*                                                        :::      ::::::::   */[m
[31m-/*   ft_strlcpy.c                                       :+:      :+:    :+:   */[m
[31m-/*                                                    +:+ +:+         +:+     */[m
[31m-/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */[m
[31m-/*                                                +#+#+#+#+#+   +#+           */[m
[31m-/*   Created: 2025/04/26 18:13:38 by aprigent          #+#    #+#             */[m
[31m-/*   Updated: 2025/04/26 18:16:54 by aprigent         ###   ########.fr       */[m
[31m-/*                                                                            */[m
[31m-/* ************************************************************************** */[m
[31m-[m
[31m-#include "libft.h"[m
[31m-[m
[31m-size_t  strlcpy(char *dst, const char *src, size_t size)[m
[31m-{[m
[31m-    size_t  i;[m
[31m-[m
[31m-    while (i < size)[m
[31m-    {[m
[31m-        dst[i] = src[i];[m
[31m-        i++;[m
[31m-    }[m
[31m-    dst[i] = 0;[m
[31m-    return (i);[m
[31m-}[m
[1mdiff --git a/libft/ft_strmapi.c b/libft/ft_strmapi.c[m
[1mdeleted file mode 100644[m
[1mindex 818067e..0000000[m
[1m--- a/libft/ft_strmapi.c[m
[1m+++ /dev/null[m
[36m@@ -1,28 +0,0 @@[m
[31m-/* ************************************************************************** */[m
[31m-/*                                                                            */[m
[31m-/*                                                        :::      ::::::::   */[m
[31m-/*   ft_strmapi.c                                       :+:      :+:    :+:   */[m
[31m-/*                                                    +:+ +:+         +:+     */[m
[31m-/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */[m
[31m-/*                                                +#+#+#+#+#+   +#+           */[m
[31m-/*   Created: 2025/04/26 21:41:45 by aprigent          #+#    #+#             */[m
[31m-/*   Updated: 2025/04/26 21:57:52 by aprigent         ###   ########.fr       */[m
[31m-/*                                                                            */[m
[31m-/* ************************************************************************** */[m
[31m-[m
[31m-#include "libft.h"[m
[31m-[m
[31m-char    *ft_strmapi(const char *s, char (*f)(unsigned int, char))[m
[31m-{[m
[31m-    char            *str;[m
[31m-    unsigned int    i;[m
[31m-[m
[31m-    str = malloc((ft_strlen(s) + 1) * sizeof(char));[m
[31m-    if (!str)[m
[31m-        return (NULL);[m
[31m-    i = 0;[m
[31m-    while (s[i])[m
[31m-        str[i] = f(i, s[i++]);[m
[31m-    str[i] = 0;[m
[31m-    return (str);[m
[31m-}[m
[1mdiff --git a/libft/ft_strtrim.c b/libft/ft_strtrim.c[m
[1mdeleted file mode 100644[m
[1mindex 55e822f..0000000[m
[1m--- a/libft/ft_strtrim.c[m
[1m+++ /dev/null[m
[36m@@ -1,40 +0,0 @@[m
[31m-/* ************************************************************************** */[m
[31m-/*                                                                            */[m
[31m-/*                                                        :::      ::::::::   */[m
[31m-/*   ft_strtrim.c                                       :+:      :+:    :+:   */[m
[31m-/*                                                    +:+ +:+         +:+     */[m
[31m-/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */[m
[31m-/*                                                +#+#+#+#+#+   +#+           */[m
[31m-/*   Created: 2025/04/26 18:31:34 by aprigent          #+#    #+#             */[m
[31m-/*   Updated: 2025/04/26 18:57:01 by aprigent         ###   ########.fr       */[m
[31m-/*                                                                            */[m
[31m-/* ************************************************************************** */[m
[31m-[m
[31m-#include "libft.h"[m
[31m-[m
[31m-char    *ft_strtrim(const char *s1, const char *set)[m
[31m-{[m
[31m-    char    *str;[m
[31m-    int     i;[m
[31m-    int     j;[m
[31m-    int     len;[m
[31m-[m
[31m-    i = 0;[m
[31m-    len = ft_strlen(s1) - 1;[m
[31m-    j = ft_strlen(set) - 1;[m
[31m-    while (s1[i] == set[i])[m
[31m-        i++;[m
[31m-    while (s1[len] == set[j])[m
[31m-    {[m
[31m-        j--;[m
[31m-        len--;[m
[31m-    }[m
[31m-    str = malloc(len - i + 1);[m
[31m-    if (!str)[m
[31m-        return (NULL);[m
[31m-    j = 0;[m
[31m-    while (i <= len)[m
[31m-        str[j++] = s1[i++];[m
[31m-    return (str)[m
[31m-}[m
[31m-[m
[1mdiff --git a/libft/ft_substr.c b/libft/ft_substr.c[m
[1mdeleted file mode 100644[m
[1mindex 9b9abd6..0000000[m
[1m--- a/libft/ft_substr.c[m
[1m+++ /dev/null[m
[36m@@ -1,27 +0,0 @@[m
[31m-/* ************************************************************************** */[m
[31m-/*                                                                            */[m
[31m-/*                                                        :::      ::::::::   */[m
[31m-/*   ft_substr.c                                        :+:      :+:    :+:   */[m
[31m-/*                                                    +:+ +:+         +:+     */[m
[31m-/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */[m
[31m-/*                                                +#+#+#+#+#+   +#+           */[m
[31m-/*   Created: 2025/04/26 17:28:55 by aprigent          #+#    #+#             */[m
[31m-/*   Updated: 2025/04/26 17:51:45 by aprigent         ###   ########.fr       */[m
[31m-/*                                                                            */[m
[31m-/* ************************************************************************** */[m
[31m-[m
[31m-#include "libft.h"[m
[31m-[m
[31m-char    *ft_substr(const char *s, unsigned int start, size_t len)[m
[31m-{[m
[31m-    char    *sub;[m
[31m-    size_t  size;[m
[31m-[m
[31m-    size = 0;[m
[31m-    while (s[start + (unsigned int)size] && size < len)[m
[31m-        size++;[m
[31m-    sub = malloc(size + 1);[m
[31m-    if (!sub)[m
[31m-        return (NULL);[m
[31m-    return (sub);[m
[31m-}[m
[1mdiff --git a/reloaded b/reloaded[m
[1mindex a1903ba..fb36661 160000[m
[1m--- a/reloaded[m
[1m+++ b/reloaded[m
[36m@@ -1 +1 @@[m
[31m-Subproject commit a1903ba55a009ed8a4f2055575d402b9e64bf850[m
[32m+[m[32mSubproject commit fb36661afaf0d769f6d4bdcd00763deb17230da7[m
