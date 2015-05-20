/* **************************
 * 二叉树的镜像（面试思路）
 * 输入一个二叉树，输出其镜像。
 * *************************/
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
  void Mirror(TreeNode *pRoot) {

        if(!pRoot)
            return ;
        //从根开始左子树和右子树互换就行了
        TreeNode *pTemp;
        pTemp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = pTemp;

        Mirror(pRoot->left);
        Mirror(pRoot->right);

  }
};