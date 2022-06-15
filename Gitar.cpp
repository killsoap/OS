#include <iostream>
#include <mysql/mysql.h>
#include <cstring>
#include <string>
#include <fstream>
#include <ctime>
#define LOG(msg) { Log << "[" << time(0) << "]" << msg; Log.flush(); }

std::ofstream Log;


class DB {
public:
	/// <summary>
	/// Initialize and start sql connection
	/// </summary>
	/// <returns>False - error</returns>
	static bool start();
	/// <summary>
	/// Send sql request
	/// </summary>
	/// <param name="req">String with sql reqest</param>
	/// <returns>NULL on error</returns>
	static MYSQL_RES* sendReq(std::string req);
	/// <summary>
	/// Returns information about a database error
	/// </summary>
	static auto mysqlError();
	static void stop();
private:
	static MYSQL* connection;
	static std::string host;
	static unsigned int port;
	static std::string user;
	static std::string password;
	static std::string dbname;
};


MYSQL* DB::connection;
std::string DB::host = "localhost";
unsigned int DB::port = 3306;
std::string DB::user = "admin";
std::string DB::password = "qwerty";
std::string DB::dbname = "Gitar_base";

bool DB::start() {
	connection = mysql_init(nullptr);
	if (mysql_real_connect(connection, host.c_str(), user.c_str(), password.c_str(), dbname.c_str(), port, nullptr, 0) == nullptr)
	{
		LOG(mysql_error(connection) << "Connection to database is failed\n");
		return false;
	}
	return true;
}
void DB::stop() { mysql_close(connection); }
auto DB::mysqlError() {	return mysql_error(connection); }
MYSQL_RES* DB::sendReq(std::string req) {
	if (mysql_query(connection, req.c_str())) return nullptr;
	return mysql_store_result(connection);
}


inline bool file_exists(const std::string& name)
    {
        std::ifstream f(name.c_str());
        return f.good();
    }
	
std::string Req(std::string req, std::string Info){
		Info += " ";
		MYSQL_RES* res = DB::sendReq(req);
		MYSQL_ROW row;
		if (res == nullptr) {LOG(DB::mysqlError() << "Error in sending request\n"); return ("Error");}
		int numFields = mysql_num_fields(res);
		while ((row = mysql_fetch_row(res)) != nullptr) {
				for (int i = 0; i<numFields; i++) {Info += (row[i] ? row[i] : "-"); Info += " "; }
		}
	return (Info);
}

int search(){
	std::cout << "Choose variant of search: \n 1 - by ФИО \n 2 - by master \n 3 - by Типу сборки \n";
	
	int chose;
	std::cin >> chose;
	
	switch (chose){
		case 1:{
			std::string input;
			std::cout << "enter ФИО \n";
			std::cin >> input;
			std::string request = "select * from Заказ where ФИО_Клиента in ('";
			request += input; request += "')";
			MYSQL_RES* res = DB::sendReq(request);
		MYSQL_ROW row;
		if (res == nullptr) {LOG(DB::mysqlError() << "Error in sending request\n"); return true; }
		while ((row = mysql_fetch_row(res)) != nullptr) {std::string req = "SELECT id_Заказа FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "№ ") << "\n";
			
			req = "SELECT ФИО_Клиента FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Телефон FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Дата_заказа FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Подтверждение_оплаты FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Сотрудник FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Материал_грифа FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Материал_корпуса FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Колки FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Звукосниматели FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Анкер FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Бридж FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Электроника FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Покраска FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Струны FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Вид_сборки FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";}
			
			break;}
		case 2:{std::string input;
			std::cout << "enter номер сотрудника \n";
			std::cin >> input;
			std::string request = "select * from Заказ where Сотрудник in ('";
			request += input; request += "')";
			MYSQL_RES* res = DB::sendReq(request);
		MYSQL_ROW row;
		if (res == nullptr) {LOG(DB::mysqlError() << "Error in sending request\n"); return true; }
		while ((row = mysql_fetch_row(res)) != nullptr) {std::string req = "SELECT id_Заказа FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "№ ") << "\n";
			
			req = "SELECT ФИО_Клиента FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Телефон FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Дата_заказа FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Подтверждение_оплаты FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Сотрудник FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Материал_грифа FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Материал_корпуса FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Колки FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Звукосниматели FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Анкер FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Бридж FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Электроника FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Покраска FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Струны FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Вид_сборки FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";}
				break;}
		case 3:{
			std::string input;
			std::cout << "enter Тип сборки \n";
			std::cin >> input;
			std::string request = "select * from Заказ where Вид_сборки in ('";
			request += input; request += "')";
			MYSQL_RES* res = DB::sendReq(request);
		MYSQL_ROW row;
		if (res == nullptr) {LOG(DB::mysqlError() << "Error in sending request\n"); return true; }
		while ((row = mysql_fetch_row(res)) != nullptr) {std::string req = "SELECT id_Заказа FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "№ ") << "\n";
			
			req = "SELECT ФИО_Клиента FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Телефон FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Дата_заказа FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Подтверждение_оплаты FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Сотрудник FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Материал_грифа FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Материал_корпуса FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Колки FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Звукосниматели FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Анкер FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Бридж FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Электроника FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Покраска FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Струны FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Вид_сборки FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";}
				break;}
		default: return 0;
		}
	return 0;
	}

