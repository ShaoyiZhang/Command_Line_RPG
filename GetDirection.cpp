#include<iostream>
#include <conio.h>
#include<string>
using namespace std;

int GetDirection()
{
	int ret = 0;

	do
	{
		int ch = _getch();
		if (isascii(ch))
			continue;

		ch = _getch();
		switch (ch)
		{
		case 72:
			ret = 2; // top
			break;
		case 75:
			ret = 1; // left 
			break;
		case 77:
			ret = 3; // right
			break;
		case 80:
			ret = 4; // down
			break;
		default:
			break;
		}
	} while (ret == 0);

	return ret;
}

int main()
{
	

	for (int k = 0; k < 10; k++)
		cout << GetDirection();
	system("pause");
	return 0;


}