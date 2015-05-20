/* *******************************
 * 重建二叉树(树)
 * 输入某二叉树的前序遍历和中序遍历的结果，
 * 请重建出该二叉树。假设输入的前序遍历和中
 * 序遍历的结果中都不含重复的数字。例如输入
 * 前序遍历序列{1,2,4,7,3,5,6,8}和中序遍
 * 历序列{4,7,2,1,5,3,8,6}，则重建二叉树
 * 并输出它的后序遍历序列。(测试用例中，"树"
 * 的输出形式类似于树的层次遍历，没有节点的用#来代替)
 * **********************/
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    struct TreeNode* getBinaryTree(vector<int> pre, vector<int> in){
        struct TreeNode *head;
        if(pre.empty())
            head=NULL;
        else if(pre.size()==1)
            head=new TreeNode(pre[0]);
        else{
            vector<int> leftPre, leftIn, rightPre, rightIn;
            bool rightTag = false;
            int root = pre[0];
            for(vector<int>::size_type i=0; i<in.size(); i++){
                if(in[i] == root)
                    rightTag=true;
                else if (!rightTag){
                    leftIn.push_back(in[i]);
                    if(i+1<pre.size())
                        leftPre.push_back(pre[i+1]);
                } else {
                    rightIn.push_back(in[i]);
                    rightPre.push_back(pre[i]);
                }
            }
            head = new TreeNode(root);
            head->left = getBinaryTree(leftPre, leftIn);
            head->right = getBinaryTree(rightPre, rightIn);
        }
        return head;
    }
  struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
        struct TreeNode *head = getBinaryTree(pre, in);
        //postOrder(head);
        return head;

  }
};
