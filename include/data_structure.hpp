#pragma once
#include <node.hpp>

// Заголовочный файл с объявлением структуры данных

namespace itis {

  // Tip 1: объявите здесь необходимые структуры, функции, константы и прочее

  // Пример: объявление константы времени компиляции в заголовочном файле
  inline constexpr auto kStringConstant = "Hello, stranger!";

  // Пример: объявление структуры с полями и методами
  struct AATree {
   public:
    int size_{0};
    int capacity_{0};
    Node* root_{nullptr};

    // Tip 2: На начальном этапе разработки структуры данных можете определения методов задавать в
    // заголовочном файле, как только работа будет завершена, можно будет оставить здесь только объявления.

    int size() const {
      return size_;
    }

    void Add(int value);

      void Skew(Node *parent);

      void Split(Node *pNode);

      Node* Search(int value);
  };

}  // namespace itis