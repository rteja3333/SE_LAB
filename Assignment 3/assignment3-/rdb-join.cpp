#include 'rdb.h'
relation *naturaljoin(relation *r1,relation *r2,list<string> joinattr ){
    relation *result=new relation;
    relation *p=cartesianproduct(r1,r2);
    int size1=r1->nattr;
    int size2=r2->nattr;
    int columnind1[size1];
    int columnind2[size2];
    auto r1attr=r1->attrnames.begin();
    int j=0;
    for(int i=0;i<size1;i++){
        for(auto commonattr=joinattr.begin();commonattr!=joinattr.end();commonattr++){
            if((*r1attr)==(*commonattr)){
                columnind1[j]=i;
                j++;
                break;
            }
        }
        r1attr++;
    }
    auto r2attr=r2->attrnames.begin();
    for(int i=0;i<size2;i++){
        for(auto commonattr=joinattr.begin();commonattr!=joinattr.end();commonattr++){
            if((*r2attr)==(*commonattr)){
                columnind2[j]=i;
                j++;
                break;
            }
        }
        r2attr++;
    }
    auto r2recs=r2->recs.begin();
    for(auto r1recs=r1->recs.begin();r1recs!=r1->recs.end;r1recs++){
        record *nrec=new record;
        for(auto r1row=(*r1recs)->attrptr.begin();r1row!=(*r1recs)->attrptr.end();r1row++){
            nrec->attrptr.push_back(*r1row);
        }
        int i=0;
        auto r2attrname=r2->attrnames.begin();
        for(auto r2row=(*r2recs)->attrptr.begin();r2row!=(*r2recs)->attrptr.end();r2row++){
            int flag=0;
            auto r1row=(*r1recs)->attrptr.begin();
            for(auto r1attrname=r1->attrnames.begin();r1attrname!=r1->attrnames.end();r1attrname++){
                if((*r1attrname)==(*r2attrname)){
                    if((*(*r1row)).val==(*(*r2row)).val){
                        break;
                    }
                    else{
                        flag=1;
                        break;
                        
                    }
                }
                else{
                    nrec->attrptr.push_back(*r2row);

                }
            }
            r2attrname++;
        }
        r2recs++;
        result->recs.push_back(nrec);
        delete nrec;
    }
    

}

