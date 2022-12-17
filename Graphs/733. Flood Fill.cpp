class Solution
{
public:
    void helper(vector<vector<int>> &image, int sr, int sc, int newColor, int oldColor)
    {
        int m = image.size();
        int n = image[0].size();

        if (sr >= m || sc >= n || sr < 0 || sc < 0)
            return;
        if (image[sr][sc] != oldColor)
            return;

        image[sr][sc] = newColor;

        helper(image, sr + 1, sc, newColor, oldColor);

        helper(image, sr, sc + 1, newColor, oldColor);

        helper(image, sr - 1, sc, newColor, oldColor);

        helper(image, sr, sc - 1, newColor, oldColor);
        return;
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        if (image[sr][sc] == newColor)
            return image;

        helper(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
};