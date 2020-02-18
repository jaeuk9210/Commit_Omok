#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include "draw.h"
#include "omok.h"

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

void chooseMenu(void) {
	static unsigned char now_menu = 0;
	drawMenuAnchor(1);
	while (_getch() != ' ') {
		char c = _getch();
			switch (c)
			{
			case UP:
				now_menu--;
				now_menu %= 5;
				drawMenuAnchor(now_menu+1);
				break;
			case DOWN:
				now_menu++;
				now_menu %= 5;
				drawMenuAnchor(now_menu+1);
				break;
			default:
				break;
			}
	}
	switch (now_menu)
	{
	case 0:
		gameStart();
		break;
	case 1:
		printf("����ڸ� �߰��մϴ�.");
		break;
	case 2:
		printf("������ �����մϴ�.");
		break;
	case 3:
		printf("������ �ҷ��ɴϴ�.");
		break;
	case 4:
		exit(0);
		break;
	default:
		break;
	}
}