#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

int BatasAkun = 0;
int pilih1, pilih2, hargagame[5][5], harga, jumlah, bayar, kembalian;
string reg[100][3], login[100][2], namagame[5][5];
char daftar, masuk, ulang, oke, Home;
int u, sukses = 0;


void VoidRegister();
void VoidLogin();
void NamaGame();
void AwalHarga();
void GameAction();
void GameRPG();
void GamePuzzle();
void GameSport();
void GameSim();
void Hitungan();
int HargaHitungan();
void Pembayaran();


int main()
{
	NamaGame();
 	do{
		cout<< "<<<<<~~~   G A M E   S T O R E   ~~~>>>>>";

		AwalHarga();

		VoidRegister();
		
		VoidLogin ();

		jumlah = 1;
		do {
			cout<< "\n__________KATEGORI GAME\n";
			cout<< "1. Action\n2. Role Playing\n3. Puzzle\n4. Sport\n5. Simulation";
			cout<< "\nPilihan	: "; cin>>pilih1;
			
			switch (pilih1) {

				case 1 :
					GameAction();
					break;

				case 2 :
					GameRPG();
					break;

				case 3 :
					GamePuzzle();
					break;

				case 4 :
					GameSport();
					break;

				case 5 :
					GameSim();
					break;

				default : 
					cout<< "Input Anda Salah"<<endl;
			}

			if (pilih1>=1 && pilih1<=5){
				cout<< endl;
				cout<< "Apakah ingin belanja lagi ? (y/t) "; cin>> ulang;
				cout<< endl;
				if (ulang == 'y')
				{
					jumlah++;
				}
			}
			else {
				cout<< endl;
				cout<< "Apakah ingin kembali ke menu ? (y/t) "; cin>> ulang;
				cout<< endl;
			}
		} while (ulang=='y');

		system("cls");
		cout<<endl<< "Daftar Belanja"<<endl;
		
		Hitungan();

		Pembayaran();
	
		cout<< "Kembali ke Home ? (y/t) "; 
		cin>> Home;
		if (Home == 'y')
		{
			system("cls");
		}

	}while(Home == 'y');

	cout<<endl<<endl;
	if (BatasAkun > 0)
	{
		cout<< "Untuk : "<<endl;
		for (int i = 0; i <= BatasAkun; ++i)
		{
			if (i>0){
				cout<< "     " << i<< ". " <<reg[i][0] <<endl;
			}
		}
	}
	cout<< endl<<endl;
	cout<< "  *************************************************"<<endl;
	cout<< "  *                                               *"<<endl;
	cout<< "  *  Terima Kasih Telah Menggunakan Program Kami  *"<<endl;
	cout<< "  *                                               *"<<endl;
	cout<< "  *************************************************"<<endl;
	cout<<endl<<endl;
	cout<< "Created by LA & RTA"<<endl<<endl<<endl;
	system("pause");

	return 0;
}

void VoidRegister(){
	if (BatasAkun == 0){
			cout<< "\nRegister Akun ? (y/t) "; cin>>daftar;
			if (daftar == 'y')
			{
				BatasAkun++;
			}
		}else if (BatasAkun > 0 && BatasAkun < 100){
			cout<< "\nRegister Akun Lagi ? (y/t) "; cin>>daftar;
			if (daftar == 'y')
			{
				BatasAkun++;
			}
		}else {
			cout<< "Tidak Bisa Register Akun Lagi!!";
		}
		
		if(daftar=='y') {
			cout<< "\nREGISTER\n" ; 
			cout<< "Nama Panggilan : "; cin>>reg[BatasAkun][0];
			cout<< "Username       : "; cin>>reg[BatasAkun][1];
			cout<< "Password       : "; cin>>reg[BatasAkun][2];

		}
}