int output_pred_S(){
	
	int choise = 0;
	std::cout << "Выберите опцию:" << "\n" << "1 - Однокомнатные квартиры" << "\n" << "2  - Двухкомнатные квартиры" << "\n"<< "3  - Трёхкомнатные квартиры" << "\n"<< "4  - Дома" << "\n";  
	std::cin >> choise;
	
	switch (choise){
		case 1: {
			std::cout << "Введите сначала нижнюю границу, затем верхнюю" << "\n";
			int lower, higher;
			std::cin >> lower >>higher;
			std::string request = "Select * from Однокомнатные_квартиры where Метраж between ";
			std::string s = std::to_string(lower);	
			request += s;
			s = std::to_string(higher);
			request += " and ";
			request += s;
			std::cout << Req(request, " ") << "\n";
			break;}
			case 2: {
			std::cout << "Введите сначала нижнюю границу, затем верхнюю" << "\n";
			int lower, higher;
			std::cin >> lower >>higher;
			std::string request = "Select * from Двухкомнатные_квартиры where Метраж between ";
			std::string s = std::to_string(lower);	
			request += s;
			s = std::to_string(higher);
			request += " and ";
			request += s;
			std::cout << Req(request, " ") << "\n";
			break;}
			case 3: {
			std::cout << "Введите сначала нижнюю границу, затем верхнюю" << "\n";
			int lower, higher;
			std::cin >> lower >>higher;
			std::string request = "Select * from Трёхкомнатные_квартиры where Метраж between ";
			std::string s = std::to_string(lower);	
			request += s;
			s = std::to_string(higher);
			request += " and ";
			request += s;
			std::cout << Req(request, " ") << "\n";
			break;}
			case 4: {
			std::cout << "Введите сначала нижнюю границу, затем верхнюю" << "\n";
			int lower, higher;
			std::cin >> lower >>higher;
			std::string request = "Select * from Дома where Метраж between ";
			std::string s = std::to_string(lower);	
			request += s;
			s = std::to_string(higher);
			request += " and ";
			request += s;
			std::cout << Req(request, " ") << "\n";
			break;}
	
	
	
	}return 0;}

