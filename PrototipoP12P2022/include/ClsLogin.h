#ifndef CLSLOGIN_H
#define CLSLOGIN_H

//librerias
#include<string>
#include<iostream>

using std::string;

class ClsLogin
{
    public:
        ClsLogin(int = 0, string = "");

        void mestablecerIngreso( int ) ;
        int mobtenerIngreso() const;

        void mestablecernombreUsuario( string );
        string mobtenernombreUsuario() const;

        virtual ~ClsLogin();

    protected:

    private:
        int m_iingresoUsuario;
        char m_snombreUsuario[ 20 ];
};

#endif // CLSLOGIN_H
