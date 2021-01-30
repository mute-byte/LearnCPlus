#include <stdio.h>
#include <stack>
#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_map>
#include <unordered_map>
#include "solution.h"
using namespace std;



int main(){
    string Original{"caaaabd"};
    string Pattern{"aaaab"};
    vector<int> Preix(Pattern.size(),0);

    PublicPrefix(Pattern, Preix );
    vector<int> Next(Preix.size(),-1);
    for (int i = 1; i < Preix.size(); i++)
    {
        Next[i] = Preix[i-1];
    }
    for(auto c:Next)
    {
        cout<<c<<endl;
    }
    cout<<"find:"<<KmpSearch(Original, Pattern, Next)<<endl;


    return 0;
}