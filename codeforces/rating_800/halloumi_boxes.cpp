#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;


  while(t--){
    int n, k;
    cin >> n;
    cin >> k;
    
    vector<int> arr(n);
    for(int i =0;i<n;i++){
      cin >> arr[i];
    }

    if (is_sorted(arr.begin(),arr.end()) || k>=2){
      cout << "YES" << "\n";
    }else{
      cout << "NO" << "\n";
    }

  }

  return 0;
}