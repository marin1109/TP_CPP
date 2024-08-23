#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
    srand(time(nullptr));
    int x {rand()};
    int i {1};
    cout << "Le nombre mystère est : " << x << endl;
    cout << "Bienvenue dans le jeu du nombre mystère !" << endl;
    while (true){
        cout << "Entrez un nombre pour deviner le nombre mystère : ";
        int y;
        cin >> y;
        if (y < x){
            cout << "C'est plus !" << endl;
        } else if (y > x){
            cout << "C'est moins !" << endl;
        } else {
            cout << "Bravo, vous avez trouvé le nombre mystère en " << i << " coups !" << endl;
            break;
        }
        i++;
    }
    return EXIT_SUCCESS;
}