class Solution {
    int N;
    int M;
    int[] dx = {1, -1, 0, 0};
    int[] dy = {0, 0, 1, -1};

    public int numIslands(char[][] grid) {
        if(grid == null || grid.length == 0 || grid[0].length == 0)
            return 0;

        N = grid.length;
        M = grid[0].length;
        int ret = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(grid[i][j] == '1') {
                    ret++;
                    dfs(grid, i, j);
                }
            }
        }
        return ret;
    }

    void dfs(char[][] grid, int i, int j) {
        if(i < 0 || j < 0 || i >= N || j >= M || grid[i][j] != '1')
            return;
        grid[i][j] = 'X';
        for(int k=0; k<4; k++) dfs(grid, i+dy[k], j+dx[k]);
    }
}