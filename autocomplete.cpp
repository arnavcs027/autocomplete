#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int found = 0, len = -1;
int maxWords = -1; // Maximum number of words to print
int wordsPrinted = 0; // Counter for printed words

class node {
public:
    char info;
    string Word;
    class node* ptrs[256];
    node() {
        for (int i = 0; i < 256; i++) {
            ptrs[i] = NULL;
        }
        info = '\0';
        Word = "";
    }
};

void insertword(string word, size_t pos, class node* root) {
    if (word.length() == pos) {
        root->Word = word;
        return;
    }
    if (root->ptrs[(unsigned char)word[pos]] == NULL) {
        node* newnode = new node;
        newnode->info = word[pos];
        root->ptrs[(unsigned char)word[pos]] = newnode;
        insertword(word, pos + 1, root->ptrs[(unsigned char)word[pos]]);
    } else {
        insertword(word, pos + 1, root->ptrs[(unsigned char)word[pos]]);
    }
}

void printall(class node* root) {
    if (wordsPrinted >= maxWords) return; // Stop if we've printed enough words

    for (int i = 0; i < 256; i++) {
        if (root->ptrs[i] != NULL) {
            printall(root->ptrs[i]);
        }
    }
    if (root->Word != "" && (root->Word.length() == static_cast<size_t>(len) && len != -1)) {
        cout << " -> " << root->Word << endl;
        found = 1;
        wordsPrinted++;
    } else if (root->Word != "" && len == -1) {
        cout << " -> " << root->Word << endl;
        found = 1;
        wordsPrinted++;
    }
}

void suggest(string key, size_t pos, class node* root) {
    if (pos < key.length() && root->ptrs[(unsigned char)key[pos]] != NULL) {
        suggest(key, pos + 1, root->ptrs[(unsigned char)key[pos]]);
    } else {
        printall(root);
    }
}

int main() {

    ifstream in("wordlist.txt");
    if (!in) {
        cerr << "Error opening file 'wordlist.txt'. Please check the file path and permissions." << endl;
        return 1;
    }

    string word, current = "", key;
    char ch;
    node* root = new node;

    while (in >> word) {
        insertword(word, 0, root);
    }
    in.close();

    cout << endl << "Trie Construction Successful" << endl;
    cout << "Enter the starting letters of the word: ";
    cin >> key;
    cout << "Do you know the length of the word? (y/n): ";
    cin >> ch;
    if (ch == 'y') {
        cout << "Enter the length: ";
        cin >> len;
    }

    cout << "Enter the number of words you want: ";
    cin >> maxWords;

    cout << endl << "Possible suggestions are:" << endl;
    
    suggest(key, 0, root);
    
    if (!found) {
        cout << "No words of specified length found" << endl;
    } else if (wordsPrinted < maxWords) {
        cout << "Only " << wordsPrinted << " words found." << endl;
    }

    return 0;
}

