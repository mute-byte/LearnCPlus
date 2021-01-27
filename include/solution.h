#include <stack>
#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
double myPow(double x, int n); 
vector<int> printNumbers(int n); 
ListNode* deleteNode(ListNode* head, int val);
void printNumbers1(int n, string& Tem);
bool isNumber(string s);
vector<int> exchange(vector<int>& nums);
