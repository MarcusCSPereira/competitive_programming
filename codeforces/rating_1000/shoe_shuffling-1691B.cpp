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
  int n; cin >> n;
  vector<ll> students_size(n);
  vector<int> shuffle_shoes(n);
  for(int i=0; i<n; i++){
    cin >> students_size[i];
    shuffle_shoes[i] = i+1;
  }

  for(int i=0; i<n-1; i++){
    if(students_size[i] == students_size[i+1]){
      int temp = shuffle_shoes[i];
      shuffle_shoes[i] = shuffle_shoes[i+1];
      shuffle_shoes[i+1] = temp;
    }
  }

  for(int i=0; i<n; i++){
    if(shuffle_shoes[i] == i+1){
      COUT(-1);
    }
  }

  for(int i=0; i<n; i++){
    i != n-1 ? cout << shuffle_shoes[i] << " " : cout << shuffle_shoes[i] << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}