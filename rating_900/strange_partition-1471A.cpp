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
  ll n, x; cin >> n >> x;
  ll ans_min=0, ans_max=0;
  for(ll i=0;i<n;i++){
    ll a; cin >> a;
    ans_min+=a;
    ans_max+= (a+x-1)/x;
  }
  cout << (ans_min+x-1)/x << " " << ans_max << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}