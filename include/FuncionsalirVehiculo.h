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