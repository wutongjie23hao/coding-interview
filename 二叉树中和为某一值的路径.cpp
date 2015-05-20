/* ******************************
 * 二叉树中和为某一值的路径(举例让抽象具体化)
 * 输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所
 * 有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形
 * 成一条路径。
 * *****************************/
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
  vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > result;
        vector<int> path;
        if(root==NULL)
            return result;
        int currentSum = 0;
        FindPath(root, expectNumber, result, path, currentSum);
        return result;
  }
    void FindPath(TreeNode* root, int expectNumber, vector<vector<int> >& result,
                  vector<int>& path, int currentSum){
        currentSum += root->val;
        path.push_back(root->val);
        //判断是否是叶节点
        bool isLeaf = (root->left==NULL) && (root->right==NULL);
        //如果是叶节点而且路径和正好是所要求的值，把路径放到结果里
        if(currentSum == expectNumber && isLeaf)
            result.push_back(path);
        //如果非叶节点，那么访问其左右子树，寻找可能的路径
        if(root->left != NULL)
            FindPath(root->left, expectNumber, result, path, currentSum);
        if(root->right != NULL)
            FindPath(root->right, expectNumber, result, path, currentSum);
        //在最后把测试的那个节点要弹出来，回到父节点
        path.pop_back();
    }
};
