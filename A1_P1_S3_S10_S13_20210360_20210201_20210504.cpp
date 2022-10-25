#include <bits/stdc++.h>
using namespace std;

class BigDecimalInt
{
    string strBigInt;
    int num;

public:
    // constructors
    BigDecimalInt();
    BigDecimalInt(string decStr);
    BigDecimalInt(int decInt);

    /*** Operator Overloading ***/
    BigDecimalInt operator+(BigDecimalInt anotherDec);
    BigDecimalInt operator-(BigDecimalInt anotherDec);
    bool operator<(BigDecimalInt anotherDec);
    bool operator>(BigDecimalInt anotherDec);
    bool operator==(BigDecimalInt anotherDec);
    BigDecimalInt operator=(BigDecimalInt anotherDec);

    int size();
    int sign();
    friend ostream &operator<<(ostream &out, BigDecimalInt &ob);
};

/*  __________ implementaion ________*/
//  (Abdulrahman)
BigDecimalInt ::BigDecimalInt()
{
    strBigInt = "";
}

BigDecimalInt ::BigDecimalInt(int decInt)
{
    num = decInt;
}

BigDecimalInt ::BigDecimalInt(string decStr)
{
    regex filter("(-?|\\+)[0-9]+");

    if (regex_match(decStr, filter))
    {
        strBigInt = decStr;
        if (strBigInt[0] == '+')
        {
            strBigInt.erase(strBigInt.begin());
        }
    }
    else
    {
        cout << "try valid num " << endl;
    }
}

