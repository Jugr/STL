#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;


/*����
��5����Ա������Ҫָ�����ĸ����Ź���
��Ա��Ϣ������ ���� �绰���ʵ�
ͨ��multimap������Ϣ���뱣����ʾ
�ֲ�����ʾԱ����Ϣ ��ʾȫ��Ա����Ϣ
*/

#define SALE_DEPATMENT 1 //����
#define DEVELOP_DEPATMENT 2 //�з�
#define FINACIAL_DEPATMENT 3 //����


class Worker
{
public:
	string mName;
	string mTele;
	int mAge;
	int mSalary;
};

//����Ա��
void Create_Worker(vector<Worker>& vWorker) {
	string seedName = "ABCDE";
	for (int i = 0; i < 5; i++) {
		Worker worker;
		worker.mName = "Ա��";
		worker.mName += seedName[i];

		worker.mAge = rand() % 10 + 20;
		worker.mSalary = rand() % 10000 + 10000;
		worker.mTele = "010-888888";

		//����Ա����Ϣ
		vWorker.push_back(worker);
	}
}
//Ա������
void WorkerByGroup(vector<Worker>& vWorker, multimap<int, Worker>& workerGroup) {
	//�������
	for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++) {
		int departID = rand() % 3 + 1;
		switch (departID)
		{
		case SALE_DEPATMENT:
			workerGroup.insert(make_pair(SALE_DEPATMENT, *it));
			break;
		case DEVELOP_DEPATMENT:
			workerGroup.insert(make_pair(DEVELOP_DEPATMENT, *it));
			break;
		case FINACIAL_DEPATMENT:
			workerGroup.insert(make_pair(FINACIAL_DEPATMENT, *it));
			break;
		default:
			break;
		}

	}


}

void showWorkers(multimap<int, Worker>& workerGroup, int departID);

//��ӡÿһ����Ա����Ϣ
void PrintWorkerByGroup(multimap<int, Worker>& workerGroup) {
	//��ӡԱ����Ϣ
	cout << "���۲���" << endl;
	showWorkers(workerGroup, SALE_DEPATMENT);
	cout << "�з�����" << endl;
	showWorkers(workerGroup, DEVELOP_DEPATMENT);
	cout << "������" << endl;
	showWorkers(workerGroup, FINACIAL_DEPATMENT);
	
}

void showWorkers(multimap<int, Worker>& workerGroup,int departID) {
	
	//1.��Ҫ�ҵ�key��һ�γ��ֵ�λ�� Ȼ��Ӹ�λ��������
	//2.��Ҫ֪��key��ͬ��Ԫ�ظ���

	multimap<int, Worker>::iterator it = workerGroup.find(departID);
	int DepartCount = workerGroup.count(departID);

	int num = 0;
	for (multimap<int, Worker>::iterator pos = it; it != workerGroup.end() && num < DepartCount; pos++, num++) {
		cout << "������" << (*pos).second.mName << "���䣺" << (*pos).second.mAge << endl;
	}

}


int main2() {

	//���Ա����Ϣ
	vector<Worker> vWorker;
	//multimap���������Ϣ
	multimap<int, Worker> workerGroup;

	//����Ա��
	Create_Worker(vWorker);
	//Ա������
	WorkerByGroup(vWorker, workerGroup);
	//��ӡÿһ����Ա����Ϣ
	PrintWorkerByGroup(workerGroup);
	/*
	���۲���
	������Ա��D���䣺28
	�з�����
	������Ա��C���䣺29
	������Ա��E���䣺22
	������
	������Ա��A���䣺21
	������Ա��B���䣺24
	*/
	return 0;
}
