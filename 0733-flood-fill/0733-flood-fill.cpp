class Solution {
    void DFS(vector<vector<int>>& image,int rows,int cols,int color,int originalColor,int currRow,int currCol){
        image[currRow][currCol] = color;
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        for(int i= 0 ; i<4;i++){
            int newRow = currRow + dr[i];
            int newCol = currCol + dc[i];
            if(newRow >=0  && newRow < rows && newCol >= 0 && newCol < cols && image[newRow][newCol] == originalColor){
                DFS(image,rows,cols,color,originalColor,newRow,newCol);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();
        int originalColor = image[sr][sc];
        if(originalColor == color){
            return image;
        }
        for(int i = 0 ; i< rows;i++){
            DFS(image,rows,cols,color,originalColor,sr,sc);
        }
        return image;
    }
};