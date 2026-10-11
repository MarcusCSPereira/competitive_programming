#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t; cin >> t;
  int it = 0;
  while(it < t){
    ll n; cin >> n;
    map<ll,int> mp;

    for(int i =0 ; i<n;i++){
      ll val; cin >> val;
      if(mp[val]) mp[val] += 1;
      else mp[val] = 1;
    }
    for(auto &[k,v] : mp){
      if(v == 1) cout << "Case #" << it+1 << ": " << k << endl; 
    }
  
    it++;
  }

  return 0;
}