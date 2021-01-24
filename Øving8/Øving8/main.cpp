
#include "filEn.hpp"
#include <iostream> 
#include "emnekatalog.hpp"
#include "tegnstatistikk.hpp"
#include "ordstatestikk.hpp"
using namespace std;

int main(){
    skrivTilFil("eple.txt");
    
    lesFraFil("eple.txt", "fisk.txt");
    
    /*string a="abi";
    cout << a[1] << endl;
    cout << static_cast<int>(a[1]) << endl;
    cout << 'q'-static_cast<int>(a[0]) << endl;
    */
    // cout << char('a'+1) << endl;
    
    CourseCatalog q;
    test(q);
    tegnstatestikk("eple.txt");
    
    cout << "\n \n oppg4 \n";
    
    lagStatestikk("eple.txt");
    return 0;
}
