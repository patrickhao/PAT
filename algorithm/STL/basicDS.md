# 和基本数据结构有关的STL的用法
1. 定义

```cpp
stack<int> name;
queue<int> name;
```

2. 常见使用

**下列两种结构在访问元素时必须用```empty()```判断是否为空

```cpp
//stack
#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> st;
	for(int i = 0; i < 5; i++) {
		st.push(i);
	}
	cout << st.top() << endl;
	st.pop();//栈顶元素出栈
	cout << st.top() << endl;
}
```
```cpp
//queue
#include <iostream>
#include <stack>

using namespace std;

int main() {
	queue<int> q;
	for(int i = 0; i < 5; i++) {
		q.push(i);
	}
	cout << q.front() << endl;
	cout << q.back() << endl;
	st.pop();//队首元素出队
	cout << q.front() << endl;
}
```
