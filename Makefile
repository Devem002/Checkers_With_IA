CXXFLAGS =	-O0 -g -Wall -fmessage-length=0 -std=gnu++11

OBJS =	CheckersIA.o utils/SDLfunctions.o objects/Piece.o objects/Game.o objects/Table.o objects/Drawable.o objects/Player.o objects/players/IA.o objects/players/Human.o objects/players/IAmove.o  objects/players/IATable.o objects/TableBase.o

LIBS =	-lSDL -lSDL_image

TARGET =	CheckersIA

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
