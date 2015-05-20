/* ***********************
 * 合并两个排序的列表（代码鲁棒性）
 * 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合
 * 成后的链表满足单调不减规则。
 * *************************/
struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) :
      val(x), next(NULL) {
  }
};

class Solution {
public:
  ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
  {
    struct ListNode *pNewHead=NULL;
        struct ListNode *pNew, *pTemp;

        //
        while(pHead1!=NULL && pHead2!=NULL){
            if(pHead1->val >= pHead2->val){
                pTemp = pHead2->next;
                pHead2->next = NULL;
                if(!pNewHead){
                    pNewHead = pHead2;
                    pNew = pNewHead;
                }
                else{
                    pNew->next = pHead2;
                    pNew = pNew->next;
                }
                pHead2 = pTemp;

            } else //if (pHead1->val <= pHead2->val)
            {
                pTemp = pHead1->next;
                pHead1->next = NULL;
                if(!pNewHead){
                    pNewHead = pHead1;
                    pNew = pNewHead;
                } else {
                    pNew->next = pHead1;
                    pNew = pNew->next;
                }
                pHead1 = pTemp;
            }
        }
        //
        if(!pHead1){
            if(!pNewHead)
                pNewHead = pHead2;
            else
              pNew->next = pHead2;
        }
        if(!pHead2){
            if(!pNewHead)
                pNewHead = pHead1;
            else
                pNew->next = pHead1;
        }

        return pNewHead;
  }
};