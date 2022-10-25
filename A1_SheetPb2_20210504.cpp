#include <bits/stdc++.h>

using namespace std;

vector<string> split(string target, string delimiter);

int main()
{

    string target{"1, 2, 3, 4, 5, 6, 7, 8, 9, 10"};
    string delimiter{","};
    cout << "Kindly enter text with separator:" << endl;
    getline(cin, target);
    cout << "Kindly enter seperator:" << endl;
    getline(cin, delimiter);
    cout << "******************" << endl;
    vector<string> TextSplit = split(target, delimiter);
    bool spaced = true;
    for (int i{1}; i < TextSplit.size(); i++)
    {
        char temp{};
        temp = TextSplit[i][0];
        if (temp != ' ')
        {
            spaced = false;
            break;
        }
        else
        {
            spaced = true;
        }
    }
    if (spaced)
    {
        char choice{};
        cout << "Would you like to switch the separator from \"" << delimiter << "\" to \"" << delimiter + ' ' << "\"?" << endl;
        cin >> choice;
        cout << "******************" << endl;
        if (tolower(choice) == 'y')
        {
            delimiter = delimiter + " ";
            TextSplit = split(target, delimiter);
        }
    }
    for (int i{}; i < TextSplit.size(); i++)
    {
        cout << TextSplit[i] << endl;
    }
    cin >> target;
    cin >> target;
    cin >> target;
    cin >> target;
    return 0;
}
vector<string> split(string target, string delimiter)
{
    int temp1{}, temp2{}, DelimiterSize = delimiter.size();
    vector<string> vec1;
    temp1 = target.find(delimiter);
    if (temp1 == -1)
    {
        cout << "Error: separator not found" << endl;
        return vec1;
    }
    vec1.push_back(target.substr(0, temp1));
    temp2 = target.find(delimiter, temp1 + DelimiterSize);
    while (temp2 != -1 && temp1 != -1)
    {
        vec1.push_back(target.substr(temp1 + DelimiterSize, temp2 - temp1 - DelimiterSize));
        temp1 = temp2;
        temp2 = target.find(delimiter, temp1 + DelimiterSize);
    }
    vec1.push_back(target.substr(target.rfind(delimiter) + DelimiterSize, target.length() - 1 - target.rfind(delimiter)));
    return vec1;
}
