# Understanding `set` and `multiset` in C++

In C++, `set` and `multiset` are part of the Standard Template Library (STL) and are used to store collections of unique or non-unique elements, respectively. Both data structures are implemented as balanced binary search trees (typically Red-Black Trees), which ensures that they maintain sorted order and provide efficient operations.

## `set`

### Overview

A `set` is a collection of unique elements, sorted according to a specified sorting criterion (by default, ascending order). It provides efficient operations for insertion, deletion, and lookup.

### Key Methods

Here's a brief overview of the key methods of the `set` container, along with examples:

#### 1. `insert()`

Adds an element to the set. If the element is already present, the set does not change.

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> mySet;

    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);

    for (int elem : mySet) {
        cout << elem << " ";
    }
    // Output: 10 20 30
}
```

#### 2. `erase()`

Removes a specific element or range of elements from the set.

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> mySet = {10, 20, 30};

    mySet.erase(20); // Removes element 20

    for (int elem : mySet) {
        cout << elem << " ";
    }
    // Output: 10 30
}
```

#### 3. `find()`

Searches for an element and returns an iterator to it if found.

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> mySet = {10, 20, 30};

    auto it = mySet.find(20);
    if (it != mySet.end()) {
        cout << "Element found: " << *it << endl;
    } else {
        cout << "Element not found" << endl;
    }
    // Output: Element found: 20
}
```

#### 4. `count()`

Counts the number of occurrences of a specific element (always 0 or 1 for `set`).

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> mySet = {10, 20, 30};

    cout << "Count of 20: " << mySet.count(20) << endl;
    // Output: Count of 20: 1
}
```

#### 5. `size()`

Returns the number of elements in the set.

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> mySet = {10, 20, 30};

    cout << "Size of set: " << mySet.size() << endl;
    // Output: Size of set: 3
}
```

## `multiset`

### Overview

A `multiset` is a collection of elements where duplicates are allowed. Unlike `set`, `multiset` can store multiple instances of the same value, and it also maintains elements in sorted order.

### Key Methods

Here's a brief overview of the key methods of the `multiset` container, along with examples:

#### 1. `insert()`

Adds an element to the multiset, allowing for duplicates.

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {
    multiset<int> myMultiSet;

    myMultiSet.insert(10);
    myMultiSet.insert(20);
    myMultiSet.insert(20);
    myMultiSet.insert(30);

    for (int elem : myMultiSet) {
        cout << elem << " ";
    }
    // Output: 10 20 20 30
}
```

#### 2. `erase()`

Removes a specific element or range of elements from the multiset. Note that you can specify the number of occurrences to remove.

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {
    multiset<int> myMultiSet = {10, 20, 20, 30};

    myMultiSet.erase(20); // Removes all occurrences of 20

    for (int elem : myMultiSet) {
        cout << elem << " ";
    }
    // Output: 10 30
}
```

#### 3. `find()`

Searches for an element and returns an iterator to it if found. For `multiset`, it only finds one instance.

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {
    multiset<int> myMultiSet = {10, 20, 20, 30};

    auto it = myMultiSet.find(20);
    if (it != myMultiSet.end()) {
        cout << "Element found: " << *it << endl;
    } else {
        cout << "Element not found" << endl;
    }
    // Output: Element found: 20
}
```

#### 4. `count()`

Counts the number of occurrences of a specific element in the multiset.

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {
    multiset<int> myMultiSet = {10, 20, 20, 30};

    cout << "Count of 20: " << myMultiSet.count(20) << endl;
    // Output: Count of 20: 2
}
```

#### 5. `size()`

Returns the number of elements in the multiset, including duplicates.

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {
    multiset<int> myMultiSet = {10, 20, 20, 30};

    cout << "Size of multiset: " << myMultiSet.size() << endl;
    // Output: Size of multiset: 4
}
```

## Conclusion

Both `set` and `multiset` are powerful containers in C++ STL, each with its own use cases. `set` is useful when you need a collection of unique elements with fast lookup and sorted order, while `multiset` is appropriate when you need to allow duplicates while maintaining a sorted order. Understanding these containers and their methods allows for efficient management and manipulation of collections in C++.


Yes, you can store `pair<int, int>` in a `multiset` in C++. The `multiset` will store the pairs in a sorted order based on the comparison of the pairs. By default, pairs are compared lexicographically, meaning they are first compared by the first element, and if those are equal, then by the second element.

Here’s a detailed explanation and example of how to use `pair<int, int>` with a `multiset`:

## Storing `pair<int, int>` in `multiset`

### Overview

When you store `pair<int, int>` in a `multiset`, the pairs are sorted based on their first element. If the first elements are equal, the pairs are then sorted based on their second element. This behavior is due to the default comparison operator (`<`) used by `multiset`.

### Example Code

Here's a complete example demonstrating how to use `multiset` with `pair<int, int>`:

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {
    // Define a multiset of pairs
    multiset<pair<int, int>> myMultiSet;

    // Insert pairs into the multiset
    myMultiSet.insert({10, 20});
    myMultiSet.insert({5, 30});
    myMultiSet.insert({10, 10});
    myMultiSet.insert({10, 20}); // Duplicate pair
    myMultiSet.insert({5, 25});

    // Print the elements of the multiset
    for (const auto& p : myMultiSet) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    // Find the count of pairs with a specific first element
    int key = 10;
    auto range = myMultiSet.equal_range({key, 0}); // We don't care about the second value for counting
    cout << "Count of pairs with first element " << key << ": " << distance(range.first, range.second) << endl;

    return 0;
}
```

### Explanation

1. **Insertion**: We insert multiple pairs into the `multiset`. Note that pairs like `(10, 20)` can appear multiple times because `multiset` allows duplicates.

2. **Printing**: The pairs are printed in sorted order, which is lexicographically. For the given example, the output will be:
   ```
   (5, 25) (5, 30) (10, 10) (10, 20) (10, 20)
   ```

3. **Counting**: We use `equal_range` to get the range of pairs that have the same first element (in this case, `10`). We then count how many pairs have the first element equal to `10`.

### Custom Comparison

If you need a different sorting criterion, you can define a custom comparator for the `multiset`. For example, if you want to sort pairs by the second element first, then by the first element, you can do so as follows:

```cpp
#include <iostream>
#include <set>

using namespace std;

// Custom comparator for sorting pairs by the second element, then by the first
struct CustomComparator {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.second != b.second)
            return a.second < b.second;
        return a.first < b.first;
    }
};

int main() {
    // Define a multiset with a custom comparator
    multiset<pair<int, int>, CustomComparator> myMultiSet;

    // Insert pairs into the multiset
    myMultiSet.insert({10, 20});
    myMultiSet.insert({5, 30});
    myMultiSet.insert({10, 10});
    myMultiSet.insert({10, 20}); // Duplicate pair
    myMultiSet.insert({5, 25});

    // Print the elements of the multiset
    for (const auto& p : myMultiSet) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    return 0;
}
```

### Custom Sorting Output

With the custom comparator, the output will be sorted by the second element of the pairs:

```
(10, 10) (10, 20) (10, 20) (5, 25) (5, 30)
```

### Conclusion

You can definitely store `pair<int, int>` in a `multiset`, and the default behavior will sort the pairs lexicographically. If you need a different sorting criterion, you can provide a custom comparator. This flexibility makes `multiset` a powerful container for managing collections of pairs or other composite data types.