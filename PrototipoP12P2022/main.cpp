//Librerias
#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>

#include "ClsLogin.h"
#include "ClsCartelera.h"

using namespace std;

int obtenerClave( const char * const );
int obtenerUsuario( const char * const );
void crearArchivoUsuarios();
void nuevoUsuario( fstream& );
void mostrarCartelera();
void crearArchivoCartelera();
void agregarCartelera( fstream& );
void actualizarRegistroCartelera(fstream&);
void mostrarLineaCartelera( ostream&, const ClsCartelera & );
void eliminarRegistroCartelera( fstream& );
void consultarRegistroCartelera(fstream&);
void mostrarLineaPantallaCartelera(const ClsCartelera &);

int main()
{
    //VariablesMenus
    int imenuPrincipal;
    int menuLogin;
    int menuLoginMenu;
    int menuCartelera;

    //Variables Cartelera
    int m_iclaveCartelera=0;
    char m_snombreCartelera[0];
    char m_sPrecio[0];
    char m_sCodigo[0];

    //LOGIN
    char snombreUsuario[ 20 ];
    int isesion = 0;
    int a=1;
    int codigo;
    int codigoa=0;
    string accion="";
    string ingresoUsuario;


    do
    {
        system("cls");

        fstream archivoCartelera("RegistroCartelera.dat", ios::in | ios::out | ios::binary);

        if ( !archivoCartelera )
        {
            cerr << "No se pudo abrir el archivo." << endl;
            crearArchivoCartelera();
            cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
            exit ( 1 );
            exit( EXIT_FAILURE );
        }

        cout<<"Angel Roberto Agustin de Leon Hernandez / 9491-21-7527"<<endl;
        cout<<""<<endl;
        cout<<"-----------------------------------------"<<endl;
        cout<<"|---------BIENVENIDO A ARCACINE---------|"<<endl;
        cout<<"-----------------------------------------"<<endl;
        cout<<"1. CARTELERA"<<endl;
        cout<<"2. COMPRAR"<<endl;
        cout<<"3. RESERVAR"<<endl;
        cout<<"4. CONSULTAR"<<endl;
        cout<<"5. INICIAR SECION"<<endl;
        cout<<"0. EXIT"<<endl;

        cout<<"-------------------------------"<<endl;
        cout<<"OPCIONES A ESCOGER :     [1/2/3/4/5/0]"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"INGRESA TU OPCION : ";
        cin>>imenuPrincipal;

        switch(imenuPrincipal)
        {
            case 1:
                {
                    system("cls");
                    consultarRegistroCartelera(archivoCartelera);
                    getch();
                }
                break;

            case 2:
                {

                }
                break;

            case 3:
                {

                }
                break;

            case 4:
                {

                }
                break;

            case 5:
                {
                    do
                    {
                        system("cls");
                        fstream archivoUsuarios("RegistroUsuarios.dat", ios::in | ios::out | ios::binary);
                        if ( !archivoUsuarios )
                            {
                                cerr << "No se pudo abrir el archivo." << endl;
                                crearArchivoUsuarios();
                                cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                exit ( 0 );
                            }
                        cout<<"1. Iniciar sesion "<<endl;
                        cout<<"0. REGRESAR "<<endl;
                        cin>>menuLogin;
                        switch(menuLogin)
                        {
                            case 1:
                                {
                                    cout<<"Ingrese su nombre de usuario :";
                                    cin>>snombreUsuario;
                                    string nombreUsuario;

                                    int numeroUsuario = obtenerUsuario("Escriba su codigo : ");
                                    archivoUsuarios.seekg(
                                      ( numeroUsuario - 1 ) * sizeof( ClsLogin ) );
                                    ClsLogin usuario;
                                    archivoUsuarios.read( reinterpret_cast< char * >( &usuario ),
                                      sizeof( ClsLogin ) );

                                    if ( usuario.mobtenerIngreso() != 0 )
                                    {
                                        nombreUsuario=usuario.mobtenernombreUsuario();
                                    }

                                   else
                                   {
                                       cerr <<"No esta registrado." << endl;
                                   }
                                   if (nombreUsuario==snombreUsuario)
                                    {
                                        cout<<"Acceso concedido";
                                        a=0;
                                    }
                                    else
                                    {
                                        cout <<"Acceso denegado";
                                        getch();
                                    }

                                    if(a==0)
                                    {
                                        getch();

                                        do
                                        {
                                            system("cls");

                                            cout<<"-----------------------------------------"<<endl;
                                            cout<<"|-------BIENVENIDO ADMINISTRADOR-------|"<<endl;
                                            cout<<"---------------s-------------------------"<<endl;
                                            cout<<"1. CARTELERA"<<endl;
                                            cout<<"2. PROVEEDOR"<<endl;
                                            cout<<"3. BANCO"<<endl;
                                            cout<<"4. AGREGAR USUARIO"<<endl;
                                            cout<<"0. EXIT"<<endl;

                                            cout<<"-------------------------------"<<endl;
                                            cout<<"OPCIONES A ESCOGER :     [1/2/3/4/0]"<<endl;
                                            cout<<"-------------------------------"<<endl;
                                            cout<<"INGRESA TU OPCION : ";
                                            cin>>menuLoginMenu;

                                            switch(menuLoginMenu)
                                            {
                                                case 1:
                                                    {
                                                        do
                                                        {
                                                            system("cls");

                                                            fstream archivoCartelera("RegistroCartelera.dat", ios::in | ios::out | ios::binary);

                                                            if ( !archivoCartelera )
                                                            {
                                                                cerr << "No se pudo abrir el archivo." << endl;
                                                                crearArchivoCartelera();
                                                                cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                                                exit ( 1 );
                                                                exit( EXIT_FAILURE );
                                                            }

                                                            cout<<"-----------------------------------------"<<endl;
                                                            cout<<"|-----------MENU CARTELERA--------------|"<<endl;
                                                            cout<<"-----------------------------------------"<<endl;
                                                            cout<<"1. AGREGAR"<<endl;
                                                            cout<<"2. MODIFICAR/ACTUALIZAR"<<endl;
                                                            cout<<"3. ELIMINAR"<<endl;
                                                            cout<<"4. MOSTRAR"<<endl;
                                                            cout<<"0. EXIT"<<endl;

                                                            cout<<"-------------------------------"<<endl;
                                                            cout<<"OPCIONES A ESCOGER :     [1/2/3/4/0]"<<endl;
                                                            cout<<"-------------------------------"<<endl;
                                                            cout<<"INGRESA TU OPCION : ";
                                                            cin>>menuCartelera;

                                                            switch(menuCartelera)
                                                            {
                                                                case 1:
                                                                    {
                                                                        system("cls");
                                                                        agregarCartelera(archivoCartelera);
                                                                        getch();
                                                                    }
                                                                    break;
                                                                case 2:
                                                                    {
                                                                        system("cls");
                                                                        actualizarRegistroCartelera(archivoCartelera);
                                                                        getch();
                                                                    }
                                                                    break;
                                                                case 3:
                                                                    {
                                                                        system("cls");
                                                                        eliminarRegistroCartelera(archivoCartelera);
                                                                        getch();
                                                                    }
                                                                    break;
                                                                case 4:
                                                                    {
                                                                        system("cls");
                                                                        consultarRegistroCartelera(archivoCartelera);
                                                                        getch();
                                                                    }
                                                                    break;

                                                            }
                                                        }while(menuCartelera!= 0);
                                                    }
                                                    break;
                                                case 2:
                                                    {
                                                        //MenuAdministrador
                                                    }
                                                    break;
                                                case 3:
                                                    {
                                                        //MenuAdministrador
                                                    }
                                                    break;
                                                case 4:
                                                    {
                                                        //MenuAdministrador
                                                    }
                                                    break;
                                            }
                                        }while(menuLoginMenu!= 0);
                                    }
                                }
                                break;
                        }
                    }while(menuLogin!=0);
                }
                break;
        }
    }while(imenuPrincipal!= 0);
}

