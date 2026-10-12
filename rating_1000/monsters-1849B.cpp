#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
//typedef __int128 i128;

bool many_cases = true;

void solve(){
  ll n, k; cin >> n >> k;
  vector<pair<ll,ll>> life(n);
  for(int i=0; i<n; i++){
    ll x; cin >> x;
    if(x%k == 0){
      life[i].first = -k;
      life[i].second = i+1;
    }else{
      life[i].first = -(x%k);
      life[i].second = i+1;
    }
  }

  sort(life.begin(), life.end());
  for(auto it : life){
    cout << it.second << " ";
  }
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}