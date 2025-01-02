// UNORDERED_MULTISETS:

/*
Unordered Multisets are unordered associative containers that contain a set of keys
which may be equivalent

They are implemented using using open hashing (aka hashing with chaining)

Support forward iterators

Support default ctor, several parameterized ctors, itr ctors,
copy/move ctors, initializer list ctors, range-based ctors,
copy/move assignment oprs, and initializer list assignment opr

Access -> N/A
Search -> O(1)*
Insert -> O(1)*
Delete -> O(1)*
    *on average, worst case O(n)
*/ 
    
#include <unordered_set>

std::unordered_multiset<key_type, hasher=, key_equal=, allocator_type=> umset;