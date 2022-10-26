#include <string>
#include <iostream>
using namespace std;


class TrieNode {
    public :
    char data; // To store data (character value: ‘A’ - ‘Z’)
    TrieNode **children; // To store the address of each child
    bool isTerminal; // it will be TRUE if the word terminates at this character
    
    TrieNode(char data) { // Constructor for values initialization
        this -> data = data;
        children = new TrieNode*[26];
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

    public :
    Trie() {
        root = new TrieNode('\0');
    }

    void insertWord(TrieNode *root, string word) {
        // Base case
        if(word.size() == 0) {
            root -> isTerminal = true;
            return;
        }
        // Small Calculation
        int index = word[0] - 'a'; // As for ‘a’ refers to index 0, ‘b’ refers to
        // index 2 and so on, so to reach the correct index we will do so
        
        TrieNode *child;
        
        if(root -> children[index] != NULL) { // If the first character of string is
        // already present as the child node of the root node
            child = root -> children[index];
        }
        else { // If not present as the child then creating one.
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }
        // Recursive call
        insertWord(child, word.substr(1));
        }
    }
        // For user
    void insertWord(string word) {
        insertWord(root, word);
    }

    void removeWord(TrieNode *root, string word) {
        // Base case
        if(word.size() == 0) {
            root -> isTerminal = false;
            return;
        }
        // Small calculation
        TrieNode *child;
        int index = word[0] - 'a';
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
        // Word not found
            return;
        }
        removeWord(child, word.substr(1));
        if(child -> isTerminal == false) {
            for(int i = 0; i < 26; i++) {
                if(child -> children[i] != NULL) {
                    return;
                }
            }
            delete child;
            root -> children[index] = NULL;
        }
        
        // For user
    void removeWord(string word) {
        removeWord(root, word);
    }


};
