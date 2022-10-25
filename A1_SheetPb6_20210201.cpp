#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std ;

#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
void fractal( unsigned int n, unsigned int i = 0  ){
if (n == 2){
        cout << "*\n* *\n  *\n" ; 
    }

    else{
       
        fractal( n / 2);

        for (int k = 0; k < n; k++){
            cout << "* ";
        }

        cout << endl;
        
        for (int k = 0; k <= n; k++){
            cout << ' ';
            }
        cout << '*' << endl; 
          for (int k = 0; k <= n; k++){
            cout << ' ';
            }
        cout << "* *" << endl ;
            for (int k = 0; k <= n+2; k++){
                cout << ' ';
            }
        cout << "*" << endl ;
        
        
    }
}

int main()
{
	fast 
    fractal(8 , 0)	;
	 
	return 0 ;
}