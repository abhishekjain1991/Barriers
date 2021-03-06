#include "MPI_Test.h"

void print_time(struct timeval *t1, struct timeval *t2 ,char* fname,int num_threads , int orient ){
	t_sec=(t2->tv_sec-t1->tv_sec);
	t_usec=(t2->tv_usec-t1->tv_usec);
	if(t1->tv_usec>t2->tv_usec) 
	{
		t_usec=1000000-t1->tv_usec+t2->tv_usec;
		t_sec-=1;
	}
	FILE *fp=fopen(fname, "a");
	if(orient ==1 )
		fprintf(fp,"%d,%f,",num_threads,((t_sec+(pow(10,-6)*t_usec))/100));
	if(orient==2)
		fprintf(fp,"%f,",((t_sec+(pow(10,-6)*t_usec))/100));
	if(orient==3)
    		fprintf(fp,"%f\n",((t_sec+(pow(10,-6)*t_usec))/100));
	fclose(fp);
}
