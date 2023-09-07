/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// ������ ������ �����Ƿ�, �׳� �ܼ� ������ üũ�ϴ� ���

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

// ���� ���� ��� õõ�� ���� ���� �����, ����Ŭ�� ��Ƴ��� ��� ( 10000�� ��ä�����ִ°�� 


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

// �� �ڵ� �ӵ��� �����Ѱ� ����


// �ΰ� ��ħ. �ִ� 5000�� ���� Ȯ�οϷ��̹Ƿ�, 5000���������� ������� �ٷ� ���ϸ鼭, ��ª�����ϰ�� fast�� ���� ���Ƽ� Ÿ�̹� �°� slow�� ������ �ٷ� ����

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