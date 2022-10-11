	public:
	int numberOfCells(int n, int m, int r, int c, int u, int d, vector<vector<char>> &mat)
	{
		//dfs(n,m,r,c,u,d,mat);
		
		
		queue<vector<int>> q;
		q.push({r , c, u ,d });
		mat[r][c] ='*';
		while(q.size()){
		    auto it = q.front();
		    q.pop();
		    int i = it[0] , j = it[1] , up = it[2] , down = it[3];
		     if( j > 0  && mat[i][j-1] == '.' ){
		        mat[i][j-1] = '*';
		        q.push({i ,j-1 , up ,down});
		    }
		    if( j < m-1  && mat[i][j+1] == '.' ){
		        mat[i][j+1] = '*';
		        q.push({i ,j+1 , up ,down});
		    }
		    if( i > 0 && up > 0 && mat[i-1][j] == '.' ){
		        mat[i-1][j] = '*';
		        q.push({i-1 ,j , up-1 ,down});
		    }
		    if( i < n-1 && down > 0 && mat[i+1][j] == '.' ){
		        mat[i+1][j] = '*';
		        q.push({i+1 ,j , up ,down-1});
		    }
		   
		}
		
		
		
		
		int cnt = 0;
		for(int i=0; i< n; i++){
		    for(int j=0; j< m; j++){
		        if(mat[i][j] == '*'){
		            cnt++;
		        }
		    }
		}
		return cnt;
	}
	
	void dfs(int n, int m , int r ,int c , int u ,int d , vector<vector<char>> &mat){
	   mat[r][c] = '*';
	   
	   if(r > 0 && u > 0 && mat[r-1][c] == '.'){
	       dfs(n , m , r-1 ,c, u-1 , d , mat);
	   }
	   if(r < n-1  && d > 0 && mat[r+1][c] == '.' ){
	       dfs(n ,m , r+1 , c ,u ,  d-1 , mat);
	   }
	   if(c > 0 && mat[r][c-1] == '.' ) {
	       dfs(n , m , r , c-1 ,u ,d ,mat);
	   }
	   if(c < m-1 && mat[r][c+1] == '.' ){
	       dfs(n, m, r , c+1 ,u ,d , mat);
	   }
	   
	   return;
	}
	

};
