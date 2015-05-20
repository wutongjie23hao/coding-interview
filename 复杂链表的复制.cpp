/* ******************************
 * 复杂链表的复制(分析让复杂问题简单)
 * 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一
 * 个节点，另一个特殊指针指向任意一个节点）。
 * ******************************/
struct RandomListNode {
  int label;
  struct RandomListNode *next, *random;
  RandomListNode(int x) :
      label(x), next(NULL), random(NULL) {
  }
};

class Solution {
public:
  RandomListNode* Clone(RandomListNode* pHead)
  {
    RandomListNode *pCloneHead=NULL, *pTemp, *pFront;
        map<RandomListNode*, RandomListNode*> s2CMap;

        if(pHead == NULL)
            return NULL;
        pFront = pHead;
        while(pFront!=NULL){
            pTemp = new RandomListNode(pFront->label);
            s2CMap[pFront] = pTemp;
            pFront = pFront->next;
        }

        pFront = pHead;
        while(pFront!=NULL){
            s2CMap[pFront]->next = s2CMap[pFront->next];
            s2CMap[pFront]->random = s2CMap[pFront->random];
            if(pCloneHead==NULL){
                pCloneHead = s2CMap[pFront];
                pFront = pFront->next;
            } else{
                pFront = pFront->next;
            }
        }
        return pCloneHead;
  }
};

