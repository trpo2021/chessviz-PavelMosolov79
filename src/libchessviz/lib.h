#ifndef LIBCHESS_H
#define LIBCHESS_H
#include <string>
using namespace std;

bool friendly_fire_(char desk[8][8], int y2, int x2, int &borw);
bool granica(string xod, const int size_str);
bool type(char desk[8][8],int y, int x, int y2, int x2, char xod, bool &friendly_fire, int &borw);
bool white(char desk[8][8], int y, int x, int &borw);
bool black(char desk[8][8], int y, int x, int &borw);
bool figure(char desk[8][8],int y, int x, char xod);
bool pawn(char desk[8][8], int y, int x);
//bool King(char desk[8][8], int y, int x);
//bool Quenn(char desk[8][8], int y, int x);
//bool Elepnant(char desk[8][8], int y, int x);
//bool Horse(char desk[8][8], int y, int x);
//bool Rook(char desk[8][8], int y, int x);
bool move(char desk [8][8], int y, int x, int y2, int x2);
void print(char desk[8][8]);
#endif
