#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <time.h>
using namespace std;
//function for deleting "cost.csv" and adding the first line
void removeCSV()
{
    remove("costs.csv");
    fstream file;
    file.open("costs.csv",ios::out | ios::app);
    file<<"Days,Transport,Accommodation,Makeup,Food,Drinks,Space rental,Discount"<<endl;
    file.close();
}

//function for extracting names randomly from text files
string random_names()
{
    string fullname;
    string fnames[200];
    string lnames[200];
    string pause = " ";
    int a = 0, b = 0;
    int randNum1, randNum2;
    fstream filea, fileb;
    filea.open("prenume.txt");
    fileb.open("nume.txt");

    while(filea.good()){
        getline(filea, fnames[a]);
        a++;
    }

    while(fileb.good()){
        getline(fileb, lnames[b]);
        b++;
    }

    randNum1 = rand()%a;
    randNum2 = rand()%b;
    fullname = fnames[randNum1] + pause + lnames[randNum2];

    return fullname;
}

//function for deleting "meniu.csv" and adding the first line
void removeCSV1()
{
    remove("meniu.csv");
    fstream file;
    file.open("meniu.csv",ios::out | ios::app);
    file<<"Soup,Main Course,Dessert"<<endl;
    file.close();
}

//function for extracting food randomly from text files
string random_food(string file)
{

    string fullname;
    string fnames[50];
    string pause = " ";
    int a = 0, b = 0;
    int randNum1, randNum2;
    fstream file1;
    file1.open(file);


    while(file1.good()){
        getline(file1, fnames[a]);
        a++;
    }


    //srand(time(NULL));
    randNum1 = rand()%a;
    fullname = fnames[randNum1];

    return fullname;
}

//Builder Pattern for food menius
class Meniu{
public:
    vector<string> parts;

    void ListParts()const{
        fstream file;
        file.open("meniu.csv",ios::out| ios::app);
        cout << "Dishes: ";
        for (size_t i=0;i<parts.size();i++){
            if(parts[i]== parts.back()){
                cout << parts[i];
                file<<parts[i];
            }else{
                cout << parts[i] << ", ";
                file<< parts[i] << ", ";
            }
        }
        file<<endl;
        file.close();

        cout << "\n\n";
    }

};

class Builder{
public:
    virtual ~Builder(){}
    virtual void Soup1() const =0;
    virtual void Soup2() const =0;
    virtual void Soup3() const =0;
    virtual void Soup_v_1() const =0;
    virtual void Soup_v_2() const =0;
    virtual void Soup_v_3() const =0;
    virtual void Dish_1() const =0;
    virtual void Dish_2() const =0;
    virtual void Dish_3() const =0;
    virtual void Dish_v1() const =0;
    virtual void Dish_v2() const =0;
    virtual void Dish_v3() const =0;
    virtual void Dish_f1() const =0;
    virtual void Dish_f2() const =0;
    virtual void Dish_f3() const =0;
    virtual void Dessert1() const =0;
    virtual void Dessert2() const =0;
    virtual void Dessert3() const =0;


};

class ConcreteBuilder1 : public Builder{
private:

    Meniu* product;

public:

    ConcreteBuilder1(){
        this->Reset();
    }

    ~ConcreteBuilder1(){
        delete product;
    }

    void Reset(){
        this->product= new Meniu();
    }

    void Soup1()const override{
        srand(time(NULL));
        string food = random_food("ciorbe_all.txt");
        this->product->parts.push_back(food);
    }

    void Soup2() const override{
        string food = random_food("ciorbe_all.txt");
        this->product->parts.push_back(food);
    }

    void Soup3() const override{
        string food = random_food("ciorbe_all.txt");
        this->product->parts.push_back(food);
    }

    void Soup_v_1() const override{
        string food = random_food("ciorbe_veg.txt");
        this->product->parts.push_back(food);
    }

    void Soup_v_2() const override{
        string food = random_food("ciorbe_veg.txt");
        this->product->parts.push_back(food);
    }

    void Soup_v_3() const override{
        string food = random_food("ciorbe_veg.txt");
        this->product->parts.push_back(food);
    }

    void Dish_1()const override{
        string food = random_food("principal_all.txt");
        this->product->parts.push_back(food);
    }

    void Dish_2()const override{
        string food = random_food("principal_all.txt");
        this->product->parts.push_back(food);
    }

