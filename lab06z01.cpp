#include <iostream>
using namespace std;

float suma(float a, float b){
    return a+b;
}

float roznica(float a, float b){
    return a-b;
}

float iloczyn(float a, float b){
    return a*b;
}

float iloraz(float a, float b){
    if(b==0){
        return 0;
    }
    else{
        return a/b;
    }
}

bool sprawdz(float(*funkcja)(const float, const float),const float a,const float b){
    if(funkcja(a ,b) >= 0){
        return true;
    }
    else{
        return false;
    }
}


int main(int argc, char *argv[]){

     if(argc<2){
        cout<<"za mao\n";
    }
    else if(argc > 3){
        cout<<"za duzo\n";
        exit(0);
    }

float a=atof(argv[1]);
float b=atof(argv[2]);

cout<<suma(a,b)<<endl<<roznica(a,b)<<endl<<iloczyn(a,b)<<endl<<iloraz(a,b);


// cout << "\nPodaj dwie liczby: ", cin >> a >> b;
if(sprawdz(suma, a, b))
cout << "\nSuma jest wieksza lub rowna 0" << endl;
else
cout << "\nSuma jest mniejsza od 0" << endl;
if(sprawdz(roznica, a, b))
cout << "\nRoznica jest wieksza lub rowna 0" << endl;
else
cout << "\nRoznica jest mniejsza od 0" << endl;
if(sprawdz(iloczyn, a, b))
cout << "\nIloczyn jest wiekszy lub rowny 0" << endl;
else
cout << "\nIloczyn jest mniejszy od 0" << endl;
if(sprawdz(iloraz, a, b))
cout << "\nIloraz jest wiekszy lub rowny 0" << endl;
else
cout << "\nIloraz jest mniejszy od 0" << endl;
}