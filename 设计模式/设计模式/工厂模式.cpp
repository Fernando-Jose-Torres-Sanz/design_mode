#include<iostream>
#include<list>
#include<vector>
using namespace std;

//简单工厂模式
	//class MyCar{
	//public:
	//	virtual string CarName() = 0;
	//};

	//class BMWCAR:public MyCar{
	//public:
	//	BMWCAR(){
	//		cout << "creater BMW success" << endl;
	//	}
	//	string CarName(){
	//		return "BMWCar";
	//	}
	//};

	//class BanzCAR :public MyCar{
	//public:
	//	BanzCAR(){
	//		cout << "creater Banz success" << endl;
	//	}
	//	string CarName(){
	//	
	//		return "BanzCar";
	//	}
	//};

	//class BYDCAR:public MyCar{
	//public:
	//	BYDCAR(){
	//		cout << "creater BYD success" << endl;
	//	}
	//	string CarName(){
	//	
	//		return "BYDCAR";
	//	}
	//};

	//class Factory{
	//public:
	//	enum CAR{
	//		BMWCar,
	//		BanzCar,
	//		BYDCar
	//	};
	//	static MyCar* CreatCar(CAR type){
	//		MyCar* ptr = nullptr;
	//		switch (type)
	//		{
	//		case CAR::BMWCar:
	//			ptr = new BMWCAR();
	//		
	//			break;
	//		case CAR::BanzCar:
	//			ptr = new BanzCAR();
	//		
	//			break;
	//		case CAR::BYDCar:
	//			ptr = new BYDCAR();
	//		
	//			break;
	//		default:
	//			break;
	//		}
	//		return ptr;
	//	}
	//};


class MyCar{
public:
	virtual string CarName() = 0;
};

class BMWCAR :public MyCar{
public:
	BMWCAR(){
		cout << "creater BMW success" << endl;
	}
	string CarName(){
		return "BMWCar";
	}
};

class BanzCAR :public MyCar{
public:
	BanzCAR(){
		cout << "creater Banz success" << endl;
	}
	string CarName(){
		return "BanzCar";
	}
};

class BYDCAR :public MyCar{
public:
	BYDCAR(){
		cout << "creater BYD success" << endl;
	}
	string CarName(){
		return "BYDCAR";
	}
};

//定义抽象工厂类
class CreateFactory{
public:
	virtual MyCar* creatercar() = 0;
};

//具体工厂的定义
class Create_BMW_Factory: public CreateFactory{
	MyCar* creatercar(){
		return new BMWCAR();
	}
};

class Create_Banz_Factory : public CreateFactory{
	MyCar* creatercar(){
		return new BanzCAR();
	}
};
class Create_BYD_Factory : public CreateFactory{
	MyCar* creatercar(){
		return new BYDCAR();
	}
};



int main(){

	CreateFactory* ptr = new Create_Banz_Factory;
	ptr->creatercar();
	delete ptr;
	ptr = new Create_BYD_Factory;
	ptr->creatercar();
	delete ptr;

	ptr = new Create_BMW_Factory;
	ptr->creatercar();
	delete ptr;

	system("pause");
	return 0;
}

