// leetcode 3번

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

// 연속적으로 나오는데, 반복되는 문자가 없는 가장 긴 서브스트링 찾기
// 속도, 공간 면에서 최하위권 나옴

// 아마, 괜찮은 속도를 위해서는 dp를 활용해야 하는것으로 보임.
// 좀 찾아봐야겠다.

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
                if (repeat[i] == *it) // 이미 탐색한거중 중복 있음
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
// dp 쓰는건 아니였다. 아무데나 dp를 갖다 붙이지 말자.
// 그냥 푸니까 되는데, 코드를 개선했더니 속도가 엄청 빨라졌다.
// 정확한 이유는 조금 생각해봐야겠다. 추측하긴, 원래는 찾는것도 string을 기준으로
// 겹치는 것을 찾은데다가(find 등도 미사용), repeat를 클리어하고 다시 거기서부터 s를 쭉 긁어서 원소를 집어넣어, 이중으로 시간을 먹였는데
// 지금은 set 대신 vector 사용, 그를 통해 탐색하고 앞의 것을 지워버리는 식으로 한것 등이 영향 준것 같다.