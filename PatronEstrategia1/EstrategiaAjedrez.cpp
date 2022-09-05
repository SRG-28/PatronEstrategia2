
#include<iostream>
#include<sstream>
using namespace std;

class EstApertura {
	//Interfaz <Abstract>

public:
	virtual void tipoEstrategia() = 0;
	//virtual puro


};


class DefensaSiciliana : public EstApertura {
public:
	void tipoEstrategia() {
		cout << "Se utilizará la defensa Siciliana." << endl;
	}
};


class DefensaBerlinesa : public EstApertura {
public:
	void tipoEstrategia() {
		cout << "Se utilizará la defensa Berlinesa." << endl;
	}
};


class DefensaKaroCam : public EstApertura {
public:
	void tipoEstrategia() {
		cout << "Se utilizará la defensa Karo-Cam." << endl;
	}
};

//termina la herencia


class Jugador {
private:
	string nombre;
	EstApertura* ptr;
public:
	Jugador(string nombre);
	virtual ~Jugador();
	void setEstrategia(EstApertura* ptrA);
	void ejecutarEstrategia();
};

Jugador::Jugador(string nombre): nombre(nombre)
{
}

Jugador::~Jugador()
{
	//delete ptr;
}

void Jugador::setEstrategia(EstApertura* ptrA)
{
	this->ptr = ptrA;
}

void Jugador::ejecutarEstrategia()
{
	cout << "Yo con nombre: " << nombre << "  voy a";
	cout << "  desarrollar una estrategia de defensa.  ";
	ptr->tipoEstrategia();
}


int main() {
	cout << "Declarando y definiendo un jugador" << endl;
	Jugador* jug1 = new Jugador("Gaspar");
	//cout << "Declarar y definir una estrategia" << endl;
	EstApertura* ptr = new DefensaSiciliana();

	//vista para seleccionar alguna estrategia
	//despliega menu de estrategias 
	//el jug escoge la estrategia que gusta usar

	//vincular

	cout << "Ingresa el tipo de estrategia que va a a usar el jugador" << endl;
	//settear la estrategia
	jug1->setEstrategia(ptr);


	//ejecución de la estrategia
	jug1->ejecutarEstrategia();


	system("pause");

	delete jug1;
	delete ptr;
	return 0;
}
