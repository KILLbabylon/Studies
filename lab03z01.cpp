#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

void wypisz(const int* t, const unsigned int n){
	for(unsigned int i=0; i<n; ++i){
		cout<<t[i]<<" ";
	}
	cout<<endl;
}
int* utworz1(const unsigned int n){
	int *t = new int [n];
	return t;
}
void utworz2(int*& t, const unsigned int n){
	t = new int [n];
	for(unsigned int i=0;i<n;i++){
		t[i]=0;
	}
}
void utworz3(int* t, const unsigned int n){
	for(unsigned int i=0;i<n;i++){
		t[i]=0;
	}
}
void utworz3(int** t, const unsigned int n, const unsigned int m)
{
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < m; j++)
        {
            t[i][j] = 0;
        }
    }
}
int zwolnij(int *t, const unsigned int n){
	delete [] t;
	t = nullptr;
	return 0;
}
void wypelnij01(int* t, const unsigned int n){
	unsigned int m=n/2;
	for(unsigned int i=0;i<m;i++)
		t[i]=0;
	for(unsigned int i=m;i<n;i++)
		t[i]=i+1;
}
void losowo(int* t, const unsigned int n){
	for (unsigned i = 0; i < n; i++){
		t[i] = rand() % 100;
	}
}
void wypelnij_losowo(int* t, const unsigned int n, int a, int b){
    int zakres = b - a + 1;
    srand(time(NULL));
    for (unsigned int i = 0; i < n; ++i)
		t[i] = rand() % zakres + a;
}
int* suma1(const int* t1, const int* t2, const unsigned int n){
	int *t3=new int [n];
	for(unsigned int i=0;i<n;i++)
		t3[i]=t1[i]+t2[i];
	return t3;
}
void suma2(const int* t1, const int* t2, int*& t3, const unsigned int n){
	t3 = new int[n];
	for(unsigned int i=0;i<n;i++)
		t3[i]=t1[i]+t2[i];
	cout<<"Suma 2: ";
	for(unsigned int i=0;i<n;i++)
		cout<<t3[i]<<" ";
	cout<<"\n";
}
void suma3(const int* t1, const int* t2, int* t3, const unsigned int n){
	for(unsigned int i=0;i<n;i++)
		t3[i]=t1[i]+t2[i];
	cout<<"Suma 3: ";
	for(unsigned int i=0;i<n;i++)
		cout<<t3[i]<<" ";
	cout<<"\n";
}
int* kasuj(int* t, const unsigned n, const unsigned e){
	int* wynik = new int[n - 1];
	for (unsigned i = 0; i < n - 1; i++){
		wynik[i] = i < e ? t[i] : t[i + 1];
	}
	return wynik;
}
int* zadanie9(const int* t, const unsigned int n,const unsigned int m){
	int *t2=new int [n];
	t2[0]=m;
	for(unsigned int i=1;i<n;i++){
		t2[i]=t[i];
	}
	return t2;
}
void wstaw(int* t, int x){
	t[0] = x;
}

