#include<bits/stdc++.h>
using namespace std;

int power(int n){
   if(n==0)return 1;

   int ans=power(n-1)*2;
   return ans;
}

int main(){
    cout<<power(10)<<endl;
    return 0;
}