#ifndef BDB_VECTOR_HPP
#define BDB_VECTOR_HPP

#include "Optional.hpp"

#include <vector>

namespace bdb{

template <class T>
class Vector : private std::vector<T>{
  public:
    //ctor
    using std::vector<T>::vector;
    Vector(std::initializer_list<T> init):std::vector<T>(init){};
    using std::vector<T>::operator=;

    //member function from std::vector
    using std::vector<T>::begin;
    using std::vector<T>::end;
    using std::vector<T>::cbegin;
    using std::vector<T>::cend;
    using std::vector<T>::rbegin;
    using std::vector<T>::rend;
    using std::vector<T>::crbegin;
    using std::vector<T>::crend;

    using std::vector<T>::size;
    using std::vector<T>::max_size;
    using std::vector<T>::resize;
    using std::vector<T>::capacity;
    using std::vector<T>::empty;
    using std::vector<T>::reserve;
    using std::vector<T>::shrink_to_fit;

    using std::vector<T>::operator[];
    using std::vector<T>::at;
    using std::vector<T>::data;
    using std::vector<T>::front;
    using std::vector<T>::back;

    using std::vector<T>::assign;
    using std::vector<T>::push_back;
    using std::vector<T>::emplace_back;
    using std::vector<T>::pop_back;
    using std::vector<T>::insert;
    using std::vector<T>::emplace;
    using std::vector<T>::swap;
    using std::vector<T>::clear;

    //member type
    using std::vector<T>::reference;
    using std::vector<T>::const_reference;
    using std::vector<T>::iterator;
    using std::vector<T>::const_iterator;
    using std::vector<T>::size_type;
    using std::vector<T>::difference_type;
    using std::vector<T>::value_type;
    using std::vector<T>::reverse_iterator;
    using std::vector<T>::const_reverse_iterator;

    //at function with bdb::Optional
    Optional<T> maybe_at(std::vector<T>::size_type n){
      if(n >= this->size()) return std::nullopt;
      else return make_optional((*this)[n]);
    }

    //stream
    friend inline std::ostream& operator<<(std::ostream& os,const Vector<T>& vec) noexcept{
      for(typename Vector<T>::size_type i=0;i<vec.size();i++) os << "Vec[" << i << "] : " <<vec[i] <<  std::endl;
      return os;
    }
};


}//ns bdb


#endif