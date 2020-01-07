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