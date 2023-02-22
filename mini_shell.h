/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:36:00 by sben-ela          #+#    #+#             */
/*   Updated: 2023/02/22 16:53:47 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef MINI_SHELL_H
# define  MINI_SHELL_H

#define    CMD 3
#define    REDIR_INPUT 0
#define    REDIR_OUTPUT 1
#define    DELIMITER 4
#define    APPEND 5

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

void	execute(t_shell *shell, char ***env);
void    ft_error(char *str);
// int		ft_strchr(char *str, char c);
char	**ft_split(char const *str, char c);
void    ft_execute(t_shell *shell, char **env);
void	whatever(t_shell *shell, char **env);
char	*parse_redirect(char *line);

//utils
int	handle_couts(t_shell *shell);
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

char	**ft_split_v2(char const *str, char c);

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
char	*expand_env(char *line, char **env);
char	*get_expanded_value(char **line, char **env);
char	*search_env_var(char *key, char **env);

int	ft_isalnum(int c);
char	*ft_itoa(int n);

//error
int	ft_puterr(char *cmd, char *arg, char *msg, int errnum);
int	ft_perror(char *msg, char *utils);

int    ft_strchr(char *s, int c);
int        ft_strcmp(char *s1, char *s2);
int        ft_strlen(char *str);
char    **ft_split_v2(char const *str, char c);
char    *parse_redirect(char *line);
//util
int        ft_isalpha(int c);
int        count_redirect(char *line);
t_shell    *ft_lstlast(t_shell *lst);
void    ft_lstadd_back(t_shell **lst, t_shell *new);
int        count_char(char *str, char c);
char    *handle_param(char *str, char c);
char    *ft_strtrim(char *s1, char *set);
int        ft_strncmp(char *s1, char *s2, unsigned int n);
char    *ft_strjoin(char *left_str, char *buff);
void    ft_putstr_fd(char *s, int fd);
int        parse_syntax(char *line);
int        ft_checkspace(const char *str);
int        count_single_couts(char *line);
int        count_double_couts(char *line);
char    **second_split(char const *s, char c);
char       *get_value(char *str,char **env);
int        ft_isalnum(int c);
char    *ft_strnstr(const char *haystack, const char *needle, size_t len);
char    *ft_strdup(char *source);
int handle_pipes(char *line);


// builtin
int	cd_builtin(char **cmd, char ***env);
int	echo_builtin(char **cmd);
int env_builtin(char **cmd, char **env);
int exit_builtin(char **cmd, char **env);
int	export_builtin(char ***ev, char **cmd);
int	pwd_builtin(char *cmd);
int	unset_builtin(char **cmd, char ***ev);


#endif

