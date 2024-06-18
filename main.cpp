// Librerías
#include <iostream>
#include <vector>

using namespace std;

// Union con tipos diferentes para cada raza
union Height {
    double height_orc;
    double height_human;
    double height_elf;
};

// Estructura anidada a cada raza, con una función
struct Weapon {
    int damage;
    double speed;

    // Funcion estatica
    static void attack() {
        cout << "Ataque generico" << endl;
    }
};

// Estructura para la raza: Orcos
struct Orcs {
    double strength;
    string skin_color;
    int level;
    Height height;
    Weapon weapon;

    void invade() {
        cout << "¡¡Orco atacando!! Inicia la invasion" << endl;
    }

    void train() {
        strength += 2;
        level++;
        cout << "Entrenando..." << endl;
        cout << "Fuerza incrementada en: " << strength << endl;
    }

    void attack() {
        cout << "¡RAWR! ¡Orco al ataque! " << weapon.damage  << " puntos de daño" << endl;
    }
};

// Estructura para la raza: Humanos
struct Humans {
    int age;
    double intelligence;
    string ocupation;
    Height height;
    Weapon weapon;

    void build() {
        intelligence *= 2;
        cout << "Construyendo..." << endl;
        cout << "Inteligencia aumentada en: " << intelligence << endl;
    }

    void change_ocupation() {
        vector<string> ocu = {"Medico", "Ingeniero", "Profesor", "Programador", "Abogado"};
        ocupation = ocu[rand() % ocu.size()];

        cout << "Nueva ocupacion: " << ocupation << endl;
    }

    void attack() {
        cout << "¡Humano al ataque! " << weapon.damage << " puntos de daño" << endl;
    }
};

// Estructura para la raza: Elfos
struct Elfs {
    string magicHab;
    int ability;
    string rank;
    Height height;
    Weapon weapon;

    void bewitch() {
        cout << "Ataque de elfo usando " << magicHab << endl;
    }

    void heal() {
        ability += 1;
        cout << "¡Salud de elfo aumentada!" << endl;
    }

    void attack() {
        cout << "¡Elfo atacando!" << weapon.damage << " puntos de daño" << endl;
    }
};

// Funcion sobrecargada para el llenado manual de un orco
void fillManual(Orcs& orc) {
    cout << "\nIntroduce la fuerza del orco: ";
    cin >> orc.strength;

    cout << "Introduce el color del orco: ";
    cin >> orc.skin_color;

    cout << "Introduce el nivel del orco: ";
    cin >> orc.level;

    cout << "Introduce la altura del orco: ";
    cin >> orc.height.height_orc;

    cout << "Introduce el daño del arma del orco: ";
    cin >> orc.weapon.damage;

    cout << "Introduce la velocidad del arma del orco: ";
    cin >> orc.weapon.speed;
}

// Función sobrecargada para el llenado manual de un humano
void fillManual(Humans& human) {
    cout << "\nIntroduce la edad del humano: ";
    cin >> human.age;

    cout << "Introduce el nivel de inteligencia del humano: ";
    cin >> human.intelligence;

    cout << "Introduce la ocupacion del humano: ";
    cin >> human.ocupation;

    cout << "Introduce la altura del humano: ";
    cin >> human.height.height_human;

    cout << "Introduce el daño del arma del humano: ";
    cin >> human.weapon.damage;

    cout << "Introduce la velocidad del arma del humano: ";
    cin >> human.weapon.speed;
}

// Funcion sobrecargada para el llenado manual de un elfo
void fillManual(Elfs& elf) {
    cout << "\nIntroduce la habilidad del elfo: ";
    cin >> elf.magicHab;

    cout << "Introduce el nivel de habilidad del elfo: ";
    cin >> elf.ability;

    cout << "Introduce el rango del elfo: ";
    cin >> elf.rank;

    cout << "Introduce la altura del elfo: ";
    cin >> elf.height.height_elf;

    cout << "Introduce el daño del arma del elfo: ";
    cin >> elf.weapon.damage;

    cout << "Introduce la velocidad del arma del elfo: ";
    cin >> elf.weapon.speed;
}

