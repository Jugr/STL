#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;


/*案例
有5名新员工，需要指派在哪个部门工作
人员信息：姓名 年龄 电话工资等
通过multimap进行信息插入保持显示
分部门显示员工信息 显示全部员工信息
*/

#define SALE_DEPATMENT 1 //销售
#define DEVELOP_DEPATMENT 2 //研发
#define FINACIAL_DEPATMENT 3 //财务


class Worker
{
public:
	string mName;
	string mTele;
	int mAge;
	int mSalary;
};

//创建员工
void Create_Worker(vector<Worker>& vWorker) {
	string seedName = "ABCDE";
	for (int i = 0; i < 5; i++) {
		Worker worker;
		worker.mName = "员工";
		worker.mName += seedName[i];

		worker.mAge = rand() % 10 + 20;
		worker.mSalary = rand() % 10000 + 10000;
		worker.mTele = "010-888888";

		//保存员工信息
		vWorker.push_back(worker);
	}
}
//员工分组
void WorkerByGroup(vector<Worker>& vWorker, multimap<int, Worker>& workerGroup) {
	//随机分配
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

//打印每一部门员工信息
void PrintWorkerByGroup(multimap<int, Worker>& workerGroup) {
	//打印员工信息
	cout << "销售部门" << endl;
	showWorkers(workerGroup, SALE_DEPATMENT);
	cout << "研发部门" << endl;
	showWorkers(workerGroup, DEVELOP_DEPATMENT);
	cout << "财务部门" << endl;
	showWorkers(workerGroup, FINACIAL_DEPATMENT);
	
}

void showWorkers(multimap<int, Worker>& workerGroup,int departID) {
	
	//1.需要找到key第一次出现的位置 然后从该位置往后找
	//2.需要知道key相同的元素个数

	multimap<int, Worker>::iterator it = workerGroup.find(departID);
	int DepartCount = workerGroup.count(departID);

	int num = 0;
	for (multimap<int, Worker>::iterator pos = it; it != workerGroup.end() && num < DepartCount; pos++, num++) {
		cout << "姓名：" << (*pos).second.mName << "年龄：" << (*pos).second.mAge << endl;
	}

}


int main2() {

	//存放员工信息
	vector<Worker> vWorker;
	//multimap保存分组信息
	multimap<int, Worker> workerGroup;

	//创建员工
	Create_Worker(vWorker);
	//员工分组
	WorkerByGroup(vWorker, workerGroup);
	//打印每一部门员工信息
	PrintWorkerByGroup(workerGroup);
	/*
	销售部门
	姓名：员工D年龄：28
	研发部门
	姓名：员工C年龄：29
	姓名：员工E年龄：22
	财务部门
	姓名：员工A年龄：21
	姓名：员工B年龄：24
	*/
	return 0;
}
