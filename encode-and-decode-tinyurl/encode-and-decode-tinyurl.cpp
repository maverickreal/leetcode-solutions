class Solution {
public:
    unordered_map<string,string>ump;
    hash<string>h;
    // Encodes a URL to a shortened URL.
    string encode(string lon) {
        string s=to_string(h(lon));
        ump[s]=lon;
        return "http://tinyurl.com/"+s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shor) {
        return ump[shor.substr(19,shor.length()-19)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));