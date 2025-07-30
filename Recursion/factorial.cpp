#include<bits/stdc++.h>
using namespace std;

int fac(int n){
   if(n==1)return 1;

   int ans=fac(n-1)*n;
   return ans;
}

int main(){
    cout<<fac(5)<<endl;
    return 0;
}