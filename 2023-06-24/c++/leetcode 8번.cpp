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

// ���ù��� �򰥷��� �� �����ɷȴ�. ����� �� �׷���..
// ���� ���� ������ �ڵ�� �����ϱ� �ѵ�, ��� �պκ� ����� ����, ���ڳ������� ���̰�, ���� ������ ���ڷ� �ٲٰ�, �ڿ� ���� �ƴѰ� ������ �ڸ��� ��.
// ��ȣ��������, �� ���� ���� (1��)�� �ٷ� ���� �տ� ���� ���̽��� �װ� �ݿ��ϸ� �ǰ�, �ƴϸ� ���ڳ��� ���̴ϱ� ���ϸ� ��