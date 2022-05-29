#include <iostream>
using namespace std;
int main(){
	for(;;){
    int a=0;
    cout<<"\nwybierz akcje: \n";
    cout<<"0: wyjscie\n1: zad1\n2: zad2\n3: zad3\n4: zad4\n5: zad5\n6: zad6\n7: zad7\n8: zad8\n9: zad9\n10: zad10\n11: zad11\n12: zad12\n";
    cin>>a;
    unsigned const int n = 10;
    unsigned int m = 0;
    switch (a)
    {
    case 1:
    	{
		
        m=0;
	    cout <<"Podaj n: ",	cin >> m;
	    for(int i = 0; i < m; ++i){
		    cout << "Jacek Tyras\n";
	    }
	    cout << endl;
	    int i = 0;
	    while (i < m){
		    cout << "Jacek Tyras " << endl;
		    ++i;
	    }
	    cout << endl;
	    i = 0;
	    do {
		    cout << "Jacek Tyras " << endl;
		    i++;
	    }while(i < m);
    	}	
    	cout<<endl;
        break;
    case 2:
    	{
		
        int a, b ,c=0;
	    cout <<"Podaj liczbe: ", cin >> a;
	    cout <<"Podaj liczbe: ", cin >> b;
	    cout <<"Podaj liczbe: ", cin >> c;
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
		}
		cout<<endl;
        break;

    case 3:  
	{
	  
	    int T[n];
	    for(unsigned int i = 0; i < n; i++){
		    T[i] = i + (-5);
		    cout << T[i] << endl;
	    }
	}
		cout<<endl;
        break; 

    case 4:
    	{
		
        m = 0;
	    cout <<"podaj n: ", cin >> m;
	    int T[m];
	    T[0] = 1;
	    T[1] = 1;
	    cout << T[0] << "\n" << T[1] << "\n";
	    for(unsigned int i = 2;i < m; i++){
		    T[i] = T[i-1] + T[i-2];
		    cout << T[i] << endl;
	    }
	}
		cout<<endl;
        break;

    case 5:
    	{
		
        unsigned int sum=0;
	    cout <<"podaj n: ", cin >> m;
	    int T[m];
	    T[0] = 1;
	    T[1] = 1;
	    sum = T[0] + T[1];
	    for(unsigned int i = 2;i < m; ++i){
		    T[i] = T[i-1] + T[i-2];
		    sum = sum + T[i];
	    }
	    cout << sum;
	}
		cout<<endl;
        break;

    case 6:
    	{
		
        int sum;
	    int T[n];
	    T[0] = 1;
	    T[1] = 1;
	    sum = T[0] + T[1];
	    for(unsigned int i = 2;i < n; i++){
		    T[i] = T[i-1] + T[i-2];
		    if(T[i] % 2 == 0)
			    sum = sum + T[i];
	    }
	    cout << sum;
	}	
		cout<<endl;
        break;

    case 7:
    	{
		
	    int T[n];
	    for(int i = 0;i < n; i++){
		    if(i % 2 == 0){
			    T[i] = i * 2;
		    }
		    else{
			    T[i] = i - 1;
		    }
		    cout << T[i] << endl;
	    }
	}
		cout<<endl;
        break;

    case 8:
    	{
		
        m=0;
	    int silnia = 1;
	    cout <<"podaj n: ", cin >> m;
	    for(unsigned int i = m; i > 1; i--){
		    silnia = silnia * i;
	    }
	    cout << silnia;
	}
		cout<<endl;
        break;

    case 9:
    	{
		
	    int T[n]; 
	    int max = 0;
	
	    for(int i = 0;i < n; ++i){
		    cout << "podaj wartosc: ", cin >> T[i];
	    }
	    int i = 0;
	    max = T[i];
	    for(unsigned int i = 0;i < n; i++){
		    if(T[i] > max)
			    max = T[i];
	    }
	    cout << "\nmax: " << max;
	}	
		cout<<endl;
        break;

    case 10:
    	{
		
	    int T[n], max = 0;
	    for(int i = 0;i < n; i++){
		    cout << "podaj wartosc: ",cin >> T[i];
	    }
	    cout << endl;
	    unsigned int i=0;
	    max = T[i];
	    for(i = 0;i < n; i++){
		    if(T[i] > max){
			    max = T[i];
		    }
	    }
	    for(i = 0;i < n; i++){
		    if(T[i] == max)
			    cout << "index max: " << i;
	    }
	}
		cout<<endl;
        break;

    case 11:
    	{
		int T[n];
		int suma, counter = 0;
		float avg = 0;
		for(unsigned int i = 0;i < n; i++){
			T[i] = i;
		}
		for(unsigned int i = 0;i < n; i++){
			if(T[i] % 2 != 0 && T[i] % 3 == 0){
				suma += T[i];
				counter++;
			}
		}
		cout << "srednia: " << suma/counter;
    	}
    	cout<<endl;
        break;

    case 12:
    	{
		
        int T[n];
        for(int i=0; i<n; i++){
            if(i%2==0){
                T[i]={2};
            }
            else{
                T[i]={0};
            }
            cout<<T[i]<<" ";
        }
        cout<<endl;
    }
    	cout<<endl;
        break;
	case 0:
		exit(1);
		break;
	
	default:
		cout<<"zostaly wprowadzone bledne dane\n\n\n";
    }
}
    return 0;
}
