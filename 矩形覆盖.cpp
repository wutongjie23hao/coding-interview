/***************************
 * 矩形覆盖
 * 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
 * 请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
 * ***************************/
class Solution {
public:
  int rectCover(int number) {
        int sum[100001];
        if(number>=0 && number<=100001){
            sum[0] = 0;
            sum[1] = 1;
            sum[2] = 2;
            if(number>2){
                for(int i=3; i<=number; i++)
                  sum[i] = sum[i-1]+sum[i-2];
            }
            return sum[number];
        } else
            return rectCover(number-1)+rectCover(number-2);
  }
};