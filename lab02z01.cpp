#include <iostream>
#include <cmath>
using namespace std;

long unsigned int SilniaRek(unsigned int n){
	if(n>1){
		return (n*SilniaRek(n-1));
		}
	else{
		return 1;
		}
	return 0;
	}
	
long unsigned int SilniaIt(unsigned int n){
	long unsigned int silnia=1;
	for(unsigned int i=0; i<n; i++){
				silnia *= i+1;
				}
			return silnia;
	}
	
unsigned int FibRek(unsigned int n){
	if(n<3){
		return 1;
		}
	return FibRek(n-2)+FibRek(n-1);
	}
	
unsigned int FibIt(unsigned int n){
	long long a = 0, b = 1;
	for(unsigned int i =0; i<n; i++){
		b += a;
		a = b-a;
		}
	return a;
	}

int main(){
	unsigned int n=0;
	int w=0;
	for(;;){
	cout<<"podaj akcje: \n0: wyjscie\n1: silnia rekurencyjna\n2: silnia iteracyjna\n3: Fibonacci rekurencyjnie\n4: Fibonacci iteracyjnie", cin>>w;
	switch(w){
		case 0:
		{
			exit(0);
			}
			break;
		case 1:
		{
			cout << "podaj n: ", cin >> n;
			if (cin.fail()) {
					cin.clear();
    				cout<<"nastepnym razem podaj liczbe\n";	
					exit(0);	
				}
				else{
					cout << SilniaRek(n) << "\n";
				}
			}
			break;
		case 2:
		{
			cout << "podaj n: ", cin >> n;
			if (cin.fail()) {
					cin.clear();
    				cout<<"nastepnym razem podaj liczbe\n";	
					exit(0);	
				}
				else{
					cout<<"wynik: "<<SilniaIt(n)<<"\n";
				}
			}
			break;
		case 3:
		{
			cout<<"podaj n: ", cin>>n;
			
			if (cin.fail()){
						cin.clear();
						cout<<"nastepnym razem podaj liczbe\n";     
						exit(0); 
			}
			else{
				if(n<0){
				cout<<"zostaly podane liczby ujemne\n";
				exit(0);  
					}
					else{
						cout<<"wynik: "<<FibRek(n)<<"\n";
					}
			}
			}
			break;
		case 4:
		{
			cout<<"podaj n: ", cin>>n;
			
			if (cin.fail()){
						cin.clear();
						cout<<"nastepnym razem podaj liczbe\n";     
						exit(0); 
			}
			else{
				if(n<0){
				cout<<"zostaly podane liczby ujemne\n";
				exit(0);  
					}
					else{
						cout<<"wynik: "<<FibIt(n)<<"\n";
					}
			}
			}
			break;

		default:
		{
			cout<<"\nbledne dane\n";
		}
		}
	}
return 0;
}

