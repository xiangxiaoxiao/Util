/*
 * glog_demo.cpp
 *
 *  Created on: 2016年8月12日
 *      Author: lm
 */

#include "log.h"
#include<unistd.h>

int main()
{
	Log::get_instance()->init("./system_log/mylog.log", 100, 2000000, 10);
	//Log::get_instance()->init("./mylog.log", 100, 2000000, 0);//synchronization model
	sleep(1);
	int i = 0;
	Log::get_instance()->write_log(1, "d=%d,c=%c,s=%s,f=%f", i,'a',"log", 1.000);
	Log::get_instance()->write_log(2, "d=%d,c=%c,s=%s,f=%f", i,'a',"log", 1.000);
	Log::get_instance()->write_log(3, "d=%d,c=%c,s=%s,f=%f", i,'a',"log", 1.000);


	pthread_t id;
	for(int i = 0; i < 1; i++)
	{
		pthread_create(&id, NULL, f, NULL);
		pthread_join(id,NULL);
	}

	for(;;)
	{
		sleep(15);
		Log::get_instance()->flush();
	}

	return 0;
}

