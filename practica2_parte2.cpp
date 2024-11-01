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

void leerRegistro(int id) {
    ifstream archivo("Data/personas.bin", ios::binary);
    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    Persona p;
    bool encontrado = false;

    while (archivo.read(reinterpret_cast<char*>(&p), sizeof(Persona))) {
        if (p.id_del_registro == id) {
            cout << "ID del registro: " << p.id_del_registro << endl;
            cout << "Nombre: " << p.nombre << endl;
            cout << "Cedula: " << p.cedula << endl;
            cout << "Edad: " << p.edad << endl;
            cout << "Peso: " << p.peso << " kg" << endl;
            cout << "Altura: " << p.altura << " m" << endl;
            cout << "Genero: " << p.genero << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Registro con ID " << id << " no encontrado." << endl;
    }

    archivo.close();
}

int main() {
    int id;
    cout << "Ingrese el ID del registro a buscar: ";
    cin >> id;
    leerRegistro(id);
    return 0;
}