int main(){
	int a,b,x,n=0;
	int w=1;
	int* t = new int[n];
	
	cout<<"\n1: zad1\n2: zad2\n3: zad3\n4: zad4\n5: zad5\n6: zad6\n7: zad7\n8: zad8\n9: zad9\n";

	switch(w){
		
		case 1:
		{
			n=0;
			cout << "Zadanie 1" << endl;
			cout<<"podaj n: ",cin>>n;
			t = utworz1(n);
			losowo(t, n);
			wypisz(t, n);
			zwolnij(t, n);
			
		}
		
		
		case 2:
		{
			n=0;
			cout << "\nZadanie 2\n" << endl;
			cout << "\nZadanie 2.a\n" << endl;
			cout<<"\npodaj n: ",cin>>n;
			t = utworz1(n);
			wypisz(t, n);
			zwolnij(t, n);
			n=0;

			cout << "Zadanie 2.b\n" << endl;
			cout<<"podaj n: ",cin>>n;
			utworz2(t, n);
			wypisz(t, n);
			zwolnij(t, n);
			n=0;

			cout << "Zadanie 2.c\n" << endl;
			cout<<"podaj n: ",cin>>n;
			utworz3(t, n);
			wypisz(t, n);
			zwolnij(t, n);
			
		}
		
		
		case 3:
		{
			n=0;
			cout << "Zadanie 3\n" << endl;
			cout<<"podaj n: ",cin>>n;
			t = utworz1(n);
			zwolnij(t, n);
			cout<<"\nzwolniono\n";
			
		}
		
		
		case 4:
		{
			n=0;
			cout << "Zadanie 4\n" << endl;
			cout<<"podaj n: ",cin>>n;
			t = utworz1(n);
			wypelnij01(t, n);
			wypisz(t, n);
			zwolnij(t, n);
			
		}
	
		
		case 5:
		{
			n=0;
			cout << "Zadanie 5\n" << endl;
			cout<<"podaj n: ",cin>>n;
			t = utworz1(n);
			losowo(t, n);
			wypisz(t, n);
			zwolnij(t, n);
			
		}
		
		
		case 6:
		{
			n=0;
			cout << "Zadanie 6" << endl;
			cout<<"podaj n: ",cin>>n;
			cout<<"podaj zakres od: ",cin>>a,cout<<" do: ",cin>>b;
			t = utworz1(n);
			wypelnij_losowo(t, n, a, b);
			wypisz(t, n);
			zwolnij(t, n);
			
		}
		
		case 7:
		{
			n=0;
			cout << "Zadanie 7\n" << endl;
			cout<<"podaj n: ",cin>>n;
			t = utworz1(n);
			int* t1 = new int[n];
			int* t2 = new int[n];

			cout << "Zadanie 7.a\n" << endl;
			cout << "\nTablica 1: " << endl;
			losowo(t1, n);
			wypisz(t1, n);
			
			cout << "\nTablica 2: " << endl;
			losowo(t2, n);
			wypisz(t2, n);

			cout << "\nSuma: " << endl;
			suma1(t1, t2, n);
			zwolnij(t1, n);
			zwolnij(t2, n);

			cout << "Zadanie 7.b\n" << endl;

			t1 = utworz1(n);
			t2 = utworz1(n);
			int* t3 = new int[n];

			cout << "\nTablica 1: " << endl;
			losowo(t1, n);
			wypisz(t1, n);
			
			cout << "\nTablica 2: " << endl;
			losowo(t2, n);
			wypisz(t2, n);
			cout << "\nSuma: " << endl;
			suma2(t1, t2, t3, n);
			wypisz(t3, n);
			zwolnij(t1, n);
			zwolnij(t2, n);
			zwolnij(t3, n);

			cout << "Zadanie 7.c\n" << endl;

			t1 = utworz1(n);
			t2 = utworz1(n);
			t3 = utworz1(n);
			
			cout << "Tablica 1: " << endl;
			losowo(t1, n);
			wypisz(t1, n);
			
			cout << "Tablica 2: " << endl;
			losowo(t2, n);
			wypisz(t2, n);
			
			cout << "Suma: " << endl;
			suma3(t1, t2, t3, n);
			wypisz(t3, n);

			zwolnij(t1, n);
			zwolnij(t2, n);
			zwolnij(t3, n);
			
		}
		
		case 8:
		{
			n=0;
			unsigned e;
			cout << "Zadanie 8" << endl;
			cout<<"podaj n: ",cin>>n;
			t = utworz1(n);
			losowo(t, n);
			wypisz(t, n);
			cout << "Podaj element do usuniecia: ",cin>>e;
			kasuj(t, n, e);
			wypisz(t, n - 1);
			zwolnij(t, n);
			
		}
		
		case 9:
		{
			n=0;
			cout << "Zadanie 9" << endl;
			cout<<"podaj n: ",cin>>n;
			t = utworz1(n);
			losowo(t, n);
			wypisz(t, n);
			cout << "Podaj nowe T[0]: ", cin>>x;
			wstaw(t, x);
			wypisz(t, n);
			zwolnij(t, n);
			
		}
		

		default:
		{
			 exit(0);
		}
	}
	
	return 0;
}
	
