#include <iostream>
#include <string>
#include <vector>

struct Objet {
    int  tx, ty, angle, echelle, profondeur;
    std::string nom, parent;
    int x,y,angleMonde,echelleMonde,niveau;
};
int normaliserAngle(int angle)
{
    angle %= 360;

    if (angle < 0)
    {
        angle += 360;
    }

    return angle;
}
void calculerObjet(Objet& objet, const std::vector<Objet>& objets)
{
    if (objet.parent == "-")
    {
        objet.x = objet.tx;
        objet.y = objet.ty;
        objet.angleMonde = normaliserAngle(objet.angle);
        objet.echelleMonde = objet.echelle;
        objet.niveau = 1;

        return ;
    }

    const Objet* parent = nullptr;

    for (const Objet& o : objets)
    {
        if (o.nom == objet.parent)
        {
            parent = &o;
            break;
        }
    }
    if (parent == nullptr)
    {
        return ;
    }
    int ax = objet.tx * parent->echelleMonde;
    int ay = objet.ty * parent->echelleMonde;
    int rx = 0;
    int ry = 0;
    switch (parent->angleMonde)
    {
        case 0:
            rx = ax;
            ry = ay;
            break;

        case 90:
            rx = -ay;
            ry = ax;
            break;

        case 180:
            rx = -ax;
            ry = -ay;
            break;

        case 270:
            rx = ay;
            ry = -ax;
            break;
    }
    objet.x = parent->x + rx;
    objet.y = parent->y + ry;
    objet.angleMonde =
        normaliserAngle(parent->angleMonde + objet.angle);
    objet.echelleMonde =
        parent->echelleMonde * objet.echelle;
    objet.niveau = parent->niveau + 1;
}

int main()
{
    int N;
    std::cin >> N;

    std::vector<Objet> objets;

    int profondeurMax = 0;

    for (int i = 0; i < N; ++i)
    {
        Objet objet;

        std::cin >> objet.nom >> objet.parent >> objet.tx >> objet.ty >> objet.angle >> objet.echelle;

        calculerObjet(objet, objets);

        if (objet.niveau > profondeurMax)
        {
            profondeurMax = objet.niveau;
        }

        objets.push_back(objet);
    }

    for (const Objet& objet : objets)
    {
        std::cout << objet.nom << " " << objet.x << " " << objet.y << " " << objet.angleMonde << " " << objet.echelleMonde << "\n";
    }

    std::cout << "PROFONDEUR " << profondeurMax << "\n";

    return 0;
}
    