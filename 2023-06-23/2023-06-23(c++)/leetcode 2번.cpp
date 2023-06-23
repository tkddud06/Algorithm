

// leetcode 2번 첫 코드

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


//class Solution {
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        // 앞쪽부터 순서대로 더하고, 만약 자리올림수 발생시 다음단계로 넘기면 되지.
//        ListNode* header = new ListNode();
//        ListNode* ptr = header;
//        int carry = 0;
//        for (l1; l1 != nullptr; l1 = l1->next) // l1이 null이 아니면 계속 진행하며 더해줌
//        {
//            if (l2 == nullptr) // l2가 null일 경우에는 중지하고, l1 남은걸 그대로 넣어줌
//            {
//                for (l1; l1 != nullptr; l1 = l1->next)
//                {
//                    ptr->next = new ListNode(l1->val + carry);
//                    carry = 0;
//                    if (ptr->next->val >= 10)
//                    {
//                        ptr->next->val = ptr->next->val % 10;
//                        carry = 1;
//                    }
//                    ptr = ptr->next;
//                }
//                break;
//            }
//            else
//            {
//                ptr->next = new ListNode(l1->val + l2->val + carry);
//                carry = 0;
//                if (ptr->next->val >= 10)
//                {
//                    ptr->next->val = ptr->next->val % 10;
//                    carry = 1;
//                }
//                ptr = ptr->next;
//                l2 = l2->next;
//            }
//        }
//
//        // l1이 null인데 l2가 남아있다면, l2를 넣어주는 알고리즘
//
//        if (l2 != nullptr)
//        {
//            for (l2; l2 != nullptr; l2 = l2->next)
//            {
//                ptr->next = new ListNode(l2->val + carry);
//                carry = 0;
//                if (ptr->next->val >= 10)
//                {
//                    ptr->next->val = ptr->next->val % 10;
//                    carry = 1;
//                }
//                ptr = ptr->next;
//            }
//        }
//        if (carry)
//        {
//            ptr->next = new ListNode(carry);
//        }
//        ListNode* result = header->next;
//        delete header;
//        return result;
//
//    }
//};


// 속도가 하위 19퍼센트 쯤이라, 일부 코드를 바꿈


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


 //class Solution {
 //public:
 //    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
 //        ListNode* header = new ListNode();
 //        ListNode* ptr = header;
 //        int carry = 0;
 //        while (l1)
 //        {
 //            if (!l2)
 //            {
 //                while (l1)
 //                {
 //                    int sum = l1->val + carry;
 //                    if (sum >= 10)
 //                    {
 //                        sum = sum % 10;
 //                        carry = 1;
 //                    }
 //                    else carry = 0;
 //                    ptr->next = new ListNode(sum);
 //
 //                    l1 = l1->next;
 //                    ptr = ptr->next;
 //                }
 //                break;
 //            }
 //            else
 //            {
 //                int sum = l1->val + l2->val + carry;
 //                if (sum >= 10)
 //                {
 //                    sum = sum % 10;
 //                    carry = 1;
 //                }
 //                else carry = 0;
 //                ptr->next = new ListNode(sum);
 //                l1 = l1->next;
 //                l2 = l2->next;
 //                ptr = ptr->next;
 //            }
 //        }
 //
 //        while (l2)
 //        {
 //            int sum = l2->val + carry;
 //            if (sum >= 10)
 //            {
 //                sum = sum % 10;
 //                carry = 1;
 //            }
 //            else carry = 0;
 //            ptr->next = new ListNode(sum);
 //            l2 = l2->next;
 //            ptr = ptr->next;
 //        }
 //
 //        if (carry)
 //        {
 //            ptr->next = new ListNode(carry);
 //        }
 //
 //        ListNode* result = header->next;
 //        delete header;
 //        return result;
 //
 //    }
 //
 //};