#include "solution.h"
      double myPow(double x, int n) 
      {
        if (x == 0)
        {
            return 0;
        }
        double res = 1;
        long long Tem = n;
        if (Tem < 0)
        {
            Tem = -Tem;
            x = 1 / x;
        }
        while (Tem != 0)
        {
            if (Tem % 2 == 1)
            {
                res = res * x;
            }
            x *=x;
            Tem = Tem / 2;
        }
        return res;   
    }
    vector<int> printNumbers(int n) {
        int a=(int)pow(10,n);
        vector<int> Res;
        for (int i = 1; i < a; i++)
        {
            Res.push_back(i);
        }
        return Res;    
    }

    ListNode* deleteNode(ListNode* head, int val) {
            if (head == nullptr)
            {
                return head;
            }
            if (head->val == val)
            {
                return head->next;
            }
            ListNode* Tem = head;
            while (Tem->next != nullptr)
            {
                if (Tem->next->val == val)
                {
                    Tem->next = Tem->next->next;
                    break;
                }
                else
                {
                    Tem = Tem->next;
                }    
            }
            return head;
    }        
    void printNumbers1(int n, string& Tem) {
        if (n == 0)
        {
            cout<<Tem<<endl;
            return;
        }
        for (int i = 0; i <= 9; i++)
        {
            if (i == 0 && Tem.empty())
            {
                continue;
            }
            else
            {
                if (Tem.front() == '0')
                {
                    Tem.erase(0,1);
                }
                Tem.push_back(i + '0');
                printNumbers1(n - 1, Tem);
                Tem.pop_back();
            }    
        }        
    }
    /*请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"-1E-16"、
    "0123"都表示数值，但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。
    */
    bool isNumber(string s) {
        unordered_map<int, unordered_map<char, int>> transfer
        {
            //d数字， s符号，e e或者E；
            {0,{{' ', 0},{'s', 1},{'d', 2},{'.', 4}}}, //0. start with 'blank'
            {1,{{'d', 2},{'.', 4}}},                   //1. 'sign' before 'e'
            {2,{{'d', 2},{'.', 3},{'e', 5},{' ', 8}}}, //2. 'digit' before 'dot'
            {3,{{'d', 3},{'e', 5},{' ', 8}}},          //3. 'digit' after 'dot'
            {4,{{'d', 3}}},                            //4. 'digit' after 'dot' (‘blank’ before 'dot')
            {5,{{'s', 6},{'d', 7}}},                   //5. 'e'
            {6,{{'d', 7}}},                            //6. 'sign' after 'e'
            {7,{{'d', 7},{' ', 8}}},                   //7. 'digit' after 'e'
            {8,{{' ', 8}}}                             //8. end with 'blank'
        };
        int state = 0;
        for (unsigned int i = 0; i < s.length(); i++)
        {
            char t;
            if('0' <= s[i] && s[i]<= '9')
            {
                t = 'd';//digit
            }
            else if(s[i] == '+' || s[i] == '-')
            {
                t = 's';//sign
            }
            else if(s[i] == 'e' || s[i] == 'E')
            {
                t = 'e';//e or E
            }
            else if(s[i] == ' ' || s[i] == '.')
            {
                t = '.';//dot, blank
            } 
            else
            {
                t = '?';// unknown
            }
            if(transfer[state].find(t) == transfer[state].end())
            {
                return false;
            }
            else
            {
                state = transfer[state][t];
            }               
        }
        return state == 2 || state == 3 ||state == 7 ||state == 8;    
    }
    vector<int> exchange(vector<int>& nums) {
        vector<int> Res(nums);
        if (nums.empty())
        {
            return Res;
        }
        for (int i = 0, j = Res.size() - 1; i < j; i++)
        {
            if (Res[i]%2==0)
            {
               while (Res[j]%2 == 0 && i < j)
               {
                   j--;
               }
               int Tem = Res[j];
               Res[j] = Res[i];
               Res[i] = Tem;   
            }    
        }
        return Res;    
    }
    bool recure(TreeNode* A, TreeNode* B)
    {
        if (B == nullptr)
        {
            return true;
        }
        if (A == nullptr)
        {
            return false;
        }
        else
        {
            return A->val == B->val && recure(A->left, B->left) && recure(A->right, B->right);
        }    
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr)
        {
            return true;
        }
        return recure(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr)
        {
            return nullptr;
        }
        else
        {
            TreeNode* Tem = root->left;
            root->left = mirrorTree(root->right);
            root->right = mirrorTree(Tem);
        }
        return root;    
    }

