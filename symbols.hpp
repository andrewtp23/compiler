 #ifndef symbols_hpp
 #define  symbols_hpp

 //Symbols modified by Andrew Parker. Original credit to Dr. Andrew Sutton
 #include <string>
 #include <unordered_map>

 using symbol = const std::string;

 struct symbol_table{

   symbol* insert(const std::string& str){
     auto result = syms.insert({str,nullptr});
     return &result.first->first;
   }

   symbol* find(const std::string& str) {
     auto iter = syms.find(str);
     return &iter->first;
   }

 private:
    std::unordered_map<std::string, void*> syms;
 };

 #endif
