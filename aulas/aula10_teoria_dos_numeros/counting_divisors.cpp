#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
typedef long long ll;


bool many_cases = true;

void solve(){
  int n; cin >> n;
  int count = 0;

  for(int i = 1; i * i <= n; i++){
    if(n % i == 0){
      if(i == n/i) count++;
      else count +=2;
    }

  }

  cout << count << "\n";
}


int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}
