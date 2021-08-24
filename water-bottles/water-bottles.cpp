class Solution {
public:
    int func(int bot,int ex,int res){
  if(bot<ex)
    return res;
  res+=bot/ex;
  bot=bot/ex+bot%ex;
  return func(bot,ex,res);
}
    int numWaterBottles(int bot, int ex) {
        int res=bot;
        return func(bot,ex,res);
    }
};