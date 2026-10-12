#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug (x) cout << #x << " = " << x << endl
typedef long long ll;

bool many_cases = true;

bool bs2(ll m, vector<ll> &v, ll k){return 0;}

void solve(){
  ll n; cin >> n;
  vector<ll> v(3*n);
  for(int i =0;i<v.size();i++){
    ll x;cin>>x;
    v[i] =x;
  }
  sort(v.begin(),v.end());

  ll ans = 0;
  for(int i =n;i<v.size();i+=2){
    ans += v[i];
  }

  cout << ans << endl; 
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}