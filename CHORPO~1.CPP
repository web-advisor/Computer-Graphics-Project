
// --------------------------- ** Header Files ** ----------------------------------
#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

// --------------------------- ** Funtction Prototypes ** -----------------------------------------
void SOUND(int);
void welcome();
void HOME();
void rectangle(int k);
void start();
void boundary();
void GAME();
void movingman();
void manright(int x, int y);
void manleft(int x, int y);
void manup(int x, int y);
void mandown(int x, int y);
void noman(int x, int y);
void time(int);
void Options();
void display(int no);
void Control();
void change1();
void change2();
void change3();
void help();

// ******************* DECLARATION OF GLOBAL VARIABLES *********************

char bs = 223, cr = 219;
int k, i, j;

//   Initialisation of Variables to Initilize Position of Man

int x = 40, y = 15, x1 = 2, y1 = 5, x2 = 60, y2 = 10, x3 = 50, y3 = 5, stop = 0, stop1 = 0, stop2 = 0, stop3 = 0;
int no = 2, o = 2;

//  Variable Initialisation (Control for Movement of MAN)

char w3 = 'w', a3 = 'a', d3 = 'd', f3 = 'f', t3 = 't', h3 = 'h', g3 = 'g';
char s3 = 's', j3 = 'j', i3 = 'i', k3 = 'k', l3 = 'l';

// ----------------------------------- ** main function ** --------------------------------------------------

void main()
{
	welcome();
	HOME();
	getch();
}

// -------------------------**********--***- ** Function Definition ** -***--*******************-----------------------

//---------------------- Function for Welcome Screen------------------------
void welcome()
{

	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");
	cleardevice();
	//  getch();
	cleardevice();
	int i, j;
	// setbkcolor(BLACK);
	setbkcolor(LIGHTCYAN);
	setcolor(6);
	outtextxy(10, 10, " ||           ||   /====  ||      /====  /====\\   ||=\\\\    //=||   /==== ");
	outtextxy(10, 20, " ||           ||  ||      ||     ||     ||    ||  ||   \\\\_//  ||  ||     ");
	outtextxy(10, 30, " ||     ^     ||  ||==    ||     ||     ||    ||  ||          ||  ||==   ");
	outtextxy(10, 40, " ||   // \\\\   ||  ||      ||     ||     ||    ||  ||          ||  ||     ");
	outtextxy(10, 50, " ||_//     \\\\_||   \\====  `====   \\====  \\====/   ||          ||   \\==== ");
	//   textattr(random(20)+BLINK);
	//   textbackground(BLACK);
	for (i = 1, j = getmaxx(); i < getmaxx(); i += 30, j -= 30)
	{
		outtextxy(j, 70, "*");
		outtextxy(i, 80, "$");
		outtextxy(j, 90, "*");
		delay(1);
		outtextxy(j, 130, "*");
		outtextxy(i, 120, "$");
		outtextxy(j, 110, "*");
		delay(1);
	}

	SOUND(20);
	setcolor(BLUE);
	outtextxy(150, 150, "  /==== ||   ||  /===\\   /===\\ ");
	outtextxy(150, 160, " ||     ||   || ||   || ||   || ");
	outtextxy(150, 170, " ||     ||===|| ||   || ||===/ ");
	outtextxy(150, 180, " ||     ||   || ||   || ||  \\\\ ");
	outtextxy(150, 190, "  \\==== ||   ||  \\===/  ||   \\\\ ");
	setcolor(GREEN);
	outtextxy(130, 250, "  /===\\   /===\\  ||    ||  /====  /====");
	outtextxy(130, 260, " ||   || ||   || ||    || ||     ||    ");
	outtextxy(130, 270, " ||===/  ||   || ||    || ||     ||==  ");
	outtextxy(130, 280, " ||      ||   || ||    || ||     ||    ");
	outtextxy(130, 290, " ||       \\===/  `==== ||  \\====  \\====");
	setcolor(5);
	outtextxy(300, 380, "MADE BY  : AMAR SINHA  & CHIRAG AGGARWAL");
	outtextxy(300, 390, "ROLL NO. : 04415002719 & 04615002719");
	setcolor(4);
	outtextxy(200, 420, "COMPUTER GRAPHICS PROJECT");
	SOUND(30);

	getch();
	cleardevice();
	closegraph();
}

