#include <bits/stdc++.h>
using namespace std;

bool bears(int n){
    int temp = (n%10)*((n/10)%10);
    if (n == 42){
        return true;
    }else if (n < 42){
        return false;
    }else if (n%2==0 && bears(n/2)){
        return true;
    }else if (n%5==0 && bears(n - 42)){
        return true;
    }else if (temp>0 && n%3==0||n%4==0 && bears(n - temp)){
        return true;
    }
    return false;
}

int main()
{
    cout << "Enter number : ";
    int n; cin >> n;
    bears(n);
    if (bears(n)==true){
        cout << '(' << n << ')' << " is True";
    }else {
        cout << '(' << n << ')' << " is False";
    }
    return 0;
}
