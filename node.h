#ifndef NODE_H
#define NODE_H
#include "stuinfo.h"
#include <QString>
#include <QMessageBox>

class Node
{
public:
    Node();
    void InputStudent();//输入学生信息
    void DeleteStudent(long long number);//删除学生信息
    void OutputStudent();//输出学生信息
    void ChangeStudent(QString name,long long number,QString age,QString gender,long long tel,QString bir,QString address,double score);//修改学生信息
    bool SearchStudent(QString &name,long long number,QString &age,QString &gender,long long &tel,QString &bir,QString &address,double &score);//查找学生信息

private:
        stuinfo st;//数据域
        Node *pNext;//指针域
        Node *pHead;//头结点
};
typedef Node NODE;
typedef Node* PNODE;
/*
NODE 相当于  Node
PNODE 相当于 Node*
*/
#endif // NODE_H