// -----------------Function for produncing random frequency sound  -----------
void SOUND(int count)
{
	while (count--)
	{ // Sound Effects
		sound(10 * random(100));
		delay(75);
		nosound();
	}
}

// --------------Function that cleans scrn and makes way for MENU screen ------------
void HOME()
{
	rectangle(0);
	start();
	char a, b;
	int k = 0;
	while (a != 13)
	{
		if (a == '\0')
		{
			b = getch();
			if (b == 72)
			{
				if (k != 0)
				{
					k -= 2;
					rectangle(k);
					start();
				}
			}
			else if (b == 80)
			{
				if (k < 6)
				{
					k += 2;
					rectangle(k);
					start();
				}
			}
		}
		a = getch();
	}
	if (k == 0)
	{
		GAME();
		getch();
		clrscr();
		boundary();
		HOME();
		exit(0);
	}
	else if (k == 2)
	{
		clrscr();
		boundary();
		Options();
		// OPTION(G);
		HOME();
		exit(0);
	}
	else if (k == 4)
	{
		clrscr();
		boundary();
		help();
		getch();
		HOME();
		exit(0);
	}
	else
	{
		clrscr();
		welcome();
	}
}

//---------------------------------_RECTANGLE_FOR_SELECTION_---------------------------------------------------------------------------------------

void rectangle(int k)
{
	clrscr();
	boundary();
	textattr(RED);
	textbackground(BLUE);
	gotoxy(25, 9 + k);
	cprintf("--------------------------");
	gotoxy(25, 11 + k);
	cprintf("--------------------------");
	gotoxy(24, 10 + k);
	cprintf("|                          |");

	textcolor(BLUE);
}

// ------------------------Function used for boundary of game.-------------

void boundary()
{
	for (j = 1, i = 2; i < 80; i++, j++)
	{
		gotoxy(i, 1);
		cout << cr;
		gotoxy(i, 25);
		cout << bs;

		if (j < 25)
		{
			gotoxy(1, j);
			cout << char(222);
			gotoxy(79, j);
			cout << char(222);
		}
	}
	gotoxy(1, 25);
	cout << char(254);
}

//----------------------------------_STARTING_PAGE_---------------------------------------------------------------------------------------

void start()
{
	boundary();
	textattr(RED);
	textbackground(BLUE);
	gotoxy(32, 2);
	cprintf("===============");
	gotoxy(32, 3);
	cprintf("# CHOR-POLICE #");
	gotoxy(32, 4);
	cprintf("===============");
	textattr(GREEN);
	textbackground(BLUE);
	gotoxy(35, 10);
	cprintf("START");
	gotoxy(35, 12);
	cprintf("OPTION");
	gotoxy(35, 14);
	cprintf("HELP");
	gotoxy(35, 16);
	cprintf("BACK");
	textcolor(YELLOW);
}

// --------------Function that cleans scrn and makes way for GAME screen ------------

void GAME()
{
	clrscr();
	_setcursortype(_NOCURSOR);
	movingman();
}

//  ---------------- Function to Make MENS Move Together According to Users Choice

