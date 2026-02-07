// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// 1. 
// unordered_map<string, vector<string>> mp; //{string type key : {string type}}
        // for(string s : strs) {
        //     string word = s;
        //     sort(word.begin(), word.end()); // string ko alphabetical order mein kiya
        //     mp[word].push_back(s); //'sorted' key par original string 's' ko daal denge
        // }
        // vector<vector<string>> ans;
        // for(auto hey : mp) {
        //     ans.push_back(hey.second); // hey.second matlab vector<string> map ke andr wala
        // }
        // return ans; // O(n*k*log k)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        for(string s : strs){
            //26 size ka count array banao
            vector<int> count(26, 0);
            for(char c : s){
                count[c-'a']++;
            }
            // Is poore vector ko hi 'Key' ki tarah use kar lo
            // Jo words anagram honge, unka count vector ekdum same hoga
            mp[count].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto& hey : mp) { // & used to prevent photocopy
            ans.push_back(hey.second);
        }
        return ans;        
    }
};
/*
Feature	   unordered_map (Jo pehle use kiya)	map (Jo abhi use kiya)
Logic	   Hashing use karta hai. Ek formula    BST (Balanced Binary Search Tree) 
           lagata hai aur seedha address        use karta hai. Ye elements ko hamesha 
           par jump karta hai.                  "sorted order" mein rakhta hai.

Key        Isse sirf simple cheezein            Isse farak nahi padta! Ye do vectors ko 
Support    pasand hain (int,string, float).     compare kar sakta hai (ki kaun bada hai,
           Isse nahi pata ki vector<int>        kaun chota).
           ka hash kaise nikalein.
Speed      O(1) (Bahut fast)                    O(log n) (Thoda slow)
*/
/*
Map yahan kar kya raha hai? (Deep Detail)
Chalo map ke andar ki ek "Group" ko zoom karke dekhte hain. Maano humne vector<int> count banaya "eat" ke liye.

Map ka Dabba: Map ke paas bahut saare "Keys" hain. Har Key ek 26-size ka vector hai.

Checking: Jab "tea" aata hai, hum uska count vector banate hain. Map apne saare purane vectors se is naye vector ko compare karta hai.

Identity Match: Jaise hi usse dikhta hai ki "tea" ka vector aur "eat" ka vector bilkul ek jaise hain (exact same values at all 26 positions), wo samajh jaata hai: "Oho! Ye dono toh bhai-bhai hain."

Grouping: Wo "tea" ko usi vector wali "Value" (jo ki ek list/vector of strings hai) mein ghusa deta hai.

*/
           