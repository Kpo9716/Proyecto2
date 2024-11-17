//Autor: Kervin Picado Obando
//Fecha:26/10/2024
//Descripcion: Proyecto #2 Introduccion a la programacion

#include <iostream>
#include <fstream>
#include <iomanip>
#include <regex>

using namespace std;


// Prototipos de funciones
void MostrarSubmenuPedidos();
void MenuInventario();
void MenuPedido();
void ReporteInventario();
void ReportePedidos();
void MostrarMenu();
void MostrarSubMenuInventarios();
void CargarDatos();
void GuardarDatos();
void LimpiarCin();
int CantidadDeDatosActuales();
bool FloatValido(float& numero);
bool EnteroValido(int& numero);
bool StringEnBlancoOVacio(string& dato);
bool CedulaValida(string& cedula);
bool FechaValida(string& fechaDeSolicitud);
bool ValidaRespuestaSiONo(const string& mensaje);
void ImprimeMensajeDeError(const string& mensajeError);
string GenerarConsecutivo(string codigoInicial, int consecutivo);


//Prototipos de funciones para Inventario
void IngresarPiezasAlInventario();
void IngresarPiezaAlInventario();
void ConsultarPiezaDelInventario();
void ModificarPiezaDelInventario();
void EliminarPiezaDelInventario();
void ImprimeEncabezadoInventarios(const int medidaDeColumnas[]);

//Prototipo de funciones para Pedido
void IngresarPedidos();
void IngresoDePedido();
void ConsultaDePedido();
void CancelarPedido();
void RegistrarEntregaDePedido();
void ImprimeEncabezadoPedidos(const int medidaDeColumnas[]);


//Matrices
string matrizDeInventario[100][8];
string matrizDePedidos[100][6];
int cantidadDeInventarioActual = 0;
int cantidadDePedidosActual = 0;
const int medidaDeColumnasInventarios[] = {17, 17, 16, 20, 22, 23, 18};
const int medidaDeColumnasPedidos[] = {18, 17, 20, 25, 20, 19};

int main()
{
    char opcion;
    system("cls");
    setlocale (LC_ALL, "spanish");
    bool salir = false;
    CargarDatos();

    while (!salir)
    {
        MostrarMenu();
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case '1':
            MenuInventario();
            break;
        case '2':
            MenuPedido();
            break;
        case '3':
            ReporteInventario();
            break;
        case '4':
            ReportePedidos();
            break;
        case '5':
            GuardarDatos();
            cout << "Saliendo del programa.\n";
            salir = true;
            break;
        default:
            ImprimeMensajeDeError("Opción inválida, vuelva a intentarlo.");
            system("pause");
            break;
        }



    }
}

void MostrarMenu()
{
    system("cls");
    cout<<"1. Inventario"<<endl;
    cout<<"2. Pedido"<<endl;
    cout<<"3. Reporte de Inventario"<<endl;
    cout<<"4. Reporte de Pedidos"<<endl;
    cout<<"5. Salir"<<endl;
}


void MostrarSubMenuInventarios()
{
    system("cls");
    cout<<"a. Ingresa pieza al inventario."<<endl;
    cout<<"b. Consultar pieza de inventario."<<endl;
    cout<<"c. Modificar pieza del inventario."<<endl;
    cout<<"d. Eliminar pieza del inventario."<<endl;
    cout<<"e. Regrear al menu principal."<<endl;
}

void MenuInventario()
{
    char opcion;
    bool regresarAlMenu = false;

    while (!regresarAlMenu)
    {
        MostrarSubMenuInventarios();
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch(opcion)
        {
        case 'a':
            system("cls");
            IngresarPiezasAlInventario();
            break;
        case 'b':
            system("cls");
            ConsultarPiezaDelInventario();
            break;
        case 'c':
            system("cls");
            ModificarPiezaDelInventario();
            break;
        case 'd':
            system("cls");
            EliminarPiezaDelInventario();
            break;
        case 'e':
            regresarAlMenu = true;
            break;

        default:
            ImprimeMensajeDeError("Opción inválida, vuelva a intentarlo.\n");
            system("pause");
            break;
        }
    }
}

