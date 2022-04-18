#ifndef GRAPHIC_H
#define GRAPHIC_H

//@func
/*
** < image.c > */

t_image	image__new(t_mlx__ref mlx_ref, t_sizevec size);
void	image__delete(t_image image);
#endif
