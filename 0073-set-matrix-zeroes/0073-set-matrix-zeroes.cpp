class Solution {
public:

void markRow(vector<vector<int>>& matrix,int i){
            for( int j = 0 ; j < matrix[0].size() ;j++){
                    matrix[i][j] = 0;
            }
        }

        void markCol(vector<vector<int>>& matrix, int j){
            for( int i = 0 ; i < matrix.size() ;i++){
                    matrix[i][j] = 0;
            }
        }

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int>rows(n,0);
        vector<int>cols(m,0);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == 0){
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (rows[i] == 1) {
                markRow(matrix, i);
            }
        }

        for (int j = 0; j < m; j++) {
            if (cols[j] == 1) {
                markCol(matrix, j);
            }
        }
    }
};