void movingman()
{
	textbackground(BLUE);
	textcolor(RED);
	manright(x1, y1);
	textcolor(GREEN);
	manup(x, y);
	if (no == 4)
	{
		manleft(x2, y2);
		manright(x3, y3);
	}
	if (no == 3)
	{
		manleft(x2, y2);
		stop3 = 1;
	}
	if (no == 2)
	{
		stop2 = 1;
		stop3 = 1;
	}

	char a, b;
	while (1)
	{
		while (!kbhit()) // This Loop Will Continue Until User Press Any Key
			time(1);
		b = getch();
		if (b == 'x')
			exit(0);

		//------------------------------------MOVE_UP-------------------------------------------------------------------------------------------------

		if (y1 > 1 && b == w3)
		{
			if ((y1 == y || y1 == y + 3) && (x1 == x || x1 == x + 3 || x1 == x - 3))
			{
				stop = y;
				noman(x, y);
				textcolor(RED);
				manup(x1, y1);
			}
			if ((y1 == y2 || y1 == y2 + 3) && (x1 == x2 || x1 == x2 + 3 || x1 == x2 - 3))
			{
				stop2 = y2;
				noman(x2, y2);
				textcolor(RED);
				manup(x1, y1);
			}
			if ((y1 == y3 || y1 == y3 + 3) && (x1 == x3 || x1 == x3 + 3 || x1 == x3 - 3))
			{
				stop3 = y3;
				noman(x3, y3);
				textcolor(RED);
				manup(x1, y1);
			}
			textcolor(RED);
			y1 -= 1;
			manup(x1, y1);
		}
		if (y > 1 && b == 72)
		{
			if ((y1 == y || y1 + 3 == y) && (x1 == x || x1 + 3 == x || x1 - 3 == x))
			{
				stop = y;
				noman(x, y);
				textcolor(RED);
				manup(x1, y1);
			}
			textcolor(GREEN);
			y -= 1;
			if (!stop)
				manup(x, y);
		}
		if (y2 > 1 && b == i3)
		{
			if ((y1 == y2 || y1 + 3 == y2) && (x1 == x2 || x1 + 3 == x2 || x1 - 3 == x2))
			{
				stop2 = y2;
				noman(x2, y2);
				textcolor(RED);
				manup(x1, y1);
			}
			textcolor(GREEN);
			y2 -= 1;
			if (!stop2)
				manup(x2, y2);
		}
		if (y3 > 1 && b == t3)
		{
			if ((y1 == y3 || y1 + 3 == y3) && (x1 == x3 || x1 + 3 == x3 || x1 - 3 == x3))
			{
				stop3 = y3;
				noman(x3, y3);
				textcolor(RED);
				manup(x1, y1);
			}
			textcolor(GREEN);
			y3 -= 1;
			if (!stop3)
				manup(x3, y3);
		}

		//--------------------------------------MOVE_DOWN----------------------------------------------------------------------------------------------------

		if (y1 < 23 && b == s3)
		{
			if ((y1 == y || y1 == y - 3) && (x1 == x || x1 == x + 3 || x1 == x - 3))
			{
				stop = y;
				noman(x, y);
				textcolor(RED);
				manup(x1, y1);
			}
			if ((y1 == y2 || y1 == y2 - 3) && (x1 == x2 || x1 == x2 + 3 || x1 == x2 - 3))
			{
				stop2 = y2;
				noman(x2, y2);
				textcolor(RED);
				manup(x1, y1);
			}
			if ((y1 == y3 || y1 == y3 - 3) && (x1 == x3 || x1 == x3 + 3 || x1 == x3 - 3))
			{
				stop3 = y3;
				noman(x3, y3);
				textcolor(RED);
				manup(x1, y1);
			}
			textcolor(RED);
			y1 += 1;
			mandown(x1, y1);
		}
		if (y < 23 && b == 80)
		{
			if ((y1 == y || y1 - 3 == y) && (x1 == x || x1 + 3 == x || x1 - 3 == x))
			{
				stop = y;
				noman(x, y);
				textcolor(RED);
				manup(x1, y1);
			}
			textcolor(GREEN);
			y += 1;
			if (!stop)
				mandown(x, y);
		}
		if (y2 < 23 && b == k3)
		{
			if ((y1 == y2 || y1 - 3 == y2) && (x1 == x2 || x1 + 3 == x2 || x1 - 3 == x2))
			{
				stop2 = y2;
				noman(x2, y2);
				textcolor(RED);
				manup(x1, y1);
			}
			textcolor(GREEN);
			y2 += 1;
			if (!stop2)
				mandown(x2, y2);
		}
		if (y3 < 23 && b == g3)
		{
			if ((y1 == y3 || y1 - 3 == y3) && (x1 == x3 || x1 + 3 == x3 || x1 - 3 == x3))
			{
				stop3 = y3;
				noman(x3, y3);
				textcolor(RED);
				manup(x1, y1);
			}
			textcolor(GREEN);
			y3 += 1;
			if (!stop3)
				mandown(x3, y3);
		}

		//---------------------------------------MOVE_LEFT-------------------------------------------------------------------------------------------------------------------------------------------------

		if (x1 > 1 && b == a3)
		{
			if ((x1 == x || x1 == x + 3) && (y1 == y || y1 + 2 == y || y1 - 2 == y || y1 + 1 == y || y1 - 1 == y))
			{
				stop = x;
				noman(x, y);
				textcolor(RED);
				manup(x1, y1);
			}
			if ((x1 == x2 || x1 == x2 + 3) && (y1 == y2 || y1 + 2 == y2 || y1 - 2 == y2 || y1 + 1 == y2 || y1 - 1 == y2))
			{
				stop2 = x2;
				noman(x2, y2);
				textcolor(RED);
				manup(x1, y1);
			}
			if ((x1 == x3 || x1 == x3 + 3) && (y1 == y3 || y1 + 2 == y3 || y1 - 2 == y3 || y1 + 1 == y3 || y1 - 1 == y3))
			{
				stop3 = x3;
				noman(x3, y3);
				textcolor(RED);
				manup(x1, y1);
			}
			textcolor(RED);
			x1 -= 1;
			manleft(x1, y1);
		}
		if (x > 1 && b == 75)
		{
			if ((x1 == x || x1 + 3 == x) && (y1 == y || y1 == y + 2 || y1 == y - 2 || y1 == y + 1 || y1 == y - 1))
			{
				stop = x;
				noman(x, y);
				textcolor(RED);
				manup(x1, y1);
			}
			textcolor(GREEN);
			x -= 1;
			if (!stop)
				manleft(x, y);
		}
		if (x2 > 1 && b == j3)
		{
			if ((x1 == x2 || x1 + 3 == x2) && (y1 == y2 || y1 == y2 + 2 || y1 == y2 - 2 || y1 == y2 + 1 || y1 == y2 - 1))
			{
				stop2 = x2;
				noman(x2, y2);
				textcolor(RED);
				manup(x1, y1);
			}
			textcolor(GREEN);
			x2 -= 1;
			if (!stop2)
				manleft(x2, y2);
		}
		if (x3 > 1 && b == f3)
		{
			if ((x1 == x3 || x1 + 3 == x3) && (y1 == y3 || y1 == y3 + 2 || y1 == y3 - 2 || y1 == y3 + 1 || y1 == y3 - 1))
			{
				stop3 = x3;
				noman(x3, y3);
				textcolor(RED);
				manup(x1, y1);
			}
			textcolor(GREEN);
			x3 -= 1;
			if (!stop3)
				manleft(x3, y3);
		}

		//--------------------------------------------MOVE_RIGHT-------------------------------------------------------------------------------------------------------------------------------------------------------

		if (x1 < 75 && b == d3)
		{
			if ((x1 == x || x1 == x - 3) && (y1 == y || y1 == y - 2 || y1 == y + 2 || y1 == y - 1 || y1 == y + 1))
			{
				stop = x;
				noman(x, y);
				textcolor(RED);
				manup(x1, y1);
			}
			if ((x1 == x2 || x1 == x2 - 3) && (y1 == y2 || y1 == y2 - 2 || y1 == y2 + 2 || y1 == y2 - 1 || y1 == y2 + 1))
			{
				stop2 = x2;
				noman(x2, y2);
				textcolor(RED);
				manup(x1, y1);
			}
			if ((x1 == x3 || x1 == x3 - 3) && (y1 == y3 || y1 == y3 - 2 || y1 == y3 + 2 || y1 == y3 - 1 || y1 == y3 + 1))
			{
				stop3 = x3;
				noman(x3, y3);
				textcolor(RED);
				manup(x1, y1);
			}
			textcolor(RED);
			x1 += 1;
			manright(x1, y1);
		}
		if (x < 75 && b == 77)
		{
			if ((x1 == x || x1 - 3 == x) && (y1 == y || y1 - 2 == y || y1 + 2 == y || y1 - 1 == y || y1 + 1 == y))
			{
				stop = x;
				noman(x, y);
				textcolor(RED);
				manup(x1, y1);
			}
			textcolor(GREEN);
			x += 1;
			if (!stop)
				manright(x, y);
		}
		if (x2 < 75 && b == l3)
		{
			if ((x1 == x2 || x1 - 3 == x2) && (y1 == y2 || y1 - 2 == y2 || y1 + 2 == y2 || y1 - 1 == y2 || y1 + 1 == y2))
			{
				stop2 = x2;
				noman(x2, y2);
				textcolor(RED);
				manup(x1, y1);
			}
			textcolor(GREEN);
			x2 += 1;
			if (!stop2)
				manright(x2, y2);
		}
		if (x3 < 75 && b == h3)
		{
			if ((x1 == x3 || x1 - 3 == x3) && (y1 == y3 || y1 - 2 == y3 || y1 + 2 == y3 || y1 - 1 == y3 || y1 + 1 == y3))
			{
				stop3 = x3;
				noman(x3, y3);
				textcolor(RED);
				manup(x1, y1);
			}
			textcolor(GREEN);
			x3 += 1;
			if (!stop3)
				manright(x3, y3);
		}

		if (stop != 0 && stop2 != 0 && stop3 != 0)
		{
			time(0);
			while (!kbhit())
			{
				textattr(random(16) + BLINK);
				textbackground(BLACK);
				gotoxy(37, 5);
				cprintf(" GAME OVER ");
				gotoxy(35, 7);
				cprintf("PRESS X to EXIT");
				gotoxy(32, 9);
				cprintf("PRESS ANY KEY to BACK");
			}

			char x;
			x = getch();
			sleep(5);
			if (tolower(x) == 'x')
				exit(0);
			getch();
			gotoxy(32, 11);
			cprintf("PLEASE PRESS AGAIN");
			textcolor(BLUE);
			textbackground(BLUE);
			x = 40, y = 15, x1 = 2, y1 = 5, x2 = 60, y2 = 10, x3 = 50, y3 = 5, stop = 0, stop1 = 0, stop2 = 0, stop3 = 0;

			HOME();
		}
	}
}

