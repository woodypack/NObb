#include "functor.h"

#include <stdio.h>

class A {
//	friend class B;
public:
	A() { }
	virtual ~A() { }

protected:
	void task_parent() { printf("42\n"); }
};

class B : public A {
public:
	B() { }

	void run_tasks();

protected:
	void task_self() { printf("21\n"); }

	static Functor<void> tasks[];
};

B b{};

Functor<void> B::tasks[] = {
	Functor<void>::bind<A, &A::task_parent>(&b),
	Functor<void>::bind<B, &B::task_self>(&b)
};

void B::run_tasks()
{
	for (int i; i < sizeof(tasks) / sizeof(tasks[0]); i++) {
		tasks[i]();
	}
}

int main()
{
	b.run_tasks();
	return 0;
}