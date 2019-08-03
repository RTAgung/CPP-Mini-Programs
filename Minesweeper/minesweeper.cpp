#include <bits/stdc++.h>
using namespace std;

typedef struct{
	int win;
	int lose;
	int win_rate;
}Result;

typedef struct{
	string username;
	string password;
	Result rank;
}Data;

Result user ;
Data account[1000], temp;

ifstream myFileIn;
ofstream myFileOut;
string username, password;

char matrix[100][100], hidden[100][100], first[100][100];
int col, row, click;

void getFileAccount(int *l);
void historyOut();
void historyIn(int i, int l);
void signIn();
	void game();
		void play();
			void firstTouch();
			void hiddenMaker();
			void bombMaker(int bomb);
			void numberMaker();
			void playing(int bomb);
			void resultGame();
			void reset();
		void history();
void signUp();
void ranking();
	void rankByWin(int l);
	void rankByRate(int l);
	

int main(){
	system("cls");
	int menu;
	top :
	cout<< "Menu" << endl;
	cout<< "1. Sign in \n2. Sign up \n3. Rangking \n4. Exit" << endl;
	cout<< "Enter : "; cin>> menu;

	switch(menu){
		case 1:
			signIn();
			break;
		case 2:
			signUp();
			goto top;
			break;
		case 3:
			ranking();
			goto top;
		case 4:
			exit (1);
			break;
		default:
			cout<< "Wrong Input!";
			goto top;	
	}
	return 0;
}

void getFileAccount(int *l){
	int i;
	top :

	myFileIn.open("account.txt");
	if (!myFileIn.good())
	{
		myFileOut.open("account.txt");
		myFileOut.close();
		myFileIn.close();
		goto top;
	}
	i = 0;
	while(true){
		myFileIn >> account[i].username;
		if (myFileIn.eof())
		{
			break;
		}
		myFileIn >> account[i].password;
		i++;
	}
	*l = i;
	myFileIn.close();
}

void historyOut(){
	string file_name = username + ".txt";
	user.win_rate = (100*user.win)/(user.win + user.lose);
	myFileOut.open(file_name.c_str());
	myFileOut << user.win << endl;
	myFileOut << user.lose << endl;
	myFileOut << user.win_rate <<endl;
	myFileOut.close();
}

void historyIn(int i, int l){
	string file_name;
	if(i<l)
	{
		file_name = account[i].username + ".txt";
		myFileIn.open(file_name.c_str());

		myFileIn>>account[i].rank.win;
		myFileIn>>account[i].rank.lose;
		myFileIn>>account[i].rank.win_rate;

		myFileIn.close();
		historyIn(i+1, l);
	}
}

void signIn(){
	bool success;
	
	int length;

	getFileAccount(&length);

	system("cls");

	top :
	cout<< "Input Username : "; cin >> username;
	cout<< "Input Password : "; cin >> password;

	success = false;
	for (int i = 0; i < length; ++i)
	{
		if (username == account[i].username && password == account[i].password)
		{
			system("cls");
			success = true;
			cout<< "Sign in success!" << endl;
		}
	}

	if (!success)
	{
		cout<< endl << "Wrong username or password!" << endl << endl ; 
		goto top;
	}
	else
	{
		game();
	}
}

void signUp(){
	string us, pw;
	bool used;
	int length;

	getFileAccount(&length);

	system("cls");
	top :
	cout<< "Regristration" <<endl;
	cout<< "Input Username : "; cin >> us;
	cout<< "Input Password : "; cin >> pw; 
	
	used = false;
	for (int i = 0; i < length; ++i)
	{
		if (us == account[i].username)
		{
			used = true;
		}
	}

	if (used)
	{
		cout<< endl << "Username is already used!!" << endl << "Please Try Again" << endl << endl;
		goto top;
	}
	else
	{
		cout<< "Registration success!" << endl;
		system("pause");
		system("cls");
		myFileOut.open("account.txt", ios::app);
		myFileOut << us << endl;
		myFileOut << pw << endl;
		myFileOut.close();
	}
}

