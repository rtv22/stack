#include <stack.hpp>
#include <chrono>
#include <thread>

template <typename T>
void producer(stack<T> &tmp)
{
	for (;;)
	{
		tmp.push(std::rand() % 10);
		std::this_thread::sleep_for(std::chrono::seconds(std::rand() % (3) + 1));
	}
}

template <typename T>
void consumer(stack<T> &tmp)
{
	for (;;)
	{
		tmp.pop();
		std::this_thread::sleep_for(std::chrono::seconds(std::rand() %	3));
		std::this_thread::sleep_for(std::chrono::seconds(std::rand() %	3));
	}
}

int main()
{
	stack<int> Stack;
	std::thread prod(producer, std::ref(Stack));
	std::thread cons(consumer, std::ref(Stack));
	prod.join();
	cons.join();
	return 0;
}