// Funcion sobrecargada para el llenado aleatorio de un orco usando referencias
void fillRandom(Orcs& orc) {
    vector<string> skin_colors = {"Verde", "Marron", "Gris", "Negro", "Azul"};

    orc.strength = rand() % 100 + 1;
    orc.skin_color = skin_colors[rand() % skin_colors.size()];
    orc.level = rand() % 10 + 1;
    orc.height.height_orc = (rand() % 7000 + 1500) / 100.0;  // Altura en metros
    orc.weapon.damage = rand() % 41 + 10;
    orc.weapon.speed = (rand() % 10 + 1) / 10.0;  // Velocidad en m/s
}

// Función sobrecargada para el llenado aleatorio de un humano usando referencias
void fillRandom(Humans& human) {
    vector<string> occupations = {"Medico", "Ingeniero", "Profesor", "Programador", "Abogado"};

    human.age = rand() % 100 + 1;
    human.intelligence = static_cast<double>(rand() % 100) / 10.0;  // Valores entre 0 y 10
    human.ocupation = occupations[rand() % occupations.size()];
    human.height.height_human = (rand() % 1500 + 1500) / 100.0;  // Altura en centímetros
    human.weapon.damage = rand() % 41 + 10;
    human.weapon.speed = (rand() % 10 + 1) / 10.0;  // Velocidad en m/s
}

// Función sobrecargada para el llenado aleatorio de un elfo usando referencias
void fillRandom(Elfs& elf) {
    vector<string> ranks = {"Arquero", "Mago", "Guerrero", "Sanador", "Ladron"};
    vector<string> magicHabs = {"Inmortalidad", "Invisibilidad", "Teletransportacion", "Ilusiones", "Control mental"};

    elf.magicHab = magicHabs[rand() % magicHabs.size()];
    elf.ability = static_cast<double>(rand() % 100) / 10.0;  // Valores entre 0 y 10
    elf.rank = ranks[rand() % ranks.size()];
    elf.height.height_elf = (rand() % 1500 + 1500) / 100.0;  // Altura en centímetros
    elf.weapon.damage = rand() % 41 + 10;
    elf.weapon.speed = (rand() % 10 + 1) / 10.0;  // Velocidad en m/s
}

// Función para mostrar la informacion de un orco
void showInfo(const Orcs& orc) {
    cout << "\n---------- ORCO --------" << endl;
    cout << "Fuerza: " << orc.strength << endl;
    cout << "Color de piel: " << orc.skin_color << endl;
    cout << "Nivel: " << orc.level << endl;
    cout << "Altura: " << orc.height.height_orc << endl;
    cout << "Daño del arma: " << orc.weapon.damage << endl;
    cout << "Velocidad del arma: " << orc.weapon.speed << endl;
    cout << "------------------------" << endl;
}

// Funcion para mostrar la informacion de un humano
void showInfo(const Humans& human) {
    cout << "\n--------- HUMANO -------" << endl;
    cout << "Edad: " << human.age << endl;
    cout << "Inteligencia: " << human.intelligence << endl;
    cout << "Ocupacion: " << human.ocupation << endl;
    cout << "Altura: " << human.height.height_human << endl;
    cout << "Daño del arma: " << human.weapon.damage << endl;
    cout << "Velocidad del arma: " << human.weapon.speed << endl;
    cout << "------------------------" << endl;
}

// Funcion para mostrar la informacion de un elfo
void showInfo(const Elfs& elf) {
    cout << "\n--------- ELFO --------" << endl;
    cout << "Habilidad magica: " << elf.magicHab << endl;
    cout << "Nivel de habilidad: " << elf.ability << endl;
    cout << "Rango: " << elf.rank << endl;
    cout << "Altura: " << elf.height.height_elf << endl;
    cout << "Daño del arma: " << elf.weapon.damage << endl;
    cout << "Velocidad del arma: " << elf.weapon.speed << endl;
    cout << "------------------------" << endl;
}

