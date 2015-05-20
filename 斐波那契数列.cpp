/* ************************
 * 斐波那契数列(递归和循环)
 * 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项
 * ************************/
class Solution {
public:
  int Fibonacci(int n) {
        int front=0, back=1;
        if(n<=0)
            return 0;
        if(n==1 || n==2)
            return 1;
        int i=2;
        while(i<=n){
            back = front+back;
            front = back-front;
            i++;
        }
        return back;
  }
};