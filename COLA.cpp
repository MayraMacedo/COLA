#include <iostream>
using namespace std;

class nodo
{
  private:
    int valor;
    nodo *siguiente;
    friend class cola;
  public:
    nodo(int v, nodo *sig = NULL)
    {
        valor = v;
        siguiente = sig;
    }
};

typedef nodo *pnodo;

class cola
{
  private:
    pnodo primero, ultimo;

  public:
    cola() : primero(NULL), ultimo(NULL) {}
    void Anadir(int v);
    bool Vacia();
    int Leer();
    void Eliminar();
};

void cola::Anadir(int v)
{
    pnodo nuevo;
	nuevo = new nodo(v);
    /* Crear un nodo nuevo */
    /* Este sera el ultimo nodo, no debe tener siguiente */
    if (Vacia() )
    {
    	primero = nuevo;
	}
	else
    {
    	ultimo->siguiente = nuevo;
        //nuevo->siguiente=NULL;
    }
    ultimo = nuevo;
	


    if (!primero)
        primero = nuevo;
}

bool cola :: Vacia()
{
	return (primero == NULL)? true: false;
}
int cola::Leer()
{

    if (primero== NULL)
        return 0; 

    return primero->valor;
	
}
void cola::Eliminar()
{
	pnodo nodo;

    nodo = primero;
    cout<<"Elimino a " <<primero->valor<<endl;
    if (primero==ultimo)
    {
    	primero = NULL;
		ultimo = NULL;
	}
	else
	{
		primero = primero->siguiente;
	}

    delete nodo;
	
}

int main()
{
    cola Cola;

    Cola.Anadir(1);
    cout << "Anadir(1)" << endl;
    Cola.Anadir(2);
    cout << "Anadir(2)" << endl;
    cout << "Leer: " << Cola.Leer() << endl;
    Cola.Eliminar();
	cout << "Leer: " << Cola.Leer() << endl;
	Cola.Eliminar();
	cout << "Leer: " << Cola.Leer() << endl;	
	Cola.Anadir(3);
    cout << "Anadir(3)" << endl;

    return 0;
}
