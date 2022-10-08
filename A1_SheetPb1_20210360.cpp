#include <bits/stdc++.h>
//#include <algorithm>
using namespace std;

string replace_he(string& s, string from,  string to){
    size_t place = s.find("He");
    size_t place2 = s.find("he");
    if(place != string::npos){
        s.replace(place, from.size(), to);
    }
    else if (place2 != string::npos){
        s.replace(place2, from.size(), to);
    }
    return s;
}

string replace_him(string& s, string from,  string to){
    size_t place = s.find("Him");
    size_t place2 = s.find("him");
    if(place != string::npos){
        s.replace(place, from.size(), to);
    }
    else if (place2 != string::npos){
        s.replace(place2, from.size(), to);
    }
    return s;
}

string replace_his(string& s, string from,  string to){
    size_t place = s.find("His");
    size_t place2 = s.find("his");
    if(place != string::npos){
        s.replace(place, from.size(), to);
    }
    else if (place2 != string::npos){
        s.replace(place2, from.size(), to);
    }
    return s;
}

string replace_himself(string& s, string from,  string to){
    size_t place = s.find("Himself");
    size_t place2 = s.find("himself");
    if(place != string::npos){
        s.replace(place, from.size(), to);
    }
    else if (place2 != string::npos){
        s.replace(place2, from.size(), to);
    }
    return s;
}

int main()
{
    string s,she = "he and she", her="him and her", hers="his and hers ", herself="himself and herself";
    getline(cin, s);
    replace_he(s,"he",she); replace_him(s,"him",her);   replace_his(s,"his ", hers);    replace_himself(s,"himself",herself);
    cout << s;
    return 0;
}
