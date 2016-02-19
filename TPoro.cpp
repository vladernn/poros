/*
 * TPoro.cpp
 *
 *  Created on: 17 de feb. de 2016
 *      Author: vladernn
 */
#include "TPoro.h"

TPoro::TPoro() {
	color= NULL;
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
	for(unsigned int i=0;i<strlen(color);i++)
				putchar (tolower(color[i]));
}
TPoro::TPoro(TPoro &poroX)
{
	x=poroX.x;
	y=poroX.y;
	volumen=poroX.volumen;
	if(poroX.EsVacio()==false)
	{
		color=new char[strlen( poroX.color)+1];
		strcpy(color,poroX.color);
		for(unsigned int i=0;i<strlen(color);i++)
			putchar (tolower(color[i]));

	}else
	{
		color=NULL;
	}
}
TPoro::~TPoro()
{
		x=y=0;
		volumen=0;
		delete[] color;
}
TPoro& TPoro::operator=(TPoro & suPoro)
{
	return suPoro;
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

	if(this->PosicionX()==suPoro.PosicionX() && this->PosicionY()==suPoro.PosicionY()
			&& this->Volumen()==suPoro.Volumen() && sonIguales==true)
	{
		return(true);
	}else
	{
		return(false);
	}
}
bool TPoro::operator!=(TPoro & suPoro)
{
	if(*this==suPoro)
	{
		return(false);
	}else
	{
		return(true);
	}
}
bool TPoro::EsVacio()
{
	if(this->color==NULL and this->volumen==0 and this->x==0 and this->y==0)
	{
		return true;
	}else
	{
		return false;
	}

}
int main()
{
	TPoro miPoro(1,2,2.07,"Amarillo");
	cout<<":"<<miPoro.Volumen()<<":"<<miPoro.Color()<<endl;
	TPoro miPoro2(miPoro);
	cout<<":"<<miPoro2.Volumen()<<":"<<miPoro2.Color()<<endl;

	return 0;
}

