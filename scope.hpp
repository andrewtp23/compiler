#ifndef scope_hpp
#define scope_hpp

#include "ast.hpp"
#include "symbols.hpp"
#include <unordered_map>

struct scope{
  void insert(std::string s, Decl* d){
    map.insert({s,d});
  }
  void modify(std::string s, Decl* d){
    map[s] = d;
  }

  Decl* find(std::string s){
    auto iter = map.find(s);
    if(iter != map.end())
      return iter->second;
    else
      return nullptr;
  }

  std::unordered_map<std::string, Decl*> map;
};

#endif