void VoidLogin(){
	do{
			cout<< "\nLogin Akun ? (y/t) "; cin>>masuk;
			if(masuk=='y'){
				u = 1;
				do {
					cout<< "\nLOGIN AKUN\n";
					cout<< "Username	: "; cin>>login[BatasAkun][0];
					cout<< "Password	: "; cin>>login[BatasAkun][1];
					for (int i = 0; i < 100; ++i)
					{
						if (login[BatasAkun][0]==reg[BatasAkun-i][1] && login[BatasAkun][1]==reg[BatasAkun-i][2])
						{
							system("cls");								
							cout<< "Login Sukses\n\n";
							cout<< "Atas Nama " << reg[BatasAkun-i][0]<<endl<<endl;
							sukses = 1;
							break;
						}
					}

					if (sukses == 1)
					{
						break;
					}
					else if (sukses == 0){
						cout<<"Login Gagal"<<endl;
						if (u==3)
						{
							cout<<"Coba Lagi di Lain Waktu"<<endl;
						}
					}
					cout<< endl;
					u++;
				} while(u<=3);
			}

		}while(u==4);
}

void AwalHarga(){
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
		hargagame[i][j] = 0;
		}
	}
}

void NamaGame(){
	//Game Action
	namagame[0][0] = "Assassin's Creed Identity";
	namagame[0][1] = "SoulBlade";
	namagame[0][2] = "The Amazing Spider-Man 2";
	namagame[0][3] = "Five Night at Freddy's";
	namagame[0][4] = "Space Marshals";
	//Game Role Playing
	namagame[1][0] = "80 Days";
	namagame[1][1] = "Evoland";
	namagame[1][2] = "WitchSpring3";
	namagame[1][3] = "Overlive: A Zombie Survival Story";
	namagame[1][4] = "Fairy Knights";
	//Game Puzzle
	namagame[2][0] = "The Room Two";
	namagame[2][1] = "Lara Croft GO";
	namagame[2][2] = "Monument Valley";
	namagame[2][3] = "Where's My Water";
	namagame[2][4] = "Legacy 2 - The Ancient Curse";
	//Game Sport
	namagame[3][0] = "True Skate";
	namagame[3][1] = "NBA JAM by EA SPORTS";
	namagame[3][2] = "Pool Break Pro #D Billiards";
	namagame[3][3] = "BCM Surfing Game";
	namagame[3][4] = "Football CEO Pro";
	//Game Simulation
	namagame[4][0] = "Jomblo Keren";
	namagame[4][1] = "Farming Simulator 18";
	namagame[4][2] = "Aerofly 2 Flight Simulator";
	namagame[4][3] = "Truck Simulation 16";
	namagame[4][4] = "Clouds & Sheep Premium";
}

void GameAction(){
		do {
		cout<< "\n__________MENU GAME ACTION\n";
		cout<< "1. Assassin's Creed Identity             Rp. 29000"<<endl;
		cout<< "2. SoulBlade                             Rp. 28000"<<endl;
		cout<< "3. The Amazing Spider-Man 2              Rp. 99000"<<endl;
		cout<< "4. Five Night at Freddy's                Rp. 37217"<<endl;
		cout<< "5. Space Marshals                        Rp. 61547"<<endl;
		cout<< "Pilihan : ";cin>>pilih2;
		cout<< endl;
		switch (pilih2) {

			case 1 : 
				cout<< "Anda Memilih "<< namagame[pilih1-1][pilih2-1] << " ? (y/t) ";
				cin>> oke;
				if (oke=='y'){
				hargagame[pilih1-1][pilih2-1] = 29000;
				}
				break;

			case 2 :
				cout<< "Anda Memilih "<< namagame[pilih1-1][pilih2-1] << " ? (y/t) ";
				cin>> oke;
				if (oke=='y'){
				hargagame[pilih1-1][pilih2-1] = 28000;
				}
				break;

			case 3 :
				cout<< "Anda Memilih "<< namagame[pilih1-1][pilih2-1] << " ? (y/t) ";
				cin>> oke;
				if (oke=='y'){
				hargagame[pilih1-1][pilih2-1] = 99000;
				}
				break;

			case 4 :
				cout<< "Anda Memilih "<< namagame[pilih1-1][pilih2-1] << " ? (y/t) ";
				cin>> oke;
				if (oke=='y'){
				hargagame[pilih1-1][pilih2-1] = 37217;
				}
				break;

			case 5 :
				cout<< "Anda Memilih "<< namagame[pilih1-1][pilih2-1] << " ? (y/t) ";
				cin>> oke;
				if (oke=='y'){
				hargagame[pilih1-1][pilih2-1] = 61547;
				}
				break;

			default :
				cout<< "Input Anda Salah"<<endl;
				cout<< "Kembali ? (y/t)"; cin>>oke;
				if (oke=='y'){
					oke = 't';
				}else if (oke=='t'){
					oke = 'y';
				}
			}
		}while (oke=='t');
}

