//??......LekhanKarya..Nithost_16??
//
//find-first-k-maximum-occurring-words-given-set-strings

//Time Complexity for push/pop O(log(M))   so OverAll Time O(N) where N is size of string vector;
//Thu May 14 16:24:42 IST 2020
//

# include "bits/stdc++.h"
using namespace std;

//create Node that have string and frequency parameter
struct Node{
     string str;
     int freq;
};

//function for campare Nodes with respect to frequency and lexically 
struct cmp
{
     bool operator()(const Node a, const Node b)const
     {
          //if frequency of both Node is equal then we need to compare lexical way
          //lexicographical_compare() stl is used here for sorting string lexically
          if( a.freq == b.freq)  return !(lexicographical_compare(a.str.begin(),a.str.end(), b.str.begin(),b.str.end()));
          return a.freq < b.freq;
     }
     /* data */
};


//Main function for finding frequent words
void findFrequentWords(vector<string> str, int k)
{
     //create a max heap 
     priority_queue<Node, vector<Node>, cmp> pq;

     unordered_map<string ,int > freqOfWords;
     //vector<string > freqWords;

     for(auto &i:str)
     {
          //count frequency of each word
         freqOfWords[i]++;
     }
     
     for(auto &i: freqOfWords)
     {
          //push Word and their frequency into queue
          pq.push({i.first, i.second});
     }
     
     while(!pq.empty() && k--)
     {
          Node mx = pq.top();
          pq.pop();

          //push frequent words inoto vector of freqWords
          //freqWords.push_back(mx.str);

         //print frequent word with their frequency 
          cout<<mx.str<<" "<<mx.freq<<"\n";
     }

}

int main()
{
   int k=4;
   vector<string> str={"code", "coder", "coding", "codable", "codec", "codecs", "coded",
		"codeless", "codec", "codecs", "codependence", "codex", "codify",
		"codependents", "codes", "code", "coder", "codesign", "codec",
		"codeveloper", "codrive", "codec", "codecs", "codiscovered"};

   findFrequentWords(str,k);
   return 0;
}