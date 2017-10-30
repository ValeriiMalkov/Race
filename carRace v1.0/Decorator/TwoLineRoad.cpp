#include"TwoLineRoad.h"
TwoLineRoad::TwoLineRoad(Asphalt* asphalt) : Road(asphalt) { add(); }
void TwoLineRoad::operator=(const TwoLineRoad& two) {}
TwoLineRoad::~TwoLineRoad() {}
void TwoLineRoad::add()
{
	for (int i = 0; i < size_; ++i) {
		for (int j = 0; j < size_; ++j) {
			map_[i][0] = '|';
			map_[i][size_ - 2] = '|';
			map_[i][(size_ - 2) / 2] = '|';
			map_[i][j] = ' ';
		}
	}
}
void TwoLineRoad::viewer()
{
	Road::viewer();
}