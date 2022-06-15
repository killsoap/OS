all:
	g++ Gitar.cpp -o Gitar -lpthread `mysql_config --cflags --libs`
