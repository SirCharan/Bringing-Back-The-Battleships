#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int gridU[10][10],gridC[10][10];
int hitU[10][10],hitC[10][10];
int n = 10;
void setter()
{
    int i,j,row,col,count=0,flag,vh;
    for (i=0;i<n;i++){
        for(j=0;j<n;j++){
            gridU[i][j] = -1;
            gridC[i][j] = -1;
            hitU[i][j] = -1;
            hitC[i][j] = -1;
        }
    }
    printf("WELCOME TO BATTLESHIPS\n");
    printf("-A Project By Charandeep Kapoor\n");
	sleep(1);
    printf("Set your weapon\n");
    //carrier
    while(1){
    printf("Carrier - Size 5 Ship,9 points for a hit\n");
    printf("Enter Row:");
    scanf("%d",&row);
    printf("Enter Column:");
    scanf("%d",&col);
    printf("Select\n1.Vertical\n2.Horizontal\n");
    scanf("%d",&vh);
    if(row>0 && col>0 && row<=10 && col <=10){
        if(vh==1){
            if(row+4<=10){
                for(i=row;i<row+5;i++){
                    gridU[i-1][col-1]=9;
                }
                flag =1;
            }
            else
                flag = 0;
        }
        if(vh==2){
            if(col+4<=10){
                for(i=col;i<col+5;i++){
                    gridU[row-1][i-1]=9;
                }
                flag =1;
            }
            else
                flag = 0;
        }

        }
    else
        flag==0;
    if (flag==0){
        printf("Not fitting, Enter correct position\n");
        continue;
        }
    else
        break;
    }
    //Battleship
    while(1){
    printf("BattleShip - Size 4 Ship,7 points for a hit\n");
    printf("Enter Row:");
    scanf("%d",&row);
    printf("Enter Column:");
    scanf("%d",&col);
    printf("Select\n1.Vertical\n2.Horizontal\n");
    scanf("%d",&vh);
    if(row>0 && col>0 && row<=10 && col <=10){
        if(vh==1){
            if(row+3<=10){
                flag =1;
                for(i=row;i<row+4;i++){
                    if(gridU[i-1][col-1]!=-1){
                        flag=0;
                        break;
                    }
                }
                if (flag==1){
                    for(i=row;i<row+4;i++){
                    gridU[i-1][col-1]=7;
                    }
                }

            }
            else
                flag = 0;
        }
        if(vh==2){
            if(col+3<=10){
                flag=1;
                for(i=col;i<col+4;i++){
                    if(gridU[row-1][i-1]!=-1){
                        flag=0;
                        break;
                    }
                }
                if (flag==1){
                    for(i=col;i<col+4;i++){
                        gridU[row-1][i-1]=7;
                    }
                }
            }
            else
                flag = 0;
        }

        }
    else
        flag=0;
    if (flag==0){
        printf("Not fitting, Enter correct position\n");
        continue;
        }
    else
        break;
    }
    //Cruiser
    while(1){
    printf("Cruiser - Size 3 Ship,5 points for a hit\n");
    printf("Enter Row:");
    scanf("%d",&row);
    printf("Enter Column:");
    scanf("%d",&col);
    printf("Select\n1.Vertical\n2.Horizontal\n");
    scanf("%d",&vh);
    if(row>0 && col>0 && row<=10 && col <=10){
        if(vh==1){
            if(row+2<=10){
                flag =1;
                for(i=row;i<row+3;i++){
                    if(gridU[i-1][col-1]!=-1){
                        flag=0;
                        break;
                    }
                }
                if (flag==1){
                    for(i=row;i<row+3;i++){
                    gridU[i-1][col-1]=5;
                    }
                }

            }
            else
                flag = 0;
        }
        if(vh==2){
            if(col+2<=10){
                flag=1;
                for(i=col;i<col+3;i++){
                    if(gridU[row-1][i-1]!=-1){
                        flag=0;
                        break;
                    }
                }
                if (flag==1){
                    for(i=col;i<col+3;i++){
                        gridU[row-1][i-1]=5;
                    }
                }
            }
            else
                flag = 0;
        }

        }
    else
        flag=0;
    if (flag==0){
        printf("Not fitting, Enter correct position\n");
        continue;
        }
    else
        break;
    }
    //Destroyer
    for(i=0;i<2;){
        printf("Destroyer Ship %d - Size 2 Ship,3 points for a hit\n",i+1);
        printf("Enter Row:");
        scanf("%d",&row);
        printf("Enter Column:");
        scanf("%d",&col);
        printf("Select\n1.Vertical\n2.Horizontal\n");
        scanf("%d",&vh);
        if(row>0 && col>0 && row<=10 && col <=10){
            if(vh==1){
                if(row+1<=10){
                if(gridU[row-1][col-1]!=-1 || gridU[row][col-1]!=-1){
                    printf("Over writing, Enter correct position\n");
                    continue;
                }
                else{
                   gridU[row-1][col-1]= 3;
                   gridU[row][col-1]= 3;
                   i++;
                }
              }
              else{
                printf("Not fitting, Enter correct position\n");
                    continue;
              }
            }
            if(vh==2){
                if(col+1<=10){
                if(gridU[row-1][col-1]!=-1 || gridU[row-1][col]!=-1){
                    printf("Over writing, Enter correct position\n");
                    continue;
                }
                else{
                   gridU[row-1][col-1]= 3;
                   gridU[row-1][col]= 3;
                   i++;
                }
              }
              else{
                printf("Not fitting, Enter correct position\n");
                    continue;
              }
            }
        }
        else{
            printf("Wrong position, Enter correct position\n");
            continue;
        }
    }
    //Submarine
    for(i=0;i<4;){
        printf("Submarine %d - Size 1 Ship,1 points for a hit\n",i+1);
        printf("Enter Row:");
        scanf("%d",&row);
        printf("Enter Column:");
        scanf("%d",&col);
        if(row>0 && col>0 && row<=10 && col <=10){
            if (gridU[row-1][col-1]!=-1){
            printf("Over Writing, Enter correct position\n");
            continue;
            }
        else{
            gridU[row-1][col-1]= 1;
            i++;
            }
        }
        else{
            printf("Wrong position, Enter correct position\n");
            continue;
        }
    }
    printf("Your weapons to the grid\n");
    for(i=0;i<n;i++ ){
      for(j=0;j<n;j++ ){
        if(gridU[i][j]==-1)
            printf("  |O");
        else if(gridU[i][j]==9)
            printf("  |C");
        else if(gridU[i][j]==7)
            printf("  |B");
        else if(gridU[i][j]==5)
            printf("  |R");
        else if(gridU[i][j]==3)
            printf("  |D");
        else if(gridU[i][j]==1)
            printf("  |S");
    }
      printf("\n");
    }
    srand(time(0));
    i = 5;
    while(i>1){
        vh = rand()%2;
        if (vh==0){
            row = rand()%(n-i+1);
            col = rand()%n;
            flag = 1;
            for(j=row;j<row+i;j++){
                    if(gridC[j][col]!=-1){
                        flag=0;
                        break;
                    }
            }
            if (flag==0)
                continue;
            else{
                for(j=row;j<row+i;j++){
                    gridC[j][col]=i+(i-1);
            }
                i--;
            }
        }
        else{
            row = rand()%n;
            col = rand()%(n-i+1);
            flag = 1;
            for(j=col;j<col+i;j++){
                    if(gridC[row][j]!=-1){
                        flag=0;
                        break;
                    }
            }
            if (flag==0)
                continue;
            else{
                for(j=col;j<col+i;j++){
                    gridC[row][j]=i+(i-1);
            }
                i--;
            }
        }
    }
    while(1){
        vh = rand()%2;
        if (vh==0){
            row = rand()%(n-1);
            col = rand()%n;
            if(gridC[row][col] !=-1 || gridC[row+1][col] !=-1)
                continue;
            else{
                gridC[row][col] = 3;
                gridC[row+1][col] = 3;
                break;
            }
        }
        else{
            row = rand()%n;
            col = rand()%(n-1);
            if(gridC[row][col] !=-1 || gridC[row][col+1] !=-1)
                continue;
            else{
                gridC[row][col] = 3;
                gridC[row][col+1] = 3;
                break;
            }
        }
    }
    for(i=0;i<4;){
        row = rand()%n;
        col = rand()%n;
        if(gridC[row][col]!=-1)
            continue;
        else{
            gridC[row][col]=1;
            i++;
        }
    }
      printf("\n");
    }
