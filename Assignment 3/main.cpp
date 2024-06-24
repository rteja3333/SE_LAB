
#include <bits/stdc++.h>
using namespace std;
class attr{
    public:
    virtual bool operator==(const attr &right)=0;
    virtual bool operator!=(const attr &right)=0;
    virtual bool operator<(const attr &right)=0;
    virtual bool operator<=(const attr &right)=0;
    virtual bool operator>(const attr &right)=0;
    virtual bool operator>=(const attr &right)=0;
};
class integerattribute:public attr{
public:
    int val;
    integerattribute(int v):val(v){}
    bool operator==(const attr &right){
        const integerattribute &right1=static_cast<const integerattribute&>(right);
        return right1.val==val;
    }
    bool operator!=(const attr &right){
        const integerattribute &right1=static_cast<const integerattribute&>(right);
        return right1.val!=val;
    }
    bool operator<(const attr &right){
        const integerattribute &right1=static_cast<const integerattribute &>(right);
        return right1.val<val;
    }
    bool operator<=(const attr &right){
        const integerattribute &right1=static_cast<const integerattribute&>(right);
        return right1.val<=val;
    }
    bool operator>(const attr &right){
        const integerattribute &right1=static_cast<const integerattribute&>(right);
        return right1.val>val;
    }
    bool operator>=(const attr &right){
        const integerattribute &right1=static_cast<const integerattribute&>(right);
        return right1.val>=val;
    }
};
class floatattribute:public attr{
    public:
    float val;
    floatattribute(float v):val(v){}
    bool operator==(const attr &right){
        const floatattribute &right1=static_cast<const floatattribute&>(right);
        return right1.val==val;
    }
    bool operator!=(const attr &right){
        const floatattribute &right1=static_cast<const floatattribute&>(right);
        return right1.val!=val;
    }
    bool operator<(const attr &right){
        const floatattribute &right1=static_cast<const floatattribute &>(right);
        return right1.val<val;
    }
    bool operator<=(const attr &right){
        const floatattribute &right1=static_cast<const floatattribute&>(right);
        return right1.val<=val;
    }
    bool operator>(const attr &right){
        const floatattribute &right1=static_cast<const floatattribute&>(right);
        return right1.val>val;
    }
    bool operator>=(const attr &right){
        const floatattribute &right1=static_cast<const floatattribute&>(right);
        return right1.val>=val;
    }
};
class stringattribute:public attr{
    public:
    string val;
    stringattribute(string v):val(v){}
    bool operator==(const attr &right){
        const stringattribute &right1=static_cast<const stringattribute&>(right);
        return right1.val==val;
    }
    bool operator!=(const attr &right){
        const stringattribute &right1=static_cast<const stringattribute&>(right);
        return right1.val!=val;
    }
    bool operator<(const attr &right){
        const stringattribute &right1=static_cast<const stringattribute &>(right);
        return right1.val<val;
    }
    bool operator<=(const attr &right){
        const stringattribute &right1=static_cast<const stringattribute&>(right);
        return right1.val<=val;
    }
    bool operator>(const attr &right){
        const stringattribute &right1=static_cast<const stringattribute&>(right);
        return right1.val>val;
    }
    bool operator>=(const attr &right){
        const stringattribute &right1=static_cast<const stringattribute&>(right);
        return right1.val>=val;
    }
};

class record{
    public:
    vector<attr*> attrptr;
    void setsize(int size){
        attrptr.resize(size);
    }
    vector<attr*> getrecord(void){
        return attrptr;
    }
    attr* getattribute(int index){
        return attrptr.at(index);
    }
    void addattr(attr * a){
        attrptr.push_back(a);
    }
    void remattr(void){
        int s=attrptr.size();
        attrptr.resize(s-1);
    }
    int isrecordsame(record *r2){
        for(auto it=attrptr.begin();it!=attrptr.end();it++){
            auto it1=r2->attrptr.begin();
            if(it1!=it){
                return 0;
            }
            it1++;
        }
        return 1;
    }
    record *changerecordorder(int arr[]){
        int idx=0;
        record *result=new record;
        result->setsize(0);
        //cout<<"size of arr"<<sizeof(*arr)/sizeof(int);
        while(idx<(sizeof(*arr)/sizeof(int))){
            //cout<<"enter while loop\n";
            int i=0;
            //cout<<"size ofattrptr\n"<<attrptr.size();
            for(auto it=attrptr.begin();it!=attrptr.end();it++){
                //cout<<i;
                if(i==arr[idx]){
                    //result->addattr(*it);
                    //cout<<(*(*it)).val;
                    (*result).attrptr.push_back((*it));
                    //cout<<"enter for loop\n";
                    idx++;
                    break;
                }
                i++;
            }
        }
        //cout<<"return changorder\n";
        return result;
    }
    record *joinrecord(record *r){
        record *result=new record;
        for(auto it=attrptr.begin();it!=attrptr.end();it++){
            result->attrptr.push_back(*it);
        }
        for(auto it=r->attrptr.begin();it!=r->attrptr.end();it++){
            result->attrptr.push_back(*it);
        }
        return result;
    }

};
class relation{
    public:
    int nattr,nrecs;
    list <record*> recs;
    vector <string> attrnames;
    vector <int> attrinds;
    void setsize(int rows,int columns){
        nrecs=rows;
        nattr=columns;
    }
    
