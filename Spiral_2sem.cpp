#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <fstream> 

int n;
int m;
int array[11][11];

int top;
int bottom;
int left;
int right;

int num;

char ch;

int x = 0;
int y = 0;

int flag = 0;

void menu();
void firstSpiral();
void secondSpiral();
void thirdSpiral();
void fourthSpiral();
void gotoxy(int x, int y);
void cursor(int x, int y);

void firstSpiral() {
	printf("\n");

	if (m != 0 && n != 0) {
		num = 1;
		top = 0;
		bottom = n - 1;
		left = 0;
		right = m - 1;

		while (num <= (n * m)) {

			for (int i = left; i <= right && num <= (n * m) && num > 0; i++) {
				array[top][i] = num++;
			}
			top++;

			for (int i = top; i <= bottom && num <= (n * m) && num > 0; i++) {
				array[i][right] = num++;
			}
			right--;

			for (int i = right; i >= left && num <= (n * m) && num > 0; i--) {
				array[bottom][i] = num++;
			}
			bottom--;

			for (int i = bottom; i >= top && num <= (n * m) && num > 0; i--) {
				array[i][left] = num++;
			}
			left++;
		}

		for (int i = 0; i < n; i++) {
			gotoxy(0, 11 + i);
			for (int j = 0; j < m; j++) {
				printf("%4d", array[i][j]);
			}
			printf("\n");

			flag = 1;
		}
	}
	else {
		gotoxy(0, 8);
		printf("--------------------------------------------------------- \n");
		printf("Не введены ширина или длина!                              \n");
		printf("--------------------------------------------------------- \n");
		_getch();
	}
}

void secondSpiral() {
	printf("\n");

	if (m != 0 && n != 0) {
		num = 1;
		top = 0;
		bottom = n - 1;
		left = 0;
		right = m - 1;

		while (num <= (n * m)) {

			for (int i = right; i >= left && num <= (n * m) && num > 0; i--) {
				array[top][i] = num++;
			}
			top++;

			for (int i = top; i <= bottom && num <= (n * m) && num > 0; i++) {
				array[i][left] = num++;
			}
			left++;

			for (int i = left; i <= right && num <= (n * m) && num > 0; i++) {
				array[bottom][i] = num++;
			}
			bottom--;

			for (int i = bottom; i >= top && num <= (n * m) && num > 0; i--) {
				array[i][right] = num++;
			}
			right--;
		}

		for (int i = 0; i < n; i++) {
			gotoxy(0, 11 + i);
			for (int j = 0; j < m; j++) {
				printf("%4d", array[i][j]);
			}
			printf("\n");

			flag = 2;
		}
	}
	else {
		gotoxy(0, 8);
		printf("--------------------------------------------------------- \n");
		printf("Не введены ширина или длина!                              \n");
		printf("--------------------------------------------------------- \n");
		_getch();
	}
}

void thirdSpiral() {
	printf("\n");

	if (m != 0 && n != 0) {
		num = n * m;
		top = 0;
		bottom = n - 1;
		left = 0;
		right = m - 1;

		while (num >= 1) {

			for (int i = right; i >= left && num <= (n * m) && num > 0; i--) {
				array[top][i] = num--;
			}
			top++;

			for (int i = top; i <= bottom && num <= (n * m) && num > 0; i++) {
				array[i][left] = num--;
			}
			left++;

			for (int i = left; i <= right && num <= (n * m) && num > 0; i++) {
				array[bottom][i] = num--;
			}
			bottom--;

			for (int i = bottom; i >= top && num <= (n * m) && num > 0; i--) {
				array[i][right] = num--;
			}
			right--;
		}

		for (int i = 0; i < n; i++) {
			gotoxy(0, 11 + i);
			for (int j = 0; j < m; j++) {
				printf("%4d", array[i][j]);
			}
			printf("\n");

			flag = 3;
		}

	}
	else {
		gotoxy(0, 8);
		printf("--------------------------------------------------------- \n");
		printf("Не введены ширина или длина!                              \n");
		printf("--------------------------------------------------------- \n");
		_getch();
	}
}

void fourthSpiral() {
	printf("\n");

	if (m != 0 && n != 0) {
		num = n * m;
		top = 0;
		bottom = n - 1;
		left = 0;
		right = m - 1;

		while (num >= 1) {

			for (int i = left; i <= right && num <= (n * m) && num > 0; i++) {
				array[top][i] = num--;
			}
			top++;

			for (int i = top; i <= bottom && num <= (n * m) && num > 0; i++) {
				array[i][right] = num--;
			}
			right--;

			for (int i = right; i >= left && num <= (n * m) && num > 0; i--) {
				array[bottom][i] = num--;
			}
			bottom--;

			for (int i = bottom; i >= top && num <= (n * m) && num > 0; i--) {
				array[i][left] = num--;
			}
			left++;
		}

		for (int i = 0; i < n; i++) {
			gotoxy(0, 11 + i);
			for (int j = 0; j < m; j++) {
				printf("%4d", array[i][j]);
			}
			printf("\n");

			flag = 4;
		}
	}
	else {
		gotoxy(0, 8);
		printf("--------------------------------------------------------- \n");
		printf("Не введены ширина или длина!                              \n");
		printf("--------------------------------------------------------- \n");
		_getch();
	}
}

