#ifndef STUINFO_H
#define STUINFO_H
#include <QString>

class stuinfo {

	private:
		QString stu_name;//姓名
		long long stu_number;//学号
		QString stu_age;//年龄
		QString stu_gender;//性别
		QString stu_address;//地址
		long long stu_tel; //电话号码 1XXXXXXXXXX
		QString stu_bir;//生日
		double stu_score;//学生成绩（0-100）
	public:
		stuinfo();
		//inp>>name>>number>>age>>gender>>tel>>bir>>address>>score;
		stuinfo(QString name,long long number,QString age,QString gender,long long tel,QString bir,QString address,double score);
		//获取
		QString getname() ;
		long long getnumber() ;
		QString getage() ;
		QString getgender();
		QString getaddress();
		long long gettel() ;
		QString getbir();
		double getscore() ;
		//设置
		void setname(QString name);
		void setnumber(long long number);
		void setage(QString age);
		void setgender(QString gender);
		void setaddress(QString address);
		void settel(long long tel);
		void setbir(QString bir) ;
		void setscore(double score) ;

};

#endif // STUINFO_H
