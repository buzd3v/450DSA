#include <algorithm>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>
template <typename T> class Node {
public:
  T data;
  Node<T> *next;
};

template <typename T> class LinkedList {
private:
  Node<T> *head;
  int size;

public:
  LinkedList() {
    head = nullptr;
    size = 0;
  }
  LinkedList(const LinkedList &other) : head(other.head), size(other.size){};
  LinkedList(LinkedList &&other) noexcept : head(other.head), size(other.size) {
    other.head = nullptr;
    other.size = 0;
  };
  LinkedList &operator=(const LinkedList &other) = default;

  // ~LinkedList() { clear(); }

  void push_back(const T &value) {
    Node<T> *newNode = new Node<T>();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
      head = newNode;
    } else {
      Node<T> *current = head;
      while (current->next != nullptr) {
        current = current->next;
      }
      current->next = newNode;
    }
    size++;
  }

  void insert(int index, T value) {
    if (index < 0 || index > size) {
      return;
    }

    Node<T> *newNode = new Node<T>();
    newNode->data = value;

    if (index == 0) {
      newNode->next = head;
      head = newNode;
    } else {
      Node<T> *current = head;
      for (int i = 0; i < index - 1; i++) {
        current = current->next;
      }
      newNode->next = current->next;
      current->next = newNode;
    }
    size++;
  }
  void erase(int index) {
    if (index < 0 || index >= size) {
      return;
    }

    if (index == 0) {
      Node<T> *current = head;
      head = head->next;
      delete current;
    } else {
      Node<T> *current = head;
      for (int i = 0; i < index - 1; i++) {
        current = current->next;
      }
      Node<T> *next = current->next;
      current->next = next->next;
      delete next;
    }
    size--;
  }

  void clear() {
    while (head != nullptr) {
      Node<T> *current = head;
      head = head->next;
      delete current;
    }
    size = 0;
  }

  T operator[](int index) {
    if (index < 0 || index >= size) {
      return T();
    }

    Node<T> *current = head;
    for (int i = 0; i < index; i++) {
      current = current->next;
    }
    return current->data;
  }

  int getSize() { return size; }
  T getHead() { return head->data; }
  bool find(const T &value, bool t) {
    if (t == true) {
      Node<T> *current = head;
      while (current != nullptr) {
        if (current->data == value) {
          return true;
        }
        current = current->next;
      }
      return false;
    }
    return false;
  }
  // range-based for loop
public:
  class Iterator {
  public:
    Iterator(Node<T> *node) : current(node) {}

    T &operator*() { return current->data; }
    Iterator &operator++() {
      current = current->next;
      return *this;
    }
    bool operator!=(const Iterator &other) const {
      return current != other.current;
    }
    bool operator==(const Iterator &other) const {
      return current == other.current;
    }

  private:
    Node<T> *current;
  };

  Iterator begin() { return Iterator(head); }
  Iterator end() { return Iterator(nullptr); }
  Iterator find(const std::string &value) {
    Iterator it = begin();
    Iterator end_it = end();
    while (it != end_it) {
      if ((*it).word == value) {
        return it;
      }
      ++it;
    }
    return end_it;
  }
};
class StopList {
private:
  LinkedList<std::string> stopList;

public:
  StopList(){};
  StopList(const std::string &path) { createStopList(path); }
  ~StopList(){};

  void createStopList(const std::string &path) {
    std::ifstream file(path);
    std::string word;

    // Check if the file is open
    if (file.is_open()) {
      // Read each line of the file as a string
      while (std::getline(file, word)) {
        stopList.push_back(word);
      }
      file.close(); // close the file
    } else {
      std::cout << "Unable to open file" << std::endl;
    }
  }
  void log() {
    for (auto c : stopList) {
      std::cout << c << std::endl;
    }
  }
  auto &getStopList() { return stopList; }
};
class Data {
public:
  std::string word;
  int timeAppear;
  LinkedList<int> line;
  Data(){};
  Data(std::string word, int time, LinkedList<int> line)
      : word(word), timeAppear(time), line(line){};
  bool operator==(const Data &other) {
    if (this->word.compare(other.word) == 0) {
      return true;
    }
    return false;
  }
  void log() {
    for (auto l : line) {
      std::cout << l << " ";
    }
    std::cout << std::endl;
  }
};
class wpfData {
public:
  std::string word;
  int line;
};
class IndexList {
private:
  LinkedList<Data> indexList;

  LinkedList<std::string> stopList;

public:
  IndexList(StopList &c) { stopList = c.getStopList(); }
  ~IndexList(){};

  // get all the word from file and added into the list;
  auto getIndexList() { return indexList; }
  auto log() {
    for (auto c : indexList) {
      std::cout << c.word << " " << c.timeAppear << " ";
    }
  }
  void getWordsFromFile(const char *path) {
    std::ifstream file(path);
    std::string word;
    std::string line;
    int lineNumber = 1;
    // Check if the file is open
    if (file.is_open()) {
      // Read each line of the file
      while (std::getline(file, line)) {
        std::string tmp;
        std::string lower_line;
        for (auto c : line) {
          if (isalpha(c)) {
            tmp += c;
          } else if (!tmp.empty()) {
            std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
            if ((tmp.size() <= 11))
              if (isExist(tmp)) {
                auto itr = indexList.find(tmp);
                (*itr).timeAppear++;
                if (!isExistInLine(tmp, lineNumber)) {
                  (*itr).line.push_back(lineNumber);
                }
              } else {
                LinkedList<int> l_list;
                l_list.push_back(lineNumber);
                Data d_data(tmp, 1, std::move(l_list));
                indexList.push_back(std::move(d_data));
              }
            tmp.clear();
          }
        }
        if (!tmp.empty())
          std::cout << tmp << std::endl;
        lineNumber++;
      }
      file.close(); // close the file
    } else {
      std::cout << "Unable to open file" << std::endl;
    }
  }
  void updateIndexList(const std::string &word, int &line) {
    // if (isExist(word))
  }
  bool isExist(const std::string &word) {
    for (auto c : indexList) {
      if (c.word.compare(word) == 0) {
        return true;
      }
    }
    return false;
  }
  bool isExistInLine(const std::string &word, int lineNumber) {
    for (auto c : indexList) {
      if (c.word.compare(word) == 0 && c.line.find(lineNumber, true))
        return true;
    }
    return false;
  }
};

int main() {
  StopList t("./StopWord.txt");
  IndexList idx(t);
  // t.log();
  // bool c = t.getStopList().find("the", true);
  idx.getWordsFromFile("./VanBan.txt");
  idx.log();
}