/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:04:29 by tsongtra          #+#    #+#             */
/*   Updated: 2023/09/24 13:21:55 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_words(const char *s, char c)
{
	size_t	count;
	size_t	in_word;
	size_t	i;

	count = 0;
	in_word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*duplicate_word(const char *start, const char *end)
{
	size_t	len;
	char	*word;

	len = end - start;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (word != NULL)
	{
		ft_strncpy(word, start, len);
		word[len] = '\0';
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t		word_count;
	size_t		i;
	char		**str;
	const char	*start;

	word_count = count_words(s, c);
	str = (char **)malloc((word_count + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	start = s;
	i = 0;
	while (*s != '\0')
	{
		if (*s == c)
		{
			if (s > start)
				str[i++] = duplicate_word(start, s);
			start = s + 1;
		}
		s++;
	}
	if (s > start)
		str[i++] = duplicate_word(start, s);
	str[i] = NULL;
	return (str);
}

// #include <stdio.h>

// int	main()
// {
// 	char	t[] = "Hello,Test,Easy";
// 	char	**str = ft_split(t,',');
// 	int		i;

// 	i = 0;
// 	while (i < 3)
// 	{
// 		printf("Word split is = %s\n",str[i]);
// 		i++;
// 	}
// 	return (0);
// }
