/* **************************
 * 顺时针打印矩阵（画图让抽象具体化）
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例
 * 如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次
 * 打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
 * *************************/
class Solution {
public:
    vector<int> PrintMatrixIncircle(vector<vector<int> > matrix,int start){
        vector<int> result;
        int endY = matrix.size() - 1 - start;
        int endX = matrix[0].size() - 1 - start;

        for(int i=start; i<= endX; ++i){
            result.push_back(matrix[start][i]);
        }

        if(start<endY){
            for(int i = start+1; i<= endY; ++i){
                result.push_back(matrix[i][endX]);
            }
        }

        if(start<endX && start<endY){
            for(int i=endX-1; i>=start; --i){
                result.push_back(matrix[endY][i]);
            }
        }

        if(start<endX && start < endY - 1){
            for(int i = endY - 1; i >= start+1; --i){
                result.push_back(matrix[i][start]);
            }
        }
        return result;
    }
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> result;
        if(matrix.empty())
            return result;
        if(matrix[0].empty())
            return result;
        unsigned int start = 0;

        unsigned int rows = matrix.size();
        unsigned int columns = matrix[0].size();
        while(columns > start*2 && rows > start *2){
            vector<int> tempV = PrintMatrixIncircle(matrix, start);
            for(vector<int>::iterator iter=tempV.begin(); iter<tempV.end(); iter++){
                result.push_back(*iter);
            }
            ++start;
        }
        return result;
    }
};