//   Function to Make Man Move RIGHT

void manright(int x, int y)
{
	textbackground(BLUE);
	gotoxy(x, y);
	cprintf("  O  ");
	gotoxy(x, y + 1);
	cprintf("  |' ");
	gotoxy(x, y + 2);
	cprintf("  ^  ");
}

//   Function to Make Man Move LEFT

void manleft(int x, int y)
{
	textbackground(BLUE);
	gotoxy(x, y);
	cprintf("  O  ");
	gotoxy(x, y + 1);
	cprintf(" `|  ");
	gotoxy(x, y + 2);
	cprintf("  ^  ");
}

//   Function to Make Man Move UP

void manup(int x, int y)
{
	textbackground(BLUE);
	gotoxy(x, y);
	cprintf("  O  ");
	gotoxy(x, y + 1);
	cprintf("  |  ");
	gotoxy(x, y + 2);
	cprintf("  ^  ");
	gotoxy(x, y + 3);
	cprintf("     ");
}

//   Function to Make Man Move DOWN

void mandown(int x, int y)
{
	textbackground(BLUE);
	gotoxy(x, y - 1);
	cprintf("     ");
	gotoxy(x, y);
	cprintf("  O  ");
	gotoxy(x, y + 1);
	cprintf("  |  ");
	gotoxy(x, y + 2);
	cprintf("  ^  ");
}

