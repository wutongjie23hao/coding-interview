/* ******************
 * 替换空格(字符串)
 * 请实现一个函数，将一个字符串中的空格替换成“%20”。
 * 例如，当字符串为We Are Happy.则经过替换之后的字
 * 符串为We%20Are%20Happy
 * **********************/
class Solution {
public:
  string replaceSpace(string str) {
        int numStr=0;
        for(string::size_type i=0; i<str.length(); i++){
            if(str[i]==' ')
                numStr++;
        }
        string resultString(str.length()+2*numStr,' ');

        for(string::size_type i=0,j=0; i<str.length(); i++){
            if(str[i]==' '){
                resultString[j] = '%';
                resultString[j+1] = '2';
                resultString[j+2] = '0';
                j += 3;
            } else {
                resultString[j] = str[i];
                j++;
            }
        }
        return resultString;
  }
};
