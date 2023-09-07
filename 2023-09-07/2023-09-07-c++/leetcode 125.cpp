#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        //    string m;
        //    for (int i = 0; i < s.length(); i++)
        //    {
        //        if (!isalnum(s[i]))
        //        {
        //            s.erase(i, 1);
        //            i--;
        //        }
        //        else
        //        {
        //            s[i] = tolower(s[i]);
        //        }
        //    }
        //    int len = s.length();

        //    for (int i = 0; i < len / 2; i++)
        //    {
        //        if (s[i] != s[len - 1 - i])
        //        {
        //            return false;
        //        }
        //    }
        //    return true;
        //}

        //// 위 방법은 속도가 느림.

        int len = s.length() - 1;
        int i = 0, j = len;
        while (1)
        {
            while (i <= len && !isalnum(s[i])) i++;
            while (0 <= j && !isalnum(s[j])) j--;

            if (i > j || i > len || j < 0)
            {
                break;
            }
            else
            {
                if (tolower(s[i]) != tolower(s[j]))
                {
                    return false;
                }
            }
            i++;
            j--;
        }

        return true;

    }
};


int main()
{
    Solution S;
    bool res = S.isPalindrome("A man, a plan, a canal: Panama");
    if (res)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}