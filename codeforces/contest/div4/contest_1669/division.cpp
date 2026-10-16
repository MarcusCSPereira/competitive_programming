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
  if(n >= 1900){
    cout << "Division 1" << endl;
    return;
  }else if(n >= 1600){
    cout << "Division 2" << endl;
    return;
  }else if(n >= 1400){
    cout << "Division 3" << endl;
    return;
  }else{
    cout <<  "Division 4" << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}