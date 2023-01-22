# ifndef __PAIRE_HPP__
#define __PAIRE_HPP__

namespace ft
{
    template <class T1, class T2> 
    class pair
    {
        //init memnbre
        public:
        T1 first;
        T2 second;

        //constructeur par defaut
        pair(): first(), second(){}
        //constructeur par copie
        //ref constant a la classe pair avec membre first et second
        //pour affecter un objet a un autre
        pair (const pair<T1, T2>& other) : first(other.first), second(other.second) {}
    };

    template <typename T1, typename T2>
    class pair {
    public:
        T1 first;
        T2 second;

        // constructeur par défaut
        //init les valeurs 
        pair() : first(), second() {}

        // constructeur prenant les valeurs pour initialiser les membres
        pair(const T1& first, const T2& second) : first(first), second(second) {}

        // constructeur par copie
        pair(const pair<T1, T2>& other) : first(other.first), second(other.second) {}

        // surcharge de l'operateur d'affectation pour copier les objets
        pair<T1, T2>& operator=(const pair<T1, T2>& other) {
            first = other.first;
            second = other.second;
            return *this;
        }

        // destructeur
        ~pair() {
            // code de nettoyage ici si nécessaire
        }

        //stocke deux valeurs de n'importe quel type

};

}

#endif