/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kqueiroz <kqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:11:15 by kqueiroz          #+#    #+#             */
/*   Updated: 2025/09/25 16:24:41 by kqueiroz         ###   ########.fr       */
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
	return (0);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*dest;

	len = 0;
	while (s[len] != '\0')
		len++;
	dest = malloc((len + 1) * sizeof(char));
	if (dest == NULL)
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
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	sub_len;

	if (s == 0)
		return (0);
	sub_len = ft_strlen(s);
	if (start >= sub_len)
		return (ft_strdup(""));
	if (start + len > sub_len)
		len = sub_len - start;
	sub_str = malloc((len + 1) * sizeof(char));
	if (sub_str == 0)
		return (0);
	ft_strlcpy(sub_str, s + start, len + 1);
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
	if (s1 == 0 && s2 == 0)
		return (0);
	dst = malloc((len1 + len2 + 1) * sizeof(char));
	if (dst == 0)
		return (0);
	i = -1;
	while (++i < len1)
		dst[i] = s1[i];
	i = -1;
	while (++i < len2)
		dst[i + len1] = s2[i];
	dst[len1 + len2] = '\0';
	return (dst);
}
