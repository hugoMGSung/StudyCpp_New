#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "cursor.h"

class Sun {
private:
	const int x, y;
	const char ch;
public:
	Sun(int ax, int ay, char ach) : x(ax), y(ay), ch(ach) { ; }
	void Show() {
		gotoxy(x, y); putch(ch);
	}
	void Hide() {
		gotoxy(x, y); putch(' ');
	}
	int GetX() const { return x; }
	int GetY() const { return y; }
};

class Earth {
private:
	const int r;
	int x, y;
	const char ch;
	const Sun* pSun;
public:
	Earth(int ar, char ach, Sun * apSun) : r(ar), ch(ach), pSun(apSun) { ; }
	void Revolve(double angle) {
		Hide();
		x = int(cos(angle * 3.141592 / 180) * r * 2);
		y = int(sin(angle * 3.141592 / 180) * r);
		Show();
	}
	void Show() {
		gotoxy(pSun->GetX() + x, pSun->GetY() + y); putch(ch);
	}
	void Hide() {
		gotoxy(pSun->GetX() + x, pSun->GetY() + y); putch(' ');
	}
};

int main() {
	Sun S(40, 12, 'S');
	Earth E(10, 'E', &S);

	clrscr();
	showcursor(0);
	S.Show();
	for (double angle = 0; !kbhit(); angle += 10) {
		E.Revolve(angle);
		delay(100);
	}
	showcursor(1);
}

