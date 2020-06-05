#include "node.h"

#include <QDialog>
#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QtDebug>
Node::Node() {

}

void Node::InputStudent() {
	QFile file("stuinfo.txt");
	file.open(QIODevice::ReadOnly|QIODevice::Text);
	if(!file.isOpen()) { //如果数据文件没有打开，弹出对话框提示用户
		QMessageBox::about(NULL, "反馈", "数据文件打开失败");
		return;
	}
	QTextStream inp(&file);
	pHead = new NODE[sizeof(NODE)];
	if (NULL == pHead) {
		QMessageBox::about(NULL,"反馈","动态内存分配失败，无法修改删除！");
		return;
	}
	PNODE pTail = pHead;//创建一个指向头结点的指针
	pTail->pNext = NULL;//初始化指针的指针域为NULL
	QString name;//姓名
	long long number;//学号
	QString age;//年龄
	QString gender;//性别
	QString address;//地址
	long long tel; //电话号码 1XXXXXXXXXX
	QString bir;//生日
	double score;//学生成绩（0-100）
	while(!inp.atEnd()) {
		PNODE pNew = new NODE[sizeof(NODE)];
		if (NULL == pNew) {
			QMessageBox::about(NULL,"反馈","动态内存分配失败，无法修改删除！");
			return;
		}
		inp>>name>>number>>age>>gender>>tel>>bir>>address>>score;
		pNew->st.setname(name);//学生的姓名
		pNew->st.setnumber(number);//学生的学号
		pNew->st.setage(age);//学生的年龄
		pNew->st.setgender(gender);//设置学生的性别
		pNew->st.settel(tel); //设置学生的电话
		pNew->st.setbir(bir);//设置学生的生日
		pNew->st.setaddress(address);//设置学生的地址
		pNew->st.setscore(score);//设置学生的成绩

		pTail->pNext = pNew;//将pNew挂在老结点的后面
		pTail = pNew;//将指针pTail移到pNew上
		pTail->pNext = NULL;
	}
	file.close();
}

void Node::DeleteStudent(long long number) {
	PNODE p, be, bp;
	p = pHead->pNext;
	if (number == p->st.getnumber()) {
		pHead->pNext = pHead->pNext->pNext;
        delete[]pHead->pNext->pNext;//删除
		QMessageBox::about(NULL,"反馈","已成功删除该学生信息!");
	} else {
		be = bp = p;
		while (number != bp->st.getnumber() && bp->pNext != NULL) {
			be = bp;
			bp = bp->pNext;
		}
		if (number == bp->st.getnumber()) {
			be->pNext = bp->pNext;
			delete[]bp;
			QMessageBox::about(NULL,"反馈","已成功删除该学生信息!");
		} else
			QMessageBox::about(NULL,"反馈","查无此人!");
	}
}

void Node::OutputStudent() {
	QFile file("stuinfo.txt");
	file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
	if(!file.isOpen()) { //如果数据文件没有打开，弹出对话框提示用户
		QMessageBox::about(NULL, "反馈", "数据文件打开失败");
		return;
	}
	QTextStream out(&file);
	PNODE p = pHead->pNext;
    for(; p; p=p->pNext) {//输出
		if(p->st.getname()=="") break;
		out<<p->st.getname()<<" "<<p->st.getnumber()<<" "<<p->st.getage()<<" "<<p->st.getgender()<<" "<<p->st.gettel()<<" "<<p->st.getbir()<<" "<<p->st.getaddress()<<" "<<p->st.getscore()<<"\n";
	}
	file.close();
}

void Node::ChangeStudent(QString name,long long number,QString age,QString gender,long long tel,QString bir,QString address,double score) {
	PNODE p = pHead->pNext;
	bool flag = false;
	for(; p; p = p->pNext) {
		if(number==p->st.getnumber()) {
			flag = true;
			break;
		}
	}
	if(flag == false) {
		QMessageBox::about(NULL,"反馈","查无此人!");
		return;
	}
	p->st.setname(name);//学生的姓名
	p->st.setnumber(number);//学生的学号
	p->st.setage(age);//学生的年龄
	p->st.setgender(gender);//设置学生的性别
	p->st.settel(tel); //设置学生的电话
	p->st.setbir(bir);//设置学生的生日
	p->st.setaddress(address);//设置学生的地址
	p->st.setscore(score);//设置学生的成绩
	QMessageBox::about(NULL,"反馈","已成功修改该学生信息!");

}
bool Node::SearchStudent(QString &name,long long number,QString &age,QString &gender,long long &tel,QString &bir,QString &address,double &score) {
	PNODE p = pHead->pNext;
	bool flag = false;
    for(; p; p = p->pNext) {//循环查找
		if(number==p->st.getnumber()) {
			flag = true;
			name = p->st.getname();
			age = p->st.getage();
			gender = p->st.getgender();
			address = p->st.getaddress();
			tel = p->st.gettel();
			bir = p->st.getbir();
			score = p->st.getscore();
			break;
		}
	}
	if(flag == false) {
        return false;//没有找到
	}
    return true;//找到
}
