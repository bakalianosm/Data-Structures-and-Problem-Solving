


#include "../include/trie.hpp"
#include <iostream>


Trie::Trie(){

   this->root = new class trie_node;
   

   for (int i=0; i<25; i++){
      this->root->children[i] = NULL;
   }
   this->root->wordEnding = false;
   this->trieWords = 0;
   
   cout << "Trie initialized" << endl;
}

void Trie::insert(string word){

   class trie_node* curNode = this->root;
   int index;   
   for(int i = 0; i < word.length(); i++){
      index = word[i] - 'a';

      // Check if not exists node with this letter
      if(curNode->children[index] == NULL){
         // create it
         curNode->children[index] = new trie_node;
         for(int i = 0 ; i< 25 ; i++){
            curNode->children[index]->children[i] = NULL;
         }
         curNode->children[index]->data = word[i];
         curNode->children[index]->wordEnding = false;
      }

      curNode = curNode->children[index];
   }

   curNode->wordEnding = true;
    
   this->trieWords++;
   
   cout << word << " inserted!" << endl;
}


bool Trie::search(string word){
   int index;
   class trie_node* curNode = this->root;

   
   for(int i = 0; i< word.length(); i++){

      index = word[i] - 'a';
      if(curNode->children[index] == NULL){
         return false;
      }
      else{
         curNode = curNode->children[index];
      }
   }

   if(curNode->wordEnding == true){
      return true;
   }
   else{
      return false;
   }
}




void Trie::remove(string word, int depth = 0){

   class trie_node* curNode = this->root;
   
   // empty tree
   if(root == NULL) return;
   
   
   if(depth == word.size()){
      if(curNode->wordEnding == true){
         curNode->wordEnding = false;
      }

      if(curNode->isEmpty() == true){
         delete curNode;
         curNode = NULL;
      }
      return ;
   }

   int index = word[depth] - 'a';
   curNode = curNode->children[index];
   this->remove(word, depth+1);

   if (curNode->isEmpty() && curNode->wordEnding == false) {
        delete (curNode);
        curNode = NULL;
   }
 
    return ;

}
int Trie::howManyWords(){
   cout << "Trie contains " << this->trieWords << " words" << endl;
   
   return this->trieWords;
}

bool trie_node::isEmpty(){
   for (int i = 0; i < 25; i++)
      if (this->children[i])
         return false;
   return true;
}
// trie_node::trie_node(char data){
//    for(int i = 0 ; i< 25; i++){
//       this->children[i] = NULL;
//    }
//    this->data = data;
//    this->wordEnding = false;
// }