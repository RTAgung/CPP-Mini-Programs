#include <bits/stdc++.h>
using namespace std;

typedef struct{
	string mapel;
	int raport;
	int ujian;
}sDaftarNilai;
typedef struct{
	string nama;
	string TTL;
	string NISN;
	string nomor_ijazah;
	string keterangan;
	float rata_raport;
	float rata_ujian;
	sDaftarNilai daftarNilai[30];
	int banyak_nilai;
}sIjazah;

sIjazah siswaFile[100], siswa, temp;
ifstream myFileIn;
ofstream myFileOut;
string listFile[100];

void getFile(int *panjang);
void setFile(int panjang);
void getList();
void menuData();
	void input();
	void output();
	void delFile();
void searching();
	void seqSearch();
		void seqSearchByNama();
		void seqSearchByNISN();
		void seqSearchByNilaiRaport();
		void seqSearchByNilaiUjian();
		void seqSearchByKeterangan();
	void binSearch();
		void binSearchByNama();
			void binSearchByNamaBubble(int panjang);
			void binSearchByNamaSelection(int panjang);
			void binSearchByNamaInsertion(int panjang);
			void binSearchByNamaShell(int panjang);
			void binSearchByNamaMergeSort(int l, int r);
				void binSearchByNamaMerge(int l, int m, int r);
			void binSearchByNamaQuick(int first, int last);
		void binSearchByNISN();
			void binSearchByNISNBubble(int panjang);
			void binSearchByNISNSelection(int panjang);
			void binSearchByNISNInsertion(int panjang);
			void binSearchByNISNShell(int panjang);
			void binSearchByNISNMergeSort(int l, int r);
		 		void binSearchByNISNMerge(int l, int m, int r);
			void binSearchByNISNQuick(int first, int last);
		void binSearchByNomorIjazah();
			void binSearchByNomorIjazahBubble(int panjang);
			void binSearchByNomorIjazahSelection(int panjang);
			void binSearchByNomorIjazahInsertion(int panjang);
			void binSearchByNomorIjazahShell(int panjang);
			void binSearchByNomorIjazahMergeSort(int l, int r);
				void binSearchByNomorIjazahMerge(int l, int m, int r);
			void binSearchByNomorIjazahQuick(int first, int last);
void transaksi();
	void mergingSambung();
	void splitting();
	

int main()
{
	system("cls");
	int pilih;
	cout<< "MENU \n";
	cout<< "1. DATA \n2. SEARCHING \n3. TRANSAKSI \n4. EXIT \n";
	cout<< "PILIH : "; cin>>pilih;
	switch (pilih){
		case 1:
			system("cls");
			menuData();
			break;
		case 2:
			system("cls");
			searching();
			break;
		case 3:
			system("cls");
			transaksi();
			break;
		case 4:
			system("cls");
			exit(1);
			break;
		default :
			cout<< "Salah Input\n";
	}
	return 0;
}

void getFile(int *panjang){
	int i = 0;
	int j;

	while(true){
		getline(myFileIn, siswaFile[i].nama);
		if (myFileIn.eof())
		{
			break;
		}
		getline(myFileIn, siswaFile[i].TTL);
		myFileIn >> siswaFile[i].NISN;
		myFileIn >> siswaFile[i].nomor_ijazah;
		myFileIn >> siswaFile[i].banyak_nilai;
		j = 0;
		while(j < siswaFile[i].banyak_nilai){
			myFileIn.ignore();
			getline(myFileIn, siswaFile[i].daftarNilai[j].mapel);
			myFileIn >> siswaFile[i].daftarNilai[j].raport;
			myFileIn >> siswaFile[i].daftarNilai[j].ujian;
			j++;
		}
		myFileIn >> siswaFile[i].rata_raport;
		myFileIn >> siswaFile[i].rata_ujian;
		myFileIn.ignore();
		getline(myFileIn, siswaFile[i].keterangan);
		i++;
	}
	*panjang = i;
}

void setFile(int panjang){
	for (int i = 0; i < panjang; ++i)
	{
		myFileOut << siswaFile[i].nama << endl;
		myFileOut << siswaFile[i].TTL << endl;
		myFileOut << siswaFile[i].NISN << endl;
		myFileOut << siswaFile[i].nomor_ijazah << endl;
		myFileOut << siswaFile[i].banyak_nilai << endl;
		for (int j = 0; j < siswaFile[i].banyak_nilai; ++j)
		{
			myFileOut << siswaFile[i].daftarNilai[j].mapel << endl;
			myFileOut << siswaFile[i].daftarNilai[j].raport << endl;
			myFileOut << siswaFile[i].daftarNilai[j].ujian << endl;
		}
		myFileOut << siswaFile[i].rata_raport << endl;
		myFileOut << siswaFile[i].rata_ujian << endl;
		myFileOut << siswaFile[i].keterangan << endl;
	}
}

void getList(){
	int i = 0;
	myFileIn.open("ListFile.txt");
	while(!myFileIn.eof()){
		myFileIn >> listFile[i];
		i++;
	}
	myFileIn.close();
	cout << "Daftar Nama File" << endl;
	for (int j = 0; j < i-1; ++j)
	{
		cout<< j+1 << ". " << listFile[j] << endl;
	}
}

