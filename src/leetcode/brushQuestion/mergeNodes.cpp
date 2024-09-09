/*
 * @Author: 辜思学
 * @Description: 2181. 合并零之间的节点
 * @Date: 2024-09-09 10:20:48
 */

#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeNodes(ListNode *head)
{
    ListNode *resHead = head->next;

    ListNode *curNode = head->next->next;
    ListNode *resCurNode = head->next;
    while (curNode != NULL)
    {
        if (curNode->val == 0)
        {
            if (curNode->next == NULL)
            {
                resCurNode->next = NULL;
            }
            else
            {
                resCurNode = resCurNode->next;
                resCurNode->val = 0;
            }
        }
        else
        {
            resCurNode->val += curNode->val;
        }
        curNode = curNode->next;
    }

    return resHead;
}