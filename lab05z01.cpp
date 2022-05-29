#include <iostream>
#include <cstring>
using namespace std;

void kopiuj(const string src, char*& dest)
{
	dest = new char [src.size()+1];
	size_t p = src.copy(dest, src.size());
	dest[p] = '\0';
}

string wstaw(const string src, const char s, size_t p){
	string dest;
    size_t i=0;
	for(;i < p; i++){
	dest +=src[i];
	dest += s;
    
	}
	 for(;i < src.size(); i++){
		dest += src[i];
	 }
	return dest;
}

string wstaw(const string src, const string s, size_t p){
    string dest;
    dest=src;
    return dest.replace(p, 1, s);
    
}

string wytnij(const string src, size_t n){
    string dest;
    dest=src;
    dest.erase(0,n);
    return dest;
}

int szukaj(const string src, const char s){
    string dest;
    dest=src;
    int counter=0;
    for(size_t i=0; i<dest.length();i++){
        if(dest[i]!=s){
            counter++;
        }
        else{
            return counter;
        }
    }
    return 0;
}

int porownaj(const string s1, const string s2){
    if(s1.length()==s2.length()){
        return 0;
    }
    else if(s1.length()<s2.length()){
        return -1;
    }
    else{
        return 1;
    }
    return 3;
}

int main(int argc, char *argv[]){

    if(argc<3){
        cout<<"za mao\n";
    }
    else if(argc > 4){
        cout<<"za duzo\n";
        exit(0);
    }

    string src(argv[1]); //glowny ciag
    char* s1(argv[2]); //symbol
    string s2(argv[3]); //ciag do porownania

	string dest = src;

    char* dest1 = nullptr;
    kopiuj(src, dest1);
    
    cout <<"oryginal: "<< src << '\n' <<"skopiowane do dest: "<< dest << endl;
	
	delete[] dest1;
	dest1 = nullptr;
    int x;

    cout<<"podaj pozyje do wstawienia symbolu: ",cin>>x;
    cout<<wstaw(src, s1, x)<<endl;
    cout<<"podaj popzyje do wstawienia symbolu: ",cin>>x;
    cout<<wstaw(src, s1, x)<<endl;
    cout<<"podaj ilosc symboli do wyciecia: ", cin>>x;
    cout<<wytnij(src,x)<<endl;
    cout<<"pozycja szukanego symbolu: "<<szukaj(src, s1[0])<<endl;
    cout<<"porownanie: "<<porownaj(s1, s2)<<endl;

	return 0;
}
