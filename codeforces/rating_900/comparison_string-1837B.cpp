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
  int n; cin >> n; string s; cin >> s;
  ll max_streak =1, curr_streak = 1;
  for(int i=1;i<n;i++){
    if(s[i] == s[i-1]){
      curr_streak++;
      max_streak = max(curr_streak, max_streak);
    }else{
      curr_streak = 1;
    }
  }

  cout << max_streak + 1 << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}