//   Function to Remove Man After He is Caught

void noman(int x, int y)
{
	textbackground(BLUE);
	gotoxy(x, y - 1);
	cprintf("     ");
	gotoxy(x, y);
	cprintf("     ");
	gotoxy(x, y + 1);
	cprintf("     ");
	gotoxy(x, y + 2);
	cprintf("     ");
}

// ----------------------- Function to Display Time ----------------

int sc = 0;
void time(int s = 1)
{
	static unsigned int hr = 0, min = 0, sec = 0;
	if (s == 0)
	{
		hr = 0;
		min = 0;
		sec = 0;
		return;
	}
	textcolor(WHITE);
	delay(1);
	sc += 1;
	if (sc == 1000)
	{
		sec += 1;
		sc = 0;
	}
	if (sec == 60)
	{
		min += 1;
		sec = 0;
	}
	if (min == 60)
	{
		hr += 1;
		min = 0;
	}
	gotoxy(37, 22);
	cprintf("TIME : ");
	gotoxy(35, 24);
	cprintf("PRESS X to EXIT");
	gotoxy(42, 22);
	cprintf("%d", hr);
	gotoxy(43, 22);
	cprintf("%d", min);
	gotoxy(44, 22);
	cprintf(":");
	gotoxy(45, 22);
	cprintf("%d", sec);
	textcolor(11);
}

