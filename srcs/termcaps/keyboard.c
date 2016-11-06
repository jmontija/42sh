/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <jmontija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:05:11 by jmontija          #+#    #+#             */
/*   Updated: 2016/11/06 18:07:10 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fortytwo.h"

int		ft_is_printable(char *order)
{
	int	i;

	i = -1;
	while (order[++i] != '\0')
		if (ft_isprint(order[i]) == false)
			return (0);
	return (1);
}

int		key_selection_next(t_group *grp, char *order, int key)
{
	if (key == HOME)
		ft_go_home(grp);
	else if (key == END)
		ft_go_end(grp);
	else if (key == ALT_L)
		ft_prev_word(grp);
	else if (key == ALT_R)
		ft_next_word(grp);
	else if (key == ARROW_L || key == ARROW_R ||
		key == ARROW_U || key == ARROW_D)
		handling_arrow(grp, key);
	else if (ft_is_printable(order))
		print_cmd(grp, order);
	else
		return (0);
	return (1);
}

int		key_selection(t_group *grp, char *order)
{
	int	key;

	key = KEY(order[0], order[1], order[2], order[3]);
	if (key == ENTER)
		return (key);
	// if (key != ARROW_U && key != ARROW_D)
	// 	grp->curr_hist = NULL;
	if (key == CTRL_D)
		handling_ctrl_d(grp);
	else if (key == DEL)
		remove_line(grp);
	else if (key == BACKSPACE || key == DEL)
		handling_backspace(grp);
	else if (key == CTRL_L)
		handling_clear_screen(grp);
	else if (key == PAGE_UP)
		ft_go_up(grp);
	else if (key == PAGE_DOWN)
		ft_go_down(grp);
	else
		return (key_selection_next(grp, order, key));
	return (1);
}

// void	read_fd_in(t_group *grp, char *order)
// {
// 	int	i;

// 	i = -1; 
// 	while (order && order[++i] != '\0')
// 	{
// 		if (order[i] != '\n')
// 			TERM(cmd_line) = ft_charjoin(TERM(cmd_line), order[i]);
// 		else if (order[i + 1] != '\0')
// 			TERM(cmd_line) = JOIN(TERM(cmd_line), " ; ");
// 	}
// 	grp->exit[0] = true;
// }

// void	check_heredoc(t_group *grp)
// {
// 	int	i;
// 	char c;
// 	char *eof;

// 	i = -1;
// 	n = false;
// 	while (TERM(cmd_line)[++i] != '\0')
// 	{
// 		c = TERM(cmd_line)[i];
// 		if (TERM(cmd_line)[i + 1] != '\0')
// 			n = TERM(cmd_line)[i + 1]
// 		if (c == '<' && n == '<' )
// 			heredoc = true;
// 		else if (heredoc == true && c != ' ')
// 			eof = ft_charjoin(eof, c);
// 		else if (heredoc == true && c == ' ')
// 			get_cmd
// 		REMOVE(&prev_char);
// 		prev_char = SDUP(order);
// 	}
// }

void	get_cmd(t_group *grp, int fd)
{
	int		ret;
	char	*prev_char;
	int		heredoc;
	char	order[BUF_SIZE + 1];

	ft_bzero(order, BUF_SIZE + 1);
	prev_char = NULL;
	heredoc = false;
	while ((ret = read(fd, order, BUF_SIZE)) > 0)
	{
		order[ret] = '\0';
		if (key_selection(grp, order) == '\n' && ft_escape(grp) == 0)
			break ;
		ft_bzero(order, BUF_SIZE + 1);
	}
	if (TERM(cmd_quote) != NULL)
		fill_cmd_line(grp);
	ft_go_end(grp);
	//check_heredoc(grp);
	//ret == 0 ? read_fd_in(grp, tmp) :
	ft_putchar_fd('\n', 2);
	reset_edl(grp);
	ft_bzero(order, BUF_SIZE + 1);
}
