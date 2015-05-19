/*****************************
 * 跳台阶
 * 题目描述
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
 * ********************************/
class Solution {
public:
  int jumpFloor(int number) {
        int sum[100001];
        if (number==0) return 0;
        else if (number==1) return 1;
        else if (number==2) return 2;
        else if (number>2&&number<=100000){
            sum[0] = 0;
            sum[1] = 1;
            sum[2] = 2;
            for(int i=3; i<=number; i++)
                sum[i]=sum[i-1]+sum[i-2];
            return sum[number];
        }
        else return jumpFloor(number-1)+jumpFloor(number-2);
  }
};