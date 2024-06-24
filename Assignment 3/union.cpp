relation *union(relation *r1,relation *r2){
    relation *result;
    if(r1->nattr!=r2->nattr){
        cout<<"given relations are not compatible for union"<<endl;
        exit();
    }
    int a=r2->nattr;
    int columnindex[a];
    int j=0;
    for(auto it=r1->attrnames.begin();it!=r1->attrnames.end();it++){
        int flag=0;
        int i=0;
        for(auto it1=r2->attrnames.begin();it!=r1->attrnames.end();it1++){
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
            exit();
        }
    }
    for(auto it=r1->attrnames.begin();it!=r1->attrnames.end();it++){
        result->attrnames.push_back(it);
    }
    for(auto it=r1->attrinds.begin();it!=r1->attrinds.end();it++){
        result->attrinds.push_back(it);
    }
    for(auto it=r1->recs.begin();it!=r1->recs.end();it++){
        result->recs.push_back(it);
    }
    result->nattr=r1->nattr;
    result->nrecs=r1->nrecs;
    for(auto it=r2->recs.begin();it!=r2->recs.end;it++){
        record *temp;
        temp=it->changerecordorder(columnindex);
        int flag=0;
        for(auto it1=result->recs.begin(),it1!=result->recs.end();it1++){
            if(it1==temp){
                flag=1;
                break;
            }
        }
        if!(flag){
            result->recs.push_back(temp);
        }
    }
    return result;

}
