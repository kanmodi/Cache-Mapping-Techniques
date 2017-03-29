#include <bits/stdc++.h>

using namespace std;

float asso(int cpu[]);
float direct(int cpu[]);
float setAsso(int cpu[]);

int main(){
    //int t = 2;
    float a = 0, d = 0, s = 0;
    //while(t--){
        int cpu[7][15]={
                        {1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                        {1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                        {0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0},
                        {0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1},
                        {1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0},
                        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1}
                    };
        //cout << "Enter the CPU address: ";
        for(int i = 0; i < 7; i++){
            a = asso(cpu[i]);
            d = direct(cpu[i]);
            s = setAsso(cpu[i]);
        }

    cout << "\nFor Associative mapping: " << a;
    cout << "\nFor Direct mapping: " << d;
    cout << "\nFor Set Associative mapping: " << s;

}

float asso(int cpu[]){
    static float hit_ratio = 0, hit = 0, miss = 0;
    int cache[14][15]={
                        {1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0},
                        {1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
                        {0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0},
                        {1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0},
                        {0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0},
                        {0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0},
                        {0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1},
                        {1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0},
                        {1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0},
                        {0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
                        {0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0},
                        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1},
                        {1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0}
                    };
    /*for (int i = 0; i < 15; i++){
        for (int j = 0; j < 27; j++)
            cin >> cache[i][j];
    }*/

    int k = 0, flag;
    for (int i = 0; i < 14; i++){
        flag = 1;
        k = 0;
        for (int j = 0; j < 15; j++){
            if (cpu[k++] != cache[i][j]){
                flag = 0;
                break;
            }
        }
        if(flag == 1)
            break;
    }

    if (flag == 1)
        hit++;
    else
        miss++;

    hit_ratio = hit / (hit + miss);

    return (hit_ratio);
}

float direct(int cpu[]){
    static float hit_ratio = 0, hit = 0, miss = 0;
    int cache[512][15];
    for(int i = 0; i < 512; i++)
        for(int j = 0; j < 15; j++)
            cache[i][j]=0;

    cache[0][0] = 0;
    cache[0][1] = 0;
    cache[0][2] = 0;
    cache[0][3] = 0;
    cache[0][4] = 0;
    cache[0][5] = 0;
    cache[0][6] = 0;
    cache[0][7] = 0;
    cache[0][8] = 1;
    cache[0][9] = 0;
    cache[0][10] = 0;
    cache[0][11] = 0;
    cache[0][12] = 0;
    cache[0][13] = 0;
    cache[0][14] = 0;

    cache[1][0] = 0;
    cache[1][1] = 1;
    cache[1][2] = 0;
    cache[1][3] = 0;
    cache[1][4] = 0;
    cache[1][5] = 0;
    cache[1][6] = 0;
    cache[1][7] = 0;
    cache[1][8] = 0;
    cache[1][9] = 1;
    cache[1][10] = 0;
    cache[1][11] = 0;
    cache[1][12] = 0;
    cache[1][13] = 1;
    cache[1][14] = 0;

    cache[2][0] = 1;
    cache[2][1] = 1;
    cache[2][2] = 0;
    cache[2][3] = 0;
    cache[2][4] = 0;
    cache[2][5] = 0;
    cache[2][6] = 0;
    cache[2][7] = 0;
    cache[2][8] = 1;
    cache[2][9] = 0;
    cache[2][10] = 0;
    cache[2][11] = 0;
    cache[2][12] = 0;
    cache[2][13] = 0;
    cache[2][14] = 0;

    cache[3][0] = 0;
    cache[3][1] = 1;
    cache[3][2] = 1;
    cache[3][3] = 0;
    cache[3][4] = 1;
    cache[3][5] = 1;
    cache[3][6] = 0;
    cache[3][7] = 1;
    cache[3][8] = 0;
    cache[3][9] = 1;
    cache[3][10] =1;
    cache[3][11] = 1;
    cache[3][12] = 1;
    cache[3][13] = 1;
    cache[3][14] = 1;

    cache[4][0] = 1;
    cache[4][1] = 0;
    cache[4][2] = 0;
    cache[4][3] = 1;
    cache[4][4] = 1;
    cache[4][5] = 0;
    cache[4][6] = 1;
    cache[4][7] = 1;
    cache[4][8] = 1;
    cache[4][9] = 0;
    cache[4][10] = 1;
    cache[4][11] = 0;
    cache[4][12] = 0;
    cache[4][13] = 1;
    cache[4][14] = 1;

    cache[5][0] = 0;
    cache[5][1] = 1;
    cache[5][2] = 1;
    cache[5][3] = 0;
    cache[5][4] = 0;
    cache[5][5] = 0;
    cache[5][6] = 1;
    cache[5][7] = 0;
    cache[5][8] = 0;
    cache[5][9] = 1;
    cache[5][10] = 0;
    cache[5][11] = 1;
    cache[5][12] = 0;
    cache[5][13] = 1;
    cache[5][14] = 0;

    cache[6][0] = 1;
    cache[6][1] = 0;
    cache[6][2] = 1;
    cache[6][3] = 0;
    cache[6][4] = 1;
    cache[6][5] = 1;
    cache[6][6] = 1;
    cache[6][7] = 1;
    cache[6][8] = 1;
    cache[6][9] = 1;
    cache[6][10] = 1;
    cache[6][11] = 1;
    cache[6][12] = 1;
    cache[6][13] = 1;
    cache[6][14] = 1;


    int k = 0, flag1, flag2;
    for (int i = 0; i < 512; i++){
        flag1 = 1;
        k = 6;
        for (int j = 0; j < 9 ; j++){
            if (cpu[k++]!= cache[i][j]){
                flag1 = 0;
                break;
            }
        }
        if(flag1 == 1){
            flag2 = 1;
            int h=0;
            for (int l = 9; l < 15; l++){
                if (cpu[h++] != cache[i][l]){
                    flag2 = 0;
                     break;
                }
            }
            if(flag2 == 1)
                break;
        }
    }

    if (flag2 == 1 && flag1 == 1)
        hit++;
    else
        miss++;

    hit_ratio = hit / (hit + miss);

    return (hit_ratio);
}

float setAsso(int cpu[]){
    static float hit_ratio = 0, hit = 0, miss = 0;
   /* int cache[4][21]={  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
                        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                        {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                        {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1}};
    /*for (int i = 0; i < 21; i++){
        for (int j = 0; j < 21; j++)
            cache[i][j];
    }*/

    int cache[512][15];
    for(int i = 0; i < 512; i++)
        for(int j = 0; j < 21; j++)
            cache[i][j] = 0;

    cache[0][0] = 0;
    cache[0][1] = 0;
    cache[0][2] = 0;
    cache[0][3] = 0;
    cache[0][4] = 0;
    cache[0][5] = 0;
    cache[0][6] = 0;
    cache[0][7] = 0;
    cache[0][8] = 1;
    cache[0][9] = 0;
    cache[0][10] = 0;
    cache[0][11] = 0;
    cache[0][12] = 0;
    cache[0][13] = 0;
    cache[0][14] = 1;
    cache[0][15] = 0;
    cache[0][16] = 0;
    cache[0][17] = 0;
    cache[0][18] = 0;
    cache[0][19] = 0;
    cache[0][20] = 0;


    cache[1][0] = 0;
    cache[1][1] = 1;
    cache[1][2] = 0;
    cache[1][3] = 0;
    cache[1][4] = 0;
    cache[1][5] = 0;
    cache[1][6] = 0;
    cache[1][7] = 0;
    cache[1][8] = 0;
    cache[1][9] = 1;
    cache[1][10] = 0;
    cache[1][11] = 0;
    cache[1][12] = 0;
    cache[1][13] = 1;
    cache[1][14] = 0;
    cache[1][15] = 0;
    cache[1][16] = 0;
    cache[1][17] = 0;
    cache[1][18] = 0;
    cache[1][19] = 0;
    cache[1][20] = 0;

    cache[2][0] = 1;
    cache[2][1] = 1;
    cache[2][2] = 0;
    cache[2][3] = 0;
    cache[2][4] = 0;
    cache[2][5] = 0;
    cache[2][6] = 0;
    cache[2][7] = 0;
    cache[2][8] = 1;
    cache[2][9] = 0;
    cache[2][10] = 0;
    cache[2][11] = 0;
    cache[2][12] = 0;
    cache[2][13] = 0;
    cache[2][14] = 0;
    cache[2][15] = 1;
    cache[2][16] = 1;
    cache[2][17] = 1;
    cache[2][18] = 1;
    cache[2][19] = 1;
    cache[2][20] = 1;

    cache[3][0] = 0;
    cache[3][1] = 1;
    cache[3][2] = 1;
    cache[3][3] = 0;
    cache[3][4] = 1;
    cache[3][5] = 1;
    cache[3][6] = 0;
    cache[3][7] = 1;
    cache[3][8] = 0;
    cache[3][9] = 0;
    cache[3][10] = 0;
    cache[3][11] = 1;
    cache[3][12] = 0;
    cache[3][13] = 1;
    cache[3][14] = 1;
    cache[3][15] = 0;
    cache[3][16] = 0;
    cache[3][17] = 0;
    cache[3][18] = 0;
    cache[3][19] = 0;
    cache[3][20] = 0;


    cache[4][0] = 1;
    cache[4][1] = 0;
    cache[4][2] = 0;
    cache[4][3] = 1;
    cache[4][4] = 1;
    cache[4][5] = 0;
    cache[4][6] = 1;
    cache[4][7] = 1;
    cache[4][8] = 1;
    cache[4][9] = 0;
    cache[4][10] = 1;
    cache[4][11] = 0;
    cache[4][12] = 0;
    cache[4][13] = 1;
    cache[4][14] = 1;
    cache[4][15] = 0;
    cache[4][16] = 0;
    cache[4][17] = 0;
    cache[4][18] = 0;
    cache[4][19] = 0;
    cache[4][20] = 0;

    cache[5][0] = 0;
    cache[5][1] = 1;
    cache[5][2] = 1;
    cache[5][3] = 0;
    cache[5][4] = 0;
    cache[5][5] = 0;
    cache[5][6] = 1;
    cache[5][7] = 0;
    cache[5][8] = 0;
    cache[5][9] = 1;
    cache[5][10] = 0;
    cache[5][11] = 1;
    cache[5][12] = 0;
    cache[5][13] = 1;
    cache[5][14] = 0;
    cache[5][15] = 0;
    cache[5][16] = 0;
    cache[5][17] = 0;
    cache[5][18] = 0;
    cache[5][19] = 0;
    cache[5][20] = 0;


    cache[6][0] = 1;
    cache[6][1] = 0;
    cache[6][2] = 1;
    cache[6][3] = 1;
    cache[6][4] = 0;
    cache[6][5] = 1;
    cache[6][6] = 1;
    cache[6][7] = 1;
    cache[6][8] = 1;
    cache[6][9] = 0;
    cache[6][10] = 0;
    cache[6][11] = 0;
    cache[6][12] = 0;
    cache[6][13] = 0;
    cache[6][14] = 0;
    cache[6][15] = 1;
    cache[6][16] = 1;
    cache[6][17] = 1;
    cache[6][18] = 1;
    cache[6][19] = 1;
    cache[6][20] = 1;
    int k = 0, flag, flag1, flag2;
    for (int i = 0; i < 512; i++){
        flag = 1;
        k = 6;
        for (int j = 0; j < 9 ; j++){
            if (cpu[k++] != cache[i][j]){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            flag1 = 1;
            int h=0;
            for (int l = 9; l < 15; l++){
                if (cpu[h++] != cache[i][l]){
                    flag1 = 0;
                    break;
                }
            }
            if(flag1 == 1)
                break;
            else{
                flag2 = 1;
                int g = 0;
                for (int l = 15; l < 21; l++){
                    if (cpu[g++] != cache[i][l]){
                        flag2 = 0;
                        break;
                    }
                }
                if(flag2 == 1)
                    break;
            }
        }
    }
    if (flag == 1 && (flag1 == 1 || flag2 == 1))
        hit++;
    else
        miss++;

    hit_ratio = hit / (hit + miss);

    return (hit_ratio);
}
