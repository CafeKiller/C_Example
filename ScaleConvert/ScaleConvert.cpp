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
 * @file: ����ת������
 * @data: 2023_10_27 13:51:58
 * */ 

int main(){

	int modelNum = 0;

    printf("#############[RULE] �淶˵�� ################ \n");
	printf("�����Ƶķ�Χ��0-1111111111 \n");
	printf("ʮ���Ƶķ�Χ��0-1023 \n");
	printf("ʮ�����Ƶķ�Χ��0-3FF \n");
	printf("������Χ����ȷ��ֵ���bug!!! \n");

	printf("#############����ģʽ����################ \n");
	
	printf("������ģʽ����: 1 \n");
	printf("ʮ����ģʽ����: 2 \n");
	printf("ʮ������ģʽ����: 3 \n");

	int input = 0;
	while(1){
		printf("����������Ҫʹ��ģʽ: ");
		scanf("%d", &modelNum);
        printf("\n");
		switch(modelNum)
        {
			case 1:
				printf("������һ�������Ƶ�ֵ: ");
                scanf("%d", &input);

                printf("\n");
                binaryToDec(input);
                printf("\n");
                binaryToHex(input);
                printf("\n");

                printf("\n############################# \n");
				break;
            case 2:
				printf("������һ��ʮ���Ƶ�ֵ: ");
                scanf("%d", &input);

                printf("\n");
                decToBinary(input);
                printf("\n");
                decToHex(input);
                printf("\n");

                printf("\n############################# \n");
                break;
            case 3:
                printf("������һ��ʮ�����Ƶ�ֵ: ");
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
                printf("[Error] ��������ȷ��ģʽ��Ӧ������\n");
                printf("\n");
		}
       
	}
	return 0;
}

/**
 * @desc: ������תʮ������
 * @parma: binary ����������
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
 * @desc: ������תʮ����
 * @parma: binary ����������
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
    printf("[SUCCESS]�ó�ʮ������: %d", sum);
    
}

/**
 * @desc: ʮ����ת������
 * @parma: dec ʮ��������
 * @data: 2023_10_27
*/
void decToBinary(int dec){
    int result = 0;
    int y, x = 1; // y��ʾ������xΪ���ӵ�ϵ��
    while (dec != 0)
    {
        y = dec % 2;
        result += x * y;
        x *= 10;
        dec /= 2;
    }
    printf("[SUCCESS]�ó�������: %d", result);
}

/**
 * @desc: ʮ����תʮ������
 * @parma: dec ʮ��������
 * @data: 2023_10_27
*/
void decToHex(int dec){
    char  buffer [64];
    sprintf (buffer,  "%x" , dec);
    printf("[SUCCESS]�ó�ʮ������: %s", buffer);
}

/**
 * @desc: ʮ������ת������
 * @parma: dec ʮ�������ַ���
 * @data: 2023_10_27
*/
void hexToBinary(char hex[]){
    int result = 0;
    result = strtol(hex, NULL, 16);
    // ����ʮ����ת�����ƺ��� decToBinary
    decToBinary(result);
}

/**
 * @desc: ʮ������תʮ����
 * @parma: dec ʮ�������ַ���
 * @data: 2023_10_27
*/
void hexToDec(char hex[]){
    int result = 0;
    result = strtol(hex, NULL, 16);
    printf("[SUCCESS]�ó�ʮ������: %d", result);
}