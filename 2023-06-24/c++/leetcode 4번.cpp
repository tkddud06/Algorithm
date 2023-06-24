//================================================================ =
//== 22 == ERROR: AddressSanitizer: heap - buffer - overflow on address 0x6020000000d4 at pc 0x00000034c7e3 bp 0x7ffea0f26450 sp 0x7ffea0f26448
//READ of size 4 at 0x6020000000d4 thread T0
//#2 0x7f10bae3e082  (/ lib / x86_64 - linux - gnu / libc.so.6 + 0x24082)
//0x6020000000d4 is located 0 bytes to the right of 4 - byte region[0x6020000000d0, 0x6020000000d4)
//allocated by thread T0 here :
//#6 0x7f10bae3e082  (/ lib / x86_64 - linux - gnu / libc.so.6 + 0x24082)
//Shadow bytes around the buggy address :
//0x0c047fff7fc0 : 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//0x0c047fff7fd0 : 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//0x0c047fff7fe0 : 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//0x0c047fff7ff0 : 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//0x0c047fff8000 : fa fa fd fa fa fa fd fa fa fa fd fa fa fa 00 fa
//= > 0x0c047fff8010: fa fa fd fa fa fa fd fa fa fa[04]fa fa fa fa fa
//0x0c047fff8020 : fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//0x0c047fff8030 : fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//0x0c047fff8040 : fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//0x0c047fff8050 : fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//0x0c047fff8060 : fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//Shadow byte legend(one shadow byte represents 8 application bytes) :
//    Addressable : 00
//    Partially addressable : 01 02 03 04 05 06 07
//    Heap left redzone : fa
//    Freed heap region : fd
//    Stack left redzone : f1
//    Stack mid redzone : f2
//    Stack right redzone : f3
//    Stack after return : f5
//    Stack use after scope : f8
//    Global redzone : f9
//    Global init order : f6
//    Poisoned by user : f7
//    Container overflow : fc
//    Array cookie : ac
//    Intra object redzone : bb
//  ASan internal:           fe
//    Left alloca redzone : ca
//    Right alloca redzone : cb
//    Shadow gap : cc
//    == 22 == ABORTING
// 
// 라는 오류가 나와서 사실 상당히 당황스러웠다. 아마 메모리 참조 오류가 아닐까 싶다.
// 실제로, 인덱스에 따라 참조하는 부분을 고치자 해결됨.

// 찾아 보니까 '힙 버퍼 오버플로는 프로그램이 동적으로 할당된 버퍼(힙의)에 저장할 수 있는 것보다 더 많은 데이터를 쓸 때 발생합니다. 이로 인해 인접한 메모리를 덮어쓰게 되어 메모리 손상 및 잠재적인 충돌이 발생할 수 있습니다.' 라고 함. 아마 벡터 사용과정에서, 동적 할당이 잘못되거나 한거 같음. 암튼 동적할당 안된곳에
// 데이터를 넣거나 접근하려고 할때 뜨는 모양.
// 챗지피티한테 물어보니, 요약하면, AddressSanitizer의 오류 메시지는 프로그램이 메모리 주소 0x6020000000d4에서 4바이트를 읽으려고 시도했을 때 힙 버퍼 오버플로우가 발생했음을 나타냅니다. 오류 발생 지점의 코드와 메모리 영역에 대한 추가 정보가 제공되었으며, 프로그램 실행이 추가 문제를 방지하기 위해 중단되었습니다. 라고 응답함.
// 내가 찾아본 것이 맞는 것 같다.

// 해당 문제는 해결했으나
//Line 1034: Char 9 : runtime error : reference binding to null pointer of type 'int' (stl_vector.h)
//SUMMARY : UndefinedBehaviorSanitizer : undefined - behavior / usr / bin / .. / lib / gcc / x86_64 - linux - gnu / 9 / .. / .. / .. / .. / include / c++ / 9 / bits / stl_vector.h : 1043 : 9
// 라는 오류를 맞딱뜨림. 한 벡터가 빈 상태로 올때 나타나는 오류 같은데, (벡터가 비어있으면 size가 비작동되거나, 따른 오류로 보임.)
// 
// size는 예상대로, 벡터가 비어있어도 작동 가능했음. 실수는 휴먼에러였음. num1[i1]을 불러와야하는 자리에서, num2[i1]로 되어있었음.
// 오류 정의로는, 널 포인터를 역참조하여 바인딩하려할때 나는거라는거 같아.
// 아마, nums2[i1]은 없는 값을 가져오는 것이였으므로, nullptr이 vector 내부적으로 있었고, 그 값을 넣는 과정에서 오류가 난듯.

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i1 = 0;
        int i2 = 0;
        double length = nums1.size() + nums2.size();
        int find_idx = ceil(length / 2);
        int median1;
        int median2;

        //if (length == 1)
        //{
        //    if (i1 >= nums1.size()) // nums1 다찾음
        //    {
        //        return double(nums2[i2]);
        //    }
        //    else if (i2 >= nums2.size()) // nums2 다찾음
        //    {
        //        return double(nums1[i1]);
        //    }
        //}

        for (int sum_i = 0; sum_i < find_idx - 1; sum_i++)
        {
            if (i1 >= nums1.size()) // nums1 다찾음
            {
                i2++;
            }
            else if (i2 >= nums2.size()) // nums2 다찾음
            {
                i1++;
            }
            else // 둘다 아직 찾아봐야함
            {
                if (nums1[i1] < nums2[i2])
                {
                    i1++;
                }
                else
                {
                    i2++;
                }
            }
        }

        // 이제 인덱스 뽑아야 하는 상황

        if (i1 >= nums1.size()) // nums1 다찾음
        {
            median1 = nums2[i2];
            i2++;
        }
        else if (i2 >= nums2.size()) // nums2 다찾음
        {
            median1 = nums2[i1]; // 해당 부분이 문제였음
            i1++;
        }
        else // 둘다 아직 찾아봐야함
        {
            if (nums1[i1] < nums2[i2])
            {
                median1 = nums1[i1];
                i1++;
            }
            else
            {
                median1 = nums2[i2];
                i2++;
            }
        }

        if (int(length) % 2 == 0) // 짝수라서 두개 찾아야 됨
        {
            if (i1 >= nums1.size()) // nums1 다찾음
            {
                median2 = nums2[i2];
                i2++;
            }
            else if (i2 >= nums2.size()) // nums2 다찾음
            {
                median2 = nums1[i1]; // 해당 부분이 문제였음
                i1++;
            }
            else // 둘다 아직 찾아봐야함
            {
                if (nums1[i1] < nums2[i2])
                {
                    median2 = nums1[i1];
                    i1++;
                }
                else
                {
                    median2 = nums2[i2];
                    i2++;
                }
            }

            return double(median1 + median2) / 2;
        }
        else
        {
            return double(median1);
        }
    }
};

// 문제는 해결했지만, 해당 코드는 O((m+n)/2), 즉 O(m+n) 이다.
// O(log m+n)을 만드는건 쉽지 않네.. 솔루션들을 보니, 뉘앙스는 알겠는데 완벽히 이해가 안되니, 천천히 봐 보자. 
// https://leetcode.com/problems/median-of-two-sorted-arrays/solutions/2651020/c-solution/
// https://izmirprogramming.tistory.com/11
// 대충 컨셉트는 알겠는데, 내일 다시한번 깊게 봐 보자.


int main()
{
    Solution s;
    vector<int> v1 = { 1 };
    vector<int> v2 = { };
    cout << s.findMedianSortedArrays(v1, v2) << endl;;

    return 0;
}