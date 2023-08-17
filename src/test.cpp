#include "Vector.hpp"

int main(){

  bdb::Vector vec = {1,2,3};
  std::cout << vec;

  auto o = vec.maybe_at(1).err_log();
  std::cout << o << '(' << __FILE__ <<':'<<__LINE__<<')'<< std::endl;

  o = vec.maybe_at(4).err_log();
  std::cout << o << '(' << __FILE__ <<':'<<__LINE__<<')'<< std::endl;

}