    void setcolumnnames(void){
        cout<<"column names:\n";
        for(auto i=1;i<=nattr;i++){
            cout<<i<<".";
            string a;
            cin>>a;
            attrnames.push_back(a);
        }
    }
    void setdataypes(void){
        cout<<"enter dataypes :\n 1 - int\n 2 - float\n 3 - string\n";
        int i=1;
        for(auto i=1;i<=nattr;i++){
            cout<<i<<".";
            int a;
            cin>>a;
            attrinds.push_back(a);
        }
    }
    void setdata(void){
        for(auto row=1;row<=nrecs;row++){
            cout<<"row "<<row<<":\n";
            auto dtype=attrinds.begin();
            auto columnname=attrnames.begin();
            record *r=new record;
            for(auto column=1;column<=nattr;column++){
                cout<<*columnname<<":";
                columnname++;                
                if(*dtype==1){
                    int value;
                    cin>>value;
                    attr *a=new integerattribute (value);
                    r->attrptr.push_back(a);
                }
                else if(*dtype==2){
                    float value;
                    cin>>value;
                    attr *a=new floatattribute (value);
                    r->attrptr.push_back(a);
                }
                else if(*dtype==3){
                    string value;
                    cin>>value;
                    attr *a=new stringattribute (value);
                    r->attrptr.push_back(a);
                }
                dtype++;
            }
            //cout<<r->attrptr.size();
            recs.push_back(r);
            
            //delete r;
        }
    }

