#include <bits/stdc++.h>
using namespace std;

int rekursi(int a, int b, int c, int d);
int pangkat(int a, int b);
int main()
{
	int bil, naik, pangkat;
	int i;
	cout<< "bil : "; cin>> bil;
	cout<< "naik : "; cin>> naik;
	cout<< "pangkat : "; cin>> pangkat;
	i = 0;
	int hasil = rekursi(bil,naik,pangkat,i);

	cout<< endl << "hasil : " << hasil;
	return 0;
}

int rekursi(int a, int b, int c, int d){
	if (d == c)
	{
		return a * pangkat(b, (c-(c-d)));
	}
	else
	{
		return a * pangkat(b, (c-(c-d))) + rekursi(a,b,c,(d+1));
	}
}

int pangkat(int a, int b){
	/*if (b == 0)
	{
		return 1;
	}
	else
	{
		return a * pangkat(a,(b-1));
	}*/
	int hasil = 1;
	for (int i = 0; i < b; ++i)
	{
		hasil = hasil * a;
	}

	return hasil;
}