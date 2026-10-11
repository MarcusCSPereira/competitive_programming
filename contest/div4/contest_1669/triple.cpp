#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define FOR(i,a,op,b,c) for (int i =a; i op b; i += c)
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
typedef long long ll;

bool many_cases = true;

void solve(){
  int n; cin >> n;
  map<int,int> mp;
  for(int i=0;i<n;i++){
    int x; cin >> x;
    if(mp[x]) mp[x]++;
    else mp[x] = 1;
  }
  if (n < 3){cout << "-1" << endl; return;}
  for(auto p:mp){
    if(p.second >= 3){ cout << p.first << endl; return;}
  }

  cout << "-1" << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}