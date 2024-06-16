class Sphere
{
    float rayon;
    const float pi = 3.141592;

public:
    Sphere();
    ~Sphere();

    float getRayon();

    void setRayon(float Rayon);
    
    float getAire();
    float getVolume();
};