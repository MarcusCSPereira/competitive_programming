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
  ll n; cin >> n;
  ll count_3=0, count_2=0;
  while(n % 3 == 0){
    n/=3;
    count_3++;
  }
  while(n % 2 == 0){
    n/=2;
    count_2++;
  }

  if(n > 1 || count_2 > count_3){
    COUT(-1);
  }else{
    cout << count_3 + (count_3-count_2) << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}