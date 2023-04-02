#include "Datchik.h"

bool Datchik::cheak(item* D, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (gip((D[i]).get_x(), (D[i]).get_y()) <= radius) return true;
	}
	return false;
}
int Datchik::count(item* D, int size)
{
	int tr = 0;
	for (int i = 0; i < size; i++)
	{
		if (gip((D[i]).get_x(), (D[i]).get_y()) <= radius) tr += 1;
	}
	return tr;
}
void Datchik::set(float x, float y, float r)
{
	pos_x = x;
	pos_y = y;
	radius = r;
}
