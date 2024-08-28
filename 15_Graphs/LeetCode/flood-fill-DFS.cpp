bool isValid(vector<vector<int>> &image, int i, int j, int n, int m,
             int &color)
{
    if (i >= 0 && i < n && j >= 0 && j < m && image[i][j] == color)
        return true;

    return false;
}

void floodFillRecDFS(vector<vector<int>> &image, int sr, int sc, int &color,
                     int &newColor)
{
    // same location py new color fill kardo
    int n = image.size();
    int m = image[0].size();

    image[sr][sc] = newColor;

    // search in all four direction

    if (isValid(image, sr + 1, sc, n, m, color))
        floodFillRecDFS(image, sr + 1, sc, color, newColor);

    if (isValid(image, sr - 1, sc, n, m, color))
        floodFillRecDFS(image, sr - 1, sc, color, newColor);

    if (isValid(image, sr, sc + 1, n, m, color))
        floodFillRecDFS(image, sr, sc + 1, color, newColor);

    if (isValid(image, sr, sc - 1, n, m, color))
        floodFillRecDFS(image, sr, sc - 1, color, newColor);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                              int color)
{
    int oldColor = image[sr][sc];
    if (oldColor == color)
        return image; // no need to fill it again

    floodFillRecDFS(image, sr, sc, oldColor, color);

    return image;
}