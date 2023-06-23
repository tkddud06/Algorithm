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
// ��� ������ ���ͼ� ��� ����� ��Ȳ��������. �Ƹ� �޸� ���� ������ �ƴұ� �ʹ�. ���߿� ã�ƺ� ����.
// ������, �ε����� ���� �����ϴ� �κ��� ��ġ�� �ذ��.

// �ش� ������ �ذ�������
//Line 1034: Char 9 : runtime error : reference binding to null pointer of type 'int' (stl_vector.h)
//SUMMARY : UndefinedBehaviorSanitizer : undefined - behavior / usr / bin / .. / lib / gcc / x86_64 - linux - gnu / 9 / .. / .. / .. / .. / include / c++ / 9 / bits / stl_vector.h : 1043 : 9
// ��� ������ �µ��߸�. �� ���Ͱ� �� ���·� �ö� ��Ÿ���� ���� ��������, ���Ͱ� ��������� size�� ���۵��ǰų�, ���� ������ ����. ������� ���Ϻ���..

//class Solution {
//public:
//    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//        int i1 = 0;
//        int i2 = 0;
//        double length = nums1.size() + nums2.size();
//        int find_idx = ceil(length / 2);
//        int median1;
//        int median2;
//
//        if (length == 1)
//        {
//            if (i1 >= nums1.size()) // nums1 ��ã��
//            {
//                return double(nums2[i2]);
//            }
//            else if (i2 >= nums2.size()) // nums2 ��ã��
//            {
//                return double(nums1[i1]);
//            }
//        }
//
//        for (int sum_i = 0; sum_i < find_idx - 1; sum_i++)
//        {
//            if (i1 >= nums1.size()) // nums1 ��ã��
//            {
//                i2++;
//            }
//            else if (i2 >= nums2.size()) // nums2 ��ã��
//            {
//                i1++;
//            }
//            else // �Ѵ� ���� ã�ƺ�����
//            {
//                if (nums1[i1] < nums2[i2])
//                {
//                    i1++;
//                }
//                else
//                {
//                    i2++;
//                }
//            }
//        }
//
//        // ���� �ε��� �̾ƾ� �ϴ� ��Ȳ
//
//        if (i1 >= nums1.size()) // nums1 ��ã��
//        {
//            median1 = nums2[i2];
//            i2++;
//        }
//        else if (i2 >= nums2.size()) // nums2 ��ã��
//        {
//            median1 = nums2[i1];
//            i1++;
//        }
//        else // �Ѵ� ���� ã�ƺ�����
//        {
//            if (nums1[i1] < nums2[i2])
//            {
//                median1 = nums1[i1];
//                i1++;
//            }
//            else
//            {
//                median1 = nums2[i2];
//                i2++;
//            }
//        }
//
//        if (int(length) % 2 == 0) // ¦���� �ΰ� ã�ƾ� ��
//        {
//            if (i1 >= nums1.size()) // nums1 ��ã��
//            {
//                median2 = nums2[i2];
//                i2++;
//            }
//            else if (i2 >= nums2.size()) // nums2 ��ã��
//            {
//                median2 = nums2[i1];
//                i1++;
//            }
//            else // �Ѵ� ���� ã�ƺ�����
//            {
//                if (nums1[i1] < nums2[i2])
//                {
//                    median2 = nums1[i1];
//                    i1++;
//                }
//                else
//                {
//                    median2 = nums2[i2];
//                    i2++;
//                }
//            }
//
//            return double(median1 + median2) / 2;
//        }
//        else
//        {
//            return double(median1);
//        }
//    }
//};