void IngresarPiezasAlInventario()
{
    do
    {
        IngresarPiezaAlInventario();
    }
    while(ValidaRespuestaSiONo("¿Desea ingresar otra pieza al inventario? S/N: "));
}

void IngresarPiezaAlInventario()
{
    string codigoDePieza = GenerarConsecutivo("P", cantidadDeInventarioActual);
    string nombreDeLaPieza, nombreDelProveedor, facturaDeLaEmpresa, numeroDeCedula;
    float costoDeLaPiezaPorUnidad;
    int cantidadDePiezas;

    LimpiarCin();

    do
    {
        system("cls");
        cout<<"Ingrese el nombre de la pieza: ";
    }
    while(StringEnBlancoOVacio(nombreDeLaPieza));


    do
    {
        system("cls");
        cout<<"Ingrese el costo de la pieza por unidad: ";
    }
    while(!FloatValido(costoDeLaPiezaPorUnidad));

    do
    {
        system("cls");
        cout<<"Ingrese la cantidad de piezas: ";
    }
    while(!EnteroValido(cantidadDePiezas));

    do
    {
        system("cls");
        cout<<"Ingrese el nombre de la empresa que proveee las piezas: ";
    }
    while(StringEnBlancoOVacio(nombreDelProveedor));

    do
    {
        system("cls");
        cout<<"Ingrese la factura de la empresa que proveee las piezas: ";
    }
    while(StringEnBlancoOVacio(facturaDeLaEmpresa));

    do
    {
        system("cls");
        cout<<"Ingrese su numero de cédula: ";
    }
    while(!CedulaValida(numeroDeCedula));


    matrizDeInventario[cantidadDeInventarioActual][0] = codigoDePieza;
    matrizDeInventario[cantidadDeInventarioActual][1] = nombreDeLaPieza;
    matrizDeInventario[cantidadDeInventarioActual][2] = to_string(costoDeLaPiezaPorUnidad);
    matrizDeInventario[cantidadDeInventarioActual][3] = to_string(cantidadDePiezas);
    matrizDeInventario[cantidadDeInventarioActual][4] = nombreDelProveedor;
    matrizDeInventario[cantidadDeInventarioActual][5] = facturaDeLaEmpresa;
    matrizDeInventario[cantidadDeInventarioActual][6] = numeroDeCedula;
    matrizDeInventario[cantidadDeInventarioActual][7] = "false";//Indica que el archivo no está eliminado

    cantidadDeInventarioActual++;


}


void ConsultarPiezaDelInventario()
{
    do
    {
        LimpiarCin();
        cout<<"Digite código de pieza: ";
        string codigoDePieza;
        cin>>codigoDePieza;
        bool piezaEncontrada = false;
        for(int fila =0; fila < cantidadDeInventarioActual; fila++)
        {
            if (matrizDeInventario[fila][0] == codigoDePieza && matrizDeInventario[fila][7] == "false")
            {
                const int medidaDeColumnas[] = {17, 17, 16, 20, 22, 23, 18};

                ImprimeEncabezadoInventarios(medidaDeColumnas);
                for (int columna =0; columna < 7; columna++)
                {
                    cout << left <<setw(medidaDeColumnas[columna])<<matrizDeInventario[fila][columna]; // Imprime todas las columnas de esa fila
                }
                cout<<endl<<endl;
                system("pause");

                piezaEncontrada = true;
            }

            if (piezaEncontrada)
                break;
        }

        if (!piezaEncontrada)
        {
            ImprimeMensajeDeError("No se encontró ninguna pieza con esa información.");
            system("pause");
        }

    }
    while(ValidaRespuestaSiONo("¿Desea buscar otro código de pieza? S/N: "));
}

