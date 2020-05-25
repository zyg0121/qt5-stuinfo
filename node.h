#ifndef NODE_H
#define NODE_H
#include "stuinfo.h"
#include <QString>
#include <QMessageBox>

class Node
{
public:
    Node();
    void InputStudent();
    void DeleteStudent(long long number);
    void OutputStudent();
    void ChangeStudent(QString name,long long number,QString age,QString gender,long long tel,QString bir,QString address,double score);
    bool SearchStudent(QString &name,long long number,QString &age,QString &gender,long long &tel,QString &bir,QString &address,double &score);

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