// Funcion principal
int main() {
    // Arreglo por cada tipo de raza
    Orcs *arregloO = nullptr;
    Humans *arregloH = nullptr;
    Elfs *arregloE = nullptr;
    int n = 1;
    srand(time(0));

    // Eleccion de la raza a utilizar
    char opcion_raza;
    do {
        cout << "Elige la raza: Orcos ('o') / Humanos ('h') / Elfos ('e')" << endl;
        cout << "Ingresa la opcion: ";
        cin >> opcion_raza;
    } while (opcion_raza != 'o' && opcion_raza != 'h' && opcion_raza != 'e');

    // Eleccion del tipo de generacion de elementos
    int opcionG;
    do {
        cout << "Un elemento (1) / Arreglo de elementos (2)" << endl;
        cout << "Ingresa la opcion: ";
        cin >> opcionG;
    } while (opcionG != 1 && opcionG != 2);

    // Creación del arreglo de acuerdo a la opcion del usuario
    switch (opcionG) {
        case 1:
            if (opcion_raza == 'o')
                arregloO = new Orcs[n];

            if (opcion_raza == 'h')
                arregloH = new Humans[n];

            if (opcion_raza == 'e')
                arregloE = new Elfs[n];

            break;

        case 2:
            cout << "¿Cuantos elementos quieres almacenar?: ";
            cin >> n;
            if (opcion_raza == 'o')
                arregloO = new Orcs[n];

            if (opcion_raza == 'h')
                arregloH = new Humans[n];

            if (opcion_raza == 'e')
                arregloE = new Elfs[n];

            break;

        default:
            cout << "Opcion invalida" << endl;
            break;
    }

    int opcion;

    // Menu con las opciones disponibles al usuario
    do {
        cout << "\n------- Menu --------" << endl;
        cout << "1. Llenar con informacion aleatoria" << endl;
        cout << "2. Llenar manualmente" << endl;
        cout << "3. Mostrar informacion" << endl;
        cout << "4. Funciones" << endl;
        cout << "5. Cambiar raza actual" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingresa una opcion: ";

        cin >> opcion;

        switch (opcion) {
            case 1: // Llenado aleatorio
                if (opcion_raza == 'o')
                    for (int i = 0; i < n; i++)
                        fillRandom(arregloO[i]);

                if (opcion_raza == 'h')
                    for (int i = 0; i < n; i++)
                        fillRandom(arregloH[i]);

                if (opcion_raza == 'e')
                    for (int i = 0; i < n; i++)
                        fillRandom(arregloE[i]);

                cout << "\nInformacion llenada aleatoriamente con exito :)" << endl;
                break;

            case 2: // Llenado Manual
                if (opcion_raza == 'o')
                    for (int i = 0; i < n; i++)
                        fillManual(arregloO[i]);

                if (opcion_raza == 'h')
                    for (int i = 0; i < n; i++)
                        fillManual(arregloH[i]);

                if (opcion_raza == 'e')
                    for (int i = 0; i < n; i++)
                        fillManual(arregloE[i]);

                cout << "\nInformacion llenada manualmente con exito :)" << endl;

                break;

            case 3: // Mostrar la informacion
                if (opcion_raza == 'o')
                    for (int i = 0; i < n; i++)
                        showInfo(arregloO[i]);

                if (opcion_raza == 'h')
                    for (int i = 0; i < n; i++)
                        showInfo(arregloH[i]);

                if (opcion_raza == 'e')
                    for (int i = 0; i < n; i++)
                        showInfo(arregloE[i]);

                break;

            case 4: // Utilizar las funciones de cada raza
                int opcionF;
                do {
                    if (opcion_raza == 'o') { // Orcos
                        cout << "\n-- FUNCIONES DISPONIBLES --" << endl;
                        cout << "1. Invadir" << endl;
                        cout << "2. Entrenar" << endl;
                        cout << "3. Atacar" << endl;
                        cout << "0. Salir" << endl;
                        cout << "---------------------------" << endl;
                        cout << "Ingresa una opcion: ";
                        cin >> opcionF;

                        switch(opcionF) {
                            case 1:
                                arregloO[0].invade();
                                break;

                            case 2:
                                arregloO[0].train();
                                break;

                            case 3:
                                arregloO[0].attack();
                                break;

                            case 0:
                                cout << "Cerrando menu ..." << endl;
                                break;

                            default:
                                cout << "Ingresa una opcion valida" << endl;
                                break;
                        }
                    }

                    if (opcion_raza == 'h') { // Humanos
                        cout << "\n-- FUNCIONES DISPONIBLES --" << endl;
                        cout << "1. Construir" << endl;
                        cout << "2. Cambiar ocupacion" << endl;
                        cout << "3. Atacar" << endl;
                        cout << "0. Salir" << endl;
                        cout << "---------------------------" << endl;
                        cout << "Ingresa una opcion: ";
                        cin >> opcionF;

                        switch(opcionF) {
                            case 1:
                                arregloH[0].build();
                                break;

                            case 2:
                                arregloH[0].change_ocupation();
                                break;

                            case 3:
                                arregloH[0].attack();
                                break;

                            case 0:
                                cout << "Cerrando menu ..." << endl;
                                break;

                            default:
                                cout << "Ingresa una opcion valida" << endl;
                                break;
                        }
                    }

                    if (opcion_raza == 'e') { // Elfos
                        cout << "\n-- FUNCIONES DISPONIBLES --" << endl;
                        cout << "1. Hechizar" << endl;
                        cout << "2. Curar" << endl;
                        cout << "3. Atacar" << endl;
                        cout << "0. Salir" << endl;
                        cout << "---------------------------" << endl;
                        cout << "Ingresa una opcion: ";
                        cin >> opcionF;

                        switch(opcionF) {
                            case 1:
                                arregloE[0].bewitch();
                                break;

                            case 2:
                                arregloE[0].heal();
                                break;

                            case 3:
                                arregloE[0].attack();
                                break;

                            case 0:
                                cout << "Cerrando menu ..." << endl;
                                break;

                            default:
                                cout << "Ingresa una opcion valida" << endl;
                                break;
                        }
                    }
                } while (opcionF != 0);

                break;

            case 5: // Cambio de raza a utilizar
                n = 1;
                do {
                    cout << "Elige una raza nueva (Orcos ('o') / Humanos ('h') / Elfos ('e')): ";
                    cin >> opcion_raza;
                } while (opcion_raza != 'o' && opcion_raza != 'h' && opcion_raza != 'e');

                do {
                    cout << "Un elemento (1) / Arreglo de elementos (2)" << endl;
                    cout << "Ingresa la opcion: ";
                    cin >> opcionG;
                } while (opcionG != 1 && opcionG != 2);

                switch (opcionG) {
                    case 1:
                        if (opcion_raza == 'o')
                            arregloO = new Orcs[n];

                        if (opcion_raza == 'h')
                            arregloH = new Humans[n];

                        if (opcion_raza == 'e')
                            arregloE = new Elfs[n];

                        break;

                    case 2:
                        cout << "¿Cuantos elementos quieres almacenar?: ";
                        cin >> n;
                        if (opcion_raza == 'o')
                            arregloO = new Orcs[n];

                        if (opcion_raza == 'h')
                            arregloH = new Humans[n];

                        if (opcion_raza == 'e')
                            arregloE = new Elfs[n];

                        break;

                    default:
                        cout << "Opcion invalida" << endl;
                        break;
                }
                break;

            case 0: // Salir del menu y del programa
                cout << "Saliendo..." << endl;
                exit(0);

            default:
                cout << "Ingresa una opcion valida" << endl;
                break;
        }

    } while (opcion != 0);

    // Liberar memoria alocada para los arreglos de elementos de cada raza
    delete arregloO;
    delete arregloH;
    delete arregloE;

}