///////////////////////////////////////////////////////////////LOGIN/////////////////////////////////
void crearArchivoUsuarios()
{
    ofstream archivoUsuarios("RegistroUsuarios.dat", ios::out | ios::binary);
    if(!archivoUsuarios)
    {
        cerr<<"No se abrio el archivo"<<endl;
        exit(1);
    }
    ClsLogin usuarioEnBlanco;
    for(int i=0; i<100; i++)
    {
        archivoUsuarios.write(reinterpret_cast<const char * > (&usuarioEnBlanco), sizeof(ClsLogin));
    }
}

int obtenerUsuario( const char * const indicador )
{
   int m_iingresoUsuario;

   do {
      cout << indicador << " (1 - 100): ";
      cin >> m_iingresoUsuario;

   } while ( m_iingresoUsuario < 1 || m_iingresoUsuario > 100 );

   return m_iingresoUsuario;

}
////////////////////////////////////////////////////TERMINA LOGIN///////////////////////////////////////////

////////////////////////////////////////////////////NUEVO USUARIO/////////////////////////////////////////
void nuevoUsuario( fstream &insertarEnArchivo )
{
   int aingresoUsuario = obtenerUsuario( "Escriba el codigo de ingreso " );

   insertarEnArchivo.seekg(
      ( aingresoUsuario - 1 ) * sizeof( ClsLogin ) );

   ClsLogin usuario;
   insertarEnArchivo.read( reinterpret_cast< char * >( &usuario ),
      sizeof( ClsLogin ) );

   if ( usuario.mobtenerIngreso() == 0 ) {

      char m_snombreUsuario[ 20 ];

      cout << "Escriba el nombre : " << endl;
      cin >> setw( 20 ) >> m_snombreUsuario;

      usuario.mestablecernombreUsuario( m_snombreUsuario );
      usuario.mestablecerIngreso( aingresoUsuario );

      insertarEnArchivo.seekp( ( aingresoUsuario - 1 ) *
         sizeof( ClsLogin ) );

      insertarEnArchivo.write(
         reinterpret_cast< const char * >( &usuario ),
         sizeof( ClsLogin ) );

   }

   else
      cerr << "La cuenta #" << aingresoUsuario
           << " ya contiene informacion." << endl;

}
////////////////////////////////////////////////////TERMINA NUEVO USUARIO//////////////////////////////////////

