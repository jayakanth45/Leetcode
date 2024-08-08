class Solution {
public:
    bool check(int i, int j, int n, int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int x, int y) {
        int n = rows, m = cols;

        vector<vector<int>> result;
        int count = 0;
        int right = 1, down = 1, left = 1, up = 1;
        while(count <= n*m-1){
            int i;
            for(i = y; i < y+right; i++){
                if(check(x, i, n, m)){
                    result.push_back({x, i});
                    count++;
                }
                cout << x << " " << i <<endl;
            }
            y = i;

            for(i=x; i < x+down ; i++){
                if(check(i, y, n, m)){
                    result.push_back({i, y});
                    count++;
                }
                cout << i << " " << y <<endl;
            }
            x = i;

            for(i=y; i >= y-left; i--){
                if(check(x, i, n, m)){
                    result.push_back({x, i});
                    count++;
                }
                cout << x << " " << i <<endl;
            }
            y = i;

            for(i=x; i >= x-up; i--){
                if(check(i, y, n, m)){
                    result.push_back({i, y});
                    count++;
                }
                cout << i << " " << y <<endl;
            }
            x = i;

            right+=2; down+=2; left+=2; up+=2;
        }

        return result;
    }
};