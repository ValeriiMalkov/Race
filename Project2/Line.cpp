#include"Line.h"
Line::Line(Road* road, int x) : coord_(x), Decor(road) { add(); }
//void TwoLineRoad::operator=(const TwoLineRoad& two) {}
Line::~Line() {}
void Line::add()
{
	for (int i = 0; i < size_; ++i) {
		for (int j = 0; j < size_; ++j) {
			map_[i][coord_] = '|';

		}
	}
}