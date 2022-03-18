

class level
{
protected:
    unsigned int _deepth;
public:
    level(unsigned int inDeepth = 0): _deepth(inDeepth){} ;
    ~level(){};
    virtual void setDepth(unsigned int inDepth);
};

