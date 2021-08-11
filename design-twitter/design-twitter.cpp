class Twitter {
public:
  /*["Twitter","postTweet","postTweet","unfollow","getNewsFeed"]
   [[],[1,4],[2,5],[1,2],[1]]
  timeline   [[4,1],[5,2]]
  */
    unordered_map<int,list<int>>graph;
    vector<pair<int,int>>timeline;
    void postTweet(int uid, int tid) {
        timeline.push_back({tid,uid});
    }
    vector<int> getNewsFeed(int uid) {
      vector<int>res;
      int sz=timeline.size(),post=0;
        for(int i=sz-1;i>-1;--i){
          if(post==10)
            break;
          if(timeline[i].second==uid or find(graph[uid].begin(),graph[uid].end(),timeline[i].second)!=graph[uid].end()){
            ++post;
            res.push_back(timeline[i].first);
          }
        }
        return res;
    }
    void follow(int fr, int fe) {
        graph[fr].push_back(fe);
    }
    void unfollow(int fr, int fe) {
      if(fr==fe)//1   2
        return;
      auto it=find(graph[fr].begin(),graph[fr].end(),fe);
      if(it!=graph[fr].end())
        graph[fr].erase(it);
    }
};
