#include <string>
#include <cmath>
#include <stdio.h>
#include <iostream>
using namespace std;

bool friendly_fire_(char desk[8][8], int y2, int x2, int &borw)
{
	if (desk[y2][x2]  >= 'a'  and borw == 0)
	{
		return true;
	}
	if (desk[y2][x2]  < 'Z' and borw == 1)
	{
		return true;
	}
	return false;
}

bool granica(string xod, const int size_str)
{
	int granica = 0;
	for(int i=0; i < size_str; i++) 
	{
    	if ((xod[i] >= 'a' && xod[i] <= 'h') || (xod[i] >= '0' && xod[i] <= '9'))
		{ 
    		granica++;
		}
	}
	if(granica != 4)
	{
		return false;
	}
	return true;
}

bool white(char desk[8][8], int y, int x, int &borw)
{
	if (desk[y][x] < 'Z')
	{
		borw++;
		return true;	
	}
	return false;
}

bool black(char desk[8][8], int y, int x, int &borw)
{
	if(desk[y][x] > 'a')
	{
		borw--;
		return true;
	}
	return false;
}

bool figure(char desk[8][8],int y, int x, char xod)
{
	if ((xod+32) == desk[y][x] || xod == desk[y][x])
	{
		return true;
	}
	else return false;
} 

bool pawn(char desk[8][8], int y, int x) 
{
	if ((desk[y][x]=='P')||(desk[y][x]=='p')) 
	{
		return true;
	}
	else return false;
}

bool type(char desk[8][8],int y, int x, int y2, int x2, char xod, bool &friendly_fire, int &borw)
{
	bool t = false;
	if (xod == '-' && desk[y2][x2] == ' ' && desk[y][x] != ' ')
	{
		t = true;
		return t;
	}
	if (xod == 'x' && desk[y2][x2] != ' ' && desk[y][x] != ' ')
	{
		friendly_fire = friendly_fire_(desk, y2, x2, borw);
		t = true;
		return t;
	}
	return t;
}

bool move(char desk [8][8], int y, int x, int y2, int x2) 
{
	int dx, dy;
	if (desk[y][x] == 'N' || desk[y][x] == 'n') 
	{
		dx = x2-x;
		dy = y2-y;
		if (abs(dx)==2 and abs(dy)==1) 
		{
			return true;
		}
		if (abs(dx)==1 and abs(dy)==2) 
		{
			return true;
		}
		else return false;
	}
	if (desk[y][x] == 'B' || desk[y][x] == 'b') 
	{
		int i, j;
		dx = x2-x;
		dy = y2-y;
		if (abs(dx)!=abs(dy)) 
		{
			return false;
		}
		cout << abs(dx) << " " << abs(dy) << endl;
		dx/=abs(dx);
		dy/=abs(dy);
		for (i=x+dx, j=y+dy; i != x2; i+=dx, j+=dy) 
		{
			cout << desk[j][i] << " " << j << " " << i << endl;
			if(desk[j][i]!=' ') 
			{
				return false;
			}
		}
		return true;
	}
	if (desk[y][x] == 'R' || desk[y][x] == 'r') 
	{
		int i, j;
		dx = x2-x;
		dy = y2-y;
		cout << abs(dx) << " " << abs(dy) << endl;
		if (dx != 0 && dy == 0) 
		{
			dx/=abs(dx);
			for (i = x+dx, j = y+dy; i != x2; i+=dx)
			{
				cout << desk[j][i] << " " << j << " " << i << endl;
				if(desk[j][i]!=' ') 
				{
					return false;
				}
			}
			return true;
		}
		if (dy != 0 && dx == 0)
		{
			dy/=abs(dy);
			for (i = x+dx, j = y+dy; j != y2; j+=dy)
			{
				cout << desk[j][i] << " " << j << " " << i << endl;
				if(desk[j][i]!=' ') 
				{
					return false;
				}
			}
			return true;
		}
		return false;
	} 	
	else return false;
}

void print(char desk[8][8]) 
{
    for (int i = 0; i < 8; ++i) 
	{
        printf("%d ", 8 - i);
        for (int j = 0; j < 8; ++j) 
		{
            printf("%c ", desk[i][j]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}
