
#include "iostream"
using namespace std;

int Bulan[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; 
string Hari[7] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
void hitungHariA(int *hariA, int tanggalLahir, int bulanLahir, int tahunLahir);
void hitungHariB(int *hariB, int tanggalIni, int bulanIni, int tahunIni);
void hitungUmur(int *t,int tanggalLahir, int bulanLahir, int tahunLahir, int tanggalIni, int bulanIni, int tahunIni);
void cariHariA(string *hariLahir, int hariA);
void cariHariB(string *hariSekarang, int hariB);

int main()
{
	int tanggalLahir, bulanLahir, tahunLahir, hariA;
	int tanggalIni, bulanIni, tahunIni, hariB;
	int t;
	string hariSekarang, hariLahir;

	cout << "\tTanggal Lahir" << endl;
	cout << "Tanggal : "; cin >> tanggalLahir;
	cout << "Bulan   : "; cin >> bulanLahir;
	cout << "Tahun   : "; cin >> tahunLahir;
	cout << endl;
	cout << "\tTanggal Sekarang" << endl;
	cout << "Tanggal : "; cin >> tanggalIni;
	cout << "Bulan   : "; cin >> bulanIni;
	cout << "Tahun   : "; cin >> tahunIni;
	cout << endl << endl;

	hitungHariA(&hariA, tanggalLahir, bulanLahir, tahunLahir);
	hitungHariB(&hariB, tanggalIni, bulanIni, tahunIni);
	hitungUmur(&t, tanggalLahir, bulanLahir, tahunLahir, tanggalIni, bulanIni, tahunIni);
	cariHariA(&hariLahir, hariA);
	cariHariB(&hariSekarang, hariB);

	cout << "Hari Lahir    : " << hariLahir << endl;
	cout << "Hari Sekarang : " << hariSekarang << endl;
	cout << "Umur Sekarang : " << t << " tahun" << endl;
	cout << endl << endl;
	system("pause");
	return 0;
}

void hitungHariA(int *hariA, int tanggalLahir, int bulanLahir, int tahunLahir){
	int th, kabisat, bln;
	
	th = ((tahunLahir - 1950) * 365);
	
	kabisat = 0;
	for (int i = tahunLahir; i >= 1950; --i)
	{
		if (i % 4 == 0){
			kabisat++;
		}
	}

	if (tahunLahir % 4 == 0 && bulanLahir <= 2 && tanggalLahir <= 29)
	{
		kabisat--;
	}

	bln = 0;
	for (int i = 0; i < bulanLahir - 1; ++i)
	{
		bln = Bulan[i] + bln;
	}

	*hariA = th + kabisat + bln + tanggalLahir - 1;
}

void hitungHariB(int *hariB, int tanggalIni, int bulanIni, int tahunIni){
	int th, kabisat, bln;
	
	th = ((tahunIni - 1950) * 365);
	
	kabisat = 0;
	for (int i = tahunIni; i >= 1950; --i)
	{
		if (i % 4 == 0){
			kabisat++;
		}
	}

	if (tahunIni % 4 == 0 && bulanIni <= 2 && tanggalIni <= 29)
	{
		kabisat--;
	}

	bln = 0;
	for (int i = 0; i < bulanIni - 1; ++i)
	{
		bln = Bulan[i] + bln;
	}

	*hariB = th + kabisat + bln + tanggalIni - 1;
}

void hitungUmur(int *t,int tanggalLahir, int bulanLahir, int tahunLahir, int tanggalIni, int bulanIni, int tahunIni){
	*t = tahunIni - (tahunLahir + 1);
	if (bulanIni > bulanLahir){
		*t = *t + 1;
	}
	else if (bulanIni == bulanLahir && tanggalIni >= tanggalLahir){
		*t = *t + 1;
	}
}

void cariHariA(string *hariLahir, int hariA){
	int x;
	x = hariA%7;

	switch (x){
		case 0:
			*hariLahir = Hari[x];
			break;
		case 1:
			*hariLahir = Hari[x];
			break;
		case 2:
			*hariLahir = Hari[x];
			break;
		case 3:
			*hariLahir = Hari[x];
			break;
		case 4:
			*hariLahir = Hari[x];
			break;
		case 5:
			*hariLahir = Hari[x];
			break;
		case 6:
			*hariLahir = Hari[x];
			break;
	}
}

void cariHariB(string *hariSekarang, int hariB){
	int x;
	x = hariB%7;

	switch (x){
		case 0:
			*hariSekarang = Hari[x];
			break;
		case 1:
			*hariSekarang = Hari[x];
			break;
		case 2:
			*hariSekarang = Hari[x];
			break;
		case 3:
			*hariSekarang = Hari[x];
			break;
		case 4:
			*hariSekarang = Hari[x];
			break;
		case 5:
			*hariSekarang = Hari[x];
			break;
		case 6:
			*hariSekarang = Hari[x];
			break;
	}
}
