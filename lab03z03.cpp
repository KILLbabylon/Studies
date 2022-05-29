#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

typedef int** matrix;
void pamiecNew(matrix& b, const int& m, const int& n){
    b = new int* [m];
    for (int i = 0; i < m; i++){
        b[i] = new int[n];
	}
	for (int i=0;i<m; ++i)
        for (int j=0;j<n; j++)
            b[i][j] = 0;
}
int** utworz1(const unsigned int n,const unsigned int m){
	int **t = new int* [m];
	for (unsigned int i=0;i<m; i++){
        t[i] = new int [n];
    }
    for (unsigned int i=0;i<m; i++){
        for (unsigned int j=0;j<n; j++)
            t[i][j] = 0;
    }
	return t;
}
void utworz2(int**& t,const unsigned int n,const unsigned int m){
    t = new int* [m];
    for (unsigned int i=0;i<m; i++){
        t[i] = new int[n];
	}
	for (unsigned int i=0;i<m; i++)
        for (unsigned int j=0;j<n; j++)
            t[i][j] = 0;
}
void pamiecDel(matrix& b, const int& m, const int& n){
    for (int i = 0; i < m; i++)
        delete []b[i];
    delete []b;
}
int wypelnij(matrix& b, const int& m, const int& n, const int& minZ, const int& maxZ){
    int zakres = maxZ - minZ + 1;
    srand(time(NULL));
    for (int i=0;i<m; i++)
        for (int j=0;j<n; j++)
            b[i][j] = rand() % zakres + minZ;
    return 0;
}
int suma(const matrix &a, const int& m1,const int &n1, const matrix &b , const int& m2,const int &n2, const matrix &c){
    for(int i=0; i<m2; i++){
        for(int j=0; j<n1; j++){
            c[i][j]=a[i][j]+b[i][j];
        }
    }
    return 0;
}
int roznica(const matrix &a, const int& m1,const int &n1, const matrix &b , const int& m2,const int &n2, const matrix &c){
    for(int i=0; i<m2; i++){
        for(int j=0; j<n1; j++){
            c[i][j]=a[i][j]-b[i][j];
        }
    }
    return 0;
}
int iloczyn(const matrix &a, const int& m1,const int &n1, const matrix &b , const int& m2,const int &n2, const matrix &c){
    int suma;
    for(int i=0; i<m1; i++)
    {
        for(int j=0; j<n2; j++)
        {
            suma=0;
            for(int s=0; s<n1; s++)
            {
                suma+=a[i][s]*b[s][j];
            }
            c[i][j]=suma;
        }
    }
    return 0;
}
int transponowanie(const matrix &a, const int& m1,const int &n1, const matrix &b){
    for(int i=0; i<m1; i++){
        for(int j=0; j<n1; j++){
            b[i][j]=a[j][i];
        }
    }
    return 0;
}
int tabliczkaMnozenia(const matrix &a, const int& m1,const int &n1){
	for(int i=0; i<m1; i++){
		a[i][0]=i;
        for(int j=0; j<n1; j++){
			a[0][j]=j;
        }
    }
    for(int i=1; i<m1; i++){
        for(int j=1; j<n1; j++){
			a[i][j]=i*j;
        }
    }
    return 0;
}
int wypisz(const matrix& c, const int& m, const int& n){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout<<"\t"<<c[i][j];
        cout << endl;
    }
    cout << endl;
    return 0;
}
int main(){
	unsigned int m1,n1,m2,n2;
    matrix A;
    matrix B;
    matrix C;
    cout<<"podaj wielkosci maciezy do zadania 2: ",cin>>m1,cout<<" na: ",cin>>n1;
    int **a = utworz1(m1,n1);
	int**b;
    utworz2(b,m1,n1);
    cout<<"A:\n";
	wypisz(a,m1,n1);
    cout<<"B:\n";
	wypisz(b,m1,n1);
	pamiecDel(b,m1,n1);
	pamiecDel(a,m1,n1);

    cout<<"-----------Wypelnianie losowe-----------\n\n\n";
    cout<<"podaj wielkosc A: ",cin>>m1,cout<<" na: ",cin>>n1;
    pamiecNew(A, m1, n1);
    wypelnij(A,m1,n1,0,100);
    wypisz(A,m1,n1);
    cout<<"podaj wielkosc B: ",cin>>m2,cout<<" na: ",cin>>n2;
    pamiecNew(B, m2, n2);
    wypelnij(B,m2,n2,0,100);
    wypisz(B,m2,n2);
    cout<<"---------------------------------------\n\n\n";

    cout << "-----------------Suma-----------------\n";
    pamiecNew(C, m2, n2);
    suma(A,m1,n1,B,m2,n2,C);
    wypisz(C,m2,n2);
    pamiecDel(C, m2, n2);
    cout<< "---------------------------------------\n\n\n";

    cout << "---------------Roznica---------------\n";
    pamiecNew(C, m2, n2);
    roznica(A,m1,n1,B,m2,n2,C);
    wypisz(C,m2,n2);
    pamiecDel(C, m2, n2);
    cout<<"---------------------------------------\n\n\n";

    cout << "---------------Iloczyn---------------\n";
    pamiecNew(C, m2, n2);
    iloczyn(A,m1,n1,B,m2,n2,C);
    wypisz(C,m2,n2);
    pamiecDel(C, m2, n2);
    cout<<"---------------------------------------\n\n\n";

    cout << "----------Transponowanie----------\n";

    pamiecNew(C, m2, n2);
    transponowanie(A,m1,n1,C);
    wypisz(C,n1,m1);
    pamiecDel(C, m2, n2);
    cout<<"---------------------------------------\n\n\n";

    cout <<"\n\n----------tabliczka mnozenia----------\n";
    pamiecNew(C,m2,n2);
    tabliczkaMnozenia(C,m2,n2);
    wypisz(C,n2,m2);
    pamiecDel(C,m2,n2);
    cout<<"---------------------------------------\n\n\n";

    pamiecDel(A,m1,n1);
    pamiecDel(B,m2,n2);
    return 0;
}