void GameRPG(){
	do {
						cout<< "\n__________MENU GAME ROLE PLAYING\n";
						cout<< "1. 80 Days                               Rp. 59000"<<endl;
						cout<< "2. Evoland                               Rp. 15000"<<endl;
						cout<< "3. WitchSpring3                          Rp. 58000"<<endl;
						cout<< "4. Overlive: A Zombie Survival Story     Rp. 32000"<<endl;
						cout<< "5. Fairy Knights                         Rp. 27000"<<endl;
						cout<< "Pilihan : ";cin>>pilih2;
						cout<< endl;
						switch (pilih2) {

							case 1 : 
								cout<< "Anda Memilih "<< namagame[pilih1-1][pilih2-1] << " ? (y/t) ";
								cin>> oke;
								if (oke=='y'){
									hargagame[pilih1-1][pilih2-1] = 59000;
								}
								break;

							case 2 :
								cout<< "Anda Memilih "<< namagame[pilih1-1][pilih2-1] << " ? (y/t) ";
								cin>> oke;
								if (oke=='y'){
									hargagame[pilih1-1][pilih2-1] = 15000;
								}
								break;

							case 3 :
								cout<< "Anda Memilih "<< namagame[pilih1-1][pilih2-1] << " ? (y/t) ";
								cin>> oke;
								if (oke=='y'){
									hargagame[pilih1-1][pilih2-1] = 58000;
								}
								break;

							case 4 :
								cout<< "Anda Memilih "<< namagame[pilih1-1][pilih2-1] << " ? (y/t) ";
								cin>> oke;
								if (oke=='y'){
									hargagame[pilih1-1][pilih2-1] = 32000;
								}
								break;

							case 5 :
								cout<< "Anda Memilih "<< namagame[pilih1-1][pilih2-1] << " ? (y/t) ";
								cin>> oke;
								if (oke=='y'){
									hargagame[pilih1-1][pilih2-1] = 27000;
								}
								break;

							default :
								cout<< "Input Anda Salah"<<endl;
								cout<< "Kembali ? (y/t)"; cin>>oke;
								if (oke=='y'){
									oke = 't';
								}else if (oke=='t'){
									oke = 'y';
								}
						}
					}while (oke=='t');
}

void GamePuzzle(){
	do {
						cout<< "\n__________MENU GAME PUZZLE\n";
						cout<< "1. The Room Two                          Rp. 28000"<<endl;
						cout<< "2. Lara Croft GO                         Rp. 15000"<<endl;
						cout<< "3. Monument Valley                       Rp. 51000"<<endl;
						cout<< "4. Where's My Water                      Rp. 27000"<<endl;
						cout<< "5. Legacy 2 - The Ancient Curse          Rp. 30000"<<endl;
						cout<< "Pilihan : ";cin>>pilih2;
						cout<< endl;
						switch (pilih2) {

							case 1 : 
								cout<< "Anda Memilih "<< namagame[pilih1-1][pilih2-1] << " ? (y/t) ";
								cin>> oke;
								if (oke=='y'){
									hargagame[pilih1-1][pilih2-1] = 28000;
								}
								break;

							case 2 :
								cout<< "Anda Memilih "<< namagame[pilih1-1][pilih2-1] << " ? (y/t) ";
								cin>> oke;
								if (oke=='y'){
									hargagame[pilih1-1][pilih2-1] = 15000;
								}
								break;

							case 3 :
								cout<< "Anda Memilih "<< namagame[pilih1-1][pilih2-1] << " ? (y/t) ";
								cin>> oke;
								if (oke=='y'){
									hargagame[pilih1-1][pilih2-1] = 51000;
								}
								break;

							case 4 :
								cout<< "Anda Memilih "<< namagame[pilih1-1][pilih2-1] << " ? (y/t) ";
								cin>> oke;
								if (oke=='y'){
									hargagame[pilih1-1][pilih2-1] = 27000;
								}
								break;

							case 5 :
								cout<< "Anda Memilih "<< namagame[pilih1-1][pilih2-1] << " ? (y/t) ";
								cin>> oke;
								if (oke=='y'){
									hargagame[pilih1-1][pilih2-1] = 30000;
								}
								break;

							default :
								cout<< "Input Anda Salah"<<endl;
								cout<< "Kembali ? (y/t)"; cin>>oke;
								if (oke=='y'){
									oke = 't';
								}else if (oke=='t'){
									oke = 'y';
								}
						}
					}while (oke=='t');
}

