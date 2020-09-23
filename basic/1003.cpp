#include <cstdio>

#define  MAXLINE 100

typedef struct {
    int state;
    int num_p;
    int num_a;
    int num_t;
}states;

int main()
{
    freopen("./sample_in/1003.txt", "r", stdin);
    int nums;
    scanf("%d\n",&nums);

    states sta[nums];

    for(int i=0;i<nums;i++){
        sta[i].state=1;
        sta[i].num_p=0;
        sta[i].num_a=0;
        sta[i].num_t=0;
    }

    for(int i=0;i<nums;i++){
        int loc_p,loc_t;
        char c;
        int index_cc=0;
        int length=0;
        char cc[MAXLINE];

        for(int ic = 0;ic < MAXLINE;ic++)
            cc[ic] = 0;

        while((c=getchar())!='\n' && c!=EOF){
           cc[index_cc++]=c;
           length++;
           switch(c){
               case 'P':
                   sta[i].num_p++;
                   loc_p = index_cc;
                   break;
               case 'A':
                   sta[i].num_a++;
                   break;
               case 'T':
                   sta[i].num_t++;
                   loc_t = index_cc;
                   break;
               default:
                   sta[i].state=0;
                   break;
           }
           if(sta[i].num_p>1||sta[i].num_t>1)
               sta[i].state=0;
        }
        if(sta[i].state==0){
            continue;
        }else{
            int n1=0;
            int n2=0;
            int n3=0;

            int ii=0;
            while(cc[ii++]=='A')
                n1++;
            while(cc[ii++]=='A')
                n2++;
            while(cc[ii++]=='A')
                n3++;

            n3 = n3 - (n2 -1) * n1;
            if(!(n1 == n3 && n2 > 0 && loc_p < loc_t))
                sta[i].state=0;
        }
    }

    for(int i=0;i<nums;i++) {
        if (sta[i].state == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return  0;
}