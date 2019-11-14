#include<iostream>
#include<list>
#include<string>
#include<vector>

using namespace std;

////简单工厂模式
//	//class MyCar{
//	//public:
//	//	virtual string CarName() = 0;
//	//};
//
//	//class BMWCAR:public MyCar{
//	//public:
//	//	BMWCAR(){
//	//		cout << "creater BMW success" << endl;
//	//	}
//	//	string CarName(){
//	//		return "BMWCar";
//	//	}
//	//};
//
//	//class BanzCAR :public MyCar{
//	//public:
//	//	BanzCAR(){
//	//		cout << "creater Banz success" << endl;
//	//	}
//	//	string CarName(){
//	//	
//	//		return "BanzCar";
//	//	}
//	//};
//
//	//class BYDCAR:public MyCar{
//	//public:
//	//	BYDCAR(){
//	//		cout << "creater BYD success" << endl;
//	//	}
//	//	string CarName(){
//	//	
//	//		return "BYDCAR";
//	//	}
//	//};
//
//	//class Factory{
//	//public:
//	//	enum CAR{
//	//		BMWCar,
//	//		BanzCar,
//	//		BYDCar
//	//	};
//	//	static MyCar* CreatCar(CAR type){
//	//		MyCar* ptr = nullptr;
//	//		switch (type)
//	//		{
//	//		case CAR::BMWCar:
//	//			ptr = new BMWCAR();
//	//		
//	//			break;
//	//		case CAR::BanzCar:
//	//			ptr = new BanzCAR();
//	//		
//	//			break;
//	//		case CAR::BYDCar:
//	//			ptr = new BYDCAR();
//	//		
//	//			break;
//	//		default:
//	//			break;
//	//		}
//	//		return ptr;
//	//	}
//	//};
//
////
////class MyCar{
////public:
////	virtual string CarName() = 0;
////};
////
////class BMWCAR :public MyCar{
////public:
////	BMWCAR(){
////		cout << "creater BMW success" << endl;
////	}
////	string CarName(){
////		return "BMWCar";
////	}
////};
////
////class BanzCAR :public MyCar{
////public:
////	BanzCAR(){
////		cout << "creater Banz success" << endl;
////	}
////	string CarName(){
////		return "BanzCar";
////	}
////};
////
////class BYDCAR :public MyCar{
////public:
////	BYDCAR(){
////		cout << "creater BYD success" << endl;
////	}
////	string CarName(){
////		return "BYDCAR";
////	}
////};
////
//////定义抽象工厂类
////class CreateFactory{
////public:
////	virtual MyCar* creatercar() = 0;
////};
////
//////具体工厂的定义
////class Create_BMW_Factory: public CreateFactory{
////	MyCar* creatercar(){
////		return new BMWCAR();
////	}
////};
////
////class Create_Banz_Factory : public CreateFactory{
////	MyCar* creatercar(){
////		return new BanzCAR();
////	}
////};
////class Create_BYD_Factory : public CreateFactory{
////	MyCar* creatercar(){
////		return new BYDCAR();
////	}
////};
////
////
////
////int main(){
////
////	CreateFactory* ptr = new Create_Banz_Factory;
////	ptr->creatercar();
////	delete ptr;
////	ptr = new Create_BYD_Factory;
////	ptr->creatercar();
////	delete ptr;
////
////	ptr = new Create_BMW_Factory;
////	ptr->creatercar();
////	delete ptr;
////
////	system("pause");
////	return 0;
////}
//
//


//创建抽象产品类
class MyCar{
public:
	virtual string CarName() = 0;
};

class MyBike{
public:
	virtual string BikeName() = 0;
};

//创建汽车具体产品
class BMWCAR : public MyCar{
public:
	//宝马汽车
	string CarName(){
		return "BMWCAR";
	}
};

class BanzCAR : public MyCar{
public:
	//奔驰汽车
	string CarName(){
		return "BanzCAR";
	}
};

class BYDCAR : public MyCar{
public:
	//比亚迪汽车
	string CarName(){
		return "BYDCAR";
	}
};


//创建自行车集体产品
class BMWBike : public MyBike{
public:
	//宝马自行车
	string BikeName(){
		return "BMWBike";
	}
};

