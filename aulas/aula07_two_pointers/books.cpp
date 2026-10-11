#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
typedef long long ll;

bool many_cases = false;

void solve(){
  int n, t; cin >> n >> t;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin >> v[i];
  
  int s = 0;
  ll soma = 0;
  int ans = 0;

  for (int f = 0; f < v.size(); f++) {
      soma += v[f];

      while (soma > t) {
          soma -= v[s];
          s++;
      }

      ans = max(ans, f - s + 1);
  }

  cout << ans;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  ll t =1;
  if(many_cases) cin >> t;
  while(t--) solve();

  return 0;
}