    void createrecord(void){
        auto dtype=attrinds.begin();
        auto columnname=attrnames.begin();
        record *r=new record;
        for(auto column=1;column<=nattr;column++){
            cout<<*columnname<<":";
            columnname++;                
            if(*dtype==1){
                int value;
                cin>>value;
                attr *a=new integerattribute (value);
                r->attrptr.push_back(a);
            }
            else if(*dtype==2){
                float value;
                cin>>value;
                attr *a=new floatattribute (value);
                r->attrptr.push_back(a);
            }
            else if(*dtype==3){
                string value;
                cin>>value;
                attr *a=new stringattribute (value);
                r->attrptr.push_back(a);
            }
            dtype++;
        }
        recs.push_back(r);
    }
    // void printdata(void){
    //     for(auto rowit=recs.begin();rowit!=recs.end();rowit++){
    //         auto columnname=attrnames.begin();
    //         int i=1;
    //         for(auto columnit=(*(*rowit)).attrptr.begin();columnit!=(*(*rowit)).attrptr.end();columnit++){
    //             cout<<"row"<<i<<endl;
    //             cout<<*columnname<<":";
    //             cout<<(*(*columnit)).val<<"\t";
    //             columnname++;
    //             i++;
    //         }
    //         //cout<<"abc\n";
    //     }
    // }
    void printdata(void){
        int j=1;
        for(auto rowit=recs.begin();rowit!=recs.end();rowit++){
            cout<<"roowit:"<<j<<endl;
            auto columnname=attrnames.begin();
            int i=1;
            for(auto columnit=(*(*rowit)).attrptr.begin();columnit!=(*(*rowit)).attrptr.end();columnit++){
                cout<<"row"<<i<<endl;
                cout<<*columnname<<":";
                //cout<<(*(*columnit)).val<<"\t";
                cout<<endl;
                columnname++;
                i++;
            }
            //cout<<"abc\n";
            j++;
        }
    }
};

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
            if((*it1)==(*it)){
                flag=1;
                columnindex[j]=i;
                j++;
                break;
            }
            i++;
        }
        if(flag==0){
            cout<<"given relations are not compatible for union"<<endl;
            return result;
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
    int j=0,flag,i;
    for(auto it=r2->attrnames.begin();it!=r2->attrnames.end();it++){
        flag=0;
        i=0;
        for(auto it1=r1->attrnames.begin();it1!=r1->attrnames.end();it1++){
            if((*it1)==(*it)){
                //cout<<"enter\n";
                flag=1;
                columnindex[j]=i;
                //cout<<"enter1\n";
                j++;
                break;
            }
            i++;
        }
        if(flag==0){
            cout<<"given relations are not compatible for difference"<<endl;
            return result;
            exit(0);
        }
    }
    for(auto it=r1->recs.begin();it!=r1->recs.end();it++){
        record *temp=new record;
        //cout<<"enter2\n";
        temp=(*(*it)).changerecordorder(columnindex);

        //cout<<"enter2\n";
        int flag=0;
        for(auto it1=r2->recs.begin();it1!=r2->recs.end();it1++){
            if((*(*it1)).attrptr==(*temp).attrptr){
                flag==1;
                break;
            }
        }

        if (!flag){
            result->recs.push_back(*it);
        }
    }
    result->attrnames=r1->attrnames;
    //cout<<"enter1\n";
    result->attrinds=r1->attrinds;
    //cout<<"enter2\n";
    result->nattr=r1->nattr;
    //cout<<"enter3\n";
    result->nrecs=result->recs.size();
    //cout<<"enter4\n";
    //cout<<"before return\n";
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
// relation *naturaljoin(relation *r1,relation *r2,list<string> joinattr ){
//     relation *result=new relation;
//     relation *p=cartesianproduct(r1,r2);
    
//     int size=r2->nattr;
//     int columnind[size];
//     auto r2attr=r2->attrnames.begin();
//     int j=0;
//     for(int i=0;i<size;i++){
//         for(auto commonattr=joinattr.begin();commonattr!=joinattr.end();commonattr++){
//             if((*r2attr)==(*commonattr)){
//                 columnind[j]=i;
//                 j++;
//                 break;
//             }
//         }
//         r2attr++;
//     }
// }
void ui(vector<relation*> tables){
    int exit=0;
    cout<<"1.show existing tables\n"<<endl;
    cout<<"2.create new table\n"<<endl;
    cout<<"3.delete an existing table\n"<<endl;
    cout<<"4.add a record to a table\n"<<endl;
    cout<<"5.create a table from existing tables using operations\n"<<endl;
    int choice;
    cout<<"Enter choice:"<<endl;
    cin>>choice;
    if(choice==1){
        int i=1;
        for(auto it=tables.begin();it!=tables.end();it++){
            cout<<"Table"<<i<<" :"<<endl;
            (*it)->printdata();
            i++;
        }
    }
    else if(choice==2){
        relation *nrel=new relation;
        int a,b;
        cout<<"enter size of the table:";
        cin>>a>>b;
        nrel->setsize(a,b);
        nrel->setcolumnnames();
        nrel->setdataypes();
        nrel->setdata();
        tables.push_back(nrel);
    }
    else if(choice==3){
        int tableno;
        cout<<"enter the table number which need to be deleted:";
        cin>>tableno;
        int i=1;
        for(auto it=tables.begin();it!=tables.end();it++){
            if(i==tableno){
                tables.erase(it);
                break;
            }
            i++;
        }   
    }
    else if(choice==4){
        int tableno;
        cout<<"enter the table number in which record needs to be added:";
        cin>>tableno;
        int i=1;
        for(auto it=tables.begin();it!=tables.end();it++){
            if(i==tableno){
                (*it)->createrecord();
                break;
            }
            i++;
        }   
    }
    else if(choice==5){
        relation *rnew=new relation;
        int choice1;
        cout<<"1.union"<<endl;
        cout<<"2.difference"<<endl;
        cout<<"3.cartesian product"<<endl;
        cout<<"4.projection"<<endl;
        cout<<"5.rename"<<endl;
        cout<<"6.selection"<<endl;
        cout<<"7.natural join"<<endl;
        cout<<"enter your choice :";
        cin>>choice1;
        if(choice1==1){
            int table1,table2;
            cout<<"enter table numbers:";
            cin>>table1;
            cin>>table2;
            int i=1;
            auto it=tables.begin();
            for(auto it=tables.begin();it!=tables.end();it++){
                if(i==table1){
                    break;
                }
                i++;
            }
            i=1;
            auto it1=tables.begin();
            for(auto it1=tables.begin();it1!=tables.end();it1++){
                if(i==table2){
                    break;
                }
                i++;
            }
            tables.push_back(union1(*it,*it1));
        }
        else if(choice1==2){
            int table1,table2;
            cout<<"enter table numbers:";
            cin>>table1;
            cin>>table2;
            int i=1;
            auto it=tables.begin();
            auto it1=tables.begin();
            for(auto it=tables.begin();it!=tables.end();it++){
                if(i==table1){
                    break;
                }
                i++;
            }
            i=1;
            for(auto it1=tables.begin();it1!=tables.end();it1++){
                if(i==table2){
                    break;
                }
                i++;
            }
            tables.push_back(difference(*it,*it1));

        }
        else if(choice1==3){
            int table1,table2;
            cout<<"enter table numbers:";
            cin>>table1;
            cin>>table2;
            int i=1;
            auto it=tables.begin();
            auto it1=tables.begin();
            for(auto it=tables.begin();it!=tables.end();it++){
                if(i==table1){
                    break;
                }
                i++;
            }
            i=1;
            for(auto it1=tables.begin();it1!=tables.end();it1++){
                if(i==table2){
                    break;
                }
                i++;
            }
            tables.push_back(cartesianproduct(*it,*it1));
        }
        else if(choice1==4){
            int tableno;
            cout<<"enter table no:";
            cin>>tableno;
            int i=1;
            auto it=tables.begin();
            for(auto it=tables.begin();it!=tables.end();it++){
                if(i==tableno){
                    break;
                }
            }
            list<string> projattr;
            string str;
            int addingattr;
            cout<<"enter the attributes names which need to be projected(column names):";
            cin>>str;
            projattr.push_back(str);
            cout<<"enter =0-stop adding attr names,1-add attr name";
            cin>>addingattr;
            while(addingattr){
                cin>>str;
                projattr.push_back(str);
                cout<<"enter =0-stop adding attr names,1-add attr name";
                cin>>addingattr;
            }
            tables.push_back(projection(*it,projattr));
            
        }
        else if(choice1==5){
            int tableno;
            cout<<"enter table no:";
            cin>>tableno;
            int i=1;
            auto it=tables.begin();
            for( it=tables.begin();it!=tables.end();it++){
                if(i==tableno){
                    break;
                }
            }
            cout<<"enter the attribute name(column name) which need to be renamed:";
            string rattrname;
            cin>>rattrname;
            cout<<"enter new name:";
            string newname;
            cin>>newname;
            tables.push_back(rename((*it),rattrname,newname));            
        }
        else if(choice1==6){
            
        }
        else if(choice1==7){
            int table1,table2;
            cout<<"enter table numbers:";
            cin>>table1;
            cin>>table2;
            int i=1;
            auto it=tables.begin();
            auto it1=tables.begin();
            for(auto it=tables.begin();it!=tables.end();it++){
                if(i==table1){
                    break;
                }
                i++;
            }
            i=1;
            for(auto it1=tables.begin();it1!=tables.end();it1++){
                if(i==table2){
                    break;
                }
                i++;
            }
            list<string> joinattr;
            string str;
            int addingattr;
            cout<<"enter the common attributes names(column names):";
            cin>>str;
            joinattr.push_back(str);
            cout<<"enter =0-stop adding attr names,1-add attr name";
            cin>>addingattr;
            while(addingattr){
                cin>>str;
                joinattr.push_back(str);
                cout<<"enter =0-stop adding attr names,1-add attr name";
                cin>>addingattr;
            }
            //tables.push_back(naturaljoin(*it,*it1,joinattr));
        }
        
    }
    cout<<"enter 1 to exit , else 0:\n";
    cin>>exit;
    if(!(exit)){
        ui(tables);
    }
    return ;
}

 int main(){
       // vector<relation*> tables;
       // ui(tables);
    relation *a=new relation;
    a->nattr=2;
    a->nrecs=2;
    //cout<<"main";
    a->setcolumnnames();
    a->setdataypes();
    a->setdata();
   // cout<<"size of recs:";
    //cout<<(*(a->recs.begin()))->attrptr.size();
    //a.printdata();
//     // cout<<"aaaaaaaaaaa";
//     // int arr[]={1,2};
//     // cout<<sizeof(arr)/sizeof(int);
//     return 0;
relation *b=new relation;
    b->nattr=2;
    b->nrecs=2;
    cout<<"main";
    b->setcolumnnames();
    b->setdataypes();
    b->setdata();
relation *c=difference(a,b);
cout<<(*(*(c->recs.begin()))->attrptr.begin())->val;

    return 0;
    
}
