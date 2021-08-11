
class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        Queue<int[]>q=new LinkedList<>(); 
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(mat[i][j]==1)
                    mat[i][j]=-1;
                else
                    q.add(new int[]{i,j});
            }
        }

    int dis=0;
    while(!q.isEmpty()){
            ++dis;
            int sz=q.size();
            while(sz-->0){
                int[] it=q.poll();
                int f=it[0],s=it[1];
                if(s+1<n && mat[f][s+1]==-1){
                    q.add(new int[] {f,s+1});
                    mat[f][s+1]=dis;
                }
                if(s>0 && mat[f][s-1]==-1){
                    q.add(new int[]{f,s-1});
                    mat[f][s-1]=dis;
                }
                if(f+1<m && mat[f+1][s]==-1){
                    q.add(new int[]{f+1,s});
                    mat[f+1][s]=dis;
                }
                if(f>0 && mat[f-1][s]==-1){
                    q.add(new int[]{f-1,s});
                    mat[f-1][s]=dis;
                }
            }
        }
        return mat;
    }
}