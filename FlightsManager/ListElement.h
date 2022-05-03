#pragma once

/*Klasa implementuj�ca element listy*/
template<typename T>
class ListElement
{
private:
	T value;

public:
	ListElement<T>* pNext;
	ListElement<T>* pPrev;

	T GetValue();
	bool SetValue(T);
	ListElement();
	ListElement(T);
};

/*Getter warto�ci elementu*/
template<typename T> T ListElement<T>::GetValue()
{
	return this->value;
}

/*Setter warto�ci elementu*/
template<typename T> bool ListElement<T>::SetValue(T valueP)
{
	this->value = valueP;
	return true;
}

/*Konstruktor*/
template<typename T> ListElement<T>::ListElement()
{
	pPrev = nullptr;
	pNext = nullptr;
}

/*Konstruktor z zainicjowaniem warto�ci elementu*/
template<typename T> ListElement<T>::ListElement(T valueP)
{
	pPrev = nullptr;
	pNext = nullptr;

	this->value = valueP;
}

