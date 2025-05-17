#include <iostream>
using namespace std;

int main() {
    cout << "Menu Principal :\n1. Pokédex\n2. Gymnases\n3. Statistiques\n4. Combat Maître\n5. Interactions\nChoix : ";
    int choix;
    cin >> choix;
    switch (choix) {
        case 1: system("./Pokedex"); break;
        case 2: system("./Gymnase"); break;
        case 3: system("./Badges"); break;
        case 4: system("./CombatMaitre"); break;
        case 5: system("./Interaction"); break;
        default: cout << "Choix invalide\n"; break;
    }
    return 0;
}
