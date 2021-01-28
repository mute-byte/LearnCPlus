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
     
