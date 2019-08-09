#include <bits/stdc++.h>
using namespace std;

int main(){
	string nama;
	int pilih, panjang,x,y,z;
	char *sem, *cari, *ptr;
	bool ketemu;
	
	sem = (char *)malloc(sizeof(char));
	cari = (char *)malloc(sizeof(char));
	ptr = (char *)malloc(sizeof(char));
	*ptr = '*';
	
	menu :
	cout<< "Menu : " << endl;
	cout<< "1. Input \n2. Output \n3. Searching" << endl;
	cout<< "Pilih (1..3) : "; cin>> pilih;
	
	switch(pilih){
		case 1:
			cout<< "Kalimat : "; 
			cin.ignore(); getline(cin,nama);
			cout<< "Sembunyikan huruf : "; cin>> *sem;
			panjang = nama.length();
			nama[panjang] = ' ';
			
			break;
		case 2:
			for (int i = 0; i < panjang; i++)
			{
				if (nama[i] == *sem)
				{
					cout<< *ptr;
				}
				else
				{
					cout<< nama[i];
				}
			}
			cout<< endl;
			break;
		case 3:
			z = 0;
			x = 0;
			y = 0;
			ketemu = false;
			cout<< "Cari : "; cin>> *cari;
			cout<< "Hasil : ";
			for (int i = 0; i < panjang+1; i++)
			{
				if (nama[i] == *cari)
				{
					ketemu = true;
				}
				if (nama[i] == ' ')
				{
					if (ketemu)
					{
						if (z != 0)
						{
							cout<< ", ";
						}
						for (int i = y; i < x; i++)
						{
							cout<< nama[i];
						}
						
						z++;
					}
					ketemu = false;
					y = x+1;
				}
				x++;
			}
			cout<< endl << "Kesimpulan : terdapat " << z << " kata yang memiliki huruf " << *cari << endl;
			break;
		default:
			break;
	}
	cout<< endl << endl;
	goto menu;
}

