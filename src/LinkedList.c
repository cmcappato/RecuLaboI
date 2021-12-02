#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

LinkedList* ll_newLinkedList(void)
{
    LinkedList* this; //Puntero a LL
    this = (LinkedList*)malloc(sizeof(LinkedList)); //Asigno espacio en memoria con malloc

    if(this != NULL) //Verifica que sea distinto de NULL para indicar que asigno espacio en memoria correctamente
    {
        this -> size = 0; //Inicializo en 0
        this -> pFirstNode = NULL; //Inicializo en NULL
    }

    return this;
}

int ll_len(LinkedList* this)
{
    int returnAux = -1; //Variable de retorno

    if (this != NULL) //Verifico que sea distinto de NULL
    {
        returnAux = this -> size; //Le asigno a la variable returnAux el valor asociado a la LL
    }

    return returnAux; //Retorna el valor de la variable
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
    Node* pNode = NULL; //Variable de retorno

    if(this != NULL) //Verifico que this sea distinto de NULL
    {
        if (nodeIndex >= 0 && nodeIndex < ll_len(this))
        {
            pNode = this -> pFirstNode;

            for(int i = 0; i < nodeIndex; i++) //Recorro hasta que encuentre el indice a buscar
            {
                pNode = pNode -> pNextNode; //Le asigno el valor del siguiente nodo
            }
        }
    }

    return pNode;
}

Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
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
    int returnAux = -1; //Variable de retorno
    Node* pNewNode = malloc(sizeof(Node)); //Creo espacio en memoria para un nuevo nodo
    Node* pActualNode = NULL; //Inicializo el nuevo nodo en NULL
    pNewNode -> pElement = pElement;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this) && pNewNode!= NULL)
    {
        if(nodeIndex == 0)
        {
            pNewNode -> pNextNode = this -> pFirstNode;
            this -> pFirstNode = pNewNode;
            this -> size ++;
            returnAux = 0;
        }
        else
        {
            pActualNode = getNode(this, nodeIndex - 1);
            pNewNode -> pNextNode = pActualNode -> pNextNode;
            pActualNode -> pNextNode = pNewNode;
            this -> size ++;
            returnAux = 0;
        }
    }

    return returnAux;
}

int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1; //Variable de retorno

    if (this != NULL) //Verifico que this sea distinto de NULL
    {
        returnAux = addNode(this, this -> size, pElement);
    }

    return returnAux;
}

void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL; //Variable de retorno
    Node* pNode;

    if(this != NULL) //Verifico que this sea distinto de NULL
    {
        if (index >= 0 && index < ll_len(this))//Verifico que this sea distinto de NULL
        {
            pNode = getNode(this, index);
            returnAux = pNode -> pElement;
        }
    }

    return returnAux;
}

int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1; //Variable de retorno
    Node* pNewNode;

    if(this != NULL && index >= 0 && index < ll_len(this)) //Verifico que this sea distinto de NULL
    {
        pNewNode = getNode(this, index);
        if(pNewNode != NULL)
        {
            pNewNode -> pElement = pElement;
            returnAux = 0;
        }
    }

    return returnAux;
}

int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1; //Variable de retorno
    Node* pNodeA = NULL;
    Node* pNodeB = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this) && ll_len(this) > 0)
    {
        if(index != 0 && index != (ll_len(this)))
        {
            pNodeB = getNode(this, (index - 1));
            pNodeA = getNode(this, index);
            pNodeB -> pNextNode = pNodeA -> pNextNode;
            free(pNodeA);
        }
        else
        {
            if (index == 0)
            {
                pNodeA = getNode(this, index);
                this -> pFirstNode = pNodeA -> pNextNode;
                free(pNodeA);
            }
            else
            {
                if (index!=0 && index == (ll_len(this)))
                {
                    free(pNodeA);
                }
            }
        }
        this -> size--;
        returnAux = 0;
    }

    return returnAux;
}

int ll_clear(LinkedList* this)
{
    int returnAux = -1; //Variable de retorno

    if(this != NULL) //Verifico que sea distinto de NULL
    {
        for(int i = ll_len(this); i >= 0; i--)
        {
            ll_remove(this, i - 1);
        }
        returnAux = 0;
    }

    return returnAux;
}

int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1; //Variable de retorno

    if(this != NULL) //Verifico que sea distinto de NULL
    {
        ll_clear(this);
        free(this);
        returnAux = 0;
    }

    return returnAux;
}

