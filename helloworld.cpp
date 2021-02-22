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

    vector<int> test{49,38,65,97,76,13,27,49,55,4};
    MergeSort(test,0,test.size()-1);
    for (auto i : test)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}