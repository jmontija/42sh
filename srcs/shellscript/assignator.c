/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanain <vdanain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 23:53:50 by vdanain           #+#    #+#             */
/*   Updated: 2016/12/11 17:34:56 by vdanain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fortytwo.h"

/*
**	handler de l'assignation simple
*/

static void		*simple_assignator(char *value, int *type)
{
	int		*ret;

	*type = type_guesser(value);
	if (*type == STR_T)
		return ((void *)value);
	ret = (int *)malloc(sizeof(int));
	*ret = ft_atoi(value);
	return ((void *)ret);
}

static void		*handler_numb_op(char **clean, char op, int *type)
{
	char	*ret;
	void	*r_ret;

	*type = NUMBER_T;
	ret = NULL;
	r_ret = NULL;
	if (op == '/' && ft_atoi(clean[1]) == 0)
		return (NULL);
	if (op == '+')
		ret = ft_itoa(ft_atoi(clean[0]) + ft_atoi(clean[1]));
	if (op == '-')
		ret = ft_itoa(ft_atoi(clean[0]) - ft_atoi(clean[1]));
	if (op == '*')
		ret = ft_itoa(ft_atoi(clean[0]) * ft_atoi(clean[1]));
	if (op == '/')
		ret = ft_itoa(ft_atoi(clean[0]) / ft_atoi(clean[1]));
	if (op == '%')
		ret = ft_itoa(ft_atoi(clean[0]) % ft_atoi(clean[1]));
	r_ret = simple_assignator(ret, type);
	ft_strdel(&ret);
	return (r_ret);
}

static void		*handler_str_conc(char **clean, int *type)
{
	char	*ret;

	*type = STR_T;
	ret = ft_strjoin(clean[0], clean[1]);
	return ((void *)ret);
}

static void		*handler_op(char *value, int *type, char op)
{
	char		**clean;
	int			types[2];
	void		*ret;

	ret = NULL;
	clean = ft_strsplit(value, op);
	if (!clean[1])
	{
		ft_freestrtab(&clean);
		return (NULL);
	}
	ft_my_trim(&clean[0]);
	ft_my_trim(&clean[1]);
	var_replacer(get_script(NULL), &clean[0]);
	var_replacer(get_script(NULL), &clean[1]);
	types[0] = type_guesser(clean[0]);
	types[1] = type_guesser(clean[1]);
	if (types[0] == types[1] && types[0] == NUMBER_T)
		ret = handler_numb_op(clean, op, type);
	if (types[0] == types[1] && types[0] == STR_T && op == '+')
	{
		ret = handler_str_conc(clean, type);
	}
	ft_freestrtab(&clean);
	return (ret);
}

/*
**	handler de l'assignation
*/

void			*assignator(t_assign *assign, int *type)
{
	if (!assign->value)
		return (NULL);
	if (check_op(assign->value) > 1 && check_if_path(assign->value))
		return (NULL);
	if (ft_strchr(assign->value, '+'))
		return (handler_op(assign->value, type, '+'));
	else if (ft_strchr(assign->value, '-'))
		return (handler_op(assign->value, type, '-'));
	else if (ft_strchr(assign->value, '*'))
		return (handler_op(assign->value, type, '*'));
	else if (ft_strchr(assign->value, '/'))
	{
		if (check_if_path(assign->value))
			return (handler_op(assign->value, type, '/'));
		else
			return (simple_assignator(assign->value, type));
	}
	else if (ft_strchr(assign->value, '%'))
		return (handler_op(assign->value, type, '%'));
	else
	{
		var_replacer(get_script(NULL), &assign->value);
		return (simple_assignator(assign->value, type));
	}
}