///////////////////////////////////////////////////CARTELERA//////////////////////////////////////////////////
///////////////////////////////////////////////CRACION ARCHIVO CARTELERA//////////////////////////////////////
void crearArchivoCartelera()
{
    ofstream archivoCartelera("RegistroCartelera.dat", ios::out | ios::binary);
    if(!archivoCartelera)
    {
        cerr<<"No se habrio el archivo"<<endl;
        exit(1);
    }
    ClsCartelera carteleraEnBlanco;
    for(int i=0; i<100; i++)
    {
        archivoCartelera.write(reinterpret_cast<const char * > (&carteleraEnBlanco), sizeof(ClsCartelera));
    }
}

///////////////////////////////////////////////////AGREAGAR CARTELERA////////////////////////////////////////////
int obtenerClave( const char * const indicador )
{
   int m_iclaveCartelera;

   do {
      cout << indicador << " (1 - 100): ";
      cin >> m_iclaveCartelera;

   } while ( m_iclaveCartelera < 1 || m_iclaveCartelera > 100 );

   return m_iclaveCartelera;

}

void agregarCartelera( fstream &insertarEnArchivoCartelera )
{
   int m_iclaveCartelera = obtenerClave( "Escriba el nuevo numero de cartelera" );

   insertarEnArchivoCartelera.seekg(
      ( m_iclaveCartelera - 1 ) * sizeof( ClsCartelera) );

   ClsCartelera cartelera;
   insertarEnArchivoCartelera.read( reinterpret_cast< char * >( &cartelera ),
      sizeof( ClsCartelera ) );

   if ( cartelera.mobtenerClave() == 0 ) {

      char m_snombreCartelera[ 20 ];
      char m_sPrecio[20];
      char m_sCodigo[20];

      cout << "Escriba el nombre: ";
      cin >> setw( 20 ) >> m_snombreCartelera;
      cout << "Escriba el Precio: ";
      cin >> setw( 20 ) >> m_sPrecio;
      cout << "Escriba el Codigo: ";
      cin >> setw( 20 ) >> m_sCodigo;

      cartelera.mestablecerNombreCartelera( m_snombreCartelera);
      cartelera.mestablecerClave( m_iclaveCartelera);
      cartelera.mestablecerPrecio( m_sPrecio);
      cartelera.mestablecerCodigo( m_sCodigo);

      insertarEnArchivoCartelera.seekp( ( m_iclaveCartelera - 1 ) *
         sizeof( ClsCartelera ) );

      insertarEnArchivoCartelera.write(
         reinterpret_cast< const char * >( &cartelera ),
         sizeof( ClsCartelera ) );

   }

   else
      cerr << "La cuenta #" << m_iclaveCartelera
           << " ya contiene informacion." << endl;

}
/////////////////////////////////////////////FIN AGREGAR CARTELERA/////////////////////////////

