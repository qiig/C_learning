#include <stdio.h>
#include <string.h>

// 输入学生姓名和成绩
// 按成绩排名 0 为 降序 1 为升序
// 成绩相同按输入顺序输出
// 结构体，不改变顺序的排序，

typedef struct stu {
    char na[20];
    int gr;
} STU;
 
int main(){
    int n, isA;
    while(scanf("%d %d", &n, &isA) != EOF){
        STU cg, a[n];
        for(int i = 0; i < n; i++){
            scanf("%s %d", &a[i].na, &a[i].gr);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n - i - 1; j++){
                if (isA) {
                    if(a[j].gr > a[j+1].gr){
                            cg = a[j+1];
                            a[j+1] = a[j];
                            a[j] = cg;
                    }
                } else {
                    if(a[j].gr < a[j+1].gr){
                        cg = a[j+1];
                        a[j+1] = a[j];
                        a[j] = cg;
                    }
                }

            }
        }
        for(int i = 0; i < n; i++){
            printf("%s %d\n",a[i].na, a[i].gr);
        }
    }
    return 0;
}