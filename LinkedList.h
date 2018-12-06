
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;
template <class T>
struct lnode{
	T data;
	lnode* next;
};

template <class T>
class LinkedList{
	private:
		LinkedList(const LinkedList&)=delete; //copy constructor

	protected:
		int count;
		lnode<T> *head, *last;
	public:
		LinkedList();
		bool isEmpty();
		int length();
		T front();
		T back();
		T search(string&, T&);
		void inserFirst(T&);
		void inserLast(T&);
		void deleteNote(T&);
		void destroylist();
		LinkedList<T>& operator=(LinkedList<T>&);
		template <class U>
		friend ostream& operator<<(ostream& os, LinkedList<U>& list);
		~LinkedList();
};
template <class T>
LinkedList<T>::LinkedList(){
     head = last = NULL;
     count = 0;
}
template <class T>
bool LinkedList<T>::isEmpty(){
	return head==NULL;
}
template <class T>
int LinkedList<T>::length(){
	return count;
}
template <class T>
T LinkedList<T>::front(){
	return head->data;
}
template <class T>
T LinkedList<T>::back(){
	return last->data;
}
template <class T>
void LinkedList<T>::inserFirst(T& item){
	lnode<T> *temp = new lnode<T>;
	temp->data = item;
	temp->next = head;
	head = temp;
	count++;
	if(last==NULL) last = temp;

}
template <class T>
void LinkedList<T>::inserLast(T& item){
	lnode<T> *newlnode = new lnode<T>;
	newlnode->data = item;
	newlnode->next = NULL;
	if(head==NULL){
		head = last = newlnode;
	}else{
		last->next = newlnode;
		last = newlnode;
	}
	count++;
}

template <class T>
T LinkedList<T>::search(string& p, T& error)
{

  if(this->head == NULL)
    {
      return error;
    }
  lnode<T> *temp1 = new lnode<T>;

  temp1 = this->head;

  while(temp1 != NULL)
    {
      if(temp1->data == p)
	{
	return (temp1->data);
	}
      temp1 = temp1->next;
    }
  return error;

}

template <class T>
void LinkedList<T>::deleteNote(T& item){
	if(head == NULL)
		cerr<<"empty list";
	else{
		if(head->data == item){
			lnode<T>* p = head;
			head = head->next;
			delete p;
			count--;
			if(head==NULL) last = NULL;
		}else{
			lnode<T>* p = head;
			lnode<T>* q = p->next;
			while(q!=NULL && q->data != item){
				p = q;
				q = q->next;
			}
			if(q!=NULL){
				p->next = q->next;
				count--;
				if(last == q) last = p;
				delete q;
			}
		}
	}
}

template <class T>
void LinkedList<T>::destroylist(){
	lnode<T> *p;
	while(head != NULL){
		p = head;
		head = head->next;
		delete p;
	}
	last = NULL;
	count = 0;
}
template <class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& list){
	if(this!= &list){
		copylist(list);
	}
	return *this;
}
template <class T>
ostream& operator<<(ostream& os, LinkedList<T>& list){
	lnode<T> *p = list.head;
	while(p!= NULL){
		os<<p->data<<" "<<endl;
		p = p->next;
	}

}

template <class T>
LinkedList<T>::~LinkedList(){
	destroylist();
}


#endif /* LINKEDLIST_H */
