
#include <iostream>
#include "../include/trie.hpp"

using namespace std;

int main(int argc, char* argv[]){
   Trie myTrie;
   cout << "Hello World" << endl;

   string words[10]= {"hello", "word", "mike", 
                     "bakalianos", "programmer", "also", "dog",\
                     "cat", "car", "inverse"};
   

   string search_words[15]= {"hello", "word", "mike", 
                     "here", "her","new", "random", "search", "complete",
                     "herbs", "h", "dog",
                     "invest", "inverse", "invest"};
   
   for(int i=0; i<10; i++){
      myTrie.insert(words[i]);
   }

   for(int i=0; i<15; i++){
      if(myTrie.search(search_words[i]) == true){
         cout << "\t" << search_words[i] << "\t\tfound in TRIE" << endl;
      }
      else {
         cout << "\t" << search_words[i] << "\t\tNOT found in TRIE" << endl;
      }
   }
   myTrie.remove("mike", 0);
  
}