void GameSport(){
	do {
						cout<< "\n__________MENU GAME SPORT\n";
						cout<< "1. True Skate                            Rp. 26000"<<endl;
						cout<< "2. NBA JAM by EA SPORTS                  Rp. 75000"<<endl;
						cout<< "3. Pool Break Pro #D Billiards           Rp. 27000"<<endl;
						cout<< "4. BCM Surfing Game                      Rp. 32000"<<endl;
						cout<< "5. Football CEO Pro                      Rp. 37222"<<endl;
						cout<< "Pilihan : ";cin>>pilih2;
						cout<< endl;
						switch (pilih2) {

							case 1 : 
								cout<< "Anda Memilih "<< namagame[pilih1-1][pilih2-1] << " ? (y/t) ";
								cin>> oke;
								if (oke=='y'){
									hargagame[pilih1-1][pilih2-1] = 26000;
								}
								break;

							case 2 :
								cout<< "Anda Memilih "<< namagame[pilih1-1][pilih2-1] << " ? (y/t) ";
								cin>> oke;
								if (oke=='y'){
									hargagame[pilih1-1][pilih2-1] = 75000;
								}
								break;

							case 3 :
								cout<< "Anda Memilih "<< namagame[pilih1-1][pilih2-1] << " ? (y/t) ";
								cin>> oke;
								if (oke=='y'){
									hargagame[pilih1-1][pilih2-1] = 27000;
								}
								break;

							case 4 :
								cout<< "Anda Memilih "<< namagame[pilih1-1][pilih2-1] << " ? (y/t) ";
								cin>> oke;
								if (oke=='y'){
									hargagame[pilih1-1][pilih2-1] = 32000;
								}
								break;

							case 5 :
								cout<< "Anda Memilih "<< namagame[pilih1-1][pilih2-1] << " ? (y/t) ";
								cin>> oke;
								if (oke=='y'){
									hargagame[pilih1-1][pilih2-1] = 37222;
								}
								break;

							default :
								cout<< "Input Anda Salah"<<endl;
								cout<< "Kembali ? (y/t)"; cin>>oke;
								if (oke=='y'){
									oke = 't';
								}else if (oke=='t'){
									oke = 'y';
								}
						}
					}while (oke=='t');
}

