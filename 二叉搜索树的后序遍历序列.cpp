/* *****************************
 * 二叉搜索树的后序遍历序列(举例让抽象具体化)
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
 * 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不
 * 相同。
 * *****************************/
class Solution {
public:
  bool VerifySquenceOfBST(vector<int> sequence) {
        vector<int> leftTree, rightTree;

        if(sequence.empty())
            return false;
        if(sequence.size()<=2)
            return true;
        int rootData = sequence[sequence.size()-1];
        bool result = true;
        unsigned int i=0;
        while(i<sequence.size()-2){
            if(sequence[i]<rootData)
                leftTree.push_back(sequence[i]);
            else
                break;
            i++;
        }
        unsigned int startR = i;
        for(i=startR; startR<sequence.size()-2 && i<=sequence.size()-2; i++){
            if(sequence[i]>=rootData)
                rightTree.push_back(sequence[i]);
            else{
                result=false;
                break;
            }
        }
        if(i<=sequence.size()-2 && !result)
            return result;
        if(leftTree.empty())
          result = VerifySquenceOfBST(rightTree);
        else if(rightTree.empty())
            result = VerifySquenceOfBST(leftTree);
            else
            result = VerifySquenceOfBST(rightTree) && VerifySquenceOfBST(leftTree);
        return result;
  }
};
