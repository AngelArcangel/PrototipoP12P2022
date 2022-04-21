#include "ClsLogin.h"

//librerias
#include<conio.h>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cstring>

using namespace std;
ClsLogin::ClsLogin(int ivalorIngreso, string svalorUsuario)
{
    mestablecerIngreso(ivalorIngreso);
    mestablecernombreUsuario(svalorUsuario);
}

int ClsLogin::mobtenerIngreso() const
{
    return m_iingresoUsuario;
}

void ClsLogin::mestablecerIngreso (int iingreso)
{
    m_iingresoUsuario = iingreso;
}

string ClsLogin::mobtenernombreUsuario() const
{
    return m_snombreUsuario;
}

void ClsLogin::mestablecernombreUsuario( string scadenaUsuario )
{
   const char *svalorUsuario = scadenaUsuario.data();
   int ilongitud = strlen( svalorUsuario );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_snombreUsuario, svalorUsuario, ilongitud );

   m_snombreUsuario[ ilongitud ] = '\0';

}

ClsLogin::~ClsLogin()
{
    //dtor
}
