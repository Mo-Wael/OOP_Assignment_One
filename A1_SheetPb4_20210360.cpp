#include <bits/stdc++.h>
using namespace std;

bool check(int n){
    if (n<0){
        cout << "Error- Invalid Input" << endl;
        return false;
    }else if (n==0){
        cout << 0;
    }
}

void binaryPrint(int n){
    if (n==0){
        return ;
    }else{
        binaryPrint(n/2);
        cout << n%2;
    }
}

void numbers(string prefix, int k){
    if (k==0){
        cout << prefix << endl;
    }
    else {
        numbers(prefix+"0", k-1);
        numbers(prefix+"1", k-1);
    }
}

int main()
{
    while (true)
    {
        cout << "Enter 1 for (One Binary Number) OR 2 for (Printing Many Numbers) OR 0 to end : ";
        int choice; cin >> choice;
        if (choice==0){
            cout << "Thanks for using.";
            break;
        }else if (choice==1){
            cout << "Enter positive number to convert : ";
            int n; cin >> n;
            if (!check(n)){continue;}
            else{binaryPrint(n);}
            cout << endl;
        }else if (choice==2){
            cout << "Enter a string with 5-digits and an integer to print all possible values : ";
            //numbers("00101",2);       // Main_Case
            string s; cin >> s;
            int m; cin >> m;
            numbers(s,m);
            cout << endl;
        }
    }
    return 0;
}
