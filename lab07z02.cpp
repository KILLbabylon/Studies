#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string fileIntoString(const string& path){
    ifstream file(path);
    return string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}

int wystapienia(string loc, string x){
    ofstream plik;
    string str;
    str = fileIntoString(loc);

    int count = 0;
    plik.open(loc, std::ios_base::app);
        for(int i = 0; (i = str.find(x, i)) != std::string::npos; i++){
            count++;
        }
        plik.close();
        return count;
}

void filtr(char symbol, int ile, string loc, string out)
{
    fstream plik;
    fstream odp;
    plik.open(loc, ios::in);
    odp.open(out, ios::app);
    
    string napis;
    odp <<"\n----- "<< symbol <<" -----\n";
    do{
        int tmp = 0;
        plik >> napis;
        
        for(char c : napis){
            if(c == symbol)
                tmp++;
        }
        
        if(tmp == ile){ 
            odp << napis << endl;
        }
    }while(!plik.eof());
    
    plik.close();
    odp.close();
}

int main(int argc, char** argv){
    if(argc !=5){
        cerr << "mozna podac 4 argumenty\n";
        return -1;
    }
    string loc=(argv[1]);
    string out=(argv[2]);
    string zawartosc=(argv[3]);
    int ile=atof(argv[4]);
    cout<<"wystapienia "<<zawartosc<<": "<<wystapienia(loc, zawartosc)<<"\n";
    filtr(zawartosc[0], ile, loc, out);
    
    return 0;
}