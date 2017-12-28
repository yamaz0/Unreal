#include "Path.h"



Path::Path()
{
	
}


Path::~Path()
{
}

void Path::setPath(float x_, float y_, sf::Vector2f dist_)
{
	x = x_;
	y = y_;
	distance = dist_;
}

bool Path::check(float x_, float y_)
{
	if (!(x+distance.x > x_ && x < x_) 
		&& !(y+ distance.y > y_ && y < y_))
		return true;
	return false;
}