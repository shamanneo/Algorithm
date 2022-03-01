#include <iostream>
#include <string> 
#include <unordered_map>
using namespace std ; 

unordered_map<string, string> g_arr ; 
unordered_map<string, int> g_size ; 

string root(string a)
{
    if(g_arr[a] == a)
    {
        return a ;  
    }
    return g_arr[a] = root(g_arr[a]) ; 
}

void Union(string a, string b) 
{
    string ra = root(a) ; 
    string rb = root(b) ; 
    if(ra == rb)
    {
        return ; 
    }
    g_arr[rb] = ra ; 
    g_size[ra] += g_size[rb] ; 
}

int main()
{
    cin.tie(nullptr) ;
    ios_base::sync_with_stdio(false) ; 
    string a ; 
    string b ; 
    int T = 0 ;
    cin >> T ; 
    int fc = 0 ; 
    for(int j = 0 ; j < T ; j++)
    {
        cin >> fc ; 
        g_arr.clear() ; 
        g_size.clear() ; 
        for(int i = 0 ; i < fc ; i++)
        {
            cin >> a >> b ; 
            if(g_arr.count(a) == 0)
            {
                g_arr.insert(make_pair(a, a)) ; 
                g_size.insert(make_pair(a, 1)) ; 
            }
            if(g_arr.count(b) == 0)
            {
                g_arr.insert(make_pair(b, b)) ;
                g_size.insert(make_pair(b, 1)) ; 
            }
            Union(a, b) ; 
            cout << g_size[root(a)] << '\n' ; 
        }
    }
    return 0 ; 
}

