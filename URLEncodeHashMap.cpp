class Solution {
    
private:
    unordered_map<string, string> urlMapping;
    string base_url = "http://tinyurl.com/";
    
public:
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string url_postfix_hash;
        
        for(int i = 0; i <= 6; i++) {
            url_postfix_hash += randomCharGen();
        } 
        
        string short_url = base_url + url_postfix_hash;
        cout << "SHORT URL: " << short_url << endl;
        urlMapping[short_url] = longUrl;
        return short_url;
    }
    
    // Hash function
    int randomCharGen() {
        random_device seed;
        mt19937 charGen(seed());
        uniform_int_distribution<> ourDist(0,120);
        return ourDist(charGen);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return urlMapping[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