// ----------------------- Function to List Options -----------------------
void Options()
{
	int k = 0;
	rectangle(k);
	display(no);
	char b, a;
label:
	while (a != 13)
	{
		a = getch();
		if (a == '\0')
		{
			b = getch();
			if (b == 72)
			{
				if (k >= 2)
				{
					k -= 2;
					rectangle(k);
					display(no);
				}
			}
			else if (b == 80)
			{
				if (k < 4)
				{
					k += 2;
					rectangle(k);
					display(no);
				}
			}
		}
	}
	if (k == 0)
	{
		if (o == 2)
		{
			o = 3;
			no = 3;
			display(no);
			Options();
		}
		if (o == 3)
		{
			o = 4;
			no = 4;
			display(no);
			Options();
		}
		if (o == 4)
		{
			o = 2;
			no = 2;
			display(no);
			Options();
		}
	}
	if (k == 2)
	{
		Control();
		HOME();
	}
	if (k == 4)
		HOME();
}

//  Function to Display Option Of GAME

void display(int no)
{
	textcolor(YELLOW);
	gotoxy(28, 10);
	cprintf(" NO. OF PLAYERS : ");
	cprintf("%d", no);
	gotoxy(28, 12);
	cprintf("    CONTROLS ");
	gotoxy(28, 14);
	cprintf("      BACK ");
}

// -------------Funnction to List Controls Menu---------------------------
void Control()
{
	char x;
	textbackground(BLUE);
	textcolor(RED);
	gotoxy(35, 3);
	cprintf(" *-*-*-*-*-*");
	gotoxy(35, 4);
	cprintf("%  CONTROLS  %");
	gotoxy(35, 5);
	cprintf(" =+=+=+=+=+=");
	textcolor(YELLOW);
	gotoxy(5, 8);
	cprintf("        RED PLAYER    GREEN PLAYER 1     GREEN PLAYER 2   GREEN PLAYER 3");
	gotoxy(5, 10);
	cprintf("  UP    ");
	cout << "\t" << w3 << "\t   up_arrow_key\t\t  " << i3 << "\t\t  " << t3 << "    ";
	gotoxy(13, 11);
	cout << "\t\t\t\t\t\t\t       ";
	gotoxy(5, 12);
	cprintf(" DOWN   ");
	cout << "\t" << s3 << "\t  down_arrow_key\t  " << k3 << "\t\t  " << g3 << "    ";
	gotoxy(13, 13);
	cout << "\t\t\t\t\t\t\t       ";
	gotoxy(5, 14);
	cprintf(" RIGHT  ");
	cout << "\t" << d3 << "\t  right_arrow_key\t  " << l3 << "\t\t  " << h3 << "    ";
	gotoxy(13, 15);
	cout << "\t\t\t\t\t\t\t       ";
	gotoxy(5, 16);
	cprintf(" LEFT   ");
	cout << "\t" << a3 << "\t  left_arrow_key\t  " << j3 << "\t\t  " << f3 << "    ";

	gotoxy(27, 20);
	cprintf("PRESS Y  TO CHANGE CONTROLS");
	gotoxy(32, 22);
	cprintf("PRESS X  TO EXIT");
	gotoxy(23, 24);
	cprintf("PRESS ANY OTHER KEY FOR MAIN MENU");
	x = getch();
	if (tolower(x) == 'y')
	{
		gotoxy(27, 20);
		cprintf("                            ");
		gotoxy(32, 22);
		cprintf("PRESS ENTER  TO EXIT");
		gotoxy(23, 24);
		cprintf("                                 ");
		change1();
		change2();
		change3();
	}
	if (tolower(x) == 'x')
		exit(0);
	HOME();
	getch();
}