void menuData(){
	int pilih;
	menu :
	cout<< "MENU DATA " << endl;
	cout<< "1. INPUT \n2. OUTPUT \n3. DELETE FILE \n4. BACK TO MENU \n" ;
	cout<< "pilih : "; cin>> pilih;
	
	switch(pilih){
		case 1:
			system("cls");
			input();
			break;
		case 2:
			system("cls");
			output();
			break;
		case 3:
			system("cls");
			delFile();
		case 4:
			system("cls");
			main();
			break;
		default :
			cout<< "Salah Input" <<endl <<endl;
			goto menu;
	}
}

	void input(){
		int banyak, pilih;
		string nama;
		menu :
		cout<< "1. Gunakan File yang sudah ada " << endl;
		cout<< "2. Buat file baru" << endl;
		cout<< "Pilih : "; cin>> pilih;

		switch(pilih){
			case 1:
				getList();
				cout<< "Ketik nama file yang digunakan : "; cin>> nama;
				myFileIn.open(nama.c_str());
				if (!myFileIn.good())
				{
					cout<< nama << " tidak ada di dalam direktori" << endl << endl;
					myFileIn.close();
					goto menu;
				}
				myFileIn.close();
				break;
			case 2:
				cout<< "Masukan nama file yang digunakan : "; cin>> nama;
				myFileOut.open("ListFile.txt", ios::app);
				myFileOut << nama << endl;
				myFileOut.close();
				break;
			default:
				cout<< "Salah Input!" << endl;
				goto menu;
		}

		system("cls");

		cout<< "Masukan banyak data : "; cin>> banyak;
		cout<< endl;

		cout<< "Data siswa : \n";
		for (int j = 0; j < banyak; ++j)
		{
			siswa.rata_raport = 0;
			siswa.rata_ujian = 0;
			cout<< "Nama\t\t\t : "; cin.ignore(); getline(cin,siswa.nama);
			cout<< "Tempat Tanggal Lahir\t : "; getline(cin,siswa.TTL);
			cout<< "NISN\t\t\t : "; cin>> siswa.NISN;
			cout<< "Nomor Ijazah\t\t : "; cin>> siswa.nomor_ijazah;
			cout<< "\tData nilai\n";
			cout<< "\tMasukan banyak nilai : "; cin>> siswa.banyak_nilai;
			for (int i = 0; i < siswa.banyak_nilai; ++i)
			{
				cout<< "\tMapel ke-"<<i+1<<endl;
				cout<< "\t  Nama Mapel   : "; cin.ignore(); getline(cin,siswa.daftarNilai[i].mapel);
				cout<< "\t  Nilai Raport : "; cin>>siswa.daftarNilai[i].raport;
				cout<< "\t  Nilai Ujian  : "; cin>>siswa.daftarNilai[i].ujian;
				siswa.rata_raport = siswa.rata_raport + siswa.daftarNilai[i].raport;
				siswa.rata_ujian = siswa.rata_ujian + siswa.daftarNilai[i].ujian;
			}
			siswa.rata_raport /= siswa.banyak_nilai;
			siswa.rata_ujian /= siswa.banyak_nilai; 
			if (siswa.rata_ujian >= 70)
			{
				siswa.keterangan = "LULUS";
			}
			else
			{
				siswa.keterangan = "TIDAK LULUS";
			}

			myFileOut.open(nama.c_str(), ios::app);
			myFileOut << siswa.nama << endl;
			myFileOut << siswa.TTL << endl;
			myFileOut << siswa.NISN << endl;
			myFileOut << siswa.nomor_ijazah << endl;
			myFileOut << siswa.banyak_nilai << endl;
			for (int i = 0; i < siswa.banyak_nilai; ++i)
			{
				myFileOut << siswa.daftarNilai[i].mapel << endl;
				myFileOut << siswa.daftarNilai[i].raport << endl;
				myFileOut << siswa.daftarNilai[i].ujian << endl;
			}
			myFileOut << siswa.rata_raport << endl;
			myFileOut << siswa.rata_ujian << endl;
			myFileOut << siswa.keterangan << endl;
			myFileOut.close();
			cout<< endl;
		}
		cout<< endl;
		system("pause");
		system("cls");
		menuData();
	}

	void output(){
		string file;
		int panjang, pilih;

		menu :
		getList();
		cout<< "Ketik nama file yang digunakan : "; cin>> file;
		myFileIn.open(file.c_str());
		if (!myFileIn.good())
		{
			cout<< "\t" << file << " tidak ada di dalam direktori" << endl;
			myFileIn.close();
			goto menu;
		}

		getFile(&panjang);
		for (int i = 0; i < panjang; ++i)
		{
			cout<< i+1 << endl;
			cout<< "\tNama\t\t : " <<  siswaFile[i].nama << endl;
   			cout<< "\tTTL\t\t : " <<  siswaFile[i].TTL << endl;
   			cout<< "\tNISN\t\t : " <<  siswaFile[i].NISN << endl;
   			cout<< "\tNomor Ijazah\t : " <<  siswaFile[i].nomor_ijazah << endl;
   			cout<< "\tRata-rata Raport : " <<  siswaFile[i].rata_raport << endl;
   			cout<< "\tRata-rata Ujian\t : " <<  siswaFile[i].rata_ujian << endl;
   			cout<< "\tKeterangan\t : " << siswaFile[i].keterangan << endl;
		}
		
		myFileIn.close();
		system("pause");
		system("cls");
		menuData();
	}

	void delFile(){
		string file, null;
		int i = 0;
		getList();
		cout<< "Ketik nama file yang ingin dihapus : "; cin>> file;
		remove(file.c_str());

		myFileOut.open("ListFile.txt");
		while(listFile[i] != null){
			if (file != listFile[i])
			{
				myFileOut << listFile[i] << endl;
			}
			i++;
		}
		myFileOut.close();
		menuData();


	}

