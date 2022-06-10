#include "types__engine.h"

bool	engine__is_other_frame(t_engine *this)
{
	return (this->frame > NUM_FRAMES / 2);
}

void	engine__change_frames(t_engine *this)
{
	this->frame++;
	if (this->frame > NUM_FRAMES)
		this->frame = 0;
}

