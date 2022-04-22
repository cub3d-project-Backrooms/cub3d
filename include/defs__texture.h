#ifndef DEFS__TEXTURE_H
#define DEFS__TEXTURE_H

typedef enum e_texdata
{
	TEX__AMOUNT = 4,
	TEX__WIDTH = 64,
	TEX__HEIGHT = 64,
	TEX__WALL__NORTH = 0,
	TEX__WALL__SOUTH,
	TEX__WALL__EAST,
	TEX__WALL__WEST,
	TEX__FLOOR,
	TEX__CEILING0,
	TEX__CEILING1,
}	t_texdata;

#define FLOOR_PATH "texture/backroom/floor1.xpm"
#define CEILING_PATH "texture/backroom/ceiling0.xpm"
#define CEILING2_PATH "texture/backroom/light0.xpm"

#endif /* DEFS__TEXTURE_H */
