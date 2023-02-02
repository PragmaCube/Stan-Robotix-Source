class Vecteur
{
  float mX, mY;

public:
  Vecteur();
  ~Vecteur();

  float getX();
  float getY();
  float getNorme();

  void setX(float);
  void setY(float);
};

float produitScalaire(Vecteur, Vecteur);