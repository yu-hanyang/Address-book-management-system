#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

//设计联系人的结构体
struct Person {
	//姓名
	string m_Name;
	//性别 1 男 2 女
	int m_Sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//住址
	string m_Addr; 
};

//设计通信录的结构体
struct Addressbooks {

	//通信录中保存的联系人数组
	Person personArray[MAX];
	//通信录中当前记录联系人个数
	int m_Size;
};

//1、添加联系人
void addPerson(Addressbooks* abs) {
	//判断通信录是否已满,如果满了就不再添加
	if (abs->m_Size == MAX) {
		cout << "通信录已满" << endl;
		return;
	}
	else {
		//添加具体联系人
		//Person* tmp_person = &abs->personArray[abs->m_Size];
		//姓名
		string name;
		cout << "请输入人名：" << endl;
		cin >> name;  
		abs->personArray[abs->m_Size].m_Name = name;
		//性别
		cout << "请输入性别：1，代表男；2，代表女" << endl;
		int gender;
		while (true) {
			cin >> gender;
			if (gender == 1 || gender == 2) {
				abs->personArray[abs->m_Size].m_Sex = gender;
				break;
			}
			else {
				cout << "输入有误请重新输入" << endl;
			}

		}
		//年龄
		int age;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//电话
		string PhoneNum;
		cout << "请输入电话：" << endl;
		cin >> PhoneNum;
		abs->personArray[abs->m_Size].m_Phone = PhoneNum;
		//地址
		string address;
		cout << "请输入地址：" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新通信录的人数
		abs->m_Size++; 
		cout << "添加成功" << endl;
		system("pause");//请按任意键继续
		system("cls");//清屏操作
	}
}

//2、显示联系人
void showPerson(Addressbooks* abs) {
	//判断通信录人数是否为零
	if (abs->m_Size == 0) {
		cout << "当前记录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << i + 1 << "、\t";
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			if (abs->personArray[i].m_Sex == 1) {
				cout << "性别：男" << "\t";
			}
			else {
				cout << "性别：女" << "\t";
			}
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "地址：" << abs->personArray[i].m_Addr << "\n";

		}
	}
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}

//检测联系人是否存在,存在返回下标，不存在返回-1
int isExisit(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;
		}
	}
	return -1;
}

//3、删除联系人
void deletePerosn(Addressbooks* abs) {
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;
	int index = isExisit(abs,name);
	if (index == -1) {
		cout << "该联系人不存在" << endl;
	}
	else {
		//找到此人，进行删除操作
		//使用将后面的人之间覆盖上去
		for (int i = index; i < abs->m_Size; i++) {
			//数据前移
			abs->personArray[i] = abs->personArray[i + 1];

		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	system("pause");//请按任意键继续
	system("cls");//清屏操作

}

//4、查找联系人
void findPerson(Addressbooks* abs) {
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	int index = isExisit(abs, name);
	if (index == -1) {
		cout << "该联系人不存在" << endl;
	}
	else {
		cout << index + 1 << "、\t";
		cout << "姓名：" << abs->personArray[index].m_Name << "\t";
		if (abs->personArray[index].m_Sex == 1) {
			cout << "性别：男" << "\t";
		}
		else {
			cout << "性别：女" << "\t";
		}
		cout << "年龄：" << abs->personArray[index].m_Age << "\t";
		cout << "电话：" << abs->personArray[index].m_Phone << "\t";
		cout << "地址：" << abs->personArray[index].m_Addr << "\n";
	}
	system("pause");//请按任意键继续
	system("cls");//清屏操作

}

//5、修改联系人
void updatePerson(Addressbooks* abs) {
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;
	int index = isExisit(abs, name);
	if (index == -1) {
		cout << "该联系人不存在" << endl;
	}
	else {
		string name;
		cout << "请输入人名：" << endl;
		cin >> name;
		abs->personArray[index].m_Name = name;
		//性别
		cout << "请输入性别：1，代表男；2，代表女" << endl;
		int gender;
		while (true) {
			cin >> gender;
			if (gender == 1 || gender == 2) {
				abs->personArray[index].m_Sex = gender;
				break;
			}
			else {
				cout << "输入有误请重新输入" << endl;
			}

		}
		//年龄
		int age;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[index].m_Age = age;
		//电话
		string PhoneNum;
		cout << "请输入电话：" << endl;
		cin >> PhoneNum;
		abs->personArray[index].m_Phone = PhoneNum;
		//地址
		string address;
		cout << "请输入地址：" << endl;
		cin >> address;
		abs->personArray[index].m_Addr = address;

		
		
		cout << "修改成功" << endl;
	}
	system("pause");//请按任意键继续
	system("cls");//清屏操作

}

//6、清空联系人
void cleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "通信录已清空" << endl;
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}


//菜单界面
void showMenu() {
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通信录  *****" << endl;
	cout << "***************************" << endl;
}

int main() {

	//创建通信录结构体变量
	Addressbooks abs;
	//初始化通信录中当前人员的个数
	abs.m_Size = 0;


	int select = 0;//创建用户输入的变量

	while(true) {

		//菜单的调用
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1://1、添加联系人
			addPerson(&abs);//利用地址传递可以修饰实参
			break;
		case 2://2、显示联系人
			showPerson(&abs);
			break;
		case 3://3、删除联系人
			deletePerosn(&abs);
			break;
		case 4://4、查找联系人
			findPerson(&abs);
			break;
		case 5://5、修改联系人
			updatePerson(&abs);
			break;
		case 6://6、清空联系人
			cleanPerson(&abs);
			break;
		case 0://0、退出通信录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}


	}

	

	system("pause");
	return 0;
}