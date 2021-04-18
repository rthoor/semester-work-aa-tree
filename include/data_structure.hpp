#pragma once
#include <node.hpp>
#include <iostream>
using namespace std;

// Заголовочный файл с объявлением структуры данных

namespace itis {

  // Tip 1: объявите здесь необходимые структуры, функции, константы и прочее

  // Пример: объявление константы времени компиляции в заголовочном файле
  inline constexpr auto kStringConstant = "Hello, stranger!";

  // Пример: объявление структуры с полями и методами
  struct AATree {
   public:
    Node* root_{nullptr};

    void Add(int value);

      void Skew(Node *parent);

      void Split(Node *pNode);

      Node* Search(int value);

      Node *Delete(int value);

      void DecreaseLevel(Node* current);

      void Print(Node* current);
      void Print1(Node* current);
  };

}  // namespace itis