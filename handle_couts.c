#include "mini_shell.h"

int	count_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str [i])
	{
		while (str [i] && str [i] == c)
			i++;
		if (str [i])
			count ++;
		while (str[i] && str [i] != c)
		i++;
	}
	return(count);
}

int count_char(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while(str[i])
	{
		if(str[i] == c)
			count++;
		i++;
	}
	return(count);
}
char *handle_param(char *str)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	dst = malloc(ft_strlen(str) - (count_char(str, '"') - count_char(str, '\'')) + 1);
	if(!dst)
		return(0);
	while(str[i])
	{
		if(str[i] != '"' && str[i] != '\'')
			dst[j++] = str[i];
		i++;
	}
	dst[j] = '\0';
	return(dst);
}

int	handle_couts(t_shell *shell)
{
	while(shell)
	{
		if(count_char(shell->cmd, '\'') % 2 != 0 || count_char(shell->cmd, '\"') % 2 != 0
		|| count_char(shell->cmd, '\"') == ft_strlen(shell->cmd)
		|| count_char(shell->cmd, '\'') == ft_strlen(shell->cmd))
		{
			ft_error("    mini_shell : command not found");
			return(1);
		}
		// this function return a new cmd without couts if cmd with param becouse
		// in bash comand between couts it working for example "ls" but ls -"l" not working
		if(count_words(shell->cmd, ' ') > 1)
			shell->cmd = handle_param(shell->cmd);
		// in this condition i want to make without couts in the bigining or the last
		// becousse in bash command without param between couts it working
		else if(count_words(shell->cmd, ' ') == 1)
		{
			shell->cmd = ft_strtrim(shell->cmd, "\"");
			shell->cmd = ft_strtrim(shell->cmd, "\'");
		}
		shell = shell->next;
	}
	return(0);
}