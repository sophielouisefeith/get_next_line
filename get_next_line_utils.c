/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 11:49:15 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/16 11:47:27 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"




size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
} 

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*str;

	len = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (str == 0)
		return (0);
	while (s1[len])
	{
		str[len] = s1[len];
		len++;
	}
	str[len] = '\0';
	return (str);
}

static char		*ft_strcpy(char *dest, char const *src1, char const *src2)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (src1[i] != '\0')
	{
		dest[i] = src1[i];
		i++;
	}
	while (src2[c] != '\0')
	{
		dest[i] = src2[c];
		i++;
		c++;
	}
	dest[i] = '\0';
	return (dest);
}

char			*ft_strjoin(char  *s1, char  *s2)
{
	size_t		s1len;
	size_t		s2len;
	char		*ns;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ns = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (ns == NULL)
		return (NULL);
	ft_strcpy(ns, s1, s2);
	free(s1);
	free(s2);
	return (ns);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (*s == c)
		return ((char*)s);
	return (0);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	srclen;
	char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	srclen = ft_strlen(s);
	if (start >= srclen)
		return (ft_strdup(""));
	if (srclen - start < len)
		len = srclen - start;
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t len;

	if (!src && !dst)
		return (0);
	i = 0;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	while (src[i] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
