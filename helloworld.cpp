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

    vector<int> test{5,4,6,2,1,2};
    BubbleSort(test);
    for (auto i : test)
    {
        cout<<i<<endl;
    }
    return 0;
}