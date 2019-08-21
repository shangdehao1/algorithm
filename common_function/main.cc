#include <iostream>
#include <list>
#include <map>


using namespace std;



template<typename K, typename V>
class lru_map 
{
  struct entry {
    V value;
    typename std::list<K>::iterator lru_iterator;
  };

  std::list<K> m_lru;
  std::map<K, entry> m_entries_map;
  size_t m_watermark;
  std::mutex m_locker;

public:
  class UpdateContext {
    public:
      virtual ~Update() {};
      virtual bool update(V* v) = 0;
  };

public:
  lru_map(size_t m) : m_watermark(m) {}
  ~lru_map(){} 

  bool find(const K& key, V& value);
  bool find_and_update(const K& key, V& value, UpdateContext ctx);
  void add();
  void erase();
private:
  boo
  
};





int main() {


  return 0;
}
