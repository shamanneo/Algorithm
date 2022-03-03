#include <iostream>
#include <vector> 
#include <algorithm>
#include <map>
#include <cmath> 

using namespace std ;
int GetMod(map<int, int> &m)
{
    vector<pair<int, int>> v_rev ;
    vector<pair<int, int>> v_mod ;
    for(auto it = m.begin() ; it != m.end() ; it++)
    {
        v_rev.emplace_back(pair<int, int> { it->second, it->first } ) ; 
    }
    sort(v_rev.begin(), v_rev.end()) ; 
    int max_count = v_rev.rbegin()->first ; 
    for(auto it = v_rev.begin() ; it != v_rev.end() ; it++)
    {
       if(it->first == max_count)
       {
           v_mod.emplace_back(pair<int, int> { it->second, it->first } ) ; 
       }
    }
    sort(v_mod.begin(), v_mod.end()) ; 
    if(v_mod.size() == 1)
    {
        return v_mod[0].first ; 
    }
    return v_mod[1].first ; 
}

int main()
{
    double avg = 0 ;
    int mid = 0 ;
    int rag = 0 ; 
    map<int, int> m ; 
    vector<int> v ; 
    int N = 0 ; 
    int in = 0 ; 
    cin >> N ; 

    for(int i = 0 ; i < N ; i++)
    {
        cin >> in ;
        v.push_back(in) ; 
        auto it = m.find(in) ; 
        if(it == m.end()) // not exist
        {
            m.insert(pair<int, int> { in, 1 } ) ;
        }
        else
        {
            it->second++ ; 
        }
    }
    sort(v.begin(), v.end()) ; 
    double sum = 0 ; 
    for(auto i : v)
    {
        sum += i ; 
    }
    avg = round(sum / N) ; 
    if(avg == -0)
    {
        avg = 0 ; 
    }
    mid = v[N / 2] ; 
    rag = v[N - 1] - v[0] ; 

    cout << avg << '\n' ;  
    cout << mid << '\n' ; 
    cout << GetMod(m) << '\n' ;  
    cout << rag << '\n' ;
    return 0 ;     
}
