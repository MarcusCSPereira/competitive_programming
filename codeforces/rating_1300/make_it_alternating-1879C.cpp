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
  string s; cin >> s;
  ll ans = 1;
  ll op = 0;
  ll count = 1;
  for(int i=1; i< s.size();i++){
    if(s[i] == s[i-1]){
      count++;
      op++;
    }else{
      ans = ans * count % 998244353;
      count = 1;
    }
  }

  ans = ans * count % 998244353;
  ll fat = 1;
  for (int i = 2; i <= op; i++) {
    fat = fat * i % 998244353;
  }

  cout << op << " " << ans * fat % 998244353 << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}