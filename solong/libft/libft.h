/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyondq <beyondq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:45:26 by tsongtra          #+#    #+#             */
/*   Updated: 2025/03/05 11:02:16 by beyondq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

long			ft_atoi(const char *str);

void			ft_bzero(void *s, size_t n);

void			*ft_calloc(size_t count, size_t size);

int				ft_isalnum(int c);

int				ft_isalpha(int c);

int				ft_isascii(int c);

int				ft_isdigit(int c);

int				ft_isprint(int c);

char			*ft_itoa(int n);

void			*ft_memccpy(void *dst, const void *src, int c, size_t n);

void			*ft_memchr(const void *s, int c, size_t n);

int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_memcpy(void *dst, const void *src, size_t n);

void			*ft_memmove(void *dst, const void *src, size_t len);

void			*ft_memset(void *b, int c, size_t len);

void			ft_putchar_fd(char c, int fd);

void			ft_putendl_fd(char *s, int fd);

void			ft_putnbr_fd(int n, int fd);

void			ft_putstr_fd(char *s, int fd);

char			**ft_split(char const *s, char c);

char			*ft_strchr(const char *s, int c);

char			*ft_strdup(const char *s1);

char			*ft_strjoin(char const *s1, char const *s2);

size_t			ft_strlcat(char *dst, const char *src, size_t size);

size_t			ft_strlcpy(char *dst, const char *src, size_t size);

size_t			ft_strlen(const char *s);

void			ft_striteri(char *s, void (*f)(unsigned int, char*));

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int				ft_strncmp(const char *s1, const char *s2, size_t n);

char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);

char			*ft_strrchr(const char *s, int c);

char			*ft_strtrim(char const *s1, char const *set);

char			*ft_substr(char const *s, unsigned int start, size_t len);

int				ft_tolower(int c);

int				ft_toupper(int c);

void			ft_lstdelone(t_list *lst, void (*del)(void*));

void			ft_lstclear(t_list **lst, void (*del)(void*));

void			ft_lstiter(t_list *lst, void (*f)(void*));

t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *));

char			*get_next_line(int fd);
void			ft_free_ptr(char **ptr);

size_t			print_char(char c);
size_t			print_string(char *str);
size_t			print_int(int n);
size_t			print_percent(void);
size_t			print_hex(unsigned long n, unsigned int c);
size_t			print_pointer(unsigned long n);
size_t			print_uint(unsigned int n);
int				ft_printf(const char *str, ...);

#endif