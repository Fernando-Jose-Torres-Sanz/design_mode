#include<iostream>
using namespace std;
//����ģʽ
//һ����ֻ�ܴ���һ�����󣬼�����ģʽ����ģʽ���Ա�֤ϵͳ�и���ֻ��һ��ʵ�������ṩһ����������ȫ �ַ��ʵ㣬��ʵ�������г���ģ�鹲��
//����ģʽ
//1.�����캯��˽��
//2.����һ�������ľ�̬��Ա,��̬��Ա�ڳ�������֮ǰ���Ѿ���ʼ��
//3.����һ����̬������ȡ������̬��Ա
//4.��ֹ����
class singleton
{
public:
	//���뷵�����û���ָ��,��Ϊֱ�ӷ��صĻ��ᷢ��һ�ο�������,�Ͳ��ǵ���ģʽ��
	static singleton* getinstance(){
		return &_sin;
	}
private:
	//�������캯���Ϳ������캯��
	singleton(){}
	singleton(const singleton& s);
	//��̬��Ա���������ݶ�,��Ӱ����Ĵ�С
	//��̬�����������������ʼ��
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
////�߳̿��ļ�
////#include<thread>//<pthread>
////#include<mutex>
////����ģʽ
////��򵥵�   
////1.���캯��˽��
////2.�����������캯��
////3.�ṩ��̬��ȫ�Ľӿ�(������if����ж�ָ���Ƿ񴴽��ɹ������Ч��)
////4.����һ����̬���͵�ָ��,��ʼ��Ϊnullptr
////5.(��ѡ)����һ��,�ڲ���,�����ͷŵ���ָ��
////class singleton{
////public:
////	static singleton* getinstance(){
////		�����߳�ִ�е������ʱ��,�޷���֤������.....�п��ܻ�����ڴ�й©
////		if (_sin == nullptr){
////			��һ��if��Ϊ�����Ч��,��һ���̲߳ż���,������̶߳��ǲ��е�,ֱ�ӿ��Դӵ�һ��if������ȥ.
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
////�ڴ�й©(��ʧ���ڴ���ָ��һƬ�ռ��ָ��)
////int main(){
////	int *p = new int[0x3fffffff] ;
////	system("pause");
////	return 0;
////}