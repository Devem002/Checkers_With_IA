#ifndef TABLE_H_
#define TABLE_H_

#include "../utils/SDLfunctions.h"
#include "Drawable.h"
#include <vector>
#include "Piece.h"
#include <utility>
#include "Utils.h"
#include "TableBase.h"


using namespace std;

class Table : public Drawable, public TableBase{

public:
	Table();
	Table(pc_color color_up);
	virtual ~Table();
	void draw(SDL_Surface* screen);

};

#endif
