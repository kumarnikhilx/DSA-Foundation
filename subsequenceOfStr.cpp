#include<bits/stdc++.h>
using namespace std;

void subsequenceOfStr(int index,string str,vector<char> &ds,vector<vector<char>> &ans){
    if(index>=str.length()){
        ans.push_back(ds); //here rather than storing the ds in ans we directly print the all elementof ds;
        return;
    }

    //include then exclue so, while backtracking remember to pop_back the element which push_back;
    // ds.push_back(str[index]);
    // subsequenceOfStr(index+1,str,ds,ans);
    // ds.pop_back();
    // subsequenceOfStr(index+1,str,ds,ans);
    
    //first,exclude then include;
    subsequenceOfStr(index+1,str,ds,ans);
    ds.push_back(str[index]);
    subsequenceOfStr(index+1,str,ds,ans);
    ds.pop_back();





}

int main(){
    string str="abc";
    vector<char>ds;
    vector<vector<char>> ans;
    subsequenceOfStr(0,str,ds,ans);

    for(int i = 0; i < ans.size(); ++i) {
        cout<<"["<<"";
    for(int j = 0; j < ans[i].size(); ++j) {
        cout << ans[i][j] ;
    }
      cout<<"]"<<" ";
    cout << endl;
}

}