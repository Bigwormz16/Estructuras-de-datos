#include<iostream>
#include<assert.h>
using namespace std;
template <class Type>
struct nodeType{
	Type info;
	nodeType<Type> *link;
};
template <class Type>
class linkedListIterator{
public:
	linkedListIterator();
	linkedListIterator(nodeType<Type> *ptr);
	Type operator*();
	linkedListIterator<Type> operator++();
	bool operator==(const linkedListIterator<Type>& right) const;
	bool operator!=(const linkedListIterator<Type>& right) const;
private:
	nodeType<Type> *current;
};
template <class Type>
linkedListIterator<Type>::linkedListIterator(){
	current = NULL;
}
template <class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type> *ptr){
	current = ptr;
}
template <class Type>
Type linkedListIterator<Type>::operator*(){
	return current->info;
}
template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++(){
	current = current->link;
	return *this;
}
template <class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right) const{
	return (current == right.current);
}
template <class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right) const{
	return (current != right.current);
}
template <class Type>
class linkedListType{
public:
	void initializeList();
	bool isEmptyList() const;
	void print() const;
	int length() const;
	void destroyList();
	Type front() const;
	Type back() const;
	linkedListIterator<Type> begin();
	linkedListIterator<Type> end();
	linkedListType();
	~linkedListType();
	bool search(const Type& searchItem) const;
	void insertFirst(const Type& newItem);
	void insertLast(const Type& newItem);
	void deleteNode(const Type& deleteItem);
protected:
	int count;
	nodeType<Type> *first;
	nodeType<Type> *last;
};
template <class Type>
bool linkedListType<Type>::isEmptyList() const{
	return (first == NULL);
}
template <class Type>
linkedListType<Type>::linkedListType(){
	first = NULL;
	last = NULL;
	count = 0;
}
template <class Type>
void linkedListType<Type>::destroyList(){
	nodeType<Type> *temp;
	while (first != NULL){
		temp = first;
		first = first->link;
		delete temp;
	}
	last = NULL;
	count = 0;
}
template <class Type>
void linkedListType<Type>::initializeList(){
	destroyList(); 
}
template <class Type>
void linkedListType<Type>::print() const{
	nodeType<Type> *current; 
	current = first;
	while (current != NULL) {
		cout << current->info << " ";
		current = current->link;
	}
}
template <class Type>
int linkedListType<Type>::length() const{
	return count;
}
template <class Type>
Type linkedListType<Type>::front() const{
	assert(first != NULL);
	return first->info; 
}
template <class Type>
Type linkedListType<Type>::back() const{
	assert(last != NULL);
	return last->info;
}
template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin(){
	linkedListIterator<Type> temp(first);
	return temp;
}
template <class Type>
linkedListIterator<Type> linkedListType<Type>::end(){
	linkedListIterator<Type> temp(NULL);
	return temp;
}
template <class Type>
linkedListType<Type>::~linkedListType(){
	destroyList();
}
template <class Type>
bool linkedListType<Type>::search(const Type& searchItem) const{
	nodeType<Type> *current;
	bool found = false;
	current = first;
	while (current != NULL && !found)
		if (current->info == searchItem)
			found = true;
		else
			current = current->link;
	return found;
}
template <class Type>
void linkedListType<Type>::insertFirst(const Type& newItem){
	nodeType<Type> *newNode; 
	newNode = new nodeType<Type>; 
	newNode->info = newItem;
	newNode->link = first; 
	first = newNode;
	count++; 
	if (last == NULL)
		last = newNode;
}
template <class Type>
void linkedListType<Type>::insertLast(const Type& newItem){
	nodeType<Type> *newNode;
	newNode = new nodeType<Type>;
	newNode->info = newItem; 
	newNode->link = NULL; 
	if (first == NULL){
		first = newNode;
		last = newNode;
		count++;
	}
	else{
		last->link = newNode;
		last = newNode; 
		count++; 
	}
}
template <class Type>
void linkedListType<Type>::deleteNode(const Type& deleteItem){
	nodeType<Type> *current; 
	nodeType<Type> *trailCurrent; 
	bool found;
	if (first == NULL) 
		cout << "Cannot delete from an empty list."
		<< endl;
	else{
		if (first->info == deleteItem) {
			current = first;
			first = first->link;
			count--;
			if (first == NULL)
				last = NULL;
			delete current;
		}
		else {
			found = false;
			trailCurrent = first; 
			current = first->link; 
			while (current != NULL && !found){
				if (current->info != deleteItem){
					trailCurrent = current;
					current = current-> link;
				}else
					found = true;
			}
			if (found){
				trailCurrent->link = current->link;
				count--;
				if (last == current) 
					last = trailCurrent; 
				delete current;
			}else
				cout << "The item to be deleted is not in "
				<< "the list." << endl;
		}
	}
}

template <class Type>
linkedListType<Type> operator+(const linkedListType <Type>A , const linkedListType <Type>B){
	linkedListType<Type>Temp;
	Temp.initializeList();
	for(int i=0;i<A.length();i++){
		Temp.insertFirst(A.front());
		A.deleteNode(A.front());
	}
	for(int j=0;j<B.length();j++){
		Temp.insertFirst(B.front());
		B.deleteNode(B.front());
	}
	return Temp;
}
template <class Type>
linkedListType<Type> operator-(const linkedListType <Type>A , const linkedListType <Type>B){
	linkedListType<Type>Temp;
	Temp.initializeList();
	for(int i=0;i<A.length();i++){
		if( A.front() != B.front() ){
			Temp.insertFirst(A.front());
		    A.deleteNode(A.front());
		    B.deleteNode(B.front());
		}
	}
	return Temp;
}
int main(){
	linkedListType<int> lista;
	lista.initializeList();
	lista.insertFirst(10);
	lista.insertFirst(102);
	lista.insertFirst(101);
	lista.print();
	cout<<endl;
	cout<<"numero de elemetos de la lista son :"<<lista.length()<<endl;
	linkedListType<int> lista2;
	lista2.initializeList();
	lista2.insertFirst(104);
	lista2.insertFirst(107);
	lista2.insertFirst(666);
	lista2.print();
	cout<<endl;
	cout<<"numero de elemetos de la lista son :"<<lista2.length()<<endl;
	linkedListType<int> lista3;
	lista3.initializeList();
	lista3=lista+lista2;
	
	linkedListType<int> lista4;
	lista4.initializeList();
	lista4.insertFirst(1021);
	lista4.insertFirst(12213);
	lista4.insertFirst(31313);
	
	linkedListType<int> lista5;
	lista5.initializeList();
	lista5.insertFirst(1021);
	lista5.insertFirst(534543);
	lista5.insertFirst(634564);
	
	linkedListType<int> lista6;
	lista6.initializeList();
	lista6=lista4-lista5;
	
	return 0;
}
