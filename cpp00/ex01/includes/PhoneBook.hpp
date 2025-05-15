
class   Phonebook {
    private :
            int nb_contact;

    public :

        Phonebook();
        ~Phonebook();


        void setNb_contact(int nb){
            this->nb_contact = nb;
        }
        int getNb_contact(){
            return (this->nb_contact);
        }
        void    new_contact();



};