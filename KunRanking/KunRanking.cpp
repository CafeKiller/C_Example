#include <stdio.h>

#define NAME_LEN  50 

struct student {
    int   sid; // ѧ��
    char  name[32]; // ����
    float score; // �ɼ�
};

void inputStuInfo(int studNum, struct student stuTb[]);
void ranking(int studNum, struct student stuTb[]);


int main()
{
    const int MAX_SIZE = 256;
    int studNum = 0;

    while (1)
    {
        printf("==��ӭʹ��ѧ���ɼ�����ϵͳ==\n");
        printf("������༶ѧ������ (���ɳ��� [%d] ,�����쳣): ", MAX_SIZE);
        scanf("%d", &studNum);
        printf("\n");

        if (studNum > MAX_SIZE)
        {
            printf("[ERROR] ѧ����������,�ڴ治��");
            return 1;
        }


        struct student stuTb[MAX_SIZE];
        inputStuInfo(studNum, stuTb);
        ranking(studNum, stuTb);
    }

    return 0;

}

/**
 * @desc: ����ѧ����Ϣ
 * @parma: studNum ѧ������
 * @parma: stuTb ѧ����
 * @data: 2023_10_27
*/
void inputStuInfo(int studNum, struct student stuTb[]) {
    printf("�������λѧ����Ϣ: \n");
    for (int i = 0; i < studNum; i++)
    {
        printf("������ѧ���ɼ�: ");
        scanf_s("%f", &stuTb[i].score);

        printf("������ѧ��ѧ��: ");
        scanf_s("%d", &stuTb[i].sid);

        printf("������ѧ������: ");
        scanf_s("%s", &stuTb[i].name, NAME_LEN);

        printf("\n");
    }
}

/**
 * @desc: ���㲢�������(�Ӹ�����)
 * @parma: studNum ѧ������
 * @parma: stuTb ѧ����
 * @data: 2023_10_27
*/
void ranking(int studNum, struct student stuTb[]) {
    struct student temp; // ��ʱ����,���ڽ���
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
    printf("�ɼ�����Ϊ��\n");
    printf("\t \t ѧ�� \t ����\t �ɼ�\n");
    for (i = 0; i < studNum; i++)
    {
        printf("\t \t %d\t %s\t %0.2f\n", stuTb[i].sid, stuTb[i].name, stuTb[i].score);
    }
    printf("\n");
}