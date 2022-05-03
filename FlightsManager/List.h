#pragma once
#include <memory>
#include <iterator>

#include "ListElement.h"

/*Klasa implementuj¹ca liste dwukierunkow¹*/
template<typename T>
class List
{
private:
	ListElement<T>* element;

public:

	/*Getter do wartoœci wêz³a listy*/
	ListElement<T> GetElement();

	/*Setter wartoœci wez³a listy*/
	bool SetElement(ListElement<T>);

	/*Konstruktor*/
	List();

	/*Konstruktor z inicjacj¹ pierwszego elementu*/
	List(ListElement<T>);

	~List();

	/*Dodanie elementu na koniec listy*/
	bool PushBack(ListElement<T>);

	/*Dodanie elementu na poczatek listy*/
	bool PushFront(ListElement<T>);

	/*Usuniêcie elementu z koñca listy*/
	bool PopFront();

	/*Dodanie elemntu na pocz¹tek listy*/
	bool PopBack();

	/*Uzyskanie wskaŸnika pierwszego elementu listy*/
	ListElement<T>* Front();

	/*Uzyskanie wskaŸnikaostatniego elementu listy*/
	ListElement<T>* Back();

	/*Sprawdzenie czy llista jest pusta*/
	bool Empty();

	/*Zwrócenie rozmiaru listy*/
	size_t Size();

	/*Usuniecie zawartoœci listy*/
	bool Erase();
};

template<typename T> ListElement<T> List<T>::GetElement()
{
	return *(this->element);
}

template<typename T> bool List<T>::SetElement(ListElement<T> elementP)
{
	*(this->element) = elementP;

	return true;
}

template<typename T> List<T>::List()
{
	element = nullptr;
}

template<typename T> List<T>::~List()
{
	this->Erase();
}

template<typename T> List<T>::List(ListElement<T> elementP)
{
	this->element = new ListElement<T>(elementP);
}

template<typename T> bool List<T>::PushBack(ListElement<T> elementP)
{

	if (this->element == nullptr)
	{
		this->element = new ListElement<T>(elementP);
	}
	else
	{
		ListElement<T>* pHeadIt = this->element;

		while (pHeadIt->pNext != nullptr)
		{
			pHeadIt = pHeadIt->pNext;
		}

		pHeadIt->pNext = new ListElement<T>(elementP);
		pHeadIt->pNext->pPrev = pHeadIt;
	}	

	return true;
}

template<typename T> bool List<T>::PushFront(ListElement<T> elementP)
{
	if (this->element == nullptr)
	{
		this->element = new ListElement<T>(elementP);
	}
	else
	{
		ListElement<T>* pElementP = new ListElement<T>(elementP);
		pElementP->pNext = this->element;
		this->element = pElementP;
		this->element->pNext->pPrev = this->element;
	}

	return true;
}

template<typename T> bool List<T>::PopBack()
{
	if (this == nullptr)
	{
		return true;
	}
	else
	{
		ListElement<T>* pHeadIt = this->element;

		while (pHeadIt->pNext != nullptr)
		{
			pHeadIt = pHeadIt->pNext;
		}


		if (pHeadIt->pPrev != nullptr)
		{
			pHeadIt->pPrev->pNext = nullptr;
		}

		delete pHeadIt;
		pHeadIt = nullptr;

		return true;
	}
}

template<typename T> bool List<T>::PopFront()
{
	if (this == nullptr)
	{
		return false;
	}
	else
	{
		if (this->element == nullptr)
		{
			delete this->element;
			this->element = nullptr;
		}
		else
		{
			ListElement<T>* pHeadIt = this->element;
			this->element = this->element->pNext;
			this->element->pPrev = nullptr;
			delete pHeadIt;
			pHeadIt = nullptr;
		}

		return true;
	}
}

template<typename T>  ListElement<T>* List<T>::Front()
{
	return this->element;
}

template<typename T>  ListElement<T>* List<T>::Back()
{
	if (this->element == nullptr)
	{
		return nullptr;
	}
	else
	{
		ListElement<T>* pHeadIt = this->element;

		while (pHeadIt->pNext != nullptr)
		{
			pHeadIt = pHeadIt->pNext;
		}
		
		return pHeadIt;
	}

	return nullptr;
}

template<typename T> bool List<T>::Empty()
{
	if (this->element == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T> size_t List<T>::Size()
{
	if (this->element == nullptr)
	{
		return 0;
	}
	else
	{
		size_t sizeTemp = 0;

		ListElement<T>* tempList = this;

		while (tempList != nullptr)
		{
			sizeTemp++;
			tempList = tempList->pNext;
		}

		return sizeTemp;
	}

	return 0;
}

template<typename T> bool List<T>::Erase()
{
	while (this->Empty())
	{
		ListElement<T>* pHeadIt = this->element;

		while (pHeadIt->pNext != nullptr)
		{
			pHeadIt = pHeadIt->pNext;
		}

		delete pHeadIt;
		pHeadIt = nullptr;
	}

	return true;
}