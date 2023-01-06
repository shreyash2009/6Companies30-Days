#include <bits/stdc++.h>
using namespace std;
//driver code
int evalRPN(vector<string>& t) {


    // we have isDigit inbuild function which can tell us whether given string char is int or not    isDigit(char)
        stack<int> s;
        for(int i=0;i<t.size();i++){
            if(t[i]=="*" || t[i]=="/"|| t[i]=="+"|| t[i]=="-"){

                if(!s.empty()){
                    int f = s.top();
                s.pop();
                int n = s.top();
                s.pop();
                int res=0;
                if(t[i]=="*"){
                     res = f*n;
                }
                else if(t[i]=="/"){
                     res = n/f;
                }
                else if(t[i]=="+"){
                    res = f+n;
                }
                else if(t[i]=="-"){
                     res = n-f;
                }
                s.push(res);
                }
                else{
                    return -1;
                }
                
            }
            else{
                int x = stoi(t[i]);
                s.push(x);
            }
        }

        return s.top();
    }
int main()
{   
    vector<string> arr={"2","1","+","3","*"};
    return evalRPN(arr);

    return 0;
}