// operator +
BigDecimalInt BigDecimalInt ::operator+(BigDecimalInt anotherDec)
{
    BigDecimalInt temp;
    string str1 = strBigInt, res = "";
    string str2 = anotherDec.strBigInt;

    // str2 should be larger than str1
    if (str1.length() > str2.length())
    {
        swap(str1, str2);
    }

    int len1 = str1.size(), len2 = str2.size();
    int diff = len2 - len1;
    str1.insert(str1.begin(), diff, ' ');

    int carry = 0, i = len2 - 1;
    while (len1--)
    {
        int sum = (str2[i] - '0') + (str1[i] - '0') + carry;
        res.push_back(sum % 10 + '0');
        carry = sum / 10;
        i--;
    }
    while (i >= 0)
    {
        int sum = (str2[i] - '0') + carry;
        res.push_back(sum % 10 + '0');
        carry = sum / 10;
        i--;
    }

    if (carry)
    {
        res.push_back(carry + '0');
    }

    reverse(res.begin(), res.end());
    temp.strBigInt = res;
    return temp;
}
//************************* (Mohamed)
// Operator -
BigDecimalInt BigDecimalInt ::operator-(BigDecimalInt anotherDec)
{
    if (strBigInt < anotherDec.strBigInt)
    {
        swap(strBigInt, anotherDec.strBigInt);
    }
    BigDecimalInt result;
    int carry = 0, diff = strBigInt.size() - anotherDec.strBigInt.size();
    // sub. the digits from right (H2H).
    for (int i = anotherDec.strBigInt.size() - 1; i >= 0; i--)
    {
        int step = ((strBigInt[i + diff] - '0') - (anotherDec.strBigInt[i] - '0') - carry);
        if (step < 0)
        { // There will be a carry
            step += 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        result.strBigInt += (step + '0');
    } // sub. the remining from bigger string (ALONE).
    for (int i = diff - 1; i >= 0; i--)
    {
        if (strBigInt[i] == '0' && carry != 0)
        {
            result.strBigInt += '9';
            continue;
        }
        int step = ((strBigInt[i] - '0') - carry);
        if (i > 0 || step > 0)
        {
            result.strBigInt += step + '0';
        }
        carry = 0;
    }
    reverse(result.strBigInt.begin(), result.strBigInt.end());
    return result;
}

// Operator <
bool BigDecimalInt ::operator<(BigDecimalInt anotherDec)
{
    // +    +
    if ((strBigInt[0] == '+' || isdigit(strBigInt[0])) && (anotherDec.strBigInt[0] == '+' || isdigit(anotherDec.strBigInt[0])))
    {
        if (strBigInt.size() < anotherDec.strBigInt.size())
        {
            return true;
        }
        else if (strBigInt.size() == anotherDec.strBigInt.size())
        {
            for (int i = 0; i < strBigInt.size(); i++)
            {
                if (strBigInt[i] < anotherDec.strBigInt[i])
                {
                    return true;
                }
            }
        }
    }
    //  -   -
    else if (strBigInt[0] == '-' && anotherDec.strBigInt[0] == '-')
    {
        if (strBigInt.length() > anotherDec.strBigInt.length())
        {
            return true;
        }
        else if (strBigInt.length() == anotherDec.strBigInt.length())
        {
            for (int i = 1; i < strBigInt.size(); i++)
            {
                if (strBigInt[i] < anotherDec.strBigInt[i])
                {
                    return true;
                }
            }
        }
    }
    //  -   +
    else if (strBigInt[0] == '-' && (anotherDec.strBigInt[0] == '+' || isdigit(anotherDec.strBigInt[0])))
    {
        return true;
    }
    //  +   - and opposite conditions
    else
    {
        return false;
    }
}
//********************************** (Abdelhalim)
//  Operator >
bool BigDecimalInt ::operator>(BigDecimalInt anotherDec)
{
    // +    +
    if ((strBigInt[0] == '+' || isdigit(strBigInt[0])) && (anotherDec.strBigInt[0] == '+' || isdigit(anotherDec.strBigInt[0])))
    {
        if (strBigInt.size() > anotherDec.strBigInt.size())
        {
            return true;
        }
        else if (strBigInt.size() == anotherDec.strBigInt.size())
        {
            for (int i = 0; i < strBigInt.size(); i++)
            {
                if (strBigInt[i] > anotherDec.strBigInt[i])
                {
                    return true;
                }
            }
        }
    }
    //  -   -
    else if (strBigInt[0] == '-' && anotherDec.strBigInt[0] == '-')
    {
        if (strBigInt.length() < anotherDec.strBigInt.length())
        {
            return true;
        }
        else if (strBigInt.length() == anotherDec.strBigInt.length())
        {
            for (int i = 1; i < strBigInt.size(); i++)
            {
                if (strBigInt[i] < anotherDec.strBigInt[i])
                {
                    return true;
                }
            }
        }
    }
    //  +   -
    else if (anotherDec.strBigInt[0] == '-' && (strBigInt[0] == '+' || isdigit(strBigInt[0])))
    {
        return true;
    }
    //  -   + and opposite conditions
    else
    {
        return false;
    }
}

// Operator ==
bool BigDecimalInt ::operator==(BigDecimalInt anotherDec)
{
    if (strBigInt.length() != anotherDec.strBigInt.length())
        return false;
    for (int i{}; i < strBigInt.length(); i++)
    {
        if (strBigInt[i] != anotherDec.strBigInt[i])
            return false;
    }
    return true;
}

// Operator =
BigDecimalInt BigDecimalInt ::operator=(BigDecimalInt anotherDec)
{
    BigDecimalInt temp;
    strBigInt = anotherDec.strBigInt;
    return temp;
}

// size
int BigDecimalInt ::size()
{
    return strBigInt.length();
}

// Sign
int BigDecimalInt ::sign()
{
    if (strBigInt[0] == '-')
    {
        return -1;
    }
    return 1;
}

// operator <<
ostream &operator<<(ostream &out, BigDecimalInt &ob)
{
    out << ob.strBigInt << endl;
    return out;
}

int main()
{
    BigDecimalInt num1("123456789012345678901234567890"), num2("113456789011345678901134567890"), num3("-200000000000000000000000000000");
    if (num3 < num1)
    {
        cout << "True\n";
    }
    else
    {
        cout << "False\n";
    }
    if (num2 > num1)
    {
        cout << "True\n";
    }
    else
    {
        cout << "False\n";
    }
    BigDecimalInt num4 = num2;
    cout << num4;
    if (num4 == num2)
    {
        cout << "True\n";
    }
    else
    {
        cout << "False\n";
    }
    BigDecimalInt num5 = num1 - num4; // 10,000,000,001,000,000,000,100,000,000
    cout << num5;
    BigDecimalInt num6 = num1 + num2; // 236,913,578,023,691,357,802,369,135,780
    cout << num6;
    cout << num3.sign() << endl;
    cout << num6.size() << endl;
    return 0;
}
