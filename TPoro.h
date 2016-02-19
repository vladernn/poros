/*
 * TPoro.h
 *
 *  Created on: 17 de feb. de 2016
 *      Author: vladernn
 */

#ifndef TPORO_H_
#define TPORO_H_

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class TPoro {
private:
	// Coordenada x de la posición
	int x;
	// Coordenada y de la posición
	int y;
	// Volumen
	double volumen;
	// Color
	char* color;
public:
	// Constructor por defecto
	TPoro();
	// Constructor a partir de una posición y un volumen
	TPoro(int, int, double);
	// Constructor a partir de una posición, un volumen y un color
	TPoro(int, int, double, char *);
	// Constructor de copia
	TPoro(TPoro &);
	// Destructor
	~TPoro();

	// Sobrecarga del operador asignación
	TPoro & operator=(TPoro &);
	// Sobrecarga del operador igualdad
	bool operator==(TPoro &);
	// Sobrecarga del operador desigualdad
	bool operator!=(TPoro &);
	// Modifica la posición
	void Posicion(int x, int y){this->x=x;this->y=y;}
	// Modifica el volumen
	void Volumen(double vol){volumen=vol;}
	// Modifica el color
	void Color(char * col){color=col;}
	// Devuelve la coordenada x de la posición
	int PosicionX(){return(x);}
	// Devuelve la coordenada y de la posición
	int PosicionY(){return(y);}
	// Devuelve el volumen
	double Volumen(){return(volumen);}
	// Devuelve el color
	char * Color(){return(color);}
	// Devuelve cierto si el poro está vacío
	bool EsVacio();
};

#endif /* TPORO_H_ */
