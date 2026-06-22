#pragma once

#include "searchable_bag.hpp"

class set {
  private:
    searchable_bag& bag;
  public:
    set() = delete;
    set(const set& other) = delete ;
    set& operator=(const set& other) = delete;
    set(searchable_bag& s_bag);
    ~set();

    bool has(int) const;
    void insert(int);
    void isnert(int*, int);
    void print() const;
    void clear();

    searchable_bag& get_bag();
};

