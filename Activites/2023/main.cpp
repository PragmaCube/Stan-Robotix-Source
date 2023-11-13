class Sonic
{
const float vitesse = 342.88;
public:
Sonic();
~Sonic();
float getVitesse();
float distanceParcourue(float secondes);
};
Sonic::Sonic() { }
Sonic::~Sonic() { }
float Sonic::getVitesse()
{
return vitesse;
}
float Sonic::distanceParcourue(float secondes)
41
{
return vitesse * secondes;
}
int main()
{
Sonic sonic;
cout << "Sonic a parcouru " << sonic.distanceParcoure(7200) << " mètres en 2h";
}
