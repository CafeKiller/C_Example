#include <stdio.h>

int priceCompute(int price);
int menuSelect(int selectNum);

int main()
{
    printf("\n############################# \n");
    printf("--|�˵�|-- \n");
    printf("--|1.���������й�����: 12Ԫ|-- \n");
    printf("--|2.���շ����й�����: 17Ԫ|-- \n");
    printf("--|3.������Ѽ�й�����: 18Ԫ|-- \n");
    printf("--|4.������ζ��: 8Ԫ|-- \n");
    printf("--|5.��������: 6Ԫ|-- \n");
    printf("\n############################# \n");

    int model = 0, total = 0, menuSelectNum = 0;

    while (1)
    {
        printf("��ӭʹ��[TastienSystem], �㵥����(1), ���˷���(2), ������: ");
        scanf("%d", &model);
        if (model == 1)
        {
            printf("\n������˵��е����,���е㵥: ");
            scanf("%d", &menuSelectNum);
            printf("\n");
            total += menuSelect(menuSelectNum);
        } else if(model == 2) {
            printf("\n[SUCCESS] �㵥����,����: ��һ������:[ %d ]Ԫ\n", total);
            printf("\n");
            total = 0;
        } else {
            printf("\n[ERROR] �����������,����������!!!! \n");
        }
        
    }
    printf("��ӭ�´ι���");
    return 0;
}

/**
 * @desc: �۸����
 * @parma: price ��Ʒ����
 * @data: 2023_10_27
*/
int priceCompute(int price){
    int num = 1;
    printf("[INFO] ��������Ҫ������, ���������: ");
    scanf("%d", &num);
    printf("\n");
    return price * num;
}

/**
 * @desc: �˵�ѡ��
 * @parma: selectNum �˵��в�Ʒ�����
 * @data: 2023_10_27
*/
int menuSelect(int selectNum){
    switch(selectNum){
        case 1:
            printf("[INFO] ��ѡ�����: [1]���������й�����, ����12Ԫ\n");
            return priceCompute(12);
            break;
        case 2:
            printf("[INFO] ��ѡ�����: [2]���շ����й�����, ����17Ԫ\n");
            return priceCompute(17);
            break;
        case 3:
            printf("[INFO] ��ѡ�����: [3]������Ѽ�й�����, ����18Ԫ\n");
            return priceCompute(18);
            break;
        case 4:
            printf("[INFO] ��ѡ�����: [4]������ζ��, ����8Ԫ\n");
            return priceCompute(8);
            break;
        case 5:
            printf("[INFO] ��ѡ�����: [5]��������, ����6Ԫ\n");
            return priceCompute(6);
            break;
        default:
            printf("[ERROR] ��ѡ��������Ų������ײ�������ѡ��\n");
            return 0;
    }
}