#include <iostream>

using namespace std;

template <typename T>
class stack
{
public:
	stack();
	stack(const stack<T> &copy);
	size_t count() const;
	void print()const;
	void push(T const &);
	void swap()
	T pop();
	~stack();
private:
	T * array_;
	size_t array_size_;
	size_t count_;
};

template <typename T> 
stack<T>::stack() : count_(0), array_size_(0), array_{ nullptr }
{}

template<class T>
stack<T>::~stack()
{
	count_ = 0;
	array_size_ = 0;
	delete[] array_;
}

template <typename T> 
stack<T>::stack(const stack<T>& copy)
{
	array_size_ = copy.array_size_;
	count_ = copy.count_;
	array_ = new T*[array_size_];
	for (int i = 0; i < array_size_; i++)
		array_[array_size_] = copy.array_[array_size_];
}

template<class T>
size_t stack<T>::count() const
{
	return count_;
}

template<typename T> 
void stack<T>::swap() {
	T * temp = new T[array_size_]();
	std::copy(array_, array_ + count_, stdext::checked_array_iterator<T*>(temp, array_size_));
	array_ = temp;
}

template <typename T>
void stack<T>::push(T const &value)
{
	if (array_size_ == 0)
	{
		array_size_ = 1;
		array_ = new T[array_size_];
	}
	else if (array_size_ == count_)
	{
		array_size_ = array_size_ * 2;
		swap();
		//T *s1 = new T[array_size_];
		//for (int i = 0; i < count_; i++)
		//std::copy(int i = 0; i < count; i++)
		//	s1[i] = array_[i];
		//delete[] array_;
		//array_ = s1;
	}
	array_[count_] = value;
	count_++;
}

template <typename T>
T stack<T>::pop()
{
	if (count_ == 0) 
		throw "Stack is empty" ;
	count_--;
	T x = array_[count_];
	swap();
	return x;
}

template <typename T>
void stack<T>::print() const
{
	for (int i = 0; i < array_size_; i++)
		cout << array_[i];
}