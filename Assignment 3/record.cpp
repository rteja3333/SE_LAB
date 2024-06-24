
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