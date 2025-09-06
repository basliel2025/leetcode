#include <iostream>
#include <vector>
#include<map>
#include <stack>
#include<queue>
using namespace std;
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool endWordExists = false;
        int i = 0;
        while (i < wordList.size()) {
            if (wordList[i] == endWord) {
                endWordExists = true;
                break;
            }
            i++;
        }

        if (!endWordExists) {
            return 0;
        }

        map<string, vector<string>> side;
        vector<string> allWords = wordList;
        allWords.push_back(beginWord);

        int j = 0;
        while (j < allWords.size()) {
            string word = allWords[j];
            side[word] = vector<string>();

            int k = 0;
            while (k < allWords.size()) {
                string otherWord = allWords[k];
                if (word != otherWord) {
                    int diff = 0;
                    int l = 0;
                    while (l < word.length()) {
                        if (word[l] != otherWord[l]) {
                            diff++;
                        }
                        l++;
                    }
                    if (diff == 1) {
                        side[word].push_back(otherWord);
                    }
                }
                k++;
            }
            j++;
        }

        map<string, bool> visited;
        int m = 0;
        while (m < allWords.size()) {
            visited[allWords[m]] = false;
            m++;
        }

        queue<string> pack;
        pack.push(beginWord);
        visited[beginWord] = true;
        int level = 1;

        while (!pack.empty()) {
            int size = pack.size();
            int n = 0;
            while (n < size) {
                string current = pack.front();
                pack.pop();

                if (current == endWord) {
                    return level;
                }

                int p = 0;
                while (p < side[current].size()) {
                    string neighbor = side[current][p];
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        pack.push(neighbor);
                    }
                    p++;
                }
                n++;
            }
            level++;
        }

        return 0;
    };