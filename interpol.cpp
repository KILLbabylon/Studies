#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<iomanip>
using namespace std;

int main(){
    const int n=20;
    double x[n];
    for(int i=0; i<n; i++)
        x[i]=i+1;
    double y[n];
    ifstream plik;
    plik.open("interpolacja.txt");
    int i=0;
    string wartosc;
    if(plik.good()){
        while(!plik.eof()){
            getline(plik,wartosc);
            double warLicz=atof(wartosc.c_str());
            y[i]=warLicz;
            i++;
        }
    plik.close();
    }
    double a[n];
    double mian=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j!=i)
                mian=mian*(x[i]-x[j]);
                else continue;
        }
        a[i]=y[i]/mian;
        mian=1;
    }
    for(int i=0; i<n; i++){
        cout<<a[i];
        for(int j=0; j<n; j++){
            if(j!=i){
                if(j==n-1 || i==n-1)
                    cout << "(x-" << x[j] << ")";
                else 
                    cout << "(x-" << x[j] << ")*";
            }
        }
        if(i!=n-1)
            cout << "+";
    }
    cout << endl;
return 0;
}
