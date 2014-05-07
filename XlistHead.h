#if !defined( XlistHead )
#define XlistHead

template<class TYPE>
struct link //элемент списка
{
	TYPE data; //элемент данных
	link * next; //указатель на следующий элемент
	link * prev; // previous - указатель на предыдущий элемент
};

template<class TYPE>
class Xlist //список ссылок
{
private:
	link<TYPE>* head; //указатель на первый элемент списка
	link<TYPE>* temp; //указатель на последний элемент списка
	void lookF();
	void lookB();
public:
	Xlist(){ 
		head = NULL;
		temp = NULL; //элемент указывающий на конец списка
	}
	virtual ~Xlist();
	bool isEmpty();
	void addItemF(TYPE data);
	void addItemB(TYPE data);
	void removeF();
	void removeB();
	void display();
	void displayB();
	TYPE& getF();
	TYPE& getB();
	int getCount();
	void clean();
};
#endif