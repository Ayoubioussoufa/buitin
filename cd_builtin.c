/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:13:14 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/22 10:01:53 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

// char	*ft_strdup(const char *source)
// {
// 	char	*mem;
// 	int		i;

// 	i = 0;
// 	mem = malloc((ft_strlen(source) + 1) * sizeof(char));
// 	if (!mem)
// 		return (NULL);
// 	while (source[i] != '\0')
// 	{
// 		mem[i] = source[i];
// 		i++;
// 	}
// 	mem[i] = '\0';
// 	return (mem);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*mem;
// 	size_t	lengthstring;
// 	size_t	i;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	lengthstring = ft_strlen(s);
// 	if (!s[0] || start >= lengthstring || len == 0)
// 		return (ft_strdup(""));
// 	if (len > (lengthstring - start))
// 		len = lengthstring - start;
// 	mem = malloc(len + 1);
// 	if (!mem)
// 		return (NULL);
// 	while (len > i && s[start] != '\0')
// 		mem[i++] = s[start++];
// 	mem[i] = '\0';
// 	return (mem);
// }


int	check(char const *set, char s)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrimbehind(char *s1, char const *set)
{
	int		i;
	int		len;
	char	*mem;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	len = ft_strlen(s1) - 1;
	while (s1[len] && s1[len] != '/')
		len--;
	mem = ft_substr(s1, i, len - i);
	return (mem);
}

char	**get_pathcd(char **env, int index)
{
	char	**paths;
	char	*cmd;
	int		i;

	i = 0;
	while (env[i])
	{
		if (index == 0)
		{
			if (ft_strnstr(env[i], "OLDPWD", 7))
			{
				paths = ft_split(env[i] + 7, ':');
			// if (!paths)
				// error("Split function failed", 1);
				return (paths);
			}
			i++;
		}
		else if (index == 1)
		{
			if (ft_strnstr(env[i], "HOME", 4))
			{
				paths = ft_split(env[i] + 5, ':');
			// if (!paths)
				// error("Split function failed", 1);
				return (paths);
			}
			i++;
		}
	}
	return (paths);
}

void	protection_chdir(int i)
{
	if (i == 0)
		return ;
	else
	{
		// error();
		printf("OMG FIX YOUR SHIT DUMBASS\n");
		exit(1);
	}
}

int cd_builtin(char **env, char **cmd)
{
	char	**path;
	char	*cmds;
	char	*command;
	char	get[256];
	int	i;

	i = 0;
	if (!strcmp(cmd[0], "cd") || ((!strcmp(cmd[0], "~")) && !cmd[1]))
	{
		path = get_pathcd(env, 1);
		i = chdir(*path);
		protection_chdir(i);
	}
	else if (!strcmp(cmd[1], "-"))
	{
		path = get_pathcd(env, 0);
		printf("%s\n", path[0]);
		i = chdir(*path);
		protection_chdir(i);
	}
	else if (!strcmp(cmd[1], ".."))
	{
		i = chdir(cmd[1]);
		protection_chdir(i);
	}
	else if (!strcmp(cmd[1], "."))
		;
	else
	{
		if (access(cmd[1], F_OK) == 0)
		{
			if (access(cmd[1], R_OK))
				printf("plop"),exit(1);//error
			else if (access(cmd[1], W_OK))
				printf("ploplo"),exit(1);//error
			else if (access(cmd[1], X_OK))
				printf("plopl"),exit(1);//error
		}
		else
			printf("ploplol"),exit(1);//error
		i = chdir(cmd[1]);
		protection_chdir(i);
		printf("%s\n", getcwd(get, sizeof(get)));
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	char	cmds[256];
	char	**cmd;

	cmd = ft_split("cd ~", ' ');
	cd_builtin(env, cmd);
}

// ~ cd 
// depends on ch7sl mn n9ta anrj3o lour

/*
void	set_dir(t_env *ev, char *cwd, char *owd)
{
	t_env_elem	*env_elem;

	env_elem = search_env_elem(ev, "PWD");
	if (!env_elem)
		return ;
	env_elem->value = ft_strdup(cwd);
	env_elem = search_env_elem(ev, "OLDPWD");
	if (!env_elem)
		return ;
	env_elem->value = ft_strdup(owd);
}

int	cd_builtin(char **cmd, char ***env)
{
	t_env		*ev;
	char		cwd[1024];
	char		owd[1024];

	ev = create_env(*env);
	getcwd(owd, sizeof(owd));
	if (!cmd[1])
	{
		if (chdir(expand_env("$HOME", *env)) != 0)
			return (ft_puterr(cmd[0],
					expand_env("$HOME", *env), NULL, 1));
	}
	else
	{
		if (chdir(cmd[1]) != 0)
			return (ft_puterr(cmd[0], cmd[1], NULL, 1));
	}
	getcwd(cwd, sizeof(cwd));
	set_dir(ev, cwd, owd);
	*env = convert_array(ev);
	status = EXIT_SUCCESS;
	return (EXIT_SUCCESS);
}
*/