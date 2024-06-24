#include 'rdb.h'
relation *union1(relation *r1,relation *r2){
    relation *result=new relation;
    if(r1->nattr!=r2->nattr){
        cout<<"given relations are not compatible for union"<<endl;
        return result;
        exit(0);
    }
    int a=r2->nattr;
    int columnindex[a];
    int j=0;
    for(auto it=r1->attrnames.begin();it!=r1->attrnames.end();it++){
        int flag=0;
        int i=0;
        for(auto it1=r2->attrnames.begin();it1!=r1->attrnames.end();it1++){
            if(it1==it){
                flag=1;
                columnindex[j]=i;
                j++;
                break;
            }
            i++;
        }
        if(flag==0){
            cout<<"given relations are not compatible for union"<<endl;
            return NULL;
            exit(0);
        }
    }
    for(auto it=r1->attrnames.begin();it!=r1->attrnames.end();it++){
        result->attrnames.push_back(*it);
    }
    for(auto it=r1->attrinds.begin();it!=r1->attrinds.end();it++){
        result->attrinds.push_back(*it);
    }
    if(!((r1->recs).empty())){
        for(auto it=r1->recs.begin();it!=r1->recs.end();it++){
            result->recs.push_back(*it);
        }
    }
    result->nattr=r1->nattr;
    result->nrecs=r1->nrecs;
    if(!((r2->recs).empty())){
        for(auto it=r2->recs.begin();it!=r2->recs.end();it++){
            record *temp;
            temp=(*(*it)).changerecordorder(columnindex);
            int flag=0;
            for(auto it1=result->recs.begin();it1!=result->recs.end();it1++){
                if((*it1)->attrptr==temp->attrptr){
                    flag=1;
                    break;
                }
            }
            if(!(flag)){
                result->recs.push_back(temp);
            }
        }
    }
    return result;

}
relation *difference(relation *r1,relation *r2){
    relation *result=new relation;
    if(r1->nattr!=r2->nattr){
        cout<<"given relations are not compatible for difference"<<endl;
        return NULL;
        exit(0);
    }
    int a=r2->nattr;
    int columnindex[a];
    int j=0;
    for(auto it=r2->attrnames.begin();it!=r2->attrnames.end();it++){
        int flag=0;
        int i=0;
        for(auto it1=r1->attrnames.begin();it1!=r1->attrnames.end();it1++){
            if(it1==it){
                flag=1;
                columnindex[j]=i;
                j++;
                break;
            }
            i++;
        }
        if(flag==0){
            cout<<"given relations are not compatible for difference"<<endl;
            return NULL;
            exit(0);
        }
    }
    for(auto it=r1->recs.begin();it!=r1->recs.end();it++){
        record *temp;
        temp=(*(*it)).changerecordorder(columnindex);
        int flag=0;
        for(auto it1=r2->recs.begin();it1!=r2->recs.end();it1++){
            if((*it1)->attrptr==(temp)->attrptr){
                flag==1;
                break;
            }
        }
        if (!flag){
            result->recs.push_back(*it);
        }
    }
    result->attrnames=r1->attrnames;
    result->attrinds=r1->attrinds;
    result->nattr=r1->nattr;
    result->nrecs=result->recs.size();
    return result;

}
relation *cartesianproduct(relation *r1,relation *r2){
    relation *result=new relation;
    result->nattr=r1->nattr+r2->nattr;
    result->nrecs=r1->nrecs*r2->nrecs;
    vector<string> nattrnames;
    for(auto it=r1->attrnames.begin();it!=r1->attrnames.end();it++){
        nattrnames.push_back(*it);
    }
    for(auto it=r2->attrnames.begin();it!=r2->attrnames.end();it++){
        nattrnames.push_back(*it);
    }
    result->attrnames=nattrnames;
    vector<int> nattrinds;
    for(auto it=r1->attrinds.begin();it!=r1->attrinds.end();it++){
        nattrinds.push_back(*it);
    }
    for(auto it=r2->attrinds.begin();it!=r2->attrinds.end();it++){
        nattrinds.push_back(*it);
    }
    result->attrinds=nattrinds;
    for(auto it=r1->recs.begin();it!=r1->recs.end();it++){
        for(auto it1=r2->recs.begin();it1!=r2->recs.end();it1++){
            record *nrecord=new record;
            nrecord=(*(*it)).joinrecord(*it1);
            result->recs.push_back(nrecord);
        }  
    }
    return result;
}
relation *projection(relation *r,list <string> projectattrs){
    relation *result=new relation;
    int columnindex[projectattrs.size()];
    for(auto it=projectattrs.begin();it!=projectattrs.end();it++){
        result->attrnames.push_back(*it);
    }
    int j=0;
    for(auto it=result->attrnames.begin();it!=result->attrnames.end();it++){
        int flag=0;
        int i=0;
        for(auto it1=r->attrnames.begin();it!=r->attrnames.end();it1++){
            if(it1==it){
                flag=1;
                columnindex[j]=i;
                j++;
                break;
            }
            i++;
        }
    }
    for(auto it=r->recs.begin();it!=r->recs.end();it++){
        record *temp=new record;
        temp=(*(*it)).changerecordorder(columnindex);
        int flag=0;
        for(auto it1=result->recs.begin();it1!=result->recs.end();it++){
            if(it==it1){
                flag=1;
                break;
            }
        }
        if(!flag){
            result->recs.push_back(temp);
        }
    }
    return result;
}
relation *rename(relation *r,string s1,string s2){
    int idx=0;
    int flag=0;
    auto it=r->attrnames.begin();
    while(!flag){
        if(*it==s1){
            *it=s2;
            flag=1;
            break;
        }
        idx++;
        it++;
    }
    return r;
}
struct  DNFformula{
    list<list<tuple<string,char,attr*>>> ops;
};
relation *selection(relation *r1,DNFformula *f){
    relation *result=new relation;
    
    for(auto it=r1->attrnames.begin();it!=r1->attrnames.end();it++){
        result->attrnames.push_back(*it);
    }
    for(auto it=r1->attrinds.begin();it!=r1->attrinds.end();it++){
        result->attrinds.push_back(*it);
    }
    
    result->nattr=r1->nattr;
    result->nrecs=r1->nrecs;
    for(auto it=f->ops.begin();it!=f->ops.end();it++){
        relation *result1=new relation;
        for(auto it1=r1->attrnames.begin();it1!=r1->attrnames.end();it++){
        result1->attrnames.push_back(*it1);
        }
        for(auto it1=r1->attrinds.begin();it1!=r1->attrinds.end();it++){
            result1->attrinds.push_back(*it1);
        }
        result1->nattr=r1->nattr;
        result1->nrecs=r1->nrecs;
        for(auto it1=r1->recs.begin();it1!=r1->recs.end();it1++){
            int flag=0;
            for(auto it2=(*it).begin();it2!=(*it).end();it2++){
                auto att=(*it1)->attrptr.begin();
                for(auto column=r1->attrnames.begin();column!=r1->attrnames.end();column++){
                    if(*column==get<0>(*it2)){
                        break;
                    }
                    att++;
                }
                auto op=get<1>(*it2);
                auto lim=get<2>(*it2);
                // if(op=='=='){
                //     if(!((*att)->val==lim)){
                //         flag=1;
                //         break;
                //     }
                // }
                // else if(op=='!='){
                //     if(!((*att)->val!=lim)){
                //         flag=1;
                //         break;
                //     }
                // }
                // else if(op=='<'){
                //     if(!((*att)->val<lim)){
                //         flag=1;
                //         break;
                //     }
                // }
                // else if(op=='<='){
                //     if(!((*att)->val<=lim)){
                //         flag=1;
                //         break;
                //     }
                // }
                // else if(op=='>'){
                //     if(!((*att)->val>lim)){
                //         flag=1;
                //         break;
                //     }
                // }
                // else if(op=='>='){
                //     if(!((*att)->val>=lim)){
                //         flag=1;
                //         break;
                //     }
                // }
            }
            if(flag==1){
                continue;
            }
            result1->recs.push_back(*it1);
        }
        relation *temp=union1(result,result1);
        delete result;
        relation *result=new relation;
        for(auto it2=r1->attrnames.begin();it2!=r1->attrnames.end();it++){
            result->attrnames.push_back(*it2);
        }
        for(auto it2=r1->attrinds.begin();it2!=r1->attrinds.end();it++){
            result->attrinds.push_back(*it2);
        }
        result->nattr=r1->nattr;
        result->nrecs=r1->nrecs;
        for(auto rattr=temp->recs.begin();rattr!=temp->recs.end();rattr++){
            result->recs.push_back(*rattr);
        }
        delete result1;
    }
    return result;
}
