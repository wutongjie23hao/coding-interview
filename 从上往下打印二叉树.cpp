/* ***************************
 * 从上往下打印二叉树（举例让抽象具体化）
 * 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
 * ***************************/
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) :
      val(x), left(NULL), right(NULL) {
  }
};

class Solution {
public:
  vector<int> PrintFromTopToBottom(TreeNode *root) {
        vector<int> result;
        if(root==NULL)
            return result;
         //
        queue<TreeNode*> tempQ;
        TreeNode *pTemp=root;
        tempQ.push(root);
        while(!tempQ.empty()){
            pTemp = tempQ.front();
            tempQ.pop();
            result.push_back(pTemp->val);
            if(pTemp->left != NULL)
                tempQ.push(pTemp->left);
            if(pTemp->right != NULL)
                tempQ.push(pTemp->right);
        }

        return result;
  }
};
