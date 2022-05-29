#include <iostream>
#include <cmath>
using namespace std;
typedef double** matrix;

int main(){
	const int n=5;
	double A[n][n]={{-2,0.5,-2,-3,2},{-2,-4,-5,-3,0.5},{0.5,3,2,2,0.5},{-3,2,0.5,-2,3},{-4,-5,4,0.5,-5}};
	double B[n]={4,2,-2,0.5,0.5};
	double L[n][n]={0};
	double U[n][n];
	double suma;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==j){
				U[i][j]={1};
			}
			else{
				U[i][j]={0};
			}
		}
	}
	
	for(int i=0; i<n; i++){
		L[i][0]=A[i][0];
	}
	
	for(int i=1; i<n; i++){
		U[0][i]=(A[0][i])/(L[0][0]);
	}
	
	for(int i=1; i<n; i++){
		L[i][1]=A[i][1]-L[i][0]*U[0][1];
	}
	suma=0;
	for(int j=2; j<n; j++){
		for(int i=1; i<j-1; i++){
			for(int s=1; s<n; s++){
				suma=suma+(L[i][s]*U[s][j]);	
			}
            U[i][j]=(A[i][j]-suma)/(L[i][i]);
		}
		suma=0;
		int i=1;
		for(int i=j; j<n; j++){
			for(int s=1; s<n; s++){
				suma=suma+(L[i][s]*U[s][j]);
				L[i][j]=A[i][j]-suma;
			}
		}		
	}

	
	
	
	for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout<< L[i][j]<<"\t";
			}
			cout<<endl;
		}
	
	
	
	
	
	
	
	
	
	

	
	return 0;
}
