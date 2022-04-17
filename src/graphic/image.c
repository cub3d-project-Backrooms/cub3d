#include "std__types__error.h"
#include "std__types__math.h"
#include "types__mlx.h"

t_image image__new(t_mlx__ref mlx_ref, t_sizevec size) {
  t_image image;

  image.size = size;
  image.img_ref = mlx_new_image(mlx_ref, size.width, size.height),
  image.mlx_ref = mlx_ref,
  image.data_addr = mlx_get_data_addr(image.img_ref, &image.bits_per_pixel,
                                      &image.size_line, &image.endian);
  return image;
}

void image__delete(t_image image) {
  mlx_destroy_image(image.mlx_ref, image.img_ref);
}