void ranking(){
	int length, sort;
	getFileAccount(&length);
	historyIn(0, length);
	system("cls");
	rank_top:
	cout<<"Sort by "<<endl;
	cout<<"1. Win\n2. Win rate\nInput : "; cin>>sort;
	switch(sort){
		case 1:
			rankByWin(length);
			break;
			
		case 2:
			rankByRate(length);
			break;

		default: 
		cout<<"Wrong Input!";
		goto rank_top;
	}
	
	system("cls");
	
	for (int i = 0; i < length; ++i)
	{
		cout<<i+1<<". "<<account[i].username<<endl;
		cout<<"   win      : "<<account[i].rank.win<<endl;
		cout<<"   lose     : "<<account[i].rank.lose<<endl;
		cout<<"   win rate : "<<account[i].rank.win_rate<<"%"<<endl<<endl;
	}
	system("pause");
	system("cls");
}
	
	void rankByWin(int l){
		for (int i=0; i<l; i++){
			for(int j=0; j<l-i-1; j++){
				if( account[j].rank.win < account[j+1].rank.win ){
					temp = account[j];
					account[j] = account[j+1];
					account[j+1] = temp;
				}
			}
		}
	}

	void rankByRate(int l){
		int j;

   for(int i=1; i<l; i++) {
      temp = account[i];
      j = i - 1;
      while((temp.rank.win_rate > account[j].rank.win_rate) & (j >= 0))
      {
         account[j+1] = account[j];
         j = j - 1;
         account[j+1] = temp;
      }
   }

	}