int output_pred_cost(){
	
	int choise = 0;
	std::cout << "Выберите опцию:" << "\n" << "1 - Однокомнатные квартиры" << "\n" << "2  - Двухкомнатные квартиры" << "\n"<< "3  - Трёхкомнатные квартиры" << "\n"<< "4  - Дома" << "\n";  
	std::cin >> choise;
	
	switch (choise){
		case 1: {
			std::cout << "Введите сначала нижнюю границу, затем верхнюю" << "\n";
			int lower, higher;
			std::cin >> lower >>higher;
			std::string request = "Select * from Однокомнатные_квартиры where Цена between ";
			std::string s = std::to_string(lower);	
			request += s;
			s = std::to_string(higher);
			request += " and ";
			request += s;
			std::cout << Req(request, " ") << "\n";
			break;}
			case 2: {
			std::cout << "Введите сначала нижнюю границу, затем верхнюю" << "\n";
			int lower, higher;
			std::cin >> lower >>higher;
			std::string request = "Select * from Двухкомнатные_квартиры where Цена between ";
			std::string s = std::to_string(lower);	
			request += s;
			s = std::to_string(higher);
			request += " and ";
			request += s;
			std::cout << Req(request, " ") << "\n";
			break;}
			case 3: {
			std::cout << "Введите сначала нижнюю границу, затем верхнюю" << "\n";
			int lower, higher;
			std::cin >> lower >>higher;
			std::string request = "Select * from Трёхкомнатные_квартиры where Цена between ";
			std::string s = std::to_string(lower);	
			request += s;
			s = std::to_string(higher);
			request += " and ";
			request += s;
			std::cout << Req(request, " ") << "\n";
			break;}
			case 4: {
			std::cout << "Введите сначала нижнюю границу, затем верхнюю" << "\n";
			int lower, higher;
			std::cin >> lower >>higher;
			std::string request = "Select * from Дома where Цена between ";
			std::string s = std::to_string(lower);	
			request += s;
			s = std::to_string(higher);
			request += " and ";
			request += s;
			std::cout << Req(request, " ") << "\n";
			break;}
	
	
	
	}return 0;}

int output_top(){
	std::string request = "SELECT * from Однокомнатные_квартиры order by Количество_просмотров DESC;";
	std::cout << Req(request, " ") << "\n";
	
	return 0;
	}

int output_users(){
	int choise = 0;
	std::cout << "Выберите опцию:" << "\n" << "1 - поиск по паспорту" << "\n" << "2  - поиск по имени" << "\n";  
	std::cin >> choise;
	
	switch (choise){
		case 1: {
			int pasport;
			std::cin >> pasport;
			std::string request = "Select ФИО, Номер_паспорта, Логин, Пароль from Пользователи where Номер_паспорта = (";
			
			std::string s = std::to_string(pasport);	
			request += s;
			request += + ")";
			std::cout << Req(request, "Пользователь:") << "\n";
			break;}
		case 2:{
		std::string FIO;
			std::cin >> FIO;
			std::string request = "Select ФИО, Номер_паспорта, Логин, Пароль from Пользователи where ФИО = ('";	
			request += FIO;
			request += + "')";
			std::cout << Req(request, "Пользователь:") << "\n";	

		break;}
		}
	return 0;
	}
	
int Anker(){
	MYSQL_RES* res = DB::sendReq("select * from Анкер"); 
			MYSQL_ROW row;
			if (res == nullptr) {LOG(DB::mysqlError() << "Error in sending request\n"); return true; }
			while ((row = mysql_fetch_row(res)) != nullptr) {
						
			std::string req = "SELECT id_Анкера FROM Анкер WHERE id_Анкера=(" + (std::string)row[0]+")";
			std::cout << Req(req, "--") << "\n";
			
			req = "SELECT Тип_Анкера FROM Анкер WHERE id_Анкера=(" + (std::string)row[0]+")";
			std::cout << Req(req, "--") << "\n";
			
			req = "SELECT Цена FROM Анкер WHERE id_Анкера=(" + (std::string)row[0]+")";
			std::cout << Req(req, "Стоимость --") << "\n";
			}
			
	return 0;
	}
	
int Bridge(){
	MYSQL_RES* res = DB::sendReq("select * from Бридж"); 
			MYSQL_ROW row;
			if (res == nullptr) {LOG(DB::mysqlError() << "Error in sending request\n"); return true; }
			while ((row = mysql_fetch_row(res)) != nullptr) {
						
			std::string req = "SELECT id_Бриджа FROM Бридж WHERE id_Бриджа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "--") << "\n";
			
			req = "SELECT Модель FROM Бридж WHERE id_Бриджа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "--") << "\n";
			
			
			req = "SELECT Фирма FROM Бридж WHERE id_Бриджа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "--") << "\n";
			
			req = "SELECT Цена FROM Бридж WHERE id_Бриджа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "Стоимость --") << "\n";
			} 
	return 0;
	}
	
