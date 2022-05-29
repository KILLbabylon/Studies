#include <iostream>
#include <fstream>
using namespace std;
void selektor(){
    string a;
    int i;
    ofstream file;
    file.open ("adresy_email.txt");
    do{
        cin>>a;
        i = 0;
        while(a[i]!='\0'){
            i++;
            if(a[i]=='@'){
                file<<a<<';';
            }
        }
    }while(a!="END");
    file.close();
}
int main(){
    cout << "Podaj dane osobowe do wczytania: \n";
    selektor();
    return 0;
}