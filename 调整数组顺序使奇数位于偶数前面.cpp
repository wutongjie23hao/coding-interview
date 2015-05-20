/* ******************
 * 调整数组顺序使奇数位于偶数前面(代码完整性)
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
 * 的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保
 * 证奇数和奇数，偶数和偶数之间的相对位置不变。
 * *****************/
class Solution {
public:
  void reOrderArray(vector<int> &array) {

        queue<int> odd,even;
        for(vector<int>::size_type i=0; i<array.size(); i++){
            if(array[i]&0x1)
                odd.push(array[i]);
            else
                even.push(array[i]);
        }

        int temp;
        queue<int>::size_type oddSize = odd.size();
        for(queue<int>::size_type i=0; i<oddSize; i++){
            temp = odd.front();
            odd.pop();
            array[i] = temp;
        }

        queue<int>::size_type evenSize = even.size();
        for(queue<int>::size_type i=0; i<evenSize; i++){
            temp = even.front();
            even.pop();
            array[i+oddSize] = temp;
        }
    }
};
