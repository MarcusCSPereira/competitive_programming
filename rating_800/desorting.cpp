#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
//typedef __int128 i128;
const int tam_limit = 1e5 + 1;
const ll LLMAX = LONG_LONG_MAX;
const ll LLMIN = LONG_LONG_MIN;

bool many_cases = true;

void solve(){
  READVEC(n, v, ll, ll);
  vector<ll> cp_v = v;
  sort(v.begin(),v.end());
  if (cp_v != v){
    COUT(0);
  }
  ll men_dif = LLMAX;
  for(int i=1;i<n;i++){
    men_dif = min(abs(v[i] - v[i-1]),men_dif);
  }

  cout << (men_dif/2) + 1 << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}