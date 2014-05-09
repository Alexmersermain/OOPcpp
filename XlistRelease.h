#if !defined( XlistRelease )
#define XlistRelease
#include "XlistHead.h"
using namespace std;

//------------------isEmpty--------------------------------//�������� �� ������� ������
template<class TYPE>
bool Xlist<TYPE>::isEmpty() 
{
	if ( this->head != NULL ) return false; else return true; 
}
//--------------------addItemF--------------------------//���������� ������ � ������ ������
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
//-------------------addItemB-----------------------------//���������� ������ � �����
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
//-----------------------removeB--------------------------//�������� ���������� ��������
template<class TYPE>
void Xlist<TYPE>::removeB() //�������� ���������� ��������
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
//-------------------removeF-------------------------------//�������� ������� ��������
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
//-----------------getF-----------------------------------//����� ������� �������� ������
template<class TYPE>
TYPE& Xlist<TYPE>::getF() 
{
	if ( !this->isEmpty() ) return head->data; else { cout<<"Wrong act! Xlist is Empty"<<endl; exit(1); return head->data; } 
}
//------------------getB--------------------------------//����� ���������� �������� ������
template<class TYPE>
TYPE& Xlist<TYPE>::getB() 
{
	if ( !this->isEmpty() ) return temp->data; else { cout<<"Wrong act! Xlist is Empty"<<endl; exit(1); return head->data; } 
}
//-----------------lookF-----------------------------------//����� ���� ������
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
//-----------------lookB-----------------------------------//����� ���� ������
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
//-----------------getCount---------------------------------//�������� ����� ���������
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
//-----------------display---------------------------------//����� ���� ������ � ������
template<class TYPE>
void Xlist<TYPE>::display() 
{
	cout<<"\n-into Xlist "<<this->getCount()<<" items;"<<endl;
	this->lookF();
}
//-----------------displayB---------------------------------//����� ���� ������ � �����
template<class TYPE>
void Xlist<TYPE>::displayB() 
{
	cout<<"\n-into Xlist "<<this->getCount()<<" items;"<<endl;
	this->lookB();
}
//-----------------clean---------------------------------//�������� ������
template<class TYPE>
void Xlist<TYPE>::clean() 
{
	while( !this->isEmpty() ) this->removeB();
	cout<<"Xlist has been cleaned"<<endl;
}
//-----------------����������---------------------------------
template<class TYPE>
Xlist<TYPE>::~Xlist() 
{
	this->clean();
}
#endif