void ModificarPiezaDelInventario()
{
    do
    {
        LimpiarCin();
        cout<<"Digite código de pieza: ";
        string codigoDePieza;
        float nuevoCosto;
        int nuevaCantidad;
        cin>>codigoDePieza;
        bool piezaEncontrada = 0;
        for(int fila =0; fila < cantidadDeInventarioActual; fila++)
        {
            if (matrizDeInventario[fila][0] == codigoDePieza && matrizDeInventario[fila][7] == "false")
            {
                do
                {
                    system("cls");
                    cout<<"Ingrese el nuevo costo de la pieza por unidad: ";
                }
                while(!FloatValido(nuevoCosto));

                do
                {
                    system("cls");
                    cout<<"Ingrese la nueva cantidad de piezas: ";
                }
                while(!EnteroValido(nuevaCantidad));

                matrizDeInventario[fila][2] = to_string(nuevoCosto);
                matrizDeInventario[fila][3] = to_string(nuevaCantidad);

                ImprimeEncabezadoInventarios(medidaDeColumnasInventarios);
                for (int columna =0; columna < 7; columna++)
                {
                    cout << left <<setw(medidaDeColumnasInventarios[columna])<<matrizDeInventario[fila][columna];
                }
                cout<<endl<<endl;
                system("pause");

                piezaEncontrada = true;
            }

            if (piezaEncontrada)
                break;
        }

        if (!piezaEncontrada)
        {
            ImprimeMensajeDeError("No se encontró ninguna pieza con esa información.");
            system("pause");
        }

    }
    while(ValidaRespuestaSiONo("¿Desea modificar otra pieza? S/N: "));
}

void EliminarPiezaDelInventario()
{
    do
    {
        LimpiarCin();
        cout<<"Digite código de pieza: ";
        string codigoDePieza;
        cin>>codigoDePieza;
        bool piezaEncontrada = 0;
        for(int fila =0; fila < cantidadDeInventarioActual; fila++)
        {
            if (matrizDeInventario[fila][0] == codigoDePieza && matrizDeInventario[fila][7] == "false")
            {
                bool eliminar = ValidaRespuestaSiONo("¿Esta seguro que deseea elminar esta pieza? S/N: ");

                if (eliminar)
                {
                    matrizDeInventario[fila][7] = "true";
                    cout<<"Pieza eliminada"<<endl;
                    system("pause");
                }

                piezaEncontrada = true;
            }

            if (piezaEncontrada)
                break;
        }

        if (!piezaEncontrada)
        {
            ImprimeMensajeDeError("No se encontró ninguna pieza con esa información.");
            system("pause");
        }

    }
    while(ValidaRespuestaSiONo("¿Desea eliminar otra pieza? S/N: "));
}

void ReporteInventario()
{
    if (cantidadDeInventarioActual <= 0)
    {
        ImprimeMensajeDeError("No hay datos para mostrar.");
        system("pause");

        return;
    }

    ImprimeEncabezadoInventarios(medidaDeColumnasInventarios);
    for (int fila = 0; fila < cantidadDeInventarioActual; fila++)
    {
        for (int columna = 0; columna < 7; columna++)
        {
            cout << left <<setw(medidaDeColumnasInventarios[columna])<<matrizDeInventario[fila][columna]; // Imprime todas las columnas de esa fila
        }
        cout<<endl<<endl;
    }
    system("pause");
}

void ImprimeEncabezadoInventarios(const int medidaDeColumnas[])
{
    system("cls");
    // Imprimir encabezados
    cout << "\033[32m" << left << setw(medidaDeColumnas[0]) << "Codigo de pieza"
         << setw(medidaDeColumnas[1]) << "Nombre de pieza"
         << setw(medidaDeColumnas[2]) << "Costo de pieza"
         << setw(medidaDeColumnas[3]) << "Cantidad de piezas"
         << setw(medidaDeColumnas[4]) << "Nombre de la empresa"
         << setw(medidaDeColumnas[5]) << "Factura de la empresa"
         << setw(medidaDeColumnas[6]) << "Numero de cédula"
         << endl;
    cout << string(133, '-') << "\033[0m" << endl <<endl;;
}

void MostrarSubmenuPedidos()
{
    system("cls");
    cout<<"a. Ingreso de Pedido."<<endl;
    cout<<"b. Consulta de Pedido."<<endl;
    cout<<"c. Cancelar Pedido."<<endl;
    cout<<"d. Registrar entrega de pedido."<<endl;
    cout<<"e. Regrear al menu principal."<<endl;
}

