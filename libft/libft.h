/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:29:15 by frgojard          #+#    #+#             */
/*   Updated: 2022/10/19 11:39:08 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <stddef.h>
# include <stdarg.h>
# include <limits.h>
# include <fcntl.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				pos;
	int				t_pos;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}	t_list;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *s);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
long long	ft_atoi(const char *str);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
void		*ft_memchr(const void *s, int c, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strdup(const char *s);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_itoa(int n);
t_list		*ft_lstnew(int content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(int));
void		ft_lstclear(t_list **lst, void (*del)(int));
void		ft_lstiter(t_list *lst, void (*f)(int));
t_list		*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int));
int			ft_printf(const char *s, ...);
int			ft_putchar(char c);
int			ft_putstr(const char *str);
int			ft_putnbr_count(int nb);
int			ft_putnbr_hexa(size_t nbr, char *base);
int			ft_putnbr_u(unsigned int nb);
int			ft_putnbr_p(va_list args, char *base);
char		*get_next_line(int fd);
char		*ft_strdup_gnl(char *s);
char		*ft_strjoin_gnl(char *s1, char *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		ft_stock(char *line, char *buf);
int			ft_start(char *stash, int c);
int			ft_end(char *stash);
char		*ft_strchr(const char *s, int c);
char		*ft_process(char *buf, int readsize, char *line, int fd);
void		ft_sort_int_tab(int *tab, int size);
#endif
