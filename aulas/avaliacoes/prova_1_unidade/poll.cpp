#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug (x) cout << #x << " = " << x << endl
typedef long long ll;

bool many_cases = false;

bool bs2(ll m, vector<ll> &v, ll k){return 0;}

void solve(){
  ll n; cin >> n;
  map<string, ll> mp;
  ll maxx=0;
  for(int i =0; i< n;i++){
    string x;cin>>x;
    mp[x]++;
    maxx = max(mp[x], maxx);
  }

  for(auto &[k,v] : mp){
    if (v == maxx) cout << k << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}