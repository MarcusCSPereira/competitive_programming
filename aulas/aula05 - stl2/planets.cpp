#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);

  ll t;cin >> t;
  while(t--){
    ll n, c; cin >> n >> c;
    vector<ll> v(n);
    map<ll,ll> mp;
    for(int i=0;i< n ;i++){
      cin >> v[i];
      mp[v[i]] +=1;
    }
    ll cost=0;
    for (auto &[k,v] : mp){
      if(mp[k] >= c){
        cost += c;
      }else{
        cost += mp[k];
      }
    }

    cout << cost << endl;

  }

  return 0;
}