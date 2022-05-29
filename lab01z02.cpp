#include <iostream>
using namespace std;

int Zad1A(int& n){
	for(int i = 0; i < n; ++i){
		cout << "Jacek Tyras\n";
	}
	cout << endl;
	return 0;
}
int Zad1B(int& n){
	int i = 0;
	while (i < n){
		cout << "Jacek Tyras\n";
		++i;
	}
	cout << endl;
	return 0;
}
int Zad1C(int& n){
	int i = 0;
	do {
		cout << "Jacek Tyras\n";
		++i;
	}while(i < n);
	cout << endl;
	return 0;
}

int Zad2(int a,int b, int c){
	int max = a;
	if(max < b){
		max = b;
		if(max < c)
			max = c;	
	}
	else{
		if(max < c)
		max = c;
		}		
	cout <<"max: "<< max;
    return 0;
}

int Zad3(int* T, int n){
	for(unsigned int i = 0; i < n; ++i){
		T[i] = i + (-5);
		cout << T[i] << "\n";
	}
	return 0;
}

int Zad4(int* T, int n){
	T[0] = 1;
	T[1] = 1;
	cout << T[0] <<"\n";
	cout << T[1] <<"\n";
	for(unsigned int i = 2;i < n; ++i){
		T[i] = T[i-1] + T[i-2];
		cout << T[i] << endl;
	}
	return 0;	
}

int Zad5(int* T, int n,int suma){
	T[0] = 1;
	T[1] = 1;
	suma = T[0] + T[1];
	for(unsigned int i = 2;i < n; ++i){
		T[i] = T[i-1] + T[i-2];
		suma += T[i];
	}
	cout << suma;
	return 0;	
}

int Zad6(int* T, int n,int suma){
	T[0] = 1;
	T[1] = 1;
	suma = T[0] + T[1];
	for(unsigned int i = 2;i < n; ++i){
		T[i] = T[i-1] + T[i-2];
		if(T[i] % 2 == 0)
			suma += T[i];
	}
	cout << suma;
	return 0;	
}

int Zad7(int* T, int n){
	for(unsigned int i = 0;i < n; ++i){
		if(i % 2 == 0)
			T[i] = i * 2;
		else
			T[i] = i - 1;
	}
	for(unsigned int i = 0;i < n; ++i){
		cout << T[i] <<"\n";
	}
	return 0;
}

int Zad8(int n,int silnia){
	for(unsigned int i = n;i > 1; --i){
		silnia *= i;
	}
	cout << silnia;
	return 0;
}

int Zad9(int n){
	if(n>1){
		return n*Zad9(n-1);
	}
	else{
		return 1;
	}
}

int Zad10(int* T, int n, int max){
	int i = 0;
	max = T[i];
	for(unsigned int i = 0;i < n; i++){
		if(T[i] > max)
			max = T[i];
	}
	cout << "\nmax: " << max;
	return 0;
}

int Zad11(int* T, int n,int max){
	unsigned int i=0;
	max = T[i];
	for(i = 0; i < n; i++){
		if(T[i] > max){
			max = T[i];
		}
	}
	for(i = 0;i < n; i++){
		if(T[i] == max)
			cout << "index max: " << i;
	}
	return 0;
}


float Zad12(int* T, int n){
	int tmp,counter = 0;
	for(unsigned int i = 0;i < n; i++){
		if(T[i] % 2 != 0 && T[i] % 3 == 0){
			tmp += T[i];
			counter++;
		}
	}
	return tmp/counter;
}

int Zad13(int* T, int n){
	for(unsigned int i = 0;i < n; ++i){
		if(i % 2 == 0){
			T[i] = 0;
		}
		else{
			T[i] = 2;
		}
	}
	for(unsigned int i = 0;i < n; ++i)
		cout << T[i] << "\n";
	return 0;
}

int main(){
for(;;){
int a=0;
    cout<<"\nwybierz akcje: \n";
    cout<<"0: wyjscie\n1: zad1\n2: zad2\n3: zad3\n4: zad4\n5: zad5\n6: zad6\n7: zad7\n8: zad8\n9: zad9\n10: zad10\n11: zad11\n12: zad12\n13: zad13\n";
    cin>>a;

    switch(a){

        case 0:
            exit(1);
        break;

        case 1:
            {
            int n;
	        cout <<"Podaj n: ",cin >> n;
	        Zad1A(n);
	        Zad1B(n);
	        Zad1C(n);
            }
        break;

        case 2:
            {
            int a, b ,c = 0;
	        cout <<"Podaj pierwsza liczbe: ",cin >> a;
	        cout <<"Podaj druga liczbe: ",cin >> b;
	        cout <<"Podaj trzecia liczbe: ",cin >> c;
	        Zad2(a,b,c);
            }
        break;

        case 3:
            {
            unsigned const int n = 20;
	        int T[n];
	        Zad3(T,n);   
            }
            break;

        case 4:
            {
            unsigned const int n = 20;
	        int T[n];
	        Zad4(T,n);
            }
            break;

        case 5:
            {
            int suma;
	        unsigned const int n = 20;
	        int T[n];
	        Zad5(T,n,suma);
            }
            break;

        case 6:
            {
            int suma;
	        unsigned const int n = 20;
	        int T[n];
	        Zad6(T,n,suma);
            }
            break;

        case 7:
            {
            unsigned const int n = 20;
	        int T[n];
	        Zad7(T,n);
            }
            break;

        case 8:
            {
            unsigned int n;
	        int silnia = 1;
	        cout << "Podaj n: ",cin >> n;
	        Zad8(n,silnia);
            }
            break;

        case 9:
            {
            unsigned int n;
	        int silnia = 1;
	        cout << "Podaj n: ",cin >> n;
	        cout<<Zad9(n);
            }
            break;

        case 10:
            {
            unsigned const int n = 5;
	        int T[n], max = 0;
	        for(int i = 0;i < n; i++){
		        cout << "podaj wartosc: ",cin >> T[i];
	        }
	        Zad10(T,n,max);
            }
            break;

        case 11:
            {
            unsigned const int n = 4;
	        int T[n], max = 0;
	        for(int i = 0;i < n; i++){
		        cout << "podaj wartosc: ", cin >> T[i];
	        }
	        cout<<endl;
	        Zad11(T,n,max);
            }
            break;

        case 12:
            {
            unsigned const int n = 6;
	        int T[n];
	        for(unsigned int i = 0;i < n; i++){
		        T[i] = i;
	        }
	        cout<<Zad12(T,n);
            }
            break;

        case 13:
            {
            unsigned const int n = 15;
	        int T[n];
	        Zad13(T,n);
            }
            break;
    }
}
return 0;
}
