#pragma once
#include <iostream>

template<typename T>
struct Element
{
    T value;
    Element* next;
};

template<typename T>
class List {

public:
    List() {
    }

    T get(int i) {
        Element<T>* currentElement = firstElement;

        for (int j = 0; j < i; j++) {
            if (currentElement->next == NULL) exit(EXIT_FAILURE);

            currentElement = currentElement->next;
        }
        return currentElement->value;
    }

    void add(T newValue, int i)
    {
        if (i == 0) addBegin(newValue);
        else {
            Element<T>* newElement = new Element<T>;

            newElement->value = newValue;
            newElement->next = NULL;

            Element<T>* currentElement = firstElement;

            for (int j = 0; j < i - 1; j++) {
                if (currentElement->next == NULL) exit(EXIT_FAILURE);

                currentElement = currentElement->next;
            }
            newElement->next = currentElement->next;
            currentElement->next = newElement;
        }
    }

    void addBegin(T newValue)
    {
        Element<T>* newElement = new Element<T>;

        newElement->value = newValue;
        newElement->next = NULL;

        if (firstElement != NULL) /* La liste n'est pas vide */
        {
            Element<T>* oldFirstElement = firstElement;

            firstElement = newElement;

            newElement->next = oldFirstElement;
        }
        else /* La liste est vide, notre élément est le premier directement*/
        {
            firstElement = newElement;
        }
    }

    void deleteBegin()
    {
        /* On vérifie s'il y a quelque chose à supprimer */
        if (firstElement != NULL)
        {
            Element<T>* oldFirstElement = firstElement;

            firstElement = oldFirstElement->next;       //Decalage

            delete oldFirstElement;
        }
    }

    void addEnd(T newValue)
    {
        Element<T>* newElement = new Element<T>;

        newElement->value = newValue;
        newElement->next = NULL;

        Element<T>* currentElement = firstElement;

        if (currentElement != NULL) {
            while (currentElement->next != NULL)
            {
                currentElement = currentElement->next;
            }
            currentElement->next = newElement;
        }
        else {
            firstElement = newElement;
        }
    }

    void deleteEnd()
    {
        Element<T>* newElement = new Element<T>;

        Element<T>* currentElement = firstElement;
        Element<T>* lastElement = NULL;

        while (currentElement->next->next != NULL)
        {
            currentElement = currentElement->next;
        }
        lastElement = currentElement->next->next;
        currentElement->next = NULL;

        delete lastElement;
    }

    void display()
    {
        Element<T>* element = firstElement;

        while (element != NULL)
        {
            std::cout << element->value << "->";
            element = element->next;
        }

        std::cout << "NULL" << std::endl;
    }

    int size()
    {
        int nb = 0;

        Element<T>* element = firstElement;

        while (element != NULL)
        {
            nb++;
            element = element->next;
        }
        return nb;
    }

    void clear() {
        Element<T>* element = firstElement;

        while (element != NULL)
        {
            Element<T>* elementToDelete = element;
            element = element->next;

            delete elementToDelete;
        }

        firstElement = NULL;
    }

    ~List() {
        clear();
    }

private:
    Element<T> *firstElement = NULL;
};
/*---------------------------------------------------------------------------------------------------------*/

//void supprimerElement(Liste<T>* liste, int i);




/*
template<typename T>
void afficherListeRecursive(Element<T>* currentElement)
{
    if (currentElement != NULL)
    {
        std::cout << currentElement->value;
        afficherListeRecursive(currentElement->next);
    }
}*/

