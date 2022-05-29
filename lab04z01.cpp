#include <iostream>
#include <ctype.h>
using namespace std;

int dlugosc(const char* a){
    unsigned int i = 0;
    while(a[i]!='\0'){
        i++;
    }
    return i;
}

char* wstaw(const char* zrodlo, char symbol){
    const int n = dlugosc(zrodlo);
    char* wynik = new char[n];

    for(int i=0; i<n+1; i++){
       wynik[i]=zrodlo[i];
    }
    for(int i=0; i<n; i++){
       if(i%3==0){
           wynik[i]=symbol;
       }
    }
    return wynik;
}

void wstaw(char* cel, const char* zrodlo, char symbol){
    const int n = dlugosc(zrodlo);
    for(int i=0; i<n+1; i++){
       cel[i]=zrodlo[i];
    }
    for(int i=0; i<n; i++){
       if(i%3==0){
           cel[i]=symbol;
       }
    }
    cout<<"\n\n"<<cel;
}

void wstaw1(char*& cel, const char* zrodlo, char symbol){
    const int n = dlugosc(zrodlo);
    cel = new char[n];

    for(int i=0; i<n+1; i++){
       cel[i]=zrodlo[i];
    }
    for(int i=0; i<n; i++){
       if(i%3==0){
           cel[i]=symbol;
       }
    }
    cout<<cel;
    delete[]cel;
    cel=nullptr;
}

int szukaj(char* zrodlo, char symbol){
    int i = 0, znaleziono = 0;
    while(zrodlo[i]!='\0'){
        i++;
    }
    for(int g=1;g<i;g++){
        if(zrodlo[g]==symbol){
            znaleziono++;
        }
    }
    return znaleziono;
}

char* kopiuj(const char* a){
    int b=0;
    while(a[b]!='\0'){
        b++;
    }
    char* k = new char[b];
    k[b]='\0';
    for(int i=0;i<b;i++){
        k[i]=toupper(a[i]);
    }
    return k;
}

int main(int argc, char *argv[]){

    if (argc < 3){
        cerr << "Za mało argumentów\n";
        exit(0);
    }
    if (argc > 3){
        cerr << "Za dużo argumentów\n";
        exit(0);
    }

    //...
    char* a = wstaw(argv[1], argv[2][0]);
    char* b, *c=0;
    delete[]a;
    a=nullptr;
    //...
    wstaw(b, argv[1], argv[2][0]);
    wstaw1(c, argv[1], argv[2][0]);
    //...
    cout << a << endl;
    cout << szukaj(a, 's') << endl;
    //...
    char* k1 = kopiuj(argv[1]);
    delete[]k1;
    k1 = nullptr;
    cout << a << endl;
    //...

    
    
}