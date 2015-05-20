/* ***************
 * 旋转数组的最小数字(查找和排序)
 * 把一个数组最开始的若干个元素搬到数组的末尾，
 * 我们称之为数组的旋转。输入一个递增排序的数组
 * 的一个旋转，输出旋转数组的最小元素。例如数组
 * {3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数
 * 组的最小值为1。
 * ****************/
class Solution {
public:
  int minNumberInRotateArray(vector<int> rotateArray) {
    if(rotateArray.empty())
            return 0;
        vector<int>::size_type start=0, end=rotateArray.size()-1, mid=start;
        while(rotateArray[start]>=rotateArray[end]){
            if(start == end-1){
                mid = end;
                break;
            }
            mid = (start+end)/2;
            if ((rotateArray[mid]==rotateArray[start])
                    && (rotateArray[end] == rotateArray[mid]))
                break;
            if(rotateArray[mid] >= rotateArray[start])
                start = mid;
            else if (rotateArray[mid] <= rotateArray[end])
                end = mid;
        }

        //普通情况
        if (end-start == 1)
            return rotateArray[mid];
        //start、end、mid 对应的值相等，就得一个一个地查找了
        else {
            int minV = rotateArray[start];
            for(vector<int>::size_type i=start; i<end; i++){
                if(rotateArray[i]<minV)
                    minV = rotateArray[i];
            }
            return minV;
        }
  }
};