#include<iostream>
using namespace std;
//单例模式
//一个类只能创建一个对象，即单例模式，该模式可以保证系统中该类只有一个实例，并提供一个访问它的全 局访问点，该实例被所有程序模块共享
//饿汉模式
//1.将构造函数私有
//2.定义一个单例的静态成员,静态成员在程序运行之前就已经初始化
//3.定义一个静态方法获取单例静态成员
//4.防止拷贝
class singleton
{
public:
	//必须返回引用或者指针,因为直接返回的话会发生一次拷贝构造,就不是单例模式了
	static singleton* getinstance(){
		return &_sin;
	}
private:
	//封死构造函数和拷贝构造函数
	singleton(){}
	singleton(const singleton& s);
	//静态成员存在于数据段,不影响类的大小
	//静态变量必须在类外面初始化
	static singleton _sin;
};
singleton singleton::_sin;
//singleton _sin;
int main(){
	singleton*s = singleton::getinstance();
	cout << s << endl;
	system("pause");
	return 0;
}

////
////线程库文件
////#include<thread>//<pthread>
////#include<mutex>
////懒汉模式
////最简单的   
////1.构造函数私有
////2.封死拷贝构造函数
////3.提供静态安全的接口(用两个if语句判断指针是否创建成功来提高效率)
////4.定义一个静态类型的指针,初始化为nullptr
////5.(可选)定义一个,内部类,辅助释放单例指针
////class singleton{
////public:
////	static singleton* getinstance(){
////		当多线程执行到这里的时候,无法保证但单例.....有可能会造成内存泄漏
////		if (_sin == nullptr){
////			第一个if是为了提高效率,第一批线程才加锁,往后的线程都是并行的,直接可以从的一个if中跳过去.
////			_mtx.lock();
////			if (_sin == nullptr){
////				_sin = new singleton;
////			}
////			_mtx.unlock();
////		}
////			return _sin;
////	}
////	/*class GC{
////		public:
////			~GC(){
////				if (_sin){
////					delete _sin;
////					_sin = nullptr;
////				}
////			}
////	};*/
////private:
////	singleton(){}
////	singleton(const singleton& s) = delete;
////	static singleton* _sin;
////	static mutex _mtx;
////	static GC _gc;
////};
////singleton* singleton::_sin = nullptr;
////mutex singleton::_mtx;
////singleton::GC singleton::_gc;
////void fun(){
////	for (int i = 0; i < 20; i++){
////		cout << i << endl;
////	}
////}
////
////void test(){
////	cout << singleton::getinstance()<<endl;
////}
////int main(){
////	thread t1(test);
////	thread t2(test);
////	thread t3(test);
////
////
////	t1.join();
////	t2.join();
////	t3.join();
////	system("pause");
////	return 0;
////}
////
////
////内存泄漏(丢失了内存中指向一片空间的指针)
////int main(){
////	int *p = new int[0x3fffffff] ;
////	system("pause");
////	return 0;
////}