#include <stdio.h>

#define NAME_LEN  50 

struct student {
    int   sid; // 学号
    char  name[32]; // 姓名
    float score; // 成绩
};

void inputStuInfo(int studNum, struct student stuTb[]);
void ranking(int studNum, struct student stuTb[]);


int main()
{
    const int MAX_SIZE = 256;
    int studNum = 0;

    while (1)
    {
        printf("==欢迎使用学生成绩管理系统==\n");
        printf("请输入班级学生数量 (不可超过 [%d] ,否则异常): ", MAX_SIZE);
        scanf("%d", &studNum);
        printf("\n");

        if (studNum > MAX_SIZE)
        {
            printf("[ERROR] 学生数量过多,内存不足");
            return 1;
        }


        struct student stuTb[MAX_SIZE];
        inputStuInfo(studNum, stuTb);
        ranking(studNum, stuTb);
    }

    return 0;

}

/**
 * @desc: 输入学生信息
 * @parma: studNum 学生数量
 * @parma: stuTb 学生表
 * @data: 2023_10_27
*/
void inputStuInfo(int studNum, struct student stuTb[]) {
    printf("请输入各位学生信息: \n");
    for (int i = 0; i < studNum; i++)
    {
        printf("请输入学生成绩: ");
        scanf_s("%f", &stuTb[i].score);

        printf("请输入学生学号: ");
        scanf_s("%d", &stuTb[i].sid);

        printf("请输入学生姓名: ");
        scanf_s("%s", &stuTb[i].name, NAME_LEN);

        printf("\n");
    }
}

/**
 * @desc: 计算并输出排名(从高至低)
 * @parma: studNum 学生数量
 * @parma: stuTb 学生表
 * @data: 2023_10_27
*/
void ranking(int studNum, struct student stuTb[]) {
    struct student temp; // 临时变量,用于交换
    int i, j;
    for (i = 0; i < studNum - 1; i++)
    {
        for (j = i + 1; j < studNum; j++)
        {
            if (stuTb[i].score < stuTb[j].score)
            {
                temp = stuTb[i];
                stuTb[i] = stuTb[j];
                stuTb[j] = temp;
            }
        }
    }
    printf("成绩排名为：\n");
    printf("\t \t 学号 \t 姓名\t 成绩\n");
    for (i = 0; i < studNum; i++)
    {
        printf("\t \t %d\t %s\t %0.2f\n", stuTb[i].sid, stuTb[i].name, stuTb[i].score);
    }
    printf("\n");
}