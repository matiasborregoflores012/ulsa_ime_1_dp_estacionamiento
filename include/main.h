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