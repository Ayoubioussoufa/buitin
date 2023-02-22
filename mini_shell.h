/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:36:00 by sben-ela          #+#    #+#             */
/*   Updated: 2023/02/19 15:52:57 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef MINI_SHELL_H
# define  MINI_SHELL_H

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<readline/readline.h>
#include	<readline/history.h>
#include	<fcntl.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <string.h>

typedef struct s_env_elem
{
	char				*key;
	char				*value;
	struct s_env_elem	*next;
	struct s_env_elem	*prev;
}	t_env_elem;

typedef struct s_env
{
	t_env_elem	*head;
	char		**env;
	int			size;
}	t_env;

typedef	struct	shell
{
	/// type => redirect_input = 0; redirect_output = 1; pipe = 2; cmd = 3; << = delimiter; >> = redirect_output in append mode
	int				type;
	char			*cmd;
	char			**cmds;
	char			**paths;
	char			*argv;
	struct shell	*next;
}	t_shell;

void    ft_error(char *str);
// int		ft_strchr(char *str, char c);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *str, char c);
void    ft_execute(t_shell *shell, char **env);
void	whatever(t_shell *shell, char **env);
char	*parse_redirect(char *line);

//utils
int	handle_couts(t_shell *shell);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
// char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnstr(char *str, int n);
int    echo_builtin(char **cmd);
void	ft_putchar(char c);
int	unset_builtin(char **cmd, char ***ev);
int	ft_isalpha(int c);
char	*ft_strdup(char *str);
char	*ft_substr(char *s, int start, int len);
// char	*ft_substr(char const *s, unsigned int start, size_t len);
// char	*ft_strdup(const char *source);


//env functions
char	**convert_array(t_env *env);
void	del_env(t_env *env);
void	print_env(t_env *env);
t_env	*create_env(char **tab);
t_env	*init_env(t_env *env);
t_env_elem	*new_env_elem(char *line);
void	add_env_elem(t_env *env, t_env_elem *new);
t_env_elem	*search_env_elem(t_env *env, char *key);
void	del_env_elem(t_env *env, t_env_elem *elem);

//error
int	ft_puterr(char *cmd, char *arg, char *msg, int errnum);
int	ft_perror(char *msg, char *utils);

#endif

