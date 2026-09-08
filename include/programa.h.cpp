#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

// Funcion para mostrar el estado del estacionamiento
void imprimirEstado(const map<string, vector<bool>>& estacionamiento)
{
    int totalOcupados = 0;
    int totalCapacidad = 0;

    cout << "\nESTADO DEL ESTACIONAMIENTO" << endl;

    for (const auto& par : estacionamiento)
    {
        string tipo = par.first;
        vector<bool> lugares = par.second;

        int ocupados = 0;

        for (bool ocupado : lugares)
        {
            if (ocupado == true)
            {
                ocupados++;
            }
        }

        totalOcupados = totalOcupados + ocupados;
        totalCapacidad = totalCapacidad + lugares.size();

        cout << tipo << ": " << ocupados << "/" 
             << lugares.size() << " ocupados" << endl;
    }

    double porcentaje;

    if (totalCapacidad == 0)
    {
        porcentaje = 0;
    }
    else
    {
        porcentaje = 100.0 * totalOcupados / totalCapacidad;
    }

    cout << "Ocupacion total: " << fixed << setprecision(1)
         << porcentaje << "% (" << totalOcupados << "/"
         << totalCapacidad << ")" << endl;

    cout << "-------------------------------\n" << endl;
}


// Funcion para que entre un vehiculo
bool entrarVehiculo(map<string, vector<bool>>& estacionamiento,
                    const string& tipo)
{
    if (estacionamiento.find(tipo) == estacionamiento.end())
    {
        cout << "Entrada invalida: tipo de vehiculo no reconocido." << endl;
        return false;
    }

    vector<bool>& lugares = estacionamiento[tipo];

    for (int i = 0; i < lugares.size(); i++)
    {
        if (lugares[i] == false)
        {
            lugares[i] = true;

            cout << "Vehiculo aceptado. Lugar asignado: "
                 << tipo << setw(2) << setfill('0') << i + 1 << endl;

            imprimirEstado(estacionamiento);

            return true;
        }
    }

    cout << "ERROR: Estacionamiento lleno para "
         << tipo << "." << endl;

    return false;
}


// Funcion para que salga un vehiculo
bool salirVehiculo(map<string, vector<bool>>& estacionamiento,
                   const string& comando)
{
    string tipo;
    int numero = -1;

    for (int i = 0; i < comando.size(); i++)
    {
        if (isdigit(comando[i]))
        {
            tipo = comando.substr(0, i);
            numero = stoi(comando.substr(i));
            break;
        }
    }

    if (estacionamiento.find(tipo) == estacionamiento.end())
    {
        cout << "Salida invalida: tipo de vehiculo no reconocido." << endl;
        return false;
    }

    vector<bool>& lugares = estacionamiento[tipo];

    if (numero < 1 || numero > lugares.size())
    {
        cout << "Salida invalida: el lugar "
             << comando << " no existe." << endl;
        return false;
    }

    if (lugares[numero - 1] == false)
    {
        cout << "ERROR: Lugar " << comando
             << " ya esta libre." << endl;
        return false;
    }

    lugares[numero - 1] = false;

    cout << "Vehiculo de lugar " << comando
         << " ha salido." << endl;

    imprimirEstado(estacionamiento);

    return true;
}


int main()
{
    cout << "Bienvenido al Simulador de Acceso a Estacionamiento" << endl;
    cout << "Ingrese el tamaño del vehiculo para entrada "
         << "(COMPACTO, SEDAN, SUV)" << endl;
    cout << "o el numero de lugar para la salida (ej. SUV01)" << endl;
    cout << "Escriba SALIR para terminar\n" << endl;

    map<string, vector<bool>> estacionamiento =
    {
        {"SUV", vector<bool>(5, false)},
        {"SEDAN", vector<bool>(8, false)},
        {"COMPACTO", vector<bool>(10, false)}
    };

    string comando;

    while (true)
    {
        cout << "> ";
        cin >> comando;

        if (comando == "SALIR")
        {
            cout << "Simulacion finalizada." << endl;
            break;
        }
        else if (comando == "SUV" ||
                 comando == "SEDAN" ||
                 comando == "COMPACTO")
        {
            entrarVehiculo(estacionamiento, comando);
        }
        else
        {
            salirVehiculo(estacionamiento, comando);
        }
    }

    return 0;
}