void GameSim(){
	do {
						cout<< "\n__________MENU GAME SIMULATION\n";
						cout<< "1. Jomblo Keren                          Rp.  3000"<<endl;
						cout<< "2. Farming Simulator 18                  Rp. 66000"<<endl;
						cout<< "3. Aerofly 2 Flight Simulator            Rp. 57000"<<endl;
						cout<< "4. Truck Simulation 16                   Rp. 25000"<<endl;
						cout<< "5. Clouds & Sheep Premium                Rp. 28000"<<endl;
						cout<< "Pilihan : ";cin>>pilih2;
						cout<< endl;
						switch (pilih2) {

							case 1 : 
								cout<< "Anda Memilih "<< namagame[pilih1-1][pilih2-1] << " ? (y/t) ";
								cin>> oke;
								if (oke=='y'){
									hargagame[pilih1-1][pilih2-1] = 3000;
								}
								break;

							case 2 :
								cout<< "Anda Memilih "<< namagame[pilih1-1][pilih2-1] << " ? (y/t) ";
								cin>> oke;
								if (oke=='y'){
									hargagame[pilih1-1][pilih2-1] = 66000;
								}
								break;

							case 3 :
								cout<< "Anda Memilih "<< namagame[pilih1-1][pilih2-1] << " ? (y/t) ";
								cin>> oke;
								if (oke=='y'){
									hargagame[pilih1-1][pilih2-1] = 57000;
								}
								break;

							case 4 :
								cout<< "Anda Memilih "<< namagame[pilih1-1][pilih2-1] << " ? (y/t) ";
								cin>> oke;
								if (oke=='y'){
									hargagame[pilih1-1][pilih2-1] = 25000;
								}
								break;

							case 5 :
								cout<< "Anda Memilih "<< namagame[pilih1-1][pilih2-1] << " ? (y/t) ";
								cin>> oke;
								if (oke=='y'){
									hargagame[pilih1-1][pilih2-1] = 28000;
								}
								break;

							default :
								cout<< "Input Anda Salah"<<endl;
								cout<< "Kembali ? (y/t)"; cin>>oke;
								if (oke=='y'){
									oke = 't';
								}else if (oke=='t'){
									oke = 'y';
								}
						}
					}while (oke=='t');
}

void Hitungan(){
	for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (hargagame[i][j]!=0)
				{
					cout<<setiosflags(ios::right)<<setw(33) << namagame[i][j]<<setiosflags(ios::right)<<setw(21) <<"Rp. "<<hargagame[i][j]<<endl;
				}
			}	
		}
}

int HargaHitungan(){
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (i >= 0 && j > 0)
			{
				hargagame[i][j] = hargagame[i][j] + hargagame[i][j-1];
			}
		}
	}
	for (int i = 0; i < 5; ++i)
		{
			if (i > 0)
			{
				hargagame[i][4] = hargagame[i][4] + hargagame[i-1][4]; 
			}
		}
	harga = hargagame[4][4];

	return harga;
}

void Pembayaran(){
		harga = HargaHitungan();
		cout<< "----------------------------------------------,-------------  +"<<endl;
		cout<< "Harga Total                                     = Rp. " <<harga<<endl;
		if (jumlah >= 5 && harga >= 125000)
		{
			harga = harga * 85/100;
			cout<< "Diskon pembelian aplikasi 5/keatas dan\n";
			cout<< "harga Rp. 125000/keatas (15%)                   = Rp. " <<harga<<endl;
		}else if (jumlah >= 5)
		{
			harga = harga * 95/100;
			cout<< "Diskon pembelian aplikasi 5/keatas (5%)         = Rp. " <<harga<<endl;
		}else if (harga >= 125000)
		{
			harga = harga * 90/100;
			cout<< "Diskon pembelian harga Rp. 125000/keatas (10%)  = Rp. " <<harga<<endl;
		}else
		{
			cout<< "Tidak ada diskon pembelian                      = Rp. " <<harga<<endl;
		}

		if (sukses == 1)
		{
			harga = harga * 90/100;
			cout<< "Diskon memiliki akun (10%%)                     = Rp. " <<harga<<endl<<endl;
		}else
		{
			cout<< "Tidak ada diskon memiliki akun                  = Rp. " <<harga<<endl<<endl;
		}

		do
		{
			cout<< "Harga Total                                     = Rp. " <<harga<<endl;
			cout<< "Bayar                                           = Rp. "; cin >>bayar;
			kembalian = bayar - harga;
			if (bayar >= harga)
			{
				cout<< "Kembalian                                       = Rp. " << kembalian<<endl<<endl;
			}
			else {
				cout<< "Pembayaran kurang gan!"<<endl<<endl;
			}
		}while(bayar < harga);
}
