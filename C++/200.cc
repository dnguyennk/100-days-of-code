/* Numbers of Island */
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //BFS
        int nr = grid.size();
        if (!nr) return 0; //grid = 0 -> no island
        int nc = grid[0].size(); //numCol

        int num_islands = 0;
        for (int r = 0; r < nr; r++){
            for (int c = 0; c < nc; c++){
                if (grid[r][c] == '1'){ //island found
                    ++num_islands;
                    grid[r][c] = 0; //marked 0 as visited
                    queue<pair<int, int>> neighbors; 
                    neighbors.push({r, c}); //add to queue
                                    //cont until queue empty
                    while(!neighbors.empty()){
                        auto rc = neighbors.front(); //store the front pair 
                        neighbors.pop();
                        int row = rc.first;
                        int col = rc.second;
                        //Check 4 dir: up,down,left,right
                        if (row-1 >=0 && grid[row-1][col] == '1'){
                            neighbors.push({row-1, col});
                            grid[row-1][col] = '0';
                        }
                        if (row+1 < nr && grid[row+1][col] == '1'){
                            neighbors.push({row+1, col});
                            grid[row+1][col] ='0';
                        }
                        if (col-1 >= 0 && grid[row][col-1] == '1'){
                            neighbors.push({row, col-1});
                            grid[row][col-1] = '0';
                        }
                        if (col+1 <nc && grid[row][col+1] == '1'){
                            neighbors.push({row, col+1});
                            grid[row][col+1] = '0';
                        }
                    }
                }
            }
        }
        return num_islands;
    } 
};