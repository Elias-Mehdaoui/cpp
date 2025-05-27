#include "AMateria.hpp"

class Cure : public AMateria
{
    public :
        Cure();
        Cure(const Cure& other);
        ~Cure();
        Cure& operator=(const Cure& other);

        Cure *clone() const override;
};