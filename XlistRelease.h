#if !defined( XlistRelease )
#define XlistRelease
#include "XlistHead.h"
using namespace std;

//------------------isEmpty--------------------------------//проверка на пустоту списка
template<class TYPE>
bool Xlist<TYPE>::isEmpty() 
{
	if ( this->head != NULL ) return false; else return true; 
}
//--------------------addItemF--------------------------//добавление данных с начала списка
template<class TYPE>
void Xlist<TYPE>::addItemF(TYPE d) 
{
	link<TYPE> * newlink = new link<TYPE>;
	newlink->data = d;
	if ( head == NULL ){
		head = newlink; 
		temp = head;
		newlink->next = NULL;
	} 
	else{ 
		head->prev = newlink;
		newlink->next = head;
		head = newlink;
	}
	newlink->prev = NULL;
}
//-------------------addItemB-----------------------------//добавление данных с конца
template<class TYPE>
void Xlist<TYPE>::addItemB(TYPE d) 
{
	link<TYPE> * newlink = new link<TYPE>;
	newlink->data = d;
	if ( head == NULL ){
		head = newlink; 
		temp = head;
		newlink->prev = NULL;
	} 
	else{ 
		temp->next = newlink;
		newlink->prev = temp;
		temp = newlink;
	}
	newlink->next = NULL;
}
//-----------------------removeB--------------------------//удаление последнего элемента
template<class TYPE>
void Xlist<TYPE>::removeB() //удаление последнего элемента
{
	if ( !this->isEmpty() ) {
		link<TYPE> * vs = new link<TYPE>;
		vs = temp;
		if ( vs->prev != NULL){
			temp=vs->prev;
			temp->next = NULL;
		}
		else { 
			this->head = NULL;
			temp=head;
		}
		//cout<<"\n element from Back: '"<<vs->data<<"' has been removed"<<endl;
		delete vs;
	} else cout<<"Xlist is Empty"<<endl;
}
//-------------------removeF-------------------------------//удаление первого элемента
template<class TYPE>
void Xlist<TYPE>::removeF() 
{
	if ( !this->isEmpty() ) {
		link<TYPE> * vs = new link<TYPE>;
		vs = head;
		if ( head->next != NULL ){
			head = vs->next;
			head->prev = NULL;
		}
		else { 
			this->head = NULL;
			temp=head;
		}
		//cout<<"\n element by Front: '"<<vs->data<<"' has been removed"<<endl;
		delete vs;
	} else cout<<"Xlist is Empty"<<endl;
}
//-----------------getF-----------------------------------//вывод первого элемента списка
template<class TYPE>
TYPE& Xlist<TYPE>::getF() 
{
	if ( !this->isEmpty() ) return head->data; else { cout<<"Wrong act! Xlist is Empty"<<endl; exit(1); return head->data; } 
}
//------------------getB--------------------------------//вывод последнего элемента списка
template<class TYPE>
TYPE& Xlist<TYPE>::getB() 
{
	if ( !this->isEmpty() ) return temp->data; else { cout<<"Wrong act! Xlist is Empty"<<endl; exit(1); return head->data; } 
}
//-----------------lookF-----------------------------------//вывод всех ссылок
template<class TYPE>
void Xlist<TYPE>::lookF()
{
	link<TYPE>* current = head; 
	while( current != NULL ) 
	{
		cout << current->data<<"\n"; 
		current = current->next; 
	}
	cout<<endl;
}
//-----------------lookB-----------------------------------//вывод всех ссылок
template<class TYPE>
void Xlist<TYPE>::lookB()
{
	link<TYPE>* current = temp; 
	while( current != NULL ) 
	{
		cout << current->data<<"\n"; 
		current = current->prev; 
	}
	cout<<endl;
}
//-----------------getCount---------------------------------//получить число элементов
template<class TYPE>
int Xlist<TYPE>::getCount() 
{
	link<TYPE>* current = head; 
	int count=0;
	while( current != NULL ) 
	{
		count++;
		current = current->next; 
	}
	return count;
}
//-----------------display---------------------------------//вывод всех ссылок с начала
template<class TYPE>
void Xlist<TYPE>::display() 
{
	cout<<"\n-into Xlist "<<this->getCount()<<" items;"<<endl;
	this->lookF();
}
//-----------------displayB---------------------------------//вывод всех ссылок с конца
template<class TYPE>
void Xlist<TYPE>::displayB() 
{
	cout<<"\n-into Xlist "<<this->getCount()<<" items;"<<endl;
	this->lookB();
}
//-----------------clean---------------------------------//очистить список
template<class TYPE>
void Xlist<TYPE>::clean() 
{
	while( !this->isEmpty() ) this->removeB();
	cout<<"Xlist has been cleaned"<<endl;
}
//-----------------Деструктор---------------------------------
template<class TYPE>
Xlist<TYPE>::~Xlist() 
{
	this->clean();
}
#endif