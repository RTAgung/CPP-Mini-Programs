#include <bits/stdc++.h>
using namespace std;

int rek(int bil, int mod){
	if (mod == 1)
	{
		cout<< bil%mod << " = ";
		return bil%mod;
	}
	else
	{
		cout<< bil%mod << " + ";
		return bil%mod + rek(bil/mod,mod-1);
	}
}

int main(){
	int bil;
	int mod;
	int hasil;
	
	cout<< "Bilangan = "; cin>> bil;
	cout<< "Mod = "; cin>> mod;
	
	cout<< "Hasil = ";
	int a = bil;
	int p;
	hasil = 0;
	
	// for (int i = mod; i > 0; i--)
	// {
	// 	p = a%i;
	// 	hasil = hasil + p;
		
	// 	if (i == 1){
	// 		cout<< p << " = ";
	// 	}
	// 	else{
	// 		cout<< p << " + ";
	// 	}
	// 	a /= i;
	// 	p = a;
	// }
	
	cout<< rek(bil,mod);
	
}
