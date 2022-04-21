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

int obtenerCuenta( const char * const );
int obtenerUsuario( const char * const );
void crearArchivoUsuarios();
void nuevoUsuario( fstream& );
void mostrarCartelera();
void crearArchivoCartelera();
/*void nuevoEmpleado( fstream& );
void crearArchivoCredito();
void consultarRegistro(fstream&);
void mostrarLineaPantalla(const ClsEmpleados &);
void actualizarRegistro(fstream&);
void mostrarLinea( ostream&, const ClsEmpleados & );
void imprimirRegistro( fstream& );
void eliminarRegistro( fstream& );
void buscarEmpleado( fstream& );
string obtenerNombreUsuario();
void escribirBitacora(int, string);*/

int main()
{
    //VariablesMenus
    int imenuPrincipal;
    int menuLogin;
    int menuLoginMenu;
    int menuCartelera;

    //Variables
    int m_iclaveEmpleado=0;
    char m_snombreEmpleado[0];
    int iingresoUsuario;
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

        cout<<"  |||||||"<<endl;
        cout<<"  |     |"<<endl;
        cout<<"  |     |"<<endl;
        cout<<"  |     |"<<endl;
        cout<<"  |||||||"<<endl;
        cout<<"  |     |"<<endl;
        cout<<"  |     |"<<endl;
        cout<<"  |     |"<<endl;
        cout<<"  |     |"<<endl;
        cout<<""<<endl;
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
                                                            cout<<"1. Agregar"<<endl;
                                                            cout<<"2. Modificar"<<endl;
                                                            cout<<"3. Eliminar"<<endl;
                                                            cout<<"4. Mostrar"<<endl;
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
                                                                        //AgregarCartelera
                                                                    }
                                                                    break;
                                                                case 2:
                                                                    {
                                                                        //ModificarCartelera
                                                                    }
                                                                    break;
                                                                case 3:
                                                                    {
                                                                        //EliminarCartelera
                                                                    }
                                                                    break;
                                                                case 4:
                                                                    {
                                                                        //MostrarCartelera
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

