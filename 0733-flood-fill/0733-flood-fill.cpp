class Solution {
public:
     vector<vector<int>> fillColor(vector<vector<int>>& image, int sr, int sc, int color,
                   int newColor) {
     if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != color) {
            return {};
        }

        image[sr][sc] = newColor;

        fillColor(image , sr+1 ,sc ,color , newColor);
        fillColor(image , sr ,sc+1 ,color , newColor);
        fillColor(image , sr ,sc-1 ,color , newColor);
        fillColor(image , sr-1 ,sc ,color , newColor);
        return image;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        if(image[sr][sc] == color){
            return image;
        }

       return fillColor(image, sr, sc, image[sr][sc], color);
        
    }
};