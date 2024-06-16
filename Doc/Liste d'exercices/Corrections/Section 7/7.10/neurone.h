#include <vector>
using namespace std;

class Neurone
{
    vector<float> entrees;
    vector<float> poids;

public:
    Neurone();
    ~Neurone();

    vector<float> getEntrees();
    vector<float> getPoids();

    void setEntrees(vector<float>);
    void setPoids(vector<float>);

    float sortie();
};