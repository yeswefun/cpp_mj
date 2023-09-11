

声明与实现混合

```cpp
#pragma once

#ifndef __USER_H
#define __USER_H

#include <iostream>
using namespace std;

class User {

private:
	int m_age;

public:
	void setAge(int age) {
		m_age = age;
	}

	int getAge() {
		return m_age;
	}

	User() {
		m_age = 0;
		cout << "User()" << endl;
	}

	~User() {
		cout << "~User()" << endl;
	}
};

#endif // !__USER_H

```




声明与实现分离

```cpp
#pragma once

#ifndef __USER2_H
#define __USER2_H


class User {

private:
	int m_age;

public:

	void setAge(int age);

	int getAge();

	User();

	~User();
};


#endif // !__USER2_H
```




```cpp
#include "user2.h"

#include <iostream>
using namespace std;


void User::setAge(int age) {
	m_age = age;
}

int User::getAge() {
	return m_age;
}

User::User() {
	m_age = 0;
	cout << "User()" << endl;
}

User::~User() {
	cout << "~User()" << endl;
}
```

