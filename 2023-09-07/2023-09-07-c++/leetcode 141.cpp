/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 정해진 개수가 있으므로, 그냥 단순 끝까지 체크하는 방법

class Solution {
public:
    bool hasCycle(ListNode* head) {
        int i = 0;
        while (i <= 10000)
        {
            if (head == NULL)
            {
                return false;
            }
            head = head->next;
            i++;
        }
        return true;
    }
};

// 빨리 도는 놈과 천천히 도는 놈을 만들어, 사이클을 잡아내는 방법 ( 10000개 꽉채워져있는경우 


class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (slow && fast && fast->next)
        {

            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};

// 두 코드 속도는 유사한것 같다


// 두개 합침. 최대 5000번 돌면 확인완료이므로, 5000번돌았으면 낭비없이 바로 컷하면서, 더짧은거일경우 fast가 빨리 돌아서 타이밍 맞게 slow를 만나면 바로 종료

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int i = 0;
        while (slow && fast && fast->next)
        {
            if (i > 5000)
            {
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
            i++;
        }
        return false;
    }
};