class NombreComplexe
{
    double partieRelle;
    double partieImaginaire;

public:
    NombreComplexe();
    ~NombreComplexe();

    double getPartieRelle();
    double getPartieImaginaire();

    void setPartieReelle(double);
    void setPartieImaginaire(double);
};

NombreComplexe additionComplexe(NombreComplexe, NombreComplexe);

NombreComplexe multiplicationComplexe(NombreComplexe, NombreComplexe);

NombreComplexe divisionComplexe(NombreComplexe, NombreComplexe);