void MenuPedido()
{
    char opcion;
    bool regresarAlMenu = false;

    while (!regresarAlMenu)
    {
        MostrarSubmenuPedidos();
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch(opcion)
        {
        case 'a':
            system("cls");
            IngresarPedidos();
            break;

        case 'b':
            system("cls");
            ConsultaDePedido();
            break;

        case 'c':
            system("cls");
            CancelarPedido();
            break;

        case 'd':
            system("cls");
            RegistrarEntregaDePedido();
            break;

        case 'e':
            regresarAlMenu = true;
            break;

        default:
            ImprimeMensajeDeError("Opción inválida, vuelva a intentarlo.\n");
            system("pause");
            break;
        }
    }
}

void IngresarPedidos()
{
    do
    {
        IngresoDePedido();
    }
    while(ValidaRespuestaSiONo("¿Desea ingresar otra pedido? S/N: "));
}

void IngresoDePedido()
{
    string codigoDePedido = GenerarConsecutivo("PE", cantidadDePedidosActual);
    string codigoDePieza, fechaDeSolicitud, numeroDeIDEmpleado;
    int cantidadDePiezasASolicitar;


    LimpiarCin();

    do
    {
        system("cls");
        cout<<"Ingrese el código de la pieza: ";
    }
    while(StringEnBlancoOVacio(codigoDePieza));


    do
    {
        system("cls");
        cout<<"Ingrese la cantidad de piezas a solicitar: ";
    }
    while(!EnteroValido(cantidadDePiezasASolicitar));

    do
    {
        system("cls");
        cout<<"Ingrese número de cédula del Empleado: ";
    }
    while(!CedulaValida(numeroDeIDEmpleado));

    do
    {
        system("cls");
        cout<<"Ingrese fecha de solicitud: ";
    }
    while(!FechaValida(fechaDeSolicitud));


    matrizDePedidos[cantidadDePedidosActual][0] = codigoDePedido;
    matrizDePedidos[cantidadDePedidosActual][1] = codigoDePieza;
    matrizDePedidos[cantidadDePedidosActual][2] = to_string(cantidadDePiezasASolicitar);
    matrizDePedidos[cantidadDePedidosActual][3] = numeroDeIDEmpleado;
    matrizDePedidos[cantidadDePedidosActual][4] = fechaDeSolicitud;
    matrizDePedidos[cantidadDePedidosActual][5] = "EnProceso";//Indica que el archivo no está eliminado


    cantidadDePedidosActual++;
}

void ConsultaDePedido()
{
    do
    {
        LimpiarCin();
        cout<<"Digite código de pedido: ";
        string codigoDePedido;
        cin>>codigoDePedido;
        bool pedidoEncontrado = false;
        for(int fila =0; fila < cantidadDePedidosActual; fila++)
        {
            if (matrizDePedidos[fila][0] == codigoDePedido)
            {
                ImprimeEncabezadoPedidos(medidaDeColumnasPedidos);
                for (int columna =0; columna < 6; columna++)
                {
                    cout << left <<setw(medidaDeColumnasPedidos[columna])<<matrizDePedidos[fila][columna]; // Imprime todas las columnas de esa fila
                }
                cout<<endl<<endl;
                system("pause");

                pedidoEncontrado = true;
            }

            if (pedidoEncontrado)
                break;
        }

        if (!pedidoEncontrado)
        {
            ImprimeMensajeDeError("No se encontró ningún pedido con esa información.");
            system("pause");
        }

    }
    while(ValidaRespuestaSiONo("¿Desea buscar otro código de pedido? S/N: "));
}

void CancelarPedido()
{
    do
    {
        LimpiarCin();
        cout<<"Digite código de pedido: ";
        string codigoDePedido;
        cin>>codigoDePedido;
        bool pedidoEncontrado = 0;
        for(int fila =0; fila < cantidadDePedidosActual; fila++)
        {
            if (matrizDePedidos[fila][0] == codigoDePedido)
            {
                bool eliminar = ValidaRespuestaSiONo("¿Esta seguro que deseea cancelar este pedido? S/N: ");

                if (eliminar)
                {
                    matrizDePedidos[fila][5] = "Cancelado";
                    cout<<"Pedido cancelado"<<endl;
                    system("pause");
                }

                pedidoEncontrado = true;
            }

            if (pedidoEncontrado)
                break;
        }

        if (!pedidoEncontrado)
        {
            ImprimeMensajeDeError("No se encontró ningún pedido con esa información.");
            system("pause");
        }

    }
    while(ValidaRespuestaSiONo("¿Desea cancelar otro pedido? S/N: "));
}

