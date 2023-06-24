class Solution {
public:
    int myAtoi(string s) {
        bool digit_on = false;
        bool negpos = true;
        long long x = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (digit_on == true && !isdigit(s[i]))
            {
                break;
            }
            else if (s[i] == '+')
            {
                if (!isdigit(s[i + 1]))
                {
                    return 0;
                }
                else negpos = true;
            }
            else if (s[i] == '-')
            {
                if (!isdigit(s[i + 1]))
                {
                    return 0;
                }
                else negpos = false;
            }
            else if (!isdigit(s[i]) && !isspace(s[i])) { return 0; }
            else if (isdigit(s[i]))
            {
                digit_on = true;
                x *= 10;
                x += s[i] - 48;
            }
            long long max = INT_MAX;
            max += 1;
            if (x >= INT_MAX && negpos) return INT_MAX;
            else if (x >= max && !negpos) return INT_MIN;
        }
        if (!negpos) x *= -1;
        return x;
    }
};

// 지시문이 헷갈려서 좀 오래걸렸다. 영어라서 더 그런듯..
// 지금 조금 구현한 코드는 복잡하긴 한데, 사실 앞부분 빈공간 떼고, 문자나왔으면 컷이고, 숫자 나오면 숫자로 바꾸고, 뒤에 숫자 아닌거 나오면 자르면 됨.
// 부호같은경우는, 딱 단일 개수 (1개)로 바로 숫자 앞에 나온 케이스면 그거 반영하면 되고, 아니면 문자나온 셈이니까 컷하면 됨