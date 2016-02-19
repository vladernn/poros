/*
 * TPoro.cpp
 *
 *  Created on: 17 de feb. de 2016
 *      Author: vladernn
 */
#include "TPoro.h"

TPoro::TPoro() {
	color= NULL; // preguntar por que no va el NULL :(
	x=0;
	y=0;
	volumen=0;
}
TPoro::TPoro(int x ,int y,double vol)
{
	this->x=x;
	this->y=y;
	this->volumen=vol;
	color=NULL;
}
TPoro::TPoro(int x,int y,double vol,char* col)
{
	this->x=x;
	this->y=y;
	volumen=vol;
	color=col;
}
TPoro::TPoro(TPoro& poroX)
{
	x=poroX.x;
	y=poroX.y;
	volumen=poroX.volumen;
	color=poroX.color;
}
TPoro::~TPoro()
{
		x=y=0;
		volumen=0;
		delete[] color;
}
TPoro & operator=(TPoro & suPoro)
{
	TPoro miPoro=new TPoro(suPoro.PosicionX(),suPoro.PosicionY(),suPoro.Volumen(),suPoro.Color());
	return(miPoro);
}
bool TPoro:: operator==(TPoro & suPoro)
{
	bool sonIguales=false;
	if(suPoro.Color()!=NULL and this->Color()!=NULL)
	{

		if(strcmp(this->Color(),suPoro.Color())==0)
		{
			sonIguales=true;
		}
	}

	if(this->PosicionX()==suPoro.PosicionX() and this->PosicionY()==suPoro.PosicionY() and
			and this->Volumen()==suPoro.Volumen() and sonIguales)
	{
		return(true);
	}else
	{
		return(false);
	}
}
bool TPoro::operator!=(TPoro & suPoro)
{
	if(this==suPoro)
	{
		return(false);
	}else
	{
		return(true);
	}
}
int main()
{
	TPoro* miPoro=new TPoro(1,2,2.07,"amarillo");
	cout<<":"<<miPoro->Volumen()<<":"<<miPoro->Color()<<endl;
	return 0;
}

