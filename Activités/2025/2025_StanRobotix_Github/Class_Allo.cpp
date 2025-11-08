class Allo
{
    int mAllo = 3232;
    int mSalut =6622;
public:
    Allo();
    ~Allo();
    int getAllo();
    int getSalut();
};

Allo::Allo() { }

Allo::~Allo() { }

int Allo::getAllo()
{
    return mAllo;
}
int Allo::getSalut()
{
    return mSalut;
}