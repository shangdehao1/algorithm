#include <string>

#include "lru_map.h"


class person {
public:
  string m_name;
  string m_school;
  string m_wife;
  uint32_t m_age;
};


class update_person : public lru_map<T, person>::UpdateContext {
public:
  update_persion(){}
  ~update_persion(){}
  bool update (person* m) override {
    m->m_name = m_name;
    m->m_school = m_school;
    m->m_wife = m_wife;
    m->m_age = m_age;
  }

  string m_name;
  string m_school;
  string m_wife;
  uint32_t m_age;
};


int main() {
  lru_map test_lru(10);

  return 0;
}
