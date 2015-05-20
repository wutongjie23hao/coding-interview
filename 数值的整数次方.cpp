/* ***********************
 * 数值的整数次方
 * 给定一个double类型的浮点数base和int类型
 * 的整数exponent。求base的exponent次方。
 * ***********************/
class Solution {
public:
    double Power(double base, int exponent) {

        double result;
        bool is_minus = false;

        //指数为次数
        if (exponent < 0){
            is_minus = true;
            exponent *= -1;
        }

        if (0 == exponent)
            result = 1;
        else if (1 == exponent)
            result = base;
        else{
            //exponent为奇数
            if (exponent&0x1)
                result = Power(base, (exponent-1)/2)*Power(base, (exponent-1)/2)*base;
            else
            //exponent为偶数
                result = Power(base, exponent/2)*Power(base, exponent/2);
        }

        //为负数且为0
        if (is_minus && 0==base)
            result = 0;
        else if (is_minus)
            result = 1/result;

        return result;

  }
};
