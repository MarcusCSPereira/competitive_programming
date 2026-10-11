#include <bits/stdc++.h>
#define debug(x) cout << #x << "=" << x << endl
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);

  int n, h; cin >> n >> h;
  int arr[n];
  for(int i=0;i<n;i++){ cin >> arr[i];}

  int r = 0;
  for(int i =0;i<n;i++){
    if(arr[i] > h){
      r+=2;
    }else{
      r+=1;
    } 
  }

  cout << r;

  return 0;
}
