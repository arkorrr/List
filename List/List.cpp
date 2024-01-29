#include <iostream>
using namespace std;
struct Element
{
	//Данные
	char data;
	//Адрес следующего элемента списка
	Element* Next;
};
//Односвязный список
class List
{
	//Адрес головного элемента списка
	Element* Head;
	//Адрес концевого элемента списка
	Element* Tail;
	//Количество элементов списка
	int Count;
public:
	//Конструктор
	List();
	//Деструктор
	~List();
	//Добавление элемента в список
	//(Новый элемент становится последним)
	void Add(char data);
	//Удаление элемента списка
	//(Удаляется головной элемент)
	void Del();
	//Удаление всего списка
	void DelAll();
	//Распечатка содержимого списка
	//(Распечатка начинается с головного элемента) 
	void Print();
	void PrintPos(char element);
	//Получение количества элементов,
	//находящихся в списке
	int GetCount();

	void AddHead(char data);
};
List::List()
{
	//Изначально список пуст
	Head = Tail = NULL;
	Count = 0;
}
List::~List()
{
	//Вызов функции удаления
	DelAll();
}
int List::GetCount()
{
	//Возвращаем количество элементов
	return Count;
}
void List::AddHead(char data)
{
	Element* temp = new Element;
	temp->data = data;
	temp->Next = Head;
	Head = temp;
	if (Tail == NULL) 
	{
		Tail = temp;
	}
}
void List::Add(char data)
{
	//создание нового элемента
	Element* temp = new Element;
	//заполнение данными
	temp->data = data;
	//следующий элемент отсутствует
	temp->Next = NULL;
	//новый элемент становится последним элементом списка
	//если он не первый добавленный
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	//новый элемент становится единственным
	//если он первый добавленный
	else {
		Head = Tail = temp;
	}
}
void List::Del()
{
	//запоминаем адрес головного элемента
	Element* temp = Head;
	//перебрасываем голову на следующий элемент
	Head = Head->Next;
	//удаляем бывший головной элемент
	delete temp;
}
void List::DelAll()
{
	//Пока еще есть элементы 
	while (Head != 0)
		//Удаляем элементы по одному
		Del();
}
void List::Print()
{
	//запоминаем адрес головного элемента
	Element* temp = Head;
	//Пока еще есть элементы
	while (temp != 0)
	{
		//Выводим данные
		cout << temp->data << " ";
		//Переходим на следующий элемент
		temp = temp->Next;
	}
	cout << "\n\n";
}

void List::PrintPos(char element)
{
	Element* temp = Head;
	int pos = 0;
	int count = 0;
	cout << "Search for a specific element in the list: " << element << endl;
	while (temp != 0)
	{
		pos += 1;
		if (temp->data == element)
		{
			count += 1;
			cout << "#" << count << " Location of this element in list = " << pos << endl;
		}
		temp = temp->Next;
	}
	if (count == 0)
	{
		cout << "A Specific element in the list is not found." << endl;
	}
}


//Тестовый пример
void main()
{
	//Создаем объект класса List
	List lst;
	//Тестовая строка
	char s[] = "Hello, World !!!";
	//Выводим строку
	cout << s << "\n\n";
	//Определяем длину строки
	int len = strlen(s);
	//Загоняем строку в список
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	lst.PrintPos('l');	
}

// Односвязный список — это совокупность нескольких объектов, каждый из которых представляет собой элемент 
// списка, состоящий из двух частей. Первая часть элемента — значение, которое он хранит, вторая — информация
// о следующем элементе списка.