void game(){
	int menu;
	string file_name = username + ".txt";

	top :
	myFileIn.open(file_name.c_str());
	if (!myFileIn.good())
	{
		myFileOut.open(file_name.c_str());
		myFileOut << 0 << endl << 0 << endl << 0;

		myFileOut.close();
		myFileIn.close();
		goto top;
	}
	myFileIn >> user.win;
	myFileIn >> user.lose;
	myFileIn >> user.win_rate;
	
	myFileIn.close();

	top2 :
	cout<< "Menu" << endl;
	cout<< "1. Play \n2. History \n3. Logout" << endl;
	cout<< "Enter : "; cin >> menu;

	switch(menu){
		case 1:
			play();
			break;
		case 2:
			history();
			break;
		case 3:
			main();
			break;
		default :
			cout<< "Input Error" << endl << endl;
			goto top2;
	}
}
	
	void play(){
		int menu;
		int bomb;
		system("cls");

		cout<< "Difficult" << endl;
		cout<< "1. Easy \n2. Medium \n3. Hard \n4. Custom" << endl; //15,25,35
		cout<< "Enter : "; cin >> menu;

		if (menu == 4)
		{
			cout<< endl << endl <<"Enter row size   : "; cin>>row;
			cout<<"Enter col size   : "; cin>>col;
			cout<<"Enter total bomb : "; cin>>bomb;
			hiddenMaker();
		}
		else
		{
			row = (menu==1)? 5 : (menu==2)? 8 : 11;
			col = (menu==1)? 5 : (menu==2)? 8 : 11;
			bomb = (menu==1)? 3 : (menu==2)? 13 : 37;
			hiddenMaker();
		}
		

		firstTouch();
		bombMaker(bomb);
		numberMaker();
		playing(bomb);
	}

		void firstTouch(){
			int r,c;
			system("cls");
			cout<< "\t";
			for (int i = 0; i < col; ++i)
			{
				cout << setw(3) << i << " ";
			}
			cout<< endl;
			for (int i = 0; i < row; ++i)
			{
				cout<< i << "\t";
				for (int j = 0; j < col; ++j)
				{
					cout<< "[ ] ";
				}
				cout<< endl;
			}

			cout<<"\nInput example : 2 5";
			cout<<"\nInput row & coloumn	: "; cin>>r>>c;
			click = 0;
			for (int i = r-1; i < r+2; ++i)
			{
				for (int j = c-1; j < c+2; ++j)
				{
					first[i][j] = 'f';
					if (i >= 0 && i < row && j >= 0 && j < col)
					{
						click++;
					}
				}
			}
		}

		void hiddenMaker(){
			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < col; ++j)
				{
					hidden[i][j] = ' ';
				}
			}
		}

		void bombMaker(int bomb){
			int x,y;
			for (int i = 0; i < bomb; ++i)
			{
				random:
				
				x = rand() % row;
				//srand(time(NULL));
				y = rand() % col;
				//srand(time(NULL));
				
				if (matrix[x][y] == '*' || first[x][y] == 'f')
				{
					goto random;
				}
				else
				{
					matrix[x][y] = '*';
				}
			}
		}

		void numberMaker(){
			int exist;
			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < col; ++j)
				{
					if (matrix[i][j] != '*')
					{
						exist = 0;
						for (int k = i-1; k < i+2; ++k)
						{
							for (int l = j-1; l < j+2; ++l)
							{
								if (matrix[k][l] == '*')
								{
									exist++;
								}
							}
						}
						matrix[i][j] = (char)(exist+48);
					}
				}
			}
		}

		void playing(int bomb){
			int r, c, a, w;
			w = (row * col) - bomb - click;
			a=0;

			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < col; ++j)
				{
					if (first[i][j] == 'f')
					{
						hidden[i][j] = matrix[i][j];
					}
				}
			}

			rowcol :
			system("cls");
			cout<< "\t";
			for (int i = 0; i < col; ++i)
			{
				cout << setw(3) << i << " ";
			}
			cout<< endl;
			for (int i = 0; i < row; ++i)
			{
				cout<< i << "\t";
				for (int j = 0; j < col; ++j)
				{
					cout<< "[" << hidden[i][j] << "] ";
				}
				cout<< endl;
			}
			
			if ((a==0 || hidden[r][c] != '*') && a < w){
				cout<<"\nInput example : 2 5";
				cout<<"\nInput row & coloumn	: "; cin>>r>>c;
				if (hidden[r][c] != ' ')
				{
					goto rowcol;
				}
				else if (r < row && r >= 0 && c < col && c >= 0){
					hidden[r][c] = matrix[r][c];
					a++;
					goto rowcol;
				}
				else {
					a++;
					goto rowcol;
				}
			}
			
			if (hidden[r][c] == '*')
			{
				resultGame();
				cout<<"\n======================YOU LOSE !!======================\n\n";
				user.lose++;
				historyOut();
				reset();
				system("pause");
				system("cls");
				game();
			}
			else if (a == w)
			{
				resultGame();
				cout<<"\n======================YOU WIN !!======================\n\n";
				user.win++;
				historyOut();
				reset();
				system("pause");
				system("cls");
				game();
			}
		}

		void resultGame(){
			system("cls");
			cout<< "\t";
			for (int i = 0; i < col; ++i)
			{
				cout << setw(3) << i << " ";
			}
			cout<< endl;
			for (int i = 0; i < row; ++i)
			{
				cout<< i << "\t";
				for (int j = 0; j < col; ++j)
				{
					cout<< "[" << matrix[i][j] << "] ";
				}
				cout<< endl;
			}
		}

		void reset(){
			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < col; ++j)
				{
					matrix[i][j] = ' ';
					first[i][j] = ' ';
				}
			}
		}

	void history(){
		system("cls");
		cout<< "\t" << username << endl;
		cout<< "win      : " << user.win << endl;
		cout<< "lose     : " << user.lose << endl;
		cout<< "win rate : " << user.win_rate << '%' << endl << endl;

		system("pause");
		system("cls");
		game();
	}