#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std ;

#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

string pattern(string outs, unsigned int n, unsigned int i) 
{
       int temp = (int) (log(n) / log(2));
       if (temp == 0) 
       {
           for (int j = 0; j < i; j++)
               outs += ' ';
           for (int j = 0; j < n; j++)
               outs += "* ";
           return outs += '\n';
       } 
       else 
       {
           outs = pattern(outs, (int) (pow(2.0, temp - 1)), i);
           for (int j = 0; j < i; j++)
               outs += ' ';
           for (int j = 0; j < n; j++)
               outs += "* ";
           outs += '\n';
           i = i + temp * 2;
           return outs = pattern(outs, (int) (pow(2.0, temp - 1)), i);
       }
}

int main() {
  
cout << pattern("", 8, 0) << endl;

return 0;
}