// ------------------- Funtions to Change Control -------------------------

void change1()
{
	int i = 0;
	char a, b, c;
	while (i != 4)
	{
		if (i == 0)
		{
			textattr(WHITE + BLINK);
			gotoxy(15, 10);
			cprintf("<ENTER>");
			c = getch();
			if (c == 13)
				exit(0);
			w3 = c;
			gotoxy(15, 10);
			cout << "  " << w3 << "    ";
			textcolor(WHITE);
			gotoxy(17, 12);
			cout << s3;
			gotoxy(17, 14);
			cout << d3;
			gotoxy(17, 16);
			cout << a3;
			k = 2;
			i = 1;
		}
		if (i == 1)
		{
			textattr(WHITE + BLINK);
			gotoxy(15, 12);
			cprintf("<ENTER>");
			c = getch();
			if (c == 13)
				exit(0);
			s3 = c;
			gotoxy(15, 12);
			cout << "  " << s3 << "    ";
			textcolor(WHITE);
			gotoxy(17, 10);
			cout << w3;
			gotoxy(17, 14);
			cout << d3;
			gotoxy(17, 16);
			cout << a3;
			k = 2;
			i = 2;
		}
		if (i == 2)
		{
			textattr(WHITE + BLINK);
			gotoxy(15, 14);
			cprintf("<ENTER>");
			c = getch();
			if (c == 13)
				exit(0);
			d3 = c;
			gotoxy(15, 14);
			cout << "  " << d3 << "    ";
			textcolor(WHITE);
			gotoxy(17, 10);
			cout << w3;
			gotoxy(17, 12);
			cout << s3;
			gotoxy(17, 16);
			cout << a3;
			k = 3;
			i = 3;
		}
		if (i == 3)
		{
			textattr(WHITE + BLINK);
			gotoxy(15, 16);
			cprintf("<ENTER>");
			c = getch();
			if (c == 13)
				exit(0);
			a3 = c;
			gotoxy(15, 16);
			cout << "  " << a3 << "    ";
			textcolor(WHITE);
			gotoxy(17, 10);
			cout << w3;
			gotoxy(17, 12);
			cout << s3;
			gotoxy(17, 14);
			cout << d3;
			k = 2;
			i = 4;
		}
	}
	textbackground(BLUE);
}
void change2()
{
	int i = 0;
	char a, b, c;
	while (i != 4)
	{
		if (i == 0)
		{
			textattr(WHITE + BLINK);
			gotoxy(49, 10);
			cprintf("<ENTER>");
			c = getch();
			if (c == 13)
				exit(0);
			i3 = c;
			gotoxy(49, 10);
			cout << "  " << i3 << "    ";
			textcolor(WHITE);
			gotoxy(51, 12);
			cout << k3;
			gotoxy(51, 14);
			cout << l3;
			gotoxy(51, 16);
			cout << j3;
			k = 2;
			i = 1;
		}
		if (i == 1)
		{
			textattr(WHITE + BLINK);
			gotoxy(49, 12);
			cprintf("<ENTER>");
			c = getch();
			if (c == 13)
				exit(0);
			k3 = c;
			gotoxy(49, 12);
			cout << "  " << k3 << "    ";
			textcolor(WHITE);
			gotoxy(51, 10);
			cout << i3;
			gotoxy(51, 14);
			cout << l3;
			gotoxy(51, 16);
			cout << j3;
			k = 2;
			i = 2;
		}
		if (i == 2)
		{
			textattr(WHITE + BLINK);
			gotoxy(49, 14);
			cprintf("<ENTER>");
			c = getch();
			if (c == 13)
				exit(0);
			l3 = c;
			gotoxy(49, 14);
			cout << "  " << l3 << "    ";
			textcolor(WHITE);
			gotoxy(51, 10);
			cout << i3;
			gotoxy(51, 12);
			cout << k3;
			gotoxy(51, 16);
			cout << j3;
			k = 3;
			i = 3;
		}
		if (i == 3)
		{
			textattr(WHITE + BLINK);
			gotoxy(49, 16);
			cprintf("<ENTER>");
			c = getch();
			if (c == 13)
				exit(0);
			j3 = c;
			gotoxy(49, 16);
			cout << "  " << j3 << "    ";
			textcolor(WHITE);
			gotoxy(51, 10);
			cout << i3;
			gotoxy(51, 12);
			cout << k3;
			gotoxy(51, 14);
			cout << l3;
			k = 2;
			i = 4;
		}
	}
	textbackground(BLUE);
}
void change3()
{
	int i = 0;
	char a, b, c;
	while (i != 4)
	{
		if (i == 0)
		{
			textattr(WHITE + BLINK);
			gotoxy(65, 10);
			cprintf("<ENTER>");
			c = getch();
			if (c == 13)
				exit(0);
			t3 = c;
			gotoxy(65, 10);
			cout << "  " << t3 << "    ";
			textcolor(WHITE);
			gotoxy(67, 12);
			cout << g3;
			gotoxy(67, 14);
			cout << h3;
			gotoxy(67, 16);
			cout << f3;
			k = 2;
			i = 1;
		}
		if (i == 1)
		{
			textattr(WHITE + BLINK);
			gotoxy(65, 12);
			cprintf("<ENTER>");
			c = getch();
			if (c == 13)
				exit(0);
			g3 = c;
			gotoxy(65, 12);
			cout << "  " << g3 << "    ";
			textcolor(WHITE);
			gotoxy(67, 10);
			cout << t3;
			gotoxy(67, 14);
			cout << h3;
			gotoxy(67, 16);
			cout << f3;
			k = 2;
			i = 2;
		}
		if (i == 2)
		{
			textattr(WHITE + BLINK);
			gotoxy(65, 14);
			cprintf("<ENTER>");
			c = getch();
			if (c == 13)
				exit(0);
			h3 = c;
			gotoxy(65, 14);
			cout << "  " << h3 << "    ";
			textcolor(WHITE);
			gotoxy(67, 10);
			cout << t3;
			gotoxy(67, 12);
			cout << g3;
			gotoxy(67, 16);
			cout << f3;
			k = 3;
			i = 3;
		}
		if (i == 3)
		{
			textattr(WHITE + BLINK);
			gotoxy(65, 16);
			cprintf("<ENTER>");
			c = getch();
			if (c == 13)
				exit(0);
			f3 = c;
			gotoxy(65, 16);
			cout << "  " << f3 << "    ";
			textcolor(WHITE);
			gotoxy(67, 10);
			cout << t3;
			gotoxy(67, 12);
			cout << g3;
			gotoxy(67, 14);
			cout << h3;
			k = 2;
			i = 4;
		}
	}
	textbackground(BLUE);
}

