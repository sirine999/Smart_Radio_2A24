#include "employee.h"

Employee::Employee()
{

}
Employee::Employee(int id,QString nom,QString prenom , QString adresse , QString mail , QString genre , int salaire)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->mail=mail;
    this->genre=genre;
    this->salaire=salaire;
}
bool Employee:: ajouter(){
    QSqlQuery query;


            query.prepare("INSERT INTO Employee (id, nom, prenom, adresse, mail, salaire , genre) "
                          "VALUES (:id, :nom, :prenom, :adresse , :mail, :salaire , :genre)");
            query.bindValue(":id", id);
            query.bindValue(":nom", nom);
            query.bindValue(":prenom", prenom);
             query.bindValue(":adresse", adresse);
              query.bindValue(":mail", mail);
               query.bindValue(":salaire", salaire);
               query.bindValue(":genre", genre);



            return query.exec();
}
QSqlQueryModel* Employee::afficher(){
    QSqlQueryModel* model=new QSqlQueryModel();

       model->setQuery("SELECT* FROM Employee");

       return model;
}
bool Employee::supprimer(int id){
    QSqlQuery query;
              query.prepare("DELETE FROM Employee where id=:id ");
              query.bindValue(":id", id);

        return query.exec();
}
bool Employee::modifier(){
    QSqlQuery query;

        query.prepare("UPDATE Employee set  nom=:nom ,prenom =:prenom,adresse=:adresse, mail=:mail, salaire=:salaire, genre=:genre WHERE id=:id");
        query.bindValue(":id", id);
        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);
         query.bindValue(":adresse", adresse);
          query.bindValue(":mail", mail);
           query.bindValue(":salaire", salaire);
           query.bindValue(":genre", genre);
        return query.exec();
}
QSqlQueryModel * Employee:: getAllId(){
    QSqlQueryModel * model =new QSqlQueryModel();
            model->setQuery("select id from Employee ");
            return model ;
}
Employee* Employee::reademploye (QString val)
{
 QSqlQuery query;
    query.prepare("Select * FROM EMPLOYEe where id='"+val+"'");
        if(query.exec())
        {     while(query.next())
            {
               setId(query.value(0).toInt());
              setNom(query.value(1).toString());
             setPrenom(query.value(2).toString());
             setAdresse(query.value(3).toString());
              setMail(query.value(4).toString());
             setSalaire(query.value(5).toInt());
             setGenre(query.value(6).toString());

            }
        }
     return this;
}


