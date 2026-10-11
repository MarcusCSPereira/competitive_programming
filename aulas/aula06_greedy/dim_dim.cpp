#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl
#define endl "\n"
typedef long long ll;

void solve(){
  ll n; cin >> n;
  vector<int> c {1, 2, 5, 10, 20, 50, 100, 200};
  ll ans = 0;
  for(int i = c.size()-1;i>=0;i--){
    ans += n/c[i];
    n = n%c[i];
    if (n==0) break;
  }
  cout << ans << endl;

}

bool many_cases = false;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);

  ll t=1;
  if(many_cases) cin >> t;
  while(t--) solve();

  return 0;
}