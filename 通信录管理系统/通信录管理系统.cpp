#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

//�����ϵ�˵Ľṹ��
struct Person {
	//����
	string m_Name;
	//�Ա� 1 �� 2 Ů
	int m_Sex;
	//����
	int m_Age;
	//�绰
	string m_Phone;
	//סַ
	string m_Addr; 
};

//���ͨ��¼�Ľṹ��
struct Addressbooks {

	//ͨ��¼�б������ϵ������
	Person personArray[MAX];
	//ͨ��¼�е�ǰ��¼��ϵ�˸���
	int m_Size;
};

//1�������ϵ��
void addPerson(Addressbooks* abs) {
	//�ж�ͨ��¼�Ƿ�����,������˾Ͳ������
	if (abs->m_Size == MAX) {
		cout << "ͨ��¼����" << endl;
		return;
	}
	else {
		//��Ӿ�����ϵ��
		//Person* tmp_person = &abs->personArray[abs->m_Size];
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;  
		abs->personArray[abs->m_Size].m_Name = name;
		//�Ա�
		cout << "�������Ա�1�������У�2������Ů" << endl;
		int gender;
		while (true) {
			cin >> gender;
			if (gender == 1 || gender == 2) {
				abs->personArray[abs->m_Size].m_Sex = gender;
				break;
			}
			else {
				cout << "������������������" << endl;
			}

		}
		//����
		int age;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//�绰
		string PhoneNum;
		cout << "������绰��" << endl;
		cin >> PhoneNum;
		abs->personArray[abs->m_Size].m_Phone = PhoneNum;
		//��ַ
		string address;
		cout << "�������ַ��" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//����ͨ��¼������
		abs->m_Size++; 
		cout << "��ӳɹ�" << endl;
		system("pause");//�밴���������
		system("cls");//��������
	}
}

//2����ʾ��ϵ��
void showPerson(Addressbooks* abs) {
	//�ж�ͨ��¼�����Ƿ�Ϊ��
	if (abs->m_Size == 0) {
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << i + 1 << "��\t";
			cout << "������" << abs->personArray[i].m_Name << "\t";
			if (abs->personArray[i].m_Sex == 1) {
				cout << "�Ա���" << "\t";
			}
			else {
				cout << "�Ա�Ů" << "\t";
			}
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "��ַ��" << abs->personArray[i].m_Addr << "\n";

		}
	}
	system("pause");//�밴���������
	system("cls");//��������
}

//�����ϵ���Ƿ����,���ڷ����±꣬�����ڷ���-1
int isExisit(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;
		}
	}
	return -1;
}

//3��ɾ����ϵ��
void deletePerosn(Addressbooks* abs) {
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int index = isExisit(abs,name);
	if (index == -1) {
		cout << "����ϵ�˲�����" << endl;
	}
	else {
		//�ҵ����ˣ�����ɾ������
		//ʹ�ý��������֮�串����ȥ
		for (int i = index; i < abs->m_Size; i++) {
			//����ǰ��
			abs->personArray[i] = abs->personArray[i + 1];

		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");//�밴���������
	system("cls");//��������

}

//4��������ϵ��
void findPerson(Addressbooks* abs) {
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int index = isExisit(abs, name);
	if (index == -1) {
		cout << "����ϵ�˲�����" << endl;
	}
	else {
		cout << index + 1 << "��\t";
		cout << "������" << abs->personArray[index].m_Name << "\t";
		if (abs->personArray[index].m_Sex == 1) {
			cout << "�Ա���" << "\t";
		}
		else {
			cout << "�Ա�Ů" << "\t";
		}
		cout << "���䣺" << abs->personArray[index].m_Age << "\t";
		cout << "�绰��" << abs->personArray[index].m_Phone << "\t";
		cout << "��ַ��" << abs->personArray[index].m_Addr << "\n";
	}
	system("pause");//�밴���������
	system("cls");//��������

}

//5���޸���ϵ��
void updatePerson(Addressbooks* abs) {
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int index = isExisit(abs, name);
	if (index == -1) {
		cout << "����ϵ�˲�����" << endl;
	}
	else {
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[index].m_Name = name;
		//�Ա�
		cout << "�������Ա�1�������У�2������Ů" << endl;
		int gender;
		while (true) {
			cin >> gender;
			if (gender == 1 || gender == 2) {
				abs->personArray[index].m_Sex = gender;
				break;
			}
			else {
				cout << "������������������" << endl;
			}

		}
		//����
		int age;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[index].m_Age = age;
		//�绰
		string PhoneNum;
		cout << "������绰��" << endl;
		cin >> PhoneNum;
		abs->personArray[index].m_Phone = PhoneNum;
		//��ַ
		string address;
		cout << "�������ַ��" << endl;
		cin >> address;
		abs->personArray[index].m_Addr = address;

		
		
		cout << "�޸ĳɹ�" << endl;
	}
	system("pause");//�밴���������
	system("cls");//��������

}

//6�������ϵ��
void cleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "ͨ��¼�����" << endl;
	system("pause");//�밴���������
	system("cls");//��������
}


//�˵�����
void showMenu() {
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨ��¼  *****" << endl;
	cout << "***************************" << endl;
}

int main() {

	//����ͨ��¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨ��¼�е�ǰ��Ա�ĸ���
	abs.m_Size = 0;


	int select = 0;//�����û�����ı���

	while(true) {

		//�˵��ĵ���
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1://1�������ϵ��
			addPerson(&abs);//���õ�ַ���ݿ�������ʵ��
			break;
		case 2://2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://3��ɾ����ϵ��
			deletePerosn(&abs);
			break;
		case 4://4��������ϵ��
			findPerson(&abs);
			break;
		case 5://5���޸���ϵ��
			updatePerson(&abs);
			break;
		case 6://6�������ϵ��
			cleanPerson(&abs);
			break;
		case 0://0���˳�ͨ��¼
			cout << "��ӭ�´�ʹ��" << endl;
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