int print(int turn,int arr[10][10])
{
    int i, j;
    if(turn==0)
        printf("\nYour Grid\n\n");
    else
        printf("\nComputer's Grid\n\n");
    for(i=0;i<n;i++ ){
      for(j=0;j<n;j++ ){
        if(arr[i][j]==-1)
            printf("  |O");
        else if(arr[i][j]==1)
        printf("  |H");
        else if(arr[i][j]==0)
            printf("  |M");
    }
      printf("\n");
    }
}
int main()
{
    int i,j,turn=0,r,c,count=0,next=-1,uScore = 0,cScore=0,flag,cr,cc;
    int hcount=0,left=0,right=0,up=0,down=0,next_r,next_c,val=0;
    srand(time(0));
    setter();
    printf("\n______PLAY______\n");
    while(count<50){
        if(turn==0){
            printf("\nYour Turn\n");
            printf("Enter row:");
            scanf("%d",&r);
            printf("Enter column:");
            scanf("%d",&c);
            if(r>0 && r<=n && c>0 && c<=n){
                if(gridC[r-1][c-1]==1){
                  printf("You hit submarine at (%d,%d)",r,c);
                  gridC[r-1][c-1]=0;
                  hitC[r-1][c-1] = 1;
                  uScore += 1;
                  continue;
                }
                else if(gridC[r-1][c-1]==3){
                  printf("You hit destroyer partially at (%d,%d)",r,c);
                  gridC[r-1][c-1]=2;
                  hitC[r-1][c-1]=1;
                  uScore += 3;
                  continue;
                }
                else if(gridC[r-1][c-1]==5){
                  printf("You hit cruiser partially at (%d,%d)",r,c);
                  gridC[r-1][c-1]=4;
                  hitC[r-1][c-1]=1;
                  uScore += 5;
                  continue;
                }
                else if(gridC[r-1][c-1]==7){
                  printf("You hit battleship partially at (%d,%d)",r,c);
                  gridC[r-1][c-1]=6;
                  hitC[r-1][c-1]=1;
                  uScore += 7;
                  continue;
                }
                else if(gridC[r-1][c-1]==9){
                  printf("You hit carrier partially at (%d,%d)",r,c);
                  gridC[r-1][c-1]=8;
                  hitC[r-1][c-1]=1;
                  uScore += 9;
                  continue;
                }
                else{
                    printf("You missed at (%d,%d)",r,c);
                    hitC[r-1][c-1] = 0;
                }
                turn = 1;
                print(0,hitC);
            }
            else{
                printf("Wrong hit! try again\n");
                continue;
            }
        }
        else{
            if(next==-1){
                cr = rand()%n;
                cc = rand()%n;
                if(hitU[cr][cc]==1 ||  hitU[cr][cc]==0)
                    continue;
                printf("\nComputer's Turn\n");
                if(gridU[cr][cc]==1){
                  printf("Computer hit submarine at (%d,%d)",cr+1,cc+1);
                  gridU[cr][cc]=0;
                  hitU[cr][cc] =1;
                  cScore += 1;
                  continue;
                }
                else if(gridU[cr][cc]==3 || gridU[cr][cc]==5 || gridU[cr][cc]==7 || gridU[cr][cc]==9){
                  if(gridU[cr][cc]==3){
                  printf("Computer hit destroyer partially at (%d,%d)\n",cr+1,cc+1);
                  gridU[cr][cc]=2;
                  hitU[cr][cc] =1;
                  cScore += 3;
                  hcount = 1;
                  }
                  else if(gridU[cr][cc]==5){
                  printf("Computer hit cruiser partially at (%d,%d)\n",cr+1,cc+1);
                  gridU[cr][cc]=4;
                  hitU[cr][cc] =1;
                  cScore += 5;
                  hcount = 2;
                  }
                  else if(gridU[cr][cc]==7){
                  printf("Computer hit battleship partially at (%d,%d)\n",cr+1,cc+1);
                  gridU[cr][cc]=6;
                  hitU[cr][cc] =1;
                  cScore += 7;
                  hcount = 3;
                  }
                  else if(gridU[cr][cc]==9){
                  printf("Computer hit carrier partially at (%d,%d)\n",cr+1,cc+1);
                  gridU[cr][cc]=8;
                  hitU[cr][cc] =1;
                  cScore += 9;
                  hcount = 4;
                  }
                  next = 1;
                  if(cc==9){
                    left=1;
                    next_r = cr;
                    next_c = cc-1;
                  }
                  else{
                    right=1;
                    next_r = cr;
                    next_c = cc+1;
                  }
                  val = gridU[cr][cc]+1;
                  continue;
                }
                else{
                    printf("Computer missed at (%d,%d)",cr+1,cc+1);
                    hitU[cr][cc] =0;
                }
            }
            else{
                if(gridU[next_r][next_c]==val){
                    gridU[next_r][next_c] = val-1;
                    hitU[next_r][next_c] =1;
                    cScore += val;
                    hcount -= 1;
                    if(val==3)
                        printf("Computer hit destroyer at (%d,%d)",next_r+1,next_c+1);
                    if(val==5)
                        printf("Computer hit cruiser at (%d,%d)",next_r+1,next_c+1);
                    if (val==7)
                        printf("Computer hit battleship at (%d,%d)",next_r+1,next_c+1);
                    if (val==9)
                        printf("Computer hit carrier at (%d,%d)",next_r+1,next_c+1);
                    if(hcount!=0)
                        printf(" partially\n");
                    if(right==1){
                        if(next_c+1<n)
                            next_c += 1;
                        else{
                            next_c = cc-1;
                            right = 0;
                            left = 1;
                        }

                    }
                    else if(left==1){
                        if(next_c-1>=0)
                            next_c -= 1;
                        else{
                            next=-1;
                            left=0;
                        }

                    }
                    else if(up==1){
                        if(next_r-1>=0)
                            next_r -= 1;
                        else{
                            up=0;
                            down=1;
                            next_r = cr+1;
                        }

                    }
                    else if(down==1){
                        if(next_r+1<n)
                            next_r += 1;
                        else{
                            next=-1;
                            down=0;
                        }

                    }
                    if(hcount<=0){
                        left=0,right=0;
                        up=0,down=0,next=-1;
                    }
                    continue;
                }
                else{
                flag = 0;
                 if(gridU[next_r][next_c]==1){
                    printf("Computer hit submarine at (%d,%d)\n",next_r+1,next_c+1);
                    gridU[next_r][next_c]=0;
                    hitU[next_r][next_c] =1;
                    cScore += 1;
                    flag = 1;
                }
                else if(gridU[next_r][next_c]==3){
                    printf("Computer hit destroyer at (%d,%d) partially\n",next_r+1,next_c+1);
                    gridU[next_r][next_c]=2;
                    hitU[next_r][next_c] =1;
                    cScore += 3;
                    flag = 1;
                }
                else if(gridU[next_r][next_c]==5){
                    printf("Computer hit cruiser at (%d,%d) partially\n",next_r+1,next_c+1);
                    gridU[next_r][next_c]=4;
                    hitU[next_r][next_c] =1;
                    cScore += 5;
                    flag = 1;
                }
                else if(gridU[next_r][next_c]==7){
                    printf("Computer hit battleship at (%d,%d) partially\n",next_r+1,next_c+1);
                    gridU[next_r][next_c]=6;
                    hitU[next_r][next_c] =1;
                    cScore += 7;
                    flag = 1;
                }
                else if(gridU[next_r][next_c]==9){
                    printf("Computer hit carrier at (%d,%d) partially\n",next_r+1,next_c+1);
                    gridU[next_r][next_c]=8;
                    hitU[next_r][next_c] =1;
                    cScore += 8;
                    flag = 1;
                }
                else{
                    printf("Computer missed at (%d,%d)\n",next_r+1,next_c+1);
                    hitU[next_r][next_c] =0;
                    flag = 0;
                }
                if(right==1){
                    if(c-1>=0){
                        next_c = cc-1;
                        left = 1;
                        }
                    else{
                            up = 1;
                            next_r = cr-1;
                            next_c = cc;
                        }
                    right = 0;
                    }
                    else if(left==1){
                        if(r-1>=0){
                        next_r = cr-1;
                        next_c = cc;
                        up = 1;
                        }
                        else{
                            down = 1;
                            next_r = cr+1;
                            next_c = cc;
                        }
                    left = 0;
                    }
                    else if(up==1){
                        if(r+1<n){
                            next_r = cr+1;
                            next_c = cc;
                            down = 1;
                            }
                        else{
                            next = -1;
                        }
                        up=0;
                    }
                    else if(down==1){
                        down = 0;
                        next = -1;
                }
            }
            if (flag==1)
                continue;
        }
            turn = 0;
            print(1,hitU);
            }
        count++;
    }
    printf("Your Score:%d\nComputer Score:%d\n",uScore,cScore);
    if(cScore>uScore)
        printf("Computer win\n");
    else if(cScore<uScore)
        printf("You win\n");
    else
        printf("Draw\n");
    return 0;
}
