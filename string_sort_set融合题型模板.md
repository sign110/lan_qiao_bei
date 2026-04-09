# string截取查找 + sort排序 + set去重 融合题型模板

> 整合 string 操作、sort 自定义排序、set 去重 三大知识点，用于蓝桥杯等竞赛中的复合型题目。

---

## 一、知识点速查

### 1. string 截取与查找

```cpp
#include <iostream>
#include <string>
using namespace std;

// 常用操作速查
string s = "Hello, World!";

// 查找子串位置（找不到返回 string::npos）
size_t pos = s.find("World");       // 正向查找
size_t pos2 = s.rfind("l");         // 反向查找
size_t pos3 = s.find_first_of("aeiou"); // 查找任意字符首次出现

// 截取子串：substr(起始位置, 长度)
string sub = s.substr(7, 5);        // "World"

// 判断是否找到
if (pos != string::npos) {
    cout << "找到，位置：" << pos << endl;
}

// 字符类型判断（需 #include <cctype>）
// isalpha(c)  isdigit(c)  isupper(c)  islower(c)
// toupper(c)  tolower(c)
```

### 2. sort 自定义排序

```cpp
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// 基本排序
vector<int> v = {3, 1, 4, 1, 5};
sort(v.begin(), v.end());            // 升序
sort(v.begin(), v.end(), greater<int>()); // 降序

// 自定义比较器（lambda）
vector<string> words = {"banana", "apple", "fig", "cherry"};
// 按长度升序，长度相同则按字典序
sort(words.begin(), words.end(), [](const string& a, const string& b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
});

// 对结构体排序
struct Student {
    string name;
    int score;
};
vector<Student> stu;
// 按分数降序，分数相同按姓名升序
sort(stu.begin(), stu.end(), [](const Student& a, const Student& b) {
    if (a.score != b.score) return a.score > b.score;
    return a.name < b.name;
});
```

### 3. set 去重

```cpp
#include <set>
#include <string>
using namespace std;

// set 自动去重 + 升序排列
set<int> s;
s.insert(3); s.insert(1); s.insert(3); // {1, 3}

// set<string> 去重
set<string> wordSet;
wordSet.insert("apple");
wordSet.insert("banana");
wordSet.insert("apple"); // 自动去重

// 遍历
for (const auto& w : wordSet) {
    cout << w << " ";
}

// 查找
if (wordSet.count("apple")) {
    cout << "存在" << endl;
}

// vector 去重常用写法（保持原顺序）
#include <vector>
#include <unordered_set>
vector<string> vec = {"a", "b", "a", "c", "b"};
unordered_set<string> seen;
vector<string> unique_vec;
for (const auto& x : vec) {
    if (seen.insert(x).second) {   // insert 返回 {iter, bool}
        unique_vec.push_back(x);
    }
}
```

---

## 二、融合题型模板

### 题型一：统计字符串中不重复的单词并排序输出

**题意：** 给定一段文本，找出所有单词，去除重复，按字典序输出。

```cpp
#include <iostream>
#include <string>
#include <set>
#include <sstream>
using namespace std;

int main() {
    string line;
    getline(cin, line);

    set<string> words; // 自动去重 + 字典序排列
    stringstream ss(line);
    string word;
    while (ss >> word) {
        // 去掉单词首尾非字母字符（如标点）
        int l = 0, r = (int)word.size() - 1;
        while (l <= r && !isalpha(word[l])) l++;
        while (r >= l && !isalpha(word[r])) r--;
        if (l <= r) {
            string clean = word.substr(l, r - l + 1);
            // 统一转小写
            for (char& c : clean) c = tolower(c);
            words.insert(clean);
        }
    }

    for (const string& w : words) {
        cout << w << "\n";
    }
    return 0;
}
```

---

### 题型二：字符串按规则排序后去重输出

**题意：** 给定 n 个字符串，先按长度升序排序，长度相同按字典序；去掉重复项后输出。

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    // 排序：先按长度，再按字典序
    sort(v.begin(), v.end(), [](const string& a, const string& b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    });

    // 去重（有序后相邻比较即可）
    set<string> seen;
    for (const string& s : v) {
        if (seen.insert(s).second) {  // 未出现过
            cout << s << "\n";
        }
    }
    return 0;
}
```

---

### 题型三：查找子串并统计不同匹配位置

**题意：** 在主串中查找模式串的所有出现位置，去重后升序输出位置。

```cpp
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    string text, pattern;
    cin >> text >> pattern;

    set<int> positions; // 自动去重 + 升序
    size_t pos = text.find(pattern);
    while (pos != string::npos) {
        positions.insert((int)pos);
        pos = text.find(pattern, pos + 1); // 从下一个位置继续查找
    }

    cout << "共找到 " << positions.size() << " 个不同位置：\n";
    for (int p : positions) {
        cout << p << " ";
    }
    cout << "\n";
    return 0;
}
```

---

### 题型四：提取数字串、去重后排序求和

**题意：** 给定字符串，提取其中所有连续数字子串，去重后按数值升序排序，输出它们的和。

```cpp
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;

    set<string> numStrs; // 字符串去重（避免重复数字串）
    int i = 0, n = (int)s.size();
    while (i < n) {
        if (isdigit(s[i])) {
            int j = i;
            while (j < n && isdigit(s[j])) j++;
            numStrs.insert(s.substr(i, j - i));
            i = j;
        } else {
            i++;
        }
    }

    // 转为整数并排序
    vector<long long> nums;
    for (const string& ns : numStrs) {
        nums.push_back(stoll(ns));
    }
    sort(nums.begin(), nums.end());

    long long sum = 0;
    for (long long x : nums) {
        cout << x << " ";
        sum += x;
    }
    cout << "\n总和：" << sum << "\n";
    return 0;
}
```

---

### 题型五：综合题——字符串分组排序去重

**题意：** 给定 n 个学生的姓名和成绩，去除重复姓名（保留最高分），按分数降序输出；分数相同时按姓名字典序升序。

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> best; // 姓名 -> 最高分（自动去重）
    for (int i = 0; i < n; i++) {
        string name;
        int score;
        cin >> name >> score;
        // 保留该姓名的最高分
        if (best.find(name) == best.end() || score > best[name]) {
            best[name] = score;
        }
    }

    // 转为 vector 方便排序
    vector<pair<string, int>> students(best.begin(), best.end());
    sort(students.begin(), students.end(), [](const pair<string,int>& a, const pair<string,int>& b) {
        if (a.second != b.second) return a.second > b.second; // 分数降序
        return a.first < b.first;                              // 姓名升序
    });

    for (const auto& p : students) {
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}
```

---

## 三、常见坑点提示

| 坑点 | 说明 |
|------|------|
| `string::npos` | `find` 失败时返回此值，类型为 `size_t`（无符号）, 与 `-1` 比较需注意 |
| `substr` 越界 | 起始位置超过字符串长度会抛出异常, 需先判断 |
| `sort` 比较器 | 必须满足**严格弱序**, 相等时不能返回 `true`（否则 UB） |
| `set` 有序性 | `set<string>` 按字典序；如需按其他顺序，改用 `vector` + `sort` |
| `stoi`/`stoll` | 转换前确保字符串非空且为合法数字串 |

---

## 四、头文件汇总

```cpp
#include <iostream>   // cin, cout
#include <string>     // string, substr, find
#include <algorithm>  // sort, unique
#include <vector>     // vector
#include <set>        // set, unordered_set
#include <map>        // map
#include <sstream>    // stringstream（分割字符串）
#include <cctype>     // isalpha, isdigit, toupper, tolower
using namespace std;
```
