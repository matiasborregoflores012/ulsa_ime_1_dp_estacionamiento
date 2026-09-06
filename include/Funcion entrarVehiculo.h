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