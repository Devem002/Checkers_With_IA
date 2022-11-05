#include "IA.h"
#include <iostream>
#include <queue>
#include <limits.h>

using namespace std;

AI::AI(pc_color color, Table *table) : Player(color, table){
	isPlayerHuman = false;
}

//Metodo para liberar la memoria del arbol
void AI::clearTree(vector<AImove *> &tree){
	for(vector<AImove *>::iterator i = tree.begin(); i != tree.end(); i++){
		AImove *m = *i;
		if(m->next.size() != 0)
			clearTree(m->next);
		delete m;
	}
}


void AI::click(int x, int y){

}

GameMove * AI::play(){
	vector<AImove *> moveList;
	vector<Piece> *myPieces = getPieces();

	for(int i = 0; i < myPieces->size(); i++){
		vector<AImove *> moves = possibleMovesForPiece(myPieces->at(i), NULL);
		moveList.insert( moveList.end(), moves.begin(), moves.end() );
	}
	//crea el arbol minimax
	vector<AImove *> nowList = moveList;
	vector<AImove *> nextList;
	for(int i = 0; i < this->maxDepth - 1; i++){
		//recorre la rama
		for(int j = 0; j < nowList.size(); j++){
			AImove *m = nowList[j];
			AITable &table = m->tableGame;
			vector<Piece> *myPieces = getPieces(table);
			//recorre las ramas y genera los movimientos posibles
			for(int k = 0; k < myPieces->size(); k++){
				vector<AImove *> moves = possibleMovesForPiece(myPieces->at(k), m);
				nowList[j]->next.insert(nowList[j]->next.end(), moves.begin(), moves.end());
				nextList.insert(nextList.end(), moves.begin(), moves.end() );
			}
		}
		//siguente rama
		nowList = nextList;
		cout<<"Pieza:"<<i<<" movimientos posibles: "<<nowList.size()<<endl;
		nextList.clear();
	}

	//obtiene el mejor movimiento
	GameMove * retMove = new GameMove();
	AImove *aiMove = getBestMove(moveList,0, this->maxDepth);
	retMove->start = aiMove->m.start;
	retMove->end   = aiMove->m.end;
	//cout<<"Size of list = "<<moveList.size()<<endl;

	this->clearTree(moveList);

	return retMove;
}

AImove* AI::getBestMove (vector<AImove *> &moveList, int layer, int maxLayer){
	if(layer == maxLayer - 1){

		int min = INT_MAX;
		for(int j = 0; j < moveList.size(); j++){
			if(moveList[j]->score < min)
				min = moveList[j]->score;
		}
		moveList[0]->previous->score += min;
		if(maxLayer != 1){
			return NULL;
		}
	}else{

		for(int j = 0; j < moveList.size(); j++)
			getBestMove(moveList[j]->next,layer + 1, maxLayer);
		int min = INT_MAX;
		for(int j = 0; j < moveList.size(); j++){
			if(moveList[j]->score < min)
				min = moveList[j]->score;
		}

		if(moveList[0]->previous != NULL)
			moveList[0]->previous->score += min;
	}

	if(layer == 0){
		AImove *retMove;
		int maxV = INT_MIN;
		for(int i = 0; i < moveList.size(); i++)
			if(moveList[i]->score > maxV){
				maxV = moveList[i]->score;
				retMove = moveList[i];
			}
		return retMove;
	}
	return NULL;
}

void AI::draw(SDL_Surface* screen){
	
}

void AI::mouseMove(int x, int y){


}


AImove* AI::createTree(int treeDepth){
	AImove* gameTree;
	bool aiPlay = true;
	for(int i = 0; i < treeDepth; i++){

		aiPlay = !aiPlay;
	}

	return gameTree;
}

AI::~AI() {
	// TODO Auto-generated destructor stub
	
}

bool AI::checkPositionValid(position &p){
	if(p.first >= 0 && p.first <= 7 &&
	   p.second >= 0 && p.second <= 7)
		return true;
	return false;
}