    void Dish_3()const override{
        string food = random_food("principal_all.txt");
        this->product->parts.push_back(food);
    }
    void Dish_v1()const override{
        string food = random_food("principal_veg.txt");
        this->product->parts.push_back(food);
    }

    void Dish_v2()const override{
        string food = random_food("principal_veg.txt");
        this->product->parts.push_back(food);
    }

    void Dish_v3()const override{
        string food = random_food("principal_veg.txt");
        this->product->parts.push_back(food);
    }
    void Dish_f1()const override{
        string food = random_food("principal_flex.txt");
        this->product->parts.push_back(food);
    }

    void Dish_f2()const override{
        string food = random_food("principal_flex.txt");
        this->product->parts.push_back(food);
    }

    void Dish_f3()const override{
        string food = random_food("principal_flex.txt");
        this->product->parts.push_back(food);
    }
    void Dessert1()const override{
        string food = random_food("dessert.txt");
        this->product->parts.push_back(food);
    }
    void Dessert2()const override{
        string food = random_food("dessert.txt");
        this->product->parts.push_back(food);
    }
    void Dessert3()const override{
        string food = random_food("dessert.txt");
        this->product->parts.push_back(food);
    }

    Meniu* GetProduct() {
        Meniu* result= this->product;
        this->Reset();
        return result;
    }
};

class Director{

private:
    Builder* builder;

public:

    void set_builder(Builder* builder){
        this->builder=builder;
    }


    void BuildMeniu1All(){
        this->builder->Soup1();
        this->builder->Dish_1();
        this->builder->Dessert1();
    }

    void BuildMeniu1Veg(){
        this->builder->Soup_v_1();
        this->builder->Dish_v1();
        this->builder->Dessert1();
    }

    void BuildMeniu1Flex(){
        this->builder->Soup_v_1();
        this->builder->Dish_f1();
        this->builder->Dessert1();
    }
    void BuildMeniu2All(){
        this->builder->Soup2();
        this->builder->Dish_2();
        this->builder->Dessert2();
    }

    void BuildMeniu2Veg(){
        this->builder->Soup_v_2();
        this->builder->Dish_v2();
        this->builder->Dessert2();
    }

    void BuildMeniu2Flex(){
        this->builder->Soup_v_2();
        this->builder->Dish_f2();
        this->builder->Dessert2();
    }
    void BuildMeniu3All(){
        this->builder->Soup3();
        this->builder->Dish_3();
        this->builder->Dessert3();
    }

    void BuildMeniu3Veg(){
        this->builder->Soup_v_3();
        this->builder->Dish_v3();
        this->builder->Dessert3();
    }

    void BuildMeniu3Flex(){
        this->builder->Soup_v_3();
        this->builder->Dish_f3();
        this->builder->Dessert3();
    }
};

void ClientCode(Director& director)
{
    ConcreteBuilder1* builder = new ConcreteBuilder1();
    director.set_builder(builder);
    cout << ".................Meniu 1................"<<endl;
    director.BuildMeniu1All();

    Meniu* p= builder->GetProduct();
    p->ListParts();
    delete p;

    cout << ".............Meniu vegetarian 1............."<<endl;
    director.BuildMeniu1Veg();

    p= builder->GetProduct();
    p->ListParts();
    delete p;

    // Remember, the Builder pattern can be used without a Director class.
    cout << ".........................Meniu flexitarian 1........................"<<endl;
    director.BuildMeniu1Flex();

    p= builder->GetProduct();
    p->ListParts();
    delete p;

    cout << ".................Meniu 2................"<<endl;
    director.BuildMeniu2All();

    p = builder->GetProduct();
    p->ListParts();
    delete p;

    cout << ".............Meniu vegetarian 2............."<<endl;
    director.BuildMeniu2Veg();

    p= builder->GetProduct();
    p->ListParts();
    delete p;

    // Remember, the Builder pattern can be used without a Director class.
    cout << ".........................Meniu flexitarian 2........................"<<endl;
    director.BuildMeniu2Flex();

    p= builder->GetProduct();
    p->ListParts();
    delete p;

    cout << ".................Meniu 3................"<<endl;
    director.BuildMeniu3All();

    p = builder->GetProduct();
    p->ListParts();
    delete p;

    cout << ".............Meniu vegetarian 3............."<<endl;
    director.BuildMeniu3Veg();

    p= builder->GetProduct();
    p->ListParts();
    delete p;

    // Remember, the Builder pattern can be used without a Director class.
    cout << ".........................Meniu flexitarian 3........................"<<endl;
    director.BuildMeniu3Flex();

    p= builder->GetProduct();
    p->ListParts();
    delete p;

    delete builder;
}

