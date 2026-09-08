#include <iostream>
using namespace std;


struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (list1 != nullptr && list2 != nullptr) 
        {
            if (list1->val <= list2->val) 
            {
                tail->next = list1;
                list1 = list1->next;
            } else 
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        if (list1 != nullptr) 
            tail->next = list1;
        else 
            tail->next = list2;
        return dummy.next;
    }
};

ListNode* createList(int n)
{
    if (n == 0)
        return nullptr;
    int x;
    cin >> x;
    ListNode* head = new ListNode(x);
    ListNode* tail = head;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        tail->next = new ListNode(x);
        tail = tail->next;
    }
    return head;
}

void printList(ListNode* head)
{
    while (head != nullptr)
    {
        cout << head->val;
        if (head->next != nullptr)
            cout << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n1, n2;
    cin >> n1;
    ListNode* list1 = createList(n1);
    cin >> n2;
    ListNode* list2 = createList(n2);
    Solution solution;
    ListNode* result = solution.mergeTwoLists(list1, list2);
    printList(result);
    return 0;
}