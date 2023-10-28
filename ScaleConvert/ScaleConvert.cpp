#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void binaryToHex(int binary);
void binaryToDec(int binary);

void decToBinary(int dec);
void decToHex(int dec);

void hexToBinary(char hex[]);
void hexToDec(char hex[]);

/**
 * @file: 进制转换程序
 * @data: 2023_10_27 13:51:58
 * */ 

int main(){

	int modelNum = 0;

    printf("#############[RULE] 规范说明 ################ \n");
	printf("二进制的范围在0-1111111111 \n");
	printf("十进制的范围在0-1023 \n");
	printf("十六进制的范围在0-3FF \n");
	printf("超出范围或不正确的值会出bug!!! \n");

	printf("#############输入模式规则################ \n");
	
	printf("二进制模式输入: 1 \n");
	printf("十进制模式输入: 2 \n");
	printf("十六进制模式输入: 3 \n");

	int input = 0;
	while(1){
		printf("请输入你需要使用模式: ");
		scanf("%d", &modelNum);
        printf("\n");
		switch(modelNum)
        {
			case 1:
				printf("请输入一个二进制的值: ");
                scanf("%d", &input);

                printf("\n");
                binaryToDec(input);
                printf("\n");
                binaryToHex(input);
                printf("\n");

                printf("\n############################# \n");
				break;
            case 2:
				printf("请输入一个十进制的值: ");
                scanf("%d", &input);

                printf("\n");
                decToBinary(input);
                printf("\n");
                decToHex(input);
                printf("\n");

                printf("\n############################# \n");
                break;
            case 3:
                printf("请输入一个十六进制的值: ");
                char hex[32];
                scanf("%s", hex);

                printf("\n");
                hexToBinary(hex);
                printf("\n");
                hexToDec(hex);
                printf("\n");

                printf("\n############################# \n");
                break;
            default:
                printf("\n");
                printf("[Error] 请输入正确的模式对应的数字\n");
                printf("\n");
		}
       
	}
	return 0;
}

/**
 * @desc: 二级制转十六进制
 * @parma: binary 二进制整数
 * @data: 2023_10_27
*/
void binaryToHex(int binary)
{
	int m = 0,i = 0, sum = 0;
    while (binary != 0)
    {
        m = binary % 10;
        binary /= 10;
        sum += m*pow(2, i);
        ++i;
    }
    decToHex(sum);
}

/**
 * @desc: 二进制转十进制
 * @parma: binary 二进制整数
 * @data: 2023_10_27
*/
void binaryToDec(int binary)
{
    int m = 0,i = 0, sum = 0;
    while (binary != 0)
    {
        m = binary % 10;
        binary /= 10;
        sum += m*pow(2, i);
        ++i;
    }
    printf("[SUCCESS]得出十六进制: %d", sum);
    
}

/**
 * @desc: 十进制转二进制
 * @parma: dec 十进制整数
 * @data: 2023_10_27
*/
void decToBinary(int dec){
    int result = 0;
    int y, x = 1; // y表示余数，x为叠加的系数
    while (dec != 0)
    {
        y = dec % 2;
        result += x * y;
        x *= 10;
        dec /= 2;
    }
    printf("[SUCCESS]得出二进制: %d", result);
}

/**
 * @desc: 十进制转十六进制
 * @parma: dec 十进制整数
 * @data: 2023_10_27
*/
void decToHex(int dec){
    char  buffer [64];
    sprintf (buffer,  "%x" , dec);
    printf("[SUCCESS]得出十六进制: %s", buffer);
}

/**
 * @desc: 十六进制转二进制
 * @parma: dec 十六进制字符串
 * @data: 2023_10_27
*/
void hexToBinary(char hex[]){
    int result = 0;
    result = strtol(hex, NULL, 16);
    // 调用十进制转二进制函数 decToBinary
    decToBinary(result);
}

/**
 * @desc: 十六进制转十进制
 * @parma: dec 十六进制字符串
 * @data: 2023_10_27
*/
void hexToDec(char hex[]){
    int result = 0;
    result = strtol(hex, NULL, 16);
    printf("[SUCCESS]得出十六进制: %d", result);
}