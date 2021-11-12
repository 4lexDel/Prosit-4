#pragma once
#include<iostream>

template<typename T>
struct Element
{
    T value;
    Element* suivant;
};

template<typename T>
struct Liste
{
    Element<T>* premier;
};

template<typename T>
Liste<T>* initialiser()
{
    Liste<T>* liste = new Liste<T>;
    liste->premier = NULL;

    return liste;
}

template<typename T>
void ajouterElement(Liste<T>* liste, T nvValue, int i)
{
    Element<T>* nouveau = new Element<T>;
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->value = nvValue;
    nouveau->suivant = NULL;

    Element* elementActuel = liste->premier;

    for (int j = 0; i < j - 1; j++) {
        if (elementActuel->suivant == NULL) exit(EXIT_FAILURE);

        elementActuel = elementActuel->suivant;
    }
    nouveau->suivant = elementActuel->suivant;
    elementActuel->suivant = nouveau;
}
//void supprimerElement(Liste<T>** liste, int i);

template<typename T>
void ajouterElementDebut(Liste<T>* liste, T nvValue)
{
    Element<T>* nouveau = new Element<T>;
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->value = nvValue;
    nouveau->suivant = NULL;

    if (liste->premier != NULL) /* La liste n'est pas vide */
    {
        Element<T>* premierElement = liste->premier;

        liste->premier = nouveau;

        nouveau->suivant = premierElement;
    }
    else /* La liste est vide, notre élément est le premier directement*/
    {
        liste->premier = nouveau;
    }
}

template<typename T>
void supprimerElementDebut(Liste<T>* liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    /* On vérifie s'il y a quelque chose à supprimer */
    if (liste->premier != NULL)
    {
        Element<T>* elementDeliste = liste->premier;

        liste->premier = elementDeliste->suivant;
        delete elementDeliste;
    }
}

template<typename T>
void ajouterElementFin(Liste<T>* liste, T nvValue)
{
    Element<T>* nouveau = new Element<T>;
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->value = nvValue;
    nouveau->suivant = NULL;

    Element<T>* currentElement = liste->premier;

    if (currentElement != NULL) {
        while (currentElement->suivant != NULL)
        {
            currentElement = currentElement->suivant;
        }
        currentElement->suivant = nouveau;
    }
    else {
        liste->premier = nouveau;
    }
}

template<typename T>
void supprimerElementFin(Liste<T>* liste)
{
    Element<T>* nouveau = new Element<T>;
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element<T>* elementActuel = liste->premier;
    Element<T>* dernierElement = NULL;

    while (elementActuel->suivant->suivant != NULL)
    {
        elementActuel = elementActuel->suivant;
    }
    dernierElement = elementActuel->suivant->suivant;
    elementActuel->suivant = NULL;

    delete dernierElement;
}

template<typename T>
void afficherListe(Liste<T>* liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element<T>* element = liste->premier;

    while (element != NULL)
    {
        std::cout << element->value;
        element = element->suivant;
    }

    std::cout << std::endl;
}

template<typename T>
void afficherListeRecursive(Element<T>* currentElement)
{
    if (currentElement != NULL)
    {
        std::cout << currentElement->value;
        afficherListeRecursive(currentElement->suivant);
    }
}

template<typename T>
int compterElementListe(Liste<T>** liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int compteur = 0;

    Element<T>* element = liste->premier;

    while (element != NULL)
    {
        compteur++;
        element = element->suivant;
    }
    return compteur;
}