class BanzBike : public MyBike{
public:
	//奔驰自行车
	string BikeName(){
		return "BanzBike";
	}
};

class BYDBike : public MyBike{
public:
	//比亚迪自行车
	string BikeName(){
		return "BYDBike";
	}
};


class BMWFactory;
//创建抽象工厂
class Factory{
public:
	enum Factory_Type{
		BMWFACTORY,
		BanzFACTORY,
		BYDFACTORY
	};
	virtual MyCar* creatercar()=0 ;
	virtual MyBike* createrbike()=0 ;

	static Factory* createrfactory(Factory_Type type);
};

class BMWFactory :public Factory{
public:
	MyCar* creatercar(){
		MyCar* ptr = nullptr;
		ptr = new BMWCAR();
		return ptr;
	}

	MyBike* createrbike(){
		MyBike* ptr = nullptr;
		ptr = new BMWBike();
		return ptr;
	}
};
class BanzFactory :public Factory{
	MyCar* creatercar(){
		MyCar* ptr = nullptr;
		ptr = new BanzCAR();
		return ptr;
	}

	MyBike* createrbike(){
		MyBike* ptr = nullptr;
		ptr = new BanzBike();
		return ptr;
	}
};
class BYDFactory :public Factory{
	MyCar* creatercar(){
		MyCar* ptr = nullptr;
		ptr = new BYDCAR();
		return ptr;
	}

	MyBike* createrbike(){
		MyBike* ptr = nullptr;
		ptr = new BYDBike();
		return ptr;
	}
};

Factory* Factory::createrfactory(Factory_Type type){
	Factory* ptr = new BMWFactory();
	switch (type){
	case Factory_Type::BMWFACTORY:
		ptr = new BMWFactory();
		break;
	case Factory_Type::BanzFACTORY:
		ptr = new BanzFactory();
		break;
	case Factory_Type::BYDFACTORY:
		ptr = new BYDFactory();
		break;
	default:
		break;
	}
	return ptr;
}



int main(){
	Factory* ptr = Factory::createrfactory(Factory::Factory_Type::BMWFACTORY);
	cout << ptr->creatercar()->CarName() << endl;
	cout << ptr->createrbike()->BikeName() << endl;
	cout << endl;
	ptr = Factory::createrfactory(Factory::Factory_Type::BanzFACTORY);
	cout << ptr->creatercar()->CarName() << endl;
	cout << ptr->createrbike()->BikeName() << endl;
	cout << endl;
	ptr = Factory::createrfactory(Factory::Factory_Type::BYDFACTORY);
	cout << ptr->creatercar()->CarName() << endl;
	cout << ptr->createrbike()->BikeName() << endl;
	cout << endl;
	system("pause");
	return 0;
}
//#include<iostream>
//#include<vector>
//#include<sstream>
//using namespace std;
//
//int main(){
//	vector<int> addend_v;
//	vector<int> augend_v;
//	vector<int> count_v;
//	string addend;
//	string augend;
//	cin >> addend >> augend;
//	int len = addend.size() > augend.size() ? addend.size() + 1 : augend.size() + 1;
//	count_v.resize(len, 0);
//	for (int i = addend.size()-1 ; i>=0; i--){
//		int num = addend[i] - '0';
//		addend_v.push_back(num);
//	}
//	addend_v.resize(len, 0);
//	for (int i = augend.size()-1 ; i>=0; i--){
//		int num = augend[i] - '0';
//		augend_v.push_back(num);
//	}
//	augend_v.resize(len, 0);
//	for (int i = 0; i < count_v.size(); i++){
//		int num = (addend_v[i] + augend_v[i] + count_v[i]);
//		count_v[i] = num % 10;
//		if (i == len-1){
//			if (count_v[len - 1] == 1){
//				count_v.push_back(1);
//			}
//			break;
//		}
//		count_v[i + 1] = num / 10;
//	}
//	stringstream tmp;
//	for (int i = count_v.size()-2 ; i>=0; i--){
//		tmp << count_v[i];
//	}
//	string str=tmp.str();
//	cout << str << endl;
//	system("pause");
//	return 0;
//}

