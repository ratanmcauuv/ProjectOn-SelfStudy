#include <iostream>
#include <typeinfo>
#include <string>
#include <algorithm>
using namespace std;

class AbsCar
{
 public:
    virtual ~AbsCar() = 0;
    virtual void getCarInfo() = 0;
};

AbsCar :: ~AbsCar() { 
    std::cout << "~AbsCar()\n"; 
}

class TataCar : public AbsCar
{
 public:
    void getCarInfo() {
        std::cout << "This is Tata Car\n";
    }
    ~TataCar() {
        std::cout << "~TataCar()\n";
    }
};

class MahindraCar : public AbsCar
{
 public:
    void getCarInfo() {
        std::cout << "This is Mahindra Car\n";
    }
    ~MahindraCar() {
        std::cout << "~MahindraCar()\n";
    }
};

class AbsVehicleFactory
{
 public:
    virtual ~AbsVehicleFactory() = 0;
    virtual void getFactoryName() = 0;
    virtual void createCar() = 0;
};

AbsVehicleFactory::~AbsVehicleFactory() {
    std::cout << "Inside ~AbsVehicleFactory()";
}

class Mahindra : public AbsVehicleFactory
{
 public:
    Mahindra() { std::cout << "Mahindra()\n"; }
    ~Mahindra() { std::cout << "~Mahindra()\n"; }
    void getFactoryName() {
        std::cout << "Factory name :: Mahindra\n";  
    }
    void createCar() {
        std::cout << "Creating Mahindra car()\n";
        AbsCar *icar = new MahindraCar();
        icar->getCarInfo();
        delete icar;
    }
};

class TataMotors : public AbsVehicleFactory
{
 public:
    TataMotors() { std::cout << "TataMotors()\n"; }
    ~TataMotors() { std::cout << "~TataMotors()\n"; }
    void getFactoryName() {
        std::cout << "Factory name :: TataMotors\n";  
    }
    void createCar() {
        std::cout << "Creating Tata car()\n";
        AbsCar *icar = new TataCar();
        icar->getCarInfo();
        delete icar;
    }
};

class AutoMobileFactory
{
 public:
    static AbsVehicleFactory *GetVehicleFactory(std::string &vType);
};

AbsVehicleFactory *AutoMobileFactory::GetVehicleFactory(std::string &autoMobCompany)
{
    AbsVehicleFactory *amf;
    std::transform(autoMobCompany.begin(), autoMobCompany.end(), autoMobCompany.begin(), ::tolower);

    if(autoMobCompany == "tata") {
        amf = new TataMotors();
    } else if(autoMobCompany == "mahindra") {
        amf = new Mahindra();
    }
    return amf;
}

//Client
int main()
{
    string vCompany;
    std::cout << "Enter vehicle Company to be created : \n";
    std::cin >> vCompany;

    AbsVehicleFactory *absFactory = AutoMobileFactory :: GetVehicleFactory(vCompany);
    if(absFactory) {
        std::cout << "Type of absFactory ::: " << typeid(absFactory).name() << std::endl;
        absFactory->getFactoryName();
        absFactory->createCar();
    }    
    
    return 0;
}