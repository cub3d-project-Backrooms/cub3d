#include <stdio.h>
#include "mlx.h"

int	key_hook(int keycode)
{
	printf("pressed %d\n", keycode);
	return (0);
}

int main(void)
{
	printf("Hello, World!\n");
	void * mlx = mlx_init();
	void * win = mlx_new_window(mlx, 100, 100, "Hello, World!");

	mlx_key_hook(win, NULL, NULL);
	mlx_do_key_autorepeaton(mlx);
	mlx_loop(mlx);
	return 0;
}
