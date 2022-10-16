#include <bits/stdc++.h>
using namespace std;

class BigDecimalInt{
    string strBigInt;
public:
    BigDecimalInt(){
        cout << "There is no values." << endl;
        strBigInt = "";
    }
    BigDecimalInt(string x){
        int i = 0;
        if (x[i]=='+' && x[i+1]=='-' || x[i]=='+' && x[i+1]==' ' || x[i]=='-' && x[i+1]==' '){
            cout << "The value is unvalid." << endl;
            strBigInt = "";
        }else {
            cout << "The value is valid." << endl;
            strBigInt = x;
        }
    }
// Operator - 
    BigDecimalInt operator-(BigDecimalInt n2){
        BigDecimalInt n3;
        //  +   +
        if (strBigInt[0]=='+' && n2.strBigInt[0]=='+' || isdigit(strBigInt[0]) || isdigit(n2.strBigInt[0])){
            if (strBigInt.size() > n2.strBigInt.size()){        // if the size of 2strings aren't equal=> we add 0 in the begging of the less string.
                while (n2.strBigInt.size() != strBigInt.size()){
                    n2.strBigInt.insert(0,"0");
                }
            }else {
                while (strBigInt.size() != n2.strBigInt.size()){
                    strBigInt.insert(0,"0");
                }
            }
        }
        // -    -
        else if (strBigInt[0]=='-' && n2.strBigInt[0]=='-'){
            if (strBigInt.size() > n2.strBigInt.size()){        // if the size of 2strings aren't equal=> we add 0 in the begging of the less string.
                while (n2.strBigInt.size() != strBigInt.size()){
                    n2.strBigInt.insert(1,"0");
                }
            }else {
                while (strBigInt.size() != n2.strBigInt.size()){
                    strBigInt.insert(1,"0");
                }
            }
        }
        for (int i=strBigInt.size()-1; i>=0; i--){
            n3.strBigInt += char((strBigInt[i] - n2.strBigInt[i])+'0');
        }reverse(n3.strBigInt.begin(), n3.strBigInt.end());
        if (strBigInt[0]=='-' && n2.strBigInt[0]=='-'){n3.strBigInt[0]='-';}
        return n3;
    }
    // Operator -
    bool operator<(BigDecimalInt n2){
        // +    +
        if (strBigInt[0]=='+' && n2.strBigInt[0]=='+' || isdigit(strBigInt[0]) || isdigit(n2.strBigInt[0])){
            if (strBigInt.size() < n2.strBigInt.size()){
                return true;
            }
            else if (strBigInt.size()==n2.strBigInt.size()){
                for (int i=0; i<strBigInt.size(); i++){
                    if (strBigInt[i] < n2.strBigInt[i]){
                        return true;
                    }
                }
            }
        }
        //  -   -
        else if (strBigInt[0]=='-' && n2.strBigInt[0]=='-'){
            if (strBigInt.length() > n2.strBigInt.length()){
                return true;
            }
            else if (strBigInt.length()==n2.strBigInt.length()){
                for (int i=1; i<strBigInt.size(); i++){
                    if (strBigInt[i] < n2.strBigInt[i]){
                        return true;
                    }
                }
            }
        }
        //  -   +
        else if (strBigInt[0]=='-' && n2.strBigInt[0]=='+'||isdigit(n2.strBigInt[0])){
            return true;
        }
        //  +   - and opposite conditions
        else {
            return false;
        }
    }
    void print_value(){
        cout << "YES less" << endl;
    }
};

int main()
{
    //string num1("123456789012345678901234567890"), num2("113456789011345678901134567890"), num3("-200000000000000000000000000000"), num5="", num4="",temp="";
    BigDecimalInt num("-100000000000000000000000000000");
    BigDecimalInt num2("-113456789011345678901134567890");
//    BigDecimalInt num3 = num - num2;
//    num3.print_value();
    if (num < num2){
        cout << "True";
    }else {cout << "False";}
    //236913578023691357802369135780

    return 0;
}
