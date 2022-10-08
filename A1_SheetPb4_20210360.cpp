#include <bits/stdc++.h>
using namespace std;

void check(int n){
    if (n<0){
        cout << "Error- Invalid Input" << endl;
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
    int n; cin >> n;
    if (n==0){cout << 0;}
    //check(n);
    binaryPrint(n);
    cout << endl;
    numbers("00101",2);
    return 0;
}