int Strings(){
	MYSQL_RES* res = DB::sendReq("select * from Струны"); 
			MYSQL_ROW row;
			if (res == nullptr) {LOG(DB::mysqlError() << "Error in sending request\n"); return true; }
			while ((row = mysql_fetch_row(res)) != nullptr) {
						
			std::string req = "SELECT id_Струн FROM Струны WHERE id_Струн=(" + (std::string)row[0]+")";
			std::cout << Req(req, "--") << "\n";
			
			req = "SELECT Модель FROM Струны WHERE id_Струн=(" + (std::string)row[0]+")";
			std::cout << Req(req, "--") << "\n";
			
			req = "SELECT Фирма FROM Струны WHERE id_Струн=(" + (std::string)row[0]+")";
			std::cout << Req(req, "--") << "\n";
			
			req = "SELECT Цена FROM Струны WHERE id_Струн=(" + (std::string)row[0]+")";
			std::cout << Req(req, "Стоимость --") << "\n";
			}
			
	return 0;
	}

int Compile(){
	MYSQL_RES* res = DB::sendReq("select * from Вид_сборки"); 
			MYSQL_ROW row;
			if (res == nullptr) {LOG(DB::mysqlError() << "Error in sending request\n"); return true; }
			while ((row = mysql_fetch_row(res)) != nullptr) {
						
			std::string req = "SELECT id_Сборки FROM Вид_сборки WHERE id_Сборки=(" + (std::string)row[0]+")";
			std::cout << Req(req, "--") << "\n";
			
			req = "SELECT Тип_сборки FROM Вид_сборки WHERE id_Сборки=(" + (std::string)row[0]+")";
			std::cout << Req(req, "--") << "\n";
			
			req = "SELECT Цена FROM Вид_сборки WHERE id_Сборки=(" + (std::string)row[0]+")";
			std::cout << Req(req, "Стоимость --") << "\n";
			}
	return 0;
	}

int Body(){
	MYSQL_RES* res = DB::sendReq("select * from Материал_корпуса"); 
			MYSQL_ROW row;
			if (res == nullptr) {LOG(DB::mysqlError() << "Error in sending request\n"); return true; }
			while ((row = mysql_fetch_row(res)) != nullptr) {
						
			std::string req = "SELECT id_корпуса FROM Материал_корпуса WHERE id_корпуса=(" + (std::string)row[0]+")";
			std::cout << Req(req, "--") << "\n";
			
			req = "SELECT Материал FROM Материал_корпуса WHERE id_корпуса=(" + (std::string)row[0]+")";
			std::cout << Req(req, "--") << "\n";
			
			req = "SELECT Цена FROM Материал_корпуса WHERE id_корпуса=(" + (std::string)row[0]+")";
			std::cout << Req(req, "Стоимость --") << "\n";
			}
			
	return 0;
	}

int Grief(){
	MYSQL_RES* res = DB::sendReq("select * from Материал_грифа"); 
			MYSQL_ROW row;
			if (res == nullptr) {LOG(DB::mysqlError() << "Error in sending request\n"); return true; }
			while ((row = mysql_fetch_row(res)) != nullptr) {
						
			std::string req = "SELECT id_Грифа FROM Материал_грифа WHERE id_Грифа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "--") << "\n";
			
			req = "SELECT Материал FROM Материал_грифа WHERE id_Грифа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "--") << "\n";
			
			req = "SELECT Цена FROM Материал_грифа WHERE id_Грифа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "Стоимость --") << "\n";
			}
			
	return 0;
	}

