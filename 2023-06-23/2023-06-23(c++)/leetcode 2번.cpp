

// leetcode 2�� ù �ڵ�

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
//        // ���ʺ��� ������� ���ϰ�, ���� �ڸ��ø��� �߻��� �����ܰ�� �ѱ�� ����.
//        ListNode* header = new ListNode();
//        ListNode* ptr = header;
//        int carry = 0;
//        for (l1; l1 != nullptr; l1 = l1->next) // l1�� null�� �ƴϸ� ��� �����ϸ� ������
//        {
//            if (l2 == nullptr) // l2�� null�� ��쿡�� �����ϰ�, l1 ������ �״�� �־���
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
//        // l1�� null�ε� l2�� �����ִٸ�, l2�� �־��ִ� �˰���
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


// �ӵ��� ���� 19�ۼ�Ʈ ���̶�, �Ϻ� �ڵ带 �ٲ�


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