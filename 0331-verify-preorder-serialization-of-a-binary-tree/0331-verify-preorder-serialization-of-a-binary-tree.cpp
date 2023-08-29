class Solution {
public:
    bool isValidSerialization(const string&preorder) {
        // if(preorder[0]=='#'){
        //     return (preorder.size()==1);
        // }
        vector<char>st;
        for(int i=0; i<preorder.size(); ++i){
            if(preorder[i]==','){
                continue;
            }
            if(preorder[i]=='#'){
                while(st.size()>1 && st.back()=='#' && st[st.size()-2]!='#'){
                    st.pop_back(); st.pop_back();
                }
                st.push_back('#');
            } else{
                st.push_back('x');
                while(i+1<preorder.size() && preorder[i+1]>='0' && preorder[i+1]<='9'){
                    ++i;
                }
            }
        }
        // while(st.size()>1 && st.back()=='#' && st[st.size()-2]!='#'){
        //     st.pop_back(); st.pop_back();
        // }
        return (st.size()==1 && st.back()=='#');
    }
};