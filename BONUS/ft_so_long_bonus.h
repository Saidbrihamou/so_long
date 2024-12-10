/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:10:27 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/09 12:07:59 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_BONUS_H
# define FT_SO_LONG_BONUS_H

# include <mlx.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <time.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_position
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_data
{
	int		front;
	int		back;
	t_pos	**prev;
	t_pos	*queue;
	t_pos	courrent;
}	t_data_bfs;

typedef struct s_var_cheak
{
	int	n_exit;
	int	n_start;
	int	n_carrot;
	int	y;
	int	x;	
}	t_var_cheak;

typedef struct enemy_imgs
{
	int		ifinsilese;
	void	*fox_up[3];
	void	*fox_down[3];
	void	*fox_lefth[3];
	void	*fox_regth[3];
}	t_enemy_imgs;

typedef struct s_map
{
	void	*empty_space;
	void	*wall;
	void	*center[2];
	void	*exit_map_close;
	void	*exit_map_open;
	void	*player[7];
	void	*collectible;
}	t_map;

typedef struct s_gvar
{
	int				g_count_move;
	int				game_over;
	char			**g_data;
	int				g_count_carrot;
	t_pos			g_pos_door;
	t_pos			*foxes;
	int				count_foxes;
	t_map			g_map;
	t_enemy_imgs	img_fox;
	void			*mlx;
	void			*win;
	t_pos			size;
}	t_vars;

char		*get_next_line(int fd);
char		*ft_strjoin_and_free(const char *buffer, ssize_t	len_buffer, \
										char *temp, size_t *num_line_read);
char		*create_result(char *temp, char *buffer_static[10250], \
													ssize_t num_read, int fd);
void		ft_update_rest_and_temp(char *temp, \
						char *buffer_static[10250], int fd);
size_t		count_newline(char *str[10250], int fd);
void		ft_cat(char *dst, const char *src, size_t len_src);
int			my_free(char **p);

void		exit_and_free(void *mlx, void *win, t_vars *data_g);

t_pos		get_me_pos_player_ordoor(char p_or_e, t_vars *g_data);

void		set_map(void *mlx_and_win[3], t_pos size, t_vars *data_g);
void		set_img_in_map(void *mlx_and_win[3], \
				char img, t_pos pos, t_vars *data_g);
void		main_cheak(char *filename, t_vars *data_g);
void		exit_with_error(char *msg, t_pos size, t_vars *data_g);
void		count_total_carrot(t_vars *data_g);

int			handle_key(int key, void *mlx_and_win[2]);

char		cheak_pathinmap(t_pos pos_obj, char **data_path);
char		**get_map_from_file(char *filename, t_pos *size, t_vars *data_g);
void		open_door( void *mlx_and_win[2], t_vars *data_g);

# define S_PX 50

t_var_cheak	inisialyse(void);

void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_itoa(int n);
int			updata_move(t_vars *data_g);
char		**get_me_data_path(t_pos size, t_vars *data_g);
int			is_equal(t_pos p1, t_pos p2);
void		free_data(char **data_var, t_pos size);
void		set_foxes_in_tab_util(t_vars *data_g);
int			cheakpath_is_valid(t_pos size, t_vars *data_g);
int			cheak_howmanyexit_and_starting_carrot(t_pos size, t_vars *data_g);
t_pos		get_pos_to_move(t_vars *data_g, t_pos start, t_pos end);
char		get_deriction(t_pos p_enemy, t_pos p_to);
void		insialise_fox_img(t_vars *data_g);
void		set_img_for_enemy(t_pos p_to, char img, t_vars *data_g);
void		insialyse_t_data(t_data_bfs *vars, t_pos size, t_pos start);
t_pos		pos_add(t_pos p1, t_pos p2);
void		add_in_queue(t_data_bfs *vars, t_pos pos, t_pos pos_father);
int			is_pos_allowed(char **data, t_pos pos, t_vars *data_g);

#endif