void writeSpiral() {
	//char path[] = "Spiral.txt"; 
	FILE* fout;

	fopen_s(&fout, "Spiral.txt", "w");

	if (fout == NULL)
	{
		printf("--------------------------------------------------------- \n");
		printf("Ошибка открытия файла!                                    \n");
		printf("--------------------------------------------------------- \n");
		_getch();
		return;
	}
	
	else {
		if (n == 0 && m == 0) {
			gotoxy(0, 8);
			printf("--------------------------------------------------------- \n");
			printf("Необходимо ввести значения для спирали!                   \n");
			printf("--------------------------------------------------------- \n");
			fprintf(fout, "Введите значения и будет тут спиралька!");
			fclose(fout);
			_getch();

		}
		else if (flag == 0) {
			gotoxy(0, 8);
			printf("--------------------------------------------------------- \n");
			printf("Необходимо выбрать направление спирали!                   \n");
			printf("--------------------------------------------------------- \n");
			fprintf(fout, "Выберите в программе направление спирали и будет вам счастье!");
			fclose(fout);
			_getch();
		}
		else {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					fprintf(fout, "%4d", array[i][j]);
				}
				fprintf(fout, "\n");
			}
			gotoxy(0, 8);
			printf("--------------------------------------------------------- \n");
			printf("Спиралька записана в файл!                                \n");
			printf("--------------------------------------------------------- \n");
			fclose(fout);
			_getch();
		}
	}
	
}

void sumFromFile() {
	FILE* fin;

	fopen_s(&fin, "Spiral.txt", "r");

	if (fin == NULL)
	{
		gotoxy(0, 8);
		printf("--------------------------------------------------------- \n");
		printf("Ошибка открытия файла!                                    \n");
		printf("--------------------------------------------------------- \n");
		return;
	}

	else {
		if (n == 0 && m == 0) {
			gotoxy(0, 8);
			printf("--------------------------------------------------------- \n");
			printf("Необходимо ввести значения для спирали!                   \n");
			printf("--------------------------------------------------------- \n");
			fprintf(fin, "Введите значения и будет тут спиралька!");
			_getch();
		}
		else {

			int sum = 0, num;

			while (fscanf_s(fin, "%d", &num) == 1) {
				sum += num;
			}
			gotoxy(0, 8);
			printf("--------------------------------------------------------- \n");
			printf("Сумма чисел из файла: %d                                  \n", sum);
			printf("--------------------------------------------------------- \n");
			fclose(fin);
			_getch();
			
		}
	}

}

void firstInput() {
	system("cls");
	printf("Введите длину (от 1 до 11): ");
	scanf_s("%d", &m);
	if (m <= 11 && m >= 1) {
		system("cls");
		menu();
	}
	else {
		printf("Ошибка! Длина может быть от 1 до 11");
		m = 0;
		ch = _getch();
		while (ch != 13) {
			ch = _getch();
		}
	}
}

void secondInput() {
	system("cls");
	printf("Введите ширину (от 1 до 11): ");
	scanf_s("%d", &n);
	if (n <= 11 && n >= 1) {
		system("cls");
		menu();
	}
	else {
		printf("Ошибка! Ширина может быть от 1 до 11");
		n = 0;
		ch = _getch();
		while (ch != 13) {
			ch = _getch();
		}
	}
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/*void cursor(int x, int y) {
	system("cls");
	menu();
	gotoxy(35, y);
	printf(" <--");
}*/

void cursor(int old_y, int new_y) {
	gotoxy(35, old_y);
	printf("    "); 

	gotoxy(35, new_y);
	printf(" <--");
}

void menu() {

	gotoxy(0, 0);
	if (m != 0 && m < 12) {
		printf("1. Длина спирали: %2d\n", m);
	}
	else {
		printf("1. Ввод длины: \n");

	}
		if (n != 0 && n < 12) {
			printf("2. Ширина спирали: %2d\n", n);
		}
		else {
			printf("2. Ввод ширины: \n");
		}

		printf("3. Спираль слева по часовой \n");
		printf("4. Спираль справа против часовой \n");
		printf("5. Спираль с центра по часовой \n");
		printf("6. Спираль с центра против часовой \n");
		printf("7. Записать спираль в файл \n");
		printf("8. Вывести сумму чисел из файла \n");
		printf("--------------------------------------------------------- \n");
		printf("                                                          \n");
		printf("--------------------------------------------------------- \n");
}

int main()
{
	setlocale(LC_ALL, "Rus");

	while (ch != 27) {
		ch = 0;
		//system("cls");
		gotoxy(0, 0);
		menu();
		cursor(x, y);
		int old_y = y;

		ch = _getch();
		if (ch == -32 || ch == 224) {

			ch = _getch();
			if (ch == 72) {
				if (y > 0) {
					y--;
				}
				cursor(old_y, y);
			}
			else if (ch == 80) {
				if (y < 7) {
					y++;
				}
				cursor(old_y, y);
			}
		}
		else if (ch == 13) {
			if (y == 0)
			{
				cursor(0, 8);
				firstInput();
			}
			else if (y == 1)
			{
				cursor(0, 8);
				secondInput();
			}
			else if (y == 2)
			{
				cursor(0, 8);
				firstSpiral();
			}
			else if (y == 3) {
				cursor(x, y);
				secondSpiral();
			}
			else if (y == 4) {
				cursor(x, y);
				thirdSpiral();
			}
			else if (y == 5) {
				cursor(x, y);
				fourthSpiral();
			}
			else if (y == 6) {
				cursor(x, y);
				writeSpiral();
			}
			else if (y == 7) {
				cursor(x, y);
				sumFromFile();
			}
		}
	}
	gotoxy(0, 7);
}
