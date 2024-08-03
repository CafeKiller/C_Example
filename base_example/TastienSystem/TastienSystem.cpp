#include <stdio.h>

int priceCompute(int price);
int menuSelect(int selectNum);

int main()
{
    printf("\n############################# \n");
    printf("--|菜单|-- \n");
    printf("--|1.香辣鸡腿中国汉堡: 12元|-- \n");
    printf("--|2.板烧凤梨中国汉堡: 17元|-- \n");
    printf("--|3.北京烤鸭中国汉堡: 18元|-- \n");
    printf("--|4.塔塔风味奶: 8元|-- \n");
    printf("--|5.冰柠可乐: 6元|-- \n");
    printf("\n############################# \n");

    int model = 0, total = 0, menuSelectNum = 0;

    while (1)
    {
        printf("欢迎使用[TastienSystem], 点单服务(1), 结账服务(2), 请输入: ");
        scanf("%d", &model);
        if (model == 1)
        {
            printf("\n请输入菜单中的序号,进行点单: ");
            scanf("%d", &menuSelectNum);
            printf("\n");
            total += menuSelect(menuSelectNum);
        } else if(model == 2) {
            printf("\n[SUCCESS] 点单结束,结算: 你一共点了:[ %d ]元\n", total);
            printf("\n");
            total = 0;
        } else {
            printf("\n[ERROR] 输入参数有误,请重新输入!!!! \n");
        }
        
    }
    printf("欢迎下次光临");
    return 0;
}

/**
 * @desc: 价格计算
 * @parma: price 菜品单价
 * @data: 2023_10_27
*/
int priceCompute(int price){
    int num = 1;
    printf("[INFO] 请问你需要几份呢, 请输入份量: ");
    scanf("%d", &num);
    printf("\n");
    return price * num;
}

/**
 * @desc: 菜单选择
 * @parma: selectNum 菜单中菜品的序号
 * @data: 2023_10_27
*/
int menuSelect(int selectNum){
    switch(selectNum){
        case 1:
            printf("[INFO] 您选择的是: [1]香辣鸡腿中国汉堡, 单价12元\n");
            return priceCompute(12);
            break;
        case 2:
            printf("[INFO] 您选择的是: [2]板烧凤梨中国汉堡, 单价17元\n");
            return priceCompute(17);
            break;
        case 3:
            printf("[INFO] 您选择的是: [3]北京烤鸭中国汉堡, 单价18元\n");
            return priceCompute(18);
            break;
        case 4:
            printf("[INFO] 您选择的是: [4]塔塔风味奶, 单价8元\n");
            return priceCompute(8);
            break;
        case 5:
            printf("[INFO] 您选择的是: [5]冰柠可乐, 单价6元\n");
            return priceCompute(6);
            break;
        default:
            printf("[ERROR] 您选择的这个序号不存在套餐请重新选择\n");
            return 0;
    }
}