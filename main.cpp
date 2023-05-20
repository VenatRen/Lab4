#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для проверки того, может ли слово состоять из букв другого слова
bool canBeMadeOf(string word, string letters) {
    for (char c : word) {
        size_t pos = letters.find(c);
        if (pos == string::npos) {
            return false;
        }
        letters.erase(pos, 1);
    }
    return true;
}

// Функция поиска всех слов из словаря, которые могут быть составлены из букв данного слова
vector<string> findWords(string word, string dictFile) {
    vector<string> words;
    ifstream file(dictFile);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (canBeMadeOf(line, word)) {
                words.push_back(line);
            }
        }
        file.close();
    }
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.size() > b.size();
    });
    return words;
}

int main() {
    string word = "привет";
    string dictFile = "text.txt";
    vector<string> words = findWords(word, dictFile);
    for (string w : words) {
        cout << w << endl;
    }
    cout << "Работу выполнил: Ставничий Даниил Сергеевич, ФИТУ РПИб" << endl;
    return 0;
}