void PublicPrefix(string& Pattern, vector<int>& Next)
{
    Next[0] = 0;
    int i = 1;
    int len = 0;//始终指向i之前部分的最长公共前后缀的长度
    while (i < Pattern.size())
    {
        if (Pattern[i] == Pattern[len])
        {
            len++;
            Next[i] = len;
            i++;
        }
        else
        {//len始终指向不匹配前最长公共前后缀的长度
            if (len == 0)
            {
                Next[i] = len;
                i++;
            }
            len = Pattern[len-1];
        }   
    }
}
int KmpSearch(string& Original, string& Pattern, vector<int>& Next)
{
    int i = 0;
    int j = 0;
    while (i<Original.size())
    {
        if (j == Pattern.size())
        {
            return i - j;
        }
        if (Original[i] == Pattern[j])
        {
            i++,j++;
        }
        else
        {
            j = Next[j];
            if (j == -1)
            {
                i++;
                j++;
            }
       }    
    }
    return -1;   
}
void DirectInsertionSort(vector<int> &original)
{
    for (int i = 1; i < original.size(); i++)
    {
        int tem = original[i];
        int j = i;
        while (j > 0 && tem < original[j-1])
        {
            original[j] = original[j-1];
            j--;
        }

        original[j] = tem;    
    }
    
}
void SelectSort(vector<int> &original)
{
    for (int i = 0; i < original.size(); i++)
    {
        int k=i;
        for (int j = i+1; j < original.size(); j++)
        {
            if (original[j] < original[k] )
            {
                k = j;
            }    
        }
        swap(original[k], original[i]);    
    }
    
}
void BubbleSort(vector<int>& original)
{
     for (int i = original.size() - 1; i >= 0; i--)
     {
         bool flag = false;
         for (int j = 0; j < i; j++)
         {
             if (original[j]>original[j+1])
             {
                 swap(original[j], original[j+1]);
                 flag = true;
             }    
         }
         if (flag == false)
         {
             break;
         }
         
     }
     
}
void QuickSort(vector<int>& original, int low, int high)
{
    if (low >= high)
    {
       return;
    }
    
    int i = low, j = high;
    int tem = original[low];
    while (i < j)
    {
       while (i< j && original[j] > tem)
       {
           j--;
       }
       if (i < j)
       {
           original[i] = original[j];
           i++;
       }
       while (i < j && original[i] < tem)
       {
           i++;
       }
       if (i < j)
       {
           original[j] = original[i];
           j--;
       }   
    }
    original[i] = tem;
    QuickSort(original, low, i - 1);
    QuickSort(original, i + 1, high);
    
}
void ShellSort(vector<int>& original)
{
    for (int gap = original.size()/2; gap > 0; gap/=2)
    {
        for (int i = gap; i < original.size(); i++)
        {
            int tem = original[i];
            int j = i;
            while (j >= gap && tem < original[j-gap])
            {
                original[j] = original[j-gap];
                j-=gap;
            }
            original[j] = tem;    
        }
        
    }
    
}
void Merge(vector<int>& original, int low, int mid, int high)
{
    vector<int> Left;
    vector<int> Right;
    int il, ir, im;
    for (il = low; il <= mid; il++)
    {
        Left.push_back(original[il]);
    }
    for (ir = mid+1; ir <= high; ir++)
    {
        Right.push_back(original[ir]);
    }
    im = low, ir = 0, il = 0;
    while (il < Left.size() && ir < Right.size())
    {
        if (Left[il] < Right[ir])
        {
            original[im] = Left[il];
            im++;
            il++;
        }
        else
        {
            original[im] = Right[ir];
            im ++;
            ir ++;
        }   
    }
    while (il < Left.size())
    {
        original[im] = Left[il];
        im++;
        il++;
    }
    while (ir < Right.size())
    {
        original[im] = Right[ir];
        im++;
        ir++;
    }
}
void MergeSort(vector<int>& original, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high)/2;
//        cout<<low<<"***"<<mid<<endl;
        MergeSort(original,low,mid);
//        cout<<mid+1<<"$$$"<<high<<endl;
        MergeSort(original,mid+1,high);
        Merge(original,low,mid,high);
    }
//    cout<<"low:"<<low<<"   "<<"high:"<<high<<endl;
}
#if 0
    vector<int> test{5,4,6,2,1,2};
    BubbleSort(test);
    for (auto i : test)
    {
        cout<<i<<endl;
    }
#endif	
    #if 0
    vector<vector<int>> Graph{{INT32_MAX,1,2,3,INT32_MAX,INT32_MAX},
                              {1,INT32_MAX,7,INT32_MAX,8,INT32_MAX},
                              {2,7,INT32_MAX,6,4,INT32_MAX},
                              {3,INT32_MAX,6,INT32_MAX,INT32_MAX,5},
                              {INT32_MAX,8,4,INT32_MAX,INT32_MAX,9},
                              {INT32_MAX,INT32_MAX,INT32_MAX,5,9,INT32_MAX}};

    cout<<Prim(Graph,0)<<endl;
    #endif
int Prim(vector<vector<int>>& Graph, int v0)
{
    vector<int> Cost(Graph.size(),0);
    vector<bool> Visist(Graph.size(),false);
    int v,min,sum;
    for (int i = 0; i < Graph.size(); i++)
    {
        Cost[i] = Graph[v0][i];
    }
    v=v0;
    sum=0;
    Visist[v] = true;
    for (int j = 0; j < Graph.size()-1; j++)
    {
        min=INT32_MAX;
        for (int m = 0; m < Cost.size(); m++)
        {
            if (Visist[m] == false && Cost[m] < min)
            {
                cout<<"Cost[m]:"<<Cost[m]<<"min:"<<min<<endl;
                min = Cost[m];
                v = m;
            }    
        }
        Visist[v] = true;
        sum+=min;
        for (int n = 0; n < Cost.size(); n++)
        {
            if (Visist[n] == false && Graph[v][n] < Cost[n])
            {
                Cost[n] = Graph[v][n];
            }     
        }    
    }
    return sum;
}
#if 0
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
#endif