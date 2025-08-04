# Autocomplete CLI Tool

A simple C++ command-line tool that provides autocomplete suggestions from a dictionary using a Trie (prefix tree) data structure.

## 📄 Overview

This project builds a Trie from a large word list (`wordlist.txt`) and lets the user enter a prefix. It returns possible word suggestions starting with that prefix, optionally filtered by length and limited in number.

## 🧠 Features

- Efficient Trie-based word storage
- Fast autocomplete suggestions
- Optional filtering by word length
- User-defined limit on suggestions
- Reads words from an external dictionary file

## 📂 Files

| File             | Description                         |
|------------------|-------------------------------------|
| `autocomplete.cpp` | Main program using Trie structure |
| `wordlist.txt`     | Word list used to build the Trie  |

##  How to Run

1. Clone the Repository
If you haven’t already:

git clone https://github.com/arnavcs027/autocomplete.git
cd autocomplete

2. Ensure Files Are Present
Make sure these two files are in the same directory:

autocomplete.cpp
wordlist.txt

3. Compile the Code
Use a C++ compiler (e.g., g++) to compile:

g++ autocomplete.cpp -o autocomplete

⚠️ Make sure g++ is installed. You can check with g++ --version.

4. Run the Program
After compilation, run the executable:

./autocomplete   # On Linux/macOS
autocomplete.exe # On Windows (if using CMD or PowerShell)

### 🔧 Requirements

- C++ compiler (e.g., `g++`)
- A terminal or command line interface

### ⚙️ Compile the code

```bash
g++ autocomplete.cpp -o autocomplete
