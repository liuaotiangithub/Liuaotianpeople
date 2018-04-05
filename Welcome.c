/*
 * calc termnail width and height
*/
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Welcome.h"
#include <string.h>

#define ClearScreen {system("clear");}
#define END1 {printf("请输入任意键继续....");system("read abs");}

int Center_Display(char *buf, int reserve, char *buf1);

int main(void)
{	
	ClearScreen; //清空屏幕显示
	int cols = 0;
	int lines = 0;
	int lines_data_content = 0; //等待计算出一行可以容纳的数字
	int print_data_size = 0;  //计算出要打印的字符长度
	char welcome_content[] = {"欢迎使用信息管理系统"};
	
	Center_Display(welcome_content, 0, NULL);
	Center_Display()
	
	END1;	
	return 0;
}


int Center_Display(char *buf, int reserve, char *buf1)
{
	/*
	 * 居中打印这段文字
	 * reserve:预留一些位置，比如说
	 * buf1: 输出在预留位置
	*/
	int lines_content = 0;//保存每一行可以输出多少文字
	int print_space = 0; //保存需要打印的空格
	struct winsize tz;  //创建终端尺寸的结构体
	ioctl(STDIN_FILENO, TIOCGWINSZ, &tz);  //获得终端尺寸给tz这个结构体
	lines_content = tz.ws_col / 2; //宽度除以2得到可以输出多少文字，因为每个文字占两个字符宽度
	print_space = (lines_content - ((int)strlen(buf) / 3)) / 2; //因为每个字符占3个长度 windows可能不同，字符编码问题，在Linux是这样，所以字符长度除以3之后得出有多少个字，然后总字数减去这个字数，除以2就是打印空格的次数
	print_space -= reserve; //减掉预留的位置，一个位置相当于一个空格的宽度
	for(int i = 0; i < print_space; i++)
	{
		printf("  "); //打印出空格
	}
	if (reserve)
	{
		if (buf1 == NULL)
		{
			//如果需要输出，但字符串是NULL就报错
			return -1;
		}
		printf("%s", buf1);
	}
	printf("%s\n", buf);
	return 0;
}

