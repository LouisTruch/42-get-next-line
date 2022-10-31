/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:33:13 by ltruchel          #+#    #+#             */
/*   Updated: 2022/10/31 16:10:56 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		m_size;

	if (!s)
		return (NULL);
	m_size = ft_strlen(s) - start;
	if (m_size < 0)
		m_size = 0;
	if ((size_t)m_size > len)
		m_size = len;
	new = ft_calloc(sizeof(char), (m_size + 1));
	if (!new)
		return (NULL);
	new[m_size] = '\0';
	m_size--;
	while (m_size >= 0)
	{
		new[m_size] = s[m_size + start];
		m_size--;
	}
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == '\0' && c == 0)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	new = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (!new)
		return (0);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	return (new);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mem;
	int		i;
	int		l;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	l = nmemb * size;
	if (size != 0 && l / size != nmemb)
		return (0);
	mem = malloc(l);
	if (!mem)
		return (0);
	i = 0;
	while (i < l)
	{
		mem[i] = '\0';
		i++;
	}
	return (mem);
}
