class Solution {
public:
    int og_col = -1;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (og_col == -1) og_col = image[sr][sc];
        if (min(sr, sc) >= 0 && sr < image.size() && sc < image[0].size()) {
            if (image[sr][sc] == color) return image;
            if (image[sr][sc] == og_col) {
                if (image[sr][sc] != color) image[sr][sc] = color;
                // else {
                image = floodFill(image, sr+1, sc, color);
                image = floodFill(image, sr, sc+1, color);
                image = floodFill(image, sr-1, sc, color);
                image = floodFill(image, sr, sc-1, color);
                // }
            }
        }
        return image;
    }
};