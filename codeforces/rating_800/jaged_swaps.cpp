#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << x << endl
typedef long long ll;

bool many_cases = true;

void solve(){
  ll n; cin >> n;
  vector<ll> v(n);
  ll men = LLONG_MAX;
  ll indx;
  for(int i=0;i<n;i++){
    cin >> v[i];
    if (v[i] <= men) {men = v[i]; indx = i;}
  }
  indx == 0LL ? cout << "YES" << endl : cout << "NO" << endl;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll t=1; if (many_cases) cin >> t;
  while(t--) solve();
  return 0;
}