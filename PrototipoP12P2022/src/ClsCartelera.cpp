#include "ClsCartelera.h"

//librerias
#include<conio.h>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cstring>

using namespace std;

ClsCartelera::ClsCartelera(int valorClave, string txtNombre, string nPrecio, string nCodigo)
{
    mestablecerClave(valorClave);
    mestablecerNombreCartelera(txtNombre);
    mestablecerPrecio(nPrecio);
    mestablecerCodigo(nCodigo);
}

int ClsCartelera::mobtenerClave() const
{
    return m_iclaveCartelera;
}

void ClsCartelera::mestablecerClave (int ienteroClave)
{
    m_iclaveCartelera = ienteroClave;
}

//Funciones del nombre del empleado
string ClsCartelera::mobtenerNombreCartelera() const
{
    return m_snombreCartelera;
}

void ClsCartelera::mestablecerNombreCartelera( string scadenaNombreCartelera )
{
   const char *svalorNombreCartelera = scadenaNombreCartelera.data();
   int ilongitud = strlen( svalorNombreCartelera );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_snombreCartelera, svalorNombreCartelera, ilongitud );

   m_snombreCartelera[ ilongitud ] = '\0';

}

string ClsCartelera::mobtenerPrecio() const
{
    return m_sPrecio;
}

void ClsCartelera::mestablecerPrecio( string scadenaPrecio )
{
   const char *svalorPrecio = scadenaPrecio.data();
   int ilongitud = strlen( svalorPrecio );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sPrecio, svalorPrecio, ilongitud );

   m_sPrecio[ ilongitud ] = '\0';

}

string ClsCartelera::mobtenerCodigo() const
{
    return m_sCodigo;
}

void ClsCartelera::mestablecerCodigo( string scadenaCodigo )
{
   const char *svalorCodigo = scadenaCodigo.data();
   int ilongitud = strlen( svalorCodigo );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sCodigo, svalorCodigo, ilongitud );

   m_sCodigo[ ilongitud ] = '\0';

}

ClsCartelera::~ClsCartelera()
{
    //dtor
}
