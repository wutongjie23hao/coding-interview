/* ***************************
 * 二进制中1的个数（位运算）
 * 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
 * ****************************/
class Solution {
public:
   int  NumberOf1(int n) {
         int counter=0;
         while(n){
             counter++;
             n=n&(n-1);
         }
         return counter;
   }
};