//////////////////////////////////////////MODIFICAR CARTELERA//////////////////////////////////
void actualizarRegistroCartelera( fstream &actualizarArchivoCartelera)
{
   int numeroClave = obtenerClave( "Escriba la cuenta que desea actualizar" );

   actualizarArchivoCartelera.seekg(
      ( numeroClave - 1 ) * sizeof( ClsCartelera ) );

   ClsCartelera cartelera;
   actualizarArchivoCartelera.read( reinterpret_cast< char * >( &cartelera ),
      sizeof( ClsCartelera ) );

   if ( cartelera.mobtenerClave() != 0 ) {
      mostrarLineaCartelera( cout, cartelera );

      cout << "\nEscriba el nombre: ";
      char m_snombreCartelera [ 20 ];
      cin >> m_snombreCartelera;

      cout << "\nEscriba el Precio: ";
      char m_sPrecio [ 20 ];
      cin >> m_sPrecio;

      cout << "\nEscriba el Codigo: ";
      char m_sCodigo [ 20 ];
      cin >> m_sCodigo;

      cartelera.mestablecerNombreCartelera( m_snombreCartelera );
      mostrarLineaCartelera( cout, cartelera );

      actualizarArchivoCartelera.seekp(
         ( numeroClave - 1 ) * sizeof( ClsCartelera ) );

      actualizarArchivoCartelera.write(
         reinterpret_cast< const char * >( &cartelera ),
         sizeof( ClsCartelera ) );
   }

   else
      cerr << "La cuenta #" << numeroClave
         << " no tiene informacion." << endl;

}

void mostrarLineaCartelera( ostream &salidaCartelera, const ClsCartelera &registroCartelera )
{
   salidaCartelera << left << setw( 9 ) << registroCartelera.mobtenerClave()
          << setw( 20 ) << registroCartelera.mobtenerNombreCartelera().data()
          << setw( 20 ) << registroCartelera.mobtenerPrecio().data()
          << setw( 20 ) << registroCartelera.mobtenerCodigo().data()
          << endl;

}
//////////////////////////////////////////////////////////////TERMINA ACTUALIZAR CARTELERA//////////////////

//////////////////////////////////////////////////ELIMINAR CARTELERA//////////////////////////////////////
void eliminarRegistroCartelera( fstream &eliminarDeArchivoCartelera )
{
   int numeroClave= obtenerClave( "Escriba la cuenta a eliminar" );

   eliminarDeArchivoCartelera.seekg(
      ( numeroClave - 1 ) * sizeof( ClsCartelera ) );

   ClsCartelera cartelera;
   eliminarDeArchivoCartelera.read( reinterpret_cast< char * >( &cartelera ),
      sizeof( ClsCartelera ) );

   if ( cartelera.mobtenerClave() != 0 ) {
      ClsCartelera carteleEnBlancoSueldo;

      eliminarDeArchivoCartelera.seekp( ( numeroClave - 1 ) *
         sizeof( ClsCartelera ) );

      eliminarDeArchivoCartelera.write(
         reinterpret_cast< const char * >( &carteleEnBlancoSueldo ),
         sizeof( ClsCartelera ) );

      cout << "Empleado clave #" << numeroClave << " eliminado correctamente.\n";

   }

   else
   {
       cerr << "Empleado clave #" << numeroClave << " esta vacia.\n";
   }
   getch();

}
////////////////////////////////////////////FIN ELIMINAR CARTELERA////////////////

////////////////////////////////////////////MOSTRAR CARTELERA/////////////////////////
void consultarRegistroCartelera( fstream &leerDeArchivoCartelera )
{

   cout << left << setw( 9 ) << "Clave" << setw( 20 )
       << "Nombre" << setw( 20 ) << "Precio"
       << setw( 20 ) << "Clave" << endl;

   leerDeArchivoCartelera.seekg( 0 );

   ClsCartelera cartelera;
   leerDeArchivoCartelera.read( reinterpret_cast< char * >( &cartelera ),
      sizeof( ClsCartelera ) );

   while ( !leerDeArchivoCartelera.eof() ) {

      if ( cartelera.mobtenerClave() != 0 )
         mostrarLineaPantallaCartelera(cartelera);

      leerDeArchivoCartelera.read( reinterpret_cast< char * >( &cartelera ),
         sizeof( ClsCartelera ) );

   }

}

void mostrarLineaPantallaCartelera( const ClsCartelera &registroCartelera )
{
   cout << left << setw( 10 ) << registroCartelera.mobtenerClave()
          << setw( 20 ) << registroCartelera.mobtenerNombreCartelera().data()
          << setw( 20 ) << registroCartelera.mobtenerPrecio().data()
          << setw( 20 ) << registroCartelera.mobtenerCodigo().data() << endl;

}
