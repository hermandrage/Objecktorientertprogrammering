

#include "emnekatalog.hpp"

ostream& operator<<(ostream& os, const CourseCatalog& q){
    for (map<string,string>::const_iterator it=q.emner.begin(); it!=q.emner.end(); it++) {
        os << it->first << " - " << it->second << endl;
    }
    return os;
}
void CourseCatalog::addCourse(string kode, string navn){
    emner[kode]=navn;
}
void CourseCatalog::removeCourse(string kode){
    emner.erase(kode);
}
string CourseCatalog::getCourse(string kode){
    return emner[kode];
}
void test(CourseCatalog q){
    q.addCourse("TDT4110", "Informasjonsteknologi");
    q.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
    q.addCourse("TMA4100", "Matematikk 1");
    //q.addCourse("TDT4102", "C++"); bytter ut den forrige "verdien"
    //q.emner.insert(pair<string, string>("TDT4102","C++")) -> skjer ingenting
    
    cout << q;
}
