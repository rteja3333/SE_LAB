
#include <bits/stdc++.h>
#include 'rdb.h'
using namespace std;
class attr;
class record;
class realtion;
class integerattribute:public attr;
class floatattribute:public attr;
class stringattribute:public attr;

relation *union1(relation *,relation *);
relation *naturaljoin(relation *,relation *,list<string>);
relation *difference(relation *,relation *);
relation *cartesianproduct(relation *,relation *);
relation *projection(relation *,list<string>);
relation *rename(relation *,string,string);
relation  *selection(relation *,DNFformula *);