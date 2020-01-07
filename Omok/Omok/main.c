#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "draw.h"

HANDLE COUT = 0;
HANDLE CIN = 0;

void Set_Cursor() {
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0; // true ����, false �Ⱥ���
	ConsoleCursor.dwSize = 1; // Ŀ��������
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor); // ����
}

int BeInput() {
	INPUT_RECORD input_record;
	DWORD input_count;

	PeekConsoleInput(CIN, &input_record, 1, &input_count);
	return input_count;
}

int GetInput(WORD* vkey, COORD* pos) {
	INPUT_RECORD input_record;
	DWORD input_count;

	ReadConsoleInput(CIN, &input_record, 1, &input_count);
	switch (input_record.EventType)
	{
	case MOUSE_EVENT:
		if (pos && (input_record.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)) {
			CONSOLE_SCREEN_BUFFER_INFO csbi;

			GetConsoleScreenBufferInfo(COUT, &csbi);

			*pos = input_record.Event.MouseEvent.dwMousePosition;
			pos->X -= csbi.srWindow.Left;
			pos->Y -= csbi.srWindow.Top;

			return MOUSE_EVENT;
		}
		break;
	default:
		break;
	}
	return 0;
}

void gotoxy(int x, int y) {
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

int main(int argc, const char* argv[]) {
	system("mode con cols=80 lines=30");
	DWORD mode;
	WORD key;
	COORD pos;

	int event;
	int x;
	int y;

	Set_Cursor();
	PrintPlate();

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (BeInput()) {
			if (GetInput(&key, &pos) != 0) {
				MOUSE_EVENT;
				x = pos.X % 2 ? pos.X - 1 : pos.X; //2����Ʈ ���� �Է� ������ ĭ�� ���� �ʴ� ���� ����
				y = pos.Y;
				if (x < 38 && y < 19) {
					gotoxy(x, y);
					printf("��");
				}
			}
		}
	}
	return 0;
}