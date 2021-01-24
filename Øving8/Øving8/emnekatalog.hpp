
#ifndef emnekatalog_hpp
#define emnekatalog_hpp

#include <stdio.h>
#include <iostream> 
#include <map> 
#include <string>
using namespace std;

class CourseCatalog{
public:
    void addCourse(string kode, string navn);
    void removeCourse(string kode);
    string getCourse(string kode);
    map<string,string>emner;
    
};

ostream& operator<<(ostream& os, const CourseCatalog& q);
void test(CourseCatalog q);

#endif /* emnekatalog_hpp */