int Paint(){
	MYSQL_RES* res = DB::sendReq("select * from Покраска"); 
			MYSQL_ROW row;
			if (res == nullptr) {LOG(DB::mysqlError() << "Error in sending request\n"); return true; }
			while ((row = mysql_fetch_row(res)) != nullptr) {
						
			std::string req = "SELECT id_Покраски FROM Покраска WHERE id_Покраски=(" + (std::string)row[0]+")";
			std::cout << Req(req, "--") << "\n";
			
			req = "SELECT Тип_покраски FROM Покраска WHERE id_Покраски=(" + (std::string)row[0]+")";
			std::cout << Req(req, "--") << "\n";
			
			req = "SELECT Цена FROM Покраска WHERE id_Покраски=(" + (std::string)row[0]+")";
			std::cout << Req(req, "Стоимость --") << "\n";
			}
	
	return 0;
	}
	
int SoundCheck(){
	MYSQL_RES* res = DB::sendReq("select * from Звукосниматель"); 
			MYSQL_ROW row;
			if (res == nullptr) {LOG(DB::mysqlError() << "Error in sending request\n"); return true; }
			while ((row = mysql_fetch_row(res)) != nullptr) {
						
			std::string req = "SELECT id_Звукоснимателя FROM Звукосниматель WHERE id_Звукоснимателя=(" + (std::string)row[0]+")";
			std::cout << Req(req, "--") << "\n";
			
			req = "SELECT Модель FROM Звукосниматель WHERE id_Звукоснимателя=(" + (std::string)row[0]+")";
			std::cout << Req(req, "--") << "\n";
			
			req = "SELECT Фирма FROM Звукосниматель WHERE id_Звукоснимателя=(" + (std::string)row[0]+")";
			std::cout << Req(req, "--") << "\n";
			
			req = "SELECT Цена FROM Звукосниматель WHERE id_Звукоснимателя=(" + (std::string)row[0]+")";
			std::cout << Req(req, "Стоимость --") << "\n";
			}
			
	return 0;
	}
	
int Kolki(){
	MYSQL_RES* res = DB::sendReq("select * from Колки"); 
			MYSQL_ROW row;
			if (res == nullptr) {LOG(DB::mysqlError() << "Error in sending request\n"); return true; }
			while ((row = mysql_fetch_row(res)) != nullptr) {
						
			std::string req = "SELECT id_Колков FROM Колки WHERE id_Колков=(" + (std::string)row[0]+")";
			std::cout << Req(req, "--") << "\n";
			
			req = "SELECT Модель FROM Колки WHERE id_Колков=(" + (std::string)row[0]+")";
			std::cout << Req(req, "--") << "\n";
			
			req = "SELECT Фирма FROM Колки WHERE id_Колков=(" + (std::string)row[0]+")";
			std::cout << Req(req, "--") << "\n";
			
			req = "SELECT Цена FROM Колки WHERE id_Колков=(" + (std::string)row[0]+")";
			std::cout << Req(req, "Стоимость --") << "\n";
			}
			
	return 0;
	}

int Electro(){
	MYSQL_RES* res = DB::sendReq("select * from Электроника"); 
			MYSQL_ROW row;
			if (res == nullptr) {LOG(DB::mysqlError() << "Error in sending request\n"); return true; }
			while ((row = mysql_fetch_row(res)) != nullptr) {
						
			std::string req = "SELECT id_Электроники FROM Электроника WHERE id_Электроники=(" + (std::string)row[0]+")";
			std::cout << Req(req, "--") << "\n";
			
			req = "SELECT Конфигурация FROM Электроника WHERE id_Электроники=(" + (std::string)row[0]+")";
			std::cout << Req(req, "--") << "\n";
			
			req = "SELECT Цена FROM Электроника WHERE id_Электроники=(" + (std::string)row[0]+")";
			std::cout << Req(req, "Стоимость --") << "\n";
			}
			
	return 0;
	}

