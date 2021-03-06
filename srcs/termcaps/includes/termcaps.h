/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <jtranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:43:24 by jtranchi          #+#    #+#             */
/*   Updated: 2016/11/23 22:57:10 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCAPS_H
# define TERMCAPS_H

typedef struct			s_cmdquote
{
	char				*line;
	int					noeof;
	struct s_cmdquote	*next;
}						t_cmdquote;

typedef struct			s_term
{
	char				*cmd_line;
	char				*cmd_save;
	char				*search;
	int					line;
	int					curs_pos;
	int					cmd_size;
	int					other_read;
	struct s_window		*window;
	struct s_cmdquote	*cmd_quote;
}						t_term;

void					get_cmd(t_group *grp, int fd);
void					ft_go_home(t_group *grp);
void					ft_go_end(t_group *grp);
void					ft_go_up(t_group *grp);
void					ft_go_down(t_group *grp);
void					up_clear_find(t_group *grp, char *name);
void					ft_replace_cursor(t_group *grp);
void					ft_get_cmd(t_group *grp, char *order);
void					print_cmd(t_group *grp, char *order);
void					handling_ctrl_d(t_group *grp);
void					handling_backspace(t_group *grp);
void					ft_left_arrow(t_group *grp);
void					ft_right_arrow(t_group *grp);
void					handling_arrow(t_group *grp, int key);
void					ft_prev_word(t_group *grp);
void					ft_next_word(t_group *grp);
void					handling_clear_screen(t_group *grp);
void					remove_line(t_group *grp);
void					reset_edl(t_group *grp);
int						check_last_char(char *line, int i);
int						ft_escape(t_group *grp);
void					fill_cmd_line(t_group *grp);
int						ft_is_printable(char *order);
void					check_squote_escape(t_group *grp,
										int i, int *ret, int *test);
int						ft_contains(t_group *grp, int i);
int						ft_get_last_eol(t_group *grp);
void					ft_place_to_eof(t_group *grp);

#endif
