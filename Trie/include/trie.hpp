
#include <iostream>
using namespace std;
class trie_node ;
typedef class trie_node* TrieNode;

class Trie;
class Trie {
   public:
      Trie();
      TrieNode root;

      // Functionality
      
      void insert(string word);
      bool search(string word);
      bool startsWith(string prefix);
      void remove(string word, int depth);
      int howManyWords();
   private:
      int trieWords;
      

};


class trie_node{
   public:
      // trie_node(char data);
      char data;
      trie_node* children[25];
      bool wordEnding;
      bool isEmpty();
} ;


