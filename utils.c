/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:24:04 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/19 15:54:54 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

// int ft_strlen(char *str)
// {
//     int i;

//     i = 0;
//     while(str[i])
//         i++;
//     return(i);
// }

int		ft_strcmp(char *s1, char *s2)
{
 	int	i;
 
 	i = 0;
 	while (s1[i] == s2[i] && s1[i] && s2[i])
 		i++;
 	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// int ft_strchr(char *str, char c)
// {
// 	int i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == c)
// 			return(i);
// 		i++;
// 	}
// 	return(0);
// }

int	ft_lstsize(t_shell *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*s;
// 	int		i;
// 	int		j;
// 	int		k;

// 	i = 0;
// 	k = 0;
// 	j = 0;
// 	if (!s1 || !s2)
// 		return (NULL);
// 	s = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
// 	if (!s)
// 		return (NULL);
// 	while (s1[j])
// 		s[i++] = s1[j++];
// 	while (s2[k])
// 		s[i++] = s2[k++];
// 	s[i] = '\0';
// 	return (s);
// }