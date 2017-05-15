#ifndef STD_ARRAY_H
#define STD_ARRAY_H

#include <stddef.h>

/* Adapted from GNU libstdc++ array */
/* DOES NOT SUPPORT ZERO-SIZED ARRAYS */

template<typename T, size_t N>
struct std_array {
  typedef T&        reference;
  typedef const T&  const_reference;
  typedef T*        iterator;
  typedef const T*  const_iterator;
  typedef size_t    size_type;
  typedef ptrdiff_t difference_type;
  typedef T         value_type;
  typedef T*        pointer;
  typedef const T*  const_pointer;

  T elems[N];

  iterator
  begin() noexcept
  { return iterator(data()); }

  const_iterator
  begin() const noexcept
  { return const_iterator(data()); }

  iterator
  end() noexcept
  { return iterator(data() + N); }

  const_iterator
  end() const noexcept
  { return const_iterator(data() + N); }

  reference
  operator[](size_type n) noexcept
  { return const_cast<reference>(elems[n]); }

  constexpr const_reference
  operator[](size_type n) const noexcept
  { return const_cast<reference>(elems[n]); }

  pointer
  data() noexcept
  { return const_cast<pointer>(elems); }

  const_pointer
  data() const noexcept
  { return const_cast<pointer>(elems); }
};

#endif /* STD_ARRAY_H */
