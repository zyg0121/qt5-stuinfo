#include "stuinfo.h"

#include <QString>
stuinfo::stuinfo() {

}
stuinfo::stuinfo(QString name,long long number,QString age,QString gender,long long tel,QString bir,QString address,double score) {
	stu_name = name;
	stu_number = number;
	stu_age = age;
	stu_gender = gender;
	stu_address = address;
	stu_tel = tel;
	stu_bir = bir;
	stu_score = score;
}
QString stuinfo::getname() {
	return stu_name;
}
long long stuinfo::getnumber() {
	return stu_number;
}
QString stuinfo::getage() {
	return stu_age;
}
QString stuinfo::getgender() {
	return stu_gender;
}
QString stuinfo:: getaddress() {
	return stu_address;
}
long long stuinfo::gettel() {
	return stu_tel;
}
QString stuinfo::getbir() {
	return stu_bir;
}
double stuinfo::getscore() {
	return stu_score;
}
void stuinfo::setname(QString name) {
	stu_name = name;
}
void stuinfo::setnumber(long long number) {
	stu_number = number;
}
void stuinfo::setage(QString age) {
	stu_age = age;
}
void stuinfo::setgender(QString gender) {
	stu_gender = gender;
}
void stuinfo::setaddress(QString address) {
	stu_address = address;
}
void stuinfo::settel(long long tel) {
	stu_tel = tel;
}
void stuinfo::setbir(QString bir) {
	stu_bir = bir;
}
void stuinfo::setscore(double score) {
	stu_score = score;
}
