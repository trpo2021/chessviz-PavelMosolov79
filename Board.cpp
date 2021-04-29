#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <string>
#include "lib.h"

using namespace std;

int main() 
{
	setlocale(LC_ALL, "Russian");
	int borw = 0;
	char desk[8][8];
	
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            desk[i][j] = ' '; 
            
    for (int i = 0; i < 8; ++i) 
	{
        desk[1][i] = 'p';
        desk[6][i] = 'P';
    }
    desk[0][0] = 'r';
    desk[0][7] = 'r';
    desk[7][0] = 'R';
    desk[7][7] = 'R';
    desk[0][1] = 'n';
    desk[0][6] = 'n';
    desk[7][1] = 'N';
    desk[7][6] = 'N';
    desk[0][2] = 'b';
    desk[0][5] = 'b';
    desk[7][2] = 'B';
    desk[7][5] = 'B';
    desk[0][3] = 'q';
    desk[7][3] = 'Q';
    desk[0][4] = 'k';
    desk[7][4] = 'K';
    
    print(desk);
    
    printf("\nХод Белых: \n");
    
    do 
	{	
    	bool flag = false, side, friendly_fire = true;
    	const int size_str = 10;
		int i = 0;
    	string xod;
    	xod.clear();
    	cin >> xod;
    	
    	if (xod[0] >= 'A' && xod[0] <= 'Z') 
			i++;
    	
    	printf("\n");
    	
        int x, x2, y, y2;
        x = xod[0+i] - 'a';
        x2 = xod[3+i] - 'a';
        y = xod[1+i] - '1';
        y2 = xod[4+i] - '1';
        y = 7 - y;
        y2 = 7 - y2;
        
		if (granica(xod, size_str) == false)
		{
        	cerr << "Нельзя выйти за пределы доски!\n";
        	continue;
		}        
        
        if (xod.empty() || xod.size() > size_str) 
		{
    		cout << "Вы ввели некоректный ход!" << endl;
    		continue;
		} 
		
        if(i == 1)
		{
	        if (figure(desk, y, x, xod[0]) == false)
			{
	        	cout << "Вы взяли фигуру другого игрока!\n";
	        	continue;
			}
		}
		
		if(i == 0) 
		{
			if (pawn(desk, y, x) == false) 
			{
				cout << "Это не пешка!\n";
	        	continue;
			}
		}
		
		if (type(desk, y, x, y2, x2, xod[2+i], friendly_fire, borw) == false)
		{
			cout << "Вы выбрали неккоректное действие!\n"; 	
			continue;
		}
        
		if (i == 1) 
		{
			if (move(desk, y, x, y2, x2) == false) 
			{
				cout << "Нельзя так походить!\n"; 
				continue;
			}
		}
				
		if (friendly_fire == false)
		{
			cout << "На чьей вы стороне?\n";
			continue;
		}
		
        switch(borw)
		{
        	case 0: 
				side = white(desk, y, x, borw);
        		break;
        	case 1: 
				side = black(desk, y, x, borw);
				break;
		}
		
		if(side == false)
		{
			cout << "Ошибка: Сейчас ходит противоположная сторона\n";
			continue;
		}	
	
		cout << borw << " \n";  			
        
        desk[y2][x2] = desk[y][x];
        desk[y][x] = ' ';
        print(desk);
        
        switch (borw) 
		{
        	case 1:
        		printf("\nХод чёрных: \n");
        		break;
        	case 0:
        		printf("\nХод белых: \n");
        		break;
		}
    	
	} while(true);
	return 0;
}


