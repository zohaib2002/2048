#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <iomanip.h>
#include <time.h>

int grid[4][4];

void init_grid()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			grid[i][j] = 0;

}

bool chkfull()
{
	bool isfull = true;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (grid[i][j] == 0)
			{
				isfull = false;
				break;
			}

	if (isfull) return true;
	else return false;

}

int score()
{
	int s = 0;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			s += grid[i][j];

	return s;

}

void dis_grid()
{
	cout << "---------------------------------\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			if (grid[i][j] != 0)
				cout << "|" << setw(4) << grid[i][j] << "\t";
			else cout << "|" << setw(4) <<" \t";
      cout << "|\n";
      cout << "---------------------------------";
		cout << "\n\n";

	}

	cout << "\n" << setw(20) << "Score: " << score();

}

void spawn()
{
	int k = 0;

	int posi[16];
	int posj[16];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (grid[i][j] == 0)
			{
				posi[k] = i;
				posj[k] = j;
				k++;

			}

	int r;

	srand(time(0));
	r = rand() % k;

	grid[posi[r]][posj[r]] = 2;
}

void arrow_up()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (grid[i][j] == grid[i + 1][j])
			{
				grid[i][j] += grid[i][j];
				grid[i + 1][j] = 0;
			}

	//COM 1

	for (int j = 1; j < 4; j++)
		for (int i = 1; i < 4; i++)
			if (grid[i - 1][0] == 0)
			{
				grid[i - 1][0] = grid[i][0];
				grid[i][0] = 0;
			}

	//COM 2

	for (int j = 1; j < 4; j++)
		for (int i = 1; i < 4; i++)
			if (grid[i - 1][1] == 0)
			{
				grid[i - 1][1] = grid[i][1];
				grid[i][1] = 0;
			}

	//COM 3

	for (int j = 1; j < 4; j++)
		for (int i = 1; i < 4; i++)
			if (grid[i - 1][2] == 0)
			{
				grid[i - 1][2] = grid[i][2];
				grid[i][2] = 0;
			}

	//COM 4

	for (int j = 1; j < 4; j++)
		for (int i = 1; i < 4; i++)
			if (grid[i - 1][3] == 0)
			{
				grid[i - 1][3] = grid[i][3];
				grid[i][3] = 0;
			}

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (grid[i][j] == grid[i + 1][j])
			{
				grid[i][j] += grid[i][j];
				grid[i + 1][j] = 0;
			}

	spawn();
}

void arrow_down()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (grid[i][j] == grid[i - 1][j])
			{
				grid[i][j] += grid[i][j];
				grid[i - 1][j] = 0;
			}

	//COM 1

	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 3; i++)
			if (grid[i + 1][0] == 0)
			{
				grid[i + 1][0] = grid[i][0];
				grid[i][0] = 0;
			}

	//COM 2

	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 3; i++)
			if (grid[i + 1][1] == 0)
			{
				grid[i + 1][1] = grid[i][1];
				grid[i][1] = 0;
			}

	//COM 3

	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 3; i++)
			if (grid[i + 1][2] == 0)
			{
				grid[i + 1][2] = grid[i][2];
				grid[i][2] = 0;
			}

	//COM 4

	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 3; i++)
			if (grid[i + 1][3] == 0)
			{
				grid[i + 1][3] = grid[i][3];
				grid[i][3] = 0;
			}

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (grid[i][j] == grid[i - 1][j])
			{
				grid[i][j] += grid[i][j];
				grid[i - 1][j] = 0;
			}

	spawn();
}

void arrow_left()
{
	for (int i = 1; i < 4; i++)
		for (int j = 1; j < 4; j++)
			if (grid[i][j] == grid[i][j + 1])
			{
				grid[i][j] += grid[i][j];
				grid[i][j + 1] = 0;
			}

	//ROW 1

	for (int j = 1; j < 4; j++)
		for (int i = 1; i < 4; i++)
			if (grid[0][i - 1] == 0)
			{
				grid[0][i - 1] = grid[0][i];
				grid[0][i] = 0;
			}

	//ROW 2

	for (int j = 1; j < 4; j++)
		for (int i = 1; i < 4; i++)
			if (grid[1][i - 1] == 0)
			{
				grid[1][i - 1] = grid[1][i];
				grid[1][i] = 0;
			}

	//ROW 3

	for (int j = 1; j < 4; j++)
		for (int i = 1; i < 4; i++)
			if (grid[2][i - 1] == 0)
			{
				grid[2][i - 1] = grid[2][i];
				grid[2][i] = 0;
			}

	//ROW 4

	for (int j = 1; j < 4; j++)
		for (int i = 1; i < 4; i++)
			if (grid[3][i - 1] == 0)
			{
				grid[3][i - 1] = grid[3][i];
				grid[3][i] = 0;
			}

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (grid[i][j] == grid[i][j + 1])
			{
				grid[i][j] += grid[i][j];
				grid[i][j + 1] = 0;
			}

	spawn();
}

void arrow_right()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (grid[i][j] == grid[i][j - 1])
			{
				grid[i][j] += grid[i][j];
				grid[i][j - 1] = 0;
			}

	//ROW 1

	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 3; i++)
			if (grid[0][i + 1] == 0)
			{
				grid[0][i + 1] = grid[0][i];
				grid[0][i] = 0;
			}

	//ROW 2

	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 3; i++)
			if (grid[1][i + 1] == 0)
			{
				grid[1][i + 1] = grid[1][i];
				grid[1][i] = 0;
			}

	//ROW 3

	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 3; i++)
			if (grid[2][i + 1] == 0)
			{
				grid[2][i + 1] = grid[2][i];
				grid[2][i] = 0;
			}

	//ROW 4

	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 3; i++)
			if (grid[3][i + 1] == 0)
			{
				grid[3][i + 1] = grid[3][i];
				grid[3][i] = 0;
			}

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (grid[i][j] == grid[i][j - 1])
			{
				grid[i][j] += grid[i][j];
				grid[i][j - 1] = 0;
			}

	spawn();
}

void main()
{
	init_grid();
	char ch;

	do {
		clrscr();
      cout << "2048: Press W,A,S,D to play!\n\n";
		dis_grid();
		ch = getch();

		switch (ch)
		{
			case 'a':
				arrow_left();
				break;
			case 's':
				arrow_down();
				break;
			case 'd':
				arrow_right();
				break;
			case 'w':
				arrow_up();
				break;
		}
	} while (!chkfull());

	cout << "\nGame Over";

	getch();
}
