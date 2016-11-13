/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_init2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanain <vdanain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 17:32:31 by victordanain      #+#    #+#             */
/*   Updated: 2016/11/13 23:02:57 by vdanain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fortytwo.h"

/*
**	verifie si un char est deja present dans la charlist
*/

static int		check_charlist(char *lst, char c)
{
	int		i;

	i = 0;
	while (lst && lst[i])
	{
		if (c == lst[i])
			return (0);
		i++;
	}
	return (1);
}

/*
**	lis tous les noms de commandes et retourne le nb de char differents
**	les composant
*/

char			*get_nbchar(DIR *cur_d, int free)
{
	struct dirent	*cur_e;
	static char		*charlist = NULL;
	int				i;
	char			c[2];
	char			*tmp;

	ft_bzero(c, 2);
	if (free == 1)
	{
		ft_strdel(&charlist);
		return (NULL);
	}
	while ((cur_e = readdir(cur_d)))
	{
		i = 0;
		while (cur_e->d_name[i])
		{
			if (check_charlist(charlist, cur_e->d_name[i]))
			{
				c[0] = cur_e->d_name[i];
				tmp = (charlist == NULL) ? ft_strdup("") : ft_strdup(charlist);
				ft_strdel(&charlist);
				charlist = ft_strjoin(tmp, c);
				ft_strdel(&tmp);
			}
			i++;
		}
	}
	return (charlist);
}

/*
**	return index in the node tab from the char
*/

int				val_tokey(char *charlist, char c)
{
	int		i;

	i = 0;
	while (charlist[i])
	{
		if (charlist[i] == c)
			return (i);
		i++;
	}
	return (0);
}

/*
**	cree un t_path pour une commande
*/

t_path			*init_path(char *name, char *path)
{
	t_path		*new;

	new = (t_path *)malloc(sizeof(t_path));
	new->name = ft_strdup(name);
	new->path = ft_strdup(path);
	return (new);
}
