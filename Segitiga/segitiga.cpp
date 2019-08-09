#include <iostream>
using namespace std;

int main()
{
	int x;
	cout<< "Masukan panjang sisi : "; cin>> x;

	for (int i = 0; i < x; i++)
	{
		for (int k = x; k >= i; k--)
		{
			cout<< "* ";
		}
		for (int j = 0; j < i; j++)
		{
			cout<< "    ";
		}
		cout<< "* ";
		for (int l = x; l > i; l--)
		{
			cout<< "* ";
		}
		cout<< endl;
	}
	for (int i = 0; i <= x; i++)
	{
		for (int k = 0; k <= i ; k++)
		{
			cout<< "* ";
		}
		for (int j = x; j > i; j--)
		{
			cout<< "    ";
		}
		for (int l = 0; l <= i; l++)
		{
			cout<< "* ";
		}
		cout<< endl;
	}
	
	system("pause");
	return 0;
}