//Abstract Factory Pattern for assigning makeup type
class Makeup{
public:
    virtual string type() = 0;
};

class Vampire:public Makeup{
public:
    string type(){
        string mu_type = "vampire";
        return mu_type;
    }
};

class Werewolf:public Makeup{
public:
    string type(){
        string mu_type = "werewolf";
        return mu_type;
    }
};

class Siren:public Makeup{
public:
    string type(){
        string mu_type = "siren";
        return mu_type;
    }
};

class Psychic:public Makeup{
public:
    string type(){
        string mu_type = "psychic";
        return mu_type;
    }
};

class Human:public Makeup{
public:
    string type(){
        string mu_type = "human";
        return mu_type;
    }
};

class Monster{
public:
    ~Monster();
    virtual Makeup *create_vampire() = 0;
    virtual Makeup *create_werewolf() = 0;
    virtual Makeup *create_siren() = 0;
    virtual Makeup *create_psychic() = 0;
    virtual Makeup *create_human() = 0;
};

class Actor:public Monster{
    Makeup *create_vampire(){
        return new Vampire;
    }

    Makeup *create_werewolf(){
        return new Werewolf;
    }

    Makeup *create_siren(){
        return new Siren;
    }

    Makeup *create_psychic(){
        return new Psychic;
    }

    Makeup *create_human(){
        return new Human;
    }
};

//function for assigning the makeup randomly to the actors and extras
string monster_makeup(){
    int no = rand()%5+1;
    string mu;
    Monster* monster;
    Makeup* makeup;
    if(no == 1)
    {
        monster = new Actor;
        makeup = monster->create_vampire();
        mu = makeup->type();
    }
    else if(no == 2)
    {
        monster = new Actor;
        makeup = monster->create_werewolf();
        mu = makeup->type();
    }
    else if(no == 3)
    {
        monster = new Actor;
        makeup = monster->create_siren();
        mu = makeup->type();
    }
    else if(no == 4)
    {
        monster = new Actor;
        makeup = monster->create_psychic();
        mu = makeup->type();
    }
    else if(no == 5)
    {
        monster = new Actor;
        makeup = monster->create_human();
        mu = makeup->type();
    }

    return mu;
}

//function for assignin every cast member a diet type
string diet()
{
    int no = rand()%3+1;
    string food;

    if(no == 1) food = "anything";
    else if(no == 2) food = "vegetarian";
    else if(no == 3) food = "flexitarian";

    return food;
}

//Cast class
class Cast{
public:
    //method for creating a new file with extras added
    void add_cast(){

        vector<vector<string>> content;
        vector<string> row;
        string line, word;

        //we first delete the csv to rewrite all the names
        remove("cast_f.csv");

        fstream  file1;
        fstream file2;

        file1.open("cast_i.csv",ios::in);
        file2.open("cast_f.csv",ios::out | ios::app);

        string name;
        string fnct;

        //adding the original cast to the new csv

        while(getline(file1,name,',')) {
            getline(file1, fnct, '\n');

            if (file2.is_open()) {
                file2 << name << "," << fnct << endl;

            }
        }


        //adding the extras to the new csv
        srand(time(NULL));
        fnct = "extra";
        for (int i = 1; i <= 132 ; i++)
        {
            name = random_names();
            file2<<name<<","<<fnct<<endl;
        }

        cout<<"Cast added"<<endl;

        file1.close();
        file2.close();

    }

    //function for calculating the number of original cast members
    int nr_pers_cast_i() {
        fstream file;
        file.open("cast_i.csv", ios::in);

        string name, fnct;
        float cnt = 0;

            while (getline(file, name, ',')) {
                getline(file, fnct, '\n');
                cnt += 1;
            }


        file.close();

        return cnt;
    }

    //function for calculating the number of cast members + extras
    int nr_pers_cast_f() {
        fstream file;
        file.open("cast_f.csv", ios::in);

        string name, fnct;
        float cnt = 0;

        while(getline(file, name, ','))
        {
            getline(file, fnct, '\n');
            cnt += 1;
        }

        file.close();

        return cnt;
    }