void searching(){
	int pilih;
	menu :
	cout<< "MENU SEARCHING : \n";
	cout<< "1. SEQ SEARCH \n2. BINARY SEARCH \n3. KEMBALI KE MENU UTAMA \n";
	cout<< "PILIH : "; cin>> pilih;
	switch(pilih){
		case 1:
			seqSearch();
			system("pause");
			system("cls");
			goto menu;
			break;
		case 2:
			binSearch();
			system("pause");
			system("cls");
			goto menu;
			break;
		case 3:
			system("cls");
			main();
			break;
		default:
			cout<< "Salah Input \n";
			goto menu;
	}
}

	void seqSearch(){
		int pilih;
		cout<< "\tBERDASARKAN\n";
		cout<< "\t1. NAMA \n\t2. NISN \n\t3. NILAI RAPORT \n\t4. NILAI UJIAN \n\t5. KETERANGAN\n";
		cout<< "\tPILIH : "; cin>> pilih;
		cout<< endl;

		switch(pilih){
			case 1:
				seqSearchByNama();
				break;
			case 2:
				seqSearchByNISN();
				break;
			case 3:
				seqSearchByNilaiRaport();
				break;
			case 4:
				seqSearchByNilaiUjian();
				break;
			case 5:
				seqSearchByKeterangan();
				break;
			default :
				cout<< "Salah Input \n";	
		}
		
	   	cout<<endl <<endl;
	}

		void seqSearchByNama(){
			bool found = false;
			int panjang;
			string file, nama;

			menu :
			getList();
			cout<< "Ketik nama file yang digunakan : "; cin>> file;
			myFileIn.open(file.c_str());
			if (!myFileIn.good())
			{
				cout<< "\t" << file << " tidak ada di dalam direktori" << endl;
				myFileIn.close();
				goto menu;
			}

			getFile(&panjang);
			cout<< "\tNama siswa yang dicari : "; cin.ignore(); getline(cin,nama);
			cout<<endl;

		   	for (int i = 0; (i < panjang && !found); ++i)
		   	{
		   		if (nama == siswaFile[i].nama)
		   		{
	   			found = true;
	   			cout<< "\tNama\t\t : " <<  siswaFile[i].nama << endl;
	   			cout<< "\tTTL\t\t : " <<  siswaFile[i].TTL << endl;
	   			cout<< "\tNISN\t\t : " <<  siswaFile[i].NISN << endl;
	   			cout<< "\tNomor Ijazah\t : " <<  siswaFile[i].nomor_ijazah << endl;
	   			cout<< "\tRata-rata Raport : " <<  siswaFile[i].rata_raport << endl;
	   			cout<< "\tRata-rata Ujian\t : " <<  siswaFile[i].rata_ujian << endl;
	   			cout<< "\tKeterangan\t : " << siswaFile[i].keterangan << endl;
		   		}
		   	}
		   	if (!found)
		   	{
		   		cout<< "\t" << nama << " tidak ada di dalam " << file << endl ;
		   	}
			myFileIn.close();
		}

		void seqSearchByNISN(){
			bool found = false;
			int panjang;
			string file, NISN;
			
			menu :
			getList();
			cout<< "Ketik nama file yang digunakan : "; cin>> file;
			myFileIn.open(file.c_str());
			if (!myFileIn.good())
			{
				cout<< "\t" << file << " tidak ada di dalam direktori" << endl;
				myFileIn.close();
				goto menu;
			}
	
			getFile(&panjang);
			cout<< "\tNISN siswa yang dicari : "; cin>> NISN;
			cout<<endl;

		   	for (int i = 0; (i < panjang && !found); ++i)
		   	{
		   		if (NISN == siswaFile[i].NISN)
		   		{
		   			found = true;
		   			cout<< "\tNama\t\t : " <<  siswaFile[i].nama << endl;
		   			cout<< "\tTTL\t\t : " <<  siswaFile[i].TTL << endl;
		   			cout<< "\tNISN\t\t : " <<  siswaFile[i].NISN << endl;
		   			cout<< "\tNomor Ijazah\t : " <<  siswaFile[i].nomor_ijazah << endl;
		   			cout<< "\tRata-rata Raport : " <<  siswaFile[i].rata_raport << endl;
		   			cout<< "\tRata-rata Ujian\t : " <<  siswaFile[i].rata_ujian << endl;
		   			cout<< "\tKeterangan\t : " << siswaFile[i].keterangan << endl;
		   		}
		   	}
		   	if (!found)
		   	{
		   		cout<< "\t" << NISN << " tidak ada di dalam " << file << endl ;
		   	}
		
			myFileIn.close();
		}

		void seqSearchByNilaiRaport(){
			bool found = false;
			int panjang, nilai, a;
			string file;
			
			menu :
			getList();
			cout<< "Ketik nama file yang digunakan : "; cin>> file;
			myFileIn.open(file.c_str());
			if (!myFileIn.good())
			{
				cout<< "\t" << file << " tidak ada di dalam direktori" << endl;
				myFileIn.close();
				goto menu;
			}

			getFile(&panjang);
			cout<< "\tNilai raport siswa yang dicari (>keatas) : "; cin>> nilai;
			cout<<endl;
			
			a = 0;
		   	for (int i = 0; i < panjang; ++i)
		   	{
		   		if (nilai <= siswaFile[i].rata_raport)
		   		{
		   			found = true;
		   			cout<< "\t" << a+1 << "." << endl;
		   			cout<< "\t   Nama\t\t     : " <<  siswaFile[i].nama << endl;
		   			cout<< "\t   TTL\t\t     : " <<  siswaFile[i].TTL << endl;
		   			cout<< "\t   NISN\t\t     : " <<  siswaFile[i].NISN << endl;
		   			cout<< "\t   Nomor Ijazah\t     : " <<  siswaFile[i].nomor_ijazah << endl;
		   			cout<< "\t   Rata-rata Raport  : " <<  siswaFile[i].rata_raport << endl;
		   			cout<< "\t   Rata-rata Ujian   : " <<  siswaFile[i].rata_ujian << endl;
		   			cout<< "\t   Keterangan\t     : " << siswaFile[i].keterangan << endl;
		   			a++;
		   		}
		   	}
		   	if (!found)
		  	{
		  		cout<< "\tNilai raport " << nilai << " keatas tidak ada di dalam " << file << endl ;
			}
			
			myFileIn.close();
		}

		void seqSearchByNilaiUjian(){
			bool found = false;
			int panjang, nilai, a;
			string file;
			
			menu :
			getList();
			cout<< "Ketik nama file yang digunakan : "; cin>> file;
			myFileIn.open(file.c_str());
			if (!myFileIn.good())
			{
				cout<< "\t" << file << " tidak ada di dalam direktori" << endl;
				myFileIn.close();
				goto menu;
			}

			getFile(&panjang);
			cout<< "\tNilai ujian siswa yang dicari (>keatas) : "; cin>> nilai;
			cout<<endl;
				
			a = 0;
		   	for (int i = 0; i < panjang; ++i)
		   	{
		   		if (nilai <= siswaFile[i].rata_ujian)
		   		{
		   			found = true;
		   			cout<< "\t" << a+1 << "." << endl;
		   			cout<< "\t   Nama\t\t     : " <<  siswaFile[i].nama << endl;
		   			cout<< "\t   TTL\t\t     : " <<  siswaFile[i].TTL << endl;
		   			cout<< "\t   NISN\t\t     : " <<  siswaFile[i].NISN << endl;
		   			cout<< "\t   Nomor Ijazah\t     : " <<  siswaFile[i].nomor_ijazah << endl;
		   			cout<< "\t   Rata-rata Raport  : " <<  siswaFile[i].rata_raport << endl;
		   			cout<< "\t   Rata-rata Ujian   : " <<  siswaFile[i].rata_ujian << endl;
		   			cout<< "\t   Keterangan\t     : " << siswaFile[i].keterangan << endl;
		   			a++;
		   		}
		   	}
		   	if (!found)
		   	{
		   		cout<< "\tNilai ujian " << nilai << " keatas tidak ada di dalam " << file << endl ;
		   	}
		
			myFileIn.close();
		}

		void seqSearchByKeterangan(){
			bool found = false;
			int panjang, a;
			string file, ket;
			
			menu :
			getList();
			cout<< "Ketik nama file yang digunakan : "; cin>> file;
			myFileIn.open(file.c_str());
			if (!myFileIn.good())
			{
				cout<< "\t" << file << " tidak ada di dalam direktori" << endl;
				myFileIn.close();
				goto menu;
			}
			
			getFile(&panjang);
			cout<< "\tKeterangan siswa yang dicari (LULUS/TIDAK LULUS) : "; cin.ignore(); getline(cin, ket);
			cout<<endl;
			
			a = 0;
		   	for (int i = 0; i < panjang; ++i)
		   	{
		   		if (ket == siswaFile[i].keterangan)
		   		{
		   			found = true;
		   			cout<< "\t" << a+1 << "." << endl;
		   			cout<< "\t   Nama\t\t     : " <<  siswaFile[i].nama << endl;
		   			cout<< "\t   TTL\t\t     : " <<  siswaFile[i].TTL << endl;
		   			cout<< "\t   NISN\t\t     : " <<  siswaFile[i].NISN << endl;
		   			cout<< "\t   Nomor Ijazah\t     : " <<  siswaFile[i].nomor_ijazah << endl;
		   			cout<< "\t   Rata-rata Raport  : " <<  siswaFile[i].rata_raport << endl;
		   			cout<< "\t   Rata-rata Ujian   : " <<  siswaFile[i].rata_ujian << endl;
		   			cout<< "\t   Keterangan\t     : " << siswaFile[i].keterangan << endl;
		   			a++;
		   		}
		   	}
		   	if (!found)
		   	{
		   		cout<< "\tSiswa yang " << ket << " tidak ada di dalam " << file << endl ;
		   	}
		
			myFileIn.close();
		}

	void binSearch(){
		int pilih;
		cout<< "\tBERDASARKAN\n";
		cout<< "\t1. NAMA \n\t2. NISN \n\t3. NOMOR IJAZAH \n";
		cout<< "\tPILIH : "; cin >> pilih;
		cout<< endl;

		switch(pilih){
			case 1:
				binSearchByNama();
				break;
			case 2:
				binSearchByNISN();
				break;
			case 3:
				binSearchByNomorIjazah();
				break;
			default :
				cout<< "Salah Input" <<endl;	
		}
		cout<< endl << endl;
	}

		void binSearchByNama(){
			bool found;
			int pilih, panjang, i, j, k;
			string file1, file2, nama;
			int first;
			int last;

			awal :
			getList();
			cout<< "Ketik nama file yang digunakan : "; cin>> file1;
			myFileIn.open(file1.c_str());
			if (!myFileIn.good())
			{
				cout<< "\t" << file1 << " tidak ada di dalam direktori" << endl;
				myFileIn.close();
				goto awal;
			}

			getFile(&panjang);
			myFileIn.close();

			cout<< "\tTempat file baru dengan nama yang sudah urut : "; cin>> file2;
			myFileOut.open("ListFile.txt", ios::app);
			myFileOut << file2 << endl;
			myFileOut.close();

			myFileOut.open(file2.c_str());
			cout<< endl;

			menu :
			cout<< "\t\tMETODE SORTING\n";
			cout<< "\t\t1. BUBBLE \n\t\t2. SELECTION \n\t\t3. INSERTION \n\t\t4. SHELL \n\t\t5. MERGE \n\t\t6. QUICK \n";
			cout<< "\t\tPILIH : "; cin >> pilih;
			cout<< endl;

			switch(pilih){
				case 1:
					binSearchByNamaBubble(panjang);
					break;
				case 2:
					binSearchByNamaSelection(panjang);
					break;
				case 3:
					binSearchByNamaInsertion(panjang);
					break;
				case 4:
					binSearchByNamaShell(panjang);
					break;
				case 5:
					binSearchByNamaMergeSort(0, panjang-1);
					break;
				case 6:
					first = 0;
					last = panjang - 1;
					binSearchByNamaQuick(first, last);
					break;
				default :
					cout<< "Salah Input \n";
					goto menu;
			}
			setFile(panjang);
			myFileOut.close();

			cout<< "\t\tNama siswa yang dicari : "; cin.ignore(); getline(cin,nama);
			i = 0;
			j = panjang; //2
			while((!found) & (i <= j)){
				k = (i + j) / 2;
			    if(nama == siswaFile[k].nama)
			        found = true;
			    else
			    {
			        if(nama < siswaFile[k].nama)
			    	    j = k - 1;
			        else
			        	i = k + 1;
			    }
			}
			cout<< endl;
			if(found)
			{
			    cout<< "\t\tNama\t\t : " <<  siswaFile[k].nama << endl;
		   		cout<< "\t\tTTL\t\t : " <<  siswaFile[k].TTL << endl;
		   		cout<< "\t\tNISN\t\t : " <<  siswaFile[k].NISN << endl;
		   		cout<< "\t\tNomor Ijazah\t : " <<  siswaFile[k].nomor_ijazah << endl;
		   		cout<< "\t\tRata-rata Raport : " <<  siswaFile[k].rata_raport << endl;
		   		cout<< "\t\tRata-rata Ujian\t : " <<  siswaFile[k].rata_ujian << endl;
		   		cout<< "\t\tKeterangan\t : " << siswaFile[k].keterangan << endl;
			}
			else
			    cout << "\t\t" << nama << " tidak ada di dalam " << file1 << endl;
		}

			void binSearchByNamaBubble(int panjang){
				for(int i = 0; i<panjang-1; i++) {
					for(int j = 0; j<panjang-1-i; j++) {
				    	if(siswaFile[j].nama > siswaFile[j+1].nama) {
					        temp = siswaFile[j];
					        siswaFile[j] = siswaFile[j+1];
					        siswaFile[j+1] = temp;
				        }
				    }
				}
			}

			void binSearchByNamaSelection(int panjang){
				for(int current=0; current<panjang; current++)  
				{
				    for(int j=current+1; j<panjang; j++)		 
					{
				        if(siswaFile[current].nama > siswaFile[j].nama) 
				        {
				          	temp = siswaFile[current];
				          	siswaFile[current] = siswaFile[j];
				          	siswaFile[j] = temp;
				        }
				    }
				}
			}

			void binSearchByNamaInsertion(int panjang){
				int i, j;
				string tomp;
			    for(i=1; i<panjang; i++) {
			    	temp = siswaFile[i];
			       	tomp = siswaFile[i].nama;
			      	j = i - 1;
			      	while((tomp < siswaFile[j].nama) & (j >= 0))
			      	{
			         	siswaFile[j+1] = siswaFile[j];
			         	j = j - 1;
			         	siswaFile[j+1] = temp;
			      	}
			   }
			}

			void binSearchByNamaShell(int panjang){
				int i, j, k;
			    for(k = panjang/2; k > 0; k /= 2)
			   	{
			      	for(j = k; j < panjang; j++)
			      	{
			         	for(i = j-k; i >= 0; i -= k)
			         	{
			            	if(siswaFile[i + k].nama >= siswaFile[i].nama)
			               		break;
			            	else 
			            	{
			               		temp = siswaFile[i];
			               		siswaFile[i] = siswaFile[i + k];
			               		siswaFile[i + k] = temp;
			            	}
			         	}
			      	}
			   	}
			}

			void binSearchByNamaMergeSort(int l, int r) { 
			    if (l < r) 
			    { 
			        int m = l+(r-l)/2;  
			        binSearchByNamaMergeSort(l, m); 
			        binSearchByNamaMergeSort(m+1, r); 
			        binSearchByNamaMerge(l, m, r); 
			    } 
			}

				void binSearchByNamaMerge(int l, int m, int r){
					int i, j, k; 
				    int n1 = m - l + 1; 
				    int n2 =  r - m; 
				  	
				    sIjazah L[n1], R[n2]; 
				  	
				    for (i = 0; i < n1; i++) 
				        L[i] = siswaFile[l + i]; 
				    for (j = 0; j < n2; j++) 
				        R[j] = siswaFile[m + 1+ j]; 
			
				    i = 0;
				    j = 0;
				    k = l;
				    while (i < n1 && j < n2) 
				    { 
				        if (L[i].nama <= R[j].nama) 
				        { 
				            siswaFile[k] = L[i]; 
				            i++; 
				        } 
				        else
				        { 
				            siswaFile[k] = R[j]; 
				            j++; 
				        } 
				        k++; 
				    } 
				    while (i < n1) 
				    { 
				        siswaFile[k] = L[i]; 
				        i++; 
				        k++; 
				    } 
				    while (j < n2) 
				    { 
				        siswaFile[k] = R[j]; 
				        j++; 
				        k++; 
				    } 
				}

			void binSearchByNamaQuick(int first, int last){
				int low, high;
				string list_separator;

			   	low = first;
			   	high = last;
			   	list_separator = siswaFile[(first + last) / 2].nama;

			   	do {
			      	while(siswaFile[low].nama < list_separator)
			         	low++;
			      	while(siswaFile[high].nama > list_separator)
			         	high--;

			      	if(low <= high)
			      	{
			         	temp = siswaFile[low];
			         	siswaFile[low++] = siswaFile[high];
			         	siswaFile[high--] = temp;
			 		}
			   	} while(low <= high);

			   	if(first < high) binSearchByNamaQuick(first, high);
			   	if(low < last) binSearchByNamaQuick(low, last);
			}

		void binSearchByNISN(){
			bool found;
			int pilih, panjang, i, j, k;
			string file1, file2, NISN;
			int first;
			int last;

			awal :
			getList();
			cout<< "Ketik nama file yang digunakan : "; cin>> file1;
			myFileIn.open(file1.c_str());
			if (!myFileIn.good())
			{
				cout<< "\t" << file1 << " tidak ada di dalam direktori" << endl;
				myFileIn.close();
				goto awal;
			}

			getFile(&panjang);
			myFileIn.close();
			cout<< "\tTempat file dengan nama yang sudah urut : "; cin>> file2;

			myFileOut.open("ListFile.txt", ios::app);
			myFileOut << file2 << endl;
			myFileOut.close();

			myFileOut.open(file2.c_str());
			cout<<endl;
			menu :
			cout<< "\t\tMETODE SORTING\n";
			cout<< "\t\t1. BUBBLE \n\t\t2. SELECTION \n\t\t3. INSERTION \n\t\t4. SHELL \n\t\t5. MERGE \n\t\t6. QUICK \n";
			cout<< "\t\tPILIH : "; cin >> pilih;
			cout<< endl;

			switch(pilih){
				case 1:
					binSearchByNISNBubble(panjang);
					break;
				case 2:
					binSearchByNISNSelection(panjang);
					break;
				case 3:
					binSearchByNISNInsertion(panjang);
					break;
				case 4:
					binSearchByNISNShell(panjang);
					break;
				case 5:
					binSearchByNISNMergeSort(0, panjang-1);
					break;
				case 6:
					first = 0;
					last = panjang - 1;
					binSearchByNISNQuick(first, last);
					break;
				default :
					cout<< "Salah Input \n";
					goto menu;
			}
			setFile(panjang);
			myFileOut.close();

			cout<< "\t\tNISN siswa yang dicari : "; cin >> NISN;
			i = 0;
			j = panjang; //2
			while((!found) & (i <= j)){
				k = (i + j) / 2;
			    if(NISN == siswaFile[k].NISN)
			        found = true;
			    else
			    {
			        if(NISN < siswaFile[k].NISN)
			    	    j = k - 1;
			        else
			        	i = k + 1;
			    }
			}
			cout<<endl;
			if(found)
			{
			    cout<< "\t\tNama\t\t : " <<  siswaFile[k].nama << endl;
		   		cout<< "\t\tTTL\t\t : " <<  siswaFile[k].TTL << endl;
		   		cout<< "\t\tNISN\t\t : " <<  siswaFile[k].NISN << endl;
		   		cout<< "\t\tNomor Ijazah\t : " <<  siswaFile[k].nomor_ijazah << endl;
		   		cout<< "\t\tRata-rata Raport : " <<  siswaFile[k].rata_raport << endl;
		   		cout<< "\t\tRata-rata Ujian\t : " <<  siswaFile[k].rata_ujian << endl;
		   		cout<< "\t\tKeterangan\t : " << siswaFile[k].keterangan << endl;
			}
			else
			    cout << "\t\tNISN " << NISN << " tidak ada di dalam " << file1 << endl;
		}

			void binSearchByNISNBubble(int panjang){
				for(int i = 0; i<panjang-1; i++) {
					for(int j = 0; j<panjang-1-i; j++) {
				    	if(siswaFile[j].NISN > siswaFile[j+1].NISN) {
				        temp = siswaFile[j];
				        siswaFile[j] = siswaFile[j+1];
				        siswaFile[j+1] = temp;
				        }
				    }
				}
			}

			void binSearchByNISNSelection(int panjang){
				for(int current=0; current<panjang; current++)  
				{
				    for(int j=current+1; j<panjang; j++)		 
					{
				        if(siswaFile[current].NISN > siswaFile[j].NISN) 
				        {
				          	temp = siswaFile[current];
				          	siswaFile[current] = siswaFile[j];
				          	siswaFile[j] = temp;
				        }
				    }
				}
			}

			void binSearchByNISNInsertion(int panjang){
				int i, j;
				string tomp;
			    for(i=1; i<panjang; i++) {
			    	temp = siswaFile[i];
			       	tomp = siswaFile[i].NISN;
			      	j = i - 1;
			      	while((tomp < siswaFile[j].NISN) & (j >= 0))
			      	{
			         	siswaFile[j+1] = siswaFile[j];
			         	j = j - 1;
			         	siswaFile[j+1] = temp;
			      	}
			   }
			}

			void binSearchByNISNShell(int panjang){
				int i, j, k;
			    for(k = panjang/2; k > 0; k /= 2)
			   	{
			      	for(j = k; j < panjang; j++)
			      	{
			         	for(i = j-k; i >= 0; i -= k)
			         	{
			            	if(siswaFile[i + k].NISN >= siswaFile[i].NISN)
			               		break;
			            	else 
			            	{
			               		temp = siswaFile[i];
			               		siswaFile[i] = siswaFile[i + k];
			               		siswaFile[i + k] = temp;
			            	}
			         	}
			      	}
			   	}
			}

			void binSearchByNISNMergeSort(int l, int r) { 
			    if (l < r) 
			    { 
			        int m = l+(r-l)/2;  
			        binSearchByNISNMergeSort(l, m); 
			        binSearchByNISNMergeSort(m+1, r); 
			        binSearchByNISNMerge(l, m, r); 
			    } 
			}

				void binSearchByNISNMerge(int l, int m, int r){
					int i, j, k; 
				    int n1 = m - l + 1; 
				    int n2 =  r - m; 
				  	
				    sIjazah L[n1], R[n2]; 
				  	
				    for (i = 0; i < n1; i++) 
				        L[i] = siswaFile[l + i]; 
				    for (j = 0; j < n2; j++) 
				        R[j] = siswaFile[m + 1+ j]; 
			
				    i = 0;
				    j = 0;
				    k = l;
				    while (i < n1 && j < n2) 
				    { 
				        if (L[i].NISN <= R[j].NISN) 
				        { 
				            siswaFile[k] = L[i]; 
				            i++; 
				        } 
				        else
				        { 
				            siswaFile[k] = R[j]; 
				            j++; 
				        } 
				        k++; 
				    } 
				    while (i < n1) 
				    { 
				        siswaFile[k] = L[i]; 
				        i++; 
				        k++; 
				    } 
				    while (j < n2) 
				    { 
				        siswaFile[k] = R[j]; 
				        j++; 
				        k++; 
				    } 
				}

			void binSearchByNISNQuick(int first, int last){
				int low, high;
				string list_separator;

			   	low = first;
			   	high = last;
			   	list_separator = siswaFile[(first + last) / 2].NISN;

			   	do {
			      	while(siswaFile[low].NISN < list_separator)
			         	low++;
			      	while(siswaFile[high].NISN > list_separator)
			         	high--;

			      	if(low <= high)
			      	{
			         	temp = siswaFile[low];
			         	siswaFile[low++] = siswaFile[high];
			         	siswaFile[high--] = temp;
			 		}
			   	} while(low <= high);

			   	if(first < high) binSearchByNamaQuick(first, high);
			   	if(low < last) binSearchByNamaQuick(low, last);
			}

		void binSearchByNomorIjazah(){
			bool found;
			int pilih, panjang, i, j, k;
			string file1, file2, nomor;
			int first;
			int last;

			awal :
			getList();
			cout<< "Ketik nama file yang digunakan : "; cin>> file1;
			myFileIn.open(file1.c_str());
			if (!myFileIn.good())
			{
				cout<< "\t" << file1 << " tidak ada di dalam direktori" << endl;
				myFileIn.close();
				goto awal;
			}

			getFile(&panjang);
			myFileIn.close();
			cout<< "\tTempat file dengan nama yang sudah urut : "; cin>> file2;

			myFileOut.open("ListFile.txt", ios::app);
			myFileOut << file2 << endl;
			myFileOut.close();

			myFileOut.open(file2.c_str());

			cout<<endl;
			menu :
			cout<< "\t\tMETODE SORTING\n";
			cout<< "\t\t1. BUBBLE \n\t\t2. SELECTION \n\t\t3. INSERTION \n\t\t4. SHELL \n\t\t5. MERGE \n\t\t6. QUICK \n";
			cout<< "\t\tPILIH : "; cin >> pilih;
			cout<< endl;

			switch(pilih){
				case 1:
					binSearchByNomorIjazahBubble(panjang);
					break;
				case 2:
					binSearchByNomorIjazahSelection(panjang);
					break;
				case 3:
					binSearchByNomorIjazahInsertion(panjang);
					break;
				case 4:
					binSearchByNomorIjazahShell(panjang);
					break;
				case 5:
					binSearchByNomorIjazahMergeSort(0, panjang-1);
					break;
				case 6:
					first = 0;
					last = panjang - 1;
					binSearchByNomorIjazahQuick(first, last);
					break;
				default :
					cout<< "Salah Input \n";
					goto menu;
			}
			setFile(panjang);
			myFileOut.close();

			cout<< "\t\tNomor Ijazah siswa yang dicari : "; cin >> nomor;
			i = 0;
			j = panjang; //2
			while((!found) & (i <= j)){
				k = (i + j) / 2;
			    if(nomor == siswaFile[k].nomor_ijazah)
			        found = true;
			    else
			    {
			        if(nomor < siswaFile[k].nomor_ijazah)
			    	    j = k - 1;
			        else
			        	i = k + 1;
			    }
			}
			cout<<endl;
			if(found)
			{
			    cout<< "\t\tNama\t\t : " <<  siswaFile[k].nama << endl;
		   		cout<< "\t\tTTL\t\t : " <<  siswaFile[k].TTL << endl;
		   		cout<< "\t\tNISN\t\t : " <<  siswaFile[k].NISN << endl;
		   		cout<< "\t\tNomor Ijazah\t : " <<  siswaFile[k].nomor_ijazah << endl;
		   		cout<< "\t\tRata-rata Raport : " <<  siswaFile[k].rata_raport << endl;
		   		cout<< "\t\tRata-rata Ujian\t : " <<  siswaFile[k].rata_ujian << endl;
		   		cout<< "\t\tKeterangan\t : " << siswaFile[k].keterangan << endl;
			}
			else
			    cout << "\t\tNomor Ijazah " << nomor << " tidak ada di dalam " << file1 << endl;
		}

			void binSearchByNomorIjazahBubble(int panjang){
				for(int i = 0; i<panjang-1; i++) {
					for(int j = 0; j<panjang-1-i; j++) {
				    	if(siswaFile[j].nomor_ijazah > siswaFile[j+1].nomor_ijazah) {
				        temp = siswaFile[j];
				        siswaFile[j] = siswaFile[j+1];
				        siswaFile[j+1] = temp;
				        }
				    }
				}
			}

			void binSearchByNomorIjazahSelection(int panjang){
				for(int current=0; current<panjang; current++)  
				{
				    for(int j=current+1; j<panjang; j++)		 
					{
				        if(siswaFile[current].nomor_ijazah > siswaFile[j].nomor_ijazah) 
				        {
				          	temp = siswaFile[current];
				          	siswaFile[current] = siswaFile[j];
				          	siswaFile[j] = temp;
				        }
				    }
				}
			}

			void binSearchByNomorIjazahInsertion(int panjang){
				int i, j;
				string tomp;
			    for(i=1; i<panjang; i++) {
			    	temp = siswaFile[i];
			       	tomp = siswaFile[i].nomor_ijazah;
			      	j = i - 1;
			      	while((tomp < siswaFile[j].nomor_ijazah) & (j >= 0))
			      	{
			         	siswaFile[j+1] = siswaFile[j];
			         	j = j - 1;
			         	siswaFile[j+1] = temp;
			      	}
			   }
			}

			void binSearchByNomorIjazahShell(int panjang){
				int i, j, k;
			    for(k = panjang/2; k > 0; k /= 2)
			   	{
			      	for(j = k; j < panjang; j++)
			      	{
			         	for(i = j-k; i >= 0; i -= k)
			         	{
			            	if(siswaFile[i + k].nomor_ijazah >= siswaFile[i].nomor_ijazah)
			               		break;
			            	else 
			            	{
			               		temp = siswaFile[i];
			               		siswaFile[i] = siswaFile[i + k];
			               		siswaFile[i + k] = temp;
			            	}
			         	}
			      	}
			   	}
			}

			void binSearchByNomorIjazahMergeSort(int l, int r) { 
			    if (l < r) 
			    { 
			        int m = l+(r-l)/2;  
			        binSearchByNomorIjazahMergeSort(l, m); 
			        binSearchByNomorIjazahMergeSort(m+1, r); 
			        binSearchByNomorIjazahMerge(l, m, r); 
			    } 
			}

				void binSearchByNomorIjazahMerge(int l, int m, int r){
					int i, j, k; 
				    int n1 = m - l + 1; 
				    int n2 =  r - m; 
				  	
				    sIjazah L[n1], R[n2]; 
				  	
				    for (i = 0; i < n1; i++) 
				        L[i] = siswaFile[l + i]; 
				    for (j = 0; j < n2; j++) 
				        R[j] = siswaFile[m + 1+ j]; 
			
				    i = 0;
				    j = 0;
				    k = l;
				    while (i < n1 && j < n2) 
				    { 
				        if (L[i].nomor_ijazah <= R[j].nomor_ijazah) 
				        { 
				            siswaFile[k] = L[i]; 
				            i++; 
				        } 
				        else
				        { 
				            siswaFile[k] = R[j]; 
				            j++; 
				        } 
				        k++; 
				    } 
				    while (i < n1) 
				    { 
				        siswaFile[k] = L[i]; 
				        i++; 
				        k++; 
				    } 
				    while (j < n2) 
				    { 
				        siswaFile[k] = R[j]; 
				        j++; 
				        k++; 
				    } 
				}

			void binSearchByNomorIjazahQuick(int first, int last){
				int low, high;
				string list_separator;

			   	low = first;
			   	high = last;
			   	list_separator = siswaFile[(first + last) / 2].nomor_ijazah;

			   	do {
			      	while(siswaFile[low].nomor_ijazah < list_separator)
			         	low++;
			      	while(siswaFile[high].nomor_ijazah > list_separator)
			         	high--;

			      	if(low <= high)
			      	{
			         	temp = siswaFile[low];
			         	siswaFile[low++] = siswaFile[high];
			         	siswaFile[high--] = temp;
			 		}
			   	} while(low <= high);

			   	if(first < high) binSearchByNamaQuick(first, high);
			   	if(low < last) binSearchByNamaQuick(low, last);
			}

