/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:37:36 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/08/02 19:41:41 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// linked list struct
struct				s_list
{
	int				*content;
	struct s_list	*next;
};

typedef struct s_list	t_list;

/* Old Linked-list structure
struct				s_list
{
	int				content;
	struct s_list	*next;
};

typedef struct s_list	t_list;
*/

// printf function
int				ft_printf(const char *format, ...);

// ft_printf aux functions
int				ft_putchar(va_list params, int *i);
int				ft_putstr(va_list params, int *i);
int				ft_putint(va_list params, int *i);
int				ft_putunsint(va_list params, int *i);
int				ft_putptr(va_list params, int *i, char mode);
int				ft_puthex(va_list params, int *i, char mode);

// libft functions

char			*ft_itoa(int n);
char			**ft_split(const char *s, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strnstr(const char *h, const char *n, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(const char *s, unsigned int start, size_t len);

int				ft_atoi(const char *nptr);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_toupper(int c);
int				ft_tolower(int c);

long long int	ft_atol(const char *nptr);

size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);

void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));

// libft bonus
int				ft_lstsize(t_list *lst);

t_list			*ft_lstnew(int *content);
t_list			*ft_lstlast(t_list *lst);

void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));

#endif
