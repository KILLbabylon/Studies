#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;
typedef int** matrix;

void pamiecNew(int* t, const unsigned int n){
	for(unsigned int i=0;i<n;i++){
		t[i]=0;
	}
}
void pamiecDel(int *t, const unsigned int n){
	delete [] t;
	t = nullptr;
}
void wypelnij_losowo(int* t, const unsigned int n, int a, int b){
    int zakres = b - a + 1;
    srand(time(NULL));
    for (unsigned int i = 0; i < n; i++)
		t[i] = rand() % zakres + a;
}
int* traf(const unsigned int n){
	int *t=new int [n];
	cout<<"Podaj "<<n<<" typów:\n";
	for(unsigned int i=0;i<n;i++){
		cin>>t[i];
	}
	return t;
}
unsigned int porownaj(const int* t1, const int* t2, const unsigned int size, const unsigned int n_size){
	unsigned int n=0;
	for(unsigned int i=0;i<size;i++)
		for(unsigned int j=0;j<n_size;j++)
			if(t1[i]==t2[j])
				n++;
	if(n>0)
		return n;
	return 0;
}
void pamiecNew2(matrix& b, const int& m, const int& n){
    b = new int* [m];
    for (int i = 0; i < m; ++i){
        b[i] = new int[n];
	}
	for (int i=0;i<m; ++i)
        for (int j=0;j<n; ++j)
            b[i][j] = 0;
}
void pamiecDel2(matrix& b, const int& m, const int& n){
    for (int i = 0; i < m; i++)
        delete []b[i];
    delete []b;
}
int wypelnijLosowo(matrix& b, const int& m, const int& n, const int& minZ, const int& maxZ){
    int zakres = maxZ - minZ + 1;
    srand(time(NULL));
    for (int i=0;i<m; ++i)
        for (int j=0;j<n; ++j)
            b[i][j] = rand() % zakres + minZ;
    return 0;
}
int wypelnij(matrix& b, const int& m, const int& n){
    int sum=1;
    for (int i=0;i<m; i++){
        for (int j=0;j<n; j++){
            b[i][j] = sum;
            sum++;
        }
    }
    return 0;
}
int uzupelnij(const matrix& c, const int& m, const int& n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
            cin>>c[i][j];
    }
    return 0;
}
int wypisz(const matrix& c, const int& m, const int& n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
            cout<<"\t"<<c[i][j];
        cout << endl;
    }
    cout << endl;
    return 0;
}
int porownaj(matrix& a, matrix& b, const unsigned int& m, const unsigned int& n){
    unsigned int win=0;
	for(unsigned int i=0;i<m;i++){
		for(unsigned int j=0;j<n;j++){
			for(unsigned int k=0;k<n;k++){
				if(a[i][j]==b[i][k])
					win++;
			}
		}
	}
	if(win>0)
		return win;
	return 0;
}
int main(){
    matrix k;
    matrix A;

    cout<<"\n--------------------------lab03z02--------------------------\n";
	unsigned int x,y,nw=6,w=49;
    cout<<"podaj zakres od: ",cin>>x,cout<<" do: ",cin>>y;
	int *T= new int [w]; 
	pamiecNew(T,w);
	wypelnij_losowo(T,w,x,y);
	int *U=traf(nw);
	cout<<"Trafione: "<<porownaj(T,U,w,nw);
    
	pamiecDel(U,nw);
	pamiecDel(T,w);
    cout<<"\n--------------------------lab03z02--------------------------\n";

	cout<<"\n--------------------------lab03z04--------------------------\n";
	unsigned int m1=1,n1=6;
    cout<<"podaj zakres od: ",cin>>x,cout<<" do: ",cin>>y,cout<<"\nWylosuj sposrod 6 liczb\n";  
	
	
	pamiecNew2(k,m1,n1);
	uzupelnij(k,m1,n1);

	cout<<"Twoje liczby\n";
	wypisz(k,m1,n1);

	
	pamiecNew2(A,m1,n1);
	wypelnijLosowo(A,m1,n1,x,y);

	cout<<"Wylosowane liczby: ";
	wypisz(A,m1,n1);

	cout<<"Trafione: "<<porownaj(k,A,m1,n1)<<"\n";
	pamiecDel2(A,m1,n1);
	pamiecDel2(k,m1,n1);
    cout<<"\n--------------------------lab03z04--------------------------\n";
	return 0;
}