#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
typedef long long ll;

bool many_cases = false;

bool bs2(ll m, vector<ll> &v, ll k){return 0;}

void solve(){
  ll n; cin >> n;
  vector<string> v(n);
  map<string, ll> mp;
  for(int i =0;i<n;i++){
    string x;cin>>x;
    v[i] = x;
  }

  for(ll i=v.size()-1;i>=0;i--){
    if(mp[v[i]]) continue;
    else{
      mp[v[i]]++;
      cout << v[i] << endl;
    } 
  }


}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}