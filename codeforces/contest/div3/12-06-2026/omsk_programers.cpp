#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define FOR(i,a,op,b,c) for (int i =a; i op b; i += c)
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
typedef long long ll;

bool many_cases = true;

void solve(){
  ll a,b,x; cin >> a >> b >> x;
  ll ops = 0;
  ll ans = abs(a-b);
  if (ans == 0 || ans == 1){
    cout << ans << endl;
    return;
  }
  while(a > 0 || b > 0){
    if(a >= b){
      a/=x;
      ops++;
    }else{
      b/=x;
      ops++;
    }

    ans = min(ans, (abs(a-b) + ops));

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