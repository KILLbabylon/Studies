#include <iostream>

using namespace std;
float dodawanie(float a,float b){
	return a+b;
}

float odejmowanie(float a,float b){
	return a-b;
}

float mnozenie(float a,float b){
	return a*b;
}

float dzielenie(float a,float b){
	return a/b;
}

long int kwadrat(long int podstawa)
{
	int wynik = 1;
	for (int i = 0; i < 2; i++)
		wynik *= podstawa;
	return wynik;
}

//alternatywnie można przekazać również stopień aby móc obliczyć dowolną potęgę 
// long int potega(long int podstawa, float stopien)
// {
// 	int wynik = 1;
// 	for (int i = 0; i < stopien; i++)
// 		wynik *= podstawa;
// 	return wynik;
// }


long int szescian(long int podstawa)
{
	int wynik2 = 1;
	for (int i = 0; i < 3; i++)
		wynik2 *= podstawa;
	return wynik2;
}

double zad7(float x){
	return mnozenie(dodawanie(mnozenie(10, szescian(x)), mnozenie(3.1415, kwadrat(x))), odejmowanie(dzielenie(x,3), dzielenie(1, kwadrat(x))));
}

float trojkat(float a, float b, float c){
	return a+b+c;
}


float poleTrojkata(float a){
	return a/2;
}



int kalkulator(){
	float a,b,c,x;
	int w;
		cout<<"\n\npodaj operacje:\n0: wyjscie\n1: dodawanie\n2: odejmowanie\n3: mnozenie\n4: dzielenie\n5: kwadrat\n6: szescian\n7: obwod trojkata\n8:pole trojkata\n", cin>>w;
		switch(w){
			case 0:
			{
				exit(0);
			}
			break;

			case 1:
			{
				cout<<"podaj a: ", cin>>a, cout<<"podaj b: ", cin>>b;
				if (cin.fail()) {
						cin.clear();
						cout<<"nastepnym razem podaj liczbe\n"; 
						exit(0);      
					}
					else{
						cout<<"wynik: "<<dodawanie(a,b);
					}
			}
			break;

			case 2:
			{
				cout<<"podaj a: ", cin>>a, cout<<"podaj b: ", cin>>b;
				if (cin.fail()) {
						cin.clear();
						cout<<"nastepnym razem podaj liczbe\n";     
						exit(0);   
					}
					else{
						cout<<"wynik: "<<odejmowanie(a,b);
					}
			}
			break;

			case 3:
			{
				cout<<"podaj a: ", cin>>a, cout<<"podaj b: ", cin>>b;
				if (cin.fail()) {
						cin.clear();
						cout<<"nastepnym razem podaj liczbe\n";  
						exit(0);      
					}
					else{
						cout<<"wynik: "<<mnozenie(a,b);
					}
			}
			break;

			case 4:
			{
				cout<<"podaj a: ", cin>>a, cout<<"podaj b: ", cin>>b;
				if (cin.fail()&&b==0){
						cin.clear();
						cout<<"nastepnym razem podaj poprawna liczbe\n";  
						exit(0);     
					}
					else{
						cout<<"wynik: "<<dzielenie(a,b);
					}
			}
			break;

			case 5:
			{
				cout<<"podaj a: ", cin>>a;
				if (cin.fail()){
						cin.clear();
						cout<<"nastepnym razem podaj liczbe\n"; 
						exit(0);       
					}
					else{
						cout<<"wynik: "<<kwadrat(a);
					}
			}
			break;

			case 6:
			{
				cout<<"podaj a: ", cin>>a;
				if (cin.fail()){
						cin.clear();
						cout<<"nastepnym razem podaj liczbe\n";   
						exit(0);     
					}
					else{
						cout<<"wynik: "<<szescian(a);
					}
			}
			break;

			case 7:
			{
				cout<<"podaj a: ", cin>>a,cout<<"podaj b:",cin>>b, cout<<"podaj c:",cin>>c;
				
				if (cin.fail()){
							cin.clear();
							cout<<"nastepnym razem podaj liczbe\n";     
							exit(0); 
				}
				else{
					if(a<0 || b<0 || c<0){
					cout<<"zostaly podane liczby ujemne\n";
					exit(0);  
						}
						else{
							cout<<"wynik: "<<trojkat(a,b,c);
						}
				}
			}
			break;

			case 8:
			{
				cout<<"podaj a: ", cin>>a,cout<<"podaj b:",cin>>b, cout<<"podaj c:",cin>>c;
				
				if (cin.fail()){
							cin.clear();
							cout<<"nastepnym razem podaj liczbe\n";     
							exit(0); 
				}
				else{
					if(a<0 || b<0 || c<0){
					cout<<"zostaly podane liczby ujemne\n";
					exit(0);  
						}
						else{
							cout<<"wynik: "<<poleTrojkata(trojkat(a,b,c));
						}
				}
			}

			case 9:
			{
				cout<<"podaj x: ", cin>>a;
				if (cin.fail()){
						cin.clear();
						cout<<"nastepnym razem podaj liczbe\n";   
						exit(0);     
					}
					else{
						cout<<"wynik: "<<zad7(a);
					}
			}
			break;

			default:
			{
				cout<<"\nbledne dane\n";
				break;
			}
		}
	
	return 1;
}

int main(){
	while(kalkulator());
	return 0;		
}