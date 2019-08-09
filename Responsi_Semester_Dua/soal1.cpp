#include <bits/stdc++.h>
using namespace std;

typedef struct{
	string jurusan;
	int jam;
	int durasi;
}Data;

Data data[1000];
ifstream myFileIn;
ofstream myFileOut;

void input();
void output();
void getFile(int *l);
void sortOut(int size);
void result();
void sortRe(int size);

int main(){
	int enter;
	
	top:
	
	cout<< "MENU : " << endl;
	cout<< "1. INPUT \n2. OUTPUT \n3. HASIL \n4. EXIT" << endl;
	cout<< "PILIH (1..4) : "; cin>> enter;
	
	switch (enter)
	{
		case 1:
			input();
			break;
		case 2:
			output();
			break;
		case 3:
			result();
			break;
		case 4:
			exit(1);
			break;	
		default:
			break;
	}
	cout<< endl << endl;
	goto top;
}

void getFile(int *l){
	int i = 0;
	myFileIn.open("file1.txt");
	while(true){
		getline(myFileIn, data[i].jurusan);
		if (myFileIn.eof())
		{
			break;
		}
		myFileIn >> data[i].jam;
		myFileIn >> data[i].durasi;
		myFileIn.ignore();
		i++;
	}
	myFileIn.close();
	*l = i;
}

void input(){
	int other;
	cout<< "JUMLAH JURUSAN LAIN : "; cin>>other;
	myFileOut.open("file1.txt", ios::app);
	for (int i = 0; i < other; i++)
	{
		cout<< i+1;
		cout<< "\tJURUSAN \t: "; cin.ignore(); getline(cin,data[i].jurusan);
		cout<< "\tJAM \t\t: "; cin>> data[i].jam;
		cout<< "\tDURASI \t\t: "; cin>> data[i].durasi;
		cout<< endl;
		myFileOut << data[i].jurusan << endl;
		myFileOut << data[i].jam << endl;
		myFileOut << data[i].durasi << endl;
	}
	myFileOut.close();
}

void output(){
	int length;
	
	getFile(&length);
	sortOut(length);
	
	for (int i = 0; i < length; i++)
	{
		cout<< i+1;
		cout<< "\t JURUSAN \t: " << data[i].jurusan << endl;
		cout<< "\t JAM \t\t: " << data[i].jam << endl;
		cout<< "\t DURASI \t: " << data[i].durasi << endl;
		cout<< endl;
	}
	
}

void sortOut(int size){
	Data temp;
	for(int current=0; current<size; current++)
	{
		for(int j=current+1; j<size; j++)
		{
			if(data[current].durasi+data[current].jam > data[j].durasi+data[j].jam)
			{
				temp = data[current];
				data[current] = data[j];
				data[j] = temp;
			}
		}
	}
		
	for(int current=0; current<size; current++)
	{
		for(int j=current+1; j<size; j++)
		{
			if(data[current].jam > data[j].jam)
			{
				temp = data[current];
				data[current] = data[j];
				data[j] = temp;
			}
		}
	}
}

void result(){
	int length;
	int a,b,s,j;
	getFile(&length);
	sortRe(length);
	
	s = 0;
	j = 1;
	myFileOut.open("file2.txt");
	for (int i = 0; i < length; i++)
	{
		a = data[i-j].jam + data[i-j].durasi;
		b = data[i].jam;
		
		if (i == 0)
		{
			cout<< s+1;
			cout<< "\t JURUSAN \t: " << data[i].jurusan << endl;
			cout<< "\t JAM \t\t: " << data[i].jam << endl;
			cout<< "\t DURASI \t: " << data[i].durasi << endl;
			cout<< endl;
			
			myFileOut << data[i].jurusan << endl;
			myFileOut << data[i].jam << endl;
			myFileOut << data[i].durasi << endl;
			
			s++;
			j = 1;
		}
		else
		{
			if (a <= b)
			{
				cout<< s+1;
				cout<< "\t JURUSAN \t: " << data[i].jurusan << endl;
				cout<< "\t JAM \t\t: " << data[i].jam << endl;
				cout<< "\t DURASI \t: " << data[i].durasi << endl;
				cout<< endl;
				
				myFileOut << data[i].jurusan << endl;
				myFileOut << data[i].jam << endl;
				myFileOut << data[i].durasi << endl;
				
				s++;
				j = 1;
			}
			else
			{
				j = j+1;
			}
		}
	}
	myFileOut.close();
	
	cout<< endl << "Kesimpulan : IF dapat menjalin kerjasama dengan " << s << " Jurusan lain." << endl;
	
}

void sortRe(int size){
	Data temp;
	for(int current=0; current<size; current++)
	{
		for(int j=current+1; j<size; j++)
		{
			if(data[current].durasi+data[current].jam > data[j].durasi+data[j].jam)
			{
				temp = data[current];
				data[current] = data[j];
				data[j] = temp;
			}
		}
	}
}