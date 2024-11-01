#include <iostream>
#include <fstream>

using namespace std;

struct Persona {
    int id_del_registro;
    char nombre[50];
    char cedula[20];
    int edad;
    float peso;
    float altura;
    char genero; // 'M' o 'F'
};

void agregarPersonas() {
    ofstream archivo("Data/personas.bin", ios::binary | ios::app);
    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    int numPersonas;
    cout << "Ingrese el numero de personas a registrar: ";
    cin >> numPersonas;

    for (int i = 0; i < numPersonas; ++i) {
        Persona p;
        cout << "Registro #" << (i + 1) << endl;
        cout << "ID del registro: ";
        cin >> p.id_del_registro;
        cin.ignore(); // Limpiar el buffer de entrada
        cout << "Nombre: ";
        cin.getline(p.nombre, 50);
        cout << "Cedula: ";
        cin.getline(p.cedula, 20);
        cout << "Edad: ";
        cin >> p.edad;
        cout << "Peso (kg): ";
        cin >> p.peso;
        cout << "Altura (m): ";
        cin >> p.altura;
        cout << "Genero (M/F): ";
        cin >> p.genero;

        archivo.write(reinterpret_cast<const char*>(&p), sizeof(Persona));
    }

    archivo.close();
    cout << "Datos guardados en personas.bin." << endl;
}

int main() {
    agregarPersonas();
    return 0;
}