int Workers(){
	MYSQL_RES* res = DB::sendReq("select * from Сотрудники"); 
			MYSQL_ROW row;
			if (res == nullptr) {LOG(DB::mysqlError() << "Error in sending request\n"); return true; }
			while ((row = mysql_fetch_row(res)) != nullptr) {
						
			std::string req = "SELECT id_Сотрудника FROM Сотрудники WHERE id_Сотрудника=(" + (std::string)row[0]+")";
			std::cout << Req(req, "№ - ") << "\n";
			
			req = "SELECT ФИО FROM Сотрудники WHERE id_Сотрудника=(" + (std::string)row[0]+")";
			std::cout << Req(req, "ФИО сборщика--") << "\n";
			
			req = "SELECT Должность FROM Сотрудники WHERE id_Сотрудника=(" + (std::string)row[0]+")";
			std::cout << Req(req, "Должность --") << "\n";
			}
			
	return 0;
	}

int output_goods(){
	
	int choise = 0;
	std::cout << "Выберите вид товара:" << "\n" 
	<< "1 - Анкер" << "\n" 
	<< "2 - Бридж" << "\n" 
	<< "3 - Струны" << "\n" 
	<< "4 - Сборка" << "\n"
	<< "5 - Материал корпуса" << "\n"
	<< "6 - Материал грифа" << "\n"
	<< "7 - Покраска" << "\n"
	<< "8 - Звукосниматель" << "\n"
	<< "9 - Колки" << "\n"
	<< "0 - Электроника" << "\n";  
	
	std::cin >> choise;
	
	switch (choise)
	{
		case 1: { Anker(); break;}
		case 2:	{ Bridge(); break;}
		case 3: { Strings(); break;}
		case 4: { Compile(); break;}
		case 5: { Body(); break;}
		case 6: { Grief(); break;}
		case 7:	{ Paint(); break;}
		case 8: { SoundCheck(); break;}
		case 9: { Kolki(); break;}
		case 0: { Electro(); break;}
		default: std::cout << "Invalid input"; return 1;
		}
		
	return 0;
	}