void help()
{
	clrscr();
	boundary();
	textcolor(WHITE);
	gotoxy(32, 3);
	cprintf(" HOW TO PLAY ");
	gotoxy(32, 4);
	cprintf("=============");
	gotoxy(10, 6);
	cprintf(" THIS IS A MULTIPLAYER GAME (NO.OF PLAYERS : MAX-4 & MIN-2) ");
	gotoxy(10, 8);
	cprintf("      FIRST OF ALL YOU HAVE TO SELECT NO OF PLAYERS. ");
	gotoxy(10, 10);
	cprintf(" POLICE (RED PLAYER) HAS TO CATCH THE THEIF (GREEN PLAYERS)  ");
	gotoxy(10, 12);
	cprintf("          ONCE YOU ARE CAUGHT, YOU ARE OUT OF GAME ");
	gotoxy(10, 14);
	cprintf("   TO MOVE YOUR PLAYER YOU HAVE TO PRESS KEYS FREQUENTLY ");
	gotoxy(10, 16);
	cprintf("               PLAYERS CAN CHANGE THEIR CONTROL. ");
	gotoxy(10, 18);
	cprintf("LET US CHECK WHICH POLICEMEN CAN CATCH THE THEIFS IN LESS TIME ");

	textcolor(WHITE);
	gotoxy(35, 23);
	cprintf(" BACK ");
	textcolor(WHITE);
}
