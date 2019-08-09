#include <bits/stdc++.h>
using namespace std;

void sort(int banyak, int array[]);

int main()
{
	int banyak;
	int *ptr;

	cout<< "Masukan banyak bilangan : "; cin >> banyak;
	int array[banyak];
	
	ptr = array;
	for (int i = 0; i < banyak; ++i)
	{
		cout<< "Angka " << i+1 << " : "; 
		cin>>array[i]; 
	}


	int pilih;
	char back;
	int akhir = sizeof(array)/sizeof(array[0]) - 1;

	sort(banyak,array);
	do{
		cout<< endl << "1. MIN \n2. MAX " << endl;
		cout<< "PILIH : "; cin>> pilih;

		switch(pilih){
			case 1:
				cout<< endl << *ptr;
				break;
			case 2:
				cout<< endl << *(ptr + akhir);
				break;
			default:
				cout<< "SALAH INPUT!";
		}
		cout<< endl << endl << "Balik (y/t) ? "; cin>> back;
	}while(back == 'y' || back == 'Y');

	return 0;
}

void sort(int banyak, int array[]){
	int temp;
	for(int i=0; i<banyak; i++)  
	{
	    for(int j=i+1; j<banyak; j++)		 
		{
	        if(array[i] > array[j]) 
	        {
	          	temp = array[i];
	          	array[i] = array[j];
	          	array[j] = temp;
	        }
	    }
	}
}