int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1; //Variable de retorno
    Node* pNodeAux = NULL;

    if(this != NULL) //Verifico que sea distinto de NULL
    {
        for (int i = 0; i < ll_len(this); i++)
        {
            pNodeAux = getNode(this, i);
            if (pNodeAux -> pElement == pElement)
            {
                returnAux = i;
                break;
            }
        }
    }

    return returnAux;
}

int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1; //Variable de retorno

    if(this != NULL) //Verifico que sea distinto de NULL
    {
        if(ll_len(this) > 0)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }

    return returnAux;
}

int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1; //Variable de retorno

    if (this != NULL && index >= 0 && index <= ll_len(this))
    {
        returnAux = addNode(this, index, pElement);
    }

    return returnAux;
}

void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL; //Variable de retorno

    if (this != NULL && index >= 0 && index <= ll_len(this))
    {
        returnAux = ll_get(this, index);
        if(returnAux != NULL)
        {
            ll_remove(this, index);
        }
    }

    return returnAux;
}

int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1; //Variable de retorno
    Node* pNodeAux = NULL;

    if(this != NULL) //Verifico que sea distinto de NULL
    {
        returnAux = 0;
        for(int i = 0; i < ll_len(this); i++)
        {
            pNodeAux = getNode(this, i);
            if(pNodeAux -> pElement == pElement)
            {
                returnAux = 1;
                break;
            }
        }
    }

    return returnAux;
}

int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1; //Variable de retorno
    void* pAuxiliar = NULL;
    int indice;

    if (this != NULL && this2 != NULL)
    {
        returnAux = 1;
        for(int i = 0; i < ll_len(this2); i++)
        {
            pAuxiliar = ll_get(this, i);
            indice = ll_contains(this2, pAuxiliar);
            if (indice == 0)
            {
                returnAux = 0;
                break;
            }
        }
    }

    return returnAux;
}

LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL; //Variable de retorno
    void* pAuxiliar = NULL;

    if(this != NULL && from >= 0 && from < ll_len(this) && to >= 0 && to <= ll_len(this))
    {
        cloneArray = ll_newLinkedList();
        for (int i = from; i < to; i++)
        {
            pAuxiliar = ll_get(this, i);
            ll_add(cloneArray, pAuxiliar);
        }
    }

    return cloneArray;
}

LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL; //Variable de retorno

    if(this != NULL) //Verifico que sea distinto de NULL
    {
        cloneArray = ll_subList(this, 0, ll_len(this));
    }

    return cloneArray;
}

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1; //Variable de retorno
    void* pElementA = NULL;
    void* pElementB = NULL;
    void* pAuxiliar = NULL;

    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
        for(int i = 0; i < ll_len(this) - 1; i++)
        {
            pElementA = ll_get(this, i);
            for(int j = i + 1; j < ll_len(this); j++)
            {
                pElementB = ll_get(this, j);
                if(order == 0)
                {
                    if(pFunc(pElementA, pElementB) < 0)
                    {
                        pAuxiliar = pElementB;
                        pElementB = pElementA;
                        pElementA = pAuxiliar;
                    }
                }
                else
                {
                    if(pFunc(pElementA, pElementB) > 0)
                    {
                        pAuxiliar = pElementB;
                        pElementB = pElementA;
                        pElementA = pAuxiliar;
                    }
                }
                ll_set(this, i, pElementA);
                ll_set(this, j, pElementB);
            }
        }
        returnAux = 0;
    }

    return returnAux;
}

int ll_map(LinkedList* this, void (*pFunc)(void*))
{
    int retorno = -1;
    void* pElement = NULL;

    if(this != NULL && pFunc != NULL)
    {
        for(int i = 0; i < ll_len(this); i++)
        {
            pElement = ll_get(this, i);
            pFunc(pElement);
            retorno = 0;
        }
    }
    return retorno;
}

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* this2 = NULL; //Variable de retorno
    void* pElement = NULL;

    if(this != NULL && pFunc != NULL && !ll_isEmpty(this))
    {
        this2 = ll_newLinkedList();
        for(int i = 0; i < ll_len(this); i++)
        {
            pElement = ll_get(this, i);
            if(pFunc(pElement))
            {
                ll_add(this2, pElement);
            }
        }
    }

    return this2;
}
