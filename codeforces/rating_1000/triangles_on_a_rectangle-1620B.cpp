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
  ll w, h;cin >> w >> h;
	ll area = INT_MIN;
  for (int i = 0; i < 4; i++){
    ll k; cin >> k;
    ll first, last;

    for (int j = 0; j < k; j++){
      ll x;
      cin >> x;
      if (j == 0) first = x;
      if (j == k - 1) last = x;
    }

    ll base = last - first;
    ll height;
    if (i <= 1)
      height = h;
    else
      height = w;
    
    area = max(area, base * height);
  }

  cout << area << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}