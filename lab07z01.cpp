#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
using namespace std;

void zapisz_a(string loc){
    ofstream plik(loc);
        for(int i=0; i<10; i++){
            plik<<"Hello World!!!\n";
        }
        plik<<"\n";
        plik.close();
}

void zapisz(string loc, string content, int n){
    ofstream plik;
    plik.open(loc, std::ios_base::app);
        for(int i=0; i<n; i++){
            plik<<content<<"\n";
        }
        plik<<"\n";
        plik.close();
}

void zapisz(string loc, string content, int n, ofstream &plik){
    plik.open(loc, std::ios_base::app);
        for(int i=0; i<n; i++){
            plik<<content<<"\n";
        }
        plik<<"\n";
        plik.close();
}
    
int main(int argc, char** argv){
    
    if(argc !=4){
        cerr << "mozna podac 3 argumenty\n";
        return -1;
    }

    ofstream plik;
    int w;
    string loc=(argv[1]);
    string zawartosc=(argv[2]);
    unsigned int n=atof(argv[3]);
    
    for(;;){
    cout<<"prosze dokonac wyboru funkcji:\n0: wyjscie\n1: zapisz_a - nalezy pamietac, ze ta funkcja nadpisuje plik\n2: zapisz_a\n3: zapisz_b\n",cin>>w;

    switch(w){
        default:
        {
             cout<<"wybrano niepoprawny znak\n";
        }
        break;
    
        case 0:
        {
            exit(0);
        }
        break;

        
        case 1:
        {
            zapisz_a(loc);
        }
        break;

        
        case 2:
        {
            zapisz(loc, zawartosc, n);
        }
        break;

        
        case 3:
        {
            zapisz(loc, zawartosc, n, plik);
        }
        break;
        }
    }
  return 0;
}