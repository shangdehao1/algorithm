#ifndef DEHAO_LRU_MAP_H
#define DEHAO_LRU_MAP_H

#include <list>
#include <map>
#include <mutex>


template <class K, class V>
class lru_map {
  struct entry {
    V value;
    typename std::list<K>::iterator lru_iter;
  };

  std::map<K, entry> entries;
  std::list<K> entries_lru;

  std::mutex lock;
  size_t m_lru_size;

public:
  class UpdateContext {
    public:
      virtual ~UpdateContext() {}
      virtual bool update(V *v) = 0;
  };

  bool _find(const K& key, V *value, UpdateContext *ctx);
  void _add(const K& key, V& value);

public:
  lru_map(int m) : m_lru_size(m) {}
  virtual ~lru_map() {}
  bool find(const K& key, V& value);
  bool find_and_update(const K& key, V *value, UpdateContext *ctx);
  void add(const K& key, V& value);
  void erase(const K& key);
};

template <class K, class V>
bool lru_map<K, V>::_find(const K& key, V *value, UpdateContext *ctx)
{
  typename std::map<K, entry>::iterator iter = entries.find(key);
  if (iter == entries.end()) {
    return false;
  }

  entry& e = iter->second;
  entries_lru.erase(e.lru_iter);

  bool r = true;

  if (ctx) {
    r = ctx->update(&e.value);
  }

  if (value) {
    *value = e.value;
  }

  entries_lru.push_front(key);
  e.lru_iter = entries_lru.begin();

  return r;
}

template <class K, class V>
bool lru_map<K, V>::find(const K& key, V& value)
{
  std::lock_guard<std::mutex> l(lock);
  return _find(key, &value, NULL);
}

template <class K, class V>
bool lru_map<K, V>::find_and_update(const K& key, V *value, UpdateContext *ctx)
{
  std::lock_guard<std::mutex> l(lock);
  return _find(key, value, ctx);
}

template <class K, class V>
void lru_map<K, V>::_add(const K& key, V& value)
{
  typename std::map<K, entry>::iterator iter = entries.find(key);
  if (iter != entries.end()) {
    entry& e = iter->second;
    entries_lru.erase(e.lru_iter);
  }

  entries_lru.push_front(key);
  entry& e = entries[key];
  e.value = value;
  e.lru_iter = entries_lru.begin();

  while (entries.size() > m_lru_size) {
    typename std::list<K>::reverse_iterator riter = entries_lru.rbegin();
    iter = entries.find(*riter);
    entries.erase(iter);
    entries_lru.pop_back();
  }
}

template <class K, class V>
void lru_map<K, V>::add(const K& key, V& value)
{
  std::lock_guard<std::mutex> l(lock);
  _add(key, value);
}

template <class K, class V>
void lru_map<K, V>::erase(const K& key)
{
  std::lock_guard<std::mutex> l(lock);
  typename std::map<K, entry>::iterator iter = entries.find(key);
  if (iter == entries.end()) {
    return;
  }

  entry& e = iter->second;
  entries_lru.erase(e.lru_iter);
  entries.erase(iter);
}

#endif




template<typename K, typename V>
class lru_map {

  struct entry {
    V value;
    std::list<K>::iterator iter_lru;
  };

  std::list<K> m_entries_lru;
  std::map<K, entry> m_entries;
  size_t m_lru_size;
  std::mutex m_lock;

  bool _find(const K& key, V* v, UpdateContext& update ) {}
  void _add(const K& key, const V& value) {}

public:

  class UpdateContext {
   public:
    virtual ~UpdateContext(){}  
    virtual void update() {} = 0;
  };  

  lru_map(size_t s) : m_lru_size(s) {};
  ~lru_map(){}

   
  bool find_and_update(const K& key, V* v, Update  
  


};

























