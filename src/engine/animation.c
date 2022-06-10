#include "types__engine.h"

bool	is_other_frame(int frame)
{
	return (frame > NUM_FRAMES / 2);
}

void	engine__change_frames(t_engine *this)
{
	this->frame++;
	if (this->frame > NUM_FRAMES)
		this->frame = 0;
}

