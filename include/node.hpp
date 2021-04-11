#pragma once

namespace itis {

    struct Node {
    public:
        // хранимое значение
        int value;

        // указатели на левого и правого потомка
        Node *left;
        Node *right;

        // уровень
        int level;


        Node(int value, Node *left, Node *right, int level) : value(value), left(left), right(right), level(level) {}
    };
}
