#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process(char* text_fileway)
{
	const unsigned MAX = 64;
	FILE* file = nullptr;
	char buffer[MAX]{};
	char* estr = nullptr;
	file = fopen(text_fileway, "r");

	if (file)
	{
		while (!feof(file))
		{
			estr = fgets(buffer, sizeof(buffer), file);
			if (estr == NULL)
			{
				if (feof(file) != 0)
					break;
				else
				{
					puts("Error occured while reading the file.");
					break;
				}
			}
			// ПОСТРОЧНАЯ ОБРАБОТКА ТЕКСТА ПРОГРАММЫ
			puts(buffer);
			//КОНЕЦ
		}
	}
	else
		puts("Can not open that file.");
}


int main(int argc, char** argv)
{
	//Программа использует аргументы командной строки для получения пути к файлу с текстом
	if (argc > 1)
		process(argv[1]);
	else
		puts("You should give me a path of file to parse.");

	system("pause");
	return 0;
}