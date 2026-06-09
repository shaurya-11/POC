#include <iostream>
#include <list>
#include <string>
#include <unordered_map>

class LruCache {
 public:
  explicit LruCache(size_t capacity) : capacity_(capacity) {}

  void put(const std::string& key, int value) {
    if (entries_.size() >= capacity_) {
      auto last = order_.back();
      order_.pop_back();
      entries_.erase(last);
    }

    order_.push_front(key);
    entries_[key] = {value, order_.begin()};
  }

  int get(const std::string& key) {
    auto found = entries_.find(key);
    if (found == entries_.end()) {
      return -1;
    }

    order_.erase(found->second.position);
    order_.push_front(key);
    found->second.position = order_.begin();
    return found->second.value;
  }

 private:
  struct Entry {
    int value;
    std::list<std::string>::iterator position;
  };

  size_t capacity_;
  std::list<std::string> order_;
  std::unordered_map<std::string, Entry> entries_;
};

int main() {
  LruCache cache(2);
  cache.put("one", 1);
  cache.put("two", 2);
  cache.put("three", 3);

  std::cout << cache.get("one") << "\n";
  std::cout << cache.get("three") << "\n";
}

testing the changes 
// Automatic webhook verification marker.
int webhookVerificationValue() {
  return 42;
}

int anotherWebhookPollingMarker() {
  return 99;
}
