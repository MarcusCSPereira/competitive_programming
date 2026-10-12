#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define FOR(i,a,b,c) for (int i =a; i<b; i += c)
typedef long long ll;

bool many_cases = true;

void solve(){
  pair<ll,ll> x, y;
  cin >> x.first >> y.first;
  cin >> x.second >> y.second;

  if(y.second < y.first){
    cout << -1 << endl;
    return;
  }

  if(x.first < x.second && y.second - y.first < x.second - x.first){
    cout << -1 << endl;
    return;
  }

  ll ry = y.second - y.first;
  ll rx = abs((x.first + ry) - x.second);

  cout << ry+rx << endl;

}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}