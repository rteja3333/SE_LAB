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
            vector<attr*> attrptr_;
            for(auto column=1;column<=nattr;column++){
                cout<<*columnname<<":";
                columnname++;                
                if(*dtype==1){
                    int value;
                    cin>>value;
                    attr *a=new integerattribute (value);
                    attrptr_.push_back(a);
                }
                else if(*dtype==2){
                    float value;
                    cin>>value;
                    attr *a=new floatattribute (value);
                    attrptr_.push_back(a);
                }
                else if(*dtype==3){
                    string value;
                    cin>>value;
                    attr *a=new stringattribute (value);
                    attrptr_.push_back(a);
                }
                r->attrptr=attrptr_;
                recs.push_back(r);
                dtype++;
            }
        }
    }
    void printdata(void){
        for(auto rowit=recs.begin();rowit!=recs.end();rowit++){
            auto columnname=attrnames.begin();
            int i=1;
            for(auto columnit=(*rowit)->attrptr.begin();columnit!=(*rowit)->attrptr.end();columnit++){
                cout<<i<<endl;
                cout<<*columnname<<":";
                cout<<(*columnit)->val<<"\t";
                columnname++;
                i++;
            }
            cout<<"\n";
        }
    }


};


