#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "move.h"
#include "util.h"

void drawTilte() {
	printf("\n");
	printf("	      #####     #######\n");
	printf("	     #     #    #     #\n");
	printf("	     #     #    #######\n");
	printf("	      #####        #\n");
	printf("	        #      #########\n");
	printf("	        #       #######\n");
	printf("	    #########         #\n");
}

void drawMenu() {
	gotoxy(14, 10);
	printf("   게임시작 ");
	gotoxy(14, 12);
	printf("  사용자추가");
	gotoxy(14, 14);
	printf("     설정   ");
	gotoxy(14, 16);
	printf("   불러오기 ");
	gotoxy(14, 18);
	printf("     종료   ");
}

void drawMenuAnchor(unsigned char now_menu) {
	switch (now_menu)
	{
	case 1:
		drawMenu();
		gotoxy(14, 10);
		printf(">");
		break;
	case 2:
		drawMenu();
		gotoxy(14, 12);
		printf(">");
		break;
	case 3:
		drawMenu();
		gotoxy(14, 14);
		printf(">");
		break;
	case 4:
		drawMenu();
		gotoxy(14, 16);
		printf(">");
		break;
	case 5:
		drawMenu();
		gotoxy(14, 18);
		printf(">");
		break;
	default:
		break;
	}
}

const void PrintLine(int i) {
	unsigned char a = 0xa6;
	unsigned char b[12];

	for (int i = 1; i < 12; i++) {
		b[i] = 0xa0 + i;
	}
	printf("%c%c", a, b[i]);
}

void PrintPlate() {

	PrintLine(3);
	for (int i = 0; i < 17; i++) {
		PrintLine(8);
	}
	PrintLine(4);
	printf("\n");

	for (int i = 0; i < 17; i++) {
		PrintLine(7);
		for (int j = 0; j < 17; j++) {
			PrintLine(11);
		}
		PrintLine(9);
		printf("\n");
	}

	PrintLine(6);
	for (int i = 0; i < 17; i++) {
		PrintLine(10);
	}
	PrintLine(5);
	printf("\n");
}