void RegistrarEntregaDePedido()
{
    do
    {
        LimpiarCin();
        cout<<"Digite código de pedido: ";
        string codigoDePedido;
        cin>>codigoDePedido;
        bool pedidoEncontrado = 0;
        for(int fila =0; fila < cantidadDePedidosActual; fila++)
        {
            if (matrizDePedidos[fila][0] == codigoDePedido)
            {
                bool eliminar = ValidaRespuestaSiONo("¿Esta seguro que deseea entregar este pedido? S/N: ");

                if (eliminar)
                {
                    matrizDePedidos[fila][5] = "Entregado";
                    cout<<"Pedido entregado"<<endl;
                    system("pause");
                }

                pedidoEncontrado = true;
            }

            if (pedidoEncontrado)
                break;
        }

        if (!pedidoEncontrado)
        {
            ImprimeMensajeDeError("No se encontró ningún pedido con esa información.");
            system("pause");
        }

    }
    while(ValidaRespuestaSiONo("¿Desea cancelar otro pedido? S/N: "));
}

void ReportePedidos()
{
    if (cantidadDePedidosActual <= 0)
    {
        ImprimeMensajeDeError("No hay datos para mostrar.");
        system("pause");

        return;
    }

    ImprimeEncabezadoPedidos(medidaDeColumnasPedidos);

    for (int fila = 0; fila < cantidadDePedidosActual; fila++)
    {
        for (int columna = 0; columna < 6; columna++)
        {
            cout << left <<setw(medidaDeColumnasPedidos[columna])<<matrizDePedidos[fila][columna]; // Imprime todas las columnas de esa fila
        }
        cout<<endl;
    }
    system("pause");
}

void ImprimeEncabezadoPedidos(const int medidaDeColumnas[])
{
    system("cls");

    // Imprimir encabezados
    cout << "\033[32m" << left << setw(medidaDeColumnas[0]) << "Código de pedido"
         << setw(medidaDeColumnas[1]) << "Código de pieza"
         << setw(medidaDeColumnas[2]) << "Cantidad de piezas"
         << setw(medidaDeColumnas[3]) << "# de cédula de empleado"
         << setw(medidaDeColumnas[4]) << "Fecha de solicitud"
         << setw(medidaDeColumnas[5]) << "Estado del pedido"
         << endl;
    cout << string(133, '-') << "\033[0m" << endl <<endl;;
}

string GenerarConsecutivo(string codigoInicial, int consecutivo)
{
    ostringstream codigoDePieza;

    // Agrega la palabra al inicio
    codigoDePieza << codigoInicial;

    // Rellena el número con ceros a la izquierda para que tenga 8 dígitos
    codigoDePieza << setw(8) << setfill('0') << consecutivo + 1;


    return codigoDePieza.str();
}

bool FloatValido(float& numero)
{
    LimpiarCin();
    cin>>numero;
    if (cin.fail())
    {
        ImprimeMensajeDeError("Numero invalido. Intente nuevamente");
        system("pause");
        return false;
    }

    return true;
}
bool EnteroValido(int& numero)
{
    LimpiarCin();
    cin>>numero;
    if (cin.fail())
    {
        ImprimeMensajeDeError("Numero invalido. Intente nuevamente");
        system("pause");
        LimpiarCin();
        return false;
    }

    return true;
}

bool StringEnBlancoOVacio(string& dato)
{
    LimpiarCin();
    getline(cin, dato);
    regex enBlancoOVacio("^\\s*$");
    bool resultado = regex_match(dato, enBlancoOVacio);

    if (resultado)
    {
        ImprimeMensajeDeError("No debe ingresar datos en blanco. Intente nuevamente.");
        system("pause");
    }

    return resultado;
}

