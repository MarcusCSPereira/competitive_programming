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
  vector<ll> second;
  ll low_first = LLONG_MAX;
  for(int i=0; i< n; i++){
    int m; cin >>m;
    vector<ll> nums(m);
    for(int j=0;j<m;j++){
      cin >> nums[j];
    }
    sort(nums.begin(), nums.end());
    second.push_back(nums[1]);
    low_first = min(low_first, nums[0]);
  }

  sort(second.begin(), second.end());
  second[0] = 0;
  ll second_sum = accumulate(second.begin(), second.end(), 0LL);
  cout << second_sum + low_first << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}