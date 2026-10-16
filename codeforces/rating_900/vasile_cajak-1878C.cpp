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
  ll n, x, k; cin >> n >> k >> x;
  ll min_sum = (k * (1 + k)) / 2;
  ll max_sum = (k *(2*n +1 - k))/2;
  if(x<=max_sum && x>=min_sum){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}