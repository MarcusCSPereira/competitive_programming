#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define FOR(i,a,op,b,c) for (int i =a; i op b; i += c)
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
typedef long long ll;

bool many_cases = false;

void solve(){
  READVEC(n, x, ll, ll);
  READVEC(q, m, ll, ll);

  sort(x.begin(),x.end());
  FOR(i,0,<,q,1){
    ll ans = upper_bound(x.begin(),x.end(),m[i]) - x.begin();
    cout << ans << endl;
  }

}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}