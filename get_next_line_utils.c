/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kqueiroz <kqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:11:15 by kqueiroz          #+#    #+#             */
/*   Updated: 2025/10/07 15:31:28 by kqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*dest;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	sub_len;
	size_t	i;

	if (!s)
		return (NULL);
	sub_len = ft_strlen(s);
	if (start >= sub_len)
		return (ft_strdup(""));
	if (start + len > sub_len)
		len = sub_len - start;
	sub_str = malloc((len + 1) * sizeof(char));
	if (!sub_str)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	dst = malloc((len1 + len2 + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = -1;
	while (++i < len1)
		dst[i] = s1[i];
	i = -1;
	while (++i < len2)
		dst[i + len1] = s2[i];
	dst[len1 + len2] = '\0';
	return (dst);
}
