
// *****抽象工厂模式*****
// 抽象工厂模式包含多个抽象产品接口，多个具体产品类，一个抽象工厂接口和多个具体工厂，
// 每个具体工厂负责创建一组相关的产品.
// 工厂方法模式使得每个工厂类的职责单一，每个工厂只负责创建一种产品，当创建对象涉及一系列复杂的初始化逻辑，
// 而这些逻辑在不同的子类中可能有所不同时，可以使用工厂方法模式将这些初始化逻辑封装在子类的工厂中.

#include <iostream>
#include <string>

// 抽象椅子接口
class Chair {
public:
	virtual void showInfo() = 0;
};

// 具体现代风格椅子
class ModernChair : public Chair {
public:
	void showInfo() override {
		std::cout << "modern chair" << std::endl;
	}
};

// 具体古典风格椅子
class ClassicalChair : public Chair {
public:
	void showInfo() override {
		std::cout << "classical chair" << std::endl;
	}
};

// 抽象沙发接口
class Sofa {
public:
	virtual void displayInfo() = 0;
};

// 具体现代风格沙发
class ModernSofa : public Sofa {
public:
	void displayInfo() override {
		std::cout << "modern sofa" << std::endl;
	}
};

// 具体古典风格沙发
class ClassicalSofa : public Sofa {
public:
	void displayInfo() override {
		std::cout << "classical sofa" << std::endl;
	}
};

// 抽象家居工厂接口
class FurnitureFactory {
public:
	virtual Chair* createChair() = 0;
	virtual Sofa* createSofa() = 0;
};

// 具体现代风格家居工厂
class ModernFurnitureFactory : public FurnitureFactory {
public:
	Chair* createChair() override {
		return new ModernChair();
	}

	Sofa* createSofa() override {
		return new ModernSofa();
	}
};

// 具体古典风格家居工厂
class ClassicalFurnitureFactory : public FurnitureFactory {
public:
	Chair* createChair() override {
		return new ClassicalChair();
	}

	Sofa* createSofa() override {
		return new ClassicalSofa();
	}
};

int main() {
	// 读取订单数量
	int N;
	std::cin >> N;

	// 处理每个订单
	for (int i = 0; i < N; i++) {
		// 读取家具类型
		std::string furnitureType;
		std::cin >> furnitureType;

		// 创建相应风格的家居装饰品工厂
		FurnitureFactory* factory = nullptr;
		if (furnitureType == "modern") {
			factory = new ModernFurnitureFactory();
		}
		else if (furnitureType == "classical") {
			factory = new ClassicalFurnitureFactory();
		}

		// 根据工厂生产椅子和沙发
		Chair* chair = factory->createChair();
		Sofa* sofa = factory->createSofa();

		// 输出家具信息
		chair->showInfo();
		sofa->displayInfo();

		// 释放动态分配的对象
		delete chair;
		delete sofa;
		delete factory;
	}

	return 0;
}