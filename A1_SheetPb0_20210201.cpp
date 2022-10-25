#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<sstream>

using namespace std ;

string space_correctness(string str)
{
    if(islower(str[0])){
      str[0] =  toupper(str[0]) ;
    }
   
   string temp ;
   stringstream ss ;
   ss << str;
   str = "";
 
    
    while (!ss.eof()) {
        ss >> temp ;
        str = str + temp + ' ';
    }
    return str;
  
}

int main(){

  string input ;
  cout << "Enter the scentence you need to correct " << endl ;
  getline(cin,input) ;
  cout << space_correctness(input) ;
  


}