    //function for adding actors and extras to a new csv to assign each makeup type
    void actor_cast() {


        //we first delete the csv to rewrite all the names
        remove("makeup.csv");

        fstream file1, file2;
        string name, fnct;

        string srch1 = "actor/actress";
        string srch2 = "extra";
        int cnt = 0;

        file1.open("cast_f.csv", ios::in);
        file2.open("makeup.csv", ios::out | ios::app);


        //adding the actors and extras to the new csv
        string line;
        while (getline(file1, line)) {
            stringstream ss(line);
            string field;

            while (getline(ss, field, ',')) {
                if (field == srch1 || field == srch2) {
                    //generating "randomly" the makeup type
                    string mu = monster_makeup();
                    file2<<line<<","<<mu<<endl;
                }
            }
        }

            cout << "Added cast's makeup" << endl;

            file1.close();
            file2.close();

        }

    //function to calculate the number of actors and extras
    int no_actors() {
        fstream file;
        file.open("makeup.csv", ios::in);

        string name, fnct;
        float cnt = 0;

        while(getline(file, name, ','))
        {
            getline(file, fnct, '\n');
            cnt += 1;
        }

        file.close();

        return cnt;
    }

    //calculating number of actors with x makeup or diet type
    int no_of_type(string srch,string filename)
    {
        fstream file;
        int cnt = 0;

        file.open(filename, ios::in);
        string line;
        while (getline(file, line)) {
            stringstream lineStream(line);
            string field;
            int fieldIndex = 0;
            while (getline(lineStream, field, ',')) {
                if (fieldIndex == 2) {
                    if (field == srch) {
                        cnt += 1;
                    }
                }
                ++fieldIndex;
            }
        }

        return cnt;
        file.close();
    }

    //adding each cast memeber"s diet to a new csv
    void add_diet()
    {
        vector<vector<string>> content;
        vector<string> row;
        string line, word;

        //we first delete the csv to rewrite all the names and diets
        remove("diet.csv");

        fstream  file1;
        fstream file2;

        file1.open("cast_f.csv",ios::in);
        file2.open("diet.csv",ios::out | ios::app);

        string name;
        string fnct;

        //adding the fields to the csv
        while(getline(file1,name,','))
        {
            getline(file1,fnct,'\n');

            if (file2.is_open()) {
                //generating "randomly" the type of diet
                string food = diet();
                file2 << name<< ","<<fnct<<","<<food<<endl;

            } else cout << "Could not open the file\n";
        }

        cout<<"Diet added"<<endl;

        file1.close();
        file2.close();
    }
};

//Bus class
class Bus{
public:

    //method for number of buses needed
    int no_of_buses(int cast_f)
    {
        int nr;
        if(cast_f % 50 != 0) nr = (cast_f/50) + 1;
        else nr = cast_f/50;

        return nr;
    }

};

//rooms class
class Rooms{
public:
    //method for calculating number of rooms for original cast members
    float rooms_for_cast(int cast)
    {
        int no = 0;
        if (cast % 2 != 0) no = cast/2 + 1;
        else no = cast/2;
        return no;
    }
    //method for calculating number of rooms for extras
    float rooms_for_extras(int extras)
    {
        int no = 0;
        if (extras % 3 != 0) no = extras/3 + 1;
        else no = extras/3;
        return no;
    }

};

//drinks class
class Drinks{
public:
    //method for calculating number of water litters needed in a day
    int water(int cast_f)
    {
        float water1 = 0;
        water1 = cast_f;
        return water1;
    }

    //method for calculating number of coffee litters needed in a day
    int coffee(int cast_f)
    {
        float coffee1 = 0;
        coffee1 = cast_f * 0.8;
        return coffee1;
    }

    //method for calculating number of juice litters needed in a day
    int juice(int cast_f)
    {
        float juice1 = 0;
        juice1 = cast_f * 0.5;
        return juice1;
    }
};

//cost class
class Cost{
public:
    //method for calculating cost of one way bus ride
    float cost_bus_one_way(int buses)
    {
        float cost = 0;
        cost = buses * 5680;
        cost = cost/4.65;
        return cost;
    }

    //method for calculating cost of both ways bus ride
    float cost_bus_both_ways(int buses)
    {
        float cost = 0;
        cost = buses * 5680 * 2;
        cost = cost / 4.65;
        return cost;
    }

    //method for calculating cost of makeup for a day
    float cost_of_makeup(int v, int w, int s, int p, int h)
    {
        float cost = 0;
        cost = v*230 + w*555 + s*345 + p*157 + h*55;
        cost = cost / 4.65;
        return cost;
    }

