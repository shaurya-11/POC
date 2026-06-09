#include <array>
#include <iostream>
#include <memory>
#include <string>

class Trie {
 public:
  void insert(const std::string& word) {
    Node* current = &root_;
    for (char ch : word) {
      int index = ch - 'a';
      if (!current->children[index]) {
        current->children[index] = std::make_unique<Node>();
      }
      current = current->children[index].get();
    }
    current->isWord = true;
  }

  bool search(const std::string& word) const {
    const Node* node = findNode(word);
    return node != nullptr && node->isWord;
  }

  bool startsWith(const std::string& prefix) const {
    return findNode(prefix) != nullptr;
  }

 private:
  struct Node {
    bool isWord = false;
    std::array<std::unique_ptr<Node>, 26> children;
  };

  const Node* findNode(const std::string& text) const {
    const Node* current = &root_;
    for (char ch : text) {
      int index = ch - 'a';
      if (!current->children[index]) {
        return nullptr;
      }
      current = current->children[index].get();
    }
    return current;
  }

  Node root_;
};

int main() {
  Trie trie;
  trie.insert("code");
  trie.insert("coder");

  std::cout << trie.search("code") << "\n";
  std::cout << trie.search("codex") << "\n";
  std::cout << trie.startsWith("cod") << "\n";
}
