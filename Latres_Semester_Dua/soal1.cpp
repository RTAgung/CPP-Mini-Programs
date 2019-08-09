#include <bits/stdc++.h>
using namespace std;


typedef struct{
	string nama;
	string asal;
	int matematika;
	int fisika;
	int biologi;
	int kimia;
	int poin;
}Data;

Data data[1000], temp;
ifstream myFileIn;
ofstream myFileOut;
int jml;
int mhs;

void input();
void output();
	void sort();
void hasil();
	void poinMatematika(int *pm, int i);
	void poinFisika(int *pf, int i);
	void poinKimia(int *pk, int i);
	void poinBiologi(int *pb, int i);
void lolos();
	void sortPoin();
	void sortNama();

int main()
{
	int enter;
	top :
	cout<< "MENU" << endl;
	cout<< "1. INPUT \n2. OUTPUT \n3. HASIL \n4. LOLOS \n5. EXIT"<< endl;
	cout<< "PILIH (1..4) = "; cin>>enter;		
	
	switch(enter){
		case 1:
			input();
			break;
		case 2:
			output();
			break;
		case 3:
			hasil();
			break;
		case 4:
			lolos();
			break;
		case 5:
			exit(1);
		default :
			cout<< "Error Input!" << endl;
	}
	goto top;
	return 0;
}

void input(){
	cout<< "Jumlah Maksimum  : "; cin>> jml;
	cout<< "Jumlah Mahasiswa : "; cin>> mhs;

	for (int i = 0; i < mhs; ++i)
	{
		cout<< i+1;
		cout<< "\tNama Mahasiswa   : "; cin.ignore(); getline(cin,data[i].nama);
		cout<< "\tAsal Sekolah     : "; getline(cin,data[i].asal);
		cout<< "\tNilai Matematika : "; cin>> data[i].matematika;
		cout<< "\tNilai Fisika     : "; cin>> data[i].fisika;
		cout<< "\tNilai Kimia      : "; cin>> data[i].kimia;
		cout<< "\tNilai Biologi    : "; cin>> data[i].biologi;
		cout<< endl;
	}
}

void output(){
	sort();
	myFileOut.open("file1.txt");

	for (int i = 0; i < mhs; ++i)
	{
		cout<< i+1;
		cout<< "\tNama Mahasiswa   : " << data[i].nama << endl;
		cout<< "\tAsal Sekolah     : " << data[i].asal << endl;
		cout<< "\tNilai Matematika : " << data[i].matematika << endl;
		cout<< "\tNilai Fisika     : " << data[i].fisika << endl;
		cout<< "\tNilai Kimia      : " << data[i].kimia << endl;
		cout<< "\tNilai Biologi    : " << data[i].biologi << endl;
		cout<< endl;
	
		myFileOut<< data[i].nama << endl;
		myFileOut<< data[i].asal << endl;
		myFileOut<< data[i].matematika << endl;
		myFileOut<< data[i].fisika << endl;
		myFileOut<< data[i].kimia << endl;
		myFileOut<< data[i].biologi << endl;
	}

	myFileOut.close();
}

	void sort(){
		for (int i = 0; i < mhs; ++i)
		{
			for (int j = i+1 ; j < mhs; ++j)
			{
				if (data[i].nama > data[j].nama)
				{
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
			}
		}
	}

void hasil(){
	int pm, pf, pk, pb;
	for (int i = 0; i < mhs; ++i)
	{
		pm = jml;
		pf = jml;
		pk = jml;
		pb = jml;
		
		poinMatematika(&pm, i);
		poinFisika(&pf, i);
		poinKimia(&pk, i);
		poinBiologi(&pb, i);

		data[i].poin = pm + pf + pk + pb;
		
		cout<< i+1;
		cout<< "\tNama Mahasiswa   : " << data[i].nama << endl;
		cout<< "\tPoin Matematika  : " << pm << endl;
		cout<< "\tPoin Fisika      : " << pf << endl;
		cout<< "\tPoin Kimia       : " << pk << endl;
		cout<< "\tPoin Biologi     : " << pb << endl;
		cout<< "\tTotal Poin       : " << data[i].poin << endl;
		cout<< endl;
	}
}
	
	void poinMatematika(int *pm, int i){
		bool sama;
		int x = *pm;
		for (int j = 0; j < mhs; ++j)
		{
			if (data[i].matematika < data[j].matematika)
			{
				sama = false;
				for (int k = j-1; k >= 0; --k)
				{
					if (data[j].matematika == data[k].matematika)
					{
						sama = true;
					}
				}
				if (!sama)
				{
					x--;
				}
			}
		}
		*pm = x;
	}

	void poinFisika(int *pf, int i){
		bool sama;
		int x = *pf;
		for (int j = 0; j < mhs; ++j)
		{
			if (data[i].fisika < data[j].fisika)
			{
				sama = false;
				for (int k = j-1; k >= 0; --k)
				{
					if (data[j].fisika == data[k].fisika)
					{
						sama = true;
					}
				}
				if (!sama)
				{
					x--;
				}
			}
		}
		*pf = x;
	}

	void poinKimia(int *pk, int i){
		bool sama;
		int x = *pk;
		for (int j = 0; j < mhs; ++j)
		{
			if (data[i].kimia < data[j].kimia)
			{
				sama = false;
				for (int k = j-1; k >= 0; --k)
				{
					if (data[j].kimia == data[k].kimia)
					{
						sama = true;
					}
				}
				if (!sama)
				{
					x--;
				}
			}
		}
		*pk = x;
	}

	void poinBiologi(int *pb, int i){
		bool sama;
		int x = *pb;
		for (int j = 0; j < mhs; ++j)
		{
			if (data[i].biologi < data[j].biologi)
			{
				sama = false;
				for (int k = j-1; k >= 0; --k)
				{
					if (data[j].biologi == data[k].biologi)
					{
						sama = true;
					}
				}
				if (!sama)
				{
					x--;
				}
			}
		}
		*pb = x;
	}

void lolos(){
	sortPoin();
	sortNama();

	

	for (int i = 0; i < jml; ++i)
	{
		cout<< i+1;
		cout<< "\tNama Mahasiswa   : " << data[i].nama << endl;
		cout<< "\tAsal Sekolah     : " << data[i].asal << endl;
		cout<< "\tNilai Matematika : " << data[i].matematika << endl;
		cout<< "\tNilai Fisika     : " << data[i].fisika << endl;
		cout<< "\tNilai Kimia      : " << data[i].kimia << endl;
		cout<< "\tNilai Biologi    : " << data[i].biologi << endl;
		cout<< endl;
	
		
	}
	myFileOut.open("file2.txt");
	for (int i = 0; i < jml; ++i)
	{
		myFileOut<< data[i].nama << endl;
		myFileOut<< data[i].asal << endl;
		myFileOut<< data[i].matematika << endl;
		myFileOut<< data[i].fisika << endl;
		myFileOut<< data[i].kimia << endl;
		myFileOut<< data[i].biologi << endl;
	}
	myFileOut.close();
}

	void sortPoin(){
		for (int i = 0; i < mhs; ++i)
		{
			for (int j = i+1 ; j < mhs; ++j)
			{
				if (data[i].poin < data[j].poin)
				{
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
			}
		}
	}

	void sortNama(){
		for (int i = 0; i < jml; ++i)
		{
			for (int j = i+1 ; j < jml; ++j)
			{
				if (data[i].nama > data[j].nama)
				{
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
			}
		}
	}