bool CedulaValida(string& cedula)
{
    LimpiarCin();
    getline(cin, cedula);
    regex cedulaValida("^\\d{9}$");
    bool resultado = regex_match(cedula, cedulaValida);

    if (!resultado)
    {
        ImprimeMensajeDeError("La cedula solo puede contener 9 dígitos, ejem: 123456789");
        system("pause");
    }

    return resultado;
}

bool ValidaRespuestaSiONo(const string& mensaje)
{
    while(true)
    {
        LimpiarCin();
        system("cls");
        char respuesta;
        cout<<mensaje;
        cin>>respuesta;

        if (respuesta == 's' || respuesta == 'S')
            return true;
        else if (respuesta == 'n' || respuesta == 'N')
            return false;
        else
        {
            ImprimeMensajeDeError("Debe ingresar ((s) o (n)) o ((S) o (N)) solamente. Por favor intente nuevamente.");
            system("pause");
        }
    }
}

void CargarDatos()
{
    //Carga datos de inventario
    ifstream archivoInventario("INVENTARIO.TXT", ifstream::in);

    cantidadDeInventarioActual = 0;
    while (cantidadDeInventarioActual < 100 && archivoInventario)
    {
        for (int col = 0; col < 8; ++col)
        {
            if (!(archivoInventario >> matrizDeInventario[cantidadDeInventarioActual][col]))
            {
                // Si no se pueden leer más datos, salir
                break;
            }
        }
                    ++cantidadDeInventarioActual; // Incrementar el contador de filas leídas

    }

    //Carga datos de pedidos
    ifstream archivoPedidos("PEDIDOS.TXT");

    cantidadDePedidosActual = 0;
    while (cantidadDePedidosActual < 100 && archivoPedidos)
    {
        for (int col = 0; col < 6; ++col)
        {
            if (!(archivoPedidos >> matrizDePedidos[cantidadDePedidosActual][col]))
            {
                // Si no se pueden leer más datos, salir
                break;
            }
        }
        ++cantidadDePedidosActual; // Incrementar el contador de filas leídas
    }
}

void GuardarDatos()
{
    if(cantidadDeInventarioActual > 0)
    {
        //Guarda datos de Inventario
        ofstream archivoInventario("INVENTARIO.TXT");

        if (archivoInventario.fail())
        {
            cerr<<"Hubo un error al abrir el archivo";
            return;
        }


        for (int i = 0; i < cantidadDeInventarioActual; i++)
        {
            for (int j =0; j < 8; j++)
            {
                string dato = matrizDeInventario[i][j];
                archivoInventario << dato << " ";
            }
            archivoInventario << endl;
        }

        archivoInventario.close();
    }


    if (cantidadDePedidosActual > 0)
    {
        //Guarda datos de Pedidos
        ofstream archivoPedido("PEDIDOS.TXT");

        if (archivoPedido.fail())
        {
            cerr<<"Hubo un error al abrir el archivo";
            return;
        }


        for (int i = 0; i < cantidadDePedidosActual; i++)
        {
            for (int j =0; j < 6; j++)
            {
                archivoPedido << matrizDePedidos[i][j] << " ";
            }
            archivoPedido << endl;
        }

        archivoPedido.close();
    }



}

bool FechaValida(string& fechaDeSolicitud)
{
    LimpiarCin();
    getline(cin, fechaDeSolicitud);
    regex fechaValida(R"(^([0-2][0-9]|3[0-1])/(0[1-9]|1[0-2])/(\d{4})$)");
    bool resultado = regex_match(fechaDeSolicitud, fechaValida);

    if (!resultado)
    {
        ImprimeMensajeDeError("La Fecha tiene que estar en formato Día, Mes, Año ejem: DD/MM/YYYY");
        system("pause");
    }


    return resultado;
}

void LimpiarCin()
{
    cin.clear();
    fflush(stdin);
}

void ImprimeMensajeDeError(const string& mensajeError)
{
    cout<<"\033[31m"<<mensajeError<<"\033[0m"<<endl;
}