    //method for calculating cost of rooms for one night
    float cost_of_rooms(int r_cast,int r_extras)
    {
        float cost = 0;
        cost = r_cast * 350 + r_extras * 420;
        cost = cost / 4.65;
        return cost;
    }

    //method for calculating cost of drinks for one day
    float cost_of_drinks(int water, int coffee, int juice)
    {
        float cost = 0, costw = 0, costc = 0, costj = 0;

        if(water % 2 != 0) (costw = water/2 + 1) * 6;
        else costw = water/2 * 6;

        costc = coffee * 30;


        if(juice % 2 != 0) costj = (juice/2 + 1) * 8;
        else costj = juice/2 * 8;


        cost = costw + costc + costj;
        cost = cost / 4.65;

        return cost;
    }

    //method for calculating cost of food for one day
    float cost_of_food(int any, int veg, int flex)
    {
        float cost = 0;
        cost = any * 40 + veg * 33 + flex * 46;
        cost = cost / 4.65;

        return cost;
    }

    //method for calculating cost of castle rent for one day
    float cost_of_castle()
    {
        float cost = 0;
        cost = 10000 / 4.65;
        return cost;
    }

    //method for calculating cost of something for x days
    float cost_total_fnct(int x, float fnct)
    {
        float cost = x * fnct;
        return cost;
    }

    //method for calculating discount for castle rent for x days
    float discount(int x,float castel)
    {
        float disc = 0;
        disc = (x/10)*0.02*castel;

        return disc;
    }

    //method for calculating cost of total castle rent for x days
    float cost_total_castle(int disc, float castel)
    {
        float cost = castel - disc;
        return cost;
    }

    //method for calculating total cost
    long long cost_total_x(float t_tr, float t_mu, float t_rooms, float t_food, float t_drinks, float t_castel)
    {
        double cost = 0;
        cost = t_tr + t_mu + t_rooms + t_food + t_drinks + t_castel;

        return cost;
    }

    //method for adding the costs to the csv
    void CSV_cost(int x,long long tr, long long rooms, long long mu, long long food, long long drink, long long space, long long disc)
    {
        fstream file;

        file.open("costs.csv",ios::out | ios::app);
        file<<x<<","<<tr<<","<<rooms<<","<<mu<<","<<food<<","<<drink<<","<<space<<","<<disc<<endl;
        file.close();
    }


};

