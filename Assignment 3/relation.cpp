class relation{
    public:
    int nattr,nrecs;
    list <record*> recs;
    vector <string> attrnames;
    vector <int> attrinds;
    void setsize(int rows,int columns){
        nrecs=rows;
        nattr=columns;
        attrnames.resize(nattr);
        recs.resize(rows);
        for (auto it=recs.begin();it!=recs.end();it++){
            (*it)->attrptr.resize(columns);
        }
    }
    
    void setcolumnnames(void){
        int i=1;
        for(auto it=attrnames.begin();it!=attrnames.end();it++){
            cout<<i<<".";
            cin>>*it;
            i++;
        }
    }
    void setdataypes(void){
        cout<<"enter dataypes :\n 1 - int\n 2 - float\n 3 - string";
        int i=1;
        for(auto it=attrinds.begin();it!=attrinds.end();it++){
            cout<<"column "<<i<<".";
            cin>>*it;
            i++;
        }
    }
    void setdata(void){
        for(auto it=recs.begin();it!=recs.end();it++){
            auto dtype=attrinds.begin();
            auto columnname=attrnames.begin();
            for(auto row=(*it)->attrptr.begin();row!=(*it)->attrptr.end();row++){
                cout<<*columnname<<":";
                columnname++;
                dtype++;
                
                if(*dtype==1){
                    int value;
                    cin>>value;
                    row = new integerattribute (value);
                    
                }
                else if(*dtype==2){
                    float value;
                    cin>>value;
                    floatattribute a(value);
                    row=&a;
                }
                else if(*dtype==3){
                    string value;
                    cin>>value;
                    stringattribute a(value);
                    row=&a;
                }
            }
        }
    }


};

