
### 1. Function Pointers

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool compare(int a, int b) {
    return a < b;  // Example: Ascending order
}

int main() {
    vector<int> vec = {4, 2, 3, 1};
    sort(vec.begin(), vec.end(), compare);
    for (int num : vec) {
        cout << num << " ";
    }
    return 0;
}
```

### 2. Function Objects (Functors)

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Compare {
public:
    bool operator()(int a, int b) const {
        return a < b;  // Example: Ascending order
    }
};

int main() {
    vector<int> vec = {4, 2, 3, 1};
    sort(vec.begin(), vec.end(), Compare());
    for (int num : vec) {
        cout << num << " ";
    }
    return 0;
}
```

### 3. Lambda Functions

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> vec = {4, 2, 3, 1};
    sort(vec.begin(), vec.end(), [](int a, int b) {
        return a < b;  // Example: Ascending order
    });
    for (int num : vec) {
        cout << num << " ";
    }
    return 0;
}
```

### 4. `std::function`

```cpp
#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

int main() {
    vector<int> vec = {4, 2, 3, 1};
    function<bool(int, int)> cmp = [](int a, int b) {
        return a < b;  // Example: Ascending order
    };
    sort(vec.begin(), vec.end(), cmp);
    for (int num : vec) {
        cout << num << " ";
    }
    return 0;
}
```

### 5. Using `std::greater` and `std::less`

```cpp
#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

int main() {
    vector<int> vec = {4, 2, 3, 1};
    sort(vec.begin(), vec.end(), greater<int>());
    for (int num : vec) {
        cout << num << " ";
    }
    return 0;
}
```

### 6. Comparator for Custom Classes

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class MyClass {
public:
    int value;
    MyClass(int v) : value(v) {}
};

// Comparator function
bool compareMyClass(const MyClass& a, const MyClass& b) {
    return a.value < b.value;  // Example: Ascending order based on 'value'
}

int main() {
    vector<MyClass> vec = {MyClass(4), MyClass(2), MyClass(3), MyClass(1)};
    sort(vec.begin(), vec.end(), compareMyClass);
    for (const MyClass& obj : vec) {
        cout << obj.value << " ";
    }
    return 0;
}
```

### 7. Using `std::tuple` or `std::pair`

```cpp
#include <algorithm>
#include <vector>
#include <iostream>
#include <tuple>

using namespace std;

bool compareTuple(const tuple<int, int>& a, const tuple<int, int>& b) {
    return get<0>(a) < get<0>(b);  // Example: Compare first elements
}

int main() {
    vector<tuple<int, int>> vec = {make_tuple(4, 10), make_tuple(2, 20), make_tuple(3, 30), make_tuple(1, 40)};
    sort(vec.begin(), vec.end(), compareTuple);
    for (const auto& t : vec) {
        cout << "(" << get<0>(t) << ", " << get<1>(t) << ") ";
    }
    return 0;
}
```

