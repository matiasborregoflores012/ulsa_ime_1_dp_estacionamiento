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