int create (){
	int Summ = 0;
	std::string req;
	std::string request = "insert into Заказ (id_Заказа, ФИО_Клиента, Телефон, Дата_заказа, Сотрудник, Материал_грифа,Материал_корпуса, Колки, Звукосниматели, Анкер, Бридж, Электроника, Покраска, Струны, Вид_сборки) values (NULL, '";
	
	std::cout << "enter your FIO" << "\n"; 
	
	std::string enter;
	std::cin >> enter;
	request += enter; request += "', ";
	
	std::cout << "enter your number without 8 and kode" << "\n"; 
	
	int enter2;
	std::cin >> enter2;
	std::string s = std::to_string(enter2);
	request += s; request += ", ";
	
	
	request += "'2021-12-22', ";
	
	
	std::cout << "enter number of worker" << "\n"; 
	Workers();
	std::cin >> enter2;
	s = std::to_string(enter2);
	request += s; request += ", ";
	
	std::cout << "enter number of grief" << "\n"; 
	Grief();
	std::cin >> enter2;
	s = std::to_string(enter2);
	req = "select Цена from Материал_грифа where id_Грифа = (";
	req += s; req += ")";
	req = Req(req,"");
	Summ += std::stoi(req);
	request += s; request += ", ";
	
	std::cout << "enter number of body" << "\n"; 
	Body();
	std::cin >> enter2;
	s = std::to_string(enter2);
	req = "select Цена from Материал_корпуса where id_корпуса = (";
	req += s; req += ")";
	req = Req(req,"");
	Summ += std::stoi(req);
	request += s; request += ", ";
	
	std::cout << "enter number of kolki" << "\n"; 
	Kolki();
	std::cin >> enter2;
	s = std::to_string(enter2);
	req = "select Цена from Колки where id_Колков = (";
	req += s; req += ")";
	req = Req(req,"");
	Summ += std::stoi(req);
	request += s; request += ", ";
	
	std::cout << "enter number of soundcheck" << "\n"; 
	SoundCheck();
	std::cin >> enter2;
	s = std::to_string(enter2);
	req = "select Цена from Звукосниматель where id_звукоснимателя = (";
	req += s; req += ")";
	req = Req(req,"");
	Summ += std::stoi(req);
	request += s; request += ", ";
	
	std::cout << "enter number of anker" << "\n"; 
	Anker();
	std::cin >> enter2;
	s = std::to_string(enter2);
	req = "select Цена from Анкер where id_Анкера = (";
	req += s; req += ")";
	req = Req(req,"");
	Summ += std::stoi(req);
	request += s; request += ", ";
	
	std::cout << "enter number of bridge" << "\n"; 
	Bridge();
	std::cin >> enter2;
	s = std::to_string(enter2);
	req = "select Цена from Бридж where id_Бриджа = (";
	req += s; req += ")";
	req = Req(req,"");
	Summ += std::stoi(req);
	request += s; request += ", ";
	
	std::cout << "enter number of electro" << "\n"; 
	Electro();
	std::cin >> enter2;
	s = std::to_string(enter2);
	req = "select Цена from Электроника where id_Электроники = (";
	req += s; req += ")";
	req = Req(req,"");
	Summ += std::stoi(req);
	request += s; request += ", ";
	
	std::cout << "enter number of paint" << "\n"; 
	Paint();
	std::cin >> enter2;
	s = std::to_string(enter2);
	req = "select Цена from Покраска where id_Покраски = (";
	req += s; req += ")";
	req = Req(req,"");
	Summ += std::stoi(req);
	request += s; request += ", ";
	
	std::cout << "enter number of strings" << "\n"; 
	Strings();
	std::cin >> enter2;
	s = std::to_string(enter2);
	req = "select Цена from Струны where id_Струн = (";
	req += s; req += ")";
	req = Req(req,"");
	Summ += std::stoi(req);
	request += s; request += ", ";
	
	std::cout << "enter number of compile" << "\n"; 
	Compile();
	std::cin >> enter2;
	s = std::to_string(enter2);
	req = "select Цена from Вид_сборки where id_Сборки = (";
	req += s; req += ")";
	req = Req(req,"");
	Summ += std::stoi(req);
	request += s;
	
	request += ")";
	
	std::cout << "Summ of your order - " << Summ <<"\n Do you want to accept it?" <<"\n 1 - yes \n 2 - no \n";
	int chose;
	while (true){
	std::cin >> chose;
	switch (chose){
		case 1: {DB::sendReq(request); return 0;}
		case 2: {return 0;}
		default: {std::cout << "Invalid input, try again \n 1 - Yes \n 2 - No \n"; break;}
		}
	}
	}

int Orders(){
	MYSQL_RES* res = DB::sendReq("select * from Заказ"); 
			MYSQL_ROW row;
			if (res == nullptr) {LOG(DB::mysqlError() << "Error in sending request\n"); return true; }
			while ((row = mysql_fetch_row(res)) != nullptr) {
						
			std::string req = "SELECT id_Заказа FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "№ ") << "\n";
			
			req = "SELECT ФИО_Клиента FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Телефон FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Дата_заказа FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Подтверждение_оплаты FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Сотрудник FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Материал_грифа FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Материал_корпуса FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Колки FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Звукосниматели FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Анкер FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Бридж FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Электроника FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Покраска FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Струны FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			
			req = "SELECT Вид_сборки FROM Заказ WHERE id_Заказа=(" + (std::string)row[0]+")";
			std::cout << Req(req, "- ") << "\n";
			}
			
	return 0;
	}


int main()
{
	Log.open("Log", std::ios::app);
	
	DB::start();
	
	int choyse;
	while (true){	
	std::cout << "Выберите опцию:" << "\n" 
	<< "1 - Вывод асортимента" << "\n" 
	<< "2 - Создание заказа и расчёт стоимости" << "\n" 
	<< "3 - Вывод всех заказов" << "\n" 
	<< "4 - Поиск заказа" << "\n"
	<< "0 - Выход" << "\n";  
	
	std::cin >> choyse;

	switch (choyse)
	{
		case 1: output_goods(); break;
		case 2: create(); break;
		case 3: Orders(); break;
		case 4: search(); break;
		case 0: DB::stop(); return 0;
		default: std::cout << "Invalid input, try again" << "\n"; break;	
	}
}

return 0;
}
