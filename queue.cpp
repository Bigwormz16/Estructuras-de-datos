#include <iostream>
#include <assert.h>
using namespace std;

template <class Type>
class queueType{
private:
	int maxQueueSize;
	int count;
	int queueFront;
	int queueRear;
public:
	Type *list;
	bool isEmptyQueue() const;
	bool isFullQueue() const;
	void initializeQueue();
	Type front() const;
	Type back() const;
	void addQueue(const Type& queueElement);
	queueType(int queueSize = 100);
	~queueType();
};
template <class Type>
bool queueType<Type>::isEmptyQueue() const{
	return (count == 0);
}

template <class Type>
bool queueType<Type>::isFullQueue() const{
	return (count == maxQueueSize);
}

template <class Type>
void queueType<Type>::initializeQueue(){
	queueFront = 0;
	queueRear = maxQueueSize - 1;
	count = 0;
}

template <class Type>
Type queueType<Type>::front() const{
	assert(!isEmptyQueue());
	return list[queueFront];
}

template <class Type>
Type queueType<Type>::back() const{
	assert(!isEmptyQueue());
	return list[queueRear];
}

template <class Type>
void queueType<Type>::addQueue(const Type& newElement){
	if (!isFullQueue()){
		queueRear = (queueRear + 1) % maxQueueSize; 
		count++;
		list[queueRear] = newElement;
	}
	else
		cout << "Cannot add to a full queue." << endl;
}

template <class Type>
queueType<Type>::queueType(int queueSize){
	if (queueSize <= 0){
		maxQueueSize = 100;
	}
	else
		maxQueueSize = queueSize; 
	queueFront = 0;
	queueRear = maxQueueSize - 1; 
	count = 0;
	list = new Type[maxQueueSize]; 
} 

template <class Type>
queueType<Type>::~queueType(){
	delete [] list;
}

template<class Type>
queueType<Type>& operator+(const queueType<Type>A , const queueType<Type>B){
	queueType<Type>Temp(100);
	for(int i=0;i<50;i++){
		Temp.addQueue(A.list[i]);
	}
	for(int j=0;j<50;j++){
		Temp.addQueue(B.list[j]);
	}
	return Temp;
}
template<class Type>
queueType<Type>& operator-(const queueType<Type>A , const queueType<Type>B){
	queueType<Type>Temp(100);
	for(int i=0;i<50;i++){
		int j=0;
		if(A.list[i]!=B.list[j]){
		Temp.addQueue(A.list[i]);
		}
		j++;
	}
	return Temp;
}

int main(){
	queueType<int>cola(100);
	cola.initializeQueue();
	cola.addQueue(12);
	queueType<int>cola2(100);
	cola2.initializeQueue();
	cola2.addQueue(13);
	queueType<int>cola3(100);
	cola3 = cola+cola2;
	
	queueType<int> cola4(50);
	cola4.initializeQueue();
	cola4.addQueue(665);
	queueType<int> cola5(50);
	cola5.initializeQueue();
	cola5.addQueue(2131);
	queueType<int> cola6(100);
	cola4=cola5-cola6;
	return 0;
}