void transaksi(){
	int pilih; 

	menu :
	cout<< "TRANSAKSI\n";
	cout<< "1. MERGING SAMBUNG \n2. SPLITTING \n3. BACK TO MAIN MENU \n";
	cout<< "PILIH : "; cin>> pilih;

	switch(pilih){
		case 1:
			mergingSambung();
			system("cls");
			goto menu;
			break;
		case 2:
			splitting();
			system("cls");
			goto menu;
			break;
		case 3:
			main();
		default :
			cout<< "Salah Input" << endl << endl;
			goto menu;
	}
} 

	void mergingSambung(){
		string file1, file2, file;
		int i = 0, j;

		getList();

		satu :
		cout<< "Ketik nama file pertama : "; cin>> file1;
		myFileIn.open(file1.c_str());
		if (!myFileIn.good())
		{
			cout<< file1 << " tidak ada di dalam direktori" << endl;
			myFileIn.close();
			goto satu;
		}

		while(true){
			getline(myFileIn, siswaFile[i].nama);
			if (myFileIn.eof())
			{
				break;
			}
			getline(myFileIn, siswaFile[i].TTL);
			myFileIn >> siswaFile[i].NISN;
			myFileIn >> siswaFile[i].nomor_ijazah;
			myFileIn >> siswaFile[i].banyak_nilai;
			j = 0;
			while(j < siswaFile[i].banyak_nilai){
				myFileIn.ignore();
				getline(myFileIn, siswaFile[i].daftarNilai[j].mapel);
				myFileIn >> siswaFile[i].daftarNilai[j].raport;
				myFileIn >> siswaFile[i].daftarNilai[j].ujian;
				j++;
			}
			myFileIn >> siswaFile[i].rata_raport;
			myFileIn >> siswaFile[i].rata_ujian;
			myFileIn.ignore();
			getline(myFileIn, siswaFile[i].keterangan);
			i++;
		}
		myFileIn.close();


		dua :
		cout<< "Ketik nama file kedua : "; cin>> file2;
		myFileIn.open(file2.c_str());
		if (!myFileIn.good())
		{
			cout<< file2 << " tidak ada di dalam direktori" << endl;
			myFileIn.close();
			goto dua;
		}

		while(true){
			getline(myFileIn, siswaFile[i].nama);
			if (myFileIn.eof())
			{
				break;
			}
			getline(myFileIn, siswaFile[i].TTL);
			myFileIn >> siswaFile[i].NISN;
			myFileIn >> siswaFile[i].nomor_ijazah;
			myFileIn >> siswaFile[i].banyak_nilai;
			j = 0;
			while(j < siswaFile[i].banyak_nilai){
				myFileIn.ignore();
				getline(myFileIn, siswaFile[i].daftarNilai[j].mapel);
				myFileIn >> siswaFile[i].daftarNilai[j].raport;
				myFileIn >> siswaFile[i].daftarNilai[j].ujian;
				j++;
			}
			myFileIn >> siswaFile[i].rata_raport;
			myFileIn >> siswaFile[i].rata_ujian;
			myFileIn.ignore();
			getline(myFileIn, siswaFile[i].keterangan);
			i++;
		}
		myFileIn.close();

		cout<< "Masukkan nama file baru : "; cin>> file;
		
		myFileOut.open("ListFile.txt", ios::app);
		myFileOut << file << endl;
		myFileOut.close();

		myFileOut.open(file.c_str());
		setFile(i);
		myFileOut.close();
	}

	void splitting(){
		int panjang;
		string file, file1, file2;

		cout<< "Splitting yang lulus dan tidak lulus" <<endl;
			
		getList();
		awal :
		cout<< "Ketik nama file yang akan displitting  : "; cin>> file;
		myFileIn.open(file.c_str());
		if (!myFileIn.good())
		{
			cout<< file << " tidak ada di dalam direktori" << endl;
			myFileIn.close();
			goto awal;
		}

		getFile(&panjang);
		myFileIn.close();
		cout<< "\tMasukkan nama file pertama hasil splitting (LULUS) : "; cin>> file1;
		myFileOut.open("ListFile.txt", ios::app);
		myFileOut << file1 << endl;
		myFileOut.close();

		cout<< "\tMasukkan nama file kedua hasil splitting (TIDAK LULUS) : "; cin>> file2;
		myFileOut.open("ListFile.txt", ios::app);
		myFileOut << file2 << endl;
		myFileOut.close();

		for (int i = 0; i < panjang; i++)
		{
			if (siswaFile[i].keterangan == "LULUS")
			{
				myFileOut.open(file1.c_str(), ios::app);
				myFileOut << siswaFile[i].nama << endl;
				myFileOut << siswaFile[i].TTL << endl;
				myFileOut << siswaFile[i].NISN << endl;
				myFileOut << siswaFile[i].nomor_ijazah << endl;
				myFileOut << siswaFile[i].banyak_nilai << endl;
				for (int j = 0; j < siswaFile[i].banyak_nilai; j++)
				{
					myFileOut << siswaFile[i].daftarNilai[j].mapel << endl;
					myFileOut << siswaFile[i].daftarNilai[j].raport << endl;
					myFileOut << siswaFile[i].daftarNilai[j].ujian << endl;
				}
				myFileOut << siswaFile[i].rata_raport << endl;
				myFileOut << siswaFile[i].rata_ujian << endl;
				myFileOut << siswaFile[i].keterangan << endl;
				myFileOut.close();
			}
			else
			{
				myFileOut.open(file2.c_str(), ios::app);
				myFileOut << siswaFile[i].nama << endl;
				myFileOut << siswaFile[i].TTL << endl;
				myFileOut << siswaFile[i].NISN << endl;
				myFileOut << siswaFile[i].nomor_ijazah << endl;
				myFileOut << siswaFile[i].banyak_nilai << endl;
				for (int j = 0; j < siswaFile[i].banyak_nilai; ++j)
				{
					myFileOut << siswaFile[i].daftarNilai[j].mapel << endl;
					myFileOut << siswaFile[i].daftarNilai[j].raport << endl;
					myFileOut << siswaFile[i].daftarNilai[j].ujian << endl;
				}
				myFileOut << siswaFile[i].rata_raport << endl;
				myFileOut << siswaFile[i].rata_ujian << endl;
				myFileOut << siswaFile[i].keterangan << endl;
				myFileOut.close();
			}
		}	
	}