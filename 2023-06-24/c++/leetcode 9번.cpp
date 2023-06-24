// 릿코드 9번
// 조건 중, 스트링으로 바꾸지 않고 해보기 있어서 그렇게 해봄.

// 단순히 거꾸로 다시 숫자를 만들어서 비교하는건, 비효율 + int 범위를 넘을 가능성 있음
// 즉각즉각 비교하는것이 더 유리하다는 결론 내려짐
// 혹은, 문자형으로 바꾸어서 배열식으로 한 뒤, 양쪽으로 비교하는 방법이 있겠음.

// % 10 == 끝자리 수. 끝자리수 날리는건 /10 하면 됨.
// 앞자리 수는 어캐 구하지?. 이 두 쌍이 나온다면, 비교. (자리수가 짝수)
// 끝자리 수는 존재하는데, 앞자리 수가 비존재하는 경우라면 스킵 (자리수가 홀수)
// 앞자리 수 구하는 방법이 애매하네. 그냥 vec로 만들어서 양쪽 비교나 할까?

// vector<int> vec;
// while(x)
// {
//     vec.push_back(x%10);
//     x /= 10;
// }
// int n = vec.size();

// for(int i = 0; i < n-1-i; i++)
// {
//     if (vec[i] != vec[n-1-i])
//     {
//         return false;
//     }
// }
// return true;

// 위 알고리즘으로 하면, 공간복잡도와 시간복잡도 모두 하위권 보임

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        if (x < 10) return true;

        unsigned int re_x = x;
        unsigned int y = 0;
        int i = 0;
        while (x)
        {
            y *= 10;
            y += x % 10;
            i++;
            x /= 10;
        }
        cout << y << endl;
        if (re_x == y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// 해당 코드로 하면, 공간복잡도 중위권, 시간복잡도 중하위권 보임
// 주석이 상당수 포함되어있었는데, 주석 빼니까 중위권 보임

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        unsigned int re_x = x;
        unsigned int y = 0;
        while (x)
        {
            y *= 10;
            y += x % 10;
            x /= 10;
        }
        if (re_x == y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
// 최종 코드. 상위권 보임. ( 시간마다 성능차이에 의해 미묘한 차이 보이지만, 사실상 무의미)
// 코드 서치들 해본 결과, x의 맨앞자리 숫자를 구할 수 있는 방법도 있음. x의 범위가 2의32승-1부터이므로, 10자리 수임 최대. 그러므로,
// 나눠주는 값을 1000000000으로 해두고, 빠르게 와일문 돌려보면서 첫 무게수를 찾는거지.
// 이를 통해서 했으면, 처음 계획한것처럼 바로바로 비교도 가능하겠다. 지금 방법은 수를 거꾸로 만들어서 한 거고. 처음엔 int 넘으니까 어려울거라 생각했는데,
// 그냥 자료형을 다른걸로 바꿔쓰면 되는거였음.