int main() {

    removeCSV();
    removeCSV1();

    Cast cast;
    Bus bus;
    Cost cost;
    Rooms rooms;
    Drinks drinks;

    cout<<"\t\t\t----------------------WELCOME TO THE WEDNESDAY CAST!----------------------\n";

    cast.add_cast();
    cast.actor_cast();
    cast.add_diet();

    cout<<"\t\t\t----------------------HOW BIG IS THE WEDNESDAY FAMILY---------------------\n";
    int cast_i = cast.nr_pers_cast_i();
    cout<<"No. of cast members without extras: "<<cast_i<<endl;
    int cast_f = cast.nr_pers_cast_f();
    cout<<"No. of cast members with extras: "<<cast_f<<endl;
    int cast_act = cast.no_actors();
    cout<<"No. of actors + extras: "<<cast_act<<endl;
    int cast_e = cast_f - cast_i;
    cout<<"No. of extras: "<<cast_e<<endl;

    cout<<"\t\t\t----------------------NEEDED---------------------\n";
    cout<<"\t.............transport................."<<endl;
    cout<<"\n";
    int buses = bus.no_of_buses(cast_f);
    cout<<"No. of buses needed: "<<buses<<endl;
    cout<<"\n";
    cout<<"\t..............makeup kits................"<<endl;
    cout<<"\n";
    int vamp = cast.no_of_type("vampire","makeup.csv");
    cout<<"No. of vampires needed: "<<vamp<<endl;
    int werew = cast.no_of_type("werewolf","makeup.csv");
    cout<<"No. of werewolves needed: "<<werew<<endl;
    int sirens = cast.no_of_type("siren","makeup.csv");
    cout<<"No. of sirens needed: "<<sirens<<endl;
    int psy = cast.no_of_type("psychic","makeup.csv");
    cout<<"No. of vampires needed: "<<psy<<endl;
    int hum = cast.no_of_type("human","makeup.csv");
    cout<<"No. of humans needed: "<<hum<<endl;
    cout<<"\n";
    cout<<"\t..............rooms................"<<endl;
    cout<<"\n";
    int rooms_cast = rooms.rooms_for_cast(cast_i);
    cout<<"No. of rooms for the cast: "<<rooms_cast<<endl;
    int rooms_extras = rooms.rooms_for_extras(cast_e);
    cout<<"No. of rooms for the extras: "<<rooms_extras<<endl;
    cout<<"\n";
    cout<<"\t...............menus..............."<<endl;
    cout<<"\n";
    int anything = cast.no_of_type("anything","diet.csv");
    cout<<"No. of menus for people who can eat anything for one day: "<<anything<<endl;
    int vegetarians = cast.no_of_type("vegetarian","diet.csv");
    cout<<"No. of menus for vegetarians for one day: "<<vegetarians<<endl;
    int flexitarians = cast.no_of_type("flexitarian","diet.csv");
    cout<<"No. of menus for flexitarians for one day: "<<flexitarians<<endl;
    cout<<"\n";
    cout<<"\t.............drinks................"<<endl;
    cout<<"\n";
    int water = drinks.water(cast_f);
    cout<<"Liters of water needed for one day: "<<water<<endl;
    int coffee = drinks.coffee(cast_f);
    cout<<"Liters of coffee needed for one day: "<<coffee<<endl;
    int juice = drinks.juice(cast_f);
    cout<<"Liters of juice needed for one day: "<<juice<<endl;
    cout<<"\n";


    cout<<"\t\t\t----------------------PRICES---------------------\n";
    float cost1 = cost.cost_bus_one_way(buses);
    cout<<"Price of one way ride with the buses: "<<cost1<<"$"<<endl;

    float cost2 = cost.cost_bus_both_ways(buses);
    cout<<"Price of both ways ride with the buses: "<<cost2<<"$"<<endl;

    float cost3 = cost.cost_of_makeup(vamp,werew,sirens,psy,hum);
    cout<<"Price of makeup for one day: "<<cost3<<"$"<<endl;

    float cost4 = cost.cost_of_rooms(rooms_cast,rooms_extras);
    cout<<"Price of rooms for one night: "<<cost4<<"$"<<endl;

    float cost5 = cost.cost_of_food(anything,vegetarians,flexitarians);
    cout<<"Price of food for one day in: "<<cost5<<"$"<<endl;

    float cost6 = cost.cost_of_drinks(water,coffee,juice);
    cout<<"Price of drinks for one day: "<<cost6<<"$"<<endl;

    float cost7 = cost.cost_of_castle();
    cout<<"Price of renting the cantacuzino castle for a day: "<<cost7<<"$"<<endl;


    int v[5] = {30,45,60,100};

    cout<<"\t\t\t----------------------TOTAL FOR X DAYS---------------------\n";
    cout<<"Price for transport is standard for x days!! ---> "<<cost2<<"$"<<endl;
    for(int i = 0 ; i <= 3 ; i++)
    {
        int x = v[i];
        cout<<"\n\t................."<<x<<" DAYS..............."<<endl;
        long long t_mu = cost.cost_total_fnct(x,cost3);
        cout<<"Price for makeup: "<<t_mu<<"$"<<endl;
        long long t_rooms = cost.cost_total_fnct(x,cost4);
        cout<<"Price for rooms: "<<t_rooms<<"$"<<endl;
        long long t_food = cost.cost_total_fnct(x,cost5);
        cout<<"Price for food: "<<t_food<<"$"<<endl;
        long long t_drinks = cost.cost_total_fnct(x,cost6);
        cout<<"Price for drinks: "<<t_drinks<<"$"<<endl;
        float disc = cost.discount(x,cost7);
        cout<<"Discount for castle: "<<disc<<"$"<<endl;
        long long t_castle = cost.cost_total_castle(disc,cost4);
        cout<<"Price for castle: "<<t_castle<<"$"<<endl;
        long long total = cost.cost_total_x(cost2,t_mu,t_rooms,t_food,t_drinks,t_castle);
        cout<<"TOTAL: "<<total<<"$"<<endl;
        cost.CSV_cost(x,cost2,t_rooms,t_mu,t_food,t_drinks,t_castle,disc);
    }

    cout<<"\t\t\t----------------------MENIU FOR 3 DAYS---------------------\n";
    Director* director= new Director();
    ClientCode(*director);
    delete director;
    return 0;


}
