#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>

using namespace std ; 
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define Yes cout << "YES" << endl;
#define No cout << "NO" << endl;

bool compare(const pair<string,int> &a,const pair<string,int> &b)
{
       return a.second > b.second;
}

vector<pair<string,int>> addPlayer(vector<pair<string,int>> & v )
{ 
    
    string name ;
    int n, score ;
    cout << "Enter number of players " << endl;
    cin >> n ;
    cout << "enter name of player and his Score respectively " << endl ;

    while (n--)
    {
     cin >> name >> score ;
     v.push_back(make_pair(name,score));    
    }

    sort(v.begin(),v.end(),compare);
    return v ;
    

}

void display_Top_10(vector<pair<string,int>> v)
{ 
    cout << "Top 10" << endl ;
    for (int i = 0; i < 10 ; i++)
    {
        cout  << v[i].first << ' ' << v[i].second << endl ;     
    }
    
}

void get_highest_score(vector<pair<string,int>> v)
{
  multimap <string,int> mp;
  for (int i = 0; i < 10 ; i++){
    mp.insert(make_pair(v[i].first , v[i].second));
  }
  string name ;
  cout << "enter player name " << endl ;
  cin >> name ;
  
  auto it = mp.find(name);
  if (it != mp.end())
  {
    cout << it->second << endl ;
    return ;
  }

  for (int i = 10; i < v.size(); i++)
  {
    if(name == v[i].first){
       cout << "Name not in top 10 "<< endl ;
       return ;
    }
  }
  
 cout << "Name not in list " << endl ;
  

  
}

int main()
{
	fast 
    vector<pair<string,int>> table ;
    int choice = 0 ;
	cout << "Choose the Operation you want by pressing button " << endl ;
    cout << "Add player -> Press 1 " << endl ;
    cout << "display top 10 Standings -> Press 2 " << endl ;
    cout << "Select player to see his highest score -> 3 " << endl ;
    cout << "TO EXIT -> Press 0  " << endl ;
    

	while (true)
    {
        cout << "enter choice :- " << endl ;
        cin >> choice ;
        
        if(choice == 1){
         addPlayer(table);
        }
        else if(choice == 2){
          display_Top_10(table);
        }
        else if(choice == 3){
           get_highest_score(table);
        }
        else if(choice == 0){
            break;
        }
    }
    
  
	
	return 0;
}