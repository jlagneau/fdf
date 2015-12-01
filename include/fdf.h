/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 08:36:28 by jlagneau          #+#    #+#             */
/*   Updated: 2013/12/22 17:40:55 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include <libft.h>
# define PROGRAM_NAME       "FdF"
# define HEIGHT             800
# define WIDTH              800
# define ESCAPE_KEY         65307
# define ENTER_KEY          65293
# define PAD                5
# define PAD2               6
# define CTE1               0.8
# define CTE2               0.9
# define ABSOLUTE(x)        (x + (x >> 31)) ^ (x >> 31)

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef void	(*t_pers)(int, int, int, t_coord*);

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				bpp;
	int				sl;
	int				end;
	char			*data;
	char			***coord;
	t_pers			pers;
}					t_env;

typedef struct		s_z
{
	int				z1;
	int				z2;
}					t_z;

typedef struct		s_diff
{
	int				x;
	int				y;
	int				dx;
	int				dy;
	int				incx;
	int				incy;
	int				inc1;
	int				inc2;
	int				err;
}					t_diff;

int					init(char ***coord);
char				***arg_getcoord(char *file);
int					draw(t_env *e);
int					event_keyboard_handler(int k, t_env *e);
int					event_mouse_handler(int button, int x, int y, t_env *e);
int					event_expose_handler(t_env *e);
void				print_usage(void);
void				print_debug(char ***coord);
void				get_realcoord_para(int x, int y, int z, t_coord *coord);
void				get_realcoord_iso(int x, int y, int z, t_coord *coord);
int					col(int z1, int z2);
void				switch_perspective(t_env *e);
void				put_pixel(int x, int y, int c, t_env *e);

#endif
