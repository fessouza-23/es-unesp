#include <iostream>
#include <string>
#include <set>
#include <cctype>
using namespace std;

int main() {
    set<string> setDicionario; // Conjunto "set" que implementa Arvore Binaria
    string linha;

    while (getline(cin, linha) && !linha.empty()) {
        string palavra;
        for (char c : linha) {
            if (isalpha(c)) {
                palavra += tolower(c);
            } else if (!palavra.empty()) {
                setDicionario.insert(palavra);
                palavra.clear();
            }
        }
        if (!palavra.empty()) {
            setDicionario.insert(palavra);
        }
    }

    for (const string& w : setDicionario) {
        cout << w << endl;
    }

    return 0;
}
