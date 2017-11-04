#include"Line.h"
Line::Line(shared_ptr<Road>& road, int x) : coord_(x), Decor(road) { add(); }
Line::~Line() {}
void Line::add()
{
	for (int i = 0; i < size_; ++i) {
		for (int j = 0; j < size_; ++j) {
			(*road_->getMap())(i, coord_) = '|';
		}
	}
}