/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:09:29 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/23 15:58:47 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

void	unset_env(char *cmd, t_env *env)
{
	t_env_elem	*elem;

	elem = NULL;
	if (cmd && !ft_isalpha(cmd[0]))
	{
		printf("minishell: unset: `%s`: not a valid identifier\n",
			cmd);
		//status
	}
	else
	{
		elem = search_env_elem(env, cmd);
		if (elem)
			del_env_elem(env, elem);
	}
}

int	unset_builtin(char **cmd, char ***ev)
{
	t_env	*env;
	int		i;

	i = 1;
	env = NULL;
	env = create_env(*ev);
	while (cmd[i])
	{
		unset_env(cmd[i], env);
		free(cmd[i]);
		i++;
	}
	// int j = 0;
	// i = 0;
	// while (ev)
	// {
	// 	j = 0;
	// 	while(ev[i][j])
	// 		free(ev[i][j++]);
	// 	free(ev[i]);
	// 	i++;
	// }
	// free(ev);
	*ev = convert_array(env);
	del_env(env);
	return (1); //status hnayya succesfully
}
//STATUS needed !

// int	main(int ac, char **av, char **env)
// {
// 	(void)ac;
// 	(void)av;
// 	char **read;
// 	int	i;
	
// 	read = ft_split("unset ebbeb", ' ');
// 	unset_builtin(read, &env);
// 	i = 0;
// 	while (env[i])
// 		printf("%s\n", env[i++]);
// 	system("leaks a.out");
// }