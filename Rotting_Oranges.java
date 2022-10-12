class Solution {
    
    static class Pair{
        int r ,c;
        Pair(int r , int c){
            this.r = r;
            this.c = c;
        }
    }
    public int orangesRotting(int[][] grid) {
        Queue<Pair> q = new ArrayDeque<>();
        int fresh = 0;
        int m = grid.length , n = grid[0].length;
        for(int i=0;i < m ; i++){
            for(int j=0 ; j < n ;j++){
                if(grid[i][j]==2){
                    q.add(new Pair(i,j));
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh == 0){
            return 0;
        }
        int minutes = 0;
        while(q.size()>0){
            minutes++;
            int sz = q.size();
            
            while(sz-- > 0){
                
                Pair cur = q.poll();
                int row = cur.r;
                int col = cur.c;
                     
                if( valid(grid , row - 1, col) ){
                    q.add( new Pair(row-1,col));
                    fresh--;
                }
                if( valid(grid , row , col+1) ){
                    q.add( new Pair(row,col+1));
                    fresh--;
                }
                if( valid(grid , row , col-1) ){
                    q.add( new Pair(row,col-1));
                    fresh--;
                }
                if( valid(grid , row+1, col) ){
                    q.add( new Pair(row+1,col));
                    fresh--;
                }
                
            }
            
        }
        if(fresh > 0) return -1;
        
        return minutes - 1;
    }
    public boolean valid(int[][] grid , int i , int j ){
      if( i< 0 || j< 0 || i>= grid.length || j>= grid[0].length || grid[i][j] != 1){
          return false;
      }
      grid[i][j] = 2;
      return true;
  }
    
    
}
