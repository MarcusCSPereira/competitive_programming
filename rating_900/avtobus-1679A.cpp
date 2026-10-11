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
  long long n;
  cin >> n;
  if (n % 2 != 0 || n < 4) {
      cout << -1 << "\n";
  } else {
      long long min_buses = (n + 5) / 6;
      
      long long max_buses = n / 4;
      
      cout << min_buses << " " << max_buses << "\n";
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}