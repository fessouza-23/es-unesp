#include <iostream>
#include <queue>
#include <cmath>

int main() {
    int atual, meta, val, media, dias = 0;
    std::queue<int> fila;

    std::cin >> atual >> meta;

    for (int i = 0; i < 30; i++) {
        std::cin >> val;
        fila.push(val);
    }

    while (atual < meta) {
        media = 0;
        int size = fila.size();
        for (int i = 0; i < size; i++) {
            media += fila.front();
            fila.push(fila.front());
            fila.pop();
        }
        media = std::ceil(static_cast<double>(media) / size);
        atual += media;
        dias++;
    }
    dias++;

    std::cout << dias << std::endl;
    return 0;
}
