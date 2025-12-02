
// *****单例模式*****
// 是一种创建型设计模式,它的核心思想是保证一个类只有一个实例，并提供一个全局访问点来访问这个实例
// 优点：
//     1.全局控制：严格的控制客户怎样访问它以及何时访问它
//     2.节省资源：避免多次创建了相同的对象，多个模块可以通过单例实例共享数据
//     3.懒加载：单例模式可以实现懒加载，只有在需要时才进行实例化，这无疑会提高程序的性能
// 实现一个单例设计模式遵循的规则：
//     1.私有的构造函数：防止外部代码直接创建类的实例
//     2.私有的静态实例变量：保存该类的唯一实例
//     3.公有的静态方法：通过公有的静态方法来获取类的实例
// 单例模式 实现方式：饿汉式、懒汉式。
// 饿汉式在程序启动阶段就完成了实例的初始化，因此不存在多个线程同时尝试初始化实例的问题.
// 懒汉式中多个线程同时访问 getInstance() 方法，并且在同一时刻检测到实例没有被创建，就可能会同时创建实例，
// 从而导致多个实例被创建，可以采用一些同步机制，例如使用互斥锁来确保在任何时刻只有一个线程能够执行实例的创建



#include <iostream>
#include <map>
#include <string>

using namespace std;

class ShoppingCartManager {
public:
	// 获取购物车实例--公有静态方法获取实例
	static ShoppingCartManager& getInstance() {
		static ShoppingCartManager instance;
		return instance;
	}

	// 添加商品到购物车
	void addToCart(const string& itemName, int quantity) {
		cart[itemName] += quantity;
	}

	// 查看购物车
	void viewCart() const {
		for (const auto& item : cart) {
			cout << item.first << " " << item.second << endl;
		}
	}

private:
	// 私有构造函数
	ShoppingCartManager() {}

	// 购物车存储商品和数量的映射--私有静态实例变量
	map<string, int> cart;
};

int main() {
	string itemName;
	int quantity;

	while (cin >> itemName >> quantity) {
		// 获取购物车实例并添加商品
		ShoppingCartManager& cart = ShoppingCartManager::getInstance();
		cart.addToCart(itemName, quantity);
	}

	// 输出购物车内容
	const ShoppingCartManager& cart = ShoppingCartManager::getInstance();
	cart.viewCart();

	return 0;
}