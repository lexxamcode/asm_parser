#include <stdio.h>
#include <stdlib.h>

char* read_asm_listing(char* text_fileway)
{
	//READING FROM FILE TO STRING
	#pragma warning(suppress : 4996)
	FILE* input_file = fopen(text_fileway, "r");
	long size = ftell(input_file);
	char* listing = (char*)malloc(sizeof(char) * size);

	if (listing)
		fread(listing, sizeof(char), size, input_file);
	else
		puts("File is empty or damaged.");
	fclose(input_file);

	return listing;
}

int main(int argc, char** argv)
{
	// Программа использует аргументы командной строки для получения пути к файлу с текстом
	if (argc > 1)
		char* listing = read_asm_listing(argv[1]);
	else
		puts("You should give me a path of file to parse.");

	system("pause");
	return 0;
}