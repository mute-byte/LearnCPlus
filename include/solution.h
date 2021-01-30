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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
double myPow(double x, int n); 
vector<int> printNumbers(int n); 
ListNode* deleteNode(ListNode* head, int val);
void printNumbers1(int n, string& Tem);
bool isNumber(string s);
vector<int> exchange(vector<int>& nums);
bool recure(TreeNode* A, TreeNode* B);
bool isSubStructure(TreeNode* A, TreeNode* B);
TreeNode* mirrorTree(TreeNode* root);
