#include "simpFilters.h" 

int main(int argc, char **argv){
#ifdef IS_IMAGE		
	Mat img;
	if(argc!=2 || !(img=imread(argv[1], 0)).data){
		throw runtime_error("输入参数不正确!");	
	}
	runFilters(img);
#else

#endif
	return 0;
}
