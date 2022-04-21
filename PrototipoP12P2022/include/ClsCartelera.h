#ifndef CLSCARTELERA_H
#define CLSCARTELERA_H

#include<string>
#include<iostream>

using std::string;

class ClsCartelera
{
    public:
        ClsCartelera(int = 0, string = "", string = "", string = "");

        void mestablecerClave( int ) ;
        int mobtenerClave() const;

        void mestablecerNombreCartelera( string );
        string mobtenerNombreCartelera() const;

        void mestablecerPrecio( string );
        string mobtenerPrecio() const;

        void mestablecerCodigo( string );
        string mobtenerCodigo() const;

        virtual ~ClsCartelera();

    protected:

    private:
        int m_iclaveCartelera;
        char m_snombreCartelera[ 20 ];
        char m_sPrecio[ 20 ];
        char m_sCodigo[ 20 ];
};

#endif // CLSCARTELERA_H
