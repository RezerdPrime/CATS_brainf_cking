#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//#include <iostream>
//using namespace std;
int main() {

	FILE *fin = fopen("input.txt", "r"),
		 *fout = fopen("output.txt", "w");

	long long x1, y1, x2, y2, xp, yp;
	fscanf(fin, "%lli %lli %lli %lli %lli %lli", &x1, &y1, &x2, &y2, &xp, &yp);

	x2 -= x1; xp -= x1; // сведение к частному случаю, когда прямоугольник исходит
	y2 -= y1; yp -= y1; // из точки (0, 0)

	if ((x2 < 0) and (xp < 0)) {
		x2 = -x2;
		xp = -xp;
	}

	if ((y2 < 0) and (yp < 0)) {
		y2 = -y2;
		yp = -yp;
	}

	//cout << " " << 0 << " " << 0 << " " << x2 << " " << y2 << " " << xp << " " << yp << endl;

	if ((0 == x2) and (x2 == y2) and (y2 == xp) and (xp == yp)) {
		fprintf(fout, "CENTER"); 
		return 0; // исключение, когда не прямоугольник, а точка
	}

	else if ((0 == y2) and (y2 == yp)) {
		if ((xp * 10) >= (x2 * 10) / 2) { xp = x2 - xp; }

		if ((xp * 100) >= (x2 * 100) / 4) { fprintf(fout, "CENTER"); return 0; }
		else { fprintf(fout, "CORNER"); return 0; } // исключение, когда не прямоугольник, а горизонтальная линия
	}

	else if ((0 == x2) and (x2 == xp)) {
		if ((yp * 10) >= (y2 * 10) / 2) { yp = y2 - yp; }

		if ((yp * 100) >= (y2 * 100) / 4) { fprintf(fout, "CENTER"); return 0; }
		else { fprintf(fout, "CORNER"); return 0; } // исключение, когда не прямоугольник, а вертикальная линия
	}

	else {
		if ((xp * 10) >= (x2 * 10) / 2) { xp = x2 - xp; } // отражение прямоугольника для сведения к частному случаю
		if ((yp * 10) >= (y2 * 10) / 2) { yp = y2 - yp; } // когда точка находится около (0, 0)

		//cout << xp << " " << (x2 * x2 + y2 * y2 - 4 * y2 * yp) / (4 * x2) << endl;

		if ((xp * 100 * abs(x2)) >= ((x2 * x2 + y2 * y2 - 4 * y2 * yp) * 100 * abs(x2)) / (4 * x2)) { fprintf(fout, "CENTER"); } // (*)
		else { fprintf(fout, "CORNER"); }
	}

	fclose(fin); fclose(fout);
	return 0;
}

/*

на примере теста: 100 200 300 400 290 210

для начала мы сводим всё к частному случаю:

1) вычитаем координаты смещения прямоугольника из координат верхней границы и координат данной точки
0 0 200 200 190 10 (сокращу на 10 для личного удобства: 0 0 20 20 19 1)

2) отзеркаливаем точку, если она "находится далеко" от точки (0, 0), т.е. снова сводим к частному случаю
от 19 до 20 остаётся расстояние равное 1 => координаты данной точки в частном случае: (1, 1)

3) сравниваем Х положение данной точки с тем, которое бы приняла точка по спец.функции при её данной высоте (или приведённой к частному случаю)

-----------------------------------

(*) - функция прямой, которая является границей для области центра и угла по условию задачи.

В условии написано, что для нахождения точки в углу, расстояние от неё до ближайшей вершины должно быть меньше, чем до центра прямоугольника.
как раз таки на точках этой прямой, расстояния от данной точки до центра и вершины будут равными, т.е. тут точка будет соответствовать условию
нахождения в центре. Поскольку я всё привожу к частному случаю, функция прямой имеет именно такой вид (вывел я её долгими и упорными наблюдениями
за поведением графиков). Если положение на оси ОХ данной точки равно или превышает значение функции на её высоте -> точка находится в центре.

Для наглядности, я создал график в десмосе: https://www.desmos.com/calculator/ag3hhp3uiv?lang=ru

*/
