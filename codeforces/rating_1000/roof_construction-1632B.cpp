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
  int n;cin >> n;
  int msb = log2(n-1);
  int min_val = pow(2,msb);
  for(int i = (min_val-1); i >=0; i--){
    cout << i << " ";
  }
  for(int i = min_val; i<n; i++){
    i == n-1 ? cout << i << endl : cout << i << " ";
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}