#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
//typedef __int128 i128;

bool many_cases = false;

void solve(){
  string s; cin >> s;
  set<char> se;
  for(int i=0;i<s.size();i++){
    se.insert(s[i]);
  }
  if(se.size() % 2 ==0){
    COUT("CHAT WITH HER!");
  }else{
    COUT("IGNORE HIM!");
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}