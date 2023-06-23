// leetcode 3��

//#include <set>
//
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        auto iterator = s.begin();
//        std::set<char> repeat;
//        int counter = 0;
//        int maxc = 0;
//        auto start = iterator;
//        while (*iterator)
//        {
//            if (repeat.count(*iterator))
//            {
//                if (maxc < counter)
//                {
//                    maxc = counter;
//                }
//                while (1)
//                {
//                    if (*start == *iterator)
//                    {
//                        start++;
//                        break;
//                    }
//                    else
//                    {
//                        start++;
//                    }
//                }
//                counter = iterator - start + 1;
//                repeat.clear();
//                auto temp = start;
//                while (temp != iterator)
//                {
//                    repeat.insert(*temp);
//                    temp++;
//                }
//                repeat.insert(*iterator);
//            }
//            else
//            {
//                counter++;
//                repeat.insert(*iterator);
//            }
//            iterator++;
//        }
//
//        if (maxc < counter)
//        {
//            maxc = counter;
//            counter = 0;
//        }
//
//        return maxc;
//    }
//};

// ���������� �����µ�, �ݺ��Ǵ� ���ڰ� ���� ���� �� ���꽺Ʈ�� ã��
// �ӵ�, ���� �鿡�� �������� ����

// �Ƹ�, ������ �ӵ��� ���ؼ��� dp�� Ȱ���ؾ� �ϴ°����� ����.
// �� ã�ƺ��߰ڴ�.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string::iterator it = s.begin();
        vector<char> repeat;
        int counter = 0;
        int maxc = 0;
        while (it != s.end())
        {
            int idx = -1;
            for (int i = 0; i < repeat.size(); i++)
            {
                if (repeat[i] == *it) // �̹� Ž���Ѱ��� �ߺ� ����
                {
                    idx = i;
                    break;
                }
            }
            if (idx != -1)
            {

                if (maxc < counter)
                {
                    maxc = counter;
                }
                repeat.erase(repeat.begin(), repeat.begin() + idx + 1);
                repeat.push_back(*it);
                counter = repeat.size();

            }
            else
            {
                counter++;
                repeat.push_back(*it);
            }
            it++;
        }

        if (maxc < counter)
        {
            maxc = counter;
            counter = 0;
        }

        return maxc;
    }
};

int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;

    return 0;
}
// dp ���°� �ƴϿ���. �ƹ����� dp�� ���� ������ ����.
// �׳� Ǫ�ϱ� �Ǵµ�, �ڵ带 �����ߴ��� �ӵ��� ��û ��������.
// ��Ȯ�� ������ ���� �����غ��߰ڴ�. �����ϱ�, ������ ã�°͵� string�� ��������
// ��ġ�� ���� ã�����ٰ�(find � �̻��), repeat�� Ŭ�����ϰ� �ٽ� �ű⼭���� s�� �� �ܾ ���Ҹ� ����־�, �������� �ð��� �Կ��µ�
// ������ set ��� vector ���, �׸� ���� Ž���ϰ� ���� ���� ���������� ������ �Ѱ� ���� ���� �ذ� ����.