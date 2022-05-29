#include <iostream>


using namespace std;
void zamien1(int a, int b)
{
    int temp;
    
    temp = a;
    a = b;
    b = temp;

    cout << "Zamiana poprzez wartosc: " << "\na = " << a << endl << "b = " << b << endl;
}
void zamien2(int* a, int* b)
{
    int temp;
    
    temp = *a;
    *a = *b;
    *b = temp;

    cout << "Zamiana poprzez wskaznik: " << "\na = " << *a << endl << "b = " << *b << endl;
}
void zamien3(int& a, int& b)
{
    int temp;
    
    temp = a;
    a = b;
    b = temp;

    cout << "Zamiana poprzez referencje: " << "\na = " << a << endl << "b = " << b << endl;
}

int main(){
    for(;;){
    	int a, b, w;
        cout << "\nakcja:\n0. wyjscie\n1: zamien1\n2: Zamien2\n3: Zamien\n", cin >> w;
        switch(w)
        {
            case 0:
            {
                exit(0);
            }
            break;
            
            
            case 1:
            {
                cout << "Wprowadz wartosc a: ", cin >> a;
				cout << "Wprowadz wartosc b: ", cin >> b;
				if (cin.fail()) {
					cin.clear();
    				cout<<"nastepnym razem podaj liczbe\n";
                    exit(0);		
				}
				else{
					zamien1(a,b);
				}
				break;
			}
                
            
            case 2:
            {
                cout << "Wprowadz wartosc a: ", cin >> a;
                cout << "Wprowadz wartosc b: ", cin >> b;
				if (cin.fail()) {
					cin.clear();
    				cout<<"nastepnym razem podaj liczbe\n";		
                    exit(0);
				}
				else{
					zamien2(&a,&b);
				}
                break;
            }
            case 3:
            {
                cout << "Wprowadz wartosc a: ", cin >> a;
                cout << "Wprowadz wartosc b: ", cin >> b;
				if (cin.fail()) {
					cin.clear();
    				cout<<"nastepnym razem podaj liczbe\n";	
                    exit(0);	
				}
				else{
					zamien3(a,b);
				}
                
            }
            break;
        
        	
            default:
            	cout << "\nBledne dane\n";
            break;
        }
    }

}

