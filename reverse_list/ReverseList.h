#pragma once

template <typename T>
class ReverseList {
	
	typedef struct list_t {
		T data;
		list_t* next = NULL;
	} list_t;

	list_t* first;
	list_t* last;

public:
	ReverseList();
	~ReverseList();

	size_t size(void);

	void push_back(T);
	T pop_back(void);
	void push_front(T data);
	T pop_front(void);

	void print(void);
	void reverse(void);

};

template<typename T>
ReverseList<T>::ReverseList()
	:first(NULL), last(NULL)
{
}

template<typename T>
ReverseList<T>::~ReverseList()
{
	list_t* nodes = first;
	while (nodes != NULL)
	{
		list_t* tmp = nodes;
		nodes = nodes->next;
		delete tmp;
	}
}

template<typename T>
size_t ReverseList<T>::size(void)
{
	size_t size = 0;
	for (list_t* node = first; node != NULL; size++, node = node->next);

	return size;
}

template<typename T>
void ReverseList<T>::push_back(T data)
{
	list_t* node = new list_t;
	node->data = data;

	if (first == NULL) {
		first = node;
	}

	if (last != NULL) {
		last->next = node;
	}

	last = node;
}

template<typename T>
T ReverseList<T>::pop_back(void)
{
	if (last == NULL) {
		return NULL;
	}
	list_t* node = last;
	T data = node->data;

	list_t* tmpnode = first;
	if (first != node && first != NULL) {
		list_t* tmpnode = first;
		while (tmpnode->next != node && tmpnode->next != NULL)
		{
			tmpnode = tmpnode->next;
		}
		last = tmpnode;
		last->next = NULL;
	}

	if (first == node) {
		first = NULL;
	}

	delete node;
	return data;
}

template<typename T>
void ReverseList<T>::push_front(T data)
{
	list_t* node = new list_t;
	node->data = data;

	if (last == NULL) {
		last = node;
	}

	if (first != NULL) {
		node->next = first;
	}

	first = node;
}

template<typename T>
T ReverseList<T>::pop_front(void)
{
	if (first == NULL) {
		return NULL;
	}

	list_t* node = first;
	T data = node->data;

	if (node->next != NULL) {
		first = node->next;
	}

	if (last == node) {
		last = NULL;
	}

	delete node;
	return data;
}

template<typename T>
void ReverseList<T>::print(void)
{
	list_t* node = first;
	while (node != NULL)
	{
		std::cout << node->data << " ";
		node = node->next;
	}

	std::cout << std::endl;
}

template<typename T>
void ReverseList<T>::reverse(void)
{

	list_t* prevptr = NULL;
	list_t* nextptr = first;

	list_t* tmp = first;
	first = last;
	last = tmp;

	while (nextptr != NULL)
	{
		list_t* tmp = nextptr->next;
		nextptr->next = prevptr;
		prevptr = nextptr;
		nextptr = tmp;
	}
}
