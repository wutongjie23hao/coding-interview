/* ********************
 * 二维数组中的查找（数组）
 * 在一个二维数组中，每一行都按照从左到右递增的顺序
 * 排序，每一列都按照从上到下递增的顺序排序。请完成
 * 一个函数，输入这样的一个二维数组和一个整数，判断
 * 数组中是否含有该整数。
 * *********************/
class Solution {
public:
  bool Find(vector<vector<int> > array,int target) {
        if(array.empty())
            return false;
        if(array[0].empty())
            return false;
        int maxColumns = array[0].size(), maxRows = array.size();
        int curColumn=maxColumns-1, curRow = 0;
        int result =false;
        while(curColumn>=0&&curRow<maxRows){
            if(array[curRow][curColumn]==target){
                result = true;
                break;
            }else if (array[curRow][curColumn]>target)
                 curColumn--;
             else
                 curRow++;
        }
        return result;

  }
};
