#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
        this->pFirstNode = NULL;
        this->size = 0;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	int returnAux = -1;

	if(this != NULL && this->size >= 0)
	{
		returnAux = this->size;
	}

    return returnAux;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* nodo = NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		nodo = this->pFirstNode;
		for(int i = 0; i < nodeIndex; i++)
		{
			nodo = nodo->pNextNode;
		}
	}

    return nodo;
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int exito = -1;
	Node* nodo = NULL;
	Node* auxNodo = NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)) // El nodeIndex es el ULTIMO o ALGUNO ya existente.
	{
		nodo = (Node*) malloc(sizeof(Node));
		if(nodo != NULL)
		{
			nodo->pElement = pElement;

			if(nodeIndex == 0) // Si se quiere agregar al primer elemento, tengo que hacer un swap.
			{
				nodo->pNextNode = this->pFirstNode; // El primero pasa a ser el segundo.
				this->pFirstNode = nodo; // El nodo pasa a ser el primero.
			}
			else
			{
				auxNodo = getNode(this, nodeIndex - 1); // nodeIndex - 1 (si es igual al len) es el ultimo nodo, pero antes del for trae el firsNode.
				if(auxNodo != NULL)
				{
					nodo->pNextNode = auxNodo->pNextNode;
					auxNodo->pNextNode = nodo;
				}
			}

			this->size++;
			exito = 0;
		}

	}

    return exito;
}



int ll_add(LinkedList* this, void* pElement)
{
    int exito = -1;
    if(this != NULL)
    {
    	addNode(this, ll_len(this), pElement);
    	exito = 0;
    }
    return exito;
}


void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* node;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	node = getNode(this, index);
    	returnAux = node->pElement;
    }
    return returnAux;
}


int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* node;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	node = getNode(this, index);
    	node->pElement = pElement;
    	returnAux = 0;
    }

    return returnAux;
}


int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* auxNode;
    Node* auxNode2;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	if(index == 0)
    	{
    		auxNode = this->pFirstNode;
    		this->pFirstNode = getNode(this, 1);
    	}
    	else
    	{
    		auxNode = getNode(this, index);
    		auxNode2 = getNode(this, index - 1);
    		auxNode2->pNextNode = auxNode->pNextNode;
    	}

    	this->size--;
    	free(auxNode);
    	returnAux = 0;
    }

    return returnAux;
}


int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    if(this !=NULL)
    {
    	for(int i = 0; i < ll_len(this); i++)
    	{
    		if(ll_remove(this, i) != 0){
    			returnAux = -1;
    			break;
    		}
    		else
    		{
    	    	returnAux = 0;
    		}
    	}
    }

    return returnAux;
}


int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL && ll_clear(this) == 0)
    {
    	free(this);
    	returnAux = 0;
    }
    return returnAux;
}


int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    void* auxElement;

    if(this != NULL)
    {
    	for(int i = 0; i < ll_len(this); i++)
    	{
    		auxElement = ll_get(this, i);
    		if(auxElement == pElement)
    		{
    			returnAux = i;
    		}
    	}
    }
    return returnAux;
}


int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = ll_len(this) ? 0 : 1;
    }

    return returnAux;
}


int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
    	returnAux = addNode(this, index, pElement);
    }

    return returnAux;
}


void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
    	returnAux = ll_get(this, index);
    	free(returnAux);
    	this->size--;
    }

    return returnAux;
}


int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = ll_indexOf(this, pElement) >= 0 ? 1 : 0;
    }

    return returnAux;
}


int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	int exito = -1;

	if(this != NULL && this2 != NULL)
	{
		exito = 1;
		for(int i = 0; i < ll_len(this2); i++)
		{
			if(!ll_contains(this, ll_get(this2, i)))
			{
				exito = 0;
				break;
			}
		}
	}

	return exito;
}


LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    Node* nodo;

    if(this != NULL && from >= 0 && to <= ll_len(this))
    {
    	cloneArray = ll_newLinkedList();
    	if(cloneArray != NULL)
    	{
        	for(int i = from; i < to; i++)
        	{
        		nodo = getNode(this, i);
        		addNode(cloneArray, i, nodo->pElement);
        	}
    	}

    }
    return cloneArray;
}


LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
    	cloneArray = ll_newLinkedList();
    	if(cloneArray != NULL)
    	{
    		cloneArray = ll_subList(this, 0 , ll_len(this));
    	}
    }

    return cloneArray;
}


int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    void* auxI;
    void* auxJ;

    if(this != NULL && (order == 1 || order == 0) && pFunc != NULL)
    {
    	for(int i = 0; i < ll_len(this) - 1; i++)
    	{
    		for(int j = i + 1; j < ll_len(this); j++)
    		{
    			auxI = ll_get(this, i);
    			auxJ = ll_get(this, j);
    			if(((pFunc(auxI, auxJ) > 0) && order == 1) ||
    			   ((pFunc(auxI, auxJ) < 0) && order == 0))
    			{
    				ll_set(this, j, auxI);
    				ll_set(this, i, auxJ);
    				returnAux = 0;
    			}
    		}
    	}
    }
    return returnAux;
}

LinkedList* ll_map(LinkedList* this, void (*pFunc)(void* pElement))
{
	LinkedList* returnList = NULL;
	void* eElement;

	if(this != NULL && pFunc != NULL)
	{
		returnList = ll_newLinkedList();
		for(int i = 0; i < ll_len(this); i++)
		{
			eElement = ll_get(this, i);
			pFunc(eElement);
			ll_add(returnList, eElement);
		}
	}
	return returnList;
}

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void* pElemenet))
{
	LinkedList* newList = NULL;
	void* eElement;

	if(this != NULL && pFunc != NULL)
	{
		newList = ll_newLinkedList();
		if(newList != NULL)
		{
			for(int i = 0; i < ll_len(this); i++)
			{
				eElement = ll_get(this, i);
				if(eElement != NULL && pFunc(eElement) == 0)
				{
					ll_add(newList, eElement);
				}
			}
		}
	}

	return newList;
}

int ll_count(LinkedList* this, int (*pFunc)(void* pElemenet))
{
	int salida = 0;
	void* eElement;

	if(this != NULL && pFunc != NULL)
	{
		for(int i = 0; i < ll_len(this); i++)
		{
			eElement = ll_get(this, i);
			if(eElement != NULL)
				salida = salida + pFunc(eElement);
		}
	}
	return salida;
}
