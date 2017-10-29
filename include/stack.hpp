#include <iostream>

using namespace std;

template <typename T>
class stack
{
public:
	stack();/*noexept*/
	stack(const stack<T> &);/*strong*/
	size_t count() const; /*noexcept*/
	void print()const;/*noexcept*/
	void push(T const &); /*strong*/
	void swap(stack<T>&); /*noexcept*/
	void pop(); /*strong*/
	T top(); /*strong*/
	bool empty() const; /*noexcept*/
	stack<T>& operator=(stack<T> &); /*noexcept*/
	~stack();/*noexcept*/
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
	if (count_ > 0) {
		array_size_ = copy.array_size_;
		count_ = copy.count_;
		array_ = new T[count_];
		std::copy(copy.array_, copy.array_ + copy.count_, array_);
	}
	else{
		array_ = nullptr;
	}
}

template<class T>
size_t stack<T>::count() const
{
	return count_;
}

template <typename T>
bool stack<T>::empty() const 
{
	return (count_ == 0);
}

template<typename T> 
void stack<T>::swap(stack& x) 
{
	std::swap(x.array_size_, array_size_);
	std::swap(count_, x.count_);
	std::swap(x.array_, array_);
}

template <typename T>
T stack<T>::top()
{
	if (empty())
	{
		throw "Stack is empty!";
	}
	return array_[count_ - 1];
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
		if (array_size_ > 0) {
			array_size_ = array_size_ * 2;
			T *s1 = new T[array_size_];
			std::copy(array_, array_ + count_, s1);
			delete[] array_;
			array_ = s1;
		}
	}
	array_[count_] = value;
	count_++;
}

template <typename T>
void stack<T>::pop()
{
	if (empty()) 
		throw "Stack is empty" ;
	count_--;
}

template <typename T>
void stack<T>::print() const
{
	for (int i = 0; i < array_size_; i++)
		cout << array_[i];
}

template<typename T>
stack<T>& stack<T>::operator=(stack<T> & tmp)
{
	if (this != &tmp)
	{
		stack<T> other(tmp);
		other.swap(*this);
	}
	return *this;
}
