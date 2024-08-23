#include "Article.hpp"
#include "ArticleEnSolde.hpp"

using namespace std;

int main() {
    Article article("Parapluie", 5);
    std::cout << article << std::endl;

    Article a1("Parapluie", 12);
    cout << a1 << endl;
    
    ArticleEnSolde a2("Botte" ,12,5);
    cout << a2 << endl;
    
    ArticleEnSolde a3(a1);
    cout << a3 << endl;

    return EXIT_SUCCESS;
}
