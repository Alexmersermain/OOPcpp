#if !defined( XlistHead )
#define XlistHead

template<class TYPE>
struct link //������� ������
{
	TYPE data; //������� ������
	link * next; //��������� �� ��������� �������
	link * prev; // previous - ��������� �� ���������� �������
};

template<class TYPE>
class Xlist //������ ������
{
private:
	link<TYPE>* head; //��������� �� ������ ������� ������
	link<TYPE>* temp; //��������� �� ��������� ������� ������
	void lookF();
	void lookB();
public:
	Xlist(){ 
		head = NULL;
		temp = NULL; //������� ����������� �� ����� ������
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