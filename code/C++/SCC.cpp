struct SCC{
   vector<vector<int>> adj1, adj2; vector<int> vis, todo, comp; int k = 0, n;
   void init(int _N){
      vis.resize(_N); adj1.resize(_N); comp.resize(_N); n = _N; adj2.resize(_N);
   }
   void add(int x, int y){
      adj1[x].push_back(y);
      adj2[y].push_back(x);
   }
   void dfs1(int a){
      vis[a] = 1;
      for(int i = 0; i < (int)adj1[a].size(); ++i){
         int b = adj1[a][i];
         if(!vis[b]) dfs1(b);
      }
      todo.push_back(a);
   }  
   void dfs2(int a){
      vis[a] = 1;
      comp[a] = k;
      for(int i = 0; i < (int)adj2[a].size(); ++i){
         int b = adj2[a][i];
         if(!vis[b]){
            dfs2(b);
         }
      }
   }
   void gen_code(){
      for(int i = 1; i <= n; ++i){
         if(!vis[i]) dfs1(i);
      }
      reverse(todo.begin(),todo.end());
      fill(vis.begin(),vis.end(),0);
      for(int i = 0; i < (int)todo.size(); ++i){
         int a = todo[a];
         if(!vis[a]){
            ++k;
            dfs2(a);
         }
      }

   }
};
SCC scc;